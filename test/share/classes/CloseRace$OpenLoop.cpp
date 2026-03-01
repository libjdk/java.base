#include <CloseRace$OpenLoop.h>

#include <CloseRace.h>
#include <java/io/FileInputStream.h>
#include <java/io/InputStream.h>
#include <java/lang/Error.h>
#include <java/lang/InterruptedException.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/concurrent/CountDownLatch.h>
#include <jcpp.h>

using $CloseRace = ::CloseRace;
using $FileInputStream = ::java::io::FileInputStream;
using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $CountDownLatch = ::java::util::concurrent::CountDownLatch;

$MethodInfo _CloseRace$OpenLoop_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(CloseRace$OpenLoop, init$, void)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(CloseRace$OpenLoop, run, void)},
	{}
};

$InnerClassInfo _CloseRace$OpenLoop_InnerClassesInfo_[] = {
	{"CloseRace$OpenLoop", "CloseRace", "OpenLoop", $STATIC},
	{}
};

$ClassInfo _CloseRace$OpenLoop_ClassInfo_ = {
	$ACC_SUPER,
	"CloseRace$OpenLoop",
	"java.lang.Object",
	"java.lang.Runnable",
	nullptr,
	_CloseRace$OpenLoop_MethodInfo_,
	nullptr,
	nullptr,
	_CloseRace$OpenLoop_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"CloseRace"
};

$Object* allocate$CloseRace$OpenLoop($Class* clazz) {
	return $of($alloc(CloseRace$OpenLoop));
}

void CloseRace$OpenLoop::init$() {
}

void CloseRace$OpenLoop::run() {
	$useLocalCurrentObjectStackCache();
	$init($CloseRace);
	$nc($CloseRace::threadsStarted)->countDown();
	while (!$Thread::interrupted()) {
		try {
			do {
				if ($Thread::interrupted()) {
					return;
				}
			} while ($CloseRace::count($($CloseRace::procFDsInUse())) != 3);
			$var($List, iss, $new($ArrayList, 4));
			for (int32_t i = 0; i < 3; ++i) {
				iss->add($$new($FileInputStream, "bigfile"_s));
			}
			do {
				if ($Thread::interrupted()) {
					return;
				}
			} while ($CloseRace::count($($CloseRace::procFDsInUse())) == $nc($CloseRace::procFDs)->length);
			iss->add($$new($FileInputStream, "bigfile"_s));
			$Thread::sleep(1);
			{
				$var($Iterator, i$, iss->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($InputStream, is, $cast($InputStream, i$->next()));
					$nc(is)->close();
				}
			}
		} catch ($InterruptedException& e) {
			break;
		} catch ($Exception& e) {
			$throwNew($Error, static_cast<$Throwable*>(e));
		}
	}
}

CloseRace$OpenLoop::CloseRace$OpenLoop() {
}

$Class* CloseRace$OpenLoop::load$($String* name, bool initialize) {
	$loadClass(CloseRace$OpenLoop, name, initialize, &_CloseRace$OpenLoop_ClassInfo_, allocate$CloseRace$OpenLoop);
	return class$;
}

$Class* CloseRace$OpenLoop::class$ = nullptr;