#include <Bug6609740.h>

#include <java/lang/Number.h>
#include <java/text/DecimalFormat.h>
#include <java/text/NumberFormat.h>
#include <java/text/ParseException.h>
#include <java/util/Locale.h>
#include <jcpp.h>

#undef US

using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Number = ::java::lang::Number;
using $RuntimeException = ::java::lang::RuntimeException;
using $DecimalFormat = ::java::text::DecimalFormat;
using $NumberFormat = ::java::text::NumberFormat;
using $ParseException = ::java::text::ParseException;
using $Locale = ::java::util::Locale;

$MethodInfo _Bug6609740_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Bug6609740, init$, void)},
	{"formatOnPattern", "(Ljava/text/NumberFormat;Ljava/lang/String;DLjava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Bug6609740, formatOnPattern, void, $NumberFormat*, $String*, double, $String*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Bug6609740, main, void, $StringArray*)},
	{"parseOnPattern", "(Ljava/text/NumberFormat;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Number;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Bug6609740, parseOnPattern, void, $NumberFormat*, $String*, $String*, $Number*)},
	{}
};

$ClassInfo _Bug6609740_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Bug6609740",
	"java.lang.Object",
	nullptr,
	nullptr,
	_Bug6609740_MethodInfo_
};

$Object* allocate$Bug6609740($Class* clazz) {
	return $of($alloc(Bug6609740));
}

void Bug6609740::init$() {
}

void Bug6609740::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	double dNumber = -3456.349347;
	$var($String, fOutput, "(3,456.35)"_s);
	$var($StringArray, validCases, $new($StringArray, {
		"#,##0.0#;(#,##0.0#)"_s,
		"#,##0.0#;(#)"_s,
		"#,##0.0#;(#,##0)"_s
	}));
	$init($Locale);
	$var($NumberFormat, nf, $NumberFormat::getInstance($Locale::US));
	{
		$var($StringArray, arr$, validCases);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, pattern, arr$->get(i$));
			{
				formatOnPattern(nf, pattern, dNumber, fOutput);
			}
		}
	}
	$var($String, parseString, "(3,456.35)"_s);
	$var($Number, pOutput, $Double::valueOf(-3456.35));
	{
		$var($StringArray, arr$, validCases);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, pattern, arr$->get(i$));
			{
				parseOnPattern(nf, pattern, parseString, pOutput);
			}
		}
	}
	$var($StringArray, invalidParseCases, $new($StringArray, {
		"#,##0.0#;0"_s,
		"#,##0.0#;()"_s
	}));
	{
		$var($StringArray, arr$, invalidParseCases);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, pattern, arr$->get(i$));
			{
				if ($instanceOf($DecimalFormat, nf)) {
					$nc(($cast($DecimalFormat, nf)))->applyPattern(pattern);
				}
				try {
					$nc(nf)->parse(parseString);
				} catch ($ParseException& ex) {
					continue;
				}
				$throwNew($RuntimeException, $$str({"[FAILED: Should throw ParseException for pattern: "_s, pattern, " and input: "_s, parseString, "]"_s}));
			}
		}
	}
	$var($StringArray, invalidPatterns, $new($StringArray, {
		";(#,##0.0#)"_s,
		"#,##0.0#0;(#)"_s,
		"#,##0.0.#"_s,
		"#,##0%%"_s,
		".#,##0"_s
	}));
	{
		$var($StringArray, arr$, invalidPatterns);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, pattern, arr$->get(i$));
			{
				if ($instanceOf($DecimalFormat, nf)) {
					try {
						$nc(($cast($DecimalFormat, nf)))->applyPattern(pattern);
					} catch ($IllegalArgumentException& ex) {
						continue;
					}
					$throwNew($RuntimeException, $$str({"[FAILED: Should throw IllegalArgumentException for invalid pattern: "_s, pattern, "]"_s}));
				}
			}
		}
	}
}

void Bug6609740::formatOnPattern($NumberFormat* nf, $String* pattern, double number, $String* expected) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($DecimalFormat, nf)) {
		$nc(($cast($DecimalFormat, nf)))->applyPattern(pattern);
	}
	$var($String, formatted, $nc(nf)->format(number));
	if (!$nc(formatted)->equals(expected)) {
		$throwNew($RuntimeException, $$str({"[FAILED: Unable to format the number based on the pattern: \'"_s, pattern, "\', Expected : \'"_s, expected, "\', Found: \'"_s, formatted, "\']"_s}));
	}
}

void Bug6609740::parseOnPattern($NumberFormat* nf, $String* pattern, $String* parseString, $Number* expected) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($DecimalFormat, nf)) {
		$nc(($cast($DecimalFormat, nf)))->applyPattern(pattern);
	}
	try {
		$var($Number, output, $nc(nf)->parse(parseString));
		double var$0 = $nc(expected)->doubleValue();
		if (var$0 != $nc(output)->doubleValue()) {
			$throwNew($RuntimeException, $$str({"[FAILED: Unable to parse the number based on the pattern: \'"_s, pattern, "\', Expected : \'"_s, expected, "\', Found: \'"_s, output, "\']"_s}));
		}
	} catch ($ParseException& ex) {
		$throwNew($RuntimeException, $$str({"[FAILED: Unable to parse the pattern: \'"_s, pattern, "\']"_s}), ex);
	}
}

Bug6609740::Bug6609740() {
}

$Class* Bug6609740::load$($String* name, bool initialize) {
	$loadClass(Bug6609740, name, initialize, &_Bug6609740_ClassInfo_, allocate$Bug6609740);
	return class$;
}

$Class* Bug6609740::class$ = nullptr;