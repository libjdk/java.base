#include <sun/security/ssl/ExtendedMasterSecretExtension$ExtendedMasterSecretSpec.h>

#include <java/nio/ByteBuffer.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/ExtendedMasterSecretExtension.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef DECODE_ERROR
#undef NOMINAL

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

$FieldInfo _ExtendedMasterSecretExtension$ExtendedMasterSecretSpec_FieldInfo_[] = {
	{"NOMINAL", "Lsun/security/ssl/ExtendedMasterSecretExtension$ExtendedMasterSecretSpec;", nullptr, $STATIC | $FINAL, $staticField(ExtendedMasterSecretExtension$ExtendedMasterSecretSpec, NOMINAL)},
	{}
};

$MethodInfo _ExtendedMasterSecretExtension$ExtendedMasterSecretSpec_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ExtendedMasterSecretExtension$ExtendedMasterSecretSpec, init$, void)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(ExtendedMasterSecretExtension$ExtendedMasterSecretSpec, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ExtendedMasterSecretExtension$ExtendedMasterSecretSpec, toString, $String*)},
	{}
};

$InnerClassInfo _ExtendedMasterSecretExtension$ExtendedMasterSecretSpec_InnerClassesInfo_[] = {
	{"sun.security.ssl.ExtendedMasterSecretExtension$ExtendedMasterSecretSpec", "sun.security.ssl.ExtendedMasterSecretExtension", "ExtendedMasterSecretSpec", $STATIC | $FINAL},
	{"sun.security.ssl.SSLExtension$SSLExtensionSpec", "sun.security.ssl.SSLExtension", "SSLExtensionSpec", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ExtendedMasterSecretExtension$ExtendedMasterSecretSpec_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.ExtendedMasterSecretExtension$ExtendedMasterSecretSpec",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$SSLExtensionSpec",
	_ExtendedMasterSecretExtension$ExtendedMasterSecretSpec_FieldInfo_,
	_ExtendedMasterSecretExtension$ExtendedMasterSecretSpec_MethodInfo_,
	nullptr,
	nullptr,
	_ExtendedMasterSecretExtension$ExtendedMasterSecretSpec_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.ExtendedMasterSecretExtension"
};

$Object* allocate$ExtendedMasterSecretExtension$ExtendedMasterSecretSpec($Class* clazz) {
	return $of($alloc(ExtendedMasterSecretExtension$ExtendedMasterSecretSpec));
}

ExtendedMasterSecretExtension$ExtendedMasterSecretSpec* ExtendedMasterSecretExtension$ExtendedMasterSecretSpec::NOMINAL = nullptr;

void ExtendedMasterSecretExtension$ExtendedMasterSecretSpec::init$() {
}

void ExtendedMasterSecretExtension$ExtendedMasterSecretSpec::init$($HandshakeContext* hc, $ByteBuffer* m) {
	$useLocalCurrentObjectStackCache();
	if ($nc(m)->hasRemaining()) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, "Invalid extended_master_secret extension data: not empty"_s)))));
	}
}

$String* ExtendedMasterSecretExtension$ExtendedMasterSecretSpec::toString() {
	return "<empty>"_s;
}

void clinit$ExtendedMasterSecretExtension$ExtendedMasterSecretSpec($Class* class$) {
	$assignStatic(ExtendedMasterSecretExtension$ExtendedMasterSecretSpec::NOMINAL, $new(ExtendedMasterSecretExtension$ExtendedMasterSecretSpec));
}

ExtendedMasterSecretExtension$ExtendedMasterSecretSpec::ExtendedMasterSecretExtension$ExtendedMasterSecretSpec() {
}

$Class* ExtendedMasterSecretExtension$ExtendedMasterSecretSpec::load$($String* name, bool initialize) {
	$loadClass(ExtendedMasterSecretExtension$ExtendedMasterSecretSpec, name, initialize, &_ExtendedMasterSecretExtension$ExtendedMasterSecretSpec_ClassInfo_, clinit$ExtendedMasterSecretExtension$ExtendedMasterSecretSpec, allocate$ExtendedMasterSecretExtension$ExtendedMasterSecretSpec);
	return class$;
}

$Class* ExtendedMasterSecretExtension$ExtendedMasterSecretSpec::class$ = nullptr;

		} // ssl
	} // security
} // sun