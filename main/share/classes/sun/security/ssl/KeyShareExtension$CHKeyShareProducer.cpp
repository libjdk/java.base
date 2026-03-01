#include <sun/security/ssl/KeyShareExtension$CHKeyShareProducer.h>

#include <java/nio/ByteBuffer.h>
#include <java/util/AbstractCollection.h>
#include <java/util/EnumSet.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <sun/security/ssl/ClientHandshakeContext.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/KeyShareExtension$CHKeyShareSpec.h>
#include <sun/security/ssl/KeyShareExtension$KeyShareEntry.h>
#include <sun/security/ssl/KeyShareExtension.h>
#include <sun/security/ssl/NamedGroup$NamedGroupSpec.h>
#include <sun/security/ssl/NamedGroup.h>
#include <sun/security/ssl/NamedGroupPossession.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLExtension.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLKeyExchange.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLPossession.h>
#include <jcpp.h>

#undef CH_KEY_SHARE

using $SSLPossessionArray = $Array<::sun::security::ssl::SSLPossession>;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $EnumSet = ::java::util::EnumSet;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $ClientHandshakeContext = ::sun::security::ssl::ClientHandshakeContext;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $KeyShareExtension$CHKeyShareSpec = ::sun::security::ssl::KeyShareExtension$CHKeyShareSpec;
using $KeyShareExtension$KeyShareEntry = ::sun::security::ssl::KeyShareExtension$KeyShareEntry;
using $NamedGroup = ::sun::security::ssl::NamedGroup;
using $NamedGroup$NamedGroupSpec = ::sun::security::ssl::NamedGroup$NamedGroupSpec;
using $NamedGroupPossession = ::sun::security::ssl::NamedGroupPossession;
using $Record = ::sun::security::ssl::Record;
using $SSLConfiguration = ::sun::security::ssl::SSLConfiguration;
using $SSLExtension = ::sun::security::ssl::SSLExtension;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLKeyExchange = ::sun::security::ssl::SSLKeyExchange;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLPossession = ::sun::security::ssl::SSLPossession;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _KeyShareExtension$CHKeyShareProducer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(KeyShareExtension$CHKeyShareProducer, init$, void)},
	{"getShare", "(Lsun/security/ssl/ClientHandshakeContext;Lsun/security/ssl/NamedGroup;)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(KeyShareExtension$CHKeyShareProducer, getShare, $bytes*, $ClientHandshakeContext*, $NamedGroup*)},
	{"produce", "(Lsun/security/ssl/ConnectionContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;)[B", nullptr, $PUBLIC, $virtualMethod(KeyShareExtension$CHKeyShareProducer, produce, $bytes*, $ConnectionContext*, $SSLHandshake$HandshakeMessage*), "java.io.IOException"},
	{}
};

$InnerClassInfo _KeyShareExtension$CHKeyShareProducer_InnerClassesInfo_[] = {
	{"sun.security.ssl.KeyShareExtension$CHKeyShareProducer", "sun.security.ssl.KeyShareExtension", "CHKeyShareProducer", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _KeyShareExtension$CHKeyShareProducer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.KeyShareExtension$CHKeyShareProducer",
	"java.lang.Object",
	"sun.security.ssl.HandshakeProducer",
	nullptr,
	_KeyShareExtension$CHKeyShareProducer_MethodInfo_,
	nullptr,
	nullptr,
	_KeyShareExtension$CHKeyShareProducer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.KeyShareExtension"
};

$Object* allocate$KeyShareExtension$CHKeyShareProducer($Class* clazz) {
	return $of($alloc(KeyShareExtension$CHKeyShareProducer));
}

void KeyShareExtension$CHKeyShareProducer::init$() {
}

$bytes* KeyShareExtension$CHKeyShareProducer::produce($ConnectionContext* context, $SSLHandshake$HandshakeMessage* message) {
	$useLocalCurrentObjectStackCache();
	$var($ClientHandshakeContext, chc, $cast($ClientHandshakeContext, context));
	$init($SSLExtension);
	if (!$nc($nc(chc)->sslConfig)->isAvailable($SSLExtension::CH_KEY_SHARE)) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::fine("Ignore unavailable key_share extension"_s, $$new($ObjectArray, 0));
		}
		return nullptr;
	}
	$var($List, namedGroups, nullptr);
	if ($nc(chc)->serverSelectedNamedGroup != nullptr) {
		$assign(namedGroups, $List::of($of(chc->serverSelectedNamedGroup)));
	} else {
		$assign(namedGroups, chc->clientRequestedNamedGroups);
		if (namedGroups == nullptr || $nc(namedGroups)->isEmpty()) {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
				$SSLLogger::warning("Ignore key_share extension, no supported groups"_s, $$new($ObjectArray, 0));
			}
			return nullptr;
		}
	}
	$var($List, keyShares, $new($LinkedList));
	$load($NamedGroup$NamedGroupSpec);
	$var($EnumSet, ngTypes, $EnumSet::noneOf($NamedGroup$NamedGroupSpec::class$));
	$var($bytes, keyExchangeData, nullptr);
	{
		$var($Iterator, i$, $nc(namedGroups)->iterator());
		for (; $nc(i$)->hasNext();) {
			$NamedGroup* ng = $cast($NamedGroup, i$->next());
			{
				if (!$nc(ngTypes)->contains($nc(ng)->spec)) {
					if (($assign(keyExchangeData, getShare(chc, ng))) != nullptr) {
						keyShares->add($$new($KeyShareExtension$KeyShareEntry, $nc(ng)->id, keyExchangeData));
						ngTypes->add($nc(ng)->spec);
						if (ngTypes->size() == 2) {
							break;
						}
					}
				}
			}
		}
	}
	int32_t listLen = 0;
	{
		$var($Iterator, i$, keyShares->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($KeyShareExtension$KeyShareEntry, entry, $cast($KeyShareExtension$KeyShareEntry, i$->next()));
			{
				listLen += $nc(entry)->getEncodedSize();
			}
		}
	}
	$var($bytes, extData, $new($bytes, listLen + 2));
	$var($ByteBuffer, m, $ByteBuffer::wrap(extData));
	$Record::putInt16(m, listLen);
	{
		$var($Iterator, i$, keyShares->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($KeyShareExtension$KeyShareEntry, entry, $cast($KeyShareExtension$KeyShareEntry, i$->next()));
			{
				$nc(m)->put($($nc(entry)->getEncoded()));
			}
		}
	}
	$nc($nc(chc)->handshakeExtensions)->put($SSLExtension::CH_KEY_SHARE, $$new($KeyShareExtension$CHKeyShareSpec, keyShares));
	return extData;
}

$bytes* KeyShareExtension$CHKeyShareProducer::getShare($ClientHandshakeContext* chc, $NamedGroup* ng) {
	$init(KeyShareExtension$CHKeyShareProducer);
	$useLocalCurrentObjectStackCache();
	$var($SSLKeyExchange, ke, $SSLKeyExchange::valueOf(ng));
	if (ke == nullptr) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::warning($$str({"No key exchange for named group "_s, $nc(ng)->name$}), $$new($ObjectArray, 0));
		}
	} else {
		$var($SSLPossessionArray, poses, $nc(ke)->createPossessions(chc));
		{
			$var($SSLPossessionArray, arr$, poses);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($SSLPossession, pos, arr$->get(i$));
				{
					$nc($nc(chc)->handshakePossessions)->add(pos);
					if ($instanceOf($NamedGroupPossession, pos)) {
						return $nc(pos)->encode();
					}
				}
			}
		}
	}
	return nullptr;
}

KeyShareExtension$CHKeyShareProducer::KeyShareExtension$CHKeyShareProducer() {
}

$Class* KeyShareExtension$CHKeyShareProducer::load$($String* name, bool initialize) {
	$loadClass(KeyShareExtension$CHKeyShareProducer, name, initialize, &_KeyShareExtension$CHKeyShareProducer_ClassInfo_, allocate$KeyShareExtension$CHKeyShareProducer);
	return class$;
}

$Class* KeyShareExtension$CHKeyShareProducer::class$ = nullptr;

		} // ssl
	} // security
} // sun