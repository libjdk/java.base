#include <sun/nio/fs/WindowsFileAttributeViews$Dos.h>

#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/nio/file/attribute/FileTime.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <sun/nio/fs/AbstractBasicFileAttributeView$AttributesBuilder.h>
#include <sun/nio/fs/AbstractBasicFileAttributeView.h>
#include <sun/nio/fs/Util.h>
#include <sun/nio/fs/WindowsException.h>
#include <sun/nio/fs/WindowsFileAttributeViews$Basic.h>
#include <sun/nio/fs/WindowsFileAttributeViews.h>
#include <sun/nio/fs/WindowsFileAttributes.h>
#include <sun/nio/fs/WindowsLinkSupport.h>
#include <sun/nio/fs/WindowsNativeDispatcher.h>
#include <sun/nio/fs/WindowsPath.h>
#include <jcpp.h>

#undef ARCHIVE_NAME
#undef ATTRIBUTES_NAME
#undef HIDDEN_NAME
#undef READONLY_NAME
#undef SYSTEM_NAME

using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $FileTime = ::java::nio::file::attribute::FileTime;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $AbstractBasicFileAttributeView = ::sun::nio::fs::AbstractBasicFileAttributeView;
using $AbstractBasicFileAttributeView$AttributesBuilder = ::sun::nio::fs::AbstractBasicFileAttributeView$AttributesBuilder;
using $Util = ::sun::nio::fs::Util;
using $WindowsException = ::sun::nio::fs::WindowsException;
using $WindowsFileAttributeViews$Basic = ::sun::nio::fs::WindowsFileAttributeViews$Basic;
using $WindowsFileAttributes = ::sun::nio::fs::WindowsFileAttributes;
using $WindowsLinkSupport = ::sun::nio::fs::WindowsLinkSupport;
using $WindowsNativeDispatcher = ::sun::nio::fs::WindowsNativeDispatcher;
using $WindowsPath = ::sun::nio::fs::WindowsPath;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _WindowsFileAttributeViews$Dos_FieldInfo_[] = {
	{"READONLY_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WindowsFileAttributeViews$Dos, READONLY_NAME)},
	{"ARCHIVE_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WindowsFileAttributeViews$Dos, ARCHIVE_NAME)},
	{"SYSTEM_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WindowsFileAttributeViews$Dos, SYSTEM_NAME)},
	{"HIDDEN_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WindowsFileAttributeViews$Dos, HIDDEN_NAME)},
	{"ATTRIBUTES_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WindowsFileAttributeViews$Dos, ATTRIBUTES_NAME)},
	{"dosAttributeNames", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $STATIC | $FINAL, $staticField(WindowsFileAttributeViews$Dos, dosAttributeNames)},
	{}
};

$MethodInfo _WindowsFileAttributeViews$Dos_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lsun/nio/fs/WindowsPath;Z)V", nullptr, 0, $method(WindowsFileAttributeViews$Dos, init$, void, $WindowsPath*, bool)},
	{"name", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(WindowsFileAttributeViews$Dos, name, $String*)},
	{"readAttributes", "([Ljava/lang/String;)Ljava/util/Map;", "([Ljava/lang/String;)Ljava/util/Map<Ljava/lang/String;Ljava/lang/Object;>;", $PUBLIC, $virtualMethod(WindowsFileAttributeViews$Dos, readAttributes, $Map*, $StringArray*), "java.io.IOException"},
	{"readAttributes", "()Ljava/nio/file/attribute/DosFileAttributes;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(WindowsFileAttributeViews$Dos, readAttributes, $BasicFileAttributes*), "java.io.IOException"},
	{"setArchive", "(Z)V", nullptr, $PUBLIC, $virtualMethod(WindowsFileAttributeViews$Dos, setArchive, void, bool), "java.io.IOException"},
	{"setAttribute", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(WindowsFileAttributeViews$Dos, setAttribute, void, $String*, Object$*), "java.io.IOException"},
	{"setAttributes", "(Lsun/nio/fs/WindowsFileAttributes;)V", nullptr, 0, $virtualMethod(WindowsFileAttributeViews$Dos, setAttributes, void, $WindowsFileAttributes*), "java.io.IOException"},
	{"setHidden", "(Z)V", nullptr, $PUBLIC, $virtualMethod(WindowsFileAttributeViews$Dos, setHidden, void, bool), "java.io.IOException"},
	{"setReadOnly", "(Z)V", nullptr, $PUBLIC, $virtualMethod(WindowsFileAttributeViews$Dos, setReadOnly, void, bool), "java.io.IOException"},
	{"setSystem", "(Z)V", nullptr, $PUBLIC, $virtualMethod(WindowsFileAttributeViews$Dos, setSystem, void, bool), "java.io.IOException"},
	{"*setTimes", "(Ljava/nio/file/attribute/FileTime;Ljava/nio/file/attribute/FileTime;Ljava/nio/file/attribute/FileTime;)V", nullptr, $PUBLIC},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"updateAttributes", "(IZ)V", nullptr, $PRIVATE, $method(WindowsFileAttributeViews$Dos, updateAttributes, void, int32_t, bool), "java.io.IOException"},
	{}
};

$InnerClassInfo _WindowsFileAttributeViews$Dos_InnerClassesInfo_[] = {
	{"sun.nio.fs.WindowsFileAttributeViews$Dos", "sun.nio.fs.WindowsFileAttributeViews", "Dos", $STATIC},
	{"sun.nio.fs.WindowsFileAttributeViews$Basic", "sun.nio.fs.WindowsFileAttributeViews", "Basic", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _WindowsFileAttributeViews$Dos_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.WindowsFileAttributeViews$Dos",
	"sun.nio.fs.WindowsFileAttributeViews$Basic",
	"java.nio.file.attribute.DosFileAttributeView",
	_WindowsFileAttributeViews$Dos_FieldInfo_,
	_WindowsFileAttributeViews$Dos_MethodInfo_,
	nullptr,
	nullptr,
	_WindowsFileAttributeViews$Dos_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.fs.WindowsFileAttributeViews"
};

$Object* allocate$WindowsFileAttributeViews$Dos($Class* clazz) {
	return $of($alloc(WindowsFileAttributeViews$Dos));
}

void WindowsFileAttributeViews$Dos::setTimes($FileTime* lastModifiedTime, $FileTime* lastAccessTime, $FileTime* createTime) {
	this->$WindowsFileAttributeViews$Basic::setTimes(lastModifiedTime, lastAccessTime, createTime);
}

int32_t WindowsFileAttributeViews$Dos::hashCode() {
	 return this->$WindowsFileAttributeViews$Basic::hashCode();
}

bool WindowsFileAttributeViews$Dos::equals(Object$* obj) {
	 return this->$WindowsFileAttributeViews$Basic::equals(obj);
}

$Object* WindowsFileAttributeViews$Dos::clone() {
	 return this->$WindowsFileAttributeViews$Basic::clone();
}

$String* WindowsFileAttributeViews$Dos::toString() {
	 return this->$WindowsFileAttributeViews$Basic::toString();
}

void WindowsFileAttributeViews$Dos::finalize() {
	this->$WindowsFileAttributeViews$Basic::finalize();
}

$String* WindowsFileAttributeViews$Dos::READONLY_NAME = nullptr;
$String* WindowsFileAttributeViews$Dos::ARCHIVE_NAME = nullptr;
$String* WindowsFileAttributeViews$Dos::SYSTEM_NAME = nullptr;
$String* WindowsFileAttributeViews$Dos::HIDDEN_NAME = nullptr;
$String* WindowsFileAttributeViews$Dos::ATTRIBUTES_NAME = nullptr;
$Set* WindowsFileAttributeViews$Dos::dosAttributeNames = nullptr;

void WindowsFileAttributeViews$Dos::init$($WindowsPath* file, bool followLinks) {
	$WindowsFileAttributeViews$Basic::init$(file, followLinks);
}

$String* WindowsFileAttributeViews$Dos::name() {
	return "dos"_s;
}

void WindowsFileAttributeViews$Dos::setAttribute($String* attribute, Object$* value) {
	if ($nc(attribute)->equals(WindowsFileAttributeViews$Dos::READONLY_NAME)) {
		setReadOnly($nc(($cast($Boolean, value)))->booleanValue());
		return;
	}
	if ($nc(attribute)->equals(WindowsFileAttributeViews$Dos::ARCHIVE_NAME)) {
		setArchive($nc(($cast($Boolean, value)))->booleanValue());
		return;
	}
	if ($nc(attribute)->equals(WindowsFileAttributeViews$Dos::SYSTEM_NAME)) {
		setSystem($nc(($cast($Boolean, value)))->booleanValue());
		return;
	}
	if ($nc(attribute)->equals(WindowsFileAttributeViews$Dos::HIDDEN_NAME)) {
		setHidden($nc(($cast($Boolean, value)))->booleanValue());
		return;
	}
	$WindowsFileAttributeViews$Basic::setAttribute(attribute, value);
}

$Map* WindowsFileAttributeViews$Dos::readAttributes($StringArray* attributes) {
	$useLocalCurrentObjectStackCache();
	$var($AbstractBasicFileAttributeView$AttributesBuilder, builder, $AbstractBasicFileAttributeView$AttributesBuilder::create(WindowsFileAttributeViews$Dos::dosAttributeNames, attributes));
	$var($WindowsFileAttributes, attrs, $cast($WindowsFileAttributes, readAttributes()));
	addRequestedBasicAttributes(attrs, builder);
	if ($nc(builder)->match(WindowsFileAttributeViews$Dos::READONLY_NAME)) {
		builder->add(WindowsFileAttributeViews$Dos::READONLY_NAME, $($Boolean::valueOf($nc(attrs)->isReadOnly())));
	}
	if ($nc(builder)->match(WindowsFileAttributeViews$Dos::ARCHIVE_NAME)) {
		builder->add(WindowsFileAttributeViews$Dos::ARCHIVE_NAME, $($Boolean::valueOf($nc(attrs)->isArchive())));
	}
	if ($nc(builder)->match(WindowsFileAttributeViews$Dos::SYSTEM_NAME)) {
		builder->add(WindowsFileAttributeViews$Dos::SYSTEM_NAME, $($Boolean::valueOf($nc(attrs)->isSystem())));
	}
	if ($nc(builder)->match(WindowsFileAttributeViews$Dos::HIDDEN_NAME)) {
		builder->add(WindowsFileAttributeViews$Dos::HIDDEN_NAME, $($Boolean::valueOf($nc(attrs)->isHidden())));
	}
	if ($nc(builder)->match(WindowsFileAttributeViews$Dos::ATTRIBUTES_NAME)) {
		builder->add(WindowsFileAttributeViews$Dos::ATTRIBUTES_NAME, $($Integer::valueOf($nc(attrs)->attributes())));
	}
	return $nc(builder)->unmodifiableMap();
}

void WindowsFileAttributeViews$Dos::updateAttributes(int32_t flag, bool enable) {
	$nc(this->file)->checkWrite();
	$var($String, path, $WindowsLinkSupport::getFinalPath(this->file, this->followLinks));
	try {
		int32_t oldValue = $WindowsNativeDispatcher::GetFileAttributes(path);
		int32_t newValue = oldValue;
		if (enable) {
			newValue |= flag;
		} else {
			newValue &= (uint32_t)~flag;
		}
		if (newValue != oldValue) {
			$WindowsNativeDispatcher::SetFileAttributes(path, newValue);
		}
	} catch ($WindowsException& x) {
		x->rethrowAsIOException(this->file);
	}
}

void WindowsFileAttributeViews$Dos::setReadOnly(bool value) {
	updateAttributes(1, value);
}

void WindowsFileAttributeViews$Dos::setHidden(bool value) {
	updateAttributes(2, value);
}

void WindowsFileAttributeViews$Dos::setArchive(bool value) {
	updateAttributes(32, value);
}

void WindowsFileAttributeViews$Dos::setSystem(bool value) {
	updateAttributes(4, value);
}

void WindowsFileAttributeViews$Dos::setAttributes($WindowsFileAttributes* attrs) {
	$useLocalCurrentObjectStackCache();
	int32_t flags = 0;
	if ($nc(attrs)->isReadOnly()) {
		flags |= 1;
	}
	if ($nc(attrs)->isHidden()) {
		flags |= 2;
	}
	if ($nc(attrs)->isArchive()) {
		flags |= 32;
	}
	if ($nc(attrs)->isSystem()) {
		flags |= 4;
	}
	updateAttributes(flags, true);
	int64_t var$0 = $WindowsFileAttributes::toWindowsTime($($nc(attrs)->creationTime()));
	int64_t var$1 = $WindowsFileAttributes::toWindowsTime($($nc(attrs)->lastModifiedTime()));
	setFileTimes(var$0, var$1, $WindowsFileAttributes::toWindowsTime($($nc(attrs)->lastAccessTime())));
}

$BasicFileAttributes* WindowsFileAttributeViews$Dos::readAttributes() {
	return $WindowsFileAttributeViews$Basic::readAttributes();
}

void clinit$WindowsFileAttributeViews$Dos($Class* class$) {
	$assignStatic(WindowsFileAttributeViews$Dos::READONLY_NAME, "readonly"_s);
	$assignStatic(WindowsFileAttributeViews$Dos::ARCHIVE_NAME, "archive"_s);
	$assignStatic(WindowsFileAttributeViews$Dos::SYSTEM_NAME, "system"_s);
	$assignStatic(WindowsFileAttributeViews$Dos::HIDDEN_NAME, "hidden"_s);
	$assignStatic(WindowsFileAttributeViews$Dos::ATTRIBUTES_NAME, "attributes"_s);
	$init($AbstractBasicFileAttributeView);
	$assignStatic(WindowsFileAttributeViews$Dos::dosAttributeNames, $Util::newSet($AbstractBasicFileAttributeView::basicAttributeNames, $$new($StringArray, {
		WindowsFileAttributeViews$Dos::READONLY_NAME,
		WindowsFileAttributeViews$Dos::ARCHIVE_NAME,
		WindowsFileAttributeViews$Dos::SYSTEM_NAME,
		WindowsFileAttributeViews$Dos::HIDDEN_NAME,
		WindowsFileAttributeViews$Dos::ATTRIBUTES_NAME
	})));
}

WindowsFileAttributeViews$Dos::WindowsFileAttributeViews$Dos() {
}

$Class* WindowsFileAttributeViews$Dos::load$($String* name, bool initialize) {
	$loadClass(WindowsFileAttributeViews$Dos, name, initialize, &_WindowsFileAttributeViews$Dos_ClassInfo_, clinit$WindowsFileAttributeViews$Dos, allocate$WindowsFileAttributeViews$Dos);
	return class$;
}

$Class* WindowsFileAttributeViews$Dos::class$ = nullptr;

		} // fs
	} // nio
} // sun