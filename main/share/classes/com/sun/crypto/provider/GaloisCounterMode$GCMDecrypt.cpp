#include <com/sun/crypto/provider/GaloisCounterMode$GCMDecrypt.h>

#include <com/sun/crypto/provider/GCM.h>
#include <com/sun/crypto/provider/GCTR.h>
#include <com/sun/crypto/provider/GHASH.h>
#include <com/sun/crypto/provider/GaloisCounterMode$GCMEngine.h>
#include <com/sun/crypto/provider/GaloisCounterMode.h>
#include <com/sun/crypto/provider/SymmetricCipher.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/lang/ArrayIndexOutOfBoundsException.h>
#include <java/lang/Math.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/ProviderException.h>
#include <javax/crypto/AEADBadTagException.h>
#include <javax/crypto/ShortBufferException.h>
#include <sun/security/util/ArrayUtil.h>
#include <jcpp.h>

using $GCM = ::com::sun::crypto::provider::GCM;
using $GCTR = ::com::sun::crypto::provider::GCTR;
using $GHASH = ::com::sun::crypto::provider::GHASH;
using $GaloisCounterMode = ::com::sun::crypto::provider::GaloisCounterMode;
using $GaloisCounterMode$GCMEngine = ::com::sun::crypto::provider::GaloisCounterMode$GCMEngine;
using $SymmetricCipher = ::com::sun::crypto::provider::SymmetricCipher;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $ArrayIndexOutOfBoundsException = ::java::lang::ArrayIndexOutOfBoundsException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $ProviderException = ::java::security::ProviderException;
using $AEADBadTagException = ::javax::crypto::AEADBadTagException;
using $ShortBufferException = ::javax::crypto::ShortBufferException;
using $ArrayUtil = ::sun::security::util::ArrayUtil;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _GaloisCounterMode$GCMDecrypt_FieldInfo_[] = {
	{"this$0", "Lcom/sun/crypto/provider/GaloisCounterMode;", nullptr, $FINAL | $SYNTHETIC, $field(GaloisCounterMode$GCMDecrypt, this$0)},
	{"tag", "[B", nullptr, 0, $field(GaloisCounterMode$GCMDecrypt, tag)},
	{"tagOfs", "I", nullptr, 0, $field(GaloisCounterMode$GCMDecrypt, tagOfs)},
	{}
};

$MethodInfo _GaloisCounterMode$GCMDecrypt_MethodInfo_[] = {
	{"<init>", "(Lcom/sun/crypto/provider/GaloisCounterMode;Lcom/sun/crypto/provider/SymmetricCipher;)V", nullptr, 0, $method(GaloisCounterMode$GCMDecrypt, init$, void, $GaloisCounterMode*, $SymmetricCipher*)},
	{"decryptBlocks", "(Lcom/sun/crypto/provider/GCM;[BII[BI)I", nullptr, 0, $virtualMethod(GaloisCounterMode$GCMDecrypt, decryptBlocks, int32_t, $GCM*, $bytes*, int32_t, int32_t, $bytes*, int32_t)},
	{"doFinal", "([BII[BI)I", nullptr, $PUBLIC, $virtualMethod(GaloisCounterMode$GCMDecrypt, doFinal, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.AEADBadTagException,javax.crypto.ShortBufferException"},
	{"doFinal", "(Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)I", nullptr, $PUBLIC, $virtualMethod(GaloisCounterMode$GCMDecrypt, doFinal, int32_t, $ByteBuffer*, $ByteBuffer*), "javax.crypto.IllegalBlockSizeException,javax.crypto.AEADBadTagException,javax.crypto.ShortBufferException"},
	{"doUpdate", "([BII)[B", nullptr, 0, $virtualMethod(GaloisCounterMode$GCMDecrypt, doUpdate, $bytes*, $bytes*, int32_t, int32_t)},
	{"doUpdate", "([BII[BI)I", nullptr, $PUBLIC, $virtualMethod(GaloisCounterMode$GCMDecrypt, doUpdate, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException"},
	{"doUpdate", "(Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)I", nullptr, $PUBLIC, $virtualMethod(GaloisCounterMode$GCMDecrypt, doUpdate, int32_t, $ByteBuffer*, $ByteBuffer*), "javax.crypto.ShortBufferException"},
	{"findTag", "([BII)V", nullptr, 0, $virtualMethod(GaloisCounterMode$GCMDecrypt, findTag, void, $bytes*, int32_t, int32_t)},
	{"getOutputSize", "(IZ)I", nullptr, $PUBLIC, $virtualMethod(GaloisCounterMode$GCMDecrypt, getOutputSize, int32_t, int32_t, bool)},
	{}
};

$InnerClassInfo _GaloisCounterMode$GCMDecrypt_InnerClassesInfo_[] = {
	{"com.sun.crypto.provider.GaloisCounterMode$GCMDecrypt", "com.sun.crypto.provider.GaloisCounterMode", "GCMDecrypt", 0},
	{"com.sun.crypto.provider.GaloisCounterMode$GCMEngine", "com.sun.crypto.provider.GaloisCounterMode", "GCMEngine", $ABSTRACT},
	{}
};

$ClassInfo _GaloisCounterMode$GCMDecrypt_ClassInfo_ = {
	$ACC_SUPER,
	"com.sun.crypto.provider.GaloisCounterMode$GCMDecrypt",
	"com.sun.crypto.provider.GaloisCounterMode$GCMEngine",
	nullptr,
	_GaloisCounterMode$GCMDecrypt_FieldInfo_,
	_GaloisCounterMode$GCMDecrypt_MethodInfo_,
	nullptr,
	nullptr,
	_GaloisCounterMode$GCMDecrypt_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"com.sun.crypto.provider.GaloisCounterMode"
};

$Object* allocate$GaloisCounterMode$GCMDecrypt($Class* clazz) {
	return $of($alloc(GaloisCounterMode$GCMDecrypt));
}

void GaloisCounterMode$GCMDecrypt::init$($GaloisCounterMode* this$0, $SymmetricCipher* blockCipher) {
	$set(this, this$0, this$0);
	$GaloisCounterMode$GCMEngine::init$(this$0, blockCipher);
	this->tagOfs = 0;
}

int32_t GaloisCounterMode$GCMDecrypt::getOutputSize(int32_t inLen, bool isFinal) {
	if (!isFinal) {
		return 0;
	}
	return $Math::max(inLen + getBufferedLength() - this->this$0->tagLenBytes, 0);
}

void GaloisCounterMode$GCMDecrypt::findTag($bytes* in, int32_t inOfs, int32_t inLen) {
	$set(this, tag, $new($bytes, this->this$0->tagLenBytes));
	if (inLen >= this->this$0->tagLenBytes) {
		this->tagOfs = inLen - this->this$0->tagLenBytes;
		$System::arraycopy(in, inOfs + this->tagOfs, this->tag, 0, this->this$0->tagLenBytes);
	} else {
		$var($bytes, buffer, $nc(this->ibuffer)->toByteArray());
		this->tagOfs = mergeBlock(buffer, $nc(buffer)->length - (this->this$0->tagLenBytes - inLen), in, inOfs, inLen, this->tag) - this->this$0->tagLenBytes;
	}
}

$bytes* GaloisCounterMode$GCMDecrypt::doUpdate($bytes* in, int32_t inOff, int32_t inLen) {
	try {
		doUpdate(in, inOff, inLen, nullptr, 0);
	} catch ($ShortBufferException& e) {
	}
	return $new($bytes, 0);
}

int32_t GaloisCounterMode$GCMDecrypt::doUpdate($bytes* in, int32_t inOfs, int32_t inLen, $bytes* out, int32_t outOfs) {
	processAAD();
	if (inLen > 0) {
		initBuffer(inLen);
		$nc(this->ibuffer)->write(in, inOfs, inLen);
	}
	return 0;
}

int32_t GaloisCounterMode$GCMDecrypt::doUpdate($ByteBuffer* src, $ByteBuffer* dst) {
	$useLocalCurrentObjectStackCache();
	processAAD();
	if ($nc(src)->remaining() > 0) {
		if (src->hasArray()) {
			$var($bytes, var$0, $cast($bytes, src->array()));
			int32_t var$2 = src->arrayOffset();
			int32_t var$1 = var$2 + src->position();
			doUpdate(var$0, var$1, src->remaining(), nullptr, 0);
			src->position(src->limit());
		} else {
			$var($bytes, b, $new($bytes, src->remaining()));
			src->get(b);
			initBuffer(b->length);
			try {
				$nc(this->ibuffer)->write(b);
			} catch ($IOException& e) {
				$throwNew($ProviderException, "Unable to add remaining input to the buffer"_s, e);
			}
		}
	}
	return 0;
}

int32_t GaloisCounterMode$GCMDecrypt::doFinal($bytes* in, int32_t inOfs, int32_t inLen, $bytes* out$renamed, int32_t outOfs) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, out, out$renamed);
	$var($GHASH, save, nullptr);
	int32_t len = inLen + getBufferedLength();
	try {
		$ArrayUtil::nullAndBoundsCheck(out, outOfs, len - this->this$0->tagLenBytes);
	} catch ($ArrayIndexOutOfBoundsException& aiobe) {
		$throwNew($ShortBufferException, "Output buffer invalid"_s);
	}
	if (len < this->this$0->tagLenBytes) {
		$throwNew($AEADBadTagException, "Input too short - need tag"_s);
	}
	if (len - this->this$0->tagLenBytes > $nc(out)->length - outOfs) {
		$assign(save, $cast($GHASH, $nc(this->ghashAllToS)->clone()));
	}
	this->this$0->checkDataLength($$new($ints, {len - this->this$0->tagLenBytes}));
	processAAD();
	findTag(in, inOfs, inLen);
	$var($bytes, block, $GaloisCounterMode::getLengthBlock(this->sizeOfAAD, decryptBlocks(this->ghashAllToS, in, inOfs, inLen, nullptr, 0)));
	$nc(this->ghashAllToS)->update(block);
	$assign(block, $nc(this->ghashAllToS)->digest());
	$$new($GCTR, this->this$0->blockCipher, this->preCounterBlock)->doFinal(block, 0, this->this$0->tagLenBytes, block, 0);
	int32_t mismatch = 0;
	for (int32_t i = 0; i < this->this$0->tagLenBytes; ++i) {
		mismatch |= $nc(this->tag)->get(i) ^ $nc(block)->get(i);
	}
	if (mismatch != 0) {
		$throwNew($AEADBadTagException, "Tag mismatch!"_s);
	}
	if (save != nullptr) {
		$set(this, ghashAllToS, save);
		$throwNew($ShortBufferException, $$str({"Output buffer too small, mustbe at least "_s, $$str((len - this->this$0->tagLenBytes)), " bytes long"_s}));
	}
	$assign(out, overlapDetection(in, inOfs, out, outOfs));
	len = decryptBlocks(this->gctrPAndC, in, inOfs, inLen, out, outOfs);
	restoreOut(out, len);
	return len;
}

int32_t GaloisCounterMode$GCMDecrypt::doFinal($ByteBuffer* src, $ByteBuffer* dst$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($ByteBuffer, dst, dst$renamed);
	$var($GHASH, save, nullptr);
	$var($ByteBuffer, tag, nullptr);
	$var($ByteBuffer, ct, $nc(src)->duplicate());
	$var($ByteBuffer, buffer, nullptr);
	int32_t len = $nc(ct)->remaining() - this->this$0->tagLenBytes;
	if (getBufferedLength() != 0) {
		$assign(buffer, $ByteBuffer::wrap($($nc(this->ibuffer)->toByteArray())));
		len += $nc(buffer)->remaining();
	}
	this->this$0->checkDataLength($$new($ints, {len}));
	if (len > $nc(dst)->remaining()) {
		$assign(save, $cast($GHASH, $nc(this->ghashAllToS)->clone()));
	}
	if (ct->remaining() >= this->this$0->tagLenBytes) {
		$assign(tag, src->duplicate());
		$nc(tag)->position(ct->limit() - this->this$0->tagLenBytes);
		ct->limit(ct->limit() - this->this$0->tagLenBytes);
	} else if (buffer != nullptr) {
		$assign(tag, $ByteBuffer::allocate(this->this$0->tagLenBytes));
		int32_t var$0 = buffer->remaining();
		int32_t limit = var$0 - (this->this$0->tagLenBytes - ct->remaining());
		buffer->mark();
		buffer->position(limit);
		$nc(tag)->put(buffer);
		buffer->reset();
		buffer->limit(limit);
		tag->put(ct);
		tag->flip();
	} else {
		$throwNew($AEADBadTagException, "Input too short - need tag"_s);
	}
	ct->mark();
	processAAD();
	doLastBlock(this->ghashAllToS, buffer, ct, nullptr);
	$var($bytes, block, $GaloisCounterMode::getLengthBlock(this->sizeOfAAD, len));
	$nc(this->ghashAllToS)->update(block);
	$assign(block, $nc(this->ghashAllToS)->digest());
	$$new($GCTR, this->this$0->blockCipher, this->preCounterBlock)->doFinal(block, 0, this->this$0->tagLenBytes, block, 0);
	int32_t mismatch = 0;
	for (int32_t i = 0; i < this->this$0->tagLenBytes; ++i) {
		mismatch |= $nc(tag)->get() ^ $nc(block)->get(i);
	}
	if (mismatch != 0) {
		$throwNew($AEADBadTagException, "Tag mismatch!"_s);
	}
	if (save != nullptr) {
		$set(this, ghashAllToS, save);
		$throwNew($ShortBufferException, $$str({"Output buffer too small, must be at least "_s, $$str(len), " bytes long"_s}));
	}
	if (buffer != nullptr) {
		buffer->flip();
	}
	ct->reset();
	this->processed = 0;
	$assign(dst, overlapDetection(src, dst));
	doLastBlock(this->gctrPAndC, buffer, ct, dst);
	restoreDst(dst);
	src->position(src->limit());
	if (this->ibuffer != nullptr) {
		$nc(this->ibuffer)->reset();
	}
	return this->processed;
}

int32_t GaloisCounterMode$GCMDecrypt::decryptBlocks($GCM* op, $bytes* in$renamed, int32_t inOfs, int32_t inLen, $bytes* out, int32_t outOfs) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, in, in$renamed);
	$var($bytes, buffer, nullptr);
	$var($bytes, block, nullptr);
	int32_t len = 0;
	int32_t bLen = getBufferedLength();
	if (this->tagOfs < 0) {
		inLen = 0;
		bLen += this->tagOfs;
	} else {
		inLen -= this->this$0->tagLenBytes;
	}
	if (bLen > 0) {
		$assign(buffer, $nc(this->ibuffer)->toByteArray());
		if (bLen >= this->blockSize) {
			len += $nc(op)->update(buffer, 0, bLen, out, outOfs);
			outOfs += len;
		}
		int32_t bufRemainder = bLen - len;
		if (bufRemainder > 0) {
			$assign(block, $new($bytes, this->blockSize));
			int32_t inUsed = mergeBlock(buffer, len, bufRemainder, in, inOfs, inLen, block);
			inOfs += inUsed;
			inLen -= inUsed;
			if (inLen > 0) {
				int32_t resultLen = $nc(op)->update(block, 0, this->blockSize, out, outOfs);
				outOfs += resultLen;
				len += resultLen;
			} else {
				$assign(in, block);
				inOfs = 0;
				inLen = inUsed + bufRemainder;
			}
		}
	}
	if (inLen > 0x00010000) {
		int32_t l = throttleData(op, in, inOfs, inLen, out, outOfs);
		inOfs += l;
		inLen -= l;
		outOfs += l;
		len += l;
	}
	return len + $nc(op)->doFinal(in, inOfs, inLen, out, outOfs);
}

GaloisCounterMode$GCMDecrypt::GaloisCounterMode$GCMDecrypt() {
}

$Class* GaloisCounterMode$GCMDecrypt::load$($String* name, bool initialize) {
	$loadClass(GaloisCounterMode$GCMDecrypt, name, initialize, &_GaloisCounterMode$GCMDecrypt_ClassInfo_, allocate$GaloisCounterMode$GCMDecrypt);
	return class$;
}

$Class* GaloisCounterMode$GCMDecrypt::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com