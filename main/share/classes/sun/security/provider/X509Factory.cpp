#include <sun/security/provider/X509Factory.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/PushbackInputStream.h>
#include <java/math/BigInteger.h>
#include <java/security/Key.h>
#include <java/security/Principal.h>
#include <java/security/PublicKey.h>
#include <java/security/cert/CRL.h>
#include <java/security/cert/CRLException.h>
#include <java/security/cert/CertPath.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/CertificateFactorySpi.h>
#include <java/security/cert/X509CRL.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Base64$Decoder.h>
#include <java/util/Base64.h>
#include <java/util/Collection.h>
#include <java/util/Date.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jdk/internal/event/EventHelper.h>
#include <jdk/internal/event/X509CertificateEvent.h>
#include <sun/security/pkcs/PKCS7.h>
#include <sun/security/pkcs/ParsingException.h>
#include <sun/security/provider/certpath/X509CertPath.h>
#include <sun/security/provider/certpath/X509CertificatePair.h>
#include <sun/security/util/Cache$EqualByteArray.h>
#include <sun/security/util/Cache.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/KeyUtil.h>
#include <sun/security/x509/X509CRLImpl.h>
#include <sun/security/x509/X509CertImpl.h>
#include <jcpp.h>

#undef BEGIN_CERT
#undef ENC_MAX_LENGTH
#undef END_CERT

using $X509CRLArray = $Array<::java::security::cert::X509CRL>;
using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $PushbackInputStream = ::java::io::PushbackInputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Key = ::java::security::Key;
using $Principal = ::java::security::Principal;
using $PublicKey = ::java::security::PublicKey;
using $CRL = ::java::security::cert::CRL;
using $CRLException = ::java::security::cert::CRLException;
using $CertPath = ::java::security::cert::CertPath;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateException = ::java::security::cert::CertificateException;
using $CertificateFactorySpi = ::java::security::cert::CertificateFactorySpi;
using $X509CRL = ::java::security::cert::X509CRL;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Base64 = ::java::util::Base64;
using $Base64$Decoder = ::java::util::Base64$Decoder;
using $Collection = ::java::util::Collection;
using $Date = ::java::util::Date;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $EventHelper = ::jdk::internal::event::EventHelper;
using $X509CertificateEvent = ::jdk::internal::event::X509CertificateEvent;
using $PKCS7 = ::sun::security::pkcs::PKCS7;
using $ParsingException = ::sun::security::pkcs::ParsingException;
using $X509CertPath = ::sun::security::provider::certpath::X509CertPath;
using $X509CertificatePair = ::sun::security::provider::certpath::X509CertificatePair;
using $Cache = ::sun::security::util::Cache;
using $Cache$EqualByteArray = ::sun::security::util::Cache$EqualByteArray;
using $DerValue = ::sun::security::util::DerValue;
using $KeyUtil = ::sun::security::util::KeyUtil;
using $X509CRLImpl = ::sun::security::x509::X509CRLImpl;
using $X509CertImpl = ::sun::security::x509::X509CertImpl;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _X509Factory_FieldInfo_[] = {
	{"BEGIN_CERT", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509Factory, BEGIN_CERT)},
	{"END_CERT", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509Factory, END_CERT)},
	{"ENC_MAX_LENGTH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(X509Factory, ENC_MAX_LENGTH)},
	{"certCache", "Lsun/security/util/Cache;", "Lsun/security/util/Cache<Ljava/lang/Object;Lsun/security/x509/X509CertImpl;>;", $PRIVATE | $STATIC | $FINAL, $staticField(X509Factory, certCache)},
	{"crlCache", "Lsun/security/util/Cache;", "Lsun/security/util/Cache<Ljava/lang/Object;Lsun/security/x509/X509CRLImpl;>;", $PRIVATE | $STATIC | $FINAL, $staticField(X509Factory, crlCache)},
	{}
};

$MethodInfo _X509Factory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(X509Factory, init$, void)},
	{"addToCache", "(Lsun/security/util/Cache;[BLjava/lang/Object;)V", "<V:Ljava/lang/Object;>(Lsun/security/util/Cache<Ljava/lang/Object;TV;>;[BTV;)V", $PRIVATE | $STATIC | $SYNCHRONIZED, $staticMethod(X509Factory, addToCache, void, $Cache*, $bytes*, Object$*)},
	{"checkHeaderFooter", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(X509Factory, checkHeaderFooter, void, $String*, $String*), "java.io.IOException"},
	{"commitEvent", "(Lsun/security/x509/X509CertImpl;)V", nullptr, $PRIVATE, $method(X509Factory, commitEvent, void, $X509CertImpl*)},
	{"engineGenerateCRL", "(Ljava/io/InputStream;)Ljava/security/cert/CRL;", nullptr, $PUBLIC, $virtualMethod(X509Factory, engineGenerateCRL, $CRL*, $InputStream*), "java.security.cert.CRLException"},
	{"engineGenerateCRLs", "(Ljava/io/InputStream;)Ljava/util/Collection;", "(Ljava/io/InputStream;)Ljava/util/Collection<+Ljava/security/cert/CRL;>;", $PUBLIC, $virtualMethod(X509Factory, engineGenerateCRLs, $Collection*, $InputStream*), "java.security.cert.CRLException"},
	{"engineGenerateCertPath", "(Ljava/io/InputStream;)Ljava/security/cert/CertPath;", nullptr, $PUBLIC, $virtualMethod(X509Factory, engineGenerateCertPath, $CertPath*, $InputStream*), "java.security.cert.CertificateException"},
	{"engineGenerateCertPath", "(Ljava/io/InputStream;Ljava/lang/String;)Ljava/security/cert/CertPath;", nullptr, $PUBLIC, $virtualMethod(X509Factory, engineGenerateCertPath, $CertPath*, $InputStream*, $String*), "java.security.cert.CertificateException"},
	{"engineGenerateCertPath", "(Ljava/util/List;)Ljava/security/cert/CertPath;", "(Ljava/util/List<+Ljava/security/cert/Certificate;>;)Ljava/security/cert/CertPath;", $PUBLIC, $virtualMethod(X509Factory, engineGenerateCertPath, $CertPath*, $List*), "java.security.cert.CertificateException"},
	{"engineGenerateCertificate", "(Ljava/io/InputStream;)Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $virtualMethod(X509Factory, engineGenerateCertificate, $Certificate*, $InputStream*), "java.security.cert.CertificateException"},
	{"engineGenerateCertificates", "(Ljava/io/InputStream;)Ljava/util/Collection;", "(Ljava/io/InputStream;)Ljava/util/Collection<+Ljava/security/cert/Certificate;>;", $PUBLIC, $virtualMethod(X509Factory, engineGenerateCertificates, $Collection*, $InputStream*), "java.security.cert.CertificateException"},
	{"engineGetCertPathEncodings", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(X509Factory, engineGetCertPathEncodings, $Iterator*)},
	{"getFromCache", "(Lsun/security/util/Cache;[B)Ljava/lang/Object;", "<K:Ljava/lang/Object;V:Ljava/lang/Object;>(Lsun/security/util/Cache<TK;TV;>;[B)TV;", $PRIVATE | $STATIC | $SYNCHRONIZED, $staticMethod(X509Factory, getFromCache, $Object*, $Cache*, $bytes*)},
	{"intern", "(Ljava/security/cert/X509Certificate;)Lsun/security/x509/X509CertImpl;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $staticMethod(X509Factory, intern, $X509CertImpl*, $X509Certificate*), "java.security.cert.CertificateException"},
	{"intern", "(Ljava/security/cert/X509CRL;)Lsun/security/x509/X509CRLImpl;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $staticMethod(X509Factory, intern, $X509CRLImpl*, $X509CRL*), "java.security.cert.CRLException"},
	{"parseX509orPKCS7CRL", "(Ljava/io/InputStream;)Ljava/util/Collection;", "(Ljava/io/InputStream;)Ljava/util/Collection<+Ljava/security/cert/CRL;>;", $PRIVATE, $method(X509Factory, parseX509orPKCS7CRL, $Collection*, $InputStream*), "java.security.cert.CRLException,java.io.IOException"},
	{"parseX509orPKCS7Cert", "(Ljava/io/InputStream;)Ljava/util/Collection;", "(Ljava/io/InputStream;)Ljava/util/Collection<+Ljava/security/cert/Certificate;>;", $PRIVATE, $method(X509Factory, parseX509orPKCS7Cert, $Collection*, $InputStream*), "java.security.cert.CertificateException,java.io.IOException"},
	{"readBERInternal", "(Ljava/io/InputStream;Ljava/io/ByteArrayOutputStream;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(X509Factory, readBERInternal, int32_t, $InputStream*, $ByteArrayOutputStream*, int32_t), "java.io.IOException"},
	{"readFully", "(Ljava/io/InputStream;Ljava/io/ByteArrayOutputStream;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(X509Factory, readFully, int32_t, $InputStream*, $ByteArrayOutputStream*, int32_t), "java.io.IOException"},
	{"readOneBlock", "(Ljava/io/InputStream;)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(X509Factory, readOneBlock, $bytes*, $InputStream*), "java.io.IOException"},
	{}
};

$ClassInfo _X509Factory_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.provider.X509Factory",
	"java.security.cert.CertificateFactorySpi",
	nullptr,
	_X509Factory_FieldInfo_,
	_X509Factory_MethodInfo_
};

$Object* allocate$X509Factory($Class* clazz) {
	return $of($alloc(X509Factory));
}

$String* X509Factory::BEGIN_CERT = nullptr;
$String* X509Factory::END_CERT = nullptr;
$Cache* X509Factory::certCache = nullptr;
$Cache* X509Factory::crlCache = nullptr;

void X509Factory::init$() {
	$CertificateFactorySpi::init$();
}

$Certificate* X509Factory::engineGenerateCertificate($InputStream* is) {
	$useLocalCurrentObjectStackCache();
	if (is == nullptr) {
		$nc(X509Factory::certCache)->clear();
		$X509CertificatePair::clearCache();
		$throwNew($CertificateException, "Missing input stream"_s);
	}
	try {
		$var($bytes, encoding, readOneBlock(is));
		if (encoding != nullptr) {
			$var($X509CertImpl, cert, $cast($X509CertImpl, getFromCache(X509Factory::certCache, encoding)));
			if (cert != nullptr) {
				return cert;
			}
			$assign(cert, $new($X509CertImpl, encoding));
			addToCache(X509Factory::certCache, $(cert->getEncodedInternal()), cert);
			commitEvent(cert);
			return cert;
		} else {
			$throwNew($IOException, "Empty input"_s);
		}
	} catch ($IOException& ioe) {
		$throwNew($CertificateException, $$str({"Could not parse certificate: "_s, $(ioe->toString())}), ioe);
	}
	$shouldNotReachHere();
}

int32_t X509Factory::readFully($InputStream* in, $ByteArrayOutputStream* bout, int32_t length) {
	$init(X509Factory);
	int32_t read = 0;
	$var($bytes, buffer, $new($bytes, 2048));
	while (length > 0) {
		int32_t n = $nc(in)->read(buffer, 0, length < 2048 ? length : 2048);
		if (n <= 0) {
			break;
		}
		$nc(bout)->write(buffer, 0, n);
		read += n;
		length -= n;
	}
	return read;
}

$X509CertImpl* X509Factory::intern($X509Certificate* c) {
	$load(X509Factory);
	$synchronized(class$) {
		$init(X509Factory);
		$useLocalCurrentObjectStackCache();
		if (c == nullptr) {
			return nullptr;
		}
		bool isImpl = $instanceOf($X509CertImpl, c);
		$var($bytes, encoding, nullptr);
		if (isImpl) {
			$assign(encoding, $nc(($cast($X509CertImpl, c)))->getEncodedInternal());
		} else {
			$assign(encoding, $nc(c)->getEncoded());
		}
		$var($X509CertImpl, newC, $cast($X509CertImpl, getFromCache(X509Factory::certCache, encoding)));
		if (newC != nullptr) {
			return newC;
		}
		if (isImpl) {
			$assign(newC, $cast($X509CertImpl, c));
		} else {
			$assign(newC, $new($X509CertImpl, encoding));
			$assign(encoding, newC->getEncodedInternal());
		}
		addToCache(X509Factory::certCache, encoding, newC);
		return newC;
	}
}

$X509CRLImpl* X509Factory::intern($X509CRL* c) {
	$load(X509Factory);
	$synchronized(class$) {
		$init(X509Factory);
		$useLocalCurrentObjectStackCache();
		if (c == nullptr) {
			return nullptr;
		}
		bool isImpl = $instanceOf($X509CRLImpl, c);
		$var($bytes, encoding, nullptr);
		if (isImpl) {
			$assign(encoding, $nc(($cast($X509CRLImpl, c)))->getEncodedInternal());
		} else {
			$assign(encoding, $nc(c)->getEncoded());
		}
		$var($X509CRLImpl, newC, $cast($X509CRLImpl, getFromCache(X509Factory::crlCache, encoding)));
		if (newC != nullptr) {
			return newC;
		}
		if (isImpl) {
			$assign(newC, $cast($X509CRLImpl, c));
		} else {
			$assign(newC, $new($X509CRLImpl, encoding));
			$assign(encoding, newC->getEncodedInternal());
		}
		addToCache(X509Factory::crlCache, encoding, newC);
		return newC;
	}
}

$Object* X509Factory::getFromCache($Cache* cache, $bytes* encoding) {
	$load(X509Factory);
	$synchronized(class$) {
		$init(X509Factory);
		$var($Object, key, $new($Cache$EqualByteArray, encoding));
		return $of($nc(cache)->get(key));
	}
}

void X509Factory::addToCache($Cache* cache, $bytes* encoding, Object$* value) {
	$load(X509Factory);
	$synchronized(class$) {
		$init(X509Factory);
		if ($nc(encoding)->length > X509Factory::ENC_MAX_LENGTH) {
			return;
		}
		$var($Object, key, $new($Cache$EqualByteArray, encoding));
		$nc(cache)->put(key, value);
	}
}

$CertPath* X509Factory::engineGenerateCertPath($InputStream* inStream) {
	$useLocalCurrentObjectStackCache();
	if (inStream == nullptr) {
		$throwNew($CertificateException, "Missing input stream"_s);
	}
	try {
		$var($bytes, encoding, readOneBlock(inStream));
		if (encoding != nullptr) {
			return $new($X509CertPath, static_cast<$InputStream*>($$new($ByteArrayInputStream, encoding)));
		} else {
			$throwNew($IOException, "Empty input"_s);
		}
	} catch ($IOException& ioe) {
		$throwNew($CertificateException, $(ioe->getMessage()));
	}
	$shouldNotReachHere();
}

$CertPath* X509Factory::engineGenerateCertPath($InputStream* inStream, $String* encoding) {
	$useLocalCurrentObjectStackCache();
	if (inStream == nullptr) {
		$throwNew($CertificateException, "Missing input stream"_s);
	}
	try {
		$var($bytes, data, readOneBlock(inStream));
		if (data != nullptr) {
			return $new($X509CertPath, $$new($ByteArrayInputStream, data), encoding);
		} else {
			$throwNew($IOException, "Empty input"_s);
		}
	} catch ($IOException& ioe) {
		$throwNew($CertificateException, $(ioe->getMessage()));
	}
	$shouldNotReachHere();
}

$CertPath* X509Factory::engineGenerateCertPath($List* certificates) {
	return ($new($X509CertPath, certificates));
}

$Iterator* X509Factory::engineGetCertPathEncodings() {
	return ($X509CertPath::getEncodingsStatic());
}

$Collection* X509Factory::engineGenerateCertificates($InputStream* is) {
	if (is == nullptr) {
		$throwNew($CertificateException, "Missing input stream"_s);
	}
	try {
		return parseX509orPKCS7Cert(is);
	} catch ($IOException& ioe) {
		$throwNew($CertificateException, static_cast<$Throwable*>(ioe));
	}
	$shouldNotReachHere();
}

$CRL* X509Factory::engineGenerateCRL($InputStream* is) {
	$useLocalCurrentObjectStackCache();
	if (is == nullptr) {
		$nc(X509Factory::crlCache)->clear();
		$throwNew($CRLException, "Missing input stream"_s);
	}
	try {
		$var($bytes, encoding, readOneBlock(is));
		if (encoding != nullptr) {
			$var($X509CRLImpl, crl, $cast($X509CRLImpl, getFromCache(X509Factory::crlCache, encoding)));
			if (crl != nullptr) {
				return crl;
			}
			$assign(crl, $new($X509CRLImpl, encoding));
			addToCache(X509Factory::crlCache, $(crl->getEncodedInternal()), crl);
			return crl;
		} else {
			$throwNew($IOException, "Empty input"_s);
		}
	} catch ($IOException& ioe) {
		$throwNew($CRLException, $(ioe->getMessage()));
	}
	$shouldNotReachHere();
}

$Collection* X509Factory::engineGenerateCRLs($InputStream* is) {
	if (is == nullptr) {
		$throwNew($CRLException, "Missing input stream"_s);
	}
	try {
		return parseX509orPKCS7CRL(is);
	} catch ($IOException& ioe) {
		$throwNew($CRLException, $(ioe->getMessage()));
	}
	$shouldNotReachHere();
}

$Collection* X509Factory::parseX509orPKCS7Cert($InputStream* is) {
	$useLocalCurrentObjectStackCache();
	int32_t peekByte = 0;
	$var($bytes, data, nullptr);
	$var($PushbackInputStream, pbis, $new($PushbackInputStream, is));
	$var($Collection, coll, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>($new($ArrayList)))));
	peekByte = pbis->read();
	if (peekByte == -1) {
		return static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>($new($ArrayList, 0))));
	} else {
		pbis->unread(peekByte);
		$assign(data, readOneBlock(pbis));
	}
	if (data == nullptr) {
		$throwNew($CertificateException, "No certificate data found"_s);
	}
	try {
		$var($PKCS7, pkcs7, $new($PKCS7, data));
		$var($X509CertificateArray, certs, pkcs7->getCertificates());
		if (certs != nullptr) {
			return $Arrays::asList(certs);
		} else {
			return static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>($new($ArrayList, 0))));
		}
	} catch ($ParsingException& e) {
		while (data != nullptr) {
			coll->add($$new($X509CertImpl, data));
			$assign(data, readOneBlock(pbis));
		}
	}
	return coll;
}

$Collection* X509Factory::parseX509orPKCS7CRL($InputStream* is) {
	$useLocalCurrentObjectStackCache();
	int32_t peekByte = 0;
	$var($bytes, data, nullptr);
	$var($PushbackInputStream, pbis, $new($PushbackInputStream, is));
	$var($Collection, coll, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>($new($ArrayList)))));
	peekByte = pbis->read();
	if (peekByte == -1) {
		return static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>($new($ArrayList, 0))));
	} else {
		pbis->unread(peekByte);
		$assign(data, readOneBlock(pbis));
	}
	if (data == nullptr) {
		$throwNew($CRLException, "No CRL data found"_s);
	}
	try {
		$var($PKCS7, pkcs7, $new($PKCS7, data));
		$var($X509CRLArray, crls, pkcs7->getCRLs());
		if (crls != nullptr) {
			return $Arrays::asList(crls);
		} else {
			return static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>($new($ArrayList, 0))));
		}
	} catch ($ParsingException& e) {
		while (data != nullptr) {
			coll->add($$new($X509CRLImpl, data));
			$assign(data, readOneBlock(pbis));
		}
	}
	return coll;
}

$bytes* X509Factory::readOneBlock($InputStream* is) {
	$init(X509Factory);
	$useLocalCurrentObjectStackCache();
	int32_t c = $nc(is)->read();
	if (c == -1) {
		return nullptr;
	}
	if (c == $DerValue::tag_Sequence) {
		$var($ByteArrayOutputStream, bout, $new($ByteArrayOutputStream, 2048));
		bout->write(c);
		readBERInternal(is, bout, c);
		return bout->toByteArray();
	} else {
		$var($ByteArrayOutputStream, data, $new($ByteArrayOutputStream));
		int32_t hyphen = (c == u'-') ? 1 : 0;
		int32_t last = (c == u'-') ? -1 : c;
		while (true) {
			int32_t next = is->read();
			if (next == -1) {
				return nullptr;
			}
			if (next == u'-') {
				++hyphen;
			} else {
				hyphen = 0;
				last = next;
			}
			if (hyphen == 5 && (last == -1 || last == u'\r' || last == u'\n')) {
				break;
			}
		}
		int32_t end = 0;
		$var($StringBuilder, header, $new($StringBuilder, "-----"_s));
		while (true) {
			int32_t next = is->read();
			if (next == -1) {
				$throwNew($IOException, "Incomplete data"_s);
			}
			if (next == u'\n') {
				end = u'\n';
				break;
			}
			if (next == u'\r') {
				next = is->read();
				if (next == -1) {
					$throwNew($IOException, "Incomplete data"_s);
				}
				if (next == u'\n') {
					end = u'\n';
				} else {
					end = u'\r';
					if (next != 9 && next != 10 && next != 13 && next != 32) {
						data->write(next);
					}
				}
				break;
			}
			header->append((char16_t)next);
		}
		while (true) {
			int32_t next = is->read();
			if (next == -1) {
				$throwNew($IOException, "Incomplete data"_s);
			}
			if (next != u'-') {
				if (next != 9 && next != 10 && next != 13 && next != 32) {
					data->write(next);
				}
			} else {
				break;
			}
		}
		$var($StringBuilder, footer, $new($StringBuilder, "-"_s));
		while (true) {
			int32_t next = is->read();
			if (next == -1 || next == end || next == u'\n') {
				break;
			}
			if (next != u'\r') {
				footer->append((char16_t)next);
			}
		}
		$var($String, var$0, $nc($(header->toString()))->stripTrailing());
		checkHeaderFooter(var$0, $($nc($(footer->toString()))->stripTrailing()));
		try {
			return $nc($($Base64::getDecoder()))->decode($(data->toByteArray()));
		} catch ($IllegalArgumentException& e) {
			$throwNew($IOException, static_cast<$Throwable*>(e));
		}
	}
	$shouldNotReachHere();
}

void X509Factory::checkHeaderFooter($String* header, $String* footer) {
	$init(X509Factory);
	$useLocalCurrentObjectStackCache();
	bool var$1 = $nc(header)->length() < 16;
	bool var$0 = var$1 || !$nc(header)->startsWith("-----BEGIN "_s);
	if (var$0 || !$nc(header)->endsWith("-----"_s)) {
		$throwNew($IOException, $$str({"Illegal header: "_s, header}));
	}
	bool var$3 = $nc(footer)->length() < 14;
	bool var$2 = var$3 || !$nc(footer)->startsWith("-----END "_s);
	if (var$2 || !$nc(footer)->endsWith("-----"_s)) {
		$throwNew($IOException, $$str({"Illegal footer: "_s, footer}));
	}
	$var($String, headerType, $nc(header)->substring(11, header->length() - 5));
	$var($String, footerType, $nc(footer)->substring(9, footer->length() - 5));
	if (!headerType->equals(footerType)) {
		$throwNew($IOException, $$str({"Header and footer do not match: "_s, header, " "_s, footer}));
	}
}

int32_t X509Factory::readBERInternal($InputStream* is, $ByteArrayOutputStream* bout, int32_t tag) {
	$init(X509Factory);
	if (tag == -1) {
		tag = $nc(is)->read();
		if (tag == -1) {
			$throwNew($IOException, "BER/DER tag info absent"_s);
		}
		if (((int32_t)(tag & (uint32_t)31)) == 31) {
			$throwNew($IOException, "Multi octets tag not supported"_s);
		}
		$nc(bout)->write(tag);
	}
	int32_t n = $nc(is)->read();
	if (n == -1) {
		$throwNew($IOException, "BER/DER length info absent"_s);
	}
	$nc(bout)->write(n);
	int32_t length = 0;
	if (n == 128) {
		if (((int32_t)(tag & (uint32_t)32)) != 32) {
			$throwNew($IOException, "Non constructed encoding must have definite length"_s);
		}
		while (true) {
			int32_t subTag = readBERInternal(is, bout, -1);
			if (subTag == 0) {
				break;
			}
		}
	} else {
		if (n < 128) {
			length = n;
		} else if (n == 129) {
			length = is->read();
			if (length == -1) {
				$throwNew($IOException, "Incomplete BER/DER length info"_s);
			}
			bout->write(length);
		} else if (n == 130) {
			int32_t highByte = is->read();
			int32_t lowByte = is->read();
			if (lowByte == -1) {
				$throwNew($IOException, "Incomplete BER/DER length info"_s);
			}
			bout->write(highByte);
			bout->write(lowByte);
			length = (highByte << 8) | lowByte;
		} else if (n == 131) {
			int32_t highByte = is->read();
			int32_t midByte = is->read();
			int32_t lowByte = is->read();
			if (lowByte == -1) {
				$throwNew($IOException, "Incomplete BER/DER length info"_s);
			}
			bout->write(highByte);
			bout->write(midByte);
			bout->write(lowByte);
			length = ((highByte << 16) | (midByte << 8)) | lowByte;
		} else if (n == 132) {
			int32_t highByte = is->read();
			int32_t nextByte = is->read();
			int32_t midByte = is->read();
			int32_t lowByte = is->read();
			if (lowByte == -1) {
				$throwNew($IOException, "Incomplete BER/DER length info"_s);
			}
			if (highByte > 127) {
				$throwNew($IOException, "Invalid BER/DER data (a little huge?)"_s);
			}
			bout->write(highByte);
			bout->write(nextByte);
			bout->write(midByte);
			bout->write(lowByte);
			length = (((highByte << 24) | (nextByte << 16)) | (midByte << 8)) | lowByte;
		} else {
			$throwNew($IOException, "Invalid BER/DER data (too huge?)"_s);
		}
		if (readFully(is, bout, length) != length) {
			$throwNew($IOException, "Incomplete BER/DER data"_s);
		}
	}
	return tag;
}

void X509Factory::commitEvent($X509CertImpl* info) {
	$useLocalCurrentObjectStackCache();
	$var($X509CertificateEvent, xce, $new($X509CertificateEvent));
	bool var$0 = xce->shouldCommit();
	if (var$0 || $EventHelper::isLoggingSecurity()) {
		$var($PublicKey, pKey, $nc(info)->getPublicKey());
		$var($String, algId, info->getSigAlgName());
		$var($String, serNum, $nc($(info->getSerialNumber()))->toString(16));
		$var($String, subject, $nc($(info->getSubjectDN()))->getName());
		$var($String, issuer, $nc($(info->getIssuerDN()))->getName());
		$var($String, keyType, $nc(pKey)->getAlgorithm());
		int32_t length = $KeyUtil::getKeySize(static_cast<$Key*>(pKey));
		int32_t hashCode = info->hashCode();
		int64_t beginDate = $nc($(info->getNotBefore()))->getTime();
		int64_t endDate = $nc($(info->getNotAfter()))->getTime();
		if (xce->shouldCommit()) {
			$set(xce, algorithm, algId);
			$set(xce, serialNumber, serNum);
			$set(xce, subject, subject);
			$set(xce, issuer, issuer);
			$set(xce, keyType, keyType);
			xce->keyLength = length;
			xce->certificateId = hashCode;
			xce->validFrom = beginDate;
			xce->validUntil = endDate;
			xce->commit();
		}
		if ($EventHelper::isLoggingSecurity()) {
			$EventHelper::logX509CertificateEvent(algId, serNum, subject, issuer, keyType, length, hashCode, beginDate, endDate);
		}
	}
}

void clinit$X509Factory($Class* class$) {
	$assignStatic(X509Factory::BEGIN_CERT, "-----BEGIN CERTIFICATE-----"_s);
	$assignStatic(X509Factory::END_CERT, "-----END CERTIFICATE-----"_s);
	$assignStatic(X509Factory::certCache, $Cache::newSoftMemoryCache(750));
	$assignStatic(X509Factory::crlCache, $Cache::newSoftMemoryCache(750));
}

X509Factory::X509Factory() {
}

$Class* X509Factory::load$($String* name, bool initialize) {
	$loadClass(X509Factory, name, initialize, &_X509Factory_ClassInfo_, clinit$X509Factory, allocate$X509Factory);
	return class$;
}

$Class* X509Factory::class$ = nullptr;

		} // provider
	} // security
} // sun