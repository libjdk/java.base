#include <WriteParams.h>

#include <java/io/BufferedWriter.h>
#include <java/io/CharArrayWriter.h>
#include <java/io/OutputStream.h>
#include <java/io/OutputStreamWriter.h>
#include <java/io/PipedReader.h>
#include <java/io/PipedWriter.h>
#include <java/io/StringWriter.h>
#include <java/io/Writer.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <jcpp.h>

#undef MAX_VALUE
#undef MIN_VALUE

using $charArray2 = $Array<char16_t, 2>;
using $BufferedWriter = ::java::io::BufferedWriter;
using $CharArrayWriter = ::java::io::CharArrayWriter;
using $OutputStream = ::java::io::OutputStream;
using $OutputStreamWriter = ::java::io::OutputStreamWriter;
using $PipedReader = ::java::io::PipedReader;
using $PipedWriter = ::java::io::PipedWriter;
using $StringWriter = ::java::io::StringWriter;
using $Writer = ::java::io::Writer;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;

$FieldInfo _WriteParams_FieldInfo_[] = {
	{"values", "[I", nullptr, $STATIC, $staticField(WriteParams, values)},
	{"b", "[[C", nullptr, $STATIC, $staticField(WriteParams, b)},
	{}
};

$MethodInfo _WriteParams_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(WriteParams, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(WriteParams, main, void, $StringArray*), "java.lang.Exception"},
	{"test", "(Ljava/io/Writer;)V", nullptr, $STATIC, $staticMethod(WriteParams, test, void, $Writer*), "java.lang.Exception"},
	{}
};

$ClassInfo _WriteParams_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"WriteParams",
	"java.lang.Object",
	nullptr,
	_WriteParams_FieldInfo_,
	_WriteParams_MethodInfo_
};

$Object* allocate$WriteParams($Class* clazz) {
	return $of($alloc(WriteParams));
}

$ints* WriteParams::values = nullptr;
$charArray2* WriteParams::b = nullptr;

void WriteParams::init$() {
}

void WriteParams::test($Writer* wtr) {
	$init(WriteParams);
	int32_t i = 0;
	int32_t j = 0;
	int32_t k = 0;
	bool nullPtr = false;
	bool indexOutBnd = false;
	for (i = 0; i < $nc(WriteParams::b)->length; ++i) {
		for (j = 0; j < $nc(WriteParams::values)->length; ++j) {
			for (k = 0; k < $nc(WriteParams::values)->length; ++k) {
				nullPtr = ($nc(WriteParams::b)->get(i) == nullptr);
				int32_t bufLen = nullPtr ? 0 : $nc($nc(WriteParams::b)->get(i))->length;
				indexOutBnd = (($nc(WriteParams::values)->get(j) + $nc(WriteParams::values)->get(k)) < 0) || ($nc(WriteParams::values)->get(j) < 0) || ($nc(WriteParams::values)->get(j) > bufLen) || ($nc(WriteParams::values)->get(k) < 0) || (($nc(WriteParams::values)->get(j) + $nc(WriteParams::values)->get(k)) > bufLen);
				try {
					$nc(wtr)->write($nc(WriteParams::b)->get(i), $nc(WriteParams::values)->get(j), $nc(WriteParams::values)->get(k));
				} catch ($NullPointerException& e) {
					if (!nullPtr) {
						$throwNew($Exception, "should not throw NullPointerException"_s);
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

void WriteParams::main($StringArray* args) {
	$init(WriteParams);
	$useLocalCurrentObjectStackCache();
	$var($StringWriter, sw, $new($StringWriter));
	test(sw);
	test($$new($BufferedWriter, sw));
	test($$new($CharArrayWriter));
	test($$new($OutputStreamWriter, $System::err));
	test($$new($PipedWriter, $$new($PipedReader)));
}

void clinit$WriteParams($Class* class$) {
	$assignStatic(WriteParams::values, $new($ints, {
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
	$assignStatic(WriteParams::b, $new($charArray2, {
		($chars*)nullptr,
		$$new($chars, 32)
	}));
}

WriteParams::WriteParams() {
}

$Class* WriteParams::load$($String* name, bool initialize) {
	$loadClass(WriteParams, name, initialize, &_WriteParams_ClassInfo_, clinit$WriteParams, allocate$WriteParams);
	return class$;
}

$Class* WriteParams::class$ = nullptr;