#include <java/time/chrono/ThaiBuddhistEra.h>

#include <java/lang/Enum.h>
#include <java/time/DateTimeException.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/chrono/ThaiBuddhistChronology.h>
#include <java/time/chrono/ThaiBuddhistDate.h>
#include <java/time/format/DateTimeFormatter.h>
#include <java/time/format/DateTimeFormatterBuilder.h>
#include <java/time/format/TextStyle.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalField.h>
#include <java/util/Locale.h>
#include <jcpp.h>

#undef BE
#undef BEFORE_BE
#undef ERA
#undef INSTANCE

using $ThaiBuddhistEraArray = $Array<::java::time::chrono::ThaiBuddhistEra>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $DateTimeException = ::java::time::DateTimeException;
using $Chronology = ::java::time::chrono::Chronology;
using $ThaiBuddhistChronology = ::java::time::chrono::ThaiBuddhistChronology;
using $ThaiBuddhistDate = ::java::time::chrono::ThaiBuddhistDate;
using $DateTimeFormatter = ::java::time::format::DateTimeFormatter;
using $DateTimeFormatterBuilder = ::java::time::format::DateTimeFormatterBuilder;
using $TextStyle = ::java::time::format::TextStyle;
using $ChronoField = ::java::time::temporal::ChronoField;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalField = ::java::time::temporal::TemporalField;
using $Locale = ::java::util::Locale;

namespace java {
	namespace time {
		namespace chrono {

$FieldInfo _ThaiBuddhistEra_FieldInfo_[] = {
	{"BEFORE_BE", "Ljava/time/chrono/ThaiBuddhistEra;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(ThaiBuddhistEra, BEFORE_BE)},
	{"BE", "Ljava/time/chrono/ThaiBuddhistEra;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(ThaiBuddhistEra, BE)},
	{"$VALUES", "[Ljava/time/chrono/ThaiBuddhistEra;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(ThaiBuddhistEra, $VALUES)},
	{}
};

$MethodInfo _ThaiBuddhistEra_MethodInfo_[] = {
	{"$values", "()[Ljava/time/chrono/ThaiBuddhistEra;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ThaiBuddhistEra, $values, $ThaiBuddhistEraArray*)},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $FINAL},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL},
	{"*finalize", "()V", nullptr, $PROTECTED | $FINAL},
	{"*hashCode", "()I", nullptr, $PUBLIC | $FINAL},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(ThaiBuddhistEra, init$, void, $String*, int32_t)},
	{"getDisplayName", "(Ljava/time/format/TextStyle;Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistEra, getDisplayName, $String*, $TextStyle*, $Locale*)},
	{"getValue", "()I", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistEra, getValue, int32_t)},
	{"of", "(I)Ljava/time/chrono/ThaiBuddhistEra;", nullptr, $PUBLIC | $STATIC, $staticMethod(ThaiBuddhistEra, of, ThaiBuddhistEra*, int32_t)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"valueOf", "(Ljava/lang/String;)Ljava/time/chrono/ThaiBuddhistEra;", nullptr, $PUBLIC | $STATIC, $staticMethod(ThaiBuddhistEra, valueOf, ThaiBuddhistEra*, $String*)},
	{"values", "()[Ljava/time/chrono/ThaiBuddhistEra;", nullptr, $PUBLIC | $STATIC, $staticMethod(ThaiBuddhistEra, values, $ThaiBuddhistEraArray*)},
	{}
};

$ClassInfo _ThaiBuddhistEra_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER | $ENUM,
	"java.time.chrono.ThaiBuddhistEra",
	"java.lang.Enum",
	"java.time.chrono.Era",
	_ThaiBuddhistEra_FieldInfo_,
	_ThaiBuddhistEra_MethodInfo_,
	"Ljava/lang/Enum<Ljava/time/chrono/ThaiBuddhistEra;>;Ljava/time/chrono/Era;"
};

$Object* allocate$ThaiBuddhistEra($Class* clazz) {
	return $of($alloc(ThaiBuddhistEra));
}

$String* ThaiBuddhistEra::toString() {
	 return this->$Enum::toString();
}

bool ThaiBuddhistEra::equals(Object$* other) {
	 return this->$Enum::equals(other);
}

int32_t ThaiBuddhistEra::hashCode() {
	 return this->$Enum::hashCode();
}

$Object* ThaiBuddhistEra::clone() {
	 return this->$Enum::clone();
}

void ThaiBuddhistEra::finalize() {
	this->$Enum::finalize();
}

ThaiBuddhistEra* ThaiBuddhistEra::BEFORE_BE = nullptr;
ThaiBuddhistEra* ThaiBuddhistEra::BE = nullptr;
$ThaiBuddhistEraArray* ThaiBuddhistEra::$VALUES = nullptr;

$ThaiBuddhistEraArray* ThaiBuddhistEra::$values() {
	$init(ThaiBuddhistEra);
	return $new($ThaiBuddhistEraArray, {
		ThaiBuddhistEra::BEFORE_BE,
		ThaiBuddhistEra::BE
	});
}

$ThaiBuddhistEraArray* ThaiBuddhistEra::values() {
	$init(ThaiBuddhistEra);
	return $cast($ThaiBuddhistEraArray, ThaiBuddhistEra::$VALUES->clone());
}

ThaiBuddhistEra* ThaiBuddhistEra::valueOf($String* name) {
	$init(ThaiBuddhistEra);
	return $cast(ThaiBuddhistEra, $Enum::valueOf(ThaiBuddhistEra::class$, name));
}

void ThaiBuddhistEra::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

ThaiBuddhistEra* ThaiBuddhistEra::of(int32_t thaiBuddhistEra) {
	$init(ThaiBuddhistEra);
	$useLocalCurrentObjectStackCache();
	switch (thaiBuddhistEra) {
	case 0:
		{
			return ThaiBuddhistEra::BEFORE_BE;
		}
	case 1:
		{
			return ThaiBuddhistEra::BE;
		}
	default:
		{
			$throwNew($DateTimeException, $$str({"Invalid era: "_s, $$str(thaiBuddhistEra)}));
		}
	}
}

int32_t ThaiBuddhistEra::getValue() {
	return ordinal();
}

$String* ThaiBuddhistEra::getDisplayName($TextStyle* style, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	$init($ThaiBuddhistChronology);
	return $nc($($nc($($nc($($$new($DateTimeFormatterBuilder)->appendText(static_cast<$TemporalField*>($ChronoField::ERA), style)))->toFormatter(locale)))->withChronology($ThaiBuddhistChronology::INSTANCE)))->format(this == ThaiBuddhistEra::BE ? $(static_cast<$TemporalAccessor*>($ThaiBuddhistDate::of(1, 1, 1))) : $(static_cast<$TemporalAccessor*>($ThaiBuddhistDate::of(0, 1, 1))));
}

void clinit$ThaiBuddhistEra($Class* class$) {
	$assignStatic(ThaiBuddhistEra::BEFORE_BE, $new(ThaiBuddhistEra, "BEFORE_BE"_s, 0));
	$assignStatic(ThaiBuddhistEra::BE, $new(ThaiBuddhistEra, "BE"_s, 1));
	$assignStatic(ThaiBuddhistEra::$VALUES, ThaiBuddhistEra::$values());
}

ThaiBuddhistEra::ThaiBuddhistEra() {
}

$Class* ThaiBuddhistEra::load$($String* name, bool initialize) {
	$loadClass(ThaiBuddhistEra, name, initialize, &_ThaiBuddhistEra_ClassInfo_, clinit$ThaiBuddhistEra, allocate$ThaiBuddhistEra);
	return class$;
}

$Class* ThaiBuddhistEra::class$ = nullptr;

		} // chrono
	} // time
} // java