#include <LambdaReturn.h>

#include <LambdaReturn$I.h>
#include <java/lang/AssertionError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaConversionException.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jcpp.h>

#undef FLAG_BRIDGES
#undef I
#undef O
#undef S
#undef TYPE
#undef V

using $LambdaReturn$I = ::LambdaReturn$I;
using $PrintStream = ::java::io::PrintStream;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $LambdaConversionException = ::java::lang::invoke::LambdaConversionException;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;

$FieldInfo _LambdaReturn_FieldInfo_[] = {
	{"l", "Ljava/lang/invoke/MethodHandles$Lookup;", nullptr, $STATIC, $staticField(LambdaReturn, l)},
	{}
};

$MethodInfo _LambdaReturn_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LambdaReturn, init$, void)},
	{"amf", "(Ljava/util/List;Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodType;Ljava/lang/invoke/MethodType;Ljava/lang/invoke/MethodType;Z)V", "(Ljava/util/List<Ljava/lang/String;>;Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodType;Ljava/lang/invoke/MethodType;Ljava/lang/invoke/MethodType;Z)V", $PRIVATE | $STATIC, $staticMethod(LambdaReturn, amf, void, $List*, $MethodHandle*, $MethodType*, $MethodType*, $MethodType*, bool)},
	{"hereS", "()Ljava/lang/String;", nullptr, $STATIC, $staticMethod(LambdaReturn, hereS, $String*)},
	{"hereV", "()V", nullptr, $STATIC, $staticMethod(LambdaReturn, hereV, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(LambdaReturn, main, void, $StringArray*), "java.lang.Throwable"},
	{"mt", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodType;", "(Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodType;", $PRIVATE | $STATIC, $staticMethod(LambdaReturn, mt, $MethodType*, $Class*)},
	{"mt", "(Ljava/lang/Class;Ljava/lang/Class;)Ljava/lang/invoke/MethodType;", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodType;", $PRIVATE | $STATIC, $staticMethod(LambdaReturn, mt, $MethodType*, $Class*, $Class*)},
	{}
};

$InnerClassInfo _LambdaReturn_InnerClassesInfo_[] = {
	{"LambdaReturn$I", "LambdaReturn", "I", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _LambdaReturn_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"LambdaReturn",
	"java.lang.Object",
	nullptr,
	_LambdaReturn_FieldInfo_,
	_LambdaReturn_MethodInfo_,
	nullptr,
	nullptr,
	_LambdaReturn_InnerClassesInfo_,
	nullptr,
	nullptr,
	"LambdaReturn$I"
};

$Object* allocate$LambdaReturn($Class* clazz) {
	return $of($alloc(LambdaReturn));
}

$MethodHandles$Lookup* LambdaReturn::l = nullptr;

void LambdaReturn::init$() {
}

void LambdaReturn::hereV() {
}

$String* LambdaReturn::hereS() {
	return "hi"_s;
}

$MethodType* LambdaReturn::mt($Class* k) {
	return $MethodType::methodType(k);
}

$MethodType* LambdaReturn::mt($Class* k, $Class* k2) {
	return $MethodType::methodType(k, k2);
}

void LambdaReturn::amf($List* errs, $MethodHandle* h, $MethodType* mts, $MethodType* mtf, $MethodType* mtb, bool shouldWork) {
	$useLocalCurrentObjectStackCache();
	$load($LambdaReturn$I);
	$var($MethodType, mti, mt($LambdaReturn$I::class$));
	try {
		$init(LambdaReturn);
		$LambdaMetafactory::altMetafactory(LambdaReturn::l, "m"_s, mti, $$new($ObjectArray, {
			$of(mts),
			$of(h),
			$of(mtf),
			$($of($Integer::valueOf($LambdaMetafactory::FLAG_BRIDGES))),
			$($of($Integer::valueOf(1))),
			$of(mtb)
		}));
	} catch ($LambdaConversionException& e) {
		if (shouldWork) {
			$nc(errs)->add($$str({"Error: Should work h="_s, h, " s="_s, mts, " -- f="_s, mtf, " / b="_s, mtb, " got: "_s, e}));
		}
		return;
	}
	if (!shouldWork) {
		$nc(errs)->add($$str({"Error: Should fail h="_s, h, " s="_s, mts, " -- f="_s, mtf, " / b="_s, mtb}));
	}
}

void LambdaReturn::main($StringArray* args) {
	$load(LambdaReturn);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$init(LambdaReturn);
	$assignStatic(LambdaReturn::l, $MethodHandles::lookup());
	$init($Void);
	$var($MethodHandle, hV, $nc(LambdaReturn::l)->findStatic(LambdaReturn::class$, "hereV"_s, $(mt($Void::TYPE))));
	$var($MethodHandle, hS, $nc(LambdaReturn::l)->findStatic(LambdaReturn::class$, "hereS"_s, $(mt($String::class$))));
	$var($List, errs, $new($ArrayList));
	$var($MethodType, V, mt($Void::TYPE));
	$var($MethodType, S, mt($String::class$));
	$var($MethodType, O, mt($Object::class$));
	$init($Integer);
	$var($MethodType, I, mt($Integer::TYPE));
	amf(errs, hS, S, S, O, true);
	amf(errs, hS, S, S, V, false);
	amf(errs, hS, S, S, I, false);
	amf(errs, hS, O, S, S, true);
	amf(errs, hS, V, S, S, false);
	amf(errs, hS, I, S, S, false);
	amf(errs, hS, O, O, S, false);
	amf(errs, hS, S, O, O, false);
	amf(errs, hV, V, V, O, false);
	amf(errs, hV, V, V, I, false);
	amf(errs, hV, V, V, S, false);
	amf(errs, hV, O, V, V, false);
	amf(errs, hV, I, V, V, false);
	amf(errs, hV, S, V, V, false);
	if (errs->size() > 0) {
		{
			$var($Iterator, i$, errs->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, err, $cast($String, i$->next()));
				{
					$nc($System::err)->println(err);
				}
			}
		}
		$throwNew($AssertionError, $of($$str({"Errors: "_s, $$str(errs->size())})));
	}
}

LambdaReturn::LambdaReturn() {
}

$Class* LambdaReturn::load$($String* name, bool initialize) {
	$loadClass(LambdaReturn, name, initialize, &_LambdaReturn_ClassInfo_, allocate$LambdaReturn);
	return class$;
}

$Class* LambdaReturn::class$ = nullptr;