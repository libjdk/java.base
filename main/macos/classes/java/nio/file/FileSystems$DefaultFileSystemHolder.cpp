#include <java/nio/file/FileSystems$DefaultFileSystemHolder.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/Error.h>
#include <java/lang/reflect/Constructor.h>
#include <java/net/URI.h>
#include <java/nio/file/FileSystem.h>
#include <java/nio/file/FileSystems$DefaultFileSystemHolder$1.h>
#include <java/nio/file/FileSystems.h>
#include <java/nio/file/spi/FileSystemProvider.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <sun/nio/fs/DefaultFileSystemProvider.h>
#include <sun/nio/fs/MacOSXFileSystemProvider.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Constructor = ::java::lang::reflect::Constructor;
using $URI = ::java::net::URI;
using $FileSystem = ::java::nio::file::FileSystem;
using $FileSystems$DefaultFileSystemHolder$1 = ::java::nio::file::FileSystems$DefaultFileSystemHolder$1;
using $FileSystemProvider = ::java::nio::file::spi::FileSystemProvider;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $DefaultFileSystemProvider = ::sun::nio::fs::DefaultFileSystemProvider;

namespace java {
	namespace nio {
		namespace file {

$FieldInfo _FileSystems$DefaultFileSystemHolder_FieldInfo_[] = {
	{"defaultFileSystem", "Ljava/nio/file/FileSystem;", nullptr, $STATIC | $FINAL, $staticField(FileSystems$DefaultFileSystemHolder, defaultFileSystem$)},
	{}
};

$MethodInfo _FileSystems$DefaultFileSystemHolder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(FileSystems$DefaultFileSystemHolder, init$, void)},
	{"defaultFileSystem", "()Ljava/nio/file/FileSystem;", nullptr, $PRIVATE | $STATIC, $staticMethod(FileSystems$DefaultFileSystemHolder, defaultFileSystem, $FileSystem*)},
	{"getDefaultProvider", "()Ljava/nio/file/spi/FileSystemProvider;", nullptr, $PRIVATE | $STATIC, $staticMethod(FileSystems$DefaultFileSystemHolder, getDefaultProvider, $FileSystemProvider*)},
	{}
};

$InnerClassInfo _FileSystems$DefaultFileSystemHolder_InnerClassesInfo_[] = {
	{"java.nio.file.FileSystems$DefaultFileSystemHolder", "java.nio.file.FileSystems", "DefaultFileSystemHolder", $PRIVATE | $STATIC},
	{"java.nio.file.FileSystems$DefaultFileSystemHolder$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _FileSystems$DefaultFileSystemHolder_ClassInfo_ = {
	$ACC_SUPER,
	"java.nio.file.FileSystems$DefaultFileSystemHolder",
	"java.lang.Object",
	nullptr,
	_FileSystems$DefaultFileSystemHolder_FieldInfo_,
	_FileSystems$DefaultFileSystemHolder_MethodInfo_,
	nullptr,
	nullptr,
	_FileSystems$DefaultFileSystemHolder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.nio.file.FileSystems"
};

$Object* allocate$FileSystems$DefaultFileSystemHolder($Class* clazz) {
	return $of($alloc(FileSystems$DefaultFileSystemHolder));
}

$FileSystem* FileSystems$DefaultFileSystemHolder::defaultFileSystem$ = nullptr;

void FileSystems$DefaultFileSystemHolder::init$() {
}

$FileSystem* FileSystems$DefaultFileSystemHolder::defaultFileSystem() {
	$init(FileSystems$DefaultFileSystemHolder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($FileSystemProvider, provider, $cast($FileSystemProvider, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($FileSystems$DefaultFileSystemHolder$1)))));
	return $nc(provider)->getFileSystem($($URI::create("file:///"_s)));
}

$FileSystemProvider* FileSystems$DefaultFileSystemHolder::getDefaultProvider() {
	$init(FileSystems$DefaultFileSystemHolder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($FileSystemProvider, provider, $DefaultFileSystemProvider::instance());
	$var($String, prop, "java.nio.file.spi.DefaultFileSystemProvider"_s);
	$var($String, propValue, $System::getProperty(prop));
	if (propValue != nullptr) {
		{
			$var($StringArray, arr$, propValue->split(","_s));
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, cn, arr$->get(i$));
				{
					try {
						$Class* c = $Class::forName(cn, true, $($ClassLoader::getSystemClassLoader()));
						$load($FileSystemProvider);
						$var($Constructor, ctor, $nc(c)->getDeclaredConstructor($$new($ClassArray, {$FileSystemProvider::class$})));
						$assign(provider, $cast($FileSystemProvider, $nc(ctor)->newInstance($$new($ObjectArray, {$of(provider)}))));
						if (!$nc($($nc(provider)->getScheme()))->equals("file"_s)) {
							$throwNew($Error, "Default provider must use scheme \'file\'"_s);
						}
					} catch ($Exception& x) {
						$throwNew($Error, static_cast<$Throwable*>(x));
					}
				}
			}
		}
	}
	return provider;
}

void clinit$FileSystems$DefaultFileSystemHolder($Class* class$) {
	$assignStatic(FileSystems$DefaultFileSystemHolder::defaultFileSystem$, FileSystems$DefaultFileSystemHolder::defaultFileSystem());
}

FileSystems$DefaultFileSystemHolder::FileSystems$DefaultFileSystemHolder() {
}

$Class* FileSystems$DefaultFileSystemHolder::load$($String* name, bool initialize) {
	$loadClass(FileSystems$DefaultFileSystemHolder, name, initialize, &_FileSystems$DefaultFileSystemHolder_ClassInfo_, clinit$FileSystems$DefaultFileSystemHolder, allocate$FileSystems$DefaultFileSystemHolder);
	return class$;
}

$Class* FileSystems$DefaultFileSystemHolder::class$ = nullptr;

		} // file
	} // nio
} // java