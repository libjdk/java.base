#include <util/ClassSupplier.h>

#include <java/lang/ClassNotFoundException.h>
#include <java/lang/Enum.h>
#include <java/lang/Error.h>
#include <java/lang/NoClassDefFoundError.h>
#include <jcpp.h>

#undef PACKAGE_CLASS_IN_PKG_A
#undef PACKAGE_CLASS_IN_PKG_B
#undef PUBLIC_SUBCLASS_IN_PKG_B
#undef PUBLIC_SUPERCLASS_IN_PKG_A

using $ClassSupplierArray = $Array<::util::ClassSupplier>;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Enum = ::java::lang::Enum;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoClassDefFoundError = ::java::lang::NoClassDefFoundError;

namespace util {

$FieldInfo _ClassSupplier_FieldInfo_[] = {
	{"PACKAGE_CLASS_IN_PKG_A", "Lutil/ClassSupplier;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(ClassSupplier, PACKAGE_CLASS_IN_PKG_A)},
	{"PUBLIC_SUPERCLASS_IN_PKG_A", "Lutil/ClassSupplier;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(ClassSupplier, PUBLIC_SUPERCLASS_IN_PKG_A)},
	{"PACKAGE_CLASS_IN_PKG_B", "Lutil/ClassSupplier;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(ClassSupplier, PACKAGE_CLASS_IN_PKG_B)},
	{"PUBLIC_SUBCLASS_IN_PKG_B", "Lutil/ClassSupplier;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(ClassSupplier, PUBLIC_SUBCLASS_IN_PKG_B)},
	{"$VALUES", "[Lutil/ClassSupplier;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(ClassSupplier, $VALUES)},
	{"className", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(ClassSupplier, className)},
	{}
};

$MethodInfo _ClassSupplier_MethodInfo_[] = {
	{"$values", "()[Lutil/ClassSupplier;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ClassSupplier, $values, $ClassSupplierArray*)},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $FINAL},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL},
	{"*finalize", "()V", nullptr, $PROTECTED | $FINAL},
	{"*hashCode", "()I", nullptr, $PUBLIC | $FINAL},
	{"<init>", "(Ljava/lang/String;ILjava/lang/String;)V", "(Ljava/lang/String;)V", $PRIVATE, $method(ClassSupplier, init$, void, $String*, int32_t, $String*)},
	{"get", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PUBLIC, $virtualMethod(ClassSupplier, get, $Object*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"valueOf", "(Ljava/lang/String;)Lutil/ClassSupplier;", nullptr, $PUBLIC | $STATIC, $staticMethod(ClassSupplier, valueOf, ClassSupplier*, $String*)},
	{"values", "()[Lutil/ClassSupplier;", nullptr, $PUBLIC | $STATIC, $staticMethod(ClassSupplier, values, $ClassSupplierArray*)},
	{}
};

$ClassInfo _ClassSupplier_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER | $ENUM,
	"util.ClassSupplier",
	"java.lang.Enum",
	"java.util.function.Supplier",
	_ClassSupplier_FieldInfo_,
	_ClassSupplier_MethodInfo_,
	"Ljava/lang/Enum<Lutil/ClassSupplier;>;Ljava/util/function/Supplier<Ljava/lang/Class<*>;>;"
};

$Object* allocate$ClassSupplier($Class* clazz) {
	return $of($alloc(ClassSupplier));
}

$String* ClassSupplier::toString() {
	 return this->$Enum::toString();
}

bool ClassSupplier::equals(Object$* arg0) {
	 return this->$Enum::equals(arg0);
}

int32_t ClassSupplier::hashCode() {
	 return this->$Enum::hashCode();
}

$Object* ClassSupplier::clone() {
	 return this->$Enum::clone();
}

void ClassSupplier::finalize() {
	this->$Enum::finalize();
}

ClassSupplier* ClassSupplier::PACKAGE_CLASS_IN_PKG_A = nullptr;
ClassSupplier* ClassSupplier::PUBLIC_SUPERCLASS_IN_PKG_A = nullptr;
ClassSupplier* ClassSupplier::PACKAGE_CLASS_IN_PKG_B = nullptr;
ClassSupplier* ClassSupplier::PUBLIC_SUBCLASS_IN_PKG_B = nullptr;
$ClassSupplierArray* ClassSupplier::$VALUES = nullptr;

$ClassSupplierArray* ClassSupplier::$values() {
	$init(ClassSupplier);
	return $new($ClassSupplierArray, {
		ClassSupplier::PACKAGE_CLASS_IN_PKG_A,
		ClassSupplier::PUBLIC_SUPERCLASS_IN_PKG_A,
		ClassSupplier::PACKAGE_CLASS_IN_PKG_B,
		ClassSupplier::PUBLIC_SUBCLASS_IN_PKG_B
	});
}

$ClassSupplierArray* ClassSupplier::values() {
	$init(ClassSupplier);
	return $cast($ClassSupplierArray, ClassSupplier::$VALUES->clone());
}

ClassSupplier* ClassSupplier::valueOf($String* name) {
	$init(ClassSupplier);
	return $cast(ClassSupplier, $Enum::valueOf(ClassSupplier::class$, name));
}

void ClassSupplier::init$($String* $enum$name, int32_t $enum$ordinal, $String* className) {
	$Enum::init$($enum$name, $enum$ordinal);
	$set(this, className, className);
}

$Object* ClassSupplier::get() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		return $of($Class::forName(this->className));
	} catch ($ClassNotFoundException& e) {
		$throw($cast($Error, $($$new($NoClassDefFoundError, this->className)->initCause(e))));
	}
	$shouldNotReachHere();
}

void clinit$ClassSupplier($Class* class$) {
	$assignStatic(ClassSupplier::PACKAGE_CLASS_IN_PKG_A, $new(ClassSupplier, "PACKAGE_CLASS_IN_PKG_A"_s, 0, "a.Package"_s));
	$assignStatic(ClassSupplier::PUBLIC_SUPERCLASS_IN_PKG_A, $new(ClassSupplier, "PUBLIC_SUPERCLASS_IN_PKG_A"_s, 1, "a.PublicSuper"_s));
	$assignStatic(ClassSupplier::PACKAGE_CLASS_IN_PKG_B, $new(ClassSupplier, "PACKAGE_CLASS_IN_PKG_B"_s, 2, "b.Package"_s));
	$assignStatic(ClassSupplier::PUBLIC_SUBCLASS_IN_PKG_B, $new(ClassSupplier, "PUBLIC_SUBCLASS_IN_PKG_B"_s, 3, "b.PublicSub"_s));
	$assignStatic(ClassSupplier::$VALUES, ClassSupplier::$values());
}

ClassSupplier::ClassSupplier() {
}

$Class* ClassSupplier::load$($String* name, bool initialize) {
	$loadClass(ClassSupplier, name, initialize, &_ClassSupplier_ClassInfo_, clinit$ClassSupplier, allocate$ClassSupplier);
	return class$;
}

$Class* ClassSupplier::class$ = nullptr;

} // util