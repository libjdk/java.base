#include <sun/security/provider/PolicyFile$5.h>

#include <java/net/SocketPermission.h>
#include <java/net/URL.h>
#include <java/security/CodeSource.h>
#include <java/security/Permission.h>
#include <java/security/cert/Certificate.h>
#include <java/util/List.h>
#include <java/util/PropertyPermission.h>
#include <sun/security/provider/PolicyFile$PolicyEntry.h>
#include <sun/security/provider/PolicyFile$PolicyInfo.h>
#include <sun/security/provider/PolicyFile.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef LOCAL_LISTEN_PERMISSION
#undef PROPERTY_READ_ACTION

using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $URL = ::java::net::URL;
using $CodeSource = ::java::security::CodeSource;
using $Permission = ::java::security::Permission;
using $List = ::java::util::List;
using $PropertyPermission = ::java::util::PropertyPermission;
using $PolicyFile = ::sun::security::provider::PolicyFile;
using $PolicyFile$PolicyEntry = ::sun::security::provider::PolicyFile$PolicyEntry;
using $PolicyFile$PolicyInfo = ::sun::security::provider::PolicyFile$PolicyInfo;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _PolicyFile$5_FieldInfo_[] = {
	{"this$0", "Lsun/security/provider/PolicyFile;", nullptr, $FINAL | $SYNTHETIC, $field(PolicyFile$5, this$0)},
	{"val$newInfo", "Lsun/security/provider/PolicyFile$PolicyInfo;", nullptr, $FINAL | $SYNTHETIC, $field(PolicyFile$5, val$newInfo)},
	{}
};

$MethodInfo _PolicyFile$5_MethodInfo_[] = {
	{"<init>", "(Lsun/security/provider/PolicyFile;Lsun/security/provider/PolicyFile$PolicyInfo;)V", nullptr, 0, $method(PolicyFile$5, init$, void, $PolicyFile*, $PolicyFile$PolicyInfo*)},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC, $virtualMethod(PolicyFile$5, run, $Object*)},
	{}
};

$EnclosingMethodInfo _PolicyFile$5_EnclosingMethodInfo_ = {
	"sun.security.provider.PolicyFile",
	"initStaticPolicy",
	"(Lsun/security/provider/PolicyFile$PolicyInfo;)V"
};

$InnerClassInfo _PolicyFile$5_InnerClassesInfo_[] = {
	{"sun.security.provider.PolicyFile$5", nullptr, nullptr, 0},
	{"sun.security.provider.PolicyFile$PolicyInfo", "sun.security.provider.PolicyFile", "PolicyInfo", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _PolicyFile$5_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.provider.PolicyFile$5",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_PolicyFile$5_FieldInfo_,
	_PolicyFile$5_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Object;>;",
	&_PolicyFile$5_EnclosingMethodInfo_,
	_PolicyFile$5_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.provider.PolicyFile"
};

$Object* allocate$PolicyFile$5($Class* clazz) {
	return $of($alloc(PolicyFile$5));
}

void PolicyFile$5::init$($PolicyFile* this$0, $PolicyFile$PolicyInfo* val$newInfo) {
	$set(this, this$0, this$0);
	$set(this, val$newInfo, val$newInfo);
}

$Object* PolicyFile$5::run() {
	$useLocalCurrentObjectStackCache();
	$var($PolicyFile$PolicyEntry, pe, $new($PolicyFile$PolicyEntry, $$new($CodeSource, ($URL*)nullptr, ($CertificateArray*)nullptr)));
	$init($SecurityConstants);
	pe->add($SecurityConstants::LOCAL_LISTEN_PERMISSION);
	pe->add($$new($PropertyPermission, "java.version"_s, $SecurityConstants::PROPERTY_READ_ACTION));
	pe->add($$new($PropertyPermission, "java.vendor"_s, $SecurityConstants::PROPERTY_READ_ACTION));
	pe->add($$new($PropertyPermission, "java.vendor.url"_s, $SecurityConstants::PROPERTY_READ_ACTION));
	pe->add($$new($PropertyPermission, "java.class.version"_s, $SecurityConstants::PROPERTY_READ_ACTION));
	pe->add($$new($PropertyPermission, "os.name"_s, $SecurityConstants::PROPERTY_READ_ACTION));
	pe->add($$new($PropertyPermission, "os.version"_s, $SecurityConstants::PROPERTY_READ_ACTION));
	pe->add($$new($PropertyPermission, "os.arch"_s, $SecurityConstants::PROPERTY_READ_ACTION));
	pe->add($$new($PropertyPermission, "file.separator"_s, $SecurityConstants::PROPERTY_READ_ACTION));
	pe->add($$new($PropertyPermission, "path.separator"_s, $SecurityConstants::PROPERTY_READ_ACTION));
	pe->add($$new($PropertyPermission, "line.separator"_s, $SecurityConstants::PROPERTY_READ_ACTION));
	pe->add($$new($PropertyPermission, "java.specification.version"_s, $SecurityConstants::PROPERTY_READ_ACTION));
	pe->add($$new($PropertyPermission, "java.specification.vendor"_s, $SecurityConstants::PROPERTY_READ_ACTION));
	pe->add($$new($PropertyPermission, "java.specification.name"_s, $SecurityConstants::PROPERTY_READ_ACTION));
	pe->add($$new($PropertyPermission, "java.vm.specification.version"_s, $SecurityConstants::PROPERTY_READ_ACTION));
	pe->add($$new($PropertyPermission, "java.vm.specification.vendor"_s, $SecurityConstants::PROPERTY_READ_ACTION));
	pe->add($$new($PropertyPermission, "java.vm.specification.name"_s, $SecurityConstants::PROPERTY_READ_ACTION));
	pe->add($$new($PropertyPermission, "java.vm.version"_s, $SecurityConstants::PROPERTY_READ_ACTION));
	pe->add($$new($PropertyPermission, "java.vm.vendor"_s, $SecurityConstants::PROPERTY_READ_ACTION));
	pe->add($$new($PropertyPermission, "java.vm.name"_s, $SecurityConstants::PROPERTY_READ_ACTION));
	$nc($nc(this->val$newInfo)->policyEntries)->add(pe);
	return $of(nullptr);
}

PolicyFile$5::PolicyFile$5() {
}

$Class* PolicyFile$5::load$($String* name, bool initialize) {
	$loadClass(PolicyFile$5, name, initialize, &_PolicyFile$5_ClassInfo_, allocate$PolicyFile$5);
	return class$;
}

$Class* PolicyFile$5::class$ = nullptr;

		} // provider
	} // security
} // sun