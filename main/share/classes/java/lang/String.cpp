#include <java/lang/String.h>

#include <java/io/ObjectStreamField.h>
#include <java/io/Serializable.h>
#include <java/io/UnsupportedEncodingException.h>
#include <java/lang/AbstractStringBuilder.h>
#include <java/lang/CharSequence.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/Error.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/Iterable.h>
#include <java/lang/Math.h>
#include <java/lang/OutOfMemoryError.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/String$CaseInsensitiveComparator.h>
#include <java/lang/StringBuffer.h>
#include <java/lang/StringCoding.h>
#include <java/lang/StringConcatHelper.h>
#include <java/lang/StringIndexOutOfBoundsException.h>
#include <java/lang/StringLatin1$CharsSpliterator.h>
#include <java/lang/StringLatin1.h>
#include <java/lang/StringUTF16$CharsSpliterator.h>
#include <java/lang/StringUTF16$CodePointsSpliterator.h>
#include <java/lang/StringUTF16.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/nio/charset/CharacterCodingException.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/CharsetDecoder.h>
#include <java/nio/charset/CharsetEncoder.h>
#include <java/nio/charset/CoderResult.h>
#include <java/nio/charset/CodingErrorAction.h>
#include <java/nio/charset/IllegalCharsetNameException.h>
#include <java/nio/charset/MalformedInputException.h>
#include <java/nio/charset/UnmappableCharacterException.h>
#include <java/nio/charset/UnsupportedCharsetException.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Comparator.h>
#include <java/util/Formatter.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/Spliterator$OfInt.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Function.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/IntStream.h>
#include <java/util/stream/Stream.h>
#include <java/util/stream/StreamSupport.h>
#include <sun/nio/cs/ArrayDecoder.h>
#include <sun/nio/cs/ArrayEncoder.h>
#include <sun/nio/cs/ISO_8859_1.h>
#include <sun/nio/cs/US_ASCII.h>
#include <sun/nio/cs/UTF_8.h>
#include <jcpp.h>

#include <java/lang/ConstStringManager.h>
#include <java/lang/ObjectManagerInternal.h>
#include <string.h>

#undef CASE_INSENSITIVE_ORDER
#undef COMPACT_STRINGS
#undef IMMUTABLE
#undef INSTANCE
#undef LATIN1
#undef MAX_LOW_SURROGATE
#undef MAX_VALUE
#undef MIN_HIGH_SURROGATE
#undef MIN_VALUE
#undef REPL
#undef REPLACE
#undef UTF16

using $ObjectStreamFieldArray = $Array<::java::io::ObjectStreamField>;
using $CharSequenceArray = $Array<::java::lang::CharSequence>;
using $Serializable = ::java::io::Serializable;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $AbstractStringBuilder = ::java::lang::AbstractStringBuilder;
using $ArithmeticException = ::java::lang::ArithmeticException;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Double = ::java::lang::Double;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Iterable = ::java::lang::Iterable;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $NullPointerException = ::java::lang::NullPointerException;
using $OutOfMemoryError = ::java::lang::OutOfMemoryError;
using $String$CaseInsensitiveComparator = ::java::lang::String$CaseInsensitiveComparator;
using $StringBuffer = ::java::lang::StringBuffer;
using $StringCoding = ::java::lang::StringCoding;
using $StringConcatHelper = ::java::lang::StringConcatHelper;
using $StringIndexOutOfBoundsException = ::java::lang::StringIndexOutOfBoundsException;
using $StringLatin1 = ::java::lang::StringLatin1;
using $StringLatin1$CharsSpliterator = ::java::lang::StringLatin1$CharsSpliterator;
using $StringUTF16 = ::java::lang::StringUTF16;
using $StringUTF16$CharsSpliterator = ::java::lang::StringUTF16$CharsSpliterator;
using $StringUTF16$CodePointsSpliterator = ::java::lang::StringUTF16$CodePointsSpliterator;
using $Void = ::java::lang::Void;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CharBuffer = ::java::nio::CharBuffer;
using $CharacterCodingException = ::java::nio::charset::CharacterCodingException;
using $Charset = ::java::nio::charset::Charset;
using $CharsetDecoder = ::java::nio::charset::CharsetDecoder;
using $CharsetEncoder = ::java::nio::charset::CharsetEncoder;
using $CoderResult = ::java::nio::charset::CoderResult;
using $CodingErrorAction = ::java::nio::charset::CodingErrorAction;
using $IllegalCharsetNameException = ::java::nio::charset::IllegalCharsetNameException;
using $MalformedInputException = ::java::nio::charset::MalformedInputException;
using $UnmappableCharacterException = ::java::nio::charset::UnmappableCharacterException;
using $UnsupportedCharsetException = ::java::nio::charset::UnsupportedCharsetException;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Comparator = ::java::util::Comparator;
using $Formatter = ::java::util::Formatter;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfInt = ::java::util::Spliterator$OfInt;
using $Function = ::java::util::function::Function;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern = ::java::util::regex::Pattern;
using $Collectors = ::java::util::stream::Collectors;
using $IntStream = ::java::util::stream::IntStream;
using $Stream = ::java::util::stream::Stream;
using $StreamSupport = ::java::util::stream::StreamSupport;
using $ArrayDecoder = ::sun::nio::cs::ArrayDecoder;
using $ArrayEncoder = ::sun::nio::cs::ArrayEncoder;
using $ISO_8859_1 = ::sun::nio::cs::ISO_8859_1;
using $US_ASCII = ::sun::nio::cs::US_ASCII;
using $UTF_8 = ::sun::nio::cs::UTF_8;

namespace java {
	namespace lang {

class String$$Lambda$lambda$indent$0 : public $Function {
	$class(String$$Lambda$lambda$indent$0, $NO_CLASS_INIT, $Function)
public:
	void init$(String* spaces) {
		$set(this, spaces, spaces);
	}
	virtual $Object* apply(Object$* s) override {
		 return $of(String::lambda$indent$0(spaces, $cast(String, s)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<String$$Lambda$lambda$indent$0>());
	}
	String* spaces = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo String$$Lambda$lambda$indent$0::fieldInfos[2] = {
	{"spaces", "Ljava/lang/String;", nullptr, $PUBLIC, $field(String$$Lambda$lambda$indent$0, spaces)},
	{}
};
$MethodInfo String$$Lambda$lambda$indent$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(String$$Lambda$lambda$indent$0, init$, void, String*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(String$$Lambda$lambda$indent$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo String$$Lambda$lambda$indent$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.String$$Lambda$lambda$indent$0",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* String$$Lambda$lambda$indent$0::load$(String* name, bool initialize) {
	$loadClass(String$$Lambda$lambda$indent$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* String$$Lambda$lambda$indent$0::class$ = nullptr;

class String$$Lambda$lambda$indent$1$1 : public $Function {
	$class(String$$Lambda$lambda$indent$1$1, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* s) override {
		 return $of(String::lambda$indent$1($cast(String, s)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<String$$Lambda$lambda$indent$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo String$$Lambda$lambda$indent$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(String$$Lambda$lambda$indent$1$1, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(String$$Lambda$lambda$indent$1$1, apply, $Object*, Object$*)},
	{}
};
$ClassInfo String$$Lambda$lambda$indent$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.String$$Lambda$lambda$indent$1$1",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* String$$Lambda$lambda$indent$1$1::load$(String* name, bool initialize) {
	$loadClass(String$$Lambda$lambda$indent$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* String$$Lambda$lambda$indent$1$1::class$ = nullptr;

class String$$Lambda$lambda$indent$2$2 : public $Function {
	$class(String$$Lambda$lambda$indent$2$2, $NO_CLASS_INIT, $Function)
public:
	void init$(int32_t n) {
		this->n = n;
	}
	virtual $Object* apply(Object$* s) override {
		 return $of(String::lambda$indent$2(n, $cast(String, s)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<String$$Lambda$lambda$indent$2$2>());
	}
	int32_t n = 0;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo String$$Lambda$lambda$indent$2$2::fieldInfos[2] = {
	{"n", "I", nullptr, $PUBLIC, $field(String$$Lambda$lambda$indent$2$2, n)},
	{}
};
$MethodInfo String$$Lambda$lambda$indent$2$2::methodInfos[3] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(String$$Lambda$lambda$indent$2$2, init$, void, int32_t)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(String$$Lambda$lambda$indent$2$2, apply, $Object*, Object$*)},
	{}
};
$ClassInfo String$$Lambda$lambda$indent$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.String$$Lambda$lambda$indent$2$2",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* String$$Lambda$lambda$indent$2$2::load$(String* name, bool initialize) {
	$loadClass(String$$Lambda$lambda$indent$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* String$$Lambda$lambda$indent$2$2::class$ = nullptr;

class String$$Lambda$lambda$stripIndent$3$3 : public $Function {
	$class(String$$Lambda$lambda$stripIndent$3$3, $NO_CLASS_INIT, $Function)
public:
	void init$(int32_t outdent) {
		this->outdent = outdent;
	}
	virtual $Object* apply(Object$* line) override {
		 return $of(String::lambda$stripIndent$3(outdent, $cast(String, line)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<String$$Lambda$lambda$stripIndent$3$3>());
	}
	int32_t outdent = 0;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo String$$Lambda$lambda$stripIndent$3$3::fieldInfos[2] = {
	{"outdent", "I", nullptr, $PUBLIC, $field(String$$Lambda$lambda$stripIndent$3$3, outdent)},
	{}
};
$MethodInfo String$$Lambda$lambda$stripIndent$3$3::methodInfos[3] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(String$$Lambda$lambda$stripIndent$3$3, init$, void, int32_t)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(String$$Lambda$lambda$stripIndent$3$3, apply, $Object*, Object$*)},
	{}
};
$ClassInfo String$$Lambda$lambda$stripIndent$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.String$$Lambda$lambda$stripIndent$3$3",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* String$$Lambda$lambda$stripIndent$3$3::load$(String* name, bool initialize) {
	$loadClass(String$$Lambda$lambda$stripIndent$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* String$$Lambda$lambda$stripIndent$3$3::class$ = nullptr;

$CompoundAttribute _String_FieldAnnotations_value[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _String_MethodAnnotations_init$1[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$NamedAttribute String_Attribute_var$0[] = {
	{"since", 's', "1.1"},
	{}
};

$CompoundAttribute _String_MethodAnnotations_init$5[] = {
	{"Ljava/lang/Deprecated;", String_Attribute_var$0},
	{}
};

$NamedAttribute String_Attribute_var$1[] = {
	{"since", 's', "1.1"},
	{}
};

$CompoundAttribute _String_MethodAnnotations_init$6[] = {
	{"Ljava/lang/Deprecated;", String_Attribute_var$1},
	{}
};

$NamedAttribute String_Attribute_var$2[] = {
	{"since", 's', "1.1"},
	{}
};

$CompoundAttribute _String_MethodAnnotations_getBytes58[] = {
	{"Ljava/lang/Deprecated;", String_Attribute_var$2},
	{}
};

$CompoundAttribute _String_MethodAnnotations_join88[] = {
	{"Ljdk/internal/vm/annotation/ForceInline;", nullptr},
	{}
};

$FieldInfo _String_FieldInfo_[] = {
	{"value", "[B", nullptr, $PRIVATE | $FINAL, $field(String, value$), _String_FieldAnnotations_value},
	{"hash", "I", nullptr, $PRIVATE, $field(String, hash)},
	{"hashIsZero", "Z", nullptr, $PRIVATE, $field(String, hashIsZero)},
	{"coder", "B", nullptr, $PRIVATE | $FINAL, $field(String, coder$)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(String, serialVersionUID)},
	{"COMPACT_STRINGS", "Z", nullptr, $STATIC | $FINAL, $staticField(String, COMPACT_STRINGS)},
	{"serialPersistentFields", "[Ljava/io/ObjectStreamField;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(String, serialPersistentFields)},
	{"REPL", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(String, REPL)},
	{"CASE_INSENSITIVE_ORDER", "Ljava/util/Comparator;", "Ljava/util/Comparator<Ljava/lang/String;>;", $PUBLIC | $STATIC | $FINAL, $staticField(String, CASE_INSENSITIVE_ORDER)},
	{"LATIN1", "B", nullptr, $STATIC | $FINAL, $constField(String, LATIN1)},
	{"UTF16", "B", nullptr, $STATIC | $FINAL, $constField(String, UTF16)},
	{}
};

$MethodInfo _String_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "()V", nullptr, $PUBLIC, $method(String, init$, void)},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(String, init$, void, String*), nullptr, nullptr, _String_MethodAnnotations_init$1},
	{"<init>", "([C)V", nullptr, $PUBLIC, $method(String, init$, void, $chars*)},
	{"<init>", "([CII)V", nullptr, $PUBLIC, $method(String, init$, void, $chars*, int32_t, int32_t)},
	{"<init>", "([III)V", nullptr, $PUBLIC, $method(String, init$, void, $ints*, int32_t, int32_t)},
	{"<init>", "([BIII)V", nullptr, $PUBLIC | $DEPRECATED, $method(String, init$, void, $bytes*, int32_t, int32_t, int32_t), nullptr, nullptr, _String_MethodAnnotations_init$5},
	{"<init>", "([BI)V", nullptr, $PUBLIC | $DEPRECATED, $method(String, init$, void, $bytes*, int32_t), nullptr, nullptr, _String_MethodAnnotations_init$6},
	{"<init>", "([BIILjava/lang/String;)V", nullptr, $PUBLIC, $method(String, init$, void, $bytes*, int32_t, int32_t, String*), "java.io.UnsupportedEncodingException"},
	{"<init>", "([BIILjava/nio/charset/Charset;)V", nullptr, $PUBLIC, $method(String, init$, void, $bytes*, int32_t, int32_t, $Charset*)},
	{"<init>", "([BLjava/lang/String;)V", nullptr, $PUBLIC, $method(String, init$, void, $bytes*, String*), "java.io.UnsupportedEncodingException"},
	{"<init>", "([BLjava/nio/charset/Charset;)V", nullptr, $PUBLIC, $method(String, init$, void, $bytes*, $Charset*)},
	{"<init>", "([BII)V", nullptr, $PUBLIC, $method(String, init$, void, $bytes*, int32_t, int32_t)},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(String, init$, void, $bytes*)},
	{"<init>", "(Ljava/lang/StringBuffer;)V", nullptr, $PUBLIC, $method(String, init$, void, $StringBuffer*)},
	{"<init>", "(Ljava/lang/StringBuilder;)V", nullptr, $PUBLIC, $method(String, init$, void, $StringBuilder*)},
	{"<init>", "([CIILjava/lang/Void;)V", nullptr, 0, $method(String, init$, void, $chars*, int32_t, int32_t, $Void*)},
	{"<init>", "(Ljava/lang/AbstractStringBuilder;Ljava/lang/Void;)V", nullptr, 0, $method(String, init$, void, $AbstractStringBuilder*, $Void*)},
	{"<init>", "([BB)V", nullptr, 0, $method(String, init$, void, $bytes*, int8_t)},
	{"charAt", "(I)C", nullptr, $PUBLIC, $virtualMethod(String, charAt, char16_t, int32_t)},
	{"chars", "()Ljava/util/stream/IntStream;", nullptr, $PUBLIC, $virtualMethod(String, chars, $IntStream*)},
	{"checkBoundsBeginEnd", "(III)V", nullptr, $STATIC, $staticMethod(String, checkBoundsBeginEnd, void, int32_t, int32_t, int32_t)},
	{"checkBoundsOffCount", "(III)V", nullptr, $STATIC, $staticMethod(String, checkBoundsOffCount, void, int32_t, int32_t, int32_t)},
	{"checkIndex", "(II)V", nullptr, $STATIC, $staticMethod(String, checkIndex, void, int32_t, int32_t)},
	{"checkOffset", "(II)V", nullptr, $STATIC, $staticMethod(String, checkOffset, void, int32_t, int32_t)},
	{"codePointAt", "(I)I", nullptr, $PUBLIC, $method(String, codePointAt, int32_t, int32_t)},
	{"codePointBefore", "(I)I", nullptr, $PUBLIC, $method(String, codePointBefore, int32_t, int32_t)},
	{"codePointCount", "(II)I", nullptr, $PUBLIC, $method(String, codePointCount, int32_t, int32_t, int32_t)},
	{"codePoints", "()Ljava/util/stream/IntStream;", nullptr, $PUBLIC, $virtualMethod(String, codePoints, $IntStream*)},
	{"coder", "()B", nullptr, 0, $method(String, coder, int8_t)},
	{"compareTo", "(Ljava/lang/String;)I", nullptr, $PUBLIC, $method(String, compareTo, int32_t, String*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(String, compareTo, int32_t, Object$*)},
	{"compareToIgnoreCase", "(Ljava/lang/String;)I", nullptr, $PUBLIC, $method(String, compareToIgnoreCase, int32_t, String*)},
	{"concat", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $method(String, concat, String*, String*)},
	{"contains", "(Ljava/lang/CharSequence;)Z", nullptr, $PUBLIC, $method(String, contains, bool, $CharSequence*)},
	{"contentEquals", "(Ljava/lang/StringBuffer;)Z", nullptr, $PUBLIC, $method(String, contentEquals, bool, $StringBuffer*)},
	{"contentEquals", "(Ljava/lang/CharSequence;)Z", nullptr, $PUBLIC, $method(String, contentEquals, bool, $CharSequence*)},
	{"copyValueOf", "([CII)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(String, copyValueOf, String*, $chars*, int32_t, int32_t)},
	{"copyValueOf", "([C)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(String, copyValueOf, String*, $chars*)},
	{"decode2", "(II)C", nullptr, $PRIVATE | $STATIC, $staticMethod(String, decode2, char16_t, int32_t, int32_t)},
	{"decode3", "(III)C", nullptr, $PRIVATE | $STATIC, $staticMethod(String, decode3, char16_t, int32_t, int32_t, int32_t)},
	{"decode4", "(IIII)I", nullptr, $PRIVATE | $STATIC, $staticMethod(String, decode4, int32_t, int32_t, int32_t, int32_t, int32_t)},
	{"decodeASCII", "([BI[CII)I", nullptr, $STATIC, $staticMethod(String, decodeASCII, int32_t, $bytes*, int32_t, $chars*, int32_t, int32_t)},
	{"decodeUTF8_UTF16", "([BII[BIZ)I", nullptr, $PRIVATE | $STATIC, $staticMethod(String, decodeUTF8_UTF16, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t, bool)},
	{"decodeWithDecoder", "(Ljava/nio/charset/CharsetDecoder;[C[BII)I", nullptr, $PRIVATE | $STATIC, $staticMethod(String, decodeWithDecoder, int32_t, $CharsetDecoder*, $chars*, $bytes*, int32_t, int32_t)},
	{"describeConstable", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(String, describeConstable, $Optional*)},
	{"encode", "(Ljava/nio/charset/Charset;B[B)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(String, encode, $bytes*, $Charset*, int8_t, $bytes*)},
	{"encode8859_1", "(B[B)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(String, encode8859_1, $bytes*, int8_t, $bytes*)},
	{"encode8859_1", "(B[BZ)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(String, encode8859_1, $bytes*, int8_t, $bytes*, bool)},
	{"encodeASCII", "(B[B)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(String, encodeASCII, $bytes*, int8_t, $bytes*)},
	{"encodeUTF8", "(B[BZ)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(String, encodeUTF8, $bytes*, int8_t, $bytes*, bool)},
	{"encodeUTF8_UTF16", "([BZ)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(String, encodeUTF8_UTF16, $bytes*, $bytes*, bool)},
	{"encodeWithEncoder", "(Ljava/nio/charset/Charset;B[BZ)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(String, encodeWithEncoder, $bytes*, $Charset*, int8_t, $bytes*, bool)},
	{"endsWith", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $method(String, endsWith, bool, String*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(String, equals, bool, Object$*)},
	{"equalsIgnoreCase", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $method(String, equalsIgnoreCase, bool, String*)},
	{"format", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(String, format, String*, String*, $ObjectArray*)},
	{"format", "(Ljava/util/Locale;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(String, format, String*, $Locale*, String*, $ObjectArray*)},
	{"formatted", "([Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PUBLIC | $TRANSIENT, $method(String, formatted, String*, $ObjectArray*)},
	{"getBytes", "(II[BI)V", nullptr, $PUBLIC | $DEPRECATED, $method(String, getBytes, void, int32_t, int32_t, $bytes*, int32_t), nullptr, nullptr, _String_MethodAnnotations_getBytes58},
	{"getBytes", "(Ljava/lang/String;)[B", nullptr, $PUBLIC, $method(String, getBytes, $bytes*, String*), "java.io.UnsupportedEncodingException"},
	{"getBytes", "(Ljava/nio/charset/Charset;)[B", nullptr, $PUBLIC, $method(String, getBytes, $bytes*, $Charset*)},
	{"getBytes", "()[B", nullptr, $PUBLIC, $method(String, getBytes, $bytes*)},
	{"getBytes", "([BIB)V", nullptr, 0, $method(String, getBytes, void, $bytes*, int32_t, int8_t)},
	{"getBytes", "([BIIBI)V", nullptr, 0, $method(String, getBytes, void, $bytes*, int32_t, int32_t, int8_t, int32_t)},
	{"getBytesNoRepl", "(Ljava/lang/String;Ljava/nio/charset/Charset;)[B", nullptr, $STATIC, $staticMethod(String, getBytesNoRepl, $bytes*, String*, $Charset*), "java.nio.charset.CharacterCodingException"},
	{"getBytesNoRepl1", "(Ljava/lang/String;Ljava/nio/charset/Charset;)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(String, getBytesNoRepl1, $bytes*, String*, $Charset*)},
	{"getBytesUTF8NoRepl", "(Ljava/lang/String;)[B", nullptr, $STATIC, $staticMethod(String, getBytesUTF8NoRepl, $bytes*, String*)},
	{"getChars", "(II[CI)V", nullptr, $PUBLIC, $method(String, getChars, void, int32_t, int32_t, $chars*, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(String, hashCode, int32_t)},
	{"indent", "(I)Ljava/lang/String;", nullptr, $PUBLIC, $method(String, indent, String*, int32_t)},
	{"indexOf", "(I)I", nullptr, $PUBLIC, $method(String, indexOf, int32_t, int32_t)},
	{"indexOf", "(II)I", nullptr, $PUBLIC, $method(String, indexOf, int32_t, int32_t, int32_t)},
	{"indexOf", "(Ljava/lang/String;)I", nullptr, $PUBLIC, $method(String, indexOf, int32_t, String*)},
	{"indexOf", "(Ljava/lang/String;I)I", nullptr, $PUBLIC, $method(String, indexOf, int32_t, String*, int32_t)},
	{"indexOf", "([BBILjava/lang/String;I)I", nullptr, $STATIC, $staticMethod(String, indexOf, int32_t, $bytes*, int8_t, int32_t, String*, int32_t)},
	{"indexOfNonWhitespace", "()I", nullptr, $PRIVATE, $method(String, indexOfNonWhitespace, int32_t)},
	{"intern", "()Ljava/lang/String;", nullptr, $PUBLIC | $NATIVE, $method(String, intern, String*)},
	{"isASCII", "([B)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(String, isASCII, bool, $bytes*)},
	{"isBlank", "()Z", nullptr, $PUBLIC, $method(String, isBlank, bool)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(String, isEmpty, bool)},
	{"isLatin1", "()Z", nullptr, 0, $method(String, isLatin1, bool)},
	{"isMalformed3", "(III)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(String, isMalformed3, bool, int32_t, int32_t, int32_t)},
	{"isMalformed3_2", "(II)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(String, isMalformed3_2, bool, int32_t, int32_t)},
	{"isMalformed4", "(III)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(String, isMalformed4, bool, int32_t, int32_t, int32_t)},
	{"isMalformed4_2", "(II)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(String, isMalformed4_2, bool, int32_t, int32_t)},
	{"isMalformed4_3", "(I)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(String, isMalformed4_3, bool, int32_t)},
	{"isNotContinuation", "(I)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(String, isNotContinuation, bool, int32_t)},
	{"join", "(Ljava/lang/CharSequence;[Ljava/lang/CharSequence;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(String, join, String*, $CharSequence*, $CharSequenceArray*)},
	{"join", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;I)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(String, join, String*, String*, String*, String*, $StringArray*, int32_t), nullptr, nullptr, _String_MethodAnnotations_join88},
	{"join", "(Ljava/lang/CharSequence;Ljava/lang/Iterable;)Ljava/lang/String;", "(Ljava/lang/CharSequence;Ljava/lang/Iterable<+Ljava/lang/CharSequence;>;)Ljava/lang/String;", $PUBLIC | $STATIC, $staticMethod(String, join, String*, $CharSequence*, $Iterable*)},
	{"lambda$indent$0", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(String, lambda$indent$0, String*, String*, String*)},
	{"lambda$indent$1", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(String, lambda$indent$1, String*, String*)},
	{"lambda$indent$2", "(ILjava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(String, lambda$indent$2, String*, int32_t, String*)},
	{"lambda$stripIndent$3", "(ILjava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(String, lambda$stripIndent$3, String*, int32_t, String*)},
	{"lastIndexOf", "(I)I", nullptr, $PUBLIC, $method(String, lastIndexOf, int32_t, int32_t)},
	{"lastIndexOf", "(II)I", nullptr, $PUBLIC, $method(String, lastIndexOf, int32_t, int32_t, int32_t)},
	{"lastIndexOf", "(Ljava/lang/String;)I", nullptr, $PUBLIC, $method(String, lastIndexOf, int32_t, String*)},
	{"lastIndexOf", "(Ljava/lang/String;I)I", nullptr, $PUBLIC, $method(String, lastIndexOf, int32_t, String*, int32_t)},
	{"lastIndexOf", "([BBILjava/lang/String;I)I", nullptr, $STATIC, $staticMethod(String, lastIndexOf, int32_t, $bytes*, int8_t, int32_t, String*, int32_t)},
	{"lastIndexOfNonWhitespace", "()I", nullptr, $PRIVATE, $method(String, lastIndexOfNonWhitespace, int32_t)},
	{"length", "()I", nullptr, $PUBLIC, $virtualMethod(String, length, int32_t)},
	{"lines", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljava/lang/String;>;", $PUBLIC, $method(String, lines, $Stream*)},
	{"lookupCharset", "(Ljava/lang/String;)Ljava/nio/charset/Charset;", nullptr, $PRIVATE | $STATIC, $staticMethod(String, lookupCharset, $Charset*, String*), "java.io.UnsupportedEncodingException"},
	{"malformed3", "([BI)I", nullptr, $PRIVATE | $STATIC, $staticMethod(String, malformed3, int32_t, $bytes*, int32_t)},
	{"malformed4", "([BI)I", nullptr, $PRIVATE | $STATIC, $staticMethod(String, malformed4, int32_t, $bytes*, int32_t)},
	{"matches", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $method(String, matches, bool, String*)},
	{"newStringNoRepl", "([BLjava/nio/charset/Charset;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(String, newStringNoRepl, String*, $bytes*, $Charset*), "java.nio.charset.CharacterCodingException"},
	{"newStringNoRepl1", "([BLjava/nio/charset/Charset;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(String, newStringNoRepl1, String*, $bytes*, $Charset*)},
	{"newStringUTF8NoRepl", "([BII)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(String, newStringUTF8NoRepl, String*, $bytes*, int32_t, int32_t)},
	{"nonSyncContentEquals", "(Ljava/lang/AbstractStringBuilder;)Z", nullptr, $PRIVATE, $method(String, nonSyncContentEquals, bool, $AbstractStringBuilder*)},
	{"offsetByCodePoints", "(II)I", nullptr, $PUBLIC, $method(String, offsetByCodePoints, int32_t, int32_t, int32_t)},
	{"outdent", "(Ljava/util/List;)I", "(Ljava/util/List<Ljava/lang/String;>;)I", $PRIVATE | $STATIC, $staticMethod(String, outdent, int32_t, $List*)},
	{"rangeCheck", "([CII)Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC, $staticMethod(String, rangeCheck, $Void*, $chars*, int32_t, int32_t)},
	{"regionMatches", "(ILjava/lang/String;II)Z", nullptr, $PUBLIC, $method(String, regionMatches, bool, int32_t, String*, int32_t, int32_t)},
	{"regionMatches", "(ZILjava/lang/String;II)Z", nullptr, $PUBLIC, $method(String, regionMatches, bool, bool, int32_t, String*, int32_t, int32_t)},
	{"repeat", "(I)Ljava/lang/String;", nullptr, $PUBLIC, $method(String, repeat, String*, int32_t)},
	{"replace", "(CC)Ljava/lang/String;", nullptr, $PUBLIC, $method(String, replace, String*, char16_t, char16_t)},
	{"replace", "(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;", nullptr, $PUBLIC, $method(String, replace, String*, $CharSequence*, $CharSequence*)},
	{"replaceAll", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $method(String, replaceAll, String*, String*, String*)},
	{"replaceFirst", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $method(String, replaceFirst, String*, String*, String*)},
	{"resolveConstantDesc", "(Ljava/lang/invoke/MethodHandles$Lookup;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(String, resolveConstantDesc, $Object*, $MethodHandles$Lookup*)},
	{"safeTrim", "([BIZ)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(String, safeTrim, $bytes*, $bytes*, int32_t, bool)},
	{"scale", "(IF)I", nullptr, $PRIVATE | $STATIC, $staticMethod(String, scale, int32_t, int32_t, float)},
	{"split", "(Ljava/lang/String;I)[Ljava/lang/String;", nullptr, $PUBLIC, $method(String, split, $StringArray*, String*, int32_t)},
	{"split", "(Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PUBLIC, $method(String, split, $StringArray*, String*)},
	{"startsWith", "(Ljava/lang/String;I)Z", nullptr, $PUBLIC, $method(String, startsWith, bool, String*, int32_t)},
	{"startsWith", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $method(String, startsWith, bool, String*)},
	{"strip", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(String, strip, String*)},
	{"stripIndent", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(String, stripIndent, String*)},
	{"stripLeading", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(String, stripLeading, String*)},
	{"stripTrailing", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(String, stripTrailing, String*)},
	{"subSequence", "(II)Ljava/lang/CharSequence;", nullptr, $PUBLIC, $virtualMethod(String, subSequence, $CharSequence*, int32_t, int32_t)},
	{"substring", "(I)Ljava/lang/String;", nullptr, $PUBLIC, $method(String, substring, String*, int32_t)},
	{"substring", "(II)Ljava/lang/String;", nullptr, $PUBLIC, $method(String, substring, String*, int32_t, int32_t)},
	{"throwMalformed", "(II)V", nullptr, $PRIVATE | $STATIC, $staticMethod(String, throwMalformed, void, int32_t, int32_t)},
	{"throwMalformed", "([B)V", nullptr, $PRIVATE | $STATIC, $staticMethod(String, throwMalformed, void, $bytes*)},
	{"throwUnmappable", "(I)V", nullptr, $PRIVATE | $STATIC, $staticMethod(String, throwUnmappable, void, int32_t)},
	{"throwUnmappable", "([B)V", nullptr, $PRIVATE | $STATIC, $staticMethod(String, throwUnmappable, void, $bytes*)},
	{"toCharArray", "()[C", nullptr, $PUBLIC, $method(String, toCharArray, $chars*)},
	{"toLowerCase", "(Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $method(String, toLowerCase, String*, $Locale*)},
	{"toLowerCase", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(String, toLowerCase, String*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(String, toString, String*)},
	{"toUpperCase", "(Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $method(String, toUpperCase, String*, $Locale*)},
	{"toUpperCase", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(String, toUpperCase, String*)},
	{"transform", "(Ljava/util/function/Function;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(Ljava/util/function/Function<-Ljava/lang/String;+TR;>;)TR;", $PUBLIC, $method(String, transform, $Object*, $Function*)},
	{"translateEscapes", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(String, translateEscapes, String*)},
	{"trim", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(String, trim, String*)},
	{"value", "()[B", nullptr, 0, $method(String, value, $bytes*)},
	{"valueOf", "(Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(String, valueOf, String*, Object$*)},
	{"valueOf", "([C)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(String, valueOf, String*, $chars*)},
	{"valueOf", "([CII)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(String, valueOf, String*, $chars*, int32_t, int32_t)},
	{"valueOf", "(Z)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(String, valueOf, String*, bool)},
	{"valueOf", "(C)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(String, valueOf, String*, char16_t)},
	{"valueOf", "(I)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(String, valueOf, String*, int32_t)},
	{"valueOf", "(J)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(String, valueOf, String*, int64_t)},
	{"valueOf", "(F)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(String, valueOf, String*, float)},
	{"valueOf", "(D)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(String, valueOf, String*, double)},
	{"valueOfCodePoint", "(I)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(String, valueOfCodePoint, String*, int32_t)},
	{}
};

#define _METHOD_INDEX_intern 78

$InnerClassInfo _String_InnerClassesInfo_[] = {
	{"java.lang.String$CaseInsensitiveComparator", "java.lang.String", "CaseInsensitiveComparator", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _String_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.lang.String",
	"java.lang.Object",
	"java.io.Serializable,java.lang.Comparable,java.lang.CharSequence,java.lang.constant.Constable,java.lang.constant.ConstantDesc",
	_String_FieldInfo_,
	_String_MethodInfo_,
	"Ljava/lang/Object;Ljava/io/Serializable;Ljava/lang/Comparable<Ljava/lang/String;>;Ljava/lang/CharSequence;Ljava/lang/constant/Constable;Ljava/lang/constant/ConstantDesc;",
	nullptr,
	_String_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.String$CaseInsensitiveComparator"
};

$Object* allocate$String($Class* clazz) {
	return $of($alloc(String));
}

$Object* String::clone() {
	 return this->$Serializable::clone();
}

void String::finalize() {
	this->$Serializable::finalize();
}

bool String::COMPACT_STRINGS = false;
$ObjectStreamFieldArray* String::serialPersistentFields = nullptr;
$Comparator* String::CASE_INSENSITIVE_ORDER = nullptr;

void String::init$() {
	$set(this, value$, $new($bytes, 0));
	coder$ = LATIN1;
}

void String::init$(String* original) {
	$set(this, value$, $nc(original)->value$);
	this->coder$ = original->coder$;
	this->hash = original->hash;
}

void String::init$($chars* value) {
	String::init$(value, 0, $nc(value)->length, ($Void*)nullptr);
}

void String::init$($chars* value, int32_t offset, int32_t count) {
	String::init$(value, offset, count, $(rangeCheck(value, offset, count)));
}

$Void* String::rangeCheck($chars* value, int32_t offset, int32_t count) {
	checkBoundsOffCount(offset, count, $nc(value)->length);
	return nullptr;
}

void String::init$($ints* codePoints, int32_t offset, int32_t count) {
	checkBoundsOffCount(offset, count, $nc(codePoints)->length);
	if (count == 0) {
		$set(this, value$, ""_s->value$);
		this->coder$ = ""_s->coder$;
		return;
	}
	if (String::COMPACT_STRINGS) {
		$var($bytes, val, $StringLatin1::toBytes(codePoints, offset, count));
		if (val != nullptr) {
			this->coder$ = String::LATIN1;
			$set(this, value$, val);
			return;
		}
	}
	this->coder$ = String::UTF16;
	$set(this, value$, $StringUTF16::toBytes(codePoints, offset, count));
}

void String::init$($bytes* ascii, int32_t hibyte, int32_t offset, int32_t count) {
	checkBoundsOffCount(offset, count, $nc(ascii)->length);
	if (count == 0) {
		$set(this, value$, ""_s->value$);
		this->coder$ = ""_s->coder$;
		return;
	}
	if (String::COMPACT_STRINGS && (int8_t)hibyte == 0) {
		$set(this, value$, $Arrays::copyOfRange(ascii, offset, offset + count));
		this->coder$ = String::LATIN1;
	} else {
		hibyte <<= 8;
		$var($bytes, val, $StringUTF16::newBytesFor(count));
		for (int32_t i = 0; i < count; ++i) {
			$StringUTF16::putChar(val, i, hibyte | ((int32_t)($nc(ascii)->get(offset++) & (uint32_t)255)));
		}
		$set(this, value$, val);
		this->coder$ = String::UTF16;
	}
}

void String::init$($bytes* ascii, int32_t hibyte) {
	String::init$(ascii, hibyte, 0, $nc(ascii)->length);
}

void String::init$($bytes* bytes, int32_t offset, int32_t length, String* charsetName) {
	String::init$(bytes, offset, length, $(lookupCharset(charsetName)));
}

void String::init$($bytes* bytes$renamed, int32_t offset, int32_t length, $Charset* charset) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, bytes, bytes$renamed);
	$Objects::requireNonNull(charset);
	checkBoundsOffCount(offset, length, $nc(bytes)->length);
	if (length == 0) {
		$set(this, value$, ""_s->value$);
		this->coder$ = ""_s->coder$;
	} else {
		$init($UTF_8);
		if ($equals(charset, $UTF_8::INSTANCE)) {
			if (String::COMPACT_STRINGS && !$StringCoding::hasNegatives(bytes, offset, length)) {
				$set(this, value$, $Arrays::copyOfRange(bytes, offset, offset + length));
				this->coder$ = String::LATIN1;
			} else {
				int32_t sl = offset + length;
				int32_t dp = 0;
				$var($bytes, dst, nullptr);
				if (String::COMPACT_STRINGS) {
					$assign(dst, $new($bytes, length));
					while (offset < sl) {
						int32_t b1 = $nc(bytes)->get(offset);
						if (b1 >= 0) {
							dst->set(dp++, (int8_t)b1);
							++offset;
							continue;
						}
						if ((b1 == (int8_t)194 || b1 == (int8_t)195) && offset + 1 < sl) {
							int32_t b2 = bytes->get(offset + 1);
							if (!isNotContinuation(b2)) {
								dst->set(dp++, (int8_t)decode2(b1, b2));
								offset += 2;
								continue;
							}
						}
						break;
					}
					if (offset == sl) {
						if (dp != dst->length) {
							$assign(dst, $Arrays::copyOf(dst, dp));
						}
						$set(this, value$, dst);
						this->coder$ = String::LATIN1;
						return;
					}
				}
				if (dp == 0 || dst == nullptr) {
					$assign(dst, $new($bytes, length << 1));
				} else {
					$var($bytes, buf, $new($bytes, length << 1));
					$StringLatin1::inflate(dst, 0, buf, 0, dp);
					$assign(dst, buf);
				}
				dp = decodeUTF8_UTF16(bytes, offset, sl, dst, dp, true);
				if (dp != length) {
					$assign(dst, $Arrays::copyOf(dst, dp << 1));
				}
				$set(this, value$, dst);
				this->coder$ = String::UTF16;
			}
		} else {
			$init($ISO_8859_1);
			if ($equals(charset, $ISO_8859_1::INSTANCE)) {
				if (String::COMPACT_STRINGS) {
					$set(this, value$, $Arrays::copyOfRange(bytes, offset, offset + length));
					this->coder$ = String::LATIN1;
				} else {
					$set(this, value$, $StringLatin1::inflate(bytes, offset, length));
					this->coder$ = String::UTF16;
				}
			} else {
				$init($US_ASCII);
				if ($equals(charset, $US_ASCII::INSTANCE)) {
					if (String::COMPACT_STRINGS && !$StringCoding::hasNegatives(bytes, offset, length)) {
						$set(this, value$, $Arrays::copyOfRange(bytes, offset, offset + length));
						this->coder$ = String::LATIN1;
					} else {
						$var($bytes, dst, $new($bytes, length << 1));
						int32_t dp = 0;
						while (dp < length) {
							int32_t b = $nc(bytes)->get(offset++);
							$StringUTF16::putChar(dst, dp++, (b >= 0) ? (char16_t)b : String::REPL);
						}
						$set(this, value$, dst);
						this->coder$ = String::UTF16;
					}
				} else {
					$var($CharsetDecoder, cd, charset->newDecoder());
					{
						$var($ArrayDecoder, ad, nullptr);
						bool var$0 = $instanceOf($ArrayDecoder, cd);
						if (var$0) {
							$assign(ad, $cast($ArrayDecoder, cd));
							var$0 = true;
						}
						if (var$0) {
							bool var$1 = $nc(ad)->isASCIICompatible();
							if (var$1 && !$StringCoding::hasNegatives(bytes, offset, length)) {
								if (String::COMPACT_STRINGS) {
									$set(this, value$, $Arrays::copyOfRange(bytes, offset, offset + length));
									this->coder$ = String::LATIN1;
									return;
								}
								$set(this, value$, $StringLatin1::inflate(bytes, offset, length));
								this->coder$ = String::UTF16;
								return;
							}
							if (String::COMPACT_STRINGS && $nc(ad)->isLatin1Decodable()) {
								$var($bytes, dst, $new($bytes, length));
								ad->decodeToLatin1(bytes, offset, length, dst);
								$set(this, value$, dst);
								this->coder$ = String::LATIN1;
								return;
							}
							int32_t en = scale(length, $nc(cd)->maxCharsPerByte());
							$init($CodingErrorAction);
							$nc($($nc(cd)->onMalformedInput($CodingErrorAction::REPLACE)))->onUnmappableCharacter($CodingErrorAction::REPLACE);
							$var($chars, ca, $new($chars, en));
							int32_t clen = $nc(ad)->decode(bytes, offset, length, ca);
							if (String::COMPACT_STRINGS) {
								$var($bytes, bs, $StringUTF16::compress(ca, 0, clen));
								if (bs != nullptr) {
									$set(this, value$, bs);
									this->coder$ = String::LATIN1;
									return;
								}
							}
							this->coder$ = String::UTF16;
							$set(this, value$, $StringUTF16::toBytes(ca, 0, clen));
							return;
						}
					}
					int32_t en = scale(length, $nc(cd)->maxCharsPerByte());
					$init($CodingErrorAction);
					$nc($($nc(cd)->onMalformedInput($CodingErrorAction::REPLACE)))->onUnmappableCharacter($CodingErrorAction::REPLACE);
					$var($chars, ca, $new($chars, en));
					bool var$2 = $of(charset)->getClass()->getClassLoader0() != nullptr;
					if (var$2 && $System::getSecurityManager() != nullptr) {
						$assign(bytes, $Arrays::copyOfRange(bytes, offset, offset + length));
						offset = 0;
					}
					int32_t caLen = decodeWithDecoder(cd, ca, bytes, offset, length);
					if (String::COMPACT_STRINGS) {
						$var($bytes, bs, $StringUTF16::compress(ca, 0, caLen));
						if (bs != nullptr) {
							$set(this, value$, bs);
							this->coder$ = String::LATIN1;
							return;
						}
					}
					this->coder$ = String::UTF16;
					$set(this, value$, $StringUTF16::toBytes(ca, 0, caLen));
				}
			}
		}
	}
}

String* String::newStringUTF8NoRepl($bytes* bytes, int32_t offset, int32_t length) {
	$useLocalCurrentObjectStackCache();
	checkBoundsOffCount(offset, length, $nc(bytes)->length);
	if (length == 0) {
		return ""_s;
	}
	if (String::COMPACT_STRINGS && !$StringCoding::hasNegatives(bytes, offset, length)) {
		return $new(String, $($Arrays::copyOfRange(bytes, offset, offset + length)), String::LATIN1);
	} else {
		int32_t sl = offset + length;
		int32_t dp = 0;
		$var($bytes, dst, nullptr);
		if (String::COMPACT_STRINGS) {
			$assign(dst, $new($bytes, length));
			while (offset < sl) {
				int32_t b1 = $nc(bytes)->get(offset);
				if (b1 >= 0) {
					dst->set(dp++, (int8_t)b1);
					++offset;
					continue;
				}
				if ((b1 == (int8_t)194 || b1 == (int8_t)195) && offset + 1 < sl) {
					int32_t b2 = bytes->get(offset + 1);
					if (!isNotContinuation(b2)) {
						dst->set(dp++, (int8_t)decode2(b1, b2));
						offset += 2;
						continue;
					}
				}
				break;
			}
			if (offset == sl) {
				if (dp != dst->length) {
					$assign(dst, $Arrays::copyOf(dst, dp));
				}
				return $new(String, dst, String::LATIN1);
			}
		}
		if (dp == 0 || dst == nullptr) {
			$assign(dst, $new($bytes, length << 1));
		} else {
			$var($bytes, buf, $new($bytes, length << 1));
			$StringLatin1::inflate(dst, 0, buf, 0, dp);
			$assign(dst, buf);
		}
		dp = decodeUTF8_UTF16(bytes, offset, sl, dst, dp, false);
		if (dp != length) {
			$assign(dst, $Arrays::copyOf(dst, dp << 1));
		}
		return $new(String, dst, String::UTF16);
	}
}

String* String::newStringNoRepl($bytes* src, $Charset* cs) {
	$useLocalCurrentObjectStackCache();
	try {
		return newStringNoRepl1(src, cs);
	} catch ($IllegalArgumentException& e) {
		$var($Throwable, cause, e->getCause());
		{
			$var($MalformedInputException, mie, nullptr);
			bool var$0 = $instanceOf($MalformedInputException, cause);
			if (var$0) {
				$assign(mie, $cast($MalformedInputException, cause));
				var$0 = true;
			}
			if (var$0) {
				$throw(mie);
			}
		}
		$throw($cast($CharacterCodingException, cause));
	}
	$shouldNotReachHere();
}

String* String::newStringNoRepl1($bytes* src$renamed, $Charset* cs) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, src, src$renamed);
	int32_t len = $nc(src)->length;
	if (len == 0) {
		return ""_s;
	}
	$init($UTF_8);
	if ($equals(cs, $UTF_8::INSTANCE)) {
		return newStringUTF8NoRepl(src, 0, src->length);
	}
	$init($ISO_8859_1);
	if ($equals(cs, $ISO_8859_1::INSTANCE)) {
		if (String::COMPACT_STRINGS) {
			return $new(String, src, String::LATIN1);
		}
		return $new(String, $($StringLatin1::inflate(src, 0, src->length)), String::UTF16);
	}
	$init($US_ASCII);
	if ($equals(cs, $US_ASCII::INSTANCE)) {
		if (!$StringCoding::hasNegatives(src, 0, src->length)) {
			if (String::COMPACT_STRINGS) {
				return $new(String, src, String::LATIN1);
			}
			return $new(String, $($StringLatin1::inflate(src, 0, src->length)), String::UTF16);
		} else {
			throwMalformed(src);
		}
	}
	$var($CharsetDecoder, cd, $nc(cs)->newDecoder());
	{
		$var($ArrayDecoder, ad, nullptr);
		bool var$2 = $instanceOf($ArrayDecoder, cd);
		if (var$2) {
			$assign(ad, $cast($ArrayDecoder, cd));
			var$2 = true;
		}
		bool var$1 = var$2;
		bool var$0 = var$1 && $nc(ad)->isASCIICompatible();
		if (var$0 && !$StringCoding::hasNegatives(src, 0, src->length)) {
			return $new(String, src, 0, src->length, static_cast<$Charset*>($ISO_8859_1::INSTANCE));
		}
	}
	int32_t en = scale(len, $nc(cd)->maxCharsPerByte());
	$var($chars, ca, $new($chars, en));
	bool var$3 = $of(cs)->getClass()->getClassLoader0() != nullptr;
	if (var$3 && $System::getSecurityManager() != nullptr) {
		$assign(src, $Arrays::copyOf(src, len));
	}
	int32_t caLen = decodeWithDecoder(cd, ca, src, 0, src->length);
	if (String::COMPACT_STRINGS) {
		$var($bytes, bs, $StringUTF16::compress(ca, 0, caLen));
		if (bs != nullptr) {
			return $new(String, bs, String::LATIN1);
		}
	}
	return $new(String, $($StringUTF16::toBytes(ca, 0, caLen)), String::UTF16);
}

$bytes* String::safeTrim($bytes* ba, int32_t len, bool isTrusted) {
	if (len == $nc(ba)->length && (isTrusted || $System::getSecurityManager() == nullptr)) {
		return ba;
	} else {
		return $Arrays::copyOf(ba, len);
	}
}

int32_t String::scale(int32_t len, float expansionFactor) {
	return $cast(int32_t, (len * (double)expansionFactor));
}

$Charset* String::lookupCharset(String* csn) {
	$Objects::requireNonNull(csn);
	try {
		return $Charset::forName(csn);
	} catch ($UnsupportedCharsetException& x) {
		$throwNew($UnsupportedEncodingException, csn);
	} catch ($IllegalCharsetNameException& x) {
		$throwNew($UnsupportedEncodingException, csn);
	}
	$shouldNotReachHere();
}

$bytes* String::encode($Charset* cs, int8_t coder, $bytes* val) {
	$init($UTF_8);
	if ($equals(cs, $UTF_8::INSTANCE)) {
		return encodeUTF8(coder, val, true);
	}
	$init($ISO_8859_1);
	if ($equals(cs, $ISO_8859_1::INSTANCE)) {
		return encode8859_1(coder, val);
	}
	$init($US_ASCII);
	if ($equals(cs, $US_ASCII::INSTANCE)) {
		return encodeASCII(coder, val);
	}
	return encodeWithEncoder(cs, coder, val, true);
}

$bytes* String::encodeWithEncoder($Charset* cs, int8_t coder, $bytes* val, bool doReplace) {
	$useLocalCurrentObjectStackCache();
	$var($CharsetEncoder, ce, $nc(cs)->newEncoder());
	int32_t len = $sr($nc(val)->length, coder);
	int32_t en = scale(len, $nc(ce)->maxBytesPerChar());
	{
		$var($ArrayEncoder, ae, nullptr);
		bool var$0 = $instanceOf($ArrayEncoder, ce);
		if (var$0) {
			$assign(ae, $cast($ArrayEncoder, ce));
			var$0 = true;
		}
		if (var$0) {
			bool var$1 = coder == String::LATIN1 && $nc(ae)->isASCIICompatible();
			if (var$1 && !$StringCoding::hasNegatives(val, 0, val->length)) {
				return $Arrays::copyOf(val, val->length);
			}
			$var($bytes, ba, $new($bytes, en));
			if (len == 0) {
				return ba;
			}
			if (doReplace) {
				$init($CodingErrorAction);
				$nc($($nc(ce)->onMalformedInput($CodingErrorAction::REPLACE)))->onUnmappableCharacter($CodingErrorAction::REPLACE);
			}
			int32_t blen = (coder == String::LATIN1) ? $nc(ae)->encodeFromLatin1(val, 0, len, ba) : ae->encodeFromUTF16(val, 0, len, ba);
			if (blen != -1) {
				return safeTrim(ba, blen, true);
			}
		}
	}
	$var($bytes, ba, $new($bytes, en));
	if (len == 0) {
		return ba;
	}
	if (doReplace) {
		$init($CodingErrorAction);
		$nc($($nc(ce)->onMalformedInput($CodingErrorAction::REPLACE)))->onUnmappableCharacter($CodingErrorAction::REPLACE);
	}
	$var($chars, ca, (coder == String::LATIN1) ? $StringLatin1::toChars(val) : $StringUTF16::toChars(val));
	$var($ByteBuffer, bb, $ByteBuffer::wrap(ba));
	$var($CharBuffer, cb, $CharBuffer::wrap(ca, 0, len));
	try {
		$var($CoderResult, cr, $nc(ce)->encode(cb, bb, true));
		if (!$nc(cr)->isUnderflow()) {
			cr->throwException();
		}
		$assign(cr, ce->flush(bb));
		if (!$nc(cr)->isUnderflow()) {
			cr->throwException();
		}
	} catch ($CharacterCodingException& x) {
		if (!doReplace) {
			$throwNew($IllegalArgumentException, static_cast<$Throwable*>(x));
		} else {
			$throwNew($Error, static_cast<$Throwable*>(x));
		}
	}
	$var($bytes, var$2, ba);
	int32_t var$3 = $nc(bb)->position();
	return safeTrim(var$2, var$3, $of(cs)->getClass()->getClassLoader0() == nullptr);
}

$bytes* String::getBytesUTF8NoRepl(String* s) {
	int8_t var$0 = $nc(s)->coder();
	return encodeUTF8(var$0, $(s->value()), false);
}

bool String::isASCII($bytes* src) {
	return !$StringCoding::hasNegatives(src, 0, $nc(src)->length);
}

$bytes* String::getBytesNoRepl(String* s, $Charset* cs) {
	try {
		return getBytesNoRepl1(s, cs);
	} catch ($IllegalArgumentException& e) {
		$var($Throwable, cause, e->getCause());
		if ($instanceOf($UnmappableCharacterException, cause)) {
			$throw($cast($UnmappableCharacterException, cause));
		}
		$throw($cast($CharacterCodingException, cause));
	}
	$shouldNotReachHere();
}

$bytes* String::getBytesNoRepl1(String* s, $Charset* cs) {
	$var($bytes, val, $nc(s)->value());
	int8_t coder = s->coder();
	$init($UTF_8);
	if ($equals(cs, $UTF_8::INSTANCE)) {
		if (coder == String::LATIN1 && isASCII(val)) {
			return val;
		}
		return encodeUTF8(coder, val, false);
	}
	$init($ISO_8859_1);
	if ($equals(cs, $ISO_8859_1::INSTANCE)) {
		if (coder == String::LATIN1) {
			return val;
		}
		return encode8859_1(coder, val, false);
	}
	$init($US_ASCII);
	if ($equals(cs, $US_ASCII::INSTANCE)) {
		if (coder == String::LATIN1) {
			if (isASCII(val)) {
				return val;
			} else {
				throwUnmappable(val);
			}
		}
	}
	return encodeWithEncoder(cs, coder, val, false);
}

$bytes* String::encodeASCII(int8_t coder, $bytes* val) {
	$useLocalCurrentObjectStackCache();
	if (coder == String::LATIN1) {
		$var($bytes, dst, $Arrays::copyOf(val, $nc(val)->length));
		for (int32_t i = 0; i < dst->length; ++i) {
			if (dst->get(i) < 0) {
				dst->set(i, (int8_t)u'?');
			}
		}
		return dst;
	}
	int32_t len = $nc(val)->length >> 1;
	$var($bytes, dst, $new($bytes, len));
	int32_t dp = 0;
	for (int32_t i = 0; i < len; ++i) {
		char16_t c = $StringUTF16::getChar(val, i);
		if (c < 128) {
			dst->set(dp++, (int8_t)c);
			continue;
		}
		bool var$0 = $Character::isHighSurrogate(c) && i + 1 < len;
		if (var$0 && $Character::isLowSurrogate($StringUTF16::getChar(val, i + 1))) {
			++i;
		}
		dst->set(dp++, (int8_t)u'?');
	}
	if (len == dp) {
		return dst;
	}
	return $Arrays::copyOf(dst, dp);
}

$bytes* String::encode8859_1(int8_t coder, $bytes* val) {
	return encode8859_1(coder, val, true);
}

$bytes* String::encode8859_1(int8_t coder, $bytes* val, bool doReplace) {
	if (coder == String::LATIN1) {
		return $Arrays::copyOf(val, $nc(val)->length);
	}
	int32_t len = $nc(val)->length >> 1;
	$var($bytes, dst, $new($bytes, len));
	int32_t dp = 0;
	int32_t sp = 0;
	int32_t sl = len;
	while (sp < sl) {
		int32_t ret = $StringCoding::implEncodeISOArray(val, sp, dst, dp, len);
		sp = sp + ret;
		dp = dp + ret;
		if (ret != len) {
			if (!doReplace) {
				throwUnmappable(sp);
			}
			char16_t c = $StringUTF16::getChar(val, sp++);
			bool var$0 = $Character::isHighSurrogate(c) && sp < sl;
			if (var$0 && $Character::isLowSurrogate($StringUTF16::getChar(val, sp))) {
				++sp;
			}
			dst->set(dp++, (int8_t)u'?');
			len = sl - sp;
		}
	}
	if (dp == dst->length) {
		return dst;
	}
	return $Arrays::copyOf(dst, dp);
}

int32_t String::decodeASCII($bytes* sa, int32_t sp, $chars* da, int32_t dp, int32_t len) {
	if (!$StringCoding::hasNegatives(sa, sp, len)) {
		$StringLatin1::inflate(sa, sp, da, dp, len);
		return len;
	} else {
		int32_t start = sp;
		int32_t end = sp + len;
		while (sp < end && $nc(sa)->get(sp) >= 0) {
			$nc(da)->set(dp++, (char16_t)sa->get(sp++));
		}
		return sp - start;
	}
}

bool String::isNotContinuation(int32_t b) {
	return ((int32_t)(b & (uint32_t)192)) != 128;
}

bool String::isMalformed3(int32_t b1, int32_t b2, int32_t b3) {
	return (b1 == (int8_t)224 && ((int32_t)(b2 & (uint32_t)224)) == 128) || ((int32_t)(b2 & (uint32_t)192)) != 128 || ((int32_t)(b3 & (uint32_t)192)) != 128;
}

bool String::isMalformed3_2(int32_t b1, int32_t b2) {
	return (b1 == (int8_t)224 && ((int32_t)(b2 & (uint32_t)224)) == 128) || ((int32_t)(b2 & (uint32_t)192)) != 128;
}

bool String::isMalformed4(int32_t b2, int32_t b3, int32_t b4) {
	return ((int32_t)(b2 & (uint32_t)192)) != 128 || ((int32_t)(b3 & (uint32_t)192)) != 128 || ((int32_t)(b4 & (uint32_t)192)) != 128;
}

bool String::isMalformed4_2(int32_t b1, int32_t b2) {
	return (b1 == 240 && (b2 < 144 || b2 > 191)) || (b1 == 244 && ((int32_t)(b2 & (uint32_t)240)) != 128) || ((int32_t)(b2 & (uint32_t)192)) != 128;
}

bool String::isMalformed4_3(int32_t b3) {
	return ((int32_t)(b3 & (uint32_t)192)) != 128;
}

char16_t String::decode2(int32_t b1, int32_t b2) {
	return (char16_t)(((b1 << 6) ^ b2) ^ (((int8_t)192 << 6) ^ ((int8_t)128 << 0)));
}

char16_t String::decode3(int32_t b1, int32_t b2, int32_t b3) {
	return (char16_t)(((b1 << 12) ^ (b2 << 6)) ^ (b3 ^ ((((int8_t)224 << 12) ^ ((int8_t)128 << 6)) ^ ((int8_t)128 << 0))));
}

int32_t String::decode4(int32_t b1, int32_t b2, int32_t b3, int32_t b4) {
	return ((((b1 << 18) ^ (b2 << 12)) ^ (b3 << 6)) ^ (b4 ^ (((((int8_t)240 << 18) ^ ((int8_t)128 << 12)) ^ ((int8_t)128 << 6)) ^ ((int8_t)128 << 0))));
}

int32_t String::decodeUTF8_UTF16($bytes* src, int32_t sp, int32_t sl, $bytes* dst, int32_t dp, bool doReplace) {
	while (sp < sl) {
		int32_t b1 = $nc(src)->get(sp++);
		if (b1 >= 0) {
			$StringUTF16::putChar(dst, dp++, (char16_t)b1);
		} else if ((b1 >> 5) == -2 && ((int32_t)(b1 & (uint32_t)30)) != 0) {
			if (sp < sl) {
				int32_t b2 = src->get(sp++);
				if (isNotContinuation(b2)) {
					if (!doReplace) {
						throwMalformed(sp - 1, 1);
					}
					$StringUTF16::putChar(dst, dp++, String::REPL);
					--sp;
				} else {
					$StringUTF16::putChar(dst, dp++, decode2(b1, b2));
				}
				continue;
			}
			if (!doReplace) {
				throwMalformed(sp, 1);
			}
			$StringUTF16::putChar(dst, dp++, String::REPL);
			break;
		} else if ((b1 >> 4) == -2) {
			if (sp + 1 < sl) {
				int32_t b2 = src->get(sp++);
				int32_t b3 = src->get(sp++);
				if (isMalformed3(b1, b2, b3)) {
					if (!doReplace) {
						throwMalformed(sp - 3, 3);
					}
					$StringUTF16::putChar(dst, dp++, String::REPL);
					sp -= 3;
					sp += malformed3(src, sp);
				} else {
					char16_t c = decode3(b1, b2, b3);
					if ($Character::isSurrogate(c)) {
						if (!doReplace) {
							throwMalformed(sp - 3, 3);
						}
						$StringUTF16::putChar(dst, dp++, String::REPL);
					} else {
						$StringUTF16::putChar(dst, dp++, c);
					}
				}
				continue;
			}
			if (sp < sl && isMalformed3_2(b1, src->get(sp))) {
				if (!doReplace) {
					throwMalformed(sp - 1, 2);
				}
				$StringUTF16::putChar(dst, dp++, String::REPL);
				continue;
			}
			if (!doReplace) {
				throwMalformed(sp, 1);
			}
			$StringUTF16::putChar(dst, dp++, String::REPL);
			break;
		} else if ((b1 >> 3) == -2) {
			if (sp + 2 < sl) {
				int32_t b2 = src->get(sp++);
				int32_t b3 = src->get(sp++);
				int32_t b4 = src->get(sp++);
				int32_t uc = decode4(b1, b2, b3, b4);
				bool var$0 = isMalformed4(b2, b3, b4);
				if (var$0 || !$Character::isSupplementaryCodePoint(uc)) {
					if (!doReplace) {
						throwMalformed(sp - 4, 4);
					}
					$StringUTF16::putChar(dst, dp++, String::REPL);
					sp -= 4;
					sp += malformed4(src, sp);
				} else {
					$StringUTF16::putChar(dst, dp++, $Character::highSurrogate(uc));
					$StringUTF16::putChar(dst, dp++, $Character::lowSurrogate(uc));
				}
				continue;
			}
			b1 &= (uint32_t)255;
			if (b1 > 244 || sp < sl && isMalformed4_2(b1, (int32_t)(src->get(sp) & (uint32_t)255))) {
				if (!doReplace) {
					throwMalformed(sp - 1, 1);
				}
				$StringUTF16::putChar(dst, dp++, String::REPL);
				continue;
			}
			if (!doReplace) {
				throwMalformed(sp - 1, 1);
			}
			++sp;
			$StringUTF16::putChar(dst, dp++, String::REPL);
			if (sp < sl && isMalformed4_3(src->get(sp))) {
				continue;
			}
			break;
		} else {
			if (!doReplace) {
				throwMalformed(sp - 1, 1);
			}
			$StringUTF16::putChar(dst, dp++, String::REPL);
		}
	}
	return dp;
}

int32_t String::decodeWithDecoder($CharsetDecoder* cd, $chars* dst, $bytes* src, int32_t offset, int32_t length) {
	$useLocalCurrentObjectStackCache();
	$var($ByteBuffer, bb, $ByteBuffer::wrap(src, offset, length));
	$var($CharBuffer, cb, $CharBuffer::wrap(dst, 0, $nc(dst)->length));
	try {
		$var($CoderResult, cr, $nc(cd)->decode(bb, cb, true));
		if (!$nc(cr)->isUnderflow()) {
			cr->throwException();
		}
		$assign(cr, cd->flush(cb));
		if (!$nc(cr)->isUnderflow()) {
			cr->throwException();
		}
	} catch ($CharacterCodingException& x) {
		$throwNew($Error, static_cast<$Throwable*>(x));
	}
	return $nc(cb)->position();
}

int32_t String::malformed3($bytes* src, int32_t sp) {
	int32_t b1 = $nc(src)->get(sp++);
	int32_t b2 = src->get(sp);
	return ((b1 == (int8_t)224 && ((int32_t)(b2 & (uint32_t)224)) == 128) || isNotContinuation(b2)) ? 1 : 2;
}

int32_t String::malformed4($bytes* src, int32_t sp) {
	int32_t b1 = (int32_t)($nc(src)->get(sp++) & (uint32_t)255);
	int32_t b2 = (int32_t)(src->get(sp++) & (uint32_t)255);
	if (b1 > 244 || (b1 == 240 && (b2 < 144 || b2 > 191)) || (b1 == 244 && ((int32_t)(b2 & (uint32_t)240)) != 128) || isNotContinuation(b2)) {
		return 1;
	}
	if (isNotContinuation(src->get(sp))) {
		return 2;
	}
	return 3;
}

void String::throwMalformed(int32_t off, int32_t nb) {
	$useLocalCurrentObjectStackCache();
	$var(String, msg, $str({"malformed input off : "_s, $$str(off), ", length : "_s, $$str(nb)}));
	$throwNew($IllegalArgumentException, msg, $$new($MalformedInputException, nb));
}

void String::throwMalformed($bytes* val) {
	int32_t dp = 0;
	while (dp < $nc(val)->length && val->get(dp) >= 0) {
		++dp;
	}
	throwMalformed(dp, 1);
}

void String::throwUnmappable(int32_t off) {
	$useLocalCurrentObjectStackCache();
	$var(String, msg, $str({"malformed input off : "_s, $$str(off), ", length : 1"_s}));
	$throwNew($IllegalArgumentException, msg, $$new($UnmappableCharacterException, 1));
}

void String::throwUnmappable($bytes* val) {
	int32_t dp = 0;
	while (dp < $nc(val)->length && val->get(dp) >= 0) {
		++dp;
	}
	throwUnmappable(dp);
}

$bytes* String::encodeUTF8(int8_t coder, $bytes* val, bool doReplace) {
	$useLocalCurrentObjectStackCache();
	if (coder == String::UTF16) {
		return encodeUTF8_UTF16(val, doReplace);
	}
	if (!$StringCoding::hasNegatives(val, 0, $nc(val)->length)) {
		return $Arrays::copyOf(val, $nc(val)->length);
	}
	int32_t dp = 0;
	$var($bytes, dst, $new($bytes, $nc(val)->length << 1));
	{
		$var($bytes, arr$, val);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			int8_t c = arr$->get(i$);
			{
				if (c < 0) {
					dst->set(dp++, (int8_t)(192 | (((int32_t)(c & (uint32_t)255)) >> 6)));
					dst->set(dp++, (int8_t)(128 | ((int32_t)(c & (uint32_t)63))));
				} else {
					dst->set(dp++, c);
				}
			}
		}
	}
	if (dp == dst->length) {
		return dst;
	}
	return $Arrays::copyOf(dst, dp);
}

$bytes* String::encodeUTF8_UTF16($bytes* val, bool doReplace) {
	int32_t dp = 0;
	int32_t sp = 0;
	int32_t sl = $nc(val)->length >> 1;
	$var($bytes, dst, $new($bytes, sl * 3));
	char16_t c = 0;
	while (sp < sl && (c = $StringUTF16::getChar(val, sp)) < (char16_t)0x80) {
		dst->set(dp++, (int8_t)c);
		++sp;
	}
	while (sp < sl) {
		c = $StringUTF16::getChar(val, sp++);
		if (c < 128) {
			dst->set(dp++, (int8_t)c);
		} else if (c < 2048) {
			dst->set(dp++, (int8_t)(192 | (c >> 6)));
			dst->set(dp++, (int8_t)(128 | ((int32_t)(c & (uint32_t)63))));
		} else if ($Character::isSurrogate(c)) {
			int32_t uc = -1;
			char16_t c2 = 0;
			bool var$0 = $Character::isHighSurrogate(c) && sp < sl;
			if (var$0 && $Character::isLowSurrogate(c2 = $StringUTF16::getChar(val, sp))) {
				uc = $Character::toCodePoint(c, c2);
			}
			if (uc < 0) {
				if (doReplace) {
					dst->set(dp++, (int8_t)u'?');
				} else {
					throwUnmappable(sp - 1);
				}
			} else {
				dst->set(dp++, (int8_t)(240 | (uc >> 18)));
				dst->set(dp++, (int8_t)(128 | ((int32_t)((uc >> 12) & (uint32_t)63))));
				dst->set(dp++, (int8_t)(128 | ((int32_t)((uc >> 6) & (uint32_t)63))));
				dst->set(dp++, (int8_t)(128 | ((int32_t)(uc & (uint32_t)63))));
				++sp;
			}
		} else {
			dst->set(dp++, (int8_t)(224 | (c >> 12)));
			dst->set(dp++, (int8_t)(128 | ((int32_t)((c >> 6) & (uint32_t)63))));
			dst->set(dp++, (int8_t)(128 | ((int32_t)(c & (uint32_t)63))));
		}
	}
	if (dp == dst->length) {
		return dst;
	}
	return $Arrays::copyOf(dst, dp);
}

void String::init$($bytes* bytes, String* charsetName) {
	String::init$(bytes, 0, $nc(bytes)->length, charsetName);
}

void String::init$($bytes* bytes, $Charset* charset) {
	String::init$(bytes, 0, $nc(bytes)->length, charset);
}

void String::init$($bytes* bytes, int32_t offset, int32_t length) {
	String::init$(bytes, offset, length, $($Charset::defaultCharset()));
}

void String::init$($bytes* bytes) {
	String::init$(bytes, 0, $nc(bytes)->length);
}

void String::init$($StringBuffer* buffer) {
	String::init$($($nc(buffer)->toString()));
}

void String::init$($StringBuilder* builder) {
	String::init$(static_cast<$AbstractStringBuilder*>(builder), ($Void*)nullptr);
}

int32_t String::length() {
	return $sr($nc(this->value$)->length, coder());
}

bool String::isEmpty() {
	return $nc(this->value$)->length == 0;
}

char16_t String::charAt(int32_t index) {
	if (isLatin1()) {
		return $StringLatin1::charAt(this->value$, index);
	} else {
		return $StringUTF16::charAt(this->value$, index);
	}
}

int32_t String::codePointAt(int32_t index) {
	if (isLatin1()) {
		checkIndex(index, $nc(this->value$)->length);
		return (int32_t)($nc(this->value$)->get(index) & (uint32_t)255);
	}
	int32_t length = $nc(this->value$)->length >> 1;
	checkIndex(index, length);
	return $StringUTF16::codePointAt(this->value$, index, length);
}

int32_t String::codePointBefore(int32_t index) {
	int32_t i = index - 1;
	if (i < 0 || i >= length()) {
		$throwNew($StringIndexOutOfBoundsException, index);
	}
	if (isLatin1()) {
		return ((int32_t)($nc(this->value$)->get(i) & (uint32_t)255));
	}
	return $StringUTF16::codePointBefore(this->value$, index);
}

int32_t String::codePointCount(int32_t beginIndex, int32_t endIndex) {
	if (beginIndex < 0 || beginIndex > endIndex || endIndex > length()) {
		$throwNew($IndexOutOfBoundsException);
	}
	if (isLatin1()) {
		return endIndex - beginIndex;
	}
	return $StringUTF16::codePointCount(this->value$, beginIndex, endIndex);
}

int32_t String::offsetByCodePoints(int32_t index, int32_t codePointOffset) {
	if (index < 0 || index > length()) {
		$throwNew($IndexOutOfBoundsException);
	}
	return $Character::offsetByCodePoints(this, index, codePointOffset);
}

void String::getChars(int32_t srcBegin, int32_t srcEnd, $chars* dst, int32_t dstBegin) {
	checkBoundsBeginEnd(srcBegin, srcEnd, length());
	checkBoundsOffCount(dstBegin, srcEnd - srcBegin, $nc(dst)->length);
	if (isLatin1()) {
		$StringLatin1::getChars(this->value$, srcBegin, srcEnd, dst, dstBegin);
	} else {
		$StringUTF16::getChars(this->value$, srcBegin, srcEnd, dst, dstBegin);
	}
}

void String::getBytes(int32_t srcBegin, int32_t srcEnd, $bytes* dst, int32_t dstBegin) {
	checkBoundsBeginEnd(srcBegin, srcEnd, length());
	$Objects::requireNonNull(dst);
	checkBoundsOffCount(dstBegin, srcEnd - srcBegin, dst->length);
	if (isLatin1()) {
		$StringLatin1::getBytes(this->value$, srcBegin, srcEnd, dst, dstBegin);
	} else {
		$StringUTF16::getBytes(this->value$, srcBegin, srcEnd, dst, dstBegin);
	}
}

$bytes* String::getBytes(String* charsetName) {
	if (charsetName == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($Charset, var$0, lookupCharset(charsetName));
	return encode(var$0, coder(), this->value$);
}

$bytes* String::getBytes($Charset* charset) {
	if (charset == nullptr) {
		$throwNew($NullPointerException);
	}
	return encode(charset, coder(), this->value$);
}

$bytes* String::getBytes() {
	$var($Charset, var$0, $Charset::defaultCharset());
	return encode(var$0, coder(), this->value$);
}

bool String::equals(Object$* anObject) {
	if ($equals(this, anObject)) {
		return true;
	}
	$var(String, aString, nullptr);
	bool var$2 = $instanceOf(String, anObject);
	if (var$2) {
		$assign(aString, $cast(String, anObject));
		var$2 = true;
	}
	bool var$1 = (var$2);
	bool var$0 = var$1 && (!String::COMPACT_STRINGS || this->coder$ == $nc(aString)->coder$);
	return var$0 && $StringLatin1::equals(this->value$, aString->value$);
}

bool String::contentEquals($StringBuffer* sb) {
	return contentEquals(static_cast<$CharSequence*>(sb));
}

bool String::nonSyncContentEquals($AbstractStringBuilder* sb) {
	$useLocalCurrentObjectStackCache();
	int32_t len = length();
	if (len != $nc(sb)->length()) {
		return false;
	}
	$var($bytes, v1, this->value$);
	$var($bytes, v2, $nc(sb)->getValue());
	int8_t coder = this->coder();
	if (coder == sb->getCoder()) {
		int32_t n = $nc(v1)->length;
		for (int32_t i = 0; i < n; ++i) {
			if (v1->get(i) != $nc(v2)->get(i)) {
				return false;
			}
		}
	} else {
		if (coder != String::LATIN1) {
			return false;
		}
		return $StringUTF16::contentEquals(v1, v2, len);
	}
	return true;
}

bool String::contentEquals($CharSequence* cs) {
	if ($instanceOf($AbstractStringBuilder, cs)) {
		if ($instanceOf($StringBuffer, cs)) {
			$synchronized(cs) {
				return nonSyncContentEquals($cast($AbstractStringBuilder, cs));
			}
		} else {
			return nonSyncContentEquals($cast($AbstractStringBuilder, cs));
		}
	}
	if ($instanceOf(String, cs)) {
		return equals(cs);
	}
	int32_t n = $nc(cs)->length();
	if (n != length()) {
		return false;
	}
	$var($bytes, val, this->value$);
	if (isLatin1()) {
		for (int32_t i = 0; i < n; ++i) {
			if (((int32_t)($nc(val)->get(i) & (uint32_t)255)) != cs->charAt(i)) {
				return false;
			}
		}
	} else if (!$StringUTF16::contentEquals(val, cs, n)) {
		return false;
	}
	return true;
}

bool String::equalsIgnoreCase(String* anotherString) {
	bool var$0 = false;
	if (this == anotherString) {
		var$0 = true;
	} else {
		bool var$2 = (anotherString != nullptr);
		if (var$2) {
			int32_t var$3 = anotherString->length();
			var$2 = (var$3 == length());
		}
		bool var$1 = var$2;
		var$0 = var$1 && regionMatches(true, 0, anotherString, 0, length());
	}
	return var$0;
}

int32_t String::compareTo(String* anotherString) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, v1, this->value$);
	$var($bytes, v2, $nc(anotherString)->value$);
	int8_t coder = this->coder();
	if (coder == anotherString->coder()) {
		return coder == String::LATIN1 ? $StringLatin1::compareTo(v1, v2) : $StringUTF16::compareTo(v1, v2);
	}
	return coder == String::LATIN1 ? $StringLatin1::compareToUTF16(v1, v2) : $StringUTF16::compareToLatin1(v1, v2);
}

int32_t String::compareToIgnoreCase(String* str) {
	return $nc(String::CASE_INSENSITIVE_ORDER)->compare(this, str);
}

bool String::regionMatches(int32_t toffset, String* other, int32_t ooffset, int32_t len) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, tv, this->value$);
	$var($bytes, ov, $nc(other)->value$);
	bool var$0 = (ooffset < 0) || (toffset < 0) || (toffset > (int64_t)length() - len);
	if (var$0 || (ooffset > (int64_t)other->length() - len)) {
		return false;
	}
	int8_t coder = this->coder();
	if (coder == other->coder()) {
		if (!isLatin1() && (len > 0)) {
			toffset = toffset << 1;
			ooffset = ooffset << 1;
			len = len << 1;
		}
		while (len-- > 0) {
			if ($nc(tv)->get(toffset++) != $nc(ov)->get(ooffset++)) {
				return false;
			}
		}
	} else if (coder == String::LATIN1) {
		while (len-- > 0) {
			char16_t var$1 = $StringLatin1::getChar(tv, toffset++);
			if (var$1 != $StringUTF16::getChar(ov, ooffset++)) {
				return false;
			}
		}
	} else {
		while (len-- > 0) {
			char16_t var$2 = $StringUTF16::getChar(tv, toffset++);
			if (var$2 != $StringLatin1::getChar(ov, ooffset++)) {
				return false;
			}
		}
	}
	return true;
}

bool String::regionMatches(bool ignoreCase, int32_t toffset, String* other, int32_t ooffset, int32_t len) {
	$useLocalCurrentObjectStackCache();
	if (!ignoreCase) {
		return regionMatches(toffset, other, ooffset, len);
	}
	bool var$0 = (ooffset < 0) || (toffset < 0) || (toffset > (int64_t)length() - len);
	if (var$0 || (ooffset > (int64_t)$nc(other)->length() - len)) {
		return false;
	}
	$var($bytes, tv, this->value$);
	$var($bytes, ov, $nc(other)->value$);
	int8_t coder = this->coder();
	if (coder == other->coder()) {
		return coder == String::LATIN1 ? $StringLatin1::regionMatchesCI(tv, toffset, ov, ooffset, len) : $StringUTF16::regionMatchesCI(tv, toffset, ov, ooffset, len);
	}
	return coder == String::LATIN1 ? $StringLatin1::regionMatchesCI_UTF16(tv, toffset, ov, ooffset, len) : $StringUTF16::regionMatchesCI_Latin1(tv, toffset, ov, ooffset, len);
}

bool String::startsWith(String* prefix, int32_t toffset) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = toffset < 0;
	if (!var$0) {
		int32_t var$1 = toffset;
		int32_t var$3 = length();
		int32_t var$2 = var$3 - $nc(prefix)->length();
		var$0 = var$1 > var$2;
	}
	if (var$0) {
		return false;
	}
	$var($bytes, ta, this->value$);
	$var($bytes, pa, $nc(prefix)->value$);
	int32_t po = 0;
	int32_t pc = $nc(pa)->length;
	int8_t coder = this->coder();
	if (coder == prefix->coder()) {
		int32_t to = (coder == String::LATIN1) ? toffset : toffset << 1;
		while (po < pc) {
			if ($nc(ta)->get(to++) != pa->get(po++)) {
				return false;
			}
		}
	} else {
		if (coder == String::LATIN1) {
			return false;
		}
		while (po < pc) {
			if ($StringUTF16::getChar(ta, toffset++) != ((int32_t)(pa->get(po++) & (uint32_t)255))) {
				return false;
			}
		}
	}
	return true;
}

bool String::startsWith(String* prefix) {
	return startsWith(prefix, 0);
}

bool String::endsWith(String* suffix) {
	int32_t var$0 = length();
	return startsWith(suffix, var$0 - $nc(suffix)->length());
}

int32_t String::hashCode() {
	int32_t h = this->hash;
	if (h == 0 && !this->hashIsZero) {
		h = isLatin1() ? $StringLatin1::hashCode(this->value$) : $StringUTF16::hashCode(this->value$);
		if (h == 0) {
			this->hashIsZero = true;
		} else {
			this->hash = h;
		}
	}
	return h;
}

int32_t String::indexOf(int32_t ch) {
	return indexOf(ch, 0);
}

int32_t String::indexOf(int32_t ch, int32_t fromIndex) {
	return isLatin1() ? $StringLatin1::indexOf(this->value$, ch, fromIndex) : $StringUTF16::indexOf(this->value$, ch, fromIndex);
}

int32_t String::lastIndexOf(int32_t ch) {
	return lastIndexOf(ch, length() - 1);
}

int32_t String::lastIndexOf(int32_t ch, int32_t fromIndex) {
	return isLatin1() ? $StringLatin1::lastIndexOf(this->value$, ch, fromIndex) : $StringUTF16::lastIndexOf(this->value$, ch, fromIndex);
}

int32_t String::indexOf(String* str) {
	int8_t coder = this->coder();
	if (coder == $nc(str)->coder()) {
		return isLatin1() ? $StringLatin1::indexOf(this->value$, str->value$) : $StringUTF16::indexOf(this->value$, str->value$);
	}
	if (coder == String::LATIN1) {
		return -1;
	}
	return $StringUTF16::indexOfLatin1(this->value$, $nc(str)->value$);
}

int32_t String::indexOf(String* str, int32_t fromIndex) {
	$var($bytes, var$0, this->value$);
	int8_t var$1 = coder();
	return indexOf(var$0, var$1, length(), str, fromIndex);
}

int32_t String::indexOf($bytes* src, int8_t srcCoder, int32_t srcCount, String* tgtStr, int32_t fromIndex) {
	$var($bytes, tgt, $nc(tgtStr)->value$);
	int8_t tgtCoder = tgtStr->coder();
	int32_t tgtCount = tgtStr->length();
	if (fromIndex >= srcCount) {
		return (tgtCount == 0 ? srcCount : -1);
	}
	if (fromIndex < 0) {
		fromIndex = 0;
	}
	if (tgtCount == 0) {
		return fromIndex;
	}
	if (tgtCount > srcCount) {
		return -1;
	}
	if (srcCoder == tgtCoder) {
		return srcCoder == String::LATIN1 ? $StringLatin1::indexOf(src, srcCount, tgt, tgtCount, fromIndex) : $StringUTF16::indexOf(src, srcCount, tgt, tgtCount, fromIndex);
	}
	if (srcCoder == String::LATIN1) {
		return -1;
	}
	return $StringUTF16::indexOfLatin1(src, srcCount, tgt, tgtCount, fromIndex);
}

int32_t String::lastIndexOf(String* str) {
	return lastIndexOf(str, length());
}

int32_t String::lastIndexOf(String* str, int32_t fromIndex) {
	$var($bytes, var$0, this->value$);
	int8_t var$1 = coder();
	return lastIndexOf(var$0, var$1, length(), str, fromIndex);
}

int32_t String::lastIndexOf($bytes* src, int8_t srcCoder, int32_t srcCount, String* tgtStr, int32_t fromIndex) {
	$var($bytes, tgt, $nc(tgtStr)->value$);
	int8_t tgtCoder = tgtStr->coder();
	int32_t tgtCount = tgtStr->length();
	int32_t rightIndex = srcCount - tgtCount;
	if (fromIndex > rightIndex) {
		fromIndex = rightIndex;
	}
	if (fromIndex < 0) {
		return -1;
	}
	if (tgtCount == 0) {
		return fromIndex;
	}
	if (srcCoder == tgtCoder) {
		return srcCoder == String::LATIN1 ? $StringLatin1::lastIndexOf(src, srcCount, tgt, tgtCount, fromIndex) : $StringUTF16::lastIndexOf(src, srcCount, tgt, tgtCount, fromIndex);
	}
	if (srcCoder == String::LATIN1) {
		return -1;
	}
	return $StringUTF16::lastIndexOfLatin1(src, srcCount, tgt, tgtCount, fromIndex);
}

String* String::substring(int32_t beginIndex) {
	return substring(beginIndex, length());
}

String* String::substring(int32_t beginIndex, int32_t endIndex) {
	int32_t length = this->length();
	checkBoundsBeginEnd(beginIndex, endIndex, length);
	if (beginIndex == 0 && endIndex == length) {
		return this;
	}
	int32_t subLen = endIndex - beginIndex;
	return isLatin1() ? $StringLatin1::newString(this->value$, beginIndex, subLen) : $StringUTF16::newString(this->value$, beginIndex, subLen);
}

$CharSequence* String::subSequence(int32_t beginIndex, int32_t endIndex) {
	return this->substring(beginIndex, endIndex);
}

String* String::concat(String* str) {
	if ($nc(str)->isEmpty()) {
		return this;
	}
	if (this->coder$ == LATIN1 && str->coder$ == LATIN1) {
		return ObjectManagerInternal::concatLatinString(this, str);
	}
	return $StringConcatHelper::simpleConcat(this, str);
}

String* String::replace(char16_t oldChar, char16_t newChar) {
	if (oldChar != newChar) {
		$var(String, ret, isLatin1() ? $StringLatin1::replace(this->value$, oldChar, newChar) : $StringUTF16::replace(this->value$, oldChar, newChar));
		if (ret != nullptr) {
			return ret;
		}
	}
	return this;
}

bool String::matches(String* regex) {
	return $Pattern::matches(regex, this);
}

bool String::contains($CharSequence* s) {
	return indexOf($($nc(s)->toString())) >= 0;
}

String* String::replaceFirst(String* regex, String* replacement) {
	$useLocalCurrentObjectStackCache();
	return $nc($($nc($($Pattern::compile(regex)))->matcher(this)))->replaceFirst(replacement);
}

String* String::replaceAll(String* regex, String* replacement) {
	$useLocalCurrentObjectStackCache();
	return $nc($($nc($($Pattern::compile(regex)))->matcher(this)))->replaceAll(replacement);
}

String* String::replace($CharSequence* target, $CharSequence* replacement) {
	$useLocalCurrentObjectStackCache();
	$var(String, trgtStr, $nc(target)->toString());
	$var(String, replStr, $nc(replacement)->toString());
	int32_t thisLen = length();
	int32_t trgtLen = $nc(trgtStr)->length();
	int32_t replLen = $nc(replStr)->length();
	if (trgtLen > 0) {
		if (trgtLen == 1 && replLen == 1) {
			char16_t var$0 = trgtStr->charAt(0);
			return replace(var$0, replStr->charAt(0));
		}
		bool thisIsLatin1 = this->isLatin1();
		bool trgtIsLatin1 = trgtStr->isLatin1();
		bool replIsLatin1 = replStr->isLatin1();
		$var(String, ret, (thisIsLatin1 && trgtIsLatin1 && replIsLatin1) ? $StringLatin1::replace(this->value$, thisLen, trgtStr->value$, trgtLen, replStr->value$, replLen) : $StringUTF16::replace(this->value$, thisLen, thisIsLatin1, trgtStr->value$, trgtLen, trgtIsLatin1, replStr->value$, replLen, replIsLatin1));
		if (ret != nullptr) {
			return ret;
		}
		return this;
	} else {
		int32_t resultLen = 0;
		try {
			resultLen = $Math::addExact(thisLen, $Math::multiplyExact($Math::addExact(thisLen, 1), replLen));
		} catch ($ArithmeticException& ignored) {
			$throwNew($OutOfMemoryError, "Required length exceeds implementation limit"_s);
		}
		$var($StringBuilder, sb, $new($StringBuilder, resultLen));
		sb->append(replStr);
		for (int32_t i = 0; i < thisLen; ++i) {
			sb->append(charAt(i))->append(replStr);
		}
		return sb->toString();
	}
}

$StringArray* String::split(String* regex, int32_t limit) {
	$useLocalCurrentObjectStackCache();
	char16_t ch = (char16_t)0;
	bool var$2 = $nc(regex)->length() == 1;
	bool var$1 = (var$2 && ".$|()[{^?*+\\"_s->indexOf((int32_t)(ch = regex->charAt(0))) == -1);
	if (!var$1) {
		bool var$4 = $nc(regex)->length() == 2;
		bool var$3 = var$4 && regex->charAt(0) == u'\\';
		var$1 = (var$3 && (((ch = regex->charAt(1)) - u'0') | (u'9' - ch)) < 0 && ((ch - u'a') | (u'z' - ch)) < 0 && ((ch - u'A') | (u'Z' - ch)) < 0);
	}
	bool var$0 = (var$1);
	if (var$0 && (ch < $Character::MIN_HIGH_SURROGATE || ch > $Character::MAX_LOW_SURROGATE)) {
		int32_t off = 0;
		int32_t next = 0;
		bool limited = limit > 0;
		$var($ArrayList, list, $new($ArrayList));
		while ((next = indexOf((int32_t)ch, off)) != -1) {
			if (!limited || list->size() < limit - 1) {
				list->add($(substring(off, next)));
				off = next + 1;
			} else {
				int32_t last = length();
				list->add($(substring(off, last)));
				off = last;
				break;
			}
		}
		if (off == 0) {
			return $new($StringArray, {this});
		}
		if (!limited || list->size() < limit) {
			list->add($(substring(off, length())));
		}
		int32_t resultSize = list->size();
		if (limit == 0) {
			while (resultSize > 0 && $nc(($cast(String, $(list->get(resultSize - 1)))))->isEmpty()) {
				--resultSize;
			}
		}
		$var($StringArray, result, $new($StringArray, resultSize));
		return $fcast($StringArray, $nc($(list->subList(0, resultSize)))->toArray(result));
	}
	return $nc($($Pattern::compile(regex)))->split(this, limit);
}

$StringArray* String::split(String* regex) {
	return split(regex, 0);
}

String* String::join($CharSequence* delimiter, $CharSequenceArray* elements) {
	$useLocalCurrentObjectStackCache();
	$var(String, delim, $nc(delimiter)->toString());
	$var($StringArray, elems, $new($StringArray, $nc(elements)->length));
	for (int32_t i = 0; i < elements->length; ++i) {
		elems->set(i, $(String::valueOf($of(elements->get(i)))));
	}
	return join(""_s, ""_s, delim, elems, elems->length);
}

String* String::join(String* prefix, String* suffix, String* delimiter, $StringArray* elements, int32_t size) {
	$useLocalCurrentObjectStackCache();
	int8_t var$0 = $nc(prefix)->coder();
	int32_t icoder = var$0 | $nc(suffix)->coder();
	int64_t var$1 = (int64_t)prefix->length();
	int64_t len = var$1 + suffix->length();
	if (size > 1) {
		len += (int64_t)(size - 1) * $nc(delimiter)->length();
		icoder |= delimiter->coder();
	}
	for (int32_t i = 0; i < size; ++i) {
		$var(String, el, $nc(elements)->get(i));
		len += $nc(el)->length();
		icoder |= el->coder();
	}
	int8_t coder = (int8_t)icoder;
	bool var$2 = len < (int64_t)0;
	if (!var$2) {
		int64_t var$3 = (len <<= coder);
		var$2 = var$3 != (int32_t)len;
	}
	if (var$2) {
		$throwNew($OutOfMemoryError, "Requested string length exceeds VM limit"_s);
	}
	$var($bytes, value, $StringConcatHelper::newArray(len));
	int32_t off = 0;
	prefix->getBytes(value, off, coder);
	off += prefix->length();
	if (size > 0) {
		$var(String, el, $nc(elements)->get(0));
		$nc(el)->getBytes(value, off, coder);
		off += el->length();
		for (int32_t i = 1; i < size; ++i) {
			$nc(delimiter)->getBytes(value, off, coder);
			off += delimiter->length();
			$assign(el, elements->get(i));
			$nc(el)->getBytes(value, off, coder);
			off += el->length();
		}
	}
	suffix->getBytes(value, off, coder);
	return $new(String, value, coder);
}

String* String::join($CharSequence* delimiter, $Iterable* elements) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(delimiter);
	$Objects::requireNonNull(elements);
	$var(String, delim, delimiter->toString());
	$var($StringArray, elems, $new($StringArray, 8));
	int32_t size = 0;
	{
		$var($Iterator, i$, elements->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($CharSequence, cs, $cast($CharSequence, i$->next()));
			{
				if (size >= elems->length) {
					$assign(elems, $fcast($StringArray, $Arrays::copyOf(elems, elems->length << 1)));
				}
				elems->set(size++, $(String::valueOf($of(cs))));
			}
		}
	}
	return join(""_s, ""_s, delim, elems, size);
}

String* String::toLowerCase($Locale* locale) {
	return isLatin1() ? $StringLatin1::toLowerCase(this, this->value$, locale) : $StringUTF16::toLowerCase(this, this->value$, locale);
}

String* String::toLowerCase() {
	return toLowerCase($($Locale::getDefault()));
}

String* String::toUpperCase($Locale* locale) {
	return isLatin1() ? $StringLatin1::toUpperCase(this, this->value$, locale) : $StringUTF16::toUpperCase(this, this->value$, locale);
}

String* String::toUpperCase() {
	return toUpperCase($($Locale::getDefault()));
}

String* String::trim() {
	$var(String, ret, isLatin1() ? $StringLatin1::trim(this->value$) : $StringUTF16::trim(this->value$));
	return ret == nullptr ? this : ret;
}

String* String::strip() {
	$var(String, ret, isLatin1() ? $StringLatin1::strip(this->value$) : $StringUTF16::strip(this->value$));
	return ret == nullptr ? this : ret;
}

String* String::stripLeading() {
	$var(String, ret, isLatin1() ? $StringLatin1::stripLeading(this->value$) : $StringUTF16::stripLeading(this->value$));
	return ret == nullptr ? this : ret;
}

String* String::stripTrailing() {
	$var(String, ret, isLatin1() ? $StringLatin1::stripTrailing(this->value$) : $StringUTF16::stripTrailing(this->value$));
	return ret == nullptr ? this : ret;
}

bool String::isBlank() {
	int32_t var$0 = indexOfNonWhitespace();
	return var$0 == length();
}

$Stream* String::lines() {
	return isLatin1() ? $StringLatin1::lines(this->value$) : $StringUTF16::lines(this->value$);
}

String* String::indent(int32_t n) {
	$useLocalCurrentObjectStackCache();
	if (isEmpty()) {
		return ""_s;
	}
	$var($Stream, stream, lines());
	if (n > 0) {
		$var(String, spaces, " "_s->repeat(n));
		$assign(stream, stream->map(static_cast<$Function*>($$new(String$$Lambda$lambda$indent$0, spaces))));
	} else if (n == $Integer::MIN_VALUE) {
		$assign(stream, stream->map(static_cast<$Function*>($$new(String$$Lambda$lambda$indent$1$1))));
	} else if (n < 0) {
		$assign(stream, stream->map(static_cast<$Function*>($$new(String$$Lambda$lambda$indent$2$2, n))));
	}
	return $cast(String, stream->collect($($Collectors::joining("\n"_s, ""_s, "\n"_s))));
}

int32_t String::indexOfNonWhitespace() {
	return isLatin1() ? $StringLatin1::indexOfNonWhitespace(this->value$) : $StringUTF16::indexOfNonWhitespace(this->value$);
}

int32_t String::lastIndexOfNonWhitespace() {
	return isLatin1() ? $StringLatin1::lastIndexOfNonWhitespace(this->value$) : $StringUTF16::lastIndexOfNonWhitespace(this->value$);
}

String* String::stripIndent() {
	$useLocalCurrentObjectStackCache();
	int32_t length = this->length();
	if (length == 0) {
		return ""_s;
	}
	char16_t lastChar = charAt(length - 1);
	bool optOut = lastChar == u'\n' || lastChar == u'\r';
	$var($List, lines, $nc($(this->lines()))->toList());
	int32_t outdent = optOut ? 0 : String::outdent(lines);
	return $cast(String, $nc($($nc($($nc(lines)->stream()))->map(static_cast<$Function*>($$new(String$$Lambda$lambda$stripIndent$3$3, outdent)))))->collect($($Collectors::joining("\n"_s, ""_s, optOut ? static_cast<$CharSequence*>("\n"_s) : static_cast<$CharSequence*>(""_s)))));
}

int32_t String::outdent($List* lines) {
	$useLocalCurrentObjectStackCache();
	int32_t outdent = $Integer::MAX_VALUE;
	{
		$var($Iterator, i$, $nc(lines)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var(String, line, $cast(String, i$->next()));
			{
				int32_t leadingWhitespace = $nc(line)->indexOfNonWhitespace();
				if (leadingWhitespace != line->length()) {
					outdent = $Integer::min(outdent, leadingWhitespace);
				}
			}
		}
	}
	$var(String, lastLine, $cast(String, lines->get(lines->size() - 1)));
	if ($nc(lastLine)->isBlank()) {
		outdent = $Integer::min(outdent, lastLine->length());
	}
	return outdent;
}

String* String::translateEscapes() {
	$useLocalCurrentObjectStackCache();
	if (isEmpty()) {
		return ""_s;
	}
	$var($chars, chars, toCharArray());
	int32_t length = chars->length;
	int32_t from = 0;
	int32_t to = 0;
	while (from < length) {
		char16_t ch = chars->get(from++);
		if (ch == u'\\') {
			ch = from < length ? chars->get(from++) : u'\0';
			{
				int32_t limit = 0;
				int32_t code = 0;
				switch (ch) {
				case u'b':
					{
						ch = u'\b';
						break;
					}
				case u'f':
					{
						ch = u'\f';
						break;
					}
				case u'n':
					{
						ch = u'\n';
						break;
					}
				case u'r':
					{
						ch = u'\r';
						break;
					}
				case u's':
					{
						ch = u' ';
						break;
					}
				case u't':
					{
						ch = u'\t';
						break;
					}
				case u'\'':
					{}
				case u'\"':
					{}
				case u'\\':
					{
						break;
					}
				case u'0':
					{}
				case u'1':
					{}
				case u'2':
					{}
				case u'3':
					{}
				case u'4':
					{}
				case u'5':
					{}
				case u'6':
					{}
				case u'7':
					{
						limit = $Integer::min(from + (ch <= u'3' ? 2 : 1), length);
						code = ch - u'0';
						while (from < limit) {
							ch = chars->get(from);
							if (ch < u'0' || u'7' < ch) {
								break;
							}
							++from;
							code = (code << 3) | (ch - u'0');
						}
						ch = (char16_t)code;
						break;
					}
				case u'\n':
					{
						continue;
					}
				case u'\r':
					{
						if (from < length && chars->get(from) == u'\n') {
							++from;
						}
						continue;
					}
				default:
					{
						{
							$var(String, msg, String::format("Invalid escape sequence: \\%c \\\\u%04X"_s, $$new($ObjectArray, {
								$($of($Character::valueOf(ch))),
								$($of($Integer::valueOf((int32_t)ch)))
							})));
							$throwNew($IllegalArgumentException, msg);
						}
					}
				}
			}
		}
		chars->set(to++, ch);
	}
	return $new(String, chars, 0, to);
}

$Object* String::transform($Function* f) {
	return $of($nc(f)->apply(this));
}

String* String::toString() {
	return this;
}

$IntStream* String::chars() {
	$useLocalCurrentObjectStackCache();
	return $StreamSupport::intStream(isLatin1() ? static_cast<$Spliterator$OfInt*>($$new($StringLatin1$CharsSpliterator, this->value$, $Spliterator::IMMUTABLE)) : static_cast<$Spliterator$OfInt*>($$new($StringUTF16$CharsSpliterator, this->value$, $Spliterator::IMMUTABLE)), false);
}

$IntStream* String::codePoints() {
	$useLocalCurrentObjectStackCache();
	return $StreamSupport::intStream(isLatin1() ? static_cast<$Spliterator$OfInt*>($$new($StringLatin1$CharsSpliterator, this->value$, $Spliterator::IMMUTABLE)) : static_cast<$Spliterator$OfInt*>($$new($StringUTF16$CodePointsSpliterator, this->value$, $Spliterator::IMMUTABLE)), false);
}

$chars* String::toCharArray() {
	return isLatin1() ? $StringLatin1::toChars(this->value$) : $StringUTF16::toChars(this->value$);
}

String* String::format(String* format, $ObjectArray* args) {
	$useLocalCurrentObjectStackCache();
	return $nc($($$new($Formatter)->format(format, args)))->toString();
}

String* String::format($Locale* l, String* format, $ObjectArray* args) {
	$useLocalCurrentObjectStackCache();
	return $nc($($$new($Formatter, l)->format(format, args)))->toString();
}

String* String::formatted($ObjectArray* args) {
	$useLocalCurrentObjectStackCache();
	return $nc($($$new($Formatter)->format(this, args)))->toString();
}

String* String::valueOf(Object$* obj) {
	return (obj == nullptr) ? "null"_s : $nc($of(obj))->toString();
}

String* String::valueOf($chars* data) {
	return $new(String, data);
}

String* String::valueOf($chars* data, int32_t offset, int32_t count) {
	return $new(String, data, offset, count);
}

String* String::copyValueOf($chars* data, int32_t offset, int32_t count) {
	return $new(String, data, offset, count);
}

String* String::copyValueOf($chars* data) {
	return $new(String, data);
}

String* String::valueOf(bool b) {
	return b ? "true"_s : "false"_s;
}

String* String::valueOf(char16_t c) {
	$useLocalCurrentObjectStackCache();
	if (String::COMPACT_STRINGS && $StringLatin1::canEncode(c)) {
		return $new(String, $($StringLatin1::toBytes(c)), String::LATIN1);
	}
	return $new(String, $($StringUTF16::toBytes(c)), String::UTF16);
}

String* String::valueOf(int32_t i) {
	return $Integer::toString(i);
}

String* String::valueOf(int64_t l) {
	return $Long::toString(l);
}

String* String::valueOf(float f) {
	return $Float::toString(f);
}

String* String::valueOf(double d) {
	return $Double::toString(d);
}

String* String::intern() {
	return ConstStringManager::intern(this);
}

String* String::repeat(int32_t count) {
	$useLocalCurrentObjectStackCache();
	if (count < 0) {
		$throwNew($IllegalArgumentException, $$str({"count is negative: "_s, $$str(count)}));
	}
	if (count == 1) {
		return this;
	}
	int32_t len = $nc(this->value$)->length;
	if (len == 0 || count == 0) {
		return ""_s;
	}
	if ($div($Integer::MAX_VALUE, count) < len) {
		$throwNew($OutOfMemoryError, "Required length exceeds implementation limit"_s);
	}
	if (len == 1) {
		$var($bytes, single, $new($bytes, count));
		$Arrays::fill(single, $nc(this->value$)->get(0));
		return $new(String, single, this->coder$);
	}
	int32_t limit = len * count;
	$var($bytes, multiple, $new($bytes, limit));
	$System::arraycopy(this->value$, 0, multiple, 0, len);
	int32_t copied = len;
	for (; copied < limit - copied; copied <<= 1) {
		$System::arraycopy(multiple, 0, multiple, copied, copied);
	}
	$System::arraycopy(multiple, 0, multiple, copied, limit - copied);
	return $new(String, multiple, this->coder$);
}

void String::getBytes($bytes* dst, int32_t dstBegin, int8_t coder) {
	if (this->coder() == coder) {
		$System::arraycopy(this->value$, 0, dst, $sl(dstBegin, coder), $nc(this->value$)->length);
	} else {
		$StringLatin1::inflate(this->value$, 0, dst, dstBegin, $nc(this->value$)->length);
	}
}

void String::getBytes($bytes* dst, int32_t srcPos, int32_t dstBegin, int8_t coder, int32_t length) {
	if (this->coder() == coder) {
		$System::arraycopy(this->value$, $sl(srcPos, coder), dst, $sl(dstBegin, coder), $sl(length, coder));
	} else {
		$StringLatin1::inflate(this->value$, srcPos, dst, dstBegin, length);
	}
}

void String::init$($chars* value, int32_t off, int32_t len, $Void* sig) {
	if (len == 0) {
		$set(this, value$, ""_s->value$);
		this->coder$ = ""_s->coder$;
		return;
	}
	if (String::COMPACT_STRINGS) {
		$var($bytes, val, $StringUTF16::compress(value, off, len));
		if (val != nullptr) {
			$set(this, value$, val);
			this->coder$ = String::LATIN1;
			return;
		}
	}
	this->coder$ = String::UTF16;
	$set(this, value$, $StringUTF16::toBytes(value, off, len));
}

void String::init$($AbstractStringBuilder* asb, $Void* sig) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, val, $nc(asb)->getValue());
	int32_t length = asb->length();
	if (asb->isLatin1()) {
		this->coder$ = String::LATIN1;
		$set(this, value$, $Arrays::copyOfRange(val, 0, length));
	} else {
		if (String::COMPACT_STRINGS) {
			$var($bytes, buf, $StringUTF16::compress(val, 0, length));
			if (buf != nullptr) {
				this->coder$ = String::LATIN1;
				$set(this, value$, buf);
				return;
			}
		}
		this->coder$ = String::UTF16;
		$set(this, value$, $Arrays::copyOfRange(val, 0, length << 1));
	}
}

void String::init$($bytes* value, int8_t coder) {
	$set(this, value$, value);
	this->coder$ = coder;
}

int8_t String::coder() {
	return String::COMPACT_STRINGS ? this->coder$ : String::UTF16;
}

$bytes* String::value() {
	return this->value$;
}

bool String::isLatin1() {
	return String::COMPACT_STRINGS && this->coder$ == String::LATIN1;
}

void String::checkIndex(int32_t index, int32_t length) {
	$useLocalCurrentObjectStackCache();
	if (index < 0 || index >= length) {
		$throwNew($StringIndexOutOfBoundsException, $$str({"index "_s, $$str(index), ", length "_s, $$str(length)}));
	}
}

void String::checkOffset(int32_t offset, int32_t length) {
	$useLocalCurrentObjectStackCache();
	if (offset < 0 || offset > length) {
		$throwNew($StringIndexOutOfBoundsException, $$str({"offset "_s, $$str(offset), ", length "_s, $$str(length)}));
	}
}

void String::checkBoundsOffCount(int32_t offset, int32_t count, int32_t length) {
	$useLocalCurrentObjectStackCache();
	if (offset < 0 || count < 0 || offset > length - count) {
		$throwNew($StringIndexOutOfBoundsException, $$str({"offset "_s, $$str(offset), ", count "_s, $$str(count), ", length "_s, $$str(length)}));
	}
}

void String::checkBoundsBeginEnd(int32_t begin, int32_t end, int32_t length) {
	$useLocalCurrentObjectStackCache();
	if (begin < 0 || begin > end || end > length) {
		$throwNew($StringIndexOutOfBoundsException, $$str({"begin "_s, $$str(begin), ", end "_s, $$str(end), ", length "_s, $$str(length)}));
	}
}

String* String::valueOfCodePoint(int32_t codePoint) {
	$useLocalCurrentObjectStackCache();
	if (String::COMPACT_STRINGS && $StringLatin1::canEncode(codePoint)) {
		return $new(String, $($StringLatin1::toBytes((char16_t)codePoint)), String::LATIN1);
	} else if ($Character::isBmpCodePoint(codePoint)) {
		return $new(String, $($StringUTF16::toBytes((char16_t)codePoint)), String::UTF16);
	} else if ($Character::isSupplementaryCodePoint(codePoint)) {
		return $new(String, $($StringUTF16::toBytesSupplementary(codePoint)), String::UTF16);
	}
	$throwNew($IllegalArgumentException, $(format("Not a valid Unicode code point: 0x%X"_s, $$new($ObjectArray, {$($of($Integer::valueOf(codePoint)))}))));
}

$Optional* String::describeConstable() {
	return $Optional::of(this);
}

$Object* String::resolveConstantDesc($MethodHandles$Lookup* lookup) {
	return $of(this);
}

int32_t String::compareTo(Object$* anotherString) {
	return this->compareTo($cast(String, anotherString));
}

String* String::lambda$stripIndent$3(int32_t outdent, String* line) {
	int32_t firstNonWhitespace = $nc(line)->indexOfNonWhitespace();
	int32_t lastNonWhitespace = line->lastIndexOfNonWhitespace();
	int32_t incidentalWhitespace = $Math::min(outdent, firstNonWhitespace);
	return firstNonWhitespace > lastNonWhitespace ? ""_s : line->substring(incidentalWhitespace, lastNonWhitespace);
}

String* String::lambda$indent$2(int32_t n, String* s) {
	return $nc(s)->substring($Math::min(-n, s->indexOfNonWhitespace()));
}

String* String::lambda$indent$1(String* s) {
	return $nc(s)->stripLeading();
}

String* String::lambda$indent$0(String* spaces, String* s) {
	return $str({spaces, s});
}

void clinit$String($Class* class$) {
	{
		String::COMPACT_STRINGS = true;
	}
	$assignStatic(String::serialPersistentFields, $new($ObjectStreamFieldArray, 0));
	$assignStatic(String::CASE_INSENSITIVE_ORDER, $new($String$CaseInsensitiveComparator));
}

String::String() {
}

bool String::equals(String* s) {
	if (s == nullptr) {
		return false;
	}
	return (!COMPACT_STRINGS || this->coder$ == s->coder$) && StringLatin1::equals(this->value$, s->value$);
}

bool String::equals(const char* s) {
	if (s == nullptr) {
		return false;
	}
	int32_t len = length();
	int32_t index = 0;
	for (; index < len; index++) {
		char c = s[index];
		if (c == 0) {
			return false;
		}
		if (charAt(index) != c) {
			return false;
		}
	}
	return s[index] == 0;
}

bool String::equals(const char16_t* s) {
	if (s == nullptr) {
		return false;
	}
	int32_t len = length();
	int32_t index = 0;
	for (; index < len; index++) {
		char16_t c = s[index];
		if (c == 0) {
			return false;
		}
		if (charAt(index) != c) {
			return false;
		}
	}
	return s[index] == 0;
}

bool String::equals(::std::nullptr_t) {
	return equals((String*)nullptr);
}

bool String::equalsIgnoreCase(const char* anotherString) {
	$nullcheck(anotherString);
	return equalsIgnoreCase($$str(anotherString));
}

bool String::equalsIgnoreCase(const char16_t* anotherString) {
	$nullcheck(anotherString);
	return equalsIgnoreCase($$str(anotherString));
}

bool String::equalsIgnoreCase(::std::nullptr_t) {
	return equalsIgnoreCase((String*)nullptr);
}

int32_t String::compareTo(const char* anotherString) {
	$nullcheck(anotherString);
	int32_t len = length();
	for (int32_t i = 0; i < len; i++) {
		char16_t c2 = anotherString[i];
		if (c2 == 0) {
			return 1;
		}
		char16_t c1 = charAt(i);
		if (c1 != c2) {
			return c1 - c2;
		}
	}
	if (anotherString[len] == 0) {
		return 0;
	}
	return -1;
}

int32_t String::compareTo(const char16_t* anotherString) {
	$nullcheck(anotherString);
	int32_t len = length();
	for (int32_t i = 0; i < len; i++) {
		char16_t c2 = anotherString[i];
		if (c2 == 0) {
			return 1;
		}
		char16_t c1 = charAt(i);
		if (c1 != c2) {
			return c1 - c2;
		}
	}
	if (anotherString[len] == 0) {
		return 0;
	}
	return -1;
}

int32_t String::compareTo(::std::nullptr_t) {
	return compareTo((String*)nullptr);
}

int32_t String::compareToIgnoreCase(const char* anotherString) {
	$nullcheck(anotherString);
	return compareToIgnoreCase($$str(anotherString));
}

int32_t String::compareToIgnoreCase(const char16_t* anotherString) {
	$nullcheck(anotherString);
	return compareToIgnoreCase($$str(anotherString));
}

int32_t String::compareToIgnoreCase(::std::nullptr_t) {
	return compareToIgnoreCase((String*)nullptr);
}

bool String::startsWith(const char* prefix, int32_t toffset) {
	$nullcheck(prefix);
	return startsWith($$str(prefix), toffset);
}

bool String::startsWith(::std::nullptr_t) {
	return startsWith((String*)nullptr);
}

bool String::startsWith(::std::nullptr_t, int32_t toffset) {
	return startsWith((String*)nullptr, toffset);
}

bool String::startsWith(const char* prefix) {
	$nullcheck(prefix);
	return startsWith($$str(prefix));
}

bool String::endsWith(const char* suffix) {
	$nullcheck(suffix);
	return endsWith($$str(suffix));
}

bool String::endsWith(::std::nullptr_t) {
	return endsWith((String*)nullptr);
}

int32_t String::indexOf(const char* str) {
	$nullcheck(str);
	return indexOf($$str(str));
}

int32_t String::indexOf(::std::nullptr_t) {
	return indexOf((String*)nullptr);
}

int32_t String::indexOf(const char* str, int32_t fromIndex) {
	$nullcheck(str);
	return indexOf($$str(str), fromIndex);
}

int32_t String::indexOf(::std::nullptr_t, int32_t fromIndex) {
	return indexOf((String*)nullptr, fromIndex);
}

int32_t String::lastIndexOf(const char* str) {
	$nullcheck(str);
	return lastIndexOf($$str(str));
}

int32_t String::lastIndexOf(::std::nullptr_t) {
	return lastIndexOf((String*)nullptr);
}

int32_t String::lastIndexOf(const char* str, int32_t fromIndex) {
	$nullcheck(str);
	return lastIndexOf($$str(str), fromIndex);
}

int32_t String::lastIndexOf(::std::nullptr_t, int32_t fromIndex) {
	return lastIndexOf((String*)nullptr, fromIndex);
}

String* String::concat(const char* str) {
	$nullcheck(str);
	return concat($$str(str));
}

String* String::concat(::std::nullptr_t) {
	return concat((String*)nullptr);
}

bool String::matches(const char* regex) {
	$nullcheck(regex);
	return matches($$str(regex));
}

bool String::matches(::std::nullptr_t) {
	return matches((String*)nullptr);
}

bool String::contains(const char* s) {
	$nullcheck(s);
	return contains($$str(s));
}

bool String::contains(::std::nullptr_t) {
	return contains((String*)nullptr);
}

String* String::replaceFirst(const char* regex, const char* replacement) {
	$nullcheck(regex);
	$nullcheck(replacement);
	return replaceFirst($$str(regex), $$str(replacement));
}

String* String::replaceAll(const char* regex, const char* replacement) {
	$nullcheck(regex);
	$nullcheck(replacement);
	return replaceAll($$str(regex), $$str(replacement));
}

String* String::replace(const char* target, const char* replacement) {
	$nullcheck(target);
	$nullcheck(replacement);
	return replace($$str(target), $$str(replacement));
}

$StringArray* String::split(const char* regex, int32_t limit) {
	$nullcheck(regex);
	return split($$str(regex), limit);
}

$StringArray* String::split(::std::nullptr_t) {
	$nullcheck(nullptr);
	return nullptr;
}

$StringArray* String::split(::std::nullptr_t, int32_t limit) {
	$nullcheck(nullptr);
	return nullptr;
}

$StringArray* String::split(const char* regex) {
	$nullcheck(regex);
	return split($$str(regex));
}

const char* String::c_str() {
	return (const char*)value$->begin();
}

int32_t String::utf8Size() {
	if (coder$ == LATIN1) {
		return value$->length;
	} else {
		$var($bytes, bytes, getBytes("UTF-8"_s));
		return bytes->length;
	}
}

$bytes* String::utf8Bytes() {
	$var($bytes, bytes, nullptr);
	if (coder$ == LATIN1) {
		$assign(bytes, value$);
	} else {
		$assign(bytes, getBytes("UTF-8"_s));
	}
	$var($bytes, ret, $new($bytes, bytes->length + 1));
	ret->setArray(0, bytes, 0, bytes->length);
	return ret;
}

char* String::utf8String(char* buf, int32_t bufLen) {
	if (buf == nullptr || bufLen <= 0) {
		return nullptr;
	}
	$var($bytes, bytes, nullptr);
	if (coder$ == LATIN1) {
		$assign(bytes, value$);
	} else {
		$assign(bytes, getBytes("UTF-8"_s));
	}
	int32_t len = Integer::min(bufLen - 1, bytes->length);
	bytes->getRegion(0, len, (int8_t*)buf);
	buf[len] = 0;
	return buf;
}

String* String::literalOf(const char* literal) {
	return ConstStringManager::literalOf(literal);
}

String* String::literalOf(const char* literal, int32_t length) {
	return ConstStringManager::literalOf(literal);
}

String* String::literalOf(const char16_t* literal) {
	return ConstStringManager::literalOf(literal);
}

String* String::literalOf(const char16_t* literal, int32_t length) {
	return ConstStringManager::literalOf(literal);
}

String* String::constValueOf(::std::nullptr_t) {
	return "null"_s;
}

String* String::constValueOf(const char* s) {
	return ConstStringManager::constValueOf(s);
}

String* String::constValueOf(const char* s, int32_t length) {
	return ConstStringManager::constValueOf(s);
}

String* String::constValueOf(const char16_t* s) {
	return ConstStringManager::constValueOf(s);
}

String* String::constValueOf(const char16_t* s, int32_t length) {
	return ConstStringManager::constValueOf(s);
}

String* String::constValueOf(const ::std::initializer_list<int32_t>& codePoints) {
	return ConstStringManager::constValueOf(codePoints);
}

String* String::constValueOf(const ::std::initializer_list<Object$*>& objects) {
	$var(String, s, valueOf(objects));
	return ConstStringManager::intern(s);
}

String* String::valueOf(::std::nullptr_t) {
	return "null"_s;
}

String* String::valueOf(String* s) {
	return (s == nullptr) ? "null"_s : s;
}

String* String::valueOf(const char* s) {
	if (s != nullptr) {
		return ObjectManagerInternal::allocString((int8_t*)s, strlen(s), LATIN1);
	} else {
		return "null"_s;
	}
}

String* String::valueOf(const char* s, int32_t length) {
	if (s != nullptr) {
		return ObjectManagerInternal::allocString((int8_t*)s, Integer::min(strlen(s), length), LATIN1);
	} else {
		return "null"_s;
	}
}

String* String::valueOf(const char16_t* s) {
	if (s == nullptr) {
		return "null"_s;
	}
	int32_t length = 0;
	for (; s[length] != 0; length++) {
	}
	if (length == 0) {
		return ""_s;
	}
	$var($chars, ca, $new($chars, length));
	ca->setRegion(0, length, s);
	return $new(String, ca);
}

String* String::valueOf(const char16_t* s, int32_t length) {
	if (length == 0) {
		return ""_s;
	}
	if (s == nullptr) {
		return "null"_s;
	}
	$var($chars, ca, $new($chars, length));
	ca->setRegion(0, length, s);
	return $new(String, ca);
}

String* String::valueOf(const ::std::initializer_list<int32_t>& codePoints) {
	$var($ints, ia, $new($ints, codePoints));
	return $new(String, ia, 0, ia->length);
}

String* String::valueOf(const ::std::initializer_list<Object$*>& objects) {
	$var(StringBuilder, sb, $new(StringBuilder));
	::std::initializer_list<Object$*>::iterator it = objects.begin();
	while (it != objects.end()) {
		Object* obj = (Object*)*it;
		if (obj != nullptr) {
			String* s = $fcast(String, class$->castOrNull(obj));
			if (s != nullptr) {
				sb->append(s);
			} else {
				sb->append(obj);
			}
		} else {
			sb->append("null"_s);
		}
		++it;
	}
	return sb->toString();
}

String* String::concat(Object$* left, Object$* right) {
	if (left != nullptr) {
		Object* lObj = (Object*)left;
		$var(String, lStr, lObj->toString());
		if (right != nullptr) {
			Object* rObj = (Object*)right;
			$var(String, rStr, rObj->toString());
			return lStr->concat(rStr);
		} else {
			return lStr->concat("null"_s);
		}
	}
	if (right != nullptr) {
		Object* rObj = (Object*)right;
		$var(String, rStr, rObj->toString());
		return "null"_s->concat(rStr);
	} else {
		return "nullnull"_s;
	}
}

String* String::concat(::std::nullptr_t, ::std::nullptr_t) {
	return "nullnull"_s;
}

String* String::concat(String* left, String* right) {
	if (left != nullptr) {
		if (right != nullptr) {
			return left->concat(right);
		} else {
			return left->concat("null"_s);
		}
	}
	if (right != nullptr) {
		return "null"_s->concat(right);
	} else {
		return "nullnull"_s;
	}
}

String* String::concat(Object$* left, const char* right) {
	return concat(left, $$str(right));
}

String* String::concat(String* left, const char* right) {
	return concat(left, $$str(right));
}

String* String::concat(Object$* left, const char16_t* right) {
	return concat(left, $$str(right));
}

String* String::concat(String* left, const char16_t* right) {
	return concat(left, $$str(right));
}

String* String::concat(const char* left, Object$* right) {
	return concat($$str(left), right);
}

String* String::concat(const char* left, String* right) {
	return concat($$str(left), right);
}

String* String::concat(const char* left, const char* right) {
	return concat($$str(left), $$str(right));
}

String* String::concat(const char* left, const char16_t* right) {
	return concat($$str(left), $$str(right));
}

String* String::concat(const char16_t* left, Object$* right) {
	return concat($$str(left), right);
}

String* String::concat(const char16_t* left, String* right) {
	return concat($$str(left), right);
}

String* String::concat(const char16_t* left, const char* right) {
	return concat($$str(left), $$str(right));
}

String* String::concat(const char16_t* left, const char16_t* right) {
	return concat($$str(left), $$str(right));
}

$Class* String::load$(String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(String$$Lambda$lambda$indent$0::classInfo$.name)) {
			return String$$Lambda$lambda$indent$0::load$(name, initialize);
		}
		if (name->equals(String$$Lambda$lambda$indent$1$1::classInfo$.name)) {
			return String$$Lambda$lambda$indent$1$1::load$(name, initialize);
		}
		if (name->equals(String$$Lambda$lambda$indent$2$2::classInfo$.name)) {
			return String$$Lambda$lambda$indent$2$2::load$(name, initialize);
		}
		if (name->equals(String$$Lambda$lambda$stripIndent$3$3::classInfo$.name)) {
			return String$$Lambda$lambda$stripIndent$3$3::load$(name, initialize);
		}
	}
	$loadClass(String, name, initialize, &_String_ClassInfo_, clinit$String, allocate$String);
	return class$;
}

$Class* String::class$ = nullptr;

	} // lang
} // java