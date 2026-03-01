#include <java/nio/file/attribute/PosixFilePermissions.h>

#include <java/nio/file/attribute/FileAttribute.h>
#include <java/nio/file/attribute/PosixFilePermission.h>
#include <java/nio/file/attribute/PosixFilePermissions$1.h>
#include <java/util/Collection.h>
#include <java/util/EnumSet.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef GROUP_EXECUTE
#undef GROUP_READ
#undef GROUP_WRITE
#undef OTHERS_EXECUTE
#undef OTHERS_READ
#undef OTHERS_WRITE
#undef OWNER_EXECUTE
#undef OWNER_READ
#undef OWNER_WRITE

using $ClassInfo = ::java::lang::ClassInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $FileAttribute = ::java::nio::file::attribute::FileAttribute;
using $PosixFilePermission = ::java::nio::file::attribute::PosixFilePermission;
using $PosixFilePermissions$1 = ::java::nio::file::attribute::PosixFilePermissions$1;
using $Collection = ::java::util::Collection;
using $EnumSet = ::java::util::EnumSet;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $Set = ::java::util::Set;

namespace java {
	namespace nio {
		namespace file {
			namespace attribute {

$MethodInfo _PosixFilePermissions_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(PosixFilePermissions, init$, void)},
	{"asFileAttribute", "(Ljava/util/Set;)Ljava/nio/file/attribute/FileAttribute;", "(Ljava/util/Set<Ljava/nio/file/attribute/PosixFilePermission;>;)Ljava/nio/file/attribute/FileAttribute<Ljava/util/Set<Ljava/nio/file/attribute/PosixFilePermission;>;>;", $PUBLIC | $STATIC, $staticMethod(PosixFilePermissions, asFileAttribute, $FileAttribute*, $Set*)},
	{"fromString", "(Ljava/lang/String;)Ljava/util/Set;", "(Ljava/lang/String;)Ljava/util/Set<Ljava/nio/file/attribute/PosixFilePermission;>;", $PUBLIC | $STATIC, $staticMethod(PosixFilePermissions, fromString, $Set*, $String*)},
	{"isR", "(C)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(PosixFilePermissions, isR, bool, char16_t)},
	{"isSet", "(CC)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(PosixFilePermissions, isSet, bool, char16_t, char16_t)},
	{"isW", "(C)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(PosixFilePermissions, isW, bool, char16_t)},
	{"isX", "(C)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(PosixFilePermissions, isX, bool, char16_t)},
	{"toString", "(Ljava/util/Set;)Ljava/lang/String;", "(Ljava/util/Set<Ljava/nio/file/attribute/PosixFilePermission;>;)Ljava/lang/String;", $PUBLIC | $STATIC, $staticMethod(PosixFilePermissions, toString, $String*, $Set*)},
	{"writeBits", "(Ljava/lang/StringBuilder;ZZZ)V", nullptr, $PRIVATE | $STATIC, $staticMethod(PosixFilePermissions, writeBits, void, $StringBuilder*, bool, bool, bool)},
	{}
};

$InnerClassInfo _PosixFilePermissions_InnerClassesInfo_[] = {
	{"java.nio.file.attribute.PosixFilePermissions$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _PosixFilePermissions_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.nio.file.attribute.PosixFilePermissions",
	"java.lang.Object",
	nullptr,
	nullptr,
	_PosixFilePermissions_MethodInfo_,
	nullptr,
	nullptr,
	_PosixFilePermissions_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.nio.file.attribute.PosixFilePermissions$1"
};

$Object* allocate$PosixFilePermissions($Class* clazz) {
	return $of($alloc(PosixFilePermissions));
}

void PosixFilePermissions::init$() {
}

void PosixFilePermissions::writeBits($StringBuilder* sb, bool r, bool w, bool x) {
	if (r) {
		$nc(sb)->append(u'r');
	} else {
		$nc(sb)->append(u'-');
	}
	if (w) {
		$nc(sb)->append(u'w');
	} else {
		$nc(sb)->append(u'-');
	}
	if (x) {
		$nc(sb)->append(u'x');
	} else {
		$nc(sb)->append(u'-');
	}
}

$String* PosixFilePermissions::toString($Set* perms) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder, 9));
	$var($StringBuilder, var$0, sb);
	$init($PosixFilePermission);
	bool var$1 = $nc(perms)->contains($PosixFilePermission::OWNER_READ);
	bool var$2 = perms->contains($PosixFilePermission::OWNER_WRITE);
	writeBits(var$0, var$1, var$2, perms->contains($PosixFilePermission::OWNER_EXECUTE));
	$var($StringBuilder, var$3, sb);
	bool var$4 = $nc(perms)->contains($PosixFilePermission::GROUP_READ);
	bool var$5 = perms->contains($PosixFilePermission::GROUP_WRITE);
	writeBits(var$3, var$4, var$5, perms->contains($PosixFilePermission::GROUP_EXECUTE));
	$var($StringBuilder, var$6, sb);
	bool var$7 = $nc(perms)->contains($PosixFilePermission::OTHERS_READ);
	bool var$8 = perms->contains($PosixFilePermission::OTHERS_WRITE);
	writeBits(var$6, var$7, var$8, perms->contains($PosixFilePermission::OTHERS_EXECUTE));
	return sb->toString();
}

bool PosixFilePermissions::isSet(char16_t c, char16_t setValue) {
	if (c == setValue) {
		return true;
	}
	if (c == u'-') {
		return false;
	}
	$throwNew($IllegalArgumentException, "Invalid mode"_s);
}

bool PosixFilePermissions::isR(char16_t c) {
	return isSet(c, u'r');
}

bool PosixFilePermissions::isW(char16_t c) {
	return isSet(c, u'w');
}

bool PosixFilePermissions::isX(char16_t c) {
	return isSet(c, u'x');
}

$Set* PosixFilePermissions::fromString($String* perms) {
	if ($nc(perms)->length() != 9) {
		$throwNew($IllegalArgumentException, "Invalid mode"_s);
	}
	$load($PosixFilePermission);
	$var($Set, result, $EnumSet::noneOf($PosixFilePermission::class$));
	if (isR($nc(perms)->charAt(0))) {
		$init($PosixFilePermission);
		$nc(result)->add($PosixFilePermission::OWNER_READ);
	}
	if (isW($nc(perms)->charAt(1))) {
		$init($PosixFilePermission);
		$nc(result)->add($PosixFilePermission::OWNER_WRITE);
	}
	if (isX($nc(perms)->charAt(2))) {
		$init($PosixFilePermission);
		$nc(result)->add($PosixFilePermission::OWNER_EXECUTE);
	}
	if (isR($nc(perms)->charAt(3))) {
		$init($PosixFilePermission);
		$nc(result)->add($PosixFilePermission::GROUP_READ);
	}
	if (isW($nc(perms)->charAt(4))) {
		$init($PosixFilePermission);
		$nc(result)->add($PosixFilePermission::GROUP_WRITE);
	}
	if (isX($nc(perms)->charAt(5))) {
		$init($PosixFilePermission);
		$nc(result)->add($PosixFilePermission::GROUP_EXECUTE);
	}
	if (isR($nc(perms)->charAt(6))) {
		$init($PosixFilePermission);
		$nc(result)->add($PosixFilePermission::OTHERS_READ);
	}
	if (isW($nc(perms)->charAt(7))) {
		$init($PosixFilePermission);
		$nc(result)->add($PosixFilePermission::OTHERS_WRITE);
	}
	if (isX($nc(perms)->charAt(8))) {
		$init($PosixFilePermission);
		$nc(result)->add($PosixFilePermission::OTHERS_EXECUTE);
	}
	return result;
}

$FileAttribute* PosixFilePermissions::asFileAttribute($Set* perms$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Set, perms, perms$renamed);
	$assign(perms, $new($HashSet, static_cast<$Collection*>(perms)));
	{
		$var($Iterator, i$, perms->iterator());
		for (; $nc(i$)->hasNext();) {
			$PosixFilePermission* p = $cast($PosixFilePermission, i$->next());
			{
				if (p == nullptr) {
					$throwNew($NullPointerException);
				}
			}
		}
	}
	$var($Set, value, perms);
	return $new($PosixFilePermissions$1, value);
}

PosixFilePermissions::PosixFilePermissions() {
}

$Class* PosixFilePermissions::load$($String* name, bool initialize) {
	$loadClass(PosixFilePermissions, name, initialize, &_PosixFilePermissions_ClassInfo_, allocate$PosixFilePermissions);
	return class$;
}

$Class* PosixFilePermissions::class$ = nullptr;

			} // attribute
		} // file
	} // nio
} // java