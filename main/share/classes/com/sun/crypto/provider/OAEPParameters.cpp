#include <com/sun/crypto/provider/OAEPParameters.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/math/BigInteger.h>
#include <java/security/AlgorithmParametersSpi.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/InvalidParameterSpecException.h>
#include <java/security/spec/MGF1ParameterSpec.h>
#include <javax/crypto/spec/OAEPParameterSpec.h>
#include <javax/crypto/spec/PSource$PSpecified.h>
#include <javax/crypto/spec/PSource.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/AlgorithmId.h>
#include <jcpp.h>

#undef MGF1
#undef OID_MGF1
#undef SHA1
#undef TAG_CONTEXT

using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $AlgorithmParametersSpi = ::java::security::AlgorithmParametersSpi;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $InvalidParameterSpecException = ::java::security::spec::InvalidParameterSpecException;
using $MGF1ParameterSpec = ::java::security::spec::MGF1ParameterSpec;
using $OAEPParameterSpec = ::javax::crypto::spec::OAEPParameterSpec;
using $PSource = ::javax::crypto::spec::PSource;
using $PSource$PSpecified = ::javax::crypto::spec::PSource$PSpecified;
using $Debug = ::sun::security::util::Debug;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $AlgorithmId = ::sun::security::x509::AlgorithmId;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _OAEPParameters_FieldInfo_[] = {
	{"mdName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(OAEPParameters, mdName)},
	{"mgfSpec", "Ljava/security/spec/MGF1ParameterSpec;", nullptr, $PRIVATE, $field(OAEPParameters, mgfSpec)},
	{"p", "[B", nullptr, $PRIVATE, $field(OAEPParameters, p)},
	{"OID_MGF1", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE | $STATIC, $staticField(OAEPParameters, OID_MGF1)},
	{"OID_PSpecified", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE | $STATIC, $staticField(OAEPParameters, OID_PSpecified)},
	{}
};

$MethodInfo _OAEPParameters_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(OAEPParameters, init$, void)},
	{"engineGetEncoded", "()[B", nullptr, $PROTECTED, $virtualMethod(OAEPParameters, engineGetEncoded, $bytes*), "java.io.IOException"},
	{"engineGetEncoded", "(Ljava/lang/String;)[B", nullptr, $PROTECTED, $virtualMethod(OAEPParameters, engineGetEncoded, $bytes*, $String*), "java.io.IOException"},
	{"engineGetParameterSpec", "(Ljava/lang/Class;)Ljava/security/spec/AlgorithmParameterSpec;", "<T::Ljava/security/spec/AlgorithmParameterSpec;>(Ljava/lang/Class<TT;>;)TT;", $PROTECTED, $virtualMethod(OAEPParameters, engineGetParameterSpec, $AlgorithmParameterSpec*, $Class*), "java.security.spec.InvalidParameterSpecException"},
	{"engineInit", "(Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, $PROTECTED, $virtualMethod(OAEPParameters, engineInit, void, $AlgorithmParameterSpec*), "java.security.spec.InvalidParameterSpecException"},
	{"engineInit", "([B)V", nullptr, $PROTECTED, $virtualMethod(OAEPParameters, engineInit, void, $bytes*), "java.io.IOException"},
	{"engineInit", "([BLjava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(OAEPParameters, engineInit, void, $bytes*, $String*), "java.io.IOException"},
	{"engineToString", "()Ljava/lang/String;", nullptr, $PROTECTED, $virtualMethod(OAEPParameters, engineToString, $String*)},
	{}
};

$ClassInfo _OAEPParameters_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.OAEPParameters",
	"java.security.AlgorithmParametersSpi",
	nullptr,
	_OAEPParameters_FieldInfo_,
	_OAEPParameters_MethodInfo_
};

$Object* allocate$OAEPParameters($Class* clazz) {
	return $of($alloc(OAEPParameters));
}

$ObjectIdentifier* OAEPParameters::OID_MGF1 = nullptr;
$ObjectIdentifier* OAEPParameters::OID_PSpecified = nullptr;

void OAEPParameters::init$() {
	$AlgorithmParametersSpi::init$();
}

void OAEPParameters::engineInit($AlgorithmParameterSpec* paramSpec) {
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf($OAEPParameterSpec, paramSpec))) {
		$throwNew($InvalidParameterSpecException, "Inappropriate parameter specification"_s);
	}
	$var($OAEPParameterSpec, spec, $cast($OAEPParameterSpec, paramSpec));
	$set(this, mdName, $nc(spec)->getDigestAlgorithm());
	$var($String, mgfName, spec->getMGFAlgorithm());
	if (!$nc(mgfName)->equalsIgnoreCase("MGF1"_s)) {
		$throwNew($InvalidParameterSpecException, $$str({"Unsupported mgf "_s, mgfName, "; MGF1 only"_s}));
	}
	$var($AlgorithmParameterSpec, mgfSpec, spec->getMGFParameters());
	if (!($instanceOf($MGF1ParameterSpec, mgfSpec))) {
		$throwNew($InvalidParameterSpecException, "Inappropriate mgf parameters; non-null MGF1ParameterSpec only"_s);
	}
	$set(this, mgfSpec, $cast($MGF1ParameterSpec, mgfSpec));
	$var($PSource, pSrc, spec->getPSource());
	if ($nc($($nc(pSrc)->getAlgorithm()))->equals("PSpecified"_s)) {
		$set(this, p, $nc(($cast($PSource$PSpecified, pSrc)))->getValue());
	} else {
		$throwNew($InvalidParameterSpecException, $$str({"Unsupported pSource "_s, $(pSrc->getAlgorithm()), "; PSpecified only"_s}));
	}
}

void OAEPParameters::engineInit($bytes* encoded) {
	$useLocalCurrentObjectStackCache();
	$var($DerInputStream, der, $new($DerInputStream, encoded));
	$set(this, mdName, "SHA-1"_s);
	$init($MGF1ParameterSpec);
	$set(this, mgfSpec, $MGF1ParameterSpec::SHA1);
	$set(this, p, $new($bytes, 0));
	$var($DerValueArray, datum, der->getSequence(3));
	for (int32_t i = 0; i < $nc(datum)->length; ++i) {
		$var($DerValue, data, datum->get(i));
		if ($nc(data)->isContextSpecific((int8_t)0)) {
			$set(this, mdName, $nc($($AlgorithmId::parse($($nc(data->data$)->getDerValue()))))->getName());
		} else if (data->isContextSpecific((int8_t)1)) {
			$var($AlgorithmId, val, $AlgorithmId::parse($($nc(data->data$)->getDerValue())));
			if (!$nc($($nc(val)->getOID()))->equals(OAEPParameters::OID_MGF1)) {
				$throwNew($IOException, "Only MGF1 mgf is supported"_s);
			}
			$var($AlgorithmId, params, $AlgorithmId::parse($$new($DerValue, $($nc(val)->getEncodedParams()))));
			$var($String, mgfDigestName, $nc(params)->getName());
			if ($nc(mgfDigestName)->equals("SHA-1"_s)) {
				$set(this, mgfSpec, $MGF1ParameterSpec::SHA1);
			} else if (mgfDigestName->equals("SHA-224"_s)) {
				$set(this, mgfSpec, $MGF1ParameterSpec::SHA224);
			} else if (mgfDigestName->equals("SHA-256"_s)) {
				$set(this, mgfSpec, $MGF1ParameterSpec::SHA256);
			} else if (mgfDigestName->equals("SHA-384"_s)) {
				$set(this, mgfSpec, $MGF1ParameterSpec::SHA384);
			} else if (mgfDigestName->equals("SHA-512"_s)) {
				$set(this, mgfSpec, $MGF1ParameterSpec::SHA512);
			} else if (mgfDigestName->equals("SHA-512/224"_s)) {
				$set(this, mgfSpec, $MGF1ParameterSpec::SHA512_224);
			} else if (mgfDigestName->equals("SHA-512/256"_s)) {
				$set(this, mgfSpec, $MGF1ParameterSpec::SHA512_256);
			} else {
				$throwNew($IOException, "Unrecognized message digest algorithm"_s);
			}
		} else if (data->isContextSpecific((int8_t)2)) {
			$var($AlgorithmId, val, $AlgorithmId::parse($($nc(data->data$)->getDerValue())));
			if (!$nc($($nc(val)->getOID()))->equals(OAEPParameters::OID_PSpecified)) {
				$throwNew($IOException, "Wrong OID for pSpecified"_s);
			}
			$var($DerInputStream, dis, $new($DerInputStream, $($nc(val)->getEncodedParams())));
			$set(this, p, dis->getOctetString());
			if (dis->available() != 0) {
				$throwNew($IOException, "Extra data for pSpecified"_s);
			}
		} else {
			$throwNew($IOException, "Invalid encoded OAEPParameters"_s);
		}
	}
}

void OAEPParameters::engineInit($bytes* encoded, $String* decodingMethod) {
	if ((decodingMethod != nullptr) && (!decodingMethod->equalsIgnoreCase("ASN.1"_s))) {
		$throwNew($IllegalArgumentException, "Only support ASN.1 format"_s);
	}
	engineInit(encoded);
}

$AlgorithmParameterSpec* OAEPParameters::engineGetParameterSpec($Class* paramSpec) {
	$useLocalCurrentObjectStackCache();
	$load($OAEPParameterSpec);
	if ($OAEPParameterSpec::class$->isAssignableFrom(paramSpec)) {
		return $cast($AlgorithmParameterSpec, $nc(paramSpec)->cast($$new($OAEPParameterSpec, this->mdName, "MGF1"_s, this->mgfSpec, $$new($PSource$PSpecified, this->p))));
	} else {
		$throwNew($InvalidParameterSpecException, "Inappropriate parameter specification"_s);
	}
}

$bytes* OAEPParameters::engineGetEncoded() {
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, tmp, $new($DerOutputStream));
	$var($DerOutputStream, tmp2, nullptr);
	$var($DerOutputStream, tmp3, nullptr);
	$var($AlgorithmId, mdAlgId, nullptr);
	try {
		$assign(mdAlgId, $AlgorithmId::get(this->mdName));
	} catch ($NoSuchAlgorithmException& nsae) {
		$throwNew($IOException, $$str({"AlgorithmId "_s, this->mdName, " impl not found"_s}));
	}
	$assign(tmp2, $new($DerOutputStream));
	$nc(mdAlgId)->derEncode(tmp2);
	tmp->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), tmp2);
	$assign(tmp2, $new($DerOutputStream));
	tmp2->putOID(OAEPParameters::OID_MGF1);
	$var($AlgorithmId, mgfDigestId, nullptr);
	try {
		$assign(mgfDigestId, $AlgorithmId::get($($nc(this->mgfSpec)->getDigestAlgorithm())));
	} catch ($NoSuchAlgorithmException& nase) {
		$throwNew($IOException, $$str({"AlgorithmId "_s, $($nc(this->mgfSpec)->getDigestAlgorithm()), " impl not found"_s}));
	}
	$nc(mgfDigestId)->encode(tmp2);
	$assign(tmp3, $new($DerOutputStream));
	tmp3->write($DerValue::tag_Sequence, tmp2);
	tmp->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1), tmp3);
	$assign(tmp2, $new($DerOutputStream));
	tmp2->putOID(OAEPParameters::OID_PSpecified);
	tmp2->putOctetString(this->p);
	$assign(tmp3, $new($DerOutputStream));
	tmp3->write($DerValue::tag_Sequence, tmp2);
	tmp->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2), tmp3);
	$var($DerOutputStream, out, $new($DerOutputStream));
	out->write($DerValue::tag_Sequence, tmp);
	return out->toByteArray();
}

$bytes* OAEPParameters::engineGetEncoded($String* encodingMethod) {
	if ((encodingMethod != nullptr) && (!encodingMethod->equalsIgnoreCase("ASN.1"_s))) {
		$throwNew($IllegalArgumentException, "Only support ASN.1 format"_s);
	}
	return engineGetEncoded();
}

$String* OAEPParameters::engineToString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append($$str({"MD: "_s, this->mdName, "\n"_s}));
	sb->append($$str({"MGF: MGF1"_s, $($nc(this->mgfSpec)->getDigestAlgorithm()), "\n"_s}));
	sb->append($$str({"PSource: PSpecified "_s, ($nc(this->p)->length == 0 ? ""_s : $($Debug::toHexString($$new($BigInteger, this->p)))), "\n"_s}));
	return sb->toString();
}

void clinit$OAEPParameters($Class* class$) {
	$init($KnownOIDs);
	$assignStatic(OAEPParameters::OID_MGF1, $ObjectIdentifier::of($KnownOIDs::MGF1));
	$assignStatic(OAEPParameters::OID_PSpecified, $ObjectIdentifier::of($KnownOIDs::PSpecified));
}

OAEPParameters::OAEPParameters() {
}

$Class* OAEPParameters::load$($String* name, bool initialize) {
	$loadClass(OAEPParameters, name, initialize, &_OAEPParameters_ClassInfo_, clinit$OAEPParameters, allocate$OAEPParameters);
	return class$;
}

$Class* OAEPParameters::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com