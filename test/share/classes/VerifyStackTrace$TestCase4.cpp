#include <VerifyStackTrace$TestCase4.h>

#include <VerifyStackTrace$TestCase3.h>
#include <VerifyStackTrace.h>
#include <java/lang/StackWalker$Option.h>
#include <java/lang/StackWalker.h>
#include <java/util/EnumSet.h>
#include <java/util/Set.h>
#include <jcpp.h>

using $VerifyStackTrace$TestCase3 = ::VerifyStackTrace$TestCase3;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $StackWalker = ::java::lang::StackWalker;
using $StackWalker$Option = ::java::lang::StackWalker$Option;
using $EnumSet = ::java::util::EnumSet;
using $Set = ::java::util::Set;

$FieldInfo _VerifyStackTrace$TestCase4_FieldInfo_[] = {
	{"walker", "Ljava/lang/StackWalker;", nullptr, $PRIVATE | $FINAL, $field(VerifyStackTrace$TestCase4, walker$)},
	{"description", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(VerifyStackTrace$TestCase4, description$)},
	{}
};

$MethodInfo _VerifyStackTrace$TestCase4_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(VerifyStackTrace$TestCase4, init$, void)},
	{"description", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(VerifyStackTrace$TestCase4, description, $String*)},
	{"walker", "()Ljava/lang/StackWalker;", nullptr, $PUBLIC, $virtualMethod(VerifyStackTrace$TestCase4, walker, $StackWalker*)},
	{}
};

$InnerClassInfo _VerifyStackTrace$TestCase4_InnerClassesInfo_[] = {
	{"VerifyStackTrace$TestCase4", "VerifyStackTrace", "TestCase4", $STATIC | $FINAL},
	{"VerifyStackTrace$TestCase3", "VerifyStackTrace", "TestCase3", $STATIC},
	{}
};

$ClassInfo _VerifyStackTrace$TestCase4_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"VerifyStackTrace$TestCase4",
	"VerifyStackTrace$TestCase3",
	nullptr,
	_VerifyStackTrace$TestCase4_FieldInfo_,
	_VerifyStackTrace$TestCase4_MethodInfo_,
	nullptr,
	nullptr,
	_VerifyStackTrace$TestCase4_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"VerifyStackTrace"
};

$Object* allocate$VerifyStackTrace$TestCase4($Class* clazz) {
	return $of($alloc(VerifyStackTrace$TestCase4));
}

void VerifyStackTrace$TestCase4::init$() {
	$VerifyStackTrace$TestCase3::init$();
	$load($StackWalker$Option);
	$set(this, walker$, $StackWalker::getInstance($(static_cast<$Set*>($EnumSet::allOf($StackWalker$Option::class$)))));
	$set(this, description$, "StackWalker.getInstance(StackWalker.Option.RETAIN_CLASS_REFERENCE, StackWalker.Option.SHOW_HIDDEN_FRAMES, StackWalker.Option.SHOW_REFLECT_FRAMES)"_s);
}

$StackWalker* VerifyStackTrace$TestCase4::walker() {
	return this->walker$;
}

$String* VerifyStackTrace$TestCase4::description() {
	return this->description$;
}

VerifyStackTrace$TestCase4::VerifyStackTrace$TestCase4() {
}

$Class* VerifyStackTrace$TestCase4::load$($String* name, bool initialize) {
	$loadClass(VerifyStackTrace$TestCase4, name, initialize, &_VerifyStackTrace$TestCase4_ClassInfo_, allocate$VerifyStackTrace$TestCase4);
	return class$;
}

$Class* VerifyStackTrace$TestCase4::class$ = nullptr;