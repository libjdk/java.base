#include <sun/nio/fs/BsdFileSystem$SupportedFileFileAttributeViewsHolder.h>

#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <sun/nio/fs/BsdFileSystem.h>
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

$FieldInfo _BsdFileSystem$SupportedFileFileAttributeViewsHolder_FieldInfo_[] = {
	{"supportedFileAttributeViews", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $STATIC | $FINAL, $staticField(BsdFileSystem$SupportedFileFileAttributeViewsHolder, supportedFileAttributeViews$)},
	{}
};

$MethodInfo _BsdFileSystem$SupportedFileFileAttributeViewsHolder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(BsdFileSystem$SupportedFileFileAttributeViewsHolder, init$, void)},
	{"supportedFileAttributeViews", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(BsdFileSystem$SupportedFileFileAttributeViewsHolder, supportedFileAttributeViews, $Set*)},
	{}
};

$InnerClassInfo _BsdFileSystem$SupportedFileFileAttributeViewsHolder_InnerClassesInfo_[] = {
	{"sun.nio.fs.BsdFileSystem$SupportedFileFileAttributeViewsHolder", "sun.nio.fs.BsdFileSystem", "SupportedFileFileAttributeViewsHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _BsdFileSystem$SupportedFileFileAttributeViewsHolder_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.BsdFileSystem$SupportedFileFileAttributeViewsHolder",
	"java.lang.Object",
	nullptr,
	_BsdFileSystem$SupportedFileFileAttributeViewsHolder_FieldInfo_,
	_BsdFileSystem$SupportedFileFileAttributeViewsHolder_MethodInfo_,
	nullptr,
	nullptr,
	_BsdFileSystem$SupportedFileFileAttributeViewsHolder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.fs.BsdFileSystem"
};

$Object* allocate$BsdFileSystem$SupportedFileFileAttributeViewsHolder($Class* clazz) {
	return $of($alloc(BsdFileSystem$SupportedFileFileAttributeViewsHolder));
}

$Set* BsdFileSystem$SupportedFileFileAttributeViewsHolder::supportedFileAttributeViews$ = nullptr;

void BsdFileSystem$SupportedFileFileAttributeViewsHolder::init$() {
}

$Set* BsdFileSystem$SupportedFileFileAttributeViewsHolder::supportedFileAttributeViews() {
	$init(BsdFileSystem$SupportedFileFileAttributeViewsHolder);
	$useLocalCurrentObjectStackCache();
	$var($Set, result, $new($HashSet));
	result->addAll($($UnixFileSystem::standardFileAttributeViews()));
	result->add("user"_s);
	return $Collections::unmodifiableSet(result);
}

void clinit$BsdFileSystem$SupportedFileFileAttributeViewsHolder($Class* class$) {
	$assignStatic(BsdFileSystem$SupportedFileFileAttributeViewsHolder::supportedFileAttributeViews$, BsdFileSystem$SupportedFileFileAttributeViewsHolder::supportedFileAttributeViews());
}

BsdFileSystem$SupportedFileFileAttributeViewsHolder::BsdFileSystem$SupportedFileFileAttributeViewsHolder() {
}

$Class* BsdFileSystem$SupportedFileFileAttributeViewsHolder::load$($String* name, bool initialize) {
	$loadClass(BsdFileSystem$SupportedFileFileAttributeViewsHolder, name, initialize, &_BsdFileSystem$SupportedFileFileAttributeViewsHolder_ClassInfo_, clinit$BsdFileSystem$SupportedFileFileAttributeViewsHolder, allocate$BsdFileSystem$SupportedFileFileAttributeViewsHolder);
	return class$;
}

$Class* BsdFileSystem$SupportedFileFileAttributeViewsHolder::class$ = nullptr;

		} // fs
	} // nio
} // sun