#include <java/lang/ProcessImpl$ProcessPipeInputStream.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/ByteArrayInputStream.h>
#include <java/io/FileDescriptor.h>
#include <java/io/FilterInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/lang/Process$PipeInputStream.h>
#include <java/lang/ProcessBuilder$NullInputStream.h>
#include <java/lang/ProcessImpl.h>
#include <java/util/Arrays.h>
#include <jcpp.h>

#undef INSTANCE

using $BufferedInputStream = ::java::io::BufferedInputStream;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Process$PipeInputStream = ::java::lang::Process$PipeInputStream;
using $ProcessBuilder$NullInputStream = ::java::lang::ProcessBuilder$NullInputStream;
using $ProcessImpl = ::java::lang::ProcessImpl;
using $Arrays = ::java::util::Arrays;

namespace java {
	namespace lang {

$FieldInfo _ProcessImpl$ProcessPipeInputStream_FieldInfo_[] = {
	{"closeLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(ProcessImpl$ProcessPipeInputStream, closeLock)},
	{}
};

$MethodInfo _ProcessImpl$ProcessPipeInputStream_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, 0, $method(ProcessImpl$ProcessPipeInputStream, init$, void, int32_t)},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(ProcessImpl$ProcessPipeInputStream, close, void), "java.io.IOException"},
	{"drainInputStream", "(Ljava/io/InputStream;)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(ProcessImpl$ProcessPipeInputStream, drainInputStream, $bytes*, $InputStream*), "java.io.IOException"},
	{"processExited", "()V", nullptr, $SYNCHRONIZED, $virtualMethod(ProcessImpl$ProcessPipeInputStream, processExited, void)},
	{}
};

$InnerClassInfo _ProcessImpl$ProcessPipeInputStream_InnerClassesInfo_[] = {
	{"java.lang.ProcessImpl$ProcessPipeInputStream", "java.lang.ProcessImpl", "ProcessPipeInputStream", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _ProcessImpl$ProcessPipeInputStream_ClassInfo_ = {
	$ACC_SUPER,
	"java.lang.ProcessImpl$ProcessPipeInputStream",
	"java.io.BufferedInputStream",
	nullptr,
	_ProcessImpl$ProcessPipeInputStream_FieldInfo_,
	_ProcessImpl$ProcessPipeInputStream_MethodInfo_,
	nullptr,
	nullptr,
	_ProcessImpl$ProcessPipeInputStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.ProcessImpl"
};

$Object* allocate$ProcessImpl$ProcessPipeInputStream($Class* clazz) {
	return $of($alloc(ProcessImpl$ProcessPipeInputStream));
}

void ProcessImpl$ProcessPipeInputStream::init$(int32_t fd) {
	$useLocalCurrentObjectStackCache();
	$BufferedInputStream::init$($$new($Process$PipeInputStream, $($ProcessImpl::newFileDescriptor(fd))));
	$set(this, closeLock, $new($Object));
}

$bytes* ProcessImpl$ProcessPipeInputStream::drainInputStream($InputStream* in) {
	$init(ProcessImpl$ProcessPipeInputStream);
	int32_t n = 0;
	int32_t j = 0;
	$var($bytes, a, nullptr);
	while ((j = $nc(in)->available()) > 0) {
		$assign(a, (a == nullptr) ? $new($bytes, j) : $Arrays::copyOf(a, n + j));
		n += in->read(a, n, j);
	}
	return (a == nullptr || n == $nc(a)->length) ? a : $Arrays::copyOf(a, n);
}

void ProcessImpl$ProcessPipeInputStream::processExited() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$synchronized(this->closeLock) {
			try {
				$var($InputStream, in, this->in);
				if (in != nullptr) {
					$var($bytes, stragglers, drainInputStream(in));
					in->close();
					$init($ProcessBuilder$NullInputStream);
					$set(this, in, (stragglers == nullptr) ? static_cast<$InputStream*>($ProcessBuilder$NullInputStream::INSTANCE) : static_cast<$InputStream*>($new($ByteArrayInputStream, stragglers)));
				}
			} catch ($IOException& ignored) {
			}
		}
	}
}

void ProcessImpl$ProcessPipeInputStream::close() {
	$synchronized(this->closeLock) {
		$BufferedInputStream::close();
	}
}

ProcessImpl$ProcessPipeInputStream::ProcessImpl$ProcessPipeInputStream() {
}

$Class* ProcessImpl$ProcessPipeInputStream::load$($String* name, bool initialize) {
	$loadClass(ProcessImpl$ProcessPipeInputStream, name, initialize, &_ProcessImpl$ProcessPipeInputStream_ClassInfo_, allocate$ProcessImpl$ProcessPipeInputStream);
	return class$;
}

$Class* ProcessImpl$ProcessPipeInputStream::class$ = nullptr;

	} // lang
} // java