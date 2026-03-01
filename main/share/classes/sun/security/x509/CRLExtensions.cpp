#include <sun/security/x509/CRLExtensions.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/security/cert/CRLException.h>
#include <java/security/cert/CertificateException.h>
#include <java/util/AbstractMap.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/Map.h>
#include <java/util/TreeMap.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/CertAttrSet.h>
#include <sun/security/x509/Extension.h>
#include <sun/security/x509/OIDMap.h>
#include <sun/security/x509/X509AttributeName.h>
#include <sun/security/x509/X509CertImpl.h>
#include <jcpp.h>

#undef NAME
#undef PARAMS
#undef TAG_CONTEXT

using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Constructor = ::java::lang::reflect::Constructor;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $CRLException = ::java::security::cert::CRLException;
using $CertificateException = ::java::security::cert::CertificateException;
using $AbstractMap = ::java::util::AbstractMap;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $Map = ::java::util::Map;
using $TreeMap = ::java::util::TreeMap;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $CertAttrSet = ::sun::security::x509::CertAttrSet;
using $Extension = ::sun::security::x509::Extension;
using $OIDMap = ::sun::security::x509::OIDMap;
using $X509AttributeName = ::sun::security::x509::X509AttributeName;
using $X509CertImpl = ::sun::security::x509::X509CertImpl;

namespace sun {
	namespace security {
		namespace x509 {

$FieldInfo _CRLExtensions_FieldInfo_[] = {
	{"map", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Lsun/security/x509/Extension;>;", $PRIVATE, $field(CRLExtensions, map)},
	{"unsupportedCritExt", "Z", nullptr, $PRIVATE, $field(CRLExtensions, unsupportedCritExt)},
	{"PARAMS", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(CRLExtensions, PARAMS)},
	{}
};

$MethodInfo _CRLExtensions_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CRLExtensions, init$, void)},
	{"<init>", "(Lsun/security/util/DerInputStream;)V", nullptr, $PUBLIC, $method(CRLExtensions, init$, void, $DerInputStream*), "java.security.cert.CRLException"},
	{"delete", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(CRLExtensions, delete$, void, $String*)},
	{"encode", "(Ljava/io/OutputStream;Z)V", nullptr, $PUBLIC, $virtualMethod(CRLExtensions, encode, void, $OutputStream*, bool), "java.security.cert.CRLException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(CRLExtensions, equals, bool, Object$*)},
	{"get", "(Ljava/lang/String;)Lsun/security/x509/Extension;", nullptr, $PUBLIC, $virtualMethod(CRLExtensions, get, $Extension*, $String*)},
	{"getAllExtensions", "()Ljava/util/Collection;", "()Ljava/util/Collection<Lsun/security/x509/Extension;>;", $PUBLIC, $virtualMethod(CRLExtensions, getAllExtensions, $Collection*)},
	{"getElements", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Lsun/security/x509/Extension;>;", $PUBLIC, $virtualMethod(CRLExtensions, getElements, $Enumeration*)},
	{"hasUnsupportedCriticalExtension", "()Z", nullptr, $PUBLIC, $virtualMethod(CRLExtensions, hasUnsupportedCriticalExtension, bool)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(CRLExtensions, hashCode, int32_t)},
	{"init", "(Lsun/security/util/DerInputStream;)V", nullptr, $PRIVATE, $method(CRLExtensions, init, void, $DerInputStream*), "java.security.cert.CRLException"},
	{"parseExtension", "(Lsun/security/x509/Extension;)V", nullptr, $PRIVATE, $method(CRLExtensions, parseExtension, void, $Extension*), "java.security.cert.CRLException"},
	{"set", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(CRLExtensions, set, void, $String*, Object$*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CRLExtensions, toString, $String*)},
	{}
};

$ClassInfo _CRLExtensions_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.x509.CRLExtensions",
	"java.lang.Object",
	nullptr,
	_CRLExtensions_FieldInfo_,
	_CRLExtensions_MethodInfo_
};

$Object* allocate$CRLExtensions($Class* clazz) {
	return $of($alloc(CRLExtensions));
}

$ClassArray* CRLExtensions::PARAMS = nullptr;

void CRLExtensions::init$() {
	$set(this, map, $Collections::synchronizedMap(static_cast<$Map*>(static_cast<$AbstractMap*>($$new($TreeMap)))));
	this->unsupportedCritExt = false;
}

void CRLExtensions::init$($DerInputStream* in) {
	$set(this, map, $Collections::synchronizedMap(static_cast<$Map*>(static_cast<$AbstractMap*>($$new($TreeMap)))));
	this->unsupportedCritExt = false;
	init(in);
}

void CRLExtensions::init($DerInputStream* derStrm) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($DerInputStream, str, derStrm);
		int8_t nextByte = (int8_t)$nc(derStrm)->peekByte();
		if ((((int32_t)(nextByte & (uint32_t)192)) == 128) && (((int32_t)(nextByte & (uint32_t)31)) == 0)) {
			$var($DerValue, val, $nc(str)->getDerValue());
			$assign(str, $nc(val)->data$);
		}
		$var($DerValueArray, exts, $nc(str)->getSequence(5));
		for (int32_t i = 0; i < $nc(exts)->length; ++i) {
			$var($Extension, ext, $new($Extension, exts->get(i)));
			parseExtension(ext);
		}
	} catch ($IOException& e) {
		$throwNew($CRLException, $$str({"Parsing error: "_s, $(e->toString())}));
	}
}

void CRLExtensions::parseExtension($Extension* ext) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$Class* extClass = $OIDMap::getClass($($nc(ext)->getExtensionId()));
		if (extClass == nullptr) {
			if ($nc(ext)->isCritical()) {
				this->unsupportedCritExt = true;
			}
			if ($nc(this->map)->put($($nc($($nc(ext)->getExtensionId()))->toString()), ext) != nullptr) {
				$throwNew($CRLException, "Duplicate extensions not allowed"_s);
			}
			return;
		}
		$var($Constructor, cons, $nc(extClass)->getConstructor(CRLExtensions::PARAMS));
		$var($ObjectArray, passed, $new($ObjectArray, {
			$($of($Boolean::valueOf($nc(ext)->isCritical()))),
			$($of($nc(ext)->getExtensionValue()))
		}));
		$var($CertAttrSet, crlExt, $cast($CertAttrSet, $nc(cons)->newInstance(passed)));
		if ($nc(this->map)->put($($nc(crlExt)->getName()), $cast($Extension, crlExt)) != nullptr) {
			$throwNew($CRLException, "Duplicate extensions not allowed"_s);
		}
	} catch ($InvocationTargetException& invk) {
		$throwNew($CRLException, $($nc($(invk->getCause()))->getMessage()));
	} catch ($Exception& e) {
		$throwNew($CRLException, $(e->toString()));
	}
}

void CRLExtensions::encode($OutputStream* out, bool isExplicit) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($DerOutputStream, extOut, $new($DerOutputStream));
		$var($Collection, allExts, $nc(this->map)->values());
		$var($ObjectArray, objs, $nc(allExts)->toArray());
		for (int32_t i = 0; i < $nc(objs)->length; ++i) {
			if ($instanceOf($CertAttrSet, objs->get(i))) {
				$nc(($cast($CertAttrSet, objs->get(i))))->encode(extOut);
			} else if ($instanceOf($Extension, objs->get(i))) {
				$nc(($cast($Extension, objs->get(i))))->encode(extOut);
			} else {
				$throwNew($CRLException, "Illegal extension object"_s);
			}
		}
		$var($DerOutputStream, seq, $new($DerOutputStream));
		seq->write($DerValue::tag_Sequence, extOut);
		$var($DerOutputStream, tmp, $new($DerOutputStream));
		if (isExplicit) {
			tmp->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), seq);
		} else {
			$assign(tmp, seq);
		}
		$nc(out)->write($(tmp->toByteArray()));
	} catch ($IOException& e) {
		$throwNew($CRLException, $$str({"Encoding error: "_s, $(e->toString())}));
	} catch ($CertificateException& e) {
		$throwNew($CRLException, $$str({"Encoding error: "_s, $(e->toString())}));
	}
}

$Extension* CRLExtensions::get($String* alias) {
	$useLocalCurrentObjectStackCache();
	$var($X509AttributeName, attr, $new($X509AttributeName, alias));
	$var($String, name, nullptr);
	$var($String, id, attr->getPrefix());
	$init($X509CertImpl);
	if ($nc(id)->equalsIgnoreCase($X509CertImpl::NAME)) {
		int32_t index = $nc(alias)->lastIndexOf((int32_t)u'.');
		$assign(name, alias->substring(index + 1));
	} else {
		$assign(name, alias);
	}
	return $cast($Extension, $nc(this->map)->get(name));
}

void CRLExtensions::set($String* alias, Object$* obj) {
	$nc(this->map)->put(alias, $cast($Extension, obj));
}

void CRLExtensions::delete$($String* alias) {
	$nc(this->map)->remove(alias);
}

$Enumeration* CRLExtensions::getElements() {
	return $Collections::enumeration($($nc(this->map)->values()));
}

$Collection* CRLExtensions::getAllExtensions() {
	return $nc(this->map)->values();
}

bool CRLExtensions::hasUnsupportedCriticalExtension() {
	return this->unsupportedCritExt;
}

bool CRLExtensions::equals(Object$* other) {
	$useLocalCurrentObjectStackCache();
	if ($equals(this, other)) {
		return true;
	}
	if (!($instanceOf(CRLExtensions, other))) {
		return false;
	}
	$var($Collection, otherC, $nc(($cast(CRLExtensions, other)))->getAllExtensions());
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
	return true;
}

int32_t CRLExtensions::hashCode() {
	return $nc(this->map)->hashCode();
}

$String* CRLExtensions::toString() {
	return $nc($of(this->map))->toString();
}

void clinit$CRLExtensions($Class* class$) {
	$load($Boolean);
	$assignStatic(CRLExtensions::PARAMS, $new($ClassArray, {
		$Boolean::class$,
		$Object::class$
	}));
}

CRLExtensions::CRLExtensions() {
}

$Class* CRLExtensions::load$($String* name, bool initialize) {
	$loadClass(CRLExtensions, name, initialize, &_CRLExtensions_ClassInfo_, clinit$CRLExtensions, allocate$CRLExtensions);
	return class$;
}

$Class* CRLExtensions::class$ = nullptr;

		} // x509
	} // security
} // sun