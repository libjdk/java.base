#include <jdk/internal/module/ModuleHashesBuilder.h>

#include <java/io/Serializable.h>
#include <java/lang/InternalError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/Configuration.h>
#include <java/lang/module/ModuleReference.h>
#include <java/lang/module/ResolvedModule.h>
#include <java/util/AbstractMap.h>
#include <java/util/ArrayDeque.h>
#include <java/util/Collection.h>
#include <java/util/Deque.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/TreeMap.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/module/ModuleHashes.h>
#include <jdk/internal/module/ModuleHashesBuilder$Graph$Builder.h>
#include <jdk/internal/module/ModuleHashesBuilder$Graph.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Configuration = ::java::lang::module::Configuration;
using $ResolvedModule = ::java::lang::module::ResolvedModule;
using $AbstractMap = ::java::util::AbstractMap;
using $ArrayDeque = ::java::util::ArrayDeque;
using $Collection = ::java::util::Collection;
using $Deque = ::java::util::Deque;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $TreeMap = ::java::util::TreeMap;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $Supplier = ::java::util::function::Supplier;
using $Collectors = ::java::util::stream::Collectors;
using $Stream = ::java::util::stream::Stream;
using $ModuleHashes = ::jdk::internal::module::ModuleHashes;
using $ModuleHashesBuilder$Graph = ::jdk::internal::module::ModuleHashesBuilder$Graph;
using $ModuleHashesBuilder$Graph$Builder = ::jdk::internal::module::ModuleHashesBuilder$Graph$Builder;

namespace jdk {
	namespace internal {
		namespace module {

class ModuleHashesBuilder$$Lambda$lambda$computeHashes$0 : public $Predicate {
	$class(ModuleHashesBuilder$$Lambda$lambda$computeHashes$0, $NO_CLASS_INIT, $Predicate)
public:
	void init$($Set* roots, $Set* mods) {
		$set(this, roots, roots);
		$set(this, mods, mods);
	}
	virtual bool test(Object$* mn) override {
		 return ModuleHashesBuilder::lambda$computeHashes$0(roots, mods, $cast($String, mn));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleHashesBuilder$$Lambda$lambda$computeHashes$0>());
	}
	$Set* roots = nullptr;
	$Set* mods = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModuleHashesBuilder$$Lambda$lambda$computeHashes$0::fieldInfos[3] = {
	{"roots", "Ljava/util/Set;", nullptr, $PUBLIC, $field(ModuleHashesBuilder$$Lambda$lambda$computeHashes$0, roots)},
	{"mods", "Ljava/util/Set;", nullptr, $PUBLIC, $field(ModuleHashesBuilder$$Lambda$lambda$computeHashes$0, mods)},
	{}
};
$MethodInfo ModuleHashesBuilder$$Lambda$lambda$computeHashes$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/Set;Ljava/util/Set;)V", nullptr, $PUBLIC, $method(ModuleHashesBuilder$$Lambda$lambda$computeHashes$0, init$, void, $Set*, $Set*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ModuleHashesBuilder$$Lambda$lambda$computeHashes$0, test, bool, Object$*)},
	{}
};
$ClassInfo ModuleHashesBuilder$$Lambda$lambda$computeHashes$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleHashesBuilder$$Lambda$lambda$computeHashes$0",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* ModuleHashesBuilder$$Lambda$lambda$computeHashes$0::load$($String* name, bool initialize) {
	$loadClass(ModuleHashesBuilder$$Lambda$lambda$computeHashes$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleHashesBuilder$$Lambda$lambda$computeHashes$0::class$ = nullptr;

class ModuleHashesBuilder$$Lambda$lambda$computeHashes$3$1 : public $Consumer {
	$class(ModuleHashesBuilder$$Lambda$lambda$computeHashes$3$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$(ModuleHashesBuilder* inst, $ModuleHashesBuilder$Graph* transposedGraph, $Set* mods, $Map* hashes) {
		$set(this, inst$, inst);
		$set(this, transposedGraph, transposedGraph);
		$set(this, mods, mods);
		$set(this, hashes, hashes);
	}
	virtual void accept(Object$* mn) override {
		$nc(inst$)->lambda$computeHashes$3(transposedGraph, mods, hashes, $cast($String, mn));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleHashesBuilder$$Lambda$lambda$computeHashes$3$1>());
	}
	ModuleHashesBuilder* inst$ = nullptr;
	$ModuleHashesBuilder$Graph* transposedGraph = nullptr;
	$Set* mods = nullptr;
	$Map* hashes = nullptr;
	static $FieldInfo fieldInfos[5];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModuleHashesBuilder$$Lambda$lambda$computeHashes$3$1::fieldInfos[5] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ModuleHashesBuilder$$Lambda$lambda$computeHashes$3$1, inst$)},
	{"transposedGraph", "Ljdk/internal/module/ModuleHashesBuilder$Graph;", nullptr, $PUBLIC, $field(ModuleHashesBuilder$$Lambda$lambda$computeHashes$3$1, transposedGraph)},
	{"mods", "Ljava/util/Set;", nullptr, $PUBLIC, $field(ModuleHashesBuilder$$Lambda$lambda$computeHashes$3$1, mods)},
	{"hashes", "Ljava/util/Map;", nullptr, $PUBLIC, $field(ModuleHashesBuilder$$Lambda$lambda$computeHashes$3$1, hashes)},
	{}
};
$MethodInfo ModuleHashesBuilder$$Lambda$lambda$computeHashes$3$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/module/ModuleHashesBuilder;Ljdk/internal/module/ModuleHashesBuilder$Graph;Ljava/util/Set;Ljava/util/Map;)V", nullptr, $PUBLIC, $method(ModuleHashesBuilder$$Lambda$lambda$computeHashes$3$1, init$, void, ModuleHashesBuilder*, $ModuleHashesBuilder$Graph*, $Set*, $Map*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ModuleHashesBuilder$$Lambda$lambda$computeHashes$3$1, accept, void, Object$*)},
	{}
};
$ClassInfo ModuleHashesBuilder$$Lambda$lambda$computeHashes$3$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleHashesBuilder$$Lambda$lambda$computeHashes$3$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ModuleHashesBuilder$$Lambda$lambda$computeHashes$3$1::load$($String* name, bool initialize) {
	$loadClass(ModuleHashesBuilder$$Lambda$lambda$computeHashes$3$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleHashesBuilder$$Lambda$lambda$computeHashes$3$1::class$ = nullptr;

class ModuleHashesBuilder$$Lambda$lambda$computeHashes$1$2 : public $Predicate {
	$class(ModuleHashesBuilder$$Lambda$lambda$computeHashes$1$2, $NO_CLASS_INIT, $Predicate)
public:
	void init$(ModuleHashesBuilder* inst, $String* mn) {
		$set(this, inst$, inst);
		$set(this, mn, mn);
	}
	virtual bool test(Object$* n) override {
		 return $nc(inst$)->lambda$computeHashes$1(mn, $cast($String, n));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleHashesBuilder$$Lambda$lambda$computeHashes$1$2>());
	}
	ModuleHashesBuilder* inst$ = nullptr;
	$String* mn = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModuleHashesBuilder$$Lambda$lambda$computeHashes$1$2::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ModuleHashesBuilder$$Lambda$lambda$computeHashes$1$2, inst$)},
	{"mn", "Ljava/lang/String;", nullptr, $PUBLIC, $field(ModuleHashesBuilder$$Lambda$lambda$computeHashes$1$2, mn)},
	{}
};
$MethodInfo ModuleHashesBuilder$$Lambda$lambda$computeHashes$1$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/module/ModuleHashesBuilder;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(ModuleHashesBuilder$$Lambda$lambda$computeHashes$1$2, init$, void, ModuleHashesBuilder*, $String*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ModuleHashesBuilder$$Lambda$lambda$computeHashes$1$2, test, bool, Object$*)},
	{}
};
$ClassInfo ModuleHashesBuilder$$Lambda$lambda$computeHashes$1$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleHashesBuilder$$Lambda$lambda$computeHashes$1$2",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* ModuleHashesBuilder$$Lambda$lambda$computeHashes$1$2::load$($String* name, bool initialize) {
	$loadClass(ModuleHashesBuilder$$Lambda$lambda$computeHashes$1$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleHashesBuilder$$Lambda$lambda$computeHashes$1$2::class$ = nullptr;

class ModuleHashesBuilder$$Lambda$lambda$computeHashes$2$3 : public $Function {
	$class(ModuleHashesBuilder$$Lambda$lambda$computeHashes$2$3, $NO_CLASS_INIT, $Function)
public:
	void init$(ModuleHashesBuilder* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* name) override {
		 return $of($nc(inst$)->lambda$computeHashes$2($cast($String, name)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleHashesBuilder$$Lambda$lambda$computeHashes$2$3>());
	}
	ModuleHashesBuilder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModuleHashesBuilder$$Lambda$lambda$computeHashes$2$3::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ModuleHashesBuilder$$Lambda$lambda$computeHashes$2$3, inst$)},
	{}
};
$MethodInfo ModuleHashesBuilder$$Lambda$lambda$computeHashes$2$3::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/module/ModuleHashesBuilder;)V", nullptr, $PUBLIC, $method(ModuleHashesBuilder$$Lambda$lambda$computeHashes$2$3, init$, void, ModuleHashesBuilder*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModuleHashesBuilder$$Lambda$lambda$computeHashes$2$3, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ModuleHashesBuilder$$Lambda$lambda$computeHashes$2$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleHashesBuilder$$Lambda$lambda$computeHashes$2$3",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* ModuleHashesBuilder$$Lambda$lambda$computeHashes$2$3::load$($String* name, bool initialize) {
	$loadClass(ModuleHashesBuilder$$Lambda$lambda$computeHashes$2$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleHashesBuilder$$Lambda$lambda$computeHashes$2$3::class$ = nullptr;

class ModuleHashesBuilder$$Lambda$reference$4 : public $Function {
	$class(ModuleHashesBuilder$$Lambda$reference$4, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($ResolvedModule, inst$)->reference());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleHashesBuilder$$Lambda$reference$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ModuleHashesBuilder$$Lambda$reference$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModuleHashesBuilder$$Lambda$reference$4, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModuleHashesBuilder$$Lambda$reference$4, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ModuleHashesBuilder$$Lambda$reference$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleHashesBuilder$$Lambda$reference$4",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ModuleHashesBuilder$$Lambda$reference$4::load$($String* name, bool initialize) {
	$loadClass(ModuleHashesBuilder$$Lambda$reference$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleHashesBuilder$$Lambda$reference$4::class$ = nullptr;

class ModuleHashesBuilder$$Lambda$InternalError$5 : public $Supplier {
	$class(ModuleHashesBuilder$$Lambda$InternalError$5, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of($new($InternalError));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleHashesBuilder$$Lambda$InternalError$5>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ModuleHashesBuilder$$Lambda$InternalError$5::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModuleHashesBuilder$$Lambda$InternalError$5, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModuleHashesBuilder$$Lambda$InternalError$5, get, $Object*)},
	{}
};
$ClassInfo ModuleHashesBuilder$$Lambda$InternalError$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleHashesBuilder$$Lambda$InternalError$5",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* ModuleHashesBuilder$$Lambda$InternalError$5::load$($String* name, bool initialize) {
	$loadClass(ModuleHashesBuilder$$Lambda$InternalError$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleHashesBuilder$$Lambda$InternalError$5::class$ = nullptr;

$FieldInfo _ModuleHashesBuilder_FieldInfo_[] = {
	{"configuration", "Ljava/lang/module/Configuration;", nullptr, $PRIVATE | $FINAL, $field(ModuleHashesBuilder, configuration)},
	{"hashModuleCandidates", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $FINAL, $field(ModuleHashesBuilder, hashModuleCandidates)},
	{}
};

$MethodInfo _ModuleHashesBuilder_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/module/Configuration;Ljava/util/Set;)V", "(Ljava/lang/module/Configuration;Ljava/util/Set<Ljava/lang/String;>;)V", $PUBLIC, $method(ModuleHashesBuilder, init$, void, $Configuration*, $Set*)},
	{"computeHashes", "(Ljava/util/Set;)Ljava/util/Map;", "(Ljava/util/Set<Ljava/lang/String;>;)Ljava/util/Map<Ljava/lang/String;Ljdk/internal/module/ModuleHashes;>;", $PUBLIC, $virtualMethod(ModuleHashesBuilder, computeHashes, $Map*, $Set*)},
	{"lambda$computeHashes$0", "(Ljava/util/Set;Ljava/util/Set;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModuleHashesBuilder, lambda$computeHashes$0, bool, $Set*, $Set*, $String*)},
	{"lambda$computeHashes$1", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $SYNTHETIC, $method(ModuleHashesBuilder, lambda$computeHashes$1, bool, $String*, $String*)},
	{"lambda$computeHashes$2", "(Ljava/lang/String;)Ljava/lang/module/ResolvedModule;", nullptr, $PRIVATE | $SYNTHETIC, $method(ModuleHashesBuilder, lambda$computeHashes$2, $ResolvedModule*, $String*)},
	{"lambda$computeHashes$3", "(Ljdk/internal/module/ModuleHashesBuilder$Graph;Ljava/util/Set;Ljava/util/Map;Ljava/lang/String;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(ModuleHashesBuilder, lambda$computeHashes$3, void, $ModuleHashesBuilder$Graph*, $Set*, $Map*, $String*)},
	{}
};

$InnerClassInfo _ModuleHashesBuilder_InnerClassesInfo_[] = {
	{"jdk.internal.module.ModuleHashesBuilder$TopoSorter", "jdk.internal.module.ModuleHashesBuilder", "TopoSorter", $PRIVATE | $STATIC},
	{"jdk.internal.module.ModuleHashesBuilder$Graph", "jdk.internal.module.ModuleHashesBuilder", "Graph", $STATIC},
	{}
};

$ClassInfo _ModuleHashesBuilder_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.module.ModuleHashesBuilder",
	"java.lang.Object",
	nullptr,
	_ModuleHashesBuilder_FieldInfo_,
	_ModuleHashesBuilder_MethodInfo_,
	nullptr,
	nullptr,
	_ModuleHashesBuilder_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.module.ModuleHashesBuilder$TopoSorter,jdk.internal.module.ModuleHashesBuilder$Graph,jdk.internal.module.ModuleHashesBuilder$Graph$Builder"
};

$Object* allocate$ModuleHashesBuilder($Class* clazz) {
	return $of($alloc(ModuleHashesBuilder));
}

void ModuleHashesBuilder::init$($Configuration* config, $Set* modules) {
	$set(this, configuration, config);
	$set(this, hashModuleCandidates, modules);
}

$Map* ModuleHashesBuilder::computeHashes($Set* roots) {
	$useLocalCurrentObjectStackCache();
	$var($ModuleHashesBuilder$Graph$Builder, builder, $new($ModuleHashesBuilder$Graph$Builder));
	$var($Deque, todo, $new($ArrayDeque, $(static_cast<$Collection*>($nc(this->configuration)->modules()))));
	$var($Set, visited, $new($HashSet));
	$var($ResolvedModule, rm, nullptr);
	while (($assign(rm, $cast($ResolvedModule, todo->poll()))) != nullptr) {
		if (visited->add(rm)) {
			builder->addNode($($nc(rm)->name()));
			{
				$var($Iterator, i$, $nc($($nc(rm)->reads()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($ResolvedModule, dm, $cast($ResolvedModule, i$->next()));
					{
						if (!visited->contains(dm)) {
							todo->push(dm);
						}
						$var($Object, var$0, $of(rm->name()));
						builder->addEdge(var$0, $($nc(dm)->name()));
					}
				}
			}
		}
	}
	$var($ModuleHashesBuilder$Graph, transposedGraph, $nc($(builder->build()))->transpose());
	$var($Set, mods, $new($HashSet));
	$var($Map, hashes, static_cast<$Map*>(static_cast<$AbstractMap*>($new($TreeMap))));
	$nc($($nc($($nc($(builder->build()))->orderedNodes()))->filter(static_cast<$Predicate*>($$new(ModuleHashesBuilder$$Lambda$lambda$computeHashes$0, roots, mods)))))->forEach(static_cast<$Consumer*>($$new(ModuleHashesBuilder$$Lambda$lambda$computeHashes$3$1, this, transposedGraph, mods, hashes)));
	return hashes;
}

void ModuleHashesBuilder::lambda$computeHashes$3($ModuleHashesBuilder$Graph* transposedGraph, $Set* mods, $Map* hashes, $String* mn) {
	$useLocalCurrentObjectStackCache();
	$var($Set, ns, $cast($Set, $nc($($nc($($nc($($nc(transposedGraph)->dfs($of(mn))))->stream()))->filter(static_cast<$Predicate*>($$new(ModuleHashesBuilder$$Lambda$lambda$computeHashes$1$2, this, mn)))))->collect($($Collectors::toSet()))));
	$nc(mods)->add(mn);
	mods->addAll(ns);
	if (!$nc(ns)->isEmpty()) {
		$var($Set, mrefs, $cast($Set, $nc($($nc($($nc($(ns->stream()))->map(static_cast<$Function*>($$new(ModuleHashesBuilder$$Lambda$lambda$computeHashes$2$3, this)))))->map(static_cast<$Function*>($$new(ModuleHashesBuilder$$Lambda$reference$4)))))->collect($($Collectors::toSet()))));
		$nc(hashes)->put(mn, $($ModuleHashes::generate(mrefs, "SHA-256"_s)));
	}
}

$ResolvedModule* ModuleHashesBuilder::lambda$computeHashes$2($String* name) {
	$useLocalCurrentObjectStackCache();
	return $cast($ResolvedModule, $nc($($nc(this->configuration)->findModule(name)))->orElseThrow(static_cast<$Supplier*>($$new(ModuleHashesBuilder$$Lambda$InternalError$5))));
}

bool ModuleHashesBuilder::lambda$computeHashes$1($String* mn, $String* n) {
	bool var$0 = !$nc(n)->equals(mn);
	return var$0 && $nc(this->hashModuleCandidates)->contains(n);
}

bool ModuleHashesBuilder::lambda$computeHashes$0($Set* roots, $Set* mods, $String* mn) {
	bool var$0 = $nc(roots)->contains(mn);
	return var$0 && !$nc(mods)->contains(mn);
}

ModuleHashesBuilder::ModuleHashesBuilder() {
}

$Class* ModuleHashesBuilder::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ModuleHashesBuilder$$Lambda$lambda$computeHashes$0::classInfo$.name)) {
			return ModuleHashesBuilder$$Lambda$lambda$computeHashes$0::load$(name, initialize);
		}
		if (name->equals(ModuleHashesBuilder$$Lambda$lambda$computeHashes$3$1::classInfo$.name)) {
			return ModuleHashesBuilder$$Lambda$lambda$computeHashes$3$1::load$(name, initialize);
		}
		if (name->equals(ModuleHashesBuilder$$Lambda$lambda$computeHashes$1$2::classInfo$.name)) {
			return ModuleHashesBuilder$$Lambda$lambda$computeHashes$1$2::load$(name, initialize);
		}
		if (name->equals(ModuleHashesBuilder$$Lambda$lambda$computeHashes$2$3::classInfo$.name)) {
			return ModuleHashesBuilder$$Lambda$lambda$computeHashes$2$3::load$(name, initialize);
		}
		if (name->equals(ModuleHashesBuilder$$Lambda$reference$4::classInfo$.name)) {
			return ModuleHashesBuilder$$Lambda$reference$4::load$(name, initialize);
		}
		if (name->equals(ModuleHashesBuilder$$Lambda$InternalError$5::classInfo$.name)) {
			return ModuleHashesBuilder$$Lambda$InternalError$5::load$(name, initialize);
		}
	}
	$loadClass(ModuleHashesBuilder, name, initialize, &_ModuleHashesBuilder_ClassInfo_, allocate$ModuleHashesBuilder);
	return class$;
}

$Class* ModuleHashesBuilder::class$ = nullptr;

		} // module
	} // internal
} // jdk