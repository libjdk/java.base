#include <sun/security/x509/AlgorithmId.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Module.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Provider.h>
#include <java/security/Security.h>
#include <java/util/AbstractMap.h>
#include <java/util/Arrays.h>
#include <java/util/Iterator.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <jcpp.h>

#undef DSA
#undef EC
#undef ENGLISH
#undef MD2
#undef MD5
#undef MGF1
#undef RSA
#undef RSASSA_PSS
#undef SHA_1

using $ProviderArray = $Array<::java::security::Provider>;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Provider = ::java::security::Provider;
using $Security = ::java::security::Security;
using $AbstractMap = ::java::util::AbstractMap;
using $Arrays = ::java::util::Arrays;
using $Iterator = ::java::util::Iterator;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;

namespace sun {
	namespace security {
		namespace x509 {

$CompoundAttribute _AlgorithmId_MethodAnnotations_init$0[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _AlgorithmId_MethodAnnotations_getAlgorithmId17[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _AlgorithmId_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(AlgorithmId, serialVersionUID)},
	{"algid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE, $field(AlgorithmId, algid)},
	{"algParams", "Ljava/security/AlgorithmParameters;", nullptr, $PRIVATE, $field(AlgorithmId, algParams)},
	{"encodedParams", "[B", nullptr, $PROTECTED | $TRANSIENT, $field(AlgorithmId, encodedParams)},
	{"aliasOidsTable", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $STATIC | $VOLATILE, $staticField(AlgorithmId, aliasOidsTable$)},
	{"MD2_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, MD2_oid)},
	{"MD5_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, MD5_oid)},
	{"SHA_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, SHA_oid)},
	{"SHA224_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, SHA224_oid)},
	{"SHA256_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, SHA256_oid)},
	{"SHA384_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, SHA384_oid)},
	{"SHA512_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, SHA512_oid)},
	{"SHA512_224_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, SHA512_224_oid)},
	{"SHA512_256_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, SHA512_256_oid)},
	{"SHA3_224_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, SHA3_224_oid)},
	{"SHA3_256_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, SHA3_256_oid)},
	{"SHA3_384_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, SHA3_384_oid)},
	{"SHA3_512_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, SHA3_512_oid)},
	{"DSA_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, DSA_oid)},
	{"EC_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, EC_oid)},
	{"RSAEncryption_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, RSAEncryption_oid)},
	{"RSASSA_PSS_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, RSASSA_PSS_oid)},
	{"MGF1_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, MGF1_oid)},
	{"ed25519_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, ed25519_oid)},
	{"ed448_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, ed448_oid)},
	{"x25519_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, x25519_oid)},
	{"x448_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, x448_oid)},
	{"SHA224withECDSA_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, SHA224withECDSA_oid)},
	{"SHA256withECDSA_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, SHA256withECDSA_oid)},
	{"SHA384withECDSA_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, SHA384withECDSA_oid)},
	{"SHA512withECDSA_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AlgorithmId, SHA512withECDSA_oid)},
	{}
};

$MethodInfo _AlgorithmId_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "()V", nullptr, $PUBLIC | $DEPRECATED, $method(AlgorithmId, init$, void), nullptr, nullptr, _AlgorithmId_MethodAnnotations_init$0},
	{"<init>", "(Lsun/security/util/ObjectIdentifier;)V", nullptr, $PUBLIC, $method(AlgorithmId, init$, void, $ObjectIdentifier*)},
	{"<init>", "(Lsun/security/util/ObjectIdentifier;Ljava/security/AlgorithmParameters;)V", nullptr, $PUBLIC, $method(AlgorithmId, init$, void, $ObjectIdentifier*, $AlgorithmParameters*)},
	{"<init>", "(Lsun/security/util/ObjectIdentifier;Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(AlgorithmId, init$, void, $ObjectIdentifier*, $DerValue*), "java.io.IOException"},
	{"algOID", "(Ljava/lang/String;)Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE | $STATIC, $staticMethod(AlgorithmId, algOID, $ObjectIdentifier*, $String*), "java.io.IOException"},
	{"aliasOidsTable", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(AlgorithmId, aliasOidsTable, $Map*)},
	{"clearAliasOidsTable", "()V", nullptr, $PUBLIC | $STATIC, $staticMethod(AlgorithmId, clearAliasOidsTable, void)},
	{"collectOIDAliases", "()Ljava/util/concurrent/ConcurrentHashMap;", "()Ljava/util/concurrent/ConcurrentHashMap<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(AlgorithmId, collectOIDAliases, $ConcurrentHashMap*)},
	{"decodeParams", "()V", nullptr, $PROTECTED, $virtualMethod(AlgorithmId, decodeParams, void), "java.io.IOException"},
	{"derEncode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $virtualMethod(AlgorithmId, derEncode, void, $OutputStream*), "java.io.IOException"},
	{"encode", "(Lsun/security/util/DerOutputStream;)V", nullptr, $PUBLIC | $FINAL, $method(AlgorithmId, encode, void, $DerOutputStream*), "java.io.IOException"},
	{"encode", "()[B", nullptr, $PUBLIC | $FINAL, $method(AlgorithmId, encode, $bytes*), "java.io.IOException"},
	{"equals", "(Lsun/security/x509/AlgorithmId;)Z", nullptr, $PUBLIC, $virtualMethod(AlgorithmId, equals, bool, AlgorithmId*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(AlgorithmId, equals, bool, Object$*)},
	{"equals", "(Lsun/security/util/ObjectIdentifier;)Z", nullptr, $PUBLIC | $FINAL, $method(AlgorithmId, equals, bool, $ObjectIdentifier*)},
	{"get", "(Ljava/lang/String;)Lsun/security/x509/AlgorithmId;", nullptr, $PUBLIC | $STATIC, $staticMethod(AlgorithmId, get, AlgorithmId*, $String*), "java.security.NoSuchAlgorithmException"},
	{"get", "(Ljava/security/AlgorithmParameters;)Lsun/security/x509/AlgorithmId;", nullptr, $PUBLIC | $STATIC, $staticMethod(AlgorithmId, get, AlgorithmId*, $AlgorithmParameters*), "java.security.NoSuchAlgorithmException"},
	{"getAlgorithmId", "(Ljava/lang/String;)Lsun/security/x509/AlgorithmId;", nullptr, $PUBLIC | $STATIC | $DEPRECATED, $staticMethod(AlgorithmId, getAlgorithmId, AlgorithmId*, $String*), "java.security.NoSuchAlgorithmException", nullptr, _AlgorithmId_MethodAnnotations_getAlgorithmId17},
	{"getEncodedParams", "()[B", nullptr, $PUBLIC, $virtualMethod(AlgorithmId, getEncodedParams, $bytes*), "java.io.IOException"},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(AlgorithmId, getName, $String*)},
	{"getOID", "()Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $FINAL, $method(AlgorithmId, getOID, $ObjectIdentifier*)},
	{"getParameters", "()Ljava/security/AlgorithmParameters;", nullptr, $PUBLIC, $virtualMethod(AlgorithmId, getParameters, $AlgorithmParameters*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(AlgorithmId, hashCode, int32_t)},
	{"isKnownProvider", "(Ljava/security/Provider;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(AlgorithmId, isKnownProvider, bool, $Provider*)},
	{"paramsToString", "()Ljava/lang/String;", nullptr, $PROTECTED, $virtualMethod(AlgorithmId, paramsToString, $String*)},
	{"parse", "(Lsun/security/util/DerValue;)Lsun/security/x509/AlgorithmId;", nullptr, $PUBLIC | $STATIC, $staticMethod(AlgorithmId, parse, AlgorithmId*, $DerValue*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(AlgorithmId, toString, $String*)},
	{}
};

$ClassInfo _AlgorithmId_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.x509.AlgorithmId",
	"java.lang.Object",
	"java.io.Serializable,sun.security.util.DerEncoder",
	_AlgorithmId_FieldInfo_,
	_AlgorithmId_MethodInfo_
};

$Object* allocate$AlgorithmId($Class* clazz) {
	return $of($alloc(AlgorithmId));
}

$Object* AlgorithmId::clone() {
	 return this->$Serializable::clone();
}

void AlgorithmId::finalize() {
	this->$Serializable::finalize();
}

$volatile($Map*) AlgorithmId::aliasOidsTable$ = nullptr;
$ObjectIdentifier* AlgorithmId::MD2_oid = nullptr;
$ObjectIdentifier* AlgorithmId::MD5_oid = nullptr;
$ObjectIdentifier* AlgorithmId::SHA_oid = nullptr;
$ObjectIdentifier* AlgorithmId::SHA224_oid = nullptr;
$ObjectIdentifier* AlgorithmId::SHA256_oid = nullptr;
$ObjectIdentifier* AlgorithmId::SHA384_oid = nullptr;
$ObjectIdentifier* AlgorithmId::SHA512_oid = nullptr;
$ObjectIdentifier* AlgorithmId::SHA512_224_oid = nullptr;
$ObjectIdentifier* AlgorithmId::SHA512_256_oid = nullptr;
$ObjectIdentifier* AlgorithmId::SHA3_224_oid = nullptr;
$ObjectIdentifier* AlgorithmId::SHA3_256_oid = nullptr;
$ObjectIdentifier* AlgorithmId::SHA3_384_oid = nullptr;
$ObjectIdentifier* AlgorithmId::SHA3_512_oid = nullptr;
$ObjectIdentifier* AlgorithmId::DSA_oid = nullptr;
$ObjectIdentifier* AlgorithmId::EC_oid = nullptr;
$ObjectIdentifier* AlgorithmId::RSAEncryption_oid = nullptr;
$ObjectIdentifier* AlgorithmId::RSASSA_PSS_oid = nullptr;
$ObjectIdentifier* AlgorithmId::MGF1_oid = nullptr;
$ObjectIdentifier* AlgorithmId::ed25519_oid = nullptr;
$ObjectIdentifier* AlgorithmId::ed448_oid = nullptr;
$ObjectIdentifier* AlgorithmId::x25519_oid = nullptr;
$ObjectIdentifier* AlgorithmId::x448_oid = nullptr;
$ObjectIdentifier* AlgorithmId::SHA224withECDSA_oid = nullptr;
$ObjectIdentifier* AlgorithmId::SHA256withECDSA_oid = nullptr;
$ObjectIdentifier* AlgorithmId::SHA384withECDSA_oid = nullptr;
$ObjectIdentifier* AlgorithmId::SHA512withECDSA_oid = nullptr;

void AlgorithmId::init$() {
}

void AlgorithmId::init$($ObjectIdentifier* oid) {
	$set(this, algid, oid);
}

void AlgorithmId::init$($ObjectIdentifier* oid, $AlgorithmParameters* algparams) {
	$set(this, algid, oid);
	$set(this, algParams, algparams);
	if (this->algParams != nullptr) {
		try {
			$set(this, encodedParams, $nc(this->algParams)->getEncoded());
		} catch ($IOException& ioe) {
		}
	}
}

void AlgorithmId::init$($ObjectIdentifier* oid, $DerValue* params) {
	$set(this, algid, oid);
	if (params != nullptr) {
		$set(this, encodedParams, params->toByteArray());
		decodeParams();
	}
}

void AlgorithmId::decodeParams() {
	$useLocalCurrentObjectStackCache();
	$var($String, algidName, getName());
	try {
		$set(this, algParams, $AlgorithmParameters::getInstance(algidName));
	} catch ($NoSuchAlgorithmException& e) {
		$set(this, algParams, nullptr);
		return;
	}
	$nc(this->algParams)->init($cast($bytes, $($nc(this->encodedParams)->clone())));
}

void AlgorithmId::encode($DerOutputStream* out) {
	derEncode(out);
}

void AlgorithmId::derEncode($OutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	$var($DerOutputStream, tmp, $new($DerOutputStream));
	bytes->putOID(this->algid);
	if (this->algParams != nullptr && this->encodedParams == nullptr) {
		$set(this, encodedParams, $nc(this->algParams)->getEncoded());
	}
	if (this->encodedParams == nullptr) {
		bool var$7 = $nc(this->algid)->equals(AlgorithmId::RSASSA_PSS_oid);
		bool var$6 = var$7 || $nc(this->algid)->equals(AlgorithmId::ed448_oid);
		bool var$5 = var$6 || $nc(this->algid)->equals(AlgorithmId::ed25519_oid);
		bool var$4 = var$5 || $nc(this->algid)->equals(AlgorithmId::x448_oid);
		bool var$3 = var$4 || $nc(this->algid)->equals(AlgorithmId::x25519_oid);
		bool var$2 = var$3 || $nc(this->algid)->equals(AlgorithmId::SHA224withECDSA_oid);
		bool var$1 = var$2 || $nc(this->algid)->equals(AlgorithmId::SHA256withECDSA_oid);
		bool var$0 = var$1 || $nc(this->algid)->equals(AlgorithmId::SHA384withECDSA_oid);
		if (var$0 || $nc(this->algid)->equals(AlgorithmId::SHA512withECDSA_oid)) {
		} else {
			bytes->putNull();
		}
	} else {
		bytes->write(this->encodedParams);
	}
	tmp->write($DerValue::tag_Sequence, bytes);
	$nc(out)->write($(tmp->toByteArray()));
}

$bytes* AlgorithmId::encode() {
	$var($DerOutputStream, out, $new($DerOutputStream));
	derEncode(out);
	return out->toByteArray();
}

$ObjectIdentifier* AlgorithmId::getOID() {
	return this->algid;
}

$String* AlgorithmId::getName() {
	$useLocalCurrentObjectStackCache();
	$var($String, oidStr, $nc(this->algid)->toString());
	$KnownOIDs* o = $KnownOIDs::findMatch(oidStr);
	if (o == $KnownOIDs::SpecifiedSHA2withECDSA) {
		if (this->encodedParams != nullptr) {
			try {
				$var(AlgorithmId, digestParams, AlgorithmId::parse($$new($DerValue, this->encodedParams)));
				$var($String, digestAlg, $nc(digestParams)->getName());
				return $str({$($nc(digestAlg)->replace(static_cast<$CharSequence*>("-"_s), static_cast<$CharSequence*>(""_s))), "withECDSA"_s});
			} catch ($IOException& e) {
			}
		}
	}
	if (o != nullptr) {
		return o->stdName();
	} else {
		$var($String, n, $cast($String, $nc($(aliasOidsTable()))->get(oidStr)));
		if (n != nullptr) {
			return n;
		} else {
			return $nc(this->algid)->toString();
		}
	}
}

$AlgorithmParameters* AlgorithmId::getParameters() {
	return this->algParams;
}

$bytes* AlgorithmId::getEncodedParams() {
	$useLocalCurrentObjectStackCache();
	$init($KnownOIDs);
	return (this->encodedParams == nullptr || $nc($($nc(this->algid)->toString()))->equals($($KnownOIDs::SpecifiedSHA2withECDSA->value()))) ? ($bytes*)nullptr : $cast($bytes, $nc(this->encodedParams)->clone());
}

bool AlgorithmId::equals(AlgorithmId* other) {
	bool var$0 = $nc(this->algid)->equals($of($nc(other)->algid));
	return var$0 && $Arrays::equals(this->encodedParams, $nc(other)->encodedParams);
}

bool AlgorithmId::equals(Object$* other) {
	if ($equals(this, other)) {
		return true;
	}
	if ($instanceOf(AlgorithmId, other)) {
		return equals($cast(AlgorithmId, other));
	} else if ($instanceOf($ObjectIdentifier, other)) {
		return equals($cast($ObjectIdentifier, other));
	} else {
		return false;
	}
}

bool AlgorithmId::equals($ObjectIdentifier* id) {
	return $nc(this->algid)->equals($of(id));
}

int32_t AlgorithmId::hashCode() {
	int32_t hashCode = $nc(this->algid)->hashCode();
	hashCode = 31 * hashCode + $Arrays::hashCode(this->encodedParams);
	return hashCode;
}

$String* AlgorithmId::paramsToString() {
	if (this->encodedParams == nullptr) {
		return ""_s;
	} else if (this->algParams != nullptr) {
		return $str({", "_s, $($nc(this->algParams)->toString())});
	} else {
		return ", params unparsed"_s;
	}
}

$String* AlgorithmId::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $(getName()));
	return $concat(var$0, $(paramsToString()));
}

AlgorithmId* AlgorithmId::parse($DerValue* val) {
	$init(AlgorithmId);
	$useLocalCurrentObjectStackCache();
	if ($nc(val)->tag != $DerValue::tag_Sequence) {
		$throwNew($IOException, "algid parse error, not a sequence"_s);
	}
	$var($ObjectIdentifier, algid, nullptr);
	$var($DerValue, params, nullptr);
	$var($DerInputStream, in, $nc(val)->toDerInputStream());
	$assign(algid, $nc(in)->getOID());
	if (in->available() == 0) {
		$assign(params, nullptr);
	} else {
		$assign(params, in->getDerValue());
		if ($nc(params)->tag == $DerValue::tag_Null) {
			if (params->length() != 0) {
				$throwNew($IOException, "invalid NULL"_s);
			}
			$assign(params, nullptr);
		}
		if (in->available() != 0) {
			$throwNew($IOException, "Invalid AlgorithmIdentifier: extra data"_s);
		}
	}
	return $new(AlgorithmId, algid, params);
}

AlgorithmId* AlgorithmId::getAlgorithmId($String* algname) {
	$init(AlgorithmId);
	return get(algname);
}

AlgorithmId* AlgorithmId::get($String* algname) {
	$init(AlgorithmId);
	$useLocalCurrentObjectStackCache();
	$var($ObjectIdentifier, oid, nullptr);
	try {
		$assign(oid, algOID(algname));
	} catch ($IOException& ioe) {
		$throwNew($NoSuchAlgorithmException, $$str({"Invalid ObjectIdentifier "_s, algname}));
	}
	if (oid == nullptr) {
		$throwNew($NoSuchAlgorithmException, $$str({"unrecognized algorithm name: "_s, algname}));
	}
	return $new(AlgorithmId, oid);
}

AlgorithmId* AlgorithmId::get($AlgorithmParameters* algparams) {
	$init(AlgorithmId);
	$useLocalCurrentObjectStackCache();
	$var($ObjectIdentifier, oid, nullptr);
	$var($String, algname, $nc(algparams)->getAlgorithm());
	try {
		$assign(oid, algOID(algname));
	} catch ($IOException& ioe) {
		$throwNew($NoSuchAlgorithmException, $$str({"Invalid ObjectIdentifier "_s, algname}));
	}
	if (oid == nullptr) {
		$throwNew($NoSuchAlgorithmException, $$str({"unrecognized algorithm name: "_s, algname}));
	}
	return $new(AlgorithmId, oid, algparams);
}

$ObjectIdentifier* AlgorithmId::algOID($String* name$renamed) {
	$init(AlgorithmId);
	$useLocalCurrentObjectStackCache();
	$var($String, name, name$renamed);
	if ($nc(name)->startsWith("OID."_s)) {
		$assign(name, name->substring("OID."_s->length()));
	}
	$KnownOIDs* k = $KnownOIDs::findMatch(name);
	if (k != nullptr) {
		return $ObjectIdentifier::of(k);
	}
	if ($nc(name)->indexOf("."_s) == -1) {
		$init($Locale);
		$assign(name, name->toUpperCase($Locale::ENGLISH));
		$var($String, oidStr, $cast($String, $nc($(aliasOidsTable()))->get(name)));
		if (oidStr != nullptr) {
			return $ObjectIdentifier::of(oidStr);
		}
		return nullptr;
	} else {
		return $ObjectIdentifier::of(name);
	}
}

void AlgorithmId::clearAliasOidsTable() {
	$init(AlgorithmId);
	$assignStatic(AlgorithmId::aliasOidsTable$, nullptr);
}

$Map* AlgorithmId::aliasOidsTable() {
	$init(AlgorithmId);
	$var($Map, tab, AlgorithmId::aliasOidsTable$);
	if (tab == nullptr) {
		$synchronized(AlgorithmId::class$) {
			if (($assign(tab, AlgorithmId::aliasOidsTable$)) == nullptr) {
				$assignStatic(AlgorithmId::aliasOidsTable$, ($assign(tab, static_cast<$Map*>(static_cast<$AbstractMap*>(collectOIDAliases())))));
			}
		}
	}
	return tab;
}

bool AlgorithmId::isKnownProvider($Provider* p) {
	$init(AlgorithmId);
	$useLocalCurrentObjectStackCache();
	$var($String, pn, $nc(p)->getName());
	$var($String, mn, $nc($($of(p)->getClass()->getModule()))->getName());
	if (pn != nullptr && mn != nullptr) {
		bool var$3 = mn->equals("java.base"_s);
		if (var$3) {
			bool var$6 = pn->equals("SUN"_s);
			bool var$5 = var$6 || pn->equals("SunRsaSign"_s);
			bool var$4 = var$5 || pn->equals("SunJCE"_s);
			var$3 = (var$4 || pn->equals("SunJSSE"_s));
		}
		bool var$2 = (var$3);
		if (!var$2) {
			bool var$7 = mn->equals("jdk.crypto.ec"_s);
			var$2 = (var$7 && pn->equals("SunEC"_s));
		}
		bool var$1 = var$2;
		if (!var$1) {
			bool var$8 = mn->equals("jdk.crypto.mscapi"_s);
			var$1 = (var$8 && pn->equals("SunMSCAPI"_s));
		}
		bool var$0 = var$1;
		if (!var$0) {
			bool var$9 = mn->equals("jdk.crypto.cryptoki"_s);
			var$0 = (var$9 && pn->startsWith("SunPKCS11"_s));
		}
		return (var$0);
	} else {
		return false;
	}
}

$ConcurrentHashMap* AlgorithmId::collectOIDAliases() {
	$init(AlgorithmId);
	$useLocalCurrentObjectStackCache();
	$var($ConcurrentHashMap, t, $new($ConcurrentHashMap));
	{
		$var($ProviderArray, arr$, $Security::getProviders());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Provider, provider, arr$->get(i$));
			{
				if (isKnownProvider(provider)) {
					continue;
				}
				{
					$var($Iterator, i$, $nc($($nc(provider)->keySet()))->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($Object, key, i$->next());
						{
							$var($String, alias, $cast($String, key));
							$init($Locale);
							$var($String, upperCaseAlias, $nc(alias)->toUpperCase($Locale::ENGLISH));
							int32_t index = 0;
							bool var$0 = upperCaseAlias->startsWith("ALG.ALIAS"_s);
							if (var$0 && (index = upperCaseAlias->indexOf("OID."_s, 0)) != -1) {
								index += "OID."_s->length();
								if (index == alias->length()) {
									break;
								}
								$var($String, ostr, alias->substring(index));
								$var($String, stdAlgName, provider->getProperty(alias));
								if (stdAlgName != nullptr) {
									$assign(stdAlgName, stdAlgName->toUpperCase($Locale::ENGLISH));
								}
								if ($KnownOIDs::findMatch(stdAlgName) == nullptr) {
									t->putIfAbsent(stdAlgName, ostr);
								}
								if ($KnownOIDs::findMatch(ostr) == nullptr) {
									t->putIfAbsent(ostr, stdAlgName);
								}
							}
						}
					}
				}
			}
		}
	}
	return t;
}

void clinit$AlgorithmId($Class* class$) {
	$init($KnownOIDs);
	$assignStatic(AlgorithmId::MD2_oid, $ObjectIdentifier::of($KnownOIDs::MD2));
	$assignStatic(AlgorithmId::MD5_oid, $ObjectIdentifier::of($KnownOIDs::MD5));
	$assignStatic(AlgorithmId::SHA_oid, $ObjectIdentifier::of($KnownOIDs::SHA_1));
	$assignStatic(AlgorithmId::SHA224_oid, $ObjectIdentifier::of($KnownOIDs::SHA_224));
	$assignStatic(AlgorithmId::SHA256_oid, $ObjectIdentifier::of($KnownOIDs::SHA_256));
	$assignStatic(AlgorithmId::SHA384_oid, $ObjectIdentifier::of($KnownOIDs::SHA_384));
	$assignStatic(AlgorithmId::SHA512_oid, $ObjectIdentifier::of($KnownOIDs::SHA_512));
	$assignStatic(AlgorithmId::SHA512_224_oid, $ObjectIdentifier::of($KnownOIDs::SHA_512$224));
	$assignStatic(AlgorithmId::SHA512_256_oid, $ObjectIdentifier::of($KnownOIDs::SHA_512$256));
	$assignStatic(AlgorithmId::SHA3_224_oid, $ObjectIdentifier::of($KnownOIDs::SHA3_224));
	$assignStatic(AlgorithmId::SHA3_256_oid, $ObjectIdentifier::of($KnownOIDs::SHA3_256));
	$assignStatic(AlgorithmId::SHA3_384_oid, $ObjectIdentifier::of($KnownOIDs::SHA3_384));
	$assignStatic(AlgorithmId::SHA3_512_oid, $ObjectIdentifier::of($KnownOIDs::SHA3_512));
	$assignStatic(AlgorithmId::DSA_oid, $ObjectIdentifier::of($KnownOIDs::DSA));
	$assignStatic(AlgorithmId::EC_oid, $ObjectIdentifier::of($KnownOIDs::EC));
	$assignStatic(AlgorithmId::RSAEncryption_oid, $ObjectIdentifier::of($KnownOIDs::RSA));
	$assignStatic(AlgorithmId::RSASSA_PSS_oid, $ObjectIdentifier::of($KnownOIDs::RSASSA_PSS));
	$assignStatic(AlgorithmId::MGF1_oid, $ObjectIdentifier::of($KnownOIDs::MGF1));
	$assignStatic(AlgorithmId::ed25519_oid, $ObjectIdentifier::of($KnownOIDs::Ed25519));
	$assignStatic(AlgorithmId::ed448_oid, $ObjectIdentifier::of($KnownOIDs::Ed448));
	$assignStatic(AlgorithmId::x25519_oid, $ObjectIdentifier::of($KnownOIDs::X25519));
	$assignStatic(AlgorithmId::x448_oid, $ObjectIdentifier::of($KnownOIDs::X448));
	$assignStatic(AlgorithmId::SHA224withECDSA_oid, $ObjectIdentifier::of($KnownOIDs::SHA224withECDSA));
	$assignStatic(AlgorithmId::SHA256withECDSA_oid, $ObjectIdentifier::of($KnownOIDs::SHA256withECDSA));
	$assignStatic(AlgorithmId::SHA384withECDSA_oid, $ObjectIdentifier::of($KnownOIDs::SHA384withECDSA));
	$assignStatic(AlgorithmId::SHA512withECDSA_oid, $ObjectIdentifier::of($KnownOIDs::SHA512withECDSA));
}

AlgorithmId::AlgorithmId() {
}

$Class* AlgorithmId::load$($String* name, bool initialize) {
	$loadClass(AlgorithmId, name, initialize, &_AlgorithmId_ClassInfo_, clinit$AlgorithmId, allocate$AlgorithmId);
	return class$;
}

$Class* AlgorithmId::class$ = nullptr;

		} // x509
	} // security
} // sun