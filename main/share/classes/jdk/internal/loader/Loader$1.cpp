#include <jdk/internal/loader/Loader$1.h>

#include <java/lang/module/ModuleReader.h>
#include <java/lang/module/ModuleReference.h>
#include <java/net/MalformedURLException.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/util/Optional.h>
#include <jdk/internal/loader/Loader.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ModuleReader = ::java::lang::module::ModuleReader;
using $ModuleReference = ::java::lang::module::ModuleReference;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URI = ::java::net::URI;
using $Optional = ::java::util::Optional;
using $Loader = ::jdk::internal::loader::Loader;

namespace jdk {
	namespace internal {
		namespace loader {

$FieldInfo _Loader$1_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/loader/Loader;", nullptr, $FINAL | $SYNTHETIC, $field(Loader$1, this$0)},
	{"val$name", "Ljava/lang/String;", nullptr, $FINAL | $SYNTHETIC, $field(Loader$1, val$name)},
	{"val$mref", "Ljava/lang/module/ModuleReference;", nullptr, $FINAL | $SYNTHETIC, $field(Loader$1, val$mref)},
	{}
};

$MethodInfo _Loader$1_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/loader/Loader;Ljava/lang/module/ModuleReference;Ljava/lang/String;)V", "()V", 0, $method(Loader$1, init$, void, $Loader*, $ModuleReference*, $String*)},
	{"run", "()Ljava/net/URL;", nullptr, $PUBLIC, $virtualMethod(Loader$1, run, $Object*), "java.io.IOException"},
	{}
};

$EnclosingMethodInfo _Loader$1_EnclosingMethodInfo_ = {
	"jdk.internal.loader.Loader",
	"findResource",
	"(Ljava/lang/String;Ljava/lang/String;)Ljava/net/URL;"
};

$InnerClassInfo _Loader$1_InnerClassesInfo_[] = {
	{"jdk.internal.loader.Loader$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Loader$1_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.loader.Loader$1",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	_Loader$1_FieldInfo_,
	_Loader$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedExceptionAction<Ljava/net/URL;>;",
	&_Loader$1_EnclosingMethodInfo_,
	_Loader$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.loader.Loader"
};

$Object* allocate$Loader$1($Class* clazz) {
	return $of($alloc(Loader$1));
}

void Loader$1::init$($Loader* this$0, $ModuleReference* val$mref, $String* val$name) {
	$set(this, this$0, this$0);
	$set(this, val$mref, val$mref);
	$set(this, val$name, val$name);
}

$Object* Loader$1::run() {
	$useLocalCurrentObjectStackCache();
	$var($Optional, ouri, $nc($(this->this$0->moduleReaderFor(this->val$mref)))->find(this->val$name));
	if ($nc(ouri)->isPresent()) {
		try {
			return $of($nc(($cast($URI, $(ouri->get()))))->toURL());
		} catch ($MalformedURLException& e) {
		} catch ($IllegalArgumentException& e) {
		}
	}
	return $of(nullptr);
}

Loader$1::Loader$1() {
}

$Class* Loader$1::load$($String* name, bool initialize) {
	$loadClass(Loader$1, name, initialize, &_Loader$1_ClassInfo_, allocate$Loader$1);
	return class$;
}

$Class* Loader$1::class$ = nullptr;

		} // loader
	} // internal
} // jdk