#include <WriteBytes.h>

#include <java/io/BufferedOutputStream.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/OutputStream.h>
#include <java/util/Arrays.h>
#include <jcpp.h>

using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Arrays = ::java::util::Arrays;

$MethodInfo _WriteBytes_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(WriteBytes, init$, void)},
	{"assertTrue", "(ZLjava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(WriteBytes, assertTrue, void, bool, $String*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(WriteBytes, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$ClassInfo _WriteBytes_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"WriteBytes",
	"java.lang.Object",
	nullptr,
	nullptr,
	_WriteBytes_MethodInfo_
};

$Object* allocate$WriteBytes($Class* clazz) {
	return $of($alloc(WriteBytes));
}

void WriteBytes::init$() {
}

void WriteBytes::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($ByteArrayOutputStream, baos, $new($ByteArrayOutputStream));
	$var($OutputStream, out, $new($BufferedOutputStream, baos, 512));
	$var($PrintStream, ps, $new($PrintStream, out, false));
	$var($bytes, buf, $new($bytes, 128));
	for (int32_t i = 0; i < buf->length; ++i) {
		buf->set(i, (int8_t)i);
	}
	ps->writeBytes(buf);
	assertTrue(baos->size() == 0, "Buffer should not have been flushed"_s);
	ps->close();
	bool var$0 = baos->size() == buf->length;
	assertTrue(var$0, $$str({"Stream size "_s, $$str(baos->size()), " but expected "_s, $$str(buf->length)}));
	$assign(ps, $new($PrintStream, out, true));
	ps->writeBytes(buf);
	bool var$1 = baos->size() == 2 * buf->length;
	assertTrue(var$1, $$str({"Stream size "_s, $$str(baos->size()), " but expected "_s, $$str(2 * buf->length)}));
	$var($bytes, arr, baos->toByteArray());
	assertTrue($nc(arr)->length == 2 * buf->length, $$str({"Array length "_s, $$str(arr->length), " but expected "_s, $$str(2 * buf->length)}));
	assertTrue($Arrays::equals(buf, 0, buf->length, arr, 0, buf->length), "First write not equal"_s);
	assertTrue($Arrays::equals(buf, 0, buf->length, arr, buf->length, 2 * buf->length), "Second write not equal"_s);
	ps->close();
	ps->writeBytes(buf);
	assertTrue(ps->checkError(), "Error condition should be true"_s);
}

void WriteBytes::assertTrue(bool condition, $String* msg) {
	if (!condition) {
		$throwNew($RuntimeException, msg);
	}
}

WriteBytes::WriteBytes() {
}

$Class* WriteBytes::load$($String* name, bool initialize) {
	$loadClass(WriteBytes, name, initialize, &_WriteBytes_ClassInfo_, allocate$WriteBytes);
	return class$;
}

$Class* WriteBytes::class$ = nullptr;