#include <jdk/internal/org/objectweb/asm/util/TraceSignatureVisitor.h>

#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/signature/SignatureVisitor.h>
#include <jcpp.h>

#undef ACC_INTERFACE
#undef ASM8
#undef BASE_TYPES
#undef COMMA_SEPARATOR
#undef EXTENDS
#undef EXTENDS_SEPARATOR
#undef IMPLEMENTS_SEPARATOR
#undef SUPER

using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $SignatureVisitor = ::jdk::internal::org::objectweb::asm$::signature::SignatureVisitor;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace util {

$FieldInfo _TraceSignatureVisitor_FieldInfo_[] = {
	{"COMMA_SEPARATOR", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TraceSignatureVisitor, COMMA_SEPARATOR)},
	{"EXTENDS_SEPARATOR", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TraceSignatureVisitor, EXTENDS_SEPARATOR)},
	{"IMPLEMENTS_SEPARATOR", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TraceSignatureVisitor, IMPLEMENTS_SEPARATOR)},
	{"BASE_TYPES", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Character;Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(TraceSignatureVisitor, BASE_TYPES)},
	{"isInterface", "Z", nullptr, $PRIVATE | $FINAL, $field(TraceSignatureVisitor, isInterface)},
	{"declaration", "Ljava/lang/StringBuilder;", nullptr, $PRIVATE | $FINAL, $field(TraceSignatureVisitor, declaration)},
	{"returnType", "Ljava/lang/StringBuilder;", nullptr, $PRIVATE, $field(TraceSignatureVisitor, returnType)},
	{"exceptions", "Ljava/lang/StringBuilder;", nullptr, $PRIVATE, $field(TraceSignatureVisitor, exceptions)},
	{"formalTypeParameterVisited", "Z", nullptr, $PRIVATE, $field(TraceSignatureVisitor, formalTypeParameterVisited)},
	{"interfaceBoundVisited", "Z", nullptr, $PRIVATE, $field(TraceSignatureVisitor, interfaceBoundVisited)},
	{"parameterTypeVisited", "Z", nullptr, $PRIVATE, $field(TraceSignatureVisitor, parameterTypeVisited)},
	{"interfaceVisited", "Z", nullptr, $PRIVATE, $field(TraceSignatureVisitor, interfaceVisited)},
	{"argumentStack", "I", nullptr, $PRIVATE, $field(TraceSignatureVisitor, argumentStack)},
	{"arrayStack", "I", nullptr, $PRIVATE, $field(TraceSignatureVisitor, arrayStack)},
	{"separator", "Ljava/lang/String;", nullptr, $PRIVATE, $field(TraceSignatureVisitor, separator)},
	{}
};

$MethodInfo _TraceSignatureVisitor_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(TraceSignatureVisitor, init$, void, int32_t)},
	{"<init>", "(Ljava/lang/StringBuilder;)V", nullptr, $PRIVATE, $method(TraceSignatureVisitor, init$, void, $StringBuilder*)},
	{"endFormals", "()V", nullptr, $PRIVATE, $method(TraceSignatureVisitor, endFormals, void)},
	{"endType", "()V", nullptr, $PRIVATE, $method(TraceSignatureVisitor, endType, void)},
	{"getDeclaration", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(TraceSignatureVisitor, getDeclaration, $String*)},
	{"getExceptions", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(TraceSignatureVisitor, getExceptions, $String*)},
	{"getReturnType", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(TraceSignatureVisitor, getReturnType, $String*)},
	{"startType", "()V", nullptr, $PRIVATE, $method(TraceSignatureVisitor, startType, void)},
	{"visitArrayType", "()Ljdk/internal/org/objectweb/asm/signature/SignatureVisitor;", nullptr, $PUBLIC, $virtualMethod(TraceSignatureVisitor, visitArrayType, $SignatureVisitor*)},
	{"visitBaseType", "(C)V", nullptr, $PUBLIC, $virtualMethod(TraceSignatureVisitor, visitBaseType, void, char16_t)},
	{"visitClassBound", "()Ljdk/internal/org/objectweb/asm/signature/SignatureVisitor;", nullptr, $PUBLIC, $virtualMethod(TraceSignatureVisitor, visitClassBound, $SignatureVisitor*)},
	{"visitClassType", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(TraceSignatureVisitor, visitClassType, void, $String*)},
	{"visitEnd", "()V", nullptr, $PUBLIC, $virtualMethod(TraceSignatureVisitor, visitEnd, void)},
	{"visitExceptionType", "()Ljdk/internal/org/objectweb/asm/signature/SignatureVisitor;", nullptr, $PUBLIC, $virtualMethod(TraceSignatureVisitor, visitExceptionType, $SignatureVisitor*)},
	{"visitFormalTypeParameter", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(TraceSignatureVisitor, visitFormalTypeParameter, void, $String*)},
	{"visitInnerClassType", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(TraceSignatureVisitor, visitInnerClassType, void, $String*)},
	{"visitInterface", "()Ljdk/internal/org/objectweb/asm/signature/SignatureVisitor;", nullptr, $PUBLIC, $virtualMethod(TraceSignatureVisitor, visitInterface, $SignatureVisitor*)},
	{"visitInterfaceBound", "()Ljdk/internal/org/objectweb/asm/signature/SignatureVisitor;", nullptr, $PUBLIC, $virtualMethod(TraceSignatureVisitor, visitInterfaceBound, $SignatureVisitor*)},
	{"visitParameterType", "()Ljdk/internal/org/objectweb/asm/signature/SignatureVisitor;", nullptr, $PUBLIC, $virtualMethod(TraceSignatureVisitor, visitParameterType, $SignatureVisitor*)},
	{"visitReturnType", "()Ljdk/internal/org/objectweb/asm/signature/SignatureVisitor;", nullptr, $PUBLIC, $virtualMethod(TraceSignatureVisitor, visitReturnType, $SignatureVisitor*)},
	{"visitSuperclass", "()Ljdk/internal/org/objectweb/asm/signature/SignatureVisitor;", nullptr, $PUBLIC, $virtualMethod(TraceSignatureVisitor, visitSuperclass, $SignatureVisitor*)},
	{"visitTypeArgument", "()V", nullptr, $PUBLIC, $virtualMethod(TraceSignatureVisitor, visitTypeArgument, void)},
	{"visitTypeArgument", "(C)Ljdk/internal/org/objectweb/asm/signature/SignatureVisitor;", nullptr, $PUBLIC, $virtualMethod(TraceSignatureVisitor, visitTypeArgument, $SignatureVisitor*, char16_t)},
	{"visitTypeVariable", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(TraceSignatureVisitor, visitTypeVariable, void, $String*)},
	{}
};

$ClassInfo _TraceSignatureVisitor_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.util.TraceSignatureVisitor",
	"jdk.internal.org.objectweb.asm.signature.SignatureVisitor",
	nullptr,
	_TraceSignatureVisitor_FieldInfo_,
	_TraceSignatureVisitor_MethodInfo_
};

$Object* allocate$TraceSignatureVisitor($Class* clazz) {
	return $of($alloc(TraceSignatureVisitor));
}

$String* TraceSignatureVisitor::COMMA_SEPARATOR = nullptr;
$String* TraceSignatureVisitor::EXTENDS_SEPARATOR = nullptr;
$String* TraceSignatureVisitor::IMPLEMENTS_SEPARATOR = nullptr;
$Map* TraceSignatureVisitor::BASE_TYPES = nullptr;

void TraceSignatureVisitor::init$(int32_t accessFlags) {
	$SignatureVisitor::init$($Opcodes::ASM8);
	$set(this, separator, ""_s);
	this->isInterface = ((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_INTERFACE)) != 0;
	$set(this, declaration, $new($StringBuilder));
}

void TraceSignatureVisitor::init$($StringBuilder* stringBuilder) {
	$SignatureVisitor::init$($Opcodes::ASM8);
	$set(this, separator, ""_s);
	this->isInterface = false;
	$set(this, declaration, stringBuilder);
}

void TraceSignatureVisitor::visitFormalTypeParameter($String* name) {
	$nc(this->declaration)->append(this->formalTypeParameterVisited ? TraceSignatureVisitor::COMMA_SEPARATOR : "<"_s)->append(name);
	this->formalTypeParameterVisited = true;
	this->interfaceBoundVisited = false;
}

$SignatureVisitor* TraceSignatureVisitor::visitClassBound() {
	$set(this, separator, TraceSignatureVisitor::EXTENDS_SEPARATOR);
	startType();
	return this;
}

$SignatureVisitor* TraceSignatureVisitor::visitInterfaceBound() {
	$set(this, separator, this->interfaceBoundVisited ? TraceSignatureVisitor::COMMA_SEPARATOR : TraceSignatureVisitor::EXTENDS_SEPARATOR);
	this->interfaceBoundVisited = true;
	startType();
	return this;
}

$SignatureVisitor* TraceSignatureVisitor::visitSuperclass() {
	endFormals();
	$set(this, separator, TraceSignatureVisitor::EXTENDS_SEPARATOR);
	startType();
	return this;
}

$SignatureVisitor* TraceSignatureVisitor::visitInterface() {
	if (this->interfaceVisited) {
		$set(this, separator, TraceSignatureVisitor::COMMA_SEPARATOR);
	} else {
		$set(this, separator, this->isInterface ? TraceSignatureVisitor::EXTENDS_SEPARATOR : TraceSignatureVisitor::IMPLEMENTS_SEPARATOR);
		this->interfaceVisited = true;
	}
	startType();
	return this;
}

$SignatureVisitor* TraceSignatureVisitor::visitParameterType() {
	endFormals();
	if (this->parameterTypeVisited) {
		$nc(this->declaration)->append(TraceSignatureVisitor::COMMA_SEPARATOR);
	} else {
		$nc(this->declaration)->append(u'(');
		this->parameterTypeVisited = true;
	}
	startType();
	return this;
}

$SignatureVisitor* TraceSignatureVisitor::visitReturnType() {
	endFormals();
	if (this->parameterTypeVisited) {
		this->parameterTypeVisited = false;
	} else {
		$nc(this->declaration)->append(u'(');
	}
	$nc(this->declaration)->append(u')');
	$set(this, returnType, $new($StringBuilder));
	return $new(TraceSignatureVisitor, this->returnType);
}

$SignatureVisitor* TraceSignatureVisitor::visitExceptionType() {
	if (this->exceptions == nullptr) {
		$set(this, exceptions, $new($StringBuilder));
	} else {
		$nc(this->exceptions)->append(TraceSignatureVisitor::COMMA_SEPARATOR);
	}
	return $new(TraceSignatureVisitor, this->exceptions);
}

void TraceSignatureVisitor::visitBaseType(char16_t descriptor) {
	$useLocalCurrentObjectStackCache();
	$var($String, baseType, $cast($String, $nc(TraceSignatureVisitor::BASE_TYPES)->get($($Character::valueOf(descriptor)))));
	if (baseType == nullptr) {
		$throwNew($IllegalArgumentException);
	}
	$nc(this->declaration)->append(baseType);
	endType();
}

void TraceSignatureVisitor::visitTypeVariable($String* name) {
	$nc(this->declaration)->append(this->separator)->append(name);
	$set(this, separator, ""_s);
	endType();
}

$SignatureVisitor* TraceSignatureVisitor::visitArrayType() {
	startType();
	this->arrayStack |= 1;
	return this;
}

void TraceSignatureVisitor::visitClassType($String* name) {
	$useLocalCurrentObjectStackCache();
	if ("java/lang/Object"_s->equals(name)) {
		bool needObjectClass = this->argumentStack % 2 != 0 || this->parameterTypeVisited;
		if (needObjectClass) {
			$nc(this->declaration)->append(this->separator)->append($($nc(name)->replace(u'/', u'.')));
		}
	} else {
		$nc(this->declaration)->append(this->separator)->append($($nc(name)->replace(u'/', u'.')));
	}
	$set(this, separator, ""_s);
	this->argumentStack *= 2;
}

void TraceSignatureVisitor::visitInnerClassType($String* name) {
	if (this->argumentStack % 2 != 0) {
		$nc(this->declaration)->append(u'>');
	}
	this->argumentStack /= 2;
	$nc(this->declaration)->append(u'.');
	$nc(this->declaration)->append(this->separator)->append($($nc(name)->replace(u'/', u'.')));
	$set(this, separator, ""_s);
	this->argumentStack *= 2;
}

void TraceSignatureVisitor::visitTypeArgument() {
	if (this->argumentStack % 2 == 0) {
		++this->argumentStack;
		$nc(this->declaration)->append(u'<');
	} else {
		$nc(this->declaration)->append(TraceSignatureVisitor::COMMA_SEPARATOR);
	}
	$nc(this->declaration)->append(u'?');
}

$SignatureVisitor* TraceSignatureVisitor::visitTypeArgument(char16_t tag) {
	if (this->argumentStack % 2 == 0) {
		++this->argumentStack;
		$nc(this->declaration)->append(u'<');
	} else {
		$nc(this->declaration)->append(TraceSignatureVisitor::COMMA_SEPARATOR);
	}
	if (tag == $SignatureVisitor::EXTENDS) {
		$nc(this->declaration)->append("? extends "_s);
	} else if (tag == $SignatureVisitor::SUPER) {
		$nc(this->declaration)->append("? super "_s);
	}
	startType();
	return this;
}

void TraceSignatureVisitor::visitEnd() {
	if (this->argumentStack % 2 != 0) {
		$nc(this->declaration)->append(u'>');
	}
	this->argumentStack /= 2;
	endType();
}

$String* TraceSignatureVisitor::getDeclaration() {
	return $nc(this->declaration)->toString();
}

$String* TraceSignatureVisitor::getReturnType() {
	return this->returnType == nullptr ? ($String*)nullptr : $nc(this->returnType)->toString();
}

$String* TraceSignatureVisitor::getExceptions() {
	return this->exceptions == nullptr ? ($String*)nullptr : $nc(this->exceptions)->toString();
}

void TraceSignatureVisitor::endFormals() {
	if (this->formalTypeParameterVisited) {
		$nc(this->declaration)->append(u'>');
		this->formalTypeParameterVisited = false;
	}
}

void TraceSignatureVisitor::startType() {
	this->arrayStack *= 2;
}

void TraceSignatureVisitor::endType() {
	if (this->arrayStack % 2 == 0) {
		this->arrayStack /= 2;
	} else {
		while (this->arrayStack % 2 != 0) {
			this->arrayStack /= 2;
			$nc(this->declaration)->append("[]"_s);
		}
	}
}

void clinit$TraceSignatureVisitor($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(TraceSignatureVisitor::COMMA_SEPARATOR, ", "_s);
	$assignStatic(TraceSignatureVisitor::EXTENDS_SEPARATOR, " extends "_s);
	$assignStatic(TraceSignatureVisitor::IMPLEMENTS_SEPARATOR, " implements "_s);
	{
		$var($HashMap, baseTypes, $new($HashMap));
		baseTypes->put($($Character::valueOf(u'Z')), "boolean"_s);
		baseTypes->put($($Character::valueOf(u'B')), "byte"_s);
		baseTypes->put($($Character::valueOf(u'C')), "char"_s);
		baseTypes->put($($Character::valueOf(u'S')), "short"_s);
		baseTypes->put($($Character::valueOf(u'I')), "int"_s);
		baseTypes->put($($Character::valueOf(u'J')), "long"_s);
		baseTypes->put($($Character::valueOf(u'F')), "float"_s);
		baseTypes->put($($Character::valueOf(u'D')), "double"_s);
		baseTypes->put($($Character::valueOf(u'V')), "void"_s);
		$assignStatic(TraceSignatureVisitor::BASE_TYPES, $Collections::unmodifiableMap(baseTypes));
	}
}

TraceSignatureVisitor::TraceSignatureVisitor() {
}

$Class* TraceSignatureVisitor::load$($String* name, bool initialize) {
	$loadClass(TraceSignatureVisitor, name, initialize, &_TraceSignatureVisitor_ClassInfo_, clinit$TraceSignatureVisitor, allocate$TraceSignatureVisitor);
	return class$;
}

$Class* TraceSignatureVisitor::class$ = nullptr;

					} // util
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk