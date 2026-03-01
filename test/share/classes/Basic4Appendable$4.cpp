#include <Basic4Appendable$4.h>

#include <Basic4Appendable.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/OutputStreamWriter.h>
#include <java/lang/Appendable.h>
#include <jcpp.h>

using $Basic4Appendable = ::Basic4Appendable;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $OutputStreamWriter = ::java::io::OutputStreamWriter;
using $Appendable = ::java::lang::Appendable;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;

$FieldInfo _Basic4Appendable$4_FieldInfo_[] = {
	{"csn", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Basic4Appendable$4, csn)},
	{"exp", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Basic4Appendable$4, exp)},
	{}
};

$MethodInfo _Basic4Appendable$4_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(Basic4Appendable$4, init$, void)},
	{"init", "(Ljava/lang/Appendable;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Basic4Appendable$4, init, void, $Appendable*, $String*, $String*)},
	{"reset", "(Ljava/lang/Appendable;)Ljava/lang/Appendable;", nullptr, $PUBLIC, $virtualMethod(Basic4Appendable$4, reset, $Appendable*, $Appendable*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(Basic4Appendable$4, run, void)},
	{}
};

$EnclosingMethodInfo _Basic4Appendable$4_EnclosingMethodInfo_ = {
	"Basic4Appendable",
	nullptr,
	nullptr
};

$InnerClassInfo _Basic4Appendable$4_InnerClassesInfo_[] = {
	{"Basic4Appendable$4", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Basic4Appendable$4_ClassInfo_ = {
	$ACC_SUPER,
	"Basic4Appendable$4",
	"java.lang.Object",
	"BasicRunnable",
	_Basic4Appendable$4_FieldInfo_,
	_Basic4Appendable$4_MethodInfo_,
	nullptr,
	&_Basic4Appendable$4_EnclosingMethodInfo_,
	_Basic4Appendable$4_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"Basic4Appendable"
};

$Object* allocate$Basic4Appendable$4($Class* clazz) {
	return $of($alloc(Basic4Appendable$4));
}

void Basic4Appendable$4::init$() {
}

void Basic4Appendable$4::init($Appendable* osw, $String* csn, $String* exp) {
	try {
		$nc(($cast($OutputStreamWriter, osw)))->flush();
	} catch ($IOException& x) {
		$Basic4Appendable::fail(x);
	}
	$set(this, csn, csn);
	$set(this, exp, exp);
}

void Basic4Appendable$4::run() {
	$useLocalCurrentObjectStackCache();
	$init($Basic4Appendable);
	$Basic4Appendable::ck($$str({"OutputStreamWriter.append("_s, this->csn, ")"_s}), this->exp, $($nc($Basic4Appendable::gos)->toString()));
}

$Appendable* Basic4Appendable$4::reset($Appendable* osw) {
	$init($Basic4Appendable);
	$nc($Basic4Appendable::gos)->reset();
	return osw;
}

Basic4Appendable$4::Basic4Appendable$4() {
}

$Class* Basic4Appendable$4::load$($String* name, bool initialize) {
	$loadClass(Basic4Appendable$4, name, initialize, &_Basic4Appendable$4_ClassInfo_, allocate$Basic4Appendable$4);
	return class$;
}

$Class* Basic4Appendable$4::class$ = nullptr;