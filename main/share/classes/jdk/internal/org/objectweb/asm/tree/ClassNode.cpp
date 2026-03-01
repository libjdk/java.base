#include <jdk/internal/org/objectweb/asm/tree/ClassNode.h>

#include <java/lang/IllegalStateException.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <jdk/internal/org/objectweb/asm/AnnotationVisitor.h>
#include <jdk/internal/org/objectweb/asm/Attribute.h>
#include <jdk/internal/org/objectweb/asm/ClassVisitor.h>
#include <jdk/internal/org/objectweb/asm/FieldVisitor.h>
#include <jdk/internal/org/objectweb/asm/MethodVisitor.h>
#include <jdk/internal/org/objectweb/asm/ModuleVisitor.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/RecordComponentVisitor.h>
#include <jdk/internal/org/objectweb/asm/TypePath.h>
#include <jdk/internal/org/objectweb/asm/tree/AnnotationNode.h>
#include <jdk/internal/org/objectweb/asm/tree/FieldNode.h>
#include <jdk/internal/org/objectweb/asm/tree/InnerClassNode.h>
#include <jdk/internal/org/objectweb/asm/tree/MethodNode.h>
#include <jdk/internal/org/objectweb/asm/tree/ModuleNode.h>
#include <jdk/internal/org/objectweb/asm/tree/RecordComponentNode.h>
#include <jdk/internal/org/objectweb/asm/tree/TypeAnnotationNode.h>
#include <jdk/internal/org/objectweb/asm/tree/UnsupportedClassVersionException.h>
#include <jdk/internal/org/objectweb/asm/tree/Util.h>
#include <jcpp.h>

#undef ACC_RECORD
#undef ASM5
#undef ASM6
#undef ASM7
#undef ASM8
#undef ASM9_EXPERIMENTAL

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $AnnotationVisitor = ::jdk::internal::org::objectweb::asm$::AnnotationVisitor;
using $Attribute = ::jdk::internal::org::objectweb::asm$::Attribute;
using $ClassVisitor = ::jdk::internal::org::objectweb::asm$::ClassVisitor;
using $FieldVisitor = ::jdk::internal::org::objectweb::asm$::FieldVisitor;
using $MethodVisitor = ::jdk::internal::org::objectweb::asm$::MethodVisitor;
using $ModuleVisitor = ::jdk::internal::org::objectweb::asm$::ModuleVisitor;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $RecordComponentVisitor = ::jdk::internal::org::objectweb::asm$::RecordComponentVisitor;
using $TypePath = ::jdk::internal::org::objectweb::asm$::TypePath;
using $AnnotationNode = ::jdk::internal::org::objectweb::asm$::tree::AnnotationNode;
using $FieldNode = ::jdk::internal::org::objectweb::asm$::tree::FieldNode;
using $InnerClassNode = ::jdk::internal::org::objectweb::asm$::tree::InnerClassNode;
using $MethodNode = ::jdk::internal::org::objectweb::asm$::tree::MethodNode;
using $ModuleNode = ::jdk::internal::org::objectweb::asm$::tree::ModuleNode;
using $RecordComponentNode = ::jdk::internal::org::objectweb::asm$::tree::RecordComponentNode;
using $TypeAnnotationNode = ::jdk::internal::org::objectweb::asm$::tree::TypeAnnotationNode;
using $UnsupportedClassVersionException = ::jdk::internal::org::objectweb::asm$::tree::UnsupportedClassVersionException;
using $Util = ::jdk::internal::org::objectweb::asm$::tree::Util;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace tree {

$CompoundAttribute _ClassNode_FieldAnnotations_permittedSubclassesExperimental[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _ClassNode_MethodAnnotations_visitPermittedSubclassExperimental15[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _ClassNode_FieldInfo_[] = {
	{"version", "I", nullptr, $PUBLIC, $field(ClassNode, version)},
	{"access", "I", nullptr, $PUBLIC, $field(ClassNode, access)},
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(ClassNode, name)},
	{"signature", "Ljava/lang/String;", nullptr, $PUBLIC, $field(ClassNode, signature)},
	{"superName", "Ljava/lang/String;", nullptr, $PUBLIC, $field(ClassNode, superName)},
	{"interfaces", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PUBLIC, $field(ClassNode, interfaces)},
	{"sourceFile", "Ljava/lang/String;", nullptr, $PUBLIC, $field(ClassNode, sourceFile)},
	{"sourceDebug", "Ljava/lang/String;", nullptr, $PUBLIC, $field(ClassNode, sourceDebug)},
	{"module", "Ljdk/internal/org/objectweb/asm/tree/ModuleNode;", nullptr, $PUBLIC, $field(ClassNode, module)},
	{"outerClass", "Ljava/lang/String;", nullptr, $PUBLIC, $field(ClassNode, outerClass)},
	{"outerMethod", "Ljava/lang/String;", nullptr, $PUBLIC, $field(ClassNode, outerMethod)},
	{"outerMethodDesc", "Ljava/lang/String;", nullptr, $PUBLIC, $field(ClassNode, outerMethodDesc)},
	{"visibleAnnotations", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/AnnotationNode;>;", $PUBLIC, $field(ClassNode, visibleAnnotations)},
	{"invisibleAnnotations", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/AnnotationNode;>;", $PUBLIC, $field(ClassNode, invisibleAnnotations)},
	{"visibleTypeAnnotations", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/TypeAnnotationNode;>;", $PUBLIC, $field(ClassNode, visibleTypeAnnotations)},
	{"invisibleTypeAnnotations", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/TypeAnnotationNode;>;", $PUBLIC, $field(ClassNode, invisibleTypeAnnotations)},
	{"attrs", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/org/objectweb/asm/Attribute;>;", $PUBLIC, $field(ClassNode, attrs)},
	{"innerClasses", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/InnerClassNode;>;", $PUBLIC, $field(ClassNode, innerClasses)},
	{"nestHostClass", "Ljava/lang/String;", nullptr, $PUBLIC, $field(ClassNode, nestHostClass)},
	{"nestMembers", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PUBLIC, $field(ClassNode, nestMembers)},
	{"permittedSubclassesExperimental", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PUBLIC | $DEPRECATED, $field(ClassNode, permittedSubclassesExperimental), _ClassNode_FieldAnnotations_permittedSubclassesExperimental},
	{"recordComponents", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/RecordComponentNode;>;", $PUBLIC, $field(ClassNode, recordComponents)},
	{"fields", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/FieldNode;>;", $PUBLIC, $field(ClassNode, fields)},
	{"methods", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/MethodNode;>;", $PUBLIC, $field(ClassNode, methods)},
	{}
};

$MethodInfo _ClassNode_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ClassNode, init$, void)},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(ClassNode, init$, void, int32_t)},
	{"accept", "(Ljdk/internal/org/objectweb/asm/ClassVisitor;)V", nullptr, $PUBLIC, $virtualMethod(ClassNode, accept, void, $ClassVisitor*)},
	{"check", "(I)V", nullptr, $PUBLIC, $virtualMethod(ClassNode, check, void, int32_t)},
	{"visit", "(IILjava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ClassNode, visit, void, int32_t, int32_t, $String*, $String*, $String*, $StringArray*)},
	{"visitAnnotation", "(Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/AnnotationVisitor;", nullptr, $PUBLIC, $virtualMethod(ClassNode, visitAnnotation, $AnnotationVisitor*, $String*, bool)},
	{"visitAttribute", "(Ljdk/internal/org/objectweb/asm/Attribute;)V", nullptr, $PUBLIC, $virtualMethod(ClassNode, visitAttribute, void, $Attribute*)},
	{"visitEnd", "()V", nullptr, $PUBLIC, $virtualMethod(ClassNode, visitEnd, void)},
	{"visitField", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Object;)Ljdk/internal/org/objectweb/asm/FieldVisitor;", nullptr, $PUBLIC, $virtualMethod(ClassNode, visitField, $FieldVisitor*, int32_t, $String*, $String*, $String*, Object$*)},
	{"visitInnerClass", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V", nullptr, $PUBLIC, $virtualMethod(ClassNode, visitInnerClass, void, $String*, $String*, $String*, int32_t)},
	{"visitMethod", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/MethodVisitor;", nullptr, $PUBLIC, $virtualMethod(ClassNode, visitMethod, $MethodVisitor*, int32_t, $String*, $String*, $String*, $StringArray*)},
	{"visitModule", "(Ljava/lang/String;ILjava/lang/String;)Ljdk/internal/org/objectweb/asm/ModuleVisitor;", nullptr, $PUBLIC, $virtualMethod(ClassNode, visitModule, $ModuleVisitor*, $String*, int32_t, $String*)},
	{"visitNestHost", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ClassNode, visitNestHost, void, $String*)},
	{"visitNestMember", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ClassNode, visitNestMember, void, $String*)},
	{"visitOuterClass", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ClassNode, visitOuterClass, void, $String*, $String*, $String*)},
	{"visitPermittedSubclassExperimental", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(ClassNode, visitPermittedSubclassExperimental, void, $String*), nullptr, nullptr, _ClassNode_MethodAnnotations_visitPermittedSubclassExperimental15},
	{"visitRecordComponent", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/RecordComponentVisitor;", nullptr, $PUBLIC, $virtualMethod(ClassNode, visitRecordComponent, $RecordComponentVisitor*, $String*, $String*, $String*)},
	{"visitSource", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ClassNode, visitSource, void, $String*, $String*)},
	{"visitTypeAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/AnnotationVisitor;", nullptr, $PUBLIC, $virtualMethod(ClassNode, visitTypeAnnotation, $AnnotationVisitor*, int32_t, $TypePath*, $String*, bool)},
	{}
};

$ClassInfo _ClassNode_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.tree.ClassNode",
	"jdk.internal.org.objectweb.asm.ClassVisitor",
	nullptr,
	_ClassNode_FieldInfo_,
	_ClassNode_MethodInfo_
};

$Object* allocate$ClassNode($Class* clazz) {
	return $of($alloc(ClassNode));
}

void ClassNode::init$() {
	ClassNode::init$($Opcodes::ASM8);
	if ($of(this)->getClass() != ClassNode::class$) {
		$throwNew($IllegalStateException);
	}
}

void ClassNode::init$(int32_t api) {
	$ClassVisitor::init$(api);
	$set(this, interfaces, $new($ArrayList));
	$set(this, innerClasses, $new($ArrayList));
	$set(this, fields, $new($ArrayList));
	$set(this, methods, $new($ArrayList));
}

void ClassNode::visit(int32_t version, int32_t access, $String* name, $String* signature, $String* superName, $StringArray* interfaces) {
	this->version = version;
	this->access = access;
	$set(this, name, name);
	$set(this, signature, signature);
	$set(this, superName, superName);
	$set(this, interfaces, $Util::asArrayList(interfaces));
}

void ClassNode::visitSource($String* file, $String* debug) {
	$set(this, sourceFile, file);
	$set(this, sourceDebug, debug);
}

$ModuleVisitor* ClassNode::visitModule($String* name, int32_t access, $String* version) {
	$set(this, module, $new($ModuleNode, name, access, version));
	return this->module;
}

void ClassNode::visitNestHost($String* nestHost) {
	$set(this, nestHostClass, nestHost);
}

void ClassNode::visitOuterClass($String* owner, $String* name, $String* descriptor) {
	$set(this, outerClass, owner);
	$set(this, outerMethod, name);
	$set(this, outerMethodDesc, descriptor);
}

$AnnotationVisitor* ClassNode::visitAnnotation($String* descriptor, bool visible) {
	$var($AnnotationNode, annotation, $new($AnnotationNode, descriptor));
	if (visible) {
		$set(this, visibleAnnotations, $Util::add(this->visibleAnnotations, annotation));
	} else {
		$set(this, invisibleAnnotations, $Util::add(this->invisibleAnnotations, annotation));
	}
	return annotation;
}

$AnnotationVisitor* ClassNode::visitTypeAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	$var($TypeAnnotationNode, typeAnnotation, $new($TypeAnnotationNode, typeRef, typePath, descriptor));
	if (visible) {
		$set(this, visibleTypeAnnotations, $Util::add(this->visibleTypeAnnotations, typeAnnotation));
	} else {
		$set(this, invisibleTypeAnnotations, $Util::add(this->invisibleTypeAnnotations, typeAnnotation));
	}
	return typeAnnotation;
}

void ClassNode::visitAttribute($Attribute* attribute) {
	$set(this, attrs, $Util::add(this->attrs, attribute));
}

void ClassNode::visitNestMember($String* nestMember) {
	$set(this, nestMembers, $Util::add(this->nestMembers, nestMember));
}

void ClassNode::visitPermittedSubclassExperimental($String* permittedSubclass) {
	$set(this, permittedSubclassesExperimental, $Util::add(this->permittedSubclassesExperimental, permittedSubclass));
}

void ClassNode::visitInnerClass($String* name, $String* outerName, $String* innerName, int32_t access) {
	$var($InnerClassNode, innerClass, $new($InnerClassNode, name, outerName, innerName, access));
	$nc(this->innerClasses)->add(innerClass);
}

$RecordComponentVisitor* ClassNode::visitRecordComponent($String* name, $String* descriptor, $String* signature) {
	$var($RecordComponentNode, recordComponent, $new($RecordComponentNode, name, descriptor, signature));
	$set(this, recordComponents, $Util::add(this->recordComponents, recordComponent));
	return recordComponent;
}

$FieldVisitor* ClassNode::visitField(int32_t access, $String* name, $String* descriptor, $String* signature, Object$* value) {
	$var($FieldNode, field, $new($FieldNode, access, name, descriptor, signature, value));
	$nc(this->fields)->add(field);
	return field;
}

$MethodVisitor* ClassNode::visitMethod(int32_t access, $String* name, $String* descriptor, $String* signature, $StringArray* exceptions) {
	$var($MethodNode, method, $new($MethodNode, access, name, descriptor, signature, exceptions));
	$nc(this->methods)->add(method);
	return method;
}

void ClassNode::visitEnd() {
}

void ClassNode::check(int32_t api) {
	$useLocalCurrentObjectStackCache();
	if (api != $Opcodes::ASM9_EXPERIMENTAL && this->permittedSubclassesExperimental != nullptr) {
		$throwNew($UnsupportedClassVersionException);
	}
	if (api < $Opcodes::ASM8 && (((int32_t)(this->access & (uint32_t)$Opcodes::ACC_RECORD)) != 0 || this->recordComponents != nullptr)) {
		$throwNew($UnsupportedClassVersionException);
	}
	if (api < $Opcodes::ASM7 && (this->nestHostClass != nullptr || this->nestMembers != nullptr)) {
		$throwNew($UnsupportedClassVersionException);
	}
	if (api < $Opcodes::ASM6 && this->module != nullptr) {
		$throwNew($UnsupportedClassVersionException);
	}
	if (api < $Opcodes::ASM5) {
		if (this->visibleTypeAnnotations != nullptr && !$nc(this->visibleTypeAnnotations)->isEmpty()) {
			$throwNew($UnsupportedClassVersionException);
		}
		if (this->invisibleTypeAnnotations != nullptr && !$nc(this->invisibleTypeAnnotations)->isEmpty()) {
			$throwNew($UnsupportedClassVersionException);
		}
	}
	if (this->visibleAnnotations != nullptr) {
		for (int32_t i = $nc(this->visibleAnnotations)->size() - 1; i >= 0; --i) {
			$nc(($cast($AnnotationNode, $($nc(this->visibleAnnotations)->get(i)))))->check(api);
		}
	}
	if (this->invisibleAnnotations != nullptr) {
		for (int32_t i = $nc(this->invisibleAnnotations)->size() - 1; i >= 0; --i) {
			$nc(($cast($AnnotationNode, $($nc(this->invisibleAnnotations)->get(i)))))->check(api);
		}
	}
	if (this->visibleTypeAnnotations != nullptr) {
		for (int32_t i = $nc(this->visibleTypeAnnotations)->size() - 1; i >= 0; --i) {
			$nc(($cast($TypeAnnotationNode, $($nc(this->visibleTypeAnnotations)->get(i)))))->check(api);
		}
	}
	if (this->invisibleTypeAnnotations != nullptr) {
		for (int32_t i = $nc(this->invisibleTypeAnnotations)->size() - 1; i >= 0; --i) {
			$nc(($cast($TypeAnnotationNode, $($nc(this->invisibleTypeAnnotations)->get(i)))))->check(api);
		}
	}
	if (this->recordComponents != nullptr) {
		for (int32_t i = $nc(this->recordComponents)->size() - 1; i >= 0; --i) {
			$nc(($cast($RecordComponentNode, $($nc(this->recordComponents)->get(i)))))->check(api);
		}
	}
	for (int32_t i = $nc(this->fields)->size() - 1; i >= 0; --i) {
		$nc(($cast($FieldNode, $($nc(this->fields)->get(i)))))->check(api);
	}
	for (int32_t i = $nc(this->methods)->size() - 1; i >= 0; --i) {
		$nc(($cast($MethodNode, $($nc(this->methods)->get(i)))))->check(api);
	}
}

void ClassNode::accept($ClassVisitor* classVisitor) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, interfacesArray, $new($StringArray, $nc(this->interfaces)->size()));
	$nc(this->interfaces)->toArray(interfacesArray);
	$nc(classVisitor)->visit(this->version, this->access, this->name, this->signature, this->superName, interfacesArray);
	if (this->sourceFile != nullptr || this->sourceDebug != nullptr) {
		classVisitor->visitSource(this->sourceFile, this->sourceDebug);
	}
	if (this->module != nullptr) {
		$nc(this->module)->accept(classVisitor);
	}
	if (this->nestHostClass != nullptr) {
		classVisitor->visitNestHost(this->nestHostClass);
	}
	if (this->outerClass != nullptr) {
		classVisitor->visitOuterClass(this->outerClass, this->outerMethod, this->outerMethodDesc);
	}
	if (this->visibleAnnotations != nullptr) {
		{
			int32_t i = 0;
			int32_t n = $nc(this->visibleAnnotations)->size();
			for (; i < n; ++i) {
				$var($AnnotationNode, annotation, $cast($AnnotationNode, $nc(this->visibleAnnotations)->get(i)));
				$nc(annotation)->accept($(classVisitor->visitAnnotation(annotation->desc, true)));
			}
		}
	}
	if (this->invisibleAnnotations != nullptr) {
		{
			int32_t i = 0;
			int32_t n = $nc(this->invisibleAnnotations)->size();
			for (; i < n; ++i) {
				$var($AnnotationNode, annotation, $cast($AnnotationNode, $nc(this->invisibleAnnotations)->get(i)));
				$nc(annotation)->accept($(classVisitor->visitAnnotation(annotation->desc, false)));
			}
		}
	}
	if (this->visibleTypeAnnotations != nullptr) {
		{
			int32_t i = 0;
			int32_t n = $nc(this->visibleTypeAnnotations)->size();
			for (; i < n; ++i) {
				$var($TypeAnnotationNode, typeAnnotation, $cast($TypeAnnotationNode, $nc(this->visibleTypeAnnotations)->get(i)));
				$nc(typeAnnotation)->accept($(classVisitor->visitTypeAnnotation(typeAnnotation->typeRef, typeAnnotation->typePath, typeAnnotation->desc, true)));
			}
		}
	}
	if (this->invisibleTypeAnnotations != nullptr) {
		{
			int32_t i = 0;
			int32_t n = $nc(this->invisibleTypeAnnotations)->size();
			for (; i < n; ++i) {
				$var($TypeAnnotationNode, typeAnnotation, $cast($TypeAnnotationNode, $nc(this->invisibleTypeAnnotations)->get(i)));
				$nc(typeAnnotation)->accept($(classVisitor->visitTypeAnnotation(typeAnnotation->typeRef, typeAnnotation->typePath, typeAnnotation->desc, false)));
			}
		}
	}
	if (this->attrs != nullptr) {
		{
			int32_t i = 0;
			int32_t n = $nc(this->attrs)->size();
			for (; i < n; ++i) {
				classVisitor->visitAttribute($cast($Attribute, $($nc(this->attrs)->get(i))));
			}
		}
	}
	if (this->nestMembers != nullptr) {
		{
			int32_t i = 0;
			int32_t n = $nc(this->nestMembers)->size();
			for (; i < n; ++i) {
				classVisitor->visitNestMember($cast($String, $($nc(this->nestMembers)->get(i))));
			}
		}
	}
	if (this->permittedSubclassesExperimental != nullptr) {
		{
			int32_t i = 0;
			int32_t n = $nc(this->permittedSubclassesExperimental)->size();
			for (; i < n; ++i) {
				classVisitor->visitPermittedSubclassExperimental($cast($String, $($nc(this->permittedSubclassesExperimental)->get(i))));
			}
		}
	}
	{
		int32_t i = 0;
		int32_t n = $nc(this->innerClasses)->size();
		for (; i < n; ++i) {
			$nc(($cast($InnerClassNode, $($nc(this->innerClasses)->get(i)))))->accept(classVisitor);
		}
	}
	if (this->recordComponents != nullptr) {
		{
			int32_t i = 0;
			int32_t n = $nc(this->recordComponents)->size();
			for (; i < n; ++i) {
				$nc(($cast($RecordComponentNode, $($nc(this->recordComponents)->get(i)))))->accept(classVisitor);
			}
		}
	}
	{
		int32_t i = 0;
		int32_t n = $nc(this->fields)->size();
		for (; i < n; ++i) {
			$nc(($cast($FieldNode, $($nc(this->fields)->get(i)))))->accept(classVisitor);
		}
	}
	{
		int32_t i = 0;
		int32_t n = $nc(this->methods)->size();
		for (; i < n; ++i) {
			$nc(($cast($MethodNode, $($nc(this->methods)->get(i)))))->accept(classVisitor);
		}
	}
	classVisitor->visitEnd();
}

ClassNode::ClassNode() {
}

$Class* ClassNode::load$($String* name, bool initialize) {
	$loadClass(ClassNode, name, initialize, &_ClassNode_ClassInfo_, allocate$ClassNode);
	return class$;
}

$Class* ClassNode::class$ = nullptr;

					} // tree
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk