#include <jdk/internal/jrtfs/ExplodedImage$PathNode.h>

#include <java/io/IOException.h>
#include <java/io/UncheckedIOException.h>
#include <java/nio/file/DirectoryStream.h>
#include <java/nio/file/FileSystemException.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jdk/internal/jimage/ImageReader$Node.h>
#include <jdk/internal/jrtfs/ExplodedImage.h>
#include <jdk/internal/jrtfs/SystemImage.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $DirectoryStream = ::java::nio::file::DirectoryStream;
using $FileSystemException = ::java::nio::file::FileSystemException;
using $Files = ::java::nio::file::Files;
using $Path = ::java::nio::file::Path;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $ImageReader$Node = ::jdk::internal::jimage::ImageReader$Node;
using $ExplodedImage = ::jdk::internal::jrtfs::ExplodedImage;
using $SystemImage = ::jdk::internal::jrtfs::SystemImage;

namespace jdk {
	namespace internal {
		namespace jrtfs {

$FieldInfo _ExplodedImage$PathNode_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/jrtfs/ExplodedImage;", nullptr, $FINAL | $SYNTHETIC, $field(ExplodedImage$PathNode, this$0)},
	{"path", "Ljava/nio/file/Path;", nullptr, $PRIVATE, $field(ExplodedImage$PathNode, path)},
	{"link", "Ljdk/internal/jrtfs/ExplodedImage$PathNode;", nullptr, $PRIVATE, $field(ExplodedImage$PathNode, link)},
	{"children", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/jimage/ImageReader$Node;>;", $PRIVATE, $field(ExplodedImage$PathNode, children)},
	{}
};

$MethodInfo _ExplodedImage$PathNode_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/jrtfs/ExplodedImage;Ljava/lang/String;Ljava/nio/file/Path;Ljava/nio/file/attribute/BasicFileAttributes;)V", nullptr, 0, $method(ExplodedImage$PathNode, init$, void, $ExplodedImage*, $String*, $Path*, $BasicFileAttributes*)},
	{"<init>", "(Ljdk/internal/jrtfs/ExplodedImage;Ljava/lang/String;Ljdk/internal/jimage/ImageReader$Node;)V", nullptr, 0, $method(ExplodedImage$PathNode, init$, void, $ExplodedImage*, $String*, $ImageReader$Node*)},
	{"<init>", "(Ljdk/internal/jrtfs/ExplodedImage;Ljava/lang/String;Ljava/util/List;)V", "(Ljava/lang/String;Ljava/util/List<Ljdk/internal/jimage/ImageReader$Node;>;)V", 0, $method(ExplodedImage$PathNode, init$, void, $ExplodedImage*, $String*, $List*)},
	{"getChildren", "()Ljava/util/List;", "()Ljava/util/List<Ljdk/internal/jimage/ImageReader$Node;>;", $PUBLIC, $virtualMethod(ExplodedImage$PathNode, getChildren, $List*)},
	{"getContent", "()[B", nullptr, 0, $method(ExplodedImage$PathNode, getContent, $bytes*), "java.io.IOException"},
	{"isDirectory", "()Z", nullptr, $PUBLIC, $virtualMethod(ExplodedImage$PathNode, isDirectory, bool)},
	{"isLink", "()Z", nullptr, $PUBLIC, $virtualMethod(ExplodedImage$PathNode, isLink, bool)},
	{"resolveLink", "(Z)Ljdk/internal/jrtfs/ExplodedImage$PathNode;", nullptr, $PUBLIC, $virtualMethod(ExplodedImage$PathNode, resolveLink, ExplodedImage$PathNode*, bool)},
	{"size", "()J", nullptr, $PUBLIC, $virtualMethod(ExplodedImage$PathNode, size, int64_t)},
	{}
};

$InnerClassInfo _ExplodedImage$PathNode_InnerClassesInfo_[] = {
	{"jdk.internal.jrtfs.ExplodedImage$PathNode", "jdk.internal.jrtfs.ExplodedImage", "PathNode", $PRIVATE | $FINAL},
	{"jdk.internal.jimage.ImageReader$Node", "jdk.internal.jimage.ImageReader", "Node", $PUBLIC | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _ExplodedImage$PathNode_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.jrtfs.ExplodedImage$PathNode",
	"jdk.internal.jimage.ImageReader$Node",
	nullptr,
	_ExplodedImage$PathNode_FieldInfo_,
	_ExplodedImage$PathNode_MethodInfo_,
	nullptr,
	nullptr,
	_ExplodedImage$PathNode_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.jrtfs.ExplodedImage"
};

$Object* allocate$ExplodedImage$PathNode($Class* clazz) {
	return $of($alloc(ExplodedImage$PathNode));
}

void ExplodedImage$PathNode::init$($ExplodedImage* this$0, $String* name, $Path* path, $BasicFileAttributes* attrs) {
	$set(this, this$0, this$0);
	$ImageReader$Node::init$(name, attrs);
	$set(this, path, path);
}

void ExplodedImage$PathNode::init$($ExplodedImage* this$0, $String* name, $ImageReader$Node* link) {
	$set(this, this$0, this$0);
	$ImageReader$Node::init$(name, $($nc(link)->getFileAttributes()));
	$set(this, link, $cast(ExplodedImage$PathNode, link));
}

void ExplodedImage$PathNode::init$($ExplodedImage* this$0, $String* name, $List* children) {
	$set(this, this$0, this$0);
	$ImageReader$Node::init$(name, this$0->modulesDirAttrs);
	$set(this, children, children);
}

bool ExplodedImage$PathNode::isDirectory() {
	return this->children != nullptr || (this->link == nullptr && $nc($(getFileAttributes()))->isDirectory());
}

bool ExplodedImage$PathNode::isLink() {
	return this->link != nullptr;
}

ExplodedImage$PathNode* ExplodedImage$PathNode::resolveLink(bool recursive) {
	if (this->link == nullptr) {
		return this;
	}
	return recursive && $nc(this->link)->isLink() ? $nc(this->link)->resolveLink(true) : this->link;
}

$bytes* ExplodedImage$PathNode::getContent() {
	$useLocalCurrentObjectStackCache();
	if (!$nc($(getFileAttributes()))->isRegularFile()) {
		$throwNew($FileSystemException, $$str({$(getName()), " is not file"_s}));
	}
	return $Files::readAllBytes(this->path);
}

$List* ExplodedImage$PathNode::getChildren() {
	$useLocalCurrentObjectStackCache();
	if (!isDirectory()) {
		$throwNew($IllegalArgumentException, $$str({"not a directory: "_s, $(getNameString())}));
	}
	if (this->children == nullptr) {
		$var($List, list, $new($ArrayList));
		try {
			$var($DirectoryStream, stream, $Files::newDirectoryStream(this->path));
			{
				$var($Throwable, var$0, nullptr);
				try {
					try {
						{
							$var($Iterator, i$, $nc(stream)->iterator());
							for (; $nc(i$)->hasNext();) {
								$var($Path, p, $cast($Path, i$->next()));
								{
									$init($SystemImage);
									$assign(p, $nc($SystemImage::explodedModulesDir)->relativize(p));
									$var($String, pName, $str({"/modules/"_s, $(this->this$0->nativeSlashToFrontSlash($($nc(p)->toString())))}));
									$var($ImageReader$Node, node, this->this$0->findNode(pName));
									if (node != nullptr) {
										list->add(node);
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
		} catch ($IOException& x) {
			return nullptr;
		}
		$set(this, children, list);
	}
	return this->children;
}

int64_t ExplodedImage$PathNode::size() {
	try {
		return isDirectory() ? (int64_t)0 : $Files::size(this->path);
	} catch ($IOException& ex) {
		$throwNew($UncheckedIOException, ex);
	}
	$shouldNotReachHere();
}

ExplodedImage$PathNode::ExplodedImage$PathNode() {
}

$Class* ExplodedImage$PathNode::load$($String* name, bool initialize) {
	$loadClass(ExplodedImage$PathNode, name, initialize, &_ExplodedImage$PathNode_ClassInfo_, allocate$ExplodedImage$PathNode);
	return class$;
}

$Class* ExplodedImage$PathNode::class$ = nullptr;

		} // jrtfs
	} // internal
} // jdk