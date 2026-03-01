#include <sun/nio/ch/PendingIoCache$1.h>

#include <java/io/IOException.h>
#include <java/nio/channels/AsynchronousCloseException.h>
#include <sun/nio/ch/Iocp$ResultHandler.h>
#include <sun/nio/ch/PendingIoCache.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AsynchronousCloseException = ::java::nio::channels::AsynchronousCloseException;
using $Iocp$ResultHandler = ::sun::nio::ch::Iocp$ResultHandler;
using $PendingIoCache = ::sun::nio::ch::PendingIoCache;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _PendingIoCache$1_FieldInfo_[] = {
	{"this$0", "Lsun/nio/ch/PendingIoCache;", nullptr, $FINAL | $SYNTHETIC, $field(PendingIoCache$1, this$0)},
	{"val$rh", "Lsun/nio/ch/Iocp$ResultHandler;", nullptr, $FINAL | $SYNTHETIC, $field(PendingIoCache$1, val$rh)},
	{}
};

$MethodInfo _PendingIoCache$1_MethodInfo_[] = {
	{"<init>", "(Lsun/nio/ch/PendingIoCache;Lsun/nio/ch/Iocp$ResultHandler;)V", "()V", 0, $method(PendingIoCache$1, init$, void, $PendingIoCache*, $Iocp$ResultHandler*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(PendingIoCache$1, run, void)},
	{}
};

$EnclosingMethodInfo _PendingIoCache$1_EnclosingMethodInfo_ = {
	"sun.nio.ch.PendingIoCache",
	"clearPendingIoMap",
	"()V"
};

$InnerClassInfo _PendingIoCache$1_InnerClassesInfo_[] = {
	{"sun.nio.ch.PendingIoCache$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _PendingIoCache$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.PendingIoCache$1",
	"java.lang.Object",
	"java.lang.Runnable",
	_PendingIoCache$1_FieldInfo_,
	_PendingIoCache$1_MethodInfo_,
	nullptr,
	&_PendingIoCache$1_EnclosingMethodInfo_,
	_PendingIoCache$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.ch.PendingIoCache"
};

$Object* allocate$PendingIoCache$1($Class* clazz) {
	return $of($alloc(PendingIoCache$1));
}

void PendingIoCache$1::init$($PendingIoCache* this$0, $Iocp$ResultHandler* val$rh) {
	$set(this, this$0, this$0);
	$set(this, val$rh, val$rh);
}

void PendingIoCache$1::run() {
	$nc(this->val$rh)->failed(-1, $$new($AsynchronousCloseException));
}

PendingIoCache$1::PendingIoCache$1() {
}

$Class* PendingIoCache$1::load$($String* name, bool initialize) {
	$loadClass(PendingIoCache$1, name, initialize, &_PendingIoCache$1_ClassInfo_, allocate$PendingIoCache$1);
	return class$;
}

$Class* PendingIoCache$1::class$ = nullptr;

		} // ch
	} // nio
} // sun