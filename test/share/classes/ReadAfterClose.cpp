#include <ReadAfterClose.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/ByteArrayInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <jcpp.h>

using $BufferedInputStream = ::java::io::BufferedInputStream;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;

$MethodInfo _ReadAfterClose_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ReadAfterClose, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ReadAfterClose, main, void, $StringArray*), "java.lang.Exception"},
	{"testRead", "(Ljava/io/InputStream;)V", nullptr, $STATIC, $staticMethod(ReadAfterClose, testRead, void, $InputStream*), "java.lang.Exception"},
	{}
};

$ClassInfo _ReadAfterClose_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ReadAfterClose",
	"java.lang.Object",
	nullptr,
	nullptr,
	_ReadAfterClose_MethodInfo_
};

$Object* allocate$ReadAfterClose($Class* clazz) {
	return $of($alloc(ReadAfterClose));
}

void ReadAfterClose::init$() {
}

void ReadAfterClose::testRead($InputStream* in) {
	$nc(in)->close();
	$var($bytes, buf, $new($bytes, 2));
	try {
		in->read(buf, 0, 1);
		$throwNew($Exception, "Should not allow read on a closed stream"_s);
	} catch ($IOException& e) {
	}
	try {
		in->read(buf, 0, 0);
		$throwNew($Exception, "Should not allow read on a closed stream"_s);
	} catch ($IOException& e) {
	}
}

void ReadAfterClose::main($StringArray* argv) {
	$useLocalCurrentObjectStackCache();
	$var($BufferedInputStream, bis, $new($BufferedInputStream, $$new($ByteArrayInputStream, $$new($bytes, 32))));
	testRead(bis);
}

ReadAfterClose::ReadAfterClose() {
}

$Class* ReadAfterClose::load$($String* name, bool initialize) {
	$loadClass(ReadAfterClose, name, initialize, &_ReadAfterClose_ClassInfo_, allocate$ReadAfterClose);
	return class$;
}

$Class* ReadAfterClose::class$ = nullptr;