#include <CheckPermission$Checks.h>

#include <CheckPermission$FileOperation.h>
#include <CheckPermission.h>
#include <java/util/ArrayList.h>
#include <java/util/EnumMap.h>
#include <java/util/HashSet.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <jcpp.h>

using $CheckPermission$FileOperation = ::CheckPermission$FileOperation;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $EnumMap = ::java::util::EnumMap;
using $HashSet = ::java::util::HashSet;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;

$FieldInfo _CheckPermission$Checks_FieldInfo_[] = {
	{"permissionsChecked", "Ljava/util/List;", "Ljava/util/List<Ljava/security/Permission;>;", $PRIVATE, $field(CheckPermission$Checks, permissionsChecked$)},
	{"propertiesChecked", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE, $field(CheckPermission$Checks, propertiesChecked$)},
	{"fileOperationChecked", "Ljava/util/Map;", "Ljava/util/Map<LCheckPermission$FileOperation;Ljava/util/List<Ljava/lang/String;>;>;", $PRIVATE, $field(CheckPermission$Checks, fileOperationChecked$)},
	{}
};

$MethodInfo _CheckPermission$Checks_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(CheckPermission$Checks, init$, void)},
	{"addFileOperation", "(LCheckPermission$FileOperation;Ljava/lang/String;)V", nullptr, 0, $virtualMethod(CheckPermission$Checks, addFileOperation, void, $CheckPermission$FileOperation*, $String*)},
	{"fileOperationChecked", "(LCheckPermission$FileOperation;)Ljava/util/List;", "(LCheckPermission$FileOperation;)Ljava/util/List<Ljava/lang/String;>;", 0, $virtualMethod(CheckPermission$Checks, fileOperationChecked, $List*, $CheckPermission$FileOperation*)},
	{"permissionsChecked", "()Ljava/util/List;", "()Ljava/util/List<Ljava/security/Permission;>;", 0, $virtualMethod(CheckPermission$Checks, permissionsChecked, $List*)},
	{"propertiesChecked", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", 0, $virtualMethod(CheckPermission$Checks, propertiesChecked, $Set*)},
	{}
};

$InnerClassInfo _CheckPermission$Checks_InnerClassesInfo_[] = {
	{"CheckPermission$Checks", "CheckPermission", "Checks", $STATIC},
	{}
};

$ClassInfo _CheckPermission$Checks_ClassInfo_ = {
	$ACC_SUPER,
	"CheckPermission$Checks",
	"java.lang.Object",
	nullptr,
	_CheckPermission$Checks_FieldInfo_,
	_CheckPermission$Checks_MethodInfo_,
	nullptr,
	nullptr,
	_CheckPermission$Checks_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"CheckPermission"
};

$Object* allocate$CheckPermission$Checks($Class* clazz) {
	return $of($alloc(CheckPermission$Checks));
}

void CheckPermission$Checks::init$() {
	$set(this, permissionsChecked$, $new($ArrayList));
	$set(this, propertiesChecked$, $new($HashSet));
	$load($CheckPermission$FileOperation);
	$set(this, fileOperationChecked$, $new($EnumMap, $CheckPermission$FileOperation::class$));
}

$List* CheckPermission$Checks::permissionsChecked() {
	return this->permissionsChecked$;
}

$Set* CheckPermission$Checks::propertiesChecked() {
	return this->propertiesChecked$;
}

$List* CheckPermission$Checks::fileOperationChecked($CheckPermission$FileOperation* op) {
	return $cast($List, $nc(this->fileOperationChecked$)->get(op));
}

void CheckPermission$Checks::addFileOperation($CheckPermission$FileOperation* op, $String* file) {
	$var($List, opList, $cast($List, $nc(this->fileOperationChecked$)->get(op)));
	if (opList == nullptr) {
		$assign(opList, $new($ArrayList));
		$nc(this->fileOperationChecked$)->put(op, opList);
	}
	$nc(opList)->add(file);
}

CheckPermission$Checks::CheckPermission$Checks() {
}

$Class* CheckPermission$Checks::load$($String* name, bool initialize) {
	$loadClass(CheckPermission$Checks, name, initialize, &_CheckPermission$Checks_ClassInfo_, allocate$CheckPermission$Checks);
	return class$;
}

$Class* CheckPermission$Checks::class$ = nullptr;