#include <sun/security/util/JarConstraintsParameters.h>

#include <java/security/CodeSigner.h>
#include <java/security/Key.h>
#include <java/security/PublicKey.h>
#include <java/security/Timestamp.h>
#include <java/security/cert/CertPath.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/Date.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/util/AnchorCertificates.h>
#include <sun/security/validator/Validator.h>
#include <jcpp.h>

#undef VAR_GENERIC

using $CodeSignerArray = $Array<::java::security::CodeSigner>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CodeSigner = ::java::security::CodeSigner;
using $Key = ::java::security::Key;
using $Timestamp = ::java::security::Timestamp;
using $CertPath = ::java::security::cert::CertPath;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $Date = ::java::util::Date;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $AnchorCertificates = ::sun::security::util::AnchorCertificates;
using $Validator = ::sun::security::validator::Validator;

namespace sun {
	namespace security {
		namespace util {

$FieldInfo _JarConstraintsParameters_FieldInfo_[] = {
	{"anchorIsJdkCA", "Z", nullptr, $PRIVATE, $field(JarConstraintsParameters, anchorIsJdkCA$)},
	{"anchorIsJdkCASet", "Z", nullptr, $PRIVATE, $field(JarConstraintsParameters, anchorIsJdkCASet)},
	{"timestamp", "Ljava/util/Date;", nullptr, $PRIVATE, $field(JarConstraintsParameters, timestamp)},
	{"keys", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/Key;>;", $PRIVATE | $FINAL, $field(JarConstraintsParameters, keys)},
	{"certsIssuedByAnchor", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/cert/X509Certificate;>;", $PRIVATE | $FINAL, $field(JarConstraintsParameters, certsIssuedByAnchor)},
	{"message", "Ljava/lang/String;", nullptr, $PRIVATE, $field(JarConstraintsParameters, message)},
	{}
};

$MethodInfo _JarConstraintsParameters_MethodInfo_[] = {
	{"<init>", "([Ljava/security/CodeSigner;)V", nullptr, $PUBLIC, $method(JarConstraintsParameters, init$, void, $CodeSignerArray*)},
	{"anchorIsJdkCA", "()Z", nullptr, $PUBLIC, $virtualMethod(JarConstraintsParameters, anchorIsJdkCA, bool)},
	{"extendedExceptionMsg", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(JarConstraintsParameters, extendedExceptionMsg, $String*)},
	{"getDate", "()Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(JarConstraintsParameters, getDate, $Date*)},
	{"getKeys", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/security/Key;>;", $PUBLIC, $virtualMethod(JarConstraintsParameters, getKeys, $Set*)},
	{"getVariant", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(JarConstraintsParameters, getVariant, $String*)},
	{"init", "(Ljava/security/cert/CertPath;)V", nullptr, $PRIVATE, $method(JarConstraintsParameters, init, void, $CertPath*)},
	{"setExtendedExceptionMsg", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(JarConstraintsParameters, setExtendedExceptionMsg, void, $String*, $String*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(JarConstraintsParameters, toString, $String*)},
	{}
};

$ClassInfo _JarConstraintsParameters_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.util.JarConstraintsParameters",
	"java.lang.Object",
	"sun.security.util.ConstraintsParameters",
	_JarConstraintsParameters_FieldInfo_,
	_JarConstraintsParameters_MethodInfo_
};

$Object* allocate$JarConstraintsParameters($Class* clazz) {
	return $of($alloc(JarConstraintsParameters));
}

void JarConstraintsParameters::init$($CodeSignerArray* signers) {
	$useLocalCurrentObjectStackCache();
	$set(this, keys, $new($HashSet));
	$set(this, certsIssuedByAnchor, $new($HashSet));
	$var($Date, latestTimestamp, nullptr);
	bool skipTimestamp = false;
	{
		$var($CodeSignerArray, arr$, signers);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($CodeSigner, signer, arr$->get(i$));
			{
				init($($nc(signer)->getSignerCertPath()));
				$var($Timestamp, timestamp, $nc(signer)->getTimestamp());
				if (timestamp == nullptr) {
					$assign(latestTimestamp, nullptr);
					skipTimestamp = true;
				} else {
					init($($nc(timestamp)->getSignerCertPath()));
					if (!skipTimestamp) {
						$var($Date, timestampDate, $nc(timestamp)->getTimestamp());
						if (latestTimestamp == nullptr) {
							$assign(latestTimestamp, timestampDate);
						} else if ($nc(latestTimestamp)->before(timestampDate)) {
							$assign(latestTimestamp, timestampDate);
						}
					}
				}
			}
		}
	}
	$set(this, timestamp, latestTimestamp);
}

void JarConstraintsParameters::init($CertPath* cp) {
	$useLocalCurrentObjectStackCache();
	$var($List, chain, $nc(cp)->getCertificates());
	if (!$nc(chain)->isEmpty()) {
		$nc(this->certsIssuedByAnchor)->add($cast($X509Certificate, $(chain->get(chain->size() - 1))));
		$nc(this->keys)->add($($nc(($cast($X509Certificate, $(chain->get(0)))))->getPublicKey()));
	}
}

$String* JarConstraintsParameters::getVariant() {
	$init($Validator);
	return $Validator::VAR_GENERIC;
}

bool JarConstraintsParameters::anchorIsJdkCA() {
	$useLocalCurrentObjectStackCache();
	if (this->anchorIsJdkCASet) {
		return this->anchorIsJdkCA$;
	}
	{
		$var($Iterator, i$, $nc(this->certsIssuedByAnchor)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($X509Certificate, cert, $cast($X509Certificate, i$->next()));
			{
				if ($AnchorCertificates::issuerOf(cert)) {
					this->anchorIsJdkCA$ = true;
					break;
				}
			}
		}
	}
	this->anchorIsJdkCASet = true;
	return this->anchorIsJdkCA$;
}

$Date* JarConstraintsParameters::getDate() {
	return this->timestamp;
}

$Set* JarConstraintsParameters::getKeys() {
	return this->keys;
}

void JarConstraintsParameters::setExtendedExceptionMsg($String* file, $String* target) {
	$set(this, message, $str({" used"_s, (target != nullptr ? $$str({" with "_s, target}) : ""_s), " in "_s, file, " file."_s}));
}

$String* JarConstraintsParameters::extendedExceptionMsg() {
	return this->message;
}

$String* JarConstraintsParameters::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder, "[\n"_s));
	sb->append("\n  Variant: "_s)->append($(getVariant()));
	sb->append("\n  Certs Issued by Anchor:"_s);
	{
		$var($Iterator, i$, $nc(this->certsIssuedByAnchor)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($X509Certificate, cert, $cast($X509Certificate, i$->next()));
			{
				sb->append("\n    Cert Issuer: "_s)->append($($of($nc(cert)->getIssuerX500Principal())));
				sb->append("\n    Cert Subject: "_s)->append($($of($nc(cert)->getSubjectX500Principal())));
			}
		}
	}
	{
		$var($Iterator, i$, $nc(this->keys)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Key, key, $cast($Key, i$->next()));
			{
				sb->append("\n  Key: "_s)->append($($nc(key)->getAlgorithm()));
			}
		}
	}
	if (this->timestamp != nullptr) {
		sb->append("\n  Timestamp: "_s)->append($of(this->timestamp));
	}
	sb->append("\n]"_s);
	return sb->toString();
}

JarConstraintsParameters::JarConstraintsParameters() {
}

$Class* JarConstraintsParameters::load$($String* name, bool initialize) {
	$loadClass(JarConstraintsParameters, name, initialize, &_JarConstraintsParameters_ClassInfo_, allocate$JarConstraintsParameters);
	return class$;
}

$Class* JarConstraintsParameters::class$ = nullptr;

		} // util
	} // security
} // sun