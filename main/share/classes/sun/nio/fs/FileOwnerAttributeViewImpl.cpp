#include <sun/nio/fs/FileOwnerAttributeViewImpl.h>

#include <java/nio/file/attribute/AclFileAttributeView.h>
#include <java/nio/file/attribute/BasicFileAttributeView.h>
#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/nio/file/attribute/FileAttributeView.h>
#include <java/nio/file/attribute/FileOwnerAttributeView.h>
#include <java/nio/file/attribute/PosixFileAttributeView.h>
#include <java/nio/file/attribute/PosixFileAttributes.h>
#include <java/nio/file/attribute/UserPrincipal.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <jcpp.h>

#undef OWNER_NAME

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $AclFileAttributeView = ::java::nio::file::attribute::AclFileAttributeView;
using $BasicFileAttributeView = ::java::nio::file::attribute::BasicFileAttributeView;
using $FileAttributeView = ::java::nio::file::attribute::FileAttributeView;
using $FileOwnerAttributeView = ::java::nio::file::attribute::FileOwnerAttributeView;
using $PosixFileAttributeView = ::java::nio::file::attribute::PosixFileAttributeView;
using $PosixFileAttributes = ::java::nio::file::attribute::PosixFileAttributes;
using $UserPrincipal = ::java::nio::file::attribute::UserPrincipal;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _FileOwnerAttributeViewImpl_FieldInfo_[] = {
	{"OWNER_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(FileOwnerAttributeViewImpl, OWNER_NAME)},
	{"view", "Ljava/nio/file/attribute/FileAttributeView;", nullptr, $PRIVATE | $FINAL, $field(FileOwnerAttributeViewImpl, view)},
	{"isPosixView", "Z", nullptr, $PRIVATE | $FINAL, $field(FileOwnerAttributeViewImpl, isPosixView)},
	{}
};

$MethodInfo _FileOwnerAttributeViewImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/nio/file/attribute/PosixFileAttributeView;)V", nullptr, 0, $method(FileOwnerAttributeViewImpl, init$, void, $PosixFileAttributeView*)},
	{"<init>", "(Ljava/nio/file/attribute/AclFileAttributeView;)V", nullptr, 0, $method(FileOwnerAttributeViewImpl, init$, void, $AclFileAttributeView*)},
	{"getOwner", "()Ljava/nio/file/attribute/UserPrincipal;", nullptr, $PUBLIC, $virtualMethod(FileOwnerAttributeViewImpl, getOwner, $UserPrincipal*), "java.io.IOException"},
	{"name", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(FileOwnerAttributeViewImpl, name, $String*)},
	{"readAttributes", "([Ljava/lang/String;)Ljava/util/Map;", "([Ljava/lang/String;)Ljava/util/Map<Ljava/lang/String;Ljava/lang/Object;>;", $PUBLIC, $virtualMethod(FileOwnerAttributeViewImpl, readAttributes, $Map*, $StringArray*), "java.io.IOException"},
	{"setAttribute", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(FileOwnerAttributeViewImpl, setAttribute, void, $String*, Object$*), "java.io.IOException"},
	{"setOwner", "(Ljava/nio/file/attribute/UserPrincipal;)V", nullptr, $PUBLIC, $virtualMethod(FileOwnerAttributeViewImpl, setOwner, void, $UserPrincipal*), "java.io.IOException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _FileOwnerAttributeViewImpl_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.nio.fs.FileOwnerAttributeViewImpl",
	"java.lang.Object",
	"java.nio.file.attribute.FileOwnerAttributeView,sun.nio.fs.DynamicFileAttributeView",
	_FileOwnerAttributeViewImpl_FieldInfo_,
	_FileOwnerAttributeViewImpl_MethodInfo_
};

$Object* allocate$FileOwnerAttributeViewImpl($Class* clazz) {
	return $of($alloc(FileOwnerAttributeViewImpl));
}

int32_t FileOwnerAttributeViewImpl::hashCode() {
	 return this->$FileOwnerAttributeView::hashCode();
}

bool FileOwnerAttributeViewImpl::equals(Object$* obj) {
	 return this->$FileOwnerAttributeView::equals(obj);
}

$Object* FileOwnerAttributeViewImpl::clone() {
	 return this->$FileOwnerAttributeView::clone();
}

$String* FileOwnerAttributeViewImpl::toString() {
	 return this->$FileOwnerAttributeView::toString();
}

void FileOwnerAttributeViewImpl::finalize() {
	this->$FileOwnerAttributeView::finalize();
}

$String* FileOwnerAttributeViewImpl::OWNER_NAME = nullptr;

void FileOwnerAttributeViewImpl::init$($PosixFileAttributeView* view) {
	$set(this, view, static_cast<$FileAttributeView*>(static_cast<$BasicFileAttributeView*>(view)));
	this->isPosixView = true;
}

void FileOwnerAttributeViewImpl::init$($AclFileAttributeView* view) {
	$set(this, view, view);
	this->isPosixView = false;
}

$String* FileOwnerAttributeViewImpl::name() {
	return "owner"_s;
}

void FileOwnerAttributeViewImpl::setAttribute($String* attribute, Object$* value) {
	$useLocalCurrentObjectStackCache();
	if ($nc(attribute)->equals(FileOwnerAttributeViewImpl::OWNER_NAME)) {
		setOwner($cast($UserPrincipal, value));
	} else {
		$throwNew($IllegalArgumentException, $$str({"\'"_s, $(name()), ":"_s, attribute, "\' not recognized"_s}));
	}
}

$Map* FileOwnerAttributeViewImpl::readAttributes($StringArray* attributes) {
	$useLocalCurrentObjectStackCache();
	$var($Map, result, $new($HashMap));
	{
		$var($StringArray, arr$, attributes);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, attribute, arr$->get(i$));
			{
				bool var$0 = $nc(attribute)->equals("*"_s);
				if (var$0 || $nc(attribute)->equals(FileOwnerAttributeViewImpl::OWNER_NAME)) {
					result->put(FileOwnerAttributeViewImpl::OWNER_NAME, $(getOwner()));
				} else {
					$throwNew($IllegalArgumentException, $$str({"\'"_s, $(name()), ":"_s, attribute, "\' not recognized"_s}));
				}
			}
		}
	}
	return result;
}

$UserPrincipal* FileOwnerAttributeViewImpl::getOwner() {
	if (this->isPosixView) {
		return $nc($($cast($PosixFileAttributes, $nc(($cast($PosixFileAttributeView, this->view)))->readAttributes())))->owner();
	} else {
		return $nc(($cast($AclFileAttributeView, this->view)))->getOwner();
	}
}

void FileOwnerAttributeViewImpl::setOwner($UserPrincipal* owner) {
	if (this->isPosixView) {
		$nc(($cast($PosixFileAttributeView, this->view)))->setOwner(owner);
	} else {
		$nc(($cast($AclFileAttributeView, this->view)))->setOwner(owner);
	}
}

FileOwnerAttributeViewImpl::FileOwnerAttributeViewImpl() {
}

void clinit$FileOwnerAttributeViewImpl($Class* class$) {
	$assignStatic(FileOwnerAttributeViewImpl::OWNER_NAME, "owner"_s);
}

$Class* FileOwnerAttributeViewImpl::load$($String* name, bool initialize) {
	$loadClass(FileOwnerAttributeViewImpl, name, initialize, &_FileOwnerAttributeViewImpl_ClassInfo_, clinit$FileOwnerAttributeViewImpl, allocate$FileOwnerAttributeViewImpl);
	return class$;
}

$Class* FileOwnerAttributeViewImpl::class$ = nullptr;

		} // fs
	} // nio
} // sun