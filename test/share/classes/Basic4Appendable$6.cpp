#include <Basic4Appendable$6.h>

#include <Basic4Appendable.h>
#include <java/io/StringWriter.h>
#include <java/lang/Appendable.h>
#include <jcpp.h>

using $Basic4Appendable = ::Basic4Appendable;
using $StringWriter = ::java::io::StringWriter;
using $Appendable = ::java::lang::Appendable;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;

$FieldInfo _Basic4Appendable$6_FieldInfo_[] = {
	{"csn", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Basic4Appendable$6, csn)},
	{"exp", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Basic4Appendable$6, exp)},
	{"sw", "Ljava/io/StringWriter;", nullptr, $PRIVATE, $field(Basic4Appendable$6, sw)},
	{}
};

$MethodInfo _Basic4Appendable$6_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(Basic4Appendable$6, init$, void)},
	{"init", "(Ljava/lang/Appendable;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Basic4Appendable$6, init, void, $Appendable*, $String*, $String*)},
	{"reset", "(Ljava/lang/Appendable;)Ljava/lang/Appendable;", nullptr, $PUBLIC, $virtualMethod(Basic4Appendable$6, reset, $Appendable*, $Appendable*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(Basic4Appendable$6, run, void)},
	{}
};

$EnclosingMethodInfo _Basic4Appendable$6_EnclosingMethodInfo_ = {
	"Basic4Appendable",
	nullptr,
	nullptr
};

$InnerClassInfo _Basic4Appendable$6_InnerClassesInfo_[] = {
	{"Basic4Appendable$6", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Basic4Appendable$6_ClassInfo_ = {
	$ACC_SUPER,
	"Basic4Appendable$6",
	"java.lang.Object",
	"BasicRunnable",
	_Basic4Appendable$6_FieldInfo_,
	_Basic4Appendable$6_MethodInfo_,
	nullptr,
	&_Basic4Appendable$6_EnclosingMethodInfo_,
	_Basic4Appendable$6_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"Basic4Appendable"
};

$Object* allocate$Basic4Appendable$6($Class* clazz) {
	return $of($alloc(Basic4Appendable$6));
}

void Basic4Appendable$6::init$() {
}

void Basic4Appendable$6::init($Appendable* sw, $String* csn, $String* exp) {
	$set(this, sw, $cast($StringWriter, sw));
	$set(this, csn, csn);
	$set(this, exp, exp);
}

void Basic4Appendable$6::run() {
	$useLocalCurrentObjectStackCache();
	$Basic4Appendable::ck($$str({"StringWriter.append("_s, this->csn, ")"_s}), this->exp, $($nc(this->sw)->toString()));
}

$Appendable* Basic4Appendable$6::reset($Appendable* sw) {
	return $new($StringWriter);
}

Basic4Appendable$6::Basic4Appendable$6() {
}

$Class* Basic4Appendable$6::load$($String* name, bool initialize) {
	$loadClass(Basic4Appendable$6, name, initialize, &_Basic4Appendable$6_ClassInfo_, allocate$Basic4Appendable$6);
	return class$;
}

$Class* Basic4Appendable$6::class$ = nullptr;