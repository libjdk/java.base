#include <java/util/regex/Pattern.h>

#include <java/io/ObjectInputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Iterable.h>
#include <java/lang/Math.h>
#include <java/lang/OutOfMemoryError.h>
#include <java/lang/StackOverflowError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/text/Normalizer$Form.h>
#include <java/text/Normalizer.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashSet.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Predicate.h>
#include <java/util/regex/ASCII.h>
#include <java/util/regex/CharPredicates.h>
#include <java/util/regex/Grapheme.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern$1MatcherIterator.h>
#include <java/util/regex/Pattern$BackRef.h>
#include <java/util/regex/Pattern$Begin.h>
#include <java/util/regex/Pattern$Behind.h>
#include <java/util/regex/Pattern$BehindS.h>
#include <java/util/regex/Pattern$BitClass.h>
#include <java/util/regex/Pattern$BmpCharPredicate.h>
#include <java/util/regex/Pattern$BmpCharProperty.h>
#include <java/util/regex/Pattern$BmpCharPropertyGreedy.h>
#include <java/util/regex/Pattern$BnM.h>
#include <java/util/regex/Pattern$Bound.h>
#include <java/util/regex/Pattern$Branch.h>
#include <java/util/regex/Pattern$BranchConn.h>
#include <java/util/regex/Pattern$CIBackRef.h>
#include <java/util/regex/Pattern$Caret.h>
#include <java/util/regex/Pattern$CharPredicate.h>
#include <java/util/regex/Pattern$CharProperty.h>
#include <java/util/regex/Pattern$CharPropertyGreedy.h>
#include <java/util/regex/Pattern$Curly.h>
#include <java/util/regex/Pattern$Dollar.h>
#include <java/util/regex/Pattern$End.h>
#include <java/util/regex/Pattern$First.h>
#include <java/util/regex/Pattern$GraphemeBound.h>
#include <java/util/regex/Pattern$GroupCurly.h>
#include <java/util/regex/Pattern$GroupHead.h>
#include <java/util/regex/Pattern$GroupTail.h>
#include <java/util/regex/Pattern$LastMatch.h>
#include <java/util/regex/Pattern$LastNode.h>
#include <java/util/regex/Pattern$LazyLoop.h>
#include <java/util/regex/Pattern$LineEnding.h>
#include <java/util/regex/Pattern$LookBehindEndNode.h>
#include <java/util/regex/Pattern$Loop.h>
#include <java/util/regex/Pattern$NFCCharProperty.h>
#include <java/util/regex/Pattern$Neg.h>
#include <java/util/regex/Pattern$Node.h>
#include <java/util/regex/Pattern$NotBehind.h>
#include <java/util/regex/Pattern$NotBehindS.h>
#include <java/util/regex/Pattern$Pos.h>
#include <java/util/regex/Pattern$Prolog.h>
#include <java/util/regex/Pattern$Qtype.h>
#include <java/util/regex/Pattern$Ques.h>
#include <java/util/regex/Pattern$Slice.h>
#include <java/util/regex/Pattern$SliceI.h>
#include <java/util/regex/Pattern$SliceIS.h>
#include <java/util/regex/Pattern$SliceS.h>
#include <java/util/regex/Pattern$SliceU.h>
#include <java/util/regex/Pattern$SliceUS.h>
#include <java/util/regex/Pattern$Start.h>
#include <java/util/regex/Pattern$StartS.h>
#include <java/util/regex/Pattern$TreeInfo.h>
#include <java/util/regex/Pattern$UnixCaret.h>
#include <java/util/regex/Pattern$UnixDollar.h>
#include <java/util/regex/Pattern$XGrapheme.h>
#include <java/util/regex/PatternSyntaxException.h>
#include <java/util/stream/Stream.h>
#include <java/util/stream/StreamSupport.h>
#include <jdk/internal/util/ArraysSupport.h>
#include <sun/text/Normalizer.h>
#include <jcpp.h>

#undef ALL
#undef ALL_FLAGS
#undef BOTH
#undef CANON_EQ
#undef CASE_INSENSITIVE
#undef COMMENTS
#undef DOT
#undef DOTALL
#undef ENGLISH
#undef GREEDY
#undef INDEPENDENT
#undef INSTANCE
#undef LAZY
#undef LITERAL
#undef MAX_CODE_POINT
#undef MAX_LOW_SURROGATE
#undef MAX_REPS
#undef MAX_VALUE
#undef MIN_HIGH_SURROGATE
#undef MIN_SUPPLEMENTARY_CODE_POINT
#undef MULTILINE
#undef N
#undef NFC
#undef NFD
#undef NONE
#undef NONNULL
#undef NON_SPACING_MARK
#undef ORDERED
#undef POSSESSIVE
#undef UNICODE_CASE
#undef UNICODE_CHARACTER_CLASS
#undef UNIXDOT
#undef UNIX_LINES

using $Pattern$GroupHeadArray = $Array<::java::util::regex::Pattern$GroupHead>;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $Serializable = ::java::io::Serializable;
using $ArithmeticException = ::java::lang::ArithmeticException;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $OutOfMemoryError = ::java::lang::OutOfMemoryError;
using $StackOverflowError = ::java::lang::StackOverflowError;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Normalizer = ::java::text::Normalizer;
using $Normalizer$Form = ::java::text::Normalizer$Form;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LinkedHashSet = ::java::util::LinkedHashSet;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $Spliterator = ::java::util::Spliterator;
using $Spliterators = ::java::util::Spliterators;
using $Consumer = ::java::util::function::Consumer;
using $Predicate = ::java::util::function::Predicate;
using $ASCII = ::java::util::regex::ASCII;
using $CharPredicates = ::java::util::regex::CharPredicates;
using $Grapheme = ::java::util::regex::Grapheme;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern$1MatcherIterator = ::java::util::regex::Pattern$1MatcherIterator;
using $Pattern$BackRef = ::java::util::regex::Pattern$BackRef;
using $Pattern$Begin = ::java::util::regex::Pattern$Begin;
using $Pattern$Behind = ::java::util::regex::Pattern$Behind;
using $Pattern$BehindS = ::java::util::regex::Pattern$BehindS;
using $Pattern$BitClass = ::java::util::regex::Pattern$BitClass;
using $Pattern$BmpCharPredicate = ::java::util::regex::Pattern$BmpCharPredicate;
using $Pattern$BmpCharProperty = ::java::util::regex::Pattern$BmpCharProperty;
using $Pattern$BmpCharPropertyGreedy = ::java::util::regex::Pattern$BmpCharPropertyGreedy;
using $Pattern$BnM = ::java::util::regex::Pattern$BnM;
using $Pattern$Bound = ::java::util::regex::Pattern$Bound;
using $Pattern$Branch = ::java::util::regex::Pattern$Branch;
using $Pattern$BranchConn = ::java::util::regex::Pattern$BranchConn;
using $Pattern$CIBackRef = ::java::util::regex::Pattern$CIBackRef;
using $Pattern$Caret = ::java::util::regex::Pattern$Caret;
using $Pattern$CharPredicate = ::java::util::regex::Pattern$CharPredicate;
using $Pattern$CharProperty = ::java::util::regex::Pattern$CharProperty;
using $Pattern$CharPropertyGreedy = ::java::util::regex::Pattern$CharPropertyGreedy;
using $Pattern$Curly = ::java::util::regex::Pattern$Curly;
using $Pattern$Dollar = ::java::util::regex::Pattern$Dollar;
using $Pattern$End = ::java::util::regex::Pattern$End;
using $Pattern$First = ::java::util::regex::Pattern$First;
using $Pattern$GraphemeBound = ::java::util::regex::Pattern$GraphemeBound;
using $Pattern$GroupCurly = ::java::util::regex::Pattern$GroupCurly;
using $Pattern$GroupHead = ::java::util::regex::Pattern$GroupHead;
using $Pattern$GroupTail = ::java::util::regex::Pattern$GroupTail;
using $Pattern$LastMatch = ::java::util::regex::Pattern$LastMatch;
using $Pattern$LastNode = ::java::util::regex::Pattern$LastNode;
using $Pattern$LazyLoop = ::java::util::regex::Pattern$LazyLoop;
using $Pattern$LineEnding = ::java::util::regex::Pattern$LineEnding;
using $Pattern$LookBehindEndNode = ::java::util::regex::Pattern$LookBehindEndNode;
using $Pattern$Loop = ::java::util::regex::Pattern$Loop;
using $Pattern$NFCCharProperty = ::java::util::regex::Pattern$NFCCharProperty;
using $Pattern$Neg = ::java::util::regex::Pattern$Neg;
using $Pattern$Node = ::java::util::regex::Pattern$Node;
using $Pattern$NotBehind = ::java::util::regex::Pattern$NotBehind;
using $Pattern$NotBehindS = ::java::util::regex::Pattern$NotBehindS;
using $Pattern$Pos = ::java::util::regex::Pattern$Pos;
using $Pattern$Prolog = ::java::util::regex::Pattern$Prolog;
using $Pattern$Qtype = ::java::util::regex::Pattern$Qtype;
using $Pattern$Ques = ::java::util::regex::Pattern$Ques;
using $Pattern$Slice = ::java::util::regex::Pattern$Slice;
using $Pattern$SliceI = ::java::util::regex::Pattern$SliceI;
using $Pattern$SliceIS = ::java::util::regex::Pattern$SliceIS;
using $Pattern$SliceS = ::java::util::regex::Pattern$SliceS;
using $Pattern$SliceU = ::java::util::regex::Pattern$SliceU;
using $Pattern$SliceUS = ::java::util::regex::Pattern$SliceUS;
using $Pattern$Start = ::java::util::regex::Pattern$Start;
using $Pattern$StartS = ::java::util::regex::Pattern$StartS;
using $Pattern$TreeInfo = ::java::util::regex::Pattern$TreeInfo;
using $Pattern$UnixCaret = ::java::util::regex::Pattern$UnixCaret;
using $Pattern$UnixDollar = ::java::util::regex::Pattern$UnixDollar;
using $Pattern$XGrapheme = ::java::util::regex::Pattern$XGrapheme;
using $PatternSyntaxException = ::java::util::regex::PatternSyntaxException;
using $Stream = ::java::util::stream::Stream;
using $StreamSupport = ::java::util::stream::StreamSupport;
using $ArraysSupport = ::jdk::internal::util::ArraysSupport;
using $1Normalizer = ::sun::text::Normalizer;

namespace java {
	namespace util {
		namespace regex {

class Pattern$$Lambda$lambda$normalizeSlice$0 : public $Consumer {
	$class(Pattern$$Lambda$lambda$normalizeSlice$0, $NO_CLASS_INIT, $Consumer)
public:
	void init$($StringBuilder* dst) {
		$set(this, dst, dst);
	}
	virtual void accept(Object$* s) override {
		Pattern::lambda$normalizeSlice$0(dst, $cast($String, s));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Pattern$$Lambda$lambda$normalizeSlice$0>());
	}
	$StringBuilder* dst = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Pattern$$Lambda$lambda$normalizeSlice$0::fieldInfos[2] = {
	{"dst", "Ljava/lang/StringBuilder;", nullptr, $PUBLIC, $field(Pattern$$Lambda$lambda$normalizeSlice$0, dst)},
	{}
};
$MethodInfo Pattern$$Lambda$lambda$normalizeSlice$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/StringBuilder;)V", nullptr, $PUBLIC, $method(Pattern$$Lambda$lambda$normalizeSlice$0, init$, void, $StringBuilder*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Pattern$$Lambda$lambda$normalizeSlice$0, accept, void, Object$*)},
	{}
};
$ClassInfo Pattern$$Lambda$lambda$normalizeSlice$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.regex.Pattern$$Lambda$lambda$normalizeSlice$0",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* Pattern$$Lambda$lambda$normalizeSlice$0::load$($String* name, bool initialize) {
	$loadClass(Pattern$$Lambda$lambda$normalizeSlice$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Pattern$$Lambda$lambda$normalizeSlice$0::class$ = nullptr;

class Pattern$$Lambda$lambda$VertWS$1$1 : public $Pattern$BmpCharPredicate {
	$class(Pattern$$Lambda$lambda$VertWS$1$1, $NO_CLASS_INIT, $Pattern$BmpCharPredicate)
public:
	void init$() {
	}
	virtual bool is(int32_t cp) override {
		 return Pattern::lambda$VertWS$1(cp);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Pattern$$Lambda$lambda$VertWS$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Pattern$$Lambda$lambda$VertWS$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Pattern$$Lambda$lambda$VertWS$1$1, init$, void)},
	{"is", "(I)Z", nullptr, $PUBLIC, $virtualMethod(Pattern$$Lambda$lambda$VertWS$1$1, is, bool, int32_t)},
	{}
};
$ClassInfo Pattern$$Lambda$lambda$VertWS$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.regex.Pattern$$Lambda$lambda$VertWS$1$1",
	"java.lang.Object",
	"java.util.regex.Pattern$BmpCharPredicate",
	nullptr,
	methodInfos
};
$Class* Pattern$$Lambda$lambda$VertWS$1$1::load$($String* name, bool initialize) {
	$loadClass(Pattern$$Lambda$lambda$VertWS$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Pattern$$Lambda$lambda$VertWS$1$1::class$ = nullptr;

class Pattern$$Lambda$lambda$HorizWS$2$2 : public $Pattern$BmpCharPredicate {
	$class(Pattern$$Lambda$lambda$HorizWS$2$2, $NO_CLASS_INIT, $Pattern$BmpCharPredicate)
public:
	void init$() {
	}
	virtual bool is(int32_t cp) override {
		 return Pattern::lambda$HorizWS$2(cp);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Pattern$$Lambda$lambda$HorizWS$2$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Pattern$$Lambda$lambda$HorizWS$2$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Pattern$$Lambda$lambda$HorizWS$2$2, init$, void)},
	{"is", "(I)Z", nullptr, $PUBLIC, $virtualMethod(Pattern$$Lambda$lambda$HorizWS$2$2, is, bool, int32_t)},
	{}
};
$ClassInfo Pattern$$Lambda$lambda$HorizWS$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.regex.Pattern$$Lambda$lambda$HorizWS$2$2",
	"java.lang.Object",
	"java.util.regex.Pattern$BmpCharPredicate",
	nullptr,
	methodInfos
};
$Class* Pattern$$Lambda$lambda$HorizWS$2$2::load$($String* name, bool initialize) {
	$loadClass(Pattern$$Lambda$lambda$HorizWS$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Pattern$$Lambda$lambda$HorizWS$2$2::class$ = nullptr;

class Pattern$$Lambda$lambda$ALL$3$3 : public $Pattern$CharPredicate {
	$class(Pattern$$Lambda$lambda$ALL$3$3, $NO_CLASS_INIT, $Pattern$CharPredicate)
public:
	void init$() {
	}
	virtual bool is(int32_t ch) override {
		 return Pattern::lambda$ALL$3(ch);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Pattern$$Lambda$lambda$ALL$3$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Pattern$$Lambda$lambda$ALL$3$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Pattern$$Lambda$lambda$ALL$3$3, init$, void)},
	{"is", "(I)Z", nullptr, $PUBLIC, $virtualMethod(Pattern$$Lambda$lambda$ALL$3$3, is, bool, int32_t)},
	{}
};
$ClassInfo Pattern$$Lambda$lambda$ALL$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.regex.Pattern$$Lambda$lambda$ALL$3$3",
	"java.lang.Object",
	"java.util.regex.Pattern$CharPredicate",
	nullptr,
	methodInfos
};
$Class* Pattern$$Lambda$lambda$ALL$3$3::load$($String* name, bool initialize) {
	$loadClass(Pattern$$Lambda$lambda$ALL$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Pattern$$Lambda$lambda$ALL$3$3::class$ = nullptr;

class Pattern$$Lambda$lambda$DOT$4$4 : public $Pattern$CharPredicate {
	$class(Pattern$$Lambda$lambda$DOT$4$4, $NO_CLASS_INIT, $Pattern$CharPredicate)
public:
	void init$() {
	}
	virtual bool is(int32_t ch) override {
		 return Pattern::lambda$DOT$4(ch);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Pattern$$Lambda$lambda$DOT$4$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Pattern$$Lambda$lambda$DOT$4$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Pattern$$Lambda$lambda$DOT$4$4, init$, void)},
	{"is", "(I)Z", nullptr, $PUBLIC, $virtualMethod(Pattern$$Lambda$lambda$DOT$4$4, is, bool, int32_t)},
	{}
};
$ClassInfo Pattern$$Lambda$lambda$DOT$4$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.regex.Pattern$$Lambda$lambda$DOT$4$4",
	"java.lang.Object",
	"java.util.regex.Pattern$CharPredicate",
	nullptr,
	methodInfos
};
$Class* Pattern$$Lambda$lambda$DOT$4$4::load$($String* name, bool initialize) {
	$loadClass(Pattern$$Lambda$lambda$DOT$4$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Pattern$$Lambda$lambda$DOT$4$4::class$ = nullptr;

class Pattern$$Lambda$lambda$UNIXDOT$5$5 : public $Pattern$CharPredicate {
	$class(Pattern$$Lambda$lambda$UNIXDOT$5$5, $NO_CLASS_INIT, $Pattern$CharPredicate)
public:
	void init$() {
	}
	virtual bool is(int32_t ch) override {
		 return Pattern::lambda$UNIXDOT$5(ch);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Pattern$$Lambda$lambda$UNIXDOT$5$5>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Pattern$$Lambda$lambda$UNIXDOT$5$5::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Pattern$$Lambda$lambda$UNIXDOT$5$5, init$, void)},
	{"is", "(I)Z", nullptr, $PUBLIC, $virtualMethod(Pattern$$Lambda$lambda$UNIXDOT$5$5, is, bool, int32_t)},
	{}
};
$ClassInfo Pattern$$Lambda$lambda$UNIXDOT$5$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.regex.Pattern$$Lambda$lambda$UNIXDOT$5$5",
	"java.lang.Object",
	"java.util.regex.Pattern$CharPredicate",
	nullptr,
	methodInfos
};
$Class* Pattern$$Lambda$lambda$UNIXDOT$5$5::load$($String* name, bool initialize) {
	$loadClass(Pattern$$Lambda$lambda$UNIXDOT$5$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Pattern$$Lambda$lambda$UNIXDOT$5$5::class$ = nullptr;

class Pattern$$Lambda$lambda$SingleS$6$6 : public $Pattern$BmpCharPredicate {
	$class(Pattern$$Lambda$lambda$SingleS$6$6, $NO_CLASS_INIT, $Pattern$BmpCharPredicate)
public:
	void init$(int32_t c) {
		this->c = c;
	}
	virtual bool is(int32_t ch) override {
		 return Pattern::lambda$SingleS$6(c, ch);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Pattern$$Lambda$lambda$SingleS$6$6>());
	}
	int32_t c = 0;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Pattern$$Lambda$lambda$SingleS$6$6::fieldInfos[2] = {
	{"c", "I", nullptr, $PUBLIC, $field(Pattern$$Lambda$lambda$SingleS$6$6, c)},
	{}
};
$MethodInfo Pattern$$Lambda$lambda$SingleS$6$6::methodInfos[3] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(Pattern$$Lambda$lambda$SingleS$6$6, init$, void, int32_t)},
	{"is", "(I)Z", nullptr, $PUBLIC, $virtualMethod(Pattern$$Lambda$lambda$SingleS$6$6, is, bool, int32_t)},
	{}
};
$ClassInfo Pattern$$Lambda$lambda$SingleS$6$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.regex.Pattern$$Lambda$lambda$SingleS$6$6",
	"java.lang.Object",
	"java.util.regex.Pattern$BmpCharPredicate",
	fieldInfos,
	methodInfos
};
$Class* Pattern$$Lambda$lambda$SingleS$6$6::load$($String* name, bool initialize) {
	$loadClass(Pattern$$Lambda$lambda$SingleS$6$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Pattern$$Lambda$lambda$SingleS$6$6::class$ = nullptr;

class Pattern$$Lambda$lambda$SingleI$8$7 : public $Pattern$BmpCharPredicate {
	$class(Pattern$$Lambda$lambda$SingleI$8$7, $NO_CLASS_INIT, $Pattern$BmpCharPredicate)
public:
	void init$(int32_t lower, int32_t upper) {
		this->lower = lower;
		this->upper = upper;
	}
	virtual bool is(int32_t ch) override {
		 return Pattern::lambda$SingleI$8(lower, upper, ch);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Pattern$$Lambda$lambda$SingleI$8$7>());
	}
	int32_t lower = 0;
	int32_t upper = 0;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Pattern$$Lambda$lambda$SingleI$8$7::fieldInfos[3] = {
	{"lower", "I", nullptr, $PUBLIC, $field(Pattern$$Lambda$lambda$SingleI$8$7, lower)},
	{"upper", "I", nullptr, $PUBLIC, $field(Pattern$$Lambda$lambda$SingleI$8$7, upper)},
	{}
};
$MethodInfo Pattern$$Lambda$lambda$SingleI$8$7::methodInfos[3] = {
	{"<init>", "(II)V", nullptr, $PUBLIC, $method(Pattern$$Lambda$lambda$SingleI$8$7, init$, void, int32_t, int32_t)},
	{"is", "(I)Z", nullptr, $PUBLIC, $virtualMethod(Pattern$$Lambda$lambda$SingleI$8$7, is, bool, int32_t)},
	{}
};
$ClassInfo Pattern$$Lambda$lambda$SingleI$8$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.regex.Pattern$$Lambda$lambda$SingleI$8$7",
	"java.lang.Object",
	"java.util.regex.Pattern$BmpCharPredicate",
	fieldInfos,
	methodInfos
};
$Class* Pattern$$Lambda$lambda$SingleI$8$7::load$($String* name, bool initialize) {
	$loadClass(Pattern$$Lambda$lambda$SingleI$8$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Pattern$$Lambda$lambda$SingleI$8$7::class$ = nullptr;

class Pattern$$Lambda$lambda$SingleU$9$8 : public $Pattern$CharPredicate {
	$class(Pattern$$Lambda$lambda$SingleU$9$8, $NO_CLASS_INIT, $Pattern$CharPredicate)
public:
	void init$(int32_t lower) {
		this->lower = lower;
	}
	virtual bool is(int32_t ch) override {
		 return Pattern::lambda$SingleU$9(lower, ch);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Pattern$$Lambda$lambda$SingleU$9$8>());
	}
	int32_t lower = 0;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Pattern$$Lambda$lambda$SingleU$9$8::fieldInfos[2] = {
	{"lower", "I", nullptr, $PUBLIC, $field(Pattern$$Lambda$lambda$SingleU$9$8, lower)},
	{}
};
$MethodInfo Pattern$$Lambda$lambda$SingleU$9$8::methodInfos[3] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(Pattern$$Lambda$lambda$SingleU$9$8, init$, void, int32_t)},
	{"is", "(I)Z", nullptr, $PUBLIC, $virtualMethod(Pattern$$Lambda$lambda$SingleU$9$8, is, bool, int32_t)},
	{}
};
$ClassInfo Pattern$$Lambda$lambda$SingleU$9$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.regex.Pattern$$Lambda$lambda$SingleU$9$8",
	"java.lang.Object",
	"java.util.regex.Pattern$CharPredicate",
	fieldInfos,
	methodInfos
};
$Class* Pattern$$Lambda$lambda$SingleU$9$8::load$($String* name, bool initialize) {
	$loadClass(Pattern$$Lambda$lambda$SingleU$9$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Pattern$$Lambda$lambda$SingleU$9$8::class$ = nullptr;

class Pattern$$Lambda$lambda$Range$10$9 : public $Pattern$BmpCharPredicate {
	$class(Pattern$$Lambda$lambda$Range$10$9, $NO_CLASS_INIT, $Pattern$BmpCharPredicate)
public:
	void init$(int32_t lower, int32_t upper) {
		this->lower = lower;
		this->upper = upper;
	}
	virtual bool is(int32_t ch) override {
		 return Pattern::lambda$Range$10(lower, upper, ch);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Pattern$$Lambda$lambda$Range$10$9>());
	}
	int32_t lower = 0;
	int32_t upper = 0;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Pattern$$Lambda$lambda$Range$10$9::fieldInfos[3] = {
	{"lower", "I", nullptr, $PUBLIC, $field(Pattern$$Lambda$lambda$Range$10$9, lower)},
	{"upper", "I", nullptr, $PUBLIC, $field(Pattern$$Lambda$lambda$Range$10$9, upper)},
	{}
};
$MethodInfo Pattern$$Lambda$lambda$Range$10$9::methodInfos[3] = {
	{"<init>", "(II)V", nullptr, $PUBLIC, $method(Pattern$$Lambda$lambda$Range$10$9, init$, void, int32_t, int32_t)},
	{"is", "(I)Z", nullptr, $PUBLIC, $virtualMethod(Pattern$$Lambda$lambda$Range$10$9, is, bool, int32_t)},
	{}
};
$ClassInfo Pattern$$Lambda$lambda$Range$10$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.regex.Pattern$$Lambda$lambda$Range$10$9",
	"java.lang.Object",
	"java.util.regex.Pattern$BmpCharPredicate",
	fieldInfos,
	methodInfos
};
$Class* Pattern$$Lambda$lambda$Range$10$9::load$($String* name, bool initialize) {
	$loadClass(Pattern$$Lambda$lambda$Range$10$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Pattern$$Lambda$lambda$Range$10$9::class$ = nullptr;

class Pattern$$Lambda$lambda$CIRange$12$10 : public $Pattern$CharPredicate {
	$class(Pattern$$Lambda$lambda$CIRange$12$10, $NO_CLASS_INIT, $Pattern$CharPredicate)
public:
	void init$(int32_t lower, int32_t upper) {
		this->lower = lower;
		this->upper = upper;
	}
	virtual bool is(int32_t ch) override {
		 return Pattern::lambda$CIRange$12(lower, upper, ch);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Pattern$$Lambda$lambda$CIRange$12$10>());
	}
	int32_t lower = 0;
	int32_t upper = 0;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Pattern$$Lambda$lambda$CIRange$12$10::fieldInfos[3] = {
	{"lower", "I", nullptr, $PUBLIC, $field(Pattern$$Lambda$lambda$CIRange$12$10, lower)},
	{"upper", "I", nullptr, $PUBLIC, $field(Pattern$$Lambda$lambda$CIRange$12$10, upper)},
	{}
};
$MethodInfo Pattern$$Lambda$lambda$CIRange$12$10::methodInfos[3] = {
	{"<init>", "(II)V", nullptr, $PUBLIC, $method(Pattern$$Lambda$lambda$CIRange$12$10, init$, void, int32_t, int32_t)},
	{"is", "(I)Z", nullptr, $PUBLIC, $virtualMethod(Pattern$$Lambda$lambda$CIRange$12$10, is, bool, int32_t)},
	{}
};
$ClassInfo Pattern$$Lambda$lambda$CIRange$12$10::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.regex.Pattern$$Lambda$lambda$CIRange$12$10",
	"java.lang.Object",
	"java.util.regex.Pattern$CharPredicate",
	fieldInfos,
	methodInfos
};
$Class* Pattern$$Lambda$lambda$CIRange$12$10::load$($String* name, bool initialize) {
	$loadClass(Pattern$$Lambda$lambda$CIRange$12$10, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Pattern$$Lambda$lambda$CIRange$12$10::class$ = nullptr;

class Pattern$$Lambda$lambda$CIRangeU$13$11 : public $Pattern$CharPredicate {
	$class(Pattern$$Lambda$lambda$CIRangeU$13$11, $NO_CLASS_INIT, $Pattern$CharPredicate)
public:
	void init$(int32_t lower, int32_t upper) {
		this->lower = lower;
		this->upper = upper;
	}
	virtual bool is(int32_t ch) override {
		 return Pattern::lambda$CIRangeU$13(lower, upper, ch);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Pattern$$Lambda$lambda$CIRangeU$13$11>());
	}
	int32_t lower = 0;
	int32_t upper = 0;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Pattern$$Lambda$lambda$CIRangeU$13$11::fieldInfos[3] = {
	{"lower", "I", nullptr, $PUBLIC, $field(Pattern$$Lambda$lambda$CIRangeU$13$11, lower)},
	{"upper", "I", nullptr, $PUBLIC, $field(Pattern$$Lambda$lambda$CIRangeU$13$11, upper)},
	{}
};
$MethodInfo Pattern$$Lambda$lambda$CIRangeU$13$11::methodInfos[3] = {
	{"<init>", "(II)V", nullptr, $PUBLIC, $method(Pattern$$Lambda$lambda$CIRangeU$13$11, init$, void, int32_t, int32_t)},
	{"is", "(I)Z", nullptr, $PUBLIC, $virtualMethod(Pattern$$Lambda$lambda$CIRangeU$13$11, is, bool, int32_t)},
	{}
};
$ClassInfo Pattern$$Lambda$lambda$CIRangeU$13$11::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.regex.Pattern$$Lambda$lambda$CIRangeU$13$11",
	"java.lang.Object",
	"java.util.regex.Pattern$CharPredicate",
	fieldInfos,
	methodInfos
};
$Class* Pattern$$Lambda$lambda$CIRangeU$13$11::load$($String* name, bool initialize) {
	$loadClass(Pattern$$Lambda$lambda$CIRangeU$13$11, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Pattern$$Lambda$lambda$CIRangeU$13$11::class$ = nullptr;

class Pattern$$Lambda$lambda$asPredicate$14$12 : public $Predicate {
	$class(Pattern$$Lambda$lambda$asPredicate$14$12, $NO_CLASS_INIT, $Predicate)
public:
	void init$(Pattern* inst) {
		$set(this, inst$, inst);
	}
	virtual bool test(Object$* s) override {
		 return $nc(inst$)->lambda$asPredicate$14($cast($String, s));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Pattern$$Lambda$lambda$asPredicate$14$12>());
	}
	Pattern* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Pattern$$Lambda$lambda$asPredicate$14$12::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Pattern$$Lambda$lambda$asPredicate$14$12, inst$)},
	{}
};
$MethodInfo Pattern$$Lambda$lambda$asPredicate$14$12::methodInfos[3] = {
	{"<init>", "(Ljava/util/regex/Pattern;)V", nullptr, $PUBLIC, $method(Pattern$$Lambda$lambda$asPredicate$14$12, init$, void, Pattern*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Pattern$$Lambda$lambda$asPredicate$14$12, test, bool, Object$*)},
	{}
};
$ClassInfo Pattern$$Lambda$lambda$asPredicate$14$12::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.regex.Pattern$$Lambda$lambda$asPredicate$14$12",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* Pattern$$Lambda$lambda$asPredicate$14$12::load$($String* name, bool initialize) {
	$loadClass(Pattern$$Lambda$lambda$asPredicate$14$12, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Pattern$$Lambda$lambda$asPredicate$14$12::class$ = nullptr;

class Pattern$$Lambda$lambda$asMatchPredicate$15$13 : public $Predicate {
	$class(Pattern$$Lambda$lambda$asMatchPredicate$15$13, $NO_CLASS_INIT, $Predicate)
public:
	void init$(Pattern* inst) {
		$set(this, inst$, inst);
	}
	virtual bool test(Object$* s) override {
		 return $nc(inst$)->lambda$asMatchPredicate$15($cast($String, s));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Pattern$$Lambda$lambda$asMatchPredicate$15$13>());
	}
	Pattern* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Pattern$$Lambda$lambda$asMatchPredicate$15$13::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Pattern$$Lambda$lambda$asMatchPredicate$15$13, inst$)},
	{}
};
$MethodInfo Pattern$$Lambda$lambda$asMatchPredicate$15$13::methodInfos[3] = {
	{"<init>", "(Ljava/util/regex/Pattern;)V", nullptr, $PUBLIC, $method(Pattern$$Lambda$lambda$asMatchPredicate$15$13, init$, void, Pattern*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Pattern$$Lambda$lambda$asMatchPredicate$15$13, test, bool, Object$*)},
	{}
};
$ClassInfo Pattern$$Lambda$lambda$asMatchPredicate$15$13::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.regex.Pattern$$Lambda$lambda$asMatchPredicate$15$13",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* Pattern$$Lambda$lambda$asMatchPredicate$15$13::load$($String* name, bool initialize) {
	$loadClass(Pattern$$Lambda$lambda$asMatchPredicate$15$13, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Pattern$$Lambda$lambda$asMatchPredicate$15$13::class$ = nullptr;

$FieldInfo _Pattern_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Pattern, $assertionsDisabled)},
	{"UNIX_LINES", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Pattern, UNIX_LINES)},
	{"CASE_INSENSITIVE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Pattern, CASE_INSENSITIVE)},
	{"COMMENTS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Pattern, COMMENTS)},
	{"MULTILINE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Pattern, MULTILINE)},
	{"LITERAL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Pattern, LITERAL)},
	{"DOTALL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Pattern, DOTALL)},
	{"UNICODE_CASE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Pattern, UNICODE_CASE)},
	{"CANON_EQ", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Pattern, CANON_EQ)},
	{"UNICODE_CHARACTER_CLASS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Pattern, UNICODE_CHARACTER_CLASS)},
	{"ALL_FLAGS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Pattern, ALL_FLAGS)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Pattern, serialVersionUID)},
	{"pattern", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Pattern, pattern$)},
	{"flags", "I", nullptr, $PRIVATE, $field(Pattern, flags$)},
	{"flags0", "I", nullptr, $PRIVATE | $TRANSIENT, $field(Pattern, flags0)},
	{"compiled", "Z", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(Pattern, compiled)},
	{"normalizedPattern", "Ljava/lang/String;", nullptr, $PRIVATE | $TRANSIENT, $field(Pattern, normalizedPattern)},
	{"root", "Ljava/util/regex/Pattern$Node;", nullptr, $TRANSIENT, $field(Pattern, root)},
	{"matchRoot", "Ljava/util/regex/Pattern$Node;", nullptr, $TRANSIENT, $field(Pattern, matchRoot)},
	{"buffer", "[I", nullptr, $TRANSIENT, $field(Pattern, buffer)},
	{"predicate", "Ljava/util/regex/Pattern$CharPredicate;", nullptr, $TRANSIENT, $field(Pattern, predicate)},
	{"namedGroups", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/Integer;>;", $VOLATILE | $TRANSIENT, $field(Pattern, namedGroups$)},
	{"groupNodes", "[Ljava/util/regex/Pattern$GroupHead;", nullptr, $TRANSIENT, $field(Pattern, groupNodes)},
	{"topClosureNodes", "Ljava/util/List;", "Ljava/util/List<Ljava/util/regex/Pattern$Node;>;", $TRANSIENT, $field(Pattern, topClosureNodes)},
	{"localTCNCount", "I", nullptr, $TRANSIENT, $field(Pattern, localTCNCount)},
	{"hasGroupRef", "Z", nullptr, $TRANSIENT, $field(Pattern, hasGroupRef)},
	{"temp", "[I", nullptr, $PRIVATE | $TRANSIENT, $field(Pattern, temp)},
	{"capturingGroupCount", "I", nullptr, $TRANSIENT, $field(Pattern, capturingGroupCount)},
	{"localCount", "I", nullptr, $TRANSIENT, $field(Pattern, localCount)},
	{"cursor", "I", nullptr, $PRIVATE | $TRANSIENT, $field(Pattern, cursor$)},
	{"patternLength", "I", nullptr, $PRIVATE | $TRANSIENT, $field(Pattern, patternLength)},
	{"hasSupplementary", "Z", nullptr, $PRIVATE | $TRANSIENT, $field(Pattern, hasSupplementary)},
	{"MAX_REPS", "I", nullptr, $STATIC | $FINAL, $constField(Pattern, MAX_REPS)},
	{"accept", "Ljava/util/regex/Pattern$Node;", nullptr, $STATIC | $FINAL, $staticField(Pattern, accept$)},
	{"lastAccept", "Ljava/util/regex/Pattern$Node;", nullptr, $STATIC | $FINAL, $staticField(Pattern, lastAccept)},
	{}
};

$MethodInfo _Pattern_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;I)V", nullptr, $PRIVATE, $method(Pattern, init$, void, $String*, int32_t)},
	{"ALL", "()Ljava/util/regex/Pattern$CharPredicate;", nullptr, $STATIC, $staticMethod(Pattern, ALL, $Pattern$CharPredicate*)},
	{"CIRange", "(II)Ljava/util/regex/Pattern$CharPredicate;", nullptr, $STATIC, $staticMethod(Pattern, CIRange, $Pattern$CharPredicate*, int32_t, int32_t)},
	{"CIRangeU", "(II)Ljava/util/regex/Pattern$CharPredicate;", nullptr, $STATIC, $staticMethod(Pattern, CIRangeU, $Pattern$CharPredicate*, int32_t, int32_t)},
	{"DOT", "()Ljava/util/regex/Pattern$CharPredicate;", nullptr, $STATIC, $staticMethod(Pattern, DOT, $Pattern$CharPredicate*)},
	{"HorizWS", "()Ljava/util/regex/Pattern$BmpCharPredicate;", nullptr, $STATIC, $staticMethod(Pattern, HorizWS, $Pattern$BmpCharPredicate*)},
	{"N", "()I", nullptr, $PRIVATE, $method(Pattern, N, int32_t)},
	{"Range", "(II)Ljava/util/regex/Pattern$CharPredicate;", nullptr, $STATIC, $staticMethod(Pattern, Range, $Pattern$CharPredicate*, int32_t, int32_t)},
	{"RemoveQEQuoting", "()V", nullptr, $PRIVATE, $method(Pattern, RemoveQEQuoting, void)},
	{"Single", "(I)Ljava/util/regex/Pattern$BmpCharPredicate;", nullptr, $STATIC, $staticMethod(Pattern, Single, $Pattern$BmpCharPredicate*, int32_t)},
	{"SingleI", "(II)Ljava/util/regex/Pattern$BmpCharPredicate;", nullptr, $STATIC, $staticMethod(Pattern, SingleI, $Pattern$BmpCharPredicate*, int32_t, int32_t)},
	{"SingleS", "(I)Ljava/util/regex/Pattern$CharPredicate;", nullptr, $STATIC, $staticMethod(Pattern, SingleS, $Pattern$CharPredicate*, int32_t)},
	{"SingleU", "(I)Ljava/util/regex/Pattern$CharPredicate;", nullptr, $STATIC, $staticMethod(Pattern, SingleU, $Pattern$CharPredicate*, int32_t)},
	{"UNIXDOT", "()Ljava/util/regex/Pattern$CharPredicate;", nullptr, $STATIC, $staticMethod(Pattern, UNIXDOT, $Pattern$CharPredicate*)},
	{"VertWS", "()Ljava/util/regex/Pattern$BmpCharPredicate;", nullptr, $STATIC, $staticMethod(Pattern, VertWS, $Pattern$BmpCharPredicate*)},
	{"accept", "(ILjava/lang/String;)V", nullptr, $PRIVATE, $method(Pattern, accept, void, int32_t, $String*)},
	{"addFlag", "()V", nullptr, $PRIVATE, $method(Pattern, addFlag, void)},
	{"append", "(II)V", nullptr, $PRIVATE, $method(Pattern, append, void, int32_t, int32_t)},
	{"asMatchPredicate", "()Ljava/util/function/Predicate;", "()Ljava/util/function/Predicate<Ljava/lang/String;>;", $PUBLIC, $method(Pattern, asMatchPredicate, $Predicate*)},
	{"asPredicate", "()Ljava/util/function/Predicate;", "()Ljava/util/function/Predicate<Ljava/lang/String;>;", $PUBLIC, $method(Pattern, asPredicate, $Predicate*)},
	{"atom", "()Ljava/util/regex/Pattern$Node;", nullptr, $PRIVATE, $method(Pattern, atom, $Pattern$Node*)},
	{"bitsOrSingle", "(Ljava/util/regex/Pattern$BitClass;I)Ljava/util/regex/Pattern$CharPredicate;", nullptr, $PRIVATE, $method(Pattern, bitsOrSingle, $Pattern$CharPredicate*, $Pattern$BitClass*, int32_t)},
	{"c", "()I", nullptr, $PRIVATE, $method(Pattern, c, int32_t)},
	{"clazz", "(Z)Ljava/util/regex/Pattern$CharPredicate;", nullptr, $PRIVATE, $method(Pattern, clazz, $Pattern$CharPredicate*, bool)},
	{"closure", "(Ljava/util/regex/Pattern$Node;)Ljava/util/regex/Pattern$Node;", nullptr, $PRIVATE, $method(Pattern, closure, $Pattern$Node*, $Pattern$Node*)},
	{"compile", "(Ljava/lang/String;)Ljava/util/regex/Pattern;", nullptr, $PUBLIC | $STATIC, $staticMethod(Pattern, compile, Pattern*, $String*)},
	{"compile", "(Ljava/lang/String;I)Ljava/util/regex/Pattern;", nullptr, $PUBLIC | $STATIC, $staticMethod(Pattern, compile, Pattern*, $String*, int32_t)},
	{"compile", "()V", nullptr, $PRIVATE, $method(Pattern, compile, void)},
	{"composeOneStep", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Pattern, composeOneStep, $String*, $String*)},
	{"countChars", "(Ljava/lang/CharSequence;II)I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(Pattern, countChars, int32_t, $CharSequence*, int32_t, int32_t)},
	{"countCodePoints", "(Ljava/lang/CharSequence;)I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(Pattern, countCodePoints, int32_t, $CharSequence*)},
	{"createGroup", "(Z)Ljava/util/regex/Pattern$Node;", nullptr, $PRIVATE, $method(Pattern, createGroup, $Pattern$Node*, bool)},
	{"curly", "(Ljava/util/regex/Pattern$Node;I)Ljava/util/regex/Pattern$Node;", nullptr, $PRIVATE, $method(Pattern, curly, $Pattern$Node*, $Pattern$Node*, int32_t)},
	{"cursor", "()I", nullptr, $PRIVATE, $method(Pattern, cursor, int32_t)},
	{"error", "(Ljava/lang/String;)Ljava/util/regex/PatternSyntaxException;", nullptr, $PRIVATE, $method(Pattern, error, $PatternSyntaxException*, $String*)},
	{"escape", "(ZZZ)I", nullptr, $PRIVATE, $method(Pattern, escape, int32_t, bool, bool, bool)},
	{"expr", "(Ljava/util/regex/Pattern$Node;)Ljava/util/regex/Pattern$Node;", nullptr, $PRIVATE, $method(Pattern, expr, $Pattern$Node*, $Pattern$Node*)},
	{"family", "(ZZ)Ljava/util/regex/Pattern$CharPredicate;", nullptr, $PRIVATE, $method(Pattern, family, $Pattern$CharPredicate*, bool, bool)},
	{"findSupplementary", "(II)Z", nullptr, $PRIVATE, $method(Pattern, findSupplementary, bool, int32_t, int32_t)},
	{"flags", "()I", nullptr, $PUBLIC, $method(Pattern, flags, int32_t)},
	{"getClass", "(I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(Pattern, getClass, int32_t, int32_t)},
	{"group0", "()Ljava/util/regex/Pattern$Node;", nullptr, $PRIVATE, $method(Pattern, group0, $Pattern$Node*)},
	{"groupname", "(I)Ljava/lang/String;", nullptr, $PRIVATE, $method(Pattern, groupname, $String*, int32_t)},
	{"has", "(I)Z", nullptr, $PRIVATE, $method(Pattern, has, bool, int32_t)},
	{"hasBaseCharacter", "(Ljava/util/regex/Matcher;ILjava/lang/CharSequence;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(Pattern, hasBaseCharacter, bool, $Matcher*, int32_t, $CharSequence*)},
	{"inRange", "(III)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(Pattern, inRange, bool, int32_t, int32_t, int32_t)},
	{"isLineSeparator", "(I)Z", nullptr, $PRIVATE, $method(Pattern, isLineSeparator, bool, int32_t)},
	{"isSupplementary", "(I)Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(Pattern, isSupplementary, bool, int32_t)},
	{"lambda$ALL$3", "(I)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Pattern, lambda$ALL$3, bool, int32_t)},
	{"lambda$CIRange$12", "(III)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Pattern, lambda$CIRange$12, bool, int32_t, int32_t, int32_t)},
	{"lambda$CIRangeU$13", "(III)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Pattern, lambda$CIRangeU$13, bool, int32_t, int32_t, int32_t)},
	{"lambda$DOT$4", "(I)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Pattern, lambda$DOT$4, bool, int32_t)},
	{"lambda$HorizWS$2", "(I)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Pattern, lambda$HorizWS$2, bool, int32_t)},
	{"lambda$Range$10", "(III)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Pattern, lambda$Range$10, bool, int32_t, int32_t, int32_t)},
	{"lambda$SingleI$8", "(III)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Pattern, lambda$SingleI$8, bool, int32_t, int32_t, int32_t)},
	{"lambda$SingleS$6", "(II)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Pattern, lambda$SingleS$6, bool, int32_t, int32_t)},
	{"lambda$SingleU$9", "(II)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Pattern, lambda$SingleU$9, bool, int32_t, int32_t)},
	{"lambda$UNIXDOT$5", "(I)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Pattern, lambda$UNIXDOT$5, bool, int32_t)},
	{"lambda$VertWS$1", "(I)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Pattern, lambda$VertWS$1, bool, int32_t)},
	{"lambda$asMatchPredicate$15", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $SYNTHETIC, $method(Pattern, lambda$asMatchPredicate$15, bool, $String*)},
	{"lambda$asPredicate$14", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $SYNTHETIC, $method(Pattern, lambda$asPredicate$14, bool, $String*)},
	{"lambda$normalizeSlice$0", "(Ljava/lang/StringBuilder;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Pattern, lambda$normalizeSlice$0, void, $StringBuilder*, $String*)},
	{"mark", "(I)V", nullptr, $PRIVATE, $method(Pattern, mark, void, int32_t)},
	{"matcher", "(Ljava/lang/CharSequence;)Ljava/util/regex/Matcher;", nullptr, $PUBLIC, $method(Pattern, matcher, $Matcher*, $CharSequence*)},
	{"matches", "(Ljava/lang/String;Ljava/lang/CharSequence;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(Pattern, matches, bool, $String*, $CharSequence*)},
	{"namedGroups", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/lang/Integer;>;", 0, $method(Pattern, namedGroups, $Map*)},
	{"newCharProperty", "(Ljava/util/regex/Pattern$CharPredicate;)Ljava/util/regex/Pattern$CharProperty;", nullptr, $PRIVATE, $method(Pattern, newCharProperty, $Pattern$CharProperty*, $Pattern$CharPredicate*)},
	{"newSlice", "([IIZ)Ljava/util/regex/Pattern$Node;", nullptr, $PRIVATE, $method(Pattern, newSlice, $Pattern$Node*, $ints*, int32_t, bool)},
	{"next", "()I", nullptr, $PRIVATE, $method(Pattern, next, int32_t)},
	{"nextEscaped", "()I", nullptr, $PRIVATE, $method(Pattern, nextEscaped, int32_t)},
	{"normalize", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Pattern, normalize, $String*, $String*)},
	{"normalizeClazz", "(Ljava/lang/String;IILjava/lang/StringBuilder;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Pattern, normalizeClazz, void, $String*, int32_t, int32_t, $StringBuilder*)},
	{"normalizeSlice", "(Ljava/lang/String;IILjava/lang/StringBuilder;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Pattern, normalizeSlice, void, $String*, int32_t, int32_t, $StringBuilder*)},
	{"o", "()I", nullptr, $PRIVATE, $method(Pattern, o, int32_t)},
	{"parsePastLine", "()I", nullptr, $PRIVATE, $method(Pattern, parsePastLine, int32_t)},
	{"parsePastWhitespace", "(I)I", nullptr, $PRIVATE, $method(Pattern, parsePastWhitespace, int32_t, int32_t)},
	{"pattern", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(Pattern, pattern, $String*)},
	{"peek", "()I", nullptr, $PRIVATE, $method(Pattern, peek, int32_t)},
	{"peekPastLine", "()I", nullptr, $PRIVATE, $method(Pattern, peekPastLine, int32_t)},
	{"peekPastWhitespace", "(I)I", nullptr, $PRIVATE, $method(Pattern, peekPastWhitespace, int32_t, int32_t)},
	{"produceEquivalentAlternation", "(Ljava/lang/String;Ljava/util/Set;)V", "(Ljava/lang/String;Ljava/util/Set<Ljava/lang/String;>;)V", $PRIVATE | $STATIC, $staticMethod(Pattern, produceEquivalentAlternation, void, $String*, $Set*)},
	{"producePermutations", "(Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Pattern, producePermutations, $StringArray*, $String*)},
	{"qtype", "()Ljava/util/regex/Pattern$Qtype;", nullptr, $PRIVATE, $method(Pattern, qtype, $Pattern$Qtype*)},
	{"quote", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Pattern, quote, $String*, $String*)},
	{"range", "(Ljava/util/regex/Pattern$BitClass;)Ljava/util/regex/Pattern$CharPredicate;", nullptr, $PRIVATE, $method(Pattern, range, $Pattern$CharPredicate*, $Pattern$BitClass*)},
	{"read", "()I", nullptr, $PRIVATE, $method(Pattern, read, int32_t)},
	{"readEscaped", "()I", nullptr, $PRIVATE, $method(Pattern, readEscaped, int32_t)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(Pattern, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"ref", "(I)Ljava/util/regex/Pattern$Node;", nullptr, $PRIVATE, $method(Pattern, ref, $Pattern$Node*, int32_t)},
	{"sequence", "(Ljava/util/regex/Pattern$Node;)Ljava/util/regex/Pattern$Node;", nullptr, $PRIVATE, $method(Pattern, sequence, $Pattern$Node*, $Pattern$Node*)},
	{"setcursor", "(I)V", nullptr, $PRIVATE, $method(Pattern, setcursor, void, int32_t)},
	{"single", "(I)Ljava/util/regex/Pattern$CharPredicate;", nullptr, $PRIVATE, $method(Pattern, single, $Pattern$CharPredicate*, int32_t)},
	{"skip", "()I", nullptr, $PRIVATE, $method(Pattern, skip, int32_t)},
	{"split", "(Ljava/lang/CharSequence;I)[Ljava/lang/String;", nullptr, $PUBLIC, $method(Pattern, split, $StringArray*, $CharSequence*, int32_t)},
	{"split", "(Ljava/lang/CharSequence;)[Ljava/lang/String;", nullptr, $PUBLIC, $method(Pattern, split, $StringArray*, $CharSequence*)},
	{"splitAsStream", "(Ljava/lang/CharSequence;)Ljava/util/stream/Stream;", "(Ljava/lang/CharSequence;)Ljava/util/stream/Stream<Ljava/lang/String;>;", $PUBLIC, $method(Pattern, splitAsStream, $Stream*, $CharSequence*)},
	{"subFlag", "()V", nullptr, $PRIVATE, $method(Pattern, subFlag, void)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Pattern, toString, $String*)},
	{"u", "()I", nullptr, $PRIVATE, $method(Pattern, u, int32_t)},
	{"unread", "()V", nullptr, $PRIVATE, $method(Pattern, unread, void)},
	{"uxxxx", "()I", nullptr, $PRIVATE, $method(Pattern, uxxxx, int32_t)},
	{"x", "()I", nullptr, $PRIVATE, $method(Pattern, x, int32_t)},
	{}
};

$InnerClassInfo _Pattern_InnerClassesInfo_[] = {
	{"java.util.regex.Pattern$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"java.util.regex.Pattern$BmpCharPredicate", "java.util.regex.Pattern", "BmpCharPredicate", $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.regex.Pattern$CharPredicate", "java.util.regex.Pattern", "CharPredicate", $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.regex.Pattern$BnMS", "java.util.regex.Pattern", "BnMS", $STATIC | $FINAL},
	{"java.util.regex.Pattern$BnM", "java.util.regex.Pattern", "BnM", $STATIC},
	{"java.util.regex.Pattern$Bound", "java.util.regex.Pattern", "Bound", $STATIC | $FINAL},
	{"java.util.regex.Pattern$NotBehindS", "java.util.regex.Pattern", "NotBehindS", $STATIC | $FINAL},
	{"java.util.regex.Pattern$NotBehind", "java.util.regex.Pattern", "NotBehind", $STATIC},
	{"java.util.regex.Pattern$BehindS", "java.util.regex.Pattern", "BehindS", $STATIC | $FINAL},
	{"java.util.regex.Pattern$Behind", "java.util.regex.Pattern", "Behind", $STATIC},
	{"java.util.regex.Pattern$LookBehindEndNode", "java.util.regex.Pattern", "LookBehindEndNode", $STATIC},
	{"java.util.regex.Pattern$Neg", "java.util.regex.Pattern", "Neg", $STATIC | $FINAL},
	{"java.util.regex.Pattern$Pos", "java.util.regex.Pattern", "Pos", $STATIC | $FINAL},
	{"java.util.regex.Pattern$First", "java.util.regex.Pattern", "First", $STATIC | $FINAL},
	{"java.util.regex.Pattern$CIBackRef", "java.util.regex.Pattern", "CIBackRef", $STATIC},
	{"java.util.regex.Pattern$BackRef", "java.util.regex.Pattern", "BackRef", $STATIC},
	{"java.util.regex.Pattern$LazyLoop", "java.util.regex.Pattern", "LazyLoop", $STATIC | $FINAL},
	{"java.util.regex.Pattern$Loop", "java.util.regex.Pattern", "Loop", $STATIC},
	{"java.util.regex.Pattern$Prolog", "java.util.regex.Pattern", "Prolog", $STATIC | $FINAL},
	{"java.util.regex.Pattern$GroupTail", "java.util.regex.Pattern", "GroupTail", $STATIC | $FINAL},
	{"java.util.regex.Pattern$GroupHead", "java.util.regex.Pattern", "GroupHead", $STATIC | $FINAL},
	{"java.util.regex.Pattern$Branch", "java.util.regex.Pattern", "Branch", $STATIC | $FINAL},
	{"java.util.regex.Pattern$BranchConn", "java.util.regex.Pattern", "BranchConn", $STATIC | $FINAL},
	{"java.util.regex.Pattern$GroupCurly", "java.util.regex.Pattern", "GroupCurly", $STATIC | $FINAL},
	{"java.util.regex.Pattern$Curly", "java.util.regex.Pattern", "Curly", $STATIC | $FINAL},
	{"java.util.regex.Pattern$BmpCharPropertyGreedy", "java.util.regex.Pattern", "BmpCharPropertyGreedy", $STATIC | $FINAL},
	{"java.util.regex.Pattern$CharPropertyGreedy", "java.util.regex.Pattern", "CharPropertyGreedy", $STATIC},
	{"java.util.regex.Pattern$Ques", "java.util.regex.Pattern", "Ques", $STATIC | $FINAL},
	{"java.util.regex.Pattern$SliceUS", "java.util.regex.Pattern", "SliceUS", $STATIC | $FINAL},
	{"java.util.regex.Pattern$SliceIS", "java.util.regex.Pattern", "SliceIS", $STATIC},
	{"java.util.regex.Pattern$SliceS", "java.util.regex.Pattern", "SliceS", $STATIC | $FINAL},
	{"java.util.regex.Pattern$SliceU", "java.util.regex.Pattern", "SliceU", $STATIC | $FINAL},
	{"java.util.regex.Pattern$SliceI", "java.util.regex.Pattern", "SliceI", $STATIC},
	{"java.util.regex.Pattern$Slice", "java.util.regex.Pattern", "Slice", $STATIC},
	{"java.util.regex.Pattern$SliceNode", "java.util.regex.Pattern", "SliceNode", $STATIC},
	{"java.util.regex.Pattern$GraphemeBound", "java.util.regex.Pattern", "GraphemeBound", $STATIC},
	{"java.util.regex.Pattern$XGrapheme", "java.util.regex.Pattern", "XGrapheme", $STATIC},
	{"java.util.regex.Pattern$NFCCharProperty", "java.util.regex.Pattern", "NFCCharProperty", $PRIVATE | $STATIC},
	{"java.util.regex.Pattern$BmpCharProperty", "java.util.regex.Pattern", "BmpCharProperty", $PRIVATE | $STATIC},
	{"java.util.regex.Pattern$CharProperty", "java.util.regex.Pattern", "CharProperty", $STATIC},
	{"java.util.regex.Pattern$LineEnding", "java.util.regex.Pattern", "LineEnding", $STATIC | $FINAL},
	{"java.util.regex.Pattern$UnixDollar", "java.util.regex.Pattern", "UnixDollar", $STATIC | $FINAL},
	{"java.util.regex.Pattern$Dollar", "java.util.regex.Pattern", "Dollar", $STATIC | $FINAL},
	{"java.util.regex.Pattern$LastMatch", "java.util.regex.Pattern", "LastMatch", $STATIC | $FINAL},
	{"java.util.regex.Pattern$UnixCaret", "java.util.regex.Pattern", "UnixCaret", $STATIC | $FINAL},
	{"java.util.regex.Pattern$Caret", "java.util.regex.Pattern", "Caret", $STATIC | $FINAL},
	{"java.util.regex.Pattern$End", "java.util.regex.Pattern", "End", $STATIC | $FINAL},
	{"java.util.regex.Pattern$Begin", "java.util.regex.Pattern", "Begin", $STATIC | $FINAL},
	{"java.util.regex.Pattern$StartS", "java.util.regex.Pattern", "StartS", $STATIC | $FINAL},
	{"java.util.regex.Pattern$Start", "java.util.regex.Pattern", "Start", $STATIC},
	{"java.util.regex.Pattern$LastNode", "java.util.regex.Pattern", "LastNode", $STATIC},
	{"java.util.regex.Pattern$Node", "java.util.regex.Pattern", "Node", $STATIC},
	{"java.util.regex.Pattern$BitClass", "java.util.regex.Pattern", "BitClass", $STATIC | $FINAL},
	{"java.util.regex.Pattern$Qtype", "java.util.regex.Pattern", "Qtype", $STATIC | $FINAL | $ENUM},
	{"java.util.regex.Pattern$TreeInfo", "java.util.regex.Pattern", "TreeInfo", $STATIC | $FINAL},
	{"java.util.regex.Pattern$1MatcherIterator", nullptr, "MatcherIterator", 0},
	{}
};

$ClassInfo _Pattern_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.util.regex.Pattern",
	"java.lang.Object",
	"java.io.Serializable",
	_Pattern_FieldInfo_,
	_Pattern_MethodInfo_,
	nullptr,
	nullptr,
	_Pattern_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.regex.Pattern$1,java.util.regex.Pattern$BmpCharPredicate,java.util.regex.Pattern$CharPredicate,java.util.regex.Pattern$BnMS,java.util.regex.Pattern$BnM,java.util.regex.Pattern$Bound,java.util.regex.Pattern$NotBehindS,java.util.regex.Pattern$NotBehind,java.util.regex.Pattern$BehindS,java.util.regex.Pattern$Behind,java.util.regex.Pattern$LookBehindEndNode,java.util.regex.Pattern$Neg,java.util.regex.Pattern$Pos,java.util.regex.Pattern$First,java.util.regex.Pattern$CIBackRef,java.util.regex.Pattern$BackRef,java.util.regex.Pattern$LazyLoop,java.util.regex.Pattern$Loop,java.util.regex.Pattern$Prolog,java.util.regex.Pattern$GroupTail,java.util.regex.Pattern$GroupHead,java.util.regex.Pattern$Branch,java.util.regex.Pattern$BranchConn,java.util.regex.Pattern$GroupCurly,java.util.regex.Pattern$Curly,java.util.regex.Pattern$BmpCharPropertyGreedy,java.util.regex.Pattern$CharPropertyGreedy,java.util.regex.Pattern$Ques,java.util.regex.Pattern$SliceUS,java.util.regex.Pattern$SliceIS,java.util.regex.Pattern$SliceS,java.util.regex.Pattern$SliceU,java.util.regex.Pattern$SliceI,java.util.regex.Pattern$Slice,java.util.regex.Pattern$SliceNode,java.util.regex.Pattern$GraphemeBound,java.util.regex.Pattern$XGrapheme,java.util.regex.Pattern$NFCCharProperty,java.util.regex.Pattern$BmpCharProperty,java.util.regex.Pattern$CharProperty,java.util.regex.Pattern$LineEnding,java.util.regex.Pattern$UnixDollar,java.util.regex.Pattern$Dollar,java.util.regex.Pattern$LastMatch,java.util.regex.Pattern$UnixCaret,java.util.regex.Pattern$Caret,java.util.regex.Pattern$End,java.util.regex.Pattern$Begin,java.util.regex.Pattern$StartS,java.util.regex.Pattern$Start,java.util.regex.Pattern$LastNode,java.util.regex.Pattern$Node,java.util.regex.Pattern$BitClass,java.util.regex.Pattern$Qtype,java.util.regex.Pattern$TreeInfo,java.util.regex.Pattern$1MatcherIterator"
};

$Object* allocate$Pattern($Class* clazz) {
	return $of($alloc(Pattern));
}

bool Pattern::$assertionsDisabled = false;
$Pattern$Node* Pattern::accept$ = nullptr;
$Pattern$Node* Pattern::lastAccept = nullptr;

Pattern* Pattern::compile($String* regex) {
	$init(Pattern);
	return $new(Pattern, regex, 0);
}

Pattern* Pattern::compile($String* regex, int32_t flags) {
	$init(Pattern);
	return $new(Pattern, regex, flags);
}

$String* Pattern::pattern() {
	return this->pattern$;
}

$String* Pattern::toString() {
	return this->pattern$;
}

$Matcher* Pattern::matcher($CharSequence* input) {
	if (!this->compiled) {
		$synchronized(this) {
			if (!this->compiled) {
				compile();
			}
		}
	}
	$var($Matcher, m, $new($Matcher, this, input));
	return m;
}

int32_t Pattern::flags() {
	return this->flags0;
}

bool Pattern::matches($String* regex, $CharSequence* input) {
	$init(Pattern);
	$useLocalCurrentObjectStackCache();
	$var(Pattern, p, Pattern::compile(regex));
	$var($Matcher, m, $nc(p)->matcher(input));
	return $nc(m)->matches();
}

$StringArray* Pattern::split($CharSequence* input, int32_t limit) {
	$useLocalCurrentObjectStackCache();
	int32_t index = 0;
	bool matchLimited = limit > 0;
	$var($ArrayList, matchList, $new($ArrayList));
	$var($Matcher, m, matcher(input));
	while ($nc(m)->find()) {
		if (!matchLimited || matchList->size() < limit - 1) {
			bool var$0 = index == 0 && index == m->start();
			if (var$0) {
				int32_t var$1 = m->start();
				var$0 = var$1 == m->end();
			}
			if (var$0) {
				continue;
			}
			$var($String, match, $nc($($nc(input)->subSequence(index, m->start())))->toString());
			matchList->add(match);
			index = m->end();
		} else if (matchList->size() == limit - 1) {
			$var($String, match, $nc($($nc(input)->subSequence(index, input->length())))->toString());
			matchList->add(match);
			index = m->end();
		}
	}
	if (index == 0) {
		return $new($StringArray, {$($nc(input)->toString())});
	}
	if (!matchLimited || matchList->size() < limit) {
		matchList->add($($nc($($nc(input)->subSequence(index, input->length())))->toString()));
	}
	int32_t resultSize = matchList->size();
	if (limit == 0) {
		while (resultSize > 0 && $nc(($cast($String, $(matchList->get(resultSize - 1)))))->isEmpty()) {
			--resultSize;
		}
	}
	$var($StringArray, result, $new($StringArray, resultSize));
	return $fcast($StringArray, $nc($(matchList->subList(0, resultSize)))->toArray(result));
}

$StringArray* Pattern::split($CharSequence* input) {
	return split(input, 0);
}

$String* Pattern::quote($String* s) {
	$init(Pattern);
	int32_t slashEIndex = $nc(s)->indexOf("\\E"_s);
	if (slashEIndex == -1) {
		return $str({"\\Q"_s, s, "\\E"_s});
	}
	int32_t lenHint = s->length();
	lenHint = (lenHint < $Integer::MAX_VALUE - 8 - lenHint) ? (lenHint << 1) : ($Integer::MAX_VALUE - 8);
	$var($StringBuilder, sb, $new($StringBuilder, lenHint));
	sb->append("\\Q"_s);
	int32_t current = 0;
	do {
		sb->append(static_cast<$CharSequence*>(s), current, slashEIndex)->append("\\E\\\\E\\Q"_s);
		current = slashEIndex + 2;
	} while ((slashEIndex = s->indexOf("\\E"_s, current)) != -1);
	return sb->append(static_cast<$CharSequence*>(s), current, s->length())->append("\\E"_s)->toString();
}

void Pattern::readObject($ObjectInputStream* s) {
	$nc(s)->defaultReadObject();
	this->flags0 = this->flags$;
	this->capturingGroupCount = 1;
	this->localCount = 0;
	this->localTCNCount = 0;
	if ($nc(this->pattern$)->isEmpty()) {
		$set(this, root, $new($Pattern$Start, Pattern::lastAccept));
		$set(this, matchRoot, Pattern::lastAccept);
		this->compiled = true;
	}
}

void Pattern::init$($String* p, int32_t f) {
	$useLocalCurrentObjectStackCache();
	if (((int32_t)(f & (uint32_t)~Pattern::ALL_FLAGS)) != 0) {
		$throwNew($IllegalArgumentException, $$str({"Unknown flag 0x"_s, $($Integer::toHexString(f))}));
	}
	$set(this, pattern$, p);
	this->flags$ = f;
	if (((int32_t)(this->flags$ & (uint32_t)Pattern::UNICODE_CHARACTER_CLASS)) != 0) {
		this->flags$ |= Pattern::UNICODE_CASE;
	}
	this->flags0 = this->flags$;
	this->capturingGroupCount = 1;
	this->localCount = 0;
	this->localTCNCount = 0;
	if (!$nc(this->pattern$)->isEmpty()) {
		try {
			compile();
		} catch ($StackOverflowError& soe) {
			$throw($(error("Stack overflow during pattern compilation"_s)));
		}
	} else {
		$set(this, root, $new($Pattern$Start, Pattern::lastAccept));
		$set(this, matchRoot, Pattern::lastAccept);
	}
}

$String* Pattern::normalize($String* pattern) {
	$init(Pattern);
	int32_t plen = $nc(pattern)->length();
	$var($StringBuilder, pbuf, $new($StringBuilder, plen));
	char16_t last = (char16_t)0;
	int32_t lastStart = 0;
	char16_t cc = (char16_t)0;
	for (int32_t i = 0; i < plen;) {
		char16_t c = pattern->charAt(i);
		if (cc == 0 && c == u'\\' && i + 1 < plen && pattern->charAt(i + 1) == u'\\') {
			i += 2;
			last = (char16_t)0;
			continue;
		}
		if (c == u'[' && last != u'\\') {
			if (cc == 0) {
				if (lastStart < i) {
					normalizeSlice(pattern, lastStart, i, pbuf);
				}
				lastStart = i;
			}
			++cc;
		} else if (c == u']' && last != u'\\') {
			--cc;
			if (cc == 0) {
				normalizeClazz(pattern, lastStart, i + 1, pbuf);
				lastStart = i + 1;
			}
		}
		last = c;
		++i;
	}
	if (!Pattern::$assertionsDisabled && !(cc == 0)) {
		$throwNew($AssertionError);
	}
	if (lastStart < plen) {
		normalizeSlice(pattern, lastStart, plen, pbuf);
	}
	return pbuf->toString();
}

void Pattern::normalizeSlice($String* src, int32_t off, int32_t limit, $StringBuilder* dst) {
	$init(Pattern);
	$useLocalCurrentObjectStackCache();
	int32_t len = $nc(src)->length();
	int32_t off0 = off;
	while (off < limit && $ASCII::isAscii(src->charAt(off))) {
		++off;
	}
	if (off == limit) {
		$nc(dst)->append(static_cast<$CharSequence*>(src), off0, limit);
		return;
	}
	--off;
	if (off < off0) {
		off = off0;
	} else {
		$nc(dst)->append(static_cast<$CharSequence*>(src), off0, off);
	}
	while (off < limit) {
		int32_t ch0 = src->codePointAt(off);
		if (".$|()[]{}^?*+\\"_s->indexOf(ch0) != -1) {
			$nc(dst)->append((char16_t)ch0);
			++off;
			continue;
		}
		int32_t j = $Grapheme::nextBoundary(src, off, limit);
		int32_t ch1 = 0;
		$var($String, seq, src->substring(off, j));
		$init($Normalizer$Form);
		$var($String, nfd, $Normalizer::normalize(seq, $Normalizer$Form::NFD));
		off = j;
		if ($nc(nfd)->codePointCount(0, nfd->length()) > 1) {
			ch0 = nfd->codePointAt(0);
			ch1 = nfd->codePointAt($Character::charCount(ch0));
			if ($Character::getType(ch1) == $Character::NON_SPACING_MARK) {
				$var($Set, altns, $new($LinkedHashSet));
				altns->add(seq);
				produceEquivalentAlternation(nfd, altns);
				$nc(dst)->append("(?:"_s);
				altns->forEach(static_cast<$Consumer*>($$new(Pattern$$Lambda$lambda$normalizeSlice$0, dst)));
				int32_t var$0 = dst->length() - 1;
				dst->delete$(var$0, dst->length());
				dst->append(")"_s);
				continue;
			}
		}
		$var($String, nfc, $Normalizer::normalize(seq, $Normalizer$Form::NFC));
		bool var$1 = !seq->equals(nfc);
		if (var$1 && !$nc(nfd)->equals(nfc)) {
			$nc(dst)->append($$str({"(?:"_s, seq, "|"_s, nfd, "|"_s, nfc, ")"_s}));
		} else if (!seq->equals(nfd)) {
			$nc(dst)->append($$str({"(?:"_s, seq, "|"_s, nfd, ")"_s}));
		} else {
			$nc(dst)->append(seq);
		}
	}
}

void Pattern::normalizeClazz($String* src, int32_t off, int32_t limit, $StringBuilder* dst) {
	$init(Pattern);
	$useLocalCurrentObjectStackCache();
	$init($Normalizer$Form);
	$nc(dst)->append($($Normalizer::normalize($($nc(src)->substring(off, limit)), $Normalizer$Form::NFC)));
}

void Pattern::produceEquivalentAlternation($String* src, $Set* dst) {
	$init(Pattern);
	$useLocalCurrentObjectStackCache();
	int32_t len = countChars(src, 0, 1);
	if ($nc(src)->length() == len) {
		$nc(dst)->add(src);
		return;
	}
	$var($String, base, $nc(src)->substring(0, len));
	$var($String, combiningMarks, src->substring(len));
	$var($StringArray, perms, producePermutations(combiningMarks));
	for (int32_t x = 0; x < $nc(perms)->length; ++x) {
		$var($String, next, $str({base, perms->get(x)}));
		$nc(dst)->add(next);
		$assign(next, composeOneStep(next));
		if (next != nullptr) {
			produceEquivalentAlternation(next, dst);
		}
	}
}

$StringArray* Pattern::producePermutations($String* input) {
	$init(Pattern);
	$useLocalCurrentObjectStackCache();
	int32_t var$0 = $nc(input)->length();
	if (var$0 == countChars(input, 0, 1)) {
		return $new($StringArray, {input});
	}
	int32_t var$1 = $nc(input)->length();
	if (var$1 == countChars(input, 0, 2)) {
		int32_t c0 = $Character::codePointAt(static_cast<$CharSequence*>(input), 0);
		int32_t c1 = $Character::codePointAt(static_cast<$CharSequence*>(input), $Character::charCount(c0));
		int32_t var$2 = getClass(c1);
		if (var$2 == getClass(c0)) {
			return $new($StringArray, {input});
		}
		$var($StringArray, result, $new($StringArray, 2));
		result->set(0, input);
		$var($StringBuilder, sb, $new($StringBuilder, 2));
		sb->appendCodePoint(c1);
		sb->appendCodePoint(c0);
		result->set(1, $(sb->toString()));
		return result;
	}
	int32_t length = 1;
	int32_t nCodePoints = countCodePoints(input);
	for (int32_t x = 1; x < nCodePoints; ++x) {
		length = length * (x + 1);
	}
	$var($StringArray, temp, $new($StringArray, length));
	$var($ints, combClass, $new($ints, nCodePoints));
	{
		int32_t x = 0;
		int32_t i = 0;
		for (; x < nCodePoints; ++x) {
			int32_t c = $Character::codePointAt(static_cast<$CharSequence*>(input), i);
			combClass->set(x, getClass(c));
			i += $Character::charCount(c);
		}
	}
	int32_t index = 0;
	int32_t len = 0;
	bool loop$continue = false;
	{
		int32_t x = 0;
		int32_t offset = 0;
		for (; x < nCodePoints; ++x, offset += len) {
			len = countChars(input, offset, 1);
			for (int32_t y = x - 1; y >= 0; --y) {
				if (combClass->get(y) == combClass->get(x)) {
					loop$continue = true;
					break;
				}
			}
			if (loop$continue) {
				loop$continue = false;
				continue;
			}
			$var($StringBuilder, sb, $new($StringBuilder, input));
			$var($String, otherChars, $nc(sb->delete$(offset, offset + len))->toString());
			$var($StringArray, subResult, producePermutations(otherChars));
			$var($String, prefix, $nc(input)->substring(offset, offset + len));
			{
				$var($StringArray, arr$, subResult);
				int32_t len$ = $nc(arr$)->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($String, sre, arr$->get(i$));
					temp->set(index++, $$str({prefix, sre}));
				}
			}
		}
	}
	$var($StringArray, result, $new($StringArray, index));
	$System::arraycopy(temp, 0, result, 0, index);
	return result;
}

int32_t Pattern::getClass(int32_t c) {
	$init(Pattern);
	return $1Normalizer::getCombiningClass(c);
}

$String* Pattern::composeOneStep($String* input) {
	$init(Pattern);
	$useLocalCurrentObjectStackCache();
	int32_t len = countChars(input, 0, 2);
	$var($String, firstTwoCharacters, $nc(input)->substring(0, len));
	$init($Normalizer$Form);
	$var($String, result, $Normalizer::normalize(firstTwoCharacters, $Normalizer$Form::NFC));
	if ($nc(result)->equals(firstTwoCharacters)) {
		return nullptr;
	} else {
		$var($String, remainder, input->substring(len));
		return $str({result, remainder});
	}
}

void Pattern::RemoveQEQuoting() {
	int32_t pLen = this->patternLength;
	int32_t i = 0;
	while (i < pLen - 1) {
		if ($nc(this->temp)->get(i) != u'\\') {
			i += 1;
		} else if ($nc(this->temp)->get(i + 1) != u'Q') {
			i += 2;
		} else {
			break;
		}
	}
	if (i >= pLen - 1) {
		return;
	}
	int32_t j = i;
	i += 2;
	int32_t newTempLen = 0;
	try {
		newTempLen = $Math::addExact(j + 2, $Math::multiplyExact(3, pLen - i));
	} catch ($ArithmeticException& ae) {
		$throwNew($OutOfMemoryError, "Required pattern length too large"_s);
	}
	$var($ints, newtemp, $new($ints, newTempLen));
	$System::arraycopy(this->temp, 0, newtemp, 0, j);
	bool inQuote = true;
	bool beginQuote = true;
	while (i < pLen) {
		int32_t c = $nc(this->temp)->get(i++);
		bool var$0 = !$ASCII::isAscii(c);
		if (var$0 || $ASCII::isAlpha(c)) {
			newtemp->set(j++, c);
		} else if ($ASCII::isDigit(c)) {
			if (beginQuote) {
				newtemp->set(j++, u'\\');
				newtemp->set(j++, u'x');
				newtemp->set(j++, u'3');
			}
			newtemp->set(j++, c);
		} else if (c != u'\\') {
			if (inQuote) {
				newtemp->set(j++, u'\\');
			}
			newtemp->set(j++, c);
		} else if (inQuote) {
			if ($nc(this->temp)->get(i) == u'E') {
				++i;
				inQuote = false;
			} else {
				newtemp->set(j++, u'\\');
				newtemp->set(j++, u'\\');
			}
		} else if ($nc(this->temp)->get(i) == u'Q') {
			++i;
			inQuote = true;
			beginQuote = true;
			continue;
		} else {
			newtemp->set(j++, c);
			if (i != pLen) {
				newtemp->set(j++, $nc(this->temp)->get(i++));
			}
		}
		beginQuote = false;
	}
	this->patternLength = j;
	$set(this, temp, $Arrays::copyOf(newtemp, j + 2));
}

void Pattern::compile() {
	$useLocalCurrentObjectStackCache();
	bool var$0 = has(Pattern::CANON_EQ);
	if (var$0 && !has(Pattern::LITERAL)) {
		$set(this, normalizedPattern, normalize(this->pattern$));
	} else {
		$set(this, normalizedPattern, this->pattern$);
	}
	this->patternLength = $nc(this->normalizedPattern)->length();
	$set(this, temp, $new($ints, this->patternLength + 2));
	this->hasSupplementary = false;
	int32_t c = 0;
	int32_t count = 0;
	for (int32_t x = 0; x < this->patternLength; x += $Character::charCount(c)) {
		c = $nc(this->normalizedPattern)->codePointAt(x);
		if (isSupplementary(c)) {
			this->hasSupplementary = true;
		}
		$nc(this->temp)->set(count++, c);
	}
	this->patternLength = count;
	if (!has(Pattern::LITERAL)) {
		RemoveQEQuoting();
	}
	$set(this, buffer, $new($ints, 32));
	$set(this, groupNodes, $new($Pattern$GroupHeadArray, 10));
	$set(this, namedGroups$, nullptr);
	$set(this, topClosureNodes, $new($ArrayList, 10));
	if (has(Pattern::LITERAL)) {
		$set(this, matchRoot, newSlice(this->temp, this->patternLength, this->hasSupplementary));
		$set($nc(this->matchRoot), next, Pattern::lastAccept);
	} else {
		$set(this, matchRoot, expr(Pattern::lastAccept));
		if (this->patternLength != this->cursor$) {
			if (peek() == u')') {
				$throw($(error("Unmatched closing \')\'"_s)));
			} else {
				$throw($(error("Unexpected internal error"_s)));
			}
		}
	}
	if ($instanceOf($Pattern$Slice, this->matchRoot)) {
		$set(this, root, $Pattern$BnM::optimize(this->matchRoot));
		if (this->root == this->matchRoot) {
			$set(this, root, this->hasSupplementary ? static_cast<$Pattern$Node*>($new($Pattern$StartS, this->matchRoot)) : static_cast<$Pattern$Node*>($new($Pattern$Start, this->matchRoot)));
		}
	} else if ($instanceOf($Pattern$Begin, this->matchRoot) || $instanceOf($Pattern$First, this->matchRoot)) {
		$set(this, root, this->matchRoot);
	} else {
		$set(this, root, this->hasSupplementary ? static_cast<$Pattern$Node*>($new($Pattern$StartS, this->matchRoot)) : static_cast<$Pattern$Node*>($new($Pattern$Start, this->matchRoot)));
	}
	if (!this->hasGroupRef) {
		{
			$var($Iterator, i$, $nc(this->topClosureNodes)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Pattern$Node, node, $cast($Pattern$Node, i$->next()));
				{
					if ($instanceOf($Pattern$Loop, node)) {
						$nc(($cast($Pattern$Loop, node)))->posIndex = this->localTCNCount++;
					}
				}
			}
		}
	}
	$set(this, temp, nullptr);
	$set(this, buffer, nullptr);
	$set(this, groupNodes, nullptr);
	this->patternLength = 0;
	this->compiled = true;
	$set(this, topClosureNodes, nullptr);
}

$Map* Pattern::namedGroups() {
	$var($Map, groups, this->namedGroups$);
	if (groups == nullptr) {
		$set(this, namedGroups$, ($assign(groups, $new($HashMap, 2))));
	}
	return groups;
}

bool Pattern::has(int32_t f) {
	return ((int32_t)(this->flags0 & (uint32_t)f)) != 0;
}

void Pattern::accept(int32_t ch, $String* s) {
	int32_t testChar = $nc(this->temp)->get(this->cursor$++);
	if (has(Pattern::COMMENTS)) {
		testChar = parsePastWhitespace(testChar);
	}
	if (ch != testChar) {
		$throw($(error(s)));
	}
}

void Pattern::mark(int32_t c) {
	$nc(this->temp)->set(this->patternLength, c);
}

int32_t Pattern::peek() {
	int32_t ch = $nc(this->temp)->get(this->cursor$);
	if (has(Pattern::COMMENTS)) {
		ch = peekPastWhitespace(ch);
	}
	return ch;
}

int32_t Pattern::read() {
	int32_t ch = $nc(this->temp)->get(this->cursor$++);
	if (has(Pattern::COMMENTS)) {
		ch = parsePastWhitespace(ch);
	}
	return ch;
}

int32_t Pattern::readEscaped() {
	int32_t ch = $nc(this->temp)->get(this->cursor$++);
	return ch;
}

int32_t Pattern::next() {
	int32_t ch = $nc(this->temp)->get(++this->cursor$);
	if (has(Pattern::COMMENTS)) {
		ch = peekPastWhitespace(ch);
	}
	return ch;
}

int32_t Pattern::nextEscaped() {
	int32_t ch = $nc(this->temp)->get(++this->cursor$);
	return ch;
}

int32_t Pattern::peekPastWhitespace(int32_t ch) {
	while ($ASCII::isSpace(ch) || ch == u'#') {
		while ($ASCII::isSpace(ch)) {
			ch = $nc(this->temp)->get(++this->cursor$);
		}
		if (ch == u'#') {
			ch = peekPastLine();
		}
	}
	return ch;
}

int32_t Pattern::parsePastWhitespace(int32_t ch) {
	while ($ASCII::isSpace(ch) || ch == u'#') {
		while ($ASCII::isSpace(ch)) {
			ch = $nc(this->temp)->get(this->cursor$++);
		}
		if (ch == u'#') {
			ch = parsePastLine();
		}
	}
	return ch;
}

int32_t Pattern::parsePastLine() {
	int32_t ch = $nc(this->temp)->get(this->cursor$++);
	while (ch != 0 && !isLineSeparator(ch)) {
		ch = $nc(this->temp)->get(this->cursor$++);
	}
	if (ch == 0 && this->cursor$ > this->patternLength) {
		this->cursor$ = this->patternLength;
		ch = $nc(this->temp)->get(this->cursor$++);
	}
	return ch;
}

int32_t Pattern::peekPastLine() {
	int32_t ch = $nc(this->temp)->get(++this->cursor$);
	while (ch != 0 && !isLineSeparator(ch)) {
		ch = $nc(this->temp)->get(++this->cursor$);
	}
	if (ch == 0 && this->cursor$ > this->patternLength) {
		this->cursor$ = this->patternLength;
		ch = $nc(this->temp)->get(this->cursor$);
	}
	return ch;
}

bool Pattern::isLineSeparator(int32_t ch) {
	if (has(Pattern::UNIX_LINES)) {
		return ch == u'\n';
	} else {
		return (ch == u'\n' || ch == u'\r' || (ch | 1) == (char16_t)0x2029 || ch == (char16_t)0x85);
	}
}

int32_t Pattern::skip() {
	int32_t i = this->cursor$;
	int32_t ch = $nc(this->temp)->get(i + 1);
	this->cursor$ = i + 2;
	return ch;
}

void Pattern::unread() {
	--this->cursor$;
}

$PatternSyntaxException* Pattern::error($String* s) {
	return $new($PatternSyntaxException, s, this->normalizedPattern, this->cursor$ - 1);
}

bool Pattern::findSupplementary(int32_t start, int32_t end) {
	for (int32_t i = start; i < end; ++i) {
		if (isSupplementary($nc(this->temp)->get(i))) {
			return true;
		}
	}
	return false;
}

bool Pattern::isSupplementary(int32_t ch) {
	$init(Pattern);
	return ch >= $Character::MIN_SUPPLEMENTARY_CODE_POINT || $Character::isSurrogate((char16_t)ch);
}

$Pattern$Node* Pattern::expr($Pattern$Node* end) {
	$useLocalCurrentObjectStackCache();
	$var($Pattern$Node, prev, nullptr);
	$var($Pattern$Node, firstTail, nullptr);
	$var($Pattern$Branch, branch, nullptr);
	$var($Pattern$Node, branchConn, nullptr);
	for (;;) {
		$var($Pattern$Node, node, sequence(end));
		$var($Pattern$Node, nodeTail, this->root);
		if (prev == nullptr) {
			$assign(prev, node);
			$assign(firstTail, nodeTail);
		} else {
			if (branchConn == nullptr) {
				$assign(branchConn, $new($Pattern$BranchConn));
				$set(branchConn, next, end);
			}
			if (node == end) {
				$assign(node, nullptr);
			} else {
				$set($nc(nodeTail), next, branchConn);
			}
			if ($equals(prev, branch)) {
				$nc(branch)->add(node);
			} else {
				if (prev == end) {
					$assign(prev, nullptr);
				} else {
					$set($nc(firstTail), next, branchConn);
				}
				$assign(prev, ($assign(branch, $new($Pattern$Branch, prev, node, branchConn))));
			}
		}
		if (peek() != u'|') {
			return prev;
		}
		next();
	}
}

$Pattern$Node* Pattern::sequence($Pattern$Node* end) {
	$useLocalCurrentObjectStackCache();
	$var($Pattern$Node, head, nullptr);
	$var($Pattern$Node, tail, nullptr);
	$var($Pattern$Node, node, nullptr);
	bool LOOP$break = false;
	for (;;) {
		int32_t ch = peek();
		switch (ch) {
		case u'(':
			{
				$assign(node, group0());
				if (node == nullptr) {
					continue;
				}
				if (head == nullptr) {
					$assign(head, node);
				} else {
					$set($nc(tail), next, node);
				}
				$assign(tail, this->root);
				continue;
			}
		case u'[':
			{
				bool var$0 = has(Pattern::CANON_EQ);
				if (var$0 && !has(Pattern::LITERAL)) {
					$assign(node, $new($Pattern$NFCCharProperty, $(clazz(true))));
				} else {
					$assign(node, newCharProperty($(clazz(true))));
				}
				break;
			}
		case u'\\':
			{
				ch = nextEscaped();
				if (ch == u'p' || ch == u'P') {
					bool oneLetter = true;
					bool comp = (ch == u'P');
					ch = next();
					if (ch != u'{') {
						unread();
					} else {
						oneLetter = false;
					}
					bool var$1 = has(Pattern::CANON_EQ);
					if (var$1 && !has(Pattern::LITERAL)) {
						$assign(node, $new($Pattern$NFCCharProperty, $(family(oneLetter, comp))));
					} else {
						$assign(node, newCharProperty($(family(oneLetter, comp))));
					}
				} else {
					unread();
					$assign(node, atom());
				}
				break;
			}
		case u'^':
			{
				next();
				if (has(Pattern::MULTILINE)) {
					if (has(Pattern::UNIX_LINES)) {
						$assign(node, $new($Pattern$UnixCaret));
					} else {
						$assign(node, $new($Pattern$Caret));
					}
				} else {
					$assign(node, $new($Pattern$Begin));
				}
				break;
			}
		case u'$':
			{
				next();
				if (has(Pattern::UNIX_LINES)) {
					$assign(node, $new($Pattern$UnixDollar, has(Pattern::MULTILINE)));
				} else {
					$assign(node, $new($Pattern$Dollar, has(Pattern::MULTILINE)));
				}
				break;
			}
		case u'.':
			{
				next();
				if (has(Pattern::DOTALL)) {
					$assign(node, $new($Pattern$CharProperty, $(ALL())));
				} else if (has(Pattern::UNIX_LINES)) {
					$assign(node, $new($Pattern$CharProperty, $(UNIXDOT())));
				} else {
					$assign(node, $new($Pattern$CharProperty, $(DOT())));
				}
				break;
			}
		case u'|':
			{}
		case u')':
			{
				LOOP$break = true;
				break;
			}
		case u']':
			{}
		case u'}':
			{
				$assign(node, atom());
				break;
			}
		case u'?':
			{}
		case u'*':
			{}
		case u'+':
			{
				next();
				$throw($(error($$str({"Dangling meta character \'"_s, $$str(((char16_t)ch)), "\'"_s}))));
			}
		case 0:
			{
				if (this->cursor$ >= this->patternLength) {
					LOOP$break = true;
					break;
				}
			}
		default:
			{
				$assign(node, atom());
				break;
			}
		}

		if (LOOP$break) {
			break;
		}		$assign(node, closure(node));
		if (head == nullptr) {
			$assign(head, ($assign(tail, node)));
		} else {
			$set($nc(tail), next, node);
			$assign(tail, node);
		}
	}
	if (head == nullptr) {
		return end;
	}
	$set($nc(tail), next, end);
	$set(this, root, tail);
	return head;
}

$Pattern$Node* Pattern::atom() {
	$useLocalCurrentObjectStackCache();
	int32_t first = 0;
	int32_t prev = -1;
	bool hasSupplementary = false;
	int32_t ch = peek();
	for (;;) {
		switch (ch) {
		case u'*':
			{}
		case u'+':
			{}
		case u'?':
			{}
		case u'{':
			{
				if (first > 1) {
					this->cursor$ = prev;
					--first;
				}
				break;
			}
		case u'$':
			{}
		case u'.':
			{}
		case u'^':
			{}
		case u'(':
			{}
		case u'[':
			{}
		case u'|':
			{}
		case u')':
			{
				break;
			}
		case u'\\':
			{
				ch = nextEscaped();
				if (ch == u'p' || ch == u'P') {
					if (first > 0) {
						unread();
						break;
					} else {
						bool comp = (ch == u'P');
						bool oneLetter = true;
						ch = next();
						if (ch != u'{') {
							unread();
						} else {
							oneLetter = false;
						}
						bool var$0 = has(Pattern::CANON_EQ);
						if (var$0 && !has(Pattern::LITERAL)) {
							return $new($Pattern$NFCCharProperty, $(family(oneLetter, comp)));
						} else {
							return newCharProperty($(family(oneLetter, comp)));
						}
					}
				}
				unread();
				prev = this->cursor$;
				ch = escape(false, first == 0, false);
				if (ch >= 0) {
					append(ch, first);
					++first;
					if (isSupplementary(ch)) {
						hasSupplementary = true;
					}
					ch = peek();
					continue;
				} else if (first == 0) {
					return this->root;
				}
				this->cursor$ = prev;
				break;
			}
		case 0:
			{
				if (this->cursor$ >= this->patternLength) {
					break;
				}
			}
		default:
			{
				prev = this->cursor$;
				append(ch, first);
				++first;
				if (isSupplementary(ch)) {
					hasSupplementary = true;
				}
				ch = next();
				continue;
			}
		}
		break;
	}
	if (first == 1) {
		return newCharProperty($(single($nc(this->buffer)->get(0))));
	} else {
		return newSlice(this->buffer, first, hasSupplementary);
	}
}

void Pattern::append(int32_t ch, int32_t index) {
	int32_t len = $nc(this->buffer)->length;
	if (index - len >= 0) {
		len = $ArraysSupport::newLength(len, 1 + index - len, len);
		$set(this, buffer, $Arrays::copyOf(this->buffer, len));
	}
	$nc(this->buffer)->set(index, ch);
}

$Pattern$Node* Pattern::ref(int32_t refNum) {
	bool done = false;
	while (!done) {
		int32_t ch = peek();
		switch (ch) {
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
			{}
		case u'8':
			{}
		case u'9':
			{
				{
					int32_t newRefNum = (refNum * 10) + (ch - u'0');
					if (this->capturingGroupCount - 1 < newRefNum) {
						done = true;
						break;
					}
					refNum = newRefNum;
					read();
				}
				break;
			}
		default:
			{
				done = true;
				break;
			}
		}
	}
	this->hasGroupRef = true;
	if (has(Pattern::CASE_INSENSITIVE)) {
		return $new($Pattern$CIBackRef, refNum, has(Pattern::UNICODE_CASE));
	} else {
		return $new($Pattern$BackRef, refNum);
	}
}

int32_t Pattern::escape(bool inclass, bool create, bool isrange) {
	$useLocalCurrentObjectStackCache();
	int32_t ch = skip();
	{
		$var($String, name, nullptr)
		switch (ch) {
		case u'0':
			{
				return o();
			}
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
			{}
		case u'8':
			{}
		case u'9':
			{
				if (inclass) {
					break;
				}
				if (create) {
					$set(this, root, ref((ch - u'0')));
				}
				return -1;
			}
		case u'A':
			{
				if (inclass) {
					break;
				}
				if (create) {
					$set(this, root, $new($Pattern$Begin));
				}
				return -1;
			}
		case u'B':
			{
				if (inclass) {
					break;
				}
				if (create) {
					$init($Pattern$Bound);
					$set(this, root, $new($Pattern$Bound, $Pattern$Bound::NONE, has(Pattern::UNICODE_CHARACTER_CLASS)));
				}
				return -1;
			}
		case u'C':
			{
				break;
			}
		case u'D':
			{
				if (create) {
					$set(this, predicate, has(Pattern::UNICODE_CHARACTER_CLASS) ? $CharPredicates::DIGIT() : static_cast<$Pattern$CharPredicate*>($CharPredicates::ASCII_DIGIT()));
					$set(this, predicate, $nc(this->predicate)->negate());
					if (!inclass) {
						$set(this, root, newCharProperty(this->predicate));
					}
				}
				return -1;
			}
		case u'E':
			{}
		case u'F':
			{
				break;
			}
		case u'G':
			{
				if (inclass) {
					break;
				}
				if (create) {
					$set(this, root, $new($Pattern$LastMatch));
				}
				return -1;
			}
		case u'H':
			{
				if (create) {
					$set(this, predicate, $nc($(HorizWS()))->negate());
					if (!inclass) {
						$set(this, root, newCharProperty(this->predicate));
					}
				}
				return -1;
			}
		case u'I':
			{}
		case u'J':
			{}
		case u'K':
			{}
		case u'L':
			{}
		case u'M':
			{
				break;
			}
		case u'N':
			{
				return N();
			}
		case u'O':
			{}
		case u'P':
			{}
		case u'Q':
			{
				break;
			}
		case u'R':
			{
				if (inclass) {
					break;
				}
				if (create) {
					$set(this, root, $new($Pattern$LineEnding));
				}
				return -1;
			}
		case u'S':
			{
				if (create) {
					$set(this, predicate, has(Pattern::UNICODE_CHARACTER_CLASS) ? $CharPredicates::WHITE_SPACE() : static_cast<$Pattern$CharPredicate*>($CharPredicates::ASCII_SPACE()));
					$set(this, predicate, $nc(this->predicate)->negate());
					if (!inclass) {
						$set(this, root, newCharProperty(this->predicate));
					}
				}
				return -1;
			}
		case u'T':
			{}
		case u'U':
			{
				break;
			}
		case u'V':
			{
				if (create) {
					$set(this, predicate, $nc($(VertWS()))->negate());
					if (!inclass) {
						$set(this, root, newCharProperty(this->predicate));
					}
				}
				return -1;
			}
		case u'W':
			{
				if (create) {
					$set(this, predicate, has(Pattern::UNICODE_CHARACTER_CLASS) ? $CharPredicates::WORD() : static_cast<$Pattern$CharPredicate*>($CharPredicates::ASCII_WORD()));
					$set(this, predicate, $nc(this->predicate)->negate());
					if (!inclass) {
						$set(this, root, newCharProperty(this->predicate));
					}
				}
				return -1;
			}
		case u'X':
			{
				if (inclass) {
					break;
				}
				if (create) {
					$set(this, root, $new($Pattern$XGrapheme));
				}
				return -1;
			}
		case u'Y':
			{
				break;
			}
		case u'Z':
			{
				if (inclass) {
					break;
				}
				if (create) {
					if (has(Pattern::UNIX_LINES)) {
						$set(this, root, $new($Pattern$UnixDollar, false));
					} else {
						$set(this, root, $new($Pattern$Dollar, false));
					}
				}
				return -1;
			}
		case u'a':
			{
				return (char16_t)0x7;
			}
		case u'b':
			{
				if (inclass) {
					break;
				}
				if (create) {
					if (peek() == u'{') {
						if (skip() == u'g') {
							if (read() == u'}') {
								$set(this, root, $new($Pattern$GraphemeBound));
								return -1;
							}
							break;
						}
						unread();
						unread();
					}
					$init($Pattern$Bound);
					$set(this, root, $new($Pattern$Bound, $Pattern$Bound::BOTH, has(Pattern::UNICODE_CHARACTER_CLASS)));
				}
				return -1;
			}
		case u'c':
			{
				return c();
			}
		case u'd':
			{
				if (create) {
					$set(this, predicate, has(Pattern::UNICODE_CHARACTER_CLASS) ? $CharPredicates::DIGIT() : static_cast<$Pattern$CharPredicate*>($CharPredicates::ASCII_DIGIT()));
					if (!inclass) {
						$set(this, root, newCharProperty(this->predicate));
					}
				}
				return -1;
			}
		case u'e':
			{
				return (char16_t)0x1B;
			}
		case u'f':
			{
				return u'\f';
			}
		case u'g':
			{
				break;
			}
		case u'h':
			{
				if (create) {
					$set(this, predicate, HorizWS());
					if (!inclass) {
						$set(this, root, newCharProperty(this->predicate));
					}
				}
				return -1;
			}
		case u'i':
			{}
		case u'j':
			{
				break;
			}
		case u'k':
			{
				if (inclass) {
					break;
				}
				if (read() != u'<') {
					$throw($(error("\\k is not followed by \'<\' for named capturing group"_s)));
				}
				$assign(name, groupname(read()));
				if (!$nc($(namedGroups()))->containsKey(name)) {
					$throw($(error($$str({"named capturing group <"_s, name, "> does not exist"_s}))));
				}
				if (create) {
					this->hasGroupRef = true;
					if (has(Pattern::CASE_INSENSITIVE)) {
						int32_t var$0 = $nc(($cast($Integer, $($nc($(namedGroups()))->get(name)))))->intValue();
						$set(this, root, $new($Pattern$CIBackRef, var$0, has(Pattern::UNICODE_CASE)));
					} else {
						$set(this, root, $new($Pattern$BackRef, $nc(($cast($Integer, $($nc($(namedGroups()))->get(name)))))->intValue()));
					}
				}
				return -1;
			}
		case u'l':
			{}
		case u'm':
			{
				break;
			}
		case u'n':
			{
				return u'\n';
			}
		case u'o':
			{}
		case u'p':
			{}
		case u'q':
			{
				break;
			}
		case u'r':
			{
				return u'\r';
			}
		case u's':
			{
				if (create) {
					$set(this, predicate, has(Pattern::UNICODE_CHARACTER_CLASS) ? $CharPredicates::WHITE_SPACE() : static_cast<$Pattern$CharPredicate*>($CharPredicates::ASCII_SPACE()));
					if (!inclass) {
						$set(this, root, newCharProperty(this->predicate));
					}
				}
				return -1;
			}
		case u't':
			{
				return u'\t';
			}
		case u'u':
			{
				return u();
			}
		case u'v':
			{
				if (isrange) {
					return (char16_t)0xB;
				}
				if (create) {
					$set(this, predicate, VertWS());
					if (!inclass) {
						$set(this, root, newCharProperty(this->predicate));
					}
				}
				return -1;
			}
		case u'w':
			{
				if (create) {
					$set(this, predicate, has(Pattern::UNICODE_CHARACTER_CLASS) ? $CharPredicates::WORD() : static_cast<$Pattern$CharPredicate*>($CharPredicates::ASCII_WORD()));
					if (!inclass) {
						$set(this, root, newCharProperty(this->predicate));
					}
				}
				return -1;
			}
		case u'x':
			{
				return x();
			}
		case u'y':
			{
				break;
			}
		case u'z':
			{
				if (inclass) {
					break;
				}
				if (create) {
					$set(this, root, $new($Pattern$End));
				}
				return -1;
			}
		default:
			{
				return ch;
			}
		}
	}
	$throw($(error("Illegal/unsupported escape sequence"_s)));
}

$Pattern$CharPredicate* Pattern::clazz(bool consume) {
	$useLocalCurrentObjectStackCache();
	$var($Pattern$CharPredicate, prev, nullptr);
	$var($Pattern$CharPredicate, curr, nullptr);
	$var($Pattern$BitClass, bits, $new($Pattern$BitClass));
	bool isNeg = false;
	bool hasBits = false;
	int32_t ch = next();
	if (ch == u'^' && $nc(this->temp)->get(this->cursor$ - 1) == u'[') {
		ch = next();
		isNeg = true;
	}
	for (;;) {
		switch (ch) {
		case u'[':
			{
				$assign(curr, clazz(true));
				if (prev == nullptr) {
					$assign(prev, curr);
				} else {
					$assign(prev, $nc(prev)->union$(curr));
				}
				ch = peek();
				continue;
			}
		case u'&':
			{
				ch = next();
				if (ch == u'&') {
					ch = next();
					$var($Pattern$CharPredicate, right, nullptr);
					while (ch != u']' && ch != u'&') {
						if (ch == u'[') {
							if (right == nullptr) {
								$assign(right, clazz(true));
							} else {
								$assign(right, $nc(right)->union$($(clazz(true))));
							}
						} else {
							unread();
							if (right == nullptr) {
								$assign(right, clazz(false));
							} else {
								$assign(right, $nc(right)->union$($(clazz(false))));
							}
						}
						ch = peek();
					}
					if (hasBits) {
						if (prev == nullptr) {
							$assign(prev, ($assign(curr, bits)));
						} else {
							$assign(prev, $nc(prev)->union$(bits));
						}
						hasBits = false;
					}
					if (right != nullptr) {
						$assign(curr, right);
					}
					if (prev == nullptr) {
						if (right == nullptr) {
							$throw($(error("Bad class syntax"_s)));
						} else {
							$assign(prev, right);
						}
					} else {
						$assign(prev, $nc(prev)->and$(curr));
					}
				} else {
					unread();
					break;
				}
				continue;
			}
		case 0:
			{
				if (this->cursor$ >= this->patternLength) {
					$throw($(error("Unclosed character class"_s)));
				}
				break;
			}
		case u']':
			{
				if (prev != nullptr || hasBits) {
					if (consume) {
						next();
					}
					if (prev == nullptr) {
						$assign(prev, bits);
					} else if (hasBits) {
						$assign(prev, $nc(prev)->union$(bits));
					}
					if (isNeg) {
						return $nc(prev)->negate();
					}
					return prev;
				}
				break;
			}
		default:
			{
				break;
			}
		}
		$assign(curr, range(bits));
		if (curr == nullptr) {
			hasBits = true;
		} else if (prev == nullptr) {
			$assign(prev, curr);
		} else if (prev != curr) {
			$assign(prev, $nc(prev)->union$(curr));
		}
		ch = peek();
	}
}

$Pattern$CharPredicate* Pattern::bitsOrSingle($Pattern$BitClass* bits, int32_t ch) {
	bool var$0 = ch < 256;
	if (var$0) {
		bool var$1 = has(Pattern::CASE_INSENSITIVE);
		var$0 = !(var$1 && has(Pattern::UNICODE_CASE) && (ch == 255 || ch == 181 || ch == 73 || ch == 105 || ch == 83 || ch == 115 || ch == 75 || ch == 107 || ch == 197 || ch == 229));
	}
	if (var$0) {
		$nc(bits)->add(ch, this->flags0);
		return nullptr;
	}
	return single(ch);
}

$Pattern$CharPredicate* Pattern::single(int32_t ch) {
	if (has(Pattern::CASE_INSENSITIVE)) {
		int32_t lower = 0;
		int32_t upper = 0;
		if (has(Pattern::UNICODE_CASE)) {
			upper = $Character::toUpperCase(ch);
			lower = $Character::toLowerCase(upper);
			if (upper != lower) {
				return SingleU(lower);
			}
		} else if ($ASCII::isAscii(ch)) {
			lower = $ASCII::toLower(ch);
			upper = $ASCII::toUpper(ch);
			if (lower != upper) {
				return SingleI(lower, upper);
			}
		}
	}
	if (isSupplementary(ch)) {
		return SingleS(ch);
	}
	return Single(ch);
}

$Pattern$CharPredicate* Pattern::range($Pattern$BitClass* bits) {
	$useLocalCurrentObjectStackCache();
	int32_t ch = peek();
	if (ch == u'\\') {
		ch = nextEscaped();
		if (ch == u'p' || ch == u'P') {
			bool comp = (ch == u'P');
			bool oneLetter = true;
			ch = next();
			if (ch != u'{') {
				unread();
			} else {
				oneLetter = false;
			}
			return family(oneLetter, comp);
		} else {
			bool isrange = $nc(this->temp)->get(this->cursor$ + 1) == u'-';
			unread();
			ch = escape(true, true, isrange);
			if (ch == -1) {
				return this->predicate;
			}
		}
	} else {
		next();
	}
	if (ch >= 0) {
		if (peek() == u'-') {
			int32_t endRange = $nc(this->temp)->get(this->cursor$ + 1);
			if (endRange == u'[') {
				return bitsOrSingle(bits, ch);
			}
			if (endRange != u']') {
				next();
				int32_t m = peek();
				if (m == u'\\') {
					m = escape(true, false, true);
				} else {
					next();
				}
				if (m < ch) {
					$throw($(error("Illegal character range"_s)));
				}
				if (has(Pattern::CASE_INSENSITIVE)) {
					if (has(Pattern::UNICODE_CASE)) {
						return CIRangeU(ch, m);
					}
					return CIRange(ch, m);
				} else {
					return Range(ch, m);
				}
			}
		}
		return bitsOrSingle(bits, ch);
	}
	$throw($(error($$str({"Unexpected character \'"_s, $$str(((char16_t)ch)), "\'"_s}))));
}

$Pattern$CharPredicate* Pattern::family(bool singleLetter, bool isComplement) {
	$useLocalCurrentObjectStackCache();
	next();
	$var($String, name, nullptr);
	$var($Pattern$CharPredicate, p, nullptr);
	if (singleLetter) {
		int32_t c = $nc(this->temp)->get(this->cursor$);
		if (!$Character::isSupplementaryCodePoint(c)) {
			$assign(name, $String::valueOf((char16_t)c));
		} else {
			$assign(name, $new($String, this->temp, this->cursor$, 1));
		}
		read();
	} else {
		int32_t i = this->cursor$;
		mark(u'}');
		while (read() != u'}') {
		}
		mark(u'\0');
		int32_t j = this->cursor$;
		if (j > this->patternLength) {
			$throw($(error("Unclosed character family"_s)));
		}
		if (i + 1 >= j) {
			$throw($(error("Empty character family"_s)));
		}
		$assign(name, $new($String, this->temp, i, j - i - 1));
	}
	int32_t i = $nc(name)->indexOf((int32_t)u'=');
	if (i != -1) {
		$var($String, value, name->substring(i + 1));
		$init($Locale);
		$assign(name, $(name->substring(0, i))->toLowerCase($Locale::ENGLISH));
		{
			$var($String, s116648$, name);
			int32_t tmp116648$ = -1;
			switch (s116648$->hashCode()) {
			case 3664:
				{
					if (s116648$->equals("sc"_s)) {
						tmp116648$ = 0;
					}
					break;
				}
			case (int32_t)0xC9E5D0CB:
				{
					if (s116648$->equals("script"_s)) {
						tmp116648$ = 1;
					}
					break;
				}
			case 0x00017D61:
				{
					if (s116648$->equals("blk"_s)) {
						tmp116648$ = 2;
					}
					break;
				}
			case 0x0597C48D:
				{
					if (s116648$->equals("block"_s)) {
						tmp116648$ = 3;
					}
					break;
				}
			case 3292:
				{
					if (s116648$->equals("gc"_s)) {
						tmp116648$ = 4;
					}
					break;
				}
			case 0x4B666A75:
				{
					if (s116648$->equals("general_category"_s)) {
						tmp116648$ = 5;
					}
					break;
				}
			}
			switch (tmp116648$) {
			case 0:
				{}
			case 1:
				{
					$assign(p, $CharPredicates::forUnicodeScript(value));
					break;
				}
			case 2:
				{}
			case 3:
				{
					$assign(p, $CharPredicates::forUnicodeBlock(value));
					break;
				}
			case 4:
				{}
			case 5:
				{
					$assign(p, $CharPredicates::forProperty(value, has(Pattern::CASE_INSENSITIVE)));
					break;
				}
			default:
				{
					break;
				}
			}
		}
		if (p == nullptr) {
			$throw($(error($$str({"Unknown Unicode property {name=<"_s, name, ">, value=<"_s, value, ">}"_s}))));
		}
	} else {
		if (name->startsWith("In"_s)) {
			$assign(p, $CharPredicates::forUnicodeBlock($(name->substring(2))));
		} else if (name->startsWith("Is"_s)) {
			$var($String, shortName, name->substring(2));
			$assign(p, $CharPredicates::forUnicodeProperty(shortName, has(Pattern::CASE_INSENSITIVE)));
			if (p == nullptr) {
				$assign(p, $CharPredicates::forProperty(shortName, has(Pattern::CASE_INSENSITIVE)));
			}
			if (p == nullptr) {
				$assign(p, $CharPredicates::forUnicodeScript(shortName));
			}
		} else {
			if (has(Pattern::UNICODE_CHARACTER_CLASS)) {
				$assign(p, $CharPredicates::forPOSIXName(name, has(Pattern::CASE_INSENSITIVE)));
			}
			if (p == nullptr) {
				$assign(p, $CharPredicates::forProperty(name, has(Pattern::CASE_INSENSITIVE)));
			}
		}
		if (p == nullptr) {
			$throw($(error($$str({"Unknown character property name {"_s, name, "}"_s}))));
		}
	}
	if (isComplement) {
		this->hasSupplementary = true;
		$assign(p, $nc(p)->negate());
	}
	return p;
}

$Pattern$CharProperty* Pattern::newCharProperty($Pattern$CharPredicate* p) {
	if (p == nullptr) {
		return nullptr;
	}
	if ($instanceOf($Pattern$BmpCharPredicate, p)) {
		return $new($Pattern$BmpCharProperty, $cast($Pattern$BmpCharPredicate, p));
	} else {
		this->hasSupplementary = true;
		return $new($Pattern$CharProperty, p);
	}
}

$String* Pattern::groupname(int32_t ch) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	if (!$ASCII::isAlpha(ch)) {
		$throw($(error("capturing group name does not start with a Latin letter"_s)));
	}
	do {
		sb->append((char16_t)ch);
	} while ($ASCII::isAlnum(ch = read()));
	if (ch != u'>') {
		$throw($(error("named capturing group is missing trailing \'>\'"_s)));
	}
	return sb->toString();
}

$Pattern$Node* Pattern::group0() {
	$useLocalCurrentObjectStackCache();
	bool capturingGroup = false;
	$var($Pattern$Node, head, nullptr);
	$var($Pattern$Node, tail, nullptr);
	int32_t save = this->flags0;
	int32_t saveTCNCount = $nc(this->topClosureNodes)->size();
	$set(this, root, nullptr);
	int32_t ch = next();
	if (ch == u'?') {
		ch = skip();
		switch (ch) {
		case u':':
			{
				{
					$assign(head, createGroup(true));
					$assign(tail, this->root);
					$set($nc(head), next, expr(tail));
				}
				break;
			}
		case u'=':
			{}
		case u'!':
			{
				{
					$assign(head, createGroup(true));
					$assign(tail, this->root);
					$set($nc(head), next, expr(tail));
					if (ch == u'=') {
						$assign(head, ($assign(tail, $new($Pattern$Pos, head))));
					} else {
						$assign(head, ($assign(tail, $new($Pattern$Neg, head))));
					}
				}
				break;
			}
		case u'>':
			{
				{
					$assign(head, createGroup(true));
					$assign(tail, this->root);
					$set($nc(head), next, expr(tail));
					$init($Pattern$Qtype);
					$assign(head, ($assign(tail, $new($Pattern$Ques, head, $Pattern$Qtype::INDEPENDENT))));
				}
				break;
			}
		case u'<':
			{
				{
					ch = read();
					if (ch != u'=' && ch != u'!') {
						$var($String, name, groupname(ch));
						if ($nc($(namedGroups()))->containsKey(name)) {
							$throw($(error($$str({"Named capturing group <"_s, name, "> is already defined"_s}))));
						}
						capturingGroup = true;
						$assign(head, createGroup(false));
						$assign(tail, this->root);
						$nc($(namedGroups()))->put(name, $($Integer::valueOf(this->capturingGroupCount - 1)));
						$set($nc(head), next, expr(tail));
						break;
					}
					int32_t start = this->cursor$;
					$assign(head, createGroup(true));
					$assign(tail, this->root);
					$set($nc(head), next, expr(tail));
					$init($Pattern$LookBehindEndNode);
					$set($nc(tail), next, $Pattern$LookBehindEndNode::INSTANCE);
					$var($Pattern$TreeInfo, info, $new($Pattern$TreeInfo));
					head->study(info);
					if (info->maxValid == false) {
						$throw($(error("Look-behind group does not have an obvious maximum length"_s)));
					}
					bool hasSupplementary = findSupplementary(start, this->patternLength);
					if (ch == u'=') {
						$assign(head, ($assign(tail, hasSupplementary ? static_cast<$Pattern$Node*>($new($Pattern$BehindS, head, info->maxLength, info->minLength)) : static_cast<$Pattern$Node*>($new($Pattern$Behind, head, info->maxLength, info->minLength)))));
					} else {
						$assign(head, ($assign(tail, hasSupplementary ? static_cast<$Pattern$Node*>($new($Pattern$NotBehindS, head, info->maxLength, info->minLength)) : static_cast<$Pattern$Node*>($new($Pattern$NotBehind, head, info->maxLength, info->minLength)))));
					}
					if (saveTCNCount < $nc(this->topClosureNodes)->size()) {
						$nc($($nc(this->topClosureNodes)->subList(saveTCNCount, $nc(this->topClosureNodes)->size())))->clear();
					}
				}
				break;
			}
		case u'$':
			{}
		case u'@':
			{
				$throw($(error("Unknown group type"_s)));
			}
		default:
			{
				{
					unread();
					addFlag();
					ch = read();
					if (ch == u')') {
						return nullptr;
					}
					if (ch != u':') {
						$throw($(error("Unknown inline modifier"_s)));
					}
					$assign(head, createGroup(true));
					$assign(tail, this->root);
					$set($nc(head), next, expr(tail));
				}
				break;
			}
		}
	} else {
		capturingGroup = true;
		$assign(head, createGroup(false));
		$assign(tail, this->root);
		$set($nc(head), next, expr(tail));
	}
	accept(u')', "Unclosed group"_s);
	this->flags0 = save;
	$var($Pattern$Node, node, closure(head));
	if (node == head) {
		$set(this, root, tail);
		return node;
	}
	if (head == tail) {
		$set(this, root, node);
		return node;
	}
	if (saveTCNCount < $nc(this->topClosureNodes)->size()) {
		$nc($($nc(this->topClosureNodes)->subList(saveTCNCount, $nc(this->topClosureNodes)->size())))->clear();
	}
	{
		$var($Pattern$Ques, ques, nullptr);
		$var($Pattern$Curly, curly, nullptr);
		bool var$0 = $instanceOf($Pattern$Ques, node);
		if (var$0) {
			$assign(ques, $cast($Pattern$Ques, node));
			var$0 = true;
		}
		if (var$0) {
			$init($Pattern$Qtype);
			if ($nc(ques)->type == $Pattern$Qtype::POSSESSIVE) {
				$set(this, root, node);
				return node;
			}
			$set($nc(tail), next, $new($Pattern$BranchConn));
			$assign(tail, tail->next);
			if ($nc(ques)->type == $Pattern$Qtype::GREEDY) {
				$assign(head, $new($Pattern$Branch, head, nullptr, tail));
			} else {
				$assign(head, $new($Pattern$Branch, nullptr, head, tail));
			}
			$set(this, root, tail);
			return head;
		} else {
			bool var$2 = $instanceOf($Pattern$Curly, node);
			if (var$2) {
				$assign(curly, $cast($Pattern$Curly, node));
				var$2 = true;
			}
			if (var$2) {
				$init($Pattern$Qtype);
				if ($nc(curly)->type == $Pattern$Qtype::POSSESSIVE) {
					$set(this, root, node);
					return node;
				}
				$var($Pattern$TreeInfo, info, $new($Pattern$TreeInfo));
				if ($nc(head)->study(info)) {
					$var($Pattern$GroupTail, temp, $cast($Pattern$GroupTail, tail));
					$assign(head, ($set(this, root, $new($Pattern$GroupCurly, head->next, $nc(curly)->cmin, curly->cmax, curly->type, $nc(($cast($Pattern$GroupTail, tail)))->localIndex, $nc(($cast($Pattern$GroupTail, tail)))->groupIndex, capturingGroup))));
					return head;
				} else {
					int32_t temp = $nc(($cast($Pattern$GroupHead, head)))->localIndex;
					$var($Pattern$Loop, loop, nullptr);
					if ($nc(curly)->type == $Pattern$Qtype::GREEDY) {
						$assign(loop, $new($Pattern$Loop, this->localCount, temp));
						if (curly->cmax == Pattern::MAX_REPS) {
							$nc(this->topClosureNodes)->add(loop);
						}
					} else {
						$assign(loop, $new($Pattern$LazyLoop, this->localCount, temp));
					}
					$var($Pattern$Prolog, prolog, $new($Pattern$Prolog, loop));
					this->localCount += 1;
					$nc(loop)->cmin = $nc(curly)->cmin;
					loop->cmax = curly->cmax;
					$set(loop, body, head);
					$set($nc(tail), next, loop);
					$set(this, root, loop);
					return prolog;
				}
			}
		}
	}
	$throw($(error("Internal logic error"_s)));
}

$Pattern$Node* Pattern::createGroup(bool anonymous) {
	int32_t localIndex = this->localCount++;
	int32_t groupIndex = 0;
	if (!anonymous) {
		groupIndex = this->capturingGroupCount++;
	}
	$var($Pattern$GroupHead, head, $new($Pattern$GroupHead, localIndex));
	$set(this, root, $new($Pattern$GroupTail, localIndex, groupIndex));
	$set(head, tail, $cast($Pattern$GroupTail, this->root));
	if (!anonymous && groupIndex < 10) {
		$nc(this->groupNodes)->set(groupIndex, head);
	}
	return head;
}

void Pattern::addFlag() {
	int32_t ch = peek();
	for (;;) {
		switch (ch) {
		case u'i':
			{
				this->flags0 |= Pattern::CASE_INSENSITIVE;
				break;
			}
		case u'm':
			{
				this->flags0 |= Pattern::MULTILINE;
				break;
			}
		case u's':
			{
				this->flags0 |= Pattern::DOTALL;
				break;
			}
		case u'd':
			{
				this->flags0 |= Pattern::UNIX_LINES;
				break;
			}
		case u'u':
			{
				this->flags0 |= Pattern::UNICODE_CASE;
				break;
			}
		case u'c':
			{
				this->flags0 |= Pattern::CANON_EQ;
				break;
			}
		case u'x':
			{
				this->flags0 |= Pattern::COMMENTS;
				break;
			}
		case u'U':
			{
				this->flags0 |= (Pattern::UNICODE_CHARACTER_CLASS | Pattern::UNICODE_CASE);
				break;
			}
		case u'-':
			{
				ch = next();
				subFlag();
			}
		default:
			{
				return;
			}
		}
		ch = next();
	}
}

void Pattern::subFlag() {
	int32_t ch = peek();
	for (;;) {
		switch (ch) {
		case u'i':
			{
				this->flags0 &= (uint32_t)~Pattern::CASE_INSENSITIVE;
				break;
			}
		case u'm':
			{
				this->flags0 &= (uint32_t)~Pattern::MULTILINE;
				break;
			}
		case u's':
			{
				this->flags0 &= (uint32_t)~Pattern::DOTALL;
				break;
			}
		case u'd':
			{
				this->flags0 &= (uint32_t)~Pattern::UNIX_LINES;
				break;
			}
		case u'u':
			{
				this->flags0 &= (uint32_t)~Pattern::UNICODE_CASE;
				break;
			}
		case u'c':
			{
				this->flags0 &= (uint32_t)~Pattern::CANON_EQ;
				break;
			}
		case u'x':
			{
				this->flags0 &= (uint32_t)~Pattern::COMMENTS;
				break;
			}
		case u'U':
			{
				this->flags0 &= (uint32_t)~(Pattern::UNICODE_CHARACTER_CLASS | Pattern::UNICODE_CASE);
				break;
			}
		default:
			{
				return;
			}
		}
		ch = next();
	}
}

$Pattern$Qtype* Pattern::qtype() {
	int32_t ch = next();
	if (ch == u'?') {
		next();
		$init($Pattern$Qtype);
		return $Pattern$Qtype::LAZY;
	} else if (ch == u'+') {
		next();
		$init($Pattern$Qtype);
		return $Pattern$Qtype::POSSESSIVE;
	}
	$init($Pattern$Qtype);
	return $Pattern$Qtype::GREEDY;
}

$Pattern$Node* Pattern::curly($Pattern$Node* prev, int32_t cmin) {
	$Pattern$Qtype* qtype = this->qtype();
	$init($Pattern$Qtype);
	if (qtype == $Pattern$Qtype::GREEDY) {
		if ($instanceOf($Pattern$BmpCharProperty, prev)) {
			return $new($Pattern$BmpCharPropertyGreedy, $cast($Pattern$BmpCharProperty, prev), cmin);
		} else if ($instanceOf($Pattern$CharProperty, prev)) {
			return $new($Pattern$CharPropertyGreedy, $cast($Pattern$CharProperty, prev), cmin);
		}
	}
	return $new($Pattern$Curly, prev, cmin, Pattern::MAX_REPS, qtype);
}

$Pattern$Node* Pattern::closure($Pattern$Node* prev) {
	$useLocalCurrentObjectStackCache();
	int32_t ch = peek();
	switch (ch) {
	case u'?':
		{
			return $new($Pattern$Ques, prev, $(qtype()));
		}
	case u'*':
		{
			return curly(prev, 0);
		}
	case u'+':
		{
			return curly(prev, 1);
		}
	case u'{':
		{
			ch = skip();
			if ($ASCII::isDigit(ch)) {
				int32_t cmin = 0;
				int32_t cmax = 0;
				try {
					do {
						cmin = $Math::addExact($Math::multiplyExact(cmin, 10), ch - u'0');
					} while ($ASCII::isDigit(ch = read()));
					if (ch == u',') {
						ch = read();
						if (ch == u'}') {
							unread();
							return curly(prev, cmin);
						} else {
							cmax = 0;
							while ($ASCII::isDigit(ch)) {
								cmax = $Math::addExact($Math::multiplyExact(cmax, 10), ch - u'0');
								ch = read();
							}
						}
					} else {
						cmax = cmin;
					}
				} catch ($ArithmeticException& ae) {
					$throw($(error("Illegal repetition range"_s)));
				}
				if (ch != u'}') {
					$throw($(error("Unclosed counted closure"_s)));
				}
				if (cmax < cmin) {
					$throw($(error("Illegal repetition range"_s)));
				}
				unread();
				return (cmin == 0 && cmax == 1) ? static_cast<$Pattern$Node*>($new($Pattern$Ques, prev, $(qtype()))) : static_cast<$Pattern$Node*>($new($Pattern$Curly, prev, cmin, cmax, $(qtype())));
			} else {
				$throw($(error("Illegal repetition"_s)));
			}
		}
	default:
		{
			return prev;
		}
	}
}

int32_t Pattern::c() {
	if (this->cursor$ < this->patternLength) {
		return read() ^ 64;
	}
	$throw($(error("Illegal control escape sequence"_s)));
}

int32_t Pattern::o() {
	int32_t n = read();
	if (((n - u'0') | (u'7' - n)) >= 0) {
		int32_t m = read();
		if (((m - u'0') | (u'7' - m)) >= 0) {
			int32_t o = read();
			if ((((o - u'0') | (u'7' - o)) >= 0) && (((n - u'0') | (u'3' - n)) >= 0)) {
				return (n - u'0') * 64 + (m - u'0') * 8 + (o - u'0');
			}
			unread();
			return (n - u'0') * 8 + (m - u'0');
		}
		unread();
		return (n - u'0');
	}
	$throw($(error("Illegal octal escape sequence"_s)));
}

int32_t Pattern::x() {
	$useLocalCurrentObjectStackCache();
	int32_t n = read();
	if ($ASCII::isHexDigit(n)) {
		int32_t m = read();
		if ($ASCII::isHexDigit(m)) {
			int32_t var$0 = $ASCII::toDigit(n) * 16;
			return var$0 + $ASCII::toDigit(m);
		}
	} else if (n == u'{' && $ASCII::isHexDigit(peek())) {
		int32_t ch = 0;
		while ($ASCII::isHexDigit(n = read())) {
			ch = (ch << 4) + $ASCII::toDigit(n);
			if (ch > $Character::MAX_CODE_POINT) {
				$throw($(error("Hexadecimal codepoint is too big"_s)));
			}
		}
		if (n != u'}') {
			$throw($(error("Unclosed hexadecimal escape sequence"_s)));
		}
		return ch;
	}
	$throw($(error("Illegal hexadecimal escape sequence"_s)));
}

int32_t Pattern::cursor() {
	return this->cursor$;
}

void Pattern::setcursor(int32_t pos) {
	this->cursor$ = pos;
}

int32_t Pattern::uxxxx() {
	$useLocalCurrentObjectStackCache();
	int32_t n = 0;
	for (int32_t i = 0; i < 4; ++i) {
		int32_t ch = read();
		if (!$ASCII::isHexDigit(ch)) {
			$throw($(error("Illegal Unicode escape sequence"_s)));
		}
		n = n * 16 + $ASCII::toDigit(ch);
	}
	return n;
}

int32_t Pattern::u() {
	int32_t n = uxxxx();
	if ($Character::isHighSurrogate((char16_t)n)) {
		int32_t cur = cursor();
		bool var$0 = read() == u'\\';
		if (var$0 && read() == u'u') {
			int32_t n2 = uxxxx();
			if ($Character::isLowSurrogate((char16_t)n2)) {
				return $Character::toCodePoint((char16_t)n, (char16_t)n2);
			}
		}
		setcursor(cur);
	}
	return n;
}

int32_t Pattern::N() {
	$useLocalCurrentObjectStackCache();
	if (read() == u'{') {
		int32_t i = this->cursor$;
		while (read() != u'}') {
			if (this->cursor$ >= this->patternLength) {
				$throw($(error("Unclosed character name escape sequence"_s)));
			}
		}
		$var($String, name, $new($String, this->temp, i, this->cursor$ - i - 1));
		try {
			return $Character::codePointOf(name);
		} catch ($IllegalArgumentException& x) {
			$throw($(error($$str({"Unknown character name ["_s, name, "]"_s}))));
		}
	}
	$throw($(error("Illegal character name escape sequence"_s)));
	$shouldNotReachHere();
}

int32_t Pattern::countChars($CharSequence* seq, int32_t index, int32_t lengthInCodePoints) {
	$init(Pattern);
	if (lengthInCodePoints == 1 && !$Character::isHighSurrogate($nc(seq)->charAt(index))) {
		if (!Pattern::$assertionsDisabled && !(index >= 0 && index < $nc(seq)->length())) {
			$throwNew($AssertionError);
		}
		return 1;
	}
	int32_t length = $nc(seq)->length();
	int32_t x = index;
	if (lengthInCodePoints >= 0) {
		if (!Pattern::$assertionsDisabled && !(index >= 0 && index < length)) {
			$throwNew($AssertionError);
		}
		for (int32_t i = 0; x < length && i < lengthInCodePoints; ++i) {
			if ($Character::isHighSurrogate(seq->charAt(x++))) {
				if (x < length && $Character::isLowSurrogate(seq->charAt(x))) {
					++x;
				}
			}
		}
		return x - index;
	}
	if (!Pattern::$assertionsDisabled && !(index >= 0 && index <= length)) {
		$throwNew($AssertionError);
	}
	if (index == 0) {
		return 0;
	}
	int32_t len = -lengthInCodePoints;
	for (int32_t i = 0; x > 0 && i < len; ++i) {
		if ($Character::isLowSurrogate(seq->charAt(--x))) {
			if (x > 0 && $Character::isHighSurrogate(seq->charAt(x - 1))) {
				--x;
			}
		}
	}
	return index - x;
}

int32_t Pattern::countCodePoints($CharSequence* seq) {
	$init(Pattern);
	int32_t length = $nc(seq)->length();
	int32_t n = 0;
	for (int32_t i = 0; i < length;) {
		++n;
		if ($Character::isHighSurrogate(seq->charAt(i++))) {
			if (i < length && $Character::isLowSurrogate(seq->charAt(i))) {
				++i;
			}
		}
	}
	return n;
}

$Pattern$Node* Pattern::newSlice($ints* buf, int32_t count, bool hasSupplementary) {
	$var($ints, tmp, $new($ints, count));
	if (has(Pattern::CASE_INSENSITIVE)) {
		if (has(Pattern::UNICODE_CASE)) {
			for (int32_t i = 0; i < count; ++i) {
				tmp->set(i, $Character::toLowerCase($Character::toUpperCase($nc(buf)->get(i))));
			}
			return hasSupplementary ? static_cast<$Pattern$Node*>($new($Pattern$SliceUS, tmp)) : static_cast<$Pattern$Node*>($new($Pattern$SliceU, tmp));
		}
		for (int32_t i = 0; i < count; ++i) {
			tmp->set(i, $ASCII::toLower($nc(buf)->get(i)));
		}
		return hasSupplementary ? static_cast<$Pattern$Node*>($new($Pattern$SliceIS, tmp)) : static_cast<$Pattern$Node*>($new($Pattern$SliceI, tmp));
	}
	for (int32_t i = 0; i < count; ++i) {
		tmp->set(i, $nc(buf)->get(i));
	}
	return hasSupplementary ? static_cast<$Pattern$Node*>($new($Pattern$SliceS, tmp)) : static_cast<$Pattern$Node*>($new($Pattern$Slice, tmp));
}

bool Pattern::hasBaseCharacter($Matcher* matcher, int32_t i, $CharSequence* seq) {
	$init(Pattern);
	int32_t start = (!$nc(matcher)->transparentBounds) ? $nc(matcher)->from : 0;
	for (int32_t x = i; x >= start; --x) {
		int32_t ch = $Character::codePointAt(seq, x);
		if ($Character::isLetterOrDigit(ch)) {
			return true;
		}
		if ($Character::getType(ch) == $Character::NON_SPACING_MARK) {
			continue;
		}
		return false;
	}
	return false;
}

$Pattern$BmpCharPredicate* Pattern::VertWS() {
	$init(Pattern);
	return static_cast<$Pattern$BmpCharPredicate*>($new(Pattern$$Lambda$lambda$VertWS$1$1));
}

$Pattern$BmpCharPredicate* Pattern::HorizWS() {
	$init(Pattern);
	return static_cast<$Pattern$BmpCharPredicate*>($new(Pattern$$Lambda$lambda$HorizWS$2$2));
}

$Pattern$CharPredicate* Pattern::ALL() {
	$init(Pattern);
	return static_cast<$Pattern$CharPredicate*>($new(Pattern$$Lambda$lambda$ALL$3$3));
}

$Pattern$CharPredicate* Pattern::DOT() {
	$init(Pattern);
	return static_cast<$Pattern$CharPredicate*>($new(Pattern$$Lambda$lambda$DOT$4$4));
}

$Pattern$CharPredicate* Pattern::UNIXDOT() {
	$init(Pattern);
	return static_cast<$Pattern$CharPredicate*>($new(Pattern$$Lambda$lambda$UNIXDOT$5$5));
}

$Pattern$CharPredicate* Pattern::SingleS(int32_t c) {
	$init(Pattern);
	return static_cast<$Pattern$CharPredicate*>($new(Pattern$$Lambda$lambda$SingleS$6$6, c));
}

$Pattern$BmpCharPredicate* Pattern::Single(int32_t c) {
	$init(Pattern);
	return static_cast<$Pattern$BmpCharPredicate*>($new(Pattern$$Lambda$lambda$SingleS$6$6, c));
}

$Pattern$BmpCharPredicate* Pattern::SingleI(int32_t lower, int32_t upper) {
	$init(Pattern);
	return static_cast<$Pattern$BmpCharPredicate*>($new(Pattern$$Lambda$lambda$SingleI$8$7, lower, upper));
}

$Pattern$CharPredicate* Pattern::SingleU(int32_t lower) {
	$init(Pattern);
	return static_cast<$Pattern$CharPredicate*>($new(Pattern$$Lambda$lambda$SingleU$9$8, lower));
}

bool Pattern::inRange(int32_t lower, int32_t ch, int32_t upper) {
	$init(Pattern);
	return lower <= ch && ch <= upper;
}

$Pattern$CharPredicate* Pattern::Range(int32_t lower, int32_t upper) {
	$init(Pattern);
	if (upper < $Character::MIN_HIGH_SURROGATE || lower > $Character::MAX_LOW_SURROGATE && upper < $Character::MIN_SUPPLEMENTARY_CODE_POINT) {
		return (static_cast<$Pattern$BmpCharPredicate*>($new(Pattern$$Lambda$lambda$Range$10$9, lower, upper)));
	}
	return static_cast<$Pattern$CharPredicate*>($new(Pattern$$Lambda$lambda$Range$10$9, lower, upper));
}

$Pattern$CharPredicate* Pattern::CIRange(int32_t lower, int32_t upper) {
	$init(Pattern);
	return static_cast<$Pattern$CharPredicate*>($new(Pattern$$Lambda$lambda$CIRange$12$10, lower, upper));
}

$Pattern$CharPredicate* Pattern::CIRangeU(int32_t lower, int32_t upper) {
	$init(Pattern);
	return static_cast<$Pattern$CharPredicate*>($new(Pattern$$Lambda$lambda$CIRangeU$13$11, lower, upper));
}

$Predicate* Pattern::asPredicate() {
	return static_cast<$Predicate*>($new(Pattern$$Lambda$lambda$asPredicate$14$12, this));
}

$Predicate* Pattern::asMatchPredicate() {
	return static_cast<$Predicate*>($new(Pattern$$Lambda$lambda$asMatchPredicate$15$13, this));
}

$Stream* Pattern::splitAsStream($CharSequence* input) {
	$useLocalCurrentObjectStackCache();
	{
	}
	return $StreamSupport::stream($($Spliterators::spliteratorUnknownSize(static_cast<$Iterator*>($$new($Pattern$1MatcherIterator, this, input)), $Spliterator::ORDERED | $Spliterator::NONNULL)), false);
}

bool Pattern::lambda$asMatchPredicate$15($String* s) {
	return $nc($(matcher(s)))->matches();
}

bool Pattern::lambda$asPredicate$14($String* s) {
	return $nc($(matcher(s)))->find();
}

bool Pattern::lambda$CIRangeU$13(int32_t lower, int32_t upper, int32_t ch) {
	$init(Pattern);
	if (inRange(lower, ch, upper)) {
		return true;
	}
	int32_t up = $Character::toUpperCase(ch);
	bool var$0 = inRange(lower, up, upper);
	return var$0 || inRange(lower, $Character::toLowerCase(up), upper);
}

bool Pattern::lambda$CIRange$12(int32_t lower, int32_t upper, int32_t ch) {
	$init(Pattern);
	bool var$0 = inRange(lower, ch, upper);
	if (!var$0) {
		bool var$1 = $ASCII::isAscii(ch);
		if (var$1) {
			bool var$2 = inRange(lower, $ASCII::toUpper(ch), upper);
			var$1 = (var$2 || inRange(lower, $ASCII::toLower(ch), upper));
		}
		var$0 = var$1;
	}
	return var$0;
}

bool Pattern::lambda$Range$10(int32_t lower, int32_t upper, int32_t ch) {
	$init(Pattern);
	return inRange(lower, ch, upper);
}

bool Pattern::lambda$SingleU$9(int32_t lower, int32_t ch) {
	$init(Pattern);
	return lower == ch || lower == $Character::toLowerCase($Character::toUpperCase(ch));
}

bool Pattern::lambda$SingleI$8(int32_t lower, int32_t upper, int32_t ch) {
	$init(Pattern);
	return ch == lower || ch == upper;
}

bool Pattern::lambda$SingleS$6(int32_t c, int32_t ch) {
	$init(Pattern);
	return ch == c;
}

bool Pattern::lambda$UNIXDOT$5(int32_t ch) {
	$init(Pattern);
	return ch != u'\n';
}

bool Pattern::lambda$DOT$4(int32_t ch) {
	$init(Pattern);
	return (ch != u'\n' && ch != u'\r' && (ch | 1) != (char16_t)0x2029 && ch != (char16_t)0x85);
}

bool Pattern::lambda$ALL$3(int32_t ch) {
	$init(Pattern);
	return true;
}

bool Pattern::lambda$HorizWS$2(int32_t cp) {
	$init(Pattern);
	return cp == 9 || cp == 32 || cp == 160 || cp == 5760 || cp == 6158 || cp >= 8192 && cp <= 8202 || cp == 8239 || cp == 8287 || cp == 12288;
}

bool Pattern::lambda$VertWS$1(int32_t cp) {
	$init(Pattern);
	return (cp >= 10 && cp <= 13) || cp == 133 || cp == 8232 || cp == 8233;
}

void Pattern::lambda$normalizeSlice$0($StringBuilder* dst, $String* s) {
	$init(Pattern);
	$nc(dst)->append(s)->append(u'|');
}

void clinit$Pattern($Class* class$) {
	Pattern::$assertionsDisabled = !Pattern::class$->desiredAssertionStatus();
	$assignStatic(Pattern::accept$, $new($Pattern$Node));
	$assignStatic(Pattern::lastAccept, $new($Pattern$LastNode));
}

Pattern::Pattern() {
}

$Class* Pattern::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Pattern$$Lambda$lambda$normalizeSlice$0::classInfo$.name)) {
			return Pattern$$Lambda$lambda$normalizeSlice$0::load$(name, initialize);
		}
		if (name->equals(Pattern$$Lambda$lambda$VertWS$1$1::classInfo$.name)) {
			return Pattern$$Lambda$lambda$VertWS$1$1::load$(name, initialize);
		}
		if (name->equals(Pattern$$Lambda$lambda$HorizWS$2$2::classInfo$.name)) {
			return Pattern$$Lambda$lambda$HorizWS$2$2::load$(name, initialize);
		}
		if (name->equals(Pattern$$Lambda$lambda$ALL$3$3::classInfo$.name)) {
			return Pattern$$Lambda$lambda$ALL$3$3::load$(name, initialize);
		}
		if (name->equals(Pattern$$Lambda$lambda$DOT$4$4::classInfo$.name)) {
			return Pattern$$Lambda$lambda$DOT$4$4::load$(name, initialize);
		}
		if (name->equals(Pattern$$Lambda$lambda$UNIXDOT$5$5::classInfo$.name)) {
			return Pattern$$Lambda$lambda$UNIXDOT$5$5::load$(name, initialize);
		}
		if (name->equals(Pattern$$Lambda$lambda$SingleS$6$6::classInfo$.name)) {
			return Pattern$$Lambda$lambda$SingleS$6$6::load$(name, initialize);
		}
		if (name->equals(Pattern$$Lambda$lambda$SingleI$8$7::classInfo$.name)) {
			return Pattern$$Lambda$lambda$SingleI$8$7::load$(name, initialize);
		}
		if (name->equals(Pattern$$Lambda$lambda$SingleU$9$8::classInfo$.name)) {
			return Pattern$$Lambda$lambda$SingleU$9$8::load$(name, initialize);
		}
		if (name->equals(Pattern$$Lambda$lambda$Range$10$9::classInfo$.name)) {
			return Pattern$$Lambda$lambda$Range$10$9::load$(name, initialize);
		}
		if (name->equals(Pattern$$Lambda$lambda$CIRange$12$10::classInfo$.name)) {
			return Pattern$$Lambda$lambda$CIRange$12$10::load$(name, initialize);
		}
		if (name->equals(Pattern$$Lambda$lambda$CIRangeU$13$11::classInfo$.name)) {
			return Pattern$$Lambda$lambda$CIRangeU$13$11::load$(name, initialize);
		}
		if (name->equals(Pattern$$Lambda$lambda$asPredicate$14$12::classInfo$.name)) {
			return Pattern$$Lambda$lambda$asPredicate$14$12::load$(name, initialize);
		}
		if (name->equals(Pattern$$Lambda$lambda$asMatchPredicate$15$13::classInfo$.name)) {
			return Pattern$$Lambda$lambda$asMatchPredicate$15$13::load$(name, initialize);
		}
	}
	$loadClass(Pattern, name, initialize, &_Pattern_ClassInfo_, clinit$Pattern, allocate$Pattern);
	return class$;
}

$Class* Pattern::class$ = nullptr;

		} // regex
	} // util
} // java