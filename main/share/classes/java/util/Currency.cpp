#include <java/util/Currency.h>

#include <java/io/DataInputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Currency$1.h>
#include <java/util/Currency$CurrencyNameGetter.h>
#include <java/util/Currency$CurrencyProperty.h>
#include <java/util/Currency$OtherCurrencyEntry.h>
#include <java/util/Currency$SpecialCaseEntry.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale$Category.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Optional.h>
#include <java/util/Properties.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/regex/Pattern.h>
#include <java/util/spi/CurrencyNameProvider.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/Stream.h>
#include <sun/util/locale/provider/CalendarDataUtility.h>
#include <sun/util/locale/provider/LocaleServiceProviderPool$LocalizedObjectGetter.h>
#include <sun/util/locale/provider/LocaleServiceProviderPool.h>
#include <jcpp.h>

#undef A_TO_Z
#undef COUNTRY_TYPE_MASK
#undef COUNTRY_WITHOUT_CURRENCY_ENTRY
#undef DISPLAY
#undef DISPLAYNAME
#undef INSTANCE
#undef INVALID_COUNTRY_ENTRY
#undef MAGIC_NUMBER
#undef MAX_VALUE
#undef MIN_VALUE
#undef NUMERIC_CODE_MASK
#undef NUMERIC_CODE_SHIFT
#undef ROOT
#undef SIMPLE_CASE_COUNTRY_DEFAULT_DIGITS_MASK
#undef SIMPLE_CASE_COUNTRY_DEFAULT_DIGITS_SHIFT
#undef SIMPLE_CASE_COUNTRY_FINAL_CHAR_MASK
#undef SIMPLE_CASE_COUNTRY_MASK
#undef SIMPLE_CASE_COUNTRY_MAX_DEFAULT_DIGITS
#undef SPECIAL_CASE_COUNTRY_INDEX_DELTA
#undef SPECIAL_CASE_COUNTRY_INDEX_MASK
#undef SPECIAL_CASE_COUNTRY_MASK
#undef SYMBOL
#undef VALID_FORMAT_VERSION

using $DataInputStream = ::java::io::DataInputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Currency$1 = ::java::util::Currency$1;
using $Currency$CurrencyNameGetter = ::java::util::Currency$CurrencyNameGetter;
using $Currency$CurrencyProperty = ::java::util::Currency$CurrencyProperty;
using $Currency$OtherCurrencyEntry = ::java::util::Currency$OtherCurrencyEntry;
using $Currency$SpecialCaseEntry = ::java::util::Currency$SpecialCaseEntry;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Locale$Category = ::java::util::Locale$Category;
using $Map = ::java::util::Map;
using $Optional = ::java::util::Optional;
using $Properties = ::java::util::Properties;
using $Set = ::java::util::Set;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $BiConsumer = ::java::util::function::BiConsumer;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Pattern = ::java::util::regex::Pattern;
using $CurrencyNameProvider = ::java::util::spi::CurrencyNameProvider;
using $Collectors = ::java::util::stream::Collectors;
using $Stream = ::java::util::stream::Stream;
using $CalendarDataUtility = ::sun::util::locale::provider::CalendarDataUtility;
using $LocaleServiceProviderPool = ::sun::util::locale::provider::LocaleServiceProviderPool;
using $LocaleServiceProviderPool$LocalizedObjectGetter = ::sun::util::locale::provider::LocaleServiceProviderPool$LocalizedObjectGetter;

namespace java {
	namespace util {

class Currency$$Lambda$lambda$getValidCurrencyData$0 : public $Function {
	$class(Currency$$Lambda$lambda$getValidCurrencyData$0, $NO_CLASS_INIT, $Function)
public:
	void init$($Properties* props, $Pattern* pattern) {
		$set(this, props, props);
		$set(this, pattern, pattern);
	}
	virtual $Object* apply(Object$* k) override {
		 return $of(Currency::lambda$getValidCurrencyData$0(props, pattern, $cast($String, k)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Currency$$Lambda$lambda$getValidCurrencyData$0>());
	}
	$Properties* props = nullptr;
	$Pattern* pattern = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Currency$$Lambda$lambda$getValidCurrencyData$0::fieldInfos[3] = {
	{"props", "Ljava/util/Properties;", nullptr, $PUBLIC, $field(Currency$$Lambda$lambda$getValidCurrencyData$0, props)},
	{"pattern", "Ljava/util/regex/Pattern;", nullptr, $PUBLIC, $field(Currency$$Lambda$lambda$getValidCurrencyData$0, pattern)},
	{}
};
$MethodInfo Currency$$Lambda$lambda$getValidCurrencyData$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/Properties;Ljava/util/regex/Pattern;)V", nullptr, $PUBLIC, $method(Currency$$Lambda$lambda$getValidCurrencyData$0, init$, void, $Properties*, $Pattern*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Currency$$Lambda$lambda$getValidCurrencyData$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Currency$$Lambda$lambda$getValidCurrencyData$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.Currency$$Lambda$lambda$getValidCurrencyData$0",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Currency$$Lambda$lambda$getValidCurrencyData$0::load$($String* name, bool initialize) {
	$loadClass(Currency$$Lambda$lambda$getValidCurrencyData$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Currency$$Lambda$lambda$getValidCurrencyData$0::class$ = nullptr;

class Currency$$Lambda$lambda$getValidCurrencyData$1$1 : public $Function {
	$class(Currency$$Lambda$lambda$getValidCurrencyData$1$1, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* o) override {
		 return $of(Currency::lambda$getValidCurrencyData$1($cast($Optional, o)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Currency$$Lambda$lambda$getValidCurrencyData$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Currency$$Lambda$lambda$getValidCurrencyData$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Currency$$Lambda$lambda$getValidCurrencyData$1$1, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Currency$$Lambda$lambda$getValidCurrencyData$1$1, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Currency$$Lambda$lambda$getValidCurrencyData$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.Currency$$Lambda$lambda$getValidCurrencyData$1$1",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Currency$$Lambda$lambda$getValidCurrencyData$1$1::load$($String* name, bool initialize) {
	$loadClass(Currency$$Lambda$lambda$getValidCurrencyData$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Currency$$Lambda$lambda$getValidCurrencyData$1$1::class$ = nullptr;

class Currency$$Lambda$lambda$getValidCurrencyData$2$2 : public $Function {
	$class(Currency$$Lambda$lambda$getValidCurrencyData$2$2, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* entry) override {
		 return $of(Currency::lambda$getValidCurrencyData$2($cast($Currency$CurrencyProperty, entry)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Currency$$Lambda$lambda$getValidCurrencyData$2$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Currency$$Lambda$lambda$getValidCurrencyData$2$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Currency$$Lambda$lambda$getValidCurrencyData$2$2, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Currency$$Lambda$lambda$getValidCurrencyData$2$2, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Currency$$Lambda$lambda$getValidCurrencyData$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.Currency$$Lambda$lambda$getValidCurrencyData$2$2",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Currency$$Lambda$lambda$getValidCurrencyData$2$2::load$($String* name, bool initialize) {
	$loadClass(Currency$$Lambda$lambda$getValidCurrencyData$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Currency$$Lambda$lambda$getValidCurrencyData$2$2::class$ = nullptr;

class Currency$$Lambda$lambda$getValidCurrencyData$4$3 : public $BiConsumer {
	$class(Currency$$Lambda$lambda$getValidCurrencyData$4$3, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($List* propertyEntries) {
		$set(this, propertyEntries, propertyEntries);
	}
	virtual void accept(Object$* curCode, Object$* list) override {
		Currency::lambda$getValidCurrencyData$4(propertyEntries, $cast($String, curCode), $cast($List, list));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Currency$$Lambda$lambda$getValidCurrencyData$4$3>());
	}
	$List* propertyEntries = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Currency$$Lambda$lambda$getValidCurrencyData$4$3::fieldInfos[2] = {
	{"propertyEntries", "Ljava/util/List;", nullptr, $PUBLIC, $field(Currency$$Lambda$lambda$getValidCurrencyData$4$3, propertyEntries)},
	{}
};
$MethodInfo Currency$$Lambda$lambda$getValidCurrencyData$4$3::methodInfos[3] = {
	{"<init>", "(Ljava/util/List;)V", nullptr, $PUBLIC, $method(Currency$$Lambda$lambda$getValidCurrencyData$4$3, init$, void, $List*)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Currency$$Lambda$lambda$getValidCurrencyData$4$3, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo Currency$$Lambda$lambda$getValidCurrencyData$4$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.Currency$$Lambda$lambda$getValidCurrencyData$4$3",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Currency$$Lambda$lambda$getValidCurrencyData$4$3::load$($String* name, bool initialize) {
	$loadClass(Currency$$Lambda$lambda$getValidCurrencyData$4$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Currency$$Lambda$lambda$getValidCurrencyData$4$3::class$ = nullptr;

class Currency$$Lambda$lambda$getValidCurrencyData$3$4 : public $Consumer {
	$class(Currency$$Lambda$lambda$getValidCurrencyData$3$4, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* prop) override {
		Currency::lambda$getValidCurrencyData$3($cast($Currency$CurrencyProperty, prop));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Currency$$Lambda$lambda$getValidCurrencyData$3$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Currency$$Lambda$lambda$getValidCurrencyData$3$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Currency$$Lambda$lambda$getValidCurrencyData$3$4, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Currency$$Lambda$lambda$getValidCurrencyData$3$4, accept, void, Object$*)},
	{}
};
$ClassInfo Currency$$Lambda$lambda$getValidCurrencyData$3$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.Currency$$Lambda$lambda$getValidCurrencyData$3$4",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* Currency$$Lambda$lambda$getValidCurrencyData$3$4::load$($String* name, bool initialize) {
	$loadClass(Currency$$Lambda$lambda$getValidCurrencyData$3$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Currency$$Lambda$lambda$getValidCurrencyData$3$4::class$ = nullptr;

$FieldInfo _Currency_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Currency, serialVersionUID)},
	{"currencyCode", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Currency, currencyCode)},
	{"defaultFractionDigits", "I", nullptr, $PRIVATE | $FINAL | $TRANSIENT, $field(Currency, defaultFractionDigits)},
	{"numericCode", "I", nullptr, $PRIVATE | $FINAL | $TRANSIENT, $field(Currency, numericCode)},
	{"instances", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/lang/String;Ljava/util/Currency;>;", $PRIVATE | $STATIC, $staticField(Currency, instances)},
	{"available", "Ljava/util/HashSet;", "Ljava/util/HashSet<Ljava/util/Currency;>;", $PRIVATE | $STATIC, $staticField(Currency, available)},
	{"formatVersion", "I", nullptr, $STATIC, $staticField(Currency, formatVersion)},
	{"dataVersion", "I", nullptr, $STATIC, $staticField(Currency, dataVersion)},
	{"mainTable", "[I", nullptr, $STATIC, $staticField(Currency, mainTable)},
	{"specialCasesList", "Ljava/util/List;", "Ljava/util/List<Ljava/util/Currency$SpecialCaseEntry;>;", $STATIC, $staticField(Currency, specialCasesList)},
	{"otherCurrenciesList", "Ljava/util/List;", "Ljava/util/List<Ljava/util/Currency$OtherCurrencyEntry;>;", $STATIC, $staticField(Currency, otherCurrenciesList)},
	{"MAGIC_NUMBER", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Currency, MAGIC_NUMBER)},
	{"A_TO_Z", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Currency, A_TO_Z)},
	{"INVALID_COUNTRY_ENTRY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Currency, INVALID_COUNTRY_ENTRY)},
	{"COUNTRY_WITHOUT_CURRENCY_ENTRY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Currency, COUNTRY_WITHOUT_CURRENCY_ENTRY)},
	{"SIMPLE_CASE_COUNTRY_MASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Currency, SIMPLE_CASE_COUNTRY_MASK)},
	{"SIMPLE_CASE_COUNTRY_FINAL_CHAR_MASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Currency, SIMPLE_CASE_COUNTRY_FINAL_CHAR_MASK)},
	{"SIMPLE_CASE_COUNTRY_DEFAULT_DIGITS_MASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Currency, SIMPLE_CASE_COUNTRY_DEFAULT_DIGITS_MASK)},
	{"SIMPLE_CASE_COUNTRY_DEFAULT_DIGITS_SHIFT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Currency, SIMPLE_CASE_COUNTRY_DEFAULT_DIGITS_SHIFT)},
	{"SIMPLE_CASE_COUNTRY_MAX_DEFAULT_DIGITS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Currency, SIMPLE_CASE_COUNTRY_MAX_DEFAULT_DIGITS)},
	{"SPECIAL_CASE_COUNTRY_MASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Currency, SPECIAL_CASE_COUNTRY_MASK)},
	{"SPECIAL_CASE_COUNTRY_INDEX_MASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Currency, SPECIAL_CASE_COUNTRY_INDEX_MASK)},
	{"SPECIAL_CASE_COUNTRY_INDEX_DELTA", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Currency, SPECIAL_CASE_COUNTRY_INDEX_DELTA)},
	{"COUNTRY_TYPE_MASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Currency, COUNTRY_TYPE_MASK)},
	{"NUMERIC_CODE_MASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Currency, NUMERIC_CODE_MASK)},
	{"NUMERIC_CODE_SHIFT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Currency, NUMERIC_CODE_SHIFT)},
	{"VALID_FORMAT_VERSION", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Currency, VALID_FORMAT_VERSION)},
	{"SYMBOL", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Currency, SYMBOL)},
	{"DISPLAYNAME", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Currency, DISPLAYNAME)},
	{}
};

$MethodInfo _Currency_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;II)V", nullptr, $PRIVATE, $method(Currency, init$, void, $String*, int32_t, int32_t)},
	{"getAvailableCurrencies", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/util/Currency;>;", $PUBLIC | $STATIC, $staticMethod(Currency, getAvailableCurrencies, $Set*)},
	{"getCurrencyCode", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(Currency, getCurrencyCode, $String*)},
	{"getDefaultFractionDigits", "()I", nullptr, $PUBLIC, $method(Currency, getDefaultFractionDigits, int32_t)},
	{"getDisplayName", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(Currency, getDisplayName, $String*)},
	{"getDisplayName", "(Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $method(Currency, getDisplayName, $String*, $Locale*)},
	{"getInstance", "(Ljava/lang/String;)Ljava/util/Currency;", nullptr, $PUBLIC | $STATIC, $staticMethod(Currency, getInstance, Currency*, $String*)},
	{"getInstance", "(Ljava/lang/String;II)Ljava/util/Currency;", nullptr, $PRIVATE | $STATIC, $staticMethod(Currency, getInstance, Currency*, $String*, int32_t, int32_t)},
	{"getInstance", "(Ljava/util/Locale;)Ljava/util/Currency;", nullptr, $PUBLIC | $STATIC, $staticMethod(Currency, getInstance, Currency*, $Locale*)},
	{"getMainTableEntry", "(CC)I", nullptr, $PRIVATE | $STATIC, $staticMethod(Currency, getMainTableEntry, int32_t, char16_t, char16_t)},
	{"getNumericCode", "()I", nullptr, $PUBLIC, $method(Currency, getNumericCode, int32_t)},
	{"getNumericCodeAsString", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(Currency, getNumericCodeAsString, $String*)},
	{"getSymbol", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(Currency, getSymbol, $String*)},
	{"getSymbol", "(Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $method(Currency, getSymbol, $String*, $Locale*)},
	{"getValidCurrencyData", "(Ljava/util/Properties;Ljava/util/regex/Pattern;)Ljava/util/List;", "(Ljava/util/Properties;Ljava/util/regex/Pattern;)Ljava/util/List<Ljava/util/Currency$CurrencyProperty;>;", $PRIVATE | $STATIC, $staticMethod(Currency, getValidCurrencyData, $List*, $Properties*, $Pattern*)},
	{"lambda$getValidCurrencyData$0", "(Ljava/util/Properties;Ljava/util/regex/Pattern;Ljava/lang/String;)Ljava/util/Optional;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Currency, lambda$getValidCurrencyData$0, $Optional*, $Properties*, $Pattern*, $String*)},
	{"lambda$getValidCurrencyData$1", "(Ljava/util/Optional;)Ljava/util/stream/Stream;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Currency, lambda$getValidCurrencyData$1, $Stream*, $Optional*)},
	{"lambda$getValidCurrencyData$2", "(Ljava/util/Currency$CurrencyProperty;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Currency, lambda$getValidCurrencyData$2, $String*, $Currency$CurrencyProperty*)},
	{"lambda$getValidCurrencyData$3", "(Ljava/util/Currency$CurrencyProperty;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Currency, lambda$getValidCurrencyData$3, void, $Currency$CurrencyProperty*)},
	{"lambda$getValidCurrencyData$4", "(Ljava/util/List;Ljava/lang/String;Ljava/util/List;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Currency, lambda$getValidCurrencyData$4, void, $List*, $String*, $List*)},
	{"readIntArray", "(Ljava/io/DataInputStream;I)[I", nullptr, $PRIVATE | $STATIC, $staticMethod(Currency, readIntArray, $ints*, $DataInputStream*, int32_t), "java.io.IOException"},
	{"readOtherCurrencies", "(Ljava/io/DataInputStream;I)Ljava/util/List;", "(Ljava/io/DataInputStream;I)Ljava/util/List<Ljava/util/Currency$OtherCurrencyEntry;>;", $PRIVATE | $STATIC, $staticMethod(Currency, readOtherCurrencies, $List*, $DataInputStream*, int32_t), "java.io.IOException"},
	{"readResolve", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(Currency, readResolve, $Object*)},
	{"readSpecialCases", "(Ljava/io/DataInputStream;I)Ljava/util/List;", "(Ljava/io/DataInputStream;I)Ljava/util/List<Ljava/util/Currency$SpecialCaseEntry;>;", $PRIVATE | $STATIC, $staticMethod(Currency, readSpecialCases, $List*, $DataInputStream*, int32_t), "java.io.IOException"},
	{"replaceCurrencyData", "(Ljava/util/Currency$CurrencyProperty;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Currency, replaceCurrencyData, void, $Currency$CurrencyProperty*)},
	{"setMainTableEntry", "(CCI)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Currency, setMainTableEntry, void, char16_t, char16_t, int32_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Currency, toString, $String*)},
	{"updateMainTableEntry", "(Ljava/lang/String;II)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Currency, updateMainTableEntry, void, $String*, int32_t, int32_t)},
	{}
};

$InnerClassInfo _Currency_InnerClassesInfo_[] = {
	{"java.util.Currency$CurrencyProperty", "java.util.Currency", "CurrencyProperty", $PRIVATE | $STATIC},
	{"java.util.Currency$OtherCurrencyEntry", "java.util.Currency", "OtherCurrencyEntry", $PRIVATE | $STATIC},
	{"java.util.Currency$SpecialCaseEntry", "java.util.Currency", "SpecialCaseEntry", $PRIVATE | $STATIC},
	{"java.util.Currency$CurrencyNameGetter", "java.util.Currency", "CurrencyNameGetter", $PRIVATE | $STATIC},
	{"java.util.Currency$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Currency_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.util.Currency",
	"java.lang.Object",
	"java.io.Serializable",
	_Currency_FieldInfo_,
	_Currency_MethodInfo_,
	nullptr,
	nullptr,
	_Currency_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.Currency$CurrencyProperty,java.util.Currency$OtherCurrencyEntry,java.util.Currency$SpecialCaseEntry,java.util.Currency$CurrencyNameGetter,java.util.Currency$1"
};

$Object* allocate$Currency($Class* clazz) {
	return $of($alloc(Currency));
}

$ConcurrentMap* Currency::instances = nullptr;
$HashSet* Currency::available = nullptr;
int32_t Currency::formatVersion = 0;
int32_t Currency::dataVersion = 0;
$ints* Currency::mainTable = nullptr;
$List* Currency::specialCasesList = nullptr;
$List* Currency::otherCurrenciesList = nullptr;

void Currency::init$($String* currencyCode, int32_t defaultFractionDigits, int32_t numericCode) {
	$set(this, currencyCode, currencyCode);
	this->defaultFractionDigits = defaultFractionDigits;
	this->numericCode = numericCode;
}

Currency* Currency::getInstance($String* currencyCode) {
	$init(Currency);
	return getInstance(currencyCode, $Integer::MIN_VALUE, 0);
}

Currency* Currency::getInstance($String* currencyCode, int32_t defaultFractionDigits, int32_t numericCode) {
	$init(Currency);
	$useLocalCurrentObjectStackCache();
	$var(Currency, instance, $cast(Currency, $nc(Currency::instances)->get(currencyCode)));
	if (instance != nullptr) {
		return instance;
	}
	if (defaultFractionDigits == $Integer::MIN_VALUE) {
		bool found = false;
		if ($nc(currencyCode)->length() != 3) {
			$throwNew($IllegalArgumentException);
		}
		char16_t char1 = $nc(currencyCode)->charAt(0);
		char16_t char2 = currencyCode->charAt(1);
		int32_t tableEntry = getMainTableEntry(char1, char2);
		if (((int32_t)(tableEntry & (uint32_t)Currency::COUNTRY_TYPE_MASK)) == Currency::SIMPLE_CASE_COUNTRY_MASK && tableEntry != Currency::INVALID_COUNTRY_ENTRY && currencyCode->charAt(2) - u'A' == ((int32_t)(tableEntry & (uint32_t)Currency::SIMPLE_CASE_COUNTRY_FINAL_CHAR_MASK))) {
			defaultFractionDigits = $sr((int32_t)(tableEntry & (uint32_t)Currency::SIMPLE_CASE_COUNTRY_DEFAULT_DIGITS_MASK), Currency::SIMPLE_CASE_COUNTRY_DEFAULT_DIGITS_SHIFT);
			numericCode = $sr((int32_t)(tableEntry & (uint32_t)Currency::NUMERIC_CODE_MASK), Currency::NUMERIC_CODE_SHIFT);
			found = true;
		} else {
			$var($ints, fractionAndNumericCode, $Currency$SpecialCaseEntry::findEntry(currencyCode));
			if (fractionAndNumericCode != nullptr) {
				defaultFractionDigits = fractionAndNumericCode->get(0);
				numericCode = fractionAndNumericCode->get(1);
				found = true;
			}
		}
		if (!found) {
			$var($Currency$OtherCurrencyEntry, ocEntry, $Currency$OtherCurrencyEntry::findEntry(currencyCode));
			if (ocEntry == nullptr) {
				$throwNew($IllegalArgumentException);
			}
			defaultFractionDigits = $nc(ocEntry)->fraction;
			numericCode = ocEntry->numericCode;
		}
	}
	$var(Currency, currencyVal, $new(Currency, currencyCode, defaultFractionDigits, numericCode));
	$assign(instance, $cast(Currency, $nc(Currency::instances)->putIfAbsent(currencyCode, currencyVal)));
	return (instance != nullptr ? instance : currencyVal);
}

Currency* Currency::getInstance($Locale* locale) {
	$init(Currency);
	$useLocalCurrentObjectStackCache();
	$var($String, override$, $nc(locale)->getUnicodeLocaleType("cu"_s));
	if (override$ != nullptr) {
		try {
			return getInstance($(override$->toUpperCase($Locale::ROOT)));
		} catch ($IllegalArgumentException& iae) {
		}
	}
	$var($String, country, $nc($($CalendarDataUtility::findRegionOverride(locale)))->getCountry());
	if (country == nullptr || !$nc(country)->matches("^[a-zA-Z]{2}$"_s)) {
		$throwNew($IllegalArgumentException);
	}
	char16_t char1 = $nc(country)->charAt(0);
	char16_t char2 = country->charAt(1);
	int32_t tableEntry = getMainTableEntry(char1, char2);
	if (((int32_t)(tableEntry & (uint32_t)Currency::COUNTRY_TYPE_MASK)) == Currency::SIMPLE_CASE_COUNTRY_MASK && tableEntry != Currency::INVALID_COUNTRY_ENTRY) {
		char16_t finalChar = (char16_t)(((int32_t)(tableEntry & (uint32_t)Currency::SIMPLE_CASE_COUNTRY_FINAL_CHAR_MASK)) + u'A');
		int32_t defaultFractionDigits = $sr((int32_t)(tableEntry & (uint32_t)Currency::SIMPLE_CASE_COUNTRY_DEFAULT_DIGITS_MASK), Currency::SIMPLE_CASE_COUNTRY_DEFAULT_DIGITS_SHIFT);
		int32_t numericCode = $sr((int32_t)(tableEntry & (uint32_t)Currency::NUMERIC_CODE_MASK), Currency::NUMERIC_CODE_SHIFT);
		$var($StringBuilder, sb, $new($StringBuilder, country));
		sb->append(finalChar);
		return getInstance($(sb->toString()), defaultFractionDigits, numericCode);
	} else {
		if (tableEntry == Currency::INVALID_COUNTRY_ENTRY) {
			$throwNew($IllegalArgumentException);
		}
		if (tableEntry == Currency::COUNTRY_WITHOUT_CURRENCY_ENTRY) {
			return nullptr;
		} else {
			int32_t index = $Currency$SpecialCaseEntry::toIndex(tableEntry);
			$var($Currency$SpecialCaseEntry, scEntry, $cast($Currency$SpecialCaseEntry, $nc(Currency::specialCasesList)->get(index)));
			if ($nc(scEntry)->cutOverTime == $Long::MAX_VALUE || $System::currentTimeMillis() < $nc(scEntry)->cutOverTime) {
				return getInstance(scEntry->oldCurrency, scEntry->oldCurrencyFraction, scEntry->oldCurrencyNumericCode);
			} else {
				return getInstance(scEntry->newCurrency, scEntry->newCurrencyFraction, scEntry->newCurrencyNumericCode);
			}
		}
	}
}

$Set* Currency::getAvailableCurrencies() {
	$init(Currency);
	$useLocalCurrentObjectStackCache();
	$synchronized(Currency::class$) {
		if (Currency::available == nullptr) {
			$assignStatic(Currency::available, $new($HashSet, 256));
			for (char16_t c1 = u'A'; c1 <= u'Z'; ++c1) {
				for (char16_t c2 = u'A'; c2 <= u'Z'; ++c2) {
					int32_t tableEntry = getMainTableEntry(c1, c2);
					if (((int32_t)(tableEntry & (uint32_t)Currency::COUNTRY_TYPE_MASK)) == Currency::SIMPLE_CASE_COUNTRY_MASK && tableEntry != Currency::INVALID_COUNTRY_ENTRY) {
						char16_t finalChar = (char16_t)(((int32_t)(tableEntry & (uint32_t)Currency::SIMPLE_CASE_COUNTRY_FINAL_CHAR_MASK)) + u'A');
						int32_t defaultFractionDigits = $sr((int32_t)(tableEntry & (uint32_t)Currency::SIMPLE_CASE_COUNTRY_DEFAULT_DIGITS_MASK), Currency::SIMPLE_CASE_COUNTRY_DEFAULT_DIGITS_SHIFT);
						int32_t numericCode = $sr((int32_t)(tableEntry & (uint32_t)Currency::NUMERIC_CODE_MASK), Currency::NUMERIC_CODE_SHIFT);
						$var($StringBuilder, sb, $new($StringBuilder));
						sb->append(c1);
						sb->append(c2);
						sb->append(finalChar);
						$nc(Currency::available)->add($(getInstance($(sb->toString()), defaultFractionDigits, numericCode)));
					} else if (((int32_t)(tableEntry & (uint32_t)Currency::COUNTRY_TYPE_MASK)) == Currency::SPECIAL_CASE_COUNTRY_MASK && tableEntry != Currency::INVALID_COUNTRY_ENTRY && tableEntry != Currency::COUNTRY_WITHOUT_CURRENCY_ENTRY) {
						int32_t index = $Currency$SpecialCaseEntry::toIndex(tableEntry);
						$var($Currency$SpecialCaseEntry, scEntry, $cast($Currency$SpecialCaseEntry, $nc(Currency::specialCasesList)->get(index)));
						if ($nc(scEntry)->cutOverTime == $Long::MAX_VALUE || $System::currentTimeMillis() < $nc(scEntry)->cutOverTime) {
							$nc(Currency::available)->add($(getInstance(scEntry->oldCurrency, scEntry->oldCurrencyFraction, scEntry->oldCurrencyNumericCode)));
						} else {
							$nc(Currency::available)->add($(getInstance(scEntry->newCurrency, scEntry->newCurrencyFraction, scEntry->newCurrencyNumericCode)));
						}
					}
				}
			}
			{
				$var($Iterator, i$, $nc(Currency::otherCurrenciesList)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Currency$OtherCurrencyEntry, entry, $cast($Currency$OtherCurrencyEntry, i$->next()));
					{
						$nc(Currency::available)->add($(getInstance($nc(entry)->currencyCode)));
					}
				}
			}
		}
	}
	$var($Set, result, $cast($Set, $nc(Currency::available)->clone()));
	return result;
}

$String* Currency::getCurrencyCode() {
	return this->currencyCode;
}

$String* Currency::getSymbol() {
	$init($Locale$Category);
	return getSymbol($($Locale::getDefault($Locale$Category::DISPLAY)));
}

$String* Currency::getSymbol($Locale* locale$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Locale, locale, locale$renamed);
	$load($CurrencyNameProvider);
	$var($LocaleServiceProviderPool, pool, $LocaleServiceProviderPool::getPool($CurrencyNameProvider::class$));
	$assign(locale, $CalendarDataUtility::findRegionOverride(locale));
	$init($Currency$CurrencyNameGetter);
	$var($String, symbol, $cast($String, $nc(pool)->getLocalizedObject($Currency$CurrencyNameGetter::INSTANCE, locale, this->currencyCode, $$new($ObjectArray, {$($of($Integer::valueOf(Currency::SYMBOL)))}))));
	if (symbol != nullptr) {
		return symbol;
	}
	return this->currencyCode;
}

int32_t Currency::getDefaultFractionDigits() {
	return this->defaultFractionDigits;
}

int32_t Currency::getNumericCode() {
	return this->numericCode;
}

$String* Currency::getNumericCodeAsString() {
	if (this->numericCode < 100) {
		$var($StringBuilder, sb, $new($StringBuilder));
		sb->append(u'0');
		if (this->numericCode < 10) {
			sb->append(u'0');
		}
		return sb->append(this->numericCode)->toString();
	}
	return $String::valueOf(this->numericCode);
}

$String* Currency::getDisplayName() {
	$init($Locale$Category);
	return getDisplayName($($Locale::getDefault($Locale$Category::DISPLAY)));
}

$String* Currency::getDisplayName($Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$load($CurrencyNameProvider);
	$var($LocaleServiceProviderPool, pool, $LocaleServiceProviderPool::getPool($CurrencyNameProvider::class$));
	$init($Currency$CurrencyNameGetter);
	$var($String, result, $cast($String, $nc(pool)->getLocalizedObject($Currency$CurrencyNameGetter::INSTANCE, locale, this->currencyCode, $$new($ObjectArray, {$($of($Integer::valueOf(Currency::DISPLAYNAME)))}))));
	if (result != nullptr) {
		return result;
	}
	return this->currencyCode;
}

$String* Currency::toString() {
	return this->currencyCode;
}

$Object* Currency::readResolve() {
	return $of(getInstance(this->currencyCode));
}

int32_t Currency::getMainTableEntry(char16_t char1, char16_t char2) {
	$init(Currency);
	if (char1 < u'A' || char1 > u'Z' || char2 < u'A' || char2 > u'Z') {
		$throwNew($IllegalArgumentException);
	}
	return $nc(Currency::mainTable)->get((char1 - u'A') * Currency::A_TO_Z + (char2 - u'A'));
}

void Currency::setMainTableEntry(char16_t char1, char16_t char2, int32_t entry) {
	$init(Currency);
	if (char1 < u'A' || char1 > u'Z' || char2 < u'A' || char2 > u'Z') {
		$throwNew($IllegalArgumentException);
	}
	$nc(Currency::mainTable)->set((char1 - u'A') * Currency::A_TO_Z + (char2 - u'A'), entry);
}

$ints* Currency::readIntArray($DataInputStream* dis, int32_t count) {
	$init(Currency);
	$var($ints, ret, $new($ints, count));
	for (int32_t i = 0; i < count; ++i) {
		ret->set(i, $nc(dis)->readInt());
	}
	return ret;
}

$List* Currency::readSpecialCases($DataInputStream* dis, int32_t count) {
	$init(Currency);
	$useLocalCurrentObjectStackCache();
	$var($List, list, $new($ArrayList, count));
	int64_t cutOverTime = 0;
	$var($String, oldCurrency, nullptr);
	$var($String, newCurrency, nullptr);
	int32_t oldCurrencyFraction = 0;
	int32_t newCurrencyFraction = 0;
	int32_t oldCurrencyNumericCode = 0;
	int32_t newCurrencyNumericCode = 0;
	for (int32_t i = 0; i < count; ++i) {
		cutOverTime = $nc(dis)->readLong();
		$assign(oldCurrency, dis->readUTF());
		$assign(newCurrency, dis->readUTF());
		oldCurrencyFraction = dis->readInt();
		newCurrencyFraction = dis->readInt();
		oldCurrencyNumericCode = dis->readInt();
		newCurrencyNumericCode = dis->readInt();
		$var($Currency$SpecialCaseEntry, sc, $new($Currency$SpecialCaseEntry, cutOverTime, oldCurrency, newCurrency, oldCurrencyFraction, newCurrencyFraction, oldCurrencyNumericCode, newCurrencyNumericCode));
		list->add(sc);
	}
	return list;
}

$List* Currency::readOtherCurrencies($DataInputStream* dis, int32_t count) {
	$init(Currency);
	$useLocalCurrentObjectStackCache();
	$var($List, list, $new($ArrayList, count));
	$var($String, currencyCode, nullptr);
	int32_t fraction = 0;
	int32_t numericCode = 0;
	for (int32_t i = 0; i < count; ++i) {
		$assign(currencyCode, $nc(dis)->readUTF());
		fraction = dis->readInt();
		numericCode = dis->readInt();
		$var($Currency$OtherCurrencyEntry, oc, $new($Currency$OtherCurrencyEntry, currencyCode, fraction, numericCode));
		list->add(oc);
	}
	return list;
}

$List* Currency::getValidCurrencyData($Properties* props, $Pattern* pattern) {
	$init(Currency);
	$useLocalCurrentObjectStackCache();
	$var($Set, keys, $nc(props)->stringPropertyNames());
	$var($List, propertyEntries, $new($ArrayList));
	$var($Map, currencyCodeGroup, $cast($Map, $nc($($nc($($nc($($nc(keys)->stream()))->map(static_cast<$Function*>($$new(Currency$$Lambda$lambda$getValidCurrencyData$0, props, pattern)))))->flatMap(static_cast<$Function*>($$new(Currency$$Lambda$lambda$getValidCurrencyData$1$1)))))->collect($($Collectors::groupingBy(static_cast<$Function*>($$new(Currency$$Lambda$lambda$getValidCurrencyData$2$2)))))));
	$nc(currencyCodeGroup)->forEach(static_cast<$BiConsumer*>($$new(Currency$$Lambda$lambda$getValidCurrencyData$4$3, propertyEntries)));
	return propertyEntries;
}

void Currency::replaceCurrencyData($Currency$CurrencyProperty* prop) {
	$init(Currency);
	$useLocalCurrentObjectStackCache();
	$var($String, ctry, $nc(prop)->country);
	$var($String, code, prop->currencyCode);
	int32_t numeric = prop->numericCode;
	int32_t fraction = prop->fraction;
	int32_t entry = $sl(numeric, Currency::NUMERIC_CODE_SHIFT);
	int32_t index = $Currency$SpecialCaseEntry::indexOf(code, fraction, numeric);
	int32_t scCurrencyCodeIndex = -1;
	if (index == -1) {
		scCurrencyCodeIndex = $Currency$SpecialCaseEntry::currencyCodeIndex(code);
		if (scCurrencyCodeIndex != -1) {
			$nc(Currency::specialCasesList)->set(scCurrencyCodeIndex, $$new($Currency$SpecialCaseEntry, code, fraction, numeric));
			$var($Currency$OtherCurrencyEntry, oe, $Currency$OtherCurrencyEntry::findEntry(code));
			if (oe != nullptr) {
				int32_t oIndex = $nc(Currency::otherCurrenciesList)->indexOf(oe);
				$nc(Currency::otherCurrenciesList)->set(oIndex, $$new($Currency$OtherCurrencyEntry, code, fraction, numeric));
			}
		}
	}
	bool var$0 = index == -1;
	if (var$0) {
		char16_t var$2 = $nc(ctry)->charAt(0);
		bool var$1 = var$2 != $nc(code)->charAt(0);
		if (!var$1) {
			char16_t var$3 = $nc(ctry)->charAt(1);
			var$1 = var$3 != $nc(code)->charAt(1);
		}
		var$0 = (var$1);
	}
	if (var$0) {
		if (scCurrencyCodeIndex == -1) {
			$nc(Currency::specialCasesList)->add($$new($Currency$SpecialCaseEntry, code, fraction, numeric));
			index = $nc(Currency::specialCasesList)->size() - 1;
		} else {
			index = scCurrencyCodeIndex;
		}
		updateMainTableEntry(code, fraction, numeric);
	}
	if (index == -1) {
		entry |= ($sl(fraction, Currency::SIMPLE_CASE_COUNTRY_DEFAULT_DIGITS_SHIFT)) | ($nc(code)->charAt(2) - u'A');
	} else {
		entry = Currency::SPECIAL_CASE_COUNTRY_MASK | (index + Currency::SPECIAL_CASE_COUNTRY_INDEX_DELTA);
	}
	char16_t var$4 = $nc(ctry)->charAt(0);
	setMainTableEntry(var$4, ctry->charAt(1), entry);
}

void Currency::updateMainTableEntry($String* code, int32_t fraction, int32_t numeric) {
	$init(Currency);
	char16_t var$0 = $nc(code)->charAt(0);
	int32_t tableEntry = getMainTableEntry(var$0, code->charAt(1));
	int32_t entry = $sl(numeric, Currency::NUMERIC_CODE_SHIFT);
	if (((int32_t)(tableEntry & (uint32_t)Currency::COUNTRY_TYPE_MASK)) == Currency::SIMPLE_CASE_COUNTRY_MASK && tableEntry != Currency::INVALID_COUNTRY_ENTRY && $nc(code)->charAt(2) - u'A' == ((int32_t)(tableEntry & (uint32_t)Currency::SIMPLE_CASE_COUNTRY_FINAL_CHAR_MASK))) {
		int32_t numericCode = $sr((int32_t)(tableEntry & (uint32_t)Currency::NUMERIC_CODE_MASK), Currency::NUMERIC_CODE_SHIFT);
		int32_t defaultFractionDigits = $sr((int32_t)(tableEntry & (uint32_t)Currency::SIMPLE_CASE_COUNTRY_DEFAULT_DIGITS_MASK), Currency::SIMPLE_CASE_COUNTRY_DEFAULT_DIGITS_SHIFT);
		if (numeric != numericCode || fraction != defaultFractionDigits) {
			entry |= ($sl(fraction, Currency::SIMPLE_CASE_COUNTRY_DEFAULT_DIGITS_SHIFT)) | (code->charAt(2) - u'A');
			char16_t var$1 = code->charAt(0);
			setMainTableEntry(var$1, code->charAt(1), entry);
		}
	}
}

void Currency::lambda$getValidCurrencyData$4($List* propertyEntries, $String* curCode, $List* list) {
	$init(Currency);
	bool inconsistent = $Currency$CurrencyProperty::containsInconsistentInstances(list);
	if (inconsistent) {
		$nc(list)->forEach(static_cast<$Consumer*>($$new(Currency$$Lambda$lambda$getValidCurrencyData$3$4)));
	} else {
		$nc(propertyEntries)->addAll(list);
	}
}

void Currency::lambda$getValidCurrencyData$3($Currency$CurrencyProperty* prop) {
	$init(Currency);
	$Currency$CurrencyProperty::info($$str({"The property entry for "_s, $nc(prop)->country, " is inconsistent. Ignored."_s}), nullptr);
}

$String* Currency::lambda$getValidCurrencyData$2($Currency$CurrencyProperty* entry) {
	$init(Currency);
	return $nc(entry)->currencyCode;
}

$Stream* Currency::lambda$getValidCurrencyData$1($Optional* o) {
	$init(Currency);
	return $nc(o)->stream();
}

$Optional* Currency::lambda$getValidCurrencyData$0($Properties* props, $Pattern* pattern, $String* k) {
	$init(Currency);
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($String, var$0, $nc(k)->toUpperCase($Locale::ROOT));
	return $Currency$CurrencyProperty::getValidEntry(var$0, $($nc($($nc(props)->getProperty(k)))->toUpperCase($Locale::ROOT)), pattern);
}

void clinit$Currency($Class* class$) {
	$beforeCallerSensitive();
	$assignStatic(Currency::instances, $new($ConcurrentHashMap, 7));
	{
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Currency$1)));
	}
}

Currency::Currency() {
}

$Class* Currency::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Currency$$Lambda$lambda$getValidCurrencyData$0::classInfo$.name)) {
			return Currency$$Lambda$lambda$getValidCurrencyData$0::load$(name, initialize);
		}
		if (name->equals(Currency$$Lambda$lambda$getValidCurrencyData$1$1::classInfo$.name)) {
			return Currency$$Lambda$lambda$getValidCurrencyData$1$1::load$(name, initialize);
		}
		if (name->equals(Currency$$Lambda$lambda$getValidCurrencyData$2$2::classInfo$.name)) {
			return Currency$$Lambda$lambda$getValidCurrencyData$2$2::load$(name, initialize);
		}
		if (name->equals(Currency$$Lambda$lambda$getValidCurrencyData$4$3::classInfo$.name)) {
			return Currency$$Lambda$lambda$getValidCurrencyData$4$3::load$(name, initialize);
		}
		if (name->equals(Currency$$Lambda$lambda$getValidCurrencyData$3$4::classInfo$.name)) {
			return Currency$$Lambda$lambda$getValidCurrencyData$3$4::load$(name, initialize);
		}
	}
	$loadClass(Currency, name, initialize, &_Currency_ClassInfo_, clinit$Currency, allocate$Currency);
	return class$;
}

$Class* Currency::class$ = nullptr;

	} // util
} // java