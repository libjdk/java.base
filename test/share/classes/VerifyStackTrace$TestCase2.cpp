#include <VerifyStackTrace$TestCase2.h>

#include <VerifyStackTrace.h>
#include <java/lang/Enum.h>
#include <java/lang/StackWalker$Option.h>
#include <java/lang/StackWalker.h>
#include <java/util/EnumSet.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef RETAIN_CLASS_REFERENCE
#undef SHOW_REFLECT_FRAMES

using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $StackWalker = ::java::lang::StackWalker;
using $StackWalker$Option = ::java::lang::StackWalker$Option;
using $EnumSet = ::java::util::EnumSet;
using $Set = ::java::util::Set;

$FieldInfo _VerifyStackTrace$TestCase2_FieldInfo_[] = {
	{"walker", "Ljava/lang/StackWalker;", nullptr, $PRIVATE | $FINAL, $field(VerifyStackTrace$TestCase2, walker$)},
	{"description", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(VerifyStackTrace$TestCase2, description$)},
	{"expected", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(VerifyStackTrace$TestCase2, expected$)},
	{}
};

$MethodInfo _VerifyStackTrace$TestCase2_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(VerifyStackTrace$TestCase2, init$, void)},
	{"description", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(VerifyStackTrace$TestCase2, description, $String*)},
	{"expected", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(VerifyStackTrace$TestCase2, expected, $String*)},
	{"walker", "()Ljava/lang/StackWalker;", nullptr, $PUBLIC, $virtualMethod(VerifyStackTrace$TestCase2, walker, $StackWalker*)},
	{}
};

$InnerClassInfo _VerifyStackTrace$TestCase2_InnerClassesInfo_[] = {
	{"VerifyStackTrace$TestCase2", "VerifyStackTrace", "TestCase2", $STATIC | $FINAL},
	{"VerifyStackTrace$TestCase", "VerifyStackTrace", "TestCase", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _VerifyStackTrace$TestCase2_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"VerifyStackTrace$TestCase2",
	"java.lang.Object",
	"VerifyStackTrace$TestCase",
	_VerifyStackTrace$TestCase2_FieldInfo_,
	_VerifyStackTrace$TestCase2_MethodInfo_,
	nullptr,
	nullptr,
	_VerifyStackTrace$TestCase2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"VerifyStackTrace"
};

$Object* allocate$VerifyStackTrace$TestCase2($Class* clazz) {
	return $of($alloc(VerifyStackTrace$TestCase2));
}

void VerifyStackTrace$TestCase2::init$() {
	$init($StackWalker$Option);
	$set(this, walker$, $StackWalker::getInstance($(static_cast<$Set*>($EnumSet::of(static_cast<$Enum*>($StackWalker$Option::RETAIN_CLASS_REFERENCE), static_cast<$Enum*>($StackWalker$Option::SHOW_REFLECT_FRAMES))))));
	$set(this, description$, "nStackWalker.getInstance(StackWalker.Option.RETAIN_CLASS_REFERENCE, StackWalker.Option.SHOW_REFLECT_FRAMES)"_s);
	$set(this, expected$, "1: VerifyStackTrace.lambda$test$1(VerifyStackTrace.java:211)\n2: VerifyStackTrace$Handle.execute(VerifyStackTrace.java:147)\n3: VerifyStackTrace$Handle.run(VerifyStackTrace.java:160)\n4: VerifyStackTrace.invoke(VerifyStackTrace.java:190)\n5: java.base/jdk.internal.reflect.NativeMethodAccessorImpl.invoke0(Native Method)\n6: java.base/jdk.internal.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:62)\n7: java.base/jdk.internal.reflect.DelegatingMethodAccessorImpl.invoke(DelegatingMethodAccessorImpl.java:43)\n8: java.base/java.lang.reflect.Method.invoke(Method.java:520)\n9: VerifyStackTrace$1.run(VerifyStackTrace.java:220)\n10: java.base/java.security.AccessController.doPrivileged(AccessController.java:310)\n11: VerifyStackTrace.test(VerifyStackTrace.java:229)\n12: VerifyStackTrace.main(VerifyStackTrace.java:185)\n"_s);
}

$StackWalker* VerifyStackTrace$TestCase2::walker() {
	return this->walker$;
}

$String* VerifyStackTrace$TestCase2::description() {
	return this->description$;
}

$String* VerifyStackTrace$TestCase2::expected() {
	return this->expected$;
}

VerifyStackTrace$TestCase2::VerifyStackTrace$TestCase2() {
}

$Class* VerifyStackTrace$TestCase2::load$($String* name, bool initialize) {
	$loadClass(VerifyStackTrace$TestCase2, name, initialize, &_VerifyStackTrace$TestCase2_ClassInfo_, allocate$VerifyStackTrace$TestCase2);
	return class$;
}

$Class* VerifyStackTrace$TestCase2::class$ = nullptr;