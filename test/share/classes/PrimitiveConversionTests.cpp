#include <PrimitiveConversionTests.h>

#include <java/math/BigInteger.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Random.h>
#include <jcpp.h>

#undef ALL_BIGINTEGER_CANDIDATES
#undef MAX_EXPONENT
#undef ONE

using $IntegerArray = $Array<::java::lang::Integer>;
using $BigIntegerArray = $Array<::java::math::BigInteger>;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $BigInteger = ::java::math::BigInteger;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Random = ::java::util::Random;

$FieldInfo _PrimitiveConversionTests_FieldInfo_[] = {
	{"ALL_BIGINTEGER_CANDIDATES", "Ljava/util/List;", "Ljava/util/List<Ljava/math/BigInteger;>;", $STATIC | $FINAL, $staticField(PrimitiveConversionTests, ALL_BIGINTEGER_CANDIDATES)},
	{}
};

$MethodInfo _PrimitiveConversionTests_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PrimitiveConversionTests, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(PrimitiveConversionTests, main, void, $StringArray*)},
	{"testDoubleValue", "()I", nullptr, $PUBLIC | $STATIC, $staticMethod(PrimitiveConversionTests, testDoubleValue, int32_t)},
	{"testFloatValue", "()I", nullptr, $PUBLIC | $STATIC, $staticMethod(PrimitiveConversionTests, testFloatValue, int32_t)},
	{}
};

$ClassInfo _PrimitiveConversionTests_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"PrimitiveConversionTests",
	"java.lang.Object",
	nullptr,
	_PrimitiveConversionTests_FieldInfo_,
	_PrimitiveConversionTests_MethodInfo_
};

$Object* allocate$PrimitiveConversionTests($Class* clazz) {
	return $of($alloc(PrimitiveConversionTests));
}

$List* PrimitiveConversionTests::ALL_BIGINTEGER_CANDIDATES = nullptr;

void PrimitiveConversionTests::init$() {
}

int32_t PrimitiveConversionTests::testDoubleValue() {
	$init(PrimitiveConversionTests);
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println("--- testDoubleValue ---"_s);
	int32_t failures = 0;
	{
		$var($Iterator, i$, $nc(PrimitiveConversionTests::ALL_BIGINTEGER_CANDIDATES)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($BigInteger, big, $cast($BigInteger, i$->next()));
			{
				double expected = $Double::parseDouble($($nc(big)->toString()));
				double actual = $nc(big)->doubleValue();
				int64_t var$0 = $Double::doubleToRawLongBits(expected);
				if (var$0 != $Double::doubleToRawLongBits(actual)) {
					$nc($System::out)->format("big: %s, expected: %f, actual: %f%n"_s, $$new($ObjectArray, {
						$of(big),
						$($of($Double::valueOf(expected))),
						$($of($Double::valueOf(actual)))
					}));
					++failures;
				}
			}
		}
	}
	return failures;
}

int32_t PrimitiveConversionTests::testFloatValue() {
	$init(PrimitiveConversionTests);
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println("--- testFloatValue ---"_s);
	int32_t failures = 0;
	{
		$var($Iterator, i$, $nc(PrimitiveConversionTests::ALL_BIGINTEGER_CANDIDATES)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($BigInteger, big, $cast($BigInteger, i$->next()));
			{
				float expected = $Float::parseFloat($($nc(big)->toString()));
				float actual = $nc(big)->floatValue();
				int32_t var$0 = $Float::floatToRawIntBits(expected);
				if (var$0 != $Float::floatToRawIntBits(actual)) {
					$nc($System::out)->format("big: %s, expected: %f, actual: %f%n"_s, $$new($ObjectArray, {
						$of(big),
						$($of($Float::valueOf(expected))),
						$($of($Float::valueOf(actual)))
					}));
					++failures;
				}
			}
		}
	}
	return failures;
}

void PrimitiveConversionTests::main($StringArray* args) {
	$init(PrimitiveConversionTests);
	$useLocalCurrentObjectStackCache();
	int32_t failures = testDoubleValue();
	failures += testFloatValue();
	if (failures > 0) {
		$throwNew($RuntimeException, $$str({"Incurred "_s, $$str(failures), " failures while testing primitive conversions."_s}));
	}
}

void clinit$PrimitiveConversionTests($Class* class$) {
	$useLocalCurrentObjectStackCache();
	{
		$var($List, samples, $new($ArrayList));
		{
			$var($Iterator, i$, $nc($($Arrays::asList($$new($IntegerArray, {
				$($Integer::valueOf(0)),
				$($Integer::valueOf(1)),
				$($Integer::valueOf(2)),
				$($Integer::valueOf(3)),
				$($Integer::valueOf(4)),
				$($Integer::valueOf(5)),
				$($Integer::valueOf(6)),
				$($Integer::valueOf(7)),
				$($Integer::valueOf(31)),
				$($Integer::valueOf(32)),
				$($Integer::valueOf(33)),
				$($Integer::valueOf(34)),
				$($Integer::valueOf(62)),
				$($Integer::valueOf(63)),
				$($Integer::valueOf(64)),
				$($Integer::valueOf(65)),
				$($Integer::valueOf(71)),
				$($Integer::valueOf(72)),
				$($Integer::valueOf(73)),
				$($Integer::valueOf(79)),
				$($Integer::valueOf(80)),
				$($Integer::valueOf(81)),
				$($Integer::valueOf(255)),
				$($Integer::valueOf(256)),
				$($Integer::valueOf(257)),
				$($Integer::valueOf(511)),
				$($Integer::valueOf(512)),
				$($Integer::valueOf(513)),
				$($Integer::valueOf($Double::MAX_EXPONENT - 1)),
				$($Integer::valueOf($Double::MAX_EXPONENT)),
				$($Integer::valueOf($Double::MAX_EXPONENT + 1)),
				$($Integer::valueOf(2000)),
				$($Integer::valueOf(2001)),
				$($Integer::valueOf(2002))
			}))))->iterator());
			for (; $nc(i$)->hasNext();) {
				int32_t exponent = $nc(($cast($Integer, $(i$->next()))))->intValue();
				{
					$init($BigInteger);
					$var($BigInteger, x, $nc($BigInteger::ONE)->shiftLeft(exponent));
					{
						$var($Iterator, i$, $nc($($Arrays::asList($$new($BigIntegerArray, {
							x,
							$($nc(x)->add($BigInteger::ONE)),
							$(x->subtract($BigInteger::ONE))
						}))))->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($BigInteger, y, $cast($BigInteger, i$->next()));
							{
								samples->add(y);
								samples->add($($nc(y)->negate()));
							}
						}
					}
				}
			}
		}
		$var($Random, rng, $new($Random, 0x0012D687));
		for (int32_t i = 0; i < 2000; ++i) {
			samples->add($$new($BigInteger, rng->nextInt(2000), rng));
		}
		$assignStatic(PrimitiveConversionTests::ALL_BIGINTEGER_CANDIDATES, $Collections::unmodifiableList(samples));
	}
}

PrimitiveConversionTests::PrimitiveConversionTests() {
}

$Class* PrimitiveConversionTests::load$($String* name, bool initialize) {
	$loadClass(PrimitiveConversionTests, name, initialize, &_PrimitiveConversionTests_ClassInfo_, clinit$PrimitiveConversionTests, allocate$PrimitiveConversionTests);
	return class$;
}

$Class* PrimitiveConversionTests::class$ = nullptr;