#include <java/lang/invoke/BootstrapMethodInvoker$VM_BSCI.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/invoke/AbstractConstantGroup$BSCIWithCache.h>
#include <java/lang/invoke/AbstractConstantGroup$WithCache.h>
#include <java/lang/invoke/AbstractConstantGroup.h>
#include <java/lang/invoke/BootstrapMethodInvoker.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandleNatives.h>
#include <java/lang/invoke/MethodHandleStatics.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/util/Arrays.h>
#include <java/util/List.h>
#include <jcpp.h>

#undef MIN_PF
#undef NOT_PRESENT
#undef TRACE_METHOD_LINKAGE

using $SerializableArray = $Array<::java::io::Serializable>;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractConstantGroup$BSCIWithCache = ::java::lang::invoke::AbstractConstantGroup$BSCIWithCache;
using $AbstractConstantGroup$WithCache = ::java::lang::invoke::AbstractConstantGroup$WithCache;
using $BootstrapMethodInvoker = ::java::lang::invoke::BootstrapMethodInvoker;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandleNatives = ::java::lang::invoke::MethodHandleNatives;
using $MethodHandleStatics = ::java::lang::invoke::MethodHandleStatics;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $Arrays = ::java::util::Arrays;

namespace java {
	namespace lang {
		namespace invoke {

$FieldInfo _BootstrapMethodInvoker$VM_BSCI_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(BootstrapMethodInvoker$VM_BSCI, $assertionsDisabled)},
	{"indexInfo", "[I", nullptr, $PRIVATE | $FINAL, $field(BootstrapMethodInvoker$VM_BSCI, indexInfo)},
	{"caller", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $FINAL, $field(BootstrapMethodInvoker$VM_BSCI, caller)},
	{"MIN_PF", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(BootstrapMethodInvoker$VM_BSCI, MIN_PF)},
	{}
};

$MethodInfo _BootstrapMethodInvoker$VM_BSCI_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/String;Ljava/lang/Object;Ljava/lang/invoke/MethodHandles$Lookup;[I)V", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/String;TT;Ljava/lang/invoke/MethodHandles$Lookup;[I)V", 0, $method(BootstrapMethodInvoker$VM_BSCI, init$, void, $MethodHandle*, $String*, Object$*, $MethodHandles$Lookup*, $ints*)},
	{"copyConstants", "(II[Ljava/lang/Object;I)I", nullptr, $PUBLIC, $virtualMethod(BootstrapMethodInvoker$VM_BSCI, copyConstants, int32_t, int32_t, int32_t, $ObjectArray*, int32_t)},
	{"fillCache", "(I)Ljava/lang/Object;", nullptr, 0, $virtualMethod(BootstrapMethodInvoker$VM_BSCI, fillCache, $Object*, int32_t)},
	{"maybePrefetchIntoCache", "(IZ)V", nullptr, $PRIVATE, $method(BootstrapMethodInvoker$VM_BSCI, maybePrefetchIntoCache, void, int32_t, bool)},
	{"prefetchIntoCache", "(II)V", nullptr, $PRIVATE, $method(BootstrapMethodInvoker$VM_BSCI, prefetchIntoCache, void, int32_t, int32_t)},
	{}
};

$InnerClassInfo _BootstrapMethodInvoker$VM_BSCI_InnerClassesInfo_[] = {
	{"java.lang.invoke.BootstrapMethodInvoker$VM_BSCI", "java.lang.invoke.BootstrapMethodInvoker", "VM_BSCI", $PRIVATE | $STATIC | $FINAL},
	{"java.lang.invoke.AbstractConstantGroup$BSCIWithCache", "java.lang.invoke.AbstractConstantGroup", "BSCIWithCache", $STATIC},
	{}
};

$ClassInfo _BootstrapMethodInvoker$VM_BSCI_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.lang.invoke.BootstrapMethodInvoker$VM_BSCI",
	"java.lang.invoke.AbstractConstantGroup$BSCIWithCache",
	nullptr,
	_BootstrapMethodInvoker$VM_BSCI_FieldInfo_,
	_BootstrapMethodInvoker$VM_BSCI_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/invoke/AbstractConstantGroup$BSCIWithCache<TT;>;",
	nullptr,
	_BootstrapMethodInvoker$VM_BSCI_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.invoke.BootstrapMethodInvoker"
};

$Object* allocate$BootstrapMethodInvoker$VM_BSCI($Class* clazz) {
	return $of($alloc(BootstrapMethodInvoker$VM_BSCI));
}

bool BootstrapMethodInvoker$VM_BSCI::$assertionsDisabled = false;

void BootstrapMethodInvoker$VM_BSCI::init$($MethodHandle* bsm, $String* name, Object$* type, $MethodHandles$Lookup* lookup, $ints* indexInfo) {
	$AbstractConstantGroup$BSCIWithCache::init$(bsm, name, type, $nc(indexInfo)->get(0));
	if (!$nc(lookup)->hasFullPrivilegeAccess()) {
		$throwNew($AssertionError, $of("bad Lookup object"_s));
	}
	$set(this, caller, $nc(lookup)->lookupClass());
	$set(this, indexInfo, indexInfo);
	prefetchIntoCache(0, size());
}

$Object* BootstrapMethodInvoker$VM_BSCI::fillCache(int32_t i) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, buf, $new($ObjectArray, {($Object*)nullptr}));
	copyConstants(i, i + 1, buf, 0);
	$var($Object, res, wrapNull(buf->get(0)));
	$nc(this->cache)->set(i, res);
	int32_t next = i + 1;
	if (next < $nc(this->cache)->length && $nc(this->cache)->get(next) == nullptr) {
		maybePrefetchIntoCache(next, false);
	}
	return $of(res);
}

int32_t BootstrapMethodInvoker$VM_BSCI::copyConstants(int32_t start, int32_t end, $ObjectArray* buf, int32_t pos) {
	$useLocalCurrentObjectStackCache();
	int32_t i = start;
	int32_t bufi = pos;
	while (i < end) {
		$var($Object, x, $nc(this->cache)->get(i));
		if (x == nullptr) {
			break;
		}
		$nc(buf)->set(bufi++, $(unwrapNull(x)));
		++i;
	}
	if (i >= end) {
		return i;
	}
	$var($ObjectArray, temp, $new($ObjectArray, end - i));
	$init($MethodHandleStatics);
	if ($MethodHandleStatics::TRACE_METHOD_LINKAGE) {
		$nc($System::out)->println($$str({"resolving more BSM arguments: "_s, $($Arrays::asList($$new($SerializableArray, {
			$(static_cast<$Serializable*>($nc(this->caller)->getSimpleName())),
			$(static_cast<$Serializable*>($Arrays::toString(this->indexInfo))),
			$(static_cast<$Serializable*>($Integer::valueOf(i))),
			$(static_cast<$Serializable*>($Integer::valueOf(end)))
		})))}));
	}
	$MethodHandleNatives::copyOutBootstrapArguments(this->caller, this->indexInfo, i, end, temp, 0, true, nullptr);
	{
		$var($ObjectArray, arr$, temp);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Object, x, arr$->get(i$));
			{
				$assign(x, $BootstrapMethodInvoker::maybeReBox(x));
				$nc(buf)->set(bufi++, x);
				$nc(this->cache)->set(i++, $(wrapNull(x)));
			}
		}
	}
	if (end < $nc(this->cache)->length && $nc(this->cache)->get(end) == nullptr) {
		maybePrefetchIntoCache(end, true);
	}
	return i;
}

void BootstrapMethodInvoker$VM_BSCI::maybePrefetchIntoCache(int32_t i, bool bulk) {
	int32_t len = $nc(this->cache)->length;
	if (!BootstrapMethodInvoker$VM_BSCI::$assertionsDisabled && !(0 <= i && i <= len)) {
		$throwNew($AssertionError);
	}
	int32_t pfLimit = i;
	if (bulk) {
		pfLimit += i;
	}
	if (pfLimit < i + BootstrapMethodInvoker$VM_BSCI::MIN_PF) {
		pfLimit = i + BootstrapMethodInvoker$VM_BSCI::MIN_PF;
	}
	if (pfLimit > len || pfLimit < 0) {
		pfLimit = len;
	}
	int32_t empty = 0;
	int32_t nonEmpty = 0;
	int32_t lastEmpty = i;
	for (int32_t j = i; j < pfLimit; ++j) {
		if ($nc(this->cache)->get(j) == nullptr) {
			++empty;
			lastEmpty = j;
		} else {
			++nonEmpty;
			if (nonEmpty > empty) {
				pfLimit = lastEmpty + 1;
				break;
			}
			if (pfLimit < len) {
				++pfLimit;
			}
		}
	}
	if (bulk && empty < BootstrapMethodInvoker$VM_BSCI::MIN_PF && pfLimit < len) {
		return;
	}
	prefetchIntoCache(i, pfLimit);
}

void BootstrapMethodInvoker$VM_BSCI::prefetchIntoCache(int32_t i, int32_t pfLimit) {
	$useLocalCurrentObjectStackCache();
	if (pfLimit <= i) {
		return;
	}
	$var($ObjectArray, temp, $new($ObjectArray, pfLimit - i));
	$init($MethodHandleStatics);
	if ($MethodHandleStatics::TRACE_METHOD_LINKAGE) {
		$nc($System::out)->println($$str({"prefetching BSM arguments: "_s, $($Arrays::asList($$new($SerializableArray, {
			$(static_cast<$Serializable*>($nc(this->caller)->getSimpleName())),
			$(static_cast<$Serializable*>($Arrays::toString(this->indexInfo))),
			$(static_cast<$Serializable*>($Integer::valueOf(i))),
			$(static_cast<$Serializable*>($Integer::valueOf(pfLimit)))
		})))}));
	}
	$init($AbstractConstantGroup$WithCache);
	$MethodHandleNatives::copyOutBootstrapArguments(this->caller, this->indexInfo, i, pfLimit, temp, 0, false, $AbstractConstantGroup$WithCache::NOT_PRESENT);
	{
		$var($ObjectArray, arr$, temp);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Object0, x, arr$->get(i$));
			{
				if (!$equals(x, $AbstractConstantGroup$WithCache::NOT_PRESENT) && $nc(this->cache)->get(i) == nullptr) {
					$nc(this->cache)->set(i, $(wrapNull($($BootstrapMethodInvoker::maybeReBox(x)))));
				}
				++i;
			}
		}
	}
}

void clinit$BootstrapMethodInvoker$VM_BSCI($Class* class$) {
	$load($BootstrapMethodInvoker);
	BootstrapMethodInvoker$VM_BSCI::$assertionsDisabled = !$BootstrapMethodInvoker::class$->desiredAssertionStatus();
}

BootstrapMethodInvoker$VM_BSCI::BootstrapMethodInvoker$VM_BSCI() {
}

$Class* BootstrapMethodInvoker$VM_BSCI::load$($String* name, bool initialize) {
	$loadClass(BootstrapMethodInvoker$VM_BSCI, name, initialize, &_BootstrapMethodInvoker$VM_BSCI_ClassInfo_, clinit$BootstrapMethodInvoker$VM_BSCI, allocate$BootstrapMethodInvoker$VM_BSCI);
	return class$;
}

$Class* BootstrapMethodInvoker$VM_BSCI::class$ = nullptr;

		} // invoke
	} // lang
} // java