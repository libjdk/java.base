#include <jdk/internal/loader/Loader.h>

#include <java/io/File.h>
#include <java/io/FilePermission.h>
#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/InternalError.h>
#include <java/lang/ModuleLayer.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/Configuration.h>
#include <java/lang/module/ModuleDescriptor$Exports.h>
#include <java/lang/module/ModuleDescriptor$Opens.h>
#include <java/lang/module/ModuleDescriptor.h>
#include <java/lang/module/ModuleReader.h>
#include <java/lang/module/ModuleReference.h>
#include <java/lang/module/ResolvedModule.h>
#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/CodeSource.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/security/SecureClassLoader.h>
#include <java/util/AbstractMap.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/loader/BootLoader.h>
#include <jdk/internal/loader/ClassLoaders.h>
#include <jdk/internal/loader/Loader$1.h>
#include <jdk/internal/loader/Loader$2.h>
#include <jdk/internal/loader/Loader$3.h>
#include <jdk/internal/loader/Loader$LoadedModule.h>
#include <jdk/internal/loader/Loader$NullModuleReader.h>
#include <jdk/internal/loader/LoaderPool.h>
#include <jdk/internal/module/Resources.h>
#include <jcpp.h>

using $File = ::java::io::File;
using $FilePermission = ::java::io::FilePermission;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $ModuleLayer = ::java::lang::ModuleLayer;
using $SecurityManager = ::java::lang::SecurityManager;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Configuration = ::java::lang::module::Configuration;
using $ModuleDescriptor = ::java::lang::module::ModuleDescriptor;
using $ModuleDescriptor$Exports = ::java::lang::module::ModuleDescriptor$Exports;
using $ModuleDescriptor$Opens = ::java::lang::module::ModuleDescriptor$Opens;
using $ModuleReader = ::java::lang::module::ModuleReader;
using $ModuleReference = ::java::lang::module::ModuleReference;
using $ResolvedModule = ::java::lang::module::ResolvedModule;
using $URL = ::java::net::URL;
using $URLConnection = ::java::net::URLConnection;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AccessController = ::java::security::AccessController;
using $CodeSource = ::java::security::CodeSource;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $SecureClassLoader = ::java::security::SecureClassLoader;
using $AbstractMap = ::java::util::AbstractMap;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $Supplier = ::java::util::function::Supplier;
using $Stream = ::java::util::stream::Stream;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $BootLoader = ::jdk::internal::loader::BootLoader;
using $ClassLoaders = ::jdk::internal::loader::ClassLoaders;
using $Loader$1 = ::jdk::internal::loader::Loader$1;
using $Loader$2 = ::jdk::internal::loader::Loader$2;
using $Loader$3 = ::jdk::internal::loader::Loader$3;
using $Loader$LoadedModule = ::jdk::internal::loader::Loader$LoadedModule;
using $Loader$NullModuleReader = ::jdk::internal::loader::Loader$NullModuleReader;
using $LoaderPool = ::jdk::internal::loader::LoaderPool;
using $Resources = ::jdk::internal::module::Resources;

namespace jdk {
	namespace internal {
		namespace loader {

class Loader$$Lambda$lambda$new$0 : public $Consumer {
	$class(Loader$$Lambda$lambda$new$0, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Map* localPackageToModule, $Loader$LoadedModule* lm) {
		$set(this, localPackageToModule, localPackageToModule);
		$set(this, lm, lm);
	}
	virtual void accept(Object$* pn) override {
		Loader::lambda$new$0(localPackageToModule, lm, $cast($String, pn));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Loader$$Lambda$lambda$new$0>());
	}
	$Map* localPackageToModule = nullptr;
	$Loader$LoadedModule* lm = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Loader$$Lambda$lambda$new$0::fieldInfos[3] = {
	{"localPackageToModule", "Ljava/util/Map;", nullptr, $PUBLIC, $field(Loader$$Lambda$lambda$new$0, localPackageToModule)},
	{"lm", "Ljdk/internal/loader/Loader$LoadedModule;", nullptr, $PUBLIC, $field(Loader$$Lambda$lambda$new$0, lm)},
	{}
};
$MethodInfo Loader$$Lambda$lambda$new$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/Map;Ljdk/internal/loader/Loader$LoadedModule;)V", nullptr, $PUBLIC, $method(Loader$$Lambda$lambda$new$0, init$, void, $Map*, $Loader$LoadedModule*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Loader$$Lambda$lambda$new$0, accept, void, Object$*)},
	{}
};
$ClassInfo Loader$$Lambda$lambda$new$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.loader.Loader$$Lambda$lambda$new$0",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* Loader$$Lambda$lambda$new$0::load$($String* name, bool initialize) {
	$loadClass(Loader$$Lambda$lambda$new$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Loader$$Lambda$lambda$new$0::class$ = nullptr;

class Loader$$Lambda$lambda$new$1$1 : public $Consumer {
	$class(Loader$$Lambda$lambda$new$1$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$($ModuleReference* mref, $Map* localPackageToModule) {
		$set(this, mref, mref);
		$set(this, localPackageToModule, localPackageToModule);
	}
	virtual void accept(Object$* pn) override {
		Loader::lambda$new$1(mref, localPackageToModule, $cast($String, pn));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Loader$$Lambda$lambda$new$1$1>());
	}
	$ModuleReference* mref = nullptr;
	$Map* localPackageToModule = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Loader$$Lambda$lambda$new$1$1::fieldInfos[3] = {
	{"mref", "Ljava/lang/module/ModuleReference;", nullptr, $PUBLIC, $field(Loader$$Lambda$lambda$new$1$1, mref)},
	{"localPackageToModule", "Ljava/util/Map;", nullptr, $PUBLIC, $field(Loader$$Lambda$lambda$new$1$1, localPackageToModule)},
	{}
};
$MethodInfo Loader$$Lambda$lambda$new$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/module/ModuleReference;Ljava/util/Map;)V", nullptr, $PUBLIC, $method(Loader$$Lambda$lambda$new$1$1, init$, void, $ModuleReference*, $Map*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Loader$$Lambda$lambda$new$1$1, accept, void, Object$*)},
	{}
};
$ClassInfo Loader$$Lambda$lambda$new$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.loader.Loader$$Lambda$lambda$new$1$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* Loader$$Lambda$lambda$new$1$1::load$($String* name, bool initialize) {
	$loadClass(Loader$$Lambda$lambda$new$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Loader$$Lambda$lambda$new$1$1::class$ = nullptr;

class Loader$$Lambda$lambda$initRemotePackageMap$2$2 : public $Function {
	$class(Loader$$Lambda$lambda$initRemotePackageMap$2$2, $NO_CLASS_INIT, $Function)
public:
	void init$(Loader* inst, $ResolvedModule* other) {
		$set(this, inst$, inst);
		$set(this, other, other);
	}
	virtual $Object* apply(Object$* parent) override {
		 return $of($nc(inst$)->lambda$initRemotePackageMap$2(other, $cast($ModuleLayer, parent)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Loader$$Lambda$lambda$initRemotePackageMap$2$2>());
	}
	Loader* inst$ = nullptr;
	$ResolvedModule* other = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Loader$$Lambda$lambda$initRemotePackageMap$2$2::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Loader$$Lambda$lambda$initRemotePackageMap$2$2, inst$)},
	{"other", "Ljava/lang/module/ResolvedModule;", nullptr, $PUBLIC, $field(Loader$$Lambda$lambda$initRemotePackageMap$2$2, other)},
	{}
};
$MethodInfo Loader$$Lambda$lambda$initRemotePackageMap$2$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/loader/Loader;Ljava/lang/module/ResolvedModule;)V", nullptr, $PUBLIC, $method(Loader$$Lambda$lambda$initRemotePackageMap$2$2, init$, void, Loader*, $ResolvedModule*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Loader$$Lambda$lambda$initRemotePackageMap$2$2, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Loader$$Lambda$lambda$initRemotePackageMap$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.loader.Loader$$Lambda$lambda$initRemotePackageMap$2$2",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Loader$$Lambda$lambda$initRemotePackageMap$2$2::load$($String* name, bool initialize) {
	$loadClass(Loader$$Lambda$lambda$initRemotePackageMap$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Loader$$Lambda$lambda$initRemotePackageMap$2$2::class$ = nullptr;

class Loader$$Lambda$stream$3 : public $Function {
	$class(Loader$$Lambda$stream$3, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($Optional, inst$)->stream());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Loader$$Lambda$stream$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Loader$$Lambda$stream$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Loader$$Lambda$stream$3, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Loader$$Lambda$stream$3, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Loader$$Lambda$stream$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.loader.Loader$$Lambda$stream$3",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Loader$$Lambda$stream$3::load$($String* name, bool initialize) {
	$loadClass(Loader$$Lambda$stream$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Loader$$Lambda$stream$3::class$ = nullptr;

class Loader$$Lambda$lambda$initRemotePackageMap$3$4 : public $Supplier {
	$class(Loader$$Lambda$lambda$initRemotePackageMap$3$4, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(Loader::lambda$initRemotePackageMap$3());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Loader$$Lambda$lambda$initRemotePackageMap$3$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Loader$$Lambda$lambda$initRemotePackageMap$3$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Loader$$Lambda$lambda$initRemotePackageMap$3$4, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Loader$$Lambda$lambda$initRemotePackageMap$3$4, get, $Object*)},
	{}
};
$ClassInfo Loader$$Lambda$lambda$initRemotePackageMap$3$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.loader.Loader$$Lambda$lambda$initRemotePackageMap$3$4",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* Loader$$Lambda$lambda$initRemotePackageMap$3$4::load$($String* name, bool initialize) {
	$loadClass(Loader$$Lambda$lambda$initRemotePackageMap$3$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Loader$$Lambda$lambda$initRemotePackageMap$3$4::class$ = nullptr;

class Loader$$Lambda$lambda$initRemotePackageMap$4$5 : public $Consumer {
	$class(Loader$$Lambda$lambda$initRemotePackageMap$4$5, $NO_CLASS_INIT, $Consumer)
public:
	void init$(Loader* inst, $ClassLoader* l) {
		$set(this, inst$, inst);
		$set(this, l, l);
	}
	virtual void accept(Object$* pn) override {
		$nc(inst$)->lambda$initRemotePackageMap$4(l, $cast($String, pn));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Loader$$Lambda$lambda$initRemotePackageMap$4$5>());
	}
	Loader* inst$ = nullptr;
	$ClassLoader* l = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Loader$$Lambda$lambda$initRemotePackageMap$4$5::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Loader$$Lambda$lambda$initRemotePackageMap$4$5, inst$)},
	{"l", "Ljava/lang/ClassLoader;", nullptr, $PUBLIC, $field(Loader$$Lambda$lambda$initRemotePackageMap$4$5, l)},
	{}
};
$MethodInfo Loader$$Lambda$lambda$initRemotePackageMap$4$5::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/loader/Loader;Ljava/lang/ClassLoader;)V", nullptr, $PUBLIC, $method(Loader$$Lambda$lambda$initRemotePackageMap$4$5, init$, void, Loader*, $ClassLoader*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Loader$$Lambda$lambda$initRemotePackageMap$4$5, accept, void, Object$*)},
	{}
};
$ClassInfo Loader$$Lambda$lambda$initRemotePackageMap$4$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.loader.Loader$$Lambda$lambda$initRemotePackageMap$4$5",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* Loader$$Lambda$lambda$initRemotePackageMap$4$5::load$($String* name, bool initialize) {
	$loadClass(Loader$$Lambda$lambda$initRemotePackageMap$4$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Loader$$Lambda$lambda$initRemotePackageMap$4$5::class$ = nullptr;

class Loader$$Lambda$lambda$findModuleLayer$5$6 : public $Predicate {
	$class(Loader$$Lambda$lambda$findModuleLayer$5$6, $NO_CLASS_INIT, $Predicate)
public:
	void init$($Configuration* cf) {
		$set(this, cf, cf);
	}
	virtual bool test(Object$* l) override {
		 return Loader::lambda$findModuleLayer$5(cf, $cast($ModuleLayer, l));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Loader$$Lambda$lambda$findModuleLayer$5$6>());
	}
	$Configuration* cf = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Loader$$Lambda$lambda$findModuleLayer$5$6::fieldInfos[2] = {
	{"cf", "Ljava/lang/module/Configuration;", nullptr, $PUBLIC, $field(Loader$$Lambda$lambda$findModuleLayer$5$6, cf)},
	{}
};
$MethodInfo Loader$$Lambda$lambda$findModuleLayer$5$6::methodInfos[3] = {
	{"<init>", "(Ljava/lang/module/Configuration;)V", nullptr, $PUBLIC, $method(Loader$$Lambda$lambda$findModuleLayer$5$6, init$, void, $Configuration*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Loader$$Lambda$lambda$findModuleLayer$5$6, test, bool, Object$*)},
	{}
};
$ClassInfo Loader$$Lambda$lambda$findModuleLayer$5$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.loader.Loader$$Lambda$lambda$findModuleLayer$5$6",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* Loader$$Lambda$lambda$findModuleLayer$5$6::load$($String* name, bool initialize) {
	$loadClass(Loader$$Lambda$lambda$findModuleLayer$5$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Loader$$Lambda$lambda$findModuleLayer$5$6::class$ = nullptr;

class Loader$$Lambda$lambda$findClassInModuleOrNull$6$7 : public $PrivilegedAction {
	$class(Loader$$Lambda$lambda$findClassInModuleOrNull$6$7, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(Loader* inst, $String* cn, $Loader$LoadedModule* loadedModule) {
		$set(this, inst$, inst);
		$set(this, cn, cn);
		$set(this, loadedModule, loadedModule);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$findClassInModuleOrNull$6(cn, loadedModule));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Loader$$Lambda$lambda$findClassInModuleOrNull$6$7>());
	}
	Loader* inst$ = nullptr;
	$String* cn = nullptr;
	$Loader$LoadedModule* loadedModule = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Loader$$Lambda$lambda$findClassInModuleOrNull$6$7::fieldInfos[4] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Loader$$Lambda$lambda$findClassInModuleOrNull$6$7, inst$)},
	{"cn", "Ljava/lang/String;", nullptr, $PUBLIC, $field(Loader$$Lambda$lambda$findClassInModuleOrNull$6$7, cn)},
	{"loadedModule", "Ljdk/internal/loader/Loader$LoadedModule;", nullptr, $PUBLIC, $field(Loader$$Lambda$lambda$findClassInModuleOrNull$6$7, loadedModule)},
	{}
};
$MethodInfo Loader$$Lambda$lambda$findClassInModuleOrNull$6$7::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/loader/Loader;Ljava/lang/String;Ljdk/internal/loader/Loader$LoadedModule;)V", nullptr, $PUBLIC, $method(Loader$$Lambda$lambda$findClassInModuleOrNull$6$7, init$, void, Loader*, $String*, $Loader$LoadedModule*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Loader$$Lambda$lambda$findClassInModuleOrNull$6$7, run, $Object*)},
	{}
};
$ClassInfo Loader$$Lambda$lambda$findClassInModuleOrNull$6$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.loader.Loader$$Lambda$lambda$findClassInModuleOrNull$6$7",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* Loader$$Lambda$lambda$findClassInModuleOrNull$6$7::load$($String* name, bool initialize) {
	$loadClass(Loader$$Lambda$lambda$findClassInModuleOrNull$6$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Loader$$Lambda$lambda$findClassInModuleOrNull$6$7::class$ = nullptr;

class Loader$$Lambda$lambda$moduleReaderFor$7$8 : public $Function {
	$class(Loader$$Lambda$lambda$moduleReaderFor$7$8, $NO_CLASS_INIT, $Function)
public:
	void init$(Loader* inst, $ModuleReference* mref) {
		$set(this, inst$, inst);
		$set(this, mref, mref);
	}
	virtual $Object* apply(Object$* m) override {
		 return $of($nc(inst$)->lambda$moduleReaderFor$7(mref, $cast($ModuleReference, m)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Loader$$Lambda$lambda$moduleReaderFor$7$8>());
	}
	Loader* inst$ = nullptr;
	$ModuleReference* mref = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Loader$$Lambda$lambda$moduleReaderFor$7$8::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Loader$$Lambda$lambda$moduleReaderFor$7$8, inst$)},
	{"mref", "Ljava/lang/module/ModuleReference;", nullptr, $PUBLIC, $field(Loader$$Lambda$lambda$moduleReaderFor$7$8, mref)},
	{}
};
$MethodInfo Loader$$Lambda$lambda$moduleReaderFor$7$8::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/loader/Loader;Ljava/lang/module/ModuleReference;)V", nullptr, $PUBLIC, $method(Loader$$Lambda$lambda$moduleReaderFor$7$8, init$, void, Loader*, $ModuleReference*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Loader$$Lambda$lambda$moduleReaderFor$7$8, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Loader$$Lambda$lambda$moduleReaderFor$7$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.loader.Loader$$Lambda$lambda$moduleReaderFor$7$8",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Loader$$Lambda$lambda$moduleReaderFor$7$8::load$($String* name, bool initialize) {
	$loadClass(Loader$$Lambda$lambda$moduleReaderFor$7$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Loader$$Lambda$lambda$moduleReaderFor$7$8::class$ = nullptr;

$FieldInfo _Loader_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Loader, $assertionsDisabled)},
	{"pool", "Ljdk/internal/loader/LoaderPool;", nullptr, $PRIVATE | $FINAL, $field(Loader, pool$)},
	{"parent", "Ljava/lang/ClassLoader;", nullptr, $PRIVATE | $FINAL, $field(Loader, parent)},
	{"nameToModule", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/module/ModuleReference;>;", $PRIVATE | $FINAL, $field(Loader, nameToModule)},
	{"localPackageToModule", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljdk/internal/loader/Loader$LoadedModule;>;", $PRIVATE | $FINAL, $field(Loader, localPackageToModule)},
	{"remotePackageToLoader", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/ClassLoader;>;", $PRIVATE | $FINAL, $field(Loader, remotePackageToLoader)},
	{"moduleToReader", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/module/ModuleReference;Ljava/lang/module/ModuleReader;>;", $PRIVATE | $FINAL, $field(Loader, moduleToReader)},
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $FINAL, $field(Loader, acc)},
	{}
};

$MethodInfo _Loader_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/module/ResolvedModule;Ljdk/internal/loader/LoaderPool;Ljava/lang/ClassLoader;)V", nullptr, $PUBLIC, $method(Loader, init$, void, $ResolvedModule*, $LoaderPool*, $ClassLoader*)},
	{"<init>", "(Ljava/util/Collection;Ljava/lang/ClassLoader;)V", "(Ljava/util/Collection<Ljava/lang/module/ResolvedModule;>;Ljava/lang/ClassLoader;)V", $PUBLIC, $method(Loader, init$, void, $Collection*, $ClassLoader*)},
	{"createModuleReader", "(Ljava/lang/module/ModuleReference;)Ljava/lang/module/ModuleReader;", nullptr, $PRIVATE, $method(Loader, createModuleReader, $ModuleReader*, $ModuleReference*)},
	{"defineClass", "(Ljava/lang/String;Ljdk/internal/loader/Loader$LoadedModule;)Ljava/lang/Class;", "(Ljava/lang/String;Ljdk/internal/loader/Loader$LoadedModule;)Ljava/lang/Class<*>;", $PRIVATE, $method(Loader, defineClass, $Class*, $String*, $Loader$LoadedModule*)},
	{"findClass", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(Loader, findClass, $Class*, $String*), "java.lang.ClassNotFoundException"},
	{"findClass", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(Loader, findClass, $Class*, $String*, $String*)},
	{"findClassInModuleOrNull", "(Ljdk/internal/loader/Loader$LoadedModule;Ljava/lang/String;)Ljava/lang/Class;", "(Ljdk/internal/loader/Loader$LoadedModule;Ljava/lang/String;)Ljava/lang/Class<*>;", $PRIVATE, $method(Loader, findClassInModuleOrNull, $Class*, $Loader$LoadedModule*, $String*)},
	{"findLoadedModule", "(Ljava/lang/String;)Ljdk/internal/loader/Loader$LoadedModule;", nullptr, $PRIVATE, $method(Loader, findLoadedModule, $Loader$LoadedModule*, $String*)},
	{"findModuleLayer", "(Ljava/lang/ModuleLayer;Ljava/lang/module/Configuration;)Ljava/util/Optional;", "(Ljava/lang/ModuleLayer;Ljava/lang/module/Configuration;)Ljava/util/Optional<Ljava/lang/ModuleLayer;>;", $PRIVATE, $method(Loader, findModuleLayer, $Optional*, $ModuleLayer*, $Configuration*)},
	{"findResource", "(Ljava/lang/String;Ljava/lang/String;)Ljava/net/URL;", nullptr, $PROTECTED, $virtualMethod(Loader, findResource, $URL*, $String*, $String*), "java.io.IOException"},
	{"findResource", "(Ljava/lang/String;)Ljava/net/URL;", nullptr, $PUBLIC, $virtualMethod(Loader, findResource, $URL*, $String*)},
	{"findResources", "(Ljava/lang/String;)Ljava/util/Enumeration;", "(Ljava/lang/String;)Ljava/util/Enumeration<Ljava/net/URL;>;", $PUBLIC, $virtualMethod(Loader, findResources, $Enumeration*, $String*), "java.io.IOException"},
	{"findResourcesAsList", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Ljava/net/URL;>;", $PRIVATE, $method(Loader, findResourcesAsList, $List*, $String*), "java.io.IOException"},
	{"getPermissions", "(Ljava/security/CodeSource;)Ljava/security/PermissionCollection;", nullptr, $PROTECTED, $virtualMethod(Loader, getPermissions, $PermissionCollection*, $CodeSource*)},
	{"getResource", "(Ljava/lang/String;)Ljava/net/URL;", nullptr, $PUBLIC, $virtualMethod(Loader, getResource, $URL*, $String*)},
	{"getResources", "(Ljava/lang/String;)Ljava/util/Enumeration;", "(Ljava/lang/String;)Ljava/util/Enumeration<Ljava/net/URL;>;", $PUBLIC, $virtualMethod(Loader, getResources, $Enumeration*, $String*), "java.io.IOException"},
	{"initRemotePackageMap", "(Ljava/lang/module/Configuration;Ljava/util/List;)Ljdk/internal/loader/Loader;", "(Ljava/lang/module/Configuration;Ljava/util/List<Ljava/lang/ModuleLayer;>;)Ljdk/internal/loader/Loader;", $PUBLIC, $method(Loader, initRemotePackageMap, Loader*, $Configuration*, $List*)},
	{"isOpen", "(Ljava/lang/module/ModuleReference;Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(Loader, isOpen, bool, $ModuleReference*, $String*)},
	{"lambda$findClassInModuleOrNull$6", "(Ljava/lang/String;Ljdk/internal/loader/Loader$LoadedModule;)Ljava/lang/Class;", nullptr, $PRIVATE | $SYNTHETIC, $method(Loader, lambda$findClassInModuleOrNull$6, $Class*, $String*, $Loader$LoadedModule*)},
	{"lambda$findModuleLayer$5", "(Ljava/lang/module/Configuration;Ljava/lang/ModuleLayer;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Loader, lambda$findModuleLayer$5, bool, $Configuration*, $ModuleLayer*)},
	{"lambda$initRemotePackageMap$2", "(Ljava/lang/module/ResolvedModule;Ljava/lang/ModuleLayer;)Ljava/util/Optional;", nullptr, $PRIVATE | $SYNTHETIC, $method(Loader, lambda$initRemotePackageMap$2, $Optional*, $ResolvedModule*, $ModuleLayer*)},
	{"lambda$initRemotePackageMap$3", "()Ljava/lang/InternalError;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Loader, lambda$initRemotePackageMap$3, $InternalError*)},
	{"lambda$initRemotePackageMap$4", "(Ljava/lang/ClassLoader;Ljava/lang/String;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(Loader, lambda$initRemotePackageMap$4, void, $ClassLoader*, $String*)},
	{"lambda$moduleReaderFor$7", "(Ljava/lang/module/ModuleReference;Ljava/lang/module/ModuleReference;)Ljava/lang/module/ModuleReader;", nullptr, $PRIVATE | $SYNTHETIC, $method(Loader, lambda$moduleReaderFor$7, $ModuleReader*, $ModuleReference*, $ModuleReference*)},
	{"lambda$new$0", "(Ljava/util/Map;Ljdk/internal/loader/Loader$LoadedModule;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Loader, lambda$new$0, void, $Map*, $Loader$LoadedModule*, $String*)},
	{"lambda$new$1", "(Ljava/lang/module/ModuleReference;Ljava/util/Map;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Loader, lambda$new$1, void, $ModuleReference*, $Map*, $String*)},
	{"loadClass", "(Ljava/lang/String;Z)Ljava/lang/Class;", "(Ljava/lang/String;Z)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(Loader, loadClass, $Class*, $String*, bool), "java.lang.ClassNotFoundException"},
	{"moduleReaderFor", "(Ljava/lang/module/ModuleReference;)Ljava/lang/module/ModuleReader;", nullptr, $PRIVATE, $method(Loader, moduleReaderFor, $ModuleReader*, $ModuleReference*)},
	{"packageName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Loader, packageName, $String*, $String*)},
	{"pool", "()Ljdk/internal/loader/LoaderPool;", nullptr, $PUBLIC, $method(Loader, pool, $LoaderPool*)},
	{"remotePackage", "(Ljava/lang/String;Ljava/lang/ClassLoader;)V", nullptr, $PRIVATE, $method(Loader, remotePackage, void, $String*, $ClassLoader*)},
	{}
};

$InnerClassInfo _Loader_InnerClassesInfo_[] = {
	{"jdk.internal.loader.Loader$NullModuleReader", "jdk.internal.loader.Loader", "NullModuleReader", $PRIVATE | $STATIC},
	{"jdk.internal.loader.Loader$LoadedModule", "jdk.internal.loader.Loader", "LoadedModule", $PRIVATE | $STATIC},
	{"jdk.internal.loader.Loader$3", nullptr, nullptr, 0},
	{"jdk.internal.loader.Loader$2", nullptr, nullptr, 0},
	{"jdk.internal.loader.Loader$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Loader_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.loader.Loader",
	"java.security.SecureClassLoader",
	nullptr,
	_Loader_FieldInfo_,
	_Loader_MethodInfo_,
	nullptr,
	nullptr,
	_Loader_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.loader.Loader$NullModuleReader,jdk.internal.loader.Loader$LoadedModule,jdk.internal.loader.Loader$3,jdk.internal.loader.Loader$2,jdk.internal.loader.Loader$1"
};

$Object* allocate$Loader($Class* clazz) {
	return $of($alloc(Loader));
}

bool Loader::$assertionsDisabled = false;

void Loader::init$($ResolvedModule* resolvedModule, $LoaderPool* pool, $ClassLoader* parent) {
	$useLocalCurrentObjectStackCache();
	$SecureClassLoader::init$($$str({"Loader-"_s, $($nc(resolvedModule)->name())}), parent);
	$set(this, remotePackageToLoader, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
	$set(this, moduleToReader, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
	$set(this, pool$, pool);
	$set(this, parent, parent);
	$var($ModuleReference, mref, $nc(resolvedModule)->reference());
	$var($ModuleDescriptor, descriptor, $nc(mref)->descriptor());
	$var($String, mn, $nc(descriptor)->name());
	$set(this, nameToModule, $Map::of(mn, mref));
	$var($Map, localPackageToModule, $new($HashMap));
	$var($Loader$LoadedModule, lm, $new($Loader$LoadedModule, mref));
	$nc($(descriptor->packages()))->forEach(static_cast<$Consumer*>($$new(Loader$$Lambda$lambda$new$0, localPackageToModule, lm)));
	$set(this, localPackageToModule, localPackageToModule);
	$set(this, acc, $AccessController::getContext());
}

void Loader::init$($Collection* modules, $ClassLoader* parent) {
	$useLocalCurrentObjectStackCache();
	$SecureClassLoader::init$(parent);
	$set(this, remotePackageToLoader, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
	$set(this, moduleToReader, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
	$set(this, pool$, nullptr);
	$set(this, parent, parent);
	$var($Map, nameToModule, $new($HashMap));
	$var($Map, localPackageToModule, $new($HashMap));
	{
		$var($Iterator, i$, $nc(modules)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ResolvedModule, resolvedModule, $cast($ResolvedModule, i$->next()));
			{
				$var($ModuleReference, mref, $nc(resolvedModule)->reference());
				$var($ModuleDescriptor, descriptor, $nc(mref)->descriptor());
				nameToModule->put($($nc(descriptor)->name()), mref);
				$nc($($nc(descriptor)->packages()))->forEach(static_cast<$Consumer*>($$new(Loader$$Lambda$lambda$new$1$1, mref, localPackageToModule)));
			}
		}
	}
	$set(this, nameToModule, nameToModule);
	$set(this, localPackageToModule, localPackageToModule);
	$set(this, acc, $AccessController::getContext());
}

Loader* Loader::initRemotePackageMap($Configuration* cf, $List* parentModuleLayers) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($($nc(this->nameToModule)->keySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, name, $cast($String, i$->next()));
			{
				$var($ResolvedModule, resolvedModule, $cast($ResolvedModule, $nc($($nc(cf)->findModule(name)))->get()));
				if (!Loader::$assertionsDisabled && !($nc(resolvedModule)->configuration() == cf)) {
					$throwNew($AssertionError);
				}
				{
					$var($Iterator, i$, $nc($($nc(resolvedModule)->reads()))->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($ResolvedModule, other, $cast($ResolvedModule, i$->next()));
						{
							$var($String, mn, $nc(other)->name());
							$var($ClassLoader, loader, nullptr);
							if (other->configuration() == cf) {
								if (this->pool$ == nullptr) {
									if (!Loader::$assertionsDisabled && !$nc(this->nameToModule)->containsKey(mn)) {
										$throwNew($AssertionError);
									}
									continue;
								}
								$assign(loader, $nc(this->pool$)->loaderFor(mn));
								if (!Loader::$assertionsDisabled && !(loader != nullptr)) {
									$throwNew($AssertionError);
								}
							} else {
								$var($ModuleLayer, layer, $cast($ModuleLayer, $nc($($nc($($nc($($nc($($nc(parentModuleLayers)->stream()))->map(static_cast<$Function*>($$new(Loader$$Lambda$lambda$initRemotePackageMap$2$2, this, other)))))->flatMap(static_cast<$Function*>($$new(Loader$$Lambda$stream$3)))))->findAny()))->orElseThrow(static_cast<$Supplier*>($$new(Loader$$Lambda$lambda$initRemotePackageMap$3$4)))));
								if (!Loader::$assertionsDisabled && !$nc($($nc(layer)->findModule(mn)))->isPresent()) {
									$throwNew($AssertionError);
								}
								$assign(loader, $nc(layer)->findLoader(mn));
								if (loader == nullptr) {
									$assign(loader, $ClassLoaders::platformClassLoader());
								}
							}
							$var($ModuleDescriptor, descriptor, $nc($(other->reference()))->descriptor());
							if ($nc(descriptor)->isAutomatic()) {
								$var($ClassLoader, l, loader);
								$nc($(descriptor->packages()))->forEach(static_cast<$Consumer*>($$new(Loader$$Lambda$lambda$initRemotePackageMap$4$5, this, l)));
							} else {
								$var($String, target, resolvedModule->name());
								{
									$var($Iterator, i$, $nc($(descriptor->exports()))->iterator());
									for (; $nc(i$)->hasNext();) {
										$var($ModuleDescriptor$Exports, e, $cast($ModuleDescriptor$Exports, i$->next()));
										{
											bool delegate = false;
											if ($nc(e)->isQualified()) {
												bool var$0 = (other->configuration() == cf);
												delegate = var$0 && $nc($(e->targets()))->contains(target);
											} else {
												delegate = true;
											}
											if (delegate) {
												remotePackage($($nc(e)->source()), loader);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return this;
}

void Loader::remotePackage($String* pn, $ClassLoader* loader) {
	$useLocalCurrentObjectStackCache();
	$var($ClassLoader, l, $cast($ClassLoader, $nc(this->remotePackageToLoader)->putIfAbsent(pn, loader)));
	if (l != nullptr && l != loader) {
		$throwNew($IllegalStateException, $$str({"Package "_s, pn, " cannot be imported from multiple loaders"_s}));
	}
}

$Optional* Loader::findModuleLayer($ModuleLayer* parent, $Configuration* cf) {
	$useLocalCurrentObjectStackCache();
	return $nc($($nc($($nc($($SharedSecrets::getJavaLangAccess()))->layers(parent)))->filter(static_cast<$Predicate*>($$new(Loader$$Lambda$lambda$findModuleLayer$5$6, cf)))))->findAny();
}

$LoaderPool* Loader::pool() {
	return this->pool$;
}

$URL* Loader::findResource($String* mn, $String* name) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ModuleReference, mref, (mn != nullptr) ? $cast($ModuleReference, $nc(this->nameToModule)->get(mn)) : ($ModuleReference*)nullptr);
	if (mref == nullptr) {
		return nullptr;
	}
	$var($URL, url, nullptr);
	try {
		$assign(url, $cast($URL, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($Loader$1, this, mref, name)))));
	} catch ($PrivilegedActionException& pae) {
		$throw($cast($IOException, $(pae->getCause())));
	}
	if (url != nullptr && $System::getSecurityManager() != nullptr) {
		try {
			$var($URL, urlToCheck, url);
			$assign(url, $cast($URL, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($Loader$2, this, urlToCheck)), this->acc)));
		} catch ($PrivilegedActionException& pae) {
			$assign(url, nullptr);
		}
	}
	return url;
}

$URL* Loader::findResource($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($String, pn, $Resources::toPackageName(name));
	$var($Loader$LoadedModule, module, $cast($Loader$LoadedModule, $nc(this->localPackageToModule)->get(pn)));
	if (module != nullptr) {
		try {
			$var($URL, url, findResource($(module->name()), name));
			bool var$0 = url != nullptr;
			if (var$0) {
				bool var$2 = $nc(name)->endsWith(".class"_s);
				bool var$1 = var$2 || $nc($($nc(url)->toString()))->endsWith("/"_s);
				var$0 = (var$1 || isOpen($(module->mref()), pn));
			}
			if (var$0) {
				return url;
			}
		} catch ($IOException& ioe) {
		}
	} else {
		{
			$var($Iterator, i$, $nc($($nc(this->nameToModule)->values()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($ModuleReference, mref, $cast($ModuleReference, i$->next()));
				{
					try {
						$var($URL, url, findResource($($nc($($nc(mref)->descriptor()))->name()), name));
						if (url != nullptr) {
							return url;
						}
					} catch ($IOException& ioe) {
					}
				}
			}
		}
	}
	return nullptr;
}

$Enumeration* Loader::findResources($String* name) {
	return $Collections::enumeration($(findResourcesAsList(name)));
}

$URL* Loader::getResource($String* name) {
	$Objects::requireNonNull(name);
	$var($URL, url, findResource(name));
	if (url == nullptr) {
		if (this->parent != nullptr) {
			$assign(url, $nc(this->parent)->getResource(name));
		} else {
			$assign(url, $BootLoader::findResource(name));
		}
	}
	return url;
}

$Enumeration* Loader::getResources($String* name) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(name);
	$var($List, urls, findResourcesAsList(name));
	$var($Enumeration, e, nullptr);
	if (this->parent != nullptr) {
		$assign(e, $nc(this->parent)->getResources(name));
	} else {
		$assign(e, $BootLoader::findResources(name));
	}
	return $new($Loader$3, this, urls, e);
}

$List* Loader::findResourcesAsList($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($String, pn, $Resources::toPackageName(name));
	$var($Loader$LoadedModule, module, $cast($Loader$LoadedModule, $nc(this->localPackageToModule)->get(pn)));
	if (module != nullptr) {
		$var($URL, url, findResource($(module->name()), name));
		bool var$0 = url != nullptr;
		if (var$0) {
			bool var$2 = $nc(name)->endsWith(".class"_s);
			bool var$1 = var$2 || $nc($($nc(url)->toString()))->endsWith("/"_s);
			var$0 = (var$1 || isOpen($(module->mref()), pn));
		}
		if (var$0) {
			return $List::of($of(url));
		} else {
			return $Collections::emptyList();
		}
	} else {
		$var($List, urls, $new($ArrayList));
		{
			$var($Iterator, i$, $nc($($nc(this->nameToModule)->values()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($ModuleReference, mref, $cast($ModuleReference, i$->next()));
				{
					$var($URL, url, findResource($($nc($($nc(mref)->descriptor()))->name()), name));
					if (url != nullptr) {
						urls->add(url);
					}
				}
			}
		}
		return urls;
	}
}

$Class* Loader::findClass($String* cn) {
	$Class* c = nullptr;
	$var($Loader$LoadedModule, loadedModule, findLoadedModule(cn));
	if (loadedModule != nullptr) {
		c = findClassInModuleOrNull(loadedModule, cn);
	}
	if (c == nullptr) {
		$throwNew($ClassNotFoundException, cn);
	}
	return c;
}

$Class* Loader::findClass($String* mn, $String* cn) {
	$useLocalCurrentObjectStackCache();
	$Class* c = nullptr;
	$var($Loader$LoadedModule, loadedModule, findLoadedModule(cn));
	if (loadedModule != nullptr && $nc($(loadedModule->name()))->equals(mn)) {
		c = findClassInModuleOrNull(loadedModule, cn);
	}
	return c;
}

$Class* Loader::loadClass($String* cn, bool resolve) {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$var($String, pn, packageName(cn));
		if (!$nc(pn)->isEmpty()) {
			sm->checkPackageAccess(pn);
		}
	}
	$synchronized(getClassLoadingLock(cn)) {
		$Class* c = findLoadedClass(cn);
		if (c == nullptr) {
			$var($Loader$LoadedModule, loadedModule, findLoadedModule(cn));
			if (loadedModule != nullptr) {
				c = findClassInModuleOrNull(loadedModule, cn);
			} else {
				$var($String, pn, packageName(cn));
				$var($ClassLoader, loader, $cast($ClassLoader, $nc(this->remotePackageToLoader)->get(pn)));
				if (loader == nullptr) {
					$assign(loader, this->parent);
				}
				if (loader == nullptr) {
					c = $BootLoader::loadClassOrNull(cn);
				} else {
					c = $nc(loader)->loadClass(cn);
				}
			}
		}
		if (c == nullptr) {
			$throwNew($ClassNotFoundException, cn);
		}
		if (resolve) {
			resolveClass(c);
		}
		return c;
	}
}

$Class* Loader::findClassInModuleOrNull($Loader$LoadedModule* loadedModule, $String* cn) {
	$beforeCallerSensitive();
	$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(Loader$$Lambda$lambda$findClassInModuleOrNull$6$7, this, cn, loadedModule)));
	return $cast($Class, $AccessController::doPrivileged(pa, this->acc));
}

$Class* Loader::defineClass($String* cn, $Loader$LoadedModule* loadedModule) {
	$useLocalCurrentObjectStackCache();
	$var($ModuleReader, reader, moduleReaderFor($($nc(loadedModule)->mref())));
	try {
		$var($String, rn, $($nc(cn)->replace(u'.', u'/'))->concat(".class"_s));
		$var($ByteBuffer, bb, $cast($ByteBuffer, $nc($($nc(reader)->read(rn)))->orElse(nullptr)));
		if (bb == nullptr) {
			return nullptr;
		}
		{
			$var($Throwable, var$0, nullptr);
			$var($Class, var$2, nullptr);
			bool return$1 = false;
			try {
				var$2 = defineClass(cn, bb, $($nc(loadedModule)->codeSource()));
				return$1 = true;
				goto $finally;
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				reader->release(bb);
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	} catch ($IOException& ioe) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$PermissionCollection* Loader::getPermissions($CodeSource* cs) {
	$useLocalCurrentObjectStackCache();
	$var($PermissionCollection, perms, $SecureClassLoader::getPermissions(cs));
	$var($URL, url, $nc(cs)->getLocation());
	if (url == nullptr) {
		return perms;
	}
	try {
		$var($Permission, p, $nc($($nc(url)->openConnection()))->getPermission());
		if (p != nullptr) {
			if ($instanceOf($FilePermission, p)) {
				$var($String, path, p->getName());
				$init($File);
				if ($nc(path)->endsWith($File::separator)) {
					$plusAssign(path, "-"_s);
					$assign(p, $new($FilePermission, path, "read"_s));
				}
			}
			$nc(perms)->add(p);
		}
	} catch ($IOException& ioe) {
	}
	return perms;
}

$Loader$LoadedModule* Loader::findLoadedModule($String* cn) {
	$var($String, pn, packageName(cn));
	return $nc(pn)->isEmpty() ? ($Loader$LoadedModule*)nullptr : $cast($Loader$LoadedModule, $nc(this->localPackageToModule)->get(pn));
}

$String* Loader::packageName($String* cn) {
	int32_t pos = $nc(cn)->lastIndexOf((int32_t)u'.');
	return (pos < 0) ? ""_s : cn->substring(0, pos);
}

$ModuleReader* Loader::moduleReaderFor($ModuleReference* mref) {
	return $cast($ModuleReader, $nc(this->moduleToReader)->computeIfAbsent(mref, static_cast<$Function*>($$new(Loader$$Lambda$lambda$moduleReaderFor$7$8, this, mref))));
}

$ModuleReader* Loader::createModuleReader($ModuleReference* mref) {
	try {
		return $nc(mref)->open();
	} catch ($IOException& e) {
		return $new($Loader$NullModuleReader);
	}
	$shouldNotReachHere();
}

bool Loader::isOpen($ModuleReference* mref, $String* pn) {
	$useLocalCurrentObjectStackCache();
	$var($ModuleDescriptor, descriptor, $nc(mref)->descriptor());
	bool var$0 = $nc(descriptor)->isOpen();
	if (var$0 || $nc(descriptor)->isAutomatic()) {
		return true;
	}
	{
		$var($Iterator, i$, $nc($($nc(descriptor)->opens()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ModuleDescriptor$Opens, opens, $cast($ModuleDescriptor$Opens, i$->next()));
			{
				$var($String, source, $nc(opens)->source());
				bool var$1 = !opens->isQualified();
				if (var$1 && $nc(source)->equals(pn)) {
					return true;
				}
			}
		}
	}
	return false;
}

$ModuleReader* Loader::lambda$moduleReaderFor$7($ModuleReference* mref, $ModuleReference* m) {
	return createModuleReader(mref);
}

$Class* Loader::lambda$findClassInModuleOrNull$6($String* cn, $Loader$LoadedModule* loadedModule) {
	return defineClass(cn, loadedModule);
}

bool Loader::lambda$findModuleLayer$5($Configuration* cf, $ModuleLayer* l) {
	$init(Loader);
	return $nc(l)->configuration() == cf;
}

void Loader::lambda$initRemotePackageMap$4($ClassLoader* l, $String* pn) {
	remotePackage(pn, l);
}

$InternalError* Loader::lambda$initRemotePackageMap$3() {
	$init(Loader);
	return $new($InternalError, "Unable to find parent layer"_s);
}

$Optional* Loader::lambda$initRemotePackageMap$2($ResolvedModule* other, $ModuleLayer* parent) {
	return findModuleLayer(parent, $($nc(other)->configuration()));
}

void Loader::lambda$new$1($ModuleReference* mref, $Map* localPackageToModule, $String* pn) {
	$init(Loader);
	$useLocalCurrentObjectStackCache();
	$var($Loader$LoadedModule, lm, $new($Loader$LoadedModule, mref));
	if ($nc(localPackageToModule)->put(pn, lm) != nullptr) {
		$throwNew($IllegalArgumentException, $$str({"Package "_s, pn, " in more than one module"_s}));
	}
}

void Loader::lambda$new$0($Map* localPackageToModule, $Loader$LoadedModule* lm, $String* pn) {
	$init(Loader);
	$nc(localPackageToModule)->put(pn, lm);
}

void clinit$Loader($Class* class$) {
	$beforeCallerSensitive();
	Loader::$assertionsDisabled = !Loader::class$->desiredAssertionStatus();
	{
		$ClassLoader::registerAsParallelCapable();
	}
}

Loader::Loader() {
}

$Class* Loader::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Loader$$Lambda$lambda$new$0::classInfo$.name)) {
			return Loader$$Lambda$lambda$new$0::load$(name, initialize);
		}
		if (name->equals(Loader$$Lambda$lambda$new$1$1::classInfo$.name)) {
			return Loader$$Lambda$lambda$new$1$1::load$(name, initialize);
		}
		if (name->equals(Loader$$Lambda$lambda$initRemotePackageMap$2$2::classInfo$.name)) {
			return Loader$$Lambda$lambda$initRemotePackageMap$2$2::load$(name, initialize);
		}
		if (name->equals(Loader$$Lambda$stream$3::classInfo$.name)) {
			return Loader$$Lambda$stream$3::load$(name, initialize);
		}
		if (name->equals(Loader$$Lambda$lambda$initRemotePackageMap$3$4::classInfo$.name)) {
			return Loader$$Lambda$lambda$initRemotePackageMap$3$4::load$(name, initialize);
		}
		if (name->equals(Loader$$Lambda$lambda$initRemotePackageMap$4$5::classInfo$.name)) {
			return Loader$$Lambda$lambda$initRemotePackageMap$4$5::load$(name, initialize);
		}
		if (name->equals(Loader$$Lambda$lambda$findModuleLayer$5$6::classInfo$.name)) {
			return Loader$$Lambda$lambda$findModuleLayer$5$6::load$(name, initialize);
		}
		if (name->equals(Loader$$Lambda$lambda$findClassInModuleOrNull$6$7::classInfo$.name)) {
			return Loader$$Lambda$lambda$findClassInModuleOrNull$6$7::load$(name, initialize);
		}
		if (name->equals(Loader$$Lambda$lambda$moduleReaderFor$7$8::classInfo$.name)) {
			return Loader$$Lambda$lambda$moduleReaderFor$7$8::load$(name, initialize);
		}
	}
	$loadClass(Loader, name, initialize, &_Loader_ClassInfo_, clinit$Loader, allocate$Loader);
	return class$;
}

$Class* Loader::class$ = nullptr;

		} // loader
	} // internal
} // jdk