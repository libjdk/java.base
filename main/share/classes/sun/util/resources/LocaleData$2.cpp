#include <sun/util/resources/LocaleData$2.h>

#include <java/util/Locale.h>
#include <java/util/MissingResourceException.h>
#include <java/util/ResourceBundle.h>
#include <sun/util/resources/Bundles$Strategy.h>
#include <sun/util/resources/Bundles.h>
#include <sun/util/resources/LocaleData$SupplementaryStrategy.h>
#include <sun/util/resources/LocaleData.h>
#include <sun/util/resources/OpenListResourceBundle.h>
#include <jcpp.h>

#undef INSTANCE

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Locale = ::java::util::Locale;
using $MissingResourceException = ::java::util::MissingResourceException;
using $Bundles = ::sun::util::resources::Bundles;
using $Bundles$Strategy = ::sun::util::resources::Bundles$Strategy;
using $LocaleData$SupplementaryStrategy = ::sun::util::resources::LocaleData$SupplementaryStrategy;
using $OpenListResourceBundle = ::sun::util::resources::OpenListResourceBundle;

namespace sun {
	namespace util {
		namespace resources {

$FieldInfo _LocaleData$2_FieldInfo_[] = {
	{"val$locale", "Ljava/util/Locale;", nullptr, $FINAL | $SYNTHETIC, $field(LocaleData$2, val$locale)},
	{"val$baseName", "Ljava/lang/String;", nullptr, $FINAL | $SYNTHETIC, $field(LocaleData$2, val$baseName)},
	{}
};

$MethodInfo _LocaleData$2_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/util/Locale;)V", nullptr, 0, $method(LocaleData$2, init$, void, $String*, $Locale*)},
	{"run", "()Lsun/util/resources/OpenListResourceBundle;", nullptr, $PUBLIC, $virtualMethod(LocaleData$2, run, $Object*)},
	{}
};

$EnclosingMethodInfo _LocaleData$2_EnclosingMethodInfo_ = {
	"sun.util.resources.LocaleData",
	"getSupplementary",
	"(Ljava/lang/String;Ljava/util/Locale;)Lsun/util/resources/OpenListResourceBundle;"
};

$InnerClassInfo _LocaleData$2_InnerClassesInfo_[] = {
	{"sun.util.resources.LocaleData$2", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LocaleData$2_ClassInfo_ = {
	$ACC_SUPER,
	"sun.util.resources.LocaleData$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_LocaleData$2_FieldInfo_,
	_LocaleData$2_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Lsun/util/resources/OpenListResourceBundle;>;",
	&_LocaleData$2_EnclosingMethodInfo_,
	_LocaleData$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.util.resources.LocaleData"
};

$Object* allocate$LocaleData$2($Class* clazz) {
	return $of($alloc(LocaleData$2));
}

void LocaleData$2::init$($String* val$baseName, $Locale* val$locale) {
	$set(this, val$baseName, val$baseName);
	$set(this, val$locale, val$locale);
}

$Object* LocaleData$2::run() {
	$var($OpenListResourceBundle, rb, nullptr);
	try {
		$init($LocaleData$SupplementaryStrategy);
		$assign(rb, $cast($OpenListResourceBundle, $Bundles::of(this->val$baseName, this->val$locale, $LocaleData$SupplementaryStrategy::INSTANCE)));
	} catch ($MissingResourceException& e) {
	}
	return $of(rb);
}

LocaleData$2::LocaleData$2() {
}

$Class* LocaleData$2::load$($String* name, bool initialize) {
	$loadClass(LocaleData$2, name, initialize, &_LocaleData$2_ClassInfo_, allocate$LocaleData$2);
	return class$;
}

$Class* LocaleData$2::class$ = nullptr;

		} // resources
	} // util
} // sun