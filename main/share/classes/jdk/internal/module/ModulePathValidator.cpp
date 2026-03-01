#include <jdk/internal/module/ModulePathValidator.h>

#include <java/io/File.h>
#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/FindException.h>
#include <java/lang/module/ModuleDescriptor.h>
#include <java/lang/module/ModuleFinder.h>
#include <java/lang/module/ModuleReference.h>
#include <java/net/URI.h>
#include <java/nio/file/DirectoryStream.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/NoSuchFileException.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/util/Comparator.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Stream.h>
#include <jcpp.h>

#undef INDENT
#undef MODULE_INFO

using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $PathArray = $Array<::java::nio::file::Path>;
using $File = ::java::io::File;
using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $FindException = ::java::lang::module::FindException;
using $ModuleDescriptor = ::java::lang::module::ModuleDescriptor;
using $ModuleFinder = ::java::lang::module::ModuleFinder;
using $ModuleReference = ::java::lang::module::ModuleReference;
using $URI = ::java::net::URI;
using $DirectoryStream = ::java::nio::file::DirectoryStream;
using $Files = ::java::nio::file::Files;
using $NoSuchFileException = ::java::nio::file::NoSuchFileException;
using $Path = ::java::nio::file::Path;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $Comparator = ::java::util::Comparator;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $Stream = ::java::util::stream::Stream;

namespace jdk {
	namespace internal {
		namespace module {

class ModulePathValidator$$Lambda$lambda$scanAllModules$0 : public $Function {
	$class(ModulePathValidator$$Lambda$lambda$scanAllModules$0, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* x$0) override {
		 return $of(ModulePathValidator::lambda$scanAllModules$0($cast($String, x$0)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePathValidator$$Lambda$lambda$scanAllModules$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ModulePathValidator$$Lambda$lambda$scanAllModules$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModulePathValidator$$Lambda$lambda$scanAllModules$0, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModulePathValidator$$Lambda$lambda$scanAllModules$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ModulePathValidator$$Lambda$lambda$scanAllModules$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePathValidator$$Lambda$lambda$scanAllModules$0",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ModulePathValidator$$Lambda$lambda$scanAllModules$0::load$($String* name, bool initialize) {
	$loadClass(ModulePathValidator$$Lambda$lambda$scanAllModules$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePathValidator$$Lambda$lambda$scanAllModules$0::class$ = nullptr;

class ModulePathValidator$$Lambda$scan$1 : public $Consumer {
	$class(ModulePathValidator$$Lambda$scan$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$(ModulePathValidator* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* entry) override {
		$nc(inst$)->scan($cast($Path, entry));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePathValidator$$Lambda$scan$1>());
	}
	ModulePathValidator* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModulePathValidator$$Lambda$scan$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ModulePathValidator$$Lambda$scan$1, inst$)},
	{}
};
$MethodInfo ModulePathValidator$$Lambda$scan$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/module/ModulePathValidator;)V", nullptr, $PUBLIC, $method(ModulePathValidator$$Lambda$scan$1, init$, void, ModulePathValidator*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ModulePathValidator$$Lambda$scan$1, accept, void, Object$*)},
	{}
};
$ClassInfo ModulePathValidator$$Lambda$scan$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePathValidator$$Lambda$scan$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ModulePathValidator$$Lambda$scan$1::load$($String* name, bool initialize) {
	$loadClass(ModulePathValidator$$Lambda$scan$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePathValidator$$Lambda$scan$1::class$ = nullptr;

class ModulePathValidator$$Lambda$descriptor$2 : public $Function {
	$class(ModulePathValidator$$Lambda$descriptor$2, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($ModuleReference, inst$)->descriptor());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePathValidator$$Lambda$descriptor$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ModulePathValidator$$Lambda$descriptor$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModulePathValidator$$Lambda$descriptor$2, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModulePathValidator$$Lambda$descriptor$2, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ModulePathValidator$$Lambda$descriptor$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePathValidator$$Lambda$descriptor$2",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ModulePathValidator$$Lambda$descriptor$2::load$($String* name, bool initialize) {
	$loadClass(ModulePathValidator$$Lambda$descriptor$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePathValidator$$Lambda$descriptor$2::class$ = nullptr;

class ModulePathValidator$$Lambda$process$3 : public $Consumer {
	$class(ModulePathValidator$$Lambda$process$3, $NO_CLASS_INIT, $Consumer)
public:
	void init$(ModulePathValidator* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* mref) override {
		$nc(inst$)->process($cast($ModuleReference, mref));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePathValidator$$Lambda$process$3>());
	}
	ModulePathValidator* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModulePathValidator$$Lambda$process$3::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ModulePathValidator$$Lambda$process$3, inst$)},
	{}
};
$MethodInfo ModulePathValidator$$Lambda$process$3::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/module/ModulePathValidator;)V", nullptr, $PUBLIC, $method(ModulePathValidator$$Lambda$process$3, init$, void, ModulePathValidator*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ModulePathValidator$$Lambda$process$3, accept, void, Object$*)},
	{}
};
$ClassInfo ModulePathValidator$$Lambda$process$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePathValidator$$Lambda$process$3",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ModulePathValidator$$Lambda$process$3::load$($String* name, bool initialize) {
	$loadClass(ModulePathValidator$$Lambda$process$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePathValidator$$Lambda$process$3::class$ = nullptr;

class ModulePathValidator$$Lambda$lambda$printModule$2$4 : public $Predicate {
	$class(ModulePathValidator$$Lambda$lambda$printModule$2$4, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* uri) override {
		 return ModulePathValidator::lambda$printModule$2($cast($URI, uri));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePathValidator$$Lambda$lambda$printModule$2$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ModulePathValidator$$Lambda$lambda$printModule$2$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModulePathValidator$$Lambda$lambda$printModule$2$4, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ModulePathValidator$$Lambda$lambda$printModule$2$4, test, bool, Object$*)},
	{}
};
$ClassInfo ModulePathValidator$$Lambda$lambda$printModule$2$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePathValidator$$Lambda$lambda$printModule$2$4",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* ModulePathValidator$$Lambda$lambda$printModule$2$4::load$($String* name, bool initialize) {
	$loadClass(ModulePathValidator$$Lambda$lambda$printModule$2$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePathValidator$$Lambda$lambda$printModule$2$4::class$ = nullptr;

class ModulePathValidator$$Lambda$lambda$printModule$3$5 : public $Consumer {
	$class(ModulePathValidator$$Lambda$lambda$printModule$3$5, $NO_CLASS_INIT, $Consumer)
public:
	void init$(ModulePathValidator* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* uri) override {
		$nc(inst$)->lambda$printModule$3($cast($URI, uri));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModulePathValidator$$Lambda$lambda$printModule$3$5>());
	}
	ModulePathValidator* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModulePathValidator$$Lambda$lambda$printModule$3$5::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ModulePathValidator$$Lambda$lambda$printModule$3$5, inst$)},
	{}
};
$MethodInfo ModulePathValidator$$Lambda$lambda$printModule$3$5::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/module/ModulePathValidator;)V", nullptr, $PUBLIC, $method(ModulePathValidator$$Lambda$lambda$printModule$3$5, init$, void, ModulePathValidator*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ModulePathValidator$$Lambda$lambda$printModule$3$5, accept, void, Object$*)},
	{}
};
$ClassInfo ModulePathValidator$$Lambda$lambda$printModule$3$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModulePathValidator$$Lambda$lambda$printModule$3$5",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ModulePathValidator$$Lambda$lambda$printModule$3$5::load$($String* name, bool initialize) {
	$loadClass(ModulePathValidator$$Lambda$lambda$printModule$3$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModulePathValidator$$Lambda$lambda$printModule$3$5::class$ = nullptr;

$FieldInfo _ModulePathValidator_FieldInfo_[] = {
	{"MODULE_INFO", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ModulePathValidator, MODULE_INFO)},
	{"INDENT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ModulePathValidator, INDENT)},
	{"nameToModule", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/module/ModuleReference;>;", $PRIVATE | $FINAL, $field(ModulePathValidator, nameToModule)},
	{"packageToModule", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/module/ModuleReference;>;", $PRIVATE | $FINAL, $field(ModulePathValidator, packageToModule)},
	{"out", "Ljava/io/PrintStream;", nullptr, $PRIVATE | $FINAL, $field(ModulePathValidator, out)},
	{"errorCount", "I", nullptr, $PRIVATE, $field(ModulePathValidator, errorCount)},
	{}
};

$MethodInfo _ModulePathValidator_MethodInfo_[] = {
	{"<init>", "(Ljava/io/PrintStream;)V", nullptr, $PRIVATE, $method(ModulePathValidator, init$, void, $PrintStream*)},
	{"isJrt", "(Ljava/net/URI;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ModulePathValidator, isJrt, bool, $URI*)},
	{"lambda$printModule$2", "(Ljava/net/URI;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModulePathValidator, lambda$printModule$2, bool, $URI*)},
	{"lambda$printModule$3", "(Ljava/net/URI;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(ModulePathValidator, lambda$printModule$3, void, $URI*)},
	{"lambda$scanAllModules$0", "(Ljava/lang/String;)Ljava/nio/file/Path;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModulePathValidator, lambda$scanAllModules$0, $Path*, $String*)},
	{"printModule", "(Ljava/lang/module/ModuleReference;)V", nullptr, $PRIVATE, $method(ModulePathValidator, printModule, void, $ModuleReference*)},
	{"process", "(Ljava/lang/module/ModuleReference;)V", nullptr, $PRIVATE, $method(ModulePathValidator, process, void, $ModuleReference*)},
	{"scan", "(Ljava/nio/file/Path;)V", nullptr, $PRIVATE, $method(ModulePathValidator, scan, void, $Path*)},
	{"scanAllModules", "(Ljava/io/PrintStream;)I", nullptr, $STATIC, $staticMethod(ModulePathValidator, scanAllModules, int32_t, $PrintStream*)},
	{"scanDirectory", "(Ljava/nio/file/Path;)V", nullptr, $PRIVATE, $method(ModulePathValidator, scanDirectory, void, $Path*)},
	{"scanModule", "(Ljava/nio/file/Path;)Ljava/util/Optional;", "(Ljava/nio/file/Path;)Ljava/util/Optional<Ljava/lang/module/ModuleReference;>;", $PRIVATE, $method(ModulePathValidator, scanModule, $Optional*, $Path*)},
	{}
};

$ClassInfo _ModulePathValidator_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.module.ModulePathValidator",
	"java.lang.Object",
	nullptr,
	_ModulePathValidator_FieldInfo_,
	_ModulePathValidator_MethodInfo_
};

$Object* allocate$ModulePathValidator($Class* clazz) {
	return $of($alloc(ModulePathValidator));
}

$String* ModulePathValidator::MODULE_INFO = nullptr;
$String* ModulePathValidator::INDENT = nullptr;

void ModulePathValidator::init$($PrintStream* out) {
	$set(this, nameToModule, $new($HashMap));
	$set(this, packageToModule, $new($HashMap));
	$set(this, out, out);
}

int32_t ModulePathValidator::scanAllModules($PrintStream* out) {
	$init(ModulePathValidator);
	$useLocalCurrentObjectStackCache();
	$var(ModulePathValidator, validator, $new(ModulePathValidator, out));
	$var($String, value, $System::getProperty("jdk.module.upgrade.path"_s));
	if (value != nullptr) {
		$init($File);
		$nc($($nc($($Stream::of($(value->split($File::pathSeparator)))))->map(static_cast<$Function*>($$new(ModulePathValidator$$Lambda$lambda$scanAllModules$0)))))->forEach(static_cast<$Consumer*>($$new(ModulePathValidator$$Lambda$scan$1, static_cast<ModulePathValidator*>(validator))));
	}
	$nc($($nc($($nc($($nc($($ModuleFinder::ofSystem()))->findAll()))->stream()))->sorted($($Comparator::comparing(static_cast<$Function*>($$new(ModulePathValidator$$Lambda$descriptor$2)))))))->forEach(static_cast<$Consumer*>($$new(ModulePathValidator$$Lambda$process$3, static_cast<ModulePathValidator*>(validator))));
	$assign(value, $System::getProperty("jdk.module.path"_s));
	if (value != nullptr) {
		$init($File);
		$nc($($nc($($Stream::of($(value->split($File::pathSeparator)))))->map(static_cast<$Function*>($$new(ModulePathValidator$$Lambda$lambda$scanAllModules$0)))))->forEach(static_cast<$Consumer*>($$new(ModulePathValidator$$Lambda$scan$1, static_cast<ModulePathValidator*>(validator))));
	}
	return validator->errorCount;
}

void ModulePathValidator::printModule($ModuleReference* mref) {
	$useLocalCurrentObjectStackCache();
	$nc($($nc($($nc(mref)->location()))->filter(static_cast<$Predicate*>($$new(ModulePathValidator$$Lambda$lambda$printModule$2$4)))))->ifPresent(static_cast<$Consumer*>($$new(ModulePathValidator$$Lambda$lambda$printModule$3$5, this)));
	$var($ModuleDescriptor, descriptor, mref->descriptor());
	$nc(this->out)->print($($nc(descriptor)->name()));
	if ($nc(descriptor)->isAutomatic()) {
		$nc(this->out)->print(" automatic"_s);
	}
	$nc(this->out)->println();
}

void ModulePathValidator::process($ModuleReference* mref) {
	$useLocalCurrentObjectStackCache();
	$var($String, name, $nc($($nc(mref)->descriptor()))->name());
	$var($ModuleReference, previous, $cast($ModuleReference, $nc(this->nameToModule)->putIfAbsent(name, mref)));
	if (previous != nullptr) {
		printModule(mref);
		$nc(this->out)->print($$str({ModulePathValidator::INDENT, "shadowed by "_s}));
		printModule(previous);
	} else {
		bool first = true;
		{
			$var($Iterator, i$, $nc($($nc($(mref->descriptor()))->packages()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, pkg, $cast($String, i$->next()));
				{
					$assign(previous, $cast($ModuleReference, $nc(this->packageToModule)->putIfAbsent(pkg, mref)));
					if (previous != nullptr) {
						if (first) {
							printModule(mref);
							first = false;
							++this->errorCount;
						}
						$var($String, mn, $nc($(previous->descriptor()))->name());
						$nc(this->out)->println($$str({ModulePathValidator::INDENT, "contains "_s, pkg, " conflicts with module "_s, mn}));
					}
				}
			}
		}
	}
}

void ModulePathValidator::scan($Path* entry) {
	$useLocalCurrentObjectStackCache();
	$var($BasicFileAttributes, attrs, nullptr);
	try {
		$load($BasicFileAttributes);
		$assign(attrs, $Files::readAttributes(entry, $BasicFileAttributes::class$, $$new($LinkOptionArray, 0)));
	} catch ($NoSuchFileException& ignore) {
		return;
	} catch ($IOException& ioe) {
		$nc(this->out)->println($$str({entry, " "_s, ioe}));
		++this->errorCount;
		return;
	}
	$var($String, fn, $nc($($nc(entry)->getFileName()))->toString());
	bool var$0 = $nc(attrs)->isRegularFile();
	if (var$0 && $nc(fn)->endsWith(".jar"_s)) {
		$nc($(scanModule(entry)))->ifPresent(static_cast<$Consumer*>($$new(ModulePathValidator$$Lambda$process$3, this)));
	} else if (attrs->isDirectory()) {
		$var($Path, mi, entry->resolve(ModulePathValidator::MODULE_INFO));
		if ($Files::exists(mi, $$new($LinkOptionArray, 0))) {
			$nc($(scanModule(entry)))->ifPresent(static_cast<$Consumer*>($$new(ModulePathValidator$$Lambda$process$3, this)));
		} else {
			scanDirectory(entry);
		}
	}
}

void ModulePathValidator::scanDirectory($Path* dir) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($DirectoryStream, stream, $Files::newDirectoryStream(dir));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($Map, moduleToEntry, $new($HashMap));
					{
						$var($Iterator, i$, $nc(stream)->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($Path, entry, $cast($Path, i$->next()));
							{
								$var($BasicFileAttributes, attrs, nullptr);
								try {
									$load($BasicFileAttributes);
									$assign(attrs, $Files::readAttributes(entry, $BasicFileAttributes::class$, $$new($LinkOptionArray, 0)));
								} catch ($IOException& ioe) {
									$nc(this->out)->println($$str({entry, " "_s, ioe}));
									++this->errorCount;
									continue;
								}
								$var($ModuleReference, mref, nullptr);
								$var($String, fn, $nc($($nc(entry)->getFileName()))->toString());
								bool var$1 = $nc(attrs)->isRegularFile();
								if (var$1 && $nc(fn)->endsWith(".jar"_s)) {
									$assign(mref, $cast($ModuleReference, $nc($(scanModule(entry)))->orElse(nullptr)));
								} else if (attrs->isDirectory()) {
									$var($Path, mi, entry->resolve(ModulePathValidator::MODULE_INFO));
									if ($Files::exists(mi, $$new($LinkOptionArray, 0))) {
										$assign(mref, $cast($ModuleReference, $nc($(scanModule(entry)))->orElse(nullptr)));
									}
								}
								if (mref != nullptr) {
									$var($String, name, $nc($(mref->descriptor()))->name());
									$var($Path, previous, $cast($Path, moduleToEntry->putIfAbsent(name, entry)));
									if (previous != nullptr) {
										printModule(mref);
										$nc(this->out)->println($$str({ModulePathValidator::INDENT, "contains same module as "_s, $(previous->getFileName())}));
										++this->errorCount;
									} else {
										process(mref);
									}
								}
							}
						}
					}
				} catch ($Throwable& t$) {
					if (stream != nullptr) {
						try {
							stream->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$2) {
				$assign(var$0, var$2);
			} /*finally*/ {
				if (stream != nullptr) {
					stream->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} catch ($IOException& ioe) {
		$nc(this->out)->println($$str({dir, " "_s, ioe}));
		++this->errorCount;
	}
}

$Optional* ModulePathValidator::scanModule($Path* entry) {
	$useLocalCurrentObjectStackCache();
	$var($ModuleFinder, finder, $ModuleFinder::of($$new($PathArray, {entry})));
	try {
		return $nc($($nc($($nc(finder)->findAll()))->stream()))->findFirst();
	} catch ($FindException& e) {
		$nc(this->out)->println($of(entry));
		$nc(this->out)->println($$str({ModulePathValidator::INDENT, $(e->getMessage())}));
		$var($Throwable, cause, e->getCause());
		if (cause != nullptr) {
			$nc(this->out)->println($$str({ModulePathValidator::INDENT, cause}));
		}
		++this->errorCount;
		return $Optional::empty();
	}
	$shouldNotReachHere();
}

bool ModulePathValidator::isJrt($URI* uri) {
	$init(ModulePathValidator);
	return (uri != nullptr && $nc($(uri->getScheme()))->equalsIgnoreCase("jrt"_s));
}

void ModulePathValidator::lambda$printModule$3($URI* uri) {
	$nc(this->out)->print($$str({uri, " "_s}));
}

bool ModulePathValidator::lambda$printModule$2($URI* uri) {
	$init(ModulePathValidator);
	return !isJrt(uri);
}

$Path* ModulePathValidator::lambda$scanAllModules$0($String* x$0) {
	$init(ModulePathValidator);
	return $Path::of(x$0, $$new($StringArray, 0));
}

ModulePathValidator::ModulePathValidator() {
}

void clinit$ModulePathValidator($Class* class$) {
	$assignStatic(ModulePathValidator::MODULE_INFO, "module-info.class"_s);
	$assignStatic(ModulePathValidator::INDENT, "    "_s);
}

$Class* ModulePathValidator::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ModulePathValidator$$Lambda$lambda$scanAllModules$0::classInfo$.name)) {
			return ModulePathValidator$$Lambda$lambda$scanAllModules$0::load$(name, initialize);
		}
		if (name->equals(ModulePathValidator$$Lambda$scan$1::classInfo$.name)) {
			return ModulePathValidator$$Lambda$scan$1::load$(name, initialize);
		}
		if (name->equals(ModulePathValidator$$Lambda$descriptor$2::classInfo$.name)) {
			return ModulePathValidator$$Lambda$descriptor$2::load$(name, initialize);
		}
		if (name->equals(ModulePathValidator$$Lambda$process$3::classInfo$.name)) {
			return ModulePathValidator$$Lambda$process$3::load$(name, initialize);
		}
		if (name->equals(ModulePathValidator$$Lambda$lambda$printModule$2$4::classInfo$.name)) {
			return ModulePathValidator$$Lambda$lambda$printModule$2$4::load$(name, initialize);
		}
		if (name->equals(ModulePathValidator$$Lambda$lambda$printModule$3$5::classInfo$.name)) {
			return ModulePathValidator$$Lambda$lambda$printModule$3$5::load$(name, initialize);
		}
	}
	$loadClass(ModulePathValidator, name, initialize, &_ModulePathValidator_ClassInfo_, clinit$ModulePathValidator, allocate$ModulePathValidator);
	return class$;
}

$Class* ModulePathValidator::class$ = nullptr;

		} // module
	} // internal
} // jdk