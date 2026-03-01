#include <java/lang/reflect/UndeclaredThrowableException.h>

#include <java/io/ObjectInputStream$GetField.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream$PutField.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/ObjectStreamField.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jcpp.h>

using $ObjectStreamFieldArray = $Array<::java::io::ObjectStreamField>;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectInputStream$GetField = ::java::io::ObjectInputStream$GetField;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ObjectOutputStream$PutField = ::java::io::ObjectOutputStream$PutField;
using $ObjectStreamField = ::java::io::ObjectStreamField;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;

namespace java {
	namespace lang {
		namespace reflect {

$FieldInfo _UndeclaredThrowableException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(UndeclaredThrowableException, serialVersionUID)},
	{"serialPersistentFields", "[Ljava/io/ObjectStreamField;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UndeclaredThrowableException, serialPersistentFields)},
	{}
};

$MethodInfo _UndeclaredThrowableException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $method(UndeclaredThrowableException, init$, void, $Throwable*)},
	{"<init>", "(Ljava/lang/Throwable;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(UndeclaredThrowableException, init$, void, $Throwable*, $String*)},
	{"getUndeclaredThrowable", "()Ljava/lang/Throwable;", nullptr, $PUBLIC, $virtualMethod(UndeclaredThrowableException, getUndeclaredThrowable, $Throwable*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(UndeclaredThrowableException, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(UndeclaredThrowableException, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$ClassInfo _UndeclaredThrowableException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.lang.reflect.UndeclaredThrowableException",
	"java.lang.RuntimeException",
	nullptr,
	_UndeclaredThrowableException_FieldInfo_,
	_UndeclaredThrowableException_MethodInfo_
};

$Object* allocate$UndeclaredThrowableException($Class* clazz) {
	return $of($alloc(UndeclaredThrowableException));
}

$ObjectStreamFieldArray* UndeclaredThrowableException::serialPersistentFields = nullptr;

void UndeclaredThrowableException::init$($Throwable* undeclaredThrowable) {
	$RuntimeException::init$(nullptr, undeclaredThrowable);
}

void UndeclaredThrowableException::init$($Throwable* undeclaredThrowable, $String* s) {
	$RuntimeException::init$(s, undeclaredThrowable);
}

$Throwable* UndeclaredThrowableException::getUndeclaredThrowable() {
	return $RuntimeException::getCause();
}

void UndeclaredThrowableException::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectInputStream$GetField, fields, $nc(s)->readFields());
	$var($Throwable, exception, $cast($Throwable, $nc(fields)->get("undeclaredThrowable"_s, ($Object*)nullptr)));
	if (exception != nullptr) {
		$nc($($SharedSecrets::getJavaLangAccess()))->setCause(this, exception);
	}
}

void UndeclaredThrowableException::writeObject($ObjectOutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectOutputStream$PutField, fields, $nc(out)->putFields());
	$nc(fields)->put("undeclaredThrowable"_s, $($of($RuntimeException::getCause())));
	out->writeFields();
}

void clinit$UndeclaredThrowableException($Class* class$) {
	$assignStatic(UndeclaredThrowableException::serialPersistentFields, $new($ObjectStreamFieldArray, {$$new($ObjectStreamField, "undeclaredThrowable"_s, $Throwable::class$)}));
}

UndeclaredThrowableException::UndeclaredThrowableException() {
}

UndeclaredThrowableException::UndeclaredThrowableException(const UndeclaredThrowableException& e) : $RuntimeException(e) {
}

void UndeclaredThrowableException::throw$() {
	throw *this;
}

$Class* UndeclaredThrowableException::load$($String* name, bool initialize) {
	$loadClass(UndeclaredThrowableException, name, initialize, &_UndeclaredThrowableException_ClassInfo_, clinit$UndeclaredThrowableException, allocate$UndeclaredThrowableException);
	return class$;
}

$Class* UndeclaredThrowableException::class$ = nullptr;

		} // reflect
	} // lang
} // java