#include <sun/nio/ch/PipeImpl$Initializer.h>

#include <java/io/IOException.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/Runnable.h>
#include <java/nio/channels/ClosedByInterruptException.h>
#include <java/nio/channels/spi/SelectorProvider.h>
#include <sun/nio/ch/PipeImpl$Initializer$1.h>
#include <sun/nio/ch/PipeImpl$Initializer$LoopbackConnector.h>
#include <sun/nio/ch/PipeImpl.h>
#include <sun/nio/ch/SinkChannelImpl.h>
#include <sun/nio/ch/SourceChannelImpl.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $ClosedByInterruptException = ::java::nio::channels::ClosedByInterruptException;
using $SelectorProvider = ::java::nio::channels::spi::SelectorProvider;
using $PipeImpl$Initializer$1 = ::sun::nio::ch::PipeImpl$Initializer$1;
using $PipeImpl$Initializer$LoopbackConnector = ::sun::nio::ch::PipeImpl$Initializer$LoopbackConnector;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _PipeImpl$Initializer_FieldInfo_[] = {
	{"sp", "Ljava/nio/channels/spi/SelectorProvider;", nullptr, $PRIVATE | $FINAL, $field(PipeImpl$Initializer, sp)},
	{"ioe", "Ljava/io/IOException;", nullptr, $PRIVATE, $field(PipeImpl$Initializer, ioe)},
	{"source", "Lsun/nio/ch/SourceChannelImpl;", nullptr, 0, $field(PipeImpl$Initializer, source)},
	{"sink", "Lsun/nio/ch/SinkChannelImpl;", nullptr, 0, $field(PipeImpl$Initializer, sink)},
	{}
};

$MethodInfo _PipeImpl$Initializer_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/channels/spi/SelectorProvider;)V", nullptr, $PRIVATE, $method(PipeImpl$Initializer, init$, void, $SelectorProvider*)},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC, $virtualMethod(PipeImpl$Initializer, run, $Object*), "java.io.IOException"},
	{}
};

$InnerClassInfo _PipeImpl$Initializer_InnerClassesInfo_[] = {
	{"sun.nio.ch.PipeImpl$Initializer", "sun.nio.ch.PipeImpl", "Initializer", $PRIVATE | $STATIC},
	{"sun.nio.ch.PipeImpl$Initializer$LoopbackConnector", "sun.nio.ch.PipeImpl$Initializer", "LoopbackConnector", $PRIVATE},
	{"sun.nio.ch.PipeImpl$Initializer$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _PipeImpl$Initializer_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.PipeImpl$Initializer",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	_PipeImpl$Initializer_FieldInfo_,
	_PipeImpl$Initializer_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedExceptionAction<Ljava/lang/Void;>;",
	nullptr,
	_PipeImpl$Initializer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.ch.PipeImpl"
};

$Object* allocate$PipeImpl$Initializer($Class* clazz) {
	return $of($alloc(PipeImpl$Initializer));
}

void PipeImpl$Initializer::init$($SelectorProvider* sp) {
	$set(this, sp, sp);
}

$Object* PipeImpl$Initializer::run() {
	$useLocalCurrentObjectStackCache();
	$var($PipeImpl$Initializer$LoopbackConnector, connector, $new($PipeImpl$Initializer$LoopbackConnector, this));
	connector->run();
	if ($instanceOf($ClosedByInterruptException, this->ioe)) {
		$set(this, ioe, nullptr);
		$var($Thread, connThread, $new($PipeImpl$Initializer$1, this, connector));
		connThread->start();
		for (;;) {
			try {
				connThread->join();
				break;
			} catch ($InterruptedException& ex) {
			}
		}
		$($Thread::currentThread())->interrupt();
	}
	if (this->ioe != nullptr) {
		$throwNew($IOException, "Unable to establish loopback connection"_s, this->ioe);
	}
	return $of(nullptr);
}

PipeImpl$Initializer::PipeImpl$Initializer() {
}

$Class* PipeImpl$Initializer::load$($String* name, bool initialize) {
	$loadClass(PipeImpl$Initializer, name, initialize, &_PipeImpl$Initializer_ClassInfo_, allocate$PipeImpl$Initializer);
	return class$;
}

$Class* PipeImpl$Initializer::class$ = nullptr;

		} // ch
	} // nio
} // sun