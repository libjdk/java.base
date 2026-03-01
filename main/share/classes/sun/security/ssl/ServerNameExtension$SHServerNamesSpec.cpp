#include <sun/security/ssl/ServerNameExtension$SHServerNamesSpec.h>

#include <java/nio/ByteBuffer.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/ServerNameExtension.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef DECODE_ERROR
#undef DEFAULT

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $SSLProtocolException = ::javax::net::ssl::SSLProtocolException;
using $Alert = ::sun::security::ssl::Alert;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _ServerNameExtension$SHServerNamesSpec_FieldInfo_[] = {
	{"DEFAULT", "Lsun/security/ssl/ServerNameExtension$SHServerNamesSpec;", nullptr, $STATIC | $FINAL, $staticField(ServerNameExtension$SHServerNamesSpec, DEFAULT)},
	{}
};

$MethodInfo _ServerNameExtension$SHServerNamesSpec_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ServerNameExtension$SHServerNamesSpec, init$, void)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(ServerNameExtension$SHServerNamesSpec, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ServerNameExtension$SHServerNamesSpec, toString, $String*)},
	{}
};

$InnerClassInfo _ServerNameExtension$SHServerNamesSpec_InnerClassesInfo_[] = {
	{"sun.security.ssl.ServerNameExtension$SHServerNamesSpec", "sun.security.ssl.ServerNameExtension", "SHServerNamesSpec", $STATIC | $FINAL},
	{"sun.security.ssl.SSLExtension$SSLExtensionSpec", "sun.security.ssl.SSLExtension", "SSLExtensionSpec", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ServerNameExtension$SHServerNamesSpec_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.ServerNameExtension$SHServerNamesSpec",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$SSLExtensionSpec",
	_ServerNameExtension$SHServerNamesSpec_FieldInfo_,
	_ServerNameExtension$SHServerNamesSpec_MethodInfo_,
	nullptr,
	nullptr,
	_ServerNameExtension$SHServerNamesSpec_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.ServerNameExtension"
};

$Object* allocate$ServerNameExtension$SHServerNamesSpec($Class* clazz) {
	return $of($alloc(ServerNameExtension$SHServerNamesSpec));
}

ServerNameExtension$SHServerNamesSpec* ServerNameExtension$SHServerNamesSpec::DEFAULT = nullptr;

void ServerNameExtension$SHServerNamesSpec::init$() {
}

void ServerNameExtension$SHServerNamesSpec::init$($HandshakeContext* hc, $ByteBuffer* buffer) {
	$useLocalCurrentObjectStackCache();
	if ($nc(buffer)->remaining() != 0) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, "Invalid ServerHello server_name extension: not empty"_s)))));
	}
}

$String* ServerNameExtension$SHServerNamesSpec::toString() {
	return "<empty extension_data field>"_s;
}

void clinit$ServerNameExtension$SHServerNamesSpec($Class* class$) {
	$assignStatic(ServerNameExtension$SHServerNamesSpec::DEFAULT, $new(ServerNameExtension$SHServerNamesSpec));
}

ServerNameExtension$SHServerNamesSpec::ServerNameExtension$SHServerNamesSpec() {
}

$Class* ServerNameExtension$SHServerNamesSpec::load$($String* name, bool initialize) {
	$loadClass(ServerNameExtension$SHServerNamesSpec, name, initialize, &_ServerNameExtension$SHServerNamesSpec_ClassInfo_, clinit$ServerNameExtension$SHServerNamesSpec, allocate$ServerNameExtension$SHServerNamesSpec);
	return class$;
}

$Class* ServerNameExtension$SHServerNamesSpec::class$ = nullptr;

		} // ssl
	} // security
} // sun