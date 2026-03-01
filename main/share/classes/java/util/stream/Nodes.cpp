#include <java/util/stream/Nodes.h>

#include <java/io/Serializable.h>
#include <java/lang/Error.h>
#include <java/lang/IncompatibleClassChangeError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Collection.h>
#include <java/util/Spliterator.h>
#include <java/util/concurrent/ForkJoinTask.h>
#include <java/util/function/IntFunction.h>
#include <java/util/stream/Node$Builder$OfDouble.h>
#include <java/util/stream/Node$Builder$OfInt.h>
#include <java/util/stream/Node$Builder$OfLong.h>
#include <java/util/stream/Node$Builder.h>
#include <java/util/stream/Node$OfDouble.h>
#include <java/util/stream/Node$OfInt.h>
#include <java/util/stream/Node$OfLong.h>
#include <java/util/stream/Node.h>
#include <java/util/stream/Nodes$1.h>
#include <java/util/stream/Nodes$AbstractConcNode.h>
#include <java/util/stream/Nodes$ArrayNode.h>
#include <java/util/stream/Nodes$CollectionNode.h>
#include <java/util/stream/Nodes$CollectorTask$OfDouble.h>
#include <java/util/stream/Nodes$CollectorTask$OfInt.h>
#include <java/util/stream/Nodes$CollectorTask$OfLong.h>
#include <java/util/stream/Nodes$CollectorTask$OfRef.h>
#include <java/util/stream/Nodes$ConcNode$OfDouble.h>
#include <java/util/stream/Nodes$ConcNode$OfInt.h>
#include <java/util/stream/Nodes$ConcNode$OfLong.h>
#include <java/util/stream/Nodes$ConcNode.h>
#include <java/util/stream/Nodes$DoubleArrayNode.h>
#include <java/util/stream/Nodes$DoubleFixedNodeBuilder.h>
#include <java/util/stream/Nodes$DoubleSpinedNodeBuilder.h>
#include <java/util/stream/Nodes$EmptyNode$OfDouble.h>
#include <java/util/stream/Nodes$EmptyNode$OfInt.h>
#include <java/util/stream/Nodes$EmptyNode$OfLong.h>
#include <java/util/stream/Nodes$EmptyNode$OfRef.h>
#include <java/util/stream/Nodes$FixedNodeBuilder.h>
#include <java/util/stream/Nodes$IntArrayNode.h>
#include <java/util/stream/Nodes$IntFixedNodeBuilder.h>
#include <java/util/stream/Nodes$IntSpinedNodeBuilder.h>
#include <java/util/stream/Nodes$LongArrayNode.h>
#include <java/util/stream/Nodes$LongFixedNodeBuilder.h>
#include <java/util/stream/Nodes$LongSpinedNodeBuilder.h>
#include <java/util/stream/Nodes$SizedCollectorTask$OfDouble.h>
#include <java/util/stream/Nodes$SizedCollectorTask$OfInt.h>
#include <java/util/stream/Nodes$SizedCollectorTask$OfLong.h>
#include <java/util/stream/Nodes$SizedCollectorTask$OfRef.h>
#include <java/util/stream/Nodes$SpinedNodeBuilder.h>
#include <java/util/stream/Nodes$ToArrayTask$OfDouble.h>
#include <java/util/stream/Nodes$ToArrayTask$OfInt.h>
#include <java/util/stream/Nodes$ToArrayTask$OfLong.h>
#include <java/util/stream/Nodes$ToArrayTask$OfRef.h>
#include <java/util/stream/PipelineHelper.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

#undef BAD_SIZE
#undef EMPTY_DOUBLE_ARRAY
#undef EMPTY_DOUBLE_NODE
#undef EMPTY_INT_ARRAY
#undef EMPTY_INT_NODE
#undef EMPTY_LONG_ARRAY
#undef EMPTY_LONG_NODE
#undef EMPTY_NODE
#undef MAX_ARRAY_SIZE
#undef SUBSIZED

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IncompatibleClassChangeError = ::java::lang::IncompatibleClassChangeError;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Collection = ::java::util::Collection;
using $Spliterator = ::java::util::Spliterator;
using $IntFunction = ::java::util::function::IntFunction;
using $Node = ::java::util::stream::Node;
using $Node$Builder = ::java::util::stream::Node$Builder;
using $Node$Builder$OfDouble = ::java::util::stream::Node$Builder$OfDouble;
using $Node$Builder$OfInt = ::java::util::stream::Node$Builder$OfInt;
using $Node$Builder$OfLong = ::java::util::stream::Node$Builder$OfLong;
using $Node$OfDouble = ::java::util::stream::Node$OfDouble;
using $Node$OfInt = ::java::util::stream::Node$OfInt;
using $Node$OfLong = ::java::util::stream::Node$OfLong;
using $Nodes$1 = ::java::util::stream::Nodes$1;
using $Nodes$AbstractConcNode = ::java::util::stream::Nodes$AbstractConcNode;
using $Nodes$ArrayNode = ::java::util::stream::Nodes$ArrayNode;
using $Nodes$CollectionNode = ::java::util::stream::Nodes$CollectionNode;
using $Nodes$CollectorTask$OfDouble = ::java::util::stream::Nodes$CollectorTask$OfDouble;
using $Nodes$CollectorTask$OfInt = ::java::util::stream::Nodes$CollectorTask$OfInt;
using $Nodes$CollectorTask$OfLong = ::java::util::stream::Nodes$CollectorTask$OfLong;
using $Nodes$CollectorTask$OfRef = ::java::util::stream::Nodes$CollectorTask$OfRef;
using $Nodes$ConcNode = ::java::util::stream::Nodes$ConcNode;
using $Nodes$ConcNode$OfDouble = ::java::util::stream::Nodes$ConcNode$OfDouble;
using $Nodes$ConcNode$OfInt = ::java::util::stream::Nodes$ConcNode$OfInt;
using $Nodes$ConcNode$OfLong = ::java::util::stream::Nodes$ConcNode$OfLong;
using $Nodes$DoubleArrayNode = ::java::util::stream::Nodes$DoubleArrayNode;
using $Nodes$DoubleFixedNodeBuilder = ::java::util::stream::Nodes$DoubleFixedNodeBuilder;
using $Nodes$DoubleSpinedNodeBuilder = ::java::util::stream::Nodes$DoubleSpinedNodeBuilder;
using $Nodes$EmptyNode$OfDouble = ::java::util::stream::Nodes$EmptyNode$OfDouble;
using $Nodes$EmptyNode$OfInt = ::java::util::stream::Nodes$EmptyNode$OfInt;
using $Nodes$EmptyNode$OfLong = ::java::util::stream::Nodes$EmptyNode$OfLong;
using $Nodes$EmptyNode$OfRef = ::java::util::stream::Nodes$EmptyNode$OfRef;
using $Nodes$FixedNodeBuilder = ::java::util::stream::Nodes$FixedNodeBuilder;
using $Nodes$IntArrayNode = ::java::util::stream::Nodes$IntArrayNode;
using $Nodes$IntFixedNodeBuilder = ::java::util::stream::Nodes$IntFixedNodeBuilder;
using $Nodes$IntSpinedNodeBuilder = ::java::util::stream::Nodes$IntSpinedNodeBuilder;
using $Nodes$LongArrayNode = ::java::util::stream::Nodes$LongArrayNode;
using $Nodes$LongFixedNodeBuilder = ::java::util::stream::Nodes$LongFixedNodeBuilder;
using $Nodes$LongSpinedNodeBuilder = ::java::util::stream::Nodes$LongSpinedNodeBuilder;
using $Nodes$SizedCollectorTask$OfDouble = ::java::util::stream::Nodes$SizedCollectorTask$OfDouble;
using $Nodes$SizedCollectorTask$OfInt = ::java::util::stream::Nodes$SizedCollectorTask$OfInt;
using $Nodes$SizedCollectorTask$OfLong = ::java::util::stream::Nodes$SizedCollectorTask$OfLong;
using $Nodes$SizedCollectorTask$OfRef = ::java::util::stream::Nodes$SizedCollectorTask$OfRef;
using $Nodes$SpinedNodeBuilder = ::java::util::stream::Nodes$SpinedNodeBuilder;
using $Nodes$ToArrayTask$OfDouble = ::java::util::stream::Nodes$ToArrayTask$OfDouble;
using $Nodes$ToArrayTask$OfInt = ::java::util::stream::Nodes$ToArrayTask$OfInt;
using $Nodes$ToArrayTask$OfLong = ::java::util::stream::Nodes$ToArrayTask$OfLong;
using $Nodes$ToArrayTask$OfRef = ::java::util::stream::Nodes$ToArrayTask$OfRef;
using $PipelineHelper = ::java::util::stream::PipelineHelper;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

class Nodes$$Lambda$lambda$castingArray$0 : public $IntFunction {
	$class(Nodes$$Lambda$lambda$castingArray$0, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t size) override {
		 return $of(Nodes::lambda$castingArray$0(size));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Nodes$$Lambda$lambda$castingArray$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Nodes$$Lambda$lambda$castingArray$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Nodes$$Lambda$lambda$castingArray$0, init$, void)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Nodes$$Lambda$lambda$castingArray$0, apply, $Object*, int32_t)},
	{}
};
$ClassInfo Nodes$$Lambda$lambda$castingArray$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Nodes$$Lambda$lambda$castingArray$0",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
$Class* Nodes$$Lambda$lambda$castingArray$0::load$($String* name, bool initialize) {
	$loadClass(Nodes$$Lambda$lambda$castingArray$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Nodes$$Lambda$lambda$castingArray$0::class$ = nullptr;

$FieldInfo _Nodes_FieldInfo_[] = {
	{"MAX_ARRAY_SIZE", "J", nullptr, $STATIC | $FINAL, $constField(Nodes, MAX_ARRAY_SIZE)},
	{"BAD_SIZE", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Nodes, BAD_SIZE)},
	{"EMPTY_NODE", "Ljava/util/stream/Node;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Nodes, EMPTY_NODE)},
	{"EMPTY_INT_NODE", "Ljava/util/stream/Node$OfInt;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Nodes, EMPTY_INT_NODE)},
	{"EMPTY_LONG_NODE", "Ljava/util/stream/Node$OfLong;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Nodes, EMPTY_LONG_NODE)},
	{"EMPTY_DOUBLE_NODE", "Ljava/util/stream/Node$OfDouble;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Nodes, EMPTY_DOUBLE_NODE)},
	{"EMPTY_INT_ARRAY", "[I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Nodes, EMPTY_INT_ARRAY)},
	{"EMPTY_LONG_ARRAY", "[J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Nodes, EMPTY_LONG_ARRAY)},
	{"EMPTY_DOUBLE_ARRAY", "[D", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Nodes, EMPTY_DOUBLE_ARRAY)},
	{}
};

$MethodInfo _Nodes_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(Nodes, init$, void)},
	{"builder", "(JLjava/util/function/IntFunction;)Ljava/util/stream/Node$Builder;", "<T:Ljava/lang/Object;>(JLjava/util/function/IntFunction<[TT;>;)Ljava/util/stream/Node$Builder<TT;>;", $STATIC, $staticMethod(Nodes, builder, $Node$Builder*, int64_t, $IntFunction*)},
	{"builder", "()Ljava/util/stream/Node$Builder;", "<T:Ljava/lang/Object;>()Ljava/util/stream/Node$Builder<TT;>;", $STATIC, $staticMethod(Nodes, builder, $Node$Builder*)},
	{"castingArray", "()Ljava/util/function/IntFunction;", "<T:Ljava/lang/Object;>()Ljava/util/function/IntFunction<[TT;>;", $STATIC, $staticMethod(Nodes, castingArray, $IntFunction*)},
	{"collect", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;ZLjava/util/function/IntFunction;)Ljava/util/stream/Node;", "<P_IN:Ljava/lang/Object;P_OUT:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<TP_OUT;>;Ljava/util/Spliterator<TP_IN;>;ZLjava/util/function/IntFunction<[TP_OUT;>;)Ljava/util/stream/Node<TP_OUT;>;", $PUBLIC | $STATIC, $staticMethod(Nodes, collect, $Node*, $PipelineHelper*, $Spliterator*, bool, $IntFunction*)},
	{"collectDouble", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;Z)Ljava/util/stream/Node$OfDouble;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Double;>;Ljava/util/Spliterator<TP_IN;>;Z)Ljava/util/stream/Node$OfDouble;", $PUBLIC | $STATIC, $staticMethod(Nodes, collectDouble, $Node$OfDouble*, $PipelineHelper*, $Spliterator*, bool)},
	{"collectInt", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;Z)Ljava/util/stream/Node$OfInt;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Integer;>;Ljava/util/Spliterator<TP_IN;>;Z)Ljava/util/stream/Node$OfInt;", $PUBLIC | $STATIC, $staticMethod(Nodes, collectInt, $Node$OfInt*, $PipelineHelper*, $Spliterator*, bool)},
	{"collectLong", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;Z)Ljava/util/stream/Node$OfLong;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Long;>;Ljava/util/Spliterator<TP_IN;>;Z)Ljava/util/stream/Node$OfLong;", $PUBLIC | $STATIC, $staticMethod(Nodes, collectLong, $Node$OfLong*, $PipelineHelper*, $Spliterator*, bool)},
	{"conc", "(Ljava/util/stream/StreamShape;Ljava/util/stream/Node;Ljava/util/stream/Node;)Ljava/util/stream/Node;", "<T:Ljava/lang/Object;>(Ljava/util/stream/StreamShape;Ljava/util/stream/Node<TT;>;Ljava/util/stream/Node<TT;>;)Ljava/util/stream/Node<TT;>;", $STATIC, $staticMethod(Nodes, conc, $Node*, $StreamShape*, $Node*, $Node*)},
	{"doubleBuilder", "(J)Ljava/util/stream/Node$Builder$OfDouble;", nullptr, $STATIC, $staticMethod(Nodes, doubleBuilder, $Node$Builder$OfDouble*, int64_t)},
	{"doubleBuilder", "()Ljava/util/stream/Node$Builder$OfDouble;", nullptr, $STATIC, $staticMethod(Nodes, doubleBuilder, $Node$Builder$OfDouble*)},
	{"emptyNode", "(Ljava/util/stream/StreamShape;)Ljava/util/stream/Node;", "<T:Ljava/lang/Object;>(Ljava/util/stream/StreamShape;)Ljava/util/stream/Node<TT;>;", $STATIC, $staticMethod(Nodes, emptyNode, $Node*, $StreamShape*)},
	{"flatten", "(Ljava/util/stream/Node;Ljava/util/function/IntFunction;)Ljava/util/stream/Node;", "<T:Ljava/lang/Object;>(Ljava/util/stream/Node<TT;>;Ljava/util/function/IntFunction<[TT;>;)Ljava/util/stream/Node<TT;>;", $PUBLIC | $STATIC, $staticMethod(Nodes, flatten, $Node*, $Node*, $IntFunction*)},
	{"flattenDouble", "(Ljava/util/stream/Node$OfDouble;)Ljava/util/stream/Node$OfDouble;", nullptr, $PUBLIC | $STATIC, $staticMethod(Nodes, flattenDouble, $Node$OfDouble*, $Node$OfDouble*)},
	{"flattenInt", "(Ljava/util/stream/Node$OfInt;)Ljava/util/stream/Node$OfInt;", nullptr, $PUBLIC | $STATIC, $staticMethod(Nodes, flattenInt, $Node$OfInt*, $Node$OfInt*)},
	{"flattenLong", "(Ljava/util/stream/Node$OfLong;)Ljava/util/stream/Node$OfLong;", nullptr, $PUBLIC | $STATIC, $staticMethod(Nodes, flattenLong, $Node$OfLong*, $Node$OfLong*)},
	{"intBuilder", "(J)Ljava/util/stream/Node$Builder$OfInt;", nullptr, $STATIC, $staticMethod(Nodes, intBuilder, $Node$Builder$OfInt*, int64_t)},
	{"intBuilder", "()Ljava/util/stream/Node$Builder$OfInt;", nullptr, $STATIC, $staticMethod(Nodes, intBuilder, $Node$Builder$OfInt*)},
	{"lambda$castingArray$0", "(I)[Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Nodes, lambda$castingArray$0, $ObjectArray*, int32_t)},
	{"longBuilder", "(J)Ljava/util/stream/Node$Builder$OfLong;", nullptr, $STATIC, $staticMethod(Nodes, longBuilder, $Node$Builder$OfLong*, int64_t)},
	{"longBuilder", "()Ljava/util/stream/Node$Builder$OfLong;", nullptr, $STATIC, $staticMethod(Nodes, longBuilder, $Node$Builder$OfLong*)},
	{"node", "([Ljava/lang/Object;)Ljava/util/stream/Node;", "<T:Ljava/lang/Object;>([TT;)Ljava/util/stream/Node<TT;>;", $STATIC, $staticMethod(Nodes, node, $Node*, $ObjectArray*)},
	{"node", "(Ljava/util/Collection;)Ljava/util/stream/Node;", "<T:Ljava/lang/Object;>(Ljava/util/Collection<TT;>;)Ljava/util/stream/Node<TT;>;", $STATIC, $staticMethod(Nodes, node, $Node*, $Collection*)},
	{"node", "([I)Ljava/util/stream/Node$OfInt;", nullptr, $STATIC, $staticMethod(Nodes, node, $Node$OfInt*, $ints*)},
	{"node", "([J)Ljava/util/stream/Node$OfLong;", nullptr, $STATIC, $staticMethod(Nodes, node, $Node$OfLong*, $longs*)},
	{"node", "([D)Ljava/util/stream/Node$OfDouble;", nullptr, $STATIC, $staticMethod(Nodes, node, $Node$OfDouble*, $doubles*)},
	{}
};

$InnerClassInfo _Nodes_InnerClassesInfo_[] = {
	{"java.util.stream.Nodes$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"java.util.stream.Nodes$CollectorTask", "java.util.stream.Nodes", "CollectorTask", $PRIVATE | $STATIC},
	{"java.util.stream.Nodes$ToArrayTask", "java.util.stream.Nodes", "ToArrayTask", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.stream.Nodes$SizedCollectorTask", "java.util.stream.Nodes", "SizedCollectorTask", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.stream.Nodes$DoubleSpinedNodeBuilder", "java.util.stream.Nodes", "DoubleSpinedNodeBuilder", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.Nodes$LongSpinedNodeBuilder", "java.util.stream.Nodes", "LongSpinedNodeBuilder", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.Nodes$IntSpinedNodeBuilder", "java.util.stream.Nodes", "IntSpinedNodeBuilder", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.Nodes$DoubleFixedNodeBuilder", "java.util.stream.Nodes", "DoubleFixedNodeBuilder", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.Nodes$LongFixedNodeBuilder", "java.util.stream.Nodes", "LongFixedNodeBuilder", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.Nodes$IntFixedNodeBuilder", "java.util.stream.Nodes", "IntFixedNodeBuilder", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.Nodes$DoubleArrayNode", "java.util.stream.Nodes", "DoubleArrayNode", $PRIVATE | $STATIC},
	{"java.util.stream.Nodes$LongArrayNode", "java.util.stream.Nodes", "LongArrayNode", $PRIVATE | $STATIC},
	{"java.util.stream.Nodes$IntArrayNode", "java.util.stream.Nodes", "IntArrayNode", $PRIVATE | $STATIC},
	{"java.util.stream.Nodes$SpinedNodeBuilder", "java.util.stream.Nodes", "SpinedNodeBuilder", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.Nodes$FixedNodeBuilder", "java.util.stream.Nodes", "FixedNodeBuilder", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.Nodes$InternalNodeSpliterator", "java.util.stream.Nodes", "InternalNodeSpliterator", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.stream.Nodes$ConcNode", "java.util.stream.Nodes", "ConcNode", $STATIC | $FINAL},
	{"java.util.stream.Nodes$AbstractConcNode", "java.util.stream.Nodes", "AbstractConcNode", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.stream.Nodes$CollectionNode", "java.util.stream.Nodes", "CollectionNode", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.Nodes$ArrayNode", "java.util.stream.Nodes", "ArrayNode", $PRIVATE | $STATIC},
	{"java.util.stream.Nodes$EmptyNode", "java.util.stream.Nodes", "EmptyNode", $PRIVATE | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _Nodes_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.Nodes",
	"java.lang.Object",
	nullptr,
	_Nodes_FieldInfo_,
	_Nodes_MethodInfo_,
	nullptr,
	nullptr,
	_Nodes_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.stream.Nodes$1,java.util.stream.Nodes$CollectorTask,java.util.stream.Nodes$CollectorTask$OfDouble,java.util.stream.Nodes$CollectorTask$OfLong,java.util.stream.Nodes$CollectorTask$OfInt,java.util.stream.Nodes$CollectorTask$OfRef,java.util.stream.Nodes$ToArrayTask,java.util.stream.Nodes$ToArrayTask$OfDouble,java.util.stream.Nodes$ToArrayTask$OfLong,java.util.stream.Nodes$ToArrayTask$OfInt,java.util.stream.Nodes$ToArrayTask$OfPrimitive,java.util.stream.Nodes$ToArrayTask$OfRef,java.util.stream.Nodes$SizedCollectorTask,java.util.stream.Nodes$SizedCollectorTask$OfDouble,java.util.stream.Nodes$SizedCollectorTask$OfLong,java.util.stream.Nodes$SizedCollectorTask$OfInt,java.util.stream.Nodes$SizedCollectorTask$OfRef,java.util.stream.Nodes$DoubleSpinedNodeBuilder,java.util.stream.Nodes$LongSpinedNodeBuilder,java.util.stream.Nodes$IntSpinedNodeBuilder,java.util.stream.Nodes$DoubleFixedNodeBuilder,java.util.stream.Nodes$LongFixedNodeBuilder,java.util.stream.Nodes$IntFixedNodeBuilder,java.util.stream.Nodes$DoubleArrayNode,java.util.stream.Nodes$LongArrayNode,java.util.stream.Nodes$IntArrayNode,java.util.stream.Nodes$SpinedNodeBuilder,java.util.stream.Nodes$FixedNodeBuilder,java.util.stream.Nodes$InternalNodeSpliterator,java.util.stream.Nodes$InternalNodeSpliterator$OfDouble,java.util.stream.Nodes$InternalNodeSpliterator$OfLong,java.util.stream.Nodes$InternalNodeSpliterator$OfInt,java.util.stream.Nodes$InternalNodeSpliterator$OfPrimitive,java.util.stream.Nodes$InternalNodeSpliterator$OfRef,java.util.stream.Nodes$ConcNode,java.util.stream.Nodes$ConcNode$OfDouble,java.util.stream.Nodes$ConcNode$OfLong,java.util.stream.Nodes$ConcNode$OfInt,java.util.stream.Nodes$ConcNode$OfPrimitive,java.util.stream.Nodes$AbstractConcNode,java.util.stream.Nodes$CollectionNode,java.util.stream.Nodes$ArrayNode,java.util.stream.Nodes$EmptyNode,java.util.stream.Nodes$EmptyNode$OfDouble,java.util.stream.Nodes$EmptyNode$OfLong,java.util.stream.Nodes$EmptyNode$OfInt,java.util.stream.Nodes$EmptyNode$OfRef"
};

$Object* allocate$Nodes($Class* clazz) {
	return $of($alloc(Nodes));
}

$String* Nodes::BAD_SIZE = nullptr;
$Node* Nodes::EMPTY_NODE = nullptr;
$Node$OfInt* Nodes::EMPTY_INT_NODE = nullptr;
$Node$OfLong* Nodes::EMPTY_LONG_NODE = nullptr;
$Node$OfDouble* Nodes::EMPTY_DOUBLE_NODE = nullptr;
$ints* Nodes::EMPTY_INT_ARRAY = nullptr;
$longs* Nodes::EMPTY_LONG_ARRAY = nullptr;
$doubles* Nodes::EMPTY_DOUBLE_ARRAY = nullptr;

void Nodes::init$() {
	$throwNew($Error, "no instances"_s);
}

$IntFunction* Nodes::castingArray() {
	$init(Nodes);
	return static_cast<$IntFunction*>($new(Nodes$$Lambda$lambda$castingArray$0));
}

$Node* Nodes::emptyNode($StreamShape* shape) {
	$init(Nodes);
	$init($Nodes$1);

	$var($Node, var$0, nullptr)
	switch ($nc($Nodes$1::$SwitchMap$java$util$stream$StreamShape)->get($nc((shape))->ordinal())) {
	default:
		{
			$throwNew($IncompatibleClassChangeError);
		}
	case 1:
		{
			$assign(var$0, Nodes::EMPTY_NODE);
			break;
		}
	case 2:
		{
			$assign(var$0, Nodes::EMPTY_INT_NODE);
			break;
		}
	case 3:
		{
			$assign(var$0, Nodes::EMPTY_LONG_NODE);
			break;
		}
	case 4:
		{
			$assign(var$0, Nodes::EMPTY_DOUBLE_NODE);
			break;
		}
	}
	return var$0;
}

$Node* Nodes::conc($StreamShape* shape, $Node* left, $Node* right) {
	$init(Nodes);
	$init($Nodes$1);

	$var($Nodes$AbstractConcNode, var$0, nullptr)
	switch ($nc($Nodes$1::$SwitchMap$java$util$stream$StreamShape)->get($nc((shape))->ordinal())) {
	default:
		{
			$throwNew($IncompatibleClassChangeError);
		}
	case 1:
		{
			$assign(var$0, $new($Nodes$ConcNode, left, right));
			break;
		}
	case 2:
		{
			$assign(var$0, $new($Nodes$ConcNode$OfInt, $cast($Node$OfInt, left), $cast($Node$OfInt, right)));
			break;
		}
	case 3:
		{
			$assign(var$0, $new($Nodes$ConcNode$OfLong, $cast($Node$OfLong, left), $cast($Node$OfLong, right)));
			break;
		}
	case 4:
		{
			$assign(var$0, $new($Nodes$ConcNode$OfDouble, $cast($Node$OfDouble, left), $cast($Node$OfDouble, right)));
			break;
		}
	}
	return static_cast<$Node*>(var$0);
}

$Node* Nodes::node($ObjectArray* array) {
	$init(Nodes);
	return $new($Nodes$ArrayNode, array);
}

$Node* Nodes::node($Collection* c) {
	$init(Nodes);
	return $new($Nodes$CollectionNode, c);
}

$Node$Builder* Nodes::builder(int64_t exactSizeIfKnown, $IntFunction* generator) {
	$init(Nodes);
	return (exactSizeIfKnown >= 0 && exactSizeIfKnown < Nodes::MAX_ARRAY_SIZE) ? static_cast<$Node$Builder*>($new($Nodes$FixedNodeBuilder, exactSizeIfKnown, generator)) : builder();
}

$Node$Builder* Nodes::builder() {
	$init(Nodes);
	return $new($Nodes$SpinedNodeBuilder);
}

$Node$OfInt* Nodes::node($ints* array) {
	$init(Nodes);
	return $new($Nodes$IntArrayNode, array);
}

$Node$Builder$OfInt* Nodes::intBuilder(int64_t exactSizeIfKnown) {
	$init(Nodes);
	return (exactSizeIfKnown >= 0 && exactSizeIfKnown < Nodes::MAX_ARRAY_SIZE) ? static_cast<$Node$Builder$OfInt*>($new($Nodes$IntFixedNodeBuilder, exactSizeIfKnown)) : intBuilder();
}

$Node$Builder$OfInt* Nodes::intBuilder() {
	$init(Nodes);
	return $new($Nodes$IntSpinedNodeBuilder);
}

$Node$OfLong* Nodes::node($longs* array) {
	$init(Nodes);
	return $new($Nodes$LongArrayNode, array);
}

$Node$Builder$OfLong* Nodes::longBuilder(int64_t exactSizeIfKnown) {
	$init(Nodes);
	return (exactSizeIfKnown >= 0 && exactSizeIfKnown < Nodes::MAX_ARRAY_SIZE) ? static_cast<$Node$Builder$OfLong*>($new($Nodes$LongFixedNodeBuilder, exactSizeIfKnown)) : longBuilder();
}

$Node$Builder$OfLong* Nodes::longBuilder() {
	$init(Nodes);
	return $new($Nodes$LongSpinedNodeBuilder);
}

$Node$OfDouble* Nodes::node($doubles* array) {
	$init(Nodes);
	return $new($Nodes$DoubleArrayNode, array);
}

$Node$Builder$OfDouble* Nodes::doubleBuilder(int64_t exactSizeIfKnown) {
	$init(Nodes);
	return (exactSizeIfKnown >= 0 && exactSizeIfKnown < Nodes::MAX_ARRAY_SIZE) ? static_cast<$Node$Builder$OfDouble*>($new($Nodes$DoubleFixedNodeBuilder, exactSizeIfKnown)) : doubleBuilder();
}

$Node$Builder$OfDouble* Nodes::doubleBuilder() {
	$init(Nodes);
	return $new($Nodes$DoubleSpinedNodeBuilder);
}

$Node* Nodes::collect($PipelineHelper* helper, $Spliterator* spliterator, bool flattenTree, $IntFunction* generator) {
	$init(Nodes);
	$useLocalCurrentObjectStackCache();
	int64_t size = $nc(helper)->exactOutputSizeIfKnown(spliterator);
	if (size >= 0 && $nc(spliterator)->hasCharacteristics($Spliterator::SUBSIZED)) {
		if (size >= Nodes::MAX_ARRAY_SIZE) {
			$throwNew($IllegalArgumentException, Nodes::BAD_SIZE);
		}
		$var($ObjectArray, array, $cast($ObjectArray, $nc(generator)->apply((int32_t)size)));
		$$new($Nodes$SizedCollectorTask$OfRef, spliterator, helper, array)->invoke();
		return Nodes::node(array);
	} else {
		$var($Node, node, $cast($Node, $$new($Nodes$CollectorTask$OfRef, helper, generator, spliterator)->invoke()));
		return flattenTree ? flatten(node, generator) : node;
	}
}

$Node$OfInt* Nodes::collectInt($PipelineHelper* helper, $Spliterator* spliterator, bool flattenTree) {
	$init(Nodes);
	$useLocalCurrentObjectStackCache();
	int64_t size = $nc(helper)->exactOutputSizeIfKnown(spliterator);
	if (size >= 0 && $nc(spliterator)->hasCharacteristics($Spliterator::SUBSIZED)) {
		if (size >= Nodes::MAX_ARRAY_SIZE) {
			$throwNew($IllegalArgumentException, Nodes::BAD_SIZE);
		}
		$var($ints, array, $new($ints, (int32_t)size));
		$$new($Nodes$SizedCollectorTask$OfInt, spliterator, helper, array)->invoke();
		return Nodes::node(array);
	} else {
		$var($Node$OfInt, node, $cast($Node$OfInt, $$new($Nodes$CollectorTask$OfInt, helper, spliterator)->invoke()));
		return flattenTree ? flattenInt(node) : node;
	}
}

$Node$OfLong* Nodes::collectLong($PipelineHelper* helper, $Spliterator* spliterator, bool flattenTree) {
	$init(Nodes);
	$useLocalCurrentObjectStackCache();
	int64_t size = $nc(helper)->exactOutputSizeIfKnown(spliterator);
	if (size >= 0 && $nc(spliterator)->hasCharacteristics($Spliterator::SUBSIZED)) {
		if (size >= Nodes::MAX_ARRAY_SIZE) {
			$throwNew($IllegalArgumentException, Nodes::BAD_SIZE);
		}
		$var($longs, array, $new($longs, (int32_t)size));
		$$new($Nodes$SizedCollectorTask$OfLong, spliterator, helper, array)->invoke();
		return Nodes::node(array);
	} else {
		$var($Node$OfLong, node, $cast($Node$OfLong, $$new($Nodes$CollectorTask$OfLong, helper, spliterator)->invoke()));
		return flattenTree ? flattenLong(node) : node;
	}
}

$Node$OfDouble* Nodes::collectDouble($PipelineHelper* helper, $Spliterator* spliterator, bool flattenTree) {
	$init(Nodes);
	$useLocalCurrentObjectStackCache();
	int64_t size = $nc(helper)->exactOutputSizeIfKnown(spliterator);
	if (size >= 0 && $nc(spliterator)->hasCharacteristics($Spliterator::SUBSIZED)) {
		if (size >= Nodes::MAX_ARRAY_SIZE) {
			$throwNew($IllegalArgumentException, Nodes::BAD_SIZE);
		}
		$var($doubles, array, $new($doubles, (int32_t)size));
		$$new($Nodes$SizedCollectorTask$OfDouble, spliterator, helper, array)->invoke();
		return Nodes::node(array);
	} else {
		$var($Node$OfDouble, node, $cast($Node$OfDouble, $$new($Nodes$CollectorTask$OfDouble, helper, spliterator)->invoke()));
		return flattenTree ? flattenDouble(node) : node;
	}
}

$Node* Nodes::flatten($Node* node, $IntFunction* generator) {
	$init(Nodes);
	$useLocalCurrentObjectStackCache();
	if ($nc(node)->getChildCount() > 0) {
		int64_t size = node->count();
		if (size >= Nodes::MAX_ARRAY_SIZE) {
			$throwNew($IllegalArgumentException, Nodes::BAD_SIZE);
		}
		$var($ObjectArray, array, $cast($ObjectArray, $nc(generator)->apply((int32_t)size)));
		$$new($Nodes$ToArrayTask$OfRef, node, array, 0)->invoke();
		return Nodes::node(array);
	} else {
		return node;
	}
}

$Node$OfInt* Nodes::flattenInt($Node$OfInt* node) {
	$init(Nodes);
	$useLocalCurrentObjectStackCache();
	if ($nc(node)->getChildCount() > 0) {
		int64_t size = node->count();
		if (size >= Nodes::MAX_ARRAY_SIZE) {
			$throwNew($IllegalArgumentException, Nodes::BAD_SIZE);
		}
		$var($ints, array, $new($ints, (int32_t)size));
		$$new($Nodes$ToArrayTask$OfInt, node, array, 0)->invoke();
		return Nodes::node(array);
	} else {
		return node;
	}
}

$Node$OfLong* Nodes::flattenLong($Node$OfLong* node) {
	$init(Nodes);
	$useLocalCurrentObjectStackCache();
	if ($nc(node)->getChildCount() > 0) {
		int64_t size = node->count();
		if (size >= Nodes::MAX_ARRAY_SIZE) {
			$throwNew($IllegalArgumentException, Nodes::BAD_SIZE);
		}
		$var($longs, array, $new($longs, (int32_t)size));
		$$new($Nodes$ToArrayTask$OfLong, node, array, 0)->invoke();
		return Nodes::node(array);
	} else {
		return node;
	}
}

$Node$OfDouble* Nodes::flattenDouble($Node$OfDouble* node) {
	$init(Nodes);
	$useLocalCurrentObjectStackCache();
	if ($nc(node)->getChildCount() > 0) {
		int64_t size = node->count();
		if (size >= Nodes::MAX_ARRAY_SIZE) {
			$throwNew($IllegalArgumentException, Nodes::BAD_SIZE);
		}
		$var($doubles, array, $new($doubles, (int32_t)size));
		$$new($Nodes$ToArrayTask$OfDouble, node, array, 0)->invoke();
		return Nodes::node(array);
	} else {
		return node;
	}
}

$ObjectArray* Nodes::lambda$castingArray$0(int32_t size) {
	$init(Nodes);
	return $new($ObjectArray, size);
}

void clinit$Nodes($Class* class$) {
	$assignStatic(Nodes::BAD_SIZE, "Stream size exceeds max array size"_s);
	$assignStatic(Nodes::EMPTY_NODE, $new($Nodes$EmptyNode$OfRef));
	$assignStatic(Nodes::EMPTY_INT_NODE, $as($Node$OfInt, $new($Nodes$EmptyNode$OfInt)));
	$assignStatic(Nodes::EMPTY_LONG_NODE, $as($Node$OfLong, $new($Nodes$EmptyNode$OfLong)));
	$assignStatic(Nodes::EMPTY_DOUBLE_NODE, $as($Node$OfDouble, $new($Nodes$EmptyNode$OfDouble)));
	$assignStatic(Nodes::EMPTY_INT_ARRAY, $new($ints, 0));
	$assignStatic(Nodes::EMPTY_LONG_ARRAY, $new($longs, 0));
	$assignStatic(Nodes::EMPTY_DOUBLE_ARRAY, $new($doubles, 0));
}

Nodes::Nodes() {
}

$Class* Nodes::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Nodes$$Lambda$lambda$castingArray$0::classInfo$.name)) {
			return Nodes$$Lambda$lambda$castingArray$0::load$(name, initialize);
		}
	}
	$loadClass(Nodes, name, initialize, &_Nodes_ClassInfo_, clinit$Nodes, allocate$Nodes);
	return class$;
}

$Class* Nodes::class$ = nullptr;

		} // stream
	} // util
} // java