#include <java/lang/Class$EnclosingMethodInfo.h>

#include <java/lang/AssertionError.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/InternalError.h>
#include <jcpp.h>

using $AssertionError = ::java::lang::AssertionError;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;

namespace java {
	namespace lang {

$FieldInfo _Class$EnclosingMethodInfo_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Class$EnclosingMethodInfo, $assertionsDisabled)},
	{"enclosingClass", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $FINAL, $field(Class$EnclosingMethodInfo, enclosingClass)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Class$EnclosingMethodInfo, name)},
	{"descriptor", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Class$EnclosingMethodInfo, descriptor)},
	{}
};

$MethodInfo _Class$EnclosingMethodInfo_MethodInfo_[] = {
	{"<init>", "([Ljava/lang/Object;)V", nullptr, 0, $method(Class$EnclosingMethodInfo, init$, void, $ObjectArray*)},
	{"getDescriptor", "()Ljava/lang/String;", nullptr, 0, $method(Class$EnclosingMethodInfo, getDescriptor, $String*)},
	{"getEnclosingClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", 0, $method(Class$EnclosingMethodInfo, getEnclosingClass, $Class*)},
	{"getName", "()Ljava/lang/String;", nullptr, 0, $method(Class$EnclosingMethodInfo, getName, $String*)},
	{"isConstructor", "()Z", nullptr, 0, $method(Class$EnclosingMethodInfo, isConstructor, bool)},
	{"isMethod", "()Z", nullptr, 0, $method(Class$EnclosingMethodInfo, isMethod, bool)},
	{"isPartial", "()Z", nullptr, 0, $method(Class$EnclosingMethodInfo, isPartial, bool)},
	{"validate", "([Ljava/lang/Object;)V", nullptr, $STATIC, $staticMethod(Class$EnclosingMethodInfo, validate, void, $ObjectArray*)},
	{}
};

$InnerClassInfo _Class$EnclosingMethodInfo_InnerClassesInfo_[] = {
	{"java.lang.Class$EnclosingMethodInfo", "java.lang.Class", "EnclosingMethodInfo", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _Class$EnclosingMethodInfo_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.lang.Class$EnclosingMethodInfo",
	"java.lang.Object",
	nullptr,
	_Class$EnclosingMethodInfo_FieldInfo_,
	_Class$EnclosingMethodInfo_MethodInfo_,
	nullptr,
	nullptr,
	_Class$EnclosingMethodInfo_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.Class"
};

$Object* allocate$Class$EnclosingMethodInfo($Class* clazz) {
	return $of($alloc(Class$EnclosingMethodInfo));
}

bool Class$EnclosingMethodInfo::$assertionsDisabled = false;

void Class$EnclosingMethodInfo::validate($ObjectArray* enclosingInfo) {
	$init(Class$EnclosingMethodInfo);
	$useLocalCurrentObjectStackCache();
	if ($nc(enclosingInfo)->length != 3) {
		$throwNew($InternalError, "Malformed enclosing method information"_s);
	}
	try {
		$Class* enclosingClass = $cast($Class, $nc(enclosingInfo)->get(0));
		if (!Class$EnclosingMethodInfo::$assertionsDisabled && !(enclosingClass != nullptr)) {
			$throwNew($AssertionError);
		}
		$var($String, name, $cast($String, enclosingInfo->get(1)));
		$var($String, descriptor, $cast($String, enclosingInfo->get(2)));
		if (!Class$EnclosingMethodInfo::$assertionsDisabled && !((name != nullptr && descriptor != nullptr) || name == descriptor)) {
			$throwNew($AssertionError);
		}
	} catch ($ClassCastException& cce) {
		$throwNew($InternalError, "Invalid type in enclosing method information"_s, cce);
	}
}

void Class$EnclosingMethodInfo::init$($ObjectArray* enclosingInfo) {
	validate(enclosingInfo);
	$set(this, enclosingClass, $cast($Class, $nc(enclosingInfo)->get(0)));
	$set(this, name, $cast($String, enclosingInfo->get(1)));
	$set(this, descriptor, $cast($String, enclosingInfo->get(2)));
}

bool Class$EnclosingMethodInfo::isPartial() {
	return this->enclosingClass == nullptr || this->name == nullptr || this->descriptor == nullptr;
}

bool Class$EnclosingMethodInfo::isConstructor() {
	bool var$0 = !isPartial();
	return var$0 && "<init>"_s->equals(this->name);
}

bool Class$EnclosingMethodInfo::isMethod() {
	bool var$1 = !isPartial();
	bool var$0 = var$1 && !isConstructor();
	return var$0 && !"<clinit>"_s->equals(this->name);
}

$Class* Class$EnclosingMethodInfo::getEnclosingClass() {
	return this->enclosingClass;
}

$String* Class$EnclosingMethodInfo::getName() {
	return this->name;
}

$String* Class$EnclosingMethodInfo::getDescriptor() {
	return this->descriptor;
}

void clinit$Class$EnclosingMethodInfo($Class* class$) {
	Class$EnclosingMethodInfo::$assertionsDisabled = !$Class::class$->desiredAssertionStatus();
}

Class$EnclosingMethodInfo::Class$EnclosingMethodInfo() {
}

$Class* Class$EnclosingMethodInfo::load$($String* name, bool initialize) {
	$loadClass(Class$EnclosingMethodInfo, name, initialize, &_Class$EnclosingMethodInfo_ClassInfo_, clinit$Class$EnclosingMethodInfo, allocate$Class$EnclosingMethodInfo);
	return class$;
}

$Class* Class$EnclosingMethodInfo::class$ = nullptr;

	} // lang
} // java