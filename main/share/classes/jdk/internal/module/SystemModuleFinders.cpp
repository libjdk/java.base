#include <jdk/internal/module/SystemModuleFinders.h>

#include <java/io/Serializable.h>
#include <java/lang/InternalError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/ModuleDescriptor.h>
#include <java/lang/module/ModuleFinder.h>
#include <java/lang/module/ModuleReference.h>
#include <java/lang/reflect/Constructor.h>
#include <java/net/URI.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/Path.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/function/Function.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/access/JavaNetUriAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/jimage/ImageLocation.h>
#include <jdk/internal/jimage/ImageReader.h>
#include <jdk/internal/module/ModuleBootstrap.h>
#include <jdk/internal/module/ModuleHashes$HashSupplier.h>
#include <jdk/internal/module/ModuleHashes.h>
#include <jdk/internal/module/ModuleInfo$Attributes.h>
#include <jdk/internal/module/ModuleInfo.h>
#include <jdk/internal/module/ModulePatcher.h>
#include <jdk/internal/module/ModulePath.h>
#include <jdk/internal/module/ModuleReferenceImpl.h>
#include <jdk/internal/module/ModuleResolution.h>
#include <jdk/internal/module/ModuleTarget.h>
#include <jdk/internal/module/SystemModuleFinders$1.h>
#include <jdk/internal/module/SystemModuleFinders$2.h>
#include <jdk/internal/module/SystemModuleFinders$3.h>
#include <jdk/internal/module/SystemModuleFinders$SystemImage.h>
#include <jdk/internal/module/SystemModuleFinders$SystemModuleFinder.h>
#include <jdk/internal/module/SystemModules.h>
#include <jdk/internal/module/SystemModulesMap.h>
#include <jdk/internal/util/StaticProperty.h>
#include <jcpp.h>

#include <java/lang/Machine.h>

#undef JNUA
#undef USE_FAST_PATH

using $ModuleDescriptorArray = $Array<::java::lang::module::ModuleDescriptor>;
using $ModuleReferenceArray = $Array<::java::lang::module::ModuleReference>;
using $Map$EntryArray = $Array<::java::util::Map$Entry>;
using $ModuleHashesArray = $Array<::jdk::internal::module::ModuleHashes>;
using $ModuleResolutionArray = $Array<::jdk::internal::module::ModuleResolution>;
using $ModuleTargetArray = $Array<::jdk::internal::module::ModuleTarget>;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ModuleDescriptor = ::java::lang::module::ModuleDescriptor;
using $ModuleFinder = ::java::lang::module::ModuleFinder;
using $ModuleReference = ::java::lang::module::ModuleReference;
using $Constructor = ::java::lang::reflect::Constructor;
using $URI = ::java::net::URI;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $Function = ::java::util::function::Function;
using $Supplier = ::java::util::function::Supplier;
using $JavaNetUriAccess = ::jdk::internal::access::JavaNetUriAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $ImageLocation = ::jdk::internal::jimage::ImageLocation;
using $ImageReader = ::jdk::internal::jimage::ImageReader;
using $ModuleBootstrap = ::jdk::internal::module::ModuleBootstrap;
using $ModuleHashes = ::jdk::internal::module::ModuleHashes;
using $ModuleHashes$HashSupplier = ::jdk::internal::module::ModuleHashes$HashSupplier;
using $ModuleInfo = ::jdk::internal::module::ModuleInfo;
using $ModuleInfo$Attributes = ::jdk::internal::module::ModuleInfo$Attributes;
using $ModulePatcher = ::jdk::internal::module::ModulePatcher;
using $ModuleReferenceImpl = ::jdk::internal::module::ModuleReferenceImpl;
using $ModuleResolution = ::jdk::internal::module::ModuleResolution;
using $ModuleTarget = ::jdk::internal::module::ModuleTarget;
using $SystemModuleFinders$2 = ::jdk::internal::module::SystemModuleFinders$2;
using $SystemModuleFinders$3 = ::jdk::internal::module::SystemModuleFinders$3;
using $SystemModuleFinders$SystemImage = ::jdk::internal::module::SystemModuleFinders$SystemImage;
using $SystemModuleFinders$SystemModuleFinder = ::jdk::internal::module::SystemModuleFinders$SystemModuleFinder;
using $SystemModules = ::jdk::internal::module::SystemModules;
using $SystemModulesMap = ::jdk::internal::module::SystemModulesMap;

namespace jdk {
	namespace internal {
		namespace module {

class SystemModuleFinders$$Lambda$lambda$ofModuleInfos$0 : public $Function {
	$class(SystemModuleFinders$$Lambda$lambda$ofModuleInfos$0, $NO_CLASS_INIT, $Function)
public:
	void init$($ModuleHashes* hashes, $String* name) {
		$set(this, hashes, hashes);
		$set(this, name, name);
	}
	virtual $Object* apply(Object$* k) override {
		 return $of(SystemModuleFinders::lambda$ofModuleInfos$0(hashes, name, $cast($String, k)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SystemModuleFinders$$Lambda$lambda$ofModuleInfos$0>());
	}
	$ModuleHashes* hashes = nullptr;
	$String* name = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SystemModuleFinders$$Lambda$lambda$ofModuleInfos$0::fieldInfos[3] = {
	{"hashes", "Ljdk/internal/module/ModuleHashes;", nullptr, $PUBLIC, $field(SystemModuleFinders$$Lambda$lambda$ofModuleInfos$0, hashes)},
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(SystemModuleFinders$$Lambda$lambda$ofModuleInfos$0, name)},
	{}
};
$MethodInfo SystemModuleFinders$$Lambda$lambda$ofModuleInfos$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/module/ModuleHashes;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(SystemModuleFinders$$Lambda$lambda$ofModuleInfos$0, init$, void, $ModuleHashes*, $String*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(SystemModuleFinders$$Lambda$lambda$ofModuleInfos$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo SystemModuleFinders$$Lambda$lambda$ofModuleInfos$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.SystemModuleFinders$$Lambda$lambda$ofModuleInfos$0",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* SystemModuleFinders$$Lambda$lambda$ofModuleInfos$0::load$($String* name, bool initialize) {
	$loadClass(SystemModuleFinders$$Lambda$lambda$ofModuleInfos$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SystemModuleFinders$$Lambda$lambda$ofModuleInfos$0::class$ = nullptr;

$FieldInfo _SystemModuleFinders_FieldInfo_[] = {
	{"JNUA", "Ljdk/internal/access/JavaNetUriAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SystemModuleFinders, JNUA)},
	{"USE_FAST_PATH", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SystemModuleFinders, USE_FAST_PATH)},
	{"cachedSystemModuleFinder", "Ljava/lang/module/ModuleFinder;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(SystemModuleFinders, cachedSystemModuleFinder)},
	{}
};

$MethodInfo _SystemModuleFinders_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(SystemModuleFinders, init$, void)},
	{"allSystemModules", "()Ljdk/internal/module/SystemModules;", nullptr, $STATIC, $staticMethod(SystemModuleFinders, allSystemModules, $SystemModules*)},
	{"generateNameToHash", "([Ljdk/internal/module/ModuleHashes;)Ljava/util/Map;", "([Ljdk/internal/module/ModuleHashes;)Ljava/util/Map<Ljava/lang/String;[B>;", $STATIC, $staticMethod(SystemModuleFinders, generateNameToHash, $Map*, $ModuleHashesArray*)},
	{"hashSupplier", "(Ljava/util/Map;Ljava/lang/String;)Ljdk/internal/module/ModuleHashes$HashSupplier;", "(Ljava/util/Map<Ljava/lang/String;[B>;Ljava/lang/String;)Ljdk/internal/module/ModuleHashes$HashSupplier;", $STATIC, $staticMethod(SystemModuleFinders, hashSupplier, $ModuleHashes$HashSupplier*, $Map*, $String*)},
	{"lambda$ofModuleInfos$0", "(Ljdk/internal/module/ModuleHashes;Ljava/lang/String;Ljava/lang/String;)[B", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(SystemModuleFinders, lambda$ofModuleInfos$0, $bytes*, $ModuleHashes*, $String*, $String*)},
	{"of", "(Ljdk/internal/module/SystemModules;)Ljava/lang/module/ModuleFinder;", nullptr, $STATIC, $staticMethod(SystemModuleFinders, of, $ModuleFinder*, $SystemModules*)},
	{"ofModuleInfos", "()Ljava/lang/module/ModuleFinder;", nullptr, $PRIVATE | $STATIC, $staticMethod(SystemModuleFinders, ofModuleInfos, $ModuleFinder*)},
	{"ofSystem", "()Ljava/lang/module/ModuleFinder;", nullptr, $PUBLIC | $STATIC, $staticMethod(SystemModuleFinders, ofSystem, $ModuleFinder*)},
	{"systemModules", "(Ljava/lang/String;)Ljdk/internal/module/SystemModules;", nullptr, $STATIC, $staticMethod(SystemModuleFinders, systemModules, $SystemModules*, $String*)},
	{"toModuleReference", "(Ljava/lang/module/ModuleDescriptor;Ljdk/internal/module/ModuleTarget;Ljdk/internal/module/ModuleHashes;Ljdk/internal/module/ModuleHashes$HashSupplier;Ljdk/internal/module/ModuleResolution;)Ljava/lang/module/ModuleReference;", nullptr, $STATIC, $staticMethod(SystemModuleFinders, toModuleReference, $ModuleReference*, $ModuleDescriptor*, $ModuleTarget*, $ModuleHashes*, $ModuleHashes$HashSupplier*, $ModuleResolution*)},
	{}
};

$InnerClassInfo _SystemModuleFinders_InnerClassesInfo_[] = {
	{"jdk.internal.module.SystemModuleFinders$ModuleContentSpliterator", "jdk.internal.module.SystemModuleFinders", "ModuleContentSpliterator", $PRIVATE | $STATIC},
	{"jdk.internal.module.SystemModuleFinders$SystemModuleReader", "jdk.internal.module.SystemModuleFinders", "SystemModuleReader", $PRIVATE | $STATIC},
	{"jdk.internal.module.SystemModuleFinders$SystemImage", "jdk.internal.module.SystemModuleFinders", "SystemImage", $PRIVATE | $STATIC},
	{"jdk.internal.module.SystemModuleFinders$SystemModuleFinder", "jdk.internal.module.SystemModuleFinders", "SystemModuleFinder", $PRIVATE | $STATIC},
	{"jdk.internal.module.SystemModuleFinders$3", nullptr, nullptr, 0},
	{"jdk.internal.module.SystemModuleFinders$2", nullptr, nullptr, 0},
	{"jdk.internal.module.SystemModuleFinders$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SystemModuleFinders_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.module.SystemModuleFinders",
	"java.lang.Object",
	nullptr,
	_SystemModuleFinders_FieldInfo_,
	_SystemModuleFinders_MethodInfo_,
	nullptr,
	nullptr,
	_SystemModuleFinders_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.module.SystemModuleFinders$ModuleContentSpliterator,jdk.internal.module.SystemModuleFinders$SystemModuleReader,jdk.internal.module.SystemModuleFinders$SystemImage,jdk.internal.module.SystemModuleFinders$SystemModuleFinder,jdk.internal.module.SystemModuleFinders$3,jdk.internal.module.SystemModuleFinders$2,jdk.internal.module.SystemModuleFinders$1"
};

$Object* allocate$SystemModuleFinders($Class* clazz) {
	return $of($alloc(SystemModuleFinders));
}

$JavaNetUriAccess* SystemModuleFinders::JNUA = nullptr;
bool SystemModuleFinders::USE_FAST_PATH = false;
$volatile($ModuleFinder*) SystemModuleFinders::cachedSystemModuleFinder = nullptr;

void SystemModuleFinders::init$() {
}

$SystemModules* SystemModuleFinders::allSystemModules() {
	$init(SystemModuleFinders);
	if (SystemModuleFinders::USE_FAST_PATH) {
		return $SystemModulesMap::allSystemModules();
	} else {
		return nullptr;
	}
}

$SystemModules* SystemModuleFinders::systemModules($String* initialModule) {
	$init(SystemModuleFinders);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (SystemModuleFinders::USE_FAST_PATH) {
		if (initialModule == nullptr) {
			return $SystemModulesMap::defaultSystemModules();
		}
		$var($StringArray, initialModules, $SystemModulesMap::moduleNames());
		for (int32_t i = 0; i < $nc(initialModules)->length; ++i) {
			$var($String, moduleName, initialModules->get(i));
			if ($nc(initialModule)->equals(moduleName)) {
				$var($String, cn, $nc($($SystemModulesMap::classNames()))->get(i));
				try {
					$var($Constructor, ctor, $Class::forName(cn)->getConstructor($$new($ClassArray, 0)));
					return $cast($SystemModules, $nc(ctor)->newInstance($$new($ObjectArray, 0)));
				} catch ($Exception& e) {
					$throwNew($InternalError, static_cast<$Throwable*>(e));
				}
			}
		}
	}
	return nullptr;
}

$ModuleFinder* SystemModuleFinders::of($SystemModules* systemModules) {
	$init(SystemModuleFinders);
	$useLocalCurrentObjectStackCache();
	$var($ModuleDescriptorArray, descriptors, $nc(systemModules)->moduleDescriptors());
	$var($ModuleTargetArray, targets, systemModules->moduleTargets());
	$var($ModuleHashesArray, recordedHashes, systemModules->moduleHashes());
	$var($ModuleResolutionArray, moduleResolutions, systemModules->moduleResolutions());
	int32_t moduleCount = $nc(descriptors)->length;
	$var($ModuleReferenceArray, mrefs, $new($ModuleReferenceArray, moduleCount));
	$var($Map$EntryArray, map, $new($Map$EntryArray, moduleCount));
	$var($Map, nameToHash, generateNameToHash(recordedHashes));
	for (int32_t i = 0; i < moduleCount; ++i) {
		$var($String, name, $nc(descriptors->get(i))->name());
		$var($ModuleHashes$HashSupplier, hashSupplier, SystemModuleFinders::hashSupplier(nameToHash, name));
		$var($ModuleReference, mref, toModuleReference(descriptors->get(i), $nc(targets)->get(i), $nc(recordedHashes)->get(i), hashSupplier, $nc(moduleResolutions)->get(i)));
		mrefs->set(i, mref);
		map->set(i, $($Map::entry(name, mref)));
	}
	return $new($SystemModuleFinders$SystemModuleFinder, mrefs, map);
}

$ModuleFinder* SystemModuleFinders::ofSystem() {
	$init(SystemModuleFinders);
	$var($ModuleFinder, finder, SystemModuleFinders::cachedSystemModuleFinder);
	if (finder != nullptr) {
		return finder;
	}
	$assign(finder, ::java::lang::Machine::getSystemModuleFinder());
	$assignStatic(SystemModuleFinders::cachedSystemModuleFinder, finder);
	return finder;
}

$ModuleFinder* SystemModuleFinders::ofModuleInfos() {
	$init(SystemModuleFinders);
	$useLocalCurrentObjectStackCache();
	$var($Map, nameToAttributes, $new($HashMap));
	$var($Map, nameToHash, $new($HashMap));
	$var($ImageReader, reader, $SystemModuleFinders$SystemImage::reader());
	{
		$var($StringArray, arr$, $nc(reader)->getModuleNames());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, mn, arr$->get(i$));
			{
				$var($ImageLocation, loc, reader->findLocation(mn, "module-info.class"_s));
				$var($ModuleInfo$Attributes, attrs, $ModuleInfo::read($(reader->getResourceBuffer(loc)), ($Supplier*)nullptr));
				nameToAttributes->put(mn, attrs);
				$var($ModuleHashes, hashes, $nc(attrs)->recordedHashes());
				if (hashes != nullptr) {
					{
						$var($Iterator, i$, $nc($(hashes->names()))->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($String, name, $cast($String, i$->next()));
							{
								nameToHash->computeIfAbsent(name, static_cast<$Function*>($$new(SystemModuleFinders$$Lambda$lambda$ofModuleInfos$0, hashes, name)));
							}
						}
					}
				}
			}
		}
	}
	$var($Set, mrefs, $new($HashSet));
	$var($Map, nameToModule, $new($HashMap));
	{
		$var($Iterator, i$, $nc($(nameToAttributes->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($String, mn, $cast($String, $nc(e)->getKey()));
				$var($ModuleInfo$Attributes, attrs, $cast($ModuleInfo$Attributes, e->getValue()));
				$var($ModuleHashes$HashSupplier, hashSupplier, SystemModuleFinders::hashSupplier(nameToHash, mn));
				$var($ModuleDescriptor, var$0, $nc(attrs)->descriptor());
				$var($ModuleTarget, var$1, attrs->target());
				$var($ModuleHashes, var$2, attrs->recordedHashes());
				$var($ModuleHashes$HashSupplier, var$3, hashSupplier);
				$var($ModuleReference, mref, toModuleReference(var$0, var$1, var$2, var$3, $(attrs->moduleResolution())));
				mrefs->add(mref);
				nameToModule->put(mn, mref);
			}
		}
	}
	return $new($SystemModuleFinders$SystemModuleFinder, mrefs, nameToModule);
}

$ModuleReference* SystemModuleFinders::toModuleReference($ModuleDescriptor* descriptor, $ModuleTarget* target, $ModuleHashes* recordedHashes, $ModuleHashes$HashSupplier* hasher, $ModuleResolution* mres) {
	$init(SystemModuleFinders);
	$useLocalCurrentObjectStackCache();
	$var($String, mn, $nc(descriptor)->name());
	$var($URI, uri, $nc(SystemModuleFinders::JNUA)->create("jrt"_s, $("/"_s->concat(mn))));
	$var($Supplier, readerSupplier, $new($SystemModuleFinders$2, mn, uri));
	$var($ModuleReference, mref, $new($ModuleReferenceImpl, descriptor, uri, readerSupplier, nullptr, target, recordedHashes, hasher, mres));
	$assign(mref, $nc($($ModuleBootstrap::patcher()))->patchIfNeeded(mref));
	return mref;
}

$Map* SystemModuleFinders::generateNameToHash($ModuleHashesArray* recordedHashes) {
	$init(SystemModuleFinders);
	$useLocalCurrentObjectStackCache();
	$var($Map, nameToHash, nullptr);
	bool secondSeen = false;
	{
		$var($ModuleHashesArray, arr$, recordedHashes);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($ModuleHashes, mh, arr$->get(i$));
			{
				if (mh != nullptr) {
					if (nameToHash == nullptr) {
						$assign(nameToHash, mh->hashes());
					} else {
						if (!secondSeen) {
							$assign(nameToHash, $new($HashMap, nameToHash));
							secondSeen = true;
						}
						$nc(nameToHash)->putAll($(mh->hashes()));
					}
				}
			}
		}
	}
	return (nameToHash != nullptr) ? nameToHash : $Map::of();
}

$ModuleHashes$HashSupplier* SystemModuleFinders::hashSupplier($Map* nameToHash, $String* name) {
	$init(SystemModuleFinders);
	$var($bytes, hash, $cast($bytes, $nc(nameToHash)->get(name)));
	if (hash != nullptr) {
		return $new($SystemModuleFinders$3, hash);
	} else {
		return nullptr;
	}
}

$bytes* SystemModuleFinders::lambda$ofModuleInfos$0($ModuleHashes* hashes, $String* name, $String* k) {
	$init(SystemModuleFinders);
	return $nc(hashes)->hashFor(name);
}

void clinit$SystemModuleFinders($Class* class$) {
	$assignStatic(SystemModuleFinders::JNUA, $SharedSecrets::getJavaNetUriAccess());
	{
		$var($String, value, $System::getProperty("jdk.system.module.finder.disableFastPath"_s));
		if (value == nullptr) {
			SystemModuleFinders::USE_FAST_PATH = true;
		} else {
			bool var$0 = !$nc(value)->isEmpty();
			SystemModuleFinders::USE_FAST_PATH = var$0 && !$Boolean::parseBoolean(value);
		}
	}
}

SystemModuleFinders::SystemModuleFinders() {
}

$Class* SystemModuleFinders::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SystemModuleFinders$$Lambda$lambda$ofModuleInfos$0::classInfo$.name)) {
			return SystemModuleFinders$$Lambda$lambda$ofModuleInfos$0::load$(name, initialize);
		}
	}
	$loadClass(SystemModuleFinders, name, initialize, &_SystemModuleFinders_ClassInfo_, clinit$SystemModuleFinders, allocate$SystemModuleFinders);
	return class$;
}

$Class* SystemModuleFinders::class$ = nullptr;

		} // module
	} // internal
} // jdk