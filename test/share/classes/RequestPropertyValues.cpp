#include <RequestPropertyValues.h>

#include <RequestPropertyValues$DummyURLConnection.h>
#include <java/net/MalformedURLException.h>
#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jcpp.h>

using $RequestPropertyValues$DummyURLConnection = ::RequestPropertyValues$DummyURLConnection;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URL = ::java::net::URL;
using $URLConnection = ::java::net::URLConnection;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;

$MethodInfo _RequestPropertyValues_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(RequestPropertyValues, init$, void)},
	{"getConnection", "(Ljava/net/URL;)Ljava/net/URLConnection;", nullptr, $STATIC, $staticMethod(RequestPropertyValues, getConnection, $URLConnection*, $URL*)},
	{"hasFtp", "()Z", nullptr, $PRIVATE | $STATIC, $staticMethod(RequestPropertyValues, hasFtp, bool)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(RequestPropertyValues, main, void, $StringArray*), "java.lang.Exception"},
	{"part1", "()V", nullptr, $PUBLIC | $STATIC, $staticMethod(RequestPropertyValues, part1, void), "java.lang.Exception"},
	{"part2", "()V", nullptr, $PUBLIC | $STATIC, $staticMethod(RequestPropertyValues, part2, void), "java.lang.Exception"},
	{}
};

$InnerClassInfo _RequestPropertyValues_InnerClassesInfo_[] = {
	{"RequestPropertyValues$DummyURLConnection", "RequestPropertyValues", "DummyURLConnection", $STATIC},
	{}
};

$ClassInfo _RequestPropertyValues_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"RequestPropertyValues",
	"java.lang.Object",
	nullptr,
	nullptr,
	_RequestPropertyValues_MethodInfo_,
	nullptr,
	nullptr,
	_RequestPropertyValues_InnerClassesInfo_,
	nullptr,
	nullptr,
	"RequestPropertyValues$DummyURLConnection"
};

$Object* allocate$RequestPropertyValues($Class* clazz) {
	return $of($alloc(RequestPropertyValues));
}

void RequestPropertyValues::init$() {
}

void RequestPropertyValues::main($StringArray* args) {
	part1();
	part2();
}

void RequestPropertyValues::part1() {
	$useLocalCurrentObjectStackCache();
	$var($List, urls, $new($ArrayList));
	urls->add($$new($URL, "http://localhost:8088"_s));
	urls->add($$new($URL, "file:/etc/passwd"_s));
	urls->add($$new($URL, "jar:http://foo.com/bar.html!/foo/bar"_s));
	if (hasFtp()) {
		urls->add($$new($URL, "ftp://foo:bar@foobar.com/etc/passwd"_s));
	}
	bool failed = false;
	{
		$var($Iterator, i$, urls->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($URL, url, $cast($URL, i$->next()));
			{
				$var($URLConnection, uc, $nc(url)->openConnection());
				try {
					$nc(uc)->setRequestProperty("TestHeader"_s, nullptr);
				} catch ($NullPointerException& npe) {
					$nc($System::out)->println($$str({"setRequestProperty is throwing NPE for url: "_s, url}));
					failed = true;
				}
				try {
					$nc(uc)->addRequestProperty("TestHeader"_s, nullptr);
				} catch ($NullPointerException& npe) {
					$nc($System::out)->println($$str({"addRequestProperty is throwing NPE for url: "_s, url}));
					failed = true;
				}
			}
		}
	}
	if (failed) {
		$throwNew($Exception, "RequestProperty setting/adding is throwing NPE for null values"_s);
	}
}

void RequestPropertyValues::part2() {
	$useLocalCurrentObjectStackCache();
	$var($URL, url, nullptr);
	$var($StringArray, goodKeys, $new($StringArray, {
		""_s,
		"$"_s,
		"key"_s,
		"Key"_s,
		" "_s,
		"    "_s
	}));
	$var($StringArray, goodValues, $new($StringArray, {
		""_s,
		"$"_s,
		"value"_s,
		"Value"_s,
		" "_s,
		"    "_s
	}));
	$var($URLConnection, conn, getConnection(url));
	for (int32_t i = 0; i < goodKeys->length; ++i) {
		for (int32_t j = 0; j < goodValues->length; ++j) {
			$nc(conn)->setRequestProperty(goodKeys->get(i), goodValues->get(j));
			$var($String, value, conn->getRequestProperty(goodKeys->get(i)));
			if (!((goodValues->get(j) == nullptr && value == nullptr) || (value != nullptr && value->equals(goodValues->get(j))))) {
				$throwNew($RuntimeException, "Method setRequestProperty(String,String) works incorrectly"_s);
			}
		}
	}
}

$URLConnection* RequestPropertyValues::getConnection($URL* url) {
	return $new($RequestPropertyValues$DummyURLConnection, url);
}

bool RequestPropertyValues::hasFtp() {
	try {
		return $new($URL, "ftp://"_s) != nullptr;
	} catch ($MalformedURLException& x) {
		$nc($System::out)->println("FTP not supported by this runtime."_s);
		return false;
	}
	$shouldNotReachHere();
}

RequestPropertyValues::RequestPropertyValues() {
}

$Class* RequestPropertyValues::load$($String* name, bool initialize) {
	$loadClass(RequestPropertyValues, name, initialize, &_RequestPropertyValues_ClassInfo_, allocate$RequestPropertyValues);
	return class$;
}

$Class* RequestPropertyValues::class$ = nullptr;