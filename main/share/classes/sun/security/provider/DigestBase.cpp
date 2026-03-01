#include <sun/security/provider/DigestBase.h>

#include <java/lang/ArrayIndexOutOfBoundsException.h>
#include <java/lang/Math.h>
#include <java/security/DigestException.h>
#include <java/security/MessageDigestSpi.h>
#include <java/security/ProviderException.h>
#include <java/util/Arrays.h>
#include <java/util/Objects.h>
#include <jcpp.h>

using $ArrayIndexOutOfBoundsException = ::java::lang::ArrayIndexOutOfBoundsException;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $DigestException = ::java::security::DigestException;
using $MessageDigestSpi = ::java::security::MessageDigestSpi;
using $ProviderException = ::java::security::ProviderException;
using $Arrays = ::java::util::Arrays;
using $Objects = ::java::util::Objects;

namespace sun {
	namespace security {
		namespace provider {

$CompoundAttribute _DigestBase_MethodAnnotations_implCompressMultiBlock010[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$FieldInfo _DigestBase_FieldInfo_[] = {
	{"oneByte", "[B", nullptr, $PRIVATE, $field(DigestBase, oneByte)},
	{"algorithm", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(DigestBase, algorithm)},
	{"digestLength", "I", nullptr, $PRIVATE | $FINAL, $field(DigestBase, digestLength)},
	{"blockSize", "I", nullptr, $PRIVATE | $FINAL, $field(DigestBase, blockSize)},
	{"buffer", "[B", nullptr, 0, $field(DigestBase, buffer)},
	{"bufOfs", "I", nullptr, $PRIVATE, $field(DigestBase, bufOfs)},
	{"bytesProcessed", "J", nullptr, 0, $field(DigestBase, bytesProcessed)},
	{"padding", "[B", nullptr, $STATIC | $FINAL, $staticField(DigestBase, padding)},
	{}
};

$MethodInfo _DigestBase_MethodInfo_[] = {
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/lang/String;II)V", nullptr, 0, $method(DigestBase, init$, void, $String*, int32_t, int32_t)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DigestBase, clone, $Object*), "java.lang.CloneNotSupportedException"},
	{"engineDigest", "()[B", nullptr, $PROTECTED | $FINAL, $virtualMethod(DigestBase, engineDigest, $bytes*)},
	{"engineDigest", "([BII)I", nullptr, $PROTECTED | $FINAL, $virtualMethod(DigestBase, engineDigest, int32_t, $bytes*, int32_t, int32_t), "java.security.DigestException"},
	{"engineGetDigestLength", "()I", nullptr, $PROTECTED | $FINAL, $virtualMethod(DigestBase, engineGetDigestLength, int32_t)},
	{"engineReset", "()V", nullptr, $PROTECTED | $FINAL, $virtualMethod(DigestBase, engineReset, void)},
	{"engineUpdate", "(B)V", nullptr, $PROTECTED | $FINAL, $virtualMethod(DigestBase, engineUpdate, void, int8_t)},
	{"engineUpdate", "([BII)V", nullptr, $PROTECTED | $FINAL, $virtualMethod(DigestBase, engineUpdate, void, $bytes*, int32_t, int32_t)},
	{"implCompress", "([BI)V", nullptr, $ABSTRACT, $virtualMethod(DigestBase, implCompress, void, $bytes*, int32_t)},
	{"implCompressMultiBlock", "([BII)I", nullptr, $PRIVATE, $method(DigestBase, implCompressMultiBlock, int32_t, $bytes*, int32_t, int32_t)},
	{"implCompressMultiBlock0", "([BII)I", nullptr, $PRIVATE, $method(DigestBase, implCompressMultiBlock0, int32_t, $bytes*, int32_t, int32_t), nullptr, nullptr, _DigestBase_MethodAnnotations_implCompressMultiBlock010},
	{"implCompressMultiBlockCheck", "([BII)V", nullptr, $PRIVATE, $method(DigestBase, implCompressMultiBlockCheck, void, $bytes*, int32_t, int32_t)},
	{"implDigest", "([BI)V", nullptr, $ABSTRACT, $virtualMethod(DigestBase, implDigest, void, $bytes*, int32_t)},
	{"implReset", "()V", nullptr, $ABSTRACT, $virtualMethod(DigestBase, implReset, void)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _DigestBase_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.security.provider.DigestBase",
	"java.security.MessageDigestSpi",
	"java.lang.Cloneable",
	_DigestBase_FieldInfo_,
	_DigestBase_MethodInfo_
};

$Object* allocate$DigestBase($Class* clazz) {
	return $of($alloc(DigestBase));
}

int32_t DigestBase::hashCode() {
	 return this->$MessageDigestSpi::hashCode();
}

bool DigestBase::equals(Object$* obj) {
	 return this->$MessageDigestSpi::equals(obj);
}

$String* DigestBase::toString() {
	 return this->$MessageDigestSpi::toString();
}

void DigestBase::finalize() {
	this->$MessageDigestSpi::finalize();
}

$bytes* DigestBase::padding = nullptr;

void DigestBase::init$($String* algorithm, int32_t digestLength, int32_t blockSize) {
	$MessageDigestSpi::init$();
	$set(this, algorithm, algorithm);
	this->digestLength = digestLength;
	this->blockSize = blockSize;
	$set(this, buffer, $new($bytes, blockSize));
}

int32_t DigestBase::engineGetDigestLength() {
	return this->digestLength;
}

void DigestBase::engineUpdate(int8_t b) {
	if (this->oneByte == nullptr) {
		$set(this, oneByte, $new($bytes, 1));
	}
	$nc(this->oneByte)->set(0, b);
	engineUpdate(this->oneByte, 0, 1);
}

void DigestBase::engineUpdate($bytes* b, int32_t ofs, int32_t len) {
	if (len == 0) {
		return;
	}
	if ((ofs < 0) || (len < 0) || (ofs > $nc(b)->length - len)) {
		$throwNew($ArrayIndexOutOfBoundsException);
	}
	if (this->bytesProcessed < 0) {
		engineReset();
	}
	this->bytesProcessed += len;
	if (this->bufOfs != 0) {
		int32_t n = $Math::min(len, this->blockSize - this->bufOfs);
		$System::arraycopy(b, ofs, this->buffer, this->bufOfs, n);
		this->bufOfs += n;
		ofs += n;
		len -= n;
		if (this->bufOfs >= this->blockSize) {
			implCompress(this->buffer, 0);
			this->bufOfs = 0;
		}
	}
	if (len >= this->blockSize) {
		int32_t limit = ofs + len;
		ofs = implCompressMultiBlock(b, ofs, limit - this->blockSize);
		len = limit - ofs;
	}
	if (len > 0) {
		$System::arraycopy(b, ofs, this->buffer, 0, len);
		this->bufOfs = len;
	}
}

int32_t DigestBase::implCompressMultiBlock($bytes* b, int32_t ofs, int32_t limit) {
	implCompressMultiBlockCheck(b, ofs, limit);
	return implCompressMultiBlock0(b, ofs, limit);
}

int32_t DigestBase::implCompressMultiBlock0($bytes* b, int32_t ofs, int32_t limit) {
	for (; ofs <= limit; ofs += this->blockSize) {
		implCompress(b, ofs);
	}
	return ofs;
}

void DigestBase::implCompressMultiBlockCheck($bytes* b, int32_t ofs, int32_t limit) {
	if (limit < 0) {
		return;
	}
	$Objects::requireNonNull(b);
	if (ofs < 0 || ofs >= b->length) {
		$throwNew($ArrayIndexOutOfBoundsException, ofs);
	}
	int32_t endIndex = ($div(limit, this->blockSize)) * this->blockSize + this->blockSize - 1;
	if (endIndex >= b->length) {
		$throwNew($ArrayIndexOutOfBoundsException, endIndex);
	}
}

void DigestBase::engineReset() {
	if (this->bytesProcessed == 0) {
		return;
	}
	implReset();
	this->bufOfs = 0;
	this->bytesProcessed = 0;
	$Arrays::fill(this->buffer, (int8_t)0);
}

$bytes* DigestBase::engineDigest() {
	$useLocalCurrentObjectStackCache();
	$var($bytes, b, $new($bytes, this->digestLength));
	try {
		engineDigest(b, 0, b->length);
	} catch ($DigestException& e) {
		$throw($cast($ProviderException, $($$new($ProviderException, "Internal error"_s)->initCause(e))));
	}
	return b;
}

int32_t DigestBase::engineDigest($bytes* out, int32_t ofs, int32_t len) {
	$useLocalCurrentObjectStackCache();
	if (len < this->digestLength) {
		$throwNew($DigestException, $$str({"Length must be at least "_s, $$str(this->digestLength), " for "_s, this->algorithm, "digests"_s}));
	}
	if ((ofs < 0) || (len < 0) || (ofs > $nc(out)->length - len)) {
		$throwNew($DigestException, "Buffer too short to store digest"_s);
	}
	if (this->bytesProcessed < 0) {
		engineReset();
	}
	implDigest(out, ofs);
	this->bytesProcessed = -1;
	return this->digestLength;
}

$Object* DigestBase::clone() {
	$var(DigestBase, copy, $cast(DigestBase, $MessageDigestSpi::clone()));
	$set($nc(copy), buffer, $cast($bytes, $nc(copy->buffer)->clone()));
	$set(copy, oneByte, nullptr);
	return $of(copy);
}

void clinit$DigestBase($Class* class$) {
	{
		$assignStatic(DigestBase::padding, $new($bytes, 136));
		$nc(DigestBase::padding)->set(0, (int8_t)128);
	}
}

DigestBase::DigestBase() {
}

$Class* DigestBase::load$($String* name, bool initialize) {
	$loadClass(DigestBase, name, initialize, &_DigestBase_ClassInfo_, clinit$DigestBase, allocate$DigestBase);
	return class$;
}

$Class* DigestBase::class$ = nullptr;

		} // provider
	} // security
} // sun