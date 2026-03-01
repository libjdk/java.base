#include <jdk/internal/org/objectweb/asm/util/ASMifier.h>

#include <java/io/OutputStream.h>
#include <java/io/PrintWriter.h>
#include <java/lang/IllegalStateException.h>
#include <java/util/Arrays.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <jdk/internal/org/objectweb/asm/Attribute.h>
#include <jdk/internal/org/objectweb/asm/ConstantDynamic.h>
#include <jdk/internal/org/objectweb/asm/Handle.h>
#include <jdk/internal/org/objectweb/asm/Label.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/Type.h>
#include <jdk/internal/org/objectweb/asm/TypePath.h>
#include <jdk/internal/org/objectweb/asm/util/ASMifierSupport.h>
#include <jdk/internal/org/objectweb/asm/util/Printer.h>
#include <jcpp.h>

#undef ACCESS_CLASS
#undef ACCESS_FIELD
#undef ACCESS_INNER
#undef ACCESS_MODULE
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
#undef ANNOTATION_VISITOR
#undef ANNOTATION_VISITOR0
#undef ASM8
#undef CLASS_VERSIONS
#undef COMMA
#undef END_ARRAY
#undef END_PARAMETERS
#undef FRAME_TYPES
#undef F_APPEND
#undef F_CHOP
#undef F_FULL
#undef F_NEW
#undef F_SAME
#undef F_SAME1
#undef HANDLE_TAG
#undef NEWARRAY
#undef NEW_OBJECT_ARRAY
#undef OPCODES
#undef TYPES
#undef USAGE
#undef VISIT_END

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
using $ConstantDynamic = ::jdk::internal::org::objectweb::asm$::ConstantDynamic;
using $Handle = ::jdk::internal::org::objectweb::asm$::Handle;
using $Label = ::jdk::internal::org::objectweb::asm$::Label;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $Type = ::jdk::internal::org::objectweb::asm$::Type;
using $TypePath = ::jdk::internal::org::objectweb::asm$::TypePath;
using $ASMifierSupport = ::jdk::internal::org::objectweb::asm$::util::ASMifierSupport;
using $Printer = ::jdk::internal::org::objectweb::asm$::util::Printer;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace util {

$CompoundAttribute _ASMifier_MethodAnnotations_visitPermittedSubclassExperimental66[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _ASMifier_FieldInfo_[] = {
	{"USAGE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ASMifier, USAGE)},
	{"ACCESS_CLASS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ASMifier, ACCESS_CLASS)},
	{"ACCESS_FIELD", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ASMifier, ACCESS_FIELD)},
	{"ACCESS_INNER", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ASMifier, ACCESS_INNER)},
	{"ACCESS_MODULE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ASMifier, ACCESS_MODULE)},
	{"ANNOTATION_VISITOR", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ASMifier, ANNOTATION_VISITOR)},
	{"ANNOTATION_VISITOR0", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ASMifier, ANNOTATION_VISITOR0)},
	{"COMMA", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ASMifier, COMMA)},
	{"END_ARRAY", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ASMifier, END_ARRAY)},
	{"END_PARAMETERS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ASMifier, END_PARAMETERS)},
	{"NEW_OBJECT_ARRAY", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ASMifier, NEW_OBJECT_ARRAY)},
	{"VISIT_END", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ASMifier, VISIT_END)},
	{"FRAME_TYPES", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ASMifier, FRAME_TYPES)},
	{"CLASS_VERSIONS", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Integer;Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ASMifier, CLASS_VERSIONS)},
	{"name", "Ljava/lang/String;", nullptr, $PROTECTED | $FINAL, $field(ASMifier, name)},
	{"id", "I", nullptr, $PROTECTED | $FINAL, $field(ASMifier, id)},
	{"labelNames", "Ljava/util/Map;", "Ljava/util/Map<Ljdk/internal/org/objectweb/asm/Label;Ljava/lang/String;>;", $PROTECTED, $field(ASMifier, labelNames)},
	{}
};

$MethodInfo _ASMifier_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ASMifier, init$, void)},
	{"<init>", "(ILjava/lang/String;I)V", nullptr, $PROTECTED, $method(ASMifier, init$, void, int32_t, $String*, int32_t)},
	{"appendAccessFlags", "(I)V", nullptr, $PRIVATE, $method(ASMifier, appendAccessFlags, void, int32_t)},
	{"appendConstant", "(Ljava/lang/Object;)V", nullptr, $PROTECTED, $virtualMethod(ASMifier, appendConstant, void, Object$*)},
	{"appendFrameTypes", "(I[Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(ASMifier, appendFrameTypes, void, int32_t, $ObjectArray*)},
	{"appendLabel", "(Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PROTECTED, $virtualMethod(ASMifier, appendLabel, void, $Label*)},
	{"createASMifier", "(Ljava/lang/String;I)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PROTECTED, $virtualMethod(ASMifier, createASMifier, ASMifier*, $String*, int32_t)},
	{"declareFrameTypes", "(I[Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(ASMifier, declareFrameTypes, void, int32_t, $ObjectArray*)},
	{"declareLabel", "(Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PROTECTED, $virtualMethod(ASMifier, declareLabel, void, $Label*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ASMifier, main, void, $StringArray*), "java.io.IOException"},
	{"main", "([Ljava/lang/String;Ljava/io/PrintWriter;Ljava/io/PrintWriter;)V", nullptr, $STATIC, $staticMethod(ASMifier, main, void, $StringArray*, $PrintWriter*, $PrintWriter*), "java.io.IOException"},
	{"visit", "(IILjava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visit, void, int32_t, int32_t, $String*, $String*, $String*, $StringArray*)},
	{"visit", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visit, void, $String*, Object$*)},
	{"visitAnnotableParameterCount", "(IZ)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitAnnotableParameterCount, ASMifier*, int32_t, bool)},
	{"visitAnnotation", "(Ljava/lang/String;Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitAnnotation, ASMifier*, $String*, $String*)},
	{"visitAnnotation", "(Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitAnnotation, ASMifier*, $String*, bool)},
	{"visitAnnotationDefault", "()Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitAnnotationDefault, ASMifier*)},
	{"visitAnnotationEnd", "()V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitAnnotationEnd, void)},
	{"visitArray", "(Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitArray, ASMifier*, $String*)},
	{"visitAttribute", "(Ljdk/internal/org/objectweb/asm/Attribute;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitAttribute, void, $Attribute*)},
	{"visitClassAnnotation", "(Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitClassAnnotation, ASMifier*, $String*, bool)},
	{"visitClassAttribute", "(Ljdk/internal/org/objectweb/asm/Attribute;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitClassAttribute, void, $Attribute*)},
	{"visitClassEnd", "()V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitClassEnd, void)},
	{"visitClassTypeAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitClassTypeAnnotation, ASMifier*, int32_t, $TypePath*, $String*, bool)},
	{"visitCode", "()V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitCode, void)},
	{"visitEnum", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitEnum, void, $String*, $String*, $String*)},
	{"visitExport", "(Ljava/lang/String;I[Ljava/lang/String;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(ASMifier, visitExport, void, $String*, int32_t, $StringArray*)},
	{"visitExportOrOpen", "(Ljava/lang/String;Ljava/lang/String;I[Ljava/lang/String;)V", nullptr, $PRIVATE | $TRANSIENT, $method(ASMifier, visitExportOrOpen, void, $String*, $String*, int32_t, $StringArray*)},
	{"visitField", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Object;)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitField, ASMifier*, int32_t, $String*, $String*, $String*, Object$*)},
	{"visitFieldAnnotation", "(Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitFieldAnnotation, ASMifier*, $String*, bool)},
	{"visitFieldAttribute", "(Ljdk/internal/org/objectweb/asm/Attribute;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitFieldAttribute, void, $Attribute*)},
	{"visitFieldEnd", "()V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitFieldEnd, void)},
	{"visitFieldInsn", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitFieldInsn, void, int32_t, $String*, $String*, $String*)},
	{"visitFieldTypeAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitFieldTypeAnnotation, ASMifier*, int32_t, $TypePath*, $String*, bool)},
	{"visitFrame", "(II[Ljava/lang/Object;I[Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitFrame, void, int32_t, int32_t, $ObjectArray*, int32_t, $ObjectArray*)},
	{"visitIincInsn", "(II)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitIincInsn, void, int32_t, int32_t)},
	{"visitInnerClass", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitInnerClass, void, $String*, $String*, $String*, int32_t)},
	{"visitInsn", "(I)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitInsn, void, int32_t)},
	{"visitInsnAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitInsnAnnotation, ASMifier*, int32_t, $TypePath*, $String*, bool)},
	{"visitIntInsn", "(II)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitIntInsn, void, int32_t, int32_t)},
	{"visitInvokeDynamicInsn", "(Ljava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/Handle;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(ASMifier, visitInvokeDynamicInsn, void, $String*, $String*, $Handle*, $ObjectArray*)},
	{"visitJumpInsn", "(ILjdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitJumpInsn, void, int32_t, $Label*)},
	{"visitLabel", "(Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitLabel, void, $Label*)},
	{"visitLdcInsn", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitLdcInsn, void, Object$*)},
	{"visitLineNumber", "(ILjdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitLineNumber, void, int32_t, $Label*)},
	{"visitLocalVariable", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/Label;Ljdk/internal/org/objectweb/asm/Label;I)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitLocalVariable, void, $String*, $String*, $String*, $Label*, $Label*, int32_t)},
	{"visitLocalVariableAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;[Ljdk/internal/org/objectweb/asm/Label;[Ljdk/internal/org/objectweb/asm/Label;[ILjava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitLocalVariableAnnotation, $Printer*, int32_t, $TypePath*, $LabelArray*, $LabelArray*, $ints*, $String*, bool)},
	{"visitLookupSwitchInsn", "(Ljdk/internal/org/objectweb/asm/Label;[I[Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitLookupSwitchInsn, void, $Label*, $ints*, $LabelArray*)},
	{"visitMainClass", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitMainClass, void, $String*)},
	{"visitMaxs", "(II)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitMaxs, void, int32_t, int32_t)},
	{"visitMethod", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitMethod, ASMifier*, int32_t, $String*, $String*, $String*, $StringArray*)},
	{"visitMethodAnnotation", "(Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitMethodAnnotation, ASMifier*, $String*, bool)},
	{"visitMethodAttribute", "(Ljdk/internal/org/objectweb/asm/Attribute;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitMethodAttribute, void, $Attribute*)},
	{"visitMethodEnd", "()V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitMethodEnd, void)},
	{"visitMethodInsn", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitMethodInsn, void, int32_t, $String*, $String*, $String*, bool)},
	{"visitMethodTypeAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitMethodTypeAnnotation, ASMifier*, int32_t, $TypePath*, $String*, bool)},
	{"visitModule", "(Ljava/lang/String;ILjava/lang/String;)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitModule, $Printer*, $String*, int32_t, $String*)},
	{"visitModuleEnd", "()V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitModuleEnd, void)},
	{"visitMultiANewArrayInsn", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitMultiANewArrayInsn, void, $String*, int32_t)},
	{"visitNestHost", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitNestHost, void, $String*)},
	{"visitNestMember", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitNestMember, void, $String*)},
	{"visitOpen", "(Ljava/lang/String;I[Ljava/lang/String;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(ASMifier, visitOpen, void, $String*, int32_t, $StringArray*)},
	{"visitOuterClass", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitOuterClass, void, $String*, $String*, $String*)},
	{"visitPackage", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitPackage, void, $String*)},
	{"visitParameter", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitParameter, void, $String*, int32_t)},
	{"visitParameterAnnotation", "(ILjava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitParameterAnnotation, ASMifier*, int32_t, $String*, bool)},
	{"visitPermittedSubclassExperimental", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(ASMifier, visitPermittedSubclassExperimental, void, $String*), nullptr, nullptr, _ASMifier_MethodAnnotations_visitPermittedSubclassExperimental66},
	{"visitProvide", "(Ljava/lang/String;[Ljava/lang/String;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(ASMifier, visitProvide, void, $String*, $StringArray*)},
	{"visitRecordComponent", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitRecordComponent, ASMifier*, $String*, $String*, $String*)},
	{"visitRecordComponentAnnotation", "(Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitRecordComponentAnnotation, ASMifier*, $String*, bool)},
	{"visitRecordComponentAttribute", "(Ljdk/internal/org/objectweb/asm/Attribute;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitRecordComponentAttribute, void, $Attribute*)},
	{"visitRecordComponentEnd", "()V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitRecordComponentEnd, void)},
	{"visitRecordComponentTypeAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitRecordComponentTypeAnnotation, ASMifier*, int32_t, $TypePath*, $String*, bool)},
	{"visitRequire", "(Ljava/lang/String;ILjava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitRequire, void, $String*, int32_t, $String*)},
	{"visitSource", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitSource, void, $String*, $String*)},
	{"visitTableSwitchInsn", "(IILjdk/internal/org/objectweb/asm/Label;[Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(ASMifier, visitTableSwitchInsn, void, int32_t, int32_t, $Label*, $LabelArray*)},
	{"visitTryCatchAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitTryCatchAnnotation, ASMifier*, int32_t, $TypePath*, $String*, bool)},
	{"visitTryCatchBlock", "(Ljdk/internal/org/objectweb/asm/Label;Ljdk/internal/org/objectweb/asm/Label;Ljdk/internal/org/objectweb/asm/Label;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitTryCatchBlock, void, $Label*, $Label*, $Label*, $String*)},
	{"visitTypeAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitTypeAnnotation, ASMifier*, int32_t, $TypePath*, $String*, bool)},
	{"visitTypeAnnotation", "(Ljava/lang/String;ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/ASMifier;", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitTypeAnnotation, ASMifier*, $String*, int32_t, $TypePath*, $String*, bool)},
	{"visitTypeInsn", "(ILjava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitTypeInsn, void, int32_t, $String*)},
	{"visitUse", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitUse, void, $String*)},
	{"visitVarInsn", "(II)V", nullptr, $PUBLIC, $virtualMethod(ASMifier, visitVarInsn, void, int32_t, int32_t)},
	{}
};

$ClassInfo _ASMifier_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.util.ASMifier",
	"jdk.internal.org.objectweb.asm.util.Printer",
	nullptr,
	_ASMifier_FieldInfo_,
	_ASMifier_MethodInfo_
};

$Object* allocate$ASMifier($Class* clazz) {
	return $of($alloc(ASMifier));
}

$String* ASMifier::USAGE = nullptr;
$String* ASMifier::ANNOTATION_VISITOR = nullptr;
$String* ASMifier::ANNOTATION_VISITOR0 = nullptr;
$String* ASMifier::COMMA = nullptr;
$String* ASMifier::END_ARRAY = nullptr;
$String* ASMifier::END_PARAMETERS = nullptr;
$String* ASMifier::NEW_OBJECT_ARRAY = nullptr;
$String* ASMifier::VISIT_END = nullptr;
$List* ASMifier::FRAME_TYPES = nullptr;
$Map* ASMifier::CLASS_VERSIONS = nullptr;

void ASMifier::init$() {
	ASMifier::init$($Opcodes::ASM8, "classWriter"_s, 0);
	if ($of(this)->getClass() != ASMifier::class$) {
		$throwNew($IllegalStateException);
	}
}

void ASMifier::init$(int32_t api, $String* visitorVariableName, int32_t annotationVisitorId) {
	$Printer::init$(api);
	$set(this, name, visitorVariableName);
	this->id = annotationVisitorId;
}

void ASMifier::main($StringArray* args) {
	$init(ASMifier);
	$useLocalCurrentObjectStackCache();
	$var($StringArray, var$0, args);
	$var($PrintWriter, var$1, $new($PrintWriter, static_cast<$OutputStream*>($System::out), true));
	main(var$0, var$1, $$new($PrintWriter, static_cast<$OutputStream*>($System::err), true));
}

void ASMifier::main($StringArray* args, $PrintWriter* output, $PrintWriter* logger) {
	$init(ASMifier);
	$Printer::main(args, ASMifier::USAGE, $$new(ASMifier), output, logger);
}

void ASMifier::visit(int32_t version, int32_t access, $String* name, $String* signature, $String* superName, $StringArray* interfaces) {
	$useLocalCurrentObjectStackCache();
	$var($String, simpleName, nullptr);
	if (name == nullptr) {
		$assign(simpleName, "module-info"_s);
	} else {
		int32_t lastSlashIndex = $nc(name)->lastIndexOf((int32_t)u'/');
		if (lastSlashIndex == -1) {
			$assign(simpleName, name);
		} else {
			$nc(this->text)->add($$str({"package asm."_s, $($(name->substring(0, lastSlashIndex))->replace(u'/', u'.')), ";\n"_s}));
			$assign(simpleName, $(name->substring(lastSlashIndex + 1))->replaceAll("[-\\(\\)]"_s, "_"_s));
		}
	}
	$nc(this->text)->add("import jdk.internal.org.objectweb.asm.AnnotationVisitor;\n"_s);
	$nc(this->text)->add("import jdk.internal.org.objectweb.asm.Attribute;\n"_s);
	$nc(this->text)->add("import jdk.internal.org.objectweb.asm.ClassReader;\n"_s);
	$nc(this->text)->add("import jdk.internal.org.objectweb.asm.ClassWriter;\n"_s);
	$nc(this->text)->add("import jdk.internal.org.objectweb.asm.ConstantDynamic;\n"_s);
	$nc(this->text)->add("import jdk.internal.org.objectweb.asm.FieldVisitor;\n"_s);
	$nc(this->text)->add("import jdk.internal.org.objectweb.asm.Handle;\n"_s);
	$nc(this->text)->add("import jdk.internal.org.objectweb.asm.Label;\n"_s);
	$nc(this->text)->add("import jdk.internal.org.objectweb.asm.MethodVisitor;\n"_s);
	$nc(this->text)->add("import jdk.internal.org.objectweb.asm.Opcodes;\n"_s);
	$nc(this->text)->add("import jdk.internal.org.objectweb.asm.RecordComponentVisitor;\n"_s);
	$nc(this->text)->add("import jdk.internal.org.objectweb.asm.Type;\n"_s);
	$nc(this->text)->add("import jdk.internal.org.objectweb.asm.TypePath;\n"_s);
	$nc(this->text)->add($$str({"public class "_s, simpleName, "Dump implements Opcodes {\n\n"_s}));
	$nc(this->text)->add("public static byte[] dump () throws Exception {\n\n"_s);
	$nc(this->text)->add("ClassWriter classWriter = new ClassWriter(0);\n"_s);
	$nc(this->text)->add("FieldVisitor fieldVisitor;\n"_s);
	$nc(this->text)->add("RecordComponentVisitor recordComponentVisitor;\n"_s);
	$nc(this->text)->add("MethodVisitor methodVisitor;\n"_s);
	$nc(this->text)->add("AnnotationVisitor annotationVisitor0;\n\n"_s);
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("classWriter.visit("_s);
	$var($String, versionString, $cast($String, $nc(ASMifier::CLASS_VERSIONS)->get($($Integer::valueOf(version)))));
	if (versionString != nullptr) {
		$nc(this->stringBuilder)->append(versionString);
	} else {
		$nc(this->stringBuilder)->append(version);
	}
	$nc(this->stringBuilder)->append(", "_s);
	appendAccessFlags(access | ASMifier::ACCESS_CLASS);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(name);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(signature);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(superName);
	$nc(this->stringBuilder)->append(", "_s);
	if (interfaces != nullptr && interfaces->length > 0) {
		$nc(this->stringBuilder)->append("new String[] {"_s);
		for (int32_t i = 0; i < interfaces->length; ++i) {
			$nc(this->stringBuilder)->append(i == 0 ? " "_s : ", "_s);
			appendConstant(interfaces->get(i));
		}
		$nc(this->stringBuilder)->append(" }"_s);
	} else {
		$nc(this->stringBuilder)->append("null"_s);
	}
	$nc(this->stringBuilder)->append(ASMifier::END_PARAMETERS);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitSource($String* file, $String* debug) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("classWriter.visitSource("_s);
	appendConstant(file);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(debug);
	$nc(this->stringBuilder)->append(ASMifier::END_PARAMETERS);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

$Printer* ASMifier::visitModule($String* name, int32_t flags, $String* version) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("ModuleVisitor moduleVisitor = classWriter.visitModule("_s);
	appendConstant(name);
	$nc(this->stringBuilder)->append(", "_s);
	appendAccessFlags(flags | ASMifier::ACCESS_MODULE);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(version);
	$nc(this->stringBuilder)->append(ASMifier::END_PARAMETERS);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	$var(ASMifier, asmifier, createASMifier("moduleVisitor"_s, 0));
	$nc(this->text)->add($($nc(asmifier)->getText()));
	$nc(this->text)->add("}\n"_s);
	return asmifier;
}

void ASMifier::visitNestHost($String* nestHost) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("classWriter.visitNestHost("_s);
	appendConstant(nestHost);
	$nc(this->stringBuilder)->append(ASMifier::END_PARAMETERS);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitOuterClass($String* owner, $String* name, $String* descriptor) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("classWriter.visitOuterClass("_s);
	appendConstant(owner);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(name);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(descriptor);
	$nc(this->stringBuilder)->append(ASMifier::END_PARAMETERS);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

ASMifier* ASMifier::visitClassAnnotation($String* descriptor, bool visible) {
	return visitAnnotation(descriptor, visible);
}

ASMifier* ASMifier::visitClassTypeAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	return visitTypeAnnotation(typeRef, typePath, descriptor, visible);
}

void ASMifier::visitClassAttribute($Attribute* attribute) {
	visitAttribute(attribute);
}

void ASMifier::visitNestMember($String* nestMember) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("classWriter.visitNestMember("_s);
	appendConstant(nestMember);
	$nc(this->stringBuilder)->append(ASMifier::END_PARAMETERS);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitPermittedSubclassExperimental($String* permittedSubclass) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("classWriter.visitPermittedSubclassExperimental("_s);
	appendConstant(permittedSubclass);
	$nc(this->stringBuilder)->append(ASMifier::END_PARAMETERS);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitInnerClass($String* name, $String* outerName, $String* innerName, int32_t access) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("classWriter.visitInnerClass("_s);
	appendConstant(name);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(outerName);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(innerName);
	$nc(this->stringBuilder)->append(", "_s);
	appendAccessFlags(access | ASMifier::ACCESS_INNER);
	$nc(this->stringBuilder)->append(ASMifier::END_PARAMETERS);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

ASMifier* ASMifier::visitRecordComponent($String* name, $String* descriptor, $String* signature) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("{\n"_s);
	$nc(this->stringBuilder)->append("recordComponentVisitor = classWriter.visitRecordComponent("_s);
	appendConstant(name);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(descriptor);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(signature);
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	$var(ASMifier, asmifier, createASMifier("recordComponentVisitor"_s, 0));
	$nc(this->text)->add($($nc(asmifier)->getText()));
	$nc(this->text)->add("}\n"_s);
	return asmifier;
}

ASMifier* ASMifier::visitField(int32_t access, $String* name, $String* descriptor, $String* signature, Object$* value) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("{\n"_s);
	$nc(this->stringBuilder)->append("fieldVisitor = classWriter.visitField("_s);
	appendAccessFlags(access | ASMifier::ACCESS_FIELD);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(name);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(descriptor);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(signature);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(value);
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	$var(ASMifier, asmifier, createASMifier("fieldVisitor"_s, 0));
	$nc(this->text)->add($($nc(asmifier)->getText()));
	$nc(this->text)->add("}\n"_s);
	return asmifier;
}

ASMifier* ASMifier::visitMethod(int32_t access, $String* name, $String* descriptor, $String* signature, $StringArray* exceptions) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("{\n"_s);
	$nc(this->stringBuilder)->append("methodVisitor = classWriter.visitMethod("_s);
	appendAccessFlags(access);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(name);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(descriptor);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(signature);
	$nc(this->stringBuilder)->append(", "_s);
	if (exceptions != nullptr && exceptions->length > 0) {
		$nc(this->stringBuilder)->append("new String[] {"_s);
		for (int32_t i = 0; i < exceptions->length; ++i) {
			$nc(this->stringBuilder)->append(i == 0 ? " "_s : ", "_s);
			appendConstant(exceptions->get(i));
		}
		$nc(this->stringBuilder)->append(" }"_s);
	} else {
		$nc(this->stringBuilder)->append("null"_s);
	}
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	$var(ASMifier, asmifier, createASMifier("methodVisitor"_s, 0));
	$nc(this->text)->add($($nc(asmifier)->getText()));
	$nc(this->text)->add("}\n"_s);
	return asmifier;
}

void ASMifier::visitClassEnd() {
	$nc(this->text)->add("classWriter.visitEnd();\n\n"_s);
	$nc(this->text)->add("return classWriter.toByteArray();\n"_s);
	$nc(this->text)->add("}\n"_s);
	$nc(this->text)->add("}\n"_s);
}

void ASMifier::visitMainClass($String* mainClass) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("moduleVisitor.visitMainClass("_s);
	appendConstant(mainClass);
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitPackage($String* packaze) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("moduleVisitor.visitPackage("_s);
	appendConstant(packaze);
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitRequire($String* module, int32_t access, $String* version) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("moduleVisitor.visitRequire("_s);
	appendConstant(module);
	$nc(this->stringBuilder)->append(", "_s);
	appendAccessFlags(access | ASMifier::ACCESS_MODULE);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(version);
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitExport($String* packaze, int32_t access, $StringArray* modules) {
	visitExportOrOpen("moduleVisitor.visitExport("_s, packaze, access, modules);
}

void ASMifier::visitOpen($String* packaze, int32_t access, $StringArray* modules) {
	visitExportOrOpen("moduleVisitor.visitOpen("_s, packaze, access, modules);
}

void ASMifier::visitExportOrOpen($String* visitMethod, $String* packaze, int32_t access, $StringArray* modules) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(visitMethod);
	appendConstant(packaze);
	$nc(this->stringBuilder)->append(", "_s);
	appendAccessFlags(access | ASMifier::ACCESS_MODULE);
	if (modules != nullptr && modules->length > 0) {
		$nc(this->stringBuilder)->append(", new String[] {"_s);
		for (int32_t i = 0; i < modules->length; ++i) {
			$nc(this->stringBuilder)->append(i == 0 ? " "_s : ", "_s);
			appendConstant(modules->get(i));
		}
		$nc(this->stringBuilder)->append(" }"_s);
	}
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitUse($String* service) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("moduleVisitor.visitUse("_s);
	appendConstant(service);
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitProvide($String* service, $StringArray* providers) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("moduleVisitor.visitProvide("_s);
	appendConstant(service);
	$nc(this->stringBuilder)->append(",  new String[] {"_s);
	for (int32_t i = 0; i < $nc(providers)->length; ++i) {
		$nc(this->stringBuilder)->append(i == 0 ? " "_s : ", "_s);
		appendConstant(providers->get(i));
	}
	$nc(this->stringBuilder)->append(ASMifier::END_ARRAY);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitModuleEnd() {
	$nc(this->text)->add("moduleVisitor.visitEnd();\n"_s);
}

void ASMifier::visit($String* name, Object$* value) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(ASMifier::ANNOTATION_VISITOR)->append(this->id)->append(".visit("_s);
	appendConstant(name);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(value);
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitEnum($String* name, $String* descriptor, $String* value) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(ASMifier::ANNOTATION_VISITOR)->append(this->id)->append(".visitEnum("_s);
	appendConstant(name);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(descriptor);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(value);
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

ASMifier* ASMifier::visitAnnotation($String* name, $String* descriptor) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("{\n"_s)->append("AnnotationVisitor annotationVisitor"_s)->append(this->id + 1)->append(" = annotationVisitor"_s);
	$nc(this->stringBuilder)->append(this->id)->append(".visitAnnotation("_s);
	appendConstant(name);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(descriptor);
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	$var(ASMifier, asmifier, createASMifier(ASMifier::ANNOTATION_VISITOR, this->id + 1));
	$nc(this->text)->add($($nc(asmifier)->getText()));
	$nc(this->text)->add("}\n"_s);
	return asmifier;
}

ASMifier* ASMifier::visitArray($String* name) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("{\n"_s);
	$nc(this->stringBuilder)->append("AnnotationVisitor annotationVisitor"_s)->append(this->id + 1)->append(" = annotationVisitor"_s);
	$nc(this->stringBuilder)->append(this->id)->append(".visitArray("_s);
	appendConstant(name);
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	$var(ASMifier, asmifier, createASMifier(ASMifier::ANNOTATION_VISITOR, this->id + 1));
	$nc(this->text)->add($($nc(asmifier)->getText()));
	$nc(this->text)->add("}\n"_s);
	return asmifier;
}

void ASMifier::visitAnnotationEnd() {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(ASMifier::ANNOTATION_VISITOR)->append(this->id)->append(ASMifier::VISIT_END);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

ASMifier* ASMifier::visitRecordComponentAnnotation($String* descriptor, bool visible) {
	return visitAnnotation(descriptor, visible);
}

ASMifier* ASMifier::visitRecordComponentTypeAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	return visitTypeAnnotation(typeRef, typePath, descriptor, visible);
}

void ASMifier::visitRecordComponentAttribute($Attribute* attribute) {
	visitAttribute(attribute);
}

void ASMifier::visitRecordComponentEnd() {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->name)->append(ASMifier::VISIT_END);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

ASMifier* ASMifier::visitFieldAnnotation($String* descriptor, bool visible) {
	return visitAnnotation(descriptor, visible);
}

ASMifier* ASMifier::visitFieldTypeAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	return visitTypeAnnotation(typeRef, typePath, descriptor, visible);
}

void ASMifier::visitFieldAttribute($Attribute* attribute) {
	visitAttribute(attribute);
}

void ASMifier::visitFieldEnd() {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->name)->append(ASMifier::VISIT_END);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitParameter($String* parameterName, int32_t access) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->name)->append(".visitParameter("_s);
	appendString(this->stringBuilder, parameterName);
	$nc(this->stringBuilder)->append(", "_s);
	appendAccessFlags(access);
	$nc(this->text)->add($($nc(this->stringBuilder)->append(");\n"_s)->toString()));
}

ASMifier* ASMifier::visitAnnotationDefault() {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("{\n"_s)->append(ASMifier::ANNOTATION_VISITOR0)->append(this->name)->append(".visitAnnotationDefault();\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	$var(ASMifier, asmifier, createASMifier(ASMifier::ANNOTATION_VISITOR, 0));
	$nc(this->text)->add($($nc(asmifier)->getText()));
	$nc(this->text)->add("}\n"_s);
	return asmifier;
}

ASMifier* ASMifier::visitMethodAnnotation($String* descriptor, bool visible) {
	return visitAnnotation(descriptor, visible);
}

ASMifier* ASMifier::visitMethodTypeAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	return visitTypeAnnotation(typeRef, typePath, descriptor, visible);
}

ASMifier* ASMifier::visitAnnotableParameterCount(int32_t parameterCount, bool visible) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->name)->append(".visitAnnotableParameterCount("_s)->append(parameterCount)->append(", "_s)->append(visible)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	return this;
}

ASMifier* ASMifier::visitParameterAnnotation(int32_t parameter, $String* descriptor, bool visible) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("{\n"_s)->append(ASMifier::ANNOTATION_VISITOR0)->append(this->name)->append(".visitParameterAnnotation("_s)->append(parameter)->append(", "_s);
	appendConstant(descriptor);
	$nc(this->stringBuilder)->append(", "_s)->append(visible)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	$var(ASMifier, asmifier, createASMifier(ASMifier::ANNOTATION_VISITOR, 0));
	$nc(this->text)->add($($nc(asmifier)->getText()));
	$nc(this->text)->add("}\n"_s);
	return asmifier;
}

void ASMifier::visitMethodAttribute($Attribute* attribute) {
	visitAttribute(attribute);
}

void ASMifier::visitCode() {
	$nc(this->text)->add($$str({this->name, ".visitCode();\n"_s}));
}

void ASMifier::visitFrame(int32_t type, int32_t numLocal, $ObjectArray* local, int32_t numStack, $ObjectArray* stack) {
	$nc(this->stringBuilder)->setLength(0);
	switch (type) {
	case $Opcodes::F_NEW:
		{}
	case $Opcodes::F_FULL:
		{
			declareFrameTypes(numLocal, local);
			declareFrameTypes(numStack, stack);
			if (type == $Opcodes::F_NEW) {
				$nc(this->stringBuilder)->append(this->name)->append(".visitFrame(Opcodes.F_NEW, "_s);
			} else {
				$nc(this->stringBuilder)->append(this->name)->append(".visitFrame(Opcodes.F_FULL, "_s);
			}
			$nc(this->stringBuilder)->append(numLocal)->append(ASMifier::NEW_OBJECT_ARRAY);
			appendFrameTypes(numLocal, local);
			$nc(this->stringBuilder)->append("}, "_s)->append(numStack)->append(ASMifier::NEW_OBJECT_ARRAY);
			appendFrameTypes(numStack, stack);
			$nc(this->stringBuilder)->append(u'}');
			break;
		}
	case $Opcodes::F_APPEND:
		{
			declareFrameTypes(numLocal, local);
			$nc(this->stringBuilder)->append(this->name)->append(".visitFrame(Opcodes.F_APPEND,"_s)->append(numLocal)->append(ASMifier::NEW_OBJECT_ARRAY);
			appendFrameTypes(numLocal, local);
			$nc(this->stringBuilder)->append("}, 0, null"_s);
			break;
		}
	case $Opcodes::F_CHOP:
		{
			$nc(this->stringBuilder)->append(this->name)->append(".visitFrame(Opcodes.F_CHOP,"_s)->append(numLocal)->append(", null, 0, null"_s);
			break;
		}
	case $Opcodes::F_SAME:
		{
			$nc(this->stringBuilder)->append(this->name)->append(".visitFrame(Opcodes.F_SAME, 0, null, 0, null"_s);
			break;
		}
	case $Opcodes::F_SAME1:
		{
			declareFrameTypes(1, stack);
			$nc(this->stringBuilder)->append(this->name)->append(".visitFrame(Opcodes.F_SAME1, 0, null, 1, new Object[] {"_s);
			appendFrameTypes(1, stack);
			$nc(this->stringBuilder)->append(u'}');
			break;
		}
	default:
		{
			$throwNew($IllegalArgumentException);
		}
	}
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitInsn(int32_t opcode) {
	$nc(this->stringBuilder)->setLength(0);
	$init($Printer);
	$nc(this->stringBuilder)->append(this->name)->append(".visitInsn("_s)->append($nc($Printer::OPCODES)->get(opcode))->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitIntInsn(int32_t opcode, int32_t operand) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$init($Printer);
	$nc(this->stringBuilder)->append(this->name)->append(".visitIntInsn("_s)->append($nc($Printer::OPCODES)->get(opcode))->append(", "_s)->append(opcode == $Opcodes::NEWARRAY ? $nc($Printer::TYPES)->get(operand) : $($Integer::toString(operand)))->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitVarInsn(int32_t opcode, int32_t var) {
	$nc(this->stringBuilder)->setLength(0);
	$init($Printer);
	$nc(this->stringBuilder)->append(this->name)->append(".visitVarInsn("_s)->append($nc($Printer::OPCODES)->get(opcode))->append(", "_s)->append(var)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitTypeInsn(int32_t opcode, $String* type) {
	$nc(this->stringBuilder)->setLength(0);
	$init($Printer);
	$nc(this->stringBuilder)->append(this->name)->append(".visitTypeInsn("_s)->append($nc($Printer::OPCODES)->get(opcode))->append(", "_s);
	appendConstant(type);
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitFieldInsn(int32_t opcode, $String* owner, $String* name, $String* descriptor) {
	$nc(this->stringBuilder)->setLength(0);
	$init($Printer);
	$nc(this->stringBuilder)->append(this->name)->append(".visitFieldInsn("_s)->append($nc($Printer::OPCODES)->get(opcode))->append(", "_s);
	appendConstant(owner);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(name);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(descriptor);
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitMethodInsn(int32_t opcode, $String* owner, $String* name, $String* descriptor, bool isInterface) {
	$nc(this->stringBuilder)->setLength(0);
	$init($Printer);
	$nc(this->stringBuilder)->append(this->name)->append(".visitMethodInsn("_s)->append($nc($Printer::OPCODES)->get(opcode))->append(", "_s);
	appendConstant(owner);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(name);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(descriptor);
	$nc(this->stringBuilder)->append(", "_s);
	$nc(this->stringBuilder)->append(isInterface ? "true"_s : "false"_s);
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitInvokeDynamicInsn($String* name, $String* descriptor, $Handle* bootstrapMethodHandle, $ObjectArray* bootstrapMethodArguments) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->name)->append(".visitInvokeDynamicInsn("_s);
	appendConstant(name);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(descriptor);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(bootstrapMethodHandle);
	$nc(this->stringBuilder)->append(", new Object[]{"_s);
	for (int32_t i = 0; i < $nc(bootstrapMethodArguments)->length; ++i) {
		appendConstant(bootstrapMethodArguments->get(i));
		if (i != bootstrapMethodArguments->length - 1) {
			$nc(this->stringBuilder)->append(", "_s);
		}
	}
	$nc(this->stringBuilder)->append("});\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitJumpInsn(int32_t opcode, $Label* label) {
	$nc(this->stringBuilder)->setLength(0);
	declareLabel(label);
	$init($Printer);
	$nc(this->stringBuilder)->append(this->name)->append(".visitJumpInsn("_s)->append($nc($Printer::OPCODES)->get(opcode))->append(", "_s);
	appendLabel(label);
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitLabel($Label* label) {
	$nc(this->stringBuilder)->setLength(0);
	declareLabel(label);
	$nc(this->stringBuilder)->append(this->name)->append(".visitLabel("_s);
	appendLabel(label);
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitLdcInsn(Object$* value) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->name)->append(".visitLdcInsn("_s);
	appendConstant(value);
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitIincInsn(int32_t var, int32_t increment) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->name)->append(".visitIincInsn("_s)->append(var)->append(", "_s)->append(increment)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitTableSwitchInsn(int32_t min, int32_t max, $Label* dflt, $LabelArray* labels) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	{
		$var($LabelArray, arr$, labels);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Label, label, arr$->get(i$));
			{
				declareLabel(label);
			}
		}
	}
	declareLabel(dflt);
	$nc(this->stringBuilder)->append(this->name)->append(".visitTableSwitchInsn("_s)->append(min)->append(", "_s)->append(max)->append(", "_s);
	appendLabel(dflt);
	$nc(this->stringBuilder)->append(", new Label[] {"_s);
	for (int32_t i = 0; i < $nc(labels)->length; ++i) {
		$nc(this->stringBuilder)->append(i == 0 ? " "_s : ", "_s);
		appendLabel(labels->get(i));
	}
	$nc(this->stringBuilder)->append(ASMifier::END_ARRAY);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitLookupSwitchInsn($Label* dflt, $ints* keys, $LabelArray* labels) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	{
		$var($LabelArray, arr$, labels);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Label, label, arr$->get(i$));
			{
				declareLabel(label);
			}
		}
	}
	declareLabel(dflt);
	$nc(this->stringBuilder)->append(this->name)->append(".visitLookupSwitchInsn("_s);
	appendLabel(dflt);
	$nc(this->stringBuilder)->append(", new int[] {"_s);
	for (int32_t i = 0; i < $nc(keys)->length; ++i) {
		$nc(this->stringBuilder)->append(i == 0 ? " "_s : ", "_s)->append(keys->get(i));
	}
	$nc(this->stringBuilder)->append(" }, new Label[] {"_s);
	for (int32_t i = 0; i < $nc(labels)->length; ++i) {
		$nc(this->stringBuilder)->append(i == 0 ? " "_s : ", "_s);
		appendLabel(labels->get(i));
	}
	$nc(this->stringBuilder)->append(ASMifier::END_ARRAY);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitMultiANewArrayInsn($String* descriptor, int32_t numDimensions) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->name)->append(".visitMultiANewArrayInsn("_s);
	appendConstant(descriptor);
	$nc(this->stringBuilder)->append(", "_s)->append(numDimensions)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

ASMifier* ASMifier::visitInsnAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	return visitTypeAnnotation("visitInsnAnnotation"_s, typeRef, typePath, descriptor, visible);
}

void ASMifier::visitTryCatchBlock($Label* start, $Label* end, $Label* handler, $String* type) {
	$nc(this->stringBuilder)->setLength(0);
	declareLabel(start);
	declareLabel(end);
	declareLabel(handler);
	$nc(this->stringBuilder)->append(this->name)->append(".visitTryCatchBlock("_s);
	appendLabel(start);
	$nc(this->stringBuilder)->append(", "_s);
	appendLabel(end);
	$nc(this->stringBuilder)->append(", "_s);
	appendLabel(handler);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(type);
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

ASMifier* ASMifier::visitTryCatchAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	return visitTypeAnnotation("visitTryCatchAnnotation"_s, typeRef, typePath, descriptor, visible);
}

void ASMifier::visitLocalVariable($String* name, $String* descriptor, $String* signature, $Label* start, $Label* end, int32_t index) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->name)->append(".visitLocalVariable("_s);
	appendConstant(name);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(descriptor);
	$nc(this->stringBuilder)->append(", "_s);
	appendConstant(signature);
	$nc(this->stringBuilder)->append(", "_s);
	appendLabel(start);
	$nc(this->stringBuilder)->append(", "_s);
	appendLabel(end);
	$nc(this->stringBuilder)->append(", "_s)->append(index)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

$Printer* ASMifier::visitLocalVariableAnnotation(int32_t typeRef, $TypePath* typePath, $LabelArray* start, $LabelArray* end, $ints* index, $String* descriptor, bool visible) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("{\n"_s)->append(ASMifier::ANNOTATION_VISITOR0)->append(this->name)->append(".visitLocalVariableAnnotation("_s)->append(typeRef);
	if (typePath == nullptr) {
		$nc(this->stringBuilder)->append(", null, "_s);
	} else {
		$nc(this->stringBuilder)->append(", TypePath.fromString(\""_s)->append($of(typePath))->append("\"), "_s);
	}
	$nc(this->stringBuilder)->append("new Label[] {"_s);
	for (int32_t i = 0; i < $nc(start)->length; ++i) {
		$nc(this->stringBuilder)->append(i == 0 ? " "_s : ", "_s);
		appendLabel(start->get(i));
	}
	$nc(this->stringBuilder)->append(" }, new Label[] {"_s);
	for (int32_t i = 0; i < $nc(end)->length; ++i) {
		$nc(this->stringBuilder)->append(i == 0 ? " "_s : ", "_s);
		appendLabel(end->get(i));
	}
	$nc(this->stringBuilder)->append(" }, new int[] {"_s);
	for (int32_t i = 0; i < $nc(index)->length; ++i) {
		$nc(this->stringBuilder)->append(i == 0 ? " "_s : ", "_s)->append(index->get(i));
	}
	$nc(this->stringBuilder)->append(" }, "_s);
	appendConstant(descriptor);
	$nc(this->stringBuilder)->append(", "_s)->append(visible)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	$var(ASMifier, asmifier, createASMifier(ASMifier::ANNOTATION_VISITOR, 0));
	$nc(this->text)->add($($nc(asmifier)->getText()));
	$nc(this->text)->add("}\n"_s);
	return asmifier;
}

void ASMifier::visitLineNumber(int32_t line, $Label* start) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->name)->append(".visitLineNumber("_s)->append(line)->append(", "_s);
	appendLabel(start);
	$nc(this->stringBuilder)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitMaxs(int32_t maxStack, int32_t maxLocals) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->name)->append(".visitMaxs("_s)->append(maxStack)->append(", "_s)->append(maxLocals)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

void ASMifier::visitMethodEnd() {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append(this->name)->append(ASMifier::VISIT_END);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

ASMifier* ASMifier::visitAnnotation($String* descriptor, bool visible) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("{\n"_s)->append(ASMifier::ANNOTATION_VISITOR0)->append(this->name)->append(".visitAnnotation("_s);
	appendConstant(descriptor);
	$nc(this->stringBuilder)->append(", "_s)->append(visible)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	$var(ASMifier, asmifier, createASMifier(ASMifier::ANNOTATION_VISITOR, 0));
	$nc(this->text)->add($($nc(asmifier)->getText()));
	$nc(this->text)->add("}\n"_s);
	return asmifier;
}

ASMifier* ASMifier::visitTypeAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	return visitTypeAnnotation("visitTypeAnnotation"_s, typeRef, typePath, descriptor, visible);
}

ASMifier* ASMifier::visitTypeAnnotation($String* method, int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	$useLocalCurrentObjectStackCache();
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("{\n"_s)->append(ASMifier::ANNOTATION_VISITOR0)->append(this->name)->append("."_s)->append(method)->append("("_s)->append(typeRef);
	if (typePath == nullptr) {
		$nc(this->stringBuilder)->append(", null, "_s);
	} else {
		$nc(this->stringBuilder)->append(", TypePath.fromString(\""_s)->append($of(typePath))->append("\"), "_s);
	}
	appendConstant(descriptor);
	$nc(this->stringBuilder)->append(", "_s)->append(visible)->append(");\n"_s);
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
	$var(ASMifier, asmifier, createASMifier(ASMifier::ANNOTATION_VISITOR, 0));
	$nc(this->text)->add($($nc(asmifier)->getText()));
	$nc(this->text)->add("}\n"_s);
	return asmifier;
}

void ASMifier::visitAttribute($Attribute* attribute) {
	$nc(this->stringBuilder)->setLength(0);
	$nc(this->stringBuilder)->append("// ATTRIBUTE "_s)->append($nc(attribute)->type)->append(u'\n');
	if ($instanceOf($ASMifierSupport, attribute)) {
		if (this->labelNames == nullptr) {
			$set(this, labelNames, $new($HashMap));
		}
		$nc(this->stringBuilder)->append("{\n"_s);
		$nc(($cast($ASMifierSupport, attribute)))->asmify(this->stringBuilder, "attribute"_s, this->labelNames);
		$nc(this->stringBuilder)->append(this->name)->append(".visitAttribute(attribute);\n"_s);
		$nc(this->stringBuilder)->append("}\n"_s);
	}
	$nc(this->text)->add($($nc(this->stringBuilder)->toString()));
}

ASMifier* ASMifier::createASMifier($String* visitorVariableName, int32_t annotationVisitorId) {
	return $new(ASMifier, this->api, visitorVariableName, annotationVisitorId);
}

void ASMifier::appendAccessFlags(int32_t accessFlags) {
	bool isEmpty = true;
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_PUBLIC)) != 0) {
		$nc(this->stringBuilder)->append("ACC_PUBLIC"_s);
		isEmpty = false;
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_PRIVATE)) != 0) {
		$nc(this->stringBuilder)->append("ACC_PRIVATE"_s);
		isEmpty = false;
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_PROTECTED)) != 0) {
		$nc(this->stringBuilder)->append("ACC_PROTECTED"_s);
		isEmpty = false;
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_FINAL)) != 0) {
		if (!isEmpty) {
			$nc(this->stringBuilder)->append(" | "_s);
		}
		if (((int32_t)(accessFlags & (uint32_t)ASMifier::ACCESS_MODULE)) == 0) {
			$nc(this->stringBuilder)->append("ACC_FINAL"_s);
		} else {
			$nc(this->stringBuilder)->append("ACC_TRANSITIVE"_s);
		}
		isEmpty = false;
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_STATIC)) != 0) {
		if (!isEmpty) {
			$nc(this->stringBuilder)->append(" | "_s);
		}
		$nc(this->stringBuilder)->append("ACC_STATIC"_s);
		isEmpty = false;
	}
	if (((int32_t)(accessFlags & (uint32_t)(($Opcodes::ACC_SYNCHRONIZED | $Opcodes::ACC_SUPER) | $Opcodes::ACC_TRANSITIVE))) != 0) {
		if (!isEmpty) {
			$nc(this->stringBuilder)->append(" | "_s);
		}
		if (((int32_t)(accessFlags & (uint32_t)ASMifier::ACCESS_CLASS)) == 0) {
			if (((int32_t)(accessFlags & (uint32_t)ASMifier::ACCESS_MODULE)) == 0) {
				$nc(this->stringBuilder)->append("ACC_SYNCHRONIZED"_s);
			} else {
				$nc(this->stringBuilder)->append("ACC_TRANSITIVE"_s);
			}
		} else {
			$nc(this->stringBuilder)->append("ACC_SUPER"_s);
		}
		isEmpty = false;
	}
	if (((int32_t)(accessFlags & (uint32_t)(($Opcodes::ACC_VOLATILE | $Opcodes::ACC_BRIDGE) | $Opcodes::ACC_STATIC_PHASE))) != 0) {
		if (!isEmpty) {
			$nc(this->stringBuilder)->append(" | "_s);
		}
		if (((int32_t)(accessFlags & (uint32_t)ASMifier::ACCESS_FIELD)) == 0) {
			if (((int32_t)(accessFlags & (uint32_t)ASMifier::ACCESS_MODULE)) == 0) {
				$nc(this->stringBuilder)->append("ACC_BRIDGE"_s);
			} else {
				$nc(this->stringBuilder)->append("ACC_STATIC_PHASE"_s);
			}
		} else {
			$nc(this->stringBuilder)->append("ACC_VOLATILE"_s);
		}
		isEmpty = false;
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_VARARGS)) != 0 && ((int32_t)(accessFlags & (uint32_t)(ASMifier::ACCESS_CLASS | ASMifier::ACCESS_FIELD))) == 0) {
		if (!isEmpty) {
			$nc(this->stringBuilder)->append(" | "_s);
		}
		$nc(this->stringBuilder)->append("ACC_VARARGS"_s);
		isEmpty = false;
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_TRANSIENT)) != 0 && ((int32_t)(accessFlags & (uint32_t)ASMifier::ACCESS_FIELD)) != 0) {
		if (!isEmpty) {
			$nc(this->stringBuilder)->append(" | "_s);
		}
		$nc(this->stringBuilder)->append("ACC_TRANSIENT"_s);
		isEmpty = false;
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_NATIVE)) != 0 && ((int32_t)(accessFlags & (uint32_t)(ASMifier::ACCESS_CLASS | ASMifier::ACCESS_FIELD))) == 0) {
		if (!isEmpty) {
			$nc(this->stringBuilder)->append(" | "_s);
		}
		$nc(this->stringBuilder)->append("ACC_NATIVE"_s);
		isEmpty = false;
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_ENUM)) != 0 && ((int32_t)(accessFlags & (uint32_t)((ASMifier::ACCESS_CLASS | ASMifier::ACCESS_FIELD) | ASMifier::ACCESS_INNER))) != 0) {
		if (!isEmpty) {
			$nc(this->stringBuilder)->append(" | "_s);
		}
		$nc(this->stringBuilder)->append("ACC_ENUM"_s);
		isEmpty = false;
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_ANNOTATION)) != 0 && ((int32_t)(accessFlags & (uint32_t)(ASMifier::ACCESS_CLASS | ASMifier::ACCESS_INNER))) != 0) {
		if (!isEmpty) {
			$nc(this->stringBuilder)->append(" | "_s);
		}
		$nc(this->stringBuilder)->append("ACC_ANNOTATION"_s);
		isEmpty = false;
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_ABSTRACT)) != 0) {
		if (!isEmpty) {
			$nc(this->stringBuilder)->append(" | "_s);
		}
		$nc(this->stringBuilder)->append("ACC_ABSTRACT"_s);
		isEmpty = false;
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_INTERFACE)) != 0) {
		if (!isEmpty) {
			$nc(this->stringBuilder)->append(" | "_s);
		}
		$nc(this->stringBuilder)->append("ACC_INTERFACE"_s);
		isEmpty = false;
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_STRICT)) != 0) {
		if (!isEmpty) {
			$nc(this->stringBuilder)->append(" | "_s);
		}
		$nc(this->stringBuilder)->append("ACC_STRICT"_s);
		isEmpty = false;
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_SYNTHETIC)) != 0) {
		if (!isEmpty) {
			$nc(this->stringBuilder)->append(" | "_s);
		}
		$nc(this->stringBuilder)->append("ACC_SYNTHETIC"_s);
		isEmpty = false;
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_DEPRECATED)) != 0) {
		if (!isEmpty) {
			$nc(this->stringBuilder)->append(" | "_s);
		}
		$nc(this->stringBuilder)->append("ACC_DEPRECATED"_s);
		isEmpty = false;
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_RECORD)) != 0) {
		if (!isEmpty) {
			$nc(this->stringBuilder)->append(" | "_s);
		}
		$nc(this->stringBuilder)->append("ACC_RECORD"_s);
		isEmpty = false;
	}
	if (((int32_t)(accessFlags & (uint32_t)($Opcodes::ACC_MANDATED | $Opcodes::ACC_MODULE))) != 0) {
		if (!isEmpty) {
			$nc(this->stringBuilder)->append(" | "_s);
		}
		if (((int32_t)(accessFlags & (uint32_t)ASMifier::ACCESS_CLASS)) == 0) {
			$nc(this->stringBuilder)->append("ACC_MANDATED"_s);
		} else {
			$nc(this->stringBuilder)->append("ACC_MODULE"_s);
		}
		isEmpty = false;
	}
	if (isEmpty) {
		$nc(this->stringBuilder)->append(u'0');
	}
}

void ASMifier::appendConstant(Object$* value) {
	$useLocalCurrentObjectStackCache();
	if (value == nullptr) {
		$nc(this->stringBuilder)->append("null"_s);
	} else if ($instanceOf($String, value)) {
		appendString(this->stringBuilder, $cast($String, value));
	} else if ($instanceOf($Type, value)) {
		$nc(this->stringBuilder)->append("Type.getType(\""_s);
		$nc(this->stringBuilder)->append($($nc(($cast($Type, value)))->getDescriptor()));
		$nc(this->stringBuilder)->append("\")"_s);
	} else if ($instanceOf($Handle, value)) {
		$nc(this->stringBuilder)->append("new Handle("_s);
		$var($Handle, handle, $cast($Handle, value));
		$init($Printer);
		$nc(this->stringBuilder)->append("Opcodes."_s)->append($nc($Printer::HANDLE_TAG)->get($nc(handle)->getTag()))->append(", \""_s);
		$nc(this->stringBuilder)->append($($nc(handle)->getOwner()))->append(ASMifier::COMMA);
		$nc(this->stringBuilder)->append($($nc(handle)->getName()))->append(ASMifier::COMMA);
		$nc(this->stringBuilder)->append($($nc(handle)->getDesc()))->append("\", "_s);
		$nc(this->stringBuilder)->append($nc(handle)->isInterface())->append(")"_s);
	} else if ($instanceOf($ConstantDynamic, value)) {
		$nc(this->stringBuilder)->append("new ConstantDynamic(\""_s);
		$var($ConstantDynamic, constantDynamic, $cast($ConstantDynamic, value));
		$nc(this->stringBuilder)->append($($nc(constantDynamic)->getName()))->append(ASMifier::COMMA);
		$nc(this->stringBuilder)->append($($nc(constantDynamic)->getDescriptor()))->append("\", "_s);
		appendConstant($($nc(constantDynamic)->getBootstrapMethod()));
		$nc(this->stringBuilder)->append(ASMifier::NEW_OBJECT_ARRAY);
		int32_t bootstrapMethodArgumentCount = $nc(constantDynamic)->getBootstrapMethodArgumentCount();
		for (int32_t i = 0; i < bootstrapMethodArgumentCount; ++i) {
			appendConstant($(constantDynamic->getBootstrapMethodArgument(i)));
			if (i != bootstrapMethodArgumentCount - 1) {
				$nc(this->stringBuilder)->append(", "_s);
			}
		}
		$nc(this->stringBuilder)->append("})"_s);
	} else if ($instanceOf($Byte, value)) {
		$nc(this->stringBuilder)->append("new Byte((byte)"_s)->append(value)->append(u')');
	} else if ($instanceOf($Boolean, value)) {
		$nc(this->stringBuilder)->append($nc(($cast($Boolean, value)))->booleanValue() ? "Boolean.TRUE"_s : "Boolean.FALSE"_s);
	} else if ($instanceOf($Short, value)) {
		$nc(this->stringBuilder)->append("new Short((short)"_s)->append(value)->append(u')');
	} else if ($instanceOf($Character, value)) {
		$nc(this->stringBuilder)->append("new Character((char)"_s)->append((int32_t)$nc(($cast($Character, value)))->charValue())->append(u')');
	} else if ($instanceOf($Integer, value)) {
		$nc(this->stringBuilder)->append("new Integer("_s)->append(value)->append(u')');
	} else if ($instanceOf($Float, value)) {
		$nc(this->stringBuilder)->append("new Float(\""_s)->append(value)->append("\")"_s);
	} else if ($instanceOf($Long, value)) {
		$nc(this->stringBuilder)->append("new Long("_s)->append(value)->append("L)"_s);
	} else if ($instanceOf($Double, value)) {
		$nc(this->stringBuilder)->append("new Double(\""_s)->append(value)->append("\")"_s);
	} else if ($instanceOf($bytes, value)) {
		$var($bytes, byteArray, $cast($bytes, value));
		$nc(this->stringBuilder)->append("new byte[] {"_s);
		for (int32_t i = 0; i < $nc(byteArray)->length; ++i) {
			$nc(this->stringBuilder)->append(i == 0 ? ""_s : ","_s)->append((int32_t)byteArray->get(i));
		}
		$nc(this->stringBuilder)->append(u'}');
	} else if ($instanceOf($booleans, value)) {
		$var($booleans, booleanArray, $cast($booleans, value));
		$nc(this->stringBuilder)->append("new boolean[] {"_s);
		for (int32_t i = 0; i < $nc(booleanArray)->length; ++i) {
			$nc(this->stringBuilder)->append(i == 0 ? ""_s : ","_s)->append(booleanArray->get(i));
		}
		$nc(this->stringBuilder)->append(u'}');
	} else if ($instanceOf($shorts, value)) {
		$var($shorts, shortArray, $cast($shorts, value));
		$nc(this->stringBuilder)->append("new short[] {"_s);
		for (int32_t i = 0; i < $nc(shortArray)->length; ++i) {
			$nc(this->stringBuilder)->append(i == 0 ? ""_s : ","_s)->append("(short)"_s)->append((int32_t)shortArray->get(i));
		}
		$nc(this->stringBuilder)->append(u'}');
	} else if ($instanceOf($chars, value)) {
		$var($chars, charArray, $cast($chars, value));
		$nc(this->stringBuilder)->append("new char[] {"_s);
		for (int32_t i = 0; i < $nc(charArray)->length; ++i) {
			$nc(this->stringBuilder)->append(i == 0 ? ""_s : ","_s)->append("(char)"_s)->append((int32_t)charArray->get(i));
		}
		$nc(this->stringBuilder)->append(u'}');
	} else if ($instanceOf($ints, value)) {
		$var($ints, intArray, $cast($ints, value));
		$nc(this->stringBuilder)->append("new int[] {"_s);
		for (int32_t i = 0; i < $nc(intArray)->length; ++i) {
			$nc(this->stringBuilder)->append(i == 0 ? ""_s : ","_s)->append(intArray->get(i));
		}
		$nc(this->stringBuilder)->append(u'}');
	} else if ($instanceOf($longs, value)) {
		$var($longs, longArray, $cast($longs, value));
		$nc(this->stringBuilder)->append("new long[] {"_s);
		for (int32_t i = 0; i < $nc(longArray)->length; ++i) {
			$nc(this->stringBuilder)->append(i == 0 ? ""_s : ","_s)->append(longArray->get(i))->append(u'L');
		}
		$nc(this->stringBuilder)->append(u'}');
	} else if ($instanceOf($floats, value)) {
		$var($floats, floatArray, $cast($floats, value));
		$nc(this->stringBuilder)->append("new float[] {"_s);
		for (int32_t i = 0; i < $nc(floatArray)->length; ++i) {
			$nc(this->stringBuilder)->append(i == 0 ? ""_s : ","_s)->append(floatArray->get(i))->append(u'f');
		}
		$nc(this->stringBuilder)->append(u'}');
	} else if ($instanceOf($doubles, value)) {
		$var($doubles, doubleArray, $cast($doubles, value));
		$nc(this->stringBuilder)->append("new double[] {"_s);
		for (int32_t i = 0; i < $nc(doubleArray)->length; ++i) {
			$nc(this->stringBuilder)->append(i == 0 ? ""_s : ","_s)->append(doubleArray->get(i))->append(u'd');
		}
		$nc(this->stringBuilder)->append(u'}');
	}
}

void ASMifier::declareFrameTypes(int32_t numTypes, $ObjectArray* frameTypes) {
	for (int32_t i = 0; i < numTypes; ++i) {
		if ($instanceOf($Label, $nc(frameTypes)->get(i))) {
			declareLabel($cast($Label, frameTypes->get(i)));
		}
	}
}

void ASMifier::appendFrameTypes(int32_t numTypes, $ObjectArray* frameTypes) {
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < numTypes; ++i) {
		if (i > 0) {
			$nc(this->stringBuilder)->append(", "_s);
		}
		if ($instanceOf($String, $nc(frameTypes)->get(i))) {
			appendConstant(frameTypes->get(i));
		} else if ($instanceOf($Integer, frameTypes->get(i))) {
			$nc(this->stringBuilder)->append($cast($String, $($nc(ASMifier::FRAME_TYPES)->get($nc(($cast($Integer, frameTypes->get(i))))->intValue()))));
		} else {
			appendLabel($cast($Label, frameTypes->get(i)));
		}
	}
}

void ASMifier::declareLabel($Label* label) {
	$useLocalCurrentObjectStackCache();
	if (this->labelNames == nullptr) {
		$set(this, labelNames, $new($HashMap));
	}
	$var($String, labelName, $cast($String, $nc(this->labelNames)->get(label)));
	if (labelName == nullptr) {
		$assign(labelName, $str({"label"_s, $$str($nc(this->labelNames)->size())}));
		$nc(this->labelNames)->put(label, labelName);
		$nc(this->stringBuilder)->append("Label "_s)->append(labelName)->append(" = new Label();\n"_s);
	}
}

void ASMifier::appendLabel($Label* label) {
	$nc(this->stringBuilder)->append($cast($String, $($nc(this->labelNames)->get(label))));
}

void clinit$ASMifier($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(ASMifier::USAGE, "Prints the ASM code to generate the given class.\nUsage: ASMifier [-debug] <fully qualified class name or class file name>"_s);
	$assignStatic(ASMifier::ANNOTATION_VISITOR, "annotationVisitor"_s);
	$assignStatic(ASMifier::ANNOTATION_VISITOR0, "annotationVisitor0 = "_s);
	$assignStatic(ASMifier::COMMA, "\", \""_s);
	$assignStatic(ASMifier::END_ARRAY, " });\n"_s);
	$assignStatic(ASMifier::END_PARAMETERS, ");\n\n"_s);
	$assignStatic(ASMifier::NEW_OBJECT_ARRAY, ", new Object[] {"_s);
	$assignStatic(ASMifier::VISIT_END, ".visitEnd();\n"_s);
	$assignStatic(ASMifier::FRAME_TYPES, $Collections::unmodifiableList($($Arrays::asList($$new($StringArray, {
		"Opcodes.TOP"_s,
		"Opcodes.INTEGER"_s,
		"Opcodes.FLOAT"_s,
		"Opcodes.DOUBLE"_s,
		"Opcodes.LONG"_s,
		"Opcodes.NULL"_s,
		"Opcodes.UNINITIALIZED_THIS"_s
	})))));
	{
		$var($HashMap, classVersions, $new($HashMap));
		classVersions->put($($Integer::valueOf($Opcodes::V1_1)), "V1_1"_s);
		classVersions->put($($Integer::valueOf($Opcodes::V1_2)), "V1_2"_s);
		classVersions->put($($Integer::valueOf($Opcodes::V1_3)), "V1_3"_s);
		classVersions->put($($Integer::valueOf($Opcodes::V1_4)), "V1_4"_s);
		classVersions->put($($Integer::valueOf($Opcodes::V1_5)), "V1_5"_s);
		classVersions->put($($Integer::valueOf($Opcodes::V1_6)), "V1_6"_s);
		classVersions->put($($Integer::valueOf($Opcodes::V1_7)), "V1_7"_s);
		classVersions->put($($Integer::valueOf($Opcodes::V1_8)), "V1_8"_s);
		classVersions->put($($Integer::valueOf($Opcodes::V9)), "V9"_s);
		classVersions->put($($Integer::valueOf($Opcodes::V10)), "V10"_s);
		classVersions->put($($Integer::valueOf($Opcodes::V11)), "V11"_s);
		classVersions->put($($Integer::valueOf($Opcodes::V12)), "V12"_s);
		classVersions->put($($Integer::valueOf($Opcodes::V13)), "V13"_s);
		classVersions->put($($Integer::valueOf($Opcodes::V14)), "V14"_s);
		classVersions->put($($Integer::valueOf($Opcodes::V15)), "V15"_s);
		$assignStatic(ASMifier::CLASS_VERSIONS, $Collections::unmodifiableMap(classVersions));
	}
}

ASMifier::ASMifier() {
}

$Class* ASMifier::load$($String* name, bool initialize) {
	$loadClass(ASMifier, name, initialize, &_ASMifier_ClassInfo_, clinit$ASMifier, allocate$ASMifier);
	return class$;
}

$Class* ASMifier::class$ = nullptr;

					} // util
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk