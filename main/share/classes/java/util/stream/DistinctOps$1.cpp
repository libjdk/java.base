#include <java/util/stream/DistinctOps$1.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/AbstractCollection.h>
#include <java/util/Collection.h>
#include <java/util/HashSet.h>
#include <java/util/LinkedHashSet.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/Spliterator.h>
#include <java/util/concurrent/ConcurrentHashMap$KeySetView.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/DistinctOps$1$1.h>
#include <java/util/stream/DistinctOps$1$2.h>
#include <java/util/stream/DistinctOps.h>
#include <java/util/stream/ForEachOps.h>
#include <java/util/stream/Node.h>
#include <java/util/stream/Nodes.h>
#include <java/util/stream/PipelineHelper.h>
#include <java/util/stream/ReduceOps.h>
#include <java/util/stream/ReferencePipeline$StatefulOp.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamOpFlag.h>
#include <java/util/stream/StreamShape.h>
#include <java/util/stream/StreamSpliterators$DistinctSpliterator.h>
#include <java/util/stream/TerminalOp.h>
#include <jcpp.h>

#undef DISTINCT
#undef ORDERED
#undef SORTED
#undef TRUE

using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AbstractCollection = ::java::util::AbstractCollection;
using $Collection = ::java::util::Collection;
using $HashSet = ::java::util::HashSet;
using $LinkedHashSet = ::java::util::LinkedHashSet;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $Spliterator = ::java::util::Spliterator;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $BiConsumer = ::java::util::function::BiConsumer;
using $Consumer = ::java::util::function::Consumer;
using $IntFunction = ::java::util::function::IntFunction;
using $Supplier = ::java::util::function::Supplier;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $DistinctOps$1$1 = ::java::util::stream::DistinctOps$1$1;
using $DistinctOps$1$2 = ::java::util::stream::DistinctOps$1$2;
using $ForEachOps = ::java::util::stream::ForEachOps;
using $Node = ::java::util::stream::Node;
using $Nodes = ::java::util::stream::Nodes;
using $PipelineHelper = ::java::util::stream::PipelineHelper;
using $ReduceOps = ::java::util::stream::ReduceOps;
using $ReferencePipeline$StatefulOp = ::java::util::stream::ReferencePipeline$StatefulOp;
using $Sink = ::java::util::stream::Sink;
using $StreamOpFlag = ::java::util::stream::StreamOpFlag;
using $StreamShape = ::java::util::stream::StreamShape;
using $StreamSpliterators$DistinctSpliterator = ::java::util::stream::StreamSpliterators$DistinctSpliterator;
using $TerminalOp = ::java::util::stream::TerminalOp;

namespace java {
	namespace util {
		namespace stream {

class DistinctOps$1$$Lambda$LinkedHashSet : public $Supplier {
	$class(DistinctOps$1$$Lambda$LinkedHashSet, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of($new($LinkedHashSet));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DistinctOps$1$$Lambda$LinkedHashSet>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DistinctOps$1$$Lambda$LinkedHashSet::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DistinctOps$1$$Lambda$LinkedHashSet, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DistinctOps$1$$Lambda$LinkedHashSet, get, $Object*)},
	{}
};
$ClassInfo DistinctOps$1$$Lambda$LinkedHashSet::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DistinctOps$1$$Lambda$LinkedHashSet",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* DistinctOps$1$$Lambda$LinkedHashSet::load$($String* name, bool initialize) {
	$loadClass(DistinctOps$1$$Lambda$LinkedHashSet, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DistinctOps$1$$Lambda$LinkedHashSet::class$ = nullptr;

class DistinctOps$1$$Lambda$add$1 : public $BiConsumer {
	$class(DistinctOps$1$$Lambda$add$1, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* inst$, Object$* e) override {
		$sure($HashSet, inst$)->add(e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DistinctOps$1$$Lambda$add$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DistinctOps$1$$Lambda$add$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DistinctOps$1$$Lambda$add$1, init$, void)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(DistinctOps$1$$Lambda$add$1, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo DistinctOps$1$$Lambda$add$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DistinctOps$1$$Lambda$add$1",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	nullptr,
	methodInfos
};
$Class* DistinctOps$1$$Lambda$add$1::load$($String* name, bool initialize) {
	$loadClass(DistinctOps$1$$Lambda$add$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DistinctOps$1$$Lambda$add$1::class$ = nullptr;

class DistinctOps$1$$Lambda$addAll$2 : public $BiConsumer {
	$class(DistinctOps$1$$Lambda$addAll$2, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* inst$, Object$* c) override {
		$sure($AbstractCollection, inst$)->addAll($cast($Collection, c));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DistinctOps$1$$Lambda$addAll$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DistinctOps$1$$Lambda$addAll$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DistinctOps$1$$Lambda$addAll$2, init$, void)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(DistinctOps$1$$Lambda$addAll$2, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo DistinctOps$1$$Lambda$addAll$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DistinctOps$1$$Lambda$addAll$2",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	nullptr,
	methodInfos
};
$Class* DistinctOps$1$$Lambda$addAll$2::load$($String* name, bool initialize) {
	$loadClass(DistinctOps$1$$Lambda$addAll$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DistinctOps$1$$Lambda$addAll$2::class$ = nullptr;

class DistinctOps$1$$Lambda$lambda$opEvaluateParallel$0$3 : public $Consumer {
	$class(DistinctOps$1$$Lambda$lambda$opEvaluateParallel$0$3, $NO_CLASS_INIT, $Consumer)
public:
	void init$($AtomicBoolean* seenNull, $ConcurrentHashMap* map) {
		$set(this, seenNull, seenNull);
		$set(this, map, map);
	}
	virtual void accept(Object$* t) override {
		DistinctOps$1::lambda$opEvaluateParallel$0(seenNull, map, t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DistinctOps$1$$Lambda$lambda$opEvaluateParallel$0$3>());
	}
	$AtomicBoolean* seenNull = nullptr;
	$ConcurrentHashMap* map = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo DistinctOps$1$$Lambda$lambda$opEvaluateParallel$0$3::fieldInfos[3] = {
	{"seenNull", "Ljava/util/concurrent/atomic/AtomicBoolean;", nullptr, $PUBLIC, $field(DistinctOps$1$$Lambda$lambda$opEvaluateParallel$0$3, seenNull)},
	{"map", "Ljava/util/concurrent/ConcurrentHashMap;", nullptr, $PUBLIC, $field(DistinctOps$1$$Lambda$lambda$opEvaluateParallel$0$3, map)},
	{}
};
$MethodInfo DistinctOps$1$$Lambda$lambda$opEvaluateParallel$0$3::methodInfos[3] = {
	{"<init>", "(Ljava/util/concurrent/atomic/AtomicBoolean;Ljava/util/concurrent/ConcurrentHashMap;)V", nullptr, $PUBLIC, $method(DistinctOps$1$$Lambda$lambda$opEvaluateParallel$0$3, init$, void, $AtomicBoolean*, $ConcurrentHashMap*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(DistinctOps$1$$Lambda$lambda$opEvaluateParallel$0$3, accept, void, Object$*)},
	{}
};
$ClassInfo DistinctOps$1$$Lambda$lambda$opEvaluateParallel$0$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DistinctOps$1$$Lambda$lambda$opEvaluateParallel$0$3",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* DistinctOps$1$$Lambda$lambda$opEvaluateParallel$0$3::load$($String* name, bool initialize) {
	$loadClass(DistinctOps$1$$Lambda$lambda$opEvaluateParallel$0$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DistinctOps$1$$Lambda$lambda$opEvaluateParallel$0$3::class$ = nullptr;

$MethodInfo _DistinctOps$1_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;I)V", nullptr, 0, $method(DistinctOps$1, init$, void, $AbstractPipeline*, $StreamShape*, int32_t)},
	{"lambda$opEvaluateParallel$0", "(Ljava/util/concurrent/atomic/AtomicBoolean;Ljava/util/concurrent/ConcurrentHashMap;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DistinctOps$1, lambda$opEvaluateParallel$0, void, $AtomicBoolean*, $ConcurrentHashMap*, Object$*)},
	{"opEvaluateParallel", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;Ljava/util/function/IntFunction;)Ljava/util/stream/Node;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<TT;>;Ljava/util/Spliterator<TP_IN;>;Ljava/util/function/IntFunction<[TT;>;)Ljava/util/stream/Node<TT;>;", 0, $virtualMethod(DistinctOps$1, opEvaluateParallel, $Node*, $PipelineHelper*, $Spliterator*, $IntFunction*)},
	{"opEvaluateParallelLazy", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;)Ljava/util/Spliterator;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<TT;>;Ljava/util/Spliterator<TP_IN;>;)Ljava/util/Spliterator<TT;>;", 0, $virtualMethod(DistinctOps$1, opEvaluateParallelLazy, $Spliterator*, $PipelineHelper*, $Spliterator*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<TT;>;)Ljava/util/stream/Sink<TT;>;", 0, $virtualMethod(DistinctOps$1, opWrapSink, $Sink*, int32_t, $Sink*)},
	{"reduce", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;)Ljava/util/stream/Node;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<TT;>;Ljava/util/Spliterator<TP_IN;>;)Ljava/util/stream/Node<TT;>;", 0, $virtualMethod(DistinctOps$1, reduce, $Node*, $PipelineHelper*, $Spliterator*)},
	{}
};

$EnclosingMethodInfo _DistinctOps$1_EnclosingMethodInfo_ = {
	"java.util.stream.DistinctOps",
	"makeRef",
	"(Ljava/util/stream/AbstractPipeline;)Ljava/util/stream/ReferencePipeline;"
};

$InnerClassInfo _DistinctOps$1_InnerClassesInfo_[] = {
	{"java.util.stream.DistinctOps$1", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$StatefulOp", "java.util.stream.ReferencePipeline", "StatefulOp", $STATIC | $ABSTRACT},
	{"java.util.stream.DistinctOps$1$2", nullptr, nullptr, 0},
	{"java.util.stream.DistinctOps$1$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DistinctOps$1_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.DistinctOps$1",
	"java.util.stream.ReferencePipeline$StatefulOp",
	nullptr,
	nullptr,
	_DistinctOps$1_MethodInfo_,
	"Ljava/util/stream/ReferencePipeline$StatefulOp<TT;TT;>;",
	&_DistinctOps$1_EnclosingMethodInfo_,
	_DistinctOps$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.DistinctOps"
};

$Object* allocate$DistinctOps$1($Class* clazz) {
	return $of($alloc(DistinctOps$1));
}

void DistinctOps$1::init$($AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags) {
	$ReferencePipeline$StatefulOp::init$(upstream, inputShape, opFlags);
}

$Node* DistinctOps$1::reduce($PipelineHelper* helper, $Spliterator* spliterator) {
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(DistinctOps$1$$Lambda$LinkedHashSet)));
	$var($BiConsumer, var$1, static_cast<$BiConsumer*>($new(DistinctOps$1$$Lambda$add$1)));
	$var($TerminalOp, reduceOp, $ReduceOps::makeRef(var$0, var$1, static_cast<$BiConsumer*>($$new(DistinctOps$1$$Lambda$addAll$2))));
	return $Nodes::node($cast($Collection, $($nc(reduceOp)->evaluateParallel(helper, spliterator))));
}

$Node* DistinctOps$1::opEvaluateParallel($PipelineHelper* helper, $Spliterator* spliterator, $IntFunction* generator) {
	$useLocalCurrentObjectStackCache();
	$init($StreamOpFlag);
	if ($StreamOpFlag::DISTINCT->isKnown($nc(helper)->getStreamAndOpFlags())) {
		return $nc(helper)->evaluate(spliterator, false, generator);
	} else {
		if ($StreamOpFlag::ORDERED->isKnown($nc(helper)->getStreamAndOpFlags())) {
			return reduce(helper, spliterator);
		} else {
			$var($AtomicBoolean, seenNull, $new($AtomicBoolean, false));
			$var($ConcurrentHashMap, map, $new($ConcurrentHashMap));
			$var($TerminalOp, forEachOp, $ForEachOps::makeRef(static_cast<$Consumer*>($$new(DistinctOps$1$$Lambda$lambda$opEvaluateParallel$0$3, seenNull, map)), false));
			$nc(forEachOp)->evaluateParallel(helper, spliterator);
			$var($Set, keys, map->keySet());
			if (seenNull->get()) {
				$assign(keys, $new($HashSet, static_cast<$Collection*>(keys)));
				keys->add(nullptr);
			}
			return $Nodes::node(static_cast<$Collection*>(keys));
		}
	}
}

$Spliterator* DistinctOps$1::opEvaluateParallelLazy($PipelineHelper* helper, $Spliterator* spliterator) {
	$useLocalCurrentObjectStackCache();
	$init($StreamOpFlag);
	if ($StreamOpFlag::DISTINCT->isKnown($nc(helper)->getStreamAndOpFlags())) {
		return $nc(helper)->wrapSpliterator(spliterator);
	} else {
		if ($StreamOpFlag::ORDERED->isKnown($nc(helper)->getStreamAndOpFlags())) {
			return $nc($(reduce(helper, spliterator)))->spliterator();
		} else {
			return $new($StreamSpliterators$DistinctSpliterator, $($nc(helper)->wrapSpliterator(spliterator)));
		}
	}
}

$Sink* DistinctOps$1::opWrapSink(int32_t flags, $Sink* sink) {
	$Objects::requireNonNull(sink);
	$init($StreamOpFlag);
	if ($StreamOpFlag::DISTINCT->isKnown(flags)) {
		return sink;
	} else {
		if ($StreamOpFlag::SORTED->isKnown(flags)) {
			return $new($DistinctOps$1$1, this, sink);
		} else {
			return $new($DistinctOps$1$2, this, sink);
		}
	}
}

void DistinctOps$1::lambda$opEvaluateParallel$0($AtomicBoolean* seenNull, $ConcurrentHashMap* map, Object$* t) {
	$init(DistinctOps$1);
	if (t == nullptr) {
		$nc(seenNull)->set(true);
	} else {
		$init($Boolean);
		$nc(map)->putIfAbsent(t, $Boolean::TRUE);
	}
}

DistinctOps$1::DistinctOps$1() {
}

$Class* DistinctOps$1::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DistinctOps$1$$Lambda$LinkedHashSet::classInfo$.name)) {
			return DistinctOps$1$$Lambda$LinkedHashSet::load$(name, initialize);
		}
		if (name->equals(DistinctOps$1$$Lambda$add$1::classInfo$.name)) {
			return DistinctOps$1$$Lambda$add$1::load$(name, initialize);
		}
		if (name->equals(DistinctOps$1$$Lambda$addAll$2::classInfo$.name)) {
			return DistinctOps$1$$Lambda$addAll$2::load$(name, initialize);
		}
		if (name->equals(DistinctOps$1$$Lambda$lambda$opEvaluateParallel$0$3::classInfo$.name)) {
			return DistinctOps$1$$Lambda$lambda$opEvaluateParallel$0$3::load$(name, initialize);
		}
	}
	$loadClass(DistinctOps$1, name, initialize, &_DistinctOps$1_ClassInfo_, allocate$DistinctOps$1);
	return class$;
}

$Class* DistinctOps$1::class$ = nullptr;

		} // stream
	} // util
} // java