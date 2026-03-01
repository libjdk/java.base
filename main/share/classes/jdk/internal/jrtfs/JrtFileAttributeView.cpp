#include <jdk/internal/jrtfs/JrtFileAttributeView.h>

#include <java/lang/UnsupportedOperationException.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/attribute/BasicFileAttributeView.h>
#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/nio/file/attribute/FileAttributeView.h>
#include <java/nio/file/attribute/FileTime.h>
#include <java/util/LinkedHashMap.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <jdk/internal/jrtfs/JrtFileAttributeView$1.h>
#include <jdk/internal/jrtfs/JrtFileAttributeView$AttrID.h>
#include <jdk/internal/jrtfs/JrtFileAttributes.h>
#include <jdk/internal/jrtfs/JrtPath.h>
#include <jcpp.h>

using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $JrtFileAttributeView$AttrIDArray = $Array<::jdk::internal::jrtfs::JrtFileAttributeView$AttrID>;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $BasicFileAttributeView = ::java::nio::file::attribute::BasicFileAttributeView;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $FileAttributeView = ::java::nio::file::attribute::FileAttributeView;
using $FileTime = ::java::nio::file::attribute::FileTime;
using $LinkedHashMap = ::java::util::LinkedHashMap;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $JrtFileAttributeView$1 = ::jdk::internal::jrtfs::JrtFileAttributeView$1;
using $JrtFileAttributeView$AttrID = ::jdk::internal::jrtfs::JrtFileAttributeView$AttrID;
using $JrtFileAttributes = ::jdk::internal::jrtfs::JrtFileAttributes;
using $JrtPath = ::jdk::internal::jrtfs::JrtPath;

namespace jdk {
	namespace internal {
		namespace jrtfs {

$FieldInfo _JrtFileAttributeView_FieldInfo_[] = {
	{"path", "Ljdk/internal/jrtfs/JrtPath;", nullptr, $PRIVATE | $FINAL, $field(JrtFileAttributeView, path)},
	{"isJrtView", "Z", nullptr, $PRIVATE | $FINAL, $field(JrtFileAttributeView, isJrtView)},
	{"options", "[Ljava/nio/file/LinkOption;", nullptr, $PRIVATE | $FINAL, $field(JrtFileAttributeView, options)},
	{}
};

$MethodInfo _JrtFileAttributeView_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/jrtfs/JrtPath;Z[Ljava/nio/file/LinkOption;)V", nullptr, $PRIVATE | $TRANSIENT, $method(JrtFileAttributeView, init$, void, $JrtPath*, bool, $LinkOptionArray*)},
	{"attribute", "(Ljdk/internal/jrtfs/JrtFileAttributeView$AttrID;Ljdk/internal/jrtfs/JrtFileAttributes;Z)Ljava/lang/Object;", nullptr, $STATIC, $staticMethod(JrtFileAttributeView, attribute, $Object*, $JrtFileAttributeView$AttrID*, $JrtFileAttributes*, bool)},
	{"get", "(Ljdk/internal/jrtfs/JrtPath;Ljava/lang/Class;[Ljava/nio/file/LinkOption;)Ljava/nio/file/attribute/FileAttributeView;", "<V::Ljava/nio/file/attribute/FileAttributeView;>(Ljdk/internal/jrtfs/JrtPath;Ljava/lang/Class<TV;>;[Ljava/nio/file/LinkOption;)TV;", $STATIC | $TRANSIENT, $staticMethod(JrtFileAttributeView, get, $FileAttributeView*, $JrtPath*, $Class*, $LinkOptionArray*)},
	{"get", "(Ljdk/internal/jrtfs/JrtPath;Ljava/lang/String;[Ljava/nio/file/LinkOption;)Ljdk/internal/jrtfs/JrtFileAttributeView;", nullptr, $STATIC | $TRANSIENT, $staticMethod(JrtFileAttributeView, get, JrtFileAttributeView*, $JrtPath*, $String*, $LinkOptionArray*)},
	{"name", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(JrtFileAttributeView, name, $String*)},
	{"readAttributes", "()Ljdk/internal/jrtfs/JrtFileAttributes;", nullptr, $PUBLIC, $virtualMethod(JrtFileAttributeView, readAttributes, $BasicFileAttributes*), "java.io.IOException"},
	{"readAttributes", "(Ljdk/internal/jrtfs/JrtPath;Ljava/lang/String;[Ljava/nio/file/LinkOption;)Ljava/util/Map;", "(Ljdk/internal/jrtfs/JrtPath;Ljava/lang/String;[Ljava/nio/file/LinkOption;)Ljava/util/Map<Ljava/lang/String;Ljava/lang/Object;>;", $STATIC | $TRANSIENT, $staticMethod(JrtFileAttributeView, readAttributes, $Map*, $JrtPath*, $String*, $LinkOptionArray*), "java.io.IOException"},
	{"setAttribute", "(Ljdk/internal/jrtfs/JrtPath;Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $STATIC, $staticMethod(JrtFileAttributeView, setAttribute, void, $JrtPath*, $String*, Object$*), "java.io.IOException"},
	{"setTimes", "(Ljava/nio/file/attribute/FileTime;Ljava/nio/file/attribute/FileTime;Ljava/nio/file/attribute/FileTime;)V", nullptr, $PUBLIC, $virtualMethod(JrtFileAttributeView, setTimes, void, $FileTime*, $FileTime*, $FileTime*), "java.io.IOException"},
	{}
};

$InnerClassInfo _JrtFileAttributeView_InnerClassesInfo_[] = {
	{"jdk.internal.jrtfs.JrtFileAttributeView$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"jdk.internal.jrtfs.JrtFileAttributeView$AttrID", "jdk.internal.jrtfs.JrtFileAttributeView", "AttrID", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _JrtFileAttributeView_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.jrtfs.JrtFileAttributeView",
	"java.lang.Object",
	"java.nio.file.attribute.BasicFileAttributeView",
	_JrtFileAttributeView_FieldInfo_,
	_JrtFileAttributeView_MethodInfo_,
	nullptr,
	nullptr,
	_JrtFileAttributeView_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.jrtfs.JrtFileAttributeView$1,jdk.internal.jrtfs.JrtFileAttributeView$AttrID"
};

$Object* allocate$JrtFileAttributeView($Class* clazz) {
	return $of($alloc(JrtFileAttributeView));
}

void JrtFileAttributeView::init$($JrtPath* path, bool isJrtView, $LinkOptionArray* options) {
	$set(this, path, path);
	this->isJrtView = isJrtView;
	$set(this, options, options);
}

$FileAttributeView* JrtFileAttributeView::get($JrtPath* path, $Class* type, $LinkOptionArray* options) {
	$init(JrtFileAttributeView);
	$Objects::requireNonNull(type);
	$load($BasicFileAttributeView);
	if (type == $BasicFileAttributeView::class$) {
		return static_cast<$FileAttributeView*>($new(JrtFileAttributeView, path, false, options));
	}
	if (type == JrtFileAttributeView::class$) {
		return static_cast<$FileAttributeView*>($new(JrtFileAttributeView, path, true, options));
	}
	return nullptr;
}

JrtFileAttributeView* JrtFileAttributeView::get($JrtPath* path, $String* type, $LinkOptionArray* options) {
	$init(JrtFileAttributeView);
	$Objects::requireNonNull(type);
	if (type->equals("basic"_s)) {
		return $new(JrtFileAttributeView, path, false, options);
	}
	if (type->equals("jrt"_s)) {
		return $new(JrtFileAttributeView, path, true, options);
	}
	return nullptr;
}

$String* JrtFileAttributeView::name() {
	return this->isJrtView ? "jrt"_s : "basic"_s;
}

$BasicFileAttributes* JrtFileAttributeView::readAttributes() {
	return $nc(this->path)->getAttributes(this->options);
}

void JrtFileAttributeView::setTimes($FileTime* lastModifiedTime, $FileTime* lastAccessTime, $FileTime* createTime) {
	$nc(this->path)->setTimes(lastModifiedTime, lastAccessTime, createTime);
}

void JrtFileAttributeView::setAttribute($JrtPath* path, $String* attribute$renamed, Object$* value) {
	$init(JrtFileAttributeView);
	$useLocalCurrentObjectStackCache();
	$var($String, attribute, attribute$renamed);
	int32_t colonPos = $nc(attribute)->indexOf((int32_t)u':');
	if (colonPos != -1) {
		$var($String, type, attribute->substring(0, colonPos++));
		bool var$0 = !type->equals("basic"_s);
		if (var$0 && !type->equals("jrt"_s)) {
			$throwNew($UnsupportedOperationException, $$str({"view <"_s, type, "> is not supported"_s}));
		}
		$assign(attribute, attribute->substring(colonPos));
	}
	try {
		$JrtFileAttributeView$AttrID* id = $JrtFileAttributeView$AttrID::valueOf(attribute);
		if (id == $JrtFileAttributeView$AttrID::lastModifiedTime) {
			$nc(path)->setTimes($cast($FileTime, value), nullptr, nullptr);
		} else {
			if (id == $JrtFileAttributeView$AttrID::lastAccessTime) {
				$nc(path)->setTimes(nullptr, $cast($FileTime, value), nullptr);
			} else {
				if (id == $JrtFileAttributeView$AttrID::creationTime) {
					$nc(path)->setTimes(nullptr, nullptr, $cast($FileTime, value));
				}
			}
		}
		return;
	} catch ($IllegalArgumentException& x) {
	}
	$throwNew($UnsupportedOperationException, $$str({"\'"_s, attribute, "\' is unknown or read-only attribute"_s}));
}

$Map* JrtFileAttributeView::readAttributes($JrtPath* path, $String* attributes$renamed, $LinkOptionArray* options) {
	$init(JrtFileAttributeView);
	$useLocalCurrentObjectStackCache();
	$var($String, attributes, attributes$renamed);
	int32_t colonPos = $nc(attributes)->indexOf((int32_t)u':');
	bool isJrtView = false;
	if (colonPos != -1) {
		$var($String, type, attributes->substring(0, colonPos++));
		bool var$0 = !type->equals("basic"_s);
		if (var$0 && !type->equals("jrt"_s)) {
			$throwNew($UnsupportedOperationException, $$str({"view <"_s, type, "> is not supported"_s}));
		}
		isJrtView = true;
		$assign(attributes, attributes->substring(colonPos));
	}
	$var($JrtFileAttributes, jrtfas, $nc(path)->getAttributes($$new($LinkOptionArray, 0)));
	$var($LinkedHashMap, map, $new($LinkedHashMap));
	if ("*"_s->equals(attributes)) {
		{
			$var($JrtFileAttributeView$AttrIDArray, arr$, $JrtFileAttributeView$AttrID::values());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$JrtFileAttributeView$AttrID* id = arr$->get(i$);
				{
					$var($Object, var$1, $of($nc(id)->name()));
					map->put(var$1, $(attribute(id, jrtfas, isJrtView)));
				}
			}
		}
	} else {
		$var($StringArray, as, attributes->split(","_s));
		{
			$var($StringArray, arr$, as);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, a, arr$->get(i$));
				{
					map->put(a, $(attribute($($JrtFileAttributeView$AttrID::valueOf(a)), jrtfas, isJrtView)));
				}
			}
		}
	}
	return map;
}

$Object* JrtFileAttributeView::attribute($JrtFileAttributeView$AttrID* id, $JrtFileAttributes* jrtfas, bool isJrtView) {
	$init(JrtFileAttributeView);
	$init($JrtFileAttributeView$1);
	switch ($nc($JrtFileAttributeView$1::$SwitchMap$jdk$internal$jrtfs$JrtFileAttributeView$AttrID)->get($nc((id))->ordinal())) {
	case 1:
		{
			return $of($Long::valueOf($nc(jrtfas)->size()));
		}
	case 2:
		{
			return $of($nc(jrtfas)->creationTime());
		}
	case 3:
		{
			return $of($nc(jrtfas)->lastAccessTime());
		}
	case 4:
		{
			return $of($nc(jrtfas)->lastModifiedTime());
		}
	case 5:
		{
			return $of($Boolean::valueOf($nc(jrtfas)->isDirectory()));
		}
	case 6:
		{
			return $of($Boolean::valueOf($nc(jrtfas)->isRegularFile()));
		}
	case 7:
		{
			return $of($Boolean::valueOf($nc(jrtfas)->isSymbolicLink()));
		}
	case 8:
		{
			return $of($Boolean::valueOf($nc(jrtfas)->isOther()));
		}
	case 9:
		{
			return $of($nc(jrtfas)->fileKey());
		}
	case 10:
		{
			if (isJrtView) {
				return $of($Long::valueOf($nc(jrtfas)->compressedSize()));
			}
			break;
		}
	case 11:
		{
			if (isJrtView) {
				return $of($nc(jrtfas)->extension());
			}
			break;
		}
	}
	return $of(nullptr);
}

JrtFileAttributeView::JrtFileAttributeView() {
}

$Class* JrtFileAttributeView::load$($String* name, bool initialize) {
	$loadClass(JrtFileAttributeView, name, initialize, &_JrtFileAttributeView_ClassInfo_, allocate$JrtFileAttributeView);
	return class$;
}

$Class* JrtFileAttributeView::class$ = nullptr;

		} // jrtfs
	} // internal
} // jdk