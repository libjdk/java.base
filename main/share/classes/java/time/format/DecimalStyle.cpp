#include <java/time/format/DecimalStyle.h>

#include <java/text/DecimalFormatSymbols.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Locale$Category.h>
#include <java/util/Locale.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <jcpp.h>

#undef CACHE
#undef FORMAT
#undef STANDARD

using $LocaleArray = $Array<::java::util::Locale>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $MethodInfo = ::java::lang::MethodInfo;
using $DecimalFormatSymbols = ::java::text::DecimalFormatSymbols;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Locale = ::java::util::Locale;
using $Locale$Category = ::java::util::Locale$Category;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;

namespace java {
	namespace time {
		namespace format {

$FieldInfo _DecimalStyle_FieldInfo_[] = {
	{"STANDARD", "Ljava/time/format/DecimalStyle;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DecimalStyle, STANDARD)},
	{"CACHE", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/util/Locale;Ljava/time/format/DecimalStyle;>;", $PRIVATE | $STATIC | $FINAL, $staticField(DecimalStyle, CACHE)},
	{"zeroDigit", "C", nullptr, $PRIVATE | $FINAL, $field(DecimalStyle, zeroDigit)},
	{"positiveSign", "C", nullptr, $PRIVATE | $FINAL, $field(DecimalStyle, positiveSign)},
	{"negativeSign", "C", nullptr, $PRIVATE | $FINAL, $field(DecimalStyle, negativeSign)},
	{"decimalSeparator", "C", nullptr, $PRIVATE | $FINAL, $field(DecimalStyle, decimalSeparator)},
	{}
};

$MethodInfo _DecimalStyle_MethodInfo_[] = {
	{"<init>", "(CCCC)V", nullptr, $PRIVATE, $method(DecimalStyle, init$, void, char16_t, char16_t, char16_t, char16_t)},
	{"convertNumberToI18N", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, 0, $method(DecimalStyle, convertNumberToI18N, $String*, $String*)},
	{"convertToDigit", "(C)I", nullptr, 0, $method(DecimalStyle, convertToDigit, int32_t, char16_t)},
	{"create", "(Ljava/util/Locale;)Ljava/time/format/DecimalStyle;", nullptr, $PRIVATE | $STATIC, $staticMethod(DecimalStyle, create, DecimalStyle*, $Locale*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(DecimalStyle, equals, bool, Object$*)},
	{"getAvailableLocales", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/util/Locale;>;", $PUBLIC | $STATIC, $staticMethod(DecimalStyle, getAvailableLocales, $Set*)},
	{"getDecimalSeparator", "()C", nullptr, $PUBLIC, $method(DecimalStyle, getDecimalSeparator, char16_t)},
	{"getNegativeSign", "()C", nullptr, $PUBLIC, $method(DecimalStyle, getNegativeSign, char16_t)},
	{"getPositiveSign", "()C", nullptr, $PUBLIC, $method(DecimalStyle, getPositiveSign, char16_t)},
	{"getZeroDigit", "()C", nullptr, $PUBLIC, $method(DecimalStyle, getZeroDigit, char16_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(DecimalStyle, hashCode, int32_t)},
	{"of", "(Ljava/util/Locale;)Ljava/time/format/DecimalStyle;", nullptr, $PUBLIC | $STATIC, $staticMethod(DecimalStyle, of, DecimalStyle*, $Locale*)},
	{"ofDefaultLocale", "()Ljava/time/format/DecimalStyle;", nullptr, $PUBLIC | $STATIC, $staticMethod(DecimalStyle, ofDefaultLocale, DecimalStyle*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DecimalStyle, toString, $String*)},
	{"withDecimalSeparator", "(C)Ljava/time/format/DecimalStyle;", nullptr, $PUBLIC, $method(DecimalStyle, withDecimalSeparator, DecimalStyle*, char16_t)},
	{"withNegativeSign", "(C)Ljava/time/format/DecimalStyle;", nullptr, $PUBLIC, $method(DecimalStyle, withNegativeSign, DecimalStyle*, char16_t)},
	{"withPositiveSign", "(C)Ljava/time/format/DecimalStyle;", nullptr, $PUBLIC, $method(DecimalStyle, withPositiveSign, DecimalStyle*, char16_t)},
	{"withZeroDigit", "(C)Ljava/time/format/DecimalStyle;", nullptr, $PUBLIC, $method(DecimalStyle, withZeroDigit, DecimalStyle*, char16_t)},
	{}
};

$ClassInfo _DecimalStyle_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.format.DecimalStyle",
	"java.lang.Object",
	nullptr,
	_DecimalStyle_FieldInfo_,
	_DecimalStyle_MethodInfo_
};

$Object* allocate$DecimalStyle($Class* clazz) {
	return $of($alloc(DecimalStyle));
}

DecimalStyle* DecimalStyle::STANDARD = nullptr;
$ConcurrentMap* DecimalStyle::CACHE = nullptr;

$Set* DecimalStyle::getAvailableLocales() {
	$init(DecimalStyle);
	$useLocalCurrentObjectStackCache();
	$var($LocaleArray, l, $DecimalFormatSymbols::getAvailableLocales());
	$var($Set, locales, $new($HashSet, $nc(l)->length));
	$Collections::addAll(locales, l);
	return locales;
}

DecimalStyle* DecimalStyle::ofDefaultLocale() {
	$init(DecimalStyle);
	$init($Locale$Category);
	return of($($Locale::getDefault($Locale$Category::FORMAT)));
}

DecimalStyle* DecimalStyle::of($Locale* locale) {
	$init(DecimalStyle);
	$Objects::requireNonNull($of(locale), "locale"_s);
	$var(DecimalStyle, info, $cast(DecimalStyle, $nc(DecimalStyle::CACHE)->get(locale)));
	if (info == nullptr) {
		$assign(info, create(locale));
		$nc(DecimalStyle::CACHE)->putIfAbsent(locale, info);
		$assign(info, $cast(DecimalStyle, $nc(DecimalStyle::CACHE)->get(locale)));
	}
	return info;
}

DecimalStyle* DecimalStyle::create($Locale* locale) {
	$init(DecimalStyle);
	$var($DecimalFormatSymbols, oldSymbols, $DecimalFormatSymbols::getInstance(locale));
	char16_t zeroDigit = $nc(oldSymbols)->getZeroDigit();
	char16_t positiveSign = u'+';
	char16_t negativeSign = oldSymbols->getMinusSign();
	char16_t decimalSeparator = oldSymbols->getDecimalSeparator();
	if (zeroDigit == u'0' && negativeSign == u'-' && decimalSeparator == u'.') {
		return DecimalStyle::STANDARD;
	}
	return $new(DecimalStyle, zeroDigit, positiveSign, negativeSign, decimalSeparator);
}

void DecimalStyle::init$(char16_t zeroChar, char16_t positiveSignChar, char16_t negativeSignChar, char16_t decimalPointChar) {
	this->zeroDigit = zeroChar;
	this->positiveSign = positiveSignChar;
	this->negativeSign = negativeSignChar;
	this->decimalSeparator = decimalPointChar;
}

char16_t DecimalStyle::getZeroDigit() {
	return this->zeroDigit;
}

DecimalStyle* DecimalStyle::withZeroDigit(char16_t zeroDigit) {
	if (zeroDigit == this->zeroDigit) {
		return this;
	}
	return $new(DecimalStyle, zeroDigit, this->positiveSign, this->negativeSign, this->decimalSeparator);
}

char16_t DecimalStyle::getPositiveSign() {
	return this->positiveSign;
}

DecimalStyle* DecimalStyle::withPositiveSign(char16_t positiveSign) {
	if (positiveSign == this->positiveSign) {
		return this;
	}
	return $new(DecimalStyle, this->zeroDigit, positiveSign, this->negativeSign, this->decimalSeparator);
}

char16_t DecimalStyle::getNegativeSign() {
	return this->negativeSign;
}

DecimalStyle* DecimalStyle::withNegativeSign(char16_t negativeSign) {
	if (negativeSign == this->negativeSign) {
		return this;
	}
	return $new(DecimalStyle, this->zeroDigit, this->positiveSign, negativeSign, this->decimalSeparator);
}

char16_t DecimalStyle::getDecimalSeparator() {
	return this->decimalSeparator;
}

DecimalStyle* DecimalStyle::withDecimalSeparator(char16_t decimalSeparator) {
	if (decimalSeparator == this->decimalSeparator) {
		return this;
	}
	return $new(DecimalStyle, this->zeroDigit, this->positiveSign, this->negativeSign, decimalSeparator);
}

int32_t DecimalStyle::convertToDigit(char16_t ch) {
	int32_t val = ch - this->zeroDigit;
	return (val >= 0 && val <= 9) ? val : -1;
}

$String* DecimalStyle::convertNumberToI18N($String* numericText) {
	if (this->zeroDigit == u'0') {
		return numericText;
	}
	int32_t diff = this->zeroDigit - u'0';
	$var($chars, array, $nc(numericText)->toCharArray());
	for (int32_t i = 0; i < array->length; ++i) {
		array->set(i, (char16_t)(array->get(i) + diff));
	}
	return $new($String, array);
}

bool DecimalStyle::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	$var(DecimalStyle, other, nullptr);
	bool var$4 = $instanceOf(DecimalStyle, obj);
	if (var$4) {
		$assign(other, $cast(DecimalStyle, obj));
		var$4 = true;
	}
	bool var$3 = var$4;
	bool var$2 = var$3 && this->zeroDigit == $nc(other)->zeroDigit;
	bool var$1 = var$2 && this->positiveSign == other->positiveSign;
	bool var$0 = var$1 && this->negativeSign == other->negativeSign;
	return (var$0 && this->decimalSeparator == other->decimalSeparator);
}

int32_t DecimalStyle::hashCode() {
	return this->zeroDigit + this->positiveSign + this->negativeSign + this->decimalSeparator;
}

$String* DecimalStyle::toString() {
	$useLocalCurrentObjectStackCache();
	return $str({"DecimalStyle["_s, $$str(this->zeroDigit), $$str(this->positiveSign), $$str(this->negativeSign), $$str(this->decimalSeparator), "]"_s});
}

void clinit$DecimalStyle($Class* class$) {
	$assignStatic(DecimalStyle::STANDARD, $new(DecimalStyle, u'0', u'+', u'-', u'.'));
	$assignStatic(DecimalStyle::CACHE, $new($ConcurrentHashMap, 16, 0.75f, 2));
}

DecimalStyle::DecimalStyle() {
}

$Class* DecimalStyle::load$($String* name, bool initialize) {
	$loadClass(DecimalStyle, name, initialize, &_DecimalStyle_ClassInfo_, clinit$DecimalStyle, allocate$DecimalStyle);
	return class$;
}

$Class* DecimalStyle::class$ = nullptr;

		} // format
	} // time
} // java