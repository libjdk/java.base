#include <StressLoopback$Source$1.h>

#include <StressLoopback$Source.h>
#include <StressLoopback.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/AsynchronousByteChannel.h>
#include <java/nio/channels/Channel.h>
#include <java/nio/channels/CompletionHandler.h>
#include <jcpp.h>

using $StressLoopback = ::StressLoopback;
using $StressLoopback$Source = ::StressLoopback$Source;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AsynchronousByteChannel = ::java::nio::channels::AsynchronousByteChannel;
using $Channel = ::java::nio::channels::Channel;
using $CompletionHandler = ::java::nio::channels::CompletionHandler;

$FieldInfo _StressLoopback$Source$1_FieldInfo_[] = {
	{"this$0", "LStressLoopback$Source;", nullptr, $FINAL | $SYNTHETIC, $field(StressLoopback$Source$1, this$0)},
	{}
};

$MethodInfo _StressLoopback$Source$1_MethodInfo_[] = {
	{"<init>", "(LStressLoopback$Source;)V", nullptr, 0, $method(StressLoopback$Source$1, init$, void, $StressLoopback$Source*)},
	{"completed", "(Ljava/lang/Integer;Ljava/lang/Void;)V", nullptr, $PUBLIC, $virtualMethod(StressLoopback$Source$1, completed, void, $Integer*, $Void*)},
	{"completed", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(StressLoopback$Source$1, completed, void, Object$*, Object$*)},
	{"failed", "(Ljava/lang/Throwable;Ljava/lang/Void;)V", nullptr, $PUBLIC, $virtualMethod(StressLoopback$Source$1, failed, void, $Throwable*, $Void*)},
	{"failed", "(Ljava/lang/Throwable;Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(StressLoopback$Source$1, failed, void, $Throwable*, Object$*)},
	{}
};

$EnclosingMethodInfo _StressLoopback$Source$1_EnclosingMethodInfo_ = {
	"StressLoopback$Source",
	"start",
	"()V"
};

$InnerClassInfo _StressLoopback$Source$1_InnerClassesInfo_[] = {
	{"StressLoopback$Source", "StressLoopback", "Source", $STATIC},
	{"StressLoopback$Source$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _StressLoopback$Source$1_ClassInfo_ = {
	$ACC_SUPER,
	"StressLoopback$Source$1",
	"java.lang.Object",
	"java.nio.channels.CompletionHandler",
	_StressLoopback$Source$1_FieldInfo_,
	_StressLoopback$Source$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/nio/channels/CompletionHandler<Ljava/lang/Integer;Ljava/lang/Void;>;",
	&_StressLoopback$Source$1_EnclosingMethodInfo_,
	_StressLoopback$Source$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"StressLoopback"
};

$Object* allocate$StressLoopback$Source$1($Class* clazz) {
	return $of($alloc(StressLoopback$Source$1));
}

void StressLoopback$Source$1::init$($StressLoopback$Source* this$0) {
	$set(this, this$0, this$0);
}

void StressLoopback$Source$1::completed($Integer* nwrote, $Void* att) {
	this->this$0->bytesSent += $nc(nwrote)->intValue();
	if (this->this$0->finished) {
		$StressLoopback::closeUnchecked(this->this$0->channel);
	} else {
		$nc(this->this$0->sentBuffer)->position(0);
		$nc(this->this$0->sentBuffer)->limit($nc(this->this$0->sentBuffer)->capacity());
		$nc(this->this$0->channel)->write(this->this$0->sentBuffer, ($Void*)nullptr, this);
	}
}

void StressLoopback$Source$1::failed($Throwable* exc, $Void* att) {
	$nc(exc)->printStackTrace();
	$StressLoopback::closeUnchecked(this->this$0->channel);
}

void StressLoopback$Source$1::failed($Throwable* exc, Object$* att) {
	this->failed(exc, $cast($Void, att));
}

void StressLoopback$Source$1::completed(Object$* nwrote, Object$* att) {
	this->completed($cast($Integer, nwrote), $cast($Void, att));
}

StressLoopback$Source$1::StressLoopback$Source$1() {
}

$Class* StressLoopback$Source$1::load$($String* name, bool initialize) {
	$loadClass(StressLoopback$Source$1, name, initialize, &_StressLoopback$Source$1_ClassInfo_, allocate$StressLoopback$Source$1);
	return class$;
}

$Class* StressLoopback$Source$1::class$ = nullptr;