#include <java/time/chrono/HijrahEra.h>

#include <java/lang/Enum.h>
#include <java/time/DateTimeException.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/chrono/Era.h>
#include <java/time/chrono/HijrahChronology.h>
#include <java/time/chrono/HijrahDate.h>
#include <java/time/format/DateTimeFormatter.h>
#include <java/time/format/DateTimeFormatterBuilder.h>
#include <java/time/format/TextStyle.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/ValueRange.h>
#include <java/util/Locale.h>
#include <jcpp.h>

#undef AH
#undef ERA
#undef INSTANCE

using $HijrahEraArray = $Array<::java::time::chrono::HijrahEra>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $DateTimeException = ::java::time::DateTimeException;
using $Chronology = ::java::time::chrono::Chronology;
using $Era = ::java::time::chrono::Era;
using $HijrahChronology = ::java::time::chrono::HijrahChronology;
using $HijrahDate = ::java::time::chrono::HijrahDate;
using $DateTimeFormatter = ::java::time::format::DateTimeFormatter;
using $DateTimeFormatterBuilder = ::java::time::format::DateTimeFormatterBuilder;
using $TextStyle = ::java::time::format::TextStyle;
using $ChronoField = ::java::time::temporal::ChronoField;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalField = ::java::time::temporal::TemporalField;
using $ValueRange = ::java::time::temporal::ValueRange;
using $Locale = ::java::util::Locale;

namespace java {
	namespace time {
		namespace chrono {

$FieldInfo _HijrahEra_FieldInfo_[] = {
	{"AH", "Ljava/time/chrono/HijrahEra;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(HijrahEra, AH)},
	{"$VALUES", "[Ljava/time/chrono/HijrahEra;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(HijrahEra, $VALUES)},
	{}
};

$MethodInfo _HijrahEra_MethodInfo_[] = {
	{"$values", "()[Ljava/time/chrono/HijrahEra;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(HijrahEra, $values, $HijrahEraArray*)},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $FINAL},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL},
	{"*finalize", "()V", nullptr, $PROTECTED | $FINAL},
	{"*hashCode", "()I", nullptr, $PUBLIC | $FINAL},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(HijrahEra, init$, void, $String*, int32_t)},
	{"getDisplayName", "(Ljava/time/format/TextStyle;Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HijrahEra, getDisplayName, $String*, $TextStyle*, $Locale*)},
	{"getValue", "()I", nullptr, $PUBLIC, $virtualMethod(HijrahEra, getValue, int32_t)},
	{"of", "(I)Ljava/time/chrono/HijrahEra;", nullptr, $PUBLIC | $STATIC, $staticMethod(HijrahEra, of, HijrahEra*, int32_t)},
	{"range", "(Ljava/time/temporal/TemporalField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(HijrahEra, range, $ValueRange*, $TemporalField*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"valueOf", "(Ljava/lang/String;)Ljava/time/chrono/HijrahEra;", nullptr, $PUBLIC | $STATIC, $staticMethod(HijrahEra, valueOf, HijrahEra*, $String*)},
	{"values", "()[Ljava/time/chrono/HijrahEra;", nullptr, $PUBLIC | $STATIC, $staticMethod(HijrahEra, values, $HijrahEraArray*)},
	{}
};

$ClassInfo _HijrahEra_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER | $ENUM,
	"java.time.chrono.HijrahEra",
	"java.lang.Enum",
	"java.time.chrono.Era",
	_HijrahEra_FieldInfo_,
	_HijrahEra_MethodInfo_,
	"Ljava/lang/Enum<Ljava/time/chrono/HijrahEra;>;Ljava/time/chrono/Era;"
};

$Object* allocate$HijrahEra($Class* clazz) {
	return $of($alloc(HijrahEra));
}

$String* HijrahEra::toString() {
	 return this->$Enum::toString();
}

bool HijrahEra::equals(Object$* other) {
	 return this->$Enum::equals(other);
}

int32_t HijrahEra::hashCode() {
	 return this->$Enum::hashCode();
}

$Object* HijrahEra::clone() {
	 return this->$Enum::clone();
}

void HijrahEra::finalize() {
	this->$Enum::finalize();
}

HijrahEra* HijrahEra::AH = nullptr;
$HijrahEraArray* HijrahEra::$VALUES = nullptr;

$HijrahEraArray* HijrahEra::$values() {
	$init(HijrahEra);
	return $new($HijrahEraArray, {HijrahEra::AH});
}

$HijrahEraArray* HijrahEra::values() {
	$init(HijrahEra);
	return $cast($HijrahEraArray, HijrahEra::$VALUES->clone());
}

HijrahEra* HijrahEra::valueOf($String* name) {
	$init(HijrahEra);
	return $cast(HijrahEra, $Enum::valueOf(HijrahEra::class$, name));
}

void HijrahEra::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

HijrahEra* HijrahEra::of(int32_t hijrahEra) {
	$init(HijrahEra);
	$useLocalCurrentObjectStackCache();
	if (hijrahEra == 1) {
		return HijrahEra::AH;
	} else {
		$throwNew($DateTimeException, $$str({"Invalid era: "_s, $$str(hijrahEra)}));
	}
}

int32_t HijrahEra::getValue() {
	return 1;
}

$ValueRange* HijrahEra::range($TemporalField* field) {
	$init($ChronoField);
	if ($equals(field, $ChronoField::ERA)) {
		return $ValueRange::of(1, 1);
	}
	return $Era::range(field);
}

$String* HijrahEra::getDisplayName($TextStyle* style, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	$init($HijrahChronology);
	return $nc($($nc($($nc($($$new($DateTimeFormatterBuilder)->appendText(static_cast<$TemporalField*>($ChronoField::ERA), style)))->toFormatter(locale)))->withChronology($HijrahChronology::INSTANCE)))->format($($HijrahDate::now()));
}

void clinit$HijrahEra($Class* class$) {
	$assignStatic(HijrahEra::AH, $new(HijrahEra, "AH"_s, 0));
	$assignStatic(HijrahEra::$VALUES, HijrahEra::$values());
}

HijrahEra::HijrahEra() {
}

$Class* HijrahEra::load$($String* name, bool initialize) {
	$loadClass(HijrahEra, name, initialize, &_HijrahEra_ClassInfo_, clinit$HijrahEra, allocate$HijrahEra);
	return class$;
}

$Class* HijrahEra::class$ = nullptr;

		} // chrono
	} // time
} // java