#include <java/lang/invoke/ClassSpecializer$SpeciesData.h>

#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/InternalError.h>
#include <java/lang/invoke/ClassSpecializer.h>
#include <java/lang/invoke/LambdaForm$BasicType.h>
#include <java/lang/invoke/LambdaForm$NamedFunction.h>
#include <java/lang/invoke/LambdaForm.h>
#include <java/lang/invoke/MemberName.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandleStatics.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/TypeDescriptor$OfField.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Modifier.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <sun/invoke/util/BytecodeName.h>
#include <jcpp.h>

using $MethodHandleArray = $Array<::java::lang::invoke::MethodHandle>;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $ClassSpecializer = ::java::lang::invoke::ClassSpecializer;
using $LambdaForm = ::java::lang::invoke::LambdaForm;
using $LambdaForm$BasicType = ::java::lang::invoke::LambdaForm$BasicType;
using $LambdaForm$NamedFunction = ::java::lang::invoke::LambdaForm$NamedFunction;
using $MemberName = ::java::lang::invoke::MemberName;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandleStatics = ::java::lang::invoke::MethodHandleStatics;
using $MethodType = ::java::lang::invoke::MethodType;
using $Constructor = ::java::lang::reflect::Constructor;
using $Modifier = ::java::lang::reflect::Modifier;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $BytecodeName = ::sun::invoke::util::BytecodeName;

namespace java {
	namespace lang {
		namespace invoke {

$CompoundAttribute _ClassSpecializer$SpeciesData_FieldAnnotations_speciesCode[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _ClassSpecializer$SpeciesData_FieldAnnotations_factories[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _ClassSpecializer$SpeciesData_FieldAnnotations_getters[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _ClassSpecializer$SpeciesData_FieldAnnotations_nominalGetters[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _ClassSpecializer$SpeciesData_FieldAnnotations_transformHelpers[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$FieldInfo _ClassSpecializer$SpeciesData_FieldInfo_[] = {
	{"this$0", "Ljava/lang/invoke/ClassSpecializer;", nullptr, $FINAL | $SYNTHETIC, $field(ClassSpecializer$SpeciesData, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ClassSpecializer$SpeciesData, $assertionsDisabled)},
	{"key", "Ljava/lang/Object;", "TK;", $PRIVATE | $FINAL, $field(ClassSpecializer$SpeciesData, key$)},
	{"fieldTypes", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Class<*>;>;", $PRIVATE | $FINAL, $field(ClassSpecializer$SpeciesData, fieldTypes$)},
	{"speciesCode", "Ljava/lang/Class;", "Ljava/lang/Class<+TT;>;", $PRIVATE, $field(ClassSpecializer$SpeciesData, speciesCode$), _ClassSpecializer$SpeciesData_FieldAnnotations_speciesCode},
	{"factories", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/invoke/MethodHandle;>;", $PRIVATE, $field(ClassSpecializer$SpeciesData, factories), _ClassSpecializer$SpeciesData_FieldAnnotations_factories},
	{"getters", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/invoke/MethodHandle;>;", $PRIVATE, $field(ClassSpecializer$SpeciesData, getters$), _ClassSpecializer$SpeciesData_FieldAnnotations_getters},
	{"nominalGetters", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/invoke/LambdaForm$NamedFunction;>;", $PRIVATE, $field(ClassSpecializer$SpeciesData, nominalGetters), _ClassSpecializer$SpeciesData_FieldAnnotations_nominalGetters},
	{"transformHelpers", "[Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $FINAL, $field(ClassSpecializer$SpeciesData, transformHelpers), _ClassSpecializer$SpeciesData_FieldAnnotations_transformHelpers},
	{}
};

$MethodInfo _ClassSpecializer$SpeciesData_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/invoke/ClassSpecializer;Ljava/lang/Object;)V", "(TK;)V", $PROTECTED, $method(ClassSpecializer$SpeciesData, init$, void, $ClassSpecializer*, Object$*)},
	{"deriveClassName", "()Ljava/lang/String;", nullptr, $PROTECTED, $virtualMethod(ClassSpecializer$SpeciesData, deriveClassName, $String*)},
	{"deriveFieldTypes", "(Ljava/lang/Object;)Ljava/util/List;", "(TK;)Ljava/util/List<Ljava/lang/Class<*>;>;", $PROTECTED | $ABSTRACT, $virtualMethod(ClassSpecializer$SpeciesData, deriveFieldTypes, $List*, Object$*)},
	{"deriveSuperClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<+TT;>;", $PROTECTED, $virtualMethod(ClassSpecializer$SpeciesData, deriveSuperClass, $Class*)},
	{"deriveTransformHelper", "(Ljava/lang/invoke/MemberName;I)Ljava/lang/invoke/MethodHandle;", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(ClassSpecializer$SpeciesData, deriveTransformHelper, $MethodHandle*, $MemberName*, int32_t)},
	{"deriveTransformHelperArguments", "(Ljava/lang/invoke/MemberName;ILjava/util/List;Ljava/util/List;)Ljava/util/List;", "<X:Ljava/lang/Object;>(Ljava/lang/invoke/MemberName;ILjava/util/List<TX;>;Ljava/util/List<TX;>;)Ljava/util/List<TX;>;", $PROTECTED | $ABSTRACT, $virtualMethod(ClassSpecializer$SpeciesData, deriveTransformHelperArguments, $List*, $MemberName*, int32_t, $List*, $List*)},
	{"deriveTypeString", "()Ljava/lang/String;", nullptr, $PROTECTED, $virtualMethod(ClassSpecializer$SpeciesData, deriveTypeString, $String*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ClassSpecializer$SpeciesData, equals, bool, Object$*)},
	{"factory", "()Ljava/lang/invoke/MethodHandle;", nullptr, $PROTECTED, $virtualMethod(ClassSpecializer$SpeciesData, factory, $MethodHandle*)},
	{"fieldCount", "()I", nullptr, $PROTECTED | $FINAL, $method(ClassSpecializer$SpeciesData, fieldCount, int32_t)},
	{"fieldTypes", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/Class<*>;>;", $PROTECTED | $FINAL, $method(ClassSpecializer$SpeciesData, fieldTypes, $List*)},
	{"getter", "(I)Ljava/lang/invoke/MethodHandle;", nullptr, $PROTECTED, $virtualMethod(ClassSpecializer$SpeciesData, getter, $MethodHandle*, int32_t)},
	{"getterFunction", "(I)Ljava/lang/invoke/LambdaForm$NamedFunction;", nullptr, $PROTECTED, $virtualMethod(ClassSpecializer$SpeciesData, getterFunction, $LambdaForm$NamedFunction*, int32_t)},
	{"getterFunctions", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/invoke/LambdaForm$NamedFunction;>;", $PROTECTED, $virtualMethod(ClassSpecializer$SpeciesData, getterFunctions, $List*)},
	{"getters", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/invoke/MethodHandle;>;", $PROTECTED, $virtualMethod(ClassSpecializer$SpeciesData, getters, $List*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(ClassSpecializer$SpeciesData, hashCode, int32_t)},
	{"isResolved", "()Z", nullptr, $PROTECTED | $FINAL, $method(ClassSpecializer$SpeciesData, isResolved, bool)},
	{"key", "()Ljava/lang/Object;", "()TK;", $PUBLIC | $FINAL, $method(ClassSpecializer$SpeciesData, key, $Object*)},
	{"outer", "()Ljava/lang/invoke/ClassSpecializer;", "()Ljava/lang/invoke/ClassSpecializer<TT;TK;TS;>;", $PROTECTED, $virtualMethod(ClassSpecializer$SpeciesData, outer, $ClassSpecializer*)},
	{"speciesCode", "()Ljava/lang/Class;", "()Ljava/lang/Class<+TT;>;", $PROTECTED | $FINAL, $method(ClassSpecializer$SpeciesData, speciesCode, $Class*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ClassSpecializer$SpeciesData, toString, $String*)},
	{"transformHelper", "(I)Ljava/lang/invoke/MethodHandle;", nullptr, $PROTECTED, $virtualMethod(ClassSpecializer$SpeciesData, transformHelper, $MethodHandle*, int32_t)},
	{"transformHelperType", "(I)Ljava/lang/invoke/MethodType;", nullptr, $PRIVATE | $FINAL, $method(ClassSpecializer$SpeciesData, transformHelperType, $MethodType*, int32_t)},
	{}
};

$InnerClassInfo _ClassSpecializer$SpeciesData_InnerClassesInfo_[] = {
	{"java.lang.invoke.ClassSpecializer$SpeciesData", "java.lang.invoke.ClassSpecializer", "SpeciesData", $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _ClassSpecializer$SpeciesData_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.lang.invoke.ClassSpecializer$SpeciesData",
	"java.lang.Object",
	nullptr,
	_ClassSpecializer$SpeciesData_FieldInfo_,
	_ClassSpecializer$SpeciesData_MethodInfo_,
	nullptr,
	nullptr,
	_ClassSpecializer$SpeciesData_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.invoke.ClassSpecializer"
};

$Object* allocate$ClassSpecializer$SpeciesData($Class* clazz) {
	return $of($alloc(ClassSpecializer$SpeciesData));
}

bool ClassSpecializer$SpeciesData::$assertionsDisabled = false;

void ClassSpecializer$SpeciesData::init$($ClassSpecializer* this$0, Object$* key) {
	$set(this, this$0, this$0);
	$set(this, transformHelpers, $new($MethodHandleArray, $nc(this->this$0->transformMethods$)->size()));
	$set(this, key$, $nc(this$0->keyType$)->cast($Objects::requireNonNull(key)));
	$var($List, types, deriveFieldTypes(key));
	$set(this, fieldTypes$, $List::copyOf(types));
}

$Object* ClassSpecializer$SpeciesData::key() {
	return $of(this->key$);
}

$List* ClassSpecializer$SpeciesData::fieldTypes() {
	return this->fieldTypes$;
}

int32_t ClassSpecializer$SpeciesData::fieldCount() {
	return $nc(this->fieldTypes$)->size();
}

$ClassSpecializer* ClassSpecializer$SpeciesData::outer() {
	return this->this$0;
}

bool ClassSpecializer$SpeciesData::isResolved() {
	return this->speciesCode$ != nullptr && this->factories != nullptr && !$nc(this->factories)->isEmpty();
}

$String* ClassSpecializer$SpeciesData::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$3, $$str({$($nc(this->this$0->metaType$)->getSimpleName()), "["_s}));
	$var($String, var$2, $$concat(var$3, $($nc($of(this->key$))->toString())));
	$var($String, var$1, $$concat(var$2, " => "_s));
	$var($String, var$0, $$concat(var$1, (isResolved() ? $($nc(this->speciesCode$)->getSimpleName()) : "UNRESOLVED"_s)));
	return $concat(var$0, "]"_s);
}

int32_t ClassSpecializer$SpeciesData::hashCode() {
	return $nc($of(this->key$))->hashCode();
}

bool ClassSpecializer$SpeciesData::equals(Object$* obj) {
	if (!($instanceOf(ClassSpecializer$SpeciesData, obj))) {
		return false;
	}
	$var(ClassSpecializer$SpeciesData, that, $cast(ClassSpecializer$SpeciesData, obj));
	bool var$0 = this->outer() == $nc(that)->outer();
	return var$0 && $nc($of(this->key$))->equals(that->key$);
}

$Class* ClassSpecializer$SpeciesData::speciesCode() {
	return $cast($Class, $Objects::requireNonNull(this->speciesCode$));
}

$MethodHandle* ClassSpecializer$SpeciesData::getter(int32_t i) {
	return $cast($MethodHandle, $nc(this->getters$)->get(i));
}

$LambdaForm$NamedFunction* ClassSpecializer$SpeciesData::getterFunction(int32_t i) {
	$useLocalCurrentObjectStackCache();
	$var($LambdaForm$NamedFunction, nf, $cast($LambdaForm$NamedFunction, $nc(this->nominalGetters)->get(i)));
	bool var$0 = !ClassSpecializer$SpeciesData::$assertionsDisabled;
	if (var$0) {
		var$0 = !($nc(nf)->memberDeclaringClassOrNull() == speciesCode());
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	bool var$1 = !ClassSpecializer$SpeciesData::$assertionsDisabled;
	if (var$1) {
		var$1 = !($nc(nf)->returnType() == $LambdaForm$BasicType::basicType($cast($Class, $($nc(this->fieldTypes$)->get(i)))));
	}
	if (var$1) {
		$throwNew($AssertionError);
	}
	return nf;
}

$List* ClassSpecializer$SpeciesData::getterFunctions() {
	return this->nominalGetters;
}

$List* ClassSpecializer$SpeciesData::getters() {
	return this->getters$;
}

$MethodHandle* ClassSpecializer$SpeciesData::factory() {
	return $cast($MethodHandle, $nc(this->factories)->get(0));
}

$MethodHandle* ClassSpecializer$SpeciesData::transformHelper(int32_t whichtm) {
	$useLocalCurrentObjectStackCache();
	$var($MethodHandle, mh, $nc(this->transformHelpers)->get(whichtm));
	if (mh != nullptr) {
		return mh;
	}
	$assign(mh, deriveTransformHelper($cast($MemberName, $($nc($(this->this$0->transformMethods()))->get(whichtm))), whichtm));
	$var($MethodType, mt, transformHelperType(whichtm));
	$assign(mh, $nc(mh)->asType(mt));
	return $nc(this->transformHelpers)->set(whichtm, mh);
}

$MethodType* ClassSpecializer$SpeciesData::transformHelperType(int32_t whichtm) {
	$useLocalCurrentObjectStackCache();
	$var($MemberName, tm, $cast($MemberName, $nc($(this->this$0->transformMethods()))->get(whichtm)));
	$var($ArrayList, args, $new($ArrayList));
	$var($ArrayList, fields, $new($ArrayList));
	$Collections::addAll(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>(args))), $($nc(tm)->getParameterTypes()));
	fields->addAll($(fieldTypes()));
	$var($List, helperArgs, deriveTransformHelperArguments(tm, whichtm, args, fields));
	return $MethodType::methodType($nc(tm)->getReturnType(), helperArgs);
}

$String* ClassSpecializer$SpeciesData::deriveClassName() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $$str({$($nc($nc($(outer()))->topClass())->getName()), "$Species_"_s}));
	return $concat(var$0, $(deriveTypeString()));
}

$String* ClassSpecializer$SpeciesData::deriveTypeString() {
	$useLocalCurrentObjectStackCache();
	$var($List, types, fieldTypes());
	$var($StringBuilder, buf, $new($StringBuilder));
	$var($StringBuilder, end, $new($StringBuilder));
	{
		$var($Iterator, i$, $nc(types)->iterator());
		for (; $nc(i$)->hasNext();) {
			$Class* type = $cast($Class, i$->next());
			{
				$LambdaForm$BasicType* basicType = $LambdaForm$BasicType::basicType(type);
				if ($nc(basicType)->basicTypeClass() == type) {
					buf->append(basicType->basicTypeChar());
				} else {
					buf->append(u'V');
					end->append($($ClassSpecializer::classSig(type)));
				}
			}
		}
	}
	$var($String, typeString, nullptr);
	if (end->length() > 0) {
		$assign(typeString, $BytecodeName::toBytecodeName($(buf->append("_"_s)->append(static_cast<$CharSequence*>(end))->toString())));
	} else {
		$assign(typeString, buf->toString());
	}
	return $LambdaForm::shortenSignature(typeString);
}

$Class* ClassSpecializer$SpeciesData::deriveSuperClass() {
	$useLocalCurrentObjectStackCache();
	$Class* topc = this->this$0->topClass();
	if (!this->this$0->topClassIsSuper) {
		try {
			$var($Constructor, con, $ClassSpecializer::reflectConstructor(topc, $($fcast($ClassArray, $nc($(this->this$0->baseConstructorType()))->parameterArray()))));
			bool var$0 = !$nc(topc)->isInterface();
			if (var$0 && !$Modifier::isPrivate($nc(con)->getModifiers())) {
				this->this$0->topClassIsSuper = true;
			}
		} catch ($Exception& ex) {
		} catch ($InternalError& ex) {
		}
		if (!this->this$0->topClassIsSuper) {
			$throw($($MethodHandleStatics::newInternalError("must override if the top class cannot serve as a super class"_s)));
		}
	}
	return topc;
}

void clinit$ClassSpecializer$SpeciesData($Class* class$) {
	$load($ClassSpecializer);
	ClassSpecializer$SpeciesData::$assertionsDisabled = !$ClassSpecializer::class$->desiredAssertionStatus();
}

ClassSpecializer$SpeciesData::ClassSpecializer$SpeciesData() {
}

$Class* ClassSpecializer$SpeciesData::load$($String* name, bool initialize) {
	$loadClass(ClassSpecializer$SpeciesData, name, initialize, &_ClassSpecializer$SpeciesData_ClassInfo_, clinit$ClassSpecializer$SpeciesData, allocate$ClassSpecializer$SpeciesData);
	return class$;
}

$Class* ClassSpecializer$SpeciesData::class$ = nullptr;

		} // invoke
	} // lang
} // java