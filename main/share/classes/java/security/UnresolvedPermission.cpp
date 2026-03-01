#include <java/security/UnresolvedPermission.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/reflect/Constructor.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/security/UnresolvedPermissionCollection.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateEncodingException.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/CertificateFactory.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/ArrayList.h>
#include <java/util/Hashtable.h>
#include <java/util/List.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/IOUtils.h>
#include <jcpp.h>

#undef PARAMS0
#undef PARAMS1
#undef PARAMS2

using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $NullPointerException = ::java::lang::NullPointerException;
using $Constructor = ::java::lang::reflect::Constructor;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $UnresolvedPermissionCollection = ::java::security::UnresolvedPermissionCollection;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateEncodingException = ::java::security::cert::CertificateEncodingException;
using $CertificateException = ::java::security::cert::CertificateException;
using $CertificateFactory = ::java::security::cert::CertificateFactory;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $ArrayList = ::java::util::ArrayList;
using $Hashtable = ::java::util::Hashtable;
using $List = ::java::util::List;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $Debug = ::sun::security::util::Debug;
using $IOUtils = ::sun::security::util::IOUtils;

namespace java {
	namespace security {

$FieldInfo _UnresolvedPermission_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnresolvedPermission, serialVersionUID)},
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnresolvedPermission, debug)},
	{"type", "Ljava/lang/String;", nullptr, $PRIVATE, $field(UnresolvedPermission, type)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE, $field(UnresolvedPermission, name)},
	{"actions", "Ljava/lang/String;", nullptr, $PRIVATE, $field(UnresolvedPermission, actions)},
	{"certs", "[Ljava/security/cert/Certificate;", nullptr, $PRIVATE | $TRANSIENT, $field(UnresolvedPermission, certs)},
	{"PARAMS0", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(UnresolvedPermission, PARAMS0)},
	{"PARAMS1", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(UnresolvedPermission, PARAMS1)},
	{"PARAMS2", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(UnresolvedPermission, PARAMS2)},
	{}
};

$MethodInfo _UnresolvedPermission_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC, $method(UnresolvedPermission, init$, void, $String*, $String*, $String*, $CertificateArray*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(UnresolvedPermission, equals, bool, Object$*)},
	{"getActions", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(UnresolvedPermission, getActions, $String*)},
	{"getUnresolvedActions", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(UnresolvedPermission, getUnresolvedActions, $String*)},
	{"getUnresolvedCerts", "()[Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $method(UnresolvedPermission, getUnresolvedCerts, $CertificateArray*)},
	{"getUnresolvedName", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(UnresolvedPermission, getUnresolvedName, $String*)},
	{"getUnresolvedType", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(UnresolvedPermission, getUnresolvedType, $String*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(UnresolvedPermission, hashCode, int32_t)},
	{"implies", "(Ljava/security/Permission;)Z", nullptr, $PUBLIC, $virtualMethod(UnresolvedPermission, implies, bool, $Permission*)},
	{"newPermissionCollection", "()Ljava/security/PermissionCollection;", nullptr, $PUBLIC, $virtualMethod(UnresolvedPermission, newPermissionCollection, $PermissionCollection*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(UnresolvedPermission, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"resolve", "(Ljava/security/Permission;[Ljava/security/cert/Certificate;)Ljava/security/Permission;", nullptr, 0, $method(UnresolvedPermission, resolve, $Permission*, $Permission*, $CertificateArray*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(UnresolvedPermission, toString, $String*)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(UnresolvedPermission, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$ClassInfo _UnresolvedPermission_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.security.UnresolvedPermission",
	"java.security.Permission",
	nullptr,
	_UnresolvedPermission_FieldInfo_,
	_UnresolvedPermission_MethodInfo_
};

$Object* allocate$UnresolvedPermission($Class* clazz) {
	return $of($alloc(UnresolvedPermission));
}

$Debug* UnresolvedPermission::debug = nullptr;
$ClassArray* UnresolvedPermission::PARAMS0 = nullptr;
$ClassArray* UnresolvedPermission::PARAMS1 = nullptr;
$ClassArray* UnresolvedPermission::PARAMS2 = nullptr;

void UnresolvedPermission::init$($String* type, $String* name, $String* actions, $CertificateArray* certs) {
	$useLocalCurrentObjectStackCache();
	$Permission::init$(type);
	if (type == nullptr) {
		$throwNew($NullPointerException, "type can\'t be null"_s);
	}
	$set(this, type, type);
	$set(this, name, name);
	$set(this, actions, actions);
	if (certs != nullptr) {
		for (int32_t i = 0; i < certs->length; ++i) {
			if (!($instanceOf($X509Certificate, certs->get(i)))) {
				$set(this, certs, $cast($CertificateArray, certs->clone()));
				break;
			}
		}
		if (this->certs == nullptr) {
			int32_t i = 0;
			int32_t count = 0;
			while (i < certs->length) {
				++count;
				while (((i + 1) < certs->length) && $nc($($nc(($cast($X509Certificate, certs->get(i))))->getIssuerX500Principal()))->equals($($nc(($cast($X509Certificate, certs->get(i + 1))))->getSubjectX500Principal()))) {
					++i;
				}
				++i;
			}
			if (count == certs->length) {
				$set(this, certs, $cast($CertificateArray, certs->clone()));
			}
			if (this->certs == nullptr) {
				$var($ArrayList, signerCerts, $new($ArrayList));
				i = 0;
				while (i < certs->length) {
					signerCerts->add(certs->get(i));
					while (((i + 1) < certs->length) && $nc($($nc(($cast($X509Certificate, certs->get(i))))->getIssuerX500Principal()))->equals($($nc(($cast($X509Certificate, certs->get(i + 1))))->getSubjectX500Principal()))) {
						++i;
					}
					++i;
				}
				$set(this, certs, $new($CertificateArray, signerCerts->size()));
				signerCerts->toArray(this->certs);
			}
		}
	}
}

$Permission* UnresolvedPermission::resolve($Permission* p, $CertificateArray* certs) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->certs != nullptr) {
		if (certs == nullptr) {
			return nullptr;
		}
		bool match = false;
		for (int32_t i = 0; i < $nc(this->certs)->length; ++i) {
			match = false;
			for (int32_t j = 0; j < $nc(certs)->length; ++j) {
				if ($nc($nc(this->certs)->get(i))->equals(certs->get(j))) {
					match = true;
					break;
				}
			}
			if (!match) {
				return nullptr;
			}
		}
	}
	try {
		$Class* pc = $nc($of(p))->getClass();
		if (this->name == nullptr && this->actions == nullptr) {
			try {
				$var($Constructor, c, $nc(pc)->getConstructor(UnresolvedPermission::PARAMS0));
				return $cast($Permission, $nc(c)->newInstance($$new($ObjectArray, 0)));
			} catch ($NoSuchMethodException& ne) {
				try {
					$var($Constructor, c, $nc(pc)->getConstructor(UnresolvedPermission::PARAMS1));
					return $cast($Permission, $nc(c)->newInstance($$new($ObjectArray, {$of(this->name)})));
				} catch ($NoSuchMethodException& ne1) {
					$var($Constructor, c, $nc(pc)->getConstructor(UnresolvedPermission::PARAMS2));
					return $cast($Permission, $nc(c)->newInstance($$new($ObjectArray, {
						$of(this->name),
						$of(this->actions)
					})));
				}
			}
		} else if (this->name != nullptr && this->actions == nullptr) {
			try {
				$var($Constructor, c, $nc(pc)->getConstructor(UnresolvedPermission::PARAMS1));
				return $cast($Permission, $nc(c)->newInstance($$new($ObjectArray, {$of(this->name)})));
			} catch ($NoSuchMethodException& ne) {
				$var($Constructor, c, $nc(pc)->getConstructor(UnresolvedPermission::PARAMS2));
				return $cast($Permission, $nc(c)->newInstance($$new($ObjectArray, {
					$of(this->name),
					$of(this->actions)
				})));
			}
		} else {
			$var($Constructor, c, $nc(pc)->getConstructor(UnresolvedPermission::PARAMS2));
			return $cast($Permission, $nc(c)->newInstance($$new($ObjectArray, {
				$of(this->name),
				$of(this->actions)
			})));
		}
	} catch ($NoSuchMethodException& nsme) {
		if (UnresolvedPermission::debug != nullptr) {
			$nc(UnresolvedPermission::debug)->println($$str({"NoSuchMethodException:\n  could not find proper constructor for "_s, this->type}));
			nsme->printStackTrace();
		}
		return nullptr;
	} catch ($Exception& e) {
		if (UnresolvedPermission::debug != nullptr) {
			$nc(UnresolvedPermission::debug)->println($$str({"unable to instantiate "_s, this->name}));
			e->printStackTrace();
		}
		return nullptr;
	}
	$shouldNotReachHere();
}

bool UnresolvedPermission::implies($Permission* p) {
	return false;
}

bool UnresolvedPermission::equals(Object$* obj) {
	if ($equals(obj, this)) {
		return true;
	}
	$var(UnresolvedPermission, that, nullptr);
	bool var$0 = $instanceOf(UnresolvedPermission, obj);
	if (var$0) {
		$assign(that, $cast(UnresolvedPermission, obj));
		var$0 = true;
	}
	if (!(var$0)) {
		return false;
	}
	if (!$nc(this->type)->equals($nc(that)->type)) {
		return false;
	}
	if (this->name == nullptr) {
		if ($nc(that)->name != nullptr) {
			return false;
		}
	} else if (!$nc(this->name)->equals($nc(that)->name)) {
		return false;
	}
	if (this->actions == nullptr) {
		if ($nc(that)->actions != nullptr) {
			return false;
		}
	} else if (!$nc(this->actions)->equals($nc(that)->actions)) {
		return false;
	}
	if ((this->certs == nullptr && $nc(that)->certs != nullptr) || (this->certs != nullptr && $nc(that)->certs == nullptr) || (this->certs != nullptr && $nc(that)->certs != nullptr && $nc(this->certs)->length != $nc(that->certs)->length)) {
		return false;
	}
	int32_t i = 0;
	int32_t j = 0;
	bool match = false;
	for (i = 0; this->certs != nullptr && i < $nc(this->certs)->length; ++i) {
		match = false;
		for (j = 0; j < $nc($nc(that)->certs)->length; ++j) {
			if ($nc($nc(this->certs)->get(i))->equals($nc(that->certs)->get(j))) {
				match = true;
				break;
			}
		}
		if (!match) {
			return false;
		}
	}
	for (i = 0; $nc(that)->certs != nullptr && i < $nc(that->certs)->length; ++i) {
		match = false;
		for (j = 0; j < $nc(this->certs)->length; ++j) {
			if ($nc($nc(that->certs)->get(i))->equals($nc(this->certs)->get(j))) {
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

int32_t UnresolvedPermission::hashCode() {
	int32_t hash = $nc(this->type)->hashCode();
	if (this->name != nullptr) {
		hash ^= $nc(this->name)->hashCode();
	}
	if (this->actions != nullptr) {
		hash ^= $nc(this->actions)->hashCode();
	}
	return hash;
}

$String* UnresolvedPermission::getActions() {
	return ""_s;
}

$String* UnresolvedPermission::getUnresolvedType() {
	return this->type;
}

$String* UnresolvedPermission::getUnresolvedName() {
	return this->name;
}

$String* UnresolvedPermission::getUnresolvedActions() {
	return this->actions;
}

$CertificateArray* UnresolvedPermission::getUnresolvedCerts() {
	return (this->certs == nullptr) ? ($CertificateArray*)nullptr : $cast($CertificateArray, $nc(this->certs)->clone());
}

$String* UnresolvedPermission::toString() {
	return $str({"(unresolved "_s, this->type, " "_s, this->name, " "_s, this->actions, ")"_s});
}

$PermissionCollection* UnresolvedPermission::newPermissionCollection() {
	return $new($UnresolvedPermissionCollection);
}

void UnresolvedPermission::writeObject($ObjectOutputStream* oos) {
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
}

void UnresolvedPermission::readObject($ObjectInputStream* ois) {
	$useLocalCurrentObjectStackCache();
	$var($CertificateFactory, cf, nullptr);
	$var($Hashtable, cfs, nullptr);
	$var($List, certList, nullptr);
	$nc(ois)->defaultReadObject();
	if (this->type == nullptr) {
		$throwNew($NullPointerException, "type can\'t be null"_s);
	}
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
}

void clinit$UnresolvedPermission($Class* class$) {
	$assignStatic(UnresolvedPermission::debug, $Debug::getInstance("policy,access"_s, "UnresolvedPermission"_s));
	$assignStatic(UnresolvedPermission::PARAMS0, $new($ClassArray, 0));
	$assignStatic(UnresolvedPermission::PARAMS1, $new($ClassArray, {$String::class$}));
	$assignStatic(UnresolvedPermission::PARAMS2, $new($ClassArray, {
		$String::class$,
		$String::class$
	}));
}

UnresolvedPermission::UnresolvedPermission() {
}

$Class* UnresolvedPermission::load$($String* name, bool initialize) {
	$loadClass(UnresolvedPermission, name, initialize, &_UnresolvedPermission_ClassInfo_, clinit$UnresolvedPermission, allocate$UnresolvedPermission);
	return class$;
}

$Class* UnresolvedPermission::class$ = nullptr;

	} // security
} // java