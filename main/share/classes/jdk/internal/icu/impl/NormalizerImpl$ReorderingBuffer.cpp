#include <jdk/internal/icu/impl/NormalizerImpl$ReorderingBuffer.h>

#include <java/io/IOException.h>
#include <java/lang/Appendable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/InternalError.h>
#include <jdk/internal/icu/impl/NormalizerImpl$UTF16Plus.h>
#include <jdk/internal/icu/impl/NormalizerImpl.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $Appendable = ::java::lang::Appendable;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NormalizerImpl = ::jdk::internal::icu::impl::NormalizerImpl;
using $NormalizerImpl$UTF16Plus = ::jdk::internal::icu::impl::NormalizerImpl$UTF16Plus;

namespace jdk {
	namespace internal {
		namespace icu {
			namespace impl {

$FieldInfo _NormalizerImpl$ReorderingBuffer_FieldInfo_[] = {
	{"impl", "Ljdk/internal/icu/impl/NormalizerImpl;", nullptr, $PRIVATE | $FINAL, $field(NormalizerImpl$ReorderingBuffer, impl)},
	{"app", "Ljava/lang/Appendable;", nullptr, $PRIVATE | $FINAL, $field(NormalizerImpl$ReorderingBuffer, app)},
	{"str", "Ljava/lang/StringBuilder;", nullptr, $PRIVATE | $FINAL, $field(NormalizerImpl$ReorderingBuffer, str)},
	{"appIsStringBuilder", "Z", nullptr, $PRIVATE | $FINAL, $field(NormalizerImpl$ReorderingBuffer, appIsStringBuilder)},
	{"reorderStart", "I", nullptr, $PRIVATE, $field(NormalizerImpl$ReorderingBuffer, reorderStart)},
	{"lastCC", "I", nullptr, $PRIVATE, $field(NormalizerImpl$ReorderingBuffer, lastCC)},
	{"codePointStart", "I", nullptr, $PRIVATE, $field(NormalizerImpl$ReorderingBuffer, codePointStart)},
	{"codePointLimit", "I", nullptr, $PRIVATE, $field(NormalizerImpl$ReorderingBuffer, codePointLimit)},
	{}
};

$MethodInfo _NormalizerImpl$ReorderingBuffer_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/icu/impl/NormalizerImpl;Ljava/lang/Appendable;I)V", nullptr, $PUBLIC, $method(NormalizerImpl$ReorderingBuffer, init$, void, $NormalizerImpl*, $Appendable*, int32_t)},
	{"append", "(II)V", nullptr, $PUBLIC, $method(NormalizerImpl$ReorderingBuffer, append, void, int32_t, int32_t)},
	{"append", "(Ljava/lang/CharSequence;IIZII)V", nullptr, $PUBLIC, $method(NormalizerImpl$ReorderingBuffer, append, void, $CharSequence*, int32_t, int32_t, bool, int32_t, int32_t)},
	{"append", "(C)Ljdk/internal/icu/impl/NormalizerImpl$ReorderingBuffer;", nullptr, $PUBLIC, $virtualMethod(NormalizerImpl$ReorderingBuffer, append, NormalizerImpl$ReorderingBuffer*, char16_t)},
	{"append", "(Ljava/lang/CharSequence;)Ljdk/internal/icu/impl/NormalizerImpl$ReorderingBuffer;", nullptr, $PUBLIC, $virtualMethod(NormalizerImpl$ReorderingBuffer, append, NormalizerImpl$ReorderingBuffer*, $CharSequence*)},
	{"append", "(Ljava/lang/CharSequence;II)Ljdk/internal/icu/impl/NormalizerImpl$ReorderingBuffer;", nullptr, $PUBLIC, $virtualMethod(NormalizerImpl$ReorderingBuffer, append, NormalizerImpl$ReorderingBuffer*, $CharSequence*, int32_t, int32_t)},
	{"appendZeroCC", "(I)V", nullptr, $PUBLIC, $method(NormalizerImpl$ReorderingBuffer, appendZeroCC, void, int32_t)},
	{"equals", "(Ljava/lang/CharSequence;II)Z", nullptr, $PUBLIC, $method(NormalizerImpl$ReorderingBuffer, equals, bool, $CharSequence*, int32_t, int32_t)},
	{"flush", "()V", nullptr, $PUBLIC, $method(NormalizerImpl$ReorderingBuffer, flush, void)},
	{"flushAndAppendZeroCC", "(Ljava/lang/CharSequence;II)Ljdk/internal/icu/impl/NormalizerImpl$ReorderingBuffer;", nullptr, $PUBLIC, $method(NormalizerImpl$ReorderingBuffer, flushAndAppendZeroCC, NormalizerImpl$ReorderingBuffer*, $CharSequence*, int32_t, int32_t)},
	{"getLastCC", "()I", nullptr, $PUBLIC, $method(NormalizerImpl$ReorderingBuffer, getLastCC, int32_t)},
	{"getStringBuilder", "()Ljava/lang/StringBuilder;", nullptr, $PUBLIC, $method(NormalizerImpl$ReorderingBuffer, getStringBuilder, $StringBuilder*)},
	{"insert", "(II)V", nullptr, $PRIVATE, $method(NormalizerImpl$ReorderingBuffer, insert, void, int32_t, int32_t)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $method(NormalizerImpl$ReorderingBuffer, isEmpty, bool)},
	{"length", "()I", nullptr, $PUBLIC, $method(NormalizerImpl$ReorderingBuffer, length, int32_t)},
	{"previousCC", "()I", nullptr, $PRIVATE, $method(NormalizerImpl$ReorderingBuffer, previousCC, int32_t)},
	{"remove", "()V", nullptr, $PUBLIC, $method(NormalizerImpl$ReorderingBuffer, remove, void)},
	{"removeSuffix", "(I)V", nullptr, $PUBLIC, $method(NormalizerImpl$ReorderingBuffer, removeSuffix, void, int32_t)},
	{"setIterator", "()V", nullptr, $PRIVATE, $method(NormalizerImpl$ReorderingBuffer, setIterator, void)},
	{"skipPrevious", "()V", nullptr, $PRIVATE, $method(NormalizerImpl$ReorderingBuffer, skipPrevious, void)},
	{}
};

$InnerClassInfo _NormalizerImpl$ReorderingBuffer_InnerClassesInfo_[] = {
	{"jdk.internal.icu.impl.NormalizerImpl$ReorderingBuffer", "jdk.internal.icu.impl.NormalizerImpl", "ReorderingBuffer", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _NormalizerImpl$ReorderingBuffer_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.icu.impl.NormalizerImpl$ReorderingBuffer",
	"java.lang.Object",
	"java.lang.Appendable",
	_NormalizerImpl$ReorderingBuffer_FieldInfo_,
	_NormalizerImpl$ReorderingBuffer_MethodInfo_,
	nullptr,
	nullptr,
	_NormalizerImpl$ReorderingBuffer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.icu.impl.NormalizerImpl"
};

$Object* allocate$NormalizerImpl$ReorderingBuffer($Class* clazz) {
	return $of($alloc(NormalizerImpl$ReorderingBuffer));
}

void NormalizerImpl$ReorderingBuffer::init$($NormalizerImpl* ni, $Appendable* dest, int32_t destCapacity) {
	$set(this, impl, ni);
	$set(this, app, dest);
	if ($instanceOf($StringBuilder, this->app)) {
		this->appIsStringBuilder = true;
		$set(this, str, $cast($StringBuilder, dest));
		$nc(this->str)->ensureCapacity(destCapacity);
		this->reorderStart = 0;
		if ($nc(this->str)->length() == 0) {
			this->lastCC = 0;
		} else {
			setIterator();
			this->lastCC = previousCC();
			if (this->lastCC > 1) {
				while (previousCC() > 1) {
				}
			}
			this->reorderStart = this->codePointLimit;
		}
	} else {
		this->appIsStringBuilder = false;
		$set(this, str, $new($StringBuilder));
		this->reorderStart = 0;
		this->lastCC = 0;
	}
}

bool NormalizerImpl$ReorderingBuffer::isEmpty() {
	return $nc(this->str)->length() == 0;
}

int32_t NormalizerImpl$ReorderingBuffer::length() {
	return $nc(this->str)->length();
}

int32_t NormalizerImpl$ReorderingBuffer::getLastCC() {
	return this->lastCC;
}

$StringBuilder* NormalizerImpl$ReorderingBuffer::getStringBuilder() {
	return this->str;
}

bool NormalizerImpl$ReorderingBuffer::equals($CharSequence* s, int32_t start, int32_t limit) {
	return $NormalizerImpl$UTF16Plus::equal(this->str, 0, $nc(this->str)->length(), s, start, limit);
}

void NormalizerImpl$ReorderingBuffer::append(int32_t c, int32_t cc) {
	if (this->lastCC <= cc || cc == 0) {
		$nc(this->str)->appendCodePoint(c);
		this->lastCC = cc;
		if (cc <= 1) {
			this->reorderStart = $nc(this->str)->length();
		}
	} else {
		insert(c, cc);
	}
}

void NormalizerImpl$ReorderingBuffer::append($CharSequence* s, int32_t start, int32_t limit, bool isNFD, int32_t leadCC, int32_t trailCC) {
	if (start == limit) {
		return;
	}
	if (this->lastCC <= leadCC || leadCC == 0) {
		if (trailCC <= 1) {
			this->reorderStart = $nc(this->str)->length() + (limit - start);
		} else if (leadCC <= 1) {
			this->reorderStart = $nc(this->str)->length() + 1;
		}
		$nc(this->str)->append(s, start, limit);
		this->lastCC = trailCC;
	} else {
		int32_t c = $Character::codePointAt(s, start);
		start += $Character::charCount(c);
		insert(c, leadCC);
		while (start < limit) {
			c = $Character::codePointAt(s, start);
			start += $Character::charCount(c);
			if (start < limit) {
				if (isNFD) {
					leadCC = $NormalizerImpl::getCCFromYesOrMaybe($nc(this->impl)->getNorm16(c));
				} else {
					leadCC = $nc(this->impl)->getCC($nc(this->impl)->getNorm16(c));
				}
			} else {
				leadCC = trailCC;
			}
			append(c, leadCC);
		}
	}
}

NormalizerImpl$ReorderingBuffer* NormalizerImpl$ReorderingBuffer::append(char16_t c) {
	$nc(this->str)->append(c);
	this->lastCC = 0;
	this->reorderStart = $nc(this->str)->length();
	return this;
}

void NormalizerImpl$ReorderingBuffer::appendZeroCC(int32_t c) {
	$nc(this->str)->appendCodePoint(c);
	this->lastCC = 0;
	this->reorderStart = $nc(this->str)->length();
}

NormalizerImpl$ReorderingBuffer* NormalizerImpl$ReorderingBuffer::append($CharSequence* s) {
	if ($nc(s)->length() != 0) {
		$nc(this->str)->append(s);
		this->lastCC = 0;
		this->reorderStart = $nc(this->str)->length();
	}
	return this;
}

NormalizerImpl$ReorderingBuffer* NormalizerImpl$ReorderingBuffer::append($CharSequence* s, int32_t start, int32_t limit) {
	if (start != limit) {
		$nc(this->str)->append(s, start, limit);
		this->lastCC = 0;
		this->reorderStart = $nc(this->str)->length();
	}
	return this;
}

void NormalizerImpl$ReorderingBuffer::flush() {
	if (this->appIsStringBuilder) {
		this->reorderStart = $nc(this->str)->length();
	} else {
		try {
			$nc(this->app)->append(static_cast<$CharSequence*>(this->str));
			$nc(this->str)->setLength(0);
			this->reorderStart = 0;
		} catch ($IOException& e) {
			$throwNew($InternalError, static_cast<$Throwable*>(e));
		}
	}
	this->lastCC = 0;
}

NormalizerImpl$ReorderingBuffer* NormalizerImpl$ReorderingBuffer::flushAndAppendZeroCC($CharSequence* s, int32_t start, int32_t limit) {
	if (this->appIsStringBuilder) {
		$nc(this->str)->append(s, start, limit);
		this->reorderStart = $nc(this->str)->length();
	} else {
		try {
			$nc($($nc(this->app)->append(static_cast<$CharSequence*>(this->str))))->append(s, start, limit);
			$nc(this->str)->setLength(0);
			this->reorderStart = 0;
		} catch ($IOException& e) {
			$throwNew($InternalError, static_cast<$Throwable*>(e));
		}
	}
	this->lastCC = 0;
	return this;
}

void NormalizerImpl$ReorderingBuffer::remove() {
	$nc(this->str)->setLength(0);
	this->lastCC = 0;
	this->reorderStart = 0;
}

void NormalizerImpl$ReorderingBuffer::removeSuffix(int32_t suffixLength) {
	int32_t oldLength = $nc(this->str)->length();
	$nc(this->str)->delete$(oldLength - suffixLength, oldLength);
	this->lastCC = 0;
	this->reorderStart = $nc(this->str)->length();
}

void NormalizerImpl$ReorderingBuffer::insert(int32_t c, int32_t cc) {
	for (setIterator(), skipPrevious(); previousCC() > cc;) {
	}
	if (c <= 0x0000FFFF) {
		$nc(this->str)->insert(this->codePointLimit, (char16_t)c);
		if (cc <= 1) {
			this->reorderStart = this->codePointLimit + 1;
		}
	} else {
		$nc(this->str)->insert(this->codePointLimit, $($Character::toChars(c)));
		if (cc <= 1) {
			this->reorderStart = this->codePointLimit + 2;
		}
	}
}

void NormalizerImpl$ReorderingBuffer::setIterator() {
	this->codePointStart = $nc(this->str)->length();
}

void NormalizerImpl$ReorderingBuffer::skipPrevious() {
	this->codePointLimit = this->codePointStart;
	this->codePointStart = $nc(this->str)->offsetByCodePoints(this->codePointStart, -1);
}

int32_t NormalizerImpl$ReorderingBuffer::previousCC() {
	this->codePointLimit = this->codePointStart;
	if (this->reorderStart >= this->codePointStart) {
		return 0;
	}
	int32_t c = $nc(this->str)->codePointBefore(this->codePointStart);
	this->codePointStart -= $Character::charCount(c);
	return $nc(this->impl)->getCCFromYesOrMaybeCP(c);
}

NormalizerImpl$ReorderingBuffer::NormalizerImpl$ReorderingBuffer() {
}

$Class* NormalizerImpl$ReorderingBuffer::load$($String* name, bool initialize) {
	$loadClass(NormalizerImpl$ReorderingBuffer, name, initialize, &_NormalizerImpl$ReorderingBuffer_ClassInfo_, allocate$NormalizerImpl$ReorderingBuffer);
	return class$;
}

$Class* NormalizerImpl$ReorderingBuffer::class$ = nullptr;

			} // impl
		} // icu
	} // internal
} // jdk