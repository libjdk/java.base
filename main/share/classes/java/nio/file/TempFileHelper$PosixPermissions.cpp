#include <java/nio/file/TempFileHelper$PosixPermissions.h>

#include <java/lang/Enum.h>
#include <java/nio/file/TempFileHelper.h>
#include <java/nio/file/attribute/FileAttribute.h>
#include <java/nio/file/attribute/PosixFilePermission.h>
#include <java/nio/file/attribute/PosixFilePermissions.h>
#include <java/util/EnumSet.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef OWNER_EXECUTE
#undef OWNER_READ
#undef OWNER_WRITE

using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $FileAttribute = ::java::nio::file::attribute::FileAttribute;
using $PosixFilePermission = ::java::nio::file::attribute::PosixFilePermission;
using $PosixFilePermissions = ::java::nio::file::attribute::PosixFilePermissions;
using $EnumSet = ::java::util::EnumSet;
using $Set = ::java::util::Set;

namespace java {
	namespace nio {
		namespace file {

$FieldInfo _TempFileHelper$PosixPermissions_FieldInfo_[] = {
	{"filePermissions", "Ljava/nio/file/attribute/FileAttribute;", "Ljava/nio/file/attribute/FileAttribute<Ljava/util/Set<Ljava/nio/file/attribute/PosixFilePermission;>;>;", $STATIC | $FINAL, $staticField(TempFileHelper$PosixPermissions, filePermissions)},
	{"dirPermissions", "Ljava/nio/file/attribute/FileAttribute;", "Ljava/nio/file/attribute/FileAttribute<Ljava/util/Set<Ljava/nio/file/attribute/PosixFilePermission;>;>;", $STATIC | $FINAL, $staticField(TempFileHelper$PosixPermissions, dirPermissions)},
	{}
};

$MethodInfo _TempFileHelper$PosixPermissions_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(TempFileHelper$PosixPermissions, init$, void)},
	{}
};

$InnerClassInfo _TempFileHelper$PosixPermissions_InnerClassesInfo_[] = {
	{"java.nio.file.TempFileHelper$PosixPermissions", "java.nio.file.TempFileHelper", "PosixPermissions", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _TempFileHelper$PosixPermissions_ClassInfo_ = {
	$ACC_SUPER,
	"java.nio.file.TempFileHelper$PosixPermissions",
	"java.lang.Object",
	nullptr,
	_TempFileHelper$PosixPermissions_FieldInfo_,
	_TempFileHelper$PosixPermissions_MethodInfo_,
	nullptr,
	nullptr,
	_TempFileHelper$PosixPermissions_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.nio.file.TempFileHelper"
};

$Object* allocate$TempFileHelper$PosixPermissions($Class* clazz) {
	return $of($alloc(TempFileHelper$PosixPermissions));
}

$FileAttribute* TempFileHelper$PosixPermissions::filePermissions = nullptr;
$FileAttribute* TempFileHelper$PosixPermissions::dirPermissions = nullptr;

void TempFileHelper$PosixPermissions::init$() {
}

void clinit$TempFileHelper$PosixPermissions($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$init($PosixFilePermission);
	$assignStatic(TempFileHelper$PosixPermissions::filePermissions, $PosixFilePermissions::asFileAttribute($($EnumSet::of(static_cast<$Enum*>($PosixFilePermission::OWNER_READ), static_cast<$Enum*>($PosixFilePermission::OWNER_WRITE)))));
	$assignStatic(TempFileHelper$PosixPermissions::dirPermissions, $PosixFilePermissions::asFileAttribute($($EnumSet::of($PosixFilePermission::OWNER_READ, $PosixFilePermission::OWNER_WRITE, $PosixFilePermission::OWNER_EXECUTE))));
}

TempFileHelper$PosixPermissions::TempFileHelper$PosixPermissions() {
}

$Class* TempFileHelper$PosixPermissions::load$($String* name, bool initialize) {
	$loadClass(TempFileHelper$PosixPermissions, name, initialize, &_TempFileHelper$PosixPermissions_ClassInfo_, clinit$TempFileHelper$PosixPermissions, allocate$TempFileHelper$PosixPermissions);
	return class$;
}

$Class* TempFileHelper$PosixPermissions::class$ = nullptr;

		} // file
	} // nio
} // java