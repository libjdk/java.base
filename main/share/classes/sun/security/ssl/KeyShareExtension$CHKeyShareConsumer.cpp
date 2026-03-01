#include <sun/security/ssl/KeyShareExtension$CHKeyShareConsumer.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/security/GeneralSecurityException.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/KeyShareExtension$CHKeyShareSpec.h>
#include <sun/security/ssl/KeyShareExtension$KeyShareEntry.h>
#include <sun/security/ssl/KeyShareExtension.h>
#include <sun/security/ssl/NamedGroup$ExceptionSupplier.h>
#include <sun/security/ssl/NamedGroup.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLCredentials.h>
#include <sun/security/ssl/SSLExtension.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/SupportedGroupsExtension$SupportedGroups.h>
#include <jcpp.h>

#undef CH_KEY_SHARE
#undef HELLO_RETRY_REQUEST

using $Serializable = ::java::io::Serializable;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $KeyShareExtension$CHKeyShareSpec = ::sun::security::ssl::KeyShareExtension$CHKeyShareSpec;
using $KeyShareExtension$KeyShareEntry = ::sun::security::ssl::KeyShareExtension$KeyShareEntry;
using $NamedGroup = ::sun::security::ssl::NamedGroup;
using $NamedGroup$ExceptionSupplier = ::sun::security::ssl::NamedGroup$ExceptionSupplier;
using $SSLConfiguration = ::sun::security::ssl::SSLConfiguration;
using $SSLCredentials = ::sun::security::ssl::SSLCredentials;
using $SSLExtension = ::sun::security::ssl::SSLExtension;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $SupportedGroupsExtension$SupportedGroups = ::sun::security::ssl::SupportedGroupsExtension$SupportedGroups;

namespace sun {
	namespace security {
		namespace ssl {

class KeyShareExtension$CHKeyShareConsumer$$Lambda$lambda$consume$0 : public $NamedGroup$ExceptionSupplier {
	$class(KeyShareExtension$CHKeyShareConsumer$$Lambda$lambda$consume$0, $NO_CLASS_INIT, $NamedGroup$ExceptionSupplier)
public:
	void init$() {
	}
	virtual void apply($String* s) override {
		KeyShareExtension$CHKeyShareConsumer::lambda$consume$0(s);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<KeyShareExtension$CHKeyShareConsumer$$Lambda$lambda$consume$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo KeyShareExtension$CHKeyShareConsumer$$Lambda$lambda$consume$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(KeyShareExtension$CHKeyShareConsumer$$Lambda$lambda$consume$0, init$, void)},
	{"apply", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(KeyShareExtension$CHKeyShareConsumer$$Lambda$lambda$consume$0, apply, void, $String*)},
	{}
};
$ClassInfo KeyShareExtension$CHKeyShareConsumer$$Lambda$lambda$consume$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.security.ssl.KeyShareExtension$CHKeyShareConsumer$$Lambda$lambda$consume$0",
	"java.lang.Object",
	"sun.security.ssl.NamedGroup$ExceptionSupplier",
	nullptr,
	methodInfos
};
$Class* KeyShareExtension$CHKeyShareConsumer$$Lambda$lambda$consume$0::load$($String* name, bool initialize) {
	$loadClass(KeyShareExtension$CHKeyShareConsumer$$Lambda$lambda$consume$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* KeyShareExtension$CHKeyShareConsumer$$Lambda$lambda$consume$0::class$ = nullptr;

$MethodInfo _KeyShareExtension$CHKeyShareConsumer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(KeyShareExtension$CHKeyShareConsumer, init$, void)},
	{"consume", "(Lsun/security/ssl/ConnectionContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC, $virtualMethod(KeyShareExtension$CHKeyShareConsumer, consume, void, $ConnectionContext*, $SSLHandshake$HandshakeMessage*, $ByteBuffer*), "java.io.IOException"},
	{"lambda$consume$0", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(KeyShareExtension$CHKeyShareConsumer, lambda$consume$0, void, $String*), "javax.net.ssl.SSLException"},
	{}
};

$InnerClassInfo _KeyShareExtension$CHKeyShareConsumer_InnerClassesInfo_[] = {
	{"sun.security.ssl.KeyShareExtension$CHKeyShareConsumer", "sun.security.ssl.KeyShareExtension", "CHKeyShareConsumer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLExtension$ExtensionConsumer", "sun.security.ssl.SSLExtension", "ExtensionConsumer", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _KeyShareExtension$CHKeyShareConsumer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.KeyShareExtension$CHKeyShareConsumer",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$ExtensionConsumer",
	nullptr,
	_KeyShareExtension$CHKeyShareConsumer_MethodInfo_,
	nullptr,
	nullptr,
	_KeyShareExtension$CHKeyShareConsumer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.KeyShareExtension"
};

$Object* allocate$KeyShareExtension$CHKeyShareConsumer($Class* clazz) {
	return $of($alloc(KeyShareExtension$CHKeyShareConsumer));
}

void KeyShareExtension$CHKeyShareConsumer::init$() {
}

void KeyShareExtension$CHKeyShareConsumer::consume($ConnectionContext* context, $SSLHandshake$HandshakeMessage* message, $ByteBuffer* buffer) {
	$useLocalCurrentObjectStackCache();
	$var($ServerHandshakeContext, shc, $cast($ServerHandshakeContext, context));
	$init($SSLExtension);
	if ($nc($nc(shc)->handshakeExtensions)->containsKey($SSLExtension::CH_KEY_SHARE)) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::fine("The key_share extension has been loaded"_s, $$new($ObjectArray, 0));
		}
		return;
	}
	if (!$nc($nc(shc)->sslConfig)->isAvailable($SSLExtension::CH_KEY_SHARE)) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::fine("Ignore unavailable key_share extension"_s, $$new($ObjectArray, 0));
		}
		return;
	}
	$var($KeyShareExtension$CHKeyShareSpec, spec, $new($KeyShareExtension$CHKeyShareSpec, shc, buffer));
	$var($List, credentials, $new($LinkedList));
	{
		$var($Iterator, i$, $nc(spec->clientShares)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($KeyShareExtension$KeyShareEntry, entry, $cast($KeyShareExtension$KeyShareEntry, i$->next()));
			{
				$NamedGroup* ng = $NamedGroup::valueOf($nc(entry)->namedGroupId);
				if (ng == nullptr || !$SupportedGroupsExtension$SupportedGroups::isActivatable($nc(shc)->algorithmConstraints, ng)) {
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
						$SSLLogger::fine($$str({"Ignore unsupported named group: "_s, $($NamedGroup::nameOf($nc(entry)->namedGroupId))}), $$new($ObjectArray, 0));
					}
					continue;
				}
				try {
					$var($SSLCredentials, kaCred, $nc(ng)->decodeCredentials($nc(entry)->keyExchange, $nc(shc)->algorithmConstraints, static_cast<$NamedGroup$ExceptionSupplier*>($$new(KeyShareExtension$CHKeyShareConsumer$$Lambda$lambda$consume$0))));
					if (kaCred != nullptr) {
						credentials->add(kaCred);
					}
				} catch ($GeneralSecurityException& ex) {
					$SSLLogger::warning($$str({"Cannot decode named group: "_s, $($NamedGroup::nameOf($nc(entry)->namedGroupId))}), $$new($ObjectArray, 0));
				}
			}
		}
	}
	if (!credentials->isEmpty()) {
		$nc($nc(shc)->handshakeCredentials)->addAll(credentials);
	} else {
		$init($SSLHandshake);
		$nc($nc(shc)->handshakeProducers)->put($($Byte::valueOf($SSLHandshake::HELLO_RETRY_REQUEST->id)), $SSLHandshake::HELLO_RETRY_REQUEST);
	}
	$nc($nc(shc)->handshakeExtensions)->put($SSLExtension::CH_KEY_SHARE, spec);
}

void KeyShareExtension$CHKeyShareConsumer::lambda$consume$0($String* s) {
	$init(KeyShareExtension$CHKeyShareConsumer);
	$SSLLogger::warning(s, $$new($ObjectArray, 0));
}

KeyShareExtension$CHKeyShareConsumer::KeyShareExtension$CHKeyShareConsumer() {
}

$Class* KeyShareExtension$CHKeyShareConsumer::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(KeyShareExtension$CHKeyShareConsumer$$Lambda$lambda$consume$0::classInfo$.name)) {
			return KeyShareExtension$CHKeyShareConsumer$$Lambda$lambda$consume$0::load$(name, initialize);
		}
	}
	$loadClass(KeyShareExtension$CHKeyShareConsumer, name, initialize, &_KeyShareExtension$CHKeyShareConsumer_ClassInfo_, allocate$KeyShareExtension$CHKeyShareConsumer);
	return class$;
}

$Class* KeyShareExtension$CHKeyShareConsumer::class$ = nullptr;

		} // ssl
	} // security
} // sun