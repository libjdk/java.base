#include <sun/security/ssl/KeyShareExtension$CHKeyShareSpec.h>

#include <java/nio/ByteBuffer.h>
#include <java/text/MessageFormat.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/KeyShareExtension$KeyShareEntry.h>
#include <sun/security/ssl/KeyShareExtension.h>
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
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $SSLProtocolException = ::javax::net::ssl::SSLProtocolException;
using $Alert = ::sun::security::ssl::Alert;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $KeyShareExtension$KeyShareEntry = ::sun::security::ssl::KeyShareExtension$KeyShareEntry;
using $Record = ::sun::security::ssl::Record;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $Utilities = ::sun::security::ssl::Utilities;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _KeyShareExtension$CHKeyShareSpec_FieldInfo_[] = {
	{"clientShares", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/KeyShareExtension$KeyShareEntry;>;", $FINAL, $field(KeyShareExtension$CHKeyShareSpec, clientShares)},
	{}
};

$MethodInfo _KeyShareExtension$CHKeyShareSpec_MethodInfo_[] = {
	{"<init>", "(Ljava/util/List;)V", "(Ljava/util/List<Lsun/security/ssl/KeyShareExtension$KeyShareEntry;>;)V", $PRIVATE, $method(KeyShareExtension$CHKeyShareSpec, init$, void, $List*)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(KeyShareExtension$CHKeyShareSpec, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(KeyShareExtension$CHKeyShareSpec, toString, $String*)},
	{}
};

$InnerClassInfo _KeyShareExtension$CHKeyShareSpec_InnerClassesInfo_[] = {
	{"sun.security.ssl.KeyShareExtension$CHKeyShareSpec", "sun.security.ssl.KeyShareExtension", "CHKeyShareSpec", $STATIC | $FINAL},
	{"sun.security.ssl.SSLExtension$SSLExtensionSpec", "sun.security.ssl.SSLExtension", "SSLExtensionSpec", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _KeyShareExtension$CHKeyShareSpec_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.KeyShareExtension$CHKeyShareSpec",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$SSLExtensionSpec",
	_KeyShareExtension$CHKeyShareSpec_FieldInfo_,
	_KeyShareExtension$CHKeyShareSpec_MethodInfo_,
	nullptr,
	nullptr,
	_KeyShareExtension$CHKeyShareSpec_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.KeyShareExtension"
};

$Object* allocate$KeyShareExtension$CHKeyShareSpec($Class* clazz) {
	return $of($alloc(KeyShareExtension$CHKeyShareSpec));
}

void KeyShareExtension$CHKeyShareSpec::init$($List* clientShares) {
	$set(this, clientShares, clientShares);
}

void KeyShareExtension$CHKeyShareSpec::init$($HandshakeContext* handshakeContext, $ByteBuffer* buffer) {
	$useLocalCurrentObjectStackCache();
	if ($nc(buffer)->remaining() < 2) {
		$init($Alert);
		$throw($($nc($nc(handshakeContext)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, $$str({"Invalid key_share extension: insufficient data (length="_s, $$str(buffer->remaining()), ")"_s}))))));
	}
	int32_t listLen = $Record::getInt16(buffer);
	if (listLen != $nc(buffer)->remaining()) {
		$init($Alert);
		$throw($($nc($nc(handshakeContext)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, $$str({"Invalid key_share extension: incorrect list length (length="_s, $$str(listLen), ")"_s}))))));
	}
	$var($List, keyShares, $new($LinkedList));
	while ($nc(buffer)->hasRemaining()) {
		int32_t namedGroupId = $Record::getInt16(buffer);
		$var($bytes, keyExchange, $Record::getBytes16(buffer));
		if ($nc(keyExchange)->length == 0) {
			$init($Alert);
			$throw($($nc($nc(handshakeContext)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, "Invalid key_share extension: empty key_exchange"_s)))));
		}
		keyShares->add($$new($KeyShareExtension$KeyShareEntry, namedGroupId, keyExchange));
	}
	$set(this, clientShares, $Collections::unmodifiableList(keyShares));
}

$String* KeyShareExtension$CHKeyShareSpec::toString() {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($MessageFormat, messageFormat, $new($MessageFormat, "\"client_shares\": \'[\'{0}\n\']\'"_s, $Locale::ENGLISH));
	$var($StringBuilder, builder, $new($StringBuilder, 512));
	{
		$var($Iterator, i$, $nc(this->clientShares)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($KeyShareExtension$KeyShareEntry, entry, $cast($KeyShareExtension$KeyShareEntry, i$->next()));
			{
				builder->append($($nc(entry)->toString()));
			}
		}
	}
	$var($ObjectArray, messageFields, $new($ObjectArray, {$($of($Utilities::indent($(builder->toString()))))}));
	return messageFormat->format(messageFields);
}

KeyShareExtension$CHKeyShareSpec::KeyShareExtension$CHKeyShareSpec() {
}

$Class* KeyShareExtension$CHKeyShareSpec::load$($String* name, bool initialize) {
	$loadClass(KeyShareExtension$CHKeyShareSpec, name, initialize, &_KeyShareExtension$CHKeyShareSpec_ClassInfo_, allocate$KeyShareExtension$CHKeyShareSpec);
	return class$;
}

$Class* KeyShareExtension$CHKeyShareSpec::class$ = nullptr;

		} // ssl
	} // security
} // sun