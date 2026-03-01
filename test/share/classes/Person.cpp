#include <Person.h>

#include <java/lang/Record.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/runtime/ObjectMethods.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Record = ::java::lang::Record;

$FieldInfo _Person_FieldInfo_[] = {
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Person, name$)},
	{"age", "I", nullptr, $PRIVATE | $FINAL, $field(Person, age$)},
	{"d", "D", nullptr, $PRIVATE | $FINAL, $field(Person, d$)},
	{}
};

$MethodInfo _Person_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;ID)V", nullptr, 0, $method(Person, init$, void, $String*, int32_t, double)},
	{"age", "()I", nullptr, $PUBLIC, $method(Person, age, int32_t)},
	{"d", "()D", nullptr, $PUBLIC, $method(Person, d, double)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(Person, equals, bool, Object$*)},
	{"hashCode", "()I", nullptr, $PUBLIC | $FINAL, $virtualMethod(Person, hashCode, int32_t)},
	{"name", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(Person, name, $String*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $virtualMethod(Person, toString, $String*)},
	{}
};

$ClassInfo _Person_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"Person",
	"java.lang.Record",
	nullptr,
	_Person_FieldInfo_,
	_Person_MethodInfo_
};

$Object* allocate$Person($Class* clazz) {
	return $of($alloc(Person));
}

void Person::init$($String* name, int32_t age, double d) {
	$Record::init$();
	$set(this, name$, name);
	this->age$ = age;
	this->d$ = d;
}

$String* Person::name() {
	return this->name$;
}

int32_t Person::age() {
	return this->age$;
}

double Person::d() {
	return this->d$;
}

$String* Person::toString() {
	return Person::class$->bootstrapToString(this);
}

int32_t Person::hashCode() {
	return Person::class$->bootstrapHashCode(this);
}

bool Person::equals(Object$* o) {
	return Person::class$->bootstrapEquals(this, o);
}

Person::Person() {
}

$Class* Person::load$($String* name, bool initialize) {
	$loadClass(Person, name, initialize, &_Person_ClassInfo_, allocate$Person);
	return class$;
}

$Class* Person::class$ = nullptr;