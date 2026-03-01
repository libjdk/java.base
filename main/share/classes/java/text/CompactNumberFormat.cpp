#include <java/text/CompactNumberFormat.h>

#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/Math.h>
#include <java/lang/Number.h>
#include <java/lang/StringBuffer.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/math/BigDecimal.h>
#include <java/math/BigInteger.h>
#include <java/math/RoundingMode.h>
#include <java/text/AttributedCharacterIterator.h>
#include <java/text/CharacterIteratorFieldDelegate.h>
#include <java/text/CompactNumberFormat$Patterns.h>
#include <java/text/DecimalFormat.h>
#include <java/text/DecimalFormatSymbols.h>
#include <java/text/DigitList.h>
#include <java/text/FieldPosition.h>
#include <java/text/Format$Field.h>
#include <java/text/Format$FieldDelegate.h>
#include <java/text/NumberFormat$Field.h>
#include <java/text/NumberFormat.h>
#include <java/text/ParsePosition.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/concurrent/atomic/AtomicInteger.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/IntUnaryOperator.h>
#include <java/util/function/Predicate.h>
#include <java/util/regex/MatchResult.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/IntStream.h>
#include <java/util/stream/Stream.h>
#include <jcpp.h>

#include <cmath>

#undef CONDITION
#undef COUNT_PATTERN
#undef CURRENCY_SIGN
#undef DECIMAL_SEPARATOR
#undef DIGIT
#undef DIGITS
#undef DOUBLE_FRACTION_DIGITS
#undef DOUBLE_INTEGER_DIGITS
#undef EXPR
#undef EXPR_PATTERN
#undef GROUPING_SEPARATOR
#undef HALF_EVEN
#undef MINUS_SIGN
#undef NAMED_EXPR
#undef NAMED_RELATION
#undef NAMED_VALUE_RANGE
#undef NEGATIVE_INFINITY
#undef ONE
#undef PERCENT
#undef PER_MILLE
#undef PLURALRULES_PATTERN
#undef PLURALS
#undef POSITIVE_INFINITY
#undef PREFIX
#undef QUOTE
#undef RANGE_MULTIPLIER
#undef RELATION
#undef RELATION_PATTERN
#undef SEPARATOR
#undef SIGN
#undef SPECIAL_PATTERN
#undef STATUS_INFINITE
#undef STATUS_LENGTH
#undef STATUS_POSITIVE
#undef SUFFIX
#undef VALUE_RANGE
#undef VALUE_RANGE_PATTERN
#undef ZERO
#undef ZERO_DIGIT

using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $Serializable = ::java::io::Serializable;
using $ArithmeticException = ::java::lang::ArithmeticException;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Number = ::java::lang::Number;
using $Short = ::java::lang::Short;
using $StringBuffer = ::java::lang::StringBuffer;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $BigDecimal = ::java::math::BigDecimal;
using $BigInteger = ::java::math::BigInteger;
using $RoundingMode = ::java::math::RoundingMode;
using $AttributedCharacterIterator = ::java::text::AttributedCharacterIterator;
using $CharacterIteratorFieldDelegate = ::java::text::CharacterIteratorFieldDelegate;
using $CompactNumberFormat$Patterns = ::java::text::CompactNumberFormat$Patterns;
using $DecimalFormat = ::java::text::DecimalFormat;
using $DecimalFormatSymbols = ::java::text::DecimalFormatSymbols;
using $DigitList = ::java::text::DigitList;
using $FieldPosition = ::java::text::FieldPosition;
using $Format$Field = ::java::text::Format$Field;
using $Format$FieldDelegate = ::java::text::Format$FieldDelegate;
using $NumberFormat = ::java::text::NumberFormat;
using $NumberFormat$Field = ::java::text::NumberFormat$Field;
using $ParsePosition = ::java::text::ParsePosition;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $AtomicInteger = ::java::util::concurrent::atomic::AtomicInteger;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $IntFunction = ::java::util::function::IntFunction;
using $IntUnaryOperator = ::java::util::function::IntUnaryOperator;
using $Predicate = ::java::util::function::Predicate;
using $MatchResult = ::java::util::regex::MatchResult;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern = ::java::util::regex::Pattern;
using $Collectors = ::java::util::stream::Collectors;
using $IntStream = ::java::util::stream::IntStream;
using $Stream = ::java::util::stream::Stream;

namespace java {
	namespace text {

class CompactNumberFormat$$Lambda$lambda$processCompactPatterns$0 : public $Consumer {
	$class(CompactNumberFormat$$Lambda$lambda$processCompactPatterns$0, $NO_CLASS_INIT, $Consumer)
public:
	void init$(CompactNumberFormat* inst, int32_t idx) {
		$set(this, inst$, inst);
		this->idx = idx;
	}
	virtual void accept(Object$* mr) override {
		$nc(inst$)->lambda$processCompactPatterns$0(idx, $cast($MatchResult, mr));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CompactNumberFormat$$Lambda$lambda$processCompactPatterns$0>());
	}
	CompactNumberFormat* inst$ = nullptr;
	int32_t idx = 0;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo CompactNumberFormat$$Lambda$lambda$processCompactPatterns$0::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(CompactNumberFormat$$Lambda$lambda$processCompactPatterns$0, inst$)},
	{"idx", "I", nullptr, $PUBLIC, $field(CompactNumberFormat$$Lambda$lambda$processCompactPatterns$0, idx)},
	{}
};
$MethodInfo CompactNumberFormat$$Lambda$lambda$processCompactPatterns$0::methodInfos[3] = {
	{"<init>", "(Ljava/text/CompactNumberFormat;I)V", nullptr, $PUBLIC, $method(CompactNumberFormat$$Lambda$lambda$processCompactPatterns$0, init$, void, CompactNumberFormat*, int32_t)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat$$Lambda$lambda$processCompactPatterns$0, accept, void, Object$*)},
	{}
};
$ClassInfo CompactNumberFormat$$Lambda$lambda$processCompactPatterns$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.text.CompactNumberFormat$$Lambda$lambda$processCompactPatterns$0",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* CompactNumberFormat$$Lambda$lambda$processCompactPatterns$0::load$($String* name, bool initialize) {
	$loadClass(CompactNumberFormat$$Lambda$lambda$processCompactPatterns$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CompactNumberFormat$$Lambda$lambda$processCompactPatterns$0::class$ = nullptr;

class CompactNumberFormat$$Lambda$validateRule$1 : public $Function {
	$class(CompactNumberFormat$$Lambda$validateRule$1, $NO_CLASS_INIT, $Function)
public:
	void init$(CompactNumberFormat* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* rule) override {
		 return $of($nc(inst$)->validateRule($cast($String, rule)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CompactNumberFormat$$Lambda$validateRule$1>());
	}
	CompactNumberFormat* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo CompactNumberFormat$$Lambda$validateRule$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(CompactNumberFormat$$Lambda$validateRule$1, inst$)},
	{}
};
$MethodInfo CompactNumberFormat$$Lambda$validateRule$1::methodInfos[3] = {
	{"<init>", "(Ljava/text/CompactNumberFormat;)V", nullptr, $PUBLIC, $method(CompactNumberFormat$$Lambda$validateRule$1, init$, void, CompactNumberFormat*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat$$Lambda$validateRule$1, apply, $Object*, Object$*)},
	{}
};
$ClassInfo CompactNumberFormat$$Lambda$validateRule$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.text.CompactNumberFormat$$Lambda$validateRule$1",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* CompactNumberFormat$$Lambda$validateRule$1::load$($String* name, bool initialize) {
	$loadClass(CompactNumberFormat$$Lambda$validateRule$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CompactNumberFormat$$Lambda$validateRule$1::class$ = nullptr;

class CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$1$2 : public $Function {
	$class(CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$1$2, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* r) override {
		 return $of(CompactNumberFormat::lambda$buildPluralRulesMap$1($cast($String, r)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$1$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$1$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$1$2, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$1$2, apply, $Object*, Object$*)},
	{}
};
$ClassInfo CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$1$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.text.CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$1$2",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$1$2::load$($String* name, bool initialize) {
	$loadClass(CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$1$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$1$2::class$ = nullptr;

class CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$2$3 : public $Function {
	$class(CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$2$3, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* r) override {
		 return $of(CompactNumberFormat::lambda$buildPluralRulesMap$2($cast($String, r)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$2$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$2$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$2$3, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$2$3, apply, $Object*, Object$*)},
	{}
};
$ClassInfo CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$2$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.text.CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$2$3",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$2$3::load$($String* name, bool initialize) {
	$loadClass(CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$2$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$2$3::class$ = nullptr;

class CompactNumberFormat$$Lambda$getNumericValue$4 : public $IntUnaryOperator {
	$class(CompactNumberFormat$$Lambda$getNumericValue$4, $NO_CLASS_INIT, $IntUnaryOperator)
public:
	void init$() {
	}
	virtual int32_t applyAsInt(int32_t codePoint) override {
		 return $Character::getNumericValue(codePoint);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CompactNumberFormat$$Lambda$getNumericValue$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo CompactNumberFormat$$Lambda$getNumericValue$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CompactNumberFormat$$Lambda$getNumericValue$4, init$, void)},
	{"applyAsInt", "(I)I", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat$$Lambda$getNumericValue$4, applyAsInt, int32_t, int32_t)},
	{}
};
$ClassInfo CompactNumberFormat$$Lambda$getNumericValue$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.text.CompactNumberFormat$$Lambda$getNumericValue$4",
	"java.lang.Object",
	"java.util.function.IntUnaryOperator",
	nullptr,
	methodInfos
};
$Class* CompactNumberFormat$$Lambda$getNumericValue$4::load$($String* name, bool initialize) {
	$loadClass(CompactNumberFormat$$Lambda$getNumericValue$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CompactNumberFormat$$Lambda$getNumericValue$4::class$ = nullptr;

class CompactNumberFormat$$Lambda$toString$5 : public $IntFunction {
	$class(CompactNumberFormat$$Lambda$toString$5, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t i) override {
		 return $of($Integer::toString(i));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CompactNumberFormat$$Lambda$toString$5>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo CompactNumberFormat$$Lambda$toString$5::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CompactNumberFormat$$Lambda$toString$5, init$, void)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat$$Lambda$toString$5, apply, $Object*, int32_t)},
	{}
};
$ClassInfo CompactNumberFormat$$Lambda$toString$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.text.CompactNumberFormat$$Lambda$toString$5",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
$Class* CompactNumberFormat$$Lambda$toString$5::load$($String* name, bool initialize) {
	$loadClass(CompactNumberFormat$$Lambda$toString$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CompactNumberFormat$$Lambda$toString$5::class$ = nullptr;

class CompactNumberFormat$$Lambda$lambda$getPluralCategory$3$6 : public $Predicate {
	$class(CompactNumberFormat$$Lambda$lambda$getPluralCategory$3$6, $NO_CLASS_INIT, $Predicate)
public:
	void init$(double input) {
		this->input = input;
	}
	virtual bool test(Object$* e) override {
		 return CompactNumberFormat::lambda$getPluralCategory$3(input, $cast($Map$Entry, e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CompactNumberFormat$$Lambda$lambda$getPluralCategory$3$6>());
	}
	double input = 0.0;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo CompactNumberFormat$$Lambda$lambda$getPluralCategory$3$6::fieldInfos[2] = {
	{"input", "D", nullptr, $PUBLIC, $field(CompactNumberFormat$$Lambda$lambda$getPluralCategory$3$6, input)},
	{}
};
$MethodInfo CompactNumberFormat$$Lambda$lambda$getPluralCategory$3$6::methodInfos[3] = {
	{"<init>", "(D)V", nullptr, $PUBLIC, $method(CompactNumberFormat$$Lambda$lambda$getPluralCategory$3$6, init$, void, double)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat$$Lambda$lambda$getPluralCategory$3$6, test, bool, Object$*)},
	{}
};
$ClassInfo CompactNumberFormat$$Lambda$lambda$getPluralCategory$3$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.text.CompactNumberFormat$$Lambda$lambda$getPluralCategory$3$6",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* CompactNumberFormat$$Lambda$lambda$getPluralCategory$3$6::load$($String* name, bool initialize) {
	$loadClass(CompactNumberFormat$$Lambda$lambda$getPluralCategory$3$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CompactNumberFormat$$Lambda$lambda$getPluralCategory$3$6::class$ = nullptr;

class CompactNumberFormat$$Lambda$getKey$7 : public $Function {
	$class(CompactNumberFormat$$Lambda$getKey$7, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $sure($Map$Entry, inst$)->getKey();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CompactNumberFormat$$Lambda$getKey$7>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo CompactNumberFormat$$Lambda$getKey$7::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CompactNumberFormat$$Lambda$getKey$7, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat$$Lambda$getKey$7, apply, $Object*, Object$*)},
	{}
};
$ClassInfo CompactNumberFormat$$Lambda$getKey$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.text.CompactNumberFormat$$Lambda$getKey$7",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* CompactNumberFormat$$Lambda$getKey$7::load$($String* name, bool initialize) {
	$loadClass(CompactNumberFormat$$Lambda$getKey$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CompactNumberFormat$$Lambda$getKey$7::class$ = nullptr;

class CompactNumberFormat$$Lambda$lambda$matchPluralRule$5$8 : public $Predicate {
	$class(CompactNumberFormat$$Lambda$lambda$matchPluralRule$5$8, $NO_CLASS_INIT, $Predicate)
public:
	void init$(double input) {
		this->input = input;
	}
	virtual bool test(Object$* and_condition) override {
		 return CompactNumberFormat::lambda$matchPluralRule$5(input, $cast($String, and_condition));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CompactNumberFormat$$Lambda$lambda$matchPluralRule$5$8>());
	}
	double input = 0.0;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo CompactNumberFormat$$Lambda$lambda$matchPluralRule$5$8::fieldInfos[2] = {
	{"input", "D", nullptr, $PUBLIC, $field(CompactNumberFormat$$Lambda$lambda$matchPluralRule$5$8, input)},
	{}
};
$MethodInfo CompactNumberFormat$$Lambda$lambda$matchPluralRule$5$8::methodInfos[3] = {
	{"<init>", "(D)V", nullptr, $PUBLIC, $method(CompactNumberFormat$$Lambda$lambda$matchPluralRule$5$8, init$, void, double)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat$$Lambda$lambda$matchPluralRule$5$8, test, bool, Object$*)},
	{}
};
$ClassInfo CompactNumberFormat$$Lambda$lambda$matchPluralRule$5$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.text.CompactNumberFormat$$Lambda$lambda$matchPluralRule$5$8",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* CompactNumberFormat$$Lambda$lambda$matchPluralRule$5$8::load$($String* name, bool initialize) {
	$loadClass(CompactNumberFormat$$Lambda$lambda$matchPluralRule$5$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CompactNumberFormat$$Lambda$lambda$matchPluralRule$5$8::class$ = nullptr;

class CompactNumberFormat$$Lambda$lambda$relationCheck$6$9 : public $Predicate {
	$class(CompactNumberFormat$$Lambda$lambda$relationCheck$6$9, $NO_CLASS_INIT, $Predicate)
public:
	void init$(double lop) {
		this->lop = lop;
	}
	virtual bool test(Object$* c) override {
		 return CompactNumberFormat::lambda$relationCheck$6(lop, $cast($String, c));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CompactNumberFormat$$Lambda$lambda$relationCheck$6$9>());
	}
	double lop = 0.0;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo CompactNumberFormat$$Lambda$lambda$relationCheck$6$9::fieldInfos[2] = {
	{"lop", "D", nullptr, $PUBLIC, $field(CompactNumberFormat$$Lambda$lambda$relationCheck$6$9, lop)},
	{}
};
$MethodInfo CompactNumberFormat$$Lambda$lambda$relationCheck$6$9::methodInfos[3] = {
	{"<init>", "(D)V", nullptr, $PUBLIC, $method(CompactNumberFormat$$Lambda$lambda$relationCheck$6$9, init$, void, double)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat$$Lambda$lambda$relationCheck$6$9, test, bool, Object$*)},
	{}
};
$ClassInfo CompactNumberFormat$$Lambda$lambda$relationCheck$6$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.text.CompactNumberFormat$$Lambda$lambda$relationCheck$6$9",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* CompactNumberFormat$$Lambda$lambda$relationCheck$6$9::load$($String* name, bool initialize) {
	$loadClass(CompactNumberFormat$$Lambda$lambda$relationCheck$6$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CompactNumberFormat$$Lambda$lambda$relationCheck$6$9::class$ = nullptr;

class CompactNumberFormat$$Lambda$lambda$matchPluralRule$4$10 : public $Predicate {
	$class(CompactNumberFormat$$Lambda$lambda$matchPluralRule$4$10, $NO_CLASS_INIT, $Predicate)
public:
	void init$(double input) {
		this->input = input;
	}
	virtual bool test(Object$* r) override {
		 return CompactNumberFormat::lambda$matchPluralRule$4(input, $cast($String, r));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CompactNumberFormat$$Lambda$lambda$matchPluralRule$4$10>());
	}
	double input = 0.0;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo CompactNumberFormat$$Lambda$lambda$matchPluralRule$4$10::fieldInfos[2] = {
	{"input", "D", nullptr, $PUBLIC, $field(CompactNumberFormat$$Lambda$lambda$matchPluralRule$4$10, input)},
	{}
};
$MethodInfo CompactNumberFormat$$Lambda$lambda$matchPluralRule$4$10::methodInfos[3] = {
	{"<init>", "(D)V", nullptr, $PUBLIC, $method(CompactNumberFormat$$Lambda$lambda$matchPluralRule$4$10, init$, void, double)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat$$Lambda$lambda$matchPluralRule$4$10, test, bool, Object$*)},
	{}
};
$ClassInfo CompactNumberFormat$$Lambda$lambda$matchPluralRule$4$10::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.text.CompactNumberFormat$$Lambda$lambda$matchPluralRule$4$10",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* CompactNumberFormat$$Lambda$lambda$matchPluralRule$4$10::load$($String* name, bool initialize) {
	$loadClass(CompactNumberFormat$$Lambda$lambda$matchPluralRule$4$10, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CompactNumberFormat$$Lambda$lambda$matchPluralRule$4$10::class$ = nullptr;

$FieldInfo _CompactNumberFormat_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompactNumberFormat, serialVersionUID)},
	{"compactPatterns", "[Ljava/lang/String;", nullptr, $PRIVATE, $field(CompactNumberFormat, compactPatterns)},
	{"positivePrefixPatterns", "Ljava/util/List;", "Ljava/util/List<Ljava/text/CompactNumberFormat$Patterns;>;", $PRIVATE | $TRANSIENT, $field(CompactNumberFormat, positivePrefixPatterns)},
	{"negativePrefixPatterns", "Ljava/util/List;", "Ljava/util/List<Ljava/text/CompactNumberFormat$Patterns;>;", $PRIVATE | $TRANSIENT, $field(CompactNumberFormat, negativePrefixPatterns)},
	{"positiveSuffixPatterns", "Ljava/util/List;", "Ljava/util/List<Ljava/text/CompactNumberFormat$Patterns;>;", $PRIVATE | $TRANSIENT, $field(CompactNumberFormat, positiveSuffixPatterns)},
	{"negativeSuffixPatterns", "Ljava/util/List;", "Ljava/util/List<Ljava/text/CompactNumberFormat$Patterns;>;", $PRIVATE | $TRANSIENT, $field(CompactNumberFormat, negativeSuffixPatterns)},
	{"divisors", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Number;>;", $PRIVATE | $TRANSIENT, $field(CompactNumberFormat, divisors)},
	{"placeHolderPatterns", "Ljava/util/List;", "Ljava/util/List<Ljava/text/CompactNumberFormat$Patterns;>;", $PRIVATE | $TRANSIENT, $field(CompactNumberFormat, placeHolderPatterns)},
	{"symbols", "Ljava/text/DecimalFormatSymbols;", nullptr, $PRIVATE, $field(CompactNumberFormat, symbols)},
	{"decimalPattern", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(CompactNumberFormat, decimalPattern)},
	{"decimalFormat", "Ljava/text/DecimalFormat;", nullptr, $PRIVATE | $TRANSIENT, $field(CompactNumberFormat, decimalFormat)},
	{"defaultDecimalFormat", "Ljava/text/DecimalFormat;", nullptr, $PRIVATE | $TRANSIENT, $field(CompactNumberFormat, defaultDecimalFormat)},
	{"groupingSize", "B", nullptr, $PRIVATE, $field(CompactNumberFormat, groupingSize)},
	{"parseBigDecimal", "Z", nullptr, $PRIVATE, $field(CompactNumberFormat, parseBigDecimal)},
	{"roundingMode", "Ljava/math/RoundingMode;", nullptr, $PRIVATE, $field(CompactNumberFormat, roundingMode)},
	{"pluralRules", "Ljava/lang/String;", nullptr, $PRIVATE, $field(CompactNumberFormat, pluralRules)},
	{"rulesMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $TRANSIENT, $field(CompactNumberFormat, rulesMap)},
	{"SPECIAL_PATTERN", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CompactNumberFormat, SPECIAL_PATTERN)},
	{"RANGE_MULTIPLIER", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompactNumberFormat, RANGE_MULTIPLIER)},
	{"PLURALS", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CompactNumberFormat, PLURALS)},
	{"COUNT_PATTERN", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CompactNumberFormat, COUNT_PATTERN)},
	{"EXPR", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CompactNumberFormat, EXPR)},
	{"RELATION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CompactNumberFormat, RELATION)},
	{"VALUE_RANGE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CompactNumberFormat, VALUE_RANGE)},
	{"CONDITION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CompactNumberFormat, CONDITION)},
	{"PLURALRULES_PATTERN", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CompactNumberFormat, PLURALRULES_PATTERN)},
	{"digitList", "Ljava/text/DigitList;", nullptr, $PRIVATE | $FINAL | $TRANSIENT, $field(CompactNumberFormat, digitList)},
	{"STATUS_INFINITE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompactNumberFormat, STATUS_INFINITE)},
	{"STATUS_POSITIVE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompactNumberFormat, STATUS_POSITIVE)},
	{"STATUS_LENGTH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompactNumberFormat, STATUS_LENGTH)},
	{"ZERO_DIGIT", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompactNumberFormat, ZERO_DIGIT)},
	{"DIGIT", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompactNumberFormat, DIGIT)},
	{"DECIMAL_SEPARATOR", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompactNumberFormat, DECIMAL_SEPARATOR)},
	{"GROUPING_SEPARATOR", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompactNumberFormat, GROUPING_SEPARATOR)},
	{"MINUS_SIGN", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompactNumberFormat, MINUS_SIGN)},
	{"PERCENT", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompactNumberFormat, PERCENT)},
	{"PER_MILLE", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompactNumberFormat, PER_MILLE)},
	{"SEPARATOR", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompactNumberFormat, SEPARATOR)},
	{"CURRENCY_SIGN", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompactNumberFormat, CURRENCY_SIGN)},
	{"QUOTE", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompactNumberFormat, QUOTE)},
	{"positivePrefixes", "Ljava/util/List;", "Ljava/util/List<Ljava/text/CompactNumberFormat$Patterns;>;", $PRIVATE | $TRANSIENT, $field(CompactNumberFormat, positivePrefixes)},
	{"negativePrefixes", "Ljava/util/List;", "Ljava/util/List<Ljava/text/CompactNumberFormat$Patterns;>;", $PRIVATE | $TRANSIENT, $field(CompactNumberFormat, negativePrefixes)},
	{"positiveSuffixes", "Ljava/util/List;", "Ljava/util/List<Ljava/text/CompactNumberFormat$Patterns;>;", $PRIVATE | $TRANSIENT, $field(CompactNumberFormat, positiveSuffixes)},
	{"negativeSuffixes", "Ljava/util/List;", "Ljava/util/List<Ljava/text/CompactNumberFormat$Patterns;>;", $PRIVATE | $TRANSIENT, $field(CompactNumberFormat, negativeSuffixes)},
	{"DIGITS", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CompactNumberFormat, DIGITS)},
	{"NAMED_EXPR", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CompactNumberFormat, NAMED_EXPR)},
	{"NAMED_RELATION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CompactNumberFormat, NAMED_RELATION)},
	{"NAMED_VALUE_RANGE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CompactNumberFormat, NAMED_VALUE_RANGE)},
	{"EXPR_PATTERN", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CompactNumberFormat, EXPR_PATTERN)},
	{"RELATION_PATTERN", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CompactNumberFormat, RELATION_PATTERN)},
	{"VALUE_RANGE_PATTERN", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CompactNumberFormat, VALUE_RANGE_PATTERN)},
	{}
};

$MethodInfo _CompactNumberFormat_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/text/DecimalFormatSymbols;[Ljava/lang/String;)V", nullptr, $PUBLIC, $method(CompactNumberFormat, init$, void, $String*, $DecimalFormatSymbols*, $StringArray*)},
	{"<init>", "(Ljava/lang/String;Ljava/text/DecimalFormatSymbols;[Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(CompactNumberFormat, init$, void, $String*, $DecimalFormatSymbols*, $StringArray*, $String*)},
	{"append", "(Ljava/lang/StringBuffer;Ljava/lang/String;Ljava/text/Format$FieldDelegate;Ljava/util/List;)V", "(Ljava/lang/StringBuffer;Ljava/lang/String;Ljava/text/Format$FieldDelegate;Ljava/util/List<Ljava/text/FieldPosition;>;)V", $PRIVATE, $method(CompactNumberFormat, append, void, $StringBuffer*, $String*, $Format$FieldDelegate*, $List*)},
	{"appendPrefix", "(Ljava/lang/StringBuffer;Ljava/lang/String;Ljava/text/Format$FieldDelegate;)V", nullptr, $PRIVATE, $method(CompactNumberFormat, appendPrefix, void, $StringBuffer*, $String*, $Format$FieldDelegate*)},
	{"appendSuffix", "(Ljava/lang/StringBuffer;Ljava/lang/String;Ljava/text/Format$FieldDelegate;)V", nullptr, $PRIVATE, $method(CompactNumberFormat, appendSuffix, void, $StringBuffer*, $String*, $Format$FieldDelegate*)},
	{"applyPattern", "(Ljava/lang/String;Ljava/lang/String;I)V", nullptr, $PRIVATE, $method(CompactNumberFormat, applyPattern, void, $String*, $String*, int32_t)},
	{"buildPluralRulesMap", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE, $method(CompactNumberFormat, buildPluralRulesMap, $Map*)},
	{"clone", "()Ljava/text/CompactNumberFormat;", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat, clone, $Object*)},
	{"computeDivisor", "(Ljava/lang/String;I)Ljava/lang/Number;", nullptr, $PRIVATE, $method(CompactNumberFormat, computeDivisor, $Number*, $String*, int32_t)},
	{"computeParseMultiplier", "(Ljava/lang/String;Ljava/text/ParsePosition;Ljava/lang/String;[ZZZD)Ljava/lang/Number;", nullptr, $PRIVATE, $method(CompactNumberFormat, computeParseMultiplier, $Number*, $String*, $ParsePosition*, $String*, $booleans*, bool, bool, double)},
	{"convertIfNegative", "(Ljava/lang/Number;[ZZ)Ljava/lang/Number;", nullptr, $PRIVATE, $method(CompactNumberFormat, convertIfNegative, $Number*, $Number*, $booleans*, bool)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat, equals, bool, Object$*)},
	{"evalLOperand", "(Ljava/util/regex/Matcher;D)D", nullptr, $PRIVATE | $STATIC, $staticMethod(CompactNumberFormat, evalLOperand, double, $Matcher*, double)},
	{"expandAffix", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(CompactNumberFormat, expandAffix, $String*, $String*)},
	{"expandAffixPatterns", "()V", nullptr, $PRIVATE, $method(CompactNumberFormat, expandAffixPatterns, void)},
	{"format", "(Ljava/lang/Object;Ljava/lang/StringBuffer;Ljava/text/FieldPosition;)Ljava/lang/StringBuffer;", nullptr, $PUBLIC | $FINAL, $virtualMethod(CompactNumberFormat, format, $StringBuffer*, Object$*, $StringBuffer*, $FieldPosition*)},
	{"format", "(DLjava/lang/StringBuffer;Ljava/text/FieldPosition;)Ljava/lang/StringBuffer;", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat, format, $StringBuffer*, double, $StringBuffer*, $FieldPosition*)},
	{"format", "(DLjava/lang/StringBuffer;Ljava/text/Format$FieldDelegate;)Ljava/lang/StringBuffer;", nullptr, $PRIVATE, $method(CompactNumberFormat, format, $StringBuffer*, double, $StringBuffer*, $Format$FieldDelegate*)},
	{"format", "(JLjava/lang/StringBuffer;Ljava/text/FieldPosition;)Ljava/lang/StringBuffer;", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat, format, $StringBuffer*, int64_t, $StringBuffer*, $FieldPosition*)},
	{"format", "(JLjava/lang/StringBuffer;Ljava/text/Format$FieldDelegate;)Ljava/lang/StringBuffer;", nullptr, $PRIVATE, $method(CompactNumberFormat, format, $StringBuffer*, int64_t, $StringBuffer*, $Format$FieldDelegate*)},
	{"format", "(Ljava/math/BigDecimal;Ljava/lang/StringBuffer;Ljava/text/FieldPosition;)Ljava/lang/StringBuffer;", nullptr, $PRIVATE, $method(CompactNumberFormat, format, $StringBuffer*, $BigDecimal*, $StringBuffer*, $FieldPosition*)},
	{"format", "(Ljava/math/BigDecimal;Ljava/lang/StringBuffer;Ljava/text/Format$FieldDelegate;)Ljava/lang/StringBuffer;", nullptr, $PRIVATE, $method(CompactNumberFormat, format, $StringBuffer*, $BigDecimal*, $StringBuffer*, $Format$FieldDelegate*)},
	{"format", "(Ljava/math/BigInteger;Ljava/lang/StringBuffer;Ljava/text/FieldPosition;)Ljava/lang/StringBuffer;", nullptr, $PRIVATE, $method(CompactNumberFormat, format, $StringBuffer*, $BigInteger*, $StringBuffer*, $FieldPosition*)},
	{"format", "(Ljava/math/BigInteger;Ljava/lang/StringBuffer;Ljava/text/Format$FieldDelegate;Z)Ljava/lang/StringBuffer;", nullptr, $PRIVATE, $method(CompactNumberFormat, format, $StringBuffer*, $BigInteger*, $StringBuffer*, $Format$FieldDelegate*, bool)},
	{"formatToCharacterIterator", "(Ljava/lang/Object;)Ljava/text/AttributedCharacterIterator;", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat, formatToCharacterIterator, $AttributedCharacterIterator*, Object$*)},
	{"generateParseResult", "(Ljava/lang/Number;ZZ[ZLjava/lang/Number;)Ljava/lang/Number;", nullptr, $PRIVATE, $method(CompactNumberFormat, generateParseResult, $Number*, $Number*, bool, bool, $booleans*, $Number*)},
	{"getAffix", "(ZZZII)Ljava/lang/String;", nullptr, $PRIVATE, $method(CompactNumberFormat, getAffix, $String*, bool, bool, bool, int32_t, int32_t)},
	{"getFieldPositions", "(Ljava/lang/String;Ljava/text/NumberFormat$Field;)Ljava/util/List;", "(Ljava/lang/String;Ljava/text/NumberFormat$Field;)Ljava/util/List<Ljava/text/FieldPosition;>;", $PRIVATE, $method(CompactNumberFormat, getFieldPositions, $List*, $String*, $NumberFormat$Field*)},
	{"getGroupingSize", "()I", nullptr, $PUBLIC, $method(CompactNumberFormat, getGroupingSize, int32_t)},
	{"getIntegerPart", "(DD)I", nullptr, $PRIVATE, $method(CompactNumberFormat, getIntegerPart, int32_t, double, double)},
	{"getPluralCategory", "(D)Ljava/lang/String;", nullptr, $PRIVATE, $method(CompactNumberFormat, getPluralCategory, $String*, double)},
	{"getRoundingMode", "()Ljava/math/RoundingMode;", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat, getRoundingMode, $RoundingMode*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat, hashCode, int32_t)},
	{"isGroupingUsed", "()Z", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat, isGroupingUsed, bool)},
	{"isParseBigDecimal", "()Z", nullptr, $PUBLIC, $method(CompactNumberFormat, isParseBigDecimal, bool)},
	{"isParseIntegerOnly", "()Z", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat, isParseIntegerOnly, bool)},
	{"lambda$buildPluralRulesMap$1", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(CompactNumberFormat, lambda$buildPluralRulesMap$1, $String*, $String*)},
	{"lambda$buildPluralRulesMap$2", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(CompactNumberFormat, lambda$buildPluralRulesMap$2, $String*, $String*)},
	{"lambda$getPluralCategory$3", "(DLjava/util/Map$Entry;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(CompactNumberFormat, lambda$getPluralCategory$3, bool, double, $Map$Entry*)},
	{"lambda$matchPluralRule$4", "(DLjava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(CompactNumberFormat, lambda$matchPluralRule$4, bool, double, $String*)},
	{"lambda$matchPluralRule$5", "(DLjava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(CompactNumberFormat, lambda$matchPluralRule$5, bool, double, $String*)},
	{"lambda$processCompactPatterns$0", "(ILjava/util/regex/MatchResult;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(CompactNumberFormat, lambda$processCompactPatterns$0, void, int32_t, $MatchResult*)},
	{"lambda$relationCheck$6", "(DLjava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(CompactNumberFormat, lambda$relationCheck$6, bool, double, $String*)},
	{"matchAffix", "(Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(CompactNumberFormat, matchAffix, bool, $String*, int32_t, $String*, $String*, $String*)},
	{"matchPluralRule", "(Ljava/lang/String;D)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(CompactNumberFormat, matchPluralRule, bool, $String*, double)},
	{"matchPrefixAndSuffix", "(Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(CompactNumberFormat, matchPrefixAndSuffix, bool, $String*, int32_t, $String*, $String*, $String*, $String*, $String*, $String*)},
	{"parse", "(Ljava/lang/String;Ljava/text/ParsePosition;)Ljava/lang/Number;", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat, parse, $Number*, $String*, $ParsePosition*)},
	{"parseNumberPart", "(Ljava/lang/String;I)D", nullptr, $PRIVATE, $method(CompactNumberFormat, parseNumberPart, double, $String*, int32_t)},
	{"processCompactPatterns", "()V", nullptr, $PRIVATE, $method(CompactNumberFormat, processCompactPatterns, void)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(CompactNumberFormat, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"relationCheck", "(Ljava/lang/String;D)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(CompactNumberFormat, relationCheck, bool, $String*, double)},
	{"selectCompactPattern", "(J)I", nullptr, $PRIVATE, $method(CompactNumberFormat, selectCompactPattern, int32_t, int64_t)},
	{"selectCompactPattern", "(Ljava/math/BigInteger;)I", nullptr, $PRIVATE, $method(CompactNumberFormat, selectCompactPattern, int32_t, $BigInteger*)},
	{"setGroupingSize", "(I)V", nullptr, $PUBLIC, $method(CompactNumberFormat, setGroupingSize, void, int32_t)},
	{"setGroupingUsed", "(Z)V", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat, setGroupingUsed, void, bool)},
	{"setMaximumFractionDigits", "(I)V", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat, setMaximumFractionDigits, void, int32_t)},
	{"setMaximumIntegerDigits", "(I)V", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat, setMaximumIntegerDigits, void, int32_t)},
	{"setMinimumFractionDigits", "(I)V", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat, setMinimumFractionDigits, void, int32_t)},
	{"setMinimumIntegerDigits", "(I)V", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat, setMinimumIntegerDigits, void, int32_t)},
	{"setParseBigDecimal", "(Z)V", nullptr, $PUBLIC, $method(CompactNumberFormat, setParseBigDecimal, void, bool)},
	{"setParseIntegerOnly", "(Z)V", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat, setParseIntegerOnly, void, bool)},
	{"setRoundingMode", "(Ljava/math/RoundingMode;)V", nullptr, $PUBLIC, $virtualMethod(CompactNumberFormat, setRoundingMode, void, $RoundingMode*)},
	{"valOrRangeMatches", "(Ljava/lang/String;D)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(CompactNumberFormat, valOrRangeMatches, bool, $String*, double)},
	{"validateRule", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(CompactNumberFormat, validateRule, $String*, $String*)},
	{}
};

$InnerClassInfo _CompactNumberFormat_InnerClassesInfo_[] = {
	{"java.text.CompactNumberFormat$Patterns", "java.text.CompactNumberFormat", "Patterns", $PRIVATE | $FINAL},
	{}
};

$ClassInfo _CompactNumberFormat_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.text.CompactNumberFormat",
	"java.text.NumberFormat",
	nullptr,
	_CompactNumberFormat_FieldInfo_,
	_CompactNumberFormat_MethodInfo_,
	nullptr,
	nullptr,
	_CompactNumberFormat_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.text.CompactNumberFormat$Patterns"
};

$Object* allocate$CompactNumberFormat($Class* clazz) {
	return $of($alloc(CompactNumberFormat));
}

$String* CompactNumberFormat::SPECIAL_PATTERN = nullptr;
$Pattern* CompactNumberFormat::PLURALS = nullptr;
$Pattern* CompactNumberFormat::COUNT_PATTERN = nullptr;
$String* CompactNumberFormat::EXPR = nullptr;
$String* CompactNumberFormat::RELATION = nullptr;
$String* CompactNumberFormat::VALUE_RANGE = nullptr;
$String* CompactNumberFormat::CONDITION = nullptr;
$Pattern* CompactNumberFormat::PLURALRULES_PATTERN = nullptr;
$Pattern* CompactNumberFormat::DIGITS = nullptr;
$String* CompactNumberFormat::NAMED_EXPR = nullptr;
$String* CompactNumberFormat::NAMED_RELATION = nullptr;
$String* CompactNumberFormat::NAMED_VALUE_RANGE = nullptr;
$Pattern* CompactNumberFormat::EXPR_PATTERN = nullptr;
$Pattern* CompactNumberFormat::RELATION_PATTERN = nullptr;
$Pattern* CompactNumberFormat::VALUE_RANGE_PATTERN = nullptr;

void CompactNumberFormat::init$($String* decimalPattern, $DecimalFormatSymbols* symbols, $StringArray* compactPatterns) {
	CompactNumberFormat::init$(decimalPattern, symbols, compactPatterns, ""_s);
}

void CompactNumberFormat::init$($String* decimalPattern, $DecimalFormatSymbols* symbols, $StringArray* compactPatterns, $String* pluralRules) {
	$NumberFormat::init$();
	this->groupingSize = (int8_t)0;
	this->parseBigDecimal = false;
	$init($RoundingMode);
	$set(this, roundingMode, $RoundingMode::HALF_EVEN);
	$set(this, pluralRules, ""_s);
	$set(this, digitList, $new($DigitList));
	$Objects::requireNonNull($of(decimalPattern), "decimalPattern"_s);
	$Objects::requireNonNull($of(symbols), "symbols"_s);
	$Objects::requireNonNull($of(compactPatterns), "compactPatterns"_s);
	$Objects::requireNonNull($of(pluralRules), "pluralRules"_s);
	$set(this, symbols, symbols);
	$set(this, decimalFormat, $new($DecimalFormat, CompactNumberFormat::SPECIAL_PATTERN, this->symbols));
	setMaximumIntegerDigits($nc(this->decimalFormat)->getMaximumIntegerDigits());
	setMinimumIntegerDigits($nc(this->decimalFormat)->getMinimumIntegerDigits());
	setMaximumFractionDigits($nc(this->decimalFormat)->getMaximumFractionDigits());
	setMinimumFractionDigits($nc(this->decimalFormat)->getMinimumFractionDigits());
	$NumberFormat::setGroupingUsed($nc(this->decimalFormat)->isGroupingUsed());
	$NumberFormat::setParseIntegerOnly($nc(this->decimalFormat)->isParseIntegerOnly());
	$set(this, compactPatterns, compactPatterns);
	$set(this, decimalPattern, decimalPattern);
	$set(this, defaultDecimalFormat, $new($DecimalFormat, this->decimalPattern, this->symbols));
	$nc(this->defaultDecimalFormat)->setMaximumFractionDigits(0);
	$set(this, pluralRules, pluralRules);
	processCompactPatterns();
}

$StringBuffer* CompactNumberFormat::format(Object$* number, $StringBuffer* toAppendTo, $FieldPosition* fieldPosition) {
	$useLocalCurrentObjectStackCache();
	if (number == nullptr) {
		$throwNew($IllegalArgumentException, "Cannot format null as a number"_s);
	}
	if ($instanceOf($Long, number) || $instanceOf($Integer, number) || $instanceOf($Short, number) || $instanceOf($Byte, number) || $instanceOf($AtomicInteger, number) || $instanceOf($AtomicLong, number) || ($instanceOf($BigInteger, number) && $nc(($cast($BigInteger, number)))->bitLength() < 64)) {
		return format($nc(($cast($Number, number)))->longValue(), toAppendTo, fieldPosition);
	} else if ($instanceOf($BigDecimal, number)) {
		return format($cast($BigDecimal, number), toAppendTo, fieldPosition);
	} else if ($instanceOf($BigInteger, number)) {
		return format($cast($BigInteger, number), toAppendTo, fieldPosition);
	} else if ($instanceOf($Number, number)) {
		return format($nc(($cast($Number, number)))->doubleValue(), toAppendTo, fieldPosition);
	} else {
		$throwNew($IllegalArgumentException, $$str({"Cannot format "_s, $($nc($of(number))->getClass()->getName()), " as a number"_s}));
	}
}

$StringBuffer* CompactNumberFormat::format(double number, $StringBuffer* result, $FieldPosition* fieldPosition) {
	$nc(fieldPosition)->setBeginIndex(0);
	fieldPosition->setEndIndex(0);
	return format(number, result, $(fieldPosition->getFieldDelegate()));
}

$StringBuffer* CompactNumberFormat::format(double number, $StringBuffer* result, $Format$FieldDelegate* delegate) {
	$useLocalCurrentObjectStackCache();
	bool nanOrInfinity = $nc(this->decimalFormat)->handleNaN(number, result, delegate);
	if (nanOrInfinity) {
		return result;
	}
	bool isNegative = ((number < 0.0) || (number == 0.0 && 1 / number < 0.0));
	nanOrInfinity = $nc(this->decimalFormat)->handleInfinity(number, result, delegate, isNegative);
	if (nanOrInfinity) {
		return result;
	}
	$var($DigitList, dList, $new($DigitList));
	dList->setRoundingMode($(getRoundingMode()));
	number = isNegative ? -number : number;
	dList->set(isNegative, number, getMinimumFractionDigits());
	double roundedNumber = dList->getDouble();
	int32_t compactDataIndex = selectCompactPattern($cast(int64_t, roundedNumber));
	if (compactDataIndex != -1) {
		int64_t divisor = $nc(($cast($Long, $($nc(this->divisors)->get(compactDataIndex)))))->longValue();
		int32_t iPart = getIntegerPart(number, (double)divisor);
		$var($String, prefix, getAffix(false, true, isNegative, compactDataIndex, iPart));
		$var($String, suffix, getAffix(false, false, isNegative, compactDataIndex, iPart));
		bool var$0 = !$nc(prefix)->isEmpty();
		if (var$0 || !$nc(suffix)->isEmpty()) {
			appendPrefix(result, prefix, delegate);
			if (!$nc($($nc(($cast($CompactNumberFormat$Patterns, $($nc(this->placeHolderPatterns)->get(compactDataIndex)))))->get((double)iPart)))->isEmpty()) {
				roundedNumber = roundedNumber / divisor;
				$var($Number, var$1, static_cast<$Number*>($Double::valueOf(roundedNumber)));
				bool var$2 = isNegative;
				$nc(this->decimalFormat)->setDigitList(var$1, var$2, getMaximumFractionDigits());
				$var($StringBuffer, var$3, result);
				$var($Format$FieldDelegate, var$4, delegate);
				bool var$5 = isNegative;
				int32_t var$6 = getMaximumIntegerDigits();
				int32_t var$7 = getMinimumIntegerDigits();
				int32_t var$8 = getMaximumFractionDigits();
				$nc(this->decimalFormat)->subformatNumber(var$3, var$4, var$5, false, var$6, var$7, var$8, getMinimumFractionDigits());
				appendSuffix(result, suffix, delegate);
			}
		} else {
			$nc(this->defaultDecimalFormat)->doubleSubformat(number, result, delegate, isNegative);
		}
	} else {
		$nc(this->defaultDecimalFormat)->doubleSubformat(number, result, delegate, isNegative);
	}
	return result;
}

$StringBuffer* CompactNumberFormat::format(int64_t number, $StringBuffer* result, $FieldPosition* fieldPosition) {
	$nc(fieldPosition)->setBeginIndex(0);
	fieldPosition->setEndIndex(0);
	return format(number, result, $(fieldPosition->getFieldDelegate()));
}

$StringBuffer* CompactNumberFormat::format(int64_t number, $StringBuffer* result, $Format$FieldDelegate* delegate) {
	$useLocalCurrentObjectStackCache();
	bool isNegative = (number < 0);
	if (isNegative) {
		number = -number;
	}
	if (number < 0) {
		$var($BigInteger, bigIntegerValue, $BigInteger::valueOf(number));
		return format(bigIntegerValue, result, delegate, true);
	}
	int32_t compactDataIndex = selectCompactPattern(number);
	if (compactDataIndex != -1) {
		int64_t divisor = $nc(($cast($Long, $($nc(this->divisors)->get(compactDataIndex)))))->longValue();
		int32_t iPart = getIntegerPart((double)number, (double)divisor);
		$var($String, prefix, getAffix(false, true, isNegative, compactDataIndex, iPart));
		$var($String, suffix, getAffix(false, false, isNegative, compactDataIndex, iPart));
		bool var$0 = !$nc(prefix)->isEmpty();
		if (var$0 || !$nc(suffix)->isEmpty()) {
			appendPrefix(result, prefix, delegate);
			if (!$nc($($nc(($cast($CompactNumberFormat$Patterns, $($nc(this->placeHolderPatterns)->get(compactDataIndex)))))->get((double)iPart)))->isEmpty()) {
				if ($mod(number, divisor) == 0) {
					number = $div(number, divisor);
					$nc(this->decimalFormat)->setDigitList($($Long::valueOf(number)), isNegative, 0);
					$var($StringBuffer, var$1, result);
					$var($Format$FieldDelegate, var$2, delegate);
					bool var$3 = isNegative;
					int32_t var$4 = getMaximumIntegerDigits();
					int32_t var$5 = getMinimumIntegerDigits();
					int32_t var$6 = getMaximumFractionDigits();
					$nc(this->decimalFormat)->subformatNumber(var$1, var$2, var$3, true, var$4, var$5, var$6, getMinimumFractionDigits());
				} else {
					double dNumber = (double)number / divisor;
					$var($Number, var$7, static_cast<$Number*>($Double::valueOf(dNumber)));
					bool var$8 = isNegative;
					$nc(this->decimalFormat)->setDigitList(var$7, var$8, getMaximumFractionDigits());
					$var($StringBuffer, var$9, result);
					$var($Format$FieldDelegate, var$10, delegate);
					bool var$11 = isNegative;
					int32_t var$12 = getMaximumIntegerDigits();
					int32_t var$13 = getMinimumIntegerDigits();
					int32_t var$14 = getMaximumFractionDigits();
					$nc(this->decimalFormat)->subformatNumber(var$9, var$10, var$11, false, var$12, var$13, var$14, getMinimumFractionDigits());
				}
				appendSuffix(result, suffix, delegate);
			}
		} else {
			number = isNegative ? -number : number;
			$nc(this->defaultDecimalFormat)->format(number, result, delegate);
		}
	} else {
		number = isNegative ? -number : number;
		$nc(this->defaultDecimalFormat)->format(number, result, delegate);
	}
	return result;
}

$StringBuffer* CompactNumberFormat::format($BigDecimal* number, $StringBuffer* result, $FieldPosition* fieldPosition) {
	$Objects::requireNonNull(number);
	$nc(fieldPosition)->setBeginIndex(0);
	fieldPosition->setEndIndex(0);
	return format(number, result, $(fieldPosition->getFieldDelegate()));
}

$StringBuffer* CompactNumberFormat::format($BigDecimal* number$renamed, $StringBuffer* result, $Format$FieldDelegate* delegate) {
	$useLocalCurrentObjectStackCache();
	$var($BigDecimal, number, number$renamed);
	bool isNegative = $nc(number)->signum() == -1;
	if (isNegative) {
		$assign(number, number->negate());
	}
	int32_t var$0 = getMinimumFractionDigits();
	$assign(number, number->setScale(var$0, $(getRoundingMode())));
	int32_t compactDataIndex = 0;
	if ($nc($(number->toBigInteger()))->bitLength() < 64) {
		int64_t longNumber = $nc($(number->toBigInteger()))->longValue();
		compactDataIndex = selectCompactPattern(longNumber);
	} else {
		compactDataIndex = selectCompactPattern($(number->toBigInteger()));
	}
	if (compactDataIndex != -1) {
		$var($Number, divisor, $cast($Number, $nc(this->divisors)->get(compactDataIndex)));
		double var$1 = number->doubleValue();
		int32_t iPart = getIntegerPart(var$1, $nc(divisor)->doubleValue());
		$var($String, prefix, getAffix(false, true, isNegative, compactDataIndex, iPart));
		$var($String, suffix, getAffix(false, false, isNegative, compactDataIndex, iPart));
		bool var$2 = !$nc(prefix)->isEmpty();
		if (var$2 || !$nc(suffix)->isEmpty()) {
			appendPrefix(result, prefix, delegate);
			if (!$nc($($nc(($cast($CompactNumberFormat$Patterns, $($nc(this->placeHolderPatterns)->get(compactDataIndex)))))->get((double)iPart)))->isEmpty()) {
				$var($BigDecimal, var$3, $new($BigDecimal, $($nc($of(divisor))->toString())));
				$assign(number, number->divide(var$3, $(getRoundingMode())));
				$nc(this->decimalFormat)->setDigitList(number, isNegative, getMaximumFractionDigits());
				$var($StringBuffer, var$4, result);
				$var($Format$FieldDelegate, var$5, delegate);
				bool var$6 = isNegative;
				int32_t var$7 = getMaximumIntegerDigits();
				int32_t var$8 = getMinimumIntegerDigits();
				int32_t var$9 = getMaximumFractionDigits();
				$nc(this->decimalFormat)->subformatNumber(var$4, var$5, var$6, false, var$7, var$8, var$9, getMinimumFractionDigits());
				appendSuffix(result, suffix, delegate);
			}
		} else {
			$assign(number, isNegative ? number->negate() : number);
			$nc(this->defaultDecimalFormat)->format(number, result, delegate);
		}
	} else {
		$assign(number, isNegative ? number->negate() : number);
		$nc(this->defaultDecimalFormat)->format(number, result, delegate);
	}
	return result;
}

$StringBuffer* CompactNumberFormat::format($BigInteger* number, $StringBuffer* result, $FieldPosition* fieldPosition) {
	$Objects::requireNonNull(number);
	$nc(fieldPosition)->setBeginIndex(0);
	fieldPosition->setEndIndex(0);
	return format(number, result, $(fieldPosition->getFieldDelegate()), false);
}

$StringBuffer* CompactNumberFormat::format($BigInteger* number$renamed, $StringBuffer* result, $Format$FieldDelegate* delegate, bool formatLong) {
	$useLocalCurrentObjectStackCache();
	$var($BigInteger, number, number$renamed);
	bool isNegative = $nc(number)->signum() == -1;
	if (isNegative) {
		$assign(number, number->negate());
	}
	int32_t compactDataIndex = selectCompactPattern(number);
	if (compactDataIndex != -1) {
		$var($Number, divisor, $cast($Number, $nc(this->divisors)->get(compactDataIndex)));
		double var$0 = number->doubleValue();
		int32_t iPart = getIntegerPart(var$0, $nc(divisor)->doubleValue());
		$var($String, prefix, getAffix(false, true, isNegative, compactDataIndex, iPart));
		$var($String, suffix, getAffix(false, false, isNegative, compactDataIndex, iPart));
		bool var$1 = !$nc(prefix)->isEmpty();
		if (var$1 || !$nc(suffix)->isEmpty()) {
			appendPrefix(result, prefix, delegate);
			if (!$nc($($nc(($cast($CompactNumberFormat$Patterns, $($nc(this->placeHolderPatterns)->get(compactDataIndex)))))->get((double)iPart)))->isEmpty()) {
				if ($nc($(number->mod($$new($BigInteger, $($nc($of(divisor))->toString())))))->compareTo($BigInteger::ZERO) == 0) {
					$assign(number, number->divide($$new($BigInteger, $($nc($of(divisor))->toString()))));
					$nc(this->decimalFormat)->setDigitList(number, isNegative, 0);
					$var($StringBuffer, var$2, result);
					$var($Format$FieldDelegate, var$3, delegate);
					bool var$4 = isNegative;
					int32_t var$5 = getMaximumIntegerDigits();
					int32_t var$6 = getMinimumIntegerDigits();
					int32_t var$7 = getMaximumFractionDigits();
					$nc(this->decimalFormat)->subformatNumber(var$2, var$3, var$4, true, var$5, var$6, var$7, getMinimumFractionDigits());
				} else {
					$var($BigDecimal, var$8, $new($BigDecimal, $($nc($of(divisor))->toString())));
					$var($BigDecimal, nDecimal, $$new($BigDecimal, number)->divide(var$8, $(getRoundingMode())));
					$nc(this->decimalFormat)->setDigitList(nDecimal, isNegative, getMaximumFractionDigits());
					$var($StringBuffer, var$9, result);
					$var($Format$FieldDelegate, var$10, delegate);
					bool var$11 = isNegative;
					int32_t var$12 = getMaximumIntegerDigits();
					int32_t var$13 = getMinimumIntegerDigits();
					int32_t var$14 = getMaximumFractionDigits();
					$nc(this->decimalFormat)->subformatNumber(var$9, var$10, var$11, false, var$12, var$13, var$14, getMinimumFractionDigits());
				}
				appendSuffix(result, suffix, delegate);
			}
		} else {
			$assign(number, isNegative ? number->negate() : number);
			$nc(this->defaultDecimalFormat)->format(number, result, delegate, formatLong);
		}
	} else {
		$assign(number, isNegative ? number->negate() : number);
		$nc(this->defaultDecimalFormat)->format(number, result, delegate, formatLong);
	}
	return result;
}

$String* CompactNumberFormat::getAffix(bool isExpanded, bool isPrefix, bool isNegative, int32_t compactDataIndex, int32_t iPart) {
	return $nc(($cast($CompactNumberFormat$Patterns, $($nc((isExpanded ? (isPrefix ? (isNegative ? this->negativePrefixes : this->positivePrefixes) : (isNegative ? this->negativeSuffixes : this->positiveSuffixes)) : (isPrefix ? (isNegative ? this->negativePrefixPatterns : this->positivePrefixPatterns) : (isNegative ? this->negativeSuffixPatterns : this->positiveSuffixPatterns))))->get(compactDataIndex)))))->get((double)iPart);
}

void CompactNumberFormat::appendPrefix($StringBuffer* result, $String* prefix, $Format$FieldDelegate* delegate) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuffer, var$0, result);
	$var($String, var$1, expandAffix(prefix));
	$var($Format$FieldDelegate, var$2, delegate);
	$init($NumberFormat$Field);
	append(var$0, var$1, var$2, $(getFieldPositions(prefix, $NumberFormat$Field::PREFIX)));
}

void CompactNumberFormat::appendSuffix($StringBuffer* result, $String* suffix, $Format$FieldDelegate* delegate) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuffer, var$0, result);
	$var($String, var$1, expandAffix(suffix));
	$var($Format$FieldDelegate, var$2, delegate);
	$init($NumberFormat$Field);
	append(var$0, var$1, var$2, $(getFieldPositions(suffix, $NumberFormat$Field::SUFFIX)));
}

void CompactNumberFormat::append($StringBuffer* result, $String* string, $Format$FieldDelegate* delegate, $List* positions) {
	$useLocalCurrentObjectStackCache();
	if (!$nc(string)->isEmpty()) {
		int32_t start = $nc(result)->length();
		result->append(string);
		{
			$var($Iterator, i$, $nc(positions)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($FieldPosition, fp, $cast($FieldPosition, i$->next()));
				{
					$var($Format$Field, attribute, $nc(fp)->getFieldAttribute());
					$var($Format$Field, var$0, attribute);
					$var($Object, var$1, $of(attribute));
					int32_t var$2 = start + fp->getBeginIndex();
					$nc(delegate)->formatted(var$0, var$1, var$2, start + fp->getEndIndex(), result);
				}
			}
		}
	}
}

$String* CompactNumberFormat::expandAffix($String* pattern) {
	$useLocalCurrentObjectStackCache();
	if ($nc(pattern)->indexOf((int32_t)CompactNumberFormat::QUOTE) < 0) {
		return pattern;
	}
	$var($StringBuilder, sb, $new($StringBuilder));
	for (int32_t index = 0; index < $nc(pattern)->length();) {
		char16_t ch = pattern->charAt(index++);
		if (ch == CompactNumberFormat::QUOTE) {
			ch = pattern->charAt(index++);
			if (ch == CompactNumberFormat::MINUS_SIGN) {
				sb->append($($nc(this->symbols)->getMinusSignText()));
				continue;
			}
		}
		sb->append(ch);
	}
	return sb->toString();
}

$List* CompactNumberFormat::getFieldPositions($String* pattern, $NumberFormat$Field* field) {
	$useLocalCurrentObjectStackCache();
	$var($List, positions, $new($ArrayList));
	$var($StringBuilder, affix, $new($StringBuilder));
	int32_t stringIndex = 0;
	for (int32_t index = 0; index < $nc(pattern)->length();) {
		char16_t ch = pattern->charAt(index++);
		if (ch == CompactNumberFormat::QUOTE) {
			ch = pattern->charAt(index++);
			if (ch == CompactNumberFormat::MINUS_SIGN) {
				$var($String, minusText, $nc(this->symbols)->getMinusSignText());
				$init($NumberFormat$Field);
				$var($FieldPosition, fp, $new($FieldPosition, static_cast<$Format$Field*>($NumberFormat$Field::SIGN)));
				fp->setBeginIndex(stringIndex);
				fp->setEndIndex(stringIndex + $nc(minusText)->length());
				positions->add(fp);
				stringIndex += $nc(minusText)->length();
				affix->append(minusText);
				continue;
			}
		}
		++stringIndex;
		affix->append(ch);
	}
	if (affix->length() != 0) {
		$var($FieldPosition, fp, $new($FieldPosition, static_cast<$Format$Field*>(field)));
		fp->setBeginIndex(0);
		fp->setEndIndex(affix->length());
		positions->add(fp);
	}
	return positions;
}

int32_t CompactNumberFormat::selectCompactPattern(int64_t number) {
	if ($nc(this->compactPatterns)->length == 0) {
		return -1;
	}
	int32_t dataIndex = number <= 1 ? 0 : $cast(int32_t, $Math::log10((double)number));
	dataIndex = $Math::min(dataIndex, $nc(this->compactPatterns)->length - 1);
	return dataIndex;
}

int32_t CompactNumberFormat::selectCompactPattern($BigInteger* number) {
	$useLocalCurrentObjectStackCache();
	int32_t matchedIndex = -1;
	if ($nc(this->compactPatterns)->length == 0) {
		return matchedIndex;
	}
	$init($BigInteger);
	$var($BigInteger, currentValue, $BigInteger::ONE);
	for (int32_t index = 0; index < $nc(this->compactPatterns)->length; ++index) {
		if ($nc(number)->compareTo(currentValue) > 0) {
			matchedIndex = index;
			$assign(currentValue, $nc(currentValue)->multiply($($BigInteger::valueOf((int64_t)CompactNumberFormat::RANGE_MULTIPLIER))));
			continue;
		}
		if ($nc(number)->compareTo(currentValue) < 0) {
			break;
		} else {
			matchedIndex = index;
			break;
		}
	}
	return matchedIndex;
}

$AttributedCharacterIterator* CompactNumberFormat::formatToCharacterIterator(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	$var($CharacterIteratorFieldDelegate, delegate, $new($CharacterIteratorFieldDelegate));
	$var($StringBuffer, sb, $new($StringBuffer));
	if ($instanceOf($Double, obj) || $instanceOf($Float, obj)) {
		format($nc(($cast($Number, obj)))->doubleValue(), sb, static_cast<$Format$FieldDelegate*>(delegate));
	} else if ($instanceOf($Long, obj) || $instanceOf($Integer, obj) || $instanceOf($Short, obj) || $instanceOf($Byte, obj) || $instanceOf($AtomicInteger, obj) || $instanceOf($AtomicLong, obj)) {
		format($nc(($cast($Number, obj)))->longValue(), sb, static_cast<$Format$FieldDelegate*>(delegate));
	} else if ($instanceOf($BigDecimal, obj)) {
		format($cast($BigDecimal, obj), sb, static_cast<$Format$FieldDelegate*>(delegate));
	} else if ($instanceOf($BigInteger, obj)) {
		format($cast($BigInteger, obj), sb, delegate, false);
	} else if (obj == nullptr) {
		$throwNew($NullPointerException, "formatToCharacterIterator must be passed non-null object"_s);
	} else {
		$throwNew($IllegalArgumentException, "Cannot format given Object as a Number"_s);
	}
	return delegate->getIterator($(sb->toString()));
}

$Number* CompactNumberFormat::computeDivisor($String* minIntDigits, int32_t patternIndex) {
	$useLocalCurrentObjectStackCache();
	int32_t count = $nc(minIntDigits)->length();
	$var($Number, matchedValue, nullptr);
	if (patternIndex < 19) {
		$assign(matchedValue, $Long::valueOf($cast(int64_t, $Math::pow((double)CompactNumberFormat::RANGE_MULTIPLIER, (double)patternIndex))));
	} else {
		$assign(matchedValue, $nc($($BigInteger::valueOf((int64_t)CompactNumberFormat::RANGE_MULTIPLIER)))->pow(patternIndex));
	}
	$var($Number, divisor, matchedValue);
	if (count > 0) {
		{
			$var($BigInteger, bigValue, nullptr);
			bool var$0 = $instanceOf($BigInteger, matchedValue);
			if (var$0) {
				$assign(bigValue, $cast($BigInteger, matchedValue));
				var$0 = true;
			}
			if (var$0) {
				if ($nc(bigValue)->compareTo($($BigInteger::valueOf($cast(int64_t, $Math::pow((double)CompactNumberFormat::RANGE_MULTIPLIER, (double)(count - 1)))))) < 0) {
					$throwNew($IllegalArgumentException, $$str({"Invalid Pattern ["_s, $nc(this->compactPatterns)->get(patternIndex), "]: min integer digits specified exceeds the limit for the index "_s, $$str(patternIndex)}));
				}
				$assign(divisor, $nc(bigValue)->divide($($BigInteger::valueOf($cast(int64_t, $Math::pow((double)CompactNumberFormat::RANGE_MULTIPLIER, (double)(count - 1)))))));
			} else {
				int64_t longValue = $nc(($cast($Long, matchedValue)))->longValue();
				if (longValue < $cast(int64_t, $Math::pow((double)CompactNumberFormat::RANGE_MULTIPLIER, (double)(count - 1)))) {
					$throwNew($IllegalArgumentException, $$str({"Invalid Pattern ["_s, $nc(this->compactPatterns)->get(patternIndex), "]: min integer digits specified exceeds the limit for the index "_s, $$str(patternIndex)}));
				}
				$assign(divisor, $Long::valueOf($div(longValue, $cast(int64_t, $Math::pow((double)CompactNumberFormat::RANGE_MULTIPLIER, (double)(count - 1))))));
			}
		}
	}
	return divisor;
}

void CompactNumberFormat::processCompactPatterns() {
	$useLocalCurrentObjectStackCache();
	int32_t size = $nc(this->compactPatterns)->length;
	$set(this, positivePrefixPatterns, $new($ArrayList, size));
	$set(this, negativePrefixPatterns, $new($ArrayList, size));
	$set(this, positiveSuffixPatterns, $new($ArrayList, size));
	$set(this, negativeSuffixPatterns, $new($ArrayList, size));
	$set(this, divisors, $new($ArrayList, size));
	$set(this, placeHolderPatterns, $new($ArrayList, size));
	for (int32_t index = 0; index < size; ++index) {
		$var($String, text, $nc(this->compactPatterns)->get(index));
		$nc(this->positivePrefixPatterns)->add($$new($CompactNumberFormat$Patterns, this));
		$nc(this->negativePrefixPatterns)->add($$new($CompactNumberFormat$Patterns, this));
		$nc(this->positiveSuffixPatterns)->add($$new($CompactNumberFormat$Patterns, this));
		$nc(this->negativeSuffixPatterns)->add($$new($CompactNumberFormat$Patterns, this));
		$nc(this->placeHolderPatterns)->add($$new($CompactNumberFormat$Patterns, this));
		$var($Matcher, m, text != nullptr ? $nc(CompactNumberFormat::PLURALS)->matcher(text) : ($Matcher*)nullptr);
		if (m != nullptr && m->matches()) {
			int32_t idx = index;
			$var($String, plurals, m->group("plurals"_s));
			$nc($($nc($($nc(CompactNumberFormat::COUNT_PATTERN)->matcher(plurals)))->results()))->forEach(static_cast<$Consumer*>($$new(CompactNumberFormat$$Lambda$lambda$processCompactPatterns$0, this, idx)));
		} else {
			applyPattern("other"_s, text, index);
		}
	}
	$set(this, rulesMap, buildPluralRulesMap());
}

$Map* CompactNumberFormat::buildPluralRulesMap() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->pluralRules)->length() > 2048) {
		$throwNew($IllegalArgumentException, "plural rules is too long (> 2,048)"_s);
	}
	try {
		$var($Function, var$0, static_cast<$Function*>($new(CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$1$2)));
		return $cast($Map, $nc($($nc($($Arrays::stream($($nc(this->pluralRules)->split(";"_s)))))->map(static_cast<$Function*>($$new(CompactNumberFormat$$Lambda$validateRule$1, this)))))->collect($($Collectors::toMap(var$0, static_cast<$Function*>($$new(CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$2$3))))));
	} catch ($IllegalStateException& ise) {
		$throwNew($IllegalArgumentException, static_cast<$Throwable*>(ise));
	}
	$shouldNotReachHere();
}

$String* CompactNumberFormat::validateRule($String* rule$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, rule, rule$renamed);
	$assign(rule, $nc(rule)->trim());
	bool var$0 = !rule->isEmpty();
	if (var$0 && !rule->equals("other:"_s)) {
		$var($Matcher, validator, $nc(CompactNumberFormat::PLURALRULES_PATTERN)->matcher(rule));
		if (!$nc(validator)->matches()) {
			$throwNew($IllegalArgumentException, $$str({"Invalid plural rules syntax: "_s, rule}));
		}
	}
	return rule;
}

void CompactNumberFormat::applyPattern($String* count, $String* pattern, int32_t index) {
	$useLocalCurrentObjectStackCache();
	if (pattern == nullptr) {
		$throwNew($IllegalArgumentException, $$str({"A null compact pattern encountered at index: "_s, $$str(index)}));
	}
	int32_t start = 0;
	bool gotNegative = false;
	$var($String, positivePrefix, ""_s);
	$var($String, positiveSuffix, ""_s);
	$var($String, negativePrefix, ""_s);
	$var($String, negativeSuffix, ""_s);
	$var($String, zeros, ""_s);
	for (int32_t j = 1; j >= 0 && start < $nc(pattern)->length(); --j) {
		$var($StringBuffer, prefix, $new($StringBuffer));
		$var($StringBuffer, suffix, $new($StringBuffer));
		bool inQuote = false;
		int32_t phase = 0;
		$var($StringBuffer, affix, prefix);
		for (int32_t pos = start; pos < pattern->length(); ++pos) {
			char16_t ch = pattern->charAt(pos);
			switch (phase) {
			case 0:
				{}
			case 2:
				{
					if (inQuote) {
						if (ch == CompactNumberFormat::QUOTE) {
							bool var$0 = (pos + 1) < pattern->length();
							if (var$0 && pattern->charAt(pos + 1) == CompactNumberFormat::QUOTE) {
								++pos;
								affix->append("\'\'"_s);
							} else {
								inQuote = false;
							}
							continue;
						}
					} else {
						switch (ch) {
						case CompactNumberFormat::ZERO_DIGIT:
							{
								phase = 1;
								--pos;
								continue;
							}
						case CompactNumberFormat::QUOTE:
							{
								bool var$1 = (pos + 1) < pattern->length();
								if (var$1 && pattern->charAt(pos + 1) == CompactNumberFormat::QUOTE) {
									++pos;
									affix->append("\'\'"_s);
								} else {
									inQuote = true;
								}
								continue;
							}
						case CompactNumberFormat::SEPARATOR:
							{
								if (phase == 0 || j == 0) {
									$throwNew($IllegalArgumentException, $$str({"Unquoted special character \'"_s, $$str(ch), "\' in pattern \""_s, pattern, "\""_s}));
								}
								start = pos + 1;
								pos = pattern->length();
								continue;
							}
						case CompactNumberFormat::MINUS_SIGN:
							{
								affix->append("\'-"_s);
								continue;
							}
						case CompactNumberFormat::DECIMAL_SEPARATOR:
							{}
						case CompactNumberFormat::GROUPING_SEPARATOR:
							{}
						case CompactNumberFormat::DIGIT:
							{}
						case CompactNumberFormat::PERCENT:
							{}
						case CompactNumberFormat::PER_MILLE:
							{}
						case CompactNumberFormat::CURRENCY_SIGN:
							{
								$throwNew($IllegalArgumentException, $$str({"Unquoted special character \'"_s, $$str(ch), "\' in pattern \""_s, pattern, "\""_s}));
							}
						default:
							{
								break;
							}
						}
					}
					affix->append(ch);
					break;
				}
			case 1:
				{
					if (j == 0) {
						while (pos < pattern->length()) {
							char16_t negPatternChar = pattern->charAt(pos);
							if (negPatternChar == CompactNumberFormat::ZERO_DIGIT) {
								++pos;
							} else {
								--pos;
								phase = 2;
								$assign(affix, suffix);
								break;
							}
						}
						continue;
					}
					if (ch == CompactNumberFormat::ZERO_DIGIT) {
						$assign(zeros, $str({zeros, "0"_s}));
					} else {
						phase = 2;
						$assign(affix, suffix);
						--pos;
					}
					break;
				}
			}
		}
		if (inQuote) {
			$throwNew($IllegalArgumentException, $$str({"Invalid single quote in pattern \""_s, pattern, "\""_s}));
		}
		if (j == 1) {
			$assign(positivePrefix, prefix->toString());
			$assign(positiveSuffix, suffix->toString());
			$assign(negativePrefix, positivePrefix);
			$assign(negativeSuffix, positiveSuffix);
		} else {
			$assign(negativePrefix, prefix->toString());
			$assign(negativeSuffix, suffix->toString());
			gotNegative = true;
		}
		bool var$2 = !gotNegative;
		if (!var$2) {
			bool var$3 = $nc(negativePrefix)->equals(positivePrefix);
			var$2 = (var$3 && $nc(negativeSuffix)->equals(positiveSuffix));
		}
		if (var$2) {
			$assign(negativeSuffix, positiveSuffix);
			$assign(negativePrefix, $str({"\'-"_s, positivePrefix}));
		}
	}
	bool var$4 = !$nc(positivePrefix)->isEmpty();
	if (var$4 || !$nc(positiveSuffix)->isEmpty()) {
		$nc(($cast($CompactNumberFormat$Patterns, $($nc(this->positivePrefixPatterns)->get(index)))))->put(count, positivePrefix);
		$nc(($cast($CompactNumberFormat$Patterns, $($nc(this->negativePrefixPatterns)->get(index)))))->put(count, negativePrefix);
		$nc(($cast($CompactNumberFormat$Patterns, $($nc(this->positiveSuffixPatterns)->get(index)))))->put(count, positiveSuffix);
		$nc(($cast($CompactNumberFormat$Patterns, $($nc(this->negativeSuffixPatterns)->get(index)))))->put(count, negativeSuffix);
		$nc(($cast($CompactNumberFormat$Patterns, $($nc(this->placeHolderPatterns)->get(index)))))->put(count, zeros);
		if ($nc(this->divisors)->size() <= index) {
			$nc(this->divisors)->add($(computeDivisor(zeros, index)));
		}
	} else {
		$nc(($cast($CompactNumberFormat$Patterns, $($nc(this->positivePrefixPatterns)->get(index)))))->put(count, ""_s);
		$nc(($cast($CompactNumberFormat$Patterns, $($nc(this->negativePrefixPatterns)->get(index)))))->put(count, ""_s);
		$nc(($cast($CompactNumberFormat$Patterns, $($nc(this->positiveSuffixPatterns)->get(index)))))->put(count, ""_s);
		$nc(($cast($CompactNumberFormat$Patterns, $($nc(this->negativeSuffixPatterns)->get(index)))))->put(count, ""_s);
		$nc(($cast($CompactNumberFormat$Patterns, $($nc(this->placeHolderPatterns)->get(index)))))->put(count, ""_s);
		if ($nc(this->divisors)->size() <= index) {
			$nc(this->divisors)->add($($Long::valueOf((int64_t)1)));
		}
	}
}

void CompactNumberFormat::expandAffixPatterns() {
	$useLocalCurrentObjectStackCache();
	$set(this, positivePrefixes, $new($ArrayList, $nc(this->compactPatterns)->length));
	$set(this, negativePrefixes, $new($ArrayList, $nc(this->compactPatterns)->length));
	$set(this, positiveSuffixes, $new($ArrayList, $nc(this->compactPatterns)->length));
	$set(this, negativeSuffixes, $new($ArrayList, $nc(this->compactPatterns)->length));
	for (int32_t index = 0; index < $nc(this->compactPatterns)->length; ++index) {
		$nc(this->positivePrefixes)->add($($nc(($cast($CompactNumberFormat$Patterns, $($nc(this->positivePrefixPatterns)->get(index)))))->expandAffix()));
		$nc(this->negativePrefixes)->add($($nc(($cast($CompactNumberFormat$Patterns, $($nc(this->negativePrefixPatterns)->get(index)))))->expandAffix()));
		$nc(this->positiveSuffixes)->add($($nc(($cast($CompactNumberFormat$Patterns, $($nc(this->positiveSuffixPatterns)->get(index)))))->expandAffix()));
		$nc(this->negativeSuffixes)->add($($nc(($cast($CompactNumberFormat$Patterns, $($nc(this->negativeSuffixPatterns)->get(index)))))->expandAffix()));
	}
}

$Number* CompactNumberFormat::parse($String* text, $ParsePosition* pos) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(text);
	$Objects::requireNonNull(pos);
	if (this->positivePrefixes == nullptr) {
		expandAffixPatterns();
	}
	$var($Number, cnfMultiplier, $Long::valueOf((int64_t)1));
	int32_t var$0 = pos->index;
	$var($String, var$1, $nc(this->symbols)->getNaN());
	if (text->regionMatches(var$0, var$1, 0, $nc($($nc(this->symbols)->getNaN()))->length())) {
		pos->index = pos->index + $nc($($nc(this->symbols)->getNaN()))->length();
		$init($Double);
		return $Double::valueOf($Double::NaN);
	}
	int32_t position = pos->index;
	int32_t oldStart = pos->index;
	bool gotPositive = false;
	bool gotNegative = false;
	int32_t matchedPosIndex = -1;
	int32_t matchedNegIndex = -1;
	$var($String, matchedPosPrefix, ""_s);
	$var($String, matchedNegPrefix, ""_s);
	$var($String, defaultPosPrefix, $nc(this->defaultDecimalFormat)->getPositivePrefix());
	$var($String, defaultNegPrefix, $nc(this->defaultDecimalFormat)->getNegativePrefix());
	double num = parseNumberPart(text, position);
	for (int32_t compactIndex = 0; compactIndex < $nc(this->compactPatterns)->length; ++compactIndex) {
		$var($String, positivePrefix, getAffix(true, true, false, compactIndex, $cast(int32_t, num)));
		$var($String, negativePrefix, getAffix(true, true, true, compactIndex, $cast(int32_t, num)));
		bool match = matchAffix(text, position, positivePrefix, defaultPosPrefix, matchedPosPrefix);
		if (match) {
			matchedPosIndex = compactIndex;
			$assign(matchedPosPrefix, positivePrefix);
			gotPositive = true;
		}
		match = matchAffix(text, position, negativePrefix, defaultNegPrefix, matchedNegPrefix);
		if (match) {
			matchedNegIndex = compactIndex;
			$assign(matchedNegPrefix, negativePrefix);
			gotNegative = true;
		}
	}
	if (!gotPositive && !gotNegative) {
		if (text->regionMatches(pos->index, defaultPosPrefix, 0, $nc(defaultPosPrefix)->length())) {
			$assign(matchedPosPrefix, defaultPosPrefix);
			gotPositive = true;
		}
		if (text->regionMatches(pos->index, defaultNegPrefix, 0, $nc(defaultNegPrefix)->length())) {
			$assign(matchedNegPrefix, defaultNegPrefix);
			gotNegative = true;
		}
	}
	if (gotPositive && gotNegative) {
		int32_t var$2 = $nc(matchedPosPrefix)->length();
		if (var$2 > $nc(matchedNegPrefix)->length()) {
			gotNegative = false;
		} else {
			int32_t var$4 = matchedPosPrefix->length();
			if (var$4 < matchedNegPrefix->length()) {
				gotPositive = false;
			}
		}
	}
	if (gotPositive || gotNegative) {
		position += gotPositive ? $nc(matchedPosPrefix)->length() : $nc(matchedNegPrefix)->length();
		int32_t matchedIndex = gotPositive ? matchedPosIndex : matchedNegIndex;
		if (matchedIndex != -1) {
			$assign(cnfMultiplier, $cast($Number, $nc(this->divisors)->get(matchedIndex)));
			if ($nc($($nc(($cast($CompactNumberFormat$Patterns, $($nc(this->placeHolderPatterns)->get(matchedIndex)))))->get(num)))->isEmpty()) {
				pos->index = position;
				return cnfMultiplier;
			}
		}
	}
	$nc(this->digitList)->setRoundingMode($(getRoundingMode()));
	$var($booleans, status, $new($booleans, CompactNumberFormat::STATUS_LENGTH));
	position = $nc(this->decimalFormat)->subparseNumber(text, position, this->digitList, false, false, status);
	if (position == -1) {
		pos->index = oldStart;
		pos->errorIndex = oldStart;
		return nullptr;
	}
	bool var$5 = isParseIntegerOnly();
	if (var$5) {
		char16_t var$6 = text->charAt(position);
		var$5 = var$6 == $nc(this->symbols)->getDecimalSeparator();
	}
	if (var$5) {
		++position;
		for (; position < text->length(); ++position) {
			char16_t ch = text->charAt(position);
			int32_t digit = ch - $nc(this->symbols)->getZeroDigit();
			if (digit < 0 || digit > 9) {
				digit = $Character::digit(ch, 10);
				if (!(digit >= 0 && digit <= 9)) {
					break;
				}
			}
		}
	}
	pos->index = position;
	$var($Number, multiplier, computeParseMultiplier(text, pos, gotPositive ? matchedPosPrefix : matchedNegPrefix, status, gotPositive, gotNegative, num));
	if ($nc(multiplier)->longValue() == (int64_t)-1) {
		return nullptr;
	} else if (multiplier->longValue() != (int64_t)1) {
		$assign(cnfMultiplier, multiplier);
	}
	if (status->get(CompactNumberFormat::STATUS_INFINITE)) {
		if (status->get(CompactNumberFormat::STATUS_POSITIVE)) {
			$init($Double);
			return $Double::valueOf($Double::POSITIVE_INFINITY);
		} else {
			$init($Double);
			return $Double::valueOf($Double::NEGATIVE_INFINITY);
		}
	}
	if (isParseBigDecimal()) {
		$var($BigDecimal, bigDecimalResult, $nc(this->digitList)->getBigDecimal());
		if ($nc(cnfMultiplier)->longValue() != 1) {
			$assign(bigDecimalResult, $nc(bigDecimalResult)->multiply($$new($BigDecimal, $($of(cnfMultiplier)->toString()))));
		}
		if (!status->get(CompactNumberFormat::STATUS_POSITIVE)) {
			$assign(bigDecimalResult, $nc(bigDecimalResult)->negate());
		}
		return bigDecimalResult;
	} else {
		$var($Number, cnfResult, nullptr);
		if ($nc(this->digitList)->fitsIntoLong(status->get(CompactNumberFormat::STATUS_POSITIVE), isParseIntegerOnly())) {
			int64_t longResult = $nc(this->digitList)->getLong();
			$assign(cnfResult, generateParseResult($($Long::valueOf(longResult)), false, longResult < 0, status, cnfMultiplier));
		} else {
			$assign(cnfResult, generateParseResult($($Double::valueOf($nc(this->digitList)->getDouble())), true, false, status, cnfMultiplier));
		}
		return cnfResult;
	}
}

double CompactNumberFormat::parseNumberPart($String* text, int32_t position) {
	$useLocalCurrentObjectStackCache();
	if ($nc(text)->startsWith($($nc(this->symbols)->getInfinity()), position)) {
		$init($Double);
		return $Double::POSITIVE_INFINITY;
	} else if (!text->startsWith($($nc(this->symbols)->getNaN()), position)) {
		$var($Matcher, m, $nc(CompactNumberFormat::DIGITS)->matcher(text));
		if ($nc(m)->find(position)) {
			$var($String, digits, m->group());
			int32_t cp = $nc(digits)->codePointAt(0);
			if ($Character::isDigit(cp)) {
				return $Double::parseDouble($cast($String, $($nc($($nc($($(digits->codePoints())->map(static_cast<$IntUnaryOperator*>($$new(CompactNumberFormat$$Lambda$getNumericValue$4)))))->mapToObj(static_cast<$IntFunction*>($$new(CompactNumberFormat$$Lambda$toString$5)))))->collect($($Collectors::joining())))));
			}
		} else {
			return 1.0;
		}
	}
	$init($Double);
	return $Double::NaN;
}

$Number* CompactNumberFormat::generateParseResult($Number* number, bool gotDouble, bool gotLongMin, $booleans* status, $Number* cnfMultiplier) {
	$useLocalCurrentObjectStackCache();
	if (gotDouble) {
		if ($nc(cnfMultiplier)->longValue() != (int64_t)1) {
			double var$0 = $nc(number)->doubleValue();
			double doubleResult = var$0 * cnfMultiplier->doubleValue();
			doubleResult = $nc(($cast($Double, $(convertIfNegative($($Double::valueOf(doubleResult)), status, gotLongMin)))))->doubleValue();
			int64_t longResult = $cast(int64_t, doubleResult);
			gotDouble = ((doubleResult != (double)longResult) || (doubleResult == 0.0 && 1 / doubleResult < 0.0));
			return gotDouble ? static_cast<$Number*>($Double::valueOf(doubleResult)) : static_cast<$Number*>($Long::valueOf(longResult));
		}
	} else if ($nc(cnfMultiplier)->longValue() != (int64_t)1) {
		$var($Number, result, nullptr);
		if (($instanceOf($Long, cnfMultiplier)) && !gotLongMin) {
			int64_t longMultiplier = $nc(($cast($Long, cnfMultiplier)))->longValue();
			try {
				$assign(result, $Long::valueOf($Math::multiplyExact($nc(number)->longValue(), longMultiplier)));
			} catch ($ArithmeticException& ex) {
				double var$1 = $nc(number)->doubleValue();
				$assign(result, $Double::valueOf(var$1 * cnfMultiplier->doubleValue()));
			}
		} else {
			double var$2 = $nc(number)->doubleValue();
			$assign(result, $Double::valueOf(var$2 * cnfMultiplier->doubleValue()));
		}
		return convertIfNegative(result, status, gotLongMin);
	}
	return convertIfNegative(number, status, gotLongMin);
}

$Number* CompactNumberFormat::convertIfNegative($Number* number, $booleans* status, bool gotLongMin) {
	if (!$nc(status)->get(CompactNumberFormat::STATUS_POSITIVE) && !gotLongMin) {
		if ($instanceOf($Long, number)) {
			return $Long::valueOf(-$nc(($cast($Long, number)))->longValue());
		} else {
			return $Double::valueOf(-$nc(($cast($Double, number)))->doubleValue());
		}
	} else {
		return number;
	}
}

bool CompactNumberFormat::matchAffix($String* text, int32_t position, $String* affix, $String* defaultAffix, $String* matchedAffix) {
	bool var$0 = !$nc(affix)->isEmpty();
	if (var$0 && !affix->equals(defaultAffix)) {
		int32_t var$1 = $nc(matchedAffix)->length();
		if (var$1 < affix->length()) {
			return $nc(text)->regionMatches(position, affix, 0, affix->length());
		}
	}
	return false;
}

bool CompactNumberFormat::matchPrefixAndSuffix($String* text, int32_t position, $String* prefix, $String* matchedPrefix, $String* defaultPrefix, $String* suffix, $String* matchedSuffix, $String* defaultSuffix) {
	bool var$0 = $nc(prefix)->equals(matchedPrefix);
	if (var$0 || $nc(matchedPrefix)->equals(defaultPrefix)) {
		return matchAffix(text, position, suffix, defaultSuffix, matchedSuffix);
	}
	return false;
}

$Number* CompactNumberFormat::computeParseMultiplier($String* text, $ParsePosition* parsePosition, $String* matchedPrefix, $booleans* status, bool gotPositive, bool gotNegative, double num) {
	$useLocalCurrentObjectStackCache();
	int32_t position = $nc(parsePosition)->index;
	bool gotPos = false;
	bool gotNeg = false;
	int32_t matchedPosIndex = -1;
	int32_t matchedNegIndex = -1;
	$var($String, matchedPosSuffix, ""_s);
	$var($String, matchedNegSuffix, ""_s);
	for (int32_t compactIndex = 0; compactIndex < $nc(this->compactPatterns)->length; ++compactIndex) {
		$var($String, positivePrefix, getAffix(true, true, false, compactIndex, $cast(int32_t, num)));
		$var($String, negativePrefix, getAffix(true, true, true, compactIndex, $cast(int32_t, num)));
		$var($String, positiveSuffix, getAffix(true, false, false, compactIndex, $cast(int32_t, num)));
		$var($String, negativeSuffix, getAffix(true, false, true, compactIndex, $cast(int32_t, num)));
		$var($String, var$0, text);
		int32_t var$1 = position;
		$var($String, var$2, positivePrefix);
		$var($String, var$3, matchedPrefix);
		$var($String, var$4, $nc(this->defaultDecimalFormat)->getPositivePrefix());
		$var($String, var$5, positiveSuffix);
		$var($String, var$6, matchedPosSuffix);
		bool match = matchPrefixAndSuffix(var$0, var$1, var$2, var$3, var$4, var$5, var$6, $($nc(this->defaultDecimalFormat)->getPositiveSuffix()));
		if (match) {
			matchedPosIndex = compactIndex;
			$assign(matchedPosSuffix, positiveSuffix);
			gotPos = true;
		}
		$var($String, var$7, text);
		int32_t var$8 = position;
		$var($String, var$9, negativePrefix);
		$var($String, var$10, matchedPrefix);
		$var($String, var$11, $nc(this->defaultDecimalFormat)->getNegativePrefix());
		$var($String, var$12, negativeSuffix);
		$var($String, var$13, matchedNegSuffix);
		match = matchPrefixAndSuffix(var$7, var$8, var$9, var$10, var$11, var$12, var$13, $($nc(this->defaultDecimalFormat)->getNegativeSuffix()));
		if (match) {
			matchedNegIndex = compactIndex;
			$assign(matchedNegSuffix, negativeSuffix);
			gotNeg = true;
		}
	}
	if (!gotPos && !gotNeg) {
		$var($String, positiveSuffix, $nc(this->defaultDecimalFormat)->getPositiveSuffix());
		$var($String, negativeSuffix, $nc(this->defaultDecimalFormat)->getNegativeSuffix());
		if ($nc(text)->regionMatches(position, positiveSuffix, 0, $nc(positiveSuffix)->length())) {
			$assign(matchedPosSuffix, positiveSuffix);
			gotPos = true;
		}
		if ($nc(text)->regionMatches(position, negativeSuffix, 0, $nc(negativeSuffix)->length())) {
			$assign(matchedNegSuffix, negativeSuffix);
			gotNeg = true;
		}
	}
	if (gotPos && gotNeg) {
		int32_t var$14 = $nc(matchedPosSuffix)->length();
		if (var$14 > $nc(matchedNegSuffix)->length()) {
			gotNeg = false;
		} else {
			int32_t var$16 = matchedPosSuffix->length();
			if (var$16 < matchedNegSuffix->length()) {
				gotPos = false;
			} else {
				gotPos = gotPositive;
				gotNeg = gotNegative;
			}
		}
	}
	if (gotPos == gotNeg) {
		parsePosition->errorIndex = position;
		return $Long::valueOf((int64_t)-1);
	}
	$var($Number, cnfMultiplier, nullptr);
	if (gotPos) {
		parsePosition->index = position + $nc(matchedPosSuffix)->length();
		$assign(cnfMultiplier, matchedPosIndex != -1 ? $cast($Number, $nc(this->divisors)->get(matchedPosIndex)) : static_cast<$Number*>($Long::valueOf((int64_t)1)));
	} else {
		parsePosition->index = position + $nc(matchedNegSuffix)->length();
		$assign(cnfMultiplier, matchedNegIndex != -1 ? $cast($Number, $nc(this->divisors)->get(matchedNegIndex)) : static_cast<$Number*>($Long::valueOf((int64_t)1)));
	}
	$nc(status)->set(CompactNumberFormat::STATUS_POSITIVE, gotPos);
	return cnfMultiplier;
}

void CompactNumberFormat::readObject($ObjectInputStream* inStream) {
	$useLocalCurrentObjectStackCache();
	$nc(inStream)->defaultReadObject();
	if (this->decimalPattern == nullptr || this->compactPatterns == nullptr || this->symbols == nullptr || this->roundingMode == nullptr) {
		$throwNew($InvalidObjectException, "One of the \'decimalPattern\', \'compactPatterns\', \'symbols\' or \'roundingMode\' is null"_s);
	}
	bool var$0 = getMaximumIntegerDigits() > $DecimalFormat::DOUBLE_INTEGER_DIGITS;
	if (var$0 || getMaximumFractionDigits() > $DecimalFormat::DOUBLE_FRACTION_DIGITS) {
		$throwNew($InvalidObjectException, "Digit count out of range"_s);
	}
	if (this->groupingSize < 0) {
		$throwNew($InvalidObjectException, "Grouping size is negative"_s);
	}
	if (this->pluralRules == nullptr) {
		$set(this, pluralRules, ""_s);
	}
	try {
		processCompactPatterns();
	} catch ($IllegalArgumentException& ex) {
		$throwNew($InvalidObjectException, $(ex->getMessage()));
	}
	$set(this, decimalFormat, $new($DecimalFormat, CompactNumberFormat::SPECIAL_PATTERN, this->symbols));
	$nc(this->decimalFormat)->setMaximumFractionDigits(getMaximumFractionDigits());
	$nc(this->decimalFormat)->setMinimumFractionDigits(getMinimumFractionDigits());
	$nc(this->decimalFormat)->setMaximumIntegerDigits(getMaximumIntegerDigits());
	$nc(this->decimalFormat)->setMinimumIntegerDigits(getMinimumIntegerDigits());
	$nc(this->decimalFormat)->setRoundingMode($(getRoundingMode()));
	$nc(this->decimalFormat)->setGroupingSize(getGroupingSize());
	$nc(this->decimalFormat)->setGroupingUsed(isGroupingUsed());
	$nc(this->decimalFormat)->setParseIntegerOnly(isParseIntegerOnly());
	try {
		$set(this, defaultDecimalFormat, $new($DecimalFormat, this->decimalPattern, this->symbols));
		$nc(this->defaultDecimalFormat)->setMaximumFractionDigits(0);
	} catch ($IllegalArgumentException& ex) {
		$throwNew($InvalidObjectException, $(ex->getMessage()));
	}
}

void CompactNumberFormat::setMaximumIntegerDigits(int32_t newValue) {
	$nc(this->decimalFormat)->setMaximumIntegerDigits($Math::min(newValue, $DecimalFormat::DOUBLE_INTEGER_DIGITS));
	$NumberFormat::setMaximumIntegerDigits($nc(this->decimalFormat)->getMaximumIntegerDigits());
	int32_t var$0 = $nc(this->decimalFormat)->getMinimumIntegerDigits();
	if (var$0 > $nc(this->decimalFormat)->getMaximumIntegerDigits()) {
		$nc(this->decimalFormat)->setMinimumIntegerDigits($nc(this->decimalFormat)->getMaximumIntegerDigits());
		$NumberFormat::setMinimumIntegerDigits($nc(this->decimalFormat)->getMinimumIntegerDigits());
	}
}

void CompactNumberFormat::setMinimumIntegerDigits(int32_t newValue) {
	$nc(this->decimalFormat)->setMinimumIntegerDigits($Math::min(newValue, $DecimalFormat::DOUBLE_INTEGER_DIGITS));
	$NumberFormat::setMinimumIntegerDigits($nc(this->decimalFormat)->getMinimumIntegerDigits());
	int32_t var$0 = $nc(this->decimalFormat)->getMinimumIntegerDigits();
	if (var$0 > $nc(this->decimalFormat)->getMaximumIntegerDigits()) {
		$nc(this->decimalFormat)->setMaximumIntegerDigits($nc(this->decimalFormat)->getMinimumIntegerDigits());
		$NumberFormat::setMaximumIntegerDigits($nc(this->decimalFormat)->getMaximumIntegerDigits());
	}
}

void CompactNumberFormat::setMinimumFractionDigits(int32_t newValue) {
	$nc(this->decimalFormat)->setMinimumFractionDigits($Math::min(newValue, $DecimalFormat::DOUBLE_FRACTION_DIGITS));
	$NumberFormat::setMinimumFractionDigits($nc(this->decimalFormat)->getMinimumFractionDigits());
	int32_t var$0 = $nc(this->decimalFormat)->getMinimumFractionDigits();
	if (var$0 > $nc(this->decimalFormat)->getMaximumFractionDigits()) {
		$nc(this->decimalFormat)->setMaximumFractionDigits($nc(this->decimalFormat)->getMinimumFractionDigits());
		$NumberFormat::setMaximumFractionDigits($nc(this->decimalFormat)->getMaximumFractionDigits());
	}
}

void CompactNumberFormat::setMaximumFractionDigits(int32_t newValue) {
	$nc(this->decimalFormat)->setMaximumFractionDigits($Math::min(newValue, $DecimalFormat::DOUBLE_FRACTION_DIGITS));
	$NumberFormat::setMaximumFractionDigits($nc(this->decimalFormat)->getMaximumFractionDigits());
	int32_t var$0 = $nc(this->decimalFormat)->getMinimumFractionDigits();
	if (var$0 > $nc(this->decimalFormat)->getMaximumFractionDigits()) {
		$nc(this->decimalFormat)->setMinimumFractionDigits($nc(this->decimalFormat)->getMaximumFractionDigits());
		$NumberFormat::setMinimumFractionDigits($nc(this->decimalFormat)->getMinimumFractionDigits());
	}
}

$RoundingMode* CompactNumberFormat::getRoundingMode() {
	return this->roundingMode;
}

void CompactNumberFormat::setRoundingMode($RoundingMode* roundingMode) {
	$nc(this->decimalFormat)->setRoundingMode(roundingMode);
	$set(this, roundingMode, roundingMode);
}

int32_t CompactNumberFormat::getGroupingSize() {
	return this->groupingSize;
}

void CompactNumberFormat::setGroupingSize(int32_t newValue) {
	if (newValue < 0 || newValue > 127) {
		$throwNew($IllegalArgumentException, "The value passed is negative or larger than 127"_s);
	}
	this->groupingSize = (int8_t)newValue;
	$nc(this->decimalFormat)->setGroupingSize(this->groupingSize);
}

bool CompactNumberFormat::isGroupingUsed() {
	return $NumberFormat::isGroupingUsed();
}

void CompactNumberFormat::setGroupingUsed(bool newValue) {
	$nc(this->decimalFormat)->setGroupingUsed(newValue);
	$NumberFormat::setGroupingUsed(newValue);
}

bool CompactNumberFormat::isParseIntegerOnly() {
	return $NumberFormat::isParseIntegerOnly();
}

void CompactNumberFormat::setParseIntegerOnly(bool value) {
	$nc(this->decimalFormat)->setParseIntegerOnly(value);
	$NumberFormat::setParseIntegerOnly(value);
}

bool CompactNumberFormat::isParseBigDecimal() {
	return this->parseBigDecimal;
}

void CompactNumberFormat::setParseBigDecimal(bool newValue) {
	this->parseBigDecimal = newValue;
}

bool CompactNumberFormat::equals(Object$* obj) {
	if (!$NumberFormat::equals(obj)) {
		return false;
	}
	$var(CompactNumberFormat, other, $cast(CompactNumberFormat, obj));
	bool var$3 = $nc(this->decimalPattern)->equals($nc(other)->decimalPattern);
	bool var$2 = var$3 && $nc(this->symbols)->equals($nc(other)->symbols);
	bool var$1 = var$2 && $Arrays::equals(this->compactPatterns, $nc(other)->compactPatterns);
	bool var$0 = var$1 && $nc(this->roundingMode)->equals($nc(other)->roundingMode);
	return var$0 && $nc(this->pluralRules)->equals($nc(other)->pluralRules) && this->groupingSize == $nc(other)->groupingSize && this->parseBigDecimal == other->parseBigDecimal;
}

int32_t CompactNumberFormat::hashCode() {
	int32_t var$2 = 31 * $NumberFormat::hashCode();
	int32_t var$1 = var$2 + $Objects::hash($$new($ObjectArray, {
		$of(this->decimalPattern),
		$of(this->symbols),
		$of(this->roundingMode),
		$of(this->pluralRules)
	}));
	int32_t var$0 = var$1 + $Arrays::hashCode(this->compactPatterns) + this->groupingSize;
	return var$0 + $Boolean::hashCode(this->parseBigDecimal);
}

$Object* CompactNumberFormat::clone() {
	$var(CompactNumberFormat, other, $cast(CompactNumberFormat, $NumberFormat::clone()));
	$set($nc(other), compactPatterns, $cast($StringArray, $nc(this->compactPatterns)->clone()));
	$set(other, symbols, $cast($DecimalFormatSymbols, $nc(this->symbols)->clone()));
	return $of(other);
}

int32_t CompactNumberFormat::getIntegerPart(double number, double divisor) {
	$useLocalCurrentObjectStackCache();
	return $nc($($nc($($BigDecimal::valueOf(number)))->divide($($BigDecimal::valueOf(divisor)), this->roundingMode)))->intValue();
}

$String* CompactNumberFormat::getPluralCategory(double input) {
	$useLocalCurrentObjectStackCache();
	if (this->rulesMap != nullptr) {
		return $cast($String, $nc($($nc($($nc($($nc($($nc($($nc(this->rulesMap)->entrySet()))->stream()))->filter(static_cast<$Predicate*>($$new(CompactNumberFormat$$Lambda$lambda$getPluralCategory$3$6, input)))))->map(static_cast<$Function*>($$new(CompactNumberFormat$$Lambda$getKey$7)))))->findFirst()))->orElse("other"_s));
	}
	return "other"_s;
}

bool CompactNumberFormat::matchPluralRule($String* condition, double input) {
	$init(CompactNumberFormat);
	$useLocalCurrentObjectStackCache();
	return $nc($($Arrays::stream($($nc(condition)->split("or"_s)))))->anyMatch(static_cast<$Predicate*>($$new(CompactNumberFormat$$Lambda$lambda$matchPluralRule$5$8, input)));
}

bool CompactNumberFormat::valOrRangeMatches($String* valueOrRange, double input) {
	$init(CompactNumberFormat);
	$useLocalCurrentObjectStackCache();
	$var($Matcher, m, $nc(CompactNumberFormat::VALUE_RANGE_PATTERN)->matcher(valueOrRange));
	if ($nc(m)->find()) {
		$var($String, value, m->group("value"_s));
		if (value != nullptr) {
			return input == $Double::parseDouble(value);
		} else {
			bool var$0 = input >= $Double::parseDouble($(m->group("start"_s)));
			return var$0 && input <= $Double::parseDouble($(m->group("end"_s)));
		}
	}
	return false;
}

bool CompactNumberFormat::relationCheck($String* relation, double input) {
	$init(CompactNumberFormat);
	$useLocalCurrentObjectStackCache();
	$var($Matcher, expr, $nc(CompactNumberFormat::EXPR_PATTERN)->matcher(relation));
	if ($nc(expr)->find()) {
		double lop = evalLOperand(expr, input);
		$var($Matcher, rel, $nc(CompactNumberFormat::RELATION_PATTERN)->matcher(relation));
		if ($nc(rel)->find(expr->end())) {
			$var($Stream, conditions, $Arrays::stream($($($nc(relation)->substring(rel->end()))->split(","_s))));
			if ($Objects::equals($(rel->group("rel"_s)), "!="_s)) {
				return $nc(conditions)->noneMatch(static_cast<$Predicate*>($$new(CompactNumberFormat$$Lambda$lambda$relationCheck$6$9, lop)));
			} else {
				return $nc(conditions)->anyMatch(static_cast<$Predicate*>($$new(CompactNumberFormat$$Lambda$lambda$relationCheck$6$9, lop)));
			}
		}
	}
	return false;
}

double CompactNumberFormat::evalLOperand($Matcher* expr, double input) {
	$init(CompactNumberFormat);
	$useLocalCurrentObjectStackCache();
	double ret = (double)0;
	$init($Double);
	if (input == $Double::POSITIVE_INFINITY) {
		ret = input;
	} else {
		$var($String, op, $nc(expr)->group("op"_s));
		bool var$0 = $Objects::equals(op, "n"_s);
		if (var$0 || $Objects::equals(op, "i"_s)) {
			ret = input;
		}
		$var($String, divop, expr->group("div"_s));
		if (divop != nullptr) {
			$var($String, divisor, expr->group("val"_s));
			{
				$var($String, s111788$, divop);
				int32_t tmp111788$ = -1;
				switch (s111788$->hashCode()) {
				case 37:
					{
						if (s111788$->equals("%"_s)) {
							tmp111788$ = 0;
						}
						break;
					}
				case 47:
					{
						if (s111788$->equals("/"_s)) {
							tmp111788$ = 1;
						}
						break;
					}
				}
				switch (tmp111788$) {
				case 0:
					{
						$modAssign(ret, $Double::parseDouble(divisor));
						break;
					}
				case 1:
					{
						ret /= $Double::parseDouble(divisor);
						break;
					}
				}
			}
		}
	}
	return ret;
}

bool CompactNumberFormat::lambda$relationCheck$6(double lop, $String* c) {
	$init(CompactNumberFormat);
	return valOrRangeMatches(c, lop);
}

bool CompactNumberFormat::lambda$matchPluralRule$5(double input, $String* and_condition) {
	$init(CompactNumberFormat);
	$useLocalCurrentObjectStackCache();
	return $nc($($Arrays::stream($($nc(and_condition)->split("and"_s)))))->allMatch(static_cast<$Predicate*>($$new(CompactNumberFormat$$Lambda$lambda$matchPluralRule$4$10, input)));
}

bool CompactNumberFormat::lambda$matchPluralRule$4(double input, $String* r) {
	$init(CompactNumberFormat);
	return relationCheck(r, input);
}

bool CompactNumberFormat::lambda$getPluralCategory$3(double input, $Map$Entry* e) {
	$init(CompactNumberFormat);
	return matchPluralRule($cast($String, $($nc(e)->getValue())), input);
}

$String* CompactNumberFormat::lambda$buildPluralRulesMap$2($String* r) {
	$init(CompactNumberFormat);
	return $nc(r)->replaceFirst("[^:]+:"_s, ""_s);
}

$String* CompactNumberFormat::lambda$buildPluralRulesMap$1($String* r) {
	$init(CompactNumberFormat);
	return $nc(r)->replaceFirst(":.*"_s, ""_s);
}

void CompactNumberFormat::lambda$processCompactPatterns$0(int32_t idx, $MatchResult* mr) {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $nc(mr)->group(1));
	applyPattern(var$0, $(mr->group(2)), idx);
}

void clinit$CompactNumberFormat($Class* class$) {
	$assignStatic(CompactNumberFormat::SPECIAL_PATTERN, "0"_s);
	$assignStatic(CompactNumberFormat::EXPR, "([niftvwe])\\s*(([/%])\\s*(\\d+))*"_s);
	$assignStatic(CompactNumberFormat::RELATION, "(!?=)"_s);
	$assignStatic(CompactNumberFormat::VALUE_RANGE, "((\\d+)\\.\\.(\\d+)|\\d+)"_s);
	$assignStatic(CompactNumberFormat::CONDITION, $str({CompactNumberFormat::EXPR, "\\s*"_s, CompactNumberFormat::RELATION, "\\s*"_s, CompactNumberFormat::VALUE_RANGE, "\\s*(,\\s*"_s, CompactNumberFormat::VALUE_RANGE, ")*"_s}));
	$assignStatic(CompactNumberFormat::NAMED_EXPR, "(?<op>[niftvwe])\\s*((?<div>[/%])\\s*(?<val>\\d+))*"_s);
	$assignStatic(CompactNumberFormat::NAMED_RELATION, "(?<rel>!?=)"_s);
	$assignStatic(CompactNumberFormat::NAMED_VALUE_RANGE, "(?<start>\\d+)\\.\\.(?<end>\\d+)|(?<value>\\d+)"_s);
	$assignStatic(CompactNumberFormat::PLURALS, $Pattern::compile("^\\{(?<plurals>.*)}$"_s));
	$assignStatic(CompactNumberFormat::COUNT_PATTERN, $Pattern::compile("(zero|one|two|few|many|other):((\' \'|[^ ])+)[ ]*"_s));
	$assignStatic(CompactNumberFormat::PLURALRULES_PATTERN, $Pattern::compile($$str({"(zero|one|two|few|many):\\s*"_s, CompactNumberFormat::CONDITION, "(\\s*(and|or)\\s*"_s, CompactNumberFormat::CONDITION, ")*"_s})));
	$assignStatic(CompactNumberFormat::DIGITS, $Pattern::compile("\\p{Nd}+"_s));
	$assignStatic(CompactNumberFormat::EXPR_PATTERN, $Pattern::compile(CompactNumberFormat::NAMED_EXPR));
	$assignStatic(CompactNumberFormat::RELATION_PATTERN, $Pattern::compile(CompactNumberFormat::NAMED_RELATION));
	$assignStatic(CompactNumberFormat::VALUE_RANGE_PATTERN, $Pattern::compile(CompactNumberFormat::NAMED_VALUE_RANGE));
}

CompactNumberFormat::CompactNumberFormat() {
}

$Class* CompactNumberFormat::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(CompactNumberFormat$$Lambda$lambda$processCompactPatterns$0::classInfo$.name)) {
			return CompactNumberFormat$$Lambda$lambda$processCompactPatterns$0::load$(name, initialize);
		}
		if (name->equals(CompactNumberFormat$$Lambda$validateRule$1::classInfo$.name)) {
			return CompactNumberFormat$$Lambda$validateRule$1::load$(name, initialize);
		}
		if (name->equals(CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$1$2::classInfo$.name)) {
			return CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$1$2::load$(name, initialize);
		}
		if (name->equals(CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$2$3::classInfo$.name)) {
			return CompactNumberFormat$$Lambda$lambda$buildPluralRulesMap$2$3::load$(name, initialize);
		}
		if (name->equals(CompactNumberFormat$$Lambda$getNumericValue$4::classInfo$.name)) {
			return CompactNumberFormat$$Lambda$getNumericValue$4::load$(name, initialize);
		}
		if (name->equals(CompactNumberFormat$$Lambda$toString$5::classInfo$.name)) {
			return CompactNumberFormat$$Lambda$toString$5::load$(name, initialize);
		}
		if (name->equals(CompactNumberFormat$$Lambda$lambda$getPluralCategory$3$6::classInfo$.name)) {
			return CompactNumberFormat$$Lambda$lambda$getPluralCategory$3$6::load$(name, initialize);
		}
		if (name->equals(CompactNumberFormat$$Lambda$getKey$7::classInfo$.name)) {
			return CompactNumberFormat$$Lambda$getKey$7::load$(name, initialize);
		}
		if (name->equals(CompactNumberFormat$$Lambda$lambda$matchPluralRule$5$8::classInfo$.name)) {
			return CompactNumberFormat$$Lambda$lambda$matchPluralRule$5$8::load$(name, initialize);
		}
		if (name->equals(CompactNumberFormat$$Lambda$lambda$relationCheck$6$9::classInfo$.name)) {
			return CompactNumberFormat$$Lambda$lambda$relationCheck$6$9::load$(name, initialize);
		}
		if (name->equals(CompactNumberFormat$$Lambda$lambda$matchPluralRule$4$10::classInfo$.name)) {
			return CompactNumberFormat$$Lambda$lambda$matchPluralRule$4$10::load$(name, initialize);
		}
	}
	$loadClass(CompactNumberFormat, name, initialize, &_CompactNumberFormat_ClassInfo_, clinit$CompactNumberFormat, allocate$CompactNumberFormat);
	return class$;
}

$Class* CompactNumberFormat::class$ = nullptr;

	} // text
} // java