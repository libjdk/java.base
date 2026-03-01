#include <util/MemberFactory$Kind$2.h>

#include <java/lang/AssertionError.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/reflect/AccessibleObject.h>
#include <java/lang/reflect/Method.h>
#include <util/MemberFactory$Kind.h>
#include <util/MemberFactory.h>
#include <jcpp.h>

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $RuntimeException = ::java::lang::RuntimeException;
using $AccessibleObject = ::java::lang::reflect::AccessibleObject;
using $MemberFactory = ::util::MemberFactory;
using $MemberFactory$Kind = ::util::MemberFactory$Kind;

namespace util {

$FieldInfo _MemberFactory$Kind$2_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(MemberFactory$Kind$2, $assertionsDisabled)},
	{}
};

$MethodInfo _MemberFactory$Kind$2_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;I)V", nullptr, $PRIVATE, $method(MemberFactory$Kind$2, init$, void, $String*, int32_t)},
	{"apply", "(Ljava/lang/Class;Lutil/MemberFactory;)Ljava/lang/reflect/AccessibleObject;", "(Ljava/lang/Class<*>;Lutil/MemberFactory;)Ljava/lang/reflect/AccessibleObject;", $PUBLIC, $method(MemberFactory$Kind$2, apply, $AccessibleObject*, $Class*, $MemberFactory*)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(MemberFactory$Kind$2, apply, $Object*, Object$*, Object$*)},
	{}
};

$EnclosingMethodInfo _MemberFactory$Kind$2_EnclosingMethodInfo_ = {
	"util.MemberFactory$Kind",
	nullptr,
	nullptr
};

$InnerClassInfo _MemberFactory$Kind$2_InnerClassesInfo_[] = {
	{"util.MemberFactory$Kind", "util.MemberFactory", "Kind", $STATIC | $ABSTRACT | $ENUM},
	{"util.MemberFactory$Kind$2", nullptr, nullptr, $FINAL | $ENUM},
	{}
};

$ClassInfo _MemberFactory$Kind$2_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"util.MemberFactory$Kind$2",
	"util.MemberFactory$Kind",
	nullptr,
	_MemberFactory$Kind$2_FieldInfo_,
	_MemberFactory$Kind$2_MethodInfo_,
	nullptr,
	&_MemberFactory$Kind$2_EnclosingMethodInfo_,
	_MemberFactory$Kind$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"util.MemberFactory"
};

$Object* allocate$MemberFactory$Kind$2($Class* clazz) {
	return $of($alloc(MemberFactory$Kind$2));
}

bool MemberFactory$Kind$2::$assertionsDisabled = false;

void MemberFactory$Kind$2::init$($String* $enum$name, int32_t $enum$ordinal) {
	$MemberFactory$Kind::init$($enum$name, $enum$ordinal);
}

$AccessibleObject* MemberFactory$Kind$2::apply($Class* declaringClass, $MemberFactory* factory) {
	$beforeCallerSensitive();
	if (!MemberFactory$Kind$2::$assertionsDisabled && !$equals($nc(factory)->kind, this)) {
		$throwNew($AssertionError);
	}
	try {
		return $nc(declaringClass)->getDeclaredMethod($nc(factory)->name$, factory->parameterTypes);
	} catch ($NoSuchMethodException& e) {
		$throwNew($RuntimeException, $(e->getMessage()));
	}
	$shouldNotReachHere();
}

$Object* MemberFactory$Kind$2::apply(Object$* declaringClass, Object$* factory) {
	return $of(this->apply($cast($Class, declaringClass), $cast($MemberFactory, factory)));
}

void clinit$MemberFactory$Kind$2($Class* class$) {
	$load($MemberFactory);
	MemberFactory$Kind$2::$assertionsDisabled = !$MemberFactory::class$->desiredAssertionStatus();
}

MemberFactory$Kind$2::MemberFactory$Kind$2() {
}

$Class* MemberFactory$Kind$2::load$($String* name, bool initialize) {
	$loadClass(MemberFactory$Kind$2, name, initialize, &_MemberFactory$Kind$2_ClassInfo_, clinit$MemberFactory$Kind$2, allocate$MemberFactory$Kind$2);
	return class$;
}

$Class* MemberFactory$Kind$2::class$ = nullptr;

} // util