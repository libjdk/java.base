#include <java/util/concurrent/CompletableFuture$Timeout.h>

#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/TimeoutException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $TimeoutException = ::java::util::concurrent::TimeoutException;

namespace java {
	namespace util {
		namespace concurrent {

$FieldInfo _CompletableFuture$Timeout_FieldInfo_[] = {
	{"f", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<*>;", $FINAL, $field(CompletableFuture$Timeout, f)},
	{}
};

$MethodInfo _CompletableFuture$Timeout_MethodInfo_[] = {
	{"<init>", "(Ljava/util/concurrent/CompletableFuture;)V", "(Ljava/util/concurrent/CompletableFuture<*>;)V", 0, $method(CompletableFuture$Timeout, init$, void, $CompletableFuture*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(CompletableFuture$Timeout, run, void)},
	{}
};

$InnerClassInfo _CompletableFuture$Timeout_InnerClassesInfo_[] = {
	{"java.util.concurrent.CompletableFuture$Timeout", "java.util.concurrent.CompletableFuture", "Timeout", $STATIC | $FINAL},
	{}
};

$ClassInfo _CompletableFuture$Timeout_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.concurrent.CompletableFuture$Timeout",
	"java.lang.Object",
	"java.lang.Runnable",
	_CompletableFuture$Timeout_FieldInfo_,
	_CompletableFuture$Timeout_MethodInfo_,
	nullptr,
	nullptr,
	_CompletableFuture$Timeout_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.concurrent.CompletableFuture"
};

$Object* allocate$CompletableFuture$Timeout($Class* clazz) {
	return $of($alloc(CompletableFuture$Timeout));
}

void CompletableFuture$Timeout::init$($CompletableFuture* f) {
	$set(this, f, f);
}

void CompletableFuture$Timeout::run() {
	if (this->f != nullptr && !$nc(this->f)->isDone()) {
		$nc(this->f)->completeExceptionally($$new($TimeoutException));
	}
}

CompletableFuture$Timeout::CompletableFuture$Timeout() {
}

$Class* CompletableFuture$Timeout::load$($String* name, bool initialize) {
	$loadClass(CompletableFuture$Timeout, name, initialize, &_CompletableFuture$Timeout_ClassInfo_, allocate$CompletableFuture$Timeout);
	return class$;
}

$Class* CompletableFuture$Timeout::class$ = nullptr;

		} // concurrent
	} // util
} // java