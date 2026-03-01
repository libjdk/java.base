#include <sun/security/x509/CertificateExtensions.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/security/cert/CertificateException.h>
#include <java/util/AbstractMap.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/TreeMap.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/CertAttrSet.h>
#include <sun/security/x509/Extension.h>
#include <sun/security/x509/OIDMap.h>
#include <sun/security/x509/UnparseableExtension.h>
#include <jcpp.h>

#undef IDENT
#undef NAME
#undef PARAMS
#undef TAG_CONTEXT

using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Constructor = ::java::lang::reflect::Constructor;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $CertificateException = ::java::security::cert::CertificateException;
using $AbstractMap = ::java::util::AbstractMap;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $TreeMap = ::java::util::TreeMap;
using $Debug = ::sun::security::util::Debug;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $CertAttrSet = ::sun::security::x509::CertAttrSet;
using $Extension = ::sun::security::x509::Extension;
using $OIDMap = ::sun::security::x509::OIDMap;
using $UnparseableExtension = ::sun::security::x509::UnparseableExtension;

namespace sun {
	namespace security {
		namespace x509 {

$FieldInfo _CertificateExtensions_FieldInfo_[] = {
	{"IDENT", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(CertificateExtensions, IDENT)},
	{"NAME", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(CertificateExtensions, NAME)},
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CertificateExtensions, debug)},
	{"map", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Lsun/security/x509/Extension;>;", $PRIVATE, $field(CertificateExtensions, map)},
	{"unsupportedCritExt", "Z", nullptr, $PRIVATE, $field(CertificateExtensions, unsupportedCritExt)},
	{"unparseableExtensions", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Lsun/security/x509/Extension;>;", $PRIVATE, $field(CertificateExtensions, unparseableExtensions)},
	{"PARAMS", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE | $STATIC, $staticField(CertificateExtensions, PARAMS)},
	{}
};

$MethodInfo _CertificateExtensions_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CertificateExtensions, init$, void)},
	{"<init>", "(Lsun/security/util/DerInputStream;)V", nullptr, $PUBLIC, $method(CertificateExtensions, init$, void, $DerInputStream*), "java.io.IOException"},
	{"delete", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(CertificateExtensions, delete$, void, $String*), "java.io.IOException"},
	{"encode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $virtualMethod(CertificateExtensions, encode, void, $OutputStream*), "java.security.cert.CertificateException,java.io.IOException"},
	{"encode", "(Ljava/io/OutputStream;Z)V", nullptr, $PUBLIC, $virtualMethod(CertificateExtensions, encode, void, $OutputStream*, bool), "java.security.cert.CertificateException,java.io.IOException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(CertificateExtensions, equals, bool, Object$*)},
	{"get", "(Ljava/lang/String;)Lsun/security/x509/Extension;", nullptr, $PUBLIC, $virtualMethod(CertificateExtensions, get, $Object*, $String*), "java.io.IOException"},
	{"getAllExtensions", "()Ljava/util/Collection;", "()Ljava/util/Collection<Lsun/security/x509/Extension;>;", $PUBLIC, $virtualMethod(CertificateExtensions, getAllExtensions, $Collection*)},
	{"getElements", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Lsun/security/x509/Extension;>;", $PUBLIC, $virtualMethod(CertificateExtensions, getElements, $Enumeration*)},
	{"getExtension", "(Ljava/lang/String;)Lsun/security/x509/Extension;", nullptr, 0, $virtualMethod(CertificateExtensions, getExtension, $Extension*, $String*)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CertificateExtensions, getName, $String*)},
	{"getNameByOid", "(Lsun/security/util/ObjectIdentifier;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CertificateExtensions, getNameByOid, $String*, $ObjectIdentifier*), "java.io.IOException"},
	{"getUnparseableExtensions", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Lsun/security/x509/Extension;>;", $PUBLIC, $virtualMethod(CertificateExtensions, getUnparseableExtensions, $Map*)},
	{"hasUnsupportedCriticalExtension", "()Z", nullptr, $PUBLIC, $virtualMethod(CertificateExtensions, hasUnsupportedCriticalExtension, bool)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(CertificateExtensions, hashCode, int32_t)},
	{"init", "(Lsun/security/util/DerInputStream;)V", nullptr, $PRIVATE, $method(CertificateExtensions, init, void, $DerInputStream*), "java.io.IOException"},
	{"parseExtension", "(Lsun/security/x509/Extension;)V", nullptr, $PRIVATE, $method(CertificateExtensions, parseExtension, void, $Extension*), "java.io.IOException"},
	{"set", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(CertificateExtensions, set, void, $String*, Object$*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CertificateExtensions, toString, $String*)},
	{}
};

$ClassInfo _CertificateExtensions_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.x509.CertificateExtensions",
	"java.lang.Object",
	"sun.security.x509.CertAttrSet",
	_CertificateExtensions_FieldInfo_,
	_CertificateExtensions_MethodInfo_,
	"Ljava/lang/Object;Lsun/security/x509/CertAttrSet<Lsun/security/x509/Extension;>;"
};

$Object* allocate$CertificateExtensions($Class* clazz) {
	return $of($alloc(CertificateExtensions));
}

$String* CertificateExtensions::IDENT = nullptr;
$String* CertificateExtensions::NAME = nullptr;
$Debug* CertificateExtensions::debug = nullptr;
$ClassArray* CertificateExtensions::PARAMS = nullptr;

void CertificateExtensions::init$() {
	$set(this, map, $Collections::synchronizedMap(static_cast<$Map*>(static_cast<$AbstractMap*>($$new($TreeMap)))));
	this->unsupportedCritExt = false;
}

void CertificateExtensions::init$($DerInputStream* in) {
	$set(this, map, $Collections::synchronizedMap(static_cast<$Map*>(static_cast<$AbstractMap*>($$new($TreeMap)))));
	this->unsupportedCritExt = false;
	init(in);
}

void CertificateExtensions::init($DerInputStream* in) {
	$useLocalCurrentObjectStackCache();
	$var($DerValueArray, exts, $nc(in)->getSequence(5));
	for (int32_t i = 0; i < $nc(exts)->length; ++i) {
		$var($Extension, ext, $new($Extension, exts->get(i)));
		parseExtension(ext);
	}
}

void CertificateExtensions::parseExtension($Extension* ext) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$Class* extClass = $OIDMap::getClass($($nc(ext)->getExtensionId()));
		if (extClass == nullptr) {
			if ($nc(ext)->isCritical()) {
				this->unsupportedCritExt = true;
			}
			if ($nc(this->map)->put($($nc($($nc(ext)->getExtensionId()))->toString()), ext) == nullptr) {
				return;
			} else {
				$throwNew($IOException, "Duplicate extensions not allowed"_s);
			}
		}
		$var($Constructor, cons, $nc(extClass)->getConstructor(CertificateExtensions::PARAMS));
		$var($ObjectArray, passed, $new($ObjectArray, {
			$($of($Boolean::valueOf($nc(ext)->isCritical()))),
			$($of($nc(ext)->getExtensionValue()))
		}));
		$var($CertAttrSet, certExt, $cast($CertAttrSet, $nc(cons)->newInstance(passed)));
		if ($nc(this->map)->put($($nc(certExt)->getName()), $cast($Extension, certExt)) != nullptr) {
			$throwNew($IOException, "Duplicate extensions not allowed"_s);
		}
	} catch ($InvocationTargetException& invk) {
		$var($Throwable, e, invk->getCause());
		if ($nc(ext)->isCritical() == false) {
			if (this->unparseableExtensions == nullptr) {
				$set(this, unparseableExtensions, static_cast<$Map*>(static_cast<$AbstractMap*>($new($TreeMap))));
			}
			$var($Object, var$0, $of($nc($(ext->getExtensionId()))->toString()));
			$nc(this->unparseableExtensions)->put(var$0, $$new($UnparseableExtension, ext, e));
			if (CertificateExtensions::debug != nullptr) {
				$nc(CertificateExtensions::debug)->println($$str({"Debug info only. Error parsing extension: "_s, ext}));
				$nc(e)->printStackTrace();
				$var($HexDumpEncoder, h, $new($HexDumpEncoder));
				$nc($System::err)->println($(h->encodeBuffer($(ext->getExtensionValue()))));
			}
			return;
		}
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		} else {
			$throwNew($IOException, e);
		}
	} catch ($IOException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($IOException, static_cast<$Throwable*>(e));
	}
}

void CertificateExtensions::encode($OutputStream* out) {
	encode(out, false);
}

void CertificateExtensions::encode($OutputStream* out, bool isCertReq) {
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, extOut, $new($DerOutputStream));
	$var($Collection, allExts, $nc(this->map)->values());
	$var($ObjectArray, objs, $nc(allExts)->toArray());
	for (int32_t i = 0; i < $nc(objs)->length; ++i) {
		if ($instanceOf($CertAttrSet, objs->get(i))) {
			$nc(($cast($CertAttrSet, objs->get(i))))->encode(extOut);
		} else if ($instanceOf($Extension, objs->get(i))) {
			$nc(($cast($Extension, objs->get(i))))->encode(extOut);
		} else {
			$throwNew($CertificateException, "Illegal extension object"_s);
		}
	}
	$var($DerOutputStream, seq, $new($DerOutputStream));
	seq->write($DerValue::tag_Sequence, extOut);
	$var($DerOutputStream, tmp, nullptr);
	if (!isCertReq) {
		$assign(tmp, $new($DerOutputStream));
		tmp->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3), seq);
	} else {
		$assign(tmp, seq);
	}
	$nc(out)->write($($nc(tmp)->toByteArray()));
}

void CertificateExtensions::set($String* name, Object$* obj) {
	if ($instanceOf($Extension, obj)) {
		$nc(this->map)->put(name, $cast($Extension, obj));
	} else {
		$throwNew($IOException, "Unknown extension type."_s);
	}
}

$Object* CertificateExtensions::get($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($Extension, obj, $cast($Extension, $nc(this->map)->get(name)));
	if (obj == nullptr) {
		$throwNew($IOException, $$str({"No extension found with name "_s, name}));
	}
	return $of((obj));
}

$Extension* CertificateExtensions::getExtension($String* name) {
	return $cast($Extension, $nc(this->map)->get(name));
}

void CertificateExtensions::delete$($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($Object, obj, $nc(this->map)->get(name));
	if (obj == nullptr) {
		$throwNew($IOException, $$str({"No extension found with name "_s, name}));
	}
	$nc(this->map)->remove(name);
}

$String* CertificateExtensions::getNameByOid($ObjectIdentifier* oid) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($($nc(this->map)->keySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, name, $cast($String, i$->next()));
			{
				if ($nc($($nc(($cast($Extension, $($nc(this->map)->get(name)))))->getExtensionId()))->equals(oid)) {
					return name;
				}
			}
		}
	}
	return nullptr;
}

$Enumeration* CertificateExtensions::getElements() {
	return $Collections::enumeration($($nc(this->map)->values()));
}

$Collection* CertificateExtensions::getAllExtensions() {
	return $nc(this->map)->values();
}

$Map* CertificateExtensions::getUnparseableExtensions() {
	if (this->unparseableExtensions == nullptr) {
		return $Collections::emptyMap();
	} else {
		return this->unparseableExtensions;
	}
}

$String* CertificateExtensions::getName() {
	return CertificateExtensions::NAME;
}

bool CertificateExtensions::hasUnsupportedCriticalExtension() {
	return this->unsupportedCritExt;
}

bool CertificateExtensions::equals(Object$* other) {
	$useLocalCurrentObjectStackCache();
	if ($equals(this, other)) {
		return true;
	}
	if (!($instanceOf(CertificateExtensions, other))) {
		return false;
	}
	$var($Collection, otherC, $nc(($cast(CertificateExtensions, other)))->getAllExtensions());
	$var($ObjectArray, objs, $nc(otherC)->toArray());
	int32_t len = $nc(objs)->length;
	if (len != $nc(this->map)->size()) {
		return false;
	}
	$var($Extension, otherExt, nullptr);
	$var($Extension, thisExt, nullptr);
	$var($String, key, nullptr);
	for (int32_t i = 0; i < len; ++i) {
		if ($instanceOf($CertAttrSet, objs->get(i))) {
			$assign(key, $nc(($cast($CertAttrSet, objs->get(i))))->getName());
		}
		$assign(otherExt, $cast($Extension, objs->get(i)));
		if (key == nullptr) {
			$assign(key, $nc($($nc(otherExt)->getExtensionId()))->toString());
		}
		$assign(thisExt, $cast($Extension, $nc(this->map)->get(key)));
		if (thisExt == nullptr) {
			return false;
		}
		if (!$nc(thisExt)->equals(otherExt)) {
			return false;
		}
	}
	return $nc($(this->getUnparseableExtensions()))->equals($(($cast(CertificateExtensions, other))->getUnparseableExtensions()));
}

int32_t CertificateExtensions::hashCode() {
	int32_t var$0 = $nc(this->map)->hashCode();
	return var$0 + $nc($(getUnparseableExtensions()))->hashCode();
}

$String* CertificateExtensions::toString() {
	return $nc($of(this->map))->toString();
}

void clinit$CertificateExtensions($Class* class$) {
	$assignStatic(CertificateExtensions::IDENT, "x509.info.extensions"_s);
	$assignStatic(CertificateExtensions::NAME, "extensions"_s);
	$assignStatic(CertificateExtensions::debug, $Debug::getInstance("x509"_s));
	$load($Boolean);
	$assignStatic(CertificateExtensions::PARAMS, $new($ClassArray, {
		$Boolean::class$,
		$Object::class$
	}));
}

CertificateExtensions::CertificateExtensions() {
}

$Class* CertificateExtensions::load$($String* name, bool initialize) {
	$loadClass(CertificateExtensions, name, initialize, &_CertificateExtensions_ClassInfo_, clinit$CertificateExtensions, allocate$CertificateExtensions);
	return class$;
}

$Class* CertificateExtensions::class$ = nullptr;

		} // x509
	} // security
} // sun