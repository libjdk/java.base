#include <AppendCharSequence.h>

#include <AppendCharSequence$MyNegativeLenCharSeq.h>
#include <java/lang/CharSequence.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/NegativeArraySizeException.h>
#include <java/lang/StringBuffer.h>
#include <java/util/Random.h>
#include <jcpp.h>

#undef MIN_VALUE

using $AppendCharSequence$MyNegativeLenCharSeq = ::AppendCharSequence$MyNegativeLenCharSeq;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NegativeArraySizeException = ::java::lang::NegativeArraySizeException;
using $RuntimeException = ::java::lang::RuntimeException;
using $StringBuffer = ::java::lang::StringBuffer;
using $Random = ::java::util::Random;

$FieldInfo _AppendCharSequence_FieldInfo_[] = {
	{"generator", "Ljava/util/Random;", nullptr, $PRIVATE | $STATIC, $staticField(AppendCharSequence, generator)},
	{}
};

$MethodInfo _AppendCharSequence_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(AppendCharSequence, init$, void)},
	{"bash", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(AppendCharSequence, bash, void), "java.lang.Exception"},
	{"checkConstructor", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(AppendCharSequence, checkConstructor, void), "java.lang.Exception"},
	{"checkNegativeLenCharSeq", "(I)V", nullptr, $PRIVATE | $STATIC, $staticMethod(AppendCharSequence, checkNegativeLenCharSeq, void, int32_t)},
	{"checkNulls", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(AppendCharSequence, checkNulls, void), "java.lang.Exception"},
	{"checkOffsets", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(AppendCharSequence, checkOffsets, void), "java.lang.Exception"},
	{"generateTestBuffer", "(II)Ljava/lang/StringBuffer;", nullptr, $PRIVATE | $STATIC, $staticMethod(AppendCharSequence, generateTestBuffer, $StringBuffer*, int32_t, int32_t)},
	{"getRandomIndex", "(II)I", nullptr, $PRIVATE | $STATIC, $staticMethod(AppendCharSequence, getRandomIndex, int32_t, int32_t, int32_t)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(AppendCharSequence, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$InnerClassInfo _AppendCharSequence_InnerClassesInfo_[] = {
	{"AppendCharSequence$MyNegativeLenCharSeq", "AppendCharSequence", "MyNegativeLenCharSeq", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _AppendCharSequence_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"AppendCharSequence",
	"java.lang.Object",
	nullptr,
	_AppendCharSequence_FieldInfo_,
	_AppendCharSequence_MethodInfo_,
	nullptr,
	nullptr,
	_AppendCharSequence_InnerClassesInfo_,
	nullptr,
	nullptr,
	"AppendCharSequence$MyNegativeLenCharSeq"
};

$Object* allocate$AppendCharSequence($Class* clazz) {
	return $of($alloc(AppendCharSequence));
}

$Random* AppendCharSequence::generator = nullptr;

void AppendCharSequence::init$() {
}

void AppendCharSequence::main($StringArray* args) {
	$init(AppendCharSequence);
	bash();
	checkNulls();
	checkOffsets();
	checkConstructor();
}

void AppendCharSequence::bash() {
	$init(AppendCharSequence);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < 1000; ++i) {
		$var($StringBuffer, sb1, generateTestBuffer(0, 100));
		$var($StringBuffer, sb2, generateTestBuffer(0, 100));
		$var($StringBuffer, sb3, generateTestBuffer(0, 100));
		$var($StringBuffer, sb4, generateTestBuffer(0, 100));
		$var($StringBuffer, sb5, $new($StringBuffer));
		$var($String, s1, $nc(sb1)->toString());
		$var($String, s2, $nc(sb2)->toString());
		$var($String, s3, $nc(sb3)->toString());
		$var($String, s4, $nc(sb4)->toString());
		$var($String, s5, nullptr);
		sb5->append(static_cast<$CharSequence*>(sb1));
		$assign(s5, sb1->toString());
		if (!$nc($(sb5->toString()))->equals(s5)) {
			$throwNew($RuntimeException, "StringBuffer.append failure 1"_s);
		}
		int32_t index = $nc(AppendCharSequence::generator)->nextInt(100);
		int32_t len = $nc(AppendCharSequence::generator)->nextInt(100);
		while (index > sb2->length() - len) {
			index = $nc(AppendCharSequence::generator)->nextInt(100);
			len = $nc(AppendCharSequence::generator)->nextInt(100);
		}
		sb5->append(static_cast<$CharSequence*>(sb2), index, index + len);
		$assign(s5, $str({s5, $($nc($(sb2->toString()))->substring(index, index + len))}));
		if (!$nc($(sb5->toString()))->equals(s5)) {
			$throwNew($RuntimeException, "StringBuffer.append failure 2"_s);
		}
		index = $nc(AppendCharSequence::generator)->nextInt(100);
		while (index > $nc(s5)->length()) {
			index = $nc(AppendCharSequence::generator)->nextInt(100);
		}
		sb5->insert(index, static_cast<$CharSequence*>(sb3));
		$assign(s5, $nc($$new($StringBuffer, s5)->insert(index, static_cast<$CharSequence*>(sb3)))->toString());
		if (!$nc($(sb5->toString()))->equals(s5)) {
			$throwNew($RuntimeException, "StringBuffer.insert failure 1"_s);
		}
		int32_t index1 = $nc(AppendCharSequence::generator)->nextInt(100);
		while (index1 > $nc(s5)->length()) {
			index1 = $nc(AppendCharSequence::generator)->nextInt(100);
		}
		int32_t index2 = $nc(AppendCharSequence::generator)->nextInt(100);
		len = $nc(AppendCharSequence::generator)->nextInt(100);
		while (index2 > sb4->length() - len) {
			index2 = $nc(AppendCharSequence::generator)->nextInt(100);
			len = $nc(AppendCharSequence::generator)->nextInt(100);
		}
		sb5->insert(index1, static_cast<$CharSequence*>(sb4), index2, index2 + len);
		$assign(s5, $nc($$new($StringBuffer, s5)->insert(index1, $($nc(s4)->toCharArray()), index2, len))->toString());
		if (!$nc($(sb5->toString()))->equals(s5)) {
			$throwNew($RuntimeException, "StringBuffer.insert failure 2"_s);
		}
	}
}

int32_t AppendCharSequence::getRandomIndex(int32_t constraint1, int32_t constraint2) {
	$init(AppendCharSequence);
	int32_t range = constraint2 - constraint1;
	int32_t x = $nc(AppendCharSequence::generator)->nextInt(range);
	return constraint1 + x;
}

$StringBuffer* AppendCharSequence::generateTestBuffer(int32_t min, int32_t max) {
	$init(AppendCharSequence);
	$var($StringBuffer, aNewStringBuffer, $new($StringBuffer));
	int32_t aNewLength = getRandomIndex(min, max);
	for (int32_t y = 0; y < aNewLength; ++y) {
		int32_t achar = $nc(AppendCharSequence::generator)->nextInt(30) + 30;
		char16_t test = (char16_t)(achar);
		aNewStringBuffer->append(test);
	}
	return aNewStringBuffer;
}

void AppendCharSequence::checkNulls() {
	$init(AppendCharSequence);
	$useLocalCurrentObjectStackCache();
	$var($StringBuffer, sb1, $new($StringBuffer));
	$var($CharSequence, cs, nullptr);
	sb1->append("test"_s);
	sb1->append(cs);
	if (!$nc($(sb1->toString()))->equals("testnull"_s)) {
		$throwNew($RuntimeException, "StringBuffer.append failure 3"_s);
	}
	$assign(sb1, $new($StringBuffer));
	sb1->append(static_cast<$CharSequence*>("test"_s), 0, 2);
	sb1->append(cs, 0, 2);
	if (!$nc($(sb1->toString()))->equals("tenu"_s)) {
		$throwNew($RuntimeException, "StringBuffer.append failure 4"_s);
	}
	$assign(sb1, $new($StringBuffer, "test"_s));
	sb1->insert(2, cs);
	if (!$nc($(sb1->toString()))->equals("tenullst"_s)) {
		$throwNew($RuntimeException, "StringBuffer.insert failure 3"_s);
	}
	$assign(sb1, $new($StringBuffer, "test"_s));
	sb1->insert(2, cs, 0, 2);
	if (!$nc($(sb1->toString()))->equals("tenust"_s)) {
		$throwNew($RuntimeException, "StringBuffer.insert failure 4"_s);
	}
}

void AppendCharSequence::checkOffsets() {
	$init(AppendCharSequence);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < 100; ++i) {
		$var($StringBuffer, sb, generateTestBuffer(0, 80));
		$var($CharSequence, cs, static_cast<$CharSequence*>(generateTestBuffer(0, 80)));
		int32_t index = 0;
		int32_t len = 0;
		while (index <= $nc(cs)->length() - len) {
			index = $nc(AppendCharSequence::generator)->nextInt(100) - 50;
			len = $nc(AppendCharSequence::generator)->nextInt(100) - 50;
			if (index < 0) {
				break;
			}
			if (len < 0) {
				break;
			}
		}
		try {
			$nc(sb)->append(cs, index, index + len);
			$throwNew($RuntimeException, "Append bounds checking failure"_s);
		} catch ($IndexOutOfBoundsException& e) {
		}
	}
	for (int32_t i = 0; i < 100; ++i) {
		$var($StringBuffer, sb, $new($StringBuffer, "test1"_s));
		$var($CharSequence, cs, static_cast<$CharSequence*>($new($StringBuffer, "test2"_s)));
		int32_t index = 0;
		while (index <= sb->length()) {
			index = $nc(AppendCharSequence::generator)->nextInt(100) - 50;
			if (index < 0) {
				break;
			}
		}
		try {
			sb->insert(index, cs);
			$throwNew($RuntimeException, "Insert bounds checking failure"_s);
		} catch ($IndexOutOfBoundsException& e) {
		}
	}
	for (int32_t i = 0; i < 100; ++i) {
		$var($StringBuffer, sb, $new($StringBuffer, "test1"_s));
		$var($CharSequence, cs, static_cast<$CharSequence*>($new($StringBuffer, "test2"_s)));
		int32_t index1 = 0;
		while (index1 <= sb->length()) {
			index1 = $nc(AppendCharSequence::generator)->nextInt(100) - 50;
			if (index1 < 0) {
				break;
			}
		}
		int32_t index2 = 0;
		int32_t len = 0;
		while (index2 < sb->length() - len) {
			index2 = $nc(AppendCharSequence::generator)->nextInt(100) - 50;
			len = $nc(AppendCharSequence::generator)->nextInt(100) - 50;
			if (index2 < 0) {
				break;
			}
			if (len < 0) {
				break;
			}
		}
		try {
			sb->insert(index1, cs, index2, index2 + len);
			$throwNew($RuntimeException, "Insert bounds checking failure"_s);
		} catch ($IndexOutOfBoundsException& e) {
		}
	}
}

void AppendCharSequence::checkConstructor() {
	$init(AppendCharSequence);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < 100; ++i) {
		$var($StringBuffer, sb, generateTestBuffer(0, 100));
		$var($CharSequence, cs, static_cast<$CharSequence*>(sb));
		$var($StringBuffer, sb2, $new($StringBuffer, cs));
		if (!$nc($($nc(sb)->toString()))->equals($(sb2->toString()))) {
			$throwNew($RuntimeException, "CharSequence constructor failure"_s);
		}
	}
	checkNegativeLenCharSeq(-1);
	checkNegativeLenCharSeq(-16);
	checkNegativeLenCharSeq(-17);
	checkNegativeLenCharSeq($Integer::MIN_VALUE);
}

void AppendCharSequence::checkNegativeLenCharSeq(int32_t len) {
	$init(AppendCharSequence);
	$useLocalCurrentObjectStackCache();
	try {
		$var($CharSequence, seq, $new($AppendCharSequence$MyNegativeLenCharSeq, len));
		$var($StringBuffer, sb, $new($StringBuffer, seq));
	} catch ($NegativeArraySizeException& expected) {
	} catch ($Throwable& exc) {
		$throwNew($RuntimeException, $$str({"Unexpected: "_s, exc}), exc);
	}
}

void clinit$AppendCharSequence($Class* class$) {
	$assignStatic(AppendCharSequence::generator, $new($Random));
}

AppendCharSequence::AppendCharSequence() {
}

$Class* AppendCharSequence::load$($String* name, bool initialize) {
	$loadClass(AppendCharSequence, name, initialize, &_AppendCharSequence_ClassInfo_, clinit$AppendCharSequence, allocate$AppendCharSequence);
	return class$;
}

$Class* AppendCharSequence::class$ = nullptr;