#include <jdk/internal/module/ModuleReferences.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/ModuleDescriptor.h>
#include <java/lang/module/ModuleReader.h>
#include <java/lang/module/ModuleReference.h>
#include <java/net/URI.h>
#include <java/nio/file/Path.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/module/ModuleHashes$HashSupplier.h>
#include <jdk/internal/module/ModuleHashes.h>
#include <jdk/internal/module/ModuleInfo$Attributes.h>
#include <jdk/internal/module/ModulePatcher.h>
#include <jdk/internal/module/ModuleReferenceImpl.h>
#include <jdk/internal/module/ModuleReferences$ExplodedModuleReader.h>
#include <jdk/internal/module/ModuleReferences$JModModuleReader.h>
#include <jdk/internal/module/ModuleReferences$JarModuleReader.h>
#include <jdk/internal/module/ModuleResolution.h>
#include <jdk/internal/module/ModuleTarget.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ModuleDescriptor = ::java::lang::module::ModuleDescriptor;
using $ModuleReader = ::java::lang::module::ModuleReader;
using $ModuleReference = ::java::lang::module::ModuleReference;
using $URI = ::java::net::URI;
using $Path = ::java::nio::file::Path;
using $Supplier = ::java::util::function::Supplier;
using $ModuleHashes = ::jdk::internal::module::ModuleHashes;
using $ModuleHashes$HashSupplier = ::jdk::internal::module::ModuleHashes$HashSupplier;
using $ModuleInfo$Attributes = ::jdk::internal::module::ModuleInfo$Attributes;
using $ModulePatcher = ::jdk::internal::module::ModulePatcher;
using $ModuleReferenceImpl = ::jdk::internal::module::ModuleReferenceImpl;
using $ModuleReferences$ExplodedModuleReader = ::jdk::internal::module::ModuleReferences$ExplodedModuleReader;
using $ModuleReferences$JModModuleReader = ::jdk::internal::module::ModuleReferences$JModModuleReader;
using $ModuleReferences$JarModuleReader = ::jdk::internal::module::ModuleReferences$JarModuleReader;
using $ModuleTarget = ::jdk::internal::module::ModuleTarget;

namespace jdk {
	namespace internal {
		namespace module {

class ModuleReferences$$Lambda$lambda$newJarModule$0 : public $Supplier {
	$class(ModuleReferences$$Lambda$lambda$newJarModule$0, $NO_CLASS_INIT, $Supplier)
public:
	void init$($Path* file, $URI* uri) {
		$set(this, file, file);
		$set(this, uri, uri);
	}
	virtual $Object* get() override {
		 return $of(ModuleReferences::lambda$newJarModule$0(file, uri));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleReferences$$Lambda$lambda$newJarModule$0>());
	}
	$Path* file = nullptr;
	$URI* uri = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModuleReferences$$Lambda$lambda$newJarModule$0::fieldInfos[3] = {
	{"file", "Ljava/nio/file/Path;", nullptr, $PUBLIC, $field(ModuleReferences$$Lambda$lambda$newJarModule$0, file)},
	{"uri", "Ljava/net/URI;", nullptr, $PUBLIC, $field(ModuleReferences$$Lambda$lambda$newJarModule$0, uri)},
	{}
};
$MethodInfo ModuleReferences$$Lambda$lambda$newJarModule$0::methodInfos[3] = {
	{"<init>", "(Ljava/nio/file/Path;Ljava/net/URI;)V", nullptr, $PUBLIC, $method(ModuleReferences$$Lambda$lambda$newJarModule$0, init$, void, $Path*, $URI*)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModuleReferences$$Lambda$lambda$newJarModule$0, get, $Object*)},
	{}
};
$ClassInfo ModuleReferences$$Lambda$lambda$newJarModule$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleReferences$$Lambda$lambda$newJarModule$0",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* ModuleReferences$$Lambda$lambda$newJarModule$0::load$($String* name, bool initialize) {
	$loadClass(ModuleReferences$$Lambda$lambda$newJarModule$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleReferences$$Lambda$lambda$newJarModule$0::class$ = nullptr;

class ModuleReferences$$Lambda$lambda$newJarModule$1$1 : public $ModuleHashes$HashSupplier {
	$class(ModuleReferences$$Lambda$lambda$newJarModule$1$1, $NO_CLASS_INIT, $ModuleHashes$HashSupplier)
public:
	void init$($Supplier* supplier) {
		$set(this, supplier, supplier);
	}
	virtual $bytes* generate($String* a) override {
		 return ModuleReferences::lambda$newJarModule$1(supplier, a);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleReferences$$Lambda$lambda$newJarModule$1$1>());
	}
	$Supplier* supplier = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModuleReferences$$Lambda$lambda$newJarModule$1$1::fieldInfos[2] = {
	{"supplier", "Ljava/util/function/Supplier;", nullptr, $PUBLIC, $field(ModuleReferences$$Lambda$lambda$newJarModule$1$1, supplier)},
	{}
};
$MethodInfo ModuleReferences$$Lambda$lambda$newJarModule$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/Supplier;)V", nullptr, $PUBLIC, $method(ModuleReferences$$Lambda$lambda$newJarModule$1$1, init$, void, $Supplier*)},
	{"generate", "(Ljava/lang/String;)[B", nullptr, $PUBLIC, $virtualMethod(ModuleReferences$$Lambda$lambda$newJarModule$1$1, generate, $bytes*, $String*)},
	{}
};
$ClassInfo ModuleReferences$$Lambda$lambda$newJarModule$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleReferences$$Lambda$lambda$newJarModule$1$1",
	"java.lang.Object",
	"jdk.internal.module.ModuleHashes$HashSupplier",
	fieldInfos,
	methodInfos
};
$Class* ModuleReferences$$Lambda$lambda$newJarModule$1$1::load$($String* name, bool initialize) {
	$loadClass(ModuleReferences$$Lambda$lambda$newJarModule$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleReferences$$Lambda$lambda$newJarModule$1$1::class$ = nullptr;

class ModuleReferences$$Lambda$lambda$newJModModule$2$2 : public $Supplier {
	$class(ModuleReferences$$Lambda$lambda$newJModModule$2$2, $NO_CLASS_INIT, $Supplier)
public:
	void init$($Path* file, $URI* uri) {
		$set(this, file, file);
		$set(this, uri, uri);
	}
	virtual $Object* get() override {
		 return $of(ModuleReferences::lambda$newJModModule$2(file, uri));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleReferences$$Lambda$lambda$newJModModule$2$2>());
	}
	$Path* file = nullptr;
	$URI* uri = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModuleReferences$$Lambda$lambda$newJModModule$2$2::fieldInfos[3] = {
	{"file", "Ljava/nio/file/Path;", nullptr, $PUBLIC, $field(ModuleReferences$$Lambda$lambda$newJModModule$2$2, file)},
	{"uri", "Ljava/net/URI;", nullptr, $PUBLIC, $field(ModuleReferences$$Lambda$lambda$newJModModule$2$2, uri)},
	{}
};
$MethodInfo ModuleReferences$$Lambda$lambda$newJModModule$2$2::methodInfos[3] = {
	{"<init>", "(Ljava/nio/file/Path;Ljava/net/URI;)V", nullptr, $PUBLIC, $method(ModuleReferences$$Lambda$lambda$newJModModule$2$2, init$, void, $Path*, $URI*)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModuleReferences$$Lambda$lambda$newJModModule$2$2, get, $Object*)},
	{}
};
$ClassInfo ModuleReferences$$Lambda$lambda$newJModModule$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleReferences$$Lambda$lambda$newJModModule$2$2",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* ModuleReferences$$Lambda$lambda$newJModModule$2$2::load$($String* name, bool initialize) {
	$loadClass(ModuleReferences$$Lambda$lambda$newJModModule$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleReferences$$Lambda$lambda$newJModModule$2$2::class$ = nullptr;

class ModuleReferences$$Lambda$lambda$newExplodedModule$4$3 : public $Supplier {
	$class(ModuleReferences$$Lambda$lambda$newExplodedModule$4$3, $NO_CLASS_INIT, $Supplier)
public:
	void init$($Path* dir) {
		$set(this, dir, dir);
	}
	virtual $Object* get() override {
		 return $of(ModuleReferences::lambda$newExplodedModule$4(dir));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleReferences$$Lambda$lambda$newExplodedModule$4$3>());
	}
	$Path* dir = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModuleReferences$$Lambda$lambda$newExplodedModule$4$3::fieldInfos[2] = {
	{"dir", "Ljava/nio/file/Path;", nullptr, $PUBLIC, $field(ModuleReferences$$Lambda$lambda$newExplodedModule$4$3, dir)},
	{}
};
$MethodInfo ModuleReferences$$Lambda$lambda$newExplodedModule$4$3::methodInfos[3] = {
	{"<init>", "(Ljava/nio/file/Path;)V", nullptr, $PUBLIC, $method(ModuleReferences$$Lambda$lambda$newExplodedModule$4$3, init$, void, $Path*)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModuleReferences$$Lambda$lambda$newExplodedModule$4$3, get, $Object*)},
	{}
};
$ClassInfo ModuleReferences$$Lambda$lambda$newExplodedModule$4$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleReferences$$Lambda$lambda$newExplodedModule$4$3",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* ModuleReferences$$Lambda$lambda$newExplodedModule$4$3::load$($String* name, bool initialize) {
	$loadClass(ModuleReferences$$Lambda$lambda$newExplodedModule$4$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleReferences$$Lambda$lambda$newExplodedModule$4$3::class$ = nullptr;

$MethodInfo _ModuleReferences_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ModuleReferences, init$, void)},
	{"lambda$newExplodedModule$4", "(Ljava/nio/file/Path;)Ljava/lang/module/ModuleReader;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModuleReferences, lambda$newExplodedModule$4, $ModuleReader*, $Path*)},
	{"lambda$newJModModule$2", "(Ljava/nio/file/Path;Ljava/net/URI;)Ljava/lang/module/ModuleReader;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModuleReferences, lambda$newJModModule$2, $ModuleReader*, $Path*, $URI*)},
	{"lambda$newJarModule$0", "(Ljava/nio/file/Path;Ljava/net/URI;)Ljava/lang/module/ModuleReader;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModuleReferences, lambda$newJarModule$0, $ModuleReader*, $Path*, $URI*)},
	{"lambda$newJarModule$1", "(Ljava/util/function/Supplier;Ljava/lang/String;)[B", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModuleReferences, lambda$newJarModule$1, $bytes*, $Supplier*, $String*)},
	{"newExplodedModule", "(Ljdk/internal/module/ModuleInfo$Attributes;Ljdk/internal/module/ModulePatcher;Ljava/nio/file/Path;)Ljava/lang/module/ModuleReference;", nullptr, $STATIC, $staticMethod(ModuleReferences, newExplodedModule, $ModuleReference*, $ModuleInfo$Attributes*, $ModulePatcher*, $Path*)},
	{"newJModModule", "(Ljdk/internal/module/ModuleInfo$Attributes;Ljava/nio/file/Path;)Ljava/lang/module/ModuleReference;", nullptr, $STATIC, $staticMethod(ModuleReferences, newJModModule, $ModuleReference*, $ModuleInfo$Attributes*, $Path*)},
	{"newJarModule", "(Ljdk/internal/module/ModuleInfo$Attributes;Ljdk/internal/module/ModulePatcher;Ljava/nio/file/Path;)Ljava/lang/module/ModuleReference;", nullptr, $STATIC, $staticMethod(ModuleReferences, newJarModule, $ModuleReference*, $ModuleInfo$Attributes*, $ModulePatcher*, $Path*)},
	{"newModule", "(Ljdk/internal/module/ModuleInfo$Attributes;Ljava/net/URI;Ljava/util/function/Supplier;Ljdk/internal/module/ModulePatcher;Ljdk/internal/module/ModuleHashes$HashSupplier;)Ljava/lang/module/ModuleReference;", "(Ljdk/internal/module/ModuleInfo$Attributes;Ljava/net/URI;Ljava/util/function/Supplier<Ljava/lang/module/ModuleReader;>;Ljdk/internal/module/ModulePatcher;Ljdk/internal/module/ModuleHashes$HashSupplier;)Ljava/lang/module/ModuleReference;", $PRIVATE | $STATIC, $staticMethod(ModuleReferences, newModule, $ModuleReference*, $ModuleInfo$Attributes*, $URI*, $Supplier*, $ModulePatcher*, $ModuleHashes$HashSupplier*)},
	{}
};

$InnerClassInfo _ModuleReferences_InnerClassesInfo_[] = {
	{"jdk.internal.module.ModuleReferences$ExplodedModuleReader", "jdk.internal.module.ModuleReferences", "ExplodedModuleReader", $STATIC},
	{"jdk.internal.module.ModuleReferences$JModModuleReader", "jdk.internal.module.ModuleReferences", "JModModuleReader", $STATIC},
	{"jdk.internal.module.ModuleReferences$JarModuleReader", "jdk.internal.module.ModuleReferences", "JarModuleReader", $STATIC},
	{"jdk.internal.module.ModuleReferences$SafeCloseModuleReader", "jdk.internal.module.ModuleReferences", "SafeCloseModuleReader", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _ModuleReferences_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.module.ModuleReferences",
	"java.lang.Object",
	nullptr,
	nullptr,
	_ModuleReferences_MethodInfo_,
	nullptr,
	nullptr,
	_ModuleReferences_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.module.ModuleReferences$ExplodedModuleReader,jdk.internal.module.ModuleReferences$JModModuleReader,jdk.internal.module.ModuleReferences$JarModuleReader,jdk.internal.module.ModuleReferences$SafeCloseModuleReader"
};

$Object* allocate$ModuleReferences($Class* clazz) {
	return $of($alloc(ModuleReferences));
}

void ModuleReferences::init$() {
}

$ModuleReference* ModuleReferences::newModule($ModuleInfo$Attributes* attrs, $URI* uri, $Supplier* supplier, $ModulePatcher* patcher, $ModuleHashes$HashSupplier* hasher) {
	$useLocalCurrentObjectStackCache();
	$var($ModuleDescriptor, var$0, $nc(attrs)->descriptor());
	$var($URI, var$1, uri);
	$var($Supplier, var$2, supplier);
	$var($ModuleTarget, var$3, attrs->target());
	$var($ModuleHashes, var$4, attrs->recordedHashes());
	$var($ModuleHashes$HashSupplier, var$5, hasher);
	$var($ModuleReference, mref, $new($ModuleReferenceImpl, var$0, var$1, var$2, nullptr, var$3, var$4, var$5, $(attrs->moduleResolution())));
	if (patcher != nullptr) {
		$assign(mref, patcher->patchIfNeeded(mref));
	}
	return mref;
}

$ModuleReference* ModuleReferences::newJarModule($ModuleInfo$Attributes* attrs, $ModulePatcher* patcher, $Path* file) {
	$useLocalCurrentObjectStackCache();
	$var($URI, uri, $nc(file)->toUri());
	$var($Supplier, supplier, static_cast<$Supplier*>($new(ModuleReferences$$Lambda$lambda$newJarModule$0, file, uri)));
	$var($ModuleHashes$HashSupplier, hasher, static_cast<$ModuleHashes$HashSupplier*>($new(ModuleReferences$$Lambda$lambda$newJarModule$1$1, supplier)));
	return newModule(attrs, uri, supplier, patcher, hasher);
}

$ModuleReference* ModuleReferences::newJModModule($ModuleInfo$Attributes* attrs, $Path* file) {
	$useLocalCurrentObjectStackCache();
	$var($URI, uri, $nc(file)->toUri());
	$var($Supplier, supplier, static_cast<$Supplier*>($new(ModuleReferences$$Lambda$lambda$newJModModule$2$2, file, uri)));
	$var($ModuleHashes$HashSupplier, hasher, static_cast<$ModuleHashes$HashSupplier*>($new(ModuleReferences$$Lambda$lambda$newJarModule$1$1, supplier)));
	return newModule(attrs, uri, supplier, nullptr, hasher);
}

$ModuleReference* ModuleReferences::newExplodedModule($ModuleInfo$Attributes* attrs, $ModulePatcher* patcher, $Path* dir) {
	$useLocalCurrentObjectStackCache();
	$var($Supplier, supplier, static_cast<$Supplier*>($new(ModuleReferences$$Lambda$lambda$newExplodedModule$4$3, dir)));
	return newModule(attrs, $($nc(dir)->toUri()), supplier, patcher, nullptr);
}

$ModuleReader* ModuleReferences::lambda$newExplodedModule$4($Path* dir) {
	return $new($ModuleReferences$ExplodedModuleReader, dir);
}

$ModuleReader* ModuleReferences::lambda$newJModModule$2($Path* file, $URI* uri) {
	return $new($ModuleReferences$JModModuleReader, file, uri);
}

$bytes* ModuleReferences::lambda$newJarModule$1($Supplier* supplier, $String* a) {
	return $ModuleHashes::computeHash(supplier, a);
}

$ModuleReader* ModuleReferences::lambda$newJarModule$0($Path* file, $URI* uri) {
	return $new($ModuleReferences$JarModuleReader, file, uri);
}

ModuleReferences::ModuleReferences() {
}

$Class* ModuleReferences::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ModuleReferences$$Lambda$lambda$newJarModule$0::classInfo$.name)) {
			return ModuleReferences$$Lambda$lambda$newJarModule$0::load$(name, initialize);
		}
		if (name->equals(ModuleReferences$$Lambda$lambda$newJarModule$1$1::classInfo$.name)) {
			return ModuleReferences$$Lambda$lambda$newJarModule$1$1::load$(name, initialize);
		}
		if (name->equals(ModuleReferences$$Lambda$lambda$newJModModule$2$2::classInfo$.name)) {
			return ModuleReferences$$Lambda$lambda$newJModModule$2$2::load$(name, initialize);
		}
		if (name->equals(ModuleReferences$$Lambda$lambda$newExplodedModule$4$3::classInfo$.name)) {
			return ModuleReferences$$Lambda$lambda$newExplodedModule$4$3::load$(name, initialize);
		}
	}
	$loadClass(ModuleReferences, name, initialize, &_ModuleReferences_ClassInfo_, allocate$ModuleReferences);
	return class$;
}

$Class* ModuleReferences::class$ = nullptr;

		} // module
	} // internal
} // jdk