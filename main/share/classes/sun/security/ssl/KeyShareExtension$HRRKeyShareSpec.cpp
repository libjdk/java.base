#include <sun/security/ssl/KeyShareExtension$HRRKeyShareSpec.h>

#include <java/nio/ByteBuffer.h>
#include <java/text/MessageFormat.h>
#include <java/util/Locale.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/KeyShareExtension.h>
#include <sun/security/ssl/NamedGroup.h>
#include <sun/security/ssl/Record.h>
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
using $NamedGroup = ::sun::security::ssl::NamedGroup;
using $Record = ::sun::security::ssl::Record;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _KeyShareExtension$HRRKeyShareSpec_FieldInfo_[] = {
	{"selectedGroup", "I", nullptr, $FINAL, $field(KeyShareExtension$HRRKeyShareSpec, selectedGroup)},
	{}
};

$MethodInfo _KeyShareExtension$HRRKeyShareSpec_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/NamedGroup;)V", nullptr, 0, $method(KeyShareExtension$HRRKeyShareSpec, init$, void, $NamedGroup*)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(KeyShareExtension$HRRKeyShareSpec, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(KeyShareExtension$HRRKeyShareSpec, toString, $String*)},
	{}
};

$InnerClassInfo _KeyShareExtension$HRRKeyShareSpec_InnerClassesInfo_[] = {
	{"sun.security.ssl.KeyShareExtension$HRRKeyShareSpec", "sun.security.ssl.KeyShareExtension", "HRRKeyShareSpec", $STATIC | $FINAL},
	{"sun.security.ssl.SSLExtension$SSLExtensionSpec", "sun.security.ssl.SSLExtension", "SSLExtensionSpec", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _KeyShareExtension$HRRKeyShareSpec_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.KeyShareExtension$HRRKeyShareSpec",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$SSLExtensionSpec",
	_KeyShareExtension$HRRKeyShareSpec_FieldInfo_,
	_KeyShareExtension$HRRKeyShareSpec_MethodInfo_,
	nullptr,
	nullptr,
	_KeyShareExtension$HRRKeyShareSpec_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.KeyShareExtension"
};

$Object* allocate$KeyShareExtension$HRRKeyShareSpec($Class* clazz) {
	return $of($alloc(KeyShareExtension$HRRKeyShareSpec));
}

void KeyShareExtension$HRRKeyShareSpec::init$($NamedGroup* serverGroup) {
	this->selectedGroup = $nc(serverGroup)->id;
}

void KeyShareExtension$HRRKeyShareSpec::init$($HandshakeContext* handshakeContext, $ByteBuffer* buffer) {
	$useLocalCurrentObjectStackCache();
	if ($nc(buffer)->remaining() != 2) {
		$init($Alert);
		$throw($($nc($nc(handshakeContext)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, $$str({"Invalid key_share extension: improper data (length="_s, $$str(buffer->remaining()), ")"_s}))))));
	}
	this->selectedGroup = $Record::getInt16(buffer);
}

$String* KeyShareExtension$HRRKeyShareSpec::toString() {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($MessageFormat, messageFormat, $new($MessageFormat, "\"selected group\": \'[\'{0}\']\'"_s, $Locale::ENGLISH));
	$var($ObjectArray, messageFields, $new($ObjectArray, {$($of($NamedGroup::nameOf(this->selectedGroup)))}));
	return messageFormat->format(messageFields);
}

KeyShareExtension$HRRKeyShareSpec::KeyShareExtension$HRRKeyShareSpec() {
}

$Class* KeyShareExtension$HRRKeyShareSpec::load$($String* name, bool initialize) {
	$loadClass(KeyShareExtension$HRRKeyShareSpec, name, initialize, &_KeyShareExtension$HRRKeyShareSpec_ClassInfo_, allocate$KeyShareExtension$HRRKeyShareSpec);
	return class$;
}

$Class* KeyShareExtension$HRRKeyShareSpec::class$ = nullptr;

		} // ssl
	} // security
} // sun