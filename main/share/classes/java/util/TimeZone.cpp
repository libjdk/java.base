#include <java/util/TimeZone.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/lang/SecurityManager.h>
#include <java/security/Permission.h>
#include <java/time/ZoneId.h>
#include <java/util/Date.h>
#include <java/util/Locale$Category.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Properties.h>
#include <java/util/PropertyPermission.h>
#include <jdk/internal/util/StaticProperty.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/util/calendar/ZoneInfo.h>
#include <sun/util/calendar/ZoneInfoFile.h>
#include <sun/util/locale/provider/TimeZoneNameUtility.h>
#include <jcpp.h>

#undef DISPLAY
#undef GMT_ID
#undef GMT_ID_LENGTH
#undef ID
#undef LONG
#undef NO_TIMEZONE
#undef ONE_DAY
#undef ONE_HOUR
#undef ONE_MINUTE
#undef SHORT
#undef SHORT_IDS

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $SecurityManager = ::java::lang::SecurityManager;
using $Permission = ::java::security::Permission;
using $ZoneId = ::java::time::ZoneId;
using $Date = ::java::util::Date;
using $Locale = ::java::util::Locale;
using $Locale$Category = ::java::util::Locale$Category;
using $Properties = ::java::util::Properties;
using $PropertyPermission = ::java::util::PropertyPermission;
using $StaticProperty = ::jdk::internal::util::StaticProperty;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $ZoneInfo = ::sun::util::calendar::ZoneInfo;
using $ZoneInfoFile = ::sun::util::calendar::ZoneInfoFile;
using $TimeZoneNameUtility = ::sun::util::locale::provider::TimeZoneNameUtility;

namespace java {
	namespace util {

$FieldInfo _TimeZone_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(TimeZone, $assertionsDisabled)},
	{"SHORT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(TimeZone, SHORT)},
	{"LONG", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(TimeZone, LONG)},
	{"ONE_MINUTE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TimeZone, ONE_MINUTE)},
	{"ONE_HOUR", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TimeZone, ONE_HOUR)},
	{"ONE_DAY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TimeZone, ONE_DAY)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(TimeZone, serialVersionUID)},
	{"NO_TIMEZONE", "Ljava/util/TimeZone;", nullptr, $STATIC | $FINAL, $staticField(TimeZone, NO_TIMEZONE)},
	{"ID", "Ljava/lang/String;", nullptr, $PRIVATE, $field(TimeZone, ID)},
	{"zoneId", "Ljava/time/ZoneId;", nullptr, $PRIVATE | $TRANSIENT, $field(TimeZone, zoneId)},
	{"defaultTimeZone", "Ljava/util/TimeZone;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(TimeZone, defaultTimeZone)},
	{"GMT_ID", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(TimeZone, GMT_ID)},
	{"GMT_ID_LENGTH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TimeZone, GMT_ID_LENGTH)},
	{}
};

$MethodInfo _TimeZone_MethodInfo_[] = {
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(TimeZone, init$, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(TimeZone, clone, $Object*)},
	{"getAvailableIDs", "(I)[Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $staticMethod(TimeZone, getAvailableIDs, $StringArray*, int32_t)},
	{"getAvailableIDs", "()[Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $staticMethod(TimeZone, getAvailableIDs, $StringArray*)},
	{"getDSTSavings", "()I", nullptr, $PUBLIC, $virtualMethod(TimeZone, getDSTSavings, int32_t)},
	{"getDefault", "()Ljava/util/TimeZone;", nullptr, $PUBLIC | $STATIC, $staticMethod(TimeZone, getDefault, TimeZone*)},
	{"getDefaultRef", "()Ljava/util/TimeZone;", nullptr, $STATIC, $staticMethod(TimeZone, getDefaultRef, TimeZone*)},
	{"getDisplayName", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $method(TimeZone, getDisplayName, $String*)},
	{"getDisplayName", "(Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $method(TimeZone, getDisplayName, $String*, $Locale*)},
	{"getDisplayName", "(ZI)Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $method(TimeZone, getDisplayName, $String*, bool, int32_t)},
	{"getDisplayName", "(ZILjava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(TimeZone, getDisplayName, $String*, bool, int32_t, $Locale*)},
	{"getDisplayNames", "(Ljava/lang/String;Ljava/util/Locale;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(TimeZone, getDisplayNames, $StringArray*, $String*, $Locale*)},
	{"getID", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(TimeZone, getID, $String*)},
	{"getOffset", "(IIIIII)I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(TimeZone, getOffset, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t)},
	{"getOffset", "(J)I", nullptr, $PUBLIC, $virtualMethod(TimeZone, getOffset, int32_t, int64_t)},
	{"getOffsets", "(J[I)I", nullptr, 0, $virtualMethod(TimeZone, getOffsets, int32_t, int64_t, $ints*)},
	{"getRawOffset", "()I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(TimeZone, getRawOffset, int32_t)},
	{"getSystemGMTOffsetID", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(TimeZone, getSystemGMTOffsetID, $String*)},
	{"getSystemTimeZoneID", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(TimeZone, getSystemTimeZoneID, $String*, $String*)},
	{"getTimeZone", "(Ljava/lang/String;)Ljava/util/TimeZone;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $staticMethod(TimeZone, getTimeZone, TimeZone*, $String*)},
	{"getTimeZone", "(Ljava/time/ZoneId;)Ljava/util/TimeZone;", nullptr, $PUBLIC | $STATIC, $staticMethod(TimeZone, getTimeZone, TimeZone*, $ZoneId*)},
	{"getTimeZone", "(Ljava/lang/String;Z)Ljava/util/TimeZone;", nullptr, $PRIVATE | $STATIC, $staticMethod(TimeZone, getTimeZone, TimeZone*, $String*, bool)},
	{"hasSameRules", "(Ljava/util/TimeZone;)Z", nullptr, $PUBLIC, $virtualMethod(TimeZone, hasSameRules, bool, TimeZone*)},
	{"inDaylightTime", "(Ljava/util/Date;)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(TimeZone, inDaylightTime, bool, $Date*)},
	{"observesDaylightTime", "()Z", nullptr, $PUBLIC, $virtualMethod(TimeZone, observesDaylightTime, bool)},
	{"parseCustomTimeZone", "(Ljava/lang/String;)Ljava/util/TimeZone;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(TimeZone, parseCustomTimeZone, TimeZone*, $String*)},
	{"setDefault", "(Ljava/util/TimeZone;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(TimeZone, setDefault, void, TimeZone*)},
	{"setDefaultZone", "()Ljava/util/TimeZone;", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $staticMethod(TimeZone, setDefaultZone, TimeZone*)},
	{"setID", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(TimeZone, setID, void, $String*)},
	{"setRawOffset", "(I)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(TimeZone, setRawOffset, void, int32_t)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"toZoneId", "()Ljava/time/ZoneId;", nullptr, $PUBLIC, $virtualMethod(TimeZone, toZoneId, $ZoneId*)},
	{"toZoneId0", "()Ljava/time/ZoneId;", nullptr, $PRIVATE, $method(TimeZone, toZoneId0, $ZoneId*)},
	{"useDaylightTime", "()Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(TimeZone, useDaylightTime, bool)},
	{}
};

#define _METHOD_INDEX_getSystemGMTOffsetID 20
#define _METHOD_INDEX_getSystemTimeZoneID 21

$ClassInfo _TimeZone_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.util.TimeZone",
	"java.lang.Object",
	"java.io.Serializable,java.lang.Cloneable",
	_TimeZone_FieldInfo_,
	_TimeZone_MethodInfo_
};

$Object* allocate$TimeZone($Class* clazz) {
	return $of($alloc(TimeZone));
}

int32_t TimeZone::hashCode() {
	 return this->$Serializable::hashCode();
}

bool TimeZone::equals(Object$* obj) {
	 return this->$Serializable::equals(obj);
}

$String* TimeZone::toString() {
	 return this->$Serializable::toString();
}

void TimeZone::finalize() {
	this->$Serializable::finalize();
}

bool TimeZone::$assertionsDisabled = false;
TimeZone* TimeZone::NO_TIMEZONE = nullptr;
$volatile(TimeZone*) TimeZone::defaultTimeZone = nullptr;
$String* TimeZone::GMT_ID = nullptr;

void TimeZone::init$() {
}

int32_t TimeZone::getOffset(int64_t date) {
	if (inDaylightTime($$new($Date, date))) {
		int32_t var$0 = getRawOffset();
		return var$0 + getDSTSavings();
	}
	return getRawOffset();
}

int32_t TimeZone::getOffsets(int64_t date, $ints* offsets) {
	int32_t rawoffset = getRawOffset();
	int32_t dstoffset = 0;
	if (inDaylightTime($$new($Date, date))) {
		dstoffset = getDSTSavings();
	}
	if (offsets != nullptr) {
		offsets->set(0, rawoffset);
		offsets->set(1, dstoffset);
	}
	return rawoffset + dstoffset;
}

$String* TimeZone::getID() {
	return this->ID;
}

void TimeZone::setID($String* ID) {
	if (ID == nullptr) {
		$throwNew($NullPointerException);
	}
	$set(this, ID, ID);
	$set(this, zoneId, nullptr);
}

$String* TimeZone::getDisplayName() {
	$init($Locale$Category);
	return getDisplayName(false, TimeZone::LONG, $($Locale::getDefault($Locale$Category::DISPLAY)));
}

$String* TimeZone::getDisplayName($Locale* locale) {
	return getDisplayName(false, TimeZone::LONG, locale);
}

$String* TimeZone::getDisplayName(bool daylight, int32_t style) {
	$init($Locale$Category);
	return getDisplayName(daylight, style, $($Locale::getDefault($Locale$Category::DISPLAY)));
}

$String* TimeZone::getDisplayName(bool daylight, int32_t style, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	if (style != TimeZone::SHORT && style != TimeZone::LONG) {
		$throwNew($IllegalArgumentException, $$str({"Illegal style: "_s, $$str(style)}));
	}
	$var($String, id, getID());
	$var($String, name, $TimeZoneNameUtility::retrieveDisplayName(id, daylight, style, locale));
	if (name != nullptr) {
		return name;
	}
	bool var$0 = $nc(id)->startsWith("GMT"_s);
	if (var$0 && id->length() > 3) {
		char16_t sign = id->charAt(3);
		if (sign == u'+' || sign == u'-') {
			return id;
		}
	}
	int32_t offset = getRawOffset();
	if (daylight) {
		offset += getDSTSavings();
	}
	return $ZoneInfoFile::toCustomID(offset);
}

$StringArray* TimeZone::getDisplayNames($String* id, $Locale* locale) {
	$init(TimeZone);
	return $TimeZoneNameUtility::retrieveDisplayNames(id, locale);
}

int32_t TimeZone::getDSTSavings() {
	if (useDaylightTime()) {
		return 0x0036EE80;
	}
	return 0;
}

bool TimeZone::observesDaylightTime() {
	bool var$0 = useDaylightTime();
	return var$0 || inDaylightTime($$new($Date));
}

TimeZone* TimeZone::getTimeZone($String* ID) {
	$load(TimeZone);
	$synchronized(class$) {
		$init(TimeZone);
		return getTimeZone(ID, true);
	}
}

TimeZone* TimeZone::getTimeZone($ZoneId* zoneId) {
	$init(TimeZone);
	$var($String, tzid, $nc(zoneId)->getId());
	char16_t c = $nc(tzid)->charAt(0);
	if (c == u'+' || c == u'-') {
		$assign(tzid, $str({"GMT"_s, tzid}));
	} else if (c == u'Z' && tzid->length() == 1) {
		$assign(tzid, "UTC"_s);
	}
	return getTimeZone(tzid, true);
}

$ZoneId* TimeZone::toZoneId() {
	$var($ZoneId, zId, this->zoneId);
	if (zId == nullptr) {
		$set(this, zoneId, ($assign(zId, toZoneId0())));
	}
	return zId;
}

$ZoneId* TimeZone::toZoneId0() {
	$useLocalCurrentObjectStackCache();
	$var($String, id, getID());
	$var(TimeZone, defaultZone, TimeZone::defaultTimeZone);
	if (defaultZone != this && defaultZone != nullptr && $nc(id)->equals($(defaultZone->getID()))) {
		return defaultZone->toZoneId();
	}
	bool var$0 = $ZoneInfoFile::useOldMapping();
	if (var$0 && $nc(id)->length() == 3) {
		if ("EST"_s->equals(id)) {
			return $ZoneId::of("America/New_York"_s);
		}
		if ("MST"_s->equals(id)) {
			return $ZoneId::of("America/Denver"_s);
		}
		if ("HST"_s->equals(id)) {
			return $ZoneId::of("America/Honolulu"_s);
		}
	}
	$init($ZoneId);
	return $ZoneId::of(id, $ZoneId::SHORT_IDS);
}

TimeZone* TimeZone::getTimeZone($String* ID, bool fallback) {
	$init(TimeZone);
	$var(TimeZone, tz, $ZoneInfo::getTimeZone(ID));
	if (tz == nullptr) {
		$assign(tz, parseCustomTimeZone(ID));
		if (tz == nullptr && fallback) {
			$assign(tz, $new($ZoneInfo, TimeZone::GMT_ID, 0));
		}
	}
	return tz;
}

$StringArray* TimeZone::getAvailableIDs(int32_t rawOffset) {
	$load(TimeZone);
	$synchronized(class$) {
		$init(TimeZone);
		return $ZoneInfo::getAvailableIDs(rawOffset);
	}
}

$StringArray* TimeZone::getAvailableIDs() {
	$load(TimeZone);
	$synchronized(class$) {
		$init(TimeZone);
		return $ZoneInfo::getAvailableIDs();
	}
}

$String* TimeZone::getSystemTimeZoneID($String* javaHome) {
	$init(TimeZone);
	$var($String, $ret, nullptr);
	$prepareNativeStatic(TimeZone, getSystemTimeZoneID, $String*, $String* javaHome);
	$assign($ret, $invokeNativeStaticObject(javaHome));
	$finishNativeStatic();
	return $ret;
}

$String* TimeZone::getSystemGMTOffsetID() {
	$init(TimeZone);
	$var($String, $ret, nullptr);
	$prepareNativeStatic(TimeZone, getSystemGMTOffsetID, $String*);
	$assign($ret, $invokeNativeStaticObject());
	$finishNativeStatic();
	return $ret;
}

TimeZone* TimeZone::getDefault() {
	$init(TimeZone);
	return $cast(TimeZone, $nc($(getDefaultRef()))->clone());
}

TimeZone* TimeZone::getDefaultRef() {
	$init(TimeZone);
	$var(TimeZone, defaultZone, TimeZone::defaultTimeZone);
	if (defaultZone == nullptr) {
		$assign(defaultZone, setDefaultZone());
		if (!TimeZone::$assertionsDisabled && !(defaultZone != nullptr)) {
			$throwNew($AssertionError);
		}
	}
	return defaultZone;
}

TimeZone* TimeZone::setDefaultZone() {
	$load(TimeZone);
	$synchronized(class$) {
		$init(TimeZone);
		$useLocalCurrentObjectStackCache();
		$var(TimeZone, tz, nullptr);
		$var($Properties, props, $GetPropertyAction::privilegedGetProperties());
		$var($String, zoneID, $nc(props)->getProperty("user.timezone"_s));
		if (zoneID == nullptr || $nc(zoneID)->isEmpty()) {
			$var($String, javaHome, $StaticProperty::javaHome());
			try {
				$assign(zoneID, getSystemTimeZoneID(javaHome));
				if (zoneID == nullptr) {
					$assign(zoneID, TimeZone::GMT_ID);
				}
			} catch ($NullPointerException& e) {
				$assign(zoneID, TimeZone::GMT_ID);
			}
		}
		$assign(tz, getTimeZone(zoneID, false));
		if (tz == nullptr) {
			$var($String, gmtOffsetID, getSystemGMTOffsetID());
			if (gmtOffsetID != nullptr) {
				$assign(zoneID, gmtOffsetID);
			}
			$assign(tz, getTimeZone(zoneID, true));
		}
		if (!TimeZone::$assertionsDisabled && !(tz != nullptr)) {
			$throwNew($AssertionError);
		}
		$var($String, id, zoneID);
		props->setProperty("user.timezone"_s, id);
		$assignStatic(TimeZone::defaultTimeZone, tz);
		return tz;
	}
}

void TimeZone::setDefault(TimeZone* zone) {
	$init(TimeZone);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($PropertyPermission, "user.timezone"_s, "write"_s));
	}
	$assignStatic(TimeZone::defaultTimeZone, (zone == nullptr) ? (TimeZone*)nullptr : $cast(TimeZone, $nc(zone)->clone()));
}

bool TimeZone::hasSameRules(TimeZone* other) {
	bool var$1 = other != nullptr;
	if (var$1) {
		int32_t var$2 = getRawOffset();
		var$1 = var$2 == other->getRawOffset();
	}
	bool var$0 = var$1;
	if (var$0) {
		bool var$3 = useDaylightTime();
		var$0 = var$3 == other->useDaylightTime();
	}
	return var$0;
}

$Object* TimeZone::clone() {
	try {
		return $of($Serializable::clone());
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

TimeZone* TimeZone::parseCustomTimeZone($String* id) {
	$init(TimeZone);
	int32_t length = 0;
	bool var$0 = (length = $nc(id)->length()) < (TimeZone::GMT_ID_LENGTH + 2);
	if (var$0 || $nc(id)->indexOf(TimeZone::GMT_ID) != 0) {
		return nullptr;
	}
	$var($ZoneInfo, zi, nullptr);
	$assign(zi, $ZoneInfoFile::getZoneInfo(id));
	if (zi != nullptr) {
		return zi;
	}
	int32_t index = TimeZone::GMT_ID_LENGTH;
	bool negative = false;
	char16_t c = $nc(id)->charAt(index++);
	if (c == u'-') {
		negative = true;
	} else if (c != u'+') {
		return nullptr;
	}
	int32_t hours = 0;
	int32_t num = 0;
	int32_t countDelim = 0;
	int32_t len = 0;
	while (index < length) {
		c = id->charAt(index++);
		if (c == u':') {
			if (countDelim > 0) {
				return nullptr;
			}
			if (len > 2) {
				return nullptr;
			}
			hours = num;
			++countDelim;
			num = 0;
			len = 0;
			continue;
		}
		if (c < u'0' || c > u'9') {
			return nullptr;
		}
		num = num * 10 + (c - u'0');
		++len;
	}
	if (index != length) {
		return nullptr;
	}
	if (countDelim == 0) {
		if (len <= 2) {
			hours = num;
			num = 0;
		} else {
			hours = num / 100;
			$modAssign(num, 100);
		}
	} else if (len != 2) {
		return nullptr;
	}
	if (hours > 23 || num > 59) {
		return nullptr;
	}
	int32_t gmtOffset = (hours * 60 + num) * 60 * 1000;
	if (gmtOffset == 0) {
		$assign(zi, $ZoneInfoFile::getZoneInfo(TimeZone::GMT_ID));
		if (negative) {
			$nc(zi)->setID("GMT-00:00"_s);
		} else {
			$nc(zi)->setID("GMT+00:00"_s);
		}
	} else {
		$assign(zi, $ZoneInfoFile::getCustomTimeZone(id, negative ? -gmtOffset : gmtOffset));
	}
	return zi;
}

void clinit$TimeZone($Class* class$) {
	$assignStatic(TimeZone::GMT_ID, "GMT"_s);
	TimeZone::$assertionsDisabled = !TimeZone::class$->desiredAssertionStatus();
	$assignStatic(TimeZone::NO_TIMEZONE, nullptr);
}

TimeZone::TimeZone() {
}

$Class* TimeZone::load$($String* name, bool initialize) {
	$loadClass(TimeZone, name, initialize, &_TimeZone_ClassInfo_, clinit$TimeZone, allocate$TimeZone);
	return class$;
}

$Class* TimeZone::class$ = nullptr;

	} // util
} // java