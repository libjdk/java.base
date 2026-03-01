#include <Bug8141243.h>

#include <java/text/DateFormat.h>
#include <java/text/ParseException.h>
#include <java/text/SimpleDateFormat.h>
#include <java/util/ArrayList.h>
#include <java/util/Date.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/TimeZone.h>
#include <jcpp.h>

#undef UTC

using $LocaleArray = $Array<::java::util::Locale>;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $DateFormat = ::java::text::DateFormat;
using $ParseException = ::java::text::ParseException;
using $SimpleDateFormat = ::java::text::SimpleDateFormat;
using $ArrayList = ::java::util::ArrayList;
using $Date = ::java::util::Date;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $TimeZone = ::java::util::TimeZone;

$MethodInfo _Bug8141243_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Bug8141243, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Bug8141243, main, void, $StringArray*)},
	{}
};

$ClassInfo _Bug8141243_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Bug8141243",
	"java.lang.Object",
	nullptr,
	nullptr,
	_Bug8141243_MethodInfo_
};

$Object* allocate$Bug8141243($Class* clazz) {
	return $of($alloc(Bug8141243));
}

void Bug8141243::init$() {
}

void Bug8141243::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($TimeZone, UTC, $TimeZone::getTimeZone("UTC"_s));
	$var($TimeZone, initTz, $TimeZone::getDefault());
	$var($List, errors, $new($ArrayList));
	{
		$var($Throwable, var$0, nullptr);
		try {
			$TimeZone::setDefault($($TimeZone::getTimeZone("America/Los_Angeles"_s)));
			{
				$var($LocaleArray, arr$, $DateFormat::getAvailableLocales());
				int32_t len$ = $nc(arr$)->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($Locale, locale, arr$->get(i$));
					{
						$var($String, utc, $nc(UTC)->getDisplayName(false, 0, locale));
						if (!"UTC"_s->equals(utc)) {
							$nc($System::out)->println($$str({"Skipping "_s, locale, " due to localized UTC name: "_s, utc}));
							continue;
						}
						$var($SimpleDateFormat, fmt, $new($SimpleDateFormat, "z"_s, locale));
						try {
							$var($Date, date, fmt->parse("UTC"_s));
							if (!$nc($($nc($(fmt->getTimeZone()))->getID()))->matches("(Etc/)?(UTC|Universal|UCT|Zulu)"_s)) {
								errors->add($$str({"timezone: "_s, $($nc($(fmt->getTimeZone()))->getID()), ", locale: "_s, locale}));
							}
						} catch ($ParseException& e) {
							errors->add($$str({"parse exception: "_s, e, ", locale: "_s, locale}));
						}
					}
				}
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$TimeZone::setDefault(initTz);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	if (!errors->isEmpty()) {
		$nc($System::out)->println("Got unexpected results:"_s);
		{
			$var($Iterator, i$, errors->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, s, $cast($String, i$->next()));
				{
					$nc($System::out)->println($$str({"    "_s, s}));
				}
			}
		}
		$throwNew($RuntimeException, "Test failed."_s);
	} else {
		$nc($System::out)->println("Test passed."_s);
	}
}

Bug8141243::Bug8141243() {
}

$Class* Bug8141243::load$($String* name, bool initialize) {
	$loadClass(Bug8141243, name, initialize, &_Bug8141243_ClassInfo_, allocate$Bug8141243);
	return class$;
}

$Class* Bug8141243::class$ = nullptr;