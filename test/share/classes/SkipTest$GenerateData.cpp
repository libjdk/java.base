#include <SkipTest$GenerateData.h>

#include <SkipTest.h>
#include <java/io/BufferedOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <jcpp.h>

using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;

$MethodInfo _SkipTest$GenerateData_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(SkipTest$GenerateData, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(SkipTest$GenerateData, main, void, $StringArray*)},
	{}
};

$InnerClassInfo _SkipTest$GenerateData_InnerClassesInfo_[] = {
	{"SkipTest$GenerateData", "SkipTest", "GenerateData", $STATIC},
	{}
};

$ClassInfo _SkipTest$GenerateData_ClassInfo_ = {
	$ACC_SUPER,
	"SkipTest$GenerateData",
	"java.lang.Object",
	nullptr,
	nullptr,
	_SkipTest$GenerateData_MethodInfo_,
	nullptr,
	nullptr,
	_SkipTest$GenerateData_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"SkipTest"
};

$Object* allocate$SkipTest$GenerateData($Class* clazz) {
	return $of($alloc(SkipTest$GenerateData));
}

void SkipTest$GenerateData::init$() {
}

void SkipTest$GenerateData::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($OutputStream, out, $new($BufferedOutputStream, $System::out));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					for (int32_t header = u'A'; header <= u'Z'; ++header) {
						out->write(header);
						int32_t data = $Character::toLowerCase(header);
						for (int32_t i = 0; i < 10000; ++i) {
							out->write(data);
						}
					}
				} catch ($Throwable& t$) {
					try {
						out->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				out->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} catch ($IOException& ioe) {
		ioe->printStackTrace();
		$System::exit(1);
	}
	try {
		$var($OutputStream, err, $new($BufferedOutputStream, $System::err));
		{
			$var($Throwable, var$2, nullptr);
			try {
				try {
					for (int32_t header = u'A'; header <= u'Z'; ++header) {
						err->write(header);
						int32_t data = $Character::toLowerCase(header);
						for (int32_t i = 0; i < 10000; ++i) {
							err->write(data);
						}
					}
				} catch ($Throwable& t$) {
					try {
						err->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$2, var$3);
			} /*finally*/ {
				err->close();
			}
			if (var$2 != nullptr) {
				$throw(var$2);
			}
		}
	} catch ($IOException& ioe) {
		ioe->printStackTrace();
		$System::exit(1);
	}
}

SkipTest$GenerateData::SkipTest$GenerateData() {
}

$Class* SkipTest$GenerateData::load$($String* name, bool initialize) {
	$loadClass(SkipTest$GenerateData, name, initialize, &_SkipTest$GenerateData_ClassInfo_, allocate$SkipTest$GenerateData);
	return class$;
}

$Class* SkipTest$GenerateData::class$ = nullptr;