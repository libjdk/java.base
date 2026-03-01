#include <Bug6335238$DateParseThread.h>

#include <Bug6335238.h>
#include <java/text/ParseException.h>
#include <java/text/SimpleDateFormat.h>
#include <java/util/Date.h>
#include <jcpp.h>

using $Bug6335238 = ::Bug6335238;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $ParseException = ::java::text::ParseException;
using $SimpleDateFormat = ::java::text::SimpleDateFormat;
using $Date = ::java::util::Date;

$FieldInfo _Bug6335238$DateParseThread_FieldInfo_[] = {
	{"this$0", "LBug6335238;", nullptr, $FINAL | $SYNTHETIC, $field(Bug6335238$DateParseThread, this$0)},
	{}
};

$MethodInfo _Bug6335238$DateParseThread_MethodInfo_[] = {
	{"<init>", "(LBug6335238;)V", nullptr, 0, $method(Bug6335238$DateParseThread, init$, void, $Bug6335238*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(Bug6335238$DateParseThread, run, void)},
	{}
};

$InnerClassInfo _Bug6335238$DateParseThread_InnerClassesInfo_[] = {
	{"Bug6335238$DateParseThread", "Bug6335238", "DateParseThread", 0},
	{}
};

$ClassInfo _Bug6335238$DateParseThread_ClassInfo_ = {
	$ACC_SUPER,
	"Bug6335238$DateParseThread",
	"java.lang.Thread",
	nullptr,
	_Bug6335238$DateParseThread_FieldInfo_,
	_Bug6335238$DateParseThread_MethodInfo_,
	nullptr,
	nullptr,
	_Bug6335238$DateParseThread_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"Bug6335238"
};

$Object* allocate$Bug6335238$DateParseThread($Class* clazz) {
	return $of($alloc(Bug6335238$DateParseThread));
}

void Bug6335238$DateParseThread::init$($Bug6335238* this$0) {
	$set(this, this$0, this$0);
	$Thread::init$();
}

void Bug6335238$DateParseThread::run() {
	$useLocalCurrentObjectStackCache();
	int32_t i = 0;
	$init($Bug6335238);
	while (!$Bug6335238::stopped) {
		$var($SimpleDateFormat, sdf, nullptr);
		$synchronized($Bug6335238::masterSdf) {
			$assign(sdf, $cast($SimpleDateFormat, $nc($Bug6335238::masterSdf)->clone()));
		}
		++i;
		$var($Date, date, nullptr);
		try {
			$assign(date, $nc(sdf)->parse("2000/11/18 00:01:00"_s));
			int64_t t = $nc(date)->getTime();
			if (t != (int64_t)0x000000E2E6C7C260) {
				$Bug6335238::stopped = true;
				$Bug6335238::err = true;
				$throwNew($RuntimeException, $$str({"Parsing Date Error: counter="_s, $$str(i), " Got:"_s, $$str(t), "<"_s, $(sdf->format(date)), "> != "_s, $$str((int64_t)0x000000E2E6C7C260)}));
			}
		} catch ($ParseException& e) {
			$Bug6335238::stopped = true;
			$Bug6335238::err = true;
			$throwNew($RuntimeException, static_cast<$Throwable*>(e));
		}
	}
}

Bug6335238$DateParseThread::Bug6335238$DateParseThread() {
}

$Class* Bug6335238$DateParseThread::load$($String* name, bool initialize) {
	$loadClass(Bug6335238$DateParseThread, name, initialize, &_Bug6335238$DateParseThread_ClassInfo_, allocate$Bug6335238$DateParseThread);
	return class$;
}

$Class* Bug6335238$DateParseThread::class$ = nullptr;