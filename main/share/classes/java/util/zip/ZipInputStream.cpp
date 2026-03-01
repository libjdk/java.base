#include <java/util/zip/ZipInputStream.h>

#include <java/io/EOFException.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/PushbackInputStream.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/Math.h>
#include <java/nio/charset/Charset.h>
#include <java/util/zip/CRC32.h>
#include <java/util/zip/Inflater.h>
#include <java/util/zip/InflaterInputStream.h>
#include <java/util/zip/ZipCoder.h>
#include <java/util/zip/ZipConstants.h>
#include <java/util/zip/ZipEntry.h>
#include <java/util/zip/ZipException.h>
#include <java/util/zip/ZipUtils.h>
#include <sun/nio/cs/UTF_8.h>
#include <jcpp.h>

#undef DEFLATED
#undef EXTCRC
#undef EXTHDR
#undef EXTLEN
#undef EXTSIG
#undef EXTSIZ
#undef INSTANCE
#undef LOCCRC
#undef LOCEXT
#undef LOCFLG
#undef LOCHDR
#undef LOCHOW
#undef LOCLEN
#undef LOCNAM
#undef LOCSIG
#undef LOCSIZ
#undef LOCTIM
#undef MAX_VALUE
#undef STORED

using $EOFException = ::java::io::EOFException;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $PushbackInputStream = ::java::io::PushbackInputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Charset = ::java::nio::charset::Charset;
using $CRC32 = ::java::util::zip::CRC32;
using $Inflater = ::java::util::zip::Inflater;
using $InflaterInputStream = ::java::util::zip::InflaterInputStream;
using $ZipCoder = ::java::util::zip::ZipCoder;
using $ZipConstants = ::java::util::zip::ZipConstants;
using $ZipEntry = ::java::util::zip::ZipEntry;
using $ZipException = ::java::util::zip::ZipException;
using $ZipUtils = ::java::util::zip::ZipUtils;
using $UTF_8 = ::sun::nio::cs::UTF_8;

namespace java {
	namespace util {
		namespace zip {

$FieldInfo _ZipInputStream_FieldInfo_[] = {
	{"entry", "Ljava/util/zip/ZipEntry;", nullptr, $PRIVATE, $field(ZipInputStream, entry)},
	{"flag", "I", nullptr, $PRIVATE, $field(ZipInputStream, flag)},
	{"crc", "Ljava/util/zip/CRC32;", nullptr, $PRIVATE, $field(ZipInputStream, crc)},
	{"remaining", "J", nullptr, $PRIVATE, $field(ZipInputStream, remaining)},
	{"tmpbuf", "[B", nullptr, $PRIVATE, $field(ZipInputStream, tmpbuf)},
	{"STORED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ZipInputStream, STORED)},
	{"DEFLATED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ZipInputStream, DEFLATED)},
	{"closed", "Z", nullptr, $PRIVATE, $field(ZipInputStream, closed)},
	{"entryEOF", "Z", nullptr, $PRIVATE, $field(ZipInputStream, entryEOF)},
	{"zc", "Ljava/util/zip/ZipCoder;", nullptr, $PRIVATE, $field(ZipInputStream, zc)},
	{"b", "[B", nullptr, $PRIVATE, $field(ZipInputStream, b)},
	{}
};

$MethodInfo _ZipInputStream_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(ZipInputStream, init$, void, $InputStream*)},
	{"<init>", "(Ljava/io/InputStream;Ljava/nio/charset/Charset;)V", nullptr, $PUBLIC, $method(ZipInputStream, init$, void, $InputStream*, $Charset*)},
	{"available", "()I", nullptr, $PUBLIC, $virtualMethod(ZipInputStream, available, int32_t), "java.io.IOException"},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(ZipInputStream, close, void), "java.io.IOException"},
	{"closeEntry", "()V", nullptr, $PUBLIC, $virtualMethod(ZipInputStream, closeEntry, void), "java.io.IOException"},
	{"createZipEntry", "(Ljava/lang/String;)Ljava/util/zip/ZipEntry;", nullptr, $PROTECTED, $virtualMethod(ZipInputStream, createZipEntry, $ZipEntry*, $String*)},
	{"ensureOpen", "()V", nullptr, $PRIVATE, $method(ZipInputStream, ensureOpen, void), "java.io.IOException"},
	{"getNextEntry", "()Ljava/util/zip/ZipEntry;", nullptr, $PUBLIC, $virtualMethod(ZipInputStream, getNextEntry, $ZipEntry*), "java.io.IOException"},
	{"read", "([BII)I", nullptr, $PUBLIC, $virtualMethod(ZipInputStream, read, int32_t, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{"readEnd", "(Ljava/util/zip/ZipEntry;)V", nullptr, $PRIVATE, $method(ZipInputStream, readEnd, void, $ZipEntry*), "java.io.IOException"},
	{"readFully", "([BII)V", nullptr, $PRIVATE, $method(ZipInputStream, readFully, void, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{"readLOC", "()Ljava/util/zip/ZipEntry;", nullptr, $PRIVATE, $method(ZipInputStream, readLOC, $ZipEntry*), "java.io.IOException"},
	{"skip", "(J)J", nullptr, $PUBLIC, $virtualMethod(ZipInputStream, skip, int64_t, int64_t), "java.io.IOException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _ZipInputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.zip.ZipInputStream",
	"java.util.zip.InflaterInputStream",
	"java.util.zip.ZipConstants",
	_ZipInputStream_FieldInfo_,
	_ZipInputStream_MethodInfo_
};

$Object* allocate$ZipInputStream($Class* clazz) {
	return $of($alloc(ZipInputStream));
}

int32_t ZipInputStream::hashCode() {
	 return this->$InflaterInputStream::hashCode();
}

bool ZipInputStream::equals(Object$* obj) {
	 return this->$InflaterInputStream::equals(obj);
}

$Object* ZipInputStream::clone() {
	 return this->$InflaterInputStream::clone();
}

$String* ZipInputStream::toString() {
	 return this->$InflaterInputStream::toString();
}

void ZipInputStream::finalize() {
	this->$InflaterInputStream::finalize();
}

void ZipInputStream::ensureOpen() {
	if (this->closed) {
		$throwNew($IOException, "Stream closed"_s);
	}
}

void ZipInputStream::init$($InputStream* in) {
	$init($UTF_8);
	ZipInputStream::init$(in, $UTF_8::INSTANCE);
}

void ZipInputStream::init$($InputStream* in, $Charset* charset) {
	$useLocalCurrentObjectStackCache();
	$var($InputStream, var$0, static_cast<$InputStream*>($new($PushbackInputStream, in, 512)));
	$InflaterInputStream::init$(var$0, $$new($Inflater, true), 512);
	$set(this, crc, $new($CRC32));
	$set(this, tmpbuf, $new($bytes, 512));
	this->closed = false;
	this->entryEOF = false;
	$set(this, b, $new($bytes, 256));
	this->usesDefaultInflater = true;
	if (in == nullptr) {
		$throwNew($NullPointerException, "in is null"_s);
	}
	if (charset == nullptr) {
		$throwNew($NullPointerException, "charset is null"_s);
	}
	$set(this, zc, $ZipCoder::get(charset));
}

$ZipEntry* ZipInputStream::getNextEntry() {
	ensureOpen();
	if (this->entry != nullptr) {
		closeEntry();
	}
	$nc(this->crc)->reset();
	$nc(this->inf)->reset();
	if (($set(this, entry, readLOC())) == nullptr) {
		return nullptr;
	}
	if ($nc(this->entry)->method == ZipInputStream::STORED) {
		this->remaining = $nc(this->entry)->size;
	}
	this->entryEOF = false;
	return this->entry;
}

void ZipInputStream::closeEntry() {
	ensureOpen();
	while (read(this->tmpbuf, 0, $nc(this->tmpbuf)->length) != -1) {
	}
	this->entryEOF = true;
}

int32_t ZipInputStream::available() {
	ensureOpen();
	if (this->entryEOF) {
		return 0;
	} else {
		return 1;
	}
}

int32_t ZipInputStream::read($bytes* b, int32_t off, int32_t len) {
	$useLocalCurrentObjectStackCache();
	ensureOpen();
	if (off < 0 || len < 0 || off > $nc(b)->length - len) {
		$throwNew($IndexOutOfBoundsException);
	} else if (len == 0) {
		return 0;
	}
	if (this->entry == nullptr) {
		return -1;
	}
	switch ($nc(this->entry)->method) {
	case ZipInputStream::DEFLATED:
		{
			len = $InflaterInputStream::read(b, off, len);
			if (len == -1) {
				readEnd(this->entry);
				this->entryEOF = true;
				$set(this, entry, nullptr);
			} else {
				$nc(this->crc)->update(b, off, len);
			}
			return len;
		}
	case ZipInputStream::STORED:
		{
			if (this->remaining <= 0) {
				this->entryEOF = true;
				$set(this, entry, nullptr);
				return -1;
			}
			if (len > this->remaining) {
				len = (int32_t)this->remaining;
			}
			len = $nc(this->in)->read(b, off, len);
			if (len == -1) {
				$throwNew($ZipException, "unexpected EOF"_s);
			}
			$nc(this->crc)->update(b, off, len);
			this->remaining -= len;
			if (this->remaining == 0 && $nc(this->entry)->crc != $nc(this->crc)->getValue()) {
				$var($String, var$1, $$str({"invalid entry CRC (expected 0x"_s, $($Long::toHexString($nc(this->entry)->crc)), " but got 0x"_s}));
				$var($String, var$0, $$concat(var$1, $($Long::toHexString($nc(this->crc)->getValue()))));
				$throwNew($ZipException, $$concat(var$0, ")"_s));
			}
			return len;
		}
	default:
		{
			$throwNew($ZipException, "invalid compression method"_s);
		}
	}
}

int64_t ZipInputStream::skip(int64_t n) {
	if (n < 0) {
		$throwNew($IllegalArgumentException, "negative skip length"_s);
	}
	ensureOpen();
	int32_t max = (int32_t)$Math::min(n, (int64_t)$Integer::MAX_VALUE);
	int32_t total = 0;
	while (total < max) {
		int32_t len = max - total;
		if (len > $nc(this->tmpbuf)->length) {
			len = $nc(this->tmpbuf)->length;
		}
		len = read(this->tmpbuf, 0, len);
		if (len == -1) {
			this->entryEOF = true;
			break;
		}
		total += len;
	}
	return total;
}

void ZipInputStream::close() {
	if (!this->closed) {
		$InflaterInputStream::close();
		this->closed = true;
	}
}

$ZipEntry* ZipInputStream::readLOC() {
	$useLocalCurrentObjectStackCache();
	try {
		readFully(this->tmpbuf, 0, $ZipConstants::LOCHDR);
	} catch ($EOFException& e) {
		return nullptr;
	}
	if ($ZipUtils::get32(this->tmpbuf, 0) != $ZipConstants::LOCSIG) {
		return nullptr;
	}
	this->flag = $ZipUtils::get16(this->tmpbuf, $ZipConstants::LOCFLG);
	int32_t len = $ZipUtils::get16(this->tmpbuf, $ZipConstants::LOCNAM);
	int32_t blen = $nc(this->b)->length;
	if (len > blen) {
		do {
			blen = blen * 2;
		} while (len > blen);
		$set(this, b, $new($bytes, blen));
	}
	readFully(this->b, 0, len);
	$var($ZipEntry, e, createZipEntry((((int32_t)(this->flag & (uint32_t)2048)) != 0) ? $($ZipCoder::toStringUTF8(this->b, len)) : $($nc(this->zc)->toString(this->b, len))));
	if (((int32_t)(this->flag & (uint32_t)1)) == 1) {
		$throwNew($ZipException, "encrypted ZIP entry not supported"_s);
	}
	$nc(e)->method = $ZipUtils::get16(this->tmpbuf, $ZipConstants::LOCHOW);
	e->xdostime = $ZipUtils::get32(this->tmpbuf, $ZipConstants::LOCTIM);
	if (((int32_t)(this->flag & (uint32_t)8)) == 8) {
		if (e->method != ZipInputStream::DEFLATED) {
			$throwNew($ZipException, "only DEFLATED entries can have EXT descriptor"_s);
		}
	} else {
		e->crc = $ZipUtils::get32(this->tmpbuf, $ZipConstants::LOCCRC);
		e->csize = $ZipUtils::get32(this->tmpbuf, $ZipConstants::LOCSIZ);
		e->size = $ZipUtils::get32(this->tmpbuf, $ZipConstants::LOCLEN);
	}
	len = $ZipUtils::get16(this->tmpbuf, $ZipConstants::LOCEXT);
	if (len > 0) {
		$var($bytes, extra, $new($bytes, len));
		readFully(extra, 0, len);
		e->setExtra0(extra, e->csize == (int64_t)0x00000000FFFFFFFF || e->size == (int64_t)0x00000000FFFFFFFF, true);
	}
	return e;
}

$ZipEntry* ZipInputStream::createZipEntry($String* name) {
	return $new($ZipEntry, name);
}

void ZipInputStream::readEnd($ZipEntry* e) {
	$useLocalCurrentObjectStackCache();
	int32_t n = $nc(this->inf)->getRemaining();
	if (n > 0) {
		$nc(($cast($PushbackInputStream, this->in)))->unread(this->buf, this->len - n, n);
	}
	if (((int32_t)(this->flag & (uint32_t)8)) == 8) {
		bool var$0 = $nc(this->inf)->getBytesWritten() > (int64_t)0x00000000FFFFFFFF;
		if (var$0 || $nc(this->inf)->getBytesRead() > (int64_t)0x00000000FFFFFFFF) {
			readFully(this->tmpbuf, 0, 24);
			int64_t sig = $ZipUtils::get32(this->tmpbuf, 0);
			if (sig != $ZipConstants::EXTSIG) {
				$nc(e)->crc = sig;
				e->csize = $ZipUtils::get64(this->tmpbuf, 8 - 4);
				e->size = $ZipUtils::get64(this->tmpbuf, 16 - 4);
				$nc(($cast($PushbackInputStream, this->in)))->unread(this->tmpbuf, 24 - 4, 4);
			} else {
				$nc(e)->crc = $ZipUtils::get32(this->tmpbuf, 4);
				e->csize = $ZipUtils::get64(this->tmpbuf, 8);
				e->size = $ZipUtils::get64(this->tmpbuf, 16);
			}
		} else {
			readFully(this->tmpbuf, 0, $ZipConstants::EXTHDR);
			int64_t sig = $ZipUtils::get32(this->tmpbuf, 0);
			if (sig != $ZipConstants::EXTSIG) {
				$nc(e)->crc = sig;
				e->csize = $ZipUtils::get32(this->tmpbuf, $ZipConstants::EXTSIZ - $ZipConstants::EXTCRC);
				e->size = $ZipUtils::get32(this->tmpbuf, $ZipConstants::EXTLEN - $ZipConstants::EXTCRC);
				$nc(($cast($PushbackInputStream, this->in)))->unread(this->tmpbuf, $ZipConstants::EXTHDR - $ZipConstants::EXTCRC, $ZipConstants::EXTCRC);
			} else {
				$nc(e)->crc = $ZipUtils::get32(this->tmpbuf, $ZipConstants::EXTCRC);
				e->csize = $ZipUtils::get32(this->tmpbuf, $ZipConstants::EXTSIZ);
				e->size = $ZipUtils::get32(this->tmpbuf, $ZipConstants::EXTLEN);
			}
		}
	}
	if ($nc(e)->size != $nc(this->inf)->getBytesWritten()) {
		$throwNew($ZipException, $$str({"invalid entry size (expected "_s, $$str(e->size), " but got "_s, $$str($nc(this->inf)->getBytesWritten()), " bytes)"_s}));
	}
	if ($nc(e)->csize != $nc(this->inf)->getBytesRead()) {
		$throwNew($ZipException, $$str({"invalid entry compressed size (expected "_s, $$str(e->csize), " but got "_s, $$str($nc(this->inf)->getBytesRead()), " bytes)"_s}));
	}
	if ($nc(e)->crc != $nc(this->crc)->getValue()) {
		$var($String, var$2, $$str({"invalid entry CRC (expected 0x"_s, $($Long::toHexString(e->crc)), " but got 0x"_s}));
		$var($String, var$1, $$concat(var$2, $($Long::toHexString($nc(this->crc)->getValue()))));
		$throwNew($ZipException, $$concat(var$1, ")"_s));
	}
}

void ZipInputStream::readFully($bytes* b, int32_t off, int32_t len) {
	while (len > 0) {
		int32_t n = $nc(this->in)->read(b, off, len);
		if (n == -1) {
			$throwNew($EOFException);
		}
		off += n;
		len -= n;
	}
}

ZipInputStream::ZipInputStream() {
}

$Class* ZipInputStream::load$($String* name, bool initialize) {
	$loadClass(ZipInputStream, name, initialize, &_ZipInputStream_ClassInfo_, allocate$ZipInputStream);
	return class$;
}

$Class* ZipInputStream::class$ = nullptr;

		} // zip
	} // util
} // java