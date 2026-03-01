#include <sun/security/provider/NativePRNG$RandomIO.h>

#include <java/io/EOFException.h>
#include <java/io/File.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/ProviderException.h>
#include <java/util/Arrays.h>
#include <sun/security/provider/FileInputStreamPool.h>
#include <sun/security/provider/NativePRNG$RandomIO$1.h>
#include <sun/security/provider/NativePRNG.h>
#include <sun/security/provider/SecureRandom.h>
#include <sun/security/util/Debug.h>
#include <jcpp.h>

#undef LOCK_GET_BYTES
#undef LOCK_GET_SEED
#undef LOCK_SET_SEED
#undef MAX_BUFFER_SIZE
#undef MAX_BUFFER_TIME
#undef MIN_BUFFER_SIZE
#undef REQ_LIMIT_DEC
#undef REQ_LIMIT_INC

using $EOFException = ::java::io::EOFException;
using $File = ::java::io::File;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ProviderException = ::java::security::ProviderException;
using $Arrays = ::java::util::Arrays;
using $FileInputStreamPool = ::sun::security::provider::FileInputStreamPool;
using $NativePRNG = ::sun::security::provider::NativePRNG;
using $NativePRNG$RandomIO$1 = ::sun::security::provider::NativePRNG$RandomIO$1;
using $SecureRandom = ::sun::security::provider::SecureRandom;
using $Debug = ::sun::security::util::Debug;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _NativePRNG$RandomIO_FieldInfo_[] = {
	{"MAX_BUFFER_TIME", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NativePRNG$RandomIO, MAX_BUFFER_TIME)},
	{"MAX_BUFFER_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NativePRNG$RandomIO, MAX_BUFFER_SIZE)},
	{"MIN_BUFFER_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NativePRNG$RandomIO, MIN_BUFFER_SIZE)},
	{"bufferSize", "I", nullptr, $PRIVATE, $field(NativePRNG$RandomIO, bufferSize)},
	{"seedFile", "Ljava/io/File;", nullptr, 0, $field(NativePRNG$RandomIO, seedFile)},
	{"seedIn", "Ljava/io/InputStream;", nullptr, $PRIVATE | $FINAL, $field(NativePRNG$RandomIO, seedIn)},
	{"nextIn", "Ljava/io/InputStream;", nullptr, $PRIVATE | $FINAL, $field(NativePRNG$RandomIO, nextIn)},
	{"seedOut", "Ljava/io/OutputStream;", nullptr, $PRIVATE, $field(NativePRNG$RandomIO, seedOut)},
	{"seedOutInitialized", "Z", nullptr, $PRIVATE, $field(NativePRNG$RandomIO, seedOutInitialized)},
	{"mixRandom", "Lsun/security/provider/SecureRandom;", nullptr, $PRIVATE | $VOLATILE, $field(NativePRNG$RandomIO, mixRandom)},
	{"nextBuffer", "[B", nullptr, $PRIVATE, $field(NativePRNG$RandomIO, nextBuffer)},
	{"buffered", "I", nullptr, $PRIVATE, $field(NativePRNG$RandomIO, buffered)},
	{"lastRead", "J", nullptr, $PRIVATE, $field(NativePRNG$RandomIO, lastRead)},
	{"change_buffer", "I", nullptr, $PRIVATE, $field(NativePRNG$RandomIO, change_buffer)},
	{"REQ_LIMIT_INC", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NativePRNG$RandomIO, REQ_LIMIT_INC)},
	{"REQ_LIMIT_DEC", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NativePRNG$RandomIO, REQ_LIMIT_DEC)},
	{"LOCK_GET_BYTES", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(NativePRNG$RandomIO, LOCK_GET_BYTES)},
	{"LOCK_GET_SEED", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(NativePRNG$RandomIO, LOCK_GET_SEED)},
	{"LOCK_SET_SEED", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(NativePRNG$RandomIO, LOCK_SET_SEED)},
	{}
};

$MethodInfo _NativePRNG$RandomIO_MethodInfo_[] = {
	{"<init>", "(Ljava/io/File;Ljava/io/File;)V", nullptr, $PRIVATE, $method(NativePRNG$RandomIO, init$, void, $File*, $File*), "java.io.IOException"},
	{"ensureBufferValid", "()V", nullptr, $PRIVATE, $method(NativePRNG$RandomIO, ensureBufferValid, void), "java.io.IOException"},
	{"getMixRandom", "()Lsun/security/provider/SecureRandom;", nullptr, $PRIVATE, $method(NativePRNG$RandomIO, getMixRandom, $SecureRandom*)},
	{"implGenerateSeed", "(I)[B", nullptr, $PRIVATE, $method(NativePRNG$RandomIO, implGenerateSeed, $bytes*, int32_t)},
	{"implNextBytes", "([B)V", nullptr, $PRIVATE, $method(NativePRNG$RandomIO, implNextBytes, void, $bytes*)},
	{"implSetSeed", "([B)V", nullptr, $PRIVATE, $method(NativePRNG$RandomIO, implSetSeed, void, $bytes*)},
	{"readFully", "(Ljava/io/InputStream;[B)V", nullptr, $PRIVATE | $STATIC, $staticMethod(NativePRNG$RandomIO, readFully, void, $InputStream*, $bytes*), "java.io.IOException"},
	{}
};

$InnerClassInfo _NativePRNG$RandomIO_InnerClassesInfo_[] = {
	{"sun.security.provider.NativePRNG$RandomIO", "sun.security.provider.NativePRNG", "RandomIO", $PRIVATE | $STATIC},
	{"sun.security.provider.NativePRNG$RandomIO$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _NativePRNG$RandomIO_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.provider.NativePRNG$RandomIO",
	"java.lang.Object",
	nullptr,
	_NativePRNG$RandomIO_FieldInfo_,
	_NativePRNG$RandomIO_MethodInfo_,
	nullptr,
	nullptr,
	_NativePRNG$RandomIO_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.provider.NativePRNG"
};

$Object* allocate$NativePRNG$RandomIO($Class* clazz) {
	return $of($alloc(NativePRNG$RandomIO));
}

void NativePRNG$RandomIO::init$($File* seedFile, $File* nextFile) {
	this->bufferSize = 256;
	this->change_buffer = 0;
	$set(this, LOCK_GET_BYTES, $new($Object));
	$set(this, LOCK_GET_SEED, $new($Object));
	$set(this, LOCK_SET_SEED, $new($Object));
	$set(this, seedFile, seedFile);
	$set(this, seedIn, $FileInputStreamPool::getInputStream(seedFile));
	$set(this, nextIn, $FileInputStreamPool::getInputStream(nextFile));
	$set(this, nextBuffer, $new($bytes, this->bufferSize));
}

$SecureRandom* NativePRNG$RandomIO::getMixRandom() {
	$useLocalCurrentObjectStackCache();
	$var($SecureRandom, r, this->mixRandom);
	if (r == nullptr) {
		$synchronized(this->LOCK_GET_BYTES) {
			$assign(r, this->mixRandom);
			if (r == nullptr) {
				$assign(r, $new($SecureRandom));
				try {
					$var($bytes, b, $new($bytes, 20));
					readFully(this->nextIn, b);
					r->engineSetSeed(b);
				} catch ($IOException& e) {
					$throwNew($ProviderException, "init failed"_s, e);
				}
				$set(this, mixRandom, r);
			}
		}
	}
	return r;
}

void NativePRNG$RandomIO::readFully($InputStream* in, $bytes* data) {
	int32_t len = $nc(data)->length;
	int32_t ofs = 0;
	while (len > 0) {
		int32_t k = $nc(in)->read(data, ofs, len);
		if (k <= 0) {
			$throwNew($EOFException, "File(s) closed?"_s);
		}
		ofs += k;
		len -= k;
	}
	if (len > 0) {
		$throwNew($IOException, "Could not read from file(s)"_s);
	}
}

$bytes* NativePRNG$RandomIO::implGenerateSeed(int32_t numBytes) {
	$synchronized(this->LOCK_GET_SEED) {
		try {
			$var($bytes, b, $new($bytes, numBytes));
			readFully(this->seedIn, b);
			return b;
		} catch ($IOException& e) {
			$throwNew($ProviderException, "generateSeed() failed"_s, e);
		}
	}
	$shouldNotReachHere();
}

void NativePRNG$RandomIO::implSetSeed($bytes* seed) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$synchronized(this->LOCK_SET_SEED) {
		if (this->seedOutInitialized == false) {
			this->seedOutInitialized = true;
			$set(this, seedOut, $cast($OutputStream, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($NativePRNG$RandomIO$1, this)))));
		}
		if (this->seedOut != nullptr) {
			try {
				$nc(this->seedOut)->write(seed);
			} catch ($IOException& e) {
			}
		}
		$nc($(getMixRandom()))->engineSetSeed(seed);
	}
}

void NativePRNG$RandomIO::ensureBufferValid() {
	$useLocalCurrentObjectStackCache();
	int64_t time = $System::currentTimeMillis();
	int32_t new_buffer_size = 0;
	if (this->buffered > 0) {
		if (time - this->lastRead < NativePRNG$RandomIO::MAX_BUFFER_TIME) {
			return;
		} else {
			--this->change_buffer;
		}
	} else {
		++this->change_buffer;
	}
	if (this->change_buffer > NativePRNG$RandomIO::REQ_LIMIT_INC) {
		new_buffer_size = $nc(this->nextBuffer)->length * 2;
	} else if (this->change_buffer < NativePRNG$RandomIO::REQ_LIMIT_DEC) {
		new_buffer_size = $nc(this->nextBuffer)->length / 2;
	}
	if (new_buffer_size > 0) {
		if (new_buffer_size <= NativePRNG$RandomIO::MAX_BUFFER_SIZE && new_buffer_size >= NativePRNG$RandomIO::MIN_BUFFER_SIZE) {
			$set(this, nextBuffer, $new($bytes, new_buffer_size));
			$init($NativePRNG);
			if ($NativePRNG::debug != nullptr) {
				$nc($NativePRNG::debug)->println($$str({"Buffer size changed to "_s, $$str(new_buffer_size)}));
			}
		} else {
			$init($NativePRNG);
			if ($NativePRNG::debug != nullptr) {
				$nc($NativePRNG::debug)->println($$str({"Buffer reached limit: "_s, $$str($nc(this->nextBuffer)->length)}));
			}
		}
		this->change_buffer = 0;
	}
	this->lastRead = time;
	readFully(this->nextIn, this->nextBuffer);
	this->buffered = $nc(this->nextBuffer)->length;
}

void NativePRNG$RandomIO::implNextBytes($bytes* data) {
	$useLocalCurrentObjectStackCache();
	try {
		$nc($(getMixRandom()))->engineNextBytes(data);
		int32_t data_len = $nc(data)->length;
		int32_t ofs = 0;
		int32_t len = 0;
		int32_t buf_pos = 0;
		int32_t localofs = 0;
		$var($bytes, localBuffer, nullptr);
		while (data_len > 0) {
			$synchronized(this->LOCK_GET_BYTES) {
				ensureBufferValid();
				buf_pos = $nc(this->nextBuffer)->length - this->buffered;
				if (data_len > this->buffered) {
					len = this->buffered;
					this->buffered = 0;
				} else {
					len = data_len;
					this->buffered -= len;
				}
				$assign(localBuffer, $Arrays::copyOfRange(this->nextBuffer, buf_pos, buf_pos + len));
			}
			localofs = 0;
			while (len > localofs) {
				(*data)[ofs] ^= $nc(localBuffer)->get(localofs);
				++ofs;
				++localofs;
			}
			data_len -= len;
		}
	} catch ($IOException& e) {
		$throwNew($ProviderException, "nextBytes() failed"_s, e);
	}
}

NativePRNG$RandomIO::NativePRNG$RandomIO() {
}

$Class* NativePRNG$RandomIO::load$($String* name, bool initialize) {
	$loadClass(NativePRNG$RandomIO, name, initialize, &_NativePRNG$RandomIO_ClassInfo_, allocate$NativePRNG$RandomIO);
	return class$;
}

$Class* NativePRNG$RandomIO::class$ = nullptr;

		} // provider
	} // security
} // sun