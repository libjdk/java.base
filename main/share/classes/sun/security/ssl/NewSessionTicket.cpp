#include <sun/security/ssl/NewSessionTicket.h>

#include <java/security/GeneralSecurityException.h>
#include <javax/crypto/SecretKey.h>
#include <javax/net/ssl/SSLHandshakeException.h>
#include <sun/security/ssl/CipherSuite$HashAlg.h>
#include <sun/security/ssl/HKDF.h>
#include <sun/security/ssl/HandshakeProducer.h>
#include <sun/security/ssl/NewSessionTicket$T12NewSessionTicketConsumer.h>
#include <sun/security/ssl/NewSessionTicket$T12NewSessionTicketProducer.h>
#include <sun/security/ssl/NewSessionTicket$T13NewSessionTicketConsumer.h>
#include <sun/security/ssl/NewSessionTicket$T13NewSessionTicketProducer.h>
#include <sun/security/ssl/SSLConsumer.h>
#include <sun/security/ssl/SSLProducer.h>
#include <sun/security/ssl/SSLSecretDerivation.h>
#include <jcpp.h>

#undef MAX_TICKET_LIFETIME

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $SecretKey = ::javax::crypto::SecretKey;
using $SSLHandshakeException = ::javax::net::ssl::SSLHandshakeException;
using $CipherSuite$HashAlg = ::sun::security::ssl::CipherSuite$HashAlg;
using $HKDF = ::sun::security::ssl::HKDF;
using $HandshakeProducer = ::sun::security::ssl::HandshakeProducer;
using $NewSessionTicket$T12NewSessionTicketConsumer = ::sun::security::ssl::NewSessionTicket$T12NewSessionTicketConsumer;
using $NewSessionTicket$T12NewSessionTicketProducer = ::sun::security::ssl::NewSessionTicket$T12NewSessionTicketProducer;
using $NewSessionTicket$T13NewSessionTicketConsumer = ::sun::security::ssl::NewSessionTicket$T13NewSessionTicketConsumer;
using $NewSessionTicket$T13NewSessionTicketProducer = ::sun::security::ssl::NewSessionTicket$T13NewSessionTicketProducer;
using $SSLConsumer = ::sun::security::ssl::SSLConsumer;
using $SSLProducer = ::sun::security::ssl::SSLProducer;
using $SSLSecretDerivation = ::sun::security::ssl::SSLSecretDerivation;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _NewSessionTicket_FieldInfo_[] = {
	{"MAX_TICKET_LIFETIME", "I", nullptr, $STATIC | $FINAL, $constField(NewSessionTicket, MAX_TICKET_LIFETIME)},
	{"handshakeConsumer", "Lsun/security/ssl/SSLConsumer;", nullptr, $STATIC | $FINAL, $staticField(NewSessionTicket, handshakeConsumer)},
	{"handshake12Consumer", "Lsun/security/ssl/SSLConsumer;", nullptr, $STATIC | $FINAL, $staticField(NewSessionTicket, handshake12Consumer)},
	{"t13PosthandshakeProducer", "Lsun/security/ssl/SSLProducer;", nullptr, $STATIC | $FINAL, $staticField(NewSessionTicket, t13PosthandshakeProducer)},
	{"handshake12Producer", "Lsun/security/ssl/HandshakeProducer;", nullptr, $STATIC | $FINAL, $staticField(NewSessionTicket, handshake12Producer)},
	{}
};

$MethodInfo _NewSessionTicket_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(NewSessionTicket, init$, void)},
	{"derivePreSharedKey", "(Lsun/security/ssl/CipherSuite$HashAlg;Ljavax/crypto/SecretKey;[B)Ljavax/crypto/SecretKey;", nullptr, $PRIVATE | $STATIC, $staticMethod(NewSessionTicket, derivePreSharedKey, $SecretKey*, $CipherSuite$HashAlg*, $SecretKey*, $bytes*), "java.io.IOException"},
	{}
};

$InnerClassInfo _NewSessionTicket_InnerClassesInfo_[] = {
	{"sun.security.ssl.NewSessionTicket$T12NewSessionTicketConsumer", "sun.security.ssl.NewSessionTicket", "T12NewSessionTicketConsumer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.NewSessionTicket$T13NewSessionTicketConsumer", "sun.security.ssl.NewSessionTicket", "T13NewSessionTicketConsumer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.NewSessionTicket$T12NewSessionTicketProducer", "sun.security.ssl.NewSessionTicket", "T12NewSessionTicketProducer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.NewSessionTicket$T13NewSessionTicketProducer", "sun.security.ssl.NewSessionTicket", "T13NewSessionTicketProducer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.NewSessionTicket$T13NewSessionTicketMessage", "sun.security.ssl.NewSessionTicket", "T13NewSessionTicketMessage", $STATIC | $FINAL},
	{"sun.security.ssl.NewSessionTicket$T12NewSessionTicketMessage", "sun.security.ssl.NewSessionTicket", "T12NewSessionTicketMessage", $STATIC | $FINAL},
	{"sun.security.ssl.NewSessionTicket$NewSessionTicketMessage", "sun.security.ssl.NewSessionTicket", "NewSessionTicketMessage", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _NewSessionTicket_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.NewSessionTicket",
	"java.lang.Object",
	nullptr,
	_NewSessionTicket_FieldInfo_,
	_NewSessionTicket_MethodInfo_,
	nullptr,
	nullptr,
	_NewSessionTicket_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.ssl.NewSessionTicket$T12NewSessionTicketConsumer,sun.security.ssl.NewSessionTicket$T13NewSessionTicketConsumer,sun.security.ssl.NewSessionTicket$T12NewSessionTicketProducer,sun.security.ssl.NewSessionTicket$T13NewSessionTicketProducer,sun.security.ssl.NewSessionTicket$T13NewSessionTicketMessage,sun.security.ssl.NewSessionTicket$T12NewSessionTicketMessage,sun.security.ssl.NewSessionTicket$NewSessionTicketMessage"
};

$Object* allocate$NewSessionTicket($Class* clazz) {
	return $of($alloc(NewSessionTicket));
}

$SSLConsumer* NewSessionTicket::handshakeConsumer = nullptr;
$SSLConsumer* NewSessionTicket::handshake12Consumer = nullptr;
$SSLProducer* NewSessionTicket::t13PosthandshakeProducer = nullptr;
$HandshakeProducer* NewSessionTicket::handshake12Producer = nullptr;

void NewSessionTicket::init$() {
}

$SecretKey* NewSessionTicket::derivePreSharedKey($CipherSuite$HashAlg* hashAlg, $SecretKey* resumptionMasterSecret, $bytes* nonce) {
	$init(NewSessionTicket);
	$useLocalCurrentObjectStackCache();
	try {
		$var($HKDF, hkdf, $new($HKDF, $nc(hashAlg)->name$));
		$var($bytes, hkdfInfo, $SSLSecretDerivation::createHkdfInfo($("tls13 resumption"_s->getBytes()), nonce, $nc(hashAlg)->hashLength));
		return hkdf->expand(resumptionMasterSecret, hkdfInfo, $nc(hashAlg)->hashLength, "TlsPreSharedKey"_s);
	} catch ($GeneralSecurityException& gse) {
		$throw($cast($SSLHandshakeException, $($$new($SSLHandshakeException, "Could not derive PSK"_s)->initCause(gse))));
	}
	$shouldNotReachHere();
}

void clinit$NewSessionTicket($Class* class$) {
	$assignStatic(NewSessionTicket::handshakeConsumer, $new($NewSessionTicket$T13NewSessionTicketConsumer));
	$assignStatic(NewSessionTicket::handshake12Consumer, $new($NewSessionTicket$T12NewSessionTicketConsumer));
	$assignStatic(NewSessionTicket::t13PosthandshakeProducer, $new($NewSessionTicket$T13NewSessionTicketProducer));
	$assignStatic(NewSessionTicket::handshake12Producer, $new($NewSessionTicket$T12NewSessionTicketProducer));
}

NewSessionTicket::NewSessionTicket() {
}

$Class* NewSessionTicket::load$($String* name, bool initialize) {
	$loadClass(NewSessionTicket, name, initialize, &_NewSessionTicket_ClassInfo_, clinit$NewSessionTicket, allocate$NewSessionTicket);
	return class$;
}

$Class* NewSessionTicket::class$ = nullptr;

		} // ssl
	} // security
} // sun