#include <sun/security/provider/PolicySpiFile.h>

#include <java/net/MalformedURLException.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/security/CodeSource.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/security/Policy$Parameters.h>
#include <java/security/PolicySpi.h>
#include <java/security/ProtectionDomain.h>
#include <java/security/URIParameter.h>
#include <sun/security/provider/PolicyFile.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URI = ::java::net::URI;
using $CodeSource = ::java::security::CodeSource;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $Policy$Parameters = ::java::security::Policy$Parameters;
using $PolicySpi = ::java::security::PolicySpi;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $URIParameter = ::java::security::URIParameter;
using $PolicyFile = ::sun::security::provider::PolicyFile;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _PolicySpiFile_FieldInfo_[] = {
	{"pf", "Lsun/security/provider/PolicyFile;", nullptr, $PRIVATE, $field(PolicySpiFile, pf)},
	{}
};

$MethodInfo _PolicySpiFile_MethodInfo_[] = {
	{"<init>", "(Ljava/security/Policy$Parameters;)V", nullptr, $PUBLIC, $method(PolicySpiFile, init$, void, $Policy$Parameters*)},
	{"engineGetPermissions", "(Ljava/security/CodeSource;)Ljava/security/PermissionCollection;", nullptr, $PROTECTED, $virtualMethod(PolicySpiFile, engineGetPermissions, $PermissionCollection*, $CodeSource*)},
	{"engineGetPermissions", "(Ljava/security/ProtectionDomain;)Ljava/security/PermissionCollection;", nullptr, $PROTECTED, $virtualMethod(PolicySpiFile, engineGetPermissions, $PermissionCollection*, $ProtectionDomain*)},
	{"engineImplies", "(Ljava/security/ProtectionDomain;Ljava/security/Permission;)Z", nullptr, $PROTECTED, $virtualMethod(PolicySpiFile, engineImplies, bool, $ProtectionDomain*, $Permission*)},
	{"engineRefresh", "()V", nullptr, $PROTECTED, $virtualMethod(PolicySpiFile, engineRefresh, void)},
	{}
};

$ClassInfo _PolicySpiFile_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.provider.PolicySpiFile",
	"java.security.PolicySpi",
	nullptr,
	_PolicySpiFile_FieldInfo_,
	_PolicySpiFile_MethodInfo_
};

$Object* allocate$PolicySpiFile($Class* clazz) {
	return $of($alloc(PolicySpiFile));
}

void PolicySpiFile::init$($Policy$Parameters* params) {
	$useLocalCurrentObjectStackCache();
	$PolicySpi::init$();
	if (params == nullptr) {
		$set(this, pf, $new($PolicyFile));
	} else {
		if (!($instanceOf($URIParameter, params))) {
			$throwNew($IllegalArgumentException, $$str({"Unrecognized policy parameter: "_s, params}));
		}
		$var($URIParameter, uriParam, $cast($URIParameter, params));
		try {
			$set(this, pf, $new($PolicyFile, $($nc($($nc(uriParam)->getURI()))->toURL())));
		} catch ($MalformedURLException& mue) {
			$throwNew($IllegalArgumentException, "Invalid URIParameter"_s, mue);
		}
	}
}

$PermissionCollection* PolicySpiFile::engineGetPermissions($CodeSource* codesource) {
	return $nc(this->pf)->getPermissions(codesource);
}

$PermissionCollection* PolicySpiFile::engineGetPermissions($ProtectionDomain* d) {
	return $nc(this->pf)->getPermissions(d);
}

bool PolicySpiFile::engineImplies($ProtectionDomain* d, $Permission* p) {
	return $nc(this->pf)->implies(d, p);
}

void PolicySpiFile::engineRefresh() {
	$nc(this->pf)->refresh();
}

PolicySpiFile::PolicySpiFile() {
}

$Class* PolicySpiFile::load$($String* name, bool initialize) {
	$loadClass(PolicySpiFile, name, initialize, &_PolicySpiFile_ClassInfo_, allocate$PolicySpiFile);
	return class$;
}

$Class* PolicySpiFile::class$ = nullptr;

		} // provider
	} // security
} // sun