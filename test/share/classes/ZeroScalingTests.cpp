#include <ZeroScalingTests.h>

#include <java/lang/Math.h>
#include <java/math/BigDecimal.h>
#include <java/math/BigInteger.h>
#include <java/math/MathContext.h>
#include <java/math/RoundingMode.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <jcpp.h>

#undef DOWN
#undef MAX_VALUE
#undef MIN_VALUE
#undef UNLIMITED
#undef UNNECESSARY
#undef ZERO

using $BigDecimalArray = $Array<::java::math::BigDecimal>;
using $MathContextArray = $Array<::java::math::MathContext>;
using $StringArray2 = $Array<::java::lang::String, 2>;
using $PrintStream = ::java::io::PrintStream;
using $ArithmeticException = ::java::lang::ArithmeticException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $BigDecimal = ::java::math::BigDecimal;
using $BigInteger = ::java::math::BigInteger;
using $MathContext = ::java::math::MathContext;
using $RoundingMode = ::java::math::RoundingMode;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;

$FieldInfo _ZeroScalingTests_FieldInfo_[] = {
	{"longEnough", "Ljava/math/MathContext;", nullptr, $STATIC, $staticField(ZeroScalingTests, longEnough)},
	{"zeros", "[Ljava/math/BigDecimal;", nullptr, $STATIC, $staticField(ZeroScalingTests, zeros)},
	{"element", "Ljava/math/BigDecimal;", nullptr, $STATIC, $staticField(ZeroScalingTests, element)},
	{"contexts", "[Ljava/math/MathContext;", nullptr, $STATIC, $staticField(ZeroScalingTests, contexts)},
	{}
};

$MethodInfo _ZeroScalingTests_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ZeroScalingTests, init$, void)},
	{"addTests", "()I", nullptr, $STATIC, $staticMethod(ZeroScalingTests, addTests, int32_t)},
	{"divideTests", "()I", nullptr, $STATIC, $staticMethod(ZeroScalingTests, divideTests, int32_t)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ZeroScalingTests, main, void, $StringArray*)},
	{"multiplyTests", "()I", nullptr, $STATIC, $staticMethod(ZeroScalingTests, multiplyTests, int32_t)},
	{"setScaleDoesNotMutateTest", "()I", nullptr, $STATIC, $staticMethod(ZeroScalingTests, setScaleDoesNotMutateTest, int32_t)},
	{"setScaleTests", "()I", nullptr, $STATIC, $staticMethod(ZeroScalingTests, setScaleTests, int32_t)},
	{"subtractTests", "()I", nullptr, $STATIC, $staticMethod(ZeroScalingTests, subtractTests, int32_t)},
	{"toEngineeringStringTests", "()I", nullptr, $STATIC, $staticMethod(ZeroScalingTests, toEngineeringStringTests, int32_t)},
	{"ulpTests", "()I", nullptr, $STATIC, $staticMethod(ZeroScalingTests, ulpTests, int32_t)},
	{}
};

$ClassInfo _ZeroScalingTests_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ZeroScalingTests",
	"java.lang.Object",
	nullptr,
	_ZeroScalingTests_FieldInfo_,
	_ZeroScalingTests_MethodInfo_
};

$Object* allocate$ZeroScalingTests($Class* clazz) {
	return $of($alloc(ZeroScalingTests));
}

$MathContext* ZeroScalingTests::longEnough = nullptr;
$BigDecimalArray* ZeroScalingTests::zeros = nullptr;
$BigDecimal* ZeroScalingTests::element = nullptr;
$MathContextArray* ZeroScalingTests::contexts = nullptr;

void ZeroScalingTests::init$() {
}

int32_t ZeroScalingTests::addTests() {
	$init(ZeroScalingTests);
	$useLocalCurrentObjectStackCache();
	int32_t failures = 0;
	{
		$var($BigDecimalArray, arr$, ZeroScalingTests::zeros);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($BigDecimal, zero1, arr$->get(i$));
			{
				{
					$var($BigDecimalArray, arr$, ZeroScalingTests::zeros);
					int32_t len$ = arr$->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($BigDecimal, zero2, arr$->get(i$));
						{
							$init($BigInteger);
							int32_t var$0 = $nc(zero1)->scale();
							$var($BigDecimal, expected, $new($BigDecimal, $BigInteger::ZERO, $Math::max(var$0, $nc(zero2)->scale())));
							$var($BigDecimal, result, nullptr);
							if (!$nc(($assign(result, $nc(zero1)->add(zero2))))->equals(expected)) {
								++failures;
								$var($String, var$2, $$str({"For classic exact add, expected scale of "_s, $$str(expected->scale()), "; got "_s}));
								$var($String, var$1, $$concat(var$2, $$str($nc(result)->scale())));
								$nc($System::err)->println($$concat(var$1, "."_s));
							}
							$init($MathContext);
							if (!$nc(($assign(result, $nc(zero1)->add(zero2, $MathContext::UNLIMITED))))->equals(expected)) {
								++failures;
								$var($String, var$4, $$str({"For UNLIMITED math context add, expected scale of "_s, $$str(expected->scale()), "; got "_s}));
								$var($String, var$3, $$concat(var$4, $$str($nc(result)->scale())));
								$nc($System::err)->println($$concat(var$3, "."_s));
							}
							if (!$nc(($assign(result, $nc(zero1)->add(zero2, ZeroScalingTests::longEnough))))->equals(expected)) {
								++failures;
								$var($String, var$6, $$str({"For longEnough math context add, expected scale of "_s, $$str(expected->scale()), "; got "_s}));
								$var($String, var$5, $$concat(var$6, $$str($nc(result)->scale())));
								$nc($System::err)->println($$concat(var$5, "."_s));
							}
						}
					}
				}
			}
		}
	}
	{
		$var($MathContextArray, arr$, ZeroScalingTests::contexts);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($MathContext, mc, arr$->get(i$));
			{
				{
					$var($BigDecimalArray, arr$, ZeroScalingTests::zeros);
					int32_t len$ = $nc(arr$)->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($BigDecimal, zero, arr$->get(i$));
						{
							if ($Math::abs((int64_t)$nc(zero)->scale()) < 100) {
								int32_t var$7 = $nc(zero)->scale();
								int32_t preferredScale = $Math::max(var$7, $nc(ZeroScalingTests::element)->scale());
								if ($nc(mc)->getPrecision() != 0) {
									if (preferredScale < -4) {
										preferredScale = -4;
									} else if (preferredScale > -(5 - mc->getPrecision())) {
										preferredScale = -(5 - mc->getPrecision());
									}
								}
								$var($BigDecimal, result, $nc(ZeroScalingTests::element)->add(zero, mc));
								bool var$8 = $nc(result)->scale() != preferredScale;
								if (var$8 || $nc(result)->compareTo(ZeroScalingTests::element) != 0) {
									++failures;
									$nc($System::err)->println($$str({"Expected scale  "_s, $$str(preferredScale), " result scale was "_s, $$str(result->scale()), " ; value was "_s, result}));
								}
								$assign(result, $nc(zero)->add(ZeroScalingTests::element, mc));
								bool var$9 = $nc(result)->scale() != preferredScale;
								if (var$9 || $nc(result)->compareTo(ZeroScalingTests::element) != 0) {
									++failures;
									$nc($System::err)->println($$str({"Expected scale  "_s, $$str(preferredScale), " result scale was "_s, $$str(result->scale()), " ; value was "_s, result}));
								}
								$assign(result, $nc($($nc(ZeroScalingTests::element)->negate()))->add(zero, mc));
								bool var$10 = $nc(result)->scale() != preferredScale;
								if (var$10 || $nc(result)->compareTo($($nc(ZeroScalingTests::element)->negate())) != 0) {
									++failures;
									$nc($System::err)->println($$str({"Expected scale  "_s, $$str(preferredScale), " result scale was "_s, $$str(result->scale()), " ; value was "_s, result}));
								}
								$assign(result, zero->add($($nc(ZeroScalingTests::element)->negate()), mc));
								bool var$11 = $nc(result)->scale() != preferredScale;
								if (var$11 || $nc(result)->compareTo($($nc(ZeroScalingTests::element)->negate())) != 0) {
									++failures;
									$nc($System::err)->println($$str({"Expected scale  "_s, $$str(preferredScale), " result scale was "_s, $$str(result->scale()), " ; value was "_s, result}));
								}
							}
						}
					}
				}
			}
		}
	}
	return failures;
}

int32_t ZeroScalingTests::subtractTests() {
	$init(ZeroScalingTests);
	$useLocalCurrentObjectStackCache();
	int32_t failures = 0;
	{
		$var($BigDecimalArray, arr$, ZeroScalingTests::zeros);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($BigDecimal, zero1, arr$->get(i$));
			{
				{
					$var($BigDecimalArray, arr$, ZeroScalingTests::zeros);
					int32_t len$ = arr$->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($BigDecimal, zero2, arr$->get(i$));
						{
							$init($BigInteger);
							int32_t var$0 = $nc(zero1)->scale();
							$var($BigDecimal, expected, $new($BigDecimal, $BigInteger::ZERO, $Math::max(var$0, $nc(zero2)->scale())));
							$var($BigDecimal, result, nullptr);
							if (!$nc(($assign(result, $nc(zero1)->subtract(zero2))))->equals(expected)) {
								++failures;
								$var($String, var$2, $$str({"For classic exact subtract, expected scale of "_s, $$str(expected->scale()), "; got "_s}));
								$var($String, var$1, $$concat(var$2, $$str($nc(result)->scale())));
								$nc($System::err)->println($$concat(var$1, "."_s));
							}
							$init($MathContext);
							if (!$nc(($assign(result, $nc(zero1)->subtract(zero2, $MathContext::UNLIMITED))))->equals(expected)) {
								++failures;
								$var($String, var$4, $$str({"For UNLIMITED math context subtract, expected scale of "_s, $$str(expected->scale()), "; got "_s}));
								$var($String, var$3, $$concat(var$4, $$str($nc(result)->scale())));
								$nc($System::err)->println($$concat(var$3, "."_s));
							}
							if (!$nc(($assign(result, $nc(zero1)->subtract(zero2, ZeroScalingTests::longEnough))))->equals(expected)) {
								++failures;
								$var($String, var$6, $$str({"For longEnough math context subtract, expected scale of "_s, $$str(expected->scale()), "; got "_s}));
								$var($String, var$5, $$concat(var$6, $$str($nc(result)->scale())));
								$nc($System::err)->println($$concat(var$5, "."_s));
							}
						}
					}
				}
			}
		}
	}
	{
		$var($MathContextArray, arr$, ZeroScalingTests::contexts);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($MathContext, mc, arr$->get(i$));
			{
				{
					$var($BigDecimalArray, arr$, ZeroScalingTests::zeros);
					int32_t len$ = $nc(arr$)->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($BigDecimal, zero, arr$->get(i$));
						{
							if ($Math::abs((int64_t)$nc(zero)->scale()) < 100) {
								int32_t var$7 = $nc(zero)->scale();
								int32_t preferredScale = $Math::max(var$7, $nc(ZeroScalingTests::element)->scale());
								if ($nc(mc)->getPrecision() != 0) {
									if (preferredScale < -4) {
										preferredScale = -4;
									} else if (preferredScale > -(5 - mc->getPrecision())) {
										preferredScale = -(5 - mc->getPrecision());
									}
								}
								$var($BigDecimal, result, $nc(ZeroScalingTests::element)->subtract(zero, mc));
								bool var$8 = $nc(result)->scale() != preferredScale;
								if (var$8 || $nc(result)->compareTo(ZeroScalingTests::element) != 0) {
									++failures;
									$nc($System::err)->println($$str({"Expected scale  "_s, $$str(preferredScale), " result scale was "_s, $$str(result->scale()), " ; value was "_s, result}));
								}
								$assign(result, $nc(zero)->subtract(ZeroScalingTests::element, mc));
								bool var$9 = $nc(result)->scale() != preferredScale;
								if (var$9 || $nc(result)->compareTo($($nc(ZeroScalingTests::element)->negate())) != 0) {
									++failures;
									$nc($System::err)->println($$str({"Expected scale  "_s, $$str(preferredScale), " result scale was "_s, $$str(result->scale()), " ; value was "_s, result}));
								}
								$assign(result, $nc($($nc(ZeroScalingTests::element)->negate()))->subtract(zero, mc));
								bool var$10 = $nc(result)->scale() != preferredScale;
								if (var$10 || $nc(result)->compareTo($($nc(ZeroScalingTests::element)->negate())) != 0) {
									++failures;
									$nc($System::err)->println($$str({"Expected scale  "_s, $$str(preferredScale), " result scale was "_s, $$str(result->scale()), " ; value was "_s, result}));
								}
								$assign(result, zero->subtract($($nc(ZeroScalingTests::element)->negate()), mc));
								bool var$11 = $nc(result)->scale() != preferredScale;
								if (var$11 || $nc(result)->compareTo(ZeroScalingTests::element) != 0) {
									++failures;
									$nc($System::err)->println($$str({"Expected scale  "_s, $$str(preferredScale), " result scale was "_s, $$str(result->scale()), " ; value was "_s, result}));
								}
							}
						}
					}
				}
			}
		}
	}
	return failures;
}

int32_t ZeroScalingTests::multiplyTests() {
	$init(ZeroScalingTests);
	$useLocalCurrentObjectStackCache();
	int32_t failures = 0;
	$var($BigDecimalArray, ones, $new($BigDecimalArray, {
		$($BigDecimal::valueOf(1, 0)),
		$($BigDecimal::valueOf(10, 1)),
		$($BigDecimal::valueOf(1000, 3)),
		$($BigDecimal::valueOf(0x05F5E100, 8))
	}));
	$var($List, values, $new($LinkedList));
	values->addAll($($Arrays::asList(ZeroScalingTests::zeros)));
	values->addAll($($Arrays::asList(ones)));
	{
		$var($BigDecimalArray, arr$, ZeroScalingTests::zeros);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($BigDecimal, zero1, arr$->get(i$));
			{
				{
					$var($Iterator, i$, values->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($BigDecimal, value, $cast($BigDecimal, i$->next()));
						{
							$init($BigInteger);
							int64_t var$0 = (int64_t)$nc(zero1)->scale();
							$var($BigDecimal, expected, $new($BigDecimal, $BigInteger::ZERO, (int32_t)$Math::min($Math::max(var$0 + $nc(value)->scale(), (int64_t)$Integer::MIN_VALUE), (int64_t)$Integer::MAX_VALUE)));
							$var($BigDecimal, result, nullptr);
							if (!$nc(($assign(result, $nc(zero1)->multiply(value))))->equals(expected)) {
								++failures;
								$var($String, var$2, $$str({"For classic exact multiply, expected scale of "_s, $$str(expected->scale()), "; got "_s}));
								$var($String, var$1, $$concat(var$2, $$str($nc(result)->scale())));
								$nc($System::err)->println($$concat(var$1, "."_s));
							}
							$init($MathContext);
							if (!$nc(($assign(result, $nc(zero1)->multiply(value, $MathContext::UNLIMITED))))->equals(expected)) {
								++failures;
								$var($String, var$4, $$str({"For UNLIMITED math context multiply, expected scale of "_s, $$str(expected->scale()), "; got "_s}));
								$var($String, var$3, $$concat(var$4, $$str($nc(result)->scale())));
								$nc($System::err)->println($$concat(var$3, "."_s));
							}
							if (!$nc(($assign(result, $nc(zero1)->multiply(value, ZeroScalingTests::longEnough))))->equals(expected)) {
								++failures;
								$var($String, var$6, $$str({"For longEnough math context multiply, expected scale of "_s, $$str(expected->scale()), "; got "_s}));
								$var($String, var$5, $$concat(var$6, $$str($nc(result)->scale())));
								$nc($System::err)->println($$concat(var$5, "."_s));
							}
						}
					}
				}
			}
		}
	}
	return failures;
}

int32_t ZeroScalingTests::divideTests() {
	$init(ZeroScalingTests);
	$useLocalCurrentObjectStackCache();
	int32_t failures = 0;
	$var($BigDecimalArray, ones, $new($BigDecimalArray, {
		$($BigDecimal::valueOf(1, 0)),
		$($BigDecimal::valueOf(10, -1)),
		$($BigDecimal::valueOf(100, -2)),
		$($BigDecimal::valueOf(1000, -3)),
		$($BigDecimal::valueOf(0x000F4240, -5))
	}));
	{
		$var($BigDecimalArray, arr$, ones);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($BigDecimal, one, arr$->get(i$));
			{
				{
					$var($BigDecimalArray, arr$, ZeroScalingTests::zeros);
					int32_t len$ = arr$->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($BigDecimal, zero, arr$->get(i$));
						{
							$init($BigInteger);
							int64_t var$0 = (int64_t)$nc(zero)->scale();
							$var($BigDecimal, expected, $new($BigDecimal, $BigInteger::ZERO, (int32_t)$Math::min($Math::max(var$0 - $nc(one)->scale(), (int64_t)$Integer::MIN_VALUE), (int64_t)$Integer::MAX_VALUE)));
							$var($BigDecimal, result, nullptr);
							if (!$nc(($assign(result, $nc(zero)->divide(one))))->equals(expected)) {
								++failures;
								$var($String, var$2, $$str({"For classic exact divide, expected scale of "_s, $$str(expected->scale()), "; got "_s}));
								$var($String, var$1, $$concat(var$2, $$str($nc(result)->scale())));
								$nc($System::err)->println($$concat(var$1, "."_s));
							}
							$init($MathContext);
							if (!$nc(($assign(result, $nc(zero)->divide(one, $MathContext::UNLIMITED))))->equals(expected)) {
								++failures;
								$var($String, var$4, $$str({"For UNLIMITED math context divide, expected scale of "_s, $$str(expected->scale()), "; got "_s}));
								$var($String, var$3, $$concat(var$4, $$str($nc(result)->scale())));
								$nc($System::err)->println($$concat(var$3, "."_s));
							}
							if (!$nc(($assign(result, $nc(zero)->divide(one, ZeroScalingTests::longEnough))))->equals(expected)) {
								++failures;
								$var($String, var$6, $$str({"For longEnough math context divide, expected scale of "_s, $$str(expected->scale()), "; got "_s}));
								$var($String, var$5, $$concat(var$6, $$str($nc(result)->scale())));
								$nc($System::err)->println($$concat(var$5, "."_s));
							}
						}
					}
				}
			}
		}
	}
	return failures;
}

int32_t ZeroScalingTests::setScaleTests() {
	$init(ZeroScalingTests);
	$useLocalCurrentObjectStackCache();
	int32_t failures = 0;
	$var($ints, scales, $new($ints, {
		$Integer::MIN_VALUE,
		$Integer::MIN_VALUE + 1,
		(int32_t)0xFF676980,
		-3,
		-2,
		-1,
		0,
		1,
		2,
		3,
		10,
		0x00989680,
		$Integer::MAX_VALUE - 1,
		$Integer::MAX_VALUE
	}));
	{
		$var($BigDecimalArray, arr$, ZeroScalingTests::zeros);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($BigDecimal, zero, arr$->get(i$));
			{
				{
					$var($ints, arr$, scales);
					int32_t len$ = arr$->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						int32_t scale = arr$->get(i$);
						{
							try {
								$var($BigDecimal, bd, $nc(zero)->setScale(scale));
							} catch ($ArithmeticException& e) {
								++failures;
								$nc($System::err)->println($$str({"Exception when trying to set a scale of "_s, $$str(scale), " on "_s, zero}));
							}
						}
					}
				}
			}
		}
	}
	return failures;
}

int32_t ZeroScalingTests::toEngineeringStringTests() {
	$init(ZeroScalingTests);
	$useLocalCurrentObjectStackCache();
	int32_t failures = 0;
	$var($StringArray2, testCases, $new($StringArray2, {
		$$new($StringArray, {
			"0E+10"_s,
			"0.00E+12"_s
		}),
		$$new($StringArray, {
			"0E+9"_s,
			"0E+9"_s
		}),
		$$new($StringArray, {
			"0E+8"_s,
			"0.0E+9"_s
		}),
		$$new($StringArray, {
			"0E+7"_s,
			"0.00E+9"_s
		}),
		$$new($StringArray, {
			"0E-10"_s,
			"0.0E-9"_s
		}),
		$$new($StringArray, {
			"0E-9"_s,
			"0E-9"_s
		}),
		$$new($StringArray, {
			"0E-8"_s,
			"0.00E-6"_s
		}),
		$$new($StringArray, {
			"0E-7"_s,
			"0.0E-6"_s
		})
	}));
	{
		$var($StringArray2, arr$, testCases);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($StringArray, testCase, arr$->get(i$));
			{
				$var($BigDecimal, bd, $new($BigDecimal, $nc(testCase)->get(0)));
				$var($String, result, bd->toEngineeringString());
				bool var$0 = !$nc(result)->equals($nc(testCase)->get(1));
				if (var$0 || !bd->equals($$new($BigDecimal, result))) {
					++failures;
					$nc($System::err)->println($$str({"From input ``"_s, $nc(testCase)->get(0), ",\'\'  bad engineering string output ``"_s, result, "\'\'; expected ``"_s, testCase->get(1), ".\'\'"_s}));
				}
			}
		}
	}
	return failures;
}

int32_t ZeroScalingTests::ulpTests() {
	$init(ZeroScalingTests);
	$useLocalCurrentObjectStackCache();
	int32_t failures = 0;
	{
		$var($BigDecimalArray, arr$, ZeroScalingTests::zeros);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($BigDecimal, zero, arr$->get(i$));
			{
				$var($BigDecimal, result, nullptr);
				$var($BigDecimal, expected, $BigDecimal::valueOf(1, $nc(zero)->scale()));
				if (!$nc(($assign(result, $nc(zero)->ulp())))->equals(expected)) {
					++failures;
					$nc($System::err)->println($$str({"Unexpected ulp value for zero value "_s, zero, "; expected "_s, expected, ", got "_s, result}));
				}
			}
		}
	}
	return failures;
}

int32_t ZeroScalingTests::setScaleDoesNotMutateTest() {
	$init(ZeroScalingTests);
	$useLocalCurrentObjectStackCache();
	$var($BigDecimal, total, $new($BigDecimal, "258815507198903607775511093103396443816569106750031264155319238473795838680758514810110764742309284477206138527975952150289602995045050194333030191178778772026538699925775139201970526695485362661420908248887297829319881475178467494779683293036572059595504702727301324759997409522995072582369210284334718757260859794972695026582432867589093687280300148141501712013226636373167978223780290547640482160818746599330924736802844173226042389174403401903999447463440670236056324929325189403433689.426167432065785331444814035799717606745777287606858873045971898862329763544687891847664736523584843544347118836628373041412918374550458884706686730726101338872517021688769782894793734049819222924171842793485919753186993388451909096042127903835765393729547730953942175461146061715108701615615142134282261293656760570061554783195726716403304101469782303957325142638493327692352838806741611887655695029948975509680496573999174402058593454203190963443179532640446352828089016874853634851387762579319853267317320515941105912189838719919259"
		"2777219948801935416348728821801843034343604123440594355596804948074155732691992033761262422717669396669393166485750657027505027989734189782049723369242547025513506546505735826142115068563838976929114224582869120853395758753248329791408701194556205322723181221036402330691157000207606254938169028062416307882302680316951406879649313779889625072639904682760097509980664429713088663471360229071666253306231303075559149301201504379005105305372586651726198212729370267139777099744349671651595455924827106636399667816782686226202295770093176982541349147420984207923139318437098109054143363837574076754296637142109679247674342030212052703693167977524119746176622008980863353222181916748467951631020215055555084442167087459111943216748875272272002970394717995807443033463540572735407306438420918108994905909141952250875930138343888010184881748550603068040248942927576136181904722341108594364726452037531398206582795593402512269925567443434750869235683656379194794624247945545228655598882400396628995096522213298920347064452534878980"
		"4442127828307923322684512452543458632465747128695322625543066212587099337528151271320712572074816349864279596045763995461653016395900477009254729739249913738317660964650535100130484076290582623702498233059780506352116228580654122011052498964925639923379279940699506846927194126951181899495410939283954814126232466047225363238232503883683142904561703601512238807024013376085850013271325540785562583795688634932498100391708492280818722328505114445491544113421774306657586356357215213397890544499820907576395090978414814201899236729048589007230317951288113176941478309745410310334782651770172026354186933563116697796501355264790672940852295099610547952544591650115530522009085389122636718498943445329078806839781792789370883772225511523767219416292426094549201262289177036554683123678986792213674781936483384339716510782577344754988535144989933000720065114400396122809121063080733323671879328342778896547907447628825538782498244363319093830278576075443652558654452333917040005312850333739542839388135766956853272216749309615122"
		"1381017320147344991331421789379785964440840684363041795410525097564979585773948558651896834067324427900848255265001498890329859444233861478388742393060996236783742654761350763876989363052609107226398858310051497856931093693697981165801539060516895227818925342535261227134364063673285588256280386915163875872231395348293505967057794409379709079685798908660258077792158532257603211711587587586356431658240229896344639704"_s));
	$init($RoundingMode);
	if ($nc($(total->setScale(0, $RoundingMode::DOWN)))->equals($(total->setScale(0, $RoundingMode::DOWN)))) {
		return 0;
	} else {
		return 1;
	}
}

void ZeroScalingTests::main($StringArray* argv) {
	$init(ZeroScalingTests);
	$useLocalCurrentObjectStackCache();
	int32_t failures = 0;
	failures += addTests();
	failures += subtractTests();
	failures += multiplyTests();
	failures += divideTests();
	failures += setScaleTests();
	failures += toEngineeringStringTests();
	failures += ulpTests();
	failures += setScaleDoesNotMutateTest();
	if (failures > 0) {
		$throwNew($RuntimeException, $$str({"Incurred "_s, $$str(failures), " failures testing the preservation of zero scales."_s}));
	}
}

void clinit$ZeroScalingTests($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$init($RoundingMode);
	$assignStatic(ZeroScalingTests::longEnough, $new($MathContext, 50, $RoundingMode::UNNECESSARY));
	$assignStatic(ZeroScalingTests::zeros, $new($BigDecimalArray, 23));
	{
		for (int32_t i = 0; i < 21; ++i) {
			$init($BigInteger);
			$nc(ZeroScalingTests::zeros)->set(i, $$new($BigDecimal, $BigInteger::ZERO, i - 10));
		}
		$init($BigInteger);
		$nc(ZeroScalingTests::zeros)->set(21, $$new($BigDecimal, $BigInteger::ZERO, $Integer::MIN_VALUE));
		$nc(ZeroScalingTests::zeros)->set(22, $$new($BigDecimal, $BigInteger::ZERO, $Integer::MAX_VALUE));
	}
	$assignStatic(ZeroScalingTests::element, $BigDecimal::valueOf(100, -2));
	$assignStatic(ZeroScalingTests::contexts, $new($MathContextArray, {
		$$new($MathContext, 0, $RoundingMode::UNNECESSARY),
		$$new($MathContext, 100, $RoundingMode::UNNECESSARY),
		$$new($MathContext, 5, $RoundingMode::UNNECESSARY),
		$$new($MathContext, 4, $RoundingMode::UNNECESSARY),
		$$new($MathContext, 3, $RoundingMode::UNNECESSARY),
		$$new($MathContext, 2, $RoundingMode::UNNECESSARY),
		$$new($MathContext, 1, $RoundingMode::UNNECESSARY)
	}));
}

ZeroScalingTests::ZeroScalingTests() {
}

$Class* ZeroScalingTests::load$($String* name, bool initialize) {
	$loadClass(ZeroScalingTests, name, initialize, &_ZeroScalingTests_ClassInfo_, clinit$ZeroScalingTests, allocate$ZeroScalingTests);
	return class$;
}

$Class* ZeroScalingTests::class$ = nullptr;