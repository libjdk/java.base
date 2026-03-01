#include <com/sun/crypto/provider/GaloisCounterMode$GCMEncrypt.h>

#include <com/sun/crypto/provider/GCM.h>
#include <com/sun/crypto/provider/GCTR.h>
#include <com/sun/crypto/provider/GHASH.h>
#include <com/sun/crypto/provider/GaloisCounterMode$GCMEngine.h>
#include <com/sun/crypto/provider/GaloisCounterMode$GCTRGHASH.h>
#include <com/sun/crypto/provider/GaloisCounterMode.h>
#include <com/sun/crypto/provider/SymmetricCipher.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/lang/ArrayIndexOutOfBoundsException.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/ProviderException.h>
#include <javax/crypto/ShortBufferException.h>
#include <sun/security/util/ArrayUtil.h>
#include <jcpp.h>

using $GCM = ::com::sun::crypto::provider::GCM;
using $GCTR = ::com::sun::crypto::provider::GCTR;
using $GHASH = ::com::sun::crypto::provider::GHASH;
using $GaloisCounterMode = ::com::sun::crypto::provider::GaloisCounterMode;
using $GaloisCounterMode$GCMEngine = ::com::sun::crypto::provider::GaloisCounterMode$GCMEngine;
using $GaloisCounterMode$GCTRGHASH = ::com::sun::crypto::provider::GaloisCounterMode$GCTRGHASH;
using $SymmetricCipher = ::com::sun::crypto::provider::SymmetricCipher;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $ArrayIndexOutOfBoundsException = ::java::lang::ArrayIndexOutOfBoundsException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $ProviderException = ::java::security::ProviderException;
using $ShortBufferException = ::javax::crypto::ShortBufferException;
using $ArrayUtil = ::sun::security::util::ArrayUtil;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _GaloisCounterMode$GCMEncrypt_FieldInfo_[] = {
	{"this$0", "Lcom/sun/crypto/provider/GaloisCounterMode;", nullptr, $FINAL | $SYNTHETIC, $field(GaloisCounterMode$GCMEncrypt, this$0)},
	{"gctrghash", "Lcom/sun/crypto/provider/GaloisCounterMode$GCTRGHASH;", nullptr, 0, $field(GaloisCounterMode$GCMEncrypt, gctrghash)},
	{}
};

$MethodInfo _GaloisCounterMode$GCMEncrypt_MethodInfo_[] = {
	{"<init>", "(Lcom/sun/crypto/provider/GaloisCounterMode;Lcom/sun/crypto/provider/SymmetricCipher;)V", nullptr, 0, $method(GaloisCounterMode$GCMEncrypt, init$, void, $GaloisCounterMode*, $SymmetricCipher*)},
	{"cryptBlocks", "(Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)I", nullptr, 0, $virtualMethod(GaloisCounterMode$GCMEncrypt, cryptBlocks, int32_t, $ByteBuffer*, $ByteBuffer*)},
	{"doFinal", "([BII[BI)I", nullptr, $PUBLIC, $virtualMethod(GaloisCounterMode$GCMEncrypt, doFinal, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.ShortBufferException"},
	{"doFinal", "(Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)I", nullptr, $PUBLIC, $virtualMethod(GaloisCounterMode$GCMEncrypt, doFinal, int32_t, $ByteBuffer*, $ByteBuffer*), "javax.crypto.IllegalBlockSizeException,javax.crypto.ShortBufferException"},
	{"doUpdate", "([BII)[B", nullptr, 0, $virtualMethod(GaloisCounterMode$GCMEncrypt, doUpdate, $bytes*, $bytes*, int32_t, int32_t)},
	{"doUpdate", "([BII[BI)I", nullptr, $PUBLIC, $virtualMethod(GaloisCounterMode$GCMEncrypt, doUpdate, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException"},
	{"doUpdate", "(Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)I", nullptr, $PUBLIC, $virtualMethod(GaloisCounterMode$GCMEncrypt, doUpdate, int32_t, $ByteBuffer*, $ByteBuffer*), "javax.crypto.ShortBufferException"},
	{"getOutputSize", "(IZ)I", nullptr, $PUBLIC, $virtualMethod(GaloisCounterMode$GCMEncrypt, getOutputSize, int32_t, int32_t, bool)},
	{}
};

$InnerClassInfo _GaloisCounterMode$GCMEncrypt_InnerClassesInfo_[] = {
	{"com.sun.crypto.provider.GaloisCounterMode$GCMEncrypt", "com.sun.crypto.provider.GaloisCounterMode", "GCMEncrypt", 0},
	{"com.sun.crypto.provider.GaloisCounterMode$GCMEngine", "com.sun.crypto.provider.GaloisCounterMode", "GCMEngine", $ABSTRACT},
	{}
};

$ClassInfo _GaloisCounterMode$GCMEncrypt_ClassInfo_ = {
	$ACC_SUPER,
	"com.sun.crypto.provider.GaloisCounterMode$GCMEncrypt",
	"com.sun.crypto.provider.GaloisCounterMode$GCMEngine",
	nullptr,
	_GaloisCounterMode$GCMEncrypt_FieldInfo_,
	_GaloisCounterMode$GCMEncrypt_MethodInfo_,
	nullptr,
	nullptr,
	_GaloisCounterMode$GCMEncrypt_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"com.sun.crypto.provider.GaloisCounterMode"
};

$Object* allocate$GaloisCounterMode$GCMEncrypt($Class* clazz) {
	return $of($alloc(GaloisCounterMode$GCMEncrypt));
}

void GaloisCounterMode$GCMEncrypt::init$($GaloisCounterMode* this$0, $SymmetricCipher* blockCipher) {
	$set(this, this$0, this$0);
	$GaloisCounterMode$GCMEngine::init$(this$0, blockCipher);
	$set(this, gctrghash, $new($GaloisCounterMode$GCTRGHASH, this->gctrPAndC, this->ghashAllToS));
}

int32_t GaloisCounterMode$GCMEncrypt::getOutputSize(int32_t inLen, bool isFinal) {
	int32_t len = getBufferedLength();
	if (isFinal) {
		return len + inLen + this->this$0->tagLenBytes;
	} else {
		len += inLen;
		return len - ($mod(len, $nc(this->this$0->blockCipher)->getBlockSize()));
	}
}

$bytes* GaloisCounterMode$GCMEncrypt::doUpdate($bytes* in, int32_t inOff, int32_t inLen) {
	this->this$0->checkReInit();
	$var($bytes, output, $new($bytes, getOutputSize(inLen, false)));
	try {
		doUpdate(in, inOff, inLen, output, 0);
	} catch ($ShortBufferException& e) {
		$throwNew($ProviderException, "output buffer creation failed"_s, e);
	}
	return output;
}

int32_t GaloisCounterMode$GCMEncrypt::doUpdate($bytes* in, int32_t inOfs, int32_t inLen, $bytes* out$renamed, int32_t outOfs) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, out, out$renamed);
	this->this$0->checkReInit();
	int32_t len = 0;
	int32_t bLen = getBufferedLength();
	this->this$0->checkDataLength($$new($ints, {
		inLen,
		bLen
	}));
	processAAD();
	$assign(out, overlapDetection(in, inOfs, out, outOfs));
	if (bLen > 0) {
		$var($bytes, buffer, $nc(this->ibuffer)->toByteArray());
		int32_t remainder = this->blockSize - bLen;
		if ((inLen + bLen) >= this->blockSize) {
			$var($bytes, block, $new($bytes, this->blockSize));
			$System::arraycopy(buffer, 0, block, 0, bLen);
			$System::arraycopy(in, inOfs, block, bLen, remainder);
			len = $nc(this->gctrghash)->update(block, 0, this->blockSize, out, outOfs);
			inOfs += remainder;
			inLen -= remainder;
			outOfs += this->blockSize;
			$nc(this->ibuffer)->reset();
		}
	}
	if (inLen >= this->blockSize) {
		len += $nc(this->gctrghash)->update(in, inOfs, inLen, out, outOfs);
	}
	int32_t remainder = $mod(inLen, this->blockSize);
	if (remainder > 0) {
		initBuffer(remainder);
		inLen -= remainder;
		$nc(this->ibuffer)->write(in, inOfs + inLen, remainder);
	}
	restoreOut(out, len);
	this->processed += len;
	return len;
}

int32_t GaloisCounterMode$GCMEncrypt::doUpdate($ByteBuffer* src, $ByteBuffer* dst$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($ByteBuffer, dst, dst$renamed);
	this->this$0->checkReInit();
	int32_t bLen = getBufferedLength();
	this->this$0->checkDataLength($$new($ints, {
		$nc(src)->remaining(),
		bLen
	}));
	int32_t len = 0;
	processAAD();
	$assign(dst, overlapDetection(src, dst));
	if (bLen > 0) {
		int32_t remainder = this->blockSize - bLen;
		if ($nc(src)->remaining() >= remainder) {
			$var($bytes, block, $new($bytes, this->blockSize));
			$var($ByteBuffer, buffer, $ByteBuffer::wrap($($nc(this->ibuffer)->toByteArray())));
			$nc(buffer)->get(block, 0, bLen);
			src->get(block, bLen, remainder);
			len += cryptBlocks($($ByteBuffer::wrap(block, 0, this->blockSize)), dst);
			$nc(this->ibuffer)->reset();
		}
	}
	if ($nc(src)->remaining() >= this->blockSize) {
		len += cryptBlocks(src, dst);
	}
	if ($nc(src)->remaining() > 0) {
		initBuffer(src->remaining());
		$var($bytes, b, $new($bytes, src->remaining()));
		src->get(b);
		try {
			$nc(this->ibuffer)->write(b);
		} catch ($IOException& e) {
			$throwNew($RuntimeException, static_cast<$Throwable*>(e));
		}
	}
	restoreDst(dst);
	return len;
}

int32_t GaloisCounterMode$GCMEncrypt::doFinal($bytes* in$renamed, int32_t inOfs, int32_t inLen, $bytes* out$renamed, int32_t outOfs) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, in, in$renamed);
	$var($bytes, out, out$renamed);
	this->this$0->checkReInit();
	try {
		$ArrayUtil::nullAndBoundsCheck(out, outOfs, getOutputSize(inLen, true));
	} catch ($ArrayIndexOutOfBoundsException& aiobe) {
		$throwNew($ShortBufferException, "Output buffer invalid"_s);
	}
	int32_t bLen = getBufferedLength();
	this->this$0->checkDataLength($$new($ints, {
		inLen,
		bLen,
		this->this$0->tagLenBytes
	}));
	processAAD();
	$assign(out, overlapDetection(in, inOfs, out, outOfs));
	int32_t resultLen = 0;
	$var($bytes, block, nullptr);
	if (bLen > 0) {
		$var($bytes, buffer, $nc(this->ibuffer)->toByteArray());
		if (bLen + inLen >= this->blockSize) {
			int32_t r = 0;
			int32_t bufOfs = 0;
			$assign(block, $new($bytes, this->blockSize));
			r = mergeBlock(buffer, bufOfs, in, inOfs, inLen, block);
			inOfs += r;
			inLen -= r;
			r = $nc(this->gctrghash)->update(block, 0, this->blockSize, out, outOfs);
			outOfs += r;
			resultLen += r;
			this->processed += r;
		} else {
			$assign(block, $new($bytes, bLen + inLen));
			$System::arraycopy(buffer, 0, block, 0, bLen);
			$System::arraycopy(in, inOfs, block, bLen, inLen);
			inLen += bLen;
			$assign(in, block);
			inOfs = 0;
		}
	}
	if (inLen > 0x00010000) {
		int32_t r = throttleData(this->gctrghash, in, inOfs, inLen, out, outOfs);
		inOfs += r;
		inLen -= r;
		outOfs += r;
		resultLen += r;
		this->processed += r;
	}
	this->processed += $nc(this->gctrghash)->doFinal(in, inOfs, inLen, out, outOfs);
	outOfs += inLen;
	resultLen += inLen;
	$assign(block, $GaloisCounterMode::getLengthBlock(this->sizeOfAAD, this->processed));
	$nc(this->ghashAllToS)->update(block);
	$assign(block, $nc(this->ghashAllToS)->digest());
	$$new($GCTR, this->this$0->blockCipher, this->preCounterBlock)->doFinal(block, 0, this->this$0->tagLenBytes, block, 0);
	$System::arraycopy(block, 0, out, outOfs, this->this$0->tagLenBytes);
	int32_t len = resultLen + this->this$0->tagLenBytes;
	restoreOut(out, len);
	this->this$0->reInit = true;
	return len;
}

int32_t GaloisCounterMode$GCMEncrypt::doFinal($ByteBuffer* src, $ByteBuffer* dst$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($ByteBuffer, dst, dst$renamed);
	this->this$0->checkReInit();
	$assign(dst, overlapDetection(src, dst));
	int32_t var$0 = $nc(src)->remaining();
	int32_t len = var$0 + getBufferedLength();
	this->this$0->checkDataLength($$new($ints, {
		len,
		this->this$0->tagLenBytes
	}));
	if ($nc(dst)->remaining() < len + this->this$0->tagLenBytes) {
		$throwNew($ShortBufferException, $$str({"Output buffer too small, mustbe at least "_s, $$str((len + this->this$0->tagLenBytes)), " bytes long"_s}));
	}
	processAAD();
	if (len > 0) {
		this->processed += doLastBlock(this->gctrghash, (this->ibuffer == nullptr || $nc(this->ibuffer)->size() == 0) ? ($ByteBuffer*)nullptr : $($ByteBuffer::wrap($($nc(this->ibuffer)->toByteArray()))), src, dst);
	}
	if (this->ibuffer != nullptr) {
		$nc(this->ibuffer)->reset();
	}
	$var($bytes, block, $GaloisCounterMode::getLengthBlock(this->sizeOfAAD, this->processed));
	$nc(this->ghashAllToS)->update(block);
	$assign(block, $nc(this->ghashAllToS)->digest());
	$$new($GCTR, this->this$0->blockCipher, this->preCounterBlock)->doFinal(block, 0, this->this$0->tagLenBytes, block, 0);
	$nc(dst)->put(block, 0, this->this$0->tagLenBytes);
	restoreDst(dst);
	this->this$0->reInit = true;
	return (len + this->this$0->tagLenBytes);
}

int32_t GaloisCounterMode$GCMEncrypt::cryptBlocks($ByteBuffer* src, $ByteBuffer* dst) {
	int32_t len = 0;
	if ($nc(src)->remaining() > 0x00010000) {
		len = throttleData(this->gctrghash, src, dst);
	} else {
		len = $nc(this->gctrghash)->update(src, dst);
	}
	this->processed += len;
	return len;
}

GaloisCounterMode$GCMEncrypt::GaloisCounterMode$GCMEncrypt() {
}

$Class* GaloisCounterMode$GCMEncrypt::load$($String* name, bool initialize) {
	$loadClass(GaloisCounterMode$GCMEncrypt, name, initialize, &_GaloisCounterMode$GCMEncrypt_ClassInfo_, allocate$GaloisCounterMode$GCMEncrypt);
	return class$;
}

$Class* GaloisCounterMode$GCMEncrypt::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com