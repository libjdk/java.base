#include <HiddenFrames.h>

#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/StackWalker$Option.h>
#include <java/lang/StackWalker$StackFrame.h>
#include <java/lang/StackWalker.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Method.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/stream/Stream.h>
#include <jcpp.h>

#undef SHOW_HIDDEN_FRAMES
#undef SHOW_REFLECT_FRAMES

using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $StackWalker = ::java::lang::StackWalker;
using $StackWalker$Option = ::java::lang::StackWalker$Option;
using $StackWalker$StackFrame = ::java::lang::StackWalker$StackFrame;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Method = ::java::lang::reflect::Method;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Stream = ::java::util::stream::Stream;

class HiddenFrames$$Lambda$lambda$walk$1 : public $Consumer {
	$class(HiddenFrames$$Lambda$lambda$walk$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$(HiddenFrames* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* i) override {
		$nc(inst$)->lambda$walk$1($cast($Integer, i));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HiddenFrames$$Lambda$lambda$walk$1>());
	}
	HiddenFrames* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HiddenFrames$$Lambda$lambda$walk$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(HiddenFrames$$Lambda$lambda$walk$1, inst$)},
	{}
};
$MethodInfo HiddenFrames$$Lambda$lambda$walk$1::methodInfos[3] = {
	{"<init>", "(LHiddenFrames;)V", nullptr, $PUBLIC, $method(HiddenFrames$$Lambda$lambda$walk$1, init$, void, HiddenFrames*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(HiddenFrames$$Lambda$lambda$walk$1, accept, void, Object$*)},
	{}
};
$ClassInfo HiddenFrames$$Lambda$lambda$walk$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"HiddenFrames$$Lambda$lambda$walk$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* HiddenFrames$$Lambda$lambda$walk$1::load$($String* name, bool initialize) {
	$loadClass(HiddenFrames$$Lambda$lambda$walk$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HiddenFrames$$Lambda$lambda$walk$1::class$ = nullptr;

class HiddenFrames$$Lambda$lambda$walk$0$1 : public $Function {
	$class(HiddenFrames$$Lambda$lambda$walk$0$1, $NO_CLASS_INIT, $Function)
public:
	void init$(HiddenFrames* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* s) override {
		 return $nc(inst$)->lambda$walk$0($cast($Stream, s));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HiddenFrames$$Lambda$lambda$walk$0$1>());
	}
	HiddenFrames* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HiddenFrames$$Lambda$lambda$walk$0$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(HiddenFrames$$Lambda$lambda$walk$0$1, inst$)},
	{}
};
$MethodInfo HiddenFrames$$Lambda$lambda$walk$0$1::methodInfos[3] = {
	{"<init>", "(LHiddenFrames;)V", nullptr, $PUBLIC, $method(HiddenFrames$$Lambda$lambda$walk$0$1, init$, void, HiddenFrames*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(HiddenFrames$$Lambda$lambda$walk$0$1, apply, $Object*, Object$*)},
	{}
};
$ClassInfo HiddenFrames$$Lambda$lambda$walk$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"HiddenFrames$$Lambda$lambda$walk$0$1",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* HiddenFrames$$Lambda$lambda$walk$0$1::load$($String* name, bool initialize) {
	$loadClass(HiddenFrames$$Lambda$lambda$walk$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HiddenFrames$$Lambda$lambda$walk$0$1::class$ = nullptr;

class HiddenFrames$$Lambda$checkFrame$2 : public $Consumer {
	$class(HiddenFrames$$Lambda$checkFrame$2, $NO_CLASS_INIT, $Consumer)
public:
	void init$(HiddenFrames* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* frame) override {
		$nc(inst$)->checkFrame($cast($StackWalker$StackFrame, frame));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HiddenFrames$$Lambda$checkFrame$2>());
	}
	HiddenFrames* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HiddenFrames$$Lambda$checkFrame$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(HiddenFrames$$Lambda$checkFrame$2, inst$)},
	{}
};
$MethodInfo HiddenFrames$$Lambda$checkFrame$2::methodInfos[3] = {
	{"<init>", "(LHiddenFrames;)V", nullptr, $PUBLIC, $method(HiddenFrames$$Lambda$checkFrame$2, init$, void, HiddenFrames*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(HiddenFrames$$Lambda$checkFrame$2, accept, void, Object$*)},
	{}
};
$ClassInfo HiddenFrames$$Lambda$checkFrame$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"HiddenFrames$$Lambda$checkFrame$2",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* HiddenFrames$$Lambda$checkFrame$2::load$($String* name, bool initialize) {
	$loadClass(HiddenFrames$$Lambda$checkFrame$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HiddenFrames$$Lambda$checkFrame$2::class$ = nullptr;

$FieldInfo _HiddenFrames_FieldInfo_[] = {
	{"option", "Ljava/lang/StackWalker$Option;", nullptr, $PRIVATE | $FINAL, $field(HiddenFrames, option)},
	{"walker", "Ljava/lang/StackWalker;", nullptr, $PRIVATE | $FINAL, $field(HiddenFrames, walker)},
	{"lambdas", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/StackWalker$StackFrame;>;", $PRIVATE | $FINAL, $field(HiddenFrames, lambdas)},
	{"reflects", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/StackWalker$StackFrame;>;", $PRIVATE | $FINAL, $field(HiddenFrames, reflects)},
	{}
};

$MethodInfo _HiddenFrames_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(HiddenFrames, init$, void)},
	{"<init>", "(Ljava/lang/StackWalker$Option;)V", nullptr, 0, $method(HiddenFrames, init$, void, $StackWalker$Option*)},
	{"checkFrame", "(Ljava/lang/StackWalker$StackFrame;)V", nullptr, 0, $virtualMethod(HiddenFrames, checkFrame, void, $StackWalker$StackFrame*)},
	{"lambda$walk$0", "(Ljava/util/stream/Stream;)Ljava/lang/Object;", nullptr, $PRIVATE | $SYNTHETIC, $method(HiddenFrames, lambda$walk$0, $Object*, $Stream*)},
	{"lambda$walk$1", "(Ljava/lang/Integer;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(HiddenFrames, lambda$walk$1, void, $Integer*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(HiddenFrames, main, void, $StringArray*), "java.lang.Exception"},
	{"test", "()V", nullptr, 0, $virtualMethod(HiddenFrames, test, void), "java.lang.Exception"},
	{"walk", "()V", nullptr, 0, $virtualMethod(HiddenFrames, walk, void)},
	{"walkFromReflection", "()V", nullptr, 0, $virtualMethod(HiddenFrames, walkFromReflection, void), "java.lang.Exception"},
	{}
};

$ClassInfo _HiddenFrames_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"HiddenFrames",
	"java.lang.Object",
	nullptr,
	_HiddenFrames_FieldInfo_,
	_HiddenFrames_MethodInfo_
};

$Object* allocate$HiddenFrames($Class* clazz) {
	return $of($alloc(HiddenFrames));
}

void HiddenFrames::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$$new(HiddenFrames)->test();
	$init($StackWalker$Option);
	$$new(HiddenFrames, $StackWalker$Option::SHOW_REFLECT_FRAMES)->test();
	$$new(HiddenFrames, $StackWalker$Option::SHOW_HIDDEN_FRAMES)->test();
}

void HiddenFrames::init$() {
	$set(this, lambdas, $new($ArrayList));
	$set(this, reflects, $new($ArrayList));
	$set(this, option, nullptr);
	$set(this, walker, $StackWalker::getInstance());
}

void HiddenFrames::init$($StackWalker$Option* option) {
	$set(this, lambdas, $new($ArrayList));
	$set(this, reflects, $new($ArrayList));
	$set(this, option, option);
	$set(this, walker, $StackWalker::getInstance(option));
}

void HiddenFrames::test() {
	walk();
	walkFromReflection();
}

void HiddenFrames::walk() {
	$useLocalCurrentObjectStackCache();
	$nc($($Stream::of($($of($Integer::valueOf(0))))))->forEach(static_cast<$Consumer*>($$new(HiddenFrames$$Lambda$lambda$walk$1, this)));
	if (this->option == nullptr && !$nc(this->lambdas)->isEmpty()) {
		$throwNew($RuntimeException, "Hidden frames are shown"_s);
	}
	$init($StackWalker$Option);
	if (this->option == $StackWalker$Option::SHOW_HIDDEN_FRAMES && $nc(this->lambdas)->isEmpty()) {
		$throwNew($RuntimeException, "No hidden Lambda frame"_s);
	}
}

void HiddenFrames::walkFromReflection() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Method, m, HiddenFrames::class$->getDeclaredMethod("walk"_s, $$new($ClassArray, 0)));
	$nc(m)->invoke(this, $$new($ObjectArray, 0));
	if (this->option == nullptr && !$nc(this->lambdas)->isEmpty()) {
		$throwNew($RuntimeException, "Hidden frames are shown"_s);
	}
	$init($StackWalker$Option);
	if (this->option == $StackWalker$Option::SHOW_HIDDEN_FRAMES && $nc(this->lambdas)->isEmpty()) {
		$throwNew($RuntimeException, "No hidden Lambda frame"_s);
	}
	if (this->option != nullptr && $nc(this->reflects)->isEmpty()) {
		$throwNew($RuntimeException, "No reflection frame"_s);
	}
}

void HiddenFrames::checkFrame($StackWalker$StackFrame* frame) {
	$useLocalCurrentObjectStackCache();
	$var($String, cn, $nc(frame)->getClassName());
	bool var$0 = $nc(cn)->startsWith("java.lang.reflect."_s);
	if (var$0 || $nc(cn)->startsWith("jdk.internal.reflect."_s)) {
		$nc(this->reflects)->add(frame);
	}
	$var($String, mn, frame->getMethodName());
	bool var$1 = $nc(cn)->contains("$$Lambda$"_s);
	if (var$1 || $nc(mn)->contains("lambda$"_s)) {
		$nc(this->lambdas)->add(frame);
	}
}

void HiddenFrames::lambda$walk$1($Integer* i) {
	$beforeCallerSensitive();
	$nc(this->walker)->walk(static_cast<$Function*>($$new(HiddenFrames$$Lambda$lambda$walk$0$1, this)));
}

$Object* HiddenFrames::lambda$walk$0($Stream* s) {
	$nc(s)->forEach(static_cast<$Consumer*>($$new(HiddenFrames$$Lambda$checkFrame$2, this)));
	return $of(nullptr);
}

HiddenFrames::HiddenFrames() {
}

$Class* HiddenFrames::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HiddenFrames$$Lambda$lambda$walk$1::classInfo$.name)) {
			return HiddenFrames$$Lambda$lambda$walk$1::load$(name, initialize);
		}
		if (name->equals(HiddenFrames$$Lambda$lambda$walk$0$1::classInfo$.name)) {
			return HiddenFrames$$Lambda$lambda$walk$0$1::load$(name, initialize);
		}
		if (name->equals(HiddenFrames$$Lambda$checkFrame$2::classInfo$.name)) {
			return HiddenFrames$$Lambda$checkFrame$2::load$(name, initialize);
		}
	}
	$loadClass(HiddenFrames, name, initialize, &_HiddenFrames_ClassInfo_, allocate$HiddenFrames);
	return class$;
}

$Class* HiddenFrames::class$ = nullptr;