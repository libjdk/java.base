#include <Test7087570.h>

#include <DummyFieldHolder.h>
#include <Test7087570$TestMethodData.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Error.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandleInfo.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/TypeDescriptor$OfField.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/Method.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collections.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <jcpp.h>

#undef LOOKUP
#undef TESTS
#undef TYPE

using $DummyFieldHolder = ::DummyFieldHolder;
using $Test7087570$TestMethodData = ::Test7087570$TestMethodData;
using $Test7087570$TestMethodDataArray = $Array<Test7087570$TestMethodData>;
using $LongArray = $Array<::java::lang::Long>;
using $PrintStream = ::java::io::PrintStream;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandleInfo = ::java::lang::invoke::MethodHandleInfo;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Constructor = ::java::lang::reflect::Constructor;
using $Field = ::java::lang::reflect::Field;
using $Method = ::java::lang::reflect::Method;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collections = ::java::util::Collections;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;

$FieldInfo _Test7087570_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Test7087570, $assertionsDisabled)},
	{"TESTS", "[LTest7087570$TestMethodData;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test7087570, TESTS)},
	{"LOOKUP", "Ljava/lang/invoke/MethodHandles$Lookup;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test7087570, LOOKUP)},
	{"specialMethodHandles", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/invoke/MethodHandle;>;", $PRIVATE | $STATIC, $staticField(Test7087570, specialMethodHandles)},
	{}
};

$MethodInfo _Test7087570_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Test7087570, init$, void)},
	{"assertEquals", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test7087570, assertEquals, void, Object$*, Object$*)},
	{"assertRefKindEquals", "(II)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test7087570, assertRefKindEquals, void, int32_t, int32_t)},
	{"data", "(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/invoke/MethodType;Ljava/lang/Class;I)LTest7087570$TestMethodData;", "(Ljava/lang/Class<*>;Ljava/lang/String;Ljava/lang/invoke/MethodType;Ljava/lang/Class<*>;I)LTest7087570$TestMethodData;", $PRIVATE | $STATIC, $staticMethod(Test7087570, data, $Test7087570$TestMethodData*, $Class*, $String*, $MethodType*, $Class*, int32_t)},
	{"doTest", "(Ljava/lang/invoke/MethodHandle;LTest7087570$TestMethodData;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test7087570, doTest, void, $MethodHandle*, $Test7087570$TestMethodData*)},
	{"getterMethodType", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodType;", "(Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodType;", $PRIVATE | $STATIC, $staticMethod(Test7087570, getterMethodType, $MethodType*, $Class*)},
	{"isInvokeSpecial", "(Ljava/lang/invoke/MethodHandle;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(Test7087570, isInvokeSpecial, bool, $MethodHandle*)},
	{"lookupFrom", "(LTest7087570$TestMethodData;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(Test7087570, lookupFrom, $MethodHandle*, $Test7087570$TestMethodData*), "java.lang.NoSuchMethodException,java.lang.NoSuchFieldException,java.lang.IllegalAccessException"},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(Test7087570, main, void, $StringArray*), "java.lang.Throwable"},
	{"noteInvokeSpecial", "(Ljava/lang/invoke/MethodHandle;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test7087570, noteInvokeSpecial, void, $MethodHandle*)},
	{"setterMethodType", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodType;", "(Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodType;", $PRIVATE | $STATIC, $staticMethod(Test7087570, setterMethodType, $MethodType*, $Class*)},
	{"testWithLookup", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test7087570, testWithLookup, void), "java.lang.Throwable"},
	{"testWithUnreflect", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test7087570, testWithUnreflect, void), "java.lang.Throwable"},
	{"unreflectFrom", "(LTest7087570$TestMethodData;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(Test7087570, unreflectFrom, $MethodHandle*, $Test7087570$TestMethodData*), "java.lang.NoSuchMethodException,java.lang.NoSuchFieldException,java.lang.IllegalAccessException"},
	{}
};

$InnerClassInfo _Test7087570_InnerClassesInfo_[] = {
	{"Test7087570$TestMethodData", "Test7087570", "TestMethodData", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _Test7087570_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Test7087570",
	"java.lang.Object",
	nullptr,
	_Test7087570_FieldInfo_,
	_Test7087570_MethodInfo_,
	nullptr,
	nullptr,
	_Test7087570_InnerClassesInfo_,
	nullptr,
	nullptr,
	"Test7087570$TestMethodData"
};

$Object* allocate$Test7087570($Class* clazz) {
	return $of($alloc(Test7087570));
}

bool Test7087570::$assertionsDisabled = false;
$Test7087570$TestMethodDataArray* Test7087570::TESTS = nullptr;
$MethodHandles$Lookup* Test7087570::LOOKUP = nullptr;
$List* Test7087570::specialMethodHandles = nullptr;

void Test7087570::init$() {
}

void Test7087570::main($StringArray* args) {
	$init(Test7087570);
	testWithLookup();
	testWithUnreflect();
}

void Test7087570::doTest($MethodHandle* mh, $Test7087570$TestMethodData* testMethod) {
	$init(Test7087570);
	$useLocalCurrentObjectStackCache();
	$var($MethodHandleInfo, mhi, $nc(Test7087570::LOOKUP)->revealDirect(mh));
	$nc($System::out)->printf("%s.%s: %s, nominal refKind: %s, actual refKind: %s\n"_s, $$new($ObjectArray, {
		$($of($nc($nc(testMethod)->clazz)->getName())),
		$of(testMethod->name),
		$of(testMethod->methodType),
		$($of($MethodHandleInfo::referenceKindToString(testMethod->referenceKind))),
		$($of($MethodHandleInfo::referenceKindToString($nc(mhi)->getReferenceKind())))
	}));
	assertEquals($nc(testMethod)->name, $($nc(mhi)->getName()));
	assertEquals($nc(testMethod)->methodType, $($nc(mhi)->getMethodType()));
	assertEquals($nc(testMethod)->declaringClass, $nc(mhi)->getDeclaringClass());
	$var($Object, var$0, $of($Boolean::valueOf($nc(testMethod)->referenceKind == 7)));
	assertEquals(var$0, $($Boolean::valueOf(isInvokeSpecial(mh))));
	assertRefKindEquals($nc(testMethod)->referenceKind, $nc(mhi)->getReferenceKind());
}

void Test7087570::testWithLookup() {
	$init(Test7087570);
	$useLocalCurrentObjectStackCache();
	{
		$var($Test7087570$TestMethodDataArray, arr$, Test7087570::TESTS);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Test7087570$TestMethodData, testMethod, arr$->get(i$));
			{
				$var($MethodHandle, mh, lookupFrom(testMethod));
				doTest(mh, testMethod);
			}
		}
	}
}

void Test7087570::testWithUnreflect() {
	$init(Test7087570);
	$useLocalCurrentObjectStackCache();
	{
		$var($Test7087570$TestMethodDataArray, arr$, Test7087570::TESTS);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Test7087570$TestMethodData, testMethod, arr$->get(i$));
			{
				$var($MethodHandle, mh, unreflectFrom(testMethod));
				doTest(mh, testMethod);
			}
		}
	}
}

$MethodType* Test7087570::getterMethodType($Class* clazz) {
	$init(Test7087570);
	return $MethodType::methodType(clazz);
}

$MethodType* Test7087570::setterMethodType($Class* clazz) {
	$init(Test7087570);
	$init($Void);
	return $MethodType::methodType($Void::TYPE, clazz);
}

$Test7087570$TestMethodData* Test7087570::data($Class* clazz, $String* name, $MethodType* methodType, $Class* declaringClass, int32_t referenceKind) {
	$init(Test7087570);
	return $new($Test7087570$TestMethodData, clazz, name, methodType, declaringClass, referenceKind);
}

$MethodHandle* Test7087570::lookupFrom($Test7087570$TestMethodData* testMethod) {
	$init(Test7087570);
	$useLocalCurrentObjectStackCache();
	{
		$var($Class, thisClass, nullptr)
		$var($MethodHandle, smh, nullptr)
		switch ($nc(testMethod)->referenceKind) {
		case 1:
			{
				return $nc(Test7087570::LOOKUP)->findGetter(testMethod->clazz, testMethod->name, $($cast($Class, $nc(testMethod->methodType)->returnType())));
			}
		case 3:
			{
				return $nc(Test7087570::LOOKUP)->findSetter(testMethod->clazz, testMethod->name, $($cast($Class, $nc(testMethod->methodType)->parameterType(0))));
			}
		case 2:
			{
				return $nc(Test7087570::LOOKUP)->findStaticGetter(testMethod->clazz, testMethod->name, $($cast($Class, $nc(testMethod->methodType)->returnType())));
			}
		case 4:
			{
				return $nc(Test7087570::LOOKUP)->findStaticSetter(testMethod->clazz, testMethod->name, $($cast($Class, $nc(testMethod->methodType)->parameterType(0))));
			}
		case 5:
			{}
		case 9:
			{
				return $nc(Test7087570::LOOKUP)->findVirtual(testMethod->clazz, testMethod->name, testMethod->methodType);
			}
		case 6:
			{
				return $nc(Test7087570::LOOKUP)->findStatic(testMethod->clazz, testMethod->name, testMethod->methodType);
			}
		case 7:
			{
				thisClass = $nc(Test7087570::LOOKUP)->lookupClass();
				$assign(smh, $nc(Test7087570::LOOKUP)->findSpecial(testMethod->clazz, testMethod->name, testMethod->methodType, thisClass));
				noteInvokeSpecial(smh);
				return smh;
			}
		case 8:
			{
				return $nc(Test7087570::LOOKUP)->findConstructor(testMethod->clazz, testMethod->methodType);
			}
		default:
			{
				$throwNew($Error, "ERROR: unexpected referenceKind in test data"_s);
			}
		}
	}
}

$MethodHandle* Test7087570::unreflectFrom($Test7087570$TestMethodData* testMethod) {
	$init(Test7087570);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	switch ($nc(testMethod)->referenceKind) {
	case 1:
		{}
	case 2:
		{
			{
				$var($Field, f, $nc(testMethod->clazz)->getDeclaredField(testMethod->name));
				return $nc(Test7087570::LOOKUP)->unreflectGetter(f);
			}
		}
	case 3:
		{}
	case 4:
		{
			{
				$var($Field, f, $nc(testMethod->clazz)->getDeclaredField(testMethod->name));
				return $nc(Test7087570::LOOKUP)->unreflectSetter(f);
			}
		}
	case 5:
		{}
	case 6:
		{}
	case 9:
		{
			{
				$var($Method, m, $nc(testMethod->clazz)->getDeclaredMethod(testMethod->name, $($fcast($ClassArray, $nc(testMethod->methodType)->parameterArray()))));
				return $nc(Test7087570::LOOKUP)->unreflect(m);
			}
		}
	case 7:
		{
			{
				$var($Method, m, $nc(testMethod->clazz)->getDeclaredMethod(testMethod->name, $($fcast($ClassArray, $nc(testMethod->methodType)->parameterArray()))));
				$Class* thisClass = $nc(Test7087570::LOOKUP)->lookupClass();
				$var($MethodHandle, smh, $nc(Test7087570::LOOKUP)->unreflectSpecial(m, thisClass));
				noteInvokeSpecial(smh);
				return smh;
			}
		}
	case 8:
		{
			{
				$var($Constructor, c, $nc(testMethod->clazz)->getDeclaredConstructor($($fcast($ClassArray, $nc(testMethod->methodType)->parameterArray()))));
				return $nc(Test7087570::LOOKUP)->unreflectConstructor(c);
			}
		}
	default:
		{
			$throwNew($Error, "ERROR: unexpected referenceKind in test data"_s);
		}
	}
}

void Test7087570::noteInvokeSpecial($MethodHandle* mh) {
	$init(Test7087570);
	$nc(Test7087570::specialMethodHandles)->add(mh);
	if (!Test7087570::$assertionsDisabled && !(isInvokeSpecial(mh))) {
		$throwNew($AssertionError);
	}
}

bool Test7087570::isInvokeSpecial($MethodHandle* mh) {
	$init(Test7087570);
	return $nc(Test7087570::specialMethodHandles)->contains(mh);
}

void Test7087570::assertRefKindEquals(int32_t expect, int32_t observed) {
	$init(Test7087570);
	$useLocalCurrentObjectStackCache();
	if (expect == observed) {
		return;
	}
	$var($String, var$0, $$str({"expected "_s, $($MethodHandleInfo::referenceKindToString(expect)), " but observed "_s}));
	$var($String, msg, $concat(var$0, $($MethodHandleInfo::referenceKindToString(observed))));
	$nc($System::out)->println($$str({"FAILED: "_s, msg}));
	$throwNew($AssertionError, $of(msg));
}

void Test7087570::assertEquals(Object$* expect, Object$* observed) {
	$init(Test7087570);
	$useLocalCurrentObjectStackCache();
	if ($Objects::equals(expect, observed)) {
		return;
	}
	$var($String, msg, $str({"expected "_s, expect, " but observed "_s, observed}));
	$nc($System::out)->println($$str({"FAILED: "_s, msg}));
	$throwNew($AssertionError, $of(msg));
}

void clinit$Test7087570($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	Test7087570::$assertionsDisabled = !Test7087570::class$->desiredAssertionStatus();
	$load($DummyFieldHolder);
	$load($Integer);
	$init($Byte);
	$init($Integer);
	$load($Collections);
	$init($Void);
	$load($List);
	$load($Arrays);
	$load($ObjectArray);
	$load($chars);
	$load($LongArray);
	$assignStatic(Test7087570::TESTS, $new($Test7087570$TestMethodDataArray, {
		$(Test7087570::data($DummyFieldHolder::class$, "instanceField"_s, $(Test7087570::getterMethodType($String::class$)), $DummyFieldHolder::class$, 1)),
		$(Test7087570::data($DummyFieldHolder::class$, "instanceField"_s, $(Test7087570::setterMethodType($String::class$)), $DummyFieldHolder::class$, 3)),
		$(Test7087570::data($DummyFieldHolder::class$, "staticField"_s, $(Test7087570::getterMethodType($Integer::class$)), $DummyFieldHolder::class$, 2)),
		$(Test7087570::data($DummyFieldHolder::class$, "staticField"_s, $(Test7087570::setterMethodType($Integer::class$)), $DummyFieldHolder::class$, 4)),
		$(Test7087570::data($DummyFieldHolder::class$, "instanceByteField"_s, $(Test7087570::getterMethodType($Byte::TYPE)), $DummyFieldHolder::class$, 1)),
		$(Test7087570::data($DummyFieldHolder::class$, "instanceByteField"_s, $(Test7087570::setterMethodType($Byte::TYPE)), $DummyFieldHolder::class$, 3)),
		$(Test7087570::data($Object::class$, "hashCode"_s, $($MethodType::methodType($Integer::TYPE)), $Object::class$, 5)),
		$(Test7087570::data($String::class$, "hashCode"_s, $($MethodType::methodType($Integer::TYPE)), $String::class$, 5)),
		$(Test7087570::data($Collections::class$, "sort"_s, $($MethodType::methodType($Void::TYPE, $List::class$)), $Collections::class$, 6)),
		$(Test7087570::data($Arrays::class$, "asList"_s, $($MethodType::methodType($List::class$, $getClass($ObjectArray))), $Arrays::class$, 6)),
		$(Test7087570::data($Object::class$, "hashCode"_s, $($MethodType::methodType($Integer::TYPE)), $Object::class$, 7)),
		$(Test7087570::data($String::class$, "<init>"_s, $($MethodType::methodType($Void::TYPE, $getClass($chars))), $String::class$, 8)),
		$(Test7087570::data($DummyFieldHolder::class$, "<init>"_s, $($MethodType::methodType($Void::TYPE, $Byte::TYPE, $$new($ClassArray, {$getClass($LongArray)}))), $DummyFieldHolder::class$, 8)),
		$(Test7087570::data($List::class$, "size"_s, $($MethodType::methodType($Integer::TYPE)), $List::class$, 9))
	}));
	$assignStatic(Test7087570::LOOKUP, $MethodHandles::lookup());
	$assignStatic(Test7087570::specialMethodHandles, $new($ArrayList));
}

Test7087570::Test7087570() {
}

$Class* Test7087570::load$($String* name, bool initialize) {
	$loadClass(Test7087570, name, initialize, &_Test7087570_ClassInfo_, clinit$Test7087570, allocate$Test7087570);
	return class$;
}

$Class* Test7087570::class$ = nullptr;