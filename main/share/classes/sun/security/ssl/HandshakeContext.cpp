#include <sun/security/ssl/HandshakeContext.h>

#include <java/lang/Enum.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/nio/BufferOverflowException.h>
#include <java/nio/BufferUnderflowException.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/CryptoPrimitive.h>
#include <java/util/AbstractMap$SimpleImmutableEntry.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/EnumMap.h>
#include <java/util/EnumSet.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashMap.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Queue.h>
#include <java/util/Set.h>
#include <javax/crypto/SecretKey.h>
#include <javax/net/ssl/SNIServerName.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLHandshakeException.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CipherSuite$KeyExchange.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/ContentType.h>
#include <sun/security/ssl/HandshakeHash.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/InputRecord.h>
#include <sun/security/ssl/NamedGroup$NamedGroupSpec.h>
#include <sun/security/ssl/NamedGroup.h>
#include <sun/security/ssl/OutputRecord.h>
#include <sun/security/ssl/Plaintext.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/RandomCookie.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/SSLAlgorithmConstraints.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLConsumer.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SSLKeyDerivation.h>
#include <sun/security/ssl/SSLKeyExchange.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/SSLTransport.h>
#include <sun/security/ssl/SupportedGroupsExtension$SupportedGroups.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/Utilities.h>
#include <jcpp.h>

#undef DECODE_ERROR
#undef FINISHED
#undef HANDSHAKE
#undef HELLO_REQUEST
#undef INTERNAL_ERROR
#undef KEY_AGREEMENT
#undef KEY_UPDATE
#undef NAMED_GROUP_NONE
#undef NEW_SESSION_TICKET
#undef NONE
#undef UNEXPECTED_MESSAGE

using $NamedGroup$NamedGroupSpecArray = $Array<::sun::security::ssl::NamedGroup$NamedGroupSpec>;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $BufferOverflowException = ::java::nio::BufferOverflowException;
using $BufferUnderflowException = ::java::nio::BufferUnderflowException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AlgorithmConstraints = ::java::security::AlgorithmConstraints;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $CryptoPrimitive = ::java::security::CryptoPrimitive;
using $AbstractMap$SimpleImmutableEntry = ::java::util::AbstractMap$SimpleImmutableEntry;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $EnumMap = ::java::util::EnumMap;
using $EnumSet = ::java::util::EnumSet;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LinkedHashMap = ::java::util::LinkedHashMap;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Queue = ::java::util::Queue;
using $Set = ::java::util::Set;
using $SSLHandshakeException = ::javax::net::ssl::SSLHandshakeException;
using $Alert = ::sun::security::ssl::Alert;
using $CipherSuite = ::sun::security::ssl::CipherSuite;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $ContentType = ::sun::security::ssl::ContentType;
using $HandshakeHash = ::sun::security::ssl::HandshakeHash;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $InputRecord = ::sun::security::ssl::InputRecord;
using $NamedGroup$NamedGroupSpec = ::sun::security::ssl::NamedGroup$NamedGroupSpec;
using $OutputRecord = ::sun::security::ssl::OutputRecord;
using $Plaintext = ::sun::security::ssl::Plaintext;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $Record = ::sun::security::ssl::Record;
using $SSLAlgorithmConstraints = ::sun::security::ssl::SSLAlgorithmConstraints;
using $SSLConfiguration = ::sun::security::ssl::SSLConfiguration;
using $SSLConsumer = ::sun::security::ssl::SSLConsumer;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLTransport = ::sun::security::ssl::SSLTransport;
using $SupportedGroupsExtension$SupportedGroups = ::sun::security::ssl::SupportedGroupsExtension$SupportedGroups;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $Utilities = ::sun::security::ssl::Utilities;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _HandshakeContext_FieldInfo_[] = {
	{"allowUnsafeRenegotiation", "Z", nullptr, $STATIC | $FINAL, $staticField(HandshakeContext, allowUnsafeRenegotiation)},
	{"allowLegacyHelloMessages", "Z", nullptr, $STATIC | $FINAL, $staticField(HandshakeContext, allowLegacyHelloMessages)},
	{"handshakeConsumers", "Ljava/util/LinkedHashMap;", "Ljava/util/LinkedHashMap<Ljava/lang/Byte;Lsun/security/ssl/SSLConsumer;>;", 0, $field(HandshakeContext, handshakeConsumers)},
	{"handshakeProducers", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/Byte;Lsun/security/ssl/HandshakeProducer;>;", $FINAL, $field(HandshakeContext, handshakeProducers)},
	{"sslContext", "Lsun/security/ssl/SSLContextImpl;", nullptr, $FINAL, $field(HandshakeContext, sslContext)},
	{"conContext", "Lsun/security/ssl/TransportContext;", nullptr, $FINAL, $field(HandshakeContext, conContext)},
	{"sslConfig", "Lsun/security/ssl/SSLConfiguration;", nullptr, $FINAL, $field(HandshakeContext, sslConfig)},
	{"activeProtocols", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/ProtocolVersion;>;", $FINAL, $field(HandshakeContext, activeProtocols)},
	{"activeCipherSuites", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/CipherSuite;>;", $FINAL, $field(HandshakeContext, activeCipherSuites)},
	{"algorithmConstraints", "Ljava/security/AlgorithmConstraints;", nullptr, $FINAL, $field(HandshakeContext, algorithmConstraints)},
	{"maximumActiveProtocol", "Lsun/security/ssl/ProtocolVersion;", nullptr, $FINAL, $field(HandshakeContext, maximumActiveProtocol)},
	{"handshakeOutput", "Lsun/security/ssl/HandshakeOutStream;", nullptr, $FINAL, $field(HandshakeContext, handshakeOutput)},
	{"handshakeHash", "Lsun/security/ssl/HandshakeHash;", nullptr, $FINAL, $field(HandshakeContext, handshakeHash)},
	{"handshakeSession", "Lsun/security/ssl/SSLSessionImpl;", nullptr, 0, $field(HandshakeContext, handshakeSession)},
	{"handshakeFinished", "Z", nullptr, 0, $field(HandshakeContext, handshakeFinished)},
	{"kickstartMessageDelivered", "Z", nullptr, 0, $field(HandshakeContext, kickstartMessageDelivered)},
	{"isResumption", "Z", nullptr, 0, $field(HandshakeContext, isResumption)},
	{"resumingSession", "Lsun/security/ssl/SSLSessionImpl;", nullptr, 0, $field(HandshakeContext, resumingSession)},
	{"statelessResumption", "Z", nullptr, 0, $field(HandshakeContext, statelessResumption)},
	{"delegatedActions", "Ljava/util/Queue;", "Ljava/util/Queue<Ljava/util/Map$Entry<Ljava/lang/Byte;Ljava/nio/ByteBuffer;>;>;", $FINAL, $field(HandshakeContext, delegatedActions)},
	{"taskDelegated", "Z", nullptr, $VOLATILE, $field(HandshakeContext, taskDelegated)},
	{"delegatedThrown", "Ljava/lang/Exception;", nullptr, $VOLATILE, $field(HandshakeContext, delegatedThrown)},
	{"negotiatedProtocol", "Lsun/security/ssl/ProtocolVersion;", nullptr, 0, $field(HandshakeContext, negotiatedProtocol)},
	{"negotiatedCipherSuite", "Lsun/security/ssl/CipherSuite;", nullptr, 0, $field(HandshakeContext, negotiatedCipherSuite)},
	{"handshakePossessions", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/SSLPossession;>;", $FINAL, $field(HandshakeContext, handshakePossessions)},
	{"handshakeCredentials", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/SSLCredentials;>;", $FINAL, $field(HandshakeContext, handshakeCredentials)},
	{"handshakeKeyDerivation", "Lsun/security/ssl/SSLKeyDerivation;", nullptr, 0, $field(HandshakeContext, handshakeKeyDerivation)},
	{"handshakeKeyExchange", "Lsun/security/ssl/SSLKeyExchange;", nullptr, 0, $field(HandshakeContext, handshakeKeyExchange)},
	{"baseReadSecret", "Ljavax/crypto/SecretKey;", nullptr, 0, $field(HandshakeContext, baseReadSecret)},
	{"baseWriteSecret", "Ljavax/crypto/SecretKey;", nullptr, 0, $field(HandshakeContext, baseWriteSecret)},
	{"clientHelloVersion", "I", nullptr, 0, $field(HandshakeContext, clientHelloVersion)},
	{"applicationProtocol", "Ljava/lang/String;", nullptr, 0, $field(HandshakeContext, applicationProtocol)},
	{"clientHelloRandom", "Lsun/security/ssl/RandomCookie;", nullptr, 0, $field(HandshakeContext, clientHelloRandom)},
	{"serverHelloRandom", "Lsun/security/ssl/RandomCookie;", nullptr, 0, $field(HandshakeContext, serverHelloRandom)},
	{"certRequestContext", "[B", nullptr, 0, $field(HandshakeContext, certRequestContext)},
	{"handshakeExtensions", "Ljava/util/Map;", "Ljava/util/Map<Lsun/security/ssl/SSLExtension;Lsun/security/ssl/SSLExtension$SSLExtensionSpec;>;", $FINAL, $field(HandshakeContext, handshakeExtensions)},
	{"maxFragmentLength", "I", nullptr, 0, $field(HandshakeContext, maxFragmentLength)},
	{"localSupportedSignAlgs", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/SignatureScheme;>;", 0, $field(HandshakeContext, localSupportedSignAlgs)},
	{"peerRequestedSignatureSchemes", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/SignatureScheme;>;", 0, $field(HandshakeContext, peerRequestedSignatureSchemes)},
	{"peerRequestedCertSignSchemes", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/SignatureScheme;>;", 0, $field(HandshakeContext, peerRequestedCertSignSchemes)},
	{"peerSupportedAuthorities", "[Ljavax/security/auth/x500/X500Principal;", nullptr, 0, $field(HandshakeContext, peerSupportedAuthorities)},
	{"clientRequestedNamedGroups", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/NamedGroup;>;", 0, $field(HandshakeContext, clientRequestedNamedGroups)},
	{"serverSelectedNamedGroup", "Lsun/security/ssl/NamedGroup;", nullptr, 0, $field(HandshakeContext, serverSelectedNamedGroup)},
	{"requestedServerNames", "Ljava/util/List;", "Ljava/util/List<Ljavax/net/ssl/SNIServerName;>;", 0, $field(HandshakeContext, requestedServerNames)},
	{"negotiatedServerName", "Ljavax/net/ssl/SNIServerName;", nullptr, 0, $field(HandshakeContext, negotiatedServerName)},
	{"staplingActive", "Z", nullptr, 0, $field(HandshakeContext, staplingActive)},
	{}
};

$MethodInfo _HandshakeContext_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/SSLContextImpl;Lsun/security/ssl/TransportContext;)V", nullptr, $PROTECTED, $method(HandshakeContext, init$, void, $SSLContextImpl*, $TransportContext*), "java.io.IOException"},
	{"<init>", "(Lsun/security/ssl/TransportContext;)V", nullptr, $PROTECTED, $method(HandshakeContext, init$, void, $TransportContext*)},
	{"dispatch", "(BLsun/security/ssl/Plaintext;)V", nullptr, 0, $virtualMethod(HandshakeContext, dispatch, void, int8_t, $Plaintext*), "java.io.IOException"},
	{"dispatch", "(BLjava/nio/ByteBuffer;)V", nullptr, 0, $virtualMethod(HandshakeContext, dispatch, void, int8_t, $ByteBuffer*), "java.io.IOException"},
	{"getActiveCipherSuites", "(Ljava/util/List;Ljava/util/List;Ljava/security/AlgorithmConstraints;)Ljava/util/List;", "(Ljava/util/List<Lsun/security/ssl/ProtocolVersion;>;Ljava/util/List<Lsun/security/ssl/CipherSuite;>;Ljava/security/AlgorithmConstraints;)Ljava/util/List<Lsun/security/ssl/CipherSuite;>;", $PRIVATE | $STATIC, $staticMethod(HandshakeContext, getActiveCipherSuites, $List*, $List*, $List*, $AlgorithmConstraints*)},
	{"getActiveProtocols", "(Ljava/util/List;Ljava/util/List;Ljava/security/AlgorithmConstraints;)Ljava/util/List;", "(Ljava/util/List<Lsun/security/ssl/ProtocolVersion;>;Ljava/util/List<Lsun/security/ssl/CipherSuite;>;Ljava/security/AlgorithmConstraints;)Ljava/util/List<Lsun/security/ssl/ProtocolVersion;>;", $PRIVATE | $STATIC, $staticMethod(HandshakeContext, getActiveProtocols, $List*, $List*, $List*, $AlgorithmConstraints*)},
	{"getHandshakeType", "(Lsun/security/ssl/TransportContext;Lsun/security/ssl/Plaintext;)B", nullptr, $STATIC, $staticMethod(HandshakeContext, getHandshakeType, int8_t, $TransportContext*, $Plaintext*), "java.io.IOException"},
	{"getRequestedServerNames", "()Ljava/util/List;", "()Ljava/util/List<Ljavax/net/ssl/SNIServerName;>;", 0, $virtualMethod(HandshakeContext, getRequestedServerNames, $List*)},
	{"initialize", "()V", nullptr, $PRIVATE, $method(HandshakeContext, initialize, void)},
	{"isActivatable", "(Lsun/security/ssl/CipherSuite;Ljava/security/AlgorithmConstraints;Ljava/util/Map;)Z", "(Lsun/security/ssl/CipherSuite;Ljava/security/AlgorithmConstraints;Ljava/util/Map<Lsun/security/ssl/NamedGroup$NamedGroupSpec;Ljava/lang/Boolean;>;)Z", $PRIVATE | $STATIC, $staticMethod(HandshakeContext, isActivatable, bool, $CipherSuite*, $AlgorithmConstraints*, $Map*)},
	{"isNegotiable", "(Lsun/security/ssl/CipherSuite;)Z", nullptr, 0, $virtualMethod(HandshakeContext, isNegotiable, bool, $CipherSuite*)},
	{"isNegotiable", "(Ljava/util/List;Lsun/security/ssl/CipherSuite;)Z", "(Ljava/util/List<Lsun/security/ssl/CipherSuite;>;Lsun/security/ssl/CipherSuite;)Z", $STATIC | $FINAL, $staticMethod(HandshakeContext, isNegotiable, bool, $List*, $CipherSuite*)},
	{"isNegotiable", "(Ljava/util/List;Lsun/security/ssl/ProtocolVersion;Lsun/security/ssl/CipherSuite;)Z", "(Ljava/util/List<Lsun/security/ssl/CipherSuite;>;Lsun/security/ssl/ProtocolVersion;Lsun/security/ssl/CipherSuite;)Z", $STATIC | $FINAL, $staticMethod(HandshakeContext, isNegotiable, bool, $List*, $ProtocolVersion*, $CipherSuite*)},
	{"isNegotiable", "(Lsun/security/ssl/ProtocolVersion;)Z", nullptr, 0, $virtualMethod(HandshakeContext, isNegotiable, bool, $ProtocolVersion*)},
	{"kickstart", "()V", nullptr, $ABSTRACT, $virtualMethod(HandshakeContext, kickstart, void), "java.io.IOException"},
	{"setVersion", "(Lsun/security/ssl/ProtocolVersion;)V", nullptr, 0, $virtualMethod(HandshakeContext, setVersion, void, $ProtocolVersion*)},
	{}
};

$ClassInfo _HandshakeContext_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.security.ssl.HandshakeContext",
	"java.lang.Object",
	"sun.security.ssl.ConnectionContext",
	_HandshakeContext_FieldInfo_,
	_HandshakeContext_MethodInfo_
};

$Object* allocate$HandshakeContext($Class* clazz) {
	return $of($alloc(HandshakeContext));
}

bool HandshakeContext::allowUnsafeRenegotiation = false;
bool HandshakeContext::allowLegacyHelloMessages = false;

void HandshakeContext::init$($SSLContextImpl* sslContext, $TransportContext* conContext) {
	$set(this, peerSupportedAuthorities, nullptr);
	this->staplingActive = false;
	$set(this, sslContext, sslContext);
	$set(this, conContext, conContext);
	$set(this, sslConfig, $cast($SSLConfiguration, $nc($nc(conContext)->sslConfig)->clone()));
	$set(this, algorithmConstraints, $new($SSLAlgorithmConstraints, $nc(this->sslConfig)->userSpecifiedAlgorithmConstraints));
	$set(this, activeProtocols, getActiveProtocols($nc(this->sslConfig)->enabledProtocols, $nc(this->sslConfig)->enabledCipherSuites, this->algorithmConstraints));
	if ($nc(this->activeProtocols)->isEmpty()) {
		$throwNew($SSLHandshakeException, "No appropriate protocol (protocol is disabled or cipher suites are inappropriate)"_s);
	}
	$init($ProtocolVersion);
	$ProtocolVersion* maximumVersion = $ProtocolVersion::NONE;
	{
		$var($Iterator, i$, $nc(this->activeProtocols)->iterator());
		for (; $nc(i$)->hasNext();) {
			$ProtocolVersion* pv = $cast($ProtocolVersion, i$->next());
			{
				if (maximumVersion == $ProtocolVersion::NONE || $nc(pv)->compare(maximumVersion) > 0) {
					maximumVersion = pv;
				}
			}
		}
	}
	$set(this, maximumActiveProtocol, maximumVersion);
	$set(this, activeCipherSuites, getActiveCipherSuites(this->activeProtocols, $nc(this->sslConfig)->enabledCipherSuites, this->algorithmConstraints));
	if ($nc(this->activeCipherSuites)->isEmpty()) {
		$throwNew($SSLHandshakeException, "No appropriate cipher suite"_s);
	}
	$set(this, handshakeConsumers, $new($LinkedHashMap));
	$set(this, handshakeProducers, $new($HashMap));
	$set(this, handshakeHash, $nc(conContext->inputRecord)->handshakeHash);
	$set(this, handshakeOutput, $new($HandshakeOutStream, conContext->outputRecord));
	this->handshakeFinished = false;
	this->kickstartMessageDelivered = false;
	$set(this, delegatedActions, $new($LinkedList));
	$set(this, handshakeExtensions, $new($HashMap));
	$set(this, handshakePossessions, $new($LinkedList));
	$set(this, handshakeCredentials, $new($LinkedList));
	$set(this, requestedServerNames, nullptr);
	$set(this, negotiatedServerName, nullptr);
	$set(this, negotiatedCipherSuite, conContext->cipherSuite);
	initialize();
}

void HandshakeContext::init$($TransportContext* conContext) {
	$set(this, peerSupportedAuthorities, nullptr);
	this->staplingActive = false;
	$set(this, sslContext, $nc(conContext)->sslContext);
	$set(this, conContext, conContext);
	$set(this, sslConfig, conContext->sslConfig);
	$set(this, negotiatedProtocol, conContext->protocolVersion);
	$set(this, negotiatedCipherSuite, conContext->cipherSuite);
	$set(this, handshakeOutput, $new($HandshakeOutStream, conContext->outputRecord));
	$set(this, delegatedActions, $new($LinkedList));
	$set(this, handshakeConsumers, $new($LinkedHashMap));
	$set(this, handshakeProducers, nullptr);
	$set(this, handshakeHash, nullptr);
	$set(this, activeProtocols, nullptr);
	$set(this, activeCipherSuites, nullptr);
	$set(this, algorithmConstraints, nullptr);
	$set(this, maximumActiveProtocol, nullptr);
	$set(this, handshakeExtensions, $Collections::emptyMap());
	$set(this, handshakePossessions, nullptr);
	$set(this, handshakeCredentials, nullptr);
}

void HandshakeContext::initialize() {
	$ProtocolVersion* inputHelloVersion = nullptr;
	$ProtocolVersion* outputHelloVersion = nullptr;
	if ($nc(this->conContext)->isNegotiated) {
		inputHelloVersion = $nc(this->conContext)->protocolVersion;
		outputHelloVersion = $nc(this->conContext)->protocolVersion;
	} else {
		$init($ProtocolVersion);
		if ($nc(this->activeProtocols)->contains($ProtocolVersion::SSL20Hello)) {
			inputHelloVersion = $ProtocolVersion::SSL20Hello;
			if (this->maximumActiveProtocol->useTLS13PlusSpec()) {
				outputHelloVersion = this->maximumActiveProtocol;
			} else {
				outputHelloVersion = $ProtocolVersion::SSL20Hello;
			}
		} else {
			inputHelloVersion = this->maximumActiveProtocol;
			outputHelloVersion = this->maximumActiveProtocol;
		}
	}
	$nc($nc(this->conContext)->inputRecord)->setHelloVersion(inputHelloVersion);
	$nc($nc(this->conContext)->outputRecord)->setHelloVersion(outputHelloVersion);
	if (!$nc(this->conContext)->isNegotiated) {
		$set($nc(this->conContext), protocolVersion, this->maximumActiveProtocol);
	}
	$nc($nc(this->conContext)->outputRecord)->setVersion($nc(this->conContext)->protocolVersion);
}

$List* HandshakeContext::getActiveProtocols($List* enabledProtocols, $List* enabledCipherSuites, $AlgorithmConstraints* algorithmConstraints) {
	$init(HandshakeContext);
	$useLocalCurrentObjectStackCache();
	bool enabledSSL20Hello = false;
	$var($ArrayList, protocols, $new($ArrayList, 4));
	{
		$var($Iterator, i$, $nc(enabledProtocols)->iterator());
		for (; $nc(i$)->hasNext();) {
			$ProtocolVersion* protocol = $cast($ProtocolVersion, i$->next());
			{
				$init($ProtocolVersion);
				if (!enabledSSL20Hello && protocol == $ProtocolVersion::SSL20Hello) {
					enabledSSL20Hello = true;
					continue;
				}
				$init($CryptoPrimitive);
				if (!$nc(algorithmConstraints)->permits($($EnumSet::of($CryptoPrimitive::KEY_AGREEMENT)), $nc(protocol)->name$, nullptr)) {
					continue;
				}
				bool found = false;
				$load($NamedGroup$NamedGroupSpec);
				$var($Map, cachedStatus, $new($EnumMap, $NamedGroup$NamedGroupSpec::class$));
				{
					$var($Iterator, i$, $nc(enabledCipherSuites)->iterator());
					for (; $nc(i$)->hasNext();) {
						$CipherSuite* suite = $cast($CipherSuite, i$->next());
						{
							bool var$0 = $nc(suite)->isAvailable();
							if (var$0 && suite->supports(protocol)) {
								if (isActivatable(suite, algorithmConstraints, cachedStatus)) {
									protocols->add(protocol);
									found = true;
									break;
								}
							} else {
								$init($SSLLogger);
								if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
									$SSLLogger::fine($$str({"Ignore unsupported cipher suite: "_s, suite, " for "_s, $nc(protocol)->name$}), $$new($ObjectArray, 0));
								}
							}
						}
					}
				}
				$init($SSLLogger);
				if (!found && ($SSLLogger::isOn$) && $SSLLogger::isOn("handshake"_s)) {
					$SSLLogger::fine($$str({"No available cipher suite for "_s, $nc(protocol)->name$}), $$new($ObjectArray, 0));
				}
			}
		}
	}
	if (!protocols->isEmpty()) {
		if (enabledSSL20Hello) {
			$init($ProtocolVersion);
			protocols->add($ProtocolVersion::SSL20Hello);
		}
		$Collections::sort(protocols);
	}
	return $Collections::unmodifiableList(protocols);
}

$List* HandshakeContext::getActiveCipherSuites($List* enabledProtocols, $List* enabledCipherSuites, $AlgorithmConstraints* algorithmConstraints) {
	$init(HandshakeContext);
	$useLocalCurrentObjectStackCache();
	$var($List, suites, $new($LinkedList));
	if (enabledProtocols != nullptr && !enabledProtocols->isEmpty()) {
		$load($NamedGroup$NamedGroupSpec);
		$var($Map, cachedStatus, $new($EnumMap, $NamedGroup$NamedGroupSpec::class$));
		{
			$var($Iterator, i$, $nc(enabledCipherSuites)->iterator());
			for (; $nc(i$)->hasNext();) {
				$CipherSuite* suite = $cast($CipherSuite, i$->next());
				{
					if (!$nc(suite)->isAvailable()) {
						continue;
					}
					bool isSupported = false;
					{
						$var($Iterator, i$, enabledProtocols->iterator());
						for (; $nc(i$)->hasNext();) {
							$ProtocolVersion* protocol = $cast($ProtocolVersion, i$->next());
							{
								if (!$nc(suite)->supports(protocol)) {
									continue;
								}
								if (isActivatable(suite, algorithmConstraints, cachedStatus)) {
									suites->add(suite);
									isSupported = true;
									break;
								}
							}
						}
					}
					$init($SSLLogger);
					if (!isSupported && $SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
						$SSLLogger::finest($$str({"Ignore unsupported cipher suite: "_s, suite}), $$new($ObjectArray, 0));
					}
				}
			}
		}
	}
	return $Collections::unmodifiableList(suites);
}

int8_t HandshakeContext::getHandshakeType($TransportContext* conContext, $Plaintext* plaintext) {
	$init(HandshakeContext);
	$useLocalCurrentObjectStackCache();
	$init($ContentType);
	if ($nc(plaintext)->contentType != $ContentType::HANDSHAKE->id) {
		$init($Alert);
		$throw($($nc(conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Unexpected operation for record: "_s, $$str(plaintext->contentType)}))));
	}
	if ($nc(plaintext)->fragment == nullptr || $nc($nc(plaintext)->fragment)->remaining() < 4) {
		$init($Alert);
		$throw($($nc(conContext)->fatal($Alert::UNEXPECTED_MESSAGE, "Invalid handshake message: insufficient data"_s)));
	}
	int8_t handshakeType = (int8_t)$Record::getInt8($nc(plaintext)->fragment);
	int32_t handshakeLen = $Record::getInt24($nc(plaintext)->fragment);
	if (handshakeLen != $nc($nc(plaintext)->fragment)->remaining()) {
		$init($Alert);
		$throw($($nc(conContext)->fatal($Alert::UNEXPECTED_MESSAGE, "Invalid handshake message: insufficient handshake body"_s)));
	}
	return handshakeType;
}

void HandshakeContext::dispatch(int8_t handshakeType, $Plaintext* plaintext) {
	$useLocalCurrentObjectStackCache();
	if ($nc($nc(this->conContext)->transport)->useDelegatedTask()) {
		bool hasDelegated = !$nc(this->delegatedActions)->isEmpty();
		$init($SSLHandshake);
		if (hasDelegated || (handshakeType != $SSLHandshake::FINISHED->id && handshakeType != $SSLHandshake::KEY_UPDATE->id && handshakeType != $SSLHandshake::NEW_SESSION_TICKET->id)) {
			if (!hasDelegated) {
				this->taskDelegated = false;
				$set(this, delegatedThrown, nullptr);
			}
			$var($ByteBuffer, fragment, $ByteBuffer::wrap($$new($bytes, $nc($nc(plaintext)->fragment)->remaining())));
			$nc(fragment)->put($nc(plaintext)->fragment);
			$assign(fragment, fragment->rewind());
			$nc(this->delegatedActions)->add($$new($AbstractMap$SimpleImmutableEntry, $($Byte::valueOf(handshakeType)), fragment));
			if (hasDelegated && !$nc($nc(this->conContext)->sslConfig)->isClientMode && handshakeType == $SSLHandshake::FINISHED->id) {
				$nc(this->conContext)->hasDelegatedFinished = true;
			}
		} else {
			dispatch(handshakeType, $nc(plaintext)->fragment);
		}
	} else {
		dispatch(handshakeType, $nc(plaintext)->fragment);
	}
}

void HandshakeContext::dispatch(int8_t handshakeType, $ByteBuffer* fragment) {
	$useLocalCurrentObjectStackCache();
	$var($SSLConsumer, consumer, nullptr);
	$init($SSLHandshake);
	if (handshakeType == $SSLHandshake::HELLO_REQUEST->id) {
		$assign(consumer, $SSLHandshake::HELLO_REQUEST);
	} else {
		$assign(consumer, $cast($SSLConsumer, $nc(this->handshakeConsumers)->get($($Byte::valueOf(handshakeType)))));
	}
	if (consumer == nullptr) {
		$init($Alert);
		$throw($($nc(this->conContext)->fatal($Alert::UNEXPECTED_MESSAGE, $$str({"Unexpected handshake message: "_s, $($SSLHandshake::nameOf(handshakeType))}))));
	}
	try {
		$nc(consumer)->consume(this, fragment);
	} catch ($UnsupportedOperationException& unsoe) {
		$init($Alert);
		$throw($($nc(this->conContext)->fatal($Alert::UNEXPECTED_MESSAGE, $$str({"Unsupported handshake message: "_s, $($SSLHandshake::nameOf(handshakeType))}), unsoe)));
	} catch ($BufferUnderflowException& be) {
		$init($Alert);
		$throw($($nc(this->conContext)->fatal($Alert::DECODE_ERROR, $$str({"Illegal handshake message: "_s, $($SSLHandshake::nameOf(handshakeType))}), be)));
	} catch ($BufferOverflowException& be) {
		$init($Alert);
		$throw($($nc(this->conContext)->fatal($Alert::DECODE_ERROR, $$str({"Illegal handshake message: "_s, $($SSLHandshake::nameOf(handshakeType))}), be)));
	}
	$nc(this->handshakeHash)->consume();
}

bool HandshakeContext::isNegotiable($CipherSuite* cs) {
	return isNegotiable(this->activeCipherSuites, cs);
}

bool HandshakeContext::isNegotiable($List* proposed, $CipherSuite* cs) {
	$init(HandshakeContext);
	bool var$0 = $nc(proposed)->contains(cs);
	return var$0 && $nc(cs)->isNegotiable();
}

bool HandshakeContext::isNegotiable($List* proposed, $ProtocolVersion* protocolVersion, $CipherSuite* cs) {
	$init(HandshakeContext);
	bool var$1 = $nc(proposed)->contains(cs);
	bool var$0 = var$1 && $nc(cs)->isNegotiable();
	return var$0 && cs->supports(protocolVersion);
}

bool HandshakeContext::isNegotiable($ProtocolVersion* protocolVersion) {
	return $nc(this->activeProtocols)->contains(protocolVersion);
}

void HandshakeContext::setVersion($ProtocolVersion* protocolVersion) {
	$set($nc(this->conContext), protocolVersion, protocolVersion);
}

bool HandshakeContext::isActivatable($CipherSuite* suite, $AlgorithmConstraints* algorithmConstraints, $Map* cachedStatus) {
	$init(HandshakeContext);
	$useLocalCurrentObjectStackCache();
	$init($CryptoPrimitive);
	if ($nc(algorithmConstraints)->permits($($EnumSet::of($CryptoPrimitive::KEY_AGREEMENT)), $nc(suite)->name$, nullptr)) {
		if ($nc(suite)->keyExchange == nullptr) {
			return true;
		}
		bool groupAvailable = false;
		bool retval = false;
		$var($NamedGroup$NamedGroupSpecArray, groupTypes, $nc(suite)->keyExchange->groupTypes);
		{
			$var($NamedGroup$NamedGroupSpecArray, arr$, groupTypes);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$NamedGroup$NamedGroupSpec* groupType = arr$->get(i$);
				{
					$init($NamedGroup$NamedGroupSpec);
					if (groupType != $NamedGroup$NamedGroupSpec::NAMED_GROUP_NONE) {
						$var($Boolean, checkedStatus, $cast($Boolean, $nc(cachedStatus)->get(groupType)));
						if (checkedStatus == nullptr) {
							groupAvailable = $SupportedGroupsExtension$SupportedGroups::isActivatable(algorithmConstraints, groupType);
							cachedStatus->put(groupType, $($Boolean::valueOf(groupAvailable)));
							$init($SSLLogger);
							if (!groupAvailable && $SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
								$SSLLogger::fine($$str({"No activated named group in "_s, groupType}), $$new($ObjectArray, 0));
							}
						} else {
							groupAvailable = $nc(checkedStatus)->booleanValue();
						}
						retval |= groupAvailable;
					} else {
						retval = true;
					}
				}
			}
		}
		$init($SSLLogger);
		if (!retval && $SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
			$SSLLogger::fine($$str({"No active named group(s), ignore "_s, suite}), $$new($ObjectArray, 0));
		}
		return retval;
	} else {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
			$SSLLogger::fine($$str({"Ignore disabled cipher suite: "_s, suite}), $$new($ObjectArray, 0));
		}
	}
	return false;
}

$List* HandshakeContext::getRequestedServerNames() {
	if (this->requestedServerNames == nullptr) {
		return $Collections::emptyList();
	}
	return this->requestedServerNames;
}

void clinit$HandshakeContext($Class* class$) {
	HandshakeContext::allowUnsafeRenegotiation = $Utilities::getBooleanProperty("sun.security.ssl.allowUnsafeRenegotiation"_s, false);
	HandshakeContext::allowLegacyHelloMessages = $Utilities::getBooleanProperty("sun.security.ssl.allowLegacyHelloMessages"_s, true);
}

HandshakeContext::HandshakeContext() {
}

$Class* HandshakeContext::load$($String* name, bool initialize) {
	$loadClass(HandshakeContext, name, initialize, &_HandshakeContext_ClassInfo_, clinit$HandshakeContext, allocate$HandshakeContext);
	return class$;
}

$Class* HandshakeContext::class$ = nullptr;

		} // ssl
	} // security
} // sun