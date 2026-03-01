#include <ReadLinePushback.h>

#include <java/io/DataInputStream.h>
#include <java/io/InputStream.h>
#include <java/io/PushbackInputStream.h>
#include <java/io/StringBufferInputStream.h>
#include <jcpp.h>

using $DataInputStream = ::java::io::DataInputStream;
using $InputStream = ::java::io::InputStream;
using $PushbackInputStream = ::java::io::PushbackInputStream;
using $StringBufferInputStream = ::java::io::StringBufferInputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;

$MethodInfo _ReadLinePushback_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ReadLinePushback, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ReadLinePushback, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$ClassInfo _ReadLinePushback_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ReadLinePushback",
	"java.lang.Object",
	nullptr,
	nullptr,
	_ReadLinePushback_MethodInfo_
};

$Object* allocate$ReadLinePushback($Class* clazz) {
	return $of($alloc(ReadLinePushback));
}

void ReadLinePushback::init$() {
}

void ReadLinePushback::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($PushbackInputStream, pis, $new($PushbackInputStream, ($$new($StringBufferInputStream, "\r"_s))));
	$var($DataInputStream, dis, $new($DataInputStream, pis));
	$var($String, line, dis->readLine());
	if (line == nullptr) {
		$throwNew($Exception, "Got null, should return empty line"_s);
	}
	int32_t count = pis->available();
	if (count != 0) {
		$throwNew($Exception, $$str({"Test failed: available() returns "_s, $$str(count), "when the file is empty"_s}));
	}
}

ReadLinePushback::ReadLinePushback() {
}

$Class* ReadLinePushback::load$($String* name, bool initialize) {
	$loadClass(ReadLinePushback, name, initialize, &_ReadLinePushback_ClassInfo_, allocate$ReadLinePushback);
	return class$;
}

$Class* ReadLinePushback::class$ = nullptr;