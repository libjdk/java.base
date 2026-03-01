#include <java/nio/charset/Charset$3.h>

#include <java/nio/charset/Charset$ExtendedProviderHolder.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/spi/CharsetProvider.h>
#include <java/util/AbstractMap.h>
#include <java/util/Collections.h>
#include <java/util/Comparator.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <java/util/SortedMap.h>
#include <java/util/TreeMap.h>
#include <jcpp.h>

#undef CASE_INSENSITIVE_ORDER

using $CharsetProviderArray = $Array<::java::nio::charset::spi::CharsetProvider>;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $Charset$ExtendedProviderHolder = ::java::nio::charset::Charset$ExtendedProviderHolder;
using $CharsetProvider = ::java::nio::charset::spi::CharsetProvider;
using $AbstractMap = ::java::util::AbstractMap;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $SortedMap = ::java::util::SortedMap;
using $TreeMap = ::java::util::TreeMap;

namespace java {
	namespace nio {
		namespace charset {

$MethodInfo _Charset$3_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(Charset$3, init$, void)},
	{"run", "()Ljava/util/SortedMap;", "()Ljava/util/SortedMap<Ljava/lang/String;Ljava/nio/charset/Charset;>;", $PUBLIC, $virtualMethod(Charset$3, run, $Object*)},
	{}
};

$EnclosingMethodInfo _Charset$3_EnclosingMethodInfo_ = {
	"java.nio.charset.Charset",
	"availableCharsets",
	"()Ljava/util/SortedMap;"
};

$InnerClassInfo _Charset$3_InnerClassesInfo_[] = {
	{"java.nio.charset.Charset$3", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Charset$3_ClassInfo_ = {
	$ACC_SUPER,
	"java.nio.charset.Charset$3",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_Charset$3_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/util/SortedMap<Ljava/lang/String;Ljava/nio/charset/Charset;>;>;",
	&_Charset$3_EnclosingMethodInfo_,
	_Charset$3_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.nio.charset.Charset"
};

$Object* allocate$Charset$3($Class* clazz) {
	return $of($alloc(Charset$3));
}

void Charset$3::init$() {
}

$Object* Charset$3::run() {
	$useLocalCurrentObjectStackCache();
	$var($TreeMap, m, $new($TreeMap, $String::CASE_INSENSITIVE_ORDER));
	$init($Charset);
	$Charset::put($($nc($Charset::standardProvider)->charsets()), static_cast<$Map*>(static_cast<$AbstractMap*>(m)));
	$init($Charset$ExtendedProviderHolder);
	$var($CharsetProviderArray, ecps, $Charset$ExtendedProviderHolder::extendedProviders$);
	{
		$var($CharsetProviderArray, arr$, ecps);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($CharsetProvider, ecp, arr$->get(i$));
			{
				$Charset::put($($nc(ecp)->charsets()), static_cast<$Map*>(static_cast<$AbstractMap*>(m)));
			}
		}
	}
	{
		$var($Iterator, i, $Charset::providers());
		for (; $nc(i)->hasNext();) {
			$var($CharsetProvider, cp, $cast($CharsetProvider, i->next()));
			$Charset::put($($nc(cp)->charsets()), static_cast<$Map*>(static_cast<$AbstractMap*>(m)));
		}
	}
	return $of($Collections::unmodifiableSortedMap(m));
}

Charset$3::Charset$3() {
}

$Class* Charset$3::load$($String* name, bool initialize) {
	$loadClass(Charset$3, name, initialize, &_Charset$3_ClassInfo_, allocate$Charset$3);
	return class$;
}

$Class* Charset$3::class$ = nullptr;

		} // charset
	} // nio
} // java