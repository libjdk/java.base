#include <jdk/internal/jrtfs/ExplodedImage.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/file/DirectoryStream.h>
#include <java/nio/file/FileSystem.h>
#include <java/nio/file/FileSystems.h>
#include <java/nio/file/FileVisitOption.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/jimage/ImageReader$Node.h>
#include <jdk/internal/jrtfs/ExplodedImage$PathNode.h>
#include <jdk/internal/jrtfs/SystemImage.h>
#include <jcpp.h>

#undef MODULES
#undef PACKAGES
#undef PACKAGES_LEN

using $FileVisitOptionArray = $Array<::java::nio::file::FileVisitOption>;
using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $DirectoryStream = ::java::nio::file::DirectoryStream;
using $FileSystem = ::java::nio::file::FileSystem;
using $FileSystems = ::java::nio::file::FileSystems;
using $Files = ::java::nio::file::Files;
using $Path = ::java::nio::file::Path;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $Consumer = ::java::util::function::Consumer;
using $Predicate = ::java::util::function::Predicate;
using $Stream = ::java::util::stream::Stream;
using $ImageReader$Node = ::jdk::internal::jimage::ImageReader$Node;
using $ExplodedImage$PathNode = ::jdk::internal::jrtfs::ExplodedImage$PathNode;
using $SystemImage = ::jdk::internal::jrtfs::SystemImage;

namespace jdk {
	namespace internal {
		namespace jrtfs {

class ExplodedImage$$Lambda$lambda$initNodes$0 : public $Predicate {
	$class(ExplodedImage$$Lambda$lambda$initNodes$0, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* x$0) override {
		 return ExplodedImage::lambda$initNodes$0($cast($Path, x$0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ExplodedImage$$Lambda$lambda$initNodes$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ExplodedImage$$Lambda$lambda$initNodes$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ExplodedImage$$Lambda$lambda$initNodes$0, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ExplodedImage$$Lambda$lambda$initNodes$0, test, bool, Object$*)},
	{}
};
$ClassInfo ExplodedImage$$Lambda$lambda$initNodes$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.jrtfs.ExplodedImage$$Lambda$lambda$initNodes$0",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* ExplodedImage$$Lambda$lambda$initNodes$0::load$($String* name, bool initialize) {
	$loadClass(ExplodedImage$$Lambda$lambda$initNodes$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ExplodedImage$$Lambda$lambda$initNodes$0::class$ = nullptr;

class ExplodedImage$$Lambda$lambda$initNodes$1$1 : public $Consumer {
	$class(ExplodedImage$$Lambda$lambda$initNodes$1$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$(ExplodedImage* inst, $Path* module, $Map* packageToModules, $String* moduleName) {
		$set(this, inst$, inst);
		$set(this, module, module);
		$set(this, packageToModules, packageToModules);
		$set(this, moduleName, moduleName);
	}
	virtual void accept(Object$* p) override {
		$nc(inst$)->lambda$initNodes$1(module, packageToModules, moduleName, $cast($Path, p));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ExplodedImage$$Lambda$lambda$initNodes$1$1>());
	}
	ExplodedImage* inst$ = nullptr;
	$Path* module = nullptr;
	$Map* packageToModules = nullptr;
	$String* moduleName = nullptr;
	static $FieldInfo fieldInfos[5];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ExplodedImage$$Lambda$lambda$initNodes$1$1::fieldInfos[5] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ExplodedImage$$Lambda$lambda$initNodes$1$1, inst$)},
	{"module", "Ljava/nio/file/Path;", nullptr, $PUBLIC, $field(ExplodedImage$$Lambda$lambda$initNodes$1$1, module)},
	{"packageToModules", "Ljava/util/Map;", nullptr, $PUBLIC, $field(ExplodedImage$$Lambda$lambda$initNodes$1$1, packageToModules)},
	{"moduleName", "Ljava/lang/String;", nullptr, $PUBLIC, $field(ExplodedImage$$Lambda$lambda$initNodes$1$1, moduleName)},
	{}
};
$MethodInfo ExplodedImage$$Lambda$lambda$initNodes$1$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/jrtfs/ExplodedImage;Ljava/nio/file/Path;Ljava/util/Map;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(ExplodedImage$$Lambda$lambda$initNodes$1$1, init$, void, ExplodedImage*, $Path*, $Map*, $String*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ExplodedImage$$Lambda$lambda$initNodes$1$1, accept, void, Object$*)},
	{}
};
$ClassInfo ExplodedImage$$Lambda$lambda$initNodes$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.jrtfs.ExplodedImage$$Lambda$lambda$initNodes$1$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ExplodedImage$$Lambda$lambda$initNodes$1$1::load$($String* name, bool initialize) {
	$loadClass(ExplodedImage$$Lambda$lambda$initNodes$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ExplodedImage$$Lambda$lambda$initNodes$1$1::class$ = nullptr;

$FieldInfo _ExplodedImage_FieldInfo_[] = {
	{"MODULES", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ExplodedImage, MODULES)},
	{"PACKAGES", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ExplodedImage, PACKAGES)},
	{"PACKAGES_LEN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ExplodedImage, PACKAGES_LEN)},
	{"defaultFS", "Ljava/nio/file/FileSystem;", nullptr, $PRIVATE | $FINAL, $field(ExplodedImage, defaultFS)},
	{"separator", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(ExplodedImage, separator)},
	{"nodes", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljdk/internal/jrtfs/ExplodedImage$PathNode;>;", $PRIVATE | $FINAL, $field(ExplodedImage, nodes)},
	{"modulesDirAttrs", "Ljava/nio/file/attribute/BasicFileAttributes;", nullptr, $PRIVATE | $FINAL, $field(ExplodedImage, modulesDirAttrs)},
	{}
};

$MethodInfo _ExplodedImage_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/file/Path;)V", nullptr, 0, $method(ExplodedImage, init$, void, $Path*), "java.io.IOException"},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(ExplodedImage, close, void), "java.io.IOException"},
	{"findModulesNode", "(Ljava/lang/String;)Ljdk/internal/jimage/ImageReader$Node;", nullptr, 0, $virtualMethod(ExplodedImage, findModulesNode, $ImageReader$Node*, $String*)},
	{"findNode", "(Ljava/lang/String;)Ljdk/internal/jimage/ImageReader$Node;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(ExplodedImage, findNode, $ImageReader$Node*, $String*)},
	{"frontSlashToNativeSlash", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(ExplodedImage, frontSlashToNativeSlash, $String*, $String*)},
	{"getResource", "(Ljdk/internal/jimage/ImageReader$Node;)[B", nullptr, $PUBLIC, $virtualMethod(ExplodedImage, getResource, $bytes*, $ImageReader$Node*), "java.io.IOException"},
	{"initNodes", "()V", nullptr, $PRIVATE, $method(ExplodedImage, initNodes, void), "java.io.IOException"},
	{"lambda$initNodes$0", "(Ljava/nio/file/Path;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ExplodedImage, lambda$initNodes$0, bool, $Path*)},
	{"lambda$initNodes$1", "(Ljava/nio/file/Path;Ljava/util/Map;Ljava/lang/String;Ljava/nio/file/Path;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(ExplodedImage, lambda$initNodes$1, void, $Path*, $Map*, $String*, $Path*)},
	{"nativeSlashToFrontSlash", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(ExplodedImage, nativeSlashToFrontSlash, $String*, $String*)},
	{"slashesToDots", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(ExplodedImage, slashesToDots, $String*, $String*)},
	{"underlyingPath", "(Ljava/lang/String;)Ljava/nio/file/Path;", nullptr, 0, $virtualMethod(ExplodedImage, underlyingPath, $Path*, $String*)},
	{}
};

$InnerClassInfo _ExplodedImage_InnerClassesInfo_[] = {
	{"jdk.internal.jrtfs.ExplodedImage$PathNode", "jdk.internal.jrtfs.ExplodedImage", "PathNode", $PRIVATE | $FINAL},
	{}
};

$ClassInfo _ExplodedImage_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.jrtfs.ExplodedImage",
	"jdk.internal.jrtfs.SystemImage",
	nullptr,
	_ExplodedImage_FieldInfo_,
	_ExplodedImage_MethodInfo_,
	nullptr,
	nullptr,
	_ExplodedImage_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.jrtfs.ExplodedImage$PathNode"
};

$Object* allocate$ExplodedImage($Class* clazz) {
	return $of($alloc(ExplodedImage));
}

$String* ExplodedImage::MODULES = nullptr;
$String* ExplodedImage::PACKAGES = nullptr;
int32_t ExplodedImage::PACKAGES_LEN = 0;

void ExplodedImage::init$($Path* modulesDir) {
	$useLocalCurrentObjectStackCache();
	$SystemImage::init$();
	$set(this, nodes, $Collections::synchronizedMap($$new($HashMap)));
	$set(this, defaultFS, $FileSystems::getDefault());
	$var($String, str, $nc(this->defaultFS)->getSeparator());
	$set(this, separator, $nc(str)->equals("/"_s) ? ($String*)nullptr : str);
	$load($BasicFileAttributes);
	$set(this, modulesDirAttrs, $Files::readAttributes(modulesDir, $BasicFileAttributes::class$, $$new($LinkOptionArray, 0)));
	initNodes();
}

void ExplodedImage::close() {
	$nc(this->nodes)->clear();
}

$bytes* ExplodedImage::getResource($ImageReader$Node* node) {
	return $nc(($cast($ExplodedImage$PathNode, node)))->getContent();
}

$ImageReader$Node* ExplodedImage::findNode($String* str) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($ImageReader$Node, node, findModulesNode(str));
		if (node != nullptr) {
			return node;
		}
		if ($nc(str)->startsWith(ExplodedImage::PACKAGES)) {
			int32_t pkgEndIdx = str->indexOf((int32_t)u'/', ExplodedImage::PACKAGES_LEN);
			if (pkgEndIdx != -1) {
				int32_t modEndIdx = str->indexOf((int32_t)u'/', pkgEndIdx + 1);
				if (modEndIdx != -1) {
					$var($ImageReader$Node, linkNode, $cast($ImageReader$Node, $nc(this->nodes)->get($(str->substring(0, modEndIdx)))));
					if (linkNode == nullptr || !$nc(linkNode)->isLink()) {
						return nullptr;
					}
					$var($String, mod, $str({ExplodedImage::MODULES, $(str->substring(pkgEndIdx + 1))}));
					return findModulesNode(mod);
				}
			}
		}
		return nullptr;
	}
}

$ImageReader$Node* ExplodedImage::findModulesNode($String* str) {
	$useLocalCurrentObjectStackCache();
	$var($ExplodedImage$PathNode, node, $cast($ExplodedImage$PathNode, $nc(this->nodes)->get(str)));
	if (node != nullptr) {
		return node;
	}
	$var($Path, p, underlyingPath(str));
	if (p != nullptr) {
		try {
			$load($BasicFileAttributes);
			$var($BasicFileAttributes, attrs, $Files::readAttributes(p, $BasicFileAttributes::class$, $$new($LinkOptionArray, 0)));
			if ($nc(attrs)->isRegularFile()) {
				$var($Path, f, p->getFileName());
				if ($nc($($nc(f)->toString()))->startsWith("_the."_s)) {
					return nullptr;
				}
			}
			$assign(node, $new($ExplodedImage$PathNode, this, str, p, attrs));
			$nc(this->nodes)->put(str, node);
			return node;
		} catch ($IOException& x) {
		}
	}
	return nullptr;
}

$Path* ExplodedImage::underlyingPath($String* str$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, str, str$renamed);
	if ($nc(str)->startsWith(ExplodedImage::MODULES)) {
		$assign(str, frontSlashToNativeSlash($(str->substring("/modules"_s->length()))));
		$init($SystemImage);
		return $nc(this->defaultFS)->getPath($($nc($SystemImage::explodedModulesDir)->toString()), $$new($StringArray, {str}));
	}
	return nullptr;
}

$String* ExplodedImage::frontSlashToNativeSlash($String* str) {
	return this->separator == nullptr ? str : $nc(str)->replace(static_cast<$CharSequence*>("/"_s), static_cast<$CharSequence*>(this->separator));
}

$String* ExplodedImage::nativeSlashToFrontSlash($String* str) {
	return this->separator == nullptr ? str : $nc(str)->replace(static_cast<$CharSequence*>(this->separator), static_cast<$CharSequence*>("/"_s));
}

$String* ExplodedImage::slashesToDots($String* str) {
	return $nc(str)->replace(this->separator != nullptr ? static_cast<$CharSequence*>(this->separator) : static_cast<$CharSequence*>("/"_s), static_cast<$CharSequence*>("."_s));
}

void ExplodedImage::initNodes() {
	$useLocalCurrentObjectStackCache();
	$var($Map, packageToModules, $new($HashMap));
	{
		$init($SystemImage);
		$var($DirectoryStream, stream, $Files::newDirectoryStream($SystemImage::explodedModulesDir));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					{
						$var($Iterator, i$, $nc(stream)->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($Path, module, $cast($Path, i$->next()));
							{
								if ($Files::isDirectory(module, $$new($LinkOptionArray, 0))) {
									$var($String, moduleName, $nc($($nc(module)->getFileName()))->toString());
									findModulesNode($$str({ExplodedImage::MODULES, moduleName}));
									$nc($($nc($($Files::walk(module, $$new($FileVisitOptionArray, 0))))->filter(static_cast<$Predicate*>($$new(ExplodedImage$$Lambda$lambda$initNodes$0)))))->forEach(static_cast<$Consumer*>($$new(ExplodedImage$$Lambda$lambda$initNodes$1$1, this, module, packageToModules, moduleName)));
								}
							}
						}
					}
				} catch ($Throwable& t$) {
					if (stream != nullptr) {
						try {
							stream->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				if (stream != nullptr) {
					stream->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
	$var($ExplodedImage$PathNode, modulesDir, $new($ExplodedImage$PathNode, this, "/modules"_s, static_cast<$List*>($$new($ArrayList, $($nc(this->nodes)->values())))));
	$nc(this->nodes)->put($(modulesDir->getName()), modulesDir);
	$var($List, packagesChildren, $new($ArrayList, packageToModules->size()));
	{
		$var($Iterator, i$, $nc($(packageToModules->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				$var($String, pkgName, $cast($String, $nc(entry)->getKey()));
				$var($List, moduleNameList, $cast($List, entry->getValue()));
				$var($List, moduleLinkNodes, $new($ArrayList, $nc(moduleNameList)->size()));
				{
					$var($Iterator, i$, $nc(moduleNameList)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($String, moduleName, $cast($String, i$->next()));
						{
							$var($ImageReader$Node, moduleNode, findModulesNode($$str({ExplodedImage::MODULES, moduleName})));
							$var($ExplodedImage$PathNode, linkNode, $new($ExplodedImage$PathNode, this, $$str({ExplodedImage::PACKAGES, pkgName, "/"_s, moduleName}), moduleNode));
							$nc(this->nodes)->put($(linkNode->getName()), linkNode);
							moduleLinkNodes->add(linkNode);
						}
					}
				}
				$var($ExplodedImage$PathNode, pkgDir, $new($ExplodedImage$PathNode, this, $$str({ExplodedImage::PACKAGES, pkgName}), moduleLinkNodes));
				$nc(this->nodes)->put($(pkgDir->getName()), pkgDir);
				packagesChildren->add(pkgDir);
			}
		}
	}
	$var($ExplodedImage$PathNode, packagesDir, $new($ExplodedImage$PathNode, this, "/packages"_s, packagesChildren));
	$nc(this->nodes)->put($(packagesDir->getName()), packagesDir);
	$var($List, rootChildren, $new($ArrayList));
	rootChildren->add(packagesDir);
	rootChildren->add(modulesDir);
	$var($ExplodedImage$PathNode, root, $new($ExplodedImage$PathNode, this, "/"_s, rootChildren));
	$nc(this->nodes)->put($(root->getName()), root);
}

void ExplodedImage::lambda$initNodes$1($Path* module, $Map* packageToModules, $String* moduleName, $Path* p$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Path, p, p$renamed);
	$assign(p, $nc(module)->relativize(p));
	$var($String, pkgName, slashesToDots($($nc(p)->toString())));
	bool var$0 = !$nc(pkgName)->isEmpty();
	if (var$0 && !pkgName->startsWith("META-INF"_s)) {
		$var($List, moduleNames, $cast($List, $nc(packageToModules)->get(pkgName)));
		if (moduleNames == nullptr) {
			$assign(moduleNames, $new($ArrayList));
			packageToModules->put(pkgName, moduleNames);
		}
		$nc(moduleNames)->add(moduleName);
	}
}

bool ExplodedImage::lambda$initNodes$0($Path* x$0) {
	$init(ExplodedImage);
	return $Files::isDirectory(x$0, $$new($LinkOptionArray, 0));
}

void clinit$ExplodedImage($Class* class$) {
	$assignStatic(ExplodedImage::MODULES, "/modules/"_s);
	$assignStatic(ExplodedImage::PACKAGES, "/packages/"_s);
	ExplodedImage::PACKAGES_LEN = $nc(ExplodedImage::PACKAGES)->length();
}

ExplodedImage::ExplodedImage() {
}

$Class* ExplodedImage::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ExplodedImage$$Lambda$lambda$initNodes$0::classInfo$.name)) {
			return ExplodedImage$$Lambda$lambda$initNodes$0::load$(name, initialize);
		}
		if (name->equals(ExplodedImage$$Lambda$lambda$initNodes$1$1::classInfo$.name)) {
			return ExplodedImage$$Lambda$lambda$initNodes$1$1::load$(name, initialize);
		}
	}
	$loadClass(ExplodedImage, name, initialize, &_ExplodedImage_ClassInfo_, clinit$ExplodedImage, allocate$ExplodedImage);
	return class$;
}

$Class* ExplodedImage::class$ = nullptr;

		} // jrtfs
	} // internal
} // jdk