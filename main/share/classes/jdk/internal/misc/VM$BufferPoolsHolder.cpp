#include <jdk/internal/misc/VM$BufferPoolsHolder.h>

#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/List.h>
#include <jdk/internal/access/JavaNioAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/misc/VM$BufferPool.h>
#include <jdk/internal/misc/VM.h>
#include <sun/nio/ch/FileChannelImpl.h>
#include <jcpp.h>

#undef BUFFER_POOLS

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $List = ::java::util::List;
using $JavaNioAccess = ::jdk::internal::access::JavaNioAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $FileChannelImpl = ::sun::nio::ch::FileChannelImpl;

namespace jdk {
	namespace internal {
		namespace misc {

$FieldInfo _VM$BufferPoolsHolder_FieldInfo_[] = {
	{"BUFFER_POOLS", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/misc/VM$BufferPool;>;", $STATIC | $FINAL, $staticField(VM$BufferPoolsHolder, BUFFER_POOLS)},
	{}
};

$MethodInfo _VM$BufferPoolsHolder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(VM$BufferPoolsHolder, init$, void)},
	{}
};

$InnerClassInfo _VM$BufferPoolsHolder_InnerClassesInfo_[] = {
	{"jdk.internal.misc.VM$BufferPoolsHolder", "jdk.internal.misc.VM", "BufferPoolsHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _VM$BufferPoolsHolder_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.misc.VM$BufferPoolsHolder",
	"java.lang.Object",
	nullptr,
	_VM$BufferPoolsHolder_FieldInfo_,
	_VM$BufferPoolsHolder_MethodInfo_,
	nullptr,
	nullptr,
	_VM$BufferPoolsHolder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.misc.VM"
};

$Object* allocate$VM$BufferPoolsHolder($Class* clazz) {
	return $of($alloc(VM$BufferPoolsHolder));
}

$List* VM$BufferPoolsHolder::BUFFER_POOLS = nullptr;

void VM$BufferPoolsHolder::init$() {
}

void clinit$VM$BufferPoolsHolder($Class* class$) {
	$useLocalCurrentObjectStackCache();
	{
		$var($ArrayList, bufferPools, $new($ArrayList, 3));
		bufferPools->add($($nc($($SharedSecrets::getJavaNioAccess()))->getDirectBufferPool()));
		bufferPools->add($($FileChannelImpl::getMappedBufferPool()));
		bufferPools->add($($FileChannelImpl::getSyncMappedBufferPool()));
		$assignStatic(VM$BufferPoolsHolder::BUFFER_POOLS, $Collections::unmodifiableList(bufferPools));
	}
}

VM$BufferPoolsHolder::VM$BufferPoolsHolder() {
}

$Class* VM$BufferPoolsHolder::load$($String* name, bool initialize) {
	$loadClass(VM$BufferPoolsHolder, name, initialize, &_VM$BufferPoolsHolder_ClassInfo_, clinit$VM$BufferPoolsHolder, allocate$VM$BufferPoolsHolder);
	return class$;
}

$Class* VM$BufferPoolsHolder::class$ = nullptr;

		} // misc
	} // internal
} // jdk