#include <ReadParams.h>

#include <java/io/BufferedReader.h>
#include <java/io/ByteArrayInputStream.h>
#include <java/io/CharArrayReader.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/PipedReader.h>
#include <java/io/PipedWriter.h>
#include <java/io/PushbackReader.h>
#include <java/io/Reader.h>
#include <java/io/StringReader.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <jcpp.h>

#undef MAX_VALUE
#undef MIN_VALUE

using $charArray2 = $Array<char16_t, 2>;
using $BufferedReader = ::java::io::BufferedReader;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $CharArrayReader = ::java::io::CharArrayReader;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $PipedReader = ::java::io::PipedReader;
using $PipedWriter = ::java::io::PipedWriter;
using $PushbackReader = ::java::io::PushbackReader;
using $Reader = ::java::io::Reader;
using $StringReader = ::java::io::StringReader;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;

$FieldInfo _ReadParams_FieldInfo_[] = {
	{"values", "[I", nullptr, $STATIC, $staticField(ReadParams, values)},
	{"b", "[[C", nullptr, $STATIC, $staticField(ReadParams, b)},
	{}
};

$MethodInfo _ReadParams_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ReadParams, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ReadParams, main, void, $StringArray*), "java.lang.Exception"},
	{"test", "(Ljava/io/Reader;)V", nullptr, $STATIC, $staticMethod(ReadParams, test, void, $Reader*), "java.lang.Exception"},
	{}
};

$ClassInfo _ReadParams_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ReadParams",
	"java.lang.Object",
	nullptr,
	_ReadParams_FieldInfo_,
	_ReadParams_MethodInfo_
};

$Object* allocate$ReadParams($Class* clazz) {
	return $of($alloc(ReadParams));
}

$ints* ReadParams::values = nullptr;
$charArray2* ReadParams::b = nullptr;

void ReadParams::init$() {
}

void ReadParams::test($Reader* rdr) {
	$init(ReadParams);
	$useLocalCurrentObjectStackCache();
	int32_t i = 0;
	int32_t j = 0;
	int32_t k = 0;
	bool nullPtr = false;
	bool indexOutBnd = false;
	for (i = 0; i < $nc(ReadParams::b)->length; ++i) {
		for (j = 0; j < $nc(ReadParams::values)->length; ++j) {
			for (k = 0; k < $nc(ReadParams::values)->length; ++k) {
				nullPtr = ($nc(ReadParams::b)->get(i) == nullptr);
				int32_t bufLen = nullPtr ? 0 : $nc($nc(ReadParams::b)->get(i))->length;
				indexOutBnd = (($nc(ReadParams::values)->get(j) + $nc(ReadParams::values)->get(k)) < 0) || ($nc(ReadParams::values)->get(j) < 0) || ($nc(ReadParams::values)->get(j) > bufLen) || ($nc(ReadParams::values)->get(k) < 0) || (($nc(ReadParams::values)->get(j) + $nc(ReadParams::values)->get(k)) > bufLen);
				try {
					$nc(rdr)->read($nc(ReadParams::b)->get(i), $nc(ReadParams::values)->get(j), $nc(ReadParams::values)->get(k));
				} catch ($NullPointerException& e) {
					if (!nullPtr) {
						$throwNew($Exception, $$str({"should not throw NullPointerException"_s, $$str(i), " "_s, $$str(j), " "_s, $$str(k)}));
					}
					continue;
				} catch ($IndexOutOfBoundsException& e) {
					if (!indexOutBnd) {
						$throwNew($Exception, "should not throw IndexOutOfBoundsException"_s);
					}
					continue;
				}
				if (nullPtr || indexOutBnd) {
					$throwNew($Exception, "Should have thrown an exception"_s);
				}
			}
		}
	}
}

void ReadParams::main($StringArray* args) {
	$init(ReadParams);
	$useLocalCurrentObjectStackCache();
	$var($StringReader, sr, $new($StringReader, $$new($String, $$new($bytes, 512))));
	test(sr);
	test($$new($BufferedReader, sr));
	test($$new($CharArrayReader, $$new($chars, 8)));
	$var($InputStreamReader, ir, $new($InputStreamReader, $$new($ByteArrayInputStream, $$new($bytes, 512))));
	test(ir);
	test($$new($PushbackReader, sr, 2));
	$var($PipedWriter, pw, $new($PipedWriter));
	$var($PipedReader, pir, $new($PipedReader, pw));
	pw->write($$new($chars, 512), 0, 512);
	test(pir);
}

void clinit$ReadParams($Class* class$) {
	$assignStatic(ReadParams::values, $new($ints, {
		$Integer::MIN_VALUE,
		-1,
		0,
		1,
		4,
		16,
		31,
		32,
		33,
		$Integer::MAX_VALUE
	}));
	$assignStatic(ReadParams::b, $new($charArray2, {
		($chars*)nullptr,
		$$new($chars, 32)
	}));
}

ReadParams::ReadParams() {
}

$Class* ReadParams::load$($String* name, bool initialize) {
	$loadClass(ReadParams, name, initialize, &_ReadParams_ClassInfo_, clinit$ReadParams, allocate$ReadParams);
	return class$;
}

$Class* ReadParams::class$ = nullptr;