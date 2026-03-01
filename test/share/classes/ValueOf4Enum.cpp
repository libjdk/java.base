#include <ValueOf4Enum.h>

#include <ValueOf4Enum$Silly0.h>
#include <ValueOf4Enum$Silly1.h>
#include <ValueOf4Enum$Silly127.h>
#include <ValueOf4Enum$Silly128.h>
#include <ValueOf4Enum$Silly129.h>
#include <ValueOf4Enum$Silly31.h>
#include <ValueOf4Enum$Silly32.h>
#include <ValueOf4Enum$Silly33.h>
#include <ValueOf4Enum$Silly500.h>
#include <ValueOf4Enum$Silly63.h>
#include <ValueOf4Enum$Silly64.h>
#include <ValueOf4Enum$Silly65.h>
#include <ValueOf4Enum$Specialized.h>
#include <java/lang/Enum.h>
#include <java/lang/reflect/Method.h>
#include <java/util/EnumSet.h>
#include <java/util/Iterator.h>
#include <java/util/Random.h>
#include <java/util/Set.h>
#include <jcpp.h>

using $ValueOf4Enum$Silly0 = ::ValueOf4Enum$Silly0;
using $ValueOf4Enum$Silly1 = ::ValueOf4Enum$Silly1;
using $ValueOf4Enum$Silly127 = ::ValueOf4Enum$Silly127;
using $ValueOf4Enum$Silly128 = ::ValueOf4Enum$Silly128;
using $ValueOf4Enum$Silly129 = ::ValueOf4Enum$Silly129;
using $ValueOf4Enum$Silly31 = ::ValueOf4Enum$Silly31;
using $ValueOf4Enum$Silly32 = ::ValueOf4Enum$Silly32;
using $ValueOf4Enum$Silly33 = ::ValueOf4Enum$Silly33;
using $ValueOf4Enum$Silly500 = ::ValueOf4Enum$Silly500;
using $ValueOf4Enum$Silly63 = ::ValueOf4Enum$Silly63;
using $ValueOf4Enum$Silly64 = ::ValueOf4Enum$Silly64;
using $ValueOf4Enum$Silly65 = ::ValueOf4Enum$Silly65;
using $ValueOf4Enum$Specialized = ::ValueOf4Enum$Specialized;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Method = ::java::lang::reflect::Method;
using $EnumSet = ::java::util::EnumSet;
using $Iterator = ::java::util::Iterator;
using $Random = ::java::util::Random;
using $Set = ::java::util::Set;

$FieldInfo _ValueOf4Enum_FieldInfo_[] = {
	{"rnd", "Ljava/util/Random;", nullptr, $STATIC, $staticField(ValueOf4Enum, rnd)},
	{}
};

$MethodInfo _ValueOf4Enum_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ValueOf4Enum, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ValueOf4Enum, main, void, $StringArray*), "java.lang.Exception"},
	{"test", "(Ljava/lang/Class;)V", "<T:Ljava/lang/Enum<TT;>;>(Ljava/lang/Class<TT;>;)V", $STATIC, $staticMethod(ValueOf4Enum, test, void, $Class*), "java.lang.Exception"},
	{"test", "(Ljava/lang/Class;Ljava/util/Set;)V", "<T:Ljava/lang/Enum<TT;>;>(Ljava/lang/Class<TT;>;Ljava/util/Set<TT;>;)V", $STATIC, $staticMethod(ValueOf4Enum, test, void, $Class*, $Set*), "java.lang.Exception"},
	{"testMissingException", "()V", nullptr, $STATIC, $staticMethod(ValueOf4Enum, testMissingException, void)},
	{}
};

$InnerClassInfo _ValueOf4Enum_InnerClassesInfo_[] = {
	{"ValueOf4Enum$Specialized", "ValueOf4Enum", "Specialized", $STATIC | $ABSTRACT | $ENUM},
	{"ValueOf4Enum$Silly500", "ValueOf4Enum", "Silly500", $STATIC | $FINAL | $ENUM},
	{"ValueOf4Enum$Silly129", "ValueOf4Enum", "Silly129", $STATIC | $FINAL | $ENUM},
	{"ValueOf4Enum$Silly128", "ValueOf4Enum", "Silly128", $STATIC | $FINAL | $ENUM},
	{"ValueOf4Enum$Silly127", "ValueOf4Enum", "Silly127", $STATIC | $FINAL | $ENUM},
	{"ValueOf4Enum$Silly65", "ValueOf4Enum", "Silly65", $STATIC | $FINAL | $ENUM},
	{"ValueOf4Enum$Silly64", "ValueOf4Enum", "Silly64", $STATIC | $FINAL | $ENUM},
	{"ValueOf4Enum$Silly63", "ValueOf4Enum", "Silly63", $STATIC | $FINAL | $ENUM},
	{"ValueOf4Enum$Silly33", "ValueOf4Enum", "Silly33", $STATIC | $FINAL | $ENUM},
	{"ValueOf4Enum$Silly32", "ValueOf4Enum", "Silly32", $STATIC | $FINAL | $ENUM},
	{"ValueOf4Enum$Silly31", "ValueOf4Enum", "Silly31", $STATIC | $FINAL | $ENUM},
	{"ValueOf4Enum$Silly1", "ValueOf4Enum", "Silly1", $STATIC | $FINAL | $ENUM},
	{"ValueOf4Enum$Silly0", "ValueOf4Enum", "Silly0", $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _ValueOf4Enum_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ValueOf4Enum",
	"java.lang.Object",
	nullptr,
	_ValueOf4Enum_FieldInfo_,
	_ValueOf4Enum_MethodInfo_,
	nullptr,
	nullptr,
	_ValueOf4Enum_InnerClassesInfo_,
	nullptr,
	nullptr,
	"ValueOf4Enum$Specialized,ValueOf4Enum$Specialized$1,ValueOf4Enum$Silly500,ValueOf4Enum$Silly129,ValueOf4Enum$Silly128,ValueOf4Enum$Silly127,ValueOf4Enum$Silly65,ValueOf4Enum$Silly64,ValueOf4Enum$Silly63,ValueOf4Enum$Silly33,ValueOf4Enum$Silly32,ValueOf4Enum$Silly31,ValueOf4Enum$Silly1,ValueOf4Enum$Silly0"
};

$Object* allocate$ValueOf4Enum($Class* clazz) {
	return $of($alloc(ValueOf4Enum));
}

$Random* ValueOf4Enum::rnd = nullptr;

void ValueOf4Enum::init$() {
}

void ValueOf4Enum::main($StringArray* args) {
	$init(ValueOf4Enum);
	$load($ValueOf4Enum$Silly0);
	test($ValueOf4Enum$Silly0::class$);
	$load($ValueOf4Enum$Silly1);
	test($ValueOf4Enum$Silly1::class$);
	$load($ValueOf4Enum$Silly31);
	test($ValueOf4Enum$Silly31::class$);
	$load($ValueOf4Enum$Silly32);
	test($ValueOf4Enum$Silly32::class$);
	$load($ValueOf4Enum$Silly33);
	test($ValueOf4Enum$Silly33::class$);
	$load($ValueOf4Enum$Silly63);
	test($ValueOf4Enum$Silly63::class$);
	$load($ValueOf4Enum$Silly64);
	test($ValueOf4Enum$Silly64::class$);
	$load($ValueOf4Enum$Silly65);
	test($ValueOf4Enum$Silly65::class$);
	$load($ValueOf4Enum$Silly127);
	test($ValueOf4Enum$Silly127::class$);
	$load($ValueOf4Enum$Silly128);
	test($ValueOf4Enum$Silly128::class$);
	$load($ValueOf4Enum$Silly129);
	test($ValueOf4Enum$Silly129::class$);
	$load($ValueOf4Enum$Silly500);
	test($ValueOf4Enum$Silly500::class$);
	$load($ValueOf4Enum$Specialized);
	test($ValueOf4Enum$Specialized::class$);
	testMissingException();
}

void ValueOf4Enum::test($Class* enumClass) {
	$init(ValueOf4Enum);
	$useLocalCurrentObjectStackCache();
	$var($Set, s, $EnumSet::allOf(enumClass));
	test(enumClass, s);
	{
		$var($Iterator, i, $nc(s)->iterator());
		for (; $nc(i)->hasNext();) {
			i->next();
			if ($nc(ValueOf4Enum::rnd)->nextBoolean()) {
				i->remove();
			}
		}
	}
	test(enumClass, s);
}

void ValueOf4Enum::test($Class* enumClass, $Set* s) {
	$init(ValueOf4Enum);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Method, valueOf, $nc(enumClass)->getDeclaredMethod("valueOf"_s, $$new($ClassArray, {$String::class$})));
	$var($Set, copy, $EnumSet::noneOf(enumClass));
	{
		$var($Iterator, i$, $nc(s)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Enum, e, $cast($Enum, i$->next()));
			$nc(copy)->add($cast($Enum, $($nc(valueOf)->invoke(nullptr, $$new($ObjectArray, {$($of($nc(e)->name()))})))));
		}
	}
	if (!$nc(copy)->equals(s)) {
		$throwNew($Exception, $$str({copy, " != "_s, s}));
	}
}

void ValueOf4Enum::testMissingException() {
	$init(ValueOf4Enum);
	$useLocalCurrentObjectStackCache();
	try {
		$load($ValueOf4Enum$Specialized);
		$Enum::valueOf($ValueOf4Enum$Specialized::class$, "BAZ"_s);
		$throwNew($RuntimeException, "Expected IllegalArgumentException not thrown."_s);
	} catch ($IllegalArgumentException& iae) {
		$var($String, message, iae->getMessage());
		if (!"No enum constant ValueOf4Enum.Specialized.BAZ"_s->equals(message)) {
			$throwNew($RuntimeException, $$str({"Unexpected detail message: ``"_s, message, "\'\'."_s}));
		}
	}
}

void clinit$ValueOf4Enum($Class* class$) {
	$assignStatic(ValueOf4Enum::rnd, $new($Random));
}

ValueOf4Enum::ValueOf4Enum() {
}

$Class* ValueOf4Enum::load$($String* name, bool initialize) {
	$loadClass(ValueOf4Enum, name, initialize, &_ValueOf4Enum_ClassInfo_, clinit$ValueOf4Enum, allocate$ValueOf4Enum);
	return class$;
}

$Class* ValueOf4Enum::class$ = nullptr;