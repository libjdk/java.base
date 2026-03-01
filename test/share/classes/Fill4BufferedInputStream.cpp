#include <Fill4BufferedInputStream.h>

#include <Fill4BufferedInputStream$Source.h>
#include <java/io/BufferedInputStream.h>
#include <java/io/InputStream.h>
#include <jcpp.h>

using $Fill4BufferedInputStream$Source = ::Fill4BufferedInputStream$Source;
using $BufferedInputStream = ::java::io::BufferedInputStream;
using $InputStream = ::java::io::InputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;

$MethodInfo _Fill4BufferedInputStream_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Fill4BufferedInputStream, init$, void)},
	{"go", "(I)V", nullptr, $STATIC, $staticMethod(Fill4BufferedInputStream, go, void, int32_t), "java.lang.Exception"},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Fill4BufferedInputStream, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$InnerClassInfo _Fill4BufferedInputStream_InnerClassesInfo_[] = {
	{"Fill4BufferedInputStream$Source", "Fill4BufferedInputStream", "Source", $STATIC},
	{}
};

$ClassInfo _Fill4BufferedInputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Fill4BufferedInputStream",
	"java.lang.Object",
	nullptr,
	nullptr,
	_Fill4BufferedInputStream_MethodInfo_,
	nullptr,
	nullptr,
	_Fill4BufferedInputStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	"Fill4BufferedInputStream$Source"
};

$Object* allocate$Fill4BufferedInputStream($Class* clazz) {
	return $of($alloc(Fill4BufferedInputStream));
}

void Fill4BufferedInputStream::init$() {
}

void Fill4BufferedInputStream::go(int32_t shortFall) {
	$useLocalCurrentObjectStackCache();
	$var($InputStream, r, $new($BufferedInputStream, $$new($Fill4BufferedInputStream$Source, shortFall), 10));
	$var($bytes, buf, $new($bytes, 8));
	int32_t n1 = r->read(buf);
	int32_t n2 = r->read(buf);
	$nc($System::err)->println($$str({"Shortfall "_s, $$str(shortFall), ": Read "_s, $$str(n1), ", then "_s, $$str(n2), " bytes"_s}));
	if (n1 != buf->length) {
		$throwNew($Exception, $$str({"First read returned "_s, $$str(n1)}));
	}
	if (n2 != buf->length) {
		$throwNew($Exception, $$str({"Second read returned "_s, $$str(n2)}));
	}
}

void Fill4BufferedInputStream::main($StringArray* args) {
	for (int32_t i = 0; i < 8; ++i) {
		go(i);
	}
}

Fill4BufferedInputStream::Fill4BufferedInputStream() {
}

$Class* Fill4BufferedInputStream::load$($String* name, bool initialize) {
	$loadClass(Fill4BufferedInputStream, name, initialize, &_Fill4BufferedInputStream_ClassInfo_, allocate$Fill4BufferedInputStream);
	return class$;
}

$Class* Fill4BufferedInputStream::class$ = nullptr;