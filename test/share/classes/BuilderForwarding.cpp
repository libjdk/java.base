#include <BuilderForwarding.h>

#include <java/lang/CharSequence.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/StringBuffer.h>
#include <java/lang/StringIndexOutOfBoundsException.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <jcpp.h>

#undef A_STRING_BUFFER_VAL
#undef A_STRING_BUILDER_VAL
#undef A_STRING_VAL
#undef NON_EMPTY_VAL

using $PrintStream = ::java::io::PrintStream;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $StringBuffer = ::java::lang::StringBuffer;
using $StringIndexOutOfBoundsException = ::java::lang::StringIndexOutOfBoundsException;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;

$FieldInfo _BuilderForwarding_FieldInfo_[] = {
	{"A_STRING_BUFFER_VAL", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BuilderForwarding, A_STRING_BUFFER_VAL)},
	{"A_STRING_BUILDER_VAL", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BuilderForwarding, A_STRING_BUILDER_VAL)},
	{"A_STRING_VAL", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BuilderForwarding, A_STRING_VAL)},
	{"NON_EMPTY_VAL", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BuilderForwarding, NON_EMPTY_VAL)},
	{}
};

$MethodInfo _BuilderForwarding_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(BuilderForwarding, init$, void)},
	{"appendCharSequence", "()V", nullptr, $PUBLIC, $virtualMethod(BuilderForwarding, appendCharSequence, void)},
	{"assertEquals", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(BuilderForwarding, assertEquals, void, $String*, $String*)},
	{"assertEquals", "(II)V", nullptr, $PUBLIC, $virtualMethod(BuilderForwarding, assertEquals, void, int32_t, int32_t)},
	{"executeTestMethods", "()V", nullptr, $PUBLIC, $virtualMethod(BuilderForwarding, executeTestMethods, void)},
	{"indexOfString", "()V", nullptr, $PUBLIC, $virtualMethod(BuilderForwarding, indexOfString, void)},
	{"indexOfStringIntNull", "()V", nullptr, $PUBLIC, $virtualMethod(BuilderForwarding, indexOfStringIntNull, void)},
	{"indexOfStringNull", "()V", nullptr, $PUBLIC, $virtualMethod(BuilderForwarding, indexOfStringNull, void)},
	{"indexOfStringint", "()V", nullptr, $PUBLIC, $virtualMethod(BuilderForwarding, indexOfStringint, void)},
	{"insertintCharSequence", "()V", nullptr, $PUBLIC, $virtualMethod(BuilderForwarding, insertintCharSequence, void)},
	{"insertintObject", "()V", nullptr, $PUBLIC, $virtualMethod(BuilderForwarding, insertintObject, void)},
	{"insertintboolean", "()V", nullptr, $PUBLIC, $virtualMethod(BuilderForwarding, insertintboolean, void)},
	{"insertintchar", "()V", nullptr, $PUBLIC, $virtualMethod(BuilderForwarding, insertintchar, void)},
	{"insertintdouble", "()V", nullptr, $PUBLIC, $virtualMethod(BuilderForwarding, insertintdouble, void)},
	{"insertintfloat", "()V", nullptr, $PUBLIC, $virtualMethod(BuilderForwarding, insertintfloat, void)},
	{"insertintint", "()V", nullptr, $PUBLIC, $virtualMethod(BuilderForwarding, insertintint, void)},
	{"insertintlong", "()V", nullptr, $PUBLIC, $virtualMethod(BuilderForwarding, insertintlong, void)},
	{"lastIndexOfString", "()V", nullptr, $PUBLIC, $virtualMethod(BuilderForwarding, lastIndexOfString, void)},
	{"lastIndexOfStringint", "()V", nullptr, $PUBLIC, $virtualMethod(BuilderForwarding, lastIndexOfStringint, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(BuilderForwarding, main, void, $StringArray*)},
	{}
};

$ClassInfo _BuilderForwarding_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"BuilderForwarding",
	"java.lang.Object",
	nullptr,
	_BuilderForwarding_FieldInfo_,
	_BuilderForwarding_MethodInfo_
};

$Object* allocate$BuilderForwarding($Class* clazz) {
	return $of($alloc(BuilderForwarding));
}

$String* BuilderForwarding::A_STRING_BUFFER_VAL = nullptr;
$String* BuilderForwarding::A_STRING_BUILDER_VAL = nullptr;
$String* BuilderForwarding::A_STRING_VAL = nullptr;
$String* BuilderForwarding::NON_EMPTY_VAL = nullptr;

void BuilderForwarding::init$() {
	$nc($System::out)->println("Starting BuilderForwarding"_s);
}

void BuilderForwarding::main($StringArray* args) {
	$init(BuilderForwarding);
	$$new(BuilderForwarding)->executeTestMethods();
}

void BuilderForwarding::executeTestMethods() {
	appendCharSequence();
	indexOfString();
	indexOfStringIntNull();
	indexOfStringNull();
	indexOfStringint();
	insertintCharSequence();
	insertintObject();
	insertintboolean();
	insertintchar();
	insertintdouble();
	insertintfloat();
	insertintint();
	insertintlong();
	lastIndexOfString();
	lastIndexOfStringint();
}

void BuilderForwarding::appendCharSequence() {
	$useLocalCurrentObjectStackCache();
	$var($CharSequence, aString, BuilderForwarding::A_STRING_VAL);
	$var($CharSequence, aStringBuilder, $new($StringBuilder, BuilderForwarding::A_STRING_BUILDER_VAL));
	$var($CharSequence, aStringBuffer, $new($StringBuffer, BuilderForwarding::A_STRING_BUFFER_VAL));
	assertEquals($($$new($StringBuilder)->append(aString)->toString()), BuilderForwarding::A_STRING_VAL);
	assertEquals($($$new($StringBuilder)->append(aStringBuilder)->toString()), BuilderForwarding::A_STRING_BUILDER_VAL);
	assertEquals($($$new($StringBuilder)->append(aStringBuffer)->toString()), BuilderForwarding::A_STRING_BUFFER_VAL);
	assertEquals($($$new($StringBuilder, BuilderForwarding::NON_EMPTY_VAL)->append(aString)->toString()), $$str({BuilderForwarding::NON_EMPTY_VAL, BuilderForwarding::A_STRING_VAL}));
	assertEquals($($$new($StringBuilder, BuilderForwarding::NON_EMPTY_VAL)->append(aStringBuilder)->toString()), $$str({BuilderForwarding::NON_EMPTY_VAL, BuilderForwarding::A_STRING_BUILDER_VAL}));
	assertEquals($($$new($StringBuilder, BuilderForwarding::NON_EMPTY_VAL)->append(aStringBuffer)->toString()), $$str({BuilderForwarding::NON_EMPTY_VAL, BuilderForwarding::A_STRING_BUFFER_VAL}));
}

void BuilderForwarding::indexOfString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	try {
		sb->indexOf(nullptr);
		$throwNew($RuntimeException, "Test failed: should have thrown NPE"_s);
	} catch ($NullPointerException& npe) {
	} catch ($Throwable& t) {
		$throwNew($RuntimeException, $$str({"Test failed: should have thrown NPE. Instead threw "_s, t}));
	}
	$assign(sb, $new($StringBuilder, "xyz"_s));
	assertEquals(sb->indexOf("y"_s), 1);
	assertEquals(sb->indexOf("not found"_s), -1);
}

void BuilderForwarding::indexOfStringint() {
	$var($StringBuilder, sb, $new($StringBuilder));
	try {
		sb->indexOf(nullptr, 1);
		$throwNew($RuntimeException, "Test failed: should have thrown NPE"_s);
	} catch ($NullPointerException& npe) {
	} catch ($Throwable& t) {
		$throwNew($RuntimeException, "Test failed: should have thrown NPE"_s);
	}
	$assign(sb, $new($StringBuilder, "xyyz"_s));
	assertEquals(sb->indexOf("y"_s, 0), 1);
	assertEquals(sb->indexOf("y"_s, 1), 1);
	assertEquals(sb->indexOf("y"_s, 2), 2);
	assertEquals(sb->indexOf("not found"_s), -1);
}

void BuilderForwarding::indexOfStringIntNull() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuffer, sb, $new($StringBuffer));
	try {
		sb->indexOf(nullptr, 1);
		$throwNew($RuntimeException, "Test failed: should have thrown NPE"_s);
	} catch ($NullPointerException& npe) {
	} catch ($Throwable& t) {
		$throwNew($RuntimeException, $$str({"Test failed: should have thrown NPE. Instead threw "_s, t}));
	}
}

void BuilderForwarding::indexOfStringNull() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	try {
		sb->indexOf(nullptr);
		$throwNew($RuntimeException, "Test failed: should have thrown NPE"_s);
	} catch ($NullPointerException& npe) {
	} catch ($Throwable& t) {
		$throwNew($RuntimeException, $$str({"Test failed: should have thrown NPE. Instead threw "_s, t}));
	}
}

void BuilderForwarding::insertintboolean() {
	$useLocalCurrentObjectStackCache();
	bool b = true;
	$var($StringBuilder, sb, $new($StringBuilder, "012345"_s));
	assertEquals($($nc(sb->insert(2, b))->toString()), "01true2345"_s);
}

void BuilderForwarding::insertintchar() {
	$useLocalCurrentObjectStackCache();
	char16_t c = u'C';
	$var($StringBuilder, sb, $new($StringBuilder, "012345"_s));
	assertEquals($($nc(sb->insert(2, c))->toString()), "01C2345"_s);
}

void BuilderForwarding::insertintCharSequence() {
	$useLocalCurrentObjectStackCache();
	$var($String, initString, "012345"_s);
	$var($CharSequence, aString, BuilderForwarding::A_STRING_VAL);
	$var($CharSequence, aStringBuilder, $new($StringBuilder, BuilderForwarding::A_STRING_BUILDER_VAL));
	$var($CharSequence, aStringBuffer, $new($StringBuffer, BuilderForwarding::A_STRING_BUFFER_VAL));
	assertEquals($($nc($$new($StringBuilder, initString)->insert(2, aString))->toString()), $$str({"01"_s, BuilderForwarding::A_STRING_VAL, "2345"_s}));
	assertEquals($($nc($$new($StringBuilder, initString)->insert(2, aStringBuilder))->toString()), $$str({"01"_s, BuilderForwarding::A_STRING_BUILDER_VAL, "2345"_s}));
	assertEquals($($nc($$new($StringBuilder, initString)->insert(2, aStringBuffer))->toString()), $$str({"01"_s, BuilderForwarding::A_STRING_BUFFER_VAL, "2345"_s}));
	try {
		$$new($StringBuilder, initString)->insert(7, aString);
		$throwNew($RuntimeException, "Test failed: should have thrown IndexOutOfBoundsException"_s);
	} catch ($IndexOutOfBoundsException& soob) {
	} catch ($Throwable& t) {
		$throwNew($RuntimeException, $$str({"Test failed: should have thrown IndexOutOfBoundsException, but instead threw "_s, $(t->getMessage())}));
	}
}

void BuilderForwarding::insertintdouble() {
	$useLocalCurrentObjectStackCache();
	double d = 99.0;
	$var($StringBuilder, sb, $new($StringBuilder, "012345"_s));
	assertEquals($($nc(sb->insert(2, d))->toString()), "0199.02345"_s);
}

void BuilderForwarding::insertintfloat() {
	$useLocalCurrentObjectStackCache();
	float f = 99.0f;
	$var($StringBuilder, sb, $new($StringBuilder, "012345"_s));
	assertEquals($($nc(sb->insert(2, f))->toString()), "0199.02345"_s);
}

void BuilderForwarding::insertintint() {
	$useLocalCurrentObjectStackCache();
	int32_t i = 99;
	$var($StringBuilder, sb, $new($StringBuilder, "012345"_s));
	assertEquals($($nc(sb->insert(2, i))->toString()), "01992345"_s);
}

void BuilderForwarding::insertintlong() {
	$useLocalCurrentObjectStackCache();
	int64_t l = 99;
	$var($StringBuilder, sb, $new($StringBuilder, "012345"_s));
	assertEquals($($nc(sb->insert(2, l))->toString()), "01992345"_s);
}

void BuilderForwarding::insertintObject() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder, "012345"_s));
	$var($List, ls, $new($ArrayList));
	ls->add("A"_s);
	ls->add("B"_s);
	$var($String, lsString, $of(ls)->toString());
	assertEquals($($nc(sb->insert(2, $of(ls)))->toString()), $$str({"01"_s, lsString, "2345"_s}));
	try {
		sb->insert(sb->length() + 1, $of(ls));
		$throwNew($RuntimeException, "Test failed: should have thrown StringIndexOutOfBoundsException"_s);
	} catch ($StringIndexOutOfBoundsException& soob) {
	} catch ($Throwable& t) {
		$throwNew($RuntimeException, $$str({"Test failed: should have thrown StringIndexOutOfBoundsException, but instead threw:"_s, t}));
	}
}

void BuilderForwarding::lastIndexOfString() {
	$useLocalCurrentObjectStackCache();
	$var($String, xyz, "xyz"_s);
	$var($String, xyz3, "xyzxyzxyz"_s);
	$var($StringBuilder, sb, $new($StringBuilder, xyz3));
	int32_t pos = sb->lastIndexOf("xyz"_s);
	assertEquals(pos, 2 * xyz->length());
}

void BuilderForwarding::lastIndexOfStringint() {
	$var($StringBuilder, sb, $new($StringBuilder, "xyzxyzxyz"_s));
	int32_t pos = sb->lastIndexOf("xyz"_s, 5);
	assertEquals(pos, 3);
	pos = sb->lastIndexOf("xyz"_s, 6);
	assertEquals(pos, 6);
}

void BuilderForwarding::assertEquals($String* actual, $String* expected) {
	if (!$nc(actual)->equals(expected)) {
		$throwNew($RuntimeException, $$str({"Test failed: actual = \'"_s, actual, "\', expected = \'"_s, expected, "\'"_s}));
	}
}

void BuilderForwarding::assertEquals(int32_t actual, int32_t expected) {
	$useLocalCurrentObjectStackCache();
	if (actual != expected) {
		$throwNew($RuntimeException, $$str({"Test failed: actual = \'"_s, $$str(actual), "\', expected = \'"_s, $$str(expected), "\'"_s}));
	}
}

BuilderForwarding::BuilderForwarding() {
}

void clinit$BuilderForwarding($Class* class$) {
	$assignStatic(BuilderForwarding::A_STRING_BUFFER_VAL, "aStringBuffer"_s);
	$assignStatic(BuilderForwarding::A_STRING_BUILDER_VAL, "aStringBuilder"_s);
	$assignStatic(BuilderForwarding::A_STRING_VAL, "aString"_s);
	$assignStatic(BuilderForwarding::NON_EMPTY_VAL, "NonEmpty"_s);
}

$Class* BuilderForwarding::load$($String* name, bool initialize) {
	$loadClass(BuilderForwarding, name, initialize, &_BuilderForwarding_ClassInfo_, clinit$BuilderForwarding, allocate$BuilderForwarding);
	return class$;
}

$Class* BuilderForwarding::class$ = nullptr;