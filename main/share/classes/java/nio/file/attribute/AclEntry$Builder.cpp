#include <java/nio/file/attribute/AclEntry$Builder.h>

#include <java/lang/AssertionError.h>
#include <java/lang/IllegalStateException.h>
#include <java/nio/file/attribute/AclEntry.h>
#include <java/nio/file/attribute/AclEntryFlag.h>
#include <java/nio/file/attribute/AclEntryPermission.h>
#include <java/nio/file/attribute/AclEntryType.h>
#include <java/nio/file/attribute/UserPrincipal.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/EnumSet.h>
#include <java/util/Iterator.h>
#include <java/util/Set.h>
#include <jcpp.h>

using $AclEntryFlagArray = $Array<::java::nio::file::attribute::AclEntryFlag>;
using $AclEntryPermissionArray = $Array<::java::nio::file::attribute::AclEntryPermission>;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $AclEntry = ::java::nio::file::attribute::AclEntry;
using $AclEntryFlag = ::java::nio::file::attribute::AclEntryFlag;
using $AclEntryPermission = ::java::nio::file::attribute::AclEntryPermission;
using $AclEntryType = ::java::nio::file::attribute::AclEntryType;
using $UserPrincipal = ::java::nio::file::attribute::UserPrincipal;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $EnumSet = ::java::util::EnumSet;
using $Iterator = ::java::util::Iterator;
using $Set = ::java::util::Set;

namespace java {
	namespace nio {
		namespace file {
			namespace attribute {

$FieldInfo _AclEntry$Builder_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(AclEntry$Builder, $assertionsDisabled)},
	{"type", "Ljava/nio/file/attribute/AclEntryType;", nullptr, $PRIVATE, $field(AclEntry$Builder, type)},
	{"who", "Ljava/nio/file/attribute/UserPrincipal;", nullptr, $PRIVATE, $field(AclEntry$Builder, who)},
	{"perms", "Ljava/util/Set;", "Ljava/util/Set<Ljava/nio/file/attribute/AclEntryPermission;>;", $PRIVATE, $field(AclEntry$Builder, perms)},
	{"flags", "Ljava/util/Set;", "Ljava/util/Set<Ljava/nio/file/attribute/AclEntryFlag;>;", $PRIVATE, $field(AclEntry$Builder, flags)},
	{}
};

$MethodInfo _AclEntry$Builder_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/file/attribute/AclEntryType;Ljava/nio/file/attribute/UserPrincipal;Ljava/util/Set;Ljava/util/Set;)V", "(Ljava/nio/file/attribute/AclEntryType;Ljava/nio/file/attribute/UserPrincipal;Ljava/util/Set<Ljava/nio/file/attribute/AclEntryPermission;>;Ljava/util/Set<Ljava/nio/file/attribute/AclEntryFlag;>;)V", $PRIVATE, $method(AclEntry$Builder, init$, void, $AclEntryType*, $UserPrincipal*, $Set*, $Set*)},
	{"build", "()Ljava/nio/file/attribute/AclEntry;", nullptr, $PUBLIC, $method(AclEntry$Builder, build, $AclEntry*)},
	{"checkSet", "(Ljava/util/Set;Ljava/lang/Class;)V", "(Ljava/util/Set<*>;Ljava/lang/Class<*>;)V", $PRIVATE | $STATIC, $staticMethod(AclEntry$Builder, checkSet, void, $Set*, $Class*)},
	{"setFlags", "(Ljava/util/Set;)Ljava/nio/file/attribute/AclEntry$Builder;", "(Ljava/util/Set<Ljava/nio/file/attribute/AclEntryFlag;>;)Ljava/nio/file/attribute/AclEntry$Builder;", $PUBLIC, $method(AclEntry$Builder, setFlags, AclEntry$Builder*, $Set*)},
	{"setFlags", "([Ljava/nio/file/attribute/AclEntryFlag;)Ljava/nio/file/attribute/AclEntry$Builder;", nullptr, $PUBLIC | $TRANSIENT, $method(AclEntry$Builder, setFlags, AclEntry$Builder*, $AclEntryFlagArray*)},
	{"setPermissions", "(Ljava/util/Set;)Ljava/nio/file/attribute/AclEntry$Builder;", "(Ljava/util/Set<Ljava/nio/file/attribute/AclEntryPermission;>;)Ljava/nio/file/attribute/AclEntry$Builder;", $PUBLIC, $method(AclEntry$Builder, setPermissions, AclEntry$Builder*, $Set*)},
	{"setPermissions", "([Ljava/nio/file/attribute/AclEntryPermission;)Ljava/nio/file/attribute/AclEntry$Builder;", nullptr, $PUBLIC | $TRANSIENT, $method(AclEntry$Builder, setPermissions, AclEntry$Builder*, $AclEntryPermissionArray*)},
	{"setPrincipal", "(Ljava/nio/file/attribute/UserPrincipal;)Ljava/nio/file/attribute/AclEntry$Builder;", nullptr, $PUBLIC, $method(AclEntry$Builder, setPrincipal, AclEntry$Builder*, $UserPrincipal*)},
	{"setType", "(Ljava/nio/file/attribute/AclEntryType;)Ljava/nio/file/attribute/AclEntry$Builder;", nullptr, $PUBLIC, $method(AclEntry$Builder, setType, AclEntry$Builder*, $AclEntryType*)},
	{}
};

$InnerClassInfo _AclEntry$Builder_InnerClassesInfo_[] = {
	{"java.nio.file.attribute.AclEntry$Builder", "java.nio.file.attribute.AclEntry", "Builder", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _AclEntry$Builder_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.nio.file.attribute.AclEntry$Builder",
	"java.lang.Object",
	nullptr,
	_AclEntry$Builder_FieldInfo_,
	_AclEntry$Builder_MethodInfo_,
	nullptr,
	nullptr,
	_AclEntry$Builder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.nio.file.attribute.AclEntry"
};

$Object* allocate$AclEntry$Builder($Class* clazz) {
	return $of($alloc(AclEntry$Builder));
}

bool AclEntry$Builder::$assertionsDisabled = false;

void AclEntry$Builder::init$($AclEntryType* type, $UserPrincipal* who, $Set* perms, $Set* flags) {
	if (!AclEntry$Builder::$assertionsDisabled && !(perms != nullptr && flags != nullptr)) {
		$throwNew($AssertionError);
	}
	$set(this, type, type);
	$set(this, who, who);
	$set(this, perms, perms);
	$set(this, flags, flags);
}

$AclEntry* AclEntry$Builder::build() {
	if (this->type == nullptr) {
		$throwNew($IllegalStateException, "Missing type component"_s);
	}
	if (this->who == nullptr) {
		$throwNew($IllegalStateException, "Missing who component"_s);
	}
	return $new($AclEntry, this->type, this->who, this->perms, this->flags);
}

AclEntry$Builder* AclEntry$Builder::setType($AclEntryType* type) {
	if (type == nullptr) {
		$throwNew($NullPointerException);
	}
	$set(this, type, type);
	return this;
}

AclEntry$Builder* AclEntry$Builder::setPrincipal($UserPrincipal* who) {
	if (who == nullptr) {
		$throwNew($NullPointerException);
	}
	$set(this, who, who);
	return this;
}

void AclEntry$Builder::checkSet($Set* set, $Class* type) {
	$init(AclEntry$Builder);
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc(set)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Object, e, i$->next());
			{
				if (e == nullptr) {
					$throwNew($NullPointerException);
				}
				$nc(type)->cast(e);
			}
		}
	}
}

AclEntry$Builder* AclEntry$Builder::setPermissions($Set* perms$renamed) {
	$var($Set, perms, perms$renamed);
	if ($nc(perms)->isEmpty()) {
		$assign(perms, $Collections::emptySet());
	} else {
		$assign(perms, $EnumSet::copyOf(static_cast<$Collection*>(perms)));
		$load($AclEntryPermission);
		checkSet(perms, $AclEntryPermission::class$);
	}
	$set(this, perms, perms);
	return this;
}

AclEntry$Builder* AclEntry$Builder::setPermissions($AclEntryPermissionArray* perms) {
	$useLocalCurrentObjectStackCache();
	$load($AclEntryPermission);
	$var($Set, set, $EnumSet::noneOf($AclEntryPermission::class$));
	{
		$var($AclEntryPermissionArray, arr$, perms);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$AclEntryPermission* p = arr$->get(i$);
			{
				if (p == nullptr) {
					$throwNew($NullPointerException);
				}
				$nc(set)->add(p);
			}
		}
	}
	$set(this, perms, set);
	return this;
}

AclEntry$Builder* AclEntry$Builder::setFlags($Set* flags$renamed) {
	$var($Set, flags, flags$renamed);
	if ($nc(flags)->isEmpty()) {
		$assign(flags, $Collections::emptySet());
	} else {
		$assign(flags, $EnumSet::copyOf(static_cast<$Collection*>(flags)));
		$load($AclEntryFlag);
		checkSet(flags, $AclEntryFlag::class$);
	}
	$set(this, flags, flags);
	return this;
}

AclEntry$Builder* AclEntry$Builder::setFlags($AclEntryFlagArray* flags) {
	$useLocalCurrentObjectStackCache();
	$load($AclEntryFlag);
	$var($Set, set, $EnumSet::noneOf($AclEntryFlag::class$));
	{
		$var($AclEntryFlagArray, arr$, flags);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$AclEntryFlag* f = arr$->get(i$);
			{
				if (f == nullptr) {
					$throwNew($NullPointerException);
				}
				$nc(set)->add(f);
			}
		}
	}
	$set(this, flags, set);
	return this;
}

void clinit$AclEntry$Builder($Class* class$) {
	$load($AclEntry);
	AclEntry$Builder::$assertionsDisabled = !$AclEntry::class$->desiredAssertionStatus();
}

AclEntry$Builder::AclEntry$Builder() {
}

$Class* AclEntry$Builder::load$($String* name, bool initialize) {
	$loadClass(AclEntry$Builder, name, initialize, &_AclEntry$Builder_ClassInfo_, clinit$AclEntry$Builder, allocate$AclEntry$Builder);
	return class$;
}

$Class* AclEntry$Builder::class$ = nullptr;

			} // attribute
		} // file
	} // nio
} // java