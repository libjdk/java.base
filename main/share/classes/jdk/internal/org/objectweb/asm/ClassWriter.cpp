#include <jdk/internal/org/objectweb/asm/ClassWriter.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/TypeNotPresentException.h>
#include <jdk/internal/org/objectweb/asm/AnnotationVisitor.h>
#include <jdk/internal/org/objectweb/asm/AnnotationWriter.h>
#include <jdk/internal/org/objectweb/asm/Attribute$Set.h>
#include <jdk/internal/org/objectweb/asm/Attribute.h>
#include <jdk/internal/org/objectweb/asm/ByteVector.h>
#include <jdk/internal/org/objectweb/asm/ClassReader.h>
#include <jdk/internal/org/objectweb/asm/ClassTooLargeException.h>
#include <jdk/internal/org/objectweb/asm/ClassVisitor.h>
#include <jdk/internal/org/objectweb/asm/Constants.h>
#include <jdk/internal/org/objectweb/asm/FieldVisitor.h>
#include <jdk/internal/org/objectweb/asm/FieldWriter.h>
#include <jdk/internal/org/objectweb/asm/Handle.h>
#include <jdk/internal/org/objectweb/asm/MethodVisitor.h>
#include <jdk/internal/org/objectweb/asm/MethodWriter.h>
#include <jdk/internal/org/objectweb/asm/ModuleVisitor.h>
#include <jdk/internal/org/objectweb/asm/ModuleWriter.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/RecordComponentVisitor.h>
#include <jdk/internal/org/objectweb/asm/RecordComponentWriter.h>
#include <jdk/internal/org/objectweb/asm/Symbol.h>
#include <jdk/internal/org/objectweb/asm/SymbolTable.h>
#include <jdk/internal/org/objectweb/asm/TypePath.h>
#include <jcpp.h>

#undef ACC_DEPRECATED
#undef ACC_RECORD
#undef ACC_SYNTHETIC
#undef ASM8
#undef COMPUTE_ALL_FRAMES
#undef COMPUTE_FRAMES
#undef COMPUTE_INSERTED_FRAMES
#undef COMPUTE_MAXS
#undef COMPUTE_MAX_STACK_AND_LOCAL
#undef COMPUTE_MAX_STACK_AND_LOCAL_FROM_FRAMES
#undef COMPUTE_NOTHING
#undef DEPRECATED
#undef ENCLOSING_METHOD
#undef EXPAND_ASM_INSNS
#undef EXPAND_FRAMES
#undef H_INVOKEINTERFACE
#undef INNER_CLASSES
#undef MAX_VALUE
#undef NEST_HOST
#undef NEST_MEMBERS
#undef PERMITTED_SUBCLASSES
#undef RECORD
#undef RUNTIME_INVISIBLE_ANNOTATIONS
#undef RUNTIME_INVISIBLE_TYPE_ANNOTATIONS
#undef RUNTIME_VISIBLE_ANNOTATIONS
#undef RUNTIME_VISIBLE_TYPE_ANNOTATIONS
#undef SIGNATURE
#undef SOURCE_DEBUG_EXTENSION
#undef SOURCE_FILE
#undef SYNTHETIC

using $AttributeArray = $Array<::jdk::internal::org::objectweb::asm$::Attribute>;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $TypeNotPresentException = ::java::lang::TypeNotPresentException;
using $AnnotationVisitor = ::jdk::internal::org::objectweb::asm$::AnnotationVisitor;
using $AnnotationWriter = ::jdk::internal::org::objectweb::asm$::AnnotationWriter;
using $Attribute = ::jdk::internal::org::objectweb::asm$::Attribute;
using $Attribute$Set = ::jdk::internal::org::objectweb::asm$::Attribute$Set;
using $ByteVector = ::jdk::internal::org::objectweb::asm$::ByteVector;
using $ClassReader = ::jdk::internal::org::objectweb::asm$::ClassReader;
using $ClassTooLargeException = ::jdk::internal::org::objectweb::asm$::ClassTooLargeException;
using $ClassVisitor = ::jdk::internal::org::objectweb::asm$::ClassVisitor;
using $Constants = ::jdk::internal::org::objectweb::asm$::Constants;
using $FieldVisitor = ::jdk::internal::org::objectweb::asm$::FieldVisitor;
using $FieldWriter = ::jdk::internal::org::objectweb::asm$::FieldWriter;
using $Handle = ::jdk::internal::org::objectweb::asm$::Handle;
using $MethodVisitor = ::jdk::internal::org::objectweb::asm$::MethodVisitor;
using $MethodWriter = ::jdk::internal::org::objectweb::asm$::MethodWriter;
using $ModuleVisitor = ::jdk::internal::org::objectweb::asm$::ModuleVisitor;
using $ModuleWriter = ::jdk::internal::org::objectweb::asm$::ModuleWriter;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $RecordComponentVisitor = ::jdk::internal::org::objectweb::asm$::RecordComponentVisitor;
using $RecordComponentWriter = ::jdk::internal::org::objectweb::asm$::RecordComponentWriter;
using $Symbol = ::jdk::internal::org::objectweb::asm$::Symbol;
using $SymbolTable = ::jdk::internal::org::objectweb::asm$::SymbolTable;
using $TypePath = ::jdk::internal::org::objectweb::asm$::TypePath;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {

$CompoundAttribute _ClassWriter_MethodAnnotations_newHandle9[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _ClassWriter_MethodAnnotations_visitPermittedSubclassExperimental31[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _ClassWriter_FieldInfo_[] = {
	{"COMPUTE_MAXS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ClassWriter, COMPUTE_MAXS)},
	{"COMPUTE_FRAMES", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ClassWriter, COMPUTE_FRAMES)},
	{"version", "I", nullptr, $PRIVATE, $field(ClassWriter, version)},
	{"symbolTable", "Ljdk/internal/org/objectweb/asm/SymbolTable;", nullptr, $PRIVATE | $FINAL, $field(ClassWriter, symbolTable)},
	{"accessFlags", "I", nullptr, $PRIVATE, $field(ClassWriter, accessFlags)},
	{"thisClass", "I", nullptr, $PRIVATE, $field(ClassWriter, thisClass)},
	{"superClass", "I", nullptr, $PRIVATE, $field(ClassWriter, superClass)},
	{"interfaceCount", "I", nullptr, $PRIVATE, $field(ClassWriter, interfaceCount)},
	{"interfaces", "[I", nullptr, $PRIVATE, $field(ClassWriter, interfaces)},
	{"firstField", "Ljdk/internal/org/objectweb/asm/FieldWriter;", nullptr, $PRIVATE, $field(ClassWriter, firstField)},
	{"lastField", "Ljdk/internal/org/objectweb/asm/FieldWriter;", nullptr, $PRIVATE, $field(ClassWriter, lastField)},
	{"firstMethod", "Ljdk/internal/org/objectweb/asm/MethodWriter;", nullptr, $PRIVATE, $field(ClassWriter, firstMethod)},
	{"lastMethod", "Ljdk/internal/org/objectweb/asm/MethodWriter;", nullptr, $PRIVATE, $field(ClassWriter, lastMethod)},
	{"numberOfInnerClasses", "I", nullptr, $PRIVATE, $field(ClassWriter, numberOfInnerClasses)},
	{"innerClasses", "Ljdk/internal/org/objectweb/asm/ByteVector;", nullptr, $PRIVATE, $field(ClassWriter, innerClasses)},
	{"enclosingClassIndex", "I", nullptr, $PRIVATE, $field(ClassWriter, enclosingClassIndex)},
	{"enclosingMethodIndex", "I", nullptr, $PRIVATE, $field(ClassWriter, enclosingMethodIndex)},
	{"signatureIndex", "I", nullptr, $PRIVATE, $field(ClassWriter, signatureIndex)},
	{"sourceFileIndex", "I", nullptr, $PRIVATE, $field(ClassWriter, sourceFileIndex)},
	{"debugExtension", "Ljdk/internal/org/objectweb/asm/ByteVector;", nullptr, $PRIVATE, $field(ClassWriter, debugExtension)},
	{"lastRuntimeVisibleAnnotation", "Ljdk/internal/org/objectweb/asm/AnnotationWriter;", nullptr, $PRIVATE, $field(ClassWriter, lastRuntimeVisibleAnnotation)},
	{"lastRuntimeInvisibleAnnotation", "Ljdk/internal/org/objectweb/asm/AnnotationWriter;", nullptr, $PRIVATE, $field(ClassWriter, lastRuntimeInvisibleAnnotation)},
	{"lastRuntimeVisibleTypeAnnotation", "Ljdk/internal/org/objectweb/asm/AnnotationWriter;", nullptr, $PRIVATE, $field(ClassWriter, lastRuntimeVisibleTypeAnnotation)},
	{"lastRuntimeInvisibleTypeAnnotation", "Ljdk/internal/org/objectweb/asm/AnnotationWriter;", nullptr, $PRIVATE, $field(ClassWriter, lastRuntimeInvisibleTypeAnnotation)},
	{"moduleWriter", "Ljdk/internal/org/objectweb/asm/ModuleWriter;", nullptr, $PRIVATE, $field(ClassWriter, moduleWriter)},
	{"nestHostClassIndex", "I", nullptr, $PRIVATE, $field(ClassWriter, nestHostClassIndex)},
	{"numberOfNestMemberClasses", "I", nullptr, $PRIVATE, $field(ClassWriter, numberOfNestMemberClasses)},
	{"nestMemberClasses", "Ljdk/internal/org/objectweb/asm/ByteVector;", nullptr, $PRIVATE, $field(ClassWriter, nestMemberClasses)},
	{"numberOfPermittedSubclassClasses", "I", nullptr, $PRIVATE, $field(ClassWriter, numberOfPermittedSubclassClasses)},
	{"permittedSubclassClasses", "Ljdk/internal/org/objectweb/asm/ByteVector;", nullptr, $PRIVATE, $field(ClassWriter, permittedSubclassClasses)},
	{"firstRecordComponent", "Ljdk/internal/org/objectweb/asm/RecordComponentWriter;", nullptr, $PRIVATE, $field(ClassWriter, firstRecordComponent)},
	{"lastRecordComponent", "Ljdk/internal/org/objectweb/asm/RecordComponentWriter;", nullptr, $PRIVATE, $field(ClassWriter, lastRecordComponent)},
	{"firstAttribute", "Ljdk/internal/org/objectweb/asm/Attribute;", nullptr, $PRIVATE, $field(ClassWriter, firstAttribute)},
	{"compute", "I", nullptr, $PRIVATE, $field(ClassWriter, compute)},
	{}
};

$MethodInfo _ClassWriter_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(ClassWriter, init$, void, int32_t)},
	{"<init>", "(Ljdk/internal/org/objectweb/asm/ClassReader;I)V", nullptr, $PUBLIC, $method(ClassWriter, init$, void, $ClassReader*, int32_t)},
	{"getAttributePrototypes", "()[Ljdk/internal/org/objectweb/asm/Attribute;", nullptr, $PRIVATE, $method(ClassWriter, getAttributePrototypes, $AttributeArray*)},
	{"getClassLoader", "()Ljava/lang/ClassLoader;", nullptr, $PROTECTED, $virtualMethod(ClassWriter, getClassLoader, $ClassLoader*)},
	{"getCommonSuperClass", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PROTECTED, $virtualMethod(ClassWriter, getCommonSuperClass, $String*, $String*, $String*)},
	{"newClass", "(Ljava/lang/String;)I", nullptr, $PUBLIC, $virtualMethod(ClassWriter, newClass, int32_t, $String*)},
	{"newConst", "(Ljava/lang/Object;)I", nullptr, $PUBLIC, $virtualMethod(ClassWriter, newConst, int32_t, Object$*)},
	{"newConstantDynamic", "(Ljava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/Handle;[Ljava/lang/Object;)I", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(ClassWriter, newConstantDynamic, int32_t, $String*, $String*, $Handle*, $ObjectArray*)},
	{"newField", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I", nullptr, $PUBLIC, $virtualMethod(ClassWriter, newField, int32_t, $String*, $String*, $String*)},
	{"newHandle", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)I", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(ClassWriter, newHandle, int32_t, int32_t, $String*, $String*, $String*), nullptr, nullptr, _ClassWriter_MethodAnnotations_newHandle9},
	{"newHandle", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)I", nullptr, $PUBLIC, $virtualMethod(ClassWriter, newHandle, int32_t, int32_t, $String*, $String*, $String*, bool)},
	{"newInvokeDynamic", "(Ljava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/Handle;[Ljava/lang/Object;)I", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(ClassWriter, newInvokeDynamic, int32_t, $String*, $String*, $Handle*, $ObjectArray*)},
	{"newMethod", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)I", nullptr, $PUBLIC, $virtualMethod(ClassWriter, newMethod, int32_t, $String*, $String*, $String*, bool)},
	{"newMethodType", "(Ljava/lang/String;)I", nullptr, $PUBLIC, $virtualMethod(ClassWriter, newMethodType, int32_t, $String*)},
	{"newModule", "(Ljava/lang/String;)I", nullptr, $PUBLIC, $virtualMethod(ClassWriter, newModule, int32_t, $String*)},
	{"newNameType", "(Ljava/lang/String;Ljava/lang/String;)I", nullptr, $PUBLIC, $virtualMethod(ClassWriter, newNameType, int32_t, $String*, $String*)},
	{"newPackage", "(Ljava/lang/String;)I", nullptr, $PUBLIC, $virtualMethod(ClassWriter, newPackage, int32_t, $String*)},
	{"newUTF8", "(Ljava/lang/String;)I", nullptr, $PUBLIC, $virtualMethod(ClassWriter, newUTF8, int32_t, $String*)},
	{"replaceAsmInstructions", "([BZ)[B", nullptr, $PRIVATE, $method(ClassWriter, replaceAsmInstructions, $bytes*, $bytes*, bool)},
	{"toByteArray", "()[B", nullptr, $PUBLIC, $virtualMethod(ClassWriter, toByteArray, $bytes*)},
	{"visit", "(IILjava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)V", nullptr, $PUBLIC | $FINAL, $virtualMethod(ClassWriter, visit, void, int32_t, int32_t, $String*, $String*, $String*, $StringArray*)},
	{"visitAnnotation", "(Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/AnnotationVisitor;", nullptr, $PUBLIC | $FINAL, $virtualMethod(ClassWriter, visitAnnotation, $AnnotationVisitor*, $String*, bool)},
	{"visitAttribute", "(Ljdk/internal/org/objectweb/asm/Attribute;)V", nullptr, $PUBLIC | $FINAL, $virtualMethod(ClassWriter, visitAttribute, void, $Attribute*)},
	{"visitEnd", "()V", nullptr, $PUBLIC | $FINAL, $virtualMethod(ClassWriter, visitEnd, void)},
	{"visitField", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Object;)Ljdk/internal/org/objectweb/asm/FieldVisitor;", nullptr, $PUBLIC | $FINAL, $virtualMethod(ClassWriter, visitField, $FieldVisitor*, int32_t, $String*, $String*, $String*, Object$*)},
	{"visitInnerClass", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V", nullptr, $PUBLIC | $FINAL, $virtualMethod(ClassWriter, visitInnerClass, void, $String*, $String*, $String*, int32_t)},
	{"visitMethod", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/MethodVisitor;", nullptr, $PUBLIC | $FINAL, $virtualMethod(ClassWriter, visitMethod, $MethodVisitor*, int32_t, $String*, $String*, $String*, $StringArray*)},
	{"visitModule", "(Ljava/lang/String;ILjava/lang/String;)Ljdk/internal/org/objectweb/asm/ModuleVisitor;", nullptr, $PUBLIC | $FINAL, $virtualMethod(ClassWriter, visitModule, $ModuleVisitor*, $String*, int32_t, $String*)},
	{"visitNestHost", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $FINAL, $virtualMethod(ClassWriter, visitNestHost, void, $String*)},
	{"visitNestMember", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $FINAL, $virtualMethod(ClassWriter, visitNestMember, void, $String*)},
	{"visitOuterClass", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $FINAL, $virtualMethod(ClassWriter, visitOuterClass, void, $String*, $String*, $String*)},
	{"visitPermittedSubclassExperimental", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $FINAL | $DEPRECATED, $virtualMethod(ClassWriter, visitPermittedSubclassExperimental, void, $String*), nullptr, nullptr, _ClassWriter_MethodAnnotations_visitPermittedSubclassExperimental31},
	{"visitRecordComponent", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/RecordComponentVisitor;", nullptr, $PUBLIC | $FINAL, $virtualMethod(ClassWriter, visitRecordComponent, $RecordComponentVisitor*, $String*, $String*, $String*)},
	{"visitSource", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $FINAL, $virtualMethod(ClassWriter, visitSource, void, $String*, $String*)},
	{"visitTypeAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/AnnotationVisitor;", nullptr, $PUBLIC | $FINAL, $virtualMethod(ClassWriter, visitTypeAnnotation, $AnnotationVisitor*, int32_t, $TypePath*, $String*, bool)},
	{}
};

$ClassInfo _ClassWriter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.ClassWriter",
	"jdk.internal.org.objectweb.asm.ClassVisitor",
	nullptr,
	_ClassWriter_FieldInfo_,
	_ClassWriter_MethodInfo_
};

$Object* allocate$ClassWriter($Class* clazz) {
	return $of($alloc(ClassWriter));
}

void ClassWriter::init$(int32_t flags) {
	ClassWriter::init$(nullptr, flags);
}

void ClassWriter::init$($ClassReader* classReader, int32_t flags) {
	$ClassVisitor::init$($Opcodes::ASM8);
	$set(this, symbolTable, classReader == nullptr ? $new($SymbolTable, this) : $new($SymbolTable, this, classReader));
	if (((int32_t)(flags & (uint32_t)ClassWriter::COMPUTE_FRAMES)) != 0) {
		this->compute = $MethodWriter::COMPUTE_ALL_FRAMES;
	} else if (((int32_t)(flags & (uint32_t)ClassWriter::COMPUTE_MAXS)) != 0) {
		this->compute = $MethodWriter::COMPUTE_MAX_STACK_AND_LOCAL;
	} else {
		this->compute = $MethodWriter::COMPUTE_NOTHING;
	}
}

void ClassWriter::visit(int32_t version, int32_t access, $String* name, $String* signature, $String* superName, $StringArray* interfaces) {
	$useLocalCurrentObjectStackCache();
	this->version = version;
	this->accessFlags = access;
	this->thisClass = $nc(this->symbolTable)->setMajorVersionAndClassName((int32_t)(version & (uint32_t)0x0000FFFF), name);
	if (signature != nullptr) {
		this->signatureIndex = $nc(this->symbolTable)->addConstantUtf8(signature);
	}
	this->superClass = superName == nullptr ? 0 : $nc($($nc(this->symbolTable)->addConstantClass(superName)))->index;
	if (interfaces != nullptr && interfaces->length > 0) {
		this->interfaceCount = interfaces->length;
		$set(this, interfaces, $new($ints, this->interfaceCount));
		for (int32_t i = 0; i < this->interfaceCount; ++i) {
			$nc(this->interfaces)->set(i, $nc($($nc(this->symbolTable)->addConstantClass(interfaces->get(i))))->index);
		}
	}
	if (this->compute == $MethodWriter::COMPUTE_MAX_STACK_AND_LOCAL && ((int32_t)(version & (uint32_t)0x0000FFFF)) >= $Opcodes::V1_7) {
		this->compute = $MethodWriter::COMPUTE_MAX_STACK_AND_LOCAL_FROM_FRAMES;
	}
}

void ClassWriter::visitSource($String* file, $String* debug) {
	if (file != nullptr) {
		this->sourceFileIndex = $nc(this->symbolTable)->addConstantUtf8(file);
	}
	if (debug != nullptr) {
		$set(this, debugExtension, $$new($ByteVector)->encodeUtf8(debug, 0, $Integer::MAX_VALUE));
	}
}

$ModuleVisitor* ClassWriter::visitModule($String* name, int32_t access, $String* version) {
	$useLocalCurrentObjectStackCache();
	$var($SymbolTable, var$0, this->symbolTable);
	int32_t var$1 = $nc($($nc(this->symbolTable)->addConstantModule(name)))->index;
	int32_t var$2 = access;
	return ($set(this, moduleWriter, $new($ModuleWriter, var$0, var$1, var$2, version == nullptr ? 0 : $nc(this->symbolTable)->addConstantUtf8(version))));
}

void ClassWriter::visitNestHost($String* nestHost) {
	this->nestHostClassIndex = $nc($($nc(this->symbolTable)->addConstantClass(nestHost)))->index;
}

void ClassWriter::visitOuterClass($String* owner, $String* name, $String* descriptor) {
	this->enclosingClassIndex = $nc($($nc(this->symbolTable)->addConstantClass(owner)))->index;
	if (name != nullptr && descriptor != nullptr) {
		this->enclosingMethodIndex = $nc(this->symbolTable)->addConstantNameAndType(name, descriptor);
	}
}

$AnnotationVisitor* ClassWriter::visitAnnotation($String* descriptor, bool visible) {
	if (visible) {
		return ($set(this, lastRuntimeVisibleAnnotation, $AnnotationWriter::create(this->symbolTable, descriptor, this->lastRuntimeVisibleAnnotation)));
	} else {
		return ($set(this, lastRuntimeInvisibleAnnotation, $AnnotationWriter::create(this->symbolTable, descriptor, this->lastRuntimeInvisibleAnnotation)));
	}
}

$AnnotationVisitor* ClassWriter::visitTypeAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	if (visible) {
		return ($set(this, lastRuntimeVisibleTypeAnnotation, $AnnotationWriter::create(this->symbolTable, typeRef, typePath, descriptor, this->lastRuntimeVisibleTypeAnnotation)));
	} else {
		return ($set(this, lastRuntimeInvisibleTypeAnnotation, $AnnotationWriter::create(this->symbolTable, typeRef, typePath, descriptor, this->lastRuntimeInvisibleTypeAnnotation)));
	}
}

void ClassWriter::visitAttribute($Attribute* attribute) {
	$set($nc(attribute), nextAttribute, this->firstAttribute);
	$set(this, firstAttribute, attribute);
}

void ClassWriter::visitNestMember($String* nestMember) {
	if (this->nestMemberClasses == nullptr) {
		$set(this, nestMemberClasses, $new($ByteVector));
	}
	++this->numberOfNestMemberClasses;
	$nc(this->nestMemberClasses)->putShort($nc($($nc(this->symbolTable)->addConstantClass(nestMember)))->index);
}

void ClassWriter::visitPermittedSubclassExperimental($String* permittedSubclass) {
	if (this->permittedSubclassClasses == nullptr) {
		$set(this, permittedSubclassClasses, $new($ByteVector));
	}
	++this->numberOfPermittedSubclassClasses;
	$nc(this->permittedSubclassClasses)->putShort($nc($($nc(this->symbolTable)->addConstantClass(permittedSubclass)))->index);
}

void ClassWriter::visitInnerClass($String* name, $String* outerName, $String* innerName, int32_t access) {
	$useLocalCurrentObjectStackCache();
	if (this->innerClasses == nullptr) {
		$set(this, innerClasses, $new($ByteVector));
	}
	$var($Symbol, nameSymbol, $nc(this->symbolTable)->addConstantClass(name));
	if ($nc(nameSymbol)->info == 0) {
		++this->numberOfInnerClasses;
		$nc(this->innerClasses)->putShort(nameSymbol->index);
		$nc(this->innerClasses)->putShort(outerName == nullptr ? 0 : $nc($($nc(this->symbolTable)->addConstantClass(outerName)))->index);
		$nc(this->innerClasses)->putShort(innerName == nullptr ? 0 : $nc(this->symbolTable)->addConstantUtf8(innerName));
		$nc(this->innerClasses)->putShort(access);
		nameSymbol->info = this->numberOfInnerClasses;
	}
}

$RecordComponentVisitor* ClassWriter::visitRecordComponent($String* name, $String* descriptor, $String* signature) {
	$var($RecordComponentWriter, recordComponentWriter, $new($RecordComponentWriter, this->symbolTable, name, descriptor, signature));
	if (this->firstRecordComponent == nullptr) {
		$set(this, firstRecordComponent, recordComponentWriter);
	} else {
		$set($nc(this->lastRecordComponent), delegate, recordComponentWriter);
	}
	return ($set(this, lastRecordComponent, recordComponentWriter));
}

$FieldVisitor* ClassWriter::visitField(int32_t access, $String* name, $String* descriptor, $String* signature, Object$* value) {
	$var($FieldWriter, fieldWriter, $new($FieldWriter, this->symbolTable, access, name, descriptor, signature, value));
	if (this->firstField == nullptr) {
		$set(this, firstField, fieldWriter);
	} else {
		$set($nc(this->lastField), fv, fieldWriter);
	}
	return ($set(this, lastField, fieldWriter));
}

$MethodVisitor* ClassWriter::visitMethod(int32_t access, $String* name, $String* descriptor, $String* signature, $StringArray* exceptions) {
	$var($MethodWriter, methodWriter, $new($MethodWriter, this->symbolTable, access, name, descriptor, signature, exceptions, this->compute));
	if (this->firstMethod == nullptr) {
		$set(this, firstMethod, methodWriter);
	} else {
		$set($nc(this->lastMethod), mv, methodWriter);
	}
	return ($set(this, lastMethod, methodWriter));
}

void ClassWriter::visitEnd() {
}

$bytes* ClassWriter::toByteArray() {
	$useLocalCurrentObjectStackCache();
	int32_t size = 24 + 2 * this->interfaceCount;
	int32_t fieldsCount = 0;
	$var($FieldWriter, fieldWriter, this->firstField);
	while (fieldWriter != nullptr) {
		++fieldsCount;
		size += fieldWriter->computeFieldInfoSize();
		$assign(fieldWriter, $cast($FieldWriter, fieldWriter->fv));
	}
	int32_t methodsCount = 0;
	$var($MethodWriter, methodWriter, this->firstMethod);
	while (methodWriter != nullptr) {
		++methodsCount;
		size += methodWriter->computeMethodInfoSize();
		$assign(methodWriter, $cast($MethodWriter, methodWriter->mv));
	}
	int32_t attributesCount = 0;
	if (this->innerClasses != nullptr) {
		++attributesCount;
		size += 8 + $nc(this->innerClasses)->length;
		$init($Constants);
		$nc(this->symbolTable)->addConstantUtf8($Constants::INNER_CLASSES);
	}
	if (this->enclosingClassIndex != 0) {
		++attributesCount;
		size += 10;
		$init($Constants);
		$nc(this->symbolTable)->addConstantUtf8($Constants::ENCLOSING_METHOD);
	}
	if (((int32_t)(this->accessFlags & (uint32_t)$Opcodes::ACC_SYNTHETIC)) != 0 && ((int32_t)(this->version & (uint32_t)0x0000FFFF)) < $Opcodes::V1_5) {
		++attributesCount;
		size += 6;
		$init($Constants);
		$nc(this->symbolTable)->addConstantUtf8($Constants::SYNTHETIC);
	}
	if (this->signatureIndex != 0) {
		++attributesCount;
		size += 8;
		$init($Constants);
		$nc(this->symbolTable)->addConstantUtf8($Constants::SIGNATURE);
	}
	if (this->sourceFileIndex != 0) {
		++attributesCount;
		size += 8;
		$init($Constants);
		$nc(this->symbolTable)->addConstantUtf8($Constants::SOURCE_FILE);
	}
	if (this->debugExtension != nullptr) {
		++attributesCount;
		size += 6 + $nc(this->debugExtension)->length;
		$init($Constants);
		$nc(this->symbolTable)->addConstantUtf8($Constants::SOURCE_DEBUG_EXTENSION);
	}
	if (((int32_t)(this->accessFlags & (uint32_t)$Opcodes::ACC_DEPRECATED)) != 0) {
		++attributesCount;
		size += 6;
		$init($Constants);
		$nc(this->symbolTable)->addConstantUtf8($Constants::DEPRECATED);
	}
	if (this->lastRuntimeVisibleAnnotation != nullptr) {
		++attributesCount;
		$init($Constants);
		size += $nc(this->lastRuntimeVisibleAnnotation)->computeAnnotationsSize($Constants::RUNTIME_VISIBLE_ANNOTATIONS);
	}
	if (this->lastRuntimeInvisibleAnnotation != nullptr) {
		++attributesCount;
		$init($Constants);
		size += $nc(this->lastRuntimeInvisibleAnnotation)->computeAnnotationsSize($Constants::RUNTIME_INVISIBLE_ANNOTATIONS);
	}
	if (this->lastRuntimeVisibleTypeAnnotation != nullptr) {
		++attributesCount;
		$init($Constants);
		size += $nc(this->lastRuntimeVisibleTypeAnnotation)->computeAnnotationsSize($Constants::RUNTIME_VISIBLE_TYPE_ANNOTATIONS);
	}
	if (this->lastRuntimeInvisibleTypeAnnotation != nullptr) {
		++attributesCount;
		$init($Constants);
		size += $nc(this->lastRuntimeInvisibleTypeAnnotation)->computeAnnotationsSize($Constants::RUNTIME_INVISIBLE_TYPE_ANNOTATIONS);
	}
	if ($nc(this->symbolTable)->computeBootstrapMethodsSize() > 0) {
		++attributesCount;
		size += $nc(this->symbolTable)->computeBootstrapMethodsSize();
	}
	if (this->moduleWriter != nullptr) {
		attributesCount += $nc(this->moduleWriter)->getAttributeCount();
		size += $nc(this->moduleWriter)->computeAttributesSize();
	}
	if (this->nestHostClassIndex != 0) {
		++attributesCount;
		size += 8;
		$init($Constants);
		$nc(this->symbolTable)->addConstantUtf8($Constants::NEST_HOST);
	}
	if (this->nestMemberClasses != nullptr) {
		++attributesCount;
		size += 8 + $nc(this->nestMemberClasses)->length;
		$init($Constants);
		$nc(this->symbolTable)->addConstantUtf8($Constants::NEST_MEMBERS);
	}
	if (this->permittedSubclassClasses != nullptr) {
		++attributesCount;
		size += 8 + $nc(this->permittedSubclassClasses)->length;
		$init($Constants);
		$nc(this->symbolTable)->addConstantUtf8($Constants::PERMITTED_SUBCLASSES);
	}
	int32_t recordComponentCount = 0;
	int32_t recordSize = 0;
	if (((int32_t)(this->accessFlags & (uint32_t)$Opcodes::ACC_RECORD)) != 0 || this->firstRecordComponent != nullptr) {
		$var($RecordComponentWriter, recordComponentWriter, this->firstRecordComponent);
		while (recordComponentWriter != nullptr) {
			++recordComponentCount;
			recordSize += recordComponentWriter->computeRecordComponentInfoSize();
			$assign(recordComponentWriter, $cast($RecordComponentWriter, recordComponentWriter->delegate));
		}
		++attributesCount;
		size += 8 + recordSize;
		$init($Constants);
		$nc(this->symbolTable)->addConstantUtf8($Constants::RECORD);
	}
	if (this->firstAttribute != nullptr) {
		attributesCount += $nc(this->firstAttribute)->getAttributeCount();
		size += $nc(this->firstAttribute)->computeAttributesSize(this->symbolTable);
	}
	size += $nc(this->symbolTable)->getConstantPoolLength();
	int32_t constantPoolCount = $nc(this->symbolTable)->getConstantPoolCount();
	if (constantPoolCount > 0x0000FFFF) {
		$throwNew($ClassTooLargeException, $($nc(this->symbolTable)->getClassName()), constantPoolCount);
	}
	$var($ByteVector, result, $new($ByteVector, size));
	$nc($(result->putInt((int32_t)0xCAFEBABE)))->putInt(this->version);
	$nc(this->symbolTable)->putConstantPool(result);
	int32_t mask = ((int32_t)(this->version & (uint32_t)0x0000FFFF)) < $Opcodes::V1_5 ? $Opcodes::ACC_SYNTHETIC : 0;
	$nc($($nc($(result->putShort((int32_t)(this->accessFlags & (uint32_t)~mask))))->putShort(this->thisClass)))->putShort(this->superClass);
	result->putShort(this->interfaceCount);
	for (int32_t i = 0; i < this->interfaceCount; ++i) {
		result->putShort($nc(this->interfaces)->get(i));
	}
	result->putShort(fieldsCount);
	$assign(fieldWriter, this->firstField);
	while (fieldWriter != nullptr) {
		fieldWriter->putFieldInfo(result);
		$assign(fieldWriter, $cast($FieldWriter, fieldWriter->fv));
	}
	result->putShort(methodsCount);
	bool hasFrames = false;
	bool hasAsmInstructions = false;
	$assign(methodWriter, this->firstMethod);
	while (methodWriter != nullptr) {
		hasFrames |= methodWriter->hasFrames();
		hasAsmInstructions |= methodWriter->hasAsmInstructions();
		methodWriter->putMethodInfo(result);
		$assign(methodWriter, $cast($MethodWriter, methodWriter->mv));
	}
	result->putShort(attributesCount);
	if (this->innerClasses != nullptr) {
		$init($Constants);
		$nc($($nc($($nc($(result->putShort($nc(this->symbolTable)->addConstantUtf8($Constants::INNER_CLASSES))))->putInt($nc(this->innerClasses)->length + 2)))->putShort(this->numberOfInnerClasses)))->putByteArray($nc(this->innerClasses)->data, 0, $nc(this->innerClasses)->length);
	}
	if (this->enclosingClassIndex != 0) {
		$init($Constants);
		$nc($($nc($($nc($(result->putShort($nc(this->symbolTable)->addConstantUtf8($Constants::ENCLOSING_METHOD))))->putInt(4)))->putShort(this->enclosingClassIndex)))->putShort(this->enclosingMethodIndex);
	}
	if (((int32_t)(this->accessFlags & (uint32_t)$Opcodes::ACC_SYNTHETIC)) != 0 && ((int32_t)(this->version & (uint32_t)0x0000FFFF)) < $Opcodes::V1_5) {
		$init($Constants);
		$nc($(result->putShort($nc(this->symbolTable)->addConstantUtf8($Constants::SYNTHETIC))))->putInt(0);
	}
	if (this->signatureIndex != 0) {
		$init($Constants);
		$nc($($nc($(result->putShort($nc(this->symbolTable)->addConstantUtf8($Constants::SIGNATURE))))->putInt(2)))->putShort(this->signatureIndex);
	}
	if (this->sourceFileIndex != 0) {
		$init($Constants);
		$nc($($nc($(result->putShort($nc(this->symbolTable)->addConstantUtf8($Constants::SOURCE_FILE))))->putInt(2)))->putShort(this->sourceFileIndex);
	}
	if (this->debugExtension != nullptr) {
		int32_t length = $nc(this->debugExtension)->length;
		$init($Constants);
		$nc($($nc($(result->putShort($nc(this->symbolTable)->addConstantUtf8($Constants::SOURCE_DEBUG_EXTENSION))))->putInt(length)))->putByteArray($nc(this->debugExtension)->data, 0, length);
	}
	if (((int32_t)(this->accessFlags & (uint32_t)$Opcodes::ACC_DEPRECATED)) != 0) {
		$init($Constants);
		$nc($(result->putShort($nc(this->symbolTable)->addConstantUtf8($Constants::DEPRECATED))))->putInt(0);
	}
	$AnnotationWriter::putAnnotations(this->symbolTable, this->lastRuntimeVisibleAnnotation, this->lastRuntimeInvisibleAnnotation, this->lastRuntimeVisibleTypeAnnotation, this->lastRuntimeInvisibleTypeAnnotation, result);
	$nc(this->symbolTable)->putBootstrapMethods(result);
	if (this->moduleWriter != nullptr) {
		$nc(this->moduleWriter)->putAttributes(result);
	}
	if (this->nestHostClassIndex != 0) {
		$init($Constants);
		$nc($($nc($(result->putShort($nc(this->symbolTable)->addConstantUtf8($Constants::NEST_HOST))))->putInt(2)))->putShort(this->nestHostClassIndex);
	}
	if (this->nestMemberClasses != nullptr) {
		$init($Constants);
		$nc($($nc($($nc($(result->putShort($nc(this->symbolTable)->addConstantUtf8($Constants::NEST_MEMBERS))))->putInt($nc(this->nestMemberClasses)->length + 2)))->putShort(this->numberOfNestMemberClasses)))->putByteArray($nc(this->nestMemberClasses)->data, 0, $nc(this->nestMemberClasses)->length);
	}
	if (this->permittedSubclassClasses != nullptr) {
		$init($Constants);
		$nc($($nc($($nc($(result->putShort($nc(this->symbolTable)->addConstantUtf8($Constants::PERMITTED_SUBCLASSES))))->putInt($nc(this->permittedSubclassClasses)->length + 2)))->putShort(this->numberOfPermittedSubclassClasses)))->putByteArray($nc(this->permittedSubclassClasses)->data, 0, $nc(this->permittedSubclassClasses)->length);
	}
	if (((int32_t)(this->accessFlags & (uint32_t)$Opcodes::ACC_RECORD)) != 0 || this->firstRecordComponent != nullptr) {
		$init($Constants);
		$nc($($nc($(result->putShort($nc(this->symbolTable)->addConstantUtf8($Constants::RECORD))))->putInt(recordSize + 2)))->putShort(recordComponentCount);
		$var($RecordComponentWriter, recordComponentWriter, this->firstRecordComponent);
		while (recordComponentWriter != nullptr) {
			recordComponentWriter->putRecordComponentInfo(result);
			$assign(recordComponentWriter, $cast($RecordComponentWriter, recordComponentWriter->delegate));
		}
	}
	if (this->firstAttribute != nullptr) {
		$nc(this->firstAttribute)->putAttributes(this->symbolTable, result);
	}
	if (hasAsmInstructions) {
		return replaceAsmInstructions(result->data, hasFrames);
	} else {
		return result->data;
	}
}

$bytes* ClassWriter::replaceAsmInstructions($bytes* classFile, bool hasFrames) {
	$useLocalCurrentObjectStackCache();
	$var($AttributeArray, attributes, getAttributePrototypes());
	$set(this, firstField, nullptr);
	$set(this, lastField, nullptr);
	$set(this, firstMethod, nullptr);
	$set(this, lastMethod, nullptr);
	$set(this, lastRuntimeVisibleAnnotation, nullptr);
	$set(this, lastRuntimeInvisibleAnnotation, nullptr);
	$set(this, lastRuntimeVisibleTypeAnnotation, nullptr);
	$set(this, lastRuntimeInvisibleTypeAnnotation, nullptr);
	$set(this, moduleWriter, nullptr);
	this->nestHostClassIndex = 0;
	this->numberOfNestMemberClasses = 0;
	$set(this, nestMemberClasses, nullptr);
	this->numberOfPermittedSubclassClasses = 0;
	$set(this, permittedSubclassClasses, nullptr);
	$set(this, firstRecordComponent, nullptr);
	$set(this, lastRecordComponent, nullptr);
	$set(this, firstAttribute, nullptr);
	this->compute = hasFrames ? $MethodWriter::COMPUTE_INSERTED_FRAMES : $MethodWriter::COMPUTE_NOTHING;
	$$new($ClassReader, classFile, 0, false)->accept(this, attributes, (hasFrames ? $ClassReader::EXPAND_FRAMES : 0) | $ClassReader::EXPAND_ASM_INSNS);
	return toByteArray();
}

$AttributeArray* ClassWriter::getAttributePrototypes() {
	$useLocalCurrentObjectStackCache();
	$var($Attribute$Set, attributePrototypes, $new($Attribute$Set));
	attributePrototypes->addAttributes(this->firstAttribute);
	$var($FieldWriter, fieldWriter, this->firstField);
	while (fieldWriter != nullptr) {
		fieldWriter->collectAttributePrototypes(attributePrototypes);
		$assign(fieldWriter, $cast($FieldWriter, fieldWriter->fv));
	}
	$var($MethodWriter, methodWriter, this->firstMethod);
	while (methodWriter != nullptr) {
		methodWriter->collectAttributePrototypes(attributePrototypes);
		$assign(methodWriter, $cast($MethodWriter, methodWriter->mv));
	}
	$var($RecordComponentWriter, recordComponentWriter, this->firstRecordComponent);
	while (recordComponentWriter != nullptr) {
		recordComponentWriter->collectAttributePrototypes(attributePrototypes);
		$assign(recordComponentWriter, $cast($RecordComponentWriter, recordComponentWriter->delegate));
	}
	return attributePrototypes->toArray();
}

int32_t ClassWriter::newConst(Object$* value) {
	return $nc($($nc(this->symbolTable)->addConstant(value)))->index;
}

int32_t ClassWriter::newUTF8($String* value) {
	return $nc(this->symbolTable)->addConstantUtf8(value);
}

int32_t ClassWriter::newClass($String* value) {
	return $nc($($nc(this->symbolTable)->addConstantClass(value)))->index;
}

int32_t ClassWriter::newMethodType($String* methodDescriptor) {
	return $nc($($nc(this->symbolTable)->addConstantMethodType(methodDescriptor)))->index;
}

int32_t ClassWriter::newModule($String* moduleName) {
	return $nc($($nc(this->symbolTable)->addConstantModule(moduleName)))->index;
}

int32_t ClassWriter::newPackage($String* packageName) {
	return $nc($($nc(this->symbolTable)->addConstantPackage(packageName)))->index;
}

int32_t ClassWriter::newHandle(int32_t tag, $String* owner, $String* name, $String* descriptor) {
	return newHandle(tag, owner, name, descriptor, tag == $Opcodes::H_INVOKEINTERFACE);
}

int32_t ClassWriter::newHandle(int32_t tag, $String* owner, $String* name, $String* descriptor, bool isInterface) {
	return $nc($($nc(this->symbolTable)->addConstantMethodHandle(tag, owner, name, descriptor, isInterface)))->index;
}

int32_t ClassWriter::newConstantDynamic($String* name, $String* descriptor, $Handle* bootstrapMethodHandle, $ObjectArray* bootstrapMethodArguments) {
	return $nc($($nc(this->symbolTable)->addConstantDynamic(name, descriptor, bootstrapMethodHandle, bootstrapMethodArguments)))->index;
}

int32_t ClassWriter::newInvokeDynamic($String* name, $String* descriptor, $Handle* bootstrapMethodHandle, $ObjectArray* bootstrapMethodArguments) {
	return $nc($($nc(this->symbolTable)->addConstantInvokeDynamic(name, descriptor, bootstrapMethodHandle, bootstrapMethodArguments)))->index;
}

int32_t ClassWriter::newField($String* owner, $String* name, $String* descriptor) {
	return $nc($($nc(this->symbolTable)->addConstantFieldref(owner, name, descriptor)))->index;
}

int32_t ClassWriter::newMethod($String* owner, $String* name, $String* descriptor, bool isInterface) {
	return $nc($($nc(this->symbolTable)->addConstantMethodref(owner, name, descriptor, isInterface)))->index;
}

int32_t ClassWriter::newNameType($String* name, $String* descriptor) {
	return $nc(this->symbolTable)->addConstantNameAndType(name, descriptor);
}

$String* ClassWriter::getCommonSuperClass($String* type1, $String* type2) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ClassLoader, classLoader, getClassLoader());
	$Class* class1 = nullptr;
	try {
		class1 = $Class::forName($($nc(type1)->replace(u'/', u'.')), false, classLoader);
	} catch ($ClassNotFoundException& e) {
		$throwNew($TypeNotPresentException, type1, e);
	}
	$Class* class2 = nullptr;
	try {
		class2 = $Class::forName($($nc(type2)->replace(u'/', u'.')), false, classLoader);
	} catch ($ClassNotFoundException& e) {
		$throwNew($TypeNotPresentException, type2, e);
	}
	if ($nc(class1)->isAssignableFrom(class2)) {
		return type1;
	}
	if ($nc(class2)->isAssignableFrom(class1)) {
		return type2;
	}
	bool var$0 = $nc(class1)->isInterface();
	if (var$0 || $nc(class2)->isInterface()) {
		return "java/lang/Object"_s;
	} else {
		do {
			class1 = $nc(class1)->getSuperclass();
		} while (!$nc(class1)->isAssignableFrom(class2));
		return $nc($(class1->getName()))->replace(u'.', u'/');
	}
}

$ClassLoader* ClassWriter::getClassLoader() {
	$beforeCallerSensitive();
	return $of(this)->getClass()->getClassLoader();
}

ClassWriter::ClassWriter() {
}

$Class* ClassWriter::load$($String* name, bool initialize) {
	$loadClass(ClassWriter, name, initialize, &_ClassWriter_ClassInfo_, allocate$ClassWriter);
	return class$;
}

$Class* ClassWriter::class$ = nullptr;

				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk