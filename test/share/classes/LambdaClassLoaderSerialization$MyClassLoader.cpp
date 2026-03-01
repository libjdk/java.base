#include <LambdaClassLoaderSerialization$MyClassLoader.h>

#include <LambdaClassLoaderSerialization.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;

$MethodInfo _LambdaClassLoaderSerialization$MyClassLoader_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/ClassLoader;)V", nullptr, 0, $method(LambdaClassLoaderSerialization$MyClassLoader, init$, void, $ClassLoader*)},
	{"findClass", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(LambdaClassLoaderSerialization$MyClassLoader, findClass, $Class*, $String*), "java.lang.ClassNotFoundException"},
	{"loadClass", "(Ljava/lang/String;Z)Ljava/lang/Class;", "(Ljava/lang/String;Z)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(LambdaClassLoaderSerialization$MyClassLoader, loadClass, $Class*, $String*, bool), "java.lang.ClassNotFoundException"},
	{}
};

$InnerClassInfo _LambdaClassLoaderSerialization$MyClassLoader_InnerClassesInfo_[] = {
	{"LambdaClassLoaderSerialization$MyClassLoader", "LambdaClassLoaderSerialization", "MyClassLoader", $STATIC},
	{}
};

$ClassInfo _LambdaClassLoaderSerialization$MyClassLoader_ClassInfo_ = {
	$ACC_SUPER,
	"LambdaClassLoaderSerialization$MyClassLoader",
	"java.lang.ClassLoader",
	nullptr,
	nullptr,
	_LambdaClassLoaderSerialization$MyClassLoader_MethodInfo_,
	nullptr,
	nullptr,
	_LambdaClassLoaderSerialization$MyClassLoader_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"LambdaClassLoaderSerialization"
};

$Object* allocate$LambdaClassLoaderSerialization$MyClassLoader($Class* clazz) {
	return $of($alloc(LambdaClassLoaderSerialization$MyClassLoader));
}

void LambdaClassLoaderSerialization$MyClassLoader::init$($ClassLoader* parent) {
	$ClassLoader::init$(parent);
}

$Class* LambdaClassLoaderSerialization$MyClassLoader::loadClass($String* name, bool resolve) {
	if ($nc(name)->indexOf((int32_t)u'.') < 0) {
		$synchronized(getClassLoadingLock(name)) {
			$Class* c = findLoadedClass(name);
			if (c == nullptr) {
				c = findClass(name);
			}
			if (resolve) {
				resolveClass(c);
			}
			return c;
		}
	} else {
		return $ClassLoader::loadClass(name, resolve);
	}
}

$Class* LambdaClassLoaderSerialization$MyClassLoader::findClass($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($String, path, $($nc(name)->replace(u'.', u'/'))->concat(".class"_s));
	try {
		$var($InputStream, is, getResourceAsStream(path));
		{
			$var($Throwable, var$0, nullptr);
			$var($Class, var$2, nullptr);
			bool return$1 = false;
			try {
				try {
					if (is != nullptr) {
						$var($bytes, bytes, is->readAllBytes());
						var$2 = defineClass(name, bytes, 0, $nc(bytes)->length);
						return$1 = true;
						goto $finally;
					} else {
						$throwNew($ClassNotFoundException, name);
					}
				} catch ($Throwable& t$) {
					if (is != nullptr) {
						try {
							is->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				if (is != nullptr) {
					is->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	} catch ($IOException& e) {
		$throwNew($ClassNotFoundException, name, e);
	}
	$shouldNotReachHere();
}

LambdaClassLoaderSerialization$MyClassLoader::LambdaClassLoaderSerialization$MyClassLoader() {
}

$Class* LambdaClassLoaderSerialization$MyClassLoader::load$($String* name, bool initialize) {
	$loadClass(LambdaClassLoaderSerialization$MyClassLoader, name, initialize, &_LambdaClassLoaderSerialization$MyClassLoader_ClassInfo_, allocate$LambdaClassLoaderSerialization$MyClassLoader);
	return class$;
}

$Class* LambdaClassLoaderSerialization$MyClassLoader::class$ = nullptr;