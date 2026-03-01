#ifndef _java_lang_reflect_Method_h_
#define _java_lang_reflect_Method_h_
//$ class java.lang.reflect.Method
//$ extends java.lang.reflect.Executable

#include <java/lang/Array.h>
#include <java/lang/reflect/Executable.h>

namespace java {
	namespace lang {
		class StringBuilder;
	}
}
namespace java {
	namespace lang {
		namespace annotation {
			class Annotation;
		}
	}
}
namespace java {
	namespace lang {
		namespace reflect {
			class AnnotatedType;
			class Type;
			class TypeVariable;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace reflect {
			class MethodAccessor;
		}
	}
}
namespace sun {
	namespace reflect {
		namespace generics {
			namespace factory {
				class GenericsFactory;
			}
		}
	}
}
namespace sun {
	namespace reflect {
		namespace generics {
			namespace repository {
				class ConstructorRepository;
				class MethodRepository;
			}
		}
	}
}

namespace java {
	namespace lang {
		namespace reflect {

class $import Method : public ::java::lang::reflect::Executable {
	$class(Method, $PRELOAD | $NO_CLASS_INIT, ::java::lang::reflect::Executable)
public:
	Method();
	using ::java::lang::reflect::Executable::checkCanSetAccessible;
	void init$($Class* declaringClass, $String* name, $ClassArray* parameterTypes, $Class* returnType, $ClassArray* checkedExceptions, int32_t modifiers, int32_t slot, $String* signature, $bytes* annotations, $bytes* parameterAnnotations, $bytes* annotationDefault);
	::jdk::internal::reflect::MethodAccessor* acquireMethodAccessor();
	virtual void checkCanSetAccessible($Class* caller) override;
	::java::lang::reflect::Method* copy();
	virtual bool equals(Object$* obj) override;
	virtual ::java::lang::reflect::AnnotatedType* getAnnotatedReturnType() override;
	virtual ::java::lang::annotation::Annotation* getAnnotation($Class* annotationClass) override;
	virtual $bytes* getAnnotationBytes() override;
	virtual $Array<::java::lang::annotation::Annotation>* getDeclaredAnnotations() override;
	virtual $Class* getDeclaringClass() override;
	$Object* getDefaultValue();
	virtual $ClassArray* getExceptionTypes() override;
	::sun::reflect::generics::factory::GenericsFactory* getFactory();
	virtual $Array<::java::lang::reflect::Type>* getGenericExceptionTypes() override;
	virtual ::sun::reflect::generics::repository::ConstructorRepository* getGenericInfo() override;
	virtual $Array<::java::lang::reflect::Type>* getGenericParameterTypes() override;
	::java::lang::reflect::Type* getGenericReturnType();
	$String* getGenericSignature();
	::jdk::internal::reflect::MethodAccessor* getMethodAccessor();
	virtual int32_t getModifiers() override;
	virtual $String* getName() override;
	virtual $Array<::java::lang::annotation::Annotation, 2>* getParameterAnnotations() override;
	virtual int32_t getParameterCount() override;
	virtual $ClassArray* getParameterTypes() override;
	$Class* getReturnType();
	virtual ::java::lang::reflect::Method* getRoot() override;
	virtual $ClassArray* getSharedExceptionTypes() override;
	virtual $ClassArray* getSharedParameterTypes() override;
	virtual $Array<::java::lang::reflect::TypeVariable>* getTypeParameters() override;
	virtual bool handleParameterNumberMismatch(int32_t resultLength, $ClassArray* parameterTypes) override;
	virtual bool hasGenericInformation() override;
	virtual int32_t hashCode() override;
	$Object* invoke(Object$* obj, $ObjectArray* args);
	bool isBridge();
	bool isDefault();
	virtual bool isSynthetic() override;
	virtual bool isVarArgs() override;
	::java::lang::reflect::Method* leafCopy();
	virtual void setAccessible(bool flag) override;
	void setMethodAccessor(::jdk::internal::reflect::MethodAccessor* accessor);
	virtual void specificToGenericStringHeader(::java::lang::StringBuilder* sb) override;
	virtual void specificToStringHeader(::java::lang::StringBuilder* sb) override;
	virtual $String* toGenericString() override;
	$String* toShortSignature();
	virtual $String* toShortString() override;
	virtual $String* toString() override;
	$Class* clazz = nullptr;
	int32_t slot = 0;
	$String* name = nullptr;
	$Class* returnType = nullptr;
	$ClassArray* parameterTypes = nullptr;
	$ClassArray* exceptionTypes = nullptr;
	int32_t modifiers = 0;
	$String* signature = nullptr;
	::sun::reflect::generics::repository::MethodRepository* genericInfo = nullptr;
	$bytes* annotations = nullptr;
	$bytes* parameterAnnotations = nullptr;
	$bytes* annotationDefault = nullptr;
	$volatile(::jdk::internal::reflect::MethodAccessor*) methodAccessor = nullptr;
	::java::lang::reflect::Method* root = nullptr;
	bool isStatic();
	bool isCallerSensitive();
	bool isHidden();
	$String* getDescriptor();
	$Object* invokeSpecial(Object$* obj, $ObjectArray* args);
	$Value invokev(Object$* obj, $Value* argv);
	int32_t virtualOffset = 0;
	int32_t virtualIndex = 0;
};

		} // reflect
	} // lang
} // java

#endif // _java_lang_reflect_Method_h_