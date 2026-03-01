#include <jdk/internal/icu/text/NormalizerBase.h>

#include <java/lang/CharSequence.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/Cloneable.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/InternalError.h>
#include <java/text/CharacterIterator.h>
#include <java/text/Normalizer$Form.h>
#include <jdk/internal/icu/text/Normalizer2.h>
#include <jdk/internal/icu/text/NormalizerBase$1.h>
#include <jdk/internal/icu/text/NormalizerBase$Mode.h>
#include <jdk/internal/icu/text/NormalizerBase$NFCMode.h>
#include <jdk/internal/icu/text/NormalizerBase$NFDMode.h>
#include <jdk/internal/icu/text/NormalizerBase$NFKCMode.h>
#include <jdk/internal/icu/text/NormalizerBase$NFKDMode.h>
#include <jdk/internal/icu/text/NormalizerBase$NONEMode.h>
#include <jdk/internal/icu/text/UCharacterIterator.h>
#include <jcpp.h>

#undef DONE
#undef NFC
#undef NFD
#undef NFKC
#undef NFKD
#undef NONE
#undef UNICODE_3_2
#undef UNICODE_3_2_0_ORIGINAL
#undef UNICODE_LATEST

using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $CharacterIterator = ::java::text::CharacterIterator;
using $Normalizer$Form = ::java::text::Normalizer$Form;
using $Normalizer2 = ::jdk::internal::icu::text::Normalizer2;
using $NormalizerBase$1 = ::jdk::internal::icu::text::NormalizerBase$1;
using $NormalizerBase$Mode = ::jdk::internal::icu::text::NormalizerBase$Mode;
using $NormalizerBase$NFCMode = ::jdk::internal::icu::text::NormalizerBase$NFCMode;
using $NormalizerBase$NFDMode = ::jdk::internal::icu::text::NormalizerBase$NFDMode;
using $NormalizerBase$NFKCMode = ::jdk::internal::icu::text::NormalizerBase$NFKCMode;
using $NormalizerBase$NFKDMode = ::jdk::internal::icu::text::NormalizerBase$NFKDMode;
using $NormalizerBase$NONEMode = ::jdk::internal::icu::text::NormalizerBase$NONEMode;
using $UCharacterIterator = ::jdk::internal::icu::text::UCharacterIterator;

namespace jdk {
	namespace internal {
		namespace icu {
			namespace text {

$CompoundAttribute _NormalizerBase_MethodAnnotations_getBeginIndex8[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _NormalizerBase_MethodAnnotations_getEndIndex9[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _NormalizerBase_FieldInfo_[] = {
	{"text", "Ljdk/internal/icu/text/UCharacterIterator;", nullptr, $PRIVATE, $field(NormalizerBase, text)},
	{"norm2", "Ljdk/internal/icu/text/Normalizer2;", nullptr, $PRIVATE, $field(NormalizerBase, norm2)},
	{"mode", "Ljdk/internal/icu/text/NormalizerBase$Mode;", nullptr, $PRIVATE, $field(NormalizerBase, mode)},
	{"options", "I", nullptr, $PRIVATE, $field(NormalizerBase, options)},
	{"currentIndex", "I", nullptr, $PRIVATE, $field(NormalizerBase, currentIndex)},
	{"nextIndex", "I", nullptr, $PRIVATE, $field(NormalizerBase, nextIndex)},
	{"buffer", "Ljava/lang/StringBuilder;", nullptr, $PRIVATE, $field(NormalizerBase, buffer)},
	{"bufferPos", "I", nullptr, $PRIVATE, $field(NormalizerBase, bufferPos)},
	{"UNICODE_3_2", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerBase, UNICODE_3_2)},
	{"UNICODE_3_2_0_ORIGINAL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerBase, UNICODE_3_2_0_ORIGINAL)},
	{"UNICODE_LATEST", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerBase, UNICODE_LATEST)},
	{"DONE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerBase, DONE)},
	{"NONE", "Ljdk/internal/icu/text/NormalizerBase$Mode;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(NormalizerBase, NONE)},
	{"NFD", "Ljdk/internal/icu/text/NormalizerBase$Mode;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(NormalizerBase, NFD)},
	{"NFKD", "Ljdk/internal/icu/text/NormalizerBase$Mode;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(NormalizerBase, NFKD)},
	{"NFC", "Ljdk/internal/icu/text/NormalizerBase$Mode;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(NormalizerBase, NFC)},
	{"NFKC", "Ljdk/internal/icu/text/NormalizerBase$Mode;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(NormalizerBase, NFKC)},
	{}
};

$MethodInfo _NormalizerBase_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljdk/internal/icu/text/NormalizerBase$Mode;I)V", nullptr, $PUBLIC, $method(NormalizerBase, init$, void, $String*, $NormalizerBase$Mode*, int32_t)},
	{"<init>", "(Ljava/lang/String;Ljdk/internal/icu/text/NormalizerBase$Mode;)V", nullptr, $PUBLIC, $method(NormalizerBase, init$, void, $String*, $NormalizerBase$Mode*)},
	{"<init>", "(Ljava/text/CharacterIterator;Ljdk/internal/icu/text/NormalizerBase$Mode;I)V", nullptr, $PUBLIC, $method(NormalizerBase, init$, void, $CharacterIterator*, $NormalizerBase$Mode*, int32_t)},
	{"<init>", "(Ljava/text/CharacterIterator;Ljdk/internal/icu/text/NormalizerBase$Mode;)V", nullptr, $PUBLIC, $method(NormalizerBase, init$, void, $CharacterIterator*, $NormalizerBase$Mode*)},
	{"clearBuffer", "()V", nullptr, $PRIVATE, $method(NormalizerBase, clearBuffer, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(NormalizerBase, clone, $Object*)},
	{"current", "()I", nullptr, $PUBLIC, $method(NormalizerBase, current, int32_t)},
	{"endIndex", "()I", nullptr, $PUBLIC, $method(NormalizerBase, endIndex, int32_t)},
	{"getBeginIndex", "()I", nullptr, $PUBLIC | $DEPRECATED, $method(NormalizerBase, getBeginIndex, int32_t), nullptr, nullptr, _NormalizerBase_MethodAnnotations_getBeginIndex8},
	{"getEndIndex", "()I", nullptr, $PUBLIC | $DEPRECATED, $method(NormalizerBase, getEndIndex, int32_t), nullptr, nullptr, _NormalizerBase_MethodAnnotations_getEndIndex9},
	{"getIndex", "()I", nullptr, $PUBLIC, $method(NormalizerBase, getIndex, int32_t)},
	{"getMode", "()Ljdk/internal/icu/text/NormalizerBase$Mode;", nullptr, $PUBLIC, $method(NormalizerBase, getMode, $NormalizerBase$Mode*)},
	{"isNormalized", "(Ljava/lang/String;Ljdk/internal/icu/text/NormalizerBase$Mode;I)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(NormalizerBase, isNormalized, bool, $String*, $NormalizerBase$Mode*, int32_t)},
	{"isNormalized", "(Ljava/lang/String;Ljava/text/Normalizer$Form;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(NormalizerBase, isNormalized, bool, $String*, $Normalizer$Form*)},
	{"isNormalized", "(Ljava/lang/String;Ljava/text/Normalizer$Form;I)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(NormalizerBase, isNormalized, bool, $String*, $Normalizer$Form*, int32_t)},
	{"next", "()I", nullptr, $PUBLIC, $method(NormalizerBase, next, int32_t)},
	{"nextNormalize", "()Z", nullptr, $PRIVATE, $method(NormalizerBase, nextNormalize, bool)},
	{"normalize", "(Ljava/lang/String;Ljdk/internal/icu/text/NormalizerBase$Mode;I)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(NormalizerBase, normalize, $String*, $String*, $NormalizerBase$Mode*, int32_t)},
	{"normalize", "(Ljava/lang/String;Ljava/text/Normalizer$Form;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(NormalizerBase, normalize, $String*, $String*, $Normalizer$Form*)},
	{"normalize", "(Ljava/lang/String;Ljava/text/Normalizer$Form;I)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(NormalizerBase, normalize, $String*, $String*, $Normalizer$Form*, int32_t)},
	{"previous", "()I", nullptr, $PUBLIC, $method(NormalizerBase, previous, int32_t)},
	{"previousNormalize", "()Z", nullptr, $PRIVATE, $method(NormalizerBase, previousNormalize, bool)},
	{"reset", "()V", nullptr, $PUBLIC, $method(NormalizerBase, reset, void)},
	{"setIndex", "(I)I", nullptr, $PUBLIC, $method(NormalizerBase, setIndex, int32_t, int32_t)},
	{"setIndexOnly", "(I)V", nullptr, $PUBLIC, $method(NormalizerBase, setIndexOnly, void, int32_t)},
	{"setMode", "(Ljdk/internal/icu/text/NormalizerBase$Mode;)V", nullptr, $PUBLIC, $method(NormalizerBase, setMode, void, $NormalizerBase$Mode*)},
	{"setText", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(NormalizerBase, setText, void, $String*)},
	{"setText", "(Ljava/text/CharacterIterator;)V", nullptr, $PUBLIC, $method(NormalizerBase, setText, void, $CharacterIterator*)},
	{"toMode", "(Ljava/text/Normalizer$Form;)Ljdk/internal/icu/text/NormalizerBase$Mode;", nullptr, $PRIVATE | $STATIC, $staticMethod(NormalizerBase, toMode, $NormalizerBase$Mode*, $Normalizer$Form*)},
	{}
};

$InnerClassInfo _NormalizerBase_InnerClassesInfo_[] = {
	{"jdk.internal.icu.text.NormalizerBase$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"jdk.internal.icu.text.NormalizerBase$NFKCMode", "jdk.internal.icu.text.NormalizerBase", "NFKCMode", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.text.NormalizerBase$NFCMode", "jdk.internal.icu.text.NormalizerBase", "NFCMode", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.text.NormalizerBase$NFKDMode", "jdk.internal.icu.text.NormalizerBase", "NFKDMode", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.text.NormalizerBase$NFDMode", "jdk.internal.icu.text.NormalizerBase", "NFDMode", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.text.NormalizerBase$NONEMode", "jdk.internal.icu.text.NormalizerBase", "NONEMode", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.text.NormalizerBase$Mode", "jdk.internal.icu.text.NormalizerBase", "Mode", $PUBLIC | $STATIC | $ABSTRACT},
	{"jdk.internal.icu.text.NormalizerBase$NFKC32ModeImpl", "jdk.internal.icu.text.NormalizerBase", "NFKC32ModeImpl", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.text.NormalizerBase$NFC32ModeImpl", "jdk.internal.icu.text.NormalizerBase", "NFC32ModeImpl", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.text.NormalizerBase$NFKD32ModeImpl", "jdk.internal.icu.text.NormalizerBase", "NFKD32ModeImpl", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.text.NormalizerBase$NFD32ModeImpl", "jdk.internal.icu.text.NormalizerBase", "NFD32ModeImpl", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.text.NormalizerBase$Unicode32", "jdk.internal.icu.text.NormalizerBase", "Unicode32", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.text.NormalizerBase$NFKCModeImpl", "jdk.internal.icu.text.NormalizerBase", "NFKCModeImpl", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.text.NormalizerBase$NFCModeImpl", "jdk.internal.icu.text.NormalizerBase", "NFCModeImpl", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.text.NormalizerBase$NFKDModeImpl", "jdk.internal.icu.text.NormalizerBase", "NFKDModeImpl", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.text.NormalizerBase$NFDModeImpl", "jdk.internal.icu.text.NormalizerBase", "NFDModeImpl", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.text.NormalizerBase$ModeImpl", "jdk.internal.icu.text.NormalizerBase", "ModeImpl", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _NormalizerBase_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.icu.text.NormalizerBase",
	"java.lang.Object",
	"java.lang.Cloneable",
	_NormalizerBase_FieldInfo_,
	_NormalizerBase_MethodInfo_,
	nullptr,
	nullptr,
	_NormalizerBase_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.icu.text.NormalizerBase$1,jdk.internal.icu.text.NormalizerBase$NFKCMode,jdk.internal.icu.text.NormalizerBase$NFCMode,jdk.internal.icu.text.NormalizerBase$NFKDMode,jdk.internal.icu.text.NormalizerBase$NFDMode,jdk.internal.icu.text.NormalizerBase$NONEMode,jdk.internal.icu.text.NormalizerBase$Mode,jdk.internal.icu.text.NormalizerBase$NFKC32ModeImpl,jdk.internal.icu.text.NormalizerBase$NFC32ModeImpl,jdk.internal.icu.text.NormalizerBase$NFKD32ModeImpl,jdk.internal.icu.text.NormalizerBase$NFD32ModeImpl,jdk.internal.icu.text.NormalizerBase$Unicode32,jdk.internal.icu.text.NormalizerBase$NFKCModeImpl,jdk.internal.icu.text.NormalizerBase$NFCModeImpl,jdk.internal.icu.text.NormalizerBase$NFKDModeImpl,jdk.internal.icu.text.NormalizerBase$NFDModeImpl,jdk.internal.icu.text.NormalizerBase$ModeImpl"
};

$Object* allocate$NormalizerBase($Class* clazz) {
	return $of($alloc(NormalizerBase));
}

$NormalizerBase$Mode* NormalizerBase::NONE = nullptr;
$NormalizerBase$Mode* NormalizerBase::NFD = nullptr;
$NormalizerBase$Mode* NormalizerBase::NFKD = nullptr;
$NormalizerBase$Mode* NormalizerBase::NFC = nullptr;
$NormalizerBase$Mode* NormalizerBase::NFKC = nullptr;

$NormalizerBase$Mode* NormalizerBase::toMode($Normalizer$Form* form) {
	$init(NormalizerBase);
	$init($NormalizerBase$1);
	switch ($nc($NormalizerBase$1::$SwitchMap$java$text$Normalizer$Form)->get($nc((form))->ordinal())) {
	case 1:
		{
			return NormalizerBase::NFC;
		}
	case 2:
		{
			return NormalizerBase::NFD;
		}
	case 3:
		{
			return NormalizerBase::NFKC;
		}
	case 4:
		{
			return NormalizerBase::NFKD;
		}
	}
	$throwNew($IllegalArgumentException, $$str({"Unexpected normalization form: "_s, form}));
}

void NormalizerBase::init$($String* str, $NormalizerBase$Mode* mode, int32_t opt) {
	$set(this, text, $UCharacterIterator::getInstance(str));
	$set(this, mode, mode);
	this->options = opt;
	$set(this, norm2, $nc(mode)->getNormalizer2(opt));
	$set(this, buffer, $new($StringBuilder));
}

void NormalizerBase::init$($String* str, $NormalizerBase$Mode* mode) {
	NormalizerBase::init$(str, mode, 0);
}

void NormalizerBase::init$($CharacterIterator* iter, $NormalizerBase$Mode* mode, int32_t opt) {
	$set(this, text, $UCharacterIterator::getInstance($cast($CharacterIterator, $($nc(iter)->clone()))));
	$set(this, mode, mode);
	this->options = opt;
	$set(this, norm2, $nc(mode)->getNormalizer2(opt));
	$set(this, buffer, $new($StringBuilder));
}

void NormalizerBase::init$($CharacterIterator* iter, $NormalizerBase$Mode* mode) {
	NormalizerBase::init$(iter, mode, 0);
}

$Object* NormalizerBase::clone() {
	$useLocalCurrentObjectStackCache();
	try {
		$var(NormalizerBase, copy, $cast(NormalizerBase, $Cloneable::clone()));
		$set($nc(copy), text, $cast($UCharacterIterator, $nc(this->text)->clone()));
		$set(copy, mode, this->mode);
		copy->options = this->options;
		$set(copy, norm2, this->norm2);
		$set(copy, buffer, $new($StringBuilder, static_cast<$CharSequence*>(this->buffer)));
		copy->bufferPos = this->bufferPos;
		copy->currentIndex = this->currentIndex;
		copy->nextIndex = this->nextIndex;
		return $of(copy);
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, $(e->toString()), e);
	}
	$shouldNotReachHere();
}

$String* NormalizerBase::normalize($String* str, $NormalizerBase$Mode* mode, int32_t options) {
	$init(NormalizerBase);
	return $nc($($nc(mode)->getNormalizer2(options)))->normalize(str);
}

$String* NormalizerBase::normalize($String* str, $Normalizer$Form* form) {
	$init(NormalizerBase);
	return NormalizerBase::normalize(str, $(toMode(form)), NormalizerBase::UNICODE_LATEST);
}

$String* NormalizerBase::normalize($String* str, $Normalizer$Form* form, int32_t options) {
	$init(NormalizerBase);
	return NormalizerBase::normalize(str, $(toMode(form)), options);
}

bool NormalizerBase::isNormalized($String* str, $NormalizerBase$Mode* mode, int32_t options) {
	$init(NormalizerBase);
	return $nc($($nc(mode)->getNormalizer2(options)))->isNormalized(str);
}

bool NormalizerBase::isNormalized($String* str, $Normalizer$Form* form) {
	$init(NormalizerBase);
	return NormalizerBase::isNormalized(str, $(toMode(form)), NormalizerBase::UNICODE_LATEST);
}

bool NormalizerBase::isNormalized($String* str, $Normalizer$Form* form, int32_t options) {
	$init(NormalizerBase);
	return NormalizerBase::isNormalized(str, $(toMode(form)), options);
}

int32_t NormalizerBase::current() {
	bool var$0 = this->bufferPos < $nc(this->buffer)->length();
	if (var$0 || nextNormalize()) {
		return $nc(this->buffer)->codePointAt(this->bufferPos);
	} else {
		return NormalizerBase::DONE;
	}
}

int32_t NormalizerBase::next() {
	bool var$0 = this->bufferPos < $nc(this->buffer)->length();
	if (var$0 || nextNormalize()) {
		int32_t c = $nc(this->buffer)->codePointAt(this->bufferPos);
		this->bufferPos += $Character::charCount(c);
		return c;
	} else {
		return NormalizerBase::DONE;
	}
}

int32_t NormalizerBase::previous() {
	if (this->bufferPos > 0 || previousNormalize()) {
		int32_t c = $nc(this->buffer)->codePointBefore(this->bufferPos);
		this->bufferPos -= $Character::charCount(c);
		return c;
	} else {
		return NormalizerBase::DONE;
	}
}

void NormalizerBase::reset() {
	$nc(this->text)->setIndex(0);
	this->currentIndex = (this->nextIndex = 0);
	clearBuffer();
}

void NormalizerBase::setIndexOnly(int32_t index) {
	$nc(this->text)->setIndex(index);
	this->currentIndex = (this->nextIndex = index);
	clearBuffer();
}

int32_t NormalizerBase::setIndex(int32_t index) {
	setIndexOnly(index);
	return current();
}

int32_t NormalizerBase::getBeginIndex() {
	return 0;
}

int32_t NormalizerBase::getEndIndex() {
	return endIndex();
}

int32_t NormalizerBase::getIndex() {
	if (this->bufferPos < $nc(this->buffer)->length()) {
		return this->currentIndex;
	} else {
		return this->nextIndex;
	}
}

int32_t NormalizerBase::endIndex() {
	return $nc(this->text)->getLength();
}

void NormalizerBase::setMode($NormalizerBase$Mode* newMode) {
	$set(this, mode, newMode);
	$set(this, norm2, $nc(this->mode)->getNormalizer2(this->options));
}

$NormalizerBase$Mode* NormalizerBase::getMode() {
	return this->mode;
}

void NormalizerBase::setText($String* newText) {
	$var($UCharacterIterator, newIter, $UCharacterIterator::getInstance(newText));
	if (newIter == nullptr) {
		$throwNew($IllegalStateException, "Could not create a new UCharacterIterator"_s);
	}
	$set(this, text, newIter);
	reset();
}

void NormalizerBase::setText($CharacterIterator* newText) {
	$var($UCharacterIterator, newIter, $UCharacterIterator::getInstance(newText));
	if (newIter == nullptr) {
		$throwNew($IllegalStateException, "Could not create a new UCharacterIterator"_s);
	}
	$set(this, text, newIter);
	this->currentIndex = (this->nextIndex = 0);
	clearBuffer();
}

void NormalizerBase::clearBuffer() {
	$nc(this->buffer)->setLength(0);
	this->bufferPos = 0;
}

bool NormalizerBase::nextNormalize() {
	$useLocalCurrentObjectStackCache();
	clearBuffer();
	this->currentIndex = this->nextIndex;
	$nc(this->text)->setIndex(this->nextIndex);
	int32_t c = $nc(this->text)->nextCodePoint();
	if (c < 0) {
		return false;
	}
	$var($StringBuilder, segment, $$new($StringBuilder)->appendCodePoint(c));
	while ((c = $nc(this->text)->nextCodePoint()) >= 0) {
		if ($nc(this->norm2)->hasBoundaryBefore(c)) {
			$nc(this->text)->moveCodePointIndex(-1);
			break;
		}
		$nc(segment)->appendCodePoint(c);
	}
	this->nextIndex = $nc(this->text)->getIndex();
	$nc(this->norm2)->normalize(static_cast<$CharSequence*>(segment), this->buffer);
	return $nc(this->buffer)->length() != 0;
}

bool NormalizerBase::previousNormalize() {
	$useLocalCurrentObjectStackCache();
	clearBuffer();
	this->nextIndex = this->currentIndex;
	$nc(this->text)->setIndex(this->currentIndex);
	$var($StringBuilder, segment, $new($StringBuilder));
	int32_t c = 0;
	while ((c = $nc(this->text)->previousCodePoint()) >= 0) {
		if (c <= 0x0000FFFF) {
			segment->insert(0, (char16_t)c);
		} else {
			segment->insert(0, $($Character::toChars(c)));
		}
		if ($nc(this->norm2)->hasBoundaryBefore(c)) {
			break;
		}
	}
	this->currentIndex = $nc(this->text)->getIndex();
	$nc(this->norm2)->normalize(static_cast<$CharSequence*>(segment), this->buffer);
	this->bufferPos = $nc(this->buffer)->length();
	return $nc(this->buffer)->length() != 0;
}

void clinit$NormalizerBase($Class* class$) {
	$assignStatic(NormalizerBase::NONE, $new($NormalizerBase$NONEMode));
	$assignStatic(NormalizerBase::NFD, $new($NormalizerBase$NFDMode));
	$assignStatic(NormalizerBase::NFKD, $new($NormalizerBase$NFKDMode));
	$assignStatic(NormalizerBase::NFC, $new($NormalizerBase$NFCMode));
	$assignStatic(NormalizerBase::NFKC, $new($NormalizerBase$NFKCMode));
}

NormalizerBase::NormalizerBase() {
}

$Class* NormalizerBase::load$($String* name, bool initialize) {
	$loadClass(NormalizerBase, name, initialize, &_NormalizerBase_ClassInfo_, clinit$NormalizerBase, allocate$NormalizerBase);
	return class$;
}

$Class* NormalizerBase::class$ = nullptr;

			} // text
		} // icu
	} // internal
} // jdk