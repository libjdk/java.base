#include <jdk/internal/perf/Perf.h>

#include <java/lang/Math.h>
#include <java/lang/Runnable.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/ref/Cleaner$Cleanable.h>
#include <java/lang/ref/Cleaner.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/charset/Charset.h>
#include <java/security/Permission.h>
#include <jdk/internal/perf/Perf$CleanerAction.h>
#include <jdk/internal/ref/CleanerFactory.h>
#include <sun/nio/cs/UTF_8.h>
#include <jcpp.h>

#undef INSTANCE
#undef PERF_MODE_RO
#undef PERF_MODE_RW

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $Cleaner = ::java::lang::ref::Cleaner;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Charset = ::java::nio::charset::Charset;
using $Permission = ::java::security::Permission;
using $Perf$CleanerAction = ::jdk::internal::perf::Perf$CleanerAction;
using $CleanerFactory = ::jdk::internal::ref::CleanerFactory;
using $UTF_8 = ::sun::nio::cs::UTF_8;

namespace jdk {
	namespace internal {
		namespace perf {

$FieldInfo _Perf_FieldInfo_[] = {
	{"instance", "Ljdk/internal/perf/Perf;", nullptr, $PRIVATE | $STATIC, $staticField(Perf, instance)},
	{"PERF_MODE_RO", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Perf, PERF_MODE_RO)},
	{"PERF_MODE_RW", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Perf, PERF_MODE_RW)},
	{}
};

$MethodInfo _Perf_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(Perf, init$, void)},
	{"attach", "(ILjava/lang/String;)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $method(Perf, attach, $ByteBuffer*, int32_t, $String*), "java.lang.IllegalArgumentException,java.io.IOException"},
	{"attach", "(Ljava/lang/String;ILjava/lang/String;)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $method(Perf, attach, $ByteBuffer*, $String*, int32_t, $String*), "java.lang.IllegalArgumentException,java.io.IOException"},
	{"attach", "(Ljava/lang/String;II)Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $NATIVE, $method(Perf, attach, $ByteBuffer*, $String*, int32_t, int32_t), "java.lang.IllegalArgumentException,java.io.IOException"},
	{"attachImpl", "(Ljava/lang/String;II)Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $method(Perf, attachImpl, $ByteBuffer*, $String*, int32_t, int32_t), "java.lang.IllegalArgumentException,java.io.IOException"},
	{"createByteArray", "(Ljava/lang/String;II[BI)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $NATIVE, $method(Perf, createByteArray, $ByteBuffer*, $String*, int32_t, int32_t, $bytes*, int32_t)},
	{"createLong", "(Ljava/lang/String;IIJ)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $NATIVE, $method(Perf, createLong, $ByteBuffer*, $String*, int32_t, int32_t, int64_t)},
	{"createString", "(Ljava/lang/String;IILjava/lang/String;I)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $method(Perf, createString, $ByteBuffer*, $String*, int32_t, int32_t, $String*, int32_t)},
	{"createString", "(Ljava/lang/String;IILjava/lang/String;)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $method(Perf, createString, $ByteBuffer*, $String*, int32_t, int32_t, $String*)},
	{"detach", "(Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE | $NATIVE, $method(Perf, detach, void, $ByteBuffer*)},
	{"getPerf", "()Ljdk/internal/perf/Perf;", nullptr, $PUBLIC | $STATIC, $staticMethod(Perf, getPerf, Perf*)},
	{"highResCounter", "()J", nullptr, $PUBLIC | $NATIVE, $method(Perf, highResCounter, int64_t)},
	{"highResFrequency", "()J", nullptr, $PUBLIC | $NATIVE, $method(Perf, highResFrequency, int64_t)},
	{"registerNatives", "()V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(Perf, registerNatives, void)},
	{}
};

#define _METHOD_INDEX_attach 3
#define _METHOD_INDEX_createByteArray 5
#define _METHOD_INDEX_createLong 6
#define _METHOD_INDEX_detach 9
#define _METHOD_INDEX_highResCounter 11
#define _METHOD_INDEX_highResFrequency 12
#define _METHOD_INDEX_registerNatives 13

$InnerClassInfo _Perf_InnerClassesInfo_[] = {
	{"jdk.internal.perf.Perf$CleanerAction", "jdk.internal.perf.Perf", "CleanerAction", $PRIVATE | $STATIC},
	{"jdk.internal.perf.Perf$GetPerfAction", "jdk.internal.perf.Perf", "GetPerfAction", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _Perf_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.perf.Perf",
	"java.lang.Object",
	nullptr,
	_Perf_FieldInfo_,
	_Perf_MethodInfo_,
	nullptr,
	nullptr,
	_Perf_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.perf.Perf$CleanerAction,jdk.internal.perf.Perf$GetPerfAction"
};

$Object* allocate$Perf($Class* clazz) {
	return $of($alloc(Perf));
}

Perf* Perf::instance = nullptr;

void Perf::init$() {
}

Perf* Perf::getPerf() {
	$init(Perf);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		$var($Permission, perm, $new($RuntimePermission, "jdk.internal.perf.Perf.getPerf"_s));
		security->checkPermission(perm);
	}
	return Perf::instance;
}

$ByteBuffer* Perf::attach(int32_t lvmid, $String* mode) {
	if ($nc(mode)->compareTo("r"_s) == 0) {
		return attachImpl(nullptr, lvmid, Perf::PERF_MODE_RO);
	} else if (mode->compareTo("rw"_s) == 0) {
		return attachImpl(nullptr, lvmid, Perf::PERF_MODE_RW);
	} else {
		$throwNew($IllegalArgumentException, "unknown mode"_s);
	}
}

$ByteBuffer* Perf::attach($String* user, int32_t lvmid, $String* mode) {
	if ($nc(mode)->compareTo("r"_s) == 0) {
		return attachImpl(user, lvmid, Perf::PERF_MODE_RO);
	} else if (mode->compareTo("rw"_s) == 0) {
		return attachImpl(user, lvmid, Perf::PERF_MODE_RW);
	} else {
		$throwNew($IllegalArgumentException, "unknown mode"_s);
	}
}

$ByteBuffer* Perf::attachImpl($String* user, int32_t lvmid, int32_t mode) {
	$useLocalCurrentObjectStackCache();
	$var($ByteBuffer, b, attach(user, lvmid, mode));
	if (lvmid == 0) {
		return b;
	} else {
		$var($ByteBuffer, dup, $nc(b)->duplicate());
		$nc($($CleanerFactory::cleaner()))->register$(dup, $$new($Perf$CleanerAction, Perf::instance, b));
		return dup;
	}
}

$ByteBuffer* Perf::attach($String* user, int32_t lvmid, int32_t mode) {
	// TODO
	return nullptr;
}

void Perf::detach($ByteBuffer* bb) {
	// TODO
}

$ByteBuffer* Perf::createLong($String* name, int32_t variability, int32_t units, int64_t value) {
	// TODO
	return $ByteBuffer::allocateDirect(sizeof(int64_t));
}

$ByteBuffer* Perf::createString($String* name, int32_t variability, int32_t units, $String* value, int32_t maxLength) {
	$useLocalCurrentObjectStackCache();
	$init($UTF_8);
	$var($bytes, v, $nc(value)->getBytes(static_cast<$Charset*>($UTF_8::INSTANCE)));
	$var($bytes, v1, $new($bytes, v->length + 1));
	$System::arraycopy(v, 0, v1, 0, v->length);
	v1->set(v->length, (int8_t)u'\0');
	return createByteArray(name, variability, units, v1, $Math::max(v1->length, maxLength));
}

$ByteBuffer* Perf::createString($String* name, int32_t variability, int32_t units, $String* value) {
	$useLocalCurrentObjectStackCache();
	$init($UTF_8);
	$var($bytes, v, $nc(value)->getBytes(static_cast<$Charset*>($UTF_8::INSTANCE)));
	$var($bytes, v1, $new($bytes, v->length + 1));
	$System::arraycopy(v, 0, v1, 0, v->length);
	v1->set(v->length, (int8_t)u'\0');
	return createByteArray(name, variability, units, v1, v1->length);
}

$ByteBuffer* Perf::createByteArray($String* name, int32_t variability, int32_t units, $bytes* value, int32_t maxLength) {
	// TODO
	return nullptr;
}

int64_t Perf::highResCounter() {
	// TODO
	return 0;
}

int64_t Perf::highResFrequency() {
	// TODO
	return 0;
}

void Perf::registerNatives() {
}

void clinit$Perf($Class* class$) {
	{
		Perf::registerNatives();
		$assignStatic(Perf::instance, $new(Perf));
	}
}

Perf::Perf() {
}

$Class* Perf::load$($String* name, bool initialize) {
	$loadClass(Perf, name, initialize, &_Perf_ClassInfo_, clinit$Perf, allocate$Perf);
	return class$;
}

$Class* Perf::class$ = nullptr;

		} // perf
	} // internal
} // jdk