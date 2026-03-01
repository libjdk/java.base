#include <jdk/internal/jimage/ImageReader$Directory.h>

#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/function/Consumer.h>
#include <jdk/internal/jimage/ImageReader$Node.h>
#include <jdk/internal/jimage/ImageReader.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Consumer = ::java::util::function::Consumer;
using $ImageReader$Node = ::jdk::internal::jimage::ImageReader$Node;

namespace jdk {
	namespace internal {
		namespace jimage {

$FieldInfo _ImageReader$Directory_FieldInfo_[] = {
	{"children", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/jimage/ImageReader$Node;>;", $PRIVATE | $FINAL, $field(ImageReader$Directory, children)},
	{}
};

$MethodInfo _ImageReader$Directory_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/nio/file/attribute/BasicFileAttributes;)V", nullptr, $PRIVATE, $method(ImageReader$Directory, init$, void, $String*, $BasicFileAttributes*)},
	{"addChild", "(Ljdk/internal/jimage/ImageReader$Node;)V", nullptr, 0, $method(ImageReader$Directory, addChild, void, $ImageReader$Node*)},
	{"create", "(Ljdk/internal/jimage/ImageReader$Directory;Ljava/lang/String;Ljava/nio/file/attribute/BasicFileAttributes;)Ljdk/internal/jimage/ImageReader$Directory;", nullptr, $STATIC, $staticMethod(ImageReader$Directory, create, ImageReader$Directory*, ImageReader$Directory*, $String*, $BasicFileAttributes*)},
	{"getChildren", "()Ljava/util/List;", "()Ljava/util/List<Ljdk/internal/jimage/ImageReader$Node;>;", $PUBLIC, $virtualMethod(ImageReader$Directory, getChildren, $List*)},
	{"isDirectory", "()Z", nullptr, $PUBLIC, $virtualMethod(ImageReader$Directory, isDirectory, bool)},
	{"walk", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<-Ljdk/internal/jimage/ImageReader$Node;>;)V", $PUBLIC, $method(ImageReader$Directory, walk, void, $Consumer*)},
	{}
};

$InnerClassInfo _ImageReader$Directory_InnerClassesInfo_[] = {
	{"jdk.internal.jimage.ImageReader$Directory", "jdk.internal.jimage.ImageReader", "Directory", $STATIC | $FINAL},
	{"jdk.internal.jimage.ImageReader$Node", "jdk.internal.jimage.ImageReader", "Node", $PUBLIC | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _ImageReader$Directory_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.jimage.ImageReader$Directory",
	"jdk.internal.jimage.ImageReader$Node",
	nullptr,
	_ImageReader$Directory_FieldInfo_,
	_ImageReader$Directory_MethodInfo_,
	nullptr,
	nullptr,
	_ImageReader$Directory_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.jimage.ImageReader"
};

$Object* allocate$ImageReader$Directory($Class* clazz) {
	return $of($alloc(ImageReader$Directory));
}

void ImageReader$Directory::init$($String* name, $BasicFileAttributes* fileAttrs) {
	$ImageReader$Node::init$(name, fileAttrs);
	$set(this, children, $new($ArrayList));
}

ImageReader$Directory* ImageReader$Directory::create(ImageReader$Directory* parent, $String* name, $BasicFileAttributes* fileAttrs) {
	$init(ImageReader$Directory);
	$var(ImageReader$Directory, d, $new(ImageReader$Directory, name, fileAttrs));
	if (parent != nullptr) {
		parent->addChild(d);
	}
	return d;
}

bool ImageReader$Directory::isDirectory() {
	return true;
}

$List* ImageReader$Directory::getChildren() {
	return $Collections::unmodifiableList(this->children);
}

void ImageReader$Directory::addChild($ImageReader$Node* node) {
	$nc(this->children)->add(node);
}

void ImageReader$Directory::walk($Consumer* consumer) {
	$useLocalCurrentObjectStackCache();
	$nc(consumer)->accept(this);
	{
		$var($Iterator, i$, $nc(this->children)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ImageReader$Node, child, $cast($ImageReader$Node, i$->next()));
			{
				if ($nc(child)->isDirectory()) {
					$nc(($cast(ImageReader$Directory, child)))->walk(consumer);
				} else {
					consumer->accept(child);
				}
			}
		}
	}
}

ImageReader$Directory::ImageReader$Directory() {
}

$Class* ImageReader$Directory::load$($String* name, bool initialize) {
	$loadClass(ImageReader$Directory, name, initialize, &_ImageReader$Directory_ClassInfo_, allocate$ImageReader$Directory);
	return class$;
}

$Class* ImageReader$Directory::class$ = nullptr;

		} // jimage
	} // internal
} // jdk