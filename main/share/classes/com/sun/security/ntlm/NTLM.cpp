#include <com/sun/security/ntlm/NTLM.h>

#include <com/sun/security/ntlm/NTLMException.h>
#include <com/sun/security/ntlm/Version.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/lang/AssertionError.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/spec/InvalidKeySpecException.h>
#include <java/security/spec/KeySpec.h>
#include <java/util/Arrays.h>
#include <java/util/Locale.h>
#include <javax/crypto/BadPaddingException.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/IllegalBlockSizeException.h>
#include <javax/crypto/Mac.h>
#include <javax/crypto/NoSuchPaddingException.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/SecretKeyFactory.h>
#include <javax/crypto/spec/DESKeySpec.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <sun/security/action/GetBooleanAction.h>
#include <sun/security/provider/MD4.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <jcpp.h>

#undef BAD_VERSION
#undef DEBUG
#undef ENCRYPT_MODE
#undef ENGLISH
#undef NTLM
#undef NTLM2
#undef UTF_16LE

using $NTLMException = ::com::sun::security::ntlm::NTLMException;
using $Version = ::com::sun::security::ntlm::Version;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $InvalidKeySpecException = ::java::security::spec::InvalidKeySpecException;
using $KeySpec = ::java::security::spec::KeySpec;
using $Arrays = ::java::util::Arrays;
using $Locale = ::java::util::Locale;
using $BadPaddingException = ::javax::crypto::BadPaddingException;
using $Cipher = ::javax::crypto::Cipher;
using $IllegalBlockSizeException = ::javax::crypto::IllegalBlockSizeException;
using $Mac = ::javax::crypto::Mac;
using $NoSuchPaddingException = ::javax::crypto::NoSuchPaddingException;
using $SecretKey = ::javax::crypto::SecretKey;
using $SecretKeyFactory = ::javax::crypto::SecretKeyFactory;
using $DESKeySpec = ::javax::crypto::spec::DESKeySpec;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;
using $GetBooleanAction = ::sun::security::action::GetBooleanAction;
using $MD4 = ::sun::security::provider::MD4;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;

namespace com {
	namespace sun {
		namespace security {
			namespace ntlm {

$FieldInfo _NTLM_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(NTLM, $assertionsDisabled)},
	{"fac", "Ljavax/crypto/SecretKeyFactory;", nullptr, $PRIVATE | $FINAL, $field(NTLM, fac)},
	{"cipher", "Ljavax/crypto/Cipher;", nullptr, $PRIVATE | $FINAL, $field(NTLM, cipher)},
	{"md4", "Ljava/security/MessageDigest;", nullptr, $PRIVATE | $FINAL, $field(NTLM, md4)},
	{"hmac", "Ljavax/crypto/Mac;", nullptr, $PRIVATE | $FINAL, $field(NTLM, hmac)},
	{"md5", "Ljava/security/MessageDigest;", nullptr, $PRIVATE | $FINAL, $field(NTLM, md5)},
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(NTLM, DEBUG)},
	{"v", "Lcom/sun/security/ntlm/Version;", nullptr, $FINAL, $field(NTLM, v)},
	{"writeLM", "Z", nullptr, $FINAL, $field(NTLM, writeLM)},
	{"writeNTLM", "Z", nullptr, $FINAL, $field(NTLM, writeNTLM)},
	{}
};

$MethodInfo _NTLM_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $method(NTLM, init$, void, $String*), "com.sun.security.ntlm.NTLMException"},
	{"calcLMHash", "([B)[B", nullptr, 0, $virtualMethod(NTLM, calcLMHash, $bytes*, $bytes*)},
	{"calcNTHash", "([B)[B", nullptr, 0, $virtualMethod(NTLM, calcNTHash, $bytes*, $bytes*)},
	{"calcResponse", "([B[B)[B", nullptr, 0, $virtualMethod(NTLM, calcResponse, $bytes*, $bytes*, $bytes*)},
	{"calcV2", "([BLjava/lang/String;[B[B)[B", nullptr, 0, $virtualMethod(NTLM, calcV2, $bytes*, $bytes*, $String*, $bytes*, $bytes*)},
	{"debug", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(NTLM, debug, void, $String*, $ObjectArray*)},
	{"debug", "([B)V", nullptr, $PUBLIC, $virtualMethod(NTLM, debug, void, $bytes*)},
	{"getP1", "([C)[B", nullptr, $STATIC, $staticMethod(NTLM, getP1, $bytes*, $chars*)},
	{"getP2", "([C)[B", nullptr, $STATIC, $staticMethod(NTLM, getP2, $bytes*, $chars*)},
	{"hmacMD5", "([B[B)[B", nullptr, 0, $virtualMethod(NTLM, hmacMD5, $bytes*, $bytes*, $bytes*)},
	{"makeDesKey", "([BI)[B", nullptr, 0, $virtualMethod(NTLM, makeDesKey, $bytes*, $bytes*, int32_t)},
	{"ntlm2LM", "([B)[B", nullptr, $STATIC, $staticMethod(NTLM, ntlm2LM, $bytes*, $bytes*)},
	{"ntlm2NTLM", "([B[B[B)[B", nullptr, 0, $virtualMethod(NTLM, ntlm2NTLM, $bytes*, $bytes*, $bytes*, $bytes*)},
	{}
};

$InnerClassInfo _NTLM_InnerClassesInfo_[] = {
	{"com.sun.security.ntlm.NTLM$Writer", "com.sun.security.ntlm.NTLM", "Writer", $STATIC},
	{"com.sun.security.ntlm.NTLM$Reader", "com.sun.security.ntlm.NTLM", "Reader", $STATIC},
	{}
};

$ClassInfo _NTLM_ClassInfo_ = {
	$ACC_SUPER,
	"com.sun.security.ntlm.NTLM",
	"java.lang.Object",
	nullptr,
	_NTLM_FieldInfo_,
	_NTLM_MethodInfo_,
	nullptr,
	nullptr,
	_NTLM_InnerClassesInfo_,
	nullptr,
	nullptr,
	"com.sun.security.ntlm.NTLM$Writer,com.sun.security.ntlm.NTLM$Reader"
};

$Object* allocate$NTLM($Class* clazz) {
	return $of($alloc(NTLM));
}

bool NTLM::$assertionsDisabled = false;
bool NTLM::DEBUG = false;

void NTLM::init$($String* version$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, version, version$renamed);
	if (version == nullptr) {
		$assign(version, "LMv2/NTLMv2"_s);
	}
	{
		$var($String, s2555$, version);
		int32_t tmp2555$ = -1;
		switch ($nc(s2555$)->hashCode()) {
		case 2433:
			{
				if (s2555$->equals("LM"_s)) {
					tmp2555$ = 0;
				}
				break;
			}
		case 0x0024B9C7:
			{
				if (s2555$->equals("NTLM"_s)) {
					tmp2555$ = 1;
				}
				break;
			}
		case 0x3A79C995:
			{
				if (s2555$->equals("LM/NTLM"_s)) {
					tmp2555$ = 2;
				}
				break;
			}
		case 0x04727F4B:
			{
				if (s2555$->equals("NTLM2"_s)) {
					tmp2555$ = 3;
				}
				break;
			}
		case 0x0023BBBD:
			{
				if (s2555$->equals("LMv2"_s)) {
					tmp2555$ = 4;
				}
				break;
			}
		case (int32_t)0x89DD7283:
			{
				if (s2555$->equals("NTLMv2"_s)) {
					tmp2555$ = 5;
				}
				break;
			}
		case (int32_t)0x8FA45915:
			{
				if (s2555$->equals("LMv2/NTLMv2"_s)) {
					tmp2555$ = 6;
				}
				break;
			}
		}
		switch (tmp2555$) {
		case 0:
			{
				$init($Version);
				$set(this, v, $Version::NTLM);
				this->writeLM = true;
				this->writeNTLM = false;
				break;
			}
		case 1:
			{
				$init($Version);
				$set(this, v, $Version::NTLM);
				this->writeLM = false;
				this->writeNTLM = true;
				break;
			}
		case 2:
			{
				$init($Version);
				$set(this, v, $Version::NTLM);
				this->writeLM = (this->writeNTLM = true);
				break;
			}
		case 3:
			{
				$init($Version);
				$set(this, v, $Version::NTLM2);
				this->writeLM = (this->writeNTLM = true);
				break;
			}
		case 4:
			{
				$init($Version);
				$set(this, v, $Version::NTLMv2);
				this->writeLM = true;
				this->writeNTLM = false;
				break;
			}
		case 5:
			{
				$init($Version);
				$set(this, v, $Version::NTLMv2);
				this->writeLM = false;
				this->writeNTLM = true;
				break;
			}
		case 6:
			{
				$init($Version);
				$set(this, v, $Version::NTLMv2);
				this->writeLM = (this->writeNTLM = true);
				break;
			}
		default:
			{
				$throwNew($NTLMException, $NTLMException::BAD_VERSION, $$str({"Unknown version "_s, version}));
			}
		}
	}
	try {
		$set(this, fac, $SecretKeyFactory::getInstance("DES"_s));
		$set(this, cipher, $Cipher::getInstance("DES/ECB/NoPadding"_s));
		$set(this, md4, $MD4::getInstance());
		$set(this, hmac, $Mac::getInstance("HmacMD5"_s));
		$set(this, md5, $MessageDigest::getInstance("MD5"_s));
	} catch ($NoSuchPaddingException& e) {
		$throwNew($AssertionError);
	} catch ($NoSuchAlgorithmException& e) {
		$throwNew($AssertionError);
	}
}

void NTLM::debug($String* format, $ObjectArray* args) {
	if (NTLM::DEBUG) {
		$nc($System::out)->printf(format, args);
	}
}

void NTLM::debug($bytes* bytes) {
	if (NTLM::DEBUG) {
		try {
			$$new($HexDumpEncoder)->encodeBuffer(bytes, static_cast<$OutputStream*>($System::out));
		} catch ($IOException& ioe) {
		}
	}
}

$bytes* NTLM::makeDesKey($bytes* input, int32_t off) {
	$useLocalCurrentObjectStackCache();
	$var($ints, in, $new($ints, $nc(input)->length));
	for (int32_t i = 0; i < in->length; ++i) {
		in->set(i, input->get(i) < 0 ? input->get(i) + 256 : (int32_t)input->get(i));
	}
	$var($bytes, out, $new($bytes, 8));
	out->set(0, (int8_t)in->get(off + 0));
	out->set(1, (int8_t)(((int32_t)((in->get(off + 0) << 7) & (uint32_t)255)) | (in->get(off + 1) >> 1)));
	out->set(2, (int8_t)(((int32_t)((in->get(off + 1) << 6) & (uint32_t)255)) | (in->get(off + 2) >> 2)));
	out->set(3, (int8_t)(((int32_t)((in->get(off + 2) << 5) & (uint32_t)255)) | (in->get(off + 3) >> 3)));
	out->set(4, (int8_t)(((int32_t)((in->get(off + 3) << 4) & (uint32_t)255)) | (in->get(off + 4) >> 4)));
	out->set(5, (int8_t)(((int32_t)((in->get(off + 4) << 3) & (uint32_t)255)) | (in->get(off + 5) >> 5)));
	out->set(6, (int8_t)(((int32_t)((in->get(off + 5) << 2) & (uint32_t)255)) | (in->get(off + 6) >> 6)));
	out->set(7, (int8_t)((int32_t)((in->get(off + 6) << 1) & (uint32_t)255)));
	return out;
}

$bytes* NTLM::calcLMHash($bytes* pwb) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, magic, $new($bytes, {
		(int8_t)75,
		(int8_t)71,
		(int8_t)83,
		(int8_t)33,
		(int8_t)64,
		(int8_t)35,
		(int8_t)36,
		(int8_t)37
	}));
	$var($bytes, pwb1, $new($bytes, 14));
	int32_t len = $nc(pwb)->length;
	if (len > 14) {
		len = 14;
	}
	$System::arraycopy(pwb, 0, pwb1, 0, len);
	try {
		$var($DESKeySpec, dks1, $new($DESKeySpec, $(makeDesKey(pwb1, 0))));
		$var($DESKeySpec, dks2, $new($DESKeySpec, $(makeDesKey(pwb1, 7))));
		$var($SecretKey, key1, $nc(this->fac)->generateSecret(dks1));
		$var($SecretKey, key2, $nc(this->fac)->generateSecret(dks2));
		$nc(this->cipher)->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>(key1));
		$var($bytes, out1, $nc(this->cipher)->doFinal(magic, 0, 8));
		$nc(this->cipher)->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>(key2));
		$var($bytes, out2, $nc(this->cipher)->doFinal(magic, 0, 8));
		$var($bytes, result, $new($bytes, 21));
		$System::arraycopy(out1, 0, result, 0, 8);
		$System::arraycopy(out2, 0, result, 8, 8);
		return result;
	} catch ($InvalidKeyException& ive) {
		if (!NTLM::$assertionsDisabled) {
			$throwNew($AssertionError);
		}
	} catch ($InvalidKeySpecException& ikse) {
		if (!NTLM::$assertionsDisabled) {
			$throwNew($AssertionError);
		}
	} catch ($IllegalBlockSizeException& ibse) {
		if (!NTLM::$assertionsDisabled) {
			$throwNew($AssertionError);
		}
	} catch ($BadPaddingException& bpe) {
		if (!NTLM::$assertionsDisabled) {
			$throwNew($AssertionError);
		}
	}
	return nullptr;
}

$bytes* NTLM::calcNTHash($bytes* pw) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, out, $nc(this->md4)->digest(pw));
	$var($bytes, result, $new($bytes, 21));
	$System::arraycopy(out, 0, result, 0, 16);
	return result;
}

$bytes* NTLM::calcResponse($bytes* key, $bytes* text) {
	$useLocalCurrentObjectStackCache();
	try {
		if (!NTLM::$assertionsDisabled && !($nc(key)->length == 21)) {
			$throwNew($AssertionError);
		}
		$var($DESKeySpec, dks1, $new($DESKeySpec, $(makeDesKey(key, 0))));
		$var($DESKeySpec, dks2, $new($DESKeySpec, $(makeDesKey(key, 7))));
		$var($DESKeySpec, dks3, $new($DESKeySpec, $(makeDesKey(key, 14))));
		$var($SecretKey, key1, $nc(this->fac)->generateSecret(dks1));
		$var($SecretKey, key2, $nc(this->fac)->generateSecret(dks2));
		$var($SecretKey, key3, $nc(this->fac)->generateSecret(dks3));
		$nc(this->cipher)->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>(key1));
		$var($bytes, out1, $nc(this->cipher)->doFinal(text, 0, 8));
		$nc(this->cipher)->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>(key2));
		$var($bytes, out2, $nc(this->cipher)->doFinal(text, 0, 8));
		$nc(this->cipher)->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>(key3));
		$var($bytes, out3, $nc(this->cipher)->doFinal(text, 0, 8));
		$var($bytes, result, $new($bytes, 24));
		$System::arraycopy(out1, 0, result, 0, 8);
		$System::arraycopy(out2, 0, result, 8, 8);
		$System::arraycopy(out3, 0, result, 16, 8);
		return result;
	} catch ($IllegalBlockSizeException& ex) {
		if (!NTLM::$assertionsDisabled) {
			$throwNew($AssertionError);
		}
	} catch ($BadPaddingException& ex) {
		if (!NTLM::$assertionsDisabled) {
			$throwNew($AssertionError);
		}
	} catch ($InvalidKeySpecException& ex) {
		if (!NTLM::$assertionsDisabled) {
			$throwNew($AssertionError);
		}
	} catch ($InvalidKeyException& ex) {
		if (!NTLM::$assertionsDisabled) {
			$throwNew($AssertionError);
		}
	}
	return nullptr;
}

$bytes* NTLM::hmacMD5($bytes* key, $bytes* text) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($SecretKeySpec, skey, $new($SecretKeySpec, $($Arrays::copyOf(key, 16)), "HmacMD5"_s));
		$nc(this->hmac)->init(skey);
		return $nc(this->hmac)->doFinal(text);
	} catch ($InvalidKeyException& ex) {
		if (!NTLM::$assertionsDisabled) {
			$throwNew($AssertionError);
		}
	} catch ($RuntimeException& e) {
		if (!NTLM::$assertionsDisabled) {
			$throwNew($AssertionError);
		}
	}
	return nullptr;
}

$bytes* NTLM::calcV2($bytes* nthash, $String* text, $bytes* blob, $bytes* challenge) {
	$useLocalCurrentObjectStackCache();
	$init($StandardCharsets);
	$var($bytes, ntlmv2hash, hmacMD5(nthash, $($nc(text)->getBytes($StandardCharsets::UTF_16LE))));
	$var($bytes, cn, $new($bytes, $nc(blob)->length + 8));
	$System::arraycopy(challenge, 0, cn, 0, 8);
	$System::arraycopy(blob, 0, cn, 8, blob->length);
	$var($bytes, result, $new($bytes, 16 + blob->length));
	$System::arraycopy($(hmacMD5(ntlmv2hash, cn)), 0, result, 0, 16);
	$System::arraycopy(blob, 0, result, 16, blob->length);
	return result;
}

$bytes* NTLM::ntlm2LM($bytes* nonce) {
	$init(NTLM);
	return $Arrays::copyOf(nonce, 24);
}

$bytes* NTLM::ntlm2NTLM($bytes* ntlmHash, $bytes* nonce, $bytes* challenge) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, b, $Arrays::copyOf(challenge, 16));
	$System::arraycopy(nonce, 0, b, 8, 8);
	$var($bytes, sesshash, $Arrays::copyOf($($nc(this->md5)->digest(b)), 8));
	return calcResponse(ntlmHash, sesshash);
}

$bytes* NTLM::getP1($chars* password) {
	$init(NTLM);
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$init($StandardCharsets);
	return $($$new($String, password)->toUpperCase($Locale::ENGLISH))->getBytes($StandardCharsets::ISO_8859_1);
}

$bytes* NTLM::getP2($chars* password) {
	$init(NTLM);
	$init($StandardCharsets);
	return $$new($String, password)->getBytes($StandardCharsets::UTF_16LE);
}

void clinit$NTLM($Class* class$) {
	NTLM::$assertionsDisabled = !NTLM::class$->desiredAssertionStatus();
	NTLM::DEBUG = $GetBooleanAction::privilegedGetProperty("ntlm.debug"_s);
}

NTLM::NTLM() {
}

$Class* NTLM::load$($String* name, bool initialize) {
	$loadClass(NTLM, name, initialize, &_NTLM_ClassInfo_, clinit$NTLM, allocate$NTLM);
	return class$;
}

$Class* NTLM::class$ = nullptr;

			} // ntlm
		} // security
	} // sun
} // com