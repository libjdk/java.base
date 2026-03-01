#include <java/util/regex/Matcher.h>

#include <java/lang/CharSequence.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/Math.h>
#include <java/lang/StringBuffer.h>
#include <java/util/ConcurrentModificationException.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators.h>
#include <java/util/function/Function.h>
#include <java/util/regex/ASCII.h>
#include <java/util/regex/IntHashSet.h>
#include <java/util/regex/MatchResult.h>
#include <java/util/regex/Matcher$1MatchResultIterator.h>
#include <java/util/regex/Matcher$ImmutableMatchResult.h>
#include <java/util/regex/Pattern$Node.h>
#include <java/util/regex/Pattern.h>
#include <java/util/stream/Stream.h>
#include <java/util/stream/StreamSupport.h>
#include <jcpp.h>

#undef ENDANCHOR
#undef NOANCHOR
#undef NONNULL
#undef ORDERED

using $IntHashSetArray = $Array<::java::util::regex::IntHashSet>;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $StringBuffer = ::java::lang::StringBuffer;
using $ConcurrentModificationException = ::java::util::ConcurrentModificationException;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Spliterator = ::java::util::Spliterator;
using $Spliterators = ::java::util::Spliterators;
using $Function = ::java::util::function::Function;
using $ASCII = ::java::util::regex::ASCII;
using $IntHashSet = ::java::util::regex::IntHashSet;
using $MatchResult = ::java::util::regex::MatchResult;
using $Matcher$1MatchResultIterator = ::java::util::regex::Matcher$1MatchResultIterator;
using $Matcher$ImmutableMatchResult = ::java::util::regex::Matcher$ImmutableMatchResult;
using $Pattern = ::java::util::regex::Pattern;
using $Pattern$Node = ::java::util::regex::Pattern$Node;
using $Stream = ::java::util::stream::Stream;
using $StreamSupport = ::java::util::stream::StreamSupport;

namespace java {
	namespace util {
		namespace regex {

$FieldInfo _Matcher_FieldInfo_[] = {
	{"parentPattern", "Ljava/util/regex/Pattern;", nullptr, 0, $field(Matcher, parentPattern)},
	{"groups", "[I", nullptr, 0, $field(Matcher, groups)},
	{"from", "I", nullptr, 0, $field(Matcher, from)},
	{"to", "I", nullptr, 0, $field(Matcher, to)},
	{"lookbehindTo", "I", nullptr, 0, $field(Matcher, lookbehindTo)},
	{"text", "Ljava/lang/CharSequence;", nullptr, 0, $field(Matcher, text)},
	{"ENDANCHOR", "I", nullptr, $STATIC | $FINAL, $constField(Matcher, ENDANCHOR)},
	{"NOANCHOR", "I", nullptr, $STATIC | $FINAL, $constField(Matcher, NOANCHOR)},
	{"acceptMode", "I", nullptr, 0, $field(Matcher, acceptMode)},
	{"first", "I", nullptr, 0, $field(Matcher, first)},
	{"last", "I", nullptr, 0, $field(Matcher, last)},
	{"oldLast", "I", nullptr, 0, $field(Matcher, oldLast)},
	{"lastAppendPosition", "I", nullptr, 0, $field(Matcher, lastAppendPosition)},
	{"locals", "[I", nullptr, 0, $field(Matcher, locals)},
	{"localsPos", "[Ljava/util/regex/IntHashSet;", nullptr, 0, $field(Matcher, localsPos)},
	{"hitEnd", "Z", nullptr, 0, $field(Matcher, hitEnd$)},
	{"requireEnd", "Z", nullptr, 0, $field(Matcher, requireEnd$)},
	{"transparentBounds", "Z", nullptr, 0, $field(Matcher, transparentBounds)},
	{"anchoringBounds", "Z", nullptr, 0, $field(Matcher, anchoringBounds)},
	{"modCount", "I", nullptr, 0, $field(Matcher, modCount)},
	{}
};

$MethodInfo _Matcher_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(Matcher, init$, void)},
	{"<init>", "(Ljava/util/regex/Pattern;Ljava/lang/CharSequence;)V", nullptr, 0, $method(Matcher, init$, void, $Pattern*, $CharSequence*)},
	{"appendExpandedReplacement", "(Ljava/lang/String;Ljava/lang/StringBuilder;)Ljava/lang/StringBuilder;", nullptr, $PRIVATE, $method(Matcher, appendExpandedReplacement, $StringBuilder*, $String*, $StringBuilder*)},
	{"appendReplacement", "(Ljava/lang/StringBuffer;Ljava/lang/String;)Ljava/util/regex/Matcher;", nullptr, $PUBLIC, $method(Matcher, appendReplacement, Matcher*, $StringBuffer*, $String*)},
	{"appendReplacement", "(Ljava/lang/StringBuilder;Ljava/lang/String;)Ljava/util/regex/Matcher;", nullptr, $PUBLIC, $method(Matcher, appendReplacement, Matcher*, $StringBuilder*, $String*)},
	{"appendTail", "(Ljava/lang/StringBuffer;)Ljava/lang/StringBuffer;", nullptr, $PUBLIC, $method(Matcher, appendTail, $StringBuffer*, $StringBuffer*)},
	{"appendTail", "(Ljava/lang/StringBuilder;)Ljava/lang/StringBuilder;", nullptr, $PUBLIC, $method(Matcher, appendTail, $StringBuilder*, $StringBuilder*)},
	{"charAt", "(I)C", nullptr, 0, $method(Matcher, charAt, char16_t, int32_t)},
	{"end", "()I", nullptr, $PUBLIC, $virtualMethod(Matcher, end, int32_t)},
	{"end", "(I)I", nullptr, $PUBLIC, $virtualMethod(Matcher, end, int32_t, int32_t)},
	{"end", "(Ljava/lang/String;)I", nullptr, $PUBLIC, $method(Matcher, end, int32_t, $String*)},
	{"find", "()Z", nullptr, $PUBLIC, $method(Matcher, find, bool)},
	{"find", "(I)Z", nullptr, $PUBLIC, $method(Matcher, find, bool, int32_t)},
	{"getMatchedGroupIndex", "(Ljava/lang/String;)I", nullptr, 0, $method(Matcher, getMatchedGroupIndex, int32_t, $String*)},
	{"getSubSequence", "(II)Ljava/lang/CharSequence;", nullptr, 0, $method(Matcher, getSubSequence, $CharSequence*, int32_t, int32_t)},
	{"getTextLength", "()I", nullptr, 0, $method(Matcher, getTextLength, int32_t)},
	{"group", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Matcher, group, $String*)},
	{"group", "(I)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Matcher, group, $String*, int32_t)},
	{"group", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $method(Matcher, group, $String*, $String*)},
	{"groupCount", "()I", nullptr, $PUBLIC, $virtualMethod(Matcher, groupCount, int32_t)},
	{"hasAnchoringBounds", "()Z", nullptr, $PUBLIC, $method(Matcher, hasAnchoringBounds, bool)},
	{"hasTransparentBounds", "()Z", nullptr, $PUBLIC, $method(Matcher, hasTransparentBounds, bool)},
	{"hitEnd", "()Z", nullptr, $PUBLIC, $method(Matcher, hitEnd, bool)},
	{"lookingAt", "()Z", nullptr, $PUBLIC, $method(Matcher, lookingAt, bool)},
	{"match", "(II)Z", nullptr, 0, $method(Matcher, match, bool, int32_t, int32_t)},
	{"matches", "()Z", nullptr, $PUBLIC, $method(Matcher, matches, bool)},
	{"pattern", "()Ljava/util/regex/Pattern;", nullptr, $PUBLIC, $method(Matcher, pattern, $Pattern*)},
	{"quoteReplacement", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Matcher, quoteReplacement, $String*, $String*)},
	{"region", "(II)Ljava/util/regex/Matcher;", nullptr, $PUBLIC, $method(Matcher, region, Matcher*, int32_t, int32_t)},
	{"regionEnd", "()I", nullptr, $PUBLIC, $method(Matcher, regionEnd, int32_t)},
	{"regionStart", "()I", nullptr, $PUBLIC, $method(Matcher, regionStart, int32_t)},
	{"replaceAll", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $method(Matcher, replaceAll, $String*, $String*)},
	{"replaceAll", "(Ljava/util/function/Function;)Ljava/lang/String;", "(Ljava/util/function/Function<Ljava/util/regex/MatchResult;Ljava/lang/String;>;)Ljava/lang/String;", $PUBLIC, $method(Matcher, replaceAll, $String*, $Function*)},
	{"replaceFirst", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $method(Matcher, replaceFirst, $String*, $String*)},
	{"replaceFirst", "(Ljava/util/function/Function;)Ljava/lang/String;", "(Ljava/util/function/Function<Ljava/util/regex/MatchResult;Ljava/lang/String;>;)Ljava/lang/String;", $PUBLIC, $method(Matcher, replaceFirst, $String*, $Function*)},
	{"requireEnd", "()Z", nullptr, $PUBLIC, $method(Matcher, requireEnd, bool)},
	{"reset", "()Ljava/util/regex/Matcher;", nullptr, $PUBLIC, $method(Matcher, reset, Matcher*)},
	{"reset", "(Ljava/lang/CharSequence;)Ljava/util/regex/Matcher;", nullptr, $PUBLIC, $method(Matcher, reset, Matcher*, $CharSequence*)},
	{"results", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljava/util/regex/MatchResult;>;", $PUBLIC, $method(Matcher, results, $Stream*)},
	{"search", "(I)Z", nullptr, 0, $method(Matcher, search, bool, int32_t)},
	{"start", "()I", nullptr, $PUBLIC, $virtualMethod(Matcher, start, int32_t)},
	{"start", "(I)I", nullptr, $PUBLIC, $virtualMethod(Matcher, start, int32_t, int32_t)},
	{"start", "(Ljava/lang/String;)I", nullptr, $PUBLIC, $method(Matcher, start, int32_t, $String*)},
	{"toMatchResult", "()Ljava/util/regex/MatchResult;", nullptr, $PUBLIC, $method(Matcher, toMatchResult, $MatchResult*)},
	{"toMatchResult", "(Ljava/lang/String;)Ljava/util/regex/MatchResult;", nullptr, $PRIVATE, $method(Matcher, toMatchResult, $MatchResult*, $String*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Matcher, toString, $String*)},
	{"useAnchoringBounds", "(Z)Ljava/util/regex/Matcher;", nullptr, $PUBLIC, $method(Matcher, useAnchoringBounds, Matcher*, bool)},
	{"usePattern", "(Ljava/util/regex/Pattern;)Ljava/util/regex/Matcher;", nullptr, $PUBLIC, $method(Matcher, usePattern, Matcher*, $Pattern*)},
	{"useTransparentBounds", "(Z)Ljava/util/regex/Matcher;", nullptr, $PUBLIC, $method(Matcher, useTransparentBounds, Matcher*, bool)},
	{}
};

$InnerClassInfo _Matcher_InnerClassesInfo_[] = {
	{"java.util.regex.Matcher$ImmutableMatchResult", "java.util.regex.Matcher", "ImmutableMatchResult", $PRIVATE | $STATIC},
	{"java.util.regex.Matcher$1MatchResultIterator", nullptr, "MatchResultIterator", 0},
	{}
};

$ClassInfo _Matcher_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.util.regex.Matcher",
	"java.lang.Object",
	"java.util.regex.MatchResult",
	_Matcher_FieldInfo_,
	_Matcher_MethodInfo_,
	nullptr,
	nullptr,
	_Matcher_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.regex.Matcher$ImmutableMatchResult,java.util.regex.Matcher$1MatchResultIterator"
};

$Object* allocate$Matcher($Class* clazz) {
	return $of($alloc(Matcher));
}

void Matcher::init$() {
	this->acceptMode = Matcher::NOANCHOR;
	this->first = -1;
	this->last = 0;
	this->oldLast = -1;
	this->lastAppendPosition = 0;
	this->transparentBounds = false;
	this->anchoringBounds = true;
}

void Matcher::init$($Pattern* parent, $CharSequence* text) {
	this->acceptMode = Matcher::NOANCHOR;
	this->first = -1;
	this->last = 0;
	this->oldLast = -1;
	this->lastAppendPosition = 0;
	this->transparentBounds = false;
	this->anchoringBounds = true;
	$set(this, parentPattern, parent);
	$set(this, text, text);
	int32_t parentGroupCount = $Math::max($nc(parent)->capturingGroupCount, 10);
	$set(this, groups, $new($ints, parentGroupCount * 2));
	$set(this, locals, $new($ints, $nc(parent)->localCount));
	$set(this, localsPos, $new($IntHashSetArray, parent->localTCNCount));
	reset();
}

$Pattern* Matcher::pattern() {
	return this->parentPattern;
}

$MatchResult* Matcher::toMatchResult() {
	return toMatchResult($($nc(this->text)->toString()));
}

$MatchResult* Matcher::toMatchResult($String* text) {
	int32_t var$0 = this->first;
	int32_t var$1 = this->last;
	int32_t var$2 = groupCount();
	return $new($Matcher$ImmutableMatchResult, var$0, var$1, var$2, $cast($ints, $($nc(this->groups)->clone())), text);
}

Matcher* Matcher::usePattern($Pattern* newPattern) {
	if (newPattern == nullptr) {
		$throwNew($IllegalArgumentException, "Pattern cannot be null"_s);
	}
	$set(this, parentPattern, newPattern);
	int32_t parentGroupCount = $Math::max($nc(newPattern)->capturingGroupCount, 10);
	$set(this, groups, $new($ints, parentGroupCount * 2));
	$set(this, locals, $new($ints, $nc(newPattern)->localCount));
	for (int32_t i = 0; i < $nc(this->groups)->length; ++i) {
		$nc(this->groups)->set(i, -1);
	}
	for (int32_t i = 0; i < $nc(this->locals)->length; ++i) {
		$nc(this->locals)->set(i, -1);
	}
	$set(this, localsPos, $new($IntHashSetArray, $nc(this->parentPattern)->localTCNCount));
	++this->modCount;
	return this;
}

Matcher* Matcher::reset() {
	this->first = -1;
	this->last = 0;
	this->oldLast = -1;
	for (int32_t i = 0; i < $nc(this->groups)->length; ++i) {
		$nc(this->groups)->set(i, -1);
	}
	for (int32_t i = 0; i < $nc(this->locals)->length; ++i) {
		$nc(this->locals)->set(i, -1);
	}
	for (int32_t i = 0; i < $nc(this->localsPos)->length; ++i) {
		if ($nc(this->localsPos)->get(i) != nullptr) {
			$nc($nc(this->localsPos)->get(i))->clear();
		}
	}
	this->lastAppendPosition = 0;
	this->from = 0;
	this->to = getTextLength();
	++this->modCount;
	return this;
}

Matcher* Matcher::reset($CharSequence* input) {
	$set(this, text, input);
	return reset();
}

int32_t Matcher::start() {
	if (this->first < 0) {
		$throwNew($IllegalStateException, "No match available"_s);
	}
	return this->first;
}

int32_t Matcher::start(int32_t group) {
	$useLocalCurrentObjectStackCache();
	if (this->first < 0) {
		$throwNew($IllegalStateException, "No match available"_s);
	}
	if (group < 0 || group > groupCount()) {
		$throwNew($IndexOutOfBoundsException, $$str({"No group "_s, $$str(group)}));
	}
	return $nc(this->groups)->get(group * 2);
}

int32_t Matcher::start($String* name) {
	return $nc(this->groups)->get(getMatchedGroupIndex(name) * 2);
}

int32_t Matcher::end() {
	if (this->first < 0) {
		$throwNew($IllegalStateException, "No match available"_s);
	}
	return this->last;
}

int32_t Matcher::end(int32_t group) {
	$useLocalCurrentObjectStackCache();
	if (this->first < 0) {
		$throwNew($IllegalStateException, "No match available"_s);
	}
	if (group < 0 || group > groupCount()) {
		$throwNew($IndexOutOfBoundsException, $$str({"No group "_s, $$str(group)}));
	}
	return $nc(this->groups)->get(group * 2 + 1);
}

int32_t Matcher::end($String* name) {
	return $nc(this->groups)->get(getMatchedGroupIndex(name) * 2 + 1);
}

$String* Matcher::group() {
	return group(0);
}

$String* Matcher::group(int32_t group) {
	$useLocalCurrentObjectStackCache();
	if (this->first < 0) {
		$throwNew($IllegalStateException, "No match found"_s);
	}
	if (group < 0 || group > groupCount()) {
		$throwNew($IndexOutOfBoundsException, $$str({"No group "_s, $$str(group)}));
	}
	if (($nc(this->groups)->get(group * 2) == -1) || ($nc(this->groups)->get(group * 2 + 1) == -1)) {
		return nullptr;
	}
	return $nc($(getSubSequence($nc(this->groups)->get(group * 2), $nc(this->groups)->get(group * 2 + 1))))->toString();
}

$String* Matcher::group($String* name) {
	int32_t group = getMatchedGroupIndex(name);
	if (($nc(this->groups)->get(group * 2) == -1) || ($nc(this->groups)->get(group * 2 + 1) == -1)) {
		return nullptr;
	}
	return $nc($(getSubSequence($nc(this->groups)->get(group * 2), $nc(this->groups)->get(group * 2 + 1))))->toString();
}

int32_t Matcher::groupCount() {
	return $nc(this->parentPattern)->capturingGroupCount - 1;
}

bool Matcher::matches() {
	return match(this->from, Matcher::ENDANCHOR);
}

bool Matcher::find() {
	int32_t nextSearchIndex = this->last;
	if (nextSearchIndex == this->first) {
		++nextSearchIndex;
	}
	if (nextSearchIndex < this->from) {
		nextSearchIndex = this->from;
	}
	if (nextSearchIndex > this->to) {
		for (int32_t i = 0; i < $nc(this->groups)->length; ++i) {
			$nc(this->groups)->set(i, -1);
		}
		return false;
	}
	return search(nextSearchIndex);
}

bool Matcher::find(int32_t start) {
	int32_t limit = getTextLength();
	if ((start < 0) || (start > limit)) {
		$throwNew($IndexOutOfBoundsException, "Illegal start index"_s);
	}
	reset();
	return search(start);
}

bool Matcher::lookingAt() {
	return match(this->from, Matcher::NOANCHOR);
}

$String* Matcher::quoteReplacement($String* s) {
	$init(Matcher);
	bool var$0 = ($nc(s)->indexOf((int32_t)u'\\') == -1);
	if (var$0 && (s->indexOf((int32_t)u'$') == -1)) {
		return s;
	}
	$var($StringBuilder, sb, $new($StringBuilder));
	for (int32_t i = 0; i < $nc(s)->length(); ++i) {
		char16_t c = s->charAt(i);
		if (c == u'\\' || c == u'$') {
			sb->append(u'\\');
		}
		sb->append(c);
	}
	return sb->toString();
}

Matcher* Matcher::appendReplacement($StringBuffer* sb, $String* replacement) {
	if (this->first < 0) {
		$throwNew($IllegalStateException, "No match available"_s);
	}
	$var($StringBuilder, result, $new($StringBuilder));
	appendExpandedReplacement(replacement, result);
	$nc(sb)->append(this->text, this->lastAppendPosition, this->first);
	sb->append(static_cast<$CharSequence*>(result));
	this->lastAppendPosition = this->last;
	++this->modCount;
	return this;
}

Matcher* Matcher::appendReplacement($StringBuilder* sb, $String* replacement) {
	if (this->first < 0) {
		$throwNew($IllegalStateException, "No match available"_s);
	}
	$var($StringBuilder, result, $new($StringBuilder));
	appendExpandedReplacement(replacement, result);
	$nc(sb)->append(this->text, this->lastAppendPosition, this->first);
	sb->append(static_cast<$CharSequence*>(result));
	this->lastAppendPosition = this->last;
	++this->modCount;
	return this;
}

$StringBuilder* Matcher::appendExpandedReplacement($String* replacement, $StringBuilder* result) {
	$useLocalCurrentObjectStackCache();
	int32_t cursor = 0;
	while (cursor < $nc(replacement)->length()) {
		char16_t nextChar = replacement->charAt(cursor);
		if (nextChar == u'\\') {
			++cursor;
			if (cursor == replacement->length()) {
				$throwNew($IllegalArgumentException, "character to be escaped is missing"_s);
			}
			nextChar = replacement->charAt(cursor);
			$nc(result)->append(nextChar);
			++cursor;
		} else if (nextChar == u'$') {
			++cursor;
			if (cursor == replacement->length()) {
				$throwNew($IllegalArgumentException, "Illegal group reference: group index is missing"_s);
			}
			nextChar = replacement->charAt(cursor);
			int32_t refNum = -1;
			if (nextChar == u'{') {
				++cursor;
				$var($StringBuilder, gsb, $new($StringBuilder));
				while (cursor < replacement->length()) {
					nextChar = replacement->charAt(cursor);
					bool var$1 = $ASCII::isLower(nextChar);
					bool var$0 = var$1 || $ASCII::isUpper(nextChar);
					if (var$0 || $ASCII::isDigit(nextChar)) {
						gsb->append(nextChar);
						++cursor;
					} else {
						break;
					}
				}
				if (gsb->length() == 0) {
					$throwNew($IllegalArgumentException, "named capturing group has 0 length name"_s);
				}
				if (nextChar != u'}') {
					$throwNew($IllegalArgumentException, "named capturing group is missing trailing \'}\'"_s);
				}
				$var($String, gname, gsb->toString());
				if ($ASCII::isDigit($nc(gname)->charAt(0))) {
					$throwNew($IllegalArgumentException, $$str({"capturing group name {"_s, gname, "} starts with digit character"_s}));
				}
				if (!$nc($($nc(this->parentPattern)->namedGroups()))->containsKey(gname)) {
					$throwNew($IllegalArgumentException, $$str({"No group with name {"_s, gname, "}"_s}));
				}
				refNum = $nc(($cast($Integer, $($nc($($nc(this->parentPattern)->namedGroups()))->get(gname)))))->intValue();
				++cursor;
			} else {
				refNum = nextChar - u'0';
				if ((refNum < 0) || (refNum > 9)) {
					$throwNew($IllegalArgumentException, "Illegal group reference"_s);
				}
				++cursor;
				bool done = false;
				while (!done) {
					if (cursor >= replacement->length()) {
						break;
					}
					int32_t nextDigit = replacement->charAt(cursor) - u'0';
					if ((nextDigit < 0) || (nextDigit > 9)) {
						break;
					}
					int32_t newRefNum = (refNum * 10) + nextDigit;
					if (groupCount() < newRefNum) {
						done = true;
					} else {
						refNum = newRefNum;
						++cursor;
					}
				}
			}
			bool var$2 = start(refNum) != -1;
			if (var$2 && end(refNum) != -1) {
				$var($CharSequence, var$3, this->text);
				int32_t var$4 = start(refNum);
				$nc(result)->append(var$3, var$4, end(refNum));
			}
		} else {
			$nc(result)->append(nextChar);
			++cursor;
		}
	}
	return result;
}

$StringBuffer* Matcher::appendTail($StringBuffer* sb) {
	$nc(sb)->append(this->text, this->lastAppendPosition, getTextLength());
	return sb;
}

$StringBuilder* Matcher::appendTail($StringBuilder* sb) {
	$nc(sb)->append(this->text, this->lastAppendPosition, getTextLength());
	return sb;
}

$String* Matcher::replaceAll($String* replacement) {
	reset();
	bool result = find();
	if (result) {
		$var($StringBuilder, sb, $new($StringBuilder));
		do {
			appendReplacement(sb, replacement);
			result = find();
		} while (result);
		appendTail(sb);
		return sb->toString();
	}
	return $nc(this->text)->toString();
}

$String* Matcher::replaceAll($Function* replacer) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(replacer);
	reset();
	bool result = find();
	if (result) {
		$var($StringBuilder, sb, $new($StringBuilder));
		do {
			int32_t ec = this->modCount;
			$var($String, replacement, $cast($String, replacer->apply(this)));
			if (ec != this->modCount) {
				$throwNew($ConcurrentModificationException);
			}
			appendReplacement(sb, replacement);
			result = find();
		} while (result);
		appendTail(sb);
		return sb->toString();
	}
	return $nc(this->text)->toString();
}

$Stream* Matcher::results() {
	$useLocalCurrentObjectStackCache();
	{
	}
	return $StreamSupport::stream($($Spliterators::spliteratorUnknownSize(static_cast<$Iterator*>($$new($Matcher$1MatchResultIterator, this)), $Spliterator::ORDERED | $Spliterator::NONNULL)), false);
}

$String* Matcher::replaceFirst($String* replacement) {
	if (replacement == nullptr) {
		$throwNew($NullPointerException, "replacement"_s);
	}
	reset();
	if (!find()) {
		return $nc(this->text)->toString();
	}
	$var($StringBuilder, sb, $new($StringBuilder));
	appendReplacement(sb, replacement);
	appendTail(sb);
	return sb->toString();
}

$String* Matcher::replaceFirst($Function* replacer) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(replacer);
	reset();
	if (!find()) {
		return $nc(this->text)->toString();
	}
	$var($StringBuilder, sb, $new($StringBuilder));
	int32_t ec = this->modCount;
	$var($String, replacement, $cast($String, replacer->apply(this)));
	if (ec != this->modCount) {
		$throwNew($ConcurrentModificationException);
	}
	appendReplacement(sb, replacement);
	appendTail(sb);
	return sb->toString();
}

Matcher* Matcher::region(int32_t start, int32_t end) {
	if ((start < 0) || (start > getTextLength())) {
		$throwNew($IndexOutOfBoundsException, "start"_s);
	}
	if ((end < 0) || (end > getTextLength())) {
		$throwNew($IndexOutOfBoundsException, "end"_s);
	}
	if (start > end) {
		$throwNew($IndexOutOfBoundsException, "start > end"_s);
	}
	reset();
	this->from = start;
	this->to = end;
	return this;
}

int32_t Matcher::regionStart() {
	return this->from;
}

int32_t Matcher::regionEnd() {
	return this->to;
}

bool Matcher::hasTransparentBounds() {
	return this->transparentBounds;
}

Matcher* Matcher::useTransparentBounds(bool b) {
	this->transparentBounds = b;
	return this;
}

bool Matcher::hasAnchoringBounds() {
	return this->anchoringBounds;
}

Matcher* Matcher::useAnchoringBounds(bool b) {
	this->anchoringBounds = b;
	return this;
}

$String* Matcher::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append("java.util.regex.Matcher"_s)->append("[pattern="_s)->append($($of(pattern())))->append(" region="_s)->append(regionStart())->append(u',')->append(regionEnd())->append(" lastmatch="_s);
	if ((this->first >= 0) && (group() != nullptr)) {
		sb->append($(group()));
	}
	sb->append(u']');
	return sb->toString();
}

bool Matcher::hitEnd() {
	return this->hitEnd$;
}

bool Matcher::requireEnd() {
	return this->requireEnd$;
}

bool Matcher::search(int32_t from) {
	this->hitEnd$ = false;
	this->requireEnd$ = false;
	from = from < 0 ? 0 : from;
	this->first = from;
	this->oldLast = this->oldLast < 0 ? from : this->oldLast;
	for (int32_t i = 0; i < $nc(this->groups)->length; ++i) {
		$nc(this->groups)->set(i, -1);
	}
	for (int32_t i = 0; i < $nc(this->localsPos)->length; ++i) {
		if ($nc(this->localsPos)->get(i) != nullptr) {
			$nc($nc(this->localsPos)->get(i))->clear();
		}
	}
	this->acceptMode = Matcher::NOANCHOR;
	bool result = $nc($nc(this->parentPattern)->root)->match(this, from, this->text);
	if (!result) {
		this->first = -1;
	}
	this->oldLast = this->last;
	++this->modCount;
	return result;
}

bool Matcher::match(int32_t from, int32_t anchor) {
	this->hitEnd$ = false;
	this->requireEnd$ = false;
	from = from < 0 ? 0 : from;
	this->first = from;
	this->oldLast = this->oldLast < 0 ? from : this->oldLast;
	for (int32_t i = 0; i < $nc(this->groups)->length; ++i) {
		$nc(this->groups)->set(i, -1);
	}
	for (int32_t i = 0; i < $nc(this->localsPos)->length; ++i) {
		if ($nc(this->localsPos)->get(i) != nullptr) {
			$nc($nc(this->localsPos)->get(i))->clear();
		}
	}
	this->acceptMode = anchor;
	bool result = $nc($nc(this->parentPattern)->matchRoot)->match(this, from, this->text);
	if (!result) {
		this->first = -1;
	}
	this->oldLast = this->last;
	++this->modCount;
	return result;
}

int32_t Matcher::getTextLength() {
	return $nc(this->text)->length();
}

$CharSequence* Matcher::getSubSequence(int32_t beginIndex, int32_t endIndex) {
	return $nc(this->text)->subSequence(beginIndex, endIndex);
}

char16_t Matcher::charAt(int32_t i) {
	return $nc(this->text)->charAt(i);
}

int32_t Matcher::getMatchedGroupIndex($String* name) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(name), "Group name"_s);
	if (this->first < 0) {
		$throwNew($IllegalStateException, "No match found"_s);
	}
	if (!$nc($($nc(this->parentPattern)->namedGroups()))->containsKey(name)) {
		$throwNew($IllegalArgumentException, $$str({"No group with name <"_s, name, ">"_s}));
	}
	return $nc(($cast($Integer, $($nc($($nc(this->parentPattern)->namedGroups()))->get(name)))))->intValue();
}

Matcher::Matcher() {
}

$Class* Matcher::load$($String* name, bool initialize) {
	$loadClass(Matcher, name, initialize, &_Matcher_ClassInfo_, allocate$Matcher);
	return class$;
}

$Class* Matcher::class$ = nullptr;

		} // regex
	} // util
} // java