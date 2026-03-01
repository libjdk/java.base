#include <java/time/ZoneId.h>

#include <java/io/DataOutput.h>
#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/time/DateTimeException.h>
#include <java/time/Instant.h>
#include <java/time/Ser.h>
#include <java/time/ZoneId$1.h>
#include <java/time/ZoneOffset.h>
#include <java/time/ZoneRegion.h>
#include <java/time/format/DateTimeFormatter.h>
#include <java/time/format/DateTimeFormatterBuilder.h>
#include <java/time/format/TextStyle.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalQueries.h>
#include <java/time/temporal/TemporalQuery.h>
#include <java/time/zone/ZoneRules.h>
#include <java/time/zone/ZoneRulesException.h>
#include <java/time/zone/ZoneRulesProvider.h>
#include <java/util/Collection.h>
#include <java/util/HashSet.h>
#include <java/util/Locale.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/TimeZone.h>
#include <jcpp.h>

#undef EPOCH
#undef SHORT_IDS
#undef UTC
#undef ZONE_REGION_TYPE

using $Map$EntryArray = $Array<::java::util::Map$Entry>;
using $DataOutput = ::java::io::DataOutput;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $DateTimeException = ::java::time::DateTimeException;
using $Instant = ::java::time::Instant;
using $Ser = ::java::time::Ser;
using $ZoneId$1 = ::java::time::ZoneId$1;
using $ZoneOffset = ::java::time::ZoneOffset;
using $ZoneRegion = ::java::time::ZoneRegion;
using $DateTimeFormatter = ::java::time::format::DateTimeFormatter;
using $DateTimeFormatterBuilder = ::java::time::format::DateTimeFormatterBuilder;
using $TextStyle = ::java::time::format::TextStyle;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalQueries = ::java::time::temporal::TemporalQueries;
using $ZoneRules = ::java::time::zone::ZoneRules;
using $ZoneRulesException = ::java::time::zone::ZoneRulesException;
using $ZoneRulesProvider = ::java::time::zone::ZoneRulesProvider;
using $Collection = ::java::util::Collection;
using $HashSet = ::java::util::HashSet;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $TimeZone = ::java::util::TimeZone;

namespace java {
	namespace time {

$CompoundAttribute _ZoneId_Annotations_[] = {
	{"Ljdk/internal/ValueBased;", nullptr},
	{}
};

$FieldInfo _ZoneId_FieldInfo_[] = {
	{"SHORT_IDS", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PUBLIC | $STATIC | $FINAL, $staticField(ZoneId, SHORT_IDS)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ZoneId, serialVersionUID)},
	{}
};

$MethodInfo _ZoneId_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(ZoneId, init$, void)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ZoneId, equals, bool, Object$*)},
	{"from", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/ZoneId;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZoneId, from, ZoneId*, $TemporalAccessor*)},
	{"getAvailableZoneIds", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(ZoneId, getAvailableZoneIds, $Set*)},
	{"getDisplayName", "(Ljava/time/format/TextStyle;Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ZoneId, getDisplayName, $String*, $TextStyle*, $Locale*)},
	{"getId", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ZoneId, getId, $String*)},
	{"getRules", "()Ljava/time/zone/ZoneRules;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ZoneId, getRules, $ZoneRules*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(ZoneId, hashCode, int32_t)},
	{"normalized", "()Ljava/time/ZoneId;", nullptr, $PUBLIC, $virtualMethod(ZoneId, normalized, ZoneId*)},
	{"of", "(Ljava/lang/String;Ljava/util/Map;)Ljava/time/ZoneId;", "(Ljava/lang/String;Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)Ljava/time/ZoneId;", $PUBLIC | $STATIC, $staticMethod(ZoneId, of, ZoneId*, $String*, $Map*)},
	{"of", "(Ljava/lang/String;)Ljava/time/ZoneId;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZoneId, of, ZoneId*, $String*)},
	{"of", "(Ljava/lang/String;Z)Ljava/time/ZoneId;", nullptr, $STATIC, $staticMethod(ZoneId, of, ZoneId*, $String*, bool)},
	{"ofOffset", "(Ljava/lang/String;Ljava/time/ZoneOffset;)Ljava/time/ZoneId;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZoneId, ofOffset, ZoneId*, $String*, $ZoneOffset*)},
	{"ofWithPrefix", "(Ljava/lang/String;IZ)Ljava/time/ZoneId;", nullptr, $PRIVATE | $STATIC, $staticMethod(ZoneId, ofWithPrefix, ZoneId*, $String*, int32_t, bool)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(ZoneId, readObject, void, $ObjectInputStream*), "java.io.InvalidObjectException"},
	{"systemDefault", "()Ljava/time/ZoneId;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZoneId, systemDefault, ZoneId*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ZoneId, toString, $String*)},
	{"toTemporal", "()Ljava/time/temporal/TemporalAccessor;", nullptr, $PRIVATE, $method(ZoneId, toTemporal, $TemporalAccessor*)},
	{"write", "(Ljava/io/DataOutput;)V", nullptr, $ABSTRACT, $virtualMethod(ZoneId, write, void, $DataOutput*), "java.io.IOException"},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(ZoneId, writeReplace, $Object*)},
	{}
};

$InnerClassInfo _ZoneId_InnerClassesInfo_[] = {
	{"java.time.ZoneId$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ZoneId_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.time.ZoneId",
	"java.lang.Object",
	"java.io.Serializable",
	_ZoneId_FieldInfo_,
	_ZoneId_MethodInfo_,
	nullptr,
	nullptr,
	_ZoneId_InnerClassesInfo_,
	_ZoneId_Annotations_,
	nullptr,
	"java.time.ZoneId$1"
};

$Object* allocate$ZoneId($Class* clazz) {
	return $of($alloc(ZoneId));
}

$Map* ZoneId::SHORT_IDS = nullptr;

ZoneId* ZoneId::systemDefault() {
	$init(ZoneId);
	return $nc($($TimeZone::getDefault()))->toZoneId();
}

$Set* ZoneId::getAvailableZoneIds() {
	$init(ZoneId);
	return $new($HashSet, $(static_cast<$Collection*>($ZoneRulesProvider::getAvailableZoneIds())));
}

ZoneId* ZoneId::of($String* zoneId, $Map* aliasMap) {
	$init(ZoneId);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(zoneId), "zoneId"_s);
	$Objects::requireNonNull($of(aliasMap), "aliasMap"_s);
	$var($String, id, $cast($String, $Objects::requireNonNullElse($cast($String, $($nc(aliasMap)->get(zoneId))), zoneId)));
	return of(id);
}

ZoneId* ZoneId::of($String* zoneId) {
	$init(ZoneId);
	return of(zoneId, true);
}

ZoneId* ZoneId::ofOffset($String* prefix$renamed, $ZoneOffset* offset) {
	$init(ZoneId);
	$useLocalCurrentObjectStackCache();
	$var($String, prefix, prefix$renamed);
	$Objects::requireNonNull($of(prefix), "prefix"_s);
	$Objects::requireNonNull($of(offset), "offset"_s);
	if ($nc(prefix)->isEmpty()) {
		return offset;
	}
	bool var$1 = !$nc(prefix)->equals("GMT"_s);
	bool var$0 = var$1 && !prefix->equals("UTC"_s);
	if (var$0 && !prefix->equals("UT"_s)) {
		$throwNew($IllegalArgumentException, $$str({"prefix should be GMT, UTC or UT, is: "_s, prefix}));
	}
	if ($nc(offset)->getTotalSeconds() != 0) {
		$assign(prefix, $nc(prefix)->concat($(offset->getId())));
	}
	return $new($ZoneRegion, prefix, $($nc(offset)->getRules()));
}

ZoneId* ZoneId::of($String* zoneId, bool checkAvailable) {
	$init(ZoneId);
	$Objects::requireNonNull($of(zoneId), "zoneId"_s);
	bool var$1 = $nc(zoneId)->length() <= 1;
	bool var$0 = var$1 || $nc(zoneId)->startsWith("+"_s);
	if (var$0 || $nc(zoneId)->startsWith("-"_s)) {
		return $ZoneOffset::of(zoneId);
	} else {
		bool var$3 = zoneId->startsWith("UTC"_s);
		if (var$3 || zoneId->startsWith("GMT"_s)) {
			return ofWithPrefix(zoneId, 3, checkAvailable);
		} else if (zoneId->startsWith("UT"_s)) {
			return ofWithPrefix(zoneId, 2, checkAvailable);
		}
	}
	return $ZoneRegion::ofId(zoneId, checkAvailable);
}

ZoneId* ZoneId::ofWithPrefix($String* zoneId, int32_t prefixLength, bool checkAvailable) {
	$init(ZoneId);
	$useLocalCurrentObjectStackCache();
	$var($String, prefix, $nc(zoneId)->substring(0, prefixLength));
	if (zoneId->length() == prefixLength) {
		$init($ZoneOffset);
		return ofOffset(prefix, $ZoneOffset::UTC);
	}
	bool var$0 = zoneId->charAt(prefixLength) != u'+';
	if (var$0 && zoneId->charAt(prefixLength) != u'-') {
		return $ZoneRegion::ofId(zoneId, checkAvailable);
	}
	try {
		$var($ZoneOffset, offset, $ZoneOffset::of($(zoneId->substring(prefixLength))));
		if (offset == $ZoneOffset::UTC) {
			return ofOffset(prefix, offset);
		}
		return ofOffset(prefix, offset);
	} catch ($DateTimeException& ex) {
		$throwNew($DateTimeException, $$str({"Invalid ID for offset-based ZoneId: "_s, zoneId}), ex);
	}
	$shouldNotReachHere();
}

ZoneId* ZoneId::from($TemporalAccessor* temporal) {
	$init(ZoneId);
	$useLocalCurrentObjectStackCache();
	$var(ZoneId, obj, $cast(ZoneId, $nc(temporal)->query($($TemporalQueries::zone()))));
	if (obj == nullptr) {
		$var($String, var$0, $$str({"Unable to obtain ZoneId from TemporalAccessor: "_s, temporal, " of type "_s}));
		$throwNew($DateTimeException, $$concat(var$0, $($of(temporal)->getClass()->getName())));
	}
	return obj;
}

void ZoneId::init$() {
	$load($ZoneOffset);
	bool var$0 = $of(this)->getClass() != $ZoneOffset::class$;
	$load($ZoneRegion);
	if (var$0 && $of(this)->getClass() != $ZoneRegion::class$) {
		$throwNew($AssertionError, $of("Invalid subclass"_s));
	}
}

$String* ZoneId::getDisplayName($TextStyle* style, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	return $nc($($nc($($$new($DateTimeFormatterBuilder)->appendZoneText(style)))->toFormatter(locale)))->format($(toTemporal()));
}

$TemporalAccessor* ZoneId::toTemporal() {
	return $new($ZoneId$1, this);
}

ZoneId* ZoneId::normalized() {
	try {
		$var($ZoneRules, rules, getRules());
		if ($nc(rules)->isFixedOffset()) {
			$init($Instant);
			return rules->getOffset($Instant::EPOCH);
		}
	} catch ($ZoneRulesException& ex) {
	}
	return this;
}

bool ZoneId::equals(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	if ($equals(this, obj)) {
		return true;
	}
	$var(ZoneId, other, nullptr);
	bool var$1 = $instanceOf(ZoneId, obj);
	if (var$1) {
		$assign(other, $cast(ZoneId, obj));
		var$1 = true;
	}
	bool var$0 = (var$1);
	return var$0 && $nc($(getId()))->equals($($nc(other)->getId()));
}

int32_t ZoneId::hashCode() {
	return $nc($(getId()))->hashCode();
}

void ZoneId::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

$String* ZoneId::toString() {
	return getId();
}

$Object* ZoneId::writeReplace() {
	return $of($new($Ser, $Ser::ZONE_REGION_TYPE, this));
}

void clinit$ZoneId($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(ZoneId::SHORT_IDS, $Map::ofEntries($$new($Map$EntryArray, {
		$($Map::entry("ACT"_s, "Australia/Darwin"_s)),
		$($Map::entry("AET"_s, "Australia/Sydney"_s)),
		$($Map::entry("AGT"_s, "America/Argentina/Buenos_Aires"_s)),
		$($Map::entry("ART"_s, "Africa/Cairo"_s)),
		$($Map::entry("AST"_s, "America/Anchorage"_s)),
		$($Map::entry("BET"_s, "America/Sao_Paulo"_s)),
		$($Map::entry("BST"_s, "Asia/Dhaka"_s)),
		$($Map::entry("CAT"_s, "Africa/Harare"_s)),
		$($Map::entry("CNT"_s, "America/St_Johns"_s)),
		$($Map::entry("CST"_s, "America/Chicago"_s)),
		$($Map::entry("CTT"_s, "Asia/Shanghai"_s)),
		$($Map::entry("EAT"_s, "Africa/Addis_Ababa"_s)),
		$($Map::entry("ECT"_s, "Europe/Paris"_s)),
		$($Map::entry("IET"_s, "America/Indiana/Indianapolis"_s)),
		$($Map::entry("IST"_s, "Asia/Kolkata"_s)),
		$($Map::entry("JST"_s, "Asia/Tokyo"_s)),
		$($Map::entry("MIT"_s, "Pacific/Apia"_s)),
		$($Map::entry("NET"_s, "Asia/Yerevan"_s)),
		$($Map::entry("NST"_s, "Pacific/Auckland"_s)),
		$($Map::entry("PLT"_s, "Asia/Karachi"_s)),
		$($Map::entry("PNT"_s, "America/Phoenix"_s)),
		$($Map::entry("PRT"_s, "America/Puerto_Rico"_s)),
		$($Map::entry("PST"_s, "America/Los_Angeles"_s)),
		$($Map::entry("SST"_s, "Pacific/Guadalcanal"_s)),
		$($Map::entry("VST"_s, "Asia/Ho_Chi_Minh"_s)),
		$($Map::entry("EST"_s, "-05:00"_s)),
		$($Map::entry("MST"_s, "-07:00"_s)),
		$($Map::entry("HST"_s, "-10:00"_s))
	})));
}

ZoneId::ZoneId() {
}

$Class* ZoneId::load$($String* name, bool initialize) {
	$loadClass(ZoneId, name, initialize, &_ZoneId_ClassInfo_, clinit$ZoneId, allocate$ZoneId);
	return class$;
}

$Class* ZoneId::class$ = nullptr;

	} // time
} // java