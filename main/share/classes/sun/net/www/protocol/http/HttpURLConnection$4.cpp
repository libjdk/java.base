#include <sun/net/www/protocol/http/HttpURLConnection$4.h>

#include <java/lang/SecurityException.h>
#include <java/net/InetAddress.h>
#include <java/net/UnknownHostException.h>
#include <sun/net/www/protocol/http/HttpURLConnection.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $InetAddress = ::java::net::InetAddress;
using $UnknownHostException = ::java::net::UnknownHostException;

namespace sun {
	namespace net {
		namespace www {
			namespace protocol {
				namespace http {

$FieldInfo _HttpURLConnection$4_FieldInfo_[] = {
	{"val$result", "[Z", nullptr, $FINAL | $SYNTHETIC, $field(HttpURLConnection$4, val$result)},
	{"val$h2", "Ljava/lang/String;", nullptr, $FINAL | $SYNTHETIC, $field(HttpURLConnection$4, val$h2)},
	{"val$h1", "Ljava/lang/String;", nullptr, $FINAL | $SYNTHETIC, $field(HttpURLConnection$4, val$h1)},
	{}
};

$MethodInfo _HttpURLConnection$4_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;[Z)V", nullptr, 0, $method(HttpURLConnection$4, init$, void, $String*, $String*, $booleans*)},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection$4, run, $Object*)},
	{}
};

$EnclosingMethodInfo _HttpURLConnection$4_EnclosingMethodInfo_ = {
	"sun.net.www.protocol.http.HttpURLConnection",
	"hostsEqual",
	"(Ljava/net/URL;Ljava/net/URL;)Z"
};

$InnerClassInfo _HttpURLConnection$4_InnerClassesInfo_[] = {
	{"sun.net.www.protocol.http.HttpURLConnection$4", nullptr, nullptr, 0},
	{}
};

$ClassInfo _HttpURLConnection$4_ClassInfo_ = {
	$ACC_SUPER,
	"sun.net.www.protocol.http.HttpURLConnection$4",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_HttpURLConnection$4_FieldInfo_,
	_HttpURLConnection$4_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Object;>;",
	&_HttpURLConnection$4_EnclosingMethodInfo_,
	_HttpURLConnection$4_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.net.www.protocol.http.HttpURLConnection"
};

$Object* allocate$HttpURLConnection$4($Class* clazz) {
	return $of($alloc(HttpURLConnection$4));
}

void HttpURLConnection$4::init$($String* val$h1, $String* val$h2, $booleans* val$result) {
	$set(this, val$h1, val$h1);
	$set(this, val$h2, val$h2);
	$set(this, val$result, val$result);
}

$Object* HttpURLConnection$4::run() {
	$useLocalCurrentObjectStackCache();
	try {
		$var($InetAddress, a1, $InetAddress::getByName(this->val$h1));
		$var($InetAddress, a2, $InetAddress::getByName(this->val$h2));
		$nc(this->val$result)->set(0, $nc(a1)->equals(a2));
	} catch ($UnknownHostException& e) {
	} catch ($SecurityException& e) {
	}
	return $of(nullptr);
}

HttpURLConnection$4::HttpURLConnection$4() {
}

$Class* HttpURLConnection$4::load$($String* name, bool initialize) {
	$loadClass(HttpURLConnection$4, name, initialize, &_HttpURLConnection$4_ClassInfo_, allocate$HttpURLConnection$4);
	return class$;
}

$Class* HttpURLConnection$4::class$ = nullptr;

				} // http
			} // protocol
		} // www
	} // net
} // sun