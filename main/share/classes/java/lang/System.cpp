#include <java/lang/System.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/BufferedOutputStream.h>
#include <java/io/Console.h>
#include <java/io/FileDescriptor.h>
#include <java/io/FileInputStream.h>
#include <java/io/FileOutputStream.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/Serializable.h>
#include <java/io/UnsupportedEncodingException.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/Error.h>
#include <java/lang/IllegalCallerException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Module.h>
#include <java/lang/ModuleLayer.h>
#include <java/lang/ProcessEnvironment.h>
#include <java/lang/Runtime.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/System$1.h>
#include <java/lang/System$2.h>
#include <java/lang/System$CallersHolder.h>
#include <java/lang/System$Logger.h>
#include <java/lang/System$LoggerFinder.h>
#include <java/lang/Terminator.h>
#include <java/lang/ThreadGroup.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/VersionProps.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/StringConcatFactory.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Modifier.h>
#include <java/net/URL.h>
#include <java/nio/channels/Channel.h>
#include <java/nio/channels/spi/SelectorProvider.h>
#include <java/nio/file/FileSystem.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/CodeSource.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/ProtectionDomain.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Properties.h>
#include <java/util/PropertyPermission.h>
#include <java/util/ResourceBundle.h>
#include <java/util/Set.h>
#include <jdk/internal/access/JavaIOAccess.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/logger/LazyLoggers.h>
#include <jdk/internal/misc/Unsafe.h>
#include <jdk/internal/misc/VM.h>
#include <jdk/internal/module/ModuleBootstrap.h>
#include <jdk/internal/reflect/Reflection.h>
#include <jdk/internal/util/StaticProperty.h>
#include <jdk/internal/util/SystemProps.h>
#include <sun/nio/fs/DefaultFileSystemProvider.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#include <java/lang/Array.h>
#include <java/lang/RuntimeException.h>
#include <java/lang/reflect/AccessibleObject.h>
#include <java/lang/ref/Reference.h>
#include <java/lang/Machine.h>
#include <java/lang/ClassEntry.h>
#include <java/lang/ModuleInfo.h>
#include <java/lang/module/Configuration.h>
#include <java/util/List.h>
#include "Platform.h"

//#include "_java_lang_System.h"

using Configuration = ::java::lang::module::Configuration;
using List = ::java::util::List;

#undef LOGGERFINDER_PERMISSION
#undef MAYBE
#undef NEVER
#undef PROPERTY_WRITE_ACTION

using $ThrowableArray = $Array<::java::lang::Throwable>;
using $PermissionArray = $Array<::java::security::Permission>;
using $BufferedInputStream = ::java::io::BufferedInputStream;
using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $Console = ::java::io::Console;
using $FileDescriptor = ::java::io::FileDescriptor;
using $FileInputStream = ::java::io::FileInputStream;
using $FileOutputStream = ::java::io::FileOutputStream;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalCallerException = ::java::lang::IllegalCallerException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $ModuleLayer = ::java::lang::ModuleLayer;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $NullPointerException = ::java::lang::NullPointerException;
using $ProcessEnvironment = ::java::lang::ProcessEnvironment;
using $Runtime = ::java::lang::Runtime;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $System$1 = ::java::lang::System$1;
using $System$2 = ::java::lang::System$2;
using $System$CallersHolder = ::java::lang::System$CallersHolder;
using $System$Logger = ::java::lang::System$Logger;
using $System$LoggerFinder = ::java::lang::System$LoggerFinder;
using $Terminator = ::java::lang::Terminator;
using $ThreadGroup = ::java::lang::ThreadGroup;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $VersionProps = ::java::lang::VersionProps;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $StringConcatFactory = ::java::lang::invoke::StringConcatFactory;
using $Constructor = ::java::lang::reflect::Constructor;
using $Modifier = ::java::lang::reflect::Modifier;
using $URL = ::java::net::URL;
using $Channel = ::java::nio::channels::Channel;
using $SelectorProvider = ::java::nio::channels::spi::SelectorProvider;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $CodeSource = ::java::security::CodeSource;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Objects = ::java::util::Objects;
using $Properties = ::java::util::Properties;
using $PropertyPermission = ::java::util::PropertyPermission;
using $ResourceBundle = ::java::util::ResourceBundle;
using $Set = ::java::util::Set;
using $JavaIOAccess = ::jdk::internal::access::JavaIOAccess;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $LazyLoggers = ::jdk::internal::logger::LazyLoggers;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $VM = ::jdk::internal::misc::VM;
using $ModuleBootstrap = ::jdk::internal::module::ModuleBootstrap;
using $Reflection = ::jdk::internal::reflect::Reflection;
using $StaticProperty = ::jdk::internal::util::StaticProperty;
using $SystemProps = ::jdk::internal::util::SystemProps;
using $DefaultFileSystemProvider = ::sun::nio::fs::DefaultFileSystemProvider;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace java {
	namespace lang {

class System$$Lambda$getProtectionDomain : public $PrivilegedAction {
	$class(System$$Lambda$getProtectionDomain, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($Class* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->getProtectionDomain());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<System$$Lambda$getProtectionDomain>());
	}
	$Class* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo System$$Lambda$getProtectionDomain::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(System$$Lambda$getProtectionDomain, inst$)},
	{}
};
$MethodInfo System$$Lambda$getProtectionDomain::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Class;)V", nullptr, $PUBLIC, $method(System$$Lambda$getProtectionDomain, init$, void, $Class*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(System$$Lambda$getProtectionDomain, run, $Object*)},
	{}
};
$ClassInfo System$$Lambda$getProtectionDomain::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.System$$Lambda$getProtectionDomain",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* System$$Lambda$getProtectionDomain::load$($String* name, bool initialize) {
	$loadClass(System$$Lambda$getProtectionDomain, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* System$$Lambda$getProtectionDomain::class$ = nullptr;

class System$$Lambda$lambda$getLogger$0$1 : public $PrivilegedAction {
	$class(System$$Lambda$lambda$getLogger$0$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($String* name, $ResourceBundle* rb, $Class* caller) {
		$set(this, name, name);
		$set(this, rb, rb);
		this->caller = caller;
	}
	virtual $Object* run() override {
		 return $of(System::lambda$getLogger$0(name, rb, caller));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<System$$Lambda$lambda$getLogger$0$1>());
	}
	$String* name = nullptr;
	$ResourceBundle* rb = nullptr;
	$Class* caller = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo System$$Lambda$lambda$getLogger$0$1::fieldInfos[4] = {
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(System$$Lambda$lambda$getLogger$0$1, name)},
	{"rb", "Ljava/util/ResourceBundle;", nullptr, $PUBLIC, $field(System$$Lambda$lambda$getLogger$0$1, rb)},
	{"caller", "Ljava/lang/Class;", nullptr, $PUBLIC, $field(System$$Lambda$lambda$getLogger$0$1, caller)},
	{}
};
$MethodInfo System$$Lambda$lambda$getLogger$0$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;Ljava/util/ResourceBundle;Ljava/lang/Class;)V", nullptr, $PUBLIC, $method(System$$Lambda$lambda$getLogger$0$1, init$, void, $String*, $ResourceBundle*, $Class*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(System$$Lambda$lambda$getLogger$0$1, run, $Object*)},
	{}
};
$ClassInfo System$$Lambda$lambda$getLogger$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.System$$Lambda$lambda$getLogger$0$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* System$$Lambda$lambda$getLogger$0$1::load$($String* name, bool initialize) {
	$loadClass(System$$Lambda$lambda$getLogger$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* System$$Lambda$lambda$getLogger$0$1::class$ = nullptr;

$CompoundAttribute _System_FieldAnnotations_allowSecurityManager[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _System_FieldAnnotations_initialErrStream[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _System_MethodAnnotations_arraycopy2[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _System_MethodAnnotations_currentTimeMillis9[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _System_MethodAnnotations_getLogger12[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _System_MethodAnnotations_getLogger13[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$NamedAttribute System_Attribute_var$0[] = {
	{"since", 's', "17"},
	{"forRemoval", 'Z', "true"},
	{}
};

$CompoundAttribute _System_MethodAnnotations_getSecurityManager17[] = {
	{"Ljava/lang/Deprecated;", System_Attribute_var$0},
	{}
};

$CompoundAttribute _System_MethodAnnotations_identityHashCode20[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _System_MethodAnnotations_load28[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _System_MethodAnnotations_loadLibrary29[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _System_MethodAnnotations_nanoTime32[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$NamedAttribute System_Attribute_var$1[] = {
	{"since", 's', "17"},
	{"forRemoval", 'Z', "true"},
	{}
};

$CompoundAttribute _System_MethodAnnotations_setSecurityManager45[] = {
	{"Ljava/lang/Deprecated;", System_Attribute_var$1},
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$FieldInfo _System_FieldInfo_[] = {
	{"in", "Ljava/io/InputStream;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(System, in)},
	{"out", "Ljava/io/PrintStream;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(System, out)},
	{"err", "Ljava/io/PrintStream;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(System, err)},
	{"NEVER", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(System, NEVER)},
	{"MAYBE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(System, MAYBE)},
	{"allowSecurityManager", "I", nullptr, $PRIVATE | $STATIC, $staticField(System, allowSecurityManager$), _System_FieldAnnotations_allowSecurityManager},
	{"security", "Ljava/lang/SecurityManager;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(System, security)},
	{"cons", "Ljava/io/Console;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(System, cons)},
	{"initialErrStream", "Ljava/io/PrintStream;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(System, initialErrStream), _System_FieldAnnotations_initialErrStream},
	{"props", "Ljava/util/Properties;", nullptr, $PRIVATE | $STATIC, $staticField(System, props)},
	{"lineSeparator", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(System, lineSeparator$)},
	{"bootLayer", "Ljava/lang/ModuleLayer;", nullptr, $STATIC, $staticField(System, bootLayer)},
	{}
};

$MethodInfo _System_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(System, init$, void)},
	{"allowSecurityManager", "()Z", nullptr, $PRIVATE | $STATIC, $staticMethod(System, allowSecurityManager, bool)},
	{"arraycopy", "(Ljava/lang/Object;ILjava/lang/Object;II)V", nullptr, $PUBLIC | $STATIC | $NATIVE, $staticMethod(System, arraycopy, void, Object$*, int32_t, Object$*, int32_t, int32_t), nullptr, nullptr, _System_MethodAnnotations_arraycopy2},
	{"checkIO", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(System, checkIO, void)},
	{"checkKey", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(System, checkKey, void, $String*)},
	{"clearProperty", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(System, clearProperty, $String*, $String*)},
	{"codeSource", "(Ljava/lang/Class;)Ljava/net/URL;", "(Ljava/lang/Class<*>;)Ljava/net/URL;", $PRIVATE | $STATIC, $staticMethod(System, codeSource, $URL*, $Class*)},
	{"console", "()Ljava/io/Console;", nullptr, $PUBLIC | $STATIC, $staticMethod(System, console, $Console*)},
	{"createProperties", "(Ljava/util/Map;)Ljava/util/Properties;", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)Ljava/util/Properties;", $PRIVATE | $STATIC, $staticMethod(System, createProperties, $Properties*, $Map*)},
	{"currentTimeMillis", "()J", nullptr, $PUBLIC | $STATIC | $NATIVE, $staticMethod(System, currentTimeMillis, int64_t), nullptr, nullptr, _System_MethodAnnotations_currentTimeMillis9},
	{"exit", "(I)V", nullptr, $PUBLIC | $STATIC, $staticMethod(System, exit, void, int32_t)},
	{"gc", "()V", nullptr, $PUBLIC | $STATIC, $staticMethod(System, gc, void)},
	{"getLogger", "(Ljava/lang/String;)Ljava/lang/System$Logger;", nullptr, $PUBLIC | $STATIC, $staticMethod(System, getLogger, $System$Logger*, $String*), nullptr, nullptr, _System_MethodAnnotations_getLogger12},
	{"getLogger", "(Ljava/lang/String;Ljava/util/ResourceBundle;)Ljava/lang/System$Logger;", nullptr, $PUBLIC | $STATIC, $staticMethod(System, getLogger, $System$Logger*, $String*, $ResourceBundle*), nullptr, nullptr, _System_MethodAnnotations_getLogger13},
	{"getProperties", "()Ljava/util/Properties;", nullptr, $PUBLIC | $STATIC, $staticMethod(System, getProperties, $Properties*)},
	{"getProperty", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(System, getProperty, $String*, $String*)},
	{"getProperty", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(System, getProperty, $String*, $String*, $String*)},
	{"getSecurityManager", "()Ljava/lang/SecurityManager;", nullptr, $PUBLIC | $STATIC | $DEPRECATED, $staticMethod(System, getSecurityManager, $SecurityManager*), nullptr, nullptr, _System_MethodAnnotations_getSecurityManager17},
	{"getenv", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(System, getenv, $String*, $String*)},
	{"getenv", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(System, getenv, $Map*)},
	{"identityHashCode", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $STATIC | $NATIVE, $staticMethod(System, identityHashCode, int32_t, Object$*), nullptr, nullptr, _System_MethodAnnotations_identityHashCode20},
	{"implSetSecurityManager", "(Ljava/lang/SecurityManager;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(System, implSetSecurityManager, void, $SecurityManager*)},
	{"inheritedChannel", "()Ljava/nio/channels/Channel;", nullptr, $PUBLIC | $STATIC, $staticMethod(System, inheritedChannel, $Channel*), "java.io.IOException"},
	{"initPhase1", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(System, initPhase1, void)},
	{"initPhase2", "(ZZ)I", nullptr, $PRIVATE | $STATIC, $staticMethod(System, initPhase2, int32_t, bool, bool)},
	{"initPhase3", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(System, initPhase3, void)},
	{"lambda$getLogger$0", "(Ljava/lang/String;Ljava/util/ResourceBundle;Ljava/lang/Class;)Ljava/lang/System$Logger;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(System, lambda$getLogger$0, $System$Logger*, $String*, $ResourceBundle*, $Class*)},
	{"lineSeparator", "()Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(System, lineSeparator, $String*)},
	{"load", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(System, load, void, $String*), nullptr, nullptr, _System_MethodAnnotations_load28},
	{"loadLibrary", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(System, loadLibrary, void, $String*), nullptr, nullptr, _System_MethodAnnotations_loadLibrary29},
	{"logInitException", "(ZZLjava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(System, logInitException, void, bool, bool, $String*, $Throwable*)},
	{"mapLibraryName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $NATIVE, $staticMethod(System, mapLibraryName, $String*, $String*)},
	{"nanoTime", "()J", nullptr, $PUBLIC | $STATIC | $NATIVE, $staticMethod(System, nanoTime, int64_t), nullptr, nullptr, _System_MethodAnnotations_nanoTime32},
	{"newPrintStream", "(Ljava/io/FileOutputStream;Ljava/lang/String;)Ljava/io/PrintStream;", nullptr, $PRIVATE | $STATIC, $staticMethod(System, newPrintStream, $PrintStream*, $FileOutputStream*, $String*)},
	{"registerNatives", "()V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(System, registerNatives, void)},
	{"runFinalization", "()V", nullptr, $PUBLIC | $STATIC, $staticMethod(System, runFinalization, void)},
	{"setErr", "(Ljava/io/PrintStream;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(System, setErr, void, $PrintStream*)},
	{"setErr0", "(Ljava/io/PrintStream;)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(System, setErr0, void, $PrintStream*)},
	{"setIn", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(System, setIn, void, $InputStream*)},
	{"setIn0", "(Ljava/io/InputStream;)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(System, setIn0, void, $InputStream*)},
	{"setJavaLangAccess", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(System, setJavaLangAccess, void)},
	{"setOut", "(Ljava/io/PrintStream;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(System, setOut, void, $PrintStream*)},
	{"setOut0", "(Ljava/io/PrintStream;)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(System, setOut0, void, $PrintStream*)},
	{"setProperties", "(Ljava/util/Properties;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(System, setProperties, void, $Properties*)},
	{"setProperty", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(System, setProperty, $String*, $String*, $String*)},
	{"setSecurityManager", "(Ljava/lang/SecurityManager;)V", nullptr, $PUBLIC | $STATIC | $DEPRECATED, $staticMethod(System, setSecurityManager, void, $SecurityManager*), nullptr, nullptr, _System_MethodAnnotations_setSecurityManager45},
	{"setSecurityManager0", "(Ljava/lang/SecurityManager;)V", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $staticMethod(System, setSecurityManager0, void, $SecurityManager*)},
	{}
};

#define _METHOD_INDEX_arraycopy 2
#define _METHOD_INDEX_currentTimeMillis 9
#define _METHOD_INDEX_identityHashCode 20
#define _METHOD_INDEX_mapLibraryName 31
#define _METHOD_INDEX_nanoTime 32
#define _METHOD_INDEX_registerNatives 34
#define _METHOD_INDEX_setErr0 37
#define _METHOD_INDEX_setIn0 39
#define _METHOD_INDEX_setOut0 42

$InnerClassInfo _System_InnerClassesInfo_[] = {
	{"java.lang.System$LoggerFinder", "java.lang.System", "LoggerFinder", $PUBLIC | $STATIC | $ABSTRACT},
	{"java.lang.System$Logger", "java.lang.System", "Logger", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.lang.System$CallersHolder", "java.lang.System", "CallersHolder", $PRIVATE | $STATIC},
	{"java.lang.System$2", nullptr, nullptr, 0},
	{"java.lang.System$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _System_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.lang.System",
	"java.lang.Object",
	nullptr,
	_System_FieldInfo_,
	_System_MethodInfo_,
	nullptr,
	nullptr,
	_System_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.System$LoggerFinder,java.lang.System$Logger,java.lang.System$Logger$Level,java.lang.System$CallersHolder,java.lang.System$2,java.lang.System$1"
};

$Object* allocate$System($Class* clazz) {
	return $of($alloc(System));
}

$InputStream* System::in = nullptr;
$PrintStream* System::out = nullptr;
$PrintStream* System::err = nullptr;
int32_t System::allowSecurityManager$ = 0;
$volatile($SecurityManager*) System::security = nullptr;
$volatile($Console*) System::cons = nullptr;
$volatile($PrintStream*) System::initialErrStream = nullptr;
$Properties* System::props = nullptr;
$String* System::lineSeparator$ = nullptr;
$ModuleLayer* System::bootLayer = nullptr;

void System::registerNatives() {
}

void System::init$() {
}

bool System::allowSecurityManager() {
	return (System::allowSecurityManager$ != System::NEVER);
}

void System::setIn($InputStream* in) {
	checkIO();
	setIn0(in);
}

void System::setOut($PrintStream* out) {
	checkIO();
	setOut0(out);
}

void System::setErr($PrintStream* err) {
	checkIO();
	setErr0(err);
}

$Console* System::console() {
	$useLocalCurrentObjectStackCache();
	$var($Console, c, nullptr);
	if (($assign(c, System::cons)) == nullptr) {
		$synchronized(System::class$) {
			if (($assign(c, System::cons)) == nullptr) {
				$assignStatic(System::cons, ($assign(c, $nc($($SharedSecrets::getJavaIOAccess()))->console())));
			}
		}
	}
	return c;
}

$Channel* System::inheritedChannel() {
	return $nc($($SelectorProvider::provider()))->inheritedChannel();
}

void System::checkIO() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, "setIO"_s));
	}
}

void System::setIn0($InputStream* in) {
	$assignStatic(System::in, in);
}

void System::setOut0($PrintStream* out) {
	$assignStatic(System::out, out);
}

void System::setErr0($PrintStream* err) {
	$assignStatic(System::err, err);
}

$URL* System::codeSource($Class* clazz) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(System$$Lambda$getProtectionDomain, static_cast<$Class*>($nc(clazz)))));
	$var($CodeSource, cs, $nc(($cast($ProtectionDomain, $($AccessController::doPrivileged(pa)))))->getCodeSource());
	return (cs != nullptr) ? $nc(cs)->getLocation() : ($URL*)nullptr;
}

void System::setSecurityManager($SecurityManager* sm) {
	$useLocalCurrentObjectStackCache();
	if (allowSecurityManager()) {
		$Class* callerClass = $Reflection::getCallerClass();
		$init($System$CallersHolder);
		if ($nc($System$CallersHolder::callers)->putIfAbsent(callerClass, $($Boolean::valueOf(true))) == nullptr) {
			$var($URL, url, codeSource(callerClass));
			$var($String, source, nullptr);
			if (url == nullptr) {
				$assign(source, $nc(callerClass)->getName());
			} else {
				$assign(source, $str({$($nc(callerClass)->getName()), " ("_s, url, ")"_s}));
			}
			$nc(System::initialErrStream)->printf("WARNING: A terminally deprecated method in java.lang.System has been called\nWARNING: System::setSecurityManager has been called by %s\nWARNING: Please consider reporting this to the maintainers of %s\nWARNING: System::setSecurityManager will be removed in a future release\n"_s, $$new($ObjectArray, {
				$of(source),
				$($of($nc(callerClass)->getName()))
			}));
		}
		implSetSecurityManager(sm);
	} else if (sm != nullptr) {
		$throwNew($UnsupportedOperationException, "The Security Manager is deprecated and will be removed in a future release"_s);
	}
}

void System::implSetSecurityManager($SecurityManager* sm) {
	$beforeCallerSensitive();
	if (System::security == nullptr) {
		$Object::class$->getResource("java/lang/ANY"_s);
		$DefaultFileSystemProvider::theFileSystem();
	}
	if (sm != nullptr) {
		try {
			sm->checkPackageAccess("java.lang"_s);
		} catch ($Exception& e) {
		}
	}
	setSecurityManager0(sm);
}

void System::setSecurityManager0($SecurityManager* s) {
	$load(System);
	$synchronized(class$) {
		$useLocalCurrentObjectStackCache();
		$beforeCallerSensitive();
		$var($SecurityManager, sm, getSecurityManager());
		if (sm != nullptr) {
			sm->checkPermission($$new($RuntimePermission, "setSecurityManager"_s));
		}
		if ((s != nullptr) && ($of(s)->getClass()->getClassLoader() != nullptr)) {
			$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($System$1, s)));
		}
		$assignStatic(System::security, s);
	}
}

$SecurityManager* System::getSecurityManager() {
	if (allowSecurityManager()) {
		return System::security;
	} else {
		return nullptr;
	}
}

int64_t System::currentTimeMillis() {
	return Platform::getTimeMillis();
}

int64_t System::nanoTime() {
	return Platform::getTimeNanos();
}

void System::arraycopy(Object$* src, int32_t srcPos, Object$* dest, int32_t destPos, int32_t length) {
	if (src == nullptr || dest == nullptr) {
		$throwNew(NullPointerException);
	}
	Class* srcClass = $toObject0(src)->getClass();
	if (!srcClass->isArray()) {
		$throwNew(IllegalArgumentException);
	}
	Class* destClass = $toObject0(dest)->getClass();
	if (!destClass->isArray()) {
		$throwNew(IllegalArgumentException);
	}

	if (srcClass == ByteArray::class$)	{
		if (srcClass != destClass) {
			$throwNew(IllegalArgumentException);
		}
		ByteArray* srcArray = $fcast<ByteArray>(src);
		ByteArray* destArray = $fcast<ByteArray>(dest);
		destArray->setArray(destPos, srcArray, srcPos, length);
		return;
	}
	if (srcClass == ShortArray::class$) {
		if (srcClass != destClass) {
			$throwNew(IllegalArgumentException);
		}
		ShortArray* srcArray = $fcast<ShortArray>(src);
		ShortArray* destArray = $fcast<ShortArray>(dest);
		destArray->setArray(destPos, srcArray, srcPos, length);
		return;
	}
	if (srcClass == CharArray::class$)	{
		if (srcClass != destClass) {
			$throwNew(IllegalArgumentException);
		}
		CharArray* srcArray = $fcast<CharArray>(src);
		CharArray* destArray = $fcast<CharArray>(dest);
		destArray->setArray(destPos, srcArray, srcPos, length);
		return;
	}
	if (srcClass == IntArray::class$) {
		if (srcClass != destClass) {
			$throwNew(IllegalArgumentException);
		}
		IntArray* srcArray = $fcast<IntArray>(src);
		IntArray* destArray = $fcast<IntArray>(dest);
		destArray->setArray(destPos, srcArray, srcPos, length);
		return;
	}
	if (srcClass == FloatArray::class$) {
		if (srcClass != destClass) {
			$throwNew(IllegalArgumentException);
		}
		FloatArray* srcArray = $fcast<FloatArray>(src);
		FloatArray* destArray = $fcast<FloatArray>(dest);
		destArray->setArray(destPos, srcArray, srcPos, length);
		return;
	}
	if (srcClass == DoubleArray::class$) {
		if (srcClass != destClass) {
			$throwNew(IllegalArgumentException);
		}
		DoubleArray* srcArray = $fcast<DoubleArray>(src);
		DoubleArray* destArray = $fcast<DoubleArray>(dest);
		destArray->setArray(destPos, srcArray, srcPos, length);
		return;
	}
	if (srcClass == LongArray::class$) {
		if (srcClass != destClass) {
			$throwNew(IllegalArgumentException);
		}
		LongArray* srcArray = $fcast<LongArray>(src);
		LongArray* destArray = $fcast<LongArray>(dest);
		destArray->setArray(destPos, srcArray, srcPos, length);
		return;
	}
	if (srcClass == BooleanArray::class$) {
		if (srcClass != destClass) {
			$throwNew(IllegalArgumentException);
		}
		BooleanArray* srcArray = $fcast<BooleanArray>(src);
		BooleanArray* destArray = $fcast<BooleanArray>(dest);
		destArray->setArray(destPos, srcArray, srcPos, length);
		return;
	}
	ObjectArray* srcArray = $fcast<ObjectArray>(src);
	ObjectArray* destArray = $fcast<ObjectArray>(dest);
	destArray->setArray(destPos, srcArray, srcPos, length);
}

int32_t System::identityHashCode(Object$* x) {
	$init(System);
	int32_t $ret = 0;
	$prepareNativeStatic(System, identityHashCode, int32_t, Object$* x);
	$ret = $invokeNativeStatic(x);
	$finishNativeStatic();
	return $ret;
}

$Properties* System::getProperties() {
	$var($SecurityManager, sm, getSecurityManager());
	if (sm != nullptr) {
		sm->checkPropertiesAccess();
	}
	return System::props;
}

$String* System::lineSeparator() {
	return System::lineSeparator$;
}

void System::setProperties($Properties* props$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Properties, props, props$renamed);
	$var($SecurityManager, sm, getSecurityManager());
	if (sm != nullptr) {
		sm->checkPropertiesAccess();
	}
	if (props == nullptr) {
		$var($Map, tempProps, $SystemProps::initProperties());
		$VersionProps::init(tempProps);
		$assign(props, createProperties(tempProps));
	}
	$assignStatic(System::props, props);
}

$String* System::getProperty($String* key) {
	checkKey(key);
	$var($SecurityManager, sm, getSecurityManager());
	if (sm != nullptr) {
		sm->checkPropertyAccess(key);
	}
	return $nc(System::props)->getProperty(key);
}

$String* System::getProperty($String* key, $String* def) {
	checkKey(key);
	$var($SecurityManager, sm, getSecurityManager());
	if (sm != nullptr) {
		sm->checkPropertyAccess(key);
	}
	return $nc(System::props)->getProperty(key, def);
}

$String* System::setProperty($String* key, $String* value) {
	$useLocalCurrentObjectStackCache();
	checkKey(key);
	$var($SecurityManager, sm, getSecurityManager());
	if (sm != nullptr) {
		$init($SecurityConstants);
		sm->checkPermission($$new($PropertyPermission, key, $SecurityConstants::PROPERTY_WRITE_ACTION));
	}
	return $cast($String, $nc(System::props)->setProperty(key, value));
}

$String* System::clearProperty($String* key) {
	$useLocalCurrentObjectStackCache();
	checkKey(key);
	$var($SecurityManager, sm, getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($PropertyPermission, key, "write"_s));
	}
	return $cast($String, $nc(System::props)->remove(key));
}

void System::checkKey($String* key) {
	if (key == nullptr) {
		$throwNew($NullPointerException, "key can\'t be null"_s);
	}
	if ($nc(key)->isEmpty()) {
		$throwNew($IllegalArgumentException, "key can\'t be empty"_s);
	}
}

$String* System::getenv($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, $$str({"getenv."_s, name})));
	}
	return $ProcessEnvironment::getenv(name);
}

$Map* System::getenv() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, "getenv.*"_s));
	}
	return $ProcessEnvironment::getenv();
}

$System$Logger* System::getLogger($String* name) {
	$Objects::requireNonNull(name);
	$Class* caller = $Reflection::getCallerClass();
	if (caller == nullptr) {
		$throwNew($IllegalCallerException, "no caller frame"_s);
	}
	return $LazyLoggers::getLogger(name, $($nc(caller)->getModule()));
}

$System$Logger* System::getLogger($String* name, $ResourceBundle* bundle) {
	$useLocalCurrentObjectStackCache();
	$var($ResourceBundle, rb, $cast($ResourceBundle, $Objects::requireNonNull(bundle)));
	$Objects::requireNonNull(name);
	$Class* caller = $Reflection::getCallerClass();
	if (caller == nullptr) {
		$throwNew($IllegalCallerException, "no caller frame"_s);
	}
	$var($SecurityManager, sm, System::getSecurityManager());
	if (sm != nullptr) {
		$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(System$$Lambda$lambda$getLogger$0$1, name, rb, caller)));
		$init($System$LoggerFinder);
		return $cast($System$Logger, $AccessController::doPrivileged(pa, ($AccessControlContext*)nullptr, $$new($PermissionArray, {static_cast<$Permission*>($System$LoggerFinder::LOGGERFINDER_PERMISSION)})));
	}
	return $nc($($System$LoggerFinder::accessProvider()))->getLocalizedLogger(name, rb, $($nc(caller)->getModule()));
}

void System::exit(int32_t status) {
	$nc($($Runtime::getRuntime()))->exit(status);
}

void System::gc() {
	$nc($($Runtime::getRuntime()))->gc();
}

void System::runFinalization() {
	$nc($($Runtime::getRuntime()))->runFinalization();
}

void System::load($String* filename) {
	$nc($($Runtime::getRuntime()))->load0($Reflection::getCallerClass(), filename);
}

void System::loadLibrary($String* libname) {
	$nc($($Runtime::getRuntime()))->loadLibrary0($Reflection::getCallerClass(), libname);
}

$String* System::mapLibraryName($String* libname) {
	$init(System);
	$var($String, $ret, nullptr);
	$prepareNativeStatic(System, mapLibraryName, $String*, $String* libname);
	$assign($ret, $invokeNativeStaticObject(libname));
	$finishNativeStatic();
	return $ret;
}

$PrintStream* System::newPrintStream($FileOutputStream* fos, $String* enc) {
	$useLocalCurrentObjectStackCache();
	if (enc != nullptr) {
		try {
			return $new($PrintStream, static_cast<$OutputStream*>($$new($BufferedOutputStream, fos, 128)), true, enc);
		} catch ($UnsupportedEncodingException& uee) {
		}
	}
	return $new($PrintStream, static_cast<$OutputStream*>($$new($BufferedOutputStream, fos, 128)), true);
}

void System::logInitException(bool printToStderr, bool printStackTrace, $String* msg, $Throwable* e) {
	$useLocalCurrentObjectStackCache();
	if ($VM::initLevel() < 1) {
		$throwNew($InternalError, "system classes not initialized"_s);
	}
	$var($PrintStream, log, (printToStderr) ? System::err : System::out);
	if (msg != nullptr) {
		$nc(log)->println(msg);
	}
	if (printStackTrace) {
		$nc(e)->printStackTrace(log);
	} else {
		$nc(log)->println($of(e));
		{
			$var($ThrowableArray, arr$, $nc(e)->getSuppressed());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Throwable, suppressed, arr$->get(i$));
				{
					log->println($$str({"Suppressed: "_s, suppressed}));
				}
			}
		}
		$var($Throwable, cause, e->getCause());
		if (cause != nullptr) {
			log->println($$str({"Caused by: "_s, cause}));
		}
	}
}

$Properties* System::createProperties($Map* initialProps) {
	$useLocalCurrentObjectStackCache();
	$var($Properties, properties, $new($Properties, $nc(initialProps)->size()));
	{
		$var($Iterator, i$, $nc($($nc(initialProps)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				$var($String, prop, $cast($String, $nc(entry)->getKey()));
				{
					$var($String, s90167$, prop);
					int32_t tmp90167$ = -1;
					switch ($nc(s90167$)->hashCode()) {
					case (int32_t)0xCA271E53:
						{
							if (s90167$->equals("sun.nio.MaxDirectMemorySize"_s)) {
								tmp90167$ = 0;
							}
							break;
						}
					case 0x04E90D84:
						{
							if (s90167$->equals("sun.nio.PageAlignDirectMemory"_s)) {
								tmp90167$ = 1;
							}
							break;
						}
					case 0x779CC0C8:
						{
							if (s90167$->equals("java.lang.Integer.IntegerCache.high"_s)) {
								tmp90167$ = 2;
							}
							break;
						}
					case (int32_t)0xF7D2310F:
						{
							if (s90167$->equals("sun.java.launcher.diag"_s)) {
								tmp90167$ = 3;
							}
							break;
						}
					case (int32_t)0xA0EE7DAE:
						{
							if (s90167$->equals("jdk.boot.class.path.append"_s)) {
								tmp90167$ = 4;
							}
							break;
						}
					}
					switch (tmp90167$) {
					case 0:
						{}
					case 1:
						{}
					case 2:
						{}
					case 3:
						{}
					case 4:
						{
							break;
						}
					default:
						{
							properties->put(prop, $(entry->getValue()));
						}
					}
				}
			}
		}
	}
	return properties;
}

void System::initPhase1() {
	$useLocalCurrentObjectStackCache();
	setJavaLangAccess();
	$var($Map, tempProps, $SystemProps::initProperties());
	$VersionProps::init(tempProps);
	$VM::saveProperties(tempProps);
	$assignStatic(System::props, createProperties(tempProps));
	$StaticProperty::javaHome();
	$assignStatic(System::lineSeparator$, $nc(System::props)->getProperty("line.separator"_s));
	$init($FileDescriptor);
	$var($FileInputStream, fdIn, $new($FileInputStream, $FileDescriptor::in));
	$var($FileOutputStream, fdOut, $new($FileOutputStream, $FileDescriptor::out));
	$var($FileOutputStream, fdErr, $new($FileOutputStream, $FileDescriptor::err));
	setIn0($$new($BufferedInputStream, fdIn));
	setOut0($(newPrintStream(fdOut, $($nc(System::props)->getProperty("sun.stdout.encoding"_s)))));
	setErr0($(newPrintStream(fdErr, $($nc(System::props)->getProperty("sun.stderr.encoding"_s)))));
	$Terminator::setup();
	$VM::initializeOSEnvironment();
	$var($Thread, current, $Thread::currentThread());
	$nc($(current->getThreadGroup()))->add(current);
	$VM::initLevel(1);
}

int32_t System::initPhase2(bool printToStderr, bool printStackTrace) {
	try {
		$assignStatic(System::bootLayer, $ModuleBootstrap::boot());
	} catch ($Exception& e) {
		logInitException(printToStderr, printStackTrace, "Error occurred during initialization of boot layer"_s, e);
		return -1;
	} catch ($Error& e) {
		logInitException(printToStderr, printStackTrace, "Error occurred during initialization of boot layer"_s, e);
		return -1;
	}
	$VM::initLevel(2);
	return 0;
}

void System::initPhase3() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$load($StringConcatFactory);
	$nc($($Unsafe::getUnsafe()))->ensureClassInitialized($StringConcatFactory::class$);
	$var($String, smProp, System::getProperty("java.security.manager"_s));
	bool needWarning = false;
	if (smProp != nullptr) {
		{
			$var($String, s96088$, smProp);
			int32_t tmp96088$ = -1;
			switch (s96088$->hashCode()) {
			case 0x102AC77B:
				{
					if (s96088$->equals("disallow"_s)) {
						tmp96088$ = 0;
					}
					break;
				}
			case 0x0589A349:
				{
					if (s96088$->equals("allow"_s)) {
						tmp96088$ = 1;
					}
					break;
				}
			case 0:
				{
					if (s96088$->equals(""_s)) {
						tmp96088$ = 2;
					}
					break;
				}
			case 0x5C13D641:
				{
					if (s96088$->equals("default"_s)) {
						tmp96088$ = 3;
					}
					break;
				}
			}
			switch (tmp96088$) {
			case 0:
				{
					System::allowSecurityManager$ = System::NEVER;
					break;
				}
			case 1:
				{
					System::allowSecurityManager$ = System::MAYBE;
					break;
				}
			case 2:
				{}
			case 3:
				{
					implSetSecurityManager($$new($SecurityManager));
					System::allowSecurityManager$ = System::MAYBE;
					needWarning = true;
					break;
				}
			default:
				{
					try {
						$var($ClassLoader, cl, $ClassLoader::getBuiltinAppClassLoader());
						$Class* c = $Class::forName(smProp, false, cl);
						$var($Constructor, ctor, $nc(c)->getConstructor($$new($ClassArray, 0)));
						$load($SecurityManager);
						bool var$1 = !$SecurityManager::class$->isAssignableFrom(c);
						bool var$0 = var$1 || !$Modifier::isPublic(c->getModifiers());
						if (var$0 || !$Modifier::isPublic($nc(ctor)->getModifiers())) {
							$throwNew($Error, $$str({"Could not create SecurityManager: "_s, $($nc(ctor)->toString())}));
						}
						$nc(ctor)->setAccessible(true);
						$var($SecurityManager, sm, $cast($SecurityManager, ctor->newInstance($$new($ObjectArray, 0))));
						implSetSecurityManager(sm);
						needWarning = true;
					} catch ($Exception& e) {
						$throwNew($InternalError, "Could not create SecurityManager"_s, e);
					}
					System::allowSecurityManager$ = System::MAYBE;
				}
			}
		}
	} else {
		System::allowSecurityManager$ = System::MAYBE;
	}
	if (needWarning) {
		$nc(System::err)->println("WARNING: A command line option has enabled the Security Manager\nWARNING: The Security Manager is deprecated and will be removed in a future release"_s);
	}
	$assignStatic(System::initialErrStream, System::err);
	$VM::initLevel(3);
	$var($ClassLoader, scl, $ClassLoader::initSystemClassLoader());
	$($Thread::currentThread())->setContextClassLoader(scl);
	$VM::initLevel(4);
}

void System::setJavaLangAccess() {
	$SharedSecrets::setJavaLangAccess($$new($System$2));
}

$System$Logger* System::lambda$getLogger$0($String* name, $ResourceBundle* rb, $Class* caller) {
	$useLocalCurrentObjectStackCache();
	return $nc($($System$LoggerFinder::accessProvider()))->getLocalizedLogger(name, rb, $($nc(caller)->getModule()));
}

void clinit$System($Class* class$) {
	{
		System::registerNatives();
	}
	$assignStatic(System::in, nullptr);
	$assignStatic(System::out, nullptr);
	$assignStatic(System::err, nullptr);
}

System::System() {
}

void System::addLibrary(Library* lib) {
	Machine::addLibrary(lib);
}

void System::init() {
	if (!Machine::isInited()) {
		Machine::init1();
		initPhase1();
		Machine::init2();
		initPhase2(true, true);
		initPhase3();
		Machine::init3();
	}
}

void System::deinit() {
	Machine::deinit();
}

int System::launch(int argc, char** argv, int jargc, char** jargv, const char* javaArgPrefix, $LaunchDoInitFunction doInit, $LaunchDoMainFunction doMain) {
	return Machine::launch(argc, argv, jargc, jargv, javaArgPrefix, doInit, doMain);
}

int System::launch(int argc, char** argv, const char* javaArgPrefix, $LaunchDoInitFunction doInit, $LaunchDoMainFunction doMain) {
	return Machine::launch(argc, argv, 0, nullptr, javaArgPrefix, doInit, doMain);
}

int System::launch(int argc, char** argv, $LaunchDoInitFunction doInit, $LaunchDoMainFunction doMain) {
	return Machine::launch(argc, argv, 0, nullptr, "-$", doInit, doMain);
}

#ifdef _WIN32
int System::launchw(int jargc, char** jargv, const char* javaArgPrefix, $LaunchDoInitFunction doInit, $LaunchDoMainFunction doMain) {
	return Machine::launchw(jargc, jargv, javaArgPrefix, doInit, doMain);
}

int System::launchw(const char* javaArgPrefix, $LaunchDoInitFunction doInit, $LaunchDoMainFunction doMain) {
	return Machine::launchw(0, nullptr, javaArgPrefix, doInit, doMain);
}

int System::launchw($LaunchDoInitFunction doInit, $LaunchDoMainFunction doMain) {
	return Machine::launchw(0, nullptr, "-$", doInit, doMain);
}
#endif

void System::run(String* mainClass, $StringArray* args) {
	Machine::run(mainClass, args);
}

String* System::getSystemClassPath() {
	return Machine::getSystemClassPath();
}

void* System::loadNativeMethod(Class* clazz, MethodInfo* methodInfo) {
	return Machine::loadNativeMethod(clazz, methodInfo);
}

$Class* System::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(System$$Lambda$getProtectionDomain::classInfo$.name)) {
			return System$$Lambda$getProtectionDomain::load$(name, initialize);
		}
		if (name->equals(System$$Lambda$lambda$getLogger$0$1::classInfo$.name)) {
			return System$$Lambda$lambda$getLogger$0$1::load$(name, initialize);
		}
	}
	$loadClass(System, name, initialize, &_System_ClassInfo_, clinit$System, allocate$System);
	return class$;
}

$Class* System::class$ = nullptr;

	} // lang
} // java