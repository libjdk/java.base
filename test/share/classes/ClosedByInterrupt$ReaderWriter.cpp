#include <ClosedByInterrupt$ReaderWriter.h>

#include <ClosedByInterrupt.h>
#include <java/lang/InterruptedException.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/ClosedByInterruptException.h>
#include <java/nio/channels/ClosedChannelException.h>
#include <java/nio/channels/FileChannel.h>
#include <java/util/Random.h>
#include <jcpp.h>

using $ClosedByInterrupt = ::ClosedByInterrupt;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $ClosedByInterruptException = ::java::nio::channels::ClosedByInterruptException;
using $ClosedChannelException = ::java::nio::channels::ClosedChannelException;
using $FileChannel = ::java::nio::channels::FileChannel;
using $Random = ::java::util::Random;

$FieldInfo _ClosedByInterrupt$ReaderWriter_FieldInfo_[] = {
	{"fc", "Ljava/nio/channels/FileChannel;", nullptr, $FINAL, $field(ClosedByInterrupt$ReaderWriter, fc)},
	{"interruptible", "Z", nullptr, $FINAL, $field(ClosedByInterrupt$ReaderWriter, interruptible)},
	{"writer", "Z", nullptr, $FINAL, $field(ClosedByInterrupt$ReaderWriter, writer)},
	{}
};

$MethodInfo _ClosedByInterrupt$ReaderWriter_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/channels/FileChannel;Z)V", nullptr, 0, $method(ClosedByInterrupt$ReaderWriter, init$, void, $FileChannel*, bool)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(ClosedByInterrupt$ReaderWriter, run, void)},
	{}
};

$InnerClassInfo _ClosedByInterrupt$ReaderWriter_InnerClassesInfo_[] = {
	{"ClosedByInterrupt$ReaderWriter", "ClosedByInterrupt", "ReaderWriter", $STATIC},
	{}
};

$ClassInfo _ClosedByInterrupt$ReaderWriter_ClassInfo_ = {
	$ACC_SUPER,
	"ClosedByInterrupt$ReaderWriter",
	"java.lang.Object",
	"java.lang.Runnable",
	_ClosedByInterrupt$ReaderWriter_FieldInfo_,
	_ClosedByInterrupt$ReaderWriter_MethodInfo_,
	nullptr,
	nullptr,
	_ClosedByInterrupt$ReaderWriter_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"ClosedByInterrupt"
};

$Object* allocate$ClosedByInterrupt$ReaderWriter($Class* clazz) {
	return $of($alloc(ClosedByInterrupt$ReaderWriter));
}

void ClosedByInterrupt$ReaderWriter::init$($FileChannel* fc, bool interruptible) {
	$set(this, fc, fc);
	this->interruptible = interruptible;
	$init($ClosedByInterrupt);
	this->writer = $nc($ClosedByInterrupt::rand)->nextBoolean();
}

void ClosedByInterrupt$ReaderWriter::run() {
	$useLocalCurrentObjectStackCache();
	$var($ByteBuffer, bb, $ByteBuffer::allocate(1024));
	if (this->writer) {
		$init($ClosedByInterrupt);
		$nc($ClosedByInterrupt::rand)->nextBytes($($cast($bytes, $nc(bb)->array())));
	}
	try {
		for (;;) {
			$init($ClosedByInterrupt);
			int64_t position = $nc($ClosedByInterrupt::rand)->nextInt(1024 * 1024 - $nc(bb)->capacity());
			if (this->writer) {
				$nc($($nc(bb)->position(0)))->limit(bb->capacity());
				$nc(this->fc)->write(bb, position);
			} else {
				$nc(bb)->clear();
				$nc(this->fc)->read(bb, position);
			}
			if (!this->interruptible) {
				try {
					$Thread::sleep($nc($ClosedByInterrupt::rand)->nextInt(50));
				} catch ($InterruptedException& e) {
					$ClosedByInterrupt::unexpected(static_cast<$Exception*>(e));
				}
			}
		}
	} catch ($ClosedByInterruptException& e) {
		if (this->interruptible) {
			if ($Thread::interrupted()) {
				$ClosedByInterrupt::expected($$str({e, " thrown and interrupt status set"_s}));
			} else {
				$ClosedByInterrupt::unexpected($$str({e, " thrown but interrupt status not set"_s}));
			}
		} else {
			$ClosedByInterrupt::unexpected(static_cast<$Exception*>(e));
		}
	} catch ($ClosedChannelException& e) {
		if (this->interruptible) {
			$ClosedByInterrupt::unexpected(static_cast<$Exception*>(e));
		} else {
			$ClosedByInterrupt::expected(static_cast<$Exception*>(e));
		}
	} catch ($Exception& e) {
		$ClosedByInterrupt::unexpected($cast($Exception, e));
	}
}

ClosedByInterrupt$ReaderWriter::ClosedByInterrupt$ReaderWriter() {
}

$Class* ClosedByInterrupt$ReaderWriter::load$($String* name, bool initialize) {
	$loadClass(ClosedByInterrupt$ReaderWriter, name, initialize, &_ClosedByInterrupt$ReaderWriter_ClassInfo_, allocate$ClosedByInterrupt$ReaderWriter);
	return class$;
}

$Class* ClosedByInterrupt$ReaderWriter::class$ = nullptr;