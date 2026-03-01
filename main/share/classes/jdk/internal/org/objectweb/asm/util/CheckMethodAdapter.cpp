#include <jdk/internal/org/objectweb/asm/util/CheckMethodAdapter.h>

#include <java/lang/AssertionError.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <jdk/internal/org/objectweb/asm/AnnotationVisitor.h>
#include <jdk/internal/org/objectweb/asm/Attribute.h>
#include <jdk/internal/org/objectweb/asm/ConstantDynamic.h>
#include <jdk/internal/org/objectweb/asm/Handle.h>
#include <jdk/internal/org/objectweb/asm/Label.h>
#include <jdk/internal/org/objectweb/asm/MethodVisitor.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/Type.h>
#include <jdk/internal/org/objectweb/asm/TypePath.h>
#include <jdk/internal/org/objectweb/asm/TypeReference.h>
#include <jdk/internal/org/objectweb/asm/util/CheckAnnotationAdapter.h>
#include <jdk/internal/org/objectweb/asm/util/CheckClassAdapter.h>
#include <jdk/internal/org/objectweb/asm/util/CheckMethodAdapter$1.h>
#include <jdk/internal/org/objectweb/asm/util/CheckMethodAdapter$Method.h>
#include <jcpp.h>

#undef ACC_ABSTRACT
#undef ACC_FINAL
#undef ACC_MANDATED
#undef ACC_SYNTHETIC
#undef ARRAY
#undef ASM5
#undef ASM8
#undef BIPUSH
#undef CAST
#undef CONSTRUCTOR_INVOCATION_TYPE_ARGUMENT
#undef CONSTRUCTOR_REFERENCE
#undef CONSTRUCTOR_REFERENCE_TYPE_ARGUMENT
#undef DOUBLE
#undef END_LABEL
#undef EXCEPTION_PARAMETER
#undef FLOAT
#undef F_APPEND
#undef F_CHOP
#undef F_FULL
#undef F_NEW
#undef F_SAME
#undef F_SAME1
#undef H_GETFIELD
#undef H_INVOKEINTERFACE
#undef H_INVOKESTATIC
#undef H_NEWINVOKESPECIAL
#undef H_PUTSTATIC
#undef IFNONNULL
#undef INSTANCEOF
#undef INTEGER
#undef INVALID
#undef INVALID_DESCRIPTOR
#undef INVALID_LOCAL_VARIABLE_INDEX
#undef INVALID_TYPE_REFERENCE
#undef INVOKEINTERFACE
#undef INVOKESPECIAL
#undef INVOKEVIRTUAL
#undef LOCAL_VARIABLE
#undef LONG
#undef MAX_VALUE
#undef METHOD
#undef METHOD_FORMAL_PARAMETER
#undef METHOD_INVOCATION_TYPE_ARGUMENT
#undef METHOD_RECEIVER
#undef METHOD_REFERENCE
#undef METHOD_REFERENCE_TYPE_ARGUMENT
#undef METHOD_RETURN
#undef METHOD_TYPE_PARAMETER
#undef METHOD_TYPE_PARAMETER_BOUND
#undef MIN_VALUE
#undef MUST_NOT_BE_NULL_OR_EMPTY
#undef NEW
#undef NEWARRAY
#undef NOP
#undef NULL
#undef OBJECT
#undef OPCODE_METHODS
#undef RESOURCE_VARIABLE
#undef SIPUSH
#undef SOURCE_DEPRECATED
#undef SOURCE_MASK
#undef START_LABEL
#undef THROWS
#undef TOP
#undef T_BOOLEAN
#undef T_LONG
#undef UNINITIALIZED_THIS
#undef VISIT_FIELD_INSN
#undef VISIT_INSN
#undef VISIT_INT_INSN
#undef VISIT_JUMP_INSN
#undef VISIT_METHOD_INSN
#undef VISIT_TYPE_INSN
#undef VISIT_VAR_INSN

using $LabelArray = $Array<::jdk::internal::org::objectweb::asm$::Label>;
using $CheckMethodAdapter$MethodArray = $Array<::jdk::internal::org::objectweb::asm$::util::CheckMethodAdapter$Method>;
using $AssertionError = ::java::lang::AssertionError;
using $Byte = ::java::lang::Byte;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Short = ::java::lang::Short;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $AnnotationVisitor = ::jdk::internal::org::objectweb::asm$::AnnotationVisitor;
using $Attribute = ::jdk::internal::org::objectweb::asm$::Attribute;
using $ConstantDynamic = ::jdk::internal::org::objectweb::asm$::ConstantDynamic;
using $Handle = ::jdk::internal::org::objectweb::asm$::Handle;
using $Label = ::jdk::internal::org::objectweb::asm$::Label;
using $MethodVisitor = ::jdk::internal::org::objectweb::asm$::MethodVisitor;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $Type = ::jdk::internal::org::objectweb::asm$::Type;
using $TypePath = ::jdk::internal::org::objectweb::asm$::TypePath;
using $TypeReference = ::jdk::internal::org::objectweb::asm$::TypeReference;
using $CheckAnnotationAdapter = ::jdk::internal::org::objectweb::asm$::util::CheckAnnotationAdapter;
using $CheckClassAdapter = ::jdk::internal::org::objectweb::asm$::util::CheckClassAdapter;
using $CheckMethodAdapter$1 = ::jdk::internal::org::objectweb::asm$::util::CheckMethodAdapter$1;
using $CheckMethodAdapter$Method = ::jdk::internal::org::objectweb::asm$::util::CheckMethodAdapter$Method;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace util {

$FieldInfo _CheckMethodAdapter_FieldInfo_[] = {
	{"OPCODE_METHODS", "[Ljdk/internal/org/objectweb/asm/util/CheckMethodAdapter$Method;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CheckMethodAdapter, OPCODE_METHODS)},
	{"INVALID", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CheckMethodAdapter, INVALID)},
	{"INVALID_DESCRIPTOR", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CheckMethodAdapter, INVALID_DESCRIPTOR)},
	{"INVALID_TYPE_REFERENCE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CheckMethodAdapter, INVALID_TYPE_REFERENCE)},
	{"INVALID_LOCAL_VARIABLE_INDEX", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CheckMethodAdapter, INVALID_LOCAL_VARIABLE_INDEX)},
	{"MUST_NOT_BE_NULL_OR_EMPTY", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CheckMethodAdapter, MUST_NOT_BE_NULL_OR_EMPTY)},
	{"START_LABEL", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CheckMethodAdapter, START_LABEL)},
	{"END_LABEL", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CheckMethodAdapter, END_LABEL)},
	{"version", "I", nullptr, $PUBLIC, $field(CheckMethodAdapter, version)},
	{"access", "I", nullptr, $PRIVATE, $field(CheckMethodAdapter, access)},
	{"visibleAnnotableParameterCount", "I", nullptr, $PRIVATE, $field(CheckMethodAdapter, visibleAnnotableParameterCount)},
	{"invisibleAnnotableParameterCount", "I", nullptr, $PRIVATE, $field(CheckMethodAdapter, invisibleAnnotableParameterCount)},
	{"visitCodeCalled", "Z", nullptr, $PRIVATE, $field(CheckMethodAdapter, visitCodeCalled)},
	{"visitMaxCalled", "Z", nullptr, $PRIVATE, $field(CheckMethodAdapter, visitMaxCalled)},
	{"visitEndCalled", "Z", nullptr, $PRIVATE, $field(CheckMethodAdapter, visitEndCalled)},
	{"insnCount", "I", nullptr, $PRIVATE, $field(CheckMethodAdapter, insnCount)},
	{"labelInsnIndices", "Ljava/util/Map;", "Ljava/util/Map<Ljdk/internal/org/objectweb/asm/Label;Ljava/lang/Integer;>;", $PRIVATE | $FINAL, $field(CheckMethodAdapter, labelInsnIndices)},
	{"referencedLabels", "Ljava/util/Set;", "Ljava/util/Set<Ljdk/internal/org/objectweb/asm/Label;>;", $PRIVATE, $field(CheckMethodAdapter, referencedLabels)},
	{"lastFrameInsnIndex", "I", nullptr, $PRIVATE, $field(CheckMethodAdapter, lastFrameInsnIndex)},
	{"numExpandedFrames", "I", nullptr, $PRIVATE, $field(CheckMethodAdapter, numExpandedFrames)},
	{"numCompressedFrames", "I", nullptr, $PRIVATE, $field(CheckMethodAdapter, numCompressedFrames)},
	{"handlers", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/org/objectweb/asm/Label;>;", $PRIVATE, $field(CheckMethodAdapter, handlers)},
	{}
};

$MethodInfo _CheckMethodAdapter_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/org/objectweb/asm/MethodVisitor;)V", nullptr, $PUBLIC, $method(CheckMethodAdapter, init$, void, $MethodVisitor*)},
	{"<init>", "(Ljdk/internal/org/objectweb/asm/MethodVisitor;Ljava/util/Map;)V", "(Ljdk/internal/org/objectweb/asm/MethodVisitor;Ljava/util/Map<Ljdk/internal/org/objectweb/asm/Label;Ljava/lang/Integer;>;)V", $PUBLIC, $method(CheckMethodAdapter, init$, void, $MethodVisitor*, $Map*)},
	{"<init>", "(ILjdk/internal/org/objectweb/asm/MethodVisitor;Ljava/util/Map;)V", "(ILjdk/internal/org/objectweb/asm/MethodVisitor;Ljava/util/Map<Ljdk/internal/org/objectweb/asm/Label;Ljava/lang/Integer;>;)V", $PROTECTED, $method(CheckMethodAdapter, init$, void, int32_t, $MethodVisitor*, $Map*)},
	{"<init>", "(ILjava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/MethodVisitor;Ljava/util/Map;)V", "(ILjava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/MethodVisitor;Ljava/util/Map<Ljdk/internal/org/objectweb/asm/Label;Ljava/lang/Integer;>;)V", $PUBLIC, $method(CheckMethodAdapter, init$, void, int32_t, $String*, $String*, $MethodVisitor*, $Map*)},
	{"<init>", "(IILjava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/MethodVisitor;Ljava/util/Map;)V", "(IILjava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/MethodVisitor;Ljava/util/Map<Ljdk/internal/org/objectweb/asm/Label;Ljava/lang/Integer;>;)V", $PROTECTED, $method(CheckMethodAdapter, init$, void, int32_t, int32_t, $String*, $String*, $MethodVisitor*, $Map*)},
	{"checkConstant", "(Ljava/lang/Object;)V", nullptr, $STATIC, $staticMethod(CheckMethodAdapter, checkConstant, void, Object$*)},
	{"checkDescriptor", "(ILjava/lang/String;Z)V", nullptr, $STATIC, $staticMethod(CheckMethodAdapter, checkDescriptor, void, int32_t, $String*, bool)},
	{"checkDescriptor", "(ILjava/lang/String;IZ)I", nullptr, $PRIVATE | $STATIC, $staticMethod(CheckMethodAdapter, checkDescriptor, int32_t, int32_t, $String*, int32_t, bool)},
	{"checkFrameValue", "(Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(CheckMethodAdapter, checkFrameValue, void, Object$*)},
	{"checkIdentifier", "(ILjava/lang/String;IILjava/lang/String;)V", nullptr, $STATIC, $staticMethod(CheckMethodAdapter, checkIdentifier, void, int32_t, $String*, int32_t, int32_t, $String*)},
	{"checkInternalClassName", "(ILjava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(CheckMethodAdapter, checkInternalClassName, void, int32_t, $String*, $String*)},
	{"checkInternalName", "(ILjava/lang/String;Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(CheckMethodAdapter, checkInternalName, void, int32_t, $String*, $String*)},
	{"checkLabel", "(Ljdk/internal/org/objectweb/asm/Label;ZLjava/lang/String;)V", nullptr, $PRIVATE, $method(CheckMethodAdapter, checkLabel, void, $Label*, bool, $String*)},
	{"checkLdcConstant", "(Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(CheckMethodAdapter, checkLdcConstant, void, Object$*)},
	{"checkMethodDescriptor", "(ILjava/lang/String;)V", nullptr, $STATIC, $staticMethod(CheckMethodAdapter, checkMethodDescriptor, void, int32_t, $String*)},
	{"checkMethodIdentifier", "(ILjava/lang/String;Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(CheckMethodAdapter, checkMethodIdentifier, void, int32_t, $String*, $String*)},
	{"checkOpcodeMethod", "(ILjdk/internal/org/objectweb/asm/util/CheckMethodAdapter$Method;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(CheckMethodAdapter, checkOpcodeMethod, void, int32_t, $CheckMethodAdapter$Method*)},
	{"checkSignedByte", "(ILjava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(CheckMethodAdapter, checkSignedByte, void, int32_t, $String*)},
	{"checkSignedShort", "(ILjava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(CheckMethodAdapter, checkSignedShort, void, int32_t, $String*)},
	{"checkUnqualifiedName", "(ILjava/lang/String;Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(CheckMethodAdapter, checkUnqualifiedName, void, int32_t, $String*, $String*)},
	{"checkUnsignedShort", "(ILjava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(CheckMethodAdapter, checkUnsignedShort, void, int32_t, $String*)},
	{"checkVisitCodeCalled", "()V", nullptr, $PRIVATE, $method(CheckMethodAdapter, checkVisitCodeCalled, void)},
	{"checkVisitEndNotCalled", "()V", nullptr, $PRIVATE, $method(CheckMethodAdapter, checkVisitEndNotCalled, void)},
	{"checkVisitMaxsNotCalled", "()V", nullptr, $PRIVATE, $method(CheckMethodAdapter, checkVisitMaxsNotCalled, void)},
	{"visitAnnotableParameterCount", "(IZ)V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitAnnotableParameterCount, void, int32_t, bool)},
	{"visitAnnotation", "(Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/AnnotationVisitor;", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitAnnotation, $AnnotationVisitor*, $String*, bool)},
	{"visitAnnotationDefault", "()Ljdk/internal/org/objectweb/asm/AnnotationVisitor;", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitAnnotationDefault, $AnnotationVisitor*)},
	{"visitAttribute", "(Ljdk/internal/org/objectweb/asm/Attribute;)V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitAttribute, void, $Attribute*)},
	{"visitCode", "()V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitCode, void)},
	{"visitEnd", "()V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitEnd, void)},
	{"visitFieldInsn", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitFieldInsn, void, int32_t, $String*, $String*, $String*)},
	{"visitFrame", "(II[Ljava/lang/Object;I[Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitFrame, void, int32_t, int32_t, $ObjectArray*, int32_t, $ObjectArray*)},
	{"visitIincInsn", "(II)V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitIincInsn, void, int32_t, int32_t)},
	{"visitInsn", "(I)V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitInsn, void, int32_t)},
	{"visitInsnAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/AnnotationVisitor;", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitInsnAnnotation, $AnnotationVisitor*, int32_t, $TypePath*, $String*, bool)},
	{"visitIntInsn", "(II)V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitIntInsn, void, int32_t, int32_t)},
	{"visitInvokeDynamicInsn", "(Ljava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/Handle;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(CheckMethodAdapter, visitInvokeDynamicInsn, void, $String*, $String*, $Handle*, $ObjectArray*)},
	{"visitJumpInsn", "(ILjdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitJumpInsn, void, int32_t, $Label*)},
	{"visitLabel", "(Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitLabel, void, $Label*)},
	{"visitLdcInsn", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitLdcInsn, void, Object$*)},
	{"visitLineNumber", "(ILjdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitLineNumber, void, int32_t, $Label*)},
	{"visitLocalVariable", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/Label;Ljdk/internal/org/objectweb/asm/Label;I)V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitLocalVariable, void, $String*, $String*, $String*, $Label*, $Label*, int32_t)},
	{"visitLocalVariableAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;[Ljdk/internal/org/objectweb/asm/Label;[Ljdk/internal/org/objectweb/asm/Label;[ILjava/lang/String;Z)Ljdk/internal/org/objectweb/asm/AnnotationVisitor;", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitLocalVariableAnnotation, $AnnotationVisitor*, int32_t, $TypePath*, $LabelArray*, $LabelArray*, $ints*, $String*, bool)},
	{"visitLookupSwitchInsn", "(Ljdk/internal/org/objectweb/asm/Label;[I[Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitLookupSwitchInsn, void, $Label*, $ints*, $LabelArray*)},
	{"visitMaxs", "(II)V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitMaxs, void, int32_t, int32_t)},
	{"visitMethodInsn", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitMethodInsn, void, int32_t, $String*, $String*, $String*, bool)},
	{"visitMultiANewArrayInsn", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitMultiANewArrayInsn, void, $String*, int32_t)},
	{"visitParameter", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitParameter, void, $String*, int32_t)},
	{"visitParameterAnnotation", "(ILjava/lang/String;Z)Ljdk/internal/org/objectweb/asm/AnnotationVisitor;", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitParameterAnnotation, $AnnotationVisitor*, int32_t, $String*, bool)},
	{"visitTableSwitchInsn", "(IILjdk/internal/org/objectweb/asm/Label;[Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(CheckMethodAdapter, visitTableSwitchInsn, void, int32_t, int32_t, $Label*, $LabelArray*)},
	{"visitTryCatchAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/AnnotationVisitor;", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitTryCatchAnnotation, $AnnotationVisitor*, int32_t, $TypePath*, $String*, bool)},
	{"visitTryCatchBlock", "(Ljdk/internal/org/objectweb/asm/Label;Ljdk/internal/org/objectweb/asm/Label;Ljdk/internal/org/objectweb/asm/Label;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitTryCatchBlock, void, $Label*, $Label*, $Label*, $String*)},
	{"visitTypeAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/AnnotationVisitor;", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitTypeAnnotation, $AnnotationVisitor*, int32_t, $TypePath*, $String*, bool)},
	{"visitTypeInsn", "(ILjava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitTypeInsn, void, int32_t, $String*)},
	{"visitVarInsn", "(II)V", nullptr, $PUBLIC, $virtualMethod(CheckMethodAdapter, visitVarInsn, void, int32_t, int32_t)},
	{}
};

$InnerClassInfo _CheckMethodAdapter_InnerClassesInfo_[] = {
	{"jdk.internal.org.objectweb.asm.util.CheckMethodAdapter$Method", "jdk.internal.org.objectweb.asm.util.CheckMethodAdapter", "Method", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{"jdk.internal.org.objectweb.asm.util.CheckMethodAdapter$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _CheckMethodAdapter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.util.CheckMethodAdapter",
	"jdk.internal.org.objectweb.asm.MethodVisitor",
	nullptr,
	_CheckMethodAdapter_FieldInfo_,
	_CheckMethodAdapter_MethodInfo_,
	nullptr,
	nullptr,
	_CheckMethodAdapter_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.org.objectweb.asm.util.CheckMethodAdapter$Method,jdk.internal.org.objectweb.asm.util.CheckMethodAdapter$1"
};

$Object* allocate$CheckMethodAdapter($Class* clazz) {
	return $of($alloc(CheckMethodAdapter));
}

$CheckMethodAdapter$MethodArray* CheckMethodAdapter::OPCODE_METHODS = nullptr;
$String* CheckMethodAdapter::INVALID = nullptr;
$String* CheckMethodAdapter::INVALID_DESCRIPTOR = nullptr;
$String* CheckMethodAdapter::INVALID_TYPE_REFERENCE = nullptr;
$String* CheckMethodAdapter::INVALID_LOCAL_VARIABLE_INDEX = nullptr;
$String* CheckMethodAdapter::MUST_NOT_BE_NULL_OR_EMPTY = nullptr;
$String* CheckMethodAdapter::START_LABEL = nullptr;
$String* CheckMethodAdapter::END_LABEL = nullptr;

void CheckMethodAdapter::init$($MethodVisitor* methodvisitor) {
	CheckMethodAdapter::init$(methodvisitor, $$new($HashMap));
}

void CheckMethodAdapter::init$($MethodVisitor* methodVisitor, $Map* labelInsnIndices) {
	CheckMethodAdapter::init$($Opcodes::ASM8, methodVisitor, labelInsnIndices);
	if ($of(this)->getClass() != CheckMethodAdapter::class$) {
		$throwNew($IllegalStateException);
	}
}

void CheckMethodAdapter::init$(int32_t api, $MethodVisitor* methodVisitor, $Map* labelInsnIndices) {
	$MethodVisitor::init$(api, methodVisitor);
	this->lastFrameInsnIndex = -1;
	$set(this, labelInsnIndices, labelInsnIndices);
	$set(this, referencedLabels, $new($HashSet));
	$set(this, handlers, $new($ArrayList));
}

void CheckMethodAdapter::init$(int32_t access, $String* name, $String* descriptor, $MethodVisitor* methodVisitor, $Map* labelInsnIndices) {
	CheckMethodAdapter::init$($Opcodes::ASM8, access, name, descriptor, methodVisitor, labelInsnIndices);
	if ($of(this)->getClass() != CheckMethodAdapter::class$) {
		$throwNew($IllegalStateException);
	}
}

void CheckMethodAdapter::init$(int32_t api, int32_t access, $String* name, $String* descriptor, $MethodVisitor* methodVisitor, $Map* labelInsnIndices) {
	CheckMethodAdapter::init$(api, $$new($CheckMethodAdapter$1, api, access, name, descriptor, nullptr, nullptr, methodVisitor), labelInsnIndices);
	this->access = access;
}

void CheckMethodAdapter::visitParameter($String* name, int32_t access) {
	if (name != nullptr) {
		checkUnqualifiedName(this->version, name, "name"_s);
	}
	$CheckClassAdapter::checkAccess(access, $Opcodes::ACC_FINAL + $Opcodes::ACC_MANDATED + $Opcodes::ACC_SYNTHETIC);
	$MethodVisitor::visitParameter(name, access);
}

$AnnotationVisitor* CheckMethodAdapter::visitAnnotation($String* descriptor, bool visible) {
	checkVisitEndNotCalled();
	checkDescriptor(this->version, descriptor, false);
	return $new($CheckAnnotationAdapter, $($MethodVisitor::visitAnnotation(descriptor, visible)));
}

$AnnotationVisitor* CheckMethodAdapter::visitTypeAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	$useLocalCurrentObjectStackCache();
	checkVisitEndNotCalled();
	int32_t sort = $$new($TypeReference, typeRef)->getSort();
	if (sort != $TypeReference::METHOD_TYPE_PARAMETER && sort != $TypeReference::METHOD_TYPE_PARAMETER_BOUND && sort != $TypeReference::METHOD_RETURN && sort != $TypeReference::METHOD_RECEIVER && sort != $TypeReference::METHOD_FORMAL_PARAMETER && sort != $TypeReference::THROWS) {
		$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID_TYPE_REFERENCE, $($Integer::toHexString(sort))}));
	}
	$CheckClassAdapter::checkTypeRef(typeRef);
	CheckMethodAdapter::checkDescriptor(this->version, descriptor, false);
	return $new($CheckAnnotationAdapter, $($MethodVisitor::visitTypeAnnotation(typeRef, typePath, descriptor, visible)));
}

$AnnotationVisitor* CheckMethodAdapter::visitAnnotationDefault() {
	checkVisitEndNotCalled();
	return $new($CheckAnnotationAdapter, $($MethodVisitor::visitAnnotationDefault()), false);
}

void CheckMethodAdapter::visitAnnotableParameterCount(int32_t parameterCount, bool visible) {
	checkVisitEndNotCalled();
	if (visible) {
		this->visibleAnnotableParameterCount = parameterCount;
	} else {
		this->invisibleAnnotableParameterCount = parameterCount;
	}
	$MethodVisitor::visitAnnotableParameterCount(parameterCount, visible);
}

$AnnotationVisitor* CheckMethodAdapter::visitParameterAnnotation(int32_t parameter, $String* descriptor, bool visible) {
	checkVisitEndNotCalled();
	if ((visible && this->visibleAnnotableParameterCount > 0 && parameter >= this->visibleAnnotableParameterCount) || (!visible && this->invisibleAnnotableParameterCount > 0 && parameter >= this->invisibleAnnotableParameterCount)) {
		$throwNew($IllegalArgumentException, "Invalid parameter index"_s);
	}
	checkDescriptor(this->version, descriptor, false);
	return $new($CheckAnnotationAdapter, $($MethodVisitor::visitParameterAnnotation(parameter, descriptor, visible)));
}

void CheckMethodAdapter::visitAttribute($Attribute* attribute) {
	checkVisitEndNotCalled();
	if (attribute == nullptr) {
		$throwNew($IllegalArgumentException, "Invalid attribute (must not be null)"_s);
	}
	$MethodVisitor::visitAttribute(attribute);
}

void CheckMethodAdapter::visitCode() {
	if (((int32_t)(this->access & (uint32_t)$Opcodes::ACC_ABSTRACT)) != 0) {
		$throwNew($UnsupportedOperationException, "Abstract methods cannot have code"_s);
	}
	this->visitCodeCalled = true;
	$MethodVisitor::visitCode();
}

void CheckMethodAdapter::visitFrame(int32_t type, int32_t numLocal, $ObjectArray* local, int32_t numStack, $ObjectArray* stack) {
	$useLocalCurrentObjectStackCache();
	if (this->insnCount == this->lastFrameInsnIndex) {
		$throwNew($IllegalStateException, "At most one frame can be visited at a given code location."_s);
	}
	this->lastFrameInsnIndex = this->insnCount;
	int32_t maxNumLocal = 0;
	int32_t maxNumStack = 0;
	switch (type) {
	case $Opcodes::F_NEW:
		{}
	case $Opcodes::F_FULL:
		{
			maxNumLocal = $Integer::MAX_VALUE;
			maxNumStack = $Integer::MAX_VALUE;
			break;
		}
	case $Opcodes::F_SAME:
		{
			maxNumLocal = 0;
			maxNumStack = 0;
			break;
		}
	case $Opcodes::F_SAME1:
		{
			maxNumLocal = 0;
			maxNumStack = 1;
			break;
		}
	case $Opcodes::F_APPEND:
		{}
	case $Opcodes::F_CHOP:
		{
			maxNumLocal = 3;
			maxNumStack = 0;
			break;
		}
	default:
		{
			$throwNew($IllegalArgumentException, $$str({"Invalid frame type "_s, $$str(type)}));
		}
	}
	if (numLocal > maxNumLocal) {
		$throwNew($IllegalArgumentException, $$str({"Invalid numLocal="_s, $$str(numLocal), " for frame type "_s, $$str(type)}));
	}
	if (numStack > maxNumStack) {
		$throwNew($IllegalArgumentException, $$str({"Invalid numStack="_s, $$str(numStack), " for frame type "_s, $$str(type)}));
	}
	if (type != $Opcodes::F_CHOP) {
		if (numLocal > 0 && (local == nullptr || $nc(local)->length < numLocal)) {
			$throwNew($IllegalArgumentException, "Array local[] is shorter than numLocal"_s);
		}
		for (int32_t i = 0; i < numLocal; ++i) {
			checkFrameValue($nc(local)->get(i));
		}
	}
	if (numStack > 0 && (stack == nullptr || $nc(stack)->length < numStack)) {
		$throwNew($IllegalArgumentException, "Array stack[] is shorter than numStack"_s);
	}
	for (int32_t i = 0; i < numStack; ++i) {
		checkFrameValue($nc(stack)->get(i));
	}
	if (type == $Opcodes::F_NEW) {
		++this->numExpandedFrames;
	} else {
		++this->numCompressedFrames;
	}
	if (this->numExpandedFrames > 0 && this->numCompressedFrames > 0) {
		$throwNew($IllegalArgumentException, "Expanded and compressed frames must not be mixed."_s);
	}
	$MethodVisitor::visitFrame(type, numLocal, local, numStack, stack);
}

void CheckMethodAdapter::visitInsn(int32_t opcode) {
	checkVisitCodeCalled();
	checkVisitMaxsNotCalled();
	$init($CheckMethodAdapter$Method);
	checkOpcodeMethod(opcode, $CheckMethodAdapter$Method::VISIT_INSN);
	$MethodVisitor::visitInsn(opcode);
	++this->insnCount;
}

void CheckMethodAdapter::visitIntInsn(int32_t opcode, int32_t operand) {
	$useLocalCurrentObjectStackCache();
	checkVisitCodeCalled();
	checkVisitMaxsNotCalled();
	$init($CheckMethodAdapter$Method);
	checkOpcodeMethod(opcode, $CheckMethodAdapter$Method::VISIT_INT_INSN);
	switch (opcode) {
	case $Opcodes::BIPUSH:
		{
			checkSignedByte(operand, "Invalid operand"_s);
			break;
		}
	case $Opcodes::SIPUSH:
		{
			checkSignedShort(operand, "Invalid operand"_s);
			break;
		}
	case $Opcodes::NEWARRAY:
		{
			if (operand < $Opcodes::T_BOOLEAN || operand > $Opcodes::T_LONG) {
				$throwNew($IllegalArgumentException, $$str({"Invalid operand (must be an array type code T_...): "_s, $$str(operand)}));
			}
			break;
		}
	default:
		{
			$throwNew($AssertionError);
		}
	}
	$MethodVisitor::visitIntInsn(opcode, operand);
	++this->insnCount;
}

void CheckMethodAdapter::visitVarInsn(int32_t opcode, int32_t var) {
	checkVisitCodeCalled();
	checkVisitMaxsNotCalled();
	$init($CheckMethodAdapter$Method);
	checkOpcodeMethod(opcode, $CheckMethodAdapter$Method::VISIT_VAR_INSN);
	checkUnsignedShort(var, CheckMethodAdapter::INVALID_LOCAL_VARIABLE_INDEX);
	$MethodVisitor::visitVarInsn(opcode, var);
	++this->insnCount;
}

void CheckMethodAdapter::visitTypeInsn(int32_t opcode, $String* type) {
	checkVisitCodeCalled();
	checkVisitMaxsNotCalled();
	$init($CheckMethodAdapter$Method);
	checkOpcodeMethod(opcode, $CheckMethodAdapter$Method::VISIT_TYPE_INSN);
	checkInternalName(this->version, type, "type"_s);
	if (opcode == $Opcodes::NEW && $nc(type)->charAt(0) == u'[') {
		$throwNew($IllegalArgumentException, $$str({"NEW cannot be used to create arrays: "_s, type}));
	}
	$MethodVisitor::visitTypeInsn(opcode, type);
	++this->insnCount;
}

void CheckMethodAdapter::visitFieldInsn(int32_t opcode, $String* owner, $String* name, $String* descriptor) {
	checkVisitCodeCalled();
	checkVisitMaxsNotCalled();
	$init($CheckMethodAdapter$Method);
	checkOpcodeMethod(opcode, $CheckMethodAdapter$Method::VISIT_FIELD_INSN);
	checkInternalName(this->version, owner, "owner"_s);
	checkUnqualifiedName(this->version, name, "name"_s);
	checkDescriptor(this->version, descriptor, false);
	$MethodVisitor::visitFieldInsn(opcode, owner, name, descriptor);
	++this->insnCount;
}

void CheckMethodAdapter::visitMethodInsn(int32_t opcodeAndSource, $String* owner, $String* name, $String* descriptor, bool isInterface) {
	if (this->api < $Opcodes::ASM5 && ((int32_t)(opcodeAndSource & (uint32_t)$Opcodes::SOURCE_DEPRECATED)) == 0) {
		$MethodVisitor::visitMethodInsn(opcodeAndSource, owner, name, descriptor, isInterface);
		return;
	}
	int32_t opcode = (int32_t)(opcodeAndSource & (uint32_t)~$Opcodes::SOURCE_MASK);
	checkVisitCodeCalled();
	checkVisitMaxsNotCalled();
	$init($CheckMethodAdapter$Method);
	checkOpcodeMethod(opcode, $CheckMethodAdapter$Method::VISIT_METHOD_INSN);
	if (opcode != $Opcodes::INVOKESPECIAL || !"<init>"_s->equals(name)) {
		checkMethodIdentifier(this->version, name, "name"_s);
	}
	checkInternalName(this->version, owner, "owner"_s);
	checkMethodDescriptor(this->version, descriptor);
	if (opcode == $Opcodes::INVOKEVIRTUAL && isInterface) {
		$throwNew($IllegalArgumentException, "INVOKEVIRTUAL can\'t be used with interfaces"_s);
	}
	if (opcode == $Opcodes::INVOKEINTERFACE && !isInterface) {
		$throwNew($IllegalArgumentException, "INVOKEINTERFACE can\'t be used with classes"_s);
	}
	if (opcode == $Opcodes::INVOKESPECIAL && isInterface && ((int32_t)(this->version & (uint32_t)0x0000FFFF)) < $Opcodes::V1_8) {
		$throwNew($IllegalArgumentException, "INVOKESPECIAL can\'t be used with interfaces prior to Java 8"_s);
	}
	$MethodVisitor::visitMethodInsn(opcodeAndSource, owner, name, descriptor, isInterface);
	++this->insnCount;
}

void CheckMethodAdapter::visitInvokeDynamicInsn($String* name, $String* descriptor, $Handle* bootstrapMethodHandle, $ObjectArray* bootstrapMethodArguments) {
	$useLocalCurrentObjectStackCache();
	checkVisitCodeCalled();
	checkVisitMaxsNotCalled();
	checkMethodIdentifier(this->version, name, "name"_s);
	checkMethodDescriptor(this->version, descriptor);
	bool var$0 = $nc(bootstrapMethodHandle)->getTag() != $Opcodes::H_INVOKESTATIC;
	if (var$0 && bootstrapMethodHandle->getTag() != $Opcodes::H_NEWINVOKESPECIAL) {
		$throwNew($IllegalArgumentException, $$str({"invalid handle tag "_s, $$str(bootstrapMethodHandle->getTag())}));
	}
	{
		$var($ObjectArray, arr$, bootstrapMethodArguments);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Object0, bootstrapMethodArgument, arr$->get(i$));
			{
				checkLdcConstant(bootstrapMethodArgument);
			}
		}
	}
	$MethodVisitor::visitInvokeDynamicInsn(name, descriptor, bootstrapMethodHandle, bootstrapMethodArguments);
	++this->insnCount;
}

void CheckMethodAdapter::visitJumpInsn(int32_t opcode, $Label* label) {
	checkVisitCodeCalled();
	checkVisitMaxsNotCalled();
	$init($CheckMethodAdapter$Method);
	checkOpcodeMethod(opcode, $CheckMethodAdapter$Method::VISIT_JUMP_INSN);
	checkLabel(label, false, "label"_s);
	$MethodVisitor::visitJumpInsn(opcode, label);
	$nc(this->referencedLabels)->add(label);
	++this->insnCount;
}

void CheckMethodAdapter::visitLabel($Label* label) {
	checkVisitCodeCalled();
	checkVisitMaxsNotCalled();
	checkLabel(label, false, "label"_s);
	if ($nc(this->labelInsnIndices)->get(label) != nullptr) {
		$throwNew($IllegalArgumentException, "Already visited label"_s);
	}
	$nc(this->labelInsnIndices)->put(label, $($Integer::valueOf(this->insnCount)));
	$MethodVisitor::visitLabel(label);
}

void CheckMethodAdapter::visitLdcInsn(Object$* value) {
	checkVisitCodeCalled();
	checkVisitMaxsNotCalled();
	checkLdcConstant(value);
	$MethodVisitor::visitLdcInsn(value);
	++this->insnCount;
}

void CheckMethodAdapter::visitIincInsn(int32_t var, int32_t increment) {
	checkVisitCodeCalled();
	checkVisitMaxsNotCalled();
	checkUnsignedShort(var, CheckMethodAdapter::INVALID_LOCAL_VARIABLE_INDEX);
	checkSignedShort(increment, "Invalid increment"_s);
	$MethodVisitor::visitIincInsn(var, increment);
	++this->insnCount;
}

void CheckMethodAdapter::visitTableSwitchInsn(int32_t min, int32_t max, $Label* dflt, $LabelArray* labels) {
	$useLocalCurrentObjectStackCache();
	checkVisitCodeCalled();
	checkVisitMaxsNotCalled();
	if (max < min) {
		$throwNew($IllegalArgumentException, $$str({"Max = "_s, $$str(max), " must be greater than or equal to min = "_s, $$str(min)}));
	}
	checkLabel(dflt, false, "default label"_s);
	if (labels == nullptr || $nc(labels)->length != max - min + 1) {
		$throwNew($IllegalArgumentException, "There must be max - min + 1 labels"_s);
	}
	for (int32_t i = 0; i < $nc(labels)->length; ++i) {
		checkLabel(labels->get(i), false, $$str({"label at index "_s, $$str(i)}));
	}
	$MethodVisitor::visitTableSwitchInsn(min, max, dflt, labels);
	$Collections::addAll(this->referencedLabels, labels);
	++this->insnCount;
}

void CheckMethodAdapter::visitLookupSwitchInsn($Label* dflt, $ints* keys, $LabelArray* labels) {
	$useLocalCurrentObjectStackCache();
	checkVisitMaxsNotCalled();
	checkVisitCodeCalled();
	checkLabel(dflt, false, "default label"_s);
	if (keys == nullptr || labels == nullptr || $nc(keys)->length != $nc(labels)->length) {
		$throwNew($IllegalArgumentException, "There must be the same number of keys and labels"_s);
	}
	for (int32_t i = 0; i < $nc(labels)->length; ++i) {
		checkLabel(labels->get(i), false, $$str({"label at index "_s, $$str(i)}));
	}
	$MethodVisitor::visitLookupSwitchInsn(dflt, keys, labels);
	$nc(this->referencedLabels)->add(dflt);
	$Collections::addAll(this->referencedLabels, labels);
	++this->insnCount;
}

void CheckMethodAdapter::visitMultiANewArrayInsn($String* descriptor, int32_t numDimensions) {
	$useLocalCurrentObjectStackCache();
	checkVisitCodeCalled();
	checkVisitMaxsNotCalled();
	checkDescriptor(this->version, descriptor, false);
	if ($nc(descriptor)->charAt(0) != u'[') {
		$throwNew($IllegalArgumentException, $$str({"Invalid descriptor (must be an array type descriptor): "_s, descriptor}));
	}
	if (numDimensions < 1) {
		$throwNew($IllegalArgumentException, $$str({"Invalid dimensions (must be greater than 0): "_s, $$str(numDimensions)}));
	}
	if (numDimensions > $nc(descriptor)->lastIndexOf((int32_t)u'[') + 1) {
		$throwNew($IllegalArgumentException, $$str({"Invalid dimensions (must not be greater than numDimensions(descriptor)): "_s, $$str(numDimensions)}));
	}
	$MethodVisitor::visitMultiANewArrayInsn(descriptor, numDimensions);
	++this->insnCount;
}

$AnnotationVisitor* CheckMethodAdapter::visitInsnAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	$useLocalCurrentObjectStackCache();
	checkVisitCodeCalled();
	checkVisitMaxsNotCalled();
	int32_t sort = $$new($TypeReference, typeRef)->getSort();
	if (sort != $TypeReference::INSTANCEOF && sort != $TypeReference::NEW && sort != $TypeReference::CONSTRUCTOR_REFERENCE && sort != $TypeReference::METHOD_REFERENCE && sort != $TypeReference::CAST && sort != $TypeReference::CONSTRUCTOR_INVOCATION_TYPE_ARGUMENT && sort != $TypeReference::METHOD_INVOCATION_TYPE_ARGUMENT && sort != $TypeReference::CONSTRUCTOR_REFERENCE_TYPE_ARGUMENT && sort != $TypeReference::METHOD_REFERENCE_TYPE_ARGUMENT) {
		$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID_TYPE_REFERENCE, $($Integer::toHexString(sort))}));
	}
	$CheckClassAdapter::checkTypeRef(typeRef);
	CheckMethodAdapter::checkDescriptor(this->version, descriptor, false);
	return $new($CheckAnnotationAdapter, $($MethodVisitor::visitInsnAnnotation(typeRef, typePath, descriptor, visible)));
}

void CheckMethodAdapter::visitTryCatchBlock($Label* start, $Label* end, $Label* handler, $String* type) {
	checkVisitCodeCalled();
	checkVisitMaxsNotCalled();
	checkLabel(start, false, CheckMethodAdapter::START_LABEL);
	checkLabel(end, false, CheckMethodAdapter::END_LABEL);
	checkLabel(handler, false, "handler label"_s);
	bool var$1 = $nc(this->labelInsnIndices)->get(start) != nullptr;
	bool var$0 = var$1 || $nc(this->labelInsnIndices)->get(end) != nullptr;
	if (var$0 || $nc(this->labelInsnIndices)->get(handler) != nullptr) {
		$throwNew($IllegalStateException, "Try catch blocks must be visited before their labels"_s);
	}
	if (type != nullptr) {
		checkInternalName(this->version, type, "type"_s);
	}
	$MethodVisitor::visitTryCatchBlock(start, end, handler, type);
	$nc(this->handlers)->add(start);
	$nc(this->handlers)->add(end);
}

$AnnotationVisitor* CheckMethodAdapter::visitTryCatchAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	$useLocalCurrentObjectStackCache();
	checkVisitCodeCalled();
	checkVisitMaxsNotCalled();
	int32_t sort = $$new($TypeReference, typeRef)->getSort();
	if (sort != $TypeReference::EXCEPTION_PARAMETER) {
		$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID_TYPE_REFERENCE, $($Integer::toHexString(sort))}));
	}
	$CheckClassAdapter::checkTypeRef(typeRef);
	CheckMethodAdapter::checkDescriptor(this->version, descriptor, false);
	return $new($CheckAnnotationAdapter, $($MethodVisitor::visitTryCatchAnnotation(typeRef, typePath, descriptor, visible)));
}

void CheckMethodAdapter::visitLocalVariable($String* name, $String* descriptor, $String* signature, $Label* start, $Label* end, int32_t index) {
	$useLocalCurrentObjectStackCache();
	checkVisitCodeCalled();
	checkVisitMaxsNotCalled();
	checkUnqualifiedName(this->version, name, "name"_s);
	checkDescriptor(this->version, descriptor, false);
	if (signature != nullptr) {
		$CheckClassAdapter::checkFieldSignature(signature);
	}
	checkLabel(start, true, CheckMethodAdapter::START_LABEL);
	checkLabel(end, true, CheckMethodAdapter::END_LABEL);
	checkUnsignedShort(index, CheckMethodAdapter::INVALID_LOCAL_VARIABLE_INDEX);
	int32_t startInsnIndex = $nc(($cast($Integer, $($nc(this->labelInsnIndices)->get(start)))))->intValue();
	int32_t endInsnIndex = $nc(($cast($Integer, $($nc(this->labelInsnIndices)->get(end)))))->intValue();
	if (endInsnIndex < startInsnIndex) {
		$throwNew($IllegalArgumentException, "Invalid start and end labels (end must be greater than start)"_s);
	}
	$MethodVisitor::visitLocalVariable(name, descriptor, signature, start, end, index);
}

$AnnotationVisitor* CheckMethodAdapter::visitLocalVariableAnnotation(int32_t typeRef, $TypePath* typePath, $LabelArray* start, $LabelArray* end, $ints* index, $String* descriptor, bool visible) {
	$useLocalCurrentObjectStackCache();
	checkVisitCodeCalled();
	checkVisitMaxsNotCalled();
	int32_t sort = $$new($TypeReference, typeRef)->getSort();
	if (sort != $TypeReference::LOCAL_VARIABLE && sort != $TypeReference::RESOURCE_VARIABLE) {
		$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID_TYPE_REFERENCE, $($Integer::toHexString(sort))}));
	}
	$CheckClassAdapter::checkTypeRef(typeRef);
	checkDescriptor(this->version, descriptor, false);
	if (start == nullptr || end == nullptr || index == nullptr || $nc(end)->length != $nc(start)->length || $nc(index)->length != $nc(start)->length) {
		$throwNew($IllegalArgumentException, "Invalid start, end and index arrays (must be non null and of identical length"_s);
	}
	for (int32_t i = 0; i < $nc(start)->length; ++i) {
		checkLabel(start->get(i), true, CheckMethodAdapter::START_LABEL);
		checkLabel($nc(end)->get(i), true, CheckMethodAdapter::END_LABEL);
		checkUnsignedShort($nc(index)->get(i), CheckMethodAdapter::INVALID_LOCAL_VARIABLE_INDEX);
		int32_t startInsnIndex = $nc(($cast($Integer, $($nc(this->labelInsnIndices)->get(start->get(i))))))->intValue();
		int32_t endInsnIndex = $nc(($cast($Integer, $($nc(this->labelInsnIndices)->get($nc(end)->get(i))))))->intValue();
		if (endInsnIndex < startInsnIndex) {
			$throwNew($IllegalArgumentException, "Invalid start and end labels (end must be greater than start)"_s);
		}
	}
	return $MethodVisitor::visitLocalVariableAnnotation(typeRef, typePath, start, end, index, descriptor, visible);
}

void CheckMethodAdapter::visitLineNumber(int32_t line, $Label* start) {
	checkVisitCodeCalled();
	checkVisitMaxsNotCalled();
	checkUnsignedShort(line, "Invalid line number"_s);
	checkLabel(start, true, CheckMethodAdapter::START_LABEL);
	$MethodVisitor::visitLineNumber(line, start);
}

void CheckMethodAdapter::visitMaxs(int32_t maxStack, int32_t maxLocals) {
	$useLocalCurrentObjectStackCache();
	checkVisitCodeCalled();
	checkVisitMaxsNotCalled();
	this->visitMaxCalled = true;
	{
		$var($Iterator, i$, $nc(this->referencedLabels)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Label, l, $cast($Label, i$->next()));
			{
				if ($nc(this->labelInsnIndices)->get(l) == nullptr) {
					$throwNew($IllegalStateException, "Undefined label used"_s);
				}
			}
		}
	}
	for (int32_t i = 0; i < $nc(this->handlers)->size(); i += 2) {
		$var($Integer, startInsnIndex, $cast($Integer, $nc(this->labelInsnIndices)->get($($nc(this->handlers)->get(i)))));
		$var($Integer, endInsnIndex, $cast($Integer, $nc(this->labelInsnIndices)->get($($nc(this->handlers)->get(i + 1)))));
		if (startInsnIndex == nullptr || endInsnIndex == nullptr) {
			$throwNew($IllegalStateException, "Undefined try catch block labels"_s);
		}
		int32_t var$0 = $nc(endInsnIndex)->intValue();
		if (var$0 <= $nc(startInsnIndex)->intValue()) {
			$throwNew($IllegalStateException, "Emty try catch block handler range"_s);
		}
	}
	checkUnsignedShort(maxStack, "Invalid max stack"_s);
	checkUnsignedShort(maxLocals, "Invalid max locals"_s);
	$MethodVisitor::visitMaxs(maxStack, maxLocals);
}

void CheckMethodAdapter::visitEnd() {
	checkVisitEndNotCalled();
	this->visitEndCalled = true;
	$MethodVisitor::visitEnd();
}

void CheckMethodAdapter::checkVisitCodeCalled() {
	if (!this->visitCodeCalled) {
		$throwNew($IllegalStateException, "Cannot visit instructions before visitCode has been called."_s);
	}
}

void CheckMethodAdapter::checkVisitMaxsNotCalled() {
	if (this->visitMaxCalled) {
		$throwNew($IllegalStateException, "Cannot visit instructions after visitMaxs has been called."_s);
	}
}

void CheckMethodAdapter::checkVisitEndNotCalled() {
	if (this->visitEndCalled) {
		$throwNew($IllegalStateException, "Cannot visit elements after visitEnd has been called."_s);
	}
}

void CheckMethodAdapter::checkFrameValue(Object$* value) {
	$init($Opcodes);
	if ($equals(value, $Opcodes::TOP) || $equals(value, $Opcodes::INTEGER) || $equals(value, $Opcodes::FLOAT) || $equals(value, $Opcodes::LONG) || $equals(value, $Opcodes::DOUBLE) || $equals(value, $Opcodes::NULL) || $equals(value, $Opcodes::UNINITIALIZED_THIS)) {
		return;
	}
	if ($instanceOf($String, value)) {
		checkInternalName(this->version, $cast($String, value), "Invalid stack frame value"_s);
	} else if ($instanceOf($Label, value)) {
		$nc(this->referencedLabels)->add($cast($Label, value));
	} else {
		$throwNew($IllegalArgumentException, $$str({"Invalid stack frame value: "_s, value}));
	}
}

void CheckMethodAdapter::checkOpcodeMethod(int32_t opcode, $CheckMethodAdapter$Method* method) {
	$init(CheckMethodAdapter);
	$useLocalCurrentObjectStackCache();
	if (opcode < $Opcodes::NOP || opcode > $Opcodes::IFNONNULL || $nc(CheckMethodAdapter::OPCODE_METHODS)->get(opcode) != method) {
		$throwNew($IllegalArgumentException, $$str({"Invalid opcode: "_s, $$str(opcode)}));
	}
}

void CheckMethodAdapter::checkSignedByte(int32_t value, $String* message) {
	$init(CheckMethodAdapter);
	$useLocalCurrentObjectStackCache();
	if (value < $Byte::MIN_VALUE || value > $Byte::MAX_VALUE) {
		$throwNew($IllegalArgumentException, $$str({message, " (must be a signed byte): "_s, $$str(value)}));
	}
}

void CheckMethodAdapter::checkSignedShort(int32_t value, $String* message) {
	$init(CheckMethodAdapter);
	$useLocalCurrentObjectStackCache();
	if (value < $Short::MIN_VALUE || value > $Short::MAX_VALUE) {
		$throwNew($IllegalArgumentException, $$str({message, " (must be a signed short): "_s, $$str(value)}));
	}
}

void CheckMethodAdapter::checkUnsignedShort(int32_t value, $String* message) {
	$init(CheckMethodAdapter);
	$useLocalCurrentObjectStackCache();
	if (value < 0 || value > 0x0000FFFF) {
		$throwNew($IllegalArgumentException, $$str({message, " (must be an unsigned short): "_s, $$str(value)}));
	}
}

void CheckMethodAdapter::checkConstant(Object$* value) {
	$init(CheckMethodAdapter);
	if (!($instanceOf($Integer, value)) && !($instanceOf($Float, value)) && !($instanceOf($Long, value)) && !($instanceOf($Double, value)) && !($instanceOf($String, value))) {
		$throwNew($IllegalArgumentException, $$str({"Invalid constant: "_s, value}));
	}
}

void CheckMethodAdapter::checkLdcConstant(Object$* value) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($Type, value)) {
		int32_t sort = $nc(($cast($Type, value)))->getSort();
		if (sort != $Type::OBJECT && sort != $Type::ARRAY && sort != $Type::METHOD) {
			$throwNew($IllegalArgumentException, "Illegal LDC constant value"_s);
		}
		if (sort != $Type::METHOD && ((int32_t)(this->version & (uint32_t)0x0000FFFF)) < $Opcodes::V1_5) {
			$throwNew($IllegalArgumentException, "ldc of a constant class requires at least version 1.5"_s);
		}
		if (sort == $Type::METHOD && ((int32_t)(this->version & (uint32_t)0x0000FFFF)) < $Opcodes::V1_7) {
			$throwNew($IllegalArgumentException, "ldc of a method type requires at least version 1.7"_s);
		}
	} else if ($instanceOf($Handle, value)) {
		if (((int32_t)(this->version & (uint32_t)0x0000FFFF)) < $Opcodes::V1_7) {
			$throwNew($IllegalArgumentException, "ldc of a Handle requires at least version 1.7"_s);
		}
		$var($Handle, handle, $cast($Handle, value));
		int32_t tag = $nc(handle)->getTag();
		if (tag < $Opcodes::H_GETFIELD || tag > $Opcodes::H_INVOKEINTERFACE) {
			$throwNew($IllegalArgumentException, $$str({"invalid handle tag "_s, $$str(tag)}));
		}
		checkInternalName(this->version, $(handle->getOwner()), "handle owner"_s);
		if (tag <= $Opcodes::H_PUTSTATIC) {
			checkDescriptor(this->version, $(handle->getDesc()), false);
		} else {
			checkMethodDescriptor(this->version, $(handle->getDesc()));
		}
		$var($String, handleName, handle->getName());
		if (!("<init>"_s->equals(handleName) && tag == $Opcodes::H_NEWINVOKESPECIAL)) {
			checkMethodIdentifier(this->version, handleName, "handle name"_s);
		}
	} else if ($instanceOf($ConstantDynamic, value)) {
		if (((int32_t)(this->version & (uint32_t)0x0000FFFF)) < $Opcodes::V11) {
			$throwNew($IllegalArgumentException, "ldc of a ConstantDynamic requires at least version 11"_s);
		}
		$var($ConstantDynamic, constantDynamic, $cast($ConstantDynamic, value));
		checkMethodIdentifier(this->version, $($nc(constantDynamic)->getName()), "constant dynamic name"_s);
		checkDescriptor(this->version, $($nc(constantDynamic)->getDescriptor()), false);
		checkLdcConstant($($nc(constantDynamic)->getBootstrapMethod()));
		int32_t bootstrapMethodArgumentCount = $nc(constantDynamic)->getBootstrapMethodArgumentCount();
		for (int32_t i = 0; i < bootstrapMethodArgumentCount; ++i) {
			checkLdcConstant($(constantDynamic->getBootstrapMethodArgument(i)));
		}
	} else {
		checkConstant(value);
	}
}

void CheckMethodAdapter::checkUnqualifiedName(int32_t version, $String* name, $String* message) {
	$init(CheckMethodAdapter);
	checkIdentifier(version, name, 0, -1, message);
}

void CheckMethodAdapter::checkIdentifier(int32_t version, $String* name, int32_t startPos, int32_t endPos, $String* message) {
	$init(CheckMethodAdapter);
	$useLocalCurrentObjectStackCache();
	if (name == nullptr || (endPos == -1 ? $nc(name)->length() <= startPos : endPos <= startPos)) {
		$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID, message, CheckMethodAdapter::MUST_NOT_BE_NULL_OR_EMPTY}));
	}
	int32_t max = endPos == -1 ? $nc(name)->length() : endPos;
	if (((int32_t)(version & (uint32_t)0x0000FFFF)) >= $Opcodes::V1_5) {
		for (int32_t i = startPos; i < max; i = name->offsetByCodePoints(i, 1)) {
			if (".;[/"_s->indexOf(name->codePointAt(i)) != -1) {
				$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID, message, " (must not contain . ; [ or /): "_s, name}));
			}
		}
		return;
	}
	for (int32_t i = startPos; i < max; i = name->offsetByCodePoints(i, 1)) {
		if (i == startPos ? !$Character::isJavaIdentifierStart(name->codePointAt(i)) : !$Character::isJavaIdentifierPart(name->codePointAt(i))) {
			$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID, message, " (must be a valid Java identifier): "_s, name}));
		}
	}
}

void CheckMethodAdapter::checkMethodIdentifier(int32_t version, $String* name, $String* message) {
	$init(CheckMethodAdapter);
	$useLocalCurrentObjectStackCache();
	if (name == nullptr || $nc(name)->length() == 0) {
		$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID, message, CheckMethodAdapter::MUST_NOT_BE_NULL_OR_EMPTY}));
	}
	if (((int32_t)(version & (uint32_t)0x0000FFFF)) >= $Opcodes::V1_5) {
		for (int32_t i = 0; i < $nc(name)->length(); i = $nc(name)->offsetByCodePoints(i, 1)) {
			if (".;[/<>"_s->indexOf(name->codePointAt(i)) != -1) {
				$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID, message, " (must be a valid unqualified name): "_s, name}));
			}
		}
		return;
	}
	for (int32_t i = 0; i < $nc(name)->length(); i = $nc(name)->offsetByCodePoints(i, 1)) {
		if (i == 0 ? !$Character::isJavaIdentifierStart(name->codePointAt(i)) : !$Character::isJavaIdentifierPart(name->codePointAt(i))) {
			$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID, message, " (must be a \'<init>\', \'<clinit>\' or a valid Java identifier): "_s, name}));
		}
	}
}

void CheckMethodAdapter::checkInternalName(int32_t version, $String* name, $String* message) {
	$init(CheckMethodAdapter);
	if (name == nullptr || $nc(name)->length() == 0) {
		$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID, message, CheckMethodAdapter::MUST_NOT_BE_NULL_OR_EMPTY}));
	}
	if ($nc(name)->charAt(0) == u'[') {
		checkDescriptor(version, name, false);
	} else {
		checkInternalClassName(version, name, message);
	}
}

void CheckMethodAdapter::checkInternalClassName(int32_t version, $String* name, $String* message) {
	$init(CheckMethodAdapter);
	try {
		int32_t startIndex = 0;
		int32_t slashIndex = 0;
		while ((slashIndex = $nc(name)->indexOf((int32_t)u'/', startIndex + 1)) != -1) {
			checkIdentifier(version, name, startIndex, slashIndex, nullptr);
			startIndex = slashIndex + 1;
		}
		checkIdentifier(version, name, startIndex, $nc(name)->length(), nullptr);
	} catch ($IllegalArgumentException& e) {
		$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID, message, " (must be an internal class name): "_s, name}), e);
	}
}

void CheckMethodAdapter::checkDescriptor(int32_t version, $String* descriptor, bool canBeVoid) {
	$init(CheckMethodAdapter);
	int32_t endPos = checkDescriptor(version, descriptor, 0, canBeVoid);
	if (endPos != $nc(descriptor)->length()) {
		$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID_DESCRIPTOR, descriptor}));
	}
}

int32_t CheckMethodAdapter::checkDescriptor(int32_t version, $String* descriptor, int32_t startPos, bool canBeVoid) {
	$init(CheckMethodAdapter);
	$useLocalCurrentObjectStackCache();
	if (descriptor == nullptr || startPos >= $nc(descriptor)->length()) {
		$throwNew($IllegalArgumentException, "Invalid type descriptor (must not be null or empty)"_s);
	}
	{
		int32_t pos = 0;
		int32_t endPos = 0;
		switch ($nc(descriptor)->charAt(startPos)) {
		case u'V':
			{
				if (canBeVoid) {
					return startPos + 1;
				} else {
					$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID_DESCRIPTOR, descriptor}));
				}
			}
		case u'Z':
			{}
		case u'C':
			{}
		case u'B':
			{}
		case u'S':
			{}
		case u'I':
			{}
		case u'F':
			{}
		case u'J':
			{}
		case u'D':
			{
				return startPos + 1;
			}
		case u'[':
			{
				pos = startPos + 1;
				while (true) {
					bool var$0 = pos < descriptor->length();
					if (!(var$0 && descriptor->charAt(pos) == u'[')) {
						break;
					}
					{
						++pos;
					}
				}
				if (pos < descriptor->length()) {
					return checkDescriptor(version, descriptor, pos, false);
				} else {
					$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID_DESCRIPTOR, descriptor}));
				}
			}
		case u'L':
			{
				endPos = descriptor->indexOf((int32_t)u';', startPos);
				if (startPos == -1 || endPos - startPos < 2) {
					$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID_DESCRIPTOR, descriptor}));
				}
				try {
					checkInternalClassName(version, $(descriptor->substring(startPos + 1, endPos)), nullptr);
				} catch ($IllegalArgumentException& e) {
					$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID_DESCRIPTOR, descriptor}), e);
				}
				return endPos + 1;
			}
		default:
			{
				$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID_DESCRIPTOR, descriptor}));
			}
		}
	}
}

void CheckMethodAdapter::checkMethodDescriptor(int32_t version, $String* descriptor) {
	$init(CheckMethodAdapter);
	$useLocalCurrentObjectStackCache();
	if (descriptor == nullptr || $nc(descriptor)->length() == 0) {
		$throwNew($IllegalArgumentException, "Invalid method descriptor (must not be null or empty)"_s);
	}
	bool var$0 = $nc(descriptor)->charAt(0) != u'(';
	if (var$0 || $nc(descriptor)->length() < 3) {
		$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID_DESCRIPTOR, descriptor}));
	}
	int32_t pos = 1;
	if ($nc(descriptor)->charAt(pos) != u')') {
		bool var$1 = false;
		do {
			if (descriptor->charAt(pos) == u'V') {
				$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID_DESCRIPTOR, descriptor}));
			}
			pos = checkDescriptor(version, descriptor, pos, false);
			var$1 = pos < descriptor->length();
		} while (var$1 && descriptor->charAt(pos) != u')');
	}
	pos = checkDescriptor(version, descriptor, pos + 1, true);
	if (pos != $nc(descriptor)->length()) {
		$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID_DESCRIPTOR, descriptor}));
	}
}

void CheckMethodAdapter::checkLabel($Label* label, bool checkVisited, $String* message) {
	$useLocalCurrentObjectStackCache();
	if (label == nullptr) {
		$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID, message, " (must not be null)"_s}));
	}
	if (checkVisited && $nc(this->labelInsnIndices)->get(label) == nullptr) {
		$throwNew($IllegalArgumentException, $$str({CheckMethodAdapter::INVALID, message, " (must be visited first)"_s}));
	}
}

void clinit$CheckMethodAdapter($Class* class$) {
	$assignStatic(CheckMethodAdapter::INVALID, "Invalid "_s);
	$assignStatic(CheckMethodAdapter::INVALID_DESCRIPTOR, "Invalid descriptor: "_s);
	$assignStatic(CheckMethodAdapter::INVALID_TYPE_REFERENCE, "Invalid type reference sort 0x"_s);
	$assignStatic(CheckMethodAdapter::INVALID_LOCAL_VARIABLE_INDEX, "Invalid local variable index"_s);
	$assignStatic(CheckMethodAdapter::MUST_NOT_BE_NULL_OR_EMPTY, " (must not be null or empty)"_s);
	$assignStatic(CheckMethodAdapter::START_LABEL, "start label"_s);
	$assignStatic(CheckMethodAdapter::END_LABEL, "end label"_s);
	$init($CheckMethodAdapter$Method);
	$assignStatic(CheckMethodAdapter::OPCODE_METHODS, $new($CheckMethodAdapter$MethodArray, {
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INT_INSN,
		$CheckMethodAdapter$Method::VISIT_INT_INSN,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		$CheckMethodAdapter$Method::VISIT_VAR_INSN,
		$CheckMethodAdapter$Method::VISIT_VAR_INSN,
		$CheckMethodAdapter$Method::VISIT_VAR_INSN,
		$CheckMethodAdapter$Method::VISIT_VAR_INSN,
		$CheckMethodAdapter$Method::VISIT_VAR_INSN,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_VAR_INSN,
		$CheckMethodAdapter$Method::VISIT_VAR_INSN,
		$CheckMethodAdapter$Method::VISIT_VAR_INSN,
		$CheckMethodAdapter$Method::VISIT_VAR_INSN,
		$CheckMethodAdapter$Method::VISIT_VAR_INSN,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		($CheckMethodAdapter$Method*)nullptr,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_JUMP_INSN,
		$CheckMethodAdapter$Method::VISIT_JUMP_INSN,
		$CheckMethodAdapter$Method::VISIT_JUMP_INSN,
		$CheckMethodAdapter$Method::VISIT_JUMP_INSN,
		$CheckMethodAdapter$Method::VISIT_JUMP_INSN,
		$CheckMethodAdapter$Method::VISIT_JUMP_INSN,
		$CheckMethodAdapter$Method::VISIT_JUMP_INSN,
		$CheckMethodAdapter$Method::VISIT_JUMP_INSN,
		$CheckMethodAdapter$Method::VISIT_JUMP_INSN,
		$CheckMethodAdapter$Method::VISIT_JUMP_INSN,
		$CheckMethodAdapter$Method::VISIT_JUMP_INSN,
		$CheckMethodAdapter$Method::VISIT_JUMP_INSN,
		$CheckMethodAdapter$Method::VISIT_JUMP_INSN,
		$CheckMethodAdapter$Method::VISIT_JUMP_INSN,
		$CheckMethodAdapter$Method::VISIT_JUMP_INSN,
		$CheckMethodAdapter$Method::VISIT_JUMP_INSN,
		$CheckMethodAdapter$Method::VISIT_VAR_INSN,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_FIELD_INSN,
		$CheckMethodAdapter$Method::VISIT_FIELD_INSN,
		$CheckMethodAdapter$Method::VISIT_FIELD_INSN,
		$CheckMethodAdapter$Method::VISIT_FIELD_INSN,
		$CheckMethodAdapter$Method::VISIT_METHOD_INSN,
		$CheckMethodAdapter$Method::VISIT_METHOD_INSN,
		$CheckMethodAdapter$Method::VISIT_METHOD_INSN,
		$CheckMethodAdapter$Method::VISIT_METHOD_INSN,
		($CheckMethodAdapter$Method*)nullptr,
		$CheckMethodAdapter$Method::VISIT_TYPE_INSN,
		$CheckMethodAdapter$Method::VISIT_INT_INSN,
		$CheckMethodAdapter$Method::VISIT_TYPE_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_TYPE_INSN,
		$CheckMethodAdapter$Method::VISIT_TYPE_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		$CheckMethodAdapter$Method::VISIT_INSN,
		($CheckMethodAdapter$Method*)nullptr,
		($CheckMethodAdapter$Method*)nullptr,
		$CheckMethodAdapter$Method::VISIT_JUMP_INSN,
		$CheckMethodAdapter$Method::VISIT_JUMP_INSN
	}));
}

CheckMethodAdapter::CheckMethodAdapter() {
}

$Class* CheckMethodAdapter::load$($String* name, bool initialize) {
	$loadClass(CheckMethodAdapter, name, initialize, &_CheckMethodAdapter_ClassInfo_, clinit$CheckMethodAdapter, allocate$CheckMethodAdapter);
	return class$;
}

$Class* CheckMethodAdapter::class$ = nullptr;

					} // util
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk