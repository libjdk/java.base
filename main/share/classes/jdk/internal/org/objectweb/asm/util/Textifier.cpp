#include <jdk/internal/org/objectweb/asm/util/Textifier.h>

#include <java/io/OutputStream.h>
#include <java/io/PrintWriter.h>
#include <java/lang/IllegalStateException.h>
#include <java/util/Arrays.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <jdk/internal/org/objectweb/asm/Attribute.h>
#include <jdk/internal/org/objectweb/asm/Handle.h>
#include <jdk/internal/org/objectweb/asm/Label.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/Type.h>
#include <jdk/internal/org/objectweb/asm/TypePath.h>
#include <jdk/internal/org/objectweb/asm/TypeReference.h>
#include <jdk/internal/org/objectweb/asm/signature/SignatureReader.h>
#include <jdk/internal/org/objectweb/asm/signature/SignatureVisitor.h>
#include <jdk/internal/org/objectweb/asm/util/Printer.h>
#include <jdk/internal/org/objectweb/asm/util/TextifierSupport.h>
#include <jdk/internal/org/objectweb/asm/util/TraceSignatureVisitor.h>
#include <jcpp.h>

#undef ACC_ABSTRACT
#undef ACC_ANNOTATION
#undef ACC_BRIDGE
#undef ACC_DEPRECATED
#undef ACC_ENUM
#undef ACC_FINAL
#undef ACC_INTERFACE
#undef ACC_MANDATED
#undef ACC_MODULE
#undef ACC_NATIVE
#undef ACC_OPEN
#undef ACC_PRIVATE
#undef ACC_PROTECTED
#undef ACC_PUBLIC
#undef ACC_RECORD
#undef ACC_STATIC
#undef ACC_STATIC_PHASE
#undef ACC_STRICT
#undef ACC_SUPER
#undef ACC_SYNCHRONIZED
#undef ACC_SYNTHETIC
#undef ACC_TRANSIENT
#undef ACC_TRANSITIVE
#undef ACC_VARARGS
#undef ACC_VOLATILE
#undef ASM8
#undef CAST
#undef CLASS_EXTENDS
#undef CLASS_SIGNATURE
#undef CLASS_SUFFIX
#undef CLASS_TYPE_PARAMETER
#undef CLASS_TYPE_PARAMETER_BOUND
#undef CONSTRUCTOR_INVOCATION_TYPE_ARGUMENT
#undef CONSTRUCTOR_REFERENCE
#undef CONSTRUCTOR_REFERENCE_TYPE_ARGUMENT
#undef DEPRECATED
#undef EXCEPTION_PARAMETER
#undef FIELD
#undef FIELD_DESCRIPTOR
#undef FIELD_SIGNATURE
#undef FRAME_TYPES
#undef F_APPEND
#undef F_CHOP
#undef F_FULL
#undef F_NEW
#undef F_SAME
#undef F_SAME1
#undef HANDLE_DESCRIPTOR
#undef H_GETFIELD
#undef H_GETSTATIC
#undef H_INVOKEINTERFACE
#undef H_INVOKESPECIAL
#undef H_INVOKESTATIC
#undef H_INVOKEVIRTUAL
#undef H_NEWINVOKESPECIAL
#undef H_PUTFIELD
#undef H_PUTSTATIC
#undef INSTANCEOF
#undef INTERNAL_NAME
#undef INVISIBLE
#undef LOCAL_VARIABLE
#undef METHOD
#undef METHOD_DESCRIPTOR
#undef METHOD_FORMAL_PARAMETER
#undef METHOD_INVOCATION_TYPE_ARGUMENT
#undef METHOD_RECEIVER
#undef METHOD_REFERENCE
#undef METHOD_REFERENCE_TYPE_ARGUMENT
#undef METHOD_RETURN
#undef METHOD_SIGNATURE
#undef METHOD_TYPE_PARAMETER
#undef METHOD_TYPE_PARAMETER_BOUND
#undef NEW
#undef NEWARRAY
#undef OPCODES
#undef RECORD
#undef RESOURCE_VARIABLE
#undef THROWS
#undef TYPES
#undef USAGE

using $LabelArray = $Array<::jdk::internal::org::objectweb::asm$::Label>;
using $OutputStream = ::java::io::OutputStream;
using $PrintWriter = ::java::io::PrintWriter;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Short = ::java::lang::Short;
using $Arrays = ::java::util::Arrays;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Attribute = ::jdk::internal::org::objectweb::asm$::Attribute;
using $Handle = ::jdk::internal::org::objectweb::asm$::Handle;
using $Label = ::jdk::internal::org::objectweb::asm$::Label;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $Type = ::jdk::internal::org::objectweb::asm$::Type;
using $TypePath = ::jdk::internal::org::objectweb::asm$::TypePath;
using $TypeReference = ::jdk::internal::org::objectweb::asm$::TypeReference;
using $SignatureReader = ::jdk::internal::org::objectweb::asm$::signature::SignatureReader;
using $SignatureVisitor = ::jdk::internal::org::objectweb::asm$::signature::SignatureVisitor;
using $Printer = ::jdk::internal::org::objectweb::asm$::util::Printer;
using $TextifierSupport = ::jdk::internal::org::objectweb::asm$::util::TextifierSupport;
using $TraceSignatureVisitor = ::jdk::internal::org::objectweb::asm$::util::TraceSignatureVisitor;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace util {

$CompoundAttribute _Textifier_MethodAnnotations_visitPermittedSubclassExperimental78[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _Textifier_FieldInfo_[] = {
	{"USAGE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Textifier, USAGE)},
	{"INTERNAL_NAME", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Textifier, INTERNAL_NAME)},
	{"FIELD_DESCRIPTOR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Textifier, FIELD_DESCRIPTOR)},
	{"FIELD_SIGNATURE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Textifier, FIELD_SIGNATURE)},
	{"METHOD_DESCRIPTOR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Textifier, METHOD_DESCRIPTOR)},
	{"METHOD_SIGNATURE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Textifier, METHOD_SIGNATURE)},
	{"CLASS_SIGNATURE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Textifier, CLASS_SIGNATURE)},
	{"HANDLE_DESCRIPTOR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Textifier, HANDLE_DESCRIPTOR)},
	{"CLASS_SUFFIX", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Textifier, CLASS_SUFFIX)},
	{"DEPRECATED", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Textifier, DEPRECATED)},
	{"RECORD", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Textifier, RECORD)},
	{"INVISIBLE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Textifier, INVISIBLE)},
	{"FRAME_TYPES", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Textifier, FRAME_TYPES)},
	{"tab", "Ljava/lang/String;", nullptr, $PROTECTED, $field(Textifier, tab)},
	{"tab2", "Ljava/lang/String;", nullptr, $PROTECTED, $field(Textifier, tab2)},
	{"tab3", "Ljava/lang/String;", nullptr, $PROTECTED, $field(Textifier, tab3)},
	{"ltab", "Ljava/lang/String;", nullptr, $PROTECTED, $field(Textifier, ltab)},
	{"labelNames", "Ljava/util/Map;", "Ljava/util/Map<Ljdk/internal/org/objectweb/asm/Label;Ljava/lang/String;>;", $PROTECTED, $field(Textifier, labelNames)},
	{"access", "I", nullptr, $PRIVATE, $field(Textifier, access)},
	{"numAnnotationValues", "I", nullptr, $PRIVATE, $field(Textifier, numAnnotationValues)},
	{}
};

$MethodInfo _Textifier_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Textifier, init$, void)},
	{"<init>", "(I)V", nullptr, $PROTECTED, $method(Textifier, init$, void, int32_t)},
	{"addNewTextifier", "(Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/util/Textifier;", nullptr, $PRIVATE, $method(Textifier, addNewTextifier, Textifier*, $String*)},
	{"appendAccess", "(I)V", nullptr, $PRIVATE, $method(Textifier, appendAccess, void, int32_t)},
	{"appendDescriptor", "(ILjava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(Textifier, appendDescriptor, void, int32_t, $String*)},
	{"appendFrameTypes", "(I[Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(Textifier, appendFrameTypes, void, int32_t, $ObjectArray*)},
	{"appendHandle", "(Ljdk/internal/org/objectweb/asm/Handle;)V", nullptr, $PROTECTED, $virtualMethod(Textifier, appendHandle, void, $Handle*)},
	{"appendJavaDeclaration", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(Textifier, appendJavaDeclaration, void, $String*, $String*)},
	{"appendLabel", "(Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PROTECTED, $virtualMethod(Textifier, appendLabel, void, $Label*)},
	{"appendRawAccess", "(I)V", nullptr, $PRIVATE, $method(Textifier, appendRawAccess, void, int32_t)},
	{"appendTypeReference", "(I)V", nullptr, $PRIVATE, $method(Textifier, appendTypeReference, void, int32_t)},
	{"createTextifier", "()Ljdk/internal/org/objectweb/asm/util/Textifier;", nullptr, $PROTECTED, $virtualMethod(Textifier, createTextifier, Textifier*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Textifier, main, void, $StringArray*), "java.io.IOException"},
	{"main", "([Ljava/lang/String;Ljava/io/PrintWriter;Ljava/io/PrintWriter;)V", nullptr, $STATIC, $staticMethod(Textifier, main, void, $StringArray*, $PrintWriter*, $PrintWriter*), "java.io.IOException"},
	{"maybeAppendComma", "(I)V", nullptr, $PRIVATE, $method(Textifier, maybeAppendComma, void, int32_t)},
	{"visit", "(IILjava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visit, void, int32_t, int32_t, $String*, $String*, $String*, $StringArray*)},
	{"visit", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visit, void, $String*, Object$*)},
	{"visitAnnotableParameterCount", "(IZ)Ljdk/internal/org/objectweb/asm/util/Textifier;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitAnnotableParameterCount, Textifier*, int32_t, bool)},
	{"visitAnnotation", "(Ljava/lang/String;Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/util/Textifier;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitAnnotation, Textifier*, $String*, $String*)},
	{"visitAnnotation", "(Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Textifier;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitAnnotation, Textifier*, $String*, bool)},
	{"visitAnnotationDefault", "()Ljdk/internal/org/objectweb/asm/util/Textifier;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitAnnotationDefault, Textifier*)},
	{"visitAnnotationEnd", "()V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitAnnotationEnd, void)},
	{"visitAnnotationValue", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(Textifier, visitAnnotationValue, void, $String*)},
	{"visitArray", "(Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/util/Textifier;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitArray, Textifier*, $String*)},
	{"visitAttribute", "(Ljdk/internal/org/objectweb/asm/Attribute;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitAttribute, void, $Attribute*)},
	{"visitBoolean", "(Z)V", nullptr, $PRIVATE, $method(Textifier, visitBoolean, void, bool)},
	{"visitByte", "(B)V", nullptr, $PRIVATE, $method(Textifier, visitByte, void, int8_t)},
	{"visitChar", "(C)V", nullptr, $PRIVATE, $method(Textifier, visitChar, void, char16_t)},
	{"visitClassAnnotation", "(Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Textifier;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitClassAnnotation, Textifier*, $String*, bool)},
	{"visitClassAttribute", "(Ljdk/internal/org/objectweb/asm/Attribute;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitClassAttribute, void, $Attribute*)},
	{"visitClassEnd", "()V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitClassEnd, void)},
	{"visitClassTypeAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitClassTypeAnnotation, $Printer*, int32_t, $TypePath*, $String*, bool)},
	{"visitCode", "()V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitCode, void)},
	{"visitDouble", "(D)V", nullptr, $PRIVATE, $method(Textifier, visitDouble, void, double)},
	{"visitEnum", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitEnum, void, $String*, $String*, $String*)},
	{"visitExport", "(Ljava/lang/String;I[Ljava/lang/String;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(Textifier, visitExport, void, $String*, int32_t, $StringArray*)},
	{"visitExportOrOpen", "(Ljava/lang/String;Ljava/lang/String;I[Ljava/lang/String;)V", nullptr, $PRIVATE | $TRANSIENT, $method(Textifier, visitExportOrOpen, void, $String*, $String*, int32_t, $StringArray*)},
	{"visitField", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Object;)Ljdk/internal/org/objectweb/asm/util/Textifier;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitField, Textifier*, int32_t, $String*, $String*, $String*, Object$*)},
	{"visitFieldAnnotation", "(Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Textifier;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitFieldAnnotation, Textifier*, $String*, bool)},
	{"visitFieldAttribute", "(Ljdk/internal/org/objectweb/asm/Attribute;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitFieldAttribute, void, $Attribute*)},
	{"visitFieldEnd", "()V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitFieldEnd, void)},
	{"visitFieldInsn", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitFieldInsn, void, int32_t, $String*, $String*, $String*)},
	{"visitFieldTypeAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitFieldTypeAnnotation, $Printer*, int32_t, $TypePath*, $String*, bool)},
	{"visitFloat", "(F)V", nullptr, $PRIVATE, $method(Textifier, visitFloat, void, float)},
	{"visitFrame", "(II[Ljava/lang/Object;I[Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitFrame, void, int32_t, int32_t, $ObjectArray*, int32_t, $ObjectArray*)},
	{"visitIincInsn", "(II)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitIincInsn, void, int32_t, int32_t)},
	{"visitInnerClass", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitInnerClass, void, $String*, $String*, $String*, int32_t)},
	{"visitInsn", "(I)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitInsn, void, int32_t)},
	{"visitInsnAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitInsnAnnotation, $Printer*, int32_t, $TypePath*, $String*, bool)},
	{"visitInt", "(I)V", nullptr, $PRIVATE, $method(Textifier, visitInt, void, int32_t)},
	{"visitIntInsn", "(II)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitIntInsn, void, int32_t, int32_t)},
	{"visitInvokeDynamicInsn", "(Ljava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/Handle;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(Textifier, visitInvokeDynamicInsn, void, $String*, $String*, $Handle*, $ObjectArray*)},
	{"visitJumpInsn", "(ILjdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitJumpInsn, void, int32_t, $Label*)},
	{"visitLabel", "(Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitLabel, void, $Label*)},
	{"visitLdcInsn", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitLdcInsn, void, Object$*)},
	{"visitLineNumber", "(ILjdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitLineNumber, void, int32_t, $Label*)},
	{"visitLocalVariable", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/Label;Ljdk/internal/org/objectweb/asm/Label;I)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitLocalVariable, void, $String*, $String*, $String*, $Label*, $Label*, int32_t)},
	{"visitLocalVariableAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;[Ljdk/internal/org/objectweb/asm/Label;[Ljdk/internal/org/objectweb/asm/Label;[ILjava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitLocalVariableAnnotation, $Printer*, int32_t, $TypePath*, $LabelArray*, $LabelArray*, $ints*, $String*, bool)},
	{"visitLong", "(J)V", nullptr, $PRIVATE, $method(Textifier, visitLong, void, int64_t)},
	{"visitLookupSwitchInsn", "(Ljdk/internal/org/objectweb/asm/Label;[I[Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitLookupSwitchInsn, void, $Label*, $ints*, $LabelArray*)},
	{"visitMainClass", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitMainClass, void, $String*)},
	{"visitMaxs", "(II)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitMaxs, void, int32_t, int32_t)},
	{"visitMethod", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/util/Textifier;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitMethod, Textifier*, int32_t, $String*, $String*, $String*, $StringArray*)},
	{"visitMethodAnnotation", "(Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Textifier;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitMethodAnnotation, Textifier*, $String*, bool)},
	{"visitMethodAttribute", "(Ljdk/internal/org/objectweb/asm/Attribute;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitMethodAttribute, void, $Attribute*)},
	{"visitMethodEnd", "()V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitMethodEnd, void)},
	{"visitMethodInsn", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitMethodInsn, void, int32_t, $String*, $String*, $String*, bool)},
	{"visitMethodTypeAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitMethodTypeAnnotation, $Printer*, int32_t, $TypePath*, $String*, bool)},
	{"visitModule", "(Ljava/lang/String;ILjava/lang/String;)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitModule, $Printer*, $String*, int32_t, $String*)},
	{"visitModuleEnd", "()V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitModuleEnd, void)},
	{"visitMultiANewArrayInsn", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitMultiANewArrayInsn, void, $String*, int32_t)},
	{"visitNestHost", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitNestHost, void, $String*)},
	{"visitNestMember", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitNestMember, void, $String*)},
	{"visitOpen", "(Ljava/lang/String;I[Ljava/lang/String;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(Textifier, visitOpen, void, $String*, int32_t, $StringArray*)},
	{"visitOuterClass", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitOuterClass, void, $String*, $String*, $String*)},
	{"visitPackage", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitPackage, void, $String*)},
	{"visitParameter", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitParameter, void, $String*, int32_t)},
	{"visitParameterAnnotation", "(ILjava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Textifier;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitParameterAnnotation, Textifier*, int32_t, $String*, bool)},
	{"visitPermittedSubclassExperimental", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Textifier, visitPermittedSubclassExperimental, void, $String*), nullptr, nullptr, _Textifier_MethodAnnotations_visitPermittedSubclassExperimental78},
	{"visitProvide", "(Ljava/lang/String;[Ljava/lang/String;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(Textifier, visitProvide, void, $String*, $StringArray*)},
	{"visitRecordComponent", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitRecordComponent, $Printer*, $String*, $String*, $String*)},
	{"visitRecordComponentAnnotation", "(Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Textifier;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitRecordComponentAnnotation, Textifier*, $String*, bool)},
	{"visitRecordComponentAttribute", "(Ljdk/internal/org/objectweb/asm/Attribute;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitRecordComponentAttribute, void, $Attribute*)},
	{"visitRecordComponentEnd", "()V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitRecordComponentEnd, void)},
	{"visitRecordComponentTypeAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitRecordComponentTypeAnnotation, $Printer*, int32_t, $TypePath*, $String*, bool)},
	{"visitRequire", "(Ljava/lang/String;ILjava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitRequire, void, $String*, int32_t, $String*)},
	{"visitShort", "(S)V", nullptr, $PRIVATE, $method(Textifier, visitShort, void, int16_t)},
	{"visitSource", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitSource, void, $String*, $String*)},
	{"visitString", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(Textifier, visitString, void, $String*)},
	{"visitTableSwitchInsn", "(IILjdk/internal/org/objectweb/asm/Label;[Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(Textifier, visitTableSwitchInsn, void, int32_t, int32_t, $Label*, $LabelArray*)},
	{"visitTryCatchAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitTryCatchAnnotation, $Printer*, int32_t, $TypePath*, $String*, bool)},
	{"visitTryCatchBlock", "(Ljdk/internal/org/objectweb/asm/Label;Ljdk/internal/org/objectweb/asm/Label;Ljdk/internal/org/objectweb/asm/Label;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitTryCatchBlock, void, $Label*, $Label*, $Label*, $String*)},
	{"visitType", "(Ljdk/internal/org/objectweb/asm/Type;)V", nullptr, $PRIVATE, $method(Textifier, visitType, void, $Type*)},
	{"visitTypeAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Textifier;", nullptr, $PUBLIC, $virtualMethod(Textifier, visitTypeAnnotation, Textifier*, int32_t, $TypePath*, $String*, bool)},
	{"visitTypeInsn", "(ILjava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitTypeInsn, void, int32_t, $String*)},
	{"visitUse", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitUse, void, $String*)},
	{"visitVarInsn", "(II)V", nullptr, $PUBLIC, $virtualMethod(Textifier, visitVarInsn, void, int32_t, int32_t)},
	{}
};

$ClassInfo _Textifier_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.util.Textifier",
	"jdk.internal.org.objectweb.asm.util.Printer",
	nullptr,
	_Textifier_FieldInfo_,
	_Textifier_MethodInfo_
};

$Object* allocate$Textifier($Class* clazz) {
	return $of($alloc(Textifier));
}

$String* Textifier::USAGE = nullptr;
$String* Textifier::CLASS_SUFFIX = nullptr;
$String* Textifier::DEPRECATED = nullptr;
$String* Textifier::RECORD = nullptr;
$String* Textifier::INVISIBLE = nullptr;
$List* Textifier::FRAME_TYPES = nullptr;

void Textifier::init$() {
	Textifier::init$($Opcodes::ASM8);
	if ($of(this)->getClass() != Textifier::class$) {
		$throwNew($IllegalStateException);
	}
}

void Textifier::init$(int32_t api) {
	$Printer::init$(api);
	$set(this, tab, "  "_s);
	$set(this, tab2, "    "_s);
	$set(this, tab3, "      "_s);
	$set(this, ltab, "   "_s);
}

void Textifier::main($StringArray* args) {
	$init(Textifier);
	$useLocalCurrentObjectStackCache();
	$var($StringArray, var$0, args);
	$var($PrintWriter, var$1, $new($PrintWriter, static_cast<$OutputStream*>($System::out), true));
	main(var$0, var$1, $$new($PrintWriter, static_cast<$OutputStream*>($System::err), true));
}

void Textifier::main($StringArray* args, $PrintWriter* output, $PrintWriter* logger) {
	$init(Textifier);
	$Printer::main(args, Textifier::USAGE, $$new(Textifier), output, logger);
}

void Textifier::visit(int32_t version, int32_t access, $String* name, $String* signature, $String* superName, $StringArray* interfaces) {
	if (((int32_t)(access & (uint32_t)$Opcodes::ACC_MODULE)) != 0) {
		return;
	}
	this->access = access;
	int32_t majorVersion = (int32_t)(version & (uint32_t)0x0000FFFF);
	int32_t minorVersion = (int32_t)((uint32_t)version >> 16);
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("// class version "_s)->append(majorVersion)->append(u'.')->append(minorVersion)->append(" ("_s)->append(version)->append(")\n"_s);
	if (((int32_t)(access & (uint32_t)$Opcodes::ACC_DEPRECATED)) != 0) {
		$nc(this->stringBuilder)->append(Textifier::DEPRECATED);
	}
	if (((int32_t)(access & (uint32_t)$Opcodes::ACC_RECORD)) != 0) {
		$nc(this->stringBuilder)->append(Textifier::RECORD);
	}
	appendRawAccess(access);
	appendDescriptor(Textifier::CLASS_SIGNATURE, signature);
	if (signature != nullptr) {
		appendJavaDeclaration(name, signature);
	}
	appendAccess((int32_t)(access & (uint32_t)~($Opcodes::ACC_SUPER | $Opcodes::ACC_MODULE)));
	if (((int32_t)(access & (uint32_t)$Opcodes::ACC_ANNOTATION)) != 0) {
		$nc(this->stringBuilder)->append("@interface "_s);
	} else if (((int32_t)(access & (uint32_t)$Opcodes::ACC_INTERFACE)) != 0) {
		$nc(this->stringBuilder)->append("interface "_s);
	} else if (((int32_t)(access & (uint32_t)$Opcodes::ACC_ENUM)) == 0) {
		$nc(this->stringBuilder)->append("class "_s);
	}
	appendDescriptor(Textifier::INTERNAL_NAME, name);
	if (superName != nullptr && !"java/lang/Object"_s->equals(superName)) {
		$nc(this->stringBuilder)->append(" extends "_s);
		appendDescriptor(Textifier::INTERNAL_NAME, superName);
	}
	if (interfaces != nullptr && interfaces->length > 0) {
		$nc(this->stringBuilder)->append(" implements "_s);
		for (int32_t i = 0; i < interfaces->length; ++i) {
			appendDescriptor(Textifier::INTERNAL_NAME, interfaces->get(i));
			if (i != interfaces->length - 1) {
				$nc(this->stringBuilder)->append(u' ');
			}
		}
	}
	$nc(this->stringBuilder)->append(" {\n\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitSource($String* file, $String* debug) {
	$nc(this->stringBuilder)->setLength(0);
	if (file != nullptr) {
		$nc(this->stringBuilder)->append(this->tab)->append("// compiled from: "_s)->append(file)->append(u'\n');
	}
	if (debug != nullptr) {
		$nc(this->stringBuilder)->append(this->tab)->append("// debug info: "_s)->append(debug)->append(u'\n');
	}
	if ($nc(this->stringBuilder)->length() > 0) {
		$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	}
}

$Printer* Textifier::visitModule($String* name, int32_t access, $String* version) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	if (((int32_t)(access & (uint32_t)$Opcodes::ACC_OPEN)) != 0) {
		$nc(this->stringBuilder)->append("open "_s);
	}
	$nc(this->stringBuilder)->append("module "_s)->append(name)->append(" { "_s)->append(version == nullptr ? ""_s : $$str({"// "_s, version}))->append("\n\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	return addNewTextifier(nullptr);
}

void Textifier::visitNestHost($String* nestHost) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab)->append("NESTHOST "_s);
	appendDescriptor(Textifier::INTERNAL_NAME, nestHost);
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitOuterClass($String* owner, $String* name, $String* descriptor) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab)->append("OUTERCLASS "_s);
	appendDescriptor(Textifier::INTERNAL_NAME, owner);
	$nc(this->stringBuilder)->append(u' ');
	if (name != nullptr) {
		$nc(this->stringBuilder)->append(name)->append(u' ');
	}
	appendDescriptor(Textifier::METHOD_DESCRIPTOR, descriptor);
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

Textifier* Textifier::visitClassAnnotation($String* descriptor, bool visible) {
	$nc(this->text)->add("\n"_s);
	return visitAnnotation(descriptor, visible);
}

$Printer* Textifier::visitClassTypeAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	$nc(this->text)->add("\n"_s);
	return visitTypeAnnotation(typeRef, typePath, descriptor, visible);
}

void Textifier::visitClassAttribute($Attribute* attribute) {
	$nc(this->text)->add("\n"_s);
	visitAttribute(attribute);
}

void Textifier::visitNestMember($String* nestMember) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab)->append("NESTMEMBER "_s);
	appendDescriptor(Textifier::INTERNAL_NAME, nestMember);
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitPermittedSubclassExperimental($String* permittedSubclass) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab)->append("PERMITTEDSUBCLASS "_s);
	appendDescriptor(Textifier::INTERNAL_NAME, permittedSubclass);
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitInnerClass($String* name, $String* outerName, $String* innerName, int32_t access) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab);
	appendRawAccess((int32_t)(access & (uint32_t)~$Opcodes::ACC_SUPER));
	$nc(this->stringBuilder)->append(this->tab);
	appendAccess(access);
	$nc(this->stringBuilder)->append("INNERCLASS "_s);
	appendDescriptor(Textifier::INTERNAL_NAME, name);
	$nc(this->stringBuilder)->append(u' ');
	appendDescriptor(Textifier::INTERNAL_NAME, outerName);
	$nc(this->stringBuilder)->append(u' ');
	appendDescriptor(Textifier::INTERNAL_NAME, innerName);
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

$Printer* Textifier::visitRecordComponent($String* name, $String* descriptor, $String* signature) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab)->append("RECORDCOMPONENT "_s);
	if (signature != nullptr) {
		$nc(this->stringBuilder)->append(this->tab);
		appendDescriptor(Textifier::FIELD_SIGNATURE, signature);
		$nc(this->stringBuilder)->append(this->tab);
		appendJavaDeclaration(name, signature);
	}
	$nc(this->stringBuilder)->append(this->tab);
	appendDescriptor(Textifier::FIELD_DESCRIPTOR, descriptor);
	$nc(this->stringBuilder)->append(u' ')->append(name);
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	return addNewTextifier(nullptr);
}

Textifier* Textifier::visitField(int32_t access, $String* name, $String* descriptor, $String* signature, Object$* value) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(u'\n');
	if (((int32_t)(access & (uint32_t)$Opcodes::ACC_DEPRECATED)) != 0) {
		$nc(this->stringBuilder)->append(this->tab)->append(Textifier::DEPRECATED);
	}
	$nc(this->stringBuilder)->append(this->tab);
	appendRawAccess(access);
	if (signature != nullptr) {
		$nc(this->stringBuilder)->append(this->tab);
		appendDescriptor(Textifier::FIELD_SIGNATURE, signature);
		$nc(this->stringBuilder)->append(this->tab);
		appendJavaDeclaration(name, signature);
	}
	$nc(this->stringBuilder)->append(this->tab);
	appendAccess(access);
	appendDescriptor(Textifier::FIELD_DESCRIPTOR, descriptor);
	$nc(this->stringBuilder)->append(u' ')->append(name);
	if (value != nullptr) {
		$nc(this->stringBuilder)->append(" = "_s);
		if ($instanceOf($String, value)) {
			$nc(this->stringBuilder)->append(u'\"')->append(value)->append(u'\"');
		} else {
			$nc(this->stringBuilder)->append(value);
		}
	}
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	return addNewTextifier(nullptr);
}

Textifier* Textifier::visitMethod(int32_t access, $String* name, $String* descriptor, $String* signature, $StringArray* exceptions) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(u'\n');
	if (((int32_t)(access & (uint32_t)$Opcodes::ACC_DEPRECATED)) != 0) {
		$nc(this->stringBuilder)->append(this->tab)->append(Textifier::DEPRECATED);
	}
	$nc(this->stringBuilder)->append(this->tab);
	appendRawAccess(access);
	if (signature != nullptr) {
		$nc(this->stringBuilder)->append(this->tab);
		appendDescriptor(Textifier::METHOD_SIGNATURE, signature);
		$nc(this->stringBuilder)->append(this->tab);
		appendJavaDeclaration(name, signature);
	}
	$nc(this->stringBuilder)->append(this->tab);
	appendAccess((int32_t)(access & (uint32_t)~($Opcodes::ACC_VOLATILE | $Opcodes::ACC_TRANSIENT)));
	if (((int32_t)(access & (uint32_t)$Opcodes::ACC_NATIVE)) != 0) {
		$nc(this->stringBuilder)->append("native "_s);
	}
	if (((int32_t)(access & (uint32_t)$Opcodes::ACC_VARARGS)) != 0) {
		$nc(this->stringBuilder)->append("varargs "_s);
	}
	if (((int32_t)(access & (uint32_t)$Opcodes::ACC_BRIDGE)) != 0) {
		$nc(this->stringBuilder)->append("bridge "_s);
	}
	if (((int32_t)(this->access & (uint32_t)$Opcodes::ACC_INTERFACE)) != 0 && ((int32_t)(access & (uint32_t)($Opcodes::ACC_ABSTRACT | $Opcodes::ACC_STATIC))) == 0) {
		$nc(this->stringBuilder)->append("default "_s);
	}
	$nc(this->stringBuilder)->append(name);
	appendDescriptor(Textifier::METHOD_DESCRIPTOR, descriptor);
	if (exceptions != nullptr && exceptions->length > 0) {
		$nc(this->stringBuilder)->append(" throws "_s);
		{
			$var($StringArray, arr$, exceptions);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, exception, arr$->get(i$));
				{
					appendDescriptor(Textifier::INTERNAL_NAME, exception);
					$nc(this->stringBuilder)->append(u' ');
				}
			}
		}
	}
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	return addNewTextifier(nullptr);
}

void Textifier::visitClassEnd() {
	$nc(this->text)->add("}\n"_s);
}

void Textifier::visitMainClass($String* mainClass) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("  // main class "_s)->append(mainClass)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitPackage($String* packaze) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("  // package "_s)->append(packaze)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitRequire($String* require, int32_t access, $String* version) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab)->append("requires "_s);
	if (((int32_t)(access & (uint32_t)$Opcodes::ACC_TRANSITIVE)) != 0) {
		$nc(this->stringBuilder)->append("transitive "_s);
	}
	if (((int32_t)(access & (uint32_t)$Opcodes::ACC_STATIC_PHASE)) != 0) {
		$nc(this->stringBuilder)->append("static "_s);
	}
	$nc(this->stringBuilder)->append(require)->append(u';');
	appendRawAccess(access);
	if (version != nullptr) {
		$nc(this->stringBuilder)->append("  // version "_s)->append(version)->append(u'\n');
	}
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitExport($String* packaze, int32_t access, $StringArray* modules) {
	visitExportOrOpen("exports "_s, packaze, access, modules);
}

void Textifier::visitOpen($String* packaze, int32_t access, $StringArray* modules) {
	visitExportOrOpen("opens "_s, packaze, access, modules);
}

void Textifier::visitExportOrOpen($String* method, $String* packaze, int32_t access, $StringArray* modules) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab)->append(method);
	$nc(this->stringBuilder)->append(packaze);
	if (modules != nullptr && modules->length > 0) {
		$nc(this->stringBuilder)->append(" to"_s);
	} else {
		$nc(this->stringBuilder)->append(u';');
	}
	appendRawAccess(access);
	if (modules != nullptr && modules->length > 0) {
		for (int32_t i = 0; i < modules->length; ++i) {
			$nc(this->stringBuilder)->append(this->tab2)->append(modules->get(i));
			$nc(this->stringBuilder)->append(i != modules->length - 1 ? ",\n"_s : ";\n"_s);
		}
	}
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitUse($String* use) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab)->append("uses "_s);
	appendDescriptor(Textifier::INTERNAL_NAME, use);
	$nc(this->stringBuilder)->append(";\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitProvide($String* provide, $StringArray* providers) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab)->append("provides "_s);
	appendDescriptor(Textifier::INTERNAL_NAME, provide);
	$nc(this->stringBuilder)->append(" with\n"_s);
	for (int32_t i = 0; i < $nc(providers)->length; ++i) {
		$nc(this->stringBuilder)->append(this->tab2);
		appendDescriptor(Textifier::INTERNAL_NAME, providers->get(i));
		$nc(this->stringBuilder)->append(i != providers->length - 1 ? ",\n"_s : ";\n"_s);
	}
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitModuleEnd() {
}

void Textifier::visit($String* name, Object$* value) {
	$useLocalCurrentObjectStackCache();
	visitAnnotationValue(name);
	if ($instanceOf($String, value)) {
		visitString($cast($String, value));
	} else if ($instanceOf($Type, value)) {
		visitType($cast($Type, value));
	} else if ($instanceOf($Byte, value)) {
		visitByte($nc(($cast($Byte, value)))->byteValue());
	} else if ($instanceOf($Boolean, value)) {
		visitBoolean($nc(($cast($Boolean, value)))->booleanValue());
	} else if ($instanceOf($Short, value)) {
		visitShort($nc(($cast($Short, value)))->shortValue());
	} else if ($instanceOf($Character, value)) {
		visitChar($nc(($cast($Character, value)))->charValue());
	} else if ($instanceOf($Integer, value)) {
		visitInt($nc(($cast($Integer, value)))->intValue());
	} else if ($instanceOf($Float, value)) {
		visitFloat($nc(($cast($Float, value)))->floatValue());
	} else if ($instanceOf($Long, value)) {
		visitLong($nc(($cast($Long, value)))->longValue());
	} else if ($instanceOf($Double, value)) {
		visitDouble($nc(($cast($Double, value)))->doubleValue());
	} else if ($nc($of(value))->getClass()->isArray()) {
		$nc(this->stringBuilder)->append(u'{');
		if ($instanceOf($bytes, value)) {
			$var($bytes, byteArray, $cast($bytes, value));
			for (int32_t i = 0; i < byteArray->length; ++i) {
				maybeAppendComma(i);
				visitByte(byteArray->get(i));
			}
		} else if ($instanceOf($booleans, value)) {
			$var($booleans, booleanArray, $cast($booleans, value));
			for (int32_t i = 0; i < booleanArray->length; ++i) {
				maybeAppendComma(i);
				visitBoolean(booleanArray->get(i));
			}
		} else if ($instanceOf($shorts, value)) {
			$var($shorts, shortArray, $cast($shorts, value));
			for (int32_t i = 0; i < shortArray->length; ++i) {
				maybeAppendComma(i);
				visitShort(shortArray->get(i));
			}
		} else if ($instanceOf($chars, value)) {
			$var($chars, charArray, $cast($chars, value));
			for (int32_t i = 0; i < charArray->length; ++i) {
				maybeAppendComma(i);
				visitChar(charArray->get(i));
			}
		} else if ($instanceOf($ints, value)) {
			$var($ints, intArray, $cast($ints, value));
			for (int32_t i = 0; i < intArray->length; ++i) {
				maybeAppendComma(i);
				visitInt(intArray->get(i));
			}
		} else if ($instanceOf($longs, value)) {
			$var($longs, longArray, $cast($longs, value));
			for (int32_t i = 0; i < longArray->length; ++i) {
				maybeAppendComma(i);
				visitLong(longArray->get(i));
			}
		} else if ($instanceOf($floats, value)) {
			$var($floats, floatArray, $cast($floats, value));
			for (int32_t i = 0; i < floatArray->length; ++i) {
				maybeAppendComma(i);
				visitFloat(floatArray->get(i));
			}
		} else if ($instanceOf($doubles, value)) {
			$var($doubles, doubleArray, $cast($doubles, value));
			for (int32_t i = 0; i < doubleArray->length; ++i) {
				maybeAppendComma(i);
				visitDouble(doubleArray->get(i));
			}
		}
		$nc(this->stringBuilder)->append(u'}');
	}
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitInt(int32_t value) {
	$nc(this->stringBuilder)->append(value);
}

void Textifier::visitLong(int64_t value) {
	$nc(this->stringBuilder)->append(value)->append(u'L');
}

void Textifier::visitFloat(float value) {
	$nc(this->stringBuilder)->append(value)->append(u'F');
}

void Textifier::visitDouble(double value) {
	$nc(this->stringBuilder)->append(value)->append(u'D');
}

void Textifier::visitChar(char16_t value) {
	$nc(this->stringBuilder)->append("(char)"_s)->append((int32_t)value);
}

void Textifier::visitShort(int16_t value) {
	$nc(this->stringBuilder)->append("(short)"_s)->append((int32_t)value);
}

void Textifier::visitByte(int8_t value) {
	$nc(this->stringBuilder)->append("(byte)"_s)->append((int32_t)value);
}

void Textifier::visitBoolean(bool value) {
	$nc(this->stringBuilder)->append(value);
}

void Textifier::visitString($String* value) {
	appendString(this->stringBuilder, value);
}

void Textifier::visitType($Type* value) {
	$nc(this->stringBuilder)->append($($nc(value)->getClassName()))->append(Textifier::CLASS_SUFFIX);
}

void Textifier::visitEnum($String* name, $String* descriptor, $String* value) {
	visitAnnotationValue(name);
	appendDescriptor(Textifier::FIELD_DESCRIPTOR, descriptor);
	$nc(this->stringBuilder)->append(u'.')->append(value);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

Textifier* Textifier::visitAnnotation($String* name, $String* descriptor) {
	visitAnnotationValue(name);
	$nc(this->stringBuilder)->append(u'@');
	appendDescriptor(Textifier::FIELD_DESCRIPTOR, descriptor);
	$nc(this->stringBuilder)->append(u'(');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	return addNewTextifier(")"_s);
}

Textifier* Textifier::visitArray($String* name) {
	visitAnnotationValue(name);
	$nc(this->stringBuilder)->append(u'{');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	return addNewTextifier("}"_s);
}

void Textifier::visitAnnotationEnd() {
}

void Textifier::visitAnnotationValue($String* name) {
	$nc(this->stringBuilder)->setLength(0);
	maybeAppendComma(this->numAnnotationValues++);
	if (name != nullptr) {
		$nc(this->stringBuilder)->append(name)->append(u'=');
	}
}

Textifier* Textifier::visitRecordComponentAnnotation($String* descriptor, bool visible) {
	return visitAnnotation(descriptor, visible);
}

$Printer* Textifier::visitRecordComponentTypeAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	return visitTypeAnnotation(typeRef, typePath, descriptor, visible);
}

void Textifier::visitRecordComponentAttribute($Attribute* attribute) {
	visitAttribute(attribute);
}

void Textifier::visitRecordComponentEnd() {
}

Textifier* Textifier::visitFieldAnnotation($String* descriptor, bool visible) {
	return visitAnnotation(descriptor, visible);
}

$Printer* Textifier::visitFieldTypeAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	return visitTypeAnnotation(typeRef, typePath, descriptor, visible);
}

void Textifier::visitFieldAttribute($Attribute* attribute) {
	visitAttribute(attribute);
}

void Textifier::visitFieldEnd() {
}

void Textifier::visitParameter($String* name, int32_t access) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab2)->append("// parameter "_s);
	appendAccess(access);
	$nc(this->stringBuilder)->append(u' ')->append((name == nullptr) ? "<no name>"_s : name)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

Textifier* Textifier::visitAnnotationDefault() {
	$nc(this->text)->add($$str({this->tab2, "default="_s}));
	return addNewTextifier("\n"_s);
}

Textifier* Textifier::visitMethodAnnotation($String* descriptor, bool visible) {
	return visitAnnotation(descriptor, visible);
}

$Printer* Textifier::visitMethodTypeAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	return visitTypeAnnotation(typeRef, typePath, descriptor, visible);
}

Textifier* Textifier::visitAnnotableParameterCount(int32_t parameterCount, bool visible) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab2)->append("// annotable parameter count: "_s);
	$nc(this->stringBuilder)->append(parameterCount);
	$nc(this->stringBuilder)->append(visible ? " (visible)\n"_s : " (invisible)\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	return this;
}

Textifier* Textifier::visitParameterAnnotation(int32_t parameter, $String* descriptor, bool visible) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab2)->append(u'@');
	appendDescriptor(Textifier::FIELD_DESCRIPTOR, descriptor);
	$nc(this->stringBuilder)->append(u'(');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(visible ? ") // parameter "_s : ") // invisible, parameter "_s)->append(parameter)->append(u'\n');
	return addNewTextifier($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitMethodAttribute($Attribute* attribute) {
	visitAttribute(attribute);
}

void Textifier::visitCode() {
}

void Textifier::visitFrame(int32_t type, int32_t numLocal, $ObjectArray* local, int32_t numStack, $ObjectArray* stack) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->ltab);
	$nc(this->stringBuilder)->append("FRAME "_s);
	switch (type) {
	case $Opcodes::F_NEW:
		{}
	case $Opcodes::F_FULL:
		{
			$nc(this->stringBuilder)->append("FULL ["_s);
			appendFrameTypes(numLocal, local);
			$nc(this->stringBuilder)->append("] ["_s);
			appendFrameTypes(numStack, stack);
			$nc(this->stringBuilder)->append(u']');
			break;
		}
	case $Opcodes::F_APPEND:
		{
			$nc(this->stringBuilder)->append("APPEND ["_s);
			appendFrameTypes(numLocal, local);
			$nc(this->stringBuilder)->append(u']');
			break;
		}
	case $Opcodes::F_CHOP:
		{
			$nc(this->stringBuilder)->append("CHOP "_s)->append(numLocal);
			break;
		}
	case $Opcodes::F_SAME:
		{
			$nc(this->stringBuilder)->append("SAME"_s);
			break;
		}
	case $Opcodes::F_SAME1:
		{
			$nc(this->stringBuilder)->append("SAME1 "_s);
			appendFrameTypes(1, stack);
			break;
		}
	default:
		{
			$throwNew($IllegalArgumentException);
		}
	}
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitInsn(int32_t opcode) {
	$nc(this->stringBuilder)->setLength(0);
	$init($Printer);
	$nc(this->stringBuilder)->append(this->tab2)->append($nc($Printer::OPCODES)->get(opcode))->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitIntInsn(int32_t opcode, int32_t operand) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$init($Printer);
	$nc(this->stringBuilder)->append(this->tab2)->append($nc($Printer::OPCODES)->get(opcode))->append(u' ')->append(opcode == $Opcodes::NEWARRAY ? $nc($Printer::TYPES)->get(operand) : $($Integer::toString(operand)))->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitVarInsn(int32_t opcode, int32_t var) {
	$nc(this->stringBuilder)->setLength(0);
	$init($Printer);
	$nc(this->stringBuilder)->append(this->tab2)->append($nc($Printer::OPCODES)->get(opcode))->append(u' ')->append(var)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitTypeInsn(int32_t opcode, $String* type) {
	$nc(this->stringBuilder)->setLength(0);
	$init($Printer);
	$nc(this->stringBuilder)->append(this->tab2)->append($nc($Printer::OPCODES)->get(opcode))->append(u' ');
	appendDescriptor(Textifier::INTERNAL_NAME, type);
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitFieldInsn(int32_t opcode, $String* owner, $String* name, $String* descriptor) {
	$nc(this->stringBuilder)->setLength(0);
	$init($Printer);
	$nc(this->stringBuilder)->append(this->tab2)->append($nc($Printer::OPCODES)->get(opcode))->append(u' ');
	appendDescriptor(Textifier::INTERNAL_NAME, owner);
	$nc(this->stringBuilder)->append(u'.')->append(name)->append(" : "_s);
	appendDescriptor(Textifier::FIELD_DESCRIPTOR, descriptor);
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitMethodInsn(int32_t opcode, $String* owner, $String* name, $String* descriptor, bool isInterface) {
	$nc(this->stringBuilder)->setLength(0);
	$init($Printer);
	$nc(this->stringBuilder)->append(this->tab2)->append($nc($Printer::OPCODES)->get(opcode))->append(u' ');
	appendDescriptor(Textifier::INTERNAL_NAME, owner);
	$nc(this->stringBuilder)->append(u'.')->append(name)->append(u' ');
	appendDescriptor(Textifier::METHOD_DESCRIPTOR, descriptor);
	if (isInterface) {
		$nc(this->stringBuilder)->append(" (itf)"_s);
	}
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitInvokeDynamicInsn($String* name, $String* descriptor, $Handle* bootstrapMethodHandle, $ObjectArray* bootstrapMethodArguments) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab2)->append("INVOKEDYNAMIC"_s)->append(u' ');
	$nc(this->stringBuilder)->append(name);
	appendDescriptor(Textifier::METHOD_DESCRIPTOR, descriptor);
	$nc(this->stringBuilder)->append(" ["_s);
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->stringBuilder)->append(this->tab3);
	appendHandle(bootstrapMethodHandle);
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->stringBuilder)->append(this->tab3)->append("// arguments:"_s);
	if ($nc(bootstrapMethodArguments)->length == 0) {
		$nc(this->stringBuilder)->append(" none"_s);
	} else {
		$nc(this->stringBuilder)->append(u'\n');
		{
			$var($ObjectArray, arr$, bootstrapMethodArguments);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Object0, value, arr$->get(i$));
				{
					$nc(this->stringBuilder)->append(this->tab3);
					if ($instanceOf($String, value)) {
						$Printer::appendString(this->stringBuilder, $cast($String, value));
					} else if ($instanceOf($Type, value)) {
						$var($Type, type, $cast($Type, value));
						if ($nc(type)->getSort() == $Type::METHOD) {
							appendDescriptor(Textifier::METHOD_DESCRIPTOR, $(type->getDescriptor()));
						} else {
							visitType(type);
						}
					} else if ($instanceOf($Handle, value)) {
						appendHandle($cast($Handle, value));
					} else {
						$nc(this->stringBuilder)->append(value);
					}
					$nc(this->stringBuilder)->append(", \n"_s);
				}
			}
		}
		$nc(this->stringBuilder)->setLength($nc(this->stringBuilder)->length() - 3);
	}
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->stringBuilder)->append(this->tab2)->append("]\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitJumpInsn(int32_t opcode, $Label* label) {
	$nc(this->stringBuilder)->setLength(0);
	$init($Printer);
	$nc(this->stringBuilder)->append(this->tab2)->append($nc($Printer::OPCODES)->get(opcode))->append(u' ');
	appendLabel(label);
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitLabel($Label* label) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->ltab);
	appendLabel(label);
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitLdcInsn(Object$* value) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab2)->append("LDC "_s);
	if ($instanceOf($String, value)) {
		$Printer::appendString(this->stringBuilder, $cast($String, value));
	} else if ($instanceOf($Type, value)) {
		$nc(this->stringBuilder)->append($($nc(($cast($Type, value)))->getDescriptor()))->append(Textifier::CLASS_SUFFIX);
	} else {
		$nc(this->stringBuilder)->append(value);
	}
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitIincInsn(int32_t var, int32_t increment) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab2)->append("IINC "_s)->append(var)->append(u' ')->append(increment)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitTableSwitchInsn(int32_t min, int32_t max, $Label* dflt, $LabelArray* labels) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab2)->append("TABLESWITCH\n"_s);
	for (int32_t i = 0; i < $nc(labels)->length; ++i) {
		$nc(this->stringBuilder)->append(this->tab3)->append(min + i)->append(": "_s);
		appendLabel(labels->get(i));
		$nc(this->stringBuilder)->append(u'\n');
	}
	$nc(this->stringBuilder)->append(this->tab3)->append("default: "_s);
	appendLabel(dflt);
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitLookupSwitchInsn($Label* dflt, $ints* keys, $LabelArray* labels) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab2)->append("LOOKUPSWITCH\n"_s);
	for (int32_t i = 0; i < $nc(labels)->length; ++i) {
		$nc(this->stringBuilder)->append(this->tab3)->append($nc(keys)->get(i))->append(": "_s);
		appendLabel(labels->get(i));
		$nc(this->stringBuilder)->append(u'\n');
	}
	$nc(this->stringBuilder)->append(this->tab3)->append("default: "_s);
	appendLabel(dflt);
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitMultiANewArrayInsn($String* descriptor, int32_t numDimensions) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab2)->append("MULTIANEWARRAY "_s);
	appendDescriptor(Textifier::FIELD_DESCRIPTOR, descriptor);
	$nc(this->stringBuilder)->append(u' ')->append(numDimensions)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

$Printer* Textifier::visitInsnAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	return visitTypeAnnotation(typeRef, typePath, descriptor, visible);
}

void Textifier::visitTryCatchBlock($Label* start, $Label* end, $Label* handler, $String* type) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab2)->append("TRYCATCHBLOCK "_s);
	appendLabel(start);
	$nc(this->stringBuilder)->append(u' ');
	appendLabel(end);
	$nc(this->stringBuilder)->append(u' ');
	appendLabel(handler);
	$nc(this->stringBuilder)->append(u' ');
	appendDescriptor(Textifier::INTERNAL_NAME, type);
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

$Printer* Textifier::visitTryCatchAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab2)->append("TRYCATCHBLOCK @"_s);
	appendDescriptor(Textifier::FIELD_DESCRIPTOR, descriptor);
	$nc(this->stringBuilder)->append(u'(');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(") : "_s);
	appendTypeReference(typeRef);
	$nc(this->stringBuilder)->append(", "_s)->append($of(typePath));
	$nc(this->stringBuilder)->append(visible ? "\n"_s : Textifier::INVISIBLE);
	return addNewTextifier($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitLocalVariable($String* name, $String* descriptor, $String* signature, $Label* start, $Label* end, int32_t index) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab2)->append("LOCALVARIABLE "_s)->append(name)->append(u' ');
	appendDescriptor(Textifier::FIELD_DESCRIPTOR, descriptor);
	$nc(this->stringBuilder)->append(u' ');
	appendLabel(start);
	$nc(this->stringBuilder)->append(u' ');
	appendLabel(end);
	$nc(this->stringBuilder)->append(u' ')->append(index)->append(u'\n');
	if (signature != nullptr) {
		$nc(this->stringBuilder)->append(this->tab2);
		appendDescriptor(Textifier::FIELD_SIGNATURE, signature);
		$nc(this->stringBuilder)->append(this->tab2);
		appendJavaDeclaration(name, signature);
	}
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

$Printer* Textifier::visitLocalVariableAnnotation(int32_t typeRef, $TypePath* typePath, $LabelArray* start, $LabelArray* end, $ints* index, $String* descriptor, bool visible) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab2)->append("LOCALVARIABLE @"_s);
	appendDescriptor(Textifier::FIELD_DESCRIPTOR, descriptor);
	$nc(this->stringBuilder)->append(u'(');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(") : "_s);
	appendTypeReference(typeRef);
	$nc(this->stringBuilder)->append(", "_s)->append($of(typePath));
	for (int32_t i = 0; i < $nc(start)->length; ++i) {
		$nc(this->stringBuilder)->append(" [ "_s);
		appendLabel(start->get(i));
		$nc(this->stringBuilder)->append(" - "_s);
		appendLabel($nc(end)->get(i));
		$nc(this->stringBuilder)->append(" - "_s)->append($nc(index)->get(i))->append(" ]"_s);
	}
	$nc(this->stringBuilder)->append(visible ? "\n"_s : Textifier::INVISIBLE);
	return addNewTextifier($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitLineNumber(int32_t line, $Label* start) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab2)->append("LINENUMBER "_s)->append(line)->append(u' ');
	appendLabel(start);
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitMaxs(int32_t maxStack, int32_t maxLocals) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab2)->append("MAXSTACK = "_s)->append(maxStack)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab2)->append("MAXLOCALS = "_s)->append(maxLocals)->append(u'\n');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitMethodEnd() {
}

Textifier* Textifier::visitAnnotation($String* descriptor, bool visible) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab)->append(u'@');
	appendDescriptor(Textifier::FIELD_DESCRIPTOR, descriptor);
	$nc(this->stringBuilder)->append(u'(');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	return addNewTextifier(visible ? ")\n"_s : ") // invisible\n"_s);
}

Textifier* Textifier::visitTypeAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab)->append(u'@');
	appendDescriptor(Textifier::FIELD_DESCRIPTOR, descriptor);
	$nc(this->stringBuilder)->append(u'(');
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(") : "_s);
	appendTypeReference(typeRef);
	$nc(this->stringBuilder)->append(", "_s)->append($of(typePath));
	$nc(this->stringBuilder)->append(visible ? "\n"_s : Textifier::INVISIBLE);
	return addNewTextifier($($nc(this->stringBuilder)->toString()));
}

void Textifier::visitAttribute($Attribute* attribute) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->tab)->append("ATTRIBUTE "_s);
	appendDescriptor(-1, $nc(attribute)->type);
	if ($instanceOf($TextifierSupport, attribute)) {
		if (this->labelNames == nullptr) {
			$set(this, labelNames, $new($HashMap));
		}
		$nc(($cast($TextifierSupport, attribute)))->textify(this->stringBuilder, this->labelNames);
	} else {
		$nc(this->stringBuilder)->append(" : unknown\n"_s);
	}
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void Textifier::appendAccess(int32_t accessFlags) {
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_PUBLIC)) != 0) {
		$nc(this->stringBuilder)->append("public "_s);
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_PRIVATE)) != 0) {
		$nc(this->stringBuilder)->append("private "_s);
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_PROTECTED)) != 0) {
		$nc(this->stringBuilder)->append("protected "_s);
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_FINAL)) != 0) {
		$nc(this->stringBuilder)->append("final "_s);
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_STATIC)) != 0) {
		$nc(this->stringBuilder)->append("static "_s);
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_SYNCHRONIZED)) != 0) {
		$nc(this->stringBuilder)->append("synchronized "_s);
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_VOLATILE)) != 0) {
		$nc(this->stringBuilder)->append("volatile "_s);
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_TRANSIENT)) != 0) {
		$nc(this->stringBuilder)->append("transient "_s);
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_ABSTRACT)) != 0) {
		$nc(this->stringBuilder)->append("abstract "_s);
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_STRICT)) != 0) {
		$nc(this->stringBuilder)->append("strictfp "_s);
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_SYNTHETIC)) != 0) {
		$nc(this->stringBuilder)->append("synthetic "_s);
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_MANDATED)) != 0) {
		$nc(this->stringBuilder)->append("mandated "_s);
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_ENUM)) != 0) {
		$nc(this->stringBuilder)->append("enum "_s);
	}
}

void Textifier::appendRawAccess(int32_t accessFlags) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->append("// access flags 0x"_s)->append($($nc($($Integer::toHexString(accessFlags)))->toUpperCase()))->append(u'\n');
}

void Textifier::appendDescriptor(int32_t type, $String* value) {
	if (type == Textifier::CLASS_SIGNATURE || type == Textifier::FIELD_SIGNATURE || type == Textifier::METHOD_SIGNATURE) {
		if (value != nullptr) {
			$nc(this->stringBuilder)->append("// signature "_s)->append(value)->append(u'\n');
		}
	} else {
		$nc(this->stringBuilder)->append(value);
	}
}

void Textifier::appendJavaDeclaration($String* name, $String* signature) {
	$useLocalCurrentObjectStackCache();
	$var($TraceSignatureVisitor, traceSignatureVisitor, $new($TraceSignatureVisitor, this->access));
	$$new($SignatureReader, signature)->accept(traceSignatureVisitor);
	$nc(this->stringBuilder)->append("// declaration: "_s);
	if (traceSignatureVisitor->getReturnType() != nullptr) {
		$nc(this->stringBuilder)->append($(traceSignatureVisitor->getReturnType()));
		$nc(this->stringBuilder)->append(u' ');
	}
	$nc(this->stringBuilder)->append(name);
	$nc(this->stringBuilder)->append($(traceSignatureVisitor->getDeclaration()));
	if (traceSignatureVisitor->getExceptions() != nullptr) {
		$nc(this->stringBuilder)->append(" throws "_s)->append($(traceSignatureVisitor->getExceptions()));
	}
	$nc(this->stringBuilder)->append(u'\n');
}

void Textifier::appendLabel($Label* label) {
	$useLocalCurrentObjectStackCache();
	if (this->labelNames == nullptr) {
		$set(this, labelNames, $new($HashMap));
	}
	$var($String, name, $cast($String, $nc(this->labelNames)->get(label)));
	if (name == nullptr) {
		$assign(name, $str({"L"_s, $$str($nc(this->labelNames)->size())}));
		$nc(this->labelNames)->put(label, name);
	}
	$nc(this->stringBuilder)->append(name);
}

void Textifier::appendHandle($Handle* handle) {
	$useLocalCurrentObjectStackCache();
	int32_t tag = $nc(handle)->getTag();
	$nc(this->stringBuilder)->append("// handle kind 0x"_s)->append($($Integer::toHexString(tag)))->append(" : "_s);
	bool isMethodHandle = false;
	switch (tag) {
	case $Opcodes::H_GETFIELD:
		{
			$nc(this->stringBuilder)->append("GETFIELD"_s);
			break;
		}
	case $Opcodes::H_GETSTATIC:
		{
			$nc(this->stringBuilder)->append("GETSTATIC"_s);
			break;
		}
	case $Opcodes::H_PUTFIELD:
		{
			$nc(this->stringBuilder)->append("PUTFIELD"_s);
			break;
		}
	case $Opcodes::H_PUTSTATIC:
		{
			$nc(this->stringBuilder)->append("PUTSTATIC"_s);
			break;
		}
	case $Opcodes::H_INVOKEINTERFACE:
		{
			$nc(this->stringBuilder)->append("INVOKEINTERFACE"_s);
			isMethodHandle = true;
			break;
		}
	case $Opcodes::H_INVOKESPECIAL:
		{
			$nc(this->stringBuilder)->append("INVOKESPECIAL"_s);
			isMethodHandle = true;
			break;
		}
	case $Opcodes::H_INVOKESTATIC:
		{
			$nc(this->stringBuilder)->append("INVOKESTATIC"_s);
			isMethodHandle = true;
			break;
		}
	case $Opcodes::H_INVOKEVIRTUAL:
		{
			$nc(this->stringBuilder)->append("INVOKEVIRTUAL"_s);
			isMethodHandle = true;
			break;
		}
	case $Opcodes::H_NEWINVOKESPECIAL:
		{
			$nc(this->stringBuilder)->append("NEWINVOKESPECIAL"_s);
			isMethodHandle = true;
			break;
		}
	default:
		{
			$throwNew($IllegalArgumentException);
		}
	}
	$nc(this->stringBuilder)->append(u'\n');
	$nc(this->stringBuilder)->append(this->tab3);
	appendDescriptor(Textifier::INTERNAL_NAME, $(handle->getOwner()));
	$nc(this->stringBuilder)->append(u'.');
	$nc(this->stringBuilder)->append($(handle->getName()));
	if (!isMethodHandle) {
		$nc(this->stringBuilder)->append(u'(');
	}
	appendDescriptor(Textifier::HANDLE_DESCRIPTOR, $(handle->getDesc()));
	if (!isMethodHandle) {
		$nc(this->stringBuilder)->append(u')');
	}
	if (handle->isInterface()) {
		$nc(this->stringBuilder)->append(" itf"_s);
	}
}

void Textifier::maybeAppendComma(int32_t numValues) {
	if (numValues > 0) {
		$nc(this->stringBuilder)->append(", "_s);
	}
}

void Textifier::appendTypeReference(int32_t typeRef) {
	$var($TypeReference, typeReference, $new($TypeReference, typeRef));
	switch (typeReference->getSort()) {
	case $TypeReference::CLASS_TYPE_PARAMETER:
		{
			$nc(this->stringBuilder)->append("CLASS_TYPE_PARAMETER "_s)->append(typeReference->getTypeParameterIndex());
			break;
		}
	case $TypeReference::METHOD_TYPE_PARAMETER:
		{
			$nc(this->stringBuilder)->append("METHOD_TYPE_PARAMETER "_s)->append(typeReference->getTypeParameterIndex());
			break;
		}
	case $TypeReference::CLASS_EXTENDS:
		{
			$nc(this->stringBuilder)->append("CLASS_EXTENDS "_s)->append(typeReference->getSuperTypeIndex());
			break;
		}
	case $TypeReference::CLASS_TYPE_PARAMETER_BOUND:
		{
			$nc(this->stringBuilder)->append("CLASS_TYPE_PARAMETER_BOUND "_s)->append(typeReference->getTypeParameterIndex())->append(", "_s)->append(typeReference->getTypeParameterBoundIndex());
			break;
		}
	case $TypeReference::METHOD_TYPE_PARAMETER_BOUND:
		{
			$nc(this->stringBuilder)->append("METHOD_TYPE_PARAMETER_BOUND "_s)->append(typeReference->getTypeParameterIndex())->append(", "_s)->append(typeReference->getTypeParameterBoundIndex());
			break;
		}
	case $TypeReference::FIELD:
		{
			$nc(this->stringBuilder)->append("FIELD"_s);
			break;
		}
	case $TypeReference::METHOD_RETURN:
		{
			$nc(this->stringBuilder)->append("METHOD_RETURN"_s);
			break;
		}
	case $TypeReference::METHOD_RECEIVER:
		{
			$nc(this->stringBuilder)->append("METHOD_RECEIVER"_s);
			break;
		}
	case $TypeReference::METHOD_FORMAL_PARAMETER:
		{
			$nc(this->stringBuilder)->append("METHOD_FORMAL_PARAMETER "_s)->append(typeReference->getFormalParameterIndex());
			break;
		}
	case $TypeReference::THROWS:
		{
			$nc(this->stringBuilder)->append("THROWS "_s)->append(typeReference->getExceptionIndex());
			break;
		}
	case $TypeReference::LOCAL_VARIABLE:
		{
			$nc(this->stringBuilder)->append("LOCAL_VARIABLE"_s);
			break;
		}
	case $TypeReference::RESOURCE_VARIABLE:
		{
			$nc(this->stringBuilder)->append("RESOURCE_VARIABLE"_s);
			break;
		}
	case $TypeReference::EXCEPTION_PARAMETER:
		{
			$nc(this->stringBuilder)->append("EXCEPTION_PARAMETER "_s)->append(typeReference->getTryCatchBlockIndex());
			break;
		}
	case $TypeReference::INSTANCEOF:
		{
			$nc(this->stringBuilder)->append("INSTANCEOF"_s);
			break;
		}
	case $TypeReference::NEW:
		{
			$nc(this->stringBuilder)->append("NEW"_s);
			break;
		}
	case $TypeReference::CONSTRUCTOR_REFERENCE:
		{
			$nc(this->stringBuilder)->append("CONSTRUCTOR_REFERENCE"_s);
			break;
		}
	case $TypeReference::METHOD_REFERENCE:
		{
			$nc(this->stringBuilder)->append("METHOD_REFERENCE"_s);
			break;
		}
	case $TypeReference::CAST:
		{
			$nc(this->stringBuilder)->append("CAST "_s)->append(typeReference->getTypeArgumentIndex());
			break;
		}
	case $TypeReference::CONSTRUCTOR_INVOCATION_TYPE_ARGUMENT:
		{
			$nc(this->stringBuilder)->append("CONSTRUCTOR_INVOCATION_TYPE_ARGUMENT "_s)->append(typeReference->getTypeArgumentIndex());
			break;
		}
	case $TypeReference::METHOD_INVOCATION_TYPE_ARGUMENT:
		{
			$nc(this->stringBuilder)->append("METHOD_INVOCATION_TYPE_ARGUMENT "_s)->append(typeReference->getTypeArgumentIndex());
			break;
		}
	case $TypeReference::CONSTRUCTOR_REFERENCE_TYPE_ARGUMENT:
		{
			$nc(this->stringBuilder)->append("CONSTRUCTOR_REFERENCE_TYPE_ARGUMENT "_s)->append(typeReference->getTypeArgumentIndex());
			break;
		}
	case $TypeReference::METHOD_REFERENCE_TYPE_ARGUMENT:
		{
			$nc(this->stringBuilder)->append("METHOD_REFERENCE_TYPE_ARGUMENT "_s)->append(typeReference->getTypeArgumentIndex());
			break;
		}
	default:
		{
			$throwNew($IllegalArgumentException);
		}
	}
}

void Textifier::appendFrameTypes(int32_t numTypes, $ObjectArray* frameTypes) {
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < numTypes; ++i) {
		if (i > 0) {
			$nc(this->stringBuilder)->append(u' ');
		}
		if ($instanceOf($String, $nc(frameTypes)->get(i))) {
			$var($String, descriptor, $cast($String, frameTypes->get(i)));
			if ($nc(descriptor)->charAt(0) == u'[') {
				appendDescriptor(Textifier::FIELD_DESCRIPTOR, descriptor);
			} else {
				appendDescriptor(Textifier::INTERNAL_NAME, descriptor);
			}
		} else if ($instanceOf($Integer, frameTypes->get(i))) {
			$nc(this->stringBuilder)->append($cast($String, $($nc(Textifier::FRAME_TYPES)->get($nc(($cast($Integer, frameTypes->get(i))))->intValue()))));
		} else {
			appendLabel($cast($Label, frameTypes->get(i)));
		}
	}
}

Textifier* Textifier::addNewTextifier($String* endText) {
	$useLocalCurrentObjectStackCache();
	$var(Textifier, textifier, createTextifier());
	$nc(this->text)->add($($nc(textifier)->getText()));
	if (endText != nullptr) {
		$nc(this->text)->add(endText);
	}
	return textifier;
}

Textifier* Textifier::createTextifier() {
	return $new(Textifier, this->api);
}

void clinit$Textifier($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(Textifier::USAGE, "Prints a disassembled view of the given class.\nUsage: Textifier [-debug] <fully qualified class name or class file name>"_s);
	$assignStatic(Textifier::CLASS_SUFFIX, ".class"_s);
	$assignStatic(Textifier::DEPRECATED, "// DEPRECATED\n"_s);
	$assignStatic(Textifier::RECORD, "// RECORD\n"_s);
	$assignStatic(Textifier::INVISIBLE, " // invisible\n"_s);
	$assignStatic(Textifier::FRAME_TYPES, $Collections::unmodifiableList($($Arrays::asList($$new($StringArray, {
		"T"_s,
		"I"_s,
		"F"_s,
		"D"_s,
		"J"_s,
		"N"_s,
		"U"_s
	})))));
}

Textifier::Textifier() {
}

$Class* Textifier::load$($String* name, bool initialize) {
	$loadClass(Textifier, name, initialize, &_Textifier_ClassInfo_, clinit$Textifier, allocate$Textifier);
	return class$;
}

$Class* Textifier::class$ = nullptr;

					} // util
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk