#include <java/net/URLClassLoader$1.h>

#include <java/io/IOException.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/net/URLClassLoader.h>
#include <jdk/internal/loader/Resource.h>
#include <jdk/internal/loader/URLClassPath.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $URLClassLoader = ::java::net::URLClassLoader;
using $Resource = ::jdk::internal::loader::Resource;
using $URLClassPath = ::jdk::internal::loader::URLClassPath;

namespace java {
	namespace net {

$FieldInfo _URLClassLoader$1_FieldInfo_[] = {
	{"this$0", "Ljava/net/URLClassLoader;", nullptr, $FINAL | $SYNTHETIC, $field(URLClassLoader$1, this$0)},
	{"val$name", "Ljava/lang/String;", nullptr, $FINAL | $SYNTHETIC, $field(URLClassLoader$1, val$name)},
	{}
};

$MethodInfo _URLClassLoader$1_MethodInfo_[] = {
	{"<init>", "(Ljava/net/URLClassLoader;Ljava/lang/String;)V", nullptr, 0, $method(URLClassLoader$1, init$, void, $URLClassLoader*, $String*)},
	{"run", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PUBLIC, $virtualMethod(URLClassLoader$1, run, $Object*), "java.lang.ClassNotFoundException"},
	{}
};

$EnclosingMethodInfo _URLClassLoader$1_EnclosingMethodInfo_ = {
	"java.net.URLClassLoader",
	"findClass",
	"(Ljava/lang/String;)Ljava/lang/Class;"
};

$InnerClassInfo _URLClassLoader$1_InnerClassesInfo_[] = {
	{"java.net.URLClassLoader$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _URLClassLoader$1_ClassInfo_ = {
	$ACC_SUPER,
	"java.net.URLClassLoader$1",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	_URLClassLoader$1_FieldInfo_,
	_URLClassLoader$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedExceptionAction<Ljava/lang/Class<*>;>;",
	&_URLClassLoader$1_EnclosingMethodInfo_,
	_URLClassLoader$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.net.URLClassLoader"
};

$Object* allocate$URLClassLoader$1($Class* clazz) {
	return $of($alloc(URLClassLoader$1));
}

void URLClassLoader$1::init$($URLClassLoader* this$0, $String* val$name) {
	$set(this, this$0, this$0);
	$set(this, val$name, val$name);
}

$Object* URLClassLoader$1::run() {
	$useLocalCurrentObjectStackCache();
	$var($String, path, $($nc(this->val$name)->replace(u'.', u'/'))->concat(".class"_s));
	$var($Resource, res, $nc(this->this$0->ucp)->getResource(path, false));
	if (res != nullptr) {
		try {
			return $of(this->this$0->defineClass(this->val$name, res));
		} catch ($IOException& e) {
			$throwNew($ClassNotFoundException, this->val$name, e);
		}
	} else {
		return $of(nullptr);
	}
}

URLClassLoader$1::URLClassLoader$1() {
}

$Class* URLClassLoader$1::load$($String* name, bool initialize) {
	$loadClass(URLClassLoader$1, name, initialize, &_URLClassLoader$1_ClassInfo_, allocate$URLClassLoader$1);
	return class$;
}

$Class* URLClassLoader$1::class$ = nullptr;

	} // net
} // java