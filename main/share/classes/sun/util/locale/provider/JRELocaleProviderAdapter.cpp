#include <sun/util/locale/provider/JRELocaleProviderAdapter.h>

#include <java/io/Serializable.h>
#include <java/lang/InternalError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/text/spi/BreakIteratorProvider.h>
#include <java/text/spi/CollatorProvider.h>
#include <java/text/spi/DateFormatProvider.h>
#include <java/text/spi/DateFormatSymbolsProvider.h>
#include <java/text/spi/DecimalFormatSymbolsProvider.h>
#include <java/text/spi/NumberFormatProvider.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/ResourceBundle$Control.h>
#include <java/util/ServiceLoader.h>
#include <java/util/Set.h>
#include <java/util/StringTokenizer.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <java/util/spi/CalendarDataProvider.h>
#include <java/util/spi/CalendarNameProvider.h>
#include <java/util/spi/CurrencyNameProvider.h>
#include <java/util/spi/LocaleNameProvider.h>
#include <java/util/spi/LocaleServiceProvider.h>
#include <java/util/spi/TimeZoneNameProvider.h>
#include <sun/text/spi/JavaTimeDateTimePatternProvider.h>
#include <sun/util/locale/provider/BaseLocaleDataMetaInfo.h>
#include <sun/util/locale/provider/BreakIteratorProviderImpl.h>
#include <sun/util/locale/provider/CalendarDataProviderImpl.h>
#include <sun/util/locale/provider/CalendarNameProviderImpl.h>
#include <sun/util/locale/provider/CalendarProviderImpl.h>
#include <sun/util/locale/provider/CollatorProviderImpl.h>
#include <sun/util/locale/provider/CurrencyNameProviderImpl.h>
#include <sun/util/locale/provider/DateFormatProviderImpl.h>
#include <sun/util/locale/provider/DateFormatSymbolsProviderImpl.h>
#include <sun/util/locale/provider/DecimalFormatSymbolsProviderImpl.h>
#include <sun/util/locale/provider/JRELocaleConstants.h>
#include <sun/util/locale/provider/JRELocaleProviderAdapter$AvailableJRELocales.h>
#include <sun/util/locale/provider/JavaTimeDateTimePatternImpl.h>
#include <sun/util/locale/provider/LocaleDataMetaInfo.h>
#include <sun/util/locale/provider/LocaleNameProviderImpl.h>
#include <sun/util/locale/provider/LocaleProviderAdapter$Type.h>
#include <sun/util/locale/provider/LocaleProviderAdapter.h>
#include <sun/util/locale/provider/LocaleResources.h>
#include <sun/util/locale/provider/NumberFormatProviderImpl.h>
#include <sun/util/locale/provider/ResourceBundleBasedAdapter.h>
#include <sun/util/locale/provider/TimeZoneNameProviderImpl.h>
#include <sun/util/resources/LocaleData.h>
#include <sun/util/spi/CalendarProvider.h>
#include <jcpp.h>

#undef FORMAT_DEFAULT
#undef JA_JP_JP
#undef JRE
#undef NO_NO_NY
#undef ROOT
#undef TH_TH_TH

using $LocaleArray = $Array<::java::util::Locale>;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $BreakIteratorProvider = ::java::text::spi::BreakIteratorProvider;
using $CollatorProvider = ::java::text::spi::CollatorProvider;
using $DateFormatProvider = ::java::text::spi::DateFormatProvider;
using $DateFormatSymbolsProvider = ::java::text::spi::DateFormatSymbolsProvider;
using $DecimalFormatSymbolsProvider = ::java::text::spi::DecimalFormatSymbolsProvider;
using $NumberFormatProvider = ::java::text::spi::NumberFormatProvider;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $ResourceBundle$Control = ::java::util::ResourceBundle$Control;
using $ServiceLoader = ::java::util::ServiceLoader;
using $Set = ::java::util::Set;
using $StringTokenizer = ::java::util::StringTokenizer;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $CalendarDataProvider = ::java::util::spi::CalendarDataProvider;
using $CalendarNameProvider = ::java::util::spi::CalendarNameProvider;
using $CurrencyNameProvider = ::java::util::spi::CurrencyNameProvider;
using $LocaleNameProvider = ::java::util::spi::LocaleNameProvider;
using $LocaleServiceProvider = ::java::util::spi::LocaleServiceProvider;
using $TimeZoneNameProvider = ::java::util::spi::TimeZoneNameProvider;
using $JavaTimeDateTimePatternProvider = ::sun::text::spi::JavaTimeDateTimePatternProvider;
using $BaseLocaleDataMetaInfo = ::sun::util::locale::provider::BaseLocaleDataMetaInfo;
using $BreakIteratorProviderImpl = ::sun::util::locale::provider::BreakIteratorProviderImpl;
using $CalendarDataProviderImpl = ::sun::util::locale::provider::CalendarDataProviderImpl;
using $CalendarNameProviderImpl = ::sun::util::locale::provider::CalendarNameProviderImpl;
using $CalendarProviderImpl = ::sun::util::locale::provider::CalendarProviderImpl;
using $CollatorProviderImpl = ::sun::util::locale::provider::CollatorProviderImpl;
using $CurrencyNameProviderImpl = ::sun::util::locale::provider::CurrencyNameProviderImpl;
using $DateFormatProviderImpl = ::sun::util::locale::provider::DateFormatProviderImpl;
using $DateFormatSymbolsProviderImpl = ::sun::util::locale::provider::DateFormatSymbolsProviderImpl;
using $DecimalFormatSymbolsProviderImpl = ::sun::util::locale::provider::DecimalFormatSymbolsProviderImpl;
using $JRELocaleConstants = ::sun::util::locale::provider::JRELocaleConstants;
using $JRELocaleProviderAdapter$AvailableJRELocales = ::sun::util::locale::provider::JRELocaleProviderAdapter$AvailableJRELocales;
using $JavaTimeDateTimePatternImpl = ::sun::util::locale::provider::JavaTimeDateTimePatternImpl;
using $LocaleDataMetaInfo = ::sun::util::locale::provider::LocaleDataMetaInfo;
using $LocaleNameProviderImpl = ::sun::util::locale::provider::LocaleNameProviderImpl;
using $LocaleProviderAdapter = ::sun::util::locale::provider::LocaleProviderAdapter;
using $LocaleProviderAdapter$Type = ::sun::util::locale::provider::LocaleProviderAdapter$Type;
using $LocaleResources = ::sun::util::locale::provider::LocaleResources;
using $NumberFormatProviderImpl = ::sun::util::locale::provider::NumberFormatProviderImpl;
using $ResourceBundleBasedAdapter = ::sun::util::locale::provider::ResourceBundleBasedAdapter;
using $TimeZoneNameProviderImpl = ::sun::util::locale::provider::TimeZoneNameProviderImpl;
using $LocaleData = ::sun::util::resources::LocaleData;
using $CalendarProvider = ::sun::util::spi::CalendarProvider;

namespace sun {
	namespace util {
		namespace locale {
			namespace provider {

class JRELocaleProviderAdapter$$Lambda$lambda$getBreakIteratorProvider$0 : public $PrivilegedAction {
	$class(JRELocaleProviderAdapter$$Lambda$lambda$getBreakIteratorProvider$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(JRELocaleProviderAdapter* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$getBreakIteratorProvider$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<JRELocaleProviderAdapter$$Lambda$lambda$getBreakIteratorProvider$0>());
	}
	JRELocaleProviderAdapter* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo JRELocaleProviderAdapter$$Lambda$lambda$getBreakIteratorProvider$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(JRELocaleProviderAdapter$$Lambda$lambda$getBreakIteratorProvider$0, inst$)},
	{}
};
$MethodInfo JRELocaleProviderAdapter$$Lambda$lambda$getBreakIteratorProvider$0::methodInfos[3] = {
	{"<init>", "(Lsun/util/locale/provider/JRELocaleProviderAdapter;)V", nullptr, $PUBLIC, $method(JRELocaleProviderAdapter$$Lambda$lambda$getBreakIteratorProvider$0, init$, void, JRELocaleProviderAdapter*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter$$Lambda$lambda$getBreakIteratorProvider$0, run, $Object*)},
	{}
};
$ClassInfo JRELocaleProviderAdapter$$Lambda$lambda$getBreakIteratorProvider$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.locale.provider.JRELocaleProviderAdapter$$Lambda$lambda$getBreakIteratorProvider$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getBreakIteratorProvider$0::load$($String* name, bool initialize) {
	$loadClass(JRELocaleProviderAdapter$$Lambda$lambda$getBreakIteratorProvider$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getBreakIteratorProvider$0::class$ = nullptr;

class JRELocaleProviderAdapter$$Lambda$lambda$getCollatorProvider$1$1 : public $PrivilegedAction {
	$class(JRELocaleProviderAdapter$$Lambda$lambda$getCollatorProvider$1$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(JRELocaleProviderAdapter* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$getCollatorProvider$1());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<JRELocaleProviderAdapter$$Lambda$lambda$getCollatorProvider$1$1>());
	}
	JRELocaleProviderAdapter* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo JRELocaleProviderAdapter$$Lambda$lambda$getCollatorProvider$1$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(JRELocaleProviderAdapter$$Lambda$lambda$getCollatorProvider$1$1, inst$)},
	{}
};
$MethodInfo JRELocaleProviderAdapter$$Lambda$lambda$getCollatorProvider$1$1::methodInfos[3] = {
	{"<init>", "(Lsun/util/locale/provider/JRELocaleProviderAdapter;)V", nullptr, $PUBLIC, $method(JRELocaleProviderAdapter$$Lambda$lambda$getCollatorProvider$1$1, init$, void, JRELocaleProviderAdapter*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter$$Lambda$lambda$getCollatorProvider$1$1, run, $Object*)},
	{}
};
$ClassInfo JRELocaleProviderAdapter$$Lambda$lambda$getCollatorProvider$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.locale.provider.JRELocaleProviderAdapter$$Lambda$lambda$getCollatorProvider$1$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getCollatorProvider$1$1::load$($String* name, bool initialize) {
	$loadClass(JRELocaleProviderAdapter$$Lambda$lambda$getCollatorProvider$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getCollatorProvider$1$1::class$ = nullptr;

class JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatProvider$2$2 : public $PrivilegedAction {
	$class(JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatProvider$2$2, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(JRELocaleProviderAdapter* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$getDateFormatProvider$2());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatProvider$2$2>());
	}
	JRELocaleProviderAdapter* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatProvider$2$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatProvider$2$2, inst$)},
	{}
};
$MethodInfo JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatProvider$2$2::methodInfos[3] = {
	{"<init>", "(Lsun/util/locale/provider/JRELocaleProviderAdapter;)V", nullptr, $PUBLIC, $method(JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatProvider$2$2, init$, void, JRELocaleProviderAdapter*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatProvider$2$2, run, $Object*)},
	{}
};
$ClassInfo JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatProvider$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.locale.provider.JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatProvider$2$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatProvider$2$2::load$($String* name, bool initialize) {
	$loadClass(JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatProvider$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatProvider$2$2::class$ = nullptr;

class JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatSymbolsProvider$3$3 : public $PrivilegedAction {
	$class(JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatSymbolsProvider$3$3, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(JRELocaleProviderAdapter* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$getDateFormatSymbolsProvider$3());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatSymbolsProvider$3$3>());
	}
	JRELocaleProviderAdapter* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatSymbolsProvider$3$3::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatSymbolsProvider$3$3, inst$)},
	{}
};
$MethodInfo JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatSymbolsProvider$3$3::methodInfos[3] = {
	{"<init>", "(Lsun/util/locale/provider/JRELocaleProviderAdapter;)V", nullptr, $PUBLIC, $method(JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatSymbolsProvider$3$3, init$, void, JRELocaleProviderAdapter*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatSymbolsProvider$3$3, run, $Object*)},
	{}
};
$ClassInfo JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatSymbolsProvider$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.locale.provider.JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatSymbolsProvider$3$3",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatSymbolsProvider$3$3::load$($String* name, bool initialize) {
	$loadClass(JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatSymbolsProvider$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatSymbolsProvider$3$3::class$ = nullptr;

class JRELocaleProviderAdapter$$Lambda$lambda$getDecimalFormatSymbolsProvider$4$4 : public $PrivilegedAction {
	$class(JRELocaleProviderAdapter$$Lambda$lambda$getDecimalFormatSymbolsProvider$4$4, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(JRELocaleProviderAdapter* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$getDecimalFormatSymbolsProvider$4());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<JRELocaleProviderAdapter$$Lambda$lambda$getDecimalFormatSymbolsProvider$4$4>());
	}
	JRELocaleProviderAdapter* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo JRELocaleProviderAdapter$$Lambda$lambda$getDecimalFormatSymbolsProvider$4$4::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(JRELocaleProviderAdapter$$Lambda$lambda$getDecimalFormatSymbolsProvider$4$4, inst$)},
	{}
};
$MethodInfo JRELocaleProviderAdapter$$Lambda$lambda$getDecimalFormatSymbolsProvider$4$4::methodInfos[3] = {
	{"<init>", "(Lsun/util/locale/provider/JRELocaleProviderAdapter;)V", nullptr, $PUBLIC, $method(JRELocaleProviderAdapter$$Lambda$lambda$getDecimalFormatSymbolsProvider$4$4, init$, void, JRELocaleProviderAdapter*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter$$Lambda$lambda$getDecimalFormatSymbolsProvider$4$4, run, $Object*)},
	{}
};
$ClassInfo JRELocaleProviderAdapter$$Lambda$lambda$getDecimalFormatSymbolsProvider$4$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.locale.provider.JRELocaleProviderAdapter$$Lambda$lambda$getDecimalFormatSymbolsProvider$4$4",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getDecimalFormatSymbolsProvider$4$4::load$($String* name, bool initialize) {
	$loadClass(JRELocaleProviderAdapter$$Lambda$lambda$getDecimalFormatSymbolsProvider$4$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getDecimalFormatSymbolsProvider$4$4::class$ = nullptr;

class JRELocaleProviderAdapter$$Lambda$lambda$getNumberFormatProvider$5$5 : public $PrivilegedAction {
	$class(JRELocaleProviderAdapter$$Lambda$lambda$getNumberFormatProvider$5$5, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(JRELocaleProviderAdapter* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$getNumberFormatProvider$5());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<JRELocaleProviderAdapter$$Lambda$lambda$getNumberFormatProvider$5$5>());
	}
	JRELocaleProviderAdapter* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo JRELocaleProviderAdapter$$Lambda$lambda$getNumberFormatProvider$5$5::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(JRELocaleProviderAdapter$$Lambda$lambda$getNumberFormatProvider$5$5, inst$)},
	{}
};
$MethodInfo JRELocaleProviderAdapter$$Lambda$lambda$getNumberFormatProvider$5$5::methodInfos[3] = {
	{"<init>", "(Lsun/util/locale/provider/JRELocaleProviderAdapter;)V", nullptr, $PUBLIC, $method(JRELocaleProviderAdapter$$Lambda$lambda$getNumberFormatProvider$5$5, init$, void, JRELocaleProviderAdapter*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter$$Lambda$lambda$getNumberFormatProvider$5$5, run, $Object*)},
	{}
};
$ClassInfo JRELocaleProviderAdapter$$Lambda$lambda$getNumberFormatProvider$5$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.locale.provider.JRELocaleProviderAdapter$$Lambda$lambda$getNumberFormatProvider$5$5",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getNumberFormatProvider$5$5::load$($String* name, bool initialize) {
	$loadClass(JRELocaleProviderAdapter$$Lambda$lambda$getNumberFormatProvider$5$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getNumberFormatProvider$5$5::class$ = nullptr;

class JRELocaleProviderAdapter$$Lambda$lambda$getCurrencyNameProvider$6$6 : public $PrivilegedAction {
	$class(JRELocaleProviderAdapter$$Lambda$lambda$getCurrencyNameProvider$6$6, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(JRELocaleProviderAdapter* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$getCurrencyNameProvider$6());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<JRELocaleProviderAdapter$$Lambda$lambda$getCurrencyNameProvider$6$6>());
	}
	JRELocaleProviderAdapter* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo JRELocaleProviderAdapter$$Lambda$lambda$getCurrencyNameProvider$6$6::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(JRELocaleProviderAdapter$$Lambda$lambda$getCurrencyNameProvider$6$6, inst$)},
	{}
};
$MethodInfo JRELocaleProviderAdapter$$Lambda$lambda$getCurrencyNameProvider$6$6::methodInfos[3] = {
	{"<init>", "(Lsun/util/locale/provider/JRELocaleProviderAdapter;)V", nullptr, $PUBLIC, $method(JRELocaleProviderAdapter$$Lambda$lambda$getCurrencyNameProvider$6$6, init$, void, JRELocaleProviderAdapter*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter$$Lambda$lambda$getCurrencyNameProvider$6$6, run, $Object*)},
	{}
};
$ClassInfo JRELocaleProviderAdapter$$Lambda$lambda$getCurrencyNameProvider$6$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.locale.provider.JRELocaleProviderAdapter$$Lambda$lambda$getCurrencyNameProvider$6$6",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getCurrencyNameProvider$6$6::load$($String* name, bool initialize) {
	$loadClass(JRELocaleProviderAdapter$$Lambda$lambda$getCurrencyNameProvider$6$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getCurrencyNameProvider$6$6::class$ = nullptr;

class JRELocaleProviderAdapter$$Lambda$lambda$getLocaleNameProvider$7$7 : public $PrivilegedAction {
	$class(JRELocaleProviderAdapter$$Lambda$lambda$getLocaleNameProvider$7$7, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(JRELocaleProviderAdapter* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$getLocaleNameProvider$7());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<JRELocaleProviderAdapter$$Lambda$lambda$getLocaleNameProvider$7$7>());
	}
	JRELocaleProviderAdapter* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo JRELocaleProviderAdapter$$Lambda$lambda$getLocaleNameProvider$7$7::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(JRELocaleProviderAdapter$$Lambda$lambda$getLocaleNameProvider$7$7, inst$)},
	{}
};
$MethodInfo JRELocaleProviderAdapter$$Lambda$lambda$getLocaleNameProvider$7$7::methodInfos[3] = {
	{"<init>", "(Lsun/util/locale/provider/JRELocaleProviderAdapter;)V", nullptr, $PUBLIC, $method(JRELocaleProviderAdapter$$Lambda$lambda$getLocaleNameProvider$7$7, init$, void, JRELocaleProviderAdapter*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter$$Lambda$lambda$getLocaleNameProvider$7$7, run, $Object*)},
	{}
};
$ClassInfo JRELocaleProviderAdapter$$Lambda$lambda$getLocaleNameProvider$7$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.locale.provider.JRELocaleProviderAdapter$$Lambda$lambda$getLocaleNameProvider$7$7",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getLocaleNameProvider$7$7::load$($String* name, bool initialize) {
	$loadClass(JRELocaleProviderAdapter$$Lambda$lambda$getLocaleNameProvider$7$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getLocaleNameProvider$7$7::class$ = nullptr;

class JRELocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$8$8 : public $PrivilegedAction {
	$class(JRELocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$8$8, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(JRELocaleProviderAdapter* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$getTimeZoneNameProvider$8());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<JRELocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$8$8>());
	}
	JRELocaleProviderAdapter* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo JRELocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$8$8::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(JRELocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$8$8, inst$)},
	{}
};
$MethodInfo JRELocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$8$8::methodInfos[3] = {
	{"<init>", "(Lsun/util/locale/provider/JRELocaleProviderAdapter;)V", nullptr, $PUBLIC, $method(JRELocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$8$8, init$, void, JRELocaleProviderAdapter*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$8$8, run, $Object*)},
	{}
};
$ClassInfo JRELocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$8$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.locale.provider.JRELocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$8$8",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$8$8::load$($String* name, bool initialize) {
	$loadClass(JRELocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$8$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$8$8::class$ = nullptr;

class JRELocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$9$9 : public $PrivilegedAction {
	$class(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$9$9, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(JRELocaleProviderAdapter* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$getCalendarDataProvider$9());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<JRELocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$9$9>());
	}
	JRELocaleProviderAdapter* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo JRELocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$9$9::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$9$9, inst$)},
	{}
};
$MethodInfo JRELocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$9$9::methodInfos[3] = {
	{"<init>", "(Lsun/util/locale/provider/JRELocaleProviderAdapter;)V", nullptr, $PUBLIC, $method(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$9$9, init$, void, JRELocaleProviderAdapter*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$9$9, run, $Object*)},
	{}
};
$ClassInfo JRELocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$9$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.locale.provider.JRELocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$9$9",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$9$9::load$($String* name, bool initialize) {
	$loadClass(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$9$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$9$9::class$ = nullptr;

class JRELocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$10$10 : public $PrivilegedAction {
	$class(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$10$10, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(JRELocaleProviderAdapter* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$getCalendarNameProvider$10());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<JRELocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$10$10>());
	}
	JRELocaleProviderAdapter* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo JRELocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$10$10::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$10$10, inst$)},
	{}
};
$MethodInfo JRELocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$10$10::methodInfos[3] = {
	{"<init>", "(Lsun/util/locale/provider/JRELocaleProviderAdapter;)V", nullptr, $PUBLIC, $method(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$10$10, init$, void, JRELocaleProviderAdapter*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$10$10, run, $Object*)},
	{}
};
$ClassInfo JRELocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$10$10::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.locale.provider.JRELocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$10$10",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$10$10::load$($String* name, bool initialize) {
	$loadClass(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$10$10, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$10$10::class$ = nullptr;

class JRELocaleProviderAdapter$$Lambda$lambda$getCalendarProvider$11$11 : public $PrivilegedAction {
	$class(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarProvider$11$11, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(JRELocaleProviderAdapter* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$getCalendarProvider$11());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<JRELocaleProviderAdapter$$Lambda$lambda$getCalendarProvider$11$11>());
	}
	JRELocaleProviderAdapter* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo JRELocaleProviderAdapter$$Lambda$lambda$getCalendarProvider$11$11::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarProvider$11$11, inst$)},
	{}
};
$MethodInfo JRELocaleProviderAdapter$$Lambda$lambda$getCalendarProvider$11$11::methodInfos[3] = {
	{"<init>", "(Lsun/util/locale/provider/JRELocaleProviderAdapter;)V", nullptr, $PUBLIC, $method(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarProvider$11$11, init$, void, JRELocaleProviderAdapter*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarProvider$11$11, run, $Object*)},
	{}
};
$ClassInfo JRELocaleProviderAdapter$$Lambda$lambda$getCalendarProvider$11$11::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.locale.provider.JRELocaleProviderAdapter$$Lambda$lambda$getCalendarProvider$11$11",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getCalendarProvider$11$11::load$($String* name, bool initialize) {
	$loadClass(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarProvider$11$11, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getCalendarProvider$11$11::class$ = nullptr;

class JRELocaleProviderAdapter$$Lambda$lambda$getJavaTimeDateTimePatternProvider$12$12 : public $PrivilegedAction {
	$class(JRELocaleProviderAdapter$$Lambda$lambda$getJavaTimeDateTimePatternProvider$12$12, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(JRELocaleProviderAdapter* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$getJavaTimeDateTimePatternProvider$12());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<JRELocaleProviderAdapter$$Lambda$lambda$getJavaTimeDateTimePatternProvider$12$12>());
	}
	JRELocaleProviderAdapter* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo JRELocaleProviderAdapter$$Lambda$lambda$getJavaTimeDateTimePatternProvider$12$12::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(JRELocaleProviderAdapter$$Lambda$lambda$getJavaTimeDateTimePatternProvider$12$12, inst$)},
	{}
};
$MethodInfo JRELocaleProviderAdapter$$Lambda$lambda$getJavaTimeDateTimePatternProvider$12$12::methodInfos[3] = {
	{"<init>", "(Lsun/util/locale/provider/JRELocaleProviderAdapter;)V", nullptr, $PUBLIC, $method(JRELocaleProviderAdapter$$Lambda$lambda$getJavaTimeDateTimePatternProvider$12$12, init$, void, JRELocaleProviderAdapter*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter$$Lambda$lambda$getJavaTimeDateTimePatternProvider$12$12, run, $Object*)},
	{}
};
$ClassInfo JRELocaleProviderAdapter$$Lambda$lambda$getJavaTimeDateTimePatternProvider$12$12::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.locale.provider.JRELocaleProviderAdapter$$Lambda$lambda$getJavaTimeDateTimePatternProvider$12$12",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getJavaTimeDateTimePatternProvider$12$12::load$($String* name, bool initialize) {
	$loadClass(JRELocaleProviderAdapter$$Lambda$lambda$getJavaTimeDateTimePatternProvider$12$12, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* JRELocaleProviderAdapter$$Lambda$lambda$getJavaTimeDateTimePatternProvider$12$12::class$ = nullptr;

class JRELocaleProviderAdapter$$Lambda$lambda$createSupportedLocaleString$13$13 : public $PrivilegedExceptionAction {
	$class(JRELocaleProviderAdapter$$Lambda$lambda$createSupportedLocaleString$13$13, $NO_CLASS_INIT, $PrivilegedExceptionAction)
public:
	void init$($String* category) {
		$set(this, category, category);
	}
	virtual $Object* run() override {
		 return $of(JRELocaleProviderAdapter::lambda$createSupportedLocaleString$13(category));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<JRELocaleProviderAdapter$$Lambda$lambda$createSupportedLocaleString$13$13>());
	}
	$String* category = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo JRELocaleProviderAdapter$$Lambda$lambda$createSupportedLocaleString$13$13::fieldInfos[2] = {
	{"category", "Ljava/lang/String;", nullptr, $PUBLIC, $field(JRELocaleProviderAdapter$$Lambda$lambda$createSupportedLocaleString$13$13, category)},
	{}
};
$MethodInfo JRELocaleProviderAdapter$$Lambda$lambda$createSupportedLocaleString$13$13::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(JRELocaleProviderAdapter$$Lambda$lambda$createSupportedLocaleString$13$13, init$, void, $String*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter$$Lambda$lambda$createSupportedLocaleString$13$13, run, $Object*)},
	{}
};
$ClassInfo JRELocaleProviderAdapter$$Lambda$lambda$createSupportedLocaleString$13$13::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.locale.provider.JRELocaleProviderAdapter$$Lambda$lambda$createSupportedLocaleString$13$13",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	fieldInfos,
	methodInfos
};
$Class* JRELocaleProviderAdapter$$Lambda$lambda$createSupportedLocaleString$13$13::load$($String* name, bool initialize) {
	$loadClass(JRELocaleProviderAdapter$$Lambda$lambda$createSupportedLocaleString$13$13, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* JRELocaleProviderAdapter$$Lambda$lambda$createSupportedLocaleString$13$13::class$ = nullptr;

$FieldInfo _JRELocaleProviderAdapter_FieldInfo_[] = {
	{"langtagSets", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/lang/String;Ljava/util/Set<Ljava/lang/String;>;>;", $PRIVATE | $FINAL, $field(JRELocaleProviderAdapter, langtagSets)},
	{"localeResourcesMap", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/util/Locale;Lsun/util/locale/provider/LocaleResources;>;", $PRIVATE | $FINAL, $field(JRELocaleProviderAdapter, localeResourcesMap)},
	{"localeData", "Lsun/util/resources/LocaleData;", nullptr, $PRIVATE | $VOLATILE, $field(JRELocaleProviderAdapter, localeData)},
	{"breakIteratorProvider", "Ljava/text/spi/BreakIteratorProvider;", nullptr, $PRIVATE | $VOLATILE, $field(JRELocaleProviderAdapter, breakIteratorProvider)},
	{"collatorProvider", "Ljava/text/spi/CollatorProvider;", nullptr, $PRIVATE | $VOLATILE, $field(JRELocaleProviderAdapter, collatorProvider)},
	{"dateFormatProvider", "Ljava/text/spi/DateFormatProvider;", nullptr, $PRIVATE | $VOLATILE, $field(JRELocaleProviderAdapter, dateFormatProvider)},
	{"dateFormatSymbolsProvider", "Ljava/text/spi/DateFormatSymbolsProvider;", nullptr, $PRIVATE | $VOLATILE, $field(JRELocaleProviderAdapter, dateFormatSymbolsProvider)},
	{"decimalFormatSymbolsProvider", "Ljava/text/spi/DecimalFormatSymbolsProvider;", nullptr, $PRIVATE | $VOLATILE, $field(JRELocaleProviderAdapter, decimalFormatSymbolsProvider)},
	{"numberFormatProvider", "Ljava/text/spi/NumberFormatProvider;", nullptr, $PRIVATE | $VOLATILE, $field(JRELocaleProviderAdapter, numberFormatProvider)},
	{"currencyNameProvider", "Ljava/util/spi/CurrencyNameProvider;", nullptr, $PRIVATE | $VOLATILE, $field(JRELocaleProviderAdapter, currencyNameProvider)},
	{"localeNameProvider", "Ljava/util/spi/LocaleNameProvider;", nullptr, $PRIVATE | $VOLATILE, $field(JRELocaleProviderAdapter, localeNameProvider)},
	{"timeZoneNameProvider", "Ljava/util/spi/TimeZoneNameProvider;", nullptr, $PROTECTED | $VOLATILE, $field(JRELocaleProviderAdapter, timeZoneNameProvider)},
	{"calendarDataProvider", "Ljava/util/spi/CalendarDataProvider;", nullptr, $PROTECTED | $VOLATILE, $field(JRELocaleProviderAdapter, calendarDataProvider)},
	{"calendarNameProvider", "Ljava/util/spi/CalendarNameProvider;", nullptr, $PROTECTED | $VOLATILE, $field(JRELocaleProviderAdapter, calendarNameProvider)},
	{"calendarProvider", "Lsun/util/spi/CalendarProvider;", nullptr, $PRIVATE | $VOLATILE, $field(JRELocaleProviderAdapter, calendarProvider)},
	{"javaTimeDateTimePatternProvider", "Lsun/text/spi/JavaTimeDateTimePatternProvider;", nullptr, $PRIVATE | $VOLATILE, $field(JRELocaleProviderAdapter, javaTimeDateTimePatternProvider)},
	{}
};

$MethodInfo _JRELocaleProviderAdapter_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(JRELocaleProviderAdapter, init$, void)},
	{"createAvailableLocales", "()[Ljava/util/Locale;", nullptr, $PRIVATE | $STATIC, $staticMethod(JRELocaleProviderAdapter, createAvailableLocales, $LocaleArray*)},
	{"createLanguageTagSet", "(Ljava/lang/String;)Ljava/util/Set;", "(Ljava/lang/String;)Ljava/util/Set<Ljava/lang/String;>;", $PROTECTED, $virtualMethod(JRELocaleProviderAdapter, createLanguageTagSet, $Set*, $String*)},
	{"createSupportedLocaleString", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(JRELocaleProviderAdapter, createSupportedLocaleString, $String*, $String*)},
	{"getAdapterType", "()Lsun/util/locale/provider/LocaleProviderAdapter$Type;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, getAdapterType, $LocaleProviderAdapter$Type*)},
	{"getAvailableLocales", "()[Ljava/util/Locale;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, getAvailableLocales, $LocaleArray*)},
	{"getBreakIteratorProvider", "()Ljava/text/spi/BreakIteratorProvider;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, getBreakIteratorProvider, $BreakIteratorProvider*)},
	{"getCalendarDataProvider", "()Ljava/util/spi/CalendarDataProvider;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, getCalendarDataProvider, $CalendarDataProvider*)},
	{"getCalendarNameProvider", "()Ljava/util/spi/CalendarNameProvider;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, getCalendarNameProvider, $CalendarNameProvider*)},
	{"getCalendarProvider", "()Lsun/util/spi/CalendarProvider;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, getCalendarProvider, $CalendarProvider*)},
	{"getCandidateLocales", "(Ljava/lang/String;Ljava/util/Locale;)Ljava/util/List;", "(Ljava/lang/String;Ljava/util/Locale;)Ljava/util/List<Ljava/util/Locale;>;", $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, getCandidateLocales, $List*, $String*, $Locale*)},
	{"getCollatorProvider", "()Ljava/text/spi/CollatorProvider;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, getCollatorProvider, $CollatorProvider*)},
	{"getCurrencyNameProvider", "()Ljava/util/spi/CurrencyNameProvider;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, getCurrencyNameProvider, $CurrencyNameProvider*)},
	{"getDateFormatProvider", "()Ljava/text/spi/DateFormatProvider;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, getDateFormatProvider, $DateFormatProvider*)},
	{"getDateFormatSymbolsProvider", "()Ljava/text/spi/DateFormatSymbolsProvider;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, getDateFormatSymbolsProvider, $DateFormatSymbolsProvider*)},
	{"getDecimalFormatSymbolsProvider", "()Ljava/text/spi/DecimalFormatSymbolsProvider;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, getDecimalFormatSymbolsProvider, $DecimalFormatSymbolsProvider*)},
	{"getJavaTimeDateTimePatternProvider", "()Lsun/text/spi/JavaTimeDateTimePatternProvider;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, getJavaTimeDateTimePatternProvider, $JavaTimeDateTimePatternProvider*)},
	{"getLanguageTagSet", "(Ljava/lang/String;)Ljava/util/Set;", "(Ljava/lang/String;)Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, getLanguageTagSet, $Set*, $String*)},
	{"getLocaleData", "()Lsun/util/resources/LocaleData;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, getLocaleData, $LocaleData*)},
	{"getLocaleNameProvider", "()Ljava/util/spi/LocaleNameProvider;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, getLocaleNameProvider, $LocaleNameProvider*)},
	{"getLocaleResources", "(Ljava/util/Locale;)Lsun/util/locale/provider/LocaleResources;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, getLocaleResources, $LocaleResources*, $Locale*)},
	{"getLocaleServiceProvider", "(Ljava/lang/Class;)Ljava/util/spi/LocaleServiceProvider;", "<P:Ljava/util/spi/LocaleServiceProvider;>(Ljava/lang/Class<TP;>;)TP;", $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, getLocaleServiceProvider, $LocaleServiceProvider*, $Class*)},
	{"getNumberFormatProvider", "()Ljava/text/spi/NumberFormatProvider;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, getNumberFormatProvider, $NumberFormatProvider*)},
	{"getTimeZoneNameProvider", "()Ljava/util/spi/TimeZoneNameProvider;", nullptr, $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, getTimeZoneNameProvider, $TimeZoneNameProvider*)},
	{"isSupportedProviderLocale", "(Ljava/util/Locale;Ljava/util/Set;)Z", "(Ljava/util/Locale;Ljava/util/Set<Ljava/lang/String;>;)Z", $PUBLIC, $virtualMethod(JRELocaleProviderAdapter, isSupportedProviderLocale, bool, $Locale*, $Set*)},
	{"lambda$createSupportedLocaleString$13", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(JRELocaleProviderAdapter, lambda$createSupportedLocaleString$13, $String*, $String*), "java.lang.Exception"},
	{"lambda$getBreakIteratorProvider$0", "()Ljava/text/spi/BreakIteratorProvider;", nullptr, $PRIVATE | $SYNTHETIC, $method(JRELocaleProviderAdapter, lambda$getBreakIteratorProvider$0, $BreakIteratorProvider*)},
	{"lambda$getCalendarDataProvider$9", "()Ljava/util/spi/CalendarDataProvider;", nullptr, $PRIVATE | $SYNTHETIC, $method(JRELocaleProviderAdapter, lambda$getCalendarDataProvider$9, $CalendarDataProvider*)},
	{"lambda$getCalendarNameProvider$10", "()Ljava/util/spi/CalendarNameProvider;", nullptr, $PRIVATE | $SYNTHETIC, $method(JRELocaleProviderAdapter, lambda$getCalendarNameProvider$10, $CalendarNameProvider*)},
	{"lambda$getCalendarProvider$11", "()Lsun/util/spi/CalendarProvider;", nullptr, $PRIVATE | $SYNTHETIC, $method(JRELocaleProviderAdapter, lambda$getCalendarProvider$11, $CalendarProvider*)},
	{"lambda$getCollatorProvider$1", "()Ljava/text/spi/CollatorProvider;", nullptr, $PRIVATE | $SYNTHETIC, $method(JRELocaleProviderAdapter, lambda$getCollatorProvider$1, $CollatorProvider*)},
	{"lambda$getCurrencyNameProvider$6", "()Ljava/util/spi/CurrencyNameProvider;", nullptr, $PRIVATE | $SYNTHETIC, $method(JRELocaleProviderAdapter, lambda$getCurrencyNameProvider$6, $CurrencyNameProvider*)},
	{"lambda$getDateFormatProvider$2", "()Ljava/text/spi/DateFormatProvider;", nullptr, $PRIVATE | $SYNTHETIC, $method(JRELocaleProviderAdapter, lambda$getDateFormatProvider$2, $DateFormatProvider*)},
	{"lambda$getDateFormatSymbolsProvider$3", "()Ljava/text/spi/DateFormatSymbolsProvider;", nullptr, $PRIVATE | $SYNTHETIC, $method(JRELocaleProviderAdapter, lambda$getDateFormatSymbolsProvider$3, $DateFormatSymbolsProvider*)},
	{"lambda$getDecimalFormatSymbolsProvider$4", "()Ljava/text/spi/DecimalFormatSymbolsProvider;", nullptr, $PRIVATE | $SYNTHETIC, $method(JRELocaleProviderAdapter, lambda$getDecimalFormatSymbolsProvider$4, $DecimalFormatSymbolsProvider*)},
	{"lambda$getJavaTimeDateTimePatternProvider$12", "()Lsun/text/spi/JavaTimeDateTimePatternProvider;", nullptr, $PRIVATE | $SYNTHETIC, $method(JRELocaleProviderAdapter, lambda$getJavaTimeDateTimePatternProvider$12, $JavaTimeDateTimePatternProvider*)},
	{"lambda$getLocaleNameProvider$7", "()Ljava/util/spi/LocaleNameProvider;", nullptr, $PRIVATE | $SYNTHETIC, $method(JRELocaleProviderAdapter, lambda$getLocaleNameProvider$7, $LocaleNameProvider*)},
	{"lambda$getNumberFormatProvider$5", "()Ljava/text/spi/NumberFormatProvider;", nullptr, $PRIVATE | $SYNTHETIC, $method(JRELocaleProviderAdapter, lambda$getNumberFormatProvider$5, $NumberFormatProvider*)},
	{"lambda$getTimeZoneNameProvider$8", "()Ljava/util/spi/TimeZoneNameProvider;", nullptr, $PRIVATE | $SYNTHETIC, $method(JRELocaleProviderAdapter, lambda$getTimeZoneNameProvider$8, $TimeZoneNameProvider*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _JRELocaleProviderAdapter_InnerClassesInfo_[] = {
	{"sun.util.locale.provider.JRELocaleProviderAdapter$AvailableJRELocales", "sun.util.locale.provider.JRELocaleProviderAdapter", "AvailableJRELocales", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _JRELocaleProviderAdapter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.util.locale.provider.JRELocaleProviderAdapter",
	"sun.util.locale.provider.LocaleProviderAdapter",
	"sun.util.locale.provider.ResourceBundleBasedAdapter",
	_JRELocaleProviderAdapter_FieldInfo_,
	_JRELocaleProviderAdapter_MethodInfo_,
	nullptr,
	nullptr,
	_JRELocaleProviderAdapter_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.util.locale.provider.JRELocaleProviderAdapter$AvailableJRELocales"
};

$Object* allocate$JRELocaleProviderAdapter($Class* clazz) {
	return $of($alloc(JRELocaleProviderAdapter));
}

int32_t JRELocaleProviderAdapter::hashCode() {
	 return this->$LocaleProviderAdapter::hashCode();
}

bool JRELocaleProviderAdapter::equals(Object$* obj) {
	 return this->$LocaleProviderAdapter::equals(obj);
}

$Object* JRELocaleProviderAdapter::clone() {
	 return this->$LocaleProviderAdapter::clone();
}

$String* JRELocaleProviderAdapter::toString() {
	 return this->$LocaleProviderAdapter::toString();
}

void JRELocaleProviderAdapter::finalize() {
	this->$LocaleProviderAdapter::finalize();
}

void JRELocaleProviderAdapter::init$() {
	$LocaleProviderAdapter::init$();
	$set(this, langtagSets, $new($ConcurrentHashMap));
	$set(this, localeResourcesMap, $new($ConcurrentHashMap));
}

$LocaleProviderAdapter$Type* JRELocaleProviderAdapter::getAdapterType() {
	$init($LocaleProviderAdapter$Type);
	return $LocaleProviderAdapter$Type::JRE;
}

$LocaleServiceProvider* JRELocaleProviderAdapter::getLocaleServiceProvider($Class* c) {
	{
		$var($String, s3424$, $nc(c)->getSimpleName());
		int32_t tmp3424$ = -1;
		switch ($nc(s3424$)->hashCode()) {
		case 0x361E337E:
			{
				if (s3424$->equals("BreakIteratorProvider"_s)) {
					tmp3424$ = 0;
				}
				break;
			}
		case 0x05687E73:
			{
				if (s3424$->equals("CollatorProvider"_s)) {
					tmp3424$ = 1;
				}
				break;
			}
		case (int32_t)0xF88BEA76:
			{
				if (s3424$->equals("DateFormatProvider"_s)) {
					tmp3424$ = 2;
				}
				break;
			}
		case (int32_t)0x9FBD88C7:
			{
				if (s3424$->equals("DateFormatSymbolsProvider"_s)) {
					tmp3424$ = 3;
				}
				break;
			}
		case 0x0251CD44:
			{
				if (s3424$->equals("DecimalFormatSymbolsProvider"_s)) {
					tmp3424$ = 4;
				}
				break;
			}
		case (int32_t)0xAF5962D1:
			{
				if (s3424$->equals("NumberFormatProvider"_s)) {
					tmp3424$ = 5;
				}
				break;
			}
		case (int32_t)0xD068106D:
			{
				if (s3424$->equals("CurrencyNameProvider"_s)) {
					tmp3424$ = 6;
				}
				break;
			}
		case 0x0DD09136:
			{
				if (s3424$->equals("LocaleNameProvider"_s)) {
					tmp3424$ = 7;
				}
				break;
			}
		case 0x59931075:
			{
				if (s3424$->equals("TimeZoneNameProvider"_s)) {
					tmp3424$ = 8;
				}
				break;
			}
		case 0x3D4AA639:
			{
				if (s3424$->equals("CalendarDataProvider"_s)) {
					tmp3424$ = 9;
				}
				break;
			}
		case 0x2D4AC01A:
			{
				if (s3424$->equals("CalendarNameProvider"_s)) {
					tmp3424$ = 10;
				}
				break;
			}
		case 0x4F898B6F:
			{
				if (s3424$->equals("CalendarProvider"_s)) {
					tmp3424$ = 11;
				}
				break;
			}
		case 0x54156357:
			{
				if (s3424$->equals("JavaTimeDateTimePatternProvider"_s)) {
					tmp3424$ = 12;
				}
				break;
			}
		}
		switch (tmp3424$) {
		case 0:
			{
				return static_cast<$LocaleServiceProvider*>(getBreakIteratorProvider());
			}
		case 1:
			{
				return static_cast<$LocaleServiceProvider*>(getCollatorProvider());
			}
		case 2:
			{
				return static_cast<$LocaleServiceProvider*>(getDateFormatProvider());
			}
		case 3:
			{
				return static_cast<$LocaleServiceProvider*>(getDateFormatSymbolsProvider());
			}
		case 4:
			{
				return static_cast<$LocaleServiceProvider*>(getDecimalFormatSymbolsProvider());
			}
		case 5:
			{
				return static_cast<$LocaleServiceProvider*>(getNumberFormatProvider());
			}
		case 6:
			{
				return static_cast<$LocaleServiceProvider*>(getCurrencyNameProvider());
			}
		case 7:
			{
				return static_cast<$LocaleServiceProvider*>(getLocaleNameProvider());
			}
		case 8:
			{
				return static_cast<$LocaleServiceProvider*>(getTimeZoneNameProvider());
			}
		case 9:
			{
				return static_cast<$LocaleServiceProvider*>(getCalendarDataProvider());
			}
		case 10:
			{
				return static_cast<$LocaleServiceProvider*>(getCalendarNameProvider());
			}
		case 11:
			{
				return static_cast<$LocaleServiceProvider*>(getCalendarProvider());
			}
		case 12:
			{
				return static_cast<$LocaleServiceProvider*>(getJavaTimeDateTimePatternProvider());
			}
		default:
			{
				$throwNew($InternalError, "should not come down here"_s);
			}
		}
	}
}

$BreakIteratorProvider* JRELocaleProviderAdapter::getBreakIteratorProvider() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->breakIteratorProvider == nullptr) {
		$var($BreakIteratorProvider, provider, $cast($BreakIteratorProvider, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(JRELocaleProviderAdapter$$Lambda$lambda$getBreakIteratorProvider$0, this)))));
		$synchronized(this) {
			if (this->breakIteratorProvider == nullptr) {
				$set(this, breakIteratorProvider, provider);
			}
		}
	}
	return this->breakIteratorProvider;
}

$CollatorProvider* JRELocaleProviderAdapter::getCollatorProvider() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->collatorProvider == nullptr) {
		$var($CollatorProvider, provider, $cast($CollatorProvider, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(JRELocaleProviderAdapter$$Lambda$lambda$getCollatorProvider$1$1, this)))));
		$synchronized(this) {
			if (this->collatorProvider == nullptr) {
				$set(this, collatorProvider, provider);
			}
		}
	}
	return this->collatorProvider;
}

$DateFormatProvider* JRELocaleProviderAdapter::getDateFormatProvider() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->dateFormatProvider == nullptr) {
		$var($DateFormatProvider, provider, $cast($DateFormatProvider, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatProvider$2$2, this)))));
		$synchronized(this) {
			if (this->dateFormatProvider == nullptr) {
				$set(this, dateFormatProvider, provider);
			}
		}
	}
	return this->dateFormatProvider;
}

$DateFormatSymbolsProvider* JRELocaleProviderAdapter::getDateFormatSymbolsProvider() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->dateFormatSymbolsProvider == nullptr) {
		$var($DateFormatSymbolsProvider, provider, $cast($DateFormatSymbolsProvider, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatSymbolsProvider$3$3, this)))));
		$synchronized(this) {
			if (this->dateFormatSymbolsProvider == nullptr) {
				$set(this, dateFormatSymbolsProvider, provider);
			}
		}
	}
	return this->dateFormatSymbolsProvider;
}

$DecimalFormatSymbolsProvider* JRELocaleProviderAdapter::getDecimalFormatSymbolsProvider() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->decimalFormatSymbolsProvider == nullptr) {
		$var($DecimalFormatSymbolsProvider, provider, $cast($DecimalFormatSymbolsProvider, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(JRELocaleProviderAdapter$$Lambda$lambda$getDecimalFormatSymbolsProvider$4$4, this)))));
		$synchronized(this) {
			if (this->decimalFormatSymbolsProvider == nullptr) {
				$set(this, decimalFormatSymbolsProvider, provider);
			}
		}
	}
	return this->decimalFormatSymbolsProvider;
}

$NumberFormatProvider* JRELocaleProviderAdapter::getNumberFormatProvider() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->numberFormatProvider == nullptr) {
		$var($NumberFormatProvider, provider, $cast($NumberFormatProvider, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(JRELocaleProviderAdapter$$Lambda$lambda$getNumberFormatProvider$5$5, this)))));
		$synchronized(this) {
			if (this->numberFormatProvider == nullptr) {
				$set(this, numberFormatProvider, provider);
			}
		}
	}
	return this->numberFormatProvider;
}

$CurrencyNameProvider* JRELocaleProviderAdapter::getCurrencyNameProvider() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->currencyNameProvider == nullptr) {
		$var($CurrencyNameProvider, provider, $cast($CurrencyNameProvider, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(JRELocaleProviderAdapter$$Lambda$lambda$getCurrencyNameProvider$6$6, this)))));
		$synchronized(this) {
			if (this->currencyNameProvider == nullptr) {
				$set(this, currencyNameProvider, provider);
			}
		}
	}
	return this->currencyNameProvider;
}

$LocaleNameProvider* JRELocaleProviderAdapter::getLocaleNameProvider() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->localeNameProvider == nullptr) {
		$var($LocaleNameProvider, provider, $cast($LocaleNameProvider, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(JRELocaleProviderAdapter$$Lambda$lambda$getLocaleNameProvider$7$7, this)))));
		$synchronized(this) {
			if (this->localeNameProvider == nullptr) {
				$set(this, localeNameProvider, provider);
			}
		}
	}
	return this->localeNameProvider;
}

$TimeZoneNameProvider* JRELocaleProviderAdapter::getTimeZoneNameProvider() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->timeZoneNameProvider == nullptr) {
		$var($TimeZoneNameProvider, provider, $cast($TimeZoneNameProvider, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(JRELocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$8$8, this)))));
		$synchronized(this) {
			if (this->timeZoneNameProvider == nullptr) {
				$set(this, timeZoneNameProvider, provider);
			}
		}
	}
	return this->timeZoneNameProvider;
}

$CalendarDataProvider* JRELocaleProviderAdapter::getCalendarDataProvider() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->calendarDataProvider == nullptr) {
		$var($CalendarDataProvider, provider, $cast($CalendarDataProvider, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$9$9, this)))));
		$synchronized(this) {
			if (this->calendarDataProvider == nullptr) {
				$set(this, calendarDataProvider, provider);
			}
		}
	}
	return this->calendarDataProvider;
}

$CalendarNameProvider* JRELocaleProviderAdapter::getCalendarNameProvider() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->calendarNameProvider == nullptr) {
		$var($CalendarNameProvider, provider, $cast($CalendarNameProvider, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$10$10, this)))));
		$synchronized(this) {
			if (this->calendarNameProvider == nullptr) {
				$set(this, calendarNameProvider, provider);
			}
		}
	}
	return this->calendarNameProvider;
}

$CalendarProvider* JRELocaleProviderAdapter::getCalendarProvider() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->calendarProvider == nullptr) {
		$var($CalendarProvider, provider, $cast($CalendarProvider, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarProvider$11$11, this)))));
		$synchronized(this) {
			if (this->calendarProvider == nullptr) {
				$set(this, calendarProvider, provider);
			}
		}
	}
	return this->calendarProvider;
}

$JavaTimeDateTimePatternProvider* JRELocaleProviderAdapter::getJavaTimeDateTimePatternProvider() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->javaTimeDateTimePatternProvider == nullptr) {
		$var($JavaTimeDateTimePatternProvider, provider, $cast($JavaTimeDateTimePatternProvider, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(JRELocaleProviderAdapter$$Lambda$lambda$getJavaTimeDateTimePatternProvider$12$12, this)))));
		$synchronized(this) {
			if (this->javaTimeDateTimePatternProvider == nullptr) {
				$set(this, javaTimeDateTimePatternProvider, provider);
			}
		}
	}
	return this->javaTimeDateTimePatternProvider;
}

$LocaleResources* JRELocaleProviderAdapter::getLocaleResources($Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$var($LocaleResources, lr, $cast($LocaleResources, $nc(this->localeResourcesMap)->get(locale)));
	if (lr == nullptr) {
		$assign(lr, $new($LocaleResources, this, locale));
		$var($LocaleResources, lrc, $cast($LocaleResources, $nc(this->localeResourcesMap)->putIfAbsent(locale, lr)));
		if (lrc != nullptr) {
			$assign(lr, lrc);
		}
	}
	return lr;
}

$LocaleData* JRELocaleProviderAdapter::getLocaleData() {
	if (this->localeData == nullptr) {
		$synchronized(this) {
			if (this->localeData == nullptr) {
				$set(this, localeData, $new($LocaleData, $(getAdapterType())));
			}
		}
	}
	return this->localeData;
}

$List* JRELocaleProviderAdapter::getCandidateLocales($String* baseName, $Locale* locale) {
	$init($ResourceBundle$Control);
	return $nc($($ResourceBundle$Control::getNoFallbackControl($ResourceBundle$Control::FORMAT_DEFAULT)))->getCandidateLocales(baseName, locale);
}

$LocaleArray* JRELocaleProviderAdapter::getAvailableLocales() {
	$init($JRELocaleProviderAdapter$AvailableJRELocales);
	return $cast($LocaleArray, $nc($JRELocaleProviderAdapter$AvailableJRELocales::localeList)->clone());
}

$Set* JRELocaleProviderAdapter::getLanguageTagSet($String* category) {
	$useLocalCurrentObjectStackCache();
	$var($Set, tagset, $cast($Set, $nc(this->langtagSets)->get(category)));
	if (tagset == nullptr) {
		$assign(tagset, createLanguageTagSet(category));
		$var($Set, ts, $cast($Set, $nc(this->langtagSets)->putIfAbsent(category, tagset)));
		if (ts != nullptr) {
			$assign(tagset, ts);
		}
	}
	return tagset;
}

$Set* JRELocaleProviderAdapter::createLanguageTagSet($String* category) {
	$useLocalCurrentObjectStackCache();
	$var($String, supportedLocaleString, createSupportedLocaleString(category));
	if (supportedLocaleString == nullptr) {
		return $Collections::emptySet();
	}
	$var($StringTokenizer, tokens, $new($StringTokenizer, supportedLocaleString));
	$var($Set, tagset, $new($HashSet, (tokens->countTokens() * 4 + 2) / 3));
	while (tokens->hasMoreTokens()) {
		tagset->add($(tokens->nextToken()));
	}
	return tagset;
}

$String* JRELocaleProviderAdapter::createSupportedLocaleString($String* category) {
	$init(JRELocaleProviderAdapter);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, supportedLocaleString, $BaseLocaleDataMetaInfo::getSupportedLocaleString(category));
	try {
		$var($String, nonBaseTags, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new(JRELocaleProviderAdapter$$Lambda$lambda$createSupportedLocaleString$13$13, category)))));
		if (nonBaseTags != nullptr) {
			$plusAssign(supportedLocaleString, $$str({" "_s, nonBaseTags}));
		}
	} catch ($PrivilegedActionException& pae) {
		$throwNew($InternalError, $(pae->getCause()));
	}
	return supportedLocaleString;
}

$LocaleArray* JRELocaleProviderAdapter::createAvailableLocales() {
	$init(JRELocaleProviderAdapter);
	$useLocalCurrentObjectStackCache();
	$var($String, supportedLocaleString, createSupportedLocaleString("AvailableLocales"_s));
	if ($nc(supportedLocaleString)->isEmpty()) {
		$throwNew($InternalError, "No available locales for JRE"_s);
	}
	$var($StringTokenizer, localeStringTokenizer, $new($StringTokenizer, supportedLocaleString));
	int32_t length = localeStringTokenizer->countTokens();
	$var($LocaleArray, locales, $new($LocaleArray, length + 1));
	$init($Locale);
	locales->set(0, $Locale::ROOT);
	for (int32_t i = 1; i <= length; ++i) {
		$var($String, currentToken, localeStringTokenizer->nextToken());
		{
			$var($String, s19617$, currentToken);
			int32_t tmp19617$ = -1;
			switch ($nc(s19617$)->hashCode()) {
			case 0x5F7AF717:
				{
					if (s19617$->equals("ja-JP-JP"_s)) {
						tmp19617$ = 0;
					}
					break;
				}
			case (int32_t)0xE3CED24B:
				{
					if (s19617$->equals("no-NO-NY"_s)) {
						tmp19617$ = 1;
					}
					break;
				}
			case (int32_t)0xE11B9FD4:
				{
					if (s19617$->equals("th-TH-TH"_s)) {
						tmp19617$ = 2;
					}
					break;
				}
			}
			switch (tmp19617$) {
			case 0:
				{
					$init($JRELocaleConstants);
					locales->set(i, $JRELocaleConstants::JA_JP_JP);
					break;
				}
			case 1:
				{
					$init($JRELocaleConstants);
					locales->set(i, $JRELocaleConstants::NO_NO_NY);
					break;
				}
			case 2:
				{
					$init($JRELocaleConstants);
					locales->set(i, $JRELocaleConstants::TH_TH_TH);
					break;
				}
			default:
				{
					locales->set(i, $($Locale::forLanguageTag(currentToken)));
				}
			}
		}
	}
	return locales;
}

bool JRELocaleProviderAdapter::isSupportedProviderLocale($Locale* locale$renamed, $Set* langtags) {
	$useLocalCurrentObjectStackCache();
	$var($Locale, locale, locale$renamed);
	$init($Locale);
	if ($nc($Locale::ROOT)->equals(locale)) {
		return true;
	}
	$assign(locale, $nc(locale)->stripExtensions());
	if ($nc(langtags)->contains($(locale->toLanguageTag()))) {
		return true;
	}
	$var($String, oldname, $nc($(locale->toString()))->replace(u'_', u'-'));
	bool var$2 = $nc(langtags)->contains(oldname);
	bool var$1 = var$2 || "ja-JP-JP"_s->equals(oldname);
	bool var$0 = var$1 || "th-TH-TH"_s->equals(oldname);
	return var$0 || "no-NO-NY"_s->equals(oldname);
}

$String* JRELocaleProviderAdapter::lambda$createSupportedLocaleString$13($String* category) {
	$init(JRELocaleProviderAdapter);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($StringBuilder, tags, $new($StringBuilder));
	{
		$load($LocaleDataMetaInfo);
		$var($Iterator, i$, $nc($($ServiceLoader::loadInstalled($LocaleDataMetaInfo::class$)))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($LocaleDataMetaInfo, ldmi, $cast($LocaleDataMetaInfo, i$->next()));
			{
				$init($LocaleProviderAdapter$Type);
				if ($nc(ldmi)->getType() == $LocaleProviderAdapter$Type::JRE) {
					$var($String, t, ldmi->availableLanguageTags(category));
					if (t != nullptr) {
						if (tags->length() > 0) {
							tags->append(u' ');
						}
						tags->append(t);
					}
				}
			}
		}
	}
	return tags->toString();
}

$JavaTimeDateTimePatternProvider* JRELocaleProviderAdapter::lambda$getJavaTimeDateTimePatternProvider$12() {
	$useLocalCurrentObjectStackCache();
	$var($LocaleProviderAdapter$Type, var$0, getAdapterType());
	return $new($JavaTimeDateTimePatternImpl, var$0, $(getLanguageTagSet("FormatData"_s)));
}

$CalendarProvider* JRELocaleProviderAdapter::lambda$getCalendarProvider$11() {
	$useLocalCurrentObjectStackCache();
	$var($LocaleProviderAdapter$Type, var$0, getAdapterType());
	return $new($CalendarProviderImpl, var$0, $(getLanguageTagSet("CalendarData"_s)));
}

$CalendarNameProvider* JRELocaleProviderAdapter::lambda$getCalendarNameProvider$10() {
	$useLocalCurrentObjectStackCache();
	$var($LocaleProviderAdapter$Type, var$0, getAdapterType());
	return $new($CalendarNameProviderImpl, var$0, $(getLanguageTagSet("FormatData"_s)));
}

$CalendarDataProvider* JRELocaleProviderAdapter::lambda$getCalendarDataProvider$9() {
	$useLocalCurrentObjectStackCache();
	$var($LocaleProviderAdapter$Type, var$0, getAdapterType());
	return $new($CalendarDataProviderImpl, var$0, $(getLanguageTagSet("CalendarData"_s)));
}

$TimeZoneNameProvider* JRELocaleProviderAdapter::lambda$getTimeZoneNameProvider$8() {
	$useLocalCurrentObjectStackCache();
	$var($LocaleProviderAdapter$Type, var$0, getAdapterType());
	return $new($TimeZoneNameProviderImpl, var$0, $(getLanguageTagSet("TimeZoneNames"_s)));
}

$LocaleNameProvider* JRELocaleProviderAdapter::lambda$getLocaleNameProvider$7() {
	$useLocalCurrentObjectStackCache();
	$var($LocaleProviderAdapter$Type, var$0, getAdapterType());
	return $new($LocaleNameProviderImpl, var$0, $(getLanguageTagSet("LocaleNames"_s)));
}

$CurrencyNameProvider* JRELocaleProviderAdapter::lambda$getCurrencyNameProvider$6() {
	$useLocalCurrentObjectStackCache();
	$var($LocaleProviderAdapter$Type, var$0, getAdapterType());
	return $new($CurrencyNameProviderImpl, var$0, $(getLanguageTagSet("CurrencyNames"_s)));
}

$NumberFormatProvider* JRELocaleProviderAdapter::lambda$getNumberFormatProvider$5() {
	$useLocalCurrentObjectStackCache();
	$var($LocaleProviderAdapter$Type, var$0, getAdapterType());
	return $new($NumberFormatProviderImpl, var$0, $(getLanguageTagSet("FormatData"_s)));
}

$DecimalFormatSymbolsProvider* JRELocaleProviderAdapter::lambda$getDecimalFormatSymbolsProvider$4() {
	$useLocalCurrentObjectStackCache();
	$var($LocaleProviderAdapter$Type, var$0, getAdapterType());
	return $new($DecimalFormatSymbolsProviderImpl, var$0, $(getLanguageTagSet("FormatData"_s)));
}

$DateFormatSymbolsProvider* JRELocaleProviderAdapter::lambda$getDateFormatSymbolsProvider$3() {
	$useLocalCurrentObjectStackCache();
	$var($LocaleProviderAdapter$Type, var$0, getAdapterType());
	return $new($DateFormatSymbolsProviderImpl, var$0, $(getLanguageTagSet("FormatData"_s)));
}

$DateFormatProvider* JRELocaleProviderAdapter::lambda$getDateFormatProvider$2() {
	$useLocalCurrentObjectStackCache();
	$var($LocaleProviderAdapter$Type, var$0, getAdapterType());
	return $new($DateFormatProviderImpl, var$0, $(getLanguageTagSet("FormatData"_s)));
}

$CollatorProvider* JRELocaleProviderAdapter::lambda$getCollatorProvider$1() {
	$useLocalCurrentObjectStackCache();
	$var($LocaleProviderAdapter$Type, var$0, getAdapterType());
	return $new($CollatorProviderImpl, var$0, $(getLanguageTagSet("CollationData"_s)));
}

$BreakIteratorProvider* JRELocaleProviderAdapter::lambda$getBreakIteratorProvider$0() {
	$useLocalCurrentObjectStackCache();
	$var($LocaleProviderAdapter$Type, var$0, getAdapterType());
	return $new($BreakIteratorProviderImpl, var$0, $(getLanguageTagSet("FormatData"_s)));
}

JRELocaleProviderAdapter::JRELocaleProviderAdapter() {
}

$Class* JRELocaleProviderAdapter::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(JRELocaleProviderAdapter$$Lambda$lambda$getBreakIteratorProvider$0::classInfo$.name)) {
			return JRELocaleProviderAdapter$$Lambda$lambda$getBreakIteratorProvider$0::load$(name, initialize);
		}
		if (name->equals(JRELocaleProviderAdapter$$Lambda$lambda$getCollatorProvider$1$1::classInfo$.name)) {
			return JRELocaleProviderAdapter$$Lambda$lambda$getCollatorProvider$1$1::load$(name, initialize);
		}
		if (name->equals(JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatProvider$2$2::classInfo$.name)) {
			return JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatProvider$2$2::load$(name, initialize);
		}
		if (name->equals(JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatSymbolsProvider$3$3::classInfo$.name)) {
			return JRELocaleProviderAdapter$$Lambda$lambda$getDateFormatSymbolsProvider$3$3::load$(name, initialize);
		}
		if (name->equals(JRELocaleProviderAdapter$$Lambda$lambda$getDecimalFormatSymbolsProvider$4$4::classInfo$.name)) {
			return JRELocaleProviderAdapter$$Lambda$lambda$getDecimalFormatSymbolsProvider$4$4::load$(name, initialize);
		}
		if (name->equals(JRELocaleProviderAdapter$$Lambda$lambda$getNumberFormatProvider$5$5::classInfo$.name)) {
			return JRELocaleProviderAdapter$$Lambda$lambda$getNumberFormatProvider$5$5::load$(name, initialize);
		}
		if (name->equals(JRELocaleProviderAdapter$$Lambda$lambda$getCurrencyNameProvider$6$6::classInfo$.name)) {
			return JRELocaleProviderAdapter$$Lambda$lambda$getCurrencyNameProvider$6$6::load$(name, initialize);
		}
		if (name->equals(JRELocaleProviderAdapter$$Lambda$lambda$getLocaleNameProvider$7$7::classInfo$.name)) {
			return JRELocaleProviderAdapter$$Lambda$lambda$getLocaleNameProvider$7$7::load$(name, initialize);
		}
		if (name->equals(JRELocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$8$8::classInfo$.name)) {
			return JRELocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$8$8::load$(name, initialize);
		}
		if (name->equals(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$9$9::classInfo$.name)) {
			return JRELocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$9$9::load$(name, initialize);
		}
		if (name->equals(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$10$10::classInfo$.name)) {
			return JRELocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$10$10::load$(name, initialize);
		}
		if (name->equals(JRELocaleProviderAdapter$$Lambda$lambda$getCalendarProvider$11$11::classInfo$.name)) {
			return JRELocaleProviderAdapter$$Lambda$lambda$getCalendarProvider$11$11::load$(name, initialize);
		}
		if (name->equals(JRELocaleProviderAdapter$$Lambda$lambda$getJavaTimeDateTimePatternProvider$12$12::classInfo$.name)) {
			return JRELocaleProviderAdapter$$Lambda$lambda$getJavaTimeDateTimePatternProvider$12$12::load$(name, initialize);
		}
		if (name->equals(JRELocaleProviderAdapter$$Lambda$lambda$createSupportedLocaleString$13$13::classInfo$.name)) {
			return JRELocaleProviderAdapter$$Lambda$lambda$createSupportedLocaleString$13$13::load$(name, initialize);
		}
	}
	$loadClass(JRELocaleProviderAdapter, name, initialize, &_JRELocaleProviderAdapter_ClassInfo_, allocate$JRELocaleProviderAdapter);
	return class$;
}

$Class* JRELocaleProviderAdapter::class$ = nullptr;

			} // provider
		} // locale
	} // util
} // sun