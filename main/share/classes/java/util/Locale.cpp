#include <java/util/Locale.h>

#include <java/io/ObjectInputStream$GetField.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream$PutField.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/ObjectStreamField.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/Cloneable.h>
#include <java/lang/InternalError.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/Permission.h>
#include <java/text/MessageFormat.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/IllformedLocaleException.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale$1.h>
#include <java/util/Locale$Cache.h>
#include <java/util/Locale$Category.h>
#include <java/util/Locale$FilteringMode.h>
#include <java/util/Locale$IsoCountryCode.h>
#include <java/util/Locale$LocaleKey.h>
#include <java/util/Locale$LocaleNameGetter.h>
#include <java/util/LocaleISOData.h>
#include <java/util/Map.h>
#include <java/util/MissingResourceException.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/Properties.h>
#include <java/util/PropertyPermission.h>
#include <java/util/Set.h>
#include <java/util/StringTokenizer.h>
#include <java/util/TimeZone.h>
#include <java/util/function/BinaryOperator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/spi/LocaleNameProvider.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/Stream.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/util/locale/BaseLocale.h>
#include <sun/util/locale/InternalLocaleBuilder.h>
#include <sun/util/locale/LanguageTag.h>
#include <sun/util/locale/LocaleExtensions.h>
#include <sun/util/locale/LocaleMatcher.h>
#include <sun/util/locale/LocaleSyntaxException.h>
#include <sun/util/locale/LocaleUtils.h>
#include <sun/util/locale/ParseStatus.h>
#include <sun/util/locale/provider/LocaleProviderAdapter.h>
#include <sun/util/locale/provider/LocaleResources.h>
#include <sun/util/locale/provider/LocaleServiceProviderPool$LocalizedObjectGetter.h>
#include <sun/util/locale/provider/LocaleServiceProviderPool.h>
#include <sun/util/locale/provider/TimeZoneNameUtility.h>
#include <jcpp.h>

#undef AUTOSELECT_FILTERING
#undef CALENDAR_JAPANESE
#undef CANADA
#undef CANADA_FRENCH
#undef CHINA
#undef CHINESE
#undef CONSTANT_LOCALES
#undef DISPLAY
#undef DISPLAY_COUNTRY
#undef DISPLAY_LANGUAGE
#undef DISPLAY_SCRIPT
#undef DISPLAY_UEXT_KEY
#undef DISPLAY_UEXT_TYPE
#undef DISPLAY_VARIANT
#undef ENGLISH
#undef FORMAT
#undef FRANCE
#undef FRENCH
#undef GERMAN
#undef GERMANY
#undef INSTANCE
#undef ITALIAN
#undef ITALY
#undef JAPAN
#undef JAPANESE
#undef KOREA
#undef KOREAN
#undef LOCALECACHE
#undef LONG
#undef NUMBER_THAI
#undef PRC
#undef PRIVATEUSE
#undef PRIVATE_USE_EXTENSION
#undef ROOT
#undef SEP
#undef SIMPLIFIED_CHINESE
#undef TAIWAN
#undef TRADITIONAL_CHINESE
#undef TYPE
#undef UK
#undef UNICODE_LOCALE_EXTENSION
#undef US

using $ObjectStreamFieldArray = $Array<::java::io::ObjectStreamField>;
using $LocaleArray = $Array<::java::util::Locale>;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectInputStream$GetField = ::java::io::ObjectInputStream$GetField;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ObjectOutputStream$PutField = ::java::io::ObjectOutputStream$PutField;
using $ObjectStreamField = ::java::io::ObjectStreamField;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $SecurityManager = ::java::lang::SecurityManager;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Permission = ::java::security::Permission;
using $MessageFormat = ::java::text::MessageFormat;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $IllformedLocaleException = ::java::util::IllformedLocaleException;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale$1 = ::java::util::Locale$1;
using $Locale$Cache = ::java::util::Locale$Cache;
using $Locale$Category = ::java::util::Locale$Category;
using $Locale$FilteringMode = ::java::util::Locale$FilteringMode;
using $Locale$IsoCountryCode = ::java::util::Locale$IsoCountryCode;
using $Locale$LocaleKey = ::java::util::Locale$LocaleKey;
using $Locale$LocaleNameGetter = ::java::util::Locale$LocaleNameGetter;
using $LocaleISOData = ::java::util::LocaleISOData;
using $Map = ::java::util::Map;
using $MissingResourceException = ::java::util::MissingResourceException;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $Properties = ::java::util::Properties;
using $PropertyPermission = ::java::util::PropertyPermission;
using $Set = ::java::util::Set;
using $StringTokenizer = ::java::util::StringTokenizer;
using $TimeZone = ::java::util::TimeZone;
using $BinaryOperator = ::java::util::function::BinaryOperator;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $LocaleNameProvider = ::java::util::spi::LocaleNameProvider;
using $Collectors = ::java::util::stream::Collectors;
using $Stream = ::java::util::stream::Stream;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $BaseLocale = ::sun::util::locale::BaseLocale;
using $InternalLocaleBuilder = ::sun::util::locale::InternalLocaleBuilder;
using $LanguageTag = ::sun::util::locale::LanguageTag;
using $LocaleExtensions = ::sun::util::locale::LocaleExtensions;
using $LocaleMatcher = ::sun::util::locale::LocaleMatcher;
using $LocaleSyntaxException = ::sun::util::locale::LocaleSyntaxException;
using $LocaleUtils = ::sun::util::locale::LocaleUtils;
using $ParseStatus = ::sun::util::locale::ParseStatus;
using $LocaleProviderAdapter = ::sun::util::locale::provider::LocaleProviderAdapter;
using $LocaleResources = ::sun::util::locale::provider::LocaleResources;
using $LocaleServiceProviderPool = ::sun::util::locale::provider::LocaleServiceProviderPool;
using $LocaleServiceProviderPool$LocalizedObjectGetter = ::sun::util::locale::provider::LocaleServiceProviderPool$LocalizedObjectGetter;
using $TimeZoneNameUtility = ::sun::util::locale::provider::TimeZoneNameUtility;

namespace java {
	namespace util {

class Locale$$Lambda$lambda$getDisplayName$0 : public $Function {
	$class(Locale$$Lambda$lambda$getDisplayName$0, $NO_CLASS_INIT, $Function)
public:
	void init$(Locale* inst, Locale* inLocale) {
		$set(this, inst$, inst);
		$set(this, inLocale, inLocale);
	}
	virtual $Object* apply(Object$* key) override {
		 return $of($nc(inst$)->lambda$getDisplayName$0(inLocale, $cast($String, key)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Locale$$Lambda$lambda$getDisplayName$0>());
	}
	Locale* inst$ = nullptr;
	Locale* inLocale = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Locale$$Lambda$lambda$getDisplayName$0::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Locale$$Lambda$lambda$getDisplayName$0, inst$)},
	{"inLocale", "Ljava/util/Locale;", nullptr, $PUBLIC, $field(Locale$$Lambda$lambda$getDisplayName$0, inLocale)},
	{}
};
$MethodInfo Locale$$Lambda$lambda$getDisplayName$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/Locale;Ljava/util/Locale;)V", nullptr, $PUBLIC, $method(Locale$$Lambda$lambda$getDisplayName$0, init$, void, Locale*, Locale*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Locale$$Lambda$lambda$getDisplayName$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Locale$$Lambda$lambda$getDisplayName$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.Locale$$Lambda$lambda$getDisplayName$0",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Locale$$Lambda$lambda$getDisplayName$0::load$($String* name, bool initialize) {
	$loadClass(Locale$$Lambda$lambda$getDisplayName$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Locale$$Lambda$lambda$getDisplayName$0::class$ = nullptr;

class Locale$$Lambda$add$1 : public $Consumer {
	$class(Locale$$Lambda$add$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$($ArrayList* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* e) override {
		$nc(inst$)->add(e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Locale$$Lambda$add$1>());
	}
	$ArrayList* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Locale$$Lambda$add$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Locale$$Lambda$add$1, inst$)},
	{}
};
$MethodInfo Locale$$Lambda$add$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/ArrayList;)V", nullptr, $PUBLIC, $method(Locale$$Lambda$add$1, init$, void, $ArrayList*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Locale$$Lambda$add$1, accept, void, Object$*)},
	{}
};
$ClassInfo Locale$$Lambda$add$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.Locale$$Lambda$add$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* Locale$$Lambda$add$1::load$($String* name, bool initialize) {
	$loadClass(Locale$$Lambda$add$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Locale$$Lambda$add$1::class$ = nullptr;

class Locale$$Lambda$lambda$getDisplayName$1$2 : public $Function {
	$class(Locale$$Lambda$lambda$getDisplayName$1$2, $NO_CLASS_INIT, $Function)
public:
	void init$(Locale* inst, $LocaleResources* lr, Locale* inLocale) {
		$set(this, inst$, inst);
		$set(this, lr, lr);
		$set(this, inLocale, inLocale);
	}
	virtual $Object* apply(Object$* key) override {
		 return $of($nc(inst$)->lambda$getDisplayName$1(lr, inLocale, $cast($String, key)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Locale$$Lambda$lambda$getDisplayName$1$2>());
	}
	Locale* inst$ = nullptr;
	$LocaleResources* lr = nullptr;
	Locale* inLocale = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Locale$$Lambda$lambda$getDisplayName$1$2::fieldInfos[4] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Locale$$Lambda$lambda$getDisplayName$1$2, inst$)},
	{"lr", "Lsun/util/locale/provider/LocaleResources;", nullptr, $PUBLIC, $field(Locale$$Lambda$lambda$getDisplayName$1$2, lr)},
	{"inLocale", "Ljava/util/Locale;", nullptr, $PUBLIC, $field(Locale$$Lambda$lambda$getDisplayName$1$2, inLocale)},
	{}
};
$MethodInfo Locale$$Lambda$lambda$getDisplayName$1$2::methodInfos[3] = {
	{"<init>", "(Ljava/util/Locale;Lsun/util/locale/provider/LocaleResources;Ljava/util/Locale;)V", nullptr, $PUBLIC, $method(Locale$$Lambda$lambda$getDisplayName$1$2, init$, void, Locale*, $LocaleResources*, Locale*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Locale$$Lambda$lambda$getDisplayName$1$2, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Locale$$Lambda$lambda$getDisplayName$1$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.Locale$$Lambda$lambda$getDisplayName$1$2",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Locale$$Lambda$lambda$getDisplayName$1$2::load$($String* name, bool initialize) {
	$loadClass(Locale$$Lambda$lambda$getDisplayName$1$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Locale$$Lambda$lambda$getDisplayName$1$2::class$ = nullptr;

class Locale$$Lambda$lambda$getDisplayKeyTypeExtensionString$2$3 : public $Function {
	$class(Locale$$Lambda$lambda$getDisplayKeyTypeExtensionString$2$3, $NO_CLASS_INIT, $Function)
public:
	void init$(Locale* inLocale) {
		$set(this, inLocale, inLocale);
	}
	virtual $Object* apply(Object$* id) override {
		 return $of(Locale::lambda$getDisplayKeyTypeExtensionString$2(inLocale, $cast($String, id)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Locale$$Lambda$lambda$getDisplayKeyTypeExtensionString$2$3>());
	}
	Locale* inLocale = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Locale$$Lambda$lambda$getDisplayKeyTypeExtensionString$2$3::fieldInfos[2] = {
	{"inLocale", "Ljava/util/Locale;", nullptr, $PUBLIC, $field(Locale$$Lambda$lambda$getDisplayKeyTypeExtensionString$2$3, inLocale)},
	{}
};
$MethodInfo Locale$$Lambda$lambda$getDisplayKeyTypeExtensionString$2$3::methodInfos[3] = {
	{"<init>", "(Ljava/util/Locale;)V", nullptr, $PUBLIC, $method(Locale$$Lambda$lambda$getDisplayKeyTypeExtensionString$2$3, init$, void, Locale*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Locale$$Lambda$lambda$getDisplayKeyTypeExtensionString$2$3, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Locale$$Lambda$lambda$getDisplayKeyTypeExtensionString$2$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.Locale$$Lambda$lambda$getDisplayKeyTypeExtensionString$2$3",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Locale$$Lambda$lambda$getDisplayKeyTypeExtensionString$2$3::load$($String* name, bool initialize) {
	$loadClass(Locale$$Lambda$lambda$getDisplayKeyTypeExtensionString$2$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Locale$$Lambda$lambda$getDisplayKeyTypeExtensionString$2$3::class$ = nullptr;

class Locale$$Lambda$lambda$formatList$3$4 : public $BinaryOperator {
	$class(Locale$$Lambda$lambda$formatList$3$4, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$($String* pattern) {
		$set(this, pattern, pattern);
	}
	virtual $Object* apply(Object$* s1, Object$* s2) override {
		 return $of(Locale::lambda$formatList$3(pattern, $cast($String, s1), $cast($String, s2)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Locale$$Lambda$lambda$formatList$3$4>());
	}
	$String* pattern = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Locale$$Lambda$lambda$formatList$3$4::fieldInfos[2] = {
	{"pattern", "Ljava/lang/String;", nullptr, $PUBLIC, $field(Locale$$Lambda$lambda$formatList$3$4, pattern)},
	{}
};
$MethodInfo Locale$$Lambda$lambda$formatList$3$4::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(Locale$$Lambda$lambda$formatList$3$4, init$, void, $String*)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Locale$$Lambda$lambda$formatList$3$4, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Locale$$Lambda$lambda$formatList$3$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.Locale$$Lambda$lambda$formatList$3$4",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	fieldInfos,
	methodInfos
};
$Class* Locale$$Lambda$lambda$formatList$3$4::load$($String* name, bool initialize) {
	$loadClass(Locale$$Lambda$lambda$formatList$3$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Locale$$Lambda$lambda$formatList$3$4::class$ = nullptr;

$FieldInfo _Locale_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Locale, $assertionsDisabled)},
	{"ENGLISH", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, ENGLISH)},
	{"FRENCH", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, FRENCH)},
	{"GERMAN", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, GERMAN)},
	{"ITALIAN", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, ITALIAN)},
	{"JAPANESE", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, JAPANESE)},
	{"KOREAN", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, KOREAN)},
	{"CHINESE", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, CHINESE)},
	{"SIMPLIFIED_CHINESE", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, SIMPLIFIED_CHINESE)},
	{"TRADITIONAL_CHINESE", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, TRADITIONAL_CHINESE)},
	{"FRANCE", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, FRANCE)},
	{"GERMANY", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, GERMANY)},
	{"ITALY", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, ITALY)},
	{"JAPAN", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, JAPAN)},
	{"KOREA", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, KOREA)},
	{"UK", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, UK)},
	{"US", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, US)},
	{"CANADA", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, CANADA)},
	{"CANADA_FRENCH", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, CANADA_FRENCH)},
	{"ROOT", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, ROOT)},
	{"CONSTANT_LOCALES", "Ljava/util/Map;", "Ljava/util/Map<Lsun/util/locale/BaseLocale;Ljava/util/Locale;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Locale, CONSTANT_LOCALES)},
	{"CHINA", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, CHINA)},
	{"PRC", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, PRC)},
	{"TAIWAN", "Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Locale, TAIWAN)},
	{"PRIVATE_USE_EXTENSION", "C", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Locale, PRIVATE_USE_EXTENSION)},
	{"UNICODE_LOCALE_EXTENSION", "C", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Locale, UNICODE_LOCALE_EXTENSION)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(Locale, serialVersionUID)},
	{"DISPLAY_LANGUAGE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Locale, DISPLAY_LANGUAGE)},
	{"DISPLAY_COUNTRY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Locale, DISPLAY_COUNTRY)},
	{"DISPLAY_VARIANT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Locale, DISPLAY_VARIANT)},
	{"DISPLAY_SCRIPT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Locale, DISPLAY_SCRIPT)},
	{"DISPLAY_UEXT_KEY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Locale, DISPLAY_UEXT_KEY)},
	{"DISPLAY_UEXT_TYPE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Locale, DISPLAY_UEXT_TYPE)},
	{"baseLocale", "Lsun/util/locale/BaseLocale;", nullptr, $PRIVATE | $TRANSIENT, $field(Locale, baseLocale)},
	{"localeExtensions", "Lsun/util/locale/LocaleExtensions;", nullptr, $PRIVATE | $TRANSIENT, $field(Locale, localeExtensions)},
	{"hashCodeValue", "I", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(Locale, hashCodeValue)},
	{"defaultLocale", "Ljava/util/Locale;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(Locale, defaultLocale)},
	{"defaultDisplayLocale", "Ljava/util/Locale;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(Locale, defaultDisplayLocale)},
	{"defaultFormatLocale", "Ljava/util/Locale;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(Locale, defaultFormatLocale)},
	{"languageTag", "Ljava/lang/String;", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(Locale, languageTag)},
	{"serialPersistentFields", "[Ljava/io/ObjectStreamField;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Locale, serialPersistentFields)},
	{"isoLanguages", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(Locale, isoLanguages)},
	{"isoCountries", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(Locale, isoCountries)},
	{}
};

$MethodInfo _Locale_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(Lsun/util/locale/BaseLocale;Lsun/util/locale/LocaleExtensions;)V", nullptr, $PRIVATE, $method(Locale, init$, void, $BaseLocale*, $LocaleExtensions*)},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(Locale, init$, void, $String*, $String*, $String*)},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(Locale, init$, void, $String*, $String*)},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(Locale, init$, void, $String*)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Locale, clone, $Object*)},
	{"convertOldISOCodes", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Locale, convertOldISOCodes, $String*, $String*)},
	{"createConstant", "(B)Ljava/util/Locale;", nullptr, $PRIVATE | $STATIC, $staticMethod(Locale, createConstant, Locale*, int8_t)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Locale, equals, bool, Object$*)},
	{"filter", "(Ljava/util/List;Ljava/util/Collection;Ljava/util/Locale$FilteringMode;)Ljava/util/List;", "(Ljava/util/List<Ljava/util/Locale$LanguageRange;>;Ljava/util/Collection<Ljava/util/Locale;>;Ljava/util/Locale$FilteringMode;)Ljava/util/List<Ljava/util/Locale;>;", $PUBLIC | $STATIC, $staticMethod(Locale, filter, $List*, $List*, $Collection*, $Locale$FilteringMode*)},
	{"filter", "(Ljava/util/List;Ljava/util/Collection;)Ljava/util/List;", "(Ljava/util/List<Ljava/util/Locale$LanguageRange;>;Ljava/util/Collection<Ljava/util/Locale;>;)Ljava/util/List<Ljava/util/Locale;>;", $PUBLIC | $STATIC, $staticMethod(Locale, filter, $List*, $List*, $Collection*)},
	{"filterTags", "(Ljava/util/List;Ljava/util/Collection;Ljava/util/Locale$FilteringMode;)Ljava/util/List;", "(Ljava/util/List<Ljava/util/Locale$LanguageRange;>;Ljava/util/Collection<Ljava/lang/String;>;Ljava/util/Locale$FilteringMode;)Ljava/util/List<Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(Locale, filterTags, $List*, $List*, $Collection*, $Locale$FilteringMode*)},
	{"filterTags", "(Ljava/util/List;Ljava/util/Collection;)Ljava/util/List;", "(Ljava/util/List<Ljava/util/Locale$LanguageRange;>;Ljava/util/Collection<Ljava/lang/String;>;)Ljava/util/List<Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(Locale, filterTags, $List*, $List*, $Collection*)},
	{"forLanguageTag", "(Ljava/lang/String;)Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC, $staticMethod(Locale, forLanguageTag, Locale*, $String*)},
	{"formatList", "([Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Locale, formatList, $String*, $StringArray*, $String*)},
	{"getAvailableLocales", "()[Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC, $staticMethod(Locale, getAvailableLocales, $LocaleArray*)},
	{"getBaseLocale", "()Lsun/util/locale/BaseLocale;", nullptr, 0, $method(Locale, getBaseLocale, $BaseLocale*)},
	{"getCompatibilityExtensions", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Lsun/util/locale/LocaleExtensions;", nullptr, $PRIVATE | $STATIC, $staticMethod(Locale, getCompatibilityExtensions, $LocaleExtensions*, $String*, $String*, $String*, $String*)},
	{"getCountry", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(Locale, getCountry, $String*)},
	{"getDefault", "()Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC, $staticMethod(Locale, getDefault, Locale*)},
	{"getDefault", "(Ljava/util/Locale$Category;)Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC, $staticMethod(Locale, getDefault, Locale*, $Locale$Category*)},
	{"getDefaultExtensions", "(Ljava/lang/String;)Ljava/util/Optional;", "(Ljava/lang/String;)Ljava/util/Optional<Lsun/util/locale/LocaleExtensions;>;", $PRIVATE | $STATIC, $staticMethod(Locale, getDefaultExtensions, $Optional*, $String*)},
	{"getDisplayCountry", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $method(Locale, getDisplayCountry, $String*)},
	{"getDisplayCountry", "(Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $method(Locale, getDisplayCountry, $String*, Locale*)},
	{"getDisplayKeyTypeExtensionString", "(Ljava/lang/String;Lsun/util/locale/provider/LocaleResources;Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Locale, getDisplayKeyTypeExtensionString, $String*, $String*, $LocaleResources*, Locale*)},
	{"getDisplayLanguage", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $method(Locale, getDisplayLanguage, $String*)},
	{"getDisplayLanguage", "(Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $method(Locale, getDisplayLanguage, $String*, Locale*)},
	{"getDisplayLocale", "()Ljava/util/Locale;", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $staticMethod(Locale, getDisplayLocale, Locale*)},
	{"getDisplayName", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $method(Locale, getDisplayName, $String*)},
	{"getDisplayName", "(Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $method(Locale, getDisplayName, $String*, Locale*)},
	{"getDisplayScript", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(Locale, getDisplayScript, $String*)},
	{"getDisplayScript", "(Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $method(Locale, getDisplayScript, $String*, Locale*)},
	{"getDisplayString", "(Ljava/lang/String;Ljava/lang/String;Ljava/util/Locale;I)Ljava/lang/String;", nullptr, $PRIVATE, $method(Locale, getDisplayString, $String*, $String*, $String*, Locale*, int32_t)},
	{"getDisplayVariant", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $method(Locale, getDisplayVariant, $String*)},
	{"getDisplayVariant", "(Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $method(Locale, getDisplayVariant, $String*, Locale*)},
	{"getDisplayVariantArray", "(Ljava/util/Locale;)[Ljava/lang/String;", nullptr, $PRIVATE, $method(Locale, getDisplayVariantArray, $StringArray*, Locale*)},
	{"getExtension", "(C)Ljava/lang/String;", nullptr, $PUBLIC, $method(Locale, getExtension, $String*, char16_t)},
	{"getExtensionKeys", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/Character;>;", $PUBLIC, $method(Locale, getExtensionKeys, $Set*)},
	{"getFormatLocale", "()Ljava/util/Locale;", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $staticMethod(Locale, getFormatLocale, Locale*)},
	{"getISO2Table", "(Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Locale, getISO2Table, $StringArray*, $String*)},
	{"getISO3Code", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Locale, getISO3Code, $String*, $String*, $String*)},
	{"getISO3Country", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(Locale, getISO3Country, $String*), "java.util.MissingResourceException"},
	{"getISO3Language", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(Locale, getISO3Language, $String*), "java.util.MissingResourceException"},
	{"getISOCountries", "()[Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Locale, getISOCountries, $StringArray*)},
	{"getISOCountries", "(Ljava/util/Locale$IsoCountryCode;)Ljava/util/Set;", "(Ljava/util/Locale$IsoCountryCode;)Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(Locale, getISOCountries, $Set*, $Locale$IsoCountryCode*)},
	{"getISOLanguages", "()[Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Locale, getISOLanguages, $StringArray*)},
	{"getInstance", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/util/Locale;", nullptr, $STATIC, $staticMethod(Locale, getInstance, Locale*, $String*, $String*, $String*)},
	{"getInstance", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Lsun/util/locale/LocaleExtensions;)Ljava/util/Locale;", nullptr, $STATIC, $staticMethod(Locale, getInstance, Locale*, $String*, $String*, $String*, $String*, $LocaleExtensions*)},
	{"getInstance", "(Lsun/util/locale/BaseLocale;Lsun/util/locale/LocaleExtensions;)Ljava/util/Locale;", nullptr, $STATIC, $staticMethod(Locale, getInstance, Locale*, $BaseLocale*, $LocaleExtensions*)},
	{"getLanguage", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(Locale, getLanguage, $String*)},
	{"getLocaleExtensions", "()Lsun/util/locale/LocaleExtensions;", nullptr, 0, $method(Locale, getLocaleExtensions, $LocaleExtensions*)},
	{"getScript", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(Locale, getScript, $String*)},
	{"getUnicodeLocaleAttributes", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $method(Locale, getUnicodeLocaleAttributes, $Set*)},
	{"getUnicodeLocaleKeys", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $method(Locale, getUnicodeLocaleKeys, $Set*)},
	{"getUnicodeLocaleType", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $method(Locale, getUnicodeLocaleType, $String*, $String*)},
	{"getVariant", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(Locale, getVariant, $String*)},
	{"hasExtensions", "()Z", nullptr, $PUBLIC, $method(Locale, hasExtensions, bool)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(Locale, hashCode, int32_t)},
	{"initDefault", "()Ljava/util/Locale;", nullptr, $PRIVATE | $STATIC, $staticMethod(Locale, initDefault, Locale*)},
	{"initDefault", "(Ljava/util/Locale$Category;)Ljava/util/Locale;", nullptr, $PRIVATE | $STATIC, $staticMethod(Locale, initDefault, Locale*, $Locale$Category*)},
	{"isUnicodeExtensionKey", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(Locale, isUnicodeExtensionKey, bool, $String*)},
	{"lambda$formatList$3", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Locale, lambda$formatList$3, $String*, $String*, $String*, $String*)},
	{"lambda$getDisplayKeyTypeExtensionString$2", "(Ljava/util/Locale;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Locale, lambda$getDisplayKeyTypeExtensionString$2, $String*, Locale*, $String*)},
	{"lambda$getDisplayName$0", "(Ljava/util/Locale;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $SYNTHETIC, $method(Locale, lambda$getDisplayName$0, $String*, Locale*, $String*)},
	{"lambda$getDisplayName$1", "(Lsun/util/locale/provider/LocaleResources;Ljava/util/Locale;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $SYNTHETIC, $method(Locale, lambda$getDisplayName$1, $String*, $LocaleResources*, Locale*, $String*)},
	{"lookup", "(Ljava/util/List;Ljava/util/Collection;)Ljava/util/Locale;", "(Ljava/util/List<Ljava/util/Locale$LanguageRange;>;Ljava/util/Collection<Ljava/util/Locale;>;)Ljava/util/Locale;", $PUBLIC | $STATIC, $staticMethod(Locale, lookup, Locale*, $List*, $Collection*)},
	{"lookupTag", "(Ljava/util/List;Ljava/util/Collection;)Ljava/lang/String;", "(Ljava/util/List<Ljava/util/Locale$LanguageRange;>;Ljava/util/Collection<Ljava/lang/String;>;)Ljava/lang/String;", $PUBLIC | $STATIC, $staticMethod(Locale, lookupTag, $String*, $List*, $Collection*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(Locale, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"readResolve", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(Locale, readResolve, $Object*), "java.io.ObjectStreamException"},
	{"setDefault", "(Ljava/util/Locale;)V", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $staticMethod(Locale, setDefault, void, Locale*)},
	{"setDefault", "(Ljava/util/Locale$Category;Ljava/util/Locale;)V", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $staticMethod(Locale, setDefault, void, $Locale$Category*, Locale*)},
	{"stripExtensions", "()Ljava/util/Locale;", nullptr, $PUBLIC, $method(Locale, stripExtensions, Locale*)},
	{"toLanguageTag", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(Locale, toLanguageTag, $String*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $virtualMethod(Locale, toString, $String*)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(Locale, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _Locale_InnerClassesInfo_[] = {
	{"java.util.Locale$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"java.util.Locale$LanguageRange", "java.util.Locale", "LanguageRange", $PUBLIC | $STATIC | $FINAL},
	{"java.util.Locale$FilteringMode", "java.util.Locale", "FilteringMode", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{"java.util.Locale$Builder", "java.util.Locale", "Builder", $PUBLIC | $STATIC | $FINAL},
	{"java.util.Locale$Category", "java.util.Locale", "Category", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{"java.util.Locale$LocaleNameGetter", "java.util.Locale", "LocaleNameGetter", $PRIVATE | $STATIC},
	{"java.util.Locale$LocaleKey", "java.util.Locale", "LocaleKey", $PRIVATE | $STATIC | $FINAL},
	{"java.util.Locale$Cache", "java.util.Locale", "Cache", $PRIVATE | $STATIC},
	{"java.util.Locale$IsoCountryCode", "java.util.Locale", "IsoCountryCode", $PUBLIC | $STATIC | $ABSTRACT | $ENUM},
	{}
};

$ClassInfo _Locale_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.util.Locale",
	"java.lang.Object",
	"java.lang.Cloneable,java.io.Serializable",
	_Locale_FieldInfo_,
	_Locale_MethodInfo_,
	nullptr,
	nullptr,
	_Locale_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.Locale$1,java.util.Locale$LanguageRange,java.util.Locale$FilteringMode,java.util.Locale$Builder,java.util.Locale$Category,java.util.Locale$LocaleNameGetter,java.util.Locale$LocaleKey,java.util.Locale$Cache,java.util.Locale$IsoCountryCode,java.util.Locale$IsoCountryCode$3,java.util.Locale$IsoCountryCode$2,java.util.Locale$IsoCountryCode$1"
};

$Object* allocate$Locale($Class* clazz) {
	return $of($alloc(Locale));
}

void Locale::finalize() {
	this->$Cloneable::finalize();
}

bool Locale::$assertionsDisabled = false;
Locale* Locale::ENGLISH = nullptr;
Locale* Locale::FRENCH = nullptr;
Locale* Locale::GERMAN = nullptr;
Locale* Locale::ITALIAN = nullptr;
Locale* Locale::JAPANESE = nullptr;
Locale* Locale::KOREAN = nullptr;
Locale* Locale::CHINESE = nullptr;
Locale* Locale::SIMPLIFIED_CHINESE = nullptr;
Locale* Locale::TRADITIONAL_CHINESE = nullptr;
Locale* Locale::FRANCE = nullptr;
Locale* Locale::GERMANY = nullptr;
Locale* Locale::ITALY = nullptr;
Locale* Locale::JAPAN = nullptr;
Locale* Locale::KOREA = nullptr;
Locale* Locale::UK = nullptr;
Locale* Locale::US = nullptr;
Locale* Locale::CANADA = nullptr;
Locale* Locale::CANADA_FRENCH = nullptr;
Locale* Locale::ROOT = nullptr;
$Map* Locale::CONSTANT_LOCALES = nullptr;
Locale* Locale::CHINA = nullptr;
Locale* Locale::PRC = nullptr;
Locale* Locale::TAIWAN = nullptr;
$volatile(Locale*) Locale::defaultLocale = nullptr;
$volatile(Locale*) Locale::defaultDisplayLocale = nullptr;
$volatile(Locale*) Locale::defaultFormatLocale = nullptr;
$ObjectStreamFieldArray* Locale::serialPersistentFields = nullptr;
$volatile($StringArray*) Locale::isoLanguages = nullptr;
$volatile($StringArray*) Locale::isoCountries = nullptr;

Locale* Locale::createConstant(int8_t baseType) {
	$init(Locale);
	$useLocalCurrentObjectStackCache();
	$init($BaseLocale);
	$var($BaseLocale, base, $nc($BaseLocale::constantBaseLocales)->get(baseType));
	$var(Locale, locale, $new(Locale, base, ($LocaleExtensions*)nullptr));
	$nc(Locale::CONSTANT_LOCALES)->put(base, locale);
	return locale;
}

void Locale::init$($BaseLocale* baseLocale, $LocaleExtensions* extensions) {
	$set(this, baseLocale, baseLocale);
	$set(this, localeExtensions, extensions);
}

void Locale::init$($String* language, $String* country, $String* variant) {
	if (language == nullptr || country == nullptr || variant == nullptr) {
		$throwNew($NullPointerException);
	}
	$set(this, baseLocale, $BaseLocale::getInstance($(convertOldISOCodes(language)), ""_s, country, variant));
	$set(this, localeExtensions, getCompatibilityExtensions(language, ""_s, country, variant));
}

void Locale::init$($String* language, $String* country) {
	Locale::init$(language, country, ""_s);
}

void Locale::init$($String* language) {
	Locale::init$(language, ""_s, ""_s);
}

Locale* Locale::getInstance($String* language, $String* country, $String* variant) {
	$init(Locale);
	return getInstance(language, ""_s, country, variant, nullptr);
}

Locale* Locale::getInstance($String* language, $String* script, $String* country, $String* variant, $LocaleExtensions* extensions$renamed) {
	$init(Locale);
	$useLocalCurrentObjectStackCache();
	$var($LocaleExtensions, extensions, extensions$renamed);
	if (language == nullptr || script == nullptr || country == nullptr || variant == nullptr) {
		$throwNew($NullPointerException);
	}
	if (extensions == nullptr) {
		$assign(extensions, getCompatibilityExtensions(language, script, country, variant));
	}
	$var($BaseLocale, baseloc, $BaseLocale::getInstance($(convertOldISOCodes(language)), script, country, variant));
	return getInstance(baseloc, extensions);
}

Locale* Locale::getInstance($BaseLocale* baseloc, $LocaleExtensions* extensions) {
	$init(Locale);
	$useLocalCurrentObjectStackCache();
	if (extensions == nullptr) {
		$var(Locale, locale, $cast(Locale, $nc(Locale::CONSTANT_LOCALES)->get(baseloc)));
		if (locale != nullptr) {
			return locale;
		}
		$init($Locale$Cache);
		return $cast(Locale, $nc($Locale$Cache::LOCALECACHE)->get(baseloc));
	} else {
		$var($Locale$LocaleKey, key, $new($Locale$LocaleKey, baseloc, extensions));
		$init($Locale$Cache);
		return $cast(Locale, $nc($Locale$Cache::LOCALECACHE)->get(key));
	}
}

Locale* Locale::getDefault() {
	$init(Locale);
	return Locale::defaultLocale;
}

Locale* Locale::getDefault($Locale$Category* category) {
	$init(Locale);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(category);
	$init($Locale$Category);
	if (category == $Locale$Category::DISPLAY) {
		$var(Locale, loc, Locale::defaultDisplayLocale);
		if (loc == nullptr) {
			$assign(loc, getDisplayLocale());
		}
		return loc;
	} else {
		if (!Locale::$assertionsDisabled && !(category == $Locale$Category::FORMAT)) {
			$throwNew($AssertionError, $of("Unknown category"_s));
		}
		$var(Locale, loc, Locale::defaultFormatLocale);
		if (loc == nullptr) {
			$assign(loc, getFormatLocale());
		}
		return loc;
	}
}

Locale* Locale::getDisplayLocale() {
	$load(Locale);
	$synchronized(class$) {
		$init(Locale);
		$var(Locale, loc, Locale::defaultDisplayLocale);
		if (loc == nullptr) {
			$init($Locale$Category);
			$assign(loc, ($assignStatic(Locale::defaultDisplayLocale, initDefault($Locale$Category::DISPLAY))));
		}
		return loc;
	}
}

Locale* Locale::getFormatLocale() {
	$load(Locale);
	$synchronized(class$) {
		$init(Locale);
		$var(Locale, loc, Locale::defaultFormatLocale);
		if (loc == nullptr) {
			$init($Locale$Category);
			$assign(loc, ($assignStatic(Locale::defaultFormatLocale, initDefault($Locale$Category::FORMAT))));
		}
		return loc;
	}
}

Locale* Locale::initDefault() {
	$init(Locale);
	$useLocalCurrentObjectStackCache();
	$var($String, language, nullptr);
	$var($String, region, nullptr);
	$var($String, script, nullptr);
	$var($String, country, nullptr);
	$var($String, variant, nullptr);
	$var($Properties, props, $GetPropertyAction::privilegedGetProperties());
	$assign(language, $nc(props)->getProperty("user.language"_s, "en"_s));
	$assign(region, props->getProperty("user.region"_s));
	if (region != nullptr) {
		int32_t i = region->indexOf((int32_t)u'_');
		if (i >= 0) {
			$assign(country, region->substring(0, i));
			$assign(variant, region->substring(i + 1));
		} else {
			$assign(country, region);
			$assign(variant, ""_s);
		}
		$assign(script, ""_s);
	} else {
		$assign(script, props->getProperty("user.script"_s, ""_s));
		$assign(country, props->getProperty("user.country"_s, ""_s));
		$assign(variant, props->getProperty("user.variant"_s, ""_s));
	}
	return getInstance(language, script, country, variant, $cast($LocaleExtensions, $($nc($(getDefaultExtensions($(props->getProperty("user.extensions"_s, ""_s)))))->orElse(nullptr))));
}

Locale* Locale::initDefault($Locale$Category* category) {
	$init(Locale);
	$useLocalCurrentObjectStackCache();
	$var($Properties, props, $GetPropertyAction::privilegedGetProperties());
	$var($String, var$0, $nc(props)->getProperty($nc(category)->languageKey, $($nc(Locale::defaultLocale)->getLanguage())));
	$var($String, var$1, props->getProperty($nc(category)->scriptKey, $($nc(Locale::defaultLocale)->getScript())));
	$var($String, var$2, props->getProperty($nc(category)->countryKey, $($nc(Locale::defaultLocale)->getCountry())));
	$var($String, var$3, props->getProperty($nc(category)->variantKey, $($nc(Locale::defaultLocale)->getVariant())));
	return getInstance(var$0, var$1, var$2, var$3, $cast($LocaleExtensions, $($nc($(getDefaultExtensions($(props->getProperty($nc(category)->extensionsKey, ""_s)))))->orElse($($nc(Locale::defaultLocale)->getLocaleExtensions())))));
}

$Optional* Locale::getDefaultExtensions($String* extensionsProp) {
	$init(Locale);
	$useLocalCurrentObjectStackCache();
	if ($LocaleUtils::isEmpty(extensionsProp)) {
		return $Optional::empty();
	}
	$var($LocaleExtensions, exts, nullptr);
	try {
		$assign(exts, $nc($($$new($InternalLocaleBuilder)->setExtensions(extensionsProp)))->getLocaleExtensions());
	} catch ($LocaleSyntaxException& e) {
	}
	return $Optional::ofNullable(exts);
}

void Locale::setDefault(Locale* newLocale) {
	$load(Locale);
	$synchronized(class$) {
		$init(Locale);
		$init($Locale$Category);
		setDefault($Locale$Category::DISPLAY, newLocale);
		setDefault($Locale$Category::FORMAT, newLocale);
		$assignStatic(Locale::defaultLocale, newLocale);
	}
}

void Locale::setDefault($Locale$Category* category, Locale* newLocale) {
	$load(Locale);
	$synchronized(class$) {
		$init(Locale);
		$useLocalCurrentObjectStackCache();
		if (category == nullptr) {
			$throwNew($NullPointerException, "Category cannot be NULL"_s);
		}
		if (newLocale == nullptr) {
			$throwNew($NullPointerException, "Can\'t set default locale to NULL"_s);
		}
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			sm->checkPermission($$new($PropertyPermission, "user.language"_s, "write"_s));
		}
		$init($Locale$1);
		switch ($nc($Locale$1::$SwitchMap$java$util$Locale$Category)->get($nc((category))->ordinal())) {
		case 1:
			{
				$assignStatic(Locale::defaultDisplayLocale, newLocale);
				break;
			}
		case 2:
			{
				$assignStatic(Locale::defaultFormatLocale, newLocale);
				break;
			}
		default:
			{
				if (!Locale::$assertionsDisabled) {
					$throwNew($AssertionError, $of("Unknown Category"_s));
				}
			}
		}
	}
}

$LocaleArray* Locale::getAvailableLocales() {
	$init(Locale);
	return $LocaleServiceProviderPool::getAllAvailableLocales();
}

$StringArray* Locale::getISOCountries() {
	$init(Locale);
	if (Locale::isoCountries == nullptr) {
		$init($LocaleISOData);
		$assignStatic(Locale::isoCountries, getISO2Table($LocaleISOData::isoCountryTable));
	}
	$var($StringArray, result, $new($StringArray, $nc(Locale::isoCountries)->length));
	$System::arraycopy(Locale::isoCountries, 0, result, 0, $nc(Locale::isoCountries)->length);
	return result;
}

$Set* Locale::getISOCountries($Locale$IsoCountryCode* type) {
	$init(Locale);
	$Objects::requireNonNull(type);
	return $Locale$IsoCountryCode::retrieveISOCountryCodes(type);
}

$StringArray* Locale::getISOLanguages() {
	$init(Locale);
	if (Locale::isoLanguages == nullptr) {
		$init($LocaleISOData);
		$assignStatic(Locale::isoLanguages, getISO2Table($LocaleISOData::isoLanguageTable));
	}
	$var($StringArray, result, $new($StringArray, $nc(Locale::isoLanguages)->length));
	$System::arraycopy(Locale::isoLanguages, 0, result, 0, $nc(Locale::isoLanguages)->length);
	return result;
}

$StringArray* Locale::getISO2Table($String* table) {
	$init(Locale);
	$useLocalCurrentObjectStackCache();
	int32_t len = $nc(table)->length() / 5;
	$var($StringArray, isoTable, $new($StringArray, len));
	{
		int32_t i = 0;
		int32_t j = 0;
		for (; i < len; ++i, j += 5) {
			isoTable->set(i, $(table->substring(j, j + 2)));
		}
	}
	return isoTable;
}

$String* Locale::getLanguage() {
	return $nc(this->baseLocale)->getLanguage();
}

$String* Locale::getScript() {
	return $nc(this->baseLocale)->getScript();
}

$String* Locale::getCountry() {
	return $nc(this->baseLocale)->getRegion();
}

$String* Locale::getVariant() {
	return $nc(this->baseLocale)->getVariant();
}

bool Locale::hasExtensions() {
	return this->localeExtensions != nullptr;
}

Locale* Locale::stripExtensions() {
	return hasExtensions() ? Locale::getInstance(this->baseLocale, nullptr) : this;
}

$String* Locale::getExtension(char16_t key) {
	$useLocalCurrentObjectStackCache();
	if (!$LocaleExtensions::isValidKey(key)) {
		$throwNew($IllegalArgumentException, $$str({"Ill-formed extension key: "_s, $$str(key)}));
	}
	return hasExtensions() ? $nc(this->localeExtensions)->getExtensionValue($($Character::valueOf(key))) : ($String*)nullptr;
}

$Set* Locale::getExtensionKeys() {
	if (!hasExtensions()) {
		return $Collections::emptySet();
	}
	return $nc(this->localeExtensions)->getKeys();
}

$Set* Locale::getUnicodeLocaleAttributes() {
	if (!hasExtensions()) {
		return $Collections::emptySet();
	}
	return $nc(this->localeExtensions)->getUnicodeLocaleAttributes();
}

$String* Locale::getUnicodeLocaleType($String* key) {
	if (!isUnicodeExtensionKey(key)) {
		$throwNew($IllegalArgumentException, $$str({"Ill-formed Unicode locale key: "_s, key}));
	}
	return hasExtensions() ? $nc(this->localeExtensions)->getUnicodeLocaleType(key) : ($String*)nullptr;
}

$Set* Locale::getUnicodeLocaleKeys() {
	if (this->localeExtensions == nullptr) {
		return $Collections::emptySet();
	}
	return $nc(this->localeExtensions)->getUnicodeLocaleKeys();
}

$BaseLocale* Locale::getBaseLocale() {
	return this->baseLocale;
}

$LocaleExtensions* Locale::getLocaleExtensions() {
	return this->localeExtensions;
}

$String* Locale::toString() {
	$useLocalCurrentObjectStackCache();
	bool l = !$nc($($nc(this->baseLocale)->getLanguage()))->isEmpty();
	bool s = !$nc($($nc(this->baseLocale)->getScript()))->isEmpty();
	bool r = !$nc($($nc(this->baseLocale)->getRegion()))->isEmpty();
	bool v = !$nc($($nc(this->baseLocale)->getVariant()))->isEmpty();
	bool e = this->localeExtensions != nullptr && !$nc($($nc(this->localeExtensions)->getID()))->isEmpty();
	$var($StringBuilder, result, $new($StringBuilder, $($nc(this->baseLocale)->getLanguage())));
	if (r || (l && (v || s || e))) {
		result->append(u'_')->append($($nc(this->baseLocale)->getRegion()));
	}
	if (v && (l || r)) {
		result->append(u'_')->append($($nc(this->baseLocale)->getVariant()));
	}
	if (s && (l || r)) {
		result->append("_#"_s)->append($($nc(this->baseLocale)->getScript()));
	}
	if (e && (l || r)) {
		result->append(u'_');
		if (!s) {
			result->append(u'#');
		}
		result->append($($nc(this->localeExtensions)->getID()));
	}
	return result->toString();
}

$String* Locale::toLanguageTag() {
	$useLocalCurrentObjectStackCache();
	if (this->languageTag != nullptr) {
		return this->languageTag;
	}
	$var($LanguageTag, tag, $LanguageTag::parseLocale(this->baseLocale, this->localeExtensions));
	$var($StringBuilder, buf, $new($StringBuilder));
	$var($String, subtag, $nc(tag)->getLanguage());
	if (!$nc(subtag)->isEmpty()) {
		buf->append($($LanguageTag::canonicalizeLanguage(subtag)));
	}
	$assign(subtag, tag->getScript());
	if (!$nc(subtag)->isEmpty()) {
		buf->append($LanguageTag::SEP);
		buf->append($($LanguageTag::canonicalizeScript(subtag)));
	}
	$assign(subtag, tag->getRegion());
	if (!$nc(subtag)->isEmpty()) {
		buf->append($LanguageTag::SEP);
		buf->append($($LanguageTag::canonicalizeRegion(subtag)));
	}
	$var($List, subtags, tag->getVariants());
	{
		$var($Iterator, i$, $nc(subtags)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, s, $cast($String, i$->next()));
			{
				buf->append($LanguageTag::SEP);
				buf->append(s);
			}
		}
	}
	$assign(subtags, tag->getExtensions());
	{
		$var($Iterator, i$, subtags->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, s, $cast($String, i$->next()));
			{
				buf->append($LanguageTag::SEP);
				buf->append($($LanguageTag::canonicalizeExtension(s)));
			}
		}
	}
	$assign(subtag, tag->getPrivateuse());
	if (!$nc(subtag)->isEmpty()) {
		if (buf->length() > 0) {
			buf->append($LanguageTag::SEP);
		}
		buf->append($LanguageTag::PRIVATEUSE)->append($LanguageTag::SEP);
		buf->append(subtag);
	}
	$var($String, langTag, buf->toString());
	$synchronized(this) {
		if (this->languageTag == nullptr) {
			$set(this, languageTag, langTag);
		}
	}
	return this->languageTag;
}

Locale* Locale::forLanguageTag($String* languageTag) {
	$init(Locale);
	$useLocalCurrentObjectStackCache();
	$var($LanguageTag, tag, $LanguageTag::parse(languageTag, nullptr));
	$var($InternalLocaleBuilder, bldr, $new($InternalLocaleBuilder));
	bldr->setLanguageTag(tag);
	$var($BaseLocale, base, bldr->getBaseLocale());
	$var($LocaleExtensions, exts, bldr->getLocaleExtensions());
	if (exts == nullptr && !$nc($($nc(base)->getVariant()))->isEmpty()) {
		$var($String, var$0, base->getLanguage());
		$var($String, var$1, base->getScript());
		$var($String, var$2, base->getRegion());
		$assign(exts, getCompatibilityExtensions(var$0, var$1, var$2, $(base->getVariant())));
	}
	return getInstance(base, exts);
}

$String* Locale::getISO3Language() {
	$useLocalCurrentObjectStackCache();
	$var($String, lang, $nc(this->baseLocale)->getLanguage());
	if ($nc(lang)->length() == 3) {
		return lang;
	}
	$init($LocaleISOData);
	$var($String, language3, getISO3Code(lang, $LocaleISOData::isoLanguageTable));
	if (language3 == nullptr) {
		$throwNew($MissingResourceException, $$str({"Couldn\'t find 3-letter language code for "_s, lang}), $$str({"FormatData_"_s, $(toString())}), "ShortLanguage"_s);
	}
	return language3;
}

$String* Locale::getISO3Country() {
	$useLocalCurrentObjectStackCache();
	$init($LocaleISOData);
	$var($String, country3, getISO3Code($($nc(this->baseLocale)->getRegion()), $LocaleISOData::isoCountryTable));
	if (country3 == nullptr) {
		$var($String, var$0, $str({"Couldn\'t find 3-letter country code for "_s, $($nc(this->baseLocale)->getRegion())}));
		$throwNew($MissingResourceException, var$0, $$str({"FormatData_"_s, $(toString())}), "ShortCountry"_s);
	}
	return country3;
}

$String* Locale::getISO3Code($String* iso2Code, $String* table) {
	$init(Locale);
	int32_t codeLength = $nc(iso2Code)->length();
	if (codeLength == 0) {
		return ""_s;
	}
	int32_t tableLength = $nc(table)->length();
	int32_t index = tableLength;
	if (codeLength == 2) {
		char16_t c1 = iso2Code->charAt(0);
		char16_t c2 = iso2Code->charAt(1);
		for (index = 0; index < tableLength; index += 5) {
			bool var$0 = table->charAt(index) == c1;
			if (var$0 && table->charAt(index + 1) == c2) {
				break;
			}
		}
	}
	return index < tableLength ? table->substring(index + 2, index + 5) : ($String*)nullptr;
}

$String* Locale::getDisplayLanguage() {
	$init($Locale$Category);
	return getDisplayLanguage($(getDefault($Locale$Category::DISPLAY)));
}

$String* Locale::getDisplayLanguage(Locale* inLocale) {
	return getDisplayString($($nc(this->baseLocale)->getLanguage()), nullptr, inLocale, Locale::DISPLAY_LANGUAGE);
}

$String* Locale::getDisplayScript() {
	$init($Locale$Category);
	return getDisplayScript($(getDefault($Locale$Category::DISPLAY)));
}

$String* Locale::getDisplayScript(Locale* inLocale) {
	return getDisplayString($($nc(this->baseLocale)->getScript()), nullptr, inLocale, Locale::DISPLAY_SCRIPT);
}

$String* Locale::getDisplayCountry() {
	$init($Locale$Category);
	return getDisplayCountry($(getDefault($Locale$Category::DISPLAY)));
}

$String* Locale::getDisplayCountry(Locale* inLocale) {
	return getDisplayString($($nc(this->baseLocale)->getRegion()), nullptr, inLocale, Locale::DISPLAY_COUNTRY);
}

$String* Locale::getDisplayString($String* code, $String* cat, Locale* inLocale, int32_t type) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(inLocale);
	$Objects::requireNonNull(code);
	if (code->isEmpty()) {
		return ""_s;
	}
	$load($LocaleNameProvider);
	$var($LocaleServiceProviderPool, pool, $LocaleServiceProviderPool::getPool($LocaleNameProvider::class$));
	$var($String, rbKey, type == Locale::DISPLAY_VARIANT ? $str({"%%"_s, code}) : code);
	$init($Locale$LocaleNameGetter);
	$var($String, result, $cast($String, $nc(pool)->getLocalizedObject($Locale$LocaleNameGetter::INSTANCE, inLocale, rbKey, $$new($ObjectArray, {
		$($of($Integer::valueOf(type))),
		$of(code),
		$of(cat)
	}))));
	return result != nullptr ? result : code;
}

$String* Locale::getDisplayVariant() {
	$init($Locale$Category);
	return getDisplayVariant($(getDefault($Locale$Category::DISPLAY)));
}

$String* Locale::getDisplayVariant(Locale* inLocale) {
	$useLocalCurrentObjectStackCache();
	if ($nc($($nc(this->baseLocale)->getVariant()))->isEmpty()) {
		return ""_s;
	}
	$var($LocaleResources, lr, $nc($($LocaleProviderAdapter::getResourceBundleBased()))->getLocaleResources(inLocale));
	$var($StringArray, names, getDisplayVariantArray(inLocale));
	return formatList(names, $($nc(lr)->getLocaleName("ListCompositionPattern"_s)));
}

$String* Locale::getDisplayName() {
	$init($Locale$Category);
	return getDisplayName($(getDefault($Locale$Category::DISPLAY)));
}

$String* Locale::getDisplayName(Locale* inLocale) {
	$useLocalCurrentObjectStackCache();
	$var($LocaleResources, lr, $nc($($LocaleProviderAdapter::getResourceBundleBased()))->getLocaleResources(inLocale));
	$var($String, languageName, getDisplayLanguage(inLocale));
	$var($String, scriptName, getDisplayScript(inLocale));
	$var($String, countryName, getDisplayCountry(inLocale));
	$var($StringArray, variantNames, getDisplayVariantArray(inLocale));
	$var($String, displayNamePattern, $nc(lr)->getLocaleName("DisplayNamePattern"_s));
	$var($String, listCompositionPattern, lr->getLocaleName("ListCompositionPattern"_s));
	$var($String, mainName, nullptr);
	$var($StringArray, qualifierNames, nullptr);
	bool var$1 = $nc(languageName)->isEmpty();
	bool var$0 = var$1 && $nc(scriptName)->isEmpty();
	if (var$0 && $nc(countryName)->isEmpty()) {
		if ($nc(variantNames)->length == 0) {
			return ""_s;
		} else {
			return formatList(variantNames, listCompositionPattern);
		}
	}
	$var($ArrayList, names, $new($ArrayList, 4));
	if (!$nc(languageName)->isEmpty()) {
		names->add(languageName);
	}
	if (!$nc(scriptName)->isEmpty()) {
		names->add(scriptName);
	}
	if (!$nc(countryName)->isEmpty()) {
		names->add(countryName);
	}
	if ($nc(variantNames)->length != 0) {
		names->addAll($($Arrays::asList(variantNames)));
	}
	if (this->localeExtensions != nullptr) {
		$nc($($nc($($nc($($nc(this->localeExtensions)->getUnicodeLocaleAttributes()))->stream()))->map(static_cast<$Function*>($$new(Locale$$Lambda$lambda$getDisplayName$0, this, inLocale)))))->forEach(static_cast<$Consumer*>($$new(Locale$$Lambda$add$1, static_cast<$ArrayList*>(names))));
		$nc($($nc($($nc($($nc(this->localeExtensions)->getUnicodeLocaleKeys()))->stream()))->map(static_cast<$Function*>($$new(Locale$$Lambda$lambda$getDisplayName$1$2, this, lr, inLocale)))))->forEach(static_cast<$Consumer*>($$new(Locale$$Lambda$add$1, static_cast<$ArrayList*>(names))));
	}
	$assign(mainName, $cast($String, names->get(0)));
	int32_t numNames = names->size();
	$assign(qualifierNames, (numNames > 1) ? $fcast($StringArray, $nc($(names->subList(1, numNames)))->toArray($$new($StringArray, numNames - 1))) : $new($StringArray, 0));
	$var($ObjectArray, displayNames, $new($ObjectArray, {
		$($of($Integer::valueOf($nc(qualifierNames)->length != 0 ? 2 : 1))),
		$of(mainName),
		$nc(qualifierNames)->length != 0 ? $($of(formatList(qualifierNames, listCompositionPattern))) : ($Object*)nullptr
	}));
	if (displayNamePattern != nullptr) {
		return $$new($MessageFormat, displayNamePattern)->format(displayNames);
	} else {
		$var($StringBuilder, result, $new($StringBuilder));
		result->append($cast($String, displayNames->get(1)));
		if (displayNames->length > 2) {
			result->append(" ("_s);
			result->append($cast($String, displayNames->get(2)));
			result->append(u')');
		}
		return result->toString();
	}
}

$Object* Locale::clone() {
	try {
		$var(Locale, that, $cast(Locale, $Cloneable::clone()));
		return $of(that);
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

int32_t Locale::hashCode() {
	int32_t hc = this->hashCodeValue;
	if (hc == 0) {
		hc = $nc(this->baseLocale)->hashCode();
		if (this->localeExtensions != nullptr) {
			hc ^= $nc(this->localeExtensions)->hashCode();
		}
		this->hashCodeValue = hc;
	}
	return hc;
}

bool Locale::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if (!($instanceOf(Locale, obj))) {
		return false;
	}
	$var($BaseLocale, otherBase, $nc(($cast(Locale, obj)))->baseLocale);
	if (!$nc(this->baseLocale)->equals(otherBase)) {
		return false;
	}
	if (this->localeExtensions == nullptr) {
		return ($cast(Locale, obj))->localeExtensions == nullptr;
	}
	return $nc(this->localeExtensions)->equals(($cast(Locale, obj))->localeExtensions);
}

$StringArray* Locale::getDisplayVariantArray(Locale* inLocale) {
	$useLocalCurrentObjectStackCache();
	$var($StringTokenizer, tokenizer, $new($StringTokenizer, $($nc(this->baseLocale)->getVariant()), "_"_s));
	$var($StringArray, names, $new($StringArray, tokenizer->countTokens()));
	for (int32_t i = 0; i < names->length; ++i) {
		names->set(i, $(getDisplayString($(tokenizer->nextToken()), nullptr, inLocale, Locale::DISPLAY_VARIANT)));
	}
	return names;
}

$String* Locale::getDisplayKeyTypeExtensionString($String* key, $LocaleResources* lr, Locale* inLocale) {
	$useLocalCurrentObjectStackCache();
	$var($String, type, $nc(this->localeExtensions)->getUnicodeLocaleType(key));
	$var($String, ret, getDisplayString(type, key, inLocale, Locale::DISPLAY_UEXT_TYPE));
	if (ret == nullptr || $nc(ret)->equals(type)) {
		$var($String, displayType, type);
		{
			$var($String, s90616$, key);
			int32_t tmp90616$ = -1;
			switch ($nc(s90616$)->hashCode()) {
			case 3186:
				{
					if (s90616$->equals("cu"_s)) {
						tmp90616$ = 0;
					}
					break;
				}
			case 3637:
				{
					if (s90616$->equals("rg"_s)) {
						tmp90616$ = 1;
					}
					break;
				}
			case 3718:
				{
					if (s90616$->equals("tz"_s)) {
						tmp90616$ = 2;
					}
					break;
				}
			}
			switch (tmp90616$) {
			case 0:
				{
					$assign(displayType, $nc(lr)->getCurrencyName($($nc(type)->toLowerCase(Locale::ROOT))));
					break;
				}
			case 1:
				{
					if (type != nullptr && type->matches("^[a-zA-Z]{2}[zZ]{4}$"_s)) {
						$assign(displayType, $nc(lr)->getLocaleName($($(type->substring(0, 2))->toUpperCase(Locale::ROOT))));
					}
					break;
				}
			case 2:
				{
					$assign(displayType, $cast($String, $nc($($nc($($TimeZoneNameUtility::convertLDMLShortID(type)))->map(static_cast<$Function*>($$new(Locale$$Lambda$lambda$getDisplayKeyTypeExtensionString$2$3, inLocale)))))->orElse(type)));
					break;
				}
			}
		}
		$var($String, var$0, $nc(lr)->getLocaleName("ListKeyTypePattern"_s));
		$assign(ret, $MessageFormat::format(var$0, $$new($ObjectArray, {
			$($of(getDisplayString(key, nullptr, inLocale, Locale::DISPLAY_UEXT_KEY))),
			$($nc($($Optional::ofNullable(displayType)))->orElse(type))
		})));
	}
	return ret;
}

$String* Locale::formatList($StringArray* stringList, $String* pattern) {
	$init(Locale);
	$useLocalCurrentObjectStackCache();
	if (pattern == nullptr) {
		return $cast($String, $nc($($Arrays::stream(stringList)))->collect($($Collectors::joining(","_s))));
	}

	$var($String, var$0, nullptr)
	switch ($nc(stringList)->length) {
	case 0:
		{
			$assign(var$0, ""_s);
			break;
		}
	case 1:
		{
			$assign(var$0, stringList->get(0));
			break;
		}
	default:
		{
			$assign(var$0, $cast($String, $nc($($Arrays::stream(stringList)))->reduce(""_s, static_cast<$BinaryOperator*>($$new(Locale$$Lambda$lambda$formatList$3$4, pattern)))));
			break;
		}
	}
	return var$0;
}

bool Locale::isUnicodeExtensionKey($String* s) {
	$init(Locale);
	bool var$0 = ($nc(s)->length() == 2);
	return var$0 && $LocaleUtils::isAlphaNumericString(s);
}

void Locale::writeObject($ObjectOutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectOutputStream$PutField, fields, $nc(out)->putFields());
	$nc(fields)->put("language"_s, $($of($nc(this->baseLocale)->getLanguage())));
	fields->put("script"_s, $($of($nc(this->baseLocale)->getScript())));
	fields->put("country"_s, $($of($nc(this->baseLocale)->getRegion())));
	fields->put("variant"_s, $($of($nc(this->baseLocale)->getVariant())));
	fields->put("extensions"_s, this->localeExtensions == nullptr ? $of(""_s) : $($of($nc(this->localeExtensions)->getID())));
	fields->put("hashcode"_s, -1);
	out->writeFields();
}

void Locale::readObject($ObjectInputStream* in) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectInputStream$GetField, fields, $nc(in)->readFields());
	$var($String, language, $cast($String, $nc(fields)->get("language"_s, $of(""_s))));
	$var($String, script, $cast($String, fields->get("script"_s, $of(""_s))));
	$var($String, country, $cast($String, fields->get("country"_s, $of(""_s))));
	$var($String, variant, $cast($String, fields->get("variant"_s, $of(""_s))));
	$var($String, extStr, $cast($String, fields->get("extensions"_s, $of(""_s))));
	$set(this, baseLocale, $BaseLocale::getInstance($(convertOldISOCodes(language)), script, country, variant));
	if (!$nc(extStr)->isEmpty()) {
		try {
			$var($InternalLocaleBuilder, bldr, $new($InternalLocaleBuilder));
			bldr->setExtensions(extStr);
			$set(this, localeExtensions, bldr->getLocaleExtensions());
		} catch ($LocaleSyntaxException& e) {
			$throwNew($IllformedLocaleException, $(e->getMessage()));
		}
	} else {
		$set(this, localeExtensions, nullptr);
	}
}

$Object* Locale::readResolve() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $nc(this->baseLocale)->getLanguage());
	$var($String, var$1, $nc(this->baseLocale)->getScript());
	$var($String, var$2, $nc(this->baseLocale)->getRegion());
	return $of(getInstance(var$0, var$1, var$2, $($nc(this->baseLocale)->getVariant()), this->localeExtensions));
}

$String* Locale::convertOldISOCodes($String* language) {
	$init(Locale);
	$useLocalCurrentObjectStackCache();
	return $BaseLocale::convertOldISOCodes($($nc($($LocaleUtils::toLowerString(language)))->intern()));
}

$LocaleExtensions* Locale::getCompatibilityExtensions($String* language, $String* script, $String* country, $String* variant) {
	$init(Locale);
	$var($LocaleExtensions, extensions, nullptr);
	bool var$2 = $LocaleUtils::caseIgnoreMatch(language, "ja"_s);
	bool var$1 = var$2 && $nc(script)->isEmpty();
	bool var$0 = var$1 && $LocaleUtils::caseIgnoreMatch(country, "jp"_s);
	if (var$0 && "JP"_s->equals(variant)) {
		$init($LocaleExtensions);
		$assign(extensions, $LocaleExtensions::CALENDAR_JAPANESE);
	} else {
		bool var$8 = $LocaleUtils::caseIgnoreMatch(language, "th"_s);
		bool var$7 = var$8 && script->isEmpty();
		bool var$6 = var$7 && $LocaleUtils::caseIgnoreMatch(country, "th"_s);
		if (var$6 && "TH"_s->equals(variant)) {
			$init($LocaleExtensions);
			$assign(extensions, $LocaleExtensions::NUMBER_THAI);
		}
	}
	return extensions;
}

$List* Locale::filter($List* priorityList, $Collection* locales, $Locale$FilteringMode* mode) {
	$init(Locale);
	return $LocaleMatcher::filter(priorityList, locales, mode);
}

$List* Locale::filter($List* priorityList, $Collection* locales) {
	$init(Locale);
	$init($Locale$FilteringMode);
	return filter(priorityList, locales, $Locale$FilteringMode::AUTOSELECT_FILTERING);
}

$List* Locale::filterTags($List* priorityList, $Collection* tags, $Locale$FilteringMode* mode) {
	$init(Locale);
	return $LocaleMatcher::filterTags(priorityList, tags, mode);
}

$List* Locale::filterTags($List* priorityList, $Collection* tags) {
	$init(Locale);
	$init($Locale$FilteringMode);
	return filterTags(priorityList, tags, $Locale$FilteringMode::AUTOSELECT_FILTERING);
}

Locale* Locale::lookup($List* priorityList, $Collection* locales) {
	$init(Locale);
	return $LocaleMatcher::lookup(priorityList, locales);
}

$String* Locale::lookupTag($List* priorityList, $Collection* tags) {
	$init(Locale);
	return $LocaleMatcher::lookupTag(priorityList, tags);
}

$String* Locale::lambda$formatList$3($String* pattern, $String* s1, $String* s2) {
	$init(Locale);
	if ($nc(s1)->isEmpty()) {
		return s2;
	}
	if ($nc(s2)->isEmpty()) {
		return s1;
	}
	return $MessageFormat::format(pattern, $$new($ObjectArray, {
		$of(s1),
		$of(s2)
	}));
}

$String* Locale::lambda$getDisplayKeyTypeExtensionString$2(Locale* inLocale, $String* id) {
	$init(Locale);
	return $TimeZoneNameUtility::retrieveGenericDisplayName(id, $TimeZone::LONG, inLocale);
}

$String* Locale::lambda$getDisplayName$1($LocaleResources* lr, Locale* inLocale, $String* key) {
	return getDisplayKeyTypeExtensionString(key, lr, inLocale);
}

$String* Locale::lambda$getDisplayName$0(Locale* inLocale, $String* key) {
	return getDisplayString(key, nullptr, inLocale, Locale::DISPLAY_UEXT_KEY);
}

void clinit$Locale($Class* class$) {
	$useLocalCurrentObjectStackCache();
	Locale::$assertionsDisabled = !Locale::class$->desiredAssertionStatus();
	$assignStatic(Locale::CONSTANT_LOCALES, $new($HashMap));
	{
		$assignStatic(Locale::ENGLISH, Locale::createConstant($BaseLocale::ENGLISH));
		$assignStatic(Locale::FRENCH, Locale::createConstant($BaseLocale::FRENCH));
		$assignStatic(Locale::GERMAN, Locale::createConstant($BaseLocale::GERMAN));
		$assignStatic(Locale::ITALIAN, Locale::createConstant($BaseLocale::ITALIAN));
		$assignStatic(Locale::JAPANESE, Locale::createConstant($BaseLocale::JAPANESE));
		$assignStatic(Locale::KOREAN, Locale::createConstant($BaseLocale::KOREAN));
		$assignStatic(Locale::CHINESE, Locale::createConstant($BaseLocale::CHINESE));
		$assignStatic(Locale::SIMPLIFIED_CHINESE, Locale::createConstant($BaseLocale::SIMPLIFIED_CHINESE));
		$assignStatic(Locale::TRADITIONAL_CHINESE, Locale::createConstant($BaseLocale::TRADITIONAL_CHINESE));
		$assignStatic(Locale::FRANCE, Locale::createConstant($BaseLocale::FRANCE));
		$assignStatic(Locale::GERMANY, Locale::createConstant($BaseLocale::GERMANY));
		$assignStatic(Locale::ITALY, Locale::createConstant($BaseLocale::ITALY));
		$assignStatic(Locale::JAPAN, Locale::createConstant($BaseLocale::JAPAN));
		$assignStatic(Locale::KOREA, Locale::createConstant($BaseLocale::KOREA));
		$assignStatic(Locale::UK, Locale::createConstant($BaseLocale::UK));
		$assignStatic(Locale::US, Locale::createConstant($BaseLocale::US));
		$assignStatic(Locale::CANADA, Locale::createConstant($BaseLocale::CANADA));
		$assignStatic(Locale::CANADA_FRENCH, Locale::createConstant($BaseLocale::CANADA_FRENCH));
		$assignStatic(Locale::ROOT, Locale::createConstant($BaseLocale::ROOT));
	}
	$assignStatic(Locale::CHINA, Locale::SIMPLIFIED_CHINESE);
	$assignStatic(Locale::PRC, Locale::SIMPLIFIED_CHINESE);
	$assignStatic(Locale::TAIWAN, Locale::TRADITIONAL_CHINESE);
	$assignStatic(Locale::defaultLocale, Locale::initDefault());
	$init($Integer);
	$assignStatic(Locale::serialPersistentFields, $new($ObjectStreamFieldArray, {
		$$new($ObjectStreamField, "language"_s, $String::class$),
		$$new($ObjectStreamField, "country"_s, $String::class$),
		$$new($ObjectStreamField, "variant"_s, $String::class$),
		$$new($ObjectStreamField, "hashcode"_s, $Integer::TYPE),
		$$new($ObjectStreamField, "script"_s, $String::class$),
		$$new($ObjectStreamField, "extensions"_s, $String::class$)
	}));
}

Locale::Locale() {
}

$Class* Locale::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Locale$$Lambda$lambda$getDisplayName$0::classInfo$.name)) {
			return Locale$$Lambda$lambda$getDisplayName$0::load$(name, initialize);
		}
		if (name->equals(Locale$$Lambda$add$1::classInfo$.name)) {
			return Locale$$Lambda$add$1::load$(name, initialize);
		}
		if (name->equals(Locale$$Lambda$lambda$getDisplayName$1$2::classInfo$.name)) {
			return Locale$$Lambda$lambda$getDisplayName$1$2::load$(name, initialize);
		}
		if (name->equals(Locale$$Lambda$lambda$getDisplayKeyTypeExtensionString$2$3::classInfo$.name)) {
			return Locale$$Lambda$lambda$getDisplayKeyTypeExtensionString$2$3::load$(name, initialize);
		}
		if (name->equals(Locale$$Lambda$lambda$formatList$3$4::classInfo$.name)) {
			return Locale$$Lambda$lambda$formatList$3$4::load$(name, initialize);
		}
	}
	$loadClass(Locale, name, initialize, &_Locale_ClassInfo_, clinit$Locale, allocate$Locale);
	return class$;
}

$Class* Locale::class$ = nullptr;

	} // util
} // java