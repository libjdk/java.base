#include <sun/nio/ch/IOUtil$LinkedRunnable.h>

#include <java/lang/Record.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/runtime/ObjectMethods.h>
#include <java/util/Objects.h>
#include <sun/nio/ch/IOUtil.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Record = ::java::lang::Record;
using $Runnable = ::java::lang::Runnable;
using $Objects = ::java::util::Objects;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _IOUtil$LinkedRunnable_FieldInfo_[] = {
	{"node", "Ljava/lang/Runnable;", nullptr, $PRIVATE | $FINAL, $field(IOUtil$LinkedRunnable, node$)},
	{"next", "Ljava/lang/Runnable;", nullptr, $PRIVATE | $FINAL, $field(IOUtil$LinkedRunnable, next$)},
	{}
};

$MethodInfo _IOUtil$LinkedRunnable_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(Ljava/lang/Runnable;Ljava/lang/Runnable;)V", nullptr, 0, $method(IOUtil$LinkedRunnable, init$, void, $Runnable*, $Runnable*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(IOUtil$LinkedRunnable, equals, bool, Object$*)},
	{"hashCode", "()I", nullptr, $PUBLIC | $FINAL, $virtualMethod(IOUtil$LinkedRunnable, hashCode, int32_t)},
	{"next", "()Ljava/lang/Runnable;", nullptr, $PUBLIC, $method(IOUtil$LinkedRunnable, next, $Runnable*)},
	{"node", "()Ljava/lang/Runnable;", nullptr, $PUBLIC, $method(IOUtil$LinkedRunnable, node, $Runnable*)},
	{"of", "(Ljava/lang/Runnable;Ljava/lang/Runnable;)Lsun/nio/ch/IOUtil$LinkedRunnable;", nullptr, $STATIC, $staticMethod(IOUtil$LinkedRunnable, of, IOUtil$LinkedRunnable*, $Runnable*, $Runnable*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(IOUtil$LinkedRunnable, run, void)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $virtualMethod(IOUtil$LinkedRunnable, toString, $String*)},
	{}
};

$InnerClassInfo _IOUtil$LinkedRunnable_InnerClassesInfo_[] = {
	{"sun.nio.ch.IOUtil$LinkedRunnable", "sun.nio.ch.IOUtil", "LinkedRunnable", $STATIC | $FINAL},
	{}
};

$ClassInfo _IOUtil$LinkedRunnable_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.nio.ch.IOUtil$LinkedRunnable",
	"java.lang.Record",
	"java.lang.Runnable",
	_IOUtil$LinkedRunnable_FieldInfo_,
	_IOUtil$LinkedRunnable_MethodInfo_,
	nullptr,
	nullptr,
	_IOUtil$LinkedRunnable_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.ch.IOUtil"
};

$Object* allocate$IOUtil$LinkedRunnable($Class* clazz) {
	return $of($alloc(IOUtil$LinkedRunnable));
}

$Object* IOUtil$LinkedRunnable::clone() {
	 return this->$Record::clone();
}

void IOUtil$LinkedRunnable::finalize() {
	this->$Record::finalize();
}

void IOUtil$LinkedRunnable::init$($Runnable* node, $Runnable* next) {
	$Record::init$();
	$Objects::requireNonNull(node);
	$set(this, node$, node);
	$set(this, next$, next);
}

void IOUtil$LinkedRunnable::run() {
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(this->node$)->run();
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (this->next$ != nullptr) {
				$nc(this->next$)->run();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

IOUtil$LinkedRunnable* IOUtil$LinkedRunnable::of($Runnable* first, $Runnable* second) {
	$init(IOUtil$LinkedRunnable);
	return $new(IOUtil$LinkedRunnable, first, second);
}

$Runnable* IOUtil$LinkedRunnable::node() {
	return this->node$;
}

$Runnable* IOUtil$LinkedRunnable::next() {
	return this->next$;
}

$String* IOUtil$LinkedRunnable::toString() {
	return IOUtil$LinkedRunnable::class$->bootstrapToString(this);
}

int32_t IOUtil$LinkedRunnable::hashCode() {
	return IOUtil$LinkedRunnable::class$->bootstrapHashCode(this);
}

bool IOUtil$LinkedRunnable::equals(Object$* o) {
	return IOUtil$LinkedRunnable::class$->bootstrapEquals(this, o);
}

IOUtil$LinkedRunnable::IOUtil$LinkedRunnable() {
}

$Class* IOUtil$LinkedRunnable::load$($String* name, bool initialize) {
	$loadClass(IOUtil$LinkedRunnable, name, initialize, &_IOUtil$LinkedRunnable_ClassInfo_, allocate$IOUtil$LinkedRunnable);
	return class$;
}

$Class* IOUtil$LinkedRunnable::class$ = nullptr;

		} // ch
	} // nio
} // sun