#include <ToStringCache.h>

#include <java/lang/CharSequence.h>
#include <java/lang/StringBuffer.h>
#include <jcpp.h>

using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $Float = ::java::lang::Float;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $StringBuffer = ::java::lang::StringBuffer;

$MethodInfo _ToStringCache_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ToStringCache, init$, void)},
	{"checkEqual", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ToStringCache, checkEqual, void, $String*, $String*)},
	{"checkUnequal", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ToStringCache, checkUnequal, void, $String*, $String*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ToStringCache, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$ClassInfo _ToStringCache_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ToStringCache",
	"java.lang.Object",
	nullptr,
	nullptr,
	_ToStringCache_MethodInfo_
};

$Object* allocate$ToStringCache($Class* clazz) {
	return $of($alloc(ToStringCache));
}

void ToStringCache::init$() {
}

void ToStringCache::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($String, original, "The original String"_s);
	$var($StringBuffer, sb, $new($StringBuffer, original));
	$var($String, a, sb->toString());
	checkEqual(a, original);
	$var($String, b, sb->toString());
	checkEqual(a, b);
	sb->setLength(12);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->setCharAt(0, u'X');
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->append($of($$new($Character, u'X')));
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->append("More text"_s);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->append(sb);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->append(static_cast<$CharSequence*>($$new($StringBuilder, "Build"_s)));
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->append(static_cast<$CharSequence*>($$new($StringBuilder, "Build2"_s)), 0, 1);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->append($$new($chars, {
		u'a',
		u'b'
	}));
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->append(true);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->append(u'c');
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->append(23);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->appendCodePoint($Character::codePointAt($$new($chars, {u'X'}), 0));
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->append((int64_t)1);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->append(1.0f);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->append(1.0);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->delete$(0, 5);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->deleteCharAt(0);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->replace(0, 2, "123"_s);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->insert(0, $$new($chars, {
		u'a',
		u'b',
		u'c'
	}), 0, 3);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->insert(0, $$new($Object));
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->insert(0, "abc"_s);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->insert(0, $$new($chars, {
		u'a',
		u'b',
		u'c'
	}));
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->insert(0, static_cast<$CharSequence*>($$new($StringBuilder, "Build"_s)));
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->insert(0, static_cast<$CharSequence*>($$new($StringBuilder, "Build"_s)), 0, 1);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->insert(0, false);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->insert(0, u'X');
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->insert(0, 1);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->insert(0, (int64_t)1);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->insert(0, 1.0f);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->insert(0, 1.0);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->reverse();
	$assign(b, sb->toString());
	checkUnequal(a, b);
	sb->append(($String*)nullptr);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->append(($StringBuffer*)nullptr);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->append(($StringBuilder*)nullptr);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	sb->append(($CharSequence*)nullptr);
	$assign(b, sb->toString());
	checkUnequal(a, b);
	$assign(a, b);
	$assign(sb, $new($StringBuffer, original));
	$assign(a, sb->toString());
	$assign(b, sb->toString());
	checkEqual(a, b);
	int32_t l = sb->length();
	$assign(b, sb->toString());
	checkEqual(a, b);
	int32_t cap = sb->capacity();
	$assign(b, sb->toString());
	checkEqual(a, b);
	sb->ensureCapacity(100);
	$assign(b, sb->toString());
	checkEqual(a, b);
	sb->trimToSize();
	$assign(b, sb->toString());
	checkEqual(a, b);
	char16_t c = sb->charAt(1);
	$assign(b, sb->toString());
	checkEqual(a, b);
	int32_t cp = sb->codePointAt(1);
	$assign(b, sb->toString());
	checkEqual(a, b);
	cp = sb->codePointBefore(2);
	$assign(b, sb->toString());
	checkEqual(a, b);
	int32_t count = sb->codePointCount(0, 1);
	$assign(b, sb->toString());
	checkEqual(a, b);
	count = sb->offsetByCodePoints(0, 1);
	$assign(b, sb->toString());
	checkEqual(a, b);
	sb->getChars(0, 1, $$new($chars, 2), 0);
	$assign(b, sb->toString());
	checkEqual(a, b);
	$var($String, sub, sb->substring(0));
	$assign(b, sb->toString());
	checkEqual(a, b);
	$var($CharSequence, cs, sb->subSequence(0, 1));
	$assign(b, sb->toString());
	checkEqual(a, b);
	$assign(sub, sb->substring(0, 3));
	$assign(b, sb->toString());
	checkEqual(a, b);
	int32_t index = sb->indexOf("rig"_s);
	$assign(b, sb->toString());
	checkEqual(a, b);
	index = sb->indexOf("rig"_s, 2);
	$assign(b, sb->toString());
	checkEqual(a, b);
	index = sb->lastIndexOf("rig"_s);
	$assign(b, sb->toString());
	checkEqual(a, b);
	index = sb->lastIndexOf("rig"_s, 3);
	$assign(b, sb->toString());
	checkEqual(a, b);
}

void ToStringCache::checkEqual($String* s1, $String* s2) {
	if (!$nc(s1)->equals(s2)) {
		$throwNew($RuntimeException, $$str({"Unmatched strings: s1 = "_s, s1, " s2 = "_s, s2}));
	}
}

void ToStringCache::checkUnequal($String* s1, $String* s2) {
	if ($nc(s1)->equals(s2)) {
		$throwNew($RuntimeException, $$str({"Unexpected matched strings: "_s, s1}));
	}
}

ToStringCache::ToStringCache() {
}

$Class* ToStringCache::load$($String* name, bool initialize) {
	$loadClass(ToStringCache, name, initialize, &_ToStringCache_ClassInfo_, allocate$ToStringCache);
	return class$;
}

$Class* ToStringCache::class$ = nullptr;