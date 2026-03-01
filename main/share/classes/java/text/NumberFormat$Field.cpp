#include <java/text/NumberFormat$Field.h>

#include <java/io/InvalidObjectException.h>
#include <java/text/AttributedCharacterIterator$Attribute.h>
#include <java/text/Format$Field.h>
#include <java/text/NumberFormat.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <jcpp.h>

#undef CURRENCY
#undef DECIMAL_SEPARATOR
#undef EXPONENT
#undef EXPONENT_SIGN
#undef EXPONENT_SYMBOL
#undef FRACTION
#undef GROUPING_SEPARATOR
#undef INTEGER
#undef PERCENT
#undef PERMILLE
#undef PREFIX
#undef SIGN
#undef SUFFIX

using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Format$Field = ::java::text::Format$Field;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;

namespace java {
	namespace text {

$FieldInfo _NumberFormat$Field_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NumberFormat$Field, serialVersionUID)},
	{"instanceMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/text/NumberFormat$Field;>;", $PRIVATE | $STATIC | $FINAL, $staticField(NumberFormat$Field, instanceMap)},
	{"INTEGER", "Ljava/text/NumberFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(NumberFormat$Field, INTEGER)},
	{"FRACTION", "Ljava/text/NumberFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(NumberFormat$Field, FRACTION)},
	{"EXPONENT", "Ljava/text/NumberFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(NumberFormat$Field, EXPONENT)},
	{"DECIMAL_SEPARATOR", "Ljava/text/NumberFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(NumberFormat$Field, DECIMAL_SEPARATOR)},
	{"SIGN", "Ljava/text/NumberFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(NumberFormat$Field, SIGN)},
	{"GROUPING_SEPARATOR", "Ljava/text/NumberFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(NumberFormat$Field, GROUPING_SEPARATOR)},
	{"EXPONENT_SYMBOL", "Ljava/text/NumberFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(NumberFormat$Field, EXPONENT_SYMBOL)},
	{"PERCENT", "Ljava/text/NumberFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(NumberFormat$Field, PERCENT)},
	{"PERMILLE", "Ljava/text/NumberFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(NumberFormat$Field, PERMILLE)},
	{"CURRENCY", "Ljava/text/NumberFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(NumberFormat$Field, CURRENCY)},
	{"EXPONENT_SIGN", "Ljava/text/NumberFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(NumberFormat$Field, EXPONENT_SIGN)},
	{"PREFIX", "Ljava/text/NumberFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(NumberFormat$Field, PREFIX)},
	{"SUFFIX", "Ljava/text/NumberFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(NumberFormat$Field, SUFFIX)},
	{}
};

$MethodInfo _NumberFormat$Field_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $method(NumberFormat$Field, init$, void, $String*)},
	{"readResolve", "()Ljava/lang/Object;", nullptr, $PROTECTED, $virtualMethod(NumberFormat$Field, readResolve, $Object*), "java.io.InvalidObjectException"},
	{}
};

$InnerClassInfo _NumberFormat$Field_InnerClassesInfo_[] = {
	{"java.text.NumberFormat$Field", "java.text.NumberFormat", "Field", $PUBLIC | $STATIC},
	{"java.text.Format$Field", "java.text.Format", "Field", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _NumberFormat$Field_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.text.NumberFormat$Field",
	"java.text.Format$Field",
	nullptr,
	_NumberFormat$Field_FieldInfo_,
	_NumberFormat$Field_MethodInfo_,
	nullptr,
	nullptr,
	_NumberFormat$Field_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.text.NumberFormat"
};

$Object* allocate$NumberFormat$Field($Class* clazz) {
	return $of($alloc(NumberFormat$Field));
}

$Map* NumberFormat$Field::instanceMap = nullptr;
NumberFormat$Field* NumberFormat$Field::INTEGER = nullptr;
NumberFormat$Field* NumberFormat$Field::FRACTION = nullptr;
NumberFormat$Field* NumberFormat$Field::EXPONENT = nullptr;
NumberFormat$Field* NumberFormat$Field::DECIMAL_SEPARATOR = nullptr;
NumberFormat$Field* NumberFormat$Field::SIGN = nullptr;
NumberFormat$Field* NumberFormat$Field::GROUPING_SEPARATOR = nullptr;
NumberFormat$Field* NumberFormat$Field::EXPONENT_SYMBOL = nullptr;
NumberFormat$Field* NumberFormat$Field::PERCENT = nullptr;
NumberFormat$Field* NumberFormat$Field::PERMILLE = nullptr;
NumberFormat$Field* NumberFormat$Field::CURRENCY = nullptr;
NumberFormat$Field* NumberFormat$Field::EXPONENT_SIGN = nullptr;
NumberFormat$Field* NumberFormat$Field::PREFIX = nullptr;
NumberFormat$Field* NumberFormat$Field::SUFFIX = nullptr;

void NumberFormat$Field::init$($String* name) {
	$Format$Field::init$(name);
	if ($of(this)->getClass() == NumberFormat$Field::class$) {
		$nc(NumberFormat$Field::instanceMap)->put(name, this);
	}
}

$Object* NumberFormat$Field::readResolve() {
	$useLocalCurrentObjectStackCache();
	if ($of(this)->getClass() != NumberFormat$Field::class$) {
		$throwNew($InvalidObjectException, "subclass didn\'t correctly implement readResolve"_s);
	}
	$var($Object, instance, $nc(NumberFormat$Field::instanceMap)->get($(getName())));
	if (instance != nullptr) {
		return $of(instance);
	} else {
		$throwNew($InvalidObjectException, "unknown attribute name"_s);
	}
}

void clinit$NumberFormat$Field($Class* class$) {
	$assignStatic(NumberFormat$Field::instanceMap, $new($HashMap, 11));
	$assignStatic(NumberFormat$Field::INTEGER, $new(NumberFormat$Field, "integer"_s));
	$assignStatic(NumberFormat$Field::FRACTION, $new(NumberFormat$Field, "fraction"_s));
	$assignStatic(NumberFormat$Field::EXPONENT, $new(NumberFormat$Field, "exponent"_s));
	$assignStatic(NumberFormat$Field::DECIMAL_SEPARATOR, $new(NumberFormat$Field, "decimal separator"_s));
	$assignStatic(NumberFormat$Field::SIGN, $new(NumberFormat$Field, "sign"_s));
	$assignStatic(NumberFormat$Field::GROUPING_SEPARATOR, $new(NumberFormat$Field, "grouping separator"_s));
	$assignStatic(NumberFormat$Field::EXPONENT_SYMBOL, $new(NumberFormat$Field, "exponent symbol"_s));
	$assignStatic(NumberFormat$Field::PERCENT, $new(NumberFormat$Field, "percent"_s));
	$assignStatic(NumberFormat$Field::PERMILLE, $new(NumberFormat$Field, "per mille"_s));
	$assignStatic(NumberFormat$Field::CURRENCY, $new(NumberFormat$Field, "currency"_s));
	$assignStatic(NumberFormat$Field::EXPONENT_SIGN, $new(NumberFormat$Field, "exponent sign"_s));
	$assignStatic(NumberFormat$Field::PREFIX, $new(NumberFormat$Field, "prefix"_s));
	$assignStatic(NumberFormat$Field::SUFFIX, $new(NumberFormat$Field, "suffix"_s));
}

NumberFormat$Field::NumberFormat$Field() {
}

$Class* NumberFormat$Field::load$($String* name, bool initialize) {
	$loadClass(NumberFormat$Field, name, initialize, &_NumberFormat$Field_ClassInfo_, clinit$NumberFormat$Field, allocate$NumberFormat$Field);
	return class$;
}

$Class* NumberFormat$Field::class$ = nullptr;

	} // text
} // java