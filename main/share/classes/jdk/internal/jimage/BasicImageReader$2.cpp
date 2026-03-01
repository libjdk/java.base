#include <jdk/internal/jimage/BasicImageReader$2.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/lang/reflect/Method.h>
#include <java/nio/channels/FileChannel.h>
#include <jdk/internal/jimage/BasicImageReader.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $Method = ::java::lang::reflect::Method;
using $BasicImageReader = ::jdk::internal::jimage::BasicImageReader;

namespace jdk {
	namespace internal {
		namespace jimage {

$FieldInfo _BasicImageReader$2_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/jimage/BasicImageReader;", nullptr, $FINAL | $SYNTHETIC, $field(BasicImageReader$2, this$0)},
	{}
};

$MethodInfo _BasicImageReader$2_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/jimage/BasicImageReader;)V", nullptr, 0, $method(BasicImageReader$2, init$, void, $BasicImageReader*)},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC, $virtualMethod(BasicImageReader$2, run, $Object*)},
	{}
};

$EnclosingMethodInfo _BasicImageReader$2_EnclosingMethodInfo_ = {
	"jdk.internal.jimage.BasicImageReader",
	"<init>",
	"(Ljava/nio/file/Path;Ljava/nio/ByteOrder;)V"
};

$InnerClassInfo _BasicImageReader$2_InnerClassesInfo_[] = {
	{"jdk.internal.jimage.BasicImageReader$2", nullptr, nullptr, 0},
	{}
};

$ClassInfo _BasicImageReader$2_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.jimage.BasicImageReader$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_BasicImageReader$2_FieldInfo_,
	_BasicImageReader$2_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Void;>;",
	&_BasicImageReader$2_EnclosingMethodInfo_,
	_BasicImageReader$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.jimage.BasicImageReader"
};

$Object* allocate$BasicImageReader$2($Class* clazz) {
	return $of($alloc(BasicImageReader$2));
}

void BasicImageReader$2::init$($BasicImageReader* this$0) {
	$set(this, this$0, this$0);
}

$Object* BasicImageReader$2::run() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$load($BasicImageReader);
	if ($BasicImageReader::class$->getClassLoader() == nullptr) {
		try {
			$Class* fileChannelImpl = $Class::forName("sun.nio.ch.FileChannelImpl"_s);
			$var($Method, setUninterruptible, $nc(fileChannelImpl)->getMethod("setUninterruptible"_s, $$new($ClassArray, 0)));
			$nc(setUninterruptible)->invoke(this->this$0->channel, $$new($ObjectArray, 0));
		} catch ($ClassNotFoundException& ex) {
		} catch ($NoSuchMethodException& ex) {
		} catch ($IllegalAccessException& ex) {
		} catch ($InvocationTargetException& ex) {
		}
	}
	return $of(nullptr);
}

BasicImageReader$2::BasicImageReader$2() {
}

$Class* BasicImageReader$2::load$($String* name, bool initialize) {
	$loadClass(BasicImageReader$2, name, initialize, &_BasicImageReader$2_ClassInfo_, allocate$BasicImageReader$2);
	return class$;
}

$Class* BasicImageReader$2::class$ = nullptr;

		} // jimage
	} // internal
} // jdk