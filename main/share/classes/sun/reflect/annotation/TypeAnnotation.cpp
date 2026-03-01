#include <sun/reflect/annotation/TypeAnnotation.h>

#include <java/lang/annotation/Annotation.h>
#include <java/lang/reflect/AnnotatedElement.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <sun/reflect/annotation/TypeAnnotation$LocationInfo.h>
#include <sun/reflect/annotation/TypeAnnotation$TypeAnnotationTarget.h>
#include <sun/reflect/annotation/TypeAnnotation$TypeAnnotationTargetInfo.h>
#include <jcpp.h>

using $TypeAnnotationArray = $Array<::sun::reflect::annotation::TypeAnnotation>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Annotation = ::java::lang::annotation::Annotation;
using $AnnotatedElement = ::java::lang::reflect::AnnotatedElement;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $TypeAnnotation$LocationInfo = ::sun::reflect::annotation::TypeAnnotation$LocationInfo;
using $TypeAnnotation$TypeAnnotationTarget = ::sun::reflect::annotation::TypeAnnotation$TypeAnnotationTarget;
using $TypeAnnotation$TypeAnnotationTargetInfo = ::sun::reflect::annotation::TypeAnnotation$TypeAnnotationTargetInfo;

namespace sun {
	namespace reflect {
		namespace annotation {

$FieldInfo _TypeAnnotation_FieldInfo_[] = {
	{"targetInfo", "Lsun/reflect/annotation/TypeAnnotation$TypeAnnotationTargetInfo;", nullptr, $PRIVATE | $FINAL, $field(TypeAnnotation, targetInfo)},
	{"loc", "Lsun/reflect/annotation/TypeAnnotation$LocationInfo;", nullptr, $PRIVATE | $FINAL, $field(TypeAnnotation, loc)},
	{"annotation", "Ljava/lang/annotation/Annotation;", nullptr, $PRIVATE | $FINAL, $field(TypeAnnotation, annotation)},
	{"baseDeclaration", "Ljava/lang/reflect/AnnotatedElement;", nullptr, $PRIVATE | $FINAL, $field(TypeAnnotation, baseDeclaration)},
	{}
};

$MethodInfo _TypeAnnotation_MethodInfo_[] = {
	{"<init>", "(Lsun/reflect/annotation/TypeAnnotation$TypeAnnotationTargetInfo;Lsun/reflect/annotation/TypeAnnotation$LocationInfo;Ljava/lang/annotation/Annotation;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $PUBLIC, $method(TypeAnnotation, init$, void, $TypeAnnotation$TypeAnnotationTargetInfo*, $TypeAnnotation$LocationInfo*, $Annotation*, $AnnotatedElement*)},
	{"filter", "([Lsun/reflect/annotation/TypeAnnotation;Lsun/reflect/annotation/TypeAnnotation$TypeAnnotationTarget;)Ljava/util/List;", "([Lsun/reflect/annotation/TypeAnnotation;Lsun/reflect/annotation/TypeAnnotation$TypeAnnotationTarget;)Ljava/util/List<Lsun/reflect/annotation/TypeAnnotation;>;", $PUBLIC | $STATIC, $staticMethod(TypeAnnotation, filter, $List*, $TypeAnnotationArray*, $TypeAnnotation$TypeAnnotationTarget*)},
	{"getAnnotation", "()Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC, $method(TypeAnnotation, getAnnotation, $Annotation*)},
	{"getBaseDeclaration", "()Ljava/lang/reflect/AnnotatedElement;", nullptr, $PUBLIC, $method(TypeAnnotation, getBaseDeclaration, $AnnotatedElement*)},
	{"getLocationInfo", "()Lsun/reflect/annotation/TypeAnnotation$LocationInfo;", nullptr, $PUBLIC, $method(TypeAnnotation, getLocationInfo, $TypeAnnotation$LocationInfo*)},
	{"getTargetInfo", "()Lsun/reflect/annotation/TypeAnnotation$TypeAnnotationTargetInfo;", nullptr, $PUBLIC, $method(TypeAnnotation, getTargetInfo, $TypeAnnotation$TypeAnnotationTargetInfo*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(TypeAnnotation, toString, $String*)},
	{}
};

$InnerClassInfo _TypeAnnotation_InnerClassesInfo_[] = {
	{"sun.reflect.annotation.TypeAnnotation$LocationInfo", "sun.reflect.annotation.TypeAnnotation", "LocationInfo", $PUBLIC | $STATIC | $FINAL},
	{"sun.reflect.annotation.TypeAnnotation$TypeAnnotationTargetInfo", "sun.reflect.annotation.TypeAnnotation", "TypeAnnotationTargetInfo", $PUBLIC | $STATIC | $FINAL},
	{"sun.reflect.annotation.TypeAnnotation$TypeAnnotationTarget", "sun.reflect.annotation.TypeAnnotation", "TypeAnnotationTarget", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _TypeAnnotation_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.reflect.annotation.TypeAnnotation",
	"java.lang.Object",
	nullptr,
	_TypeAnnotation_FieldInfo_,
	_TypeAnnotation_MethodInfo_,
	nullptr,
	nullptr,
	_TypeAnnotation_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.reflect.annotation.TypeAnnotation$LocationInfo,sun.reflect.annotation.TypeAnnotation$LocationInfo$Location,sun.reflect.annotation.TypeAnnotation$TypeAnnotationTargetInfo,sun.reflect.annotation.TypeAnnotation$TypeAnnotationTarget"
};

$Object* allocate$TypeAnnotation($Class* clazz) {
	return $of($alloc(TypeAnnotation));
}

void TypeAnnotation::init$($TypeAnnotation$TypeAnnotationTargetInfo* targetInfo, $TypeAnnotation$LocationInfo* loc, $Annotation* annotation, $AnnotatedElement* baseDeclaration) {
	$set(this, targetInfo, targetInfo);
	$set(this, loc, loc);
	$set(this, annotation, annotation);
	$set(this, baseDeclaration, baseDeclaration);
}

$TypeAnnotation$TypeAnnotationTargetInfo* TypeAnnotation::getTargetInfo() {
	return this->targetInfo;
}

$Annotation* TypeAnnotation::getAnnotation() {
	return this->annotation;
}

$AnnotatedElement* TypeAnnotation::getBaseDeclaration() {
	return this->baseDeclaration;
}

$TypeAnnotation$LocationInfo* TypeAnnotation::getLocationInfo() {
	return this->loc;
}

$List* TypeAnnotation::filter($TypeAnnotationArray* typeAnnotations, $TypeAnnotation$TypeAnnotationTarget* predicate) {
	$useLocalCurrentObjectStackCache();
	$var($ArrayList, typeAnnos, $new($ArrayList, $nc(typeAnnotations)->length));
	{
		$var($TypeAnnotationArray, arr$, typeAnnotations);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var(TypeAnnotation, t, arr$->get(i$));
			if ($nc($($nc(t)->getTargetInfo()))->getTarget() == predicate) {
				typeAnnos->add(t);
			}
		}
	}
	typeAnnos->trimToSize();
	return typeAnnos;
}

$String* TypeAnnotation::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$2, $$str({$($nc(this->annotation)->toString()), " with Targetnfo: "_s}));
	$var($String, var$1, $$concat(var$2, $($nc(this->targetInfo)->toString())));
	$var($String, var$0, $$concat(var$1, " on base declaration: "_s));
	return $concat(var$0, $($nc($of(this->baseDeclaration))->toString()));
}

TypeAnnotation::TypeAnnotation() {
}

$Class* TypeAnnotation::load$($String* name, bool initialize) {
	$loadClass(TypeAnnotation, name, initialize, &_TypeAnnotation_ClassInfo_, allocate$TypeAnnotation);
	return class$;
}

$Class* TypeAnnotation::class$ = nullptr;

		} // annotation
	} // reflect
} // sun