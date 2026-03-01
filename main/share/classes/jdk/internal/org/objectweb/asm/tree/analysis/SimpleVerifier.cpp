#include <jdk/internal/org/objectweb/asm/tree/analysis/SimpleVerifier.h>

#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/TypeNotPresentException.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/Type.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/BasicInterpreter.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/BasicValue.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/BasicVerifier.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/Value.h>
#include <jcpp.h>

#undef ARRAY
#undef ASM8
#undef BOOLEAN
#undef BYTE
#undef CHAR
#undef DOUBLE
#undef FLOAT
#undef INT
#undef LONG
#undef NULL_TYPE
#undef OBJECT
#undef REFERENCE_VALUE
#undef SHORT
#undef UNINITIALIZED_VALUE

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $MethodInfo = ::java::lang::MethodInfo;
using $TypeNotPresentException = ::java::lang::TypeNotPresentException;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $Type = ::jdk::internal::org::objectweb::asm$::Type;
using $BasicInterpreter = ::jdk::internal::org::objectweb::asm$::tree::analysis::BasicInterpreter;
using $BasicValue = ::jdk::internal::org::objectweb::asm$::tree::analysis::BasicValue;
using $BasicVerifier = ::jdk::internal::org::objectweb::asm$::tree::analysis::BasicVerifier;
using $1Value = ::jdk::internal::org::objectweb::asm$::tree::analysis::Value;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace tree {
						namespace analysis {

$FieldInfo _SimpleVerifier_FieldInfo_[] = {
	{"currentClass", "Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PRIVATE | $FINAL, $field(SimpleVerifier, currentClass)},
	{"currentSuperClass", "Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PRIVATE | $FINAL, $field(SimpleVerifier, currentSuperClass)},
	{"currentClassInterfaces", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/org/objectweb/asm/Type;>;", $PRIVATE | $FINAL, $field(SimpleVerifier, currentClassInterfaces)},
	{"isInterface", "Z", nullptr, $PRIVATE | $FINAL, $field(SimpleVerifier, isInterface$)},
	{"loader", "Ljava/lang/ClassLoader;", nullptr, $PRIVATE, $field(SimpleVerifier, loader)},
	{}
};

$MethodInfo _SimpleVerifier_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SimpleVerifier, init$, void)},
	{"<init>", "(Ljdk/internal/org/objectweb/asm/Type;Ljdk/internal/org/objectweb/asm/Type;Z)V", nullptr, $PUBLIC, $method(SimpleVerifier, init$, void, $Type*, $Type*, bool)},
	{"<init>", "(Ljdk/internal/org/objectweb/asm/Type;Ljdk/internal/org/objectweb/asm/Type;Ljava/util/List;Z)V", "(Ljdk/internal/org/objectweb/asm/Type;Ljdk/internal/org/objectweb/asm/Type;Ljava/util/List<Ljdk/internal/org/objectweb/asm/Type;>;Z)V", $PUBLIC, $method(SimpleVerifier, init$, void, $Type*, $Type*, $List*, bool)},
	{"<init>", "(ILjdk/internal/org/objectweb/asm/Type;Ljdk/internal/org/objectweb/asm/Type;Ljava/util/List;Z)V", "(ILjdk/internal/org/objectweb/asm/Type;Ljdk/internal/org/objectweb/asm/Type;Ljava/util/List<Ljdk/internal/org/objectweb/asm/Type;>;Z)V", $PROTECTED, $method(SimpleVerifier, init$, void, int32_t, $Type*, $Type*, $List*, bool)},
	{"getClass", "(Ljdk/internal/org/objectweb/asm/Type;)Ljava/lang/Class;", "(Ljdk/internal/org/objectweb/asm/Type;)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(SimpleVerifier, getClass, $Class*, $Type*)},
	{"getElementValue", "(Ljdk/internal/org/objectweb/asm/tree/analysis/BasicValue;)Ljdk/internal/org/objectweb/asm/tree/analysis/BasicValue;", nullptr, $PROTECTED, $virtualMethod(SimpleVerifier, getElementValue, $BasicValue*, $BasicValue*), "jdk.internal.org.objectweb.asm.tree.analysis.AnalyzerException"},
	{"getSuperClass", "(Ljdk/internal/org/objectweb/asm/Type;)Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PROTECTED, $virtualMethod(SimpleVerifier, getSuperClass, $Type*, $Type*)},
	{"isArrayValue", "(Ljdk/internal/org/objectweb/asm/tree/analysis/BasicValue;)Z", nullptr, $PROTECTED, $virtualMethod(SimpleVerifier, isArrayValue, bool, $BasicValue*)},
	{"isAssignableFrom", "(Ljdk/internal/org/objectweb/asm/Type;Ljdk/internal/org/objectweb/asm/Type;)Z", nullptr, $PROTECTED, $virtualMethod(SimpleVerifier, isAssignableFrom, bool, $Type*, $Type*)},
	{"isInterface", "(Ljdk/internal/org/objectweb/asm/Type;)Z", nullptr, $PROTECTED, $virtualMethod(SimpleVerifier, isInterface, bool, $Type*)},
	{"isSubTypeOf", "(Ljdk/internal/org/objectweb/asm/tree/analysis/BasicValue;Ljdk/internal/org/objectweb/asm/tree/analysis/BasicValue;)Z", nullptr, $PROTECTED, $virtualMethod(SimpleVerifier, isSubTypeOf, bool, $BasicValue*, $BasicValue*)},
	{"merge", "(Ljdk/internal/org/objectweb/asm/tree/analysis/BasicValue;Ljdk/internal/org/objectweb/asm/tree/analysis/BasicValue;)Ljdk/internal/org/objectweb/asm/tree/analysis/BasicValue;", nullptr, $PUBLIC, $virtualMethod(SimpleVerifier, merge, $BasicValue*, $BasicValue*, $BasicValue*)},
	{"merge", "(Ljdk/internal/org/objectweb/asm/tree/analysis/Value;Ljdk/internal/org/objectweb/asm/tree/analysis/Value;)Ljdk/internal/org/objectweb/asm/tree/analysis/Value;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(SimpleVerifier, merge, $1Value*, $1Value*, $1Value*)},
	{"newArrayValue", "(Ljdk/internal/org/objectweb/asm/Type;I)Ljdk/internal/org/objectweb/asm/tree/analysis/BasicValue;", nullptr, $PRIVATE, $method(SimpleVerifier, newArrayValue, $BasicValue*, $Type*, int32_t)},
	{"newValue", "(Ljdk/internal/org/objectweb/asm/Type;)Ljdk/internal/org/objectweb/asm/tree/analysis/BasicValue;", nullptr, $PUBLIC, $virtualMethod(SimpleVerifier, newValue, $1Value*, $Type*)},
	{"setClassLoader", "(Ljava/lang/ClassLoader;)V", nullptr, $PUBLIC, $virtualMethod(SimpleVerifier, setClassLoader, void, $ClassLoader*)},
	{}
};

$ClassInfo _SimpleVerifier_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.tree.analysis.SimpleVerifier",
	"jdk.internal.org.objectweb.asm.tree.analysis.BasicVerifier",
	nullptr,
	_SimpleVerifier_FieldInfo_,
	_SimpleVerifier_MethodInfo_
};

$Object* allocate$SimpleVerifier($Class* clazz) {
	return $of($alloc(SimpleVerifier));
}

void SimpleVerifier::init$() {
	SimpleVerifier::init$(nullptr, nullptr, false);
}

void SimpleVerifier::init$($Type* currentClass, $Type* currentSuperClass, bool isInterface) {
	SimpleVerifier::init$(currentClass, currentSuperClass, nullptr, isInterface);
}

void SimpleVerifier::init$($Type* currentClass, $Type* currentSuperClass, $List* currentClassInterfaces, bool isInterface) {
	SimpleVerifier::init$($Opcodes::ASM8, currentClass, currentSuperClass, currentClassInterfaces, isInterface);
	if ($of(this)->getClass() != SimpleVerifier::class$) {
		$throwNew($IllegalStateException);
	}
}

void SimpleVerifier::init$(int32_t api, $Type* currentClass, $Type* currentSuperClass, $List* currentClassInterfaces, bool isInterface) {
	$beforeCallerSensitive();
	$BasicVerifier::init$(api);
	$set(this, loader, $of(this)->getClass()->getClassLoader());
	$set(this, currentClass, currentClass);
	$set(this, currentSuperClass, currentSuperClass);
	$set(this, currentClassInterfaces, currentClassInterfaces);
	this->isInterface$ = isInterface;
}

void SimpleVerifier::setClassLoader($ClassLoader* loader) {
	$set(this, loader, loader);
}

$1Value* SimpleVerifier::newValue($Type* type) {
	$useLocalCurrentObjectStackCache();
	if (type == nullptr) {
		$init($BasicValue);
		return $BasicValue::UNINITIALIZED_VALUE;
	}
	bool isArray = $nc(type)->getSort() == $Type::ARRAY;
	if (isArray) {
		switch ($nc($(type->getElementType()))->getSort()) {
		case $Type::BOOLEAN:
			{}
		case $Type::CHAR:
			{}
		case $Type::BYTE:
			{}
		case $Type::SHORT:
			{
				return $new($BasicValue, type);
			}
		default:
			{
				break;
			}
		}
	}
	$var($BasicValue, value, $cast($BasicValue, $BasicVerifier::newValue(type)));
	$init($BasicValue);
	if ($nc($BasicValue::REFERENCE_VALUE)->equals(value)) {
		if (isArray) {
			$assign(value, $cast($BasicValue, newValue($(type->getElementType()))));
			$var($StringBuilder, descriptor, $new($StringBuilder));
			for (int32_t i = 0; i < type->getDimensions(); ++i) {
				descriptor->append(u'[');
			}
			descriptor->append($($nc($($nc(value)->getType()))->getDescriptor()));
			$assign(value, $new($BasicValue, $($Type::getType($(descriptor->toString())))));
		} else {
			$assign(value, $new($BasicValue, type));
		}
	}
	return value;
}

bool SimpleVerifier::isArrayValue($BasicValue* value) {
	$var($Type, type, $nc(value)->getType());
	bool var$0 = type != nullptr;
	if (var$0) {
		bool var$1 = type->getSort() == $Type::ARRAY;
		$init($BasicInterpreter);
		var$0 = (var$1 || type->equals($BasicInterpreter::NULL_TYPE));
	}
	return var$0;
}

$BasicValue* SimpleVerifier::getElementValue($BasicValue* objectArrayValue) {
	$useLocalCurrentObjectStackCache();
	$var($Type, arrayType, $nc(objectArrayValue)->getType());
	if (arrayType != nullptr) {
		if (arrayType->getSort() == $Type::ARRAY) {
			return $cast($BasicValue, newValue($($Type::getType($($nc($(arrayType->getDescriptor()))->substring(1))))));
		} else {
			$init($BasicInterpreter);
			if (arrayType->equals($BasicInterpreter::NULL_TYPE)) {
				return objectArrayValue;
			}
		}
	}
	$throwNew($AssertionError);
}

bool SimpleVerifier::isSubTypeOf($BasicValue* value, $BasicValue* expected) {
	$useLocalCurrentObjectStackCache();
	$var($Type, expectedType, $nc(expected)->getType());
	$var($Type, type, $nc(value)->getType());
	switch ($nc(expectedType)->getSort()) {
	case $Type::INT:
		{}
	case $Type::FLOAT:
		{}
	case $Type::LONG:
		{}
	case $Type::DOUBLE:
		{
			return $nc(type)->equals(expectedType);
		}
	case $Type::ARRAY:
		{}
	case $Type::OBJECT:
		{
			$init($BasicInterpreter);
			if ($nc(type)->equals($BasicInterpreter::NULL_TYPE)) {
				return true;
			} else {
				bool var$1 = type->getSort() == $Type::OBJECT;
				if (var$1 || type->getSort() == $Type::ARRAY) {
					if (isAssignableFrom(expectedType, type)) {
						return true;
					} else if ($nc(getClass(expectedType))->isInterface()) {
						return $Object::class$->isAssignableFrom(getClass(type));
					} else {
						return false;
					}
				} else {
					return false;
				}
			}
		}
	default:
		{
			$throwNew($AssertionError);
		}
	}
}

$BasicValue* SimpleVerifier::merge($BasicValue* value1, $BasicValue* value2) {
	$useLocalCurrentObjectStackCache();
	if (!$nc(value1)->equals(value2)) {
		$var($Type, type1, value1->getType());
		$var($Type, type2, $nc(value2)->getType());
		bool var$1 = type1 != nullptr;
		if (var$1) {
			bool var$2 = type1->getSort() == $Type::OBJECT;
			var$1 = (var$2 || type1->getSort() == $Type::ARRAY);
		}
		bool var$0 = var$1 && type2 != nullptr;
		if (var$0) {
			bool var$3 = type2->getSort() == $Type::OBJECT;
			var$0 = (var$3 || type2->getSort() == $Type::ARRAY);
		}
		if (var$0) {
			$init($BasicInterpreter);
			if ($nc(type1)->equals($BasicInterpreter::NULL_TYPE)) {
				return value2;
			}
			if ($nc(type2)->equals($BasicInterpreter::NULL_TYPE)) {
				return value1;
			}
			if (isAssignableFrom(type1, type2)) {
				return value1;
			}
			if (isAssignableFrom(type2, type1)) {
				return value2;
			}
			int32_t numDimensions = 0;
			bool var$7 = $nc(type1)->getSort() == $Type::ARRAY;
			bool var$6 = var$7 && $nc(type2)->getSort() == $Type::ARRAY;
			if (var$6) {
				int32_t var$8 = type1->getDimensions();
				var$6 = var$8 == type2->getDimensions();
			}
			bool var$5 = var$6;
			bool var$4 = var$5 && $nc($(type1->getElementType()))->getSort() == $Type::OBJECT;
			if (var$4 && $nc($(type2->getElementType()))->getSort() == $Type::OBJECT) {
				numDimensions = type1->getDimensions();
				$assign(type1, type1->getElementType());
				$assign(type2, type2->getElementType());
			}
			while (true) {
				if (type1 == nullptr || isInterface(type1)) {
					return newArrayValue($($Type::getObjectType("java/lang/Object"_s)), numDimensions);
				}
				$assign(type1, getSuperClass(type1));
				if (isAssignableFrom(type1, type2)) {
					return newArrayValue(type1, numDimensions);
				}
			}
		}
		return $BasicValue::UNINITIALIZED_VALUE;
	}
	return value1;
}

$BasicValue* SimpleVerifier::newArrayValue($Type* type, int32_t dimensions) {
	$useLocalCurrentObjectStackCache();
	if (dimensions == 0) {
		return $cast($BasicValue, newValue(type));
	} else {
		$var($StringBuilder, descriptor, $new($StringBuilder));
		for (int32_t i = 0; i < dimensions; ++i) {
			descriptor->append(u'[');
		}
		descriptor->append($($nc(type)->getDescriptor()));
		return $cast($BasicValue, newValue($($Type::getType($(descriptor->toString())))));
	}
}

bool SimpleVerifier::isInterface($Type* type) {
	if (this->currentClass != nullptr && $nc(this->currentClass)->equals(type)) {
		return this->isInterface$;
	}
	return $nc(getClass(type))->isInterface();
}

$Type* SimpleVerifier::getSuperClass($Type* type) {
	if (this->currentClass != nullptr && $nc(this->currentClass)->equals(type)) {
		return this->currentSuperClass;
	}
	$Class* superClass = $nc(getClass(type))->getSuperclass();
	return superClass == nullptr ? ($Type*)nullptr : $Type::getType(superClass);
}

bool SimpleVerifier::isAssignableFrom($Type* type1, $Type* type2) {
	$useLocalCurrentObjectStackCache();
	if ($nc(type1)->equals(type2)) {
		return true;
	}
	if (this->currentClass != nullptr && $nc(this->currentClass)->equals(type1)) {
		if (getSuperClass(type2) == nullptr) {
			return false;
		} else {
			if (this->isInterface$) {
				bool var$0 = $nc(type2)->getSort() == $Type::OBJECT;
				return var$0 || $nc(type2)->getSort() == $Type::ARRAY;
			}
			return isAssignableFrom(type1, $(getSuperClass(type2)));
		}
	}
	if (this->currentClass != nullptr && $nc(this->currentClass)->equals(type2)) {
		if (isAssignableFrom(type1, this->currentSuperClass)) {
			return true;
		}
		if (this->currentClassInterfaces != nullptr) {
			{
				$var($Iterator, i$, $nc(this->currentClassInterfaces)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Type, currentClassInterface, $cast($Type, i$->next()));
					{
						if (isAssignableFrom(type1, currentClassInterface)) {
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	return $nc(getClass(type1))->isAssignableFrom(getClass(type2));
}

$Class* SimpleVerifier::getClass($Type* type) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		if ($nc(type)->getSort() == $Type::ARRAY) {
			return $Class::forName($($nc($(type->getDescriptor()))->replace(u'/', u'.')), false, this->loader);
		}
		return $Class::forName($($nc(type)->getClassName()), false, this->loader);
	} catch ($ClassNotFoundException& e) {
		$throwNew($TypeNotPresentException, $(e->toString()), e);
	}
	$shouldNotReachHere();
}

$1Value* SimpleVerifier::merge($1Value* value1, $1Value* value2) {
	return this->merge($cast($BasicValue, value1), $cast($BasicValue, value2));
}

SimpleVerifier::SimpleVerifier() {
}

$Class* SimpleVerifier::load$($String* name, bool initialize) {
	$loadClass(SimpleVerifier, name, initialize, &_SimpleVerifier_ClassInfo_, allocate$SimpleVerifier);
	return class$;
}

$Class* SimpleVerifier::class$ = nullptr;

						} // analysis
					} // tree
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk