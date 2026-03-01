#include <sun/nio/ch/CompletedFuture.h>

#include <java/io/IOException.h>
#include <java/lang/SecurityException.h>
#include <java/util/concurrent/ExecutionException.h>
#include <java/util/concurrent/TimeUnit.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $SecurityException = ::java::lang::SecurityException;
using $ExecutionException = ::java::util::concurrent::ExecutionException;
using $TimeUnit = ::java::util::concurrent::TimeUnit;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _CompletedFuture_FieldInfo_[] = {
	{"result", "Ljava/lang/Object;", "TV;", $PRIVATE | $FINAL, $field(CompletedFuture, result)},
	{"exc", "Ljava/lang/Throwable;", nullptr, $PRIVATE | $FINAL, $field(CompletedFuture, exc)},
	{}
};

$MethodInfo _CompletedFuture_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Object;Ljava/lang/Throwable;)V", "(TV;Ljava/lang/Throwable;)V", $PRIVATE, $method(CompletedFuture, init$, void, Object$*, $Throwable*)},
	{"cancel", "(Z)Z", nullptr, $PUBLIC, $virtualMethod(CompletedFuture, cancel, bool, bool)},
	{"get", "()Ljava/lang/Object;", "()TV;", $PUBLIC, $virtualMethod(CompletedFuture, get, $Object*), "java.util.concurrent.ExecutionException"},
	{"get", "(JLjava/util/concurrent/TimeUnit;)Ljava/lang/Object;", "(JLjava/util/concurrent/TimeUnit;)TV;", $PUBLIC, $virtualMethod(CompletedFuture, get, $Object*, int64_t, $TimeUnit*), "java.util.concurrent.ExecutionException"},
	{"isCancelled", "()Z", nullptr, $PUBLIC, $virtualMethod(CompletedFuture, isCancelled, bool)},
	{"isDone", "()Z", nullptr, $PUBLIC, $virtualMethod(CompletedFuture, isDone, bool)},
	{"withFailure", "(Ljava/lang/Throwable;)Lsun/nio/ch/CompletedFuture;", "<V:Ljava/lang/Object;>(Ljava/lang/Throwable;)Lsun/nio/ch/CompletedFuture<TV;>;", $STATIC, $staticMethod(CompletedFuture, withFailure, CompletedFuture*, $Throwable*)},
	{"withResult", "(Ljava/lang/Object;)Lsun/nio/ch/CompletedFuture;", "<V:Ljava/lang/Object;>(TV;)Lsun/nio/ch/CompletedFuture<TV;>;", $STATIC, $staticMethod(CompletedFuture, withResult, CompletedFuture*, Object$*)},
	{"withResult", "(Ljava/lang/Object;Ljava/lang/Throwable;)Lsun/nio/ch/CompletedFuture;", "<V:Ljava/lang/Object;>(TV;Ljava/lang/Throwable;)Lsun/nio/ch/CompletedFuture<TV;>;", $STATIC, $staticMethod(CompletedFuture, withResult, CompletedFuture*, Object$*, $Throwable*)},
	{}
};

$ClassInfo _CompletedFuture_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.nio.ch.CompletedFuture",
	"java.lang.Object",
	"java.util.concurrent.Future",
	_CompletedFuture_FieldInfo_,
	_CompletedFuture_MethodInfo_,
	"<V:Ljava/lang/Object;>Ljava/lang/Object;Ljava/util/concurrent/Future<TV;>;"
};

$Object* allocate$CompletedFuture($Class* clazz) {
	return $of($alloc(CompletedFuture));
}

void CompletedFuture::init$(Object$* result, $Throwable* exc) {
	$set(this, result, result);
	$set(this, exc, exc);
}

CompletedFuture* CompletedFuture::withResult(Object$* result) {
	$init(CompletedFuture);
	return $new(CompletedFuture, result, nullptr);
}

CompletedFuture* CompletedFuture::withFailure($Throwable* exc$renamed) {
	$init(CompletedFuture);
	$var($Throwable, exc, exc$renamed);
	if (!($instanceOf($IOException, exc)) && !($instanceOf($SecurityException, exc))) {
		$assign(exc, $new($IOException, exc));
	}
	return $new(CompletedFuture, nullptr, exc);
}

CompletedFuture* CompletedFuture::withResult(Object$* result, $Throwable* exc) {
	$init(CompletedFuture);
	if (exc == nullptr) {
		return withResult(result);
	} else {
		return withFailure(exc);
	}
}

$Object* CompletedFuture::get() {
	if (this->exc != nullptr) {
		$throwNew($ExecutionException, this->exc);
	}
	return $of(this->result);
}

$Object* CompletedFuture::get(int64_t timeout, $TimeUnit* unit) {
	if (unit == nullptr) {
		$throwNew($NullPointerException);
	}
	if (this->exc != nullptr) {
		$throwNew($ExecutionException, this->exc);
	}
	return $of(this->result);
}

bool CompletedFuture::isCancelled() {
	return false;
}

bool CompletedFuture::isDone() {
	return true;
}

bool CompletedFuture::cancel(bool mayInterruptIfRunning) {
	return false;
}

CompletedFuture::CompletedFuture() {
}

$Class* CompletedFuture::load$($String* name, bool initialize) {
	$loadClass(CompletedFuture, name, initialize, &_CompletedFuture_ClassInfo_, allocate$CompletedFuture);
	return class$;
}

$Class* CompletedFuture::class$ = nullptr;

		} // ch
	} // nio
} // sun