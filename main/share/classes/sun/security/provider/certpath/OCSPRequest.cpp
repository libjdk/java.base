#include <sun/security/provider/certpath/OCSPRequest.h>

#include <java/io/OutputStream.h>
#include <java/security/cert/Extension.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <sun/security/provider/certpath/CertId.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/PKIXExtensions.h>
#include <jcpp.h>

#undef TAG_CONTEXT

using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Extension = ::java::security::cert::Extension;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $CertId = ::sun::security::provider::certpath::CertId;
using $Debug = ::sun::security::util::Debug;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $PKIXExtensions = ::sun::security::x509::PKIXExtensions;

namespace sun {
	namespace security {
		namespace provider {
			namespace certpath {

$FieldInfo _OCSPRequest_FieldInfo_[] = {
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OCSPRequest, debug)},
	{"dump", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OCSPRequest, dump)},
	{"certIds", "Ljava/util/List;", "Ljava/util/List<Lsun/security/provider/certpath/CertId;>;", $PRIVATE | $FINAL, $field(OCSPRequest, certIds)},
	{"extensions", "Ljava/util/List;", "Ljava/util/List<Ljava/security/cert/Extension;>;", $PRIVATE | $FINAL, $field(OCSPRequest, extensions)},
	{"nonce", "[B", nullptr, $PRIVATE, $field(OCSPRequest, nonce)},
	{}
};

$MethodInfo _OCSPRequest_MethodInfo_[] = {
	{"<init>", "(Lsun/security/provider/certpath/CertId;)V", nullptr, 0, $method(OCSPRequest, init$, void, $CertId*)},
	{"<init>", "(Ljava/util/List;)V", "(Ljava/util/List<Lsun/security/provider/certpath/CertId;>;)V", 0, $method(OCSPRequest, init$, void, $List*)},
	{"<init>", "(Ljava/util/List;Ljava/util/List;)V", "(Ljava/util/List<Lsun/security/provider/certpath/CertId;>;Ljava/util/List<Ljava/security/cert/Extension;>;)V", 0, $method(OCSPRequest, init$, void, $List*, $List*)},
	{"encodeBytes", "()[B", nullptr, 0, $virtualMethod(OCSPRequest, encodeBytes, $bytes*), "java.io.IOException"},
	{"getCertIds", "()Ljava/util/List;", "()Ljava/util/List<Lsun/security/provider/certpath/CertId;>;", 0, $virtualMethod(OCSPRequest, getCertIds, $List*)},
	{"getNonce", "()[B", nullptr, 0, $virtualMethod(OCSPRequest, getNonce, $bytes*)},
	{}
};

$ClassInfo _OCSPRequest_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.provider.certpath.OCSPRequest",
	"java.lang.Object",
	nullptr,
	_OCSPRequest_FieldInfo_,
	_OCSPRequest_MethodInfo_
};

$Object* allocate$OCSPRequest($Class* clazz) {
	return $of($alloc(OCSPRequest));
}

$Debug* OCSPRequest::debug = nullptr;
bool OCSPRequest::dump = false;

void OCSPRequest::init$($CertId* certId) {
	OCSPRequest::init$($($Collections::singletonList(certId)));
}

void OCSPRequest::init$($List* certIds) {
	$set(this, certIds, certIds);
	$set(this, extensions, $Collections::emptyList());
}

void OCSPRequest::init$($List* certIds, $List* extensions) {
	$set(this, certIds, certIds);
	$set(this, extensions, extensions);
}

$bytes* OCSPRequest::encodeBytes() {
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, tmp, $new($DerOutputStream));
	$var($DerOutputStream, requestsOut, $new($DerOutputStream));
	{
		$var($Iterator, i$, $nc(this->certIds)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($CertId, certId, $cast($CertId, i$->next()));
			{
				$var($DerOutputStream, certIdOut, $new($DerOutputStream));
				$nc(certId)->encode(certIdOut);
				requestsOut->write($DerValue::tag_Sequence, certIdOut);
			}
		}
	}
	tmp->write($DerValue::tag_Sequence, requestsOut);
	if (!$nc(this->extensions)->isEmpty()) {
		$var($DerOutputStream, extOut, $new($DerOutputStream));
		{
			$var($Iterator, i$, $nc(this->extensions)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Extension, ext, $cast($Extension, i$->next()));
				{
					$nc(ext)->encode(extOut);
					$init($PKIXExtensions);
					if ($nc($(ext->getId()))->equals($($nc($PKIXExtensions::OCSPNonce_Id)->toString()))) {
						$set(this, nonce, ext->getValue());
					}
				}
			}
		}
		$var($DerOutputStream, extsOut, $new($DerOutputStream));
		extsOut->write($DerValue::tag_Sequence, extOut);
		tmp->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2), extsOut);
	}
	$var($DerOutputStream, tbsRequest, $new($DerOutputStream));
	tbsRequest->write($DerValue::tag_Sequence, tmp);
	$var($DerOutputStream, ocspRequest, $new($DerOutputStream));
	ocspRequest->write($DerValue::tag_Sequence, tbsRequest);
	$var($bytes, bytes, ocspRequest->toByteArray());
	if (OCSPRequest::dump) {
		$var($HexDumpEncoder, hexEnc, $new($HexDumpEncoder));
		$nc(OCSPRequest::debug)->println($$str({"OCSPRequest bytes...\n\n"_s, $(hexEnc->encode(bytes)), "\n"_s}));
	}
	return bytes;
}

$List* OCSPRequest::getCertIds() {
	return this->certIds;
}

$bytes* OCSPRequest::getNonce() {
	return this->nonce;
}

void clinit$OCSPRequest($Class* class$) {
	$assignStatic(OCSPRequest::debug, $Debug::getInstance("certpath"_s));
	OCSPRequest::dump = OCSPRequest::debug != nullptr && $Debug::isOn("ocsp"_s);
}

OCSPRequest::OCSPRequest() {
}

$Class* OCSPRequest::load$($String* name, bool initialize) {
	$loadClass(OCSPRequest, name, initialize, &_OCSPRequest_ClassInfo_, clinit$OCSPRequest, allocate$OCSPRequest);
	return class$;
}

$Class* OCSPRequest::class$ = nullptr;

			} // certpath
		} // provider
	} // security
} // sun