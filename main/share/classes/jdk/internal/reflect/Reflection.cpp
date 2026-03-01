#include <jdk/internal/reflect/Reflection.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/IllegalCallerException.h>
#include <java/lang/Module.h>
#include <java/lang/reflect/AccessibleObject.h>
#include <java/lang/reflect/Array.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/Member.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Modifier.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/JavaLangReflectAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/misc/VM.h>
#include <jdk/internal/reflect/CallerSensitive.h>
#include <jcpp.h>

#include "StackWalk.h"
#include <java/lang/Machine.h>

#undef ALL_MEMBERS
#undef WILDCARD

using $FieldArray = $Array<::java::lang::reflect::Field>;
using $MemberArray = $Array<::java::lang::reflect::Member>;
using $MethodArray = $Array<::java::lang::reflect::Method>;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalCallerException = ::java::lang::IllegalCallerException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $AccessibleObject = ::java::lang::reflect::AccessibleObject;
using $1Array = ::java::lang::reflect::Array;
using $Constructor = ::java::lang::reflect::Constructor;
using $Field = ::java::lang::reflect::Field;
using $Member = ::java::lang::reflect::Member;
using $Method = ::java::lang::reflect::Method;
using $Modifier = ::java::lang::reflect::Modifier;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $JavaLangReflectAccess = ::jdk::internal::access::JavaLangReflectAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $VM = ::jdk::internal::misc::VM;
using $CallerSensitive = ::jdk::internal::reflect::CallerSensitive;

namespace jdk {
	namespace internal {
		namespace reflect {

$String* forLambdaClass($String* className) {
	if (className == nullptr) {
		return nullptr;
	}
 //   int32_t index = className->indexOf("$$Lambda");
  //  if (index > 0) {
  //	  return className->substring(0, index);
   // }
	if (::java::lang::Machine::isLambdaClass(className)) {
		return ::java::lang::Machine::getLambdaHoder(className);
	}
	return className;
}

$CompoundAttribute _Reflection_MethodAnnotations_getCallerClass7[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Reflection_MethodAnnotations_getClassAccessFlags8[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$FieldInfo _Reflection_FieldInfo_[] = {
	{"fieldFilterMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Class<*>;Ljava/util/Set<Ljava/lang/String;>;>;", $PRIVATE | $STATIC | $VOLATILE, $staticField(Reflection, fieldFilterMap)},
	{"methodFilterMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Class<*>;Ljava/util/Set<Ljava/lang/String;>;>;", $PRIVATE | $STATIC | $VOLATILE, $staticField(Reflection, methodFilterMap)},
	{"WILDCARD", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Reflection, WILDCARD)},
	{"ALL_MEMBERS", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC | $STATIC | $FINAL, $staticField(Reflection, ALL_MEMBERS)},
	{}
};

$MethodInfo _Reflection_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Reflection, init$, void)},
	{"areNestMates", "(Ljava/lang/Class;Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)Z", $PUBLIC | $STATIC | $NATIVE, $staticMethod(Reflection, areNestMates, bool, $Class*, $Class*)},
	{"ensureMemberAccess", "(Ljava/lang/Class;Ljava/lang/Class;Ljava/lang/Class;I)V", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;Ljava/lang/Class<*>;I)V", $PUBLIC | $STATIC, $staticMethod(Reflection, ensureMemberAccess, void, $Class*, $Class*, $Class*, int32_t), "java.lang.IllegalAccessException"},
	{"ensureNativeAccess", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;)V", $PUBLIC | $STATIC, $staticMethod(Reflection, ensureNativeAccess, void, $Class*)},
	{"filter", "([Ljava/lang/reflect/Member;Ljava/util/Set;)[Ljava/lang/reflect/Member;", "([Ljava/lang/reflect/Member;Ljava/util/Set<Ljava/lang/String;>;)[Ljava/lang/reflect/Member;", $PRIVATE | $STATIC, $staticMethod(Reflection, filter, $MemberArray*, $MemberArray*, $Set*)},
	{"filterFields", "(Ljava/lang/Class;[Ljava/lang/reflect/Field;)[Ljava/lang/reflect/Field;", "(Ljava/lang/Class<*>;[Ljava/lang/reflect/Field;)[Ljava/lang/reflect/Field;", $PUBLIC | $STATIC, $staticMethod(Reflection, filterFields, $FieldArray*, $Class*, $FieldArray*)},
	{"filterMethods", "(Ljava/lang/Class;[Ljava/lang/reflect/Method;)[Ljava/lang/reflect/Method;", "(Ljava/lang/Class<*>;[Ljava/lang/reflect/Method;)[Ljava/lang/reflect/Method;", $PUBLIC | $STATIC, $staticMethod(Reflection, filterMethods, $MethodArray*, $Class*, $MethodArray*)},
	{"getCallerClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PUBLIC | $STATIC | $NATIVE, $staticMethod(Reflection, getCallerClass, $Class*), nullptr, nullptr, _Reflection_MethodAnnotations_getCallerClass7},
	{"getClassAccessFlags", "(Ljava/lang/Class;)I", "(Ljava/lang/Class<*>;)I", $PUBLIC | $STATIC | $NATIVE, $staticMethod(Reflection, getClassAccessFlags, int32_t, $Class*), nullptr, nullptr, _Reflection_MethodAnnotations_getClassAccessFlags8},
	{"isCallerSensitive", "(Ljava/lang/reflect/Method;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(Reflection, isCallerSensitive, bool, $Method*)},
	{"isSameClassPackage", "(Ljava/lang/Class;Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC, $staticMethod(Reflection, isSameClassPackage, bool, $Class*, $Class*)},
	{"isSubclassOf", "(Ljava/lang/Class;Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)Z", $STATIC, $staticMethod(Reflection, isSubclassOf, bool, $Class*, $Class*)},
	{"isTrustedFinalField", "(Ljava/lang/reflect/Field;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(Reflection, isTrustedFinalField, bool, $Field*)},
	{"newIllegalAccessException", "(Ljava/lang/Class;Ljava/lang/Class;Ljava/lang/Class;I)Ljava/lang/IllegalAccessException;", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;Ljava/lang/Class<*>;I)Ljava/lang/IllegalAccessException;", $PUBLIC | $STATIC, $staticMethod(Reflection, newIllegalAccessException, $IllegalAccessException*, $Class*, $Class*, $Class*, int32_t)},
	{"newIllegalAccessException", "(Ljava/lang/Class;I)Ljava/lang/IllegalAccessException;", "(Ljava/lang/Class<*>;I)Ljava/lang/IllegalAccessException;", $PRIVATE | $STATIC, $staticMethod(Reflection, newIllegalAccessException, $IllegalAccessException*, $Class*, int32_t)},
	{"registerFieldsToFilter", "(Ljava/lang/Class;Ljava/util/Set;)V", "(Ljava/lang/Class<*>;Ljava/util/Set<Ljava/lang/String;>;)V", $PUBLIC | $STATIC | $SYNCHRONIZED, $staticMethod(Reflection, registerFieldsToFilter, void, $Class*, $Set*)},
	{"registerFilter", "(Ljava/util/Map;Ljava/lang/Class;Ljava/util/Set;)Ljava/util/Map;", "(Ljava/util/Map<Ljava/lang/Class<*>;Ljava/util/Set<Ljava/lang/String;>;>;Ljava/lang/Class<*>;Ljava/util/Set<Ljava/lang/String;>;)Ljava/util/Map<Ljava/lang/Class<*>;Ljava/util/Set<Ljava/lang/String;>;>;", $PRIVATE | $STATIC, $staticMethod(Reflection, registerFilter, $Map*, $Map*, $Class*, $Set*)},
	{"registerMethodsToFilter", "(Ljava/lang/Class;Ljava/util/Set;)V", "(Ljava/lang/Class<*>;Ljava/util/Set<Ljava/lang/String;>;)V", $PUBLIC | $STATIC | $SYNCHRONIZED, $staticMethod(Reflection, registerMethodsToFilter, void, $Class*, $Set*)},
	{"verifyMemberAccess", "(Ljava/lang/Class;Ljava/lang/Class;Ljava/lang/Class;I)Z", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;Ljava/lang/Class<*>;I)Z", $PUBLIC | $STATIC, $staticMethod(Reflection, verifyMemberAccess, bool, $Class*, $Class*, $Class*, int32_t)},
	{"verifyModuleAccess", "(Ljava/lang/Module;Ljava/lang/Class;)Z", "(Ljava/lang/Module;Ljava/lang/Class<*>;)Z", $PUBLIC | $STATIC, $staticMethod(Reflection, verifyModuleAccess, bool, $Module*, $Class*)},
	{"verifyPublicMemberAccess", "(Ljava/lang/Class;I)Z", "(Ljava/lang/Class<*>;I)Z", $PUBLIC | $STATIC, $staticMethod(Reflection, verifyPublicMemberAccess, bool, $Class*, int32_t)},
	{}
};

#define _METHOD_INDEX_areNestMates 1
#define _METHOD_INDEX_getCallerClass 7
#define _METHOD_INDEX_getClassAccessFlags 8

$ClassInfo _Reflection_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.reflect.Reflection",
	"java.lang.Object",
	nullptr,
	_Reflection_FieldInfo_,
	_Reflection_MethodInfo_
};

$Object* allocate$Reflection($Class* clazz) {
	return $of($alloc(Reflection));
}

$volatile($Map*) Reflection::fieldFilterMap = nullptr;
$volatile($Map*) Reflection::methodFilterMap = nullptr;
$String* Reflection::WILDCARD = nullptr;
$Set* Reflection::ALL_MEMBERS = nullptr;

void Reflection::init$() {
}

$Class* Reflection::getCallerClass() {
	::java::lang::Class* callerClass = ::java::lang::CallerHelper::getCallerClass();
	if (callerClass != nullptr) {
		return callerClass;
	}
	return StackWalk::getCallerClass();
}

int32_t Reflection::getClassAccessFlags($Class* c) {
	if ($nullcheck(c)->isPrimitive()) {
		return $Modifier::ABSTRACT | $Modifier::FINAL | $Modifier::PUBLIC;
	}
	#define JVM_ACC_WRITTEN_FLAGS 0x00007FFF
	return c->getModifiers() & JVM_ACC_WRITTEN_FLAGS;
}

void Reflection::ensureMemberAccess($Class* currentClass, $Class* memberClass, $Class* targetClass, int32_t modifiers) {
	$init(Reflection);
	if (!verifyMemberAccess(currentClass, memberClass, targetClass, modifiers)) {
		$throw($(newIllegalAccessException(currentClass, memberClass, targetClass, modifiers)));
	}
}

void Reflection::ensureNativeAccess($Class* currentClass) {
	$init(Reflection);
	$useLocalCurrentObjectStackCache();
	$var($Module, module, $nc(currentClass)->getModule());
	if (!$nc($($SharedSecrets::getJavaLangAccess()))->isEnableNativeAccess(module)) {
		$throwNew($IllegalCallerException, $$str({"Illegal native access from: "_s, module}));
	}
}

bool Reflection::verifyMemberAccess($Class* currentClass, $Class* memberClass, $Class* targetClass, int32_t modifiers) {
	$init(Reflection);
	$Objects::requireNonNull(currentClass);
	$Objects::requireNonNull(memberClass);
	if (currentClass == memberClass) {
		return true;
	}
	if (!verifyModuleAccess($(currentClass->getModule()), memberClass)) {
		return false;
	}
	bool gotIsSameClassPackage = false;
	bool isSameClassPackage = false;
	if (!$Modifier::isPublic(getClassAccessFlags(memberClass))) {
		isSameClassPackage = Reflection::isSameClassPackage(currentClass, memberClass);
		gotIsSameClassPackage = true;
		if (!isSameClassPackage) {
			return false;
		}
	}
	if ($Modifier::isPublic(modifiers)) {
		return true;
	}
	if ($Modifier::isPrivate(modifiers)) {
		if (areNestMates(currentClass, memberClass)) {
			return true;
		}
	}
	bool successSoFar = false;
	if ($Modifier::isProtected(modifiers)) {
		if (isSubclassOf(currentClass, memberClass)) {
			successSoFar = true;
		}
	}
	if (!successSoFar && !$Modifier::isPrivate(modifiers)) {
		if (!gotIsSameClassPackage) {
			isSameClassPackage = Reflection::isSameClassPackage(currentClass, memberClass);
			gotIsSameClassPackage = true;
		}
		if (isSameClassPackage) {
			successSoFar = true;
		}
	}
	if (!successSoFar) {
		return false;
	}
	if (targetClass != nullptr && $Modifier::isProtected(modifiers) && targetClass != currentClass) {
		if (!gotIsSameClassPackage) {
			isSameClassPackage = Reflection::isSameClassPackage(currentClass, memberClass);
			gotIsSameClassPackage = true;
		}
		if (!isSameClassPackage) {
			if (!isSubclassOf(targetClass, currentClass)) {
				return false;
			}
		}
	}
	return true;
}

bool Reflection::verifyPublicMemberAccess($Class* memberClass, int32_t modifiers) {
	$init(Reflection);
	$useLocalCurrentObjectStackCache();
	$var($Module, m, $nc(memberClass)->getModule());
	bool var$1 = $Modifier::isPublic(modifiers);
	bool var$0 = var$1 && $nc(m)->isExported($(memberClass->getPackageName()));
	return var$0 && $Modifier::isPublic(Reflection::getClassAccessFlags(memberClass));
}

bool Reflection::verifyModuleAccess($Module* currentModule, $Class* memberClass) {
	$init(Reflection);
	$useLocalCurrentObjectStackCache();
	$var($Module, memberModule, $nc(memberClass)->getModule());
	if (currentModule == memberModule) {
		return true;
	} else {
		$var($String, pkg, memberClass->getPackageName());
		return $nc(memberModule)->isExported(pkg, currentModule);
	}
}

bool Reflection::isSameClassPackage($Class* c1, $Class* c2) {
	$init(Reflection);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if ($nc(c1)->getClassLoader() != $nc(c2)->getClassLoader()) {
		return false;
	}
	$var($Object, var$0, $of($nc(c1)->getPackageName()));
	return $Objects::equals(var$0, $($nc(c2)->getPackageName()));
}

bool Reflection::isSubclassOf($Class* queryClass, $Class* ofClass) {
	$init(Reflection);
	while (queryClass != nullptr) {
		if (queryClass == ofClass) {
			return true;
		}
		queryClass = queryClass->getSuperclass();
	}
	return false;
}

void Reflection::registerFieldsToFilter($Class* containingClass, $Set* fieldNames) {
	$load(Reflection);
	$synchronized(class$) {
		$init(Reflection);
		$assignStatic(Reflection::fieldFilterMap, registerFilter(Reflection::fieldFilterMap, containingClass, fieldNames));
	}
}

void Reflection::registerMethodsToFilter($Class* containingClass, $Set* methodNames) {
	$load(Reflection);
	$synchronized(class$) {
		$init(Reflection);
		$assignStatic(Reflection::methodFilterMap, registerFilter(Reflection::methodFilterMap, containingClass, methodNames));
	}
}

$Map* Reflection::registerFilter($Map* map$renamed, $Class* containingClass, $Set* names) {
	$init(Reflection);
	$useLocalCurrentObjectStackCache();
	$var($Map, map, map$renamed);
	if ($nc(map)->get(containingClass) != nullptr) {
		$throwNew($IllegalArgumentException, $$str({"Filter already registered: "_s, containingClass}));
	}
	$assign(map, $new($HashMap, map));
	map->put(containingClass, $($Set::copyOf(names)));
	return map;
}

$FieldArray* Reflection::filterFields($Class* containingClass, $FieldArray* fields) {
	$init(Reflection);
	if (Reflection::fieldFilterMap == nullptr) {
		return fields;
	}
	return $fcast($FieldArray, filter($fcast($MemberArray, fields), $cast($Set, $($nc(Reflection::fieldFilterMap)->get(containingClass)))));
}

$MethodArray* Reflection::filterMethods($Class* containingClass, $MethodArray* methods) {
	$init(Reflection);
	if (Reflection::methodFilterMap == nullptr) {
		return methods;
	}
	return $fcast($MethodArray, filter($fcast($MemberArray, methods), $cast($Set, $($nc(Reflection::methodFilterMap)->get(containingClass)))));
}

$MemberArray* Reflection::filter($MemberArray* members, $Set* filteredNames) {
	$init(Reflection);
	$useLocalCurrentObjectStackCache();
	if ((filteredNames == nullptr) || ($nc(members)->length == 0)) {
		return members;
	}
	$Class* memberType = $nc($of($nc(members)->get(0)))->getClass();
	if ($nc(filteredNames)->contains(Reflection::WILDCARD)) {
		return $cast($MemberArray, $1Array::newInstance(memberType, 0));
	}
	int32_t numNewMembers = 0;
	{
		$var($MemberArray, arr$, members);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Member, member, arr$->get(i$));
			{
				if (!$nc(filteredNames)->contains($($nc(member)->getName()))) {
					++numNewMembers;
				}
			}
		}
	}
	$var($MemberArray, newMembers, $cast($MemberArray, $1Array::newInstance(memberType, numNewMembers)));
	int32_t destIdx = 0;
	{
		$var($MemberArray, arr$, members);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Member, member, arr$->get(i$));
			{
				if (!$nc(filteredNames)->contains($($nc(member)->getName()))) {
					newMembers->set(destIdx++, member);
				}
			}
		}
	}
	return newMembers;
}

bool Reflection::isCallerSensitive($Method* m) {
	$init(Reflection);
	$beforeCallerSensitive();
	$var($ClassLoader, loader, $nc($nc(m)->getDeclaringClass())->getClassLoader());
	if ($VM::isSystemDomainLoader(loader)) {
		$load($CallerSensitive);
		return m->isAnnotationPresent($CallerSensitive::class$);
	}
	return false;
}

bool Reflection::isTrustedFinalField($Field* field) {
	$init(Reflection);
	return $nc($($SharedSecrets::getJavaLangReflectAccess()))->isTrustedFinalField(field);
}

$IllegalAccessException* Reflection::newIllegalAccessException($Class* currentClass, $Class* memberClass, $Class* targetClass, int32_t modifiers) {
	$init(Reflection);
	$useLocalCurrentObjectStackCache();
	if (currentClass == nullptr) {
		return newIllegalAccessException(memberClass, modifiers);
	}
	$var($String, currentSuffix, ""_s);
	$var($String, memberSuffix, ""_s);
	$var($Module, m1, $nc(currentClass)->getModule());
	if ($nc(m1)->isNamed()) {
		$assign(currentSuffix, $str({" (in "_s, m1, ")"_s}));
	}
	$var($Module, m2, $nc(memberClass)->getModule());
	if ($nc(m2)->isNamed()) {
		$assign(memberSuffix, $str({" (in "_s, m2, ")"_s}));
	}
	$var($String, memberPackageName, memberClass->getPackageName());
	$var($String, msg, $str({currentClass, currentSuffix, " cannot access "_s}));
	if ($nc(m2)->isExported(memberPackageName, m1)) {
		$var($String, var$1, $$str({"a member of "_s, memberClass, memberSuffix, " with modifiers \""_s}));
		$var($String, var$0, $$concat(var$1, $($Modifier::toString(modifiers))));
		$plusAssign(msg, $$concat(var$0, "\""_s));
	} else {
		$plusAssign(msg, $$str({memberClass, memberSuffix, " because "_s, m2, " does not export "_s, memberPackageName}));
		if (m2->isNamed()) {
			$plusAssign(msg, $$str({" to "_s, m1}));
		}
	}
	return $new($IllegalAccessException, msg);
}

$IllegalAccessException* Reflection::newIllegalAccessException($Class* memberClass, int32_t modifiers) {
	$init(Reflection);
	$useLocalCurrentObjectStackCache();
	$var($String, memberSuffix, ""_s);
	$var($Module, m2, $nc(memberClass)->getModule());
	if ($nc(m2)->isNamed()) {
		$assign(memberSuffix, $str({" (in "_s, m2, ")"_s}));
	}
	$var($String, memberPackageName, memberClass->getPackageName());
	$var($String, msg, "JNI attached native thread (null caller frame) cannot access "_s);
	if ($nc(m2)->isExported(memberPackageName)) {
		$var($String, var$1, $$str({"a member of "_s, memberClass, memberSuffix, " with modifiers \""_s}));
		$var($String, var$0, $$concat(var$1, $($Modifier::toString(modifiers))));
		$plusAssign(msg, $$concat(var$0, "\""_s));
	} else {
		$plusAssign(msg, $$str({memberClass, memberSuffix, " because "_s, m2, " does not export "_s, memberPackageName}));
	}
	return $new($IllegalAccessException, msg);
}

bool Reflection::areNestMates($Class* currentClass, $Class* memberClass) {
	$Class* currentClassNestHost = currentClass->getNestHost();
	$Class* memberClassNestHost = memberClass->getNestHost();
	if (currentClassNestHost != nullptr && currentClassNestHost == memberClassNestHost) {
		return true;
	}
	$var($String, curreentClassName, forLambdaClass(currentClass->name));
	$var($String, memberClassName, forLambdaClass(memberClass->name));
	if (curreentClassName == nullptr) {
		return false;
	}
	return curreentClassName->equals(memberClassName);
}

void clinit$Reflection($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(Reflection::WILDCARD, "*"_s);
	$assignStatic(Reflection::ALL_MEMBERS, $Set::of($of(Reflection::WILDCARD)));
	{
		$var($Object, var$0, $of(Reflection::class$));
		$var($Object, var$1, $of(Reflection::ALL_MEMBERS));
		$load($AccessibleObject);
		$var($Object, var$2, $of($AccessibleObject::class$));
		$var($Object, var$3, $of(Reflection::ALL_MEMBERS));
		$var($Object, var$4, $of($Class::class$));
		$var($Object, var$5, $of($Set::of("classLoader"_s, "classData"_s)));
		$load($ClassLoader);
		$var($Object, var$6, $of($ClassLoader::class$));
		$var($Object, var$7, $of(Reflection::ALL_MEMBERS));
		$load($Constructor);
		$var($Object, var$8, $of($Constructor::class$));
		$var($Object, var$9, $of(Reflection::ALL_MEMBERS));
		$load($Field);
		$var($Object, var$10, $of($Field::class$));
		$var($Object, var$11, $of(Reflection::ALL_MEMBERS));
		$load($Method);
		$var($Object, var$12, $of($Method::class$));
		$var($Object, var$13, $of(Reflection::ALL_MEMBERS));
		$load($Module);
		$var($Object, var$14, $of($Module::class$));
		$var($Object, var$15, $of(Reflection::ALL_MEMBERS));
		$var($Object, var$16, $of($System::class$));
		$assignStatic(Reflection::fieldFilterMap, $Map::of(var$0, var$1, var$2, var$3, var$4, var$5, var$6, var$7, var$8, var$9, var$10, var$11, var$12, var$13, var$14, var$15, var$16, $($Set::of($of("security"_s)))));
		$assignStatic(Reflection::methodFilterMap, $Map::of());
	}
}

Reflection::Reflection() {
}

$Class* Reflection::load$($String* name, bool initialize) {
	$loadClass(Reflection, name, initialize, &_Reflection_ClassInfo_, clinit$Reflection, allocate$Reflection);
	return class$;
}

$Class* Reflection::class$ = nullptr;

		} // reflect
	} // internal
} // jdk