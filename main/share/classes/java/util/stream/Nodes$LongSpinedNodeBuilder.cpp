#include <java/util/stream/Nodes$LongSpinedNodeBuilder.h>

#include <java/lang/AssertionError.h>
#include <java/util/Spliterator$OfLong.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/LongConsumer.h>
#include <java/util/stream/Node.h>
#include <java/util/stream/Nodes.h>
#include <java/util/stream/SpinedBuffer$OfLong.h>
#include <java/util/stream/SpinedBuffer$OfPrimitive.h>
#include <jcpp.h>

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Spliterator = ::java::util::Spliterator;
using $Consumer = ::java::util::function::Consumer;
using $LongConsumer = ::java::util::function::LongConsumer;
using $Node = ::java::util::stream::Node;
using $Nodes = ::java::util::stream::Nodes;
using $SpinedBuffer$OfLong = ::java::util::stream::SpinedBuffer$OfLong;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _Nodes$LongSpinedNodeBuilder_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Nodes$LongSpinedNodeBuilder, $assertionsDisabled)},
	{"building", "Z", nullptr, $PRIVATE, $field(Nodes$LongSpinedNodeBuilder, building)},
	{}
};

$MethodInfo _Nodes$LongSpinedNodeBuilder_MethodInfo_[] = {
	{"*andThen", "(Ljava/util/function/LongConsumer;)Ljava/util/function/LongConsumer;", nullptr, $PUBLIC | $ABSTRACT},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*count", "()J", nullptr, $PUBLIC},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEach", "(Ljava/util/function/Consumer;)V", nullptr, $PUBLIC},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, 0, $method(Nodes$LongSpinedNodeBuilder, init$, void)},
	{"accept", "(J)V", nullptr, $PUBLIC, $virtualMethod(Nodes$LongSpinedNodeBuilder, accept, void, int64_t)},
	{"asPrimitiveArray", "()[J", nullptr, $PUBLIC, $virtualMethod(Nodes$LongSpinedNodeBuilder, asPrimitiveArray, $Object*)},
	{"begin", "(J)V", nullptr, $PUBLIC, $virtualMethod(Nodes$LongSpinedNodeBuilder, begin, void, int64_t)},
	{"build", "()Ljava/util/stream/Node$OfLong;", nullptr, $PUBLIC, $virtualMethod(Nodes$LongSpinedNodeBuilder, build, $Node*)},
	{"copyInto", "([JI)V", nullptr, $PUBLIC, $method(Nodes$LongSpinedNodeBuilder, copyInto, void, $longs*, int32_t)},
	{"copyInto", "(Ljava/lang/Object;I)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Nodes$LongSpinedNodeBuilder, copyInto, void, Object$*, int32_t)},
	{"end", "()V", nullptr, $PUBLIC, $virtualMethod(Nodes$LongSpinedNodeBuilder, end, void)},
	{"forEach", "(Ljava/util/function/LongConsumer;)V", nullptr, $PUBLIC, $method(Nodes$LongSpinedNodeBuilder, forEach, void, $LongConsumer*)},
	{"forEach", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Nodes$LongSpinedNodeBuilder, forEach, void, Object$*)},
	{"*newArray", "(I)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"spliterator", "()Ljava/util/Spliterator$OfLong;", nullptr, $PUBLIC, $virtualMethod(Nodes$LongSpinedNodeBuilder, spliterator, $Spliterator*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Nodes$LongSpinedNodeBuilder_InnerClassesInfo_[] = {
	{"java.util.stream.Nodes$LongSpinedNodeBuilder", "java.util.stream.Nodes", "LongSpinedNodeBuilder", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.SpinedBuffer$OfLong", "java.util.stream.SpinedBuffer", "OfLong", $STATIC},
	{"java.util.stream.Node$OfLong", "java.util.stream.Node", "OfLong", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.Node$Builder", "java.util.stream.Node", "Builder", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.Node$Builder$OfLong", "java.util.stream.Node$Builder", "OfLong", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Nodes$LongSpinedNodeBuilder_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.Nodes$LongSpinedNodeBuilder",
	"java.util.stream.SpinedBuffer$OfLong",
	"java.util.stream.Node$OfLong,java.util.stream.Node$Builder$OfLong",
	_Nodes$LongSpinedNodeBuilder_FieldInfo_,
	_Nodes$LongSpinedNodeBuilder_MethodInfo_,
	nullptr,
	nullptr,
	_Nodes$LongSpinedNodeBuilder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.Nodes"
};

$Object* allocate$Nodes$LongSpinedNodeBuilder($Class* clazz) {
	return $of($alloc(Nodes$LongSpinedNodeBuilder));
}

void Nodes$LongSpinedNodeBuilder::forEach($Consumer* consumer) {
	this->$SpinedBuffer$OfLong::forEach(consumer);
}

$Object* Nodes$LongSpinedNodeBuilder::newArray(int32_t size) {
	 return this->$SpinedBuffer$OfLong::newArray(size);
}

$String* Nodes$LongSpinedNodeBuilder::toString() {
	 return this->$SpinedBuffer$OfLong::toString();
}

int64_t Nodes$LongSpinedNodeBuilder::count() {
	 return this->$SpinedBuffer$OfLong::count();
}

int32_t Nodes$LongSpinedNodeBuilder::hashCode() {
	 return this->$SpinedBuffer$OfLong::hashCode();
}

bool Nodes$LongSpinedNodeBuilder::equals(Object$* obj) {
	 return this->$SpinedBuffer$OfLong::equals(obj);
}

$Object* Nodes$LongSpinedNodeBuilder::clone() {
	 return this->$SpinedBuffer$OfLong::clone();
}

void Nodes$LongSpinedNodeBuilder::finalize() {
	this->$SpinedBuffer$OfLong::finalize();
}

$LongConsumer* Nodes$LongSpinedNodeBuilder::andThen($LongConsumer* after) {
	 return this->$SpinedBuffer$OfLong::andThen(after);
}

bool Nodes$LongSpinedNodeBuilder::$assertionsDisabled = false;

void Nodes$LongSpinedNodeBuilder::init$() {
	$SpinedBuffer$OfLong::init$();
	this->building = false;
}

$Spliterator* Nodes$LongSpinedNodeBuilder::spliterator() {
	if (!Nodes$LongSpinedNodeBuilder::$assertionsDisabled && ! !this->building) {
		$throwNew($AssertionError, $of("during building"_s));
	}
	return $SpinedBuffer$OfLong::spliterator();
}

void Nodes$LongSpinedNodeBuilder::forEach($LongConsumer* consumer) {
	if (!Nodes$LongSpinedNodeBuilder::$assertionsDisabled && ! !this->building) {
		$throwNew($AssertionError, $of("during building"_s));
	}
	$SpinedBuffer$OfLong::forEach($of(consumer));
}

void Nodes$LongSpinedNodeBuilder::begin(int64_t size) {
	if (!Nodes$LongSpinedNodeBuilder::$assertionsDisabled && ! !this->building) {
		$throwNew($AssertionError, $of("was already building"_s));
	}
	this->building = true;
	clear();
	ensureCapacity(size);
}

void Nodes$LongSpinedNodeBuilder::accept(int64_t i) {
	if (!Nodes$LongSpinedNodeBuilder::$assertionsDisabled && !this->building) {
		$throwNew($AssertionError, $of("not building"_s));
	}
	$SpinedBuffer$OfLong::accept(i);
}

void Nodes$LongSpinedNodeBuilder::end() {
	if (!Nodes$LongSpinedNodeBuilder::$assertionsDisabled && !this->building) {
		$throwNew($AssertionError, $of("was not building"_s));
	}
	this->building = false;
}

void Nodes$LongSpinedNodeBuilder::copyInto($longs* array, int32_t offset) {
	if (!Nodes$LongSpinedNodeBuilder::$assertionsDisabled && ! !this->building) {
		$throwNew($AssertionError, $of("during building"_s));
	}
	$SpinedBuffer$OfLong::copyInto(array, offset);
}

$Object* Nodes$LongSpinedNodeBuilder::asPrimitiveArray() {
	if (!Nodes$LongSpinedNodeBuilder::$assertionsDisabled && ! !this->building) {
		$throwNew($AssertionError, $of("during building"_s));
	}
	return $of($cast($longs, $SpinedBuffer$OfLong::asPrimitiveArray()));
}

$Node* Nodes$LongSpinedNodeBuilder::build() {
	if (!Nodes$LongSpinedNodeBuilder::$assertionsDisabled && ! !this->building) {
		$throwNew($AssertionError, $of("during building"_s));
	}
	return this;
}

void Nodes$LongSpinedNodeBuilder::forEach(Object$* consumer) {
	this->forEach($cast($LongConsumer, consumer));
}

void Nodes$LongSpinedNodeBuilder::copyInto(Object$* array, int32_t offset) {
	this->copyInto($cast($longs, array), offset);
}

void clinit$Nodes$LongSpinedNodeBuilder($Class* class$) {
	$load($Nodes);
	Nodes$LongSpinedNodeBuilder::$assertionsDisabled = !$Nodes::class$->desiredAssertionStatus();
}

Nodes$LongSpinedNodeBuilder::Nodes$LongSpinedNodeBuilder() {
}

$Class* Nodes$LongSpinedNodeBuilder::load$($String* name, bool initialize) {
	$loadClass(Nodes$LongSpinedNodeBuilder, name, initialize, &_Nodes$LongSpinedNodeBuilder_ClassInfo_, clinit$Nodes$LongSpinedNodeBuilder, allocate$Nodes$LongSpinedNodeBuilder);
	return class$;
}

$Class* Nodes$LongSpinedNodeBuilder::class$ = nullptr;

		} // stream
	} // util
} // java