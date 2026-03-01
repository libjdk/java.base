#include <sun/security/x509/AVA.h>

#include <java/io/ByteArrayOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/io/Reader.h>
#include <java/lang/Appendable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/NumberFormatException.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/text/Normalizer$Form.h>
#include <java/text/Normalizer.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/HexFormat.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <sun/security/action/GetBooleanAction.h>
#include <sun/security/pkcs/PKCS9Attribute.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/AVAKeyword.h>
#include <sun/security/x509/X500Name.h>
#include <jcpp.h>

#undef AVA
#undef DEFAULT
#undef DOMAIN_COMPONENT_OID
#undef EMAIL_ADDRESS_OID
#undef NFKD
#undef PRESERVE_OLD_DC_ENCODING
#undef US
#undef UTF_8

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $Reader = ::java::io::Reader;
using $Appendable = ::java::lang::Appendable;
using $Byte = ::java::lang::Byte;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $RuntimeException = ::java::lang::RuntimeException;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $Normalizer = ::java::text::Normalizer;
using $Normalizer$Form = ::java::text::Normalizer$Form;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $HexFormat = ::java::util::HexFormat;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $GetBooleanAction = ::sun::security::action::GetBooleanAction;
using $PKCS9Attribute = ::sun::security::pkcs::PKCS9Attribute;
using $Debug = ::sun::security::util::Debug;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $AVAKeyword = ::sun::security::x509::AVAKeyword;
using $X500Name = ::sun::security::x509::X500Name;

namespace sun {
	namespace security {
		namespace x509 {

$FieldInfo _AVA_FieldInfo_[] = {
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AVA, debug)},
	{"PRESERVE_OLD_DC_ENCODING", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AVA, PRESERVE_OLD_DC_ENCODING)},
	{"DEFAULT", "I", nullptr, $STATIC | $FINAL, $constField(AVA, DEFAULT)},
	{"RFC1779", "I", nullptr, $STATIC | $FINAL, $constField(AVA, RFC1779)},
	{"RFC2253", "I", nullptr, $STATIC | $FINAL, $constField(AVA, RFC2253)},
	{"oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $FINAL, $field(AVA, oid)},
	{"value", "Lsun/security/util/DerValue;", nullptr, $FINAL, $field(AVA, value)},
	{"specialChars1779", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AVA, specialChars1779)},
	{"specialChars2253", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AVA, specialChars2253)},
	{"specialCharsDefault", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AVA, specialCharsDefault)},
	{"escapedDefault", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AVA, escapedDefault)},
	{}
};

$MethodInfo _AVA_MethodInfo_[] = {
	{"<init>", "(Lsun/security/util/ObjectIdentifier;Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(AVA, init$, void, $ObjectIdentifier*, $DerValue*)},
	{"<init>", "(Ljava/io/Reader;)V", nullptr, 0, $method(AVA, init$, void, $Reader*), "java.io.IOException"},
	{"<init>", "(Ljava/io/Reader;Ljava/util/Map;)V", "(Ljava/io/Reader;Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)V", 0, $method(AVA, init$, void, $Reader*, $Map*), "java.io.IOException"},
	{"<init>", "(Ljava/io/Reader;I)V", nullptr, 0, $method(AVA, init$, void, $Reader*, int32_t), "java.io.IOException"},
	{"<init>", "(Ljava/io/Reader;ILjava/util/Map;)V", "(Ljava/io/Reader;ILjava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)V", 0, $method(AVA, init$, void, $Reader*, int32_t, $Map*), "java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, 0, $method(AVA, init$, void, $DerValue*), "java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerInputStream;)V", nullptr, 0, $method(AVA, init$, void, $DerInputStream*), "java.io.IOException"},
	{"derEncode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $virtualMethod(AVA, derEncode, void, $OutputStream*), "java.io.IOException"},
	{"encode", "(Lsun/security/util/DerOutputStream;)V", nullptr, $PUBLIC, $virtualMethod(AVA, encode, void, $DerOutputStream*), "java.io.IOException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(AVA, equals, bool, Object$*)},
	{"getDerValue", "()Lsun/security/util/DerValue;", nullptr, $PUBLIC, $virtualMethod(AVA, getDerValue, $DerValue*)},
	{"getEmbeddedHexPair", "(ILjava/io/Reader;)Ljava/lang/Byte;", nullptr, $PRIVATE | $STATIC, $staticMethod(AVA, getEmbeddedHexPair, $Byte*, int32_t, $Reader*), "java.io.IOException"},
	{"getEmbeddedHexString", "(Ljava/util/List;)Ljava/lang/String;", "(Ljava/util/List<Ljava/lang/Byte;>;)Ljava/lang/String;", $PRIVATE | $STATIC, $staticMethod(AVA, getEmbeddedHexString, $String*, $List*)},
	{"getObjectIdentifier", "()Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC, $virtualMethod(AVA, getObjectIdentifier, $ObjectIdentifier*)},
	{"getValueString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(AVA, getValueString, $String*)},
	{"hasRFC2253Keyword", "()Z", nullptr, 0, $virtualMethod(AVA, hasRFC2253Keyword, bool)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(AVA, hashCode, int32_t)},
	{"isDerString", "(Lsun/security/util/DerValue;Z)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(AVA, isDerString, bool, $DerValue*, bool)},
	{"isTerminator", "(II)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(AVA, isTerminator, bool, int32_t, int32_t)},
	{"parseHexString", "(Ljava/io/Reader;I)Lsun/security/util/DerValue;", nullptr, $PRIVATE | $STATIC, $staticMethod(AVA, parseHexString, $DerValue*, $Reader*, int32_t), "java.io.IOException"},
	{"parseQuotedString", "(Ljava/io/Reader;Ljava/lang/StringBuilder;)Lsun/security/util/DerValue;", nullptr, $PRIVATE, $method(AVA, parseQuotedString, $DerValue*, $Reader*, $StringBuilder*), "java.io.IOException"},
	{"parseString", "(Ljava/io/Reader;IILjava/lang/StringBuilder;)Lsun/security/util/DerValue;", nullptr, $PRIVATE, $method(AVA, parseString, $DerValue*, $Reader*, int32_t, int32_t, $StringBuilder*), "java.io.IOException"},
	{"readChar", "(Ljava/io/Reader;Ljava/lang/String;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(AVA, readChar, int32_t, $Reader*, $String*), "java.io.IOException"},
	{"toKeyword", "(ILjava/util/Map;)Ljava/lang/String;", "(ILjava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)Ljava/lang/String;", $PRIVATE, $method(AVA, toKeyword, $String*, int32_t, $Map*)},
	{"toKeywordValueString", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(AVA, toKeywordValueString, $String*, $String*)},
	{"toRFC1779String", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(AVA, toRFC1779String, $String*)},
	{"toRFC1779String", "(Ljava/util/Map;)Ljava/lang/String;", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)Ljava/lang/String;", $PUBLIC, $virtualMethod(AVA, toRFC1779String, $String*, $Map*)},
	{"toRFC2253CanonicalString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(AVA, toRFC2253CanonicalString, $String*)},
	{"toRFC2253String", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(AVA, toRFC2253String, $String*)},
	{"toRFC2253String", "(Ljava/util/Map;)Ljava/lang/String;", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)Ljava/lang/String;", $PUBLIC, $virtualMethod(AVA, toRFC2253String, $String*, $Map*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(AVA, toString, $String*)},
	{"trailingSpace", "(Ljava/io/Reader;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(AVA, trailingSpace, bool, $Reader*), "java.io.IOException"},
	{}
};

$ClassInfo _AVA_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.x509.AVA",
	"java.lang.Object",
	"sun.security.util.DerEncoder",
	_AVA_FieldInfo_,
	_AVA_MethodInfo_
};

$Object* allocate$AVA($Class* clazz) {
	return $of($alloc(AVA));
}

$Debug* AVA::debug = nullptr;
bool AVA::PRESERVE_OLD_DC_ENCODING = false;
$String* AVA::specialChars1779 = nullptr;
$String* AVA::specialChars2253 = nullptr;
$String* AVA::specialCharsDefault = nullptr;
$String* AVA::escapedDefault = nullptr;

void AVA::init$($ObjectIdentifier* type, $DerValue* val) {
	if ((type == nullptr) || (val == nullptr)) {
		$throwNew($NullPointerException);
	}
	$set(this, oid, type);
	$set(this, value, val);
}

void AVA::init$($Reader* in) {
	AVA::init$(in, AVA::DEFAULT);
}

void AVA::init$($Reader* in, $Map* keywordMap) {
	AVA::init$(in, AVA::DEFAULT, keywordMap);
}

void AVA::init$($Reader* in, int32_t format) {
	AVA::init$(in, format, $($Collections::emptyMap()));
}

void AVA::init$($Reader* in, int32_t format, $Map* keywordMap) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, temp, $new($StringBuilder));
	int32_t c = 0;
	while (true) {
		c = readChar(in, "Incorrect AVA format"_s);
		if (c == u'=') {
			break;
		}
		temp->append((char16_t)c);
	}
	$set(this, oid, $AVAKeyword::getOID($(temp->toString()), format, keywordMap));
	temp->setLength(0);
	if (format == AVA::RFC2253) {
		c = $nc(in)->read();
		if (c == u' ') {
			$throwNew($IOException, "Incorrect AVA RFC2253 format - leading space must be escaped"_s);
		}
	} else {
		do {
			c = $nc(in)->read();
		} while ((c == u' ') || (c == u'\n'));
	}
	if (c == -1) {
		$set(this, value, $new($DerValue, ""_s));
		return;
	}
	if (c == u'#') {
		$set(this, value, parseHexString(in, format));
	} else if ((c == u'\"') && (format != AVA::RFC2253)) {
		$set(this, value, parseQuotedString(in, temp));
	} else {
		$set(this, value, parseString(in, c, format, temp));
	}
}

$ObjectIdentifier* AVA::getObjectIdentifier() {
	return this->oid;
}

$DerValue* AVA::getDerValue() {
	return this->value;
}

$String* AVA::getValueString() {
	$useLocalCurrentObjectStackCache();
	try {
		$var($String, s, $nc(this->value)->getAsString());
		if (s == nullptr) {
			$throwNew($RuntimeException, "AVA string is null"_s);
		}
		return s;
	} catch ($IOException& e) {
		$throwNew($RuntimeException, $$str({"AVA error: "_s, e}), e);
	}
	$shouldNotReachHere();
}

$DerValue* AVA::parseHexString($Reader* in, int32_t format) {
	$init(AVA);
	$useLocalCurrentObjectStackCache();
	int32_t c = 0;
	$var($ByteArrayOutputStream, baos, $new($ByteArrayOutputStream));
	int8_t b = (int8_t)0;
	int32_t cNdx = 0;
	while (true) {
		c = $nc(in)->read();
		if (isTerminator(c, format)) {
			break;
		}
		try {
			int32_t cVal = $HexFormat::fromHexDigit(c);
			if ((cNdx % 2) == 1) {
				b = (int8_t)((b * 16) + (int8_t)(cVal));
				baos->write((int32_t)b);
			} else {
				b = (int8_t)(cVal);
			}
			++cNdx;
		} catch ($NumberFormatException& nfe) {
			$throwNew($IOException, $$str({"AVA parse, invalid hex digit: "_s, $$str((char16_t)c)}));
		}
	}
	if (cNdx == 0) {
		$throwNew($IOException, "AVA parse, zero hex digits"_s);
	}
	if (cNdx % 2 == 1) {
		$throwNew($IOException, "AVA parse, odd number of hex digits"_s);
	}
	return $new($DerValue, $(baos->toByteArray()));
}

$DerValue* AVA::parseQuotedString($Reader* in, $StringBuilder* temp) {
	$useLocalCurrentObjectStackCache();
	int32_t c = readChar(in, "Quoted string did not end in quote"_s);
	$var($List, embeddedHex, $new($ArrayList));
	bool isPrintableString = true;
	while (c != u'\"') {
		if (c == u'\\') {
			c = readChar(in, "Quoted string did not end in quote"_s);
			$var($Byte, hexByte, nullptr);
			if (($assign(hexByte, getEmbeddedHexPair(c, in))) != nullptr) {
				isPrintableString = false;
				embeddedHex->add(hexByte);
				c = $nc(in)->read();
				continue;
			}
			if ($nc(AVA::specialChars1779)->indexOf((int32_t)(char16_t)c) < 0) {
				$throwNew($IOException, $$str({"Invalid escaped character in AVA: "_s, $$str((char16_t)c)}));
			}
		}
		if (embeddedHex->size() > 0) {
			$var($String, hexString, getEmbeddedHexString(embeddedHex));
			$nc(temp)->append(hexString);
			embeddedHex->clear();
		}
		isPrintableString &= $DerValue::isPrintableStringChar((char16_t)c);
		$nc(temp)->append((char16_t)c);
		c = readChar(in, "Quoted string did not end in quote"_s);
	}
	if (embeddedHex->size() > 0) {
		$var($String, hexString, getEmbeddedHexString(embeddedHex));
		$nc(temp)->append(hexString);
		embeddedHex->clear();
	}
	do {
		c = $nc(in)->read();
	} while ((c == u'\n') || (c == u' '));
	if (c != -1) {
		$throwNew($IOException, "AVA had characters other than whitespace after terminating quote"_s);
	}
	$init($PKCS9Attribute);
	bool var$0 = $nc(this->oid)->equals($PKCS9Attribute::EMAIL_ADDRESS_OID);
	$init($X500Name);
	if (var$0 || ($nc(this->oid)->equals($X500Name::DOMAIN_COMPONENT_OID) && AVA::PRESERVE_OLD_DC_ENCODING == false)) {
		return $new($DerValue, $DerValue::tag_IA5String, $($nc($($nc(temp)->toString()))->trim()));
	} else if (isPrintableString) {
		return $new($DerValue, $($nc($($nc(temp)->toString()))->trim()));
	} else {
		return $new($DerValue, $DerValue::tag_UTF8String, $($nc($($nc(temp)->toString()))->trim()));
	}
}

$DerValue* AVA::parseString($Reader* in, int32_t c, int32_t format, $StringBuilder* temp) {
	$useLocalCurrentObjectStackCache();
	$var($List, embeddedHex, $new($ArrayList));
	bool isPrintableString = true;
	bool escape = false;
	bool leadingChar = true;
	int32_t spaceCount = 0;
	do {
		escape = false;
		if (c == u'\\') {
			escape = true;
			c = readChar(in, "Invalid trailing backslash"_s);
			$var($Byte, hexByte, nullptr);
			if (($assign(hexByte, getEmbeddedHexPair(c, in))) != nullptr) {
				isPrintableString = false;
				embeddedHex->add(hexByte);
				c = $nc(in)->read();
				leadingChar = false;
				continue;
			}
			if (format == AVA::DEFAULT && $nc(AVA::specialCharsDefault)->indexOf((int32_t)(char16_t)c) == -1) {
				$throwNew($IOException, $$str({"Invalid escaped character in AVA: \'"_s, $$str((char16_t)c), "\'"_s}));
			} else if (format == AVA::RFC2253) {
				if (c == u' ') {
					if (!leadingChar && !trailingSpace(in)) {
						$throwNew($IOException, "Invalid escaped space character in AVA.  Only a leading or trailing space character can be escaped."_s);
					}
				} else if (c == u'#') {
					if (!leadingChar) {
						$throwNew($IOException, "Invalid escaped \'#\' character in AVA.  Only a leading \'#\' can be escaped."_s);
					}
				} else if ($nc(AVA::specialChars2253)->indexOf((int32_t)(char16_t)c) == -1) {
					$throwNew($IOException, $$str({"Invalid escaped character in AVA: \'"_s, $$str((char16_t)c), "\'"_s}));
				}
			}
		} else if (format == AVA::RFC2253) {
			if ($nc(AVA::specialChars2253)->indexOf((int32_t)(char16_t)c) != -1) {
				$throwNew($IOException, $$str({"Character \'"_s, $$str((char16_t)c), "\' in AVA appears without escape"_s}));
			}
		} else if ($nc(AVA::escapedDefault)->indexOf((int32_t)(char16_t)c) != -1) {
			$throwNew($IOException, $$str({"Character \'"_s, $$str((char16_t)c), "\' in AVA appears without escape"_s}));
		}
		if (embeddedHex->size() > 0) {
			for (int32_t i = 0; i < spaceCount; ++i) {
				$nc(temp)->append(u' ');
			}
			spaceCount = 0;
			$var($String, hexString, getEmbeddedHexString(embeddedHex));
			$nc(temp)->append(hexString);
			embeddedHex->clear();
		}
		isPrintableString &= $DerValue::isPrintableStringChar((char16_t)c);
		if (c == u' ' && escape == false) {
			++spaceCount;
		} else {
			for (int32_t i = 0; i < spaceCount; ++i) {
				$nc(temp)->append(u' ');
			}
			spaceCount = 0;
			$nc(temp)->append((char16_t)c);
		}
		c = $nc(in)->read();
		leadingChar = false;
	} while (isTerminator(c, format) == false);
	if (format == AVA::RFC2253 && spaceCount > 0) {
		$throwNew($IOException, "Incorrect AVA RFC2253 format - trailing space must be escaped"_s);
	}
	if (embeddedHex->size() > 0) {
		$var($String, hexString, getEmbeddedHexString(embeddedHex));
		$nc(temp)->append(hexString);
		embeddedHex->clear();
	}
	$init($PKCS9Attribute);
	bool var$0 = $nc(this->oid)->equals($PKCS9Attribute::EMAIL_ADDRESS_OID);
	$init($X500Name);
	if (var$0 || ($nc(this->oid)->equals($X500Name::DOMAIN_COMPONENT_OID) && AVA::PRESERVE_OLD_DC_ENCODING == false)) {
		return $new($DerValue, $DerValue::tag_IA5String, $($nc(temp)->toString()));
	} else if (isPrintableString) {
		return $new($DerValue, $($nc(temp)->toString()));
	} else {
		return $new($DerValue, $DerValue::tag_UTF8String, $($nc(temp)->toString()));
	}
}

$Byte* AVA::getEmbeddedHexPair(int32_t c1, $Reader* in) {
	$init(AVA);
	if ($HexFormat::isHexDigit(c1)) {
		int32_t c2 = readChar(in, "unexpected EOF - escaped hex value must include two valid digits"_s);
		if ($HexFormat::isHexDigit(c2)) {
			int32_t hi = $HexFormat::fromHexDigit(c1);
			int32_t lo = $HexFormat::fromHexDigit(c2);
			return $Byte::valueOf((int8_t)((hi << 4) + lo));
		} else {
			$throwNew($IOException, "escaped hex value must include two valid digits"_s);
		}
	}
	return nullptr;
}

$String* AVA::getEmbeddedHexString($List* hexList) {
	$init(AVA);
	$useLocalCurrentObjectStackCache();
	int32_t n = $nc(hexList)->size();
	$var($bytes, hexBytes, $new($bytes, n));
	for (int32_t i = 0; i < n; ++i) {
		hexBytes->set(i, $nc(($cast($Byte, $(hexList->get(i)))))->byteValue());
	}
	$init($StandardCharsets);
	return $new($String, hexBytes, $StandardCharsets::UTF_8);
}

bool AVA::isTerminator(int32_t ch, int32_t format) {
	$init(AVA);
	switch (ch) {
	case -1:
		{}
	case u'+':
		{}
	case u',':
		{
			return true;
		}
	case u';':
		{
			return format != AVA::RFC2253;
		}
	default:
		{
			return false;
		}
	}
}

int32_t AVA::readChar($Reader* in, $String* errMsg) {
	$init(AVA);
	int32_t c = $nc(in)->read();
	if (c == -1) {
		$throwNew($IOException, errMsg);
	}
	return c;
}

bool AVA::trailingSpace($Reader* in) {
	$init(AVA);
	bool trailing = false;
	if (!$nc(in)->markSupported()) {
		return true;
	} else {
		in->mark(9999);
		while (true) {
			int32_t nextChar = in->read();
			if (nextChar == -1) {
				trailing = true;
				break;
			} else if (nextChar == u' ') {
				continue;
			} else if (nextChar == u'\\') {
				int32_t followingChar = in->read();
				if (followingChar != u' ') {
					trailing = false;
					break;
				}
			} else {
				trailing = false;
				break;
			}
		}
		in->reset();
		return trailing;
	}
}

void AVA::init$($DerValue* derval) {
	$useLocalCurrentObjectStackCache();
	if ($nc(derval)->tag != $DerValue::tag_Sequence) {
		$throwNew($IOException, "AVA not a sequence"_s);
	}
	$set(this, oid, $nc($nc(derval)->data$)->getOID());
	$set(this, value, $nc(derval->data$)->getDerValue());
	if ($nc(derval->data$)->available() != 0) {
		$throwNew($IOException, $$str({"AVA, extra bytes = "_s, $$str($nc(derval->data$)->available())}));
	}
}

void AVA::init$($DerInputStream* in) {
	AVA::init$($($nc(in)->getDerValue()));
}

bool AVA::equals(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	if ($equals(this, obj)) {
		return true;
	}
	if ($instanceOf(AVA, obj) == false) {
		return false;
	}
	$var(AVA, other, $cast(AVA, obj));
	return $nc($(this->toRFC2253CanonicalString()))->equals($($nc(other)->toRFC2253CanonicalString()));
}

int32_t AVA::hashCode() {
	return $nc($(toRFC2253CanonicalString()))->hashCode();
}

void AVA::encode($DerOutputStream* out) {
	derEncode(out);
}

void AVA::derEncode($OutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, tmp, $new($DerOutputStream));
	$var($DerOutputStream, tmp2, $new($DerOutputStream));
	tmp->putOID(this->oid);
	$nc(this->value)->encode(tmp);
	tmp2->write($DerValue::tag_Sequence, tmp);
	$nc(out)->write($(tmp2->toByteArray()));
}

$String* AVA::toKeyword(int32_t format, $Map* oidMap) {
	return $AVAKeyword::getKeyword(this->oid, format, oidMap);
}

$String* AVA::toString() {
	$useLocalCurrentObjectStackCache();
	return toKeywordValueString($(toKeyword(AVA::DEFAULT, $($Collections::emptyMap()))));
}

$String* AVA::toRFC1779String() {
	return toRFC1779String($($Collections::emptyMap()));
}

$String* AVA::toRFC1779String($Map* oidMap) {
	return toKeywordValueString($(toKeyword(AVA::RFC1779, oidMap)));
}

$String* AVA::toRFC2253String() {
	return toRFC2253String($($Collections::emptyMap()));
}

$String* AVA::toRFC2253String($Map* oidMap) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, typeAndValue, $new($StringBuilder, 100));
	typeAndValue->append($(toKeyword(AVA::RFC2253, oidMap)));
	typeAndValue->append(u'=');
	bool var$1 = typeAndValue->charAt(0) >= u'0';
	bool var$0 = (var$1 && typeAndValue->charAt(0) <= u'9');
	if (var$0 || !isDerString(this->value, false)) {
		$var($bytes, data, nullptr);
		try {
			$assign(data, $nc(this->value)->toByteArray());
		} catch ($IOException& ie) {
			$throwNew($IllegalArgumentException, "DER Value conversion"_s);
		}
		typeAndValue->append(u'#');
		$nc($($HexFormat::of()))->formatHex(typeAndValue, data);
	} else {
		$var($String, valStr, nullptr);
		try {
			$init($StandardCharsets);
			$assign(valStr, $new($String, $($nc(this->value)->getDataBytes()), $StandardCharsets::UTF_8));
		} catch ($IOException& ie) {
			$throwNew($IllegalArgumentException, "DER Value conversion"_s);
		}
		$var($String, escapees, ",=+<>#;\"\\"_s);
		$var($StringBuilder, sbuffer, $new($StringBuilder));
		for (int32_t i = 0; i < $nc(valStr)->length(); ++i) {
			char16_t c = valStr->charAt(i);
			bool var$2 = $DerValue::isPrintableStringChar(c);
			if (var$2 || escapees->indexOf((int32_t)c) >= 0) {
				if (escapees->indexOf((int32_t)c) >= 0) {
					sbuffer->append(u'\\');
				}
				sbuffer->append(c);
			} else if (c == u'\0') {
				sbuffer->append("\\00"_s);
			} else if (AVA::debug != nullptr && $Debug::isOn("ava"_s)) {
				$init($StandardCharsets);
				$var($bytes, valueBytes, $nc($($Character::toString(c)))->getBytes($StandardCharsets::UTF_8));
				$nc($($nc($($nc($($HexFormat::of()))->withPrefix("\\"_s)))->withUpperCase()))->formatHex(sbuffer, valueBytes);
			} else {
				sbuffer->append(c);
			}
		}
		$var($chars, chars, $nc($(sbuffer->toString()))->toCharArray());
		$assign(sbuffer, $new($StringBuilder));
		int32_t lead = 0;
		for (lead = 0; lead < chars->length; ++lead) {
			if (chars->get(lead) != u' ' && chars->get(lead) != u'\r') {
				break;
			}
		}
		int32_t trail = 0;
		for (trail = chars->length - 1; trail >= 0; --trail) {
			if (chars->get(trail) != u' ' && chars->get(trail) != u'\r') {
				break;
			}
		}
		for (int32_t i = 0; i < chars->length; ++i) {
			char16_t c = chars->get(i);
			if (i < lead || i > trail) {
				sbuffer->append(u'\\');
			}
			sbuffer->append(c);
		}
		typeAndValue->append(static_cast<$CharSequence*>(sbuffer));
	}
	return typeAndValue->toString();
}

$String* AVA::toRFC2253CanonicalString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, typeAndValue, $new($StringBuilder, 40));
	typeAndValue->append($(toKeyword(AVA::RFC2253, $($Collections::emptyMap()))));
	typeAndValue->append(u'=');
	bool var$1 = typeAndValue->charAt(0) >= u'0';
	bool var$0 = (var$1 && typeAndValue->charAt(0) <= u'9');
	if (var$0 || !isDerString(this->value, true)) {
		$var($bytes, data, nullptr);
		try {
			$assign(data, $nc(this->value)->toByteArray());
		} catch ($IOException& ie) {
			$throwNew($IllegalArgumentException, "DER Value conversion"_s);
		}
		typeAndValue->append(u'#');
		$nc($($HexFormat::of()))->formatHex(typeAndValue, data);
	} else {
		$var($String, valStr, nullptr);
		try {
			$init($StandardCharsets);
			$assign(valStr, $new($String, $($nc(this->value)->getDataBytes()), $StandardCharsets::UTF_8));
		} catch ($IOException& ie) {
			$throwNew($IllegalArgumentException, "DER Value conversion"_s);
		}
		$var($String, escapees, ",+<>;\"\\"_s);
		$var($StringBuilder, sbuffer, $new($StringBuilder));
		bool previousWhite = false;
		for (int32_t i = 0; i < $nc(valStr)->length(); ++i) {
			char16_t c = valStr->charAt(i);
			bool var$2 = $DerValue::isPrintableStringChar(c);
			if (var$2 || escapees->indexOf((int32_t)c) >= 0 || (i == 0 && c == u'#')) {
				if ((i == 0 && c == u'#') || escapees->indexOf((int32_t)c) >= 0) {
					sbuffer->append(u'\\');
				}
				if (!$Character::isWhitespace(c)) {
					previousWhite = false;
					sbuffer->append(c);
				} else if (previousWhite == false) {
					previousWhite = true;
					sbuffer->append(c);
				} else {
					continue;
				}
			} else if (AVA::debug != nullptr && $Debug::isOn("ava"_s)) {
				previousWhite = false;
				$init($StandardCharsets);
				$var($bytes, valueBytes, $nc($($Character::toString(c)))->getBytes($StandardCharsets::UTF_8));
				$nc($($nc($($nc($($HexFormat::of()))->withPrefix("\\"_s)))->withUpperCase()))->formatHex(sbuffer, valueBytes);
			} else {
				previousWhite = false;
				sbuffer->append(c);
			}
		}
		typeAndValue->append($($nc($(sbuffer->toString()))->trim()));
	}
	$var($String, canon, typeAndValue->toString());
	$init($Locale);
	$assign(canon, $($nc(canon)->toUpperCase($Locale::US))->toLowerCase($Locale::US));
	$init($Normalizer$Form);
	return $Normalizer::normalize(canon, $Normalizer$Form::NFKD);
}

bool AVA::isDerString($DerValue* value, bool canonical) {
	$init(AVA);
	if (canonical) {
		switch ($nc(value)->tag) {
		case $DerValue::tag_PrintableString:
			{}
		case $DerValue::tag_UTF8String:
			{
				return true;
			}
		default:
			{
				return false;
			}
		}
	} else {
		switch ($nc(value)->tag) {
		case $DerValue::tag_PrintableString:
			{}
		case $DerValue::tag_T61String:
			{}
		case $DerValue::tag_IA5String:
			{}
		case $DerValue::tag_GeneralString:
			{}
		case $DerValue::tag_BMPString:
			{}
		case $DerValue::tag_UTF8String:
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

bool AVA::hasRFC2253Keyword() {
	return $AVAKeyword::hasKeyword(this->oid, AVA::RFC2253);
}

$String* AVA::toKeywordValueString($String* keyword) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, retval, $new($StringBuilder, 40));
	retval->append(keyword);
	retval->append(u'=');
	try {
		$var($String, valStr, $nc(this->value)->getAsString());
		if (valStr == nullptr) {
			$var($bytes, data, $nc(this->value)->toByteArray());
			retval->append(u'#');
			$nc($($HexFormat::of()))->formatHex(retval, data);
		} else {
			bool quoteNeeded = false;
			$var($StringBuilder, sbuffer, $new($StringBuilder));
			bool previousWhite = false;
			$var($String, escapees, ",+=\n<>#;\\\""_s);
			int32_t length = $nc(valStr)->length();
			bool var$0 = length > 1 && valStr->charAt(0) == u'\"';
			bool alreadyQuoted = (var$0 && valStr->charAt(length - 1) == u'\"');
			for (int32_t i = 0; i < length; ++i) {
				char16_t c = valStr->charAt(i);
				if (alreadyQuoted && (i == 0 || i == length - 1)) {
					sbuffer->append(c);
					continue;
				}
				bool var$1 = $DerValue::isPrintableStringChar(c);
				if (var$1 || escapees->indexOf((int32_t)c) >= 0) {
					if (!quoteNeeded && ((i == 0 && (c == u' ' || c == u'\n')) || escapees->indexOf((int32_t)c) >= 0)) {
						quoteNeeded = true;
					}
					if (!(c == u' ' || c == u'\n')) {
						if (c == u'\"' || c == u'\\') {
							sbuffer->append(u'\\');
						}
						previousWhite = false;
					} else {
						if (!quoteNeeded && previousWhite) {
							quoteNeeded = true;
						}
						previousWhite = true;
					}
					sbuffer->append(c);
				} else if (AVA::debug != nullptr && $Debug::isOn("ava"_s)) {
					previousWhite = false;
					$init($StandardCharsets);
					$var($bytes, valueBytes, $nc($($Character::toString(c)))->getBytes($StandardCharsets::UTF_8));
					$nc($($nc($($nc($($HexFormat::of()))->withPrefix("\\"_s)))->withUpperCase()))->formatHex(sbuffer, valueBytes);
				} else {
					previousWhite = false;
					sbuffer->append(c);
				}
			}
			if (sbuffer->length() > 0) {
				char16_t trailChar = sbuffer->charAt(sbuffer->length() - 1);
				if (trailChar == u' ' || trailChar == u'\n') {
					quoteNeeded = true;
				}
			}
			if (!alreadyQuoted && quoteNeeded) {
				retval->append(u'\"')->append(static_cast<$CharSequence*>(sbuffer))->append(u'\"');
			} else {
				retval->append(static_cast<$CharSequence*>(sbuffer));
			}
		}
	} catch ($IOException& e) {
		$throwNew($IllegalArgumentException, "DER Value conversion"_s);
	}
	return retval->toString();
}

void clinit$AVA($Class* class$) {
	$assignStatic(AVA::specialChars1779, ",=\n+<>#;\\\""_s);
	$assignStatic(AVA::specialChars2253, ",=+<>#;\\\""_s);
	$assignStatic(AVA::specialCharsDefault, ",=\n+<>#;\\\" "_s);
	$assignStatic(AVA::escapedDefault, ",+<>;\""_s);
	$assignStatic(AVA::debug, $Debug::getInstance("x509"_s, "\t[AVA]"_s));
	AVA::PRESERVE_OLD_DC_ENCODING = $GetBooleanAction::privilegedGetProperty("com.sun.security.preserveOldDCEncoding"_s);
}

AVA::AVA() {
}

$Class* AVA::load$($String* name, bool initialize) {
	$loadClass(AVA, name, initialize, &_AVA_ClassInfo_, clinit$AVA, allocate$AVA);
	return class$;
}

$Class* AVA::class$ = nullptr;

		} // x509
	} // security
} // sun