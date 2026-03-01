#include <jdk/internal/jimage/ImageReader$SharedImageReader.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/ByteOrder.h>
#include <java/nio/IntBuffer.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <jdk/internal/jimage/BasicImageReader.h>
#include <jdk/internal/jimage/ImageLocation.h>
#include <jdk/internal/jimage/ImageReader$Directory.h>
#include <jdk/internal/jimage/ImageReader$LinkNode.h>
#include <jdk/internal/jimage/ImageReader$Node.h>
#include <jdk/internal/jimage/ImageReader$Resource.h>
#include <jdk/internal/jimage/ImageReader$SharedImageReader$LocationVisitor.h>
#include <jdk/internal/jimage/ImageReader.h>
#include <jcpp.h>

#undef OPEN_FILES
#undef SIZE_OF_OFFSET

using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $ByteOrder = ::java::nio::ByteOrder;
using $IntBuffer = ::java::nio::IntBuffer;
using $Files = ::java::nio::file::Files;
using $Path = ::java::nio::file::Path;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $BasicImageReader = ::jdk::internal::jimage::BasicImageReader;
using $ImageLocation = ::jdk::internal::jimage::ImageLocation;
using $ImageReader = ::jdk::internal::jimage::ImageReader;
using $ImageReader$Directory = ::jdk::internal::jimage::ImageReader$Directory;
using $ImageReader$LinkNode = ::jdk::internal::jimage::ImageReader$LinkNode;
using $ImageReader$Node = ::jdk::internal::jimage::ImageReader$Node;
using $ImageReader$Resource = ::jdk::internal::jimage::ImageReader$Resource;
using $ImageReader$SharedImageReader$LocationVisitor = ::jdk::internal::jimage::ImageReader$SharedImageReader$LocationVisitor;

namespace jdk {
	namespace internal {
		namespace jimage {

class ImageReader$SharedImageReader$$Lambda$lambda$handlePackages$0 : public $ImageReader$SharedImageReader$LocationVisitor {
	$class(ImageReader$SharedImageReader$$Lambda$lambda$handlePackages$0, $NO_CLASS_INIT, $ImageReader$SharedImageReader$LocationVisitor)
public:
	void init$(ImageReader$SharedImageReader* inst) {
		$set(this, inst$, inst);
	}
	virtual void visit($ImageLocation* childloc) override {
		$nc(inst$)->lambda$handlePackages$0(childloc);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ImageReader$SharedImageReader$$Lambda$lambda$handlePackages$0>());
	}
	ImageReader$SharedImageReader* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ImageReader$SharedImageReader$$Lambda$lambda$handlePackages$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ImageReader$SharedImageReader$$Lambda$lambda$handlePackages$0, inst$)},
	{}
};
$MethodInfo ImageReader$SharedImageReader$$Lambda$lambda$handlePackages$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/jimage/ImageReader$SharedImageReader;)V", nullptr, $PUBLIC, $method(ImageReader$SharedImageReader$$Lambda$lambda$handlePackages$0, init$, void, ImageReader$SharedImageReader*)},
	{"visit", "(Ljdk/internal/jimage/ImageLocation;)V", nullptr, $PUBLIC, $virtualMethod(ImageReader$SharedImageReader$$Lambda$lambda$handlePackages$0, visit, void, $ImageLocation*)},
	{}
};
$ClassInfo ImageReader$SharedImageReader$$Lambda$lambda$handlePackages$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.jimage.ImageReader$SharedImageReader$$Lambda$lambda$handlePackages$0",
	"java.lang.Object",
	"jdk.internal.jimage.ImageReader$SharedImageReader$LocationVisitor",
	fieldInfos,
	methodInfos
};
$Class* ImageReader$SharedImageReader$$Lambda$lambda$handlePackages$0::load$($String* name, bool initialize) {
	$loadClass(ImageReader$SharedImageReader$$Lambda$lambda$handlePackages$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ImageReader$SharedImageReader$$Lambda$lambda$handlePackages$0::class$ = nullptr;

class ImageReader$SharedImageReader$$Lambda$lambda$handleModulesSubTree$1$1 : public $ImageReader$SharedImageReader$LocationVisitor {
	$class(ImageReader$SharedImageReader$$Lambda$lambda$handleModulesSubTree$1$1, $NO_CLASS_INIT, $ImageReader$SharedImageReader$LocationVisitor)
public:
	void init$(ImageReader$SharedImageReader* inst, $ImageReader$Directory* dir) {
		$set(this, inst$, inst);
		$set(this, dir, dir);
	}
	virtual void visit($ImageLocation* childloc) override {
		$nc(inst$)->lambda$handleModulesSubTree$1(dir, childloc);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ImageReader$SharedImageReader$$Lambda$lambda$handleModulesSubTree$1$1>());
	}
	ImageReader$SharedImageReader* inst$ = nullptr;
	$ImageReader$Directory* dir = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ImageReader$SharedImageReader$$Lambda$lambda$handleModulesSubTree$1$1::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ImageReader$SharedImageReader$$Lambda$lambda$handleModulesSubTree$1$1, inst$)},
	{"dir", "Ljdk/internal/jimage/ImageReader$Directory;", nullptr, $PUBLIC, $field(ImageReader$SharedImageReader$$Lambda$lambda$handleModulesSubTree$1$1, dir)},
	{}
};
$MethodInfo ImageReader$SharedImageReader$$Lambda$lambda$handleModulesSubTree$1$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/jimage/ImageReader$SharedImageReader;Ljdk/internal/jimage/ImageReader$Directory;)V", nullptr, $PUBLIC, $method(ImageReader$SharedImageReader$$Lambda$lambda$handleModulesSubTree$1$1, init$, void, ImageReader$SharedImageReader*, $ImageReader$Directory*)},
	{"visit", "(Ljdk/internal/jimage/ImageLocation;)V", nullptr, $PUBLIC, $virtualMethod(ImageReader$SharedImageReader$$Lambda$lambda$handleModulesSubTree$1$1, visit, void, $ImageLocation*)},
	{}
};
$ClassInfo ImageReader$SharedImageReader$$Lambda$lambda$handleModulesSubTree$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.jimage.ImageReader$SharedImageReader$$Lambda$lambda$handleModulesSubTree$1$1",
	"java.lang.Object",
	"jdk.internal.jimage.ImageReader$SharedImageReader$LocationVisitor",
	fieldInfos,
	methodInfos
};
$Class* ImageReader$SharedImageReader$$Lambda$lambda$handleModulesSubTree$1$1::load$($String* name, bool initialize) {
	$loadClass(ImageReader$SharedImageReader$$Lambda$lambda$handleModulesSubTree$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ImageReader$SharedImageReader$$Lambda$lambda$handleModulesSubTree$1$1::class$ = nullptr;

$FieldInfo _ImageReader$SharedImageReader_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ImageReader$SharedImageReader, $assertionsDisabled)},
	{"SIZE_OF_OFFSET", "I", nullptr, $STATIC | $FINAL, $constField(ImageReader$SharedImageReader, SIZE_OF_OFFSET)},
	{"OPEN_FILES", "Ljava/util/Map;", "Ljava/util/Map<Ljava/nio/file/Path;Ljdk/internal/jimage/ImageReader$SharedImageReader;>;", $STATIC | $FINAL, $staticField(ImageReader$SharedImageReader, OPEN_FILES)},
	{"openers", "Ljava/util/Set;", "Ljava/util/Set<Ljdk/internal/jimage/ImageReader;>;", $FINAL, $field(ImageReader$SharedImageReader, openers)},
	{"imageFileAttributes", "Ljava/nio/file/attribute/BasicFileAttributes;", nullptr, 0, $field(ImageReader$SharedImageReader, imageFileAttributes$)},
	{"nodes", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/String;Ljdk/internal/jimage/ImageReader$Node;>;", $FINAL, $field(ImageReader$SharedImageReader, nodes)},
	{"rootDir", "Ljdk/internal/jimage/ImageReader$Directory;", nullptr, $VOLATILE, $field(ImageReader$SharedImageReader, rootDir)},
	{"packagesDir", "Ljdk/internal/jimage/ImageReader$Directory;", nullptr, 0, $field(ImageReader$SharedImageReader, packagesDir)},
	{"modulesDir", "Ljdk/internal/jimage/ImageReader$Directory;", nullptr, 0, $field(ImageReader$SharedImageReader, modulesDir)},
	{}
};

$MethodInfo _ImageReader$SharedImageReader_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/file/Path;Ljava/nio/ByteOrder;)V", nullptr, $PRIVATE, $method(ImageReader$SharedImageReader, init$, void, $Path*, $ByteOrder*), "java.io.IOException"},
	{"addOpener", "(Ljdk/internal/jimage/ImageReader;)V", nullptr, 0, $method(ImageReader$SharedImageReader, addOpener, void, $ImageReader*)},
	{"buildNode", "(Ljava/lang/String;)Ljdk/internal/jimage/ImageReader$Node;", nullptr, $SYNCHRONIZED, $method(ImageReader$SharedImageReader, buildNode, $ImageReader$Node*, $String*)},
	{"buildRootDirectory", "()Ljdk/internal/jimage/ImageReader$Directory;", nullptr, $SYNCHRONIZED, $method(ImageReader$SharedImageReader, buildRootDirectory, $ImageReader$Directory*)},
	{"close", "(Ljdk/internal/jimage/ImageReader;)V", nullptr, $PUBLIC, $method(ImageReader$SharedImageReader, close, void, $ImageReader*), "java.io.IOException"},
	{"findNode", "(Ljava/lang/String;)Ljdk/internal/jimage/ImageReader$Node;", nullptr, $SYNCHRONIZED, $method(ImageReader$SharedImageReader, findNode, $ImageReader$Node*, $String*)},
	{"getBaseExt", "(Ljdk/internal/jimage/ImageLocation;)Ljava/lang/String;", nullptr, 0, $method(ImageReader$SharedImageReader, getBaseExt, $String*, $ImageLocation*)},
	{"getResource", "(Ljdk/internal/jimage/ImageReader$Node;)[B", nullptr, 0, $method(ImageReader$SharedImageReader, getResource, $bytes*, $ImageReader$Node*), "java.io.IOException"},
	{"getResource", "(Ljdk/internal/jimage/ImageReader$Resource;)[B", nullptr, 0, $method(ImageReader$SharedImageReader, getResource, $bytes*, $ImageReader$Resource*), "java.io.IOException"},
	{"getRootDirectory", "()Ljdk/internal/jimage/ImageReader$Directory;", nullptr, 0, $method(ImageReader$SharedImageReader, getRootDirectory, $ImageReader$Directory*)},
	{"handleModuleLink", "(Ljava/lang/String;)Ljdk/internal/jimage/ImageReader$Node;", nullptr, 0, $method(ImageReader$SharedImageReader, handleModuleLink, $ImageReader$Node*, $String*)},
	{"handleModulesSubTree", "(Ljava/lang/String;Ljdk/internal/jimage/ImageLocation;)Ljdk/internal/jimage/ImageReader$Node;", nullptr, 0, $method(ImageReader$SharedImageReader, handleModulesSubTree, $ImageReader$Node*, $String*, $ImageLocation*)},
	{"handlePackages", "(Ljava/lang/String;Ljdk/internal/jimage/ImageLocation;)Ljdk/internal/jimage/ImageReader$Node;", nullptr, 0, $method(ImageReader$SharedImageReader, handlePackages, $ImageReader$Node*, $String*, $ImageLocation*)},
	{"handleResource", "(Ljava/lang/String;)Ljdk/internal/jimage/ImageReader$Node;", nullptr, 0, $method(ImageReader$SharedImageReader, handleResource, $ImageReader$Node*, $String*)},
	{"imageFileAttributes", "()Ljava/nio/file/attribute/BasicFileAttributes;", nullptr, 0, $method(ImageReader$SharedImageReader, imageFileAttributes, $BasicFileAttributes*)},
	{"lambda$handleModulesSubTree$1", "(Ljdk/internal/jimage/ImageReader$Directory;Ljdk/internal/jimage/ImageLocation;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(ImageReader$SharedImageReader, lambda$handleModulesSubTree$1, void, $ImageReader$Directory*, $ImageLocation*)},
	{"lambda$handlePackages$0", "(Ljdk/internal/jimage/ImageLocation;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(ImageReader$SharedImageReader, lambda$handlePackages$0, void, $ImageLocation*)},
	{"makeDirectories", "(Ljava/lang/String;)Ljdk/internal/jimage/ImageReader$Directory;", nullptr, 0, $method(ImageReader$SharedImageReader, makeDirectories, $ImageReader$Directory*, $String*)},
	{"makeDirectory", "(Ljava/lang/String;Ljdk/internal/jimage/ImageReader$Directory;)Ljdk/internal/jimage/ImageReader$Directory;", nullptr, 0, $method(ImageReader$SharedImageReader, makeDirectory, $ImageReader$Directory*, $String*, $ImageReader$Directory*)},
	{"newDirectory", "(Ljdk/internal/jimage/ImageReader$Directory;Ljava/lang/String;)Ljdk/internal/jimage/ImageReader$Directory;", nullptr, 0, $method(ImageReader$SharedImageReader, newDirectory, $ImageReader$Directory*, $ImageReader$Directory*, $String*)},
	{"newLinkNode", "(Ljdk/internal/jimage/ImageReader$Directory;Ljava/lang/String;Ljdk/internal/jimage/ImageReader$Node;)Ljdk/internal/jimage/ImageReader$LinkNode;", nullptr, 0, $method(ImageReader$SharedImageReader, newLinkNode, $ImageReader$LinkNode*, $ImageReader$Directory*, $String*, $ImageReader$Node*)},
	{"newResource", "(Ljdk/internal/jimage/ImageReader$Directory;Ljdk/internal/jimage/ImageLocation;)Ljdk/internal/jimage/ImageReader$Resource;", nullptr, 0, $method(ImageReader$SharedImageReader, newResource, $ImageReader$Resource*, $ImageReader$Directory*, $ImageLocation*)},
	{"open", "(Ljava/nio/file/Path;Ljava/nio/ByteOrder;)Ljdk/internal/jimage/ImageReader;", nullptr, $PUBLIC | $STATIC, $staticMethod(ImageReader$SharedImageReader, open, $ImageReader*, $Path*, $ByteOrder*), "java.io.IOException"},
	{"removeOpener", "(Ljdk/internal/jimage/ImageReader;)Z", nullptr, 0, $method(ImageReader$SharedImageReader, removeOpener, bool, $ImageReader*)},
	{"visitLocation", "(Ljdk/internal/jimage/ImageLocation;Ljdk/internal/jimage/ImageReader$SharedImageReader$LocationVisitor;)V", nullptr, 0, $method(ImageReader$SharedImageReader, visitLocation, void, $ImageLocation*, $ImageReader$SharedImageReader$LocationVisitor*)},
	{"visitPackageLocation", "(Ljdk/internal/jimage/ImageLocation;)V", nullptr, 0, $method(ImageReader$SharedImageReader, visitPackageLocation, void, $ImageLocation*)},
	{}
};

$InnerClassInfo _ImageReader$SharedImageReader_InnerClassesInfo_[] = {
	{"jdk.internal.jimage.ImageReader$SharedImageReader", "jdk.internal.jimage.ImageReader", "SharedImageReader", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.jimage.ImageReader$SharedImageReader$LocationVisitor", "jdk.internal.jimage.ImageReader$SharedImageReader", "LocationVisitor", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ImageReader$SharedImageReader_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.jimage.ImageReader$SharedImageReader",
	"jdk.internal.jimage.BasicImageReader",
	nullptr,
	_ImageReader$SharedImageReader_FieldInfo_,
	_ImageReader$SharedImageReader_MethodInfo_,
	nullptr,
	nullptr,
	_ImageReader$SharedImageReader_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.jimage.ImageReader"
};

$Object* allocate$ImageReader$SharedImageReader($Class* clazz) {
	return $of($alloc(ImageReader$SharedImageReader));
}

bool ImageReader$SharedImageReader::$assertionsDisabled = false;
$Map* ImageReader$SharedImageReader::OPEN_FILES = nullptr;

void ImageReader$SharedImageReader::init$($Path* imagePath, $ByteOrder* byteOrder) {
	$BasicImageReader::init$(imagePath, byteOrder);
	$set(this, openers, $new($HashSet));
	$set(this, nodes, $new($HashMap));
}

$ImageReader* ImageReader$SharedImageReader::open($Path* imagePath, $ByteOrder* byteOrder) {
	$init(ImageReader$SharedImageReader);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(imagePath);
	$Objects::requireNonNull(byteOrder);
	$synchronized(ImageReader$SharedImageReader::OPEN_FILES) {
		$var(ImageReader$SharedImageReader, reader, $cast(ImageReader$SharedImageReader, $nc(ImageReader$SharedImageReader::OPEN_FILES)->get(imagePath)));
		if (reader == nullptr) {
			$assign(reader, $new(ImageReader$SharedImageReader, imagePath, byteOrder));
			$nc(ImageReader$SharedImageReader::OPEN_FILES)->put(imagePath, reader);
		} else if ($nc(reader)->getByteOrder() != byteOrder) {
			$throwNew($IOException, $$str({"\""_s, $(reader->getName()), "\" is not an image file"_s}));
		}
		$var($ImageReader, image, $new($ImageReader, reader));
		$nc($nc(reader)->openers)->add(image);
		return image;
	}
}

void ImageReader$SharedImageReader::close($ImageReader* image) {
	$Objects::requireNonNull(image);
	$synchronized(ImageReader$SharedImageReader::OPEN_FILES) {
		if (!$nc(this->openers)->remove(image)) {
			$throwNew($IOException, "image file already closed"_s);
		}
		if ($nc(this->openers)->isEmpty()) {
			close();
			$nc(this->nodes)->clear();
			$set(this, rootDir, nullptr);
			if (!$nc(ImageReader$SharedImageReader::OPEN_FILES)->remove($(this->getImagePath()), this)) {
				$throwNew($IOException, "image file not found in open list"_s);
			}
		}
	}
}

void ImageReader$SharedImageReader::addOpener($ImageReader* reader) {
	$synchronized(ImageReader$SharedImageReader::OPEN_FILES) {
		$nc(this->openers)->add(reader);
	}
}

bool ImageReader$SharedImageReader::removeOpener($ImageReader* reader) {
	$synchronized(ImageReader$SharedImageReader::OPEN_FILES) {
		return $nc(this->openers)->remove(reader);
	}
}

$ImageReader$Directory* ImageReader$SharedImageReader::getRootDirectory() {
	return buildRootDirectory();
}

$ImageReader$Node* ImageReader$SharedImageReader::buildNode($String* name) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($ImageReader$Node, n, nullptr);
		bool isPackages = $nc(name)->startsWith("/packages"_s);
		bool isModules = !isPackages && name->startsWith("/modules"_s);
		if (!(isModules || isPackages)) {
			return nullptr;
		}
		$var($ImageLocation, loc, findLocation(name));
		if (loc != nullptr) {
			if (isPackages) {
				$assign(n, handlePackages(name, loc));
			} else {
				$assign(n, handleModulesSubTree(name, loc));
			}
		} else if (isModules) {
			$assign(n, handleResource(name));
		} else {
			$assign(n, handleModuleLink(name));
		}
		return n;
	}
}

$ImageReader$Directory* ImageReader$SharedImageReader::buildRootDirectory() {
	$synchronized(this) {
		$var($ImageReader$Directory, root, this->rootDir);
		if (root != nullptr) {
			return root;
		}
		$assign(root, newDirectory(nullptr, "/"_s));
		$nc(root)->setIsRootDir();
		$set(this, packagesDir, newDirectory(root, "/packages"_s));
		$nc(this->packagesDir)->setIsPackagesDir();
		$set(this, modulesDir, newDirectory(root, "/modules"_s));
		$nc(this->modulesDir)->setIsModulesDir();
		root->setCompleted(true);
		return $set(this, rootDir, root);
	}
}

void ImageReader$SharedImageReader::visitLocation($ImageLocation* loc, $ImageReader$SharedImageReader$LocationVisitor* visitor) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, offsets, getResource(loc));
	$var($ByteBuffer, buffer, $ByteBuffer::wrap(offsets));
	$nc(buffer)->order($(getByteOrder()));
	$var($IntBuffer, intBuffer, buffer->asIntBuffer());
	for (int32_t i = 0; i < $div($nc(offsets)->length, ImageReader$SharedImageReader::SIZE_OF_OFFSET); ++i) {
		int32_t offset = $nc(intBuffer)->get(i);
		$var($ImageLocation, pkgLoc, getLocation(offset));
		$nc(visitor)->visit(pkgLoc);
	}
}

void ImageReader$SharedImageReader::visitPackageLocation($ImageLocation* loc) {
	$useLocalCurrentObjectStackCache();
	$var($String, pkgName, getBaseExt(loc));
	$var($bytes, stringsOffsets, getResource(loc));
	$var($ByteBuffer, buffer, $ByteBuffer::wrap(stringsOffsets));
	$nc(buffer)->order($(getByteOrder()));
	$var($IntBuffer, intBuffer, buffer->asIntBuffer());
	for (int32_t i = 0; i < $div($nc(stringsOffsets)->length, ImageReader$SharedImageReader::SIZE_OF_OFFSET); ++i) {
		$nc(intBuffer)->get(i);
		++i;
		int32_t offset = intBuffer->get(i);
		$var($String, moduleName, getString(offset));
		$var($ImageReader$Node, targetNode, findNode($$str({"/modules/"_s, moduleName})));
		if (targetNode != nullptr) {
			$var($String, pkgDirName, $str({$($nc(this->packagesDir)->getName()), "/"_s, pkgName}));
			$var($ImageReader$Directory, pkgDir, $cast($ImageReader$Directory, $nc(this->nodes)->get(pkgDirName)));
			newLinkNode(pkgDir, $$str({$($nc(pkgDir)->getName()), "/"_s, moduleName}), targetNode);
		}
	}
}

$ImageReader$Node* ImageReader$SharedImageReader::handlePackages($String* name, $ImageLocation* loc) {
	$useLocalCurrentObjectStackCache();
	int64_t size = $nc(loc)->getUncompressedSize();
	$var($ImageReader$Node, n, nullptr);
	if ($nc(name)->equals("/packages"_s)) {
		visitLocation(loc, static_cast<$ImageReader$SharedImageReader$LocationVisitor*>($$new(ImageReader$SharedImageReader$$Lambda$lambda$handlePackages$0, this)));
		$nc(this->packagesDir)->setCompleted(true);
		$assign(n, this->packagesDir);
	} else if (size != 0) {
		$var($String, pkgName, getBaseExt(loc));
		$var($ImageReader$Directory, pkgDir, newDirectory(this->packagesDir, $$str({$($nc(this->packagesDir)->getName()), "/"_s, pkgName})));
		visitPackageLocation(loc);
		$nc(pkgDir)->setCompleted(true);
		$assign(n, pkgDir);
	} else {
		$var($String, pkgName, loc->getParent());
		$var($String, modName, getBaseExt(loc));
		$var($ImageReader$Node, targetNode, findNode($$str({"/modules/"_s, modName})));
		if (targetNode != nullptr) {
			$var($String, pkgDirName, $str({$($nc(this->packagesDir)->getName()), "/"_s, pkgName}));
			$var($ImageReader$Directory, pkgDir, $cast($ImageReader$Directory, $nc(this->nodes)->get(pkgDirName)));
			$var($ImageReader$Node, linkNode, newLinkNode(pkgDir, $$str({$($nc(pkgDir)->getName()), "/"_s, modName}), targetNode));
			$assign(n, linkNode);
		}
	}
	return n;
}

$ImageReader$Node* ImageReader$SharedImageReader::handleModuleLink($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($ImageReader$Node, ret, nullptr);
	$var($String, radical, "/packages/"_s);
	$var($String, path, name);
	if ($nc(path)->startsWith(radical)) {
		int32_t start = radical->length();
		int32_t pkgEnd = path->indexOf((int32_t)u'/', start);
		if (pkgEnd != -1) {
			$var($String, pkg, path->substring(start, pkgEnd));
			$var($String, pkgPath, $str({radical, pkg}));
			$var($ImageReader$Node, n, findNode(pkgPath));
			{
				$var($Iterator, i$, $nc($($nc(n)->getChildren()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($ImageReader$Node, child, $cast($ImageReader$Node, i$->next()));
					{
						if ($nc($nc(child)->name)->equals(name)) {
							$assign(ret, child);
							break;
						}
					}
				}
			}
		}
	}
	return ret;
}

$ImageReader$Node* ImageReader$SharedImageReader::handleModulesSubTree($String* name, $ImageLocation* loc) {
	$useLocalCurrentObjectStackCache();
	$var($ImageReader$Node, n, nullptr);
	if (!ImageReader$SharedImageReader::$assertionsDisabled && !($nc(name)->equals($($nc(loc)->getFullName())))) {
		$throwNew($AssertionError);
	}
	$var($ImageReader$Directory, dir, makeDirectories(name));
	visitLocation(loc, static_cast<$ImageReader$SharedImageReader$LocationVisitor*>($$new(ImageReader$SharedImageReader$$Lambda$lambda$handleModulesSubTree$1$1, this, dir)));
	$nc(dir)->setCompleted(true);
	$assign(n, dir);
	return n;
}

$ImageReader$Node* ImageReader$SharedImageReader::handleResource($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($ImageReader$Node, n, nullptr);
	if (!$nc(name)->startsWith("/modules/"_s)) {
		return nullptr;
	}
	int32_t moduleEndIndex = $nc(name)->indexOf((int32_t)u'/', "/modules/"_s->length());
	if (moduleEndIndex == -1) {
		return nullptr;
	}
	$var($ImageLocation, moduleLoc, findLocation($(name->substring(0, moduleEndIndex))));
	if (moduleLoc == nullptr || $nc(moduleLoc)->getModuleOffset() == 0) {
		return nullptr;
	}
	$var($String, locationPath, name->substring("/modules"_s->length()));
	$var($ImageLocation, resourceLoc, findLocation(locationPath));
	if (resourceLoc != nullptr) {
		$var($ImageReader$Directory, dir, makeDirectories($(resourceLoc->buildName(true, true, false))));
		$var($ImageReader$Resource, res, newResource(dir, resourceLoc));
		$assign(n, res);
	}
	return n;
}

$String* ImageReader$SharedImageReader::getBaseExt($ImageLocation* loc) {
	$useLocalCurrentObjectStackCache();
	$var($String, base, $nc(loc)->getBase());
	$var($String, ext, loc->getExtension());
	if (ext != nullptr && !ext->isEmpty()) {
		$assign(base, $str({base, "."_s, ext}));
	}
	return base;
}

$ImageReader$Node* ImageReader$SharedImageReader::findNode($String* name) {
	$synchronized(this) {
		buildRootDirectory();
		$var($ImageReader$Node, n, $cast($ImageReader$Node, $nc(this->nodes)->get(name)));
		if (n == nullptr || !$nc(n)->isCompleted()) {
			$assign(n, buildNode(name));
		}
		return n;
	}
}

$BasicFileAttributes* ImageReader$SharedImageReader::imageFileAttributes() {
	$useLocalCurrentObjectStackCache();
	$var($BasicFileAttributes, attrs, this->imageFileAttributes$);
	if (attrs == nullptr) {
		try {
			$var($Path, file, getImagePath());
			$load($BasicFileAttributes);
			$assign(attrs, $Files::readAttributes(file, $BasicFileAttributes::class$, $$new($LinkOptionArray, 0)));
		} catch ($IOException& ioe) {
			$throwNew($UncheckedIOException, ioe);
		}
		$set(this, imageFileAttributes$, attrs);
	}
	return attrs;
}

$ImageReader$Directory* ImageReader$SharedImageReader::newDirectory($ImageReader$Directory* parent, $String* name) {
	$useLocalCurrentObjectStackCache();
	$var($ImageReader$Directory, dir, $ImageReader$Directory::create(parent, name, $(imageFileAttributes())));
	$nc(this->nodes)->put($($nc(dir)->getName()), dir);
	return dir;
}

$ImageReader$Resource* ImageReader$SharedImageReader::newResource($ImageReader$Directory* parent, $ImageLocation* loc) {
	$useLocalCurrentObjectStackCache();
	$var($ImageReader$Resource, res, $ImageReader$Resource::create(parent, loc, $(imageFileAttributes())));
	$nc(this->nodes)->put($($nc(res)->getName()), res);
	return res;
}

$ImageReader$LinkNode* ImageReader$SharedImageReader::newLinkNode($ImageReader$Directory* dir, $String* name, $ImageReader$Node* link) {
	$useLocalCurrentObjectStackCache();
	$var($ImageReader$LinkNode, linkNode, $ImageReader$LinkNode::create(dir, name, link));
	$nc(this->nodes)->put($($nc(linkNode)->getName()), linkNode);
	return linkNode;
}

$ImageReader$Directory* ImageReader$SharedImageReader::makeDirectories($String* parent) {
	$useLocalCurrentObjectStackCache();
	$var($ImageReader$Directory, last, this->rootDir);
	for (int32_t offset = $nc(parent)->indexOf((int32_t)u'/', 1); offset != -1; offset = parent->indexOf((int32_t)u'/', offset + 1)) {
		$var($String, dir, parent->substring(0, offset));
		$assign(last, makeDirectory(dir, last));
	}
	return makeDirectory(parent, last);
}

$ImageReader$Directory* ImageReader$SharedImageReader::makeDirectory($String* dir, $ImageReader$Directory* last) {
	$var($ImageReader$Directory, nextDir, $cast($ImageReader$Directory, $nc(this->nodes)->get(dir)));
	if (nextDir == nullptr) {
		$assign(nextDir, newDirectory(last, dir));
	}
	return nextDir;
}

$bytes* ImageReader$SharedImageReader::getResource($ImageReader$Node* node) {
	$useLocalCurrentObjectStackCache();
	if ($nc(node)->isResource()) {
		return $BasicImageReader::getResource($(node->getLocation()));
	}
	$throwNew($IOException, $$str({"Not a resource: "_s, node}));
}

$bytes* ImageReader$SharedImageReader::getResource($ImageReader$Resource* rs) {
	return $BasicImageReader::getResource($($nc(rs)->getLocation()));
}

void ImageReader$SharedImageReader::lambda$handleModulesSubTree$1($ImageReader$Directory* dir, $ImageLocation* childloc) {
	$useLocalCurrentObjectStackCache();
	$var($String, path, $nc(childloc)->getFullName());
	if ($nc(path)->startsWith("/modules"_s)) {
		makeDirectories(path);
	} else {
		makeDirectories($(childloc->buildName(true, true, false)));
		newResource(dir, childloc);
	}
}

void ImageReader$SharedImageReader::lambda$handlePackages$0($ImageLocation* childloc) {
	findNode($($nc(childloc)->getFullName()));
}

void clinit$ImageReader$SharedImageReader($Class* class$) {
	$load($ImageReader);
	ImageReader$SharedImageReader::$assertionsDisabled = !$ImageReader::class$->desiredAssertionStatus();
	$assignStatic(ImageReader$SharedImageReader::OPEN_FILES, $new($HashMap));
}

ImageReader$SharedImageReader::ImageReader$SharedImageReader() {
}

$Class* ImageReader$SharedImageReader::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ImageReader$SharedImageReader$$Lambda$lambda$handlePackages$0::classInfo$.name)) {
			return ImageReader$SharedImageReader$$Lambda$lambda$handlePackages$0::load$(name, initialize);
		}
		if (name->equals(ImageReader$SharedImageReader$$Lambda$lambda$handleModulesSubTree$1$1::classInfo$.name)) {
			return ImageReader$SharedImageReader$$Lambda$lambda$handleModulesSubTree$1$1::load$(name, initialize);
		}
	}
	$loadClass(ImageReader$SharedImageReader, name, initialize, &_ImageReader$SharedImageReader_ClassInfo_, clinit$ImageReader$SharedImageReader, allocate$ImageReader$SharedImageReader);
	return class$;
}

$Class* ImageReader$SharedImageReader::class$ = nullptr;

		} // jimage
	} // internal
} // jdk