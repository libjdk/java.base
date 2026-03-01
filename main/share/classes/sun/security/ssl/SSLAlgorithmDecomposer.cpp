#include <sun/security/ssl/SSLAlgorithmDecomposer.h>

#include <java/util/Collection.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <sun/security/ssl/CipherSuite$HashAlg.h>
#include <sun/security/ssl/CipherSuite$KeyExchange.h>
#include <sun/security/ssl/CipherSuite$MacAlg.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/CipherType.h>
#include <sun/security/ssl/SSLAlgorithmDecomposer$1.h>
#include <sun/security/ssl/SSLCipher.h>
#include <sun/security/util/AlgorithmDecomposer.h>
#include <jcpp.h>

#undef AEAD_CIPHER
#undef H_SHA256
#undef H_SHA384
#undef M_MD5
#undef M_NULL
#undef M_SHA
#undef M_SHA256
#undef M_SHA384
#undef TLS_EMPTY_RENEGOTIATION_INFO_SCSV

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Collection = ::java::util::Collection;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;
using $CipherSuite = ::sun::security::ssl::CipherSuite;
using $CipherSuite$HashAlg = ::sun::security::ssl::CipherSuite$HashAlg;
using $CipherSuite$KeyExchange = ::sun::security::ssl::CipherSuite$KeyExchange;
using $CipherSuite$MacAlg = ::sun::security::ssl::CipherSuite$MacAlg;
using $CipherType = ::sun::security::ssl::CipherType;
using $SSLAlgorithmDecomposer$1 = ::sun::security::ssl::SSLAlgorithmDecomposer$1;
using $SSLCipher = ::sun::security::ssl::SSLCipher;
using $AlgorithmDecomposer = ::sun::security::util::AlgorithmDecomposer;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLAlgorithmDecomposer_FieldInfo_[] = {
	{"onlyX509", "Z", nullptr, $PRIVATE | $FINAL, $field(SSLAlgorithmDecomposer, onlyX509)},
	{}
};

$MethodInfo _SSLAlgorithmDecomposer_MethodInfo_[] = {
	{"<init>", "(Z)V", nullptr, 0, $method(SSLAlgorithmDecomposer, init$, void, bool)},
	{"<init>", "()V", nullptr, 0, $method(SSLAlgorithmDecomposer, init$, void)},
	{"decompose", "(Lsun/security/ssl/CipherSuite$KeyExchange;Lsun/security/ssl/SSLCipher;Lsun/security/ssl/CipherSuite$MacAlg;Lsun/security/ssl/CipherSuite$HashAlg;)Ljava/util/Set;", "(Lsun/security/ssl/CipherSuite$KeyExchange;Lsun/security/ssl/SSLCipher;Lsun/security/ssl/CipherSuite$MacAlg;Lsun/security/ssl/CipherSuite$HashAlg;)Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE, $method(SSLAlgorithmDecomposer, decompose, $Set*, $CipherSuite$KeyExchange*, $SSLCipher*, $CipherSuite$MacAlg*, $CipherSuite$HashAlg*)},
	{"decompose", "(Ljava/lang/String;)Ljava/util/Set;", "(Ljava/lang/String;)Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(SSLAlgorithmDecomposer, decompose, $Set*, $String*)},
	{"decomposes", "(Lsun/security/ssl/CipherSuite$KeyExchange;)Ljava/util/Set;", "(Lsun/security/ssl/CipherSuite$KeyExchange;)Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE, $method(SSLAlgorithmDecomposer, decomposes, $Set*, $CipherSuite$KeyExchange*)},
	{"decomposes", "(Lsun/security/ssl/SSLCipher;)Ljava/util/Set;", "(Lsun/security/ssl/SSLCipher;)Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE, $method(SSLAlgorithmDecomposer, decomposes, $Set*, $SSLCipher*)},
	{"decomposes", "(Lsun/security/ssl/CipherSuite$MacAlg;Lsun/security/ssl/SSLCipher;)Ljava/util/Set;", "(Lsun/security/ssl/CipherSuite$MacAlg;Lsun/security/ssl/SSLCipher;)Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE, $method(SSLAlgorithmDecomposer, decomposes, $Set*, $CipherSuite$MacAlg*, $SSLCipher*)},
	{"decomposes", "(Lsun/security/ssl/CipherSuite$HashAlg;)Ljava/util/Set;", "(Lsun/security/ssl/CipherSuite$HashAlg;)Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE, $method(SSLAlgorithmDecomposer, decomposes, $Set*, $CipherSuite$HashAlg*)},
	{}
};

$InnerClassInfo _SSLAlgorithmDecomposer_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLAlgorithmDecomposer$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _SSLAlgorithmDecomposer_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.ssl.SSLAlgorithmDecomposer",
	"sun.security.util.AlgorithmDecomposer",
	nullptr,
	_SSLAlgorithmDecomposer_FieldInfo_,
	_SSLAlgorithmDecomposer_MethodInfo_,
	nullptr,
	nullptr,
	_SSLAlgorithmDecomposer_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLAlgorithmDecomposer$1"
};

$Object* allocate$SSLAlgorithmDecomposer($Class* clazz) {
	return $of($alloc(SSLAlgorithmDecomposer));
}

void SSLAlgorithmDecomposer::init$(bool onlyX509) {
	$AlgorithmDecomposer::init$();
	this->onlyX509 = onlyX509;
}

void SSLAlgorithmDecomposer::init$() {
	SSLAlgorithmDecomposer::init$(false);
}

$Set* SSLAlgorithmDecomposer::decomposes($CipherSuite$KeyExchange* keyExchange) {
	$var($Set, components, $new($HashSet));
	$init($SSLAlgorithmDecomposer$1);
	switch ($nc($SSLAlgorithmDecomposer$1::$SwitchMap$sun$security$ssl$CipherSuite$KeyExchange)->get($nc((keyExchange))->ordinal())) {
	case 1:
		{
			if (!this->onlyX509) {
				components->add("K_NULL"_s);
			}
			break;
		}
	case 2:
		{
			components->add("RSA"_s);
			break;
		}
	case 3:
		{
			components->add("RSA"_s);
			components->add("RSA_EXPORT"_s);
			break;
		}
	case 4:
		{
			components->add("RSA"_s);
			components->add("DH"_s);
			components->add("DiffieHellman"_s);
			components->add("DH_RSA"_s);
			break;
		}
	case 5:
		{
			components->add("DSA"_s);
			components->add("DSS"_s);
			components->add("DH"_s);
			components->add("DiffieHellman"_s);
			components->add("DH_DSS"_s);
			break;
		}
	case 6:
		{
			components->add("DSA"_s);
			components->add("DSS"_s);
			components->add("DH"_s);
			components->add("DHE"_s);
			components->add("DiffieHellman"_s);
			components->add("DHE_DSS"_s);
			break;
		}
	case 7:
		{
			components->add("RSA"_s);
			components->add("DH"_s);
			components->add("DHE"_s);
			components->add("DiffieHellman"_s);
			components->add("DHE_RSA"_s);
			break;
		}
	case 8:
		{
			if (!this->onlyX509) {
				components->add("ANON"_s);
				components->add("DH"_s);
				components->add("DiffieHellman"_s);
				components->add("DH_ANON"_s);
			}
			break;
		}
	case 9:
		{
			components->add("ECDH"_s);
			components->add("ECDSA"_s);
			components->add("ECDH_ECDSA"_s);
			break;
		}
	case 10:
		{
			components->add("ECDH"_s);
			components->add("RSA"_s);
			components->add("ECDH_RSA"_s);
			break;
		}
	case 11:
		{
			components->add("ECDHE"_s);
			components->add("ECDSA"_s);
			components->add("ECDHE_ECDSA"_s);
			break;
		}
	case 12:
		{
			components->add("ECDHE"_s);
			components->add("RSA"_s);
			components->add("ECDHE_RSA"_s);
			break;
		}
	case 13:
		{
			if (!this->onlyX509) {
				components->add("ECDH"_s);
				components->add("ANON"_s);
				components->add("ECDH_ANON"_s);
			}
			break;
		}
	default:
		{}
	}
	return components;
}

$Set* SSLAlgorithmDecomposer::decomposes($SSLCipher* bulkCipher) {
	$useLocalCurrentObjectStackCache();
	$var($Set, components, $new($HashSet));
	if ($nc(bulkCipher)->transformation != nullptr) {
		components->addAll($($AlgorithmDecomposer::decompose(bulkCipher->transformation)));
	}
	$init($SSLAlgorithmDecomposer$1);
	switch ($nc($SSLAlgorithmDecomposer$1::$SwitchMap$sun$security$ssl$SSLCipher)->get($nc((bulkCipher))->ordinal())) {
	case 1:
		{
			components->add("C_NULL"_s);
			break;
		}
	case 2:
		{
			components->add("RC2_CBC_40"_s);
			break;
		}
	case 3:
		{
			components->add("RC4_40"_s);
			break;
		}
	case 4:
		{
			components->add("RC4_128"_s);
			break;
		}
	case 5:
		{
			components->add("DES40_CBC"_s);
			components->add("DES_CBC_40"_s);
			break;
		}
	case 6:
		{
			components->add("DES_CBC"_s);
			break;
		}
	case 7:
		{
			components->add("3DES_EDE_CBC"_s);
			break;
		}
	case 8:
		{
			components->add("AES_128_CBC"_s);
			break;
		}
	case 9:
		{
			components->add("AES_256_CBC"_s);
			break;
		}
	case 10:
		{
			components->add("AES_128_GCM"_s);
			break;
		}
	case 11:
		{
			components->add("AES_256_GCM"_s);
			break;
		}
	}
	return components;
}

$Set* SSLAlgorithmDecomposer::decomposes($CipherSuite$MacAlg* macAlg, $SSLCipher* cipher) {
	$var($Set, components, $new($HashSet));
	$init($CipherSuite$MacAlg);
	$init($CipherType);
	if (macAlg == $CipherSuite$MacAlg::M_NULL && $nc(cipher)->cipherType != $CipherType::AEAD_CIPHER) {
		components->add("M_NULL"_s);
	} else {
		if (macAlg == $CipherSuite$MacAlg::M_MD5) {
			components->add("MD5"_s);
			components->add("HmacMD5"_s);
		} else {
			if (macAlg == $CipherSuite$MacAlg::M_SHA) {
				components->add("SHA1"_s);
				components->add("SHA-1"_s);
				components->add("HmacSHA1"_s);
			} else {
				if (macAlg == $CipherSuite$MacAlg::M_SHA256) {
					components->add("SHA256"_s);
					components->add("SHA-256"_s);
					components->add("HmacSHA256"_s);
				} else {
					if (macAlg == $CipherSuite$MacAlg::M_SHA384) {
						components->add("SHA384"_s);
						components->add("SHA-384"_s);
						components->add("HmacSHA384"_s);
					}
				}
			}
		}
	}
	return components;
}

$Set* SSLAlgorithmDecomposer::decomposes($CipherSuite$HashAlg* hashAlg) {
	$var($Set, components, $new($HashSet));
	$init($CipherSuite$HashAlg);
	if (hashAlg == $CipherSuite$HashAlg::H_SHA256) {
		components->add("SHA256"_s);
		components->add("SHA-256"_s);
		components->add("HmacSHA256"_s);
	} else {
		if (hashAlg == $CipherSuite$HashAlg::H_SHA384) {
			components->add("SHA384"_s);
			components->add("SHA-384"_s);
			components->add("HmacSHA384"_s);
		}
	}
	return components;
}

$Set* SSLAlgorithmDecomposer::decompose($CipherSuite$KeyExchange* keyExchange, $SSLCipher* cipher, $CipherSuite$MacAlg* macAlg, $CipherSuite$HashAlg* hashAlg) {
	$useLocalCurrentObjectStackCache();
	$var($Set, components, $new($HashSet));
	if (keyExchange != nullptr) {
		components->addAll($(decomposes(keyExchange)));
	}
	if (this->onlyX509) {
		return components;
	}
	if (cipher != nullptr) {
		components->addAll($(decomposes(cipher)));
	}
	if (macAlg != nullptr) {
		components->addAll($(decomposes(macAlg, cipher)));
	}
	if (hashAlg != nullptr) {
		components->addAll($(decomposes(hashAlg)));
	}
	return components;
}

$Set* SSLAlgorithmDecomposer::decompose($String* algorithm) {
	bool var$0 = $nc(algorithm)->startsWith("SSL_"_s);
	if (var$0 || $nc(algorithm)->startsWith("TLS_"_s)) {
		$CipherSuite* cipherSuite = nullptr;
		try {
			cipherSuite = $CipherSuite::nameOf(algorithm);
		} catch ($IllegalArgumentException& iae) {
		}
		$init($CipherSuite);
		if (cipherSuite != nullptr && cipherSuite != $CipherSuite::TLS_EMPTY_RENEGOTIATION_INFO_SCSV) {
			return decompose(cipherSuite->keyExchange, cipherSuite->bulkCipher, cipherSuite->macAlg, cipherSuite->hashAlg);
		}
	}
	return $AlgorithmDecomposer::decompose(algorithm);
}

SSLAlgorithmDecomposer::SSLAlgorithmDecomposer() {
}

$Class* SSLAlgorithmDecomposer::load$($String* name, bool initialize) {
	$loadClass(SSLAlgorithmDecomposer, name, initialize, &_SSLAlgorithmDecomposer_ClassInfo_, allocate$SSLAlgorithmDecomposer);
	return class$;
}

$Class* SSLAlgorithmDecomposer::class$ = nullptr;

		} // ssl
	} // security
} // sun