#include <sun/text/BreakDictionary.h>

#include <java/lang/AssertionError.h>
#include <java/nio/BufferUnderflowException.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/MissingResourceException.h>
#include <sun/text/CompactByteArray.h>
#include <sun/text/SupplementaryCharacterData.h>
#include <jcpp.h>

#undef MIN_SUPPLEMENTARY_CODE_POINT

using $AssertionError = ::java::lang::AssertionError;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BufferUnderflowException = ::java::nio::BufferUnderflowException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $MissingResourceException = ::java::util::MissingResourceException;
using $CompactByteArray = ::sun::text::CompactByteArray;
using $SupplementaryCharacterData = ::sun::text::SupplementaryCharacterData;

namespace sun {
	namespace text {

$FieldInfo _BreakDictionary_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(BreakDictionary, $assertionsDisabled)},
	{"supportedVersion", "I", nullptr, $PRIVATE | $STATIC, $staticField(BreakDictionary, supportedVersion)},
	{"columnMap", "Lsun/text/CompactByteArray;", nullptr, $PRIVATE, $field(BreakDictionary, columnMap)},
	{"supplementaryCharColumnMap", "Lsun/text/SupplementaryCharacterData;", nullptr, $PRIVATE, $field(BreakDictionary, supplementaryCharColumnMap)},
	{"numCols", "I", nullptr, $PRIVATE, $field(BreakDictionary, numCols)},
	{"numColGroups", "I", nullptr, $PRIVATE, $field(BreakDictionary, numColGroups)},
	{"table", "[S", nullptr, $PRIVATE, $field(BreakDictionary, table)},
	{"rowIndex", "[S", nullptr, $PRIVATE, $field(BreakDictionary, rowIndex)},
	{"rowIndexFlags", "[I", nullptr, $PRIVATE, $field(BreakDictionary, rowIndexFlags)},
	{"rowIndexFlagsIndex", "[S", nullptr, $PRIVATE, $field(BreakDictionary, rowIndexFlagsIndex)},
	{"rowIndexShifts", "[B", nullptr, $PRIVATE, $field(BreakDictionary, rowIndexShifts)},
	{}
};

$MethodInfo _BreakDictionary_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;[B)V", nullptr, 0, $method(BreakDictionary, init$, void, $String*, $bytes*)},
	{"cellIsPopulated", "(II)Z", nullptr, $PRIVATE, $method(BreakDictionary, cellIsPopulated, bool, int32_t, int32_t)},
	{"getNextState", "(II)S", nullptr, $PUBLIC | $FINAL, $method(BreakDictionary, getNextState, int16_t, int32_t, int32_t)},
	{"getNextStateFromCharacter", "(II)S", nullptr, $PUBLIC | $FINAL, $method(BreakDictionary, getNextStateFromCharacter, int16_t, int32_t, int32_t)},
	{"internalAt", "(II)S", nullptr, $PRIVATE, $method(BreakDictionary, internalAt, int16_t, int32_t, int32_t)},
	{"setupDictionary", "(Ljava/lang/String;[B)V", nullptr, $PRIVATE, $method(BreakDictionary, setupDictionary, void, $String*, $bytes*)},
	{}
};

$ClassInfo _BreakDictionary_ClassInfo_ = {
	$ACC_SUPER,
	"sun.text.BreakDictionary",
	"java.lang.Object",
	nullptr,
	_BreakDictionary_FieldInfo_,
	_BreakDictionary_MethodInfo_
};

$Object* allocate$BreakDictionary($Class* clazz) {
	return $of($alloc(BreakDictionary));
}

bool BreakDictionary::$assertionsDisabled = false;
int32_t BreakDictionary::supportedVersion = 0;

void BreakDictionary::init$($String* dictionaryName, $bytes* dictionaryData) {
	$set(this, columnMap, nullptr);
	$set(this, supplementaryCharColumnMap, nullptr);
	$set(this, table, nullptr);
	$set(this, rowIndex, nullptr);
	$set(this, rowIndexFlags, nullptr);
	$set(this, rowIndexFlagsIndex, nullptr);
	$set(this, rowIndexShifts, nullptr);
	try {
		setupDictionary(dictionaryName, dictionaryData);
	} catch ($BufferUnderflowException& bue) {
		$var($MissingResourceException, e, nullptr);
		$assign(e, $new($MissingResourceException, "Corrupted dictionary data"_s, dictionaryName, ""_s));
		e->initCause(bue);
		$throw(e);
	}
}

void BreakDictionary::setupDictionary($String* dictionaryName, $bytes* dictionaryData) {
	$useLocalCurrentObjectStackCache();
	$var($ByteBuffer, bb, $ByteBuffer::wrap(dictionaryData));
	int32_t version = $nc(bb)->getInt();
	if (version != BreakDictionary::supportedVersion) {
		$throwNew($MissingResourceException, $$str({"Dictionary version("_s, $$str(version), ") is unsupported"_s}), dictionaryName, ""_s);
	}
	int32_t len = bb->getInt();
	int32_t var$0 = bb->position() + len;
	if (var$0 != bb->limit()) {
		$throwNew($MissingResourceException, $$str({"Dictionary size is wrong: "_s, $$str(bb->limit())}), dictionaryName, ""_s);
	}
	len = bb->getInt();
	$var($shorts, temp, $new($shorts, len));
	for (int32_t i = 0; i < len; ++i) {
		temp->set(i, bb->getShort());
	}
	len = bb->getInt();
	$var($bytes, temp2, $new($bytes, len));
	bb->get(temp2);
	$set(this, columnMap, $new($CompactByteArray, temp, temp2));
	this->numCols = bb->getInt();
	this->numColGroups = bb->getInt();
	len = bb->getInt();
	$set(this, rowIndex, $new($shorts, len));
	for (int32_t i = 0; i < len; ++i) {
		$nc(this->rowIndex)->set(i, bb->getShort());
	}
	len = bb->getInt();
	$set(this, rowIndexFlagsIndex, $new($shorts, len));
	for (int32_t i = 0; i < len; ++i) {
		$nc(this->rowIndexFlagsIndex)->set(i, bb->getShort());
	}
	len = bb->getInt();
	$set(this, rowIndexFlags, $new($ints, len));
	for (int32_t i = 0; i < len; ++i) {
		$nc(this->rowIndexFlags)->set(i, bb->getInt());
	}
	len = bb->getInt();
	$set(this, rowIndexShifts, $new($bytes, len));
	bb->get(this->rowIndexShifts);
	len = bb->getInt();
	$set(this, table, $new($shorts, len));
	for (int32_t i = 0; i < len; ++i) {
		$nc(this->table)->set(i, bb->getShort());
	}
	len = bb->getInt();
	$var($ints, temp3, $new($ints, len));
	for (int32_t i = 0; i < len; ++i) {
		temp3->set(i, bb->getInt());
	}
	bool var$1 = !BreakDictionary::$assertionsDisabled;
	if (var$1) {
		int32_t var$2 = bb->position();
		var$1 = !(var$2 == bb->limit());
	}
	if (var$1) {
		$throwNew($AssertionError);
	}
	$set(this, supplementaryCharColumnMap, $new($SupplementaryCharacterData, temp3));
}

int16_t BreakDictionary::getNextStateFromCharacter(int32_t row, int32_t ch) {
	int32_t col = 0;
	if (ch < $Character::MIN_SUPPLEMENTARY_CODE_POINT) {
		col = $nc(this->columnMap)->elementAt((char16_t)ch);
	} else {
		col = $nc(this->supplementaryCharColumnMap)->getValue(ch);
	}
	return getNextState(row, col);
}

int16_t BreakDictionary::getNextState(int32_t row, int32_t col) {
	if (cellIsPopulated(row, col)) {
		return internalAt($nc(this->rowIndex)->get(row), col + $nc(this->rowIndexShifts)->get(row));
	} else {
		return (int16_t)0;
	}
}

bool BreakDictionary::cellIsPopulated(int32_t row, int32_t col) {
	if ($nc(this->rowIndexFlagsIndex)->get(row) < 0) {
		return col == -$nc(this->rowIndexFlagsIndex)->get(row);
	} else {
		int32_t flags = $nc(this->rowIndexFlags)->get($nc(this->rowIndexFlagsIndex)->get(row) + (col >> 5));
		return ((int32_t)(flags & (uint32_t)($sl(1, (int32_t)(col & (uint32_t)31))))) != 0;
	}
}

int16_t BreakDictionary::internalAt(int32_t row, int32_t col) {
	return $nc(this->table)->get(row * this->numCols + col);
}

void clinit$BreakDictionary($Class* class$) {
	BreakDictionary::$assertionsDisabled = !BreakDictionary::class$->desiredAssertionStatus();
	BreakDictionary::supportedVersion = 1;
}

BreakDictionary::BreakDictionary() {
}

$Class* BreakDictionary::load$($String* name, bool initialize) {
	$loadClass(BreakDictionary, name, initialize, &_BreakDictionary_ClassInfo_, clinit$BreakDictionary, allocate$BreakDictionary);
	return class$;
}

$Class* BreakDictionary::class$ = nullptr;

	} // text
} // sun