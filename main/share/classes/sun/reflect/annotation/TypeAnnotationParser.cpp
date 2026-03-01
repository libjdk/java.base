#include <sun/reflect/annotation/TypeAnnotationParser.h>

#include <java/lang/AssertionError.h>
#include <java/lang/annotation/Annotation.h>
#include <java/lang/annotation/AnnotationFormatError.h>
#include <java/lang/annotation/RetentionPolicy.h>
#include <java/lang/reflect/AccessibleObject.h>
#include <java/lang/reflect/AnnotatedElement.h>
#include <java/lang/reflect/AnnotatedType.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Executable.h>
#include <java/lang/reflect/GenericDeclaration.h>
#include <java/lang/reflect/Modifier.h>
#include <java/lang/reflect/ParameterizedType.h>
#include <java/lang/reflect/Type.h>
#include <java/nio/BufferUnderflowException.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashMap.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/reflect/ConstantPool.h>
#include <sun/reflect/annotation/AnnotatedTypeFactory.h>
#include <sun/reflect/annotation/AnnotationParser.h>
#include <sun/reflect/annotation/AnnotationType.h>
#include <sun/reflect/annotation/TypeAnnotation$LocationInfo.h>
#include <sun/reflect/annotation/TypeAnnotation$TypeAnnotationTarget.h>
#include <sun/reflect/annotation/TypeAnnotation$TypeAnnotationTargetInfo.h>
#include <sun/reflect/annotation/TypeAnnotation.h>
#include <jcpp.h>

#undef BASE_LOCATION
#undef CAST
#undef CLASS_EXTENDS
#undef CLASS_IMPLEMENTS
#undef CLASS_TYPE_PARAMETER
#undef CLASS_TYPE_PARAMETER_BOUND
#undef CONSTRUCTOR_INVOCATION_TYPE_ARGUMENT
#undef CONSTRUCTOR_REFERENCE
#undef CONSTRUCTOR_REFERENCE_TYPE_ARGUMENT
#undef EMPTY_ANNOTATED_TYPE
#undef EMPTY_ANNOTATED_TYPE_ARRAY
#undef EMPTY_TYPE_ANNOTATION_ARRAY
#undef EXCEPTION_PARAMETER
#undef FIELD
#undef INSTANCEOF
#undef LOCAL_VARIABLE
#undef METHOD_FORMAL_PARAMETER
#undef METHOD_INVOCATION_TYPE_ARGUMENT
#undef METHOD_RECEIVER
#undef METHOD_REFERENCE
#undef METHOD_REFERENCE_TYPE_ARGUMENT
#undef METHOD_RETURN
#undef METHOD_TYPE_PARAMETER
#undef METHOD_TYPE_PARAMETER_BOUND
#undef NEW
#undef RESOURCE_VARIABLE
#undef RUNTIME
#undef STATIC
#undef THROWS
#undef TYPE

using $AnnotationArray = $Array<::java::lang::annotation::Annotation>;
using $AnnotatedTypeArray = $Array<::java::lang::reflect::AnnotatedType>;
using $TypeArray = $Array<::java::lang::reflect::Type>;
using $ArrayListArray = $Array<::java::util::ArrayList>;
using $TypeAnnotationArray = $Array<::sun::reflect::annotation::TypeAnnotation>;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Void = ::java::lang::Void;
using $Annotation = ::java::lang::annotation::Annotation;
using $AnnotationFormatError = ::java::lang::annotation::AnnotationFormatError;
using $RetentionPolicy = ::java::lang::annotation::RetentionPolicy;
using $AccessibleObject = ::java::lang::reflect::AccessibleObject;
using $AnnotatedElement = ::java::lang::reflect::AnnotatedElement;
using $AnnotatedType = ::java::lang::reflect::AnnotatedType;
using $Constructor = ::java::lang::reflect::Constructor;
using $Executable = ::java::lang::reflect::Executable;
using $GenericDeclaration = ::java::lang::reflect::GenericDeclaration;
using $Modifier = ::java::lang::reflect::Modifier;
using $ParameterizedType = ::java::lang::reflect::ParameterizedType;
using $Type = ::java::lang::reflect::Type;
using $BufferUnderflowException = ::java::nio::BufferUnderflowException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Iterator = ::java::util::Iterator;
using $LinkedHashMap = ::java::util::LinkedHashMap;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $ConstantPool = ::jdk::internal::reflect::ConstantPool;
using $AnnotatedTypeFactory = ::sun::reflect::annotation::AnnotatedTypeFactory;
using $AnnotationParser = ::sun::reflect::annotation::AnnotationParser;
using $AnnotationType = ::sun::reflect::annotation::AnnotationType;
using $TypeAnnotation = ::sun::reflect::annotation::TypeAnnotation;
using $TypeAnnotation$LocationInfo = ::sun::reflect::annotation::TypeAnnotation$LocationInfo;
using $TypeAnnotation$TypeAnnotationTarget = ::sun::reflect::annotation::TypeAnnotation$TypeAnnotationTarget;
using $TypeAnnotation$TypeAnnotationTargetInfo = ::sun::reflect::annotation::TypeAnnotation$TypeAnnotationTargetInfo;

namespace sun {
	namespace reflect {
		namespace annotation {

$FieldInfo _TypeAnnotationParser_FieldInfo_[] = {
	{"EMPTY_TYPE_ANNOTATION_ARRAY", "[Lsun/reflect/annotation/TypeAnnotation;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TypeAnnotationParser, EMPTY_TYPE_ANNOTATION_ARRAY)},
	{"CLASS_TYPE_PARAMETER", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, CLASS_TYPE_PARAMETER)},
	{"METHOD_TYPE_PARAMETER", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, METHOD_TYPE_PARAMETER)},
	{"CLASS_EXTENDS", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, CLASS_EXTENDS)},
	{"CLASS_TYPE_PARAMETER_BOUND", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, CLASS_TYPE_PARAMETER_BOUND)},
	{"METHOD_TYPE_PARAMETER_BOUND", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, METHOD_TYPE_PARAMETER_BOUND)},
	{"FIELD", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, FIELD)},
	{"METHOD_RETURN", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, METHOD_RETURN)},
	{"METHOD_RECEIVER", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, METHOD_RECEIVER)},
	{"METHOD_FORMAL_PARAMETER", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, METHOD_FORMAL_PARAMETER)},
	{"THROWS", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, THROWS)},
	{"LOCAL_VARIABLE", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, LOCAL_VARIABLE)},
	{"RESOURCE_VARIABLE", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, RESOURCE_VARIABLE)},
	{"EXCEPTION_PARAMETER", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, EXCEPTION_PARAMETER)},
	{"INSTANCEOF", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, INSTANCEOF)},
	{"NEW", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, NEW)},
	{"CONSTRUCTOR_REFERENCE", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, CONSTRUCTOR_REFERENCE)},
	{"METHOD_REFERENCE", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, METHOD_REFERENCE)},
	{"CAST", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, CAST)},
	{"CONSTRUCTOR_INVOCATION_TYPE_ARGUMENT", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, CONSTRUCTOR_INVOCATION_TYPE_ARGUMENT)},
	{"METHOD_INVOCATION_TYPE_ARGUMENT", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, METHOD_INVOCATION_TYPE_ARGUMENT)},
	{"CONSTRUCTOR_REFERENCE_TYPE_ARGUMENT", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, CONSTRUCTOR_REFERENCE_TYPE_ARGUMENT)},
	{"METHOD_REFERENCE_TYPE_ARGUMENT", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TypeAnnotationParser, METHOD_REFERENCE_TYPE_ARGUMENT)},
	{}
};

$MethodInfo _TypeAnnotationParser_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(TypeAnnotationParser, init$, void)},
	{"buildAnnotatedInterfaces", "([BLjdk/internal/reflect/ConstantPool;Ljava/lang/Class;)[Ljava/lang/reflect/AnnotatedType;", "([BLjdk/internal/reflect/ConstantPool;Ljava/lang/Class<*>;)[Ljava/lang/reflect/AnnotatedType;", $PUBLIC | $STATIC, $staticMethod(TypeAnnotationParser, buildAnnotatedInterfaces, $AnnotatedTypeArray*, $bytes*, $ConstantPool*, $Class*)},
	{"buildAnnotatedSuperclass", "([BLjdk/internal/reflect/ConstantPool;Ljava/lang/Class;)Ljava/lang/reflect/AnnotatedType;", "([BLjdk/internal/reflect/ConstantPool;Ljava/lang/Class<*>;)Ljava/lang/reflect/AnnotatedType;", $PUBLIC | $STATIC, $staticMethod(TypeAnnotationParser, buildAnnotatedSuperclass, $AnnotatedType*, $bytes*, $ConstantPool*, $Class*)},
	{"buildAnnotatedType", "([BLjdk/internal/reflect/ConstantPool;Ljava/lang/reflect/AnnotatedElement;Ljava/lang/Class;Ljava/lang/reflect/Type;Lsun/reflect/annotation/TypeAnnotation$TypeAnnotationTarget;)Ljava/lang/reflect/AnnotatedType;", "([BLjdk/internal/reflect/ConstantPool;Ljava/lang/reflect/AnnotatedElement;Ljava/lang/Class<*>;Ljava/lang/reflect/Type;Lsun/reflect/annotation/TypeAnnotation$TypeAnnotationTarget;)Ljava/lang/reflect/AnnotatedType;", $PUBLIC | $STATIC, $staticMethod(TypeAnnotationParser, buildAnnotatedType, $AnnotatedType*, $bytes*, $ConstantPool*, $AnnotatedElement*, $Class*, $Type*, $TypeAnnotation$TypeAnnotationTarget*)},
	{"buildAnnotatedTypes", "([BLjdk/internal/reflect/ConstantPool;Ljava/lang/reflect/AnnotatedElement;Ljava/lang/Class;[Ljava/lang/reflect/Type;Lsun/reflect/annotation/TypeAnnotation$TypeAnnotationTarget;)[Ljava/lang/reflect/AnnotatedType;", "([BLjdk/internal/reflect/ConstantPool;Ljava/lang/reflect/AnnotatedElement;Ljava/lang/Class<*>;[Ljava/lang/reflect/Type;Lsun/reflect/annotation/TypeAnnotation$TypeAnnotationTarget;)[Ljava/lang/reflect/AnnotatedType;", $PUBLIC | $STATIC, $staticMethod(TypeAnnotationParser, buildAnnotatedTypes, $AnnotatedTypeArray*, $bytes*, $ConstantPool*, $AnnotatedElement*, $Class*, $TypeArray*, $TypeAnnotation$TypeAnnotationTarget*)},
	{"fetchBounds", "(Ljava/lang/reflect/GenericDeclaration;)Ljava/util/List;", "<D::Ljava/lang/reflect/GenericDeclaration;>(TD;)Ljava/util/List<Lsun/reflect/annotation/TypeAnnotation;>;", $PRIVATE | $STATIC, $staticMethod(TypeAnnotationParser, fetchBounds, $List*, $GenericDeclaration*)},
	{"mapTypeAnnotations", "([Lsun/reflect/annotation/TypeAnnotation;)Ljava/util/Map;", "([Lsun/reflect/annotation/TypeAnnotation;)Ljava/util/Map<Ljava/lang/Class<+Ljava/lang/annotation/Annotation;>;Ljava/lang/annotation/Annotation;>;", $STATIC, $staticMethod(TypeAnnotationParser, mapTypeAnnotations, $Map*, $TypeAnnotationArray*)},
	{"parse2ByteTarget", "(Lsun/reflect/annotation/TypeAnnotation$TypeAnnotationTarget;Ljava/nio/ByteBuffer;)Lsun/reflect/annotation/TypeAnnotation$TypeAnnotationTargetInfo;", nullptr, $PRIVATE | $STATIC, $staticMethod(TypeAnnotationParser, parse2ByteTarget, $TypeAnnotation$TypeAnnotationTargetInfo*, $TypeAnnotation$TypeAnnotationTarget*, $ByteBuffer*)},
	{"parseAllTypeAnnotations", "(Ljava/lang/reflect/AnnotatedElement;)[Lsun/reflect/annotation/TypeAnnotation;", nullptr, $STATIC, $staticMethod(TypeAnnotationParser, parseAllTypeAnnotations, $TypeAnnotationArray*, $AnnotatedElement*)},
	{"parseAnnotatedBounds", "([Ljava/lang/reflect/Type;Ljava/lang/reflect/GenericDeclaration;I)[Ljava/lang/reflect/AnnotatedType;", "<D::Ljava/lang/reflect/GenericDeclaration;>([Ljava/lang/reflect/Type;TD;I)[Ljava/lang/reflect/AnnotatedType;", $PUBLIC | $STATIC, $staticMethod(TypeAnnotationParser, parseAnnotatedBounds, $AnnotatedTypeArray*, $TypeArray*, $GenericDeclaration*, int32_t)},
	{"parseAnnotatedBounds", "([Ljava/lang/reflect/Type;Ljava/lang/reflect/GenericDeclaration;ILsun/reflect/annotation/TypeAnnotation$LocationInfo;)[Ljava/lang/reflect/AnnotatedType;", "<D::Ljava/lang/reflect/GenericDeclaration;>([Ljava/lang/reflect/Type;TD;ILsun/reflect/annotation/TypeAnnotation$LocationInfo;)[Ljava/lang/reflect/AnnotatedType;", $PRIVATE | $STATIC, $staticMethod(TypeAnnotationParser, parseAnnotatedBounds, $AnnotatedTypeArray*, $TypeArray*, $GenericDeclaration*, int32_t, $TypeAnnotation$LocationInfo*)},
	{"parseShortTarget", "(Lsun/reflect/annotation/TypeAnnotation$TypeAnnotationTarget;Ljava/nio/ByteBuffer;)Lsun/reflect/annotation/TypeAnnotation$TypeAnnotationTargetInfo;", nullptr, $PRIVATE | $STATIC, $staticMethod(TypeAnnotationParser, parseShortTarget, $TypeAnnotation$TypeAnnotationTargetInfo*, $TypeAnnotation$TypeAnnotationTarget*, $ByteBuffer*)},
	{"parseTargetInfo", "(Ljava/nio/ByteBuffer;)Lsun/reflect/annotation/TypeAnnotation$TypeAnnotationTargetInfo;", nullptr, $PRIVATE | $STATIC, $staticMethod(TypeAnnotationParser, parseTargetInfo, $TypeAnnotation$TypeAnnotationTargetInfo*, $ByteBuffer*)},
	{"parseTypeAnnotation", "(Ljava/nio/ByteBuffer;Ljdk/internal/reflect/ConstantPool;Ljava/lang/reflect/AnnotatedElement;Ljava/lang/Class;)Lsun/reflect/annotation/TypeAnnotation;", "(Ljava/nio/ByteBuffer;Ljdk/internal/reflect/ConstantPool;Ljava/lang/reflect/AnnotatedElement;Ljava/lang/Class<*>;)Lsun/reflect/annotation/TypeAnnotation;", $PRIVATE | $STATIC, $staticMethod(TypeAnnotationParser, parseTypeAnnotation, $TypeAnnotation*, $ByteBuffer*, $ConstantPool*, $AnnotatedElement*, $Class*)},
	{"parseTypeAnnotations", "([BLjdk/internal/reflect/ConstantPool;Ljava/lang/reflect/AnnotatedElement;Ljava/lang/Class;)[Lsun/reflect/annotation/TypeAnnotation;", "([BLjdk/internal/reflect/ConstantPool;Ljava/lang/reflect/AnnotatedElement;Ljava/lang/Class<*>;)[Lsun/reflect/annotation/TypeAnnotation;", $PRIVATE | $STATIC, $staticMethod(TypeAnnotationParser, parseTypeAnnotations, $TypeAnnotationArray*, $bytes*, $ConstantPool*, $AnnotatedElement*, $Class*)},
	{"parseTypeVariableAnnotations", "(Ljava/lang/reflect/GenericDeclaration;I)[Ljava/lang/annotation/Annotation;", "<D::Ljava/lang/reflect/GenericDeclaration;>(TD;I)[Ljava/lang/annotation/Annotation;", $PUBLIC | $STATIC, $staticMethod(TypeAnnotationParser, parseTypeVariableAnnotations, $AnnotationArray*, $GenericDeclaration*, int32_t)},
	{}
};

$ClassInfo _TypeAnnotationParser_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.reflect.annotation.TypeAnnotationParser",
	"java.lang.Object",
	nullptr,
	_TypeAnnotationParser_FieldInfo_,
	_TypeAnnotationParser_MethodInfo_
};

$Object* allocate$TypeAnnotationParser($Class* clazz) {
	return $of($alloc(TypeAnnotationParser));
}

$TypeAnnotationArray* TypeAnnotationParser::EMPTY_TYPE_ANNOTATION_ARRAY = nullptr;

void TypeAnnotationParser::init$() {
}

$AnnotatedType* TypeAnnotationParser::buildAnnotatedType($bytes* rawAnnotations, $ConstantPool* cp, $AnnotatedElement* decl, $Class* container, $Type* type, $TypeAnnotation$TypeAnnotationTarget* filter) {
	$init(TypeAnnotationParser);
	$useLocalCurrentObjectStackCache();
	$var($TypeAnnotationArray, tas, parseTypeAnnotations(rawAnnotations, cp, decl, container));
	$var($List, l, $new($ArrayList, $nc(tas)->length));
	{
		$var($TypeAnnotationArray, arr$, tas);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($TypeAnnotation, t, arr$->get(i$));
			{
				$var($TypeAnnotation$TypeAnnotationTargetInfo, ti, $nc(t)->getTargetInfo());
				if ($nc(ti)->getTarget() == filter) {
					l->add(t);
				}
			}
		}
	}
	$var($TypeAnnotationArray, typeAnnotations, $fcast($TypeAnnotationArray, l->toArray(TypeAnnotationParser::EMPTY_TYPE_ANNOTATION_ARRAY)));
	$init($TypeAnnotation$LocationInfo);
	return $AnnotatedTypeFactory::buildAnnotatedType(type, $($AnnotatedTypeFactory::nestingForType(type, $TypeAnnotation$LocationInfo::BASE_LOCATION)), typeAnnotations, typeAnnotations, decl);
}

$AnnotatedTypeArray* TypeAnnotationParser::buildAnnotatedTypes($bytes* rawAnnotations, $ConstantPool* cp, $AnnotatedElement* decl, $Class* container, $TypeArray* types, $TypeAnnotation$TypeAnnotationTarget* filter) {
	$init(TypeAnnotationParser);
	$useLocalCurrentObjectStackCache();
	int32_t size = $nc(types)->length;
	$var($AnnotatedTypeArray, result, $new($AnnotatedTypeArray, size));
	$init($AnnotatedTypeFactory);
	$Arrays::fill(result, $of($AnnotatedTypeFactory::EMPTY_ANNOTATED_TYPE));
	$var($ArrayListArray, l, $new($ArrayListArray, size));
	$var($TypeAnnotationArray, tas, parseTypeAnnotations(rawAnnotations, cp, decl, container));
	{
		$var($TypeAnnotationArray, arr$, tas);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($TypeAnnotation, t, arr$->get(i$));
			{
				$var($TypeAnnotation$TypeAnnotationTargetInfo, ti, $nc(t)->getTargetInfo());
				if ($nc(ti)->getTarget() == filter) {
					int32_t pos = ti->getCount();
					if (l->get(pos) == nullptr) {
						$var($ArrayList, tmp, $new($ArrayList, $nc(tas)->length));
						l->set(pos, tmp);
					}
					$var($ArrayList, tmp, l->get(pos));
					$nc(tmp)->add(t);
				}
			}
		}
	}
	bool offset = false;
	if ($instanceOf($Constructor, decl)) {
		$var($Constructor, ctor, $cast($Constructor, decl));
		$Class* declaringClass = $nc(ctor)->getDeclaringClass();
		bool var$0 = !$nc(declaringClass)->isEnum();
		if (var$0) {
			bool var$1 = declaringClass->isMemberClass();
			var$0 = (var$1 && ((int32_t)(declaringClass->getModifiers() & (uint32_t)$Modifier::STATIC)) == 0);
		}
		if (var$0) {
			offset = true;
		}
	}
	for (int32_t i = 0; i < size; ++i) {
		$var($ArrayList, list, nullptr);
		if (offset) {
			$var($ArrayList, tmp, (i == 0) ? ($ArrayList*)nullptr : l->get(i - 1));
			$assign(list, tmp);
		} else {
			$var($ArrayList, tmp, l->get(i));
			$assign(list, tmp);
		}
		$var($TypeAnnotationArray, typeAnnotations, nullptr);
		if (list != nullptr) {
			$assign(typeAnnotations, $fcast($TypeAnnotationArray, list->toArray($$new($TypeAnnotationArray, list->size()))));
		} else {
			$assign(typeAnnotations, TypeAnnotationParser::EMPTY_TYPE_ANNOTATION_ARRAY);
		}
		$init($TypeAnnotation$LocationInfo);
		result->set(i, $($AnnotatedTypeFactory::buildAnnotatedType(types->get(i), $($AnnotatedTypeFactory::nestingForType(types->get(i), $TypeAnnotation$LocationInfo::BASE_LOCATION)), typeAnnotations, typeAnnotations, decl)));
	}
	return result;
}

$AnnotatedType* TypeAnnotationParser::buildAnnotatedSuperclass($bytes* rawAnnotations, $ConstantPool* cp, $Class* decl) {
	$init(TypeAnnotationParser);
	$var($Type, supertype, $nc(decl)->getGenericSuperclass());
	if (supertype == nullptr) {
		$init($AnnotatedTypeFactory);
		return $AnnotatedTypeFactory::EMPTY_ANNOTATED_TYPE;
	}
	$init($TypeAnnotation$TypeAnnotationTarget);
	return buildAnnotatedType(rawAnnotations, cp, decl, decl, supertype, $TypeAnnotation$TypeAnnotationTarget::CLASS_EXTENDS);
}

$AnnotatedTypeArray* TypeAnnotationParser::buildAnnotatedInterfaces($bytes* rawAnnotations, $ConstantPool* cp, $Class* decl) {
	$init(TypeAnnotationParser);
	bool var$0 = decl == $Object::class$ || $nc(decl)->isArray();
	$init($Void);
	if (var$0 || $nc(decl)->isPrimitive() || decl == $Void::TYPE) {
		$init($AnnotatedTypeFactory);
		return $AnnotatedTypeFactory::EMPTY_ANNOTATED_TYPE_ARRAY;
	}
	$init($TypeAnnotation$TypeAnnotationTarget);
	return buildAnnotatedTypes(rawAnnotations, cp, decl, decl, $($nc(decl)->getGenericInterfaces()), $TypeAnnotation$TypeAnnotationTarget::CLASS_IMPLEMENTS);
}

$AnnotationArray* TypeAnnotationParser::parseTypeVariableAnnotations($GenericDeclaration* genericDecl, int32_t typeVarIndex) {
	$init(TypeAnnotationParser);
	$useLocalCurrentObjectStackCache();
	$var($AnnotatedElement, decl, nullptr);
	$TypeAnnotation$TypeAnnotationTarget* predicate = nullptr;
	if ($instanceOf($Class, genericDecl)) {
		$assign(decl, $cast($Class, genericDecl));
		$init($TypeAnnotation$TypeAnnotationTarget);
		predicate = $TypeAnnotation$TypeAnnotationTarget::CLASS_TYPE_PARAMETER;
	} else if ($instanceOf($Executable, genericDecl)) {
		$assign(decl, static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>($cast($Executable, genericDecl))));
		$init($TypeAnnotation$TypeAnnotationTarget);
		predicate = $TypeAnnotation$TypeAnnotationTarget::METHOD_TYPE_PARAMETER;
	} else {
		$throwNew($AssertionError, $of($$str({"Unknown GenericDeclaration "_s, genericDecl, "\nthis should not happen."_s})));
	}
	$var($List, typeVarAnnos, $TypeAnnotation::filter($(parseAllTypeAnnotations(decl)), predicate));
	$var($List, res, $new($ArrayList, $nc(typeVarAnnos)->size()));
	{
		$var($Iterator, i$, $nc(typeVarAnnos)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($TypeAnnotation, t, $cast($TypeAnnotation, i$->next()));
			if ($nc($($nc(t)->getTargetInfo()))->getCount() == typeVarIndex) {
				res->add($(t->getAnnotation()));
			}
		}
	}
	return $fcast($AnnotationArray, res->toArray($$new($AnnotationArray, 0)));
}

$AnnotatedTypeArray* TypeAnnotationParser::parseAnnotatedBounds($TypeArray* bounds, $GenericDeclaration* decl, int32_t typeVarIndex) {
	$init(TypeAnnotationParser);
	$init($TypeAnnotation$LocationInfo);
	return parseAnnotatedBounds(bounds, decl, typeVarIndex, $TypeAnnotation$LocationInfo::BASE_LOCATION);
}

$AnnotatedTypeArray* TypeAnnotationParser::parseAnnotatedBounds($TypeArray* bounds, $GenericDeclaration* decl, int32_t typeVarIndex, $TypeAnnotation$LocationInfo* loc) {
	$init(TypeAnnotationParser);
	$useLocalCurrentObjectStackCache();
	$var($List, candidates, fetchBounds(decl));
	if (bounds != nullptr) {
		int32_t startIndex = 0;
		$var($AnnotatedTypeArray, res, $new($AnnotatedTypeArray, bounds->length));
		if (bounds->length > 0) {
			$var($Type, b0, bounds->get(0));
			if ($instanceOf($Class, b0)) {
				$Class* c = $cast($Class, b0);
				if ($nc(c)->isInterface()) {
					startIndex = 1;
				}
			} else if ($instanceOf($ParameterizedType, b0)) {
				$var($ParameterizedType, p, $cast($ParameterizedType, b0));
				$Class* c = $cast($Class, $nc(p)->getRawType());
				if ($nc(c)->isInterface()) {
					startIndex = 1;
				}
			}
		}
		for (int32_t i = 0; i < bounds->length; ++i) {
			$var($List, l, $new($ArrayList, $nc(candidates)->size()));
			{
				$var($Iterator, i$, $nc(candidates)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($TypeAnnotation, t, $cast($TypeAnnotation, i$->next()));
					{
						$var($TypeAnnotation$TypeAnnotationTargetInfo, tInfo, $nc(t)->getTargetInfo());
						bool var$0 = $nc(tInfo)->getSecondaryIndex() == i + startIndex;
						if (var$0 && tInfo->getCount() == typeVarIndex) {
							l->add(t);
						}
					}
				}
			}
			$var($TypeAnnotationArray, typeAnnotations, $fcast($TypeAnnotationArray, l->toArray(TypeAnnotationParser::EMPTY_TYPE_ANNOTATION_ARRAY)));
			res->set(i, $($AnnotatedTypeFactory::buildAnnotatedType(bounds->get(i), $($AnnotatedTypeFactory::nestingForType(bounds->get(i), loc)), typeAnnotations, typeAnnotations, decl)));
		}
		return res;
	}
	return $new($AnnotatedTypeArray, 0);
}

$List* TypeAnnotationParser::fetchBounds($GenericDeclaration* decl) {
	$init(TypeAnnotationParser);
	$useLocalCurrentObjectStackCache();
	$var($AnnotatedElement, boundsDecl, nullptr);
	$TypeAnnotation$TypeAnnotationTarget* target = nullptr;
	if ($instanceOf($Class, decl)) {
		$init($TypeAnnotation$TypeAnnotationTarget);
		target = $TypeAnnotation$TypeAnnotationTarget::CLASS_TYPE_PARAMETER_BOUND;
		$assign(boundsDecl, $cast($Class, decl));
	} else {
		$init($TypeAnnotation$TypeAnnotationTarget);
		target = $TypeAnnotation$TypeAnnotationTarget::METHOD_TYPE_PARAMETER_BOUND;
		$assign(boundsDecl, static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>($cast($Executable, decl))));
	}
	return $TypeAnnotation::filter($(TypeAnnotationParser::parseAllTypeAnnotations(boundsDecl)), target);
}

$TypeAnnotationArray* TypeAnnotationParser::parseAllTypeAnnotations($AnnotatedElement* decl) {
	$init(TypeAnnotationParser);
	$useLocalCurrentObjectStackCache();
	$Class* container = nullptr;
	$var($bytes, rawBytes, nullptr);
	$var($JavaLangAccess, javaLangAccess, $SharedSecrets::getJavaLangAccess());
	if ($instanceOf($Class, decl)) {
		container = $cast($Class, decl);
		$assign(rawBytes, $nc(javaLangAccess)->getRawClassTypeAnnotations(container));
	} else if ($instanceOf($Executable, decl)) {
		container = $nc(($cast($Executable, decl)))->getDeclaringClass();
		$assign(rawBytes, $nc(javaLangAccess)->getRawExecutableTypeAnnotations($cast($Executable, decl)));
	} else {
		return TypeAnnotationParser::EMPTY_TYPE_ANNOTATION_ARRAY;
	}
	return parseTypeAnnotations(rawBytes, $($nc(javaLangAccess)->getConstantPool(container)), decl, container);
}

$TypeAnnotationArray* TypeAnnotationParser::parseTypeAnnotations($bytes* rawAnnotations, $ConstantPool* cp, $AnnotatedElement* baseDecl, $Class* container) {
	$init(TypeAnnotationParser);
	$useLocalCurrentObjectStackCache();
	if (rawAnnotations == nullptr) {
		return TypeAnnotationParser::EMPTY_TYPE_ANNOTATION_ARRAY;
	}
	$var($ByteBuffer, buf, $ByteBuffer::wrap(rawAnnotations));
	int32_t annotationCount = (int32_t)($nc(buf)->getShort() & (uint32_t)0x0000FFFF);
	$var($List, typeAnnotations, $new($ArrayList, annotationCount));
	for (int32_t i = 0; i < annotationCount; ++i) {
		$var($TypeAnnotation, ta, parseTypeAnnotation(buf, cp, baseDecl, container));
		if (ta != nullptr) {
			typeAnnotations->add(ta);
		}
	}
	return $fcast($TypeAnnotationArray, typeAnnotations->toArray(TypeAnnotationParser::EMPTY_TYPE_ANNOTATION_ARRAY));
}

$Map* TypeAnnotationParser::mapTypeAnnotations($TypeAnnotationArray* typeAnnos) {
	$init(TypeAnnotationParser);
	$useLocalCurrentObjectStackCache();
	$var($Map, result, $new($LinkedHashMap));
	{
		$var($TypeAnnotationArray, arr$, typeAnnos);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($TypeAnnotation, t, arr$->get(i$));
			{
				$var($Annotation, a, $nc(t)->getAnnotation());
				if (a != nullptr) {
					$Class* klass = a->annotationType();
					$var($AnnotationType, type, $AnnotationType::getInstance(klass));
					$init($RetentionPolicy);
					bool var$0 = $nc(type)->retention() == $RetentionPolicy::RUNTIME;
					if (var$0 && result->put(klass, a) != nullptr) {
						$throwNew($AnnotationFormatError, $$str({"Duplicate annotation for class: "_s, klass, ": "_s, a}));
					}
				}
			}
		}
	}
	return result;
}

$TypeAnnotation* TypeAnnotationParser::parseTypeAnnotation($ByteBuffer* buf, $ConstantPool* cp, $AnnotatedElement* baseDecl, $Class* container) {
	$init(TypeAnnotationParser);
	$useLocalCurrentObjectStackCache();
	try {
		$var($TypeAnnotation$TypeAnnotationTargetInfo, ti, parseTargetInfo(buf));
		$var($TypeAnnotation$LocationInfo, locationInfo, $TypeAnnotation$LocationInfo::parseLocationInfo(buf));
		$var($Annotation, a, $AnnotationParser::parseAnnotation(buf, cp, container, false));
		if (ti == nullptr) {
			return nullptr;
		}
		return $new($TypeAnnotation, ti, locationInfo, a, baseDecl);
	} catch ($IllegalArgumentException& e) {
		$throwNew($AnnotationFormatError, static_cast<$Throwable*>(e));
	} catch ($BufferUnderflowException& e) {
		$throwNew($AnnotationFormatError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$TypeAnnotation$TypeAnnotationTargetInfo* TypeAnnotationParser::parseTargetInfo($ByteBuffer* buf) {
	$init(TypeAnnotationParser);
	$useLocalCurrentObjectStackCache();
	int32_t posCode = (int32_t)($nc(buf)->get() & (uint32_t)255);
	{
		int16_t length = 0;
		switch (posCode) {
		case TypeAnnotationParser::CLASS_TYPE_PARAMETER:
			{}
		case TypeAnnotationParser::METHOD_TYPE_PARAMETER:
			{
				{
					int32_t index = (int32_t)(buf->get() & (uint32_t)255);
					$var($TypeAnnotation$TypeAnnotationTargetInfo, res, nullptr);
					if (posCode == TypeAnnotationParser::CLASS_TYPE_PARAMETER) {
						$init($TypeAnnotation$TypeAnnotationTarget);
						$assign(res, $new($TypeAnnotation$TypeAnnotationTargetInfo, $TypeAnnotation$TypeAnnotationTarget::CLASS_TYPE_PARAMETER, index));
					} else {
						$init($TypeAnnotation$TypeAnnotationTarget);
						$assign(res, $new($TypeAnnotation$TypeAnnotationTargetInfo, $TypeAnnotation$TypeAnnotationTarget::METHOD_TYPE_PARAMETER, index));
					}
					return res;
				}
			}
		case TypeAnnotationParser::CLASS_EXTENDS:
			{
				{
					int16_t index = buf->getShort();
					if (index == -1) {
						$init($TypeAnnotation$TypeAnnotationTarget);
						return $new($TypeAnnotation$TypeAnnotationTargetInfo, $TypeAnnotation$TypeAnnotationTarget::CLASS_EXTENDS);
					} else if (index >= 0) {
						$init($TypeAnnotation$TypeAnnotationTarget);
						$var($TypeAnnotation$TypeAnnotationTargetInfo, res, $new($TypeAnnotation$TypeAnnotationTargetInfo, $TypeAnnotation$TypeAnnotationTarget::CLASS_IMPLEMENTS, index));
						return res;
					}
				}
				break;
			}
		case TypeAnnotationParser::CLASS_TYPE_PARAMETER_BOUND:
			{
				$init($TypeAnnotation$TypeAnnotationTarget);
				return parse2ByteTarget($TypeAnnotation$TypeAnnotationTarget::CLASS_TYPE_PARAMETER_BOUND, buf);
			}
		case TypeAnnotationParser::METHOD_TYPE_PARAMETER_BOUND:
			{
				$init($TypeAnnotation$TypeAnnotationTarget);
				return parse2ByteTarget($TypeAnnotation$TypeAnnotationTarget::METHOD_TYPE_PARAMETER_BOUND, buf);
			}
		case TypeAnnotationParser::FIELD:
			{
				$init($TypeAnnotation$TypeAnnotationTarget);
				return $new($TypeAnnotation$TypeAnnotationTargetInfo, $TypeAnnotation$TypeAnnotationTarget::FIELD);
			}
		case TypeAnnotationParser::METHOD_RETURN:
			{
				$init($TypeAnnotation$TypeAnnotationTarget);
				return $new($TypeAnnotation$TypeAnnotationTargetInfo, $TypeAnnotation$TypeAnnotationTarget::METHOD_RETURN);
			}
		case TypeAnnotationParser::METHOD_RECEIVER:
			{
				$init($TypeAnnotation$TypeAnnotationTarget);
				return $new($TypeAnnotation$TypeAnnotationTargetInfo, $TypeAnnotation$TypeAnnotationTarget::METHOD_RECEIVER);
			}
		case TypeAnnotationParser::METHOD_FORMAL_PARAMETER:
			{
				{
					int32_t index = (int32_t)(buf->get() & (uint32_t)255);
					$init($TypeAnnotation$TypeAnnotationTarget);
					return $new($TypeAnnotation$TypeAnnotationTargetInfo, $TypeAnnotation$TypeAnnotationTarget::METHOD_FORMAL_PARAMETER, index);
				}
			}
		case TypeAnnotationParser::THROWS:
			{
				$init($TypeAnnotation$TypeAnnotationTarget);
				return parseShortTarget($TypeAnnotation$TypeAnnotationTarget::THROWS, buf);
			}
		case TypeAnnotationParser::LOCAL_VARIABLE:
			{}
		case TypeAnnotationParser::RESOURCE_VARIABLE:
			{
				length = buf->getShort();
				for (int32_t i = 0; i < length; ++i) {
					int16_t offset = buf->getShort();
					int16_t varLength = buf->getShort();
					int16_t index = buf->getShort();
				}
				return nullptr;
			}
		case TypeAnnotationParser::EXCEPTION_PARAMETER:
			{
				{
					int8_t index = buf->get();
				}
				return nullptr;
			}
		case TypeAnnotationParser::INSTANCEOF:
			{}
		case TypeAnnotationParser::NEW:
			{}
		case TypeAnnotationParser::CONSTRUCTOR_REFERENCE:
			{}
		case TypeAnnotationParser::METHOD_REFERENCE:
			{
				{
					int16_t offset = buf->getShort();
				}
				return nullptr;
			}
		case TypeAnnotationParser::CAST:
			{}
		case TypeAnnotationParser::CONSTRUCTOR_INVOCATION_TYPE_ARGUMENT:
			{}
		case TypeAnnotationParser::METHOD_INVOCATION_TYPE_ARGUMENT:
			{}
		case TypeAnnotationParser::CONSTRUCTOR_REFERENCE_TYPE_ARGUMENT:
			{}
		case TypeAnnotationParser::METHOD_REFERENCE_TYPE_ARGUMENT:
			{
				{
					int16_t offset = buf->getShort();
					int8_t index = buf->get();
				}
				return nullptr;
			}
		default:
			{
				break;
			}
		}
	}
	$throwNew($AnnotationFormatError, "Could not parse bytes for type annotations"_s);
}

$TypeAnnotation$TypeAnnotationTargetInfo* TypeAnnotationParser::parseShortTarget($TypeAnnotation$TypeAnnotationTarget* target, $ByteBuffer* buf) {
	$init(TypeAnnotationParser);
	int32_t index = (int32_t)($nc(buf)->getShort() & (uint32_t)0x0000FFFF);
	return $new($TypeAnnotation$TypeAnnotationTargetInfo, target, index);
}

$TypeAnnotation$TypeAnnotationTargetInfo* TypeAnnotationParser::parse2ByteTarget($TypeAnnotation$TypeAnnotationTarget* target, $ByteBuffer* buf) {
	$init(TypeAnnotationParser);
	int32_t count = (int32_t)($nc(buf)->get() & (uint32_t)255);
	int32_t secondaryIndex = (int32_t)(buf->get() & (uint32_t)255);
	return $new($TypeAnnotation$TypeAnnotationTargetInfo, target, count, secondaryIndex);
}

void clinit$TypeAnnotationParser($Class* class$) {
	$assignStatic(TypeAnnotationParser::EMPTY_TYPE_ANNOTATION_ARRAY, $new($TypeAnnotationArray, 0));
}

TypeAnnotationParser::TypeAnnotationParser() {
}

$Class* TypeAnnotationParser::load$($String* name, bool initialize) {
	$loadClass(TypeAnnotationParser, name, initialize, &_TypeAnnotationParser_ClassInfo_, clinit$TypeAnnotationParser, allocate$TypeAnnotationParser);
	return class$;
}

$Class* TypeAnnotationParser::class$ = nullptr;

		} // annotation
	} // reflect
} // sun