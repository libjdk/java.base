#include <sun/security/ssl/SupportedGroupsExtension$CHSupportedGroupsProducer.h>

#include <java/nio/ByteBuffer.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <sun/security/ssl/ClientHandshakeContext.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/NamedGroup$NamedGroupSpec.h>
#include <sun/security/ssl/NamedGroup.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLExtension.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SupportedGroupsExtension$SupportedGroups.h>
#include <sun/security/ssl/SupportedGroupsExtension$SupportedGroupsSpec.h>
#include <sun/security/ssl/SupportedGroupsExtension.h>
#include <jcpp.h>

#undef CH_SUPPORTED_GROUPS
#undef NAMED_GROUP_FFDHE

using $NamedGroupArray = $Array<::sun::security::ssl::NamedGroup>;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $ClientHandshakeContext = ::sun::security::ssl::ClientHandshakeContext;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $NamedGroup = ::sun::security::ssl::NamedGroup;
using $NamedGroup$NamedGroupSpec = ::sun::security::ssl::NamedGroup$NamedGroupSpec;
using $Record = ::sun::security::ssl::Record;
using $SSLConfiguration = ::sun::security::ssl::SSLConfiguration;
using $SSLExtension = ::sun::security::ssl::SSLExtension;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SupportedGroupsExtension$SupportedGroups = ::sun::security::ssl::SupportedGroupsExtension$SupportedGroups;
using $SupportedGroupsExtension$SupportedGroupsSpec = ::sun::security::ssl::SupportedGroupsExtension$SupportedGroupsSpec;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _SupportedGroupsExtension$CHSupportedGroupsProducer_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PRIVATE, $method(SupportedGroupsExtension$CHSupportedGroupsProducer, init$, void)},
	{"produce", "(Lsun/security/ssl/ConnectionContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;)[B", nullptr, $PUBLIC, $virtualMethod(SupportedGroupsExtension$CHSupportedGroupsProducer, produce, $bytes*, $ConnectionContext*, $SSLHandshake$HandshakeMessage*), "java.io.IOException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _SupportedGroupsExtension$CHSupportedGroupsProducer_InnerClassesInfo_[] = {
	{"sun.security.ssl.SupportedGroupsExtension$CHSupportedGroupsProducer", "sun.security.ssl.SupportedGroupsExtension", "CHSupportedGroupsProducer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SupportedGroupsExtension$SupportedGroups", "sun.security.ssl.SupportedGroupsExtension", "SupportedGroups", $STATIC},
	{}
};

$ClassInfo _SupportedGroupsExtension$CHSupportedGroupsProducer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SupportedGroupsExtension$CHSupportedGroupsProducer",
	"sun.security.ssl.SupportedGroupsExtension$SupportedGroups",
	"sun.security.ssl.HandshakeProducer",
	nullptr,
	_SupportedGroupsExtension$CHSupportedGroupsProducer_MethodInfo_,
	nullptr,
	nullptr,
	_SupportedGroupsExtension$CHSupportedGroupsProducer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SupportedGroupsExtension"
};

$Object* allocate$SupportedGroupsExtension$CHSupportedGroupsProducer($Class* clazz) {
	return $of($alloc(SupportedGroupsExtension$CHSupportedGroupsProducer));
}

int32_t SupportedGroupsExtension$CHSupportedGroupsProducer::hashCode() {
	 return this->$SupportedGroupsExtension$SupportedGroups::hashCode();
}

bool SupportedGroupsExtension$CHSupportedGroupsProducer::equals(Object$* obj) {
	 return this->$SupportedGroupsExtension$SupportedGroups::equals(obj);
}

$Object* SupportedGroupsExtension$CHSupportedGroupsProducer::clone() {
	 return this->$SupportedGroupsExtension$SupportedGroups::clone();
}

$String* SupportedGroupsExtension$CHSupportedGroupsProducer::toString() {
	 return this->$SupportedGroupsExtension$SupportedGroups::toString();
}

void SupportedGroupsExtension$CHSupportedGroupsProducer::finalize() {
	this->$SupportedGroupsExtension$SupportedGroups::finalize();
}

void SupportedGroupsExtension$CHSupportedGroupsProducer::init$() {
	$SupportedGroupsExtension$SupportedGroups::init$();
}

$bytes* SupportedGroupsExtension$CHSupportedGroupsProducer::produce($ConnectionContext* context, $SSLHandshake$HandshakeMessage* message) {
	$useLocalCurrentObjectStackCache();
	$var($ClientHandshakeContext, chc, $cast($ClientHandshakeContext, context));
	$init($SSLExtension);
	if (!$nc($nc(chc)->sslConfig)->isAvailable($SSLExtension::CH_SUPPORTED_GROUPS)) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::fine("Ignore unavailable supported_groups extension"_s, $$new($ObjectArray, 0));
		}
		return nullptr;
	}
	$init($SupportedGroupsExtension$SupportedGroups);
	$var($ArrayList, namedGroups, $new($ArrayList, $nc($SupportedGroupsExtension$SupportedGroups::supportedNamedGroups)->length));
	{
		$var($NamedGroupArray, arr$, $SupportedGroupsExtension$SupportedGroups::supportedNamedGroups);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$NamedGroup* ng = arr$->get(i$);
			{
				$init($NamedGroup$NamedGroupSpec);
				if ((!$SupportedGroupsExtension$SupportedGroups::enableFFDHE) && ($nc(ng)->spec == $NamedGroup$NamedGroupSpec::NAMED_GROUP_FFDHE)) {
					continue;
				}
				bool var$1 = $nc(ng)->isAvailable($nc(chc)->activeProtocols);
				bool var$0 = var$1 && ng->isSupported($nc(chc)->activeCipherSuites);
				if (var$0 && ng->isPermitted($nc(chc)->algorithmConstraints)) {
					namedGroups->add(ng);
				} else {
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
						$SSLLogger::fine($$str({"Ignore inactive or disabled named group: "_s, ng->name$}), $$new($ObjectArray, 0));
					}
				}
			}
		}
	}
	if (namedGroups->isEmpty()) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::warning("no available named group"_s, $$new($ObjectArray, 0));
		}
		return nullptr;
	}
	int32_t vectorLen = namedGroups->size() << 1;
	$var($bytes, extData, $new($bytes, vectorLen + 2));
	$var($ByteBuffer, m, $ByteBuffer::wrap(extData));
	$Record::putInt16(m, vectorLen);
	{
		$var($Iterator, i$, namedGroups->iterator());
		for (; $nc(i$)->hasNext();) {
			$NamedGroup* namedGroup = $cast($NamedGroup, i$->next());
			{
				$Record::putInt16(m, $nc(namedGroup)->id);
			}
		}
	}
	$set($nc(chc), clientRequestedNamedGroups, $Collections::unmodifiableList(namedGroups));
	$nc(chc->handshakeExtensions)->put($SSLExtension::CH_SUPPORTED_GROUPS, $$new($SupportedGroupsExtension$SupportedGroupsSpec, static_cast<$List*>(namedGroups)));
	return extData;
}

SupportedGroupsExtension$CHSupportedGroupsProducer::SupportedGroupsExtension$CHSupportedGroupsProducer() {
}

$Class* SupportedGroupsExtension$CHSupportedGroupsProducer::load$($String* name, bool initialize) {
	$loadClass(SupportedGroupsExtension$CHSupportedGroupsProducer, name, initialize, &_SupportedGroupsExtension$CHSupportedGroupsProducer_ClassInfo_, allocate$SupportedGroupsExtension$CHSupportedGroupsProducer);
	return class$;
}

$Class* SupportedGroupsExtension$CHSupportedGroupsProducer::class$ = nullptr;

		} // ssl
	} // security
} // sun