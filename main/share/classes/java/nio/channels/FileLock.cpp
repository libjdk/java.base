#include <java/nio/channels/FileLock.h>

#include <java/nio/channels/AsynchronousFileChannel.h>
#include <java/nio/channels/Channel.h>
#include <java/nio/channels/FileChannel.h>
#include <java/nio/channels/InterruptibleChannel.h>
#include <java/nio/channels/spi/AbstractInterruptibleChannel.h>
#include <java/util/Objects.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $AsynchronousFileChannel = ::java::nio::channels::AsynchronousFileChannel;
using $Channel = ::java::nio::channels::Channel;
using $FileChannel = ::java::nio::channels::FileChannel;
using $InterruptibleChannel = ::java::nio::channels::InterruptibleChannel;
using $AbstractInterruptibleChannel = ::java::nio::channels::spi::AbstractInterruptibleChannel;
using $Objects = ::java::util::Objects;

namespace java {
	namespace nio {
		namespace channels {

$FieldInfo _FileLock_FieldInfo_[] = {
	{"channel", "Ljava/nio/channels/Channel;", nullptr, $PRIVATE | $FINAL, $field(FileLock, channel$)},
	{"position", "J", nullptr, $PRIVATE | $FINAL, $field(FileLock, position$)},
	{"size", "J", nullptr, $PRIVATE | $FINAL, $field(FileLock, size$)},
	{"shared", "Z", nullptr, $PRIVATE | $FINAL, $field(FileLock, shared)},
	{}
};

$MethodInfo _FileLock_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/channels/FileChannel;JJZ)V", nullptr, $PROTECTED, $method(FileLock, init$, void, $FileChannel*, int64_t, int64_t, bool)},
	{"<init>", "(Ljava/nio/channels/AsynchronousFileChannel;JJZ)V", nullptr, $PROTECTED, $method(FileLock, init$, void, $AsynchronousFileChannel*, int64_t, int64_t, bool)},
	{"acquiredBy", "()Ljava/nio/channels/Channel;", nullptr, $PUBLIC, $virtualMethod(FileLock, acquiredBy, $Channel*)},
	{"channel", "()Ljava/nio/channels/FileChannel;", nullptr, $PUBLIC | $FINAL, $method(FileLock, channel, $FileChannel*)},
	{"close", "()V", nullptr, $PUBLIC | $FINAL, $virtualMethod(FileLock, close, void), "java.io.IOException"},
	{"isShared", "()Z", nullptr, $PUBLIC | $FINAL, $method(FileLock, isShared, bool)},
	{"isValid", "()Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(FileLock, isValid, bool)},
	{"overlaps", "(JJ)Z", nullptr, $PUBLIC | $FINAL, $method(FileLock, overlaps, bool, int64_t, int64_t)},
	{"position", "()J", nullptr, $PUBLIC | $FINAL, $method(FileLock, position, int64_t)},
	{"release", "()V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(FileLock, release, void), "java.io.IOException"},
	{"size", "()J", nullptr, $PUBLIC | $FINAL, $method(FileLock, size, int64_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $virtualMethod(FileLock, toString, $String*)},
	{}
};

$ClassInfo _FileLock_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.nio.channels.FileLock",
	"java.lang.Object",
	"java.lang.AutoCloseable",
	_FileLock_FieldInfo_,
	_FileLock_MethodInfo_
};

$Object* allocate$FileLock($Class* clazz) {
	return $of($alloc(FileLock));
}

void FileLock::init$($FileChannel* channel, int64_t position, int64_t size, bool shared) {
	$Objects::requireNonNull($of(channel), "Null channel"_s);
	if (position < 0) {
		$throwNew($IllegalArgumentException, "Negative position"_s);
	}
	if (size < 0) {
		$throwNew($IllegalArgumentException, "Negative size"_s);
	}
	if (position + size < 0) {
		$throwNew($IllegalArgumentException, "Negative position + size"_s);
	}
	$set(this, channel$, static_cast<$Channel*>(static_cast<$InterruptibleChannel*>(static_cast<$AbstractInterruptibleChannel*>(channel))));
	this->position$ = position;
	this->size$ = size;
	this->shared = shared;
}

void FileLock::init$($AsynchronousFileChannel* channel, int64_t position, int64_t size, bool shared) {
	$Objects::requireNonNull($of(channel), "Null channel"_s);
	if (position < 0) {
		$throwNew($IllegalArgumentException, "Negative position"_s);
	}
	if (size < 0) {
		$throwNew($IllegalArgumentException, "Negative size"_s);
	}
	if (position + size < 0) {
		$throwNew($IllegalArgumentException, "Negative position + size"_s);
	}
	$set(this, channel$, channel);
	this->position$ = position;
	this->size$ = size;
	this->shared = shared;
}

$FileChannel* FileLock::channel() {
	return ($instanceOf($FileChannel, this->channel$)) ? $cast($FileChannel, this->channel$) : ($FileChannel*)nullptr;
}

$Channel* FileLock::acquiredBy() {
	return this->channel$;
}

int64_t FileLock::position() {
	return this->position$;
}

int64_t FileLock::size() {
	return this->size$;
}

bool FileLock::isShared() {
	return this->shared;
}

bool FileLock::overlaps(int64_t position, int64_t size) {
	if (position + size <= this->position$) {
		return false;
	}
	if (this->position$ + this->size$ <= position) {
		return false;
	}
	return true;
}

void FileLock::close() {
	release();
}

$String* FileLock::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$1, $$str({$($of(this)->getClass()->getName()), "["_s, $$str(this->position$), ":"_s, $$str(this->size$), " "_s, (this->shared ? "shared"_s : "exclusive"_s), " "_s}));
	$var($String, var$0, $$concat(var$1, (isValid() ? "valid"_s : "invalid"_s)));
	return ($concat(var$0, "]"_s));
}

FileLock::FileLock() {
}

$Class* FileLock::load$($String* name, bool initialize) {
	$loadClass(FileLock, name, initialize, &_FileLock_ClassInfo_, allocate$FileLock);
	return class$;
}

$Class* FileLock::class$ = nullptr;

		} // channels
	} // nio
} // java