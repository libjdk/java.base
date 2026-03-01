#include <java/lang/ProcessEnvironment.h>

#include <java/lang/ProcessEnvironment$StringEnvironment.h>
#include <java/lang/ProcessEnvironment$Value.h>
#include <java/lang/ProcessEnvironment$Variable.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <jcpp.h>

#undef MIN_NAME_LENGTH

using $byteArray2 = $Array<int8_t, 2>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ProcessEnvironment$StringEnvironment = ::java::lang::ProcessEnvironment$StringEnvironment;
using $ProcessEnvironment$Value = ::java::lang::ProcessEnvironment$Value;
using $ProcessEnvironment$Variable = ::java::lang::ProcessEnvironment$Variable;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;

namespace java {
	namespace lang {

$FieldInfo _ProcessEnvironment_FieldInfo_[] = {
	{"theEnvironment", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/ProcessEnvironment$Variable;Ljava/lang/ProcessEnvironment$Value;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ProcessEnvironment, theEnvironment)},
	{"theUnmodifiableEnvironment", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ProcessEnvironment, theUnmodifiableEnvironment)},
	{"MIN_NAME_LENGTH", "I", nullptr, $STATIC | $FINAL, $constField(ProcessEnvironment, MIN_NAME_LENGTH)},
	{}
};

$MethodInfo _ProcessEnvironment_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ProcessEnvironment, init$, void)},
	{"arrayCompare", "([B[B)I", nullptr, $PRIVATE | $STATIC, $staticMethod(ProcessEnvironment, arrayCompare, int32_t, $bytes*, $bytes*)},
	{"arrayEquals", "([B[B)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ProcessEnvironment, arrayEquals, bool, $bytes*, $bytes*)},
	{"arrayHash", "([B)I", nullptr, $PRIVATE | $STATIC, $staticMethod(ProcessEnvironment, arrayHash, int32_t, $bytes*)},
	{"emptyEnvironment", "(I)Ljava/util/Map;", "(I)Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $STATIC, $staticMethod(ProcessEnvironment, emptyEnvironment, $Map*, int32_t)},
	{"environ", "()[[B", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(ProcessEnvironment, environ, $byteArray2*)},
	{"environment", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $STATIC, $staticMethod(ProcessEnvironment, environment, $Map*)},
	{"getenv", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(ProcessEnvironment, getenv, $String*, $String*)},
	{"getenv", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $STATIC, $staticMethod(ProcessEnvironment, getenv, $Map*)},
	{"toEnvironmentBlock", "(Ljava/util/Map;[I)[B", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;[I)[B", $STATIC, $staticMethod(ProcessEnvironment, toEnvironmentBlock, $bytes*, $Map*, $ints*)},
	{"validateValue", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ProcessEnvironment, validateValue, void, $String*)},
	{"validateVariable", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ProcessEnvironment, validateVariable, void, $String*)},
	{}
};

#define _METHOD_INDEX_environ 5

$InnerClassInfo _ProcessEnvironment_InnerClassesInfo_[] = {
	{"java.lang.ProcessEnvironment$StringKeySet", "java.lang.ProcessEnvironment", "StringKeySet", $PRIVATE | $STATIC},
	{"java.lang.ProcessEnvironment$StringValues", "java.lang.ProcessEnvironment", "StringValues", $PRIVATE | $STATIC},
	{"java.lang.ProcessEnvironment$StringEntrySet", "java.lang.ProcessEnvironment", "StringEntrySet", $PRIVATE | $STATIC},
	{"java.lang.ProcessEnvironment$StringEntry", "java.lang.ProcessEnvironment", "StringEntry", $PRIVATE | $STATIC},
	{"java.lang.ProcessEnvironment$StringEnvironment", "java.lang.ProcessEnvironment", "StringEnvironment", $PRIVATE | $STATIC},
	{"java.lang.ProcessEnvironment$Value", "java.lang.ProcessEnvironment", "Value", $PRIVATE | $STATIC},
	{"java.lang.ProcessEnvironment$Variable", "java.lang.ProcessEnvironment", "Variable", $PRIVATE | $STATIC},
	{"java.lang.ProcessEnvironment$ExternalData", "java.lang.ProcessEnvironment", "ExternalData", $PRIVATE | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _ProcessEnvironment_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.lang.ProcessEnvironment",
	"java.lang.Object",
	nullptr,
	_ProcessEnvironment_FieldInfo_,
	_ProcessEnvironment_MethodInfo_,
	nullptr,
	nullptr,
	_ProcessEnvironment_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.ProcessEnvironment$StringKeySet,java.lang.ProcessEnvironment$StringKeySet$1,java.lang.ProcessEnvironment$StringValues,java.lang.ProcessEnvironment$StringValues$1,java.lang.ProcessEnvironment$StringEntrySet,java.lang.ProcessEnvironment$StringEntrySet$2,java.lang.ProcessEnvironment$StringEntrySet$1,java.lang.ProcessEnvironment$StringEntry,java.lang.ProcessEnvironment$StringEnvironment,java.lang.ProcessEnvironment$Value,java.lang.ProcessEnvironment$Variable,java.lang.ProcessEnvironment$ExternalData"
};

$Object* allocate$ProcessEnvironment($Class* clazz) {
	return $of($alloc(ProcessEnvironment));
}

$HashMap* ProcessEnvironment::theEnvironment = nullptr;
$Map* ProcessEnvironment::theUnmodifiableEnvironment = nullptr;

$String* ProcessEnvironment::getenv($String* name) {
	$init(ProcessEnvironment);
	return $cast($String, $nc(ProcessEnvironment::theUnmodifiableEnvironment)->get(name));
}

$Map* ProcessEnvironment::getenv() {
	$init(ProcessEnvironment);
	return ProcessEnvironment::theUnmodifiableEnvironment;
}

$Map* ProcessEnvironment::environment() {
	$init(ProcessEnvironment);
	return $new($ProcessEnvironment$StringEnvironment, ($cast($Map, $($nc(ProcessEnvironment::theEnvironment)->clone()))));
}

$Map* ProcessEnvironment::emptyEnvironment(int32_t capacity) {
	$init(ProcessEnvironment);
	return $new($ProcessEnvironment$StringEnvironment, $$new($HashMap, capacity));
}

$byteArray2* ProcessEnvironment::environ() {
	$init(ProcessEnvironment);
	$var($byteArray2, $ret, nullptr);
	$prepareNativeStatic(ProcessEnvironment, environ, $byteArray2*);
	$assign($ret, $invokeNativeStaticObject());
	$finishNativeStatic();
	return $ret;
}

void ProcessEnvironment::init$() {
}

void ProcessEnvironment::validateVariable($String* name) {
	$init(ProcessEnvironment);
	bool var$0 = $nc(name)->indexOf((int32_t)u'=') != -1;
	if (var$0 || $nc(name)->indexOf((int32_t)u'\0') != -1) {
		$throwNew($IllegalArgumentException, $$str({"Invalid environment variable name: \""_s, name, "\""_s}));
	}
}

void ProcessEnvironment::validateValue($String* value) {
	$init(ProcessEnvironment);
	if ($nc(value)->indexOf((int32_t)u'\0') != -1) {
		$throwNew($IllegalArgumentException, $$str({"Invalid environment variable value: \""_s, value, "\""_s}));
	}
}

$bytes* ProcessEnvironment::toEnvironmentBlock($Map* map, $ints* envc) {
	$init(ProcessEnvironment);
	return map == nullptr ? ($bytes*)nullptr : $nc(($cast($ProcessEnvironment$StringEnvironment, map)))->toEnvironmentBlock(envc);
}

int32_t ProcessEnvironment::arrayCompare($bytes* x, $bytes* y) {
	$init(ProcessEnvironment);
	int32_t min = $nc(x)->length < $nc(y)->length ? $nc(x)->length : $nc(y)->length;
	for (int32_t i = 0; i < min; ++i) {
		if (x->get(i) != y->get(i)) {
			return x->get(i) - y->get(i);
		}
	}
	return x->length - y->length;
}

bool ProcessEnvironment::arrayEquals($bytes* x, $bytes* y) {
	$init(ProcessEnvironment);
	if ($nc(x)->length != $nc(y)->length) {
		return false;
	}
	for (int32_t i = 0; i < $nc(x)->length; ++i) {
		if (x->get(i) != $nc(y)->get(i)) {
			return false;
		}
	}
	return true;
}

int32_t ProcessEnvironment::arrayHash($bytes* x) {
	$init(ProcessEnvironment);
	int32_t hash = 0;
	for (int32_t i = 0; i < $nc(x)->length; ++i) {
		hash = 31 * hash + x->get(i);
	}
	return hash;
}

void clinit$ProcessEnvironment($Class* class$) {
	$useLocalCurrentObjectStackCache();
	{
		$var($byteArray2, environ, ProcessEnvironment::environ());
		$assignStatic(ProcessEnvironment::theEnvironment, $new($HashMap, $nc(environ)->length / 2 + 3));
		for (int32_t i = $nc(environ)->length - 1; i > 0; i -= 2) {
			$var($Object, var$0, $of($ProcessEnvironment$Variable::valueOf(environ->get(i - 1))));
			$nc(ProcessEnvironment::theEnvironment)->put(var$0, $($ProcessEnvironment$Value::valueOf(environ->get(i))));
		}
		$assignStatic(ProcessEnvironment::theUnmodifiableEnvironment, $Collections::unmodifiableMap($$new($ProcessEnvironment$StringEnvironment, ProcessEnvironment::theEnvironment)));
	}
}

ProcessEnvironment::ProcessEnvironment() {
}

$Class* ProcessEnvironment::load$($String* name, bool initialize) {
	$loadClass(ProcessEnvironment, name, initialize, &_ProcessEnvironment_ClassInfo_, clinit$ProcessEnvironment, allocate$ProcessEnvironment);
	return class$;
}

$Class* ProcessEnvironment::class$ = nullptr;

	} // lang
} // java