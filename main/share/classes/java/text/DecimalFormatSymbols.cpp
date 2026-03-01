#include <java/text/DecimalFormatSymbols.h>

#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/Cloneable.h>
#include <java/lang/InternalError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/text/spi/DecimalFormatSymbolsProvider.h>
#include <java/util/Currency.h>
#include <java/util/Locale$Category.h>
#include <java/util/Locale.h>
#include <java/util/Objects.h>
#include <java/util/OptionalInt.h>
#include <java/util/function/IntPredicate.h>
#include <java/util/stream/IntStream.h>
#include <sun/util/locale/provider/CalendarDataUtility.h>
#include <sun/util/locale/provider/LocaleProviderAdapter.h>
#include <sun/util/locale/provider/LocaleResources.h>
#include <sun/util/locale/provider/LocaleServiceProviderPool.h>
#include <sun/util/locale/provider/ResourceBundleBasedAdapter.h>
#include <jcpp.h>

#undef FORMAT
#undef ROOT

using $LocaleArray = $Array<::java::util::Locale>;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $Serializable = ::java::io::Serializable;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $DecimalFormatSymbolsProvider = ::java::text::spi::DecimalFormatSymbolsProvider;
using $Currency = ::java::util::Currency;
using $Locale = ::java::util::Locale;
using $Locale$Category = ::java::util::Locale$Category;
using $Objects = ::java::util::Objects;
using $OptionalInt = ::java::util::OptionalInt;
using $IntPredicate = ::java::util::function::IntPredicate;
using $IntStream = ::java::util::stream::IntStream;
using $CalendarDataUtility = ::sun::util::locale::provider::CalendarDataUtility;
using $LocaleProviderAdapter = ::sun::util::locale::provider::LocaleProviderAdapter;
using $LocaleResources = ::sun::util::locale::provider::LocaleResources;
using $LocaleServiceProviderPool = ::sun::util::locale::provider::LocaleServiceProviderPool;
using $ResourceBundleBasedAdapter = ::sun::util::locale::provider::ResourceBundleBasedAdapter;

namespace java {
	namespace text {

class DecimalFormatSymbols$$Lambda$lambda$findNonFormatChar$0 : public $IntPredicate {
	$class(DecimalFormatSymbols$$Lambda$lambda$findNonFormatChar$0, $NO_CLASS_INIT, $IntPredicate)
public:
	void init$() {
	}
	virtual bool test(int32_t c) override {
		 return DecimalFormatSymbols::lambda$findNonFormatChar$0(c);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DecimalFormatSymbols$$Lambda$lambda$findNonFormatChar$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DecimalFormatSymbols$$Lambda$lambda$findNonFormatChar$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DecimalFormatSymbols$$Lambda$lambda$findNonFormatChar$0, init$, void)},
	{"test", "(I)Z", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols$$Lambda$lambda$findNonFormatChar$0, test, bool, int32_t)},
	{}
};
$ClassInfo DecimalFormatSymbols$$Lambda$lambda$findNonFormatChar$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.text.DecimalFormatSymbols$$Lambda$lambda$findNonFormatChar$0",
	"java.lang.Object",
	"java.util.function.IntPredicate",
	nullptr,
	methodInfos
};
$Class* DecimalFormatSymbols$$Lambda$lambda$findNonFormatChar$0::load$($String* name, bool initialize) {
	$loadClass(DecimalFormatSymbols$$Lambda$lambda$findNonFormatChar$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DecimalFormatSymbols$$Lambda$lambda$findNonFormatChar$0::class$ = nullptr;

$FieldInfo _DecimalFormatSymbols_FieldInfo_[] = {
	{"zeroDigit", "C", nullptr, $PRIVATE, $field(DecimalFormatSymbols, zeroDigit)},
	{"groupingSeparator", "C", nullptr, $PRIVATE, $field(DecimalFormatSymbols, groupingSeparator)},
	{"decimalSeparator", "C", nullptr, $PRIVATE, $field(DecimalFormatSymbols, decimalSeparator)},
	{"perMill", "C", nullptr, $PRIVATE, $field(DecimalFormatSymbols, perMill)},
	{"percent", "C", nullptr, $PRIVATE, $field(DecimalFormatSymbols, percent)},
	{"digit", "C", nullptr, $PRIVATE, $field(DecimalFormatSymbols, digit)},
	{"patternSeparator", "C", nullptr, $PRIVATE, $field(DecimalFormatSymbols, patternSeparator)},
	{"infinity", "Ljava/lang/String;", nullptr, $PRIVATE, $field(DecimalFormatSymbols, infinity)},
	{"NaN", "Ljava/lang/String;", nullptr, $PRIVATE, $field(DecimalFormatSymbols, NaN)},
	{"minusSign", "C", nullptr, $PRIVATE, $field(DecimalFormatSymbols, minusSign)},
	{"currencySymbol", "Ljava/lang/String;", nullptr, $PRIVATE, $field(DecimalFormatSymbols, currencySymbol)},
	{"intlCurrencySymbol", "Ljava/lang/String;", nullptr, $PRIVATE, $field(DecimalFormatSymbols, intlCurrencySymbol)},
	{"monetarySeparator", "C", nullptr, $PRIVATE, $field(DecimalFormatSymbols, monetarySeparator)},
	{"exponential", "C", nullptr, $PRIVATE, $field(DecimalFormatSymbols, exponential)},
	{"exponentialSeparator", "Ljava/lang/String;", nullptr, $PRIVATE, $field(DecimalFormatSymbols, exponentialSeparator)},
	{"locale", "Ljava/util/Locale;", nullptr, $PRIVATE, $field(DecimalFormatSymbols, locale)},
	{"perMillText", "Ljava/lang/String;", nullptr, $PRIVATE, $field(DecimalFormatSymbols, perMillText)},
	{"percentText", "Ljava/lang/String;", nullptr, $PRIVATE, $field(DecimalFormatSymbols, percentText)},
	{"minusSignText", "Ljava/lang/String;", nullptr, $PRIVATE, $field(DecimalFormatSymbols, minusSignText)},
	{"monetaryGroupingSeparator", "C", nullptr, $PRIVATE, $field(DecimalFormatSymbols, monetaryGroupingSeparator)},
	{"currency", "Ljava/util/Currency;", nullptr, $PRIVATE | $TRANSIENT, $field(DecimalFormatSymbols, currency)},
	{"currencyInitialized", "Z", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(DecimalFormatSymbols, currencyInitialized)},
	{"hashCode", "I", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(DecimalFormatSymbols, hashCode$)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(DecimalFormatSymbols, serialVersionUID)},
	{"currentSerialVersion", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DecimalFormatSymbols, currentSerialVersion)},
	{"serialVersionOnStream", "I", nullptr, $PRIVATE, $field(DecimalFormatSymbols, serialVersionOnStream)},
	{}
};

$MethodInfo _DecimalFormatSymbols_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "()V", nullptr, $PUBLIC, $method(DecimalFormatSymbols, init$, void)},
	{"<init>", "(Ljava/util/Locale;)V", nullptr, $PUBLIC, $method(DecimalFormatSymbols, init$, void, $Locale*)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, clone, $Object*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, equals, bool, Object$*)},
	{"findNonFormatChar", "(Ljava/lang/String;C)C", nullptr, $PRIVATE, $method(DecimalFormatSymbols, findNonFormatChar, char16_t, $String*, char16_t)},
	{"getAvailableLocales", "()[Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC, $staticMethod(DecimalFormatSymbols, getAvailableLocales, $LocaleArray*)},
	{"getCurrency", "()Ljava/util/Currency;", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, getCurrency, $Currency*)},
	{"getCurrencySymbol", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, getCurrencySymbol, $String*)},
	{"getDecimalSeparator", "()C", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, getDecimalSeparator, char16_t)},
	{"getDigit", "()C", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, getDigit, char16_t)},
	{"getExponentSeparator", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, getExponentSeparator, $String*)},
	{"getExponentialSymbol", "()C", nullptr, 0, $virtualMethod(DecimalFormatSymbols, getExponentialSymbol, char16_t)},
	{"getGroupingSeparator", "()C", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, getGroupingSeparator, char16_t)},
	{"getInfinity", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, getInfinity, $String*)},
	{"getInstance", "()Ljava/text/DecimalFormatSymbols;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticMethod(DecimalFormatSymbols, getInstance, DecimalFormatSymbols*)},
	{"getInstance", "(Ljava/util/Locale;)Ljava/text/DecimalFormatSymbols;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticMethod(DecimalFormatSymbols, getInstance, DecimalFormatSymbols*, $Locale*)},
	{"getInternationalCurrencySymbol", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, getInternationalCurrencySymbol, $String*)},
	{"getMinusSign", "()C", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, getMinusSign, char16_t)},
	{"getMinusSignText", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(DecimalFormatSymbols, getMinusSignText, $String*)},
	{"getMonetaryDecimalSeparator", "()C", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, getMonetaryDecimalSeparator, char16_t)},
	{"getMonetaryGroupingSeparator", "()C", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, getMonetaryGroupingSeparator, char16_t)},
	{"getNaN", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, getNaN, $String*)},
	{"getPatternSeparator", "()C", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, getPatternSeparator, char16_t)},
	{"getPerMill", "()C", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, getPerMill, char16_t)},
	{"getPerMillText", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(DecimalFormatSymbols, getPerMillText, $String*)},
	{"getPercent", "()C", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, getPercent, char16_t)},
	{"getPercentText", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(DecimalFormatSymbols, getPercentText, $String*)},
	{"getZeroDigit", "()C", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, getZeroDigit, char16_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, hashCode, int32_t)},
	{"initialize", "(Ljava/util/Locale;)V", nullptr, $PRIVATE, $method(DecimalFormatSymbols, initialize, void, $Locale*)},
	{"initializeCurrency", "(Ljava/util/Locale;)V", nullptr, $PRIVATE, $method(DecimalFormatSymbols, initializeCurrency, void, $Locale*)},
	{"lambda$findNonFormatChar$0", "(I)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DecimalFormatSymbols, lambda$findNonFormatChar$0, bool, int32_t)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(DecimalFormatSymbols, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"setCurrency", "(Ljava/util/Currency;)V", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, setCurrency, void, $Currency*)},
	{"setCurrencySymbol", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, setCurrencySymbol, void, $String*)},
	{"setDecimalSeparator", "(C)V", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, setDecimalSeparator, void, char16_t)},
	{"setDigit", "(C)V", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, setDigit, void, char16_t)},
	{"setExponentSeparator", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, setExponentSeparator, void, $String*)},
	{"setExponentialSymbol", "(C)V", nullptr, 0, $virtualMethod(DecimalFormatSymbols, setExponentialSymbol, void, char16_t)},
	{"setGroupingSeparator", "(C)V", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, setGroupingSeparator, void, char16_t)},
	{"setInfinity", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, setInfinity, void, $String*)},
	{"setInternationalCurrencySymbol", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, setInternationalCurrencySymbol, void, $String*)},
	{"setMinusSign", "(C)V", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, setMinusSign, void, char16_t)},
	{"setMinusSignText", "(Ljava/lang/String;)V", nullptr, 0, $virtualMethod(DecimalFormatSymbols, setMinusSignText, void, $String*)},
	{"setMonetaryDecimalSeparator", "(C)V", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, setMonetaryDecimalSeparator, void, char16_t)},
	{"setMonetaryGroupingSeparator", "(C)V", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, setMonetaryGroupingSeparator, void, char16_t)},
	{"setNaN", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, setNaN, void, $String*)},
	{"setPatternSeparator", "(C)V", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, setPatternSeparator, void, char16_t)},
	{"setPerMill", "(C)V", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, setPerMill, void, char16_t)},
	{"setPerMillText", "(Ljava/lang/String;)V", nullptr, 0, $virtualMethod(DecimalFormatSymbols, setPerMillText, void, $String*)},
	{"setPercent", "(C)V", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, setPercent, void, char16_t)},
	{"setPercentText", "(Ljava/lang/String;)V", nullptr, 0, $virtualMethod(DecimalFormatSymbols, setPercentText, void, $String*)},
	{"setZeroDigit", "(C)V", nullptr, $PUBLIC, $virtualMethod(DecimalFormatSymbols, setZeroDigit, void, char16_t)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _DecimalFormatSymbols_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.text.DecimalFormatSymbols",
	"java.lang.Object",
	"java.lang.Cloneable,java.io.Serializable",
	_DecimalFormatSymbols_FieldInfo_,
	_DecimalFormatSymbols_MethodInfo_
};

$Object* allocate$DecimalFormatSymbols($Class* clazz) {
	return $of($alloc(DecimalFormatSymbols));
}

$String* DecimalFormatSymbols::toString() {
	 return this->$Cloneable::toString();
}

void DecimalFormatSymbols::finalize() {
	this->$Cloneable::finalize();
}

void DecimalFormatSymbols::init$() {
	this->serialVersionOnStream = DecimalFormatSymbols::currentSerialVersion;
	$init($Locale$Category);
	initialize($($Locale::getDefault($Locale$Category::FORMAT)));
}

void DecimalFormatSymbols::init$($Locale* locale) {
	this->serialVersionOnStream = DecimalFormatSymbols::currentSerialVersion;
	initialize(locale);
}

$LocaleArray* DecimalFormatSymbols::getAvailableLocales() {
	$init(DecimalFormatSymbols);
	$load($DecimalFormatSymbolsProvider);
	$var($LocaleServiceProviderPool, pool, $LocaleServiceProviderPool::getPool($DecimalFormatSymbolsProvider::class$));
	return $nc(pool)->getAvailableLocales();
}

DecimalFormatSymbols* DecimalFormatSymbols::getInstance() {
	$init(DecimalFormatSymbols);
	$init($Locale$Category);
	return getInstance($($Locale::getDefault($Locale$Category::FORMAT)));
}

DecimalFormatSymbols* DecimalFormatSymbols::getInstance($Locale* locale) {
	$init(DecimalFormatSymbols);
	$useLocalCurrentObjectStackCache();
	$var($LocaleProviderAdapter, adapter, nullptr);
	$load($DecimalFormatSymbolsProvider);
	$assign(adapter, $LocaleProviderAdapter::getAdapter($DecimalFormatSymbolsProvider::class$, locale));
	$var($DecimalFormatSymbolsProvider, provider, $nc(adapter)->getDecimalFormatSymbolsProvider());
	$var(DecimalFormatSymbols, dfsyms, $nc(provider)->getInstance(locale));
	if (dfsyms == nullptr) {
		$assign(provider, $nc($($LocaleProviderAdapter::forJRE()))->getDecimalFormatSymbolsProvider());
		$assign(dfsyms, $nc(provider)->getInstance(locale));
	}
	return dfsyms;
}

char16_t DecimalFormatSymbols::getZeroDigit() {
	return this->zeroDigit;
}

void DecimalFormatSymbols::setZeroDigit(char16_t zeroDigit) {
	this->hashCode$ = 0;
	this->zeroDigit = zeroDigit;
}

char16_t DecimalFormatSymbols::getGroupingSeparator() {
	return this->groupingSeparator;
}

void DecimalFormatSymbols::setGroupingSeparator(char16_t groupingSeparator) {
	this->hashCode$ = 0;
	this->groupingSeparator = groupingSeparator;
}

char16_t DecimalFormatSymbols::getDecimalSeparator() {
	return this->decimalSeparator;
}

void DecimalFormatSymbols::setDecimalSeparator(char16_t decimalSeparator) {
	this->hashCode$ = 0;
	this->decimalSeparator = decimalSeparator;
}

char16_t DecimalFormatSymbols::getPerMill() {
	return this->perMill;
}

void DecimalFormatSymbols::setPerMill(char16_t perMill) {
	this->hashCode$ = 0;
	this->perMill = perMill;
	$set(this, perMillText, $Character::toString(perMill));
}

char16_t DecimalFormatSymbols::getPercent() {
	return this->percent;
}

void DecimalFormatSymbols::setPercent(char16_t percent) {
	this->hashCode$ = 0;
	this->percent = percent;
	$set(this, percentText, $Character::toString(percent));
}

char16_t DecimalFormatSymbols::getDigit() {
	return this->digit;
}

void DecimalFormatSymbols::setDigit(char16_t digit) {
	this->hashCode$ = 0;
	this->digit = digit;
}

char16_t DecimalFormatSymbols::getPatternSeparator() {
	return this->patternSeparator;
}

void DecimalFormatSymbols::setPatternSeparator(char16_t patternSeparator) {
	this->hashCode$ = 0;
	this->patternSeparator = patternSeparator;
}

$String* DecimalFormatSymbols::getInfinity() {
	return this->infinity;
}

void DecimalFormatSymbols::setInfinity($String* infinity) {
	this->hashCode$ = 0;
	$set(this, infinity, infinity);
}

$String* DecimalFormatSymbols::getNaN() {
	return this->NaN;
}

void DecimalFormatSymbols::setNaN($String* NaN) {
	this->hashCode$ = 0;
	$set(this, NaN, NaN);
}

char16_t DecimalFormatSymbols::getMinusSign() {
	return this->minusSign;
}

void DecimalFormatSymbols::setMinusSign(char16_t minusSign) {
	this->hashCode$ = 0;
	this->minusSign = minusSign;
	$set(this, minusSignText, $Character::toString(minusSign));
}

$String* DecimalFormatSymbols::getCurrencySymbol() {
	initializeCurrency(this->locale);
	return this->currencySymbol;
}

void DecimalFormatSymbols::setCurrencySymbol($String* currency) {
	initializeCurrency(this->locale);
	this->hashCode$ = 0;
	$set(this, currencySymbol, currency);
}

$String* DecimalFormatSymbols::getInternationalCurrencySymbol() {
	initializeCurrency(this->locale);
	return this->intlCurrencySymbol;
}

void DecimalFormatSymbols::setInternationalCurrencySymbol($String* currencyCode) {
	initializeCurrency(this->locale);
	this->hashCode$ = 0;
	$set(this, intlCurrencySymbol, currencyCode);
	$set(this, currency, nullptr);
	if (currencyCode != nullptr) {
		try {
			$set(this, currency, $Currency::getInstance(currencyCode));
			$set(this, currencySymbol, $nc(this->currency)->getSymbol());
		} catch ($IllegalArgumentException& e) {
		}
	}
}

$Currency* DecimalFormatSymbols::getCurrency() {
	initializeCurrency(this->locale);
	return this->currency;
}

void DecimalFormatSymbols::setCurrency($Currency* currency) {
	if (currency == nullptr) {
		$throwNew($NullPointerException);
	}
	initializeCurrency(this->locale);
	this->hashCode$ = 0;
	$set(this, currency, currency);
	$set(this, intlCurrencySymbol, $nc(currency)->getCurrencyCode());
	$set(this, currencySymbol, currency->getSymbol(this->locale));
}

char16_t DecimalFormatSymbols::getMonetaryDecimalSeparator() {
	return this->monetarySeparator;
}

void DecimalFormatSymbols::setMonetaryDecimalSeparator(char16_t sep) {
	this->hashCode$ = 0;
	this->monetarySeparator = sep;
}

$String* DecimalFormatSymbols::getExponentSeparator() {
	return this->exponentialSeparator;
}

void DecimalFormatSymbols::setExponentSeparator($String* exp) {
	if (exp == nullptr) {
		$throwNew($NullPointerException);
	}
	this->hashCode$ = 0;
	$set(this, exponentialSeparator, exp);
}

char16_t DecimalFormatSymbols::getMonetaryGroupingSeparator() {
	return this->monetaryGroupingSeparator;
}

void DecimalFormatSymbols::setMonetaryGroupingSeparator(char16_t monetaryGroupingSeparator) {
	this->hashCode$ = 0;
	this->monetaryGroupingSeparator = monetaryGroupingSeparator;
}

char16_t DecimalFormatSymbols::getExponentialSymbol() {
	return this->exponential;
}

void DecimalFormatSymbols::setExponentialSymbol(char16_t exp) {
	this->exponential = exp;
}

$String* DecimalFormatSymbols::getPerMillText() {
	return this->perMillText;
}

void DecimalFormatSymbols::setPerMillText($String* perMillText) {
	$Objects::requireNonNull(perMillText);
	if (perMillText->isEmpty()) {
		$throwNew($IllegalArgumentException, "Empty argument string"_s);
	}
	this->hashCode$ = 0;
	$set(this, perMillText, perMillText);
	this->perMill = findNonFormatChar(perMillText, (char16_t)0x2030);
}

$String* DecimalFormatSymbols::getPercentText() {
	return this->percentText;
}

void DecimalFormatSymbols::setPercentText($String* percentText) {
	$Objects::requireNonNull(percentText);
	if (percentText->isEmpty()) {
		$throwNew($IllegalArgumentException, "Empty argument string"_s);
	}
	this->hashCode$ = 0;
	$set(this, percentText, percentText);
	this->percent = findNonFormatChar(percentText, u'%');
}

$String* DecimalFormatSymbols::getMinusSignText() {
	return this->minusSignText;
}

void DecimalFormatSymbols::setMinusSignText($String* minusSignText) {
	$Objects::requireNonNull(minusSignText);
	if (minusSignText->isEmpty()) {
		$throwNew($IllegalArgumentException, "Empty argument string"_s);
	}
	this->hashCode$ = 0;
	$set(this, minusSignText, minusSignText);
	this->minusSign = findNonFormatChar(minusSignText, u'-');
}

$Object* DecimalFormatSymbols::clone() {
	try {
		return $of($cast(DecimalFormatSymbols, $Cloneable::clone()));
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

bool DecimalFormatSymbols::equals(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	if (obj == nullptr) {
		return false;
	}
	if ($equals(this, obj)) {
		return true;
	}
	if ($of(this)->getClass() != $nc($of(obj))->getClass()) {
		return false;
	}
	$var(DecimalFormatSymbols, other, $cast(DecimalFormatSymbols, obj));
	bool var$7 = this->zeroDigit == $nc(other)->zeroDigit && this->groupingSeparator == other->groupingSeparator && this->decimalSeparator == other->decimalSeparator && this->percent == other->percent && $nc(this->percentText)->equals(other->percentText) && this->perMill == other->perMill;
	bool var$6 = var$7 && $nc(this->perMillText)->equals(other->perMillText) && this->digit == other->digit && this->minusSign == other->minusSign;
	bool var$5 = var$6 && $nc(this->minusSignText)->equals(other->minusSignText) && this->patternSeparator == other->patternSeparator;
	bool var$4 = var$5 && $nc(this->infinity)->equals(other->infinity);
	bool var$3 = var$4 && $nc(this->NaN)->equals(other->NaN);
	bool var$2 = var$3 && $nc($(getCurrencySymbol()))->equals($(other->getCurrencySymbol()));
	bool var$1 = var$2 && $nc(this->intlCurrencySymbol)->equals(other->intlCurrencySymbol) && this->currency == other->currency && this->monetarySeparator == other->monetarySeparator && this->monetaryGroupingSeparator == other->monetaryGroupingSeparator;
	bool var$0 = var$1 && $nc(this->exponentialSeparator)->equals(other->exponentialSeparator);
	return (var$0 && $nc(this->locale)->equals(other->locale));
}

int32_t DecimalFormatSymbols::hashCode() {
	$useLocalCurrentObjectStackCache();
	if (this->hashCode$ == 0) {
		this->hashCode$ = $Objects::hash($$new($ObjectArray, {
			$($of($Character::valueOf(this->zeroDigit))),
			$($of($Character::valueOf(this->groupingSeparator))),
			$($of($Character::valueOf(this->decimalSeparator))),
			$($of($Character::valueOf(this->percent))),
			$of(this->percentText),
			$($of($Character::valueOf(this->perMill))),
			$of(this->perMillText),
			$($of($Character::valueOf(this->digit))),
			$($of($Character::valueOf(this->minusSign))),
			$of(this->minusSignText),
			$($of($Character::valueOf(this->patternSeparator))),
			$of(this->infinity),
			$of(this->NaN),
			$($of(getCurrencySymbol())),
			$of(this->intlCurrencySymbol),
			$of(this->currency),
			$($of($Character::valueOf(this->monetarySeparator))),
			$($of($Character::valueOf(this->monetaryGroupingSeparator))),
			$of(this->exponentialSeparator),
			$of(this->locale)
		}));
	}
	return this->hashCode$;
}

void DecimalFormatSymbols::initialize($Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$set(this, locale, locale);
	$var($Locale, override$, $nc(locale)->getUnicodeLocaleType("nu"_s) == nullptr ? $CalendarDataUtility::findRegionOverride(locale) : locale);
	$load($DecimalFormatSymbolsProvider);
	$var($LocaleProviderAdapter, adapter, $LocaleProviderAdapter::getAdapter($DecimalFormatSymbolsProvider::class$, override$));
	if (!($instanceOf($ResourceBundleBasedAdapter, adapter))) {
		$assign(adapter, $LocaleProviderAdapter::getResourceBundleBased());
	}
	$var($ObjectArray, data, $nc($($nc(adapter)->getLocaleResources(override$)))->getDecimalFormatSymbolsData());
	$var($StringArray, numberElements, $cast($StringArray, $nc(data)->get(0)));
	this->decimalSeparator = $nc($nc(numberElements)->get(0))->charAt(0);
	this->groupingSeparator = $nc(numberElements->get(1))->charAt(0);
	this->patternSeparator = $nc(numberElements->get(2))->charAt(0);
	$set(this, percentText, numberElements->get(3));
	this->percent = findNonFormatChar(this->percentText, u'%');
	this->zeroDigit = $nc(numberElements->get(4))->charAt(0);
	this->digit = $nc(numberElements->get(5))->charAt(0);
	$set(this, minusSignText, numberElements->get(6));
	this->minusSign = findNonFormatChar(this->minusSignText, u'-');
	this->exponential = $nc(numberElements->get(7))->charAt(0);
	$set(this, exponentialSeparator, numberElements->get(7));
	$set(this, perMillText, numberElements->get(8));
	this->perMill = findNonFormatChar(this->perMillText, (char16_t)0x2030);
	$set(this, infinity, numberElements->get(9));
	$set(this, NaN, numberElements->get(10));
	this->monetarySeparator = numberElements->length < 12 || $nc(numberElements->get(11))->isEmpty() ? this->decimalSeparator : $nc(numberElements->get(11))->charAt(0);
	this->monetaryGroupingSeparator = numberElements->length < 13 || $nc(numberElements->get(12))->isEmpty() ? this->groupingSeparator : $nc(numberElements->get(12))->charAt(0);
	$set(this, intlCurrencySymbol, $cast($String, data->get(1)));
	$set(this, currencySymbol, $cast($String, data->get(2)));
}

char16_t DecimalFormatSymbols::findNonFormatChar($String* src, char16_t defChar) {
	$useLocalCurrentObjectStackCache();
	return (char16_t)$nc($($nc($($($nc(src)->chars())->filter(static_cast<$IntPredicate*>($$new(DecimalFormatSymbols$$Lambda$lambda$findNonFormatChar$0)))))->findFirst()))->orElse(defChar);
}

void DecimalFormatSymbols::initializeCurrency($Locale* locale) {
	$useLocalCurrentObjectStackCache();
	if (this->currencyInitialized) {
		return;
	}
	if (!$nc($($nc(locale)->getCountry()))->isEmpty()) {
		try {
			$set(this, currency, $Currency::getInstance(locale));
		} catch ($IllegalArgumentException& e) {
		}
	}
	if (this->currency != nullptr) {
		$load($DecimalFormatSymbolsProvider);
		$var($LocaleProviderAdapter, adapter, $LocaleProviderAdapter::getAdapter($DecimalFormatSymbolsProvider::class$, locale));
		if (!($instanceOf($ResourceBundleBasedAdapter, adapter))) {
			$assign(adapter, $LocaleProviderAdapter::getResourceBundleBased());
		}
		$var($ObjectArray, data, $nc($($nc(adapter)->getLocaleResources(locale)))->getDecimalFormatSymbolsData());
		$set(this, intlCurrencySymbol, $nc(this->currency)->getCurrencyCode());
		if ($nc(data)->get(1) != nullptr && $equals(data->get(1), this->intlCurrencySymbol)) {
			$set(this, currencySymbol, $cast($String, data->get(2)));
		} else {
			$set(this, currencySymbol, $nc(this->currency)->getSymbol(locale));
			data->set(1, this->intlCurrencySymbol);
			data->set(2, this->currencySymbol);
		}
	} else {
		$set(this, intlCurrencySymbol, "XXX"_s);
		try {
			$set(this, currency, $Currency::getInstance(this->intlCurrencySymbol));
		} catch ($IllegalArgumentException& e) {
		}
		$set(this, currencySymbol, u"¤"_s);
	}
	this->currencyInitialized = true;
}

void DecimalFormatSymbols::readObject($ObjectInputStream* stream) {
	$nc(stream)->defaultReadObject();
	if (this->serialVersionOnStream < 1) {
		this->monetarySeparator = this->decimalSeparator;
		this->exponential = u'E';
	}
	if (this->serialVersionOnStream < 2) {
		$init($Locale);
		$set(this, locale, $Locale::ROOT);
	}
	if (this->serialVersionOnStream < 3) {
		$set(this, exponentialSeparator, $Character::toString(this->exponential));
	}
	if (this->serialVersionOnStream < 4) {
		$set(this, perMillText, $Character::toString(this->perMill));
		$set(this, percentText, $Character::toString(this->percent));
		$set(this, minusSignText, $Character::toString(this->minusSign));
	} else {
		bool var$3 = findNonFormatChar(this->perMillText, (char16_t)0xFFFF) != this->perMill;
		bool var$2 = var$3 || findNonFormatChar(this->percentText, (char16_t)0xFFFF) != this->percent;
		if (var$2 || findNonFormatChar(this->minusSignText, (char16_t)0xFFFF) != this->minusSign) {
			$throwNew($InvalidObjectException, "\'char\' and \'String\' representations of either percent, per mille, and/or minus sign disagree."_s);
		}
	}
	if (this->serialVersionOnStream < 5) {
		this->monetaryGroupingSeparator = this->groupingSeparator;
	}
	this->serialVersionOnStream = DecimalFormatSymbols::currentSerialVersion;
	if (this->intlCurrencySymbol != nullptr) {
		try {
			$set(this, currency, $Currency::getInstance(this->intlCurrencySymbol));
		} catch ($IllegalArgumentException& e) {
		}
		this->currencyInitialized = true;
	}
}

bool DecimalFormatSymbols::lambda$findNonFormatChar$0(int32_t c) {
	$init(DecimalFormatSymbols);
	return $Character::getType(c) != $Character::FORMAT;
}

DecimalFormatSymbols::DecimalFormatSymbols() {
}

$Class* DecimalFormatSymbols::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DecimalFormatSymbols$$Lambda$lambda$findNonFormatChar$0::classInfo$.name)) {
			return DecimalFormatSymbols$$Lambda$lambda$findNonFormatChar$0::load$(name, initialize);
		}
	}
	$loadClass(DecimalFormatSymbols, name, initialize, &_DecimalFormatSymbols_ClassInfo_, allocate$DecimalFormatSymbols);
	return class$;
}

$Class* DecimalFormatSymbols::class$ = nullptr;

	} // text
} // java