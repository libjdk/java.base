#include <java/lang/runtime/SwitchBootstraps.h>

#include <java/io/Serializable.h>
#include <java/lang/Enum.h>
#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/Number.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/ConstantBootstraps.h>
#include <java/lang/invoke/ConstantCallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/TypeDescriptor$OfField.h>
#include <java/util/Objects.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/stream/Stream.h>
#include <jcpp.h>

#undef DO_ENUM_SWITCH
#undef DO_TYPE_SWITCH
#undef LOOKUP
#undef TYPE

using $Serializable = ::java::io::Serializable;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Enum = ::java::lang::Enum;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Number = ::java::lang::Number;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $CallSite = ::java::lang::invoke::CallSite;
using $ConstantBootstraps = ::java::lang::invoke::ConstantBootstraps;
using $ConstantCallSite = ::java::lang::invoke::ConstantCallSite;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Objects = ::java::util::Objects;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Stream = ::java::util::stream::Stream;

namespace java {
	namespace lang {
		namespace runtime {

class SwitchBootstraps$$Lambda$verifyLabel : public $Consumer {
	$class(SwitchBootstraps$$Lambda$verifyLabel, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* label) override {
		SwitchBootstraps::verifyLabel(label);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SwitchBootstraps$$Lambda$verifyLabel>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo SwitchBootstraps$$Lambda$verifyLabel::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SwitchBootstraps$$Lambda$verifyLabel, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(SwitchBootstraps$$Lambda$verifyLabel, accept, void, Object$*)},
	{}
};
$ClassInfo SwitchBootstraps$$Lambda$verifyLabel::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.runtime.SwitchBootstraps$$Lambda$verifyLabel",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* SwitchBootstraps$$Lambda$verifyLabel::load$($String* name, bool initialize) {
	$loadClass(SwitchBootstraps$$Lambda$verifyLabel, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SwitchBootstraps$$Lambda$verifyLabel::class$ = nullptr;

class SwitchBootstraps$$Lambda$lambda$enumSwitch$0$1 : public $Function {
	$class(SwitchBootstraps$$Lambda$lambda$enumSwitch$0$1, $NO_CLASS_INIT, $Function)
public:
	void init$($MethodHandles$Lookup* lookup, $Class* enumClass) {
		$set(this, lookup, lookup);
		this->enumClass = enumClass;
	}
	virtual $Object* apply(Object$* l) override {
		 return SwitchBootstraps::lambda$enumSwitch$0(lookup, enumClass, l);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SwitchBootstraps$$Lambda$lambda$enumSwitch$0$1>());
	}
	$MethodHandles$Lookup* lookup = nullptr;
	$Class* enumClass = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SwitchBootstraps$$Lambda$lambda$enumSwitch$0$1::fieldInfos[3] = {
	{"lookup", "Ljava/lang/invoke/MethodHandles$Lookup;", nullptr, $PUBLIC, $field(SwitchBootstraps$$Lambda$lambda$enumSwitch$0$1, lookup)},
	{"enumClass", "Ljava/lang/Class;", nullptr, $PUBLIC, $field(SwitchBootstraps$$Lambda$lambda$enumSwitch$0$1, enumClass)},
	{}
};
$MethodInfo SwitchBootstraps$$Lambda$lambda$enumSwitch$0$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/invoke/MethodHandles$Lookup;Ljava/lang/Class;)V", nullptr, $PUBLIC, $method(SwitchBootstraps$$Lambda$lambda$enumSwitch$0$1, init$, void, $MethodHandles$Lookup*, $Class*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(SwitchBootstraps$$Lambda$lambda$enumSwitch$0$1, apply, $Object*, Object$*)},
	{}
};
$ClassInfo SwitchBootstraps$$Lambda$lambda$enumSwitch$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.runtime.SwitchBootstraps$$Lambda$lambda$enumSwitch$0$1",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* SwitchBootstraps$$Lambda$lambda$enumSwitch$0$1::load$($String* name, bool initialize) {
	$loadClass(SwitchBootstraps$$Lambda$lambda$enumSwitch$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SwitchBootstraps$$Lambda$lambda$enumSwitch$0$1::class$ = nullptr;

$CompoundAttribute _SwitchBootstraps_Annotations_[] = {
	{}
};

$FieldInfo _SwitchBootstraps_FieldInfo_[] = {
	{"LOOKUP", "Ljava/lang/invoke/MethodHandles$Lookup;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SwitchBootstraps, LOOKUP)},
	{"DO_TYPE_SWITCH", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SwitchBootstraps, DO_TYPE_SWITCH)},
	{"DO_ENUM_SWITCH", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SwitchBootstraps, DO_ENUM_SWITCH)},
	{}
};

$MethodInfo _SwitchBootstraps_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(SwitchBootstraps, init$, void)},
	{"convertEnumConstants", "(Ljava/lang/invoke/MethodHandles$Lookup;Ljava/lang/Class;Ljava/lang/Object;)Ljava/lang/Object;", "<E:Ljava/lang/Enum<TE;>;>(Ljava/lang/invoke/MethodHandles$Lookup;Ljava/lang/Class<*>;Ljava/lang/Object;)Ljava/lang/Object;", $PRIVATE | $STATIC, $staticMethod(SwitchBootstraps, convertEnumConstants, $Object*, $MethodHandles$Lookup*, $Class*, Object$*)},
	{"doEnumSwitch", "(Ljava/lang/Enum;I[Ljava/lang/Object;)I", "(Ljava/lang/Enum<*>;I[Ljava/lang/Object;)I", $PRIVATE | $STATIC, $staticMethod(SwitchBootstraps, doEnumSwitch, int32_t, $Enum*, int32_t, $ObjectArray*)},
	{"doTypeSwitch", "(Ljava/lang/Object;I[Ljava/lang/Object;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(SwitchBootstraps, doTypeSwitch, int32_t, Object$*, int32_t, $ObjectArray*)},
	{"enumSwitch", "(Ljava/lang/invoke/MethodHandles$Lookup;Ljava/lang/String;Ljava/lang/invoke/MethodType;[Ljava/lang/Object;)Ljava/lang/invoke/CallSite;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(SwitchBootstraps, enumSwitch, $CallSite*, $MethodHandles$Lookup*, $String*, $MethodType*, $ObjectArray*)},
	{"lambda$enumSwitch$0", "(Ljava/lang/invoke/MethodHandles$Lookup;Ljava/lang/Class;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(SwitchBootstraps, lambda$enumSwitch$0, $Object*, $MethodHandles$Lookup*, $Class*, Object$*)},
	{"typeSwitch", "(Ljava/lang/invoke/MethodHandles$Lookup;Ljava/lang/String;Ljava/lang/invoke/MethodType;[Ljava/lang/Object;)Ljava/lang/invoke/CallSite;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(SwitchBootstraps, typeSwitch, $CallSite*, $MethodHandles$Lookup*, $String*, $MethodType*, $ObjectArray*)},
	{"verifyLabel", "(Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(SwitchBootstraps, verifyLabel, void, Object$*)},
	{}
};

$ClassInfo _SwitchBootstraps_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.lang.runtime.SwitchBootstraps",
	"java.lang.Object",
	nullptr,
	_SwitchBootstraps_FieldInfo_,
	_SwitchBootstraps_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_SwitchBootstraps_Annotations_
};

$Object* allocate$SwitchBootstraps($Class* clazz) {
	return $of($alloc(SwitchBootstraps));
}

$MethodHandles$Lookup* SwitchBootstraps::LOOKUP = nullptr;
$MethodHandle* SwitchBootstraps::DO_TYPE_SWITCH = nullptr;
$MethodHandle* SwitchBootstraps::DO_ENUM_SWITCH = nullptr;

void SwitchBootstraps::init$() {
}

$CallSite* SwitchBootstraps::typeSwitch($MethodHandles$Lookup* lookup, $String* invocationName, $MethodType* invocationType, $ObjectArray* labels$renamed) {
	$init(SwitchBootstraps);
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, labels, labels$renamed);
	bool var$2 = $nc(invocationType)->parameterCount() != 2;
	$init($Integer);
	bool var$1 = var$2 || (!$nc($of($($cast($Class, $nc(invocationType)->returnType()))))->equals($Integer::TYPE));
	bool var$0 = var$1 || $nc($($cast($Class, $nc(invocationType)->parameterType(0))))->isPrimitive();
	if (var$0 || !$nc($of($($cast($Class, $nc(invocationType)->parameterType(1)))))->equals($Integer::TYPE)) {
		$throwNew($IllegalArgumentException, $$str({"Illegal invocation type "_s, invocationType}));
	}
	$Objects::requireNonNull(labels);
	$assign(labels, $cast($ObjectArray, labels->clone()));
	$nc($($Stream::of(labels)))->forEach(static_cast<$Consumer*>($$new(SwitchBootstraps$$Lambda$verifyLabel)));
	$var($MethodHandle, target, $MethodHandles::insertArguments(SwitchBootstraps::DO_TYPE_SWITCH, 2, $$new($ObjectArray, {$of(labels)})));
	return $new($ConstantCallSite, target);
}

void SwitchBootstraps::verifyLabel(Object$* label) {
	$init(SwitchBootstraps);
	if (label == nullptr) {
		$throwNew($IllegalArgumentException, "null label found"_s);
	}
	$Class* labelClass = $nc($of(label))->getClass();
	$load($Integer);
	if (labelClass != $Class::class$ && labelClass != $String::class$ && labelClass != $Integer::class$) {
		$throwNew($IllegalArgumentException, $$str({"label with illegal type found: "_s, $of(label)->getClass()}));
	}
}

int32_t SwitchBootstraps::doTypeSwitch(Object$* target, int32_t startIndex, $ObjectArray* labels) {
	$init(SwitchBootstraps);
	$useLocalCurrentObjectStackCache();
	if (target == nullptr) {
		return -1;
	}
	$Class* targetClass = $nc($of(target))->getClass();
	for (int32_t i = startIndex; i < $nc(labels)->length; ++i) {
		$var($Object0, label, labels->get(i));
		{
			$Class* c = nullptr;
			$var($Integer, constant, nullptr);
			bool var$0 = $instanceOf($Class, label);
			if (var$0) {
				c = $cast($Class, label);
				var$0 = true;
			}
			if (var$0) {
				if ($nc(c)->isAssignableFrom(targetClass)) {
					return i;
				}
			} else {
				bool var$2 = $instanceOf($Integer, label);
				if (var$2) {
					$assign(constant, $cast($Integer, label));
					var$2 = true;
				}
				if (var$2) {
					{
						$var($Number, input, nullptr);
						$var($Character, input_1, nullptr);
						bool var$4 = $instanceOf($Number, target);
						if (var$4) {
							$assign(input, $cast($Number, target));
							var$4 = true;
						}
						bool var$3 = var$4;
						if (var$3) {
							int32_t var$5 = $nc(constant)->intValue();
							var$3 = var$5 == $nc(input)->intValue();
						}
						if (var$3) {
							return i;
						} else {
							bool var$10 = $instanceOf($Character, target);
							if (var$10) {
								$assign(input_1, $cast($Character, target));
								var$10 = true;
							}
							bool var$9 = var$10;
							if (var$9) {
								int32_t var$11 = constant->intValue();
								var$9 = var$11 == input_1->charValue();
							}
							if (var$9) {
								return i;
							}
						}
					}
				} else if ($nc($of(label))->equals(target)) {
					return i;
				}
			}
		}
	}
	return $nc(labels)->length;
}

$CallSite* SwitchBootstraps::enumSwitch($MethodHandles$Lookup* lookup, $String* invocationName, $MethodType* invocationType, $ObjectArray* labels$renamed) {
	$init(SwitchBootstraps);
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, labels, labels$renamed);
	bool var$3 = $nc(invocationType)->parameterCount() != 2;
	$init($Integer);
	bool var$2 = var$3 || (!$nc($of($($cast($Class, $nc(invocationType)->returnType()))))->equals($Integer::TYPE));
	bool var$1 = var$2 || $nc($($cast($Class, $nc(invocationType)->parameterType(0))))->isPrimitive();
	bool var$0 = var$1 || !$nc($($cast($Class, $nc(invocationType)->parameterType(0))))->isEnum();
	if (var$0 || !$nc($of($($cast($Class, $nc(invocationType)->parameterType(1)))))->equals($Integer::TYPE)) {
		$throwNew($IllegalArgumentException, $$str({"Illegal invocation type "_s, invocationType}));
	}
	$Objects::requireNonNull(labels);
	$assign(labels, $cast($ObjectArray, labels->clone()));
	$Class* enumClass = $cast($Class, $nc(invocationType)->parameterType(0));
	$assign(labels, $nc($($nc($($Stream::of(labels)))->map(static_cast<$Function*>($$new(SwitchBootstraps$$Lambda$lambda$enumSwitch$0$1, lookup, enumClass)))))->toArray());
	$var($MethodHandle, target, $MethodHandles::insertArguments(SwitchBootstraps::DO_ENUM_SWITCH, 2, $$new($ObjectArray, {$of(labels)})));
	$assign(target, $nc(target)->asType(invocationType));
	return $new($ConstantCallSite, target);
}

$Object* SwitchBootstraps::convertEnumConstants($MethodHandles$Lookup* lookup, $Class* enumClassTemplate, Object$* label) {
	$init(SwitchBootstraps);
	$useLocalCurrentObjectStackCache();
	if (label == nullptr) {
		$throwNew($IllegalArgumentException, "null label found"_s);
	}
	$Class* labelClass = $nc($of(label))->getClass();
	if (labelClass == $Class::class$) {
		if (!$equals(label, enumClassTemplate)) {
			$throwNew($IllegalArgumentException, $$str({"the Class label: "_s, label, ", expected the provided enum class: "_s, enumClassTemplate}));
		}
		return $of(label);
	} else if (labelClass == $String::class$) {
		$Class* enumClass = enumClassTemplate;
		try {
			return $of($ConstantBootstraps::enumConstant(lookup, $cast($String, label), enumClass));
		} catch ($IllegalArgumentException& ex) {
			return $of(nullptr);
		}
	} else {
		$throwNew($IllegalArgumentException, $$str({"label with illegal type found: "_s, labelClass, ", expected label of type either String or Class"_s}));
	}
	$shouldNotReachHere();
}

int32_t SwitchBootstraps::doEnumSwitch($Enum* target, int32_t startIndex, $ObjectArray* labels) {
	$init(SwitchBootstraps);
	$useLocalCurrentObjectStackCache();
	if (target == nullptr) {
		return -1;
	}
	$Class* targetClass = $nc($of(target))->getClass();
	for (int32_t i = startIndex; i < $nc(labels)->length; ++i) {
		$var($Object0, label, labels->get(i));
		{
			$Class* c = nullptr;
			bool var$0 = $instanceOf($Class, label);
			if (var$0) {
				c = $cast($Class, label);
				var$0 = true;
			}
			if (var$0) {
				if ($nc(c)->isAssignableFrom(targetClass)) {
					return i;
				}
			} else if ($equals(label, target)) {
				return i;
			}
		}
	}
	return $nc(labels)->length;
}

$Object* SwitchBootstraps::lambda$enumSwitch$0($MethodHandles$Lookup* lookup, $Class* enumClass, Object$* l) {
	$init(SwitchBootstraps);
	return $of(convertEnumConstants(lookup, enumClass, l));
}

void clinit$SwitchBootstraps($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$assignStatic(SwitchBootstraps::LOOKUP, $MethodHandles::lookup());
	{
		try {
			$init($Integer);
			$load($ObjectArray);
			$assignStatic(SwitchBootstraps::DO_TYPE_SWITCH, $nc(SwitchBootstraps::LOOKUP)->findStatic(SwitchBootstraps::class$, "doTypeSwitch"_s, $($MethodType::methodType($Integer::TYPE, $Object::class$, $$new($ClassArray, {
				$Integer::TYPE,
				$getClass($ObjectArray)
			})))));
			$load($Enum);
			$assignStatic(SwitchBootstraps::DO_ENUM_SWITCH, $nc(SwitchBootstraps::LOOKUP)->findStatic(SwitchBootstraps::class$, "doEnumSwitch"_s, $($MethodType::methodType($Integer::TYPE, $Enum::class$, $$new($ClassArray, {
				$Integer::TYPE,
				$getClass($ObjectArray)
			})))));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(e));
		}
	}
}

SwitchBootstraps::SwitchBootstraps() {
}

$Class* SwitchBootstraps::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SwitchBootstraps$$Lambda$verifyLabel::classInfo$.name)) {
			return SwitchBootstraps$$Lambda$verifyLabel::load$(name, initialize);
		}
		if (name->equals(SwitchBootstraps$$Lambda$lambda$enumSwitch$0$1::classInfo$.name)) {
			return SwitchBootstraps$$Lambda$lambda$enumSwitch$0$1::load$(name, initialize);
		}
	}
	$loadClass(SwitchBootstraps, name, initialize, &_SwitchBootstraps_ClassInfo_, clinit$SwitchBootstraps, allocate$SwitchBootstraps);
	return class$;
}

$Class* SwitchBootstraps::class$ = nullptr;

		} // runtime
	} // lang
} // java