#include <sun/security/validator/PKIXValidator.h>

#include <java/security/AlgorithmConstraints.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PublicKey.h>
#include <java/security/Timestamp.h>
#include <java/security/cert/CertPath.h>
#include <java/security/cert/CertPathBuilder.h>
#include <java/security/cert/CertPathBuilderResult.h>
#include <java/security/cert/CertPathChecker.h>
#include <java/security/cert/CertPathParameters.h>
#include <java/security/cert/CertPathValidator.h>
#include <java/security/cert/CertPathValidatorResult.h>
#include <java/security/cert/CertSelector.h>
#include <java/security/cert/CertStore.h>
#include <java/security/cert/CertStoreParameters.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/CertificateFactory.h>
#include <java/security/cert/CollectionCertStoreParameters.h>
#include <java/security/cert/PKIXBuilderParameters.h>
#include <java/security/cert/PKIXCertPathBuilderResult.h>
#include <java/security/cert/PKIXCertPathChecker.h>
#include <java/security/cert/PKIXCertPathValidatorResult.h>
#include <java/security/cert/PKIXRevocationChecker.h>
#include <java/security/cert/TrustAnchor.h>
#include <java/security/cert/X509CertSelector.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/action/GetBooleanAction.h>
#include <sun/security/provider/certpath/AlgorithmChecker.h>
#include <sun/security/provider/certpath/PKIXExtendedParameters.h>
#include <sun/security/util/SecurityProperties.h>
#include <sun/security/validator/Validator.h>
#include <sun/security/validator/ValidatorException.h>
#include <jcpp.h>

#undef ALLOW_NON_CA_ANCHOR
#undef TYPE_PKIX
#undef T_NO_TRUST_ANCHOR
#undef VAR_PLUGIN_CODE_SIGNING
#undef VAR_TLS_CLIENT
#undef VAR_TLS_SERVER

using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $AlgorithmConstraints = ::java::security::AlgorithmConstraints;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PublicKey = ::java::security::PublicKey;
using $Timestamp = ::java::security::Timestamp;
using $CertPath = ::java::security::cert::CertPath;
using $CertPathBuilder = ::java::security::cert::CertPathBuilder;
using $CertPathParameters = ::java::security::cert::CertPathParameters;
using $CertPathValidator = ::java::security::cert::CertPathValidator;
using $CertSelector = ::java::security::cert::CertSelector;
using $CertStore = ::java::security::cert::CertStore;
using $CertStoreParameters = ::java::security::cert::CertStoreParameters;
using $CertificateException = ::java::security::cert::CertificateException;
using $CertificateFactory = ::java::security::cert::CertificateFactory;
using $CollectionCertStoreParameters = ::java::security::cert::CollectionCertStoreParameters;
using $PKIXBuilderParameters = ::java::security::cert::PKIXBuilderParameters;
using $PKIXCertPathBuilderResult = ::java::security::cert::PKIXCertPathBuilderResult;
using $PKIXCertPathChecker = ::java::security::cert::PKIXCertPathChecker;
using $PKIXCertPathValidatorResult = ::java::security::cert::PKIXCertPathValidatorResult;
using $PKIXRevocationChecker = ::java::security::cert::PKIXRevocationChecker;
using $TrustAnchor = ::java::security::cert::TrustAnchor;
using $X509CertSelector = ::java::security::cert::X509CertSelector;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $GetBooleanAction = ::sun::security::action::GetBooleanAction;
using $AlgorithmChecker = ::sun::security::provider::certpath::AlgorithmChecker;
using $PKIXExtendedParameters = ::sun::security::provider::certpath::PKIXExtendedParameters;
using $SecurityProperties = ::sun::security::util::SecurityProperties;
using $Validator = ::sun::security::validator::Validator;
using $ValidatorException = ::sun::security::validator::ValidatorException;

namespace sun {
	namespace security {
		namespace validator {

$FieldInfo _PKIXValidator_FieldInfo_[] = {
	{"checkTLSRevocation", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKIXValidator, checkTLSRevocation)},
	{"ALLOW_NON_CA_ANCHOR", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKIXValidator, ALLOW_NON_CA_ANCHOR)},
	{"trustedCerts", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/cert/X509Certificate;>;", $PRIVATE | $FINAL, $field(PKIXValidator, trustedCerts)},
	{"parameterTemplate", "Ljava/security/cert/PKIXBuilderParameters;", nullptr, $PRIVATE | $FINAL, $field(PKIXValidator, parameterTemplate)},
	{"certPathLength", "I", nullptr, $PRIVATE, $field(PKIXValidator, certPathLength)},
	{"trustedSubjects", "Ljava/util/Map;", "Ljava/util/Map<Ljavax/security/auth/x500/X500Principal;Ljava/util/List<Ljava/security/PublicKey;>;>;", $PRIVATE | $FINAL, $field(PKIXValidator, trustedSubjects)},
	{"factory", "Ljava/security/cert/CertificateFactory;", nullptr, $PRIVATE | $FINAL, $field(PKIXValidator, factory)},
	{"plugin", "Z", nullptr, $PRIVATE | $FINAL, $field(PKIXValidator, plugin)},
	{}
};

$MethodInfo _PKIXValidator_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/util/Collection;)V", "(Ljava/lang/String;Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;)V", 0, $method(PKIXValidator, init$, void, $String*, $Collection*)},
	{"<init>", "(Ljava/lang/String;Ljava/security/cert/PKIXBuilderParameters;)V", nullptr, 0, $method(PKIXValidator, init$, void, $String*, $PKIXBuilderParameters*)},
	{"addResponses", "(Ljava/security/cert/PKIXBuilderParameters;[Ljava/security/cert/X509Certificate;Ljava/util/List;)V", "(Ljava/security/cert/PKIXBuilderParameters;[Ljava/security/cert/X509Certificate;Ljava/util/List<[B>;)V", $PRIVATE | $STATIC, $staticMethod(PKIXValidator, addResponses, void, $PKIXBuilderParameters*, $X509CertificateArray*, $List*)},
	{"allowNonCaAnchor", "()Z", nullptr, $PRIVATE | $STATIC, $staticMethod(PKIXValidator, allowNonCaAnchor, bool)},
	{"doBuild", "([Ljava/security/cert/X509Certificate;Ljava/util/Collection;Ljava/security/cert/PKIXBuilderParameters;)[Ljava/security/cert/X509Certificate;", "([Ljava/security/cert/X509Certificate;Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;Ljava/security/cert/PKIXBuilderParameters;)[Ljava/security/cert/X509Certificate;", $PRIVATE, $method(PKIXValidator, doBuild, $X509CertificateArray*, $X509CertificateArray*, $Collection*, $PKIXBuilderParameters*), "java.security.cert.CertificateException"},
	{"doValidate", "([Ljava/security/cert/X509Certificate;Ljava/security/cert/PKIXBuilderParameters;)[Ljava/security/cert/X509Certificate;", nullptr, $PRIVATE, $method(PKIXValidator, doValidate, $X509CertificateArray*, $X509CertificateArray*, $PKIXBuilderParameters*), "java.security.cert.CertificateException"},
	{"engineValidate", "([Ljava/security/cert/X509Certificate;Ljava/util/Collection;Ljava/util/List;Ljava/security/AlgorithmConstraints;Ljava/lang/Object;)[Ljava/security/cert/X509Certificate;", "([Ljava/security/cert/X509Certificate;Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;Ljava/util/List<[B>;Ljava/security/AlgorithmConstraints;Ljava/lang/Object;)[Ljava/security/cert/X509Certificate;", 0, $virtualMethod(PKIXValidator, engineValidate, $X509CertificateArray*, $X509CertificateArray*, $Collection*, $List*, $AlgorithmConstraints*, Object$*), "java.security.cert.CertificateException"},
	{"getCertPathLength", "()I", nullptr, $PUBLIC, $method(PKIXValidator, getCertPathLength, int32_t)},
	{"getParameters", "()Ljava/security/cert/PKIXBuilderParameters;", nullptr, $PUBLIC, $method(PKIXValidator, getParameters, $PKIXBuilderParameters*)},
	{"getTrustedCertificates", "()Ljava/util/Collection;", "()Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;", $PUBLIC, $virtualMethod(PKIXValidator, getTrustedCertificates, $Collection*)},
	{"isSignatureValid", "(Ljava/util/List;Ljava/security/cert/X509Certificate;)Z", "(Ljava/util/List<Ljava/security/PublicKey;>;Ljava/security/cert/X509Certificate;)Z", $PRIVATE, $method(PKIXValidator, isSignatureValid, bool, $List*, $X509Certificate*)},
	{"setDate", "(Ljava/security/cert/PKIXBuilderParameters;)V", nullptr, $PRIVATE, $method(PKIXValidator, setDate, void, $PKIXBuilderParameters*)},
	{"setDefaultParameters", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(PKIXValidator, setDefaultParameters, void, $String*)},
	{"setTrustedSubjects", "()Ljava/util/Map;", "()Ljava/util/Map<Ljavax/security/auth/x500/X500Principal;Ljava/util/List<Ljava/security/PublicKey;>;>;", $PRIVATE, $method(PKIXValidator, setTrustedSubjects, $Map*)},
	{"toArray", "(Ljava/security/cert/CertPath;Ljava/security/cert/TrustAnchor;)[Ljava/security/cert/X509Certificate;", nullptr, $PRIVATE | $STATIC, $staticMethod(PKIXValidator, toArray, $X509CertificateArray*, $CertPath*, $TrustAnchor*), "java.security.cert.CertificateException"},
	{"verifyTrustAnchor", "(Ljava/security/cert/X509Certificate;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(PKIXValidator, verifyTrustAnchor, void, $X509Certificate*), "sun.security.validator.ValidatorException"},
	{}
};

$ClassInfo _PKIXValidator_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.validator.PKIXValidator",
	"sun.security.validator.Validator",
	nullptr,
	_PKIXValidator_FieldInfo_,
	_PKIXValidator_MethodInfo_
};

$Object* allocate$PKIXValidator($Class* clazz) {
	return $of($alloc(PKIXValidator));
}

bool PKIXValidator::checkTLSRevocation = false;
bool PKIXValidator::ALLOW_NON_CA_ANCHOR = false;

bool PKIXValidator::allowNonCaAnchor() {
	$init(PKIXValidator);
	$var($String, prop, $SecurityProperties::privilegedGetOverridable("jdk.security.allowNonCaAnchor"_s));
	bool var$0 = prop != nullptr;
	if (var$0) {
		bool var$1 = prop->isEmpty();
		var$0 = (var$1 || prop->equalsIgnoreCase("true"_s));
	}
	return var$0;
}

void PKIXValidator::init$($String* variant, $Collection* trustedCerts) {
	$useLocalCurrentObjectStackCache();
	$init($Validator);
	$Validator::init$($Validator::TYPE_PKIX, variant);
	this->certPathLength = -1;
	$set(this, trustedCerts, ($instanceOf($Set, trustedCerts)) ? $cast($Set, trustedCerts) : static_cast<$Set*>($new($HashSet, trustedCerts)));
	$var($Set, trustAnchors, $new($HashSet));
	{
		$var($Iterator, i$, $nc(trustedCerts)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($X509Certificate, cert, $cast($X509Certificate, i$->next()));
			{
				trustAnchors->add($$new($TrustAnchor, cert, nullptr));
			}
		}
	}
	try {
		$set(this, parameterTemplate, $new($PKIXBuilderParameters, trustAnchors, ($CertSelector*)nullptr));
		$set(this, factory, $CertificateFactory::getInstance("X.509"_s));
	} catch ($InvalidAlgorithmParameterException& e) {
		$throwNew($RuntimeException, $$str({"Unexpected error: "_s, $(e->toString())}), e);
	} catch ($CertificateException& e) {
		$throwNew($RuntimeException, "Internal error"_s, e);
	}
	setDefaultParameters(variant);
	this->plugin = $nc(variant)->equals($Validator::VAR_PLUGIN_CODE_SIGNING);
	$set(this, trustedSubjects, setTrustedSubjects());
}

void PKIXValidator::init$($String* variant, $PKIXBuilderParameters* params) {
	$useLocalCurrentObjectStackCache();
	$init($Validator);
	$Validator::init$($Validator::TYPE_PKIX, variant);
	this->certPathLength = -1;
	$set(this, trustedCerts, $new($HashSet));
	{
		$var($Iterator, i$, $nc($($nc(params)->getTrustAnchors()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($TrustAnchor, anchor, $cast($TrustAnchor, i$->next()));
			{
				$var($X509Certificate, cert, $nc(anchor)->getTrustedCert());
				if (cert != nullptr) {
					$nc(this->trustedCerts)->add(cert);
				}
			}
		}
	}
	$set(this, parameterTemplate, params);
	try {
		$set(this, factory, $CertificateFactory::getInstance("X.509"_s));
	} catch ($CertificateException& e) {
		$throwNew($RuntimeException, "Internal error"_s, e);
	}
	this->plugin = $nc(variant)->equals($Validator::VAR_PLUGIN_CODE_SIGNING);
	$set(this, trustedSubjects, setTrustedSubjects());
}

$Map* PKIXValidator::setTrustedSubjects() {
	$useLocalCurrentObjectStackCache();
	$var($Map, subjectMap, $new($HashMap));
	{
		$var($Iterator, i$, $nc(this->trustedCerts)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($X509Certificate, cert, $cast($X509Certificate, i$->next()));
			{
				$var($X500Principal, dn, $nc(cert)->getSubjectX500Principal());
				$var($List, keys, nullptr);
				if (subjectMap->containsKey(dn)) {
					$assign(keys, $cast($List, subjectMap->get(dn)));
				} else {
					$assign(keys, $new($ArrayList));
					subjectMap->put(dn, keys);
				}
				$nc(keys)->add($(cert->getPublicKey()));
			}
		}
	}
	return subjectMap;
}

$Collection* PKIXValidator::getTrustedCertificates() {
	return this->trustedCerts;
}

int32_t PKIXValidator::getCertPathLength() {
	return this->certPathLength;
}

void PKIXValidator::setDefaultParameters($String* variant) {
	$init($Validator);
	if ((variant == $Validator::VAR_TLS_SERVER) || (variant == $Validator::VAR_TLS_CLIENT)) {
		$nc(this->parameterTemplate)->setRevocationEnabled(PKIXValidator::checkTLSRevocation);
	} else {
		$nc(this->parameterTemplate)->setRevocationEnabled(false);
	}
}

$PKIXBuilderParameters* PKIXValidator::getParameters() {
	return this->parameterTemplate;
}

$X509CertificateArray* PKIXValidator::engineValidate($X509CertificateArray* chain, $Collection* otherCerts, $List* responseList, $AlgorithmConstraints* constraints, Object$* parameter) {
	$useLocalCurrentObjectStackCache();
	if ((chain == nullptr) || ($nc(chain)->length == 0)) {
		$throwNew($CertificateException, "null or zero-length certificate chain"_s);
	}
	$var($PKIXBuilderParameters, pkixParameters, nullptr);
	try {
		$assign(pkixParameters, $new($PKIXExtendedParameters, $cast($PKIXBuilderParameters, $($nc(this->parameterTemplate)->clone())), ($instanceOf($Timestamp, parameter)) ? $cast($Timestamp, parameter) : ($Timestamp*)nullptr, this->variant));
	} catch ($InvalidAlgorithmParameterException& e) {
	}
	if (constraints != nullptr) {
		$nc(pkixParameters)->addCertPathChecker($$new($AlgorithmChecker, constraints, this->variant));
	}
	if (!$nc(responseList)->isEmpty()) {
		addResponses(pkixParameters, chain, responseList);
	}
	$var($X500Principal, prevIssuer, nullptr);
	for (int32_t i = 0; i < $nc(chain)->length; ++i) {
		$var($X509Certificate, cert, chain->get(i));
		$var($X500Principal, dn, $nc(cert)->getSubjectX500Principal());
		if (i == 0) {
			if ($nc(this->trustedCerts)->contains(cert)) {
				return $new($X509CertificateArray, {chain->get(0)});
			}
		} else {
			if (!$nc(dn)->equals(prevIssuer)) {
				return doBuild(chain, otherCerts, pkixParameters);
			}
			bool var$0 = $nc(this->trustedCerts)->contains(cert);
			if (!var$0) {
				bool var$1 = $nc(this->trustedSubjects)->containsKey(dn);
				var$0 = (var$1 && $nc(($cast($List, $($nc(this->trustedSubjects)->get(dn)))))->contains($(cert->getPublicKey())));
			}
			if (var$0) {
				$var($X509CertificateArray, newChain, $new($X509CertificateArray, i));
				$System::arraycopy(chain, 0, newChain, 0, i);
				return doValidate(newChain, pkixParameters);
			}
		}
		$assign(prevIssuer, cert->getIssuerX500Principal());
	}
	$var($X509Certificate, last, $nc(chain)->get(chain->length - 1));
	$var($X500Principal, issuer, $nc(last)->getIssuerX500Principal());
	$var($X500Principal, subject, last->getSubjectX500Principal());
	bool var$2 = $nc(this->trustedSubjects)->containsKey(issuer);
	if (var$2 && isSignatureValid($cast($List, $($nc(this->trustedSubjects)->get(issuer))), last)) {
		return doValidate(chain, pkixParameters);
	}
	if (this->plugin) {
		if (chain->length > 1) {
			$var($X509CertificateArray, newChain, $new($X509CertificateArray, chain->length - 1));
			$System::arraycopy(chain, 0, newChain, 0, newChain->length);
			try {
				$nc(pkixParameters)->setTrustAnchors($($Collections::singleton($$new($TrustAnchor, chain->get(chain->length - 1), nullptr))));
			} catch ($InvalidAlgorithmParameterException& iape) {
				$throwNew($CertificateException, static_cast<$Throwable*>(iape));
			}
			doValidate(newChain, pkixParameters);
		}
		$init($ValidatorException);
		$throwNew($ValidatorException, $ValidatorException::T_NO_TRUST_ANCHOR);
	}
	return doBuild(chain, otherCerts, pkixParameters);
}

bool PKIXValidator::isSignatureValid($List* keys, $X509Certificate* sub) {
	$useLocalCurrentObjectStackCache();
	if (this->plugin) {
		{
			$var($Iterator, i$, $nc(keys)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($PublicKey, key, $cast($PublicKey, i$->next()));
				{
					try {
						$nc(sub)->verify(key);
						return true;
					} catch ($Exception& ex) {
						continue;
					}
				}
			}
		}
		return false;
	}
	return true;
}

$X509CertificateArray* PKIXValidator::toArray($CertPath* path, $TrustAnchor* anchor) {
	$init(PKIXValidator);
	$useLocalCurrentObjectStackCache();
	$var($X509Certificate, trustedCert, $nc(anchor)->getTrustedCert());
	if (trustedCert == nullptr) {
		$throwNew($ValidatorException, "TrustAnchor must be specified as certificate"_s);
	}
	verifyTrustAnchor(trustedCert);
	$var($List, list, $nc(path)->getCertificates());
	$var($X509CertificateArray, chain, $new($X509CertificateArray, $nc(list)->size() + 1));
	list->toArray(chain);
	chain->set(chain->length - 1, trustedCert);
	return chain;
}

void PKIXValidator::setDate($PKIXBuilderParameters* params) {
	$var($Date, date, this->validationDate);
	if (date != nullptr) {
		$nc(params)->setDate(date);
	}
}

$X509CertificateArray* PKIXValidator::doValidate($X509CertificateArray* chain, $PKIXBuilderParameters* params) {
	$useLocalCurrentObjectStackCache();
	try {
		setDate(params);
		$var($CertPathValidator, validator, $CertPathValidator::getInstance("PKIX"_s));
		$var($CertPath, path, $nc(this->factory)->generateCertPath($($Arrays::asList(chain))));
		this->certPathLength = $nc(chain)->length;
		$var($PKIXCertPathValidatorResult, result, $cast($PKIXCertPathValidatorResult, $nc(validator)->validate(path, params)));
		return toArray(path, $($nc(result)->getTrustAnchor()));
	} catch ($GeneralSecurityException& e) {
		$throwNew($ValidatorException, $$str({"PKIX path validation failed: "_s, $(e->toString())}), static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

void PKIXValidator::verifyTrustAnchor($X509Certificate* trustedCert) {
	$init(PKIXValidator);
	$useLocalCurrentObjectStackCache();
	if (PKIXValidator::ALLOW_NON_CA_ANCHOR) {
		return;
	}
	if ($nc(trustedCert)->getVersion() < 3) {
		return;
	}
	if ($nc(trustedCert)->getBasicConstraints() == -1) {
		$throwNew($ValidatorException, $$str({"TrustAnchor with subject \""_s, $(trustedCert->getSubjectX500Principal()), "\" is not a CA certificate"_s}));
	}
	$var($booleans, keyUsageBits, $nc(trustedCert)->getKeyUsage());
	if (keyUsageBits != nullptr && !keyUsageBits->get(5)) {
		$throwNew($ValidatorException, $$str({"TrustAnchor with subject \""_s, $(trustedCert->getSubjectX500Principal()), "\" does not have keyCertSign bit set in KeyUsage extension"_s}));
	}
}

$X509CertificateArray* PKIXValidator::doBuild($X509CertificateArray* chain, $Collection* otherCerts, $PKIXBuilderParameters* params) {
	$useLocalCurrentObjectStackCache();
	try {
		setDate(params);
		$var($X509CertSelector, selector, $new($X509CertSelector));
		selector->setCertificate($nc(chain)->get(0));
		$nc(params)->setTargetCertConstraints(selector);
		$var($Collection, certs, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>($new($ArrayList)))));
		certs->addAll($($Arrays::asList(chain)));
		if (otherCerts != nullptr) {
			certs->addAll(otherCerts);
		}
		$var($CertStore, store, $CertStore::getInstance("Collection"_s, $$new($CollectionCertStoreParameters, certs)));
		params->addCertStore(store);
		$var($CertPathBuilder, builder, $CertPathBuilder::getInstance("PKIX"_s));
		$var($PKIXCertPathBuilderResult, result, $cast($PKIXCertPathBuilderResult, $nc(builder)->build(params)));
		$var($CertPath, var$0, $nc(result)->getCertPath());
		return toArray(var$0, $(result->getTrustAnchor()));
	} catch ($GeneralSecurityException& e) {
		$throwNew($ValidatorException, $$str({"PKIX path building failed: "_s, $(e->toString())}), static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

void PKIXValidator::addResponses($PKIXBuilderParameters* pkixParams, $X509CertificateArray* chain, $List* responseList) {
	$init(PKIXValidator);
	$useLocalCurrentObjectStackCache();
	try {
		bool createdRevChk = false;
		$var($PKIXRevocationChecker, revChecker, nullptr);
		$var($List, checkerList, $nc(pkixParams)->getCertPathCheckers());
		{
			$var($Iterator, i$, $nc(checkerList)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($PKIXCertPathChecker, checker, $cast($PKIXCertPathChecker, i$->next()));
				{
					if ($instanceOf($PKIXRevocationChecker, checker)) {
						$assign(revChecker, $cast($PKIXRevocationChecker, checker));
						break;
					}
				}
			}
		}
		if (revChecker == nullptr) {
			if (pkixParams->isRevocationEnabled()) {
				$assign(revChecker, $cast($PKIXRevocationChecker, $nc($($CertPathValidator::getInstance("PKIX"_s)))->getRevocationChecker()));
				createdRevChk = true;
			} else {
				return;
			}
		}
		$var($Map, responseMap, $nc(revChecker)->getOcspResponses());
		int32_t limit = $Integer::min($nc(chain)->length, $nc(responseList)->size());
		for (int32_t idx = 0; idx < limit; ++idx) {
			$var($bytes, respBytes, $cast($bytes, $nc(responseList)->get(idx)));
			if (respBytes != nullptr && respBytes->length > 0 && !$nc(responseMap)->containsKey($nc(chain)->get(idx))) {
				responseMap->put($nc(chain)->get(idx), respBytes);
			}
		}
		revChecker->setOcspResponses(responseMap);
		if (createdRevChk) {
			pkixParams->addCertPathChecker(revChecker);
		} else {
			pkixParams->setCertPathCheckers(checkerList);
		}
	} catch ($NoSuchAlgorithmException& exc) {
	}
}

void clinit$PKIXValidator($Class* class$) {
	PKIXValidator::checkTLSRevocation = $GetBooleanAction::privilegedGetProperty("com.sun.net.ssl.checkRevocation"_s);
	PKIXValidator::ALLOW_NON_CA_ANCHOR = PKIXValidator::allowNonCaAnchor();
}

PKIXValidator::PKIXValidator() {
}

$Class* PKIXValidator::load$($String* name, bool initialize) {
	$loadClass(PKIXValidator, name, initialize, &_PKIXValidator_ClassInfo_, clinit$PKIXValidator, allocate$PKIXValidator);
	return class$;
}

$Class* PKIXValidator::class$ = nullptr;

		} // validator
	} // security
} // sun