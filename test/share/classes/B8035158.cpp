#include <B8035158.h>

#include <B8035158$TestCase.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Properties.h>
#include <java/util/Set.h>
#include <java/util/concurrent/Callable.h>
#include <jcpp.h>

using $B8035158$TestCase = ::B8035158$TestCase;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Properties = ::java::util::Properties;
using $Set = ::java::util::Set;
using $Callable = ::java::util::concurrent::Callable;

$MethodInfo _B8035158_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(B8035158, init$, void)},
	{"backupAndSetProperties", "(Ljava/util/Map;Ljava/util/Map;)V", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)V", $PRIVATE | $STATIC, $staticMethod(B8035158, backupAndSetProperties, void, $Map*, $Map*)},
	{"emptyNonProxiesHosts", "()Ljava/util/Collection;", "()Ljava/util/Collection<LB8035158$TestCase;>;", $PRIVATE | $STATIC, $staticMethod(B8035158, emptyNonProxiesHosts, $Collection*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(B8035158, main, void, $StringArray*)},
	{"misc", "()Ljava/util/Collection;", "()Ljava/util/Collection<LB8035158$TestCase;>;", $PRIVATE | $STATIC, $staticMethod(B8035158, misc, $Collection*)},
	{"nonEmptyNonProxiesHosts", "()Ljava/util/Collection;", "()Ljava/util/Collection<LB8035158$TestCase;>;", $PRIVATE | $STATIC, $staticMethod(B8035158, nonEmptyNonProxiesHosts, $Collection*)},
	{"restoreProperties", "(Ljava/util/Map;)V", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)V", $PRIVATE | $STATIC, $staticMethod(B8035158, restoreProperties, void, $Map*)},
	{"withSystemPropertiesSet", "(Ljava/util/Map;Ljava/util/concurrent/Callable;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;Ljava/util/concurrent/Callable<+TT;>;)TT;", $PRIVATE | $STATIC, $staticMethod(B8035158, withSystemPropertiesSet, $Object*, $Map*, $Callable*)},
	{}
};

$InnerClassInfo _B8035158_InnerClassesInfo_[] = {
	{"B8035158$TestCase", "B8035158", "TestCase", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _B8035158_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"B8035158",
	"java.lang.Object",
	nullptr,
	nullptr,
	_B8035158_MethodInfo_,
	nullptr,
	nullptr,
	_B8035158_InnerClassesInfo_,
	nullptr,
	nullptr,
	"B8035158$TestCase,B8035158$TestCase$1"
};

$Object* allocate$B8035158($Class* clazz) {
	return $of($alloc(B8035158));
}

void B8035158::init$() {
}

void B8035158::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($(emptyNonProxiesHosts()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($B8035158$TestCase, t, $cast($B8035158$TestCase, i$->next()));
			$nc(t)->run();
		}
	}
	{
		$var($Iterator, i$, $nc($(nonEmptyNonProxiesHosts()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($B8035158$TestCase, t, $cast($B8035158$TestCase, i$->next()));
			$nc(t)->run();
		}
	}
	{
		$var($Iterator, i$, $nc($(misc()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($B8035158$TestCase, t, $cast($B8035158$TestCase, i$->next()));
			$nc(t)->run();
		}
	}
}

$Collection* B8035158::emptyNonProxiesHosts() {
	$useLocalCurrentObjectStackCache();
	$var($List, tests, $new($LinkedList));
	$var($StringArray, loopbacks, $new($StringArray, {
		"localhost"_s,
		"[::1]"_s,
		"[::0]"_s,
		"0.0.0.0"_s,
		"127.0.0.0"_s,
		"127.0.0.1"_s,
		"127.0.1.0"_s,
		"127.0.1.1"_s,
		"127.1.0.0"_s,
		"127.1.0.1"_s,
		"127.1.1.0"_s,
		"127.1.1.1"_s
	}));
	$var($Map, properties, $new($HashMap));
	properties->put("http.proxyHost"_s, "http://proxy.example.com"_s);
	properties->put("http.nonProxyHosts"_s, ""_s);
	{
		$var($StringArray, arr$, loopbacks);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, s, arr$->get(i$));
			{
				tests->add($$new($B8035158$TestCase, properties, $$str({"http://"_s, s}), true));
			}
		}
	}
	return tests;
}

$Collection* B8035158::nonEmptyNonProxiesHosts() {
	$useLocalCurrentObjectStackCache();
	$var($List, tests, $new($LinkedList));
	$var($StringArray, nonProxyHosts, $new($StringArray, {
		"google.com"_s,
		"localhost"_s,
		"[::1]"_s,
		"[::0]"_s,
		"0.0.0.0"_s,
		"127.0.0.0"_s,
		"127.0.0.1"_s,
		"127.0.1.0"_s,
		"127.0.1.1"_s,
		"127.1.0.0"_s,
		"127.1.0.1"_s,
		"127.1.1.0"_s,
		"127.1.1.1"_s
	}));
	$var($StringArray, loopbacks, $new($StringArray, {
		"localhost"_s,
		"[::1]"_s,
		"[::0]"_s,
		"0.0.0.0"_s,
		"127.0.0.0"_s,
		"127.0.0.1"_s,
		"127.0.1.0"_s,
		"127.0.1.1"_s,
		"127.1.0.0"_s,
		"127.1.0.1"_s,
		"127.1.1.0"_s,
		"127.1.1.1"_s
	}));
	{
		$var($StringArray, arr$, nonProxyHosts);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, h, arr$->get(i$));
			{
				{
					$var($StringArray, arr$, loopbacks);
					int32_t len$ = arr$->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($String, s, arr$->get(i$));
						{
							$var($Map, properties, $new($HashMap));
							properties->put("http.proxyHost"_s, "http://proxy.example.com"_s);
							properties->put("http.nonProxyHosts"_s, h);
							tests->add($$new($B8035158$TestCase, properties, $$str({"http://"_s, s}), false));
						}
					}
				}
			}
		}
	}
	return tests;
}

$Collection* B8035158::misc() {
	$useLocalCurrentObjectStackCache();
	$var($List, t, $new($LinkedList));
	t->add($$new($B8035158$TestCase, "oracle.com"_s, "http://137.254.16.101"_s, true));
	t->add($$new($B8035158$TestCase, "google.com"_s, "http://74.125.200.101"_s, true));
	t->add($$new($B8035158$TestCase, "google.com|google.ie"_s, "http://google.co.uk"_s, true));
	t->add($$new($B8035158$TestCase, "google.com|google.ie"_s, "http://google.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.com|google.ie"_s, "http://google.ie"_s, false));
	t->add($$new($B8035158$TestCase, "google.com|google.com|google.ie"_s, "http://google.ie"_s, false));
	t->add($$new($B8035158$TestCase, "google.com|bing.com|yahoo.com"_s, "http://127.0.0.1"_s, false));
	t->add($$new($B8035158$TestCase, "google.com|bing.com|yahoo.com"_s, "http://google.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.com|bing.com|yahoo.com"_s, "http://bing.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.com|bing.com|yahoo.com"_s, "http://yahoo.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.com|bing.com"_s, "http://google.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.com|bing.com"_s, "http://bing.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.com|bing.com"_s, "http://yahoo.com"_s, true));
	t->add($$new($B8035158$TestCase, "google.com|bing.co*"_s, "http://google.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.com|bing.co*"_s, "http://bing.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.com|bing.co*"_s, "http://yahoo.com"_s, true));
	t->add($$new($B8035158$TestCase, "google.com|*ing.com"_s, "http://google.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.com|*ing.com"_s, "http://bing.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.com|*ing.com"_s, "http://yahoo.com"_s, true));
	t->add($$new($B8035158$TestCase, "google.co*|bing.com"_s, "http://google.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.co*|bing.com"_s, "http://bing.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.co*|bing.com"_s, "http://yahoo.com"_s, true));
	t->add($$new($B8035158$TestCase, "google.co*|bing.co*"_s, "http://google.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.co*|bing.co*"_s, "http://bing.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.co*|bing.co*"_s, "http://yahoo.com"_s, true));
	t->add($$new($B8035158$TestCase, "google.co*|*ing.com"_s, "http://google.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.co*|*ing.com"_s, "http://bing.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.co*|*ing.com"_s, "http://yahoo.com"_s, true));
	t->add($$new($B8035158$TestCase, "*oogle.com|bing.com"_s, "http://google.com"_s, false));
	t->add($$new($B8035158$TestCase, "*oogle.com|bing.com"_s, "http://bing.com"_s, false));
	t->add($$new($B8035158$TestCase, "*oogle.com|bing.com"_s, "http://yahoo.com"_s, true));
	t->add($$new($B8035158$TestCase, "*oogle.com|bing.co*"_s, "http://google.com"_s, false));
	t->add($$new($B8035158$TestCase, "*oogle.com|bing.co*"_s, "http://bing.com"_s, false));
	t->add($$new($B8035158$TestCase, "*oogle.com|bing.co*"_s, "http://yahoo.com"_s, true));
	t->add($$new($B8035158$TestCase, "*oogle.com|*ing.com"_s, "http://google.com"_s, false));
	t->add($$new($B8035158$TestCase, "*oogle.com|*ing.com"_s, "http://bing.com"_s, false));
	t->add($$new($B8035158$TestCase, "*oogle.com|*ing.com"_s, "http://yahoo.com"_s, true));
	t->add($$new($B8035158$TestCase, "google.com|bing.com|yahoo.com"_s, "http://google.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.com|bing.com|yahoo.com"_s, "http://bing.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.com|bing.com|yahoo.com"_s, "http://yahoo.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.com|bing.com|yahoo.com"_s, "http://duckduckgo.com"_s, true));
	t->add($$new($B8035158$TestCase, "p-proxy.com"_s, "http://p-proxy.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.co*|google.ie"_s, "http://google.co.uk"_s, false));
	t->add($$new($B8035158$TestCase, "*google.*"_s, "http://google.co.uk"_s, false));
	t->add($$new($B8035158$TestCase, "*"_s, "http://google.co.uk"_s, false));
	t->add($$new($B8035158$TestCase, "localhost|*"_s, "http://google.co.uk"_s, false));
	t->add($$new($B8035158$TestCase, "*|oracle.com"_s, "http://google.co.uk"_s, false));
	t->add($$new($B8035158$TestCase, "*|oracle.com|*"_s, "http://google.co.uk"_s, false));
	t->add($$new($B8035158$TestCase, "*|*"_s, "http://google.co.uk"_s, false));
	t->add($$new($B8035158$TestCase, "*oracle.com"_s, "http://my.oracle.com"_s, false));
	t->add($$new($B8035158$TestCase, "google.com|bing.com|yahoo.com"_s, "http://127.0.0.1"_s, false));
	t->add($$new($B8035158$TestCase, "google.com|bing.com|yahoo.com"_s, "http://yahoo.com"_s, false));
	t->add($$new($B8035158$TestCase, "localhost|host.example.com"_s, "http://localhost"_s, false));
	t->add($$new($B8035158$TestCase, "localhost|host.example.com"_s, "http://host.example.com"_s, false));
	t->add($$new($B8035158$TestCase, "localhost|host.example.com"_s, "http://google.com"_s, true));
	return t;
}

$Object* B8035158::withSystemPropertiesSet($Map* localProperties, $Callable* code) {
	$useLocalCurrentObjectStackCache();
	$var($Map, backup, $new($HashMap));
	{
		$var($Throwable, var$0, nullptr);
		$var($Object, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				backupAndSetProperties(localProperties, backup);
				$assign(var$2, $nc(code)->call());
				return$1 = true;
				goto $finally;
			} catch ($Exception& e) {
				$throwNew($RuntimeException, static_cast<$Throwable*>(e));
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			restoreProperties(backup);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void B8035158::backupAndSetProperties($Map* localProperties, $Map* oldProperties) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($($nc(localProperties)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($String, var$0, $cast($String, $nc(e)->getKey()));
				$var($String, oldValue, $System::setProperty(var$0, $cast($String, $(e->getValue()))));
				$nc(oldProperties)->put($cast($String, $($nc(e)->getKey())), oldValue);
			}
		}
	}
}

void B8035158::restoreProperties($Map* oldProperties) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($($nc(oldProperties)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($String, oldValue, $cast($String, $nc(e)->getValue()));
				$var($String, key, $cast($String, e->getKey()));
				if (oldValue == nullptr) {
					$nc($($System::getProperties()))->remove(key);
				} else {
					$System::setProperty(key, oldValue);
				}
			}
		}
	}
}

B8035158::B8035158() {
}

$Class* B8035158::load$($String* name, bool initialize) {
	$loadClass(B8035158, name, initialize, &_B8035158_ClassInfo_, allocate$B8035158);
	return class$;
}

$Class* B8035158::class$ = nullptr;