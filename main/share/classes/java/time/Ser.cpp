#include <java/time/Ser.h>

#include <java/io/DataInput.h>
#include <java/io/DataOutput.h>
#include <java/io/InvalidClassException.h>
#include <java/io/ObjectInput.h>
#include <java/io/ObjectOutput.h>
#include <java/io/Serializable.h>
#include <java/io/StreamCorruptedException.h>
#include <java/time/Duration.h>
#include <java/time/Instant.h>
#include <java/time/LocalDate.h>
#include <java/time/LocalDateTime.h>
#include <java/time/LocalTime.h>
#include <java/time/MonthDay.h>
#include <java/time/OffsetDateTime.h>
#include <java/time/OffsetTime.h>
#include <java/time/Period.h>
#include <java/time/Year.h>
#include <java/time/YearMonth.h>
#include <java/time/ZoneId.h>
#include <java/time/ZoneOffset.h>
#include <java/time/ZoneRegion.h>
#include <java/time/ZonedDateTime.h>
#include <jcpp.h>

#undef DURATION_TYPE
#undef INSTANT_TYPE
#undef LOCAL_DATE_TIME_TYPE
#undef LOCAL_DATE_TYPE
#undef LOCAL_TIME_TYPE
#undef MONTH_DAY_TYPE
#undef OFFSET_DATE_TIME_TYPE
#undef OFFSET_TIME_TYPE
#undef PERIOD_TYPE
#undef YEAR_MONTH_TYPE
#undef YEAR_TYPE
#undef ZONE_DATE_TIME_TYPE
#undef ZONE_OFFSET_TYPE
#undef ZONE_REGION_TYPE

using $DataInput = ::java::io::DataInput;
using $DataOutput = ::java::io::DataOutput;
using $InvalidClassException = ::java::io::InvalidClassException;
using $ObjectInput = ::java::io::ObjectInput;
using $ObjectOutput = ::java::io::ObjectOutput;
using $Serializable = ::java::io::Serializable;
using $StreamCorruptedException = ::java::io::StreamCorruptedException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Duration = ::java::time::Duration;
using $Instant = ::java::time::Instant;
using $LocalDate = ::java::time::LocalDate;
using $LocalDateTime = ::java::time::LocalDateTime;
using $LocalTime = ::java::time::LocalTime;
using $MonthDay = ::java::time::MonthDay;
using $OffsetDateTime = ::java::time::OffsetDateTime;
using $OffsetTime = ::java::time::OffsetTime;
using $Period = ::java::time::Period;
using $Year = ::java::time::Year;
using $YearMonth = ::java::time::YearMonth;
using $ZoneOffset = ::java::time::ZoneOffset;
using $ZoneRegion = ::java::time::ZoneRegion;
using $ZonedDateTime = ::java::time::ZonedDateTime;

namespace java {
	namespace time {

$FieldInfo _Ser_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Ser, serialVersionUID)},
	{"DURATION_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, DURATION_TYPE)},
	{"INSTANT_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, INSTANT_TYPE)},
	{"LOCAL_DATE_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, LOCAL_DATE_TYPE)},
	{"LOCAL_TIME_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, LOCAL_TIME_TYPE)},
	{"LOCAL_DATE_TIME_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, LOCAL_DATE_TIME_TYPE)},
	{"ZONE_DATE_TIME_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, ZONE_DATE_TIME_TYPE)},
	{"ZONE_REGION_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, ZONE_REGION_TYPE)},
	{"ZONE_OFFSET_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, ZONE_OFFSET_TYPE)},
	{"OFFSET_TIME_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, OFFSET_TIME_TYPE)},
	{"OFFSET_DATE_TIME_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, OFFSET_DATE_TIME_TYPE)},
	{"YEAR_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, YEAR_TYPE)},
	{"YEAR_MONTH_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, YEAR_MONTH_TYPE)},
	{"MONTH_DAY_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, MONTH_DAY_TYPE)},
	{"PERIOD_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, PERIOD_TYPE)},
	{"type", "B", nullptr, $PRIVATE, $field(Ser, type)},
	{"object", "Ljava/io/Serializable;", nullptr, $PRIVATE, $field(Ser, object)},
	{}
};

$MethodInfo _Ser_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Ser, init$, void)},
	{"<init>", "(BLjava/io/Serializable;)V", nullptr, 0, $method(Ser, init$, void, int8_t, $Serializable*)},
	{"read", "(Ljava/io/ObjectInput;)Ljava/io/Serializable;", nullptr, $STATIC, $staticMethod(Ser, read, $Serializable*, $ObjectInput*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"readExternal", "(Ljava/io/ObjectInput;)V", nullptr, $PUBLIC, $virtualMethod(Ser, readExternal, void, $ObjectInput*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"readInternal", "(BLjava/io/ObjectInput;)Ljava/io/Serializable;", nullptr, $PRIVATE | $STATIC, $staticMethod(Ser, readInternal, $Serializable*, int8_t, $ObjectInput*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"readResolve", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(Ser, readResolve, $Object*)},
	{"writeExternal", "(Ljava/io/ObjectOutput;)V", nullptr, $PUBLIC, $virtualMethod(Ser, writeExternal, void, $ObjectOutput*), "java.io.IOException"},
	{"writeInternal", "(BLjava/lang/Object;Ljava/io/ObjectOutput;)V", nullptr, $STATIC, $staticMethod(Ser, writeInternal, void, int8_t, Object$*, $ObjectOutput*), "java.io.IOException"},
	{}
};

$ClassInfo _Ser_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.time.Ser",
	"java.lang.Object",
	"java.io.Externalizable",
	_Ser_FieldInfo_,
	_Ser_MethodInfo_
};

$Object* allocate$Ser($Class* clazz) {
	return $of($alloc(Ser));
}

void Ser::init$() {
}

void Ser::init$(int8_t type, $Serializable* object) {
	this->type = type;
	$set(this, object, object);
}

void Ser::writeExternal($ObjectOutput* out) {
	writeInternal(this->type, this->object, out);
}

void Ser::writeInternal(int8_t type, Object$* object, $ObjectOutput* out) {
	$init(Ser);
	$nc(out)->writeByte(type);
	switch (type) {
	case Ser::DURATION_TYPE:
		{
			$nc(($cast($Duration, object)))->writeExternal(out);
			break;
		}
	case Ser::INSTANT_TYPE:
		{
			$nc(($cast($Instant, object)))->writeExternal(out);
			break;
		}
	case Ser::LOCAL_DATE_TYPE:
		{
			$nc(($cast($LocalDate, object)))->writeExternal(out);
			break;
		}
	case Ser::LOCAL_DATE_TIME_TYPE:
		{
			$nc(($cast($LocalDateTime, object)))->writeExternal(out);
			break;
		}
	case Ser::LOCAL_TIME_TYPE:
		{
			$nc(($cast($LocalTime, object)))->writeExternal(out);
			break;
		}
	case Ser::ZONE_REGION_TYPE:
		{
			$nc(($cast($ZoneRegion, object)))->writeExternal(out);
			break;
		}
	case Ser::ZONE_OFFSET_TYPE:
		{
			$nc(($cast($ZoneOffset, object)))->writeExternal(out);
			break;
		}
	case Ser::ZONE_DATE_TIME_TYPE:
		{
			$nc(($cast($ZonedDateTime, object)))->writeExternal(out);
			break;
		}
	case Ser::OFFSET_TIME_TYPE:
		{
			$nc(($cast($OffsetTime, object)))->writeExternal(out);
			break;
		}
	case Ser::OFFSET_DATE_TIME_TYPE:
		{
			$nc(($cast($OffsetDateTime, object)))->writeExternal(out);
			break;
		}
	case Ser::YEAR_TYPE:
		{
			$nc(($cast($Year, object)))->writeExternal(out);
			break;
		}
	case Ser::YEAR_MONTH_TYPE:
		{
			$nc(($cast($YearMonth, object)))->writeExternal(out);
			break;
		}
	case Ser::MONTH_DAY_TYPE:
		{
			$nc(($cast($MonthDay, object)))->writeExternal(out);
			break;
		}
	case Ser::PERIOD_TYPE:
		{
			$nc(($cast($Period, object)))->writeExternal(out);
			break;
		}
	default:
		{
			$throwNew($InvalidClassException, "Unknown serialized type"_s);
		}
	}
}

void Ser::readExternal($ObjectInput* in) {
	this->type = $nc(in)->readByte();
	$set(this, object, readInternal(this->type, in));
}

$Serializable* Ser::read($ObjectInput* in) {
	$init(Ser);
	int8_t type = $nc(in)->readByte();
	return readInternal(type, in);
}

$Serializable* Ser::readInternal(int8_t type, $ObjectInput* in) {
	$init(Ser);
	switch (type) {
	case Ser::DURATION_TYPE:
		{
			return $Duration::readExternal(in);
		}
	case Ser::INSTANT_TYPE:
		{
			return $Instant::readExternal(in);
		}
	case Ser::LOCAL_DATE_TYPE:
		{
			return $LocalDate::readExternal(in);
		}
	case Ser::LOCAL_DATE_TIME_TYPE:
		{
			return $LocalDateTime::readExternal(in);
		}
	case Ser::LOCAL_TIME_TYPE:
		{
			return $LocalTime::readExternal(in);
		}
	case Ser::ZONE_DATE_TIME_TYPE:
		{
			return $ZonedDateTime::readExternal(in);
		}
	case Ser::ZONE_OFFSET_TYPE:
		{
			return $ZoneOffset::readExternal(in);
		}
	case Ser::ZONE_REGION_TYPE:
		{
			return $ZoneRegion::readExternal(in);
		}
	case Ser::OFFSET_TIME_TYPE:
		{
			return $OffsetTime::readExternal(in);
		}
	case Ser::OFFSET_DATE_TIME_TYPE:
		{
			return $OffsetDateTime::readExternal(in);
		}
	case Ser::YEAR_TYPE:
		{
			return $Year::readExternal(in);
		}
	case Ser::YEAR_MONTH_TYPE:
		{
			return $YearMonth::readExternal(in);
		}
	case Ser::MONTH_DAY_TYPE:
		{
			return $MonthDay::readExternal(in);
		}
	case Ser::PERIOD_TYPE:
		{
			return $Period::readExternal(in);
		}
	default:
		{
			$throwNew($StreamCorruptedException, "Unknown serialized type"_s);
		}
	}
}

$Object* Ser::readResolve() {
	return $of(this->object);
}

Ser::Ser() {
}

$Class* Ser::load$($String* name, bool initialize) {
	$loadClass(Ser, name, initialize, &_Ser_ClassInfo_, allocate$Ser);
	return class$;
}

$Class* Ser::class$ = nullptr;

	} // time
} // java