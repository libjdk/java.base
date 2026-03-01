#include <ClassRestrictions.h>

#include <ClassRestrictions$Bar.h>
#include <ClassRestrictions$Bashful.h>
#include <ClassRestrictions$Baz.h>
#include <java/io/File.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/Error.h>
#include <java/lang/reflect/Modifier.h>
#include <java/lang/reflect/Proxy.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/net/URLClassLoader.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/Paths.h>
#include <jcpp.h>

#undef TYPE

using $ClassRestrictions$Bar = ::ClassRestrictions$Bar;
using $ClassRestrictions$Bashful = ::ClassRestrictions$Bashful;
using $ClassRestrictions$Baz = ::ClassRestrictions$Baz;
using $URLArray = $Array<::java::net::URL>;
using $File = ::java::io::File;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Modifier = ::java::lang::reflect::Modifier;
using $Proxy = ::java::lang::reflect::Proxy;
using $URI = ::java::net::URI;
using $URLClassLoader = ::java::net::URLClassLoader;
using $Path = ::java::nio::file::Path;
using $Paths = ::java::nio::file::Paths;

$FieldInfo _ClassRestrictions_FieldInfo_[] = {
	{"nonPublicIntrfaceName", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(ClassRestrictions, nonPublicIntrfaceName)},
	{}
};

$MethodInfo _ClassRestrictions_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ClassRestrictions, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ClassRestrictions, main, void, $StringArray*)},
	{}
};

$InnerClassInfo _ClassRestrictions_InnerClassesInfo_[] = {
	{"ClassRestrictions$Bashful", "ClassRestrictions", "Bashful", $STATIC | $INTERFACE | $ABSTRACT},
	{"ClassRestrictions$Baz", "ClassRestrictions", "Baz", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"ClassRestrictions$Bar", "ClassRestrictions", "Bar", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ClassRestrictions_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ClassRestrictions",
	"java.lang.Object",
	nullptr,
	_ClassRestrictions_FieldInfo_,
	_ClassRestrictions_MethodInfo_,
	nullptr,
	nullptr,
	_ClassRestrictions_InnerClassesInfo_,
	nullptr,
	nullptr,
	"ClassRestrictions$Bashful,ClassRestrictions$Baz,ClassRestrictions$Bar"
};

$Object* allocate$ClassRestrictions($Class* clazz) {
	return $of($alloc(ClassRestrictions));
}

$String* ClassRestrictions::nonPublicIntrfaceName = nullptr;

void ClassRestrictions::init$() {
}

void ClassRestrictions::main($StringArray* args) {
	$init(ClassRestrictions);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$nc($System::err)->println("\nTest of restrictions on parameters to Proxy.getProxyClass\n"_s);
	try {
		$var($ClassLoader, loader, ClassRestrictions::class$->getClassLoader());
		$var($ClassArray, interfaces, nullptr);
		$Class* proxyClass = nullptr;
		try {
			$assign(interfaces, $new($ClassArray, {$Object::class$}));
			proxyClass = $Proxy::getProxyClass(loader, interfaces);
			$throwNew($Error, "proxy class created with java.lang.Object as interface"_s);
		} catch ($IllegalArgumentException& e) {
			e->printStackTrace();
			$nc($System::err)->println();
		}
		try {
			$init($Integer);
			$assign(interfaces, $new($ClassArray, {$Integer::TYPE}));
			proxyClass = $Proxy::getProxyClass(loader, interfaces);
			$throwNew($Error, "proxy class created with int.class as interface"_s);
		} catch ($IllegalArgumentException& e) {
			e->printStackTrace();
			$nc($System::err)->println();
		}
		try {
			$load($ClassRestrictions$Bar);
			$assign(interfaces, $new($ClassArray, {
				$ClassRestrictions$Bar::class$,
				$ClassRestrictions$Bar::class$
			}));
			proxyClass = $Proxy::getProxyClass(loader, interfaces);
			$throwNew($Error, "proxy class created with repeated interfaces"_s);
		} catch ($IllegalArgumentException& e) {
			e->printStackTrace();
			$nc($System::err)->println();
		}
		$init($File);
		$var($StringArray, cpaths, $nc($($System::getProperty("test.classes"_s, "."_s)))->split($File::pathSeparator));
		$var($URLArray, urls, $new($URLArray, cpaths->length));
		for (int32_t i = 0; i < cpaths->length; ++i) {
			urls->set(i, $($nc($($nc($($Paths::get(cpaths->get(i), $$new($StringArray, 0))))->toUri()))->toURL()));
		}
		$var($ClassLoader, altLoader, $new($URLClassLoader, urls, ($ClassLoader*)nullptr));
		$Class* altBarClass = nullptr;
		$load($ClassRestrictions$Bar);
		altBarClass = $Class::forName($($ClassRestrictions$Bar::class$->getName()), false, altLoader);
		try {
			$assign(interfaces, $new($ClassArray, {altBarClass}));
			proxyClass = $Proxy::getProxyClass(loader, interfaces);
			$throwNew($Error, "proxy class created with interface not visible to class loader"_s);
		} catch ($IllegalArgumentException& e) {
			e->printStackTrace();
			$nc($System::err)->println();
		}
		$load($ClassRestrictions$Bashful);
		$Class* nonPublic1 = $ClassRestrictions$Bashful::class$;
		$Class* nonPublic2 = $Class::forName(ClassRestrictions::nonPublicIntrfaceName);
		if ($Modifier::isPublic($nc(nonPublic2)->getModifiers())) {
			$throwNew($Error, $$str({"Interface "_s, ClassRestrictions::nonPublicIntrfaceName, " is public and need to be changed!"_s}));
		}
		try {
			$assign(interfaces, $new($ClassArray, {
				nonPublic1,
				nonPublic2
			}));
			proxyClass = $Proxy::getProxyClass(loader, interfaces);
			$throwNew($Error, "proxy class created with two non-public interfaces in different packages"_s);
		} catch ($IllegalArgumentException& e) {
			e->printStackTrace();
			$nc($System::err)->println();
		}
		try {
			$load($ClassRestrictions$Baz);
			$assign(interfaces, $new($ClassArray, {
				$ClassRestrictions$Bar::class$,
				$ClassRestrictions$Baz::class$
			}));
			proxyClass = $Proxy::getProxyClass(loader, interfaces);
			$throwNew($Error, "proxy class created with conflicting methods"_s);
		} catch ($IllegalArgumentException& e) {
			e->printStackTrace();
			$nc($System::err)->println();
		}
		$nc($System::err)->println("\nTEST PASSED"_s);
	} catch ($Throwable& e) {
		$nc($System::err)->println("\nTEST FAILED:"_s);
		e->printStackTrace();
		$throwNew($Error, "TEST FAILED: "_s, e);
	}
}

ClassRestrictions::ClassRestrictions() {
}

void clinit$ClassRestrictions($Class* class$) {
	$assignStatic(ClassRestrictions::nonPublicIntrfaceName, "java.util.zip.ZipConstants"_s);
}

$Class* ClassRestrictions::load$($String* name, bool initialize) {
	$loadClass(ClassRestrictions, name, initialize, &_ClassRestrictions_ClassInfo_, clinit$ClassRestrictions, allocate$ClassRestrictions);
	return class$;
}

$Class* ClassRestrictions::class$ = nullptr;