#include <sun/security/ssl/SSLSessionImpl.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/lang/SecurityManager.h>
#include <java/math/BigInteger.h>
#include <java/net/InetAddress.h>
#include <java/net/UnknownHostException.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/Permission.h>
#include <java/security/Principal.h>
#include <java/security/PrivateKey.h>
#include <java/security/SecureRandom.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Queue.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentLinkedQueue.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <javax/net/ssl/ExtendedSSLSession.h>
#include <javax/net/ssl/SNIHostName.h>
#include <javax/net/ssl/SNIServerName.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLPeerUnverifiedException.h>
#include <javax/net/ssl/SSLPermission.h>
#include <javax/net/ssl/SSLSession.h>
#include <javax/net/ssl/SSLSessionBindingEvent.h>
#include <javax/net/ssl/SSLSessionBindingListener.h>
#include <javax/net/ssl/SSLSessionContext.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/DTLSRecord.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/OutputRecord.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLExtension.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLRecord.h>
#include <sun/security/ssl/SSLSessionContextImpl.h>
#include <sun/security/ssl/SSLTransport.h>
#include <sun/security/ssl/SecureKey.h>
#include <sun/security/ssl/SessionId.h>
#include <sun/security/ssl/SignatureScheme.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/Utilities.h>
#include <sun/security/x509/X509CertImpl.h>
#include <jcpp.h>

#undef BYTES
#undef CH_EXTENDED_MASTER_SECRET
#undef C_NULL
#undef DSA_SHA1
#undef ECDSA_SHA1
#undef NONE
#undef ONE
#undef RSA_PKCS1_SHA1
#undef SH_EXTENDED_MASTER_SECRET
#undef ZERO

using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $SignatureSchemeArray = $Array<::sun::security::ssl::SignatureScheme>;
using $IOException = ::java::io::IOException;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityManager = ::java::lang::SecurityManager;
using $Short = ::java::lang::Short;
using $BigInteger = ::java::math::BigInteger;
using $InetAddress = ::java::net::InetAddress;
using $UnknownHostException = ::java::net::UnknownHostException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Permission = ::java::security::Permission;
using $Principal = ::java::security::Principal;
using $PrivateKey = ::java::security::PrivateKey;
using $SecureRandom = ::java::security::SecureRandom;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Queue = ::java::util::Queue;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentLinkedQueue = ::java::util::concurrent::ConcurrentLinkedQueue;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $SecretKey = ::javax::crypto::SecretKey;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;
using $ExtendedSSLSession = ::javax::net::ssl::ExtendedSSLSession;
using $SNIHostName = ::javax::net::ssl::SNIHostName;
using $SNIServerName = ::javax::net::ssl::SNIServerName;
using $SSLException = ::javax::net::ssl::SSLException;
using $SSLPeerUnverifiedException = ::javax::net::ssl::SSLPeerUnverifiedException;
using $SSLPermission = ::javax::net::ssl::SSLPermission;
using $SSLSession = ::javax::net::ssl::SSLSession;
using $SSLSessionBindingEvent = ::javax::net::ssl::SSLSessionBindingEvent;
using $SSLSessionBindingListener = ::javax::net::ssl::SSLSessionBindingListener;
using $SSLSessionContext = ::javax::net::ssl::SSLSessionContext;
using $CipherSuite = ::sun::security::ssl::CipherSuite;
using $DTLSRecord = ::sun::security::ssl::DTLSRecord;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $OutputRecord = ::sun::security::ssl::OutputRecord;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $Record = ::sun::security::ssl::Record;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLExtension = ::sun::security::ssl::SSLExtension;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLRecord = ::sun::security::ssl::SSLRecord;
using $SSLSessionContextImpl = ::sun::security::ssl::SSLSessionContextImpl;
using $SSLTransport = ::sun::security::ssl::SSLTransport;
using $SecureKey = ::sun::security::ssl::SecureKey;
using $SessionId = ::sun::security::ssl::SessionId;
using $SignatureScheme = ::sun::security::ssl::SignatureScheme;
using $Utilities = ::sun::security::ssl::Utilities;
using $X509CertImpl = ::sun::security::x509::X509CertImpl;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLSessionImpl_FieldInfo_[] = {
	{"protocolVersion", "Lsun/security/ssl/ProtocolVersion;", nullptr, $PRIVATE | $FINAL, $field(SSLSessionImpl, protocolVersion)},
	{"sessionId", "Lsun/security/ssl/SessionId;", nullptr, $PRIVATE | $FINAL, $field(SSLSessionImpl, sessionId)},
	{"peerCerts", "[Ljava/security/cert/X509Certificate;", nullptr, $PRIVATE, $field(SSLSessionImpl, peerCerts)},
	{"cipherSuite", "Lsun/security/ssl/CipherSuite;", nullptr, $PRIVATE, $field(SSLSessionImpl, cipherSuite)},
	{"masterSecret", "Ljavax/crypto/SecretKey;", nullptr, $PRIVATE, $field(SSLSessionImpl, masterSecret)},
	{"useExtendedMasterSecret", "Z", nullptr, $FINAL, $field(SSLSessionImpl, useExtendedMasterSecret)},
	{"creationTime", "J", nullptr, $PRIVATE | $FINAL, $field(SSLSessionImpl, creationTime)},
	{"lastUsedTime", "J", nullptr, $PRIVATE, $field(SSLSessionImpl, lastUsedTime)},
	{"host", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(SSLSessionImpl, host)},
	{"port", "I", nullptr, $PRIVATE | $FINAL, $field(SSLSessionImpl, port)},
	{"context", "Lsun/security/ssl/SSLSessionContextImpl;", nullptr, $PRIVATE, $field(SSLSessionImpl, context)},
	{"invalidated", "Z", nullptr, $PRIVATE, $field(SSLSessionImpl, invalidated)},
	{"localCerts", "[Ljava/security/cert/X509Certificate;", nullptr, $PRIVATE, $field(SSLSessionImpl, localCerts)},
	{"localPrivateKey", "Ljava/security/PrivateKey;", nullptr, $PRIVATE, $field(SSLSessionImpl, localPrivateKey)},
	{"localSupportedSignAlgs", "Ljava/util/Collection;", "Ljava/util/Collection<Lsun/security/ssl/SignatureScheme;>;", $PRIVATE | $FINAL, $field(SSLSessionImpl, localSupportedSignAlgs)},
	{"peerSupportedSignAlgs", "Ljava/util/Collection;", "Ljava/util/Collection<Lsun/security/ssl/SignatureScheme;>;", $PRIVATE, $field(SSLSessionImpl, peerSupportedSignAlgs)},
	{"useDefaultPeerSignAlgs", "Z", nullptr, $PRIVATE, $field(SSLSessionImpl, useDefaultPeerSignAlgs)},
	{"statusResponses", "Ljava/util/List;", "Ljava/util/List<[B>;", $PRIVATE, $field(SSLSessionImpl, statusResponses)},
	{"resumptionMasterSecret", "Ljavax/crypto/SecretKey;", nullptr, $PRIVATE, $field(SSLSessionImpl, resumptionMasterSecret)},
	{"preSharedKey", "Ljavax/crypto/SecretKey;", nullptr, $PRIVATE, $field(SSLSessionImpl, preSharedKey)},
	{"pskIdentity", "[B", nullptr, $PRIVATE, $field(SSLSessionImpl, pskIdentity)},
	{"ticketCreationTime", "J", nullptr, $PRIVATE | $FINAL, $field(SSLSessionImpl, ticketCreationTime)},
	{"ticketAgeAdd", "I", nullptr, $PRIVATE, $field(SSLSessionImpl, ticketAgeAdd)},
	{"negotiatedMaxFragLen", "I", nullptr, $PRIVATE, $field(SSLSessionImpl, negotiatedMaxFragLen)},
	{"maximumPacketSize", "I", nullptr, $PRIVATE, $field(SSLSessionImpl, maximumPacketSize)},
	{"childSessions", "Ljava/util/Queue;", "Ljava/util/Queue<Lsun/security/ssl/SSLSessionImpl;>;", $PRIVATE | $FINAL, $field(SSLSessionImpl, childSessions)},
	{"isSessionResumption", "Z", nullptr, $PRIVATE, $field(SSLSessionImpl, isSessionResumption$)},
	{"defaultRejoinable", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SSLSessionImpl, defaultRejoinable)},
	{"serverNameIndication", "Ljavax/net/ssl/SNIServerName;", nullptr, $FINAL, $field(SSLSessionImpl, serverNameIndication)},
	{"requestedServerNames", "Ljava/util/List;", "Ljava/util/List<Ljavax/net/ssl/SNIServerName;>;", $PRIVATE | $FINAL, $field(SSLSessionImpl, requestedServerNames)},
	{"ticketNonceCounter", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(SSLSessionImpl, ticketNonceCounter)},
	{"identificationProtocol", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(SSLSessionImpl, identificationProtocol)},
	{"sessionLock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $PRIVATE | $FINAL, $field(SSLSessionImpl, sessionLock)},
	{"defaultPeerSupportedSignAlgs", "Ljava/util/ArrayList;", "Ljava/util/ArrayList<Lsun/security/ssl/SignatureScheme;>;", $PRIVATE | $STATIC | $FINAL, $staticField(SSLSessionImpl, defaultPeerSupportedSignAlgs)},
	{"boundValues", "Ljava/util/concurrent/ConcurrentHashMap;", "Ljava/util/concurrent/ConcurrentHashMap<Lsun/security/ssl/SecureKey;Ljava/lang/Object;>;", $PRIVATE | $FINAL, $field(SSLSessionImpl, boundValues)},
	{"updateNST", "Z", nullptr, 0, $field(SSLSessionImpl, updateNST)},
	{"acceptLargeFragments", "Z", nullptr, $PRIVATE, $field(SSLSessionImpl, acceptLargeFragments)},
	{}
};

$MethodInfo _SSLSessionImpl_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(SSLSessionImpl, init$, void)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Lsun/security/ssl/CipherSuite;)V", nullptr, 0, $method(SSLSessionImpl, init$, void, $HandshakeContext*, $CipherSuite*)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Lsun/security/ssl/CipherSuite;Lsun/security/ssl/SessionId;)V", nullptr, 0, $method(SSLSessionImpl, init$, void, $HandshakeContext*, $CipherSuite*, $SessionId*)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Lsun/security/ssl/CipherSuite;Lsun/security/ssl/SessionId;J)V", nullptr, 0, $method(SSLSessionImpl, init$, void, $HandshakeContext*, $CipherSuite*, $SessionId*, int64_t)},
	{"<init>", "(Lsun/security/ssl/SSLSessionImpl;Lsun/security/ssl/SessionId;)V", nullptr, 0, $method(SSLSessionImpl, init$, void, SSLSessionImpl*, $SessionId*)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, 0, $method(SSLSessionImpl, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"addChild", "(Lsun/security/ssl/SSLSessionImpl;)V", nullptr, 0, $method(SSLSessionImpl, addChild, void, SSLSessionImpl*)},
	{"consumePreSharedKey", "()Ljavax/crypto/SecretKey;", nullptr, 0, $method(SSLSessionImpl, consumePreSharedKey, $SecretKey*)},
	{"consumePskIdentity", "()[B", nullptr, 0, $method(SSLSessionImpl, consumePskIdentity, $bytes*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, equals, bool, Object$*)},
	{"expandBufferSizes", "()V", nullptr, $PROTECTED, $method(SSLSessionImpl, expandBufferSizes, void)},
	{"finish", "()Lsun/security/ssl/SSLSessionImpl;", nullptr, 0, $method(SSLSessionImpl, finish, SSLSessionImpl*)},
	{"getApplicationBufferSize", "()I", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, getApplicationBufferSize, int32_t)},
	{"getCertificateChain", "()[Ljava/security/cert/X509Certificate;", nullptr, $PUBLIC, $method(SSLSessionImpl, getCertificateChain, $X509CertificateArray*), "javax.net.ssl.SSLPeerUnverifiedException"},
	{"getCipherSuite", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, getCipherSuite, $String*)},
	{"getCreationTime", "()J", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, getCreationTime, int64_t)},
	{"getId", "()[B", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, getId, $bytes*)},
	{"getIdentificationProtocol", "()Ljava/lang/String;", nullptr, 0, $method(SSLSessionImpl, getIdentificationProtocol, $String*)},
	{"getLastAccessedTime", "()J", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, getLastAccessedTime, int64_t)},
	{"getLocalCertificates", "()[Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, getLocalCertificates, $CertificateArray*)},
	{"getLocalPrincipal", "()Ljava/security/Principal;", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, getLocalPrincipal, $Principal*)},
	{"getLocalSupportedSignatureAlgorithms", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, getLocalSupportedSignatureAlgorithms, $StringArray*)},
	{"getLocalSupportedSignatureSchemes", "()Ljava/util/Collection;", "()Ljava/util/Collection<Lsun/security/ssl/SignatureScheme;>;", $PUBLIC, $method(SSLSessionImpl, getLocalSupportedSignatureSchemes, $Collection*)},
	{"getMasterSecret", "()Ljavax/crypto/SecretKey;", nullptr, 0, $method(SSLSessionImpl, getMasterSecret, $SecretKey*)},
	{"getMaximumPacketSize", "()I", nullptr, 0, $method(SSLSessionImpl, getMaximumPacketSize, int32_t)},
	{"getNegotiatedMaxFragSize", "()I", nullptr, 0, $method(SSLSessionImpl, getNegotiatedMaxFragSize, int32_t)},
	{"getPacketBufferSize", "()I", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, getPacketBufferSize, int32_t)},
	{"getPeerAddress", "()Ljava/net/InetAddress;", nullptr, $PUBLIC, $method(SSLSessionImpl, getPeerAddress, $InetAddress*)},
	{"getPeerCertificates", "()[Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, getPeerCertificates, $CertificateArray*), "javax.net.ssl.SSLPeerUnverifiedException"},
	{"getPeerHost", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, getPeerHost, $String*)},
	{"getPeerPort", "()I", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, getPeerPort, int32_t)},
	{"getPeerPrincipal", "()Ljava/security/Principal;", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, getPeerPrincipal, $Principal*), "javax.net.ssl.SSLPeerUnverifiedException"},
	{"getPeerSupportedSignatureAlgorithms", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, getPeerSupportedSignatureAlgorithms, $StringArray*)},
	{"getPreSharedKey", "()Ljavax/crypto/SecretKey;", nullptr, 0, $method(SSLSessionImpl, getPreSharedKey, $SecretKey*)},
	{"getProtocol", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, getProtocol, $String*)},
	{"getProtocolVersion", "()Lsun/security/ssl/ProtocolVersion;", nullptr, 0, $method(SSLSessionImpl, getProtocolVersion, $ProtocolVersion*)},
	{"getPskIdentity", "()[B", nullptr, 0, $method(SSLSessionImpl, getPskIdentity, $bytes*)},
	{"getRequestedServerNames", "()Ljava/util/List;", "()Ljava/util/List<Ljavax/net/ssl/SNIServerName;>;", $PUBLIC, $virtualMethod(SSLSessionImpl, getRequestedServerNames, $List*)},
	{"getResumptionMasterSecret", "()Ljavax/crypto/SecretKey;", nullptr, 0, $method(SSLSessionImpl, getResumptionMasterSecret, $SecretKey*)},
	{"getSessionContext", "()Ljavax/net/ssl/SSLSessionContext;", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, getSessionContext, $SSLSessionContext*)},
	{"getSessionId", "()Lsun/security/ssl/SessionId;", nullptr, 0, $method(SSLSessionImpl, getSessionId, $SessionId*)},
	{"getStatusResponses", "()Ljava/util/List;", "()Ljava/util/List<[B>;", $PUBLIC, $virtualMethod(SSLSessionImpl, getStatusResponses, $List*)},
	{"getSuite", "()Lsun/security/ssl/CipherSuite;", nullptr, 0, $method(SSLSessionImpl, getSuite, $CipherSuite*)},
	{"getTicketAgeAdd", "()I", nullptr, 0, $method(SSLSessionImpl, getTicketAgeAdd, int32_t)},
	{"getTicketCreationTime", "()J", nullptr, $PUBLIC, $method(SSLSessionImpl, getTicketCreationTime, int64_t)},
	{"getValue", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, getValue, $Object*, $String*)},
	{"getValueNames", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, getValueNames, $StringArray*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, hashCode, int32_t)},
	{"incrTicketNonceCounter", "()Ljava/math/BigInteger;", nullptr, 0, $method(SSLSessionImpl, incrTicketNonceCounter, $BigInteger*)},
	{"invalidate", "()V", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, invalidate, void)},
	{"isLocalAuthenticationValid", "()Z", nullptr, $PRIVATE, $method(SSLSessionImpl, isLocalAuthenticationValid, bool)},
	{"isPSKable", "()Z", nullptr, 0, $method(SSLSessionImpl, isPSKable, bool)},
	{"isRejoinable", "()Z", nullptr, 0, $method(SSLSessionImpl, isRejoinable, bool)},
	{"isSessionResumption", "()Z", nullptr, 0, $method(SSLSessionImpl, isSessionResumption, bool)},
	{"isStatelessable", "()Z", nullptr, 0, $method(SSLSessionImpl, isStatelessable, bool)},
	{"isValid", "()Z", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, isValid, bool)},
	{"putValue", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, putValue, void, $String*, Object$*)},
	{"removeValue", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, removeValue, void, $String*)},
	{"setAsSessionResumption", "(Z)V", nullptr, 0, $method(SSLSessionImpl, setAsSessionResumption, void, bool)},
	{"setContext", "(Lsun/security/ssl/SSLSessionContextImpl;)V", nullptr, 0, $method(SSLSessionImpl, setContext, void, $SSLSessionContextImpl*)},
	{"setLastAccessedTime", "(J)V", nullptr, 0, $method(SSLSessionImpl, setLastAccessedTime, void, int64_t)},
	{"setLocalCertificates", "([Ljava/security/cert/X509Certificate;)V", nullptr, 0, $method(SSLSessionImpl, setLocalCertificates, void, $X509CertificateArray*)},
	{"setLocalPrivateKey", "(Ljava/security/PrivateKey;)V", nullptr, 0, $method(SSLSessionImpl, setLocalPrivateKey, void, $PrivateKey*)},
	{"setMasterSecret", "(Ljavax/crypto/SecretKey;)V", nullptr, 0, $method(SSLSessionImpl, setMasterSecret, void, $SecretKey*)},
	{"setMaximumPacketSize", "(I)V", nullptr, 0, $method(SSLSessionImpl, setMaximumPacketSize, void, int32_t)},
	{"setNegotiatedMaxFragSize", "(I)V", nullptr, 0, $method(SSLSessionImpl, setNegotiatedMaxFragSize, void, int32_t)},
	{"setPeerCertificates", "([Ljava/security/cert/X509Certificate;)V", nullptr, 0, $method(SSLSessionImpl, setPeerCertificates, void, $X509CertificateArray*)},
	{"setPeerSupportedSignatureAlgorithms", "(Ljava/util/Collection;)V", "(Ljava/util/Collection<Lsun/security/ssl/SignatureScheme;>;)V", 0, $method(SSLSessionImpl, setPeerSupportedSignatureAlgorithms, void, $Collection*)},
	{"setPreSharedKey", "(Ljavax/crypto/SecretKey;)V", nullptr, 0, $method(SSLSessionImpl, setPreSharedKey, void, $SecretKey*)},
	{"setPskIdentity", "([B)V", nullptr, 0, $method(SSLSessionImpl, setPskIdentity, void, $bytes*)},
	{"setResumptionMasterSecret", "(Ljavax/crypto/SecretKey;)V", nullptr, 0, $method(SSLSessionImpl, setResumptionMasterSecret, void, $SecretKey*)},
	{"setStatusResponses", "(Ljava/util/List;)V", "(Ljava/util/List<[B>;)V", 0, $method(SSLSessionImpl, setStatusResponses, void, $List*)},
	{"setSuite", "(Lsun/security/ssl/CipherSuite;)V", nullptr, 0, $method(SSLSessionImpl, setSuite, void, $CipherSuite*)},
	{"setTicketAgeAdd", "(I)V", nullptr, 0, $method(SSLSessionImpl, setTicketAgeAdd, void, int32_t)},
	{"setUseDefaultPeerSignAlgs", "()V", nullptr, 0, $method(SSLSessionImpl, setUseDefaultPeerSignAlgs, void)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLSessionImpl, toString, $String*)},
	{"write", "()[B", nullptr, 0, $method(SSLSessionImpl, write, $bytes*), "java.lang.Exception"},
	{}
};

$ClassInfo _SSLSessionImpl_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLSessionImpl",
	"javax.net.ssl.ExtendedSSLSession",
	nullptr,
	_SSLSessionImpl_FieldInfo_,
	_SSLSessionImpl_MethodInfo_
};

$Object* allocate$SSLSessionImpl($Class* clazz) {
	return $of($alloc(SSLSessionImpl));
}

$ArrayList* SSLSessionImpl::defaultPeerSupportedSignAlgs = nullptr;

void SSLSessionImpl::init$() {
	$ExtendedSSLSession::init$();
	this->lastUsedTime = 0;
	this->useDefaultPeerSignAlgs = false;
	this->ticketCreationTime = $System::currentTimeMillis();
	this->negotiatedMaxFragLen = -1;
	$set(this, childSessions, $new($ConcurrentLinkedQueue));
	this->isSessionResumption$ = false;
	$init($BigInteger);
	$set(this, ticketNonceCounter, $BigInteger::ONE);
	$set(this, sessionLock, $new($ReentrantLock));
	this->acceptLargeFragments = $Utilities::getBooleanProperty("jsse.SSLEngine.acceptLargeFragments"_s, false);
	$init($ProtocolVersion);
	$set(this, protocolVersion, $ProtocolVersion::NONE);
	$init($CipherSuite);
	$set(this, cipherSuite, $CipherSuite::C_NULL);
	$set(this, sessionId, $new($SessionId, false, nullptr));
	$set(this, host, nullptr);
	this->port = -1;
	$set(this, localSupportedSignAlgs, $Collections::emptySet());
	$set(this, serverNameIndication, nullptr);
	$set(this, requestedServerNames, $Collections::emptyList());
	this->useExtendedMasterSecret = false;
	this->creationTime = $System::currentTimeMillis();
	$set(this, identificationProtocol, nullptr);
	$set(this, boundValues, $new($ConcurrentHashMap));
}

void SSLSessionImpl::init$($HandshakeContext* hc, $CipherSuite* cipherSuite) {
	$useLocalCurrentObjectStackCache();
	SSLSessionImpl::init$(hc, cipherSuite, $$new($SessionId, SSLSessionImpl::defaultRejoinable, $($nc($nc(hc)->sslContext)->getSecureRandom())));
}

void SSLSessionImpl::init$($HandshakeContext* hc, $CipherSuite* cipherSuite, $SessionId* id) {
	SSLSessionImpl::init$(hc, cipherSuite, id, $System::currentTimeMillis());
}

void SSLSessionImpl::init$($HandshakeContext* hc, $CipherSuite* cipherSuite, $SessionId* id, int64_t creationTime) {
	$useLocalCurrentObjectStackCache();
	$ExtendedSSLSession::init$();
	this->lastUsedTime = 0;
	this->useDefaultPeerSignAlgs = false;
	this->ticketCreationTime = $System::currentTimeMillis();
	this->negotiatedMaxFragLen = -1;
	$set(this, childSessions, $new($ConcurrentLinkedQueue));
	this->isSessionResumption$ = false;
	$init($BigInteger);
	$set(this, ticketNonceCounter, $BigInteger::ONE);
	$set(this, sessionLock, $new($ReentrantLock));
	this->acceptLargeFragments = $Utilities::getBooleanProperty("jsse.SSLEngine.acceptLargeFragments"_s, false);
	$set(this, protocolVersion, $nc(hc)->negotiatedProtocol);
	$set(this, cipherSuite, cipherSuite);
	$set(this, sessionId, id);
	$set(this, host, $nc($nc(hc->conContext)->transport)->getPeerHost());
	this->port = $nc($nc(hc->conContext)->transport)->getPeerPort();
	$set(this, localSupportedSignAlgs, hc->localSupportedSignAlgs == nullptr ? static_cast<$Collection*>($Collections::emptySet()) : $Collections::unmodifiableCollection(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>($$new($ArrayList, static_cast<$Collection*>(hc->localSupportedSignAlgs)))))));
	$set(this, serverNameIndication, hc->negotiatedServerName);
	$set(this, requestedServerNames, $List::copyOf($(hc->getRequestedServerNames())));
	if ($nc(hc->sslConfig)->isClientMode) {
		$init($SSLExtension);
		bool var$0 = ($nc(hc->handshakeExtensions)->get($SSLExtension::CH_EXTENDED_MASTER_SECRET) != nullptr);
		this->useExtendedMasterSecret = var$0 && ($nc(hc->handshakeExtensions)->get($SSLExtension::SH_EXTENDED_MASTER_SECRET) != nullptr);
	} else {
		$init($SSLExtension);
		bool var$1 = ($nc(hc->handshakeExtensions)->get($SSLExtension::CH_EXTENDED_MASTER_SECRET) != nullptr);
		this->useExtendedMasterSecret = var$1 && (!$nc(hc->negotiatedProtocol)->useTLS13PlusSpec());
	}
	this->creationTime = creationTime;
	$set(this, identificationProtocol, $nc(hc->sslConfig)->identificationProtocol);
	$set(this, boundValues, $new($ConcurrentHashMap));
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("session"_s)) {
		$SSLLogger::finest($$str({"Session initialized:  "_s, this}), $$new($ObjectArray, 0));
	}
}

void SSLSessionImpl::init$(SSLSessionImpl* baseSession, $SessionId* newId) {
	$useLocalCurrentObjectStackCache();
	$ExtendedSSLSession::init$();
	this->lastUsedTime = 0;
	this->useDefaultPeerSignAlgs = false;
	this->ticketCreationTime = $System::currentTimeMillis();
	this->negotiatedMaxFragLen = -1;
	$set(this, childSessions, $new($ConcurrentLinkedQueue));
	this->isSessionResumption$ = false;
	$init($BigInteger);
	$set(this, ticketNonceCounter, $BigInteger::ONE);
	$set(this, sessionLock, $new($ReentrantLock));
	this->acceptLargeFragments = $Utilities::getBooleanProperty("jsse.SSLEngine.acceptLargeFragments"_s, false);
	$set(this, protocolVersion, $nc(baseSession)->getProtocolVersion());
	$set(this, cipherSuite, baseSession->cipherSuite);
	$set(this, sessionId, newId);
	$set(this, host, baseSession->getPeerHost());
	this->port = baseSession->getPeerPort();
	$set(this, localSupportedSignAlgs, baseSession->localSupportedSignAlgs == nullptr ? static_cast<$Collection*>($Collections::emptySet()) : baseSession->localSupportedSignAlgs);
	$set(this, peerSupportedSignAlgs, baseSession->peerSupportedSignAlgs == nullptr ? static_cast<$Collection*>($Collections::emptySet()) : baseSession->peerSupportedSignAlgs);
	$set(this, serverNameIndication, baseSession->serverNameIndication);
	$set(this, requestedServerNames, baseSession->getRequestedServerNames());
	$set(this, masterSecret, baseSession->getMasterSecret());
	this->useExtendedMasterSecret = baseSession->useExtendedMasterSecret;
	this->creationTime = baseSession->getCreationTime();
	this->lastUsedTime = $System::currentTimeMillis();
	$set(this, identificationProtocol, baseSession->getIdentificationProtocol());
	$set(this, localCerts, baseSession->localCerts);
	$set(this, peerCerts, baseSession->peerCerts);
	$set(this, statusResponses, baseSession->statusResponses);
	$set(this, resumptionMasterSecret, baseSession->resumptionMasterSecret);
	$set(this, context, baseSession->context);
	this->negotiatedMaxFragLen = baseSession->negotiatedMaxFragLen;
	this->maximumPacketSize = baseSession->maximumPacketSize;
	$set(this, boundValues, baseSession->boundValues);
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("session"_s)) {
		$SSLLogger::finest($$str({"Session initialized:  "_s, this}), $$new($ObjectArray, 0));
	}
}

void SSLSessionImpl::init$($HandshakeContext* hc, $ByteBuffer* buf) {
	$useLocalCurrentObjectStackCache();
	$ExtendedSSLSession::init$();
	this->lastUsedTime = 0;
	this->useDefaultPeerSignAlgs = false;
	this->ticketCreationTime = $System::currentTimeMillis();
	this->negotiatedMaxFragLen = -1;
	$set(this, childSessions, $new($ConcurrentLinkedQueue));
	this->isSessionResumption$ = false;
	$init($BigInteger);
	$set(this, ticketNonceCounter, $BigInteger::ONE);
	$set(this, sessionLock, $new($ReentrantLock));
	this->acceptLargeFragments = $Utilities::getBooleanProperty("jsse.SSLEngine.acceptLargeFragments"_s, false);
	$set(this, boundValues, $new($ConcurrentHashMap));
	$set(this, protocolVersion, $ProtocolVersion::valueOf($Short::toUnsignedInt($nc(buf)->getShort())));
	$set(this, sessionId, $new($SessionId, true, $($nc($nc(hc)->sslContext)->getSecureRandom())));
	$set(this, cipherSuite, $CipherSuite::valueOf($Short::toUnsignedInt($nc(buf)->getShort())));
	$var($ArrayList, list, $new($ArrayList));
	int32_t i = $Byte::toUnsignedInt($nc(buf)->get());
	while (i-- > 0) {
		list->add($($SignatureScheme::valueOf($Short::toUnsignedInt($nc(buf)->getShort()))));
	}
	$set(this, localSupportedSignAlgs, $Collections::unmodifiableCollection(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>(list)))));
	i = $Byte::toUnsignedInt($nc(buf)->get());
	list->clear();
	while (i-- > 0) {
		list->add($($SignatureScheme::valueOf($Short::toUnsignedInt($nc(buf)->getShort()))));
	}
	$set(this, peerSupportedSignAlgs, $Collections::unmodifiableCollection(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>(list)))));
	$var($bytes, b, nullptr);
	i = $Short::toUnsignedInt($nc(buf)->getShort());
	if (i > 0) {
		$assign(b, $new($bytes, i));
		$nc(buf)->get(b, 0, i);
		i = $Short::toUnsignedInt(buf->getShort());
		$assign(b, $new($bytes, i));
		buf->get(b);
		$set(this, preSharedKey, $new($SecretKeySpec, b, "TlsMasterSecret"_s));
	} else {
		$set(this, preSharedKey, nullptr);
	}
	i = $nc(buf)->get();
	if (i > 0) {
		$assign(b, $new($bytes, i));
		buf->get(b);
		$set(this, pskIdentity, b);
	} else {
		$set(this, pskIdentity, nullptr);
	}
	i = buf->get();
	if (i > 0) {
		$assign(b, $new($bytes, i));
		buf->get(b, 0, i);
		i = $Short::toUnsignedInt(buf->getShort());
		$assign(b, $new($bytes, i));
		buf->get(b);
		$set(this, masterSecret, $new($SecretKeySpec, b, "TlsMasterSecret"_s));
	} else {
		$set(this, masterSecret, nullptr);
	}
	this->useExtendedMasterSecret = (buf->get() != 0);
	i = buf->get();
	if (i == 0) {
		$set(this, identificationProtocol, nullptr);
	} else {
		$assign(b, $new($bytes, i));
		buf->get(b);
		$set(this, identificationProtocol, $new($String, b));
	}
	i = buf->get();
	if (i == 0) {
		$set(this, serverNameIndication, nullptr);
	} else {
		$assign(b, $new($bytes, i));
		buf->get(b, 0, b->length);
		$set(this, serverNameIndication, $new($SNIHostName, b));
	}
	int32_t len = $Short::toUnsignedInt(buf->getShort());
	if (len == 0) {
		$set(this, requestedServerNames, $Collections::emptyList());
	} else {
		$set(this, requestedServerNames, $new($ArrayList));
		while (len > 0) {
			int32_t l = buf->get();
			$assign(b, $new($bytes, l));
			buf->get(b, 0, l);
			$nc(this->requestedServerNames)->add($$new($SNIHostName, $$new($String, b)));
			--len;
		}
	}
	this->maximumPacketSize = buf->getInt();
	this->negotiatedMaxFragLen = buf->getInt();
	this->creationTime = buf->getLong();
	len = $Short::toUnsignedInt(buf->getShort());
	if (len == 0) {
		$set(this, statusResponses, $Collections::emptyList());
	} else {
		$set(this, statusResponses, $new($ArrayList));
	}
	while (len-- > 0) {
		$assign(b, $new($bytes, $Short::toUnsignedInt(buf->getShort())));
		buf->get(b);
		$nc(this->statusResponses)->add(b);
	}
	i = $Byte::toUnsignedInt(buf->get());
	if (i == 0) {
		$set(this, host, $new($String));
	} else {
		$assign(b, $new($bytes, i));
		buf->get(b, 0, i);
		$set(this, host, $new($String, b));
	}
	this->port = $Short::toUnsignedInt(buf->getShort());
	i = buf->get();
	if (i == 0) {
		$set(this, peerCerts, nullptr);
	} else {
		$set(this, peerCerts, $new($X509CertificateArray, i));
		int32_t j = 0;
		while (i > j) {
			$assign(b, $new($bytes, buf->getInt()));
			buf->get(b);
			try {
				$nc(this->peerCerts)->set(j, $$new($X509CertImpl, b));
			} catch ($Exception& e) {
				$throwNew($IOException, static_cast<$Throwable*>(e));
			}
			++j;
		}
	}
	{
		$var($String, alg, nullptr)
		switch (buf->get()) {
		case 0:
			{
				break;
			}
		case 1:
			{
				len = buf->get();
				$set(this, localCerts, $new($X509CertificateArray, len));
				i = 0;
				while (len > i) {
					$assign(b, $new($bytes, buf->getInt()));
					buf->get(b);
					try {
						$nc(this->localCerts)->set(i, $$new($X509CertImpl, b));
					} catch ($Exception& e) {
						$throwNew($IOException, static_cast<$Throwable*>(e));
					}
					++i;
				}
				break;
			}
		case 2:
			{
				i = buf->get();
				$assign(b, $new($bytes, i));
				buf->get(b, 0, i);
				$assign(alg, $new($String, b));
				i = $Short::toUnsignedInt(buf->getShort());
				$assign(b, $new($bytes, i));
				buf->get(b);
				$set(this, preSharedKey, $new($SecretKeySpec, b, alg));
				$set(this, pskIdentity, $new($bytes, buf->get()));
				buf->get(this->pskIdentity);
				break;
			}
		default:
			{
				$throwNew($SSLException, "Failed local certs of session."_s);
			}
		}
	}
	$set(this, context, $cast($SSLSessionContextImpl, $nc($nc(hc)->sslContext)->engineGetServerSessionContext()));
	this->lastUsedTime = $System::currentTimeMillis();
}

bool SSLSessionImpl::isStatelessable() {
	$useLocalCurrentObjectStackCache();
	bool var$0 = !this->protocolVersion->useTLS13PlusSpec();
	if (var$0 && $nc($(getMasterSecret()))->getEncoded() == nullptr) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::finest("No MasterSecret, cannot make stateless ticket"_s, $$new($ObjectArray, 0));
		}
		return false;
	}
	if (this->boundValues != nullptr && $nc(this->boundValues)->size() > 0) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::finest("There are boundValues, cannot make stateless ticket"_s, $$new($ObjectArray, 0));
		}
		return false;
	}
	return true;
}

$bytes* SSLSessionImpl::write() {
	$useLocalCurrentObjectStackCache();
	$var($bytes, b, nullptr);
	$var($HandshakeOutStream, hos, $new($HandshakeOutStream, nullptr));
	hos->putInt16(this->protocolVersion->id);
	hos->putInt16($nc(this->cipherSuite)->id);
	hos->putInt8($nc(this->localSupportedSignAlgs)->size());
	{
		$var($Iterator, i$, $nc(this->localSupportedSignAlgs)->iterator());
		for (; $nc(i$)->hasNext();) {
			$SignatureScheme* s = $cast($SignatureScheme, i$->next());
			{
				hos->putInt16($nc(s)->id);
			}
		}
	}
	hos->putInt8($nc(this->peerSupportedSignAlgs)->size());
	{
		$var($Iterator, i$, $nc(this->peerSupportedSignAlgs)->iterator());
		for (; $nc(i$)->hasNext();) {
			$SignatureScheme* s = $cast($SignatureScheme, i$->next());
			{
				hos->putInt16($nc(s)->id);
			}
		}
	}
	if (this->preSharedKey == nullptr || $nc(this->preSharedKey)->getAlgorithm() == nullptr) {
		hos->putInt16(0);
	} else {
		hos->putInt16($nc($($nc(this->preSharedKey)->getAlgorithm()))->length());
		if ($nc($($nc(this->preSharedKey)->getAlgorithm()))->length() != 0) {
			hos->write($($nc($($nc(this->preSharedKey)->getAlgorithm()))->getBytes()));
		}
		$assign(b, $nc(this->preSharedKey)->getEncoded());
		hos->putInt16($nc(b)->length);
		hos->write(b, 0, $nc(b)->length);
	}
	if (this->pskIdentity == nullptr) {
		hos->putInt8(0);
	} else {
		hos->putInt8($nc(this->pskIdentity)->length);
		hos->write(this->pskIdentity, 0, $nc(this->pskIdentity)->length);
	}
	bool var$0 = getMasterSecret() == nullptr;
	if (var$0 || $nc($(getMasterSecret()))->getAlgorithm() == nullptr) {
		hos->putInt8(0);
	} else {
		hos->putInt8($nc($($nc($(getMasterSecret()))->getAlgorithm()))->length());
		if ($nc($($nc($(getMasterSecret()))->getAlgorithm()))->length() != 0) {
			hos->write($($nc($($nc($(getMasterSecret()))->getAlgorithm()))->getBytes()));
		}
		$assign(b, $nc($(getMasterSecret()))->getEncoded());
		hos->putInt16($nc(b)->length);
		hos->write(b, 0, $nc(b)->length);
	}
	hos->putInt8(this->useExtendedMasterSecret ? 1 : 0);
	if (this->identificationProtocol == nullptr) {
		hos->putInt8(0);
	} else {
		hos->putInt8($nc(this->identificationProtocol)->length());
		$var($bytes, var$1, $nc(this->identificationProtocol)->getBytes());
		hos->write(var$1, 0, $nc(this->identificationProtocol)->length());
	}
	if (this->serverNameIndication == nullptr) {
		hos->putInt8(0);
	} else {
		$assign(b, $nc(this->serverNameIndication)->getEncoded());
		hos->putInt8($nc(b)->length);
		hos->write(b, 0, $nc(b)->length);
	}
	hos->putInt16($nc(this->requestedServerNames)->size());
	if ($nc(this->requestedServerNames)->size() > 0) {
		{
			$var($Iterator, i$, $nc(this->requestedServerNames)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($SNIServerName, sn, $cast($SNIServerName, i$->next()));
				{
					$assign(b, $nc(sn)->getEncoded());
					hos->putInt8($nc(b)->length);
					hos->write(b, 0, $nc(b)->length);
				}
			}
		}
	}
	hos->putInt32(this->maximumPacketSize);
	hos->putInt32(this->negotiatedMaxFragLen);
	$var($ByteBuffer, buffer, $ByteBuffer::allocate($Long::BYTES));
	hos->writeBytes($($cast($bytes, $nc($($nc(buffer)->putLong(this->creationTime)))->array())));
	$var($List, list, getStatusResponses());
	int32_t l = $nc(list)->size();
	hos->putInt16(l);
	{
		$var($Iterator, i$, list->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($bytes, e, $cast($bytes, i$->next()));
			{
				hos->putInt16($nc(e)->length);
				hos->write(e);
			}
		}
	}
	if (this->host == nullptr || $nc(this->host)->length() == 0) {
		hos->putInt8(0);
	} else {
		hos->putInt8($nc(this->host)->length());
		hos->writeBytes($($nc(this->host)->getBytes()));
	}
	hos->putInt16(this->port);
	if (this->peerCerts == nullptr || $nc(this->peerCerts)->length == 0) {
		hos->putInt8(0);
	} else {
		hos->putInt8($nc(this->peerCerts)->length);
		{
			$var($X509CertificateArray, arr$, this->peerCerts);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($X509Certificate, c, arr$->get(i$));
				{
					$assign(b, $nc(c)->getEncoded());
					hos->putInt32($nc(b)->length);
					hos->writeBytes(b);
				}
			}
		}
	}
	if (this->localCerts != nullptr && $nc(this->localCerts)->length > 0) {
		hos->putInt8(1);
		hos->putInt8($nc(this->localCerts)->length);
		{
			$var($X509CertificateArray, arr$, this->localCerts);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($X509Certificate, c, arr$->get(i$));
				{
					$assign(b, $nc(c)->getEncoded());
					hos->putInt32($nc(b)->length);
					hos->writeBytes(b);
				}
			}
		}
	} else if (this->preSharedKey != nullptr) {
		hos->putInt8(2);
		hos->putInt8($nc($($nc(this->preSharedKey)->getAlgorithm()))->length());
		hos->write($($nc($($nc(this->preSharedKey)->getAlgorithm()))->getBytes()));
		$assign(b, $nc(this->preSharedKey)->getEncoded());
		hos->putInt32($nc(b)->length);
		hos->writeBytes(b);
		hos->putInt32($nc(this->pskIdentity)->length);
		hos->writeBytes(this->pskIdentity);
	} else {
		hos->putInt8(0);
	}
	return hos->toByteArray();
}

void SSLSessionImpl::setMasterSecret($SecretKey* secret) {
	$set(this, masterSecret, secret);
}

void SSLSessionImpl::setResumptionMasterSecret($SecretKey* secret) {
	$set(this, resumptionMasterSecret, secret);
}

void SSLSessionImpl::setPreSharedKey($SecretKey* key) {
	$set(this, preSharedKey, key);
}

void SSLSessionImpl::addChild(SSLSessionImpl* session) {
	$nc(this->childSessions)->add(session);
}

void SSLSessionImpl::setTicketAgeAdd(int32_t ticketAgeAdd) {
	this->ticketAgeAdd = ticketAgeAdd;
}

void SSLSessionImpl::setPskIdentity($bytes* pskIdentity) {
	$set(this, pskIdentity, pskIdentity);
}

$BigInteger* SSLSessionImpl::incrTicketNonceCounter() {
	$var($BigInteger, result, this->ticketNonceCounter);
	$init($BigInteger);
	$set(this, ticketNonceCounter, $nc(this->ticketNonceCounter)->add($BigInteger::ONE));
	return result;
}

bool SSLSessionImpl::isPSKable() {
	$init($BigInteger);
	return ($nc(this->ticketNonceCounter)->compareTo($BigInteger::ZERO) > 0);
}

$SecretKey* SSLSessionImpl::getMasterSecret() {
	return this->masterSecret;
}

$SecretKey* SSLSessionImpl::getResumptionMasterSecret() {
	return this->resumptionMasterSecret;
}

$SecretKey* SSLSessionImpl::getPreSharedKey() {
	$useLocalCurrentObjectStackCache();
	$nc(this->sessionLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($SecretKey, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, this->preSharedKey);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->sessionLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$SecretKey* SSLSessionImpl::consumePreSharedKey() {
	$useLocalCurrentObjectStackCache();
	$nc(this->sessionLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($SecretKey, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, this->preSharedKey);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$set(this, preSharedKey, nullptr);
			$nc(this->sessionLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

int32_t SSLSessionImpl::getTicketAgeAdd() {
	return this->ticketAgeAdd;
}

$String* SSLSessionImpl::getIdentificationProtocol() {
	return this->identificationProtocol;
}

$bytes* SSLSessionImpl::consumePskIdentity() {
	$useLocalCurrentObjectStackCache();
	$nc(this->sessionLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($bytes, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, this->pskIdentity);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$set(this, pskIdentity, nullptr);
			$nc(this->sessionLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$bytes* SSLSessionImpl::getPskIdentity() {
	return this->pskIdentity;
}

void SSLSessionImpl::setPeerCertificates($X509CertificateArray* peer) {
	if (this->peerCerts == nullptr) {
		$set(this, peerCerts, peer);
	}
}

void SSLSessionImpl::setLocalCertificates($X509CertificateArray* local) {
	$set(this, localCerts, local);
}

void SSLSessionImpl::setLocalPrivateKey($PrivateKey* privateKey) {
	$set(this, localPrivateKey, privateKey);
}

void SSLSessionImpl::setPeerSupportedSignatureAlgorithms($Collection* signatureSchemes) {
	$set(this, peerSupportedSignAlgs, signatureSchemes);
}

void SSLSessionImpl::setUseDefaultPeerSignAlgs() {
	this->useDefaultPeerSignAlgs = true;
	$set(this, peerSupportedSignAlgs, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>(SSLSessionImpl::defaultPeerSupportedSignAlgs))));
}

SSLSessionImpl* SSLSessionImpl::finish() {
	if (this->useDefaultPeerSignAlgs) {
		$set(this, peerSupportedSignAlgs, $Collections::emptySet());
	}
	return this;
}

void SSLSessionImpl::setStatusResponses($List* responses) {
	if (responses != nullptr && !responses->isEmpty()) {
		$set(this, statusResponses, responses);
	} else {
		$set(this, statusResponses, $Collections::emptyList());
	}
}

bool SSLSessionImpl::isRejoinable() {
	if (this->protocolVersion->useTLS13PlusSpec()) {
		return (!this->invalidated && isLocalAuthenticationValid());
	}
	bool var$0 = this->sessionId != nullptr && $nc(this->sessionId)->length() != 0 && !this->invalidated;
	return var$0 && isLocalAuthenticationValid();
}

bool SSLSessionImpl::isValid() {
	$nc(this->sessionLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			var$2 = isRejoinable();
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->sessionLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

bool SSLSessionImpl::isLocalAuthenticationValid() {
	if (this->localPrivateKey != nullptr) {
		try {
			$nc(this->localPrivateKey)->getAlgorithm();
		} catch ($Exception& e) {
			invalidate();
			return false;
		}
	}
	return true;
}

$bytes* SSLSessionImpl::getId() {
	return $nc(this->sessionId)->getId();
}

$SSLSessionContext* SSLSessionImpl::getSessionContext() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, nullptr);
	if (($assign(sm, $System::getSecurityManager())) != nullptr) {
		$nc(sm)->checkPermission($$new($SSLPermission, "getSSLSessionContext"_s));
	}
	return this->context;
}

$SessionId* SSLSessionImpl::getSessionId() {
	return this->sessionId;
}

$CipherSuite* SSLSessionImpl::getSuite() {
	return this->cipherSuite;
}

void SSLSessionImpl::setSuite($CipherSuite* suite) {
	$useLocalCurrentObjectStackCache();
	$set(this, cipherSuite, suite);
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("session"_s)) {
		$SSLLogger::finest($$str({"Negotiating session:  "_s, this}), $$new($ObjectArray, 0));
	}
}

bool SSLSessionImpl::isSessionResumption() {
	return this->isSessionResumption$;
}

void SSLSessionImpl::setAsSessionResumption(bool flag) {
	this->isSessionResumption$ = flag;
}

$String* SSLSessionImpl::getCipherSuite() {
	return $nc($(getSuite()))->name$;
}

$ProtocolVersion* SSLSessionImpl::getProtocolVersion() {
	return this->protocolVersion;
}

$String* SSLSessionImpl::getProtocol() {
	return $nc($(getProtocolVersion()))->name$;
}

int32_t SSLSessionImpl::hashCode() {
	return $nc(this->sessionId)->hashCode();
}

bool SSLSessionImpl::equals(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	if ($equals(obj, this)) {
		return true;
	}
	if ($instanceOf(SSLSessionImpl, obj)) {
		$var(SSLSessionImpl, sess, $cast(SSLSessionImpl, obj));
		return (this->sessionId != nullptr) && ($nc(this->sessionId)->equals($($nc(sess)->getSessionId())));
	}
	return false;
}

$CertificateArray* SSLSessionImpl::getPeerCertificates() {
	if (this->peerCerts == nullptr) {
		$throwNew($SSLPeerUnverifiedException, "peer not authenticated"_s);
	}
	return $cast($CertificateArray, $nc(this->peerCerts)->clone());
}

$CertificateArray* SSLSessionImpl::getLocalCertificates() {
	return (this->localCerts == nullptr ? ($CertificateArray*)nullptr : $cast($CertificateArray, $nc(this->localCerts)->clone()));
}

$X509CertificateArray* SSLSessionImpl::getCertificateChain() {
	if (this->peerCerts != nullptr) {
		return $cast($X509CertificateArray, $nc(this->peerCerts)->clone());
	} else {
		$throwNew($SSLPeerUnverifiedException, "peer not authenticated"_s);
	}
}

$List* SSLSessionImpl::getStatusResponses() {
	$useLocalCurrentObjectStackCache();
	if (this->statusResponses == nullptr || $nc(this->statusResponses)->isEmpty()) {
		return $Collections::emptyList();
	} else {
		$var($List, responses, $new($ArrayList, $nc(this->statusResponses)->size()));
		{
			$var($Iterator, i$, $nc(this->statusResponses)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($bytes, respBytes, $cast($bytes, i$->next()));
				{
					responses->add($cast($bytes, $($nc(respBytes)->clone())));
				}
			}
		}
		return $Collections::unmodifiableList(responses);
	}
}

$Principal* SSLSessionImpl::getPeerPrincipal() {
	if (this->peerCerts == nullptr) {
		$throwNew($SSLPeerUnverifiedException, "peer not authenticated"_s);
	}
	return $nc($nc(this->peerCerts)->get(0))->getSubjectX500Principal();
}

$Principal* SSLSessionImpl::getLocalPrincipal() {
	return ((this->localCerts == nullptr || $nc(this->localCerts)->length == 0) ? ($Principal*)nullptr : static_cast<$Principal*>($nc($nc(this->localCerts)->get(0))->getSubjectX500Principal()));
}

int64_t SSLSessionImpl::getTicketCreationTime() {
	return this->ticketCreationTime;
}

int64_t SSLSessionImpl::getCreationTime() {
	return this->creationTime;
}

int64_t SSLSessionImpl::getLastAccessedTime() {
	return (this->lastUsedTime != 0) ? this->lastUsedTime : this->creationTime;
}

void SSLSessionImpl::setLastAccessedTime(int64_t time) {
	this->lastUsedTime = time;
}

$InetAddress* SSLSessionImpl::getPeerAddress() {
	try {
		return $InetAddress::getByName(this->host);
	} catch ($UnknownHostException& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$String* SSLSessionImpl::getPeerHost() {
	return this->host;
}

int32_t SSLSessionImpl::getPeerPort() {
	return this->port;
}

void SSLSessionImpl::setContext($SSLSessionContextImpl* ctx) {
	if (this->context == nullptr) {
		$set(this, context, ctx);
	}
}

void SSLSessionImpl::invalidate() {
	$useLocalCurrentObjectStackCache();
	$nc(this->sessionLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			if (this->context != nullptr) {
				$nc(this->context)->remove(this->sessionId);
				$set(this, context, nullptr);
			}
			if (this->invalidated) {
				return$1 = true;
				goto $finally;
			}
			this->invalidated = true;
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("session"_s)) {
				$SSLLogger::finest($$str({"Invalidated session:  "_s, this}), $$new($ObjectArray, 0));
			}
			{
				$var($Iterator, i$, $nc(this->childSessions)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var(SSLSessionImpl, child, $cast(SSLSessionImpl, i$->next()));
					{
						$nc(child)->invalidate();
					}
				}
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			$nc(this->sessionLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
}

void SSLSessionImpl::putValue($String* key, Object$* value) {
	$useLocalCurrentObjectStackCache();
	if ((key == nullptr) || (value == nullptr)) {
		$throwNew($IllegalArgumentException, "arguments can not be null"_s);
	}
	$var($SecureKey, secureKey, $new($SecureKey, key));
	$var($Object, oldValue, $nc(this->boundValues)->put(secureKey, value));
	if ($instanceOf($SSLSessionBindingListener, oldValue)) {
		$var($SSLSessionBindingEvent, e, nullptr);
		$assign(e, $new($SSLSessionBindingEvent, this, key));
		$nc(($cast($SSLSessionBindingListener, oldValue)))->valueUnbound(e);
	}
	if ($instanceOf($SSLSessionBindingListener, value)) {
		$var($SSLSessionBindingEvent, e, nullptr);
		$assign(e, $new($SSLSessionBindingEvent, this, key));
		$nc(($cast($SSLSessionBindingListener, value)))->valueBound(e);
	}
	if (this->protocolVersion->useTLS13PlusSpec()) {
		this->updateNST = true;
	}
}

$Object* SSLSessionImpl::getValue($String* key) {
	if (key == nullptr) {
		$throwNew($IllegalArgumentException, "argument can not be null"_s);
	}
	$var($SecureKey, secureKey, $new($SecureKey, key));
	return $of($nc(this->boundValues)->get(secureKey));
}

void SSLSessionImpl::removeValue($String* key) {
	$useLocalCurrentObjectStackCache();
	if (key == nullptr) {
		$throwNew($IllegalArgumentException, "argument can not be null"_s);
	}
	$var($SecureKey, secureKey, $new($SecureKey, key));
	$var($Object, value, $nc(this->boundValues)->remove(secureKey));
	if ($instanceOf($SSLSessionBindingListener, value)) {
		$var($SSLSessionBindingEvent, e, nullptr);
		$assign(e, $new($SSLSessionBindingEvent, this, key));
		$nc(($cast($SSLSessionBindingListener, value)))->valueUnbound(e);
	}
	if (this->protocolVersion->useTLS13PlusSpec()) {
		this->updateNST = true;
	}
}

$StringArray* SSLSessionImpl::getValueNames() {
	$useLocalCurrentObjectStackCache();
	$var($ArrayList, v, $new($ArrayList));
	$var($Object, securityCtx, $SecureKey::getCurrentSecurityContext());
	{
		$var($Enumeration, e, $nc(this->boundValues)->keys());
		for (; $nc(e)->hasMoreElements();) {
			$var($SecureKey, key, $cast($SecureKey, e->nextElement()));
			if ($nc($of(securityCtx))->equals($($nc(key)->getSecurityContext()))) {
				v->add($($nc(key)->getAppKey()));
			}
		}
	}
	return $fcast($StringArray, v->toArray($$new($StringArray, 0)));
}

void SSLSessionImpl::expandBufferSizes() {
	$nc(this->sessionLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			this->acceptLargeFragments = true;
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->sessionLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

int32_t SSLSessionImpl::getPacketBufferSize() {
	$nc(this->sessionLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			int32_t packetSize = 0;
			if (this->negotiatedMaxFragLen > 0) {
				packetSize = $nc(this->cipherSuite)->calculatePacketSize(this->negotiatedMaxFragLen, this->protocolVersion, this->protocolVersion->isDTLS);
			}
			if (this->maximumPacketSize > 0) {
				var$2 = (this->maximumPacketSize > packetSize) ? this->maximumPacketSize : packetSize;
				return$1 = true;
				goto $finally;
			}
			if (packetSize != 0) {
				var$2 = packetSize;
				return$1 = true;
				goto $finally;
			}
			if (this->protocolVersion->isDTLS) {
				var$2 = $DTLSRecord::maxRecordSize;
				return$1 = true;
				goto $finally;
			} else {
				var$2 = this->acceptLargeFragments ? $SSLRecord::maxLargeRecordSize : $SSLRecord::maxRecordSize;
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->sessionLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

int32_t SSLSessionImpl::getApplicationBufferSize() {
	$nc(this->sessionLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			int32_t fragmentSize = 0;
			if (this->maximumPacketSize > 0) {
				fragmentSize = $nc(this->cipherSuite)->calculateFragSize(this->maximumPacketSize, this->protocolVersion, this->protocolVersion->isDTLS);
			}
			if (this->negotiatedMaxFragLen > 0) {
				var$2 = (this->negotiatedMaxFragLen > fragmentSize) ? this->negotiatedMaxFragLen : fragmentSize;
				return$1 = true;
				goto $finally;
			}
			if (fragmentSize != 0) {
				var$2 = fragmentSize;
				return$1 = true;
				goto $finally;
			}
			if (this->protocolVersion->isDTLS) {
				var$2 = $Record::maxDataSize;
				return$1 = true;
				goto $finally;
			} else {
				int32_t maxPacketSize = this->acceptLargeFragments ? $SSLRecord::maxLargeRecordSize : $SSLRecord::maxRecordSize;
				var$2 = (maxPacketSize - $SSLRecord::headerSize);
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->sessionLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void SSLSessionImpl::setNegotiatedMaxFragSize(int32_t negotiatedMaxFragLen) {
	$nc(this->sessionLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			this->negotiatedMaxFragLen = negotiatedMaxFragLen;
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->sessionLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

int32_t SSLSessionImpl::getNegotiatedMaxFragSize() {
	$nc(this->sessionLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			var$2 = this->negotiatedMaxFragLen;
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->sessionLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void SSLSessionImpl::setMaximumPacketSize(int32_t maximumPacketSize) {
	$nc(this->sessionLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			this->maximumPacketSize = maximumPacketSize;
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->sessionLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

int32_t SSLSessionImpl::getMaximumPacketSize() {
	$nc(this->sessionLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			var$2 = this->maximumPacketSize;
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->sessionLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$StringArray* SSLSessionImpl::getLocalSupportedSignatureAlgorithms() {
	return $SignatureScheme::getAlgorithmNames(this->localSupportedSignAlgs);
}

$Collection* SSLSessionImpl::getLocalSupportedSignatureSchemes() {
	return this->localSupportedSignAlgs;
}

$StringArray* SSLSessionImpl::getPeerSupportedSignatureAlgorithms() {
	return $SignatureScheme::getAlgorithmNames(this->peerSupportedSignAlgs);
}

$List* SSLSessionImpl::getRequestedServerNames() {
	return this->requestedServerNames;
}

$String* SSLSessionImpl::toString() {
	$useLocalCurrentObjectStackCache();
	return $str({"Session("_s, $$str(this->creationTime), "|"_s, $(getCipherSuite()), ")"_s});
}

void clinit$SSLSessionImpl($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$init($SignatureScheme);
	$assignStatic(SSLSessionImpl::defaultPeerSupportedSignAlgs, $new($ArrayList, $(static_cast<$Collection*>($Arrays::asList($$new($SignatureSchemeArray, {
		$SignatureScheme::RSA_PKCS1_SHA1,
		$SignatureScheme::DSA_SHA1,
		$SignatureScheme::ECDSA_SHA1
	}))))));
}

SSLSessionImpl::SSLSessionImpl() {
}

$Class* SSLSessionImpl::load$($String* name, bool initialize) {
	$loadClass(SSLSessionImpl, name, initialize, &_SSLSessionImpl_ClassInfo_, clinit$SSLSessionImpl, allocate$SSLSessionImpl);
	return class$;
}

$Class* SSLSessionImpl::class$ = nullptr;

		} // ssl
	} // security
} // sun