#include <sun/nio/ch/SimpleAsynchronousFileChannelImpl$1.h>

#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/nio/channels/AsynchronousCloseException.h>
#include <java/nio/channels/CompletionHandler.h>
#include <sun/nio/ch/FileDispatcher.h>
#include <sun/nio/ch/FileLockImpl.h>
#include <sun/nio/ch/Invoker.h>
#include <sun/nio/ch/NativeThreadSet.h>
#include <sun/nio/ch/PendingFuture.h>
#include <sun/nio/ch/SimpleAsynchronousFileChannelImpl.h>
#include <jcpp.h>

#undef INTERRUPTED
#undef LOCKED

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AsynchronousCloseException = ::java::nio::channels::AsynchronousCloseException;
using $CompletionHandler = ::java::nio::channels::CompletionHandler;
using $FileDispatcher = ::sun::nio::ch::FileDispatcher;
using $FileLockImpl = ::sun::nio::ch::FileLockImpl;
using $Invoker = ::sun::nio::ch::Invoker;
using $NativeThreadSet = ::sun::nio::ch::NativeThreadSet;
using $PendingFuture = ::sun::nio::ch::PendingFuture;
using $SimpleAsynchronousFileChannelImpl = ::sun::nio::ch::SimpleAsynchronousFileChannelImpl;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _SimpleAsynchronousFileChannelImpl$1_FieldInfo_[] = {
	{"this$0", "Lsun/nio/ch/SimpleAsynchronousFileChannelImpl;", nullptr, $FINAL | $SYNTHETIC, $field(SimpleAsynchronousFileChannelImpl$1, this$0)},
	{"val$attachment", "Ljava/lang/Object;", nullptr, $FINAL | $SYNTHETIC, $field(SimpleAsynchronousFileChannelImpl$1, val$attachment)},
	{"val$result", "Lsun/nio/ch/PendingFuture;", nullptr, $FINAL | $SYNTHETIC, $field(SimpleAsynchronousFileChannelImpl$1, val$result)},
	{"val$handler", "Ljava/nio/channels/CompletionHandler;", nullptr, $FINAL | $SYNTHETIC, $field(SimpleAsynchronousFileChannelImpl$1, val$handler)},
	{"val$fli", "Lsun/nio/ch/FileLockImpl;", nullptr, $FINAL | $SYNTHETIC, $field(SimpleAsynchronousFileChannelImpl$1, val$fli)},
	{"val$shared", "Z", nullptr, $FINAL | $SYNTHETIC, $field(SimpleAsynchronousFileChannelImpl$1, val$shared)},
	{"val$size", "J", nullptr, $FINAL | $SYNTHETIC, $field(SimpleAsynchronousFileChannelImpl$1, val$size)},
	{"val$position", "J", nullptr, $FINAL | $SYNTHETIC, $field(SimpleAsynchronousFileChannelImpl$1, val$position)},
	{}
};

$MethodInfo _SimpleAsynchronousFileChannelImpl$1_MethodInfo_[] = {
	{"<init>", "(Lsun/nio/ch/SimpleAsynchronousFileChannelImpl;JJZLsun/nio/ch/FileLockImpl;Ljava/nio/channels/CompletionHandler;Lsun/nio/ch/PendingFuture;Ljava/lang/Object;)V", "()V", 0, $method(SimpleAsynchronousFileChannelImpl$1, init$, void, $SimpleAsynchronousFileChannelImpl*, int64_t, int64_t, bool, $FileLockImpl*, $CompletionHandler*, $PendingFuture*, Object$*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(SimpleAsynchronousFileChannelImpl$1, run, void)},
	{}
};

$EnclosingMethodInfo _SimpleAsynchronousFileChannelImpl$1_EnclosingMethodInfo_ = {
	"sun.nio.ch.SimpleAsynchronousFileChannelImpl",
	"implLock",
	"(JJZLjava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;"
};

$InnerClassInfo _SimpleAsynchronousFileChannelImpl$1_InnerClassesInfo_[] = {
	{"sun.nio.ch.SimpleAsynchronousFileChannelImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SimpleAsynchronousFileChannelImpl$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.SimpleAsynchronousFileChannelImpl$1",
	"java.lang.Object",
	"java.lang.Runnable",
	_SimpleAsynchronousFileChannelImpl$1_FieldInfo_,
	_SimpleAsynchronousFileChannelImpl$1_MethodInfo_,
	nullptr,
	&_SimpleAsynchronousFileChannelImpl$1_EnclosingMethodInfo_,
	_SimpleAsynchronousFileChannelImpl$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.ch.SimpleAsynchronousFileChannelImpl"
};

$Object* allocate$SimpleAsynchronousFileChannelImpl$1($Class* clazz) {
	return $of($alloc(SimpleAsynchronousFileChannelImpl$1));
}

void SimpleAsynchronousFileChannelImpl$1::init$($SimpleAsynchronousFileChannelImpl* this$0, int64_t val$position, int64_t val$size, bool val$shared, $FileLockImpl* val$fli, $CompletionHandler* val$handler, $PendingFuture* val$result, Object$* val$attachment) {
	$set(this, this$0, this$0);
	this->val$position = val$position;
	this->val$size = val$size;
	this->val$shared = val$shared;
	$set(this, val$fli, val$fli);
	$set(this, val$handler, val$handler);
	$set(this, val$result, val$result);
	$set(this, val$attachment, val$attachment);
}

void SimpleAsynchronousFileChannelImpl$1::run() {
	$useLocalCurrentObjectStackCache();
	$var($Throwable, exc, nullptr);
	int32_t ti = $nc(this->this$0->threads)->add();
	{
		$var($Throwable, var$0, nullptr);
		try {
			int32_t n = 0;
			{
				$var($Throwable, var$1, nullptr);
				try {
					try {
						this->this$0->begin();
						do {
							n = $nc($SimpleAsynchronousFileChannelImpl::nd)->lock(this->this$0->fdObj, true, this->val$position, this->val$size, this->val$shared);
						} while ((n == $FileDispatcher::INTERRUPTED) && this->this$0->isOpen());
						if (n != $FileDispatcher::LOCKED || !this->this$0->isOpen()) {
							$throwNew($AsynchronousCloseException);
						}
					} catch ($IOException& x) {
						this->this$0->removeFromFileLockTable(this->val$fli);
						if (!this->this$0->isOpen()) {
							$assign(x, $new($AsynchronousCloseException));
						}
						$assign(exc, x);
					}
				} catch ($Throwable& var$2) {
					$assign(var$1, var$2);
				} /*finally*/ {
					this->this$0->end();
				}
				if (var$1 != nullptr) {
					$throw(var$1);
				}
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} /*finally*/ {
			$nc(this->this$0->threads)->remove(ti);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	if (this->val$handler == nullptr) {
		$nc(this->val$result)->setResult(this->val$fli, exc);
	} else {
		$Invoker::invokeUnchecked(this->val$handler, this->val$attachment, this->val$fli, exc);
	}
}

SimpleAsynchronousFileChannelImpl$1::SimpleAsynchronousFileChannelImpl$1() {
}

$Class* SimpleAsynchronousFileChannelImpl$1::load$($String* name, bool initialize) {
	$loadClass(SimpleAsynchronousFileChannelImpl$1, name, initialize, &_SimpleAsynchronousFileChannelImpl$1_ClassInfo_, allocate$SimpleAsynchronousFileChannelImpl$1);
	return class$;
}

$Class* SimpleAsynchronousFileChannelImpl$1::class$ = nullptr;

		} // ch
	} // nio
} // sun