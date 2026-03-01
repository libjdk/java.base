#include <ImmutableLocal.h>

#include <ImmutableLocal$1.h>
#include <java/lang/ThreadLocal.h>
#include <jcpp.h>

using $ImmutableLocal$1 = ::ImmutableLocal$1;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ThreadLocal = ::java::lang::ThreadLocal;

$FieldInfo _ImmutableLocal_FieldInfo_[] = {
	{"cache", "Ljava/lang/ThreadLocal;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ImmutableLocal, cache)},
	{}
};

$MethodInfo _ImmutableLocal_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ImmutableLocal, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ImmutableLocal, main, void, $StringArray*)},
	{}
};

$InnerClassInfo _ImmutableLocal_InnerClassesInfo_[] = {
	{"ImmutableLocal$ImmutableThreadLocal", "ImmutableLocal", "ImmutableThreadLocal", $PUBLIC | $STATIC | $ABSTRACT},
	{"ImmutableLocal$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ImmutableLocal_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ImmutableLocal",
	"java.lang.Object",
	nullptr,
	_ImmutableLocal_FieldInfo_,
	_ImmutableLocal_MethodInfo_,
	nullptr,
	nullptr,
	_ImmutableLocal_InnerClassesInfo_,
	nullptr,
	nullptr,
	"ImmutableLocal$ImmutableThreadLocal,ImmutableLocal$1"
};

$Object* allocate$ImmutableLocal($Class* clazz) {
	return $of($alloc(ImmutableLocal));
}

$ThreadLocal* ImmutableLocal::cache = nullptr;

void ImmutableLocal::init$() {
}

void ImmutableLocal::main($StringArray* args) {
	$init(ImmutableLocal);
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println($$str({"cache.get() = "_s, $($nc(ImmutableLocal::cache)->get())}));
}

void clinit$ImmutableLocal($Class* class$) {
	$assignStatic(ImmutableLocal::cache, $new($ImmutableLocal$1));
}

ImmutableLocal::ImmutableLocal() {
}

$Class* ImmutableLocal::load$($String* name, bool initialize) {
	$loadClass(ImmutableLocal, name, initialize, &_ImmutableLocal_ClassInfo_, clinit$ImmutableLocal, allocate$ImmutableLocal);
	return class$;
}

$Class* ImmutableLocal::class$ = nullptr;