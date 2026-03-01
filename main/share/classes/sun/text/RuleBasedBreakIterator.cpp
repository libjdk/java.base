#include <sun/text/RuleBasedBreakIterator.h>

#include <java/lang/AssertionError.h>
#include <java/lang/ClassCastException.h>
#include <java/nio/BufferUnderflowException.h>
#include <java/nio/ByteBuffer.h>
#include <java/text/BreakIterator.h>
#include <java/text/CharacterIterator.h>
#include <java/text/StringCharacterIterator.h>
#include <java/util/MissingResourceException.h>
#include <sun/text/CompactByteArray.h>
#include <sun/text/RuleBasedBreakIterator$SafeCharIterator.h>
#include <sun/text/SupplementaryCharacterData.h>
#include <jcpp.h>

#undef BMP_INDICES_LENGTH
#undef DONE
#undef IGNORE
#undef LABEL
#undef LABEL_LENGTH
#undef MIN_SUPPLEMENTARY_CODE_POINT
#undef START_STATE
#undef STOP_STATE

using $AssertionError = ::java::lang::AssertionError;
using $Character = ::java::lang::Character;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $BufferUnderflowException = ::java::nio::BufferUnderflowException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $BreakIterator = ::java::text::BreakIterator;
using $CharacterIterator = ::java::text::CharacterIterator;
using $StringCharacterIterator = ::java::text::StringCharacterIterator;
using $MissingResourceException = ::java::util::MissingResourceException;
using $CompactByteArray = ::sun::text::CompactByteArray;
using $RuleBasedBreakIterator$SafeCharIterator = ::sun::text::RuleBasedBreakIterator$SafeCharIterator;
using $SupplementaryCharacterData = ::sun::text::SupplementaryCharacterData;

namespace sun {
	namespace text {

$FieldInfo _RuleBasedBreakIterator_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(RuleBasedBreakIterator, $assertionsDisabled)},
	{"IGNORE", "B", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(RuleBasedBreakIterator, IGNORE)},
	{"START_STATE", "S", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RuleBasedBreakIterator, START_STATE)},
	{"STOP_STATE", "S", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RuleBasedBreakIterator, STOP_STATE)},
	{"LABEL", "[B", nullptr, $STATIC | $FINAL, $staticField(RuleBasedBreakIterator, LABEL)},
	{"LABEL_LENGTH", "I", nullptr, $STATIC | $FINAL, $staticField(RuleBasedBreakIterator, LABEL_LENGTH)},
	{"supportedVersion", "B", nullptr, $STATIC | $FINAL, $constField(RuleBasedBreakIterator, supportedVersion)},
	{"BMP_INDICES_LENGTH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RuleBasedBreakIterator, BMP_INDICES_LENGTH)},
	{"charCategoryTable", "Lsun/text/CompactByteArray;", nullptr, $PRIVATE, $field(RuleBasedBreakIterator, charCategoryTable)},
	{"supplementaryCharCategoryTable", "Lsun/text/SupplementaryCharacterData;", nullptr, $PRIVATE, $field(RuleBasedBreakIterator, supplementaryCharCategoryTable)},
	{"stateTable", "[S", nullptr, $PRIVATE, $field(RuleBasedBreakIterator, stateTable)},
	{"backwardsStateTable", "[S", nullptr, $PRIVATE, $field(RuleBasedBreakIterator, backwardsStateTable)},
	{"endStates", "[Z", nullptr, $PRIVATE, $field(RuleBasedBreakIterator, endStates)},
	{"lookaheadStates", "[Z", nullptr, $PRIVATE, $field(RuleBasedBreakIterator, lookaheadStates)},
	{"additionalData", "[B", nullptr, $PRIVATE, $field(RuleBasedBreakIterator, additionalData)},
	{"numCategories", "I", nullptr, $PRIVATE, $field(RuleBasedBreakIterator, numCategories)},
	{"text", "Ljava/text/CharacterIterator;", nullptr, $PRIVATE, $field(RuleBasedBreakIterator, text)},
	{"checksum", "J", nullptr, $PRIVATE, $field(RuleBasedBreakIterator, checksum)},
	{"cachedLastKnownBreak", "I", nullptr, $PRIVATE, $field(RuleBasedBreakIterator, cachedLastKnownBreak)},
	{}
};

$MethodInfo _RuleBasedBreakIterator_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;[B)V", nullptr, $PUBLIC, $method(RuleBasedBreakIterator, init$, void, $String*, $bytes*)},
	{"checkOffset", "(ILjava/text/CharacterIterator;)V", nullptr, $PROTECTED | $STATIC | $FINAL, $staticMethod(RuleBasedBreakIterator, checkOffset, void, int32_t, $CharacterIterator*)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(RuleBasedBreakIterator, clone, $Object*)},
	{"current", "()I", nullptr, $PUBLIC, $virtualMethod(RuleBasedBreakIterator, current, int32_t)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(RuleBasedBreakIterator, equals, bool, Object$*)},
	{"first", "()I", nullptr, $PUBLIC, $virtualMethod(RuleBasedBreakIterator, first, int32_t)},
	{"following", "(I)I", nullptr, $PUBLIC, $virtualMethod(RuleBasedBreakIterator, following, int32_t, int32_t)},
	{"getAdditionalData", "()[B", nullptr, 0, $virtualMethod(RuleBasedBreakIterator, getAdditionalData, $bytes*)},
	{"getCurrent", "()I", nullptr, 0, $virtualMethod(RuleBasedBreakIterator, getCurrent, int32_t)},
	{"getCurrentCodePointCount", "()I", nullptr, $PRIVATE, $method(RuleBasedBreakIterator, getCurrentCodePointCount, int32_t)},
	{"getNext", "()I", nullptr, 0, $virtualMethod(RuleBasedBreakIterator, getNext, int32_t)},
	{"getNextIndex", "()I", nullptr, $PRIVATE, $method(RuleBasedBreakIterator, getNextIndex, int32_t)},
	{"getPrevious", "()I", nullptr, $PRIVATE, $method(RuleBasedBreakIterator, getPrevious, int32_t)},
	{"getText", "()Ljava/text/CharacterIterator;", nullptr, $PUBLIC, $virtualMethod(RuleBasedBreakIterator, getText, $CharacterIterator*)},
	{"handleNext", "()I", nullptr, $PROTECTED, $virtualMethod(RuleBasedBreakIterator, handleNext, int32_t)},
	{"handlePrevious", "()I", nullptr, $PROTECTED, $virtualMethod(RuleBasedBreakIterator, handlePrevious, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(RuleBasedBreakIterator, hashCode, int32_t)},
	{"isBoundary", "(I)Z", nullptr, $PUBLIC, $virtualMethod(RuleBasedBreakIterator, isBoundary, bool, int32_t)},
	{"last", "()I", nullptr, $PUBLIC, $virtualMethod(RuleBasedBreakIterator, last, int32_t)},
	{"lookupBackwardState", "(II)I", nullptr, $PROTECTED, $virtualMethod(RuleBasedBreakIterator, lookupBackwardState, int32_t, int32_t, int32_t)},
	{"lookupCategory", "(I)I", nullptr, $PROTECTED, $virtualMethod(RuleBasedBreakIterator, lookupCategory, int32_t, int32_t)},
	{"lookupState", "(II)I", nullptr, $PROTECTED, $virtualMethod(RuleBasedBreakIterator, lookupState, int32_t, int32_t, int32_t)},
	{"next", "(I)I", nullptr, $PUBLIC, $virtualMethod(RuleBasedBreakIterator, next, int32_t, int32_t)},
	{"next", "()I", nullptr, $PUBLIC, $virtualMethod(RuleBasedBreakIterator, next, int32_t)},
	{"preceding", "(I)I", nullptr, $PUBLIC, $virtualMethod(RuleBasedBreakIterator, preceding, int32_t, int32_t)},
	{"previous", "()I", nullptr, $PUBLIC, $virtualMethod(RuleBasedBreakIterator, previous, int32_t)},
	{"setAdditionalData", "([B)V", nullptr, 0, $virtualMethod(RuleBasedBreakIterator, setAdditionalData, void, $bytes*)},
	{"setText", "(Ljava/text/CharacterIterator;)V", nullptr, $PUBLIC, $virtualMethod(RuleBasedBreakIterator, setText, void, $CharacterIterator*)},
	{"setupTables", "(Ljava/lang/String;Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(RuleBasedBreakIterator, setupTables, void, $String*, $ByteBuffer*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(RuleBasedBreakIterator, toString, $String*)},
	{"validateRuleData", "(Ljava/lang/String;Ljava/nio/ByteBuffer;)V", nullptr, 0, $virtualMethod(RuleBasedBreakIterator, validateRuleData, void, $String*, $ByteBuffer*)},
	{}
};

$InnerClassInfo _RuleBasedBreakIterator_InnerClassesInfo_[] = {
	{"sun.text.RuleBasedBreakIterator$SafeCharIterator", "sun.text.RuleBasedBreakIterator", "SafeCharIterator", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _RuleBasedBreakIterator_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.text.RuleBasedBreakIterator",
	"java.text.BreakIterator",
	nullptr,
	_RuleBasedBreakIterator_FieldInfo_,
	_RuleBasedBreakIterator_MethodInfo_,
	nullptr,
	nullptr,
	_RuleBasedBreakIterator_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.text.RuleBasedBreakIterator$SafeCharIterator"
};

$Object* allocate$RuleBasedBreakIterator($Class* clazz) {
	return $of($alloc(RuleBasedBreakIterator));
}

bool RuleBasedBreakIterator::$assertionsDisabled = false;
$bytes* RuleBasedBreakIterator::LABEL = nullptr;
int32_t RuleBasedBreakIterator::LABEL_LENGTH = 0;

void RuleBasedBreakIterator::init$($String* ruleFile, $bytes* ruleData) {
	$useLocalCurrentObjectStackCache();
	$BreakIterator::init$();
	$set(this, charCategoryTable, nullptr);
	$set(this, supplementaryCharCategoryTable, nullptr);
	$set(this, stateTable, nullptr);
	$set(this, backwardsStateTable, nullptr);
	$set(this, endStates, nullptr);
	$set(this, lookaheadStates, nullptr);
	$set(this, additionalData, nullptr);
	$set(this, text, nullptr);
	this->cachedLastKnownBreak = $BreakIterator::DONE;
	$var($ByteBuffer, bb, $ByteBuffer::wrap(ruleData));
	try {
		validateRuleData(ruleFile, bb);
		setupTables(ruleFile, bb);
	} catch ($BufferUnderflowException& bue) {
		$var($MissingResourceException, e, nullptr);
		$assign(e, $new($MissingResourceException, "Corrupted rule data file"_s, ruleFile, ""_s));
		e->initCause(bue);
		$throw(e);
	}
}

void RuleBasedBreakIterator::setupTables($String* ruleFile, $ByteBuffer* bb) {
	$useLocalCurrentObjectStackCache();
	int32_t stateTableLength = $nc(bb)->getInt();
	int32_t backwardsStateTableLength = bb->getInt();
	int32_t endStatesLength = bb->getInt();
	int32_t lookaheadStatesLength = bb->getInt();
	int32_t BMPdataLength = bb->getInt();
	int32_t nonBMPdataLength = bb->getInt();
	int32_t additionalDataLength = bb->getInt();
	this->checksum = bb->getLong();
	$set(this, stateTable, $new($shorts, stateTableLength));
	for (int32_t i = 0; i < stateTableLength; ++i) {
		$nc(this->stateTable)->set(i, bb->getShort());
	}
	$set(this, backwardsStateTable, $new($shorts, backwardsStateTableLength));
	for (int32_t i = 0; i < backwardsStateTableLength; ++i) {
		$nc(this->backwardsStateTable)->set(i, bb->getShort());
	}
	$set(this, endStates, $new($booleans, endStatesLength));
	for (int32_t i = 0; i < endStatesLength; ++i) {
		$nc(this->endStates)->set(i, bb->get() == 1);
	}
	$set(this, lookaheadStates, $new($booleans, lookaheadStatesLength));
	for (int32_t i = 0; i < lookaheadStatesLength; ++i) {
		$nc(this->lookaheadStates)->set(i, bb->get() == 1);
	}
	$var($shorts, temp1, $new($shorts, RuleBasedBreakIterator::BMP_INDICES_LENGTH));
	for (int32_t i = 0; i < RuleBasedBreakIterator::BMP_INDICES_LENGTH; ++i) {
		temp1->set(i, bb->getShort());
	}
	$var($bytes, temp2, $new($bytes, BMPdataLength));
	bb->get(temp2);
	$set(this, charCategoryTable, $new($CompactByteArray, temp1, temp2));
	$var($ints, temp3, $new($ints, nonBMPdataLength));
	for (int32_t i = 0; i < nonBMPdataLength; ++i) {
		temp3->set(i, bb->getInt());
	}
	$set(this, supplementaryCharCategoryTable, $new($SupplementaryCharacterData, temp3));
	if (additionalDataLength > 0) {
		$set(this, additionalData, $new($bytes, additionalDataLength));
		bb->get(this->additionalData);
	}
	bool var$0 = !RuleBasedBreakIterator::$assertionsDisabled;
	if (var$0) {
		int32_t var$1 = bb->position();
		var$0 = !(var$1 == bb->limit());
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	this->numCategories = $div($nc(this->stateTable)->length, $nc(this->endStates)->length);
}

void RuleBasedBreakIterator::validateRuleData($String* ruleFile, $ByteBuffer* bb) {
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < RuleBasedBreakIterator::LABEL_LENGTH; ++i) {
		if ($nc(bb)->get() != $nc(RuleBasedBreakIterator::LABEL)->get(i)) {
			$throwNew($MissingResourceException, "Wrong magic number"_s, ruleFile, ""_s);
		}
	}
	int8_t version = $nc(bb)->get();
	if (version != RuleBasedBreakIterator::supportedVersion) {
		$throwNew($MissingResourceException, $$str({"Unsupported version("_s, $$str(version), ")"_s}), ruleFile, ""_s);
	}
	int32_t len = bb->getInt();
	int32_t var$0 = bb->position() + len;
	if (var$0 != bb->limit()) {
		$throwNew($MissingResourceException, "Wrong data length"_s, ruleFile, ""_s);
	}
}

$bytes* RuleBasedBreakIterator::getAdditionalData() {
	return this->additionalData;
}

void RuleBasedBreakIterator::setAdditionalData($bytes* b) {
	$set(this, additionalData, b);
}

$Object* RuleBasedBreakIterator::clone() {
	$var(RuleBasedBreakIterator, result, $cast(RuleBasedBreakIterator, $BreakIterator::clone()));
	if (this->text != nullptr) {
		$set($nc(result), text, $cast($CharacterIterator, $nc(this->text)->clone()));
	}
	return $of(result);
}

bool RuleBasedBreakIterator::equals(Object$* that) {
	try {
		if (that == nullptr) {
			return false;
		}
		$var(RuleBasedBreakIterator, other, $cast(RuleBasedBreakIterator, that));
		if (this->checksum != $nc(other)->checksum) {
			return false;
		}
		if (this->text == nullptr) {
			return $nc(other)->text == nullptr;
		} else {
			return $nc($of(this->text))->equals($nc(other)->text);
		}
	} catch ($ClassCastException& e) {
		return false;
	}
	$shouldNotReachHere();
}

$String* RuleBasedBreakIterator::toString() {
	$useLocalCurrentObjectStackCache();
	return $str({"[checksum=0x"_s, $($Long::toHexString(this->checksum)), $$str(u']')});
}

int32_t RuleBasedBreakIterator::hashCode() {
	return (int32_t)this->checksum;
}

int32_t RuleBasedBreakIterator::first() {
	$var($CharacterIterator, t, getText());
	$nc(t)->first();
	return t->getIndex();
}

int32_t RuleBasedBreakIterator::last() {
	$var($CharacterIterator, t, getText());
	$nc(t)->setIndex(t->getEndIndex());
	return t->getIndex();
}

int32_t RuleBasedBreakIterator::next(int32_t n) {
	int32_t result = current();
	while (n > 0) {
		result = handleNext();
		--n;
	}
	while (n < 0) {
		result = previous();
		++n;
	}
	return result;
}

int32_t RuleBasedBreakIterator::next() {
	return handleNext();
}

int32_t RuleBasedBreakIterator::previous() {
	$var($CharacterIterator, text, getText());
	int32_t var$0 = current();
	if (var$0 == $nc(text)->getBeginIndex()) {
		return $BreakIterator::DONE;
	}
	int32_t start = current();
	int32_t lastResult = this->cachedLastKnownBreak;
	if (lastResult >= start || lastResult <= $BreakIterator::DONE) {
		getPrevious();
		lastResult = handlePrevious();
	} else {
		$nc(text)->setIndex(lastResult);
	}
	int32_t result = lastResult;
	while (result != $BreakIterator::DONE && result < start) {
		lastResult = result;
		result = handleNext();
	}
	$nc(text)->setIndex(lastResult);
	this->cachedLastKnownBreak = lastResult;
	return lastResult;
}

int32_t RuleBasedBreakIterator::getPrevious() {
	char16_t c2 = $nc(this->text)->previous();
	bool var$0 = $Character::isLowSurrogate(c2);
	if (var$0) {
		int32_t var$1 = $nc(this->text)->getIndex();
		var$0 = var$1 > $nc(this->text)->getBeginIndex();
	}
	if (var$0) {
		char16_t c1 = $nc(this->text)->previous();
		if ($Character::isHighSurrogate(c1)) {
			return $Character::toCodePoint(c1, c2);
		} else {
			$nc(this->text)->next();
		}
	}
	return (int32_t)c2;
}

int32_t RuleBasedBreakIterator::getCurrent() {
	char16_t c1 = $nc(this->text)->current();
	bool var$0 = $Character::isHighSurrogate(c1);
	if (var$0) {
		int32_t var$1 = $nc(this->text)->getIndex();
		var$0 = var$1 < $nc(this->text)->getEndIndex();
	}
	if (var$0) {
		char16_t c2 = $nc(this->text)->next();
		$nc(this->text)->previous();
		if ($Character::isLowSurrogate(c2)) {
			return $Character::toCodePoint(c1, c2);
		}
	}
	return (int32_t)c1;
}

int32_t RuleBasedBreakIterator::getCurrentCodePointCount() {
	char16_t c1 = $nc(this->text)->current();
	bool var$0 = $Character::isHighSurrogate(c1);
	if (var$0) {
		int32_t var$1 = $nc(this->text)->getIndex();
		var$0 = var$1 < $nc(this->text)->getEndIndex();
	}
	if (var$0) {
		char16_t c2 = $nc(this->text)->next();
		$nc(this->text)->previous();
		if ($Character::isLowSurrogate(c2)) {
			return 2;
		}
	}
	return 1;
}

int32_t RuleBasedBreakIterator::getNext() {
	int32_t index = $nc(this->text)->getIndex();
	int32_t endIndex = $nc(this->text)->getEndIndex();
	if (index == endIndex || (index += getCurrentCodePointCount()) >= endIndex) {
		return $CharacterIterator::DONE;
	}
	$nc(this->text)->setIndex(index);
	return getCurrent();
}

int32_t RuleBasedBreakIterator::getNextIndex() {
	int32_t var$0 = $nc(this->text)->getIndex();
	int32_t index = var$0 + getCurrentCodePointCount();
	int32_t endIndex = $nc(this->text)->getEndIndex();
	if (index > endIndex) {
		return endIndex;
	} else {
		return index;
	}
}

void RuleBasedBreakIterator::checkOffset(int32_t offset, $CharacterIterator* text) {
	$init(RuleBasedBreakIterator);
	bool var$0 = offset < $nc(text)->getBeginIndex();
	if (var$0 || offset > $nc(text)->getEndIndex()) {
		$throwNew($IllegalArgumentException, "offset out of bounds"_s);
	}
}

int32_t RuleBasedBreakIterator::following(int32_t offset) {
	$var($CharacterIterator, text, getText());
	checkOffset(offset, text);
	$nc(text)->setIndex(offset);
	if (offset == text->getBeginIndex()) {
		this->cachedLastKnownBreak = handleNext();
		return this->cachedLastKnownBreak;
	}
	int32_t result = this->cachedLastKnownBreak;
	if (result >= offset || result <= $BreakIterator::DONE) {
		result = handlePrevious();
	} else {
		text->setIndex(result);
	}
	while (result != $BreakIterator::DONE && result <= offset) {
		result = handleNext();
	}
	this->cachedLastKnownBreak = result;
	return result;
}

int32_t RuleBasedBreakIterator::preceding(int32_t offset) {
	$var($CharacterIterator, text, getText());
	checkOffset(offset, text);
	$nc(text)->setIndex(offset);
	return previous();
}

bool RuleBasedBreakIterator::isBoundary(int32_t offset) {
	$var($CharacterIterator, text, getText());
	checkOffset(offset, text);
	if (offset == $nc(text)->getBeginIndex()) {
		return true;
	} else {
		return following(offset - 1) == offset;
	}
}

int32_t RuleBasedBreakIterator::current() {
	return $nc($(getText()))->getIndex();
}

$CharacterIterator* RuleBasedBreakIterator::getText() {
	if (this->text == nullptr) {
		$set(this, text, $new($StringCharacterIterator, ""_s));
	}
	return this->text;
}

void RuleBasedBreakIterator::setText($CharacterIterator* newText) {
	int32_t end = $nc(newText)->getEndIndex();
	bool goodIterator = false;
	try {
		newText->setIndex(end);
		goodIterator = newText->getIndex() == end;
	} catch ($IllegalArgumentException& e) {
		goodIterator = false;
	}
	if (goodIterator) {
		$set(this, text, newText);
	} else {
		$set(this, text, $new($RuleBasedBreakIterator$SafeCharIterator, newText));
	}
	$nc(this->text)->first();
	this->cachedLastKnownBreak = $BreakIterator::DONE;
}

int32_t RuleBasedBreakIterator::handleNext() {
	$var($CharacterIterator, text, getText());
	int32_t var$0 = $nc(text)->getIndex();
	if (var$0 == text->getEndIndex()) {
		return $BreakIterator::DONE;
	}
	int32_t result = getNextIndex();
	int32_t lookaheadResult = 0;
	int32_t state = RuleBasedBreakIterator::START_STATE;
	int32_t category = 0;
	int32_t c = getCurrent();
	while (c != $CharacterIterator::DONE && state != RuleBasedBreakIterator::STOP_STATE) {
		category = lookupCategory(c);
		if (category != RuleBasedBreakIterator::IGNORE) {
			state = lookupState(state, category);
		}
		if ($nc(this->lookaheadStates)->get(state)) {
			if ($nc(this->endStates)->get(state)) {
				result = lookaheadResult;
			} else {
				lookaheadResult = getNextIndex();
			}
		} else if ($nc(this->endStates)->get(state)) {
			result = getNextIndex();
		}
		c = getNext();
	}
	if (c == $CharacterIterator::DONE && lookaheadResult == $nc(text)->getEndIndex()) {
		result = lookaheadResult;
	}
	$nc(text)->setIndex(result);
	return result;
}

int32_t RuleBasedBreakIterator::handlePrevious() {
	$var($CharacterIterator, text, getText());
	int32_t state = RuleBasedBreakIterator::START_STATE;
	int32_t category = 0;
	int32_t lastCategory = 0;
	int32_t c = getCurrent();
	while (c != $CharacterIterator::DONE && state != RuleBasedBreakIterator::STOP_STATE) {
		lastCategory = category;
		category = lookupCategory(c);
		if (category != RuleBasedBreakIterator::IGNORE) {
			state = lookupBackwardState(state, category);
		}
		c = getPrevious();
	}
	if (c != $CharacterIterator::DONE) {
		if (lastCategory != RuleBasedBreakIterator::IGNORE) {
			getNext();
			getNext();
		} else {
			getNext();
		}
	}
	return $nc(text)->getIndex();
}

int32_t RuleBasedBreakIterator::lookupCategory(int32_t c) {
	if (c < $Character::MIN_SUPPLEMENTARY_CODE_POINT) {
		return $nc(this->charCategoryTable)->elementAt((char16_t)c);
	} else {
		return $nc(this->supplementaryCharCategoryTable)->getValue(c);
	}
}

int32_t RuleBasedBreakIterator::lookupState(int32_t state, int32_t category) {
	return $nc(this->stateTable)->get(state * this->numCategories + category);
}

int32_t RuleBasedBreakIterator::lookupBackwardState(int32_t state, int32_t category) {
	return $nc(this->backwardsStateTable)->get(state * this->numCategories + category);
}

void clinit$RuleBasedBreakIterator($Class* class$) {
	RuleBasedBreakIterator::$assertionsDisabled = !RuleBasedBreakIterator::class$->desiredAssertionStatus();
	$assignStatic(RuleBasedBreakIterator::LABEL, $new($bytes, {
		(int8_t)u'B',
		(int8_t)u'I',
		(int8_t)u'd',
		(int8_t)u'a',
		(int8_t)u't',
		(int8_t)u'a',
		(int8_t)u'\0'
	}));
	RuleBasedBreakIterator::LABEL_LENGTH = $nc(RuleBasedBreakIterator::LABEL)->length;
}

RuleBasedBreakIterator::RuleBasedBreakIterator() {
}

$Class* RuleBasedBreakIterator::load$($String* name, bool initialize) {
	$loadClass(RuleBasedBreakIterator, name, initialize, &_RuleBasedBreakIterator_ClassInfo_, clinit$RuleBasedBreakIterator, allocate$RuleBasedBreakIterator);
	return class$;
}

$Class* RuleBasedBreakIterator::class$ = nullptr;

	} // text
} // sun