#include <sun/reflect/generics/repository/ConstructorRepository.h>

#include <java/lang/reflect/Type.h>
#include <sun/reflect/generics/factory/GenericsFactory.h>
#include <sun/reflect/generics/parser/SignatureParser.h>
#include <sun/reflect/generics/repository/AbstractRepository.h>
#include <sun/reflect/generics/repository/GenericDeclRepository.h>
#include <sun/reflect/generics/tree/FieldTypeSignature.h>
#include <sun/reflect/generics/tree/MethodTypeSignature.h>
#include <sun/reflect/generics/tree/Tree.h>
#include <sun/reflect/generics/tree/TypeSignature.h>
#include <sun/reflect/generics/tree/TypeTree.h>
#include <sun/reflect/generics/visitor/Reifier.h>
#include <sun/reflect/generics/visitor/TypeTreeVisitor.h>
#include <jcpp.h>

using $TypeArray = $Array<::java::lang::reflect::Type>;
using $FieldTypeSignatureArray = $Array<::sun::reflect::generics::tree::FieldTypeSignature>;
using $TypeSignatureArray = $Array<::sun::reflect::generics::tree::TypeSignature>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Type = ::java::lang::reflect::Type;
using $GenericsFactory = ::sun::reflect::generics::factory::GenericsFactory;
using $SignatureParser = ::sun::reflect::generics::parser::SignatureParser;
using $GenericDeclRepository = ::sun::reflect::generics::repository::GenericDeclRepository;
using $FieldTypeSignature = ::sun::reflect::generics::tree::FieldTypeSignature;
using $MethodTypeSignature = ::sun::reflect::generics::tree::MethodTypeSignature;
using $Tree = ::sun::reflect::generics::tree::Tree;
using $TypeSignature = ::sun::reflect::generics::tree::TypeSignature;
using $Reifier = ::sun::reflect::generics::visitor::Reifier;
using $TypeTreeVisitor = ::sun::reflect::generics::visitor::TypeTreeVisitor;

namespace sun {
	namespace reflect {
		namespace generics {
			namespace repository {

$FieldInfo _ConstructorRepository_FieldInfo_[] = {
	{"parameterTypes", "[Ljava/lang/reflect/Type;", nullptr, $PRIVATE | $VOLATILE, $field(ConstructorRepository, parameterTypes)},
	{"exceptionTypes", "[Ljava/lang/reflect/Type;", nullptr, $PRIVATE | $VOLATILE, $field(ConstructorRepository, exceptionTypes)},
	{}
};

$MethodInfo _ConstructorRepository_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Lsun/reflect/generics/factory/GenericsFactory;)V", nullptr, $PROTECTED, $method(ConstructorRepository, init$, void, $String*, $GenericsFactory*)},
	{"computeExceptionTypes", "()[Ljava/lang/reflect/Type;", nullptr, $PRIVATE, $method(ConstructorRepository, computeExceptionTypes, $TypeArray*)},
	{"computeParameterTypes", "()[Ljava/lang/reflect/Type;", nullptr, $PRIVATE, $method(ConstructorRepository, computeParameterTypes, $TypeArray*)},
	{"getExceptionTypes", "()[Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(ConstructorRepository, getExceptionTypes, $TypeArray*)},
	{"getParameterTypes", "()[Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(ConstructorRepository, getParameterTypes, $TypeArray*)},
	{"make", "(Ljava/lang/String;Lsun/reflect/generics/factory/GenericsFactory;)Lsun/reflect/generics/repository/ConstructorRepository;", nullptr, $PUBLIC | $STATIC, $staticMethod(ConstructorRepository, make, ConstructorRepository*, $String*, $GenericsFactory*)},
	{"parse", "(Ljava/lang/String;)Lsun/reflect/generics/tree/MethodTypeSignature;", nullptr, $PROTECTED, $virtualMethod(ConstructorRepository, parse, $Tree*, $String*)},
	{}
};

$ClassInfo _ConstructorRepository_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.reflect.generics.repository.ConstructorRepository",
	"sun.reflect.generics.repository.GenericDeclRepository",
	nullptr,
	_ConstructorRepository_FieldInfo_,
	_ConstructorRepository_MethodInfo_,
	"Lsun/reflect/generics/repository/GenericDeclRepository<Lsun/reflect/generics/tree/MethodTypeSignature;>;"
};

$Object* allocate$ConstructorRepository($Class* clazz) {
	return $of($alloc(ConstructorRepository));
}

void ConstructorRepository::init$($String* rawSig, $GenericsFactory* f) {
	$GenericDeclRepository::init$(rawSig, f);
}

$Tree* ConstructorRepository::parse($String* s) {
	return $nc($($SignatureParser::make()))->parseMethodSig(s);
}

ConstructorRepository* ConstructorRepository::make($String* rawSig, $GenericsFactory* f) {
	$init(ConstructorRepository);
	return $new(ConstructorRepository, rawSig, f);
}

$TypeArray* ConstructorRepository::getParameterTypes() {
	$var($TypeArray, value, this->parameterTypes);
	if (value == nullptr) {
		$assign(value, computeParameterTypes());
		$set(this, parameterTypes, value);
	}
	return $cast($TypeArray, $nc(value)->clone());
}

$TypeArray* ConstructorRepository::getExceptionTypes() {
	$var($TypeArray, value, this->exceptionTypes);
	if (value == nullptr) {
		$assign(value, computeExceptionTypes());
		$set(this, exceptionTypes, value);
	}
	return $cast($TypeArray, $nc(value)->clone());
}

$TypeArray* ConstructorRepository::computeParameterTypes() {
	$useLocalCurrentObjectStackCache();
	$var($TypeSignatureArray, pts, $nc(($cast($MethodTypeSignature, $(getTree()))))->getParameterTypes());
	int32_t length = $nc(pts)->length;
	$var($TypeArray, parameterTypes, $new($TypeArray, length));
	for (int32_t i = 0; i < length; ++i) {
		$var($Reifier, r, getReifier());
		$nc(pts->get(i))->accept(r);
		parameterTypes->set(i, $($cast($Type, $nc(r)->getResult())));
	}
	return parameterTypes;
}

$TypeArray* ConstructorRepository::computeExceptionTypes() {
	$useLocalCurrentObjectStackCache();
	$var($FieldTypeSignatureArray, ets, $nc(($cast($MethodTypeSignature, $(getTree()))))->getExceptionTypes());
	int32_t length = $nc(ets)->length;
	$var($TypeArray, exceptionTypes, $new($TypeArray, length));
	for (int32_t i = 0; i < length; ++i) {
		$var($Reifier, r, getReifier());
		$nc(ets->get(i))->accept(r);
		exceptionTypes->set(i, $($cast($Type, $nc(r)->getResult())));
	}
	return exceptionTypes;
}

ConstructorRepository::ConstructorRepository() {
}

$Class* ConstructorRepository::load$($String* name, bool initialize) {
	$loadClass(ConstructorRepository, name, initialize, &_ConstructorRepository_ClassInfo_, allocate$ConstructorRepository);
	return class$;
}

$Class* ConstructorRepository::class$ = nullptr;

			} // repository
		} // generics
	} // reflect
} // sun