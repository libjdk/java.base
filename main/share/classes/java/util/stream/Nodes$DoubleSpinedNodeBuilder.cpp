#include <java/util/stream/Nodes$DoubleSpinedNodeBuilder.h>

#include <java/lang/AssertionError.h>
#include <java/util/Spliterator$OfDouble.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/DoubleConsumer.h>
#include <java/util/stream/Node.h>
#include <java/util/stream/Nodes.h>
#include <java/util/stream/SpinedBuffer$OfDouble.h>
#include <java/util/stream/SpinedBuffer$OfPrimitive.h>
#include <jcpp.h>

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Spliterator = ::java::util::Spliterator;
using $Consumer = ::java::util::function::Consumer;
using $DoubleConsumer = ::java::util::function::DoubleConsumer;
using $Node = ::java::util::stream::Node;
using $Nodes = ::java::util::stream::Nodes;
using $SpinedBuffer$OfDouble = ::java::util::stream::SpinedBuffer$OfDouble;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _Nodes$DoubleSpinedNodeBuilder_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Nodes$DoubleSpinedNodeBuilder, $assertionsDisabled)},
	{"building", "Z", nullptr, $PRIVATE, $field(Nodes$DoubleSpinedNodeBuilder, building)},
	{}
};

$MethodInfo _Nodes$DoubleSpinedNodeBuilder_MethodInfo_[] = {
	{"*andThen", "(Ljava/util/function/DoubleConsumer;)Ljava/util/function/DoubleConsumer;", nullptr, $PUBLIC | $ABSTRACT},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*count", "()J", nullptr, $PUBLIC},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEach", "(Ljava/util/function/Consumer;)V", nullptr, $PUBLIC},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, 0, $method(Nodes$DoubleSpinedNodeBuilder, init$, void)},
	{"accept", "(D)V", nullptr, $PUBLIC, $virtualMethod(Nodes$DoubleSpinedNodeBuilder, accept, void, double)},
	{"asPrimitiveArray", "()[D", nullptr, $PUBLIC, $virtualMethod(Nodes$DoubleSpinedNodeBuilder, asPrimitiveArray, $Object*)},
	{"begin", "(J)V", nullptr, $PUBLIC, $virtualMethod(Nodes$DoubleSpinedNodeBuilder, begin, void, int64_t)},
	{"build", "()Ljava/util/stream/Node$OfDouble;", nullptr, $PUBLIC, $virtualMethod(Nodes$DoubleSpinedNodeBuilder, build, $Node*)},
	{"copyInto", "([DI)V", nullptr, $PUBLIC, $method(Nodes$DoubleSpinedNodeBuilder, copyInto, void, $doubles*, int32_t)},
	{"copyInto", "(Ljava/lang/Object;I)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Nodes$DoubleSpinedNodeBuilder, copyInto, void, Object$*, int32_t)},
	{"end", "()V", nullptr, $PUBLIC, $virtualMethod(Nodes$DoubleSpinedNodeBuilder, end, void)},
	{"forEach", "(Ljava/util/function/DoubleConsumer;)V", nullptr, $PUBLIC, $method(Nodes$DoubleSpinedNodeBuilder, forEach, void, $DoubleConsumer*)},
	{"forEach", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Nodes$DoubleSpinedNodeBuilder, forEach, void, Object$*)},
	{"*newArray", "(I)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"spliterator", "()Ljava/util/Spliterator$OfDouble;", nullptr, $PUBLIC, $virtualMethod(Nodes$DoubleSpinedNodeBuilder, spliterator, $Spliterator*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Nodes$DoubleSpinedNodeBuilder_InnerClassesInfo_[] = {
	{"java.util.stream.Nodes$DoubleSpinedNodeBuilder", "java.util.stream.Nodes", "DoubleSpinedNodeBuilder", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.SpinedBuffer$OfDouble", "java.util.stream.SpinedBuffer", "OfDouble", $STATIC},
	{"java.util.stream.Node$OfDouble", "java.util.stream.Node", "OfDouble", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.Node$Builder", "java.util.stream.Node", "Builder", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.Node$Builder$OfDouble", "java.util.stream.Node$Builder", "OfDouble", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Nodes$DoubleSpinedNodeBuilder_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.Nodes$DoubleSpinedNodeBuilder",
	"java.util.stream.SpinedBuffer$OfDouble",
	"java.util.stream.Node$OfDouble,java.util.stream.Node$Builder$OfDouble",
	_Nodes$DoubleSpinedNodeBuilder_FieldInfo_,
	_Nodes$DoubleSpinedNodeBuilder_MethodInfo_,
	nullptr,
	nullptr,
	_Nodes$DoubleSpinedNodeBuilder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.Nodes"
};

$Object* allocate$Nodes$DoubleSpinedNodeBuilder($Class* clazz) {
	return $of($alloc(Nodes$DoubleSpinedNodeBuilder));
}

void Nodes$DoubleSpinedNodeBuilder::forEach($Consumer* consumer) {
	this->$SpinedBuffer$OfDouble::forEach(consumer);
}

$Object* Nodes$DoubleSpinedNodeBuilder::newArray(int32_t size) {
	 return this->$SpinedBuffer$OfDouble::newArray(size);
}

$String* Nodes$DoubleSpinedNodeBuilder::toString() {
	 return this->$SpinedBuffer$OfDouble::toString();
}

int64_t Nodes$DoubleSpinedNodeBuilder::count() {
	 return this->$SpinedBuffer$OfDouble::count();
}

int32_t Nodes$DoubleSpinedNodeBuilder::hashCode() {
	 return this->$SpinedBuffer$OfDouble::hashCode();
}

bool Nodes$DoubleSpinedNodeBuilder::equals(Object$* obj) {
	 return this->$SpinedBuffer$OfDouble::equals(obj);
}

$Object* Nodes$DoubleSpinedNodeBuilder::clone() {
	 return this->$SpinedBuffer$OfDouble::clone();
}

void Nodes$DoubleSpinedNodeBuilder::finalize() {
	this->$SpinedBuffer$OfDouble::finalize();
}

$DoubleConsumer* Nodes$DoubleSpinedNodeBuilder::andThen($DoubleConsumer* after) {
	 return this->$SpinedBuffer$OfDouble::andThen(after);
}

bool Nodes$DoubleSpinedNodeBuilder::$assertionsDisabled = false;

void Nodes$DoubleSpinedNodeBuilder::init$() {
	$SpinedBuffer$OfDouble::init$();
	this->building = false;
}

$Spliterator* Nodes$DoubleSpinedNodeBuilder::spliterator() {
	if (!Nodes$DoubleSpinedNodeBuilder::$assertionsDisabled && ! !this->building) {
		$throwNew($AssertionError, $of("during building"_s));
	}
	return $SpinedBuffer$OfDouble::spliterator();
}

void Nodes$DoubleSpinedNodeBuilder::forEach($DoubleConsumer* consumer) {
	if (!Nodes$DoubleSpinedNodeBuilder::$assertionsDisabled && ! !this->building) {
		$throwNew($AssertionError, $of("during building"_s));
	}
	$SpinedBuffer$OfDouble::forEach($of(consumer));
}

void Nodes$DoubleSpinedNodeBuilder::begin(int64_t size) {
	if (!Nodes$DoubleSpinedNodeBuilder::$assertionsDisabled && ! !this->building) {
		$throwNew($AssertionError, $of("was already building"_s));
	}
	this->building = true;
	clear();
	ensureCapacity(size);
}

void Nodes$DoubleSpinedNodeBuilder::accept(double i) {
	if (!Nodes$DoubleSpinedNodeBuilder::$assertionsDisabled && !this->building) {
		$throwNew($AssertionError, $of("not building"_s));
	}
	$SpinedBuffer$OfDouble::accept(i);
}

void Nodes$DoubleSpinedNodeBuilder::end() {
	if (!Nodes$DoubleSpinedNodeBuilder::$assertionsDisabled && !this->building) {
		$throwNew($AssertionError, $of("was not building"_s));
	}
	this->building = false;
}

void Nodes$DoubleSpinedNodeBuilder::copyInto($doubles* array, int32_t offset) {
	if (!Nodes$DoubleSpinedNodeBuilder::$assertionsDisabled && ! !this->building) {
		$throwNew($AssertionError, $of("during building"_s));
	}
	$SpinedBuffer$OfDouble::copyInto(array, offset);
}

$Object* Nodes$DoubleSpinedNodeBuilder::asPrimitiveArray() {
	if (!Nodes$DoubleSpinedNodeBuilder::$assertionsDisabled && ! !this->building) {
		$throwNew($AssertionError, $of("during building"_s));
	}
	return $of($cast($doubles, $SpinedBuffer$OfDouble::asPrimitiveArray()));
}

$Node* Nodes$DoubleSpinedNodeBuilder::build() {
	if (!Nodes$DoubleSpinedNodeBuilder::$assertionsDisabled && ! !this->building) {
		$throwNew($AssertionError, $of("during building"_s));
	}
	return this;
}

void Nodes$DoubleSpinedNodeBuilder::forEach(Object$* consumer) {
	this->forEach($cast($DoubleConsumer, consumer));
}

void Nodes$DoubleSpinedNodeBuilder::copyInto(Object$* array, int32_t offset) {
	this->copyInto($cast($doubles, array), offset);
}

void clinit$Nodes$DoubleSpinedNodeBuilder($Class* class$) {
	$load($Nodes);
	Nodes$DoubleSpinedNodeBuilder::$assertionsDisabled = !$Nodes::class$->desiredAssertionStatus();
}

Nodes$DoubleSpinedNodeBuilder::Nodes$DoubleSpinedNodeBuilder() {
}

$Class* Nodes$DoubleSpinedNodeBuilder::load$($String* name, bool initialize) {
	$loadClass(Nodes$DoubleSpinedNodeBuilder, name, initialize, &_Nodes$DoubleSpinedNodeBuilder_ClassInfo_, clinit$Nodes$DoubleSpinedNodeBuilder, allocate$Nodes$DoubleSpinedNodeBuilder);
	return class$;
}

$Class* Nodes$DoubleSpinedNodeBuilder::class$ = nullptr;

		} // stream
	} // util
} // java