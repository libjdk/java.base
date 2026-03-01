#include <sun/reflect/annotation/AnnotatedTypeFactory$AnnotatedTypeBaseImpl.h>

#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/annotation/Annotation.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/AnnotatedArrayType.h>
#include <java/lang/reflect/AnnotatedElement.h>
#include <java/lang/reflect/AnnotatedParameterizedType.h>
#include <java/lang/reflect/AnnotatedType.h>
#include <java/lang/reflect/AnnotatedTypeVariable.h>
#include <java/lang/reflect/AnnotatedWildcardType.h>
#include <java/lang/reflect/Type.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/function/Function.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/Stream.h>
#include <sun/reflect/annotation/AnnotatedTypeFactory.h>
#include <sun/reflect/annotation/AnnotationSupport.h>
#include <sun/reflect/annotation/TypeAnnotation$LocationInfo.h>
#include <sun/reflect/annotation/TypeAnnotation.h>
#include <sun/reflect/annotation/TypeAnnotationParser.h>
#include <jcpp.h>

#undef BASE_LOCATION
#undef EMPTY_TYPE_ANNOTATION_ARRAY
#undef TYPE

using $AnnotationArray = $Array<::java::lang::annotation::Annotation>;
using $TypeAnnotationArray = $Array<::sun::reflect::annotation::TypeAnnotation>;
using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $Annotation = ::java::lang::annotation::Annotation;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AnnotatedArrayType = ::java::lang::reflect::AnnotatedArrayType;
using $AnnotatedElement = ::java::lang::reflect::AnnotatedElement;
using $AnnotatedParameterizedType = ::java::lang::reflect::AnnotatedParameterizedType;
using $AnnotatedType = ::java::lang::reflect::AnnotatedType;
using $AnnotatedTypeVariable = ::java::lang::reflect::AnnotatedTypeVariable;
using $AnnotatedWildcardType = ::java::lang::reflect::AnnotatedWildcardType;
using $Type = ::java::lang::reflect::Type;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Function = ::java::util::function::Function;
using $Collectors = ::java::util::stream::Collectors;
using $Stream = ::java::util::stream::Stream;
using $AnnotatedTypeFactory = ::sun::reflect::annotation::AnnotatedTypeFactory;
using $AnnotationSupport = ::sun::reflect::annotation::AnnotationSupport;
using $TypeAnnotation = ::sun::reflect::annotation::TypeAnnotation;
using $TypeAnnotation$LocationInfo = ::sun::reflect::annotation::TypeAnnotation$LocationInfo;
using $TypeAnnotationParser = ::sun::reflect::annotation::TypeAnnotationParser;

namespace sun {
	namespace reflect {
		namespace annotation {

class AnnotatedTypeFactory$AnnotatedTypeBaseImpl$$Lambda$toString : public $Function {
	$class(AnnotatedTypeFactory$AnnotatedTypeBaseImpl$$Lambda$toString, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($Annotation, inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<AnnotatedTypeFactory$AnnotatedTypeBaseImpl$$Lambda$toString>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo AnnotatedTypeFactory$AnnotatedTypeBaseImpl$$Lambda$toString::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(AnnotatedTypeFactory$AnnotatedTypeBaseImpl$$Lambda$toString, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(AnnotatedTypeFactory$AnnotatedTypeBaseImpl$$Lambda$toString, apply, $Object*, Object$*)},
	{}
};
$ClassInfo AnnotatedTypeFactory$AnnotatedTypeBaseImpl$$Lambda$toString::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.reflect.annotation.AnnotatedTypeFactory$AnnotatedTypeBaseImpl$$Lambda$toString",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* AnnotatedTypeFactory$AnnotatedTypeBaseImpl$$Lambda$toString::load$($String* name, bool initialize) {
	$loadClass(AnnotatedTypeFactory$AnnotatedTypeBaseImpl$$Lambda$toString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* AnnotatedTypeFactory$AnnotatedTypeBaseImpl$$Lambda$toString::class$ = nullptr;

$FieldInfo _AnnotatedTypeFactory$AnnotatedTypeBaseImpl_FieldInfo_[] = {
	{"type", "Ljava/lang/reflect/Type;", nullptr, $PRIVATE | $FINAL, $field(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, type)},
	{"decl", "Ljava/lang/reflect/AnnotatedElement;", nullptr, $PRIVATE | $FINAL, $field(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, decl)},
	{"location", "Lsun/reflect/annotation/TypeAnnotation$LocationInfo;", nullptr, $PRIVATE | $FINAL, $field(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, location)},
	{"allOnSameTargetTypeAnnotations", "[Lsun/reflect/annotation/TypeAnnotation;", nullptr, $PRIVATE | $FINAL, $field(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, allOnSameTargetTypeAnnotations)},
	{"annotations", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Class<+Ljava/lang/annotation/Annotation;>;Ljava/lang/annotation/Annotation;>;", $PRIVATE | $FINAL, $field(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, annotations)},
	{}
};

$MethodInfo _AnnotatedTypeFactory$AnnotatedTypeBaseImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/reflect/Type;Lsun/reflect/annotation/TypeAnnotation$LocationInfo;[Lsun/reflect/annotation/TypeAnnotation;[Lsun/reflect/annotation/TypeAnnotation;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, 0, $method(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, init$, void, $Type*, $TypeAnnotation$LocationInfo*, $TypeAnnotationArray*, $TypeAnnotationArray*, $AnnotatedElement*)},
	{"annotationsToString", "([Ljava/lang/annotation/Annotation;Z)Ljava/lang/String;", nullptr, $PROTECTED, $virtualMethod(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, annotationsToString, $String*, $AnnotationArray*, bool)},
	{"baseHashCode", "()I", nullptr, 0, $virtualMethod(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, baseHashCode, int32_t)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, equals, bool, Object$*)},
	{"equalsTypeAndAnnotations", "(Ljava/lang/reflect/AnnotatedType;)Z", nullptr, $PROTECTED, $virtualMethod(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, equalsTypeAndAnnotations, bool, $AnnotatedType*)},
	{"getAnnotatedOwnerType", "()Ljava/lang/reflect/AnnotatedType;", nullptr, $PUBLIC, $virtualMethod(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, getAnnotatedOwnerType, $AnnotatedType*)},
	{"getAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;", "<T::Ljava/lang/annotation/Annotation;>(Ljava/lang/Class<TT;>;)TT;", $PUBLIC | $FINAL, $virtualMethod(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, getAnnotation, $Annotation*, $Class*)},
	{"getAnnotations", "()[Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC | $FINAL, $virtualMethod(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, getAnnotations, $AnnotationArray*)},
	{"getAnnotationsByType", "(Ljava/lang/Class;)[Ljava/lang/annotation/Annotation;", "<T::Ljava/lang/annotation/Annotation;>(Ljava/lang/Class<TT;>;)[TT;", $PUBLIC | $FINAL, $virtualMethod(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, getAnnotationsByType, $AnnotationArray*, $Class*)},
	{"getDecl", "()Ljava/lang/reflect/AnnotatedElement;", nullptr, $FINAL, $method(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, getDecl, $AnnotatedElement*)},
	{"getDeclaredAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;", "<T::Ljava/lang/annotation/Annotation;>(Ljava/lang/Class<TT;>;)TT;", $PUBLIC | $FINAL, $virtualMethod(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, getDeclaredAnnotation, $Annotation*, $Class*)},
	{"getDeclaredAnnotations", "()[Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC | $FINAL, $virtualMethod(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, getDeclaredAnnotations, $AnnotationArray*)},
	{"getDeclaredAnnotationsByType", "(Ljava/lang/Class;)[Ljava/lang/annotation/Annotation;", "<T::Ljava/lang/annotation/Annotation;>(Ljava/lang/Class<TT;>;)[TT;", $PUBLIC | $FINAL, $virtualMethod(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, getDeclaredAnnotationsByType, $AnnotationArray*, $Class*)},
	{"getLocation", "()Lsun/reflect/annotation/TypeAnnotation$LocationInfo;", nullptr, $FINAL, $method(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, getLocation, $TypeAnnotation$LocationInfo*)},
	{"getType", "()Ljava/lang/reflect/Type;", nullptr, $PUBLIC | $FINAL, $virtualMethod(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, getType, $Type*)},
	{"getTypeAnnotations", "()[Lsun/reflect/annotation/TypeAnnotation;", nullptr, $FINAL, $method(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, getTypeAnnotations, $TypeAnnotationArray*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, hashCode, int32_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, toString, $String*)},
	{}
};

$InnerClassInfo _AnnotatedTypeFactory$AnnotatedTypeBaseImpl_InnerClassesInfo_[] = {
	{"sun.reflect.annotation.AnnotatedTypeFactory$AnnotatedTypeBaseImpl", "sun.reflect.annotation.AnnotatedTypeFactory", "AnnotatedTypeBaseImpl", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _AnnotatedTypeFactory$AnnotatedTypeBaseImpl_ClassInfo_ = {
	$ACC_SUPER,
	"sun.reflect.annotation.AnnotatedTypeFactory$AnnotatedTypeBaseImpl",
	"java.lang.Object",
	"java.lang.reflect.AnnotatedType",
	_AnnotatedTypeFactory$AnnotatedTypeBaseImpl_FieldInfo_,
	_AnnotatedTypeFactory$AnnotatedTypeBaseImpl_MethodInfo_,
	nullptr,
	nullptr,
	_AnnotatedTypeFactory$AnnotatedTypeBaseImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.reflect.annotation.AnnotatedTypeFactory"
};

$Object* allocate$AnnotatedTypeFactory$AnnotatedTypeBaseImpl($Class* clazz) {
	return $of($alloc(AnnotatedTypeFactory$AnnotatedTypeBaseImpl));
}

void AnnotatedTypeFactory$AnnotatedTypeBaseImpl::init$($Type* type, $TypeAnnotation$LocationInfo* location, $TypeAnnotationArray* actualTypeAnnotations, $TypeAnnotationArray* allOnSameTargetTypeAnnotations, $AnnotatedElement* decl) {
	$set(this, type, type);
	$set(this, decl, decl);
	$set(this, location, location);
	$set(this, allOnSameTargetTypeAnnotations, allOnSameTargetTypeAnnotations);
	$set(this, annotations, $TypeAnnotationParser::mapTypeAnnotations($($nc(location)->filter(actualTypeAnnotations))));
}

$AnnotationArray* AnnotatedTypeFactory$AnnotatedTypeBaseImpl::getAnnotations() {
	return getDeclaredAnnotations();
}

$Annotation* AnnotatedTypeFactory$AnnotatedTypeBaseImpl::getAnnotation($Class* annotation) {
	return getDeclaredAnnotation(annotation);
}

$AnnotationArray* AnnotatedTypeFactory$AnnotatedTypeBaseImpl::getAnnotationsByType($Class* annotation) {
	return getDeclaredAnnotationsByType(annotation);
}

$AnnotationArray* AnnotatedTypeFactory$AnnotatedTypeBaseImpl::getDeclaredAnnotations() {
	$useLocalCurrentObjectStackCache();
	return $fcast($AnnotationArray, $nc($($nc(this->annotations)->values()))->toArray($$new($AnnotationArray, 0)));
}

$Annotation* AnnotatedTypeFactory$AnnotatedTypeBaseImpl::getDeclaredAnnotation($Class* annotation) {
	return $cast($Annotation, $nc(this->annotations)->get(annotation));
}

$AnnotationArray* AnnotatedTypeFactory$AnnotatedTypeBaseImpl::getDeclaredAnnotationsByType($Class* annotation) {
	return $AnnotationSupport::getDirectlyAndIndirectlyPresent(this->annotations, annotation);
}

$Type* AnnotatedTypeFactory$AnnotatedTypeBaseImpl::getType() {
	return this->type;
}

$AnnotatedType* AnnotatedTypeFactory$AnnotatedTypeBaseImpl::getAnnotatedOwnerType() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (!($instanceOf($Class, this->type))) {
		$throwNew($IllegalStateException, "Can\'t compute owner"_s);
	}
	$Class* nested = $cast($Class, this->type);
	$Class* owner = $nc(nested)->getDeclaringClass();
	if (owner == nullptr) {
		return nullptr;
	}
	$init($Void);
	if (nested->isPrimitive() || nested == $Void::TYPE) {
		return nullptr;
	}
	$var($TypeAnnotation$LocationInfo, outerLoc, $nc($(getLocation()))->popLocation((int8_t)1));
	if (outerLoc == nullptr) {
		$init($AnnotatedTypeFactory);
		return $AnnotatedTypeFactory::buildAnnotatedType(owner, $TypeAnnotation$LocationInfo::BASE_LOCATION, $AnnotatedTypeFactory::EMPTY_TYPE_ANNOTATION_ARRAY, $AnnotatedTypeFactory::EMPTY_TYPE_ANNOTATION_ARRAY, $(getDecl()));
	}
	$var($TypeAnnotationArray, all, getTypeAnnotations());
	$var($List, l, $new($ArrayList, $nc(all)->length));
	{
		$var($TypeAnnotationArray, arr$, all);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($TypeAnnotation, t, arr$->get(i$));
			if ($nc($($nc(t)->getLocationInfo()))->isSameLocationInfo(outerLoc)) {
				l->add(t);
			}
		}
	}
	$var($Type, var$0, static_cast<$Type*>(owner));
	$var($TypeAnnotation$LocationInfo, var$1, outerLoc);
	$init($AnnotatedTypeFactory);
	$var($TypeAnnotationArray, var$2, $fcast($TypeAnnotationArray, l->toArray($AnnotatedTypeFactory::EMPTY_TYPE_ANNOTATION_ARRAY)));
	$var($TypeAnnotationArray, var$3, all);
	return $AnnotatedTypeFactory::buildAnnotatedType(var$0, var$1, var$2, var$3, $(getDecl()));
}

$String* AnnotatedTypeFactory$AnnotatedTypeBaseImpl::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $(annotationsToString($(getAnnotations()), false)));
	return $concat(var$0, (($instanceOf($Class, this->type)) ? $($nc(this->type)->getTypeName()) : $($nc($of(this->type))->toString())));
}

$String* AnnotatedTypeFactory$AnnotatedTypeBaseImpl::annotationsToString($AnnotationArray* annotations, bool leadingSpace) {
	$useLocalCurrentObjectStackCache();
	if (annotations != nullptr && annotations->length > 0) {
		$var($StringBuilder, sb, $new($StringBuilder));
		sb->append($cast($String, $($nc($($nc($($Stream::of(annotations)))->map(static_cast<$Function*>($$new(AnnotatedTypeFactory$AnnotatedTypeBaseImpl$$Lambda$toString)))))->collect($($Collectors::joining(" "_s))))));
		if (leadingSpace) {
			sb->insert(0, " "_s);
		} else {
			sb->append(" "_s);
		}
		return sb->toString();
	} else {
		return ""_s;
	}
}

bool AnnotatedTypeFactory$AnnotatedTypeBaseImpl::equalsTypeAndAnnotations($AnnotatedType* that) {
	$useLocalCurrentObjectStackCache();
	bool var$1 = $nc($of($(getType())))->equals($($nc(that)->getType()));
	if (var$1) {
		$var($ObjectArray, var$2, getAnnotations());
		var$1 = $Arrays::equals(var$2, $($nc(that)->getAnnotations()));
	}
	bool var$0 = var$1;
	if (var$0) {
		$var($Object, var$3, $of(getAnnotatedOwnerType()));
		var$0 = $Objects::equals(var$3, $($nc(that)->getAnnotatedOwnerType()));
	}
	return var$0;
}

int32_t AnnotatedTypeFactory$AnnotatedTypeBaseImpl::baseHashCode() {
	$useLocalCurrentObjectStackCache();
	int32_t var$1 = $nc($of(this->type))->hashCode();
	int32_t var$0 = var$1 ^ $Objects::hash($(getAnnotations()));
	return var$0 ^ $Objects::hash($$new($ObjectArray, {$($of(getAnnotatedOwnerType()))}));
}

bool AnnotatedTypeFactory$AnnotatedTypeBaseImpl::equals(Object$* o) {
	if ($instanceOf($AnnotatedType, o) && !($instanceOf($AnnotatedArrayType, o)) && !($instanceOf($AnnotatedTypeVariable, o)) && !($instanceOf($AnnotatedParameterizedType, o)) && !($instanceOf($AnnotatedWildcardType, o))) {
		$var($AnnotatedType, that, $cast($AnnotatedType, o));
		return equalsTypeAndAnnotations(that);
	} else {
		return false;
	}
}

int32_t AnnotatedTypeFactory$AnnotatedTypeBaseImpl::hashCode() {
	return baseHashCode();
}

$TypeAnnotation$LocationInfo* AnnotatedTypeFactory$AnnotatedTypeBaseImpl::getLocation() {
	return this->location;
}

$TypeAnnotationArray* AnnotatedTypeFactory$AnnotatedTypeBaseImpl::getTypeAnnotations() {
	return this->allOnSameTargetTypeAnnotations;
}

$AnnotatedElement* AnnotatedTypeFactory$AnnotatedTypeBaseImpl::getDecl() {
	return this->decl;
}

AnnotatedTypeFactory$AnnotatedTypeBaseImpl::AnnotatedTypeFactory$AnnotatedTypeBaseImpl() {
}

$Class* AnnotatedTypeFactory$AnnotatedTypeBaseImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(AnnotatedTypeFactory$AnnotatedTypeBaseImpl$$Lambda$toString::classInfo$.name)) {
			return AnnotatedTypeFactory$AnnotatedTypeBaseImpl$$Lambda$toString::load$(name, initialize);
		}
	}
	$loadClass(AnnotatedTypeFactory$AnnotatedTypeBaseImpl, name, initialize, &_AnnotatedTypeFactory$AnnotatedTypeBaseImpl_ClassInfo_, allocate$AnnotatedTypeFactory$AnnotatedTypeBaseImpl);
	return class$;
}

$Class* AnnotatedTypeFactory$AnnotatedTypeBaseImpl::class$ = nullptr;

		} // annotation
	} // reflect
} // sun