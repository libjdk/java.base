#include <jdk/internal/org/objectweb/asm/commons/RemappingClassAdapter.h>

#include <jdk/internal/org/objectweb/asm/AnnotationVisitor.h>
#include <jdk/internal/org/objectweb/asm/ClassVisitor.h>
#include <jdk/internal/org/objectweb/asm/FieldVisitor.h>
#include <jdk/internal/org/objectweb/asm/MethodVisitor.h>
#include <jdk/internal/org/objectweb/asm/ModuleVisitor.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/TypePath.h>
#include <jdk/internal/org/objectweb/asm/commons/Remapper.h>
#include <jdk/internal/org/objectweb/asm/commons/RemappingAnnotationAdapter.h>
#include <jdk/internal/org/objectweb/asm/commons/RemappingFieldAdapter.h>
#include <jdk/internal/org/objectweb/asm/commons/RemappingMethodAdapter.h>
#include <jcpp.h>

#undef ASM6

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $AnnotationVisitor = ::jdk::internal::org::objectweb::asm$::AnnotationVisitor;
using $ClassVisitor = ::jdk::internal::org::objectweb::asm$::ClassVisitor;
using $FieldVisitor = ::jdk::internal::org::objectweb::asm$::FieldVisitor;
using $MethodVisitor = ::jdk::internal::org::objectweb::asm$::MethodVisitor;
using $ModuleVisitor = ::jdk::internal::org::objectweb::asm$::ModuleVisitor;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $TypePath = ::jdk::internal::org::objectweb::asm$::TypePath;
using $Remapper = ::jdk::internal::org::objectweb::asm$::commons::Remapper;
using $RemappingAnnotationAdapter = ::jdk::internal::org::objectweb::asm$::commons::RemappingAnnotationAdapter;
using $RemappingFieldAdapter = ::jdk::internal::org::objectweb::asm$::commons::RemappingFieldAdapter;
using $RemappingMethodAdapter = ::jdk::internal::org::objectweb::asm$::commons::RemappingMethodAdapter;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace commons {

$CompoundAttribute _RemappingClassAdapter_Annotations_[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _RemappingClassAdapter_FieldInfo_[] = {
	{"remapper", "Ljdk/internal/org/objectweb/asm/commons/Remapper;", nullptr, $PROTECTED | $FINAL, $field(RemappingClassAdapter, remapper)},
	{"className", "Ljava/lang/String;", nullptr, $PROTECTED, $field(RemappingClassAdapter, className)},
	{}
};

$MethodInfo _RemappingClassAdapter_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/org/objectweb/asm/ClassVisitor;Ljdk/internal/org/objectweb/asm/commons/Remapper;)V", nullptr, $PUBLIC, $method(RemappingClassAdapter, init$, void, $ClassVisitor*, $Remapper*)},
	{"<init>", "(ILjdk/internal/org/objectweb/asm/ClassVisitor;Ljdk/internal/org/objectweb/asm/commons/Remapper;)V", nullptr, $PROTECTED, $method(RemappingClassAdapter, init$, void, int32_t, $ClassVisitor*, $Remapper*)},
	{"createRemappingAnnotationAdapter", "(Ljdk/internal/org/objectweb/asm/AnnotationVisitor;)Ljdk/internal/org/objectweb/asm/AnnotationVisitor;", nullptr, $PROTECTED, $virtualMethod(RemappingClassAdapter, createRemappingAnnotationAdapter, $AnnotationVisitor*, $AnnotationVisitor*)},
	{"createRemappingFieldAdapter", "(Ljdk/internal/org/objectweb/asm/FieldVisitor;)Ljdk/internal/org/objectweb/asm/FieldVisitor;", nullptr, $PROTECTED, $virtualMethod(RemappingClassAdapter, createRemappingFieldAdapter, $FieldVisitor*, $FieldVisitor*)},
	{"createRemappingMethodAdapter", "(ILjava/lang/String;Ljdk/internal/org/objectweb/asm/MethodVisitor;)Ljdk/internal/org/objectweb/asm/MethodVisitor;", nullptr, $PROTECTED, $virtualMethod(RemappingClassAdapter, createRemappingMethodAdapter, $MethodVisitor*, int32_t, $String*, $MethodVisitor*)},
	{"visit", "(IILjava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(RemappingClassAdapter, visit, void, int32_t, int32_t, $String*, $String*, $String*, $StringArray*)},
	{"visitAnnotation", "(Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/AnnotationVisitor;", nullptr, $PUBLIC, $virtualMethod(RemappingClassAdapter, visitAnnotation, $AnnotationVisitor*, $String*, bool)},
	{"visitField", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Object;)Ljdk/internal/org/objectweb/asm/FieldVisitor;", nullptr, $PUBLIC, $virtualMethod(RemappingClassAdapter, visitField, $FieldVisitor*, int32_t, $String*, $String*, $String*, Object$*)},
	{"visitInnerClass", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V", nullptr, $PUBLIC, $virtualMethod(RemappingClassAdapter, visitInnerClass, void, $String*, $String*, $String*, int32_t)},
	{"visitMethod", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/MethodVisitor;", nullptr, $PUBLIC, $virtualMethod(RemappingClassAdapter, visitMethod, $MethodVisitor*, int32_t, $String*, $String*, $String*, $StringArray*)},
	{"visitModule", "(Ljava/lang/String;ILjava/lang/String;)Ljdk/internal/org/objectweb/asm/ModuleVisitor;", nullptr, $PUBLIC, $virtualMethod(RemappingClassAdapter, visitModule, $ModuleVisitor*, $String*, int32_t, $String*)},
	{"visitOuterClass", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(RemappingClassAdapter, visitOuterClass, void, $String*, $String*, $String*)},
	{"visitTypeAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/AnnotationVisitor;", nullptr, $PUBLIC, $virtualMethod(RemappingClassAdapter, visitTypeAnnotation, $AnnotationVisitor*, int32_t, $TypePath*, $String*, bool)},
	{}
};

$ClassInfo _RemappingClassAdapter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.commons.RemappingClassAdapter",
	"jdk.internal.org.objectweb.asm.ClassVisitor",
	nullptr,
	_RemappingClassAdapter_FieldInfo_,
	_RemappingClassAdapter_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_RemappingClassAdapter_Annotations_
};

$Object* allocate$RemappingClassAdapter($Class* clazz) {
	return $of($alloc(RemappingClassAdapter));
}

void RemappingClassAdapter::init$($ClassVisitor* classVisitor, $Remapper* remapper) {
	RemappingClassAdapter::init$($Opcodes::ASM6, classVisitor, remapper);
}

void RemappingClassAdapter::init$(int32_t api, $ClassVisitor* classVisitor, $Remapper* remapper) {
	$ClassVisitor::init$(api, classVisitor);
	$set(this, remapper, remapper);
}

void RemappingClassAdapter::visit(int32_t version, int32_t access, $String* name, $String* signature, $String* superName, $StringArray* interfaces) {
	$useLocalCurrentObjectStackCache();
	$set(this, className, name);
	int32_t var$0 = version;
	int32_t var$1 = access;
	$var($String, var$2, $nc(this->remapper)->mapType(name));
	$var($String, var$3, $nc(this->remapper)->mapSignature(signature, false));
	$var($String, var$4, $nc(this->remapper)->mapType(superName));
	$ClassVisitor::visit(var$0, var$1, var$2, var$3, var$4, interfaces == nullptr ? ($StringArray*)nullptr : $($nc(this->remapper)->mapTypes(interfaces)));
}

$ModuleVisitor* RemappingClassAdapter::visitModule($String* name, int32_t flags, $String* version) {
	$throwNew($RuntimeException, "RemappingClassAdapter is deprecated, use ClassRemapper instead"_s);
	$shouldNotReachHere();
}

$AnnotationVisitor* RemappingClassAdapter::visitAnnotation($String* descriptor, bool visible) {
	$useLocalCurrentObjectStackCache();
	$var($AnnotationVisitor, annotationVisitor, $ClassVisitor::visitAnnotation($($nc(this->remapper)->mapDesc(descriptor)), visible));
	return annotationVisitor == nullptr ? ($AnnotationVisitor*)nullptr : createRemappingAnnotationAdapter(annotationVisitor);
}

$AnnotationVisitor* RemappingClassAdapter::visitTypeAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	$useLocalCurrentObjectStackCache();
	$var($AnnotationVisitor, annotationVisitor, $ClassVisitor::visitTypeAnnotation(typeRef, typePath, $($nc(this->remapper)->mapDesc(descriptor)), visible));
	return annotationVisitor == nullptr ? ($AnnotationVisitor*)nullptr : createRemappingAnnotationAdapter(annotationVisitor);
}

$FieldVisitor* RemappingClassAdapter::visitField(int32_t access, $String* name, $String* descriptor, $String* signature, Object$* value) {
	$useLocalCurrentObjectStackCache();
	int32_t var$0 = access;
	$var($String, var$1, $nc(this->remapper)->mapFieldName(this->className, name, descriptor));
	$var($String, var$2, $nc(this->remapper)->mapDesc(descriptor));
	$var($String, var$3, $nc(this->remapper)->mapSignature(signature, true));
	$var($FieldVisitor, fieldVisitor, $ClassVisitor::visitField(var$0, var$1, var$2, var$3, $($nc(this->remapper)->mapValue(value))));
	return fieldVisitor == nullptr ? ($FieldVisitor*)nullptr : createRemappingFieldAdapter(fieldVisitor);
}

$MethodVisitor* RemappingClassAdapter::visitMethod(int32_t access, $String* name, $String* descriptor, $String* signature, $StringArray* exceptions) {
	$useLocalCurrentObjectStackCache();
	$var($String, newDescriptor, $nc(this->remapper)->mapMethodDesc(descriptor));
	int32_t var$0 = access;
	$var($String, var$1, $nc(this->remapper)->mapMethodName(this->className, name, descriptor));
	$var($String, var$2, newDescriptor);
	$var($String, var$3, $nc(this->remapper)->mapSignature(signature, false));
	$var($MethodVisitor, methodVisitor, $ClassVisitor::visitMethod(var$0, var$1, var$2, var$3, exceptions == nullptr ? ($StringArray*)nullptr : $($nc(this->remapper)->mapTypes(exceptions))));
	return methodVisitor == nullptr ? ($MethodVisitor*)nullptr : createRemappingMethodAdapter(access, newDescriptor, methodVisitor);
}

void RemappingClassAdapter::visitInnerClass($String* name, $String* outerName, $String* innerName, int32_t access) {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $nc(this->remapper)->mapType(name));
	$ClassVisitor::visitInnerClass(var$0, outerName == nullptr ? ($String*)nullptr : $($nc(this->remapper)->mapType(outerName)), innerName, access);
}

void RemappingClassAdapter::visitOuterClass($String* owner, $String* name, $String* descriptor) {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $nc(this->remapper)->mapType(owner));
	$var($String, var$1, name == nullptr ? ($String*)nullptr : $nc(this->remapper)->mapMethodName(owner, name, descriptor));
	$ClassVisitor::visitOuterClass(var$0, var$1, descriptor == nullptr ? ($String*)nullptr : $($nc(this->remapper)->mapMethodDesc(descriptor)));
}

$FieldVisitor* RemappingClassAdapter::createRemappingFieldAdapter($FieldVisitor* fieldVisitor) {
	return $new($RemappingFieldAdapter, fieldVisitor, this->remapper);
}

$MethodVisitor* RemappingClassAdapter::createRemappingMethodAdapter(int32_t access, $String* newDescriptor, $MethodVisitor* methodVisitior) {
	return $new($RemappingMethodAdapter, access, newDescriptor, methodVisitior, this->remapper);
}

$AnnotationVisitor* RemappingClassAdapter::createRemappingAnnotationAdapter($AnnotationVisitor* av) {
	return $new($RemappingAnnotationAdapter, av, this->remapper);
}

RemappingClassAdapter::RemappingClassAdapter() {
}

$Class* RemappingClassAdapter::load$($String* name, bool initialize) {
	$loadClass(RemappingClassAdapter, name, initialize, &_RemappingClassAdapter_ClassInfo_, allocate$RemappingClassAdapter);
	return class$;
}

$Class* RemappingClassAdapter::class$ = nullptr;

					} // commons
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk