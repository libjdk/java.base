#include <sun/nio/fs/LinuxFileSystem$SupportedFileFileAttributeViewsHolder.h>

#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <sun/nio/fs/LinuxFileSystem.h>
#include <sun/nio/fs/UnixFileSystem.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;
using $UnixFileSystem = ::sun::nio::fs::UnixFileSystem;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _LinuxFileSystem$SupportedFileFileAttributeViewsHolder_FieldInfo_[] = {
	{"supportedFileAttributeViews", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $STATIC | $FINAL, $staticField(LinuxFileSystem$SupportedFileFileAttributeViewsHolder, supportedFileAttributeViews$)},
	{}
};

$MethodInfo _LinuxFileSystem$SupportedFileFileAttributeViewsHolder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(LinuxFileSystem$SupportedFileFileAttributeViewsHolder, init$, void)},
	{"supportedFileAttributeViews", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(LinuxFileSystem$SupportedFileFileAttributeViewsHolder, supportedFileAttributeViews, $Set*)},
	{}
};

$InnerClassInfo _LinuxFileSystem$SupportedFileFileAttributeViewsHolder_InnerClassesInfo_[] = {
	{"sun.nio.fs.LinuxFileSystem$SupportedFileFileAttributeViewsHolder", "sun.nio.fs.LinuxFileSystem", "SupportedFileFileAttributeViewsHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _LinuxFileSystem$SupportedFileFileAttributeViewsHolder_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.LinuxFileSystem$SupportedFileFileAttributeViewsHolder",
	"java.lang.Object",
	nullptr,
	_LinuxFileSystem$SupportedFileFileAttributeViewsHolder_FieldInfo_,
	_LinuxFileSystem$SupportedFileFileAttributeViewsHolder_MethodInfo_,
	nullptr,
	nullptr,
	_LinuxFileSystem$SupportedFileFileAttributeViewsHolder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.fs.LinuxFileSystem"
};

$Object* allocate$LinuxFileSystem$SupportedFileFileAttributeViewsHolder($Class* clazz) {
	return $of($alloc(LinuxFileSystem$SupportedFileFileAttributeViewsHolder));
}

$Set* LinuxFileSystem$SupportedFileFileAttributeViewsHolder::supportedFileAttributeViews$ = nullptr;

void LinuxFileSystem$SupportedFileFileAttributeViewsHolder::init$() {
}

$Set* LinuxFileSystem$SupportedFileFileAttributeViewsHolder::supportedFileAttributeViews() {
	$init(LinuxFileSystem$SupportedFileFileAttributeViewsHolder);
	$useLocalCurrentObjectStackCache();
	$var($Set, result, $new($HashSet));
	result->addAll($($UnixFileSystem::standardFileAttributeViews()));
	result->add("dos"_s);
	result->add("user"_s);
	return $Collections::unmodifiableSet(result);
}

void clinit$LinuxFileSystem$SupportedFileFileAttributeViewsHolder($Class* class$) {
	$assignStatic(LinuxFileSystem$SupportedFileFileAttributeViewsHolder::supportedFileAttributeViews$, LinuxFileSystem$SupportedFileFileAttributeViewsHolder::supportedFileAttributeViews());
}

LinuxFileSystem$SupportedFileFileAttributeViewsHolder::LinuxFileSystem$SupportedFileFileAttributeViewsHolder() {
}

$Class* LinuxFileSystem$SupportedFileFileAttributeViewsHolder::load$($String* name, bool initialize) {
	$loadClass(LinuxFileSystem$SupportedFileFileAttributeViewsHolder, name, initialize, &_LinuxFileSystem$SupportedFileFileAttributeViewsHolder_ClassInfo_, clinit$LinuxFileSystem$SupportedFileFileAttributeViewsHolder, allocate$LinuxFileSystem$SupportedFileFileAttributeViewsHolder);
	return class$;
}

$Class* LinuxFileSystem$SupportedFileFileAttributeViewsHolder::class$ = nullptr;

		} // fs
	} // nio
} // sun