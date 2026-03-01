#include <OpsAfterClose4InputStream.h>

#include <OpsAfterClose4InputStream$1.h>
#include <OpsAfterClose4InputStream$2.h>
#include <OpsAfterClose4InputStream$3.h>
#include <OpsAfterClose4InputStream$4.h>
#include <OpsAfterClose4InputStream$5.h>
#include <OpsAfterClose4InputStream$6.h>
#include <OpsAfterClose4InputStream$7.h>
#include <OpsAfterClose4InputStream$8.h>
#include <OpsAfterClose4InputStream$9.h>
#include <java/io/BufferedInputStream.h>
#include <java/io/ByteArrayInputStream.h>
#include <java/io/DataInputStream.h>
#include <java/io/File.h>
#include <java/io/FileDescriptor.h>
#include <java/io/FileInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/PipedInputStream.h>
#include <java/io/PipedOutputStream.h>
#include <java/io/PushbackInputStream.h>
#include <java/lang/Enum.h>
#include <java/nio/channels/FileChannel.h>
#include <jcpp.h>

#undef AVAILABLE
#undef CLOSE
#undef MARK
#undef MARK_SUPPORTED
#undef READ
#undef READ_BUF
#undef READ_BUF_OFF
#undef RESET
#undef SKIP

using $OpsAfterClose4InputStream$1 = ::OpsAfterClose4InputStream$1;
using $OpsAfterClose4InputStream$2 = ::OpsAfterClose4InputStream$2;
using $OpsAfterClose4InputStream$3 = ::OpsAfterClose4InputStream$3;
using $OpsAfterClose4InputStream$4 = ::OpsAfterClose4InputStream$4;
using $OpsAfterClose4InputStream$5 = ::OpsAfterClose4InputStream$5;
using $OpsAfterClose4InputStream$6 = ::OpsAfterClose4InputStream$6;
using $OpsAfterClose4InputStream$7 = ::OpsAfterClose4InputStream$7;
using $OpsAfterClose4InputStream$8 = ::OpsAfterClose4InputStream$8;
using $OpsAfterClose4InputStream$9 = ::OpsAfterClose4InputStream$9;
using $OpsAfterClose4InputStreamArray = $Array<OpsAfterClose4InputStream>;
using $BufferedInputStream = ::java::io::BufferedInputStream;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $DataInputStream = ::java::io::DataInputStream;
using $File = ::java::io::File;
using $FileInputStream = ::java::io::FileInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $PipedInputStream = ::java::io::PipedInputStream;
using $PipedOutputStream = ::java::io::PipedOutputStream;
using $PrintStream = ::java::io::PrintStream;
using $PushbackInputStream = ::java::io::PushbackInputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;

$FieldInfo _OpsAfterClose4InputStream_FieldInfo_[] = {
	{"READ", "LOpsAfterClose4InputStream;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose4InputStream, READ)},
	{"READ_BUF", "LOpsAfterClose4InputStream;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose4InputStream, READ_BUF)},
	{"READ_BUF_OFF", "LOpsAfterClose4InputStream;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose4InputStream, READ_BUF_OFF)},
	{"AVAILABLE", "LOpsAfterClose4InputStream;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose4InputStream, AVAILABLE)},
	{"SKIP", "LOpsAfterClose4InputStream;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose4InputStream, SKIP)},
	{"MARK", "LOpsAfterClose4InputStream;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose4InputStream, MARK)},
	{"RESET", "LOpsAfterClose4InputStream;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose4InputStream, RESET)},
	{"MARK_SUPPORTED", "LOpsAfterClose4InputStream;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose4InputStream, MARK_SUPPORTED)},
	{"CLOSE", "LOpsAfterClose4InputStream;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose4InputStream, CLOSE)},
	{"$VALUES", "[LOpsAfterClose4InputStream;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(OpsAfterClose4InputStream, $VALUES)},
	{}
};

$MethodInfo _OpsAfterClose4InputStream_MethodInfo_[] = {
	{"$values", "()[LOpsAfterClose4InputStream;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(OpsAfterClose4InputStream, $values, $OpsAfterClose4InputStreamArray*)},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(OpsAfterClose4InputStream, init$, void, $String*, int32_t)},
	{"check", "(Ljava/io/InputStream;)Z", nullptr, $ABSTRACT, $virtualMethod(OpsAfterClose4InputStream, check, bool, $InputStream*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(OpsAfterClose4InputStream, main, void, $StringArray*), "java.lang.Exception"},
	{"testFileInputStream", "(Ljava/io/FileInputStream;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(OpsAfterClose4InputStream, testFileInputStream, bool, $FileInputStream*), "java.lang.Exception"},
	{"testInputStream", "(Ljava/io/InputStream;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(OpsAfterClose4InputStream, testInputStream, bool, $InputStream*), "java.lang.Exception"},
	{"testPushbackInputStream", "(Ljava/io/PushbackInputStream;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(OpsAfterClose4InputStream, testPushbackInputStream, bool, $PushbackInputStream*), "java.lang.Exception"},
	{"valueOf", "(Ljava/lang/String;)LOpsAfterClose4InputStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(OpsAfterClose4InputStream, valueOf, OpsAfterClose4InputStream*, $String*)},
	{"values", "()[LOpsAfterClose4InputStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(OpsAfterClose4InputStream, values, $OpsAfterClose4InputStreamArray*)},
	{}
};

$InnerClassInfo _OpsAfterClose4InputStream_InnerClassesInfo_[] = {
	{"OpsAfterClose4InputStream$9", nullptr, nullptr, $FINAL | $ENUM},
	{"OpsAfterClose4InputStream$8", nullptr, nullptr, $FINAL | $ENUM},
	{"OpsAfterClose4InputStream$7", nullptr, nullptr, $FINAL | $ENUM},
	{"OpsAfterClose4InputStream$6", nullptr, nullptr, $FINAL | $ENUM},
	{"OpsAfterClose4InputStream$5", nullptr, nullptr, $FINAL | $ENUM},
	{"OpsAfterClose4InputStream$4", nullptr, nullptr, $FINAL | $ENUM},
	{"OpsAfterClose4InputStream$3", nullptr, nullptr, $FINAL | $ENUM},
	{"OpsAfterClose4InputStream$2", nullptr, nullptr, $FINAL | $ENUM},
	{"OpsAfterClose4InputStream$1", nullptr, nullptr, $FINAL | $ENUM},
	{}
};

$ClassInfo _OpsAfterClose4InputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT | $ENUM,
	"OpsAfterClose4InputStream",
	"java.lang.Enum",
	nullptr,
	_OpsAfterClose4InputStream_FieldInfo_,
	_OpsAfterClose4InputStream_MethodInfo_,
	"Ljava/lang/Enum<LOpsAfterClose4InputStream;>;",
	nullptr,
	_OpsAfterClose4InputStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	"OpsAfterClose4InputStream$9,OpsAfterClose4InputStream$8,OpsAfterClose4InputStream$7,OpsAfterClose4InputStream$6,OpsAfterClose4InputStream$5,OpsAfterClose4InputStream$4,OpsAfterClose4InputStream$3,OpsAfterClose4InputStream$2,OpsAfterClose4InputStream$1"
};

$Object* allocate$OpsAfterClose4InputStream($Class* clazz) {
	return $of($alloc(OpsAfterClose4InputStream));
}

OpsAfterClose4InputStream* OpsAfterClose4InputStream::READ = nullptr;
OpsAfterClose4InputStream* OpsAfterClose4InputStream::READ_BUF = nullptr;
OpsAfterClose4InputStream* OpsAfterClose4InputStream::READ_BUF_OFF = nullptr;
OpsAfterClose4InputStream* OpsAfterClose4InputStream::AVAILABLE = nullptr;
OpsAfterClose4InputStream* OpsAfterClose4InputStream::SKIP = nullptr;
OpsAfterClose4InputStream* OpsAfterClose4InputStream::MARK = nullptr;
OpsAfterClose4InputStream* OpsAfterClose4InputStream::RESET = nullptr;
OpsAfterClose4InputStream* OpsAfterClose4InputStream::MARK_SUPPORTED = nullptr;
OpsAfterClose4InputStream* OpsAfterClose4InputStream::CLOSE = nullptr;
$OpsAfterClose4InputStreamArray* OpsAfterClose4InputStream::$VALUES = nullptr;

$OpsAfterClose4InputStreamArray* OpsAfterClose4InputStream::$values() {
	$init(OpsAfterClose4InputStream);
	return $new($OpsAfterClose4InputStreamArray, {
		OpsAfterClose4InputStream::READ,
		OpsAfterClose4InputStream::READ_BUF,
		OpsAfterClose4InputStream::READ_BUF_OFF,
		OpsAfterClose4InputStream::AVAILABLE,
		OpsAfterClose4InputStream::SKIP,
		OpsAfterClose4InputStream::MARK,
		OpsAfterClose4InputStream::RESET,
		OpsAfterClose4InputStream::MARK_SUPPORTED,
		OpsAfterClose4InputStream::CLOSE
	});
}

$OpsAfterClose4InputStreamArray* OpsAfterClose4InputStream::values() {
	$init(OpsAfterClose4InputStream);
	return $cast($OpsAfterClose4InputStreamArray, OpsAfterClose4InputStream::$VALUES->clone());
}

OpsAfterClose4InputStream* OpsAfterClose4InputStream::valueOf($String* name) {
	$init(OpsAfterClose4InputStream);
	return $cast(OpsAfterClose4InputStream, $Enum::valueOf(OpsAfterClose4InputStream::class$, name));
}

void OpsAfterClose4InputStream::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

void OpsAfterClose4InputStream::main($StringArray* args) {
	$init(OpsAfterClose4InputStream);
	$useLocalCurrentObjectStackCache();
	bool failed = false;
	$var($File, f, $new($File, $($System::getProperty("test.dir"_s, "."_s)), "f.txt"_s));
	f->createNewFile();
	f->deleteOnExit();
	$var($FileInputStream, fis, $new($FileInputStream, f));
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (testInputStream(fis)) {
				failed = true;
			}
			if (testFileInputStream(fis)) {
				failed = true;
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			fis->close();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$var($BufferedInputStream, bs, $new($BufferedInputStream, $$new($FileInputStream, f)));
	{
		$var($Throwable, var$2, nullptr);
		try {
			if (testInputStream(bs)) {
				failed = true;
			}
		} catch ($Throwable& var$3) {
			$assign(var$2, var$3);
		} /*finally*/ {
			bs->close();
		}
		if (var$2 != nullptr) {
			$throw(var$2);
		}
	}
	$var($DataInputStream, dis, $new($DataInputStream, $$new($FileInputStream, f)));
	{
		$var($Throwable, var$4, nullptr);
		try {
			if (testInputStream(dis)) {
				failed = true;
			}
		} catch ($Throwable& var$5) {
			$assign(var$4, var$5);
		} /*finally*/ {
			dis->close();
		}
		if (var$4 != nullptr) {
			$throw(var$4);
		}
	}
	$var($PushbackInputStream, pbis, $new($PushbackInputStream, $$new($ByteArrayInputStream, $$new($bytes, 20))));
	if (testInputStream(pbis)) {
		failed = true;
	}
	if (testPushbackInputStream(pbis)) {
		failed = true;
	}
	$var($PipedInputStream, pis, $new($PipedInputStream, $$new($PipedOutputStream)));
	if (testInputStream(pis)) {
		failed = true;
	}
	if (failed) {
		$throwNew($Exception, "Some Op for some Stream failed, check the failed status above"_s);
	}
}

bool OpsAfterClose4InputStream::testInputStream($InputStream* is) {
	$init(OpsAfterClose4InputStream);
	$useLocalCurrentObjectStackCache();
	$nc(is)->close();
	bool failed = false;
	bool result = false;
	$nc($System::out)->println($$str({"Testing :"_s, is}));
	{
		$var($OpsAfterClose4InputStreamArray, arr$, OpsAfterClose4InputStream::values());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			OpsAfterClose4InputStream* op = arr$->get(i$);
			{
				if ($nc(op)->equals(OpsAfterClose4InputStream::AVAILABLE) && ($instanceOf($PipedInputStream, is))) {
					continue;
				}
				result = $nc(op)->check(is);
				if (!result) {
					failed = true;
				}
				$nc($System::out)->println($$str({op, ":"_s, $$str(result)}));
			}
		}
	}
	if (failed) {
		$nc($System::out)->println($$str({"Test failed for the failed operation{s} above for :"_s, is}));
	}
	return failed;
}

bool OpsAfterClose4InputStream::testPushbackInputStream($PushbackInputStream* pis) {
	$init(OpsAfterClose4InputStream);
	$useLocalCurrentObjectStackCache();
	bool failed = false;
	try {
		$nc(pis)->unread(1);
		$nc($System::out)->println($$str({"Test failed for unread(int):"_s, pis}));
		failed = true;
	} catch ($IOException& io) {
		$nc($System::out)->println("UNREAD(int):true"_s);
	}
	$var($bytes, buf, $new($bytes, 2));
	try {
		$nc(pis)->unread(buf, 0, 2);
		$nc($System::out)->println($$str({"Test failed for unread(buf, offset, len):"_s, pis}));
		failed = true;
	} catch ($IOException& io) {
		$nc($System::out)->println("UNREAD(buf, offset, len):true"_s);
	}
	try {
		$nc(pis)->unread(buf);
		$nc($System::out)->println($$str({"Test failed for unread(char[] buf):"_s, pis}));
		failed = true;
	} catch ($IOException& io) {
		$nc($System::out)->println("UNREAD(buf):true"_s);
	}
	return failed;
}

bool OpsAfterClose4InputStream::testFileInputStream($FileInputStream* fis) {
	$init(OpsAfterClose4InputStream);
	bool failed = false;
	try {
		$nc(fis)->getFD();
		$nc($System::out)->println("GetFD: true"_s);
	} catch ($IOException& io) {
		$nc($System::out)->println("GetFD: false"_s);
		failed = true;
	}
	$nc(fis)->getChannel();
	$nc($System::out)->println("GetChannel: true"_s);
	return failed;
}

void clinit$OpsAfterClose4InputStream($Class* class$) {
	$assignStatic(OpsAfterClose4InputStream::READ, $new($OpsAfterClose4InputStream$1, "READ"_s, 0));
	$assignStatic(OpsAfterClose4InputStream::READ_BUF, $new($OpsAfterClose4InputStream$2, "READ_BUF"_s, 1));
	$assignStatic(OpsAfterClose4InputStream::READ_BUF_OFF, $new($OpsAfterClose4InputStream$3, "READ_BUF_OFF"_s, 2));
	$assignStatic(OpsAfterClose4InputStream::AVAILABLE, $new($OpsAfterClose4InputStream$4, "AVAILABLE"_s, 3));
	$assignStatic(OpsAfterClose4InputStream::SKIP, $new($OpsAfterClose4InputStream$5, "SKIP"_s, 4));
	$assignStatic(OpsAfterClose4InputStream::MARK, $new($OpsAfterClose4InputStream$6, "MARK"_s, 5));
	$assignStatic(OpsAfterClose4InputStream::RESET, $new($OpsAfterClose4InputStream$7, "RESET"_s, 6));
	$assignStatic(OpsAfterClose4InputStream::MARK_SUPPORTED, $new($OpsAfterClose4InputStream$8, "MARK_SUPPORTED"_s, 7));
	$assignStatic(OpsAfterClose4InputStream::CLOSE, $new($OpsAfterClose4InputStream$9, "CLOSE"_s, 8));
	$assignStatic(OpsAfterClose4InputStream::$VALUES, OpsAfterClose4InputStream::$values());
}

OpsAfterClose4InputStream::OpsAfterClose4InputStream() {
}

$Class* OpsAfterClose4InputStream::load$($String* name, bool initialize) {
	$loadClass(OpsAfterClose4InputStream, name, initialize, &_OpsAfterClose4InputStream_ClassInfo_, clinit$OpsAfterClose4InputStream, allocate$OpsAfterClose4InputStream);
	return class$;
}

$Class* OpsAfterClose4InputStream::class$ = nullptr;