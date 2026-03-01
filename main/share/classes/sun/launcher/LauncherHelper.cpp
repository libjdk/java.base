#include <sun/launcher/LauncherHelper.h>

#include <java/io/File.h>
#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/io/UnsupportedEncodingException.h>
#include <java/lang/CharSequence.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/InternalError.h>
#include <java/lang/LinkageError.h>
#include <java/lang/Module.h>
#include <java/lang/ModuleLayer.h>
#include <java/lang/NoClassDefFoundError.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/Runtime.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/Configuration.h>
#include <java/lang/module/ModuleDescriptor$Exports.h>
#include <java/lang/module/ModuleDescriptor$Opens.h>
#include <java/lang/module/ModuleDescriptor$Provides.h>
#include <java/lang/module/ModuleDescriptor$Requires.h>
#include <java/lang/module/ModuleDescriptor.h>
#include <java/lang/module/ModuleFinder.h>
#include <java/lang/module/ModuleReference.h>
#include <java/lang/module/ResolvedModule.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Modifier.h>
#include <java/net/URI.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/file/DirectoryStream.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/Path.h>
#include <java/text/MessageFormat.h>
#include <java/text/Normalizer$Form.h>
#include <java/text/Normalizer.h>
#include <java/util/AbstractSet.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Comparator.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale$Category.h>
#include <java/util/Locale.h>
#include <java/util/Optional.h>
#include <java/util/Properties.h>
#include <java/util/ResourceBundle.h>
#include <java/util/Set.h>
#include <java/util/TreeSet.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/jar/Attributes$Name.h>
#include <java/util/jar/Attributes.h>
#include <java/util/jar/JarFile.h>
#include <java/util/jar/Manifest.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/misc/VM.h>
#include <jdk/internal/module/ModuleBootstrap.h>
#include <jdk/internal/module/Modules.h>
#include <jdk/internal/platform/Container.h>
#include <jdk/internal/platform/Metrics.h>
#include <sun/launcher/LauncherHelper$FXHelper.h>
#include <sun/launcher/LauncherHelper$JrtFirstComparator.h>
#include <sun/launcher/LauncherHelper$ResourceBundleHolder.h>
#include <sun/launcher/LauncherHelper$SizePrefix.h>
#include <sun/launcher/LauncherHelper$StdArg.h>
#include <jcpp.h>

#undef ADD_EXPORTS
#undef ADD_OPENS
#undef DISPLAY
#undef FORMAT
#undef INDENT
#undef JAVAFX_APPLICATION_CLASS_NAME
#undef JAVAFX_APPLICATION_MARKER
#undef JAVAFX_FXHELPER_CLASS_NAME_SUFFIX
#undef LAUNCHER_AGENT_CLASS
#undef LM_CLASS
#undef LM_JAR
#undef LM_MODULE
#undef LM_SOURCE
#undef LM_UNKNOWN
#undef LOCALE_SETTINGS
#undef MAIN_CLASS
#undef NFC
#undef NFD
#undef PROP_SETTINGS
#undef RB
#undef TYPE
#undef VM_SETTINGS

using $LocaleArray = $Array<::java::util::Locale>;
using $File = ::java::io::File;
using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $LinkageError = ::java::lang::LinkageError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $ModuleLayer = ::java::lang::ModuleLayer;
using $NoClassDefFoundError = ::java::lang::NoClassDefFoundError;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $Runtime = ::java::lang::Runtime;
using $Void = ::java::lang::Void;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Configuration = ::java::lang::module::Configuration;
using $ModuleDescriptor = ::java::lang::module::ModuleDescriptor;
using $ModuleDescriptor$Exports = ::java::lang::module::ModuleDescriptor$Exports;
using $ModuleDescriptor$Opens = ::java::lang::module::ModuleDescriptor$Opens;
using $ModuleDescriptor$Provides = ::java::lang::module::ModuleDescriptor$Provides;
using $ModuleDescriptor$Requires = ::java::lang::module::ModuleDescriptor$Requires;
using $ModuleFinder = ::java::lang::module::ModuleFinder;
using $ModuleReference = ::java::lang::module::ModuleReference;
using $ResolvedModule = ::java::lang::module::ResolvedModule;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $Method = ::java::lang::reflect::Method;
using $Modifier = ::java::lang::reflect::Modifier;
using $URI = ::java::net::URI;
using $Charset = ::java::nio::charset::Charset;
using $DirectoryStream = ::java::nio::file::DirectoryStream;
using $Files = ::java::nio::file::Files;
using $Path = ::java::nio::file::Path;
using $MessageFormat = ::java::text::MessageFormat;
using $Normalizer = ::java::text::Normalizer;
using $Normalizer$Form = ::java::text::Normalizer$Form;
using $AbstractSet = ::java::util::AbstractSet;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Comparator = ::java::util::Comparator;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Locale$Category = ::java::util::Locale$Category;
using $Optional = ::java::util::Optional;
using $Properties = ::java::util::Properties;
using $ResourceBundle = ::java::util::ResourceBundle;
using $Set = ::java::util::Set;
using $TreeSet = ::java::util::TreeSet;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $Attributes = ::java::util::jar::Attributes;
using $Attributes$Name = ::java::util::jar::Attributes$Name;
using $JarFile = ::java::util::jar::JarFile;
using $Manifest = ::java::util::jar::Manifest;
using $Collectors = ::java::util::stream::Collectors;
using $Stream = ::java::util::stream::Stream;
using $VM = ::jdk::internal::misc::VM;
using $ModuleBootstrap = ::jdk::internal::module::ModuleBootstrap;
using $Modules = ::jdk::internal::module::Modules;
using $Container = ::jdk::internal::platform::Container;
using $Metrics = ::jdk::internal::platform::Metrics;
using $LauncherHelper$FXHelper = ::sun::launcher::LauncherHelper$FXHelper;
using $LauncherHelper$JrtFirstComparator = ::sun::launcher::LauncherHelper$JrtFirstComparator;
using $LauncherHelper$ResourceBundleHolder = ::sun::launcher::LauncherHelper$ResourceBundleHolder;
using $LauncherHelper$SizePrefix = ::sun::launcher::LauncherHelper$SizePrefix;
using $LauncherHelper$StdArg = ::sun::launcher::LauncherHelper$StdArg;

namespace sun {
	namespace launcher {

class LauncherHelper$$Lambda$lambda$getMainClassFromJar$0 : public $Consumer {
	$class(LauncherHelper$$Lambda$lambda$getMainClassFromJar$0, $NO_CLASS_INIT, $Consumer)
public:
	void init$($String* jarname) {
		$set(this, jarname, jarname);
	}
	virtual void accept(Object$* m) override {
		LauncherHelper::lambda$getMainClassFromJar$0(jarname, $cast($Module, m));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LauncherHelper$$Lambda$lambda$getMainClassFromJar$0>());
	}
	$String* jarname = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LauncherHelper$$Lambda$lambda$getMainClassFromJar$0::fieldInfos[2] = {
	{"jarname", "Ljava/lang/String;", nullptr, $PUBLIC, $field(LauncherHelper$$Lambda$lambda$getMainClassFromJar$0, jarname)},
	{}
};
$MethodInfo LauncherHelper$$Lambda$lambda$getMainClassFromJar$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(LauncherHelper$$Lambda$lambda$getMainClassFromJar$0, init$, void, $String*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(LauncherHelper$$Lambda$lambda$getMainClassFromJar$0, accept, void, Object$*)},
	{}
};
$ClassInfo LauncherHelper$$Lambda$lambda$getMainClassFromJar$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.launcher.LauncherHelper$$Lambda$lambda$getMainClassFromJar$0",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* LauncherHelper$$Lambda$lambda$getMainClassFromJar$0::load$($String* name, bool initialize) {
	$loadClass(LauncherHelper$$Lambda$lambda$getMainClassFromJar$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LauncherHelper$$Lambda$lambda$getMainClassFromJar$0::class$ = nullptr;

class LauncherHelper$$Lambda$lambda$addExportsOrOpens$1$1 : public $Predicate {
	$class(LauncherHelper$$Lambda$lambda$addExportsOrOpens$1$1, $NO_CLASS_INIT, $Predicate)
public:
	void init$($String* pn) {
		$set(this, pn, pn);
	}
	virtual bool test(Object$* m) override {
		 return LauncherHelper::lambda$addExportsOrOpens$1(pn, $cast($Module, m));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LauncherHelper$$Lambda$lambda$addExportsOrOpens$1$1>());
	}
	$String* pn = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LauncherHelper$$Lambda$lambda$addExportsOrOpens$1$1::fieldInfos[2] = {
	{"pn", "Ljava/lang/String;", nullptr, $PUBLIC, $field(LauncherHelper$$Lambda$lambda$addExportsOrOpens$1$1, pn)},
	{}
};
$MethodInfo LauncherHelper$$Lambda$lambda$addExportsOrOpens$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(LauncherHelper$$Lambda$lambda$addExportsOrOpens$1$1, init$, void, $String*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(LauncherHelper$$Lambda$lambda$addExportsOrOpens$1$1, test, bool, Object$*)},
	{}
};
$ClassInfo LauncherHelper$$Lambda$lambda$addExportsOrOpens$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.launcher.LauncherHelper$$Lambda$lambda$addExportsOrOpens$1$1",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* LauncherHelper$$Lambda$lambda$addExportsOrOpens$1$1::load$($String* name, bool initialize) {
	$loadClass(LauncherHelper$$Lambda$lambda$addExportsOrOpens$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LauncherHelper$$Lambda$lambda$addExportsOrOpens$1$1::class$ = nullptr;

class LauncherHelper$$Lambda$lambda$addExportsOrOpens$2$2 : public $Consumer {
	$class(LauncherHelper$$Lambda$lambda$addExportsOrOpens$2$2, $NO_CLASS_INIT, $Consumer)
public:
	void init$(bool open, $String* pn) {
		this->open = open;
		$set(this, pn, pn);
	}
	virtual void accept(Object$* m) override {
		LauncherHelper::lambda$addExportsOrOpens$2(open, pn, $cast($Module, m));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LauncherHelper$$Lambda$lambda$addExportsOrOpens$2$2>());
	}
	bool open = false;
	$String* pn = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LauncherHelper$$Lambda$lambda$addExportsOrOpens$2$2::fieldInfos[3] = {
	{"open", "Z", nullptr, $PUBLIC, $field(LauncherHelper$$Lambda$lambda$addExportsOrOpens$2$2, open)},
	{"pn", "Ljava/lang/String;", nullptr, $PUBLIC, $field(LauncherHelper$$Lambda$lambda$addExportsOrOpens$2$2, pn)},
	{}
};
$MethodInfo LauncherHelper$$Lambda$lambda$addExportsOrOpens$2$2::methodInfos[3] = {
	{"<init>", "(ZLjava/lang/String;)V", nullptr, $PUBLIC, $method(LauncherHelper$$Lambda$lambda$addExportsOrOpens$2$2, init$, void, bool, $String*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(LauncherHelper$$Lambda$lambda$addExportsOrOpens$2$2, accept, void, Object$*)},
	{}
};
$ClassInfo LauncherHelper$$Lambda$lambda$addExportsOrOpens$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.launcher.LauncherHelper$$Lambda$lambda$addExportsOrOpens$2$2",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* LauncherHelper$$Lambda$lambda$addExportsOrOpens$2$2::load$($String* name, bool initialize) {
	$loadClass(LauncherHelper$$Lambda$lambda$addExportsOrOpens$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LauncherHelper$$Lambda$lambda$addExportsOrOpens$2$2::class$ = nullptr;

class LauncherHelper$$Lambda$showModule$3 : public $Consumer {
	$class(LauncherHelper$$Lambda$showModule$3, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* mref) override {
		LauncherHelper::showModule($cast($ModuleReference, mref));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LauncherHelper$$Lambda$showModule$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LauncherHelper$$Lambda$showModule$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LauncherHelper$$Lambda$showModule$3, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(LauncherHelper$$Lambda$showModule$3, accept, void, Object$*)},
	{}
};
$ClassInfo LauncherHelper$$Lambda$showModule$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.launcher.LauncherHelper$$Lambda$showModule$3",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* LauncherHelper$$Lambda$showModule$3::load$($String* name, bool initialize) {
	$loadClass(LauncherHelper$$Lambda$showModule$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LauncherHelper$$Lambda$showModule$3::class$ = nullptr;

class LauncherHelper$$Lambda$reference$4 : public $Function {
	$class(LauncherHelper$$Lambda$reference$4, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($ResolvedModule, inst$)->reference());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LauncherHelper$$Lambda$reference$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LauncherHelper$$Lambda$reference$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LauncherHelper$$Lambda$reference$4, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LauncherHelper$$Lambda$reference$4, apply, $Object*, Object$*)},
	{}
};
$ClassInfo LauncherHelper$$Lambda$reference$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.launcher.LauncherHelper$$Lambda$reference$4",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* LauncherHelper$$Lambda$reference$4::load$($String* name, bool initialize) {
	$loadClass(LauncherHelper$$Lambda$reference$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LauncherHelper$$Lambda$reference$4::class$ = nullptr;

class LauncherHelper$$Lambda$lambda$describeModule$3$5 : public $Predicate {
	$class(LauncherHelper$$Lambda$lambda$describeModule$3$5, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* e) override {
		 return LauncherHelper::lambda$describeModule$3($cast($ModuleDescriptor$Exports, e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LauncherHelper$$Lambda$lambda$describeModule$3$5>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LauncherHelper$$Lambda$lambda$describeModule$3$5::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LauncherHelper$$Lambda$lambda$describeModule$3$5, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(LauncherHelper$$Lambda$lambda$describeModule$3$5, test, bool, Object$*)},
	{}
};
$ClassInfo LauncherHelper$$Lambda$lambda$describeModule$3$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.launcher.LauncherHelper$$Lambda$lambda$describeModule$3$5",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* LauncherHelper$$Lambda$lambda$describeModule$3$5::load$($String* name, bool initialize) {
	$loadClass(LauncherHelper$$Lambda$lambda$describeModule$3$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LauncherHelper$$Lambda$lambda$describeModule$3$5::class$ = nullptr;

class LauncherHelper$$Lambda$source$6 : public $Function {
	$class(LauncherHelper$$Lambda$source$6, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($ModuleDescriptor$Exports, inst$)->source());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LauncherHelper$$Lambda$source$6>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LauncherHelper$$Lambda$source$6::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LauncherHelper$$Lambda$source$6, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LauncherHelper$$Lambda$source$6, apply, $Object*, Object$*)},
	{}
};
$ClassInfo LauncherHelper$$Lambda$source$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.launcher.LauncherHelper$$Lambda$source$6",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* LauncherHelper$$Lambda$source$6::load$($String* name, bool initialize) {
	$loadClass(LauncherHelper$$Lambda$source$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LauncherHelper$$Lambda$source$6::class$ = nullptr;

class LauncherHelper$$Lambda$lambda$describeModule$4$7 : public $Function {
	$class(LauncherHelper$$Lambda$lambda$describeModule$4$7, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* e) override {
		 return $of(LauncherHelper::lambda$describeModule$4($cast($ModuleDescriptor$Exports, e)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LauncherHelper$$Lambda$lambda$describeModule$4$7>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LauncherHelper$$Lambda$lambda$describeModule$4$7::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LauncherHelper$$Lambda$lambda$describeModule$4$7, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LauncherHelper$$Lambda$lambda$describeModule$4$7, apply, $Object*, Object$*)},
	{}
};
$ClassInfo LauncherHelper$$Lambda$lambda$describeModule$4$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.launcher.LauncherHelper$$Lambda$lambda$describeModule$4$7",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* LauncherHelper$$Lambda$lambda$describeModule$4$7::load$($String* name, bool initialize) {
	$loadClass(LauncherHelper$$Lambda$lambda$describeModule$4$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LauncherHelper$$Lambda$lambda$describeModule$4$7::class$ = nullptr;

class LauncherHelper$$Lambda$lambda$describeModule$5$8 : public $Consumer {
	$class(LauncherHelper$$Lambda$lambda$describeModule$5$8, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* sourceAndMods) override {
		LauncherHelper::lambda$describeModule$5($cast($String, sourceAndMods));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LauncherHelper$$Lambda$lambda$describeModule$5$8>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LauncherHelper$$Lambda$lambda$describeModule$5$8::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LauncherHelper$$Lambda$lambda$describeModule$5$8, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(LauncherHelper$$Lambda$lambda$describeModule$5$8, accept, void, Object$*)},
	{}
};
$ClassInfo LauncherHelper$$Lambda$lambda$describeModule$5$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.launcher.LauncherHelper$$Lambda$lambda$describeModule$5$8",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* LauncherHelper$$Lambda$lambda$describeModule$5$8::load$($String* name, bool initialize) {
	$loadClass(LauncherHelper$$Lambda$lambda$describeModule$5$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LauncherHelper$$Lambda$lambda$describeModule$5$8::class$ = nullptr;

class LauncherHelper$$Lambda$descriptor$9 : public $Function {
	$class(LauncherHelper$$Lambda$descriptor$9, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($ModuleReference, inst$)->descriptor());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LauncherHelper$$Lambda$descriptor$9>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LauncherHelper$$Lambda$descriptor$9::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LauncherHelper$$Lambda$descriptor$9, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LauncherHelper$$Lambda$descriptor$9, apply, $Object*, Object$*)},
	{}
};
$ClassInfo LauncherHelper$$Lambda$descriptor$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.launcher.LauncherHelper$$Lambda$descriptor$9",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* LauncherHelper$$Lambda$descriptor$9::load$($String* name, bool initialize) {
	$loadClass(LauncherHelper$$Lambda$descriptor$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LauncherHelper$$Lambda$descriptor$9::class$ = nullptr;

class LauncherHelper$$Lambda$isAutomatic$10 : public $Predicate {
	$class(LauncherHelper$$Lambda$isAutomatic$10, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* inst$) override {
		 return $sure($ModuleDescriptor, inst$)->isAutomatic();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LauncherHelper$$Lambda$isAutomatic$10>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LauncherHelper$$Lambda$isAutomatic$10::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LauncherHelper$$Lambda$isAutomatic$10, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(LauncherHelper$$Lambda$isAutomatic$10, test, bool, Object$*)},
	{}
};
$ClassInfo LauncherHelper$$Lambda$isAutomatic$10::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.launcher.LauncherHelper$$Lambda$isAutomatic$10",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* LauncherHelper$$Lambda$isAutomatic$10::load$($String* name, bool initialize) {
	$loadClass(LauncherHelper$$Lambda$isAutomatic$10, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LauncherHelper$$Lambda$isAutomatic$10::class$ = nullptr;

class LauncherHelper$$Lambda$lambda$describeModule$6$11 : public $Consumer {
	$class(LauncherHelper$$Lambda$lambda$describeModule$6$11, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* any) override {
		LauncherHelper::lambda$describeModule$6($cast($ModuleDescriptor, any));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LauncherHelper$$Lambda$lambda$describeModule$6$11>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LauncherHelper$$Lambda$lambda$describeModule$6$11::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LauncherHelper$$Lambda$lambda$describeModule$6$11, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(LauncherHelper$$Lambda$lambda$describeModule$6$11, accept, void, Object$*)},
	{}
};
$ClassInfo LauncherHelper$$Lambda$lambda$describeModule$6$11::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.launcher.LauncherHelper$$Lambda$lambda$describeModule$6$11",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* LauncherHelper$$Lambda$lambda$describeModule$6$11::load$($String* name, bool initialize) {
	$loadClass(LauncherHelper$$Lambda$lambda$describeModule$6$11, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LauncherHelper$$Lambda$lambda$describeModule$6$11::class$ = nullptr;

class LauncherHelper$$Lambda$remove$12 : public $Consumer {
	$class(LauncherHelper$$Lambda$remove$12, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Set* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* o) override {
		$nc(inst$)->remove(o);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LauncherHelper$$Lambda$remove$12>());
	}
	$Set* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LauncherHelper$$Lambda$remove$12::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(LauncherHelper$$Lambda$remove$12, inst$)},
	{}
};
$MethodInfo LauncherHelper$$Lambda$remove$12::methodInfos[3] = {
	{"<init>", "(Ljava/util/Set;)V", nullptr, $PUBLIC, $method(LauncherHelper$$Lambda$remove$12, init$, void, $Set*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(LauncherHelper$$Lambda$remove$12, accept, void, Object$*)},
	{}
};
$ClassInfo LauncherHelper$$Lambda$remove$12::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.launcher.LauncherHelper$$Lambda$remove$12",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* LauncherHelper$$Lambda$remove$12::load$($String* name, bool initialize) {
	$loadClass(LauncherHelper$$Lambda$remove$12, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LauncherHelper$$Lambda$remove$12::class$ = nullptr;

class LauncherHelper$$Lambda$source$13 : public $Function {
	$class(LauncherHelper$$Lambda$source$13, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($ModuleDescriptor$Opens, inst$)->source());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LauncherHelper$$Lambda$source$13>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LauncherHelper$$Lambda$source$13::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LauncherHelper$$Lambda$source$13, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LauncherHelper$$Lambda$source$13, apply, $Object*, Object$*)},
	{}
};
$ClassInfo LauncherHelper$$Lambda$source$13::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.launcher.LauncherHelper$$Lambda$source$13",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* LauncherHelper$$Lambda$source$13::load$($String* name, bool initialize) {
	$loadClass(LauncherHelper$$Lambda$source$13, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LauncherHelper$$Lambda$source$13::class$ = nullptr;

class LauncherHelper$$Lambda$lambda$describeModule$7$14 : public $Consumer {
	$class(LauncherHelper$$Lambda$lambda$describeModule$7$14, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* p) override {
		LauncherHelper::lambda$describeModule$7($cast($String, p));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LauncherHelper$$Lambda$lambda$describeModule$7$14>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LauncherHelper$$Lambda$lambda$describeModule$7$14::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LauncherHelper$$Lambda$lambda$describeModule$7$14, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(LauncherHelper$$Lambda$lambda$describeModule$7$14, accept, void, Object$*)},
	{}
};
$ClassInfo LauncherHelper$$Lambda$lambda$describeModule$7$14::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.launcher.LauncherHelper$$Lambda$lambda$describeModule$7$14",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* LauncherHelper$$Lambda$lambda$describeModule$7$14::load$($String* name, bool initialize) {
	$loadClass(LauncherHelper$$Lambda$lambda$describeModule$7$14, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LauncherHelper$$Lambda$lambda$describeModule$7$14::class$ = nullptr;

class LauncherHelper$$Lambda$lambda$showModule$8$15 : public $Predicate {
	$class(LauncherHelper$$Lambda$lambda$showModule$8$15, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* uri) override {
		 return LauncherHelper::lambda$showModule$8($cast($URI, uri));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LauncherHelper$$Lambda$lambda$showModule$8$15>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LauncherHelper$$Lambda$lambda$showModule$8$15::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LauncherHelper$$Lambda$lambda$showModule$8$15, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(LauncherHelper$$Lambda$lambda$showModule$8$15, test, bool, Object$*)},
	{}
};
$ClassInfo LauncherHelper$$Lambda$lambda$showModule$8$15::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.launcher.LauncherHelper$$Lambda$lambda$showModule$8$15",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* LauncherHelper$$Lambda$lambda$showModule$8$15::load$($String* name, bool initialize) {
	$loadClass(LauncherHelper$$Lambda$lambda$showModule$8$15, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LauncherHelper$$Lambda$lambda$showModule$8$15::class$ = nullptr;

class LauncherHelper$$Lambda$lambda$showModule$9$16 : public $Consumer {
	$class(LauncherHelper$$Lambda$lambda$showModule$9$16, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* uri) override {
		LauncherHelper::lambda$showModule$9($cast($URI, uri));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LauncherHelper$$Lambda$lambda$showModule$9$16>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LauncherHelper$$Lambda$lambda$showModule$9$16::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LauncherHelper$$Lambda$lambda$showModule$9$16, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(LauncherHelper$$Lambda$lambda$showModule$9$16, accept, void, Object$*)},
	{}
};
$ClassInfo LauncherHelper$$Lambda$lambda$showModule$9$16::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.launcher.LauncherHelper$$Lambda$lambda$showModule$9$16",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* LauncherHelper$$Lambda$lambda$showModule$9$16::load$($String* name, bool initialize) {
	$loadClass(LauncherHelper$$Lambda$lambda$showModule$9$16, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LauncherHelper$$Lambda$lambda$showModule$9$16::class$ = nullptr;

class LauncherHelper$$Lambda$lambda$toStringStream$10$17 : public $Function {
	$class(LauncherHelper$$Lambda$lambda$toStringStream$10$17, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* e) override {
		 return $of(LauncherHelper::lambda$toStringStream$10(e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LauncherHelper$$Lambda$lambda$toStringStream$10$17>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LauncherHelper$$Lambda$lambda$toStringStream$10$17::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LauncherHelper$$Lambda$lambda$toStringStream$10$17, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LauncherHelper$$Lambda$lambda$toStringStream$10$17, apply, $Object*, Object$*)},
	{}
};
$ClassInfo LauncherHelper$$Lambda$lambda$toStringStream$10$17::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.launcher.LauncherHelper$$Lambda$lambda$toStringStream$10$17",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* LauncherHelper$$Lambda$lambda$toStringStream$10$17::load$($String* name, bool initialize) {
	$loadClass(LauncherHelper$$Lambda$lambda$toStringStream$10$17, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LauncherHelper$$Lambda$lambda$toStringStream$10$17::class$ = nullptr;

$FieldInfo _LauncherHelper_FieldInfo_[] = {
	{"JAVAFX_APPLICATION_MARKER", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LauncherHelper, JAVAFX_APPLICATION_MARKER)},
	{"JAVAFX_APPLICATION_CLASS_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LauncherHelper, JAVAFX_APPLICATION_CLASS_NAME)},
	{"JAVAFX_FXHELPER_CLASS_NAME_SUFFIX", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LauncherHelper, JAVAFX_FXHELPER_CLASS_NAME_SUFFIX)},
	{"LAUNCHER_AGENT_CLASS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LauncherHelper, LAUNCHER_AGENT_CLASS)},
	{"MAIN_CLASS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LauncherHelper, MAIN_CLASS)},
	{"ADD_EXPORTS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LauncherHelper, ADD_EXPORTS)},
	{"ADD_OPENS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LauncherHelper, ADD_OPENS)},
	{"outBuf", "Ljava/lang/StringBuilder;", nullptr, $PRIVATE | $STATIC, $staticField(LauncherHelper, outBuf)},
	{"INDENT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LauncherHelper, INDENT)},
	{"VM_SETTINGS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LauncherHelper, VM_SETTINGS)},
	{"PROP_SETTINGS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LauncherHelper, PROP_SETTINGS)},
	{"LOCALE_SETTINGS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LauncherHelper, LOCALE_SETTINGS)},
	{"diagprop", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LauncherHelper, diagprop)},
	{"trace", "Z", nullptr, $STATIC | $FINAL, $staticField(LauncherHelper, trace)},
	{"defaultBundleName", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LauncherHelper, defaultBundleName)},
	{"ostream", "Ljava/io/PrintStream;", nullptr, $PRIVATE | $STATIC, $staticField(LauncherHelper, ostream)},
	{"appClass", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $STATIC, $staticField(LauncherHelper, appClass)},
	{"LM_UNKNOWN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LauncherHelper, LM_UNKNOWN)},
	{"LM_CLASS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LauncherHelper, LM_CLASS)},
	{"LM_JAR", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LauncherHelper, LM_JAR)},
	{"LM_MODULE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LauncherHelper, LM_MODULE)},
	{"LM_SOURCE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LauncherHelper, LM_SOURCE)},
	{"encprop", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LauncherHelper, encprop)},
	{"encoding", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(LauncherHelper, encoding)},
	{"isCharsetSupported", "Z", nullptr, $PRIVATE | $STATIC, $staticField(LauncherHelper, isCharsetSupported)},
	{}
};

$MethodInfo _LauncherHelper_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(LauncherHelper, init$, void)},
	{"abort", "(Ljava/lang/Throwable;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $STATIC | $TRANSIENT, $staticMethod(LauncherHelper, abort, void, $Throwable*, $String*, $ObjectArray*)},
	{"addExportsOrOpens", "(Ljava/lang/String;Z)V", nullptr, $STATIC, $staticMethod(LauncherHelper, addExportsOrOpens, void, $String*, bool)},
	{"appendVmSelectMessage", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(LauncherHelper, appendVmSelectMessage, void, $String*, $String*)},
	{"appendVmSynonymMessage", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(LauncherHelper, appendVmSynonymMessage, void, $String*, $String*)},
	{"checkAndLoadMain", "(ZILjava/lang/String;)Ljava/lang/Class;", "(ZILjava/lang/String;)Ljava/lang/Class<*>;", $PUBLIC | $STATIC, $staticMethod(LauncherHelper, checkAndLoadMain, $Class*, bool, int32_t, $String*)},
	{"describeModule", "(Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(LauncherHelper, describeModule, void, $String*)},
	{"doesExtendFXApplication", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC, $staticMethod(LauncherHelper, doesExtendFXApplication, bool, $Class*)},
	{"expandArgs", "([Ljava/lang/String;)[Ljava/lang/String;", nullptr, $STATIC, $staticMethod(LauncherHelper, expandArgs, $StringArray*, $StringArray*)},
	{"expandArgs", "(Ljava/util/List;)[Ljava/lang/String;", "(Ljava/util/List<Lsun/launcher/LauncherHelper$StdArg;>;)[Ljava/lang/String;", $STATIC, $staticMethod(LauncherHelper, expandArgs, $StringArray*, $List*)},
	{"formatCpuVal", "(JLjava/lang/String;J)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(LauncherHelper, formatCpuVal, $String*, int64_t, $String*, int64_t)},
	{"formatLimitString", "(JLjava/lang/String;J)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(LauncherHelper, formatLimitString, $String*, int64_t, $String*, int64_t)},
	{"getApplicationClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PUBLIC | $STATIC, $staticMethod(LauncherHelper, getApplicationClass, $Class*)},
	{"getLocalizedMessage", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(LauncherHelper, getLocalizedMessage, $String*, $String*, $ObjectArray*)},
	{"getMainClassFromJar", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(LauncherHelper, getMainClassFromJar, $String*, $String*)},
	{"initHelpMessage", "(Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(LauncherHelper, initHelpMessage, void, $String*)},
	{"initOutput", "(Z)V", nullptr, $STATIC, $staticMethod(LauncherHelper, initOutput, void, bool)},
	{"initOutput", "(Ljava/io/PrintStream;)V", nullptr, $STATIC, $staticMethod(LauncherHelper, initOutput, void, $PrintStream*)},
	{"isJrt", "(Ljava/lang/module/ModuleReference;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(LauncherHelper, isJrt, bool, $ModuleReference*)},
	{"isJrt", "(Ljava/net/URI;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(LauncherHelper, isJrt, bool, $URI*)},
	{"isPath", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(LauncherHelper, isPath, bool, $String*)},
	{"lambda$addExportsOrOpens$1", "(Ljava/lang/String;Ljava/lang/Module;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LauncherHelper, lambda$addExportsOrOpens$1, bool, $String*, $Module*)},
	{"lambda$addExportsOrOpens$2", "(ZLjava/lang/String;Ljava/lang/Module;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LauncherHelper, lambda$addExportsOrOpens$2, void, bool, $String*, $Module*)},
	{"lambda$describeModule$3", "(Ljava/lang/module/ModuleDescriptor$Exports;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LauncherHelper, lambda$describeModule$3, bool, $ModuleDescriptor$Exports*)},
	{"lambda$describeModule$4", "(Ljava/lang/module/ModuleDescriptor$Exports;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LauncherHelper, lambda$describeModule$4, $String*, $ModuleDescriptor$Exports*)},
	{"lambda$describeModule$5", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LauncherHelper, lambda$describeModule$5, void, $String*)},
	{"lambda$describeModule$6", "(Ljava/lang/module/ModuleDescriptor;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LauncherHelper, lambda$describeModule$6, void, $ModuleDescriptor*)},
	{"lambda$describeModule$7", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LauncherHelper, lambda$describeModule$7, void, $String*)},
	{"lambda$getMainClassFromJar$0", "(Ljava/lang/String;Ljava/lang/Module;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LauncherHelper, lambda$getMainClassFromJar$0, void, $String*, $Module*)},
	{"lambda$showModule$8", "(Ljava/net/URI;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LauncherHelper, lambda$showModule$8, bool, $URI*)},
	{"lambda$showModule$9", "(Ljava/net/URI;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LauncherHelper, lambda$showModule$9, void, $URI*)},
	{"lambda$toStringStream$10", "(Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LauncherHelper, lambda$toStringStream$10, $String*, Object$*)},
	{"listModules", "()V", nullptr, $STATIC, $staticMethod(LauncherHelper, listModules, void)},
	{"loadMainClass", "(ILjava/lang/String;)Ljava/lang/Class;", "(ILjava/lang/String;)Ljava/lang/Class<*>;", $PRIVATE | $STATIC, $staticMethod(LauncherHelper, loadMainClass, $Class*, int32_t, $String*)},
	{"loadModuleMainClass", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PRIVATE | $STATIC, $staticMethod(LauncherHelper, loadModuleMainClass, $Class*, $String*)},
	{"makePlatformString", "(Z[B)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(LauncherHelper, makePlatformString, $String*, bool, $bytes*)},
	{"printHelpMessage", "(Z)V", nullptr, $STATIC, $staticMethod(LauncherHelper, printHelpMessage, void, bool)},
	{"printLocale", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(LauncherHelper, printLocale, void)},
	{"printLocales", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(LauncherHelper, printLocales, void)},
	{"printProperties", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(LauncherHelper, printProperties, void)},
	{"printPropertyValue", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(LauncherHelper, printPropertyValue, void, $String*, $String*)},
	{"printSystemMetrics", "()V", nullptr, $PUBLIC | $STATIC, $staticMethod(LauncherHelper, printSystemMetrics, void)},
	{"printVmSettings", "(JJJ)V", nullptr, $PRIVATE | $STATIC, $staticMethod(LauncherHelper, printVmSettings, void, int64_t, int64_t, int64_t)},
	{"printXUsageMessage", "(Z)V", nullptr, $STATIC, $staticMethod(LauncherHelper, printXUsageMessage, void, bool)},
	{"showModule", "(Ljava/lang/module/ModuleReference;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(LauncherHelper, showModule, void, $ModuleReference*)},
	{"showResolvedModules", "()V", nullptr, $STATIC, $staticMethod(LauncherHelper, showResolvedModules, void)},
	{"showSettings", "(ZLjava/lang/String;JJJ)V", nullptr, $STATIC, $staticMethod(LauncherHelper, showSettings, void, bool, $String*, int64_t, int64_t, int64_t)},
	{"toStringStream", "(Ljava/util/Set;)Ljava/util/stream/Stream;", "<T:Ljava/lang/Object;>(Ljava/util/Set<TT;>;)Ljava/util/stream/Stream<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(LauncherHelper, toStringStream, $Stream*, $Set*)},
	{"validateMainClass", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;)V", $STATIC, $staticMethod(LauncherHelper, validateMainClass, void, $Class*)},
	{}
};

$InnerClassInfo _LauncherHelper_InnerClassesInfo_[] = {
	{"sun.launcher.LauncherHelper$JrtFirstComparator", "sun.launcher.LauncherHelper", "JrtFirstComparator", $PRIVATE | $STATIC},
	{"sun.launcher.LauncherHelper$FXHelper", "sun.launcher.LauncherHelper", "FXHelper", $STATIC | $FINAL},
	{"sun.launcher.LauncherHelper$StdArg", "sun.launcher.LauncherHelper", "StdArg", $PRIVATE | $STATIC},
	{"sun.launcher.LauncherHelper$SizePrefix", "sun.launcher.LauncherHelper", "SizePrefix", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{"sun.launcher.LauncherHelper$ResourceBundleHolder", "sun.launcher.LauncherHelper", "ResourceBundleHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _LauncherHelper_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.launcher.LauncherHelper",
	"java.lang.Object",
	nullptr,
	_LauncherHelper_FieldInfo_,
	_LauncherHelper_MethodInfo_,
	nullptr,
	nullptr,
	_LauncherHelper_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.launcher.LauncherHelper$JrtFirstComparator,sun.launcher.LauncherHelper$FXHelper,sun.launcher.LauncherHelper$StdArg,sun.launcher.LauncherHelper$SizePrefix,sun.launcher.LauncherHelper$ResourceBundleHolder"
};

$Object* allocate$LauncherHelper($Class* clazz) {
	return $of($alloc(LauncherHelper));
}

$String* LauncherHelper::JAVAFX_APPLICATION_MARKER = nullptr;
$String* LauncherHelper::JAVAFX_APPLICATION_CLASS_NAME = nullptr;
$String* LauncherHelper::JAVAFX_FXHELPER_CLASS_NAME_SUFFIX = nullptr;
$String* LauncherHelper::LAUNCHER_AGENT_CLASS = nullptr;
$String* LauncherHelper::MAIN_CLASS = nullptr;
$String* LauncherHelper::ADD_EXPORTS = nullptr;
$String* LauncherHelper::ADD_OPENS = nullptr;
$StringBuilder* LauncherHelper::outBuf = nullptr;
$String* LauncherHelper::INDENT = nullptr;
$String* LauncherHelper::VM_SETTINGS = nullptr;
$String* LauncherHelper::PROP_SETTINGS = nullptr;
$String* LauncherHelper::LOCALE_SETTINGS = nullptr;
$String* LauncherHelper::diagprop = nullptr;
bool LauncherHelper::trace = false;
$String* LauncherHelper::defaultBundleName = nullptr;
$PrintStream* LauncherHelper::ostream = nullptr;
$Class* LauncherHelper::appClass = nullptr;
$String* LauncherHelper::encprop = nullptr;
$String* LauncherHelper::encoding = nullptr;
bool LauncherHelper::isCharsetSupported = false;

void LauncherHelper::init$() {
}

void LauncherHelper::showSettings(bool printToStderr, $String* optionFlag, int64_t initialHeapSize, int64_t maxHeapSize, int64_t stackSize) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	initOutput(printToStderr);
	$var($StringArray, opts, $nc(optionFlag)->split(":"_s));
	$var($String, optStr, (opts->length > 1 && opts->get(1) != nullptr) ? $nc(opts->get(1))->trim() : "all"_s);
	{
		$var($String, s6317$, optStr);
		int32_t tmp6317$ = -1;
		switch ($nc(s6317$)->hashCode()) {
		case 3767:
			{
				if (s6317$->equals("vm"_s)) {
					tmp6317$ = 0;
				}
				break;
			}
		case (int32_t)0xC8CD8D33:
			{
				if (s6317$->equals("properties"_s)) {
					tmp6317$ = 1;
				}
				break;
			}
		case (int32_t)0xBE960E5A:
			{
				if (s6317$->equals("locale"_s)) {
					tmp6317$ = 2;
				}
				break;
			}
		case (int32_t)0xCB1C722F:
			{
				if (s6317$->equals("system"_s)) {
					tmp6317$ = 3;
				}
				break;
			}
		}
		switch (tmp6317$) {
		case 0:
			{
				printVmSettings(initialHeapSize, maxHeapSize, stackSize);
				break;
			}
		case 1:
			{
				printProperties();
				break;
			}
		case 2:
			{
				printLocale();
				break;
			}
		case 3:
			{
				if ($nc($($System::getProperty("os.name"_s)))->contains("Linux"_s)) {
					printSystemMetrics();
					break;
				}
			}
		default:
			{
				printVmSettings(initialHeapSize, maxHeapSize, stackSize);
				printProperties();
				printLocale();
				if ($nc($($System::getProperty("os.name"_s)))->contains("Linux"_s)) {
					printSystemMetrics();
				}
				break;
			}
		}
	}
}

void LauncherHelper::printVmSettings(int64_t initialHeapSize, int64_t maxHeapSize, int64_t stackSize) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	$nc(LauncherHelper::ostream)->println(LauncherHelper::VM_SETTINGS);
	if (stackSize != (int64_t)0) {
		$nc(LauncherHelper::ostream)->println($$str({LauncherHelper::INDENT, "Stack Size: "_s, $($LauncherHelper$SizePrefix::scaleValue(stackSize))}));
	}
	if (initialHeapSize != (int64_t)0) {
		$nc(LauncherHelper::ostream)->println($$str({LauncherHelper::INDENT, "Min. Heap Size: "_s, $($LauncherHelper$SizePrefix::scaleValue(initialHeapSize))}));
	}
	if (maxHeapSize != (int64_t)0) {
		$nc(LauncherHelper::ostream)->println($$str({LauncherHelper::INDENT, "Max. Heap Size: "_s, $($LauncherHelper$SizePrefix::scaleValue(maxHeapSize))}));
	} else {
		$nc(LauncherHelper::ostream)->println($$str({LauncherHelper::INDENT, "Max. Heap Size (Estimated): "_s, $($LauncherHelper$SizePrefix::scaleValue($nc($($Runtime::getRuntime()))->maxMemory()))}));
	}
	$nc(LauncherHelper::ostream)->println($$str({LauncherHelper::INDENT, "Using VM: "_s, $($System::getProperty("java.vm.name"_s))}));
	$nc(LauncherHelper::ostream)->println();
}

void LauncherHelper::printProperties() {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	$var($Properties, p, $System::getProperties());
	$nc(LauncherHelper::ostream)->println(LauncherHelper::PROP_SETTINGS);
	$var($List, sortedPropertyKeys, $new($ArrayList));
	sortedPropertyKeys->addAll($($nc(p)->stringPropertyNames()));
	$Collections::sort(sortedPropertyKeys);
	{
		$var($Iterator, i$, sortedPropertyKeys->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, x, $cast($String, i$->next()));
			{
				printPropertyValue(x, $($nc(p)->getProperty(x)));
			}
		}
	}
	$nc(LauncherHelper::ostream)->println();
}

bool LauncherHelper::isPath($String* key) {
	$init(LauncherHelper);
	bool var$0 = $nc(key)->endsWith(".dirs"_s);
	return var$0 || $nc(key)->endsWith(".path"_s);
}

void LauncherHelper::printPropertyValue($String* key, $String* value) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	$nc(LauncherHelper::ostream)->print($$str({LauncherHelper::INDENT, key, " = "_s}));
	if ($nc(key)->equals("line.separator"_s)) {
		{
			$var($bytes, arr$, $nc(value)->getBytes());
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				int8_t b = arr$->get(i$);
				{
					switch (b) {
					case 13:
						{
							$nc(LauncherHelper::ostream)->print("\\r "_s);
							break;
						}
					case 10:
						{
							$nc(LauncherHelper::ostream)->print("\\n "_s);
							break;
						}
					default:
						{
							$nc(LauncherHelper::ostream)->printf("0x%02X"_s, $$new($ObjectArray, {$($of($Integer::valueOf((int32_t)(b & (uint32_t)255))))}));
							break;
						}
					}
				}
			}
		}
		$nc(LauncherHelper::ostream)->println();
		return;
	}
	if (!isPath(key)) {
		$nc(LauncherHelper::ostream)->println(value);
		return;
	}
	$var($StringArray, values, $nc(value)->split($($System::getProperty("path.separator"_s))));
	bool first = true;
	{
		$var($StringArray, arr$, values);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, s, arr$->get(i$));
			{
				if (first) {
					$nc(LauncherHelper::ostream)->println(s);
					first = false;
				} else {
					$nc(LauncherHelper::ostream)->println($$str({LauncherHelper::INDENT, LauncherHelper::INDENT, s}));
				}
			}
		}
	}
}

void LauncherHelper::printLocale() {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	$var($Locale, locale, $Locale::getDefault());
	$nc(LauncherHelper::ostream)->println(LauncherHelper::LOCALE_SETTINGS);
	$nc(LauncherHelper::ostream)->println($$str({LauncherHelper::INDENT, "default locale = "_s, $($nc(locale)->getDisplayName())}));
	$init($Locale$Category);
	$nc(LauncherHelper::ostream)->println($$str({LauncherHelper::INDENT, "default display locale = "_s, $($nc($($Locale::getDefault($Locale$Category::DISPLAY)))->getDisplayName())}));
	$nc(LauncherHelper::ostream)->println($$str({LauncherHelper::INDENT, "default format locale = "_s, $($nc($($Locale::getDefault($Locale$Category::FORMAT)))->getDisplayName())}));
	printLocales();
	$nc(LauncherHelper::ostream)->println();
}

void LauncherHelper::printLocales() {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	$var($LocaleArray, tlocales, $Locale::getAvailableLocales());
	int32_t len = tlocales == nullptr ? 0 : $nc(tlocales)->length;
	if (len < 1) {
		return;
	}
	$var($Set, sortedSet, static_cast<$Set*>(static_cast<$AbstractSet*>($new($TreeSet))));
	{
		$var($LocaleArray, arr$, tlocales);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Locale, l, arr$->get(i$));
			{
				sortedSet->add($($nc(l)->toString()));
			}
		}
	}
	$nc(LauncherHelper::ostream)->print($$str({LauncherHelper::INDENT, "available locales = "_s}));
	$var($Iterator, iter, sortedSet->iterator());
	int32_t last = len - 1;
	for (int32_t i = 0; $nc(iter)->hasNext(); ++i) {
		$var($String, s, $cast($String, iter->next()));
		$nc(LauncherHelper::ostream)->print(s);
		if (i != last) {
			$nc(LauncherHelper::ostream)->print(", "_s);
		}
		if ((i + 1) % 8 == 0) {
			$nc(LauncherHelper::ostream)->println();
			$nc(LauncherHelper::ostream)->print($$str({LauncherHelper::INDENT, LauncherHelper::INDENT}));
		}
	}
}

void LauncherHelper::printSystemMetrics() {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	$var($Metrics, c, $Container::metrics());
	$nc(LauncherHelper::ostream)->println("Operating System Metrics:"_s);
	if (c == nullptr) {
		$nc(LauncherHelper::ostream)->println($$str({LauncherHelper::INDENT, "No metrics available for this platform"_s}));
		return;
	}
	int64_t longRetvalNotSupported = -2;
	$nc(LauncherHelper::ostream)->println($$str({LauncherHelper::INDENT, "Provider: "_s, $($nc(c)->getProvider())}));
	$nc(LauncherHelper::ostream)->println($$str({LauncherHelper::INDENT, "Effective CPU Count: "_s, $$str($nc(c)->getEffectiveCpuCount())}));
	$nc(LauncherHelper::ostream)->println($(formatCpuVal($nc(c)->getCpuPeriod(), $$str({LauncherHelper::INDENT, "CPU Period: "_s}), longRetvalNotSupported)));
	$nc(LauncherHelper::ostream)->println($(formatCpuVal($nc(c)->getCpuQuota(), $$str({LauncherHelper::INDENT, "CPU Quota: "_s}), longRetvalNotSupported)));
	$nc(LauncherHelper::ostream)->println($(formatCpuVal($nc(c)->getCpuShares(), $$str({LauncherHelper::INDENT, "CPU Shares: "_s}), longRetvalNotSupported)));
	$var($ints, cpus, $nc(c)->getCpuSetCpus());
	if (cpus != nullptr) {
		$nc(LauncherHelper::ostream)->println($$str({LauncherHelper::INDENT, "List of Processors, "_s, $$str(cpus->length), " total: "_s}));
		$nc(LauncherHelper::ostream)->print(LauncherHelper::INDENT);
		for (int32_t i = 0; i < cpus->length; ++i) {
			$nc(LauncherHelper::ostream)->print($$str({$$str(cpus->get(i)), " "_s}));
		}
		if (cpus->length > 0) {
			$nc(LauncherHelper::ostream)->println(""_s);
		}
	} else {
		$nc(LauncherHelper::ostream)->println($$str({LauncherHelper::INDENT, "List of Processors: N/A"_s}));
	}
	$assign(cpus, c->getEffectiveCpuSetCpus());
	if (cpus != nullptr) {
		$nc(LauncherHelper::ostream)->println($$str({LauncherHelper::INDENT, "List of Effective Processors, "_s, $$str(cpus->length), " total: "_s}));
		$nc(LauncherHelper::ostream)->print(LauncherHelper::INDENT);
		for (int32_t i = 0; i < cpus->length; ++i) {
			$nc(LauncherHelper::ostream)->print($$str({$$str(cpus->get(i)), " "_s}));
		}
		if (cpus->length > 0) {
			$nc(LauncherHelper::ostream)->println(""_s);
		}
	} else {
		$nc(LauncherHelper::ostream)->println($$str({LauncherHelper::INDENT, "List of Effective Processors: N/A"_s}));
	}
	$var($ints, mems, c->getCpuSetMems());
	if (mems != nullptr) {
		$nc(LauncherHelper::ostream)->println($$str({LauncherHelper::INDENT, "List of Memory Nodes, "_s, $$str(mems->length), " total: "_s}));
		$nc(LauncherHelper::ostream)->print(LauncherHelper::INDENT);
		for (int32_t i = 0; i < mems->length; ++i) {
			$nc(LauncherHelper::ostream)->print($$str({$$str(mems->get(i)), " "_s}));
		}
		if (mems->length > 0) {
			$nc(LauncherHelper::ostream)->println(""_s);
		}
	} else {
		$nc(LauncherHelper::ostream)->println($$str({LauncherHelper::INDENT, "List of Memory Nodes: N/A"_s}));
	}
	$assign(mems, c->getEffectiveCpuSetMems());
	if (mems != nullptr) {
		$nc(LauncherHelper::ostream)->println($$str({LauncherHelper::INDENT, "List of Available Memory Nodes, "_s, $$str(mems->length), " total: "_s}));
		$nc(LauncherHelper::ostream)->print(LauncherHelper::INDENT);
		for (int32_t i = 0; i < mems->length; ++i) {
			$nc(LauncherHelper::ostream)->print($$str({$$str(mems->get(i)), " "_s}));
		}
		if (mems->length > 0) {
			$nc(LauncherHelper::ostream)->println(""_s);
		}
	} else {
		$nc(LauncherHelper::ostream)->println($$str({LauncherHelper::INDENT, "List of Available Memory Nodes: N/A"_s}));
	}
	int64_t limit = c->getMemoryLimit();
	$nc(LauncherHelper::ostream)->println($(formatLimitString(limit, $$str({LauncherHelper::INDENT, "Memory Limit: "_s}), longRetvalNotSupported)));
	limit = c->getMemorySoftLimit();
	$nc(LauncherHelper::ostream)->println($(formatLimitString(limit, $$str({LauncherHelper::INDENT, "Memory Soft Limit: "_s}), longRetvalNotSupported)));
	limit = c->getMemoryAndSwapLimit();
	$nc(LauncherHelper::ostream)->println($(formatLimitString(limit, $$str({LauncherHelper::INDENT, "Memory & Swap Limit: "_s}), longRetvalNotSupported)));
	$nc(LauncherHelper::ostream)->println(""_s);
}

$String* LauncherHelper::formatLimitString(int64_t limit, $String* prefix, int64_t unavailable) {
	$init(LauncherHelper);
	if (limit >= 0) {
		return $str({prefix, $($LauncherHelper$SizePrefix::scaleValue(limit))});
	} else if (limit == unavailable) {
		return $str({prefix, "N/A"_s});
	} else {
		return $str({prefix, "Unlimited"_s});
	}
}

$String* LauncherHelper::formatCpuVal(int64_t cpuVal, $String* prefix, int64_t unavailable) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	if (cpuVal >= 0) {
		return $str({prefix, $$str(cpuVal), "us"_s});
	} else if (cpuVal == unavailable) {
		return $str({prefix, "N/A"_s});
	} else {
		return $str({prefix, $$str(cpuVal)});
	}
}

$String* LauncherHelper::getLocalizedMessage($String* key, $ObjectArray* args) {
	$init(LauncherHelper);
	$init($LauncherHelper$ResourceBundleHolder);
	$var($String, msg, $nc($LauncherHelper$ResourceBundleHolder::RB)->getString(key));
	return (args != nullptr) ? $MessageFormat::format(msg, args) : msg;
}

void LauncherHelper::initHelpMessage($String* progname) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	$assignStatic(LauncherHelper::outBuf, $nc(LauncherHelper::outBuf)->append($(getLocalizedMessage("java.launcher.opt.header"_s, $$new($ObjectArray, {(progname == nullptr) ? $of("java"_s) : $of(progname)})))));
}

void LauncherHelper::appendVmSelectMessage($String* vm1, $String* vm2) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	$assignStatic(LauncherHelper::outBuf, $nc(LauncherHelper::outBuf)->append($(getLocalizedMessage("java.launcher.opt.vmselect"_s, $$new($ObjectArray, {
		$of(vm1),
		$of(vm2)
	})))));
}

void LauncherHelper::appendVmSynonymMessage($String* vm1, $String* vm2) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	$assignStatic(LauncherHelper::outBuf, $nc(LauncherHelper::outBuf)->append($(getLocalizedMessage("java.launcher.opt.hotspot"_s, $$new($ObjectArray, {
		$of(vm1),
		$of(vm2)
	})))));
}

void LauncherHelper::printHelpMessage(bool printToStderr) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	initOutput(printToStderr);
	$init($File);
	$assignStatic(LauncherHelper::outBuf, $nc(LauncherHelper::outBuf)->append($(getLocalizedMessage("java.launcher.opt.footer"_s, $$new($ObjectArray, {$of($File::pathSeparator)})))));
	$nc(LauncherHelper::ostream)->println($($nc(LauncherHelper::outBuf)->toString()));
}

void LauncherHelper::printXUsageMessage(bool printToStderr) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	initOutput(printToStderr);
	$init($File);
	$nc(LauncherHelper::ostream)->println($(getLocalizedMessage("java.launcher.X.usage"_s, $$new($ObjectArray, {$of($File::pathSeparator)}))));
	if ($nc($($System::getProperty("os.name"_s)))->contains("OS X"_s)) {
		$nc(LauncherHelper::ostream)->println($(getLocalizedMessage("java.launcher.X.macosx.usage"_s, $$new($ObjectArray, {$of($File::pathSeparator)}))));
	}
}

void LauncherHelper::initOutput(bool printToStderr) {
	$init(LauncherHelper);
	$assignStatic(LauncherHelper::ostream, (printToStderr) ? $System::err : $System::out);
}

void LauncherHelper::initOutput($PrintStream* ps) {
	$init(LauncherHelper);
	$assignStatic(LauncherHelper::ostream, ps);
}

$String* LauncherHelper::getMainClassFromJar($String* jarname) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	$var($String, mainValue, nullptr);
	try {
		$var($JarFile, jarFile, $new($JarFile, jarname));
		{
			$var($Throwable, var$0, nullptr);
			$var($String, var$2, nullptr);
			bool return$1 = false;
			try {
				try {
					$var($Manifest, manifest, jarFile->getManifest());
					if (manifest == nullptr) {
						abort(nullptr, "java.launcher.jar.error2"_s, $$new($ObjectArray, {$of(jarname)}));
					}
					$var($Attributes, mainAttrs, $nc(manifest)->getMainAttributes());
					if (mainAttrs == nullptr) {
						abort(nullptr, "java.launcher.jar.error3"_s, $$new($ObjectArray, {$of(jarname)}));
					}
					$assign(mainValue, $nc(mainAttrs)->getValue(LauncherHelper::MAIN_CLASS));
					if (mainValue == nullptr) {
						abort(nullptr, "java.launcher.jar.error3"_s, $$new($ObjectArray, {$of(jarname)}));
					}
					$var($String, agentClass, mainAttrs->getValue(LauncherHelper::LAUNCHER_AGENT_CLASS));
					if (agentClass != nullptr) {
						$nc($($nc($($ModuleLayer::boot()))->findModule("java.instrument"_s)))->ifPresent(static_cast<$Consumer*>($$new(LauncherHelper$$Lambda$lambda$getMainClassFromJar$0, jarname)));
					}
					$var($String, exports, mainAttrs->getValue(LauncherHelper::ADD_EXPORTS));
					if (exports != nullptr) {
						addExportsOrOpens(exports, false);
					}
					$var($String, opens, mainAttrs->getValue(LauncherHelper::ADD_OPENS));
					if (opens != nullptr) {
						addExportsOrOpens(opens, true);
					}
					if (mainAttrs->containsKey($$new($Attributes$Name, LauncherHelper::JAVAFX_APPLICATION_MARKER))) {
						$LauncherHelper$FXHelper::setFXLaunchParameters(jarname, LauncherHelper::LM_JAR);
						$assign(var$2, $LauncherHelper$FXHelper::class$->getName());
						return$1 = true;
						goto $finally;
					}
					$assign(var$2, $nc(mainValue)->trim());
					return$1 = true;
					goto $finally;
				} catch ($Throwable& t$) {
					try {
						jarFile->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				jarFile->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	} catch ($IOException& ioe) {
		abort(ioe, "java.launcher.jar.error1"_s, $$new($ObjectArray, {$of(jarname)}));
	}
	return nullptr;
}

void LauncherHelper::addExportsOrOpens($String* value, bool open) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	{
		$var($StringArray, arr$, $nc(value)->split(" "_s));
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, moduleAndPackage, arr$->get(i$));
			{
				$var($StringArray, s, $($nc(moduleAndPackage)->trim())->split("/"_s));
				if (s->length == 2) {
					$var($String, mn, s->get(0));
					$var($String, pn, s->get(1));
					$nc($($nc($($nc($($ModuleLayer::boot()))->findModule(mn)))->filter(static_cast<$Predicate*>($$new(LauncherHelper$$Lambda$lambda$addExportsOrOpens$1$1, pn)))))->ifPresent(static_cast<$Consumer*>($$new(LauncherHelper$$Lambda$lambda$addExportsOrOpens$2$2, open, pn)));
				}
			}
		}
	}
}

void LauncherHelper::abort($Throwable* t, $String* msgKey, $ObjectArray* args) {
	$init(LauncherHelper);
	if (msgKey != nullptr) {
		$nc(LauncherHelper::ostream)->println($(getLocalizedMessage(msgKey, args)));
	}
	if (LauncherHelper::trace) {
		if (t != nullptr) {
			t->printStackTrace();
		} else {
			$Thread::dumpStack();
		}
	}
	$System::exit(1);
}

$Class* LauncherHelper::checkAndLoadMain(bool printToStderr, int32_t mode, $String* what) {
	$init(LauncherHelper);
	initOutput(printToStderr);
	$Class* mainClass = nullptr;
	switch (mode) {
	case LauncherHelper::LM_MODULE:
		{}
	case LauncherHelper::LM_SOURCE:
		{
			mainClass = loadModuleMainClass(what);
			break;
		}
	default:
		{
			mainClass = loadMainClass(mode, what);
			break;
		}
	}
	$assignStatic(LauncherHelper::appClass, mainClass);
	bool var$0 = $nc(LauncherHelper::JAVAFX_FXHELPER_CLASS_NAME_SUFFIX)->equals($($nc(mainClass)->getName()));
	if (var$0 || doesExtendFXApplication(mainClass)) {
		$LauncherHelper$FXHelper::setFXLaunchParameters(what, mode);
		mainClass = $LauncherHelper$FXHelper::class$;
	}
	validateMainClass(mainClass);
	return mainClass;
}

$Class* LauncherHelper::loadModuleMainClass($String* what) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	int32_t i = $nc(what)->indexOf((int32_t)u'/');
	$var($String, mainModule, nullptr);
	$var($String, mainClass, nullptr);
	if (i == -1) {
		$assign(mainModule, what);
		$assign(mainClass, nullptr);
	} else {
		$assign(mainModule, what->substring(0, i));
		$assign(mainClass, what->substring(i + 1));
	}
	$var($ModuleLayer, layer, $ModuleLayer::boot());
	$var($Optional, om, $nc(layer)->findModule(mainModule));
	if (!$nc(om)->isPresent()) {
		$throwNew($InternalError, $$str({"Module "_s, mainModule, " not in boot Layer"_s}));
	}
	$var($Module, m, $cast($Module, $nc(om)->get()));
	if (mainClass == nullptr) {
		$var($Optional, omc, $nc($($nc(m)->getDescriptor()))->mainClass());
		if (!$nc(omc)->isPresent()) {
			abort(nullptr, "java.launcher.module.error1"_s, $$new($ObjectArray, {$of(mainModule)}));
		}
		$assign(mainClass, $cast($String, $nc(omc)->get()));
	}
	$Class* c = nullptr;
	try {
		c = $Class::forName(m, mainClass);
		bool var$0 = c == nullptr && $nc($($System::getProperty("os.name"_s, ""_s)))->contains("OS X"_s);
		$init($Normalizer$Form);
		if (var$0 && $Normalizer::isNormalized(mainClass, $Normalizer$Form::NFD)) {
			$var($String, cn, $Normalizer::normalize(mainClass, $Normalizer$Form::NFC));
			c = $Class::forName(m, cn);
		}
	} catch ($LinkageError& le) {
		$var($String, var$1, $$str({$($of(le)->getClass()->getName()), ": "_s}));
		abort(nullptr, "java.launcher.module.error3"_s, $$new($ObjectArray, {
			$of(mainClass),
			$($of($nc(m)->getName())),
			$of(($$concat(var$1, $(le->getLocalizedMessage()))))
		}));
	}
	if (c == nullptr) {
		abort(nullptr, "java.launcher.module.error2"_s, $$new($ObjectArray, {
			$of(mainClass),
			$of(mainModule)
		}));
	}
	$System::setProperty("jdk.module.main.class"_s, $($nc(c)->getName()));
	return c;
}

$Class* LauncherHelper::loadMainClass(int32_t mode, $String* what) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, cn, nullptr);
	switch (mode) {
	case LauncherHelper::LM_CLASS:
		{
			$assign(cn, what);
			break;
		}
	case LauncherHelper::LM_JAR:
		{
			$assign(cn, getMainClassFromJar(what));
			break;
		}
	default:
		{
			$throwNew($InternalError, $$str({""_s, $$str(mode), ": Unknown launch mode"_s}));
		}
	}
	$assign(cn, $nc(cn)->replace(u'/', u'.'));
	$Class* mainClass = nullptr;
	$var($ClassLoader, scl, $ClassLoader::getSystemClassLoader());
	try {
		try {
			mainClass = $Class::forName(cn, false, scl);
		} catch ($NoClassDefFoundError& cnfe) {
			bool var$0 = $nc($($System::getProperty("os.name"_s, ""_s)))->contains("OS X"_s);
			$init($Normalizer$Form);
			if (var$0 && $Normalizer::isNormalized(cn, $Normalizer$Form::NFD)) {
				try {
					$var($String, ncn, $Normalizer::normalize(cn, $Normalizer$Form::NFC));
					mainClass = $Class::forName(ncn, false, scl);
				} catch ($NoClassDefFoundError& cnfe1) {
					abort(cnfe1, "java.launcher.cls.error1"_s, $$new($ObjectArray, {
						$of(cn),
						$($of($of(cnfe1)->getClass()->getCanonicalName())),
						$($of(cnfe1->getMessage()))
					}));
				} catch ($ClassNotFoundException& cnfe1) {
					abort(cnfe1, "java.launcher.cls.error1"_s, $$new($ObjectArray, {
						$of(cn),
						$($of($of(cnfe1)->getClass()->getCanonicalName())),
						$($of(cnfe1->getMessage()))
					}));
				}
			} else {
				abort(cnfe, "java.launcher.cls.error1"_s, $$new($ObjectArray, {
					$of(cn),
					$($of($of(cnfe)->getClass()->getCanonicalName())),
					$($of(cnfe->getMessage()))
				}));
			}
		} catch ($ClassNotFoundException& cnfe) {
			bool var$1 = $nc($($System::getProperty("os.name"_s, ""_s)))->contains("OS X"_s);
			$init($Normalizer$Form);
			if (var$1 && $Normalizer::isNormalized(cn, $Normalizer$Form::NFD)) {
				try {
					$var($String, ncn, $Normalizer::normalize(cn, $Normalizer$Form::NFC));
					mainClass = $Class::forName(ncn, false, scl);
				} catch ($NoClassDefFoundError& cnfe1) {
					abort(cnfe1, "java.launcher.cls.error1"_s, $$new($ObjectArray, {
						$of(cn),
						$($of($of(cnfe1)->getClass()->getCanonicalName())),
						$($of(cnfe1->getMessage()))
					}));
				} catch ($ClassNotFoundException& cnfe1) {
					abort(cnfe1, "java.launcher.cls.error1"_s, $$new($ObjectArray, {
						$of(cn),
						$($of($of(cnfe1)->getClass()->getCanonicalName())),
						$($of(cnfe1->getMessage()))
					}));
				}
			} else {
				abort(cnfe, "java.launcher.cls.error1"_s, $$new($ObjectArray, {
					$of(cn),
					$($of($of(cnfe)->getClass()->getCanonicalName())),
					$($of(cnfe->getMessage()))
				}));
			}
		}
	} catch ($LinkageError& le) {
		$var($String, var$2, $$str({$($of(le)->getClass()->getName()), ": "_s}));
		abort(le, "java.launcher.cls.error6"_s, $$new($ObjectArray, {
			$of(cn),
			$of(($$concat(var$2, $(le->getLocalizedMessage()))))
		}));
	}
	return mainClass;
}

$Class* LauncherHelper::getApplicationClass() {
	$init(LauncherHelper);
	return LauncherHelper::appClass;
}

bool LauncherHelper::doesExtendFXApplication($Class* mainClass) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	{
		$Class* sc = $nc(mainClass)->getSuperclass();
		for (; sc != nullptr; sc = $nc(sc)->getSuperclass()) {
			if ($nc($(sc->getName()))->equals(LauncherHelper::JAVAFX_APPLICATION_CLASS_NAME)) {
				return true;
			}
		}
	}
	return false;
}

void LauncherHelper::validateMainClass($Class* mainClass) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Method, mainMethod, nullptr);
	try {
		$load($StringArray);
		$assign(mainMethod, $nc(mainClass)->getMethod("main"_s, $$new($ClassArray, {$getClass($StringArray)})));
	} catch ($NoSuchMethodException& nsme) {
		abort(nullptr, "java.launcher.cls.error4"_s, $$new($ObjectArray, {
			$($of($nc(mainClass)->getName())),
			$of(LauncherHelper::JAVAFX_APPLICATION_CLASS_NAME)
		}));
	} catch ($Throwable& e) {
		if ($nc($($nc(mainClass)->getModule()))->isNamed()) {
			abort(e, "java.launcher.module.error5"_s, $$new($ObjectArray, {
				$($of(mainClass->getName())),
				$($of($nc($(mainClass->getModule()))->getName())),
				$($of($of(e)->getClass()->getName())),
				$($of(e->getLocalizedMessage()))
			}));
		} else {
			abort(e, "java.launcher.cls.error7"_s, $$new($ObjectArray, {
				$($of(mainClass->getName())),
				$($of($of(e)->getClass()->getName())),
				$($of(e->getLocalizedMessage()))
			}));
		}
	}
	int32_t mod = $nc(mainMethod)->getModifiers();
	if (!$Modifier::isStatic(mod)) {
		abort(nullptr, "java.launcher.cls.error2"_s, $$new($ObjectArray, {
			$of("static"_s),
			$($of($nc(mainMethod->getDeclaringClass())->getName()))
		}));
	}
	$init($Void);
	if (mainMethod->getReturnType() != $Void::TYPE) {
		abort(nullptr, "java.launcher.cls.error3"_s, $$new($ObjectArray, {$($of($nc(mainMethod->getDeclaringClass())->getName()))}));
	}
}

$String* LauncherHelper::makePlatformString(bool printToStderr, $bytes* inArray) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	initOutput(printToStderr);
	if (LauncherHelper::encoding == nullptr) {
		$assignStatic(LauncherHelper::encoding, $System::getProperty(LauncherHelper::encprop));
		LauncherHelper::isCharsetSupported = $Charset::isSupported(LauncherHelper::encoding);
	}
	try {
		$var($String, out, LauncherHelper::isCharsetSupported ? $new($String, inArray, LauncherHelper::encoding) : $new($String, inArray));
		return out;
	} catch ($UnsupportedEncodingException& uee) {
		abort(uee, nullptr, $$new($ObjectArray, 0));
	}
	return nullptr;
}

$StringArray* LauncherHelper::expandArgs($StringArray* argArray) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	$var($List, aList, $new($ArrayList));
	{
		$var($StringArray, arr$, argArray);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, x, arr$->get(i$));
			{
				aList->add($$new($LauncherHelper$StdArg, x));
			}
		}
	}
	return expandArgs(aList);
}

$StringArray* LauncherHelper::expandArgs($List* argList) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	$var($ArrayList, out, $new($ArrayList));
	if (LauncherHelper::trace) {
		$nc($System::err)->println("Incoming arguments:"_s);
	}
	{
		$var($Iterator, i$, $nc(argList)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($LauncherHelper$StdArg, a, $cast($LauncherHelper$StdArg, i$->next()));
			{
				if (LauncherHelper::trace) {
					$nc($System::err)->println($of(a));
				}
				if ($nc(a)->needsExpansion) {
					$var($File, x, $new($File, a->arg));
					$var($File, parent, x->getParentFile());
					$var($String, glob, x->getName());
					if (parent == nullptr) {
						$assign(parent, $new($File, "."_s));
					}
					try {
						$var($DirectoryStream, dstream, $Files::newDirectoryStream($($nc(parent)->toPath()), glob));
						{
							$var($Throwable, var$0, nullptr);
							try {
								try {
									int32_t entries = 0;
									{
										$var($Iterator, i$, $nc(dstream)->iterator());
										for (; $nc(i$)->hasNext();) {
											$var($Path, p, $cast($Path, i$->next()));
											{
												out->add($($nc($($nc(p)->normalize()))->toString()));
												++entries;
											}
										}
									}
									if (entries == 0) {
										out->add(a->arg);
									}
								} catch ($Throwable& t$) {
									if (dstream != nullptr) {
										try {
											dstream->close();
										} catch ($Throwable& x2) {
											t$->addSuppressed(x2);
										}
									}
									$throw(t$);
								}
							} catch ($Throwable& var$1) {
								$assign(var$0, var$1);
							} /*finally*/ {
								if (dstream != nullptr) {
									dstream->close();
								}
							}
							if (var$0 != nullptr) {
								$throw(var$0);
							}
						}
					} catch ($Exception& e) {
						out->add(a->arg);
						if (LauncherHelper::trace) {
							$nc($System::err)->println($$str({"Warning: passing argument as-is "_s, a}));
							$nc($System::err)->print($of(e));
						}
					}
				} else {
					out->add(a->arg);
				}
			}
		}
	}
	$var($StringArray, oarray, $new($StringArray, out->size()));
	out->toArray(oarray);
	if (LauncherHelper::trace) {
		$nc($System::err)->println("Expanded arguments:"_s);
		{
			$var($StringArray, arr$, oarray);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, x, arr$->get(i$));
				{
					$nc($System::err)->println(x);
				}
			}
		}
	}
	return oarray;
}

void LauncherHelper::listModules() {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	initOutput($System::out);
	$nc($($nc($($nc($($nc($($ModuleBootstrap::limitedFinder()))->findAll()))->stream()))->sorted($$new($LauncherHelper$JrtFirstComparator))))->forEach(static_cast<$Consumer*>($$new(LauncherHelper$$Lambda$showModule$3)));
}

void LauncherHelper::showResolvedModules() {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	initOutput($System::out);
	$var($ModuleLayer, bootLayer, $ModuleLayer::boot());
	$var($Configuration, cf, $nc(bootLayer)->configuration());
	$nc($($nc($($nc($($nc($($nc(cf)->modules()))->stream()))->map(static_cast<$Function*>($$new(LauncherHelper$$Lambda$reference$4)))))->sorted($$new($LauncherHelper$JrtFirstComparator))))->forEach(static_cast<$Consumer*>($$new(LauncherHelper$$Lambda$showModule$3)));
}

void LauncherHelper::describeModule($String* moduleName) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	initOutput($System::out);
	$var($ModuleFinder, finder, $ModuleBootstrap::limitedFinder());
	$var($ModuleReference, mref, $cast($ModuleReference, $nc($($nc(finder)->find(moduleName)))->orElse(nullptr)));
	if (mref == nullptr) {
		abort(nullptr, "java.launcher.module.error4"_s, $$new($ObjectArray, {$of(moduleName)}));
	}
	$var($ModuleDescriptor, md, $nc(mref)->descriptor());
	showModule(mref);
	$nc($($nc($($nc($($nc($($nc($($nc(md)->exports()))->stream()))->filter(static_cast<$Predicate*>($$new(LauncherHelper$$Lambda$lambda$describeModule$3$5)))))->sorted($($Comparator::comparing(static_cast<$Function*>($$new(LauncherHelper$$Lambda$source$6)))))))->map(static_cast<$Function*>($$new(LauncherHelper$$Lambda$lambda$describeModule$4$7)))))->forEach(static_cast<$Consumer*>($$new(LauncherHelper$$Lambda$lambda$describeModule$5$8)));
	{
		$var($Iterator, i$, $nc($(md->requires()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ModuleDescriptor$Requires, r, $cast($ModuleDescriptor$Requires, i$->next()));
			{
				$var($Stream, var$0, $Stream::of($($of($nc(r)->name()))));
				$var($String, nameAndMods, $cast($String, $nc($($Stream::concat(var$0, $(toStringStream($($nc(r)->modifiers()))))))->collect($($Collectors::joining(" "_s)))));
				$nc(LauncherHelper::ostream)->format("requires %s"_s, $$new($ObjectArray, {$of(nameAndMods)}));
				$nc($($nc($($nc($(finder->find($($nc(r)->name()))))->map(static_cast<$Function*>($$new(LauncherHelper$$Lambda$descriptor$9)))))->filter(static_cast<$Predicate*>($$new(LauncherHelper$$Lambda$isAutomatic$10)))))->ifPresent(static_cast<$Consumer*>($$new(LauncherHelper$$Lambda$lambda$describeModule$6$11)));
				$nc(LauncherHelper::ostream)->println();
			}
		}
	}
	{
		$var($Iterator, i$, $nc($(md->uses()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, s, $cast($String, i$->next()));
			{
				$nc(LauncherHelper::ostream)->format("uses %s%n"_s, $$new($ObjectArray, {$of(s)}));
			}
		}
	}
	{
		$var($Iterator, i$, $nc($(md->provides()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ModuleDescriptor$Provides, ps, $cast($ModuleDescriptor$Provides, i$->next()));
			{
				$var($String, names, $cast($String, $nc($($nc($($nc(ps)->providers()))->stream()))->collect($($Collectors::joining(" "_s)))));
				$nc(LauncherHelper::ostream)->format("provides %s with %s%n"_s, $$new($ObjectArray, {
					$($of(ps->service())),
					$of(names)
				}));
			}
		}
	}
	{
		$var($Iterator, i$, $nc($(md->exports()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ModuleDescriptor$Exports, e, $cast($ModuleDescriptor$Exports, i$->next()));
			{
				if ($nc(e)->isQualified()) {
					$var($String, who, $cast($String, $nc($($nc($(e->targets()))->stream()))->collect($($Collectors::joining(" "_s)))));
					$nc(LauncherHelper::ostream)->format("qualified exports %s to %s%n"_s, $$new($ObjectArray, {
						$($of(e->source())),
						$of(who)
					}));
				}
			}
		}
	}
	{
		$var($Iterator, i$, $nc($(md->opens()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ModuleDescriptor$Opens, opens, $cast($ModuleDescriptor$Opens, i$->next()));
			{
				if ($nc(opens)->isQualified()) {
					$nc(LauncherHelper::ostream)->print("qualified "_s);
				}
				$var($Stream, var$1, $Stream::of($($of($nc(opens)->source()))));
				$var($String, sourceAndMods, $cast($String, $nc($($Stream::concat(var$1, $(toStringStream($($nc(opens)->modifiers()))))))->collect($($Collectors::joining(" "_s)))));
				$nc(LauncherHelper::ostream)->format("opens %s"_s, $$new($ObjectArray, {$of(sourceAndMods)}));
				if ($nc(opens)->isQualified()) {
					$var($String, who, $cast($String, $nc($($nc($(opens->targets()))->stream()))->collect($($Collectors::joining(" "_s)))));
					$nc(LauncherHelper::ostream)->format(" to %s"_s, $$new($ObjectArray, {$of(who)}));
				}
				$nc(LauncherHelper::ostream)->println();
			}
		}
	}
	$var($Set, concealed, static_cast<$Set*>(static_cast<$AbstractSet*>($new($TreeSet, $(static_cast<$Collection*>(md->packages()))))));
	$nc($($nc($($nc($(md->exports()))->stream()))->map(static_cast<$Function*>($$new(LauncherHelper$$Lambda$source$6)))))->forEach(static_cast<$Consumer*>($$new(LauncherHelper$$Lambda$remove$12, static_cast<$Set*>(concealed))));
	$nc($($nc($($nc($(md->opens()))->stream()))->map(static_cast<$Function*>($$new(LauncherHelper$$Lambda$source$13)))))->forEach(static_cast<$Consumer*>($$new(LauncherHelper$$Lambda$remove$12, static_cast<$Set*>(concealed))));
	concealed->forEach(static_cast<$Consumer*>($$new(LauncherHelper$$Lambda$lambda$describeModule$7$14)));
}

void LauncherHelper::showModule($ModuleReference* mref) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	$var($ModuleDescriptor, md, $nc(mref)->descriptor());
	$nc(LauncherHelper::ostream)->print($($nc(md)->toNameAndVersion()));
	$nc($($nc($(mref->location()))->filter(static_cast<$Predicate*>($$new(LauncherHelper$$Lambda$lambda$showModule$8$15)))))->ifPresent(static_cast<$Consumer*>($$new(LauncherHelper$$Lambda$lambda$showModule$9$16)));
	if ($nc(md)->isOpen()) {
		$nc(LauncherHelper::ostream)->print(" open"_s);
	}
	if ($nc(md)->isAutomatic()) {
		$nc(LauncherHelper::ostream)->print(" automatic"_s);
	}
	$nc(LauncherHelper::ostream)->println();
}

$Stream* LauncherHelper::toStringStream($Set* s) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	return $nc($($nc(s)->stream()))->map(static_cast<$Function*>($$new(LauncherHelper$$Lambda$lambda$toStringStream$10$17)));
}

bool LauncherHelper::isJrt($ModuleReference* mref) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	return isJrt($cast($URI, $($nc($($nc(mref)->location()))->orElse(nullptr))));
}

bool LauncherHelper::isJrt($URI* uri) {
	$init(LauncherHelper);
	return (uri != nullptr && $nc($(uri->getScheme()))->equalsIgnoreCase("jrt"_s));
}

$String* LauncherHelper::lambda$toStringStream$10(Object$* e) {
	$init(LauncherHelper);
	return $nc($($nc($of(e))->toString()))->toLowerCase();
}

void LauncherHelper::lambda$showModule$9($URI* uri) {
	$init(LauncherHelper);
	$nc(LauncherHelper::ostream)->format(" %s"_s, $$new($ObjectArray, {$of(uri)}));
}

bool LauncherHelper::lambda$showModule$8($URI* uri) {
	$init(LauncherHelper);
	return !isJrt(uri);
}

void LauncherHelper::lambda$describeModule$7($String* p) {
	$init(LauncherHelper);
	$nc(LauncherHelper::ostream)->format("contains %s%n"_s, $$new($ObjectArray, {$of(p)}));
}

void LauncherHelper::lambda$describeModule$6($ModuleDescriptor* any) {
	$init(LauncherHelper);
	$nc(LauncherHelper::ostream)->print(" automatic"_s);
}

void LauncherHelper::lambda$describeModule$5($String* sourceAndMods) {
	$init(LauncherHelper);
	$nc(LauncherHelper::ostream)->format("exports %s%n"_s, $$new($ObjectArray, {$of(sourceAndMods)}));
}

$String* LauncherHelper::lambda$describeModule$4($ModuleDescriptor$Exports* e) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	$var($Stream, var$0, $Stream::of($($of($nc(e)->source()))));
	return $cast($String, $nc($($Stream::concat(var$0, $(toStringStream($($nc(e)->modifiers()))))))->collect($($Collectors::joining(" "_s))));
}

bool LauncherHelper::lambda$describeModule$3($ModuleDescriptor$Exports* e) {
	$init(LauncherHelper);
	return !$nc(e)->isQualified();
}

void LauncherHelper::lambda$addExportsOrOpens$2(bool open, $String* pn, $Module* m) {
	$init(LauncherHelper);
	if (open) {
		$Modules::addOpensToAllUnnamed(m, pn);
	} else {
		$Modules::addExportsToAllUnnamed(m, pn);
	}
}

bool LauncherHelper::lambda$addExportsOrOpens$1($String* pn, $Module* m) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	return $nc($($nc($($nc(m)->getDescriptor()))->packages()))->contains(pn);
}

void LauncherHelper::lambda$getMainClassFromJar$0($String* jarname, $Module* m) {
	$init(LauncherHelper);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$var($String, cn, "sun.instrument.InstrumentationImpl"_s);
		$Class* clazz = $Class::forName(cn, false, nullptr);
		$var($Method, loadAgent, $nc(clazz)->getMethod("loadAgent"_s, $$new($ClassArray, {$String::class$})));
		$nc(loadAgent)->invoke(nullptr, $$new($ObjectArray, {$of(jarname)}));
	} catch ($Throwable& e) {
		if ($instanceOf($InvocationTargetException, e)) {
			$assign(e, e->getCause());
		}
		abort(e, "java.launcher.jar.error4"_s, $$new($ObjectArray, {$of(jarname)}));
	}
}

void clinit$LauncherHelper($Class* class$) {
	$assignStatic(LauncherHelper::JAVAFX_APPLICATION_MARKER, "JavaFX-Application-Class"_s);
	$assignStatic(LauncherHelper::JAVAFX_APPLICATION_CLASS_NAME, "javafx.application.Application"_s);
	$assignStatic(LauncherHelper::JAVAFX_FXHELPER_CLASS_NAME_SUFFIX, "sun.launcher.LauncherHelper$FXHelper"_s);
	$assignStatic(LauncherHelper::LAUNCHER_AGENT_CLASS, "Launcher-Agent-Class"_s);
	$assignStatic(LauncherHelper::MAIN_CLASS, "Main-Class"_s);
	$assignStatic(LauncherHelper::ADD_EXPORTS, "Add-Exports"_s);
	$assignStatic(LauncherHelper::ADD_OPENS, "Add-Opens"_s);
	$assignStatic(LauncherHelper::INDENT, "    "_s);
	$assignStatic(LauncherHelper::VM_SETTINGS, "VM settings:"_s);
	$assignStatic(LauncherHelper::PROP_SETTINGS, "Property settings:"_s);
	$assignStatic(LauncherHelper::LOCALE_SETTINGS, "Locale settings:"_s);
	$assignStatic(LauncherHelper::diagprop, "sun.java.launcher.diag"_s);
	$assignStatic(LauncherHelper::defaultBundleName, "sun.launcher.resources.launcher"_s);
	$assignStatic(LauncherHelper::encprop, "sun.jnu.encoding"_s);
	$assignStatic(LauncherHelper::outBuf, $new($StringBuilder));
	LauncherHelper::trace = $VM::getSavedProperty(LauncherHelper::diagprop) != nullptr;
	$assignStatic(LauncherHelper::encoding, nullptr);
	LauncherHelper::isCharsetSupported = false;
}

LauncherHelper::LauncherHelper() {
}

$Class* LauncherHelper::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(LauncherHelper$$Lambda$lambda$getMainClassFromJar$0::classInfo$.name)) {
			return LauncherHelper$$Lambda$lambda$getMainClassFromJar$0::load$(name, initialize);
		}
		if (name->equals(LauncherHelper$$Lambda$lambda$addExportsOrOpens$1$1::classInfo$.name)) {
			return LauncherHelper$$Lambda$lambda$addExportsOrOpens$1$1::load$(name, initialize);
		}
		if (name->equals(LauncherHelper$$Lambda$lambda$addExportsOrOpens$2$2::classInfo$.name)) {
			return LauncherHelper$$Lambda$lambda$addExportsOrOpens$2$2::load$(name, initialize);
		}
		if (name->equals(LauncherHelper$$Lambda$showModule$3::classInfo$.name)) {
			return LauncherHelper$$Lambda$showModule$3::load$(name, initialize);
		}
		if (name->equals(LauncherHelper$$Lambda$reference$4::classInfo$.name)) {
			return LauncherHelper$$Lambda$reference$4::load$(name, initialize);
		}
		if (name->equals(LauncherHelper$$Lambda$lambda$describeModule$3$5::classInfo$.name)) {
			return LauncherHelper$$Lambda$lambda$describeModule$3$5::load$(name, initialize);
		}
		if (name->equals(LauncherHelper$$Lambda$source$6::classInfo$.name)) {
			return LauncherHelper$$Lambda$source$6::load$(name, initialize);
		}
		if (name->equals(LauncherHelper$$Lambda$lambda$describeModule$4$7::classInfo$.name)) {
			return LauncherHelper$$Lambda$lambda$describeModule$4$7::load$(name, initialize);
		}
		if (name->equals(LauncherHelper$$Lambda$lambda$describeModule$5$8::classInfo$.name)) {
			return LauncherHelper$$Lambda$lambda$describeModule$5$8::load$(name, initialize);
		}
		if (name->equals(LauncherHelper$$Lambda$descriptor$9::classInfo$.name)) {
			return LauncherHelper$$Lambda$descriptor$9::load$(name, initialize);
		}
		if (name->equals(LauncherHelper$$Lambda$isAutomatic$10::classInfo$.name)) {
			return LauncherHelper$$Lambda$isAutomatic$10::load$(name, initialize);
		}
		if (name->equals(LauncherHelper$$Lambda$lambda$describeModule$6$11::classInfo$.name)) {
			return LauncherHelper$$Lambda$lambda$describeModule$6$11::load$(name, initialize);
		}
		if (name->equals(LauncherHelper$$Lambda$remove$12::classInfo$.name)) {
			return LauncherHelper$$Lambda$remove$12::load$(name, initialize);
		}
		if (name->equals(LauncherHelper$$Lambda$source$13::classInfo$.name)) {
			return LauncherHelper$$Lambda$source$13::load$(name, initialize);
		}
		if (name->equals(LauncherHelper$$Lambda$lambda$describeModule$7$14::classInfo$.name)) {
			return LauncherHelper$$Lambda$lambda$describeModule$7$14::load$(name, initialize);
		}
		if (name->equals(LauncherHelper$$Lambda$lambda$showModule$8$15::classInfo$.name)) {
			return LauncherHelper$$Lambda$lambda$showModule$8$15::load$(name, initialize);
		}
		if (name->equals(LauncherHelper$$Lambda$lambda$showModule$9$16::classInfo$.name)) {
			return LauncherHelper$$Lambda$lambda$showModule$9$16::load$(name, initialize);
		}
		if (name->equals(LauncherHelper$$Lambda$lambda$toStringStream$10$17::classInfo$.name)) {
			return LauncherHelper$$Lambda$lambda$toStringStream$10$17::load$(name, initialize);
		}
	}
	$loadClass(LauncherHelper, name, initialize, &_LauncherHelper_ClassInfo_, clinit$LauncherHelper, allocate$LauncherHelper);
	return class$;
}

$Class* LauncherHelper::class$ = nullptr;

	} // launcher
} // sun