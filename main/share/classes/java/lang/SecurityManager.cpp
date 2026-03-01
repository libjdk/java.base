#include <java/lang/SecurityManager.h>

#include <java/io/File.h>
#include <java/io/FileDescriptor.h>
#include <java/io/FilePermission.h>
#include <java/io/Serializable.h>
#include <java/lang/Module.h>
#include <java/lang/ModuleLayer.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager$1.h>
#include <java/lang/SecurityManager$2.h>
#include <java/lang/ThreadGroup.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/ModuleDescriptor$Exports.h>
#include <java/lang/module/ModuleDescriptor$Opens.h>
#include <java/lang/module/ModuleDescriptor.h>
#include <java/net/InetAddress.h>
#include <java/net/SocketPermission.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/SecurityPermission.h>
#include <java/util/AbstractMap.h>
#include <java/util/Collection.h>
#include <java/util/HashSet.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/PropertyPermission.h>
#include <java/util/Set.h>
#include <java/util/StringTokenizer.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/module/ModuleLoaderMap.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef CREATE_CLASSLOADER_PERMISSION
#undef FILE_DELETE_ACTION
#undef FILE_EXECUTE_ACTION
#undef FILE_READ_ACTION
#undef FILE_WRITE_ACTION
#undef MODIFY_THREADGROUP_PERMISSION
#undef MODIFY_THREAD_PERMISSION
#undef PROPERTY_READ_ACTION
#undef PROPERTY_RW_ACTION
#undef SOCKET_ACCEPT_ACTION
#undef SOCKET_CONNECT_ACCEPT_ACTION
#undef SOCKET_CONNECT_ACTION
#undef SOCKET_LISTEN_ACTION
#undef SOCKET_RESOLVE_ACTION
#undef TRUE

using $File = ::java::io::File;
using $FileDescriptor = ::java::io::FileDescriptor;
using $FilePermission = ::java::io::FilePermission;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $ModuleLayer = ::java::lang::ModuleLayer;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager$1 = ::java::lang::SecurityManager$1;
using $SecurityManager$2 = ::java::lang::SecurityManager$2;
using $ThreadGroup = ::java::lang::ThreadGroup;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ModuleDescriptor = ::java::lang::module::ModuleDescriptor;
using $ModuleDescriptor$Exports = ::java::lang::module::ModuleDescriptor$Exports;
using $ModuleDescriptor$Opens = ::java::lang::module::ModuleDescriptor$Opens;
using $InetAddress = ::java::net::InetAddress;
using $SocketPermission = ::java::net::SocketPermission;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $SecurityPermission = ::java::security::SecurityPermission;
using $AbstractMap = ::java::util::AbstractMap;
using $Collection = ::java::util::Collection;
using $HashSet = ::java::util::HashSet;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $PropertyPermission = ::java::util::PropertyPermission;
using $Set = ::java::util::Set;
using $StringTokenizer = ::java::util::StringTokenizer;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $Stream = ::java::util::stream::Stream;
using $ModuleLoaderMap = ::jdk::internal::module::ModuleLoaderMap;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace java {
	namespace lang {

class SecurityManager$$Lambda$getDescriptor : public $Function {
	$class(SecurityManager$$Lambda$getDescriptor, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($Module, inst$)->getDescriptor());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SecurityManager$$Lambda$getDescriptor>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo SecurityManager$$Lambda$getDescriptor::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SecurityManager$$Lambda$getDescriptor, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(SecurityManager$$Lambda$getDescriptor, apply, $Object*, Object$*)},
	{}
};
$ClassInfo SecurityManager$$Lambda$getDescriptor::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.SecurityManager$$Lambda$getDescriptor",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* SecurityManager$$Lambda$getDescriptor::load$($String* name, bool initialize) {
	$loadClass(SecurityManager$$Lambda$getDescriptor, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SecurityManager$$Lambda$getDescriptor::class$ = nullptr;

class SecurityManager$$Lambda$lambda$addNonExportedPackages$0$1 : public $Predicate {
	$class(SecurityManager$$Lambda$lambda$addNonExportedPackages$0$1, $NO_CLASS_INIT, $Predicate)
public:
	void init$($Set* bootModules, $Set* platformModules) {
		$set(this, bootModules, bootModules);
		$set(this, platformModules, platformModules);
	}
	virtual bool test(Object$* md) override {
		 return SecurityManager::lambda$addNonExportedPackages$0(bootModules, platformModules, $cast($ModuleDescriptor, md));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SecurityManager$$Lambda$lambda$addNonExportedPackages$0$1>());
	}
	$Set* bootModules = nullptr;
	$Set* platformModules = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SecurityManager$$Lambda$lambda$addNonExportedPackages$0$1::fieldInfos[3] = {
	{"bootModules", "Ljava/util/Set;", nullptr, $PUBLIC, $field(SecurityManager$$Lambda$lambda$addNonExportedPackages$0$1, bootModules)},
	{"platformModules", "Ljava/util/Set;", nullptr, $PUBLIC, $field(SecurityManager$$Lambda$lambda$addNonExportedPackages$0$1, platformModules)},
	{}
};
$MethodInfo SecurityManager$$Lambda$lambda$addNonExportedPackages$0$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/Set;Ljava/util/Set;)V", nullptr, $PUBLIC, $method(SecurityManager$$Lambda$lambda$addNonExportedPackages$0$1, init$, void, $Set*, $Set*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(SecurityManager$$Lambda$lambda$addNonExportedPackages$0$1, test, bool, Object$*)},
	{}
};
$ClassInfo SecurityManager$$Lambda$lambda$addNonExportedPackages$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.SecurityManager$$Lambda$lambda$addNonExportedPackages$0$1",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* SecurityManager$$Lambda$lambda$addNonExportedPackages$0$1::load$($String* name, bool initialize) {
	$loadClass(SecurityManager$$Lambda$lambda$addNonExportedPackages$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SecurityManager$$Lambda$lambda$addNonExportedPackages$0$1::class$ = nullptr;

class SecurityManager$$Lambda$nonExportedPkgs$2 : public $Function {
	$class(SecurityManager$$Lambda$nonExportedPkgs$2, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* md) override {
		 return $of(SecurityManager::nonExportedPkgs($cast($ModuleDescriptor, md)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SecurityManager$$Lambda$nonExportedPkgs$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo SecurityManager$$Lambda$nonExportedPkgs$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SecurityManager$$Lambda$nonExportedPkgs$2, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(SecurityManager$$Lambda$nonExportedPkgs$2, apply, $Object*, Object$*)},
	{}
};
$ClassInfo SecurityManager$$Lambda$nonExportedPkgs$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.SecurityManager$$Lambda$nonExportedPkgs$2",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* SecurityManager$$Lambda$nonExportedPkgs$2::load$($String* name, bool initialize) {
	$loadClass(SecurityManager$$Lambda$nonExportedPkgs$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SecurityManager$$Lambda$nonExportedPkgs$2::class$ = nullptr;

class SecurityManager$$Lambda$stream$3 : public $Function {
	$class(SecurityManager$$Lambda$stream$3, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($Collection, inst$)->stream());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SecurityManager$$Lambda$stream$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo SecurityManager$$Lambda$stream$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SecurityManager$$Lambda$stream$3, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(SecurityManager$$Lambda$stream$3, apply, $Object*, Object$*)},
	{}
};
$ClassInfo SecurityManager$$Lambda$stream$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.SecurityManager$$Lambda$stream$3",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* SecurityManager$$Lambda$stream$3::load$($String* name, bool initialize) {
	$loadClass(SecurityManager$$Lambda$stream$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SecurityManager$$Lambda$stream$3::class$ = nullptr;

class SecurityManager$$Lambda$lambda$addNonExportedPackages$1$4 : public $Consumer {
	$class(SecurityManager$$Lambda$lambda$addNonExportedPackages$1$4, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* pn) override {
		SecurityManager::lambda$addNonExportedPackages$1($cast($String, pn));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SecurityManager$$Lambda$lambda$addNonExportedPackages$1$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo SecurityManager$$Lambda$lambda$addNonExportedPackages$1$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SecurityManager$$Lambda$lambda$addNonExportedPackages$1$4, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager$$Lambda$lambda$addNonExportedPackages$1$4, accept, void, Object$*)},
	{}
};
$ClassInfo SecurityManager$$Lambda$lambda$addNonExportedPackages$1$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.SecurityManager$$Lambda$lambda$addNonExportedPackages$1$4",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* SecurityManager$$Lambda$lambda$addNonExportedPackages$1$4::load$($String* name, bool initialize) {
	$loadClass(SecurityManager$$Lambda$lambda$addNonExportedPackages$1$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SecurityManager$$Lambda$lambda$addNonExportedPackages$1$4::class$ = nullptr;

class SecurityManager$$Lambda$lambda$nonExportedPkgs$2$5 : public $Predicate {
	$class(SecurityManager$$Lambda$lambda$nonExportedPkgs$2$5, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* p) override {
		 return SecurityManager::lambda$nonExportedPkgs$2($cast($ModuleDescriptor$Exports, p));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SecurityManager$$Lambda$lambda$nonExportedPkgs$2$5>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo SecurityManager$$Lambda$lambda$nonExportedPkgs$2$5::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SecurityManager$$Lambda$lambda$nonExportedPkgs$2$5, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(SecurityManager$$Lambda$lambda$nonExportedPkgs$2$5, test, bool, Object$*)},
	{}
};
$ClassInfo SecurityManager$$Lambda$lambda$nonExportedPkgs$2$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.SecurityManager$$Lambda$lambda$nonExportedPkgs$2$5",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* SecurityManager$$Lambda$lambda$nonExportedPkgs$2$5::load$($String* name, bool initialize) {
	$loadClass(SecurityManager$$Lambda$lambda$nonExportedPkgs$2$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SecurityManager$$Lambda$lambda$nonExportedPkgs$2$5::class$ = nullptr;

class SecurityManager$$Lambda$source$6 : public $Function {
	$class(SecurityManager$$Lambda$source$6, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($ModuleDescriptor$Exports, inst$)->source());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SecurityManager$$Lambda$source$6>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo SecurityManager$$Lambda$source$6::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SecurityManager$$Lambda$source$6, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(SecurityManager$$Lambda$source$6, apply, $Object*, Object$*)},
	{}
};
$ClassInfo SecurityManager$$Lambda$source$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.SecurityManager$$Lambda$source$6",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* SecurityManager$$Lambda$source$6::load$($String* name, bool initialize) {
	$loadClass(SecurityManager$$Lambda$source$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SecurityManager$$Lambda$source$6::class$ = nullptr;

class SecurityManager$$Lambda$remove$7 : public $Consumer {
	$class(SecurityManager$$Lambda$remove$7, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Set* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* o) override {
		$nc(inst$)->remove(o);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SecurityManager$$Lambda$remove$7>());
	}
	$Set* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SecurityManager$$Lambda$remove$7::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SecurityManager$$Lambda$remove$7, inst$)},
	{}
};
$MethodInfo SecurityManager$$Lambda$remove$7::methodInfos[3] = {
	{"<init>", "(Ljava/util/Set;)V", nullptr, $PUBLIC, $method(SecurityManager$$Lambda$remove$7, init$, void, $Set*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager$$Lambda$remove$7, accept, void, Object$*)},
	{}
};
$ClassInfo SecurityManager$$Lambda$remove$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.SecurityManager$$Lambda$remove$7",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* SecurityManager$$Lambda$remove$7::load$($String* name, bool initialize) {
	$loadClass(SecurityManager$$Lambda$remove$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SecurityManager$$Lambda$remove$7::class$ = nullptr;

class SecurityManager$$Lambda$lambda$nonExportedPkgs$3$8 : public $Predicate {
	$class(SecurityManager$$Lambda$lambda$nonExportedPkgs$3$8, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* p) override {
		 return SecurityManager::lambda$nonExportedPkgs$3($cast($ModuleDescriptor$Opens, p));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SecurityManager$$Lambda$lambda$nonExportedPkgs$3$8>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo SecurityManager$$Lambda$lambda$nonExportedPkgs$3$8::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SecurityManager$$Lambda$lambda$nonExportedPkgs$3$8, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(SecurityManager$$Lambda$lambda$nonExportedPkgs$3$8, test, bool, Object$*)},
	{}
};
$ClassInfo SecurityManager$$Lambda$lambda$nonExportedPkgs$3$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.SecurityManager$$Lambda$lambda$nonExportedPkgs$3$8",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* SecurityManager$$Lambda$lambda$nonExportedPkgs$3$8::load$($String* name, bool initialize) {
	$loadClass(SecurityManager$$Lambda$lambda$nonExportedPkgs$3$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SecurityManager$$Lambda$lambda$nonExportedPkgs$3$8::class$ = nullptr;

class SecurityManager$$Lambda$source$9 : public $Function {
	$class(SecurityManager$$Lambda$source$9, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($ModuleDescriptor$Opens, inst$)->source());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SecurityManager$$Lambda$source$9>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo SecurityManager$$Lambda$source$9::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SecurityManager$$Lambda$source$9, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(SecurityManager$$Lambda$source$9, apply, $Object*, Object$*)},
	{}
};
$ClassInfo SecurityManager$$Lambda$source$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.SecurityManager$$Lambda$source$9",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* SecurityManager$$Lambda$source$9::load$($String* name, bool initialize) {
	$loadClass(SecurityManager$$Lambda$source$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SecurityManager$$Lambda$source$9::class$ = nullptr;

$NamedAttribute SecurityManager_Attribute_var$0[] = {
	{"since", 's', "17"},
	{"forRemoval", 'Z', "true"},
	{}
};

$CompoundAttribute _SecurityManager_Annotations_[] = {
	{"Ljava/lang/Deprecated;", SecurityManager_Attribute_var$0},
	{}
};

$NamedAttribute SecurityManager_Attribute_var$1[] = {
	{"since", 's', "1.4"},
	{"forRemoval", 'Z', "true"},
	{}
};

$CompoundAttribute _SecurityManager_MethodAnnotations_checkMulticast14[] = {
	{"Ljava/lang/Deprecated;", SecurityManager_Attribute_var$1},
	{}
};

$FieldInfo _SecurityManager_FieldInfo_[] = {
	{"initialized", "Z", nullptr, $PRIVATE, $field(SecurityManager, initialized)},
	{"rootGroup", "Ljava/lang/ThreadGroup;", nullptr, $PRIVATE | $STATIC, $staticField(SecurityManager, rootGroup)},
	{"packageAccessValid", "Z", nullptr, $PRIVATE | $STATIC, $staticField(SecurityManager, packageAccessValid)},
	{"packageAccess", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(SecurityManager, packageAccess)},
	{"packageAccessLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SecurityManager, packageAccessLock)},
	{"packageDefinitionValid", "Z", nullptr, $PRIVATE | $STATIC, $staticField(SecurityManager, packageDefinitionValid)},
	{"packageDefinition", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(SecurityManager, packageDefinition)},
	{"packageDefinitionLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SecurityManager, packageDefinitionLock)},
	{"nonExportedPkgs", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/Boolean;>;", $PRIVATE | $STATIC | $FINAL, $staticField(SecurityManager, nonExportedPkgs$)},
	{}
};

$MethodInfo _SecurityManager_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SecurityManager, init$, void)},
	{"addNonExportedPackages", "(Ljava/lang/ModuleLayer;)V", nullptr, $STATIC, $staticMethod(SecurityManager, addNonExportedPackages, void, $ModuleLayer*)},
	{"checkAccept", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkAccept, void, $String*, int32_t)},
	{"checkAccess", "(Ljava/lang/Thread;)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkAccess, void, $Thread*)},
	{"checkAccess", "(Ljava/lang/ThreadGroup;)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkAccess, void, $ThreadGroup*)},
	{"checkConnect", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkConnect, void, $String*, int32_t)},
	{"checkConnect", "(Ljava/lang/String;ILjava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkConnect, void, $String*, int32_t, Object$*)},
	{"checkCreateClassLoader", "()V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkCreateClassLoader, void)},
	{"checkDelete", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkDelete, void, $String*)},
	{"checkExec", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkExec, void, $String*)},
	{"checkExit", "(I)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkExit, void, int32_t)},
	{"checkLink", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkLink, void, $String*)},
	{"checkListen", "(I)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkListen, void, int32_t)},
	{"checkMulticast", "(Ljava/net/InetAddress;)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkMulticast, void, $InetAddress*)},
	{"checkMulticast", "(Ljava/net/InetAddress;B)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(SecurityManager, checkMulticast, void, $InetAddress*, int8_t), nullptr, nullptr, _SecurityManager_MethodAnnotations_checkMulticast14},
	{"checkPackageAccess", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkPackageAccess, void, $String*)},
	{"checkPackageDefinition", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkPackageDefinition, void, $String*)},
	{"checkPermission", "(Ljava/security/Permission;)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkPermission, void, $Permission*)},
	{"checkPermission", "(Ljava/security/Permission;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkPermission, void, $Permission*, Object$*)},
	{"checkPrintJobAccess", "()V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkPrintJobAccess, void)},
	{"checkPropertiesAccess", "()V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkPropertiesAccess, void)},
	{"checkPropertyAccess", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkPropertyAccess, void, $String*)},
	{"checkRead", "(Ljava/io/FileDescriptor;)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkRead, void, $FileDescriptor*)},
	{"checkRead", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkRead, void, $String*)},
	{"checkRead", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkRead, void, $String*, Object$*)},
	{"checkSecurityAccess", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkSecurityAccess, void, $String*)},
	{"checkSetFactory", "()V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkSetFactory, void)},
	{"checkWrite", "(Ljava/io/FileDescriptor;)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkWrite, void, $FileDescriptor*)},
	{"checkWrite", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(SecurityManager, checkWrite, void, $String*)},
	{"getClassContext", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $PROTECTED | $NATIVE, $virtualMethod(SecurityManager, getClassContext, $ClassArray*)},
	{"getPackages", "(Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(SecurityManager, getPackages, $StringArray*, $String*)},
	{"getRootGroup", "()Ljava/lang/ThreadGroup;", nullptr, $PRIVATE | $STATIC, $staticMethod(SecurityManager, getRootGroup, $ThreadGroup*)},
	{"getSecurityContext", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(SecurityManager, getSecurityContext, $Object*)},
	{"getThreadGroup", "()Ljava/lang/ThreadGroup;", nullptr, $PUBLIC, $virtualMethod(SecurityManager, getThreadGroup, $ThreadGroup*)},
	{"invalidatePackageAccessCache", "()V", nullptr, $STATIC, $staticMethod(SecurityManager, invalidatePackageAccessCache, void)},
	{"lambda$addNonExportedPackages$0", "(Ljava/util/Set;Ljava/util/Set;Ljava/lang/module/ModuleDescriptor;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(SecurityManager, lambda$addNonExportedPackages$0, bool, $Set*, $Set*, $ModuleDescriptor*)},
	{"lambda$addNonExportedPackages$1", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(SecurityManager, lambda$addNonExportedPackages$1, void, $String*)},
	{"lambda$nonExportedPkgs$2", "(Ljava/lang/module/ModuleDescriptor$Exports;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(SecurityManager, lambda$nonExportedPkgs$2, bool, $ModuleDescriptor$Exports*)},
	{"lambda$nonExportedPkgs$3", "(Ljava/lang/module/ModuleDescriptor$Opens;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(SecurityManager, lambda$nonExportedPkgs$3, bool, $ModuleDescriptor$Opens*)},
	{"nonExportedPkgs", "(Ljava/lang/module/ModuleDescriptor;)Ljava/util/Set;", "(Ljava/lang/module/ModuleDescriptor;)Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(SecurityManager, nonExportedPkgs, $Set*, $ModuleDescriptor*)},
	{}
};

#define _METHOD_INDEX_getClassContext 29

$InnerClassInfo _SecurityManager_InnerClassesInfo_[] = {
	{"java.lang.SecurityManager$2", nullptr, nullptr, 0},
	{"java.lang.SecurityManager$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SecurityManager_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.lang.SecurityManager",
	"java.lang.Object",
	nullptr,
	_SecurityManager_FieldInfo_,
	_SecurityManager_MethodInfo_,
	nullptr,
	nullptr,
	_SecurityManager_InnerClassesInfo_,
	_SecurityManager_Annotations_,
	nullptr,
	"java.lang.SecurityManager$2,java.lang.SecurityManager$1"
};

$Object* allocate$SecurityManager($Class* clazz) {
	return $of($alloc(SecurityManager));
}

$ThreadGroup* SecurityManager::rootGroup = nullptr;
bool SecurityManager::packageAccessValid = false;
$StringArray* SecurityManager::packageAccess = nullptr;
$Object* SecurityManager::packageAccessLock = nullptr;
bool SecurityManager::packageDefinitionValid = false;
$StringArray* SecurityManager::packageDefinition = nullptr;
$Object* SecurityManager::packageDefinitionLock = nullptr;
$Map* SecurityManager::nonExportedPkgs$ = nullptr;

void SecurityManager::init$() {
	$useLocalCurrentObjectStackCache();
	this->initialized = false;
	$synchronized(SecurityManager::class$) {
		$var(SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			sm->checkPermission($$new($RuntimePermission, "createSecurityManager"_s));
		}
		this->initialized = true;
	}
}

$ClassArray* SecurityManager::getClassContext() {
	$var($ClassArray, $ret, nullptr);
	$prepareNative(SecurityManager, getClassContext, $ClassArray*);
	$assign($ret, $invokeNativeObject());
	$finishNative();
	return $ret;
}

$Object* SecurityManager::getSecurityContext() {
	return $of($AccessController::getContext());
}

void SecurityManager::checkPermission($Permission* perm) {
	$AccessController::checkPermission(perm);
}

void SecurityManager::checkPermission($Permission* perm, Object$* context) {
	if ($instanceOf($AccessControlContext, context)) {
		$nc(($cast($AccessControlContext, context)))->checkPermission(perm);
	} else {
		$throwNew($SecurityException);
	}
}

void SecurityManager::checkCreateClassLoader() {
	$init($SecurityConstants);
	checkPermission($SecurityConstants::CREATE_CLASSLOADER_PERMISSION);
}

$ThreadGroup* SecurityManager::getRootGroup() {
	$init(SecurityManager);
	$useLocalCurrentObjectStackCache();
	$var($ThreadGroup, root, $($Thread::currentThread())->getThreadGroup());
	while ($nc(root)->getParent() != nullptr) {
		$assign(root, root->getParent());
	}
	return root;
}

void SecurityManager::checkAccess($Thread* t) {
	if (t == nullptr) {
		$throwNew($NullPointerException, "thread can\'t be null"_s);
	}
	if ($nc(t)->getThreadGroup() == SecurityManager::rootGroup) {
		$init($SecurityConstants);
		checkPermission($SecurityConstants::MODIFY_THREAD_PERMISSION);
	} else {
	}
}

void SecurityManager::checkAccess($ThreadGroup* g) {
	if (g == nullptr) {
		$throwNew($NullPointerException, "thread group can\'t be null"_s);
	}
	if (g == SecurityManager::rootGroup) {
		$init($SecurityConstants);
		checkPermission($SecurityConstants::MODIFY_THREADGROUP_PERMISSION);
	} else {
	}
}

void SecurityManager::checkExit(int32_t status) {
	$useLocalCurrentObjectStackCache();
	checkPermission($$new($RuntimePermission, $$str({"exitVM."_s, $$str(status)})));
}

void SecurityManager::checkExec($String* cmd) {
	$useLocalCurrentObjectStackCache();
	$var($File, f, $new($File, cmd));
	if (f->isAbsolute()) {
		$init($SecurityConstants);
		checkPermission($$new($FilePermission, cmd, $SecurityConstants::FILE_EXECUTE_ACTION));
	} else {
		$init($SecurityConstants);
		checkPermission($$new($FilePermission, "<<ALL FILES>>"_s, $SecurityConstants::FILE_EXECUTE_ACTION));
	}
}

void SecurityManager::checkLink($String* lib) {
	$useLocalCurrentObjectStackCache();
	if (lib == nullptr) {
		$throwNew($NullPointerException, "library can\'t be null"_s);
	}
	checkPermission($$new($RuntimePermission, $$str({"loadLibrary."_s, lib})));
}

void SecurityManager::checkRead($FileDescriptor* fd) {
	if (fd == nullptr) {
		$throwNew($NullPointerException, "file descriptor can\'t be null"_s);
	}
	checkPermission($$new($RuntimePermission, "readFileDescriptor"_s));
}

void SecurityManager::checkRead($String* file) {
	$init($SecurityConstants);
	checkPermission($$new($FilePermission, file, $SecurityConstants::FILE_READ_ACTION));
}

void SecurityManager::checkRead($String* file, Object$* context) {
	$init($SecurityConstants);
	checkPermission($$new($FilePermission, file, $SecurityConstants::FILE_READ_ACTION), context);
}

void SecurityManager::checkWrite($FileDescriptor* fd) {
	if (fd == nullptr) {
		$throwNew($NullPointerException, "file descriptor can\'t be null"_s);
	}
	checkPermission($$new($RuntimePermission, "writeFileDescriptor"_s));
}

void SecurityManager::checkWrite($String* file) {
	$init($SecurityConstants);
	checkPermission($$new($FilePermission, file, $SecurityConstants::FILE_WRITE_ACTION));
}

void SecurityManager::checkDelete($String* file) {
	$init($SecurityConstants);
	checkPermission($$new($FilePermission, file, $SecurityConstants::FILE_DELETE_ACTION));
}

void SecurityManager::checkConnect($String* host$renamed, int32_t port) {
	$useLocalCurrentObjectStackCache();
	$var($String, host, host$renamed);
	if (host == nullptr) {
		$throwNew($NullPointerException, "host can\'t be null"_s);
	}
	bool var$0 = !$nc(host)->startsWith("["_s);
	if (var$0 && host->indexOf((int32_t)u':') != -1) {
		$assign(host, $str({"["_s, host, "]"_s}));
	}
	if (port == -1) {
		$init($SecurityConstants);
		checkPermission($$new($SocketPermission, host, $SecurityConstants::SOCKET_RESOLVE_ACTION));
	} else {
		$init($SecurityConstants);
		checkPermission($$new($SocketPermission, $$str({host, ":"_s, $$str(port)}), $SecurityConstants::SOCKET_CONNECT_ACTION));
	}
}

void SecurityManager::checkConnect($String* host$renamed, int32_t port, Object$* context) {
	$useLocalCurrentObjectStackCache();
	$var($String, host, host$renamed);
	if (host == nullptr) {
		$throwNew($NullPointerException, "host can\'t be null"_s);
	}
	bool var$0 = !$nc(host)->startsWith("["_s);
	if (var$0 && host->indexOf((int32_t)u':') != -1) {
		$assign(host, $str({"["_s, host, "]"_s}));
	}
	if (port == -1) {
		$init($SecurityConstants);
		checkPermission($$new($SocketPermission, host, $SecurityConstants::SOCKET_RESOLVE_ACTION), context);
	} else {
		$init($SecurityConstants);
		checkPermission($$new($SocketPermission, $$str({host, ":"_s, $$str(port)}), $SecurityConstants::SOCKET_CONNECT_ACTION), context);
	}
}

void SecurityManager::checkListen(int32_t port) {
	$useLocalCurrentObjectStackCache();
	$init($SecurityConstants);
	checkPermission($$new($SocketPermission, $$str({"localhost:"_s, $$str(port)}), $SecurityConstants::SOCKET_LISTEN_ACTION));
}

void SecurityManager::checkAccept($String* host$renamed, int32_t port) {
	$useLocalCurrentObjectStackCache();
	$var($String, host, host$renamed);
	if (host == nullptr) {
		$throwNew($NullPointerException, "host can\'t be null"_s);
	}
	bool var$0 = !$nc(host)->startsWith("["_s);
	if (var$0 && host->indexOf((int32_t)u':') != -1) {
		$assign(host, $str({"["_s, host, "]"_s}));
	}
	$init($SecurityConstants);
	checkPermission($$new($SocketPermission, $$str({host, ":"_s, $$str(port)}), $SecurityConstants::SOCKET_ACCEPT_ACTION));
}

void SecurityManager::checkMulticast($InetAddress* maddr) {
	$useLocalCurrentObjectStackCache();
	$var($String, host, $nc(maddr)->getHostAddress());
	bool var$0 = !$nc(host)->startsWith("["_s);
	if (var$0 && host->indexOf((int32_t)u':') != -1) {
		$assign(host, $str({"["_s, host, "]"_s}));
	}
	$init($SecurityConstants);
	checkPermission($$new($SocketPermission, host, $SecurityConstants::SOCKET_CONNECT_ACCEPT_ACTION));
}

void SecurityManager::checkMulticast($InetAddress* maddr, int8_t ttl) {
	$useLocalCurrentObjectStackCache();
	$var($String, host, $nc(maddr)->getHostAddress());
	bool var$0 = !$nc(host)->startsWith("["_s);
	if (var$0 && host->indexOf((int32_t)u':') != -1) {
		$assign(host, $str({"["_s, host, "]"_s}));
	}
	$init($SecurityConstants);
	checkPermission($$new($SocketPermission, host, $SecurityConstants::SOCKET_CONNECT_ACCEPT_ACTION));
}

void SecurityManager::checkPropertiesAccess() {
	$init($SecurityConstants);
	checkPermission($$new($PropertyPermission, "*"_s, $SecurityConstants::PROPERTY_RW_ACTION));
}

void SecurityManager::checkPropertyAccess($String* key) {
	$init($SecurityConstants);
	checkPermission($$new($PropertyPermission, key, $SecurityConstants::PROPERTY_READ_ACTION));
}

void SecurityManager::checkPrintJobAccess() {
	checkPermission($$new($RuntimePermission, "queuePrintJob"_s));
}

$StringArray* SecurityManager::getPackages($String* p) {
	$init(SecurityManager);
	$useLocalCurrentObjectStackCache();
	$var($StringArray, packages, nullptr);
	if (p != nullptr && !p->isEmpty()) {
		$var($StringTokenizer, tok, $new($StringTokenizer, p, ","_s));
		int32_t n = tok->countTokens();
		if (n > 0) {
			$assign(packages, $new($StringArray, n));
			int32_t i = 0;
			while (tok->hasMoreElements()) {
				$var($String, s, $nc($(tok->nextToken()))->trim());
				packages->set(i++, s);
			}
		}
	}
	if (packages == nullptr) {
		$assign(packages, $new($StringArray, 0));
	}
	return packages;
}

void SecurityManager::addNonExportedPackages($ModuleLayer* layer) {
	$init(SecurityManager);
	$useLocalCurrentObjectStackCache();
	$var($Set, bootModules, $ModuleLoaderMap::bootModules());
	$var($Set, platformModules, $ModuleLoaderMap::platformModules());
	$nc($($nc($($nc($($nc($($nc($($nc($($nc(layer)->modules()))->stream()))->map(static_cast<$Function*>($$new(SecurityManager$$Lambda$getDescriptor)))))->filter(static_cast<$Predicate*>($$new(SecurityManager$$Lambda$lambda$addNonExportedPackages$0$1, bootModules, platformModules)))))->map(static_cast<$Function*>($$new(SecurityManager$$Lambda$nonExportedPkgs$2)))))->flatMap(static_cast<$Function*>($$new(SecurityManager$$Lambda$stream$3)))))->forEach(static_cast<$Consumer*>($$new(SecurityManager$$Lambda$lambda$addNonExportedPackages$1$4)));
}

void SecurityManager::invalidatePackageAccessCache() {
	$init(SecurityManager);
	$synchronized(SecurityManager::packageAccessLock) {
		SecurityManager::packageAccessValid = false;
	}
	$synchronized(SecurityManager::packageDefinitionLock) {
		SecurityManager::packageDefinitionValid = false;
	}
}

$Set* SecurityManager::nonExportedPkgs($ModuleDescriptor* md) {
	$init(SecurityManager);
	$useLocalCurrentObjectStackCache();
	$var($Set, pkgs, $new($HashSet, $(static_cast<$Collection*>($nc(md)->packages()))));
	$nc($($nc($($nc($($nc($($nc(md)->exports()))->stream()))->filter(static_cast<$Predicate*>($$new(SecurityManager$$Lambda$lambda$nonExportedPkgs$2$5)))))->map(static_cast<$Function*>($$new(SecurityManager$$Lambda$source$6)))))->forEach(static_cast<$Consumer*>($$new(SecurityManager$$Lambda$remove$7, static_cast<$Set*>(pkgs))));
	$nc($($nc($($nc($($nc($(md->opens()))->stream()))->filter(static_cast<$Predicate*>($$new(SecurityManager$$Lambda$lambda$nonExportedPkgs$3$8)))))->map(static_cast<$Function*>($$new(SecurityManager$$Lambda$source$9)))))->forEach(static_cast<$Consumer*>($$new(SecurityManager$$Lambda$remove$7, static_cast<$Set*>(pkgs))));
	return pkgs;
}

void SecurityManager::checkPackageAccess($String* pkg) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Objects::requireNonNull($of(pkg), "package name can\'t be null"_s);
	if ($nc(SecurityManager::nonExportedPkgs$)->containsKey(pkg)) {
		checkPermission($$new($RuntimePermission, $$str({"accessClassInPackage."_s, pkg})));
		return;
	}
	$var($StringArray, restrictedPkgs, nullptr);
	$synchronized(SecurityManager::packageAccessLock) {
		if (!SecurityManager::packageAccessValid) {
			$var($String, tmpPropertyStr, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($SecurityManager$1, this)))));
			$assignStatic(SecurityManager::packageAccess, getPackages(tmpPropertyStr));
			SecurityManager::packageAccessValid = true;
		}
		$assign(restrictedPkgs, SecurityManager::packageAccess);
	}
	int32_t plen = $nc(pkg)->length();
	{
		$var($StringArray, arr$, restrictedPkgs);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, restrictedPkg, arr$->get(i$));
			{
				int32_t rlast = $nc(restrictedPkg)->length() - 1;
				bool var$0 = rlast < plen && pkg->startsWith(restrictedPkg);
				if (!var$0) {
					bool var$1 = rlast == plen && restrictedPkg->startsWith(pkg);
					var$0 = var$1 && restrictedPkg->charAt(rlast) == u'.';
				}
				if (var$0) {
					checkPermission($$new($RuntimePermission, $$str({"accessClassInPackage."_s, pkg})));
					break;
				}
			}
		}
	}
}

void SecurityManager::checkPackageDefinition($String* pkg) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Objects::requireNonNull($of(pkg), "package name can\'t be null"_s);
	if ($nc(SecurityManager::nonExportedPkgs$)->containsKey(pkg)) {
		checkPermission($$new($RuntimePermission, $$str({"defineClassInPackage."_s, pkg})));
		return;
	}
	$var($StringArray, pkgs, nullptr);
	$synchronized(SecurityManager::packageDefinitionLock) {
		if (!SecurityManager::packageDefinitionValid) {
			$var($String, tmpPropertyStr, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($SecurityManager$2, this)))));
			$assignStatic(SecurityManager::packageDefinition, getPackages(tmpPropertyStr));
			SecurityManager::packageDefinitionValid = true;
		}
		$assign(pkgs, SecurityManager::packageDefinition);
	}
	{
		$var($StringArray, arr$, pkgs);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, restrictedPkg, arr$->get(i$));
			{
				bool var$0 = $nc(pkg)->startsWith(restrictedPkg);
				if (var$0 || $nc(restrictedPkg)->equals($$str({pkg, "."_s}))) {
					checkPermission($$new($RuntimePermission, $$str({"defineClassInPackage."_s, pkg})));
					break;
				}
			}
		}
	}
}

void SecurityManager::checkSetFactory() {
	checkPermission($$new($RuntimePermission, "setFactory"_s));
}

void SecurityManager::checkSecurityAccess($String* target) {
	checkPermission($$new($SecurityPermission, target));
}

$ThreadGroup* SecurityManager::getThreadGroup() {
	return $($Thread::currentThread())->getThreadGroup();
}

bool SecurityManager::lambda$nonExportedPkgs$3($ModuleDescriptor$Opens* p) {
	$init(SecurityManager);
	return !$nc(p)->isQualified();
}

bool SecurityManager::lambda$nonExportedPkgs$2($ModuleDescriptor$Exports* p) {
	$init(SecurityManager);
	return !$nc(p)->isQualified();
}

void SecurityManager::lambda$addNonExportedPackages$1($String* pn) {
	$init(SecurityManager);
	$init($Boolean);
	$nc(SecurityManager::nonExportedPkgs$)->put(pn, $Boolean::TRUE);
}

bool SecurityManager::lambda$addNonExportedPackages$0($Set* bootModules, $Set* platformModules, $ModuleDescriptor* md) {
	$init(SecurityManager);
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(bootModules)->contains($($nc(md)->name()));
	return var$0 || $nc(platformModules)->contains($($nc(md)->name()));
}

void clinit$SecurityManager($Class* class$) {
	$assignStatic(SecurityManager::rootGroup, SecurityManager::getRootGroup());
	SecurityManager::packageAccessValid = false;
	$assignStatic(SecurityManager::packageAccessLock, $new($Object));
	SecurityManager::packageDefinitionValid = false;
	$assignStatic(SecurityManager::packageDefinitionLock, $new($Object));
	$assignStatic(SecurityManager::nonExportedPkgs$, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
	{
		SecurityManager::addNonExportedPackages($($ModuleLayer::boot()));
	}
}

SecurityManager::SecurityManager() {
}

$Class* SecurityManager::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SecurityManager$$Lambda$getDescriptor::classInfo$.name)) {
			return SecurityManager$$Lambda$getDescriptor::load$(name, initialize);
		}
		if (name->equals(SecurityManager$$Lambda$lambda$addNonExportedPackages$0$1::classInfo$.name)) {
			return SecurityManager$$Lambda$lambda$addNonExportedPackages$0$1::load$(name, initialize);
		}
		if (name->equals(SecurityManager$$Lambda$nonExportedPkgs$2::classInfo$.name)) {
			return SecurityManager$$Lambda$nonExportedPkgs$2::load$(name, initialize);
		}
		if (name->equals(SecurityManager$$Lambda$stream$3::classInfo$.name)) {
			return SecurityManager$$Lambda$stream$3::load$(name, initialize);
		}
		if (name->equals(SecurityManager$$Lambda$lambda$addNonExportedPackages$1$4::classInfo$.name)) {
			return SecurityManager$$Lambda$lambda$addNonExportedPackages$1$4::load$(name, initialize);
		}
		if (name->equals(SecurityManager$$Lambda$lambda$nonExportedPkgs$2$5::classInfo$.name)) {
			return SecurityManager$$Lambda$lambda$nonExportedPkgs$2$5::load$(name, initialize);
		}
		if (name->equals(SecurityManager$$Lambda$source$6::classInfo$.name)) {
			return SecurityManager$$Lambda$source$6::load$(name, initialize);
		}
		if (name->equals(SecurityManager$$Lambda$remove$7::classInfo$.name)) {
			return SecurityManager$$Lambda$remove$7::load$(name, initialize);
		}
		if (name->equals(SecurityManager$$Lambda$lambda$nonExportedPkgs$3$8::classInfo$.name)) {
			return SecurityManager$$Lambda$lambda$nonExportedPkgs$3$8::load$(name, initialize);
		}
		if (name->equals(SecurityManager$$Lambda$source$9::classInfo$.name)) {
			return SecurityManager$$Lambda$source$9::load$(name, initialize);
		}
	}
	$loadClass(SecurityManager, name, initialize, &_SecurityManager_ClassInfo_, clinit$SecurityManager, allocate$SecurityManager);
	return class$;
}

$Class* SecurityManager::class$ = nullptr;

	} // lang
} // java