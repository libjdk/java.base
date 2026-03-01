#include <java/nio/file/attribute/AclEntry.h>

#include <java/nio/file/attribute/AclEntry$Builder.h>
#include <java/nio/file/attribute/AclEntryFlag.h>
#include <java/nio/file/attribute/AclEntryPermission.h>
#include <java/nio/file/attribute/AclEntryType.h>
#include <java/nio/file/attribute/UserPrincipal.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/Set.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AclEntry$Builder = ::java::nio::file::attribute::AclEntry$Builder;
using $AclEntryFlag = ::java::nio::file::attribute::AclEntryFlag;
using $AclEntryPermission = ::java::nio::file::attribute::AclEntryPermission;
using $AclEntryType = ::java::nio::file::attribute::AclEntryType;
using $UserPrincipal = ::java::nio::file::attribute::UserPrincipal;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $Set = ::java::util::Set;

namespace java {
	namespace nio {
		namespace file {
			namespace attribute {

$FieldInfo _AclEntry_FieldInfo_[] = {
	{"type", "Ljava/nio/file/attribute/AclEntryType;", nullptr, $PRIVATE | $FINAL, $field(AclEntry, type$)},
	{"who", "Ljava/nio/file/attribute/UserPrincipal;", nullptr, $PRIVATE | $FINAL, $field(AclEntry, who)},
	{"perms", "Ljava/util/Set;", "Ljava/util/Set<Ljava/nio/file/attribute/AclEntryPermission;>;", $PRIVATE | $FINAL, $field(AclEntry, perms)},
	{"flags", "Ljava/util/Set;", "Ljava/util/Set<Ljava/nio/file/attribute/AclEntryFlag;>;", $PRIVATE | $FINAL, $field(AclEntry, flags$)},
	{"hash", "I", nullptr, $PRIVATE | $VOLATILE, $field(AclEntry, hash$)},
	{}
};

$MethodInfo _AclEntry_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/file/attribute/AclEntryType;Ljava/nio/file/attribute/UserPrincipal;Ljava/util/Set;Ljava/util/Set;)V", "(Ljava/nio/file/attribute/AclEntryType;Ljava/nio/file/attribute/UserPrincipal;Ljava/util/Set<Ljava/nio/file/attribute/AclEntryPermission;>;Ljava/util/Set<Ljava/nio/file/attribute/AclEntryFlag;>;)V", $PRIVATE, $method(AclEntry, init$, void, $AclEntryType*, $UserPrincipal*, $Set*, $Set*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(AclEntry, equals, bool, Object$*)},
	{"flags", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/nio/file/attribute/AclEntryFlag;>;", $PUBLIC, $method(AclEntry, flags, $Set*)},
	{"hash", "(ILjava/lang/Object;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(AclEntry, hash, int32_t, int32_t, Object$*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(AclEntry, hashCode, int32_t)},
	{"newBuilder", "()Ljava/nio/file/attribute/AclEntry$Builder;", nullptr, $PUBLIC | $STATIC, $staticMethod(AclEntry, newBuilder, $AclEntry$Builder*)},
	{"newBuilder", "(Ljava/nio/file/attribute/AclEntry;)Ljava/nio/file/attribute/AclEntry$Builder;", nullptr, $PUBLIC | $STATIC, $staticMethod(AclEntry, newBuilder, $AclEntry$Builder*, AclEntry*)},
	{"permissions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/nio/file/attribute/AclEntryPermission;>;", $PUBLIC, $method(AclEntry, permissions, $Set*)},
	{"principal", "()Ljava/nio/file/attribute/UserPrincipal;", nullptr, $PUBLIC, $method(AclEntry, principal, $UserPrincipal*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(AclEntry, toString, $String*)},
	{"type", "()Ljava/nio/file/attribute/AclEntryType;", nullptr, $PUBLIC, $method(AclEntry, type, $AclEntryType*)},
	{}
};

$InnerClassInfo _AclEntry_InnerClassesInfo_[] = {
	{"java.nio.file.attribute.AclEntry$Builder", "java.nio.file.attribute.AclEntry", "Builder", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _AclEntry_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.nio.file.attribute.AclEntry",
	"java.lang.Object",
	nullptr,
	_AclEntry_FieldInfo_,
	_AclEntry_MethodInfo_,
	nullptr,
	nullptr,
	_AclEntry_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.nio.file.attribute.AclEntry$Builder"
};

$Object* allocate$AclEntry($Class* clazz) {
	return $of($alloc(AclEntry));
}

void AclEntry::init$($AclEntryType* type, $UserPrincipal* who, $Set* perms, $Set* flags) {
	$set(this, type$, type);
	$set(this, who, who);
	$set(this, perms, perms);
	$set(this, flags$, flags);
}

$AclEntry$Builder* AclEntry::newBuilder() {
	$useLocalCurrentObjectStackCache();
	$var($Set, perms, $Collections::emptySet());
	$var($Set, flags, $Collections::emptySet());
	return $new($AclEntry$Builder, nullptr, nullptr, perms, flags);
}

$AclEntry$Builder* AclEntry::newBuilder(AclEntry* entry) {
	return $new($AclEntry$Builder, $nc(entry)->type$, entry->who, entry->perms, entry->flags$);
}

$AclEntryType* AclEntry::type() {
	return this->type$;
}

$UserPrincipal* AclEntry::principal() {
	return this->who;
}

$Set* AclEntry::permissions() {
	return $new($HashSet, static_cast<$Collection*>(this->perms));
}

$Set* AclEntry::flags() {
	return $new($HashSet, static_cast<$Collection*>(this->flags$));
}

bool AclEntry::equals(Object$* ob) {
	if ($equals(ob, this)) {
		return true;
	}
	$var(AclEntry, other, nullptr);
	bool var$0 = $instanceOf(AclEntry, ob);
	if (var$0) {
		$assign(other, $cast(AclEntry, ob));
		var$0 = true;
	}
	if (!(var$0)) {
		return false;
	}
	if (this->type$ != $nc(other)->type$) {
		return false;
	}
	if (!$nc($of(this->who))->equals($nc(other)->who)) {
		return false;
	}
	if (!$nc(this->perms)->equals($nc(other)->perms)) {
		return false;
	}
	if (!$nc(this->flags$)->equals($nc(other)->flags$)) {
		return false;
	}
	return true;
}

int32_t AclEntry::hash(int32_t h, Object$* o) {
	return h * 127 + $nc($of(o))->hashCode();
}

int32_t AclEntry::hashCode() {
	if (this->hash$ != 0) {
		return this->hash$;
	}
	int32_t h = this->type$->hashCode();
	h = hash(h, this->who);
	h = hash(h, this->perms);
	h = hash(h, this->flags$);
	this->hash$ = h;
	return this->hash$;
}

$String* AclEntry::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append($($nc(this->who)->getName()));
	sb->append(u':');
	{
		$var($Iterator, i$, $nc(this->perms)->iterator());
		for (; $nc(i$)->hasNext();) {
			$AclEntryPermission* perm = $cast($AclEntryPermission, i$->next());
			{
				sb->append($($nc(perm)->name()));
				sb->append(u'/');
			}
		}
	}
	sb->setLength(sb->length() - 1);
	sb->append(u':');
	if (!$nc(this->flags$)->isEmpty()) {
		{
			$var($Iterator, i$, $nc(this->flags$)->iterator());
			for (; $nc(i$)->hasNext();) {
				$AclEntryFlag* flag = $cast($AclEntryFlag, i$->next());
				{
					sb->append($($nc(flag)->name()));
					sb->append(u'/');
				}
			}
		}
		sb->setLength(sb->length() - 1);
		sb->append(u':');
	}
	sb->append($(this->type$->name()));
	return sb->toString();
}

AclEntry::AclEntry() {
}

$Class* AclEntry::load$($String* name, bool initialize) {
	$loadClass(AclEntry, name, initialize, &_AclEntry_ClassInfo_, allocate$AclEntry);
	return class$;
}

$Class* AclEntry::class$ = nullptr;

			} // attribute
		} // file
	} // nio
} // java