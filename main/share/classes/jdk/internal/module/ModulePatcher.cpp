#include <jdk/internal/module/ModulePatcher.h>

#include <java/io/File.h>
#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/ModuleDescriptor$Builder.h>
#include <java/lang/module/ModuleDescriptor$Exports.h>
#include <java/lang/module/ModuleDescriptor$Opens.h>
#include <java/lang/module/ModuleDescriptor$Provides.h>
#include <java/lang/module/ModuleDescriptor$Requires.h>
#include <java/lang/module/ModuleDescriptor$Version.h>
#include <java/lang/module/ModuleDescriptor.h>
#include <java/lang/module/ModuleReader.h>
#include <java/lang/module/ModuleReference.h>
#include <java/net/URI.h>
#include <java/nio/file/FileVisitOption.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/Paths.h>
#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/function/BiPredicate.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/function/Supplier.h>
#include <java/util/jar/JarEntry.h>
#include <java/util/jar/JarFile.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/access/JavaLangModuleAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/module/Checks.h>
#include <jdk/internal/module/ModuleHashes$HashSupplier.h>
#include <jdk/internal/module/ModuleHashes.h>
#include <jdk/internal/module/ModulePatcher$PatchedModuleReader.h>
#include <jdk/internal/module/ModuleReferenceImpl.h>
#include <jdk/internal/module/ModuleResolution.h>
#include <jdk/internal/module/ModuleTarget.h>
#include <jcpp.h>

#undef JLMA
#undef MAX_VALUE

using $FileVisitOptionArray = $Array<::java::nio::file::FileVisitOption>;
using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $File = ::java::io::File;
using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ModuleDescriptor = ::java::lang::module::ModuleDescriptor;
using $ModuleDescriptor$Builder = ::java::lang::module::ModuleDescriptor$Builder;
using $ModuleDescriptor$Exports = ::java::lang::module::ModuleDescriptor$Exports;
using $ModuleDescriptor$Opens = ::java::lang::module::ModuleDescriptor$Opens;
using $ModuleDescriptor$Provides = ::java::lang::module::ModuleDescriptor$Provides;
using $ModuleDescriptor$Requires = ::java::lang::module::ModuleDescriptor$Requires;
using $ModuleDescriptor$Version = ::java::lang::module::ModuleDescriptor$Version;
using $ModuleReader = ::java::lang::module::ModuleReader;
using $ModuleReference = ::java::lang::module::ModuleReference;
using $URI = ::java::net::URI;
using $Files = ::java::nio::file::Files;
using $Path = ::java::nio::file::Path;
using $Paths = ::java::nio::file::Paths;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $BiPredicate = ::java::util::function::BiPredicate;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $Supplier = ::java::util::function::Supplier;
using $JarEntry = ::java::util::jar::JarEntry;
using $JarFile = ::java::util::jar::JarFile;
using $Stream = ::java::util::stream::Stream;
using $JavaLangModuleAccess = ::jdk::internal::access::JavaLangModuleAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $Checks = ::jdk::internal::module::Checks;
using $ModuleHashes = ::jdk::internal::module::ModuleHashes;
using $ModuleHashes$HashSupplier = ::jdk::internal::module::ModuleHashes$HashSupplier;
using $ModulePatcher$PatchedModuleReader = ::jdk::internal::module::ModulePatcher$PatchedModuleReader;
using $ModuleReferenceImpl = ::jdk::internal::module::ModuleReferenceImpl;
using $ModuleResolution = ::jdk::internal::module::ModuleResolution;
using $ModuleTarget = ::jdk::internal::module::ModuleTarget;

namespace jdk {
	namespace internal {
		namespace module {

class ModulePatcher$$Lambda$lambda$new$0 : public $Function {
	$class(ModulePatcher$$Lambda$lambda$new$0, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* x$0) override {
		 return $of(ModulePatcher::lambda$new$0($cast($String, x$0)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePatcher$$Lambda$lambda$new$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ModulePatcher$$Lambda$lambda$new$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModulePatcher$$Lambda$lambda$new$0, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModulePatcher$$Lambda$lambda$new$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ModulePatcher$$Lambda$lambda$new$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePatcher$$Lambda$lambda$new$0",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ModulePatcher$$Lambda$lambda$new$0::load$($String* name, bool initialize) {
	$loadClass(ModulePatcher$$Lambda$lambda$new$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePatcher$$Lambda$lambda$new$0::class$ = nullptr;

class ModulePatcher$$Lambda$lambda$patchIfNeeded$1$1 : public $Predicate {
	$class(ModulePatcher$$Lambda$lambda$patchIfNeeded$1$1, $NO_CLASS_INIT, $Predicate)
public:
	void init$(bool isAutomatic) {
		this->isAutomatic = isAutomatic;
	}
	virtual bool test(Object$* e) override {
		 return ModulePatcher::lambda$patchIfNeeded$1(isAutomatic, $cast($JarEntry, e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePatcher$$Lambda$lambda$patchIfNeeded$1$1>());
	}
	bool isAutomatic = false;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModulePatcher$$Lambda$lambda$patchIfNeeded$1$1::fieldInfos[2] = {
	{"isAutomatic", "Z", nullptr, $PUBLIC, $field(ModulePatcher$$Lambda$lambda$patchIfNeeded$1$1, isAutomatic)},
	{}
};
$MethodInfo ModulePatcher$$Lambda$lambda$patchIfNeeded$1$1::methodInfos[3] = {
	{"<init>", "(Z)V", nullptr, $PUBLIC, $method(ModulePatcher$$Lambda$lambda$patchIfNeeded$1$1, init$, void, bool)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ModulePatcher$$Lambda$lambda$patchIfNeeded$1$1, test, bool, Object$*)},
	{}
};
$ClassInfo ModulePatcher$$Lambda$lambda$patchIfNeeded$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePatcher$$Lambda$lambda$patchIfNeeded$1$1",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* ModulePatcher$$Lambda$lambda$patchIfNeeded$1$1::load$($String* name, bool initialize) {
	$loadClass(ModulePatcher$$Lambda$lambda$patchIfNeeded$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePatcher$$Lambda$lambda$patchIfNeeded$1$1::class$ = nullptr;

class ModulePatcher$$Lambda$lambda$patchIfNeeded$2$2 : public $Function {
	$class(ModulePatcher$$Lambda$lambda$patchIfNeeded$2$2, $NO_CLASS_INIT, $Function)
public:
	void init$($Path* file) {
		$set(this, file, file);
	}
	virtual $Object* apply(Object$* e) override {
		 return $of(ModulePatcher::lambda$patchIfNeeded$2(file, $cast($JarEntry, e)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePatcher$$Lambda$lambda$patchIfNeeded$2$2>());
	}
	$Path* file = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModulePatcher$$Lambda$lambda$patchIfNeeded$2$2::fieldInfos[2] = {
	{"file", "Ljava/nio/file/Path;", nullptr, $PUBLIC, $field(ModulePatcher$$Lambda$lambda$patchIfNeeded$2$2, file)},
	{}
};
$MethodInfo ModulePatcher$$Lambda$lambda$patchIfNeeded$2$2::methodInfos[3] = {
	{"<init>", "(Ljava/nio/file/Path;)V", nullptr, $PUBLIC, $method(ModulePatcher$$Lambda$lambda$patchIfNeeded$2$2, init$, void, $Path*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModulePatcher$$Lambda$lambda$patchIfNeeded$2$2, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ModulePatcher$$Lambda$lambda$patchIfNeeded$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePatcher$$Lambda$lambda$patchIfNeeded$2$2",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* ModulePatcher$$Lambda$lambda$patchIfNeeded$2$2::load$($String* name, bool initialize) {
	$loadClass(ModulePatcher$$Lambda$lambda$patchIfNeeded$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePatcher$$Lambda$lambda$patchIfNeeded$2$2::class$ = nullptr;

class ModulePatcher$$Lambda$isPackageName$3 : public $Predicate {
	$class(ModulePatcher$$Lambda$isPackageName$3, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* name) override {
		 return $Checks::isPackageName($cast($String, name));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePatcher$$Lambda$isPackageName$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ModulePatcher$$Lambda$isPackageName$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModulePatcher$$Lambda$isPackageName$3, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ModulePatcher$$Lambda$isPackageName$3, test, bool, Object$*)},
	{}
};
$ClassInfo ModulePatcher$$Lambda$isPackageName$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePatcher$$Lambda$isPackageName$3",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* ModulePatcher$$Lambda$isPackageName$3::load$($String* name, bool initialize) {
	$loadClass(ModulePatcher$$Lambda$isPackageName$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePatcher$$Lambda$isPackageName$3::class$ = nullptr;

class ModulePatcher$$Lambda$add$4 : public $Consumer {
	$class(ModulePatcher$$Lambda$add$4, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Set* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* e) override {
		$nc(inst$)->add(e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePatcher$$Lambda$add$4>());
	}
	$Set* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModulePatcher$$Lambda$add$4::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ModulePatcher$$Lambda$add$4, inst$)},
	{}
};
$MethodInfo ModulePatcher$$Lambda$add$4::methodInfos[3] = {
	{"<init>", "(Ljava/util/Set;)V", nullptr, $PUBLIC, $method(ModulePatcher$$Lambda$add$4, init$, void, $Set*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ModulePatcher$$Lambda$add$4, accept, void, Object$*)},
	{}
};
$ClassInfo ModulePatcher$$Lambda$add$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePatcher$$Lambda$add$4",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ModulePatcher$$Lambda$add$4::load$($String* name, bool initialize) {
	$loadClass(ModulePatcher$$Lambda$add$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePatcher$$Lambda$add$4::class$ = nullptr;

class ModulePatcher$$Lambda$lambda$patchIfNeeded$3$5 : public $BiPredicate {
	$class(ModulePatcher$$Lambda$lambda$patchIfNeeded$3$5, $NO_CLASS_INIT, $BiPredicate)
public:
	void init$() {
	}
	virtual bool test(Object$* path, Object$* attrs) override {
		 return ModulePatcher::lambda$patchIfNeeded$3($cast($Path, path), $cast($BasicFileAttributes, attrs));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePatcher$$Lambda$lambda$patchIfNeeded$3$5>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ModulePatcher$$Lambda$lambda$patchIfNeeded$3$5::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModulePatcher$$Lambda$lambda$patchIfNeeded$3$5, init$, void)},
	{"test", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ModulePatcher$$Lambda$lambda$patchIfNeeded$3$5, test, bool, Object$*, Object$*)},
	{}
};
$ClassInfo ModulePatcher$$Lambda$lambda$patchIfNeeded$3$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePatcher$$Lambda$lambda$patchIfNeeded$3$5",
	"java.lang.Object",
	"java.util.function.BiPredicate",
	nullptr,
	methodInfos
};
$Class* ModulePatcher$$Lambda$lambda$patchIfNeeded$3$5::load$($String* name, bool initialize) {
	$loadClass(ModulePatcher$$Lambda$lambda$patchIfNeeded$3$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePatcher$$Lambda$lambda$patchIfNeeded$3$5::class$ = nullptr;

class ModulePatcher$$Lambda$lambda$patchIfNeeded$4$6 : public $Predicate {
	$class(ModulePatcher$$Lambda$lambda$patchIfNeeded$4$6, $NO_CLASS_INIT, $Predicate)
public:
	void init$(ModulePatcher* inst, bool isAutomatic) {
		$set(this, inst$, inst);
		this->isAutomatic = isAutomatic;
	}
	virtual bool test(Object$* path) override {
		 return $nc(inst$)->lambda$patchIfNeeded$4(isAutomatic, $cast($Path, path));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePatcher$$Lambda$lambda$patchIfNeeded$4$6>());
	}
	ModulePatcher* inst$ = nullptr;
	bool isAutomatic = false;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModulePatcher$$Lambda$lambda$patchIfNeeded$4$6::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ModulePatcher$$Lambda$lambda$patchIfNeeded$4$6, inst$)},
	{"isAutomatic", "Z", nullptr, $PUBLIC, $field(ModulePatcher$$Lambda$lambda$patchIfNeeded$4$6, isAutomatic)},
	{}
};
$MethodInfo ModulePatcher$$Lambda$lambda$patchIfNeeded$4$6::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/module/ModulePatcher;Z)V", nullptr, $PUBLIC, $method(ModulePatcher$$Lambda$lambda$patchIfNeeded$4$6, init$, void, ModulePatcher*, bool)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ModulePatcher$$Lambda$lambda$patchIfNeeded$4$6, test, bool, Object$*)},
	{}
};
$ClassInfo ModulePatcher$$Lambda$lambda$patchIfNeeded$4$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePatcher$$Lambda$lambda$patchIfNeeded$4$6",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* ModulePatcher$$Lambda$lambda$patchIfNeeded$4$6::load$($String* name, bool initialize) {
	$loadClass(ModulePatcher$$Lambda$lambda$patchIfNeeded$4$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePatcher$$Lambda$lambda$patchIfNeeded$4$6::class$ = nullptr;

class ModulePatcher$$Lambda$lambda$patchIfNeeded$5$7 : public $Function {
	$class(ModulePatcher$$Lambda$lambda$patchIfNeeded$5$7, $NO_CLASS_INIT, $Function)
public:
	void init$($Path* top) {
		$set(this, top, top);
	}
	virtual $Object* apply(Object$* path) override {
		 return $of(ModulePatcher::lambda$patchIfNeeded$5(top, $cast($Path, path)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePatcher$$Lambda$lambda$patchIfNeeded$5$7>());
	}
	$Path* top = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModulePatcher$$Lambda$lambda$patchIfNeeded$5$7::fieldInfos[2] = {
	{"top", "Ljava/nio/file/Path;", nullptr, $PUBLIC, $field(ModulePatcher$$Lambda$lambda$patchIfNeeded$5$7, top)},
	{}
};
$MethodInfo ModulePatcher$$Lambda$lambda$patchIfNeeded$5$7::methodInfos[3] = {
	{"<init>", "(Ljava/nio/file/Path;)V", nullptr, $PUBLIC, $method(ModulePatcher$$Lambda$lambda$patchIfNeeded$5$7, init$, void, $Path*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModulePatcher$$Lambda$lambda$patchIfNeeded$5$7, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ModulePatcher$$Lambda$lambda$patchIfNeeded$5$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePatcher$$Lambda$lambda$patchIfNeeded$5$7",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* ModulePatcher$$Lambda$lambda$patchIfNeeded$5$7::load$($String* name, bool initialize) {
	$loadClass(ModulePatcher$$Lambda$lambda$patchIfNeeded$5$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePatcher$$Lambda$lambda$patchIfNeeded$5$7::class$ = nullptr;

class ModulePatcher$$Lambda$requires$8 : public $Consumer {
	$class(ModulePatcher$$Lambda$requires$8, $NO_CLASS_INIT, $Consumer)
public:
	void init$($ModuleDescriptor$Builder* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* req) override {
		$nc(inst$)->requires($cast($ModuleDescriptor$Requires, req));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePatcher$$Lambda$requires$8>());
	}
	$ModuleDescriptor$Builder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModulePatcher$$Lambda$requires$8::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ModulePatcher$$Lambda$requires$8, inst$)},
	{}
};
$MethodInfo ModulePatcher$$Lambda$requires$8::methodInfos[3] = {
	{"<init>", "(Ljava/lang/module/ModuleDescriptor$Builder;)V", nullptr, $PUBLIC, $method(ModulePatcher$$Lambda$requires$8, init$, void, $ModuleDescriptor$Builder*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ModulePatcher$$Lambda$requires$8, accept, void, Object$*)},
	{}
};
$ClassInfo ModulePatcher$$Lambda$requires$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePatcher$$Lambda$requires$8",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ModulePatcher$$Lambda$requires$8::load$($String* name, bool initialize) {
	$loadClass(ModulePatcher$$Lambda$requires$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePatcher$$Lambda$requires$8::class$ = nullptr;

class ModulePatcher$$Lambda$exports$9 : public $Consumer {
	$class(ModulePatcher$$Lambda$exports$9, $NO_CLASS_INIT, $Consumer)
public:
	void init$($ModuleDescriptor$Builder* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* e) override {
		$nc(inst$)->exports($cast($ModuleDescriptor$Exports, e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePatcher$$Lambda$exports$9>());
	}
	$ModuleDescriptor$Builder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModulePatcher$$Lambda$exports$9::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ModulePatcher$$Lambda$exports$9, inst$)},
	{}
};
$MethodInfo ModulePatcher$$Lambda$exports$9::methodInfos[3] = {
	{"<init>", "(Ljava/lang/module/ModuleDescriptor$Builder;)V", nullptr, $PUBLIC, $method(ModulePatcher$$Lambda$exports$9, init$, void, $ModuleDescriptor$Builder*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ModulePatcher$$Lambda$exports$9, accept, void, Object$*)},
	{}
};
$ClassInfo ModulePatcher$$Lambda$exports$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePatcher$$Lambda$exports$9",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ModulePatcher$$Lambda$exports$9::load$($String* name, bool initialize) {
	$loadClass(ModulePatcher$$Lambda$exports$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePatcher$$Lambda$exports$9::class$ = nullptr;

class ModulePatcher$$Lambda$opens$10 : public $Consumer {
	$class(ModulePatcher$$Lambda$opens$10, $NO_CLASS_INIT, $Consumer)
public:
	void init$($ModuleDescriptor$Builder* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* obj) override {
		$nc(inst$)->opens($cast($ModuleDescriptor$Opens, obj));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePatcher$$Lambda$opens$10>());
	}
	$ModuleDescriptor$Builder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModulePatcher$$Lambda$opens$10::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ModulePatcher$$Lambda$opens$10, inst$)},
	{}
};
$MethodInfo ModulePatcher$$Lambda$opens$10::methodInfos[3] = {
	{"<init>", "(Ljava/lang/module/ModuleDescriptor$Builder;)V", nullptr, $PUBLIC, $method(ModulePatcher$$Lambda$opens$10, init$, void, $ModuleDescriptor$Builder*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ModulePatcher$$Lambda$opens$10, accept, void, Object$*)},
	{}
};
$ClassInfo ModulePatcher$$Lambda$opens$10::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePatcher$$Lambda$opens$10",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ModulePatcher$$Lambda$opens$10::load$($String* name, bool initialize) {
	$loadClass(ModulePatcher$$Lambda$opens$10, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePatcher$$Lambda$opens$10::class$ = nullptr;

class ModulePatcher$$Lambda$uses$11 : public $Consumer {
	$class(ModulePatcher$$Lambda$uses$11, $NO_CLASS_INIT, $Consumer)
public:
	void init$($ModuleDescriptor$Builder* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* service) override {
		$nc(inst$)->uses($cast($String, service));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePatcher$$Lambda$uses$11>());
	}
	$ModuleDescriptor$Builder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModulePatcher$$Lambda$uses$11::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ModulePatcher$$Lambda$uses$11, inst$)},
	{}
};
$MethodInfo ModulePatcher$$Lambda$uses$11::methodInfos[3] = {
	{"<init>", "(Ljava/lang/module/ModuleDescriptor$Builder;)V", nullptr, $PUBLIC, $method(ModulePatcher$$Lambda$uses$11, init$, void, $ModuleDescriptor$Builder*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ModulePatcher$$Lambda$uses$11, accept, void, Object$*)},
	{}
};
$ClassInfo ModulePatcher$$Lambda$uses$11::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePatcher$$Lambda$uses$11",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ModulePatcher$$Lambda$uses$11::load$($String* name, bool initialize) {
	$loadClass(ModulePatcher$$Lambda$uses$11, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePatcher$$Lambda$uses$11::class$ = nullptr;

class ModulePatcher$$Lambda$provides$12 : public $Consumer {
	$class(ModulePatcher$$Lambda$provides$12, $NO_CLASS_INIT, $Consumer)
public:
	void init$($ModuleDescriptor$Builder* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* p) override {
		$nc(inst$)->provides($cast($ModuleDescriptor$Provides, p));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePatcher$$Lambda$provides$12>());
	}
	$ModuleDescriptor$Builder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModulePatcher$$Lambda$provides$12::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ModulePatcher$$Lambda$provides$12, inst$)},
	{}
};
$MethodInfo ModulePatcher$$Lambda$provides$12::methodInfos[3] = {
	{"<init>", "(Ljava/lang/module/ModuleDescriptor$Builder;)V", nullptr, $PUBLIC, $method(ModulePatcher$$Lambda$provides$12, init$, void, $ModuleDescriptor$Builder*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ModulePatcher$$Lambda$provides$12, accept, void, Object$*)},
	{}
};
$ClassInfo ModulePatcher$$Lambda$provides$12::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePatcher$$Lambda$provides$12",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ModulePatcher$$Lambda$provides$12::load$($String* name, bool initialize) {
	$loadClass(ModulePatcher$$Lambda$provides$12, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePatcher$$Lambda$provides$12::class$ = nullptr;

class ModulePatcher$$Lambda$version$13 : public $Consumer {
	$class(ModulePatcher$$Lambda$version$13, $NO_CLASS_INIT, $Consumer)
public:
	void init$($ModuleDescriptor$Builder* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* v) override {
		$nc(inst$)->version($cast($ModuleDescriptor$Version, v));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePatcher$$Lambda$version$13>());
	}
	$ModuleDescriptor$Builder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModulePatcher$$Lambda$version$13::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ModulePatcher$$Lambda$version$13, inst$)},
	{}
};
$MethodInfo ModulePatcher$$Lambda$version$13::methodInfos[3] = {
	{"<init>", "(Ljava/lang/module/ModuleDescriptor$Builder;)V", nullptr, $PUBLIC, $method(ModulePatcher$$Lambda$version$13, init$, void, $ModuleDescriptor$Builder*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ModulePatcher$$Lambda$version$13, accept, void, Object$*)},
	{}
};
$ClassInfo ModulePatcher$$Lambda$version$13::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePatcher$$Lambda$version$13",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ModulePatcher$$Lambda$version$13::load$($String* name, bool initialize) {
	$loadClass(ModulePatcher$$Lambda$version$13, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePatcher$$Lambda$version$13::class$ = nullptr;

class ModulePatcher$$Lambda$mainClass$14 : public $Consumer {
	$class(ModulePatcher$$Lambda$mainClass$14, $NO_CLASS_INIT, $Consumer)
public:
	void init$($ModuleDescriptor$Builder* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* mc) override {
		$nc(inst$)->mainClass($cast($String, mc));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePatcher$$Lambda$mainClass$14>());
	}
	$ModuleDescriptor$Builder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModulePatcher$$Lambda$mainClass$14::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ModulePatcher$$Lambda$mainClass$14, inst$)},
	{}
};
$MethodInfo ModulePatcher$$Lambda$mainClass$14::methodInfos[3] = {
	{"<init>", "(Ljava/lang/module/ModuleDescriptor$Builder;)V", nullptr, $PUBLIC, $method(ModulePatcher$$Lambda$mainClass$14, init$, void, $ModuleDescriptor$Builder*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ModulePatcher$$Lambda$mainClass$14, accept, void, Object$*)},
	{}
};
$ClassInfo ModulePatcher$$Lambda$mainClass$14::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePatcher$$Lambda$mainClass$14",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ModulePatcher$$Lambda$mainClass$14::load$($String* name, bool initialize) {
	$loadClass(ModulePatcher$$Lambda$mainClass$14, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePatcher$$Lambda$mainClass$14::class$ = nullptr;

class ModulePatcher$$Lambda$lambda$patchIfNeeded$6$15 : public $Supplier {
	$class(ModulePatcher$$Lambda$lambda$patchIfNeeded$6$15, $NO_CLASS_INIT, $Supplier)
public:
	void init$($List* paths, $ModuleReference* mref) {
		$set(this, paths, paths);
		$set(this, mref, mref);
	}
	virtual $Object* get() override {
		 return $of(ModulePatcher::lambda$patchIfNeeded$6(paths, mref));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePatcher$$Lambda$lambda$patchIfNeeded$6$15>());
	}
	$List* paths = nullptr;
	$ModuleReference* mref = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModulePatcher$$Lambda$lambda$patchIfNeeded$6$15::fieldInfos[3] = {
	{"paths", "Ljava/util/List;", nullptr, $PUBLIC, $field(ModulePatcher$$Lambda$lambda$patchIfNeeded$6$15, paths)},
	{"mref", "Ljava/lang/module/ModuleReference;", nullptr, $PUBLIC, $field(ModulePatcher$$Lambda$lambda$patchIfNeeded$6$15, mref)},
	{}
};
$MethodInfo ModulePatcher$$Lambda$lambda$patchIfNeeded$6$15::methodInfos[3] = {
	{"<init>", "(Ljava/util/List;Ljava/lang/module/ModuleReference;)V", nullptr, $PUBLIC, $method(ModulePatcher$$Lambda$lambda$patchIfNeeded$6$15, init$, void, $List*, $ModuleReference*)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModulePatcher$$Lambda$lambda$patchIfNeeded$6$15, get, $Object*)},
	{}
};
$ClassInfo ModulePatcher$$Lambda$lambda$patchIfNeeded$6$15::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePatcher$$Lambda$lambda$patchIfNeeded$6$15",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* ModulePatcher$$Lambda$lambda$patchIfNeeded$6$15::load$($String* name, bool initialize) {
	$loadClass(ModulePatcher$$Lambda$lambda$patchIfNeeded$6$15, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePatcher$$Lambda$lambda$patchIfNeeded$6$15::class$ = nullptr;

$FieldInfo _ModulePatcher_FieldInfo_[] = {
	{"JLMA", "Ljdk/internal/access/JavaLangModuleAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ModulePatcher, JLMA)},
	{"map", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/nio/file/Path;>;>;", $PRIVATE | $FINAL, $field(ModulePatcher, map)},
	{}
};

$MethodInfo _ModulePatcher_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Map;)V", "(Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;)V", $PUBLIC, $method(ModulePatcher, init$, void, $Map*)},
	{"hasPatches", "()Z", nullptr, $PUBLIC, $method(ModulePatcher, hasPatches, bool)},
	{"isHidden", "(Ljava/nio/file/Path;)Z", nullptr, $PRIVATE, $method(ModulePatcher, isHidden, bool, $Path*)},
	{"lambda$new$0", "(Ljava/lang/String;)Ljava/nio/file/Path;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModulePatcher, lambda$new$0, $Path*, $String*)},
	{"lambda$patchIfNeeded$1", "(ZLjava/util/jar/JarEntry;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModulePatcher, lambda$patchIfNeeded$1, bool, bool, $JarEntry*)},
	{"lambda$patchIfNeeded$2", "(Ljava/nio/file/Path;Ljava/util/jar/JarEntry;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModulePatcher, lambda$patchIfNeeded$2, $String*, $Path*, $JarEntry*)},
	{"lambda$patchIfNeeded$3", "(Ljava/nio/file/Path;Ljava/nio/file/attribute/BasicFileAttributes;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModulePatcher, lambda$patchIfNeeded$3, bool, $Path*, $BasicFileAttributes*)},
	{"lambda$patchIfNeeded$4", "(ZLjava/nio/file/Path;)Z", nullptr, $PRIVATE | $SYNTHETIC, $method(ModulePatcher, lambda$patchIfNeeded$4, bool, bool, $Path*)},
	{"lambda$patchIfNeeded$5", "(Ljava/nio/file/Path;Ljava/nio/file/Path;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModulePatcher, lambda$patchIfNeeded$5, $String*, $Path*, $Path*)},
	{"lambda$patchIfNeeded$6", "(Ljava/util/List;Ljava/lang/module/ModuleReference;)Ljava/lang/module/ModuleReader;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModulePatcher, lambda$patchIfNeeded$6, $ModuleReader*, $List*, $ModuleReference*)},
	{"patchIfNeeded", "(Ljava/lang/module/ModuleReference;)Ljava/lang/module/ModuleReference;", nullptr, $PUBLIC, $method(ModulePatcher, patchIfNeeded, $ModuleReference*, $ModuleReference*)},
	{"patchedModules", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", 0, $method(ModulePatcher, patchedModules, $Set*)},
	{"toPackageName", "(Ljava/nio/file/Path;Ljava/nio/file/Path;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ModulePatcher, toPackageName, $String*, $Path*, $Path*)},
	{"toPackageName", "(Ljava/nio/file/Path;Ljava/util/jar/JarEntry;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ModulePatcher, toPackageName, $String*, $Path*, $JarEntry*)},
	{"warnIfModuleInfo", "(Ljava/nio/file/Path;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ModulePatcher, warnIfModuleInfo, $String*, $Path*, $String*)},
	{}
};

$InnerClassInfo _ModulePatcher_InnerClassesInfo_[] = {
	{"jdk.internal.module.ModulePatcher$ExplodedResourceFinder", "jdk.internal.module.ModulePatcher", "ExplodedResourceFinder", $PRIVATE | $STATIC},
	{"jdk.internal.module.ModulePatcher$JarResourceFinder", "jdk.internal.module.ModulePatcher", "JarResourceFinder", $PRIVATE | $STATIC},
	{"jdk.internal.module.ModulePatcher$ResourceFinder", "jdk.internal.module.ModulePatcher", "ResourceFinder", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.module.ModulePatcher$PatchedModuleReader", "jdk.internal.module.ModulePatcher", "PatchedModuleReader", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _ModulePatcher_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.module.ModulePatcher",
	"java.lang.Object",
	nullptr,
	_ModulePatcher_FieldInfo_,
	_ModulePatcher_MethodInfo_,
	nullptr,
	nullptr,
	_ModulePatcher_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.module.ModulePatcher$ExplodedResourceFinder,jdk.internal.module.ModulePatcher$ExplodedResourceFinder$1,jdk.internal.module.ModulePatcher$JarResourceFinder,jdk.internal.module.ModulePatcher$JarResourceFinder$1,jdk.internal.module.ModulePatcher$ResourceFinder,jdk.internal.module.ModulePatcher$PatchedModuleReader,jdk.internal.module.ModulePatcher$PatchedModuleReader$1"
};

$Object* allocate$ModulePatcher($Class* clazz) {
	return $of($alloc(ModulePatcher));
}

$JavaLangModuleAccess* ModulePatcher::JLMA = nullptr;

void ModulePatcher::init$($Map* input) {
	$useLocalCurrentObjectStackCache();
	if ($nc(input)->isEmpty()) {
		$set(this, map, $Map::of());
	} else {
		$var($Map, map, $new($HashMap));
		{
			$var($Iterator, i$, $nc($(input->entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
				{
					$var($String, mn, $cast($String, $nc(e)->getKey()));
					$var($List, paths, $nc($($nc($($nc(($cast($List, $(e->getValue()))))->stream()))->map(static_cast<$Function*>($$new(ModulePatcher$$Lambda$lambda$new$0)))))->toList());
					map->put(mn, paths);
				}
			}
		}
		$set(this, map, map);
	}
}

$ModuleReference* ModulePatcher::patchIfNeeded($ModuleReference* mref) {
	$useLocalCurrentObjectStackCache();
	$var($ModuleDescriptor, descriptor, $nc(mref)->descriptor());
	$var($String, mn, $nc(descriptor)->name());
	$var($List, paths, $cast($List, $nc(this->map)->get(mn)));
	if (paths == nullptr) {
		return mref;
	}
	$var($Set, packages, $new($HashSet));
	bool isAutomatic = descriptor->isAutomatic();
	try {
		{
			$var($Iterator, i$, $nc(paths)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Path, file, $cast($Path, i$->next()));
				{
					if ($Files::isRegularFile(file, $$new($LinkOptionArray, 0))) {
						{
							$var($JarFile, jf, $new($JarFile, $($nc(file)->toString())));
							{
								$var($Throwable, var$0, nullptr);
								try {
									try {
										$nc($($nc($($nc($($nc($(jf->stream()))->filter(static_cast<$Predicate*>($$new(ModulePatcher$$Lambda$lambda$patchIfNeeded$1$1, isAutomatic)))))->map(static_cast<$Function*>($$new(ModulePatcher$$Lambda$lambda$patchIfNeeded$2$2, file)))))->filter(static_cast<$Predicate*>($$new(ModulePatcher$$Lambda$isPackageName$3)))))->forEach(static_cast<$Consumer*>($$new(ModulePatcher$$Lambda$add$4, static_cast<$Set*>(packages))));
									} catch ($Throwable& t$) {
										try {
											jf->close();
										} catch ($Throwable& x2) {
											t$->addSuppressed(x2);
										}
										$throw(t$);
									}
								} catch ($Throwable& var$1) {
									$assign(var$0, var$1);
								} /*finally*/ {
									jf->close();
								}
								if (var$0 != nullptr) {
									$throw(var$0);
								}
							}
						}
					} else if ($Files::isDirectory(file, $$new($LinkOptionArray, 0))) {
						$var($Path, top, file);
						$nc($($nc($($nc($($nc($($Files::find(top, $Integer::MAX_VALUE, (static_cast<$BiPredicate*>($$new(ModulePatcher$$Lambda$lambda$patchIfNeeded$3$5))), $$new($FileVisitOptionArray, 0))))->filter(static_cast<$Predicate*>($$new(ModulePatcher$$Lambda$lambda$patchIfNeeded$4$6, this, isAutomatic)))))->map(static_cast<$Function*>($$new(ModulePatcher$$Lambda$lambda$patchIfNeeded$5$7, top)))))->filter(static_cast<$Predicate*>($$new(ModulePatcher$$Lambda$isPackageName$3)))))->forEach(static_cast<$Consumer*>($$new(ModulePatcher$$Lambda$add$4, static_cast<$Set*>(packages))));
					}
				}
			}
		}
	} catch ($IOException& ioe) {
		$throwNew($UncheckedIOException, ioe);
	}
	packages->removeAll($(descriptor->packages()));
	if (!packages->isEmpty()) {
		$var($String, var$2, descriptor->name());
		bool var$3 = descriptor->isAutomatic();
		$var($ModuleDescriptor$Builder, builder, $nc(ModulePatcher::JLMA)->newModuleBuilder(var$2, var$3, $(descriptor->modifiers())));
		if (!descriptor->isAutomatic()) {
			$nc($(descriptor->requires()))->forEach(static_cast<$Consumer*>($$new(ModulePatcher$$Lambda$requires$8, static_cast<$ModuleDescriptor$Builder*>($nc(builder)))));
			$nc($(descriptor->exports()))->forEach(static_cast<$Consumer*>($$new(ModulePatcher$$Lambda$exports$9, static_cast<$ModuleDescriptor$Builder*>($nc(builder)))));
			$nc($(descriptor->opens()))->forEach(static_cast<$Consumer*>($$new(ModulePatcher$$Lambda$opens$10, static_cast<$ModuleDescriptor$Builder*>($nc(builder)))));
			$nc($(descriptor->uses()))->forEach(static_cast<$Consumer*>($$new(ModulePatcher$$Lambda$uses$11, static_cast<$ModuleDescriptor$Builder*>($nc(builder)))));
		}
		$nc($(descriptor->provides()))->forEach(static_cast<$Consumer*>($$new(ModulePatcher$$Lambda$provides$12, static_cast<$ModuleDescriptor$Builder*>($nc(builder)))));
		$nc($(descriptor->version()))->ifPresent(static_cast<$Consumer*>($$new(ModulePatcher$$Lambda$version$13, static_cast<$ModuleDescriptor$Builder*>($nc(builder)))));
		$nc($(descriptor->mainClass()))->ifPresent(static_cast<$Consumer*>($$new(ModulePatcher$$Lambda$mainClass$14, static_cast<$ModuleDescriptor$Builder*>($nc(builder)))));
		$nc(builder)->packages($(descriptor->packages()));
		builder->packages(packages);
		$assign(descriptor, builder->build());
	}
	$var($URI, location, $cast($URI, $nc($(mref->location()))->orElse(nullptr)));
	$var($ModuleTarget, target, nullptr);
	$var($ModuleHashes, recordedHashes, nullptr);
	$var($ModuleHashes$HashSupplier, hasher, nullptr);
	$var($ModuleResolution, mres, nullptr);
	if ($instanceOf($ModuleReferenceImpl, mref)) {
		$var($ModuleReferenceImpl, impl, $cast($ModuleReferenceImpl, mref));
		$assign(target, impl->moduleTarget());
		$assign(recordedHashes, impl->recordedHashes());
		$assign(hasher, impl->hasher());
		$assign(mres, impl->moduleResolution());
	}
	return $new($ModuleReferenceImpl, descriptor, location, static_cast<$Supplier*>($$new(ModulePatcher$$Lambda$lambda$patchIfNeeded$6$15, paths, mref)), this, target, recordedHashes, hasher, mres);
}

bool ModulePatcher::hasPatches() {
	return !$nc(this->map)->isEmpty();
}

$Set* ModulePatcher::patchedModules() {
	return $nc(this->map)->keySet();
}

$String* ModulePatcher::toPackageName($Path* top, $Path* file) {
	$init(ModulePatcher);
	$useLocalCurrentObjectStackCache();
	$var($Path, entry, $nc(top)->relativize(file));
	$var($Path, parent, $nc(entry)->getParent());
	if (parent == nullptr) {
		return warnIfModuleInfo(top, $(entry->toString()));
	} else {
		$init($File);
		return $nc($($nc(parent)->toString()))->replace($File::separatorChar, u'.');
	}
}

bool ModulePatcher::isHidden($Path* file) {
	try {
		return $Files::isHidden(file);
	} catch ($IOException& ioe) {
		return false;
	}
	$shouldNotReachHere();
}

$String* ModulePatcher::toPackageName($Path* file, $JarEntry* entry) {
	$init(ModulePatcher);
	$useLocalCurrentObjectStackCache();
	$var($String, name, $nc(entry)->getName());
	int32_t index = $nc(name)->lastIndexOf("/"_s);
	if (index == -1) {
		return warnIfModuleInfo(file, name);
	} else {
		return $(name->substring(0, index))->replace(u'/', u'.');
	}
}

$String* ModulePatcher::warnIfModuleInfo($Path* file, $String* e) {
	$init(ModulePatcher);
	if ($nc(e)->equals("module-info.class"_s)) {
		$nc($System::err)->println($$str({"WARNING: "_s, e, " ignored in patch: "_s, file}));
	}
	return ""_s;
}

$ModuleReader* ModulePatcher::lambda$patchIfNeeded$6($List* paths, $ModuleReference* mref) {
	$init(ModulePatcher);
	return $new($ModulePatcher$PatchedModuleReader, paths, mref);
}

$String* ModulePatcher::lambda$patchIfNeeded$5($Path* top, $Path* path) {
	$init(ModulePatcher);
	return toPackageName(top, path);
}

bool ModulePatcher::lambda$patchIfNeeded$4(bool isAutomatic, $Path* path) {
	bool var$0 = (!isAutomatic || $nc($($nc(path)->toString()))->endsWith(".class"_s));
	return var$0 && !isHidden(path);
}

bool ModulePatcher::lambda$patchIfNeeded$3($Path* path, $BasicFileAttributes* attrs) {
	$init(ModulePatcher);
	return $nc(attrs)->isRegularFile();
}

$String* ModulePatcher::lambda$patchIfNeeded$2($Path* file, $JarEntry* e) {
	$init(ModulePatcher);
	return toPackageName(file, e);
}

bool ModulePatcher::lambda$patchIfNeeded$1(bool isAutomatic, $JarEntry* e) {
	$init(ModulePatcher);
	bool var$0 = !$nc(e)->isDirectory();
	return var$0 && (!isAutomatic || $nc($($nc(e)->getName()))->endsWith(".class"_s));
}

$Path* ModulePatcher::lambda$new$0($String* x$0) {
	$init(ModulePatcher);
	return $Paths::get(x$0, $$new($StringArray, 0));
}

void clinit$ModulePatcher($Class* class$) {
	$assignStatic(ModulePatcher::JLMA, $SharedSecrets::getJavaLangModuleAccess());
}

ModulePatcher::ModulePatcher() {
}

$Class* ModulePatcher::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ModulePatcher$$Lambda$lambda$new$0::classInfo$.name)) {
			return ModulePatcher$$Lambda$lambda$new$0::load$(name, initialize);
		}
		if (name->equals(ModulePatcher$$Lambda$lambda$patchIfNeeded$1$1::classInfo$.name)) {
			return ModulePatcher$$Lambda$lambda$patchIfNeeded$1$1::load$(name, initialize);
		}
		if (name->equals(ModulePatcher$$Lambda$lambda$patchIfNeeded$2$2::classInfo$.name)) {
			return ModulePatcher$$Lambda$lambda$patchIfNeeded$2$2::load$(name, initialize);
		}
		if (name->equals(ModulePatcher$$Lambda$isPackageName$3::classInfo$.name)) {
			return ModulePatcher$$Lambda$isPackageName$3::load$(name, initialize);
		}
		if (name->equals(ModulePatcher$$Lambda$add$4::classInfo$.name)) {
			return ModulePatcher$$Lambda$add$4::load$(name, initialize);
		}
		if (name->equals(ModulePatcher$$Lambda$lambda$patchIfNeeded$3$5::classInfo$.name)) {
			return ModulePatcher$$Lambda$lambda$patchIfNeeded$3$5::load$(name, initialize);
		}
		if (name->equals(ModulePatcher$$Lambda$lambda$patchIfNeeded$4$6::classInfo$.name)) {
			return ModulePatcher$$Lambda$lambda$patchIfNeeded$4$6::load$(name, initialize);
		}
		if (name->equals(ModulePatcher$$Lambda$lambda$patchIfNeeded$5$7::classInfo$.name)) {
			return ModulePatcher$$Lambda$lambda$patchIfNeeded$5$7::load$(name, initialize);
		}
		if (name->equals(ModulePatcher$$Lambda$requires$8::classInfo$.name)) {
			return ModulePatcher$$Lambda$requires$8::load$(name, initialize);
		}
		if (name->equals(ModulePatcher$$Lambda$exports$9::classInfo$.name)) {
			return ModulePatcher$$Lambda$exports$9::load$(name, initialize);
		}
		if (name->equals(ModulePatcher$$Lambda$opens$10::classInfo$.name)) {
			return ModulePatcher$$Lambda$opens$10::load$(name, initialize);
		}
		if (name->equals(ModulePatcher$$Lambda$uses$11::classInfo$.name)) {
			return ModulePatcher$$Lambda$uses$11::load$(name, initialize);
		}
		if (name->equals(ModulePatcher$$Lambda$provides$12::classInfo$.name)) {
			return ModulePatcher$$Lambda$provides$12::load$(name, initialize);
		}
		if (name->equals(ModulePatcher$$Lambda$version$13::classInfo$.name)) {
			return ModulePatcher$$Lambda$version$13::load$(name, initialize);
		}
		if (name->equals(ModulePatcher$$Lambda$mainClass$14::classInfo$.name)) {
			return ModulePatcher$$Lambda$mainClass$14::load$(name, initialize);
		}
		if (name->equals(ModulePatcher$$Lambda$lambda$patchIfNeeded$6$15::classInfo$.name)) {
			return ModulePatcher$$Lambda$lambda$patchIfNeeded$6$15::load$(name, initialize);
		}
	}
	$loadClass(ModulePatcher, name, initialize, &_ModulePatcher_ClassInfo_, clinit$ModulePatcher, allocate$ModulePatcher);
	return class$;
}

$Class* ModulePatcher::class$ = nullptr;

		} // module
	} // internal
} // jdk