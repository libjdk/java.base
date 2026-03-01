#include <indify/Indify.h>

#include <indify/Indify$1.h>
#include <indify/Indify$Chunk.h>
#include <indify/Indify$ClassFile.h>
#include <indify/Indify$Loader.h>
#include <indify/Indify$Logic.h>
#include <indify/Indify$Member.h>
#include <java/io/BufferedInputStream.h>
#include <java/io/BufferedOutputStream.h>
#include <java/io/ByteArrayInputStream.h>
#include <java/io/DataInputStream.h>
#include <java/io/DataOutputStream.h>
#include <java/io/File.h>
#include <java/io/FileInputStream.h>
#include <java/io/FileOutputStream.h>
#include <java/io/FilenameFilter.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/InternalError.h>
#include <java/lang/SecurityException.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern.h>
#include <jcpp.h>

#undef INSTRUCTION_CONSTANTS
#undef INSTRUCTION_FORMATS
#undef INSTRUCTION_INFO
#undef INSTRUCTION_NAMES
#undef INSTRUCTION_POPS
#undef OBJ_SIGNATURE
#undef WIDE_SIGNATURE

using $FileArray = $Array<::java::io::File>;
using $Indify$1 = ::indify::Indify$1;
using $Indify$Chunk = ::indify::Indify$Chunk;
using $Indify$ClassFile = ::indify::Indify$ClassFile;
using $Indify$Loader = ::indify::Indify$Loader;
using $Indify$Logic = ::indify::Indify$Logic;
using $Indify$Member = ::indify::Indify$Member;
using $BufferedInputStream = ::java::io::BufferedInputStream;
using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $DataInputStream = ::java::io::DataInputStream;
using $DataOutputStream = ::java::io::DataOutputStream;
using $File = ::java::io::File;
using $FileInputStream = ::java::io::FileInputStream;
using $FileOutputStream = ::java::io::FileOutputStream;
using $FilenameFilter = ::java::io::FilenameFilter;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $AssertionError = ::java::lang::AssertionError;
using $Byte = ::java::lang::Byte;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $Double = ::java::lang::Double;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityException = ::java::lang::SecurityException;
using $Short = ::java::lang::Short;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Constructor = ::java::lang::reflect::Constructor;
using $Method = ::java::lang::reflect::Method;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern = ::java::util::regex::Pattern;

namespace indify {

$FieldInfo _Indify_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Indify, $assertionsDisabled)},
	{"dest", "Ljava/io/File;", nullptr, $PUBLIC, $field(Indify, dest)},
	{"classpath", "[Ljava/lang/String;", nullptr, $PUBLIC, $field(Indify, classpath)},
	{"keepgoing", "Z", nullptr, $PUBLIC, $field(Indify, keepgoing)},
	{"expandProperties", "Z", nullptr, $PUBLIC, $field(Indify, expandProperties)},
	{"overwrite", "Z", nullptr, $PUBLIC, $field(Indify, overwrite)},
	{"quiet", "Z", nullptr, $PUBLIC, $field(Indify, quiet)},
	{"verbose", "Z", nullptr, $PUBLIC, $field(Indify, verbose)},
	{"all", "Z", nullptr, $PUBLIC, $field(Indify, all)},
	{"verifySpecifierCount", "I", nullptr, $PUBLIC, $field(Indify, verifySpecifierCount)},
	{"CONSTANT_Utf8", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, CONSTANT_Utf8)},
	{"CONSTANT_Integer", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, CONSTANT_Integer)},
	{"CONSTANT_Float", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, CONSTANT_Float)},
	{"CONSTANT_Long", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, CONSTANT_Long)},
	{"CONSTANT_Double", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, CONSTANT_Double)},
	{"CONSTANT_Class", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, CONSTANT_Class)},
	{"CONSTANT_String", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, CONSTANT_String)},
	{"CONSTANT_Field", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, CONSTANT_Field)},
	{"CONSTANT_Method", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, CONSTANT_Method)},
	{"CONSTANT_InterfaceMethod", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, CONSTANT_InterfaceMethod)},
	{"CONSTANT_NameAndType", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, CONSTANT_NameAndType)},
	{"CONSTANT_MethodHandle", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, CONSTANT_MethodHandle)},
	{"CONSTANT_MethodType", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, CONSTANT_MethodType)},
	{"CONSTANT_InvokeDynamic", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, CONSTANT_InvokeDynamic)},
	{"REF_getField", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, REF_getField)},
	{"REF_getStatic", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, REF_getStatic)},
	{"REF_putField", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, REF_putField)},
	{"REF_putStatic", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, REF_putStatic)},
	{"REF_invokeVirtual", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, REF_invokeVirtual)},
	{"REF_invokeStatic", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, REF_invokeStatic)},
	{"REF_invokeSpecial", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, REF_invokeSpecial)},
	{"REF_newInvokeSpecial", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, REF_newInvokeSpecial)},
	{"REF_invokeInterface", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, REF_invokeInterface)},
	{"opc_nop", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_nop)},
	{"opc_aconst_null", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_aconst_null)},
	{"opc_nconst_MIN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_nconst_MIN)},
	{"opc_nconst_MAX", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_nconst_MAX)},
	{"opc_bipush", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_bipush)},
	{"opc_sipush", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_sipush)},
	{"opc_ldc", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_ldc)},
	{"opc_ldc_w", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_ldc_w)},
	{"opc_ldc2_w", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_ldc2_w)},
	{"opc_aload", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_aload)},
	{"opc_aload_0", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_aload_0)},
	{"opc_aload_MAX", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_aload_MAX)},
	{"opc_aaload", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_aaload)},
	{"opc_astore", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_astore)},
	{"opc_astore_0", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_astore_0)},
	{"opc_astore_MAX", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_astore_MAX)},
	{"opc_aastore", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_aastore)},
	{"opc_pop", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_pop)},
	{"opc_pop2", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_pop2)},
	{"opc_dup", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_dup)},
	{"opc_dup_x1", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_dup_x1)},
	{"opc_dup_x2", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_dup_x2)},
	{"opc_dup2", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_dup2)},
	{"opc_dup2_x1", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_dup2_x1)},
	{"opc_dup2_x2", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_dup2_x2)},
	{"opc_swap", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_swap)},
	{"opc_tableswitch", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_tableswitch)},
	{"opc_lookupswitch", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_lookupswitch)},
	{"opc_areturn", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_areturn)},
	{"opc_getstatic", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_getstatic)},
	{"opc_putstatic", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_putstatic)},
	{"opc_getfield", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_getfield)},
	{"opc_putfield", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_putfield)},
	{"opc_invokevirtual", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_invokevirtual)},
	{"opc_invokespecial", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_invokespecial)},
	{"opc_invokestatic", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_invokestatic)},
	{"opc_invokeinterface", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_invokeinterface)},
	{"opc_invokedynamic", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_invokedynamic)},
	{"opc_new", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_new)},
	{"opc_anewarray", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_anewarray)},
	{"opc_checkcast", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_checkcast)},
	{"opc_ifnull", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_ifnull)},
	{"opc_ifnonnull", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_ifnonnull)},
	{"opc_wide", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Indify, opc_wide)},
	{"INSTRUCTION_CONSTANTS", "[Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Indify, INSTRUCTION_CONSTANTS)},
	{"INSTRUCTION_FORMATS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Indify, INSTRUCTION_FORMATS)},
	{"INSTRUCTION_NAMES", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Indify, INSTRUCTION_NAMES)},
	{"INSTRUCTION_POPS", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Indify, INSTRUCTION_POPS)},
	{"INSTRUCTION_INFO", "[I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Indify, INSTRUCTION_INFO)},
	{"OBJ_SIGNATURE", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Indify, OBJ_SIGNATURE)},
	{"WIDE_SIGNATURE", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Indify, WIDE_SIGNATURE)},
	{}
};

$MethodInfo _Indify_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Indify, init$, void)},
	{"argsize", "(Ljava/lang/String;)I", nullptr, $STATIC, $staticMethod(Indify, argsize, int32_t, $String*)},
	{"booleanOption", "(Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(Indify, booleanOption, bool, $String*)},
	{"classPathFile", "(Ljava/io/File;Ljava/lang/String;)Ljava/io/File;", nullptr, 0, $virtualMethod(Indify, classPathFile, $File*, $File*, $String*)},
	{"ensureDirectory", "(Ljava/io/File;)V", nullptr, $PRIVATE, $method(Indify, ensureDirectory, void, $File*)},
	{"findMember", "(Ljava/util/List;II)Lindify/Indify$Member;", "<T:Lindify/Indify$Member;>(Ljava/util/List<TT;>;II)TT;", $PRIVATE | $STATIC, $staticMethod(Indify, findMember, $Indify$Member*, $List*, int32_t, int32_t)},
	{"indify", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Indify, indify, void, $String*), "java.io.IOException"},
	{"indifyFile", "(Ljava/io/File;Ljava/io/File;)V", nullptr, $PUBLIC, $virtualMethod(Indify, indifyFile, void, $File*, $File*), "java.io.IOException"},
	{"indifyJar", "(Ljava/io/File;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Indify, indifyJar, void, $File*, Object$*), "java.io.IOException"},
	{"indifyTree", "(Ljava/io/File;Ljava/io/File;)V", nullptr, $PUBLIC, $virtualMethod(Indify, indifyTree, void, $File*, $File*), "java.io.IOException"},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(Indify, main, void, $StringArray*), "java.io.IOException"},
	{"makeClassLoader", "()Ljava/lang/ClassLoader;", nullptr, $PUBLIC, $virtualMethod(Indify, makeClassLoader, $ClassLoader*)},
	{"maybeExpandProperties", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Indify, maybeExpandProperties, $String*, $String*)},
	{"openInput", "(Ljava/io/File;)Ljava/io/DataInputStream;", nullptr, $PRIVATE, $method(Indify, openInput, $DataInputStream*, $File*), "java.io.IOException"},
	{"openOutput", "(Ljava/io/File;)Ljava/io/DataOutputStream;", nullptr, $PRIVATE, $method(Indify, openOutput, $DataOutputStream*, $File*), "java.io.IOException"},
	{"parseOptions", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/lang/String;>;)V", $PUBLIC, $virtualMethod(Indify, parseOptions, void, $List*), "java.io.IOException"},
	{"readInput", "(Ljava/io/DataInputStream;Ljava/lang/Class;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/io/DataInputStream;Ljava/lang/Class<TT;>;)TT;", $PRIVATE | $STATIC, $staticMethod(Indify, readInput, $Object*, $DataInputStream*, $Class*), "java.io.IOException"},
	{"readInput", "([BLjava/lang/Class;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>([BLjava/lang/Class<TT;>;)TT;", $PRIVATE | $STATIC, $staticMethod(Indify, readInput, $Object*, $bytes*, $Class*)},
	{"readInputs", "(Ljava/io/DataInputStream;[Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(Indify, readInputs, void, $DataInputStream*, $ObjectArray*), "java.io.IOException"},
	{"readRawBytes", "(Ljava/io/DataInputStream;I)[B", nullptr, $STATIC, $staticMethod(Indify, readRawBytes, $bytes*, $DataInputStream*, int32_t), "java.io.IOException"},
	{"run", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(Indify, run, void, $StringArray*), "java.io.IOException"},
	{"runApplication", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(Indify, runApplication, void, $StringArray*), "java.lang.Exception"},
	{"simplifyType", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(Indify, simplifyType, $String*, $String*)},
	{"writeOutput", "(Ljava/io/DataOutputStream;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Indify, writeOutput, void, $DataOutputStream*, Object$*), "java.io.IOException"},
	{"writeOutputs", "(Ljava/io/DataOutputStream;[Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(Indify, writeOutputs, void, $DataOutputStream*, $ObjectArray*), "java.io.IOException"},
	{}
};

$InnerClassInfo _Indify_InnerClassesInfo_[] = {
	{"indify.Indify$Instruction", "indify.Indify", "Instruction", $PUBLIC | $STATIC},
	{"indify.Indify$Code", "indify.Indify", "Code", $PUBLIC | $STATIC},
	{"indify.Indify$Attr", "indify.Indify", "Attr", $PUBLIC | $STATIC},
	{"indify.Indify$Method", "indify.Indify", "Method", $PUBLIC | $STATIC},
	{"indify.Indify$Field", "indify.Indify", "Field", $PUBLIC | $STATIC},
	{"indify.Indify$Member", "indify.Indify", "Member", $PUBLIC | $STATIC},
	{"indify.Indify$ClassFile", "indify.Indify", "ClassFile", $PUBLIC},
	{"indify.Indify$Pool", "indify.Indify", "Pool", $PUBLIC | $STATIC},
	{"indify.Indify$Constant", "indify.Indify", "Constant", $PUBLIC | $STATIC},
	{"indify.Indify$InnerOuter", "indify.Indify", "InnerOuter", $PUBLIC | $STATIC | $ABSTRACT},
	{"indify.Indify$Inner", "indify.Indify", "Inner", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"indify.Indify$Outer", "indify.Indify", "Outer", $PUBLIC | $STATIC | $ABSTRACT},
	{"indify.Indify$CountedList", "indify.Indify", "CountedList", $PRIVATE | $STATIC},
	{"indify.Indify$Chunk", "indify.Indify", "Chunk", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{"indify.Indify$Logic", "indify.Indify", "Logic", $PRIVATE},
	{"indify.Indify$Loader", "indify.Indify", "Loader", $PRIVATE},
	{"indify.Indify$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Indify_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"indify.Indify",
	"java.lang.Object",
	nullptr,
	_Indify_FieldInfo_,
	_Indify_MethodInfo_,
	nullptr,
	nullptr,
	_Indify_InnerClassesInfo_,
	nullptr,
	nullptr,
	"indify.Indify$Instruction,indify.Indify$Code,indify.Indify$Attr,indify.Indify$Method,indify.Indify$Field,indify.Indify$Member,indify.Indify$ClassFile,indify.Indify$Pool,indify.Indify$Constant,indify.Indify$InnerOuter,indify.Indify$Inner,indify.Indify$Outer,indify.Indify$CountedList,indify.Indify$Chunk,indify.Indify$Logic,indify.Indify$Logic$JVMState,indify.Indify$Loader,indify.Indify$1"
};

$Object* allocate$Indify($Class* clazz) {
	return $of($alloc(Indify));
}

bool Indify::$assertionsDisabled = false;
$ObjectArray* Indify::INSTRUCTION_CONSTANTS = nullptr;
$String* Indify::INSTRUCTION_FORMATS = nullptr;
$StringArray* Indify::INSTRUCTION_NAMES = nullptr;
$StringArray* Indify::INSTRUCTION_POPS = nullptr;
$ints* Indify::INSTRUCTION_INFO = nullptr;
$Pattern* Indify::OBJ_SIGNATURE = nullptr;
$Pattern* Indify::WIDE_SIGNATURE = nullptr;

void Indify::init$() {
	$set(this, classpath, $new($StringArray, {"."_s}));
	this->keepgoing = false;
	this->expandProperties = false;
	this->overwrite = false;
	this->quiet = false;
	this->verbose = false;
	this->all = false;
	this->verifySpecifierCount = -1;
}

void Indify::main($StringArray* av) {
	$init(Indify);
	$$new(Indify)->run(av);
}

void Indify::run($StringArray* av) {
	$useLocalCurrentObjectStackCache();
	$var($List, avl, $new($ArrayList, $(static_cast<$Collection*>($Arrays::asList(av)))));
	parseOptions(avl);
	if (avl->isEmpty()) {
		$throwNew($IllegalArgumentException, "Usage: indify [--dest dir] [option...] file..."_s);
	}
	if ("--java"_s->equals($(avl->get(0)))) {
		avl->remove(0);
		try {
			runApplication($fcast($StringArray, $(avl->toArray($$new($StringArray, 0)))));
		} catch ($Exception& ex) {
			if ($instanceOf($RuntimeException, ex)) {
				$throw($cast($RuntimeException, ex));
			}
			$throwNew($RuntimeException, static_cast<$Throwable*>(ex));
		}
		return;
	}
	$var($Exception, err, nullptr);
	{
		$var($Iterator, i$, avl->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, a, $cast($String, i$->next()));
			{
				try {
					indify(a);
				} catch ($Exception& ex) {
					if (err == nullptr) {
						$assign(err, ex);
					}
					$nc($System::err)->println($$str({"failure on "_s, a}));
					if (!this->keepgoing) {
						break;
					}
				}
			}
		}
	}
	if (err != nullptr) {
		if ($instanceOf($IOException, err)) {
			$throw($cast($IOException, err));
		}
		$throw($cast($RuntimeException, err));
	}
}

void Indify::runApplication($StringArray* av$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, av, av$renamed);
	$beforeCallerSensitive();
	$var($List, avl, $new($ArrayList, $(static_cast<$Collection*>($Arrays::asList(av)))));
	$var($String, mainClassName, $cast($String, avl->remove(0)));
	$assign(av, $fcast($StringArray, avl->toArray($$new($StringArray, 0))));
	$Class* mainClass = $Class::forName(mainClassName, true, $(makeClassLoader()));
	$load($StringArray);
	$var($Method, main, $nc(mainClass)->getMethod("main"_s, $$new($ClassArray, {$getClass($StringArray)})));
	try {
		$nc(main)->setAccessible(true);
	} catch ($SecurityException& ex) {
	}
	$nc(main)->invoke(nullptr, $$new($ObjectArray, {$of(av)}));
}

void Indify::parseOptions($List* av) {
	$useLocalCurrentObjectStackCache();
	for (; !$nc(av)->isEmpty(); $nc(av)->remove(0)) {
		$var($String, a, $cast($String, av->get(0)));
		if ($nc(a)->startsWith("-"_s)) {
			$var($String, a2, nullptr);
			int32_t eq = a->indexOf((int32_t)u'=');
			if (eq > 0) {
				$assign(a2, maybeExpandProperties($(a->substring(eq + 1))));
				$assign(a, a->substring(0, eq + 1));
			}
			{
				$var($String, s7664$, a);
				int32_t tmp7664$ = -1;
				switch (s7664$->hashCode()) {
				case 0x4F75DFC2:
					{
						if (s7664$->equals("--java"_s)) {
							tmp7664$ = 0;
						}
						break;
					}
				case 1495:
					{
						if (s7664$->equals("-d"_s)) {
							tmp7664$ = 1;
						}
						break;
					}
				case 0x4F733442:
					{
						if (s7664$->equals("--dest"_s)) {
							tmp7664$ = 2;
						}
						break;
					}
				case 0x0000B546:
					{
						if (s7664$->equals("-d="_s)) {
							tmp7664$ = 3;
						}
						break;
					}
				case (int32_t)0x9EF3543B:
					{
						if (s7664$->equals("--dest="_s)) {
							tmp7664$ = 4;
						}
						break;
					}
				case 0x0000B55A:
					{
						if (s7664$->equals("-cp"_s)) {
							tmp7664$ = 5;
						}
						break;
					}
				case 0x1C94DFFD:
					{
						if (s7664$->equals("--classpath"_s)) {
							tmp7664$ = 6;
						}
						break;
					}
				case 1502:
					{
						if (s7664$->equals("-k"_s)) {
							tmp7664$ = 7;
						}
						break;
					}
				case (int32_t)0xB5610FF5:
					{
						if (s7664$->equals("--keepgoing"_s)) {
							tmp7664$ = 8;
						}
						break;
					}
				case (int32_t)0xF6C0EEE8:
					{
						if (s7664$->equals("--keepgoing="_s)) {
							tmp7664$ = 9;
						}
						break;
					}
				case (int32_t)0x9BB6C4A6:
					{
						if (s7664$->equals("--expand-properties"_s)) {
							tmp7664$ = 10;
						}
						break;
					}
				case (int32_t)0xDB21D057:
					{
						if (s7664$->equals("--expand-properties="_s)) {
							tmp7664$ = 11;
						}
						break;
					}
				case 0x40EA608C:
					{
						if (s7664$->equals("--verify-specifier-count"_s)) {
							tmp7664$ = 12;
						}
						break;
					}
				case (int32_t)0xDC61B131:
					{
						if (s7664$->equals("--verify-specifier-count="_s)) {
							tmp7664$ = 13;
						}
						break;
					}
				case (int32_t)0xF0B34DEB:
					{
						if (s7664$->equals("--overwrite"_s)) {
							tmp7664$ = 14;
						}
						break;
					}
				case 0x25B66FB2:
					{
						if (s7664$->equals("--overwrite="_s)) {
							tmp7664$ = 15;
						}
						break;
					}
				case 0x02901001:
					{
						if (s7664$->equals("--all"_s)) {
							tmp7664$ = 16;
						}
						break;
					}
				case 0x4F71F05C:
					{
						if (s7664$->equals("--all="_s)) {
							tmp7664$ = 17;
						}
						break;
					}
				case 1508:
					{
						if (s7664$->equals("-q"_s)) {
							tmp7664$ = 18;
						}
						break;
					}
				case (int32_t)0x9FB1A494:
					{
						if (s7664$->equals("--quiet"_s)) {
							tmp7664$ = 19;
						}
						break;
					}
				case 0x5682EE29:
					{
						if (s7664$->equals("--quiet="_s)) {
							tmp7664$ = 20;
						}
						break;
					}
				case 1513:
					{
						if (s7664$->equals("-v"_s)) {
							tmp7664$ = 21;
						}
						break;
					}
				case 0x6789DFE2:
					{
						if (s7664$->equals("--verbose"_s)) {
							tmp7664$ = 22;
						}
						break;
					}
				case (int32_t)0x89B21C9B:
					{
						if (s7664$->equals("--verbose="_s)) {
							tmp7664$ = 23;
						}
						break;
					}
				}
				switch (tmp7664$) {
				case 0:
					{
						return;
					}
				case 1:
					{}
				case 2:
					{}
				case 3:
					{}
				case 4:
					{
						$set(this, dest, $new($File, a2 != nullptr ? a2 : $(maybeExpandProperties($cast($String, $(av->remove(1)))))));
						break;
					}
				case 5:
					{}
				case 6:
					{
						$init($File);
						$set(this, classpath, $nc($(maybeExpandProperties($cast($String, $(av->remove(1))))))->split($$str({"["_s, $$str($File::pathSeparatorChar), "]"_s})));
						break;
					}
				case 7:
					{}
				case 8:
					{}
				case 9:
					{
						this->keepgoing = booleanOption(a2);
						break;
					}
				case 10:
					{}
				case 11:
					{
						this->expandProperties = booleanOption(a2);
						break;
					}
				case 12:
					{}
				case 13:
					{
						this->verifySpecifierCount = $nc($($Integer::valueOf(a2)))->intValue();
						break;
					}
				case 14:
					{}
				case 15:
					{
						this->overwrite = booleanOption(a2);
						break;
					}
				case 16:
					{}
				case 17:
					{
						this->all = booleanOption(a2);
						break;
					}
				case 18:
					{}
				case 19:
					{}
				case 20:
					{
						this->quiet = booleanOption(a2);
						break;
					}
				case 21:
					{}
				case 22:
					{}
				case 23:
					{
						this->verbose = booleanOption(a2);
						break;
					}
				default:
					{
						$throwNew($IllegalArgumentException, $$str({"unrecognized flag: "_s, a}));
					}
				}
			}
			continue;
		} else {
			break;
		}
	}
	if (this->dest == nullptr && !this->overwrite) {
		$throwNew($RuntimeException, "no output specified; need --dest d or --overwrite"_s);
	}
	if (this->expandProperties) {
		for (int32_t i = 0; i < av->size(); ++i) {
			av->set(i, $(maybeExpandProperties($cast($String, $(av->get(i))))));
		}
	}
}

bool Indify::booleanOption($String* s) {
	$useLocalCurrentObjectStackCache();
	if (s == nullptr) {
		return true;
	}
	{
		$var($String, s9922$, s);
		int32_t tmp9922$ = -1;
		switch ($nc(s9922$)->hashCode()) {
		case 0x0036758E:
			{
				if (s9922$->equals("true"_s)) {
					tmp9922$ = 0;
				}
				break;
			}
		case 0x0001D2E7:
			{
				if (s9922$->equals("yes"_s)) {
					tmp9922$ = 1;
				}
				break;
			}
		case 3551:
			{
				if (s9922$->equals("on"_s)) {
					tmp9922$ = 2;
				}
				break;
			}
		case 49:
			{
				if (s9922$->equals("1"_s)) {
					tmp9922$ = 3;
				}
				break;
			}
		case 0x05CB1923:
			{
				if (s9922$->equals("false"_s)) {
					tmp9922$ = 4;
				}
				break;
			}
		case 3521:
			{
				if (s9922$->equals("no"_s)) {
					tmp9922$ = 5;
				}
				break;
			}
		case 0x0001AD6F:
			{
				if (s9922$->equals("off"_s)) {
					tmp9922$ = 6;
				}
				break;
			}
		case 48:
			{
				if (s9922$->equals("0"_s)) {
					tmp9922$ = 7;
				}
				break;
			}
		}
		switch (tmp9922$) {
		case 0:
			{}
		case 1:
			{}
		case 2:
			{}
		case 3:
			{
				return true;
			}
		case 4:
			{}
		case 5:
			{}
		case 6:
			{}
		case 7:
			{
				return false;
			}
		}
	}
	$throwNew($IllegalArgumentException, $$str({"unrecognized boolean flag="_s, s}));
}

$String* Indify::maybeExpandProperties($String* s$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, s, s$renamed);
	if (!this->expandProperties) {
		return s;
	}
	$var($Set, propsDone, $new($HashSet));
	while ($nc(s)->contains("${"_s)) {
		int32_t lbrk = s->indexOf("${"_s);
		int32_t rbrk = s->indexOf((int32_t)u'}', lbrk);
		if (rbrk < 0) {
			break;
		}
		$var($String, prop, s->substring(lbrk + 2, rbrk));
		if (!propsDone->add(prop)) {
			break;
		}
		$var($String, value, $System::getProperty(prop));
		if (this->verbose) {
			$nc($System::err)->println($$str({"expanding ${"_s, prop, "} => "_s, value}));
		}
		if (value == nullptr) {
			break;
		}
		$var($String, var$0, $$str({$(s->substring(0, lbrk)), value}));
		$assign(s, $concat(var$0, $(s->substring(rbrk + 1))));
	}
	return s;
}

void Indify::indify($String* a) {
	$useLocalCurrentObjectStackCache();
	$var($File, f, $new($File, a));
	$var($String, fn, f->getName());
	bool var$0 = $nc(fn)->endsWith(".class"_s);
	if (var$0 && f->isFile()) {
		indifyFile(f, this->dest);
	} else {
		bool var$2 = fn->endsWith(".jar"_s);
		if (var$2 && f->isFile()) {
			indifyJar(f, this->dest);
		} else if (f->isDirectory()) {
			indifyTree(f, this->dest);
		} else if (!this->keepgoing) {
			$throwNew($RuntimeException, $$str({"unrecognized file: "_s, a}));
		}
	}
}

void Indify::ensureDirectory($File* dir) {
	if ($nc(dir)->mkdirs() && !this->quiet) {
		$nc($System::err)->println($$str({"created "_s, dir}));
	}
}

void Indify::indifyFile($File* f, $File* dest) {
	$useLocalCurrentObjectStackCache();
	if (this->verbose) {
		$nc($System::err)->println($$str({"reading "_s, f}));
	}
	$var($Indify$ClassFile, cf, $new($Indify$ClassFile, this, f));
	$var($Indify$Logic, logic, $new($Indify$Logic, this, cf));
	bool changed = logic->transform();
	logic->reportPatternMethods(this->quiet, this->keepgoing);
	if (changed || this->all) {
		$var($File, outfile, nullptr);
		if (dest != nullptr) {
			ensureDirectory(dest);
			$assign(outfile, classPathFile(dest, $(cf->nameString())));
		} else {
			$assign(outfile, f);
		}
		cf->writeTo(outfile);
		if (!this->quiet) {
			$nc($System::err)->println($$str({"wrote "_s, outfile}));
		}
	}
}

$File* Indify::classPathFile($File* pathDir, $String* className) {
	$useLocalCurrentObjectStackCache();
	$var($String, qualname, $str({$($nc(className)->replace(u'.', u'/')), ".class"_s}));
	$init($File);
	$assign(qualname, $nc(qualname)->replace(u'/', $File::separatorChar));
	return $new($File, pathDir, qualname);
}

void Indify::indifyJar($File* f, Object$* dest) {
	$throwNew($UnsupportedOperationException, "Not yet implemented"_s);
}

void Indify::indifyTree($File* f, $File* dest) {
	$useLocalCurrentObjectStackCache();
	if (this->verbose) {
		$nc($System::err)->println($$str({"reading directory: "_s, f}));
	}
	{
		$var($FileArray, arr$, $nc(f)->listFiles(static_cast<$FilenameFilter*>($$new($Indify$1, this))));
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($File, f2, arr$->get(i$));
			{
				if ($nc($($nc(f2)->getName()))->endsWith(".class"_s)) {
					indifyFile(f2, dest);
				} else if (f2->isDirectory()) {
					indifyTree(f2, dest);
				}
			}
		}
	}
}

$ClassLoader* Indify::makeClassLoader() {
	return $new($Indify$Loader, this);
}

$DataInputStream* Indify::openInput($File* f) {
	$useLocalCurrentObjectStackCache();
	return $new($DataInputStream, $$new($BufferedInputStream, $$new($FileInputStream, f)));
}

$DataOutputStream* Indify::openOutput($File* f) {
	$useLocalCurrentObjectStackCache();
	if (!this->overwrite && $nc(f)->exists()) {
		$throwNew($IOException, $$str({"file already exists: "_s, f}));
	}
	ensureDirectory($($nc(f)->getParentFile()));
	return $new($DataOutputStream, $$new($BufferedOutputStream, $$new($FileOutputStream, f)));
}

$bytes* Indify::readRawBytes($DataInputStream* in, int32_t size) {
	$init(Indify);
	$useLocalCurrentObjectStackCache();
	$var($bytes, bytes, $new($bytes, size));
	int32_t nr = $nc(in)->read(bytes);
	if (nr != size) {
		$throwNew($InternalError, $$str({"wrong size: "_s, $$str(nr)}));
	}
	return bytes;
}

$Object* Indify::readInput($DataInputStream* in, $Class* dataClass) {
	$init(Indify);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Object, data, nullptr);
	$load($Integer);
	if (dataClass == $Integer::class$) {
		$assign(data, $Integer::valueOf($nc(in)->readInt()));
	} else {
		$load($Short);
		if (dataClass == $Short::class$) {
			$assign(data, $Short::valueOf($nc(in)->readShort()));
		} else {
			$load($Byte);
			if (dataClass == $Byte::class$) {
				$assign(data, $Byte::valueOf($nc(in)->readByte()));
			} else if (dataClass == $String::class$) {
				$assign(data, $nc(in)->readUTF());
			} else {
				$load($Indify$Chunk);
				if ($Indify$Chunk::class$->isAssignableFrom(dataClass)) {
					$var($Object, obj, nullptr);
					try {
						$assign(obj, $nc($(dataClass->getDeclaredConstructor($$new($ClassArray, 0))))->newInstance($$new($ObjectArray, 0)));
					} catch ($Exception& ex) {
						$throwNew($RuntimeException, static_cast<$Throwable*>(ex));
					}
					$nc(($cast($Indify$Chunk, obj)))->readFrom(in);
					$assign(data, obj);
				} else {
					$throwNew($InternalError, $$str({"bad input datum: "_s, dataClass}));
				}
			}
		}
	}
	return $of($nc(dataClass)->cast(data));
}

$Object* Indify::readInput($bytes* bytes, $Class* dataClass) {
	$init(Indify);
	$useLocalCurrentObjectStackCache();
	try {
		return $of(readInput($$new($DataInputStream, $$new($ByteArrayInputStream, bytes)), dataClass));
	} catch ($IOException& ex) {
		$throwNew($InternalError);
	}
	$shouldNotReachHere();
}

void Indify::readInputs($DataInputStream* in, $ObjectArray* data) {
	$init(Indify);
	$useLocalCurrentObjectStackCache();
	{
		$var($ObjectArray, arr$, data);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Object0, x, arr$->get(i$));
			$nc(($cast($Indify$Chunk, x)))->readFrom(in);
		}
	}
}

void Indify::writeOutput($DataOutputStream* out, Object$* data) {
	$init(Indify);
	$useLocalCurrentObjectStackCache();
	if (data == nullptr) {
		return;
	}
	if ($instanceOf($Integer, data)) {
		$nc(out)->writeInt($nc(($cast($Integer, data)))->intValue());
	} else if ($instanceOf($Long, data)) {
		$nc(out)->writeLong($nc(($cast($Long, data)))->longValue());
	} else if ($instanceOf($Short, data)) {
		$nc(out)->writeShort($nc(($cast($Short, data)))->shortValue());
	} else if ($instanceOf($Byte, data)) {
		$nc(out)->writeByte($nc(($cast($Byte, data)))->byteValue());
	} else if ($instanceOf($String, data)) {
		$nc(out)->writeUTF($cast($String, data));
	} else if ($instanceOf($bytes, data)) {
		$nc(out)->write($cast($bytes, data));
	} else if ($instanceOf($ObjectArray, data)) {
		{
			$var($ObjectArray, arr$, $cast($ObjectArray, data));
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Object0, x, arr$->get(i$));
				writeOutput(out, x);
			}
		}
	} else if ($instanceOf($Indify$Chunk, data)) {
		$var($Indify$Chunk, x, $cast($Indify$Chunk, data));
		$nc(x)->writeTo(out);
	} else if ($instanceOf($List, data)) {
		{
			$var($Iterator, i$, $nc(($cast($List, data)))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Object, x, i$->next());
				writeOutput(out, x);
			}
		}
	} else {
		$var($String, var$0, $$str({"bad output datum: "_s, data, " : "_s}));
		$throwNew($InternalError, $$concat(var$0, $($nc($of(data))->getClass()->getName())));
	}
}

void Indify::writeOutputs($DataOutputStream* out, $ObjectArray* data) {
	$init(Indify);
	$useLocalCurrentObjectStackCache();
	{
		$var($ObjectArray, arr$, data);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Object0, x, arr$->get(i$));
			writeOutput(out, x);
		}
	}
}

$Indify$Member* Indify::findMember($List* mems, int32_t name, int32_t type) {
	$init(Indify);
	$useLocalCurrentObjectStackCache();
	if (name == 0 || type == 0) {
		return nullptr;
	}
	{
		$var($Iterator, i$, $nc(mems)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Indify$Member, m, $cast($Indify$Member, i$->next()));
			{
				if ($nc(m)->name == name && m->type == type) {
					return m;
				}
			}
		}
	}
	return nullptr;
}

$String* Indify::simplifyType($String* type) {
	$init(Indify);
	$useLocalCurrentObjectStackCache();
	$var($String, simpleType, $nc($($nc(Indify::OBJ_SIGNATURE)->matcher(type)))->replaceAll("L"_s));
	if (!Indify::$assertionsDisabled && !($nc(simpleType)->matches("^\\([A-Z]*\\)[A-Z]$"_s))) {
		$throwNew($AssertionError);
	}
	$assign(simpleType, $nc($($nc(Indify::WIDE_SIGNATURE)->matcher(simpleType)))->replaceAll("\\0_"_s));
	return simpleType;
}

int32_t Indify::argsize($String* type) {
	$init(Indify);
	return $nc($(simplifyType(type)))->length() - 3;
}

void clinit$Indify($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(Indify::INSTRUCTION_FORMATS, "nop$ aconst_null$L iconst_m1$I iconst_0$I iconst_1$I iconst_2$I iconst_3$I iconst_4$I iconst_5$I lconst_0$J_ lconst_1$J_ fconst_0$F fconst_1$F fconst_2$F dconst_0$D_ dconst_1$D_ bipush=bx$I sipush=bxx$I ldc=bk$X ldc_w=bkk$X ldc2_w=bkk$X_ iload=bl/wbll$I lload=bl/wbll$J_ fload=bl/wbll$F dload=bl/wbll$D_ aload=bl/wbll$L iload_0$I iload_1$I iload_2$I iload_3$I lload_0$J_ lload_1$J_ lload_2$J_ lload_3$J_ fload_0$F fload_1$F fload_2$F fload_3$F dload_0$D_ dload_1$D_ dload_2$D_ dload_3$D_ aload_0$L aload_1$L aload_2$L aload_3$L iaload$LI$I laload$LI$J_ faload$LI$F daload$LI$D_ aaload$LI$L baload$LI$I caload$LI$I saload$LI$I istore=bl/wbll$I$ lstore=bl/wbll$J_$ fstore=bl/wbll$F$ dstore=bl/wbll$D_$ astore=bl/wbll$L$ istore_0$I$ istore_1$I$ istore_2$I$ istore_3$I$ lstore_0$J_$ lstore_1$J_$ lstore_2$J_$ lstore_3$J_$ fstore_0$F$ fstore_1$F$ fstore_2$F$ fstore_3$F$ dstore_0$D_$ dstore_1$D_$ dstore_2$D_$ dstore_3$D_$ astore_0$L$ astore_1$L$ astore_2$L$ astore_3$L$ iastore$LII$ lastore$LIJ_$ fastore$LIF$ dastore$LID_$ aast"
		"ore$LIL$ bastore$LII$ castore$LII$ sastore$LII$ pop$X$ pop2$XX$ dup$X$XX dup_x1$XX$XXX dup_x2$XXX$XXXX dup2$XX$XXXX dup2_x1$XXX$XXXXX dup2_x2$XXXX$XXXXXX swap$XX$XX iadd$II$I ladd$J_J_$J_ fadd$FF$F dadd$D_D_$D_ isub$II$I lsub$J_J_$J_ fsub$FF$F dsub$D_D_$D_ imul$II$I lmul$J_J_$J_ fmul$FF$F dmul$D_D_$D_ idiv$II$I ldiv$J_J_$J_ fdiv$FF$F ddiv$D_D_$D_ irem$II$I lrem$J_J_$J_ frem$FF$F drem$D_D_$D_ ineg$I$I lneg$J_$J_ fneg$F$F dneg$D_$D_ ishl$II$I lshl$J_I$J_ ishr$II$I lshr$J_I$J_ iushr$II$I lushr$J_I$J_ iand$II$I land$J_J_$J_ ior$II$I lor$J_J_$J_ ixor$II$I lxor$J_J_$J_ iinc=blx/wbllxx$ i2l$I$J_ i2f$I$F i2d$I$D_ l2i$J_$I l2f$J_$F l2d$J_$D_ f2i$F$I f2l$F$J_ f2d$F$D_ d2i$D_$I d2l$D_$J_ d2f$D_$F i2b$I$I i2c$I$I i2s$I$I lcmp fcmpl fcmpg dcmpl dcmpg ifeq=boo ifne=boo iflt=boo ifge=boo ifgt=boo ifle=boo if_icmpeq=boo if_icmpne=boo if_icmplt=boo if_icmpge=boo if_icmpgt=boo if_icmple=boo if_acmpeq=boo if_acmpne=boo goto=boo jsr=boo ret=bl/wbll tableswitch=* lookupswitch=* ireturn lreturn freturn dreturn areturn return getst"
		"atic=bkf$Q putstatic=bkf$Q$ getfield=bkf$L$Q putfield=bkf$LQ$ invokevirtual=bkm$LQ$Q invokespecial=bkm$LQ$Q invokestatic=bkm$Q$Q invokeinterface=bkixx$LQ$Q invokedynamic=bkd__$Q$Q new=bkc$L newarray=bx$I$L anewarray=bkc$I$L arraylength$L$I athrow checkcast=bkc$L$L instanceof=bkc$L$I monitorenter$L monitorexit$L wide=* multianewarray=bkcx ifnull=boo ifnonnull=boo goto_w=boooo jsr_w=boooo "_s);
	Indify::$assertionsDisabled = !Indify::class$->desiredAssertionStatus();
	$assignStatic(Indify::INSTRUCTION_CONSTANTS, $new($ObjectArray, {
		$($of($Integer::valueOf(-1))),
		$($of($Integer::valueOf(0))),
		$($of($Integer::valueOf(1))),
		$($of($Integer::valueOf(2))),
		$($of($Integer::valueOf(3))),
		$($of($Integer::valueOf(4))),
		$($of($Integer::valueOf(5))),
		$($of($Long::valueOf((int64_t)0))),
		$($of($Long::valueOf((int64_t)1))),
		$($of($Float::valueOf(0.0f))),
		$($of($Float::valueOf(1.0f))),
		$($of($Float::valueOf(2.0f))),
		$($of($Double::valueOf(0.0))),
		$($of($Double::valueOf(1.0)))
	}));
	{
		$var($StringArray, insns, $nc(Indify::INSTRUCTION_FORMATS)->split(" "_s));
		if (!Indify::$assertionsDisabled && !($nc(insns->get(Indify::opc_lookupswitch))->startsWith("lookupswitch"_s))) {
			$throwNew($AssertionError);
		}
		if (!Indify::$assertionsDisabled && !($nc(insns->get(Indify::opc_tableswitch))->startsWith("tableswitch"_s))) {
			$throwNew($AssertionError);
		}
		if (!Indify::$assertionsDisabled && !($nc(insns->get(Indify::opc_wide))->startsWith("wide"_s))) {
			$throwNew($AssertionError);
		}
		if (!Indify::$assertionsDisabled && !($nc(insns->get(Indify::opc_invokedynamic))->startsWith("invokedynamic"_s))) {
			$throwNew($AssertionError);
		}
		$var($ints, info, $new($ints, 256));
		$var($StringArray, names, $new($StringArray, 256));
		$var($StringArray, pops, $new($StringArray, 256));
		for (int32_t i = 0; i < insns->length; ++i) {
			$var($String, insn, insns->get(i));
			int32_t dl = $nc(insn)->indexOf((int32_t)u'$');
			if (dl > 0) {
				$var($String, p, insn->substring(dl + 1));
				if (p->indexOf((int32_t)u'$') < 0) {
					$assign(p, $str({"$"_s, p}));
				}
				pops->set(i, p);
				$assign(insn, insn->substring(0, dl));
			}
			int32_t eq = insn->indexOf((int32_t)u'=');
			if (eq < 0) {
				info->set(i, 1);
				names->set(i, insn);
				continue;
			}
			names->set(i, $(insn->substring(0, eq)));
			$var($String, fmt, insn->substring(eq + 1));
			if (fmt->equals("*"_s)) {
				info->set(i, 0);
				continue;
			}
			int32_t sl = fmt->indexOf((int32_t)u'/');
			if (sl < 0) {
				info->set(i, (char16_t)fmt->length());
			} else {
				$var($String, wfmt, fmt->substring(sl + 1));
				$assign(fmt, fmt->substring(0, sl));
				int32_t var$0 = fmt->length();
				info->set(i, (char16_t)(var$0 + (wfmt->length() * 16)));
			}
		}
		$assignStatic(Indify::INSTRUCTION_INFO, info);
		$assignStatic(Indify::INSTRUCTION_NAMES, names);
		$assignStatic(Indify::INSTRUCTION_POPS, pops);
	}
	$assignStatic(Indify::OBJ_SIGNATURE, $Pattern::compile("\\[*L[^;]*;|\\[+[A-Z]"_s));
	$assignStatic(Indify::WIDE_SIGNATURE, $Pattern::compile("[JD]"_s));
}

Indify::Indify() {
}

$Class* Indify::load$($String* name, bool initialize) {
	$loadClass(Indify, name, initialize, &_Indify_ClassInfo_, clinit$Indify, allocate$Indify);
	return class$;
}

$Class* Indify::class$ = nullptr;

} // indify