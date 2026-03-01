#include <java/io/ObjectStreamClass$MemberSignature.h>

#include <java/io/ObjectStreamClass.h>
#include <java/io/ObjectStreamField.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/Member.h>
#include <java/lang/reflect/Method.h>
#include <jcpp.h>

#undef TYPE

using $ObjectStreamClass = ::java::io::ObjectStreamClass;
using $ObjectStreamField = ::java::io::ObjectStreamField;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $Constructor = ::java::lang::reflect::Constructor;
using $Field = ::java::lang::reflect::Field;
using $Member = ::java::lang::reflect::Member;
using $Method = ::java::lang::reflect::Method;

namespace java {
	namespace io {

$FieldInfo _ObjectStreamClass$MemberSignature_FieldInfo_[] = {
	{"member", "Ljava/lang/reflect/Member;", nullptr, $PUBLIC | $FINAL, $field(ObjectStreamClass$MemberSignature, member)},
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $field(ObjectStreamClass$MemberSignature, name)},
	{"signature", "Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $field(ObjectStreamClass$MemberSignature, signature)},
	{}
};

$MethodInfo _ObjectStreamClass$MemberSignature_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/reflect/Field;)V", nullptr, $PUBLIC, $method(ObjectStreamClass$MemberSignature, init$, void, $Field*)},
	{"<init>", "(Ljava/lang/reflect/Constructor;)V", "(Ljava/lang/reflect/Constructor<*>;)V", $PUBLIC, $method(ObjectStreamClass$MemberSignature, init$, void, $Constructor*)},
	{"<init>", "(Ljava/lang/reflect/Method;)V", nullptr, $PUBLIC, $method(ObjectStreamClass$MemberSignature, init$, void, $Method*)},
	{}
};

$InnerClassInfo _ObjectStreamClass$MemberSignature_InnerClassesInfo_[] = {
	{"java.io.ObjectStreamClass$MemberSignature", "java.io.ObjectStreamClass", "MemberSignature", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _ObjectStreamClass$MemberSignature_ClassInfo_ = {
	$ACC_SUPER,
	"java.io.ObjectStreamClass$MemberSignature",
	"java.lang.Object",
	nullptr,
	_ObjectStreamClass$MemberSignature_FieldInfo_,
	_ObjectStreamClass$MemberSignature_MethodInfo_,
	nullptr,
	nullptr,
	_ObjectStreamClass$MemberSignature_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.io.ObjectStreamClass"
};

$Object* allocate$ObjectStreamClass$MemberSignature($Class* clazz) {
	return $of($alloc(ObjectStreamClass$MemberSignature));
}

void ObjectStreamClass$MemberSignature::init$($Field* field) {
	$set(this, member, field);
	$set(this, name, $nc(field)->getName());
	$set(this, signature, $ObjectStreamField::getClassSignature(field->getType()));
}

void ObjectStreamClass$MemberSignature::init$($Constructor* cons) {
	$set(this, member, cons);
	$set(this, name, $nc(cons)->getName());
	$init($Void);
	$set(this, signature, $ObjectStreamClass::getMethodSignature($(cons->getParameterTypes()), $Void::TYPE));
}

void ObjectStreamClass$MemberSignature::init$($Method* meth) {
	$set(this, member, meth);
	$set(this, name, $nc(meth)->getName());
	$var($ClassArray, var$0, meth->getParameterTypes());
	$set(this, signature, $ObjectStreamClass::getMethodSignature(var$0, meth->getReturnType()));
}

ObjectStreamClass$MemberSignature::ObjectStreamClass$MemberSignature() {
}

$Class* ObjectStreamClass$MemberSignature::load$($String* name, bool initialize) {
	$loadClass(ObjectStreamClass$MemberSignature, name, initialize, &_ObjectStreamClass$MemberSignature_ClassInfo_, allocate$ObjectStreamClass$MemberSignature);
	return class$;
}

$Class* ObjectStreamClass$MemberSignature::class$ = nullptr;

	} // io
} // java