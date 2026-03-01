#include <Basic4Version.h>

#include <java/io/Serializable.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/Runtime$Version.h>
#include <java/lang/Runtime.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/math/BigInteger.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/List.h>
#include <java/util/Optional.h>
#include <java/util/function/Function.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/Stream.h>
#include <jcpp.h>

#undef IAE
#undef MAX_VALUE
#undef NFE
#undef NPE
#undef ONE
#undef TOO_BIG
#undef TOO_BIG_STR

using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $Runtime = ::java::lang::Runtime;
using $Runtime$Version = ::java::lang::Runtime$Version;
using $RuntimeException = ::java::lang::RuntimeException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $BigInteger = ::java::math::BigInteger;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $List = ::java::util::List;
using $Optional = ::java::util::Optional;
using $Function = ::java::util::function::Function;
using $Collectors = ::java::util::stream::Collectors;
using $Stream = ::java::util::stream::Stream;

class Basic4Version$$Lambda$parseInt : public $Function {
	$class(Basic4Version$$Lambda$parseInt, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* arg0) override {
		 return $of($Integer::parseInt($cast($String, arg0)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Basic4Version$$Lambda$parseInt>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Basic4Version$$Lambda$parseInt::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Basic4Version$$Lambda$parseInt, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Basic4Version$$Lambda$parseInt, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Basic4Version$$Lambda$parseInt::classInfo$ = {
	$PUBLIC | $FINAL,
	"Basic4Version$$Lambda$parseInt",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Basic4Version$$Lambda$parseInt::load$($String* name, bool initialize) {
	$loadClass(Basic4Version$$Lambda$parseInt, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Basic4Version$$Lambda$parseInt::class$ = nullptr;

$FieldInfo _Basic4Version_FieldInfo_[] = {
	{"IAE", "Ljava/lang/Class;", "Ljava/lang/Class<+Ljava/lang/Throwable;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Basic4Version, IAE)},
	{"NPE", "Ljava/lang/Class;", "Ljava/lang/Class<+Ljava/lang/Throwable;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Basic4Version, NPE)},
	{"NFE", "Ljava/lang/Class;", "Ljava/lang/Class<+Ljava/lang/Throwable;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Basic4Version, NFE)},
	{"TOO_BIG", "Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Basic4Version, TOO_BIG)},
	{"TOO_BIG_STR", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Basic4Version, TOO_BIG_STR)},
	{"fail", "I", nullptr, $PRIVATE | $STATIC, $staticField(Basic4Version, fail$)},
	{"pass", "I", nullptr, $PRIVATE | $STATIC, $staticField(Basic4Version, pass$)},
	{"first", "Ljava/lang/Throwable;", nullptr, $PRIVATE | $STATIC, $staticField(Basic4Version, first)},
	{}
};

$MethodInfo _Basic4Version_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Basic4Version, init$, void)},
	{"checkCompare", "(Ljava/lang/Runtime$Version;Ljava/lang/Runtime$Version;II)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Basic4Version, checkCompare, void, $Runtime$Version*, $Runtime$Version*, int32_t, int32_t)},
	{"fail", "(Ljava/lang/String;Ljava/lang/Class;)V", nullptr, $STATIC, $staticMethod(Basic4Version, fail, void, $String*, $Class*)},
	{"fail", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(Basic4Version, fail, void, $String*, $String*, $String*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(Basic4Version, main, void, $StringArray*)},
	{"pass", "()V", nullptr, $STATIC, $staticMethod(Basic4Version, pass, void)},
	{"setFirst", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Basic4Version, setFirst, void, $String*)},
	{"test", "(Ljava/lang/String;Ljava/lang/Integer;Ljava/lang/Integer;Ljava/lang/Integer;Ljava/lang/Integer;Ljava/lang/String;Ljava/lang/Integer;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Basic4Version, test, void, $String*, $Integer*, $Integer*, $Integer*, $Integer*, $String*, $Integer*, $String*)},
	{"testCompare", "(Ljava/lang/Runtime$Version;Ljava/lang/Runtime$Version;I)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Basic4Version, testCompare, void, $Runtime$Version*, $Runtime$Version*, int32_t)},
	{"testCompareNO", "(Ljava/lang/Runtime$Version;Ljava/lang/Runtime$Version;I)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Basic4Version, testCompareNO, void, $Runtime$Version*, $Runtime$Version*, int32_t)},
	{"testEHC", "(Ljava/lang/String;Ljava/lang/String;ZZII)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Basic4Version, testEHC, void, $String*, $String*, bool, bool, int32_t, int32_t)},
	{"testEquals", "(Ljava/lang/Runtime$Version;Ljava/lang/Runtime$Version;Z)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Basic4Version, testEquals, void, $Runtime$Version*, $Runtime$Version*, bool)},
	{"testEqualsNO", "(Ljava/lang/Runtime$Version;Ljava/lang/Runtime$Version;Z)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Basic4Version, testEqualsNO, void, $Runtime$Version*, $Runtime$Version*, bool)},
	{"testHashCode", "(Ljava/lang/Runtime$Version;Ljava/lang/Runtime$Version;Z)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Basic4Version, testHashCode, void, $Runtime$Version*, $Runtime$Version*, bool)},
	{"testInt", "(II)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Basic4Version, testInt, void, int32_t, int32_t)},
	{"testParse", "(Ljava/lang/String;)Ljava/lang/Runtime$Version;", nullptr, $PRIVATE | $STATIC, $staticMethod(Basic4Version, testParse, $Runtime$Version*, $String*)},
	{"testStr", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Basic4Version, testStr, void, $String*, $String*)},
	{"testVersion", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Basic4Version, testVersion, void)},
	{"testVersion", "(Ljava/util/List;Ljava/lang/String;)V", "(Ljava/util/List<Ljava/lang/Integer;>;Ljava/lang/String;)V", $PRIVATE | $STATIC, $staticMethod(Basic4Version, testVersion, void, $List*, $String*)},
	{"tryCatch", "(Ljava/lang/String;Ljava/lang/Class;)V", "(Ljava/lang/String;Ljava/lang/Class<+Ljava/lang/Throwable;>;)V", $PRIVATE | $STATIC, $staticMethod(Basic4Version, tryCatch, void, $String*, $Class*)},
	{}
};

$ClassInfo _Basic4Version_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Basic4Version",
	"java.lang.Object",
	nullptr,
	_Basic4Version_FieldInfo_,
	_Basic4Version_MethodInfo_
};

$Object* allocate$Basic4Version($Class* clazz) {
	return $of($alloc(Basic4Version));
}

$Class* Basic4Version::IAE = nullptr;
$Class* Basic4Version::NPE = nullptr;
$Class* Basic4Version::NFE = nullptr;
$BigInteger* Basic4Version::TOO_BIG = nullptr;
$String* Basic4Version::TOO_BIG_STR = nullptr;
int32_t Basic4Version::fail$ = 0;
int32_t Basic4Version::pass$ = 0;
$Throwable* Basic4Version::first = nullptr;

void Basic4Version::init$() {
}

void Basic4Version::main($StringArray* args) {
	$init(Basic4Version);
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, "9"_s);
	$var($Integer, var$1, $Integer::valueOf(9));
	$var($Integer, var$2, $Integer::valueOf(0));
	$var($Integer, var$3, $Integer::valueOf(0));
	$var($Integer, var$4, $Integer::valueOf(0));
	$var($String, var$5, ""_s);
	test(var$0, var$1, var$2, var$3, var$4, var$5, $($Integer::valueOf(0)), ""_s);
	$var($String, var$6, "9.1"_s);
	$var($Integer, var$7, $Integer::valueOf(9));
	$var($Integer, var$8, $Integer::valueOf(1));
	$var($Integer, var$9, $Integer::valueOf(0));
	$var($Integer, var$10, $Integer::valueOf(0));
	$var($String, var$11, ""_s);
	test(var$6, var$7, var$8, var$9, var$10, var$11, $($Integer::valueOf(0)), ""_s);
	$var($String, var$12, "9.0.1"_s);
	$var($Integer, var$13, $Integer::valueOf(9));
	$var($Integer, var$14, $Integer::valueOf(0));
	$var($Integer, var$15, $Integer::valueOf(1));
	$var($Integer, var$16, $Integer::valueOf(0));
	$var($String, var$17, ""_s);
	test(var$12, var$13, var$14, var$15, var$16, var$17, $($Integer::valueOf(0)), ""_s);
	$var($String, var$18, "9.0.0.1"_s);
	$var($Integer, var$19, $Integer::valueOf(9));
	$var($Integer, var$20, $Integer::valueOf(0));
	$var($Integer, var$21, $Integer::valueOf(0));
	$var($Integer, var$22, $Integer::valueOf(1));
	$var($String, var$23, ""_s);
	test(var$18, var$19, var$20, var$21, var$22, var$23, $($Integer::valueOf(0)), ""_s);
	$var($String, var$24, "9.0.0.0.1"_s);
	$var($Integer, var$25, $Integer::valueOf(9));
	$var($Integer, var$26, $Integer::valueOf(0));
	$var($Integer, var$27, $Integer::valueOf(0));
	$var($Integer, var$28, $Integer::valueOf(0));
	$var($String, var$29, ""_s);
	test(var$24, var$25, var$26, var$27, var$28, var$29, $($Integer::valueOf(0)), ""_s);
	$var($String, var$30, "404.1.2"_s);
	$var($Integer, var$31, $Integer::valueOf(404));
	$var($Integer, var$32, $Integer::valueOf(1));
	$var($Integer, var$33, $Integer::valueOf(2));
	$var($Integer, var$34, $Integer::valueOf(0));
	$var($String, var$35, ""_s);
	test(var$30, var$31, var$32, var$33, var$34, var$35, $($Integer::valueOf(0)), ""_s);
	$var($String, var$36, "9.1.2.3"_s);
	$var($Integer, var$37, $Integer::valueOf(9));
	$var($Integer, var$38, $Integer::valueOf(1));
	$var($Integer, var$39, $Integer::valueOf(2));
	$var($Integer, var$40, $Integer::valueOf(3));
	$var($String, var$41, ""_s);
	test(var$36, var$37, var$38, var$39, var$40, var$41, $($Integer::valueOf(0)), ""_s);
	$var($String, var$42, "1000.0.0.0.0.0.99999999"_s);
	$var($Integer, var$43, $Integer::valueOf(1000));
	$var($Integer, var$44, $Integer::valueOf(0));
	$var($Integer, var$45, $Integer::valueOf(0));
	$var($Integer, var$46, $Integer::valueOf(0));
	$var($String, var$47, ""_s);
	test(var$42, var$43, var$44, var$45, var$46, var$47, $($Integer::valueOf(0)), ""_s);
	tryCatch(nullptr, Basic4Version::NPE);
	tryCatch(""_s, Basic4Version::IAE);
	tryCatch("foo"_s, Basic4Version::IAE);
	tryCatch("7a"_s, Basic4Version::IAE);
	tryCatch("0"_s, Basic4Version::IAE);
	tryCatch("09"_s, Basic4Version::IAE);
	tryCatch("9.0"_s, Basic4Version::IAE);
	tryCatch("9.0."_s, Basic4Version::IAE);
	tryCatch("1.9,1"_s, Basic4Version::IAE);
	tryCatch(Basic4Version::TOO_BIG_STR, Basic4Version::NFE);
	$var($String, var$48, "9-ea"_s);
	$var($Integer, var$49, $Integer::valueOf(9));
	$var($Integer, var$50, $Integer::valueOf(0));
	$var($Integer, var$51, $Integer::valueOf(0));
	$var($Integer, var$52, $Integer::valueOf(0));
	$var($String, var$53, "ea"_s);
	test(var$48, var$49, var$50, var$51, var$52, var$53, $($Integer::valueOf(0)), ""_s);
	$var($String, var$54, "9-internal"_s);
	$var($Integer, var$55, $Integer::valueOf(9));
	$var($Integer, var$56, $Integer::valueOf(0));
	$var($Integer, var$57, $Integer::valueOf(0));
	$var($Integer, var$58, $Integer::valueOf(0));
	$var($String, var$59, "internal"_s);
	test(var$54, var$55, var$56, var$57, var$58, var$59, $($Integer::valueOf(0)), ""_s);
	$var($String, var$60, "9-0"_s);
	$var($Integer, var$61, $Integer::valueOf(9));
	$var($Integer, var$62, $Integer::valueOf(0));
	$var($Integer, var$63, $Integer::valueOf(0));
	$var($Integer, var$64, $Integer::valueOf(0));
	$var($String, var$65, "0"_s);
	test(var$60, var$61, var$62, var$63, var$64, var$65, $($Integer::valueOf(0)), ""_s);
	$var($String, var$66, "9.2.7-8"_s);
	$var($Integer, var$67, $Integer::valueOf(9));
	$var($Integer, var$68, $Integer::valueOf(2));
	$var($Integer, var$69, $Integer::valueOf(7));
	$var($Integer, var$70, $Integer::valueOf(0));
	$var($String, var$71, "8"_s);
	test(var$66, var$67, var$68, var$69, var$70, var$71, $($Integer::valueOf(0)), ""_s);
	$var($String, var$72, "1-ALL"_s);
	$var($Integer, var$73, $Integer::valueOf(1));
	$var($Integer, var$74, $Integer::valueOf(0));
	$var($Integer, var$75, $Integer::valueOf(0));
	$var($Integer, var$76, $Integer::valueOf(0));
	$var($String, var$77, "ALL"_s);
	test(var$72, var$73, var$74, var$75, var$76, var$77, $($Integer::valueOf(0)), ""_s);
	$var($String, var$78, "2.3.4.5-1a"_s);
	$var($Integer, var$79, $Integer::valueOf(2));
	$var($Integer, var$80, $Integer::valueOf(3));
	$var($Integer, var$81, $Integer::valueOf(4));
	$var($Integer, var$82, $Integer::valueOf(5));
	$var($String, var$83, "1a"_s);
	test(var$78, var$79, var$80, var$81, var$82, var$83, $($Integer::valueOf(0)), ""_s);
	$var($String, var$84, $str({"1-"_s, Basic4Version::TOO_BIG_STR}));
	$var($Integer, var$85, $Integer::valueOf(1));
	$var($Integer, var$86, $Integer::valueOf(0));
	$var($Integer, var$87, $Integer::valueOf(0));
	$var($Integer, var$88, $Integer::valueOf(0));
	$var($String, var$89, Basic4Version::TOO_BIG_STR);
	test(var$84, var$85, var$86, var$87, var$88, var$89, $($Integer::valueOf(0)), ""_s);
	tryCatch("9:-ea"_s, Basic4Version::IAE);
	tryCatch("3.14159-"_s, Basic4Version::IAE);
	tryCatch("3.14159-%"_s, Basic4Version::IAE);
	$var($String, var$90, "9+0"_s);
	$var($Integer, var$91, $Integer::valueOf(9));
	$var($Integer, var$92, $Integer::valueOf(0));
	$var($Integer, var$93, $Integer::valueOf(0));
	$var($Integer, var$94, $Integer::valueOf(0));
	$var($String, var$95, ""_s);
	test(var$90, var$91, var$92, var$93, var$94, var$95, $($Integer::valueOf(0)), ""_s);
	$var($String, var$96, "3.14+9999900"_s);
	$var($Integer, var$97, $Integer::valueOf(3));
	$var($Integer, var$98, $Integer::valueOf(14));
	$var($Integer, var$99, $Integer::valueOf(0));
	$var($Integer, var$100, $Integer::valueOf(0));
	$var($String, var$101, ""_s);
	test(var$96, var$97, var$98, var$99, var$100, var$101, $($Integer::valueOf(0x0098961C)), ""_s);
	$var($String, var$102, "9-pre+105"_s);
	$var($Integer, var$103, $Integer::valueOf(9));
	$var($Integer, var$104, $Integer::valueOf(0));
	$var($Integer, var$105, $Integer::valueOf(0));
	$var($Integer, var$106, $Integer::valueOf(0));
	$var($String, var$107, "pre"_s);
	test(var$102, var$103, var$104, var$105, var$106, var$107, $($Integer::valueOf(105)), ""_s);
	$var($String, var$108, "6.0.42-8beta+4"_s);
	$var($Integer, var$109, $Integer::valueOf(6));
	$var($Integer, var$110, $Integer::valueOf(0));
	$var($Integer, var$111, $Integer::valueOf(42));
	$var($Integer, var$112, $Integer::valueOf(0));
	$var($String, var$113, "8beta"_s);
	test(var$108, var$109, var$110, var$111, var$112, var$113, $($Integer::valueOf(4)), ""_s);
	tryCatch("9+"_s, Basic4Version::IAE);
	tryCatch("7+a"_s, Basic4Version::IAE);
	tryCatch("9+00"_s, Basic4Version::IAE);
	tryCatch("4.2+01"_s, Basic4Version::IAE);
	tryCatch("4.2+1a"_s, Basic4Version::IAE);
	tryCatch($$str({"1+"_s, Basic4Version::TOO_BIG_STR}), Basic4Version::NFE);
	$var($String, var$114, "9+-foo"_s);
	$var($Integer, var$115, $Integer::valueOf(9));
	$var($Integer, var$116, $Integer::valueOf(0));
	$var($Integer, var$117, $Integer::valueOf(0));
	$var($Integer, var$118, $Integer::valueOf(0));
	$var($String, var$119, ""_s);
	test(var$114, var$115, var$116, var$117, var$118, var$119, $($Integer::valueOf(0)), "foo"_s);
	$var($String, var$120, "9-pre-opt"_s);
	$var($Integer, var$121, $Integer::valueOf(9));
	$var($Integer, var$122, $Integer::valueOf(0));
	$var($Integer, var$123, $Integer::valueOf(0));
	$var($Integer, var$124, $Integer::valueOf(0));
	$var($String, var$125, "pre"_s);
	test(var$120, var$121, var$122, var$123, var$124, var$125, $($Integer::valueOf(0)), "opt"_s);
	$var($String, var$126, "42+---bar"_s);
	$var($Integer, var$127, $Integer::valueOf(42));
	$var($Integer, var$128, $Integer::valueOf(0));
	$var($Integer, var$129, $Integer::valueOf(0));
	$var($Integer, var$130, $Integer::valueOf(0));
	$var($String, var$131, ""_s);
	test(var$126, var$127, var$128, var$129, var$130, var$131, $($Integer::valueOf(0)), "--bar"_s);
	$var($String, var$132, "2.91+-8061493-"_s);
	$var($Integer, var$133, $Integer::valueOf(2));
	$var($Integer, var$134, $Integer::valueOf(91));
	$var($Integer, var$135, $Integer::valueOf(0));
	$var($Integer, var$136, $Integer::valueOf(0));
	$var($String, var$137, ""_s);
	test(var$132, var$133, var$134, var$135, var$136, var$137, $($Integer::valueOf(0)), "8061493-"_s);
	$var($String, var$138, "24+-foo.bar"_s);
	$var($Integer, var$139, $Integer::valueOf(24));
	$var($Integer, var$140, $Integer::valueOf(0));
	$var($Integer, var$141, $Integer::valueOf(0));
	$var($Integer, var$142, $Integer::valueOf(0));
	$var($String, var$143, ""_s);
	test(var$138, var$139, var$140, var$141, var$142, var$143, $($Integer::valueOf(0)), "foo.bar"_s);
	$var($String, var$144, "9-ribbit+17-..."_s);
	$var($Integer, var$145, $Integer::valueOf(9));
	$var($Integer, var$146, $Integer::valueOf(0));
	$var($Integer, var$147, $Integer::valueOf(0));
	$var($Integer, var$148, $Integer::valueOf(0));
	$var($String, var$149, "ribbit"_s);
	test(var$144, var$145, var$146, var$147, var$148, var$149, $($Integer::valueOf(17)), "..."_s);
	$var($String, var$150, $str({"7+1-"_s, Basic4Version::TOO_BIG_STR}));
	$var($Integer, var$151, $Integer::valueOf(7));
	$var($Integer, var$152, $Integer::valueOf(0));
	$var($Integer, var$153, $Integer::valueOf(0));
	$var($Integer, var$154, $Integer::valueOf(0));
	$var($String, var$155, ""_s);
	test(var$150, var$151, var$152, var$153, var$154, var$155, $($Integer::valueOf(1)), Basic4Version::TOO_BIG_STR);
	tryCatch("9-pre+-opt"_s, Basic4Version::IAE);
	tryCatch("1.4142+-"_s, Basic4Version::IAE);
	tryCatch("2.9979+-%"_s, Basic4Version::IAE);
	tryCatch("10--ea"_s, Basic4Version::IAE);
	testVersion();
	testEHC("9"_s, "9"_s, true, true, 0, 0);
	testEHC("8"_s, "9"_s, false, false, -1, -1);
	testEHC("9"_s, "10"_s, false, false, -1, -1);
	testEHC("9"_s, "8"_s, false, false, 1, 1);
	testEHC("10.512.1"_s, "10.512.2"_s, false, false, -1, -1);
	testEHC("10.512.0.1"_s, "10.512.0.2"_s, false, false, -1, -1);
	testEHC("10.512.0.0.1"_s, "10.512.0.0.2"_s, false, false, -1, -1);
	testEHC("512.10.1"_s, "512.11.1"_s, false, false, -1, -1);
	testEHC("9"_s, "9+-oink"_s, false, true, -1, 0);
	testEHC("9+-ribbit"_s, "9+-moo"_s, false, true, 1, 0);
	testEHC("9-quack+3-ribbit"_s, "9-quack+3-moo"_s, false, true, 1, 0);
	testEHC("9.1+7"_s, "9.1+7-moo-baa-la"_s, false, true, -1, 0);
	testEHC("9.1.1.2-2a"_s, "9.1.1.2-12"_s, false, false, 1, 1);
	testEHC("9.1.1.2-12"_s, "9.1.1.2-4"_s, false, false, 1, 1);
	testEHC("27.16"_s, "27.16+120"_s, false, false, -1, -1);
	testEHC("10"_s, "10-ea"_s, false, false, 1, 1);
	testEHC("10.1+1"_s, "10.1-ea+1"_s, false, false, 1, 1);
	testEHC("10.0.1+22"_s, "10.0.1+21"_s, false, false, 1, 1);
	testEHC("9.1.1.2-12"_s, "9.1.1.2-a2"_s, false, false, -1, -1);
	testEHC("9.1.1.2-1"_s, "9.1.1.2-4"_s, false, false, -1, -1);
	testEHC("9-internal"_s, "9"_s, false, false, -1, -1);
	testEHC("9-ea+120"_s, "9+120"_s, false, false, -1, -1);
	testEHC("9-ea+120"_s, "9+120"_s, false, false, -1, -1);
	testEHC("9+101"_s, "9"_s, false, false, 1, 1);
	testEHC("9+101"_s, "9+102"_s, false, false, -1, -1);
	testEHC("1.9-ea"_s, "9-ea"_s, false, false, -1, -1);
	if (Basic4Version::fail$ != 0) {
		$throwNew($RuntimeException, $$str({$$str((Basic4Version::fail$ + Basic4Version::pass$)), " tests: "_s, $$str(Basic4Version::fail$), " failure(s), first"_s}), Basic4Version::first);
	} else {
		$nc($System::out)->println($$str({"all "_s, $$str((Basic4Version::fail$ + Basic4Version::pass$)), " tests passed"_s}));
	}
}

void Basic4Version::test($String* s, $Integer* feature, $Integer* interim, $Integer* update, $Integer* patch, $String* pre, $Integer* build, $String* opt) {
	$init(Basic4Version);
	$useLocalCurrentObjectStackCache();
	$var($Runtime$Version, v, testParse(s));
	testStr($($nc(v)->toString()), s);
	int32_t var$0 = $nc(v)->feature();
	testInt(var$0, $nc(feature)->intValue());
	int32_t var$1 = $nc(v)->major();
	testInt(var$1, $nc(feature)->intValue());
	int32_t var$2 = $nc(v)->interim();
	testInt(var$2, $nc(interim)->intValue());
	int32_t var$3 = $nc(v)->minor();
	testInt(var$3, $nc(interim)->intValue());
	int32_t var$4 = $nc(v)->update();
	testInt(var$4, $nc(update)->intValue());
	int32_t var$5 = $nc(v)->security();
	testInt(var$5, $nc(update)->intValue());
	int32_t var$6 = $nc(v)->patch();
	testInt(var$6, $nc(patch)->intValue());
	testStr(($nc($($nc(v)->pre()))->isPresent() ? $cast($String, $($nc($($nc(v)->pre()))->get())) : ""_s), pre);
	int32_t var$7 = ($nc($($nc(v)->build()))->isPresent() ? $nc(($cast($Integer, $($nc($($nc(v)->build()))->get()))))->intValue() : 0);
	testInt(var$7, $nc(build)->intValue());
	testStr(($nc($($nc(v)->optional()))->isPresent() ? $cast($String, $($nc($($nc(v)->optional()))->get())) : ""_s), opt);
	testVersion($($nc(v)->version()), s);
}

$Runtime$Version* Basic4Version::testParse($String* s) {
	$init(Basic4Version);
	$var($Runtime$Version, v, $Runtime$Version::parse(s));
	pass();
	return v;
}

void Basic4Version::testInt(int32_t got, int32_t exp) {
	$init(Basic4Version);
	$useLocalCurrentObjectStackCache();
	if (got != exp) {
		$var($String, var$0, "testInt()"_s);
		$var($String, var$1, $Integer::toString(exp));
		fail(var$0, var$1, $($Integer::toString(got)));
	} else {
		pass();
	}
}

void Basic4Version::testStr($String* got, $String* exp) {
	$init(Basic4Version);
	if (!$nc(got)->equals(exp)) {
		fail("testStr()"_s, exp, got);
	} else {
		pass();
	}
}

void Basic4Version::tryCatch($String* s, $Class* ex) {
	$init(Basic4Version);
	$var($Throwable, t, nullptr);
	try {
		$Runtime$Version::parse(s);
	} catch ($Throwable& x) {
		if ($nc(ex)->isAssignableFrom($of(x)->getClass())) {
			$assign(t, x);
		} else {
			x->printStackTrace();
		}
	}
	if ((t == nullptr) && (ex != nullptr)) {
		fail(s, ex);
	} else {
		pass();
	}
}

void Basic4Version::testVersion() {
	$init(Basic4Version);
	$useLocalCurrentObjectStackCache();
	$var($Runtime$Version, current, $Runtime::version());
	$var($String, javaVer, $System::getProperty("java.runtime.version"_s));
	$var($StringArray, jv, $nc(javaVer)->split("\\+"_s));
	$var($StringArray, ver, $nc(jv->get(0))->split("-"_s));
	$var($List, javaVerVNum, $cast($List, $nc($($nc($($Arrays::stream($($nc(ver->get(0))->split("\\."_s)))))->map(static_cast<$Function*>($$new(Basic4Version$$Lambda$parseInt)))))->collect($($Collectors::toList()))));
	if (!$nc(javaVerVNum)->equals($($nc(current)->version()))) {
		$var($String, var$0, "Runtime.version()"_s);
		$var($String, var$1, $of(javaVerVNum)->toString());
		fail(var$0, var$1, $($nc($of($($nc(current)->version())))->toString()));
	} else {
		pass();
	}
	$var($Optional, javaVerPre, (ver->length == 2) ? $Optional::ofNullable(ver->get(1)) : $Optional::empty());
	if (!$nc(javaVerPre)->equals($($nc(current)->pre()))) {
		$var($String, var$2, "testCurrent() pre()"_s);
		$var($String, var$3, javaVerPre->toString());
		fail(var$2, var$3, $($nc($($nc(current)->pre()))->toString()));
	} else {
		pass();
	}
	testEHC($($nc(current)->toString()), javaVer, true, true, 0, 0);
}

void Basic4Version::testVersion($List* vnum, $String* s) {
	$init(Basic4Version);
	$useLocalCurrentObjectStackCache();
	$var($List, svnum, $new($ArrayList));
	$var($StringBuilder, sb, $new($StringBuilder));
	for (int32_t i = 0; i < $nc(s)->length(); ++i) {
		$var($Character, c, $Character::valueOf(s->charAt(i)));
		if ($Character::isDigit($nc(c)->charValue())) {
			sb->append($of(c));
		} else {
			svnum->add($($Integer::valueOf($Integer::parseInt($(sb->toString())))));
			$assign(sb, $new($StringBuilder));
			bool var$0 = $nc(c)->charValue() == u'+';
			if (var$0 || $nc(c)->charValue() == u'-') {
				break;
			}
		}
	}
	if (sb->length() > 0) {
		svnum->add($($Integer::valueOf($Integer::parseInt($(sb->toString())))));
	}
	if (!svnum->equals(vnum)) {
		$var($String, var$1, "testVersion() equals()"_s);
		$var($String, var$2, $of(svnum)->toString());
		fail(var$1, var$2, $($nc($of(vnum))->toString()));
	} else {
		pass();
	}
}

void Basic4Version::testEHC($String* s0, $String* s1, bool eq, bool eqNO, int32_t cmp, int32_t cmpNO) {
	$init(Basic4Version);
	$useLocalCurrentObjectStackCache();
	$var($Runtime$Version, v0, $Runtime$Version::parse(s0));
	$var($Runtime$Version, v1, $Runtime$Version::parse(s1));
	testEquals(v0, v1, eq);
	testEqualsNO(v0, v1, eqNO);
	testHashCode(v0, v1, eq);
	testCompare(v0, v1, cmp);
	testCompareNO(v0, v1, cmpNO);
}

void Basic4Version::testEqualsNO($Runtime$Version* v0, $Runtime$Version* v1, bool eq) {
	$init(Basic4Version);
	$useLocalCurrentObjectStackCache();
	if (eq == $nc(v0)->equalsIgnoreOptional(v1)) {
		pass();
	} else {
		$var($String, var$0, $str({"equalsIgnoreOptional() "_s, $($Boolean::toString(eq))}));
		$var($String, var$1, v0->toString());
		fail(var$0, var$1, $($nc(v1)->toString()));
	}
}

void Basic4Version::testEquals($Runtime$Version* v0, $Runtime$Version* v1, bool eq) {
	$init(Basic4Version);
	$useLocalCurrentObjectStackCache();
	if (eq == $nc(v0)->equals(v1)) {
		pass();
	} else {
		$var($String, var$0, $str({"equals() "_s, $($Boolean::toString(eq))}));
		$var($String, var$1, v0->toString());
		fail(var$0, var$1, $($nc(v1)->toString()));
	}
}

void Basic4Version::testHashCode($Runtime$Version* v0, $Runtime$Version* v1, bool eq) {
	$init(Basic4Version);
	$useLocalCurrentObjectStackCache();
	int32_t h0 = $nc(v0)->hashCode();
	int32_t h1 = $nc(v1)->hashCode();
	if (eq) {
		testInt(h0, h1);
	} else if (h0 == h1) {
		$var($String, var$0, $String::format("hashCode() %s"_s, $$new($ObjectArray, {$($of($Integer::valueOf(h0)))})));
		$var($String, var$1, $Integer::toString(h0));
		fail(var$0, var$1, $($Integer::toString(h1)));
	} else {
		pass();
	}
}

void Basic4Version::testCompareNO($Runtime$Version* v0, $Runtime$Version* v1, int32_t compare) {
	$init(Basic4Version);
	int32_t cmp = $nc(v0)->compareToIgnoreOptional(v1);
	checkCompare(v0, v1, compare, cmp);
}

void Basic4Version::testCompare($Runtime$Version* v0, $Runtime$Version* v1, int32_t compare) {
	$init(Basic4Version);
	int32_t cmp = $nc(v0)->compareTo(v1);
	checkCompare(v0, v1, compare, cmp);
}

void Basic4Version::checkCompare($Runtime$Version* v0, $Runtime$Version* v1, int32_t expected, int32_t actual) {
	$init(Basic4Version);
	$useLocalCurrentObjectStackCache();
	int32_t var$0 = $Integer::signum(expected);
	if (var$0 == $Integer::signum(actual)) {
		pass();
	} else {
		$var($String, var$1, $String::format("compare() (actual = %s) (expected = %s)"_s, $$new($ObjectArray, {
			$($of($Integer::valueOf(actual))),
			$($of($Integer::valueOf(expected)))
		})));
		$var($String, var$2, $nc(v0)->toString());
		fail(var$1, var$2, $($nc(v1)->toString()));
	}
}

void Basic4Version::pass() {
	$init(Basic4Version);
	++Basic4Version::pass$;
}

void Basic4Version::fail($String* fs, $Class* ex) {
	$init(Basic4Version);
	$useLocalCurrentObjectStackCache();
	$var($String, s, $str({"\'"_s, fs, "\'"_s}));
	if (ex != nullptr) {
		$plusAssign(s, $$str({": "_s, $(ex->getName()), " not thrown"_s}));
	}
	if (Basic4Version::first == nullptr) {
		setFirst(s);
	}
	$nc($System::err)->println($$str({"FAILED: "_s, s}));
	++Basic4Version::fail$;
}

void Basic4Version::fail($String* t, $String* exp, $String* got) {
	$init(Basic4Version);
	$useLocalCurrentObjectStackCache();
	$var($String, s, $str({t, ": Expected \'"_s, exp, "\', got \'"_s, got, "\'"_s}));
	if (Basic4Version::first == nullptr) {
		setFirst(s);
	}
	$nc($System::err)->println($$str({"FAILED: "_s, s}));
	++Basic4Version::fail$;
}

void Basic4Version::setFirst($String* s) {
	$init(Basic4Version);
	try {
		$throwNew($RuntimeException, s);
	} catch ($RuntimeException& x) {
		$assignStatic(Basic4Version::first, x);
	}
}

void clinit$Basic4Version($Class* class$) {
	$load($IllegalArgumentException);
	$assignStatic(Basic4Version::IAE, $IllegalArgumentException::class$);
	$load($NullPointerException);
	$assignStatic(Basic4Version::NPE, $NullPointerException::class$);
	$load($NumberFormatException);
	$assignStatic(Basic4Version::NFE, $NumberFormatException::class$);
	$init($BigInteger);
	$assignStatic(Basic4Version::TOO_BIG, $nc(($($BigInteger::valueOf((int64_t)$Integer::MAX_VALUE))))->add($BigInteger::ONE));
	$assignStatic(Basic4Version::TOO_BIG_STR, $nc(Basic4Version::TOO_BIG)->toString());
	Basic4Version::fail$ = 0;
	Basic4Version::pass$ = 0;
}

Basic4Version::Basic4Version() {
}

$Class* Basic4Version::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Basic4Version$$Lambda$parseInt::classInfo$.name)) {
			return Basic4Version$$Lambda$parseInt::load$(name, initialize);
		}
	}
	$loadClass(Basic4Version, name, initialize, &_Basic4Version_ClassInfo_, clinit$Basic4Version, allocate$Basic4Version);
	return class$;
}

$Class* Basic4Version::class$ = nullptr;