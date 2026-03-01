#include <jdk/internal/loader/LoaderPool.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/Configuration.h>
#include <java/lang/module/ResolvedModule.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/function/Consumer.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/loader/Loader.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Configuration = ::java::lang::module::Configuration;
using $ResolvedModule = ::java::lang::module::ResolvedModule;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $Consumer = ::java::util::function::Consumer;
using $Stream = ::java::util::stream::Stream;
using $Loader = ::jdk::internal::loader::Loader;

namespace jdk {
	namespace internal {
		namespace loader {

class LoaderPool$$Lambda$lambda$new$0 : public $Consumer {
	$class(LoaderPool$$Lambda$lambda$new$0, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Configuration* cf, $List* parentLayers) {
		$set(this, cf, cf);
		$set(this, parentLayers, parentLayers);
	}
	virtual void accept(Object$* l) override {
		LoaderPool::lambda$new$0(cf, parentLayers, $cast($Loader, l));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LoaderPool$$Lambda$lambda$new$0>());
	}
	$Configuration* cf = nullptr;
	$List* parentLayers = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LoaderPool$$Lambda$lambda$new$0::fieldInfos[3] = {
	{"cf", "Ljava/lang/module/Configuration;", nullptr, $PUBLIC, $field(LoaderPool$$Lambda$lambda$new$0, cf)},
	{"parentLayers", "Ljava/util/List;", nullptr, $PUBLIC, $field(LoaderPool$$Lambda$lambda$new$0, parentLayers)},
	{}
};
$MethodInfo LoaderPool$$Lambda$lambda$new$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/module/Configuration;Ljava/util/List;)V", nullptr, $PUBLIC, $method(LoaderPool$$Lambda$lambda$new$0, init$, void, $Configuration*, $List*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(LoaderPool$$Lambda$lambda$new$0, accept, void, Object$*)},
	{}
};
$ClassInfo LoaderPool$$Lambda$lambda$new$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.loader.LoaderPool$$Lambda$lambda$new$0",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* LoaderPool$$Lambda$lambda$new$0::load$($String* name, bool initialize) {
	$loadClass(LoaderPool$$Lambda$lambda$new$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LoaderPool$$Lambda$lambda$new$0::class$ = nullptr;

$FieldInfo _LoaderPool_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(LoaderPool, $assertionsDisabled)},
	{"loaders", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljdk/internal/loader/Loader;>;", $PRIVATE | $FINAL, $field(LoaderPool, loaders$)},
	{}
};

$MethodInfo _LoaderPool_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/module/Configuration;Ljava/util/List;Ljava/lang/ClassLoader;)V", "(Ljava/lang/module/Configuration;Ljava/util/List<Ljava/lang/ModuleLayer;>;Ljava/lang/ClassLoader;)V", $PUBLIC, $method(LoaderPool, init$, void, $Configuration*, $List*, $ClassLoader*)},
	{"lambda$new$0", "(Ljava/lang/module/Configuration;Ljava/util/List;Ljdk/internal/loader/Loader;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LoaderPool, lambda$new$0, void, $Configuration*, $List*, $Loader*)},
	{"loaderFor", "(Ljava/lang/String;)Ljdk/internal/loader/Loader;", nullptr, $PUBLIC, $method(LoaderPool, loaderFor, $Loader*, $String*)},
	{"loaders", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljdk/internal/loader/Loader;>;", $PUBLIC, $method(LoaderPool, loaders, $Stream*)},
	{}
};

$ClassInfo _LoaderPool_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.loader.LoaderPool",
	"java.lang.Object",
	nullptr,
	_LoaderPool_FieldInfo_,
	_LoaderPool_MethodInfo_
};

$Object* allocate$LoaderPool($Class* clazz) {
	return $of($alloc(LoaderPool));
}

bool LoaderPool::$assertionsDisabled = false;

void LoaderPool::init$($Configuration* cf, $List* parentLayers, $ClassLoader* parentLoader) {
	$useLocalCurrentObjectStackCache();
	$var($Map, loaders, $new($HashMap));
	{
		$var($Iterator, i$, $nc($($nc(cf)->modules()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ResolvedModule, resolvedModule, $cast($ResolvedModule, i$->next()));
			{
				$var($Loader, loader, $new($Loader, resolvedModule, this, parentLoader));
				$var($String, mn, $nc(resolvedModule)->name());
				loaders->put(mn, loader);
			}
		}
	}
	$set(this, loaders$, loaders);
	$nc($(loaders->values()))->forEach(static_cast<$Consumer*>($$new(LoaderPool$$Lambda$lambda$new$0, cf, parentLayers)));
}

$Loader* LoaderPool::loaderFor($String* name) {
	$var($Loader, loader, $cast($Loader, $nc(this->loaders$)->get(name)));
	if (!LoaderPool::$assertionsDisabled && !(loader != nullptr)) {
		$throwNew($AssertionError);
	}
	return loader;
}

$Stream* LoaderPool::loaders() {
	return $nc($($nc(this->loaders$)->values()))->stream();
}

void LoaderPool::lambda$new$0($Configuration* cf, $List* parentLayers, $Loader* l) {
	$init(LoaderPool);
	$nc(l)->initRemotePackageMap(cf, parentLayers);
}

void clinit$LoaderPool($Class* class$) {
	LoaderPool::$assertionsDisabled = !LoaderPool::class$->desiredAssertionStatus();
}

LoaderPool::LoaderPool() {
}

$Class* LoaderPool::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(LoaderPool$$Lambda$lambda$new$0::classInfo$.name)) {
			return LoaderPool$$Lambda$lambda$new$0::load$(name, initialize);
		}
	}
	$loadClass(LoaderPool, name, initialize, &_LoaderPool_ClassInfo_, clinit$LoaderPool, allocate$LoaderPool);
	return class$;
}

$Class* LoaderPool::class$ = nullptr;

		} // loader
	} // internal
} // jdk