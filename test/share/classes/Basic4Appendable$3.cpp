#include <Basic4Appendable$3.h>

#include <Basic4Appendable.h>
#include <java/io/BufferedReader.h>
#include <java/io/File.h>
#include <java/io/FileReader.h>
#include <java/io/FileWriter.h>
#include <java/io/IOException.h>
#include <java/io/Reader.h>
#include <java/lang/Appendable.h>
#include <jcpp.h>

using $Basic4Appendable = ::Basic4Appendable;
using $BufferedReader = ::java::io::BufferedReader;
using $FileReader = ::java::io::FileReader;
using $FileWriter = ::java::io::FileWriter;
using $IOException = ::java::io::IOException;
using $Reader = ::java::io::Reader;
using $Appendable = ::java::lang::Appendable;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;

$FieldInfo _Basic4Appendable$3_FieldInfo_[] = {
	{"csn", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Basic4Appendable$3, csn)},
	{"exp", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Basic4Appendable$3, exp)},
	{}
};

$MethodInfo _Basic4Appendable$3_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(Basic4Appendable$3, init$, void)},
	{"init", "(Ljava/lang/Appendable;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Basic4Appendable$3, init, void, $Appendable*, $String*, $String*)},
	{"reset", "(Ljava/lang/Appendable;)Ljava/lang/Appendable;", nullptr, $PUBLIC, $virtualMethod(Basic4Appendable$3, reset, $Appendable*, $Appendable*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(Basic4Appendable$3, run, void)},
	{}
};

$EnclosingMethodInfo _Basic4Appendable$3_EnclosingMethodInfo_ = {
	"Basic4Appendable",
	nullptr,
	nullptr
};

$InnerClassInfo _Basic4Appendable$3_InnerClassesInfo_[] = {
	{"Basic4Appendable$3", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Basic4Appendable$3_ClassInfo_ = {
	$ACC_SUPER,
	"Basic4Appendable$3",
	"java.lang.Object",
	"BasicRunnable",
	_Basic4Appendable$3_FieldInfo_,
	_Basic4Appendable$3_MethodInfo_,
	nullptr,
	&_Basic4Appendable$3_EnclosingMethodInfo_,
	_Basic4Appendable$3_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"Basic4Appendable"
};

$Object* allocate$Basic4Appendable$3($Class* clazz) {
	return $of($alloc(Basic4Appendable$3));
}

void Basic4Appendable$3::init$() {
}

void Basic4Appendable$3::init($Appendable* fw, $String* csn, $String* exp) {
	try {
		$nc(($cast($FileWriter, fw)))->flush();
	} catch ($IOException& x) {
		$Basic4Appendable::fail(x);
	}
	$set(this, csn, csn);
	$set(this, exp, exp);
}

void Basic4Appendable$3::run() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	try {
		$init($Basic4Appendable);
		$var($BufferedReader, in, $new($BufferedReader, $$new($FileReader, $Basic4Appendable::gf)));
		$var($String, line, nullptr);
		while (true) {
			if (($assign(line, in->readLine())) == nullptr) {
				break;
			}
			sb->append(line);
		}
	} catch ($IOException& x) {
		$Basic4Appendable::fail(x);
	}
	$Basic4Appendable::ck($$str({"FileWriter.append("_s, this->csn, ")"_s}), this->exp, $(sb->toString()));
}

$Appendable* Basic4Appendable$3::reset($Appendable* fw$renamed) {
	$var($Appendable, fw, fw$renamed);
	try {
		$init($Basic4Appendable);
		$assign(fw, $new($FileWriter, $Basic4Appendable::gf));
	} catch ($IOException& x) {
		$Basic4Appendable::fail(x);
	}
	return fw;
}

Basic4Appendable$3::Basic4Appendable$3() {
}

$Class* Basic4Appendable$3::load$($String* name, bool initialize) {
	$loadClass(Basic4Appendable$3, name, initialize, &_Basic4Appendable$3_ClassInfo_, allocate$Basic4Appendable$3);
	return class$;
}

$Class* Basic4Appendable$3::class$ = nullptr;