#include <MirroredBreakIterator.h>

#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/text/BreakIterator.h>
#include <java/text/CharacterIterator.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/List.h>
#include <jcpp.h>

#undef DONE

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $BreakIterator = ::java::text::BreakIterator;
using $CharacterIterator = ::java::text::CharacterIterator;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $List = ::java::util::List;

$FieldInfo _MirroredBreakIterator_FieldInfo_[] = {
	{"boundaries", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Integer;>;", $PRIVATE | $FINAL, $field(MirroredBreakIterator, boundaries)},
	{"charIndex", "I", nullptr, $PRIVATE, $field(MirroredBreakIterator, charIndex)},
	{"boundaryIndex", "I", nullptr, $PRIVATE, $field(MirroredBreakIterator, boundaryIndex)},
	{}
};

$MethodInfo _MirroredBreakIterator_MethodInfo_[] = {
	{"<init>", "(Ljava/text/BreakIterator;)V", nullptr, 0, $method(MirroredBreakIterator, init$, void, $BreakIterator*)},
	{"changeIndices", "(II)I", nullptr, $PRIVATE, $method(MirroredBreakIterator, changeIndices, int32_t, int32_t, int32_t)},
	{"changeIndices", "(I)I", nullptr, $PRIVATE, $method(MirroredBreakIterator, changeIndices, int32_t, int32_t)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(MirroredBreakIterator, clone, $Object*)},
	{"current", "()I", nullptr, $PUBLIC, $virtualMethod(MirroredBreakIterator, current, int32_t)},
	{"first", "()I", nullptr, $PUBLIC, $virtualMethod(MirroredBreakIterator, first, int32_t)},
	{"following", "(I)I", nullptr, $PUBLIC, $virtualMethod(MirroredBreakIterator, following, int32_t, int32_t)},
	{"getText", "()Ljava/text/CharacterIterator;", nullptr, $PUBLIC, $virtualMethod(MirroredBreakIterator, getText, $CharacterIterator*)},
	{"isBoundary", "(I)Z", nullptr, $PUBLIC, $virtualMethod(MirroredBreakIterator, isBoundary, bool, int32_t)},
	{"last", "()I", nullptr, $PUBLIC, $virtualMethod(MirroredBreakIterator, last, int32_t)},
	{"lastBoundary", "()I", nullptr, $PRIVATE, $method(MirroredBreakIterator, lastBoundary, int32_t)},
	{"next", "(I)I", nullptr, $PUBLIC, $virtualMethod(MirroredBreakIterator, next, int32_t, int32_t)},
	{"next", "()I", nullptr, $PUBLIC, $virtualMethod(MirroredBreakIterator, next, int32_t)},
	{"preceding", "(I)I", nullptr, $PUBLIC, $virtualMethod(MirroredBreakIterator, preceding, int32_t, int32_t)},
	{"previous", "()I", nullptr, $PUBLIC, $virtualMethod(MirroredBreakIterator, previous, int32_t)},
	{"setText", "(Ljava/text/CharacterIterator;)V", nullptr, $PUBLIC, $virtualMethod(MirroredBreakIterator, setText, void, $CharacterIterator*)},
	{"validateOffset", "(I)V", nullptr, $PRIVATE, $method(MirroredBreakIterator, validateOffset, void, int32_t)},
	{}
};

$ClassInfo _MirroredBreakIterator_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"MirroredBreakIterator",
	"java.text.BreakIterator",
	nullptr,
	_MirroredBreakIterator_FieldInfo_,
	_MirroredBreakIterator_MethodInfo_
};

$Object* allocate$MirroredBreakIterator($Class* clazz) {
	return $of($alloc(MirroredBreakIterator));
}

void MirroredBreakIterator::init$($BreakIterator* bi) {
	$useLocalCurrentObjectStackCache();
	$BreakIterator::init$();
	$var($List, b, $new($ArrayList));
	int32_t i = $nc(bi)->first();
	this->charIndex = i;
	for (; i != $BreakIterator::DONE; i = bi->next()) {
		b->add($($Integer::valueOf(i)));
	}
	$set(this, boundaries, $Collections::unmodifiableList(b));
}

$Object* MirroredBreakIterator::clone() {
	try {
		return $of($BreakIterator::clone());
	} catch ($Exception& e) {
		$throwNew($RuntimeException, "clone failed"_s, e);
	}
	$shouldNotReachHere();
}

int32_t MirroredBreakIterator::first() {
	return changeIndices(0);
}

int32_t MirroredBreakIterator::last() {
	return changeIndices($nc(this->boundaries)->size() - 1);
}

int32_t MirroredBreakIterator::next(int32_t n) {
	if (n == 0) {
		return current();
	}
	int32_t newBoundary = this->boundaryIndex + n;
	if (newBoundary < 0) {
		first();
		return $BreakIterator::DONE;
	}
	if (newBoundary > lastBoundary()) {
		last();
		return $BreakIterator::DONE;
	}
	return changeIndices(newBoundary);
}

int32_t MirroredBreakIterator::next() {
	if (this->boundaryIndex == lastBoundary()) {
		return $BreakIterator::DONE;
	}
	return changeIndices(this->boundaryIndex + 1);
}

int32_t MirroredBreakIterator::previous() {
	if (this->boundaryIndex == 0) {
		return $BreakIterator::DONE;
	}
	return changeIndices(this->boundaryIndex - 1);
}

int32_t MirroredBreakIterator::following(int32_t offset) {
	$useLocalCurrentObjectStackCache();
	validateOffset(offset);
	for (int32_t b = 0; b <= lastBoundary(); ++b) {
		int32_t i = $nc(($cast($Integer, $($nc(this->boundaries)->get(b)))))->intValue();
		if (i > offset) {
			return changeIndices(i, b);
		}
	}
	return $BreakIterator::DONE;
}

int32_t MirroredBreakIterator::preceding(int32_t offset) {
	$useLocalCurrentObjectStackCache();
	validateOffset(offset);
	for (int32_t b = lastBoundary(); b >= 0; --b) {
		int32_t i = $nc(($cast($Integer, $($nc(this->boundaries)->get(b)))))->intValue();
		if (i < offset) {
			return changeIndices(i, b);
		}
	}
	return $BreakIterator::DONE;
}

bool MirroredBreakIterator::isBoundary(int32_t offset) {
	return $BreakIterator::isBoundary(offset);
}

int32_t MirroredBreakIterator::current() {
	return this->charIndex;
}

$CharacterIterator* MirroredBreakIterator::getText() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

void MirroredBreakIterator::setText($CharacterIterator* newText) {
	$throwNew($UnsupportedOperationException);
}

int32_t MirroredBreakIterator::lastBoundary() {
	return $nc(this->boundaries)->size() - 1;
}

int32_t MirroredBreakIterator::changeIndices(int32_t newCharIndex, int32_t newBoundary) {
	this->boundaryIndex = newBoundary;
	return this->charIndex = newCharIndex;
}

int32_t MirroredBreakIterator::changeIndices(int32_t newBoundary) {
	try {
		return changeIndices($nc(($cast($Integer, $($nc(this->boundaries)->get(newBoundary)))))->intValue(), newBoundary);
	} catch ($IndexOutOfBoundsException& e) {
		$throwNew($IllegalArgumentException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

void MirroredBreakIterator::validateOffset(int32_t offset) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = offset < $nc(($cast($Integer, $($nc(this->boundaries)->get(0)))))->intValue();
	if (var$0 || offset > $nc(($cast($Integer, $($nc(this->boundaries)->get(lastBoundary())))))->intValue()) {
		$throwNew($IllegalArgumentException);
	}
}

MirroredBreakIterator::MirroredBreakIterator() {
}

$Class* MirroredBreakIterator::load$($String* name, bool initialize) {
	$loadClass(MirroredBreakIterator, name, initialize, &_MirroredBreakIterator_ClassInfo_, allocate$MirroredBreakIterator);
	return class$;
}

$Class* MirroredBreakIterator::class$ = nullptr;