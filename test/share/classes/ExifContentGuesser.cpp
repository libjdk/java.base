#include <ExifContentGuesser.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/FileInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/net/URLConnection.h>
#include <jcpp.h>

using $BufferedInputStream = ::java::io::BufferedInputStream;
using $FileInputStream = ::java::io::FileInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;
using $URLConnection = ::java::net::URLConnection;

$MethodInfo _ExifContentGuesser_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ExifContentGuesser, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ExifContentGuesser, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$ClassInfo _ExifContentGuesser_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ExifContentGuesser",
	"java.lang.Object",
	nullptr,
	nullptr,
	_ExifContentGuesser_MethodInfo_
};

$Object* allocate$ExifContentGuesser($Class* clazz) {
	return $of($alloc(ExifContentGuesser));
}

void ExifContentGuesser::init$() {
}

void ExifContentGuesser::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($String, filename, $str({$($System::getProperty("test.src"_s, "."_s)), "/olympus.jpg"_s}));
	$nc($System::out)->println($$str({"filename: "_s, filename}));
	$var($InputStream, in, nullptr);
	try {
		$assign(in, $new($BufferedInputStream, $$new($FileInputStream, filename)));
		$var($String, content_type, $URLConnection::guessContentTypeFromStream(in));
		if (content_type == nullptr) {
			$throwNew($Exception, "Test failed: Could not recognise Exif image"_s);
		} else {
			$nc($System::out)->println($$str({"content-type: "_s, content_type}));
		}
	} catch ($IOException& e) {
		e->printStackTrace();
	}
}

ExifContentGuesser::ExifContentGuesser() {
}

$Class* ExifContentGuesser::load$($String* name, bool initialize) {
	$loadClass(ExifContentGuesser, name, initialize, &_ExifContentGuesser_ClassInfo_, allocate$ExifContentGuesser);
	return class$;
}

$Class* ExifContentGuesser::class$ = nullptr;