#include <MetafactoryParameterCastTest.h>

#include <MetafactoryParameterCastTest$A.h>
#include <MetafactoryParameterCastTest$ASink.h>
#include <MetafactoryParameterCastTest$B.h>
#include <MetafactoryParameterCastTest$BSink.h>
#include <MetafactoryParameterCastTest$C.h>
#include <MetafactoryParameterCastTest$NotC.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaConversionException.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Arrays.h>
#include <jcpp.h>

#undef FLAG_BRIDGES
#undef TYPE

using $MetafactoryParameterCastTest$A = ::MetafactoryParameterCastTest$A;
using $MetafactoryParameterCastTest$ASink = ::MetafactoryParameterCastTest$ASink;
using $MetafactoryParameterCastTest$B = ::MetafactoryParameterCastTest$B;
using $MetafactoryParameterCastTest$BSink = ::MetafactoryParameterCastTest$BSink;
using $MetafactoryParameterCastTest$C = ::MetafactoryParameterCastTest$C;
using $MetafactoryParameterCastTest$NotC = ::MetafactoryParameterCastTest$NotC;
using $MethodHandleArray = $Array<::java::lang::invoke::MethodHandle>;
using $MethodTypeArray = $Array<::java::lang::invoke::MethodType>;
using $AssertionError = ::java::lang::AssertionError;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaConversionException = ::java::lang::invoke::LambdaConversionException;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Arrays = ::java::util::Arrays;

$FieldInfo _MetafactoryParameterCastTest_FieldInfo_[] = {
	{"lookup", "Ljava/lang/invoke/MethodHandles$Lookup;", nullptr, $STATIC | $FINAL, $staticField(MetafactoryParameterCastTest, lookup)},
	{"lastMH", "Ljava/lang/invoke/MethodHandle;", nullptr, 0, $field(MetafactoryParameterCastTest, lastMH)},
	{"lastCaptured", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", 0, $field(MetafactoryParameterCastTest, lastCaptured)},
	{"lastInstMT", "Ljava/lang/invoke/MethodType;", nullptr, 0, $field(MetafactoryParameterCastTest, lastInstMT)},
	{"lastSamMT", "Ljava/lang/invoke/MethodType;", nullptr, 0, $field(MetafactoryParameterCastTest, lastSamMT)},
	{"lastBridgeMTs", "[Ljava/lang/invoke/MethodType;", nullptr, 0, $field(MetafactoryParameterCastTest, lastBridgeMTs)},
	{}
};

$MethodInfo _MetafactoryParameterCastTest_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(MetafactoryParameterCastTest, init$, void)},
	{"invokeAltMetafactory", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/Class;Ljava/lang/String;[Ljava/lang/Class;Ljava/lang/invoke/MethodType;Ljava/lang/invoke/MethodType;[Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/CallSite;", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/Class<*>;Ljava/lang/String;[Ljava/lang/Class<*>;Ljava/lang/invoke/MethodType;Ljava/lang/invoke/MethodType;[Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/CallSite;", $TRANSIENT, $virtualMethod(MetafactoryParameterCastTest, invokeAltMetafactory, $CallSite*, $MethodHandle*, $Class*, $String*, $ClassArray*, $MethodType*, $MethodType*, $MethodTypeArray*)},
	{"invokeMetafactory", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/Class;Ljava/lang/String;[Ljava/lang/Class;Ljava/lang/invoke/MethodType;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/CallSite;", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/Class<*>;Ljava/lang/String;[Ljava/lang/Class<*>;Ljava/lang/invoke/MethodType;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/CallSite;", 0, $virtualMethod(MetafactoryParameterCastTest, invokeMetafactory, $CallSite*, $MethodHandle*, $Class*, $String*, $ClassArray*, $MethodType*, $MethodType*)},
	{"lastMFParams", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(MetafactoryParameterCastTest, lastMFParams, $String*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(MetafactoryParameterCastTest, main, void, $StringArray*), "java.lang.Throwable"},
	{"test", "()V", nullptr, 0, $virtualMethod(MetafactoryParameterCastTest, test, void), "java.lang.Throwable"},
	{"tryASink", "(Ljava/lang/invoke/CallSite;)V", nullptr, 0, $virtualMethod(MetafactoryParameterCastTest, tryASink, void, $CallSite*), "java.lang.Throwable"},
	{"tryASink", "(LMetafactoryParameterCastTest$ASink;)V", nullptr, 0, $virtualMethod(MetafactoryParameterCastTest, tryASink, void, $MetafactoryParameterCastTest$ASink*)},
	{"tryBSink", "(Ljava/lang/invoke/CallSite;)V", nullptr, 0, $virtualMethod(MetafactoryParameterCastTest, tryBSink, void, $CallSite*), "java.lang.Throwable"},
	{"tryBSink", "(LMetafactoryParameterCastTest$BSink;)V", nullptr, 0, $virtualMethod(MetafactoryParameterCastTest, tryBSink, void, $MetafactoryParameterCastTest$BSink*)},
	{"tryCapASink", "(Ljava/lang/invoke/CallSite;)V", nullptr, 0, $virtualMethod(MetafactoryParameterCastTest, tryCapASink, void, $CallSite*), "java.lang.Throwable"},
	{"tryCapBSink", "(Ljava/lang/invoke/CallSite;)V", nullptr, 0, $virtualMethod(MetafactoryParameterCastTest, tryCapBSink, void, $CallSite*), "java.lang.Throwable"},
	{}
};

$InnerClassInfo _MetafactoryParameterCastTest_InnerClassesInfo_[] = {
	{"MetafactoryParameterCastTest$BSink", "MetafactoryParameterCastTest", "BSink", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"MetafactoryParameterCastTest$ASink", "MetafactoryParameterCastTest", "ASink", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"MetafactoryParameterCastTest$NotC", "MetafactoryParameterCastTest", "NotC", $PUBLIC | $STATIC},
	{"MetafactoryParameterCastTest$C", "MetafactoryParameterCastTest", "C", $PUBLIC | $STATIC},
	{"MetafactoryParameterCastTest$B", "MetafactoryParameterCastTest", "B", $PUBLIC | $STATIC},
	{"MetafactoryParameterCastTest$A", "MetafactoryParameterCastTest", "A", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _MetafactoryParameterCastTest_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"MetafactoryParameterCastTest",
	"java.lang.Object",
	nullptr,
	_MetafactoryParameterCastTest_FieldInfo_,
	_MetafactoryParameterCastTest_MethodInfo_,
	nullptr,
	nullptr,
	_MetafactoryParameterCastTest_InnerClassesInfo_,
	nullptr,
	nullptr,
	"MetafactoryParameterCastTest$BSink,MetafactoryParameterCastTest$ASink,MetafactoryParameterCastTest$NotC,MetafactoryParameterCastTest$C,MetafactoryParameterCastTest$B,MetafactoryParameterCastTest$A"
};

$Object* allocate$MetafactoryParameterCastTest($Class* clazz) {
	return $of($alloc(MetafactoryParameterCastTest));
}

$MethodHandles$Lookup* MetafactoryParameterCastTest::lookup = nullptr;

void MetafactoryParameterCastTest::init$() {
}

void MetafactoryParameterCastTest::main($StringArray* args) {
	$init(MetafactoryParameterCastTest);
	$$new(MetafactoryParameterCastTest)->test();
}

void MetafactoryParameterCastTest::test() {
	$useLocalCurrentObjectStackCache();
	$init($Void);
	$load($MetafactoryParameterCastTest$A);
	$var($MethodType, takeA, $MethodType::methodType($Void::TYPE, $MetafactoryParameterCastTest$A::class$));
	$load($MetafactoryParameterCastTest$B);
	$var($MethodType, takeB, $MethodType::methodType($Void::TYPE, $MetafactoryParameterCastTest$B::class$));
	$load($MetafactoryParameterCastTest$C);
	$var($MethodType, takeC, $MethodType::methodType($Void::TYPE, $MetafactoryParameterCastTest$C::class$));
	$var($ClassArray, noCapture, $new($ClassArray, 0));
	$var($ClassArray, captureB, $new($ClassArray, {$MetafactoryParameterCastTest$B::class$}));
	$var($MethodHandleArray, oneBParam, $new($MethodHandleArray, {
		$($nc(MetafactoryParameterCastTest::lookup)->findVirtual($MetafactoryParameterCastTest$B::class$, "instance0"_s, $($MethodType::methodType($Void::TYPE)))),
		$($nc(MetafactoryParameterCastTest::lookup)->findStatic($MetafactoryParameterCastTest$B::class$, "static1"_s, $($MethodType::methodType($Void::TYPE, $MetafactoryParameterCastTest$B::class$))))
	}));
	$var($MethodHandleArray, twoBParams, $new($MethodHandleArray, {
		$($nc(MetafactoryParameterCastTest::lookup)->findVirtual($MetafactoryParameterCastTest$B::class$, "instance1"_s, $($MethodType::methodType($Void::TYPE, $MetafactoryParameterCastTest$B::class$)))),
		$($nc(MetafactoryParameterCastTest::lookup)->findStatic($MetafactoryParameterCastTest$B::class$, "static2"_s, $($MethodType::methodType($Void::TYPE, $MetafactoryParameterCastTest$B::class$, $$new($ClassArray, {$MetafactoryParameterCastTest$B::class$})))))
	}));
	{
		$var($MethodHandleArray, arr$, oneBParam);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($MethodHandle, mh, arr$->get(i$));
			{
				$load($MetafactoryParameterCastTest$ASink);
				tryASink($(invokeMetafactory(mh, $MetafactoryParameterCastTest$ASink::class$, "take"_s, noCapture, takeC, takeA)));
				$load($MetafactoryParameterCastTest$BSink);
				tryBSink($(invokeMetafactory(mh, $MetafactoryParameterCastTest$BSink::class$, "take"_s, noCapture, takeC, takeB)));
				tryASink($(invokeAltMetafactory(mh, $MetafactoryParameterCastTest$ASink::class$, "take"_s, noCapture, takeC, takeA, $$new($MethodTypeArray, 0))));
				tryBSink($(invokeAltMetafactory(mh, $MetafactoryParameterCastTest$BSink::class$, "take"_s, noCapture, takeC, takeB, $$new($MethodTypeArray, 0))));
				tryASink($(invokeAltMetafactory(mh, $MetafactoryParameterCastTest$ASink::class$, "take"_s, noCapture, takeC, takeC, $$new($MethodTypeArray, {takeA}))));
				tryBSink($(invokeAltMetafactory(mh, $MetafactoryParameterCastTest$BSink::class$, "take"_s, noCapture, takeC, takeC, $$new($MethodTypeArray, {takeB}))));
			}
		}
	}
	{
		$var($MethodHandleArray, arr$, twoBParams);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($MethodHandle, mh, arr$->get(i$));
			{
				$load($MetafactoryParameterCastTest$ASink);
				tryCapASink($(invokeMetafactory(mh, $MetafactoryParameterCastTest$ASink::class$, "take"_s, captureB, takeC, takeA)));
				$load($MetafactoryParameterCastTest$BSink);
				tryCapBSink($(invokeMetafactory(mh, $MetafactoryParameterCastTest$BSink::class$, "take"_s, captureB, takeC, takeB)));
				tryCapASink($(invokeAltMetafactory(mh, $MetafactoryParameterCastTest$ASink::class$, "take"_s, captureB, takeC, takeA, $$new($MethodTypeArray, 0))));
				tryCapBSink($(invokeAltMetafactory(mh, $MetafactoryParameterCastTest$BSink::class$, "take"_s, captureB, takeC, takeB, $$new($MethodTypeArray, 0))));
				tryCapASink($(invokeAltMetafactory(mh, $MetafactoryParameterCastTest$ASink::class$, "take"_s, captureB, takeC, takeC, $$new($MethodTypeArray, {takeA}))));
				tryCapBSink($(invokeAltMetafactory(mh, $MetafactoryParameterCastTest$BSink::class$, "take"_s, captureB, takeC, takeC, $$new($MethodTypeArray, {takeB}))));
			}
		}
	}
}

void MetafactoryParameterCastTest::tryASink($CallSite* cs) {
	$useLocalCurrentObjectStackCache();
	$var($MetafactoryParameterCastTest$ASink, sink, $cast($MetafactoryParameterCastTest$ASink, $nc($($nc(cs)->dynamicInvoker()))->invoke($$new($ObjectArray, 0))));
	tryASink(sink);
}

void MetafactoryParameterCastTest::tryCapASink($CallSite* cs) {
	$useLocalCurrentObjectStackCache();
	$var($MetafactoryParameterCastTest$ASink, sink, $cast($MetafactoryParameterCastTest$ASink, $nc($($nc(cs)->dynamicInvoker()))->invoke($$new($ObjectArray, {$of($$new($MetafactoryParameterCastTest$B))}))));
	tryASink(sink);
}

void MetafactoryParameterCastTest::tryBSink($CallSite* cs) {
	$useLocalCurrentObjectStackCache();
	$var($MetafactoryParameterCastTest$BSink, sink, $cast($MetafactoryParameterCastTest$BSink, $nc($($nc(cs)->dynamicInvoker()))->invoke($$new($ObjectArray, 0))));
	tryBSink(sink);
}

void MetafactoryParameterCastTest::tryCapBSink($CallSite* cs) {
	$useLocalCurrentObjectStackCache();
	$var($MetafactoryParameterCastTest$BSink, sink, $cast($MetafactoryParameterCastTest$BSink, $nc($($nc(cs)->dynamicInvoker()))->invoke($$new($ObjectArray, {$of($$new($MetafactoryParameterCastTest$B))}))));
	tryBSink(sink);
}

void MetafactoryParameterCastTest::tryASink($MetafactoryParameterCastTest$ASink* sink) {
	$useLocalCurrentObjectStackCache();
	try {
		$nc(sink)->take($$new($MetafactoryParameterCastTest$C));
	} catch ($ClassCastException& e) {
		$var($String, var$0, $$str({"Unexpected cast failure: "_s, e, " "_s}));
		$throwNew($AssertionError, $of(($$concat(var$0, $(lastMFParams())))));
	}
	try {
		$nc(sink)->take($$new($MetafactoryParameterCastTest$B));
		$throwNew($AssertionError, $of($$str({"Missing cast from A to C: "_s, $(lastMFParams())})));
	} catch ($ClassCastException& e) {
	}
	try {
		$nc(sink)->take($$new($MetafactoryParameterCastTest$NotC));
		$throwNew($AssertionError, $of($$str({"Missing cast from A to C: "_s, $(lastMFParams())})));
	} catch ($ClassCastException& e) {
	}
}

void MetafactoryParameterCastTest::tryBSink($MetafactoryParameterCastTest$BSink* sink) {
	$useLocalCurrentObjectStackCache();
	try {
		$nc(sink)->take($$new($MetafactoryParameterCastTest$C));
	} catch ($ClassCastException& e) {
		$var($String, var$0, $$str({"Unexpected cast failure: "_s, e, " "_s}));
		$throwNew($AssertionError, $of(($$concat(var$0, $(lastMFParams())))));
	}
	try {
		$nc(sink)->take($$new($MetafactoryParameterCastTest$B));
		$throwNew($AssertionError, $of($$str({"Missing cast from B to C: "_s, $(lastMFParams())})));
	} catch ($ClassCastException& e) {
	}
	try {
		$nc(sink)->take($$new($MetafactoryParameterCastTest$NotC));
		$throwNew($AssertionError, $of($$str({"Missing cast from B to C: "_s, $(lastMFParams())})));
	} catch ($ClassCastException& e) {
	}
}

$String* MetafactoryParameterCastTest::lastMFParams() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$6, $$str({"mh="_s, this->lastMH, ", captured="_s}));
	$var($String, var$5, $$concat(var$6, $($Arrays::toString(this->lastCaptured))));
	$var($String, var$4, $$concat(var$5, ", instMT="_s));
	$var($String, var$3, $$concat(var$4, this->lastInstMT));
	$var($String, var$2, $$concat(var$3, ", samMT="_s));
	$var($String, var$1, $$concat(var$2, this->lastSamMT));
	$var($String, var$0, $$concat(var$1, ", bridgeMTs="_s));
	return $concat(var$0, $($Arrays::toString(this->lastBridgeMTs)));
}

$CallSite* MetafactoryParameterCastTest::invokeMetafactory($MethodHandle* mh, $Class* sam, $String* methodName, $ClassArray* captured, $MethodType* instMT, $MethodType* samMT) {
	$set(this, lastMH, mh);
	$set(this, lastCaptured, captured);
	$set(this, lastInstMT, instMT);
	$set(this, lastSamMT, samMT);
	$set(this, lastBridgeMTs, $new($MethodTypeArray, 0));
	try {
		return $LambdaMetafactory::metafactory(MetafactoryParameterCastTest::lookup, methodName, $($MethodType::methodType(sam, captured)), samMT, mh, instMT);
	} catch ($LambdaConversionException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$CallSite* MetafactoryParameterCastTest::invokeAltMetafactory($MethodHandle* mh, $Class* sam, $String* methodName, $ClassArray* captured, $MethodType* instMT, $MethodType* samMT, $MethodTypeArray* bridgeMTs) {
	$useLocalCurrentObjectStackCache();
	$set(this, lastMH, mh);
	$set(this, lastCaptured, captured);
	$set(this, lastInstMT, instMT);
	$set(this, lastSamMT, samMT);
	$set(this, lastBridgeMTs, bridgeMTs);
	try {
		bool bridge = $nc(bridgeMTs)->length > 0;
		$var($ObjectArray, args, $new($ObjectArray, bridge ? 5 + bridgeMTs->length : 4));
		args->set(0, samMT);
		args->set(1, mh);
		args->set(2, instMT);
		args->set(3, $($Integer::valueOf(bridge ? $LambdaMetafactory::FLAG_BRIDGES : 0)));
		if (bridge) {
			args->set(4, $($Integer::valueOf(bridgeMTs->length)));
			for (int32_t i = 0; i < bridgeMTs->length; ++i) {
				args->set(5 + i, bridgeMTs->get(i));
			}
		}
		return $LambdaMetafactory::altMetafactory(MetafactoryParameterCastTest::lookup, methodName, $($MethodType::methodType(sam, captured)), args);
	} catch ($LambdaConversionException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

void clinit$MetafactoryParameterCastTest($Class* class$) {
	$beforeCallerSensitive();
	$assignStatic(MetafactoryParameterCastTest::lookup, $MethodHandles::lookup());
}

MetafactoryParameterCastTest::MetafactoryParameterCastTest() {
}

$Class* MetafactoryParameterCastTest::load$($String* name, bool initialize) {
	$loadClass(MetafactoryParameterCastTest, name, initialize, &_MetafactoryParameterCastTest_ClassInfo_, clinit$MetafactoryParameterCastTest, allocate$MetafactoryParameterCastTest);
	return class$;
}

$Class* MetafactoryParameterCastTest::class$ = nullptr;