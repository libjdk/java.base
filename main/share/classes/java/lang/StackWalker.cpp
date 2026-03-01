#include <java/lang/StackWalker.h>

#include <java/io/Serializable.h>
#include <java/lang/Enum.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/StackStreamFactory$CallerClassFinder.h>
#include <java/lang/StackStreamFactory$StackFrameTraverser.h>
#include <java/lang/StackStreamFactory.h>
#include <java/lang/StackWalker$ExtendedOption.h>
#include <java/lang/StackWalker$Option.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/Permission.h>
#include <java/util/Collection.h>
#include <java/util/EnumSet.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/stream/Stream.h>
#include <jcpp.h>

#undef DEFAULT_EMPTY_OPTION
#undef DEFAULT_WALKER
#undef LOCALS_AND_OPERANDS
#undef RETAIN_CLASS_REFERENCE

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $StackStreamFactory = ::java::lang::StackStreamFactory;
using $StackStreamFactory$CallerClassFinder = ::java::lang::StackStreamFactory$CallerClassFinder;
using $StackStreamFactory$StackFrameTraverser = ::java::lang::StackStreamFactory$StackFrameTraverser;
using $StackWalker$ExtendedOption = ::java::lang::StackWalker$ExtendedOption;
using $StackWalker$Option = ::java::lang::StackWalker$Option;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Permission = ::java::security::Permission;
using $Collection = ::java::util::Collection;
using $EnumSet = ::java::util::EnumSet;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Stream = ::java::util::stream::Stream;

namespace java {
	namespace lang {

class StackWalker$$Lambda$lambda$forEach$0 : public $Function {
	$class(StackWalker$$Lambda$lambda$forEach$0, $NO_CLASS_INIT, $Function)
public:
	void init$($Consumer* action) {
		$set(this, action, action);
	}
	virtual $Object* apply(Object$* s) override {
		 return StackWalker::lambda$forEach$0(action, $cast($Stream, s));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<StackWalker$$Lambda$lambda$forEach$0>());
	}
	$Consumer* action = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo StackWalker$$Lambda$lambda$forEach$0::fieldInfos[2] = {
	{"action", "Ljava/util/function/Consumer;", nullptr, $PUBLIC, $field(StackWalker$$Lambda$lambda$forEach$0, action)},
	{}
};
$MethodInfo StackWalker$$Lambda$lambda$forEach$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/Consumer;)V", nullptr, $PUBLIC, $method(StackWalker$$Lambda$lambda$forEach$0, init$, void, $Consumer*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(StackWalker$$Lambda$lambda$forEach$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo StackWalker$$Lambda$lambda$forEach$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.StackWalker$$Lambda$lambda$forEach$0",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* StackWalker$$Lambda$lambda$forEach$0::load$($String* name, bool initialize) {
	$loadClass(StackWalker$$Lambda$lambda$forEach$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* StackWalker$$Lambda$lambda$forEach$0::class$ = nullptr;

$CompoundAttribute _StackWalker_MethodAnnotations_forEach5[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _StackWalker_MethodAnnotations_getCallerClass6[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _StackWalker_MethodAnnotations_walk16[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$FieldInfo _StackWalker_FieldInfo_[] = {
	{"DEFAULT_EMPTY_OPTION", "Ljava/util/EnumSet;", "Ljava/util/EnumSet<Ljava/lang/StackWalker$Option;>;", $STATIC | $FINAL, $staticField(StackWalker, DEFAULT_EMPTY_OPTION)},
	{"DEFAULT_WALKER", "Ljava/lang/StackWalker;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(StackWalker, DEFAULT_WALKER)},
	{"options", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/StackWalker$Option;>;", $PRIVATE | $FINAL, $field(StackWalker, options)},
	{"extendedOption", "Ljava/lang/StackWalker$ExtendedOption;", nullptr, $PRIVATE | $FINAL, $field(StackWalker, extendedOption)},
	{"estimateDepth", "I", nullptr, $PRIVATE | $FINAL, $field(StackWalker, estimateDepth$)},
	{"retainClassRef", "Z", nullptr, $FINAL, $field(StackWalker, retainClassRef)},
	{}
};

$MethodInfo _StackWalker_MethodInfo_[] = {
	{"<init>", "(Ljava/util/EnumSet;)V", "(Ljava/util/EnumSet<Ljava/lang/StackWalker$Option;>;)V", $PRIVATE, $method(StackWalker, init$, void, $EnumSet*)},
	{"<init>", "(Ljava/util/EnumSet;I)V", "(Ljava/util/EnumSet<Ljava/lang/StackWalker$Option;>;I)V", $PRIVATE, $method(StackWalker, init$, void, $EnumSet*, int32_t)},
	{"<init>", "(Ljava/util/EnumSet;ILjava/lang/StackWalker$ExtendedOption;)V", "(Ljava/util/EnumSet<Ljava/lang/StackWalker$Option;>;ILjava/lang/StackWalker$ExtendedOption;)V", $PRIVATE, $method(StackWalker, init$, void, $EnumSet*, int32_t, $StackWalker$ExtendedOption*)},
	{"checkPermission", "(Ljava/util/Set;)V", "(Ljava/util/Set<Ljava/lang/StackWalker$Option;>;)V", $PRIVATE | $STATIC, $staticMethod(StackWalker, checkPermission, void, $Set*)},
	{"estimateDepth", "()I", nullptr, 0, $method(StackWalker, estimateDepth, int32_t)},
	{"forEach", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<-Ljava/lang/StackWalker$StackFrame;>;)V", $PUBLIC, $method(StackWalker, forEach, void, $Consumer*), nullptr, nullptr, _StackWalker_MethodAnnotations_forEach5},
	{"getCallerClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PUBLIC, $method(StackWalker, getCallerClass, $Class*), nullptr, nullptr, _StackWalker_MethodAnnotations_getCallerClass6},
	{"getInstance", "()Ljava/lang/StackWalker;", nullptr, $PUBLIC | $STATIC, $staticMethod(StackWalker, getInstance, StackWalker*)},
	{"getInstance", "(Ljava/lang/StackWalker$Option;)Ljava/lang/StackWalker;", nullptr, $PUBLIC | $STATIC, $staticMethod(StackWalker, getInstance, StackWalker*, $StackWalker$Option*)},
	{"getInstance", "(Ljava/util/Set;)Ljava/lang/StackWalker;", "(Ljava/util/Set<Ljava/lang/StackWalker$Option;>;)Ljava/lang/StackWalker;", $PUBLIC | $STATIC, $staticMethod(StackWalker, getInstance, StackWalker*, $Set*)},
	{"getInstance", "(Ljava/util/Set;I)Ljava/lang/StackWalker;", "(Ljava/util/Set<Ljava/lang/StackWalker$Option;>;I)Ljava/lang/StackWalker;", $PUBLIC | $STATIC, $staticMethod(StackWalker, getInstance, StackWalker*, $Set*, int32_t)},
	{"hasLocalsOperandsOption", "()Z", nullptr, 0, $method(StackWalker, hasLocalsOperandsOption, bool)},
	{"hasOption", "(Ljava/lang/StackWalker$Option;)Z", nullptr, 0, $method(StackWalker, hasOption, bool, $StackWalker$Option*)},
	{"lambda$forEach$0", "(Ljava/util/function/Consumer;Ljava/util/stream/Stream;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(StackWalker, lambda$forEach$0, $Object*, $Consumer*, $Stream*)},
	{"newInstance", "(Ljava/util/Set;Ljava/lang/StackWalker$ExtendedOption;)Ljava/lang/StackWalker;", "(Ljava/util/Set<Ljava/lang/StackWalker$Option;>;Ljava/lang/StackWalker$ExtendedOption;)Ljava/lang/StackWalker;", $STATIC, $staticMethod(StackWalker, newInstance, StackWalker*, $Set*, $StackWalker$ExtendedOption*)},
	{"toEnumSet", "(Ljava/util/Set;)Ljava/util/EnumSet;", "(Ljava/util/Set<Ljava/lang/StackWalker$Option;>;)Ljava/util/EnumSet<Ljava/lang/StackWalker$Option;>;", $PRIVATE | $STATIC, $staticMethod(StackWalker, toEnumSet, $EnumSet*, $Set*)},
	{"walk", "(Ljava/util/function/Function;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/util/function/Function<-Ljava/util/stream/Stream<Ljava/lang/StackWalker$StackFrame;>;+TT;>;)TT;", $PUBLIC, $method(StackWalker, walk, $Object*, $Function*), nullptr, nullptr, _StackWalker_MethodAnnotations_walk16},
	{}
};

$InnerClassInfo _StackWalker_InnerClassesInfo_[] = {
	{"java.lang.StackWalker$ExtendedOption", "java.lang.StackWalker", "ExtendedOption", $STATIC | $FINAL | $ENUM},
	{"java.lang.StackWalker$Option", "java.lang.StackWalker", "Option", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{"java.lang.StackWalker$StackFrame", "java.lang.StackWalker", "StackFrame", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _StackWalker_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.lang.StackWalker",
	"java.lang.Object",
	nullptr,
	_StackWalker_FieldInfo_,
	_StackWalker_MethodInfo_,
	nullptr,
	nullptr,
	_StackWalker_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.StackWalker$ExtendedOption,java.lang.StackWalker$Option,java.lang.StackWalker$StackFrame"
};

$Object* allocate$StackWalker($Class* clazz) {
	return $of($alloc(StackWalker));
}

$EnumSet* StackWalker::DEFAULT_EMPTY_OPTION = nullptr;
StackWalker* StackWalker::DEFAULT_WALKER = nullptr;

StackWalker* StackWalker::getInstance() {
	$init(StackWalker);
	return StackWalker::DEFAULT_WALKER;
}

StackWalker* StackWalker::getInstance($StackWalker$Option* option) {
	$init(StackWalker);
	return getInstance($(static_cast<$Set*>($EnumSet::of($cast($StackWalker$Option, $Objects::requireNonNull(option))))));
}

StackWalker* StackWalker::getInstance($Set* options) {
	$init(StackWalker);
	if ($nc(options)->isEmpty()) {
		return StackWalker::DEFAULT_WALKER;
	}
	$var($EnumSet, optionSet, toEnumSet(options));
	checkPermission(optionSet);
	return $new(StackWalker, optionSet);
}

StackWalker* StackWalker::getInstance($Set* options, int32_t estimateDepth) {
	$init(StackWalker);
	if (estimateDepth <= 0) {
		$throwNew($IllegalArgumentException, "estimateDepth must be > 0"_s);
	}
	$var($EnumSet, optionSet, toEnumSet(options));
	checkPermission(optionSet);
	return $new(StackWalker, optionSet, estimateDepth);
}

void StackWalker::init$($EnumSet* options) {
	StackWalker::init$(options, 0, nullptr);
}

void StackWalker::init$($EnumSet* options, int32_t estimateDepth) {
	StackWalker::init$(options, estimateDepth, nullptr);
}

void StackWalker::init$($EnumSet* options, int32_t estimateDepth, $StackWalker$ExtendedOption* extendedOption) {
	$set(this, options, options);
	this->estimateDepth$ = estimateDepth;
	$set(this, extendedOption, extendedOption);
	$init($StackWalker$Option);
	this->retainClassRef = hasOption($StackWalker$Option::RETAIN_CLASS_REFERENCE);
}

void StackWalker::checkPermission($Set* options) {
	$init(StackWalker);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(options);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$init($StackWalker$Option);
		if (options->contains($StackWalker$Option::RETAIN_CLASS_REFERENCE)) {
			sm->checkPermission($$new($RuntimePermission, "getStackWalkerWithClassReference"_s));
		}
	}
}

$EnumSet* StackWalker::toEnumSet($Set* options) {
	$init(StackWalker);
	$Objects::requireNonNull(options);
	if (options->isEmpty()) {
		return StackWalker::DEFAULT_EMPTY_OPTION;
	} else {
		return $EnumSet::copyOf(static_cast<$Collection*>(options));
	}
}

$Object* StackWalker::walk($Function* function) {
	$Objects::requireNonNull(function);
	return $of($nc($($StackStreamFactory::makeStackTraverser(this, function)))->walk());
}

void StackWalker::forEach($Consumer* action) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(action);
	$nc($($StackStreamFactory::makeStackTraverser(this, static_cast<$Function*>($$new(StackWalker$$Lambda$lambda$forEach$0, action)))))->walk();
}

$Class* StackWalker::getCallerClass() {
	if (!this->retainClassRef) {
		$throwNew($UnsupportedOperationException, "This stack walker does not have RETAIN_CLASS_REFERENCE access"_s);
	}
	return $nc($($StackStreamFactory::makeCallerFinder(this)))->findCaller();
}

StackWalker* StackWalker::newInstance($Set* options, $StackWalker$ExtendedOption* extendedOption) {
	$init(StackWalker);
	$var($EnumSet, optionSet, toEnumSet(options));
	checkPermission(optionSet);
	return $new(StackWalker, optionSet, 0, extendedOption);
}

int32_t StackWalker::estimateDepth() {
	return this->estimateDepth$;
}

bool StackWalker::hasOption($StackWalker$Option* option) {
	return $nc(this->options)->contains(option);
}

bool StackWalker::hasLocalsOperandsOption() {
	$init($StackWalker$ExtendedOption);
	return this->extendedOption == $StackWalker$ExtendedOption::LOCALS_AND_OPERANDS;
}

$Object* StackWalker::lambda$forEach$0($Consumer* action, $Stream* s) {
	$init(StackWalker);
	$nc(s)->forEach(action);
	return $of(nullptr);
}

void clinit$StackWalker($Class* class$) {
	$load($StackWalker$Option);
	$assignStatic(StackWalker::DEFAULT_EMPTY_OPTION, $EnumSet::noneOf($StackWalker$Option::class$));
	$assignStatic(StackWalker::DEFAULT_WALKER, $new(StackWalker, StackWalker::DEFAULT_EMPTY_OPTION));
}

StackWalker::StackWalker() {
}

$Class* StackWalker::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(StackWalker$$Lambda$lambda$forEach$0::classInfo$.name)) {
			return StackWalker$$Lambda$lambda$forEach$0::load$(name, initialize);
		}
	}
	$loadClass(StackWalker, name, initialize, &_StackWalker_ClassInfo_, clinit$StackWalker, allocate$StackWalker);
	return class$;
}

$Class* StackWalker::class$ = nullptr;

	} // lang
} // java