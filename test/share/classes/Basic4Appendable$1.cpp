#include <Basic4Appendable$1.h>

#include <Basic4Appendable.h>
#include <java/io/BufferedWriter.h>
#include <java/io/CharArrayWriter.h>
#include <java/io/IOException.h>
#include <java/lang/Appendable.h>
#include <jcpp.h>

using $Basic4Appendable = ::Basic4Appendable;
using $BufferedWriter = ::java::io::BufferedWriter;
using $CharArrayWriter = ::java::io::CharArrayWriter;
using $IOException = ::java::io::IOException;
using $Appendable = ::java::lang::Appendable;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;

$FieldInfo _Basic4Appendable$1_FieldInfo_[] = {
	{"csn", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Basic4Appendable$1, csn)},
	{"exp", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Basic4Appendable$1, exp)},
	{}
};

$MethodInfo _Basic4Appendable$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(Basic4Appendable$1, init$, void)},
	{"init", "(Ljava/lang/Appendable;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Basic4Appendable$1, init, void, $Appendable*, $String*, $String*)},
	{"reset", "(Ljava/lang/Appendable;)Ljava/lang/Appendable;", nullptr, $PUBLIC, $virtualMethod(Basic4Appendable$1, reset, $Appendable*, $Appendable*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(Basic4Appendable$1, run, void)},
	{}
};

$EnclosingMethodInfo _Basic4Appendable$1_EnclosingMethodInfo_ = {
	"Basic4Appendable",
	nullptr,
	nullptr
};

$InnerClassInfo _Basic4Appendable$1_InnerClassesInfo_[] = {
	{"Basic4Appendable$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Basic4Appendable$1_ClassInfo_ = {
	$ACC_SUPER,
	"Basic4Appendable$1",
	"java.lang.Object",
	"BasicRunnable",
	_Basic4Appendable$1_FieldInfo_,
	_Basic4Appendable$1_MethodInfo_,
	nullptr,
	&_Basic4Appendable$1_EnclosingMethodInfo_,
	_Basic4Appendable$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"Basic4Appendable"
};

$Object* allocate$Basic4Appendable$1($Class* clazz) {
	return $of($alloc(Basic4Appendable$1));
}

void Basic4Appendable$1::init$() {
}

void Basic4Appendable$1::init($Appendable* bw, $String* csn, $String* exp) {
	try {
		$nc(($cast($BufferedWriter, bw)))->flush();
	} catch ($IOException& x) {
		$Basic4Appendable::fail(x);
	}
	$set(this, csn, csn);
	$set(this, exp, exp);
}

void Basic4Appendable$1::run() {
	$useLocalCurrentObjectStackCache();
	$init($Basic4Appendable);
	$Basic4Appendable::ck($$str({"BufferedWriter.append("_s, this->csn, ")"_s}), this->exp, $($nc($Basic4Appendable::gw)->toString()));
}

$Appendable* Basic4Appendable$1::reset($Appendable* bw) {
	$init($Basic4Appendable);
	$nc($Basic4Appendable::gw)->reset();
	return bw;
}

Basic4Appendable$1::Basic4Appendable$1() {
}

$Class* Basic4Appendable$1::load$($String* name, bool initialize) {
	$loadClass(Basic4Appendable$1, name, initialize, &_Basic4Appendable$1_ClassInfo_, allocate$Basic4Appendable$1);
	return class$;
}

$Class* Basic4Appendable$1::class$ = nullptr;