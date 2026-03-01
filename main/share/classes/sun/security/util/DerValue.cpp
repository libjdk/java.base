#include <sun/security/util/DerValue.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/EOFException.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/math/BigInteger.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Date.h>
#include <java/util/List.h>
#include <java/util/TimeZone.h>
#include <sun/nio/cs/UTF_32BE.h>
#include <sun/security/util/BitArray.h>
#include <sun/security/util/DerIndefLenConverter.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/IOUtils.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/util/calendar/CalendarDate.h>
#include <sun/util/calendar/CalendarSystem.h>
#include <sun/util/calendar/Gregorian.h>
#include <jcpp.h>

#undef MAX_VALUE
#undef MIN_VALUE
#undef TAG_APPLICATION
#undef TAG_CONTEXT
#undef TAG_PRIVATE
#undef TAG_UNIVERSAL
#undef US_ASCII
#undef UTF_16BE
#undef UTF_8

using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $EOFException = ::java::io::EOFException;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Date = ::java::util::Date;
using $List = ::java::util::List;
using $TimeZone = ::java::util::TimeZone;
using $UTF_32BE = ::sun::nio::cs::UTF_32BE;
using $BitArray = ::sun::security::util::BitArray;
using $DerIndefLenConverter = ::sun::security::util::DerIndefLenConverter;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $IOUtils = ::sun::security::util::IOUtils;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $CalendarDate = ::sun::util::calendar::CalendarDate;
using $CalendarSystem = ::sun::util::calendar::CalendarSystem;

namespace sun {
	namespace security {
		namespace util {

$FieldInfo _DerValue_FieldInfo_[] = {
	{"TAG_UNIVERSAL", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, TAG_UNIVERSAL)},
	{"TAG_APPLICATION", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, TAG_APPLICATION)},
	{"TAG_CONTEXT", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, TAG_CONTEXT)},
	{"TAG_PRIVATE", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, TAG_PRIVATE)},
	{"tag_Boolean", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, tag_Boolean)},
	{"tag_Integer", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, tag_Integer)},
	{"tag_BitString", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, tag_BitString)},
	{"tag_OctetString", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, tag_OctetString)},
	{"tag_Null", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, tag_Null)},
	{"tag_ObjectId", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, tag_ObjectId)},
	{"tag_Enumerated", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, tag_Enumerated)},
	{"tag_UTF8String", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, tag_UTF8String)},
	{"tag_PrintableString", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, tag_PrintableString)},
	{"tag_T61String", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, tag_T61String)},
	{"tag_IA5String", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, tag_IA5String)},
	{"tag_UtcTime", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, tag_UtcTime)},
	{"tag_GeneralizedTime", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, tag_GeneralizedTime)},
	{"tag_GeneralString", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, tag_GeneralString)},
	{"tag_UniversalString", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, tag_UniversalString)},
	{"tag_BMPString", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, tag_BMPString)},
	{"tag_Sequence", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, tag_Sequence)},
	{"tag_SequenceOf", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, tag_SequenceOf)},
	{"tag_Set", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, tag_Set)},
	{"tag_SetOf", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DerValue, tag_SetOf)},
	{"tag", "B", nullptr, $PUBLIC, $field(DerValue, tag)},
	{"buffer", "[B", nullptr, $FINAL, $field(DerValue, buffer)},
	{"start", "I", nullptr, $PRIVATE | $FINAL, $field(DerValue, start)},
	{"end", "I", nullptr, $FINAL, $field(DerValue, end)},
	{"allowBER", "Z", nullptr, $PRIVATE | $FINAL, $field(DerValue, allowBER)},
	{"data", "Lsun/security/util/DerInputStream;", nullptr, $PUBLIC | $FINAL, $field(DerValue, data$)},
	{}
};

$MethodInfo _DerValue_MethodInfo_[] = {
	{"<init>", "(B[BIIZ)V", nullptr, 0, $method(DerValue, init$, void, int8_t, $bytes*, int32_t, int32_t, bool)},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(DerValue, init$, void, $String*)},
	{"<init>", "(BLjava/lang/String;)V", nullptr, $PUBLIC, $method(DerValue, init$, void, int8_t, $String*)},
	{"<init>", "(B[BZ)V", nullptr, 0, $method(DerValue, init$, void, int8_t, $bytes*, bool)},
	{"<init>", "(B[B)V", nullptr, $PUBLIC, $method(DerValue, init$, void, int8_t, $bytes*)},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(DerValue, init$, void, $bytes*), "java.io.IOException"},
	{"<init>", "([BIIZZ)V", nullptr, 0, $method(DerValue, init$, void, $bytes*, int32_t, int32_t, bool, bool), "java.io.IOException"},
	{"<init>", "(Ljava/io/InputStream;Z)V", nullptr, 0, $method(DerValue, init$, void, $InputStream*, bool), "java.io.IOException"},
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(DerValue, init$, void, $InputStream*), "java.io.IOException"},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(DerValue, clear, void)},
	{"createTag", "(BZB)B", nullptr, $PUBLIC | $STATIC, $staticMethod(DerValue, createTag, int8_t, int8_t, bool, int8_t)},
	{"data", "()Lsun/security/util/DerInputStream;", nullptr, $PUBLIC | $FINAL, $method(DerValue, data, $DerInputStream*)},
	{"encode", "(Lsun/security/util/DerOutputStream;)V", nullptr, $PUBLIC, $virtualMethod(DerValue, encode, void, $DerOutputStream*), "java.io.IOException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(DerValue, equals, bool, Object$*)},
	{"getAsString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DerValue, getAsString, $String*), "java.io.IOException"},
	{"getBMPString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DerValue, getBMPString, $String*), "java.io.IOException"},
	{"getBigInteger", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(DerValue, getBigInteger, $BigInteger*), "java.io.IOException"},
	{"getBigIntegerInternal", "(BZ)Ljava/math/BigInteger;", nullptr, $PRIVATE, $method(DerValue, getBigIntegerInternal, $BigInteger*, int8_t, bool), "java.io.IOException"},
	{"getBitString", "()[B", nullptr, $PUBLIC, $virtualMethod(DerValue, getBitString, $bytes*), "java.io.IOException"},
	{"getBitString", "(Z)[B", nullptr, $PUBLIC, $virtualMethod(DerValue, getBitString, $bytes*, bool), "java.io.IOException"},
	{"getBoolean", "()Z", nullptr, $PUBLIC, $virtualMethod(DerValue, getBoolean, bool), "java.io.IOException"},
	{"getData", "()Lsun/security/util/DerInputStream;", nullptr, $PUBLIC | $FINAL, $method(DerValue, getData, $DerInputStream*)},
	{"getDataBytes", "()[B", nullptr, $PUBLIC, $virtualMethod(DerValue, getDataBytes, $bytes*), "java.io.IOException"},
	{"getEnumerated", "()I", nullptr, $PUBLIC, $virtualMethod(DerValue, getEnumerated, int32_t), "java.io.IOException"},
	{"getGeneralString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DerValue, getGeneralString, $String*), "java.io.IOException"},
	{"getGeneralizedTime", "()Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(DerValue, getGeneralizedTime, $Date*), "java.io.IOException"},
	{"getIA5String", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DerValue, getIA5String, $String*), "java.io.IOException"},
	{"getInteger", "()I", nullptr, $PUBLIC, $virtualMethod(DerValue, getInteger, int32_t), "java.io.IOException"},
	{"getIntegerInternal", "(B)I", nullptr, $PRIVATE, $method(DerValue, getIntegerInternal, int32_t, int8_t), "java.io.IOException"},
	{"getNull", "()V", nullptr, $PUBLIC, $virtualMethod(DerValue, getNull, void), "java.io.IOException"},
	{"getOID", "()Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC, $virtualMethod(DerValue, getOID, $ObjectIdentifier*), "java.io.IOException"},
	{"getOctetString", "()[B", nullptr, $PUBLIC, $virtualMethod(DerValue, getOctetString, $bytes*), "java.io.IOException"},
	{"getPositiveBigInteger", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(DerValue, getPositiveBigInteger, $BigInteger*), "java.io.IOException"},
	{"getPrintableString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DerValue, getPrintableString, $String*), "java.io.IOException"},
	{"getT61String", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DerValue, getT61String, $String*), "java.io.IOException"},
	{"getTag", "()B", nullptr, $PUBLIC | $FINAL, $method(DerValue, getTag, int8_t)},
	{"getTimeInternal", "(Z)Ljava/util/Date;", nullptr, $PRIVATE, $method(DerValue, getTimeInternal, $Date*, bool), "java.io.IOException"},
	{"getUTCTime", "()Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(DerValue, getUTCTime, $Date*), "java.io.IOException"},
	{"getUTF8String", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DerValue, getUTF8String, $String*), "java.io.IOException"},
	{"getUnalignedBitString", "()Lsun/security/util/BitArray;", nullptr, $PUBLIC, $virtualMethod(DerValue, getUnalignedBitString, $BitArray*), "java.io.IOException"},
	{"getUnalignedBitString", "(Z)Lsun/security/util/BitArray;", nullptr, $PUBLIC, $virtualMethod(DerValue, getUnalignedBitString, $BitArray*, bool), "java.io.IOException"},
	{"getUniversalString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DerValue, getUniversalString, $String*), "java.io.IOException"},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(DerValue, hashCode, int32_t)},
	{"isApplication", "()Z", nullptr, $PUBLIC, $virtualMethod(DerValue, isApplication, bool)},
	{"isConstructed", "()Z", nullptr, $PUBLIC, $virtualMethod(DerValue, isConstructed, bool)},
	{"isConstructed", "(B)Z", nullptr, $PUBLIC, $virtualMethod(DerValue, isConstructed, bool, int8_t)},
	{"isContextSpecific", "()Z", nullptr, $PUBLIC, $virtualMethod(DerValue, isContextSpecific, bool)},
	{"isContextSpecific", "(B)Z", nullptr, $PUBLIC, $virtualMethod(DerValue, isContextSpecific, bool, int8_t)},
	{"isPrintableString", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(DerValue, isPrintableString, bool, $String*)},
	{"isPrintableStringChar", "(C)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(DerValue, isPrintableStringChar, bool, char16_t)},
	{"isPrivate", "()Z", nullptr, 0, $virtualMethod(DerValue, isPrivate, bool)},
	{"isUniversal", "()Z", nullptr, $PUBLIC, $virtualMethod(DerValue, isUniversal, bool)},
	{"length", "()I", nullptr, $PUBLIC, $virtualMethod(DerValue, length, int32_t)},
	{"readStringInternal", "(BLjava/nio/charset/Charset;)Ljava/lang/String;", nullptr, $PRIVATE, $method(DerValue, readStringInternal, $String*, int8_t, $Charset*), "java.io.IOException"},
	{"resetTag", "(B)V", nullptr, $PUBLIC, $virtualMethod(DerValue, resetTag, void, int8_t)},
	{"string2bytes", "(BLjava/lang/String;)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(DerValue, string2bytes, $bytes*, int8_t, $String*)},
	{"subs", "(BI)[Lsun/security/util/DerValue;", nullptr, 0, $virtualMethod(DerValue, subs, $DerValueArray*, int8_t, int32_t), "java.io.IOException"},
	{"toByteArray", "()[B", nullptr, $PUBLIC, $virtualMethod(DerValue, toByteArray, $bytes*), "java.io.IOException"},
	{"toDerInputStream", "()Lsun/security/util/DerInputStream;", nullptr, $PUBLIC, $virtualMethod(DerValue, toDerInputStream, $DerInputStream*), "java.io.IOException"},
	{"toDigit", "(BLjava/lang/String;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(DerValue, toDigit, int32_t, int8_t, $String*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DerValue, toString, $String*)},
	{"withTag", "(B)Lsun/security/util/DerValue;", nullptr, $PUBLIC, $virtualMethod(DerValue, withTag, DerValue*, int8_t)},
	{"wrap", "(BLsun/security/util/DerOutputStream;)Lsun/security/util/DerValue;", nullptr, $PUBLIC | $STATIC, $staticMethod(DerValue, wrap, DerValue*, int8_t, $DerOutputStream*)},
	{}
};

$ClassInfo _DerValue_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.util.DerValue",
	"java.lang.Object",
	nullptr,
	_DerValue_FieldInfo_,
	_DerValue_MethodInfo_
};

$Object* allocate$DerValue($Class* clazz) {
	return $of($alloc(DerValue));
}

bool DerValue::isUniversal() {
	return (((int32_t)(this->tag & (uint32_t)192)) == 0);
}

bool DerValue::isApplication() {
	return (((int32_t)(this->tag & (uint32_t)192)) == 64);
}

bool DerValue::isContextSpecific() {
	return (((int32_t)(this->tag & (uint32_t)192)) == 128);
}

bool DerValue::isContextSpecific(int8_t cntxtTag) {
	if (!isContextSpecific()) {
		return false;
	}
	return (((int32_t)(this->tag & (uint32_t)31)) == cntxtTag);
}

bool DerValue::isPrivate() {
	return (((int32_t)(this->tag & (uint32_t)192)) == 192);
}

bool DerValue::isConstructed() {
	return (((int32_t)(this->tag & (uint32_t)32)) == 32);
}

bool DerValue::isConstructed(int8_t constructedTag) {
	if (!isConstructed()) {
		return false;
	}
	return (((int32_t)(this->tag & (uint32_t)31)) == constructedTag);
}

void DerValue::init$(int8_t tag, $bytes* buffer, int32_t start, int32_t end, bool allowBER) {
	if (((int32_t)(tag & (uint32_t)31)) == 31) {
		$throwNew($IllegalArgumentException, "Tag number over 30 is not supported"_s);
	}
	this->tag = tag;
	$set(this, buffer, buffer);
	this->start = start;
	this->end = end;
	this->allowBER = allowBER;
	$set(this, data$, data());
}

void DerValue::init$($String* value) {
	DerValue::init$(isPrintableString(value) ? DerValue::tag_PrintableString : DerValue::tag_UTF8String, value);
}

bool DerValue::isPrintableString($String* value) {
	for (int32_t i = 0; i < $nc(value)->length(); ++i) {
		if (!isPrintableStringChar(value->charAt(i))) {
			return false;
		}
	}
	return true;
}

void DerValue::init$(int8_t stringTag, $String* value) {
	DerValue::init$(stringTag, $(string2bytes(stringTag, value)), false);
}

$bytes* DerValue::string2bytes(int8_t stringTag, $String* value) {
	$useLocalCurrentObjectStackCache();

	$var($Charset, var$0, nullptr)
	switch (stringTag) {
	case DerValue::tag_PrintableString:
		{}
	case DerValue::tag_IA5String:
		{}
	case DerValue::tag_GeneralString:
		{
			$init($StandardCharsets);
			$assign(var$0, $StandardCharsets::US_ASCII);
			break;
		}
	case DerValue::tag_T61String:
		{
			$init($StandardCharsets);
			$assign(var$0, $StandardCharsets::ISO_8859_1);
			break;
		}
	case DerValue::tag_BMPString:
		{
			$init($StandardCharsets);
			$assign(var$0, $StandardCharsets::UTF_16BE);
			break;
		}
	case DerValue::tag_UTF8String:
		{
			$init($StandardCharsets);
			$assign(var$0, $StandardCharsets::UTF_8);
			break;
		}
	case DerValue::tag_UniversalString:
		{
			$assign(var$0, $Charset::forName("UTF_32BE"_s));
			break;
		}
	default:
		{
			$throwNew($IllegalArgumentException, "Unsupported DER string type"_s);
		}
	}
	$var($Charset, charset, var$0);
	return $nc(value)->getBytes(charset);
}

void DerValue::init$(int8_t tag, $bytes* buffer, bool allowBER) {
	DerValue::init$(tag, buffer, 0, $nc(buffer)->length, allowBER);
}

void DerValue::init$(int8_t tag, $bytes* buffer) {
	DerValue::init$(tag, $cast($bytes, $($nc(buffer)->clone())), true);
}

DerValue* DerValue::wrap(int8_t tag, $DerOutputStream* out) {
	int8_t var$0 = tag;
	$var($bytes, var$1, $nc(out)->buf());
	return $new(DerValue, var$0, var$1, 0, out->size(), false);
}

void DerValue::init$($bytes* encoding) {
	DerValue::init$($cast($bytes, $($nc(encoding)->clone())), 0, encoding->length, true, false);
}

void DerValue::init$($bytes* buf$renamed, int32_t offset, int32_t len, bool allowBER, bool allowMore) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, buf, buf$renamed);
	if (len < 2) {
		$throwNew($IOException, "Too short"_s);
	}
	int32_t pos = offset;
	this->tag = $nc(buf)->get(pos++);
	if (((int32_t)(this->tag & (uint32_t)31)) == 31) {
		$throwNew($IOException, $$str({"Tag number over 30 at "_s, $$str(offset), " is not supported"_s}));
	}
	int32_t lenByte = buf->get(pos++);
	int32_t length = 0;
	if (lenByte == (int8_t)128) {
		if (!allowBER) {
			$throwNew($IOException, "Indefinite length encoding not supported with DER"_s);
		}
		if (!isConstructed()) {
			$throwNew($IOException, "Indefinite length encoding not supported with non-constructed data"_s);
		}
		$assign(buf, $DerIndefLenConverter::convertStream($$new($ByteArrayInputStream, buf, pos, len - (pos - offset)), this->tag));
		offset = 0;
		len = $nc(buf)->length;
		pos = 2;
		if (this->tag != buf->get(0)) {
			$throwNew($IOException, "Indefinite length encoding not supported"_s);
		}
		lenByte = buf->get(1);
		if (lenByte == (int8_t)128) {
			$throwNew($IOException, "Indefinite len conversion failed"_s);
		}
	}
	if (((int32_t)(lenByte & (uint32_t)128)) == 0) {
		length = lenByte;
	} else {
		lenByte &= (uint32_t)127;
		if (lenByte > 4) {
			$throwNew($IOException, "Invalid lenByte"_s);
		}
		if (len < 2 + lenByte) {
			$throwNew($IOException, "Not enough length bytes"_s);
		}
		length = (int32_t)(255 & (uint32_t)(int32_t)buf->get(pos++));
		--lenByte;
		if (length == 0 && !allowBER) {
			$throwNew($IOException, "Redundant length bytes found"_s);
		}
		while (lenByte-- > 0) {
			length <<= 8;
			length += (int32_t)(255 & (uint32_t)(int32_t)buf->get(pos++));
		}
		if (length < 0) {
			$throwNew($IOException, "Invalid length bytes"_s);
		} else if (length <= 127 && !allowBER) {
			$throwNew($IOException, "Should use short form for length"_s);
		}
	}
	if (len - length < pos - offset) {
		$throwNew($EOFException, "not enough content"_s);
	}
	if (len - length > pos - offset && !allowMore) {
		$throwNew($IOException, "extra data at the end"_s);
	}
	$set(this, buffer, buf);
	this->start = pos;
	this->end = pos + length;
	this->allowBER = allowBER;
	$set(this, data$, data());
}

void DerValue::init$($InputStream* in, bool allowBER) {
	this->tag = (int8_t)$nc(in)->read();
	if (((int32_t)(this->tag & (uint32_t)31)) == 31) {
		$throwNew($IOException, "Tag number over 30 is not supported"_s);
	}
	int32_t length = $DerInputStream::getLength(in);
	if (length == -1) {
		if (!allowBER) {
			$throwNew($IOException, "Indefinite length encoding not supported with DER"_s);
		}
		if (!isConstructed()) {
			$throwNew($IOException, "Indefinite length encoding not supported with non-constructed data"_s);
		}
		$set(this, buffer, $DerIndefLenConverter::convertStream(in, this->tag));
		$var($ByteArrayInputStream, bin, $new($ByteArrayInputStream, this->buffer));
		if (this->tag != bin->read()) {
			$throwNew($IOException, "Indefinite length encoding not supported"_s);
		}
		length = $DerInputStream::getDefiniteLength(bin);
		this->start = $nc(this->buffer)->length - bin->available();
		this->end = this->start + length;
	} else {
		$set(this, buffer, $IOUtils::readExactlyNBytes(in, length));
		this->start = 0;
		this->end = length;
	}
	this->allowBER = allowBER;
	$set(this, data$, data());
}

void DerValue::init$($InputStream* in) {
	DerValue::init$(in, true);
}

void DerValue::encode($DerOutputStream* out) {
	$nc(out)->write((int32_t)this->tag);
	out->putLength(this->end - this->start);
	out->write(this->buffer, this->start, this->end - this->start);
	$nc(this->data$)->pos = $nc(this->data$)->end;
}

$DerInputStream* DerValue::data() {
	return $new($DerInputStream, this->buffer, this->start, this->end - this->start, this->allowBER);
}

$DerInputStream* DerValue::getData() {
	return this->data$;
}

int8_t DerValue::getTag() {
	return this->tag;
}

bool DerValue::getBoolean() {
	$useLocalCurrentObjectStackCache();
	if (this->tag != DerValue::tag_Boolean) {
		$throwNew($IOException, $$str({"DerValue.getBoolean, not a BOOLEAN "_s, $$str(this->tag)}));
	}
	if (this->end - this->start != 1) {
		$throwNew($IOException, $$str({"DerValue.getBoolean, invalid length "_s, $$str((this->end - this->start))}));
	}
	$nc(this->data$)->pos = $nc(this->data$)->end;
	return $nc(this->buffer)->get(this->start) != 0;
}

$ObjectIdentifier* DerValue::getOID() {
	$useLocalCurrentObjectStackCache();
	if (this->tag != DerValue::tag_ObjectId) {
		$throwNew($IOException, $$str({"DerValue.getOID, not an OID "_s, $$str(this->tag)}));
	}
	$nc(this->data$)->pos = $nc(this->data$)->end;
	return $new($ObjectIdentifier, $($Arrays::copyOfRange(this->buffer, this->start, this->end)));
}

$bytes* DerValue::getOctetString() {
	$useLocalCurrentObjectStackCache();
	if (this->tag != DerValue::tag_OctetString && !isConstructed(DerValue::tag_OctetString)) {
		$throwNew($IOException, $$str({"DerValue.getOctetString, not an Octet String: "_s, $$str(this->tag)}));
	}
	if (this->end - this->start == 0) {
		return $new($bytes, 0);
	}
	$nc(this->data$)->pos = $nc(this->data$)->end;
	if (!isConstructed()) {
		return $Arrays::copyOfRange(this->buffer, this->start, this->end);
	} else {
		$var($ByteArrayOutputStream, bout, $new($ByteArrayOutputStream));
		$var($DerInputStream, dis, data());
		while ($nc(dis)->available() > 0) {
			bout->write($($nc($(dis->getDerValue()))->getOctetString()));
		}
		return bout->toByteArray();
	}
}

int32_t DerValue::getInteger() {
	return getIntegerInternal(DerValue::tag_Integer);
}

int32_t DerValue::getIntegerInternal(int8_t expectedTag) {
	$useLocalCurrentObjectStackCache();
	$var($BigInteger, result, getBigIntegerInternal(expectedTag, false));
	if ($nc(result)->compareTo($($BigInteger::valueOf((int64_t)$Integer::MIN_VALUE))) < 0) {
		$throwNew($IOException, "Integer below minimum valid value"_s);
	}
	if ($nc(result)->compareTo($($BigInteger::valueOf((int64_t)$Integer::MAX_VALUE))) > 0) {
		$throwNew($IOException, "Integer exceeds maximum valid value"_s);
	}
	return $nc(result)->intValue();
}

$BigInteger* DerValue::getBigInteger() {
	return getBigIntegerInternal(DerValue::tag_Integer, false);
}

$BigInteger* DerValue::getPositiveBigInteger() {
	return getBigIntegerInternal(DerValue::tag_Integer, true);
}

$BigInteger* DerValue::getBigIntegerInternal(int8_t expectedTag, bool makePositive) {
	$useLocalCurrentObjectStackCache();
	if (this->tag != expectedTag) {
		$throwNew($IOException, $$str({"DerValue.getBigIntegerInternal, not expected "_s, $$str(this->tag)}));
	}
	if (this->end == this->start) {
		$throwNew($IOException, "Invalid encoding: zero length Int value"_s);
	}
	$nc(this->data$)->pos = $nc(this->data$)->end;
	if (!this->allowBER && (this->end - this->start >= 2 && ($nc(this->buffer)->get(this->start) == 0) && ($nc(this->buffer)->get(this->start + 1) >= 0))) {
		$throwNew($IOException, "Invalid encoding: redundant leading 0s"_s);
	}
	return makePositive ? $new($BigInteger, 1, this->buffer, this->start, this->end - this->start) : $new($BigInteger, this->buffer, this->start, this->end - this->start);
}

int32_t DerValue::getEnumerated() {
	return getIntegerInternal(DerValue::tag_Enumerated);
}

$bytes* DerValue::getBitString() {
	return getBitString(false);
}

$BitArray* DerValue::getUnalignedBitString() {
	return getUnalignedBitString(false);
}

$String* DerValue::getAsString() {

	$var($String, var$0, nullptr)
	switch (this->tag) {
	case DerValue::tag_UTF8String:
		{
			$assign(var$0, getUTF8String());
			break;
		}
	case DerValue::tag_PrintableString:
		{
			$assign(var$0, getPrintableString());
			break;
		}
	case DerValue::tag_T61String:
		{
			$assign(var$0, getT61String());
			break;
		}
	case DerValue::tag_IA5String:
		{
			$assign(var$0, getIA5String());
			break;
		}
	case DerValue::tag_UniversalString:
		{
			$assign(var$0, getUniversalString());
			break;
		}
	case DerValue::tag_BMPString:
		{
			$assign(var$0, getBMPString());
			break;
		}
	case DerValue::tag_GeneralString:
		{
			$assign(var$0, getGeneralString());
			break;
		}
	default:
		{
			$assign(var$0, nullptr);
			break;
		}
	}
	return var$0;
}

$bytes* DerValue::getBitString(bool tagImplicit) {
	$useLocalCurrentObjectStackCache();
	if (!tagImplicit) {
		if (this->tag != DerValue::tag_BitString) {
			$throwNew($IOException, $$str({"DerValue.getBitString, not a bit string "_s, $$str(this->tag)}));
		}
	}
	if (this->end == this->start) {
		$throwNew($IOException, "Invalid encoding: zero length bit string"_s);
	}
	int32_t numOfPadBits = $nc(this->buffer)->get(this->start);
	if ((numOfPadBits < 0) || (numOfPadBits > 7)) {
		$throwNew($IOException, "Invalid number of padding bits"_s);
	}
	$var($bytes, retval, $Arrays::copyOfRange(this->buffer, this->start + 1, this->end));
	if (numOfPadBits != 0) {
		(*retval)[this->end - this->start - 2] &= (uint8_t)($sl(255, numOfPadBits));
	}
	$nc(this->data$)->pos = $nc(this->data$)->end;
	return retval;
}

$BitArray* DerValue::getUnalignedBitString(bool tagImplicit) {
	$useLocalCurrentObjectStackCache();
	if (!tagImplicit) {
		if (this->tag != DerValue::tag_BitString) {
			$throwNew($IOException, $$str({"DerValue.getBitString, not a bit string "_s, $$str(this->tag)}));
		}
	}
	if (this->end == this->start) {
		$throwNew($IOException, "Invalid encoding: zero length bit string"_s);
	}
	$nc(this->data$)->pos = $nc(this->data$)->end;
	int32_t numOfPadBits = $nc(this->buffer)->get(this->start);
	if ((numOfPadBits < 0) || (numOfPadBits > 7)) {
		$throwNew($IOException, "Invalid number of padding bits"_s);
	}
	if (this->end == this->start + 1) {
		return $new($BitArray, 0);
	} else {
		return $new($BitArray, ((this->end - this->start - 1) << 3) - numOfPadBits, $($Arrays::copyOfRange(this->buffer, this->start + 1, this->end)));
	}
}

$bytes* DerValue::getDataBytes() {
	$nc(this->data$)->pos = $nc(this->data$)->end;
	return $Arrays::copyOfRange(this->buffer, this->start, this->end);
}

$String* DerValue::readStringInternal(int8_t expectedTag, $Charset* cs) {
	$useLocalCurrentObjectStackCache();
	if (this->tag != expectedTag) {
		$throwNew($IOException, $$str({"Incorrect string type "_s, $$str(this->tag), " is not "_s, $$str(expectedTag)}));
	}
	$nc(this->data$)->pos = $nc(this->data$)->end;
	return $new($String, this->buffer, this->start, this->end - this->start, cs);
}

$String* DerValue::getPrintableString() {
	$init($StandardCharsets);
	return readStringInternal(DerValue::tag_PrintableString, $StandardCharsets::US_ASCII);
}

$String* DerValue::getT61String() {
	$init($StandardCharsets);
	return readStringInternal(DerValue::tag_T61String, $StandardCharsets::ISO_8859_1);
}

$String* DerValue::getIA5String() {
	$init($StandardCharsets);
	return readStringInternal(DerValue::tag_IA5String, $StandardCharsets::US_ASCII);
}

$String* DerValue::getBMPString() {
	$init($StandardCharsets);
	return readStringInternal(DerValue::tag_BMPString, $StandardCharsets::UTF_16BE);
}

$String* DerValue::getUTF8String() {
	$init($StandardCharsets);
	return readStringInternal(DerValue::tag_UTF8String, $StandardCharsets::UTF_8);
}

$String* DerValue::getGeneralString() {
	$init($StandardCharsets);
	return readStringInternal(DerValue::tag_GeneralString, $StandardCharsets::US_ASCII);
}

$String* DerValue::getUniversalString() {
	return readStringInternal(DerValue::tag_UniversalString, $$new($UTF_32BE));
}

void DerValue::getNull() {
	$useLocalCurrentObjectStackCache();
	if (this->tag != DerValue::tag_Null) {
		$throwNew($IOException, $$str({"DerValue.getNull, not NULL: "_s, $$str(this->tag)}));
	}
	if (this->end != this->start) {
		$throwNew($IOException, "NULL should contain no data"_s);
	}
}

$Date* DerValue::getTimeInternal(bool generalized) {
	$useLocalCurrentObjectStackCache();
	int32_t year = 0;
	int32_t month = 0;
	int32_t day = 0;
	int32_t hour = 0;
	int32_t minute = 0;
	int32_t second = 0;
	int32_t millis = 0;
	$var($String, type, nullptr);
	int32_t pos = this->start;
	int32_t len = this->end - this->start;
	if (generalized) {
		$assign(type, "Generalized"_s);
		year = 1000 * toDigit($nc(this->buffer)->get(pos++), type);
		year += 100 * toDigit($nc(this->buffer)->get(pos++), type);
		year += 10 * toDigit($nc(this->buffer)->get(pos++), type);
		year += toDigit($nc(this->buffer)->get(pos++), type);
		len -= 2;
	} else {
		$assign(type, "UTC"_s);
		year = 10 * toDigit($nc(this->buffer)->get(pos++), type);
		year += toDigit($nc(this->buffer)->get(pos++), type);
		if (year < 50) {
			year += 2000;
		} else {
			year += 1900;
		}
	}
	month = 10 * toDigit($nc(this->buffer)->get(pos++), type);
	month += toDigit($nc(this->buffer)->get(pos++), type);
	day = 10 * toDigit($nc(this->buffer)->get(pos++), type);
	day += toDigit($nc(this->buffer)->get(pos++), type);
	hour = 10 * toDigit($nc(this->buffer)->get(pos++), type);
	hour += toDigit($nc(this->buffer)->get(pos++), type);
	minute = 10 * toDigit($nc(this->buffer)->get(pos++), type);
	minute += toDigit($nc(this->buffer)->get(pos++), type);
	len -= 10;
	millis = 0;
	if (len > 2) {
		second = 10 * toDigit($nc(this->buffer)->get(pos++), type);
		second += toDigit($nc(this->buffer)->get(pos++), type);
		len -= 2;
		if (generalized && ($nc(this->buffer)->get(pos) == u'.' || $nc(this->buffer)->get(pos) == u',')) {
			--len;
			if (len == 0) {
				$throwNew($IOException, $$str({"Parse "_s, type, " time, empty fractional part"_s}));
			}
			++pos;
			int32_t precision = 0;
			while ($nc(this->buffer)->get(pos) != u'Z' && $nc(this->buffer)->get(pos) != u'+' && $nc(this->buffer)->get(pos) != u'-') {
				int32_t thisDigit = toDigit($nc(this->buffer)->get(pos), type);
				++precision;
				--len;
				if (len == 0) {
					$throwNew($IOException, $$str({"Parse "_s, type, " time, invalid fractional part"_s}));
				}
				++pos;
				switch (precision) {
				case 1:
					{
						millis += 100 * thisDigit;
						break;
					}
				case 2:
					{
						millis += 10 * thisDigit;
						break;
					}
				case 3:
					{
						millis += thisDigit;
						break;
					}
				}
			}
			if (precision == 0) {
				$throwNew($IOException, $$str({"Parse "_s, type, " time, empty fractional part"_s}));
			}
		}
	} else {
		second = 0;
	}
	if (month == 0 || day == 0 || month > 12 || day > 31 || hour >= 24 || minute >= 60 || second >= 60) {
		$throwNew($IOException, $$str({"Parse "_s, type, " time, invalid format"_s}));
	}
	$var($CalendarSystem, gcal, $CalendarSystem::getGregorianCalendar());
	$var($CalendarDate, date, $nc(gcal)->newCalendarDate(nullptr));
	$nc(date)->setDate(year, month, day);
	date->setTimeOfDay(hour, minute, second, millis);
	int64_t time = gcal->getTime(date);
	if (!(len == 1 || len == 5)) {
		$throwNew($IOException, $$str({"Parse "_s, type, " time, invalid offset"_s}));
	}
	int32_t hr = 0;
	int32_t min = 0;
	switch ($nc(this->buffer)->get(pos++)) {
	case u'+':
		{
			if (len != 5) {
				$throwNew($IOException, $$str({"Parse "_s, type, " time, invalid offset"_s}));
			}
			hr = 10 * toDigit($nc(this->buffer)->get(pos++), type);
			hr += toDigit($nc(this->buffer)->get(pos++), type);
			min = 10 * toDigit($nc(this->buffer)->get(pos++), type);
			min += toDigit($nc(this->buffer)->get(pos++), type);
			if (hr >= 24 || min >= 60) {
				$throwNew($IOException, $$str({"Parse "_s, type, " time, +hhmm"_s}));
			}
			time -= ((hr * 60) + min) * 60 * 1000;
			break;
		}
	case u'-':
		{
			if (len != 5) {
				$throwNew($IOException, $$str({"Parse "_s, type, " time, invalid offset"_s}));
			}
			hr = 10 * toDigit($nc(this->buffer)->get(pos++), type);
			hr += toDigit($nc(this->buffer)->get(pos++), type);
			min = 10 * toDigit($nc(this->buffer)->get(pos++), type);
			min += toDigit($nc(this->buffer)->get(pos++), type);
			if (hr >= 24 || min >= 60) {
				$throwNew($IOException, $$str({"Parse "_s, type, " time, -hhmm"_s}));
			}
			time += ((hr * 60) + min) * 60 * 1000;
			break;
		}
	case u'Z':
		{
			if (len != 1) {
				$throwNew($IOException, $$str({"Parse "_s, type, " time, invalid format"_s}));
			}
			break;
		}
	default:
		{
			$throwNew($IOException, $$str({"Parse "_s, type, " time, garbage offset"_s}));
		}
	}
	return $new($Date, time);
}

int32_t DerValue::toDigit(int8_t b, $String* type) {
	if (b < u'0' || b > u'9') {
		$throwNew($IOException, $$str({"Parse "_s, type, " time, invalid format"_s}));
	}
	return b - u'0';
}

$Date* DerValue::getUTCTime() {
	$useLocalCurrentObjectStackCache();
	if (this->tag != DerValue::tag_UtcTime) {
		$throwNew($IOException, $$str({"DerValue.getUTCTime, not a UtcTime: "_s, $$str(this->tag)}));
	}
	if (this->end - this->start < 11 || this->end - this->start > 17) {
		$throwNew($IOException, "DER UTC Time length error"_s);
	}
	$nc(this->data$)->pos = $nc(this->data$)->end;
	return getTimeInternal(false);
}

$Date* DerValue::getGeneralizedTime() {
	$useLocalCurrentObjectStackCache();
	if (this->tag != DerValue::tag_GeneralizedTime) {
		$throwNew($IOException, $$str({"DerValue.getGeneralizedTime, not a GeneralizedTime: "_s, $$str(this->tag)}));
	}
	if (this->end - this->start < 13) {
		$throwNew($IOException, "DER Generalized Time length error"_s);
	}
	$nc(this->data$)->pos = $nc(this->data$)->end;
	return getTimeInternal(true);
}

bool DerValue::equals(Object$* o) {
	if ($equals(this, o)) {
		return true;
	}
	if (!($instanceOf(DerValue, o))) {
		return false;
	}
	$var(DerValue, other, $cast(DerValue, o));
	if (this->tag != $nc(other)->tag) {
		return false;
	}
	if (this->buffer == $nc(other)->buffer && this->start == other->start && this->end == other->end) {
		return true;
	}
	return $Arrays::equals(this->buffer, this->start, this->end, $nc(other)->buffer, other->start, other->end);
}

$String* DerValue::toString() {
	$useLocalCurrentObjectStackCache();
	return $String::format("DerValue(%02x, %s, %d, %d)"_s, $$new($ObjectArray, {
		$($of($Integer::valueOf((int32_t)(255 & (uint32_t)(int32_t)this->tag)))),
		$of(this->buffer),
		$($of($Integer::valueOf(this->start))),
		$($of($Integer::valueOf(this->end)))
	}));
}

$bytes* DerValue::toByteArray() {
	$useLocalCurrentObjectStackCache();
	$nc(this->data$)->pos = $nc(this->data$)->start;
	$var($DerOutputStream, out, $new($DerOutputStream));
	out->write((int32_t)this->tag);
	out->putLength(this->end - this->start);
	int32_t headLen = out->size();
	$var($bytes, result, $Arrays::copyOf($(out->buf()), this->end - this->start + headLen));
	$System::arraycopy(this->buffer, this->start, result, headLen, this->end - this->start);
	return result;
}

$DerInputStream* DerValue::toDerInputStream() {
	$useLocalCurrentObjectStackCache();
	if (this->tag == DerValue::tag_Sequence || this->tag == DerValue::tag_Set) {
		return this->data$;
	}
	$throwNew($IOException, $$str({"toDerInputStream rejects tag type "_s, $$str(this->tag)}));
}

int32_t DerValue::length() {
	return this->end - this->start;
}

bool DerValue::isPrintableStringChar(char16_t ch) {
	if ((ch >= u'a' && ch <= u'z') || (ch >= u'A' && ch <= u'Z') || (ch >= u'0' && ch <= u'9')) {
		return true;
	} else {
		switch (ch) {
		case u' ':
			{}
		case u'\'':
			{}
		case u'(':
			{}
		case u')':
			{}
		case u'+':
			{}
		case u',':
			{}
		case u'-':
			{}
		case u'.':
			{}
		case u'/':
			{}
		case u':':
			{}
		case u'=':
			{}
		case u'?':
			{
				return true;
			}
		default:
			{
				return false;
			}
		}
	}
}

int8_t DerValue::createTag(int8_t tagClass, bool form, int8_t val) {
	if (val < 0 || val > 30) {
		$throwNew($IllegalArgumentException, "Tag number over 30 is not supported"_s);
	}
	int8_t tag = (int8_t)(tagClass | val);
	if (form) {
		tag |= (int8_t)32;
	}
	return (tag);
}

void DerValue::resetTag(int8_t tag) {
	this->tag = tag;
}

DerValue* DerValue::withTag(int8_t newTag) {
	return $new(DerValue, newTag, this->buffer, this->start, this->end, this->allowBER);
}

int32_t DerValue::hashCode() {
	int32_t result = this->tag;
	for (int32_t i = this->start; i < this->end; ++i) {
		result = 31 * result + $nc(this->buffer)->get(i);
	}
	return result;
}

$DerValueArray* DerValue::subs(int8_t expectedTag, int32_t startLen) {
	$useLocalCurrentObjectStackCache();
	if (expectedTag != 0 && expectedTag != this->tag) {
		$throwNew($IOException, "Not the correct tag"_s);
	}
	$var($List, result, $new($ArrayList, startLen));
	$var($DerInputStream, dis, data());
	while ($nc(dis)->available() > 0) {
		result->add($(dis->getDerValue()));
	}
	return $fcast($DerValueArray, result->toArray($$new($DerValueArray, 0)));
}

void DerValue::clear() {
	$Arrays::fill(this->buffer, this->start, this->end, (int8_t)0);
}

DerValue::DerValue() {
}

$Class* DerValue::load$($String* name, bool initialize) {
	$loadClass(DerValue, name, initialize, &_DerValue_ClassInfo_, allocate$DerValue);
	return class$;
}

$Class* DerValue::class$ = nullptr;

		} // util
	} // security
} // sun