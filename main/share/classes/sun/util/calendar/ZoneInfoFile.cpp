#include <sun/util/calendar/ZoneInfoFile.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/DataInput.h>
#include <java/io/DataInputStream.h>
#include <java/io/InputStream.h>
#include <java/io/StreamCorruptedException.h>
#include <java/lang/Math.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/time/LocalDateTime.h>
#include <java/time/LocalTime.h>
#include <java/time/ZoneOffset.h>
#include <java/util/AbstractMap.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Calendar.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/SimpleTimeZone.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/util/calendar/ZoneInfo.h>
#include <sun/util/calendar/ZoneInfoFile$1.h>
#include <sun/util/calendar/ZoneInfoFile$Checksum.h>
#include <sun/util/calendar/ZoneInfoFile$ZoneOffsetTransitionRule.h>
#include <jcpp.h>

#undef CURRT
#undef DAYS_PER_CYCLE
#undef DST_MASK
#undef DST_NSHIFT
#undef FRIDAY
#undef LASTYEAR
#undef MONDAY
#undef OFFSET_MASK
#undef ROOT
#undef SATURDAY
#undef SECONDS_PER_DAY
#undef STANDARD_TIME
#undef SUNDAY
#undef THURSDAY
#undef TRANSITION_NSHIFT
#undef TUESDAY
#undef USE_OLDMAPPING
#undef UTC_TIME
#undef WALL_TIME
#undef WEDNESDAY

using $ZoneInfoFile$ZoneOffsetTransitionRuleArray = $Array<::sun::util::calendar::ZoneInfoFile$ZoneOffsetTransitionRule>;
using $byteArray2 = $Array<int8_t, 2>;
using $StringArray2 = $Array<::java::lang::String, 2>;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $DataInput = ::java::io::DataInput;
using $DataInputStream = ::java::io::DataInputStream;
using $InputStream = ::java::io::InputStream;
using $StreamCorruptedException = ::java::io::StreamCorruptedException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $LocalDateTime = ::java::time::LocalDateTime;
using $LocalTime = ::java::time::LocalTime;
using $ZoneOffset = ::java::time::ZoneOffset;
using $AbstractMap = ::java::util::AbstractMap;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Calendar = ::java::util::Calendar;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $SimpleTimeZone = ::java::util::SimpleTimeZone;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $ZoneInfo = ::sun::util::calendar::ZoneInfo;
using $ZoneInfoFile$1 = ::sun::util::calendar::ZoneInfoFile$1;
using $ZoneInfoFile$Checksum = ::sun::util::calendar::ZoneInfoFile$Checksum;
using $ZoneInfoFile$ZoneOffsetTransitionRule = ::sun::util::calendar::ZoneInfoFile$ZoneOffsetTransitionRule;

namespace sun {
	namespace util {
		namespace calendar {

$FieldInfo _ZoneInfoFile_FieldInfo_[] = {
	{"versionId", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(ZoneInfoFile, versionId)},
	{"zones", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Lsun/util/calendar/ZoneInfo;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ZoneInfoFile, zones)},
	{"aliases", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticField(ZoneInfoFile, aliases)},
	{"ruleArray", "[[B", nullptr, $PRIVATE | $STATIC, $staticField(ZoneInfoFile, ruleArray)},
	{"regions", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(ZoneInfoFile, regions)},
	{"indices", "[I", nullptr, $PRIVATE | $STATIC, $staticField(ZoneInfoFile, indices)},
	{"USE_OLDMAPPING", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ZoneInfoFile, USE_OLDMAPPING)},
	{"oldMappings", "[[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(ZoneInfoFile, oldMappings)},
	{"UTC1900", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ZoneInfoFile, UTC1900)},
	{"UTC2037", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ZoneInfoFile, UTC2037)},
	{"LDT2037", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ZoneInfoFile, LDT2037)},
	{"CURRT", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ZoneInfoFile, CURRT)},
	{"SECONDS_PER_DAY", "I", nullptr, $STATIC | $FINAL, $constField(ZoneInfoFile, SECONDS_PER_DAY)},
	{"DAYS_PER_CYCLE", "I", nullptr, $STATIC | $FINAL, $constField(ZoneInfoFile, DAYS_PER_CYCLE)},
	{"DAYS_0000_TO_1970", "J", nullptr, $STATIC | $FINAL, $constField(ZoneInfoFile, DAYS_0000_TO_1970)},
	{"toCalendarDOW", "[I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ZoneInfoFile, toCalendarDOW)},
	{"toSTZTime", "[I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ZoneInfoFile, toSTZTime)},
	{"OFFSET_MASK", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ZoneInfoFile, OFFSET_MASK)},
	{"DST_MASK", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ZoneInfoFile, DST_MASK)},
	{"DST_NSHIFT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ZoneInfoFile, DST_NSHIFT)},
	{"TRANSITION_NSHIFT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ZoneInfoFile, TRANSITION_NSHIFT)},
	{"LASTYEAR", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ZoneInfoFile, LASTYEAR)},
	{}
};

$MethodInfo _ZoneInfoFile_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ZoneInfoFile, init$, void)},
	{"addOldMapping", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(ZoneInfoFile, addOldMapping, void)},
	{"addTrans", "([JI[IIJII)I", nullptr, $PRIVATE | $STATIC, $staticMethod(ZoneInfoFile, addTrans, int32_t, $longs*, int32_t, $ints*, int32_t, int64_t, int32_t, int32_t)},
	{"getAliasMap", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(ZoneInfoFile, getAliasMap, $Map*)},
	{"getCustomTimeZone", "(Ljava/lang/String;I)Lsun/util/calendar/ZoneInfo;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZoneInfoFile, getCustomTimeZone, $ZoneInfo*, $String*, int32_t)},
	{"getStandardOffset", "([J[IJ)I", nullptr, $PRIVATE | $STATIC, $staticMethod(ZoneInfoFile, getStandardOffset, int32_t, $longs*, $ints*, int64_t)},
	{"getVersion", "()Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZoneInfoFile, getVersion, $String*)},
	{"getYear", "(JI)I", nullptr, $PRIVATE | $STATIC, $staticMethod(ZoneInfoFile, getYear, int32_t, int64_t, int32_t)},
	{"getZoneIds", "()[Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZoneInfoFile, getZoneIds, $StringArray*)},
	{"getZoneIds", "(I)[Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZoneInfoFile, getZoneIds, $StringArray*, int32_t)},
	{"getZoneInfo", "(Ljava/lang/String;)Lsun/util/calendar/ZoneInfo;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZoneInfoFile, getZoneInfo, $ZoneInfo*, $String*)},
	{"getZoneInfo", "(Ljava/io/DataInput;Ljava/lang/String;)Lsun/util/calendar/ZoneInfo;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZoneInfoFile, getZoneInfo, $ZoneInfo*, $DataInput*, $String*), "java.lang.Exception"},
	{"getZoneInfo", "(Ljava/lang/String;[J[I[J[I[Lsun/util/calendar/ZoneInfoFile$ZoneOffsetTransitionRule;)Lsun/util/calendar/ZoneInfo;", nullptr, $PRIVATE | $STATIC, $staticMethod(ZoneInfoFile, getZoneInfo, $ZoneInfo*, $String*, $longs*, $ints*, $longs*, $ints*, $ZoneInfoFile$ZoneOffsetTransitionRuleArray*)},
	{"getZoneInfo0", "(Ljava/lang/String;)Lsun/util/calendar/ZoneInfo;", nullptr, $PRIVATE | $STATIC, $staticMethod(ZoneInfoFile, getZoneInfo0, $ZoneInfo*, $String*)},
	{"indexOf", "([IIII)I", nullptr, $PRIVATE | $STATIC, $staticMethod(ZoneInfoFile, indexOf, int32_t, $ints*, int32_t, int32_t, int32_t)},
	{"load", "(Ljava/io/DataInputStream;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ZoneInfoFile, load, void, $DataInputStream*), "java.lang.ClassNotFoundException,java.io.IOException"},
	{"readEpochSec", "(Ljava/io/DataInput;)J", nullptr, $STATIC, $staticMethod(ZoneInfoFile, readEpochSec, int64_t, $DataInput*), "java.io.IOException"},
	{"readOffset", "(Ljava/io/DataInput;)I", nullptr, $PUBLIC | $STATIC, $staticMethod(ZoneInfoFile, readOffset, int32_t, $DataInput*), "java.io.IOException"},
	{"toCustomID", "(I)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZoneInfoFile, toCustomID, $String*, int32_t)},
	{"useOldMapping", "()Z", nullptr, $PUBLIC | $STATIC, $staticMethod(ZoneInfoFile, useOldMapping, bool)},
	{}
};

$InnerClassInfo _ZoneInfoFile_InnerClassesInfo_[] = {
	{"sun.util.calendar.ZoneInfoFile$ZoneOffsetTransitionRule", "sun.util.calendar.ZoneInfoFile", "ZoneOffsetTransitionRule", $PRIVATE | $STATIC},
	{"sun.util.calendar.ZoneInfoFile$Checksum", "sun.util.calendar.ZoneInfoFile", "Checksum", $PRIVATE | $STATIC},
	{"sun.util.calendar.ZoneInfoFile$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ZoneInfoFile_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.util.calendar.ZoneInfoFile",
	"java.lang.Object",
	nullptr,
	_ZoneInfoFile_FieldInfo_,
	_ZoneInfoFile_MethodInfo_,
	nullptr,
	nullptr,
	_ZoneInfoFile_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.util.calendar.ZoneInfoFile$ZoneOffsetTransitionRule,sun.util.calendar.ZoneInfoFile$Checksum,sun.util.calendar.ZoneInfoFile$1"
};

$Object* allocate$ZoneInfoFile($Class* clazz) {
	return $of($alloc(ZoneInfoFile));
}

$String* ZoneInfoFile::versionId = nullptr;
$Map* ZoneInfoFile::zones = nullptr;
$Map* ZoneInfoFile::aliases = nullptr;
$byteArray2* ZoneInfoFile::ruleArray = nullptr;
$StringArray* ZoneInfoFile::regions = nullptr;
$ints* ZoneInfoFile::indices = nullptr;
bool ZoneInfoFile::USE_OLDMAPPING = false;
$StringArray2* ZoneInfoFile::oldMappings = nullptr;
int64_t ZoneInfoFile::CURRT = 0;
$ints* ZoneInfoFile::toCalendarDOW = nullptr;
$ints* ZoneInfoFile::toSTZTime = nullptr;

$StringArray* ZoneInfoFile::getZoneIds() {
	$init(ZoneInfoFile);
	int32_t len = $nc(ZoneInfoFile::regions)->length + $nc(ZoneInfoFile::oldMappings)->length;
	if (!ZoneInfoFile::USE_OLDMAPPING) {
		len += 3;
	}
	$var($StringArray, ids, $fcast($StringArray, $Arrays::copyOf(ZoneInfoFile::regions, len)));
	int32_t i = $nc(ZoneInfoFile::regions)->length;
	if (!ZoneInfoFile::USE_OLDMAPPING) {
		ids->set(i++, "EST"_s);
		ids->set(i++, "HST"_s);
		ids->set(i++, "MST"_s);
	}
	for (int32_t j = 0; j < $nc(ZoneInfoFile::oldMappings)->length; ++j) {
		ids->set(i++, $nc($nc(ZoneInfoFile::oldMappings)->get(j))->get(0));
	}
	return ids;
}

$StringArray* ZoneInfoFile::getZoneIds(int32_t rawOffset) {
	$init(ZoneInfoFile);
	$useLocalCurrentObjectStackCache();
	$var($List, ids, $new($ArrayList));
	{
		$var($StringArray, arr$, getZoneIds());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, id, arr$->get(i$));
			{
				$var($ZoneInfo, zi, getZoneInfo(id));
				if ($nc(zi)->getRawOffset() == rawOffset) {
					ids->add(id);
				}
			}
		}
	}
	$var($StringArray, list, $fcast($StringArray, ids->toArray($$new($StringArray, ids->size()))));
	$Arrays::sort(list);
	return list;
}

$ZoneInfo* ZoneInfoFile::getZoneInfo($String* zoneId) {
	$init(ZoneInfoFile);
	if (zoneId == nullptr) {
		return nullptr;
	}
	$var($ZoneInfo, zi, getZoneInfo0(zoneId));
	if (zi != nullptr) {
		$assign(zi, $cast($ZoneInfo, zi->clone()));
		$nc(zi)->setID(zoneId);
	}
	return zi;
}

$ZoneInfo* ZoneInfoFile::getZoneInfo0($String* zoneId) {
	$init(ZoneInfoFile);
	$useLocalCurrentObjectStackCache();
	try {
		$var($ZoneInfo, zi, $cast($ZoneInfo, $nc(ZoneInfoFile::zones)->get(zoneId)));
		if (zi != nullptr) {
			return zi;
		}
		$var($String, zid, zoneId);
		if ($nc(ZoneInfoFile::aliases)->containsKey(zoneId)) {
			$assign(zid, $cast($String, $nc(ZoneInfoFile::aliases)->get(zoneId)));
		}
		int32_t index = $Arrays::binarySearch(ZoneInfoFile::regions, $of(zid));
		if (index < 0) {
			return nullptr;
		}
		$var($bytes, bytes, $nc(ZoneInfoFile::ruleArray)->get($nc(ZoneInfoFile::indices)->get(index)));
		$var($DataInputStream, dis, $new($DataInputStream, $$new($ByteArrayInputStream, bytes)));
		$assign(zi, getZoneInfo(dis, zid));
		$nc(ZoneInfoFile::zones)->put(zoneId, zi);
		return zi;
	} catch ($Exception& ex) {
		$throwNew($RuntimeException, $$str({"Invalid binary time-zone data: TZDB:"_s, zoneId, ", version: "_s, ZoneInfoFile::versionId}), ex);
	}
	$shouldNotReachHere();
}

$Map* ZoneInfoFile::getAliasMap() {
	$init(ZoneInfoFile);
	return $Collections::unmodifiableMap(ZoneInfoFile::aliases);
}

$String* ZoneInfoFile::getVersion() {
	$init(ZoneInfoFile);
	return ZoneInfoFile::versionId;
}

$ZoneInfo* ZoneInfoFile::getCustomTimeZone($String* originalId, int32_t gmtOffset) {
	$init(ZoneInfoFile);
	$var($String, id, toCustomID(gmtOffset));
	return $new($ZoneInfo, id, gmtOffset);
}

$String* ZoneInfoFile::toCustomID(int32_t gmtOffset) {
	$init(ZoneInfoFile);
	char16_t sign = 0;
	int32_t offset = gmtOffset / 0x0000EA60;
	if (offset >= 0) {
		sign = u'+';
	} else {
		sign = u'-';
		offset = -offset;
	}
	int32_t hh = offset / 60;
	int32_t mm = offset % 60;
	$var($chars, buf, $new($chars, {
		u'G',
		u'M',
		u'T',
		sign,
		u'0',
		u'0',
		u':',
		u'0',
		u'0'
	}));
	if (hh >= 10) {
		(*buf)[4] += hh / 10;
	}
	(*buf)[5] += hh % 10;
	if (mm != 0) {
		(*buf)[7] += mm / 10;
		(*buf)[8] += mm % 10;
	}
	return $new($String, buf);
}

void ZoneInfoFile::init$() {
}

void ZoneInfoFile::addOldMapping() {
	$init(ZoneInfoFile);
	$useLocalCurrentObjectStackCache();
	{
		$var($StringArray2, arr$, ZoneInfoFile::oldMappings);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($StringArray, alias, arr$->get(i$));
			{
				$nc(ZoneInfoFile::aliases)->put($nc(alias)->get(0), alias->get(1));
			}
		}
	}
	if (ZoneInfoFile::USE_OLDMAPPING) {
		$nc(ZoneInfoFile::aliases)->put("EST"_s, "America/New_York"_s);
		$nc(ZoneInfoFile::aliases)->put("MST"_s, "America/Denver"_s);
		$nc(ZoneInfoFile::aliases)->put("HST"_s, "Pacific/Honolulu"_s);
	} else {
		$nc(ZoneInfoFile::zones)->put("EST"_s, $$new($ZoneInfo, "EST"_s, (int32_t)0xFEED5780));
		$nc(ZoneInfoFile::zones)->put("MST"_s, $$new($ZoneInfo, "MST"_s, (int32_t)0xFE7F7A80));
		$nc(ZoneInfoFile::zones)->put("HST"_s, $$new($ZoneInfo, "HST"_s, (int32_t)0xFDDAAF00));
	}
}

bool ZoneInfoFile::useOldMapping() {
	$init(ZoneInfoFile);
	return ZoneInfoFile::USE_OLDMAPPING;
}

void ZoneInfoFile::load($DataInputStream* dis) {
	$init(ZoneInfoFile);
	$useLocalCurrentObjectStackCache();
	if ($nc(dis)->readByte() != 1) {
		$throwNew($StreamCorruptedException, "File format not recognised"_s);
	}
	$var($String, groupId, $nc(dis)->readUTF());
	if ("TZDB"_s->equals(groupId) == false) {
		$throwNew($StreamCorruptedException, "File format not recognised"_s);
	}
	int32_t versionCount = dis->readShort();
	for (int32_t i = 0; i < versionCount; ++i) {
		$assignStatic(ZoneInfoFile::versionId, dis->readUTF());
	}
	int32_t regionCount = dis->readShort();
	$var($StringArray, regionArray, $new($StringArray, regionCount));
	for (int32_t i = 0; i < regionCount; ++i) {
		regionArray->set(i, $(dis->readUTF()));
	}
	int32_t ruleCount = dis->readShort();
	$assignStatic(ZoneInfoFile::ruleArray, $new($byteArray2, ruleCount));
	for (int32_t i = 0; i < ruleCount; ++i) {
		$var($bytes, bytes, $new($bytes, dis->readShort()));
		dis->readFully(bytes);
		$nc(ZoneInfoFile::ruleArray)->set(i, bytes);
	}
	for (int32_t i = 0; i < versionCount; ++i) {
		regionCount = dis->readShort();
		$assignStatic(ZoneInfoFile::regions, $new($StringArray, regionCount));
		$assignStatic(ZoneInfoFile::indices, $new($ints, regionCount));
		for (int32_t j = 0; j < regionCount; ++j) {
			$nc(ZoneInfoFile::regions)->set(j, regionArray->get(dis->readShort()));
			$nc(ZoneInfoFile::indices)->set(j, dis->readShort());
		}
	}
	$nc(ZoneInfoFile::zones)->remove("ROC"_s);
	for (int32_t i = 0; i < versionCount; ++i) {
		int32_t aliasCount = dis->readShort();
		$nc(ZoneInfoFile::aliases)->clear();
		for (int32_t j = 0; j < aliasCount; ++j) {
			$var($String, alias, regionArray->get(dis->readShort()));
			$var($String, region, regionArray->get(dis->readShort()));
			$nc(ZoneInfoFile::aliases)->put(alias, region);
		}
	}
	addOldMapping();
}

$ZoneInfo* ZoneInfoFile::getZoneInfo($DataInput* in, $String* zoneId) {
	$init(ZoneInfoFile);
	$useLocalCurrentObjectStackCache();
	int8_t type = $nc(in)->readByte();
	int32_t stdSize = in->readInt();
	$var($longs, stdTrans, $new($longs, stdSize));
	for (int32_t i = 0; i < stdSize; ++i) {
		stdTrans->set(i, readEpochSec(in));
	}
	$var($ints, stdOffsets, $new($ints, stdSize + 1));
	for (int32_t i = 0; i < stdOffsets->length; ++i) {
		stdOffsets->set(i, readOffset(in));
	}
	int32_t savSize = in->readInt();
	$var($longs, savTrans, $new($longs, savSize));
	for (int32_t i = 0; i < savSize; ++i) {
		savTrans->set(i, readEpochSec(in));
	}
	$var($ints, savOffsets, $new($ints, savSize + 1));
	for (int32_t i = 0; i < savOffsets->length; ++i) {
		savOffsets->set(i, readOffset(in));
	}
	int32_t ruleSize = in->readByte();
	$var($ZoneInfoFile$ZoneOffsetTransitionRuleArray, rules, $new($ZoneInfoFile$ZoneOffsetTransitionRuleArray, ruleSize));
	for (int32_t i = 0; i < ruleSize; ++i) {
		rules->set(i, $$new($ZoneInfoFile$ZoneOffsetTransitionRule, in));
	}
	return getZoneInfo(zoneId, stdTrans, stdOffsets, savTrans, savOffsets, rules);
}

int32_t ZoneInfoFile::readOffset($DataInput* in) {
	$init(ZoneInfoFile);
	int32_t offsetByte = $nc(in)->readByte();
	return offsetByte == 127 ? in->readInt() : offsetByte * 900;
}

int64_t ZoneInfoFile::readEpochSec($DataInput* in) {
	$init(ZoneInfoFile);
	int32_t hiByte = (int32_t)($nc(in)->readByte() & (uint32_t)255);
	if (hiByte == 255) {
		return in->readLong();
	} else {
		int32_t midByte = (int32_t)(in->readByte() & (uint32_t)255);
		int32_t loByte = (int32_t)(in->readByte() & (uint32_t)255);
		int64_t tot = ((hiByte << 16) + (midByte << 8) + loByte);
		return (tot * 900) - (int64_t)0x0000000110BC5000;
	}
}

$ZoneInfo* ZoneInfoFile::getZoneInfo($String* zoneId, $longs* standardTransitions, $ints* standardOffsets, $longs* savingsInstantTransitions, $ints* wallOffsets, $ZoneInfoFile$ZoneOffsetTransitionRuleArray* lastRules) {
	$init(ZoneInfoFile);
	$useLocalCurrentObjectStackCache();
	int32_t rawOffset = 0;
	int32_t dstSavings = 0;
	int32_t checksum = 0;
	$var($ints, params, nullptr);
	bool willGMTOffsetChange = false;
	if ($nc(standardTransitions)->length > 0) {
		rawOffset = $nc(standardOffsets)->get(standardOffsets->length - 1) * 1000;
		willGMTOffsetChange = standardTransitions->get(standardTransitions->length - 1) > ZoneInfoFile::CURRT;
	} else {
		rawOffset = $nc(standardOffsets)->get(0) * 1000;
	}
	$var($longs, transitions, nullptr);
	$var($ints, offsets, nullptr);
	int32_t nOffsets = 0;
	int32_t nTrans = 0;
	if ($nc(savingsInstantTransitions)->length != 0) {
		$assign(transitions, $new($longs, 250));
		$assign(offsets, $new($ints, 100));
		int32_t lastyear = getYear(savingsInstantTransitions->get(savingsInstantTransitions->length - 1), $nc(wallOffsets)->get(savingsInstantTransitions->length - 1));
		int32_t i = 0;
		int32_t k = 1;
		while (i < savingsInstantTransitions->length && savingsInstantTransitions->get(i) < ZoneInfoFile::UTC1900) {
			++i;
		}
		if (i < savingsInstantTransitions->length) {
			if (i < savingsInstantTransitions->length) {
				offsets->set(0, $nc(standardOffsets)->get(standardOffsets->length - 1) * 1000);
				nOffsets = 1;
			}
			nOffsets = addTrans(transitions, nTrans++, offsets, nOffsets, ZoneInfoFile::UTC1900, $nc(wallOffsets)->get(i), getStandardOffset(standardTransitions, standardOffsets, ZoneInfoFile::UTC1900));
		}
		for (; i < savingsInstantTransitions->length; ++i) {
			int64_t trans = savingsInstantTransitions->get(i);
			if (trans > ZoneInfoFile::UTC2037) {
				lastyear = ZoneInfoFile::LASTYEAR;
				break;
			}
			while (k < $nc(standardTransitions)->length) {
				int64_t trans_s = standardTransitions->get(k);
				if (trans_s >= ZoneInfoFile::UTC1900) {
					if (trans_s > trans) {
						break;
					}
					if (trans_s < trans) {
						if (nOffsets + 2 >= offsets->length) {
							$assign(offsets, $Arrays::copyOf(offsets, offsets->length + 100));
						}
						if (nTrans + 1 >= transitions->length) {
							$assign(transitions, $Arrays::copyOf(transitions, transitions->length + 100));
						}
						nOffsets = addTrans(transitions, nTrans++, offsets, nOffsets, trans_s, $nc(wallOffsets)->get(i), $nc(standardOffsets)->get(k + 1));
					}
				}
				++k;
			}
			if (nOffsets + 2 >= offsets->length) {
				$assign(offsets, $Arrays::copyOf(offsets, offsets->length + 100));
			}
			if (nTrans + 1 >= transitions->length) {
				$assign(transitions, $Arrays::copyOf(transitions, transitions->length + 100));
			}
			nOffsets = addTrans(transitions, nTrans++, offsets, nOffsets, trans, $nc(wallOffsets)->get(i + 1), getStandardOffset(standardTransitions, standardOffsets, trans));
		}
		while (k < $nc(standardTransitions)->length) {
			int64_t trans = standardTransitions->get(k);
			if (trans >= ZoneInfoFile::UTC1900) {
				int32_t offset = $nc(wallOffsets)->get(i);
				int32_t offsetIndex = indexOf(offsets, 0, nOffsets, offset);
				if (offsetIndex == nOffsets) {
					++nOffsets;
				}
				transitions->set(nTrans++, ($sl(trans * 1000, ZoneInfoFile::TRANSITION_NSHIFT)) | ((int64_t)(offsetIndex & (uint64_t)ZoneInfoFile::OFFSET_MASK)));
			}
			++k;
		}
		if ($nc(lastRules)->length > 1) {
			while (lastyear++ < ZoneInfoFile::LASTYEAR) {
				{
					$var($ZoneInfoFile$ZoneOffsetTransitionRuleArray, arr$, lastRules);
					int32_t len$ = arr$->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($ZoneInfoFile$ZoneOffsetTransitionRule, zotr, arr$->get(i$));
						{
							int64_t trans = $nc(zotr)->getTransitionEpochSecond(lastyear);
							if (nOffsets + 2 >= offsets->length) {
								$assign(offsets, $Arrays::copyOf(offsets, offsets->length + 100));
							}
							if (nTrans + 1 >= transitions->length) {
								$assign(transitions, $Arrays::copyOf(transitions, transitions->length + 100));
							}
							nOffsets = addTrans(transitions, nTrans++, offsets, nOffsets, trans, zotr->offsetAfter, zotr->standardOffset);
						}
					}
				}
			}
			$var($ZoneInfoFile$ZoneOffsetTransitionRule, startRule, lastRules->get(lastRules->length - 2));
			$var($ZoneInfoFile$ZoneOffsetTransitionRule, endRule, lastRules->get(lastRules->length - 1));
			$assign(params, $new($ints, 10));
			if ($nc(startRule)->offsetAfter - startRule->offsetBefore < 0 && $nc(endRule)->offsetAfter - endRule->offsetBefore > 0) {
				$var($ZoneInfoFile$ZoneOffsetTransitionRule, tmp, nullptr);
				$assign(tmp, startRule);
				$assign(startRule, endRule);
				$assign(endRule, tmp);
			}
			params->set(0, $nc(startRule)->month - 1);
			int32_t dom = startRule->dom;
			int32_t dow = startRule->dow;
			if (dow == -1) {
				params->set(1, dom);
				params->set(2, 0);
			} else {
				bool var$3 = dom < 0;
				if (!var$3) {
					bool var$4 = dom >= 24;
					if (var$4) {
						bool var$5 = $nc(zoneId)->equals("Asia/Gaza"_s);
						var$4 = !(var$5 || $nc(zoneId)->equals("Asia/Hebron"_s));
					}
					var$3 = var$4;
				}
				if (var$3) {
					params->set(1, -1);
					params->set(2, $nc(ZoneInfoFile::toCalendarDOW)->get(dow));
				} else {
					params->set(1, dom);
					params->set(2, -$nc(ZoneInfoFile::toCalendarDOW)->get(dow));
				}
			}
			params->set(3, startRule->secondOfDay * 1000);
			params->set(4, $nc(ZoneInfoFile::toSTZTime)->get(startRule->timeDefinition));
			params->set(5, $nc(endRule)->month - 1);
			dom = endRule->dom;
			dow = endRule->dow;
			if (dow == -1) {
				params->set(6, dom);
				params->set(7, 0);
			} else {
				bool var$9 = dom < 0;
				if (!var$9) {
					bool var$10 = dom >= 24;
					if (var$10) {
						bool var$11 = $nc(zoneId)->equals("Asia/Gaza"_s);
						var$10 = !(var$11 || $nc(zoneId)->equals("Asia/Hebron"_s));
					}
					var$9 = var$10;
				}
				if (var$9) {
					params->set(6, -1);
					params->set(7, $nc(ZoneInfoFile::toCalendarDOW)->get(dow));
				} else {
					params->set(6, dom);
					params->set(7, -$nc(ZoneInfoFile::toCalendarDOW)->get(dow));
				}
			}
			params->set(8, endRule->secondOfDay * 1000);
			params->set(9, $nc(ZoneInfoFile::toSTZTime)->get(endRule->timeDefinition));
			dstSavings = (startRule->offsetAfter - startRule->offsetBefore) * 1000;
			if (params->get(2) == 6 && params->get(3) == 0 && ($nc(zoneId)->equals("Asia/Amman"_s))) {
				params->set(2, 5);
				params->set(3, 0x05265C00);
			}
			if (params->get(2) == 7 && params->get(3) == 0 && ($nc(zoneId)->equals("Asia/Amman"_s))) {
				params->set(2, 6);
				params->set(3, 0x05265C00);
			}
			if (params->get(7) == 6 && params->get(8) == 0 && ($nc(zoneId)->equals("Africa/Cairo"_s))) {
				params->set(7, 5);
				params->set(8, 0x05265C00);
			}
		} else if (nTrans > 0) {
			if (lastyear < ZoneInfoFile::LASTYEAR) {
				int64_t trans = ZoneInfoFile::LDT2037 - rawOffset / 1000;
				int32_t offsetIndex = indexOf(offsets, 0, nOffsets, rawOffset / 1000);
				if (offsetIndex == nOffsets) {
					++nOffsets;
				}
				transitions->set(nTrans++, $sl(trans * 1000, ZoneInfoFile::TRANSITION_NSHIFT) | ((int64_t)(offsetIndex & (uint64_t)ZoneInfoFile::OFFSET_MASK)));
			} else if (savingsInstantTransitions->length > 2) {
				int32_t m = savingsInstantTransitions->length;
				int64_t startTrans = savingsInstantTransitions->get(m - 2);
				int32_t startOffset = $nc(wallOffsets)->get(m - 2 + 1);
				int32_t startStd = getStandardOffset(standardTransitions, standardOffsets, startTrans);
				int64_t endTrans = savingsInstantTransitions->get(m - 1);
				int32_t endOffset = wallOffsets->get(m - 1 + 1);
				int32_t endStd = getStandardOffset(standardTransitions, standardOffsets, endTrans);
				if (startOffset > startStd && endOffset == endStd) {
					m = savingsInstantTransitions->length - 2;
					$var($ZoneOffset, before, $ZoneOffset::ofTotalSeconds(wallOffsets->get(m)));
					$var($ZoneOffset, after, $ZoneOffset::ofTotalSeconds(wallOffsets->get(m + 1)));
					$var($LocalDateTime, ldt, $LocalDateTime::ofEpochSecond(savingsInstantTransitions->get(m), 0, before));
					$var($LocalDateTime, startLDT, nullptr);
					int32_t var$12 = $nc(after)->getTotalSeconds();
					if (var$12 > $nc(before)->getTotalSeconds()) {
						$assign(startLDT, ldt);
					} else {
						$assign(startLDT, $nc(ldt)->plusSeconds(wallOffsets->get(m + 1) - wallOffsets->get(m)));
					}
					m = savingsInstantTransitions->length - 1;
					$assign(before, $ZoneOffset::ofTotalSeconds(wallOffsets->get(m)));
					$assign(after, $ZoneOffset::ofTotalSeconds(wallOffsets->get(m + 1)));
					$assign(ldt, $LocalDateTime::ofEpochSecond(savingsInstantTransitions->get(m), 0, before));
					$var($LocalDateTime, endLDT, nullptr);
					int32_t var$13 = $nc(after)->getTotalSeconds();
					if (var$13 > $nc(before)->getTotalSeconds()) {
						$assign(endLDT, $nc(ldt)->plusSeconds(wallOffsets->get(m + 1) - wallOffsets->get(m)));
					} else {
						$assign(endLDT, ldt);
					}
					$assign(params, $new($ints, 10));
					params->set(0, $nc(startLDT)->getMonthValue() - 1);
					params->set(1, startLDT->getDayOfMonth());
					params->set(2, 0);
					params->set(3, $nc($(startLDT->toLocalTime()))->toSecondOfDay() * 1000);
					params->set(4, $SimpleTimeZone::WALL_TIME);
					params->set(5, $nc(endLDT)->getMonthValue() - 1);
					params->set(6, endLDT->getDayOfMonth());
					params->set(7, 0);
					params->set(8, $nc($(endLDT->toLocalTime()))->toSecondOfDay() * 1000);
					params->set(9, $SimpleTimeZone::WALL_TIME);
					dstSavings = (startOffset - startStd) * 1000;
				}
			}
		}
		if (transitions != nullptr && transitions->length != nTrans) {
			if (nTrans == 0) {
				$assign(transitions, nullptr);
			} else {
				$assign(transitions, $Arrays::copyOf(transitions, nTrans));
			}
		}
		if (offsets != nullptr && offsets->length != nOffsets) {
			if (nOffsets == 0) {
				$assign(offsets, nullptr);
			} else {
				$assign(offsets, $Arrays::copyOf(offsets, nOffsets));
			}
		}
		if (transitions != nullptr) {
			$var($ZoneInfoFile$Checksum, sum, $new($ZoneInfoFile$Checksum));
			for (i = 0; i < transitions->length; ++i) {
				int64_t val = transitions->get(i);
				int32_t dst = (int32_t)((int64_t)(($usr(val, ZoneInfoFile::DST_NSHIFT)) & (uint64_t)(int64_t)15));
				int32_t saving = (dst == 0) ? 0 : offsets->get(dst);
				int32_t index = (int32_t)((int64_t)(val & (uint64_t)ZoneInfoFile::OFFSET_MASK));
				int32_t offset = offsets->get(index);
				int64_t second = ($sr(val, ZoneInfoFile::TRANSITION_NSHIFT));
				sum->update(second + index);
				sum->update(index);
				sum->update(dst == 0 ? -1 : dst);
			}
			checksum = (int32_t)sum->getValue();
		}
	}
	return $new($ZoneInfo, zoneId, rawOffset, dstSavings, checksum, transitions, offsets, params, willGMTOffsetChange);
}

int32_t ZoneInfoFile::getStandardOffset($longs* standardTransitions, $ints* standardOffsets, int64_t epochSec) {
	$init(ZoneInfoFile);
	int32_t index = 0;
	for (; index < $nc(standardTransitions)->length; ++index) {
		if (epochSec < standardTransitions->get(index)) {
			break;
		}
	}
	return $nc(standardOffsets)->get(index);
}

int32_t ZoneInfoFile::getYear(int64_t epochSecond, int32_t offset) {
	$init(ZoneInfoFile);
	int64_t second = epochSecond + offset;
	int64_t epochDay = $Math::floorDiv(second, ZoneInfoFile::SECONDS_PER_DAY);
	int64_t zeroDay = epochDay + ZoneInfoFile::DAYS_0000_TO_1970;
	zeroDay -= 60;
	int64_t adjust = 0;
	if (zeroDay < 0) {
		int64_t adjustCycles = $div((zeroDay + 1), ZoneInfoFile::DAYS_PER_CYCLE) - 1;
		adjust = adjustCycles * 400;
		zeroDay += -adjustCycles * ZoneInfoFile::DAYS_PER_CYCLE;
	}
	int64_t yearEst = $div((400 * zeroDay + 591), ZoneInfoFile::DAYS_PER_CYCLE);
	int64_t doyEst = zeroDay - (365 * yearEst + yearEst / 4 - yearEst / 100 + yearEst / 400);
	if (doyEst < 0) {
		--yearEst;
		doyEst = zeroDay - (365 * yearEst + yearEst / 4 - yearEst / 100 + yearEst / 400);
	}
	yearEst += adjust;
	int32_t marchDoy0 = (int32_t)doyEst;
	int32_t marchMonth0 = (marchDoy0 * 5 + 2) / 153;
	int32_t month = (marchMonth0 + 2) % 12 + 1;
	int32_t dom = marchDoy0 - (marchMonth0 * 306 + 5) / 10 + 1;
	yearEst += marchMonth0 / 10;
	return (int32_t)yearEst;
}

int32_t ZoneInfoFile::indexOf($ints* offsets, int32_t from, int32_t nOffsets, int32_t offset) {
	$init(ZoneInfoFile);
	offset *= 1000;
	for (; from < nOffsets; ++from) {
		if ($nc(offsets)->get(from) == offset) {
			return from;
		}
	}
	$nc(offsets)->set(from, offset);
	return from;
}

int32_t ZoneInfoFile::addTrans($longs* transitions, int32_t nTrans, $ints* offsets, int32_t nOffsets, int64_t trans, int32_t offset, int32_t stdOffset) {
	$init(ZoneInfoFile);
	int32_t offsetIndex = indexOf(offsets, 0, nOffsets, offset);
	if (offsetIndex == nOffsets) {
		++nOffsets;
	}
	int32_t dstIndex = 0;
	if (offset != stdOffset) {
		dstIndex = indexOf(offsets, 1, nOffsets, offset - stdOffset);
		if (dstIndex == nOffsets) {
			++nOffsets;
		}
	}
	$nc(transitions)->set(nTrans, (($sl(trans * 1000, ZoneInfoFile::TRANSITION_NSHIFT)) | ((int64_t)(($sl(dstIndex, ZoneInfoFile::DST_NSHIFT)) & (uint64_t)ZoneInfoFile::DST_MASK))) | ((int64_t)(offsetIndex & (uint64_t)ZoneInfoFile::OFFSET_MASK)));
	return nOffsets;
}

void clinit$ZoneInfoFile($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$assignStatic(ZoneInfoFile::zones, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
	$assignStatic(ZoneInfoFile::aliases, $new($HashMap));
	$assignStatic(ZoneInfoFile::oldMappings, $new($StringArray2, {
		$$new($StringArray, {
			"ACT"_s,
			"Australia/Darwin"_s
		}),
		$$new($StringArray, {
			"AET"_s,
			"Australia/Sydney"_s
		}),
		$$new($StringArray, {
			"AGT"_s,
			"America/Argentina/Buenos_Aires"_s
		}),
		$$new($StringArray, {
			"ART"_s,
			"Africa/Cairo"_s
		}),
		$$new($StringArray, {
			"AST"_s,
			"America/Anchorage"_s
		}),
		$$new($StringArray, {
			"BET"_s,
			"America/Sao_Paulo"_s
		}),
		$$new($StringArray, {
			"BST"_s,
			"Asia/Dhaka"_s
		}),
		$$new($StringArray, {
			"CAT"_s,
			"Africa/Harare"_s
		}),
		$$new($StringArray, {
			"CNT"_s,
			"America/St_Johns"_s
		}),
		$$new($StringArray, {
			"CST"_s,
			"America/Chicago"_s
		}),
		$$new($StringArray, {
			"CTT"_s,
			"Asia/Shanghai"_s
		}),
		$$new($StringArray, {
			"EAT"_s,
			"Africa/Addis_Ababa"_s
		}),
		$$new($StringArray, {
			"ECT"_s,
			"Europe/Paris"_s
		}),
		$$new($StringArray, {
			"IET"_s,
			"America/Indiana/Indianapolis"_s
		}),
		$$new($StringArray, {
			"IST"_s,
			"Asia/Kolkata"_s
		}),
		$$new($StringArray, {
			"JST"_s,
			"Asia/Tokyo"_s
		}),
		$$new($StringArray, {
			"MIT"_s,
			"Pacific/Apia"_s
		}),
		$$new($StringArray, {
			"NET"_s,
			"Asia/Yerevan"_s
		}),
		$$new($StringArray, {
			"NST"_s,
			"Pacific/Auckland"_s
		}),
		$$new($StringArray, {
			"PLT"_s,
			"Asia/Karachi"_s
		}),
		$$new($StringArray, {
			"PNT"_s,
			"America/Phoenix"_s
		}),
		$$new($StringArray, {
			"PRT"_s,
			"America/Puerto_Rico"_s
		}),
		$$new($StringArray, {
			"PST"_s,
			"America/Los_Angeles"_s
		}),
		$$new($StringArray, {
			"SST"_s,
			"Pacific/Guadalcanal"_s
		}),
		$$new($StringArray, {
			"VST"_s,
			"Asia/Ho_Chi_Minh"_s
		})
	}));
	{
		$init($Locale);
		$var($String, oldmapping, $nc($($GetPropertyAction::privilegedGetProperty("sun.timezone.ids.oldmapping"_s, "false"_s)))->toLowerCase($Locale::ROOT));
		bool var$0 = oldmapping->equals("yes"_s);
		ZoneInfoFile::USE_OLDMAPPING = (var$0 || oldmapping->equals("true"_s));
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ZoneInfoFile$1)));
	}
	ZoneInfoFile::CURRT = $System::currentTimeMillis() / 1000;
	$assignStatic(ZoneInfoFile::toCalendarDOW, $new($ints, {
		-1,
		$Calendar::MONDAY,
		$Calendar::TUESDAY,
		$Calendar::WEDNESDAY,
		$Calendar::THURSDAY,
		$Calendar::FRIDAY,
		$Calendar::SATURDAY,
		$Calendar::SUNDAY
	}));
	$assignStatic(ZoneInfoFile::toSTZTime, $new($ints, {
		$SimpleTimeZone::UTC_TIME,
		$SimpleTimeZone::WALL_TIME,
		$SimpleTimeZone::STANDARD_TIME
	}));
}

ZoneInfoFile::ZoneInfoFile() {
}

$Class* ZoneInfoFile::load$($String* name, bool initialize) {
	$loadClass(ZoneInfoFile, name, initialize, &_ZoneInfoFile_ClassInfo_, clinit$ZoneInfoFile, allocate$ZoneInfoFile);
	return class$;
}

$Class* ZoneInfoFile::class$ = nullptr;

		} // calendar
	} // util
} // sun