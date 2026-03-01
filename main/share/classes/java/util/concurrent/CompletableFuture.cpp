#include <java/util/concurrent/CompletableFuture.h>

#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/util/concurrent/CancellationException.h>
#include <java/util/concurrent/CompletableFuture$AltResult.h>
#include <java/util/concurrent/CompletableFuture$AnyOf.h>
#include <java/util/concurrent/CompletableFuture$AsyncRun.h>
#include <java/util/concurrent/CompletableFuture$AsyncSupply.h>
#include <java/util/concurrent/CompletableFuture$BiAccept.h>
#include <java/util/concurrent/CompletableFuture$BiApply.h>
#include <java/util/concurrent/CompletableFuture$BiCompletion.h>
#include <java/util/concurrent/CompletableFuture$BiRelay.h>
#include <java/util/concurrent/CompletableFuture$BiRun.h>
#include <java/util/concurrent/CompletableFuture$Canceller.h>
#include <java/util/concurrent/CompletableFuture$CoCompletion.h>
#include <java/util/concurrent/CompletableFuture$Completion.h>
#include <java/util/concurrent/CompletableFuture$DelayedCompleter.h>
#include <java/util/concurrent/CompletableFuture$DelayedExecutor.h>
#include <java/util/concurrent/CompletableFuture$Delayer.h>
#include <java/util/concurrent/CompletableFuture$MinimalStage.h>
#include <java/util/concurrent/CompletableFuture$OrAccept.h>
#include <java/util/concurrent/CompletableFuture$OrApply.h>
#include <java/util/concurrent/CompletableFuture$OrRun.h>
#include <java/util/concurrent/CompletableFuture$Signaller.h>
#include <java/util/concurrent/CompletableFuture$ThreadPerTaskExecutor.h>
#include <java/util/concurrent/CompletableFuture$Timeout.h>
#include <java/util/concurrent/CompletableFuture$UniAccept.h>
#include <java/util/concurrent/CompletableFuture$UniApply.h>
#include <java/util/concurrent/CompletableFuture$UniCompose.h>
#include <java/util/concurrent/CompletableFuture$UniComposeExceptionally.h>
#include <java/util/concurrent/CompletableFuture$UniExceptionally.h>
#include <java/util/concurrent/CompletableFuture$UniHandle.h>
#include <java/util/concurrent/CompletableFuture$UniRelay.h>
#include <java/util/concurrent/CompletableFuture$UniRun.h>
#include <java/util/concurrent/CompletableFuture$UniWhenComplete.h>
#include <java/util/concurrent/CompletionException.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/ExecutionException.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/ForkJoinPool$ManagedBlocker.h>
#include <java/util/concurrent/ForkJoinPool.h>
#include <java/util/concurrent/ForkJoinWorkerThread.h>
#include <java/util/concurrent/Future.h>
#include <java/util/concurrent/ScheduledFuture.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/concurrent/TimeoutException.h>
#include <java/util/concurrent/locks/LockSupport.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Supplier.h>
#include <jcpp.h>

#undef ASYNC
#undef ASYNC_POOL
#undef NESTED
#undef NEXT
#undef NIL
#undef RESULT
#undef STACK
#undef SYNC
#undef USE_COMMON_POOL

using $CompletableFutureArray = $Array<::java::util::concurrent::CompletableFuture>;
using $ClassInfo = ::java::lang::ClassInfo;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $Runnable = ::java::lang::Runnable;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $CancellationException = ::java::util::concurrent::CancellationException;
using $CompletableFuture$AltResult = ::java::util::concurrent::CompletableFuture$AltResult;
using $CompletableFuture$AnyOf = ::java::util::concurrent::CompletableFuture$AnyOf;
using $CompletableFuture$AsyncRun = ::java::util::concurrent::CompletableFuture$AsyncRun;
using $CompletableFuture$AsyncSupply = ::java::util::concurrent::CompletableFuture$AsyncSupply;
using $CompletableFuture$BiAccept = ::java::util::concurrent::CompletableFuture$BiAccept;
using $CompletableFuture$BiApply = ::java::util::concurrent::CompletableFuture$BiApply;
using $CompletableFuture$BiCompletion = ::java::util::concurrent::CompletableFuture$BiCompletion;
using $CompletableFuture$BiRelay = ::java::util::concurrent::CompletableFuture$BiRelay;
using $CompletableFuture$BiRun = ::java::util::concurrent::CompletableFuture$BiRun;
using $CompletableFuture$Canceller = ::java::util::concurrent::CompletableFuture$Canceller;
using $CompletableFuture$CoCompletion = ::java::util::concurrent::CompletableFuture$CoCompletion;
using $CompletableFuture$Completion = ::java::util::concurrent::CompletableFuture$Completion;
using $CompletableFuture$DelayedCompleter = ::java::util::concurrent::CompletableFuture$DelayedCompleter;
using $CompletableFuture$DelayedExecutor = ::java::util::concurrent::CompletableFuture$DelayedExecutor;
using $CompletableFuture$Delayer = ::java::util::concurrent::CompletableFuture$Delayer;
using $CompletableFuture$MinimalStage = ::java::util::concurrent::CompletableFuture$MinimalStage;
using $CompletableFuture$OrAccept = ::java::util::concurrent::CompletableFuture$OrAccept;
using $CompletableFuture$OrApply = ::java::util::concurrent::CompletableFuture$OrApply;
using $CompletableFuture$OrRun = ::java::util::concurrent::CompletableFuture$OrRun;
using $CompletableFuture$Signaller = ::java::util::concurrent::CompletableFuture$Signaller;
using $CompletableFuture$ThreadPerTaskExecutor = ::java::util::concurrent::CompletableFuture$ThreadPerTaskExecutor;
using $CompletableFuture$Timeout = ::java::util::concurrent::CompletableFuture$Timeout;
using $CompletableFuture$UniAccept = ::java::util::concurrent::CompletableFuture$UniAccept;
using $CompletableFuture$UniApply = ::java::util::concurrent::CompletableFuture$UniApply;
using $CompletableFuture$UniCompose = ::java::util::concurrent::CompletableFuture$UniCompose;
using $CompletableFuture$UniComposeExceptionally = ::java::util::concurrent::CompletableFuture$UniComposeExceptionally;
using $CompletableFuture$UniExceptionally = ::java::util::concurrent::CompletableFuture$UniExceptionally;
using $CompletableFuture$UniHandle = ::java::util::concurrent::CompletableFuture$UniHandle;
using $CompletableFuture$UniRelay = ::java::util::concurrent::CompletableFuture$UniRelay;
using $CompletableFuture$UniRun = ::java::util::concurrent::CompletableFuture$UniRun;
using $CompletableFuture$UniWhenComplete = ::java::util::concurrent::CompletableFuture$UniWhenComplete;
using $CompletionException = ::java::util::concurrent::CompletionException;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $ExecutionException = ::java::util::concurrent::ExecutionException;
using $Executor = ::java::util::concurrent::Executor;
using $ForkJoinPool = ::java::util::concurrent::ForkJoinPool;
using $ForkJoinPool$ManagedBlocker = ::java::util::concurrent::ForkJoinPool$ManagedBlocker;
using $ForkJoinWorkerThread = ::java::util::concurrent::ForkJoinWorkerThread;
using $Future = ::java::util::concurrent::Future;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $TimeoutException = ::java::util::concurrent::TimeoutException;
using $LockSupport = ::java::util::concurrent::locks::LockSupport;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiFunction = ::java::util::function::BiFunction;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Supplier = ::java::util::function::Supplier;

namespace java {
	namespace util {
		namespace concurrent {

$FieldInfo _CompletableFuture_FieldInfo_[] = {
	{"result", "Ljava/lang/Object;", nullptr, $VOLATILE, $field(CompletableFuture, result)},
	{"stack", "Ljava/util/concurrent/CompletableFuture$Completion;", nullptr, $VOLATILE, $field(CompletableFuture, stack)},
	{"NIL", "Ljava/util/concurrent/CompletableFuture$AltResult;", nullptr, $STATIC | $FINAL, $staticField(CompletableFuture, NIL)},
	{"USE_COMMON_POOL", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CompletableFuture, USE_COMMON_POOL)},
	{"ASYNC_POOL", "Ljava/util/concurrent/Executor;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CompletableFuture, ASYNC_POOL)},
	{"SYNC", "I", nullptr, $STATIC | $FINAL, $constField(CompletableFuture, SYNC)},
	{"ASYNC", "I", nullptr, $STATIC | $FINAL, $constField(CompletableFuture, ASYNC)},
	{"NESTED", "I", nullptr, $STATIC | $FINAL, $constField(CompletableFuture, NESTED)},
	{"RESULT", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CompletableFuture, RESULT)},
	{"STACK", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CompletableFuture, STACK)},
	{"NEXT", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CompletableFuture, NEXT)},
	{}
};

$MethodInfo _CompletableFuture_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(CompletableFuture, init$, void)},
	{"<init>", "(Ljava/lang/Object;)V", nullptr, 0, $method(CompletableFuture, init$, void, Object$*)},
	{"acceptEither", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/Consumer;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/CompletionStage<+TT;>;Ljava/util/function/Consumer<-TT;>;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC, $virtualMethod(CompletableFuture, acceptEither, $CompletionStage*, $CompletionStage*, $Consumer*)},
	{"acceptEitherAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/Consumer;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/CompletionStage<+TT;>;Ljava/util/function/Consumer<-TT;>;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC, $virtualMethod(CompletableFuture, acceptEitherAsync, $CompletionStage*, $CompletionStage*, $Consumer*)},
	{"acceptEitherAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/Consumer;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/CompletionStage<+TT;>;Ljava/util/function/Consumer<-TT;>;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC, $virtualMethod(CompletableFuture, acceptEitherAsync, $CompletionStage*, $CompletionStage*, $Consumer*, $Executor*)},
	{"allOf", "([Ljava/util/concurrent/CompletableFuture;)Ljava/util/concurrent/CompletableFuture;", "([Ljava/util/concurrent/CompletableFuture<*>;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(CompletableFuture, allOf, CompletableFuture*, $CompletableFutureArray*)},
	{"andTree", "([Ljava/util/concurrent/CompletableFuture;II)Ljava/util/concurrent/CompletableFuture;", "([Ljava/util/concurrent/CompletableFuture<*>;II)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $STATIC, $staticMethod(CompletableFuture, andTree, CompletableFuture*, $CompletableFutureArray*, int32_t, int32_t)},
	{"anyOf", "([Ljava/util/concurrent/CompletableFuture;)Ljava/util/concurrent/CompletableFuture;", "([Ljava/util/concurrent/CompletableFuture<*>;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Object;>;", $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(CompletableFuture, anyOf, CompletableFuture*, $CompletableFutureArray*)},
	{"applyToEither", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/Function;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/util/concurrent/CompletionStage<+TT;>;Ljava/util/function/Function<-TT;TU;>;)Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC, $virtualMethod(CompletableFuture, applyToEither, $CompletionStage*, $CompletionStage*, $Function*)},
	{"applyToEitherAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/Function;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/util/concurrent/CompletionStage<+TT;>;Ljava/util/function/Function<-TT;TU;>;)Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC, $virtualMethod(CompletableFuture, applyToEitherAsync, $CompletionStage*, $CompletionStage*, $Function*)},
	{"applyToEitherAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/Function;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/util/concurrent/CompletionStage<+TT;>;Ljava/util/function/Function<-TT;TU;>;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC, $virtualMethod(CompletableFuture, applyToEitherAsync, $CompletionStage*, $CompletionStage*, $Function*, $Executor*)},
	{"asyncRunStage", "(Ljava/util/concurrent/Executor;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/Executor;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $STATIC, $staticMethod(CompletableFuture, asyncRunStage, CompletableFuture*, $Executor*, $Runnable*)},
	{"asyncSupplyStage", "(Ljava/util/concurrent/Executor;Ljava/util/function/Supplier;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/util/concurrent/Executor;Ljava/util/function/Supplier<TU;>;)Ljava/util/concurrent/CompletableFuture<TU;>;", $STATIC, $staticMethod(CompletableFuture, asyncSupplyStage, CompletableFuture*, $Executor*, $Supplier*)},
	{"biAccept", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture$BiAccept;)Z", "<R:Ljava/lang/Object;S:Ljava/lang/Object;>(Ljava/lang/Object;Ljava/lang/Object;Ljava/util/function/BiConsumer<-TR;-TS;>;Ljava/util/concurrent/CompletableFuture$BiAccept<TR;TS;>;)Z", $FINAL, $method(CompletableFuture, biAccept, bool, Object$*, Object$*, $BiConsumer*, $CompletableFuture$BiAccept*)},
	{"biAcceptStage", "(Ljava/util/concurrent/Executor;Ljava/util/concurrent/CompletionStage;Ljava/util/function/BiConsumer;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/util/concurrent/Executor;Ljava/util/concurrent/CompletionStage<TU;>;Ljava/util/function/BiConsumer<-TT;-TU;>;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PRIVATE, $method(CompletableFuture, biAcceptStage, CompletableFuture*, $Executor*, $CompletionStage*, $BiConsumer*)},
	{"biApply", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/util/function/BiFunction;Ljava/util/concurrent/CompletableFuture$BiApply;)Z", "<R:Ljava/lang/Object;S:Ljava/lang/Object;>(Ljava/lang/Object;Ljava/lang/Object;Ljava/util/function/BiFunction<-TR;-TS;+TT;>;Ljava/util/concurrent/CompletableFuture$BiApply<TR;TS;TT;>;)Z", $FINAL, $method(CompletableFuture, biApply, bool, Object$*, Object$*, $BiFunction*, $CompletableFuture$BiApply*)},
	{"biApplyStage", "(Ljava/util/concurrent/Executor;Ljava/util/concurrent/CompletionStage;Ljava/util/function/BiFunction;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;V:Ljava/lang/Object;>(Ljava/util/concurrent/Executor;Ljava/util/concurrent/CompletionStage<TU;>;Ljava/util/function/BiFunction<-TT;-TU;+TV;>;)Ljava/util/concurrent/CompletableFuture<TV;>;", $PRIVATE, $method(CompletableFuture, biApplyStage, CompletableFuture*, $Executor*, $CompletionStage*, $BiFunction*)},
	{"biRun", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Runnable;Ljava/util/concurrent/CompletableFuture$BiRun;)Z", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Runnable;Ljava/util/concurrent/CompletableFuture$BiRun<**>;)Z", $FINAL, $method(CompletableFuture, biRun, bool, Object$*, Object$*, $Runnable*, $CompletableFuture$BiRun*)},
	{"biRunStage", "(Ljava/util/concurrent/Executor;Ljava/util/concurrent/CompletionStage;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/Executor;Ljava/util/concurrent/CompletionStage<*>;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PRIVATE, $method(CompletableFuture, biRunStage, CompletableFuture*, $Executor*, $CompletionStage*, $Runnable*)},
	{"bipush", "(Ljava/util/concurrent/CompletableFuture;Ljava/util/concurrent/CompletableFuture$BiCompletion;)V", "(Ljava/util/concurrent/CompletableFuture<*>;Ljava/util/concurrent/CompletableFuture$BiCompletion<***>;)V", $FINAL, $method(CompletableFuture, bipush, void, CompletableFuture*, $CompletableFuture$BiCompletion*)},
	{"cancel", "(Z)Z", nullptr, $PUBLIC, $virtualMethod(CompletableFuture, cancel, bool, bool)},
	{"cleanStack", "()V", nullptr, $FINAL, $method(CompletableFuture, cleanStack, void)},
	{"complete", "(Ljava/lang/Object;)Z", "(TT;)Z", $PUBLIC, $virtualMethod(CompletableFuture, complete, bool, Object$*)},
	{"completeAsync", "(Ljava/util/function/Supplier;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/function/Supplier<+TT;>;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture, completeAsync, CompletableFuture*, $Supplier*, $Executor*)},
	{"completeAsync", "(Ljava/util/function/Supplier;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/function/Supplier<+TT;>;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture, completeAsync, CompletableFuture*, $Supplier*)},
	{"completeExceptionally", "(Ljava/lang/Throwable;)Z", nullptr, $PUBLIC, $virtualMethod(CompletableFuture, completeExceptionally, bool, $Throwable*)},
	{"completeNull", "()Z", nullptr, $FINAL, $method(CompletableFuture, completeNull, bool)},
	{"completeOnTimeout", "(Ljava/lang/Object;JLjava/util/concurrent/TimeUnit;)Ljava/util/concurrent/CompletableFuture;", "(TT;JLjava/util/concurrent/TimeUnit;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture, completeOnTimeout, CompletableFuture*, Object$*, int64_t, $TimeUnit*)},
	{"completeRelay", "(Ljava/lang/Object;)Z", nullptr, $FINAL, $method(CompletableFuture, completeRelay, bool, Object$*)},
	{"completeThrowable", "(Ljava/lang/Throwable;)Z", nullptr, $FINAL, $method(CompletableFuture, completeThrowable, bool, $Throwable*)},
	{"completeThrowable", "(Ljava/lang/Throwable;Ljava/lang/Object;)Z", nullptr, $FINAL, $method(CompletableFuture, completeThrowable, bool, $Throwable*, Object$*)},
	{"completeValue", "(Ljava/lang/Object;)Z", "(TT;)Z", $FINAL, $method(CompletableFuture, completeValue, bool, Object$*)},
	{"completedFuture", "(Ljava/lang/Object;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(TU;)Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC | $STATIC, $staticMethod(CompletableFuture, completedFuture, CompletableFuture*, Object$*)},
	{"completedStage", "(Ljava/lang/Object;)Ljava/util/concurrent/CompletionStage;", "<U:Ljava/lang/Object;>(TU;)Ljava/util/concurrent/CompletionStage<TU;>;", $PUBLIC | $STATIC, $staticMethod(CompletableFuture, completedStage, $CompletionStage*, Object$*)},
	{"copy", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture, copy, CompletableFuture*)},
	{"defaultExecutor", "()Ljava/util/concurrent/Executor;", nullptr, $PUBLIC, $virtualMethod(CompletableFuture, defaultExecutor, $Executor*)},
	{"delayedExecutor", "(JLjava/util/concurrent/TimeUnit;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/Executor;", nullptr, $PUBLIC | $STATIC, $staticMethod(CompletableFuture, delayedExecutor, $Executor*, int64_t, $TimeUnit*, $Executor*)},
	{"delayedExecutor", "(JLjava/util/concurrent/TimeUnit;)Ljava/util/concurrent/Executor;", nullptr, $PUBLIC | $STATIC, $staticMethod(CompletableFuture, delayedExecutor, $Executor*, int64_t, $TimeUnit*)},
	{"encodeOutcome", "(Ljava/lang/Object;Ljava/lang/Throwable;)Ljava/lang/Object;", "(TT;Ljava/lang/Throwable;)Ljava/lang/Object;", 0, $virtualMethod(CompletableFuture, encodeOutcome, $Object*, Object$*, $Throwable*)},
	{"encodeRelay", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $STATIC, $staticMethod(CompletableFuture, encodeRelay, $Object*, Object$*)},
	{"encodeThrowable", "(Ljava/lang/Throwable;)Ljava/util/concurrent/CompletableFuture$AltResult;", nullptr, $STATIC, $staticMethod(CompletableFuture, encodeThrowable, $CompletableFuture$AltResult*, $Throwable*)},
	{"encodeThrowable", "(Ljava/lang/Throwable;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $STATIC, $staticMethod(CompletableFuture, encodeThrowable, $Object*, $Throwable*, Object$*)},
	{"encodeValue", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TT;)Ljava/lang/Object;", $FINAL, $method(CompletableFuture, encodeValue, $Object*, Object$*)},
	{"exceptionally", "(Ljava/util/function/Function;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/function/Function<Ljava/lang/Throwable;+TT;>;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture, exceptionally, $CompletionStage*, $Function*)},
	{"exceptionallyAsync", "(Ljava/util/function/Function;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/function/Function<Ljava/lang/Throwable;+TT;>;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture, exceptionallyAsync, $CompletionStage*, $Function*)},
	{"exceptionallyAsync", "(Ljava/util/function/Function;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/function/Function<Ljava/lang/Throwable;+TT;>;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture, exceptionallyAsync, $CompletionStage*, $Function*, $Executor*)},
	{"exceptionallyCompose", "(Ljava/util/function/Function;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/function/Function<Ljava/lang/Throwable;+Ljava/util/concurrent/CompletionStage<TT;>;>;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture, exceptionallyCompose, $CompletionStage*, $Function*)},
	{"exceptionallyComposeAsync", "(Ljava/util/function/Function;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/function/Function<Ljava/lang/Throwable;+Ljava/util/concurrent/CompletionStage<TT;>;>;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture, exceptionallyComposeAsync, $CompletionStage*, $Function*)},
	{"exceptionallyComposeAsync", "(Ljava/util/function/Function;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/function/Function<Ljava/lang/Throwable;+Ljava/util/concurrent/CompletionStage<TT;>;>;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture, exceptionallyComposeAsync, $CompletionStage*, $Function*, $Executor*)},
	{"failedFuture", "(Ljava/lang/Throwable;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/lang/Throwable;)Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC | $STATIC, $staticMethod(CompletableFuture, failedFuture, CompletableFuture*, $Throwable*)},
	{"failedStage", "(Ljava/lang/Throwable;)Ljava/util/concurrent/CompletionStage;", "<U:Ljava/lang/Object;>(Ljava/lang/Throwable;)Ljava/util/concurrent/CompletionStage<TU;>;", $PUBLIC | $STATIC, $staticMethod(CompletableFuture, failedStage, $CompletionStage*, $Throwable*)},
	{"get", "()Ljava/lang/Object;", "()TT;", $PUBLIC, $virtualMethod(CompletableFuture, get, $Object*), "java.lang.InterruptedException,java.util.concurrent.ExecutionException"},
	{"get", "(JLjava/util/concurrent/TimeUnit;)Ljava/lang/Object;", "(JLjava/util/concurrent/TimeUnit;)TT;", $PUBLIC, $virtualMethod(CompletableFuture, get, $Object*, int64_t, $TimeUnit*), "java.lang.InterruptedException,java.util.concurrent.ExecutionException,java.util.concurrent.TimeoutException"},
	{"getNow", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TT;)TT;", $PUBLIC, $virtualMethod(CompletableFuture, getNow, $Object*, Object$*)},
	{"getNumberOfDependents", "()I", nullptr, $PUBLIC, $virtualMethod(CompletableFuture, getNumberOfDependents, int32_t)},
	{"handle", "(Ljava/util/function/BiFunction;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/util/function/BiFunction<-TT;Ljava/lang/Throwable;+TU;>;)Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC, $virtualMethod(CompletableFuture, handle, $CompletionStage*, $BiFunction*)},
	{"handleAsync", "(Ljava/util/function/BiFunction;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/util/function/BiFunction<-TT;Ljava/lang/Throwable;+TU;>;)Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC, $virtualMethod(CompletableFuture, handleAsync, $CompletionStage*, $BiFunction*)},
	{"handleAsync", "(Ljava/util/function/BiFunction;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/util/function/BiFunction<-TT;Ljava/lang/Throwable;+TU;>;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC, $virtualMethod(CompletableFuture, handleAsync, $CompletionStage*, $BiFunction*, $Executor*)},
	{"internalComplete", "(Ljava/lang/Object;)Z", nullptr, $FINAL, $method(CompletableFuture, internalComplete, bool, Object$*)},
	{"isCancelled", "()Z", nullptr, $PUBLIC, $virtualMethod(CompletableFuture, isCancelled, bool)},
	{"isCompletedExceptionally", "()Z", nullptr, $PUBLIC, $virtualMethod(CompletableFuture, isCompletedExceptionally, bool)},
	{"isDone", "()Z", nullptr, $PUBLIC, $virtualMethod(CompletableFuture, isDone, bool)},
	{"join", "()Ljava/lang/Object;", "()TT;", $PUBLIC, $virtualMethod(CompletableFuture, join, $Object*)},
	{"minimalCompletionStage", "()Ljava/util/concurrent/CompletionStage;", "()Ljava/util/concurrent/CompletionStage<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture, minimalCompletionStage, $CompletionStage*)},
	{"newIncompleteFuture", "()Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>()Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC, $virtualMethod(CompletableFuture, newIncompleteFuture, CompletableFuture*)},
	{"obtrudeException", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $virtualMethod(CompletableFuture, obtrudeException, void, $Throwable*)},
	{"obtrudeValue", "(Ljava/lang/Object;)V", "(TT;)V", $PUBLIC, $virtualMethod(CompletableFuture, obtrudeValue, void, Object$*)},
	{"orAcceptStage", "(Ljava/util/concurrent/Executor;Ljava/util/concurrent/CompletionStage;Ljava/util/function/Consumer;)Ljava/util/concurrent/CompletableFuture;", "<U:TT;>(Ljava/util/concurrent/Executor;Ljava/util/concurrent/CompletionStage<TU;>;Ljava/util/function/Consumer<-TT;>;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PRIVATE, $method(CompletableFuture, orAcceptStage, CompletableFuture*, $Executor*, $CompletionStage*, $Consumer*)},
	{"orApplyStage", "(Ljava/util/concurrent/Executor;Ljava/util/concurrent/CompletionStage;Ljava/util/function/Function;)Ljava/util/concurrent/CompletableFuture;", "<U:TT;V:Ljava/lang/Object;>(Ljava/util/concurrent/Executor;Ljava/util/concurrent/CompletionStage<TU;>;Ljava/util/function/Function<-TT;+TV;>;)Ljava/util/concurrent/CompletableFuture<TV;>;", $PRIVATE, $method(CompletableFuture, orApplyStage, CompletableFuture*, $Executor*, $CompletionStage*, $Function*)},
	{"orRunStage", "(Ljava/util/concurrent/Executor;Ljava/util/concurrent/CompletionStage;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/Executor;Ljava/util/concurrent/CompletionStage<*>;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PRIVATE, $method(CompletableFuture, orRunStage, CompletableFuture*, $Executor*, $CompletionStage*, $Runnable*)},
	{"orTimeout", "(JLjava/util/concurrent/TimeUnit;)Ljava/util/concurrent/CompletableFuture;", "(JLjava/util/concurrent/TimeUnit;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture, orTimeout, CompletableFuture*, int64_t, $TimeUnit*)},
	{"orpush", "(Ljava/util/concurrent/CompletableFuture;Ljava/util/concurrent/CompletableFuture$BiCompletion;)V", "(Ljava/util/concurrent/CompletableFuture<*>;Ljava/util/concurrent/CompletableFuture$BiCompletion<***>;)V", $FINAL, $method(CompletableFuture, orpush, void, CompletableFuture*, $CompletableFuture$BiCompletion*)},
	{"postComplete", "()V", nullptr, $FINAL, $method(CompletableFuture, postComplete, void)},
	{"postFire", "(Ljava/util/concurrent/CompletableFuture;I)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/CompletableFuture<*>;I)Ljava/util/concurrent/CompletableFuture<TT;>;", $FINAL, $method(CompletableFuture, postFire, CompletableFuture*, CompletableFuture*, int32_t)},
	{"postFire", "(Ljava/util/concurrent/CompletableFuture;Ljava/util/concurrent/CompletableFuture;I)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/CompletableFuture<*>;Ljava/util/concurrent/CompletableFuture<*>;I)Ljava/util/concurrent/CompletableFuture<TT;>;", $FINAL, $method(CompletableFuture, postFire, CompletableFuture*, CompletableFuture*, CompletableFuture*, int32_t)},
	{"pushStack", "(Ljava/util/concurrent/CompletableFuture$Completion;)V", nullptr, $FINAL, $method(CompletableFuture, pushStack, void, $CompletableFuture$Completion*)},
	{"reportGet", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC, $staticMethod(CompletableFuture, reportGet, $Object*, Object$*), "java.lang.InterruptedException,java.util.concurrent.ExecutionException"},
	{"reportJoin", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC, $staticMethod(CompletableFuture, reportJoin, $Object*, Object$*)},
	{"runAfterBoth", "(Ljava/util/concurrent/CompletionStage;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/CompletionStage<*>;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC, $virtualMethod(CompletableFuture, runAfterBoth, $CompletionStage*, $CompletionStage*, $Runnable*)},
	{"runAfterBothAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/CompletionStage<*>;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC, $virtualMethod(CompletableFuture, runAfterBothAsync, $CompletionStage*, $CompletionStage*, $Runnable*)},
	{"runAfterBothAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/lang/Runnable;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/CompletionStage<*>;Ljava/lang/Runnable;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC, $virtualMethod(CompletableFuture, runAfterBothAsync, $CompletionStage*, $CompletionStage*, $Runnable*, $Executor*)},
	{"runAfterEither", "(Ljava/util/concurrent/CompletionStage;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/CompletionStage<*>;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC, $virtualMethod(CompletableFuture, runAfterEither, $CompletionStage*, $CompletionStage*, $Runnable*)},
	{"runAfterEitherAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/CompletionStage<*>;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC, $virtualMethod(CompletableFuture, runAfterEitherAsync, $CompletionStage*, $CompletionStage*, $Runnable*)},
	{"runAfterEitherAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/lang/Runnable;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/CompletionStage<*>;Ljava/lang/Runnable;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC, $virtualMethod(CompletableFuture, runAfterEitherAsync, $CompletionStage*, $CompletionStage*, $Runnable*, $Executor*)},
	{"runAsync", "(Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC | $STATIC, $staticMethod(CompletableFuture, runAsync, CompletableFuture*, $Runnable*)},
	{"runAsync", "(Ljava/lang/Runnable;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/lang/Runnable;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC | $STATIC, $staticMethod(CompletableFuture, runAsync, CompletableFuture*, $Runnable*, $Executor*)},
	{"screenExecutor", "(Ljava/util/concurrent/Executor;)Ljava/util/concurrent/Executor;", nullptr, $STATIC, $staticMethod(CompletableFuture, screenExecutor, $Executor*, $Executor*)},
	{"supplyAsync", "(Ljava/util/function/Supplier;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/util/function/Supplier<TU;>;)Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC | $STATIC, $staticMethod(CompletableFuture, supplyAsync, CompletableFuture*, $Supplier*)},
	{"supplyAsync", "(Ljava/util/function/Supplier;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/util/function/Supplier<TU;>;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC | $STATIC, $staticMethod(CompletableFuture, supplyAsync, CompletableFuture*, $Supplier*, $Executor*)},
	{"thenAccept", "(Ljava/util/function/Consumer;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/function/Consumer<-TT;>;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC, $virtualMethod(CompletableFuture, thenAccept, $CompletionStage*, $Consumer*)},
	{"thenAcceptAsync", "(Ljava/util/function/Consumer;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/function/Consumer<-TT;>;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC, $virtualMethod(CompletableFuture, thenAcceptAsync, $CompletionStage*, $Consumer*)},
	{"thenAcceptAsync", "(Ljava/util/function/Consumer;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/function/Consumer<-TT;>;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC, $virtualMethod(CompletableFuture, thenAcceptAsync, $CompletionStage*, $Consumer*, $Executor*)},
	{"thenAcceptBoth", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/BiConsumer;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/util/concurrent/CompletionStage<+TU;>;Ljava/util/function/BiConsumer<-TT;-TU;>;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC, $virtualMethod(CompletableFuture, thenAcceptBoth, $CompletionStage*, $CompletionStage*, $BiConsumer*)},
	{"thenAcceptBothAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/BiConsumer;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/util/concurrent/CompletionStage<+TU;>;Ljava/util/function/BiConsumer<-TT;-TU;>;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC, $virtualMethod(CompletableFuture, thenAcceptBothAsync, $CompletionStage*, $CompletionStage*, $BiConsumer*)},
	{"thenAcceptBothAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/BiConsumer;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/util/concurrent/CompletionStage<+TU;>;Ljava/util/function/BiConsumer<-TT;-TU;>;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC, $virtualMethod(CompletableFuture, thenAcceptBothAsync, $CompletionStage*, $CompletionStage*, $BiConsumer*, $Executor*)},
	{"thenApply", "(Ljava/util/function/Function;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+TU;>;)Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC, $virtualMethod(CompletableFuture, thenApply, $CompletionStage*, $Function*)},
	{"thenApplyAsync", "(Ljava/util/function/Function;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+TU;>;)Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC, $virtualMethod(CompletableFuture, thenApplyAsync, $CompletionStage*, $Function*)},
	{"thenApplyAsync", "(Ljava/util/function/Function;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+TU;>;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC, $virtualMethod(CompletableFuture, thenApplyAsync, $CompletionStage*, $Function*, $Executor*)},
	{"thenCombine", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/BiFunction;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;V:Ljava/lang/Object;>(Ljava/util/concurrent/CompletionStage<+TU;>;Ljava/util/function/BiFunction<-TT;-TU;+TV;>;)Ljava/util/concurrent/CompletableFuture<TV;>;", $PUBLIC, $virtualMethod(CompletableFuture, thenCombine, $CompletionStage*, $CompletionStage*, $BiFunction*)},
	{"thenCombineAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/BiFunction;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;V:Ljava/lang/Object;>(Ljava/util/concurrent/CompletionStage<+TU;>;Ljava/util/function/BiFunction<-TT;-TU;+TV;>;)Ljava/util/concurrent/CompletableFuture<TV;>;", $PUBLIC, $virtualMethod(CompletableFuture, thenCombineAsync, $CompletionStage*, $CompletionStage*, $BiFunction*)},
	{"thenCombineAsync", "(Ljava/util/concurrent/CompletionStage;Ljava/util/function/BiFunction;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;V:Ljava/lang/Object;>(Ljava/util/concurrent/CompletionStage<+TU;>;Ljava/util/function/BiFunction<-TT;-TU;+TV;>;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<TV;>;", $PUBLIC, $virtualMethod(CompletableFuture, thenCombineAsync, $CompletionStage*, $CompletionStage*, $BiFunction*, $Executor*)},
	{"thenCompose", "(Ljava/util/function/Function;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+Ljava/util/concurrent/CompletionStage<TU;>;>;)Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC, $virtualMethod(CompletableFuture, thenCompose, $CompletionStage*, $Function*)},
	{"thenComposeAsync", "(Ljava/util/function/Function;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+Ljava/util/concurrent/CompletionStage<TU;>;>;)Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC, $virtualMethod(CompletableFuture, thenComposeAsync, $CompletionStage*, $Function*)},
	{"thenComposeAsync", "(Ljava/util/function/Function;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+Ljava/util/concurrent/CompletionStage<TU;>;>;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC, $virtualMethod(CompletableFuture, thenComposeAsync, $CompletionStage*, $Function*, $Executor*)},
	{"thenRun", "(Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC, $virtualMethod(CompletableFuture, thenRun, $CompletionStage*, $Runnable*)},
	{"thenRunAsync", "(Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC, $virtualMethod(CompletableFuture, thenRunAsync, $CompletionStage*, $Runnable*)},
	{"thenRunAsync", "(Ljava/lang/Runnable;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/lang/Runnable;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC, $virtualMethod(CompletableFuture, thenRunAsync, $CompletionStage*, $Runnable*, $Executor*)},
	{"timedGet", "(J)Ljava/lang/Object;", nullptr, $PRIVATE, $method(CompletableFuture, timedGet, $Object*, int64_t), "java.util.concurrent.TimeoutException"},
	{"toCompletableFuture", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture, toCompletableFuture, CompletableFuture*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CompletableFuture, toString, $String*)},
	{"tryPushStack", "(Ljava/util/concurrent/CompletableFuture$Completion;)Z", nullptr, $FINAL, $method(CompletableFuture, tryPushStack, bool, $CompletableFuture$Completion*)},
	{"uniAcceptNow", "(Ljava/lang/Object;Ljava/util/concurrent/Executor;Ljava/util/function/Consumer;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/lang/Object;Ljava/util/concurrent/Executor;Ljava/util/function/Consumer<-TT;>;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PRIVATE, $method(CompletableFuture, uniAcceptNow, CompletableFuture*, Object$*, $Executor*, $Consumer*)},
	{"uniAcceptStage", "(Ljava/util/concurrent/Executor;Ljava/util/function/Consumer;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/Executor;Ljava/util/function/Consumer<-TT;>;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PRIVATE, $method(CompletableFuture, uniAcceptStage, CompletableFuture*, $Executor*, $Consumer*)},
	{"uniApplyNow", "(Ljava/lang/Object;Ljava/util/concurrent/Executor;Ljava/util/function/Function;)Ljava/util/concurrent/CompletableFuture;", "<V:Ljava/lang/Object;>(Ljava/lang/Object;Ljava/util/concurrent/Executor;Ljava/util/function/Function<-TT;+TV;>;)Ljava/util/concurrent/CompletableFuture<TV;>;", $PRIVATE, $method(CompletableFuture, uniApplyNow, CompletableFuture*, Object$*, $Executor*, $Function*)},
	{"uniApplyStage", "(Ljava/util/concurrent/Executor;Ljava/util/function/Function;)Ljava/util/concurrent/CompletableFuture;", "<V:Ljava/lang/Object;>(Ljava/util/concurrent/Executor;Ljava/util/function/Function<-TT;+TV;>;)Ljava/util/concurrent/CompletableFuture<TV;>;", $PRIVATE, $method(CompletableFuture, uniApplyStage, CompletableFuture*, $Executor*, $Function*)},
	{"uniAsMinimalStage", "()Ljava/util/concurrent/CompletableFuture$MinimalStage;", "()Ljava/util/concurrent/CompletableFuture$MinimalStage<TT;>;", $PRIVATE, $method(CompletableFuture, uniAsMinimalStage, $CompletableFuture$MinimalStage*)},
	{"uniComposeExceptionallyStage", "(Ljava/util/concurrent/Executor;Ljava/util/function/Function;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/Executor;Ljava/util/function/Function<Ljava/lang/Throwable;+Ljava/util/concurrent/CompletionStage<TT;>;>;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PRIVATE, $method(CompletableFuture, uniComposeExceptionallyStage, CompletableFuture*, $Executor*, $Function*)},
	{"uniComposeStage", "(Ljava/util/concurrent/Executor;Ljava/util/function/Function;)Ljava/util/concurrent/CompletableFuture;", "<V:Ljava/lang/Object;>(Ljava/util/concurrent/Executor;Ljava/util/function/Function<-TT;+Ljava/util/concurrent/CompletionStage<TV;>;>;)Ljava/util/concurrent/CompletableFuture<TV;>;", $PRIVATE, $method(CompletableFuture, uniComposeStage, CompletableFuture*, $Executor*, $Function*)},
	{"uniCopyStage", "(Ljava/util/concurrent/CompletableFuture;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;T:TU;>(Ljava/util/concurrent/CompletableFuture<TT;>;)Ljava/util/concurrent/CompletableFuture<TU;>;", $PRIVATE | $STATIC, $staticMethod(CompletableFuture, uniCopyStage, CompletableFuture*, CompletableFuture*)},
	{"uniExceptionally", "(Ljava/lang/Object;Ljava/util/function/Function;Ljava/util/concurrent/CompletableFuture$UniExceptionally;)Z", "(Ljava/lang/Object;Ljava/util/function/Function<-Ljava/lang/Throwable;+TT;>;Ljava/util/concurrent/CompletableFuture$UniExceptionally<TT;>;)Z", $FINAL, $method(CompletableFuture, uniExceptionally, bool, Object$*, $Function*, $CompletableFuture$UniExceptionally*)},
	{"uniExceptionallyStage", "(Ljava/util/concurrent/Executor;Ljava/util/function/Function;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/Executor;Ljava/util/function/Function<Ljava/lang/Throwable;+TT;>;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PRIVATE, $method(CompletableFuture, uniExceptionallyStage, CompletableFuture*, $Executor*, $Function*)},
	{"uniHandle", "(Ljava/lang/Object;Ljava/util/function/BiFunction;Ljava/util/concurrent/CompletableFuture$UniHandle;)Z", "<S:Ljava/lang/Object;>(Ljava/lang/Object;Ljava/util/function/BiFunction<-TS;Ljava/lang/Throwable;+TT;>;Ljava/util/concurrent/CompletableFuture$UniHandle<TS;TT;>;)Z", $FINAL, $method(CompletableFuture, uniHandle, bool, Object$*, $BiFunction*, $CompletableFuture$UniHandle*)},
	{"uniHandleStage", "(Ljava/util/concurrent/Executor;Ljava/util/function/BiFunction;)Ljava/util/concurrent/CompletableFuture;", "<V:Ljava/lang/Object;>(Ljava/util/concurrent/Executor;Ljava/util/function/BiFunction<-TT;Ljava/lang/Throwable;+TV;>;)Ljava/util/concurrent/CompletableFuture<TV;>;", $PRIVATE, $method(CompletableFuture, uniHandleStage, CompletableFuture*, $Executor*, $BiFunction*)},
	{"uniRunNow", "(Ljava/lang/Object;Ljava/util/concurrent/Executor;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/lang/Object;Ljava/util/concurrent/Executor;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PRIVATE, $method(CompletableFuture, uniRunNow, CompletableFuture*, Object$*, $Executor*, $Runnable*)},
	{"uniRunStage", "(Ljava/util/concurrent/Executor;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/Executor;Ljava/lang/Runnable;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PRIVATE, $method(CompletableFuture, uniRunStage, CompletableFuture*, $Executor*, $Runnable*)},
	{"uniWhenComplete", "(Ljava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture$UniWhenComplete;)Z", "(Ljava/lang/Object;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/CompletableFuture$UniWhenComplete<TT;>;)Z", $FINAL, $method(CompletableFuture, uniWhenComplete, bool, Object$*, $BiConsumer*, $CompletableFuture$UniWhenComplete*)},
	{"uniWhenCompleteStage", "(Ljava/util/concurrent/Executor;Ljava/util/function/BiConsumer;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/Executor;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PRIVATE, $method(CompletableFuture, uniWhenCompleteStage, CompletableFuture*, $Executor*, $BiConsumer*)},
	{"unipush", "(Ljava/util/concurrent/CompletableFuture$Completion;)V", nullptr, $FINAL, $method(CompletableFuture, unipush, void, $CompletableFuture$Completion*)},
	{"waitingGet", "(Z)Ljava/lang/Object;", nullptr, $PRIVATE, $method(CompletableFuture, waitingGet, $Object*, bool)},
	{"whenComplete", "(Ljava/util/function/BiConsumer;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture, whenComplete, $CompletionStage*, $BiConsumer*)},
	{"whenCompleteAsync", "(Ljava/util/function/BiConsumer;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture, whenCompleteAsync, $CompletionStage*, $BiConsumer*)},
	{"whenCompleteAsync", "(Ljava/util/function/BiConsumer;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $virtualMethod(CompletableFuture, whenCompleteAsync, $CompletionStage*, $BiConsumer*, $Executor*)},
	{}
};

$InnerClassInfo _CompletableFuture_InnerClassesInfo_[] = {
	{"java.util.concurrent.CompletableFuture$MinimalStage", "java.util.concurrent.CompletableFuture", "MinimalStage", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$Canceller", "java.util.concurrent.CompletableFuture", "Canceller", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$DelayedCompleter", "java.util.concurrent.CompletableFuture", "DelayedCompleter", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$Timeout", "java.util.concurrent.CompletableFuture", "Timeout", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$TaskSubmitter", "java.util.concurrent.CompletableFuture", "TaskSubmitter", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$DelayedExecutor", "java.util.concurrent.CompletableFuture", "DelayedExecutor", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$Delayer", "java.util.concurrent.CompletableFuture", "Delayer", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$Signaller", "java.util.concurrent.CompletableFuture", "Signaller", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$AsyncRun", "java.util.concurrent.CompletableFuture", "AsyncRun", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$AsyncSupply", "java.util.concurrent.CompletableFuture", "AsyncSupply", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$AnyOf", "java.util.concurrent.CompletableFuture", "AnyOf", $STATIC},
	{"java.util.concurrent.CompletableFuture$OrRun", "java.util.concurrent.CompletableFuture", "OrRun", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$OrAccept", "java.util.concurrent.CompletableFuture", "OrAccept", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$OrApply", "java.util.concurrent.CompletableFuture", "OrApply", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$BiRelay", "java.util.concurrent.CompletableFuture", "BiRelay", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$BiRun", "java.util.concurrent.CompletableFuture", "BiRun", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$BiAccept", "java.util.concurrent.CompletableFuture", "BiAccept", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$BiApply", "java.util.concurrent.CompletableFuture", "BiApply", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$CoCompletion", "java.util.concurrent.CompletableFuture", "CoCompletion", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$BiCompletion", "java.util.concurrent.CompletableFuture", "BiCompletion", $STATIC | $ABSTRACT},
	{"java.util.concurrent.CompletableFuture$UniCompose", "java.util.concurrent.CompletableFuture", "UniCompose", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$UniRelay", "java.util.concurrent.CompletableFuture", "UniRelay", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$UniComposeExceptionally", "java.util.concurrent.CompletableFuture", "UniComposeExceptionally", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$UniExceptionally", "java.util.concurrent.CompletableFuture", "UniExceptionally", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$UniHandle", "java.util.concurrent.CompletableFuture", "UniHandle", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$UniWhenComplete", "java.util.concurrent.CompletableFuture", "UniWhenComplete", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$UniRun", "java.util.concurrent.CompletableFuture", "UniRun", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$UniAccept", "java.util.concurrent.CompletableFuture", "UniAccept", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$UniApply", "java.util.concurrent.CompletableFuture", "UniApply", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$UniCompletion", "java.util.concurrent.CompletableFuture", "UniCompletion", $STATIC | $ABSTRACT},
	{"java.util.concurrent.CompletableFuture$Completion", "java.util.concurrent.CompletableFuture", "Completion", $STATIC | $ABSTRACT},
	{"java.util.concurrent.CompletableFuture$ThreadPerTaskExecutor", "java.util.concurrent.CompletableFuture", "ThreadPerTaskExecutor", $STATIC | $FINAL},
	{"java.util.concurrent.CompletableFuture$AsynchronousCompletionTask", "java.util.concurrent.CompletableFuture", "AsynchronousCompletionTask", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.concurrent.CompletableFuture$AltResult", "java.util.concurrent.CompletableFuture", "AltResult", $STATIC | $FINAL},
	{}
};

$ClassInfo _CompletableFuture_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.concurrent.CompletableFuture",
	"java.lang.Object",
	"java.util.concurrent.Future,java.util.concurrent.CompletionStage",
	_CompletableFuture_FieldInfo_,
	_CompletableFuture_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;Ljava/util/concurrent/Future<TT;>;Ljava/util/concurrent/CompletionStage<TT;>;",
	nullptr,
	_CompletableFuture_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.concurrent.CompletableFuture$MinimalStage,java.util.concurrent.CompletableFuture$Canceller,java.util.concurrent.CompletableFuture$DelayedCompleter,java.util.concurrent.CompletableFuture$Timeout,java.util.concurrent.CompletableFuture$TaskSubmitter,java.util.concurrent.CompletableFuture$DelayedExecutor,java.util.concurrent.CompletableFuture$Delayer,java.util.concurrent.CompletableFuture$Delayer$DaemonThreadFactory,java.util.concurrent.CompletableFuture$Signaller,java.util.concurrent.CompletableFuture$AsyncRun,java.util.concurrent.CompletableFuture$AsyncSupply,java.util.concurrent.CompletableFuture$AnyOf,java.util.concurrent.CompletableFuture$OrRun,java.util.concurrent.CompletableFuture$OrAccept,java.util.concurrent.CompletableFuture$OrApply,java.util.concurrent.CompletableFuture$BiRelay,java.util.concurrent.CompletableFuture$BiRun,java.util.concurrent.CompletableFuture$BiAccept,java.util.concurrent.CompletableFuture$BiApply,java.util.concurrent.CompletableFuture$CoCompletion,java.util.concurrent.CompletableFuture$BiCompletion,java.util.concurrent.CompletableFuture$UniCompose,java.util.concurrent.CompletableFuture$UniRelay,java.util.concurrent.CompletableFuture$UniComposeExceptionally,java.util.concurrent.CompletableFuture$UniExceptionally,java.util.concurrent.CompletableFuture$UniHandle,java.util.concurrent.CompletableFuture$UniWhenComplete,java.util.concurrent.CompletableFuture$UniRun,java.util.concurrent.CompletableFuture$UniAccept,java.util.concurrent.CompletableFuture$UniApply,java.util.concurrent.CompletableFuture$UniCompletion,java.util.concurrent.CompletableFuture$Completion,java.util.concurrent.CompletableFuture$ThreadPerTaskExecutor,java.util.concurrent.CompletableFuture$AsynchronousCompletionTask,java.util.concurrent.CompletableFuture$AltResult"
};

$Object* allocate$CompletableFuture($Class* clazz) {
	return $of($alloc(CompletableFuture));
}

int32_t CompletableFuture::hashCode() {
	 return this->$Future::hashCode();
}

bool CompletableFuture::equals(Object$* obj) {
	 return this->$Future::equals(obj);
}

$Object* CompletableFuture::clone() {
	 return this->$Future::clone();
}

void CompletableFuture::finalize() {
	this->$Future::finalize();
}

$CompletableFuture$AltResult* CompletableFuture::NIL = nullptr;
bool CompletableFuture::USE_COMMON_POOL = false;
$Executor* CompletableFuture::ASYNC_POOL = nullptr;
$VarHandle* CompletableFuture::RESULT = nullptr;
$VarHandle* CompletableFuture::STACK = nullptr;
$VarHandle* CompletableFuture::NEXT = nullptr;

bool CompletableFuture::internalComplete(Object$* r) {
	return $nc(CompletableFuture::RESULT)->compareAndSet($$new($ObjectArray, {$of(this), ($Object*)nullptr, r}));
}

bool CompletableFuture::tryPushStack($CompletableFuture$Completion* c) {
	$useLocalCurrentObjectStackCache();
	$var($CompletableFuture$Completion, h, this->stack);
	$nc(CompletableFuture::NEXT)->set($$new($ObjectArray, {$of(c), $of(h)}));
	return $nc(CompletableFuture::STACK)->compareAndSet($$new($ObjectArray, {$of(this), $of(h), $of(c)}));
}

void CompletableFuture::pushStack($CompletableFuture$Completion* c) {
	do {
	} while (!tryPushStack(c));
}

bool CompletableFuture::completeNull() {
	return $nc(CompletableFuture::RESULT)->compareAndSet($$new($ObjectArray, {$of(this), ($Object*)nullptr, $of(CompletableFuture::NIL)}));
}

$Object* CompletableFuture::encodeValue(Object$* t) {
	return $of((t == nullptr) ? $of(CompletableFuture::NIL) : $of(t));
}

bool CompletableFuture::completeValue(Object$* t) {
	return $nc(CompletableFuture::RESULT)->compareAndSet($$new($ObjectArray, {$of(this), ($Object*)nullptr, (t == nullptr) ? $of(CompletableFuture::NIL) : $of(t)}));
}

$CompletableFuture$AltResult* CompletableFuture::encodeThrowable($Throwable* x) {
	$init(CompletableFuture);
	return $new($CompletableFuture$AltResult, ($instanceOf($CompletionException, x)) ? x : static_cast<$Throwable*>($$new($CompletionException, x)));
}

bool CompletableFuture::completeThrowable($Throwable* x) {
	$useLocalCurrentObjectStackCache();
	return $nc(CompletableFuture::RESULT)->compareAndSet($$new($ObjectArray, {$of(this), ($Object*)nullptr, $($of(encodeThrowable(x)))}));
}

$Object* CompletableFuture::encodeThrowable($Throwable* x$renamed, Object$* r) {
	$init(CompletableFuture);
	$var($Throwable, x, x$renamed);
	if (!($instanceOf($CompletionException, x))) {
		$assign(x, $new($CompletionException, x));
	} else if ($instanceOf($CompletableFuture$AltResult, r) && x == $nc(($cast($CompletableFuture$AltResult, r)))->ex) {
		return $of(r);
	}
	return $of($new($CompletableFuture$AltResult, x));
}

bool CompletableFuture::completeThrowable($Throwable* x, Object$* r) {
	$useLocalCurrentObjectStackCache();
	return $nc(CompletableFuture::RESULT)->compareAndSet($$new($ObjectArray, {$of(this), ($Object*)nullptr, $(encodeThrowable(x, r))}));
}

$Object* CompletableFuture::encodeOutcome(Object$* t, $Throwable* x) {
	return $of((x == nullptr) ? (t == nullptr) ? $of(CompletableFuture::NIL) : $of(t) : $of(encodeThrowable(x)));
}

$Object* CompletableFuture::encodeRelay(Object$* r$renamed) {
	$init(CompletableFuture);
	$useLocalCurrentObjectStackCache();
	$var($Object, r, r$renamed);
	$var($Throwable, x, nullptr);
	bool var$0 = $instanceOf($CompletableFuture$AltResult, r) && ($assign(x, $nc(($cast($CompletableFuture$AltResult, r)))->ex)) != nullptr;
	if (var$0 && !($instanceOf($CompletionException, x))) {
		$assign(r, $new($CompletableFuture$AltResult, $$new($CompletionException, x)));
	}
	return $of(r);
}

bool CompletableFuture::completeRelay(Object$* r) {
	$useLocalCurrentObjectStackCache();
	return $nc(CompletableFuture::RESULT)->compareAndSet($$new($ObjectArray, {$of(this), ($Object*)nullptr, $(encodeRelay(r))}));
}

$Object* CompletableFuture::reportGet(Object$* r) {
	$init(CompletableFuture);
	$useLocalCurrentObjectStackCache();
	if (r == nullptr) {
		$throwNew($InterruptedException);
	}
	if ($instanceOf($CompletableFuture$AltResult, r)) {
		$var($Throwable, x, nullptr);
		$var($Throwable, cause, nullptr);
		if (($assign(x, $nc(($cast($CompletableFuture$AltResult, r)))->ex)) == nullptr) {
			return $of(nullptr);
		}
		if ($instanceOf($CancellationException, x)) {
			$throw($cast($CancellationException, x));
		}
		if (($instanceOf($CompletionException, x)) && ($assign(cause, $nc(x)->getCause())) != nullptr) {
			$assign(x, cause);
		}
		$throwNew($ExecutionException, x);
	}
	return $of(r);
}

$Object* CompletableFuture::reportJoin(Object$* r) {
	$init(CompletableFuture);
	if ($instanceOf($CompletableFuture$AltResult, r)) {
		$var($Throwable, x, nullptr);
		if (($assign(x, $nc(($cast($CompletableFuture$AltResult, r)))->ex)) == nullptr) {
			return $of(nullptr);
		}
		if ($instanceOf($CancellationException, x)) {
			$throw($cast($CancellationException, x));
		}
		if ($instanceOf($CompletionException, x)) {
			$throw($cast($CompletionException, x));
		}
		$throwNew($CompletionException, x);
	}
	return $of(r);
}

$Executor* CompletableFuture::screenExecutor($Executor* e) {
	$init(CompletableFuture);
	if (!CompletableFuture::USE_COMMON_POOL && $equals(e, $ForkJoinPool::commonPool())) {
		return CompletableFuture::ASYNC_POOL;
	}
	if (e == nullptr) {
		$throwNew($NullPointerException);
	}
	return e;
}

void CompletableFuture::postComplete() {
	$useLocalCurrentObjectStackCache();
	$var(CompletableFuture, f, this);
	$var($CompletableFuture$Completion, h, nullptr);
	while (true) {
		bool var$0 = ($assign(h, $nc(f)->stack)) != nullptr;
		if (!var$0) {
			bool var$1 = f != this;
			var$0 = (var$1 && ($assign(h, $nc(($assign(f, this)))->stack)) != nullptr);
		}
		if (!(var$0)) {
			break;
		}
		{
			$var(CompletableFuture, d, nullptr);
			$var($CompletableFuture$Completion, t, nullptr);
			if ($nc(CompletableFuture::STACK)->compareAndSet($$new($ObjectArray, {$of(f), $of(h), $of(($assign(t, $nc(h)->next)))}))) {
				if (t != nullptr) {
					if (f != this) {
						pushStack(h);
						continue;
					}
					$nc(CompletableFuture::NEXT)->compareAndSet($$new($ObjectArray, {$of(h), $of(t), ($Object*)nullptr}));
				}
				$assign(f, ($assign(d, $nc(h)->tryFire(CompletableFuture::NESTED))) == nullptr ? this : d);
			}
		}
	}
}

void CompletableFuture::cleanStack() {
	$useLocalCurrentObjectStackCache();
	$var($CompletableFuture$Completion, p, this->stack);
	for (bool unlinked = false;;) {
		if (p == nullptr) {
			return;
		} else if ($nc(p)->isLive()) {
			if (unlinked) {
				return;
			} else {
				break;
			}
		} else {
			$var($Object, var$1, $of(p));
			if ($nc(CompletableFuture::STACK)->weakCompareAndSet($$new($ObjectArray, {$of(this), var$1, ($of(($assign(p, p->next))))}))) {
				unlinked = true;
			} else {
				$assign(p, this->stack);
			}
		}
	}
	{
		$var($CompletableFuture$Completion, q, $nc(p)->next);
		for (; q != nullptr;) {
			$var($CompletableFuture$Completion, s, q->next);
			if (q->isLive()) {
				$assign(p, q);
				$assign(q, s);
			} else if ($nc(CompletableFuture::NEXT)->weakCompareAndSet($$new($ObjectArray, {$of(p), $of(q), $of(s)}))) {
				break;
			} else {
				$assign(q, p->next);
			}
		}
	}
}

void CompletableFuture::unipush($CompletableFuture$Completion* c) {
	$useLocalCurrentObjectStackCache();
	if (c != nullptr) {
		while (!tryPushStack(c)) {
			if (this->result != nullptr) {
				$nc(CompletableFuture::NEXT)->set($$new($ObjectArray, {$of(c), ($Object*)nullptr}));
				break;
			}
		}
		if (this->result != nullptr) {
			c->tryFire(CompletableFuture::SYNC);
		}
	}
}

CompletableFuture* CompletableFuture::postFire(CompletableFuture* a, int32_t mode) {
	if (a != nullptr && a->stack != nullptr) {
		$var($Object, r, nullptr);
		if (($assign(r, a->result)) == nullptr) {
			a->cleanStack();
		}
		if (mode >= 0 && (r != nullptr || a->result != nullptr)) {
			a->postComplete();
		}
	}
	if (this->result != nullptr && this->stack != nullptr) {
		if (mode < 0) {
			return this;
		} else {
			postComplete();
		}
	}
	return nullptr;
}

CompletableFuture* CompletableFuture::uniApplyStage($Executor* e, $Function* f) {
	$useLocalCurrentObjectStackCache();
	if (f == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($Object, r, nullptr);
	if (($assign(r, this->result)) != nullptr) {
		return uniApplyNow(r, e, f);
	}
	$var(CompletableFuture, d, newIncompleteFuture());
	unipush($$new($CompletableFuture$UniApply, e, d, this, f));
	return d;
}

CompletableFuture* CompletableFuture::uniApplyNow(Object$* r$renamed, $Executor* e, $Function* f) {
	$useLocalCurrentObjectStackCache();
	$var($Object, r, r$renamed);
	$var($Throwable, x, nullptr);
	$var(CompletableFuture, d, newIncompleteFuture());
	if ($instanceOf($CompletableFuture$AltResult, r)) {
		if (($assign(x, $nc(($cast($CompletableFuture$AltResult, r)))->ex)) != nullptr) {
			$set($nc(d), result, encodeThrowable(x, r));
			return d;
		}
		$assign(r, nullptr);
	}
	try {
		if (e != nullptr) {
			e->execute($$new($CompletableFuture$UniApply, nullptr, d, this, f));
		} else {
			$var($Object, t, r);
			$set($nc(d), result, d->encodeValue($($nc(f)->apply(t))));
		}
	} catch ($Throwable& ex) {
		$set($nc(d), result, encodeThrowable(ex));
	}
	return d;
}

CompletableFuture* CompletableFuture::uniAcceptStage($Executor* e, $Consumer* f) {
	$useLocalCurrentObjectStackCache();
	if (f == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($Object, r, nullptr);
	if (($assign(r, this->result)) != nullptr) {
		return uniAcceptNow(r, e, f);
	}
	$var(CompletableFuture, d, newIncompleteFuture());
	unipush($$new($CompletableFuture$UniAccept, e, d, this, f));
	return d;
}

CompletableFuture* CompletableFuture::uniAcceptNow(Object$* r$renamed, $Executor* e, $Consumer* f) {
	$useLocalCurrentObjectStackCache();
	$var($Object, r, r$renamed);
	$var($Throwable, x, nullptr);
	$var(CompletableFuture, d, newIncompleteFuture());
	if ($instanceOf($CompletableFuture$AltResult, r)) {
		if (($assign(x, $nc(($cast($CompletableFuture$AltResult, r)))->ex)) != nullptr) {
			$set($nc(d), result, encodeThrowable(x, r));
			return d;
		}
		$assign(r, nullptr);
	}
	try {
		if (e != nullptr) {
			e->execute($$new($CompletableFuture$UniAccept, nullptr, d, this, f));
		} else {
			$var($Object, t, r);
			$nc(f)->accept(t);
			$set($nc(d), result, CompletableFuture::NIL);
		}
	} catch ($Throwable& ex) {
		$set($nc(d), result, encodeThrowable(ex));
	}
	return d;
}

CompletableFuture* CompletableFuture::uniRunStage($Executor* e, $Runnable* f) {
	$useLocalCurrentObjectStackCache();
	if (f == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($Object, r, nullptr);
	if (($assign(r, this->result)) != nullptr) {
		return uniRunNow(r, e, f);
	}
	$var(CompletableFuture, d, newIncompleteFuture());
	unipush($$new($CompletableFuture$UniRun, e, d, this, f));
	return d;
}

CompletableFuture* CompletableFuture::uniRunNow(Object$* r, $Executor* e, $Runnable* f) {
	$useLocalCurrentObjectStackCache();
	$var($Throwable, x, nullptr);
	$var(CompletableFuture, d, newIncompleteFuture());
	if ($instanceOf($CompletableFuture$AltResult, r) && ($assign(x, $nc(($cast($CompletableFuture$AltResult, r)))->ex)) != nullptr) {
		$set($nc(d), result, encodeThrowable(x, r));
	} else {
		try {
			if (e != nullptr) {
				e->execute($$new($CompletableFuture$UniRun, nullptr, d, this, f));
			} else {
				$nc(f)->run();
				$set($nc(d), result, CompletableFuture::NIL);
			}
		} catch ($Throwable& ex) {
			$set($nc(d), result, encodeThrowable(ex));
		}
	}
	return d;
}

bool CompletableFuture::uniWhenComplete(Object$* r, $BiConsumer* f, $CompletableFuture$UniWhenComplete* c) {
	$useLocalCurrentObjectStackCache();
	$var($Object, t, nullptr);
	$var($Throwable, x, nullptr);
	if (this->result == nullptr) {
		try {
			if (c != nullptr && !c->claim()) {
				return false;
			}
			if ($instanceOf($CompletableFuture$AltResult, r)) {
				$assign(x, $nc(($cast($CompletableFuture$AltResult, r)))->ex);
				$assign(t, nullptr);
			} else {
				$var($Object, tr, r);
				$assign(t, tr);
			}
			$nc(f)->accept(t, x);
			if (x == nullptr) {
				internalComplete(r);
				return true;
			}
		} catch ($Throwable& ex) {
			if (x == nullptr) {
				$assign(x, ex);
			} else if (x != ex) {
				$nc(x)->addSuppressed(ex);
			}
		}
		completeThrowable(x, r);
	}
	return true;
}

CompletableFuture* CompletableFuture::uniWhenCompleteStage($Executor* e, $BiConsumer* f) {
	$useLocalCurrentObjectStackCache();
	if (f == nullptr) {
		$throwNew($NullPointerException);
	}
	$var(CompletableFuture, d, newIncompleteFuture());
	$var($Object, r, nullptr);
	if (($assign(r, this->result)) == nullptr) {
		unipush($$new($CompletableFuture$UniWhenComplete, e, d, this, f));
	} else if (e == nullptr) {
		$nc(d)->uniWhenComplete(r, f, nullptr);
	} else {
		try {
			$nc(e)->execute($$new($CompletableFuture$UniWhenComplete, nullptr, d, this, f));
		} catch ($Throwable& ex) {
			$set($nc(d), result, encodeThrowable(ex));
		}
	}
	return d;
}

bool CompletableFuture::uniHandle(Object$* r, $BiFunction* f, $CompletableFuture$UniHandle* c) {
	$useLocalCurrentObjectStackCache();
	$var($Object, s, nullptr);
	$var($Throwable, x, nullptr);
	if (this->result == nullptr) {
		try {
			if (c != nullptr && !c->claim()) {
				return false;
			}
			if ($instanceOf($CompletableFuture$AltResult, r)) {
				$assign(x, $nc(($cast($CompletableFuture$AltResult, r)))->ex);
				$assign(s, nullptr);
			} else {
				$assign(x, nullptr);
				$var($Object, ss, r);
				$assign(s, ss);
			}
			completeValue($($nc(f)->apply(s, x)));
		} catch ($Throwable& ex) {
			completeThrowable(ex);
		}
	}
	return true;
}

CompletableFuture* CompletableFuture::uniHandleStage($Executor* e, $BiFunction* f) {
	$useLocalCurrentObjectStackCache();
	if (f == nullptr) {
		$throwNew($NullPointerException);
	}
	$var(CompletableFuture, d, newIncompleteFuture());
	$var($Object, r, nullptr);
	if (($assign(r, this->result)) == nullptr) {
		unipush($$new($CompletableFuture$UniHandle, e, d, this, f));
	} else if (e == nullptr) {
		$nc(d)->uniHandle(r, f, nullptr);
	} else {
		try {
			$nc(e)->execute($$new($CompletableFuture$UniHandle, nullptr, d, this, f));
		} catch ($Throwable& ex) {
			$set($nc(d), result, encodeThrowable(ex));
		}
	}
	return d;
}

bool CompletableFuture::uniExceptionally(Object$* r, $Function* f, $CompletableFuture$UniExceptionally* c) {
	$useLocalCurrentObjectStackCache();
	$var($Throwable, x, nullptr);
	if (this->result == nullptr) {
		try {
			if (c != nullptr && !c->claim()) {
				return false;
			}
			if ($instanceOf($CompletableFuture$AltResult, r) && ($assign(x, $nc(($cast($CompletableFuture$AltResult, r)))->ex)) != nullptr) {
				completeValue($($nc(f)->apply(x)));
			} else {
				internalComplete(r);
			}
		} catch ($Throwable& ex) {
			completeThrowable(ex);
		}
	}
	return true;
}

CompletableFuture* CompletableFuture::uniExceptionallyStage($Executor* e, $Function* f) {
	$useLocalCurrentObjectStackCache();
	if (f == nullptr) {
		$throwNew($NullPointerException);
	}
	$var(CompletableFuture, d, newIncompleteFuture());
	$var($Object, r, nullptr);
	if (($assign(r, this->result)) == nullptr) {
		unipush($$new($CompletableFuture$UniExceptionally, e, d, this, f));
	} else if (e == nullptr) {
		$nc(d)->uniExceptionally(r, f, nullptr);
	} else {
		try {
			$nc(e)->execute($$new($CompletableFuture$UniExceptionally, nullptr, d, this, f));
		} catch ($Throwable& ex) {
			$set($nc(d), result, encodeThrowable(ex));
		}
	}
	return d;
}

CompletableFuture* CompletableFuture::uniComposeExceptionallyStage($Executor* e, $Function* f) {
	$useLocalCurrentObjectStackCache();
	if (f == nullptr) {
		$throwNew($NullPointerException);
	}
	$var(CompletableFuture, d, newIncompleteFuture());
	$var($Object, r, nullptr);
	$var($Object, s, nullptr);
	$var($Throwable, x, nullptr);
	if (($assign(r, this->result)) == nullptr) {
		unipush($$new($CompletableFuture$UniComposeExceptionally, e, d, this, f));
	} else if (!($instanceOf($CompletableFuture$AltResult, r)) || ($assign(x, $nc(($cast($CompletableFuture$AltResult, r)))->ex)) == nullptr) {
		$nc(d)->internalComplete(r);
	} else {
		try {
			if (e != nullptr) {
				e->execute($$new($CompletableFuture$UniComposeExceptionally, nullptr, d, this, f));
			} else {
				$var(CompletableFuture, g, $nc(($cast($CompletionStage, $($nc(f)->apply(x)))))->toCompletableFuture());
				if (($assign(s, $nc(g)->result)) != nullptr) {
					$set($nc(d), result, encodeRelay(s));
				} else {
					g->unipush($$new($CompletableFuture$UniRelay, d, g));
				}
			}
		} catch ($Throwable& ex) {
			$set($nc(d), result, encodeThrowable(ex));
		}
	}
	return d;
}

CompletableFuture* CompletableFuture::uniCopyStage(CompletableFuture* src) {
	$init(CompletableFuture);
	$useLocalCurrentObjectStackCache();
	$var($Object, r, nullptr);
	$var(CompletableFuture, d, $nc(src)->newIncompleteFuture());
	if (($assign(r, src->result)) != nullptr) {
		$set($nc(d), result, encodeRelay(r));
	} else {
		src->unipush($$new($CompletableFuture$UniRelay, d, src));
	}
	return d;
}

$CompletableFuture$MinimalStage* CompletableFuture::uniAsMinimalStage() {
	$useLocalCurrentObjectStackCache();
	$var($Object, r, nullptr);
	if (($assign(r, this->result)) != nullptr) {
		return $new($CompletableFuture$MinimalStage, $(encodeRelay(r)));
	}
	$var($CompletableFuture$MinimalStage, d, $new($CompletableFuture$MinimalStage));
	unipush($$new($CompletableFuture$UniRelay, d, this));
	return d;
}

CompletableFuture* CompletableFuture::uniComposeStage($Executor* e, $Function* f) {
	$useLocalCurrentObjectStackCache();
	if (f == nullptr) {
		$throwNew($NullPointerException);
	}
	$var(CompletableFuture, d, newIncompleteFuture());
	$var($Object, r, nullptr);
	$var($Object, s, nullptr);
	$var($Throwable, x, nullptr);
	if (($assign(r, this->result)) == nullptr) {
		unipush($$new($CompletableFuture$UniCompose, e, d, this, f));
	} else {
		if ($instanceOf($CompletableFuture$AltResult, r)) {
			if (($assign(x, $nc(($cast($CompletableFuture$AltResult, r)))->ex)) != nullptr) {
				$set($nc(d), result, encodeThrowable(x, r));
				return d;
			}
			$assign(r, nullptr);
		}
		try {
			if (e != nullptr) {
				e->execute($$new($CompletableFuture$UniCompose, nullptr, d, this, f));
			} else {
				$var($Object, t, r);
				$var(CompletableFuture, g, $nc(($cast($CompletionStage, $($nc(f)->apply(t)))))->toCompletableFuture());
				if (($assign(s, $nc(g)->result)) != nullptr) {
					$set($nc(d), result, encodeRelay(s));
				} else {
					g->unipush($$new($CompletableFuture$UniRelay, d, g));
				}
			}
		} catch ($Throwable& ex) {
			$set($nc(d), result, encodeThrowable(ex));
		}
	}
	return d;
}

void CompletableFuture::bipush(CompletableFuture* b, $CompletableFuture$BiCompletion* c) {
	$useLocalCurrentObjectStackCache();
	if (c != nullptr) {
		while (this->result == nullptr) {
			if (tryPushStack(c)) {
				if ($nc(b)->result == nullptr) {
					b->unipush($$new($CompletableFuture$CoCompletion, c));
				} else if (this->result != nullptr) {
					c->tryFire(CompletableFuture::SYNC);
				}
				return;
			}
		}
		$nc(b)->unipush(c);
	}
}

CompletableFuture* CompletableFuture::postFire(CompletableFuture* a, CompletableFuture* b, int32_t mode) {
	if (b != nullptr && b->stack != nullptr) {
		$var($Object, r, nullptr);
		if (($assign(r, b->result)) == nullptr) {
			b->cleanStack();
		}
		if (mode >= 0 && (r != nullptr || b->result != nullptr)) {
			b->postComplete();
		}
	}
	return postFire(a, mode);
}

bool CompletableFuture::biApply(Object$* r$renamed, Object$* s$renamed, $BiFunction* f, $CompletableFuture$BiApply* c) {
	$useLocalCurrentObjectStackCache();
	$var($Object, r, r$renamed);
	$var($Object, s, s$renamed);
	$var($Throwable, x, nullptr);
	bool tryComplete$break = false;
	for (;;) {
		if (this->result == nullptr) {
			if ($instanceOf($CompletableFuture$AltResult, r)) {
				if (($assign(x, $nc(($cast($CompletableFuture$AltResult, r)))->ex)) != nullptr) {
					completeThrowable(x, r);
					tryComplete$break = true;
					break;
				}
				$assign(r, nullptr);
			}
			if ($instanceOf($CompletableFuture$AltResult, s)) {
				if (($assign(x, $nc(($cast($CompletableFuture$AltResult, s)))->ex)) != nullptr) {
					completeThrowable(x, s);
					tryComplete$break = true;
					break;
				}
				$assign(s, nullptr);
			}
			try {
				if (c != nullptr && !c->claim()) {
					return false;
				}
				$var($Object, rr, r);
				$var($Object, ss, s);
				completeValue($($nc(f)->apply(rr, ss)));
			} catch ($Throwable& ex) {
				completeThrowable(ex);
			}
		}
		break;
	}
	return true;
}

CompletableFuture* CompletableFuture::biApplyStage($Executor* e, $CompletionStage* o, $BiFunction* f) {
	$useLocalCurrentObjectStackCache();
	$var(CompletableFuture, b, nullptr);
	$var($Object, r, nullptr);
	$var($Object, s, nullptr);
	if (f == nullptr || ($assign(b, $nc(o)->toCompletableFuture())) == nullptr) {
		$throwNew($NullPointerException);
	}
	$var(CompletableFuture, d, newIncompleteFuture());
	if (($assign(r, this->result)) == nullptr || ($assign(s, $nc(b)->result)) == nullptr) {
		bipush(b, $$new($CompletableFuture$BiApply, e, d, this, b, f));
	} else if (e == nullptr) {
		$nc(d)->biApply(r, s, f, nullptr);
	} else {
		try {
			$nc(e)->execute($$new($CompletableFuture$BiApply, nullptr, d, this, b, f));
		} catch ($Throwable& ex) {
			$set($nc(d), result, encodeThrowable(ex));
		}
	}
	return d;
}

bool CompletableFuture::biAccept(Object$* r$renamed, Object$* s$renamed, $BiConsumer* f, $CompletableFuture$BiAccept* c) {
	$useLocalCurrentObjectStackCache();
	$var($Object, r, r$renamed);
	$var($Object, s, s$renamed);
	$var($Throwable, x, nullptr);
	bool tryComplete$break = false;
	for (;;) {
		if (this->result == nullptr) {
			if ($instanceOf($CompletableFuture$AltResult, r)) {
				if (($assign(x, $nc(($cast($CompletableFuture$AltResult, r)))->ex)) != nullptr) {
					completeThrowable(x, r);
					tryComplete$break = true;
					break;
				}
				$assign(r, nullptr);
			}
			if ($instanceOf($CompletableFuture$AltResult, s)) {
				if (($assign(x, $nc(($cast($CompletableFuture$AltResult, s)))->ex)) != nullptr) {
					completeThrowable(x, s);
					tryComplete$break = true;
					break;
				}
				$assign(s, nullptr);
			}
			try {
				if (c != nullptr && !c->claim()) {
					return false;
				}
				$var($Object, rr, r);
				$var($Object, ss, s);
				$nc(f)->accept(rr, ss);
				completeNull();
			} catch ($Throwable& ex) {
				completeThrowable(ex);
			}
		}
		break;
	}
	return true;
}

CompletableFuture* CompletableFuture::biAcceptStage($Executor* e, $CompletionStage* o, $BiConsumer* f) {
	$useLocalCurrentObjectStackCache();
	$var(CompletableFuture, b, nullptr);
	$var($Object, r, nullptr);
	$var($Object, s, nullptr);
	if (f == nullptr || ($assign(b, $nc(o)->toCompletableFuture())) == nullptr) {
		$throwNew($NullPointerException);
	}
	$var(CompletableFuture, d, newIncompleteFuture());
	if (($assign(r, this->result)) == nullptr || ($assign(s, $nc(b)->result)) == nullptr) {
		bipush(b, $$new($CompletableFuture$BiAccept, e, d, this, b, f));
	} else if (e == nullptr) {
		$nc(d)->biAccept(r, s, f, nullptr);
	} else {
		try {
			$nc(e)->execute($$new($CompletableFuture$BiAccept, nullptr, d, this, b, f));
		} catch ($Throwable& ex) {
			$set($nc(d), result, encodeThrowable(ex));
		}
	}
	return d;
}

bool CompletableFuture::biRun(Object$* r, Object$* s, $Runnable* f, $CompletableFuture$BiRun* c) {
	$useLocalCurrentObjectStackCache();
	$var($Throwable, x, nullptr);
	$var($Object, z, nullptr);
	if (this->result == nullptr) {
		bool var$0 = ($instanceOf($CompletableFuture$AltResult, r) && ($assign(x, $nc((($cast($CompletableFuture$AltResult, ($assign(z, r))))))->ex)) != nullptr);
		if (var$0 || ($instanceOf($CompletableFuture$AltResult, s) && ($assign(x, $nc((($cast($CompletableFuture$AltResult, ($assign(z, s))))))->ex)) != nullptr)) {
			completeThrowable(x, z);
		} else {
			try {
				if (c != nullptr && !c->claim()) {
					return false;
				}
				$nc(f)->run();
				completeNull();
			} catch ($Throwable& ex) {
				completeThrowable(ex);
			}
		}
	}
	return true;
}

CompletableFuture* CompletableFuture::biRunStage($Executor* e, $CompletionStage* o, $Runnable* f) {
	$useLocalCurrentObjectStackCache();
	$var(CompletableFuture, b, nullptr);
	$var($Object, r, nullptr);
	$var($Object, s, nullptr);
	if (f == nullptr || ($assign(b, $nc(o)->toCompletableFuture())) == nullptr) {
		$throwNew($NullPointerException);
	}
	$var(CompletableFuture, d, newIncompleteFuture());
	if (($assign(r, this->result)) == nullptr || ($assign(s, $nc(b)->result)) == nullptr) {
		bipush(b, $$new($CompletableFuture$BiRun, e, d, this, b, f));
	} else if (e == nullptr) {
		$nc(d)->biRun(r, s, f, nullptr);
	} else {
		try {
			$nc(e)->execute($$new($CompletableFuture$BiRun, nullptr, d, this, b, f));
		} catch ($Throwable& ex) {
			$set($nc(d), result, encodeThrowable(ex));
		}
	}
	return d;
}

CompletableFuture* CompletableFuture::andTree($CompletableFutureArray* cfs, int32_t lo, int32_t hi) {
	$init(CompletableFuture);
	$useLocalCurrentObjectStackCache();
	$var(CompletableFuture, d, $new(CompletableFuture));
	if (lo > hi) {
		$set(d, result, CompletableFuture::NIL);
	} else {
		$var(CompletableFuture, a, nullptr);
		$var(CompletableFuture, b, nullptr);
		$var($Object, r, nullptr);
		$var($Object, s, nullptr);
		$var($Object, z, nullptr);
		$var($Throwable, x, nullptr);
		int32_t mid = (int32_t)((uint32_t)(lo + hi) >> 1);
		bool var$0 = ($assign(a, lo == mid ? $nc(cfs)->get(lo) : andTree(cfs, lo, mid))) == nullptr;
		if (var$0 || ($assign(b, lo == hi ? a : (hi == mid + 1) ? $nc(cfs)->get(hi) : andTree(cfs, mid + 1, hi))) == nullptr) {
			$throwNew($NullPointerException);
		}
		if (($assign(r, $nc(a)->result)) == nullptr || ($assign(s, $nc(b)->result)) == nullptr) {
			$nc(a)->bipush(b, $$new($CompletableFuture$BiRelay, d, a, b));
		} else {
			bool var$2 = ($instanceOf($CompletableFuture$AltResult, r) && ($assign(x, $nc((($cast($CompletableFuture$AltResult, ($assign(z, r))))))->ex)) != nullptr);
			if (var$2 || ($instanceOf($CompletableFuture$AltResult, s) && ($assign(x, $nc((($cast($CompletableFuture$AltResult, ($assign(z, s))))))->ex)) != nullptr)) {
				$set(d, result, encodeThrowable(x, z));
			} else {
				$set(d, result, CompletableFuture::NIL);
			}
		}
	}
	return d;
}

void CompletableFuture::orpush(CompletableFuture* b, $CompletableFuture$BiCompletion* c) {
	$useLocalCurrentObjectStackCache();
	if (c != nullptr) {
		while (!tryPushStack(c)) {
			if (this->result != nullptr) {
				$nc(CompletableFuture::NEXT)->set($$new($ObjectArray, {$of(c), ($Object*)nullptr}));
				break;
			}
		}
		if (this->result != nullptr) {
			c->tryFire(CompletableFuture::SYNC);
		} else {
			$nc(b)->unipush($$new($CompletableFuture$CoCompletion, c));
		}
	}
}

CompletableFuture* CompletableFuture::orApplyStage($Executor* e, $CompletionStage* o, $Function* f) {
	$useLocalCurrentObjectStackCache();
	$var(CompletableFuture, b, nullptr);
	if (f == nullptr || ($assign(b, $nc(o)->toCompletableFuture())) == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($Object, r, nullptr);
	$var(CompletableFuture, z, nullptr);
	bool var$0 = ($assign(r, $nc(($assign(z, this)))->result)) != nullptr;
	if (var$0 || ($assign(r, $nc(($assign(z, b)))->result)) != nullptr) {
		return $nc(z)->uniApplyNow(r, e, f);
	}
	$var(CompletableFuture, d, newIncompleteFuture());
	orpush(b, $$new($CompletableFuture$OrApply, e, d, this, b, f));
	return d;
}

CompletableFuture* CompletableFuture::orAcceptStage($Executor* e, $CompletionStage* o, $Consumer* f) {
	$useLocalCurrentObjectStackCache();
	$var(CompletableFuture, b, nullptr);
	if (f == nullptr || ($assign(b, $nc(o)->toCompletableFuture())) == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($Object, r, nullptr);
	$var(CompletableFuture, z, nullptr);
	bool var$0 = ($assign(r, $nc(($assign(z, this)))->result)) != nullptr;
	if (var$0 || ($assign(r, $nc(($assign(z, b)))->result)) != nullptr) {
		return $nc(z)->uniAcceptNow(r, e, f);
	}
	$var(CompletableFuture, d, newIncompleteFuture());
	orpush(b, $$new($CompletableFuture$OrAccept, e, d, this, b, f));
	return d;
}

CompletableFuture* CompletableFuture::orRunStage($Executor* e, $CompletionStage* o, $Runnable* f) {
	$useLocalCurrentObjectStackCache();
	$var(CompletableFuture, b, nullptr);
	if (f == nullptr || ($assign(b, $nc(o)->toCompletableFuture())) == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($Object, r, nullptr);
	$var(CompletableFuture, z, nullptr);
	bool var$0 = ($assign(r, $nc(($assign(z, this)))->result)) != nullptr;
	if (var$0 || ($assign(r, $nc(($assign(z, b)))->result)) != nullptr) {
		return $nc(z)->uniRunNow(r, e, f);
	}
	$var(CompletableFuture, d, newIncompleteFuture());
	orpush(b, $$new($CompletableFuture$OrRun, e, d, this, b, f));
	return d;
}

CompletableFuture* CompletableFuture::asyncSupplyStage($Executor* e, $Supplier* f) {
	$init(CompletableFuture);
	$useLocalCurrentObjectStackCache();
	if (f == nullptr) {
		$throwNew($NullPointerException);
	}
	$var(CompletableFuture, d, $new(CompletableFuture));
	$nc(e)->execute($$new($CompletableFuture$AsyncSupply, d, f));
	return d;
}

CompletableFuture* CompletableFuture::asyncRunStage($Executor* e, $Runnable* f) {
	$init(CompletableFuture);
	$useLocalCurrentObjectStackCache();
	if (f == nullptr) {
		$throwNew($NullPointerException);
	}
	$var(CompletableFuture, d, $new(CompletableFuture));
	$nc(e)->execute($$new($CompletableFuture$AsyncRun, d, f));
	return d;
}

$Object* CompletableFuture::waitingGet(bool interruptible) {
	$useLocalCurrentObjectStackCache();
	if (interruptible && $Thread::interrupted()) {
		return $of(nullptr);
	}
	$var($CompletableFuture$Signaller, q, nullptr);
	bool queued = false;
	$var($Object, r, nullptr);
	while (($assign(r, this->result)) == nullptr) {
		if (q == nullptr) {
			$assign(q, $new($CompletableFuture$Signaller, interruptible, 0, 0));
			if ($instanceOf($ForkJoinWorkerThread, $($Thread::currentThread()))) {
				$ForkJoinPool::helpAsyncBlocker($(defaultExecutor()), q);
			}
		} else if (!queued) {
			queued = tryPushStack(q);
		} else if (interruptible && $nc(q)->interrupted) {
			$set(q, thread, nullptr);
			cleanStack();
			return $of(nullptr);
		} else {
			try {
				$ForkJoinPool::managedBlock(q);
			} catch ($InterruptedException& ie) {
				q->interrupted = true;
			}
		}
	}
	if (q != nullptr) {
		$set(q, thread, nullptr);
		if (q->interrupted) {
			$($Thread::currentThread())->interrupt();
		}
	}
	postComplete();
	return $of(r);
}

$Object* CompletableFuture::timedGet(int64_t nanos) {
	$useLocalCurrentObjectStackCache();
	int64_t d = $System::nanoTime() + nanos;
	int64_t deadline = (d == (int64_t)0) ? (int64_t)1 : d;
	bool interrupted = false;
	bool queued = false;
	$var($CompletableFuture$Signaller, q, nullptr);
	$var($Object, r, nullptr);
	for (;;) {
		if (interrupted || (interrupted = $Thread::interrupted())) {
			break;
		} else if (($assign(r, this->result)) != nullptr) {
			break;
		} else if (nanos <= (int64_t)0) {
			break;
		} else if (q == nullptr) {
			$assign(q, $new($CompletableFuture$Signaller, true, nanos, deadline));
			if ($instanceOf($ForkJoinWorkerThread, $($Thread::currentThread()))) {
				$ForkJoinPool::helpAsyncBlocker($(defaultExecutor()), q);
			}
		} else if (!queued) {
			queued = tryPushStack(q);
		} else {
			try {
				$ForkJoinPool::managedBlock(q);
				interrupted = $nc(q)->interrupted;
				nanos = q->nanos;
			} catch ($InterruptedException& ie) {
				interrupted = true;
			}
		}
	}
	if (q != nullptr) {
		$set(q, thread, nullptr);
		if (r == nullptr) {
			cleanStack();
		}
	}
	if (r != nullptr) {
		if (interrupted) {
			$($Thread::currentThread())->interrupt();
		}
		postComplete();
		return $of(r);
	} else if (interrupted) {
		return $of(nullptr);
	} else {
		$throwNew($TimeoutException);
	}
}

void CompletableFuture::init$() {
}

void CompletableFuture::init$(Object$* r) {
	$nc(CompletableFuture::RESULT)->setRelease($$new($ObjectArray, {$of(this), r}));
}

CompletableFuture* CompletableFuture::supplyAsync($Supplier* supplier) {
	$init(CompletableFuture);
	return asyncSupplyStage(CompletableFuture::ASYNC_POOL, supplier);
}

CompletableFuture* CompletableFuture::supplyAsync($Supplier* supplier, $Executor* executor) {
	$init(CompletableFuture);
	return asyncSupplyStage($(screenExecutor(executor)), supplier);
}

CompletableFuture* CompletableFuture::runAsync($Runnable* runnable) {
	$init(CompletableFuture);
	return asyncRunStage(CompletableFuture::ASYNC_POOL, runnable);
}

CompletableFuture* CompletableFuture::runAsync($Runnable* runnable, $Executor* executor) {
	$init(CompletableFuture);
	return asyncRunStage($(screenExecutor(executor)), runnable);
}

CompletableFuture* CompletableFuture::completedFuture(Object$* value) {
	$init(CompletableFuture);
	return $new(CompletableFuture, (value == nullptr) ? $of(CompletableFuture::NIL) : $of(value));
}

bool CompletableFuture::isDone() {
	return this->result != nullptr;
}

$Object* CompletableFuture::get() {
	$var($Object, r, nullptr);
	if (($assign(r, this->result)) == nullptr) {
		$assign(r, waitingGet(true));
	}
	return $of(reportGet(r));
}

$Object* CompletableFuture::get(int64_t timeout, $TimeUnit* unit) {
	int64_t nanos = $nc(unit)->toNanos(timeout);
	$var($Object, r, nullptr);
	if (($assign(r, this->result)) == nullptr) {
		$assign(r, timedGet(nanos));
	}
	return $of(reportGet(r));
}

$Object* CompletableFuture::join() {
	$var($Object, r, nullptr);
	if (($assign(r, this->result)) == nullptr) {
		$assign(r, waitingGet(false));
	}
	return $of(reportJoin(r));
}

$Object* CompletableFuture::getNow(Object$* valueIfAbsent) {
	$var($Object, r, nullptr);
	return $of((($assign(r, this->result)) == nullptr) ? $of(valueIfAbsent) : reportJoin(r));
}

bool CompletableFuture::complete(Object$* value) {
	bool triggered = completeValue(value);
	postComplete();
	return triggered;
}

bool CompletableFuture::completeExceptionally($Throwable* ex) {
	if (ex == nullptr) {
		$throwNew($NullPointerException);
	}
	bool triggered = internalComplete($$new($CompletableFuture$AltResult, ex));
	postComplete();
	return triggered;
}

$CompletionStage* CompletableFuture::thenApply($Function* fn) {
	return uniApplyStage(nullptr, fn);
}

$CompletionStage* CompletableFuture::thenApplyAsync($Function* fn) {
	return uniApplyStage($(defaultExecutor()), fn);
}

$CompletionStage* CompletableFuture::thenApplyAsync($Function* fn, $Executor* executor) {
	return uniApplyStage($(screenExecutor(executor)), fn);
}

$CompletionStage* CompletableFuture::thenAccept($Consumer* action) {
	return uniAcceptStage(nullptr, action);
}

$CompletionStage* CompletableFuture::thenAcceptAsync($Consumer* action) {
	return uniAcceptStage($(defaultExecutor()), action);
}

$CompletionStage* CompletableFuture::thenAcceptAsync($Consumer* action, $Executor* executor) {
	return uniAcceptStage($(screenExecutor(executor)), action);
}

$CompletionStage* CompletableFuture::thenRun($Runnable* action) {
	return uniRunStage(nullptr, action);
}

$CompletionStage* CompletableFuture::thenRunAsync($Runnable* action) {
	return uniRunStage($(defaultExecutor()), action);
}

$CompletionStage* CompletableFuture::thenRunAsync($Runnable* action, $Executor* executor) {
	return uniRunStage($(screenExecutor(executor)), action);
}

$CompletionStage* CompletableFuture::thenCombine($CompletionStage* other, $BiFunction* fn) {
	return biApplyStage(nullptr, other, fn);
}

$CompletionStage* CompletableFuture::thenCombineAsync($CompletionStage* other, $BiFunction* fn) {
	return biApplyStage($(defaultExecutor()), other, fn);
}

$CompletionStage* CompletableFuture::thenCombineAsync($CompletionStage* other, $BiFunction* fn, $Executor* executor) {
	return biApplyStage($(screenExecutor(executor)), other, fn);
}

$CompletionStage* CompletableFuture::thenAcceptBoth($CompletionStage* other, $BiConsumer* action) {
	return biAcceptStage(nullptr, other, action);
}

$CompletionStage* CompletableFuture::thenAcceptBothAsync($CompletionStage* other, $BiConsumer* action) {
	return biAcceptStage($(defaultExecutor()), other, action);
}

$CompletionStage* CompletableFuture::thenAcceptBothAsync($CompletionStage* other, $BiConsumer* action, $Executor* executor) {
	return biAcceptStage($(screenExecutor(executor)), other, action);
}

$CompletionStage* CompletableFuture::runAfterBoth($CompletionStage* other, $Runnable* action) {
	return biRunStage(nullptr, other, action);
}

$CompletionStage* CompletableFuture::runAfterBothAsync($CompletionStage* other, $Runnable* action) {
	return biRunStage($(defaultExecutor()), other, action);
}

$CompletionStage* CompletableFuture::runAfterBothAsync($CompletionStage* other, $Runnable* action, $Executor* executor) {
	return biRunStage($(screenExecutor(executor)), other, action);
}

$CompletionStage* CompletableFuture::applyToEither($CompletionStage* other, $Function* fn) {
	return orApplyStage(nullptr, other, fn);
}

$CompletionStage* CompletableFuture::applyToEitherAsync($CompletionStage* other, $Function* fn) {
	return orApplyStage($(defaultExecutor()), other, fn);
}

$CompletionStage* CompletableFuture::applyToEitherAsync($CompletionStage* other, $Function* fn, $Executor* executor) {
	return orApplyStage($(screenExecutor(executor)), other, fn);
}

$CompletionStage* CompletableFuture::acceptEither($CompletionStage* other, $Consumer* action) {
	return orAcceptStage(nullptr, other, action);
}

$CompletionStage* CompletableFuture::acceptEitherAsync($CompletionStage* other, $Consumer* action) {
	return orAcceptStage($(defaultExecutor()), other, action);
}

$CompletionStage* CompletableFuture::acceptEitherAsync($CompletionStage* other, $Consumer* action, $Executor* executor) {
	return orAcceptStage($(screenExecutor(executor)), other, action);
}

$CompletionStage* CompletableFuture::runAfterEither($CompletionStage* other, $Runnable* action) {
	return orRunStage(nullptr, other, action);
}

$CompletionStage* CompletableFuture::runAfterEitherAsync($CompletionStage* other, $Runnable* action) {
	return orRunStage($(defaultExecutor()), other, action);
}

$CompletionStage* CompletableFuture::runAfterEitherAsync($CompletionStage* other, $Runnable* action, $Executor* executor) {
	return orRunStage($(screenExecutor(executor)), other, action);
}

$CompletionStage* CompletableFuture::thenCompose($Function* fn) {
	return uniComposeStage(nullptr, fn);
}

$CompletionStage* CompletableFuture::thenComposeAsync($Function* fn) {
	return uniComposeStage($(defaultExecutor()), fn);
}

$CompletionStage* CompletableFuture::thenComposeAsync($Function* fn, $Executor* executor) {
	return uniComposeStage($(screenExecutor(executor)), fn);
}

$CompletionStage* CompletableFuture::whenComplete($BiConsumer* action) {
	return uniWhenCompleteStage(nullptr, action);
}

$CompletionStage* CompletableFuture::whenCompleteAsync($BiConsumer* action) {
	return uniWhenCompleteStage($(defaultExecutor()), action);
}

$CompletionStage* CompletableFuture::whenCompleteAsync($BiConsumer* action, $Executor* executor) {
	return uniWhenCompleteStage($(screenExecutor(executor)), action);
}

$CompletionStage* CompletableFuture::handle($BiFunction* fn) {
	return uniHandleStage(nullptr, fn);
}

$CompletionStage* CompletableFuture::handleAsync($BiFunction* fn) {
	return uniHandleStage($(defaultExecutor()), fn);
}

$CompletionStage* CompletableFuture::handleAsync($BiFunction* fn, $Executor* executor) {
	return uniHandleStage($(screenExecutor(executor)), fn);
}

CompletableFuture* CompletableFuture::toCompletableFuture() {
	return this;
}

$CompletionStage* CompletableFuture::exceptionally($Function* fn) {
	return uniExceptionallyStage(nullptr, fn);
}

$CompletionStage* CompletableFuture::exceptionallyAsync($Function* fn) {
	return uniExceptionallyStage($(defaultExecutor()), fn);
}

$CompletionStage* CompletableFuture::exceptionallyAsync($Function* fn, $Executor* executor) {
	return uniExceptionallyStage($(screenExecutor(executor)), fn);
}

$CompletionStage* CompletableFuture::exceptionallyCompose($Function* fn) {
	return uniComposeExceptionallyStage(nullptr, fn);
}

$CompletionStage* CompletableFuture::exceptionallyComposeAsync($Function* fn) {
	return uniComposeExceptionallyStage($(defaultExecutor()), fn);
}

$CompletionStage* CompletableFuture::exceptionallyComposeAsync($Function* fn, $Executor* executor) {
	return uniComposeExceptionallyStage($(screenExecutor(executor)), fn);
}

CompletableFuture* CompletableFuture::allOf($CompletableFutureArray* cfs) {
	$init(CompletableFuture);
	return andTree(cfs, 0, $nc(cfs)->length - 1);
}

CompletableFuture* CompletableFuture::anyOf($CompletableFutureArray* cfs$renamed) {
	$init(CompletableFuture);
	$useLocalCurrentObjectStackCache();
	$var($CompletableFutureArray, cfs, cfs$renamed);
	int32_t n = 0;
	$var($Object, r, nullptr);
	if ((n = $nc(cfs)->length) <= 1) {
		return (n == 0) ? $new(CompletableFuture) : uniCopyStage(cfs->get(0));
	}
	{
		$var($CompletableFutureArray, arr$, cfs);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var(CompletableFuture, cf, arr$->get(i$));
			if (($assign(r, $nc(cf)->result)) != nullptr) {
				return $new(CompletableFuture, $(encodeRelay(r)));
			}
		}
	}
	$assign(cfs, $cast($CompletableFutureArray, $nc(cfs)->clone()));
	$var(CompletableFuture, d, $new(CompletableFuture));
	{
		$var($CompletableFutureArray, arr$, cfs);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var(CompletableFuture, cf, arr$->get(i$));
			$nc(cf)->unipush($$new($CompletableFuture$AnyOf, d, cf, cfs));
		}
	}
	if (d->result != nullptr) {
		{
			int32_t i = 0;
			int32_t len = cfs->length;
			for (; i < len; ++i) {
				if ($nc(cfs->get(i))->result != nullptr) {
					for (++i; i < len; ++i) {
						if ($nc(cfs->get(i))->result == nullptr) {
							$nc(cfs->get(i))->cleanStack();
						}
					}
				}
			}
		}
	}
	return d;
}

bool CompletableFuture::cancel(bool mayInterruptIfRunning) {
	$useLocalCurrentObjectStackCache();
	bool cancelled = (this->result == nullptr) && internalComplete($$new($CompletableFuture$AltResult, $$new($CancellationException)));
	postComplete();
	return cancelled || isCancelled();
}

bool CompletableFuture::isCancelled() {
	$var($Object, r, nullptr);
	bool var$0 = ($instanceOf($CompletableFuture$AltResult, $assign(r, this->result)));
	return var$0 && ($instanceOf($CancellationException, $nc(($cast($CompletableFuture$AltResult, r)))->ex));
}

bool CompletableFuture::isCompletedExceptionally() {
	$var($Object, r, nullptr);
	bool var$0 = ($instanceOf($CompletableFuture$AltResult, $assign(r, this->result)));
	return var$0 && !$equals(r, CompletableFuture::NIL);
}

void CompletableFuture::obtrudeValue(Object$* value) {
	$set(this, result, (value == nullptr) ? $of(CompletableFuture::NIL) : $of(value));
	postComplete();
}

void CompletableFuture::obtrudeException($Throwable* ex) {
	if (ex == nullptr) {
		$throwNew($NullPointerException);
	}
	$set(this, result, $new($CompletableFuture$AltResult, ex));
	postComplete();
}

int32_t CompletableFuture::getNumberOfDependents() {
	int32_t count = 0;
	{
		$var($CompletableFuture$Completion, p, this->stack);
		for (; p != nullptr; $assign(p, $nc(p)->next)) {
			++count;
		}
	}
	return count;
}

$String* CompletableFuture::toString() {
	$useLocalCurrentObjectStackCache();
	$var($Object, r, this->result);
	int32_t count = 0;
	{
		$var($CompletableFuture$Completion, p, this->stack);
		for (; p != nullptr; $assign(p, $nc(p)->next)) {
			++count;
		}
	}
	$var($String, var$0, $($Future::toString()));
	return $concat(var$0, ((r == nullptr) ? ((count == 0) ? "[Not completed]"_s : $$str({"[Not completed, "_s, $$str(count), " dependents]"_s})) : ((($instanceOf($CompletableFuture$AltResult, r)) && $nc(($cast($CompletableFuture$AltResult, r)))->ex != nullptr) ? $$str({"[Completed exceptionally: "_s, $nc(($cast($CompletableFuture$AltResult, r)))->ex, "]"_s}) : "[Completed normally]"_s)));
}

CompletableFuture* CompletableFuture::newIncompleteFuture() {
	return $new(CompletableFuture);
}

$Executor* CompletableFuture::defaultExecutor() {
	return CompletableFuture::ASYNC_POOL;
}

CompletableFuture* CompletableFuture::copy() {
	return uniCopyStage(this);
}

$CompletionStage* CompletableFuture::minimalCompletionStage() {
	return uniAsMinimalStage();
}

CompletableFuture* CompletableFuture::completeAsync($Supplier* supplier, $Executor* executor) {
	if (supplier == nullptr || executor == nullptr) {
		$throwNew($NullPointerException);
	}
	$nc(executor)->execute($$new($CompletableFuture$AsyncSupply, this, supplier));
	return this;
}

CompletableFuture* CompletableFuture::completeAsync($Supplier* supplier) {
	return completeAsync(supplier, $(defaultExecutor()));
}

CompletableFuture* CompletableFuture::orTimeout(int64_t timeout, $TimeUnit* unit) {
	$useLocalCurrentObjectStackCache();
	if (unit == nullptr) {
		$throwNew($NullPointerException);
	}
	if (this->result == nullptr) {
		whenComplete($$new($CompletableFuture$Canceller, $($CompletableFuture$Delayer::delay($$new($CompletableFuture$Timeout, this), timeout, unit))));
	}
	return this;
}

CompletableFuture* CompletableFuture::completeOnTimeout(Object$* value, int64_t timeout, $TimeUnit* unit) {
	$useLocalCurrentObjectStackCache();
	if (unit == nullptr) {
		$throwNew($NullPointerException);
	}
	if (this->result == nullptr) {
		whenComplete($$new($CompletableFuture$Canceller, $($CompletableFuture$Delayer::delay($$new($CompletableFuture$DelayedCompleter, this, value), timeout, unit))));
	}
	return this;
}

$Executor* CompletableFuture::delayedExecutor(int64_t delay, $TimeUnit* unit, $Executor* executor) {
	$init(CompletableFuture);
	if (unit == nullptr || executor == nullptr) {
		$throwNew($NullPointerException);
	}
	return $new($CompletableFuture$DelayedExecutor, delay, unit, executor);
}

$Executor* CompletableFuture::delayedExecutor(int64_t delay, $TimeUnit* unit) {
	$init(CompletableFuture);
	if (unit == nullptr) {
		$throwNew($NullPointerException);
	}
	return $new($CompletableFuture$DelayedExecutor, delay, unit, CompletableFuture::ASYNC_POOL);
}

$CompletionStage* CompletableFuture::completedStage(Object$* value) {
	$init(CompletableFuture);
	return $new($CompletableFuture$MinimalStage, (value == nullptr) ? $of(CompletableFuture::NIL) : $of(value));
}

CompletableFuture* CompletableFuture::failedFuture($Throwable* ex) {
	$init(CompletableFuture);
	if (ex == nullptr) {
		$throwNew($NullPointerException);
	}
	return $new(CompletableFuture, $$new($CompletableFuture$AltResult, ex));
}

$CompletionStage* CompletableFuture::failedStage($Throwable* ex) {
	$init(CompletableFuture);
	if (ex == nullptr) {
		$throwNew($NullPointerException);
	}
	return $new($CompletableFuture$MinimalStage, $$new($CompletableFuture$AltResult, ex));
}

void clinit$CompletableFuture($Class* class$) {
	$beforeCallerSensitive();
	$assignStatic(CompletableFuture::NIL, $new($CompletableFuture$AltResult, nullptr));
	CompletableFuture::USE_COMMON_POOL = ($ForkJoinPool::getCommonPoolParallelism() > 1);
	$assignStatic(CompletableFuture::ASYNC_POOL, CompletableFuture::USE_COMMON_POOL ? static_cast<$Executor*>($ForkJoinPool::commonPool()) : static_cast<$Executor*>($new($CompletableFuture$ThreadPerTaskExecutor)));
	{
		try {
			$var($MethodHandles$Lookup, l, $MethodHandles::lookup());
			$assignStatic(CompletableFuture::RESULT, $nc(l)->findVarHandle(CompletableFuture::class$, "result"_s, $Object::class$));
			$load($CompletableFuture$Completion);
			$assignStatic(CompletableFuture::STACK, l->findVarHandle(CompletableFuture::class$, "stack"_s, $CompletableFuture$Completion::class$));
			$assignStatic(CompletableFuture::NEXT, l->findVarHandle($CompletableFuture$Completion::class$, "next"_s, $CompletableFuture$Completion::class$));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(e));
		}
		$load($LockSupport);
		$Class* ensureLoaded = $LockSupport::class$;
	}
}

CompletableFuture::CompletableFuture() {
}

$Class* CompletableFuture::load$($String* name, bool initialize) {
	$loadClass(CompletableFuture, name, initialize, &_CompletableFuture_ClassInfo_, clinit$CompletableFuture, allocate$CompletableFuture);
	return class$;
}

$Class* CompletableFuture::class$ = nullptr;

		} // concurrent
	} // util
} // java