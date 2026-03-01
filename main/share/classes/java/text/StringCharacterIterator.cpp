#include <java/text/StringCharacterIterator.h>

#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/text/CharacterIterator.h>
#include <jcpp.h>

#undef DONE

using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $CharacterIterator = ::java::text::CharacterIterator;

namespace java {
	namespace text {

$FieldInfo _StringCharacterIterator_FieldInfo_[] = {
	{"text", "Ljava/lang/String;", nullptr, $PRIVATE, $field(StringCharacterIterator, text)},
	{"begin", "I", nullptr, $PRIVATE, $field(StringCharacterIterator, begin)},
	{"end", "I", nullptr, $PRIVATE, $field(StringCharacterIterator, end)},
	{"pos", "I", nullptr, $PRIVATE, $field(StringCharacterIterator, pos)},
	{}
};

$MethodInfo _StringCharacterIterator_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(StringCharacterIterator, init$, void, $String*)},
	{"<init>", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $method(StringCharacterIterator, init$, void, $String*, int32_t)},
	{"<init>", "(Ljava/lang/String;III)V", nullptr, $PUBLIC, $method(StringCharacterIterator, init$, void, $String*, int32_t, int32_t, int32_t)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(StringCharacterIterator, clone, $Object*)},
	{"current", "()C", nullptr, $PUBLIC, $virtualMethod(StringCharacterIterator, current, char16_t)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(StringCharacterIterator, equals, bool, Object$*)},
	{"first", "()C", nullptr, $PUBLIC, $virtualMethod(StringCharacterIterator, first, char16_t)},
	{"getBeginIndex", "()I", nullptr, $PUBLIC, $virtualMethod(StringCharacterIterator, getBeginIndex, int32_t)},
	{"getEndIndex", "()I", nullptr, $PUBLIC, $virtualMethod(StringCharacterIterator, getEndIndex, int32_t)},
	{"getIndex", "()I", nullptr, $PUBLIC, $virtualMethod(StringCharacterIterator, getIndex, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(StringCharacterIterator, hashCode, int32_t)},
	{"last", "()C", nullptr, $PUBLIC, $virtualMethod(StringCharacterIterator, last, char16_t)},
	{"next", "()C", nullptr, $PUBLIC, $virtualMethod(StringCharacterIterator, next, char16_t)},
	{"previous", "()C", nullptr, $PUBLIC, $virtualMethod(StringCharacterIterator, previous, char16_t)},
	{"setIndex", "(I)C", nullptr, $PUBLIC, $virtualMethod(StringCharacterIterator, setIndex, char16_t, int32_t)},
	{"setText", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(StringCharacterIterator, setText, void, $String*)},
	{}
};

$ClassInfo _StringCharacterIterator_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.text.StringCharacterIterator",
	"java.lang.Object",
	"java.text.CharacterIterator",
	_StringCharacterIterator_FieldInfo_,
	_StringCharacterIterator_MethodInfo_
};

$Object* allocate$StringCharacterIterator($Class* clazz) {
	return $of($alloc(StringCharacterIterator));
}

void StringCharacterIterator::init$($String* text) {
	StringCharacterIterator::init$(text, 0);
}

void StringCharacterIterator::init$($String* text, int32_t pos) {
	StringCharacterIterator::init$(text, 0, $nc(text)->length(), pos);
}

void StringCharacterIterator::init$($String* text, int32_t begin, int32_t end, int32_t pos) {
	if (text == nullptr) {
		$throwNew($NullPointerException);
	}
	$set(this, text, text);
	if (begin < 0 || begin > end || end > $nc(text)->length()) {
		$throwNew($IllegalArgumentException, "Invalid substring range"_s);
	}
	if (pos < begin || pos > end) {
		$throwNew($IllegalArgumentException, "Invalid position"_s);
	}
	this->begin = begin;
	this->end = end;
	this->pos = pos;
}

void StringCharacterIterator::setText($String* text) {
	if (text == nullptr) {
		$throwNew($NullPointerException);
	}
	$set(this, text, text);
	this->begin = 0;
	this->end = $nc(text)->length();
	this->pos = 0;
}

char16_t StringCharacterIterator::first() {
	this->pos = this->begin;
	return current();
}

char16_t StringCharacterIterator::last() {
	if (this->end != this->begin) {
		this->pos = this->end - 1;
	} else {
		this->pos = this->end;
	}
	return current();
}

char16_t StringCharacterIterator::setIndex(int32_t p) {
	if (p < this->begin || p > this->end) {
		$throwNew($IllegalArgumentException, "Invalid index"_s);
	}
	this->pos = p;
	return current();
}

char16_t StringCharacterIterator::current() {
	if (this->pos >= this->begin && this->pos < this->end) {
		return $nc(this->text)->charAt(this->pos);
	} else {
		return $CharacterIterator::DONE;
	}
}

char16_t StringCharacterIterator::next() {
	if (this->pos < this->end - 1) {
		++this->pos;
		return $nc(this->text)->charAt(this->pos);
	} else {
		this->pos = this->end;
		return $CharacterIterator::DONE;
	}
}

char16_t StringCharacterIterator::previous() {
	if (this->pos > this->begin) {
		--this->pos;
		return $nc(this->text)->charAt(this->pos);
	} else {
		return $CharacterIterator::DONE;
	}
}

int32_t StringCharacterIterator::getBeginIndex() {
	return this->begin;
}

int32_t StringCharacterIterator::getEndIndex() {
	return this->end;
}

int32_t StringCharacterIterator::getIndex() {
	return this->pos;
}

bool StringCharacterIterator::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	$var(StringCharacterIterator, that, nullptr);
	bool var$0 = $instanceOf(StringCharacterIterator, obj);
	if (var$0) {
		$assign(that, $cast(StringCharacterIterator, obj));
		var$0 = true;
	}
	if (!(var$0)) {
		return false;
	}
	int32_t var$1 = hashCode();
	if (var$1 != $nc(that)->hashCode()) {
		return false;
	}
	if (!$nc(this->text)->equals($nc(that)->text)) {
		return false;
	}
	if (this->pos != $nc(that)->pos || this->begin != $nc(that)->begin || this->end != $nc(that)->end) {
		return false;
	}
	return true;
}

int32_t StringCharacterIterator::hashCode() {
	return (($nc(this->text)->hashCode() ^ this->pos) ^ this->begin) ^ this->end;
}

$Object* StringCharacterIterator::clone() {
	try {
		$var(StringCharacterIterator, other, $cast(StringCharacterIterator, $CharacterIterator::clone()));
		return $of(other);
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

StringCharacterIterator::StringCharacterIterator() {
}

$Class* StringCharacterIterator::load$($String* name, bool initialize) {
	$loadClass(StringCharacterIterator, name, initialize, &_StringCharacterIterator_ClassInfo_, allocate$StringCharacterIterator);
	return class$;
}

$Class* StringCharacterIterator::class$ = nullptr;

	} // text
} // java