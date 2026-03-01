#include <sun/security/rsa/PSSParameters.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/security/AlgorithmParametersSpi.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/InvalidParameterSpecException.h>
#include <java/security/spec/MGF1ParameterSpec.h>
#include <java/security/spec/PSSParameterSpec.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/AlgorithmId.h>
#include <jcpp.h>

#undef DEFAULT
#undef SHA1
#undef TAG_CONTEXT
#undef TRAILER_FIELD_BC

using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $AlgorithmParametersSpi = ::java::security::AlgorithmParametersSpi;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $InvalidParameterSpecException = ::java::security::spec::InvalidParameterSpecException;
using $MGF1ParameterSpec = ::java::security::spec::MGF1ParameterSpec;
using $PSSParameterSpec = ::java::security::spec::PSSParameterSpec;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $AlgorithmId = ::sun::security::x509::AlgorithmId;

namespace sun {
	namespace security {
		namespace rsa {

$FieldInfo _PSSParameters_FieldInfo_[] = {
	{"spec", "Ljava/security/spec/PSSParameterSpec;", nullptr, $PRIVATE, $field(PSSParameters, spec)},
	{}
};

$MethodInfo _PSSParameters_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PSSParameters, init$, void)},
	{"engineGetEncoded", "()[B", nullptr, $PROTECTED, $virtualMethod(PSSParameters, engineGetEncoded, $bytes*), "java.io.IOException"},
	{"engineGetEncoded", "(Ljava/lang/String;)[B", nullptr, $PROTECTED, $virtualMethod(PSSParameters, engineGetEncoded, $bytes*, $String*), "java.io.IOException"},
	{"engineGetParameterSpec", "(Ljava/lang/Class;)Ljava/security/spec/AlgorithmParameterSpec;", "<T::Ljava/security/spec/AlgorithmParameterSpec;>(Ljava/lang/Class<TT;>;)TT;", $PROTECTED, $virtualMethod(PSSParameters, engineGetParameterSpec, $AlgorithmParameterSpec*, $Class*), "java.security.spec.InvalidParameterSpecException"},
	{"engineInit", "(Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, $PROTECTED, $virtualMethod(PSSParameters, engineInit, void, $AlgorithmParameterSpec*), "java.security.spec.InvalidParameterSpecException"},
	{"engineInit", "([B)V", nullptr, $PROTECTED, $virtualMethod(PSSParameters, engineInit, void, $bytes*), "java.io.IOException"},
	{"engineInit", "([BLjava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(PSSParameters, engineInit, void, $bytes*, $String*), "java.io.IOException"},
	{"engineToString", "()Ljava/lang/String;", nullptr, $PROTECTED, $virtualMethod(PSSParameters, engineToString, $String*)},
	{"getEncoded", "(Ljava/security/spec/PSSParameterSpec;)[B", nullptr, $PUBLIC | $STATIC, $staticMethod(PSSParameters, getEncoded, $bytes*, $PSSParameterSpec*), "java.io.IOException"},
	{}
};

$ClassInfo _PSSParameters_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.rsa.PSSParameters",
	"java.security.AlgorithmParametersSpi",
	nullptr,
	_PSSParameters_FieldInfo_,
	_PSSParameters_MethodInfo_
};

$Object* allocate$PSSParameters($Class* clazz) {
	return $of($alloc(PSSParameters));
}

void PSSParameters::init$() {
	$AlgorithmParametersSpi::init$();
}

void PSSParameters::engineInit($AlgorithmParameterSpec* paramSpec) {
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf($PSSParameterSpec, paramSpec))) {
		$throwNew($InvalidParameterSpecException, "Inappropriate parameter specification"_s);
	}
	$var($PSSParameterSpec, spec, $cast($PSSParameterSpec, paramSpec));
	$var($String, mgfName, $nc(spec)->getMGFAlgorithm());
	if (!$nc($(spec->getMGFAlgorithm()))->equalsIgnoreCase("MGF1"_s)) {
		$throwNew($InvalidParameterSpecException, $$str({"Unsupported mgf "_s, mgfName, "; MGF1 only"_s}));
	}
	$var($AlgorithmParameterSpec, mgfSpec, spec->getMGFParameters());
	if (!($instanceOf($MGF1ParameterSpec, mgfSpec))) {
		$throwNew($InvalidParameterSpecException, "Inappropriate mgf parameters; non-null MGF1ParameterSpec only"_s);
	}
	$set(this, spec, spec);
}

void PSSParameters::engineInit($bytes* encoded) {
	$useLocalCurrentObjectStackCache();
	$init($PSSParameterSpec);
	$var($String, mdName, $nc($PSSParameterSpec::DEFAULT)->getDigestAlgorithm());
	$var($MGF1ParameterSpec, mgfSpec, $cast($MGF1ParameterSpec, $nc($PSSParameterSpec::DEFAULT)->getMGFParameters()));
	int32_t saltLength = $nc($PSSParameterSpec::DEFAULT)->getSaltLength();
	int32_t trailerField = $nc($PSSParameterSpec::DEFAULT)->getTrailerField();
	$var($DerInputStream, der, $new($DerInputStream, encoded));
	$var($DerValueArray, datum, der->getSequence(4));
	{
		$var($DerValueArray, arr$, datum);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($DerValue, d, arr$->get(i$));
			{
				if ($nc(d)->isContextSpecific((int8_t)0)) {
					$assign(mdName, $nc($($AlgorithmId::parse($($nc(d->data$)->getDerValue()))))->getName());
				} else if (d->isContextSpecific((int8_t)1)) {
					$var($AlgorithmId, val, $AlgorithmId::parse($($nc(d->data$)->getDerValue())));
					if (!$nc($($nc(val)->getOID()))->equals($AlgorithmId::MGF1_oid)) {
						$throwNew($IOException, "Only MGF1 mgf is supported"_s);
					}
					$var($AlgorithmId, params, $AlgorithmId::parse($$new($DerValue, $($nc(val)->getEncodedParams()))));
					$var($String, mgfDigestName, $nc(params)->getName());
					{
						$var($String, s4425$, mgfDigestName);
						int32_t tmp4425$ = -1;
						switch ($nc(s4425$)->hashCode()) {
						case 0x04B35330:
							{
								if (s4425$->equals("SHA-1"_s)) {
									tmp4425$ = 0;
								}
								break;
							}
						case (int32_t)0xA52B5133:
							{
								if (s4425$->equals("SHA-224"_s)) {
									tmp4425$ = 1;
								}
								break;
							}
						case (int32_t)0xA52B5192:
							{
								if (s4425$->equals("SHA-256"_s)) {
									tmp4425$ = 2;
								}
								break;
							}
						case (int32_t)0xA52B55AE:
							{
								if (s4425$->equals("SHA-384"_s)) {
									tmp4425$ = 3;
								}
								break;
							}
						case (int32_t)0xA52B5C55:
							{
								if (s4425$->equals("SHA-512"_s)) {
									tmp4425$ = 4;
								}
								break;
							}
						case 0x2CE1493A:
							{
								if (s4425$->equals("SHA-512/224"_s)) {
									tmp4425$ = 5;
								}
								break;
							}
						case 0x2CE14999:
							{
								if (s4425$->equals("SHA-512/256"_s)) {
									tmp4425$ = 6;
								}
								break;
							}
						case 0x00911C4E:
							{
								if (s4425$->equals("SHA3-224"_s)) {
									tmp4425$ = 7;
								}
								break;
							}
						case 0x00911CAD:
							{
								if (s4425$->equals("SHA3-256"_s)) {
									tmp4425$ = 8;
								}
								break;
							}
						case 0x009120C9:
							{
								if (s4425$->equals("SHA3-384"_s)) {
									tmp4425$ = 9;
								}
								break;
							}
						case 0x00912770:
							{
								if (s4425$->equals("SHA3-512"_s)) {
									tmp4425$ = 10;
								}
								break;
							}
						}
						switch (tmp4425$) {
						case 0:
							{
								$init($MGF1ParameterSpec);
								$assign(mgfSpec, $MGF1ParameterSpec::SHA1);
								break;
							}
						case 1:
							{
								$init($MGF1ParameterSpec);
								$assign(mgfSpec, $MGF1ParameterSpec::SHA224);
								break;
							}
						case 2:
							{
								$init($MGF1ParameterSpec);
								$assign(mgfSpec, $MGF1ParameterSpec::SHA256);
								break;
							}
						case 3:
							{
								$init($MGF1ParameterSpec);
								$assign(mgfSpec, $MGF1ParameterSpec::SHA384);
								break;
							}
						case 4:
							{
								$init($MGF1ParameterSpec);
								$assign(mgfSpec, $MGF1ParameterSpec::SHA512);
								break;
							}
						case 5:
							{
								$init($MGF1ParameterSpec);
								$assign(mgfSpec, $MGF1ParameterSpec::SHA512_224);
								break;
							}
						case 6:
							{
								$init($MGF1ParameterSpec);
								$assign(mgfSpec, $MGF1ParameterSpec::SHA512_256);
								break;
							}
						case 7:
							{
								$init($MGF1ParameterSpec);
								$assign(mgfSpec, $MGF1ParameterSpec::SHA3_224);
								break;
							}
						case 8:
							{
								$init($MGF1ParameterSpec);
								$assign(mgfSpec, $MGF1ParameterSpec::SHA3_256);
								break;
							}
						case 9:
							{
								$init($MGF1ParameterSpec);
								$assign(mgfSpec, $MGF1ParameterSpec::SHA3_384);
								break;
							}
						case 10:
							{
								$init($MGF1ParameterSpec);
								$assign(mgfSpec, $MGF1ParameterSpec::SHA3_512);
								break;
							}
						default:
							{
								$throwNew($IOException, $$str({"Unrecognized message digest algorithm "_s, mgfDigestName}));
							}
						}
					}
				} else if (d->isContextSpecific((int8_t)2)) {
					saltLength = $nc($($nc(d->data$)->getDerValue()))->getInteger();
					if (saltLength < 0) {
						$throwNew($IOException, "Negative value for saltLength"_s);
					}
				} else if (d->isContextSpecific((int8_t)3)) {
					trailerField = $nc($($nc(d->data$)->getDerValue()))->getInteger();
					if (trailerField != 1) {
						$throwNew($IOException, $$str({"Unsupported trailerField value "_s, $$str(trailerField)}));
					}
				} else {
					$throwNew($IOException, "Invalid encoded PSSParameters"_s);
				}
			}
		}
	}
	$set(this, spec, $new($PSSParameterSpec, mdName, "MGF1"_s, mgfSpec, saltLength, trailerField));
}

void PSSParameters::engineInit($bytes* encoded, $String* decodingMethod) {
	if ((decodingMethod != nullptr) && (!decodingMethod->equalsIgnoreCase("ASN.1"_s))) {
		$throwNew($IllegalArgumentException, "Only support ASN.1 format"_s);
	}
	engineInit(encoded);
}

$AlgorithmParameterSpec* PSSParameters::engineGetParameterSpec($Class* paramSpec) {
	$load($PSSParameterSpec);
	if ($PSSParameterSpec::class$->isAssignableFrom(paramSpec)) {
		return $cast($AlgorithmParameterSpec, $nc(paramSpec)->cast(this->spec));
	} else {
		$throwNew($InvalidParameterSpecException, "Inappropriate parameter specification"_s);
	}
}

$bytes* PSSParameters::engineGetEncoded() {
	return getEncoded(this->spec);
}

$bytes* PSSParameters::engineGetEncoded($String* encMethod) {
	if ((encMethod != nullptr) && (!encMethod->equalsIgnoreCase("ASN.1"_s))) {
		$throwNew($IllegalArgumentException, "Only support ASN.1 format"_s);
	}
	return engineGetEncoded();
}

$String* PSSParameters::engineToString() {
	return $nc(this->spec)->toString();
}

$bytes* PSSParameters::getEncoded($PSSParameterSpec* spec) {
	$init(PSSParameters);
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmParameterSpec, mgfSpec, $nc(spec)->getMGFParameters());
	if (!($instanceOf($MGF1ParameterSpec, mgfSpec))) {
		$throwNew($IOException, $$str({"Cannot encode "_s, mgfSpec}));
	}
	$var($MGF1ParameterSpec, mgf1Spec, $cast($MGF1ParameterSpec, mgfSpec));
	$var($DerOutputStream, tmp, $new($DerOutputStream));
	$var($DerOutputStream, tmp2, nullptr);
	$var($DerOutputStream, tmp3, nullptr);
	$var($AlgorithmId, mdAlgId, nullptr);
	try {
		$assign(mdAlgId, $AlgorithmId::get($(spec->getDigestAlgorithm())));
	} catch ($NoSuchAlgorithmException& nsae) {
		$throwNew($IOException, $$str({"AlgorithmId "_s, $(spec->getDigestAlgorithm()), " impl not found"_s}));
	}
	$init($AlgorithmId);
	if (!$nc($($nc(mdAlgId)->getOID()))->equals($AlgorithmId::SHA_oid)) {
		$assign(tmp2, $new($DerOutputStream));
		mdAlgId->derEncode(tmp2);
		tmp->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), tmp2);
	}
	$var($AlgorithmId, mgfDigestId, nullptr);
	try {
		$assign(mgfDigestId, $AlgorithmId::get($($nc(mgf1Spec)->getDigestAlgorithm())));
	} catch ($NoSuchAlgorithmException& nase) {
		$throwNew($IOException, $$str({"AlgorithmId "_s, $($nc(mgf1Spec)->getDigestAlgorithm()), " impl not found"_s}));
	}
	if (!$nc($($nc(mgfDigestId)->getOID()))->equals($AlgorithmId::SHA_oid)) {
		$assign(tmp2, $new($DerOutputStream));
		tmp2->putOID($AlgorithmId::MGF1_oid);
		mgfDigestId->encode(tmp2);
		$assign(tmp3, $new($DerOutputStream));
		tmp3->write($DerValue::tag_Sequence, tmp2);
		tmp->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1), tmp3);
	}
	if (spec->getSaltLength() != 20) {
		$assign(tmp2, $new($DerOutputStream));
		tmp2->putInteger(spec->getSaltLength());
		tmp->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2), tmp2);
	}
	if (spec->getTrailerField() != $PSSParameterSpec::TRAILER_FIELD_BC) {
		$assign(tmp2, $new($DerOutputStream));
		tmp2->putInteger(spec->getTrailerField());
		tmp->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3), tmp2);
	}
	$var($DerOutputStream, out, $new($DerOutputStream));
	out->write($DerValue::tag_Sequence, tmp);
	return out->toByteArray();
}

PSSParameters::PSSParameters() {
}

$Class* PSSParameters::load$($String* name, bool initialize) {
	$loadClass(PSSParameters, name, initialize, &_PSSParameters_ClassInfo_, allocate$PSSParameters);
	return class$;
}

$Class* PSSParameters::class$ = nullptr;

		} // rsa
	} // security
} // sun