#include <sun/security/ssl/SupportedVersionsExtension$CHSupportedVersionsSpec.h>

#include <java/nio/ByteBuffer.h>
#include <java/text/MessageFormat.h>
#include <java/util/Locale.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/Record.h>
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
using $Record = ::sun::security::ssl::Record;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SupportedVersionsExtension$CHSupportedVersionsSpec_FieldInfo_[] = {
	{"requestedProtocols", "[I", nullptr, $FINAL, $field(SupportedVersionsExtension$CHSupportedVersionsSpec, requestedProtocols)},
	{}
};

$MethodInfo _SupportedVersionsExtension$CHSupportedVersionsSpec_MethodInfo_[] = {
	{"<init>", "([I)V", nullptr, $PRIVATE, $method(SupportedVersionsExtension$CHSupportedVersionsSpec, init$, void, $ints*)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(SupportedVersionsExtension$CHSupportedVersionsSpec, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SupportedVersionsExtension$CHSupportedVersionsSpec, toString, $String*)},
	{}
};

$InnerClassInfo _SupportedVersionsExtension$CHSupportedVersionsSpec_InnerClassesInfo_[] = {
	{"sun.security.ssl.SupportedVersionsExtension$CHSupportedVersionsSpec", "sun.security.ssl.SupportedVersionsExtension", "CHSupportedVersionsSpec", $STATIC | $FINAL},
	{"sun.security.ssl.SSLExtension$SSLExtensionSpec", "sun.security.ssl.SSLExtension", "SSLExtensionSpec", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SupportedVersionsExtension$CHSupportedVersionsSpec_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SupportedVersionsExtension$CHSupportedVersionsSpec",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$SSLExtensionSpec",
	_SupportedVersionsExtension$CHSupportedVersionsSpec_FieldInfo_,
	_SupportedVersionsExtension$CHSupportedVersionsSpec_MethodInfo_,
	nullptr,
	nullptr,
	_SupportedVersionsExtension$CHSupportedVersionsSpec_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SupportedVersionsExtension"
};

$Object* allocate$SupportedVersionsExtension$CHSupportedVersionsSpec($Class* clazz) {
	return $of($alloc(SupportedVersionsExtension$CHSupportedVersionsSpec));
}

void SupportedVersionsExtension$CHSupportedVersionsSpec::init$($ints* requestedProtocols) {
	$set(this, requestedProtocols, requestedProtocols);
}

void SupportedVersionsExtension$CHSupportedVersionsSpec::init$($HandshakeContext* hc, $ByteBuffer* m) {
	$useLocalCurrentObjectStackCache();
	if ($nc(m)->remaining() < 3) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, "Invalid supported_versions extension: insufficient data"_s)))));
	}
	$var($bytes, vbs, $Record::getBytes8(m));
	if ($nc(m)->hasRemaining()) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, "Invalid supported_versions extension: unknown extra data"_s)))));
	}
	if (vbs == nullptr || $nc(vbs)->length == 0 || ((int32_t)($nc(vbs)->length & (uint32_t)1)) != 0) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, "Invalid supported_versions extension: incomplete data"_s)))));
	}
	$var($ints, protocols, $new($ints, $nc(vbs)->length >> 1));
	{
		int32_t i = 0;
		int32_t j = 0;
		for (; i < vbs->length;) {
			int8_t major = vbs->get(i++);
			int8_t minor = vbs->get(i++);
			protocols->set(j++, (((int32_t)(major & (uint32_t)255)) << 8) | ((int32_t)(minor & (uint32_t)255)));
		}
	}
	$set(this, requestedProtocols, protocols);
}

$String* SupportedVersionsExtension$CHSupportedVersionsSpec::toString() {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($MessageFormat, messageFormat, $new($MessageFormat, "\"versions\": \'[\'{0}\']\'"_s, $Locale::ENGLISH));
	if (this->requestedProtocols == nullptr || $nc(this->requestedProtocols)->length == 0) {
		$var($ObjectArray, messageFields, $new($ObjectArray, {$of("<no supported version specified>"_s)}));
		return messageFormat->format(messageFields);
	} else {
		$var($StringBuilder, builder, $new($StringBuilder, 512));
		bool isFirst = true;
		{
			$var($ints, arr$, this->requestedProtocols);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				int32_t pv = arr$->get(i$);
				{
					if (isFirst) {
						isFirst = false;
					} else {
						builder->append(", "_s);
					}
					builder->append($($ProtocolVersion::nameOf(pv)));
				}
			}
		}
		$var($ObjectArray, messageFields, $new($ObjectArray, {$($of(builder->toString()))}));
		return messageFormat->format(messageFields);
	}
}

SupportedVersionsExtension$CHSupportedVersionsSpec::SupportedVersionsExtension$CHSupportedVersionsSpec() {
}

$Class* SupportedVersionsExtension$CHSupportedVersionsSpec::load$($String* name, bool initialize) {
	$loadClass(SupportedVersionsExtension$CHSupportedVersionsSpec, name, initialize, &_SupportedVersionsExtension$CHSupportedVersionsSpec_ClassInfo_, allocate$SupportedVersionsExtension$CHSupportedVersionsSpec);
	return class$;
}

$Class* SupportedVersionsExtension$CHSupportedVersionsSpec::class$ = nullptr;

		} // ssl
	} // security
} // sun