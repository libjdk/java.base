#include <sun/text/DictionaryBasedBreakIterator.h>

#include <java/text/CharacterIterator.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <java/util/Stack.h>
#include <sun/text/BreakDictionary.h>
#include <sun/text/RuleBasedBreakIterator.h>
#include <jcpp.h>

#undef IGNORE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $CharacterIterator = ::java::text::CharacterIterator;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $Stack = ::java::util::Stack;
using $BreakDictionary = ::sun::text::BreakDictionary;
using $RuleBasedBreakIterator = ::sun::text::RuleBasedBreakIterator;

namespace sun {
	namespace text {

$FieldInfo _DictionaryBasedBreakIterator_FieldInfo_[] = {
	{"dictionary", "Lsun/text/BreakDictionary;", nullptr, $PRIVATE, $field(DictionaryBasedBreakIterator, dictionary)},
	{"categoryFlags", "[Z", nullptr, $PRIVATE, $field(DictionaryBasedBreakIterator, categoryFlags)},
	{"dictionaryCharCount", "I", nullptr, $PRIVATE, $field(DictionaryBasedBreakIterator, dictionaryCharCount)},
	{"cachedBreakPositions", "[I", nullptr, $PRIVATE, $field(DictionaryBasedBreakIterator, cachedBreakPositions)},
	{"positionInCache", "I", nullptr, $PRIVATE, $field(DictionaryBasedBreakIterator, positionInCache)},
	{}
};

$MethodInfo _DictionaryBasedBreakIterator_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;[BLjava/lang/String;[B)V", nullptr, $PUBLIC, $method(DictionaryBasedBreakIterator, init$, void, $String*, $bytes*, $String*, $bytes*)},
	{"divideUpDictionaryRange", "(II)V", nullptr, $PRIVATE, $method(DictionaryBasedBreakIterator, divideUpDictionaryRange, void, int32_t, int32_t)},
	{"first", "()I", nullptr, $PUBLIC, $virtualMethod(DictionaryBasedBreakIterator, first, int32_t)},
	{"following", "(I)I", nullptr, $PUBLIC, $virtualMethod(DictionaryBasedBreakIterator, following, int32_t, int32_t)},
	{"handleNext", "()I", nullptr, $PROTECTED, $virtualMethod(DictionaryBasedBreakIterator, handleNext, int32_t)},
	{"last", "()I", nullptr, $PUBLIC, $virtualMethod(DictionaryBasedBreakIterator, last, int32_t)},
	{"lookupCategory", "(I)I", nullptr, $PROTECTED, $virtualMethod(DictionaryBasedBreakIterator, lookupCategory, int32_t, int32_t)},
	{"preceding", "(I)I", nullptr, $PUBLIC, $virtualMethod(DictionaryBasedBreakIterator, preceding, int32_t, int32_t)},
	{"prepareCategoryFlags", "([B)V", nullptr, $PRIVATE, $method(DictionaryBasedBreakIterator, prepareCategoryFlags, void, $bytes*)},
	{"previous", "()I", nullptr, $PUBLIC, $virtualMethod(DictionaryBasedBreakIterator, previous, int32_t)},
	{"setText", "(Ljava/text/CharacterIterator;)V", nullptr, $PUBLIC, $virtualMethod(DictionaryBasedBreakIterator, setText, void, $CharacterIterator*)},
	{}
};

$ClassInfo _DictionaryBasedBreakIterator_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.text.DictionaryBasedBreakIterator",
	"sun.text.RuleBasedBreakIterator",
	nullptr,
	_DictionaryBasedBreakIterator_FieldInfo_,
	_DictionaryBasedBreakIterator_MethodInfo_
};

$Object* allocate$DictionaryBasedBreakIterator($Class* clazz) {
	return $of($alloc(DictionaryBasedBreakIterator));
}

void DictionaryBasedBreakIterator::init$($String* ruleFile, $bytes* ruleData, $String* dictionaryFile, $bytes* dictionaryData) {
	$RuleBasedBreakIterator::init$(ruleFile, ruleData);
	$var($bytes, tmp, $RuleBasedBreakIterator::getAdditionalData());
	if (tmp != nullptr) {
		prepareCategoryFlags(tmp);
		$RuleBasedBreakIterator::setAdditionalData(nullptr);
	}
	$set(this, dictionary, $new($BreakDictionary, dictionaryFile, dictionaryData));
}

void DictionaryBasedBreakIterator::prepareCategoryFlags($bytes* data) {
	$set(this, categoryFlags, $new($booleans, $nc(data)->length));
	for (int32_t i = 0; i < data->length; ++i) {
		$nc(this->categoryFlags)->set(i, (data->get(i) == (int8_t)1) ? true : false);
	}
}

void DictionaryBasedBreakIterator::setText($CharacterIterator* newText) {
	$RuleBasedBreakIterator::setText(newText);
	$set(this, cachedBreakPositions, nullptr);
	this->dictionaryCharCount = 0;
	this->positionInCache = 0;
}

int32_t DictionaryBasedBreakIterator::first() {
	$set(this, cachedBreakPositions, nullptr);
	this->dictionaryCharCount = 0;
	this->positionInCache = 0;
	return $RuleBasedBreakIterator::first();
}

int32_t DictionaryBasedBreakIterator::last() {
	$set(this, cachedBreakPositions, nullptr);
	this->dictionaryCharCount = 0;
	this->positionInCache = 0;
	return $RuleBasedBreakIterator::last();
}

int32_t DictionaryBasedBreakIterator::previous() {
	$var($CharacterIterator, text, getText());
	if (this->cachedBreakPositions != nullptr && this->positionInCache > 0) {
		--this->positionInCache;
		$nc(text)->setIndex($nc(this->cachedBreakPositions)->get(this->positionInCache));
		return $nc(this->cachedBreakPositions)->get(this->positionInCache);
	} else {
		$set(this, cachedBreakPositions, nullptr);
		int32_t result = $RuleBasedBreakIterator::previous();
		if (this->cachedBreakPositions != nullptr) {
			this->positionInCache = $nc(this->cachedBreakPositions)->length - 2;
		}
		return result;
	}
}

int32_t DictionaryBasedBreakIterator::preceding(int32_t offset) {
	$var($CharacterIterator, text, getText());
	checkOffset(offset, text);
	if (this->cachedBreakPositions == nullptr || offset <= $nc(this->cachedBreakPositions)->get(0) || offset > $nc(this->cachedBreakPositions)->get($nc(this->cachedBreakPositions)->length - 1)) {
		$set(this, cachedBreakPositions, nullptr);
		return $RuleBasedBreakIterator::preceding(offset);
	} else {
		this->positionInCache = 0;
		while (this->positionInCache < $nc(this->cachedBreakPositions)->length && offset > $nc(this->cachedBreakPositions)->get(this->positionInCache)) {
			++this->positionInCache;
		}
		--this->positionInCache;
		$nc(text)->setIndex($nc(this->cachedBreakPositions)->get(this->positionInCache));
		return text->getIndex();
	}
}

int32_t DictionaryBasedBreakIterator::following(int32_t offset) {
	$var($CharacterIterator, text, getText());
	checkOffset(offset, text);
	if (this->cachedBreakPositions == nullptr || offset < $nc(this->cachedBreakPositions)->get(0) || offset >= $nc(this->cachedBreakPositions)->get($nc(this->cachedBreakPositions)->length - 1)) {
		$set(this, cachedBreakPositions, nullptr);
		return $RuleBasedBreakIterator::following(offset);
	} else {
		this->positionInCache = 0;
		while (this->positionInCache < $nc(this->cachedBreakPositions)->length && offset >= $nc(this->cachedBreakPositions)->get(this->positionInCache)) {
			++this->positionInCache;
		}
		$nc(text)->setIndex($nc(this->cachedBreakPositions)->get(this->positionInCache));
		return text->getIndex();
	}
}

int32_t DictionaryBasedBreakIterator::handleNext() {
	$var($CharacterIterator, text, getText());
	if (this->cachedBreakPositions == nullptr || this->positionInCache == $nc(this->cachedBreakPositions)->length - 1) {
		int32_t startPos = $nc(text)->getIndex();
		this->dictionaryCharCount = 0;
		int32_t result = $RuleBasedBreakIterator::handleNext();
		if (this->dictionaryCharCount > 1 && result - startPos > 1) {
			divideUpDictionaryRange(startPos, result);
		} else {
			$set(this, cachedBreakPositions, nullptr);
			return result;
		}
	}
	if (this->cachedBreakPositions != nullptr) {
		++this->positionInCache;
		$nc(text)->setIndex($nc(this->cachedBreakPositions)->get(this->positionInCache));
		return $nc(this->cachedBreakPositions)->get(this->positionInCache);
	}
	return -9999;
}

int32_t DictionaryBasedBreakIterator::lookupCategory(int32_t c) {
	int32_t result = $RuleBasedBreakIterator::lookupCategory(c);
	if (result != $RuleBasedBreakIterator::IGNORE && $nc(this->categoryFlags)->get(result)) {
		++this->dictionaryCharCount;
	}
	return result;
}

void DictionaryBasedBreakIterator::divideUpDictionaryRange(int32_t startPos, int32_t endPos) {
	$useLocalCurrentObjectStackCache();
	$var($CharacterIterator, text, getText());
	$nc(text)->setIndex(startPos);
	int32_t c = getCurrent();
	int32_t category = lookupCategory(c);
	while (category == $RuleBasedBreakIterator::IGNORE || !$nc(this->categoryFlags)->get(category)) {
		c = getNext();
		category = lookupCategory(c);
	}
	$var($Stack, currentBreakPositions, $new($Stack));
	$var($Stack, possibleBreakPositions, $new($Stack));
	$var($List, wrongBreakPositions, $new($ArrayList));
	int32_t state = 0;
	int32_t farthestEndPoint = text->getIndex();
	$var($Stack, bestBreakPositions, nullptr);
	c = getCurrent();
	while (true) {
		if ($nc(this->dictionary)->getNextState(state, 0) == -1) {
			possibleBreakPositions->push($($Integer::valueOf(text->getIndex())));
		}
		state = $nc(this->dictionary)->getNextStateFromCharacter(state, c);
		if (state == -1) {
			$nc(currentBreakPositions)->push($($Integer::valueOf(text->getIndex())));
			break;
		} else if (state == 0 || text->getIndex() >= endPos) {
			if (text->getIndex() > farthestEndPoint) {
				farthestEndPoint = text->getIndex();
				$var($Stack, currentBreakPositionsCopy, $cast($Stack, $nc(currentBreakPositions)->clone()));
				$assign(bestBreakPositions, currentBreakPositionsCopy);
			}
			while (true) {
				bool var$0 = !possibleBreakPositions->isEmpty();
				if (!(var$0 && wrongBreakPositions->contains($(possibleBreakPositions->peek())))) {
					break;
				}
				{
					possibleBreakPositions->pop();
				}
			}
			if (possibleBreakPositions->isEmpty()) {
				if (bestBreakPositions != nullptr) {
					$assign(currentBreakPositions, bestBreakPositions);
					if (farthestEndPoint < endPos) {
						text->setIndex(farthestEndPoint + 1);
					} else {
						break;
					}
				} else {
					bool var$2 = $nc(currentBreakPositions)->size() == 0;
					if (!var$2) {
						int32_t var$3 = $nc(($cast($Integer, $($nc(currentBreakPositions)->peek()))))->intValue();
						var$2 = var$3 != text->getIndex();
					}
					bool var$1 = (var$2);
					if (var$1 && text->getIndex() != startPos) {
						currentBreakPositions->push($($Integer::valueOf(text->getIndex())));
					}
					getNext();
					$nc(currentBreakPositions)->push($($Integer::valueOf(text->getIndex())));
				}
			} else {
				$var($Integer, temp, $cast($Integer, possibleBreakPositions->pop()));
				$var($Integer, temp2, nullptr);
				while (true) {
					bool var$4 = !$nc(currentBreakPositions)->isEmpty();
					if (var$4) {
						int32_t var$5 = $nc(temp)->intValue();
						var$4 = var$5 < $nc(($cast($Integer, $(currentBreakPositions->peek()))))->intValue();
					}
					if (!(var$4)) {
						break;
					}
					{
						$assign(temp2, $cast($Integer, currentBreakPositions->pop()));
						wrongBreakPositions->add(temp2);
					}
				}
				$nc(currentBreakPositions)->push(temp);
				text->setIndex($nc(($cast($Integer, $(currentBreakPositions->peek()))))->intValue());
			}
			c = getCurrent();
			if (text->getIndex() >= endPos) {
				break;
			}
		} else {
			c = getNext();
		}
	}
	if (!$nc(currentBreakPositions)->isEmpty()) {
		currentBreakPositions->pop();
	}
	$nc(currentBreakPositions)->push($($Integer::valueOf(endPos)));
	$set(this, cachedBreakPositions, $new($ints, currentBreakPositions->size() + 1));
	$nc(this->cachedBreakPositions)->set(0, startPos);
	for (int32_t i = 0; i < currentBreakPositions->size(); ++i) {
		$nc(this->cachedBreakPositions)->set(i + 1, $nc(($cast($Integer, $(currentBreakPositions->elementAt(i)))))->intValue());
	}
	this->positionInCache = 0;
}

DictionaryBasedBreakIterator::DictionaryBasedBreakIterator() {
}

$Class* DictionaryBasedBreakIterator::load$($String* name, bool initialize) {
	$loadClass(DictionaryBasedBreakIterator, name, initialize, &_DictionaryBasedBreakIterator_ClassInfo_, allocate$DictionaryBasedBreakIterator);
	return class$;
}

$Class* DictionaryBasedBreakIterator::class$ = nullptr;

	} // text
} // sun