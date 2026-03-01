#include <java/util/EnumMap$Values.h>

#include <java/util/AbstractCollection.h>
#include <java/util/EnumMap$ValueIterator.h>
#include <java/util/EnumMap.h>
#include <java/util/Iterator.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractCollection = ::java::util::AbstractCollection;
using $EnumMap = ::java::util::EnumMap;
using $EnumMap$ValueIterator = ::java::util::EnumMap$ValueIterator;
using $Iterator = ::java::util::Iterator;

namespace java {
	namespace util {

$FieldInfo _EnumMap$Values_FieldInfo_[] = {
	{"this$0", "Ljava/util/EnumMap;", nullptr, $FINAL | $SYNTHETIC, $field(EnumMap$Values, this$0)},
	{}
};

$MethodInfo _EnumMap$Values_MethodInfo_[] = {
	{"<init>", "(Ljava/util/EnumMap;)V", nullptr, $PRIVATE, $method(EnumMap$Values, init$, void, $EnumMap*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(EnumMap$Values, clear, void)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(EnumMap$Values, contains, bool, Object$*)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TV;>;", $PUBLIC, $virtualMethod(EnumMap$Values, iterator, $Iterator*)},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(EnumMap$Values, remove, bool, Object$*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(EnumMap$Values, size, int32_t)},
	{}
};

$InnerClassInfo _EnumMap$Values_InnerClassesInfo_[] = {
	{"java.util.EnumMap$Values", "java.util.EnumMap", "Values", $PRIVATE},
	{}
};

$ClassInfo _EnumMap$Values_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.EnumMap$Values",
	"java.util.AbstractCollection",
	nullptr,
	_EnumMap$Values_FieldInfo_,
	_EnumMap$Values_MethodInfo_,
	"Ljava/util/AbstractCollection<TV;>;",
	nullptr,
	_EnumMap$Values_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.EnumMap"
};

$Object* allocate$EnumMap$Values($Class* clazz) {
	return $of($alloc(EnumMap$Values));
}

void EnumMap$Values::init$($EnumMap* this$0) {
	$set(this, this$0, this$0);
	$AbstractCollection::init$();
}

$Iterator* EnumMap$Values::iterator() {
	return $new($EnumMap$ValueIterator, this->this$0);
}

int32_t EnumMap$Values::size() {
	return this->this$0->size$;
}

bool EnumMap$Values::contains(Object$* o) {
	return this->this$0->containsValue(o);
}

bool EnumMap$Values::remove(Object$* o$renamed) {
	$var($Object, o, o$renamed);
	$assign(o, this->this$0->maskNull(o));
	for (int32_t i = 0; i < $nc(this->this$0->vals)->length; ++i) {
		if ($nc($of(o))->equals($nc(this->this$0->vals)->get(i))) {
			$nc(this->this$0->vals)->set(i, nullptr);
			--this->this$0->size$;
			return true;
		}
	}
	return false;
}

void EnumMap$Values::clear() {
	this->this$0->clear();
}

EnumMap$Values::EnumMap$Values() {
}

$Class* EnumMap$Values::load$($String* name, bool initialize) {
	$loadClass(EnumMap$Values, name, initialize, &_EnumMap$Values_ClassInfo_, allocate$EnumMap$Values);
	return class$;
}

$Class* EnumMap$Values::class$ = nullptr;

	} // util
} // java