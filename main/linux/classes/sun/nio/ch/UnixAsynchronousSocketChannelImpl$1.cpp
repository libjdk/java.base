#include <sun/nio/ch/UnixAsynchronousSocketChannelImpl$1.h>

#include <java/nio/channels/AsynchronousChannel.h>
#include <java/nio/channels/CompletionHandler.h>
#include <java/nio/channels/InterruptedByTimeoutException.h>
#include <sun/nio/ch/Invoker.h>
#include <sun/nio/ch/PendingFuture.h>
#include <sun/nio/ch/UnixAsynchronousSocketChannelImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AsynchronousChannel = ::java::nio::channels::AsynchronousChannel;
using $CompletionHandler = ::java::nio::channels::CompletionHandler;
using $InterruptedByTimeoutException = ::java::nio::channels::InterruptedByTimeoutException;
using $Invoker = ::sun::nio::ch::Invoker;
using $PendingFuture = ::sun::nio::ch::PendingFuture;
using $UnixAsynchronousSocketChannelImpl = ::sun::nio::ch::UnixAsynchronousSocketChannelImpl;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _UnixAsynchronousSocketChannelImpl$1_FieldInfo_[] = {
	{"this$0", "Lsun/nio/ch/UnixAsynchronousSocketChannelImpl;", nullptr, $FINAL | $SYNTHETIC, $field(UnixAsynchronousSocketChannelImpl$1, this$0)},
	{}
};

$MethodInfo _UnixAsynchronousSocketChannelImpl$1_MethodInfo_[] = {
	{"<init>", "(Lsun/nio/ch/UnixAsynchronousSocketChannelImpl;)V", nullptr, 0, $method(UnixAsynchronousSocketChannelImpl$1, init$, void, $UnixAsynchronousSocketChannelImpl*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(UnixAsynchronousSocketChannelImpl$1, run, void)},
	{}
};

$EnclosingMethodInfo _UnixAsynchronousSocketChannelImpl$1_EnclosingMethodInfo_ = {
	"sun.nio.ch.UnixAsynchronousSocketChannelImpl",
	nullptr,
	nullptr
};

$InnerClassInfo _UnixAsynchronousSocketChannelImpl$1_InnerClassesInfo_[] = {
	{"sun.nio.ch.UnixAsynchronousSocketChannelImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _UnixAsynchronousSocketChannelImpl$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.UnixAsynchronousSocketChannelImpl$1",
	"java.lang.Object",
	"java.lang.Runnable",
	_UnixAsynchronousSocketChannelImpl$1_FieldInfo_,
	_UnixAsynchronousSocketChannelImpl$1_MethodInfo_,
	nullptr,
	&_UnixAsynchronousSocketChannelImpl$1_EnclosingMethodInfo_,
	_UnixAsynchronousSocketChannelImpl$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.ch.UnixAsynchronousSocketChannelImpl"
};

$Object* allocate$UnixAsynchronousSocketChannelImpl$1($Class* clazz) {
	return $of($alloc(UnixAsynchronousSocketChannelImpl$1));
}

void UnixAsynchronousSocketChannelImpl$1::init$($UnixAsynchronousSocketChannelImpl* this$0) {
	$set(this, this$0, this$0);
}

void UnixAsynchronousSocketChannelImpl$1::run() {
	$useLocalCurrentObjectStackCache();
	$var($CompletionHandler, handler, nullptr);
	$var($Object, att, nullptr);
	$var($PendingFuture, future, nullptr);
	$synchronized(this->this$0->updateLock) {
		if (!this->this$0->readPending) {
			return;
		}
		this->this$0->readPending = false;
		$assign(handler, this->this$0->readHandler);
		$assign(att, this->this$0->readAttachment);
		$assign(future, this->this$0->readFuture);
	}
	this->this$0->enableReading(true);
	$var($Exception, exc, $new($InterruptedByTimeoutException));
	if (handler == nullptr) {
		$nc(future)->setFailure(exc);
	} else {
		$var($AsynchronousChannel, ch, this->this$0);
		$Invoker::invokeIndirectly(ch, handler, att, ($Object*)nullptr, static_cast<$Throwable*>(exc));
	}
}

UnixAsynchronousSocketChannelImpl$1::UnixAsynchronousSocketChannelImpl$1() {
}

$Class* UnixAsynchronousSocketChannelImpl$1::load$($String* name, bool initialize) {
	$loadClass(UnixAsynchronousSocketChannelImpl$1, name, initialize, &_UnixAsynchronousSocketChannelImpl$1_ClassInfo_, allocate$UnixAsynchronousSocketChannelImpl$1);
	return class$;
}

$Class* UnixAsynchronousSocketChannelImpl$1::class$ = nullptr;

		} // ch
	} // nio
} // sun