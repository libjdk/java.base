#include <sun/nio/fs/AbstractAclFileAttributeView.h>

#include <java/nio/file/attribute/AclFileAttributeView.h>
#include <java/nio/file/attribute/FileOwnerAttributeView.h>
#include <java/nio/file/attribute/UserPrincipal.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <jcpp.h>

#undef ACL_NAME
#undef OWNER_NAME

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $AclFileAttributeView = ::java::nio::file::attribute::AclFileAttributeView;
using $UserPrincipal = ::java::nio::file::attribute::UserPrincipal;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $List = ::java::util::List;
using $Map = ::java::util::Map;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _AbstractAclFileAttributeView_FieldInfo_[] = {
	{"OWNER_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AbstractAclFileAttributeView, OWNER_NAME)},
	{"ACL_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AbstractAclFileAttributeView, ACL_NAME)},
	{}
};

$MethodInfo _AbstractAclFileAttributeView_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, 0, $method(AbstractAclFileAttributeView, init$, void)},
	{"name", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $virtualMethod(AbstractAclFileAttributeView, name, $String*)},
	{"readAttributes", "([Ljava/lang/String;)Ljava/util/Map;", "([Ljava/lang/String;)Ljava/util/Map<Ljava/lang/String;Ljava/lang/Object;>;", $PUBLIC | $FINAL, $virtualMethod(AbstractAclFileAttributeView, readAttributes, $Map*, $StringArray*), "java.io.IOException"},
	{"setAttribute", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC | $FINAL, $virtualMethod(AbstractAclFileAttributeView, setAttribute, void, $String*, Object$*), "java.io.IOException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _AbstractAclFileAttributeView_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.nio.fs.AbstractAclFileAttributeView",
	"java.lang.Object",
	"java.nio.file.attribute.AclFileAttributeView,sun.nio.fs.DynamicFileAttributeView",
	_AbstractAclFileAttributeView_FieldInfo_,
	_AbstractAclFileAttributeView_MethodInfo_
};

$Object* allocate$AbstractAclFileAttributeView($Class* clazz) {
	return $of($alloc(AbstractAclFileAttributeView));
}

int32_t AbstractAclFileAttributeView::hashCode() {
	 return this->$AclFileAttributeView::hashCode();
}

bool AbstractAclFileAttributeView::equals(Object$* obj) {
	 return this->$AclFileAttributeView::equals(obj);
}

$Object* AbstractAclFileAttributeView::clone() {
	 return this->$AclFileAttributeView::clone();
}

$String* AbstractAclFileAttributeView::toString() {
	 return this->$AclFileAttributeView::toString();
}

void AbstractAclFileAttributeView::finalize() {
	this->$AclFileAttributeView::finalize();
}

$String* AbstractAclFileAttributeView::OWNER_NAME = nullptr;
$String* AbstractAclFileAttributeView::ACL_NAME = nullptr;

void AbstractAclFileAttributeView::init$() {
}

$String* AbstractAclFileAttributeView::name() {
	return "acl"_s;
}

void AbstractAclFileAttributeView::setAttribute($String* attribute, Object$* value) {
	$useLocalCurrentObjectStackCache();
	if ($nc(attribute)->equals(AbstractAclFileAttributeView::OWNER_NAME)) {
		setOwner($cast($UserPrincipal, value));
		return;
	}
	if ($nc(attribute)->equals(AbstractAclFileAttributeView::ACL_NAME)) {
		setAcl($cast($List, value));
		return;
	}
	$throwNew($IllegalArgumentException, $$str({"\'"_s, $(name()), ":"_s, attribute, "\' not recognized"_s}));
}

$Map* AbstractAclFileAttributeView::readAttributes($StringArray* attributes) {
	$useLocalCurrentObjectStackCache();
	bool acl = false;
	bool owner = false;
	{
		$var($StringArray, arr$, attributes);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, attribute, arr$->get(i$));
			{
				if ($nc(attribute)->equals("*"_s)) {
					owner = true;
					acl = true;
					continue;
				}
				if ($nc(attribute)->equals(AbstractAclFileAttributeView::ACL_NAME)) {
					acl = true;
					continue;
				}
				if ($nc(attribute)->equals(AbstractAclFileAttributeView::OWNER_NAME)) {
					owner = true;
					continue;
				}
				$throwNew($IllegalArgumentException, $$str({"\'"_s, $(name()), ":"_s, attribute, "\' not recognized"_s}));
			}
		}
	}
	$var($Map, result, $new($HashMap, 2));
	if (acl) {
		result->put(AbstractAclFileAttributeView::ACL_NAME, $(getAcl()));
	}
	if (owner) {
		result->put(AbstractAclFileAttributeView::OWNER_NAME, $(getOwner()));
	}
	return $Collections::unmodifiableMap(result);
}

AbstractAclFileAttributeView::AbstractAclFileAttributeView() {
}

void clinit$AbstractAclFileAttributeView($Class* class$) {
	$assignStatic(AbstractAclFileAttributeView::OWNER_NAME, "owner"_s);
	$assignStatic(AbstractAclFileAttributeView::ACL_NAME, "acl"_s);
}

$Class* AbstractAclFileAttributeView::load$($String* name, bool initialize) {
	$loadClass(AbstractAclFileAttributeView, name, initialize, &_AbstractAclFileAttributeView_ClassInfo_, clinit$AbstractAclFileAttributeView, allocate$AbstractAclFileAttributeView);
	return class$;
}

$Class* AbstractAclFileAttributeView::class$ = nullptr;

		} // fs
	} // nio
} // sun