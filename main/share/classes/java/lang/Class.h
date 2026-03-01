#ifndef _java_lang_Class_h_
#define _java_lang_Class_h_
//$ class java.lang.Class
//$ extends java.io.Serializable
//$ implements java.lang.reflect.GenericDeclaration,java.lang.reflect.Type,java.lang.invoke.TypeDescriptor$OfField,java.lang.constant.Constable

#include <java/io/Serializable.h>
#include <java/lang/Array.h>
#include <java/lang/constant/Constable.h>
#include <java/lang/invoke/TypeDescriptor$OfField.h>
#include <java/lang/reflect/GenericDeclaration.h>
#include <java/lang/reflect/Type.h>
#include <java/lang/ClassEntry.h>

namespace java {
	namespace lang {
		class ClassInfo;
		class ClassCastOffset;
		class Throwable;
	}
}
namespace java {
	namespace lang {
		namespace invoke {
			class MethodHandle;
		}
	}
}

#pragma push_macro("ANNOTATION")
#undef ANNOTATION
#pragma push_macro("EMPTY_CLASS_ARRAY")
#undef EMPTY_CLASS_ARRAY
#pragma push_macro("ENUM")
#undef ENUM
#pragma push_macro("SYNTHETIC")
#undef SYNTHETIC

namespace java {
	namespace io {
		class InputStream;
		class ObjectStreamField;
	}
}
namespace java {
	namespace lang {
		class Class$AnnotationData;
		class Class$EnclosingMethodInfo;
		class Class$ReflectionData;
		class ClassLoader;
		class ClassValue$ClassValueMap;
		class Module;
		class Package;
		class PublicMethods$MethodList;
		class SecurityManager;
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
		namespace ref {
			class SoftReference;
		}
	}
}
namespace java {
	namespace lang {
		namespace reflect {
			class AnnotatedType;
			class Constructor;
			class Executable;
			class Field;
			class Method;
			class RecordComponent;
			class TypeVariable;
		}
	}
}
namespace java {
	namespace net {
		class URL;
	}
}
namespace java {
	namespace security {
		class ProtectionDomain;
	}
}
namespace java {
	namespace util {
		class Collection;
		class List;
		class Map;
		class Optional;
	}
}
namespace jdk {
	namespace internal {
		namespace reflect {
			class ConstantPool;
			class ReflectionFactory;
		}
	}
}
namespace sun {
	namespace reflect {
		namespace annotation {
			class AnnotationType;
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
				class ClassRepository;
			}
		}
	}
}

namespace java {
	namespace lang {

class $export Class : public ::java::io::Serializable, public ::java::lang::reflect::GenericDeclaration, public ::java::lang::reflect::Type, public ::java::lang::invoke::TypeDescriptor$OfField, public ::java::lang::constant::Constable {
	$class(Class, $PRELOAD | $PREINIT, ::java::io::Serializable, ::java::lang::reflect::GenericDeclaration, ::java::lang::reflect::Type, ::java::lang::invoke::TypeDescriptor$OfField, ::java::lang::constant::Constable)
public:
	Class();
	virtual $Object* clone() override;
	virtual bool equals(Object$* obj) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(::java::lang::ClassLoader* loader, $Class* arrayComponentType);
	static void addAll(::java::util::Collection* c, $Array<::java::lang::reflect::Field>* o);
	::java::lang::Class$AnnotationData* annotationData();
	static bool arrayContentsEq($ObjectArray* a1, $ObjectArray* a2);
	virtual ::java::lang::invoke::TypeDescriptor$OfField* arrayType() override;
	$Class* asSubclass($Class* clazz);
	$String* cannotCastMsg(Object$* obj);
	bool casAnnotationType(::sun::reflect::annotation::AnnotationType* oldType, ::sun::reflect::annotation::AnnotationType* newType);
	$Object* cast(Object$* obj);
	void checkMemberAccess(::java::lang::SecurityManager* sm, int32_t which, $Class* caller, bool checkProxyInterfaces);
	void checkPackageAccess(::java::lang::SecurityManager* sm, ::java::lang::ClassLoader* ccl, bool checkProxyInterfaces);
	static void checkPackageAccessForPermittedSubclasses(::java::lang::SecurityManager* sm, ::java::lang::ClassLoader* ccl, $ClassArray* subClasses);
	virtual ::java::lang::invoke::TypeDescriptor$OfField* componentType() override;
	static $Array<::java::lang::reflect::Constructor>* copyConstructors($Array<::java::lang::reflect::Constructor>* arg);
	static $Array<::java::lang::reflect::Field>* copyFields($Array<::java::lang::reflect::Field>* arg);
	static $Array<::java::lang::reflect::Method>* copyMethods($Array<::java::lang::reflect::Method>* arg);
	::java::lang::Class$AnnotationData* createAnnotationData(int32_t classRedefinedCount);
	virtual ::java::util::Optional* describeConstable() override;
	virtual $String* descriptorString() override;
	bool desiredAssertionStatus();
	static bool desiredAssertionStatus0($Class* clazz);
	$Class* elementType();
	::java::util::Map* enumConstantDirectory();
	static $Class* forName($String* className);
	static $Class* forName($String* name, bool initialize, ::java::lang::ClassLoader* loader);
	static $Class* forName(::java::lang::Module* module, $String* name);
	static $Class* forName0($String* name, bool initialize, ::java::lang::ClassLoader* loader, $Class* caller);
	$Array<::java::lang::reflect::AnnotatedType>* getAnnotatedInterfaces();
	::java::lang::reflect::AnnotatedType* getAnnotatedSuperclass();
	virtual ::java::lang::annotation::Annotation* getAnnotation($Class* annotationClass) override;
	::sun::reflect::annotation::AnnotationType* getAnnotationType();
	virtual $Array<::java::lang::annotation::Annotation>* getAnnotations() override;
	virtual $Array<::java::lang::annotation::Annotation>* getAnnotationsByType($Class* annotationClass) override;
	$String* getCanonicalName();
	$String* getCanonicalName0();
	$Object* getClassData();
	::java::lang::ClassLoader* getClassLoader();
	::java::lang::ClassLoader* getClassLoader0();
	$ClassArray* getClasses();
	$Class* getComponentType();
	::jdk::internal::reflect::ConstantPool* getConstantPool();
	::java::lang::reflect::Constructor* getConstructor($ClassArray* parameterTypes);
	::java::lang::reflect::Constructor* getConstructor0($ClassArray* parameterTypes, int32_t which);
	$Array<::java::lang::reflect::Constructor>* getConstructors();
	virtual ::java::lang::annotation::Annotation* getDeclaredAnnotation($Class* annotationClass) override;
	::java::util::Map* getDeclaredAnnotationMap();
	virtual $Array<::java::lang::annotation::Annotation>* getDeclaredAnnotations() override;
	virtual $Array<::java::lang::annotation::Annotation>* getDeclaredAnnotationsByType($Class* annotationClass) override;
	$ClassArray* getDeclaredClasses();
	$ClassArray* getDeclaredClasses0();
	::java::lang::reflect::Constructor* getDeclaredConstructor($ClassArray* parameterTypes);
	$Array<::java::lang::reflect::Constructor>* getDeclaredConstructors();
	$Array<::java::lang::reflect::Constructor>* getDeclaredConstructors0(bool publicOnly);
	::java::lang::reflect::Field* getDeclaredField($String* name);
	$Array<::java::lang::reflect::Field>* getDeclaredFields();
	$Array<::java::lang::reflect::Field>* getDeclaredFields0(bool publicOnly);
	::java::lang::reflect::Method* getDeclaredMethod($String* name, $ClassArray* parameterTypes);
	$Array<::java::lang::reflect::Method>* getDeclaredMethods();
	$Array<::java::lang::reflect::Method>* getDeclaredMethods0(bool publicOnly);
	::java::util::List* getDeclaredPublicMethods($String* name, $ClassArray* parameterTypes);
	$Class* getDeclaringClass();
	$Class* getDeclaringClass0();
	$Class* getEnclosingClass();
	::java::lang::reflect::Constructor* getEnclosingConstructor();
	::java::lang::reflect::Method* getEnclosingMethod();
	$ObjectArray* getEnclosingMethod0();
	::java::lang::Class$EnclosingMethodInfo* getEnclosingMethodInfo();
	$ObjectArray* getEnumConstants();
	$ObjectArray* getEnumConstantsShared();
	static $bytes* getExecutableTypeAnnotationBytes(::java::lang::reflect::Executable* ex);
	::sun::reflect::generics::factory::GenericsFactory* getFactory();
	::java::lang::reflect::Field* getField($String* name);
	::java::lang::reflect::Field* getField0($String* name);
	$Array<::java::lang::reflect::Field>* getFields();
	::sun::reflect::generics::repository::ClassRepository* getGenericInfo();
	$Array<::java::lang::reflect::Type>* getGenericInterfaces();
	$String* getGenericSignature0();
	::java::lang::reflect::Type* getGenericSuperclass();
	$ClassArray* getInterfaces();
	$ClassArray* getInterfaces(bool cloneArray);
	$ClassArray* getInterfaces0();
	::java::lang::reflect::Method* getMethod($String* name, $ClassArray* parameterTypes);
	::java::lang::reflect::Method* getMethod0($String* name, $ClassArray* parameterTypes);
	$Array<::java::lang::reflect::Method>* getMethods();
	::java::lang::PublicMethods$MethodList* getMethodsRecursive($String* name, $ClassArray* parameterTypes, bool includeStatic);
	int32_t getModifiers();
	::java::lang::Module* getModule();
	$String* getName();
	$Class* getNestHost();
	$Class* getNestHost0();
	$ClassArray* getNestMembers();
	$ClassArray* getNestMembers0();
	::java::lang::Package* getPackage();
	$String* getPackageName();
	$ClassArray* getPermittedSubclasses();
	$ClassArray* getPermittedSubclasses0();
	static $Class* getPrimitiveClass($String* name);
	::java::security::ProtectionDomain* getProtectionDomain();
	::java::security::ProtectionDomain* getProtectionDomain0();
	$bytes* getRawAnnotations();
	$bytes* getRawTypeAnnotations();
	$Array<::java::lang::reflect::RecordComponent>* getRecordComponents();
	$Array<::java::lang::reflect::RecordComponent>* getRecordComponents0();
	static ::jdk::internal::reflect::ReflectionFactory* getReflectionFactory();
	::java::net::URL* getResource($String* name);
	::java::io::InputStream* getResourceAsStream($String* name);
	$ObjectArray* getSigners();
	$String* getSimpleBinaryName();
	$String* getSimpleBinaryName0();
	$String* getSimpleName();
	$String* getSimpleName0();
	$Class* getSuperclass();
	virtual $String* getTypeName() override;
	virtual $Array<::java::lang::reflect::TypeVariable>* getTypeParameters() override;
	bool hasEnclosingMethodInfo();
	$String* initClassName();
	bool isAnnotation();
	virtual bool isAnnotationPresent($Class* annotationClass) override;
	bool isAnonymousClass();
	virtual bool isArray() override;
	bool isAssignableFrom($Class* cls);
	bool isDirectSubType($Class* c);
	bool isEnum();
	bool isHidden();
	bool isInstance(Object$* obj);
	bool isInterface();
	bool isLocalClass();
	bool isLocalOrAnonymousClass();
	bool isMemberClass();
	bool isNestmateOf($Class* c);
	bool isOpenToCaller($String* name, $Class* caller);
	virtual bool isPrimitive() override;
	bool isRecord();
	bool isRecord0();
	bool isSealed();
	bool isSynthetic();
	bool isTopLevelClass();
	bool lambda$getPermittedSubclasses$1($Class* c);
	static $ClassArray* lambda$getPermittedSubclasses$2(int32_t s);
	static $String* lambda$methodToString$0($Class* c);
	$String* methodToString($String* name, $ClassArray* argTypes);
	$Object* newInstance();
	::java::lang::Class$ReflectionData* newReflectionData(::java::lang::ref::SoftReference* oldReflectionData, int32_t classRedefinedCount);
	$Array<::java::lang::reflect::Constructor>* privateGetDeclaredConstructors(bool publicOnly);
	$Array<::java::lang::reflect::Field>* privateGetDeclaredFields(bool publicOnly);
	$Array<::java::lang::reflect::Method>* privateGetDeclaredMethods(bool publicOnly);
	$Array<::java::lang::reflect::Field>* privateGetPublicFields();
	$Array<::java::lang::reflect::Method>* privateGetPublicMethods();
	::java::security::ProtectionDomain* protectionDomain();
	::java::lang::Class$ReflectionData* reflectionData();
	static void registerNatives();
	$String* resolveName($String* name);
	static ::java::lang::reflect::Field* searchFields($Array<::java::lang::reflect::Field>* fields, $String* name);
	static ::java::lang::reflect::Method* searchMethods($Array<::java::lang::reflect::Method>* methods, $String* name, $ClassArray* parameterTypes);
	void setSigners($ObjectArray* signers);
	static $Class* toClass(::java::lang::reflect::Type* o);
	$String* toGenericString();
	virtual $String* toString() override;
	static $String* typeVarBounds(::java::lang::reflect::TypeVariable* typeVar);
	static const int32_t ANNOTATION = 8192;
	static const int32_t ENUM = 16384;
	static const int32_t SYNTHETIC = 4096;
	$volatile(::java::lang::reflect::Constructor*) cachedConstructor = nullptr;
	$String* name = nullptr;
	::java::lang::Module* module = nullptr;
	::java::lang::ClassLoader* classLoader = nullptr;
	$Object* classData = nullptr;
	$String* packageName = nullptr;
	$Class* componentType$ = nullptr;
	static ::java::security::ProtectionDomain* allPermDomain;
	$volatile(::java::lang::ref::SoftReference*) reflectionData$ = nullptr;
	$volatile(int32_t) classRedefinedCount = 0;
	$volatile(::sun::reflect::generics::repository::ClassRepository*) genericInfo = nullptr;
	static $ClassArray* EMPTY_CLASS_ARRAY;
	static const int64_t serialVersionUID = (int64_t)0x2C7E5503D9BF9553;
	static $Array<::java::io::ObjectStreamField>* serialPersistentFields;
	static ::jdk::internal::reflect::ReflectionFactory* reflectionFactory;
	$volatile($ObjectArray*) enumConstants = nullptr;
	$volatile(::java::util::Map*) enumConstantDirectory$ = nullptr;
	$volatile(::java::lang::Class$AnnotationData*) annotationData$ = nullptr;
	$volatile(::sun::reflect::annotation::AnnotationType*) annotationType = nullptr;
	::java::lang::ClassValue$ClassValueMap* classValueMap = nullptr;
public:
	enum ClassState {
		CLASS_STATE_NONE = 0,
		CLASS_STATE_LOADED,
		CLASS_STATE_INITIALIZING,
		CLASS_STATE_INITIALIZED
	};

	void setPrimitive(bool primitive);

	inline int32_t getArrayBaseOffset() {
		return size;
	}
	void setArrayIndexScale(int32_t arrayIndexScale);
	inline int32_t getArrayIndexScale() {
		return arrayIndexScale;
	}

	void setSuperClass(Class* superClass);
	void setComponentType(Class* componentType);

	int32_t getSize();
	int32_t calcBaseSize(); // without declaredfield

	::java::lang::reflect::Field* refField($String* name);
	::java::lang::reflect::Constructor* refConstructor($String* descriptor);
	::java::lang::reflect::Method* refMethod($String* name, $String* descriptor);

	::java::lang::reflect::Method* getMethodEx($String* name, $ClassArray* parameterTypes);
	::java::lang::reflect::Method* getMethodsRecursiveEx($String* name, $ClassArray* parameterTypes, bool includeStatic);
	::java::lang::reflect::Method* getMethodEx($String* name, $String* descriptor);
	::java::lang::reflect::Constructor* getDeclaredConstructor($String* descriptor);
	$Array<::java::lang::reflect::Method>* getDeclaredMethods(bool publicOnly, bool withStar);
	virtual void ensureClassInitialized();
	virtual ::jdk::internal::reflect::ConstantPool* getConstantPool0();
	void initMeta();
	void initialize();
	inline bool isInitialized() {
		return state == CLASS_STATE_INITIALIZED;
	}
	bool isCloneable();

	Object* allocateInstance();
	void initInstance(::java::lang::reflect::Constructor* constructor, Object$* instance, $ObjectArray* args);
	$Object* invokeSpecial(::java::lang::reflect::Method* method, Object$* obj, $ObjectArray* args);
	$Object* invoke(::java::lang::reflect::Method* method, Object$* obj, $ObjectArray* args);
	$Value invokev(::java::lang::reflect::Method* method, Object$* obj, $Value* argv);
	inline bool isInstance(Object0* obj) {
		if (obj == nullptr) {
			return false;
		}
		Class* clazz = obj->getClass();
		if (clazz == this) {
			return true;
		}
		return isAssignableFrom(clazz);
	}
	void calcClassCastOffset();
	static $Object* cast0(Class* to, Class* from, Object0* inst);
	inline $Object* cast(Object0* obj) {
		if (obj == nullptr) {
			return obj;
		}
		Class* clazz = obj->getClass();
		if (clazz == this) {
			return obj;
		}
		return cast0(this, clazz, obj);
	}
	inline $Object* cast(::std::nullptr_t) {
		return nullptr;
	}
	$Object* castOrNull(Object$* inst);
	$ClassArray* getPrimaryBaseClasses();
	int32_t getBaseClassOffset(Class* baseClass);

	static void loadClass(String* name, bool initialize, Class** pClass, int64_t size, int32_t mark, ClassInfo* classInfo, $InitClassFunction initClassFunction, $AllocateInstanceFunction allocateInstanceFunction, $InitInstanceFunction initInstanceFunction, $InvokeSpecialFunction invokeSpecialFunction, $InvokeFunction invokeFunction);
	static void loadClass(String* name, bool initialize, Class** pClass, int64_t size, int32_t mark, ClassInfo* classInfo, $InitClassFunction initClassFunction, $AllocateInstanceFunction allocateInstanceFunction);
	static void loadClass(String* name, bool initialize, Class** pClass, int64_t size, int32_t mark, ClassInfo* classInfo, $InitClassFunction initClassFunction);
	static void loadClass(String* name, bool initialize, Class** pClass, int64_t size, int32_t mark, ClassInfo* classInfo, $AllocateInstanceFunction allocateInstanceFunction);
	static void loadClass(String* name, bool initialize, Class** pClass, int64_t size, int32_t mark, ClassInfo* classInfo);
	static void loadClass(String* name, bool initialize, Class** pClass, int64_t size, int32_t mark);
	static void registerClass(Class* clazz, const char* name);
	static void registerClass(Class* clazz, const char* name, const char* simpleBinaryName);
	static void ensureBaseClassInitialized(Class* clazz);
	static bool isAssignable(Class* to, Class* from, Object$* inst);

	static $StringArray* parseMethodDescriptor($String* descriptor);
	Class* forName(const char* name);
	Class* forDescriptor(const char* descriptor);

	int32_t calcCastOffset(Class* classTo, Object$* obj);
	::java::lang::reflect::Field* findField($String* fieldName);
	Class* getFieldTypeByOffset(int32_t offset);

	void initObjectFieldOffset();
	void recordObjectFieldOffset(int32_t offset);
	void recordObjectFieldOffset0(int32_t offset);
	void ensureConstantPoolInitialized();

	Class* arrayType0();
	Class* arrayType(int32_t dim);
	int32_t arrayDimension();

	String* bootstrapToString(Object$* inst);
	int32_t bootstrapHashCode(Object$* inst);
	bool bootstrapEquals(Object$* inst, Object$* o);

	Class* arrayType$ = nullptr;
	String* simpleBinaryName = nullptr;
	Class* declaringClass = nullptr;
	Class* superClass = nullptr;
	Class* nestHost = nullptr;

	ClassInfo* classInfo = nullptr;
	$InitClassFunction initClassFunction = nullptr;
	$AllocateInstanceFunction allocateInstanceFunction = nullptr;
	$InitInstanceFunction initInstanceFunction = nullptr;
	$InvokeSpecialFunction invokeSpecialFunction = nullptr;
	$InvokeFunction invokeFunction = nullptr;

	::java::lang::invoke::MethodHandle* bootstrapToStringMethodHandle = nullptr;
	::java::lang::invoke::MethodHandle* bootstrapHashCodeMethodHandle = nullptr;
	::java::lang::invoke::MethodHandle* bootstrapEqualsMethodHandle = nullptr;

	ClassState state = CLASS_STATE_NONE;
	bool metaInited = false;
	bool primitive = false;
	bool hidden = false;
	bool constantPoolInited = false;
	bool byteCodeClass = false;
	int32_t arrayIndexScale = 0;
	int32_t arrayIndexScaleShift = 0;
	int32_t size = 0;
	int32_t mark = 0;

#define $USE_COMPRESS_OBJECT_FIELD_OFFSET_FLAGS
#ifdef $USE_COMPRESS_OBJECT_FIELD_OFFSET_FLAGS
	uint64_t objectFieldOffsetFlags = 0;
	inline bool needRecordObjectFieldOffset(int32_t fieldOffset) {
		int32_t index = fieldOffset / sizeof(void*);
		if ((index < (sizeof(objectFieldOffsetFlags) * 8)) && (((objectFieldOffsetFlags >> index) & 1) == 1)) {
			return false;
		}
		return true;
	}
#else
	int8_t* objectFieldOffsetFlags = nullptr;
	inline bool needRecordObjectFieldOffset(int32_t fieldOffset) {
		int32_t index = fieldOffset / sizeof(void*);
		if (index > 0 && index < size / sizeof(void*) && objectFieldOffsetFlags[index] == 0) {
			return true;
		}
		return false;
	}
#endif
	int32_t objectFieldOffsetArrayLength = 0;
	int32_t* objectFieldOffsetArray = nullptr;
	int32_t classCastOffsetArrayLength = 0;
	ClassCastOffset* classCastOffsetArray = nullptr;
};

	} // lang
} // java

#pragma pop_macro("ANNOTATION")
#pragma pop_macro("EMPTY_CLASS_ARRAY")
#pragma pop_macro("ENUM")
#pragma pop_macro("SYNTHETIC")

#endif // _java_lang_Class_h_