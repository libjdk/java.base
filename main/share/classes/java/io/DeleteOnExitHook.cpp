#include <java/io/DeleteOnExitHook.h>

#include <java/io/DeleteOnExitHook$1.h>
#include <java/io/File.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/Runnable.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractSet.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashSet.h>
#include <java/util/List.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jcpp.h>

using $DeleteOnExitHook$1 = ::java::io::DeleteOnExitHook$1;
using $File = ::java::io::File;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractSet = ::java::util::AbstractSet;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $LinkedHashSet = ::java::util::LinkedHashSet;
using $List = ::java::util::List;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;

namespace java {
	namespace io {

$FieldInfo _DeleteOnExitHook_FieldInfo_[] = {
	{"files", "Ljava/util/LinkedHashSet;", "Ljava/util/LinkedHashSet<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticField(DeleteOnExitHook, files)},
	{}
};

$MethodInfo _DeleteOnExitHook_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(DeleteOnExitHook, init$, void)},
	{"add", "(Ljava/lang/String;)V", nullptr, $STATIC | $SYNCHRONIZED, $staticMethod(DeleteOnExitHook, add, void, $String*)},
	{"runHooks", "()V", nullptr, $STATIC, $staticMethod(DeleteOnExitHook, runHooks, void)},
	{}
};

$InnerClassInfo _DeleteOnExitHook_InnerClassesInfo_[] = {
	{"java.io.DeleteOnExitHook$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DeleteOnExitHook_ClassInfo_ = {
	$ACC_SUPER,
	"java.io.DeleteOnExitHook",
	"java.lang.Object",
	nullptr,
	_DeleteOnExitHook_FieldInfo_,
	_DeleteOnExitHook_MethodInfo_,
	nullptr,
	nullptr,
	_DeleteOnExitHook_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.io.DeleteOnExitHook$1"
};

$Object* allocate$DeleteOnExitHook($Class* clazz) {
	return $of($alloc(DeleteOnExitHook));
}

$LinkedHashSet* DeleteOnExitHook::files = nullptr;

void DeleteOnExitHook::init$() {
}

void DeleteOnExitHook::add($String* file) {
	$load(DeleteOnExitHook);
	$synchronized(class$) {
		$init(DeleteOnExitHook);
		if (DeleteOnExitHook::files == nullptr) {
			$throwNew($IllegalStateException, "Shutdown in progress"_s);
		}
		$nc(DeleteOnExitHook::files)->add(file);
	}
}

void DeleteOnExitHook::runHooks() {
	$init(DeleteOnExitHook);
	$useLocalCurrentObjectStackCache();
	$var($LinkedHashSet, theFiles, nullptr);
	$synchronized(DeleteOnExitHook::class$) {
		$assign(theFiles, DeleteOnExitHook::files);
		$assignStatic(DeleteOnExitHook::files, nullptr);
	}
	$var($ArrayList, toBeDeleted, $new($ArrayList, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(static_cast<$HashSet*>(theFiles))))));
	$Collections::reverse(toBeDeleted);
	{
		$var($Iterator, i$, toBeDeleted->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, filename, $cast($String, i$->next()));
			{
				($$new($File, filename))->delete$();
			}
		}
	}
}

void clinit$DeleteOnExitHook($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(DeleteOnExitHook::files, $new($LinkedHashSet));
	{
		$nc($($SharedSecrets::getJavaLangAccess()))->registerShutdownHook(2, true, $$new($DeleteOnExitHook$1));
	}
}

DeleteOnExitHook::DeleteOnExitHook() {
}

$Class* DeleteOnExitHook::load$($String* name, bool initialize) {
	$loadClass(DeleteOnExitHook, name, initialize, &_DeleteOnExitHook_ClassInfo_, clinit$DeleteOnExitHook, allocate$DeleteOnExitHook);
	return class$;
}

$Class* DeleteOnExitHook::class$ = nullptr;

	} // io
} // java