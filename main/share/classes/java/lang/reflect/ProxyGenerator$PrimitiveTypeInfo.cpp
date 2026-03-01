#include <java/lang/reflect/ProxyGenerator$PrimitiveTypeInfo.h>

#include <java/lang/AssertionError.h>
#include <java/lang/reflect/Array.h>
#include <java/lang/reflect/ProxyGenerator.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <jcpp.h>

#undef TYPE

using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Short = ::java::lang::Short;
using $1Array = ::java::lang::reflect::Array;
using $ProxyGenerator = ::java::lang::reflect::ProxyGenerator;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;

namespace java {
	namespace lang {
		namespace reflect {

$FieldInfo _ProxyGenerator$PrimitiveTypeInfo_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ProxyGenerator$PrimitiveTypeInfo, $assertionsDisabled)},
	{"table", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Class<*>;Ljava/lang/reflect/ProxyGenerator$PrimitiveTypeInfo;>;", $PRIVATE | $STATIC, $staticField(ProxyGenerator$PrimitiveTypeInfo, table)},
	{"wrapperClassName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(ProxyGenerator$PrimitiveTypeInfo, wrapperClassName)},
	{"wrapperValueOfDesc", "Ljava/lang/String;", nullptr, $PRIVATE, $field(ProxyGenerator$PrimitiveTypeInfo, wrapperValueOfDesc)},
	{"unwrapMethodName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(ProxyGenerator$PrimitiveTypeInfo, unwrapMethodName)},
	{"unwrapMethodDesc", "Ljava/lang/String;", nullptr, $PRIVATE, $field(ProxyGenerator$PrimitiveTypeInfo, unwrapMethodDesc)},
	{}
};

$MethodInfo _ProxyGenerator$PrimitiveTypeInfo_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Class;Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)V", $PRIVATE, $method(ProxyGenerator$PrimitiveTypeInfo, init$, void, $Class*, $Class*)},
	{"add", "(Ljava/lang/Class;Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)V", $PRIVATE | $STATIC, $staticMethod(ProxyGenerator$PrimitiveTypeInfo, add, void, $Class*, $Class*)},
	{"get", "(Ljava/lang/Class;)Ljava/lang/reflect/ProxyGenerator$PrimitiveTypeInfo;", "(Ljava/lang/Class<*>;)Ljava/lang/reflect/ProxyGenerator$PrimitiveTypeInfo;", $PUBLIC | $STATIC, $staticMethod(ProxyGenerator$PrimitiveTypeInfo, get, ProxyGenerator$PrimitiveTypeInfo*, $Class*)},
	{}
};

$InnerClassInfo _ProxyGenerator$PrimitiveTypeInfo_InnerClassesInfo_[] = {
	{"java.lang.reflect.ProxyGenerator$PrimitiveTypeInfo", "java.lang.reflect.ProxyGenerator", "PrimitiveTypeInfo", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _ProxyGenerator$PrimitiveTypeInfo_ClassInfo_ = {
	$ACC_SUPER,
	"java.lang.reflect.ProxyGenerator$PrimitiveTypeInfo",
	"java.lang.Object",
	nullptr,
	_ProxyGenerator$PrimitiveTypeInfo_FieldInfo_,
	_ProxyGenerator$PrimitiveTypeInfo_MethodInfo_,
	nullptr,
	nullptr,
	_ProxyGenerator$PrimitiveTypeInfo_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.reflect.ProxyGenerator"
};

$Object* allocate$ProxyGenerator$PrimitiveTypeInfo($Class* clazz) {
	return $of($alloc(ProxyGenerator$PrimitiveTypeInfo));
}

bool ProxyGenerator$PrimitiveTypeInfo::$assertionsDisabled = false;
$Map* ProxyGenerator$PrimitiveTypeInfo::table = nullptr;

void ProxyGenerator$PrimitiveTypeInfo::init$($Class* primitiveClass, $Class* wrapperClass) {
	$useLocalCurrentObjectStackCache();
	if (!ProxyGenerator$PrimitiveTypeInfo::$assertionsDisabled && !$nc(primitiveClass)->isPrimitive()) {
		$throwNew($AssertionError);
	}
	$var($String, baseTypeString, $nc($($of($($1Array::newInstance(primitiveClass, 0)))->getClass()->getName()))->substring(1));
	$set(this, wrapperClassName, $ProxyGenerator::dotToSlash($($nc(wrapperClass)->getName())));
	$set(this, wrapperValueOfDesc, $str({"("_s, baseTypeString, ")L"_s, this->wrapperClassName, ";"_s}));
	$set(this, unwrapMethodName, $str({$($nc(primitiveClass)->getName()), "Value"_s}));
	$set(this, unwrapMethodDesc, $str({"()"_s, baseTypeString}));
}

void ProxyGenerator$PrimitiveTypeInfo::add($Class* primitiveClass, $Class* wrapperClass) {
	$init(ProxyGenerator$PrimitiveTypeInfo);
	$nc(ProxyGenerator$PrimitiveTypeInfo::table)->put(primitiveClass, $$new(ProxyGenerator$PrimitiveTypeInfo, primitiveClass, wrapperClass));
}

ProxyGenerator$PrimitiveTypeInfo* ProxyGenerator$PrimitiveTypeInfo::get($Class* cl) {
	$init(ProxyGenerator$PrimitiveTypeInfo);
	return $cast(ProxyGenerator$PrimitiveTypeInfo, $nc(ProxyGenerator$PrimitiveTypeInfo::table)->get(cl));
}

void clinit$ProxyGenerator$PrimitiveTypeInfo($Class* class$) {
	$load($ProxyGenerator);
	ProxyGenerator$PrimitiveTypeInfo::$assertionsDisabled = !$ProxyGenerator::class$->desiredAssertionStatus();
	$assignStatic(ProxyGenerator$PrimitiveTypeInfo::table, $new($HashMap));
	{
		$init($Byte);
		ProxyGenerator$PrimitiveTypeInfo::add($Byte::TYPE, $Byte::class$);
		$init($Character);
		ProxyGenerator$PrimitiveTypeInfo::add($Character::TYPE, $Character::class$);
		$init($Double);
		ProxyGenerator$PrimitiveTypeInfo::add($Double::TYPE, $Double::class$);
		$init($Float);
		ProxyGenerator$PrimitiveTypeInfo::add($Float::TYPE, $Float::class$);
		$init($Integer);
		ProxyGenerator$PrimitiveTypeInfo::add($Integer::TYPE, $Integer::class$);
		$init($Long);
		ProxyGenerator$PrimitiveTypeInfo::add($Long::TYPE, $Long::class$);
		$init($Short);
		ProxyGenerator$PrimitiveTypeInfo::add($Short::TYPE, $Short::class$);
		$init($Boolean);
		ProxyGenerator$PrimitiveTypeInfo::add($Boolean::TYPE, $Boolean::class$);
	}
}

ProxyGenerator$PrimitiveTypeInfo::ProxyGenerator$PrimitiveTypeInfo() {
}

$Class* ProxyGenerator$PrimitiveTypeInfo::load$($String* name, bool initialize) {
	$loadClass(ProxyGenerator$PrimitiveTypeInfo, name, initialize, &_ProxyGenerator$PrimitiveTypeInfo_ClassInfo_, clinit$ProxyGenerator$PrimitiveTypeInfo, allocate$ProxyGenerator$PrimitiveTypeInfo);
	return class$;
}

$Class* ProxyGenerator$PrimitiveTypeInfo::class$ = nullptr;

		} // reflect
	} // lang
} // java