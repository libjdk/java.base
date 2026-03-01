#include <OpsAfterClose.h>

#include <OpsAfterClose$1.h>
#include <OpsAfterClose$2.h>
#include <OpsAfterClose$3.h>
#include <OpsAfterClose$4.h>
#include <OpsAfterClose$5.h>
#include <OpsAfterClose$6.h>
#include <OpsAfterClose$7.h>
#include <java/io/BufferedReader.h>
#include <java/io/ByteArrayInputStream.h>
#include <java/io/CharArrayReader.h>
#include <java/io/File.h>
#include <java/io/FileReader.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/LineNumberReader.h>
#include <java/io/PipedReader.h>
#include <java/io/PipedWriter.h>
#include <java/io/PushbackReader.h>
#include <java/io/Reader.h>
#include <java/io/StringReader.h>
#include <java/lang/Enum.h>
#include <jcpp.h>

#undef CLOSE
#undef MARK
#undef READ
#undef READY
#undef READ_BUF
#undef RESET
#undef SKIP

using $OpsAfterClose$1 = ::OpsAfterClose$1;
using $OpsAfterClose$2 = ::OpsAfterClose$2;
using $OpsAfterClose$3 = ::OpsAfterClose$3;
using $OpsAfterClose$4 = ::OpsAfterClose$4;
using $OpsAfterClose$5 = ::OpsAfterClose$5;
using $OpsAfterClose$6 = ::OpsAfterClose$6;
using $OpsAfterClose$7 = ::OpsAfterClose$7;
using $OpsAfterCloseArray = $Array<OpsAfterClose>;
using $BufferedReader = ::java::io::BufferedReader;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $CharArrayReader = ::java::io::CharArrayReader;
using $File = ::java::io::File;
using $FileReader = ::java::io::FileReader;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $LineNumberReader = ::java::io::LineNumberReader;
using $PipedReader = ::java::io::PipedReader;
using $PipedWriter = ::java::io::PipedWriter;
using $PrintStream = ::java::io::PrintStream;
using $PushbackReader = ::java::io::PushbackReader;
using $Reader = ::java::io::Reader;
using $StringReader = ::java::io::StringReader;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;

$FieldInfo _OpsAfterClose_FieldInfo_[] = {
	{"READ", "LOpsAfterClose;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose, READ)},
	{"READ_BUF", "LOpsAfterClose;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose, READ_BUF)},
	{"READY", "LOpsAfterClose;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose, READY)},
	{"MARK", "LOpsAfterClose;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose, MARK)},
	{"SKIP", "LOpsAfterClose;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose, SKIP)},
	{"RESET", "LOpsAfterClose;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose, RESET)},
	{"CLOSE", "LOpsAfterClose;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose, CLOSE)},
	{"$VALUES", "[LOpsAfterClose;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(OpsAfterClose, $VALUES)},
	{}
};

$MethodInfo _OpsAfterClose_MethodInfo_[] = {
	{"$values", "()[LOpsAfterClose;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(OpsAfterClose, $values, $OpsAfterCloseArray*)},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(OpsAfterClose, init$, void, $String*, int32_t)},
	{"check", "(Ljava/io/Reader;)Z", nullptr, $ABSTRACT, $virtualMethod(OpsAfterClose, check, bool, $Reader*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(OpsAfterClose, main, void, $StringArray*), "java.lang.Exception"},
	{"testPushbackReader", "(Ljava/io/PushbackReader;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(OpsAfterClose, testPushbackReader, bool, $PushbackReader*), "java.lang.Exception"},
	{"testReader", "(Ljava/io/Reader;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(OpsAfterClose, testReader, bool, $Reader*), "java.lang.Exception"},
	{"valueOf", "(Ljava/lang/String;)LOpsAfterClose;", nullptr, $PUBLIC | $STATIC, $staticMethod(OpsAfterClose, valueOf, OpsAfterClose*, $String*)},
	{"values", "()[LOpsAfterClose;", nullptr, $PUBLIC | $STATIC, $staticMethod(OpsAfterClose, values, $OpsAfterCloseArray*)},
	{}
};

$InnerClassInfo _OpsAfterClose_InnerClassesInfo_[] = {
	{"OpsAfterClose$7", nullptr, nullptr, $FINAL | $ENUM},
	{"OpsAfterClose$6", nullptr, nullptr, $FINAL | $ENUM},
	{"OpsAfterClose$5", nullptr, nullptr, $FINAL | $ENUM},
	{"OpsAfterClose$4", nullptr, nullptr, $FINAL | $ENUM},
	{"OpsAfterClose$3", nullptr, nullptr, $FINAL | $ENUM},
	{"OpsAfterClose$2", nullptr, nullptr, $FINAL | $ENUM},
	{"OpsAfterClose$1", nullptr, nullptr, $FINAL | $ENUM},
	{}
};

$ClassInfo _OpsAfterClose_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT | $ENUM,
	"OpsAfterClose",
	"java.lang.Enum",
	nullptr,
	_OpsAfterClose_FieldInfo_,
	_OpsAfterClose_MethodInfo_,
	"Ljava/lang/Enum<LOpsAfterClose;>;",
	nullptr,
	_OpsAfterClose_InnerClassesInfo_,
	nullptr,
	nullptr,
	"OpsAfterClose$7,OpsAfterClose$6,OpsAfterClose$5,OpsAfterClose$4,OpsAfterClose$3,OpsAfterClose$2,OpsAfterClose$1"
};

$Object* allocate$OpsAfterClose($Class* clazz) {
	return $of($alloc(OpsAfterClose));
}

OpsAfterClose* OpsAfterClose::READ = nullptr;
OpsAfterClose* OpsAfterClose::READ_BUF = nullptr;
OpsAfterClose* OpsAfterClose::READY = nullptr;
OpsAfterClose* OpsAfterClose::MARK = nullptr;
OpsAfterClose* OpsAfterClose::SKIP = nullptr;
OpsAfterClose* OpsAfterClose::RESET = nullptr;
OpsAfterClose* OpsAfterClose::CLOSE = nullptr;
$OpsAfterCloseArray* OpsAfterClose::$VALUES = nullptr;

$OpsAfterCloseArray* OpsAfterClose::$values() {
	$init(OpsAfterClose);
	return $new($OpsAfterCloseArray, {
		OpsAfterClose::READ,
		OpsAfterClose::READ_BUF,
		OpsAfterClose::READY,
		OpsAfterClose::MARK,
		OpsAfterClose::SKIP,
		OpsAfterClose::RESET,
		OpsAfterClose::CLOSE
	});
}

$OpsAfterCloseArray* OpsAfterClose::values() {
	$init(OpsAfterClose);
	return $cast($OpsAfterCloseArray, OpsAfterClose::$VALUES->clone());
}

OpsAfterClose* OpsAfterClose::valueOf($String* name) {
	$init(OpsAfterClose);
	return $cast(OpsAfterClose, $Enum::valueOf(OpsAfterClose::class$, name));
}

void OpsAfterClose::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

void OpsAfterClose::main($StringArray* args) {
	$init(OpsAfterClose);
	$useLocalCurrentObjectStackCache();
	bool failed = false;
	$var($BufferedReader, br, $new($BufferedReader, $$new($StringReader, "abc def ghi"_s)));
	if (testReader(br)) {
		failed = true;
	}
	$var($CharArrayReader, car, $new($CharArrayReader, $$new($chars, 2)));
	if (testReader(car)) {
		failed = true;
	}
	$var($PushbackReader, pbr, $new($PushbackReader, $$new($CharArrayReader, $$new($chars, 2))));
	if (testReader(pbr)) {
		failed = true;
	}
	if (testPushbackReader(pbr)) {
		failed = true;
	}
	$var($StringReader, sr, $new($StringReader, "abc def ghi"_s));
	if (testReader(sr)) {
		failed = true;
	}
	$var($InputStreamReader, isr, $new($InputStreamReader, $$new($ByteArrayInputStream, $("abc"_s->getBytes()))));
	if (testReader(isr)) {
		failed = true;
	}
	$var($LineNumberReader, lnr, $new($LineNumberReader, $$new($StringReader, "abc def ghi"_s)));
	if (testReader(lnr)) {
		failed = true;
	}
	$var($File, f, $new($File, $($System::getProperty("test.dir"_s, "."_s)), "NewFile"_s));
	f->createNewFile();
	f->deleteOnExit();
	$var($FileReader, fr, $new($FileReader, f));
	if (testReader(fr)) {
		failed = true;
	}
	$var($PipedWriter, pw, $new($PipedWriter));
	$var($PipedReader, pr, $new($PipedReader, pw));
	if (testReader(pr)) {
		failed = true;
	}
	if (failed) {
		$throwNew($Exception, "Test failed for some of the operation{s} on some of the reader{s}, check the messages"_s);
	}
}

bool OpsAfterClose::testReader($Reader* r) {
	$init(OpsAfterClose);
	$useLocalCurrentObjectStackCache();
	$nc(r)->close();
	bool failed = false;
	bool result = false;
	$nc($System::out)->println($$str({"Testing reader:"_s, r}));
	{
		$var($OpsAfterCloseArray, arr$, OpsAfterClose::values());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			OpsAfterClose* op = arr$->get(i$);
			{
				result = $nc(op)->check(r);
				if (!result) {
					failed = true;
				}
				$nc($System::out)->println($$str({op, ":"_s, $$str(result)}));
			}
		}
	}
	if (failed) {
		$nc($System::out)->println($$str({"Test failed for the failed operation{s} above for the Reader:"_s, r}));
	}
	return failed;
}

bool OpsAfterClose::testPushbackReader($PushbackReader* pr) {
	$init(OpsAfterClose);
	$useLocalCurrentObjectStackCache();
	bool failed = false;
	try {
		$nc(pr)->unread(1);
		$nc($System::out)->println($$str({"Test failed for unread(int):"_s, pr}));
		failed = true;
	} catch ($IOException& io) {
		$nc($System::out)->println("UNREAD(int):true"_s);
	}
	$var($chars, buf, $new($chars, 2));
	try {
		$nc(pr)->unread(buf, 0, 2);
		$nc($System::out)->println($$str({"Test failed for unread(buf, offset, len):"_s, pr}));
		failed = true;
	} catch ($IOException& io) {
		$nc($System::out)->println("UNREAD(buf, offset, len):true"_s);
	}
	try {
		$nc(pr)->unread(buf);
		$nc($System::out)->println($$str({"Test failed for unread(char[] buf):"_s, pr}));
		failed = true;
	} catch ($IOException& io) {
		$nc($System::out)->println("UNREAD(buf):true"_s);
	}
	return failed;
}

void clinit$OpsAfterClose($Class* class$) {
	$assignStatic(OpsAfterClose::READ, $new($OpsAfterClose$1, "READ"_s, 0));
	$assignStatic(OpsAfterClose::READ_BUF, $new($OpsAfterClose$2, "READ_BUF"_s, 1));
	$assignStatic(OpsAfterClose::READY, $new($OpsAfterClose$3, "READY"_s, 2));
	$assignStatic(OpsAfterClose::MARK, $new($OpsAfterClose$4, "MARK"_s, 3));
	$assignStatic(OpsAfterClose::SKIP, $new($OpsAfterClose$5, "SKIP"_s, 4));
	$assignStatic(OpsAfterClose::RESET, $new($OpsAfterClose$6, "RESET"_s, 5));
	$assignStatic(OpsAfterClose::CLOSE, $new($OpsAfterClose$7, "CLOSE"_s, 6));
	$assignStatic(OpsAfterClose::$VALUES, OpsAfterClose::$values());
}

OpsAfterClose::OpsAfterClose() {
}

$Class* OpsAfterClose::load$($String* name, bool initialize) {
	$loadClass(OpsAfterClose, name, initialize, &_OpsAfterClose_ClassInfo_, clinit$OpsAfterClose, allocate$OpsAfterClose);
	return class$;
}

$Class* OpsAfterClose::class$ = nullptr;