#include <textToNumericFormat.h>

#include <java/net/InetAddress.h>
#include <java/net/UnknownHostException.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $InetAddress = ::java::net::InetAddress;
using $UnknownHostException = ::java::net::UnknownHostException;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;

$MethodInfo _textToNumericFormat_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(textToNumericFormat, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(textToNumericFormat, main, void, $StringArray*), "java.net.UnknownHostException"},
	{}
};

$ClassInfo _textToNumericFormat_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"textToNumericFormat",
	"java.lang.Object",
	nullptr,
	nullptr,
	_textToNumericFormat_MethodInfo_
};

$Object* allocate$textToNumericFormat($Class* clazz) {
	return $of($alloc(textToNumericFormat));
}

void textToNumericFormat::init$() {
}

void textToNumericFormat::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($List, goodList, $new($ArrayList));
	$var($List, badList, $new($ArrayList));
	$var($StringArray, goodAddrs, $new($StringArray, {
		"224.0.1.0"_s,
		"238.255.255.255"_s,
		"239.255.255.255"_s,
		"239.255.65535"_s,
		"239.16777215"_s,
		"4294967295"_s
	}));
	$var($StringArray, badAddrs, $new($StringArray, {
		"238.255.255.2550"_s,
		"256.255.255.255"_s,
		"238.255.2550.255"_s,
		"238.2550.255.255"_s,
		"2380.255.255.255"_s,
		"239.255.65536"_s,
		"239.16777216"_s,
		"4294967296"_s,
		".1.1.1"_s,
		"1..1.1"_s,
		"1.1.1."_s,
		"..."_s
	}));
	for (int32_t i = 0; i < goodAddrs->length; ++i) {
		try {
			$var($InetAddress, ia, $InetAddress::getByName(goodAddrs->get(i)));
		} catch ($UnknownHostException& e) {
			goodList->add(goodAddrs->get(i));
		}
	}
	for (int32_t i = 0; i < badAddrs->length; ++i) {
		try {
			$var($InetAddress, ia, $InetAddress::getByName(badAddrs->get(i)));
			badList->add(badAddrs->get(i));
		} catch ($UnknownHostException& e) {
		}
	}
	bool var$0 = goodList->size() > 0;
	if (var$0 || badList->size() > 0) {
		$var($String, var$1, (goodList->size() > 0 ? ($$str({"Good address not parsed: "_s, goodList})) : ""_s));
		$throwNew($RuntimeException, $$concat(var$1, (badList->size() > 0 ? ($$str({"Bad Address parsed: "_s, badList})) : ""_s)));
	}
}

textToNumericFormat::textToNumericFormat() {
}

$Class* textToNumericFormat::load$($String* name, bool initialize) {
	$loadClass(textToNumericFormat, name, initialize, &_textToNumericFormat_ClassInfo_, allocate$textToNumericFormat);
	return class$;
}

$Class* textToNumericFormat::class$ = nullptr;