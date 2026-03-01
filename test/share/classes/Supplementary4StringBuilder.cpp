#include <Supplementary4StringBuilder.h>

#include <java/lang/CharSequence.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/StringIndexOutOfBoundsException.h>
#include <jcpp.h>

#undef MAX_CODE_POINT
#undef MIN_SUPPLEMENTARY_CODE_POINT

using $intArray2 = $Array<int32_t, 2>;
using $StringArray2 = $Array<::java::lang::String, 2>;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $StringIndexOutOfBoundsException = ::java::lang::StringIndexOutOfBoundsException;

$FieldInfo _Supplementary4StringBuilder_FieldInfo_[] = {
	{"input", "[Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Supplementary4StringBuilder, input)},
	{"golden1", "[[I", nullptr, $STATIC | $FINAL, $staticField(Supplementary4StringBuilder, golden1)},
	{"golden2", "[[I", nullptr, $STATIC | $FINAL, $staticField(Supplementary4StringBuilder, golden2)},
	{"golden3", "[Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Supplementary4StringBuilder, golden3)},
	{"testdata1", "[[Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Supplementary4StringBuilder, testdata1)},
	{"At", "Z", nullptr, $STATIC | $FINAL, $constField(Supplementary4StringBuilder, At)},
	{"Before", "Z", nullptr, $STATIC | $FINAL, $constField(Supplementary4StringBuilder, Before)},
	{}
};

$MethodInfo _Supplementary4StringBuilder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Supplementary4StringBuilder, init$, void)},
	{"check", "(ZLjava/lang/String;)V", nullptr, $STATIC, $staticMethod(Supplementary4StringBuilder, check, void, bool, $String*)},
	{"check", "(ZLjava/lang/String;II)V", nullptr, $STATIC, $staticMethod(Supplementary4StringBuilder, check, void, bool, $String*, int32_t, int32_t)},
	{"check", "(ZLjava/lang/String;Ljava/lang/StringBuilder;Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(Supplementary4StringBuilder, check, void, bool, $String*, $StringBuilder*, $String*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Supplementary4StringBuilder, main, void, $StringArray*)},
	{"test1", "()V", nullptr, $STATIC, $staticMethod(Supplementary4StringBuilder, test1, void)},
	{"test2", "()V", nullptr, $STATIC, $staticMethod(Supplementary4StringBuilder, test2, void)},
	{"test3", "()V", nullptr, $STATIC, $staticMethod(Supplementary4StringBuilder, test3, void)},
	{"test4", "()V", nullptr, $STATIC, $staticMethod(Supplementary4StringBuilder, test4, void)},
	{"test5", "()V", nullptr, $STATIC, $staticMethod(Supplementary4StringBuilder, test5, void)},
	{"test6", "()V", nullptr, $STATIC, $staticMethod(Supplementary4StringBuilder, test6, void)},
	{"testAppendCodePoint", "(ILjava/lang/Class;)V", nullptr, $STATIC, $staticMethod(Supplementary4StringBuilder, testAppendCodePoint, void, int32_t, $Class*)},
	{"testCodePoint", "(ZLjava/lang/StringBuilder;II)V", nullptr, $STATIC, $staticMethod(Supplementary4StringBuilder, testCodePoint, void, bool, $StringBuilder*, int32_t, int32_t)},
	{"testCodePoint", "(ZLjava/lang/StringBuilder;I)V", nullptr, $STATIC, $staticMethod(Supplementary4StringBuilder, testCodePoint, void, bool, $StringBuilder*, int32_t)},
	{"testCodePointCount", "(Ljava/lang/StringBuilder;IILjava/lang/Class;)V", nullptr, $STATIC, $staticMethod(Supplementary4StringBuilder, testCodePointCount, void, $StringBuilder*, int32_t, int32_t, $Class*)},
	{"testDontReadOutOfBoundsTrailingSurrogate", "()V", nullptr, $STATIC, $staticMethod(Supplementary4StringBuilder, testDontReadOutOfBoundsTrailingSurrogate, void)},
	{"testOffsetByCodePoints", "(Ljava/lang/StringBuilder;IILjava/lang/Class;)V", nullptr, $STATIC, $staticMethod(Supplementary4StringBuilder, testOffsetByCodePoints, void, $StringBuilder*, int32_t, int32_t, $Class*)},
	{"toHexString", "(I)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Supplementary4StringBuilder, toHexString, $String*, int32_t)},
	{"toHexString", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Supplementary4StringBuilder, toHexString, $String*, $String*)},
	{}
};

$ClassInfo _Supplementary4StringBuilder_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Supplementary4StringBuilder",
	"java.lang.Object",
	nullptr,
	_Supplementary4StringBuilder_FieldInfo_,
	_Supplementary4StringBuilder_MethodInfo_
};

$Object* allocate$Supplementary4StringBuilder($Class* clazz) {
	return $of($alloc(Supplementary4StringBuilder));
}

$StringArray* Supplementary4StringBuilder::input = nullptr;
$intArray2* Supplementary4StringBuilder::golden1 = nullptr;
$intArray2* Supplementary4StringBuilder::golden2 = nullptr;
$StringArray* Supplementary4StringBuilder::golden3 = nullptr;
$StringArray2* Supplementary4StringBuilder::testdata1 = nullptr;

void Supplementary4StringBuilder::init$() {
}

void Supplementary4StringBuilder::main($StringArray* args) {
	$init(Supplementary4StringBuilder);
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	testDontReadOutOfBoundsTrailingSurrogate();
}

void Supplementary4StringBuilder::test1() {
	$init(Supplementary4StringBuilder);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < $nc(Supplementary4StringBuilder::input)->length; ++i) {
		$var($StringBuilder, sb, $new($StringBuilder, $nc(Supplementary4StringBuilder::input)->get(i)));
		testCodePoint(Supplementary4StringBuilder::At, sb, 0, $nc($nc(Supplementary4StringBuilder::golden1)->get(0))->get(i));
		testCodePoint(Supplementary4StringBuilder::At, sb, 9, $nc($nc(Supplementary4StringBuilder::golden1)->get(1))->get(i));
		testCodePoint(Supplementary4StringBuilder::At, sb, sb->length() - 1, $nc($nc(Supplementary4StringBuilder::golden1)->get(2))->get(i));
		testCodePoint(Supplementary4StringBuilder::At, sb, -1);
		testCodePoint(Supplementary4StringBuilder::At, sb, sb->length());
	}
}

void Supplementary4StringBuilder::test2() {
	$init(Supplementary4StringBuilder);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < $nc(Supplementary4StringBuilder::input)->length; ++i) {
		$var($StringBuilder, sb, $new($StringBuilder, $nc(Supplementary4StringBuilder::input)->get(i)));
		testCodePoint(Supplementary4StringBuilder::Before, sb, 1, $nc($nc(Supplementary4StringBuilder::golden2)->get(0))->get(i));
		testCodePoint(Supplementary4StringBuilder::Before, sb, 13, $nc($nc(Supplementary4StringBuilder::golden2)->get(1))->get(i));
		testCodePoint(Supplementary4StringBuilder::Before, sb, sb->length(), $nc($nc(Supplementary4StringBuilder::golden2)->get(2))->get(i));
		testCodePoint(Supplementary4StringBuilder::Before, sb, 0);
		testCodePoint(Supplementary4StringBuilder::Before, sb, sb->length() + 1);
	}
}

void Supplementary4StringBuilder::test3() {
	$init(Supplementary4StringBuilder);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < $nc(Supplementary4StringBuilder::input)->length; ++i) {
		$var($StringBuilder, sb, $$new($StringBuilder, $nc(Supplementary4StringBuilder::input)->get(i))->reverse());
		bool var$0 = !$nc($nc(Supplementary4StringBuilder::golden3)->get(i))->equals($($nc(sb)->toString()));
		check(var$0, $$str({"reverse() for <"_s, $(toHexString($nc(Supplementary4StringBuilder::input)->get(i))), ">"_s}), sb, $nc(Supplementary4StringBuilder::golden3)->get(i));
	}
	for (int32_t i = 0; i < $nc(Supplementary4StringBuilder::testdata1)->length; ++i) {
		$var($StringBuilder, sb, $$new($StringBuilder, $nc($nc(Supplementary4StringBuilder::testdata1)->get(i))->get(0))->reverse());
		bool var$1 = !$nc($nc($nc(Supplementary4StringBuilder::testdata1)->get(i))->get(1))->equals($($nc(sb)->toString()));
		check(var$1, $$str({"reverse() for <"_s, $(toHexString($nc($nc(Supplementary4StringBuilder::testdata1)->get(i))->get(0))), ">"_s}), sb, $nc($nc(Supplementary4StringBuilder::testdata1)->get(i))->get(1));
	}
}

void Supplementary4StringBuilder::test4() {
	$init(Supplementary4StringBuilder);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < $nc(Supplementary4StringBuilder::input)->length; ++i) {
		$var($String, s, $nc(Supplementary4StringBuilder::input)->get(i));
		$var($StringBuilder, sb, $new($StringBuilder));
		int32_t c = 0;
		for (int32_t j = 0; j < $nc(s)->length(); j += $Character::charCount(c)) {
			c = s->codePointAt(j);
			$var($StringBuilder, rsb, sb->appendCodePoint(c));
			check(sb != rsb, "appendCodePoint returned a wrong object"_s);
			int32_t sbc = sb->codePointAt(j);
			check(sbc != c, $$str({"appendCodePoint("_s, $$str(j), ") != c"_s}), sbc, c);
		}
		check(!$nc(s)->equals($(sb->toString())), $$str({"appendCodePoint() produced a wrong result with input["_s, $$str(i), "]"_s}));
	}
	$load($IllegalArgumentException);
	testAppendCodePoint(-1, $IllegalArgumentException::class$);
	testAppendCodePoint($Character::MAX_CODE_POINT + 1, $IllegalArgumentException::class$);
}

void Supplementary4StringBuilder::test5() {
	$init(Supplementary4StringBuilder);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < $nc(Supplementary4StringBuilder::input)->length; ++i) {
		$var($String, s, $nc(Supplementary4StringBuilder::input)->get(i));
		$var($StringBuilder, sb, $new($StringBuilder, s));
		int32_t length = sb->length();
		for (int32_t j = 0; j <= length; ++j) {
			int32_t result = sb->codePointCount(j, length);
			int32_t expected = $Character::codePointCount(static_cast<$CharSequence*>(sb), j, length);
			check(result != expected, $$str({"codePointCount(input["_s, $$str(i), "], "_s, $$str(j), ", "_s, $$str(length), ")"_s}), result, expected);
		}
		for (int32_t j = length; j >= 0; --j) {
			int32_t result = sb->codePointCount(0, j);
			int32_t expected = $Character::codePointCount(static_cast<$CharSequence*>(sb), 0, j);
			check(result != expected, $$str({"codePointCount(input["_s, $$str(i), "], 0, "_s, $$str(j), ")"_s}), result, expected);
		}
		$load($NullPointerException);
		testCodePointCount(nullptr, 0, 0, $NullPointerException::class$);
		$load($IndexOutOfBoundsException);
		testCodePointCount(sb, -1, length, $IndexOutOfBoundsException::class$);
		testCodePointCount(sb, 0, length + 1, $IndexOutOfBoundsException::class$);
		testCodePointCount(sb, length, length - 1, $IndexOutOfBoundsException::class$);
	}
}

void Supplementary4StringBuilder::test6() {
	$init(Supplementary4StringBuilder);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < $nc(Supplementary4StringBuilder::input)->length; ++i) {
		$var($String, s, $nc(Supplementary4StringBuilder::input)->get(i));
		$var($StringBuilder, sb, $new($StringBuilder, s));
		int32_t length = $nc(s)->length();
		for (int32_t j = 0; j <= length; ++j) {
			int32_t nCodePoints = $Character::codePointCount(static_cast<$CharSequence*>(sb), j, length);
			int32_t result = sb->offsetByCodePoints(j, nCodePoints);
			check(result != length, $$str({"offsetByCodePoints(input["_s, $$str(i), "], "_s, $$str(j), ", "_s, $$str(nCodePoints), ")"_s}), result, length);
			result = sb->offsetByCodePoints(length, -nCodePoints);
			int32_t expected = j;
			if (j > 0 && j < length) {
				int32_t cp = sb->codePointBefore(j + 1);
				if ($Character::isSupplementaryCodePoint(cp)) {
					--expected;
				}
			}
			check(result != expected, $$str({"offsetByCodePoints(input["_s, $$str(i), "], "_s, $$str(j), ", "_s, $$str((-nCodePoints)), ")"_s}), result, expected);
		}
		for (int32_t j = length; j >= 0; --j) {
			int32_t nCodePoints = $Character::codePointCount(static_cast<$CharSequence*>(sb), 0, j);
			int32_t result = sb->offsetByCodePoints(0, nCodePoints);
			int32_t expected = j;
			if (j > 0 && j < length) {
				int32_t cp = sb->codePointAt(j - 1);
				if ($Character::isSupplementaryCodePoint(cp)) {
					++expected;
				}
			}
			check(result != expected, $$str({"offsetByCodePoints(input["_s, $$str(i), "], 0, "_s, $$str(nCodePoints), ")"_s}), result, expected);
			result = sb->offsetByCodePoints(j, -nCodePoints);
			check(result != 0, $$str({"offsetBycodePoints(input["_s, $$str(i), "], "_s, $$str(j), ", "_s, $$str((-nCodePoints)), ")"_s}), result, 0);
		}
		$load($NullPointerException);
		testOffsetByCodePoints(nullptr, 0, 0, $NullPointerException::class$);
		$load($IndexOutOfBoundsException);
		testOffsetByCodePoints(sb, -1, length, $IndexOutOfBoundsException::class$);
		testOffsetByCodePoints(sb, 0, length + 1, $IndexOutOfBoundsException::class$);
		testOffsetByCodePoints(sb, 1, -2, $IndexOutOfBoundsException::class$);
		testOffsetByCodePoints(sb, length, length - 1, $IndexOutOfBoundsException::class$);
		testOffsetByCodePoints(sb, length, -(length + 1), $IndexOutOfBoundsException::class$);
	}
}

void Supplementary4StringBuilder::testDontReadOutOfBoundsTrailingSurrogate() {
	$init(Supplementary4StringBuilder);
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	int32_t suppl = $Character::MIN_SUPPLEMENTARY_CODE_POINT;
	sb->appendCodePoint(suppl);
	bool var$0 = sb->codePointAt(0) != suppl;
	$var($String, var$1, "codePointAt(0)"_s);
	check(var$0, var$1, sb->codePointAt(0), suppl);
	check(sb->length() != 2, "sb.length()"_s);
	sb->setLength(1);
	check(sb->length() != 1, "sb.length()"_s);
	int32_t var$3 = sb->codePointAt(0);
	bool var$2 = var$3 != $Character::highSurrogate(suppl);
	$var($String, var$4, "codePointAt(0)"_s);
	int32_t var$5 = sb->codePointAt(0);
	check(var$2, var$4, var$5, (int32_t)$Character::highSurrogate(suppl));
}

void Supplementary4StringBuilder::testCodePoint(bool isAt, $StringBuilder* sb, int32_t index, int32_t expected) {
	$init(Supplementary4StringBuilder);
	$useLocalCurrentObjectStackCache();
	int32_t c = isAt ? $nc(sb)->codePointAt(index) : sb->codePointBefore(index);
	check(c != expected, $$str({"codePoint"_s, (isAt ? "At"_s : "Before"_s), "("_s, $$str(index), ") for <"_s, sb, ">"_s}), c, expected);
}

void Supplementary4StringBuilder::testCodePoint(bool isAt, $StringBuilder* sb, int32_t index) {
	$init(Supplementary4StringBuilder);
	$useLocalCurrentObjectStackCache();
	bool exceptionOccurred = false;
	try {
		int32_t c = isAt ? $nc(sb)->codePointAt(index) : sb->codePointBefore(index);
	} catch ($StringIndexOutOfBoundsException& e) {
		exceptionOccurred = true;
	}
	check(!exceptionOccurred, $$str({"codePoint"_s, (isAt ? "At"_s : "Before"_s), "("_s, $$str(index), ") for <"_s, sb, "> should throw StringIndexOutOfBoundsPointerException."_s}));
}

void Supplementary4StringBuilder::testAppendCodePoint(int32_t codePoint, $Class* expectedException) {
	$init(Supplementary4StringBuilder);
	$useLocalCurrentObjectStackCache();
	try {
		$$new($StringBuilder)->appendCodePoint(codePoint);
	} catch ($Exception& e) {
		if ($nc(expectedException)->isInstance(e)) {
			return;
		}
		$throwNew($RuntimeException, "Error: Unexpected exception"_s, e);
	}
	$var($String, var$0, $$str({"appendCodePoint("_s, $(toHexString(codePoint)), ") didn\'t throw "_s}));
	check(true, $$concat(var$0, $($nc(expectedException)->getName())));
}

void Supplementary4StringBuilder::testCodePointCount($StringBuilder* sb, int32_t beginIndex, int32_t endIndex, $Class* expectedException) {
	$init(Supplementary4StringBuilder);
	$useLocalCurrentObjectStackCache();
	try {
		int32_t n = $nc(sb)->codePointCount(beginIndex, endIndex);
	} catch ($Exception& e) {
		if ($nc(expectedException)->isInstance(e)) {
			return;
		}
		$throwNew($RuntimeException, "Error: Unexpected exception"_s, e);
	}
	check(true, $$str({"codePointCount() didn\'t throw "_s, $($nc(expectedException)->getName())}));
}

void Supplementary4StringBuilder::testOffsetByCodePoints($StringBuilder* sb, int32_t index, int32_t offset, $Class* expectedException) {
	$init(Supplementary4StringBuilder);
	$useLocalCurrentObjectStackCache();
	try {
		int32_t n = $nc(sb)->offsetByCodePoints(index, offset);
	} catch ($Exception& e) {
		if ($nc(expectedException)->isInstance(e)) {
			return;
		}
		$throwNew($RuntimeException, "Error: Unexpected exception"_s, e);
	}
	check(true, $$str({"offsetByCodePoints() didn\'t throw "_s, $($nc(expectedException)->getName())}));
}

void Supplementary4StringBuilder::check(bool err, $String* msg) {
	$init(Supplementary4StringBuilder);
	if (err) {
		$throwNew($RuntimeException, $$str({"Error: "_s, msg}));
	}
}

void Supplementary4StringBuilder::check(bool err, $String* s, int32_t got, int32_t expected) {
	$init(Supplementary4StringBuilder);
	$useLocalCurrentObjectStackCache();
	if (err) {
		$var($String, var$0, $$str({"Error: "_s, s, " returned an unexpected value. got "_s, $(toHexString(got)), ", expected "_s}));
		$throwNew($RuntimeException, $$concat(var$0, $(toHexString(expected))));
	}
}

void Supplementary4StringBuilder::check(bool err, $String* s, $StringBuilder* got, $String* expected) {
	$init(Supplementary4StringBuilder);
	$useLocalCurrentObjectStackCache();
	if (err) {
		$var($String, var$1, $$str({"Error: "_s, s, " returned an unexpected value. got <"_s, $(toHexString($($nc(got)->toString()))), ">, expected <"_s}));
		$var($String, var$0, $$concat(var$1, $(toHexString(expected))));
		$throwNew($RuntimeException, $$concat(var$0, ">"_s));
	}
}

$String* Supplementary4StringBuilder::toHexString(int32_t c) {
	$init(Supplementary4StringBuilder);
	return $str({"0x"_s, $($Integer::toHexString(c))});
}

$String* Supplementary4StringBuilder::toHexString($String* s) {
	$init(Supplementary4StringBuilder);
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	for (int32_t i = 0; i < $nc(s)->length(); ++i) {
		char16_t c = s->charAt(i);
		sb->append(" 0x"_s);
		if (c < 16) {
			sb->append(u'0');
		}
		if (c < 256) {
			sb->append(u'0');
		}
		if (c < 4096) {
			sb->append(u'0');
		}
		sb->append($($Integer::toHexString(c)));
	}
	sb->append(u' ');
	return sb->toString();
}

void clinit$Supplementary4StringBuilder($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(Supplementary4StringBuilder::input, $new($StringArray, {
		$cstr({'a', 'b', 'c', 0x10000, 'd', 'e', 'f', 0xD800, 0xD800, 'a', 'b', 0x10000, 'c', 'd', 'e', 'f', 'a', 0xDC00, 'b', 'c', 'd', 'e', 'f'}),
		$cstr({0xD800, 'd', 'e', 'f', 'g', 0xD800, 'h', 'i', 'j', 0x10000, 'k', 'l', 'm', 0xDC00, 'n', 'o', 'p', 0xDC00, 0xD800, 'r', 't', 0xDC00}),
		$cstr({0xDC00, 'a', 'b', 'c', 'd', 0x10FFFF, 'e', 'f', 'g', 'h', 0x10000, '9', 'i', 'k', 0xDC00, 0xDC00, 'l', 'm', 0xDC00, 'n', 'o', 0xD800}),
		$cstr({0x10000, '!', '#', '$', 0xD800, '%', '&', 0x10000, ';', '+', 0xDC00, '<', '>', ';', '=', '^', 0xDC00, '\\', '@', 0x10000}),
		$cstr({0xE0200, 'a', 'b', 'c', 0xDE01, 0xDB40, 'd', 'e', 0xE0202, 'f', 0xE0203, 'g', 'h', 'i', 0xE0202})
	}));
	$assignStatic(Supplementary4StringBuilder::golden1, $new($intArray2, {
		$$new($ints, {
			(int32_t)u'a',
			0x0000D800,
			0x0000DC00,
			0x00010000,
			0x000E0200
		}),
		$$new($ints, {
			0x0000D800,
			0x00010000,
			(int32_t)u'g',
			0x0000DC00,
			0x000E0202
		}),
		$$new($ints, {
			(int32_t)u'f',
			0x0000DC00,
			0x0000D800,
			0x0000DC00,
			0x0000DE02
		})
	}));
	$assignStatic(Supplementary4StringBuilder::golden2, $new($intArray2, {
		$$new($ints, {
			(int32_t)u'a',
			0x0000D800,
			0x0000DC00,
			0x0000D800,
			0x0000DB40
		}),
		$$new($ints, {
			0x0000D800,
			(int32_t)u'l',
			0x00010000,
			0x0000DC00,
			0x0000DB40
		}),
		$$new($ints, {
			(int32_t)u'f',
			0x0000DC00,
			0x0000D800,
			0x00010000,
			0x000E0202
		})
	}));
	$assignStatic(Supplementary4StringBuilder::golden3, $new($StringArray, {
		$cstr({'f', 'e', 'd', 'c', 'b', 0xDC00, 'a', 'f', 'e', 'd', 'c', 0x10000, 'b', 'a', 0xD800, 0xD800, 'f', 'e', 'd', 0x10000, 'c', 'b', 'a'}),
		$cstr({0xDC00, 't', 'r', 0x10000, 'p', 'o', 'n', 0xDC00, 'm', 'l', 'k', 0x10000, 'j', 'i', 'h', 0xD800, 'g', 'f', 'e', 'd', 0xD800}),
		$cstr({0xD800, 'o', 'n', 0xDC00, 'm', 'l', 0xDC00, 0xDC00, 'k', 'i', '9', 0x10000, 'h', 'g', 'f', 'e', 0x10FFFF, 'd', 'c', 'b', 'a', 0xDC00}),
		$cstr({0x10000, '@', '\\', 0xDC00, '^', '=', ';', '>', '<', 0xDC00, '+', ';', 0x10000, '&', '%', 0xD800, '$', '#', '!', 0x10000}),
		$cstr({0xE0202, 'i', 'h', 'g', 0xE0203, 'f', 0xE0202, 'e', 'd', 0xE0201, 'c', 'b', 'a', 0xE0200})
	}));
	$assignStatic(Supplementary4StringBuilder::testdata1, $new($StringArray2, {
		$$new($StringArray, {
			$cstr({'a', 0x10000}),
			$cstr({0x10000, 'a'})
		}),
		$$new($StringArray, {
			$cstr({'a', 0xDC00, 0xD800}),
			$cstr({0x10000, 'a'})
		}),
		$$new($StringArray, {
			$cstr({0x10000, 'a'}),
			$cstr({'a', 0x10000})
		}),
		$$new($StringArray, {
			$cstr({0xDC00, 0xD800, 'a'}),
			$cstr({'a', 0x10000})
		}),
		$$new($StringArray, {
			$cstr({0xDC00, 0xD800, 0xD801}),
			$cstr({0xD801, 0x10000})
		}),
		$$new($StringArray, {
			$cstr({0xDC00, 0x10001}),
			$cstr({0x10001, 0xDC00})
		}),
		$$new($StringArray, {
			$cstr({0xD801, 0x10000}),
			$cstr({0x10000, 0xD801})
		}),
		$$new($StringArray, {
			$cstr({0x10001, 0xDC00}),
			$cstr({0xDC00, 0x10001})
		}),
		$$new($StringArray, {
			$cstr({0x10000, 0xDC01, 0xD801}),
			$cstr({0x10401, 0x10000})
		})
	}));
}

Supplementary4StringBuilder::Supplementary4StringBuilder() {
}

$Class* Supplementary4StringBuilder::load$($String* name, bool initialize) {
	$loadClass(Supplementary4StringBuilder, name, initialize, &_Supplementary4StringBuilder_ClassInfo_, clinit$Supplementary4StringBuilder, allocate$Supplementary4StringBuilder);
	return class$;
}

$Class* Supplementary4StringBuilder::class$ = nullptr;