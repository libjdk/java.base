#include <jdk/internal/reflect/MethodAccessorGenerator$1.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/InternalError.h>
#include <java/lang/ReflectiveOperationException.h>
#include <jdk/internal/reflect/ClassDefiner.h>
#include <jdk/internal/reflect/MagicAccessorImpl.h>
#include <jdk/internal/reflect/MethodAccessorGenerator.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationException = ::java::lang::InstantiationException;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $ClassDefiner = ::jdk::internal::reflect::ClassDefiner;
using $MagicAccessorImpl = ::jdk::internal::reflect::MagicAccessorImpl;
using $MethodAccessorGenerator = ::jdk::internal::reflect::MethodAccessorGenerator;

namespace jdk {
	namespace internal {
		namespace reflect {

$FieldInfo _MethodAccessorGenerator$1_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/reflect/MethodAccessorGenerator;", nullptr, $FINAL | $SYNTHETIC, $field(MethodAccessorGenerator$1, this$0)},
	{"val$declaringClass", "Ljava/lang/Class;", nullptr, $FINAL | $SYNTHETIC, $field(MethodAccessorGenerator$1, val$declaringClass)},
	{"val$bytes", "[B", nullptr, $FINAL | $SYNTHETIC, $field(MethodAccessorGenerator$1, val$bytes)},
	{"val$generatedName", "Ljava/lang/String;", nullptr, $FINAL | $SYNTHETIC, $field(MethodAccessorGenerator$1, val$generatedName)},
	{}
};

$MethodInfo _MethodAccessorGenerator$1_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/reflect/MethodAccessorGenerator;Ljava/lang/String;[BLjava/lang/Class;)V", "()V", 0, $method(MethodAccessorGenerator$1, init$, void, $MethodAccessorGenerator*, $String*, $bytes*, $Class*)},
	{"run", "()Ljdk/internal/reflect/MagicAccessorImpl;", nullptr, $PUBLIC, $virtualMethod(MethodAccessorGenerator$1, run, $Object*)},
	{}
};

$EnclosingMethodInfo _MethodAccessorGenerator$1_EnclosingMethodInfo_ = {
	"jdk.internal.reflect.MethodAccessorGenerator",
	"generate",
	"(Ljava/lang/Class;Ljava/lang/String;[Ljava/lang/Class;Ljava/lang/Class;[Ljava/lang/Class;IZZLjava/lang/Class;)Ljdk/internal/reflect/MagicAccessorImpl;"
};

$InnerClassInfo _MethodAccessorGenerator$1_InnerClassesInfo_[] = {
	{"jdk.internal.reflect.MethodAccessorGenerator$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _MethodAccessorGenerator$1_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.reflect.MethodAccessorGenerator$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_MethodAccessorGenerator$1_FieldInfo_,
	_MethodAccessorGenerator$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljdk/internal/reflect/MagicAccessorImpl;>;",
	&_MethodAccessorGenerator$1_EnclosingMethodInfo_,
	_MethodAccessorGenerator$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.reflect.MethodAccessorGenerator"
};

$Object* allocate$MethodAccessorGenerator$1($Class* clazz) {
	return $of($alloc(MethodAccessorGenerator$1));
}

void MethodAccessorGenerator$1::init$($MethodAccessorGenerator* this$0, $String* val$generatedName, $bytes* val$bytes, $Class* val$declaringClass) {
	$set(this, this$0, this$0);
	$set(this, val$generatedName, val$generatedName);
	$set(this, val$bytes, val$bytes);
	$set(this, val$declaringClass, val$declaringClass);
}

$Object* MethodAccessorGenerator$1::run() {
	$beforeCallerSensitive();
	try {
		return $of($cast($MagicAccessorImpl, $nc($ClassDefiner::defineClass(this->val$generatedName, this->val$bytes, 0, $nc(this->val$bytes)->length, $($nc(this->val$declaringClass)->getClassLoader())))->newInstance()));
	} catch ($InstantiationException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	} catch ($IllegalAccessException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

MethodAccessorGenerator$1::MethodAccessorGenerator$1() {
}

$Class* MethodAccessorGenerator$1::load$($String* name, bool initialize) {
	$loadClass(MethodAccessorGenerator$1, name, initialize, &_MethodAccessorGenerator$1_ClassInfo_, allocate$MethodAccessorGenerator$1);
	return class$;
}

$Class* MethodAccessorGenerator$1::class$ = nullptr;

		} // reflect
	} // internal
} // jdk