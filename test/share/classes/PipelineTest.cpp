#include <PipelineTest.h>

#include <PipelineTest$Fun.h>
#include <java/io/File.h>
#include <java/io/FileReader.h>
#include <java/io/FileWriter.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/Reader.h>
#include <java/io/Serializable.h>
#include <java/io/Writer.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/Iterable.h>
#include <java/lang/Process.h>
#include <java/lang/ProcessBuilder.h>
#include <java/lang/ProcessHandle$Info.h>
#include <java/lang/ProcessHandle.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Arrays.h>
#include <java/util/List.h>
#include <java/util/Optional.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Stream.h>
#include <jcpp.h>

#undef THROWS

using $PipelineTest$Fun = ::PipelineTest$Fun;
using $PipelineTest$FunArray = $Array<PipelineTest$Fun>;
using $ProcessBuilderArray = $Array<::java::lang::ProcessBuilder>;
using $File = ::java::io::File;
using $FileReader = ::java::io::FileReader;
using $FileWriter = ::java::io::FileWriter;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $Reader = ::java::io::Reader;
using $Serializable = ::java::io::Serializable;
using $Writer = ::java::io::Writer;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InterruptedException = ::java::lang::InterruptedException;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Process = ::java::lang::Process;
using $ProcessBuilder = ::java::lang::ProcessBuilder;
using $ProcessHandle = ::java::lang::ProcessHandle;
using $ProcessHandle$Info = ::java::lang::ProcessHandle$Info;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Arrays = ::java::util::Arrays;
using $List = ::java::util::List;
using $Optional = ::java::util::Optional;
using $Consumer = ::java::util::function::Consumer;
using $Predicate = ::java::util::function::Predicate;
using $Stream = ::java::util::stream::Stream;

class PipelineTest$$Lambda$lambda$t4_failStartPipeline$0 : public $PipelineTest$Fun {
	$class(PipelineTest$$Lambda$lambda$t4_failStartPipeline$0, $NO_CLASS_INIT, $PipelineTest$Fun)
public:
	void init$($File* p1err) {
		$set(this, p1err, p1err);
	}
	virtual void f() override {
		PipelineTest::lambda$t4_failStartPipeline$0(p1err);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PipelineTest$$Lambda$lambda$t4_failStartPipeline$0>());
	}
	$File* p1err = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PipelineTest$$Lambda$lambda$t4_failStartPipeline$0::fieldInfos[2] = {
	{"p1err", "Ljava/io/File;", nullptr, $PUBLIC, $field(PipelineTest$$Lambda$lambda$t4_failStartPipeline$0, p1err)},
	{}
};
$MethodInfo PipelineTest$$Lambda$lambda$t4_failStartPipeline$0::methodInfos[3] = {
	{"<init>", "(Ljava/io/File;)V", nullptr, $PUBLIC, $method(PipelineTest$$Lambda$lambda$t4_failStartPipeline$0, init$, void, $File*)},
	{"f", "()V", nullptr, $PUBLIC, $virtualMethod(PipelineTest$$Lambda$lambda$t4_failStartPipeline$0, f, void)},
	{}
};
$ClassInfo PipelineTest$$Lambda$lambda$t4_failStartPipeline$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"PipelineTest$$Lambda$lambda$t4_failStartPipeline$0",
	"java.lang.Object",
	"PipelineTest$Fun",
	fieldInfos,
	methodInfos
};
$Class* PipelineTest$$Lambda$lambda$t4_failStartPipeline$0::load$($String* name, bool initialize) {
	$loadClass(PipelineTest$$Lambda$lambda$t4_failStartPipeline$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PipelineTest$$Lambda$lambda$t4_failStartPipeline$0::class$ = nullptr;

class PipelineTest$$Lambda$lambda$t4_failStartPipeline$1$1 : public $PipelineTest$Fun {
	$class(PipelineTest$$Lambda$lambda$t4_failStartPipeline$1$1, $NO_CLASS_INIT, $PipelineTest$Fun)
public:
	void init$($File* p2out) {
		$set(this, p2out, p2out);
	}
	virtual void f() override {
		PipelineTest::lambda$t4_failStartPipeline$1(p2out);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PipelineTest$$Lambda$lambda$t4_failStartPipeline$1$1>());
	}
	$File* p2out = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PipelineTest$$Lambda$lambda$t4_failStartPipeline$1$1::fieldInfos[2] = {
	{"p2out", "Ljava/io/File;", nullptr, $PUBLIC, $field(PipelineTest$$Lambda$lambda$t4_failStartPipeline$1$1, p2out)},
	{}
};
$MethodInfo PipelineTest$$Lambda$lambda$t4_failStartPipeline$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/io/File;)V", nullptr, $PUBLIC, $method(PipelineTest$$Lambda$lambda$t4_failStartPipeline$1$1, init$, void, $File*)},
	{"f", "()V", nullptr, $PUBLIC, $virtualMethod(PipelineTest$$Lambda$lambda$t4_failStartPipeline$1$1, f, void)},
	{}
};
$ClassInfo PipelineTest$$Lambda$lambda$t4_failStartPipeline$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"PipelineTest$$Lambda$lambda$t4_failStartPipeline$1$1",
	"java.lang.Object",
	"PipelineTest$Fun",
	fieldInfos,
	methodInfos
};
$Class* PipelineTest$$Lambda$lambda$t4_failStartPipeline$1$1::load$($String* name, bool initialize) {
	$loadClass(PipelineTest$$Lambda$lambda$t4_failStartPipeline$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PipelineTest$$Lambda$lambda$t4_failStartPipeline$1$1::class$ = nullptr;

class PipelineTest$$Lambda$lambda$t4_failStartPipeline$2$2 : public $PipelineTest$Fun {
	$class(PipelineTest$$Lambda$lambda$t4_failStartPipeline$2$2, $NO_CLASS_INIT, $PipelineTest$Fun)
public:
	void init$() {
	}
	virtual void f() override {
		PipelineTest::lambda$t4_failStartPipeline$2();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PipelineTest$$Lambda$lambda$t4_failStartPipeline$2$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo PipelineTest$$Lambda$lambda$t4_failStartPipeline$2$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PipelineTest$$Lambda$lambda$t4_failStartPipeline$2$2, init$, void)},
	{"f", "()V", nullptr, $PUBLIC, $virtualMethod(PipelineTest$$Lambda$lambda$t4_failStartPipeline$2$2, f, void)},
	{}
};
$ClassInfo PipelineTest$$Lambda$lambda$t4_failStartPipeline$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"PipelineTest$$Lambda$lambda$t4_failStartPipeline$2$2",
	"java.lang.Object",
	"PipelineTest$Fun",
	nullptr,
	methodInfos
};
$Class* PipelineTest$$Lambda$lambda$t4_failStartPipeline$2$2::load$($String* name, bool initialize) {
	$loadClass(PipelineTest$$Lambda$lambda$t4_failStartPipeline$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PipelineTest$$Lambda$lambda$t4_failStartPipeline$2$2::class$ = nullptr;

class PipelineTest$$Lambda$lambda$t4_failStartPipeline$3$3 : public $PipelineTest$Fun {
	$class(PipelineTest$$Lambda$lambda$t4_failStartPipeline$3$3, $NO_CLASS_INIT, $PipelineTest$Fun)
public:
	void init$() {
	}
	virtual void f() override {
		PipelineTest::lambda$t4_failStartPipeline$3();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PipelineTest$$Lambda$lambda$t4_failStartPipeline$3$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo PipelineTest$$Lambda$lambda$t4_failStartPipeline$3$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PipelineTest$$Lambda$lambda$t4_failStartPipeline$3$3, init$, void)},
	{"f", "()V", nullptr, $PUBLIC, $virtualMethod(PipelineTest$$Lambda$lambda$t4_failStartPipeline$3$3, f, void)},
	{}
};
$ClassInfo PipelineTest$$Lambda$lambda$t4_failStartPipeline$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"PipelineTest$$Lambda$lambda$t4_failStartPipeline$3$3",
	"java.lang.Object",
	"PipelineTest$Fun",
	nullptr,
	methodInfos
};
$Class* PipelineTest$$Lambda$lambda$t4_failStartPipeline$3$3::load$($String* name, bool initialize) {
	$loadClass(PipelineTest$$Lambda$lambda$t4_failStartPipeline$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PipelineTest$$Lambda$lambda$t4_failStartPipeline$3$3::class$ = nullptr;

class PipelineTest$$Lambda$lambda$t4_failStartPipeline$4$4 : public $PipelineTest$Fun {
	$class(PipelineTest$$Lambda$lambda$t4_failStartPipeline$4$4, $NO_CLASS_INIT, $PipelineTest$Fun)
public:
	void init$() {
	}
	virtual void f() override {
		PipelineTest::lambda$t4_failStartPipeline$4();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PipelineTest$$Lambda$lambda$t4_failStartPipeline$4$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo PipelineTest$$Lambda$lambda$t4_failStartPipeline$4$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PipelineTest$$Lambda$lambda$t4_failStartPipeline$4$4, init$, void)},
	{"f", "()V", nullptr, $PUBLIC, $virtualMethod(PipelineTest$$Lambda$lambda$t4_failStartPipeline$4$4, f, void)},
	{}
};
$ClassInfo PipelineTest$$Lambda$lambda$t4_failStartPipeline$4$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"PipelineTest$$Lambda$lambda$t4_failStartPipeline$4$4",
	"java.lang.Object",
	"PipelineTest$Fun",
	nullptr,
	methodInfos
};
$Class* PipelineTest$$Lambda$lambda$t4_failStartPipeline$4$4::load$($String* name, bool initialize) {
	$loadClass(PipelineTest$$Lambda$lambda$t4_failStartPipeline$4$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PipelineTest$$Lambda$lambda$t4_failStartPipeline$4$4::class$ = nullptr;

class PipelineTest$$Lambda$print$5 : public $Consumer {
	$class(PipelineTest$$Lambda$print$5, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* p) override {
		PipelineTest::print($cast($ProcessHandle, p));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PipelineTest$$Lambda$print$5>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo PipelineTest$$Lambda$print$5::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PipelineTest$$Lambda$print$5, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(PipelineTest$$Lambda$print$5, accept, void, Object$*)},
	{}
};
$ClassInfo PipelineTest$$Lambda$print$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"PipelineTest$$Lambda$print$5",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* PipelineTest$$Lambda$print$5::load$($String* name, bool initialize) {
	$loadClass(PipelineTest$$Lambda$print$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PipelineTest$$Lambda$print$5::class$ = nullptr;

class PipelineTest$$Lambda$lambda$t4_failStartPipeline$5$6 : public $Predicate {
	$class(PipelineTest$$Lambda$lambda$t4_failStartPipeline$5$6, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* p) override {
		 return PipelineTest::lambda$t4_failStartPipeline$5($cast($ProcessHandle, p));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PipelineTest$$Lambda$lambda$t4_failStartPipeline$5$6>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo PipelineTest$$Lambda$lambda$t4_failStartPipeline$5$6::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PipelineTest$$Lambda$lambda$t4_failStartPipeline$5$6, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(PipelineTest$$Lambda$lambda$t4_failStartPipeline$5$6, test, bool, Object$*)},
	{}
};
$ClassInfo PipelineTest$$Lambda$lambda$t4_failStartPipeline$5$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"PipelineTest$$Lambda$lambda$t4_failStartPipeline$5$6",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* PipelineTest$$Lambda$lambda$t4_failStartPipeline$5$6::load$($String* name, bool initialize) {
	$loadClass(PipelineTest$$Lambda$lambda$t4_failStartPipeline$5$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PipelineTest$$Lambda$lambda$t4_failStartPipeline$5$6::class$ = nullptr;

class PipelineTest$$Lambda$lambda$t4_failStartPipeline$6$7 : public $Consumer {
	$class(PipelineTest$$Lambda$lambda$t4_failStartPipeline$6$7, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* p) override {
		PipelineTest::lambda$t4_failStartPipeline$6($cast($ProcessHandle, p));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PipelineTest$$Lambda$lambda$t4_failStartPipeline$6$7>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo PipelineTest$$Lambda$lambda$t4_failStartPipeline$6$7::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PipelineTest$$Lambda$lambda$t4_failStartPipeline$6$7, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(PipelineTest$$Lambda$lambda$t4_failStartPipeline$6$7, accept, void, Object$*)},
	{}
};
$ClassInfo PipelineTest$$Lambda$lambda$t4_failStartPipeline$6$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"PipelineTest$$Lambda$lambda$t4_failStartPipeline$6$7",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* PipelineTest$$Lambda$lambda$t4_failStartPipeline$6$7::load$($String* name, bool initialize) {
	$loadClass(PipelineTest$$Lambda$lambda$t4_failStartPipeline$6$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PipelineTest$$Lambda$lambda$t4_failStartPipeline$6$7::class$ = nullptr;

class PipelineTest$$Lambda$lambda$waitForAll$7$8 : public $Consumer {
	$class(PipelineTest$$Lambda$lambda$waitForAll$7$8, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* p) override {
		PipelineTest::lambda$waitForAll$7($cast($Process, p));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PipelineTest$$Lambda$lambda$waitForAll$7$8>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo PipelineTest$$Lambda$lambda$waitForAll$7$8::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PipelineTest$$Lambda$lambda$waitForAll$7$8, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(PipelineTest$$Lambda$lambda$waitForAll$7$8, accept, void, Object$*)},
	{}
};
$ClassInfo PipelineTest$$Lambda$lambda$waitForAll$7$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"PipelineTest$$Lambda$lambda$waitForAll$7$8",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* PipelineTest$$Lambda$lambda$waitForAll$7$8::load$($String* name, bool initialize) {
	$loadClass(PipelineTest$$Lambda$lambda$waitForAll$7$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PipelineTest$$Lambda$lambda$waitForAll$7$8::class$ = nullptr;

$CompoundAttribute _PipelineTest_MethodAnnotations_asList2[] = {
	{"Ljava/lang/SafeVarargs;", nullptr},
	{}
};

$FieldInfo _PipelineTest_FieldInfo_[] = {
	{"passed", "I", nullptr, $STATIC | $VOLATILE, $staticField(PipelineTest, passed)},
	{"failed", "I", nullptr, $STATIC | $VOLATILE, $staticField(PipelineTest, failed)},
	{}
};

$MethodInfo _PipelineTest_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PipelineTest, init$, void)},
	{"THROWS", "(Ljava/lang/Class;[LPipelineTest$Fun;)V", "(Ljava/lang/Class<+Ljava/lang/Throwable;>;[LPipelineTest$Fun;)V", $STATIC | $TRANSIENT, $staticMethod(PipelineTest, THROWS, void, $Class*, $PipelineTest$FunArray*)},
	{"asList", "([Ljava/lang/Object;)Ljava/util/List;", "<T:Ljava/lang/Object;>([TT;)Ljava/util/List<TT;>;", $STATIC | $TRANSIENT, $staticMethod(PipelineTest, asList, $List*, $ObjectArray*), nullptr, nullptr, _PipelineTest_MethodAnnotations_asList2},
	{"check", "(Z)V", nullptr, $STATIC, $staticMethod(PipelineTest, check, void, bool)},
	{"check", "(ZLjava/lang/String;)V", nullptr, $STATIC, $staticMethod(PipelineTest, check, void, bool, $String*)},
	{"equal", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $STATIC, $staticMethod(PipelineTest, equal, void, Object$*, Object$*)},
	{"fail", "()V", nullptr, $STATIC, $staticMethod(PipelineTest, fail, void)},
	{"fail", "(Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(PipelineTest, fail, void, $String*)},
	{"fileContents", "(Ljava/io/File;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(PipelineTest, fileContents, $String*, $File*)},
	{"lambda$t4_failStartPipeline$0", "(Ljava/io/File;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(PipelineTest, lambda$t4_failStartPipeline$0, void, $File*), "java.lang.Throwable"},
	{"lambda$t4_failStartPipeline$1", "(Ljava/io/File;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(PipelineTest, lambda$t4_failStartPipeline$1, void, $File*), "java.lang.Throwable"},
	{"lambda$t4_failStartPipeline$2", "()V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(PipelineTest, lambda$t4_failStartPipeline$2, void), "java.lang.Throwable"},
	{"lambda$t4_failStartPipeline$3", "()V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(PipelineTest, lambda$t4_failStartPipeline$3, void), "java.lang.Throwable"},
	{"lambda$t4_failStartPipeline$4", "()V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(PipelineTest, lambda$t4_failStartPipeline$4, void), "java.lang.Throwable"},
	{"lambda$t4_failStartPipeline$5", "(Ljava/lang/ProcessHandle;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(PipelineTest, lambda$t4_failStartPipeline$5, bool, $ProcessHandle*)},
	{"lambda$t4_failStartPipeline$6", "(Ljava/lang/ProcessHandle;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(PipelineTest, lambda$t4_failStartPipeline$6, void, $ProcessHandle*)},
	{"lambda$waitForAll$7", "(Ljava/lang/Process;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(PipelineTest, lambda$waitForAll$7, void, $Process*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(PipelineTest, main, void, $StringArray*), "java.lang.Throwable"},
	{"pass", "()V", nullptr, $STATIC, $staticMethod(PipelineTest, pass, void)},
	{"print", "(Ljava/lang/ProcessBuilder;)V", nullptr, $STATIC, $staticMethod(PipelineTest, print, void, $ProcessBuilder*)},
	{"print", "(Ljava/lang/ProcessHandle;)V", nullptr, $STATIC, $staticMethod(PipelineTest, print, void, $ProcessHandle*)},
	{"realMain", "([Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(PipelineTest, realMain, void, $StringArray*), "java.lang.Throwable"},
	{"setFileContents", "(Ljava/io/File;Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(PipelineTest, setFileContents, void, $File*, $String*)},
	{"t1_simplePipeline", "()V", nullptr, $STATIC, $staticMethod(PipelineTest, t1_simplePipeline, void)},
	{"t2_translatePipeline", "()V", nullptr, $STATIC, $staticMethod(PipelineTest, t2_translatePipeline, void)},
	{"t3_redirectErrorStream", "()V", nullptr, $STATIC, $staticMethod(PipelineTest, t3_redirectErrorStream, void)},
	{"t4_failStartPipeline", "()V", nullptr, $STATIC, $staticMethod(PipelineTest, t4_failStartPipeline, void)},
	{"unexpected", "(Ljava/lang/Throwable;)V", nullptr, $STATIC, $staticMethod(PipelineTest, unexpected, void, $Throwable*)},
	{"verify", "(Ljava/lang/String;Ljava/lang/String;Ljava/util/List;)V", "(Ljava/lang/String;Ljava/lang/String;Ljava/util/List<Ljava/lang/ProcessBuilder;>;)V", $STATIC, $staticMethod(PipelineTest, verify, void, $String*, $String*, $List*), "java.io.IOException"},
	{"verifyNullStream", "(Ljava/io/OutputStream;Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(PipelineTest, verifyNullStream, void, $OutputStream*, $String*)},
	{"verifyNullStream", "(Ljava/io/InputStream;Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(PipelineTest, verifyNullStream, void, $InputStream*, $String*)},
	{"verifyProcesses", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/lang/Process;>;)V", $STATIC, $staticMethod(PipelineTest, verifyProcesses, void, $List*)},
	{"waitForAll", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/lang/Process;>;)V", $STATIC, $staticMethod(PipelineTest, waitForAll, void, $List*)},
	{}
};

$InnerClassInfo _PipelineTest_InnerClassesInfo_[] = {
	{"PipelineTest$Fun", "PipelineTest", "Fun", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _PipelineTest_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"PipelineTest",
	"java.lang.Object",
	nullptr,
	_PipelineTest_FieldInfo_,
	_PipelineTest_MethodInfo_,
	nullptr,
	nullptr,
	_PipelineTest_InnerClassesInfo_,
	nullptr,
	nullptr,
	"PipelineTest$Fun"
};

$Object* allocate$PipelineTest($Class* clazz) {
	return $of($alloc(PipelineTest));
}

$volatile(int32_t) PipelineTest::passed = 0;
$volatile(int32_t) PipelineTest::failed = 0;

void PipelineTest::init$() {
}

void PipelineTest::realMain($StringArray* args) {
	$init(PipelineTest);
	t1_simplePipeline();
	t2_translatePipeline();
	t3_redirectErrorStream();
	t4_failStartPipeline();
}

$List* PipelineTest::asList($ObjectArray* args) {
	$init(PipelineTest);
	return $Arrays::asList(args);
}

void PipelineTest::t1_simplePipeline() {
	$init(PipelineTest);
	$useLocalCurrentObjectStackCache();
	try {
		$var($String, s1, "Now is the time to check!"_s);
		verify(s1, s1, $(asList($$new($ProcessBuilderArray, {$$new($ProcessBuilder, $$new($StringArray, {"cat"_s}))}))));
		verify(s1, s1, $(asList($$new($ProcessBuilderArray, {
			$$new($ProcessBuilder, $$new($StringArray, {"cat"_s})),
			$$new($ProcessBuilder, $$new($StringArray, {"cat"_s}))
		}))));
		verify(s1, s1, $(asList($$new($ProcessBuilderArray, {
			$$new($ProcessBuilder, $$new($StringArray, {"cat"_s})),
			$$new($ProcessBuilder, $$new($StringArray, {"cat"_s})),
			$$new($ProcessBuilder, $$new($StringArray, {"cat"_s}))
		}))));
	} catch ($Throwable& t) {
		unexpected(t);
	}
}

void PipelineTest::t2_translatePipeline() {
	$init(PipelineTest);
	$useLocalCurrentObjectStackCache();
	try {
		$var($String, s2, "Now is the time to check!"_s);
		$var($String, r2, $(s2->replace(u'e', u'E'))->replace(u'o', u'O'));
		verify(s2, r2, $(asList($$new($ProcessBuilderArray, {
			$$new($ProcessBuilder, $$new($StringArray, {
				"tr"_s,
				"e"_s,
				"E"_s
			})),
			$$new($ProcessBuilder, $$new($StringArray, {
				"tr"_s,
				"o"_s,
				"O"_s
			}))
		}))));
	} catch ($Throwable& t) {
		unexpected(t);
	}
}

void PipelineTest::t3_redirectErrorStream() {
	$init(PipelineTest);
	$useLocalCurrentObjectStackCache();
	try {
		$var($File, p1err, $new($File, "p1-test.err"_s));
		$var($File, p2out, $new($File, "p2-test.out"_s));
		$var($List, processes, $ProcessBuilder::startPipeline($(asList($$new($ProcessBuilderArray, {
			$($nc($($$new($ProcessBuilder, $$new($StringArray, {
				"cat"_s,
				"NON-EXISTENT-FILE"_s
			}))->redirectErrorStream(true)))->redirectError(p1err)),
			$($$new($ProcessBuilder, $$new($StringArray, {"cat"_s}))->redirectOutput(p2out))
		})))));
		waitForAll(processes);
		check(""_s->equals($(fileContents(p1err))), "The first process standard error should be empty"_s);
		$var($String, p2contents, fileContents(p2out));
		check($nc(p2contents)->contains("NON-EXISTENT-FILE"_s), $$str({"The error from the first process should be in the output of the second: "_s, p2contents}));
	} catch ($Throwable& t) {
		unexpected(t);
	}
}

void PipelineTest::t4_failStartPipeline() {
	$init(PipelineTest);
	$useLocalCurrentObjectStackCache();
	$var($File, p1err, $new($File, "p1-test.err"_s));
	$var($File, p2out, $new($File, "p2-test.out"_s));
	$load($IllegalArgumentException);
	THROWS($IllegalArgumentException::class$, $$new($PipelineTest$FunArray, {
		static_cast<$PipelineTest$Fun*>($$new(PipelineTest$$Lambda$lambda$t4_failStartPipeline$0, p1err)),
		static_cast<$PipelineTest$Fun*>($$new(PipelineTest$$Lambda$lambda$t4_failStartPipeline$1$1, p2out))
	}));
	$load($NullPointerException);
	THROWS($NullPointerException::class$, $$new($PipelineTest$FunArray, {
		static_cast<$PipelineTest$Fun*>($$new(PipelineTest$$Lambda$lambda$t4_failStartPipeline$2$2)),
		static_cast<$PipelineTest$Fun*>($$new(PipelineTest$$Lambda$lambda$t4_failStartPipeline$3$3))
	}));
	$load($IOException);
	THROWS($IOException::class$, $$new($PipelineTest$FunArray, {static_cast<$PipelineTest$Fun*>($$new(PipelineTest$$Lambda$lambda$t4_failStartPipeline$4$4))}));
	$nc($($nc($($ProcessHandle::current()))->children()))->forEach(static_cast<$Consumer*>($$new(PipelineTest$$Lambda$print$5)));
	$nc($($nc($($nc($($ProcessHandle::current()))->children()))->filter(static_cast<$Predicate*>($$new(PipelineTest$$Lambda$lambda$t4_failStartPipeline$5$6)))))->forEach(static_cast<$Consumer*>($$new(PipelineTest$$Lambda$lambda$t4_failStartPipeline$6$7)));
}

void PipelineTest::verify($String* input, $String* expected, $List* builders) {
	$init(PipelineTest);
	$useLocalCurrentObjectStackCache();
	$var($File, infile, $new($File, "test.in"_s));
	$var($File, outfile, $new($File, "test.out"_s));
	setFileContents(infile, input);
	for (int32_t i = 0; i < $nc(builders)->size(); ++i) {
		$var($ProcessBuilder, b, $cast($ProcessBuilder, builders->get(i)));
		if (i == 0) {
			$nc(b)->redirectInput(infile);
		}
		if (i == builders->size() - 1) {
			$nc(b)->redirectOutput(outfile);
		}
	}
	$var($List, processes, $ProcessBuilder::startPipeline(builders));
	verifyProcesses(processes);
	waitForAll(processes);
	$var($String, result, fileContents(outfile));
	check($nc(result)->equals(expected), $$str({"result not as expected: "_s, result, ", expected: "_s, expected}));
}

void PipelineTest::waitForAll($List* processes) {
	$init(PipelineTest);
	$nc(processes)->forEach(static_cast<$Consumer*>($$new(PipelineTest$$Lambda$lambda$waitForAll$7$8)));
}

void PipelineTest::print($ProcessBuilder* pb) {
	$init(PipelineTest);
	$useLocalCurrentObjectStackCache();
	if (pb != nullptr) {
		$nc($System::out)->printf(" pb: %s%n"_s, $$new($ObjectArray, {$of(pb)}));
		$nc($System::out)->printf("    cmd: %s%n"_s, $$new($ObjectArray, {$($of(pb->command()))}));
	}
}

void PipelineTest::print($ProcessHandle* p) {
	$init(PipelineTest);
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->printf("process: pid: %d, info: %s%n"_s, $$new($ObjectArray, {
		$($of($Long::valueOf($nc(p)->pid()))),
		$($of($nc(p)->info()))
	}));
}

void PipelineTest::verifyProcesses($List* processes) {
	$init(PipelineTest);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < $nc(processes)->size(); ++i) {
		$var($Process, p, $cast($Process, processes->get(i)));
		if (i != 0) {
			verifyNullStream($($nc(p)->getOutputStream()), "getOutputStream"_s);
		}
		if (i <= processes->size() - 1) {
			verifyNullStream($($nc(p)->getInputStream()), "getInputStream"_s);
		}
		if (i == processes->size() - 1) {
			verifyNullStream($($nc(p)->getErrorStream()), "getErrorStream"_s);
		}
	}
}

void PipelineTest::verifyNullStream($OutputStream* s, $String* msg) {
	$init(PipelineTest);
	try {
		$nc(s)->write(255);
		fail($$str({"Stream should have been a NullStream: "_s, msg}));
	} catch ($IOException& ie) {
	}
}

void PipelineTest::verifyNullStream($InputStream* s, $String* msg) {
	$init(PipelineTest);
	try {
		int32_t len = $nc(s)->read();
		check(len == -1, $$str({"Stream should have been a NullStream: "_s, msg}));
	} catch ($IOException& ie) {
	}
}

void PipelineTest::setFileContents($File* file, $String* contents) {
	$init(PipelineTest);
	try {
		$var($Writer, w, $new($FileWriter, file));
		w->write(contents);
		w->close();
	} catch ($Throwable& t) {
		unexpected(t);
	}
}

$String* PipelineTest::fileContents($File* file) {
	$init(PipelineTest);
	$useLocalCurrentObjectStackCache();
	try {
		$var($Reader, r, $new($FileReader, file));
		$var($StringBuilder, sb, $new($StringBuilder));
		$var($chars, buffer, $new($chars, 1024));
		int32_t n = 0;
		while ((n = r->read(buffer)) != -1) {
			sb->append(buffer, 0, n);
		}
		r->close();
		return $new($String, sb);
	} catch ($Throwable& t) {
		unexpected(t);
		return ""_s;
	}
	$shouldNotReachHere();
}

void PipelineTest::pass() {
	$init(PipelineTest);
	++PipelineTest::passed;
}

void PipelineTest::fail() {
	$init(PipelineTest);
	++PipelineTest::failed;
	$$new($Exception, "Stack trace"_s)->printStackTrace($System::out);
}

void PipelineTest::fail($String* msg) {
	$init(PipelineTest);
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println(msg);
	++PipelineTest::failed;
	$$new($Exception, $$str({"Stack trace: "_s, msg}))->printStackTrace($System::out);
}

void PipelineTest::unexpected($Throwable* t) {
	$init(PipelineTest);
	++PipelineTest::failed;
	$nc(t)->printStackTrace($System::out);
}

void PipelineTest::check(bool cond) {
	$init(PipelineTest);
	if (cond) {
		pass();
	} else {
		fail();
	}
}

void PipelineTest::check(bool cond, $String* m) {
	$init(PipelineTest);
	if (cond) {
		pass();
	} else {
		fail(m);
	}
}

void PipelineTest::equal(Object$* x, Object$* y) {
	$init(PipelineTest);
	if (x == nullptr ? y == nullptr : $nc($of(x))->equals(y)) {
		pass();
	} else {
		fail($$str({">\'"_s, x, "\'< not equal to \'"_s, y, "\'"_s}));
	}
}

void PipelineTest::main($StringArray* args) {
	$init(PipelineTest);
	$useLocalCurrentObjectStackCache();
	try {
		realMain(args);
	} catch ($Throwable& t) {
		unexpected(t);
	}
	$nc($System::out)->printf("%nPassed = %d, failed = %d%n%n"_s, $$new($ObjectArray, {
		$($of($Integer::valueOf(PipelineTest::passed))),
		$($of($Integer::valueOf(PipelineTest::failed)))
	}));
	if (PipelineTest::failed > 0) {
		$throwNew($AssertionError, $of("Some tests failed"_s));
	}
}

void PipelineTest::THROWS($Class* k, $PipelineTest$FunArray* fs) {
	$init(PipelineTest);
	$useLocalCurrentObjectStackCache();
	{
		$var($PipelineTest$FunArray, arr$, fs);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($PipelineTest$Fun, f, arr$->get(i$));
			try {
				$nc(f)->f();
				fail($$str({"Expected "_s, $($nc(k)->getName()), " not thrown"_s}));
			} catch ($Throwable& t) {
				if ($nc(k)->isAssignableFrom($of(t)->getClass())) {
					pass();
				} else {
					unexpected(t);
				}
			}
		}
	}
}

void PipelineTest::lambda$waitForAll$7($Process* p) {
	$init(PipelineTest);
	try {
		int32_t status = $nc(p)->waitFor();
	} catch ($InterruptedException& ie) {
		unexpected(ie);
	}
}

void PipelineTest::lambda$t4_failStartPipeline$6($ProcessHandle* p) {
	$init(PipelineTest);
	fail($$str({"process should have been destroyed: "_s, p}));
}

bool PipelineTest::lambda$t4_failStartPipeline$5($ProcessHandle* p) {
	$init(PipelineTest);
	$useLocalCurrentObjectStackCache();
	return $nc(($cast($String, $($nc($($nc($($nc(p)->info()))->command()))->orElse(""_s)))))->contains("cat"_s);
}

void PipelineTest::lambda$t4_failStartPipeline$4() {
	$init(PipelineTest);
	$useLocalCurrentObjectStackCache();
	$var($List, processes, $ProcessBuilder::startPipeline($(asList($$new($ProcessBuilderArray, {
		$$new($ProcessBuilder, $$new($StringArray, {
			"cat"_s,
			"c"_s
		})),
		$$new($ProcessBuilder, $$new($StringArray, {"NON-EXISTENT-COMMAND"_s}))
	})))));
}

void PipelineTest::lambda$t4_failStartPipeline$3() {
	$init(PipelineTest);
	$useLocalCurrentObjectStackCache();
	$var($List, processes, $ProcessBuilder::startPipeline($(asList($$new($ProcessBuilderArray, {
		($ProcessBuilder*)nullptr,
		$$new($ProcessBuilder, $$new($StringArray, {
			"cat"_s,
			"b"_s
		}))
	})))));
}

void PipelineTest::lambda$t4_failStartPipeline$2() {
	$init(PipelineTest);
	$useLocalCurrentObjectStackCache();
	$var($List, processes, $ProcessBuilder::startPipeline($(asList($$new($ProcessBuilderArray, {
		$$new($ProcessBuilder, $$new($StringArray, {
			"cat"_s,
			"a"_s
		})),
		($ProcessBuilder*)nullptr
	})))));
}

void PipelineTest::lambda$t4_failStartPipeline$1($File* p2out) {
	$init(PipelineTest);
	$useLocalCurrentObjectStackCache();
	$var($List, processes, $ProcessBuilder::startPipeline($(asList($$new($ProcessBuilderArray, {
		$$new($ProcessBuilder, $$new($StringArray, {
			"cat"_s,
			"NON-EXISTENT-FILE2"_s
		})),
		$($$new($ProcessBuilder, $$new($StringArray, {"cat"_s}))->redirectInput(p2out))
	})))));
}

void PipelineTest::lambda$t4_failStartPipeline$0($File* p1err) {
	$init(PipelineTest);
	$useLocalCurrentObjectStackCache();
	$var($List, processes, $ProcessBuilder::startPipeline($(asList($$new($ProcessBuilderArray, {
		$($$new($ProcessBuilder, $$new($StringArray, {
			"cat"_s,
			"NON-EXISTENT-FILE1"_s
		}))->redirectOutput(p1err)),
		$$new($ProcessBuilder, $$new($StringArray, {"cat"_s}))
	})))));
}

void clinit$PipelineTest($Class* class$) {
	PipelineTest::passed = 0;
	PipelineTest::failed = 0;
}

PipelineTest::PipelineTest() {
}

$Class* PipelineTest::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(PipelineTest$$Lambda$lambda$t4_failStartPipeline$0::classInfo$.name)) {
			return PipelineTest$$Lambda$lambda$t4_failStartPipeline$0::load$(name, initialize);
		}
		if (name->equals(PipelineTest$$Lambda$lambda$t4_failStartPipeline$1$1::classInfo$.name)) {
			return PipelineTest$$Lambda$lambda$t4_failStartPipeline$1$1::load$(name, initialize);
		}
		if (name->equals(PipelineTest$$Lambda$lambda$t4_failStartPipeline$2$2::classInfo$.name)) {
			return PipelineTest$$Lambda$lambda$t4_failStartPipeline$2$2::load$(name, initialize);
		}
		if (name->equals(PipelineTest$$Lambda$lambda$t4_failStartPipeline$3$3::classInfo$.name)) {
			return PipelineTest$$Lambda$lambda$t4_failStartPipeline$3$3::load$(name, initialize);
		}
		if (name->equals(PipelineTest$$Lambda$lambda$t4_failStartPipeline$4$4::classInfo$.name)) {
			return PipelineTest$$Lambda$lambda$t4_failStartPipeline$4$4::load$(name, initialize);
		}
		if (name->equals(PipelineTest$$Lambda$print$5::classInfo$.name)) {
			return PipelineTest$$Lambda$print$5::load$(name, initialize);
		}
		if (name->equals(PipelineTest$$Lambda$lambda$t4_failStartPipeline$5$6::classInfo$.name)) {
			return PipelineTest$$Lambda$lambda$t4_failStartPipeline$5$6::load$(name, initialize);
		}
		if (name->equals(PipelineTest$$Lambda$lambda$t4_failStartPipeline$6$7::classInfo$.name)) {
			return PipelineTest$$Lambda$lambda$t4_failStartPipeline$6$7::load$(name, initialize);
		}
		if (name->equals(PipelineTest$$Lambda$lambda$waitForAll$7$8::classInfo$.name)) {
			return PipelineTest$$Lambda$lambda$waitForAll$7$8::load$(name, initialize);
		}
	}
	$loadClass(PipelineTest, name, initialize, &_PipelineTest_ClassInfo_, clinit$PipelineTest, allocate$PipelineTest);
	return class$;
}

$Class* PipelineTest::class$ = nullptr;