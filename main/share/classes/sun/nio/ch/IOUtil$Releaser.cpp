#include <sun/nio/ch/IOUtil$Releaser.h>

#include <java/io/Serializable.h>
#include <java/lang/Record.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/runtime/ObjectMethods.h>
#include <java/util/Objects.h>
#include <jdk/internal/misc/ScopedMemoryAccess$Scope$Handle.h>
#include <sun/nio/ch/IOUtil.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Record = ::java::lang::Record;
using $Runnable = ::java::lang::Runnable;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Objects = ::java::util::Objects;
using $ScopedMemoryAccess$Scope$Handle = ::jdk::internal::misc::ScopedMemoryAccess$Scope$Handle;
using $IOUtil = ::sun::nio::ch::IOUtil;

namespace sun {
	namespace nio {
		namespace ch {

class IOUtil$Releaser$$Lambda$lambda$ofNullable$0 : public $Runnable {
	$class(IOUtil$Releaser$$Lambda$lambda$ofNullable$0, $NO_CLASS_INIT, $Runnable)
public:
	void init$() {
	}
	virtual void run() override {
		IOUtil$Releaser::lambda$ofNullable$0();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<IOUtil$Releaser$$Lambda$lambda$ofNullable$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo IOUtil$Releaser$$Lambda$lambda$ofNullable$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(IOUtil$Releaser$$Lambda$lambda$ofNullable$0, init$, void)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(IOUtil$Releaser$$Lambda$lambda$ofNullable$0, run, void)},
	{}
};
$ClassInfo IOUtil$Releaser$$Lambda$lambda$ofNullable$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.nio.ch.IOUtil$Releaser$$Lambda$lambda$ofNullable$0",
	"java.lang.Object",
	"java.lang.Runnable",
	nullptr,
	methodInfos
};
$Class* IOUtil$Releaser$$Lambda$lambda$ofNullable$0::load$($String* name, bool initialize) {
	$loadClass(IOUtil$Releaser$$Lambda$lambda$ofNullable$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* IOUtil$Releaser$$Lambda$lambda$ofNullable$0::class$ = nullptr;

$FieldInfo _IOUtil$Releaser_FieldInfo_[] = {
	{"handle", "Ljdk/internal/misc/ScopedMemoryAccess$Scope$Handle;", nullptr, $PRIVATE | $FINAL, $field(IOUtil$Releaser, handle$)},
	{}
};

$MethodInfo _IOUtil$Releaser_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(Ljdk/internal/misc/ScopedMemoryAccess$Scope$Handle;)V", nullptr, 0, $method(IOUtil$Releaser, init$, void, $ScopedMemoryAccess$Scope$Handle*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(IOUtil$Releaser, equals, bool, Object$*)},
	{"handle", "()Ljdk/internal/misc/ScopedMemoryAccess$Scope$Handle;", nullptr, $PUBLIC, $method(IOUtil$Releaser, handle, $ScopedMemoryAccess$Scope$Handle*)},
	{"hashCode", "()I", nullptr, $PUBLIC | $FINAL, $virtualMethod(IOUtil$Releaser, hashCode, int32_t)},
	{"lambda$ofNullable$0", "()V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(IOUtil$Releaser, lambda$ofNullable$0, void)},
	{"of", "(Ljdk/internal/misc/ScopedMemoryAccess$Scope$Handle;)Ljava/lang/Runnable;", nullptr, $STATIC, $staticMethod(IOUtil$Releaser, of, $Runnable*, $ScopedMemoryAccess$Scope$Handle*)},
	{"ofNullable", "(Ljdk/internal/misc/ScopedMemoryAccess$Scope$Handle;)Ljava/lang/Runnable;", nullptr, $STATIC, $staticMethod(IOUtil$Releaser, ofNullable, $Runnable*, $ScopedMemoryAccess$Scope$Handle*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(IOUtil$Releaser, run, void)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $virtualMethod(IOUtil$Releaser, toString, $String*)},
	{}
};

$InnerClassInfo _IOUtil$Releaser_InnerClassesInfo_[] = {
	{"sun.nio.ch.IOUtil$Releaser", "sun.nio.ch.IOUtil", "Releaser", $STATIC | $FINAL},
	{}
};

$ClassInfo _IOUtil$Releaser_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.nio.ch.IOUtil$Releaser",
	"java.lang.Record",
	"java.lang.Runnable",
	_IOUtil$Releaser_FieldInfo_,
	_IOUtil$Releaser_MethodInfo_,
	nullptr,
	nullptr,
	_IOUtil$Releaser_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.ch.IOUtil"
};

$Object* allocate$IOUtil$Releaser($Class* clazz) {
	return $of($alloc(IOUtil$Releaser));
}

$Object* IOUtil$Releaser::clone() {
	 return this->$Record::clone();
}

void IOUtil$Releaser::finalize() {
	this->$Record::finalize();
}

void IOUtil$Releaser::init$($ScopedMemoryAccess$Scope$Handle* handle) {
	$Record::init$();
	$Objects::requireNonNull(handle);
	$set(this, handle$, handle);
}

void IOUtil$Releaser::run() {
	$IOUtil::releaseScope(this->handle$);
}

$Runnable* IOUtil$Releaser::of($ScopedMemoryAccess$Scope$Handle* handle) {
	$init(IOUtil$Releaser);
	return $new(IOUtil$Releaser, handle);
}

$Runnable* IOUtil$Releaser::ofNullable($ScopedMemoryAccess$Scope$Handle* handle) {
	$init(IOUtil$Releaser);
	if (handle == nullptr) {
		return static_cast<$Runnable*>($new(IOUtil$Releaser$$Lambda$lambda$ofNullable$0));
	}
	return $new(IOUtil$Releaser, handle);
}

void IOUtil$Releaser::lambda$ofNullable$0() {
	$init(IOUtil$Releaser);
}

$ScopedMemoryAccess$Scope$Handle* IOUtil$Releaser::handle() {
	return this->handle$;
}

$String* IOUtil$Releaser::toString() {
	return IOUtil$Releaser::class$->bootstrapToString(this);
}

int32_t IOUtil$Releaser::hashCode() {
	return IOUtil$Releaser::class$->bootstrapHashCode(this);
}

bool IOUtil$Releaser::equals(Object$* o) {
	return IOUtil$Releaser::class$->bootstrapEquals(this, o);
}

IOUtil$Releaser::IOUtil$Releaser() {
}

$Class* IOUtil$Releaser::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(IOUtil$Releaser$$Lambda$lambda$ofNullable$0::classInfo$.name)) {
			return IOUtil$Releaser$$Lambda$lambda$ofNullable$0::load$(name, initialize);
		}
	}
	$loadClass(IOUtil$Releaser, name, initialize, &_IOUtil$Releaser_ClassInfo_, allocate$IOUtil$Releaser);
	return class$;
}

$Class* IOUtil$Releaser::class$ = nullptr;

		} // ch
	} // nio
} // sun