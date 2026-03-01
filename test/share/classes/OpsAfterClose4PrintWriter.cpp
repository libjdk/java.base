#include <OpsAfterClose4PrintWriter.h>

#include <OpsAfterClose4PrintWriter$1.h>
#include <OpsAfterClose4PrintWriter$2.h>
#include <OpsAfterClose4PrintWriter$3.h>
#include <OpsAfterClose4PrintWriter$4.h>
#include <OpsAfterClose4PrintWriter$5.h>
#include <java/io/File.h>
#include <java/io/FileWriter.h>
#include <java/io/PrintWriter.h>
#include <java/io/Writer.h>
#include <java/lang/Enum.h>
#include <jcpp.h>

#undef WRITE_BUF
#undef WRITE_BUF_OFF
#undef WRITE_INT
#undef WRITE_STR
#undef WRITE_STR_OFF

using $OpsAfterClose4PrintWriter$1 = ::OpsAfterClose4PrintWriter$1;
using $OpsAfterClose4PrintWriter$2 = ::OpsAfterClose4PrintWriter$2;
using $OpsAfterClose4PrintWriter$3 = ::OpsAfterClose4PrintWriter$3;
using $OpsAfterClose4PrintWriter$4 = ::OpsAfterClose4PrintWriter$4;
using $OpsAfterClose4PrintWriter$5 = ::OpsAfterClose4PrintWriter$5;
using $OpsAfterClose4PrintWriterArray = $Array<OpsAfterClose4PrintWriter>;
using $File = ::java::io::File;
using $FileWriter = ::java::io::FileWriter;
using $PrintStream = ::java::io::PrintStream;
using $PrintWriter = ::java::io::PrintWriter;
using $Writer = ::java::io::Writer;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;

$FieldInfo _OpsAfterClose4PrintWriter_FieldInfo_[] = {
	{"WRITE_BUF", "LOpsAfterClose4PrintWriter;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose4PrintWriter, WRITE_BUF)},
	{"WRITE_BUF_OFF", "LOpsAfterClose4PrintWriter;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose4PrintWriter, WRITE_BUF_OFF)},
	{"WRITE_INT", "LOpsAfterClose4PrintWriter;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose4PrintWriter, WRITE_INT)},
	{"WRITE_STR", "LOpsAfterClose4PrintWriter;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose4PrintWriter, WRITE_STR)},
	{"WRITE_STR_OFF", "LOpsAfterClose4PrintWriter;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(OpsAfterClose4PrintWriter, WRITE_STR_OFF)},
	{"$VALUES", "[LOpsAfterClose4PrintWriter;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(OpsAfterClose4PrintWriter, $VALUES)},
	{}
};

$MethodInfo _OpsAfterClose4PrintWriter_MethodInfo_[] = {
	{"$values", "()[LOpsAfterClose4PrintWriter;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(OpsAfterClose4PrintWriter, $values, $OpsAfterClose4PrintWriterArray*)},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(OpsAfterClose4PrintWriter, init$, void, $String*, int32_t)},
	{"check", "(Ljava/io/PrintWriter;)Z", nullptr, $ABSTRACT, $virtualMethod(OpsAfterClose4PrintWriter, check, bool, $PrintWriter*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(OpsAfterClose4PrintWriter, main, void, $StringArray*), "java.lang.Exception"},
	{"valueOf", "(Ljava/lang/String;)LOpsAfterClose4PrintWriter;", nullptr, $PUBLIC | $STATIC, $staticMethod(OpsAfterClose4PrintWriter, valueOf, OpsAfterClose4PrintWriter*, $String*)},
	{"values", "()[LOpsAfterClose4PrintWriter;", nullptr, $PUBLIC | $STATIC, $staticMethod(OpsAfterClose4PrintWriter, values, $OpsAfterClose4PrintWriterArray*)},
	{}
};

$InnerClassInfo _OpsAfterClose4PrintWriter_InnerClassesInfo_[] = {
	{"OpsAfterClose4PrintWriter$5", nullptr, nullptr, $FINAL | $ENUM},
	{"OpsAfterClose4PrintWriter$4", nullptr, nullptr, $FINAL | $ENUM},
	{"OpsAfterClose4PrintWriter$3", nullptr, nullptr, $FINAL | $ENUM},
	{"OpsAfterClose4PrintWriter$2", nullptr, nullptr, $FINAL | $ENUM},
	{"OpsAfterClose4PrintWriter$1", nullptr, nullptr, $FINAL | $ENUM},
	{}
};

$ClassInfo _OpsAfterClose4PrintWriter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT | $ENUM,
	"OpsAfterClose4PrintWriter",
	"java.lang.Enum",
	nullptr,
	_OpsAfterClose4PrintWriter_FieldInfo_,
	_OpsAfterClose4PrintWriter_MethodInfo_,
	"Ljava/lang/Enum<LOpsAfterClose4PrintWriter;>;",
	nullptr,
	_OpsAfterClose4PrintWriter_InnerClassesInfo_,
	nullptr,
	nullptr,
	"OpsAfterClose4PrintWriter$5,OpsAfterClose4PrintWriter$4,OpsAfterClose4PrintWriter$3,OpsAfterClose4PrintWriter$2,OpsAfterClose4PrintWriter$1"
};

$Object* allocate$OpsAfterClose4PrintWriter($Class* clazz) {
	return $of($alloc(OpsAfterClose4PrintWriter));
}

OpsAfterClose4PrintWriter* OpsAfterClose4PrintWriter::WRITE_BUF = nullptr;
OpsAfterClose4PrintWriter* OpsAfterClose4PrintWriter::WRITE_BUF_OFF = nullptr;
OpsAfterClose4PrintWriter* OpsAfterClose4PrintWriter::WRITE_INT = nullptr;
OpsAfterClose4PrintWriter* OpsAfterClose4PrintWriter::WRITE_STR = nullptr;
OpsAfterClose4PrintWriter* OpsAfterClose4PrintWriter::WRITE_STR_OFF = nullptr;
$OpsAfterClose4PrintWriterArray* OpsAfterClose4PrintWriter::$VALUES = nullptr;

$OpsAfterClose4PrintWriterArray* OpsAfterClose4PrintWriter::$values() {
	$init(OpsAfterClose4PrintWriter);
	return $new($OpsAfterClose4PrintWriterArray, {
		OpsAfterClose4PrintWriter::WRITE_BUF,
		OpsAfterClose4PrintWriter::WRITE_BUF_OFF,
		OpsAfterClose4PrintWriter::WRITE_INT,
		OpsAfterClose4PrintWriter::WRITE_STR,
		OpsAfterClose4PrintWriter::WRITE_STR_OFF
	});
}

$OpsAfterClose4PrintWriterArray* OpsAfterClose4PrintWriter::values() {
	$init(OpsAfterClose4PrintWriter);
	return $cast($OpsAfterClose4PrintWriterArray, OpsAfterClose4PrintWriter::$VALUES->clone());
}

OpsAfterClose4PrintWriter* OpsAfterClose4PrintWriter::valueOf($String* name) {
	$init(OpsAfterClose4PrintWriter);
	return $cast(OpsAfterClose4PrintWriter, $Enum::valueOf(OpsAfterClose4PrintWriter::class$, name));
}

void OpsAfterClose4PrintWriter::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

void OpsAfterClose4PrintWriter::main($StringArray* args) {
	$init(OpsAfterClose4PrintWriter);
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println("Testing PrintWriter"_s);
	bool failed = false;
	bool result = false;
	$var($File, f, $new($File, $($System::getProperty("test.dir"_s, "."_s)), "print-writer.out"_s));
	f->deleteOnExit();
	{
		$var($OpsAfterClose4PrintWriterArray, arr$, OpsAfterClose4PrintWriter::values());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			OpsAfterClose4PrintWriter* op = arr$->get(i$);
			{
				$var($PrintWriter, pw, $new($PrintWriter, static_cast<$Writer*>($$new($FileWriter, f))));
				pw->close();
				result = $nc(op)->check(pw);
				if (!result) {
					failed = true;
				}
				$nc($System::out)->println($$str({op, ":"_s, $$str(result)}));
			}
		}
	}
	if (failed) {
		$throwNew($Exception, "Test failed for the failed operation{s} above for the PrintWriter"_s);
	}
}

void clinit$OpsAfterClose4PrintWriter($Class* class$) {
	$assignStatic(OpsAfterClose4PrintWriter::WRITE_BUF, $new($OpsAfterClose4PrintWriter$1, "WRITE_BUF"_s, 0));
	$assignStatic(OpsAfterClose4PrintWriter::WRITE_BUF_OFF, $new($OpsAfterClose4PrintWriter$2, "WRITE_BUF_OFF"_s, 1));
	$assignStatic(OpsAfterClose4PrintWriter::WRITE_INT, $new($OpsAfterClose4PrintWriter$3, "WRITE_INT"_s, 2));
	$assignStatic(OpsAfterClose4PrintWriter::WRITE_STR, $new($OpsAfterClose4PrintWriter$4, "WRITE_STR"_s, 3));
	$assignStatic(OpsAfterClose4PrintWriter::WRITE_STR_OFF, $new($OpsAfterClose4PrintWriter$5, "WRITE_STR_OFF"_s, 4));
	$assignStatic(OpsAfterClose4PrintWriter::$VALUES, OpsAfterClose4PrintWriter::$values());
}

OpsAfterClose4PrintWriter::OpsAfterClose4PrintWriter() {
}

$Class* OpsAfterClose4PrintWriter::load$($String* name, bool initialize) {
	$loadClass(OpsAfterClose4PrintWriter, name, initialize, &_OpsAfterClose4PrintWriter_ClassInfo_, clinit$OpsAfterClose4PrintWriter, allocate$OpsAfterClose4PrintWriter);
	return class$;
}

$Class* OpsAfterClose4PrintWriter::class$ = nullptr;