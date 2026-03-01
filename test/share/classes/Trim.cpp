#include <Trim.h>

#include <java/lang/CharSequence.h>
#include <java/lang/StringBuffer.h>
#include <java/util/Random.h>
#include <jcpp.h>

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $StringBuffer = ::java::lang::StringBuffer;
using $Random = ::java::util::Random;

$FieldInfo _Trim_FieldInfo_[] = {
	{"generator", "Ljava/util/Random;", nullptr, $PRIVATE | $STATIC, $staticField(Trim, generator)},
	{}
};

$MethodInfo _Trim_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Trim, init$, void)},
	{"bash", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Trim, bash, void), "java.lang.Exception"},
	{"capacityCheck", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Trim, capacityCheck, void)},
	{"generateTestBuffer", "(II)Ljava/lang/StringBuffer;", nullptr, $PRIVATE | $STATIC, $staticMethod(Trim, generateTestBuffer, $StringBuffer*, int32_t, int32_t)},
	{"getRandomIndex", "(II)I", nullptr, $PRIVATE | $STATIC, $staticMethod(Trim, getRandomIndex, int32_t, int32_t, int32_t)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Trim, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$ClassInfo _Trim_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Trim",
	"java.lang.Object",
	nullptr,
	_Trim_FieldInfo_,
	_Trim_MethodInfo_
};

$Object* allocate$Trim($Class* clazz) {
	return $of($alloc(Trim));
}

$Random* Trim::generator = nullptr;

void Trim::init$() {
}

void Trim::main($StringArray* args) {
	$init(Trim);
	bash();
}

void Trim::bash() {
	$init(Trim);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < 1000; ++i) {
		$var($StringBuffer, sb1, generateTestBuffer(0, 100));
		$var($StringBuffer, sb2, $new($StringBuffer, static_cast<$CharSequence*>(sb1)));
		$nc(sb1)->trimToSize();
		if (!$nc($(sb1->toString()))->equals($(sb2->toString()))) {
			$throwNew($RuntimeException, "trim mutated stringbuffer contents"_s);
		}
		$var($StringBuffer, sb3, generateTestBuffer(0, 100));
		sb1->append(sb3);
		sb2->append(sb3);
		if ($nc(Trim::generator)->nextInt(2) == 0) {
			sb1->trimToSize();
		} else {
			sb2->trimToSize();
		}
		if (!$nc($(sb1->toString()))->equals($(sb2->toString()))) {
			$throwNew($RuntimeException, "trim mutated stringbuffer contents"_s);
		}
		$assign(sb3, $new($StringBuffer, 100));
		sb3->append("a"_s);
		sb1->append(sb3);
		sb2->append(sb3);
		if ($nc(Trim::generator)->nextInt(2) == 0) {
			sb1->trimToSize();
		} else {
			sb2->trimToSize();
		}
		if (!$nc($(sb1->toString()))->equals($(sb2->toString()))) {
			$throwNew($RuntimeException, "trim mutated stringbuffer contents"_s);
		}
	}
}

void Trim::capacityCheck() {
	$init(Trim);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < 100; ++i) {
		int32_t sizeNeeded = $nc(Trim::generator)->nextInt(1000) + 1;
		int32_t sizeExtra = $nc(Trim::generator)->nextInt(100) + 1;
		$var($StringBuffer, sb, $new($StringBuffer, sizeNeeded + sizeExtra));
		$var($StringBuffer, sb2, generateTestBuffer(sizeNeeded, sizeNeeded));
		if ($nc(sb2)->length() != sizeNeeded) {
			$throwNew($RuntimeException, "sb generated incorrectly"_s);
		}
		sb->append(sb2);
		int32_t oldCapacity = sb->capacity();
		sb->trimToSize();
		int32_t newCapacity = sb->capacity();
		if (oldCapacity == newCapacity) {
			$throwNew($RuntimeException, "trim failed"_s);
		}
	}
}

int32_t Trim::getRandomIndex(int32_t constraint1, int32_t constraint2) {
	$init(Trim);
	int32_t range = constraint2 - constraint1;
	if (range <= 0) {
		return constraint1;
	}
	int32_t x = $nc(Trim::generator)->nextInt(range);
	return constraint1 + x;
}

$StringBuffer* Trim::generateTestBuffer(int32_t min, int32_t max) {
	$init(Trim);
	$var($StringBuffer, aNewStringBuffer, $new($StringBuffer));
	int32_t aNewLength = getRandomIndex(min, max);
	for (int32_t y = 0; y < aNewLength; ++y) {
		int32_t achar = $nc(Trim::generator)->nextInt(30) + 30;
		char16_t test = (char16_t)(achar);
		aNewStringBuffer->append(test);
	}
	return aNewStringBuffer;
}

void clinit$Trim($Class* class$) {
	$assignStatic(Trim::generator, $new($Random));
}

Trim::Trim() {
}

$Class* Trim::load$($String* name, bool initialize) {
	$loadClass(Trim, name, initialize, &_Trim_ClassInfo_, clinit$Trim, allocate$Trim);
	return class$;
}

$Class* Trim::class$ = nullptr;