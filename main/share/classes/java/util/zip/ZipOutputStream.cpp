#include <java/util/zip/ZipOutputStream.h>

#include <java/io/FilterOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/Math.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/file/attribute/FileTime.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/Vector.h>
#include <java/util/zip/CRC32.h>
#include <java/util/zip/Deflater.h>
#include <java/util/zip/DeflaterOutputStream.h>
#include <java/util/zip/ZipCoder.h>
#include <java/util/zip/ZipConstants.h>
#include <java/util/zip/ZipEntry.h>
#include <java/util/zip/ZipException.h>
#include <java/util/zip/ZipOutputStream$XEntry.h>
#include <java/util/zip/ZipUtils.h>
#include <sun/nio/cs/UTF_8.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef CENSIG
#undef DEFAULT_COMPRESSION
#undef DEFLATED
#undef ENDSIG
#undef EXTSIG
#undef INSTANCE
#undef LOCSIG
#undef STORED

using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Charset = ::java::nio::charset::Charset;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $Vector = ::java::util::Vector;
using $CRC32 = ::java::util::zip::CRC32;
using $Deflater = ::java::util::zip::Deflater;
using $DeflaterOutputStream = ::java::util::zip::DeflaterOutputStream;
using $ZipCoder = ::java::util::zip::ZipCoder;
using $ZipConstants = ::java::util::zip::ZipConstants;
using $ZipEntry = ::java::util::zip::ZipEntry;
using $ZipException = ::java::util::zip::ZipException;
using $ZipOutputStream$XEntry = ::java::util::zip::ZipOutputStream$XEntry;
using $ZipUtils = ::java::util::zip::ZipUtils;
using $UTF_8 = ::sun::nio::cs::UTF_8;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace java {
	namespace util {
		namespace zip {

$FieldInfo _ZipOutputStream_FieldInfo_[] = {
	{"inhibitZip64", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ZipOutputStream, inhibitZip64)},
	{"current", "Ljava/util/zip/ZipOutputStream$XEntry;", nullptr, $PRIVATE, $field(ZipOutputStream, current)},
	{"xentries", "Ljava/util/Vector;", "Ljava/util/Vector<Ljava/util/zip/ZipOutputStream$XEntry;>;", $PRIVATE, $field(ZipOutputStream, xentries)},
	{"names", "Ljava/util/HashSet;", "Ljava/util/HashSet<Ljava/lang/String;>;", $PRIVATE, $field(ZipOutputStream, names)},
	{"crc", "Ljava/util/zip/CRC32;", nullptr, $PRIVATE, $field(ZipOutputStream, crc)},
	{"written", "J", nullptr, $PRIVATE, $field(ZipOutputStream, written)},
	{"locoff", "J", nullptr, $PRIVATE, $field(ZipOutputStream, locoff)},
	{"comment", "[B", nullptr, $PRIVATE, $field(ZipOutputStream, comment)},
	{"method", "I", nullptr, $PRIVATE, $field(ZipOutputStream, method)},
	{"finished", "Z", nullptr, $PRIVATE, $field(ZipOutputStream, finished)},
	{"closed", "Z", nullptr, $PRIVATE, $field(ZipOutputStream, closed)},
	{"zc", "Ljava/util/zip/ZipCoder;", nullptr, $PRIVATE | $FINAL, $field(ZipOutputStream, zc)},
	{"STORED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ZipOutputStream, STORED)},
	{"DEFLATED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ZipOutputStream, DEFLATED)},
	{}
};

$MethodInfo _ZipOutputStream_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $method(ZipOutputStream, init$, void, $OutputStream*)},
	{"<init>", "(Ljava/io/OutputStream;Ljava/nio/charset/Charset;)V", nullptr, $PUBLIC, $method(ZipOutputStream, init$, void, $OutputStream*, $Charset*)},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(ZipOutputStream, close, void), "java.io.IOException"},
	{"closeEntry", "()V", nullptr, $PUBLIC, $virtualMethod(ZipOutputStream, closeEntry, void), "java.io.IOException"},
	{"ensureOpen", "()V", nullptr, $PRIVATE, $method(ZipOutputStream, ensureOpen, void), "java.io.IOException"},
	{"finish", "()V", nullptr, $PUBLIC, $virtualMethod(ZipOutputStream, finish, void), "java.io.IOException"},
	{"getExtraLen", "([B)I", nullptr, $PRIVATE, $method(ZipOutputStream, getExtraLen, int32_t, $bytes*)},
	{"putNextEntry", "(Ljava/util/zip/ZipEntry;)V", nullptr, $PUBLIC, $virtualMethod(ZipOutputStream, putNextEntry, void, $ZipEntry*), "java.io.IOException"},
	{"setComment", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ZipOutputStream, setComment, void, $String*)},
	{"setLevel", "(I)V", nullptr, $PUBLIC, $virtualMethod(ZipOutputStream, setLevel, void, int32_t)},
	{"setMethod", "(I)V", nullptr, $PUBLIC, $virtualMethod(ZipOutputStream, setMethod, void, int32_t)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"version", "(Ljava/util/zip/ZipEntry;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(ZipOutputStream, version, int32_t, $ZipEntry*), "java.util.zip.ZipException"},
	{"versionMadeBy", "(Ljava/util/zip/ZipEntry;I)I", nullptr, $PRIVATE, $method(ZipOutputStream, versionMadeBy, int32_t, $ZipEntry*, int32_t)},
	{"write", "([BII)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(ZipOutputStream, write, void, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{"writeByte", "(I)V", nullptr, $PRIVATE, $method(ZipOutputStream, writeByte, void, int32_t), "java.io.IOException"},
	{"writeBytes", "([BII)V", nullptr, $PRIVATE, $method(ZipOutputStream, writeBytes, void, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{"writeCEN", "(Ljava/util/zip/ZipOutputStream$XEntry;)V", nullptr, $PRIVATE, $method(ZipOutputStream, writeCEN, void, $ZipOutputStream$XEntry*), "java.io.IOException"},
	{"writeEND", "(JJ)V", nullptr, $PRIVATE, $method(ZipOutputStream, writeEND, void, int64_t, int64_t), "java.io.IOException"},
	{"writeEXT", "(Ljava/util/zip/ZipEntry;)V", nullptr, $PRIVATE, $method(ZipOutputStream, writeEXT, void, $ZipEntry*), "java.io.IOException"},
	{"writeExtra", "([B)V", nullptr, $PRIVATE, $method(ZipOutputStream, writeExtra, void, $bytes*), "java.io.IOException"},
	{"writeInt", "(J)V", nullptr, $PRIVATE, $method(ZipOutputStream, writeInt, void, int64_t), "java.io.IOException"},
	{"writeLOC", "(Ljava/util/zip/ZipOutputStream$XEntry;)V", nullptr, $PRIVATE, $method(ZipOutputStream, writeLOC, void, $ZipOutputStream$XEntry*), "java.io.IOException"},
	{"writeLong", "(J)V", nullptr, $PRIVATE, $method(ZipOutputStream, writeLong, void, int64_t), "java.io.IOException"},
	{"writeShort", "(I)V", nullptr, $PRIVATE, $method(ZipOutputStream, writeShort, void, int32_t), "java.io.IOException"},
	{}
};

$InnerClassInfo _ZipOutputStream_InnerClassesInfo_[] = {
	{"java.util.zip.ZipOutputStream$XEntry", "java.util.zip.ZipOutputStream", "XEntry", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _ZipOutputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.zip.ZipOutputStream",
	"java.util.zip.DeflaterOutputStream",
	"java.util.zip.ZipConstants",
	_ZipOutputStream_FieldInfo_,
	_ZipOutputStream_MethodInfo_,
	nullptr,
	nullptr,
	_ZipOutputStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.zip.ZipOutputStream$XEntry"
};

$Object* allocate$ZipOutputStream($Class* clazz) {
	return $of($alloc(ZipOutputStream));
}

int32_t ZipOutputStream::hashCode() {
	 return this->$DeflaterOutputStream::hashCode();
}

bool ZipOutputStream::equals(Object$* obj) {
	 return this->$DeflaterOutputStream::equals(obj);
}

$Object* ZipOutputStream::clone() {
	 return this->$DeflaterOutputStream::clone();
}

$String* ZipOutputStream::toString() {
	 return this->$DeflaterOutputStream::toString();
}

void ZipOutputStream::finalize() {
	this->$DeflaterOutputStream::finalize();
}

bool ZipOutputStream::inhibitZip64 = false;

int32_t ZipOutputStream::version($ZipEntry* e) {
	$init(ZipOutputStream);

	int32_t var$0 = 0;
	switch ($nc(e)->method) {
	case ZipOutputStream::DEFLATED:
		{
			var$0 = 20;
			break;
		}
	case ZipOutputStream::STORED:
		{
			var$0 = 10;
			break;
		}
	default:
		{
			$throwNew($ZipException, "unsupported compression method"_s);
		}
	}
	return var$0;
}

void ZipOutputStream::ensureOpen() {
	if (this->closed) {
		$throwNew($IOException, "Stream closed"_s);
	}
}

void ZipOutputStream::init$($OutputStream* out) {
	$init($UTF_8);
	ZipOutputStream::init$(out, $UTF_8::INSTANCE);
}

void ZipOutputStream::init$($OutputStream* out, $Charset* charset) {
	$DeflaterOutputStream::init$(out, out != nullptr ? $$new($Deflater, $Deflater::DEFAULT_COMPRESSION, true) : ($Deflater*)nullptr);
	$set(this, xentries, $new($Vector));
	$set(this, names, $new($HashSet));
	$set(this, crc, $new($CRC32));
	this->written = 0;
	this->locoff = 0;
	this->method = ZipOutputStream::DEFLATED;
	this->closed = false;
	if (charset == nullptr) {
		$throwNew($NullPointerException, "charset is null"_s);
	}
	$set(this, zc, $ZipCoder::get(charset));
	this->usesDefaultDeflater = true;
}

void ZipOutputStream::setComment($String* comment) {
	if (comment != nullptr) {
		$set(this, comment, $nc(this->zc)->getBytes(comment));
		if ($nc(this->comment)->length > 0x0000FFFF) {
			$throwNew($IllegalArgumentException, "ZIP file comment too long."_s);
		}
	}
}

void ZipOutputStream::setMethod(int32_t method) {
	if (method != ZipOutputStream::DEFLATED && method != ZipOutputStream::STORED) {
		$throwNew($IllegalArgumentException, "invalid compression method"_s);
	}
	this->method = method;
}

void ZipOutputStream::setLevel(int32_t level) {
	$nc(this->def)->setLevel(level);
}

void ZipOutputStream::putNextEntry($ZipEntry* e) {
	ensureOpen();
	if (this->current != nullptr) {
		closeEntry();
	}
	if ($nc(e)->xdostime == -1) {
		e->setTime($System::currentTimeMillis());
	}
	if ($nc(e)->method == -1) {
		e->method = this->method;
	}
	$nc(e)->flag = 0;
	switch (e->method) {
	case ZipOutputStream::DEFLATED:
		{
			if (e->size == -1 || e->csize == -1 || e->crc == -1 || !e->csizeSet) {
				e->flag = 8;
			}
			break;
		}
	case ZipOutputStream::STORED:
		{
			if (e->size == -1) {
				e->size = e->csize;
			} else if (e->csize == -1) {
				e->csize = e->size;
			} else if (e->size != e->csize) {
				$throwNew($ZipException, "STORED entry where compressed != uncompressed size"_s);
			}
			if (e->size == -1 || e->crc == -1) {
				$throwNew($ZipException, "STORED entry missing size, compressed size, or crc-32"_s);
			}
			break;
		}
	default:
		{
			$throwNew($ZipException, "unsupported compression method"_s);
		}
	}
	if (!$nc(this->names)->add(e->name)) {
		$throwNew($ZipException, $$str({"duplicate entry: "_s, e->name}));
	}
	if ($nc(this->zc)->isUTF8()) {
		e->flag |= 2048;
	}
	$set(this, current, $new($ZipOutputStream$XEntry, e, this->written));
	$nc(this->xentries)->add(this->current);
	writeLOC(this->current);
}

void ZipOutputStream::closeEntry() {
	$useLocalCurrentObjectStackCache();
	ensureOpen();
	if (this->current != nullptr) {
		$var($ZipEntry, e, $nc(this->current)->entry);
		switch ($nc(e)->method) {
		case ZipOutputStream::DEFLATED:
			{
				{
					$nc(this->def)->finish();
					while (!$nc(this->def)->finished()) {
						deflate();
					}
					if (((int32_t)(e->flag & (uint32_t)8)) == 0) {
						if (e->size != $nc(this->def)->getBytesRead()) {
							$throwNew($ZipException, $$str({"invalid entry size (expected "_s, $$str(e->size), " but got "_s, $$str($nc(this->def)->getBytesRead()), " bytes)"_s}));
						}
						if (e->csize != $nc(this->def)->getBytesWritten()) {
							$throwNew($ZipException, $$str({"invalid entry compressed size (expected "_s, $$str(e->csize), " but got "_s, $$str($nc(this->def)->getBytesWritten()), " bytes)"_s}));
						}
						if (e->crc != $nc(this->crc)->getValue()) {
							$var($String, var$1, $$str({"invalid entry CRC-32 (expected 0x"_s, $($Long::toHexString(e->crc)), " but got 0x"_s}));
							$var($String, var$0, $$concat(var$1, $($Long::toHexString($nc(this->crc)->getValue()))));
							$throwNew($ZipException, $$concat(var$0, ")"_s));
						}
					} else {
						e->size = $nc(this->def)->getBytesRead();
						e->csize = $nc(this->def)->getBytesWritten();
						e->crc = $nc(this->crc)->getValue();
						writeEXT(e);
					}
					$nc(this->def)->reset();
					this->written += e->csize;
				}
				break;
			}
		case ZipOutputStream::STORED:
			{
				{
					if (e->size != this->written - this->locoff) {
						$throwNew($ZipException, $$str({"invalid entry size (expected "_s, $$str(e->size), " but got "_s, $$str((this->written - this->locoff)), " bytes)"_s}));
					}
					if (e->crc != $nc(this->crc)->getValue()) {
						$var($String, var$3, $$str({"invalid entry crc-32 (expected 0x"_s, $($Long::toHexString(e->crc)), " but got 0x"_s}));
						$var($String, var$2, $$concat(var$3, $($Long::toHexString($nc(this->crc)->getValue()))));
						$throwNew($ZipException, $$concat(var$2, ")"_s));
					}
				}
				break;
			}
		default:
			{
				$throwNew($ZipException, "invalid compression method"_s);
			}
		}
		$nc(this->crc)->reset();
		$set(this, current, nullptr);
	}
}

void ZipOutputStream::write($bytes* b, int32_t off, int32_t len) {
	$synchronized(this) {
		ensureOpen();
		if (off < 0 || len < 0 || off > $nc(b)->length - len) {
			$throwNew($IndexOutOfBoundsException);
		} else if (len == 0) {
			return;
		}
		if (this->current == nullptr) {
			$throwNew($ZipException, "no current ZIP entry"_s);
		}
		$var($ZipEntry, entry, $nc(this->current)->entry);
		switch ($nc(entry)->method) {
		case ZipOutputStream::DEFLATED:
			{
				$DeflaterOutputStream::write(b, off, len);
				break;
			}
		case ZipOutputStream::STORED:
			{
				{
					this->written += len;
					if (this->written - this->locoff > entry->size) {
						$throwNew($ZipException, "attempt to write past end of STORED entry"_s);
					}
					$nc(this->out)->write(b, off, len);
				}
				break;
			}
		default:
			{
				$throwNew($ZipException, "invalid compression method"_s);
			}
		}
		$nc(this->crc)->update(b, off, len);
	}
}

void ZipOutputStream::finish() {
	$useLocalCurrentObjectStackCache();
	ensureOpen();
	if (this->finished) {
		return;
	}
	if (this->current != nullptr) {
		closeEntry();
	}
	int64_t off = this->written;
	{
		$var($Iterator, i$, $nc(this->xentries)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ZipOutputStream$XEntry, xentry, $cast($ZipOutputStream$XEntry, i$->next()));
			writeCEN(xentry);
		}
	}
	writeEND(off, this->written - off);
	this->finished = true;
}

void ZipOutputStream::close() {
	if (!this->closed) {
		$DeflaterOutputStream::close();
		this->closed = true;
	}
}

void ZipOutputStream::writeLOC($ZipOutputStream$XEntry* xentry) {
	$useLocalCurrentObjectStackCache();
	$var($ZipEntry, e, $nc(xentry)->entry);
	int32_t flag = $nc(e)->flag;
	bool hasZip64 = false;
	int32_t elen = getExtraLen(e->extra);
	writeInt($ZipConstants::LOCSIG);
	if (((int32_t)(flag & (uint32_t)8)) == 8) {
		writeShort(version(e));
		writeShort(flag);
		writeShort(e->method);
		writeInt(e->xdostime);
		writeInt(0);
		writeInt(0);
		writeInt(0);
	} else {
		if (e->csize >= (int64_t)0x00000000FFFFFFFF || e->size >= (int64_t)0x00000000FFFFFFFF) {
			hasZip64 = true;
			writeShort(45);
		} else {
			writeShort(version(e));
		}
		writeShort(flag);
		writeShort(e->method);
		writeInt(e->xdostime);
		writeInt(e->crc);
		if (hasZip64) {
			writeInt(0x00000000FFFFFFFF);
			writeInt(0x00000000FFFFFFFF);
			elen += 20;
		} else {
			writeInt(e->csize);
			writeInt(e->size);
		}
	}
	$var($bytes, nameBytes, $nc(this->zc)->getBytes(e->name));
	writeShort($nc(nameBytes)->length);
	int32_t elenEXTT = 0;
	int32_t flagEXTT = 0;
	int64_t umtime = -1;
	int64_t uatime = -1;
	int64_t uctime = -1;
	if (e->mtime != nullptr) {
		elenEXTT += 4;
		flagEXTT |= 1;
		umtime = $ZipUtils::fileTimeToUnixTime(e->mtime);
	}
	if (e->atime != nullptr) {
		elenEXTT += 4;
		flagEXTT |= 2;
		uatime = $ZipUtils::fileTimeToUnixTime(e->atime);
	}
	if (e->ctime != nullptr) {
		elenEXTT += 4;
		flagEXTT |= 4;
		uctime = $ZipUtils::fileTimeToUnixTime(e->ctime);
	}
	if (flagEXTT != 0) {
		if (umtime > (int64_t)2147483647 || uatime > (int64_t)2147483647 || uctime > (int64_t)2147483647) {
			elen += 36;
		} else {
			elen += (elenEXTT + 5);
		}
	}
	writeShort(elen);
	writeBytes(nameBytes, 0, $nc(nameBytes)->length);
	if (hasZip64) {
		writeShort(1);
		writeShort(16);
		writeLong(e->size);
		writeLong(e->csize);
	}
	if (flagEXTT != 0) {
		if (umtime > (int64_t)2147483647 || uatime > (int64_t)2147483647 || uctime > (int64_t)2147483647) {
			writeShort(10);
			writeShort(32);
			writeInt(0);
			writeShort(1);
			writeShort(24);
			writeLong(e->mtime == nullptr ? (int64_t)0x8000000000000000 : $ZipUtils::fileTimeToWinTime(e->mtime));
			writeLong(e->atime == nullptr ? (int64_t)0x8000000000000000 : $ZipUtils::fileTimeToWinTime(e->atime));
			writeLong(e->ctime == nullptr ? (int64_t)0x8000000000000000 : $ZipUtils::fileTimeToWinTime(e->ctime));
		} else {
			writeShort(21589);
			writeShort(elenEXTT + 1);
			writeByte(flagEXTT);
			if (e->mtime != nullptr) {
				writeInt(umtime);
			}
			if (e->atime != nullptr) {
				writeInt(uatime);
			}
			if (e->ctime != nullptr) {
				writeInt(uctime);
			}
		}
	}
	writeExtra(e->extra);
	this->locoff = this->written;
}

void ZipOutputStream::writeEXT($ZipEntry* e) {
	writeInt($ZipConstants::EXTSIG);
	writeInt($nc(e)->crc);
	if ($nc(e)->csize >= (int64_t)0x00000000FFFFFFFF || $nc(e)->size >= (int64_t)0x00000000FFFFFFFF) {
		writeLong(e->csize);
		writeLong(e->size);
	} else {
		writeInt(e->csize);
		writeInt(e->size);
	}
}

int32_t ZipOutputStream::versionMadeBy($ZipEntry* e, int32_t version) {
	return ($nc(e)->extraAttributes < 0) ? version : 768 | ((int32_t)(version & (uint32_t)255));
}

void ZipOutputStream::writeCEN($ZipOutputStream$XEntry* xentry) {
	$useLocalCurrentObjectStackCache();
	$var($ZipEntry, e, $nc(xentry)->entry);
	int32_t flag = $nc(e)->flag;
	int32_t version = ZipOutputStream::version(e);
	int64_t csize = e->csize;
	int64_t size = e->size;
	int64_t offset = xentry->offset;
	int32_t elenZIP64 = 0;
	bool hasZip64 = false;
	if (e->csize >= (int64_t)0x00000000FFFFFFFF) {
		csize = 0x00000000FFFFFFFF;
		elenZIP64 += 8;
		hasZip64 = true;
	}
	if (e->size >= (int64_t)0x00000000FFFFFFFF) {
		size = 0x00000000FFFFFFFF;
		elenZIP64 += 8;
		hasZip64 = true;
	}
	if (xentry->offset >= (int64_t)0x00000000FFFFFFFF) {
		offset = 0x00000000FFFFFFFF;
		elenZIP64 += 8;
		hasZip64 = true;
	}
	writeInt($ZipConstants::CENSIG);
	if (hasZip64) {
		writeShort(versionMadeBy(e, 45));
		writeShort(45);
	} else {
		writeShort(versionMadeBy(e, version));
		writeShort(version);
	}
	writeShort(flag);
	writeShort(e->method);
	writeInt(e->xdostime);
	writeInt(e->crc);
	writeInt(csize);
	writeInt(size);
	$var($bytes, nameBytes, $nc(this->zc)->getBytes(e->name));
	writeShort($nc(nameBytes)->length);
	int32_t elen = getExtraLen(e->extra);
	if (hasZip64) {
		elen += (elenZIP64 + 4);
	}
	int32_t flagEXTT = 0;
	int64_t umtime = -1;
	int64_t uatime = -1;
	int64_t uctime = -1;
	if (e->mtime != nullptr) {
		flagEXTT |= 1;
		umtime = $ZipUtils::fileTimeToUnixTime(e->mtime);
	}
	if (e->atime != nullptr) {
		flagEXTT |= 2;
		uatime = $ZipUtils::fileTimeToUnixTime(e->atime);
	}
	if (e->ctime != nullptr) {
		flagEXTT |= 4;
		uctime = $ZipUtils::fileTimeToUnixTime(e->ctime);
	}
	if (flagEXTT != 0) {
		if (umtime > (int64_t)2147483647 || uatime > (int64_t)2147483647 || uctime > (int64_t)2147483647) {
			elen += 36;
		} else {
			elen += 5;
			if (e->mtime != nullptr) {
				elen += 4;
			}
		}
	}
	writeShort(elen);
	$var($bytes, commentBytes, nullptr);
	if (e->comment != nullptr) {
		$assign(commentBytes, $nc(this->zc)->getBytes(e->comment));
		writeShort($Math::min($nc(commentBytes)->length, 0x0000FFFF));
	} else {
		$assign(commentBytes, nullptr);
		writeShort(0);
	}
	writeShort(0);
	writeShort(0);
	writeInt(e->extraAttributes > 0 ? e->extraAttributes << 16 : 0);
	writeInt(offset);
	writeBytes(nameBytes, 0, $nc(nameBytes)->length);
	if (hasZip64) {
		writeShort(1);
		writeShort(elenZIP64);
		if (size == (int64_t)0x00000000FFFFFFFF) {
			writeLong(e->size);
		}
		if (csize == (int64_t)0x00000000FFFFFFFF) {
			writeLong(e->csize);
		}
		if (offset == (int64_t)0x00000000FFFFFFFF) {
			writeLong(xentry->offset);
		}
	}
	if (flagEXTT != 0) {
		if (umtime > (int64_t)2147483647 || uatime > (int64_t)2147483647 || uctime > (int64_t)2147483647) {
			writeShort(10);
			writeShort(32);
			writeInt(0);
			writeShort(1);
			writeShort(24);
			writeLong(e->mtime == nullptr ? (int64_t)0x8000000000000000 : $ZipUtils::fileTimeToWinTime(e->mtime));
			writeLong(e->atime == nullptr ? (int64_t)0x8000000000000000 : $ZipUtils::fileTimeToWinTime(e->atime));
			writeLong(e->ctime == nullptr ? (int64_t)0x8000000000000000 : $ZipUtils::fileTimeToWinTime(e->ctime));
		} else {
			writeShort(21589);
			if (e->mtime != nullptr) {
				writeShort(5);
				writeByte(flagEXTT);
				writeInt(umtime);
			} else {
				writeShort(1);
				writeByte(flagEXTT);
			}
		}
	}
	writeExtra(e->extra);
	if (commentBytes != nullptr) {
		writeBytes(commentBytes, 0, $Math::min(commentBytes->length, 0x0000FFFF));
	}
}

void ZipOutputStream::writeEND(int64_t off, int64_t len) {
	bool hasZip64 = false;
	int64_t xlen = len;
	int64_t xoff = off;
	if (xlen >= (int64_t)0x00000000FFFFFFFF) {
		xlen = 0x00000000FFFFFFFF;
		hasZip64 = true;
	}
	if (xoff >= (int64_t)0x00000000FFFFFFFF) {
		xoff = 0x00000000FFFFFFFF;
		hasZip64 = true;
	}
	int32_t count = $nc(this->xentries)->size();
	if (count >= 0x0000FFFF) {
		hasZip64 |= !ZipOutputStream::inhibitZip64;
		if (hasZip64) {
			count = 0x0000FFFF;
		}
	}
	if (hasZip64) {
		int64_t off64 = this->written;
		writeInt(101075792);
		writeLong(56 - 12);
		writeShort(45);
		writeShort(45);
		writeInt(0);
		writeInt(0);
		writeLong($nc(this->xentries)->size());
		writeLong($nc(this->xentries)->size());
		writeLong(len);
		writeLong(off);
		writeInt(117853008);
		writeInt(0);
		writeLong(off64);
		writeInt(1);
	}
	writeInt($ZipConstants::ENDSIG);
	writeShort(0);
	writeShort(0);
	writeShort(count);
	writeShort(count);
	writeInt(xlen);
	writeInt(xoff);
	if (this->comment != nullptr) {
		writeShort($nc(this->comment)->length);
		writeBytes(this->comment, 0, $nc(this->comment)->length);
	} else {
		writeShort(0);
	}
}

int32_t ZipOutputStream::getExtraLen($bytes* extra) {
	if (extra == nullptr) {
		return 0;
	}
	int32_t skipped = 0;
	int32_t len = $nc(extra)->length;
	int32_t off = 0;
	while (off + 4 <= len) {
		int32_t tag = $ZipUtils::get16(extra, off);
		int32_t sz = $ZipUtils::get16(extra, off + 2);
		if (sz < 0 || (off + 4 + sz) > len) {
			break;
		}
		if (tag == 21589 || tag == 1) {
			skipped += (sz + 4);
		}
		off += (sz + 4);
	}
	return len - skipped;
}

void ZipOutputStream::writeExtra($bytes* extra) {
	if (extra != nullptr) {
		int32_t len = extra->length;
		int32_t off = 0;
		while (off + 4 <= len) {
			int32_t tag = $ZipUtils::get16(extra, off);
			int32_t sz = $ZipUtils::get16(extra, off + 2);
			if (sz < 0 || (off + 4 + sz) > len) {
				writeBytes(extra, off, len - off);
				return;
			}
			if (tag != 21589 && tag != 1) {
				writeBytes(extra, off, sz + 4);
			}
			off += (sz + 4);
		}
		if (off < len) {
			writeBytes(extra, off, len - off);
		}
	}
}

void ZipOutputStream::writeByte(int32_t v) {
	$var($OutputStream, out, this->out);
	$nc(out)->write((int32_t)(v & (uint32_t)255));
	this->written += 1;
}

void ZipOutputStream::writeShort(int32_t v) {
	$var($OutputStream, out, this->out);
	$nc(out)->write((int32_t)(((int32_t)((uint32_t)v >> 0)) & (uint32_t)255));
	out->write((int32_t)(((int32_t)((uint32_t)v >> 8)) & (uint32_t)255));
	this->written += 2;
}

void ZipOutputStream::writeInt(int64_t v) {
	$var($OutputStream, out, this->out);
	$nc(out)->write((int32_t)((int64_t)(((int64_t)((uint64_t)v >> 0)) & (uint64_t)(int64_t)255)));
	out->write((int32_t)((int64_t)(((int64_t)((uint64_t)v >> 8)) & (uint64_t)(int64_t)255)));
	out->write((int32_t)((int64_t)(((int64_t)((uint64_t)v >> 16)) & (uint64_t)(int64_t)255)));
	out->write((int32_t)((int64_t)(((int64_t)((uint64_t)v >> 24)) & (uint64_t)(int64_t)255)));
	this->written += 4;
}

void ZipOutputStream::writeLong(int64_t v) {
	$var($OutputStream, out, this->out);
	$nc(out)->write((int32_t)((int64_t)(((int64_t)((uint64_t)v >> 0)) & (uint64_t)(int64_t)255)));
	out->write((int32_t)((int64_t)(((int64_t)((uint64_t)v >> 8)) & (uint64_t)(int64_t)255)));
	out->write((int32_t)((int64_t)(((int64_t)((uint64_t)v >> 16)) & (uint64_t)(int64_t)255)));
	out->write((int32_t)((int64_t)(((int64_t)((uint64_t)v >> 24)) & (uint64_t)(int64_t)255)));
	out->write((int32_t)((int64_t)(((int64_t)((uint64_t)v >> 32)) & (uint64_t)(int64_t)255)));
	out->write((int32_t)((int64_t)(((int64_t)((uint64_t)v >> 40)) & (uint64_t)(int64_t)255)));
	out->write((int32_t)((int64_t)(((int64_t)((uint64_t)v >> 48)) & (uint64_t)(int64_t)255)));
	out->write((int32_t)((int64_t)(((int64_t)((uint64_t)v >> 56)) & (uint64_t)(int64_t)255)));
	this->written += 8;
}

void ZipOutputStream::writeBytes($bytes* b, int32_t off, int32_t len) {
	$nc(this->out)->write(b, off, len);
	this->written += len;
}

void clinit$ZipOutputStream($Class* class$) {
	ZipOutputStream::inhibitZip64 = $Boolean::parseBoolean($($GetPropertyAction::privilegedGetProperty("jdk.util.zip.inhibitZip64"_s)));
}

ZipOutputStream::ZipOutputStream() {
}

$Class* ZipOutputStream::load$($String* name, bool initialize) {
	$loadClass(ZipOutputStream, name, initialize, &_ZipOutputStream_ClassInfo_, clinit$ZipOutputStream, allocate$ZipOutputStream);
	return class$;
}

$Class* ZipOutputStream::class$ = nullptr;

		} // zip
	} // util
} // java