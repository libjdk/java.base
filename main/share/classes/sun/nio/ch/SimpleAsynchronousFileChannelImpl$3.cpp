#include <sun/nio/ch/SimpleAsynchronousFileChannelImpl$3.h>

#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/AsynchronousCloseException.h>
#include <java/nio/channels/CompletionHandler.h>
#include <sun/nio/ch/FileDispatcher.h>
#include <sun/nio/ch/IOStatus.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/nio/ch/Invoker.h>
#include <sun/nio/ch/NativeDispatcher.h>
#include <sun/nio/ch/NativeThreadSet.h>
#include <sun/nio/ch/PendingFuture.h>
#include <sun/nio/ch/SimpleAsynchronousFileChannelImpl.h>
#include <jcpp.h>

#undef INTERRUPTED

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AsynchronousCloseException = ::java::nio::channels::AsynchronousCloseException;
using $CompletionHandler = ::java::nio::channels::CompletionHandler;
using $IOStatus = ::sun::nio::ch::IOStatus;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $Invoker = ::sun::nio::ch::Invoker;
using $NativeDispatcher = ::sun::nio::ch::NativeDispatcher;
using $NativeThreadSet = ::sun::nio::ch::NativeThreadSet;
using $PendingFuture = ::sun::nio::ch::PendingFuture;
using $SimpleAsynchronousFileChannelImpl = ::sun::nio::ch::SimpleAsynchronousFileChannelImpl;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _SimpleAsynchronousFileChannelImpl$3_FieldInfo_[] = {
	{"this$0", "Lsun/nio/ch/SimpleAsynchronousFileChannelImpl;", nullptr, $FINAL | $SYNTHETIC, $field(SimpleAsynchronousFileChannelImpl$3, this$0)},
	{"val$attachment", "Ljava/lang/Object;", nullptr, $FINAL | $SYNTHETIC, $field(SimpleAsynchronousFileChannelImpl$3, val$attachment)},
	{"val$result", "Lsun/nio/ch/PendingFuture;", nullptr, $FINAL | $SYNTHETIC, $field(SimpleAsynchronousFileChannelImpl$3, val$result)},
	{"val$handler", "Ljava/nio/channels/CompletionHandler;", nullptr, $FINAL | $SYNTHETIC, $field(SimpleAsynchronousFileChannelImpl$3, val$handler)},
	{"val$position", "J", nullptr, $FINAL | $SYNTHETIC, $field(SimpleAsynchronousFileChannelImpl$3, val$position)},
	{"val$src", "Ljava/nio/ByteBuffer;", nullptr, $FINAL | $SYNTHETIC, $field(SimpleAsynchronousFileChannelImpl$3, val$src)},
	{}
};

$MethodInfo _SimpleAsynchronousFileChannelImpl$3_MethodInfo_[] = {
	{"<init>", "(Lsun/nio/ch/SimpleAsynchronousFileChannelImpl;Ljava/nio/ByteBuffer;JLjava/nio/channels/CompletionHandler;Lsun/nio/ch/PendingFuture;Ljava/lang/Object;)V", "()V", 0, $method(SimpleAsynchronousFileChannelImpl$3, init$, void, $SimpleAsynchronousFileChannelImpl*, $ByteBuffer*, int64_t, $CompletionHandler*, $PendingFuture*, Object$*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(SimpleAsynchronousFileChannelImpl$3, run, void)},
	{}
};

$EnclosingMethodInfo _SimpleAsynchronousFileChannelImpl$3_EnclosingMethodInfo_ = {
	"sun.nio.ch.SimpleAsynchronousFileChannelImpl",
	"implWrite",
	"(Ljava/nio/ByteBuffer;JLjava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;"
};

$InnerClassInfo _SimpleAsynchronousFileChannelImpl$3_InnerClassesInfo_[] = {
	{"sun.nio.ch.SimpleAsynchronousFileChannelImpl$3", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SimpleAsynchronousFileChannelImpl$3_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.SimpleAsynchronousFileChannelImpl$3",
	"java.lang.Object",
	"java.lang.Runnable",
	_SimpleAsynchronousFileChannelImpl$3_FieldInfo_,
	_SimpleAsynchronousFileChannelImpl$3_MethodInfo_,
	nullptr,
	&_SimpleAsynchronousFileChannelImpl$3_EnclosingMethodInfo_,
	_SimpleAsynchronousFileChannelImpl$3_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.ch.SimpleAsynchronousFileChannelImpl"
};

$Object* allocate$SimpleAsynchronousFileChannelImpl$3($Class* clazz) {
	return $of($alloc(SimpleAsynchronousFileChannelImpl$3));
}

void SimpleAsynchronousFileChannelImpl$3::init$($SimpleAsynchronousFileChannelImpl* this$0, $ByteBuffer* val$src, int64_t val$position, $CompletionHandler* val$handler, $PendingFuture* val$result, Object$* val$attachment) {
	$set(this, this$0, this$0);
	$set(this, val$src, val$src);
	this->val$position = val$position;
	$set(this, val$handler, val$handler);
	$set(this, val$result, val$result);
	$set(this, val$attachment, val$attachment);
}

void SimpleAsynchronousFileChannelImpl$3::run() {
	$useLocalCurrentObjectStackCache();
	int32_t n = 0;
	$var($Throwable, exc, nullptr);
	int32_t ti = $nc(this->this$0->threads)->add();
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				this->this$0->begin();
				do {
					n = $IOUtil::write(this->this$0->fdObj, this->val$src, this->val$position, static_cast<$NativeDispatcher*>($SimpleAsynchronousFileChannelImpl::nd));
				} while ((n == $IOStatus::INTERRUPTED) && this->this$0->isOpen());
				if (n < 0 && !this->this$0->isOpen()) {
					$throwNew($AsynchronousCloseException);
				}
			} catch ($IOException& x) {
				if (!this->this$0->isOpen()) {
					$assign(x, $new($AsynchronousCloseException));
				}
				$assign(exc, x);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			this->this$0->end();
			$nc(this->this$0->threads)->remove(ti);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	if (this->val$handler == nullptr) {
		$nc(this->val$result)->setResult($($Integer::valueOf(n)), exc);
	} else {
		$Invoker::invokeUnchecked(this->val$handler, this->val$attachment, $($Integer::valueOf(n)), exc);
	}
}

SimpleAsynchronousFileChannelImpl$3::SimpleAsynchronousFileChannelImpl$3() {
}

$Class* SimpleAsynchronousFileChannelImpl$3::load$($String* name, bool initialize) {
	$loadClass(SimpleAsynchronousFileChannelImpl$3, name, initialize, &_SimpleAsynchronousFileChannelImpl$3_ClassInfo_, allocate$SimpleAsynchronousFileChannelImpl$3);
	return class$;
}

$Class* SimpleAsynchronousFileChannelImpl$3::class$ = nullptr;

		} // ch
	} // nio
} // sun