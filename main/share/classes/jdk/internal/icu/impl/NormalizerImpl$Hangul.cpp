#include <jdk/internal/icu/impl/NormalizerImpl$Hangul.h>

#include <java/io/IOException.h>
#include <java/lang/Appendable.h>
#include <java/lang/InternalError.h>
#include <jdk/internal/icu/impl/NormalizerImpl.h>
#include <jcpp.h>

#undef HANGUL_BASE
#undef HANGUL_COUNT
#undef HANGUL_END
#undef HANGUL_LIMIT
#undef JAMO_L_BASE
#undef JAMO_L_COUNT
#undef JAMO_T_BASE
#undef JAMO_T_COUNT
#undef JAMO_V_BASE
#undef JAMO_V_COUNT

using $IOException = ::java::io::IOException;
using $Appendable = ::java::lang::Appendable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;

namespace jdk {
	namespace internal {
		namespace icu {
			namespace impl {

$FieldInfo _NormalizerImpl$Hangul_FieldInfo_[] = {
	{"JAMO_L_BASE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl$Hangul, JAMO_L_BASE)},
	{"JAMO_V_BASE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl$Hangul, JAMO_V_BASE)},
	{"JAMO_T_BASE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl$Hangul, JAMO_T_BASE)},
	{"HANGUL_BASE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl$Hangul, HANGUL_BASE)},
	{"HANGUL_END", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl$Hangul, HANGUL_END)},
	{"JAMO_L_COUNT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl$Hangul, JAMO_L_COUNT)},
	{"JAMO_V_COUNT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl$Hangul, JAMO_V_COUNT)},
	{"JAMO_T_COUNT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl$Hangul, JAMO_T_COUNT)},
	{"HANGUL_COUNT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl$Hangul, HANGUL_COUNT)},
	{"HANGUL_LIMIT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl$Hangul, HANGUL_LIMIT)},
	{}
};

$MethodInfo _NormalizerImpl$Hangul_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(NormalizerImpl$Hangul, init$, void)},
	{"decompose", "(ILjava/lang/Appendable;)I", nullptr, $PUBLIC | $STATIC, $staticMethod(NormalizerImpl$Hangul, decompose, int32_t, int32_t, $Appendable*)},
	{"isHangul", "(I)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(NormalizerImpl$Hangul, isHangul, bool, int32_t)},
	{"isHangulLV", "(I)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(NormalizerImpl$Hangul, isHangulLV, bool, int32_t)},
	{}
};

$InnerClassInfo _NormalizerImpl$Hangul_InnerClassesInfo_[] = {
	{"jdk.internal.icu.impl.NormalizerImpl$Hangul", "jdk.internal.icu.impl.NormalizerImpl", "Hangul", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _NormalizerImpl$Hangul_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.icu.impl.NormalizerImpl$Hangul",
	"java.lang.Object",
	nullptr,
	_NormalizerImpl$Hangul_FieldInfo_,
	_NormalizerImpl$Hangul_MethodInfo_,
	nullptr,
	nullptr,
	_NormalizerImpl$Hangul_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.icu.impl.NormalizerImpl"
};

$Object* allocate$NormalizerImpl$Hangul($Class* clazz) {
	return $of($alloc(NormalizerImpl$Hangul));
}

void NormalizerImpl$Hangul::init$() {
}

bool NormalizerImpl$Hangul::isHangul(int32_t c) {
	return NormalizerImpl$Hangul::HANGUL_BASE <= c && c < NormalizerImpl$Hangul::HANGUL_LIMIT;
}

bool NormalizerImpl$Hangul::isHangulLV(int32_t c) {
	c -= NormalizerImpl$Hangul::HANGUL_BASE;
	return 0 <= c && c < NormalizerImpl$Hangul::HANGUL_COUNT && $mod(c, NormalizerImpl$Hangul::JAMO_T_COUNT) == 0;
}

int32_t NormalizerImpl$Hangul::decompose(int32_t c, $Appendable* buffer) {
	try {
		c -= NormalizerImpl$Hangul::HANGUL_BASE;
		int32_t c2 = $mod(c, NormalizerImpl$Hangul::JAMO_T_COUNT);
		c /= NormalizerImpl$Hangul::JAMO_T_COUNT;
		$nc(buffer)->append((char16_t)(NormalizerImpl$Hangul::JAMO_L_BASE + $div(c, NormalizerImpl$Hangul::JAMO_V_COUNT)));
		buffer->append((char16_t)(NormalizerImpl$Hangul::JAMO_V_BASE + $mod(c, NormalizerImpl$Hangul::JAMO_V_COUNT)));
		if (c2 == 0) {
			return 2;
		} else {
			buffer->append((char16_t)(NormalizerImpl$Hangul::JAMO_T_BASE + c2));
			return 3;
		}
	} catch ($IOException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

NormalizerImpl$Hangul::NormalizerImpl$Hangul() {
}

$Class* NormalizerImpl$Hangul::load$($String* name, bool initialize) {
	$loadClass(NormalizerImpl$Hangul, name, initialize, &_NormalizerImpl$Hangul_ClassInfo_, allocate$NormalizerImpl$Hangul);
	return class$;
}

$Class* NormalizerImpl$Hangul::class$ = nullptr;

			} // impl
		} // icu
	} // internal
} // jdk