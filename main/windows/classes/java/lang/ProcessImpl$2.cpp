#include <java/lang/ProcessImpl$2.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/BufferedOutputStream.h>
#include <java/io/FileDescriptor.h>
#include <java/io/FileOutputStream.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/Process$PipeInputStream.h>
#include <java/lang/ProcessBuilder$NullInputStream.h>
#include <java/lang/ProcessBuilder$NullOutputStream.h>
#include <java/lang/ProcessImpl.h>
#include <jdk/internal/access/JavaIOFileDescriptorAccess.h>
#include <jcpp.h>

#undef INSTANCE

using $BufferedInputStream = ::java::io::BufferedInputStream;
using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $FileDescriptor = ::java::io::FileDescriptor;
using $FileOutputStream = ::java::io::FileOutputStream;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Process$PipeInputStream = ::java::lang::Process$PipeInputStream;
using $ProcessBuilder$NullInputStream = ::java::lang::ProcessBuilder$NullInputStream;
using $ProcessBuilder$NullOutputStream = ::java::lang::ProcessBuilder$NullOutputStream;
using $ProcessImpl = ::java::lang::ProcessImpl;
using $JavaIOFileDescriptorAccess = ::jdk::internal::access::JavaIOFileDescriptorAccess;

namespace java {
	namespace lang {

$FieldInfo _ProcessImpl$2_FieldInfo_[] = {
	{"this$0", "Ljava/lang/ProcessImpl;", nullptr, $FINAL | $SYNTHETIC, $field(ProcessImpl$2, this$0)},
	{"val$forceNullOutputStream", "Z", nullptr, $FINAL | $SYNTHETIC, $field(ProcessImpl$2, val$forceNullOutputStream)},
	{"val$stdHandles", "[J", nullptr, $FINAL | $SYNTHETIC, $field(ProcessImpl$2, val$stdHandles)},
	{}
};

$MethodInfo _ProcessImpl$2_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/ProcessImpl;[JZ)V", "()V", 0, $method(ProcessImpl$2, init$, void, $ProcessImpl*, $longs*, bool)},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC, $virtualMethod(ProcessImpl$2, run, $Object*)},
	{}
};

$EnclosingMethodInfo _ProcessImpl$2_EnclosingMethodInfo_ = {
	"java.lang.ProcessImpl",
	"<init>",
	"([Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[JZZ)V"
};

$InnerClassInfo _ProcessImpl$2_InnerClassesInfo_[] = {
	{"java.lang.ProcessImpl$2", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ProcessImpl$2_ClassInfo_ = {
	$ACC_SUPER,
	"java.lang.ProcessImpl$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_ProcessImpl$2_FieldInfo_,
	_ProcessImpl$2_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Void;>;",
	&_ProcessImpl$2_EnclosingMethodInfo_,
	_ProcessImpl$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.ProcessImpl"
};

$Object* allocate$ProcessImpl$2($Class* clazz) {
	return $of($alloc(ProcessImpl$2));
}

void ProcessImpl$2::init$($ProcessImpl* this$0, $longs* val$stdHandles, bool val$forceNullOutputStream) {
	$set(this, this$0, this$0);
	$set(this, val$stdHandles, val$stdHandles);
	this->val$forceNullOutputStream = val$forceNullOutputStream;
}

$Object* ProcessImpl$2::run() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->val$stdHandles)->get(0) == (int64_t)-1) {
		$init($ProcessBuilder$NullOutputStream);
		$set(this->this$0, stdin_stream, $ProcessBuilder$NullOutputStream::INSTANCE);
	} else {
		$var($FileDescriptor, stdin_fd, $new($FileDescriptor));
		$init($ProcessImpl);
		$nc($ProcessImpl::fdAccess)->setHandle(stdin_fd, $nc(this->val$stdHandles)->get(0));
		$nc($ProcessImpl::fdAccess)->registerCleanup(stdin_fd);
		$set(this->this$0, stdin_stream, $new($BufferedOutputStream, $$new($FileOutputStream, stdin_fd)));
	}
	if ($nc(this->val$stdHandles)->get(1) == (int64_t)-1 || this->val$forceNullOutputStream) {
		$init($ProcessBuilder$NullInputStream);
		$set(this->this$0, stdout_stream, $ProcessBuilder$NullInputStream::INSTANCE);
	} else {
		$var($FileDescriptor, stdout_fd, $new($FileDescriptor));
		$init($ProcessImpl);
		$nc($ProcessImpl::fdAccess)->setHandle(stdout_fd, $nc(this->val$stdHandles)->get(1));
		$nc($ProcessImpl::fdAccess)->registerCleanup(stdout_fd);
		$set(this->this$0, stdout_stream, $new($BufferedInputStream, $$new($Process$PipeInputStream, stdout_fd)));
	}
	if ($nc(this->val$stdHandles)->get(2) == (int64_t)-1) {
		$init($ProcessBuilder$NullInputStream);
		$set(this->this$0, stderr_stream, $ProcessBuilder$NullInputStream::INSTANCE);
	} else {
		$var($FileDescriptor, stderr_fd, $new($FileDescriptor));
		$init($ProcessImpl);
		$nc($ProcessImpl::fdAccess)->setHandle(stderr_fd, $nc(this->val$stdHandles)->get(2));
		$nc($ProcessImpl::fdAccess)->registerCleanup(stderr_fd);
		$set(this->this$0, stderr_stream, $new($Process$PipeInputStream, stderr_fd));
	}
	return $of(nullptr);
}

ProcessImpl$2::ProcessImpl$2() {
}

$Class* ProcessImpl$2::load$($String* name, bool initialize) {
	$loadClass(ProcessImpl$2, name, initialize, &_ProcessImpl$2_ClassInfo_, allocate$ProcessImpl$2);
	return class$;
}

$Class* ProcessImpl$2::class$ = nullptr;

	} // lang
} // java