#include <jdk/internal/org/objectweb/asm/commons/Method.h>

#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <jdk/internal/org/objectweb/asm/Type.h>
#include <jcpp.h>

#undef PRIMITIVE_TYPE_DESCRIPTORS

using $TypeArray = $Array<::jdk::internal::org::objectweb::asm$::Type>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Constructor = ::java::lang::reflect::Constructor;
using $Method = ::java::lang::reflect::Method;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $Type = ::jdk::internal::org::objectweb::asm$::Type;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace commons {

$FieldInfo _Method_FieldInfo_[] = {
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Method, name)},
	{"descriptor", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Method, descriptor)},
	{"PRIMITIVE_TYPE_DESCRIPTORS", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Method, PRIMITIVE_TYPE_DESCRIPTORS)},
	{}
};

$MethodInfo _Method_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(Method, init$, void, $String*, $String*)},
	{"<init>", "(Ljava/lang/String;Ljdk/internal/org/objectweb/asm/Type;[Ljdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $method(Method, init$, void, $String*, $Type*, $TypeArray*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Method, equals, bool, Object$*)},
	{"getArgumentTypes", "()[Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PUBLIC, $virtualMethod(Method, getArgumentTypes, $TypeArray*)},
	{"getDescriptor", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Method, getDescriptor, $String*)},
	{"getDescriptorInternal", "(Ljava/lang/String;Z)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Method, getDescriptorInternal, $String*, $String*, bool)},
	{"getMethod", "(Ljava/lang/reflect/Method;)Ljdk/internal/org/objectweb/asm/commons/Method;", nullptr, $PUBLIC | $STATIC, $staticMethod(Method, getMethod, Method*, $Method*)},
	{"getMethod", "(Ljava/lang/reflect/Constructor;)Ljdk/internal/org/objectweb/asm/commons/Method;", "(Ljava/lang/reflect/Constructor<*>;)Ljdk/internal/org/objectweb/asm/commons/Method;", $PUBLIC | $STATIC, $staticMethod(Method, getMethod, Method*, $Constructor*)},
	{"getMethod", "(Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/commons/Method;", nullptr, $PUBLIC | $STATIC, $staticMethod(Method, getMethod, Method*, $String*)},
	{"getMethod", "(Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/commons/Method;", nullptr, $PUBLIC | $STATIC, $staticMethod(Method, getMethod, Method*, $String*, bool)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Method, getName, $String*)},
	{"getReturnType", "()Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PUBLIC, $virtualMethod(Method, getReturnType, $Type*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(Method, hashCode, int32_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Method, toString, $String*)},
	{}
};

$ClassInfo _Method_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.commons.Method",
	"java.lang.Object",
	nullptr,
	_Method_FieldInfo_,
	_Method_MethodInfo_
};

$Object* allocate$Method($Class* clazz) {
	return $of($alloc(Method));
}

$Map* Method::PRIMITIVE_TYPE_DESCRIPTORS = nullptr;

void Method::init$($String* name, $String* descriptor) {
	$set(this, name, name);
	$set(this, descriptor, descriptor);
}

void Method::init$($String* name, $Type* returnType, $TypeArray* argumentTypes) {
	Method::init$(name, $($Type::getMethodDescriptor(returnType, argumentTypes)));
}

Method* Method::getMethod($Method* method) {
	$init(Method);
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $nc(method)->getName());
	return $new(Method, var$0, $($Type::getMethodDescriptor(method)));
}

Method* Method::getMethod($Constructor* constructor) {
	$init(Method);
	return $new(Method, "<init>"_s, $($Type::getConstructorDescriptor(constructor)));
}

Method* Method::getMethod($String* method) {
	$init(Method);
	return getMethod(method, false);
}

Method* Method::getMethod($String* method, bool defaultPackage) {
	$init(Method);
	$useLocalCurrentObjectStackCache();
	int32_t spaceIndex = $nc(method)->indexOf((int32_t)u' ');
	int32_t currentArgumentStartIndex = method->indexOf((int32_t)u'(', spaceIndex) + 1;
	int32_t endIndex = method->indexOf((int32_t)u')', currentArgumentStartIndex);
	if (spaceIndex == -1 || currentArgumentStartIndex == 0 || endIndex == -1) {
		$throwNew($IllegalArgumentException);
	}
	$var($String, returnType, method->substring(0, spaceIndex));
	$var($String, methodName, $(method->substring(spaceIndex + 1, currentArgumentStartIndex - 1))->trim());
	$var($StringBuilder, stringBuilder, $new($StringBuilder));
	stringBuilder->append(u'(');
	int32_t currentArgumentEndIndex = 0;
	do {
		$var($String, argumentDescriptor, nullptr);
		currentArgumentEndIndex = method->indexOf((int32_t)u',', currentArgumentStartIndex);
		if (currentArgumentEndIndex == -1) {
			$assign(argumentDescriptor, getDescriptorInternal($($(method->substring(currentArgumentStartIndex, endIndex))->trim()), defaultPackage));
		} else {
			$assign(argumentDescriptor, getDescriptorInternal($($(method->substring(currentArgumentStartIndex, currentArgumentEndIndex))->trim()), defaultPackage));
			currentArgumentStartIndex = currentArgumentEndIndex + 1;
		}
		stringBuilder->append(argumentDescriptor);
	} while (currentArgumentEndIndex != -1);
	stringBuilder->append(u')')->append($(getDescriptorInternal(returnType, defaultPackage)));
	return $new(Method, methodName, $(stringBuilder->toString()));
}

$String* Method::getDescriptorInternal($String* type, bool defaultPackage) {
	$init(Method);
	$useLocalCurrentObjectStackCache();
	if (""_s->equals(type)) {
		return type;
	}
	$var($StringBuilder, stringBuilder, $new($StringBuilder));
	int32_t arrayBracketsIndex = 0;
	while ((arrayBracketsIndex = $nc(type)->indexOf("[]"_s, arrayBracketsIndex) + 1) > 0) {
		stringBuilder->append(u'[');
	}
	int32_t var$0 = type->length();
	$var($String, elementType, $nc(type)->substring(0, var$0 - stringBuilder->length() * 2));
	$var($String, descriptor, $cast($String, $nc(Method::PRIMITIVE_TYPE_DESCRIPTORS)->get(elementType)));
	if (descriptor != nullptr) {
		stringBuilder->append(descriptor);
	} else {
		stringBuilder->append(u'L');
		if (elementType->indexOf((int32_t)u'.') < 0) {
			if (!defaultPackage) {
				stringBuilder->append("java/lang/"_s);
			}
			stringBuilder->append(elementType);
		} else {
			stringBuilder->append($(elementType->replace(u'.', u'/')));
		}
		stringBuilder->append(u';');
	}
	return stringBuilder->toString();
}

$String* Method::getName() {
	return this->name;
}

$String* Method::getDescriptor() {
	return this->descriptor;
}

$Type* Method::getReturnType() {
	return $Type::getReturnType(this->descriptor);
}

$TypeArray* Method::getArgumentTypes() {
	return $Type::getArgumentTypes(this->descriptor);
}

$String* Method::toString() {
	return $str({this->name, this->descriptor});
}

bool Method::equals(Object$* other) {
	if (!($instanceOf(Method, other))) {
		return false;
	}
	$var(Method, otherMethod, $cast(Method, other));
	bool var$0 = $nc(this->name)->equals($nc(otherMethod)->name);
	return var$0 && $nc(this->descriptor)->equals($nc(otherMethod)->descriptor);
}

int32_t Method::hashCode() {
	int32_t var$0 = $nc(this->name)->hashCode();
	return var$0 ^ $nc(this->descriptor)->hashCode();
}

void clinit$Method($Class* class$) {
	{
		$var($HashMap, descriptors, $new($HashMap));
		descriptors->put("void"_s, "V"_s);
		descriptors->put("byte"_s, "B"_s);
		descriptors->put("char"_s, "C"_s);
		descriptors->put("double"_s, "D"_s);
		descriptors->put("float"_s, "F"_s);
		descriptors->put("int"_s, "I"_s);
		descriptors->put("long"_s, "J"_s);
		descriptors->put("short"_s, "S"_s);
		descriptors->put("boolean"_s, "Z"_s);
		$assignStatic(Method::PRIMITIVE_TYPE_DESCRIPTORS, descriptors);
	}
}

Method::Method() {
}

$Class* Method::load$($String* name, bool initialize) {
	$loadClass(Method, name, initialize, &_Method_ClassInfo_, clinit$Method, allocate$Method);
	return class$;
}

$Class* Method::class$ = nullptr;

					} // commons
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk