#include <java/util/BitSet.h>

#include <java/io/ObjectInputStream$GetField.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream$PutField.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/ObjectStreamField.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/Cloneable.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/lang/NegativeArraySizeException.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/ByteOrder.h>
#include <java/nio/LongBuffer.h>
#include <java/util/Arrays.h>
#include <java/util/BitSet$1BitSetSpliterator.h>
#include <java/util/Spliterator$OfInt.h>
#include <java/util/stream/IntStream.h>
#include <java/util/stream/StreamSupport.h>
#include <jcpp.h>

#undef ADDRESS_BITS_PER_WORD
#undef BITS_PER_WORD
#undef BIT_INDEX_MASK
#undef LITTLE_ENDIAN
#undef MAX_INITIAL_CAPACITY
#undef MAX_VALUE
#undef WORD_MASK

using $ObjectStreamFieldArray = $Array<::java::io::ObjectStreamField>;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectInputStream$GetField = ::java::io::ObjectInputStream$GetField;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ObjectOutputStream$PutField = ::java::io::ObjectOutputStream$PutField;
using $ObjectStreamField = ::java::io::ObjectStreamField;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $FieldInfo = ::java::lang::FieldInfo;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NegativeArraySizeException = ::java::lang::NegativeArraySizeException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $ByteOrder = ::java::nio::ByteOrder;
using $LongBuffer = ::java::nio::LongBuffer;
using $Arrays = ::java::util::Arrays;
using $BitSet$1BitSetSpliterator = ::java::util::BitSet$1BitSetSpliterator;
using $Spliterator$OfInt = ::java::util::Spliterator$OfInt;
using $IntStream = ::java::util::stream::IntStream;
using $StreamSupport = ::java::util::stream::StreamSupport;

namespace java {
	namespace util {

$FieldInfo _BitSet_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(BitSet, $assertionsDisabled)},
	{"ADDRESS_BITS_PER_WORD", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(BitSet, ADDRESS_BITS_PER_WORD)},
	{"BITS_PER_WORD", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(BitSet, BITS_PER_WORD)},
	{"BIT_INDEX_MASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(BitSet, BIT_INDEX_MASK)},
	{"WORD_MASK", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(BitSet, WORD_MASK)},
	{"serialPersistentFields", "[Ljava/io/ObjectStreamField;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BitSet, serialPersistentFields)},
	{"words", "[J", nullptr, $PRIVATE, $field(BitSet, words)},
	{"wordsInUse", "I", nullptr, $PRIVATE | $TRANSIENT, $field(BitSet, wordsInUse)},
	{"sizeIsSticky", "Z", nullptr, $PRIVATE | $TRANSIENT, $field(BitSet, sizeIsSticky)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(BitSet, serialVersionUID)},
	{}
};

$MethodInfo _BitSet_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "()V", nullptr, $PUBLIC, $method(BitSet, init$, void)},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(BitSet, init$, void, int32_t)},
	{"<init>", "([J)V", nullptr, $PRIVATE, $method(BitSet, init$, void, $longs*)},
	{"and", "(Ljava/util/BitSet;)V", nullptr, $PUBLIC, $virtualMethod(BitSet, and$, void, BitSet*)},
	{"andNot", "(Ljava/util/BitSet;)V", nullptr, $PUBLIC, $virtualMethod(BitSet, andNot, void, BitSet*)},
	{"cardinality", "()I", nullptr, $PUBLIC, $virtualMethod(BitSet, cardinality, int32_t)},
	{"checkInvariants", "()V", nullptr, $PRIVATE, $method(BitSet, checkInvariants, void)},
	{"checkRange", "(II)V", nullptr, $PRIVATE | $STATIC, $staticMethod(BitSet, checkRange, void, int32_t, int32_t)},
	{"clear", "(I)V", nullptr, $PUBLIC, $virtualMethod(BitSet, clear, void, int32_t)},
	{"clear", "(II)V", nullptr, $PUBLIC, $virtualMethod(BitSet, clear, void, int32_t, int32_t)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(BitSet, clear, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(BitSet, clone, $Object*)},
	{"ensureCapacity", "(I)V", nullptr, $PRIVATE, $method(BitSet, ensureCapacity, void, int32_t)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(BitSet, equals, bool, Object$*)},
	{"expandTo", "(I)V", nullptr, $PRIVATE, $method(BitSet, expandTo, void, int32_t)},
	{"flip", "(I)V", nullptr, $PUBLIC, $virtualMethod(BitSet, flip, void, int32_t)},
	{"flip", "(II)V", nullptr, $PUBLIC, $virtualMethod(BitSet, flip, void, int32_t, int32_t)},
	{"get", "(I)Z", nullptr, $PUBLIC, $virtualMethod(BitSet, get, bool, int32_t)},
	{"get", "(II)Ljava/util/BitSet;", nullptr, $PUBLIC, $virtualMethod(BitSet, get, BitSet*, int32_t, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(BitSet, hashCode, int32_t)},
	{"initWords", "(I)V", nullptr, $PRIVATE, $method(BitSet, initWords, void, int32_t)},
	{"intersects", "(Ljava/util/BitSet;)Z", nullptr, $PUBLIC, $virtualMethod(BitSet, intersects, bool, BitSet*)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(BitSet, isEmpty, bool)},
	{"length", "()I", nullptr, $PUBLIC, $virtualMethod(BitSet, length, int32_t)},
	{"nextClearBit", "(I)I", nullptr, $PUBLIC, $virtualMethod(BitSet, nextClearBit, int32_t, int32_t)},
	{"nextSetBit", "(I)I", nullptr, $PUBLIC, $virtualMethod(BitSet, nextSetBit, int32_t, int32_t)},
	{"nextSetBit", "(II)I", nullptr, $PRIVATE, $method(BitSet, nextSetBit, int32_t, int32_t, int32_t)},
	{"or", "(Ljava/util/BitSet;)V", nullptr, $PUBLIC, $virtualMethod(BitSet, or$, void, BitSet*)},
	{"previousClearBit", "(I)I", nullptr, $PUBLIC, $virtualMethod(BitSet, previousClearBit, int32_t, int32_t)},
	{"previousSetBit", "(I)I", nullptr, $PUBLIC, $virtualMethod(BitSet, previousSetBit, int32_t, int32_t)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(BitSet, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"recalculateWordsInUse", "()V", nullptr, $PRIVATE, $method(BitSet, recalculateWordsInUse, void)},
	{"set", "(I)V", nullptr, $PUBLIC, $virtualMethod(BitSet, set, void, int32_t)},
	{"set", "(IZ)V", nullptr, $PUBLIC, $virtualMethod(BitSet, set, void, int32_t, bool)},
	{"set", "(II)V", nullptr, $PUBLIC, $virtualMethod(BitSet, set, void, int32_t, int32_t)},
	{"set", "(IIZ)V", nullptr, $PUBLIC, $virtualMethod(BitSet, set, void, int32_t, int32_t, bool)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(BitSet, size, int32_t)},
	{"stream", "()Ljava/util/stream/IntStream;", nullptr, $PUBLIC, $virtualMethod(BitSet, stream, $IntStream*)},
	{"toByteArray", "()[B", nullptr, $PUBLIC, $virtualMethod(BitSet, toByteArray, $bytes*)},
	{"toLongArray", "()[J", nullptr, $PUBLIC, $virtualMethod(BitSet, toLongArray, $longs*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(BitSet, toString, $String*)},
	{"trimToSize", "()V", nullptr, $PRIVATE, $method(BitSet, trimToSize, void)},
	{"valueOf", "([J)Ljava/util/BitSet;", nullptr, $PUBLIC | $STATIC, $staticMethod(BitSet, valueOf, BitSet*, $longs*)},
	{"valueOf", "(Ljava/nio/LongBuffer;)Ljava/util/BitSet;", nullptr, $PUBLIC | $STATIC, $staticMethod(BitSet, valueOf, BitSet*, $LongBuffer*)},
	{"valueOf", "([B)Ljava/util/BitSet;", nullptr, $PUBLIC | $STATIC, $staticMethod(BitSet, valueOf, BitSet*, $bytes*)},
	{"valueOf", "(Ljava/nio/ByteBuffer;)Ljava/util/BitSet;", nullptr, $PUBLIC | $STATIC, $staticMethod(BitSet, valueOf, BitSet*, $ByteBuffer*)},
	{"wordIndex", "(I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(BitSet, wordIndex, int32_t, int32_t)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(BitSet, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{"xor", "(Ljava/util/BitSet;)V", nullptr, $PUBLIC, $virtualMethod(BitSet, xor$, void, BitSet*)},
	{}
};

$InnerClassInfo _BitSet_InnerClassesInfo_[] = {
	{"java.util.BitSet$1BitSetSpliterator", nullptr, "BitSetSpliterator", 0},
	{}
};

$ClassInfo _BitSet_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.BitSet",
	"java.lang.Object",
	"java.lang.Cloneable,java.io.Serializable",
	_BitSet_FieldInfo_,
	_BitSet_MethodInfo_,
	nullptr,
	nullptr,
	_BitSet_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.BitSet$1BitSetSpliterator"
};

$Object* allocate$BitSet($Class* clazz) {
	return $of($alloc(BitSet));
}

void BitSet::finalize() {
	this->$Cloneable::finalize();
}

bool BitSet::$assertionsDisabled = false;
$ObjectStreamFieldArray* BitSet::serialPersistentFields = nullptr;

int32_t BitSet::wordIndex(int32_t bitIndex) {
	$init(BitSet);
	return $sr(bitIndex, BitSet::ADDRESS_BITS_PER_WORD);
}

void BitSet::checkInvariants() {
	if (!BitSet::$assertionsDisabled && !(this->wordsInUse == 0 || $nc(this->words)->get(this->wordsInUse - 1) != 0)) {
		$throwNew($AssertionError);
	}
	if (!BitSet::$assertionsDisabled && !(this->wordsInUse >= 0 && this->wordsInUse <= $nc(this->words)->length)) {
		$throwNew($AssertionError);
	}
	if (!BitSet::$assertionsDisabled && !(this->wordsInUse == $nc(this->words)->length || $nc(this->words)->get(this->wordsInUse) == 0)) {
		$throwNew($AssertionError);
	}
}

void BitSet::recalculateWordsInUse() {
	int32_t i = 0;
	for (i = this->wordsInUse - 1; i >= 0; --i) {
		if ($nc(this->words)->get(i) != 0) {
			break;
		}
	}
	this->wordsInUse = i + 1;
}

void BitSet::init$() {
	this->wordsInUse = 0;
	this->sizeIsSticky = false;
	initWords(BitSet::BITS_PER_WORD);
	this->sizeIsSticky = false;
}

void BitSet::init$(int32_t nbits) {
	$useLocalCurrentObjectStackCache();
	this->wordsInUse = 0;
	this->sizeIsSticky = false;
	if (nbits < 0) {
		$throwNew($NegativeArraySizeException, $$str({"nbits < 0: "_s, $$str(nbits)}));
	}
	initWords(nbits);
	this->sizeIsSticky = true;
}

void BitSet::initWords(int32_t nbits) {
	$set(this, words, $new($longs, wordIndex(nbits - 1) + 1));
}

void BitSet::init$($longs* words) {
	this->wordsInUse = 0;
	this->sizeIsSticky = false;
	$set(this, words, words);
	this->wordsInUse = $nc(words)->length;
	checkInvariants();
}

BitSet* BitSet::valueOf($longs* longs) {
	$init(BitSet);
	int32_t n = 0;
	for (n = $nc(longs)->length; n > 0 && longs->get(n - 1) == 0; --n) {
	}
	return $new(BitSet, $($Arrays::copyOf(longs, n)));
}

BitSet* BitSet::valueOf($LongBuffer* lb$renamed) {
	$init(BitSet);
	$useLocalCurrentObjectStackCache();
	$var($LongBuffer, lb, lb$renamed);
	$assign(lb, $nc(lb)->slice());
	int32_t n = 0;
	for (n = lb->remaining(); n > 0 && lb->get(n - 1) == 0; --n) {
	}
	$var($longs, words, $new($longs, n));
	lb->get(words);
	return $new(BitSet, words);
}

BitSet* BitSet::valueOf($bytes* bytes) {
	$init(BitSet);
	return BitSet::valueOf($($ByteBuffer::wrap(bytes)));
}

BitSet* BitSet::valueOf($ByteBuffer* bb$renamed) {
	$init(BitSet);
	$useLocalCurrentObjectStackCache();
	$var($ByteBuffer, bb, bb$renamed);
	$init($ByteOrder);
	$assign(bb, $nc($($nc(bb)->slice()))->order($ByteOrder::LITTLE_ENDIAN));
	int32_t n = 0;
	for (n = bb->remaining(); n > 0 && bb->get(n - 1) == 0; --n) {
	}
	$var($longs, words, $new($longs, (n + 7) / 8));
	bb->limit(n);
	int32_t i = 0;
	while (bb->remaining() >= 8) {
		words->set(i++, bb->getLong());
	}
	{
		int32_t remaining = bb->remaining();
		int32_t j = 0;
		for (; j < remaining; ++j) {
			(*words)[i] |= $sl((int64_t)(bb->get() & (uint64_t)(int64_t)255), 8 * j);
		}
	}
	return $new(BitSet, words);
}

$bytes* BitSet::toByteArray() {
	$useLocalCurrentObjectStackCache();
	int32_t n = this->wordsInUse;
	if (n == 0) {
		return $new($bytes, 0);
	}
	int32_t len = 8 * (n - 1);
	for (int64_t x = $nc(this->words)->get(n - 1); x != 0; $usrAssign(x, 8)) {
		++len;
	}
	$var($bytes, bytes, $new($bytes, len));
	$init($ByteOrder);
	$var($ByteBuffer, bb, $nc($($ByteBuffer::wrap(bytes)))->order($ByteOrder::LITTLE_ENDIAN));
	for (int32_t i = 0; i < n - 1; ++i) {
		$nc(bb)->putLong($nc(this->words)->get(i));
	}
	for (int64_t x = $nc(this->words)->get(n - 1); x != 0; $usrAssign(x, 8)) {
		$nc(bb)->put((int8_t)((int64_t)(x & (uint64_t)(int64_t)255)));
	}
	return bytes;
}

$longs* BitSet::toLongArray() {
	return $Arrays::copyOf(this->words, this->wordsInUse);
}

void BitSet::ensureCapacity(int32_t wordsRequired) {
	if ($nc(this->words)->length < wordsRequired) {
		int32_t request = $Math::max(2 * $nc(this->words)->length, wordsRequired);
		$set(this, words, $Arrays::copyOf(this->words, request));
		this->sizeIsSticky = false;
	}
}

void BitSet::expandTo(int32_t wordIndex) {
	int32_t wordsRequired = wordIndex + 1;
	if (this->wordsInUse < wordsRequired) {
		ensureCapacity(wordsRequired);
		this->wordsInUse = wordsRequired;
	}
}

void BitSet::checkRange(int32_t fromIndex, int32_t toIndex) {
	$init(BitSet);
	$useLocalCurrentObjectStackCache();
	if (fromIndex < 0) {
		$throwNew($IndexOutOfBoundsException, $$str({"fromIndex < 0: "_s, $$str(fromIndex)}));
	}
	if (toIndex < 0) {
		$throwNew($IndexOutOfBoundsException, $$str({"toIndex < 0: "_s, $$str(toIndex)}));
	}
	if (fromIndex > toIndex) {
		$throwNew($IndexOutOfBoundsException, $$str({"fromIndex: "_s, $$str(fromIndex), " > toIndex: "_s, $$str(toIndex)}));
	}
}

void BitSet::flip(int32_t bitIndex) {
	$useLocalCurrentObjectStackCache();
	if (bitIndex < 0) {
		$throwNew($IndexOutOfBoundsException, $$str({"bitIndex < 0: "_s, $$str(bitIndex)}));
	}
	int32_t wordIndex = BitSet::wordIndex(bitIndex);
	expandTo(wordIndex);
	(*$nc(this->words))[wordIndex] ^= ($sl((int64_t)1, bitIndex));
	recalculateWordsInUse();
	checkInvariants();
}

void BitSet::flip(int32_t fromIndex, int32_t toIndex) {
	checkRange(fromIndex, toIndex);
	if (fromIndex == toIndex) {
		return;
	}
	int32_t startWordIndex = wordIndex(fromIndex);
	int32_t endWordIndex = wordIndex(toIndex - 1);
	expandTo(endWordIndex);
	int64_t firstWordMask = $sl(BitSet::WORD_MASK, fromIndex);
	int64_t lastWordMask = $usr(BitSet::WORD_MASK, -toIndex);
	if (startWordIndex == endWordIndex) {
		(*$nc(this->words))[startWordIndex] ^= ((int64_t)(firstWordMask & (uint64_t)lastWordMask));
	} else {
		(*$nc(this->words))[startWordIndex] ^= firstWordMask;
		for (int32_t i = startWordIndex + 1; i < endWordIndex; ++i) {
			(*$nc(this->words))[i] ^= BitSet::WORD_MASK;
		}
		(*$nc(this->words))[endWordIndex] ^= lastWordMask;
	}
	recalculateWordsInUse();
	checkInvariants();
}

void BitSet::set(int32_t bitIndex) {
	$useLocalCurrentObjectStackCache();
	if (bitIndex < 0) {
		$throwNew($IndexOutOfBoundsException, $$str({"bitIndex < 0: "_s, $$str(bitIndex)}));
	}
	int32_t wordIndex = BitSet::wordIndex(bitIndex);
	expandTo(wordIndex);
	(*$nc(this->words))[wordIndex] |= ($sl((int64_t)1, bitIndex));
	checkInvariants();
}

void BitSet::set(int32_t bitIndex, bool value) {
	if (value) {
		set(bitIndex);
	} else {
		clear(bitIndex);
	}
}

void BitSet::set(int32_t fromIndex, int32_t toIndex) {
	checkRange(fromIndex, toIndex);
	if (fromIndex == toIndex) {
		return;
	}
	int32_t startWordIndex = wordIndex(fromIndex);
	int32_t endWordIndex = wordIndex(toIndex - 1);
	expandTo(endWordIndex);
	int64_t firstWordMask = $sl(BitSet::WORD_MASK, fromIndex);
	int64_t lastWordMask = $usr(BitSet::WORD_MASK, -toIndex);
	if (startWordIndex == endWordIndex) {
		(*$nc(this->words))[startWordIndex] |= ((int64_t)(firstWordMask & (uint64_t)lastWordMask));
	} else {
		(*$nc(this->words))[startWordIndex] |= firstWordMask;
		for (int32_t i = startWordIndex + 1; i < endWordIndex; ++i) {
			$nc(this->words)->set(i, BitSet::WORD_MASK);
		}
		(*$nc(this->words))[endWordIndex] |= lastWordMask;
	}
	checkInvariants();
}

void BitSet::set(int32_t fromIndex, int32_t toIndex, bool value) {
	if (value) {
		set(fromIndex, toIndex);
	} else {
		clear(fromIndex, toIndex);
	}
}

void BitSet::clear(int32_t bitIndex) {
	$useLocalCurrentObjectStackCache();
	if (bitIndex < 0) {
		$throwNew($IndexOutOfBoundsException, $$str({"bitIndex < 0: "_s, $$str(bitIndex)}));
	}
	int32_t wordIndex = BitSet::wordIndex(bitIndex);
	if (wordIndex >= this->wordsInUse) {
		return;
	}
	(*$nc(this->words))[wordIndex] &= (uint64_t)~($sl((int64_t)1, bitIndex));
	recalculateWordsInUse();
	checkInvariants();
}

void BitSet::clear(int32_t fromIndex, int32_t toIndex) {
	checkRange(fromIndex, toIndex);
	if (fromIndex == toIndex) {
		return;
	}
	int32_t startWordIndex = wordIndex(fromIndex);
	if (startWordIndex >= this->wordsInUse) {
		return;
	}
	int32_t endWordIndex = wordIndex(toIndex - 1);
	if (endWordIndex >= this->wordsInUse) {
		toIndex = length();
		endWordIndex = this->wordsInUse - 1;
	}
	int64_t firstWordMask = $sl(BitSet::WORD_MASK, fromIndex);
	int64_t lastWordMask = $usr(BitSet::WORD_MASK, -toIndex);
	if (startWordIndex == endWordIndex) {
		(*$nc(this->words))[startWordIndex] &= (uint64_t)~((int64_t)(firstWordMask & (uint64_t)lastWordMask));
	} else {
		(*$nc(this->words))[startWordIndex] &= (uint64_t)~firstWordMask;
		for (int32_t i = startWordIndex + 1; i < endWordIndex; ++i) {
			$nc(this->words)->set(i, 0);
		}
		(*$nc(this->words))[endWordIndex] &= (uint64_t)~lastWordMask;
	}
	recalculateWordsInUse();
	checkInvariants();
}

void BitSet::clear() {
	while (this->wordsInUse > 0) {
		$nc(this->words)->set(--this->wordsInUse, 0);
	}
}

bool BitSet::get(int32_t bitIndex) {
	$useLocalCurrentObjectStackCache();
	if (bitIndex < 0) {
		$throwNew($IndexOutOfBoundsException, $$str({"bitIndex < 0: "_s, $$str(bitIndex)}));
	}
	checkInvariants();
	int32_t wordIndex = BitSet::wordIndex(bitIndex);
	return (wordIndex < this->wordsInUse) && (((int64_t)($nc(this->words)->get(wordIndex) & (uint64_t)($sl((int64_t)1, bitIndex)))) != 0);
}

BitSet* BitSet::get(int32_t fromIndex, int32_t toIndex) {
	checkRange(fromIndex, toIndex);
	checkInvariants();
	int32_t len = length();
	if (len <= fromIndex || fromIndex == toIndex) {
		return $new(BitSet, 0);
	}
	if (toIndex > len) {
		toIndex = len;
	}
	$var(BitSet, result, $new(BitSet, toIndex - fromIndex));
	int32_t targetWords = wordIndex(toIndex - fromIndex - 1) + 1;
	int32_t sourceIndex = wordIndex(fromIndex);
	bool wordAligned = (((int32_t)(fromIndex & (uint32_t)BitSet::BIT_INDEX_MASK)) == 0);
	for (int32_t i = 0; i < targetWords - 1; ++i, ++sourceIndex) {
		$nc(result->words)->set(i, wordAligned ? $nc(this->words)->get(sourceIndex) : ($usr($nc(this->words)->get(sourceIndex), fromIndex)) | ($sl($nc(this->words)->get(sourceIndex + 1), -fromIndex)));
	}
	int64_t lastWordMask = $usr(BitSet::WORD_MASK, -toIndex);
	$nc(result->words)->set(targetWords - 1, ((int32_t)((toIndex - 1) & (uint32_t)BitSet::BIT_INDEX_MASK)) < ((int32_t)(fromIndex & (uint32_t)BitSet::BIT_INDEX_MASK)) ? (($usr($nc(this->words)->get(sourceIndex), fromIndex)) | $sl((int64_t)($nc(this->words)->get(sourceIndex + 1) & (uint64_t)lastWordMask), -fromIndex)) : ($usr((int64_t)($nc(this->words)->get(sourceIndex) & (uint64_t)lastWordMask), fromIndex)));
	result->wordsInUse = targetWords;
	result->recalculateWordsInUse();
	result->checkInvariants();
	return result;
}

int32_t BitSet::nextSetBit(int32_t fromIndex) {
	$useLocalCurrentObjectStackCache();
	if (fromIndex < 0) {
		$throwNew($IndexOutOfBoundsException, $$str({"fromIndex < 0: "_s, $$str(fromIndex)}));
	}
	checkInvariants();
	int32_t u = wordIndex(fromIndex);
	if (u >= this->wordsInUse) {
		return -1;
	}
	int64_t word = (int64_t)($nc(this->words)->get(u) & (uint64_t)($sl(BitSet::WORD_MASK, fromIndex)));
	while (true) {
		if (word != 0) {
			return (u * BitSet::BITS_PER_WORD) + $Long::numberOfTrailingZeros(word);
		}
		if (++u == this->wordsInUse) {
			return -1;
		}
		word = $nc(this->words)->get(u);
	}
}

int32_t BitSet::nextClearBit(int32_t fromIndex) {
	$useLocalCurrentObjectStackCache();
	if (fromIndex < 0) {
		$throwNew($IndexOutOfBoundsException, $$str({"fromIndex < 0: "_s, $$str(fromIndex)}));
	}
	checkInvariants();
	int32_t u = wordIndex(fromIndex);
	if (u >= this->wordsInUse) {
		return fromIndex;
	}
	int64_t word = (int64_t)(~$nc(this->words)->get(u) & (uint64_t)($sl(BitSet::WORD_MASK, fromIndex)));
	while (true) {
		if (word != 0) {
			return (u * BitSet::BITS_PER_WORD) + $Long::numberOfTrailingZeros(word);
		}
		if (++u == this->wordsInUse) {
			return this->wordsInUse * BitSet::BITS_PER_WORD;
		}
		word = ~$nc(this->words)->get(u);
	}
}

int32_t BitSet::previousSetBit(int32_t fromIndex) {
	$useLocalCurrentObjectStackCache();
	if (fromIndex < 0) {
		if (fromIndex == -1) {
			return -1;
		}
		$throwNew($IndexOutOfBoundsException, $$str({"fromIndex < -1: "_s, $$str(fromIndex)}));
	}
	checkInvariants();
	int32_t u = wordIndex(fromIndex);
	if (u >= this->wordsInUse) {
		return length() - 1;
	}
	int64_t word = (int64_t)($nc(this->words)->get(u) & (uint64_t)($usr(BitSet::WORD_MASK, -(fromIndex + 1))));
	while (true) {
		if (word != 0) {
			return (u + 1) * BitSet::BITS_PER_WORD - 1 - $Long::numberOfLeadingZeros(word);
		}
		if (u-- == 0) {
			return -1;
		}
		word = $nc(this->words)->get(u);
	}
}

int32_t BitSet::previousClearBit(int32_t fromIndex) {
	$useLocalCurrentObjectStackCache();
	if (fromIndex < 0) {
		if (fromIndex == -1) {
			return -1;
		}
		$throwNew($IndexOutOfBoundsException, $$str({"fromIndex < -1: "_s, $$str(fromIndex)}));
	}
	checkInvariants();
	int32_t u = wordIndex(fromIndex);
	if (u >= this->wordsInUse) {
		return fromIndex;
	}
	int64_t word = (int64_t)(~$nc(this->words)->get(u) & (uint64_t)($usr(BitSet::WORD_MASK, -(fromIndex + 1))));
	while (true) {
		if (word != 0) {
			return (u + 1) * BitSet::BITS_PER_WORD - 1 - $Long::numberOfLeadingZeros(word);
		}
		if (u-- == 0) {
			return -1;
		}
		word = ~$nc(this->words)->get(u);
	}
}

int32_t BitSet::length() {
	if (this->wordsInUse == 0) {
		return 0;
	}
	return BitSet::BITS_PER_WORD * (this->wordsInUse - 1) + (BitSet::BITS_PER_WORD - $Long::numberOfLeadingZeros($nc(this->words)->get(this->wordsInUse - 1)));
}

bool BitSet::isEmpty() {
	return this->wordsInUse == 0;
}

bool BitSet::intersects(BitSet* set) {
	for (int32_t i = $Math::min(this->wordsInUse, $nc(set)->wordsInUse) - 1; i >= 0; --i) {
		if (((int64_t)($nc(this->words)->get(i) & (uint64_t)$nc($nc(set)->words)->get(i))) != 0) {
			return true;
		}
	}
	return false;
}

int32_t BitSet::cardinality() {
	int32_t sum = 0;
	for (int32_t i = 0; i < this->wordsInUse; ++i) {
		sum += $Long::bitCount($nc(this->words)->get(i));
	}
	return sum;
}

void BitSet::and$(BitSet* set) {
	if (this == set) {
		return;
	}
	while (this->wordsInUse > $nc(set)->wordsInUse) {
		$nc(this->words)->set(--this->wordsInUse, 0);
	}
	for (int32_t i = 0; i < this->wordsInUse; ++i) {
		(*$nc(this->words))[i] &= (uint64_t)$nc($nc(set)->words)->get(i);
	}
	recalculateWordsInUse();
	checkInvariants();
}

void BitSet::or$(BitSet* set) {
	if (this == set) {
		return;
	}
	int32_t wordsInCommon = $Math::min(this->wordsInUse, $nc(set)->wordsInUse);
	if (this->wordsInUse < $nc(set)->wordsInUse) {
		ensureCapacity(set->wordsInUse);
		this->wordsInUse = set->wordsInUse;
	}
	for (int32_t i = 0; i < wordsInCommon; ++i) {
		(*$nc(this->words))[i] |= $nc($nc(set)->words)->get(i);
	}
	if (wordsInCommon < $nc(set)->wordsInUse) {
		$System::arraycopy(set->words, wordsInCommon, this->words, wordsInCommon, this->wordsInUse - wordsInCommon);
	}
	checkInvariants();
}

void BitSet::xor$(BitSet* set) {
	int32_t wordsInCommon = $Math::min(this->wordsInUse, $nc(set)->wordsInUse);
	if (this->wordsInUse < $nc(set)->wordsInUse) {
		ensureCapacity(set->wordsInUse);
		this->wordsInUse = set->wordsInUse;
	}
	for (int32_t i = 0; i < wordsInCommon; ++i) {
		(*$nc(this->words))[i] ^= $nc($nc(set)->words)->get(i);
	}
	if (wordsInCommon < $nc(set)->wordsInUse) {
		$System::arraycopy(set->words, wordsInCommon, this->words, wordsInCommon, set->wordsInUse - wordsInCommon);
	}
	recalculateWordsInUse();
	checkInvariants();
}

void BitSet::andNot(BitSet* set) {
	for (int32_t i = $Math::min(this->wordsInUse, $nc(set)->wordsInUse) - 1; i >= 0; --i) {
		(*$nc(this->words))[i] &= (uint64_t)~$nc($nc(set)->words)->get(i);
	}
	recalculateWordsInUse();
	checkInvariants();
}

int32_t BitSet::hashCode() {
	int64_t h = 1234;
	for (int32_t i = this->wordsInUse; --i >= 0;) {
		h ^= $nc(this->words)->get(i) * (i + 1);
	}
	return (int32_t)((h >> 32) ^ h);
}

int32_t BitSet::size() {
	return $nc(this->words)->length * BitSet::BITS_PER_WORD;
}

bool BitSet::equals(Object$* obj) {
	$var(BitSet, set, nullptr);
	bool var$0 = $instanceOf(BitSet, obj);
	if (var$0) {
		$assign(set, $cast(BitSet, obj));
		var$0 = true;
	}
	if (!(var$0)) {
		return false;
	}
	if ($equals(this, obj)) {
		return true;
	}
	checkInvariants();
	$nc(set)->checkInvariants();
	if (this->wordsInUse != set->wordsInUse) {
		return false;
	}
	for (int32_t i = 0; i < this->wordsInUse; ++i) {
		if ($nc(this->words)->get(i) != $nc(set->words)->get(i)) {
			return false;
		}
	}
	return true;
}

$Object* BitSet::clone() {
	if (!this->sizeIsSticky) {
		trimToSize();
	}
	try {
		$var(BitSet, result, $cast(BitSet, $Cloneable::clone()));
		$set($nc(result), words, $cast($longs, $nc(this->words)->clone()));
		result->checkInvariants();
		return $of(result);
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

void BitSet::trimToSize() {
	if (this->wordsInUse != $nc(this->words)->length) {
		$set(this, words, $Arrays::copyOf(this->words, this->wordsInUse));
		checkInvariants();
	}
}

void BitSet::writeObject($ObjectOutputStream* s) {
	checkInvariants();
	if (!this->sizeIsSticky) {
		trimToSize();
	}
	$var($ObjectOutputStream$PutField, fields, $nc(s)->putFields());
	$nc(fields)->put("bits"_s, $of(this->words));
	s->writeFields();
}

void BitSet::readObject($ObjectInputStream* s) {
	$var($ObjectInputStream$GetField, fields, $nc(s)->readFields());
	$set(this, words, $cast($longs, $nc(fields)->get("bits"_s, ($Object*)nullptr)));
	this->wordsInUse = $nc(this->words)->length;
	recalculateWordsInUse();
	this->sizeIsSticky = ($nc(this->words)->length > 0 && $nc(this->words)->get($nc(this->words)->length - 1) == (int64_t)0);
	checkInvariants();
}

$String* BitSet::toString() {
	checkInvariants();
	int32_t MAX_INITIAL_CAPACITY = $Integer::MAX_VALUE - 8;
	int32_t numBits = (this->wordsInUse > 128) ? cardinality() : this->wordsInUse * BitSet::BITS_PER_WORD;
	int32_t initialCapacity = (numBits <= (MAX_INITIAL_CAPACITY - 2) / 6) ? 6 * numBits + 2 : MAX_INITIAL_CAPACITY;
	$var($StringBuilder, b, $new($StringBuilder, initialCapacity));
	b->append(u'{');
	int32_t i = nextSetBit(0);
	if (i != -1) {
		b->append(i);
		while (true) {
			if (++i < 0) {
				break;
			}
			if ((i = nextSetBit(i)) < 0) {
				break;
			}
			int32_t endOfRun = nextClearBit(i);
			do {
				b->append(", "_s)->append(i);
			} while (++i != endOfRun);
		}
	}
	b->append(u'}');
	return b->toString();
}

$IntStream* BitSet::stream() {
	{
	}
	return $StreamSupport::intStream($$new($BitSet$1BitSetSpliterator, this, 0, -1, 0, true), false);
}

int32_t BitSet::nextSetBit(int32_t fromIndex, int32_t toWordIndex) {
	int32_t u = wordIndex(fromIndex);
	if (u > toWordIndex) {
		return -1;
	}
	int64_t word = (int64_t)($nc(this->words)->get(u) & (uint64_t)($sl(BitSet::WORD_MASK, fromIndex)));
	while (true) {
		if (word != 0) {
			return (u * BitSet::BITS_PER_WORD) + $Long::numberOfTrailingZeros(word);
		}
		if (++u > toWordIndex) {
			return -1;
		}
		word = $nc(this->words)->get(u);
	}
}

void clinit$BitSet($Class* class$) {
	BitSet::$assertionsDisabled = !BitSet::class$->desiredAssertionStatus();
	$load($longs);
	$assignStatic(BitSet::serialPersistentFields, $new($ObjectStreamFieldArray, {$$new($ObjectStreamField, "bits"_s, $getClass($longs))}));
}

BitSet::BitSet() {
}

$Class* BitSet::load$($String* name, bool initialize) {
	$loadClass(BitSet, name, initialize, &_BitSet_ClassInfo_, clinit$BitSet, allocate$BitSet);
	return class$;
}

$Class* BitSet::class$ = nullptr;

	} // util
} // java