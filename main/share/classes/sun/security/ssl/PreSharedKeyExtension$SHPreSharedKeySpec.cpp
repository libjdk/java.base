#include <sun/security/ssl/PreSharedKeyExtension$SHPreSharedKeySpec.h>

#include <java/nio/ByteBuffer.h>
#include <java/text/MessageFormat.h>
#include <java/util/Locale.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/PreSharedKeyExtension.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/Utilities.h>
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
using $Record = ::sun::security::ssl::Record;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $Utilities = ::sun::security::ssl::Utilities;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _PreSharedKeyExtension$SHPreSharedKeySpec_FieldInfo_[] = {
	{"selectedIdentity", "I", nullptr, $FINAL, $field(PreSharedKeyExtension$SHPreSharedKeySpec, selectedIdentity)},
	{}
};

$MethodInfo _PreSharedKeyExtension$SHPreSharedKeySpec_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, 0, $method(PreSharedKeyExtension$SHPreSharedKeySpec, init$, void, int32_t)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, 0, $method(PreSharedKeyExtension$SHPreSharedKeySpec, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"getEncoded", "()[B", nullptr, 0, $method(PreSharedKeyExtension$SHPreSharedKeySpec, getEncoded, $bytes*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PreSharedKeyExtension$SHPreSharedKeySpec, toString, $String*)},
	{}
};

$InnerClassInfo _PreSharedKeyExtension$SHPreSharedKeySpec_InnerClassesInfo_[] = {
	{"sun.security.ssl.PreSharedKeyExtension$SHPreSharedKeySpec", "sun.security.ssl.PreSharedKeyExtension", "SHPreSharedKeySpec", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLExtension$SSLExtensionSpec", "sun.security.ssl.SSLExtension", "SSLExtensionSpec", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _PreSharedKeyExtension$SHPreSharedKeySpec_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.PreSharedKeyExtension$SHPreSharedKeySpec",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$SSLExtensionSpec",
	_PreSharedKeyExtension$SHPreSharedKeySpec_FieldInfo_,
	_PreSharedKeyExtension$SHPreSharedKeySpec_MethodInfo_,
	nullptr,
	nullptr,
	_PreSharedKeyExtension$SHPreSharedKeySpec_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.PreSharedKeyExtension"
};

$Object* allocate$PreSharedKeyExtension$SHPreSharedKeySpec($Class* clazz) {
	return $of($alloc(PreSharedKeyExtension$SHPreSharedKeySpec));
}

void PreSharedKeyExtension$SHPreSharedKeySpec::init$(int32_t selectedIdentity) {
	this->selectedIdentity = selectedIdentity;
}

void PreSharedKeyExtension$SHPreSharedKeySpec::init$($HandshakeContext* hc, $ByteBuffer* m) {
	$useLocalCurrentObjectStackCache();
	if ($nc(m)->remaining() < 2) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, $$str({"Invalid pre_shared_key extension: insufficient selected_identity (length="_s, $$str(m->remaining()), ")"_s}))))));
	}
	this->selectedIdentity = $Record::getInt16(m);
}

$bytes* PreSharedKeyExtension$SHPreSharedKeySpec::getEncoded() {
	return $new($bytes, {
		(int8_t)((int32_t)((this->selectedIdentity >> 8) & (uint32_t)255)),
		(int8_t)((int32_t)(this->selectedIdentity & (uint32_t)255))
	});
}

$String* PreSharedKeyExtension$SHPreSharedKeySpec::toString() {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($MessageFormat, messageFormat, $new($MessageFormat, "\"PreSharedKey\": \'{\'\n  \"selected_identity\"      : \"{0}\",\n\'}\'"_s, $Locale::ENGLISH));
	$var($ObjectArray, messageFields, $new($ObjectArray, {$($of($Utilities::byte16HexString(this->selectedIdentity)))}));
	return messageFormat->format(messageFields);
}

PreSharedKeyExtension$SHPreSharedKeySpec::PreSharedKeyExtension$SHPreSharedKeySpec() {
}

$Class* PreSharedKeyExtension$SHPreSharedKeySpec::load$($String* name, bool initialize) {
	$loadClass(PreSharedKeyExtension$SHPreSharedKeySpec, name, initialize, &_PreSharedKeyExtension$SHPreSharedKeySpec_ClassInfo_, allocate$PreSharedKeyExtension$SHPreSharedKeySpec);
	return class$;
}

$Class* PreSharedKeyExtension$SHPreSharedKeySpec::class$ = nullptr;

		} // ssl
	} // security
} // sun