#include <java/lang/invoke/ClassSpecializer.h>

#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/lang/NoSuchFieldException.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/invoke/ClassSpecializer$1.h>
#include <java/lang/invoke/ClassSpecializer$Factory.h>
#include <java/lang/invoke/ClassSpecializer$SpeciesData.h>
#include <java/lang/invoke/MemberName.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandleStatics.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Field.h>
#include <java/util/Collection.h>
#include <java/util/List.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/function/Function.h>
#include <jcpp.h>

#undef CREATE_RESERVATION
#undef E_THROWABLE
#undef MH
#undef MH_SIG
#undef STABLE
#undef STABLE_SIG
#undef TYPE

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchFieldException = ::java::lang::NoSuchFieldException;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $RuntimeException = ::java::lang::RuntimeException;
using $Void = ::java::lang::Void;
using $ClassSpecializer$1 = ::java::lang::invoke::ClassSpecializer$1;
using $ClassSpecializer$Factory = ::java::lang::invoke::ClassSpecializer$Factory;
using $ClassSpecializer$SpeciesData = ::java::lang::invoke::ClassSpecializer$SpeciesData;
using $MemberName = ::java::lang::invoke::MemberName;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandleStatics = ::java::lang::invoke::MethodHandleStatics;
using $MethodType = ::java::lang::invoke::MethodType;
using $Constructor = ::java::lang::reflect::Constructor;
using $Field = ::java::lang::reflect::Field;
using $Collection = ::java::util::Collection;
using $List = ::java::util::List;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $Function = ::java::util::function::Function;

namespace java {
	namespace lang {
		namespace invoke {

$CompoundAttribute _ClassSpecializer_FieldAnnotations_topClassIsSuper[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$FieldInfo _ClassSpecializer_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ClassSpecializer, $assertionsDisabled)},
	{"topClass", "Ljava/lang/Class;", "Ljava/lang/Class<TT;>;", $PRIVATE | $FINAL, $field(ClassSpecializer, topClass$)},
	{"keyType", "Ljava/lang/Class;", "Ljava/lang/Class<TK;>;", $PRIVATE | $FINAL, $field(ClassSpecializer, keyType$)},
	{"metaType", "Ljava/lang/Class;", "Ljava/lang/Class<TS;>;", $PRIVATE | $FINAL, $field(ClassSpecializer, metaType$)},
	{"sdAccessor", "Ljava/lang/invoke/MemberName;", nullptr, $PRIVATE | $FINAL, $field(ClassSpecializer, sdAccessor)},
	{"sdFieldName", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(ClassSpecializer, sdFieldName)},
	{"transformMethods", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/invoke/MemberName;>;", $PRIVATE | $FINAL, $field(ClassSpecializer, transformMethods$)},
	{"baseConstructorType", "Ljava/lang/invoke/MethodType;", nullptr, $PRIVATE | $FINAL, $field(ClassSpecializer, baseConstructorType$)},
	{"topSpecies", "Ljava/lang/invoke/ClassSpecializer$SpeciesData;", "TS;", $PRIVATE | $FINAL, $field(ClassSpecializer, topSpecies$)},
	{"cache", "Ljava/util/concurrent/ConcurrentHashMap;", "Ljava/util/concurrent/ConcurrentHashMap<TK;Ljava/lang/Object;>;", $PRIVATE | $FINAL, $field(ClassSpecializer, cache)},
	{"factory", "Ljava/lang/invoke/ClassSpecializer$Factory;", "Ljava/lang/invoke/ClassSpecializer<TT;TK;TS;>.Factory;", $PRIVATE | $FINAL, $field(ClassSpecializer, factory$)},
	{"topClassIsSuper", "Z", nullptr, $PRIVATE, $field(ClassSpecializer, topClassIsSuper), _ClassSpecializer_FieldAnnotations_topClassIsSuper},
	{"CREATE_RESERVATION", "Ljava/util/function/Function;", "Ljava/util/function/Function<Ljava/lang/Object;Ljava/lang/Object;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ClassSpecializer, CREATE_RESERVATION)},
	{"MH", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ClassSpecializer, MH)},
	{"MH_SIG", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ClassSpecializer, MH_SIG)},
	{"STABLE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ClassSpecializer, STABLE)},
	{"STABLE_SIG", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ClassSpecializer, STABLE_SIG)},
	{"E_THROWABLE", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ClassSpecializer, E_THROWABLE)},
	{}
};

$MethodInfo _ClassSpecializer_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Class;Ljava/lang/Class;Ljava/lang/Class;Ljava/lang/invoke/MethodType;Ljava/lang/invoke/MemberName;Ljava/lang/String;Ljava/util/List;)V", "(Ljava/lang/Class<TT;>;Ljava/lang/Class<TK;>;Ljava/lang/Class<TS;>;Ljava/lang/invoke/MethodType;Ljava/lang/invoke/MemberName;Ljava/lang/String;Ljava/util/List<Ljava/lang/invoke/MemberName;>;)V", $PROTECTED, $method(ClassSpecializer, init$, void, $Class*, $Class*, $Class*, $MethodType*, $MemberName*, $String*, $List*)},
	{"baseConstructorType", "()Ljava/lang/invoke/MethodType;", nullptr, $PROTECTED, $virtualMethod(ClassSpecializer, baseConstructorType, $MethodType*)},
	{"classBCName", "(Ljava/lang/Class;)Ljava/lang/String;", "(Ljava/lang/Class<*>;)Ljava/lang/String;", $STATIC, $staticMethod(ClassSpecializer, classBCName, $String*, $Class*)},
	{"classBCName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(ClassSpecializer, classBCName, $String*, $String*)},
	{"className", "(Ljava/lang/Class;)Ljava/lang/String;", "(Ljava/lang/Class<*>;)Ljava/lang/String;", $STATIC, $staticMethod(ClassSpecializer, className, $String*, $Class*)},
	{"classSig", "(Ljava/lang/Class;)Ljava/lang/String;", "(Ljava/lang/Class<*>;)Ljava/lang/String;", $STATIC, $staticMethod(ClassSpecializer, classSig, $String*, $Class*)},
	{"classSig", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(ClassSpecializer, classSig, $String*, $String*)},
	{"factory", "()Ljava/lang/invoke/ClassSpecializer$Factory;", "()Ljava/lang/invoke/ClassSpecializer<TT;TK;TS;>.Factory;", $PROTECTED | $FINAL, $method(ClassSpecializer, factory, $ClassSpecializer$Factory*)},
	{"findSpecies", "(Ljava/lang/Object;)Ljava/lang/invoke/ClassSpecializer$SpeciesData;", "(TK;)TS;", $PUBLIC | $FINAL, $method(ClassSpecializer, findSpecies, $ClassSpecializer$SpeciesData*, Object$*)},
	{"keyType", "()Ljava/lang/Class;", "()Ljava/lang/Class<TK;>;", $PUBLIC | $FINAL, $method(ClassSpecializer, keyType, $Class*)},
	{"makeFactory", "()Ljava/lang/invoke/ClassSpecializer$Factory;", "()Ljava/lang/invoke/ClassSpecializer<TT;TK;TS;>.Factory;", $PROTECTED, $virtualMethod(ClassSpecializer, makeFactory, $ClassSpecializer$Factory*)},
	{"metaType", "()Ljava/lang/Class;", "()Ljava/lang/Class<TS;>;", $PUBLIC | $FINAL, $method(ClassSpecializer, metaType, $Class*)},
	{"methodSig", "(Ljava/lang/invoke/MethodType;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(ClassSpecializer, methodSig, $String*, $MethodType*)},
	{"newIAE", "(Ljava/lang/String;Ljava/lang/Throwable;)Ljava/lang/RuntimeException;", nullptr, $PRIVATE | $STATIC, $staticMethod(ClassSpecializer, newIAE, $RuntimeException*, $String*, $Throwable*)},
	{"newSpeciesData", "(Ljava/lang/Object;)Ljava/lang/invoke/ClassSpecializer$SpeciesData;", "(TK;)TS;", $PROTECTED | $ABSTRACT, $virtualMethod(ClassSpecializer, newSpeciesData, $ClassSpecializer$SpeciesData*, Object$*)},
	{"reflectConstructor", "(Ljava/lang/Class;[Ljava/lang/Class;)Ljava/lang/reflect/Constructor;", "<T:Ljava/lang/Object;>(Ljava/lang/Class<TT;>;[Ljava/lang/Class<*>;)Ljava/lang/reflect/Constructor<TT;>;", $PROTECTED | $STATIC | $TRANSIENT, $staticMethod(ClassSpecializer, reflectConstructor, $Constructor*, $Class*, $ClassArray*)},
	{"reflectField", "(Ljava/lang/Class;Ljava/lang/String;)Ljava/lang/reflect/Field;", "(Ljava/lang/Class<*>;Ljava/lang/String;)Ljava/lang/reflect/Field;", $PROTECTED | $STATIC, $staticMethod(ClassSpecializer, reflectField, $Field*, $Class*, $String*)},
	{"topClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<TT;>;", $PUBLIC | $FINAL, $method(ClassSpecializer, topClass, $Class*)},
	{"topSpecies", "()Ljava/lang/invoke/ClassSpecializer$SpeciesData;", "()TS;", $PROTECTED | $FINAL, $method(ClassSpecializer, topSpecies, $ClassSpecializer$SpeciesData*)},
	{"topSpeciesKey", "()Ljava/lang/Object;", "()TK;", $PROTECTED, $virtualMethod(ClassSpecializer, topSpeciesKey, $Object*)},
	{"transformMethods", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/invoke/MemberName;>;", $PROTECTED | $FINAL, $method(ClassSpecializer, transformMethods, $List*)},
	{}
};

$InnerClassInfo _ClassSpecializer_InnerClassesInfo_[] = {
	{"java.lang.invoke.ClassSpecializer$Factory", "java.lang.invoke.ClassSpecializer", "Factory", $PUBLIC},
	{"java.lang.invoke.ClassSpecializer$SpeciesData", "java.lang.invoke.ClassSpecializer", "SpeciesData", $PUBLIC | $ABSTRACT},
	{"java.lang.invoke.ClassSpecializer$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ClassSpecializer_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"java.lang.invoke.ClassSpecializer",
	"java.lang.Object",
	nullptr,
	_ClassSpecializer_FieldInfo_,
	_ClassSpecializer_MethodInfo_,
	"<T:Ljava/lang/Object;K:Ljava/lang/Object;S:Ljava/lang/invoke/ClassSpecializer<TT;TK;TS;>.SpeciesData;>Ljava/lang/Object;",
	nullptr,
	_ClassSpecializer_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.invoke.ClassSpecializer$Factory,java.lang.invoke.ClassSpecializer$Factory$1Var,java.lang.invoke.ClassSpecializer$Factory$1,java.lang.invoke.ClassSpecializer$SpeciesData,java.lang.invoke.ClassSpecializer$1"
};

$Object* allocate$ClassSpecializer($Class* clazz) {
	return $of($alloc(ClassSpecializer));
}

bool ClassSpecializer::$assertionsDisabled = false;
$Function* ClassSpecializer::CREATE_RESERVATION = nullptr;
$String* ClassSpecializer::MH = nullptr;
$String* ClassSpecializer::MH_SIG = nullptr;
$String* ClassSpecializer::STABLE = nullptr;
$String* ClassSpecializer::STABLE_SIG = nullptr;
$StringArray* ClassSpecializer::E_THROWABLE = nullptr;

$Class* ClassSpecializer::topClass() {
	return this->topClass$;
}

$Class* ClassSpecializer::keyType() {
	return this->keyType$;
}

$Class* ClassSpecializer::metaType() {
	return this->metaType$;
}

$MethodType* ClassSpecializer::baseConstructorType() {
	return this->baseConstructorType$;
}

$ClassSpecializer$SpeciesData* ClassSpecializer::topSpecies() {
	return this->topSpecies$;
}

$List* ClassSpecializer::transformMethods() {
	return this->transformMethods$;
}

$ClassSpecializer$Factory* ClassSpecializer::factory() {
	return this->factory$;
}

void ClassSpecializer::init$($Class* topClass, $Class* keyType, $Class* metaType, $MethodType* baseConstructorType, $MemberName* sdAccessor, $String* sdFieldName, $List* transformMethods) {
	$useLocalCurrentObjectStackCache();
	$set(this, cache, $new($ConcurrentHashMap));
	$set(this, topClass$, topClass);
	$set(this, keyType$, keyType);
	$set(this, metaType$, metaType);
	$set(this, sdAccessor, sdAccessor);
	$set(this, transformMethods$, $List::copyOf(transformMethods));
	$set(this, sdFieldName, sdFieldName);
	$init($Void);
	$set(this, baseConstructorType$, $nc(baseConstructorType)->changeReturnType($Void::TYPE));
	$set(this, factory$, makeFactory());
	$var($Object, tsk, topSpeciesKey());
	$var($ClassSpecializer$SpeciesData, topSpecies, nullptr);
	if (tsk != nullptr && topSpecies == nullptr) {
		$assign(topSpecies, findSpecies(tsk));
	}
	$set(this, topSpecies$, topSpecies);
}

$Constructor* ClassSpecializer::reflectConstructor($Class* defc, $ClassArray* ptypes) {
	$init(ClassSpecializer);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		return $nc(defc)->getDeclaredConstructor(ptypes);
	} catch ($NoSuchMethodException& ex) {
		$var($String, var$1, $$str({$($nc(defc)->getName()), "("_s}));
		$init($Void);
		$var($String, var$0, $$concat(var$1, $($MethodType::methodType($Void::TYPE, ptypes))));
		$throw($(newIAE($$concat(var$0, ")"_s), ex)));
	}
	$shouldNotReachHere();
}

$Field* ClassSpecializer::reflectField($Class* defc, $String* name) {
	$init(ClassSpecializer);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		return $nc(defc)->getDeclaredField(name);
	} catch ($NoSuchFieldException& ex) {
		$throw($(newIAE($$str({$($nc(defc)->getName()), "."_s, name}), ex)));
	}
	$shouldNotReachHere();
}

$RuntimeException* ClassSpecializer::newIAE($String* message, $Throwable* cause) {
	$init(ClassSpecializer);
	return $new($IllegalArgumentException, message, cause);
}

$ClassSpecializer$SpeciesData* ClassSpecializer::findSpecies(Object$* key) {
	$useLocalCurrentObjectStackCache();
	$var($Object, speciesDataOrReservation, $nc(this->cache)->computeIfAbsent(key, ClassSpecializer::CREATE_RESERVATION));
	$var($ClassSpecializer$SpeciesData, speciesData, nullptr);
	if ($nc($of(speciesDataOrReservation))->getClass() == $Object::class$) {
		$synchronized(speciesDataOrReservation) {
			$var($Object, existingSpeciesData, $nc(this->cache)->get(key));
			if ($equals(existingSpeciesData, speciesDataOrReservation)) {
				$assign(speciesData, newSpeciesData(key));
				$assign(speciesData, $nc(this->factory$)->loadSpecies(speciesData));
				if (!$nc(this->cache)->replace(key, existingSpeciesData, speciesData)) {
					$throw($($MethodHandleStatics::newInternalError("Concurrent loadSpecies"_s)));
				}
			} else {
				$assign(speciesData, $cast($ClassSpecializer$SpeciesData, $nc(this->metaType$)->cast(existingSpeciesData)));
			}
		}
	} else {
		$assign(speciesData, $cast($ClassSpecializer$SpeciesData, $nc(this->metaType$)->cast(speciesDataOrReservation)));
	}
	if (!ClassSpecializer::$assertionsDisabled && !(speciesData != nullptr && speciesData->isResolved())) {
		$throwNew($AssertionError);
	}
	return speciesData;
}

$Object* ClassSpecializer::topSpeciesKey() {
	return $of(nullptr);
}

$ClassSpecializer$Factory* ClassSpecializer::makeFactory() {
	return $new($ClassSpecializer$Factory, this);
}

$String* ClassSpecializer::methodSig($MethodType* mt) {
	$init(ClassSpecializer);
	return $nc(mt)->toMethodDescriptorString();
}

$String* ClassSpecializer::classSig($Class* cls) {
	$init(ClassSpecializer);
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(cls)->isPrimitive();
	if (var$0 || $nc(cls)->isArray()) {
		return $nc($($nc($($MethodType::methodType(cls)))->toMethodDescriptorString()))->substring(2);
	}
	return classSig($(classBCName(cls)));
}

$String* ClassSpecializer::classSig($String* bcName) {
	$init(ClassSpecializer);
	if (!ClassSpecializer::$assertionsDisabled && !($nc(bcName)->indexOf((int32_t)u'.') < 0)) {
		$throwNew($AssertionError);
	}
	if (!ClassSpecializer::$assertionsDisabled && !(!$nc(bcName)->endsWith(";"_s))) {
		$throwNew($AssertionError);
	}
	if (!ClassSpecializer::$assertionsDisabled && !(!$nc(bcName)->startsWith("["_s))) {
		$throwNew($AssertionError);
	}
	return $str({"L"_s, bcName, ";"_s});
}

$String* ClassSpecializer::classBCName($Class* cls) {
	$init(ClassSpecializer);
	return classBCName($(className(cls)));
}

$String* ClassSpecializer::classBCName($String* str) {
	$init(ClassSpecializer);
	if (!ClassSpecializer::$assertionsDisabled && !($nc(str)->indexOf((int32_t)u'/') < 0)) {
		$throwNew($AssertionError, $of(str));
	}
	return $nc(str)->replace(u'.', u'/');
}

$String* ClassSpecializer::className($Class* cls) {
	$init(ClassSpecializer);
	bool var$0 = !ClassSpecializer::$assertionsDisabled;
	if (var$0) {
		bool var$1 = !$nc(cls)->isArray();
		var$0 = !(var$1 && !cls->isPrimitive());
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	return $nc(cls)->getName();
}

void clinit$ClassSpecializer($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(ClassSpecializer::MH, "java/lang/invoke/MethodHandle"_s);
	$assignStatic(ClassSpecializer::MH_SIG, $str({"L"_s, ClassSpecializer::MH, ";"_s}));
	$assignStatic(ClassSpecializer::STABLE, "jdk/internal/vm/annotation/Stable"_s);
	$assignStatic(ClassSpecializer::STABLE_SIG, $str({"L"_s, ClassSpecializer::STABLE, ";"_s}));
	ClassSpecializer::$assertionsDisabled = !ClassSpecializer::class$->desiredAssertionStatus();
	$assignStatic(ClassSpecializer::CREATE_RESERVATION, $new($ClassSpecializer$1));
	$assignStatic(ClassSpecializer::E_THROWABLE, $new($StringArray, {"java/lang/Throwable"_s}));
	{
		$load($MethodHandle);
		if (!ClassSpecializer::$assertionsDisabled && !($nc(ClassSpecializer::MH_SIG)->equals($(ClassSpecializer::classSig($MethodHandle::class$))))) {
			$throwNew($AssertionError);
		}
		if (!ClassSpecializer::$assertionsDisabled && !($nc(ClassSpecializer::MH)->equals($(ClassSpecializer::classBCName($MethodHandle::class$))))) {
			$throwNew($AssertionError);
		}
	}
}

ClassSpecializer::ClassSpecializer() {
}

$Class* ClassSpecializer::load$($String* name, bool initialize) {
	$loadClass(ClassSpecializer, name, initialize, &_ClassSpecializer_ClassInfo_, clinit$ClassSpecializer, allocate$ClassSpecializer);
	return class$;
}

$Class* ClassSpecializer::class$ = nullptr;

		} // invoke
	} // lang
} // java