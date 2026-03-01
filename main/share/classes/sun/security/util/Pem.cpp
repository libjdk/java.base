#include <sun/security/util/Pem.h>

#include <java/io/IOException.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/util/Base64$Decoder.h>
#include <java/util/Base64.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $Base64 = ::java::util::Base64;
using $Base64$Decoder = ::java::util::Base64$Decoder;

namespace sun {
	namespace security {
		namespace util {

$MethodInfo _Pem_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Pem, init$, void)},
	{"decode", "(Ljava/lang/String;)[B", nullptr, $PUBLIC | $STATIC, $staticMethod(Pem, decode, $bytes*, $String*), "java.io.IOException"},
	{}
};

$ClassInfo _Pem_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.util.Pem",
	"java.lang.Object",
	nullptr,
	nullptr,
	_Pem_MethodInfo_
};

$Object* allocate$Pem($Class* clazz) {
	return $of($alloc(Pem));
}

void Pem::init$() {
}

$bytes* Pem::decode($String* input) {
	$useLocalCurrentObjectStackCache();
	$init($StandardCharsets);
	$var($bytes, src, $($nc(input)->replaceAll("\\s+"_s, ""_s))->getBytes($StandardCharsets::ISO_8859_1));
	try {
		return $nc($($Base64::getDecoder()))->decode(src);
	} catch ($IllegalArgumentException& e) {
		$throwNew($IOException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

Pem::Pem() {
}

$Class* Pem::load$($String* name, bool initialize) {
	$loadClass(Pem, name, initialize, &_Pem_ClassInfo_, allocate$Pem);
	return class$;
}

$Class* Pem::class$ = nullptr;

		} // util
	} // security
} // sun