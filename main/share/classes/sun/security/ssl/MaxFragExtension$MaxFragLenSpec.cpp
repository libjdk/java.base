#include <sun/security/ssl/MaxFragExtension$MaxFragLenSpec.h>

#include <java/nio/ByteBuffer.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/MaxFragExtension$MaxFragLenEnum.h>
#include <sun/security/ssl/MaxFragExtension.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef DECODE_ERROR

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $SSLProtocolException = ::javax::net::ssl::SSLProtocolException;
using $Alert = ::sun::security::ssl::Alert;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $MaxFragExtension$MaxFragLenEnum = ::sun::security::ssl::MaxFragExtension$MaxFragLenEnum;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _MaxFragExtension$MaxFragLenSpec_FieldInfo_[] = {
	{"id", "B", nullptr, 0, $field(MaxFragExtension$MaxFragLenSpec, id)},
	{}
};

$MethodInfo _MaxFragExtension$MaxFragLenSpec_MethodInfo_[] = {
	{"<init>", "(B)V", nullptr, $PRIVATE, $method(MaxFragExtension$MaxFragLenSpec, init$, void, int8_t)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(MaxFragExtension$MaxFragLenSpec, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(MaxFragExtension$MaxFragLenSpec, toString, $String*)},
	{}
};

$InnerClassInfo _MaxFragExtension$MaxFragLenSpec_InnerClassesInfo_[] = {
	{"sun.security.ssl.MaxFragExtension$MaxFragLenSpec", "sun.security.ssl.MaxFragExtension", "MaxFragLenSpec", $STATIC | $FINAL},
	{"sun.security.ssl.SSLExtension$SSLExtensionSpec", "sun.security.ssl.SSLExtension", "SSLExtensionSpec", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _MaxFragExtension$MaxFragLenSpec_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.MaxFragExtension$MaxFragLenSpec",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$SSLExtensionSpec",
	_MaxFragExtension$MaxFragLenSpec_FieldInfo_,
	_MaxFragExtension$MaxFragLenSpec_MethodInfo_,
	nullptr,
	nullptr,
	_MaxFragExtension$MaxFragLenSpec_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.MaxFragExtension"
};

$Object* allocate$MaxFragExtension$MaxFragLenSpec($Class* clazz) {
	return $of($alloc(MaxFragExtension$MaxFragLenSpec));
}

void MaxFragExtension$MaxFragLenSpec::init$(int8_t id) {
	this->id = id;
}

void MaxFragExtension$MaxFragLenSpec::init$($HandshakeContext* hc, $ByteBuffer* buffer) {
	$useLocalCurrentObjectStackCache();
	if ($nc(buffer)->remaining() != 1) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, "Invalid max_fragment_length extension data"_s)))));
	}
	this->id = $nc(buffer)->get();
}

$String* MaxFragExtension$MaxFragLenSpec::toString() {
	return $MaxFragExtension$MaxFragLenEnum::nameOf(this->id);
}

MaxFragExtension$MaxFragLenSpec::MaxFragExtension$MaxFragLenSpec() {
}

$Class* MaxFragExtension$MaxFragLenSpec::load$($String* name, bool initialize) {
	$loadClass(MaxFragExtension$MaxFragLenSpec, name, initialize, &_MaxFragExtension$MaxFragLenSpec_ClassInfo_, allocate$MaxFragExtension$MaxFragLenSpec);
	return class$;
}

$Class* MaxFragExtension$MaxFragLenSpec::class$ = nullptr;

		} // ssl
	} // security
} // sun