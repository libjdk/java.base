#include <jdk/internal/module/ModuleHashesBuilder$TopoSorter.h>

#include <java/io/Serializable.h>
#include <java/lang/Iterable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/ArrayDeque.h>
#include <java/util/Deque.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/function/Consumer.h>
#include <jdk/internal/module/ModuleHashesBuilder$Graph.h>
#include <jdk/internal/module/ModuleHashesBuilder.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ArrayDeque = ::java::util::ArrayDeque;
using $Deque = ::java::util::Deque;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $Consumer = ::java::util::function::Consumer;
using $ModuleHashesBuilder$Graph = ::jdk::internal::module::ModuleHashesBuilder$Graph;

namespace jdk {
	namespace internal {
		namespace module {

class ModuleHashesBuilder$TopoSorter$$Lambda$lambda$sort$0 : public $Consumer {
	$class(ModuleHashesBuilder$TopoSorter$$Lambda$lambda$sort$0, $NO_CLASS_INIT, $Consumer)
public:
	void init$(ModuleHashesBuilder$TopoSorter* inst, $Set* visited, $Deque* stack) {
		$set(this, inst$, inst);
		$set(this, visited, visited);
		$set(this, stack, stack);
	}
	virtual void accept(Object$* node) override {
		$nc(inst$)->lambda$sort$0(visited, stack, node);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleHashesBuilder$TopoSorter$$Lambda$lambda$sort$0>());
	}
	ModuleHashesBuilder$TopoSorter* inst$ = nullptr;
	$Set* visited = nullptr;
	$Deque* stack = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModuleHashesBuilder$TopoSorter$$Lambda$lambda$sort$0::fieldInfos[4] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ModuleHashesBuilder$TopoSorter$$Lambda$lambda$sort$0, inst$)},
	{"visited", "Ljava/util/Set;", nullptr, $PUBLIC, $field(ModuleHashesBuilder$TopoSorter$$Lambda$lambda$sort$0, visited)},
	{"stack", "Ljava/util/Deque;", nullptr, $PUBLIC, $field(ModuleHashesBuilder$TopoSorter$$Lambda$lambda$sort$0, stack)},
	{}
};
$MethodInfo ModuleHashesBuilder$TopoSorter$$Lambda$lambda$sort$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/module/ModuleHashesBuilder$TopoSorter;Ljava/util/Set;Ljava/util/Deque;)V", nullptr, $PUBLIC, $method(ModuleHashesBuilder$TopoSorter$$Lambda$lambda$sort$0, init$, void, ModuleHashesBuilder$TopoSorter*, $Set*, $Deque*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ModuleHashesBuilder$TopoSorter$$Lambda$lambda$sort$0, accept, void, Object$*)},
	{}
};
$ClassInfo ModuleHashesBuilder$TopoSorter$$Lambda$lambda$sort$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleHashesBuilder$TopoSorter$$Lambda$lambda$sort$0",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ModuleHashesBuilder$TopoSorter$$Lambda$lambda$sort$0::load$($String* name, bool initialize) {
	$loadClass(ModuleHashesBuilder$TopoSorter$$Lambda$lambda$sort$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleHashesBuilder$TopoSorter$$Lambda$lambda$sort$0::class$ = nullptr;

$FieldInfo _ModuleHashesBuilder$TopoSorter_FieldInfo_[] = {
	{"result", "Ljava/util/Deque;", "Ljava/util/Deque<TT;>;", $FINAL, $field(ModuleHashesBuilder$TopoSorter, result)},
	{"graph", "Ljdk/internal/module/ModuleHashesBuilder$Graph;", "Ljdk/internal/module/ModuleHashesBuilder$Graph<TT;>;", $FINAL, $field(ModuleHashesBuilder$TopoSorter, graph)},
	{}
};

$MethodInfo _ModuleHashesBuilder$TopoSorter_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/module/ModuleHashesBuilder$Graph;)V", "(Ljdk/internal/module/ModuleHashesBuilder$Graph<TT;>;)V", 0, $method(ModuleHashesBuilder$TopoSorter, init$, void, $ModuleHashesBuilder$Graph*)},
	{"children", "(Ljava/lang/Object;)Ljava/util/Set;", "(TT;)Ljava/util/Set<TT;>;", $PRIVATE, $method(ModuleHashesBuilder$TopoSorter, children, $Set*, Object$*)},
	{"lambda$sort$0", "(Ljava/util/Set;Ljava/util/Deque;Ljava/lang/Object;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(ModuleHashesBuilder$TopoSorter, lambda$sort$0, void, $Set*, $Deque*, Object$*)},
	{"ordered", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<TT;>;)V", $PUBLIC, $virtualMethod(ModuleHashesBuilder$TopoSorter, ordered, void, $Consumer*)},
	{"reverse", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<TT;>;)V", $PUBLIC, $virtualMethod(ModuleHashesBuilder$TopoSorter, reverse, void, $Consumer*)},
	{"sort", "()V", nullptr, $PRIVATE, $method(ModuleHashesBuilder$TopoSorter, sort, void)},
	{"visit", "(Ljava/lang/Object;Ljava/util/Set;Ljava/util/Deque;)V", "(TT;Ljava/util/Set<TT;>;Ljava/util/Deque<TT;>;)V", $PRIVATE, $method(ModuleHashesBuilder$TopoSorter, visit, void, Object$*, $Set*, $Deque*)},
	{}
};

$InnerClassInfo _ModuleHashesBuilder$TopoSorter_InnerClassesInfo_[] = {
	{"jdk.internal.module.ModuleHashesBuilder$TopoSorter", "jdk.internal.module.ModuleHashesBuilder", "TopoSorter", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _ModuleHashesBuilder$TopoSorter_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.module.ModuleHashesBuilder$TopoSorter",
	"java.lang.Object",
	nullptr,
	_ModuleHashesBuilder$TopoSorter_FieldInfo_,
	_ModuleHashesBuilder$TopoSorter_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;",
	nullptr,
	_ModuleHashesBuilder$TopoSorter_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.module.ModuleHashesBuilder"
};

$Object* allocate$ModuleHashesBuilder$TopoSorter($Class* clazz) {
	return $of($alloc(ModuleHashesBuilder$TopoSorter));
}

void ModuleHashesBuilder$TopoSorter::init$($ModuleHashesBuilder$Graph* graph) {
	$set(this, result, $new($ArrayDeque));
	$set(this, graph, graph);
	sort();
}

void ModuleHashesBuilder$TopoSorter::ordered($Consumer* action) {
	$nc(this->result)->forEach(action);
}

void ModuleHashesBuilder$TopoSorter::reverse($Consumer* action) {
	$nc($($nc(this->result)->descendingIterator()))->forEachRemaining(action);
}

void ModuleHashesBuilder$TopoSorter::sort() {
	$useLocalCurrentObjectStackCache();
	$var($Set, visited, $new($HashSet));
	$var($Deque, stack, $new($ArrayDeque));
	$nc($nc(this->graph)->nodes$)->forEach(static_cast<$Consumer*>($$new(ModuleHashesBuilder$TopoSorter$$Lambda$lambda$sort$0, this, visited, stack)));
}

$Set* ModuleHashesBuilder$TopoSorter::children(Object$* node) {
	return $cast($Set, $nc($($nc(this->graph)->edges()))->get(node));
}

void ModuleHashesBuilder$TopoSorter::visit(Object$* node, $Set* visited, $Deque* stack) {
	$useLocalCurrentObjectStackCache();
	if ($nc(visited)->add(node)) {
		$nc(stack)->push(node);
		$nc($(children(node)))->forEach(static_cast<$Consumer*>($$new(ModuleHashesBuilder$TopoSorter$$Lambda$lambda$sort$0, this, visited, stack)));
		stack->pop();
		$nc(this->result)->addLast(node);
	} else if ($nc(stack)->contains(node)) {
		$var($String, var$0, $$str({"Cycle detected: "_s, node, " -> "_s}));
		$throwNew($IllegalArgumentException, $$concat(var$0, $(children(node))));
	}
}

void ModuleHashesBuilder$TopoSorter::lambda$sort$0($Set* visited, $Deque* stack, Object$* node) {
	visit(node, visited, stack);
}

ModuleHashesBuilder$TopoSorter::ModuleHashesBuilder$TopoSorter() {
}

$Class* ModuleHashesBuilder$TopoSorter::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ModuleHashesBuilder$TopoSorter$$Lambda$lambda$sort$0::classInfo$.name)) {
			return ModuleHashesBuilder$TopoSorter$$Lambda$lambda$sort$0::load$(name, initialize);
		}
	}
	$loadClass(ModuleHashesBuilder$TopoSorter, name, initialize, &_ModuleHashesBuilder$TopoSorter_ClassInfo_, allocate$ModuleHashesBuilder$TopoSorter);
	return class$;
}

$Class* ModuleHashesBuilder$TopoSorter::class$ = nullptr;

		} // module
	} // internal
} // jdk