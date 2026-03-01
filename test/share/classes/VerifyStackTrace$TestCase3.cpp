#include <VerifyStackTrace$TestCase3.h>

#include <VerifyStackTrace.h>
#include <java/lang/Enum.h>
#include <java/lang/StackWalker$Option.h>
#include <java/lang/StackWalker.h>
#include <java/util/EnumSet.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef RETAIN_CLASS_REFERENCE
#undef SHOW_HIDDEN_FRAMES

using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $StackWalker = ::java::lang::StackWalker;
using $StackWalker$Option = ::java::lang::StackWalker$Option;
using $EnumSet = ::java::util::EnumSet;
using $Set = ::java::util::Set;

$FieldInfo _VerifyStackTrace$TestCase3_FieldInfo_[] = {
	{"walker", "Ljava/lang/StackWalker;", nullptr, $PRIVATE | $FINAL, $field(VerifyStackTrace$TestCase3, walker$)},
	{"description", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(VerifyStackTrace$TestCase3, description$)},
	{"expected", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(VerifyStackTrace$TestCase3, expected$)},
	{}
};

$MethodInfo _VerifyStackTrace$TestCase3_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(VerifyStackTrace$TestCase3, init$, void)},
	{"description", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(VerifyStackTrace$TestCase3, description, $String*)},
	{"expected", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(VerifyStackTrace$TestCase3, expected, $String*)},
	{"walker", "()Ljava/lang/StackWalker;", nullptr, $PUBLIC, $virtualMethod(VerifyStackTrace$TestCase3, walker, $StackWalker*)},
	{}
};

$InnerClassInfo _VerifyStackTrace$TestCase3_InnerClassesInfo_[] = {
	{"VerifyStackTrace$TestCase3", "VerifyStackTrace", "TestCase3", $STATIC},
	{"VerifyStackTrace$TestCase", "VerifyStackTrace", "TestCase", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _VerifyStackTrace$TestCase3_ClassInfo_ = {
	$ACC_SUPER,
	"VerifyStackTrace$TestCase3",
	"java.lang.Object",
	"VerifyStackTrace$TestCase",
	_VerifyStackTrace$TestCase3_FieldInfo_,
	_VerifyStackTrace$TestCase3_MethodInfo_,
	nullptr,
	nullptr,
	_VerifyStackTrace$TestCase3_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"VerifyStackTrace"
};

$Object* allocate$VerifyStackTrace$TestCase3($Class* clazz) {
	return $of($alloc(VerifyStackTrace$TestCase3));
}

void VerifyStackTrace$TestCase3::init$() {
	$init($StackWalker$Option);
	$set(this, walker$, $StackWalker::getInstance($(static_cast<$Set*>($EnumSet::of(static_cast<$Enum*>($StackWalker$Option::RETAIN_CLASS_REFERENCE), static_cast<$Enum*>($StackWalker$Option::SHOW_HIDDEN_FRAMES))))));
	$set(this, description$, "StackWalker.getInstance(StackWalker.Option.RETAIN_CLASS_REFERENCE, StackWalker.Option.SHOW_HIDDEN_FRAMES)"_s);
	$set(this, expected$, "1: VerifyStackTrace.lambda$test$1(VerifyStackTrace.java:213)\n2: VerifyStackTrace$$Lambda$1/0x00000007c0089430.run(Unknown Source)\n3: VerifyStackTrace$Handle.execute(VerifyStackTrace.java:149)\n4: java.base/java.lang.invoke.LambdaForm$DMH/0x00000007c008a830.invokeVirtual_LL_V(LambdaForm$DMH)\n5: java.base/java.lang.invoke.LambdaForm$MH/0x00000007c008a830.invoke_MT(LambdaForm$MH)\n6: VerifyStackTrace$Handle.run(VerifyStackTrace.java:162)\n7: VerifyStackTrace.invoke(VerifyStackTrace.java:192)\n8: java.base/jdk.internal.reflect.NativeMethodAccessorImpl.invoke0(Native Method)\n9: java.base/jdk.internal.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:62)\n10: java.base/jdk.internal.reflect.DelegatingMethodAccessorImpl.invoke(DelegatingMethodAccessorImpl.java:43)\n11: java.base/java.lang.reflect.Method.invoke(Method.java:520)\n12: VerifyStackTrace$1.run(VerifyStackTrace.java:222)\n13: java.base/java.security.AccessController.executePrivileged(AccessController.java:759)\n14: java.base/java.security.AccessC"
		"ontroller.doPrivileged(AccessController.java:310)\n15: VerifyStackTrace.test(VerifyStackTrace.java:231)\n16: VerifyStackTrace.main(VerifyStackTrace.java:188)\n"_s);
}

$StackWalker* VerifyStackTrace$TestCase3::walker() {
	return this->walker$;
}

$String* VerifyStackTrace$TestCase3::description() {
	return this->description$;
}

$String* VerifyStackTrace$TestCase3::expected() {
	return this->expected$;
}

VerifyStackTrace$TestCase3::VerifyStackTrace$TestCase3() {
}

$Class* VerifyStackTrace$TestCase3::load$($String* name, bool initialize) {
	$loadClass(VerifyStackTrace$TestCase3, name, initialize, &_VerifyStackTrace$TestCase3_ClassInfo_, allocate$VerifyStackTrace$TestCase3);
	return class$;
}

$Class* VerifyStackTrace$TestCase3::class$ = nullptr;