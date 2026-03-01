#include <java/util/Currency$1.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/DataInputStream.h>
#include <java/io/File.h>
#include <java/io/FileReader.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/Reader.h>
#include <java/io/Serializable.h>
#include <java/lang/InternalError.h>
#include <java/lang/Iterable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Currency$CurrencyProperty.h>
#include <java/util/Currency.h>
#include <java/util/List.h>
#include <java/util/Properties.h>
#include <java/util/function/Consumer.h>
#include <java/util/regex/Pattern.h>
#include <jdk/internal/util/StaticProperty.h>
#include <jcpp.h>

using $BufferedInputStream = ::java::io::BufferedInputStream;
using $DataInputStream = ::java::io::DataInputStream;
using $File = ::java::io::File;
using $FileReader = ::java::io::FileReader;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $Reader = ::java::io::Reader;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Currency = ::java::util::Currency;
using $Currency$CurrencyProperty = ::java::util::Currency$CurrencyProperty;
using $List = ::java::util::List;
using $Properties = ::java::util::Properties;
using $Consumer = ::java::util::function::Consumer;
using $Pattern = ::java::util::regex::Pattern;
using $StaticProperty = ::jdk::internal::util::StaticProperty;

namespace java {
	namespace util {

class Currency$1$$Lambda$replaceCurrencyData : public $Consumer {
	$class(Currency$1$$Lambda$replaceCurrencyData, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* prop) override {
		$Currency::replaceCurrencyData($cast($Currency$CurrencyProperty, prop));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Currency$1$$Lambda$replaceCurrencyData>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Currency$1$$Lambda$replaceCurrencyData::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Currency$1$$Lambda$replaceCurrencyData, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Currency$1$$Lambda$replaceCurrencyData, accept, void, Object$*)},
	{}
};
$ClassInfo Currency$1$$Lambda$replaceCurrencyData::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.Currency$1$$Lambda$replaceCurrencyData",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* Currency$1$$Lambda$replaceCurrencyData::load$($String* name, bool initialize) {
	$loadClass(Currency$1$$Lambda$replaceCurrencyData, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Currency$1$$Lambda$replaceCurrencyData::class$ = nullptr;

$MethodInfo _Currency$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(Currency$1, init$, void)},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC, $virtualMethod(Currency$1, run, $Object*)},
	{}
};

$EnclosingMethodInfo _Currency$1_EnclosingMethodInfo_ = {
	"java.util.Currency",
	nullptr,
	nullptr
};

$InnerClassInfo _Currency$1_InnerClassesInfo_[] = {
	{"java.util.Currency$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Currency$1_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.Currency$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_Currency$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Object;>;",
	&_Currency$1_EnclosingMethodInfo_,
	_Currency$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.Currency"
};

$Object* allocate$Currency$1($Class* clazz) {
	return $of($alloc(Currency$1));
}

void Currency$1::init$() {
}

$Object* Currency$1::run() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		{
			$var($InputStream, in, $of(this)->getClass()->getResourceAsStream("/java/util/currency.data"_s));
			{
				$var($Throwable, var$0, nullptr);
				try {
					try {
						if (in == nullptr) {
							$throwNew($InternalError, "Currency data not found"_s);
						}
						$var($DataInputStream, dis, $new($DataInputStream, $$new($BufferedInputStream, in)));
						if (dis->readInt() != 0x43757244) {
							$throwNew($InternalError, "Currency data is possibly corrupted"_s);
						}
						$init($Currency);
						$Currency::formatVersion = dis->readInt();
						if ($Currency::formatVersion != 3) {
							$throwNew($InternalError, "Currency data format is incorrect"_s);
						}
						$Currency::dataVersion = dis->readInt();
						$assignStatic($Currency::mainTable, $Currency::readIntArray(dis, 26 * 26));
						int32_t scCount = dis->readInt();
						$assignStatic($Currency::specialCasesList, $Currency::readSpecialCases(dis, scCount));
						int32_t ocCount = dis->readInt();
						$assignStatic($Currency::otherCurrenciesList, $Currency::readOtherCurrencies(dis, ocCount));
					} catch ($Throwable& t$) {
						if (in != nullptr) {
							try {
								in->close();
							} catch ($Throwable& x2) {
								t$->addSuppressed(x2);
							}
						}
						$throw(t$);
					}
				} catch ($Throwable& var$1) {
					$assign(var$0, var$1);
				} /*finally*/ {
					if (in != nullptr) {
						in->close();
					}
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		}
	} catch ($IOException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$var($String, propsFile, $System::getProperty("java.util.currency.data"_s));
	if (propsFile == nullptr) {
		$init($File);
		$assign(propsFile, $str({$($StaticProperty::javaHome()), $File::separator, "lib"_s, $File::separator, "currency.properties"_s}));
	}
	try {
		$var($File, propFile, $new($File, propsFile));
		if (propFile->exists()) {
			$var($Properties, props, $new($Properties));
			{
				$var($FileReader, fr, $new($FileReader, propFile));
				{
					$var($Throwable, var$2, nullptr);
					try {
						try {
							props->load(static_cast<$Reader*>(fr));
						} catch ($Throwable& t$) {
							try {
								fr->close();
							} catch ($Throwable& x2) {
								t$->addSuppressed(x2);
							}
							$throw(t$);
						}
					} catch ($Throwable& var$3) {
						$assign(var$2, var$3);
					} /*finally*/ {
						fr->close();
					}
					if (var$2 != nullptr) {
						$throw(var$2);
					}
				}
			}
			$var($Pattern, propertiesPattern, $Pattern::compile("([A-Z]{3})\\s*,\\s*(\\d{3})\\s*,\\s*(\\d+)\\s*,?\\s*(\\d{4}-\\d{2}-\\d{2}T\\d{2}:\\d{2}:\\d{2})?"_s));
			$var($List, currencyEntries, $Currency::getValidCurrencyData(props, propertiesPattern));
			$nc(currencyEntries)->forEach(static_cast<$Consumer*>($$new(Currency$1$$Lambda$replaceCurrencyData)));
		}
	} catch ($IOException& e) {
		$Currency$CurrencyProperty::info("currency.properties is ignored because of an IOException"_s, e);
	}
	return $of(nullptr);
}

Currency$1::Currency$1() {
}

$Class* Currency$1::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Currency$1$$Lambda$replaceCurrencyData::classInfo$.name)) {
			return Currency$1$$Lambda$replaceCurrencyData::load$(name, initialize);
		}
	}
	$loadClass(Currency$1, name, initialize, &_Currency$1_ClassInfo_, allocate$Currency$1);
	return class$;
}

$Class* Currency$1::class$ = nullptr;

	} // util
} // java