#include <java/lang/StackStreamFactory.h>

#include <java/lang/InternalError.h>
#include <java/lang/StackStreamFactory$AbstractStackWalker.h>
#include <java/lang/StackStreamFactory$CallerClassFinder.h>
#include <java/lang/StackStreamFactory$LiveStackInfoTraverser.h>
#include <java/lang/StackStreamFactory$StackFrameTraverser.h>
#include <java/lang/StackWalker.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <java/util/function/Function.h>
#include <jdk/internal/reflect/ConstructorAccessor.h>
#include <jdk/internal/reflect/MethodAccessor.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef BATCH_SIZE
#undef DEFAULT_MODE
#undef FILL_CLASS_REFS_ONLY
#undef FILL_LIVE_STACK_FRAMES
#undef GET_CALLER_CLASS
#undef LARGE_BATCH_SIZE
#undef MIN_BATCH_SIZE
#undef SHOW_HIDDEN_FRAMES
#undef SMALL_BATCH

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $StackStreamFactory$AbstractStackWalker = ::java::lang::StackStreamFactory$AbstractStackWalker;
using $StackStreamFactory$CallerClassFinder = ::java::lang::StackStreamFactory$CallerClassFinder;
using $StackStreamFactory$LiveStackInfoTraverser = ::java::lang::StackStreamFactory$LiveStackInfoTraverser;
using $StackStreamFactory$StackFrameTraverser = ::java::lang::StackStreamFactory$StackFrameTraverser;
using $StackWalker = ::java::lang::StackWalker;
using $Constructor = ::java::lang::reflect::Constructor;
using $Method = ::java::lang::reflect::Method;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;
using $Function = ::java::util::function::Function;
using $ConstructorAccessor = ::jdk::internal::reflect::ConstructorAccessor;
using $MethodAccessor = ::jdk::internal::reflect::MethodAccessor;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace java {
	namespace lang {

$FieldInfo _StackStreamFactory_FieldInfo_[] = {
	{"stackWalkImplClasses", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/Class<*>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(StackStreamFactory, stackWalkImplClasses)},
	{"SMALL_BATCH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StackStreamFactory, SMALL_BATCH)},
	{"BATCH_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StackStreamFactory, BATCH_SIZE)},
	{"LARGE_BATCH_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StackStreamFactory, LARGE_BATCH_SIZE)},
	{"MIN_BATCH_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StackStreamFactory, MIN_BATCH_SIZE)},
	{"DEFAULT_MODE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StackStreamFactory, DEFAULT_MODE)},
	{"FILL_CLASS_REFS_ONLY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StackStreamFactory, FILL_CLASS_REFS_ONLY)},
	{"GET_CALLER_CLASS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StackStreamFactory, GET_CALLER_CLASS)},
	{"SHOW_HIDDEN_FRAMES", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StackStreamFactory, SHOW_HIDDEN_FRAMES)},
	{"FILL_LIVE_STACK_FRAMES", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StackStreamFactory, FILL_LIVE_STACK_FRAMES)},
	{"isDebug", "Z", nullptr, $STATIC | $FINAL, $staticField(StackStreamFactory, isDebug)},
	{}
};

$MethodInfo _StackStreamFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(StackStreamFactory, init$, void)},
	{"checkStackWalkModes", "()Z", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(StackStreamFactory, checkStackWalkModes, bool)},
	{"filterStackWalkImpl", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC, $staticMethod(StackStreamFactory, filterStackWalkImpl, bool, $Class*)},
	{"init", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/Class<*>;>;", $PRIVATE | $STATIC, $staticMethod(StackStreamFactory, init, $Set*)},
	{"isMethodHandleFrame", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC, $staticMethod(StackStreamFactory, isMethodHandleFrame, bool, $Class*)},
	{"isReflectionFrame", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC, $staticMethod(StackStreamFactory, isReflectionFrame, bool, $Class*)},
	{"makeCallerFinder", "(Ljava/lang/StackWalker;)Ljava/lang/StackStreamFactory$CallerClassFinder;", nullptr, $STATIC, $staticMethod(StackStreamFactory, makeCallerFinder, $StackStreamFactory$CallerClassFinder*, $StackWalker*)},
	{"makeStackTraverser", "(Ljava/lang/StackWalker;Ljava/util/function/Function;)Ljava/lang/StackStreamFactory$StackFrameTraverser;", "<T:Ljava/lang/Object;>(Ljava/lang/StackWalker;Ljava/util/function/Function<-Ljava/util/stream/Stream<Ljava/lang/StackWalker$StackFrame;>;+TT;>;)Ljava/lang/StackStreamFactory$StackFrameTraverser<TT;>;", $STATIC, $staticMethod(StackStreamFactory, makeStackTraverser, $StackStreamFactory$StackFrameTraverser*, $StackWalker*, $Function*)},
	{}
};

#define _METHOD_INDEX_checkStackWalkModes 1

$InnerClassInfo _StackStreamFactory_InnerClassesInfo_[] = {
	{"java.lang.StackStreamFactory$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"java.lang.StackStreamFactory$FrameBuffer", "java.lang.StackStreamFactory", "FrameBuffer", $STATIC | $ABSTRACT},
	{"java.lang.StackStreamFactory$LiveStackInfoTraverser", "java.lang.StackStreamFactory", "LiveStackInfoTraverser", $STATIC | $FINAL},
	{"java.lang.StackStreamFactory$CallerClassFinder", "java.lang.StackStreamFactory", "CallerClassFinder", $STATIC | $FINAL},
	{"java.lang.StackStreamFactory$StackFrameTraverser", "java.lang.StackStreamFactory", "StackFrameTraverser", $STATIC},
	{"java.lang.StackStreamFactory$AbstractStackWalker", "java.lang.StackStreamFactory", "AbstractStackWalker", $STATIC | $ABSTRACT},
	{"java.lang.StackStreamFactory$WalkerState", "java.lang.StackStreamFactory", "WalkerState", $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _StackStreamFactory_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.lang.StackStreamFactory",
	"java.lang.Object",
	nullptr,
	_StackStreamFactory_FieldInfo_,
	_StackStreamFactory_MethodInfo_,
	nullptr,
	nullptr,
	_StackStreamFactory_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.StackStreamFactory$1,java.lang.StackStreamFactory$FrameBuffer,java.lang.StackStreamFactory$LiveStackInfoTraverser,java.lang.StackStreamFactory$LiveStackInfoTraverser$LiveStackFrameBuffer,java.lang.StackStreamFactory$CallerClassFinder,java.lang.StackStreamFactory$CallerClassFinder$ClassBuffer,java.lang.StackStreamFactory$StackFrameTraverser,java.lang.StackStreamFactory$StackFrameTraverser$StackFrameBuffer,java.lang.StackStreamFactory$AbstractStackWalker,java.lang.StackStreamFactory$WalkerState"
};

$Object* allocate$StackStreamFactory($Class* clazz) {
	return $of($alloc(StackStreamFactory));
}

$Set* StackStreamFactory::stackWalkImplClasses = nullptr;
bool StackStreamFactory::isDebug = false;

void StackStreamFactory::init$() {
}

$StackStreamFactory$StackFrameTraverser* StackStreamFactory::makeStackTraverser($StackWalker* walker, $Function* function) {
	$init(StackStreamFactory);
	if ($nc(walker)->hasLocalsOperandsOption()) {
		return $new($StackStreamFactory$LiveStackInfoTraverser, walker, function);
	} else {
		return $new($StackStreamFactory$StackFrameTraverser, walker, function);
	}
}

$StackStreamFactory$CallerClassFinder* StackStreamFactory::makeCallerFinder($StackWalker* walker) {
	$init(StackStreamFactory);
	return $new($StackStreamFactory$CallerClassFinder, walker);
}

bool StackStreamFactory::checkStackWalkModes() {
	return true;
}

$Set* StackStreamFactory::init() {
	$init(StackStreamFactory);
	if (!checkStackWalkModes()) {
		$throwNew($InternalError, "StackWalker mode values do not match with JVM"_s);
	}
	$var($Set, classes, $new($HashSet));
	$load($StackWalker);
	classes->add($StackWalker::class$);
	classes->add(StackStreamFactory::class$);
	$load($StackStreamFactory$AbstractStackWalker);
	classes->add($StackStreamFactory$AbstractStackWalker::class$);
	return classes;
}

bool StackStreamFactory::filterStackWalkImpl($Class* c) {
	$init(StackStreamFactory);
	bool var$0 = $nc(StackStreamFactory::stackWalkImplClasses)->contains(c);
	return var$0 || $nc($($nc(c)->getName()))->startsWith("java.util.stream."_s);
}

bool StackStreamFactory::isMethodHandleFrame($Class* c) {
	$init(StackStreamFactory);
	return $nc($($nc(c)->getName()))->startsWith("java.lang.invoke."_s);
}

bool StackStreamFactory::isReflectionFrame($Class* c) {
	$init(StackStreamFactory);
	$load($Method);
	$load($Constructor);
	$load($MethodAccessor);
	bool var$1 = c == $Method::class$ || c == $Constructor::class$ || $MethodAccessor::class$->isAssignableFrom(c);
	$load($ConstructorAccessor);
	bool var$0 = var$1 || $ConstructorAccessor::class$->isAssignableFrom(c);
	return var$0 || $nc($($nc(c)->getName()))->startsWith("java.lang.invoke.LambdaForm"_s);
}

void clinit$StackStreamFactory($Class* class$) {
	$assignStatic(StackStreamFactory::stackWalkImplClasses, StackStreamFactory::init());
	StackStreamFactory::isDebug = "true"_s->equals($($GetPropertyAction::privilegedGetProperty("stackwalk.debug"_s)));
}

StackStreamFactory::StackStreamFactory() {
}

$Class* StackStreamFactory::load$($String* name, bool initialize) {
	$loadClass(StackStreamFactory, name, initialize, &_StackStreamFactory_ClassInfo_, clinit$StackStreamFactory, allocate$StackStreamFactory);
	return class$;
}

$Class* StackStreamFactory::class$ = nullptr;

	} // lang
} // java