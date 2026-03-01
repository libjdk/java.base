#include <sun/reflect/annotation/AnnotatedTypeFactory$AnnotatedWildcardTypeImpl.h>

#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/annotation/Annotation.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/AnnotatedElement.h>
#include <java/lang/reflect/AnnotatedType.h>
#include <java/lang/reflect/AnnotatedWildcardType.h>
#include <java/lang/reflect/Type.h>
#include <java/lang/reflect/WildcardType.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/function/Function.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/Stream.h>
#include <sun/reflect/annotation/AnnotatedTypeFactory$AnnotatedTypeBaseImpl.h>
#include <sun/reflect/annotation/AnnotatedTypeFactory.h>
#include <sun/reflect/annotation/TypeAnnotation$LocationInfo.h>
#include <sun/reflect/annotation/TypeAnnotation.h>
#include <jcpp.h>

#undef BASE_LOCATION
#undef EMPTY_ANNOTATED_TYPE
#undef EMPTY_TYPE_ANNOTATION_ARRAY

using $AnnotationArray = $Array<::java::lang::annotation::Annotation>;
using $AnnotatedTypeArray = $Array<::java::lang::reflect::AnnotatedType>;
using $TypeArray = $Array<::java::lang::reflect::Type>;
using $TypeAnnotationArray = $Array<::sun::reflect::annotation::TypeAnnotation>;
using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Annotation = ::java::lang::annotation::Annotation;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AnnotatedElement = ::java::lang::reflect::AnnotatedElement;
using $AnnotatedType = ::java::lang::reflect::AnnotatedType;
using $AnnotatedWildcardType = ::java::lang::reflect::AnnotatedWildcardType;
using $Type = ::java::lang::reflect::Type;
using $WildcardType = ::java::lang::reflect::WildcardType;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Function = ::java::util::function::Function;
using $Collectors = ::java::util::stream::Collectors;
using $Stream = ::java::util::stream::Stream;
using $AnnotatedTypeFactory = ::sun::reflect::annotation::AnnotatedTypeFactory;
using $AnnotatedTypeFactory$AnnotatedTypeBaseImpl = ::sun::reflect::annotation::AnnotatedTypeFactory$AnnotatedTypeBaseImpl;
using $TypeAnnotation = ::sun::reflect::annotation::TypeAnnotation;
using $TypeAnnotation$LocationInfo = ::sun::reflect::annotation::TypeAnnotation$LocationInfo;

namespace sun {
	namespace reflect {
		namespace annotation {

class AnnotatedTypeFactory$AnnotatedWildcardTypeImpl$$Lambda$toString : public $Function {
	$class(AnnotatedTypeFactory$AnnotatedWildcardTypeImpl$$Lambda$toString, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($of($nc(inst$))->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<AnnotatedTypeFactory$AnnotatedWildcardTypeImpl$$Lambda$toString>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo AnnotatedTypeFactory$AnnotatedWildcardTypeImpl$$Lambda$toString::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(AnnotatedTypeFactory$AnnotatedWildcardTypeImpl$$Lambda$toString, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(AnnotatedTypeFactory$AnnotatedWildcardTypeImpl$$Lambda$toString, apply, $Object*, Object$*)},
	{}
};
$ClassInfo AnnotatedTypeFactory$AnnotatedWildcardTypeImpl$$Lambda$toString::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.reflect.annotation.AnnotatedTypeFactory$AnnotatedWildcardTypeImpl$$Lambda$toString",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* AnnotatedTypeFactory$AnnotatedWildcardTypeImpl$$Lambda$toString::load$($String* name, bool initialize) {
	$loadClass(AnnotatedTypeFactory$AnnotatedWildcardTypeImpl$$Lambda$toString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* AnnotatedTypeFactory$AnnotatedWildcardTypeImpl$$Lambda$toString::class$ = nullptr;

$FieldInfo _AnnotatedTypeFactory$AnnotatedWildcardTypeImpl_FieldInfo_[] = {
	{"hasUpperBounds", "Z", nullptr, $PRIVATE | $FINAL, $field(AnnotatedTypeFactory$AnnotatedWildcardTypeImpl, hasUpperBounds$)},
	{}
};

$MethodInfo _AnnotatedTypeFactory$AnnotatedWildcardTypeImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*getAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC | $FINAL},
	{"*getAnnotations", "()[Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC | $FINAL},
	{"*getAnnotationsByType", "(Ljava/lang/Class;)[Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC | $FINAL},
	{"*getDeclaredAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC | $FINAL},
	{"*getDeclaredAnnotations", "()[Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC | $FINAL},
	{"*getDeclaredAnnotationsByType", "(Ljava/lang/Class;)[Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC | $FINAL},
	{"*getType", "()Ljava/lang/reflect/Type;", nullptr, $PUBLIC | $FINAL},
	{"<init>", "(Ljava/lang/reflect/WildcardType;Lsun/reflect/annotation/TypeAnnotation$LocationInfo;[Lsun/reflect/annotation/TypeAnnotation;[Lsun/reflect/annotation/TypeAnnotation;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, 0, $method(AnnotatedTypeFactory$AnnotatedWildcardTypeImpl, init$, void, $WildcardType*, $TypeAnnotation$LocationInfo*, $TypeAnnotationArray*, $TypeAnnotationArray*, $AnnotatedElement*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(AnnotatedTypeFactory$AnnotatedWildcardTypeImpl, equals, bool, Object$*)},
	{"getAnnotatedBounds", "([Ljava/lang/reflect/Type;)[Ljava/lang/reflect/AnnotatedType;", nullptr, $PRIVATE, $method(AnnotatedTypeFactory$AnnotatedWildcardTypeImpl, getAnnotatedBounds, $AnnotatedTypeArray*, $TypeArray*)},
	{"getAnnotatedLowerBounds", "()[Ljava/lang/reflect/AnnotatedType;", nullptr, $PUBLIC, $virtualMethod(AnnotatedTypeFactory$AnnotatedWildcardTypeImpl, getAnnotatedLowerBounds, $AnnotatedTypeArray*)},
	{"getAnnotatedOwnerType", "()Ljava/lang/reflect/AnnotatedType;", nullptr, $PUBLIC, $virtualMethod(AnnotatedTypeFactory$AnnotatedWildcardTypeImpl, getAnnotatedOwnerType, $AnnotatedType*)},
	{"getAnnotatedUpperBounds", "()[Ljava/lang/reflect/AnnotatedType;", nullptr, $PUBLIC, $virtualMethod(AnnotatedTypeFactory$AnnotatedWildcardTypeImpl, getAnnotatedUpperBounds, $AnnotatedTypeArray*)},
	{"getWildcardType", "()Ljava/lang/reflect/WildcardType;", nullptr, $PRIVATE, $method(AnnotatedTypeFactory$AnnotatedWildcardTypeImpl, getWildcardType, $WildcardType*)},
	{"hasUpperBounds", "()Z", nullptr, $PRIVATE, $method(AnnotatedTypeFactory$AnnotatedWildcardTypeImpl, hasUpperBounds, bool)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(AnnotatedTypeFactory$AnnotatedWildcardTypeImpl, hashCode, int32_t)},
	{"*isAnnotationPresent", "(Ljava/lang/Class;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(AnnotatedTypeFactory$AnnotatedWildcardTypeImpl, toString, $String*)},
	{}
};

$InnerClassInfo _AnnotatedTypeFactory$AnnotatedWildcardTypeImpl_InnerClassesInfo_[] = {
	{"sun.reflect.annotation.AnnotatedTypeFactory$AnnotatedWildcardTypeImpl", "sun.reflect.annotation.AnnotatedTypeFactory", "AnnotatedWildcardTypeImpl", $PRIVATE | $STATIC | $FINAL},
	{"sun.reflect.annotation.AnnotatedTypeFactory$AnnotatedTypeBaseImpl", "sun.reflect.annotation.AnnotatedTypeFactory", "AnnotatedTypeBaseImpl", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _AnnotatedTypeFactory$AnnotatedWildcardTypeImpl_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.reflect.annotation.AnnotatedTypeFactory$AnnotatedWildcardTypeImpl",
	"sun.reflect.annotation.AnnotatedTypeFactory$AnnotatedTypeBaseImpl",
	"java.lang.reflect.AnnotatedWildcardType",
	_AnnotatedTypeFactory$AnnotatedWildcardTypeImpl_FieldInfo_,
	_AnnotatedTypeFactory$AnnotatedWildcardTypeImpl_MethodInfo_,
	nullptr,
	nullptr,
	_AnnotatedTypeFactory$AnnotatedWildcardTypeImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.reflect.annotation.AnnotatedTypeFactory"
};

$Object* allocate$AnnotatedTypeFactory$AnnotatedWildcardTypeImpl($Class* clazz) {
	return $of($alloc(AnnotatedTypeFactory$AnnotatedWildcardTypeImpl));
}

$AnnotationArray* AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::getAnnotations() {
	 return this->$AnnotatedTypeFactory$AnnotatedTypeBaseImpl::getAnnotations();
}

$Annotation* AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::getAnnotation($Class* annotation) {
	 return this->$AnnotatedTypeFactory$AnnotatedTypeBaseImpl::getAnnotation(annotation);
}

$AnnotationArray* AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::getAnnotationsByType($Class* annotation) {
	 return this->$AnnotatedTypeFactory$AnnotatedTypeBaseImpl::getAnnotationsByType(annotation);
}

$AnnotationArray* AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::getDeclaredAnnotations() {
	 return this->$AnnotatedTypeFactory$AnnotatedTypeBaseImpl::getDeclaredAnnotations();
}

$Annotation* AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::getDeclaredAnnotation($Class* annotation) {
	 return this->$AnnotatedTypeFactory$AnnotatedTypeBaseImpl::getDeclaredAnnotation(annotation);
}

$AnnotationArray* AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::getDeclaredAnnotationsByType($Class* annotation) {
	 return this->$AnnotatedTypeFactory$AnnotatedTypeBaseImpl::getDeclaredAnnotationsByType(annotation);
}

$Type* AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::getType() {
	 return this->$AnnotatedTypeFactory$AnnotatedTypeBaseImpl::getType();
}

bool AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::isAnnotationPresent($Class* annotationClass) {
	 return this->$AnnotatedTypeFactory$AnnotatedTypeBaseImpl::isAnnotationPresent(annotationClass);
}

$Object* AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::clone() {
	 return this->$AnnotatedTypeFactory$AnnotatedTypeBaseImpl::clone();
}

void AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::finalize() {
	this->$AnnotatedTypeFactory$AnnotatedTypeBaseImpl::finalize();
}

void AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::init$($WildcardType* type, $TypeAnnotation$LocationInfo* location, $TypeAnnotationArray* actualTypeAnnotations, $TypeAnnotationArray* allOnSameTargetTypeAnnotations, $AnnotatedElement* decl) {
	$AnnotatedTypeFactory$AnnotatedTypeBaseImpl::init$(type, location, actualTypeAnnotations, allOnSameTargetTypeAnnotations, decl);
	this->hasUpperBounds$ = ($nc($($nc(type)->getLowerBounds()))->length == 0);
}

$AnnotatedTypeArray* AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::getAnnotatedUpperBounds() {
	$useLocalCurrentObjectStackCache();
	if (!hasUpperBounds()) {
		$init($TypeAnnotation$LocationInfo);
		$init($AnnotatedTypeFactory);
		return $new($AnnotatedTypeArray, {$($AnnotatedTypeFactory::buildAnnotatedType($Object::class$, $TypeAnnotation$LocationInfo::BASE_LOCATION, $AnnotatedTypeFactory::EMPTY_TYPE_ANNOTATION_ARRAY, $AnnotatedTypeFactory::EMPTY_TYPE_ANNOTATION_ARRAY, nullptr))});
	}
	return getAnnotatedBounds($($nc($(getWildcardType()))->getUpperBounds()));
}

$AnnotatedTypeArray* AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::getAnnotatedLowerBounds() {
	$useLocalCurrentObjectStackCache();
	if (this->hasUpperBounds$) {
		return $new($AnnotatedTypeArray, 0);
	}
	return getAnnotatedBounds($($nc($(getWildcardType()))->getLowerBounds()));
}

$AnnotatedType* AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::getAnnotatedOwnerType() {
	return nullptr;
}

$AnnotatedTypeArray* AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::getAnnotatedBounds($TypeArray* bounds) {
	$useLocalCurrentObjectStackCache();
	$var($AnnotatedTypeArray, res, $new($AnnotatedTypeArray, $nc(bounds)->length));
	$init($AnnotatedTypeFactory);
	$Arrays::fill(res, $of($AnnotatedTypeFactory::EMPTY_ANNOTATED_TYPE));
	int32_t initialCapacity = $nc($(getTypeAnnotations()))->length;
	for (int32_t i = 0; i < res->length; ++i) {
		$var($TypeAnnotation$LocationInfo, newLoc, $AnnotatedTypeFactory::nestingForType(bounds->get(i), $($nc($(getLocation()))->pushWildcard())));
		$var($List, l, $new($ArrayList, initialCapacity));
		{
			$var($TypeAnnotationArray, arr$, getTypeAnnotations());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($TypeAnnotation, t, arr$->get(i$));
				if ($nc($($nc(t)->getLocationInfo()))->isSameLocationInfo(newLoc)) {
					l->add(t);
				}
			}
		}
		$var($Type, var$0, bounds->get(i));
		$var($TypeAnnotation$LocationInfo, var$1, newLoc);
		$var($TypeAnnotationArray, var$2, $fcast($TypeAnnotationArray, l->toArray($AnnotatedTypeFactory::EMPTY_TYPE_ANNOTATION_ARRAY)));
		$var($TypeAnnotationArray, var$3, getTypeAnnotations());
		res->set(i, $($AnnotatedTypeFactory::buildAnnotatedType(var$0, var$1, var$2, var$3, $(getDecl()))));
	}
	return res;
}

$WildcardType* AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::getWildcardType() {
	return $cast($WildcardType, getType());
}

bool AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::hasUpperBounds() {
	return this->hasUpperBounds$;
}

$String* AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append($(annotationsToString($(getAnnotations()), false)));
	sb->append("?"_s);
	$var($AnnotatedTypeArray, bounds, getAnnotatedLowerBounds());
	if ($nc(bounds)->length > 0) {
		sb->append(" super "_s);
	} else {
		$assign(bounds, getAnnotatedUpperBounds());
		if ($nc(bounds)->length > 0) {
			if (bounds->length == 1) {
				$var($AnnotatedType, bound, bounds->get(0));
				bool var$0 = $nc($of($($nc(bound)->getType())))->equals($Object::class$);
				if (var$0 && $nc($(bound->getAnnotations()))->length == 0) {
					return sb->toString();
				}
			}
			sb->append(" extends "_s);
		}
	}
	sb->append($cast($String, $($nc($($nc($($Stream::of(bounds)))->map(static_cast<$Function*>($$new(AnnotatedTypeFactory$AnnotatedWildcardTypeImpl$$Lambda$toString)))))->collect($($Collectors::joining(" & "_s))))));
	return sb->toString();
}

bool AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::equals(Object$* o) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($AnnotatedWildcardType, o)) {
		$var($AnnotatedWildcardType, that, $cast($AnnotatedWildcardType, o));
		bool var$1 = equalsTypeAndAnnotations(that);
		if (var$1) {
			$var($ObjectArray, var$2, getAnnotatedLowerBounds());
			var$1 = $Arrays::equals(var$2, $($nc(that)->getAnnotatedLowerBounds()));
		}
		bool var$0 = var$1;
		if (var$0) {
			$var($ObjectArray, var$3, getAnnotatedUpperBounds());
			var$0 = $Arrays::equals(var$3, $($nc(that)->getAnnotatedUpperBounds()));
		}
		return var$0;
	} else {
		return false;
	}
}

int32_t AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::hashCode() {
	$useLocalCurrentObjectStackCache();
	int32_t var$1 = baseHashCode();
	int32_t var$0 = var$1 ^ $Objects::hash($(getAnnotatedLowerBounds()));
	return var$0 ^ $Objects::hash($(getAnnotatedUpperBounds()));
}

AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::AnnotatedTypeFactory$AnnotatedWildcardTypeImpl() {
}

$Class* AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(AnnotatedTypeFactory$AnnotatedWildcardTypeImpl$$Lambda$toString::classInfo$.name)) {
			return AnnotatedTypeFactory$AnnotatedWildcardTypeImpl$$Lambda$toString::load$(name, initialize);
		}
	}
	$loadClass(AnnotatedTypeFactory$AnnotatedWildcardTypeImpl, name, initialize, &_AnnotatedTypeFactory$AnnotatedWildcardTypeImpl_ClassInfo_, allocate$AnnotatedTypeFactory$AnnotatedWildcardTypeImpl);
	return class$;
}

$Class* AnnotatedTypeFactory$AnnotatedWildcardTypeImpl::class$ = nullptr;

		} // annotation
	} // reflect
} // sun