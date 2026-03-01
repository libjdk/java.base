#include <sun/reflect/generics/repository/ClassRepository.h>

#include <java/lang/reflect/Type.h>
#include <sun/reflect/generics/factory/GenericsFactory.h>
#include <sun/reflect/generics/parser/SignatureParser.h>
#include <sun/reflect/generics/repository/AbstractRepository.h>
#include <sun/reflect/generics/repository/GenericDeclRepository.h>
#include <sun/reflect/generics/tree/ClassSignature.h>
#include <sun/reflect/generics/tree/ClassTypeSignature.h>
#include <sun/reflect/generics/tree/Tree.h>
#include <sun/reflect/generics/tree/TypeTree.h>
#include <sun/reflect/generics/visitor/Reifier.h>
#include <sun/reflect/generics/visitor/TypeTreeVisitor.h>
#include <jcpp.h>

#undef NONE

using $TypeArray = $Array<::java::lang::reflect::Type>;
using $TypeTreeArray = $Array<::sun::reflect::generics::tree::TypeTree>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Type = ::java::lang::reflect::Type;
using $GenericsFactory = ::sun::reflect::generics::factory::GenericsFactory;
using $SignatureParser = ::sun::reflect::generics::parser::SignatureParser;
using $GenericDeclRepository = ::sun::reflect::generics::repository::GenericDeclRepository;
using $ClassSignature = ::sun::reflect::generics::tree::ClassSignature;
using $ClassTypeSignature = ::sun::reflect::generics::tree::ClassTypeSignature;
using $Tree = ::sun::reflect::generics::tree::Tree;
using $TypeTree = ::sun::reflect::generics::tree::TypeTree;
using $Reifier = ::sun::reflect::generics::visitor::Reifier;
using $TypeTreeVisitor = ::sun::reflect::generics::visitor::TypeTreeVisitor;

namespace sun {
	namespace reflect {
		namespace generics {
			namespace repository {

$FieldInfo _ClassRepository_FieldInfo_[] = {
	{"NONE", "Lsun/reflect/generics/repository/ClassRepository;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(ClassRepository, NONE)},
	{"superclass", "Ljava/lang/reflect/Type;", nullptr, $PRIVATE | $VOLATILE, $field(ClassRepository, superclass)},
	{"superInterfaces", "[Ljava/lang/reflect/Type;", nullptr, $PRIVATE | $VOLATILE, $field(ClassRepository, superInterfaces)},
	{}
};

$MethodInfo _ClassRepository_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Lsun/reflect/generics/factory/GenericsFactory;)V", nullptr, $PRIVATE, $method(ClassRepository, init$, void, $String*, $GenericsFactory*)},
	{"computeSuperInterfaces", "()[Ljava/lang/reflect/Type;", nullptr, $PRIVATE, $method(ClassRepository, computeSuperInterfaces, $TypeArray*)},
	{"computeSuperclass", "()Ljava/lang/reflect/Type;", nullptr, $PRIVATE, $method(ClassRepository, computeSuperclass, $Type*)},
	{"getSuperInterfaces", "()[Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(ClassRepository, getSuperInterfaces, $TypeArray*)},
	{"getSuperclass", "()Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $virtualMethod(ClassRepository, getSuperclass, $Type*)},
	{"make", "(Ljava/lang/String;Lsun/reflect/generics/factory/GenericsFactory;)Lsun/reflect/generics/repository/ClassRepository;", nullptr, $PUBLIC | $STATIC, $staticMethod(ClassRepository, make, ClassRepository*, $String*, $GenericsFactory*)},
	{"parse", "(Ljava/lang/String;)Lsun/reflect/generics/tree/ClassSignature;", nullptr, $PROTECTED, $virtualMethod(ClassRepository, parse, $Tree*, $String*)},
	{}
};

$ClassInfo _ClassRepository_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.reflect.generics.repository.ClassRepository",
	"sun.reflect.generics.repository.GenericDeclRepository",
	nullptr,
	_ClassRepository_FieldInfo_,
	_ClassRepository_MethodInfo_,
	"Lsun/reflect/generics/repository/GenericDeclRepository<Lsun/reflect/generics/tree/ClassSignature;>;"
};

$Object* allocate$ClassRepository($Class* clazz) {
	return $of($alloc(ClassRepository));
}

ClassRepository* ClassRepository::NONE = nullptr;

void ClassRepository::init$($String* rawSig, $GenericsFactory* f) {
	$GenericDeclRepository::init$(rawSig, f);
}

$Tree* ClassRepository::parse($String* s) {
	return $nc($($SignatureParser::make()))->parseClassSig(s);
}

ClassRepository* ClassRepository::make($String* rawSig, $GenericsFactory* f) {
	$init(ClassRepository);
	return $new(ClassRepository, rawSig, f);
}

$Type* ClassRepository::getSuperclass() {
	$var($Type, value, this->superclass);
	if (value == nullptr) {
		$assign(value, computeSuperclass());
		$set(this, superclass, value);
	}
	return value;
}

$TypeArray* ClassRepository::getSuperInterfaces() {
	$var($TypeArray, value, this->superInterfaces);
	if (value == nullptr) {
		$assign(value, computeSuperInterfaces());
		$set(this, superInterfaces, value);
	}
	return $cast($TypeArray, $nc(value)->clone());
}

$Type* ClassRepository::computeSuperclass() {
	$useLocalCurrentObjectStackCache();
	$var($Reifier, r, getReifier());
	$nc($($nc(($cast($ClassSignature, $(getTree()))))->getSuperclass()))->accept(r);
	return $cast($Type, $nc(r)->getResult());
}

$TypeArray* ClassRepository::computeSuperInterfaces() {
	$useLocalCurrentObjectStackCache();
	$var($TypeTreeArray, ts, $fcast($TypeTreeArray, $nc(($cast($ClassSignature, $(getTree()))))->getSuperInterfaces()));
	int32_t length = $nc(ts)->length;
	$var($TypeArray, superInterfaces, $new($TypeArray, length));
	for (int32_t i = 0; i < length; ++i) {
		$var($Reifier, r, getReifier());
		$nc(ts->get(i))->accept(r);
		superInterfaces->set(i, $($cast($Type, $nc(r)->getResult())));
	}
	return superInterfaces;
}

void clinit$ClassRepository($Class* class$) {
	$assignStatic(ClassRepository::NONE, ClassRepository::make("Ljava/lang/Object;"_s, nullptr));
}

ClassRepository::ClassRepository() {
}

$Class* ClassRepository::load$($String* name, bool initialize) {
	$loadClass(ClassRepository, name, initialize, &_ClassRepository_ClassInfo_, clinit$ClassRepository, allocate$ClassRepository);
	return class$;
}

$Class* ClassRepository::class$ = nullptr;

			} // repository
		} // generics
	} // reflect
} // sun