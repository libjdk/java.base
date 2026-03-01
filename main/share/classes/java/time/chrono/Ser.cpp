#include <java/time/chrono/Ser.h>

#include <java/io/DataInput.h>
#include <java/io/DataOutput.h>
#include <java/io/InvalidClassException.h>
#include <java/io/ObjectInput.h>
#include <java/io/ObjectOutput.h>
#include <java/io/Serializable.h>
#include <java/io/StreamCorruptedException.h>
#include <java/time/chrono/AbstractChronology.h>
#include <java/time/chrono/ChronoLocalDateTime.h>
#include <java/time/chrono/ChronoLocalDateTimeImpl.h>
#include <java/time/chrono/ChronoPeriodImpl.h>
#include <java/time/chrono/ChronoZonedDateTime.h>
#include <java/time/chrono/ChronoZonedDateTimeImpl.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/chrono/HijrahDate.h>
#include <java/time/chrono/JapaneseDate.h>
#include <java/time/chrono/JapaneseEra.h>
#include <java/time/chrono/MinguoDate.h>
#include <java/time/chrono/ThaiBuddhistDate.h>
#include <jcpp.h>

#undef CHRONO_LOCAL_DATE_TIME_TYPE
#undef CHRONO_PERIOD_TYPE
#undef CHRONO_TYPE
#undef CHRONO_ZONE_DATE_TIME_TYPE
#undef HIJRAH_DATE_TYPE
#undef JAPANESE_DATE_TYPE
#undef JAPANESE_ERA_TYPE
#undef MINGUO_DATE_TYPE
#undef THAIBUDDHIST_DATE_TYPE

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
using $AbstractChronology = ::java::time::chrono::AbstractChronology;
using $ChronoLocalDateTimeImpl = ::java::time::chrono::ChronoLocalDateTimeImpl;
using $ChronoPeriodImpl = ::java::time::chrono::ChronoPeriodImpl;
using $ChronoZonedDateTimeImpl = ::java::time::chrono::ChronoZonedDateTimeImpl;
using $HijrahDate = ::java::time::chrono::HijrahDate;
using $JapaneseDate = ::java::time::chrono::JapaneseDate;
using $JapaneseEra = ::java::time::chrono::JapaneseEra;
using $MinguoDate = ::java::time::chrono::MinguoDate;
using $ThaiBuddhistDate = ::java::time::chrono::ThaiBuddhistDate;

namespace java {
	namespace time {
		namespace chrono {

$FieldInfo _Ser_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Ser, serialVersionUID)},
	{"CHRONO_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, CHRONO_TYPE)},
	{"CHRONO_LOCAL_DATE_TIME_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, CHRONO_LOCAL_DATE_TIME_TYPE)},
	{"CHRONO_ZONE_DATE_TIME_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, CHRONO_ZONE_DATE_TIME_TYPE)},
	{"JAPANESE_DATE_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, JAPANESE_DATE_TYPE)},
	{"JAPANESE_ERA_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, JAPANESE_ERA_TYPE)},
	{"HIJRAH_DATE_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, HIJRAH_DATE_TYPE)},
	{"MINGUO_DATE_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, MINGUO_DATE_TYPE)},
	{"THAIBUDDHIST_DATE_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, THAIBUDDHIST_DATE_TYPE)},
	{"CHRONO_PERIOD_TYPE", "B", nullptr, $STATIC | $FINAL, $constField(Ser, CHRONO_PERIOD_TYPE)},
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
	{"writeInternal", "(BLjava/lang/Object;Ljava/io/ObjectOutput;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Ser, writeInternal, void, int8_t, Object$*, $ObjectOutput*), "java.io.IOException"},
	{}
};

$ClassInfo _Ser_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.time.chrono.Ser",
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
	case Ser::CHRONO_TYPE:
		{
			$nc(($cast($AbstractChronology, object)))->writeExternal(out);
			break;
		}
	case Ser::CHRONO_LOCAL_DATE_TIME_TYPE:
		{
			$nc(($cast($ChronoLocalDateTimeImpl, object)))->writeExternal(out);
			break;
		}
	case Ser::CHRONO_ZONE_DATE_TIME_TYPE:
		{
			$nc(($cast($ChronoZonedDateTimeImpl, object)))->writeExternal(out);
			break;
		}
	case Ser::JAPANESE_DATE_TYPE:
		{
			$nc(($cast($JapaneseDate, object)))->writeExternal(out);
			break;
		}
	case Ser::JAPANESE_ERA_TYPE:
		{
			$nc(($cast($JapaneseEra, object)))->writeExternal(out);
			break;
		}
	case Ser::HIJRAH_DATE_TYPE:
		{
			$nc(($cast($HijrahDate, object)))->writeExternal(out);
			break;
		}
	case Ser::MINGUO_DATE_TYPE:
		{
			$nc(($cast($MinguoDate, object)))->writeExternal(out);
			break;
		}
	case Ser::THAIBUDDHIST_DATE_TYPE:
		{
			$nc(($cast($ThaiBuddhistDate, object)))->writeExternal(out);
			break;
		}
	case Ser::CHRONO_PERIOD_TYPE:
		{
			$nc(($cast($ChronoPeriodImpl, object)))->writeExternal(out);
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
	case Ser::CHRONO_TYPE:
		{
			return $cast($Serializable, $AbstractChronology::readExternal(in));
		}
	case Ser::CHRONO_LOCAL_DATE_TIME_TYPE:
		{
			return $cast($Serializable, $ChronoLocalDateTimeImpl::readExternal(in));
		}
	case Ser::CHRONO_ZONE_DATE_TIME_TYPE:
		{
			return $cast($Serializable, $ChronoZonedDateTimeImpl::readExternal(in));
		}
	case Ser::JAPANESE_DATE_TYPE:
		{
			return $JapaneseDate::readExternal(in);
		}
	case Ser::JAPANESE_ERA_TYPE:
		{
			return $JapaneseEra::readExternal(in);
		}
	case Ser::HIJRAH_DATE_TYPE:
		{
			return $HijrahDate::readExternal(in);
		}
	case Ser::MINGUO_DATE_TYPE:
		{
			return $MinguoDate::readExternal(in);
		}
	case Ser::THAIBUDDHIST_DATE_TYPE:
		{
			return $ThaiBuddhistDate::readExternal(in);
		}
	case Ser::CHRONO_PERIOD_TYPE:
		{
			return $ChronoPeriodImpl::readExternal(in);
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

		} // chrono
	} // time
} // java