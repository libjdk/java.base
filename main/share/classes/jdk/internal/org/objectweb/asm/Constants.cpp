#include <jdk/internal/org/objectweb/asm/Constants.h>

#include <java/io/DataInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/lang/CharSequence.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/IllegalStateException.h>
#include <java/util/regex/Pattern.h>
#include <jcpp.h>

#undef ACC_CONSTRUCTOR
#undef ALOAD_0
#undef ALOAD_1
#undef ALOAD_2
#undef ALOAD_3
#undef ANNOTATION_DEFAULT
#undef ASM_GOTO
#undef ASM_GOTO_W
#undef ASM_IFEQ
#undef ASM_IFGE
#undef ASM_IFGT
#undef ASM_IFLE
#undef ASM_IFLT
#undef ASM_IFNE
#undef ASM_IFNONNULL
#undef ASM_IFNULL
#undef ASM_IFNULL_OPCODE_DELTA
#undef ASM_IF_ACMPEQ
#undef ASM_IF_ACMPNE
#undef ASM_IF_ICMPEQ
#undef ASM_IF_ICMPGE
#undef ASM_IF_ICMPGT
#undef ASM_IF_ICMPLE
#undef ASM_IF_ICMPLT
#undef ASM_IF_ICMPNE
#undef ASM_JSR
#undef ASM_OPCODE_DELTA
#undef ASTORE_0
#undef ASTORE_1
#undef ASTORE_2
#undef ASTORE_3
#undef BOOTSTRAP_METHODS
#undef CODE
#undef CONSTANT_VALUE
#undef DEPRECATED
#undef DLOAD_0
#undef DLOAD_1
#undef DLOAD_2
#undef DLOAD_3
#undef DSTORE_0
#undef DSTORE_1
#undef DSTORE_2
#undef DSTORE_3
#undef ENCLOSING_METHOD
#undef EXCEPTIONS
#undef FLOAD_0
#undef FLOAD_1
#undef FLOAD_2
#undef FLOAD_3
#undef FSTORE_0
#undef FSTORE_1
#undef FSTORE_2
#undef FSTORE_3
#undef F_INSERT
#undef GOTO_W
#undef ILOAD_0
#undef ILOAD_1
#undef ILOAD_2
#undef ILOAD_3
#undef INNER_CLASSES
#undef ISTORE_0
#undef ISTORE_1
#undef ISTORE_2
#undef ISTORE_3
#undef JSR_W
#undef LDC2_W
#undef LDC_W
#undef LINE_NUMBER_TABLE
#undef LLOAD_0
#undef LLOAD_1
#undef LLOAD_2
#undef LLOAD_3
#undef LOCAL_VARIABLE_TABLE
#undef LOCAL_VARIABLE_TYPE_TABLE
#undef LSTORE_0
#undef LSTORE_1
#undef LSTORE_2
#undef LSTORE_3
#undef METHOD_PARAMETERS
#undef MODULE
#undef MODULE_MAIN_CLASS
#undef MODULE_PACKAGES
#undef NEST_HOST
#undef NEST_MEMBERS
#undef PERMITTED_SUBCLASSES
#undef RECORD
#undef RUNTIME_INVISIBLE_ANNOTATIONS
#undef RUNTIME_INVISIBLE_PARAMETER_ANNOTATIONS
#undef RUNTIME_INVISIBLE_TYPE_ANNOTATIONS
#undef RUNTIME_VISIBLE_ANNOTATIONS
#undef RUNTIME_VISIBLE_PARAMETER_ANNOTATIONS
#undef RUNTIME_VISIBLE_TYPE_ANNOTATIONS
#undef SIGNATURE
#undef SOURCE_DEBUG_EXTENSION
#undef SOURCE_FILE
#undef STACK_MAP_TABLE
#undef SYNTHETIC
#undef WIDE
#undef WIDE_JUMP_OPCODE_DELTA

using $DataInputStream = ::java::io::DataInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Pattern = ::java::util::regex::Pattern;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {

$FieldInfo _Constants_FieldInfo_[] = {
	{"CONSTANT_VALUE", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, CONSTANT_VALUE)},
	{"CODE", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, CODE)},
	{"STACK_MAP_TABLE", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, STACK_MAP_TABLE)},
	{"EXCEPTIONS", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, EXCEPTIONS)},
	{"INNER_CLASSES", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, INNER_CLASSES)},
	{"ENCLOSING_METHOD", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, ENCLOSING_METHOD)},
	{"SYNTHETIC", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, SYNTHETIC)},
	{"SIGNATURE", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, SIGNATURE)},
	{"SOURCE_FILE", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, SOURCE_FILE)},
	{"SOURCE_DEBUG_EXTENSION", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, SOURCE_DEBUG_EXTENSION)},
	{"LINE_NUMBER_TABLE", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, LINE_NUMBER_TABLE)},
	{"LOCAL_VARIABLE_TABLE", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, LOCAL_VARIABLE_TABLE)},
	{"LOCAL_VARIABLE_TYPE_TABLE", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, LOCAL_VARIABLE_TYPE_TABLE)},
	{"DEPRECATED", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, DEPRECATED)},
	{"RUNTIME_VISIBLE_ANNOTATIONS", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, RUNTIME_VISIBLE_ANNOTATIONS)},
	{"RUNTIME_INVISIBLE_ANNOTATIONS", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, RUNTIME_INVISIBLE_ANNOTATIONS)},
	{"RUNTIME_VISIBLE_PARAMETER_ANNOTATIONS", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, RUNTIME_VISIBLE_PARAMETER_ANNOTATIONS)},
	{"RUNTIME_INVISIBLE_PARAMETER_ANNOTATIONS", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, RUNTIME_INVISIBLE_PARAMETER_ANNOTATIONS)},
	{"RUNTIME_VISIBLE_TYPE_ANNOTATIONS", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, RUNTIME_VISIBLE_TYPE_ANNOTATIONS)},
	{"RUNTIME_INVISIBLE_TYPE_ANNOTATIONS", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, RUNTIME_INVISIBLE_TYPE_ANNOTATIONS)},
	{"ANNOTATION_DEFAULT", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, ANNOTATION_DEFAULT)},
	{"BOOTSTRAP_METHODS", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, BOOTSTRAP_METHODS)},
	{"METHOD_PARAMETERS", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, METHOD_PARAMETERS)},
	{"MODULE", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, MODULE)},
	{"MODULE_PACKAGES", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, MODULE_PACKAGES)},
	{"MODULE_MAIN_CLASS", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, MODULE_MAIN_CLASS)},
	{"NEST_HOST", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, NEST_HOST)},
	{"NEST_MEMBERS", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, NEST_MEMBERS)},
	{"PERMITTED_SUBCLASSES", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, PERMITTED_SUBCLASSES)},
	{"RECORD", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Constants, RECORD)},
	{"ACC_CONSTRUCTOR", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ACC_CONSTRUCTOR)},
	{"F_INSERT", "I", nullptr, $STATIC | $FINAL, $constField(Constants, F_INSERT)},
	{"LDC_W", "I", nullptr, $STATIC | $FINAL, $constField(Constants, LDC_W)},
	{"LDC2_W", "I", nullptr, $STATIC | $FINAL, $constField(Constants, LDC2_W)},
	{"ILOAD_0", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ILOAD_0)},
	{"ILOAD_1", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ILOAD_1)},
	{"ILOAD_2", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ILOAD_2)},
	{"ILOAD_3", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ILOAD_3)},
	{"LLOAD_0", "I", nullptr, $STATIC | $FINAL, $constField(Constants, LLOAD_0)},
	{"LLOAD_1", "I", nullptr, $STATIC | $FINAL, $constField(Constants, LLOAD_1)},
	{"LLOAD_2", "I", nullptr, $STATIC | $FINAL, $constField(Constants, LLOAD_2)},
	{"LLOAD_3", "I", nullptr, $STATIC | $FINAL, $constField(Constants, LLOAD_3)},
	{"FLOAD_0", "I", nullptr, $STATIC | $FINAL, $constField(Constants, FLOAD_0)},
	{"FLOAD_1", "I", nullptr, $STATIC | $FINAL, $constField(Constants, FLOAD_1)},
	{"FLOAD_2", "I", nullptr, $STATIC | $FINAL, $constField(Constants, FLOAD_2)},
	{"FLOAD_3", "I", nullptr, $STATIC | $FINAL, $constField(Constants, FLOAD_3)},
	{"DLOAD_0", "I", nullptr, $STATIC | $FINAL, $constField(Constants, DLOAD_0)},
	{"DLOAD_1", "I", nullptr, $STATIC | $FINAL, $constField(Constants, DLOAD_1)},
	{"DLOAD_2", "I", nullptr, $STATIC | $FINAL, $constField(Constants, DLOAD_2)},
	{"DLOAD_3", "I", nullptr, $STATIC | $FINAL, $constField(Constants, DLOAD_3)},
	{"ALOAD_0", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ALOAD_0)},
	{"ALOAD_1", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ALOAD_1)},
	{"ALOAD_2", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ALOAD_2)},
	{"ALOAD_3", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ALOAD_3)},
	{"ISTORE_0", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ISTORE_0)},
	{"ISTORE_1", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ISTORE_1)},
	{"ISTORE_2", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ISTORE_2)},
	{"ISTORE_3", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ISTORE_3)},
	{"LSTORE_0", "I", nullptr, $STATIC | $FINAL, $constField(Constants, LSTORE_0)},
	{"LSTORE_1", "I", nullptr, $STATIC | $FINAL, $constField(Constants, LSTORE_1)},
	{"LSTORE_2", "I", nullptr, $STATIC | $FINAL, $constField(Constants, LSTORE_2)},
	{"LSTORE_3", "I", nullptr, $STATIC | $FINAL, $constField(Constants, LSTORE_3)},
	{"FSTORE_0", "I", nullptr, $STATIC | $FINAL, $constField(Constants, FSTORE_0)},
	{"FSTORE_1", "I", nullptr, $STATIC | $FINAL, $constField(Constants, FSTORE_1)},
	{"FSTORE_2", "I", nullptr, $STATIC | $FINAL, $constField(Constants, FSTORE_2)},
	{"FSTORE_3", "I", nullptr, $STATIC | $FINAL, $constField(Constants, FSTORE_3)},
	{"DSTORE_0", "I", nullptr, $STATIC | $FINAL, $constField(Constants, DSTORE_0)},
	{"DSTORE_1", "I", nullptr, $STATIC | $FINAL, $constField(Constants, DSTORE_1)},
	{"DSTORE_2", "I", nullptr, $STATIC | $FINAL, $constField(Constants, DSTORE_2)},
	{"DSTORE_3", "I", nullptr, $STATIC | $FINAL, $constField(Constants, DSTORE_3)},
	{"ASTORE_0", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASTORE_0)},
	{"ASTORE_1", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASTORE_1)},
	{"ASTORE_2", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASTORE_2)},
	{"ASTORE_3", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASTORE_3)},
	{"WIDE", "I", nullptr, $STATIC | $FINAL, $constField(Constants, WIDE)},
	{"GOTO_W", "I", nullptr, $STATIC | $FINAL, $constField(Constants, GOTO_W)},
	{"JSR_W", "I", nullptr, $STATIC | $FINAL, $constField(Constants, JSR_W)},
	{"WIDE_JUMP_OPCODE_DELTA", "I", nullptr, $STATIC | $FINAL, $constField(Constants, WIDE_JUMP_OPCODE_DELTA)},
	{"ASM_OPCODE_DELTA", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_OPCODE_DELTA)},
	{"ASM_IFNULL_OPCODE_DELTA", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_IFNULL_OPCODE_DELTA)},
	{"ASM_IFEQ", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_IFEQ)},
	{"ASM_IFNE", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_IFNE)},
	{"ASM_IFLT", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_IFLT)},
	{"ASM_IFGE", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_IFGE)},
	{"ASM_IFGT", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_IFGT)},
	{"ASM_IFLE", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_IFLE)},
	{"ASM_IF_ICMPEQ", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_IF_ICMPEQ)},
	{"ASM_IF_ICMPNE", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_IF_ICMPNE)},
	{"ASM_IF_ICMPLT", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_IF_ICMPLT)},
	{"ASM_IF_ICMPGE", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_IF_ICMPGE)},
	{"ASM_IF_ICMPGT", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_IF_ICMPGT)},
	{"ASM_IF_ICMPLE", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_IF_ICMPLE)},
	{"ASM_IF_ACMPEQ", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_IF_ACMPEQ)},
	{"ASM_IF_ACMPNE", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_IF_ACMPNE)},
	{"ASM_GOTO", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_GOTO)},
	{"ASM_JSR", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_JSR)},
	{"ASM_IFNULL", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_IFNULL)},
	{"ASM_IFNONNULL", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_IFNONNULL)},
	{"ASM_GOTO_W", "I", nullptr, $STATIC | $FINAL, $constField(Constants, ASM_GOTO_W)},
	{}
};

$MethodInfo _Constants_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(Constants, init$, void)},
	{"checkAsmExperimental", "(Ljava/lang/Object;)V", nullptr, $STATIC, $staticMethod(Constants, checkAsmExperimental, void, Object$*)},
	{"checkIsPreview", "(Ljava/io/InputStream;)V", nullptr, $STATIC, $staticMethod(Constants, checkIsPreview, void, $InputStream*)},
	{"isWhitelisted", "(Ljava/lang/String;)Z", nullptr, $STATIC, $staticMethod(Constants, isWhitelisted, bool, $String*)},
	{}
};

$ClassInfo _Constants_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.Constants",
	"java.lang.Object",
	nullptr,
	_Constants_FieldInfo_,
	_Constants_MethodInfo_
};

$Object* allocate$Constants($Class* clazz) {
	return $of($alloc(Constants));
}

$String* Constants::CONSTANT_VALUE = nullptr;
$String* Constants::CODE = nullptr;
$String* Constants::STACK_MAP_TABLE = nullptr;
$String* Constants::EXCEPTIONS = nullptr;
$String* Constants::INNER_CLASSES = nullptr;
$String* Constants::ENCLOSING_METHOD = nullptr;
$String* Constants::SYNTHETIC = nullptr;
$String* Constants::SIGNATURE = nullptr;
$String* Constants::SOURCE_FILE = nullptr;
$String* Constants::SOURCE_DEBUG_EXTENSION = nullptr;
$String* Constants::LINE_NUMBER_TABLE = nullptr;
$String* Constants::LOCAL_VARIABLE_TABLE = nullptr;
$String* Constants::LOCAL_VARIABLE_TYPE_TABLE = nullptr;
$String* Constants::DEPRECATED = nullptr;
$String* Constants::RUNTIME_VISIBLE_ANNOTATIONS = nullptr;
$String* Constants::RUNTIME_INVISIBLE_ANNOTATIONS = nullptr;
$String* Constants::RUNTIME_VISIBLE_PARAMETER_ANNOTATIONS = nullptr;
$String* Constants::RUNTIME_INVISIBLE_PARAMETER_ANNOTATIONS = nullptr;
$String* Constants::RUNTIME_VISIBLE_TYPE_ANNOTATIONS = nullptr;
$String* Constants::RUNTIME_INVISIBLE_TYPE_ANNOTATIONS = nullptr;
$String* Constants::ANNOTATION_DEFAULT = nullptr;
$String* Constants::BOOTSTRAP_METHODS = nullptr;
$String* Constants::METHOD_PARAMETERS = nullptr;
$String* Constants::MODULE = nullptr;
$String* Constants::MODULE_PACKAGES = nullptr;
$String* Constants::MODULE_MAIN_CLASS = nullptr;
$String* Constants::NEST_HOST = nullptr;
$String* Constants::NEST_MEMBERS = nullptr;
$String* Constants::PERMITTED_SUBCLASSES = nullptr;
$String* Constants::RECORD = nullptr;

void Constants::init$() {
}

void Constants::checkAsmExperimental(Object$* caller) {
	$init(Constants);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* callerClass = $nc($of(caller))->getClass();
	$var($String, internalName, $nc($($nc(callerClass)->getName()))->replace(u'.', u'/'));
	if (!isWhitelisted(internalName)) {
		checkIsPreview($($nc($(callerClass->getClassLoader()))->getResourceAsStream($$str({internalName, ".class"_s}))));
	}
}

bool Constants::isWhitelisted($String* internalName) {
	$init(Constants);
	$useLocalCurrentObjectStackCache();
	if (!$nc(internalName)->startsWith("jdk/internal/org/objectweb/asm/"_s)) {
		return false;
	}
	$var($String, member, "(Annotation|Class|Field|Method|Module|RecordComponent|Signature)"_s);
	bool var$1 = $nc(internalName)->contains("Test$"_s);
	bool var$0 = var$1 || $Pattern::matches($$str({"jdk/internal/org/objectweb/asm/util/Trace"_s, member, "Visitor(\\$.*)?"_s}), internalName);
	return var$0 || $Pattern::matches($$str({"jdk/internal/org/objectweb/asm/util/Check"_s, member, "Adapter(\\$.*)?"_s}), internalName);
}

void Constants::checkIsPreview($InputStream* classInputStream) {
	$init(Constants);
	$useLocalCurrentObjectStackCache();
	if (classInputStream == nullptr) {
		$throwNew($IllegalStateException, "Bytecode not available, can\'t check class version"_s);
	}
	int32_t minorVersion = 0;
	try {
		$var($DataInputStream, callerClassStream, $new($DataInputStream, classInputStream));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					callerClassStream->readInt();
					minorVersion = callerClassStream->readUnsignedShort();
				} catch ($Throwable& t$) {
					try {
						callerClassStream->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				callerClassStream->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} catch ($IOException& ioe) {
		$throwNew($IllegalStateException, "I/O error, can\'t check class version"_s, ioe);
	}
	if (minorVersion != 0x0000FFFF) {
		$throwNew($IllegalStateException, "ASM9_EXPERIMENTAL can only be used by classes compiled with --enable-preview"_s);
	}
}

Constants::Constants() {
}

void clinit$Constants($Class* class$) {
	$assignStatic(Constants::CONSTANT_VALUE, "ConstantValue"_s);
	$assignStatic(Constants::CODE, "Code"_s);
	$assignStatic(Constants::STACK_MAP_TABLE, "StackMapTable"_s);
	$assignStatic(Constants::EXCEPTIONS, "Exceptions"_s);
	$assignStatic(Constants::INNER_CLASSES, "InnerClasses"_s);
	$assignStatic(Constants::ENCLOSING_METHOD, "EnclosingMethod"_s);
	$assignStatic(Constants::SYNTHETIC, "Synthetic"_s);
	$assignStatic(Constants::SIGNATURE, "Signature"_s);
	$assignStatic(Constants::SOURCE_FILE, "SourceFile"_s);
	$assignStatic(Constants::SOURCE_DEBUG_EXTENSION, "SourceDebugExtension"_s);
	$assignStatic(Constants::LINE_NUMBER_TABLE, "LineNumberTable"_s);
	$assignStatic(Constants::LOCAL_VARIABLE_TABLE, "LocalVariableTable"_s);
	$assignStatic(Constants::LOCAL_VARIABLE_TYPE_TABLE, "LocalVariableTypeTable"_s);
	$assignStatic(Constants::DEPRECATED, "Deprecated"_s);
	$assignStatic(Constants::RUNTIME_VISIBLE_ANNOTATIONS, "RuntimeVisibleAnnotations"_s);
	$assignStatic(Constants::RUNTIME_INVISIBLE_ANNOTATIONS, "RuntimeInvisibleAnnotations"_s);
	$assignStatic(Constants::RUNTIME_VISIBLE_PARAMETER_ANNOTATIONS, "RuntimeVisibleParameterAnnotations"_s);
	$assignStatic(Constants::RUNTIME_INVISIBLE_PARAMETER_ANNOTATIONS, "RuntimeInvisibleParameterAnnotations"_s);
	$assignStatic(Constants::RUNTIME_VISIBLE_TYPE_ANNOTATIONS, "RuntimeVisibleTypeAnnotations"_s);
	$assignStatic(Constants::RUNTIME_INVISIBLE_TYPE_ANNOTATIONS, "RuntimeInvisibleTypeAnnotations"_s);
	$assignStatic(Constants::ANNOTATION_DEFAULT, "AnnotationDefault"_s);
	$assignStatic(Constants::BOOTSTRAP_METHODS, "BootstrapMethods"_s);
	$assignStatic(Constants::METHOD_PARAMETERS, "MethodParameters"_s);
	$assignStatic(Constants::MODULE, "Module"_s);
	$assignStatic(Constants::MODULE_PACKAGES, "ModulePackages"_s);
	$assignStatic(Constants::MODULE_MAIN_CLASS, "ModuleMainClass"_s);
	$assignStatic(Constants::NEST_HOST, "NestHost"_s);
	$assignStatic(Constants::NEST_MEMBERS, "NestMembers"_s);
	$assignStatic(Constants::PERMITTED_SUBCLASSES, "PermittedSubclasses"_s);
	$assignStatic(Constants::RECORD, "Record"_s);
}

$Class* Constants::load$($String* name, bool initialize) {
	$loadClass(Constants, name, initialize, &_Constants_ClassInfo_, clinit$Constants, allocate$Constants);
	return class$;
}

$Class* Constants::class$ = nullptr;

				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk