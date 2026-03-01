#include <jdk/internal/icu/impl/Norm2AllModes$ComposeNormalizer2.h>

#include <java/lang/Appendable.h>
#include <java/lang/CharSequence.h>
#include <jdk/internal/icu/impl/Norm2AllModes$Normalizer2WithImpl.h>
#include <jdk/internal/icu/impl/Norm2AllModes.h>
#include <jdk/internal/icu/impl/NormalizerImpl$ReorderingBuffer.h>
#include <jdk/internal/icu/impl/NormalizerImpl.h>
#include <jcpp.h>

using $Appendable = ::java::lang::Appendable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Norm2AllModes$Normalizer2WithImpl = ::jdk::internal::icu::impl::Norm2AllModes$Normalizer2WithImpl;
using $NormalizerImpl = ::jdk::internal::icu::impl::NormalizerImpl;
using $NormalizerImpl$ReorderingBuffer = ::jdk::internal::icu::impl::NormalizerImpl$ReorderingBuffer;

namespace jdk {
	namespace internal {
		namespace icu {
			namespace impl {

$FieldInfo _Norm2AllModes$ComposeNormalizer2_FieldInfo_[] = {
	{"onlyContiguous", "Z", nullptr, $PRIVATE | $FINAL, $field(Norm2AllModes$ComposeNormalizer2, onlyContiguous)},
	{}
};

$MethodInfo _Norm2AllModes$ComposeNormalizer2_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/icu/impl/NormalizerImpl;Z)V", nullptr, $PUBLIC, $method(Norm2AllModes$ComposeNormalizer2, init$, void, $NormalizerImpl*, bool)},
	{"hasBoundaryBefore", "(I)Z", nullptr, $PUBLIC, $virtualMethod(Norm2AllModes$ComposeNormalizer2, hasBoundaryBefore, bool, int32_t)},
	{"isNormalized", "(Ljava/lang/CharSequence;)Z", nullptr, $PUBLIC, $virtualMethod(Norm2AllModes$ComposeNormalizer2, isNormalized, bool, $CharSequence*)},
	{"normalize", "(Ljava/lang/CharSequence;Ljdk/internal/icu/impl/NormalizerImpl$ReorderingBuffer;)V", nullptr, $PROTECTED, $virtualMethod(Norm2AllModes$ComposeNormalizer2, normalize, void, $CharSequence*, $NormalizerImpl$ReorderingBuffer*)},
	{"normalizeAndAppend", "(Ljava/lang/CharSequence;ZLjdk/internal/icu/impl/NormalizerImpl$ReorderingBuffer;)V", nullptr, $PROTECTED, $virtualMethod(Norm2AllModes$ComposeNormalizer2, normalizeAndAppend, void, $CharSequence*, bool, $NormalizerImpl$ReorderingBuffer*)},
	{"spanQuickCheckYes", "(Ljava/lang/CharSequence;)I", nullptr, $PUBLIC, $virtualMethod(Norm2AllModes$ComposeNormalizer2, spanQuickCheckYes, int32_t, $CharSequence*)},
	{}
};

$InnerClassInfo _Norm2AllModes$ComposeNormalizer2_InnerClassesInfo_[] = {
	{"jdk.internal.icu.impl.Norm2AllModes$ComposeNormalizer2", "jdk.internal.icu.impl.Norm2AllModes", "ComposeNormalizer2", $PUBLIC | $STATIC | $FINAL},
	{"jdk.internal.icu.impl.Norm2AllModes$Normalizer2WithImpl", "jdk.internal.icu.impl.Norm2AllModes", "Normalizer2WithImpl", $PUBLIC | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _Norm2AllModes$ComposeNormalizer2_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.icu.impl.Norm2AllModes$ComposeNormalizer2",
	"jdk.internal.icu.impl.Norm2AllModes$Normalizer2WithImpl",
	nullptr,
	_Norm2AllModes$ComposeNormalizer2_FieldInfo_,
	_Norm2AllModes$ComposeNormalizer2_MethodInfo_,
	nullptr,
	nullptr,
	_Norm2AllModes$ComposeNormalizer2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.icu.impl.Norm2AllModes"
};

$Object* allocate$Norm2AllModes$ComposeNormalizer2($Class* clazz) {
	return $of($alloc(Norm2AllModes$ComposeNormalizer2));
}

void Norm2AllModes$ComposeNormalizer2::init$($NormalizerImpl* ni, bool fcc) {
	$Norm2AllModes$Normalizer2WithImpl::init$(ni);
	this->onlyContiguous = fcc;
}

void Norm2AllModes$ComposeNormalizer2::normalize($CharSequence* src, $NormalizerImpl$ReorderingBuffer* buffer) {
	$nc(this->impl)->compose(src, 0, $nc(src)->length(), this->onlyContiguous, true, buffer);
}

void Norm2AllModes$ComposeNormalizer2::normalizeAndAppend($CharSequence* src, bool doNormalize, $NormalizerImpl$ReorderingBuffer* buffer) {
	$nc(this->impl)->composeAndAppend(src, doNormalize, this->onlyContiguous, buffer);
}

bool Norm2AllModes$ComposeNormalizer2::isNormalized($CharSequence* s) {
	$useLocalCurrentObjectStackCache();
	$var($CharSequence, var$0, s);
	int32_t var$1 = $nc(s)->length();
	bool var$2 = this->onlyContiguous;
	return $nc(this->impl)->compose(var$0, 0, var$1, var$2, false, $$new($NormalizerImpl$ReorderingBuffer, this->impl, $$new($StringBuilder), 5));
}

int32_t Norm2AllModes$ComposeNormalizer2::spanQuickCheckYes($CharSequence* s) {
	return (int32_t)((uint32_t)$nc(this->impl)->composeQuickCheck(s, 0, $nc(s)->length(), this->onlyContiguous, true) >> 1);
}

bool Norm2AllModes$ComposeNormalizer2::hasBoundaryBefore(int32_t c) {
	return $nc(this->impl)->hasCompBoundaryBefore(c);
}

Norm2AllModes$ComposeNormalizer2::Norm2AllModes$ComposeNormalizer2() {
}

$Class* Norm2AllModes$ComposeNormalizer2::load$($String* name, bool initialize) {
	$loadClass(Norm2AllModes$ComposeNormalizer2, name, initialize, &_Norm2AllModes$ComposeNormalizer2_ClassInfo_, allocate$Norm2AllModes$ComposeNormalizer2);
	return class$;
}

$Class* Norm2AllModes$ComposeNormalizer2::class$ = nullptr;

			} // impl
		} // icu
	} // internal
} // jdk