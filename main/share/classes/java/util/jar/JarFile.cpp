#include <java/util/jar/JarFile.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/EOFException.h>
#include <java/io/File.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Math.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/OutOfMemoryError.h>
#include <java/lang/Runtime$Version.h>
#include <java/lang/Runtime.h>
#include <java/lang/ThreadLocal.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/ref/SoftReference.h>
#include <java/net/URL.h>
#include <java/security/CodeSigner.h>
#include <java/security/CodeSource.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/jar/Attributes$Name.h>
#include <java/util/jar/Attributes.h>
#include <java/util/jar/JarEntry.h>
#include <java/util/jar/JarException.h>
#include <java/util/jar/JarFile$1.h>
#include <java/util/jar/JarFile$2.h>
#include <java/util/jar/JarFile$JarFileEntry.h>
#include <java/util/jar/JarVerifier$VerifierStream.h>
#include <java/util/jar/JarVerifier.h>
#include <java/util/jar/JavaUtilJarAccessImpl.h>
#include <java/util/jar/Manifest$FastInputStream.h>
#include <java/util/jar/Manifest.h>
#include <java/util/stream/Stream.h>
#include <java/util/zip/ZipEntry.h>
#include <java/util/zip/ZipFile.h>
#include <jdk/internal/access/JavaUtilJarAccess.h>
#include <jdk/internal/access/JavaUtilZipFileAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/ManifestEntryVerifier.h>
#include <jcpp.h>

#undef BASE_VERSION
#undef BASE_VERSION_FEATURE
#undef CLASSPATH_CHARS
#undef CLASSPATH_LASTOCC
#undef CLASSPATH_OPTOSFT
#undef FALSE
#undef JUZFA
#undef MANIFEST_NAME
#undef MAX_ARRAY_SIZE
#undef META_INF
#undef META_INF_VERSIONS
#undef MULTIRELEASE_CHARS
#undef MULTIRELEASE_LASTOCC
#undef MULTIRELEASE_OPTOSFT
#undef MULTI_RELEASE
#undef MULTI_RELEASE_ENABLED
#undef MULTI_RELEASE_FORCED
#undef OPEN_READ
#undef RUNTIME_VERSION
#undef TRUE

using $CodeSourceArray = $Array<::java::security::CodeSource>;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $EOFException = ::java::io::EOFException;
using $File = ::java::io::File;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $OutOfMemoryError = ::java::lang::OutOfMemoryError;
using $Runtime = ::java::lang::Runtime;
using $Runtime$Version = ::java::lang::Runtime$Version;
using $RuntimeException = ::java::lang::RuntimeException;
using $ThreadLocal = ::java::lang::ThreadLocal;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $SoftReference = ::java::lang::ref::SoftReference;
using $URL = ::java::net::URL;
using $CodeSource = ::java::security::CodeSource;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $Attributes = ::java::util::jar::Attributes;
using $Attributes$Name = ::java::util::jar::Attributes$Name;
using $JarEntry = ::java::util::jar::JarEntry;
using $JarException = ::java::util::jar::JarException;
using $JarFile$1 = ::java::util::jar::JarFile$1;
using $JarFile$2 = ::java::util::jar::JarFile$2;
using $JarFile$JarFileEntry = ::java::util::jar::JarFile$JarFileEntry;
using $JarVerifier = ::java::util::jar::JarVerifier;
using $JarVerifier$VerifierStream = ::java::util::jar::JarVerifier$VerifierStream;
using $JavaUtilJarAccessImpl = ::java::util::jar::JavaUtilJarAccessImpl;
using $Manifest = ::java::util::jar::Manifest;
using $Manifest$FastInputStream = ::java::util::jar::Manifest$FastInputStream;
using $Stream = ::java::util::stream::Stream;
using $ZipEntry = ::java::util::zip::ZipEntry;
using $ZipFile = ::java::util::zip::ZipFile;
using $JavaUtilJarAccess = ::jdk::internal::access::JavaUtilJarAccess;
using $JavaUtilZipFileAccess = ::jdk::internal::access::JavaUtilZipFileAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $Debug = ::sun::security::util::Debug;
using $ManifestEntryVerifier = ::sun::security::util::ManifestEntryVerifier;

namespace java {
	namespace util {
		namespace jar {

class JarFile$$Lambda$getBasename : public $Function {
	$class(JarFile$$Lambda$getBasename, $NO_CLASS_INIT, $Function)
public:
	void init$(JarFile* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* name) override {
		 return $of($nc(inst$)->getBasename($cast($String, name)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<JarFile$$Lambda$getBasename>());
	}
	JarFile* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo JarFile$$Lambda$getBasename::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(JarFile$$Lambda$getBasename, inst$)},
	{}
};
$MethodInfo JarFile$$Lambda$getBasename::methodInfos[3] = {
	{"<init>", "(Ljava/util/jar/JarFile;)V", nullptr, $PUBLIC, $method(JarFile$$Lambda$getBasename, init$, void, JarFile*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(JarFile$$Lambda$getBasename, apply, $Object*, Object$*)},
	{}
};
$ClassInfo JarFile$$Lambda$getBasename::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.jar.JarFile$$Lambda$getBasename",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* JarFile$$Lambda$getBasename::load$($String* name, bool initialize) {
	$loadClass(JarFile$$Lambda$getBasename, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* JarFile$$Lambda$getBasename::class$ = nullptr;

class JarFile$$Lambda$nonNull$1 : public $Predicate {
	$class(JarFile$$Lambda$nonNull$1, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* obj) override {
		 return $Objects::nonNull(obj);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<JarFile$$Lambda$nonNull$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo JarFile$$Lambda$nonNull$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(JarFile$$Lambda$nonNull$1, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(JarFile$$Lambda$nonNull$1, test, bool, Object$*)},
	{}
};
$ClassInfo JarFile$$Lambda$nonNull$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.jar.JarFile$$Lambda$nonNull$1",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* JarFile$$Lambda$nonNull$1::load$($String* name, bool initialize) {
	$loadClass(JarFile$$Lambda$nonNull$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* JarFile$$Lambda$nonNull$1::class$ = nullptr;

class JarFile$$Lambda$getJarEntry$2 : public $Function {
	$class(JarFile$$Lambda$getJarEntry$2, $NO_CLASS_INIT, $Function)
public:
	void init$(JarFile* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* name) override {
		 return $of($nc(inst$)->getJarEntry($cast($String, name)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<JarFile$$Lambda$getJarEntry$2>());
	}
	JarFile* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo JarFile$$Lambda$getJarEntry$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(JarFile$$Lambda$getJarEntry$2, inst$)},
	{}
};
$MethodInfo JarFile$$Lambda$getJarEntry$2::methodInfos[3] = {
	{"<init>", "(Ljava/util/jar/JarFile;)V", nullptr, $PUBLIC, $method(JarFile$$Lambda$getJarEntry$2, init$, void, JarFile*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(JarFile$$Lambda$getJarEntry$2, apply, $Object*, Object$*)},
	{}
};
$ClassInfo JarFile$$Lambda$getJarEntry$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.jar.JarFile$$Lambda$getJarEntry$2",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* JarFile$$Lambda$getJarEntry$2::load$($String* name, bool initialize) {
	$loadClass(JarFile$$Lambda$getJarEntry$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* JarFile$$Lambda$getJarEntry$2::class$ = nullptr;

$FieldInfo _JarFile_FieldInfo_[] = {
	{"BASE_VERSION", "Ljava/lang/Runtime$Version;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JarFile, BASE_VERSION)},
	{"BASE_VERSION_FEATURE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JarFile, BASE_VERSION_FEATURE)},
	{"RUNTIME_VERSION", "Ljava/lang/Runtime$Version;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JarFile, RUNTIME_VERSION)},
	{"MULTI_RELEASE_ENABLED", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JarFile, MULTI_RELEASE_ENABLED)},
	{"MULTI_RELEASE_FORCED", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JarFile, MULTI_RELEASE_FORCED)},
	{"isInitializing", "Ljava/lang/ThreadLocal;", "Ljava/lang/ThreadLocal<Ljava/lang/Boolean;>;", $PRIVATE | $STATIC | $FINAL, $staticField(JarFile, isInitializing$)},
	{"MAX_ARRAY_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(JarFile, MAX_ARRAY_SIZE)},
	{"manRef", "Ljava/lang/ref/SoftReference;", "Ljava/lang/ref/SoftReference<Ljava/util/jar/Manifest;>;", $PRIVATE, $field(JarFile, manRef)},
	{"manEntry", "Ljava/util/jar/JarEntry;", nullptr, $PRIVATE, $field(JarFile, manEntry)},
	{"jv", "Ljava/util/jar/JarVerifier;", nullptr, $PRIVATE, $field(JarFile, jv)},
	{"jvInitialized", "Z", nullptr, $PRIVATE, $field(JarFile, jvInitialized)},
	{"verify", "Z", nullptr, $PRIVATE, $field(JarFile, verify)},
	{"version", "Ljava/lang/Runtime$Version;", nullptr, $PRIVATE | $FINAL, $field(JarFile, version)},
	{"versionFeature", "I", nullptr, $PRIVATE | $FINAL, $field(JarFile, versionFeature)},
	{"isMultiRelease", "Z", nullptr, $PRIVATE, $field(JarFile, isMultiRelease$)},
	{"hasClassPathAttribute", "Z", nullptr, $PRIVATE, $field(JarFile, hasClassPathAttribute$)},
	{"hasCheckedSpecialAttributes", "Z", nullptr, $PRIVATE | $VOLATILE, $field(JarFile, hasCheckedSpecialAttributes)},
	{"JUZFA", "Ljdk/internal/access/JavaUtilZipFileAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JarFile, JUZFA)},
	{"META_INF", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JarFile, META_INF)},
	{"META_INF_VERSIONS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JarFile, META_INF_VERSIONS)},
	{"MANIFEST_NAME", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(JarFile, MANIFEST_NAME)},
	{"CLASSPATH_CHARS", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JarFile, CLASSPATH_CHARS)},
	{"CLASSPATH_LASTOCC", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JarFile, CLASSPATH_LASTOCC)},
	{"CLASSPATH_OPTOSFT", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JarFile, CLASSPATH_OPTOSFT)},
	{"MULTIRELEASE_CHARS", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JarFile, MULTIRELEASE_CHARS)},
	{"MULTIRELEASE_LASTOCC", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JarFile, MULTIRELEASE_LASTOCC)},
	{"MULTIRELEASE_OPTOSFT", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JarFile, MULTIRELEASE_OPTOSFT)},
	{}
};

$MethodInfo _JarFile_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(JarFile, init$, void, $String*), "java.io.IOException"},
	{"<init>", "(Ljava/lang/String;Z)V", nullptr, $PUBLIC, $method(JarFile, init$, void, $String*, bool), "java.io.IOException"},
	{"<init>", "(Ljava/io/File;)V", nullptr, $PUBLIC, $method(JarFile, init$, void, $File*), "java.io.IOException"},
	{"<init>", "(Ljava/io/File;Z)V", nullptr, $PUBLIC, $method(JarFile, init$, void, $File*, bool), "java.io.IOException"},
	{"<init>", "(Ljava/io/File;ZI)V", nullptr, $PUBLIC, $method(JarFile, init$, void, $File*, bool, int32_t), "java.io.IOException"},
	{"<init>", "(Ljava/io/File;ZILjava/lang/Runtime$Version;)V", nullptr, $PUBLIC, $method(JarFile, init$, void, $File*, bool, int32_t, $Runtime$Version*), "java.io.IOException"},
	{"baseVersion", "()Ljava/lang/Runtime$Version;", nullptr, $PUBLIC | $STATIC, $staticMethod(JarFile, baseVersion, $Runtime$Version*)},
	{"checkForSpecialAttributes", "()V", nullptr, $PRIVATE, $method(JarFile, checkForSpecialAttributes, void), "java.io.IOException"},
	{"ensureInitialization", "()V", nullptr, $SYNCHRONIZED, $virtualMethod(JarFile, ensureInitialization, void)},
	{"entries", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/util/jar/JarEntry;>;", $PUBLIC, $virtualMethod(JarFile, entries, $Enumeration*)},
	{"entries2", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/util/jar/JarEntry;>;", 0, $virtualMethod(JarFile, entries2, $Enumeration*)},
	{"entryFor", "(Ljava/lang/String;)Ljava/util/jar/JarEntry;", nullptr, 0, $virtualMethod(JarFile, entryFor, $JarEntry*, $String*)},
	{"entryNames", "([Ljava/security/CodeSource;)Ljava/util/Enumeration;", "([Ljava/security/CodeSource;)Ljava/util/Enumeration<Ljava/lang/String;>;", 0, $virtualMethod(JarFile, entryNames, $Enumeration*, $CodeSourceArray*)},
	{"getBasename", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(JarFile, getBasename, $String*, $String*)},
	{"getBytes", "(Ljava/util/zip/ZipEntry;)[B", nullptr, $PRIVATE, $method(JarFile, getBytes, $bytes*, $ZipEntry*), "java.io.IOException"},
	{"getCodeSource", "(Ljava/net/URL;Ljava/lang/String;)Ljava/security/CodeSource;", nullptr, 0, $virtualMethod(JarFile, getCodeSource, $CodeSource*, $URL*, $String*)},
	{"getCodeSources", "(Ljava/net/URL;)[Ljava/security/CodeSource;", nullptr, 0, $virtualMethod(JarFile, getCodeSources, $CodeSourceArray*, $URL*)},
	{"getEntry", "(Ljava/lang/String;)Ljava/util/zip/ZipEntry;", nullptr, $PUBLIC, $virtualMethod(JarFile, getEntry, $ZipEntry*, $String*)},
	{"getInputStream", "(Ljava/util/zip/ZipEntry;)Ljava/io/InputStream;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(JarFile, getInputStream, $InputStream*, $ZipEntry*), "java.io.IOException"},
	{"getJarEntry", "(Ljava/lang/String;)Ljava/util/jar/JarEntry;", nullptr, $PUBLIC, $virtualMethod(JarFile, getJarEntry, $JarEntry*, $String*)},
	{"getManEntry", "()Ljava/util/jar/JarEntry;", nullptr, $PRIVATE, $method(JarFile, getManEntry, $JarEntry*)},
	{"getManifest", "()Ljava/util/jar/Manifest;", nullptr, $PUBLIC, $virtualMethod(JarFile, getManifest, $Manifest*), "java.io.IOException"},
	{"getManifestDigests", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/Object;>;", 0, $virtualMethod(JarFile, getManifestDigests, $List*)},
	{"getManifestFromReference", "()Ljava/util/jar/Manifest;", nullptr, $PRIVATE, $method(JarFile, getManifestFromReference, $Manifest*), "java.io.IOException"},
	{"getRealName", "(Ljava/util/jar/JarEntry;)Ljava/lang/String;", nullptr, 0, $virtualMethod(JarFile, getRealName, $String*, $JarEntry*)},
	{"getVersion", "()Ljava/lang/Runtime$Version;", nullptr, $PUBLIC | $FINAL, $method(JarFile, getVersion, $Runtime$Version*)},
	{"getVersionedEntry", "(Ljava/lang/String;Ljava/util/jar/JarEntry;)Ljava/util/jar/JarEntry;", nullptr, $PRIVATE, $method(JarFile, getVersionedEntry, $JarEntry*, $String*, $JarEntry*)},
	{"hasClassPathAttribute", "()Z", nullptr, 0, $virtualMethod(JarFile, hasClassPathAttribute, bool), "java.io.IOException"},
	{"initializeVerifier", "()V", nullptr, $PRIVATE, $method(JarFile, initializeVerifier, void)},
	{"isInitializing", "()Z", nullptr, $STATIC, $staticMethod(JarFile, isInitializing, bool)},
	{"isMultiRelease", "()Z", nullptr, $PUBLIC | $FINAL, $method(JarFile, isMultiRelease, bool)},
	{"match", "([B[B[B[B)I", nullptr, $PRIVATE, $method(JarFile, match, int32_t, $bytes*, $bytes*, $bytes*, $bytes*)},
	{"maybeInstantiateVerifier", "()V", nullptr, $PRIVATE, $method(JarFile, maybeInstantiateVerifier, void), "java.io.IOException"},
	{"newEntry", "(Ljava/util/jar/JarEntry;)Ljava/util/jar/JarEntry;", nullptr, 0, $virtualMethod(JarFile, newEntry, $JarEntry*, $JarEntry*)},
	{"newEntry", "(Ljava/lang/String;)Ljava/util/jar/JarEntry;", nullptr, 0, $virtualMethod(JarFile, newEntry, $JarEntry*, $String*)},
	{"runtimeVersion", "()Ljava/lang/Runtime$Version;", nullptr, $PUBLIC | $STATIC, $staticMethod(JarFile, runtimeVersion, $Runtime$Version*)},
	{"setEagerValidation", "(Z)V", nullptr, 0, $virtualMethod(JarFile, setEagerValidation, void, bool)},
	{"stream", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljava/util/jar/JarEntry;>;", $PUBLIC, $virtualMethod(JarFile, stream, $Stream*)},
	{"unsignedEntryNames", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/String;>;", $PRIVATE, $method(JarFile, unsignedEntryNames, $Enumeration*)},
	{"verifiableEntry", "(Ljava/util/zip/ZipEntry;)Ljava/util/jar/JarEntry;", nullptr, $PRIVATE, $method(JarFile, verifiableEntry, $JarEntry*, $ZipEntry*)},
	{"versionedStream", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljava/util/jar/JarEntry;>;", $PUBLIC, $virtualMethod(JarFile, versionedStream, $Stream*)},
	{}
};

$InnerClassInfo _JarFile_InnerClassesInfo_[] = {
	{"java.util.jar.JarFile$JarFileEntry", "java.util.jar.JarFile", "JarFileEntry", $PRIVATE},
	{"java.util.jar.JarFile$2", nullptr, nullptr, 0},
	{"java.util.jar.JarFile$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _JarFile_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.jar.JarFile",
	"java.util.zip.ZipFile",
	nullptr,
	_JarFile_FieldInfo_,
	_JarFile_MethodInfo_,
	nullptr,
	nullptr,
	_JarFile_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.jar.JarFile$JarFileEntry,java.util.jar.JarFile$2,java.util.jar.JarFile$1"
};

$Object* allocate$JarFile($Class* clazz) {
	return $of($alloc(JarFile));
}

$Runtime$Version* JarFile::BASE_VERSION = nullptr;
int32_t JarFile::BASE_VERSION_FEATURE = 0;
$Runtime$Version* JarFile::RUNTIME_VERSION = nullptr;
bool JarFile::MULTI_RELEASE_ENABLED = false;
bool JarFile::MULTI_RELEASE_FORCED = false;
$ThreadLocal* JarFile::isInitializing$ = nullptr;
$JavaUtilZipFileAccess* JarFile::JUZFA = nullptr;
$String* JarFile::META_INF = nullptr;
$String* JarFile::META_INF_VERSIONS = nullptr;
$String* JarFile::MANIFEST_NAME = nullptr;
$bytes* JarFile::CLASSPATH_CHARS = nullptr;
$bytes* JarFile::CLASSPATH_LASTOCC = nullptr;
$bytes* JarFile::CLASSPATH_OPTOSFT = nullptr;
$bytes* JarFile::MULTIRELEASE_CHARS = nullptr;
$bytes* JarFile::MULTIRELEASE_LASTOCC = nullptr;
$bytes* JarFile::MULTIRELEASE_OPTOSFT = nullptr;

$Runtime$Version* JarFile::baseVersion() {
	$init(JarFile);
	return JarFile::BASE_VERSION;
}

$Runtime$Version* JarFile::runtimeVersion() {
	$init(JarFile);
	return JarFile::RUNTIME_VERSION;
}

void JarFile::init$($String* name) {
	JarFile::init$($$new($File, name), true, $ZipFile::OPEN_READ);
}

void JarFile::init$($String* name, bool verify) {
	JarFile::init$($$new($File, name), verify, $ZipFile::OPEN_READ);
}

void JarFile::init$($File* file) {
	JarFile::init$(file, true, $ZipFile::OPEN_READ);
}

void JarFile::init$($File* file, bool verify) {
	JarFile::init$(file, verify, $ZipFile::OPEN_READ);
}

void JarFile::init$($File* file, bool verify, int32_t mode) {
	JarFile::init$(file, verify, mode, JarFile::BASE_VERSION);
}

void JarFile::init$($File* file, bool verify, int32_t mode, $Runtime$Version* version) {
	$ZipFile::init$(file, mode);
	this->verify = verify;
	$Objects::requireNonNull(version);
	bool var$0 = JarFile::MULTI_RELEASE_FORCED;
	if (!var$0) {
		int32_t var$1 = version->feature();
		var$0 = var$1 == $nc(JarFile::RUNTIME_VERSION)->feature();
	}
	if (var$0) {
		$set(this, version, JarFile::RUNTIME_VERSION);
	} else if (version->feature() <= JarFile::BASE_VERSION_FEATURE) {
		$set(this, version, JarFile::BASE_VERSION);
	} else {
		$set(this, version, $Runtime$Version::parse($($Integer::toString(version->feature()))));
	}
	this->versionFeature = $nc(this->version)->feature();
}

$Runtime$Version* JarFile::getVersion() {
	return isMultiRelease() ? this->version : JarFile::BASE_VERSION;
}

bool JarFile::isMultiRelease() {
	if (this->isMultiRelease$) {
		return true;
	}
	if (JarFile::MULTI_RELEASE_ENABLED) {
		try {
			checkForSpecialAttributes();
		} catch ($IOException& io) {
			this->isMultiRelease$ = false;
		}
	}
	return this->isMultiRelease$;
}

$Manifest* JarFile::getManifest() {
	return getManifestFromReference();
}

$Manifest* JarFile::getManifestFromReference() {
	$useLocalCurrentObjectStackCache();
	$var($Manifest, man, this->manRef != nullptr ? $cast($Manifest, $nc(this->manRef)->get()) : ($Manifest*)nullptr);
	if (man == nullptr) {
		$var($JarEntry, manEntry, getManEntry());
		if (manEntry != nullptr) {
			if (this->verify) {
				$var($bytes, b, getBytes(manEntry));
				if (!this->jvInitialized) {
					if ($nc(JarFile::JUZFA)->getManifestNum(this) == 1) {
						$set(this, jv, $new($JarVerifier, $(manEntry->getName()), b));
					} else {
						$init($JarVerifier);
						if ($JarVerifier::debug != nullptr) {
							$nc($JarVerifier::debug)->println("Multiple MANIFEST.MF found. Treat JAR file as unsigned"_s);
						}
					}
				}
				$var($JarVerifier, var$0, this->jv);
				$var($InputStream, var$1, static_cast<$InputStream*>($new($ByteArrayInputStream, b)));
				$assign(man, $new($Manifest, var$0, var$1, $(getName())));
			} else {
				{
					$var($InputStream, is, $ZipFile::getInputStream(manEntry));
					{
						$var($Throwable, var$2, nullptr);
						try {
							try {
								$assign(man, $new($Manifest, is, $(getName())));
							} catch ($Throwable& t$) {
								if (is != nullptr) {
									try {
										is->close();
									} catch ($Throwable& x2) {
										t$->addSuppressed(x2);
									}
								}
								$throw(t$);
							}
						} catch ($Throwable& var$3) {
							$assign(var$2, var$3);
						} /*finally*/ {
							if (is != nullptr) {
								is->close();
							}
						}
						if (var$2 != nullptr) {
							$throw(var$2);
						}
					}
				}
			}
			$set(this, manRef, $new($SoftReference, man));
		}
	}
	return man;
}

$JarEntry* JarFile::getJarEntry($String* name) {
	return $cast($JarEntry, getEntry(name));
}

$ZipEntry* JarFile::getEntry($String* name) {
	if (isMultiRelease()) {
		$var($JarEntry, je, getVersionedEntry(name, nullptr));
		if (je == nullptr) {
			$assign(je, $cast($JarEntry, $ZipFile::getEntry(name)));
		}
		return je;
	} else {
		return $ZipFile::getEntry(name);
	}
}

$Enumeration* JarFile::entries() {
	return $nc(JarFile::JUZFA)->entries(this);
}

$Stream* JarFile::stream() {
	return $nc(JarFile::JUZFA)->stream(this);
}

$Stream* JarFile::versionedStream() {
	$useLocalCurrentObjectStackCache();
	if (isMultiRelease()) {
		return $nc($($nc($($nc($($nc($($nc($($nc(JarFile::JUZFA)->entryNameStream(this)))->map(static_cast<$Function*>($$new(JarFile$$Lambda$getBasename, this)))))->filter(static_cast<$Predicate*>($$new(JarFile$$Lambda$nonNull$1)))))->distinct()))->map(static_cast<$Function*>($$new(JarFile$$Lambda$getJarEntry$2, this)))))->filter(static_cast<$Predicate*>($$new(JarFile$$Lambda$nonNull$1)));
	}
	return stream();
}

$JarEntry* JarFile::entryFor($String* name) {
	return $new($JarFile$JarFileEntry, this, name);
}

$String* JarFile::getBasename($String* name) {
	if ($nc(name)->startsWith(JarFile::META_INF_VERSIONS)) {
		int32_t off = $nc(JarFile::META_INF_VERSIONS)->length();
		int32_t index = name->indexOf((int32_t)u'/', off);
		try {
			bool var$0 = index == -1 || index == (name->length() - 1);
			if (var$0 || $Integer::parseInt(name, off, index, 10) > this->versionFeature) {
				return nullptr;
			}
		} catch ($NumberFormatException& x) {
			return nullptr;
		}
		return name->substring(index + 1);
	}
	return name;
}

$JarEntry* JarFile::getVersionedEntry($String* name, $JarEntry* defaultEntry) {
	$useLocalCurrentObjectStackCache();
	if (!$nc(name)->startsWith(JarFile::META_INF)) {
		$var($ints, versions, $nc(JarFile::JUZFA)->getMetaInfVersions(this));
		if (JarFile::BASE_VERSION_FEATURE < this->versionFeature && $nc(versions)->length > 0) {
			for (int32_t i = versions->length - 1; i >= 0; --i) {
				int32_t version = versions->get(i);
				if (version > this->versionFeature) {
					continue;
				}
				if (version < JarFile::BASE_VERSION_FEATURE) {
					break;
				}
				$var($JarFile$JarFileEntry, vje, $cast($JarFile$JarFileEntry, $ZipFile::getEntry($$str({JarFile::META_INF_VERSIONS, $$str(version), "/"_s, name}))));
				if (vje != nullptr) {
					return vje->withBasename(name);
				}
			}
		}
	}
	return defaultEntry;
}

$String* JarFile::getRealName($JarEntry* entry) {
	return $nc(entry)->getRealName();
}

void JarFile::maybeInstantiateVerifier() {
	if (this->jv != nullptr) {
		return;
	}
	if (this->verify) {
		$var($String, name, $nc(JarFile::JUZFA)->getManifestName(this, true));
		if (name != nullptr) {
			getManifest();
			return;
		}
		this->verify = false;
	}
}

void JarFile::initializeVerifier() {
	$useLocalCurrentObjectStackCache();
	$var($ManifestEntryVerifier, mev, nullptr);
	try {
		$var($List, names, $nc(JarFile::JUZFA)->getManifestAndSignatureRelatedFiles(this));
		{
			$var($Iterator, i$, $nc(names)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, name, $cast($String, i$->next()));
				{
					$var($JarEntry, e, getJarEntry(name));
					$var($bytes, b, nullptr);
					if (e == nullptr) {
						$throwNew($JarException, "corrupted jar file"_s);
					}
					if (mev == nullptr) {
						$assign(mev, $new($ManifestEntryVerifier, $(getManifestFromReference())));
					}
					if ($nc(name)->equalsIgnoreCase(JarFile::MANIFEST_NAME)) {
						$assign(b, $nc(this->jv)->manifestRawBytes);
					} else {
						$assign(b, getBytes(e));
					}
					if (b != nullptr && b->length > 0) {
						$nc(this->jv)->beginEntry(e, mev);
						$nc(this->jv)->update(b->length, b, 0, b->length, mev);
						$nc(this->jv)->update(-1, nullptr, 0, 0, mev);
					}
				}
			}
		}
	} catch ($IOException& ex) {
		$set(this, jv, nullptr);
		this->verify = false;
		$init($JarVerifier);
		if ($JarVerifier::debug != nullptr) {
			$nc($JarVerifier::debug)->println("jarfile parsing error!"_s);
			ex->printStackTrace();
		}
	} catch ($IllegalArgumentException& ex) {
		$set(this, jv, nullptr);
		this->verify = false;
		$init($JarVerifier);
		if ($JarVerifier::debug != nullptr) {
			$nc($JarVerifier::debug)->println("jarfile parsing error!"_s);
			ex->printStackTrace();
		}
	}
	if (this->jv != nullptr) {
		$nc(this->jv)->doneWithMeta();
		if ($JarVerifier::debug != nullptr) {
			$nc($JarVerifier::debug)->println("done with meta!"_s);
		}
		if ($nc(this->jv)->nothingToVerify()) {
			if ($JarVerifier::debug != nullptr) {
				$nc($JarVerifier::debug)->println("nothing to verify!"_s);
			}
			$set(this, jv, nullptr);
			this->verify = false;
		}
	}
}

$bytes* JarFile::getBytes($ZipEntry* ze) {
	$useLocalCurrentObjectStackCache();
	{
		$var($InputStream, is, $ZipFile::getInputStream(ze));
		{
			$var($Throwable, var$0, nullptr);
			$var($bytes, var$2, nullptr);
			bool return$1 = false;
			try {
				try {
					int64_t uncompressedSize = $nc(ze)->getSize();
					if (uncompressedSize > JarFile::MAX_ARRAY_SIZE) {
						$throwNew($OutOfMemoryError, "Required array size too large"_s);
					}
					int32_t len = (int32_t)uncompressedSize;
					int32_t bytesRead = 0;
					$var($bytes, b, nullptr);
					if (len != -1 && len <= 0x0000FFFF) {
						$assign(b, $new($bytes, len));
						bytesRead = $nc(is)->readNBytes(b, 0, len);
					} else {
						$assign(b, $nc(is)->readAllBytes());
						bytesRead = $nc(b)->length;
					}
					if (len != -1 && len != bytesRead) {
						$throwNew($EOFException, $$str({"Expected:"_s, $$str(len), ", read:"_s, $$str(bytesRead)}));
					}
					$assign(var$2, b);
					return$1 = true;
					goto $finally;
				} catch ($Throwable& t$) {
					if (is != nullptr) {
						try {
							is->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				if (is != nullptr) {
					is->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	}
	$shouldNotReachHere();
}

$InputStream* JarFile::getInputStream($ZipEntry* ze) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		maybeInstantiateVerifier();
		if (this->jv == nullptr) {
			return $ZipFile::getInputStream(ze);
		}
		if (!this->jvInitialized) {
			initializeVerifier();
			this->jvInitialized = true;
			if (this->jv == nullptr) {
				return $ZipFile::getInputStream(ze);
			}
		}
		$var($Manifest, var$0, getManifestFromReference());
		$var($JarEntry, var$1, verifiableEntry(ze));
		return $new($JarVerifier$VerifierStream, var$0, var$1, $($ZipFile::getInputStream(ze)), this->jv);
	}
}

$JarEntry* JarFile::verifiableEntry($ZipEntry* ze$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($ZipEntry, ze, ze$renamed);
	if ($instanceOf($JarFile$JarFileEntry, ze)) {
		return $nc(($cast($JarFile$JarFileEntry, ze)))->realEntry();
	}
	$assign(ze, getJarEntry($($nc(ze)->getName())));
	if ($instanceOf($JarFile$JarFileEntry, ze)) {
		return $nc(($cast($JarFile$JarFileEntry, ze)))->realEntry();
	}
	return $cast($JarEntry, ze);
}

$JarEntry* JarFile::getManEntry() {
	if (this->manEntry == nullptr) {
		$var($String, name, $nc(JarFile::JUZFA)->getManifestName(this, false));
		if (name != nullptr) {
			$set(this, manEntry, $cast($JarEntry, $ZipFile::getEntry(name)));
		}
	}
	return this->manEntry;
}

bool JarFile::hasClassPathAttribute() {
	checkForSpecialAttributes();
	return this->hasClassPathAttribute$;
}

int32_t JarFile::match($bytes* src, $bytes* b, $bytes* lastOcc, $bytes* optoSft) {
	int32_t len = $nc(src)->length;
	int32_t last = $nc(b)->length - len;
	int32_t i = 0;
	bool next$continue = false;
	while (i <= last) {
		for (int32_t j = (len - 1); j >= 0; --j) {
			int8_t c = b->get(i + j);
			if (c >= u' ' && c <= u'z') {
				if (c >= u'a') {
					c -= 32;
				}
				if (c != src->get(j)) {
					int32_t badShift = $nc(lastOcc)->get(c - 32);
					i += $Math::max(j + 1 - badShift, (int32_t)$nc(optoSft)->get(j));
					next$continue = true;
					break;
				}
			} else {
				i += len;
				next$continue = true;
				break;
			}
		}
		if (next$continue) {
			next$continue = false;
			continue;
		}
		return i;
	}
	return -1;
}

void JarFile::checkForSpecialAttributes() {
	$useLocalCurrentObjectStackCache();
	if (this->hasCheckedSpecialAttributes) {
		return;
	}
	$synchronized(this) {
		if (this->hasCheckedSpecialAttributes) {
			return;
		}
		$var($JarEntry, manEntry, getManEntry());
		if (manEntry != nullptr) {
			$var($bytes, b, getBytes(manEntry));
			this->hasClassPathAttribute$ = match(JarFile::CLASSPATH_CHARS, b, JarFile::CLASSPATH_LASTOCC, JarFile::CLASSPATH_OPTOSFT) != -1;
			if (JarFile::MULTI_RELEASE_ENABLED) {
				int32_t i = match(JarFile::MULTIRELEASE_CHARS, b, JarFile::MULTIRELEASE_LASTOCC, JarFile::MULTIRELEASE_OPTOSFT);
				if (i != -1) {
					$var($bytes, lbuf, $new($bytes, 512));
					$var($Attributes, attr, $new($Attributes));
					attr->read($$new($Manifest$FastInputStream, $$new($ByteArrayInputStream, b)), lbuf);
					$init($Attributes$Name);
					this->isMultiRelease$ = $Boolean::parseBoolean($(attr->getValue($Attributes$Name::MULTI_RELEASE)));
				}
			}
		}
		this->hasCheckedSpecialAttributes = true;
	}
}

void JarFile::ensureInitialization() {
	$synchronized(this) {
		try {
			maybeInstantiateVerifier();
		} catch ($IOException& e) {
			$throwNew($RuntimeException, static_cast<$Throwable*>(e));
		}
		if (this->jv != nullptr && !this->jvInitialized) {
			$init($Boolean);
			$nc(JarFile::isInitializing$)->set($Boolean::TRUE);
			{
				$var($Throwable, var$0, nullptr);
				try {
					initializeVerifier();
					this->jvInitialized = true;
				} catch ($Throwable& var$1) {
					$assign(var$0, var$1);
				} /*finally*/ {
					$nc(JarFile::isInitializing$)->set($Boolean::FALSE);
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		}
	}
}

bool JarFile::isInitializing() {
	$init(JarFile);
	$var($Boolean, value, $cast($Boolean, $nc(JarFile::isInitializing$)->get()));
	return (value == nullptr) ? false : $nc(value)->booleanValue();
}

$JarEntry* JarFile::newEntry($JarEntry* je) {
	if (isMultiRelease()) {
		return getVersionedEntry($($nc(je)->getName()), je);
	}
	return je;
}

$JarEntry* JarFile::newEntry($String* name) {
	if (isMultiRelease()) {
		$var($JarEntry, vje, getVersionedEntry(name, nullptr));
		if (vje != nullptr) {
			return vje;
		}
	}
	return $new($JarFile$JarFileEntry, this, name);
}

$Enumeration* JarFile::entryNames($CodeSourceArray* cs) {
	$useLocalCurrentObjectStackCache();
	ensureInitialization();
	if (this->jv != nullptr) {
		return $nc(this->jv)->entryNames(this, cs);
	}
	bool includeUnsigned = false;
	{
		$var($CodeSourceArray, arr$, cs);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($CodeSource, c, arr$->get(i$));
			{
				if ($nc(c)->getCodeSigners() == nullptr) {
					includeUnsigned = true;
					break;
				}
			}
		}
	}
	if (includeUnsigned) {
		return unsignedEntryNames();
	} else {
		return $Collections::emptyEnumeration();
	}
}

$Enumeration* JarFile::entries2() {
	$useLocalCurrentObjectStackCache();
	ensureInitialization();
	if (this->jv != nullptr) {
		return $nc(this->jv)->entries2(this, $($nc(JarFile::JUZFA)->entries(this)));
	}
	$var($Enumeration, unfilteredEntries, $nc(JarFile::JUZFA)->entries(this));
	return $new($JarFile$1, this, unfilteredEntries);
}

$CodeSourceArray* JarFile::getCodeSources($URL* url) {
	$useLocalCurrentObjectStackCache();
	ensureInitialization();
	if (this->jv != nullptr) {
		return $nc(this->jv)->getCodeSources(this, url);
	}
	$var($Enumeration, unsigned$, unsignedEntryNames());
	if ($nc(unsigned$)->hasMoreElements()) {
		return $new($CodeSourceArray, {$($JarVerifier::getUnsignedCS(url))});
	} else {
		return nullptr;
	}
}

$Enumeration* JarFile::unsignedEntryNames() {
	$var($Enumeration, entries, this->entries());
	return $new($JarFile$2, this, entries);
}

$CodeSource* JarFile::getCodeSource($URL* url, $String* name) {
	$useLocalCurrentObjectStackCache();
	ensureInitialization();
	if (this->jv != nullptr) {
		if ($nc(this->jv)->eagerValidation) {
			$var($CodeSource, cs, nullptr);
			$var($JarEntry, je, getJarEntry(name));
			if (je != nullptr) {
				$assign(cs, $nc(this->jv)->getCodeSource(url, this, je));
			} else {
				$assign(cs, $nc(this->jv)->getCodeSource(url, name));
			}
			return cs;
		} else {
			return $nc(this->jv)->getCodeSource(url, name);
		}
	}
	return $JarVerifier::getUnsignedCS(url);
}

void JarFile::setEagerValidation(bool eager) {
	try {
		maybeInstantiateVerifier();
	} catch ($IOException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
	if (this->jv != nullptr) {
		$nc(this->jv)->setEagerValidation(eager);
	}
}

$List* JarFile::getManifestDigests() {
	ensureInitialization();
	if (this->jv != nullptr) {
		return $nc(this->jv)->getManifestDigests();
	}
	return $new($ArrayList);
}

void clinit$JarFile($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(JarFile::META_INF, "META-INF/"_s);
	$assignStatic(JarFile::META_INF_VERSIONS, $str({JarFile::META_INF, "versions/"_s}));
	$assignStatic(JarFile::MANIFEST_NAME, $str({JarFile::META_INF, "MANIFEST.MF"_s}));
	$assignStatic(JarFile::isInitializing$, $new($ThreadLocal));
	{
		$SharedSecrets::setJavaUtilJarAccess($$new($JavaUtilJarAccessImpl));
		$assignStatic(JarFile::JUZFA, $SharedSecrets::getJavaUtilZipFileAccess());
		$assignStatic(JarFile::BASE_VERSION, $Runtime$Version::parse($($Integer::toString(8))));
		JarFile::BASE_VERSION_FEATURE = $nc(JarFile::BASE_VERSION)->feature();
		$var($String, jarVersion, $GetPropertyAction::privilegedGetProperty("jdk.util.jar.version"_s));
		int32_t runtimeVersion = $nc($($Runtime::version()))->feature();
		if (jarVersion != nullptr) {
			int32_t jarVer = $Integer::parseInt(jarVersion);
			runtimeVersion = (jarVer > runtimeVersion) ? runtimeVersion : $Math::max(jarVer, JarFile::BASE_VERSION_FEATURE);
		}
		$assignStatic(JarFile::RUNTIME_VERSION, $Runtime$Version::parse($($Integer::toString(runtimeVersion))));
		$var($String, enableMultiRelease, $GetPropertyAction::privilegedGetProperty("jdk.util.jar.enableMultiRelease"_s, "true"_s));
		{
			$var($String, s9313$, enableMultiRelease);
			int32_t tmp9313$ = -1;
			switch ($nc(s9313$)->hashCode()) {
			case 0x05CB1923:
				{
					if (s9313$->equals("false"_s)) {
						tmp9313$ = 0;
					}
					break;
				}
			case 0x05D18AEB:
				{
					if (s9313$->equals("force"_s)) {
						tmp9313$ = 1;
					}
					break;
				}
			}
			switch (tmp9313$) {
			case 0:
				{
					{
						JarFile::MULTI_RELEASE_ENABLED = false;
						JarFile::MULTI_RELEASE_FORCED = false;
					}
					break;
				}
			case 1:
				{
					{
						JarFile::MULTI_RELEASE_ENABLED = true;
						JarFile::MULTI_RELEASE_FORCED = true;
					}
					break;
				}
			default:
				{
					{
						JarFile::MULTI_RELEASE_ENABLED = true;
						JarFile::MULTI_RELEASE_FORCED = false;
					}
					break;
				}
			}
		}
	}
	$assignStatic(JarFile::CLASSPATH_CHARS, $new($bytes, {
		(int8_t)u'C',
		(int8_t)u'L',
		(int8_t)u'A',
		(int8_t)u'S',
		(int8_t)u'S',
		(int8_t)u'-',
		(int8_t)u'P',
		(int8_t)u'A',
		(int8_t)u'T',
		(int8_t)u'H',
		(int8_t)u':',
		(int8_t)u' '
	}));
	$assignStatic(JarFile::MULTIRELEASE_CHARS, $new($bytes, {
		(int8_t)u'M',
		(int8_t)u'U',
		(int8_t)u'L',
		(int8_t)u'T',
		(int8_t)u'I',
		(int8_t)u'-',
		(int8_t)u'R',
		(int8_t)u'E',
		(int8_t)u'L',
		(int8_t)u'E',
		(int8_t)u'A',
		(int8_t)u'S',
		(int8_t)u'E',
		(int8_t)u':',
		(int8_t)u' ',
		(int8_t)u'T',
		(int8_t)u'R',
		(int8_t)u'U',
		(int8_t)u'E'
	}));
	{
		$assignStatic(JarFile::CLASSPATH_LASTOCC, $new($bytes, 65));
		$assignStatic(JarFile::CLASSPATH_OPTOSFT, $new($bytes, 12));
		$nc(JarFile::CLASSPATH_LASTOCC)->set((int32_t)u'C' - 32, (int8_t)1);
		$nc(JarFile::CLASSPATH_LASTOCC)->set((int32_t)u'L' - 32, (int8_t)2);
		$nc(JarFile::CLASSPATH_LASTOCC)->set((int32_t)u'S' - 32, (int8_t)5);
		$nc(JarFile::CLASSPATH_LASTOCC)->set((int32_t)u'-' - 32, (int8_t)6);
		$nc(JarFile::CLASSPATH_LASTOCC)->set((int32_t)u'P' - 32, (int8_t)7);
		$nc(JarFile::CLASSPATH_LASTOCC)->set((int32_t)u'A' - 32, (int8_t)8);
		$nc(JarFile::CLASSPATH_LASTOCC)->set((int32_t)u'T' - 32, (int8_t)9);
		$nc(JarFile::CLASSPATH_LASTOCC)->set((int32_t)u'H' - 32, (int8_t)10);
		$nc(JarFile::CLASSPATH_LASTOCC)->set((int32_t)u':' - 32, (int8_t)11);
		$nc(JarFile::CLASSPATH_LASTOCC)->set((int32_t)u' ' - 32, (int8_t)12);
		for (int32_t i = 0; i < 11; ++i) {
			$nc(JarFile::CLASSPATH_OPTOSFT)->set(i, (int8_t)12);
		}
		$nc(JarFile::CLASSPATH_OPTOSFT)->set(11, (int8_t)1);
		$assignStatic(JarFile::MULTIRELEASE_LASTOCC, $new($bytes, 65));
		$assignStatic(JarFile::MULTIRELEASE_OPTOSFT, $new($bytes, 19));
		$nc(JarFile::MULTIRELEASE_LASTOCC)->set((int32_t)u'M' - 32, (int8_t)1);
		$nc(JarFile::MULTIRELEASE_LASTOCC)->set((int32_t)u'I' - 32, (int8_t)5);
		$nc(JarFile::MULTIRELEASE_LASTOCC)->set((int32_t)u'-' - 32, (int8_t)6);
		$nc(JarFile::MULTIRELEASE_LASTOCC)->set((int32_t)u'L' - 32, (int8_t)9);
		$nc(JarFile::MULTIRELEASE_LASTOCC)->set((int32_t)u'A' - 32, (int8_t)11);
		$nc(JarFile::MULTIRELEASE_LASTOCC)->set((int32_t)u'S' - 32, (int8_t)12);
		$nc(JarFile::MULTIRELEASE_LASTOCC)->set((int32_t)u':' - 32, (int8_t)14);
		$nc(JarFile::MULTIRELEASE_LASTOCC)->set((int32_t)u' ' - 32, (int8_t)15);
		$nc(JarFile::MULTIRELEASE_LASTOCC)->set((int32_t)u'T' - 32, (int8_t)16);
		$nc(JarFile::MULTIRELEASE_LASTOCC)->set((int32_t)u'R' - 32, (int8_t)17);
		$nc(JarFile::MULTIRELEASE_LASTOCC)->set((int32_t)u'U' - 32, (int8_t)18);
		$nc(JarFile::MULTIRELEASE_LASTOCC)->set((int32_t)u'E' - 32, (int8_t)19);
		for (int32_t i = 0; i < 17; ++i) {
			$nc(JarFile::MULTIRELEASE_OPTOSFT)->set(i, (int8_t)19);
		}
		$nc(JarFile::MULTIRELEASE_OPTOSFT)->set(17, (int8_t)6);
		$nc(JarFile::MULTIRELEASE_OPTOSFT)->set(18, (int8_t)1);
	}
}

JarFile::JarFile() {
}

$Class* JarFile::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(JarFile$$Lambda$getBasename::classInfo$.name)) {
			return JarFile$$Lambda$getBasename::load$(name, initialize);
		}
		if (name->equals(JarFile$$Lambda$nonNull$1::classInfo$.name)) {
			return JarFile$$Lambda$nonNull$1::load$(name, initialize);
		}
		if (name->equals(JarFile$$Lambda$getJarEntry$2::classInfo$.name)) {
			return JarFile$$Lambda$getJarEntry$2::load$(name, initialize);
		}
	}
	$loadClass(JarFile, name, initialize, &_JarFile_ClassInfo_, clinit$JarFile, allocate$JarFile);
	return class$;
}

$Class* JarFile::class$ = nullptr;

		} // jar
	} // util
} // java