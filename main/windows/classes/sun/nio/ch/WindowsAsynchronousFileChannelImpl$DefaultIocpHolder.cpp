#include <sun/nio/ch/WindowsAsynchronousFileChannelImpl$DefaultIocpHolder.h>

#include <java/io/IOException.h>
#include <java/lang/InternalError.h>
#include <java/nio/channels/spi/AsynchronousChannelProvider.h>
#include <sun/nio/ch/Iocp.h>
#include <sun/nio/ch/ThreadPool.h>
#include <sun/nio/ch/WindowsAsynchronousFileChannelImpl.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $AsynchronousChannelProvider = ::java::nio::channels::spi::AsynchronousChannelProvider;
using $Iocp = ::sun::nio::ch::Iocp;
using $ThreadPool = ::sun::nio::ch::ThreadPool;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _WindowsAsynchronousFileChannelImpl$DefaultIocpHolder_FieldInfo_[] = {
	{"defaultIocp", "Lsun/nio/ch/Iocp;", nullptr, $STATIC | $FINAL, $staticField(WindowsAsynchronousFileChannelImpl$DefaultIocpHolder, defaultIocp$)},
	{}
};

$MethodInfo _WindowsAsynchronousFileChannelImpl$DefaultIocpHolder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(WindowsAsynchronousFileChannelImpl$DefaultIocpHolder, init$, void)},
	{"defaultIocp", "()Lsun/nio/ch/Iocp;", nullptr, $PRIVATE | $STATIC, $staticMethod(WindowsAsynchronousFileChannelImpl$DefaultIocpHolder, defaultIocp, $Iocp*)},
	{}
};

$InnerClassInfo _WindowsAsynchronousFileChannelImpl$DefaultIocpHolder_InnerClassesInfo_[] = {
	{"sun.nio.ch.WindowsAsynchronousFileChannelImpl$DefaultIocpHolder", "sun.nio.ch.WindowsAsynchronousFileChannelImpl", "DefaultIocpHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _WindowsAsynchronousFileChannelImpl$DefaultIocpHolder_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.WindowsAsynchronousFileChannelImpl$DefaultIocpHolder",
	"java.lang.Object",
	nullptr,
	_WindowsAsynchronousFileChannelImpl$DefaultIocpHolder_FieldInfo_,
	_WindowsAsynchronousFileChannelImpl$DefaultIocpHolder_MethodInfo_,
	nullptr,
	nullptr,
	_WindowsAsynchronousFileChannelImpl$DefaultIocpHolder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.ch.WindowsAsynchronousFileChannelImpl"
};

$Object* allocate$WindowsAsynchronousFileChannelImpl$DefaultIocpHolder($Class* clazz) {
	return $of($alloc(WindowsAsynchronousFileChannelImpl$DefaultIocpHolder));
}

$Iocp* WindowsAsynchronousFileChannelImpl$DefaultIocpHolder::defaultIocp$ = nullptr;

void WindowsAsynchronousFileChannelImpl$DefaultIocpHolder::init$() {
}

$Iocp* WindowsAsynchronousFileChannelImpl$DefaultIocpHolder::defaultIocp() {
	$init(WindowsAsynchronousFileChannelImpl$DefaultIocpHolder);
	$useLocalCurrentObjectStackCache();
	try {
		return $$new($Iocp, nullptr, $($ThreadPool::createDefault()))->start();
	} catch ($IOException& ioe) {
		$throwNew($InternalError, static_cast<$Throwable*>(ioe));
	}
	$shouldNotReachHere();
}

void clinit$WindowsAsynchronousFileChannelImpl$DefaultIocpHolder($Class* class$) {
	$assignStatic(WindowsAsynchronousFileChannelImpl$DefaultIocpHolder::defaultIocp$, WindowsAsynchronousFileChannelImpl$DefaultIocpHolder::defaultIocp());
}

WindowsAsynchronousFileChannelImpl$DefaultIocpHolder::WindowsAsynchronousFileChannelImpl$DefaultIocpHolder() {
}

$Class* WindowsAsynchronousFileChannelImpl$DefaultIocpHolder::load$($String* name, bool initialize) {
	$loadClass(WindowsAsynchronousFileChannelImpl$DefaultIocpHolder, name, initialize, &_WindowsAsynchronousFileChannelImpl$DefaultIocpHolder_ClassInfo_, clinit$WindowsAsynchronousFileChannelImpl$DefaultIocpHolder, allocate$WindowsAsynchronousFileChannelImpl$DefaultIocpHolder);
	return class$;
}

$Class* WindowsAsynchronousFileChannelImpl$DefaultIocpHolder::class$ = nullptr;

		} // ch
	} // nio
} // sun