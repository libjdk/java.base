#include <ContentEquals.h>

#include <java/lang/CharSequence.h>
#include <java/lang/StringBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/util/Random.h>
#include <jcpp.h>

#undef ITERATIONS
#undef STR_LEN

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $StringBuffer = ::java::lang::StringBuffer;
using $CharBuffer = ::java::nio::CharBuffer;
using $Random = ::java::util::Random;

$FieldInfo _ContentEquals_FieldInfo_[] = {
	{"rnd", "Ljava/util/Random;", nullptr, $PRIVATE | $STATIC, $staticField(ContentEquals, rnd)},
	{"ITERATIONS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ContentEquals, ITERATIONS)},
	{"STR_LEN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ContentEquals, STR_LEN)},
	{}
};

$MethodInfo _ContentEquals_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ContentEquals, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ContentEquals, main, void, $StringArray*), "java.lang.Exception"},
	{"testCharSequence", "()V", nullptr, $PUBLIC | $STATIC, $staticMethod(ContentEquals, testCharSequence, void), "java.lang.Exception"},
	{"testString", "()V", nullptr, $PUBLIC | $STATIC, $staticMethod(ContentEquals, testString, void), "java.lang.Exception"},
	{"testStringBuffer", "()V", nullptr, $PUBLIC | $STATIC, $staticMethod(ContentEquals, testStringBuffer, void), "java.lang.Exception"},
	{"testStringBuilder", "()V", nullptr, $PUBLIC | $STATIC, $staticMethod(ContentEquals, testStringBuilder, void), "java.lang.Exception"},
	{}
};

$ClassInfo _ContentEquals_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ContentEquals",
	"java.lang.Object",
	nullptr,
	_ContentEquals_FieldInfo_,
	_ContentEquals_MethodInfo_
};

$Object* allocate$ContentEquals($Class* clazz) {
	return $of($alloc(ContentEquals));
}

$Random* ContentEquals::rnd = nullptr;

void ContentEquals::init$() {
}

void ContentEquals::main($StringArray* args) {
	$init(ContentEquals);
	testStringBuffer();
	testStringBuilder();
	testString();
	testCharSequence();
}

void ContentEquals::testStringBuffer() {
	$init(ContentEquals);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < ContentEquals::ITERATIONS; ++i) {
		int32_t length = $nc(ContentEquals::rnd)->nextInt(ContentEquals::STR_LEN) + 1;
		$var($StringBuffer, testStringBuffer, $new($StringBuffer));
		for (int32_t x = 0; x < length; ++x) {
			char16_t aChar = (char16_t)$nc(ContentEquals::rnd)->nextInt();
			testStringBuffer->append(aChar);
		}
		$var($String, testString, testStringBuffer->toString());
		char16_t c = testStringBuffer->charAt(0);
		testStringBuffer->setCharAt(0, u'c');
		testStringBuffer->setCharAt(0, c);
		if (!$nc(testString)->contentEquals(testStringBuffer)) {
			$throwNew($RuntimeException, "ContentsEqual failure"_s);
		}
	}
}

void ContentEquals::testStringBuilder() {
	$init(ContentEquals);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < ContentEquals::ITERATIONS; ++i) {
		int32_t length = $nc(ContentEquals::rnd)->nextInt(ContentEquals::STR_LEN) + 1;
		$var($StringBuilder, testStringBuilder, $new($StringBuilder));
		for (int32_t x = 0; x < length; ++x) {
			char16_t aChar = (char16_t)$nc(ContentEquals::rnd)->nextInt();
			testStringBuilder->append(aChar);
		}
		$var($String, testString, testStringBuilder->toString());
		char16_t c = testStringBuilder->charAt(0);
		testStringBuilder->setCharAt(0, u'c');
		testStringBuilder->setCharAt(0, c);
		if (!$nc(testString)->contentEquals(static_cast<$CharSequence*>(testStringBuilder))) {
			$throwNew($RuntimeException, "ContentsEqual failure"_s);
		}
	}
}

void ContentEquals::testString() {
	$init(ContentEquals);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < ContentEquals::ITERATIONS; ++i) {
		int32_t length = $nc(ContentEquals::rnd)->nextInt(ContentEquals::STR_LEN) + 1;
		$var($StringBuilder, testStringBuilder, $new($StringBuilder));
		for (int32_t x = 0; x < length; ++x) {
			char16_t aChar = (char16_t)$nc(ContentEquals::rnd)->nextInt();
			testStringBuilder->append(aChar);
		}
		$var($String, testString, testStringBuilder->toString());
		char16_t c = testStringBuilder->charAt(0);
		testStringBuilder->setCharAt(0, u'c');
		testStringBuilder->setCharAt(0, c);
		if (!$nc(testString)->contentEquals($(static_cast<$CharSequence*>(testStringBuilder->toString())))) {
			$throwNew($RuntimeException, "ContentsEqual failure"_s);
		}
	}
}

void ContentEquals::testCharSequence() {
	$init(ContentEquals);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < ContentEquals::ITERATIONS; ++i) {
		int32_t length = $nc(ContentEquals::rnd)->nextInt(ContentEquals::STR_LEN) + 1;
		$var($StringBuilder, testStringBuilder, $new($StringBuilder));
		for (int32_t x = 0; x < length; ++x) {
			char16_t aChar = (char16_t)$nc(ContentEquals::rnd)->nextInt();
			testStringBuilder->append(aChar);
		}
		$var($String, testString, testStringBuilder->toString());
		char16_t c = testStringBuilder->charAt(0);
		testStringBuilder->setCharAt(0, u'c');
		testStringBuilder->setCharAt(0, c);
		$var($CharBuffer, buf, $CharBuffer::wrap($(static_cast<$CharSequence*>(testStringBuilder->toString()))));
		if (!$nc(testString)->contentEquals(static_cast<$CharSequence*>(buf))) {
			$throwNew($RuntimeException, "ContentsEqual failure"_s);
		}
	}
}

void clinit$ContentEquals($Class* class$) {
	$assignStatic(ContentEquals::rnd, $new($Random));
}

ContentEquals::ContentEquals() {
}

$Class* ContentEquals::load$($String* name, bool initialize) {
	$loadClass(ContentEquals, name, initialize, &_ContentEquals_ClassInfo_, clinit$ContentEquals, allocate$ContentEquals);
	return class$;
}

$Class* ContentEquals::class$ = nullptr;