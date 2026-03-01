#include <sun/security/ssl/SupportedGroupsExtension$EESupportedGroupsProducer.h>

#include <java/nio/ByteBuffer.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/NamedGroup$NamedGroupSpec.h>
#include <sun/security/ssl/NamedGroup.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLExtension.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/SupportedGroupsExtension$SupportedGroups.h>
#include <sun/security/ssl/SupportedGroupsExtension$SupportedGroupsSpec.h>
#include <sun/security/ssl/SupportedGroupsExtension.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef EE_SUPPORTED_GROUPS
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
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $NamedGroup = ::sun::security::ssl::NamedGroup;
using $NamedGroup$NamedGroupSpec = ::sun::security::ssl::NamedGroup$NamedGroupSpec;
using $Record = ::sun::security::ssl::Record;
using $SSLConfiguration = ::sun::security::ssl::SSLConfiguration;
using $SSLExtension = ::sun::security::ssl::SSLExtension;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $SupportedGroupsExtension$SupportedGroups = ::sun::security::ssl::SupportedGroupsExtension$SupportedGroups;
using $SupportedGroupsExtension$SupportedGroupsSpec = ::sun::security::ssl::SupportedGroupsExtension$SupportedGroupsSpec;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _SupportedGroupsExtension$EESupportedGroupsProducer_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PRIVATE, $method(SupportedGroupsExtension$EESupportedGroupsProducer, init$, void)},
	{"produce", "(Lsun/security/ssl/ConnectionContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;)[B", nullptr, $PUBLIC, $virtualMethod(SupportedGroupsExtension$EESupportedGroupsProducer, produce, $bytes*, $ConnectionContext*, $SSLHandshake$HandshakeMessage*), "java.io.IOException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _SupportedGroupsExtension$EESupportedGroupsProducer_InnerClassesInfo_[] = {
	{"sun.security.ssl.SupportedGroupsExtension$EESupportedGroupsProducer", "sun.security.ssl.SupportedGroupsExtension", "EESupportedGroupsProducer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SupportedGroupsExtension$SupportedGroups", "sun.security.ssl.SupportedGroupsExtension", "SupportedGroups", $STATIC},
	{}
};

$ClassInfo _SupportedGroupsExtension$EESupportedGroupsProducer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SupportedGroupsExtension$EESupportedGroupsProducer",
	"sun.security.ssl.SupportedGroupsExtension$SupportedGroups",
	"sun.security.ssl.HandshakeProducer",
	nullptr,
	_SupportedGroupsExtension$EESupportedGroupsProducer_MethodInfo_,
	nullptr,
	nullptr,
	_SupportedGroupsExtension$EESupportedGroupsProducer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SupportedGroupsExtension"
};

$Object* allocate$SupportedGroupsExtension$EESupportedGroupsProducer($Class* clazz) {
	return $of($alloc(SupportedGroupsExtension$EESupportedGroupsProducer));
}

int32_t SupportedGroupsExtension$EESupportedGroupsProducer::hashCode() {
	 return this->$SupportedGroupsExtension$SupportedGroups::hashCode();
}

bool SupportedGroupsExtension$EESupportedGroupsProducer::equals(Object$* obj) {
	 return this->$SupportedGroupsExtension$SupportedGroups::equals(obj);
}

$Object* SupportedGroupsExtension$EESupportedGroupsProducer::clone() {
	 return this->$SupportedGroupsExtension$SupportedGroups::clone();
}

$String* SupportedGroupsExtension$EESupportedGroupsProducer::toString() {
	 return this->$SupportedGroupsExtension$SupportedGroups::toString();
}

void SupportedGroupsExtension$EESupportedGroupsProducer::finalize() {
	this->$SupportedGroupsExtension$SupportedGroups::finalize();
}

void SupportedGroupsExtension$EESupportedGroupsProducer::init$() {
	$SupportedGroupsExtension$SupportedGroups::init$();
}

$bytes* SupportedGroupsExtension$EESupportedGroupsProducer::produce($ConnectionContext* context, $SSLHandshake$HandshakeMessage* message) {
	$useLocalCurrentObjectStackCache();
	$var($ServerHandshakeContext, shc, $cast($ServerHandshakeContext, context));
	$init($SSLExtension);
	if (!$nc($nc(shc)->sslConfig)->isAvailable($SSLExtension::EE_SUPPORTED_GROUPS)) {
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
				bool var$1 = $nc(ng)->isAvailable($nc(shc)->activeProtocols);
				bool var$0 = var$1 && ng->isSupported($nc(shc)->activeCipherSuites);
				if (var$0 && ng->isPermitted($nc(shc)->algorithmConstraints)) {
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
	$set($nc($nc(shc)->conContext), serverRequestedNamedGroups, $Collections::unmodifiableList(namedGroups));
	$var($SupportedGroupsExtension$SupportedGroupsSpec, spec, $new($SupportedGroupsExtension$SupportedGroupsSpec, static_cast<$List*>(namedGroups)));
	$nc(shc->handshakeExtensions)->put($SSLExtension::EE_SUPPORTED_GROUPS, spec);
	return extData;
}

SupportedGroupsExtension$EESupportedGroupsProducer::SupportedGroupsExtension$EESupportedGroupsProducer() {
}

$Class* SupportedGroupsExtension$EESupportedGroupsProducer::load$($String* name, bool initialize) {
	$loadClass(SupportedGroupsExtension$EESupportedGroupsProducer, name, initialize, &_SupportedGroupsExtension$EESupportedGroupsProducer_ClassInfo_, allocate$SupportedGroupsExtension$EESupportedGroupsProducer);
	return class$;
}

$Class* SupportedGroupsExtension$EESupportedGroupsProducer::class$ = nullptr;

		} // ssl
	} // security
} // sun