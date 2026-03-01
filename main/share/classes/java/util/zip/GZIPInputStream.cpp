#include <java/util/zip/GZIPInputStream.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/EOFException.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/SequenceInputStream.h>
#include <java/util/zip/CRC32.h>
#include <java/util/zip/CheckedInputStream.h>
#include <java/util/zip/Checksum.h>
#include <java/util/zip/GZIPInputStream$1.h>
#include <java/util/zip/Inflater.h>
#include <java/util/zip/InflaterInputStream.h>
#include <java/util/zip/ZipException.h>
#include <jcpp.h>

#undef FCOMMENT
#undef FEXTRA
#undef FHCRC
#undef FNAME
#undef FTEXT
#undef GZIP_MAGIC

using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $EOFException = ::java::io::EOFException;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $SequenceInputStream = ::java::io::SequenceInputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CRC32 = ::java::util::zip::CRC32;
using $CheckedInputStream = ::java::util::zip::CheckedInputStream;
using $Checksum = ::java::util::zip::Checksum;
using $GZIPInputStream$1 = ::java::util::zip::GZIPInputStream$1;
using $Inflater = ::java::util::zip::Inflater;
using $InflaterInputStream = ::java::util::zip::InflaterInputStream;
using $ZipException = ::java::util::zip::ZipException;

namespace java {
	namespace util {
		namespace zip {

$FieldInfo _GZIPInputStream_FieldInfo_[] = {
	{"crc", "Ljava/util/zip/CRC32;", nullptr, $PROTECTED, $field(GZIPInputStream, crc)},
	{"eos", "Z", nullptr, $PROTECTED, $field(GZIPInputStream, eos)},
	{"closed", "Z", nullptr, $PRIVATE, $field(GZIPInputStream, closed)},
	{"GZIP_MAGIC", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GZIPInputStream, GZIP_MAGIC)},
	{"FTEXT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GZIPInputStream, FTEXT)},
	{"FHCRC", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GZIPInputStream, FHCRC)},
	{"FEXTRA", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GZIPInputStream, FEXTRA)},
	{"FNAME", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GZIPInputStream, FNAME)},
	{"FCOMMENT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GZIPInputStream, FCOMMENT)},
	{"tmpbuf", "[B", nullptr, $PRIVATE, $field(GZIPInputStream, tmpbuf)},
	{}
};

$MethodInfo _GZIPInputStream_MethodInfo_[] = {
	{"<init>", "(Ljava/io/InputStream;I)V", nullptr, $PUBLIC, $method(GZIPInputStream, init$, void, $InputStream*, int32_t), "java.io.IOException"},
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(GZIPInputStream, init$, void, $InputStream*), "java.io.IOException"},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(GZIPInputStream, close, void), "java.io.IOException"},
	{"ensureOpen", "()V", nullptr, $PRIVATE, $method(GZIPInputStream, ensureOpen, void), "java.io.IOException"},
	{"read", "([BII)I", nullptr, $PUBLIC, $virtualMethod(GZIPInputStream, read, int32_t, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{"readHeader", "(Ljava/io/InputStream;)I", nullptr, $PRIVATE, $method(GZIPInputStream, readHeader, int32_t, $InputStream*), "java.io.IOException"},
	{"readTrailer", "()Z", nullptr, $PRIVATE, $method(GZIPInputStream, readTrailer, bool), "java.io.IOException"},
	{"readUByte", "(Ljava/io/InputStream;)I", nullptr, $PRIVATE, $method(GZIPInputStream, readUByte, int32_t, $InputStream*), "java.io.IOException"},
	{"readUInt", "(Ljava/io/InputStream;)J", nullptr, $PRIVATE, $method(GZIPInputStream, readUInt, int64_t, $InputStream*), "java.io.IOException"},
	{"readUShort", "(Ljava/io/InputStream;)I", nullptr, $PRIVATE, $method(GZIPInputStream, readUShort, int32_t, $InputStream*), "java.io.IOException"},
	{"skipBytes", "(Ljava/io/InputStream;I)V", nullptr, $PRIVATE, $method(GZIPInputStream, skipBytes, void, $InputStream*, int32_t), "java.io.IOException"},
	{}
};

$InnerClassInfo _GZIPInputStream_InnerClassesInfo_[] = {
	{"java.util.zip.GZIPInputStream$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _GZIPInputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.zip.GZIPInputStream",
	"java.util.zip.InflaterInputStream",
	nullptr,
	_GZIPInputStream_FieldInfo_,
	_GZIPInputStream_MethodInfo_,
	nullptr,
	nullptr,
	_GZIPInputStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.zip.GZIPInputStream$1"
};

$Object* allocate$GZIPInputStream($Class* clazz) {
	return $of($alloc(GZIPInputStream));
}

void GZIPInputStream::ensureOpen() {
	if (this->closed) {
		$throwNew($IOException, "Stream closed"_s);
	}
}

void GZIPInputStream::init$($InputStream* in, int32_t size) {
	$InflaterInputStream::init$(in, in != nullptr ? $$new($Inflater, true) : ($Inflater*)nullptr, size);
	$set(this, crc, $new($CRC32));
	this->closed = false;
	$set(this, tmpbuf, $new($bytes, 128));
	this->usesDefaultInflater = true;
	readHeader(in);
}

void GZIPInputStream::init$($InputStream* in) {
	GZIPInputStream::init$(in, 512);
}

int32_t GZIPInputStream::read($bytes* buf, int32_t off, int32_t len) {
	ensureOpen();
	if (this->eos) {
		return -1;
	}
	int32_t n = $InflaterInputStream::read(buf, off, len);
	if (n == -1) {
		if (readTrailer()) {
			this->eos = true;
		} else {
			return this->read(buf, off, len);
		}
	} else {
		$nc(this->crc)->update(buf, off, n);
	}
	return n;
}

void GZIPInputStream::close() {
	if (!this->closed) {
		$InflaterInputStream::close();
		this->eos = true;
		this->closed = true;
	}
}

int32_t GZIPInputStream::readHeader($InputStream* this_in) {
	$var($CheckedInputStream, in, $new($CheckedInputStream, this_in, this->crc));
	$nc(this->crc)->reset();
	if (readUShort(in) != GZIPInputStream::GZIP_MAGIC) {
		$throwNew($ZipException, "Not in GZIP format"_s);
	}
	if (readUByte(in) != 8) {
		$throwNew($ZipException, "Unsupported compression method"_s);
	}
	int32_t flg = readUByte(in);
	skipBytes(in, 6);
	int32_t n = 2 + 2 + 6;
	if (((int32_t)(flg & (uint32_t)GZIPInputStream::FEXTRA)) == GZIPInputStream::FEXTRA) {
		int32_t m = readUShort(in);
		skipBytes(in, m);
		n += m + 2;
	}
	if (((int32_t)(flg & (uint32_t)GZIPInputStream::FNAME)) == GZIPInputStream::FNAME) {
		do {
			++n;
		} while (readUByte(in) != 0);
	}
	if (((int32_t)(flg & (uint32_t)GZIPInputStream::FCOMMENT)) == GZIPInputStream::FCOMMENT) {
		do {
			++n;
		} while (readUByte(in) != 0);
	}
	if (((int32_t)(flg & (uint32_t)GZIPInputStream::FHCRC)) == GZIPInputStream::FHCRC) {
		int32_t v = (int32_t)((int32_t)$nc(this->crc)->getValue() & (uint32_t)0x0000FFFF);
		if (readUShort(in) != v) {
			$throwNew($ZipException, "Corrupt GZIP header"_s);
		}
		n += 2;
	}
	$nc(this->crc)->reset();
	return n;
}

bool GZIPInputStream::readTrailer() {
	$useLocalCurrentObjectStackCache();
	$var($InputStream, in, this->in);
	int32_t n = $nc(this->inf)->getRemaining();
	if (n > 0) {
		$var($InputStream, var$0, static_cast<$InputStream*>($new($ByteArrayInputStream, this->buf, this->len - n, n)));
		$assign(in, $new($SequenceInputStream, var$0, $$new($GZIPInputStream$1, this, in)));
	}
	int64_t var$2 = readUInt(in);
	bool var$1 = (var$2 != $nc(this->crc)->getValue());
	if (!var$1) {
		int64_t var$3 = readUInt(in);
		var$1 = (var$3 != ((int64_t)($nc(this->inf)->getBytesWritten() & (uint64_t)(int64_t)0x00000000FFFFFFFF)));
	}
	if (var$1) {
		$throwNew($ZipException, "Corrupt GZIP trailer"_s);
	}
	if ($nc(this->in)->available() > 0 || n > 26) {
		int32_t m = 8;
		try {
			m += readHeader(in);
		} catch ($IOException& ze) {
			return true;
		}
		$nc(this->inf)->reset();
		if (n > m) {
			$nc(this->inf)->setInput(this->buf, this->len - n + m, n - m);
		}
		return false;
	}
	return true;
}

int64_t GZIPInputStream::readUInt($InputStream* in) {
	int64_t s = readUShort(in);
	return ((int64_t)readUShort(in) << 16) | s;
}

int32_t GZIPInputStream::readUShort($InputStream* in) {
	int32_t b = readUByte(in);
	return (readUByte(in) << 8) | b;
}

int32_t GZIPInputStream::readUByte($InputStream* in) {
	$useLocalCurrentObjectStackCache();
	int32_t b = $nc(in)->read();
	if (b == -1) {
		$throwNew($EOFException);
	}
	if (b < -1 || b > 255) {
		$throwNew($IOException, $$str({$($nc($of(this->in))->getClass()->getName()), ".read() returned value out of range -1..255: "_s, $$str(b)}));
	}
	return b;
}

void GZIPInputStream::skipBytes($InputStream* in, int32_t n) {
	while (n > 0) {
		int32_t len = $nc(in)->read(this->tmpbuf, 0, n < $nc(this->tmpbuf)->length ? n : $nc(this->tmpbuf)->length);
		if (len == -1) {
			$throwNew($EOFException);
		}
		n -= len;
	}
}

GZIPInputStream::GZIPInputStream() {
}

$Class* GZIPInputStream::load$($String* name, bool initialize) {
	$loadClass(GZIPInputStream, name, initialize, &_GZIPInputStream_ClassInfo_, allocate$GZIPInputStream);
	return class$;
}

$Class* GZIPInputStream::class$ = nullptr;

		} // zip
	} // util
} // java