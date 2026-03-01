#include <com/sun/crypto/provider/Poly1305.h>

#include <java/lang/AssertionError.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/Arrays.h>
#include <java/util/Objects.h>
#include <sun/security/util/math/ImmutableIntegerModuloP.h>
#include <sun/security/util/math/IntegerFieldModuloP.h>
#include <sun/security/util/math/IntegerModuloP.h>
#include <sun/security/util/math/MutableIntegerModuloP.h>
#include <sun/security/util/math/intpoly/IntegerPolynomial1305.h>
#include <jcpp.h>

#undef BLOCK_LENGTH
#undef KEY_LENGTH
#undef RS_LENGTH
#undef TAG_LENGTH

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $Arrays = ::java::util::Arrays;
using $Objects = ::java::util::Objects;
using $ImmutableIntegerModuloP = ::sun::security::util::math::ImmutableIntegerModuloP;
using $IntegerFieldModuloP = ::sun::security::util::math::IntegerFieldModuloP;
using $IntegerModuloP = ::sun::security::util::math::IntegerModuloP;
using $MutableIntegerModuloP = ::sun::security::util::math::MutableIntegerModuloP;
using $IntegerPolynomial1305 = ::sun::security::util::math::intpoly::IntegerPolynomial1305;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _Poly1305_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Poly1305, $assertionsDisabled)},
	{"KEY_LENGTH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Poly1305, KEY_LENGTH)},
	{"RS_LENGTH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Poly1305, RS_LENGTH)},
	{"BLOCK_LENGTH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Poly1305, BLOCK_LENGTH)},
	{"TAG_LENGTH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Poly1305, TAG_LENGTH)},
	{"ipl1305", "Lsun/security/util/math/IntegerFieldModuloP;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Poly1305, ipl1305)},
	{"keyBytes", "[B", nullptr, $PRIVATE, $field(Poly1305, keyBytes)},
	{"block", "[B", nullptr, $PRIVATE | $FINAL, $field(Poly1305, block)},
	{"blockOffset", "I", nullptr, $PRIVATE, $field(Poly1305, blockOffset)},
	{"r", "Lsun/security/util/math/IntegerModuloP;", nullptr, $PRIVATE, $field(Poly1305, r)},
	{"s", "Lsun/security/util/math/IntegerModuloP;", nullptr, $PRIVATE, $field(Poly1305, s)},
	{"a", "Lsun/security/util/math/MutableIntegerModuloP;", nullptr, $PRIVATE, $field(Poly1305, a)},
	{"n", "Lsun/security/util/math/MutableIntegerModuloP;", nullptr, $PRIVATE | $FINAL, $field(Poly1305, n)},
	{}
};

$MethodInfo _Poly1305_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(Poly1305, init$, void)},
	{"engineDoFinal", "()[B", nullptr, 0, $method(Poly1305, engineDoFinal, $bytes*)},
	{"engineGetMacLength", "()I", nullptr, 0, $method(Poly1305, engineGetMacLength, int32_t)},
	{"engineInit", "(Ljava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, 0, $method(Poly1305, engineInit, void, $Key*, $AlgorithmParameterSpec*), "java.security.InvalidKeyException"},
	{"engineReset", "()V", nullptr, 0, $method(Poly1305, engineReset, void)},
	{"engineUpdate", "(Ljava/nio/ByteBuffer;)V", nullptr, 0, $method(Poly1305, engineUpdate, void, $ByteBuffer*)},
	{"engineUpdate", "([BII)V", nullptr, 0, $method(Poly1305, engineUpdate, void, $bytes*, int32_t, int32_t)},
	{"engineUpdate", "(B)V", nullptr, 0, $method(Poly1305, engineUpdate, void, int8_t)},
	{"processBlock", "(Ljava/nio/ByteBuffer;I)V", nullptr, $PRIVATE, $method(Poly1305, processBlock, void, $ByteBuffer*, int32_t)},
	{"processBlock", "([BII)V", nullptr, $PRIVATE, $method(Poly1305, processBlock, void, $bytes*, int32_t, int32_t)},
	{"setRSVals", "()V", nullptr, $PRIVATE, $method(Poly1305, setRSVals, void)},
	{}
};

$ClassInfo _Poly1305_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.Poly1305",
	"java.lang.Object",
	nullptr,
	_Poly1305_FieldInfo_,
	_Poly1305_MethodInfo_
};

$Object* allocate$Poly1305($Class* clazz) {
	return $of($alloc(Poly1305));
}

bool Poly1305::$assertionsDisabled = false;
$IntegerFieldModuloP* Poly1305::ipl1305 = nullptr;

void Poly1305::init$() {
	$set(this, block, $new($bytes, Poly1305::BLOCK_LENGTH));
	$set(this, n, $nc($($nc(Poly1305::ipl1305)->get1()))->mutable$());
}

void Poly1305::engineInit($Key* newKey, $AlgorithmParameterSpec* params) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(newKey), "Null key provided during init"_s);
	$set(this, keyBytes, $nc(newKey)->getEncoded());
	if (this->keyBytes == nullptr) {
		$throwNew($InvalidKeyException, "Key does not support encoding"_s);
	} else if ($nc(this->keyBytes)->length != Poly1305::KEY_LENGTH) {
		$throwNew($InvalidKeyException, $$str({"Incorrect length for key: "_s, $$str($nc(this->keyBytes)->length)}));
	}
	engineReset();
	setRSVals();
}

int32_t Poly1305::engineGetMacLength() {
	return Poly1305::TAG_LENGTH;
}

void Poly1305::engineReset() {
	$Arrays::fill(this->block, (int8_t)0);
	this->blockOffset = 0;
	$set(this, a, $nc($($nc(Poly1305::ipl1305)->get0()))->mutable$());
}

void Poly1305::engineUpdate($ByteBuffer* buf) {
	int32_t remaining = $nc(buf)->remaining();
	while (remaining > 0) {
		int32_t bytesToWrite = $Integer::min(remaining, Poly1305::BLOCK_LENGTH - this->blockOffset);
		if (bytesToWrite >= Poly1305::BLOCK_LENGTH) {
			processBlock(buf, bytesToWrite);
		} else {
			buf->get(this->block, this->blockOffset, bytesToWrite);
			this->blockOffset += bytesToWrite;
			if (this->blockOffset >= Poly1305::BLOCK_LENGTH) {
				processBlock(this->block, 0, Poly1305::BLOCK_LENGTH);
				this->blockOffset = 0;
			}
		}
		remaining -= bytesToWrite;
	}
}

void Poly1305::engineUpdate($bytes* input, int32_t offset, int32_t len) {
	$Objects::checkFromIndexSize(offset, len, $nc(input)->length);
	if (this->blockOffset > 0) {
		int32_t blockSpaceLeft = Poly1305::BLOCK_LENGTH - this->blockOffset;
		if (len < blockSpaceLeft) {
			$System::arraycopy(input, offset, this->block, this->blockOffset, len);
			this->blockOffset += len;
			return;
		} else {
			$System::arraycopy(input, offset, this->block, this->blockOffset, blockSpaceLeft);
			offset += blockSpaceLeft;
			len -= blockSpaceLeft;
			processBlock(this->block, 0, Poly1305::BLOCK_LENGTH);
			this->blockOffset = 0;
		}
	}
	while (len >= Poly1305::BLOCK_LENGTH) {
		processBlock(input, offset, Poly1305::BLOCK_LENGTH);
		offset += Poly1305::BLOCK_LENGTH;
		len -= Poly1305::BLOCK_LENGTH;
	}
	if (len > 0) {
		$System::arraycopy(input, offset, this->block, 0, len);
		this->blockOffset = len;
	}
}

void Poly1305::engineUpdate(int8_t input) {
	if (!Poly1305::$assertionsDisabled && !(this->blockOffset < Poly1305::BLOCK_LENGTH)) {
		$throwNew($AssertionError);
	}
	$nc(this->block)->set(this->blockOffset++, input);
	if (this->blockOffset == Poly1305::BLOCK_LENGTH) {
		processBlock(this->block, 0, Poly1305::BLOCK_LENGTH);
		this->blockOffset = 0;
	}
}

$bytes* Poly1305::engineDoFinal() {
	$var($bytes, tag, $new($bytes, Poly1305::BLOCK_LENGTH));
	if (this->blockOffset > 0) {
		processBlock(this->block, 0, this->blockOffset);
		this->blockOffset = 0;
	}
	$nc(this->a)->addModPowerTwo(this->s, tag);
	engineReset();
	return tag;
}

void Poly1305::processBlock($ByteBuffer* buf, int32_t len) {
	$nc(this->n)->setValue(buf, len, (int8_t)1);
	$nc(this->a)->setSum(this->n);
	$nc(this->a)->setProduct(this->r);
}

void Poly1305::processBlock($bytes* block, int32_t offset, int32_t length) {
	$Objects::checkFromIndexSize(offset, length, $nc(block)->length);
	$nc(this->n)->setValue(block, offset, length, (int8_t)1);
	$nc(this->a)->setSum(this->n);
	$nc(this->a)->setProduct(this->r);
}

void Poly1305::setRSVals() {
	(*$nc(this->keyBytes))[3] &= (uint8_t)15;
	(*$nc(this->keyBytes))[7] &= (uint8_t)15;
	(*$nc(this->keyBytes))[11] &= (uint8_t)15;
	(*$nc(this->keyBytes))[15] &= (uint8_t)15;
	(*$nc(this->keyBytes))[4] &= (uint8_t)252;
	(*$nc(this->keyBytes))[8] &= (uint8_t)252;
	(*$nc(this->keyBytes))[12] &= (uint8_t)252;
	$set(this, r, $nc(Poly1305::ipl1305)->getElement(this->keyBytes, 0, Poly1305::RS_LENGTH, (int8_t)0));
	$set(this, s, $nc(Poly1305::ipl1305)->getElement(this->keyBytes, Poly1305::RS_LENGTH, Poly1305::RS_LENGTH, (int8_t)0));
}

void clinit$Poly1305($Class* class$) {
	Poly1305::$assertionsDisabled = !Poly1305::class$->desiredAssertionStatus();
	$assignStatic(Poly1305::ipl1305, $new($IntegerPolynomial1305));
}

Poly1305::Poly1305() {
}

$Class* Poly1305::load$($String* name, bool initialize) {
	$loadClass(Poly1305, name, initialize, &_Poly1305_ClassInfo_, clinit$Poly1305, allocate$Poly1305);
	return class$;
}

$Class* Poly1305::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com