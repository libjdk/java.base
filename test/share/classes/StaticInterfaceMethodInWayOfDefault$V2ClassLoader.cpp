#include <StaticInterfaceMethodInWayOfDefault$V2ClassLoader.h>

#include <StaticInterfaceMethodInWayOfDefault.h>
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

$MethodInfo _StaticInterfaceMethodInWayOfDefault$V2ClassLoader_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/ClassLoader;)V", nullptr, 0, $method(StaticInterfaceMethodInWayOfDefault$V2ClassLoader, init$, void, $ClassLoader*)},
	{"findClass", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(StaticInterfaceMethodInWayOfDefault$V2ClassLoader, findClass, $Class*, $String*), "java.lang.ClassNotFoundException"},
	{"loadClass", "(Ljava/lang/String;Z)Ljava/lang/Class;", "(Ljava/lang/String;Z)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(StaticInterfaceMethodInWayOfDefault$V2ClassLoader, loadClass, $Class*, $String*, bool), "java.lang.ClassNotFoundException"},
	{}
};

$InnerClassInfo _StaticInterfaceMethodInWayOfDefault$V2ClassLoader_InnerClassesInfo_[] = {
	{"StaticInterfaceMethodInWayOfDefault$V2ClassLoader", "StaticInterfaceMethodInWayOfDefault", "V2ClassLoader", $STATIC},
	{}
};

$ClassInfo _StaticInterfaceMethodInWayOfDefault$V2ClassLoader_ClassInfo_ = {
	$ACC_SUPER,
	"StaticInterfaceMethodInWayOfDefault$V2ClassLoader",
	"java.lang.ClassLoader",
	nullptr,
	nullptr,
	_StaticInterfaceMethodInWayOfDefault$V2ClassLoader_MethodInfo_,
	nullptr,
	nullptr,
	_StaticInterfaceMethodInWayOfDefault$V2ClassLoader_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"StaticInterfaceMethodInWayOfDefault"
};

$Object* allocate$StaticInterfaceMethodInWayOfDefault$V2ClassLoader($Class* clazz) {
	return $of($alloc(StaticInterfaceMethodInWayOfDefault$V2ClassLoader));
}

void StaticInterfaceMethodInWayOfDefault$V2ClassLoader::init$($ClassLoader* parent) {
	$ClassLoader::init$(parent);
}

$Class* StaticInterfaceMethodInWayOfDefault$V2ClassLoader::loadClass($String* name, bool resolve) {
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

$Class* StaticInterfaceMethodInWayOfDefault$V2ClassLoader::findClass($String* name) {
	$useLocalCurrentObjectStackCache();
	if ($nc(name)->endsWith("_v1"_s)) {
		$var($String, altName, $str({$(name->substring(0, name->length() - 3)), "_v2"_s}));
		$var($String, altPath, $($nc(altName)->replace(u'.', u'/'))->concat(".class"_s));
		try {
			$var($InputStream, is, getResourceAsStream(altPath));
			{
				$var($Throwable, var$0, nullptr);
				$var($Class, var$2, nullptr);
				bool return$1 = false;
				try {
					try {
						if (is != nullptr) {
							$var($bytes, bytes, is->readAllBytes());
							for (int32_t i = 0; i < $nc(bytes)->length - 2; ++i) {
								if (bytes->get(i) == u'_' && bytes->get(i + 1) == u'v' && bytes->get(i + 2) == u'2') {
									bytes->set(i + 2, (int8_t)u'1');
								}
							}
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
	} else {
		$var($String, path, $(name->replace(u'.', u'/'))->concat(".class"_s));
		try {
			$var($InputStream, is, getResourceAsStream(path));
			{
				$var($Throwable, var$4, nullptr);
				$var($Class, var$6, nullptr);
				bool return$5 = false;
				try {
					try {
						if (is != nullptr) {
							$var($bytes, bytes, is->readAllBytes());
							var$6 = defineClass(name, bytes, 0, $nc(bytes)->length);
							return$5 = true;
							goto $finally1;
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
				} catch ($Throwable& var$7) {
					$assign(var$4, var$7);
				} $finally1: {
					if (is != nullptr) {
						is->close();
					}
				}
				if (var$4 != nullptr) {
					$throw(var$4);
				}
				if (return$5) {
					return var$6;
				}
			}
		} catch ($IOException& e) {
			$throwNew($ClassNotFoundException, name, e);
		}
	}
	$shouldNotReachHere();
}

StaticInterfaceMethodInWayOfDefault$V2ClassLoader::StaticInterfaceMethodInWayOfDefault$V2ClassLoader() {
}

$Class* StaticInterfaceMethodInWayOfDefault$V2ClassLoader::load$($String* name, bool initialize) {
	$loadClass(StaticInterfaceMethodInWayOfDefault$V2ClassLoader, name, initialize, &_StaticInterfaceMethodInWayOfDefault$V2ClassLoader_ClassInfo_, allocate$StaticInterfaceMethodInWayOfDefault$V2ClassLoader);
	return class$;
}

$Class* StaticInterfaceMethodInWayOfDefault$V2ClassLoader::class$ = nullptr;