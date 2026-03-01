#include <sun/nio/ch/PendingFuture.h>

#include <java/io/IOException.h>
#include <java/lang/SecurityException.h>
#include <java/nio/channels/AsynchronousChannel.h>
#include <java/nio/channels/CompletionHandler.h>
#include <java/util/concurrent/CancellationException.h>
#include <java/util/concurrent/CountDownLatch.h>
#include <java/util/concurrent/ExecutionException.h>
#include <java/util/concurrent/Future.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/concurrent/TimeoutException.h>
#include <sun/nio/ch/Cancellable.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $AsynchronousChannel = ::java::nio::channels::AsynchronousChannel;
using $CompletionHandler = ::java::nio::channels::CompletionHandler;
using $CancellationException = ::java::util::concurrent::CancellationException;
using $CountDownLatch = ::java::util::concurrent::CountDownLatch;
using $ExecutionException = ::java::util::concurrent::ExecutionException;
using $Future = ::java::util::concurrent::Future;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $TimeoutException = ::java::util::concurrent::TimeoutException;
using $Cancellable = ::sun::nio::ch::Cancellable;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _PendingFuture_FieldInfo_[] = {
	{"channel", "Ljava/nio/channels/AsynchronousChannel;", nullptr, $PRIVATE | $FINAL, $field(PendingFuture, channel$)},
	{"handler", "Ljava/nio/channels/CompletionHandler;", "Ljava/nio/channels/CompletionHandler<TV;-TA;>;", $PRIVATE | $FINAL, $field(PendingFuture, handler$)},
	{"attachment", "Ljava/lang/Object;", "TA;", $PRIVATE | $FINAL, $field(PendingFuture, attachment$)},
	{"haveResult", "Z", nullptr, $PRIVATE | $VOLATILE, $field(PendingFuture, haveResult)},
	{"result", "Ljava/lang/Object;", "TV;", $PRIVATE | $VOLATILE, $field(PendingFuture, result)},
	{"exc", "Ljava/lang/Throwable;", nullptr, $PRIVATE | $VOLATILE, $field(PendingFuture, exc)},
	{"latch", "Ljava/util/concurrent/CountDownLatch;", nullptr, $PRIVATE, $field(PendingFuture, latch)},
	{"timeoutTask", "Ljava/util/concurrent/Future;", "Ljava/util/concurrent/Future<*>;", $PRIVATE, $field(PendingFuture, timeoutTask)},
	{"context", "Ljava/lang/Object;", nullptr, $PRIVATE | $VOLATILE, $field(PendingFuture, context)},
	{}
};

$MethodInfo _PendingFuture_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/channels/AsynchronousChannel;Ljava/nio/channels/CompletionHandler;Ljava/lang/Object;Ljava/lang/Object;)V", "(Ljava/nio/channels/AsynchronousChannel;Ljava/nio/channels/CompletionHandler<TV;-TA;>;TA;Ljava/lang/Object;)V", 0, $method(PendingFuture, init$, void, $AsynchronousChannel*, $CompletionHandler*, Object$*, Object$*)},
	{"<init>", "(Ljava/nio/channels/AsynchronousChannel;Ljava/nio/channels/CompletionHandler;Ljava/lang/Object;)V", "(Ljava/nio/channels/AsynchronousChannel;Ljava/nio/channels/CompletionHandler<TV;-TA;>;TA;)V", 0, $method(PendingFuture, init$, void, $AsynchronousChannel*, $CompletionHandler*, Object$*)},
	{"<init>", "(Ljava/nio/channels/AsynchronousChannel;)V", nullptr, 0, $method(PendingFuture, init$, void, $AsynchronousChannel*)},
	{"<init>", "(Ljava/nio/channels/AsynchronousChannel;Ljava/lang/Object;)V", nullptr, 0, $method(PendingFuture, init$, void, $AsynchronousChannel*, Object$*)},
	{"attachment", "()Ljava/lang/Object;", "()TA;", 0, $method(PendingFuture, attachment, $Object*)},
	{"cancel", "(Z)Z", nullptr, $PUBLIC, $virtualMethod(PendingFuture, cancel, bool, bool)},
	{"channel", "()Ljava/nio/channels/AsynchronousChannel;", nullptr, 0, $method(PendingFuture, channel, $AsynchronousChannel*)},
	{"exception", "()Ljava/lang/Throwable;", nullptr, 0, $method(PendingFuture, exception, $Throwable*)},
	{"get", "()Ljava/lang/Object;", "()TV;", $PUBLIC, $virtualMethod(PendingFuture, get, $Object*), "java.util.concurrent.ExecutionException,java.lang.InterruptedException"},
	{"get", "(JLjava/util/concurrent/TimeUnit;)Ljava/lang/Object;", "(JLjava/util/concurrent/TimeUnit;)TV;", $PUBLIC, $virtualMethod(PendingFuture, get, $Object*, int64_t, $TimeUnit*), "java.util.concurrent.ExecutionException,java.lang.InterruptedException,java.util.concurrent.TimeoutException"},
	{"getContext", "()Ljava/lang/Object;", nullptr, 0, $method(PendingFuture, getContext, $Object*)},
	{"handler", "()Ljava/nio/channels/CompletionHandler;", "()Ljava/nio/channels/CompletionHandler<TV;-TA;>;", 0, $method(PendingFuture, handler, $CompletionHandler*)},
	{"isCancelled", "()Z", nullptr, $PUBLIC, $virtualMethod(PendingFuture, isCancelled, bool)},
	{"isDone", "()Z", nullptr, $PUBLIC, $virtualMethod(PendingFuture, isDone, bool)},
	{"prepareForWait", "()Z", nullptr, $PRIVATE, $method(PendingFuture, prepareForWait, bool)},
	{"setContext", "(Ljava/lang/Object;)V", nullptr, 0, $method(PendingFuture, setContext, void, Object$*)},
	{"setFailure", "(Ljava/lang/Throwable;)V", nullptr, 0, $method(PendingFuture, setFailure, void, $Throwable*)},
	{"setResult", "(Ljava/lang/Object;)V", "(TV;)V", 0, $method(PendingFuture, setResult, void, Object$*)},
	{"setResult", "(Ljava/lang/Object;Ljava/lang/Throwable;)V", "(TV;Ljava/lang/Throwable;)V", 0, $method(PendingFuture, setResult, void, Object$*, $Throwable*)},
	{"setTimeoutTask", "(Ljava/util/concurrent/Future;)V", "(Ljava/util/concurrent/Future<*>;)V", 0, $method(PendingFuture, setTimeoutTask, void, $Future*)},
	{"value", "()Ljava/lang/Object;", "()TV;", 0, $method(PendingFuture, value, $Object*)},
	{}
};

$ClassInfo _PendingFuture_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.nio.ch.PendingFuture",
	"java.lang.Object",
	"java.util.concurrent.Future",
	_PendingFuture_FieldInfo_,
	_PendingFuture_MethodInfo_,
	"<V:Ljava/lang/Object;A:Ljava/lang/Object;>Ljava/lang/Object;Ljava/util/concurrent/Future<TV;>;"
};

$Object* allocate$PendingFuture($Class* clazz) {
	return $of($alloc(PendingFuture));
}

void PendingFuture::init$($AsynchronousChannel* channel, $CompletionHandler* handler, Object$* attachment, Object$* context) {
	$set(this, channel$, channel);
	$set(this, handler$, handler);
	$set(this, attachment$, attachment);
	$set(this, context, context);
}

void PendingFuture::init$($AsynchronousChannel* channel, $CompletionHandler* handler, Object$* attachment) {
	$set(this, channel$, channel);
	$set(this, handler$, handler);
	$set(this, attachment$, attachment);
}

void PendingFuture::init$($AsynchronousChannel* channel) {
	PendingFuture::init$(channel, nullptr, nullptr);
}

void PendingFuture::init$($AsynchronousChannel* channel, Object$* context) {
	PendingFuture::init$(channel, nullptr, nullptr, context);
}

$AsynchronousChannel* PendingFuture::channel() {
	return this->channel$;
}

$CompletionHandler* PendingFuture::handler() {
	return this->handler$;
}

$Object* PendingFuture::attachment() {
	return $of(this->attachment$);
}

void PendingFuture::setContext(Object$* context) {
	$set(this, context, context);
}

$Object* PendingFuture::getContext() {
	return $of(this->context);
}

void PendingFuture::setTimeoutTask($Future* task) {
	$synchronized(this) {
		if (this->haveResult) {
			$nc(task)->cancel(false);
		} else {
			$set(this, timeoutTask, task);
		}
	}
}

bool PendingFuture::prepareForWait() {
	$synchronized(this) {
		if (this->haveResult) {
			return false;
		} else {
			if (this->latch == nullptr) {
				$set(this, latch, $new($CountDownLatch, 1));
			}
			return true;
		}
	}
}

void PendingFuture::setResult(Object$* res) {
	$synchronized(this) {
		if (this->haveResult) {
			return;
		}
		$set(this, result, res);
		this->haveResult = true;
		if (this->timeoutTask != nullptr) {
			$nc(this->timeoutTask)->cancel(false);
		}
		if (this->latch != nullptr) {
			$nc(this->latch)->countDown();
		}
	}
}

void PendingFuture::setFailure($Throwable* x$renamed) {
	$var($Throwable, x, x$renamed);
	if (!($instanceOf($IOException, x)) && !($instanceOf($SecurityException, x))) {
		$assign(x, $new($IOException, x));
	}
	$synchronized(this) {
		if (this->haveResult) {
			return;
		}
		$set(this, exc, x);
		this->haveResult = true;
		if (this->timeoutTask != nullptr) {
			$nc(this->timeoutTask)->cancel(false);
		}
		if (this->latch != nullptr) {
			$nc(this->latch)->countDown();
		}
	}
}

void PendingFuture::setResult(Object$* res, $Throwable* x) {
	if (x == nullptr) {
		setResult(res);
	} else {
		setFailure(x);
	}
}

$Object* PendingFuture::get() {
	if (!this->haveResult) {
		bool needToWait = prepareForWait();
		if (needToWait) {
			$nc(this->latch)->await();
		}
	}
	if (this->exc != nullptr) {
		if ($instanceOf($CancellationException, this->exc)) {
			$throwNew($CancellationException);
		}
		$throwNew($ExecutionException, this->exc);
	}
	return $of(this->result);
}

$Object* PendingFuture::get(int64_t timeout, $TimeUnit* unit) {
	if (!this->haveResult) {
		bool needToWait = prepareForWait();
		if (needToWait) {
			if (!$nc(this->latch)->await(timeout, unit)) {
				$throwNew($TimeoutException);
			}
		}
	}
	if (this->exc != nullptr) {
		if ($instanceOf($CancellationException, this->exc)) {
			$throwNew($CancellationException);
		}
		$throwNew($ExecutionException, this->exc);
	}
	return $of(this->result);
}

$Throwable* PendingFuture::exception() {
	return ($instanceOf($CancellationException, this->exc)) ? ($Throwable*)nullptr : $cast($Throwable, this->exc);
}

$Object* PendingFuture::value() {
	return $of(this->result);
}

bool PendingFuture::isCancelled() {
	return ($instanceOf($CancellationException, this->exc));
}

bool PendingFuture::isDone() {
	return this->haveResult;
}

bool PendingFuture::cancel(bool mayInterruptIfRunning) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this) {
		if (this->haveResult) {
			return false;
		}
		if ($instanceOf($Cancellable, $(channel()))) {
			$nc(($cast($Cancellable, $(channel()))))->onCancel(this);
		}
		$set(this, exc, $new($CancellationException));
		this->haveResult = true;
		if (this->timeoutTask != nullptr) {
			$nc(this->timeoutTask)->cancel(false);
		}
	}
	if (mayInterruptIfRunning) {
		try {
			$nc($(channel()))->close();
		} catch ($IOException& ignore) {
		}
	}
	if (this->latch != nullptr) {
		$nc(this->latch)->countDown();
	}
	return true;
}

PendingFuture::PendingFuture() {
}

$Class* PendingFuture::load$($String* name, bool initialize) {
	$loadClass(PendingFuture, name, initialize, &_PendingFuture_ClassInfo_, allocate$PendingFuture);
	return class$;
}

$Class* PendingFuture::class$ = nullptr;

		} // ch
	} // nio
} // sun