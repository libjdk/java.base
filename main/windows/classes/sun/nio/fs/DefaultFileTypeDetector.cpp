#include <sun/nio/fs/DefaultFileTypeDetector.h>

#include <java/nio/file/spi/FileTypeDetector.h>
#include <sun/nio/fs/RegistryFileTypeDetector.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $FileTypeDetector = ::java::nio::file::spi::FileTypeDetector;
using $RegistryFileTypeDetector = ::sun::nio::fs::RegistryFileTypeDetector;

namespace sun {
	namespace nio {
		namespace fs {

$MethodInfo _DefaultFileTypeDetector_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(DefaultFileTypeDetector, init$, void)},
	{"create", "()Ljava/nio/file/spi/FileTypeDetector;", nullptr, $PUBLIC | $STATIC, $staticMethod(DefaultFileTypeDetector, create, $FileTypeDetector*)},
	{}
};

$ClassInfo _DefaultFileTypeDetector_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.fs.DefaultFileTypeDetector",
	"java.lang.Object",
	nullptr,
	nullptr,
	_DefaultFileTypeDetector_MethodInfo_
};

$Object* allocate$DefaultFileTypeDetector($Class* clazz) {
	return $of($alloc(DefaultFileTypeDetector));
}

void DefaultFileTypeDetector::init$() {
}

$FileTypeDetector* DefaultFileTypeDetector::create() {
	return $new($RegistryFileTypeDetector);
}

DefaultFileTypeDetector::DefaultFileTypeDetector() {
}

$Class* DefaultFileTypeDetector::load$($String* name, bool initialize) {
	$loadClass(DefaultFileTypeDetector, name, initialize, &_DefaultFileTypeDetector_ClassInfo_, allocate$DefaultFileTypeDetector);
	return class$;
}

$Class* DefaultFileTypeDetector::class$ = nullptr;

		} // fs
	} // nio
} // sun