#include <sun/security/x509/X509Key.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/KeyFactory.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Provider.h>
#include <java/security/PublicKey.h>
#include <java/security/Security.h>
#include <java/security/spec/InvalidKeySpecException.h>
#include <java/security/spec/KeySpec.h>
#include <java/security/spec/X509EncodedKeySpec.h>
#include <java/util/Arrays.h>
#include <java/util/Properties.h>
#include <sun/security/util/BitArray.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <sun/security/x509/AlgorithmId.h>
#include <jcpp.h>

using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InstantiationException = ::java::lang::InstantiationException;
using $MethodInfo = ::java::lang::MethodInfo;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $KeyFactory = ::java::security::KeyFactory;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Provider = ::java::security::Provider;
using $PublicKey = ::java::security::PublicKey;
using $Security = ::java::security::Security;
using $InvalidKeySpecException = ::java::security::spec::InvalidKeySpecException;
using $KeySpec = ::java::security::spec::KeySpec;
using $X509EncodedKeySpec = ::java::security::spec::X509EncodedKeySpec;
using $Arrays = ::java::util::Arrays;
using $Properties = ::java::util::Properties;
using $BitArray = ::sun::security::util::BitArray;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;
using $AlgorithmId = ::sun::security::x509::AlgorithmId;

namespace sun {
	namespace security {
		namespace x509 {

$CompoundAttribute _X509Key_FieldAnnotations_key[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _X509Key_FieldAnnotations_unusedBits[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _X509Key_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(X509Key, serialVersionUID)},
	{"algid", "Lsun/security/x509/AlgorithmId;", nullptr, $PROTECTED, $field(X509Key, algid)},
	{"key", "[B", nullptr, $PROTECTED | $DEPRECATED, $field(X509Key, key), _X509Key_FieldAnnotations_key},
	{"unusedBits", "I", nullptr, $PRIVATE | $DEPRECATED, $field(X509Key, unusedBits), _X509Key_FieldAnnotations_unusedBits},
	{"bitStringKey", "Lsun/security/util/BitArray;", nullptr, $PRIVATE | $TRANSIENT, $field(X509Key, bitStringKey)},
	{"encodedKey", "[B", nullptr, $PROTECTED, $field(X509Key, encodedKey)},
	{}
};

$MethodInfo _X509Key_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(X509Key, init$, void)},
	{"<init>", "(Lsun/security/x509/AlgorithmId;Lsun/security/util/BitArray;)V", nullptr, $PRIVATE, $method(X509Key, init$, void, $AlgorithmId*, $BitArray*), "java.security.InvalidKeyException"},
	{"buildX509Key", "(Lsun/security/x509/AlgorithmId;Lsun/security/util/BitArray;)Ljava/security/PublicKey;", nullptr, $STATIC, $staticMethod(X509Key, buildX509Key, $PublicKey*, $AlgorithmId*, $BitArray*), "java.io.IOException,java.security.InvalidKeyException"},
	{"decode", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $virtualMethod(X509Key, decode, void, $InputStream*), "java.security.InvalidKeyException"},
	{"decode", "([B)V", nullptr, $PUBLIC, $virtualMethod(X509Key, decode, void, $bytes*), "java.security.InvalidKeyException"},
	{"encode", "(Lsun/security/util/DerOutputStream;)V", nullptr, $PUBLIC | $FINAL, $method(X509Key, encode, void, $DerOutputStream*), "java.io.IOException"},
	{"encode", "()[B", nullptr, $PUBLIC, $virtualMethod(X509Key, encode, $bytes*), "java.security.InvalidKeyException"},
	{"encode", "(Lsun/security/util/DerOutputStream;Lsun/security/x509/AlgorithmId;Lsun/security/util/BitArray;)V", nullptr, $STATIC, $staticMethod(X509Key, encode, void, $DerOutputStream*, $AlgorithmId*, $BitArray*), "java.io.IOException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(X509Key, equals, bool, Object$*)},
	{"getAlgorithm", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509Key, getAlgorithm, $String*)},
	{"getAlgorithmId", "()Lsun/security/x509/AlgorithmId;", nullptr, $PUBLIC, $virtualMethod(X509Key, getAlgorithmId, $AlgorithmId*)},
	{"getEncoded", "()[B", nullptr, $PUBLIC, $virtualMethod(X509Key, getEncoded, $bytes*)},
	{"getEncodedInternal", "()[B", nullptr, $PUBLIC, $virtualMethod(X509Key, getEncodedInternal, $bytes*), "java.security.InvalidKeyException"},
	{"getFormat", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509Key, getFormat, $String*)},
	{"getKey", "()Lsun/security/util/BitArray;", nullptr, $PROTECTED, $virtualMethod(X509Key, getKey, $BitArray*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(X509Key, hashCode, int32_t)},
	{"parse", "(Lsun/security/util/DerValue;)Ljava/security/PublicKey;", nullptr, $PUBLIC | $STATIC, $staticMethod(X509Key, parse, $PublicKey*, $DerValue*), "java.io.IOException"},
	{"parseKeyBits", "()V", nullptr, $PROTECTED, $virtualMethod(X509Key, parseKeyBits, void), "java.io.IOException,java.security.InvalidKeyException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(X509Key, readObject, void, $ObjectInputStream*), "java.io.IOException"},
	{"setKey", "(Lsun/security/util/BitArray;)V", nullptr, $PROTECTED, $virtualMethod(X509Key, setKey, void, $BitArray*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509Key, toString, $String*)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(X509Key, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$ClassInfo _X509Key_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.x509.X509Key",
	"java.lang.Object",
	"java.security.PublicKey",
	_X509Key_FieldInfo_,
	_X509Key_MethodInfo_
};

$Object* allocate$X509Key($Class* clazz) {
	return $of($alloc(X509Key));
}

void X509Key::init$() {
	$set(this, key, nullptr);
	this->unusedBits = 0;
	$set(this, bitStringKey, nullptr);
}

void X509Key::init$($AlgorithmId* algid, $BitArray* key) {
	$set(this, key, nullptr);
	this->unusedBits = 0;
	$set(this, bitStringKey, nullptr);
	$set(this, algid, algid);
	setKey(key);
	encode();
}

void X509Key::setKey($BitArray* key) {
	$set(this, bitStringKey, $cast($BitArray, $nc(key)->clone()));
	$set(this, key, key->toByteArray());
	int32_t remaining = key->length() % 8;
	this->unusedBits = ((remaining == 0) ? 0 : 8 - remaining);
}

$BitArray* X509Key::getKey() {
	$set(this, bitStringKey, $new($BitArray, $nc(this->key)->length * 8 - this->unusedBits, this->key));
	return $cast($BitArray, $nc(this->bitStringKey)->clone());
}

$PublicKey* X509Key::parse($DerValue* in) {
	$init(X509Key);
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmId, algorithm, nullptr);
	$var($PublicKey, subjectKey, nullptr);
	if ($nc(in)->tag != $DerValue::tag_Sequence) {
		$throwNew($IOException, "corrupt subject key"_s);
	}
	$assign(algorithm, $AlgorithmId::parse($($nc($nc(in)->data$)->getDerValue())));
	try {
		$assign(subjectKey, buildX509Key(algorithm, $($nc($nc(in)->data$)->getUnalignedBitString())));
	} catch ($InvalidKeyException& e) {
		$throwNew($IOException, $$str({"subject key, "_s, $(e->getMessage())}), e);
	}
	if ($nc($nc(in)->data$)->available() != 0) {
		$throwNew($IOException, "excess subject key"_s);
	}
	return subjectKey;
}

void X509Key::parseKeyBits() {
	encode();
}

$PublicKey* X509Key::buildX509Key($AlgorithmId* algid, $BitArray* key) {
	$init(X509Key);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($DerOutputStream, x509EncodedKeyStream, $new($DerOutputStream));
	encode(x509EncodedKeyStream, algid, key);
	$var($X509EncodedKeySpec, x509KeySpec, $new($X509EncodedKeySpec, $(x509EncodedKeyStream->toByteArray())));
	try {
		$var($KeyFactory, keyFac, $KeyFactory::getInstance($($nc(algid)->getName())));
		return $nc(keyFac)->generatePublic(x509KeySpec);
	} catch ($NoSuchAlgorithmException& e) {
	} catch ($InvalidKeySpecException& e) {
		$throwNew($InvalidKeyException, $(e->getMessage()), e);
	}
	$var($String, classname, ""_s);
	try {
		$var($Properties, props, nullptr);
		$var($String, keytype, nullptr);
		$var($Provider, sunProvider, nullptr);
		$assign(sunProvider, $Security::getProvider("SUN"_s));
		if (sunProvider == nullptr) {
			$throwNew($InstantiationException);
		}
		$assign(classname, $nc(sunProvider)->getProperty($$str({"PublicKey.X.509."_s, $($nc(algid)->getName())})));
		if (classname == nullptr) {
			$throwNew($InstantiationException);
		}
		$Class* keyClass = nullptr;
		try {
			keyClass = $Class::forName(classname);
		} catch ($ClassNotFoundException& e) {
			$var($ClassLoader, cl, $ClassLoader::getSystemClassLoader());
			if (cl != nullptr) {
				keyClass = cl->loadClass(classname);
			}
		}
		$var($Object, inst, (keyClass != nullptr) ? $nc(keyClass)->newInstance() : ($Object*)nullptr);
		$var(X509Key, result, nullptr);
		if ($instanceOf(X509Key, inst)) {
			$assign(result, $cast(X509Key, inst));
			$set($nc(result), algid, algid);
			result->setKey(key);
			result->parseKeyBits();
			return result;
		}
	} catch ($ClassNotFoundException& e) {
	} catch ($InstantiationException& e) {
	} catch ($IllegalAccessException& e) {
		$throwNew($IOException, $$str({classname, " [internal error]"_s}));
	}
	$var(X509Key, result, $new(X509Key, algid, key));
	return result;
}

$String* X509Key::getAlgorithm() {
	return $nc(this->algid)->getName();
}

$AlgorithmId* X509Key::getAlgorithmId() {
	return this->algid;
}

void X509Key::encode($DerOutputStream* out) {
	encode(out, this->algid, $(getKey()));
}

$bytes* X509Key::getEncoded() {
	try {
		return $cast($bytes, $nc($(getEncodedInternal()))->clone());
	} catch ($InvalidKeyException& e) {
	}
	return nullptr;
}

$bytes* X509Key::getEncodedInternal() {
	$useLocalCurrentObjectStackCache();
	$var($bytes, encoded, this->encodedKey);
	if (encoded == nullptr) {
		try {
			$var($DerOutputStream, out, $new($DerOutputStream));
			encode(out);
			$assign(encoded, out->toByteArray());
		} catch ($IOException& e) {
			$throwNew($InvalidKeyException, $$str({"IOException : "_s, $(e->getMessage())}));
		}
		$set(this, encodedKey, encoded);
	}
	return encoded;
}

$String* X509Key::getFormat() {
	return "X.509"_s;
}

$bytes* X509Key::encode() {
	return $cast($bytes, $nc($(getEncodedInternal()))->clone());
}

$String* X509Key::toString() {
	$useLocalCurrentObjectStackCache();
	$var($HexDumpEncoder, encoder, $new($HexDumpEncoder));
	$var($String, var$0, $$str({"algorithm = "_s, $($nc(this->algid)->toString()), ", unparsed keybits = \n"_s}));
	return $concat(var$0, $(encoder->encodeBuffer(this->key)));
}

void X509Key::decode($InputStream* in) {
	$useLocalCurrentObjectStackCache();
	$var($DerValue, val, nullptr);
	try {
		$assign(val, $new($DerValue, in));
		if (val->tag != $DerValue::tag_Sequence) {
			$throwNew($InvalidKeyException, "invalid key format"_s);
		}
		$set(this, algid, $AlgorithmId::parse($($nc(val->data$)->getDerValue())));
		setKey($($nc(val->data$)->getUnalignedBitString()));
		parseKeyBits();
		if ($nc(val->data$)->available() != 0) {
			$throwNew($InvalidKeyException, "excess key data"_s);
		}
	} catch ($IOException& e) {
		$throwNew($InvalidKeyException, $$str({"IOException: "_s, $(e->getMessage())}));
	}
}

void X509Key::decode($bytes* encodedKey) {
	decode(static_cast<$InputStream*>($$new($ByteArrayInputStream, encodedKey)));
}

void X509Key::writeObject($ObjectOutputStream* stream) {
	$nc(stream)->write($(getEncoded()));
}

void X509Key::readObject($ObjectInputStream* stream) {
	$useLocalCurrentObjectStackCache();
	try {
		decode(static_cast<$InputStream*>(stream));
	} catch ($InvalidKeyException& e) {
		e->printStackTrace();
		$throwNew($IOException, $$str({"deserialized key is invalid: "_s, $(e->getMessage())}));
	}
}

bool X509Key::equals(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	if ($equals(this, obj)) {
		return true;
	}
	if ($instanceOf($Key, obj) == false) {
		return false;
	}
	try {
		$var($bytes, thisEncoded, this->getEncodedInternal());
		$var($bytes, otherEncoded, nullptr);
		if ($instanceOf(X509Key, obj)) {
			$assign(otherEncoded, $nc(($cast(X509Key, obj)))->getEncodedInternal());
		} else {
			$assign(otherEncoded, $nc(($cast($Key, obj)))->getEncoded());
		}
		return $Arrays::equals(thisEncoded, otherEncoded);
	} catch ($InvalidKeyException& e) {
		return false;
	}
	$shouldNotReachHere();
}

int32_t X509Key::hashCode() {
	try {
		$var($bytes, b1, getEncodedInternal());
		int32_t r = $nc(b1)->length;
		for (int32_t i = 0; i < b1->length; ++i) {
			r += ((int32_t)(b1->get(i) & (uint32_t)255)) * 37;
		}
		return r;
	} catch ($InvalidKeyException& e) {
		return 0;
	}
	$shouldNotReachHere();
}

void X509Key::encode($DerOutputStream* out, $AlgorithmId* algid, $BitArray* key) {
	$init(X509Key);
	$var($DerOutputStream, tmp, $new($DerOutputStream));
	$nc(algid)->encode(tmp);
	tmp->putUnalignedBitString(key);
	$nc(out)->write($DerValue::tag_Sequence, tmp);
}

X509Key::X509Key() {
}

$Class* X509Key::load$($String* name, bool initialize) {
	$loadClass(X509Key, name, initialize, &_X509Key_ClassInfo_, allocate$X509Key);
	return class$;
}

$Class* X509Key::class$ = nullptr;

		} // x509
	} // security
} // sun