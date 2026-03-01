#include <java/io/InputStream.h>

#include <java/io/EOFException.h>
#include <java/io/IOException.h>
#include <java/io/InputStream$1.h>
#include <java/io/OutputStream.h>
#include <java/lang/Math.h>
#include <java/lang/OutOfMemoryError.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <jcpp.h>

#undef DEFAULT_BUFFER_SIZE
#undef MAX_BUFFER_SIZE
#undef MAX_SKIP_BUFFER_SIZE
#undef MAX_VALUE

using $EOFException = ::java::io::EOFException;
using $IOException = ::java::io::IOException;
using $InputStream$1 = ::java::io::InputStream$1;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $OutOfMemoryError = ::java::lang::OutOfMemoryError;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;

namespace java {
	namespace io {

$FieldInfo _InputStream_FieldInfo_[] = {
	{"MAX_SKIP_BUFFER_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InputStream, MAX_SKIP_BUFFER_SIZE)},
	{"DEFAULT_BUFFER_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InputStream, DEFAULT_BUFFER_SIZE)},
	{"MAX_BUFFER_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InputStream, MAX_BUFFER_SIZE)},
	{}
};

$MethodInfo _InputStream_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(InputStream, init$, void)},
	{"available", "()I", nullptr, $PUBLIC, $virtualMethod(InputStream, available, int32_t), "java.io.IOException"},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(InputStream, close, void), "java.io.IOException"},
	{"mark", "(I)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(InputStream, mark, void, int32_t)},
	{"markSupported", "()Z", nullptr, $PUBLIC, $virtualMethod(InputStream, markSupported, bool)},
	{"nullInputStream", "()Ljava/io/InputStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(InputStream, nullInputStream, InputStream*)},
	{"read", "()I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(InputStream, read, int32_t), "java.io.IOException"},
	{"read", "([B)I", nullptr, $PUBLIC, $virtualMethod(InputStream, read, int32_t, $bytes*), "java.io.IOException"},
	{"read", "([BII)I", nullptr, $PUBLIC, $virtualMethod(InputStream, read, int32_t, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{"readAllBytes", "()[B", nullptr, $PUBLIC, $virtualMethod(InputStream, readAllBytes, $bytes*), "java.io.IOException"},
	{"readNBytes", "(I)[B", nullptr, $PUBLIC, $virtualMethod(InputStream, readNBytes, $bytes*, int32_t), "java.io.IOException"},
	{"readNBytes", "([BII)I", nullptr, $PUBLIC, $virtualMethod(InputStream, readNBytes, int32_t, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{"reset", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(InputStream, reset, void), "java.io.IOException"},
	{"skip", "(J)J", nullptr, $PUBLIC, $virtualMethod(InputStream, skip, int64_t, int64_t), "java.io.IOException"},
	{"skipNBytes", "(J)V", nullptr, $PUBLIC, $virtualMethod(InputStream, skipNBytes, void, int64_t), "java.io.IOException"},
	{"transferTo", "(Ljava/io/OutputStream;)J", nullptr, $PUBLIC, $virtualMethod(InputStream, transferTo, int64_t, $OutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _InputStream_InnerClassesInfo_[] = {
	{"java.io.InputStream$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _InputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.io.InputStream",
	"java.lang.Object",
	"java.io.Closeable",
	_InputStream_FieldInfo_,
	_InputStream_MethodInfo_,
	nullptr,
	nullptr,
	_InputStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.io.InputStream$1"
};

$Object* allocate$InputStream($Class* clazz) {
	return $of($alloc(InputStream));
}

void InputStream::init$() {
}

InputStream* InputStream::nullInputStream() {
	$init(InputStream);
	return $new($InputStream$1);
}

int32_t InputStream::read($bytes* b) {
	return read(b, 0, $nc(b)->length);
}

int32_t InputStream::read($bytes* b, int32_t off, int32_t len) {
	$Objects::checkFromIndexSize(off, len, $nc(b)->length);
	if (len == 0) {
		return 0;
	}
	int32_t c = read();
	if (c == -1) {
		return -1;
	}
	$nc(b)->set(off, (int8_t)c);
	int32_t i = 1;
	try {
		for (; i < len; ++i) {
			c = read();
			if (c == -1) {
				break;
			}
			b->set(off + i, (int8_t)c);
		}
	} catch ($IOException& ee) {
	}
	return i;
}

$bytes* InputStream::readAllBytes() {
	return readNBytes($Integer::MAX_VALUE);
}

$bytes* InputStream::readNBytes(int32_t len) {
	$useLocalCurrentObjectStackCache();
	if (len < 0) {
		$throwNew($IllegalArgumentException, "len < 0"_s);
	}
	$var($List, bufs, nullptr);
	$var($bytes, result, nullptr);
	int32_t total = 0;
	int32_t remaining = len;
	int32_t n = 0;
	do {
		$var($bytes, buf, $new($bytes, $Math::min(remaining, InputStream::DEFAULT_BUFFER_SIZE)));
		int32_t nread = 0;
		while ((n = read(buf, nread, $Math::min(buf->length - nread, remaining))) > 0) {
			nread += n;
			remaining -= n;
		}
		if (nread > 0) {
			if (InputStream::MAX_BUFFER_SIZE - total < nread) {
				$throwNew($OutOfMemoryError, "Required array size too large"_s);
			}
			if (nread < buf->length) {
				$assign(buf, $Arrays::copyOfRange(buf, 0, nread));
			}
			total += nread;
			if (result == nullptr) {
				$assign(result, buf);
			} else {
				if (bufs == nullptr) {
					$assign(bufs, $new($ArrayList));
					bufs->add(result);
				}
				$nc(bufs)->add(buf);
			}
		}
	} while (n >= 0 && remaining > 0);
	if (bufs == nullptr) {
		if (result == nullptr) {
			return $new($bytes, 0);
		}
		return $nc(result)->length == total ? result : $Arrays::copyOf(result, total);
	}
	$assign(result, $new($bytes, total));
	int32_t offset = 0;
	remaining = total;
	{
		$var($Iterator, i$, $nc(bufs)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($bytes, b, $cast($bytes, i$->next()));
			{
				int32_t count = $Math::min($nc(b)->length, remaining);
				$System::arraycopy(b, 0, result, offset, count);
				offset += count;
				remaining -= count;
			}
		}
	}
	return result;
}

int32_t InputStream::readNBytes($bytes* b, int32_t off, int32_t len) {
	$Objects::checkFromIndexSize(off, len, $nc(b)->length);
	int32_t n = 0;
	while (n < len) {
		int32_t count = read(b, off + n, len - n);
		if (count < 0) {
			break;
		}
		n += count;
	}
	return n;
}

int64_t InputStream::skip(int64_t n) {
	int64_t remaining = n;
	int32_t nr = 0;
	if (n <= 0) {
		return 0;
	}
	int32_t size = (int32_t)$Math::min((int64_t)InputStream::MAX_SKIP_BUFFER_SIZE, remaining);
	$var($bytes, skipBuffer, $new($bytes, size));
	while (remaining > 0) {
		nr = read(skipBuffer, 0, (int32_t)$Math::min((int64_t)size, remaining));
		if (nr < 0) {
			break;
		}
		remaining -= nr;
	}
	return n - remaining;
}

void InputStream::skipNBytes(int64_t n) {
	while (n > 0) {
		int64_t ns = skip(n);
		if (ns > 0 && ns <= n) {
			n -= ns;
		} else if (ns == 0) {
			if (read() == -1) {
				$throwNew($EOFException);
			}
			--n;
		} else {
			$throwNew($IOException, "Unable to skip exactly"_s);
		}
	}
}

int32_t InputStream::available() {
	return 0;
}

void InputStream::close() {
}

void InputStream::mark(int32_t readlimit) {
	$synchronized(this) {
	}
}

void InputStream::reset() {
	$synchronized(this) {
		$throwNew($IOException, "mark/reset not supported"_s);
	}
}

bool InputStream::markSupported() {
	return false;
}

int64_t InputStream::transferTo($OutputStream* out) {
	$Objects::requireNonNull($of(out), "out"_s);
	int64_t transferred = 0;
	$var($bytes, buffer, $new($bytes, InputStream::DEFAULT_BUFFER_SIZE));
	int32_t read = 0;
	while ((read = this->read(buffer, 0, InputStream::DEFAULT_BUFFER_SIZE)) >= 0) {
		$nc(out)->write(buffer, 0, read);
		transferred += read;
	}
	return transferred;
}

InputStream::InputStream() {
}

$Class* InputStream::load$($String* name, bool initialize) {
	$loadClass(InputStream, name, initialize, &_InputStream_ClassInfo_, allocate$InputStream);
	return class$;
}

$Class* InputStream::class$ = nullptr;

	} // io
} // java