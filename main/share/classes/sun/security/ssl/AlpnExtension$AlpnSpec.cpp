#include <sun/security/ssl/AlpnExtension$AlpnSpec.h>

#include <java/nio/ByteBuffer.h>
#include <java/nio/charset/Charset.h>
#include <java/util/Collections.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/AlpnExtension.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef DECODE_ERROR

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Collections = ::java::util::Collections;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $SSLProtocolException = ::javax::net::ssl::SSLProtocolException;
using $Alert = ::sun::security::ssl::Alert;
using $AlpnExtension = ::sun::security::ssl::AlpnExtension;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $Record = ::sun::security::ssl::Record;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _AlpnExtension$AlpnSpec_FieldInfo_[] = {
	{"applicationProtocols", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $FINAL, $field(AlpnExtension$AlpnSpec, applicationProtocols)},
	{}
};

$MethodInfo _AlpnExtension$AlpnSpec_MethodInfo_[] = {
	{"<init>", "([Ljava/lang/String;)V", nullptr, $PRIVATE, $method(AlpnExtension$AlpnSpec, init$, void, $StringArray*)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(AlpnExtension$AlpnSpec, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(AlpnExtension$AlpnSpec, toString, $String*)},
	{}
};

$InnerClassInfo _AlpnExtension$AlpnSpec_InnerClassesInfo_[] = {
	{"sun.security.ssl.AlpnExtension$AlpnSpec", "sun.security.ssl.AlpnExtension", "AlpnSpec", $STATIC | $FINAL},
	{"sun.security.ssl.SSLExtension$SSLExtensionSpec", "sun.security.ssl.SSLExtension", "SSLExtensionSpec", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _AlpnExtension$AlpnSpec_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.AlpnExtension$AlpnSpec",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$SSLExtensionSpec",
	_AlpnExtension$AlpnSpec_FieldInfo_,
	_AlpnExtension$AlpnSpec_MethodInfo_,
	nullptr,
	nullptr,
	_AlpnExtension$AlpnSpec_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.AlpnExtension"
};

$Object* allocate$AlpnExtension$AlpnSpec($Class* clazz) {
	return $of($alloc(AlpnExtension$AlpnSpec));
}

void AlpnExtension$AlpnSpec::init$($StringArray* applicationProtocols) {
	$set(this, applicationProtocols, $List::of(applicationProtocols));
}

void AlpnExtension$AlpnSpec::init$($HandshakeContext* hc, $ByteBuffer* buffer) {
	$useLocalCurrentObjectStackCache();
	if ($nc(buffer)->remaining() < 2) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, $$str({"Invalid application_layer_protocol_negotiation: insufficient data (length="_s, $$str(buffer->remaining()), ")"_s}))))));
	}
	int32_t listLen = $Record::getInt16(buffer);
	if (listLen < 2 || listLen != $nc(buffer)->remaining()) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, $$str({"Invalid application_layer_protocol_negotiation: incorrect list length (length="_s, $$str(listLen), ")"_s}))))));
	}
	$var($List, protocolNames, $new($LinkedList));
	while ($nc(buffer)->hasRemaining()) {
		$var($bytes, bytes, $Record::getBytes8(buffer));
		if ($nc(bytes)->length == 0) {
			$init($Alert);
			$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, "Invalid application_layer_protocol_negotiation extension: empty application protocol name"_s)))));
		}
		$init($AlpnExtension);
		$var($String, appProtocol, $new($String, bytes, $AlpnExtension::alpnCharset));
		protocolNames->add(appProtocol);
	}
	$set(this, applicationProtocols, $Collections::unmodifiableList(protocolNames));
}

$String* AlpnExtension$AlpnSpec::toString() {
	return $nc($of(this->applicationProtocols))->toString();
}

AlpnExtension$AlpnSpec::AlpnExtension$AlpnSpec() {
}

$Class* AlpnExtension$AlpnSpec::load$($String* name, bool initialize) {
	$loadClass(AlpnExtension$AlpnSpec, name, initialize, &_AlpnExtension$AlpnSpec_ClassInfo_, allocate$AlpnExtension$AlpnSpec);
	return class$;
}

$Class* AlpnExtension$AlpnSpec::class$ = nullptr;

		} // ssl
	} // security
} // sun