#include <jdk/internal/org/objectweb/asm/util/CheckClassAdapter.h>

#include <java/io/FileInputStream.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/PrintWriter.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/IllegalStateException.h>
#include <java/util/ArrayList.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <jdk/internal/org/objectweb/asm/AnnotationVisitor.h>
#include <jdk/internal/org/objectweb/asm/Attribute.h>
#include <jdk/internal/org/objectweb/asm/ClassReader.h>
#include <jdk/internal/org/objectweb/asm/ClassVisitor.h>
#include <jdk/internal/org/objectweb/asm/FieldVisitor.h>
#include <jdk/internal/org/objectweb/asm/MethodVisitor.h>
#include <jdk/internal/org/objectweb/asm/ModuleVisitor.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/RecordComponentVisitor.h>
#include <jdk/internal/org/objectweb/asm/Type.h>
#include <jdk/internal/org/objectweb/asm/TypePath.h>
#include <jdk/internal/org/objectweb/asm/TypeReference.h>
#include <jdk/internal/org/objectweb/asm/tree/AbstractInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/ClassNode.h>
#include <jdk/internal/org/objectweb/asm/tree/InsnList.h>
#include <jdk/internal/org/objectweb/asm/tree/MethodNode.h>
#include <jdk/internal/org/objectweb/asm/tree/TryCatchBlockNode.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/Analyzer.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/AnalyzerException.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/BasicValue.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/Frame.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/Interpreter.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/SimpleVerifier.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/Value.h>
#include <jdk/internal/org/objectweb/asm/util/CheckAnnotationAdapter.h>
#include <jdk/internal/org/objectweb/asm/util/CheckClassAdapter$1.h>
#include <jdk/internal/org/objectweb/asm/util/CheckFieldAdapter.h>
#include <jdk/internal/org/objectweb/asm/util/CheckMethodAdapter.h>
#include <jdk/internal/org/objectweb/asm/util/CheckModuleAdapter.h>
#include <jdk/internal/org/objectweb/asm/util/CheckRecordComponentAdapter.h>
#include <jdk/internal/org/objectweb/asm/util/Printer.h>
#include <jdk/internal/org/objectweb/asm/util/Textifier.h>
#include <jdk/internal/org/objectweb/asm/util/TraceMethodVisitor.h>
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
#undef ACC_STRICT
#undef ACC_SUPER
#undef ACC_SYNCHRONIZED
#undef ACC_SYNTHETIC
#undef ACC_TRANSIENT
#undef ACC_VARARGS
#undef ACC_VOLATILE
#undef ASM8
#undef ASM9_EXPERIMENTAL
#undef CAST
#undef CLASS_EXTENDS
#undef CLASS_TYPE_PARAMETER
#undef CLASS_TYPE_PARAMETER_BOUND
#undef CONSTRUCTOR_INVOCATION_TYPE_ARGUMENT
#undef CONSTRUCTOR_REFERENCE
#undef CONSTRUCTOR_REFERENCE_TYPE_ARGUMENT
#undef ERROR_AT
#undef EXCEPTION_PARAMETER
#undef FIELD
#undef INSTANCEOF
#undef LOCAL_VARIABLE
#undef METHOD_FORMAL_PARAMETER
#undef METHOD_INVOCATION_TYPE_ARGUMENT
#undef METHOD_RECEIVER
#undef METHOD_REFERENCE
#undef METHOD_REFERENCE_TYPE_ARGUMENT
#undef METHOD_RETURN
#undef METHOD_TYPE_PARAMETER
#undef METHOD_TYPE_PARAMETER_BOUND
#undef NEW
#undef RESOURCE_VARIABLE
#undef SKIP_DEBUG
#undef THROWS
#undef USAGE

using $FileInputStream = ::java::io::FileInputStream;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintWriter = ::java::io::PrintWriter;
using $AssertionError = ::java::lang::AssertionError;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $AnnotationVisitor = ::jdk::internal::org::objectweb::asm$::AnnotationVisitor;
using $Attribute = ::jdk::internal::org::objectweb::asm$::Attribute;
using $ClassReader = ::jdk::internal::org::objectweb::asm$::ClassReader;
using $ClassVisitor = ::jdk::internal::org::objectweb::asm$::ClassVisitor;
using $FieldVisitor = ::jdk::internal::org::objectweb::asm$::FieldVisitor;
using $MethodVisitor = ::jdk::internal::org::objectweb::asm$::MethodVisitor;
using $ModuleVisitor = ::jdk::internal::org::objectweb::asm$::ModuleVisitor;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $RecordComponentVisitor = ::jdk::internal::org::objectweb::asm$::RecordComponentVisitor;
using $Type = ::jdk::internal::org::objectweb::asm$::Type;
using $TypePath = ::jdk::internal::org::objectweb::asm$::TypePath;
using $TypeReference = ::jdk::internal::org::objectweb::asm$::TypeReference;
using $AbstractInsnNode = ::jdk::internal::org::objectweb::asm$::tree::AbstractInsnNode;
using $ClassNode = ::jdk::internal::org::objectweb::asm$::tree::ClassNode;
using $InsnList = ::jdk::internal::org::objectweb::asm$::tree::InsnList;
using $MethodNode = ::jdk::internal::org::objectweb::asm$::tree::MethodNode;
using $TryCatchBlockNode = ::jdk::internal::org::objectweb::asm$::tree::TryCatchBlockNode;
using $Analyzer = ::jdk::internal::org::objectweb::asm$::tree::analysis::Analyzer;
using $AnalyzerException = ::jdk::internal::org::objectweb::asm$::tree::analysis::AnalyzerException;
using $BasicValue = ::jdk::internal::org::objectweb::asm$::tree::analysis::BasicValue;
using $Frame = ::jdk::internal::org::objectweb::asm$::tree::analysis::Frame;
using $Interpreter = ::jdk::internal::org::objectweb::asm$::tree::analysis::Interpreter;
using $SimpleVerifier = ::jdk::internal::org::objectweb::asm$::tree::analysis::SimpleVerifier;
using $CheckAnnotationAdapter = ::jdk::internal::org::objectweb::asm$::util::CheckAnnotationAdapter;
using $CheckClassAdapter$1 = ::jdk::internal::org::objectweb::asm$::util::CheckClassAdapter$1;
using $CheckFieldAdapter = ::jdk::internal::org::objectweb::asm$::util::CheckFieldAdapter;
using $CheckMethodAdapter = ::jdk::internal::org::objectweb::asm$::util::CheckMethodAdapter;
using $CheckModuleAdapter = ::jdk::internal::org::objectweb::asm$::util::CheckModuleAdapter;
using $CheckRecordComponentAdapter = ::jdk::internal::org::objectweb::asm$::util::CheckRecordComponentAdapter;
using $Printer = ::jdk::internal::org::objectweb::asm$::util::Printer;
using $Textifier = ::jdk::internal::org::objectweb::asm$::util::Textifier;
using $TraceMethodVisitor = ::jdk::internal::org::objectweb::asm$::util::TraceMethodVisitor;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace util {

$CompoundAttribute _CheckClassAdapter_MethodAnnotations_visitPermittedSubclassExperimental39[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _CheckClassAdapter_FieldInfo_[] = {
	{"USAGE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CheckClassAdapter, USAGE)},
	{"ERROR_AT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CheckClassAdapter, ERROR_AT)},
	{"checkDataFlow", "Z", nullptr, $PRIVATE, $field(CheckClassAdapter, checkDataFlow)},
	{"version", "I", nullptr, $PRIVATE, $field(CheckClassAdapter, version)},
	{"visitCalled", "Z", nullptr, $PRIVATE, $field(CheckClassAdapter, visitCalled)},
	{"visitModuleCalled", "Z", nullptr, $PRIVATE, $field(CheckClassAdapter, visitModuleCalled)},
	{"visitSourceCalled", "Z", nullptr, $PRIVATE, $field(CheckClassAdapter, visitSourceCalled)},
	{"visitOuterClassCalled", "Z", nullptr, $PRIVATE, $field(CheckClassAdapter, visitOuterClassCalled)},
	{"visitNestHostCalled", "Z", nullptr, $PRIVATE, $field(CheckClassAdapter, visitNestHostCalled)},
	{"nestMemberPackageName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(CheckClassAdapter, nestMemberPackageName)},
	{"visitEndCalled", "Z", nullptr, $PRIVATE, $field(CheckClassAdapter, visitEndCalled)},
	{"labelInsnIndices", "Ljava/util/Map;", "Ljava/util/Map<Ljdk/internal/org/objectweb/asm/Label;Ljava/lang/Integer;>;", $PRIVATE, $field(CheckClassAdapter, labelInsnIndices)},
	{}
};

$MethodInfo _CheckClassAdapter_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/org/objectweb/asm/ClassVisitor;)V", nullptr, $PUBLIC, $method(CheckClassAdapter, init$, void, $ClassVisitor*)},
	{"<init>", "(Ljdk/internal/org/objectweb/asm/ClassVisitor;Z)V", nullptr, $PUBLIC, $method(CheckClassAdapter, init$, void, $ClassVisitor*, bool)},
	{"<init>", "(ILjdk/internal/org/objectweb/asm/ClassVisitor;Z)V", nullptr, $PROTECTED, $method(CheckClassAdapter, init$, void, int32_t, $ClassVisitor*, bool)},
	{"checkAccess", "(II)V", nullptr, $STATIC, $staticMethod(CheckClassAdapter, checkAccess, void, int32_t, int32_t)},
	{"checkChar", "(CLjava/lang/String;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(CheckClassAdapter, checkChar, int32_t, char16_t, $String*, int32_t)},
	{"checkClassSignature", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(CheckClassAdapter, checkClassSignature, void, $String*)},
	{"checkClassTypeSignature", "(Ljava/lang/String;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(CheckClassAdapter, checkClassTypeSignature, int32_t, $String*, int32_t)},
	{"checkFieldSignature", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(CheckClassAdapter, checkFieldSignature, void, $String*)},
	{"checkFullyQualifiedName", "(ILjava/lang/String;Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(CheckClassAdapter, checkFullyQualifiedName, void, int32_t, $String*, $String*)},
	{"checkJavaTypeSignature", "(Ljava/lang/String;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(CheckClassAdapter, checkJavaTypeSignature, int32_t, $String*, int32_t)},
	{"checkMethodSignature", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(CheckClassAdapter, checkMethodSignature, void, $String*)},
	{"checkReferenceTypeSignature", "(Ljava/lang/String;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(CheckClassAdapter, checkReferenceTypeSignature, int32_t, $String*, int32_t)},
	{"checkSignatureIdentifier", "(Ljava/lang/String;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(CheckClassAdapter, checkSignatureIdentifier, int32_t, $String*, int32_t)},
	{"checkState", "()V", nullptr, $PRIVATE, $method(CheckClassAdapter, checkState, void)},
	{"checkTypeArgument", "(Ljava/lang/String;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(CheckClassAdapter, checkTypeArgument, int32_t, $String*, int32_t)},
	{"checkTypeArguments", "(Ljava/lang/String;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(CheckClassAdapter, checkTypeArguments, int32_t, $String*, int32_t)},
	{"checkTypeParameter", "(Ljava/lang/String;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(CheckClassAdapter, checkTypeParameter, int32_t, $String*, int32_t)},
	{"checkTypeParameters", "(Ljava/lang/String;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(CheckClassAdapter, checkTypeParameters, int32_t, $String*, int32_t)},
	{"checkTypeRef", "(I)V", nullptr, $STATIC, $staticMethod(CheckClassAdapter, checkTypeRef, void, int32_t)},
	{"checkTypeVariableSignature", "(Ljava/lang/String;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(CheckClassAdapter, checkTypeVariableSignature, int32_t, $String*, int32_t)},
	{"getChar", "(Ljava/lang/String;I)C", nullptr, $PRIVATE | $STATIC, $staticMethod(CheckClassAdapter, getChar, char16_t, $String*, int32_t)},
	{"getUnqualifiedName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(CheckClassAdapter, getUnqualifiedName, $String*, $String*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(CheckClassAdapter, main, void, $StringArray*), "java.io.IOException"},
	{"main", "([Ljava/lang/String;Ljava/io/PrintWriter;)V", nullptr, $STATIC, $staticMethod(CheckClassAdapter, main, void, $StringArray*, $PrintWriter*), "java.io.IOException"},
	{"packageName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(CheckClassAdapter, packageName, $String*, $String*)},
	{"printAnalyzerResult", "(Ljdk/internal/org/objectweb/asm/tree/MethodNode;Ljdk/internal/org/objectweb/asm/tree/analysis/Analyzer;Ljava/io/PrintWriter;)V", "(Ljdk/internal/org/objectweb/asm/tree/MethodNode;Ljdk/internal/org/objectweb/asm/tree/analysis/Analyzer<Ljdk/internal/org/objectweb/asm/tree/analysis/BasicValue;>;Ljava/io/PrintWriter;)V", $STATIC, $staticMethod(CheckClassAdapter, printAnalyzerResult, void, $MethodNode*, $Analyzer*, $PrintWriter*)},
	{"verify", "(Ljdk/internal/org/objectweb/asm/ClassReader;ZLjava/io/PrintWriter;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(CheckClassAdapter, verify, void, $ClassReader*, bool, $PrintWriter*)},
	{"verify", "(Ljdk/internal/org/objectweb/asm/ClassReader;Ljava/lang/ClassLoader;ZLjava/io/PrintWriter;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(CheckClassAdapter, verify, void, $ClassReader*, $ClassLoader*, bool, $PrintWriter*)},
	{"visit", "(IILjava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(CheckClassAdapter, visit, void, int32_t, int32_t, $String*, $String*, $String*, $StringArray*)},
	{"visitAnnotation", "(Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/AnnotationVisitor;", nullptr, $PUBLIC, $virtualMethod(CheckClassAdapter, visitAnnotation, $AnnotationVisitor*, $String*, bool)},
	{"visitAttribute", "(Ljdk/internal/org/objectweb/asm/Attribute;)V", nullptr, $PUBLIC, $virtualMethod(CheckClassAdapter, visitAttribute, void, $Attribute*)},
	{"visitEnd", "()V", nullptr, $PUBLIC, $virtualMethod(CheckClassAdapter, visitEnd, void)},
	{"visitField", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Object;)Ljdk/internal/org/objectweb/asm/FieldVisitor;", nullptr, $PUBLIC, $virtualMethod(CheckClassAdapter, visitField, $FieldVisitor*, int32_t, $String*, $String*, $String*, Object$*)},
	{"visitInnerClass", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V", nullptr, $PUBLIC, $virtualMethod(CheckClassAdapter, visitInnerClass, void, $String*, $String*, $String*, int32_t)},
	{"visitMethod", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/MethodVisitor;", nullptr, $PUBLIC, $virtualMethod(CheckClassAdapter, visitMethod, $MethodVisitor*, int32_t, $String*, $String*, $String*, $StringArray*)},
	{"visitModule", "(Ljava/lang/String;ILjava/lang/String;)Ljdk/internal/org/objectweb/asm/ModuleVisitor;", nullptr, $PUBLIC, $virtualMethod(CheckClassAdapter, visitModule, $ModuleVisitor*, $String*, int32_t, $String*)},
	{"visitNestHost", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(CheckClassAdapter, visitNestHost, void, $String*)},
	{"visitNestMember", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(CheckClassAdapter, visitNestMember, void, $String*)},
	{"visitOuterClass", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(CheckClassAdapter, visitOuterClass, void, $String*, $String*, $String*)},
	{"visitPermittedSubclassExperimental", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(CheckClassAdapter, visitPermittedSubclassExperimental, void, $String*), nullptr, nullptr, _CheckClassAdapter_MethodAnnotations_visitPermittedSubclassExperimental39},
	{"visitRecordComponent", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/RecordComponentVisitor;", nullptr, $PUBLIC, $virtualMethod(CheckClassAdapter, visitRecordComponent, $RecordComponentVisitor*, $String*, $String*, $String*)},
	{"visitSource", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(CheckClassAdapter, visitSource, void, $String*, $String*)},
	{"visitTypeAnnotation", "(ILjdk/internal/org/objectweb/asm/TypePath;Ljava/lang/String;Z)Ljdk/internal/org/objectweb/asm/AnnotationVisitor;", nullptr, $PUBLIC, $virtualMethod(CheckClassAdapter, visitTypeAnnotation, $AnnotationVisitor*, int32_t, $TypePath*, $String*, bool)},
	{}
};

$InnerClassInfo _CheckClassAdapter_InnerClassesInfo_[] = {
	{"jdk.internal.org.objectweb.asm.util.CheckClassAdapter$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _CheckClassAdapter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.util.CheckClassAdapter",
	"jdk.internal.org.objectweb.asm.ClassVisitor",
	nullptr,
	_CheckClassAdapter_FieldInfo_,
	_CheckClassAdapter_MethodInfo_,
	nullptr,
	nullptr,
	_CheckClassAdapter_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.org.objectweb.asm.util.CheckClassAdapter$1"
};

$Object* allocate$CheckClassAdapter($Class* clazz) {
	return $of($alloc(CheckClassAdapter));
}

$String* CheckClassAdapter::USAGE = nullptr;
$String* CheckClassAdapter::ERROR_AT = nullptr;

void CheckClassAdapter::init$($ClassVisitor* classVisitor) {
	CheckClassAdapter::init$(classVisitor, true);
}

void CheckClassAdapter::init$($ClassVisitor* classVisitor, bool checkDataFlow) {
	CheckClassAdapter::init$($Opcodes::ASM8, classVisitor, checkDataFlow);
	if ($of(this)->getClass() != CheckClassAdapter::class$) {
		$throwNew($IllegalStateException);
	}
}

void CheckClassAdapter::init$(int32_t api, $ClassVisitor* classVisitor, bool checkDataFlow) {
	$ClassVisitor::init$(api, classVisitor);
	$set(this, labelInsnIndices, $new($HashMap));
	this->checkDataFlow = checkDataFlow;
}

void CheckClassAdapter::visit(int32_t version, int32_t access, $String* name, $String* signature, $String* superName, $StringArray* interfaces) {
	$useLocalCurrentObjectStackCache();
	if (this->visitCalled) {
		$throwNew($IllegalStateException, "visit must be called only once"_s);
	}
	this->visitCalled = true;
	checkState();
	checkAccess(access, ((((((((($Opcodes::ACC_PUBLIC | $Opcodes::ACC_FINAL) | $Opcodes::ACC_SUPER) | $Opcodes::ACC_INTERFACE) | $Opcodes::ACC_ABSTRACT) | $Opcodes::ACC_SYNTHETIC) | $Opcodes::ACC_ANNOTATION) | $Opcodes::ACC_ENUM) | $Opcodes::ACC_DEPRECATED) | $Opcodes::ACC_RECORD) | $Opcodes::ACC_MODULE);
	if (name == nullptr) {
		$throwNew($IllegalArgumentException, "Illegal class name (null)"_s);
	}
	bool var$0 = !$nc(name)->endsWith("package-info"_s);
	if (var$0 && !name->endsWith("module-info"_s)) {
		$CheckMethodAdapter::checkInternalName(version, name, "class name"_s);
	}
	if ("java/lang/Object"_s->equals(name)) {
		if (superName != nullptr) {
			$throwNew($IllegalArgumentException, "The super class name of the Object class must be \'null\'"_s);
		}
	} else if ($nc(name)->endsWith("module-info"_s)) {
		if (superName != nullptr) {
			$throwNew($IllegalArgumentException, "The super class name of a module-info class must be \'null\'"_s);
		}
	} else {
		$CheckMethodAdapter::checkInternalName(version, superName, "super class name"_s);
	}
	if (signature != nullptr) {
		checkClassSignature(signature);
	}
	if (((int32_t)(access & (uint32_t)$Opcodes::ACC_INTERFACE)) != 0 && !"java/lang/Object"_s->equals(superName)) {
		$throwNew($IllegalArgumentException, "The super class name of interfaces must be \'java/lang/Object\'"_s);
	}
	if (interfaces != nullptr) {
		for (int32_t i = 0; i < interfaces->length; ++i) {
			$CheckMethodAdapter::checkInternalName(version, interfaces->get(i), $$str({"interface name at index "_s, $$str(i)}));
		}
	}
	this->version = version;
	$ClassVisitor::visit(version, access, name, signature, superName, interfaces);
}

void CheckClassAdapter::visitSource($String* file, $String* debug) {
	checkState();
	if (this->visitSourceCalled) {
		$throwNew($IllegalStateException, "visitSource can be called only once."_s);
	}
	this->visitSourceCalled = true;
	$ClassVisitor::visitSource(file, debug);
}

$ModuleVisitor* CheckClassAdapter::visitModule($String* name, int32_t access, $String* version) {
	$useLocalCurrentObjectStackCache();
	checkState();
	if (this->visitModuleCalled) {
		$throwNew($IllegalStateException, "visitModule can be called only once."_s);
	}
	this->visitModuleCalled = true;
	checkFullyQualifiedName(this->version, name, "module name"_s);
	checkAccess(access, ($Opcodes::ACC_OPEN | $Opcodes::ACC_SYNTHETIC) | $Opcodes::ACC_MANDATED);
	$var($CheckModuleAdapter, checkModuleAdapter, $new($CheckModuleAdapter, this->api, $($ClassVisitor::visitModule(name, access, version)), ((int32_t)(access & (uint32_t)$Opcodes::ACC_OPEN)) != 0));
	checkModuleAdapter->classVersion = this->version;
	return checkModuleAdapter;
}

void CheckClassAdapter::visitNestHost($String* nestHost) {
	checkState();
	$CheckMethodAdapter::checkInternalName(this->version, nestHost, "nestHost"_s);
	if (this->visitNestHostCalled) {
		$throwNew($IllegalStateException, "visitNestHost can be called only once."_s);
	}
	if (this->nestMemberPackageName != nullptr) {
		$throwNew($IllegalStateException, "visitNestHost and visitNestMember are mutually exclusive."_s);
	}
	this->visitNestHostCalled = true;
	$ClassVisitor::visitNestHost(nestHost);
}

void CheckClassAdapter::visitNestMember($String* nestMember) {
	$useLocalCurrentObjectStackCache();
	checkState();
	$CheckMethodAdapter::checkInternalName(this->version, nestMember, "nestMember"_s);
	if (this->visitNestHostCalled) {
		$throwNew($IllegalStateException, "visitMemberOfNest and visitNestHost are mutually exclusive."_s);
	}
	$var($String, packageName, CheckClassAdapter::packageName(nestMember));
	if (this->nestMemberPackageName == nullptr) {
		$set(this, nestMemberPackageName, packageName);
	} else if (!$nc(this->nestMemberPackageName)->equals(packageName)) {
		$throwNew($IllegalStateException, $$str({"nest member "_s, nestMember, " should be in the package "_s, this->nestMemberPackageName}));
	}
	$ClassVisitor::visitNestMember(nestMember);
}

void CheckClassAdapter::visitPermittedSubclassExperimental($String* permittedSubclass) {
	checkState();
	$CheckMethodAdapter::checkInternalName(this->version, permittedSubclass, "permittedSubclass"_s);
	$ClassVisitor::visitPermittedSubclassExperimental(permittedSubclass);
}

void CheckClassAdapter::visitOuterClass($String* owner, $String* name, $String* descriptor) {
	checkState();
	if (this->visitOuterClassCalled) {
		$throwNew($IllegalStateException, "visitOuterClass can be called only once."_s);
	}
	this->visitOuterClassCalled = true;
	if (owner == nullptr) {
		$throwNew($IllegalArgumentException, "Illegal outer class owner"_s);
	}
	if (descriptor != nullptr) {
		$CheckMethodAdapter::checkMethodDescriptor(this->version, descriptor);
	}
	$ClassVisitor::visitOuterClass(owner, name, descriptor);
}

void CheckClassAdapter::visitInnerClass($String* name, $String* outerName, $String* innerName, int32_t access) {
	checkState();
	$CheckMethodAdapter::checkInternalName(this->version, name, "class name"_s);
	if (outerName != nullptr) {
		$CheckMethodAdapter::checkInternalName(this->version, outerName, "outer class name"_s);
	}
	if (innerName != nullptr) {
		int32_t startIndex = 0;
		while (true) {
			bool var$0 = startIndex < innerName->length();
			if (!(var$0 && $Character::isDigit(innerName->charAt(startIndex)))) {
				break;
			}
			{
				++startIndex;
			}
		}
		if (startIndex == 0 || startIndex < innerName->length()) {
			$CheckMethodAdapter::checkIdentifier(this->version, innerName, startIndex, -1, "inner class name"_s);
		}
	}
	checkAccess(access, (((((((($Opcodes::ACC_PUBLIC | $Opcodes::ACC_PRIVATE) | $Opcodes::ACC_PROTECTED) | $Opcodes::ACC_STATIC) | $Opcodes::ACC_FINAL) | $Opcodes::ACC_INTERFACE) | $Opcodes::ACC_ABSTRACT) | $Opcodes::ACC_SYNTHETIC) | $Opcodes::ACC_ANNOTATION) | $Opcodes::ACC_ENUM);
	$ClassVisitor::visitInnerClass(name, outerName, innerName, access);
}

$RecordComponentVisitor* CheckClassAdapter::visitRecordComponent($String* name, $String* descriptor, $String* signature) {
	checkState();
	$CheckMethodAdapter::checkUnqualifiedName(this->version, name, "record component name"_s);
	$CheckMethodAdapter::checkDescriptor(this->version, descriptor, false);
	if (signature != nullptr) {
		checkFieldSignature(signature);
	}
	return $new($CheckRecordComponentAdapter, this->api, $($ClassVisitor::visitRecordComponent(name, descriptor, signature)));
}

$FieldVisitor* CheckClassAdapter::visitField(int32_t access, $String* name, $String* descriptor, $String* signature, Object$* value) {
	checkState();
	checkAccess(access, ((((((((($Opcodes::ACC_PUBLIC | $Opcodes::ACC_PRIVATE) | $Opcodes::ACC_PROTECTED) | $Opcodes::ACC_STATIC) | $Opcodes::ACC_FINAL) | $Opcodes::ACC_VOLATILE) | $Opcodes::ACC_TRANSIENT) | $Opcodes::ACC_SYNTHETIC) | $Opcodes::ACC_ENUM) | $Opcodes::ACC_MANDATED) | $Opcodes::ACC_DEPRECATED);
	$CheckMethodAdapter::checkUnqualifiedName(this->version, name, "field name"_s);
	$CheckMethodAdapter::checkDescriptor(this->version, descriptor, false);
	if (signature != nullptr) {
		checkFieldSignature(signature);
	}
	if (value != nullptr) {
		$CheckMethodAdapter::checkConstant(value);
	}
	return $new($CheckFieldAdapter, this->api, $($ClassVisitor::visitField(access, name, descriptor, signature, value)));
}

$MethodVisitor* CheckClassAdapter::visitMethod(int32_t access, $String* name, $String* descriptor, $String* signature, $StringArray* exceptions) {
	$useLocalCurrentObjectStackCache();
	checkState();
	checkAccess(access, (((((((((((($Opcodes::ACC_PUBLIC | $Opcodes::ACC_PRIVATE) | $Opcodes::ACC_PROTECTED) | $Opcodes::ACC_STATIC) | $Opcodes::ACC_FINAL) | $Opcodes::ACC_SYNCHRONIZED) | $Opcodes::ACC_BRIDGE) | $Opcodes::ACC_VARARGS) | $Opcodes::ACC_NATIVE) | $Opcodes::ACC_ABSTRACT) | $Opcodes::ACC_STRICT) | $Opcodes::ACC_SYNTHETIC) | $Opcodes::ACC_MANDATED) | $Opcodes::ACC_DEPRECATED);
	bool var$0 = !"<init>"_s->equals(name);
	if (var$0 && !"<clinit>"_s->equals(name)) {
		$CheckMethodAdapter::checkMethodIdentifier(this->version, name, "method name"_s);
	}
	$CheckMethodAdapter::checkMethodDescriptor(this->version, descriptor);
	if (signature != nullptr) {
		checkMethodSignature(signature);
	}
	if (exceptions != nullptr) {
		for (int32_t i = 0; i < exceptions->length; ++i) {
			$CheckMethodAdapter::checkInternalName(this->version, exceptions->get(i), $$str({"exception name at index "_s, $$str(i)}));
		}
	}
	$var($CheckMethodAdapter, checkMethodAdapter, nullptr);
	if (this->checkDataFlow) {
		$assign(checkMethodAdapter, $new($CheckMethodAdapter, this->api, access, name, descriptor, $($ClassVisitor::visitMethod(access, name, descriptor, signature, exceptions)), this->labelInsnIndices));
	} else {
		$assign(checkMethodAdapter, $new($CheckMethodAdapter, this->api, $($ClassVisitor::visitMethod(access, name, descriptor, signature, exceptions)), this->labelInsnIndices));
	}
	$nc(checkMethodAdapter)->version = this->version;
	return checkMethodAdapter;
}

$AnnotationVisitor* CheckClassAdapter::visitAnnotation($String* descriptor, bool visible) {
	checkState();
	$CheckMethodAdapter::checkDescriptor(this->version, descriptor, false);
	return $new($CheckAnnotationAdapter, $($ClassVisitor::visitAnnotation(descriptor, visible)));
}

$AnnotationVisitor* CheckClassAdapter::visitTypeAnnotation(int32_t typeRef, $TypePath* typePath, $String* descriptor, bool visible) {
	$useLocalCurrentObjectStackCache();
	checkState();
	int32_t sort = $$new($TypeReference, typeRef)->getSort();
	if (sort != $TypeReference::CLASS_TYPE_PARAMETER && sort != $TypeReference::CLASS_TYPE_PARAMETER_BOUND && sort != $TypeReference::CLASS_EXTENDS) {
		$throwNew($IllegalArgumentException, $$str({"Invalid type reference sort 0x"_s, $($Integer::toHexString(sort))}));
	}
	checkTypeRef(typeRef);
	$CheckMethodAdapter::checkDescriptor(this->version, descriptor, false);
	return $new($CheckAnnotationAdapter, $($ClassVisitor::visitTypeAnnotation(typeRef, typePath, descriptor, visible)));
}

void CheckClassAdapter::visitAttribute($Attribute* attribute) {
	checkState();
	if (attribute == nullptr) {
		$throwNew($IllegalArgumentException, "Invalid attribute (must not be null)"_s);
	}
	$ClassVisitor::visitAttribute(attribute);
}

void CheckClassAdapter::visitEnd() {
	checkState();
	this->visitEndCalled = true;
	$ClassVisitor::visitEnd();
}

void CheckClassAdapter::checkState() {
	if (!this->visitCalled) {
		$throwNew($IllegalStateException, "Cannot visit member before visit has been called."_s);
	}
	if (this->visitEndCalled) {
		$throwNew($IllegalStateException, "Cannot visit member after visitEnd has been called."_s);
	}
}

void CheckClassAdapter::checkAccess(int32_t access, int32_t possibleAccess) {
	$init(CheckClassAdapter);
	$useLocalCurrentObjectStackCache();
	if (((int32_t)(access & (uint32_t)~possibleAccess)) != 0) {
		$throwNew($IllegalArgumentException, $$str({"Invalid access flags: "_s, $$str(access)}));
	}
	int32_t publicProtectedPrivate = ($Opcodes::ACC_PUBLIC | $Opcodes::ACC_PROTECTED) | $Opcodes::ACC_PRIVATE;
	if ($Integer::bitCount((int32_t)(access & (uint32_t)publicProtectedPrivate)) > 1) {
		$throwNew($IllegalArgumentException, $$str({"public, protected and private are mutually exclusive: "_s, $$str(access)}));
	}
	if ($Integer::bitCount((int32_t)(access & (uint32_t)($Opcodes::ACC_FINAL | $Opcodes::ACC_ABSTRACT))) > 1) {
		$throwNew($IllegalArgumentException, $$str({"final and abstract are mutually exclusive: "_s, $$str(access)}));
	}
}

void CheckClassAdapter::checkFullyQualifiedName(int32_t version, $String* name, $String* source) {
	$init(CheckClassAdapter);
	try {
		int32_t startIndex = 0;
		int32_t dotIndex = 0;
		while ((dotIndex = $nc(name)->indexOf((int32_t)u'.', startIndex + 1)) != -1) {
			$CheckMethodAdapter::checkIdentifier(version, name, startIndex, dotIndex, nullptr);
			startIndex = dotIndex + 1;
		}
		$CheckMethodAdapter::checkIdentifier(version, name, startIndex, $nc(name)->length(), nullptr);
	} catch ($IllegalArgumentException& e) {
		$throwNew($IllegalArgumentException, $$str({"Invalid "_s, source, " (must be a fully qualified name): "_s, name}), e);
	}
}

void CheckClassAdapter::checkClassSignature($String* signature) {
	$init(CheckClassAdapter);
	$useLocalCurrentObjectStackCache();
	int32_t pos = 0;
	if (getChar(signature, 0) == u'<') {
		pos = checkTypeParameters(signature, pos);
	}
	pos = checkClassTypeSignature(signature, pos);
	while (getChar(signature, pos) == u'L') {
		pos = checkClassTypeSignature(signature, pos);
	}
	if (pos != $nc(signature)->length()) {
		$throwNew($IllegalArgumentException, $$str({signature, CheckClassAdapter::ERROR_AT, $$str(pos)}));
	}
}

void CheckClassAdapter::checkMethodSignature($String* signature) {
	$init(CheckClassAdapter);
	$useLocalCurrentObjectStackCache();
	int32_t pos = 0;
	if (getChar(signature, 0) == u'<') {
		pos = checkTypeParameters(signature, pos);
	}
	pos = checkChar(u'(', signature, pos);
	while ("ZCBSIFJDL[T"_s->indexOf((int32_t)getChar(signature, pos)) != -1) {
		pos = checkJavaTypeSignature(signature, pos);
	}
	pos = checkChar(u')', signature, pos);
	if (getChar(signature, pos) == u'V') {
		++pos;
	} else {
		pos = checkJavaTypeSignature(signature, pos);
	}
	while (getChar(signature, pos) == u'^') {
		++pos;
		if (getChar(signature, pos) == u'L') {
			pos = checkClassTypeSignature(signature, pos);
		} else {
			pos = checkTypeVariableSignature(signature, pos);
		}
	}
	if (pos != $nc(signature)->length()) {
		$throwNew($IllegalArgumentException, $$str({signature, CheckClassAdapter::ERROR_AT, $$str(pos)}));
	}
}

void CheckClassAdapter::checkFieldSignature($String* signature) {
	$init(CheckClassAdapter);
	$useLocalCurrentObjectStackCache();
	int32_t pos = checkReferenceTypeSignature(signature, 0);
	if (pos != $nc(signature)->length()) {
		$throwNew($IllegalArgumentException, $$str({signature, CheckClassAdapter::ERROR_AT, $$str(pos)}));
	}
}

int32_t CheckClassAdapter::checkTypeParameters($String* signature, int32_t startPos) {
	$init(CheckClassAdapter);
	int32_t pos = startPos;
	pos = checkChar(u'<', signature, pos);
	pos = checkTypeParameter(signature, pos);
	while (getChar(signature, pos) != u'>') {
		pos = checkTypeParameter(signature, pos);
	}
	return pos + 1;
}

int32_t CheckClassAdapter::checkTypeParameter($String* signature, int32_t startPos) {
	$init(CheckClassAdapter);
	int32_t pos = startPos;
	pos = checkSignatureIdentifier(signature, pos);
	pos = checkChar(u':', signature, pos);
	if ("L[T"_s->indexOf((int32_t)getChar(signature, pos)) != -1) {
		pos = checkReferenceTypeSignature(signature, pos);
	}
	while (getChar(signature, pos) == u':') {
		pos = checkReferenceTypeSignature(signature, pos + 1);
	}
	return pos;
}

int32_t CheckClassAdapter::checkReferenceTypeSignature($String* signature, int32_t pos) {
	$init(CheckClassAdapter);
	switch (getChar(signature, pos)) {
	case u'L':
		{
			return checkClassTypeSignature(signature, pos);
		}
	case u'[':
		{
			return checkJavaTypeSignature(signature, pos + 1);
		}
	default:
		{
			return checkTypeVariableSignature(signature, pos);
		}
	}
}

int32_t CheckClassAdapter::checkClassTypeSignature($String* signature, int32_t startPos) {
	$init(CheckClassAdapter);
	int32_t pos = startPos;
	pos = checkChar(u'L', signature, pos);
	pos = checkSignatureIdentifier(signature, pos);
	while (getChar(signature, pos) == u'/') {
		pos = checkSignatureIdentifier(signature, pos + 1);
	}
	if (getChar(signature, pos) == u'<') {
		pos = checkTypeArguments(signature, pos);
	}
	while (getChar(signature, pos) == u'.') {
		pos = checkSignatureIdentifier(signature, pos + 1);
		if (getChar(signature, pos) == u'<') {
			pos = checkTypeArguments(signature, pos);
		}
	}
	return checkChar(u';', signature, pos);
}

int32_t CheckClassAdapter::checkTypeArguments($String* signature, int32_t startPos) {
	$init(CheckClassAdapter);
	int32_t pos = startPos;
	pos = checkChar(u'<', signature, pos);
	pos = checkTypeArgument(signature, pos);
	while (getChar(signature, pos) != u'>') {
		pos = checkTypeArgument(signature, pos);
	}
	return pos + 1;
}

int32_t CheckClassAdapter::checkTypeArgument($String* signature, int32_t startPos) {
	$init(CheckClassAdapter);
	int32_t pos = startPos;
	char16_t c = getChar(signature, pos);
	if (c == u'*') {
		return pos + 1;
	} else if (c == u'+' || c == u'-') {
		++pos;
	}
	return checkReferenceTypeSignature(signature, pos);
}

int32_t CheckClassAdapter::checkTypeVariableSignature($String* signature, int32_t startPos) {
	$init(CheckClassAdapter);
	int32_t pos = startPos;
	pos = checkChar(u'T', signature, pos);
	pos = checkSignatureIdentifier(signature, pos);
	return checkChar(u';', signature, pos);
}

int32_t CheckClassAdapter::checkJavaTypeSignature($String* signature, int32_t startPos) {
	$init(CheckClassAdapter);
	int32_t pos = startPos;
	switch (getChar(signature, pos)) {
	case u'B':
		{}
	case u'C':
		{}
	case u'D':
		{}
	case u'F':
		{}
	case u'I':
		{}
	case u'J':
		{}
	case u'S':
		{}
	case u'Z':
		{
			return pos + 1;
		}
	default:
		{
			return checkReferenceTypeSignature(signature, pos);
		}
	}
}

int32_t CheckClassAdapter::checkSignatureIdentifier($String* signature, int32_t startPos) {
	$init(CheckClassAdapter);
	$useLocalCurrentObjectStackCache();
	int32_t pos = startPos;
	while (true) {
		bool var$0 = pos < $nc(signature)->length();
		if (!(var$0 && ".;[/<>:"_s->indexOf(signature->codePointAt(pos)) == -1)) {
			break;
		}
		{
			pos = signature->offsetByCodePoints(pos, 1);
		}
	}
	if (pos == startPos) {
		$throwNew($IllegalArgumentException, $$str({signature, ": identifier expected at index "_s, $$str(startPos)}));
	}
	return pos;
}

int32_t CheckClassAdapter::checkChar(char16_t c, $String* signature, int32_t pos) {
	$init(CheckClassAdapter);
	$useLocalCurrentObjectStackCache();
	if (getChar(signature, pos) == c) {
		return pos + 1;
	}
	$throwNew($IllegalArgumentException, $$str({signature, ": \'"_s, $$str(c), "\' expected at index "_s, $$str(pos)}));
}

char16_t CheckClassAdapter::getChar($String* string, int32_t pos) {
	$init(CheckClassAdapter);
	return pos < $nc(string)->length() ? $nc(string)->charAt(pos) : (char16_t)0;
}

void CheckClassAdapter::checkTypeRef(int32_t typeRef) {
	$init(CheckClassAdapter);
	$useLocalCurrentObjectStackCache();
	int32_t mask = 0;
	switch ((int32_t)((uint32_t)typeRef >> 24)) {
	case $TypeReference::CLASS_TYPE_PARAMETER:
		{}
	case $TypeReference::METHOD_TYPE_PARAMETER:
		{}
	case $TypeReference::METHOD_FORMAL_PARAMETER:
		{
			mask = (int32_t)0xFFFF0000;
			break;
		}
	case $TypeReference::FIELD:
		{}
	case $TypeReference::METHOD_RETURN:
		{}
	case $TypeReference::METHOD_RECEIVER:
		{}
	case $TypeReference::LOCAL_VARIABLE:
		{}
	case $TypeReference::RESOURCE_VARIABLE:
		{}
	case $TypeReference::INSTANCEOF:
		{}
	case $TypeReference::NEW:
		{}
	case $TypeReference::CONSTRUCTOR_REFERENCE:
		{}
	case $TypeReference::METHOD_REFERENCE:
		{
			mask = (int32_t)0xFF000000;
			break;
		}
	case $TypeReference::CLASS_EXTENDS:
		{}
	case $TypeReference::CLASS_TYPE_PARAMETER_BOUND:
		{}
	case $TypeReference::METHOD_TYPE_PARAMETER_BOUND:
		{}
	case $TypeReference::THROWS:
		{}
	case $TypeReference::EXCEPTION_PARAMETER:
		{
			mask = -256;
			break;
		}
	case $TypeReference::CAST:
		{}
	case $TypeReference::CONSTRUCTOR_INVOCATION_TYPE_ARGUMENT:
		{}
	case $TypeReference::METHOD_INVOCATION_TYPE_ARGUMENT:
		{}
	case $TypeReference::CONSTRUCTOR_REFERENCE_TYPE_ARGUMENT:
		{}
	case $TypeReference::METHOD_REFERENCE_TYPE_ARGUMENT:
		{
			mask = (int32_t)0xFF0000FF;
			break;
		}
	default:
		{
			$throwNew($AssertionError);
		}
	}
	if (((int32_t)(typeRef & (uint32_t)~mask)) != 0) {
		$throwNew($IllegalArgumentException, $$str({"Invalid type reference 0x"_s, $($Integer::toHexString(typeRef))}));
	}
}

$String* CheckClassAdapter::packageName($String* name) {
	$init(CheckClassAdapter);
	int32_t index = $nc(name)->lastIndexOf((int32_t)u'/');
	if (index == -1) {
		return ""_s;
	}
	return name->substring(0, index);
}

void CheckClassAdapter::main($StringArray* args) {
	$init(CheckClassAdapter);
	main(args, $$new($PrintWriter, static_cast<$OutputStream*>($System::err), true));
}

void CheckClassAdapter::main($StringArray* args, $PrintWriter* logger) {
	$init(CheckClassAdapter);
	$useLocalCurrentObjectStackCache();
	if ($nc(args)->length != 1) {
		$nc(logger)->println(CheckClassAdapter::USAGE);
		return;
	}
	$var($ClassReader, classReader, nullptr);
	if ($nc($nc(args)->get(0))->endsWith(".class"_s)) {
		$var($InputStream, inputStream, $new($FileInputStream, args->get(0)));
		$assign(classReader, $new($ClassReader, inputStream));
	} else {
		$assign(classReader, $new($ClassReader, args->get(0)));
	}
	verify(classReader, false, logger);
}

void CheckClassAdapter::verify($ClassReader* classReader, bool printResults, $PrintWriter* printWriter) {
	$init(CheckClassAdapter);
	verify(classReader, nullptr, printResults, printWriter);
}

void CheckClassAdapter::verify($ClassReader* classReader, $ClassLoader* loader, bool printResults, $PrintWriter* printWriter) {
	$init(CheckClassAdapter);
	$useLocalCurrentObjectStackCache();
	$var($ClassNode, classNode, $new($ClassNode));
	$nc(classReader)->accept($$new($CheckClassAdapter$1, $Opcodes::ASM9_EXPERIMENTAL, classNode, false), $ClassReader::SKIP_DEBUG);
	$var($Type, syperType, classNode->superName == nullptr ? ($Type*)nullptr : $Type::getObjectType(classNode->superName));
	$var($List, methods, classNode->methods);
	$var($List, interfaces, $new($ArrayList));
	{
		$var($Iterator, i$, $nc(classNode->interfaces)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, interfaceName, $cast($String, i$->next()));
			{
				interfaces->add($($Type::getObjectType(interfaceName)));
			}
		}
	}
	{
		$var($Iterator, i$, $nc(methods)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($MethodNode, method, $cast($MethodNode, i$->next()));
			{
				$var($SimpleVerifier, verifier, $new($SimpleVerifier, $($Type::getObjectType(classNode->name)), syperType, interfaces, ((int32_t)(classNode->access & (uint32_t)$Opcodes::ACC_INTERFACE)) != 0));
				$var($Analyzer, analyzer, $new($Analyzer, verifier));
				if (loader != nullptr) {
					verifier->setClassLoader(loader);
				}
				try {
					analyzer->analyze(classNode->name, method);
				} catch ($AnalyzerException& e) {
					e->printStackTrace(printWriter);
				}
				if (printResults) {
					printAnalyzerResult(method, analyzer, printWriter);
				}
			}
		}
	}
	$nc(printWriter)->flush();
}

void CheckClassAdapter::printAnalyzerResult($MethodNode* method, $Analyzer* analyzer, $PrintWriter* printWriter) {
	$init(CheckClassAdapter);
	$useLocalCurrentObjectStackCache();
	$var($Textifier, textifier, $new($Textifier));
	$var($TraceMethodVisitor, traceMethodVisitor, $new($TraceMethodVisitor, textifier));
	$nc(printWriter)->println($$str({$nc(method)->name, method->desc}));
	for (int32_t i = 0; i < $nc($nc(method)->instructions)->size(); ++i) {
		$nc($($nc(method->instructions)->get(i)))->accept(traceMethodVisitor);
		$var($StringBuilder, stringBuilder, $new($StringBuilder));
		$var($Frame, frame, $nc($($nc(analyzer)->getFrames()))->get(i));
		if (frame == nullptr) {
			stringBuilder->append(u'?');
		} else {
			for (int32_t j = 0; j < $nc(frame)->getLocals(); ++j) {
				stringBuilder->append($(getUnqualifiedName($($nc(($cast($BasicValue, $(frame->getLocal(j)))))->toString()))))->append(u' ');
			}
			stringBuilder->append(" : "_s);
			for (int32_t j = 0; j < $nc(frame)->getStackSize(); ++j) {
				stringBuilder->append($(getUnqualifiedName($($nc(($cast($BasicValue, $(frame->getStack(j)))))->toString()))))->append(u' ');
			}
		}
		while (stringBuilder->length() < method->maxStack + method->maxLocals + 1) {
			stringBuilder->append(u' ');
		}
		printWriter->print($($nc($($Integer::toString(i + 0x000186A0)))->substring(1)));
		$var($String, var$0, $$str({" "_s, stringBuilder, " : "_s}));
		printWriter->print($$concat(var$0, $($nc(textifier->text)->get($nc(textifier->text)->size() - 1))));
	}
	{
		$var($Iterator, i$, $nc($nc(method)->tryCatchBlocks)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($TryCatchBlockNode, tryCatchBlock, $cast($TryCatchBlockNode, i$->next()));
			{
				$nc(tryCatchBlock)->accept(traceMethodVisitor);
				printWriter->print($$str({" "_s, $($nc(textifier->text)->get($nc(textifier->text)->size() - 1))}));
			}
		}
	}
	printWriter->println();
}

$String* CheckClassAdapter::getUnqualifiedName($String* name) {
	$init(CheckClassAdapter);
	int32_t lastSlashIndex = $nc(name)->lastIndexOf((int32_t)u'/');
	if (lastSlashIndex == -1) {
		return name;
	} else {
		int32_t endIndex = name->length();
		if (name->charAt(endIndex - 1) == u';') {
			--endIndex;
		}
		return name->substring(lastSlashIndex + 1, endIndex);
	}
}

CheckClassAdapter::CheckClassAdapter() {
}

void clinit$CheckClassAdapter($Class* class$) {
	$assignStatic(CheckClassAdapter::USAGE, "Verifies the given class.\nUsage: CheckClassAdapter <fully qualified class name or class file name>"_s);
	$assignStatic(CheckClassAdapter::ERROR_AT, ": error at index "_s);
}

$Class* CheckClassAdapter::load$($String* name, bool initialize) {
	$loadClass(CheckClassAdapter, name, initialize, &_CheckClassAdapter_ClassInfo_, clinit$CheckClassAdapter, allocate$CheckClassAdapter);
	return class$;
}

$Class* CheckClassAdapter::class$ = nullptr;

					} // util
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk