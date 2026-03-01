#include <sun/security/ssl/SSLConfiguration.h>

#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/Cloneable.h>
#include <java/lang/Enum.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/function/BiFunction.h>
#include <javax/crypto/KeyGenerator.h>
#include <javax/net/ssl/HandshakeCompletedListener.h>
#include <javax/net/ssl/SSLParameters.h>
#include <sun/security/action/GetIntegerAction.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/ClientAuthType.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLAlgorithmConstraints.h>
#include <sun/security/ssl/SSLConfiguration$1.h>
#include <sun/security/ssl/SSLConfiguration$CustomizedClientSignatureSchemes.h>
#include <sun/security/ssl/SSLConfiguration$CustomizedServerSignatureSchemes.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLExtension$ClientExtensions.h>
#include <sun/security/ssl/SSLExtension$ServerExtensions.h>
#include <sun/security/ssl/SSLExtension.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SignatureScheme.h>
#include <sun/security/ssl/Utilities.h>
#include <jcpp.h>

#undef CLIENT_AUTH_NONE
#undef CLIENT_AUTH_REQUESTED
#undef CLIENT_AUTH_REQUIRED
#undef DEFAULT
#undef NONE

using $SSLExtensionArray = $Array<::sun::security::ssl::SSLExtension>;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $AccessController = ::java::security::AccessController;
using $AlgorithmConstraints = ::java::security::AlgorithmConstraints;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $KeyGenerator = ::javax::crypto::KeyGenerator;
using $HandshakeCompletedListener = ::javax::net::ssl::HandshakeCompletedListener;
using $SSLParameters = ::javax::net::ssl::SSLParameters;
using $GetIntegerAction = ::sun::security::action::GetIntegerAction;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $CipherSuite = ::sun::security::ssl::CipherSuite;
using $ClientAuthType = ::sun::security::ssl::ClientAuthType;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLAlgorithmConstraints = ::sun::security::ssl::SSLAlgorithmConstraints;
using $SSLConfiguration$1 = ::sun::security::ssl::SSLConfiguration$1;
using $SSLConfiguration$CustomizedClientSignatureSchemes = ::sun::security::ssl::SSLConfiguration$CustomizedClientSignatureSchemes;
using $SSLConfiguration$CustomizedServerSignatureSchemes = ::sun::security::ssl::SSLConfiguration$CustomizedServerSignatureSchemes;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLExtension = ::sun::security::ssl::SSLExtension;
using $SSLExtension$ClientExtensions = ::sun::security::ssl::SSLExtension$ClientExtensions;
using $SSLExtension$ServerExtensions = ::sun::security::ssl::SSLExtension$ServerExtensions;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SignatureScheme = ::sun::security::ssl::SignatureScheme;
using $Utilities = ::sun::security::ssl::Utilities;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLConfiguration_FieldInfo_[] = {
	{"userSpecifiedAlgorithmConstraints", "Ljava/security/AlgorithmConstraints;", nullptr, 0, $field(SSLConfiguration, userSpecifiedAlgorithmConstraints)},
	{"enabledProtocols", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/ProtocolVersion;>;", 0, $field(SSLConfiguration, enabledProtocols)},
	{"enabledCipherSuites", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/CipherSuite;>;", 0, $field(SSLConfiguration, enabledCipherSuites)},
	{"clientAuthType", "Lsun/security/ssl/ClientAuthType;", nullptr, 0, $field(SSLConfiguration, clientAuthType)},
	{"identificationProtocol", "Ljava/lang/String;", nullptr, 0, $field(SSLConfiguration, identificationProtocol)},
	{"serverNames", "Ljava/util/List;", "Ljava/util/List<Ljavax/net/ssl/SNIServerName;>;", 0, $field(SSLConfiguration, serverNames)},
	{"sniMatchers", "Ljava/util/Collection;", "Ljava/util/Collection<Ljavax/net/ssl/SNIMatcher;>;", 0, $field(SSLConfiguration, sniMatchers)},
	{"applicationProtocols", "[Ljava/lang/String;", nullptr, 0, $field(SSLConfiguration, applicationProtocols)},
	{"preferLocalCipherSuites", "Z", nullptr, 0, $field(SSLConfiguration, preferLocalCipherSuites)},
	{"enableRetransmissions", "Z", nullptr, 0, $field(SSLConfiguration, enableRetransmissions)},
	{"maximumPacketSize", "I", nullptr, 0, $field(SSLConfiguration, maximumPacketSize)},
	{"signatureSchemes", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/SignatureScheme;>;", 0, $field(SSLConfiguration, signatureSchemes)},
	{"maximumProtocolVersion", "Lsun/security/ssl/ProtocolVersion;", nullptr, 0, $field(SSLConfiguration, maximumProtocolVersion)},
	{"isClientMode", "Z", nullptr, 0, $field(SSLConfiguration, isClientMode)},
	{"enableSessionCreation", "Z", nullptr, 0, $field(SSLConfiguration, enableSessionCreation)},
	{"socketAPSelector", "Ljava/util/function/BiFunction;", "Ljava/util/function/BiFunction<Ljavax/net/ssl/SSLSocket;Ljava/util/List<Ljava/lang/String;>;Ljava/lang/String;>;", 0, $field(SSLConfiguration, socketAPSelector)},
	{"engineAPSelector", "Ljava/util/function/BiFunction;", "Ljava/util/function/BiFunction<Ljavax/net/ssl/SSLEngine;Ljava/util/List<Ljava/lang/String;>;Ljava/lang/String;>;", 0, $field(SSLConfiguration, engineAPSelector)},
	{"handshakeListeners", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljavax/net/ssl/HandshakeCompletedListener;Ljava/security/AccessControlContext;>;", 0, $field(SSLConfiguration, handshakeListeners)},
	{"noSniExtension", "Z", nullptr, 0, $field(SSLConfiguration, noSniExtension)},
	{"noSniMatcher", "Z", nullptr, 0, $field(SSLConfiguration, noSniMatcher)},
	{"useExtendedMasterSecret", "Z", nullptr, $STATIC | $FINAL, $staticField(SSLConfiguration, useExtendedMasterSecret)},
	{"allowLegacyResumption", "Z", nullptr, $STATIC | $FINAL, $staticField(SSLConfiguration, allowLegacyResumption)},
	{"allowLegacyMasterSecret", "Z", nullptr, $STATIC | $FINAL, $staticField(SSLConfiguration, allowLegacyMasterSecret)},
	{"useCompatibilityMode", "Z", nullptr, $STATIC | $FINAL, $staticField(SSLConfiguration, useCompatibilityMode)},
	{"acknowledgeCloseNotify", "Z", nullptr, $STATIC | $FINAL, $staticField(SSLConfiguration, acknowledgeCloseNotify)},
	{"maxHandshakeMessageSize", "I", nullptr, $STATIC | $FINAL, $staticField(SSLConfiguration, maxHandshakeMessageSize)},
	{"maxCertificateChainLength", "I", nullptr, $STATIC | $FINAL, $staticField(SSLConfiguration, maxCertificateChainLength)},
	{}
};

$MethodInfo _SSLConfiguration_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/SSLContextImpl;Z)V", nullptr, 0, $method(SSLConfiguration, init$, void, $SSLContextImpl*, bool)},
	{"addHandshakeCompletedListener", "(Ljavax/net/ssl/HandshakeCompletedListener;)V", nullptr, 0, $method(SSLConfiguration, addHandshakeCompletedListener, void, $HandshakeCompletedListener*)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(SSLConfiguration, clone, $Object*)},
	{"getCustomizedSignatureScheme", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Lsun/security/ssl/SignatureScheme;>;", $PRIVATE | $STATIC, $staticMethod(SSLConfiguration, getCustomizedSignatureScheme, $List*, $String*)},
	{"getEnabledExtensions", "(Lsun/security/ssl/SSLHandshake;)[Lsun/security/ssl/SSLExtension;", nullptr, 0, $method(SSLConfiguration, getEnabledExtensions, $SSLExtensionArray*, $SSLHandshake*)},
	{"getEnabledExtensions", "(Lsun/security/ssl/SSLHandshake;Lsun/security/ssl/ProtocolVersion;)[Lsun/security/ssl/SSLExtension;", nullptr, 0, $method(SSLConfiguration, getEnabledExtensions, $SSLExtensionArray*, $SSLHandshake*, $ProtocolVersion*)},
	{"getEnabledExtensions", "(Lsun/security/ssl/SSLHandshake;Ljava/util/List;)[Lsun/security/ssl/SSLExtension;", "(Lsun/security/ssl/SSLHandshake;Ljava/util/List<Lsun/security/ssl/ProtocolVersion;>;)[Lsun/security/ssl/SSLExtension;", 0, $method(SSLConfiguration, getEnabledExtensions, $SSLExtensionArray*, $SSLHandshake*, $List*)},
	{"getExclusiveExtensions", "(Lsun/security/ssl/SSLHandshake;Ljava/util/List;)[Lsun/security/ssl/SSLExtension;", "(Lsun/security/ssl/SSLHandshake;Ljava/util/List<Lsun/security/ssl/SSLExtension;>;)[Lsun/security/ssl/SSLExtension;", 0, $method(SSLConfiguration, getExclusiveExtensions, $SSLExtensionArray*, $SSLHandshake*, $List*)},
	{"getSSLParameters", "()Ljavax/net/ssl/SSLParameters;", nullptr, 0, $method(SSLConfiguration, getSSLParameters, $SSLParameters*)},
	{"isAvailable", "(Lsun/security/ssl/SSLExtension;)Z", nullptr, 0, $method(SSLConfiguration, isAvailable, bool, $SSLExtension*)},
	{"isAvailable", "(Lsun/security/ssl/SSLExtension;Lsun/security/ssl/ProtocolVersion;)Z", nullptr, 0, $method(SSLConfiguration, isAvailable, bool, $SSLExtension*, $ProtocolVersion*)},
	{"removeHandshakeCompletedListener", "(Ljavax/net/ssl/HandshakeCompletedListener;)V", nullptr, 0, $method(SSLConfiguration, removeHandshakeCompletedListener, void, $HandshakeCompletedListener*)},
	{"setSSLParameters", "(Ljavax/net/ssl/SSLParameters;)V", nullptr, 0, $method(SSLConfiguration, setSSLParameters, void, $SSLParameters*)},
	{"toggleClientMode", "()V", nullptr, 0, $method(SSLConfiguration, toggleClientMode, void)},
	{}
};

$InnerClassInfo _SSLConfiguration_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLConfiguration$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"sun.security.ssl.SSLConfiguration$CustomizedServerSignatureSchemes", "sun.security.ssl.SSLConfiguration", "CustomizedServerSignatureSchemes", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLConfiguration$CustomizedClientSignatureSchemes", "sun.security.ssl.SSLConfiguration", "CustomizedClientSignatureSchemes", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _SSLConfiguration_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLConfiguration",
	"java.lang.Object",
	"java.lang.Cloneable",
	_SSLConfiguration_FieldInfo_,
	_SSLConfiguration_MethodInfo_,
	nullptr,
	nullptr,
	_SSLConfiguration_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLConfiguration$1,sun.security.ssl.SSLConfiguration$CustomizedServerSignatureSchemes,sun.security.ssl.SSLConfiguration$CustomizedClientSignatureSchemes"
};

$Object* allocate$SSLConfiguration($Class* clazz) {
	return $of($alloc(SSLConfiguration));
}

bool SSLConfiguration::useExtendedMasterSecret = false;
bool SSLConfiguration::allowLegacyResumption = false;
bool SSLConfiguration::allowLegacyMasterSecret = false;
bool SSLConfiguration::useCompatibilityMode = false;
bool SSLConfiguration::acknowledgeCloseNotify = false;
int32_t SSLConfiguration::maxHandshakeMessageSize = 0;
int32_t SSLConfiguration::maxCertificateChainLength = 0;

void SSLConfiguration::init$($SSLContextImpl* sslContext, bool isClientMode) {
	$init($SSLAlgorithmConstraints);
	$set(this, userSpecifiedAlgorithmConstraints, $SSLAlgorithmConstraints::DEFAULT);
	$set(this, enabledProtocols, $nc(sslContext)->getDefaultProtocolVersions(!isClientMode));
	$set(this, enabledCipherSuites, sslContext->getDefaultCipherSuites(!isClientMode));
	$init($ClientAuthType);
	$set(this, clientAuthType, $ClientAuthType::CLIENT_AUTH_NONE);
	$set(this, identificationProtocol, nullptr);
	$set(this, serverNames, $Collections::emptyList());
	$set(this, sniMatchers, $Collections::emptyList());
	this->preferLocalCipherSuites = true;
	$set(this, applicationProtocols, $new($StringArray, 0));
	this->enableRetransmissions = sslContext->isDTLS();
	this->maximumPacketSize = 0;
	$init($SSLConfiguration$CustomizedClientSignatureSchemes);
	$init($SSLConfiguration$CustomizedServerSignatureSchemes);
	$set(this, signatureSchemes, isClientMode ? $SSLConfiguration$CustomizedClientSignatureSchemes::signatureSchemes : $SSLConfiguration$CustomizedServerSignatureSchemes::signatureSchemes);
	$init($ProtocolVersion);
	$set(this, maximumProtocolVersion, $ProtocolVersion::NONE);
	{
		$var($Iterator, i$, $nc(this->enabledProtocols)->iterator());
		for (; $nc(i$)->hasNext();) {
			$ProtocolVersion* pv = $cast($ProtocolVersion, i$->next());
			{
				if ($nc(pv)->compareTo(static_cast<$Enum*>(this->maximumProtocolVersion)) > 0) {
					$set(this, maximumProtocolVersion, pv);
				}
			}
		}
	}
	this->isClientMode = isClientMode;
	this->enableSessionCreation = true;
	$set(this, socketAPSelector, nullptr);
	$set(this, engineAPSelector, nullptr);
	$set(this, handshakeListeners, nullptr);
	this->noSniExtension = false;
	this->noSniMatcher = false;
}

$SSLParameters* SSLConfiguration::getSSLParameters() {
	$useLocalCurrentObjectStackCache();
	$var($SSLParameters, params, $new($SSLParameters));
	params->setAlgorithmConstraints(this->userSpecifiedAlgorithmConstraints);
	params->setProtocols($($ProtocolVersion::toStringArray(this->enabledProtocols)));
	params->setCipherSuites($($CipherSuite::namesOf(this->enabledCipherSuites)));
	$init($SSLConfiguration$1);
	switch ($nc($SSLConfiguration$1::$SwitchMap$sun$security$ssl$ClientAuthType)->get($nc((this->clientAuthType))->ordinal())) {
	case 1:
		{
			params->setNeedClientAuth(true);
			break;
		}
	case 2:
		{
			params->setWantClientAuth(true);
			break;
		}
	default:
		{
			params->setWantClientAuth(false);
		}
	}
	params->setEndpointIdentificationAlgorithm(this->identificationProtocol);
	if ($nc(this->serverNames)->isEmpty() && !this->noSniExtension) {
		params->setServerNames(nullptr);
	} else {
		params->setServerNames(this->serverNames);
	}
	if ($nc(this->sniMatchers)->isEmpty() && !this->noSniMatcher) {
		params->setSNIMatchers(nullptr);
	} else {
		params->setSNIMatchers(this->sniMatchers);
	}
	params->setApplicationProtocols(this->applicationProtocols);
	params->setUseCipherSuitesOrder(this->preferLocalCipherSuites);
	params->setEnableRetransmissions(this->enableRetransmissions);
	params->setMaximumPacketSize(this->maximumPacketSize);
	return params;
}

void SSLConfiguration::setSSLParameters($SSLParameters* params) {
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmConstraints, ac, $nc(params)->getAlgorithmConstraints());
	if (ac != nullptr) {
		$set(this, userSpecifiedAlgorithmConstraints, ac);
	}
	$var($StringArray, sa, params->getCipherSuites());
	if (sa != nullptr) {
		$set(this, enabledCipherSuites, $CipherSuite::validValuesOf(sa));
	}
	$assign(sa, params->getProtocols());
	if (sa != nullptr) {
		$set(this, enabledProtocols, $ProtocolVersion::namesOf(sa));
		$set(this, maximumProtocolVersion, $ProtocolVersion::NONE);
		{
			$var($Iterator, i$, $nc(this->enabledProtocols)->iterator());
			for (; $nc(i$)->hasNext();) {
				$ProtocolVersion* pv = $cast($ProtocolVersion, i$->next());
				{
					if ($nc(pv)->compareTo(static_cast<$Enum*>(this->maximumProtocolVersion)) > 0) {
						$set(this, maximumProtocolVersion, pv);
					}
				}
			}
		}
	}
	if (params->getNeedClientAuth()) {
		$init($ClientAuthType);
		$set(this, clientAuthType, $ClientAuthType::CLIENT_AUTH_REQUIRED);
	} else if (params->getWantClientAuth()) {
		$init($ClientAuthType);
		$set(this, clientAuthType, $ClientAuthType::CLIENT_AUTH_REQUESTED);
	} else {
		$init($ClientAuthType);
		$set(this, clientAuthType, $ClientAuthType::CLIENT_AUTH_NONE);
	}
	$var($String, s, params->getEndpointIdentificationAlgorithm());
	if (s != nullptr) {
		$set(this, identificationProtocol, s);
	}
	$var($List, sniNames, params->getServerNames());
	if (sniNames != nullptr) {
		this->noSniExtension = sniNames->isEmpty();
		$set(this, serverNames, sniNames);
	}
	$var($Collection, matchers, params->getSNIMatchers());
	if (matchers != nullptr) {
		this->noSniMatcher = matchers->isEmpty();
		$set(this, sniMatchers, matchers);
	}
	$assign(sa, params->getApplicationProtocols());
	if (sa != nullptr) {
		$set(this, applicationProtocols, sa);
	}
	this->preferLocalCipherSuites = params->getUseCipherSuitesOrder();
	this->enableRetransmissions = params->getEnableRetransmissions();
	this->maximumPacketSize = params->getMaximumPacketSize();
}

void SSLConfiguration::addHandshakeCompletedListener($HandshakeCompletedListener* listener) {
	if (this->handshakeListeners == nullptr) {
		$set(this, handshakeListeners, $new($HashMap, 4));
	}
	$nc(this->handshakeListeners)->put(listener, $($AccessController::getContext()));
}

void SSLConfiguration::removeHandshakeCompletedListener($HandshakeCompletedListener* listener) {
	if (this->handshakeListeners == nullptr) {
		$throwNew($IllegalArgumentException, "no listeners"_s);
	}
	if ($nc(this->handshakeListeners)->remove(listener) == nullptr) {
		$throwNew($IllegalArgumentException, "listener not registered"_s);
	}
	if ($nc(this->handshakeListeners)->isEmpty()) {
		$set(this, handshakeListeners, nullptr);
	}
}

bool SSLConfiguration::isAvailable($SSLExtension* extension) {
	{
		$var($Iterator, i$, $nc(this->enabledProtocols)->iterator());
		for (; $nc(i$)->hasNext();) {
			$ProtocolVersion* protocolVersion = $cast($ProtocolVersion, i$->next());
			{
				if ($nc(extension)->isAvailable(protocolVersion)) {
					$init($SSLExtension$ClientExtensions);
					$init($SSLExtension$ServerExtensions);
					if (this->isClientMode ? $nc($SSLExtension$ClientExtensions::defaults)->contains(extension) : $nc($SSLExtension$ServerExtensions::defaults)->contains(extension)) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool SSLConfiguration::isAvailable($SSLExtension* extension, $ProtocolVersion* protocolVersion) {
	bool var$0 = $nc(extension)->isAvailable(protocolVersion);
	$init($SSLExtension$ClientExtensions);
	$init($SSLExtension$ServerExtensions);
	return var$0 && (this->isClientMode ? $nc($SSLExtension$ClientExtensions::defaults)->contains(extension) : $nc($SSLExtension$ServerExtensions::defaults)->contains(extension));
}

$SSLExtensionArray* SSLConfiguration::getEnabledExtensions($SSLHandshake* handshakeType) {
	$useLocalCurrentObjectStackCache();
	$var($List, extensions, $new($ArrayList));
	{
		$var($SSLExtensionArray, arr$, $SSLExtension::values());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$SSLExtension* extension = arr$->get(i$);
			{
				if ($nc(extension)->handshakeType == handshakeType) {
					if (isAvailable(extension)) {
						extensions->add(extension);
					}
				}
			}
		}
	}
	return $fcast($SSLExtensionArray, extensions->toArray($$new($SSLExtensionArray, 0)));
}

$SSLExtensionArray* SSLConfiguration::getExclusiveExtensions($SSLHandshake* handshakeType, $List* excluded) {
	$useLocalCurrentObjectStackCache();
	$var($List, extensions, $new($ArrayList));
	{
		$var($SSLExtensionArray, arr$, $SSLExtension::values());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$SSLExtension* extension = arr$->get(i$);
			{
				if ($nc(extension)->handshakeType == handshakeType) {
					bool var$0 = isAvailable(extension);
					if (var$0 && !$nc(excluded)->contains(extension)) {
						extensions->add(extension);
					}
				}
			}
		}
	}
	return $fcast($SSLExtensionArray, extensions->toArray($$new($SSLExtensionArray, 0)));
}

$SSLExtensionArray* SSLConfiguration::getEnabledExtensions($SSLHandshake* handshakeType, $ProtocolVersion* protocolVersion) {
	return getEnabledExtensions(handshakeType, $($List::of($of(protocolVersion))));
}

$SSLExtensionArray* SSLConfiguration::getEnabledExtensions($SSLHandshake* handshakeType, $List* activeProtocols) {
	$useLocalCurrentObjectStackCache();
	$var($List, extensions, $new($ArrayList));
	{
		$var($SSLExtensionArray, arr$, $SSLExtension::values());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$SSLExtension* extension = arr$->get(i$);
			{
				if ($nc(extension)->handshakeType == handshakeType) {
					if (!isAvailable(extension)) {
						continue;
					}
					{
						$var($Iterator, i$, $nc(activeProtocols)->iterator());
						for (; $nc(i$)->hasNext();) {
							$ProtocolVersion* protocolVersion = $cast($ProtocolVersion, i$->next());
							{
								if (extension->isAvailable(protocolVersion)) {
									extensions->add(extension);
									break;
								}
							}
						}
					}
				}
			}
		}
	}
	return $fcast($SSLExtensionArray, extensions->toArray($$new($SSLExtensionArray, 0)));
}

void SSLConfiguration::toggleClientMode() {
	this->isClientMode ^= true;
	$init($SSLConfiguration$CustomizedClientSignatureSchemes);
	$init($SSLConfiguration$CustomizedServerSignatureSchemes);
	$set(this, signatureSchemes, this->isClientMode ? $SSLConfiguration$CustomizedClientSignatureSchemes::signatureSchemes : $SSLConfiguration$CustomizedServerSignatureSchemes::signatureSchemes);
}

$Object* SSLConfiguration::clone() {
	try {
		$var(SSLConfiguration, config, $cast(SSLConfiguration, $Cloneable::clone()));
		if (this->handshakeListeners != nullptr) {
			$set($nc(config), handshakeListeners, $cast($HashMap, $nc(this->handshakeListeners)->clone()));
		}
		return $of(config);
	} catch ($CloneNotSupportedException& cnse) {
	}
	return $of(nullptr);
}

$List* SSLConfiguration::getCustomizedSignatureScheme($String* propertyName) {
	$init(SSLConfiguration);
	$useLocalCurrentObjectStackCache();
	$var($String, property, $GetPropertyAction::privilegedGetProperty(propertyName));
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,sslctx"_s)) {
		$SSLLogger::fine($$str({"System property "_s, propertyName, " is set to \'"_s, property, "\'"_s}), $$new($ObjectArray, 0));
	}
	if (property != nullptr && !property->isEmpty()) {
		bool var$1 = property->length() > 1;
		bool var$0 = var$1 && property->charAt(0) == u'\"';
		if (var$0 && property->charAt(property->length() - 1) == u'\"') {
			$assign(property, property->substring(1, property->length() - 1));
		}
	}
	if (property != nullptr && !property->isEmpty()) {
		$var($StringArray, signatureSchemeNames, property->split(","_s));
		$var($List, signatureSchemes, $new($ArrayList, signatureSchemeNames->length));
		for (int32_t i = 0; i < signatureSchemeNames->length; ++i) {
			signatureSchemeNames->set(i, $($nc(signatureSchemeNames->get(i))->trim()));
			if ($nc(signatureSchemeNames->get(i))->isEmpty()) {
				continue;
			}
			$SignatureScheme* scheme = $SignatureScheme::nameOf(signatureSchemeNames->get(i));
			if (scheme != nullptr && scheme->isAvailable) {
				signatureSchemes->add(scheme);
			} else {
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,sslctx"_s)) {
					$SSLLogger::fine($$str({"The current installed providers do not support signature scheme: "_s, signatureSchemeNames->get(i)}), $$new($ObjectArray, 0));
				}
			}
		}
		return signatureSchemes;
	}
	return $Collections::emptyList();
}

void clinit$SSLConfiguration($Class* class$) {
	$useLocalCurrentObjectStackCache();
	SSLConfiguration::allowLegacyResumption = $Utilities::getBooleanProperty("jdk.tls.allowLegacyResumption"_s, true);
	SSLConfiguration::allowLegacyMasterSecret = $Utilities::getBooleanProperty("jdk.tls.allowLegacyMasterSecret"_s, true);
	SSLConfiguration::useCompatibilityMode = $Utilities::getBooleanProperty("jdk.tls.client.useCompatibilityMode"_s, true);
	SSLConfiguration::acknowledgeCloseNotify = $Utilities::getBooleanProperty("jdk.tls.acknowledgeCloseNotify"_s, false);
	SSLConfiguration::maxHandshakeMessageSize = $nc($($GetIntegerAction::privilegedGetProperty("jdk.tls.maxHandshakeMessageSize"_s, 32768)))->intValue();
	SSLConfiguration::maxCertificateChainLength = $nc($($GetIntegerAction::privilegedGetProperty("jdk.tls.maxCertificateChainLength"_s, 10)))->intValue();
	{
		bool supportExtendedMasterSecret = $Utilities::getBooleanProperty("jdk.tls.useExtendedMasterSecret"_s, true);
		if (supportExtendedMasterSecret) {
			try {
				$KeyGenerator::getInstance("SunTlsExtendedMasterSecret"_s);
			} catch ($NoSuchAlgorithmException& nae) {
				supportExtendedMasterSecret = false;
			}
		}
		SSLConfiguration::useExtendedMasterSecret = supportExtendedMasterSecret;
	}
}

SSLConfiguration::SSLConfiguration() {
}

$Class* SSLConfiguration::load$($String* name, bool initialize) {
	$loadClass(SSLConfiguration, name, initialize, &_SSLConfiguration_ClassInfo_, clinit$SSLConfiguration, allocate$SSLConfiguration);
	return class$;
}

$Class* SSLConfiguration::class$ = nullptr;

		} // ssl
	} // security
} // sun