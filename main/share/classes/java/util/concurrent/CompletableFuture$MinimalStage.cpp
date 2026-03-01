#include <java/util/concurrent/CompletableFuture$MinimalStage.h>

#include <java/lang/Runnable.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/util/concurrent/CompletableFuture$Completion.h>
#include <java/util/concurrent/CompletableFuture$UniRelay.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Supplier.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletableFuture$Completion = ::java::util::concurrent::CompletableFuture$Completion;
using $CompletableFuture$UniRelay = ::java::util::concurrent::CompletableFuture$UniRelay;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $Executor = ::java::util::concurrent::Executor;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiFunction = ::java::util::function::BiFunction;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Supplier = ::java::util::function::Supplier;

namespace java {
	namespace util {
		namespace concurrent {

$MethodInfo _CompletableFuture$MinimalStage_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(CompletableFuture$MinimalStage, init$, void)},
	{"<init>", "(Ljava/lang/Object;)V", nullptr, 0, $method(CompletableFuture$MinimalStage, init$, void, Object$*)},
	{"acceptEither", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/Consumer;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, acceptEither, $CompletionStage*, $CompletionStage*, $Consumer*)},
	{"acceptEitherAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/Consumer;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, acceptEitherAsync, $CompletionStage*, $CompletionStage*, $Consumer*, $Executor*)},
	{"acceptEitherAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/Consumer;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, acceptEitherAsync, $CompletionStage*, $CompletionStage*, $Consumer*)},
	{"applyToEither", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/Function;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, applyToEither, $CompletionStage*, $CompletionStage*, $Function*)},
	{"applyToEitherAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/Function;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, applyToEitherAsync, $CompletionStage*, $CompletionStage*, $Function*, $Executor*)},
	{"applyToEitherAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/Function;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, applyToEitherAsync, $CompletionStage*, $CompletionStage*, $Function*)},
	{"cancel", "(Z)Z", nullptr, $PUBLIC, $virtualMethod(CompletableFuture$MinimalStage, cancel, bool, bool)},
	{"complete", "(Ljava/lang/Object;)Z", "(TT;)Z", $PUBLIC, $virtualMethod(CompletableFuture$MinimalStage, complete, bool, Object$*)},
	{"completeAsync", "(Ljava/util/function/Supplier;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/function/Supplier<+TT;>;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture$MinimalStage, completeAsync, $CompletableFuture*, $Supplier*, $Executor*)},
	{"completeAsync", "(Ljava/util/function/Supplier;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/function/Supplier<+TT;>;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture$MinimalStage, completeAsync, $CompletableFuture*, $Supplier*)},
	{"completeExceptionally", "(Ljava/lang/Throwable;)Z", nullptr, $PUBLIC, $virtualMethod(CompletableFuture$MinimalStage, completeExceptionally, bool, $Throwable*)},
	{"completeOnTimeout", "(Ljava/lang/Object;JLjava/util/concurrent/TimeUnit;)Ljava/util/concurrent/CompletableFuture;", "(TT;JLjava/util/concurrent/TimeUnit;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture$MinimalStage, completeOnTimeout, $CompletableFuture*, Object$*, int64_t, $TimeUnit*)},
	{"exceptionally", "(Ljava/util/function/Function;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, exceptionally, $CompletionStage*, $Function*)},
	{"exceptionallyAsync", "(Ljava/util/function/Function;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, exceptionallyAsync, $CompletionStage*, $Function*, $Executor*)},
	{"exceptionallyAsync", "(Ljava/util/function/Function;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, exceptionallyAsync, $CompletionStage*, $Function*)},
	{"exceptionallyCompose", "(Ljava/util/function/Function;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, exceptionallyCompose, $CompletionStage*, $Function*)},
	{"exceptionallyComposeAsync", "(Ljava/util/function/Function;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, exceptionallyComposeAsync, $CompletionStage*, $Function*, $Executor*)},
	{"exceptionallyComposeAsync", "(Ljava/util/function/Function;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, exceptionallyComposeAsync, $CompletionStage*, $Function*)},
	{"get", "()Ljava/lang/Object;", "()TT;", $PUBLIC, $virtualMethod(CompletableFuture$MinimalStage, get, $Object*)},
	{"get", "(JLjava/util/concurrent/TimeUnit;)Ljava/lang/Object;", "(JLjava/util/concurrent/TimeUnit;)TT;", $PUBLIC, $virtualMethod(CompletableFuture$MinimalStage, get, $Object*, int64_t, $TimeUnit*)},
	{"getNow", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TT;)TT;", $PUBLIC, $virtualMethod(CompletableFuture$MinimalStage, getNow, $Object*, Object$*)},
	{"getNumberOfDependents", "()I", nullptr, $PUBLIC, $virtualMethod(CompletableFuture$MinimalStage, getNumberOfDependents, int32_t)},
	{"handle", "(Ljava/util/function/BiFunction;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, handle, $CompletionStage*, $BiFunction*)},
	{"handleAsync", "(Ljava/util/function/BiFunction;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, handleAsync, $CompletionStage*, $BiFunction*, $Executor*)},
	{"handleAsync", "(Ljava/util/function/BiFunction;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, handleAsync, $CompletionStage*, $BiFunction*)},
	{"isCancelled", "()Z", nullptr, $PUBLIC, $virtualMethod(CompletableFuture$MinimalStage, isCancelled, bool)},
	{"isCompletedExceptionally", "()Z", nullptr, $PUBLIC, $virtualMethod(CompletableFuture$MinimalStage, isCompletedExceptionally, bool)},
	{"isDone", "()Z", nullptr, $PUBLIC, $virtualMethod(CompletableFuture$MinimalStage, isDone, bool)},
	{"join", "()Ljava/lang/Object;", "()TT;", $PUBLIC, $virtualMethod(CompletableFuture$MinimalStage, join, $Object*)},
	{"newIncompleteFuture", "()Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>()Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC, $virtualMethod(CompletableFuture$MinimalStage, newIncompleteFuture, $CompletableFuture*)},
	{"obtrudeException", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $virtualMethod(CompletableFuture$MinimalStage, obtrudeException, void, $Throwable*)},
	{"obtrudeValue", "(Ljava/lang/Object;)V", "(TT;)V", $PUBLIC, $virtualMethod(CompletableFuture$MinimalStage, obtrudeValue, void, Object$*)},
	{"orTimeout", "(JLjava/util/concurrent/TimeUnit;)Ljava/util/concurrent/CompletableFuture;", "(JLjava/util/concurrent/TimeUnit;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture$MinimalStage, orTimeout, $CompletableFuture*, int64_t, $TimeUnit*)},
	{"runAfterBoth", "(Ljava/util/concurrent/CompletionStage;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, runAfterBoth, $CompletionStage*, $CompletionStage*, $Runnable*)},
	{"runAfterBothAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/lang/Runnable;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, runAfterBothAsync, $CompletionStage*, $CompletionStage*, $Runnable*, $Executor*)},
	{"runAfterBothAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, runAfterBothAsync, $CompletionStage*, $CompletionStage*, $Runnable*)},
	{"runAfterEither", "(Ljava/util/concurrent/CompletionStage;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, runAfterEither, $CompletionStage*, $CompletionStage*, $Runnable*)},
	{"runAfterEitherAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/lang/Runnable;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, runAfterEitherAsync, $CompletionStage*, $CompletionStage*, $Runnable*, $Executor*)},
	{"runAfterEitherAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, runAfterEitherAsync, $CompletionStage*, $CompletionStage*, $Runnable*)},
	{"thenAccept", "(Ljava/util/function/Consumer;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, thenAccept, $CompletionStage*, $Consumer*)},
	{"thenAcceptAsync", "(Ljava/util/function/Consumer;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, thenAcceptAsync, $CompletionStage*, $Consumer*, $Executor*)},
	{"thenAcceptAsync", "(Ljava/util/function/Consumer;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, thenAcceptAsync, $CompletionStage*, $Consumer*)},
	{"thenAcceptBoth", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/BiConsumer;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, thenAcceptBoth, $CompletionStage*, $CompletionStage*, $BiConsumer*)},
	{"thenAcceptBothAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/BiConsumer;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, thenAcceptBothAsync, $CompletionStage*, $CompletionStage*, $BiConsumer*, $Executor*)},
	{"thenAcceptBothAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/BiConsumer;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, thenAcceptBothAsync, $CompletionStage*, $CompletionStage*, $BiConsumer*)},
	{"thenApply", "(Ljava/util/function/Function;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, thenApply, $CompletionStage*, $Function*)},
	{"thenApplyAsync", "(Ljava/util/function/Function;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, thenApplyAsync, $CompletionStage*, $Function*, $Executor*)},
	{"thenApplyAsync", "(Ljava/util/function/Function;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, thenApplyAsync, $CompletionStage*, $Function*)},
	{"thenCombine", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/BiFunction;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, thenCombine, $CompletionStage*, $CompletionStage*, $BiFunction*)},
	{"thenCombineAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/BiFunction;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, thenCombineAsync, $CompletionStage*, $CompletionStage*, $BiFunction*, $Executor*)},
	{"thenCombineAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/BiFunction;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, thenCombineAsync, $CompletionStage*, $CompletionStage*, $BiFunction*)},
	{"thenCompose", "(Ljava/util/function/Function;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, thenCompose, $CompletionStage*, $Function*)},
	{"thenComposeAsync", "(Ljava/util/function/Function;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, thenComposeAsync, $CompletionStage*, $Function*, $Executor*)},
	{"thenComposeAsync", "(Ljava/util/function/Function;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, thenComposeAsync, $CompletionStage*, $Function*)},
	{"thenRun", "(Ljava/lang/Runnable;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, thenRun, $CompletionStage*, $Runnable*)},
	{"thenRunAsync", "(Ljava/lang/Runnable;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, thenRunAsync, $CompletionStage*, $Runnable*, $Executor*)},
	{"thenRunAsync", "(Ljava/lang/Runnable;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, thenRunAsync, $CompletionStage*, $Runnable*)},
	{"toCompletableFuture", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture$MinimalStage, toCompletableFuture, $CompletableFuture*)},
	{"whenComplete", "(Ljava/util/function/BiConsumer;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, whenComplete, $CompletionStage*, $BiConsumer*)},
	{"whenCompleteAsync", "(Ljava/util/function/BiConsumer;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, whenCompleteAsync, $CompletionStage*, $BiConsumer*, $Executor*)},
	{"whenCompleteAsync", "(Ljava/util/function/BiConsumer;)Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(CompletableFuture$MinimalStage, whenCompleteAsync, $CompletionStage*, $BiConsumer*)},
	{}
};

$InnerClassInfo _CompletableFuture$MinimalStage_InnerClassesInfo_[] = {
	{"java.util.concurrent.CompletableFuture$MinimalStage", "java.util.concurrent.CompletableFuture", "MinimalStage", $STATIC | $FINAL},
	{}
};

$ClassInfo _CompletableFuture$MinimalStage_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.concurrent.CompletableFuture$MinimalStage",
	"java.util.concurrent.CompletableFuture",
	nullptr,
	nullptr,
	_CompletableFuture$MinimalStage_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/util/concurrent/CompletableFuture<TT;>;",
	nullptr,
	_CompletableFuture$MinimalStage_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.concurrent.CompletableFuture"
};

$Object* allocate$CompletableFuture$MinimalStage($Class* clazz) {
	return $of($alloc(CompletableFuture$MinimalStage));
}

void CompletableFuture$MinimalStage::init$() {
	$CompletableFuture::init$();
}

void CompletableFuture$MinimalStage::init$(Object$* r) {
	$CompletableFuture::init$(r);
}

$CompletableFuture* CompletableFuture$MinimalStage::newIncompleteFuture() {
	return $new(CompletableFuture$MinimalStage);
}

$Object* CompletableFuture$MinimalStage::get() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Object* CompletableFuture$MinimalStage::get(int64_t timeout, $TimeUnit* unit) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Object* CompletableFuture$MinimalStage::getNow(Object$* valueIfAbsent) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Object* CompletableFuture$MinimalStage::join() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool CompletableFuture$MinimalStage::complete(Object$* value) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool CompletableFuture$MinimalStage::completeExceptionally($Throwable* ex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool CompletableFuture$MinimalStage::cancel(bool mayInterruptIfRunning) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

void CompletableFuture$MinimalStage::obtrudeValue(Object$* value) {
	$throwNew($UnsupportedOperationException);
}

void CompletableFuture$MinimalStage::obtrudeException($Throwable* ex) {
	$throwNew($UnsupportedOperationException);
}

bool CompletableFuture$MinimalStage::isDone() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool CompletableFuture$MinimalStage::isCancelled() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool CompletableFuture$MinimalStage::isCompletedExceptionally() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

int32_t CompletableFuture$MinimalStage::getNumberOfDependents() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$CompletableFuture* CompletableFuture$MinimalStage::completeAsync($Supplier* supplier, $Executor* executor) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$CompletableFuture* CompletableFuture$MinimalStage::completeAsync($Supplier* supplier) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$CompletableFuture* CompletableFuture$MinimalStage::orTimeout(int64_t timeout, $TimeUnit* unit) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$CompletableFuture* CompletableFuture$MinimalStage::completeOnTimeout(Object$* value, int64_t timeout, $TimeUnit* unit) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$CompletableFuture* CompletableFuture$MinimalStage::toCompletableFuture() {
	$useLocalCurrentObjectStackCache();
	$var($Object, r, nullptr);
	if (($assign(r, this->result)) != nullptr) {
		return $new($CompletableFuture, $(encodeRelay(r)));
	} else {
		$var($CompletableFuture, d, $new($CompletableFuture));
		unipush($$new($CompletableFuture$UniRelay, d, this));
		return d;
	}
}

$CompletionStage* CompletableFuture$MinimalStage::exceptionallyComposeAsync($Function* fn, $Executor* executor) {
	return $CompletableFuture::exceptionallyComposeAsync(fn, executor);
}

$CompletionStage* CompletableFuture$MinimalStage::exceptionallyComposeAsync($Function* fn) {
	return $CompletableFuture::exceptionallyComposeAsync(fn);
}

$CompletionStage* CompletableFuture$MinimalStage::exceptionallyCompose($Function* fn) {
	return $CompletableFuture::exceptionallyCompose(fn);
}

$CompletionStage* CompletableFuture$MinimalStage::exceptionallyAsync($Function* fn, $Executor* executor) {
	return $CompletableFuture::exceptionallyAsync(fn, executor);
}

$CompletionStage* CompletableFuture$MinimalStage::exceptionallyAsync($Function* fn) {
	return $CompletableFuture::exceptionallyAsync(fn);
}

$CompletionStage* CompletableFuture$MinimalStage::exceptionally($Function* fn) {
	return $CompletableFuture::exceptionally(fn);
}

$CompletionStage* CompletableFuture$MinimalStage::whenCompleteAsync($BiConsumer* action, $Executor* executor) {
	return $CompletableFuture::whenCompleteAsync(action, executor);
}

$CompletionStage* CompletableFuture$MinimalStage::whenCompleteAsync($BiConsumer* action) {
	return $CompletableFuture::whenCompleteAsync(action);
}

$CompletionStage* CompletableFuture$MinimalStage::whenComplete($BiConsumer* action) {
	return $CompletableFuture::whenComplete(action);
}

$CompletionStage* CompletableFuture$MinimalStage::handleAsync($BiFunction* fn, $Executor* executor) {
	return $CompletableFuture::handleAsync(fn, executor);
}

$CompletionStage* CompletableFuture$MinimalStage::handleAsync($BiFunction* fn) {
	return $CompletableFuture::handleAsync(fn);
}

$CompletionStage* CompletableFuture$MinimalStage::handle($BiFunction* fn) {
	return $CompletableFuture::handle(fn);
}

$CompletionStage* CompletableFuture$MinimalStage::thenComposeAsync($Function* fn, $Executor* executor) {
	return $CompletableFuture::thenComposeAsync(fn, executor);
}

$CompletionStage* CompletableFuture$MinimalStage::thenComposeAsync($Function* fn) {
	return $CompletableFuture::thenComposeAsync(fn);
}

$CompletionStage* CompletableFuture$MinimalStage::thenCompose($Function* fn) {
	return $CompletableFuture::thenCompose(fn);
}

$CompletionStage* CompletableFuture$MinimalStage::runAfterEitherAsync($CompletionStage* other, $Runnable* action, $Executor* executor) {
	return $CompletableFuture::runAfterEitherAsync(other, action, executor);
}

$CompletionStage* CompletableFuture$MinimalStage::runAfterEitherAsync($CompletionStage* other, $Runnable* action) {
	return $CompletableFuture::runAfterEitherAsync(other, action);
}

$CompletionStage* CompletableFuture$MinimalStage::runAfterEither($CompletionStage* other, $Runnable* action) {
	return $CompletableFuture::runAfterEither(other, action);
}

$CompletionStage* CompletableFuture$MinimalStage::acceptEitherAsync($CompletionStage* other, $Consumer* action, $Executor* executor) {
	return $CompletableFuture::acceptEitherAsync(other, action, executor);
}

$CompletionStage* CompletableFuture$MinimalStage::acceptEitherAsync($CompletionStage* other, $Consumer* action) {
	return $CompletableFuture::acceptEitherAsync(other, action);
}

$CompletionStage* CompletableFuture$MinimalStage::acceptEither($CompletionStage* other, $Consumer* action) {
	return $CompletableFuture::acceptEither(other, action);
}

$CompletionStage* CompletableFuture$MinimalStage::applyToEitherAsync($CompletionStage* other, $Function* fn, $Executor* executor) {
	return $CompletableFuture::applyToEitherAsync(other, fn, executor);
}

$CompletionStage* CompletableFuture$MinimalStage::applyToEitherAsync($CompletionStage* other, $Function* fn) {
	return $CompletableFuture::applyToEitherAsync(other, fn);
}

$CompletionStage* CompletableFuture$MinimalStage::applyToEither($CompletionStage* other, $Function* fn) {
	return $CompletableFuture::applyToEither(other, fn);
}

$CompletionStage* CompletableFuture$MinimalStage::runAfterBothAsync($CompletionStage* other, $Runnable* action, $Executor* executor) {
	return $CompletableFuture::runAfterBothAsync(other, action, executor);
}

$CompletionStage* CompletableFuture$MinimalStage::runAfterBothAsync($CompletionStage* other, $Runnable* action) {
	return $CompletableFuture::runAfterBothAsync(other, action);
}

$CompletionStage* CompletableFuture$MinimalStage::runAfterBoth($CompletionStage* other, $Runnable* action) {
	return $CompletableFuture::runAfterBoth(other, action);
}

$CompletionStage* CompletableFuture$MinimalStage::thenAcceptBothAsync($CompletionStage* other, $BiConsumer* action, $Executor* executor) {
	return $CompletableFuture::thenAcceptBothAsync(other, action, executor);
}

$CompletionStage* CompletableFuture$MinimalStage::thenAcceptBothAsync($CompletionStage* other, $BiConsumer* action) {
	return $CompletableFuture::thenAcceptBothAsync(other, action);
}

$CompletionStage* CompletableFuture$MinimalStage::thenAcceptBoth($CompletionStage* other, $BiConsumer* action) {
	return $CompletableFuture::thenAcceptBoth(other, action);
}

$CompletionStage* CompletableFuture$MinimalStage::thenCombineAsync($CompletionStage* other, $BiFunction* fn, $Executor* executor) {
	return $CompletableFuture::thenCombineAsync(other, fn, executor);
}

$CompletionStage* CompletableFuture$MinimalStage::thenCombineAsync($CompletionStage* other, $BiFunction* fn) {
	return $CompletableFuture::thenCombineAsync(other, fn);
}

$CompletionStage* CompletableFuture$MinimalStage::thenCombine($CompletionStage* other, $BiFunction* fn) {
	return $CompletableFuture::thenCombine(other, fn);
}

$CompletionStage* CompletableFuture$MinimalStage::thenRunAsync($Runnable* action, $Executor* executor) {
	return $CompletableFuture::thenRunAsync(action, executor);
}

$CompletionStage* CompletableFuture$MinimalStage::thenRunAsync($Runnable* action) {
	return $CompletableFuture::thenRunAsync(action);
}

$CompletionStage* CompletableFuture$MinimalStage::thenRun($Runnable* action) {
	return $CompletableFuture::thenRun(action);
}

$CompletionStage* CompletableFuture$MinimalStage::thenAcceptAsync($Consumer* action, $Executor* executor) {
	return $CompletableFuture::thenAcceptAsync(action, executor);
}

$CompletionStage* CompletableFuture$MinimalStage::thenAcceptAsync($Consumer* action) {
	return $CompletableFuture::thenAcceptAsync(action);
}

$CompletionStage* CompletableFuture$MinimalStage::thenAccept($Consumer* action) {
	return $CompletableFuture::thenAccept(action);
}

$CompletionStage* CompletableFuture$MinimalStage::thenApplyAsync($Function* fn, $Executor* executor) {
	return $CompletableFuture::thenApplyAsync(fn, executor);
}

$CompletionStage* CompletableFuture$MinimalStage::thenApplyAsync($Function* fn) {
	return $CompletableFuture::thenApplyAsync(fn);
}

$CompletionStage* CompletableFuture$MinimalStage::thenApply($Function* fn) {
	return $CompletableFuture::thenApply(fn);
}

CompletableFuture$MinimalStage::CompletableFuture$MinimalStage() {
}

$Class* CompletableFuture$MinimalStage::load$($String* name, bool initialize) {
	$loadClass(CompletableFuture$MinimalStage, name, initialize, &_CompletableFuture$MinimalStage_ClassInfo_, allocate$CompletableFuture$MinimalStage);
	return class$;
}

$Class* CompletableFuture$MinimalStage::class$ = nullptr;

		} // concurrent
	} // util
} // java