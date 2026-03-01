#include <StressLoopback$Source.h>

#include <StressLoopback$Source$1.h>
#include <StressLoopback.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/AsynchronousByteChannel.h>
#include <java/nio/channels/Channel.h>
#include <java/nio/channels/CompletionHandler.h>
#include <java/util/Random.h>
#include <jcpp.h>

using $StressLoopback = ::StressLoopback;
using $StressLoopback$Source$1 = ::StressLoopback$Source$1;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AsynchronousByteChannel = ::java::nio::channels::AsynchronousByteChannel;
using $Channel = ::java::nio::channels::Channel;
using $CompletionHandler = ::java::nio::channels::CompletionHandler;
using $Random = ::java::util::Random;

$FieldInfo _StressLoopback$Source_FieldInfo_[] = {
	{"channel", "Ljava/nio/channels/AsynchronousByteChannel;", nullptr, $PRIVATE | $FINAL, $field(StressLoopback$Source, channel)},
	{"sentBuffer", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $FINAL, $field(StressLoopback$Source, sentBuffer)},
	{"bytesSent", "J", nullptr, $PRIVATE | $VOLATILE, $field(StressLoopback$Source, bytesSent)},
	{"finished", "Z", nullptr, $PRIVATE | $VOLATILE, $field(StressLoopback$Source, finished)},
	{}
};

$MethodInfo _StressLoopback$Source_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/channels/AsynchronousByteChannel;)V", nullptr, 0, $method(StressLoopback$Source, init$, void, $AsynchronousByteChannel*)},
	{"finish", "()J", nullptr, 0, $virtualMethod(StressLoopback$Source, finish, int64_t)},
	{"start", "()V", nullptr, 0, $virtualMethod(StressLoopback$Source, start, void)},
	{}
};

$InnerClassInfo _StressLoopback$Source_InnerClassesInfo_[] = {
	{"StressLoopback$Source", "StressLoopback", "Source", $STATIC},
	{"StressLoopback$Source$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _StressLoopback$Source_ClassInfo_ = {
	$ACC_SUPER,
	"StressLoopback$Source",
	"java.lang.Object",
	nullptr,
	_StressLoopback$Source_FieldInfo_,
	_StressLoopback$Source_MethodInfo_,
	nullptr,
	nullptr,
	_StressLoopback$Source_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"StressLoopback"
};

$Object* allocate$StressLoopback$Source($Class* clazz) {
	return $of($alloc(StressLoopback$Source));
}

void StressLoopback$Source::init$($AsynchronousByteChannel* channel) {
	$set(this, channel, channel);
	$init($StressLoopback);
	int32_t size = 1024 + $nc($StressLoopback::rand)->nextInt(10000);
	$set(this, sentBuffer, ($nc($StressLoopback::rand)->nextBoolean()) ? $ByteBuffer::allocateDirect(size) : $ByteBuffer::allocate(size));
}

void StressLoopback$Source::start() {
	$nc(this->sentBuffer)->position(0);
	$nc(this->sentBuffer)->limit($nc(this->sentBuffer)->capacity());
	$nc(this->channel)->write(this->sentBuffer, ($Void*)nullptr, $$new($StressLoopback$Source$1, this));
}

int64_t StressLoopback$Source::finish() {
	this->finished = true;
	$StressLoopback::waitUntilClosed(this->channel);
	return this->bytesSent;
}

StressLoopback$Source::StressLoopback$Source() {
}

$Class* StressLoopback$Source::load$($String* name, bool initialize) {
	$loadClass(StressLoopback$Source, name, initialize, &_StressLoopback$Source_ClassInfo_, allocate$StressLoopback$Source);
	return class$;
}

$Class* StressLoopback$Source::class$ = nullptr;