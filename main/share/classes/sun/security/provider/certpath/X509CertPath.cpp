#include <sun/security/provider/certpath/X509CertPath.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/security/cert/CertPath.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateEncodingException.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/CertificateFactory.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/ListIterator.h>
#include <sun/security/pkcs/ContentInfo.h>
#include <sun/security/pkcs/PKCS7.h>
#include <sun/security/pkcs/SignerInfo.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/AlgorithmId.h>
#include <jcpp.h>

#undef COUNT_ENCODING
#undef DATA_OID
#undef PKCS7_ENCODING
#undef PKIPATH_ENCODING

using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $SignerInfoArray = $Array<::sun::security::pkcs::SignerInfo>;
using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $AlgorithmIdArray = $Array<::sun::security::x509::AlgorithmId>;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CertPath = ::java::security::cert::CertPath;
using $CertificateEncodingException = ::java::security::cert::CertificateEncodingException;
using $CertificateException = ::java::security::cert::CertificateException;
using $CertificateFactory = ::java::security::cert::CertificateFactory;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $ListIterator = ::java::util::ListIterator;
using $ContentInfo = ::sun::security::pkcs::ContentInfo;
using $PKCS7 = ::sun::security::pkcs::PKCS7;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace provider {
			namespace certpath {

$FieldInfo _X509CertPath_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(X509CertPath, serialVersionUID)},
	{"certs", "Ljava/util/List;", "Ljava/util/List<Ljava/security/cert/X509Certificate;>;", $PRIVATE, $field(X509CertPath, certs)},
	{"COUNT_ENCODING", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(X509CertPath, COUNT_ENCODING)},
	{"PKCS7_ENCODING", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(X509CertPath, PKCS7_ENCODING)},
	{"PKIPATH_ENCODING", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(X509CertPath, PKIPATH_ENCODING)},
	{"encodingList", "Ljava/util/Collection;", "Ljava/util/Collection<Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(X509CertPath, encodingList)},
	{}
};

$MethodInfo _X509CertPath_MethodInfo_[] = {
	{"<init>", "(Ljava/util/List;)V", "(Ljava/util/List<+Ljava/security/cert/Certificate;>;)V", $PUBLIC, $method(X509CertPath, init$, void, $List*), "java.security.cert.CertificateException"},
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(X509CertPath, init$, void, $InputStream*), "java.security.cert.CertificateException"},
	{"<init>", "(Ljava/io/InputStream;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(X509CertPath, init$, void, $InputStream*, $String*), "java.security.cert.CertificateException"},
	{"encodePKCS7", "()[B", nullptr, $PRIVATE, $method(X509CertPath, encodePKCS7, $bytes*), "java.security.cert.CertificateEncodingException"},
	{"encodePKIPATH", "()[B", nullptr, $PRIVATE, $method(X509CertPath, encodePKIPATH, $bytes*), "java.security.cert.CertificateEncodingException"},
	{"getCertificates", "()Ljava/util/List;", "()Ljava/util/List<Ljava/security/cert/X509Certificate;>;", $PUBLIC, $virtualMethod(X509CertPath, getCertificates, $List*)},
	{"getEncoded", "()[B", nullptr, $PUBLIC, $virtualMethod(X509CertPath, getEncoded, $bytes*), "java.security.cert.CertificateEncodingException"},
	{"getEncoded", "(Ljava/lang/String;)[B", nullptr, $PUBLIC, $virtualMethod(X509CertPath, getEncoded, $bytes*, $String*), "java.security.cert.CertificateEncodingException"},
	{"getEncodings", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(X509CertPath, getEncodings, $Iterator*)},
	{"getEncodingsStatic", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(X509CertPath, getEncodingsStatic, $Iterator*)},
	{"parsePKCS7", "(Ljava/io/InputStream;)Ljava/util/List;", "(Ljava/io/InputStream;)Ljava/util/List<Ljava/security/cert/X509Certificate;>;", $PRIVATE | $STATIC, $staticMethod(X509CertPath, parsePKCS7, $List*, $InputStream*), "java.security.cert.CertificateException"},
	{"parsePKIPATH", "(Ljava/io/InputStream;)Ljava/util/List;", "(Ljava/io/InputStream;)Ljava/util/List<Ljava/security/cert/X509Certificate;>;", $PRIVATE | $STATIC, $staticMethod(X509CertPath, parsePKIPATH, $List*, $InputStream*), "java.security.cert.CertificateException"},
	{"readAllBytes", "(Ljava/io/InputStream;)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(X509CertPath, readAllBytes, $bytes*, $InputStream*), "java.io.IOException"},
	{}
};

$ClassInfo _X509CertPath_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.provider.certpath.X509CertPath",
	"java.security.cert.CertPath",
	nullptr,
	_X509CertPath_FieldInfo_,
	_X509CertPath_MethodInfo_
};

$Object* allocate$X509CertPath($Class* clazz) {
	return $of($alloc(X509CertPath));
}

$String* X509CertPath::COUNT_ENCODING = nullptr;
$String* X509CertPath::PKCS7_ENCODING = nullptr;
$String* X509CertPath::PKIPATH_ENCODING = nullptr;
$Collection* X509CertPath::encodingList = nullptr;

void X509CertPath::init$($List* certs) {
	$useLocalCurrentObjectStackCache();
	$CertPath::init$("X.509"_s);
	{
		$var($Iterator, i$, $nc(certs)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Object, obj, i$->next());
			{
				if ($instanceOf($X509Certificate, obj) == false) {
					$throwNew($CertificateException, $$str({"List is not all X509Certificates: "_s, $($nc($of(obj))->getClass()->getName())}));
				}
			}
		}
	}
	$set(this, certs, $Collections::unmodifiableList($$new($ArrayList, certs)));
}

void X509CertPath::init$($InputStream* is) {
	X509CertPath::init$(is, X509CertPath::PKIPATH_ENCODING);
}

void X509CertPath::init$($InputStream* is, $String* encoding) {
	$CertPath::init$("X.509"_s);
	{
		$var($String, s6111$, encoding);
		int32_t tmp6111$ = -1;
		switch ($nc(s6111$)->hashCode()) {
		case 0x44768AF3:
			{
				if (s6111$->equals("PkiPath"_s)) {
					tmp6111$ = 0;
				}
				break;
			}
		case 0x048A75EC:
			{
				if (s6111$->equals("PKCS7"_s)) {
					tmp6111$ = 1;
				}
				break;
			}
		}
		switch (tmp6111$) {
		case 0:
			{
				$set(this, certs, parsePKIPATH(is));
				break;
			}
		case 1:
			{
				$set(this, certs, parsePKCS7(is));
				break;
			}
		default:
			{
				$throwNew($CertificateException, "unsupported encoding"_s);
			}
		}
	}
}

$List* X509CertPath::parsePKIPATH($InputStream* is) {
	$init(X509CertPath);
	$useLocalCurrentObjectStackCache();
	$var($List, certList, nullptr);
	$var($CertificateFactory, certFac, nullptr);
	if (is == nullptr) {
		$throwNew($CertificateException, "input stream is null"_s);
	}
	try {
		$var($DerInputStream, dis, $new($DerInputStream, $(readAllBytes(is))));
		$var($DerValueArray, seq, dis->getSequence(3));
		if ($nc(seq)->length == 0) {
			return $Collections::emptyList();
		}
		$assign(certFac, $CertificateFactory::getInstance("X.509"_s));
		$assign(certList, $new($ArrayList, $nc(seq)->length));
		for (int32_t i = $nc(seq)->length - 1; i >= 0; --i) {
			certList->add($cast($X509Certificate, $($nc(certFac)->generateCertificate($$new($ByteArrayInputStream, $($nc(seq->get(i))->toByteArray()))))));
		}
		return $Collections::unmodifiableList(certList);
	} catch ($IOException& ioe) {
		$throwNew($CertificateException, $$str({"IOException parsing PkiPath data: "_s, ioe}), ioe);
	}
	$shouldNotReachHere();
}

$List* X509CertPath::parsePKCS7($InputStream* is$renamed) {
	$init(X509CertPath);
	$useLocalCurrentObjectStackCache();
	$var($InputStream, is, is$renamed);
	$var($List, certList, nullptr);
	if (is == nullptr) {
		$throwNew($CertificateException, "input stream is null"_s);
	}
	try {
		if ($nc(is)->markSupported() == false) {
			$assign(is, $new($ByteArrayInputStream, $(readAllBytes(is))));
		}
		$var($PKCS7, pkcs7, $new($PKCS7, is));
		$var($X509CertificateArray, certArray, pkcs7->getCertificates());
		if (certArray != nullptr) {
			$assign(certList, $Arrays::asList(certArray));
		} else {
			$assign(certList, $new($ArrayList, 0));
		}
	} catch ($IOException& ioe) {
		$throwNew($CertificateException, $$str({"IOException parsing PKCS7 data: "_s, ioe}));
	}
	return $Collections::unmodifiableList(certList);
}

$bytes* X509CertPath::readAllBytes($InputStream* is) {
	$init(X509CertPath);
	$useLocalCurrentObjectStackCache();
	$var($bytes, buffer, $new($bytes, 8192));
	$var($ByteArrayOutputStream, baos, $new($ByteArrayOutputStream, 2048));
	int32_t n = 0;
	while ((n = $nc(is)->read(buffer)) != -1) {
		baos->write(buffer, 0, n);
	}
	return baos->toByteArray();
}

$bytes* X509CertPath::getEncoded() {
	return encodePKIPATH();
}

$bytes* X509CertPath::encodePKIPATH() {
	$useLocalCurrentObjectStackCache();
	$var($ListIterator, li, $nc(this->certs)->listIterator($nc(this->certs)->size()));
	try {
		$var($DerOutputStream, bytes, $new($DerOutputStream));
		while ($nc(li)->hasPrevious()) {
			$var($X509Certificate, cert, $cast($X509Certificate, li->previous()));
			int32_t var$0 = $nc(this->certs)->lastIndexOf(cert);
			if (var$0 != $nc(this->certs)->indexOf(cert)) {
				$throwNew($CertificateEncodingException, "Duplicate Certificate"_s);
			}
			$var($bytes, encoded, $nc(cert)->getEncoded());
			bytes->write(encoded);
		}
		$var($DerOutputStream, derout, $new($DerOutputStream));
		derout->write($DerValue::tag_SequenceOf, bytes);
		return derout->toByteArray();
	} catch ($IOException& ioe) {
		$throwNew($CertificateEncodingException, $$str({"IOException encoding PkiPath data: "_s, ioe}), ioe);
	}
	$shouldNotReachHere();
}

$bytes* X509CertPath::encodePKCS7() {
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmIdArray, var$0, $new($AlgorithmIdArray, 0));
	$init($ContentInfo);
	$var($ContentInfo, var$1, $new($ContentInfo, $ContentInfo::DATA_OID, ($DerValue*)nullptr));
	$var($PKCS7, p7, $new($PKCS7, var$0, var$1, $fcast($X509CertificateArray, $($nc(this->certs)->toArray($$new($X509CertificateArray, $nc(this->certs)->size())))), $$new($SignerInfoArray, 0)));
	$var($DerOutputStream, derout, $new($DerOutputStream));
	try {
		p7->encodeSignedData(derout);
	} catch ($IOException& ioe) {
		$throwNew($CertificateEncodingException, $(ioe->getMessage()));
	}
	return derout->toByteArray();
}

$bytes* X509CertPath::getEncoded($String* encoding) {
	{
		$var($String, s13290$, encoding);
		int32_t tmp13290$ = -1;
		switch ($nc(s13290$)->hashCode()) {
		case 0x44768AF3:
			{
				if (s13290$->equals("PkiPath"_s)) {
					tmp13290$ = 0;
				}
				break;
			}
		case 0x048A75EC:
			{
				if (s13290$->equals("PKCS7"_s)) {
					tmp13290$ = 1;
				}
				break;
			}
		}
		switch (tmp13290$) {
		case 0:
			{
				return encodePKIPATH();
			}
		case 1:
			{
				return encodePKCS7();
			}
		default:
			{
				$throwNew($CertificateEncodingException, "unsupported encoding"_s);
			}
		}
	}
}

$Iterator* X509CertPath::getEncodingsStatic() {
	$init(X509CertPath);
	return $nc(X509CertPath::encodingList)->iterator();
}

$Iterator* X509CertPath::getEncodings() {
	return getEncodingsStatic();
}

$List* X509CertPath::getCertificates() {
	return this->certs;
}

void clinit$X509CertPath($Class* class$) {
	$assignStatic(X509CertPath::COUNT_ENCODING, "count"_s);
	$assignStatic(X509CertPath::PKCS7_ENCODING, "PKCS7"_s);
	$assignStatic(X509CertPath::PKIPATH_ENCODING, "PkiPath"_s);
	{
		$var($List, list, $new($ArrayList, 2));
		list->add(X509CertPath::PKIPATH_ENCODING);
		list->add(X509CertPath::PKCS7_ENCODING);
		$assignStatic(X509CertPath::encodingList, $Collections::unmodifiableCollection(list));
	}
}

X509CertPath::X509CertPath() {
}

$Class* X509CertPath::load$($String* name, bool initialize) {
	$loadClass(X509CertPath, name, initialize, &_X509CertPath_ClassInfo_, clinit$X509CertPath, allocate$X509CertPath);
	return class$;
}

$Class* X509CertPath::class$ = nullptr;

			} // certpath
		} // provider
	} // security
} // sun