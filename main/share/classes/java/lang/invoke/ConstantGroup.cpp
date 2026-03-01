#include <java/lang/invoke/ConstantGroup.h>

#include <java/lang/AssertionError.h>
#include <java/lang/invoke/AbstractConstantGroup$AsList.h>
#include <java/lang/invoke/AbstractConstantGroup$SubGroup.h>
#include <java/lang/invoke/AbstractConstantGroup$WithCache.h>
#include <java/lang/invoke/ConstantGroup$1.h>
#include <java/lang/invoke/ConstantGroup$1Impl.h>
#include <java/util/List.h>
#include <java/util/function/IntFunction.h>
#include <jcpp.h>

#undef NOT_PRESENT
#undef NP

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractConstantGroup$AsList = ::java::lang::invoke::AbstractConstantGroup$AsList;
using $AbstractConstantGroup$SubGroup = ::java::lang::invoke::AbstractConstantGroup$SubGroup;
using $AbstractConstantGroup$WithCache = ::java::lang::invoke::AbstractConstantGroup$WithCache;
using $ConstantGroup$1 = ::java::lang::invoke::ConstantGroup$1;
using $ConstantGroup$1Impl = ::java::lang::invoke::ConstantGroup$1Impl;
using $List = ::java::util::List;
using $IntFunction = ::java::util::function::IntFunction;

namespace java {
	namespace lang {
		namespace invoke {

$MethodInfo _ConstantGroup_MethodInfo_[] = {
	{"asList", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/Object;>;", $PUBLIC, $virtualMethod(ConstantGroup, asList, $List*)},
	{"asList", "(Ljava/lang/Object;)Ljava/util/List;", "(Ljava/lang/Object;)Ljava/util/List<Ljava/lang/Object;>;", $PUBLIC, $virtualMethod(ConstantGroup, asList, $List*, Object$*)},
	{"copyConstants", "(II[Ljava/lang/Object;I)I", nullptr, $PUBLIC, $virtualMethod(ConstantGroup, copyConstants, int32_t, int32_t, int32_t, $ObjectArray*, int32_t), "java.lang.LinkageError"},
	{"copyConstants", "(II[Ljava/lang/Object;ILjava/lang/Object;)I", nullptr, $PUBLIC, $virtualMethod(ConstantGroup, copyConstants, int32_t, int32_t, int32_t, $ObjectArray*, int32_t, Object$*)},
	{"get", "(I)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ConstantGroup, get, $Object*, int32_t), "java.lang.LinkageError"},
	{"get", "(ILjava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ConstantGroup, get, $Object*, int32_t, Object$*)},
	{"isPresent", "(I)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ConstantGroup, isPresent, bool, int32_t)},
	{"makeConstantGroup", "(Ljava/util/List;Ljava/lang/Object;Ljava/util/function/IntFunction;)Ljava/lang/invoke/ConstantGroup;", "(Ljava/util/List<Ljava/lang/Object;>;Ljava/lang/Object;Ljava/util/function/IntFunction<Ljava/lang/Object;>;)Ljava/lang/invoke/ConstantGroup;", $PUBLIC | $STATIC, $staticMethod(ConstantGroup, makeConstantGroup, ConstantGroup*, $List*, Object$*, $IntFunction*)},
	{"makeConstantGroup", "(Ljava/util/List;)Ljava/lang/invoke/ConstantGroup;", "(Ljava/util/List<Ljava/lang/Object;>;)Ljava/lang/invoke/ConstantGroup;", $PUBLIC | $STATIC, $staticMethod(ConstantGroup, makeConstantGroup, ConstantGroup*, $List*)},
	{"size", "()I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ConstantGroup, size, int32_t)},
	{"subGroup", "(II)Ljava/lang/invoke/ConstantGroup;", nullptr, $PUBLIC, $virtualMethod(ConstantGroup, subGroup, ConstantGroup*, int32_t, int32_t)},
	{}
};

$InnerClassInfo _ConstantGroup_InnerClassesInfo_[] = {
	{"java.lang.invoke.ConstantGroup$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"java.lang.invoke.ConstantGroup$1Impl", nullptr, "Impl", 0},
	{}
};

$ClassInfo _ConstantGroup_ClassInfo_ = {
	$INTERFACE | $ABSTRACT,
	"java.lang.invoke.ConstantGroup",
	nullptr,
	nullptr,
	nullptr,
	_ConstantGroup_MethodInfo_,
	nullptr,
	nullptr,
	_ConstantGroup_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.invoke.ConstantGroup$1,java.lang.invoke.ConstantGroup$1Impl"
};

$Object* allocate$ConstantGroup($Class* clazz) {
	return $of($alloc(ConstantGroup));
}

$List* ConstantGroup::asList() {
	return $new($AbstractConstantGroup$AsList, this, 0, size());
}

$List* ConstantGroup::asList(Object$* ifNotPresent) {
	return $new($AbstractConstantGroup$AsList, this, 0, size(), ifNotPresent);
}

ConstantGroup* ConstantGroup::subGroup(int32_t start, int32_t end) {
	return $new($AbstractConstantGroup$SubGroup, this, start, end);
}

int32_t ConstantGroup::copyConstants(int32_t start, int32_t end, $ObjectArray* buf, int32_t pos) {
	$useLocalCurrentObjectStackCache();
	int32_t bufBase = pos - start;
	for (int32_t i = start; i < end; ++i) {
		$nc(buf)->set(bufBase + i, $(get(i)));
	}
	return end;
}

int32_t ConstantGroup::copyConstants(int32_t start, int32_t end, $ObjectArray* buf, int32_t pos, Object$* ifNotPresent) {
	$useLocalCurrentObjectStackCache();
	int32_t bufBase = pos - start;
	for (int32_t i = start; i < end; ++i) {
		$nc(buf)->set(bufBase + i, $(get(i, ifNotPresent)));
	}
	return end;
}

ConstantGroup* ConstantGroup::makeConstantGroup($List* constants, Object$* ifNotPresent, $IntFunction* constantProvider) {
	$init(ConstantGroup);
	{
	}
	return $new($ConstantGroup$1Impl, constants, ifNotPresent, constantProvider);
}

ConstantGroup* ConstantGroup::makeConstantGroup($List* constants) {
	$init(ConstantGroup);
	$init($AbstractConstantGroup$WithCache);
	$var($Object, NP, $AbstractConstantGroup$WithCache::NOT_PRESENT);
	$init($ConstantGroup$1);
	if (!$ConstantGroup$1::$assertionsDisabled && !(!$nc(constants)->contains(NP))) {
		$throwNew($AssertionError);
	}
	return makeConstantGroup(constants, NP, nullptr);
}

void clinit$ConstantGroup($Class* class$) {
	{
		$init($ConstantGroup$1);
		if ($ConstantGroup$1::$assertionsDisabled) {
		}
	}
}

$Class* ConstantGroup::load$($String* name, bool initialize) {
	$loadClass(ConstantGroup, name, initialize, &_ConstantGroup_ClassInfo_, clinit$ConstantGroup, allocate$ConstantGroup);
	return class$;
}

$Class* ConstantGroup::class$ = nullptr;

		} // invoke
	} // lang
} // java