#include <java/text/AttributedString$AttributeMap.h>

#include <java/text/Annotation.h>
#include <java/text/AttributeEntry.h>
#include <java/text/AttributedCharacterIterator$Attribute.h>
#include <java/text/AttributedString.h>
#include <java/util/AbstractMap.h>
#include <java/util/HashSet.h>
#include <java/util/Map$Entry.h>
#include <java/util/Set.h>
#include <java/util/Vector.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Annotation = ::java::text::Annotation;
using $AttributeEntry = ::java::text::AttributeEntry;
using $AttributedCharacterIterator$Attribute = ::java::text::AttributedCharacterIterator$Attribute;
using $AttributedString = ::java::text::AttributedString;
using $AbstractMap = ::java::util::AbstractMap;
using $HashSet = ::java::util::HashSet;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $Vector = ::java::util::Vector;

namespace java {
	namespace text {

$FieldInfo _AttributedString$AttributeMap_FieldInfo_[] = {
	{"this$0", "Ljava/text/AttributedString;", nullptr, $FINAL | $SYNTHETIC, $field(AttributedString$AttributeMap, this$0)},
	{"runIndex", "I", nullptr, 0, $field(AttributedString$AttributeMap, runIndex)},
	{"beginIndex", "I", nullptr, 0, $field(AttributedString$AttributeMap, beginIndex)},
	{"endIndex", "I", nullptr, 0, $field(AttributedString$AttributeMap, endIndex)},
	{}
};

$MethodInfo _AttributedString$AttributeMap_MethodInfo_[] = {
	{"<init>", "(Ljava/text/AttributedString;III)V", nullptr, 0, $method(AttributedString$AttributeMap, init$, void, $AttributedString*, int32_t, int32_t, int32_t)},
	{"entrySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/util/Map$Entry<Ljava/text/AttributedCharacterIterator$Attribute;Ljava/lang/Object;>;>;", $PUBLIC, $virtualMethod(AttributedString$AttributeMap, entrySet, $Set*)},
	{"get", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(AttributedString$AttributeMap, get, $Object*, Object$*)},
	{}
};

$InnerClassInfo _AttributedString$AttributeMap_InnerClassesInfo_[] = {
	{"java.text.AttributedString$AttributeMap", "java.text.AttributedString", "AttributeMap", $PRIVATE | $FINAL},
	{"java.text.AttributedCharacterIterator$Attribute", "java.text.AttributedCharacterIterator", "Attribute", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _AttributedString$AttributeMap_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.text.AttributedString$AttributeMap",
	"java.util.AbstractMap",
	nullptr,
	_AttributedString$AttributeMap_FieldInfo_,
	_AttributedString$AttributeMap_MethodInfo_,
	"Ljava/util/AbstractMap<Ljava/text/AttributedCharacterIterator$Attribute;Ljava/lang/Object;>;",
	nullptr,
	_AttributedString$AttributeMap_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.text.AttributedString"
};

$Object* allocate$AttributedString$AttributeMap($Class* clazz) {
	return $of($alloc(AttributedString$AttributeMap));
}

void AttributedString$AttributeMap::init$($AttributedString* this$0, int32_t runIndex, int32_t beginIndex, int32_t endIndex) {
	$set(this, this$0, this$0);
	$AbstractMap::init$();
	this->runIndex = runIndex;
	this->beginIndex = beginIndex;
	this->endIndex = endIndex;
}

$Set* AttributedString$AttributeMap::entrySet() {
	$useLocalCurrentObjectStackCache();
	$var($HashSet, set, $new($HashSet));
	$synchronized(this->this$0) {
		int32_t size = $nc($nc(this->this$0->runAttributes)->get(this->runIndex))->size();
		for (int32_t i = 0; i < size; ++i) {
			$var($AttributedCharacterIterator$Attribute, key, $cast($AttributedCharacterIterator$Attribute, $nc($nc(this->this$0->runAttributes)->get(this->runIndex))->get(i)));
			$var($Object, value, $nc($nc(this->this$0->runAttributeValues)->get(this->runIndex))->get(i));
			if ($instanceOf($Annotation, value)) {
				$assign(value, this->this$0->getAttributeCheckRange(key, this->runIndex, this->beginIndex, this->endIndex));
				if (value == nullptr) {
					continue;
				}
			}
			$var($Map$Entry, entry, $new($AttributeEntry, key, value));
			set->add(entry);
		}
	}
	return set;
}

$Object* AttributedString$AttributeMap::get(Object$* key) {
	return $of(this->this$0->getAttributeCheckRange($cast($AttributedCharacterIterator$Attribute, key), this->runIndex, this->beginIndex, this->endIndex));
}

AttributedString$AttributeMap::AttributedString$AttributeMap() {
}

$Class* AttributedString$AttributeMap::load$($String* name, bool initialize) {
	$loadClass(AttributedString$AttributeMap, name, initialize, &_AttributedString$AttributeMap_ClassInfo_, allocate$AttributedString$AttributeMap);
	return class$;
}

$Class* AttributedString$AttributeMap::class$ = nullptr;

	} // text
} // java