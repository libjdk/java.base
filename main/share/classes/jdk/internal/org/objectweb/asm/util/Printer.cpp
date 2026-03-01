#include <jdk/internal/org/objectweb/asm/util/Printer.h>

#include <java/io/FileInputStream.h>
#include <java/io/InputStream.h>
#include <java/io/PrintWriter.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jdk/internal/org/objectweb/asm/Attribute.h>
#include <jdk/internal/org/objectweb/asm/ClassReader.h>
#include <jdk/internal/org/objectweb/asm/ClassVisitor.h>
#include <jdk/internal/org/objectweb/asm/Handle.h>
#include <jdk/internal/org/objectweb/asm/Label.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/TypePath.h>
#include <jdk/internal/org/objectweb/asm/util/TraceClassVisitor.h>
#include <jcpp.h>

#undef HANDLE_TAG
#undef INVOKEINTERFACE
#undef OPCODES
#undef SKIP_DEBUG
#undef TYPES
#undef UNSUPPORTED_OPERATION

using $LabelArray = $Array<::jdk::internal::org::objectweb::asm$::Label>;
using $FileInputStream = ::java::io::FileInputStream;
using $InputStream = ::java::io::InputStream;
using $PrintWriter = ::java::io::PrintWriter;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Attribute = ::jdk::internal::org::objectweb::asm$::Attribute;
using $ClassReader = ::jdk::internal::org::objectweb::asm$::ClassReader;
using $ClassVisitor = ::jdk::internal::org::objectweb::asm$::ClassVisitor;
using $Handle = ::jdk::internal::org::objectweb::asm$::Handle;
using $Label = ::jdk::internal::org::objectweb::asm$::Label;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $TypePath = ::jdk::internal::org::objectweb::asm$::TypePath;
using $TraceClassVisitor = ::jdk::internal::org::objectweb::asm$::util::TraceClassVisitor;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace util {

$CompoundAttribute _Printer_MethodAnnotations_visitMethodInsn46[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Printer_MethodAnnotations_visitPermittedSubclassExperimental59[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _Printer_FieldInfo_[] = {
	{"OPCODES", "[Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Printer, OPCODES)},
	{"TYPES", "[Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Printer, TYPES)},
	{"HANDLE_TAG", "[Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Printer, HANDLE_TAG)},
	{"UNSUPPORTED_OPERATION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Printer, UNSUPPORTED_OPERATION)},
	{"api", "I", nullptr, $PROTECTED | $FINAL, $field(Printer, api)},
	{"stringBuilder", "Ljava/lang/StringBuilder;", nullptr, $PROTECTED | $FINAL, $field(Printer, stringBuilder)},
	{"text", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Object;>;", $PUBLIC | $FINAL, $field(Printer, text)},
	{}
};

$MethodInfo _Printer_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PROTECTED, $method(Printer, init$, void, int32_t)},
	{"appendString", "(Ljava/lang/StringBuilder;Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Printer, appendString, void, $StringBuilder*, $String*)},
	{"getText", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/Object;>;", $PUBLIC, $virtualMethod(Printer, getText, $List*)},
	{"main", "([Ljava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/util/Printer;Ljava/io/PrintWriter;Ljava/io/PrintWriter;)V", nullptr, $STATIC, $staticMethod(Printer, main, void, $StringArray*, $String*, Printer*, $PrintWriter*, $PrintWriter*), "java.io.IOException"},
	{"print", "(Ljava/io/PrintWriter;)V", nullptr, $PUBLIC, $virtualMethod(Printer, print, void, $PrintWriter*)},
	{"printList", "(Ljava/io/PrintWriter;Ljava/util/List;)V", "(Ljava/io/PrintWriter;Ljava/util/List<*>;)V", $STATIC, $staticMethod(Printer, printList, void, $PrintWriter*, $List*)},
	{"visit", "(IILjava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visit, void, int32_t, int32_t, $String*, $String*, $String*, $StringArray*)},
	{"visit", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visit, void, $String*, Object$*)},
	{"visitAnnotableParameterCount", "(IZ)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(Printer, visitAnnotableParameterCount, Printer*, int32_t, bool)},
	{"visitAnnotation", "(Ljava/lang/String;Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitAnnotation, Printer*, $String*, $String*)},
	{"visitAnnotationDefault", "()Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitAnnotationDefault, Printer*)},
	{"visitAnnotationEnd", "()V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitAnnotationEnd, void)},
	{"visitArray", "(Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitArray, Printer*, $String*)},
	{"visitClassAnnotation", "(Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitClassAnnotation, Printer*, $String*, bool)},
	{"visitClassAttribute", "(Ljdk/internal/org/objectweb/asm/Attribute;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitClassAttribute, void, $Attribute*)},
	{"visitClassEnd", "()V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitClassEnd, void)},
	{"visitClassTypeAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(Printer, visitClassTypeAnnotation, Printer*, int32_t, $TypePath*, $String*, bool)},
	{"visitCode", "()V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitCode, void)},
	{"visitEnum", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitEnum, void, $String*, $String*, $String*)},
	{"visitExport", "(Ljava/lang/String;I[Ljava/lang/String;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(Printer, visitExport, void, $String*, int32_t, $StringArray*)},
	{"visitField", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Object;)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitField, Printer*, int32_t, $String*, $String*, $String*, Object$*)},
	{"visitFieldAnnotation", "(Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitFieldAnnotation, Printer*, $String*, bool)},
	{"visitFieldAttribute", "(Ljdk/internal/org/objectweb/asm/Attribute;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitFieldAttribute, void, $Attribute*)},
	{"visitFieldEnd", "()V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitFieldEnd, void)},
	{"visitFieldInsn", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitFieldInsn, void, int32_t, $String*, $String*, $String*)},
	{"visitFieldTypeAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(Printer, visitFieldTypeAnnotation, Printer*, int32_t, $TypePath*, $String*, bool)},
	{"visitFrame", "(II[Ljava/lang/Object;I[Ljava/lang/Object;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitFrame, void, int32_t, int32_t, $ObjectArray*, int32_t, $ObjectArray*)},
	{"visitIincInsn", "(II)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitIincInsn, void, int32_t, int32_t)},
	{"visitInnerClass", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitInnerClass, void, $String*, $String*, $String*, int32_t)},
	{"visitInsn", "(I)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitInsn, void, int32_t)},
	{"visitInsnAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(Printer, visitInsnAnnotation, Printer*, int32_t, $TypePath*, $String*, bool)},
	{"visitIntInsn", "(II)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitIntInsn, void, int32_t, int32_t)},
	{"visitInvokeDynamicInsn", "(Ljava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/Handle;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT | $ABSTRACT, $virtualMethod(Printer, visitInvokeDynamicInsn, void, $String*, $String*, $Handle*, $ObjectArray*)},
	{"visitJumpInsn", "(ILjdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitJumpInsn, void, int32_t, $Label*)},
	{"visitLabel", "(Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitLabel, void, $Label*)},
	{"visitLdcInsn", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitLdcInsn, void, Object$*)},
	{"visitLineNumber", "(ILjdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitLineNumber, void, int32_t, $Label*)},
	{"visitLocalVariable", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/Label;Ljdk/internal/org/objectweb/asm/Label;I)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitLocalVariable, void, $String*, $String*, $String*, $Label*, $Label*, int32_t)},
	{"visitLocalVariableAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;[Ljdk/internal/org/objectweb/asm/Label;[Ljdk/internal/org/objectweb/asm/Label;[ILjava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(Printer, visitLocalVariableAnnotation, Printer*, int32_t, $TypePath*, $LabelArray*, $LabelArray*, $ints*, $String*, bool)},
	{"visitLookupSwitchInsn", "(Ljdk/internal/org/objectweb/asm/Label;[I[Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitLookupSwitchInsn, void, $Label*, $ints*, $LabelArray*)},
	{"visitMainClass", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Printer, visitMainClass, void, $String*)},
	{"visitMaxs", "(II)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitMaxs, void, int32_t, int32_t)},
	{"visitMethod", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitMethod, Printer*, int32_t, $String*, $String*, $String*, $StringArray*)},
	{"visitMethodAnnotation", "(Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitMethodAnnotation, Printer*, $String*, bool)},
	{"visitMethodAttribute", "(Ljdk/internal/org/objectweb/asm/Attribute;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitMethodAttribute, void, $Attribute*)},
	{"visitMethodEnd", "()V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitMethodEnd, void)},
	{"visitMethodInsn", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Printer, visitMethodInsn, void, int32_t, $String*, $String*, $String*), nullptr, nullptr, _Printer_MethodAnnotations_visitMethodInsn46},
	{"visitMethodInsn", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)V", nullptr, $PUBLIC, $virtualMethod(Printer, visitMethodInsn, void, int32_t, $String*, $String*, $String*, bool)},
	{"visitMethodTypeAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(Printer, visitMethodTypeAnnotation, Printer*, int32_t, $TypePath*, $String*, bool)},
	{"visitModule", "(Ljava/lang/String;ILjava/lang/String;)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(Printer, visitModule, Printer*, $String*, int32_t, $String*)},
	{"visitModuleEnd", "()V", nullptr, $PUBLIC, $virtualMethod(Printer, visitModuleEnd, void)},
	{"visitMultiANewArrayInsn", "(Ljava/lang/String;I)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitMultiANewArrayInsn, void, $String*, int32_t)},
	{"visitNestHost", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Printer, visitNestHost, void, $String*)},
	{"visitNestMember", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Printer, visitNestMember, void, $String*)},
	{"visitOpen", "(Ljava/lang/String;I[Ljava/lang/String;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(Printer, visitOpen, void, $String*, int32_t, $StringArray*)},
	{"visitOuterClass", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitOuterClass, void, $String*, $String*, $String*)},
	{"visitPackage", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Printer, visitPackage, void, $String*)},
	{"visitParameter", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $virtualMethod(Printer, visitParameter, void, $String*, int32_t)},
	{"visitParameterAnnotation", "(ILjava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitParameterAnnotation, Printer*, int32_t, $String*, bool)},
	{"visitPermittedSubclassExperimental", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Printer, visitPermittedSubclassExperimental, void, $String*), nullptr, nullptr, _Printer_MethodAnnotations_visitPermittedSubclassExperimental59},
	{"visitProvide", "(Ljava/lang/String;[Ljava/lang/String;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(Printer, visitProvide, void, $String*, $StringArray*)},
	{"visitRecordComponent", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(Printer, visitRecordComponent, Printer*, $String*, $String*, $String*)},
	{"visitRecordComponentAnnotation", "(Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(Printer, visitRecordComponentAnnotation, Printer*, $String*, bool)},
	{"visitRecordComponentAttribute", "(Ljdk/internal/org/objectweb/asm/Attribute;)V", nullptr, $PUBLIC, $virtualMethod(Printer, visitRecordComponentAttribute, void, $Attribute*)},
	{"visitRecordComponentEnd", "()V", nullptr, $PUBLIC, $virtualMethod(Printer, visitRecordComponentEnd, void)},
	{"visitRecordComponentTypeAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(Printer, visitRecordComponentTypeAnnotation, Printer*, int32_t, $TypePath*, $String*, bool)},
	{"visitRequire", "(Ljava/lang/String;ILjava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Printer, visitRequire, void, $String*, int32_t, $String*)},
	{"visitSource", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitSource, void, $String*, $String*)},
	{"visitTableSwitchInsn", "(IILjdk/internal/org/objectweb/asm/Label;[Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC | $TRANSIENT | $ABSTRACT, $virtualMethod(Printer, visitTableSwitchInsn, void, int32_t, int32_t, $Label*, $LabelArray*)},
	{"visitTryCatchAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/util/Printer;", nullptr, $PUBLIC, $virtualMethod(Printer, visitTryCatchAnnotation, Printer*, int32_t, $TypePath*, $String*, bool)},
	{"visitTryCatchBlock", "(Ljdk/internal/org/objectweb/asm/Label;Ljdk/internal/org/objectweb/asm/Label;Ljdk/internal/org/objectweb/asm/Label;Ljava/lang/String;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitTryCatchBlock, void, $Label*, $Label*, $Label*, $String*)},
	{"visitTypeInsn", "(ILjava/lang/String;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitTypeInsn, void, int32_t, $String*)},
	{"visitUse", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Printer, visitUse, void, $String*)},
	{"visitVarInsn", "(II)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Printer, visitVarInsn, void, int32_t, int32_t)},
	{}
};

$ClassInfo _Printer_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"jdk.internal.org.objectweb.asm.util.Printer",
	"java.lang.Object",
	nullptr,
	_Printer_FieldInfo_,
	_Printer_MethodInfo_
};

$Object* allocate$Printer($Class* clazz) {
	return $of($alloc(Printer));
}

$StringArray* Printer::OPCODES = nullptr;
$StringArray* Printer::TYPES = nullptr;
$StringArray* Printer::HANDLE_TAG = nullptr;
$String* Printer::UNSUPPORTED_OPERATION = nullptr;

void Printer::init$(int32_t api) {
	this->api = api;
	$set(this, stringBuilder, $new($StringBuilder));
	$set(this, text, $new($ArrayList));
}

Printer* Printer::visitModule($String* name, int32_t access, $String* version) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
	$shouldNotReachHere();
}

void Printer::visitNestHost($String* nestHost) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
}

Printer* Printer::visitClassTypeAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
	$shouldNotReachHere();
}

void Printer::visitNestMember($String* nestMember) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
}

void Printer::visitPermittedSubclassExperimental($String* permittedSubclass) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
}

Printer* Printer::visitRecordComponent($String* name, $String* descriptor, $String* signature) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
	$shouldNotReachHere();
}

void Printer::visitMainClass($String* mainClass) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
}

void Printer::visitPackage($String* packaze) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
}

void Printer::visitRequire($String* module, int32_t access, $String* version) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
}

void Printer::visitExport($String* packaze, int32_t access, $StringArray* modules) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
}

void Printer::visitOpen($String* packaze, int32_t access, $StringArray* modules) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
}

void Printer::visitUse($String* service) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
}

void Printer::visitProvide($String* service, $StringArray* providers) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
}

void Printer::visitModuleEnd() {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
}

Printer* Printer::visitRecordComponentAnnotation($String* descriptor, bool visible) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
	$shouldNotReachHere();
}

Printer* Printer::visitRecordComponentTypeAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
	$shouldNotReachHere();
}

void Printer::visitRecordComponentAttribute($Attribute* attribute) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
}

void Printer::visitRecordComponentEnd() {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
}

Printer* Printer::visitFieldTypeAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
	$shouldNotReachHere();
}

void Printer::visitParameter($String* name, int32_t access) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
}

Printer* Printer::visitMethodTypeAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
	$shouldNotReachHere();
}

Printer* Printer::visitAnnotableParameterCount(int32_t parameterCount, bool visible) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
	$shouldNotReachHere();
}

void Printer::visitMethodInsn(int32_t opcode, $String* owner, $String* name, $String* descriptor) {
	visitMethodInsn(opcode, owner, name, descriptor, opcode == $Opcodes::INVOKEINTERFACE);
}

void Printer::visitMethodInsn(int32_t opcode, $String* owner, $String* name, $String* descriptor, bool isInterface) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
}

Printer* Printer::visitInsnAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
	$shouldNotReachHere();
}

Printer* Printer::visitTryCatchAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
	$shouldNotReachHere();
}

Printer* Printer::visitLocalVariableAnnotation(int32_t typeRef, $TypePath* typePath, $LabelArray* start, $LabelArray* end, $ints* index, $String* descriptor, bool visible) {
	$throwNew($UnsupportedOperationException, Printer::UNSUPPORTED_OPERATION);
	$shouldNotReachHere();
}

$List* Printer::getText() {
	return this->text;
}

void Printer::print($PrintWriter* printWriter) {
	printList(printWriter, this->text);
}

void Printer::printList($PrintWriter* printWriter, $List* list) {
	$init(Printer);
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc(list)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Object, o, i$->next());
			{
				if ($instanceOf($List, o)) {
					printList(printWriter, $cast($List, o));
				} else {
					$nc(printWriter)->print($($nc($of(o))->toString()));
				}
			}
		}
	}
}

void Printer::appendString($StringBuilder* stringBuilder, $String* string) {
	$init(Printer);
	$useLocalCurrentObjectStackCache();
	$nc(stringBuilder)->append(u'\"');
	for (int32_t i = 0; i < $nc(string)->length(); ++i) {
		char16_t c = string->charAt(i);
		if (c == u'\n') {
			stringBuilder->append("\\n"_s);
		} else if (c == u'\r') {
			stringBuilder->append("\\r"_s);
		} else if (c == u'\\') {
			stringBuilder->append("\\\\"_s);
		} else if (c == u'\"') {
			stringBuilder->append("\\\""_s);
		} else if (c < 32 || c > 127) {
			stringBuilder->append("\\u"_s);
			if (c < 16) {
				stringBuilder->append("000"_s);
			} else if (c < 256) {
				stringBuilder->append("00"_s);
			} else if (c < 4096) {
				stringBuilder->append(u'0');
			}
			stringBuilder->append($($Integer::toString(c, 16)));
		} else {
			stringBuilder->append(c);
		}
	}
	stringBuilder->append(u'\"');
}

void Printer::main($StringArray* args, $String* usage, Printer* printer, $PrintWriter* output, $PrintWriter* logger) {
	$init(Printer);
	$useLocalCurrentObjectStackCache();
	if ($nc(args)->length < 1 || $nc(args)->length > 2 || ($nc($nc(args)->get(0))->equals("-debug"_s) && args->length != 2)) {
		$nc(logger)->println(usage);
		return;
	}
	$var($TraceClassVisitor, traceClassVisitor, $new($TraceClassVisitor, nullptr, printer, output));
	$var($String, className, nullptr);
	int32_t parsingOptions = 0;
	if ($nc($nc(args)->get(0))->equals("-debug"_s)) {
		$assign(className, args->get(1));
		parsingOptions = $ClassReader::SKIP_DEBUG;
	} else {
		$assign(className, args->get(0));
		parsingOptions = 0;
	}
	bool var$1 = $nc(className)->endsWith(".class"_s);
	bool var$0 = var$1 || $nc(className)->indexOf((int32_t)u'\\') != -1;
	if (var$0 || $nc(className)->indexOf((int32_t)u'/') != -1) {
		$var($InputStream, inputStream, $new($FileInputStream, className));
		$$new($ClassReader, inputStream)->accept(traceClassVisitor, parsingOptions);
	} else {
		$$new($ClassReader, className)->accept(traceClassVisitor, parsingOptions);
	}
}

void clinit$Printer($Class* class$) {
	$assignStatic(Printer::UNSUPPORTED_OPERATION, "Must be overridden"_s);
	$assignStatic(Printer::OPCODES, $new($StringArray, {
		"NOP"_s,
		"ACONST_NULL"_s,
		"ICONST_M1"_s,
		"ICONST_0"_s,
		"ICONST_1"_s,
		"ICONST_2"_s,
		"ICONST_3"_s,
		"ICONST_4"_s,
		"ICONST_5"_s,
		"LCONST_0"_s,
		"LCONST_1"_s,
		"FCONST_0"_s,
		"FCONST_1"_s,
		"FCONST_2"_s,
		"DCONST_0"_s,
		"DCONST_1"_s,
		"BIPUSH"_s,
		"SIPUSH"_s,
		"LDC"_s,
		"LDC_W"_s,
		"LDC2_W"_s,
		"ILOAD"_s,
		"LLOAD"_s,
		"FLOAD"_s,
		"DLOAD"_s,
		"ALOAD"_s,
		"ILOAD_0"_s,
		"ILOAD_1"_s,
		"ILOAD_2"_s,
		"ILOAD_3"_s,
		"LLOAD_0"_s,
		"LLOAD_1"_s,
		"LLOAD_2"_s,
		"LLOAD_3"_s,
		"FLOAD_0"_s,
		"FLOAD_1"_s,
		"FLOAD_2"_s,
		"FLOAD_3"_s,
		"DLOAD_0"_s,
		"DLOAD_1"_s,
		"DLOAD_2"_s,
		"DLOAD_3"_s,
		"ALOAD_0"_s,
		"ALOAD_1"_s,
		"ALOAD_2"_s,
		"ALOAD_3"_s,
		"IALOAD"_s,
		"LALOAD"_s,
		"FALOAD"_s,
		"DALOAD"_s,
		"AALOAD"_s,
		"BALOAD"_s,
		"CALOAD"_s,
		"SALOAD"_s,
		"ISTORE"_s,
		"LSTORE"_s,
		"FSTORE"_s,
		"DSTORE"_s,
		"ASTORE"_s,
		"ISTORE_0"_s,
		"ISTORE_1"_s,
		"ISTORE_2"_s,
		"ISTORE_3"_s,
		"LSTORE_0"_s,
		"LSTORE_1"_s,
		"LSTORE_2"_s,
		"LSTORE_3"_s,
		"FSTORE_0"_s,
		"FSTORE_1"_s,
		"FSTORE_2"_s,
		"FSTORE_3"_s,
		"DSTORE_0"_s,
		"DSTORE_1"_s,
		"DSTORE_2"_s,
		"DSTORE_3"_s,
		"ASTORE_0"_s,
		"ASTORE_1"_s,
		"ASTORE_2"_s,
		"ASTORE_3"_s,
		"IASTORE"_s,
		"LASTORE"_s,
		"FASTORE"_s,
		"DASTORE"_s,
		"AASTORE"_s,
		"BASTORE"_s,
		"CASTORE"_s,
		"SASTORE"_s,
		"POP"_s,
		"POP2"_s,
		"DUP"_s,
		"DUP_X1"_s,
		"DUP_X2"_s,
		"DUP2"_s,
		"DUP2_X1"_s,
		"DUP2_X2"_s,
		"SWAP"_s,
		"IADD"_s,
		"LADD"_s,
		"FADD"_s,
		"DADD"_s,
		"ISUB"_s,
		"LSUB"_s,
		"FSUB"_s,
		"DSUB"_s,
		"IMUL"_s,
		"LMUL"_s,
		"FMUL"_s,
		"DMUL"_s,
		"IDIV"_s,
		"LDIV"_s,
		"FDIV"_s,
		"DDIV"_s,
		"IREM"_s,
		"LREM"_s,
		"FREM"_s,
		"DREM"_s,
		"INEG"_s,
		"LNEG"_s,
		"FNEG"_s,
		"DNEG"_s,
		"ISHL"_s,
		"LSHL"_s,
		"ISHR"_s,
		"LSHR"_s,
		"IUSHR"_s,
		"LUSHR"_s,
		"IAND"_s,
		"LAND"_s,
		"IOR"_s,
		"LOR"_s,
		"IXOR"_s,
		"LXOR"_s,
		"IINC"_s,
		"I2L"_s,
		"I2F"_s,
		"I2D"_s,
		"L2I"_s,
		"L2F"_s,
		"L2D"_s,
		"F2I"_s,
		"F2L"_s,
		"F2D"_s,
		"D2I"_s,
		"D2L"_s,
		"D2F"_s,
		"I2B"_s,
		"I2C"_s,
		"I2S"_s,
		"LCMP"_s,
		"FCMPL"_s,
		"FCMPG"_s,
		"DCMPL"_s,
		"DCMPG"_s,
		"IFEQ"_s,
		"IFNE"_s,
		"IFLT"_s,
		"IFGE"_s,
		"IFGT"_s,
		"IFLE"_s,
		"IF_ICMPEQ"_s,
		"IF_ICMPNE"_s,
		"IF_ICMPLT"_s,
		"IF_ICMPGE"_s,
		"IF_ICMPGT"_s,
		"IF_ICMPLE"_s,
		"IF_ACMPEQ"_s,
		"IF_ACMPNE"_s,
		"GOTO"_s,
		"JSR"_s,
		"RET"_s,
		"TABLESWITCH"_s,
		"LOOKUPSWITCH"_s,
		"IRETURN"_s,
		"LRETURN"_s,
		"FRETURN"_s,
		"DRETURN"_s,
		"ARETURN"_s,
		"RETURN"_s,
		"GETSTATIC"_s,
		"PUTSTATIC"_s,
		"GETFIELD"_s,
		"PUTFIELD"_s,
		"INVOKEVIRTUAL"_s,
		"INVOKESPECIAL"_s,
		"INVOKESTATIC"_s,
		"INVOKEINTERFACE"_s,
		"INVOKEDYNAMIC"_s,
		"NEW"_s,
		"NEWARRAY"_s,
		"ANEWARRAY"_s,
		"ARRAYLENGTH"_s,
		"ATHROW"_s,
		"CHECKCAST"_s,
		"INSTANCEOF"_s,
		"MONITORENTER"_s,
		"MONITOREXIT"_s,
		"WIDE"_s,
		"MULTIANEWARRAY"_s,
		"IFNULL"_s,
		"IFNONNULL"_s
	}));
	$assignStatic(Printer::TYPES, $new($StringArray, {
		""_s,
		""_s,
		""_s,
		""_s,
		"T_BOOLEAN"_s,
		"T_CHAR"_s,
		"T_FLOAT"_s,
		"T_DOUBLE"_s,
		"T_BYTE"_s,
		"T_SHORT"_s,
		"T_INT"_s,
		"T_LONG"_s
	}));
	$assignStatic(Printer::HANDLE_TAG, $new($StringArray, {
		""_s,
		"H_GETFIELD"_s,
		"H_GETSTATIC"_s,
		"H_PUTFIELD"_s,
		"H_PUTSTATIC"_s,
		"H_INVOKEVIRTUAL"_s,
		"H_INVOKESTATIC"_s,
		"H_INVOKESPECIAL"_s,
		"H_NEWINVOKESPECIAL"_s,
		"H_INVOKEINTERFACE"_s
	}));
}

Printer::Printer() {
}

$Class* Printer::load$($String* name, bool initialize) {
	$loadClass(Printer, name, initialize, &_Printer_ClassInfo_, clinit$Printer, allocate$Printer);
	return class$;
}

$Class* Printer::class$ = nullptr;

					} // util
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk