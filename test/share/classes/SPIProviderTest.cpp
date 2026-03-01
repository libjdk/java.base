#include <SPIProviderTest.h>

#include <java/io/Serializable.h>
#include <java/lang/Number.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/text/NumberFormat$Style.h>
#include <java/text/NumberFormat.h>
#include <java/text/ParseException.h>
#include <java/util/Arrays.h>
#include <java/util/Locale.h>
#include <java/util/function/Consumer.h>
#include <java/util/stream/Stream.h>
#include <jcpp.h>

#undef QAA
#undef QAB
#undef SHORT

using $ObjectArray2 = $Array<::java::lang::Object, 2>;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Number = ::java::lang::Number;
using $RuntimeException = ::java::lang::RuntimeException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $NumberFormat = ::java::text::NumberFormat;
using $NumberFormat$Style = ::java::text::NumberFormat$Style;
using $ParseException = ::java::text::ParseException;
using $Arrays = ::java::util::Arrays;
using $Locale = ::java::util::Locale;
using $Consumer = ::java::util::function::Consumer;
using $Stream = ::java::util::stream::Stream;

class SPIProviderTest$$Lambda$testSPIProvider : public $Consumer {
	$class(SPIProviderTest$$Lambda$testSPIProvider, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* args) override {
		SPIProviderTest::testSPIProvider($cast($ObjectArray, args));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SPIProviderTest$$Lambda$testSPIProvider>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo SPIProviderTest$$Lambda$testSPIProvider::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SPIProviderTest$$Lambda$testSPIProvider, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(SPIProviderTest$$Lambda$testSPIProvider, accept, void, Object$*)},
	{}
};
$ClassInfo SPIProviderTest$$Lambda$testSPIProvider::classInfo$ = {
	$PUBLIC | $FINAL,
	"SPIProviderTest$$Lambda$testSPIProvider",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* SPIProviderTest$$Lambda$testSPIProvider::load$($String* name, bool initialize) {
	$loadClass(SPIProviderTest$$Lambda$testSPIProvider, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SPIProviderTest$$Lambda$testSPIProvider::class$ = nullptr;

$FieldInfo _SPIProviderTest_FieldInfo_[] = {
	{"QAA", "Ljava/util/Locale;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SPIProviderTest, QAA)},
	{"QAB", "Ljava/util/Locale;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SPIProviderTest, QAB)},
	{}
};

$MethodInfo _SPIProviderTest_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(SPIProviderTest, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(SPIProviderTest, main, void, $StringArray*)},
	{"testData", "()[[Ljava/lang/Object;", nullptr, 0, $virtualMethod(SPIProviderTest, testData, $ObjectArray2*)},
	{"testSPIProvider", "([Ljava/lang/Object;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(SPIProviderTest, testSPIProvider, void, $ObjectArray*)},
	{}
};

$ClassInfo _SPIProviderTest_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"SPIProviderTest",
	"java.lang.Object",
	nullptr,
	_SPIProviderTest_FieldInfo_,
	_SPIProviderTest_MethodInfo_
};

$Object* allocate$SPIProviderTest($Class* clazz) {
	return $of($alloc(SPIProviderTest));
}

$Locale* SPIProviderTest::QAA = nullptr;
$Locale* SPIProviderTest::QAB = nullptr;

void SPIProviderTest::main($StringArray* args) {
	$init(SPIProviderTest);
	$new(SPIProviderTest);
}

void SPIProviderTest::init$() {
	$useLocalCurrentObjectStackCache();
	$nc($($Arrays::stream($(testData()))))->forEach(static_cast<$Consumer*>($$new(SPIProviderTest$$Lambda$testSPIProvider)));
}

$ObjectArray2* SPIProviderTest::testData() {
	$useLocalCurrentObjectStackCache();
	return $new($ObjectArray2, {
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAA),
			$($of($Integer::valueOf(1000))),
			$of("1K"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAA),
			$($of($Integer::valueOf(-1000))),
			$of("-1K"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAA),
			$($of($Integer::valueOf(2000))),
			$of("2K"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAA),
			$($of($Integer::valueOf(-2000))),
			$of("-2K"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAA),
			$($of($Integer::valueOf(0x000F4240))),
			$of("1M"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAA),
			$($of($Integer::valueOf((int32_t)0xFFF0BDC0))),
			$of("-1M"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAA),
			$($of($Integer::valueOf(0x001E8480))),
			$of("2M"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAA),
			$($of($Integer::valueOf((int32_t)0xFFE17B80))),
			$of("-2M"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAB),
			$($of($Integer::valueOf(1000))),
			$of("1K"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAB),
			$($of($Integer::valueOf(-1000))),
			$of("(1K)"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAB),
			$($of($Integer::valueOf(2000))),
			$of("2KK"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAB),
			$($of($Integer::valueOf(-2000))),
			$of("-2KK"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAB),
			$($of($Integer::valueOf(3000))),
			$of("3KKK"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAB),
			$($of($Integer::valueOf(-3000))),
			$of("-3KKK"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAB),
			$($of($Integer::valueOf(5000))),
			$of("5KKKK"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAB),
			$($of($Integer::valueOf(-5000))),
			$of("-5KKKK"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAB),
			$($of($Integer::valueOf(10000))),
			$of("10000"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAB),
			$($of($Integer::valueOf(-10000))),
			$of("-10000"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAB),
			$($of($Integer::valueOf(0x000F4240))),
			$of("1 M"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAB),
			$($of($Integer::valueOf((int32_t)0xFFF0BDC0))),
			$of("(1 M)"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAB),
			$($of($Integer::valueOf(0x001E8480))),
			$of("2 MM"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAB),
			$($of($Integer::valueOf((int32_t)0xFFE17B80))),
			$of("(2 MM)"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAB),
			$($of($Integer::valueOf(0x002DC6C0))),
			$of("3 MMM"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAB),
			$($of($Integer::valueOf((int32_t)0xFFD23940))),
			$of("-3 MMM"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAB),
			$($of($Integer::valueOf(0x004C4B40))),
			$of("5 MMMM"_s)
		}),
		$$new($ObjectArray, {
			$of(SPIProviderTest::QAB),
			$($of($Integer::valueOf((int32_t)0xFFB3B4C0))),
			$of("-5 MMMM"_s)
		})
	});
}

void SPIProviderTest::testSPIProvider($ObjectArray* args) {
	$init(SPIProviderTest);
	$useLocalCurrentObjectStackCache();
	$var($Locale, loc, $cast($Locale, $nc(args)->get(0)));
	$var($Number, number, $cast($Number, args->get(1)));
	$var($String, expected, $cast($String, args->get(2)));
	$nc($System::out)->printf("Testing locale: %s, number: %d, expected: %s\n"_s, $$new($ObjectArray, {
		$of(loc),
		$of(number),
		$of(expected)
	}));
	$init($NumberFormat$Style);
	$var($NumberFormat, nf, $NumberFormat::getCompactNumberInstance(loc, $NumberFormat$Style::SHORT));
	$var($String, formatted, $nc(nf)->format(number));
	$nc($System::out)->printf("    formatted: %s\n"_s, $$new($ObjectArray, {$of(formatted)}));
	if (!$nc(formatted)->equals(expected)) {
		$throwNew($RuntimeException, "formatted and expected strings do not match."_s);
	}
	try {
		$var($Number, parsed, nf->parse(formatted));
		$nc($System::out)->printf("    parsed: %s\n"_s, $$new($ObjectArray, {$of(parsed)}));
		int32_t var$0 = $nc(parsed)->intValue();
		if (var$0 != $nc(number)->intValue()) {
			$throwNew($RuntimeException, "parsed and input numbers do not match."_s);
		}
	} catch ($ParseException& pe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(pe));
	}
}

void clinit$SPIProviderTest($Class* class$) {
	$assignStatic(SPIProviderTest::QAA, $Locale::forLanguageTag("qaa"_s));
	$assignStatic(SPIProviderTest::QAB, $Locale::forLanguageTag("qab"_s));
}

SPIProviderTest::SPIProviderTest() {
}

$Class* SPIProviderTest::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SPIProviderTest$$Lambda$testSPIProvider::classInfo$.name)) {
			return SPIProviderTest$$Lambda$testSPIProvider::load$(name, initialize);
		}
	}
	$loadClass(SPIProviderTest, name, initialize, &_SPIProviderTest_ClassInfo_, clinit$SPIProviderTest, allocate$SPIProviderTest);
	return class$;
}

$Class* SPIProviderTest::class$ = nullptr;