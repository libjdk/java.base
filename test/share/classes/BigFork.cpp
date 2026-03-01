#include <BigFork.h>

#include <java/io/BufferedReader.h>
#include <java/io/FileInputStream.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/Reader.h>
#include <java/lang/OutOfMemoryError.h>
#include <java/lang/Process.h>
#include <java/lang/ProcessBuilder.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <java/util/Random.h>
#include <jcpp.h>

using $BufferedReader = ::java::io::BufferedReader;
using $FileInputStream = ::java::io::FileInputStream;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $PrintStream = ::java::io::PrintStream;
using $Reader = ::java::io::Reader;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $OutOfMemoryError = ::java::lang::OutOfMemoryError;
using $Process = ::java::lang::Process;
using $ProcessBuilder = ::java::lang::ProcessBuilder;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $Random = ::java::util::Random;

$FieldInfo _BigFork_FieldInfo_[] = {
	{"rnd", "Ljava/util/Random;", nullptr, $STATIC | $FINAL, $staticField(BigFork, rnd)},
	{}
};

$MethodInfo _BigFork_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(BigFork, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(BigFork, main, void, $StringArray*), "java.lang.Throwable"},
	{"showCommittedMemory", "()V", nullptr, $STATIC, $staticMethod(BigFork, showCommittedMemory, void), "java.io.IOException"},
	{"touchPages", "([B)V", nullptr, $STATIC, $staticMethod(BigFork, touchPages, void, $bytes*)},
	{}
};

$ClassInfo _BigFork_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"BigFork",
	"java.lang.Object",
	nullptr,
	_BigFork_FieldInfo_,
	_BigFork_MethodInfo_
};

$Object* allocate$BigFork($Class* clazz) {
	return $of($alloc(BigFork));
}

$Random* BigFork::rnd = nullptr;

void BigFork::init$() {
}

void BigFork::touchPages($bytes* chunk) {
	$init(BigFork);
	int32_t pageSize = 4096;
	for (int32_t i = 0; i < $nc(chunk)->length; i += pageSize) {
		chunk->set(i, (int8_t)$nc(BigFork::rnd)->nextInt());
	}
}

void BigFork::showCommittedMemory() {
	$init(BigFork);
	$useLocalCurrentObjectStackCache();
	$var($BufferedReader, r, $new($BufferedReader, $$new($InputStreamReader, $$new($FileInputStream, "/proc/meminfo"_s))));
	$nc($System::out)->println("-------"_s);
	$var($String, line, nullptr);
	while (($assign(line, r->readLine())) != nullptr) {
		if ($nc(line)->startsWith("Commit"_s)) {
			$nc($System::out)->printf("%s%n"_s, $$new($ObjectArray, {$of(line)}));
		}
	}
	$nc($System::out)->println("-------"_s);
}

void BigFork::main($StringArray* args) {
	$init(BigFork);
	$useLocalCurrentObjectStackCache();
	showCommittedMemory();
	int32_t chunkSize = 1024 * 1024 * 100;
	$var($List, chunks, $new($ArrayList, 100));
	try {
		for (;;) {
			$var($bytes, chunk, $new($bytes, chunkSize));
			touchPages(chunk);
			chunks->add(chunk);
		}
	} catch ($OutOfMemoryError& e) {
		chunks->set(0, nullptr);
		$System::gc();
		int32_t size = chunks->size();
		$nc($System::out)->printf("size=%.2gGB%n"_s, $$new($ObjectArray, {$($of($Double::valueOf((double)size / 10)))}));
		showCommittedMemory();
		$var($Process, p, $$new($ProcessBuilder, $$new($StringArray, {"/bin/true"_s}))->start());
		$nc(p)->waitFor();
	}
}

void clinit$BigFork($Class* class$) {
	$assignStatic(BigFork::rnd, $new($Random));
}

BigFork::BigFork() {
}

$Class* BigFork::load$($String* name, bool initialize) {
	$loadClass(BigFork, name, initialize, &_BigFork_ClassInfo_, clinit$BigFork, allocate$BigFork);
	return class$;
}

$Class* BigFork::class$ = nullptr;