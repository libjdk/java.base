#include <AnotherSelectFdsLimit.h>

#include <AnotherSelectFdsLimit$WorkerThread.h>
#include <java/lang/CharSequence.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jcpp.h>

#undef DEFAULT_FDS_TO_USE

using $AnotherSelectFdsLimit$WorkerThread = ::AnotherSelectFdsLimit$WorkerThread;
using $PrintStream = ::java::io::PrintStream;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;

$FieldInfo _AnotherSelectFdsLimit_FieldInfo_[] = {
	{"DEFAULT_FDS_TO_USE", "I", nullptr, $STATIC | $FINAL, $constField(AnotherSelectFdsLimit, DEFAULT_FDS_TO_USE)},
	{}
};

$MethodInfo _AnotherSelectFdsLimit_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(AnotherSelectFdsLimit, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(AnotherSelectFdsLimit, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$InnerClassInfo _AnotherSelectFdsLimit_InnerClassesInfo_[] = {
	{"AnotherSelectFdsLimit$WorkerThread", "AnotherSelectFdsLimit", "WorkerThread", $STATIC},
	{}
};

$ClassInfo _AnotherSelectFdsLimit_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"AnotherSelectFdsLimit",
	"java.lang.Object",
	nullptr,
	_AnotherSelectFdsLimit_FieldInfo_,
	_AnotherSelectFdsLimit_MethodInfo_,
	nullptr,
	nullptr,
	_AnotherSelectFdsLimit_InnerClassesInfo_,
	nullptr,
	nullptr,
	"AnotherSelectFdsLimit$WorkerThread"
};

$Object* allocate$AnotherSelectFdsLimit($Class* clazz) {
	return $of($alloc(AnotherSelectFdsLimit));
}

void AnotherSelectFdsLimit::init$() {
}

void AnotherSelectFdsLimit::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	if (!$nc($($System::getProperty("os.name"_s)))->contains("OS X"_s)) {
		$nc($System::out)->println("Test only run on MAC. Exiting."_s);
		return;
	}
	int32_t fdsToUse = AnotherSelectFdsLimit::DEFAULT_FDS_TO_USE;
	if ($nc(args)->length == 1) {
		fdsToUse = $Integer::parseInt(args->get(0));
	}
	$nc($System::out)->println($$str({"Using "_s, $$str(fdsToUse), " fds."_s}));
	$var($List, threads, $new($ArrayList));
	for (int32_t i = 0; i < fdsToUse; ++i) {
		threads->add($$new($AnotherSelectFdsLimit$WorkerThread));
	}
	{
		$var($Iterator, i$, threads->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Thread, t, $cast($Thread, i$->next()));
			$nc(t)->start();
		}
	}
	{
		$var($Iterator, i$, threads->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Thread, t, $cast($Thread, i$->next()));
			$nc(t)->join();
		}
	}
}

AnotherSelectFdsLimit::AnotherSelectFdsLimit() {
}

$Class* AnotherSelectFdsLimit::load$($String* name, bool initialize) {
	$loadClass(AnotherSelectFdsLimit, name, initialize, &_AnotherSelectFdsLimit_ClassInfo_, allocate$AnotherSelectFdsLimit);
	return class$;
}

$Class* AnotherSelectFdsLimit::class$ = nullptr;