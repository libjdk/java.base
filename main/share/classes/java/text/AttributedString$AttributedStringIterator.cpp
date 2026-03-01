#include <java/text/AttributedString$AttributedStringIterator.h>

#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/text/AttributedCharacterIterator$Attribute.h>
#include <java/text/AttributedCharacterIterator.h>
#include <java/text/AttributedString$AttributeMap.h>
#include <java/text/AttributedString.h>
#include <java/text/CharacterIterator.h>
#include <java/util/HashSet.h>
#include <java/util/Hashtable.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/Vector.h>
#include <jcpp.h>

#undef DONE

using $AttributedCharacterIterator$AttributeArray = $Array<::java::text::AttributedCharacterIterator$Attribute>;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $AttributedCharacterIterator = ::java::text::AttributedCharacterIterator;
using $AttributedCharacterIterator$Attribute = ::java::text::AttributedCharacterIterator$Attribute;
using $AttributedString = ::java::text::AttributedString;
using $AttributedString$AttributeMap = ::java::text::AttributedString$AttributeMap;
using $CharacterIterator = ::java::text::CharacterIterator;
using $HashSet = ::java::util::HashSet;
using $Hashtable = ::java::util::Hashtable;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $Vector = ::java::util::Vector;

namespace java {
	namespace text {

$FieldInfo _AttributedString$AttributedStringIterator_FieldInfo_[] = {
	{"this$0", "Ljava/text/AttributedString;", nullptr, $FINAL | $SYNTHETIC, $field(AttributedString$AttributedStringIterator, this$0)},
	{"beginIndex", "I", nullptr, $PRIVATE, $field(AttributedString$AttributedStringIterator, beginIndex)},
	{"endIndex", "I", nullptr, $PRIVATE, $field(AttributedString$AttributedStringIterator, endIndex)},
	{"relevantAttributes", "[Ljava/text/AttributedCharacterIterator$Attribute;", nullptr, $PRIVATE, $field(AttributedString$AttributedStringIterator, relevantAttributes)},
	{"currentIndex", "I", nullptr, $PRIVATE, $field(AttributedString$AttributedStringIterator, currentIndex)},
	{"currentRunIndex", "I", nullptr, $PRIVATE, $field(AttributedString$AttributedStringIterator, currentRunIndex)},
	{"currentRunStart", "I", nullptr, $PRIVATE, $field(AttributedString$AttributedStringIterator, currentRunStart)},
	{"currentRunLimit", "I", nullptr, $PRIVATE, $field(AttributedString$AttributedStringIterator, currentRunLimit)},
	{}
};

$MethodInfo _AttributedString$AttributedStringIterator_MethodInfo_[] = {
	{"<init>", "(Ljava/text/AttributedString;[Ljava/text/AttributedCharacterIterator$Attribute;II)V", nullptr, 0, $method(AttributedString$AttributedStringIterator, init$, void, $AttributedString*, $AttributedCharacterIterator$AttributeArray*, int32_t, int32_t)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, clone, $Object*)},
	{"current", "()C", nullptr, $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, current, char16_t)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, equals, bool, Object$*)},
	{"first", "()C", nullptr, $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, first, char16_t)},
	{"getAllAttributeKeys", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/text/AttributedCharacterIterator$Attribute;>;", $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, getAllAttributeKeys, $Set*)},
	{"getAttribute", "(Ljava/text/AttributedCharacterIterator$Attribute;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, getAttribute, $Object*, $AttributedCharacterIterator$Attribute*)},
	{"getAttributes", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/text/AttributedCharacterIterator$Attribute;Ljava/lang/Object;>;", $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, getAttributes, $Map*)},
	{"getBeginIndex", "()I", nullptr, $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, getBeginIndex, int32_t)},
	{"getEndIndex", "()I", nullptr, $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, getEndIndex, int32_t)},
	{"getIndex", "()I", nullptr, $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, getIndex, int32_t)},
	{"getRunLimit", "()I", nullptr, $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, getRunLimit, int32_t)},
	{"getRunLimit", "(Ljava/text/AttributedCharacterIterator$Attribute;)I", nullptr, $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, getRunLimit, int32_t, $AttributedCharacterIterator$Attribute*)},
	{"getRunLimit", "(Ljava/util/Set;)I", "(Ljava/util/Set<+Ljava/text/AttributedCharacterIterator$Attribute;>;)I", $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, getRunLimit, int32_t, $Set*)},
	{"getRunStart", "()I", nullptr, $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, getRunStart, int32_t)},
	{"getRunStart", "(Ljava/text/AttributedCharacterIterator$Attribute;)I", nullptr, $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, getRunStart, int32_t, $AttributedCharacterIterator$Attribute*)},
	{"getRunStart", "(Ljava/util/Set;)I", "(Ljava/util/Set<+Ljava/text/AttributedCharacterIterator$Attribute;>;)I", $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, getRunStart, int32_t, $Set*)},
	{"getString", "()Ljava/text/AttributedString;", nullptr, $PRIVATE, $method(AttributedString$AttributedStringIterator, getString, $AttributedString*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, hashCode, int32_t)},
	{"internalSetIndex", "(I)C", nullptr, $PRIVATE, $method(AttributedString$AttributedStringIterator, internalSetIndex, char16_t, int32_t)},
	{"last", "()C", nullptr, $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, last, char16_t)},
	{"next", "()C", nullptr, $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, next, char16_t)},
	{"previous", "()C", nullptr, $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, previous, char16_t)},
	{"setIndex", "(I)C", nullptr, $PUBLIC, $virtualMethod(AttributedString$AttributedStringIterator, setIndex, char16_t, int32_t)},
	{"updateRunInfo", "()V", nullptr, $PRIVATE, $method(AttributedString$AttributedStringIterator, updateRunInfo, void)},
	{}
};

$InnerClassInfo _AttributedString$AttributedStringIterator_InnerClassesInfo_[] = {
	{"java.text.AttributedString$AttributedStringIterator", "java.text.AttributedString", "AttributedStringIterator", $PRIVATE | $FINAL},
	{}
};

$ClassInfo _AttributedString$AttributedStringIterator_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.text.AttributedString$AttributedStringIterator",
	"java.lang.Object",
	"java.text.AttributedCharacterIterator",
	_AttributedString$AttributedStringIterator_FieldInfo_,
	_AttributedString$AttributedStringIterator_MethodInfo_,
	nullptr,
	nullptr,
	_AttributedString$AttributedStringIterator_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.text.AttributedString"
};

$Object* allocate$AttributedString$AttributedStringIterator($Class* clazz) {
	return $of($alloc(AttributedString$AttributedStringIterator));
}

void AttributedString$AttributedStringIterator::init$($AttributedString* this$0, $AttributedCharacterIterator$AttributeArray* attributes, int32_t beginIndex, int32_t endIndex) {
	$set(this, this$0, this$0);
	if (beginIndex < 0 || beginIndex > endIndex || endIndex > this$0->length()) {
		$throwNew($IllegalArgumentException, "Invalid substring range"_s);
	}
	this->beginIndex = beginIndex;
	this->endIndex = endIndex;
	this->currentIndex = beginIndex;
	updateRunInfo();
	if (attributes != nullptr) {
		$set(this, relevantAttributes, $cast($AttributedCharacterIterator$AttributeArray, attributes->clone()));
	}
}

bool AttributedString$AttributedStringIterator::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	$var(AttributedString$AttributedStringIterator, that, nullptr);
	bool var$0 = $instanceOf(AttributedString$AttributedStringIterator, obj);
	if (var$0) {
		$assign(that, $cast(AttributedString$AttributedStringIterator, obj));
		var$0 = true;
	}
	if (!(var$0)) {
		return false;
	}
	if (this->this$0 != $nc(that)->getString()) {
		return false;
	}
	if (this->currentIndex != $nc(that)->currentIndex || this->beginIndex != $nc(that)->beginIndex || this->endIndex != $nc(that)->endIndex) {
		return false;
	}
	return true;
}

int32_t AttributedString$AttributedStringIterator::hashCode() {
	return (($nc(this->this$0->text)->hashCode() ^ this->currentIndex) ^ this->beginIndex) ^ this->endIndex;
}

$Object* AttributedString$AttributedStringIterator::clone() {
	try {
		$var(AttributedString$AttributedStringIterator, other, $cast(AttributedString$AttributedStringIterator, $AttributedCharacterIterator::clone()));
		return $of(other);
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

char16_t AttributedString$AttributedStringIterator::first() {
	return internalSetIndex(this->beginIndex);
}

char16_t AttributedString$AttributedStringIterator::last() {
	if (this->endIndex == this->beginIndex) {
		return internalSetIndex(this->endIndex);
	} else {
		return internalSetIndex(this->endIndex - 1);
	}
}

char16_t AttributedString$AttributedStringIterator::current() {
	if (this->currentIndex == this->endIndex) {
		return $CharacterIterator::DONE;
	} else {
		return this->this$0->charAt(this->currentIndex);
	}
}

char16_t AttributedString$AttributedStringIterator::next() {
	if (this->currentIndex < this->endIndex) {
		return internalSetIndex(this->currentIndex + 1);
	} else {
		return $CharacterIterator::DONE;
	}
}

char16_t AttributedString$AttributedStringIterator::previous() {
	if (this->currentIndex > this->beginIndex) {
		return internalSetIndex(this->currentIndex - 1);
	} else {
		return $CharacterIterator::DONE;
	}
}

char16_t AttributedString$AttributedStringIterator::setIndex(int32_t position) {
	if (position < this->beginIndex || position > this->endIndex) {
		$throwNew($IllegalArgumentException, "Invalid index"_s);
	}
	return internalSetIndex(position);
}

int32_t AttributedString$AttributedStringIterator::getBeginIndex() {
	return this->beginIndex;
}

int32_t AttributedString$AttributedStringIterator::getEndIndex() {
	return this->endIndex;
}

int32_t AttributedString$AttributedStringIterator::getIndex() {
	return this->currentIndex;
}

int32_t AttributedString$AttributedStringIterator::getRunStart() {
	return this->currentRunStart;
}

int32_t AttributedString$AttributedStringIterator::getRunStart($AttributedCharacterIterator$Attribute* attribute) {
	$useLocalCurrentObjectStackCache();
	if (this->currentRunStart == this->beginIndex || this->currentRunIndex == -1) {
		return this->currentRunStart;
	} else {
		$var($Object, value, getAttribute(attribute));
		int32_t runStart = this->currentRunStart;
		int32_t runIndex = this->currentRunIndex;
		while (runStart > this->beginIndex && $AttributedString::valuesMatch(value, $(this->this$0->getAttribute(attribute, runIndex - 1)))) {
			--runIndex;
			runStart = $nc(this->this$0->runStarts)->get(runIndex);
		}
		if (runStart < this->beginIndex) {
			runStart = this->beginIndex;
		}
		return runStart;
	}
}

int32_t AttributedString$AttributedStringIterator::getRunStart($Set* attributes) {
	if (this->currentRunStart == this->beginIndex || this->currentRunIndex == -1) {
		return this->currentRunStart;
	} else {
		int32_t runStart = this->currentRunStart;
		int32_t runIndex = this->currentRunIndex;
		while (runStart > this->beginIndex && this->this$0->attributeValuesMatch(attributes, this->currentRunIndex, runIndex - 1)) {
			--runIndex;
			runStart = $nc(this->this$0->runStarts)->get(runIndex);
		}
		if (runStart < this->beginIndex) {
			runStart = this->beginIndex;
		}
		return runStart;
	}
}

int32_t AttributedString$AttributedStringIterator::getRunLimit() {
	return this->currentRunLimit;
}

int32_t AttributedString$AttributedStringIterator::getRunLimit($AttributedCharacterIterator$Attribute* attribute) {
	$useLocalCurrentObjectStackCache();
	if (this->currentRunLimit == this->endIndex || this->currentRunIndex == -1) {
		return this->currentRunLimit;
	} else {
		$var($Object, value, getAttribute(attribute));
		int32_t runLimit = this->currentRunLimit;
		int32_t runIndex = this->currentRunIndex;
		while (runLimit < this->endIndex && $AttributedString::valuesMatch(value, $(this->this$0->getAttribute(attribute, runIndex + 1)))) {
			++runIndex;
			runLimit = runIndex < this->this$0->runCount - 1 ? $nc(this->this$0->runStarts)->get(runIndex + 1) : this->endIndex;
		}
		if (runLimit > this->endIndex) {
			runLimit = this->endIndex;
		}
		return runLimit;
	}
}

int32_t AttributedString$AttributedStringIterator::getRunLimit($Set* attributes) {
	if (this->currentRunLimit == this->endIndex || this->currentRunIndex == -1) {
		return this->currentRunLimit;
	} else {
		int32_t runLimit = this->currentRunLimit;
		int32_t runIndex = this->currentRunIndex;
		while (runLimit < this->endIndex && this->this$0->attributeValuesMatch(attributes, this->currentRunIndex, runIndex + 1)) {
			++runIndex;
			runLimit = runIndex < this->this$0->runCount - 1 ? $nc(this->this$0->runStarts)->get(runIndex + 1) : this->endIndex;
		}
		if (runLimit > this->endIndex) {
			runLimit = this->endIndex;
		}
		return runLimit;
	}
}

$Map* AttributedString$AttributedStringIterator::getAttributes() {
	if (this->this$0->runAttributes == nullptr || this->currentRunIndex == -1 || $nc(this->this$0->runAttributes)->get(this->currentRunIndex) == nullptr) {
		return $new($Hashtable);
	}
	return $new($AttributedString$AttributeMap, this->this$0, this->currentRunIndex, this->beginIndex, this->endIndex);
}

$Set* AttributedString$AttributedStringIterator::getAllAttributeKeys() {
	$useLocalCurrentObjectStackCache();
	if (this->this$0->runAttributes == nullptr) {
		return $new($HashSet);
	}
	$synchronized(this->this$0) {
		$var($Set, keys, $new($HashSet));
		int32_t i = 0;
		while (i < this->this$0->runCount) {
			if ($nc(this->this$0->runStarts)->get(i) < this->endIndex && (i == this->this$0->runCount - 1 || $nc(this->this$0->runStarts)->get(i + 1) > this->beginIndex)) {
				$var($Vector, currentRunAttributes, $nc(this->this$0->runAttributes)->get(i));
				if (currentRunAttributes != nullptr) {
					int32_t j = currentRunAttributes->size();
					while (j-- > 0) {
						keys->add($cast($AttributedCharacterIterator$Attribute, $(currentRunAttributes->get(j))));
					}
				}
			}
			++i;
		}
		return keys;
	}
}

$Object* AttributedString$AttributedStringIterator::getAttribute($AttributedCharacterIterator$Attribute* attribute) {
	int32_t runIndex = this->currentRunIndex;
	if (runIndex < 0) {
		return $of(nullptr);
	}
	return $of(this->this$0->getAttributeCheckRange(attribute, runIndex, this->beginIndex, this->endIndex));
}

$AttributedString* AttributedString$AttributedStringIterator::getString() {
	return this->this$0;
}

char16_t AttributedString$AttributedStringIterator::internalSetIndex(int32_t position) {
	this->currentIndex = position;
	if (position < this->currentRunStart || position >= this->currentRunLimit) {
		updateRunInfo();
	}
	if (this->currentIndex == this->endIndex) {
		return $CharacterIterator::DONE;
	} else {
		return this->this$0->charAt(position);
	}
}

void AttributedString$AttributedStringIterator::updateRunInfo() {
	if (this->currentIndex == this->endIndex) {
		this->currentRunStart = (this->currentRunLimit = this->endIndex);
		this->currentRunIndex = -1;
	} else {
		$synchronized(this->this$0) {
			int32_t runIndex = -1;
			while (runIndex < this->this$0->runCount - 1 && $nc(this->this$0->runStarts)->get(runIndex + 1) <= this->currentIndex) {
				++runIndex;
			}
			this->currentRunIndex = runIndex;
			if (runIndex >= 0) {
				this->currentRunStart = $nc(this->this$0->runStarts)->get(runIndex);
				if (this->currentRunStart < this->beginIndex) {
					this->currentRunStart = this->beginIndex;
				}
			} else {
				this->currentRunStart = this->beginIndex;
			}
			if (runIndex < this->this$0->runCount - 1) {
				this->currentRunLimit = $nc(this->this$0->runStarts)->get(runIndex + 1);
				if (this->currentRunLimit > this->endIndex) {
					this->currentRunLimit = this->endIndex;
				}
			} else {
				this->currentRunLimit = this->endIndex;
			}
		}
	}
}

AttributedString$AttributedStringIterator::AttributedString$AttributedStringIterator() {
}

$Class* AttributedString$AttributedStringIterator::load$($String* name, bool initialize) {
	$loadClass(AttributedString$AttributedStringIterator, name, initialize, &_AttributedString$AttributedStringIterator_ClassInfo_, allocate$AttributedString$AttributedStringIterator);
	return class$;
}

$Class* AttributedString$AttributedStringIterator::class$ = nullptr;

	} // text
} // java