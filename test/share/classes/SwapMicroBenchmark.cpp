#include <SwapMicroBenchmark.h>

#include <SwapMicroBenchmark$1.h>
#include <SwapMicroBenchmark$2.h>
#include <SwapMicroBenchmark$3.h>
#include <SwapMicroBenchmark$4.h>
#include <SwapMicroBenchmark$5.h>
#include <SwapMicroBenchmark$6.h>
#include <SwapMicroBenchmark$7.h>
#include <SwapMicroBenchmark$8.h>
#include <SwapMicroBenchmark$9.h>
#include <SwapMicroBenchmark$Job.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Error.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/Math.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/Random.h>
#include <java/util/concurrent/CountDownLatch.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern.h>
#include <jcpp.h>

using $SwapMicroBenchmark$1 = ::SwapMicroBenchmark$1;
using $SwapMicroBenchmark$2 = ::SwapMicroBenchmark$2;
using $SwapMicroBenchmark$3 = ::SwapMicroBenchmark$3;
using $SwapMicroBenchmark$4 = ::SwapMicroBenchmark$4;
using $SwapMicroBenchmark$5 = ::SwapMicroBenchmark$5;
using $SwapMicroBenchmark$6 = ::SwapMicroBenchmark$6;
using $SwapMicroBenchmark$7 = ::SwapMicroBenchmark$7;
using $SwapMicroBenchmark$8 = ::SwapMicroBenchmark$8;
using $SwapMicroBenchmark$9 = ::SwapMicroBenchmark$9;
using $SwapMicroBenchmark$Job = ::SwapMicroBenchmark$Job;
using $SwapMicroBenchmark$JobArray = $Array<SwapMicroBenchmark$Job>;
using $PrintStream = ::java::io::PrintStream;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $Error = ::java::lang::Error;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InterruptedException = ::java::lang::InterruptedException;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Random = ::java::util::Random;
using $CountDownLatch = ::java::util::concurrent::CountDownLatch;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern = ::java::util::regex::Pattern;

$MethodInfo _SwapMicroBenchmark_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SwapMicroBenchmark, init$, void)},
	{"collectAllGarbage", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(SwapMicroBenchmark, collectAllGarbage, void)},
	{"deoptimize", "(I)V", nullptr, $PRIVATE | $STATIC, $staticMethod(SwapMicroBenchmark, deoptimize, void, int32_t)},
	{"filter", "(Ljava/util/regex/Pattern;[LSwapMicroBenchmark$Job;)[LSwapMicroBenchmark$Job;", nullptr, $PRIVATE | $STATIC, $staticMethod(SwapMicroBenchmark, filter, $SwapMicroBenchmark$JobArray*, $Pattern*, $SwapMicroBenchmark$JobArray*)},
	{"intArg", "([Ljava/lang/String;Ljava/lang/String;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(SwapMicroBenchmark, intArg, int32_t, $StringArray*, $String*, int32_t)},
	{"keywordValue", "([Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(SwapMicroBenchmark, keywordValue, $String*, $StringArray*, $String*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(SwapMicroBenchmark, main, void, $StringArray*), "java.lang.Throwable"},
	{"patternArg", "([Ljava/lang/String;Ljava/lang/String;)Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC, $staticMethod(SwapMicroBenchmark, patternArg, $Pattern*, $StringArray*, $String*)},
	{"time", "([LSwapMicroBenchmark$Job;)V", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(SwapMicroBenchmark, time, void, $SwapMicroBenchmark$JobArray*), "java.lang.Throwable"},
	{"time0", "([LSwapMicroBenchmark$Job;)[J", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(SwapMicroBenchmark, time0, $longs*, $SwapMicroBenchmark$JobArray*), "java.lang.Throwable"},
	{}
};

$InnerClassInfo _SwapMicroBenchmark_InnerClassesInfo_[] = {
	{"SwapMicroBenchmark$Job", "SwapMicroBenchmark", "Job", $STATIC | $ABSTRACT},
	{"SwapMicroBenchmark$9", nullptr, nullptr, 0},
	{"SwapMicroBenchmark$8", nullptr, nullptr, 0},
	{"SwapMicroBenchmark$7", nullptr, nullptr, 0},
	{"SwapMicroBenchmark$6", nullptr, nullptr, 0},
	{"SwapMicroBenchmark$5", nullptr, nullptr, 0},
	{"SwapMicroBenchmark$4", nullptr, nullptr, 0},
	{"SwapMicroBenchmark$3", nullptr, nullptr, 0},
	{"SwapMicroBenchmark$2", nullptr, nullptr, 0},
	{"SwapMicroBenchmark$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SwapMicroBenchmark_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"SwapMicroBenchmark",
	"java.lang.Object",
	nullptr,
	nullptr,
	_SwapMicroBenchmark_MethodInfo_,
	nullptr,
	nullptr,
	_SwapMicroBenchmark_InnerClassesInfo_,
	nullptr,
	nullptr,
	"SwapMicroBenchmark$Job,SwapMicroBenchmark$9,SwapMicroBenchmark$8,SwapMicroBenchmark$7,SwapMicroBenchmark$6,SwapMicroBenchmark$5,SwapMicroBenchmark$4,SwapMicroBenchmark$3,SwapMicroBenchmark$2,SwapMicroBenchmark$1"
};

$Object* allocate$SwapMicroBenchmark($Class* clazz) {
	return $of($alloc(SwapMicroBenchmark));
}

void SwapMicroBenchmark::init$() {
}

void SwapMicroBenchmark::collectAllGarbage() {
	$var($CountDownLatch, drained, $new($CountDownLatch, 1));
	try {
		$System::gc();
		$new($SwapMicroBenchmark$1, drained);
		$System::gc();
		drained->await();
		$System::gc();
	} catch ($InterruptedException& e) {
		$throwNew($Error, static_cast<$Throwable*>(e));
	}
}

$longs* SwapMicroBenchmark::time0($SwapMicroBenchmark$JobArray* jobs) {
	int64_t warmupNanos = (int64_t)100 * (int64_t)1000 * (int64_t)1000;
	$var($longs, nanoss, $new($longs, $nc(jobs)->length));
	for (int32_t i = 0; i < jobs->length; ++i) {
		collectAllGarbage();
		int64_t t0 = $System::nanoTime();
		int64_t t = 0;
		int32_t j = 0;
		do {
			$nc(jobs->get(i))->work();
			++j;
		} while ((t = $System::nanoTime() - t0) < warmupNanos);
		nanoss->set(i, $div(t, j));
	}
	return nanoss;
}

void SwapMicroBenchmark::time($SwapMicroBenchmark$JobArray* jobs) {
	$useLocalCurrentObjectStackCache();
	$var($longs, warmup, time0(jobs));
	$var($longs, nanoss, time0(jobs));
	$var($longs, milliss, $new($longs, $nc(jobs)->length));
	$var($doubles, ratios, $new($doubles, jobs->length));
	$var($String, nameHeader, "Method"_s);
	$var($String, millisHeader, "Millis"_s);
	$var($String, ratioHeader, "Ratio"_s);
	int32_t nameWidth = nameHeader->length();
	int32_t millisWidth = millisHeader->length();
	int32_t ratioWidth = ratioHeader->length();
	for (int32_t i = 0; i < jobs->length; ++i) {
		nameWidth = $Math::max(nameWidth, $nc($($nc(jobs->get(i))->name()))->length());
		milliss->set(i, $div($nc(nanoss)->get(i), ((int64_t)1000 * (int64_t)1000)));
		millisWidth = $Math::max(millisWidth, $nc($($String::format("%d"_s, $$new($ObjectArray, {$($of($Long::valueOf(milliss->get(i))))}))))->length());
		ratios->set(i, (double)nanoss->get(i) / (double)nanoss->get(0));
		ratioWidth = $Math::max(ratioWidth, $nc($($String::format("%.3f"_s, $$new($ObjectArray, {$($of($Double::valueOf(ratios->get(i))))}))))->length());
	}
	$var($String, format, $String::format("%%-%ds %%%dd %%%d.3f%%n"_s, $$new($ObjectArray, {
		$($of($Integer::valueOf(nameWidth))),
		$($of($Integer::valueOf(millisWidth))),
		$($of($Integer::valueOf(ratioWidth)))
	})));
	$var($String, headerFormat, $String::format("%%-%ds %%%ds %%%ds%%n"_s, $$new($ObjectArray, {
		$($of($Integer::valueOf(nameWidth))),
		$($of($Integer::valueOf(millisWidth))),
		$($of($Integer::valueOf(ratioWidth)))
	})));
	$nc($System::out)->printf(headerFormat, $$new($ObjectArray, {
		$of("Method"_s),
		$of("Millis"_s),
		$of("Ratio"_s)
	}));
	for (int32_t i = 0; i < jobs->length; ++i) {
		$nc($System::out)->printf(format, $$new($ObjectArray, {
			$($of($nc(jobs->get(i))->name())),
			$($of($Long::valueOf(milliss->get(i)))),
			$($of($Double::valueOf(ratios->get(i))))
		}));
	}
}

$String* SwapMicroBenchmark::keywordValue($StringArray* args, $String* keyword) {
	$useLocalCurrentObjectStackCache();
	{
		$var($StringArray, arr$, args);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, arg, arr$->get(i$));
			if ($nc(arg)->startsWith(keyword)) {
				return arg->substring($nc(keyword)->length() + 1);
			}
		}
	}
	return nullptr;
}

int32_t SwapMicroBenchmark::intArg($StringArray* args, $String* keyword, int32_t defaultValue) {
	$var($String, val, keywordValue(args, keyword));
	return val == nullptr ? defaultValue : $Integer::parseInt(val);
}

$Pattern* SwapMicroBenchmark::patternArg($StringArray* args, $String* keyword) {
	$var($String, val, keywordValue(args, keyword));
	return val == nullptr ? ($Pattern*)nullptr : $Pattern::compile(val);
}

$SwapMicroBenchmark$JobArray* SwapMicroBenchmark::filter($Pattern* filter, $SwapMicroBenchmark$JobArray* jobs) {
	$useLocalCurrentObjectStackCache();
	if (filter == nullptr) {
		return jobs;
	}
	$var($SwapMicroBenchmark$JobArray, newJobs, $new($SwapMicroBenchmark$JobArray, $nc(jobs)->length));
	int32_t n = 0;
	{
		$var($SwapMicroBenchmark$JobArray, arr$, jobs);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($SwapMicroBenchmark$Job, job, arr$->get(i$));
			if ($nc($($nc(filter)->matcher($($nc(job)->name()))))->find()) {
				newJobs->set(n++, job);
			}
		}
	}
	$var($SwapMicroBenchmark$JobArray, ret, $new($SwapMicroBenchmark$JobArray, n));
	$System::arraycopy(newJobs, 0, ret, 0, n);
	return ret;
}

void SwapMicroBenchmark::deoptimize(int32_t sum) {
	if (sum == 42) {
		$nc($System::out)->println("the answer"_s);
	}
}

void SwapMicroBenchmark::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	int32_t iterations = intArg(args, "iterations"_s, 2);
	int32_t size = intArg(args, "size"_s, 512);
	$var($Pattern, filter, patternArg(args, "filter"_s));
	$var($Random, rnd, $new($Random));
	$var($ByteBuffer, b, $ByteBuffer::allocateDirect(8 * size));
	for (int32_t i = 0; i < $nc(b)->limit(); ++i) {
		b->put(i, (int8_t)rnd->nextInt());
	}
	$var($SwapMicroBenchmark$JobArray, jobs, $new($SwapMicroBenchmark$JobArray, {
		static_cast<$SwapMicroBenchmark$Job*>($$new($SwapMicroBenchmark$2, "swap char BIG_ENDIAN"_s, b, iterations)),
		static_cast<$SwapMicroBenchmark$Job*>($$new($SwapMicroBenchmark$3, "swap char LITTLE_ENDIAN"_s, b, iterations)),
		static_cast<$SwapMicroBenchmark$Job*>($$new($SwapMicroBenchmark$4, "swap short BIG_ENDIAN"_s, b, iterations)),
		static_cast<$SwapMicroBenchmark$Job*>($$new($SwapMicroBenchmark$5, "swap short LITTLE_ENDIAN"_s, b, iterations)),
		static_cast<$SwapMicroBenchmark$Job*>($$new($SwapMicroBenchmark$6, "swap int BIG_ENDIAN"_s, b, iterations)),
		static_cast<$SwapMicroBenchmark$Job*>($$new($SwapMicroBenchmark$7, "swap int LITTLE_ENDIAN"_s, b, iterations)),
		static_cast<$SwapMicroBenchmark$Job*>($$new($SwapMicroBenchmark$8, "swap long BIG_ENDIAN"_s, b, iterations)),
		static_cast<$SwapMicroBenchmark$Job*>($$new($SwapMicroBenchmark$9, "swap long LITTLE_ENDIAN"_s, b, iterations))
	}));
	time($(SwapMicroBenchmark::filter(filter, jobs)));
}

SwapMicroBenchmark::SwapMicroBenchmark() {
}

$Class* SwapMicroBenchmark::load$($String* name, bool initialize) {
	$loadClass(SwapMicroBenchmark, name, initialize, &_SwapMicroBenchmark_ClassInfo_, allocate$SwapMicroBenchmark);
	return class$;
}

$Class* SwapMicroBenchmark::class$ = nullptr;