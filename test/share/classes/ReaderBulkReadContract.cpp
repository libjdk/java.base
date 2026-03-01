#include <ReaderBulkReadContract.h>

#include <java/io/BufferedReader.h>
#include <java/io/ByteArrayInputStream.h>
#include <java/io/CharArrayReader.h>
#include <java/io/File.h>
#include <java/io/FileReader.h>
#include <java/io/FileWriter.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/LineNumberReader.h>
#include <java/io/PipedReader.h>
#include <java/io/PipedWriter.h>
#include <java/io/PushbackReader.h>
#include <java/io/Reader.h>
#include <java/io/Serializable.h>
#include <java/io/StringReader.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Arrays.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/function/Function.h>
#include <jcpp.h>

#undef MAX_VALUE
#undef MIN_VALUE

using $IntegerArray = $Array<::java::lang::Integer>;
using $FunctionArray = $Array<::java::util::function::Function>;
using $BufferedReader = ::java::io::BufferedReader;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $CharArrayReader = ::java::io::CharArrayReader;
using $File = ::java::io::File;
using $FileReader = ::java::io::FileReader;
using $FileWriter = ::java::io::FileWriter;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $LineNumberReader = ::java::io::LineNumberReader;
using $PipedReader = ::java::io::PipedReader;
using $PipedWriter = ::java::io::PipedWriter;
using $PushbackReader = ::java::io::PushbackReader;
using $Reader = ::java::io::Reader;
using $Serializable = ::java::io::Serializable;
using $StringReader = ::java::io::StringReader;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Arrays = ::java::util::Arrays;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $Function = ::java::util::function::Function;

class ReaderBulkReadContract$$Lambda$lambda$args$0 : public $Function {
	$class(ReaderBulkReadContract$$Lambda$lambda$args$0, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* s) override {
		 return $of(ReaderBulkReadContract::lambda$args$0($cast($String, s)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ReaderBulkReadContract$$Lambda$lambda$args$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ReaderBulkReadContract$$Lambda$lambda$args$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ReaderBulkReadContract$$Lambda$lambda$args$0, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ReaderBulkReadContract$$Lambda$lambda$args$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ReaderBulkReadContract$$Lambda$lambda$args$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"ReaderBulkReadContract$$Lambda$lambda$args$0",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ReaderBulkReadContract$$Lambda$lambda$args$0::load$($String* name, bool initialize) {
	$loadClass(ReaderBulkReadContract$$Lambda$lambda$args$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ReaderBulkReadContract$$Lambda$lambda$args$0::class$ = nullptr;

class ReaderBulkReadContract$$Lambda$lambda$args$1$1 : public $Function {
	$class(ReaderBulkReadContract$$Lambda$lambda$args$1$1, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* s) override {
		 return $of(ReaderBulkReadContract::lambda$args$1($cast($String, s)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ReaderBulkReadContract$$Lambda$lambda$args$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ReaderBulkReadContract$$Lambda$lambda$args$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ReaderBulkReadContract$$Lambda$lambda$args$1$1, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ReaderBulkReadContract$$Lambda$lambda$args$1$1, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ReaderBulkReadContract$$Lambda$lambda$args$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"ReaderBulkReadContract$$Lambda$lambda$args$1$1",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ReaderBulkReadContract$$Lambda$lambda$args$1$1::load$($String* name, bool initialize) {
	$loadClass(ReaderBulkReadContract$$Lambda$lambda$args$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ReaderBulkReadContract$$Lambda$lambda$args$1$1::class$ = nullptr;

class ReaderBulkReadContract$$Lambda$lambda$args$2$2 : public $Function {
	$class(ReaderBulkReadContract$$Lambda$lambda$args$2$2, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* s) override {
		 return $of(ReaderBulkReadContract::lambda$args$2($cast($String, s)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ReaderBulkReadContract$$Lambda$lambda$args$2$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ReaderBulkReadContract$$Lambda$lambda$args$2$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ReaderBulkReadContract$$Lambda$lambda$args$2$2, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ReaderBulkReadContract$$Lambda$lambda$args$2$2, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ReaderBulkReadContract$$Lambda$lambda$args$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"ReaderBulkReadContract$$Lambda$lambda$args$2$2",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ReaderBulkReadContract$$Lambda$lambda$args$2$2::load$($String* name, bool initialize) {
	$loadClass(ReaderBulkReadContract$$Lambda$lambda$args$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ReaderBulkReadContract$$Lambda$lambda$args$2$2::class$ = nullptr;

class ReaderBulkReadContract$$Lambda$lambda$args$3$3 : public $Function {
	$class(ReaderBulkReadContract$$Lambda$lambda$args$3$3, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* s) override {
		 return $of(ReaderBulkReadContract::lambda$args$3($cast($String, s)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ReaderBulkReadContract$$Lambda$lambda$args$3$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ReaderBulkReadContract$$Lambda$lambda$args$3$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ReaderBulkReadContract$$Lambda$lambda$args$3$3, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ReaderBulkReadContract$$Lambda$lambda$args$3$3, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ReaderBulkReadContract$$Lambda$lambda$args$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"ReaderBulkReadContract$$Lambda$lambda$args$3$3",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ReaderBulkReadContract$$Lambda$lambda$args$3$3::load$($String* name, bool initialize) {
	$loadClass(ReaderBulkReadContract$$Lambda$lambda$args$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ReaderBulkReadContract$$Lambda$lambda$args$3$3::class$ = nullptr;

class ReaderBulkReadContract$$Lambda$lambda$args$4$4 : public $Function {
	$class(ReaderBulkReadContract$$Lambda$lambda$args$4$4, $NO_CLASS_INIT, $Function)
public:
	void init$(ReaderBulkReadContract* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* s) override {
		 return $of($nc(inst$)->lambda$args$4($cast($String, s)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ReaderBulkReadContract$$Lambda$lambda$args$4$4>());
	}
	ReaderBulkReadContract* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ReaderBulkReadContract$$Lambda$lambda$args$4$4::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ReaderBulkReadContract$$Lambda$lambda$args$4$4, inst$)},
	{}
};
$MethodInfo ReaderBulkReadContract$$Lambda$lambda$args$4$4::methodInfos[3] = {
	{"<init>", "(LReaderBulkReadContract;)V", nullptr, $PUBLIC, $method(ReaderBulkReadContract$$Lambda$lambda$args$4$4, init$, void, ReaderBulkReadContract*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ReaderBulkReadContract$$Lambda$lambda$args$4$4, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ReaderBulkReadContract$$Lambda$lambda$args$4$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"ReaderBulkReadContract$$Lambda$lambda$args$4$4",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* ReaderBulkReadContract$$Lambda$lambda$args$4$4::load$($String* name, bool initialize) {
	$loadClass(ReaderBulkReadContract$$Lambda$lambda$args$4$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ReaderBulkReadContract$$Lambda$lambda$args$4$4::class$ = nullptr;

class ReaderBulkReadContract$$Lambda$lambda$args$5$5 : public $Function {
	$class(ReaderBulkReadContract$$Lambda$lambda$args$5$5, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* s) override {
		 return $of(ReaderBulkReadContract::lambda$args$5($cast($String, s)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ReaderBulkReadContract$$Lambda$lambda$args$5$5>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ReaderBulkReadContract$$Lambda$lambda$args$5$5::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ReaderBulkReadContract$$Lambda$lambda$args$5$5, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ReaderBulkReadContract$$Lambda$lambda$args$5$5, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ReaderBulkReadContract$$Lambda$lambda$args$5$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"ReaderBulkReadContract$$Lambda$lambda$args$5$5",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ReaderBulkReadContract$$Lambda$lambda$args$5$5::load$($String* name, bool initialize) {
	$loadClass(ReaderBulkReadContract$$Lambda$lambda$args$5$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ReaderBulkReadContract$$Lambda$lambda$args$5$5::class$ = nullptr;

class ReaderBulkReadContract$$Lambda$lambda$args$6$6 : public $Function {
	$class(ReaderBulkReadContract$$Lambda$lambda$args$6$6, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* s) override {
		 return $of(ReaderBulkReadContract::lambda$args$6($cast($String, s)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ReaderBulkReadContract$$Lambda$lambda$args$6$6>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ReaderBulkReadContract$$Lambda$lambda$args$6$6::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ReaderBulkReadContract$$Lambda$lambda$args$6$6, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ReaderBulkReadContract$$Lambda$lambda$args$6$6, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ReaderBulkReadContract$$Lambda$lambda$args$6$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"ReaderBulkReadContract$$Lambda$lambda$args$6$6",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ReaderBulkReadContract$$Lambda$lambda$args$6$6::load$($String* name, bool initialize) {
	$loadClass(ReaderBulkReadContract$$Lambda$lambda$args$6$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ReaderBulkReadContract$$Lambda$lambda$args$6$6::class$ = nullptr;

class ReaderBulkReadContract$$Lambda$lambda$args$7$7 : public $Function {
	$class(ReaderBulkReadContract$$Lambda$lambda$args$7$7, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* s) override {
		 return $of(ReaderBulkReadContract::lambda$args$7($cast($String, s)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ReaderBulkReadContract$$Lambda$lambda$args$7$7>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ReaderBulkReadContract$$Lambda$lambda$args$7$7::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ReaderBulkReadContract$$Lambda$lambda$args$7$7, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ReaderBulkReadContract$$Lambda$lambda$args$7$7, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ReaderBulkReadContract$$Lambda$lambda$args$7$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"ReaderBulkReadContract$$Lambda$lambda$args$7$7",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ReaderBulkReadContract$$Lambda$lambda$args$7$7::load$($String* name, bool initialize) {
	$loadClass(ReaderBulkReadContract$$Lambda$lambda$args$7$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ReaderBulkReadContract$$Lambda$lambda$args$7$7::class$ = nullptr;

class ReaderBulkReadContract$$Lambda$createTempFileWithContents$8 : public $Function {
	$class(ReaderBulkReadContract$$Lambda$createTempFileWithContents$8, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* contents) override {
		 return $of(ReaderBulkReadContract::createTempFileWithContents($cast($String, contents)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ReaderBulkReadContract$$Lambda$createTempFileWithContents$8>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ReaderBulkReadContract$$Lambda$createTempFileWithContents$8::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ReaderBulkReadContract$$Lambda$createTempFileWithContents$8, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ReaderBulkReadContract$$Lambda$createTempFileWithContents$8, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ReaderBulkReadContract$$Lambda$createTempFileWithContents$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"ReaderBulkReadContract$$Lambda$createTempFileWithContents$8",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ReaderBulkReadContract$$Lambda$createTempFileWithContents$8::load$($String* name, bool initialize) {
	$loadClass(ReaderBulkReadContract$$Lambda$createTempFileWithContents$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ReaderBulkReadContract$$Lambda$createTempFileWithContents$8::class$ = nullptr;

$FieldInfo _ReaderBulkReadContract_FieldInfo_[] = {
	{"cache", "Ljava/util/concurrent/ConcurrentHashMap;", "Ljava/util/concurrent/ConcurrentHashMap<Ljava/lang/String;Ljava/io/File;>;", $PRIVATE | $FINAL, $field(ReaderBulkReadContract, cache)},
	{}
};

$MethodInfo _ReaderBulkReadContract_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ReaderBulkReadContract, init$, void)},
	{"args", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<[Ljava/lang/Object;>;", $PRIVATE, $method(ReaderBulkReadContract, args, $Iterator*)},
	{"createTempFileWithContents", "(Ljava/lang/String;)Ljava/io/File;", nullptr, $PRIVATE | $STATIC, $staticMethod(ReaderBulkReadContract, createTempFileWithContents, $File*, $String*)},
	{"lambda$args$0", "(Ljava/lang/String;)Ljava/io/Reader;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ReaderBulkReadContract, lambda$args$0, $Reader*, $String*)},
	{"lambda$args$1", "(Ljava/lang/String;)Ljava/io/Reader;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ReaderBulkReadContract, lambda$args$1, $Reader*, $String*)},
	{"lambda$args$2", "(Ljava/lang/String;)Ljava/io/Reader;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ReaderBulkReadContract, lambda$args$2, $Reader*, $String*)},
	{"lambda$args$3", "(Ljava/lang/String;)Ljava/io/Reader;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ReaderBulkReadContract, lambda$args$3, $Reader*, $String*)},
	{"lambda$args$4", "(Ljava/lang/String;)Ljava/io/Reader;", nullptr, $PRIVATE | $SYNTHETIC, $method(ReaderBulkReadContract, lambda$args$4, $Reader*, $String*)},
	{"lambda$args$5", "(Ljava/lang/String;)Ljava/io/Reader;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ReaderBulkReadContract, lambda$args$5, $Reader*, $String*)},
	{"lambda$args$6", "(Ljava/lang/String;)Ljava/io/Reader;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ReaderBulkReadContract, lambda$args$6, $Reader*, $String*)},
	{"lambda$args$7", "(Ljava/lang/String;)Ljava/io/Reader;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ReaderBulkReadContract, lambda$args$7, $Reader*, $String*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ReaderBulkReadContract, main, void, $StringArray*), "java.io.IOException"},
	{"newFileReader", "(Ljava/lang/String;)Ljava/io/FileReader;", nullptr, $PRIVATE, $method(ReaderBulkReadContract, newFileReader, $FileReader*, $String*)},
	{"newPipedReader", "(Ljava/lang/String;)Ljava/io/PipedReader;", nullptr, $PRIVATE | $STATIC, $staticMethod(ReaderBulkReadContract, newPipedReader, $PipedReader*, $String*)},
	{"read", "(Ljava/io/Reader;III)V", nullptr, $PRIVATE, $method(ReaderBulkReadContract, read, void, $Reader*, int32_t, int32_t, int32_t), "java.io.IOException"},
	{"test", "()V", nullptr, $PRIVATE, $method(ReaderBulkReadContract, test, void), "java.io.IOException"},
	{}
};

$ClassInfo _ReaderBulkReadContract_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ReaderBulkReadContract",
	"java.lang.Object",
	nullptr,
	_ReaderBulkReadContract_FieldInfo_,
	_ReaderBulkReadContract_MethodInfo_
};

$Object* allocate$ReaderBulkReadContract($Class* clazz) {
	return $of($alloc(ReaderBulkReadContract));
}

void ReaderBulkReadContract::init$() {
	$set(this, cache, $new($ConcurrentHashMap));
}

void ReaderBulkReadContract::main($StringArray* args) {
	$var(ReaderBulkReadContract, t, $new(ReaderBulkReadContract));
	t->test();
}

void ReaderBulkReadContract::test() {
	$useLocalCurrentObjectStackCache();
	$var($Iterator, args, this->args());
	while ($nc(args)->hasNext()) {
		$var($ObjectArray, a, $cast($ObjectArray, args->next()));
		$var($Reader, r, $cast($Reader, $nc(a)->get(0)));
		int32_t size = $nc(($cast($Integer, a->get(1))))->intValue();
		int32_t off = $nc(($cast($Integer, a->get(2))))->intValue();
		int32_t len = $nc(($cast($Integer, a->get(3))))->intValue();
		{
			$var($Throwable, var$0, nullptr);
			try {
				read(r, size, off, len);
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				$nc(r)->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

$Iterator* ReaderBulkReadContract::args() {
	$useLocalCurrentObjectStackCache();
	$var($IntegerArray, lens, $new($IntegerArray, {
		$($Integer::valueOf($Integer::MIN_VALUE)),
		$($Integer::valueOf(-5)),
		$($Integer::valueOf(-4)),
		$($Integer::valueOf(-3)),
		$($Integer::valueOf(-2)),
		$($Integer::valueOf(-1)),
		$($Integer::valueOf(0)),
		$($Integer::valueOf(1)),
		$($Integer::valueOf(2)),
		$($Integer::valueOf(3)),
		$($Integer::valueOf(4)),
		$($Integer::valueOf(5)),
		$($Integer::valueOf($Integer::MAX_VALUE))
	}));
	$var($IntegerArray, offs, $new($IntegerArray, {
		$($Integer::valueOf($Integer::MIN_VALUE)),
		$($Integer::valueOf(-5)),
		$($Integer::valueOf(-4)),
		$($Integer::valueOf(-3)),
		$($Integer::valueOf(-2)),
		$($Integer::valueOf(-1)),
		$($Integer::valueOf(0)),
		$($Integer::valueOf(1)),
		$($Integer::valueOf(2)),
		$($Integer::valueOf(3)),
		$($Integer::valueOf(4)),
		$($Integer::valueOf(5)),
		$($Integer::valueOf($Integer::MAX_VALUE))
	}));
	$var($IntegerArray, sizes, $new($IntegerArray, {
		$($Integer::valueOf(0)),
		$($Integer::valueOf(1)),
		$($Integer::valueOf(2)),
		$($Integer::valueOf(3)),
		$($Integer::valueOf(4)),
		$($Integer::valueOf(5))
	}));
	$var($StringArray, contents, $new($StringArray, {
		""_s,
		"a"_s,
		"ab"_s
	}));
	$var($List, fs, $Arrays::asList($$new($FunctionArray, {
		static_cast<$Function*>($$new(ReaderBulkReadContract$$Lambda$lambda$args$0)),
		static_cast<$Function*>($$new(ReaderBulkReadContract$$Lambda$lambda$args$1$1)),
		static_cast<$Function*>($$new(ReaderBulkReadContract$$Lambda$lambda$args$2$2)),
		static_cast<$Function*>($$new(ReaderBulkReadContract$$Lambda$lambda$args$3$3)),
		static_cast<$Function*>($$new(ReaderBulkReadContract$$Lambda$lambda$args$4$4, this)),
		static_cast<$Function*>($$new(ReaderBulkReadContract$$Lambda$lambda$args$5$5)),
		static_cast<$Function*>($$new(ReaderBulkReadContract$$Lambda$lambda$args$6$6)),
		static_cast<$Function*>($$new(ReaderBulkReadContract$$Lambda$lambda$args$7$7))
	})));
	$var($List, tuples, $Collections::synchronizedList($$new($LinkedList)));
	{
		$var($IntegerArray, arr$, lens);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Integer, len, arr$->get(i$));
			{
				$var($IntegerArray, arr$, offs);
				int32_t len$ = arr$->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($Integer, off, arr$->get(i$));
					{
						$var($StringArray, arr$, contents);
						int32_t len$ = arr$->length;
						int32_t i$ = 0;
						for (; i$ < len$; ++i$) {
							$var($String, s, arr$->get(i$));
							{
								$var($IntegerArray, arr$, sizes);
								int32_t len$ = arr$->length;
								int32_t i$ = 0;
								for (; i$ < len$; ++i$) {
									$var($Integer, size, arr$->get(i$));
									{
										$var($Iterator, i$, $nc(fs)->iterator());
										for (; $nc(i$)->hasNext();) {
											$var($Function, f, $cast($Function, i$->next()));
											$nc(tuples)->add($$new($ObjectArray, {
												$($nc(f)->apply(s)),
												$of(size),
												$of(off),
												$of(len)
											}));
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return $nc(tuples)->iterator();
}

void ReaderBulkReadContract::read($Reader* r, int32_t size, int32_t off, int32_t len) {
	$useLocalCurrentObjectStackCache();
	$var($IndexOutOfBoundsException, ex, nullptr);
	try {
		$nc(r)->read($$new($chars, size), off, len);
	} catch ($IndexOutOfBoundsException& e) {
		$assign(ex, e);
	}
	bool incorrectBounds = off < 0 || len < 0 || len > size - off;
	bool exceptionThrown = ex != nullptr;
	if (incorrectBounds != exceptionThrown) {
		$throwNew($AssertionError, $($of($String::format("r=%s, size=%s, off=%s, len=%s, incorrectBounds=%s, exceptionThrown=%s"_s, $$new($ObjectArray, {
			$of(r),
			$($of($Integer::valueOf(size))),
			$($of($Integer::valueOf(off))),
			$($of($Integer::valueOf(len))),
			$($of($Boolean::valueOf(incorrectBounds))),
			$($of($Boolean::valueOf(exceptionThrown)))
		})))));
	}
}

$PipedReader* ReaderBulkReadContract::newPipedReader($String* contents) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($PipedWriter, w, $new($PipedWriter));
		{
			$var($Throwable, var$0, nullptr);
			$var($PipedReader, var$2, nullptr);
			bool return$1 = false;
			try {
				try {
					$var($PipedReader, r, $new($PipedReader, w));
					w->write(contents);
					$assign(var$2, r);
					return$1 = true;
					goto $finally;
				} catch ($Throwable& t$) {
					try {
						w->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				w->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	} catch ($IOException& e) {
		$throwNew($UncheckedIOException, e);
	}
	$shouldNotReachHere();
}

$FileReader* ReaderBulkReadContract::newFileReader($String* contents) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($File, f, $cast($File, $nc(this->cache)->computeIfAbsent(contents, static_cast<$Function*>($$new(ReaderBulkReadContract$$Lambda$createTempFileWithContents$8)))));
		return $new($FileReader, f);
	} catch ($IOException& e) {
		$throwNew($UncheckedIOException, e);
	}
	$shouldNotReachHere();
}

$File* ReaderBulkReadContract::createTempFileWithContents($String* contents) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($File, testDir, $new($File, $($System::getProperty("test.dir"_s, "."_s))));
		$var($File, file, $File::createTempFile("ReaderContract"_s, ""_s, testDir));
		{
			$var($FileWriter, w, $new($FileWriter, file));
			{
				$var($Throwable, var$0, nullptr);
				try {
					try {
						w->write(contents);
					} catch ($Throwable& t$) {
						try {
							w->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
						$throw(t$);
					}
				} catch ($Throwable& var$1) {
					$assign(var$0, var$1);
				} /*finally*/ {
					w->close();
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		}
		return file;
	} catch ($IOException& e) {
		$throwNew($UncheckedIOException, e);
	}
	$shouldNotReachHere();
}

$Reader* ReaderBulkReadContract::lambda$args$7($String* s) {
	return $new($StringReader, s);
}

$Reader* ReaderBulkReadContract::lambda$args$6($String* s) {
	return newPipedReader(s);
}

$Reader* ReaderBulkReadContract::lambda$args$5($String* s) {
	return $new($PushbackReader, $$new($StringReader, s));
}

$Reader* ReaderBulkReadContract::lambda$args$4($String* s) {
	return newFileReader(s);
}

$Reader* ReaderBulkReadContract::lambda$args$3($String* s) {
	$useLocalCurrentObjectStackCache();
	return $new($InputStreamReader, $$new($ByteArrayInputStream, $($nc(s)->getBytes())));
}

$Reader* ReaderBulkReadContract::lambda$args$2($String* s) {
	return $new($CharArrayReader, $($nc(s)->toCharArray()));
}

$Reader* ReaderBulkReadContract::lambda$args$1($String* s) {
	return $new($LineNumberReader, $$new($StringReader, s));
}

$Reader* ReaderBulkReadContract::lambda$args$0($String* s) {
	return $new($BufferedReader, $$new($StringReader, s));
}

ReaderBulkReadContract::ReaderBulkReadContract() {
}

$Class* ReaderBulkReadContract::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ReaderBulkReadContract$$Lambda$lambda$args$0::classInfo$.name)) {
			return ReaderBulkReadContract$$Lambda$lambda$args$0::load$(name, initialize);
		}
		if (name->equals(ReaderBulkReadContract$$Lambda$lambda$args$1$1::classInfo$.name)) {
			return ReaderBulkReadContract$$Lambda$lambda$args$1$1::load$(name, initialize);
		}
		if (name->equals(ReaderBulkReadContract$$Lambda$lambda$args$2$2::classInfo$.name)) {
			return ReaderBulkReadContract$$Lambda$lambda$args$2$2::load$(name, initialize);
		}
		if (name->equals(ReaderBulkReadContract$$Lambda$lambda$args$3$3::classInfo$.name)) {
			return ReaderBulkReadContract$$Lambda$lambda$args$3$3::load$(name, initialize);
		}
		if (name->equals(ReaderBulkReadContract$$Lambda$lambda$args$4$4::classInfo$.name)) {
			return ReaderBulkReadContract$$Lambda$lambda$args$4$4::load$(name, initialize);
		}
		if (name->equals(ReaderBulkReadContract$$Lambda$lambda$args$5$5::classInfo$.name)) {
			return ReaderBulkReadContract$$Lambda$lambda$args$5$5::load$(name, initialize);
		}
		if (name->equals(ReaderBulkReadContract$$Lambda$lambda$args$6$6::classInfo$.name)) {
			return ReaderBulkReadContract$$Lambda$lambda$args$6$6::load$(name, initialize);
		}
		if (name->equals(ReaderBulkReadContract$$Lambda$lambda$args$7$7::classInfo$.name)) {
			return ReaderBulkReadContract$$Lambda$lambda$args$7$7::load$(name, initialize);
		}
		if (name->equals(ReaderBulkReadContract$$Lambda$createTempFileWithContents$8::classInfo$.name)) {
			return ReaderBulkReadContract$$Lambda$createTempFileWithContents$8::load$(name, initialize);
		}
	}
	$loadClass(ReaderBulkReadContract, name, initialize, &_ReaderBulkReadContract_ClassInfo_, allocate$ReaderBulkReadContract);
	return class$;
}

$Class* ReaderBulkReadContract::class$ = nullptr;