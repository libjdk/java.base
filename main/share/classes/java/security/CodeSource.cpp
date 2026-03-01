#include <java/security/CodeSource.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/net/SocketPermission.h>
#include <java/net/URL.h>
#include <java/security/CodeSigner.h>
#include <java/security/Permission.h>
#include <java/security/Timestamp.h>
#include <java/security/cert/CertPath.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateEncodingException.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/CertificateFactory.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Hashtable.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <sun/net/util/URLUtil.h>
#include <sun/security/util/IOUtils.h>
#include <jcpp.h>

using $CodeSignerArray = $Array<::java::security::CodeSigner>;
using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SocketPermission = ::java::net::SocketPermission;
using $URL = ::java::net::URL;
using $CodeSigner = ::java::security::CodeSigner;
using $Permission = ::java::security::Permission;
using $Timestamp = ::java::security::Timestamp;
using $CertPath = ::java::security::cert::CertPath;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateEncodingException = ::java::security::cert::CertificateEncodingException;
using $CertificateException = ::java::security::cert::CertificateException;
using $CertificateFactory = ::java::security::cert::CertificateFactory;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Hashtable = ::java::util::Hashtable;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $URLUtil = ::sun::net::util::URLUtil;
using $IOUtils = ::sun::security::util::IOUtils;

namespace java {
	namespace security {

$FieldInfo _CodeSource_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CodeSource, serialVersionUID)},
	{"location", "Ljava/net/URL;", nullptr, $PRIVATE | $FINAL, $field(CodeSource, location)},
	{"signers", "[Ljava/security/CodeSigner;", nullptr, $PRIVATE | $TRANSIENT, $field(CodeSource, signers)},
	{"certs", "[Ljava/security/cert/Certificate;", nullptr, $PRIVATE | $TRANSIENT, $field(CodeSource, certs)},
	{"sp", "Ljava/net/SocketPermission;", nullptr, $PRIVATE | $TRANSIENT, $field(CodeSource, sp)},
	{"factory", "Ljava/security/cert/CertificateFactory;", nullptr, $PRIVATE | $TRANSIENT, $field(CodeSource, factory)},
	{"locationNoFragString", "Ljava/lang/String;", nullptr, $PRIVATE | $TRANSIENT, $field(CodeSource, locationNoFragString)},
	{}
};

$MethodInfo _CodeSource_MethodInfo_[] = {
	{"<init>", "(Ljava/net/URL;[Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC, $method(CodeSource, init$, void, $URL*, $CertificateArray*)},
	{"<init>", "(Ljava/net/URL;[Ljava/security/CodeSigner;)V", nullptr, $PUBLIC, $method(CodeSource, init$, void, $URL*, $CodeSignerArray*)},
	{"convertCertArrayToSignerArray", "([Ljava/security/cert/Certificate;)[Ljava/security/CodeSigner;", nullptr, $PRIVATE, $method(CodeSource, convertCertArrayToSignerArray, $CodeSignerArray*, $CertificateArray*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(CodeSource, equals, bool, Object$*)},
	{"getCertificates", "()[Ljava/security/cert/Certificate;", nullptr, $PUBLIC | $FINAL, $method(CodeSource, getCertificates, $CertificateArray*)},
	{"getCodeSigners", "()[Ljava/security/CodeSigner;", nullptr, $PUBLIC | $FINAL, $method(CodeSource, getCodeSigners, $CodeSignerArray*)},
	{"getLocation", "()Ljava/net/URL;", nullptr, $PUBLIC | $FINAL, $method(CodeSource, getLocation, $URL*)},
	{"getLocationNoFragString", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(CodeSource, getLocationNoFragString, $String*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(CodeSource, hashCode, int32_t)},
	{"implies", "(Ljava/security/CodeSource;)Z", nullptr, $PUBLIC, $virtualMethod(CodeSource, implies, bool, CodeSource*)},
	{"matchCerts", "(Ljava/security/CodeSource;Z)Z", nullptr, 0, $virtualMethod(CodeSource, matchCerts, bool, CodeSource*, bool)},
	{"matchLocation", "(Ljava/security/CodeSource;)Z", nullptr, $PRIVATE, $method(CodeSource, matchLocation, bool, CodeSource*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(CodeSource, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CodeSource, toString, $String*)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(CodeSource, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$ClassInfo _CodeSource_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.security.CodeSource",
	"java.lang.Object",
	"java.io.Serializable",
	_CodeSource_FieldInfo_,
	_CodeSource_MethodInfo_
};

$Object* allocate$CodeSource($Class* clazz) {
	return $of($alloc(CodeSource));
}

void CodeSource::init$($URL* url, $CertificateArray* certs) {
	$set(this, signers, nullptr);
	$set(this, certs, nullptr);
	$set(this, factory, nullptr);
	$set(this, location, url);
	if (url != nullptr) {
		$set(this, locationNoFragString, $URLUtil::urlNoFragString(url));
	}
	if (certs != nullptr) {
		$set(this, certs, $cast($CertificateArray, certs->clone()));
	}
}

void CodeSource::init$($URL* url, $CodeSignerArray* signers) {
	$set(this, signers, nullptr);
	$set(this, certs, nullptr);
	$set(this, factory, nullptr);
	$set(this, location, url);
	if (url != nullptr) {
		$set(this, locationNoFragString, $URLUtil::urlNoFragString(url));
	}
	if (signers != nullptr) {
		$set(this, signers, $cast($CodeSignerArray, signers->clone()));
	}
}

int32_t CodeSource::hashCode() {
	if (this->location != nullptr) {
		return $nc(this->location)->hashCode();
	} else {
		return 0;
	}
}

bool CodeSource::equals(Object$* obj) {
	if ($equals(obj, this)) {
		return true;
	}
	$var(CodeSource, other, nullptr);
	bool var$2 = $instanceOf(CodeSource, obj);
	if (var$2) {
		$assign(other, $cast(CodeSource, obj));
		var$2 = true;
	}
	bool var$1 = (var$2);
	bool var$0 = var$1 && $Objects::equals(this->location, $nc(other)->location);
	return var$0 && matchCerts(other, true);
}

$URL* CodeSource::getLocation() {
	return this->location;
}

$String* CodeSource::getLocationNoFragString() {
	return this->locationNoFragString;
}

$CertificateArray* CodeSource::getCertificates() {
	$useLocalCurrentObjectStackCache();
	if (this->certs != nullptr) {
		return $cast($CertificateArray, $nc(this->certs)->clone());
	} else if (this->signers != nullptr) {
		$var($ArrayList, certChains, $new($ArrayList));
		for (int32_t i = 0; i < $nc(this->signers)->length; ++i) {
			certChains->addAll($($nc($($nc($nc(this->signers)->get(i))->getSignerCertPath()))->getCertificates()));
		}
		$set(this, certs, $fcast($CertificateArray, certChains->toArray($$new($CertificateArray, certChains->size()))));
		return $cast($CertificateArray, $nc(this->certs)->clone());
	} else {
		return nullptr;
	}
}

$CodeSignerArray* CodeSource::getCodeSigners() {
	if (this->signers != nullptr) {
		return $cast($CodeSignerArray, $nc(this->signers)->clone());
	} else if (this->certs != nullptr) {
		$set(this, signers, convertCertArrayToSignerArray(this->certs));
		return $cast($CodeSignerArray, $nc(this->signers)->clone());
	} else {
		return nullptr;
	}
}

bool CodeSource::implies(CodeSource* codesource) {
	if (codesource == nullptr) {
		return false;
	}
	bool var$0 = matchCerts(codesource, false);
	return var$0 && matchLocation(codesource);
}

bool CodeSource::matchCerts(CodeSource* that, bool strict) {
	bool match = false;
	if (this->certs == nullptr && this->signers == nullptr) {
		if (strict) {
			return ($nc(that)->certs == nullptr && that->signers == nullptr);
		} else {
			return true;
		}
	} else if (this->signers != nullptr && $nc(that)->signers != nullptr) {
		if (strict && $nc(this->signers)->length != $nc(that->signers)->length) {
			return false;
		}
		for (int32_t i = 0; i < $nc(this->signers)->length; ++i) {
			match = false;
			for (int32_t j = 0; j < $nc(that->signers)->length; ++j) {
				if ($nc($nc(this->signers)->get(i))->equals($nc(that->signers)->get(j))) {
					match = true;
					break;
				}
			}
			if (!match) {
				return false;
			}
		}
		return true;
	} else if (this->certs != nullptr && that->certs != nullptr) {
		if (strict && $nc(this->certs)->length != $nc(that->certs)->length) {
			return false;
		}
		for (int32_t i = 0; i < $nc(this->certs)->length; ++i) {
			match = false;
			for (int32_t j = 0; j < $nc(that->certs)->length; ++j) {
				if ($nc($nc(this->certs)->get(i))->equals($nc(that->certs)->get(j))) {
					match = true;
					break;
				}
			}
			if (!match) {
				return false;
			}
		}
		return true;
	}
	return false;
}

bool CodeSource::matchLocation(CodeSource* that) {
	$useLocalCurrentObjectStackCache();
	if (this->location == nullptr) {
		return true;
	}
	if ((that == nullptr) || ($nc(that)->location == nullptr)) {
		return false;
	}
	if ($nc(this->location)->equals($nc(that)->location)) {
		return true;
	}
	if (!$nc($($nc(this->location)->getProtocol()))->equalsIgnoreCase($($nc($nc(that)->location)->getProtocol()))) {
		return false;
	}
	int32_t thisPort = $nc(this->location)->getPort();
	if (thisPort != -1) {
		int32_t thatPort = $nc($nc(that)->location)->getPort();
		int32_t port = thatPort != -1 ? thatPort : $nc(that->location)->getDefaultPort();
		if (thisPort != port) {
			return false;
		}
	}
	if ($nc($($nc(this->location)->getFile()))->endsWith("/-"_s)) {
		$var($String, thisPath, $nc($($nc(this->location)->getFile()))->substring(0, $nc($($nc(this->location)->getFile()))->length() - 1));
		if (!$nc($($nc($nc(that)->location)->getFile()))->startsWith(thisPath)) {
			return false;
		}
	} else if ($nc($($nc(this->location)->getFile()))->endsWith("/*"_s)) {
		int32_t last = $nc($($nc($nc(that)->location)->getFile()))->lastIndexOf((int32_t)u'/');
		if (last == -1) {
			return false;
		}
		$var($String, thisPath, $nc($($nc(this->location)->getFile()))->substring(0, $nc($($nc(this->location)->getFile()))->length() - 1));
		$var($String, thatPath, $nc($($nc(that->location)->getFile()))->substring(0, last + 1));
		if (!thatPath->equals(thisPath)) {
			return false;
		}
	} else {
		bool var$1 = (!$nc($($nc($nc(that)->location)->getFile()))->equals($($nc(this->location)->getFile())));
		if (var$1 && (!$nc($($nc(that->location)->getFile()))->equals($$str({$($nc(this->location)->getFile()), "/"_s})))) {
			return false;
		}
	}
	bool var$2 = $nc(this->location)->getRef() != nullptr;
	if (var$2 && !$nc($($nc(this->location)->getRef()))->equals($($nc($nc(that)->location)->getRef()))) {
		return false;
	}
	$var($String, thisHost, $nc(this->location)->getHost());
	$var($String, thatHost, $nc($nc(that)->location)->getHost());
	if (thisHost != nullptr) {
		bool var$4 = ""_s->equals(thisHost);
		bool var$3 = (var$4 || "localhost"_s->equals(thisHost));
		if (var$3) {
			bool var$5 = ""_s->equals(thatHost);
			var$3 = (var$5 || "localhost"_s->equals(thatHost));
		}
		if (var$3) {
		} else if (!thisHost->equals(thatHost)) {
			if (thatHost == nullptr) {
				return false;
			}
			if (this->sp == nullptr) {
				$set(this, sp, $new($SocketPermission, thisHost, "resolve"_s));
			}
			if (that->sp == nullptr) {
				$set(that, sp, $new($SocketPermission, thatHost, "resolve"_s));
			}
			if (!$nc(this->sp)->implies(that->sp)) {
				return false;
			}
		}
	}
	return true;
}

$String* CodeSource::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append("("_s);
	sb->append($of(this->location));
	if (this->certs != nullptr && $nc(this->certs)->length > 0) {
		for (int32_t i = 0; i < $nc(this->certs)->length; ++i) {
			sb->append($$str({" "_s, $nc(this->certs)->get(i)}));
		}
	} else if (this->signers != nullptr && $nc(this->signers)->length > 0) {
		for (int32_t i = 0; i < $nc(this->signers)->length; ++i) {
			sb->append($$str({" "_s, $nc(this->signers)->get(i)}));
		}
	} else {
		sb->append(" <no signer certificates>"_s);
	}
	sb->append(")"_s);
	return sb->toString();
}

void CodeSource::writeObject($ObjectOutputStream* oos) {
	$useLocalCurrentObjectStackCache();
	$nc(oos)->defaultWriteObject();
	if (this->certs == nullptr || $nc(this->certs)->length == 0) {
		oos->writeInt(0);
	} else {
		oos->writeInt($nc(this->certs)->length);
		for (int32_t i = 0; i < $nc(this->certs)->length; ++i) {
			$var($Certificate, cert, $nc(this->certs)->get(i));
			try {
				oos->writeUTF($($nc(cert)->getType()));
				$var($bytes, encoded, $nc(cert)->getEncoded());
				oos->writeInt($nc(encoded)->length);
				oos->write(encoded);
			} catch ($CertificateEncodingException& cee) {
				$throwNew($IOException, $(cee->getMessage()));
			}
		}
	}
	if (this->signers != nullptr && $nc(this->signers)->length > 0) {
		oos->writeObject(this->signers);
	}
}

void CodeSource::readObject($ObjectInputStream* ois) {
	$useLocalCurrentObjectStackCache();
	$var($CertificateFactory, cf, nullptr);
	$var($Hashtable, cfs, nullptr);
	$var($List, certList, nullptr);
	$nc(ois)->defaultReadObject();
	int32_t size = ois->readInt();
	if (size > 0) {
		$assign(cfs, $new($Hashtable, 3));
		$assign(certList, $new($ArrayList, size > 20 ? 20 : size));
	} else if (size < 0) {
		$throwNew($IOException, "size cannot be negative"_s);
	}
	for (int32_t i = 0; i < size; ++i) {
		$var($String, certType, ois->readUTF());
		if ($nc(cfs)->containsKey(certType)) {
			$assign(cf, $cast($CertificateFactory, cfs->get(certType)));
		} else {
			try {
				$assign(cf, $CertificateFactory::getInstance(certType));
			} catch ($CertificateException& ce) {
				$throwNew($ClassNotFoundException, $$str({"Certificate factory for "_s, certType, " not found"_s}));
			}
			cfs->put(certType, cf);
		}
		$var($bytes, encoded, $IOUtils::readExactlyNBytes(ois, ois->readInt()));
		$var($ByteArrayInputStream, bais, $new($ByteArrayInputStream, encoded));
		try {
			$nc(certList)->add($($nc(cf)->generateCertificate(bais)));
		} catch ($CertificateException& ce) {
			$throwNew($IOException, $(ce->getMessage()));
		}
		bais->close();
	}
	if (certList != nullptr) {
		$set(this, certs, $fcast($CertificateArray, certList->toArray($$new($CertificateArray, size))));
	}
	try {
		$set(this, signers, $cast($CodeSignerArray, $nc(($cast($CodeSignerArray, $(ois->readObject()))))->clone()));
	} catch ($IOException& ioe) {
	}
	if (this->location != nullptr) {
		$set(this, locationNoFragString, $URLUtil::urlNoFragString(this->location));
	}
}

$CodeSignerArray* CodeSource::convertCertArrayToSignerArray($CertificateArray* certs) {
	$useLocalCurrentObjectStackCache();
	if (certs == nullptr) {
		return nullptr;
	}
	try {
		if (this->factory == nullptr) {
			$set(this, factory, $CertificateFactory::getInstance("X.509"_s));
		}
		int32_t i = 0;
		$var($List, signers, $new($ArrayList));
		while (i < $nc(certs)->length) {
			$var($List, certChain, $new($ArrayList));
			certChain->add(certs->get(i++));
			int32_t j = i;
			while (j < certs->length && $instanceOf($X509Certificate, certs->get(j)) && $nc(($cast($X509Certificate, certs->get(j))))->getBasicConstraints() != -1) {
				certChain->add(certs->get(j));
				++j;
			}
			i = j;
			$var($CertPath, certPath, $nc(this->factory)->generateCertPath(certChain));
			signers->add($$new($CodeSigner, certPath, nullptr));
		}
		if (signers->isEmpty()) {
			return nullptr;
		} else {
			return $fcast($CodeSignerArray, signers->toArray($$new($CodeSignerArray, signers->size())));
		}
	} catch ($CertificateException& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

CodeSource::CodeSource() {
}

$Class* CodeSource::load$($String* name, bool initialize) {
	$loadClass(CodeSource, name, initialize, &_CodeSource_ClassInfo_, allocate$CodeSource);
	return class$;
}

$Class* CodeSource::class$ = nullptr;

	} // security
} // java