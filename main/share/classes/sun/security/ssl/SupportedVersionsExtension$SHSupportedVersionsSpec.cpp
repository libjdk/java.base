#include <sun/security/ssl/SupportedVersionsExtension$SHSupportedVersionsSpec.h>

#include <java/nio/ByteBuffer.h>
#include <java/text/MessageFormat.h>
#include <java/util/Locale.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SupportedVersionsExtension.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef DECODE_ERROR
#undef ENGLISH

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $MessageFormat = ::java::text::MessageFormat;
using $Locale = ::java::util::Locale;
using $SSLProtocolException = ::javax::net::ssl::SSLProtocolException;
using $Alert = ::sun::security::ssl::Alert;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SupportedVersionsExtension$SHSupportedVersionsSpec_FieldInfo_[] = {
	{"selectedVersion", "I", nullptr, $FINAL, $field(SupportedVersionsExtension$SHSupportedVersionsSpec, selectedVersion)},
	{}
};

$MethodInfo _SupportedVersionsExtension$SHSupportedVersionsSpec_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/ProtocolVersion;)V", nullptr, $PRIVATE, $method(SupportedVersionsExtension$SHSupportedVersionsSpec, init$, void, $ProtocolVersion*)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(SupportedVersionsExtension$SHSupportedVersionsSpec, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SupportedVersionsExtension$SHSupportedVersionsSpec, toString, $String*)},
	{}
};

$InnerClassInfo _SupportedVersionsExtension$SHSupportedVersionsSpec_InnerClassesInfo_[] = {
	{"sun.security.ssl.SupportedVersionsExtension$SHSupportedVersionsSpec", "sun.security.ssl.SupportedVersionsExtension", "SHSupportedVersionsSpec", $STATIC | $FINAL},
	{"sun.security.ssl.SSLExtension$SSLExtensionSpec", "sun.security.ssl.SSLExtension", "SSLExtensionSpec", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SupportedVersionsExtension$SHSupportedVersionsSpec_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SupportedVersionsExtension$SHSupportedVersionsSpec",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$SSLExtensionSpec",
	_SupportedVersionsExtension$SHSupportedVersionsSpec_FieldInfo_,
	_SupportedVersionsExtension$SHSupportedVersionsSpec_MethodInfo_,
	nullptr,
	nullptr,
	_SupportedVersionsExtension$SHSupportedVersionsSpec_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SupportedVersionsExtension"
};

$Object* allocate$SupportedVersionsExtension$SHSupportedVersionsSpec($Class* clazz) {
	return $of($alloc(SupportedVersionsExtension$SHSupportedVersionsSpec));
}

void SupportedVersionsExtension$SHSupportedVersionsSpec::init$($ProtocolVersion* selectedVersion) {
	this->selectedVersion = $nc(selectedVersion)->id;
}

void SupportedVersionsExtension$SHSupportedVersionsSpec::init$($HandshakeContext* hc, $ByteBuffer* m) {
	$useLocalCurrentObjectStackCache();
	if ($nc(m)->remaining() != 2) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, "Invalid supported_versions: insufficient data"_s)))));
	}
	int8_t major = $nc(m)->get();
	int8_t minor = m->get();
	this->selectedVersion = (((int32_t)(major & (uint32_t)255)) << 8) | ((int32_t)(minor & (uint32_t)255));
}

$String* SupportedVersionsExtension$SHSupportedVersionsSpec::toString() {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($MessageFormat, messageFormat, $new($MessageFormat, "\"selected version\": \'[\'{0}\']\'"_s, $Locale::ENGLISH));
	$var($ObjectArray, messageFields, $new($ObjectArray, {$($of($ProtocolVersion::nameOf(this->selectedVersion)))}));
	return messageFormat->format(messageFields);
}

SupportedVersionsExtension$SHSupportedVersionsSpec::SupportedVersionsExtension$SHSupportedVersionsSpec() {
}

$Class* SupportedVersionsExtension$SHSupportedVersionsSpec::load$($String* name, bool initialize) {
	$loadClass(SupportedVersionsExtension$SHSupportedVersionsSpec, name, initialize, &_SupportedVersionsExtension$SHSupportedVersionsSpec_ClassInfo_, allocate$SupportedVersionsExtension$SHSupportedVersionsSpec);
	return class$;
}

$Class* SupportedVersionsExtension$SHSupportedVersionsSpec::class$ = nullptr;

		} // ssl
	} // security
} // sun