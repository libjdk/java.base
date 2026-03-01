#include <java/time/temporal/TemporalAdjusters.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/time/DayOfWeek.h>
#include <java/time/LocalDate.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/ChronoUnit.h>
#include <java/time/temporal/Temporal.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalAdjuster.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/TemporalUnit.h>
#include <java/time/temporal/ValueRange.h>
#include <java/util/Objects.h>
#include <java/util/function/UnaryOperator.h>
#include <jcpp.h>

#undef DAYS
#undef DAY_OF_MONTH
#undef DAY_OF_WEEK
#undef DAY_OF_YEAR
#undef MONTHS
#undef YEARS

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $DayOfWeek = ::java::time::DayOfWeek;
using $LocalDate = ::java::time::LocalDate;
using $ChronoField = ::java::time::temporal::ChronoField;
using $ChronoUnit = ::java::time::temporal::ChronoUnit;
using $Temporal = ::java::time::temporal::Temporal;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalAdjuster = ::java::time::temporal::TemporalAdjuster;
using $TemporalField = ::java::time::temporal::TemporalField;
using $TemporalUnit = ::java::time::temporal::TemporalUnit;
using $ValueRange = ::java::time::temporal::ValueRange;
using $Objects = ::java::util::Objects;
using $UnaryOperator = ::java::util::function::UnaryOperator;

namespace java {
	namespace time {
		namespace temporal {

class TemporalAdjusters$$Lambda$lambda$ofDateAdjuster$0 : public $TemporalAdjuster {
	$class(TemporalAdjusters$$Lambda$lambda$ofDateAdjuster$0, $NO_CLASS_INIT, $TemporalAdjuster)
public:
	void init$($UnaryOperator* dateBasedAdjuster) {
		$set(this, dateBasedAdjuster, dateBasedAdjuster);
	}
	virtual $Temporal* adjustInto($Temporal* temporal) override {
		 return TemporalAdjusters::lambda$ofDateAdjuster$0(dateBasedAdjuster, temporal);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TemporalAdjusters$$Lambda$lambda$ofDateAdjuster$0>());
	}
	$UnaryOperator* dateBasedAdjuster = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo TemporalAdjusters$$Lambda$lambda$ofDateAdjuster$0::fieldInfos[2] = {
	{"dateBasedAdjuster", "Ljava/util/function/UnaryOperator;", nullptr, $PUBLIC, $field(TemporalAdjusters$$Lambda$lambda$ofDateAdjuster$0, dateBasedAdjuster)},
	{}
};
$MethodInfo TemporalAdjusters$$Lambda$lambda$ofDateAdjuster$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/UnaryOperator;)V", nullptr, $PUBLIC, $method(TemporalAdjusters$$Lambda$lambda$ofDateAdjuster$0, init$, void, $UnaryOperator*)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(TemporalAdjusters$$Lambda$lambda$ofDateAdjuster$0, adjustInto, $Temporal*, $Temporal*)},
	{}
};
$ClassInfo TemporalAdjusters$$Lambda$lambda$ofDateAdjuster$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.temporal.TemporalAdjusters$$Lambda$lambda$ofDateAdjuster$0",
	"java.lang.Object",
	"java.time.temporal.TemporalAdjuster",
	fieldInfos,
	methodInfos
};
$Class* TemporalAdjusters$$Lambda$lambda$ofDateAdjuster$0::load$($String* name, bool initialize) {
	$loadClass(TemporalAdjusters$$Lambda$lambda$ofDateAdjuster$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TemporalAdjusters$$Lambda$lambda$ofDateAdjuster$0::class$ = nullptr;

class TemporalAdjusters$$Lambda$lambda$firstDayOfMonth$1$1 : public $TemporalAdjuster {
	$class(TemporalAdjusters$$Lambda$lambda$firstDayOfMonth$1$1, $NO_CLASS_INIT, $TemporalAdjuster)
public:
	void init$() {
	}
	virtual $Temporal* adjustInto($Temporal* temporal) override {
		 return TemporalAdjusters::lambda$firstDayOfMonth$1(temporal);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TemporalAdjusters$$Lambda$lambda$firstDayOfMonth$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo TemporalAdjusters$$Lambda$lambda$firstDayOfMonth$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(TemporalAdjusters$$Lambda$lambda$firstDayOfMonth$1$1, init$, void)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(TemporalAdjusters$$Lambda$lambda$firstDayOfMonth$1$1, adjustInto, $Temporal*, $Temporal*)},
	{}
};
$ClassInfo TemporalAdjusters$$Lambda$lambda$firstDayOfMonth$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.temporal.TemporalAdjusters$$Lambda$lambda$firstDayOfMonth$1$1",
	"java.lang.Object",
	"java.time.temporal.TemporalAdjuster",
	nullptr,
	methodInfos
};
$Class* TemporalAdjusters$$Lambda$lambda$firstDayOfMonth$1$1::load$($String* name, bool initialize) {
	$loadClass(TemporalAdjusters$$Lambda$lambda$firstDayOfMonth$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TemporalAdjusters$$Lambda$lambda$firstDayOfMonth$1$1::class$ = nullptr;

class TemporalAdjusters$$Lambda$lambda$lastDayOfMonth$2$2 : public $TemporalAdjuster {
	$class(TemporalAdjusters$$Lambda$lambda$lastDayOfMonth$2$2, $NO_CLASS_INIT, $TemporalAdjuster)
public:
	void init$() {
	}
	virtual $Temporal* adjustInto($Temporal* temporal) override {
		 return TemporalAdjusters::lambda$lastDayOfMonth$2(temporal);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TemporalAdjusters$$Lambda$lambda$lastDayOfMonth$2$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo TemporalAdjusters$$Lambda$lambda$lastDayOfMonth$2$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(TemporalAdjusters$$Lambda$lambda$lastDayOfMonth$2$2, init$, void)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(TemporalAdjusters$$Lambda$lambda$lastDayOfMonth$2$2, adjustInto, $Temporal*, $Temporal*)},
	{}
};
$ClassInfo TemporalAdjusters$$Lambda$lambda$lastDayOfMonth$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.temporal.TemporalAdjusters$$Lambda$lambda$lastDayOfMonth$2$2",
	"java.lang.Object",
	"java.time.temporal.TemporalAdjuster",
	nullptr,
	methodInfos
};
$Class* TemporalAdjusters$$Lambda$lambda$lastDayOfMonth$2$2::load$($String* name, bool initialize) {
	$loadClass(TemporalAdjusters$$Lambda$lambda$lastDayOfMonth$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TemporalAdjusters$$Lambda$lambda$lastDayOfMonth$2$2::class$ = nullptr;

class TemporalAdjusters$$Lambda$lambda$firstDayOfNextMonth$3$3 : public $TemporalAdjuster {
	$class(TemporalAdjusters$$Lambda$lambda$firstDayOfNextMonth$3$3, $NO_CLASS_INIT, $TemporalAdjuster)
public:
	void init$() {
	}
	virtual $Temporal* adjustInto($Temporal* temporal) override {
		 return TemporalAdjusters::lambda$firstDayOfNextMonth$3(temporal);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TemporalAdjusters$$Lambda$lambda$firstDayOfNextMonth$3$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo TemporalAdjusters$$Lambda$lambda$firstDayOfNextMonth$3$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(TemporalAdjusters$$Lambda$lambda$firstDayOfNextMonth$3$3, init$, void)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(TemporalAdjusters$$Lambda$lambda$firstDayOfNextMonth$3$3, adjustInto, $Temporal*, $Temporal*)},
	{}
};
$ClassInfo TemporalAdjusters$$Lambda$lambda$firstDayOfNextMonth$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.temporal.TemporalAdjusters$$Lambda$lambda$firstDayOfNextMonth$3$3",
	"java.lang.Object",
	"java.time.temporal.TemporalAdjuster",
	nullptr,
	methodInfos
};
$Class* TemporalAdjusters$$Lambda$lambda$firstDayOfNextMonth$3$3::load$($String* name, bool initialize) {
	$loadClass(TemporalAdjusters$$Lambda$lambda$firstDayOfNextMonth$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TemporalAdjusters$$Lambda$lambda$firstDayOfNextMonth$3$3::class$ = nullptr;

class TemporalAdjusters$$Lambda$lambda$firstDayOfYear$4$4 : public $TemporalAdjuster {
	$class(TemporalAdjusters$$Lambda$lambda$firstDayOfYear$4$4, $NO_CLASS_INIT, $TemporalAdjuster)
public:
	void init$() {
	}
	virtual $Temporal* adjustInto($Temporal* temporal) override {
		 return TemporalAdjusters::lambda$firstDayOfYear$4(temporal);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TemporalAdjusters$$Lambda$lambda$firstDayOfYear$4$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo TemporalAdjusters$$Lambda$lambda$firstDayOfYear$4$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(TemporalAdjusters$$Lambda$lambda$firstDayOfYear$4$4, init$, void)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(TemporalAdjusters$$Lambda$lambda$firstDayOfYear$4$4, adjustInto, $Temporal*, $Temporal*)},
	{}
};
$ClassInfo TemporalAdjusters$$Lambda$lambda$firstDayOfYear$4$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.temporal.TemporalAdjusters$$Lambda$lambda$firstDayOfYear$4$4",
	"java.lang.Object",
	"java.time.temporal.TemporalAdjuster",
	nullptr,
	methodInfos
};
$Class* TemporalAdjusters$$Lambda$lambda$firstDayOfYear$4$4::load$($String* name, bool initialize) {
	$loadClass(TemporalAdjusters$$Lambda$lambda$firstDayOfYear$4$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TemporalAdjusters$$Lambda$lambda$firstDayOfYear$4$4::class$ = nullptr;

class TemporalAdjusters$$Lambda$lambda$lastDayOfYear$5$5 : public $TemporalAdjuster {
	$class(TemporalAdjusters$$Lambda$lambda$lastDayOfYear$5$5, $NO_CLASS_INIT, $TemporalAdjuster)
public:
	void init$() {
	}
	virtual $Temporal* adjustInto($Temporal* temporal) override {
		 return TemporalAdjusters::lambda$lastDayOfYear$5(temporal);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TemporalAdjusters$$Lambda$lambda$lastDayOfYear$5$5>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo TemporalAdjusters$$Lambda$lambda$lastDayOfYear$5$5::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(TemporalAdjusters$$Lambda$lambda$lastDayOfYear$5$5, init$, void)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(TemporalAdjusters$$Lambda$lambda$lastDayOfYear$5$5, adjustInto, $Temporal*, $Temporal*)},
	{}
};
$ClassInfo TemporalAdjusters$$Lambda$lambda$lastDayOfYear$5$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.temporal.TemporalAdjusters$$Lambda$lambda$lastDayOfYear$5$5",
	"java.lang.Object",
	"java.time.temporal.TemporalAdjuster",
	nullptr,
	methodInfos
};
$Class* TemporalAdjusters$$Lambda$lambda$lastDayOfYear$5$5::load$($String* name, bool initialize) {
	$loadClass(TemporalAdjusters$$Lambda$lambda$lastDayOfYear$5$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TemporalAdjusters$$Lambda$lambda$lastDayOfYear$5$5::class$ = nullptr;

class TemporalAdjusters$$Lambda$lambda$firstDayOfNextYear$6$6 : public $TemporalAdjuster {
	$class(TemporalAdjusters$$Lambda$lambda$firstDayOfNextYear$6$6, $NO_CLASS_INIT, $TemporalAdjuster)
public:
	void init$() {
	}
	virtual $Temporal* adjustInto($Temporal* temporal) override {
		 return TemporalAdjusters::lambda$firstDayOfNextYear$6(temporal);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TemporalAdjusters$$Lambda$lambda$firstDayOfNextYear$6$6>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo TemporalAdjusters$$Lambda$lambda$firstDayOfNextYear$6$6::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(TemporalAdjusters$$Lambda$lambda$firstDayOfNextYear$6$6, init$, void)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(TemporalAdjusters$$Lambda$lambda$firstDayOfNextYear$6$6, adjustInto, $Temporal*, $Temporal*)},
	{}
};
$ClassInfo TemporalAdjusters$$Lambda$lambda$firstDayOfNextYear$6$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.temporal.TemporalAdjusters$$Lambda$lambda$firstDayOfNextYear$6$6",
	"java.lang.Object",
	"java.time.temporal.TemporalAdjuster",
	nullptr,
	methodInfos
};
$Class* TemporalAdjusters$$Lambda$lambda$firstDayOfNextYear$6$6::load$($String* name, bool initialize) {
	$loadClass(TemporalAdjusters$$Lambda$lambda$firstDayOfNextYear$6$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TemporalAdjusters$$Lambda$lambda$firstDayOfNextYear$6$6::class$ = nullptr;

class TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$7$7 : public $TemporalAdjuster {
	$class(TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$7$7, $NO_CLASS_INIT, $TemporalAdjuster)
public:
	void init$(int32_t dowValue, int32_t ordinal) {
		this->dowValue = dowValue;
		this->ordinal = ordinal;
	}
	virtual $Temporal* adjustInto($Temporal* temporal) override {
		 return TemporalAdjusters::lambda$dayOfWeekInMonth$7(dowValue, ordinal, temporal);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$7$7>());
	}
	int32_t dowValue = 0;
	int32_t ordinal = 0;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$7$7::fieldInfos[3] = {
	{"dowValue", "I", nullptr, $PUBLIC, $field(TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$7$7, dowValue)},
	{"ordinal", "I", nullptr, $PUBLIC, $field(TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$7$7, ordinal)},
	{}
};
$MethodInfo TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$7$7::methodInfos[3] = {
	{"<init>", "(II)V", nullptr, $PUBLIC, $method(TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$7$7, init$, void, int32_t, int32_t)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$7$7, adjustInto, $Temporal*, $Temporal*)},
	{}
};
$ClassInfo TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$7$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.temporal.TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$7$7",
	"java.lang.Object",
	"java.time.temporal.TemporalAdjuster",
	fieldInfos,
	methodInfos
};
$Class* TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$7$7::load$($String* name, bool initialize) {
	$loadClass(TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$7$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$7$7::class$ = nullptr;

class TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$8$8 : public $TemporalAdjuster {
	$class(TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$8$8, $NO_CLASS_INIT, $TemporalAdjuster)
public:
	void init$(int32_t dowValue, int32_t ordinal) {
		this->dowValue = dowValue;
		this->ordinal = ordinal;
	}
	virtual $Temporal* adjustInto($Temporal* temporal) override {
		 return TemporalAdjusters::lambda$dayOfWeekInMonth$8(dowValue, ordinal, temporal);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$8$8>());
	}
	int32_t dowValue = 0;
	int32_t ordinal = 0;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$8$8::fieldInfos[3] = {
	{"dowValue", "I", nullptr, $PUBLIC, $field(TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$8$8, dowValue)},
	{"ordinal", "I", nullptr, $PUBLIC, $field(TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$8$8, ordinal)},
	{}
};
$MethodInfo TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$8$8::methodInfos[3] = {
	{"<init>", "(II)V", nullptr, $PUBLIC, $method(TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$8$8, init$, void, int32_t, int32_t)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$8$8, adjustInto, $Temporal*, $Temporal*)},
	{}
};
$ClassInfo TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$8$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.temporal.TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$8$8",
	"java.lang.Object",
	"java.time.temporal.TemporalAdjuster",
	fieldInfos,
	methodInfos
};
$Class* TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$8$8::load$($String* name, bool initialize) {
	$loadClass(TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$8$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$8$8::class$ = nullptr;

class TemporalAdjusters$$Lambda$lambda$next$9$9 : public $TemporalAdjuster {
	$class(TemporalAdjusters$$Lambda$lambda$next$9$9, $NO_CLASS_INIT, $TemporalAdjuster)
public:
	void init$(int32_t dowValue) {
		this->dowValue = dowValue;
	}
	virtual $Temporal* adjustInto($Temporal* temporal) override {
		 return TemporalAdjusters::lambda$next$9(dowValue, temporal);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TemporalAdjusters$$Lambda$lambda$next$9$9>());
	}
	int32_t dowValue = 0;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo TemporalAdjusters$$Lambda$lambda$next$9$9::fieldInfos[2] = {
	{"dowValue", "I", nullptr, $PUBLIC, $field(TemporalAdjusters$$Lambda$lambda$next$9$9, dowValue)},
	{}
};
$MethodInfo TemporalAdjusters$$Lambda$lambda$next$9$9::methodInfos[3] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(TemporalAdjusters$$Lambda$lambda$next$9$9, init$, void, int32_t)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(TemporalAdjusters$$Lambda$lambda$next$9$9, adjustInto, $Temporal*, $Temporal*)},
	{}
};
$ClassInfo TemporalAdjusters$$Lambda$lambda$next$9$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.temporal.TemporalAdjusters$$Lambda$lambda$next$9$9",
	"java.lang.Object",
	"java.time.temporal.TemporalAdjuster",
	fieldInfos,
	methodInfos
};
$Class* TemporalAdjusters$$Lambda$lambda$next$9$9::load$($String* name, bool initialize) {
	$loadClass(TemporalAdjusters$$Lambda$lambda$next$9$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TemporalAdjusters$$Lambda$lambda$next$9$9::class$ = nullptr;

class TemporalAdjusters$$Lambda$lambda$nextOrSame$10$10 : public $TemporalAdjuster {
	$class(TemporalAdjusters$$Lambda$lambda$nextOrSame$10$10, $NO_CLASS_INIT, $TemporalAdjuster)
public:
	void init$(int32_t dowValue) {
		this->dowValue = dowValue;
	}
	virtual $Temporal* adjustInto($Temporal* temporal) override {
		 return TemporalAdjusters::lambda$nextOrSame$10(dowValue, temporal);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TemporalAdjusters$$Lambda$lambda$nextOrSame$10$10>());
	}
	int32_t dowValue = 0;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo TemporalAdjusters$$Lambda$lambda$nextOrSame$10$10::fieldInfos[2] = {
	{"dowValue", "I", nullptr, $PUBLIC, $field(TemporalAdjusters$$Lambda$lambda$nextOrSame$10$10, dowValue)},
	{}
};
$MethodInfo TemporalAdjusters$$Lambda$lambda$nextOrSame$10$10::methodInfos[3] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(TemporalAdjusters$$Lambda$lambda$nextOrSame$10$10, init$, void, int32_t)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(TemporalAdjusters$$Lambda$lambda$nextOrSame$10$10, adjustInto, $Temporal*, $Temporal*)},
	{}
};
$ClassInfo TemporalAdjusters$$Lambda$lambda$nextOrSame$10$10::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.temporal.TemporalAdjusters$$Lambda$lambda$nextOrSame$10$10",
	"java.lang.Object",
	"java.time.temporal.TemporalAdjuster",
	fieldInfos,
	methodInfos
};
$Class* TemporalAdjusters$$Lambda$lambda$nextOrSame$10$10::load$($String* name, bool initialize) {
	$loadClass(TemporalAdjusters$$Lambda$lambda$nextOrSame$10$10, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TemporalAdjusters$$Lambda$lambda$nextOrSame$10$10::class$ = nullptr;

class TemporalAdjusters$$Lambda$lambda$previous$11$11 : public $TemporalAdjuster {
	$class(TemporalAdjusters$$Lambda$lambda$previous$11$11, $NO_CLASS_INIT, $TemporalAdjuster)
public:
	void init$(int32_t dowValue) {
		this->dowValue = dowValue;
	}
	virtual $Temporal* adjustInto($Temporal* temporal) override {
		 return TemporalAdjusters::lambda$previous$11(dowValue, temporal);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TemporalAdjusters$$Lambda$lambda$previous$11$11>());
	}
	int32_t dowValue = 0;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo TemporalAdjusters$$Lambda$lambda$previous$11$11::fieldInfos[2] = {
	{"dowValue", "I", nullptr, $PUBLIC, $field(TemporalAdjusters$$Lambda$lambda$previous$11$11, dowValue)},
	{}
};
$MethodInfo TemporalAdjusters$$Lambda$lambda$previous$11$11::methodInfos[3] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(TemporalAdjusters$$Lambda$lambda$previous$11$11, init$, void, int32_t)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(TemporalAdjusters$$Lambda$lambda$previous$11$11, adjustInto, $Temporal*, $Temporal*)},
	{}
};
$ClassInfo TemporalAdjusters$$Lambda$lambda$previous$11$11::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.temporal.TemporalAdjusters$$Lambda$lambda$previous$11$11",
	"java.lang.Object",
	"java.time.temporal.TemporalAdjuster",
	fieldInfos,
	methodInfos
};
$Class* TemporalAdjusters$$Lambda$lambda$previous$11$11::load$($String* name, bool initialize) {
	$loadClass(TemporalAdjusters$$Lambda$lambda$previous$11$11, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TemporalAdjusters$$Lambda$lambda$previous$11$11::class$ = nullptr;

class TemporalAdjusters$$Lambda$lambda$previousOrSame$12$12 : public $TemporalAdjuster {
	$class(TemporalAdjusters$$Lambda$lambda$previousOrSame$12$12, $NO_CLASS_INIT, $TemporalAdjuster)
public:
	void init$(int32_t dowValue) {
		this->dowValue = dowValue;
	}
	virtual $Temporal* adjustInto($Temporal* temporal) override {
		 return TemporalAdjusters::lambda$previousOrSame$12(dowValue, temporal);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TemporalAdjusters$$Lambda$lambda$previousOrSame$12$12>());
	}
	int32_t dowValue = 0;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo TemporalAdjusters$$Lambda$lambda$previousOrSame$12$12::fieldInfos[2] = {
	{"dowValue", "I", nullptr, $PUBLIC, $field(TemporalAdjusters$$Lambda$lambda$previousOrSame$12$12, dowValue)},
	{}
};
$MethodInfo TemporalAdjusters$$Lambda$lambda$previousOrSame$12$12::methodInfos[3] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(TemporalAdjusters$$Lambda$lambda$previousOrSame$12$12, init$, void, int32_t)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(TemporalAdjusters$$Lambda$lambda$previousOrSame$12$12, adjustInto, $Temporal*, $Temporal*)},
	{}
};
$ClassInfo TemporalAdjusters$$Lambda$lambda$previousOrSame$12$12::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.temporal.TemporalAdjusters$$Lambda$lambda$previousOrSame$12$12",
	"java.lang.Object",
	"java.time.temporal.TemporalAdjuster",
	fieldInfos,
	methodInfos
};
$Class* TemporalAdjusters$$Lambda$lambda$previousOrSame$12$12::load$($String* name, bool initialize) {
	$loadClass(TemporalAdjusters$$Lambda$lambda$previousOrSame$12$12, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TemporalAdjusters$$Lambda$lambda$previousOrSame$12$12::class$ = nullptr;

$MethodInfo _TemporalAdjusters_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(TemporalAdjusters, init$, void)},
	{"dayOfWeekInMonth", "(ILjava/time/DayOfWeek;)Ljava/time/temporal/TemporalAdjuster;", nullptr, $PUBLIC | $STATIC, $staticMethod(TemporalAdjusters, dayOfWeekInMonth, $TemporalAdjuster*, int32_t, $DayOfWeek*)},
	{"firstDayOfMonth", "()Ljava/time/temporal/TemporalAdjuster;", nullptr, $PUBLIC | $STATIC, $staticMethod(TemporalAdjusters, firstDayOfMonth, $TemporalAdjuster*)},
	{"firstDayOfNextMonth", "()Ljava/time/temporal/TemporalAdjuster;", nullptr, $PUBLIC | $STATIC, $staticMethod(TemporalAdjusters, firstDayOfNextMonth, $TemporalAdjuster*)},
	{"firstDayOfNextYear", "()Ljava/time/temporal/TemporalAdjuster;", nullptr, $PUBLIC | $STATIC, $staticMethod(TemporalAdjusters, firstDayOfNextYear, $TemporalAdjuster*)},
	{"firstDayOfYear", "()Ljava/time/temporal/TemporalAdjuster;", nullptr, $PUBLIC | $STATIC, $staticMethod(TemporalAdjusters, firstDayOfYear, $TemporalAdjuster*)},
	{"firstInMonth", "(Ljava/time/DayOfWeek;)Ljava/time/temporal/TemporalAdjuster;", nullptr, $PUBLIC | $STATIC, $staticMethod(TemporalAdjusters, firstInMonth, $TemporalAdjuster*, $DayOfWeek*)},
	{"lambda$dayOfWeekInMonth$7", "(IILjava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(TemporalAdjusters, lambda$dayOfWeekInMonth$7, $Temporal*, int32_t, int32_t, $Temporal*)},
	{"lambda$dayOfWeekInMonth$8", "(IILjava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(TemporalAdjusters, lambda$dayOfWeekInMonth$8, $Temporal*, int32_t, int32_t, $Temporal*)},
	{"lambda$firstDayOfMonth$1", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(TemporalAdjusters, lambda$firstDayOfMonth$1, $Temporal*, $Temporal*)},
	{"lambda$firstDayOfNextMonth$3", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(TemporalAdjusters, lambda$firstDayOfNextMonth$3, $Temporal*, $Temporal*)},
	{"lambda$firstDayOfNextYear$6", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(TemporalAdjusters, lambda$firstDayOfNextYear$6, $Temporal*, $Temporal*)},
	{"lambda$firstDayOfYear$4", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(TemporalAdjusters, lambda$firstDayOfYear$4, $Temporal*, $Temporal*)},
	{"lambda$lastDayOfMonth$2", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(TemporalAdjusters, lambda$lastDayOfMonth$2, $Temporal*, $Temporal*)},
	{"lambda$lastDayOfYear$5", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(TemporalAdjusters, lambda$lastDayOfYear$5, $Temporal*, $Temporal*)},
	{"lambda$next$9", "(ILjava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(TemporalAdjusters, lambda$next$9, $Temporal*, int32_t, $Temporal*)},
	{"lambda$nextOrSame$10", "(ILjava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(TemporalAdjusters, lambda$nextOrSame$10, $Temporal*, int32_t, $Temporal*)},
	{"lambda$ofDateAdjuster$0", "(Ljava/util/function/UnaryOperator;Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(TemporalAdjusters, lambda$ofDateAdjuster$0, $Temporal*, $UnaryOperator*, $Temporal*)},
	{"lambda$previous$11", "(ILjava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(TemporalAdjusters, lambda$previous$11, $Temporal*, int32_t, $Temporal*)},
	{"lambda$previousOrSame$12", "(ILjava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(TemporalAdjusters, lambda$previousOrSame$12, $Temporal*, int32_t, $Temporal*)},
	{"lastDayOfMonth", "()Ljava/time/temporal/TemporalAdjuster;", nullptr, $PUBLIC | $STATIC, $staticMethod(TemporalAdjusters, lastDayOfMonth, $TemporalAdjuster*)},
	{"lastDayOfYear", "()Ljava/time/temporal/TemporalAdjuster;", nullptr, $PUBLIC | $STATIC, $staticMethod(TemporalAdjusters, lastDayOfYear, $TemporalAdjuster*)},
	{"lastInMonth", "(Ljava/time/DayOfWeek;)Ljava/time/temporal/TemporalAdjuster;", nullptr, $PUBLIC | $STATIC, $staticMethod(TemporalAdjusters, lastInMonth, $TemporalAdjuster*, $DayOfWeek*)},
	{"next", "(Ljava/time/DayOfWeek;)Ljava/time/temporal/TemporalAdjuster;", nullptr, $PUBLIC | $STATIC, $staticMethod(TemporalAdjusters, next, $TemporalAdjuster*, $DayOfWeek*)},
	{"nextOrSame", "(Ljava/time/DayOfWeek;)Ljava/time/temporal/TemporalAdjuster;", nullptr, $PUBLIC | $STATIC, $staticMethod(TemporalAdjusters, nextOrSame, $TemporalAdjuster*, $DayOfWeek*)},
	{"ofDateAdjuster", "(Ljava/util/function/UnaryOperator;)Ljava/time/temporal/TemporalAdjuster;", "(Ljava/util/function/UnaryOperator<Ljava/time/LocalDate;>;)Ljava/time/temporal/TemporalAdjuster;", $PUBLIC | $STATIC, $staticMethod(TemporalAdjusters, ofDateAdjuster, $TemporalAdjuster*, $UnaryOperator*)},
	{"previous", "(Ljava/time/DayOfWeek;)Ljava/time/temporal/TemporalAdjuster;", nullptr, $PUBLIC | $STATIC, $staticMethod(TemporalAdjusters, previous, $TemporalAdjuster*, $DayOfWeek*)},
	{"previousOrSame", "(Ljava/time/DayOfWeek;)Ljava/time/temporal/TemporalAdjuster;", nullptr, $PUBLIC | $STATIC, $staticMethod(TemporalAdjusters, previousOrSame, $TemporalAdjuster*, $DayOfWeek*)},
	{}
};

$ClassInfo _TemporalAdjusters_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.temporal.TemporalAdjusters",
	"java.lang.Object",
	nullptr,
	nullptr,
	_TemporalAdjusters_MethodInfo_
};

$Object* allocate$TemporalAdjusters($Class* clazz) {
	return $of($alloc(TemporalAdjusters));
}

void TemporalAdjusters::init$() {
}

$TemporalAdjuster* TemporalAdjusters::ofDateAdjuster($UnaryOperator* dateBasedAdjuster) {
	$Objects::requireNonNull($of(dateBasedAdjuster), "dateBasedAdjuster"_s);
	return static_cast<$TemporalAdjuster*>($new(TemporalAdjusters$$Lambda$lambda$ofDateAdjuster$0, dateBasedAdjuster));
}

$TemporalAdjuster* TemporalAdjusters::firstDayOfMonth() {
	return static_cast<$TemporalAdjuster*>($new(TemporalAdjusters$$Lambda$lambda$firstDayOfMonth$1$1));
}

$TemporalAdjuster* TemporalAdjusters::lastDayOfMonth() {
	return static_cast<$TemporalAdjuster*>($new(TemporalAdjusters$$Lambda$lambda$lastDayOfMonth$2$2));
}

$TemporalAdjuster* TemporalAdjusters::firstDayOfNextMonth() {
	return static_cast<$TemporalAdjuster*>($new(TemporalAdjusters$$Lambda$lambda$firstDayOfNextMonth$3$3));
}

$TemporalAdjuster* TemporalAdjusters::firstDayOfYear() {
	return static_cast<$TemporalAdjuster*>($new(TemporalAdjusters$$Lambda$lambda$firstDayOfYear$4$4));
}

$TemporalAdjuster* TemporalAdjusters::lastDayOfYear() {
	return static_cast<$TemporalAdjuster*>($new(TemporalAdjusters$$Lambda$lambda$lastDayOfYear$5$5));
}

$TemporalAdjuster* TemporalAdjusters::firstDayOfNextYear() {
	return static_cast<$TemporalAdjuster*>($new(TemporalAdjusters$$Lambda$lambda$firstDayOfNextYear$6$6));
}

$TemporalAdjuster* TemporalAdjusters::firstInMonth($DayOfWeek* dayOfWeek) {
	return TemporalAdjusters::dayOfWeekInMonth(1, dayOfWeek);
}

$TemporalAdjuster* TemporalAdjusters::lastInMonth($DayOfWeek* dayOfWeek) {
	return TemporalAdjusters::dayOfWeekInMonth(-1, dayOfWeek);
}

$TemporalAdjuster* TemporalAdjusters::dayOfWeekInMonth(int32_t ordinal, $DayOfWeek* dayOfWeek) {
	$Objects::requireNonNull($of(dayOfWeek), "dayOfWeek"_s);
	int32_t dowValue = $nc(dayOfWeek)->getValue();
	if (ordinal >= 0) {
		return static_cast<$TemporalAdjuster*>($new(TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$7$7, dowValue, ordinal));
	} else {
		return static_cast<$TemporalAdjuster*>($new(TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$8$8, dowValue, ordinal));
	}
}

$TemporalAdjuster* TemporalAdjusters::next($DayOfWeek* dayOfWeek) {
	int32_t dowValue = $nc(dayOfWeek)->getValue();
	return static_cast<$TemporalAdjuster*>($new(TemporalAdjusters$$Lambda$lambda$next$9$9, dowValue));
}

$TemporalAdjuster* TemporalAdjusters::nextOrSame($DayOfWeek* dayOfWeek) {
	int32_t dowValue = $nc(dayOfWeek)->getValue();
	return static_cast<$TemporalAdjuster*>($new(TemporalAdjusters$$Lambda$lambda$nextOrSame$10$10, dowValue));
}

$TemporalAdjuster* TemporalAdjusters::previous($DayOfWeek* dayOfWeek) {
	int32_t dowValue = $nc(dayOfWeek)->getValue();
	return static_cast<$TemporalAdjuster*>($new(TemporalAdjusters$$Lambda$lambda$previous$11$11, dowValue));
}

$TemporalAdjuster* TemporalAdjusters::previousOrSame($DayOfWeek* dayOfWeek) {
	int32_t dowValue = $nc(dayOfWeek)->getValue();
	return static_cast<$TemporalAdjuster*>($new(TemporalAdjusters$$Lambda$lambda$previousOrSame$12$12, dowValue));
}

$Temporal* TemporalAdjusters::lambda$previousOrSame$12(int32_t dowValue, $Temporal* temporal) {
	$init($ChronoField);
	int32_t calDow = $nc(temporal)->get($ChronoField::DAY_OF_WEEK);
	if (calDow == dowValue) {
		return temporal;
	}
	int32_t daysDiff = dowValue - calDow;
	$init($ChronoUnit);
	return temporal->minus(daysDiff >= 0 ? 7 - daysDiff : -daysDiff, $ChronoUnit::DAYS);
}

$Temporal* TemporalAdjusters::lambda$previous$11(int32_t dowValue, $Temporal* temporal) {
	$init($ChronoField);
	int32_t calDow = $nc(temporal)->get($ChronoField::DAY_OF_WEEK);
	int32_t daysDiff = dowValue - calDow;
	$init($ChronoUnit);
	return temporal->minus(daysDiff >= 0 ? 7 - daysDiff : -daysDiff, $ChronoUnit::DAYS);
}

$Temporal* TemporalAdjusters::lambda$nextOrSame$10(int32_t dowValue, $Temporal* temporal) {
	$init($ChronoField);
	int32_t calDow = $nc(temporal)->get($ChronoField::DAY_OF_WEEK);
	if (calDow == dowValue) {
		return temporal;
	}
	int32_t daysDiff = calDow - dowValue;
	$init($ChronoUnit);
	return temporal->plus(daysDiff >= 0 ? 7 - daysDiff : -daysDiff, $ChronoUnit::DAYS);
}

$Temporal* TemporalAdjusters::lambda$next$9(int32_t dowValue, $Temporal* temporal) {
	$init($ChronoField);
	int32_t calDow = $nc(temporal)->get($ChronoField::DAY_OF_WEEK);
	int32_t daysDiff = calDow - dowValue;
	$init($ChronoUnit);
	return temporal->plus(daysDiff >= 0 ? 7 - daysDiff : -daysDiff, $ChronoUnit::DAYS);
}

$Temporal* TemporalAdjusters::lambda$dayOfWeekInMonth$8(int32_t dowValue, int32_t ordinal, $Temporal* temporal) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	$var($Temporal, temp, $nc(temporal)->with($ChronoField::DAY_OF_MONTH, $nc($(temporal->range($ChronoField::DAY_OF_MONTH)))->getMaximum()));
	int32_t curDow = $nc(temp)->get($ChronoField::DAY_OF_WEEK);
	int32_t daysDiff = dowValue - curDow;
	daysDiff = (daysDiff == 0 ? 0 : (daysDiff > 0 ? daysDiff - 7 : daysDiff));
	daysDiff -= (-ordinal - (int64_t)1) * (int64_t)7;
	$init($ChronoUnit);
	return temp->plus(daysDiff, $ChronoUnit::DAYS);
}

$Temporal* TemporalAdjusters::lambda$dayOfWeekInMonth$7(int32_t dowValue, int32_t ordinal, $Temporal* temporal) {
	$init($ChronoField);
	$var($Temporal, temp, $nc(temporal)->with($ChronoField::DAY_OF_MONTH, 1));
	int32_t curDow = $nc(temp)->get($ChronoField::DAY_OF_WEEK);
	int32_t dowDiff = (dowValue - curDow + 7) % 7;
	dowDiff += (ordinal - (int64_t)1) * (int64_t)7;
	$init($ChronoUnit);
	return temp->plus(dowDiff, $ChronoUnit::DAYS);
}

$Temporal* TemporalAdjusters::lambda$firstDayOfNextYear$6($Temporal* temporal) {
	$init($ChronoField);
	$init($ChronoUnit);
	return $nc($($nc(temporal)->with($ChronoField::DAY_OF_YEAR, 1)))->plus(1, $ChronoUnit::YEARS);
}

$Temporal* TemporalAdjusters::lambda$lastDayOfYear$5($Temporal* temporal) {
	$init($ChronoField);
	return $nc(temporal)->with($ChronoField::DAY_OF_YEAR, $nc($(temporal->range($ChronoField::DAY_OF_YEAR)))->getMaximum());
}

$Temporal* TemporalAdjusters::lambda$firstDayOfYear$4($Temporal* temporal) {
	$init($ChronoField);
	return $nc(temporal)->with($ChronoField::DAY_OF_YEAR, 1);
}

$Temporal* TemporalAdjusters::lambda$firstDayOfNextMonth$3($Temporal* temporal) {
	$init($ChronoField);
	$init($ChronoUnit);
	return $nc($($nc(temporal)->with($ChronoField::DAY_OF_MONTH, 1)))->plus(1, $ChronoUnit::MONTHS);
}

$Temporal* TemporalAdjusters::lambda$lastDayOfMonth$2($Temporal* temporal) {
	$init($ChronoField);
	return $nc(temporal)->with($ChronoField::DAY_OF_MONTH, $nc($(temporal->range($ChronoField::DAY_OF_MONTH)))->getMaximum());
}

$Temporal* TemporalAdjusters::lambda$firstDayOfMonth$1($Temporal* temporal) {
	$init($ChronoField);
	return $nc(temporal)->with($ChronoField::DAY_OF_MONTH, 1);
}

$Temporal* TemporalAdjusters::lambda$ofDateAdjuster$0($UnaryOperator* dateBasedAdjuster, $Temporal* temporal) {
	$useLocalCurrentObjectStackCache();
	$var($LocalDate, input, $LocalDate::from(temporal));
	$var($LocalDate, output, $cast($LocalDate, $nc(dateBasedAdjuster)->apply(input)));
	return $nc(temporal)->with(output);
}

TemporalAdjusters::TemporalAdjusters() {
}

$Class* TemporalAdjusters::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(TemporalAdjusters$$Lambda$lambda$ofDateAdjuster$0::classInfo$.name)) {
			return TemporalAdjusters$$Lambda$lambda$ofDateAdjuster$0::load$(name, initialize);
		}
		if (name->equals(TemporalAdjusters$$Lambda$lambda$firstDayOfMonth$1$1::classInfo$.name)) {
			return TemporalAdjusters$$Lambda$lambda$firstDayOfMonth$1$1::load$(name, initialize);
		}
		if (name->equals(TemporalAdjusters$$Lambda$lambda$lastDayOfMonth$2$2::classInfo$.name)) {
			return TemporalAdjusters$$Lambda$lambda$lastDayOfMonth$2$2::load$(name, initialize);
		}
		if (name->equals(TemporalAdjusters$$Lambda$lambda$firstDayOfNextMonth$3$3::classInfo$.name)) {
			return TemporalAdjusters$$Lambda$lambda$firstDayOfNextMonth$3$3::load$(name, initialize);
		}
		if (name->equals(TemporalAdjusters$$Lambda$lambda$firstDayOfYear$4$4::classInfo$.name)) {
			return TemporalAdjusters$$Lambda$lambda$firstDayOfYear$4$4::load$(name, initialize);
		}
		if (name->equals(TemporalAdjusters$$Lambda$lambda$lastDayOfYear$5$5::classInfo$.name)) {
			return TemporalAdjusters$$Lambda$lambda$lastDayOfYear$5$5::load$(name, initialize);
		}
		if (name->equals(TemporalAdjusters$$Lambda$lambda$firstDayOfNextYear$6$6::classInfo$.name)) {
			return TemporalAdjusters$$Lambda$lambda$firstDayOfNextYear$6$6::load$(name, initialize);
		}
		if (name->equals(TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$7$7::classInfo$.name)) {
			return TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$7$7::load$(name, initialize);
		}
		if (name->equals(TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$8$8::classInfo$.name)) {
			return TemporalAdjusters$$Lambda$lambda$dayOfWeekInMonth$8$8::load$(name, initialize);
		}
		if (name->equals(TemporalAdjusters$$Lambda$lambda$next$9$9::classInfo$.name)) {
			return TemporalAdjusters$$Lambda$lambda$next$9$9::load$(name, initialize);
		}
		if (name->equals(TemporalAdjusters$$Lambda$lambda$nextOrSame$10$10::classInfo$.name)) {
			return TemporalAdjusters$$Lambda$lambda$nextOrSame$10$10::load$(name, initialize);
		}
		if (name->equals(TemporalAdjusters$$Lambda$lambda$previous$11$11::classInfo$.name)) {
			return TemporalAdjusters$$Lambda$lambda$previous$11$11::load$(name, initialize);
		}
		if (name->equals(TemporalAdjusters$$Lambda$lambda$previousOrSame$12$12::classInfo$.name)) {
			return TemporalAdjusters$$Lambda$lambda$previousOrSame$12$12::load$(name, initialize);
		}
	}
	$loadClass(TemporalAdjusters, name, initialize, &_TemporalAdjusters_ClassInfo_, allocate$TemporalAdjusters);
	return class$;
}

$Class* TemporalAdjusters::class$ = nullptr;

		} // temporal
	} // time
} // java