#include <java/time/zone/ZoneRules.h>

#include <java/io/DataInput.h>
#include <java/io/DataOutput.h>
#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/Math.h>
#include <java/time/Duration.h>
#include <java/time/Instant.h>
#include <java/time/LocalDateTime.h>
#include <java/time/Year.h>
#include <java/time/ZoneOffset.h>
#include <java/time/chrono/ChronoLocalDateTime.h>
#include <java/time/zone/Ser.h>
#include <java/time/zone/ZoneOffsetTransition.h>
#include <java/time/zone/ZoneOffsetTransitionRule.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <jcpp.h>

#undef DAYS_PER_CYCLE
#undef EMPTY_LASTRULES
#undef EMPTY_LDT_ARRAY
#undef EMPTY_LONG_ARRAY
#undef LAST_CACHED_YEAR
#undef MAX_VALUE
#undef ZERO
#undef ZRULES

using $LocalDateTimeArray = $Array<::java::time::LocalDateTime>;
using $ZoneOffsetArray = $Array<::java::time::ZoneOffset>;
using $ZoneOffsetTransitionArray = $Array<::java::time::zone::ZoneOffsetTransition>;
using $ZoneOffsetTransitionRuleArray = $Array<::java::time::zone::ZoneOffsetTransitionRule>;
using $DataInput = ::java::io::DataInput;
using $DataOutput = ::java::io::DataOutput;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Duration = ::java::time::Duration;
using $Instant = ::java::time::Instant;
using $LocalDateTime = ::java::time::LocalDateTime;
using $Year = ::java::time::Year;
using $ZoneOffset = ::java::time::ZoneOffset;
using $ChronoLocalDateTime = ::java::time::chrono::ChronoLocalDateTime;
using $Ser = ::java::time::zone::Ser;
using $ZoneOffsetTransition = ::java::time::zone::ZoneOffsetTransition;
using $ZoneOffsetTransitionRule = ::java::time::zone::ZoneOffsetTransitionRule;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;

namespace java {
	namespace time {
		namespace zone {

$FieldInfo _ZoneRules_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ZoneRules, serialVersionUID)},
	{"LAST_CACHED_YEAR", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ZoneRules, LAST_CACHED_YEAR)},
	{"standardTransitions", "[J", nullptr, $PRIVATE | $FINAL, $field(ZoneRules, standardTransitions)},
	{"standardOffsets", "[Ljava/time/ZoneOffset;", nullptr, $PRIVATE | $FINAL, $field(ZoneRules, standardOffsets)},
	{"savingsInstantTransitions", "[J", nullptr, $PRIVATE | $FINAL, $field(ZoneRules, savingsInstantTransitions)},
	{"savingsLocalTransitions", "[Ljava/time/LocalDateTime;", nullptr, $PRIVATE | $FINAL, $field(ZoneRules, savingsLocalTransitions)},
	{"wallOffsets", "[Ljava/time/ZoneOffset;", nullptr, $PRIVATE | $FINAL, $field(ZoneRules, wallOffsets)},
	{"lastRules", "[Ljava/time/zone/ZoneOffsetTransitionRule;", nullptr, $PRIVATE | $FINAL, $field(ZoneRules, lastRules)},
	{"lastRulesCache", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/lang/Integer;[Ljava/time/zone/ZoneOffsetTransition;>;", $PRIVATE | $FINAL | $TRANSIENT, $field(ZoneRules, lastRulesCache)},
	{"EMPTY_LONG_ARRAY", "[J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ZoneRules, EMPTY_LONG_ARRAY)},
	{"EMPTY_LASTRULES", "[Ljava/time/zone/ZoneOffsetTransitionRule;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ZoneRules, EMPTY_LASTRULES)},
	{"EMPTY_LDT_ARRAY", "[Ljava/time/LocalDateTime;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ZoneRules, EMPTY_LDT_ARRAY)},
	{"DAYS_PER_CYCLE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ZoneRules, DAYS_PER_CYCLE)},
	{"DAYS_0000_TO_1970", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ZoneRules, DAYS_0000_TO_1970)},
	{}
};

$MethodInfo _ZoneRules_MethodInfo_[] = {
	{"<init>", "(Ljava/time/ZoneOffset;Ljava/time/ZoneOffset;Ljava/util/List;Ljava/util/List;Ljava/util/List;)V", "(Ljava/time/ZoneOffset;Ljava/time/ZoneOffset;Ljava/util/List<Ljava/time/zone/ZoneOffsetTransition;>;Ljava/util/List<Ljava/time/zone/ZoneOffsetTransition;>;Ljava/util/List<Ljava/time/zone/ZoneOffsetTransitionRule;>;)V", 0, $method(ZoneRules, init$, void, $ZoneOffset*, $ZoneOffset*, $List*, $List*, $List*)},
	{"<init>", "([J[Ljava/time/ZoneOffset;[J[Ljava/time/ZoneOffset;[Ljava/time/zone/ZoneOffsetTransitionRule;)V", nullptr, $PRIVATE, $method(ZoneRules, init$, void, $longs*, $ZoneOffsetArray*, $longs*, $ZoneOffsetArray*, $ZoneOffsetTransitionRuleArray*)},
	{"<init>", "(Ljava/time/ZoneOffset;)V", nullptr, $PRIVATE, $method(ZoneRules, init$, void, $ZoneOffset*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ZoneRules, equals, bool, Object$*)},
	{"findOffsetInfo", "(Ljava/time/LocalDateTime;Ljava/time/zone/ZoneOffsetTransition;)Ljava/lang/Object;", nullptr, $PRIVATE, $method(ZoneRules, findOffsetInfo, $Object*, $LocalDateTime*, $ZoneOffsetTransition*)},
	{"findTransitionArray", "(I)[Ljava/time/zone/ZoneOffsetTransition;", nullptr, $PRIVATE, $method(ZoneRules, findTransitionArray, $ZoneOffsetTransitionArray*, int32_t)},
	{"findYear", "(JLjava/time/ZoneOffset;)I", nullptr, $PRIVATE, $method(ZoneRules, findYear, int32_t, int64_t, $ZoneOffset*)},
	{"getDaylightSavings", "(Ljava/time/Instant;)Ljava/time/Duration;", nullptr, $PUBLIC, $method(ZoneRules, getDaylightSavings, $Duration*, $Instant*)},
	{"getOffset", "(Ljava/time/Instant;)Ljava/time/ZoneOffset;", nullptr, $PUBLIC, $method(ZoneRules, getOffset, $ZoneOffset*, $Instant*)},
	{"getOffset", "(Ljava/time/LocalDateTime;)Ljava/time/ZoneOffset;", nullptr, $PUBLIC, $method(ZoneRules, getOffset, $ZoneOffset*, $LocalDateTime*)},
	{"getOffsetInfo", "(Ljava/time/LocalDateTime;)Ljava/lang/Object;", nullptr, $PRIVATE, $method(ZoneRules, getOffsetInfo, $Object*, $LocalDateTime*)},
	{"getStandardOffset", "(Ljava/time/Instant;)Ljava/time/ZoneOffset;", nullptr, $PUBLIC, $method(ZoneRules, getStandardOffset, $ZoneOffset*, $Instant*)},
	{"getTransition", "(Ljava/time/LocalDateTime;)Ljava/time/zone/ZoneOffsetTransition;", nullptr, $PUBLIC, $method(ZoneRules, getTransition, $ZoneOffsetTransition*, $LocalDateTime*)},
	{"getTransitionRules", "()Ljava/util/List;", "()Ljava/util/List<Ljava/time/zone/ZoneOffsetTransitionRule;>;", $PUBLIC, $method(ZoneRules, getTransitionRules, $List*)},
	{"getTransitions", "()Ljava/util/List;", "()Ljava/util/List<Ljava/time/zone/ZoneOffsetTransition;>;", $PUBLIC, $method(ZoneRules, getTransitions, $List*)},
	{"getValidOffsets", "(Ljava/time/LocalDateTime;)Ljava/util/List;", "(Ljava/time/LocalDateTime;)Ljava/util/List<Ljava/time/ZoneOffset;>;", $PUBLIC, $method(ZoneRules, getValidOffsets, $List*, $LocalDateTime*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(ZoneRules, hashCode, int32_t)},
	{"isDaylightSavings", "(Ljava/time/Instant;)Z", nullptr, $PUBLIC, $method(ZoneRules, isDaylightSavings, bool, $Instant*)},
	{"isFixedOffset", "()Z", nullptr, $PUBLIC, $method(ZoneRules, isFixedOffset, bool)},
	{"isValidOffset", "(Ljava/time/LocalDateTime;Ljava/time/ZoneOffset;)Z", nullptr, $PUBLIC, $method(ZoneRules, isValidOffset, bool, $LocalDateTime*, $ZoneOffset*)},
	{"nextTransition", "(Ljava/time/Instant;)Ljava/time/zone/ZoneOffsetTransition;", nullptr, $PUBLIC, $method(ZoneRules, nextTransition, $ZoneOffsetTransition*, $Instant*)},
	{"of", "(Ljava/time/ZoneOffset;Ljava/time/ZoneOffset;Ljava/util/List;Ljava/util/List;Ljava/util/List;)Ljava/time/zone/ZoneRules;", "(Ljava/time/ZoneOffset;Ljava/time/ZoneOffset;Ljava/util/List<Ljava/time/zone/ZoneOffsetTransition;>;Ljava/util/List<Ljava/time/zone/ZoneOffsetTransition;>;Ljava/util/List<Ljava/time/zone/ZoneOffsetTransitionRule;>;)Ljava/time/zone/ZoneRules;", $PUBLIC | $STATIC, $staticMethod(ZoneRules, of, ZoneRules*, $ZoneOffset*, $ZoneOffset*, $List*, $List*, $List*)},
	{"of", "(Ljava/time/ZoneOffset;)Ljava/time/zone/ZoneRules;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZoneRules, of, ZoneRules*, $ZoneOffset*)},
	{"previousTransition", "(Ljava/time/Instant;)Ljava/time/zone/ZoneOffsetTransition;", nullptr, $PUBLIC, $method(ZoneRules, previousTransition, $ZoneOffsetTransition*, $Instant*)},
	{"readExternal", "(Ljava/io/DataInput;)Ljava/time/zone/ZoneRules;", nullptr, $STATIC, $staticMethod(ZoneRules, readExternal, ZoneRules*, $DataInput*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(ZoneRules, readObject, void, $ObjectInputStream*), "java.io.InvalidObjectException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ZoneRules, toString, $String*)},
	{"writeExternal", "(Ljava/io/DataOutput;)V", nullptr, 0, $method(ZoneRules, writeExternal, void, $DataOutput*), "java.io.IOException"},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(ZoneRules, writeReplace, $Object*)},
	{}
};

$ClassInfo _ZoneRules_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.zone.ZoneRules",
	"java.lang.Object",
	"java.io.Serializable",
	_ZoneRules_FieldInfo_,
	_ZoneRules_MethodInfo_
};

$Object* allocate$ZoneRules($Class* clazz) {
	return $of($alloc(ZoneRules));
}

$longs* ZoneRules::EMPTY_LONG_ARRAY = nullptr;
$ZoneOffsetTransitionRuleArray* ZoneRules::EMPTY_LASTRULES = nullptr;
$LocalDateTimeArray* ZoneRules::EMPTY_LDT_ARRAY = nullptr;

ZoneRules* ZoneRules::of($ZoneOffset* baseStandardOffset, $ZoneOffset* baseWallOffset, $List* standardOffsetTransitionList, $List* transitionList, $List* lastRules) {
	$init(ZoneRules);
	$Objects::requireNonNull($of(baseStandardOffset), "baseStandardOffset"_s);
	$Objects::requireNonNull($of(baseWallOffset), "baseWallOffset"_s);
	$Objects::requireNonNull($of(standardOffsetTransitionList), "standardOffsetTransitionList"_s);
	$Objects::requireNonNull($of(transitionList), "transitionList"_s);
	$Objects::requireNonNull($of(lastRules), "lastRules"_s);
	return $new(ZoneRules, baseStandardOffset, baseWallOffset, standardOffsetTransitionList, transitionList, lastRules);
}

ZoneRules* ZoneRules::of($ZoneOffset* offset) {
	$init(ZoneRules);
	$Objects::requireNonNull($of(offset), "offset"_s);
	return $new(ZoneRules, offset);
}

void ZoneRules::init$($ZoneOffset* baseStandardOffset, $ZoneOffset* baseWallOffset, $List* standardOffsetTransitionList, $List* transitionList, $List* lastRules) {
	$useLocalCurrentObjectStackCache();
	$set(this, lastRulesCache, $new($ConcurrentHashMap));
	$set(this, standardTransitions, $new($longs, $nc(standardOffsetTransitionList)->size()));
	$set(this, standardOffsets, $new($ZoneOffsetArray, standardOffsetTransitionList->size() + 1));
	$nc(this->standardOffsets)->set(0, baseStandardOffset);
	for (int32_t i = 0; i < standardOffsetTransitionList->size(); ++i) {
		$nc(this->standardTransitions)->set(i, $nc(($cast($ZoneOffsetTransition, $(standardOffsetTransitionList->get(i)))))->toEpochSecond());
		$nc(this->standardOffsets)->set(i + 1, $($nc(($cast($ZoneOffsetTransition, $(standardOffsetTransitionList->get(i)))))->getOffsetAfter()));
	}
	$var($List, localTransitionList, $new($ArrayList));
	$var($List, localTransitionOffsetList, $new($ArrayList));
	localTransitionOffsetList->add(baseWallOffset);
	{
		$var($Iterator, i$, $nc(transitionList)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ZoneOffsetTransition, trans, $cast($ZoneOffsetTransition, i$->next()));
			{
				if ($nc(trans)->isGap()) {
					localTransitionList->add($(trans->getDateTimeBefore()));
					localTransitionList->add($(trans->getDateTimeAfter()));
				} else {
					localTransitionList->add($(trans->getDateTimeAfter()));
					localTransitionList->add($(trans->getDateTimeBefore()));
				}
				localTransitionOffsetList->add($($nc(trans)->getOffsetAfter()));
			}
		}
	}
	$set(this, savingsLocalTransitions, $fcast($LocalDateTimeArray, localTransitionList->toArray($$new($LocalDateTimeArray, localTransitionList->size()))));
	$set(this, wallOffsets, $fcast($ZoneOffsetArray, localTransitionOffsetList->toArray($$new($ZoneOffsetArray, localTransitionOffsetList->size()))));
	$set(this, savingsInstantTransitions, $new($longs, transitionList->size()));
	for (int32_t i = 0; i < transitionList->size(); ++i) {
		$nc(this->savingsInstantTransitions)->set(i, $nc(($cast($ZoneOffsetTransition, $(transitionList->get(i)))))->toEpochSecond());
	}
	$var($ObjectArray, temp, $nc(lastRules)->toArray());
	$load($ZoneOffsetTransitionRuleArray);
	$var($ZoneOffsetTransitionRuleArray, rulesArray, $fcast($ZoneOffsetTransitionRuleArray, $Arrays::copyOf(temp, $nc(temp)->length, $getClass($ZoneOffsetTransitionRuleArray))));
	if (rulesArray->length > 16) {
		$throwNew($IllegalArgumentException, "Too many transition rules"_s);
	}
	$set(this, lastRules, rulesArray);
}

void ZoneRules::init$($longs* standardTransitions, $ZoneOffsetArray* standardOffsets, $longs* savingsInstantTransitions, $ZoneOffsetArray* wallOffsets, $ZoneOffsetTransitionRuleArray* lastRules) {
	$useLocalCurrentObjectStackCache();
	$set(this, lastRulesCache, $new($ConcurrentHashMap));
	$set(this, standardTransitions, standardTransitions);
	$set(this, standardOffsets, standardOffsets);
	$set(this, savingsInstantTransitions, savingsInstantTransitions);
	$set(this, wallOffsets, wallOffsets);
	$set(this, lastRules, lastRules);
	if ($nc(savingsInstantTransitions)->length == 0) {
		$set(this, savingsLocalTransitions, ZoneRules::EMPTY_LDT_ARRAY);
	} else {
		$var($List, localTransitionList, $new($ArrayList));
		for (int32_t i = 0; i < savingsInstantTransitions->length; ++i) {
			$var($ZoneOffset, before, $nc(wallOffsets)->get(i));
			$var($ZoneOffset, after, wallOffsets->get(i + 1));
			$var($ZoneOffsetTransition, trans, $new($ZoneOffsetTransition, savingsInstantTransitions->get(i), before, after));
			if (trans->isGap()) {
				localTransitionList->add($(trans->getDateTimeBefore()));
				localTransitionList->add($(trans->getDateTimeAfter()));
			} else {
				localTransitionList->add($(trans->getDateTimeAfter()));
				localTransitionList->add($(trans->getDateTimeBefore()));
			}
		}
		$set(this, savingsLocalTransitions, $fcast($LocalDateTimeArray, localTransitionList->toArray($$new($LocalDateTimeArray, localTransitionList->size()))));
	}
}

void ZoneRules::init$($ZoneOffset* offset) {
	$set(this, lastRulesCache, $new($ConcurrentHashMap));
	$set(this, standardOffsets, $new($ZoneOffsetArray, 1));
	$nc(this->standardOffsets)->set(0, offset);
	$set(this, standardTransitions, ZoneRules::EMPTY_LONG_ARRAY);
	$set(this, savingsInstantTransitions, ZoneRules::EMPTY_LONG_ARRAY);
	$set(this, savingsLocalTransitions, ZoneRules::EMPTY_LDT_ARRAY);
	$set(this, wallOffsets, this->standardOffsets);
	$set(this, lastRules, ZoneRules::EMPTY_LASTRULES);
}

void ZoneRules::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

$Object* ZoneRules::writeReplace() {
	return $of($new($Ser, $Ser::ZRULES, this));
}

void ZoneRules::writeExternal($DataOutput* out) {
	$useLocalCurrentObjectStackCache();
	$nc(out)->writeInt($nc(this->standardTransitions)->length);
	{
		$var($longs, arr$, this->standardTransitions);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			int64_t trans = arr$->get(i$);
			{
				$Ser::writeEpochSec(trans, out);
			}
		}
	}
	{
		$var($ZoneOffsetArray, arr$, this->standardOffsets);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($ZoneOffset, offset, arr$->get(i$));
			{
				$Ser::writeOffset(offset, out);
			}
		}
	}
	out->writeInt($nc(this->savingsInstantTransitions)->length);
	{
		$var($longs, arr$, this->savingsInstantTransitions);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			int64_t trans = arr$->get(i$);
			{
				$Ser::writeEpochSec(trans, out);
			}
		}
	}
	{
		$var($ZoneOffsetArray, arr$, this->wallOffsets);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($ZoneOffset, offset, arr$->get(i$));
			{
				$Ser::writeOffset(offset, out);
			}
		}
	}
	out->writeByte($nc(this->lastRules)->length);
	{
		$var($ZoneOffsetTransitionRuleArray, arr$, this->lastRules);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($ZoneOffsetTransitionRule, rule, arr$->get(i$));
			{
				$nc(rule)->writeExternal(out);
			}
		}
	}
}

ZoneRules* ZoneRules::readExternal($DataInput* in) {
	$init(ZoneRules);
	$useLocalCurrentObjectStackCache();
	int32_t stdSize = $nc(in)->readInt();
	if (stdSize > 1024) {
		$throwNew($InvalidObjectException, "Too many transitions"_s);
	}
	$var($longs, stdTrans, (stdSize == 0) ? ZoneRules::EMPTY_LONG_ARRAY : $new($longs, stdSize));
	for (int32_t i = 0; i < stdSize; ++i) {
		$nc(stdTrans)->set(i, $Ser::readEpochSec(in));
	}
	$var($ZoneOffsetArray, stdOffsets, $new($ZoneOffsetArray, stdSize + 1));
	for (int32_t i = 0; i < stdOffsets->length; ++i) {
		stdOffsets->set(i, $($Ser::readOffset(in)));
	}
	int32_t savSize = in->readInt();
	if (savSize > 1024) {
		$throwNew($InvalidObjectException, "Too many saving offsets"_s);
	}
	$var($longs, savTrans, (savSize == 0) ? ZoneRules::EMPTY_LONG_ARRAY : $new($longs, savSize));
	for (int32_t i = 0; i < savSize; ++i) {
		$nc(savTrans)->set(i, $Ser::readEpochSec(in));
	}
	$var($ZoneOffsetArray, savOffsets, $new($ZoneOffsetArray, savSize + 1));
	for (int32_t i = 0; i < savOffsets->length; ++i) {
		savOffsets->set(i, $($Ser::readOffset(in)));
	}
	int32_t ruleSize = in->readByte();
	if (ruleSize > 16) {
		$throwNew($InvalidObjectException, "Too many transition rules"_s);
	}
	$var($ZoneOffsetTransitionRuleArray, rules, (ruleSize == 0) ? ZoneRules::EMPTY_LASTRULES : $new($ZoneOffsetTransitionRuleArray, ruleSize));
	for (int32_t i = 0; i < ruleSize; ++i) {
		$nc(rules)->set(i, $($ZoneOffsetTransitionRule::readExternal(in)));
	}
	return $new(ZoneRules, stdTrans, stdOffsets, savTrans, savOffsets, rules);
}

bool ZoneRules::isFixedOffset() {
	return $nc($nc(this->standardOffsets)->get(0))->equals($nc(this->wallOffsets)->get(0)) && $nc(this->standardTransitions)->length == 0 && $nc(this->savingsInstantTransitions)->length == 0 && $nc(this->lastRules)->length == 0;
}

$ZoneOffset* ZoneRules::getOffset($Instant* instant) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->savingsInstantTransitions)->length == 0) {
		return $nc(this->wallOffsets)->get(0);
	}
	int64_t epochSec = $nc(instant)->getEpochSecond();
	if ($nc(this->lastRules)->length > 0 && epochSec > $nc(this->savingsInstantTransitions)->get($nc(this->savingsInstantTransitions)->length - 1)) {
		int32_t year = findYear(epochSec, $nc(this->wallOffsets)->get($nc(this->wallOffsets)->length - 1));
		$var($ZoneOffsetTransitionArray, transArray, findTransitionArray(year));
		$var($ZoneOffsetTransition, trans, nullptr);
		for (int32_t i = 0; i < $nc(transArray)->length; ++i) {
			$assign(trans, transArray->get(i));
			if (epochSec < $nc(trans)->toEpochSecond()) {
				return trans->getOffsetBefore();
			}
		}
		return $nc(trans)->getOffsetAfter();
	}
	int32_t index = $Arrays::binarySearch(this->savingsInstantTransitions, epochSec);
	if (index < 0) {
		index = -index - 2;
	}
	return $nc(this->wallOffsets)->get(index + 1);
}

$ZoneOffset* ZoneRules::getOffset($LocalDateTime* localDateTime) {
	$var($Object, info, getOffsetInfo(localDateTime));
	if ($instanceOf($ZoneOffsetTransition, info)) {
		return $nc(($cast($ZoneOffsetTransition, info)))->getOffsetBefore();
	}
	return $cast($ZoneOffset, info);
}

$List* ZoneRules::getValidOffsets($LocalDateTime* localDateTime) {
	$var($Object, info, getOffsetInfo(localDateTime));
	if ($instanceOf($ZoneOffsetTransition, info)) {
		return $nc(($cast($ZoneOffsetTransition, info)))->getValidOffsets();
	}
	return $Collections::singletonList($cast($ZoneOffset, info));
}

$ZoneOffsetTransition* ZoneRules::getTransition($LocalDateTime* localDateTime) {
	$var($Object, info, getOffsetInfo(localDateTime));
	return ($instanceOf($ZoneOffsetTransition, info) ? $cast($ZoneOffsetTransition, info) : ($ZoneOffsetTransition*)nullptr);
}

$Object* ZoneRules::getOffsetInfo($LocalDateTime* dt) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->savingsLocalTransitions)->length == 0) {
		return $of($nc(this->wallOffsets)->get(0));
	}
	if ($nc(this->lastRules)->length > 0 && $nc(dt)->isAfter($nc(this->savingsLocalTransitions)->get($nc(this->savingsLocalTransitions)->length - 1))) {
		$var($ZoneOffsetTransitionArray, transArray, findTransitionArray(dt->getYear()));
		$var($Object, info, nullptr);
		{
			$var($ZoneOffsetTransitionArray, arr$, transArray);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($ZoneOffsetTransition, trans, arr$->get(i$));
				{
					$assign(info, findOffsetInfo(dt, trans));
					if ($instanceOf($ZoneOffsetTransition, info) || $nc($of(info))->equals($($nc(trans)->getOffsetBefore()))) {
						return $of(info);
					}
				}
			}
		}
		return $of(info);
	}
	int32_t index = $Arrays::binarySearch(this->savingsLocalTransitions, $of(dt));
	if (index == -1) {
		return $of($nc(this->wallOffsets)->get(0));
	}
	if (index < 0) {
		index = -index - 2;
	} else if (index < $nc(this->savingsLocalTransitions)->length - 1 && $nc($nc(this->savingsLocalTransitions)->get(index))->equals($nc(this->savingsLocalTransitions)->get(index + 1))) {
		++index;
	}
	if (((int32_t)(index & (uint32_t)1)) == 0) {
		$var($LocalDateTime, dtBefore, $nc(this->savingsLocalTransitions)->get(index));
		$var($LocalDateTime, dtAfter, $nc(this->savingsLocalTransitions)->get(index + 1));
		$var($ZoneOffset, offsetBefore, $nc(this->wallOffsets)->get(index / 2));
		$var($ZoneOffset, offsetAfter, $nc(this->wallOffsets)->get(index / 2 + 1));
		int32_t var$0 = $nc(offsetAfter)->getTotalSeconds();
		if (var$0 > $nc(offsetBefore)->getTotalSeconds()) {
			return $of($new($ZoneOffsetTransition, dtBefore, offsetBefore, offsetAfter));
		} else {
			return $of($new($ZoneOffsetTransition, dtAfter, offsetBefore, offsetAfter));
		}
	} else {
		return $of($nc(this->wallOffsets)->get(index / 2 + 1));
	}
}

$Object* ZoneRules::findOffsetInfo($LocalDateTime* dt, $ZoneOffsetTransition* trans) {
	$useLocalCurrentObjectStackCache();
	$var($LocalDateTime, localTransition, $nc(trans)->getDateTimeBefore());
	if (trans->isGap()) {
		if ($nc(dt)->isBefore(localTransition)) {
			return $of(trans->getOffsetBefore());
		}
		if ($nc(dt)->isBefore($(trans->getDateTimeAfter()))) {
			return $of(trans);
		} else {
			return $of(trans->getOffsetAfter());
		}
	} else {
		if ($nc(dt)->isBefore(localTransition) == false) {
			return $of(trans->getOffsetAfter());
		}
		if ($nc(dt)->isBefore($(trans->getDateTimeAfter()))) {
			return $of(trans->getOffsetBefore());
		} else {
			return $of(trans);
		}
	}
}

$ZoneOffsetTransitionArray* ZoneRules::findTransitionArray(int32_t year) {
	$useLocalCurrentObjectStackCache();
	$var($Integer, yearObj, $Integer::valueOf(year));
	$var($ZoneOffsetTransitionArray, transArray, $cast($ZoneOffsetTransitionArray, $nc(this->lastRulesCache)->get(yearObj)));
	if (transArray != nullptr) {
		return transArray;
	}
	$var($ZoneOffsetTransitionRuleArray, ruleArray, this->lastRules);
	$assign(transArray, $new($ZoneOffsetTransitionArray, $nc(ruleArray)->length));
	for (int32_t i = 0; i < ruleArray->length; ++i) {
		transArray->set(i, $($nc(ruleArray->get(i))->createTransition(year)));
	}
	if (year < ZoneRules::LAST_CACHED_YEAR) {
		$nc(this->lastRulesCache)->putIfAbsent(yearObj, transArray);
	}
	return transArray;
}

$ZoneOffset* ZoneRules::getStandardOffset($Instant* instant) {
	if ($nc(this->standardTransitions)->length == 0) {
		return $nc(this->standardOffsets)->get(0);
	}
	int64_t epochSec = $nc(instant)->getEpochSecond();
	int32_t index = $Arrays::binarySearch(this->standardTransitions, epochSec);
	if (index < 0) {
		index = -index - 2;
	}
	return $nc(this->standardOffsets)->get(index + 1);
}

$Duration* ZoneRules::getDaylightSavings($Instant* instant) {
	$useLocalCurrentObjectStackCache();
	if (isFixedOffset()) {
		$init($Duration);
		return $Duration::ZERO;
	}
	$var($ZoneOffset, standardOffset, getStandardOffset(instant));
	$var($ZoneOffset, actualOffset, getOffset(instant));
	int32_t var$0 = $nc(actualOffset)->getTotalSeconds();
	return $Duration::ofSeconds(var$0 - $nc(standardOffset)->getTotalSeconds());
}

bool ZoneRules::isDaylightSavings($Instant* instant) {
	$useLocalCurrentObjectStackCache();
	return ($nc($(getStandardOffset(instant)))->equals($(getOffset(instant))) == false);
}

bool ZoneRules::isValidOffset($LocalDateTime* localDateTime, $ZoneOffset* offset) {
	return $nc($(getValidOffsets(localDateTime)))->contains(offset);
}

$ZoneOffsetTransition* ZoneRules::nextTransition($Instant* instant) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->savingsInstantTransitions)->length == 0) {
		return nullptr;
	}
	int64_t epochSec = $nc(instant)->getEpochSecond();
	if (epochSec >= $nc(this->savingsInstantTransitions)->get($nc(this->savingsInstantTransitions)->length - 1)) {
		if ($nc(this->lastRules)->length == 0) {
			return nullptr;
		}
		int32_t year = findYear(epochSec, $nc(this->wallOffsets)->get($nc(this->wallOffsets)->length - 1));
		$var($ZoneOffsetTransitionArray, transArray, findTransitionArray(year));
		{
			$var($ZoneOffsetTransitionArray, arr$, transArray);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($ZoneOffsetTransition, trans, arr$->get(i$));
				{
					if (epochSec < $nc(trans)->toEpochSecond()) {
						return trans;
					}
				}
			}
		}
		if (year < $Year::MAX_VALUE) {
			$assign(transArray, findTransitionArray(year + 1));
			return $nc(transArray)->get(0);
		}
		return nullptr;
	}
	int32_t index = $Arrays::binarySearch(this->savingsInstantTransitions, epochSec);
	if (index < 0) {
		index = -index - 1;
	} else {
		index += 1;
	}
	return $new($ZoneOffsetTransition, $nc(this->savingsInstantTransitions)->get(index), $nc(this->wallOffsets)->get(index), $nc(this->wallOffsets)->get(index + 1));
}

$ZoneOffsetTransition* ZoneRules::previousTransition($Instant* instant) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->savingsInstantTransitions)->length == 0) {
		return nullptr;
	}
	int64_t epochSec = $nc(instant)->getEpochSecond();
	if (instant->getNano() > 0 && epochSec < $Long::MAX_VALUE) {
		epochSec += 1;
	}
	int64_t lastHistoric = $nc(this->savingsInstantTransitions)->get($nc(this->savingsInstantTransitions)->length - 1);
	if ($nc(this->lastRules)->length > 0 && epochSec > lastHistoric) {
		$var($ZoneOffset, lastHistoricOffset, $nc(this->wallOffsets)->get($nc(this->wallOffsets)->length - 1));
		int32_t year = findYear(epochSec, lastHistoricOffset);
		$var($ZoneOffsetTransitionArray, transArray, findTransitionArray(year));
		for (int32_t i = $nc(transArray)->length - 1; i >= 0; --i) {
			if (epochSec > $nc(transArray->get(i))->toEpochSecond()) {
				return transArray->get(i);
			}
		}
		int32_t lastHistoricYear = findYear(lastHistoric, lastHistoricOffset);
		if (--year > lastHistoricYear) {
			$assign(transArray, findTransitionArray(year));
			return $nc(transArray)->get(transArray->length - 1);
		}
	}
	int32_t index = $Arrays::binarySearch(this->savingsInstantTransitions, epochSec);
	if (index < 0) {
		index = -index - 1;
	}
	if (index <= 0) {
		return nullptr;
	}
	return $new($ZoneOffsetTransition, $nc(this->savingsInstantTransitions)->get(index - 1), $nc(this->wallOffsets)->get(index - 1), $nc(this->wallOffsets)->get(index));
}

int32_t ZoneRules::findYear(int64_t epochSecond, $ZoneOffset* offset) {
	int64_t localSecond = epochSecond + $nc(offset)->getTotalSeconds();
	int64_t zeroDay = $Math::floorDiv(localSecond, 0x00015180) + ZoneRules::DAYS_0000_TO_1970;
	zeroDay -= 60;
	int64_t adjust = 0;
	if (zeroDay < 0) {
		int64_t adjustCycles = $div((zeroDay + 1), ZoneRules::DAYS_PER_CYCLE) - 1;
		adjust = adjustCycles * 400;
		zeroDay += -adjustCycles * ZoneRules::DAYS_PER_CYCLE;
	}
	int64_t yearEst = $div((400 * zeroDay + 591), ZoneRules::DAYS_PER_CYCLE);
	int64_t doyEst = zeroDay - (365 * yearEst + yearEst / 4 - yearEst / 100 + yearEst / 400);
	if (doyEst < 0) {
		--yearEst;
		doyEst = zeroDay - (365 * yearEst + yearEst / 4 - yearEst / 100 + yearEst / 400);
	}
	yearEst += adjust;
	int32_t marchDoy0 = (int32_t)doyEst;
	int32_t marchMonth0 = (marchDoy0 * 5 + 2) / 153;
	yearEst += marchMonth0 / 10;
	return (int32_t)$Math::min(yearEst, (int64_t)$Year::MAX_VALUE);
}

$List* ZoneRules::getTransitions() {
	$useLocalCurrentObjectStackCache();
	$var($List, list, $new($ArrayList));
	for (int32_t i = 0; i < $nc(this->savingsInstantTransitions)->length; ++i) {
		list->add($$new($ZoneOffsetTransition, $nc(this->savingsInstantTransitions)->get(i), $nc(this->wallOffsets)->get(i), $nc(this->wallOffsets)->get(i + 1)));
	}
	return $Collections::unmodifiableList(list);
}

$List* ZoneRules::getTransitionRules() {
	return $List::of(this->lastRules);
}

bool ZoneRules::equals(Object$* otherRules) {
	if ($equals(this, otherRules)) {
		return true;
	}
	$var(ZoneRules, other, nullptr);
	bool var$5 = $instanceOf(ZoneRules, otherRules);
	if (var$5) {
		$assign(other, $cast(ZoneRules, otherRules));
		var$5 = true;
	}
	bool var$4 = (var$5);
	bool var$3 = var$4 && $Arrays::equals(this->standardTransitions, $nc(other)->standardTransitions);
	bool var$2 = var$3 && $Arrays::equals(this->standardOffsets, $nc(other)->standardOffsets);
	bool var$1 = var$2 && $Arrays::equals(this->savingsInstantTransitions, $nc(other)->savingsInstantTransitions);
	bool var$0 = var$1 && $Arrays::equals(this->wallOffsets, $nc(other)->wallOffsets);
	return var$0 && $Arrays::equals(this->lastRules, $nc(other)->lastRules);
}

int32_t ZoneRules::hashCode() {
	int32_t var$3 = $Arrays::hashCode(this->standardTransitions);
	int32_t var$2 = var$3 ^ $Arrays::hashCode(this->standardOffsets);
	int32_t var$1 = var$2 ^ $Arrays::hashCode(this->savingsInstantTransitions);
	int32_t var$0 = var$1 ^ $Arrays::hashCode(this->wallOffsets);
	return var$0 ^ $Arrays::hashCode(this->lastRules);
}

$String* ZoneRules::toString() {
	return $str({"ZoneRules[currentStandardOffset="_s, $nc(this->standardOffsets)->get($nc(this->standardOffsets)->length - 1), "]"_s});
}

void clinit$ZoneRules($Class* class$) {
	$assignStatic(ZoneRules::EMPTY_LONG_ARRAY, $new($longs, 0));
	$assignStatic(ZoneRules::EMPTY_LASTRULES, $new($ZoneOffsetTransitionRuleArray, 0));
	$assignStatic(ZoneRules::EMPTY_LDT_ARRAY, $new($LocalDateTimeArray, 0));
}

ZoneRules::ZoneRules() {
}

$Class* ZoneRules::load$($String* name, bool initialize) {
	$loadClass(ZoneRules, name, initialize, &_ZoneRules_ClassInfo_, clinit$ZoneRules, allocate$ZoneRules);
	return class$;
}

$Class* ZoneRules::class$ = nullptr;

		} // zone
	} // time
} // java