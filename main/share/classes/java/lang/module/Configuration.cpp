#include <java/lang/module/Configuration.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/ModuleDescriptor.h>
#include <java/lang/module/ModuleFinder.h>
#include <java/lang/module/ModuleReference.h>
#include <java/lang/module/ResolvedModule.h>
#include <java/lang/module/Resolver.h>
#include <java/nio/file/Path.h>
#include <java/util/ArrayDeque.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Deque.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/misc/CDS.h>
#include <jdk/internal/module/ModuleReferenceImpl.h>
#include <jdk/internal/module/ModuleTarget.h>
#include <jcpp.h>

#undef EMPTY_CONFIGURATION

using $ResolvedModuleArray = $Array<::java::lang::module::ResolvedModule>;
using $PathArray = $Array<::java::nio::file::Path>;
using $Map$EntryArray = $Array<::java::util::Map$Entry>;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ModuleFinder = ::java::lang::module::ModuleFinder;
using $ModuleReference = ::java::lang::module::ModuleReference;
using $ResolvedModule = ::java::lang::module::ResolvedModule;
using $Resolver = ::java::lang::module::Resolver;
using $ArrayDeque = ::java::util::ArrayDeque;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Deque = ::java::util::Deque;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $Collectors = ::java::util::stream::Collectors;
using $Stream = ::java::util::stream::Stream;
using $CDS = ::jdk::internal::misc::CDS;
using $ModuleReferenceImpl = ::jdk::internal::module::ModuleReferenceImpl;
using $ModuleTarget = ::jdk::internal::module::ModuleTarget;

namespace java {
	namespace lang {
		namespace module {

class Configuration$$Lambda$lambda$findModule$0 : public $Function {
	$class(Configuration$$Lambda$lambda$findModule$0, $NO_CLASS_INIT, $Function)
public:
	void init$($String* name) {
		$set(this, name, name);
	}
	virtual $Object* apply(Object$* cf) override {
		 return $of(Configuration::lambda$findModule$0(name, $cast(Configuration, cf)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Configuration$$Lambda$lambda$findModule$0>());
	}
	$String* name = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Configuration$$Lambda$lambda$findModule$0::fieldInfos[2] = {
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(Configuration$$Lambda$lambda$findModule$0, name)},
	{}
};
$MethodInfo Configuration$$Lambda$lambda$findModule$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(Configuration$$Lambda$lambda$findModule$0, init$, void, $String*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Configuration$$Lambda$lambda$findModule$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Configuration$$Lambda$lambda$findModule$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Configuration$$Lambda$lambda$findModule$0",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Configuration$$Lambda$lambda$findModule$0::load$($String* name, bool initialize) {
	$loadClass(Configuration$$Lambda$lambda$findModule$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Configuration$$Lambda$lambda$findModule$0::class$ = nullptr;

class Configuration$$Lambda$nonNull$1 : public $Predicate {
	$class(Configuration$$Lambda$nonNull$1, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* obj) override {
		 return $Objects::nonNull(obj);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Configuration$$Lambda$nonNull$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Configuration$$Lambda$nonNull$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Configuration$$Lambda$nonNull$1, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Configuration$$Lambda$nonNull$1, test, bool, Object$*)},
	{}
};
$ClassInfo Configuration$$Lambda$nonNull$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Configuration$$Lambda$nonNull$1",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* Configuration$$Lambda$nonNull$1::load$($String* name, bool initialize) {
	$loadClass(Configuration$$Lambda$nonNull$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Configuration$$Lambda$nonNull$1::class$ = nullptr;

class Configuration$$Lambda$reference$2 : public $Function {
	$class(Configuration$$Lambda$reference$2, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($ResolvedModule, inst$)->reference());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Configuration$$Lambda$reference$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Configuration$$Lambda$reference$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Configuration$$Lambda$reference$2, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Configuration$$Lambda$reference$2, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Configuration$$Lambda$reference$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Configuration$$Lambda$reference$2",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Configuration$$Lambda$reference$2::load$($String* name, bool initialize) {
	$loadClass(Configuration$$Lambda$reference$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Configuration$$Lambda$reference$2::class$ = nullptr;

class Configuration$$Lambda$descriptor$3 : public $Function {
	$class(Configuration$$Lambda$descriptor$3, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($ModuleReference, inst$)->descriptor());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Configuration$$Lambda$descriptor$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Configuration$$Lambda$descriptor$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Configuration$$Lambda$descriptor$3, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Configuration$$Lambda$descriptor$3, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Configuration$$Lambda$descriptor$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Configuration$$Lambda$descriptor$3",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Configuration$$Lambda$descriptor$3::load$($String* name, bool initialize) {
	$loadClass(Configuration$$Lambda$descriptor$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Configuration$$Lambda$descriptor$3::class$ = nullptr;

class Configuration$$Lambda$name$4 : public $Function {
	$class(Configuration$$Lambda$name$4, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($ResolvedModule, inst$)->name());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Configuration$$Lambda$name$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Configuration$$Lambda$name$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Configuration$$Lambda$name$4, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Configuration$$Lambda$name$4, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Configuration$$Lambda$name$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Configuration$$Lambda$name$4",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Configuration$$Lambda$name$4::load$($String* name, bool initialize) {
	$loadClass(Configuration$$Lambda$name$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Configuration$$Lambda$name$4::class$ = nullptr;

$CompoundAttribute _Configuration_FieldAnnotations_EMPTY_CONFIGURATION[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$FieldInfo _Configuration_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Configuration, $assertionsDisabled)},
	{"EMPTY_CONFIGURATION", "Ljava/lang/module/Configuration;", nullptr, $PRIVATE | $STATIC, $staticField(Configuration, EMPTY_CONFIGURATION), _Configuration_FieldAnnotations_EMPTY_CONFIGURATION},
	{"parents", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/module/Configuration;>;", $PRIVATE | $FINAL, $field(Configuration, parents$)},
	{"graph", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/module/ResolvedModule;Ljava/util/Set<Ljava/lang/module/ResolvedModule;>;>;", $PRIVATE | $FINAL, $field(Configuration, graph)},
	{"modules", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/module/ResolvedModule;>;", $PRIVATE | $FINAL, $field(Configuration, modules$)},
	{"nameToModule", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/module/ResolvedModule;>;", $PRIVATE | $FINAL, $field(Configuration, nameToModule)},
	{"targetPlatform", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Configuration, targetPlatform$)},
	{"allConfigurations", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/module/Configuration;>;", $PRIVATE | $VOLATILE, $field(Configuration, allConfigurations)},
	{}
};

$MethodInfo _Configuration_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(Configuration, init$, void)},
	{"<init>", "(Ljava/util/List;Ljava/lang/module/Resolver;)V", "(Ljava/util/List<Ljava/lang/module/Configuration;>;Ljava/lang/module/Resolver;)V", $PRIVATE, $method(Configuration, init$, void, $List*, $Resolver*)},
	{"<init>", "(Ljava/lang/module/ModuleFinder;Ljava/util/Map;)V", "(Ljava/lang/module/ModuleFinder;Ljava/util/Map<Ljava/lang/String;Ljava/util/Set<Ljava/lang/String;>;>;)V", 0, $method(Configuration, init$, void, $ModuleFinder*, $Map*)},
	{"configurations", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljava/lang/module/Configuration;>;", 0, $method(Configuration, configurations, $Stream*)},
	{"descriptors", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/module/ModuleDescriptor;>;", 0, $method(Configuration, descriptors, $Set*)},
	{"empty", "()Ljava/lang/module/Configuration;", nullptr, $PUBLIC | $STATIC, $staticMethod(Configuration, empty, Configuration*)},
	{"findModule", "(Ljava/lang/String;)Ljava/util/Optional;", "(Ljava/lang/String;)Ljava/util/Optional<Ljava/lang/module/ResolvedModule;>;", $PUBLIC, $method(Configuration, findModule, $Optional*, $String*)},
	{"lambda$findModule$0", "(Ljava/lang/String;Ljava/lang/module/Configuration;)Ljava/lang/module/ResolvedModule;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Configuration, lambda$findModule$0, $ResolvedModule*, $String*, Configuration*)},
	{"modules", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/module/ResolvedModule;>;", $PUBLIC, $method(Configuration, modules, $Set*)},
	{"parents", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/module/Configuration;>;", $PUBLIC, $method(Configuration, parents, $List*)},
	{"reads", "(Ljava/lang/module/ResolvedModule;)Ljava/util/Set;", "(Ljava/lang/module/ResolvedModule;)Ljava/util/Set<Ljava/lang/module/ResolvedModule;>;", 0, $method(Configuration, reads, $Set*, $ResolvedModule*)},
	{"resolve", "(Ljava/lang/module/ModuleFinder;Ljava/lang/module/ModuleFinder;Ljava/util/Collection;)Ljava/lang/module/Configuration;", "(Ljava/lang/module/ModuleFinder;Ljava/lang/module/ModuleFinder;Ljava/util/Collection<Ljava/lang/String;>;)Ljava/lang/module/Configuration;", $PUBLIC, $method(Configuration, resolve, Configuration*, $ModuleFinder*, $ModuleFinder*, $Collection*)},
	{"resolve", "(Ljava/lang/module/ModuleFinder;Ljava/util/List;Ljava/lang/module/ModuleFinder;Ljava/util/Collection;)Ljava/lang/module/Configuration;", "(Ljava/lang/module/ModuleFinder;Ljava/util/List<Ljava/lang/module/Configuration;>;Ljava/lang/module/ModuleFinder;Ljava/util/Collection<Ljava/lang/String;>;)Ljava/lang/module/Configuration;", $PUBLIC | $STATIC, $staticMethod(Configuration, resolve, Configuration*, $ModuleFinder*, $List*, $ModuleFinder*, $Collection*)},
	{"resolveAndBind", "(Ljava/lang/module/ModuleFinder;Ljava/lang/module/ModuleFinder;Ljava/util/Collection;)Ljava/lang/module/Configuration;", "(Ljava/lang/module/ModuleFinder;Ljava/lang/module/ModuleFinder;Ljava/util/Collection<Ljava/lang/String;>;)Ljava/lang/module/Configuration;", $PUBLIC, $method(Configuration, resolveAndBind, Configuration*, $ModuleFinder*, $ModuleFinder*, $Collection*)},
	{"resolveAndBind", "(Ljava/lang/module/ModuleFinder;Ljava/util/Collection;Ljava/io/PrintStream;)Ljava/lang/module/Configuration;", "(Ljava/lang/module/ModuleFinder;Ljava/util/Collection<Ljava/lang/String;>;Ljava/io/PrintStream;)Ljava/lang/module/Configuration;", $STATIC, $staticMethod(Configuration, resolveAndBind, Configuration*, $ModuleFinder*, $Collection*, $PrintStream*)},
	{"resolveAndBind", "(Ljava/lang/module/ModuleFinder;Ljava/util/List;Ljava/lang/module/ModuleFinder;Ljava/util/Collection;)Ljava/lang/module/Configuration;", "(Ljava/lang/module/ModuleFinder;Ljava/util/List<Ljava/lang/module/Configuration;>;Ljava/lang/module/ModuleFinder;Ljava/util/Collection<Ljava/lang/String;>;)Ljava/lang/module/Configuration;", $PUBLIC | $STATIC, $staticMethod(Configuration, resolveAndBind, Configuration*, $ModuleFinder*, $List*, $ModuleFinder*, $Collection*)},
	{"targetPlatform", "()Ljava/lang/String;", nullptr, 0, $method(Configuration, targetPlatform, $String*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Configuration, toString, $String*)},
	{}
};

$ClassInfo _Configuration_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.lang.module.Configuration",
	"java.lang.Object",
	nullptr,
	_Configuration_FieldInfo_,
	_Configuration_MethodInfo_
};

$Object* allocate$Configuration($Class* clazz) {
	return $of($alloc(Configuration));
}

bool Configuration::$assertionsDisabled = false;
Configuration* Configuration::EMPTY_CONFIGURATION = nullptr;

$String* Configuration::targetPlatform() {
	return this->targetPlatform$;
}

void Configuration::init$() {
	$set(this, parents$, $List::of());
	$set(this, graph, $Map::of());
	$set(this, modules$, $Set::of());
	$set(this, nameToModule, $Map::of());
	$set(this, targetPlatform$, nullptr);
}

void Configuration::init$($List* parents, $Resolver* resolver) {
	$useLocalCurrentObjectStackCache();
	$var($Map, g, $nc(resolver)->finish(this));
	$var($Map$EntryArray, nameEntries, $new($Map$EntryArray, $nc(g)->size()));
	$var($ResolvedModuleArray, moduleArray, $new($ResolvedModuleArray, g->size()));
	int32_t i = 0;
	{
		$var($Iterator, i$, $nc($(g->keySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ResolvedModule, resolvedModule, $cast($ResolvedModule, i$->next()));
			{
				moduleArray->set(i, resolvedModule);
				nameEntries->set(i, $($Map::entry($($nc(resolvedModule)->name()), resolvedModule)));
				++i;
			}
		}
	}
	$set(this, parents$, $List::copyOf(parents));
	$set(this, graph, g);
	$set(this, modules$, $Set::of(moduleArray));
	$set(this, nameToModule, $Map::ofEntries(nameEntries));
	$set(this, targetPlatform$, resolver->targetPlatform());
}

void Configuration::init$($ModuleFinder* finder, $Map* map) {
	$useLocalCurrentObjectStackCache();
	int32_t moduleCount = $nc(map)->size();
	$var($Map$EntryArray, nameEntries, $new($Map$EntryArray, moduleCount));
	$var($ResolvedModuleArray, moduleArray, $new($ResolvedModuleArray, moduleCount));
	$var($String, targetPlatform, nullptr);
	int32_t i = 0;
	{
		$var($Iterator, i$, $nc($(map->keySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, name, $cast($String, i$->next()));
			{
				$var($ModuleReference, mref, $cast($ModuleReference, $nc($($nc(finder)->find(name)))->orElse(nullptr)));
				if (!Configuration::$assertionsDisabled && !(mref != nullptr)) {
					$throwNew($AssertionError);
				}
				if (targetPlatform == nullptr && $instanceOf($ModuleReferenceImpl, mref)) {
					$var($ModuleTarget, target, $nc(($cast($ModuleReferenceImpl, mref)))->moduleTarget());
					if (target != nullptr) {
						$assign(targetPlatform, target->targetPlatform());
					}
				}
				$var($ResolvedModule, resolvedModule, $new($ResolvedModule, this, mref));
				moduleArray->set(i, resolvedModule);
				nameEntries->set(i, $($Map::entry(name, resolvedModule)));
				++i;
			}
		}
	}
	$var($Map, nameToModule, $Map::ofEntries(nameEntries));
	$var($Map$EntryArray, moduleEntries, $new($Map$EntryArray, moduleCount));
	i = 0;
	{
		$var($ResolvedModuleArray, arr$, moduleArray);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($ResolvedModule, resolvedModule, arr$->get(i$));
			{
				$var($Set, names, $cast($Set, map->get($($nc(resolvedModule)->name()))));
				$var($ResolvedModuleArray, readsArray, $new($ResolvedModuleArray, $nc(names)->size()));
				int32_t j = 0;
				{
					$var($Iterator, i$, names->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($String, name, $cast($String, i$->next()));
						{
							readsArray->set(j++, $cast($ResolvedModule, $($nc(nameToModule)->get(name))));
						}
					}
				}
				moduleEntries->set(i++, $($Map::entry(resolvedModule, $($Set::of(readsArray)))));
			}
		}
	}
	$set(this, parents$, $List::of($($of(empty()))));
	$set(this, graph, $Map::ofEntries(moduleEntries));
	$set(this, modules$, $Set::of(moduleArray));
	$set(this, nameToModule, nameToModule);
	$set(this, targetPlatform$, targetPlatform);
}

Configuration* Configuration::resolve($ModuleFinder* before, $ModuleFinder* after, $Collection* roots) {
	return resolve(before, $($List::of($of(this))), after, roots);
}

Configuration* Configuration::resolveAndBind($ModuleFinder* before, $ModuleFinder* after, $Collection* roots) {
	return resolveAndBind(before, $($List::of($of(this))), after, roots);
}

Configuration* Configuration::resolveAndBind($ModuleFinder* finder, $Collection* roots, $PrintStream* traceOutput) {
	$init(Configuration);
	$useLocalCurrentObjectStackCache();
	$var($List, parents, $List::of($($of(empty()))));
	$var($Resolver, resolver, $new($Resolver, finder, parents, $($ModuleFinder::of($$new($PathArray, 0))), traceOutput));
	$nc($(resolver->resolve(roots)))->bind(false);
	return $new(Configuration, parents, resolver);
}

Configuration* Configuration::resolve($ModuleFinder* before, $List* parents, $ModuleFinder* after, $Collection* roots) {
	$init(Configuration);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(before);
	$Objects::requireNonNull(after);
	$Objects::requireNonNull(roots);
	$var($List, parentList, $new($ArrayList, static_cast<$Collection*>(parents)));
	if (parentList->isEmpty()) {
		$throwNew($IllegalArgumentException, "\'parents\' is empty"_s);
	}
	$var($Resolver, resolver, $new($Resolver, before, parentList, after, nullptr));
	resolver->resolve(roots);
	return $new(Configuration, parentList, resolver);
}

Configuration* Configuration::resolveAndBind($ModuleFinder* before, $List* parents, $ModuleFinder* after, $Collection* roots) {
	$init(Configuration);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(before);
	$Objects::requireNonNull(after);
	$Objects::requireNonNull(roots);
	$var($List, parentList, $new($ArrayList, static_cast<$Collection*>(parents)));
	if (parentList->isEmpty()) {
		$throwNew($IllegalArgumentException, "\'parents\' is empty"_s);
	}
	$var($Resolver, resolver, $new($Resolver, before, parentList, after, nullptr));
	$nc($(resolver->resolve(roots)))->bind();
	return $new(Configuration, parentList, resolver);
}

Configuration* Configuration::empty() {
	$init(Configuration);
	return Configuration::EMPTY_CONFIGURATION;
}

$List* Configuration::parents() {
	return this->parents$;
}

$Set* Configuration::modules() {
	return this->modules$;
}

$Optional* Configuration::findModule($String* name) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(name);
	$var($ResolvedModule, m, $cast($ResolvedModule, $nc(this->nameToModule)->get(name)));
	if (m != nullptr) {
		return $Optional::of(m);
	}
	if (!$nc(this->parents$)->isEmpty()) {
		return $nc($($nc($($nc($($nc($(configurations()))->skip(1)))->map(static_cast<$Function*>($$new(Configuration$$Lambda$lambda$findModule$0, name)))))->filter(static_cast<$Predicate*>($$new(Configuration$$Lambda$nonNull$1)))))->findFirst();
	}
	return $Optional::empty();
}

$Set* Configuration::descriptors() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->modules$)->isEmpty()) {
		return $Set::of();
	} else {
		return $cast($Set, $nc($($nc($($nc($($nc(this->modules$)->stream()))->map(static_cast<$Function*>($$new(Configuration$$Lambda$reference$2)))))->map(static_cast<$Function*>($$new(Configuration$$Lambda$descriptor$3)))))->collect($($Collectors::toSet())));
	}
}

$Set* Configuration::reads($ResolvedModule* m) {
	return $Set::copyOf($cast($Collection, $($nc(this->graph)->get(m))));
}

$Stream* Configuration::configurations() {
	$useLocalCurrentObjectStackCache();
	$var($List, allConfigurations, this->allConfigurations);
	if (allConfigurations == nullptr) {
		$assign(allConfigurations, $new($ArrayList));
		$var($Set, visited, $new($HashSet));
		$var($Deque, stack, $new($ArrayDeque));
		visited->add(this);
		stack->push(this);
		while (!stack->isEmpty()) {
			$var(Configuration, layer, $cast(Configuration, stack->pop()));
			allConfigurations->add(layer);
			for (int32_t i = $nc($nc(layer)->parents$)->size() - 1; i >= 0; --i) {
				$var(Configuration, parent, $cast(Configuration, $nc(layer->parents$)->get(i)));
				if (visited->add(parent)) {
					stack->push(parent);
				}
			}
		}
		$set(this, allConfigurations, allConfigurations);
	}
	return $nc(allConfigurations)->stream();
}

$String* Configuration::toString() {
	$useLocalCurrentObjectStackCache();
	return $cast($String, $nc($($nc($($nc($(modules()))->stream()))->map(static_cast<$Function*>($$new(Configuration$$Lambda$name$4)))))->collect($($Collectors::joining(", "_s))));
}

$ResolvedModule* Configuration::lambda$findModule$0($String* name, Configuration* cf) {
	$init(Configuration);
	return $cast($ResolvedModule, $nc($nc(cf)->nameToModule)->get(name));
}

void clinit$Configuration($Class* class$) {
	Configuration::$assertionsDisabled = !Configuration::class$->desiredAssertionStatus();
	{
		$CDS::initializeFromArchive(Configuration::class$);
		if (Configuration::EMPTY_CONFIGURATION == nullptr) {
			$assignStatic(Configuration::EMPTY_CONFIGURATION, $new(Configuration));
		}
	}
}

Configuration::Configuration() {
}

$Class* Configuration::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Configuration$$Lambda$lambda$findModule$0::classInfo$.name)) {
			return Configuration$$Lambda$lambda$findModule$0::load$(name, initialize);
		}
		if (name->equals(Configuration$$Lambda$nonNull$1::classInfo$.name)) {
			return Configuration$$Lambda$nonNull$1::load$(name, initialize);
		}
		if (name->equals(Configuration$$Lambda$reference$2::classInfo$.name)) {
			return Configuration$$Lambda$reference$2::load$(name, initialize);
		}
		if (name->equals(Configuration$$Lambda$descriptor$3::classInfo$.name)) {
			return Configuration$$Lambda$descriptor$3::load$(name, initialize);
		}
		if (name->equals(Configuration$$Lambda$name$4::classInfo$.name)) {
			return Configuration$$Lambda$name$4::load$(name, initialize);
		}
	}
	$loadClass(Configuration, name, initialize, &_Configuration_ClassInfo_, clinit$Configuration, allocate$Configuration);
	return class$;
}

$Class* Configuration::class$ = nullptr;

		} // module
	} // lang
} // java