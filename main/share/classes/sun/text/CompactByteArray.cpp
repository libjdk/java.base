#include <sun/text/CompactByteArray.h>

#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/Cloneable.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <jcpp.h>

#undef BLOCKCOUNT
#undef BLOCKMASK
#undef BLOCKSHIFT
#undef INDEXCOUNT
#undef INDEXSHIFT
#undef UNICODECOUNT

using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InternalError = ::java::lang::InternalError;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;

namespace sun {
	namespace text {

$FieldInfo _CompactByteArray_FieldInfo_[] = {
	{"UNICODECOUNT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(CompactByteArray, UNICODECOUNT)},
	{"BLOCKSHIFT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompactByteArray, BLOCKSHIFT)},
	{"BLOCKCOUNT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompactByteArray, BLOCKCOUNT)},
	{"INDEXSHIFT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompactByteArray, INDEXSHIFT)},
	{"INDEXCOUNT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompactByteArray, INDEXCOUNT)},
	{"BLOCKMASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompactByteArray, BLOCKMASK)},
	{"values", "[B", nullptr, $PRIVATE, $field(CompactByteArray, values)},
	{"indices", "[S", nullptr, $PRIVATE, $field(CompactByteArray, indices)},
	{"isCompact", "Z", nullptr, $PRIVATE, $field(CompactByteArray, isCompact)},
	{"hashes", "[I", nullptr, $PRIVATE, $field(CompactByteArray, hashes)},
	{}
};

$MethodInfo _CompactByteArray_MethodInfo_[] = {
	{"<init>", "(B)V", nullptr, $PUBLIC, $method(CompactByteArray, init$, void, int8_t)},
	{"<init>", "([S[B)V", nullptr, $PUBLIC, $method(CompactByteArray, init$, void, $shorts*, $bytes*)},
	{"arrayRegionMatches", "([BI[BII)Z", nullptr, $STATIC | $FINAL, $staticMethod(CompactByteArray, arrayRegionMatches, bool, $bytes*, int32_t, $bytes*, int32_t, int32_t)},
	{"blockTouched", "(I)Z", nullptr, $PRIVATE | $FINAL, $method(CompactByteArray, blockTouched, bool, int32_t)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(CompactByteArray, clone, $Object*)},
	{"compact", "()V", nullptr, $PUBLIC, $method(CompactByteArray, compact, void)},
	{"elementAt", "(C)B", nullptr, $PUBLIC, $method(CompactByteArray, elementAt, int8_t, char16_t)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(CompactByteArray, equals, bool, Object$*)},
	{"expand", "()V", nullptr, $PRIVATE, $method(CompactByteArray, expand, void)},
	{"getArray", "()[B", nullptr, $PRIVATE, $method(CompactByteArray, getArray, $bytes*)},
	{"getIndexArray", "()[S", nullptr, $PUBLIC, $method(CompactByteArray, getIndexArray, $shorts*)},
	{"getStringArray", "()[B", nullptr, $PUBLIC, $method(CompactByteArray, getStringArray, $bytes*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(CompactByteArray, hashCode, int32_t)},
	{"setElementAt", "(CB)V", nullptr, $PUBLIC, $method(CompactByteArray, setElementAt, void, char16_t, int8_t)},
	{"setElementAt", "(CCB)V", nullptr, $PUBLIC, $method(CompactByteArray, setElementAt, void, char16_t, char16_t, int8_t)},
	{"touchBlock", "(II)V", nullptr, $PRIVATE | $FINAL, $method(CompactByteArray, touchBlock, void, int32_t, int32_t)},
	{}
};

$ClassInfo _CompactByteArray_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.text.CompactByteArray",
	"java.lang.Object",
	"java.lang.Cloneable",
	_CompactByteArray_FieldInfo_,
	_CompactByteArray_MethodInfo_
};

$Object* allocate$CompactByteArray($Class* clazz) {
	return $of($alloc(CompactByteArray));
}

void CompactByteArray::init$(int8_t defaultValue) {
	int32_t i = 0;
	$set(this, values, $new($bytes, CompactByteArray::UNICODECOUNT));
	$set(this, indices, $new($shorts, CompactByteArray::INDEXCOUNT));
	$set(this, hashes, $new($ints, CompactByteArray::INDEXCOUNT));
	for (i = 0; i < CompactByteArray::UNICODECOUNT; ++i) {
		$nc(this->values)->set(i, defaultValue);
	}
	for (i = 0; i < CompactByteArray::INDEXCOUNT; ++i) {
		$nc(this->indices)->set(i, (int16_t)($sl(i, CompactByteArray::BLOCKSHIFT)));
		$nc(this->hashes)->set(i, 0);
	}
	this->isCompact = false;
}

void CompactByteArray::init$($shorts* indexArray, $bytes* newValues) {
	int32_t i = 0;
	if ($nc(indexArray)->length != CompactByteArray::INDEXCOUNT) {
		$throwNew($IllegalArgumentException, "Index out of bounds!"_s);
	}
	for (i = 0; i < CompactByteArray::INDEXCOUNT; ++i) {
		int16_t index = $nc(indexArray)->get(i);
		if ((index < 0) || (index >= $nc(newValues)->length + CompactByteArray::BLOCKCOUNT)) {
			$throwNew($IllegalArgumentException, "Index out of bounds!"_s);
		}
	}
	$set(this, indices, indexArray);
	$set(this, values, newValues);
	this->isCompact = true;
}

int8_t CompactByteArray::elementAt(char16_t index) {
	return ($nc(this->values)->get(((int32_t)($nc(this->indices)->get($sr((int32_t)index, CompactByteArray::BLOCKSHIFT)) & (uint32_t)0x0000FFFF)) + ((int32_t)(index & (uint32_t)CompactByteArray::BLOCKMASK))));
}

void CompactByteArray::setElementAt(char16_t index, int8_t value) {
	if (this->isCompact) {
		expand();
	}
	$nc(this->values)->set((int32_t)index, value);
	touchBlock($sr((int32_t)index, CompactByteArray::BLOCKSHIFT), value);
}

void CompactByteArray::setElementAt(char16_t start, char16_t end, int8_t value) {
	int32_t i = 0;
	if (this->isCompact) {
		expand();
	}
	for (i = start; i <= end; ++i) {
		$nc(this->values)->set(i, value);
		touchBlock($sr(i, CompactByteArray::BLOCKSHIFT), value);
	}
}

void CompactByteArray::compact() {
	if (!this->isCompact) {
		int32_t limitCompacted = 0;
		int32_t iBlockStart = 0;
		int16_t iUntouched = (int16_t)-1;
		for (int32_t i = 0; i < $nc(this->indices)->length; ++i, iBlockStart += CompactByteArray::BLOCKCOUNT) {
			$nc(this->indices)->set(i, (int16_t)-1);
			bool touched = blockTouched(i);
			if (!touched && iUntouched != -1) {
				$nc(this->indices)->set(i, iUntouched);
			} else {
				int32_t jBlockStart = 0;
				int32_t j = 0;
				for (j = 0; j < limitCompacted; ++j, jBlockStart += CompactByteArray::BLOCKCOUNT) {
					if ($nc(this->hashes)->get(i) == $nc(this->hashes)->get(j) && arrayRegionMatches(this->values, iBlockStart, this->values, jBlockStart, CompactByteArray::BLOCKCOUNT)) {
						$nc(this->indices)->set(i, (int16_t)jBlockStart);
						break;
					}
				}
				if ($nc(this->indices)->get(i) == -1) {
					$System::arraycopy(this->values, iBlockStart, this->values, jBlockStart, CompactByteArray::BLOCKCOUNT);
					$nc(this->indices)->set(i, (int16_t)jBlockStart);
					$nc(this->hashes)->set(j, $nc(this->hashes)->get(i));
					++limitCompacted;
					if (!touched) {
						iUntouched = (int16_t)jBlockStart;
					}
				}
			}
		}
		int32_t newSize = limitCompacted * CompactByteArray::BLOCKCOUNT;
		$var($bytes, result, $new($bytes, newSize));
		$System::arraycopy(this->values, 0, result, 0, newSize);
		$set(this, values, result);
		this->isCompact = true;
		$set(this, hashes, nullptr);
	}
}

bool CompactByteArray::arrayRegionMatches($bytes* source, int32_t sourceStart, $bytes* target, int32_t targetStart, int32_t len) {
	$init(CompactByteArray);
	int32_t sourceEnd = sourceStart + len;
	int32_t delta = targetStart - sourceStart;
	for (int32_t i = sourceStart; i < sourceEnd; ++i) {
		if ($nc(source)->get(i) != $nc(target)->get(i + delta)) {
			return false;
		}
	}
	return true;
}

void CompactByteArray::touchBlock(int32_t i, int32_t value) {
	$nc(this->hashes)->set(i, ($nc(this->hashes)->get(i) + (value << 1)) | 1);
}

bool CompactByteArray::blockTouched(int32_t i) {
	return $nc(this->hashes)->get(i) != 0;
}

$shorts* CompactByteArray::getIndexArray() {
	return this->indices;
}

$bytes* CompactByteArray::getStringArray() {
	return this->values;
}

$Object* CompactByteArray::clone() {
	try {
		$var(CompactByteArray, other, $cast(CompactByteArray, $Cloneable::clone()));
		$set($nc(other), values, $cast($bytes, $nc(this->values)->clone()));
		$set(other, indices, $cast($shorts, $nc(this->indices)->clone()));
		if (this->hashes != nullptr) {
			$set(other, hashes, $cast($ints, $nc(this->hashes)->clone()));
		}
		return $of(other);
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

bool CompactByteArray::equals(Object$* obj) {
	if (obj == nullptr) {
		return false;
	}
	if ($equals(this, obj)) {
		return true;
	}
	if ($of(this)->getClass() != $nc($of(obj))->getClass()) {
		return false;
	}
	$var(CompactByteArray, other, $cast(CompactByteArray, obj));
	for (int32_t i = 0; i < CompactByteArray::UNICODECOUNT; ++i) {
		int8_t var$0 = elementAt((char16_t)i);
		if (var$0 != $nc(other)->elementAt((char16_t)i)) {
			return false;
		}
	}
	return true;
}

int32_t CompactByteArray::hashCode() {
	int32_t result = 0;
	int32_t increment = $Math::min(3, $nc(this->values)->length / 16);
	for (int32_t i = 0; i < $nc(this->values)->length; i += increment) {
		result = result * 37 + $nc(this->values)->get(i);
	}
	return result;
}

void CompactByteArray::expand() {
	int32_t i = 0;
	if (this->isCompact) {
		$var($bytes, tempArray, nullptr);
		$set(this, hashes, $new($ints, CompactByteArray::INDEXCOUNT));
		$assign(tempArray, $new($bytes, CompactByteArray::UNICODECOUNT));
		for (i = 0; i < CompactByteArray::UNICODECOUNT; ++i) {
			int8_t value = elementAt((char16_t)i);
			tempArray->set(i, value);
			touchBlock($sr(i, CompactByteArray::BLOCKSHIFT), value);
		}
		for (i = 0; i < CompactByteArray::INDEXCOUNT; ++i) {
			$nc(this->indices)->set(i, (int16_t)($sl(i, CompactByteArray::BLOCKSHIFT)));
		}
		$set(this, values, nullptr);
		$set(this, values, tempArray);
		this->isCompact = false;
	}
}

$bytes* CompactByteArray::getArray() {
	return this->values;
}

CompactByteArray::CompactByteArray() {
}

$Class* CompactByteArray::load$($String* name, bool initialize) {
	$loadClass(CompactByteArray, name, initialize, &_CompactByteArray_ClassInfo_, allocate$CompactByteArray);
	return class$;
}

$Class* CompactByteArray::class$ = nullptr;

	} // text
} // sun