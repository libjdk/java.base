#include <java/lang/module/ModuleDescriptor.h>

#include <java/io/InputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Comparable.h>
#include <java/lang/Enum.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/ModuleDescriptor$1.h>
#include <java/lang/module/ModuleDescriptor$Builder.h>
#include <java/lang/module/ModuleDescriptor$Modifier.h>
#include <java/lang/module/ModuleDescriptor$Requires.h>
#include <java/lang/module/ModuleDescriptor$Version.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/Locale.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/function/Function.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/access/JavaLangModuleAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/module/ModuleInfo$Attributes.h>
#include <jdk/internal/module/ModuleInfo.h>
#include <jcpp.h>

#undef AUTOMATIC
#undef OPEN
#undef ROOT

using $ComparableArray = $Array<::java::lang::Comparable>;
using $InputStream = ::java::io::InputStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Comparable = ::java::lang::Comparable;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ModuleDescriptor$1 = ::java::lang::module::ModuleDescriptor$1;
using $ModuleDescriptor$Builder = ::java::lang::module::ModuleDescriptor$Builder;
using $ModuleDescriptor$Modifier = ::java::lang::module::ModuleDescriptor$Modifier;
using $ModuleDescriptor$Requires = ::java::lang::module::ModuleDescriptor$Requires;
using $ModuleDescriptor$Version = ::java::lang::module::ModuleDescriptor$Version;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $Locale = ::java::util::Locale;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $Function = ::java::util::function::Function;
using $Supplier = ::java::util::function::Supplier;
using $Collectors = ::java::util::stream::Collectors;
using $Stream = ::java::util::stream::Stream;
using $JavaLangModuleAccess = ::jdk::internal::access::JavaLangModuleAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $ModuleInfo = ::jdk::internal::module::ModuleInfo;
using $ModuleInfo$Attributes = ::jdk::internal::module::ModuleInfo$Attributes;

namespace java {
	namespace lang {
		namespace module {

class ModuleDescriptor$$Lambda$name : public $Function {
	$class(ModuleDescriptor$$Lambda$name, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($ModuleDescriptor$Requires, inst$)->name());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleDescriptor$$Lambda$name>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ModuleDescriptor$$Lambda$name::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModuleDescriptor$$Lambda$name, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModuleDescriptor$$Lambda$name, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ModuleDescriptor$$Lambda$name::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.ModuleDescriptor$$Lambda$name",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ModuleDescriptor$$Lambda$name::load$($String* name, bool initialize) {
	$loadClass(ModuleDescriptor$$Lambda$name, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleDescriptor$$Lambda$name::class$ = nullptr;

class ModuleDescriptor$$Lambda$lambda$toString$0$1 : public $Function {
	$class(ModuleDescriptor$$Lambda$lambda$toString$0$1, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* e) override {
		 return $of(ModuleDescriptor::lambda$toString$0(e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleDescriptor$$Lambda$lambda$toString$0$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ModuleDescriptor$$Lambda$lambda$toString$0$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModuleDescriptor$$Lambda$lambda$toString$0$1, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModuleDescriptor$$Lambda$lambda$toString$0$1, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ModuleDescriptor$$Lambda$lambda$toString$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.ModuleDescriptor$$Lambda$lambda$toString$0$1",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ModuleDescriptor$$Lambda$lambda$toString$0$1::load$($String* name, bool initialize) {
	$loadClass(ModuleDescriptor$$Lambda$lambda$toString$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleDescriptor$$Lambda$lambda$toString$0$1::class$ = nullptr;

$FieldInfo _ModuleDescriptor_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ModuleDescriptor, $assertionsDisabled)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(ModuleDescriptor, name$)},
	{"version", "Ljava/lang/module/ModuleDescriptor$Version;", nullptr, $PRIVATE | $FINAL, $field(ModuleDescriptor, version$)},
	{"rawVersionString", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(ModuleDescriptor, rawVersionString)},
	{"modifiers", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Modifier;>;", $PRIVATE | $FINAL, $field(ModuleDescriptor, modifiers$)},
	{"open", "Z", nullptr, $PRIVATE | $FINAL, $field(ModuleDescriptor, open)},
	{"automatic", "Z", nullptr, $PRIVATE | $FINAL, $field(ModuleDescriptor, automatic)},
	{"requires", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Requires;>;", $PRIVATE | $FINAL, $field(ModuleDescriptor, requires$)},
	{"exports", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Exports;>;", $PRIVATE | $FINAL, $field(ModuleDescriptor, exports$)},
	{"opens", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Opens;>;", $PRIVATE | $FINAL, $field(ModuleDescriptor, opens$)},
	{"uses", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $FINAL, $field(ModuleDescriptor, uses$)},
	{"provides", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Provides;>;", $PRIVATE | $FINAL, $field(ModuleDescriptor, provides$)},
	{"packages", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $FINAL, $field(ModuleDescriptor, packages$)},
	{"mainClass", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(ModuleDescriptor, mainClass$)},
	{"hash", "I", nullptr, $PRIVATE | $TRANSIENT, $field(ModuleDescriptor, hash)},
	{}
};

$MethodInfo _ModuleDescriptor_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/module/ModuleDescriptor$Version;Ljava/lang/String;Ljava/util/Set;Ljava/util/Set;Ljava/util/Set;Ljava/util/Set;Ljava/util/Set;Ljava/util/Set;Ljava/util/Set;Ljava/lang/String;)V", "(Ljava/lang/String;Ljava/lang/module/ModuleDescriptor$Version;Ljava/lang/String;Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Modifier;>;Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Requires;>;Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Exports;>;Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Opens;>;Ljava/util/Set<Ljava/lang/String;>;Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Provides;>;Ljava/util/Set<Ljava/lang/String;>;Ljava/lang/String;)V", $PRIVATE, $method(ModuleDescriptor, init$, void, $String*, $ModuleDescriptor$Version*, $String*, $Set*, $Set*, $Set*, $Set*, $Set*, $Set*, $Set*, $String*)},
	{"<init>", "(Ljava/lang/String;Ljava/lang/module/ModuleDescriptor$Version;Ljava/util/Set;Ljava/util/Set;Ljava/util/Set;Ljava/util/Set;Ljava/util/Set;Ljava/util/Set;Ljava/util/Set;Ljava/lang/String;IZ)V", "(Ljava/lang/String;Ljava/lang/module/ModuleDescriptor$Version;Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Modifier;>;Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Requires;>;Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Exports;>;Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Opens;>;Ljava/util/Set<Ljava/lang/String;>;Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Provides;>;Ljava/util/Set<Ljava/lang/String;>;Ljava/lang/String;IZ)V", 0, $method(ModuleDescriptor, init$, void, $String*, $ModuleDescriptor$Version*, $Set*, $Set*, $Set*, $Set*, $Set*, $Set*, $Set*, $String*, int32_t, bool)},
	{"compare", "(Ljava/lang/Object;Ljava/lang/Object;)I", "<T:Ljava/lang/Object;:Ljava/lang/Comparable<-TT;>;>(TT;TT;)I", $PRIVATE | $STATIC, $staticMethod(ModuleDescriptor, compare, int32_t, Object$*, Object$*)},
	{"compare", "(Ljava/util/Set;Ljava/util/Set;)I", "<T:Ljava/lang/Object;:Ljava/lang/Comparable<-TT;>;>(Ljava/util/Set<TT;>;Ljava/util/Set<TT;>;)I", $PRIVATE | $STATIC, $staticMethod(ModuleDescriptor, compare, int32_t, $Set*, $Set*)},
	{"compareTo", "(Ljava/lang/module/ModuleDescriptor;)I", nullptr, $PUBLIC, $virtualMethod(ModuleDescriptor, compareTo, int32_t, ModuleDescriptor*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(ModuleDescriptor, compareTo, int32_t, Object$*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ModuleDescriptor, equals, bool, Object$*)},
	{"exports", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Exports;>;", $PUBLIC, $virtualMethod(ModuleDescriptor, exports, $Set*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(ModuleDescriptor, hashCode, int32_t)},
	{"isAutomatic", "()Z", nullptr, $PUBLIC, $virtualMethod(ModuleDescriptor, isAutomatic, bool)},
	{"isOpen", "()Z", nullptr, $PUBLIC, $virtualMethod(ModuleDescriptor, isOpen, bool)},
	{"lambda$toString$0", "(Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModuleDescriptor, lambda$toString$0, $String*, Object$*)},
	{"mainClass", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(ModuleDescriptor, mainClass, $Optional*)},
	{"modifiers", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Modifier;>;", $PUBLIC, $virtualMethod(ModuleDescriptor, modifiers, $Set*)},
	{"modsValue", "(Ljava/util/Set;)J", "<E:Ljava/lang/Enum<TE;>;>(Ljava/util/Set<TE;>;)J", $PRIVATE | $STATIC, $staticMethod(ModuleDescriptor, modsValue, int64_t, $Set*)},
	{"name", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ModuleDescriptor, name, $String*)},
	{"newAutomaticModule", "(Ljava/lang/String;)Ljava/lang/module/ModuleDescriptor$Builder;", nullptr, $PUBLIC | $STATIC, $staticMethod(ModuleDescriptor, newAutomaticModule, $ModuleDescriptor$Builder*, $String*)},
	{"newModule", "(Ljava/lang/String;Ljava/util/Set;)Ljava/lang/module/ModuleDescriptor$Builder;", "(Ljava/lang/String;Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Modifier;>;)Ljava/lang/module/ModuleDescriptor$Builder;", $PUBLIC | $STATIC, $staticMethod(ModuleDescriptor, newModule, $ModuleDescriptor$Builder*, $String*, $Set*)},
	{"newModule", "(Ljava/lang/String;)Ljava/lang/module/ModuleDescriptor$Builder;", nullptr, $PUBLIC | $STATIC, $staticMethod(ModuleDescriptor, newModule, $ModuleDescriptor$Builder*, $String*)},
	{"newOpenModule", "(Ljava/lang/String;)Ljava/lang/module/ModuleDescriptor$Builder;", nullptr, $PUBLIC | $STATIC, $staticMethod(ModuleDescriptor, newOpenModule, $ModuleDescriptor$Builder*, $String*)},
	{"opens", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Opens;>;", $PUBLIC, $virtualMethod(ModuleDescriptor, opens, $Set*)},
	{"packageName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ModuleDescriptor, packageName, $String*, $String*)},
	{"packages", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(ModuleDescriptor, packages, $Set*)},
	{"provides", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Provides;>;", $PUBLIC, $virtualMethod(ModuleDescriptor, provides, $Set*)},
	{"rawVersion", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(ModuleDescriptor, rawVersion, $Optional*)},
	{"read", "(Ljava/io/InputStream;Ljava/util/function/Supplier;)Ljava/lang/module/ModuleDescriptor;", "(Ljava/io/InputStream;Ljava/util/function/Supplier<Ljava/util/Set<Ljava/lang/String;>;>;)Ljava/lang/module/ModuleDescriptor;", $PUBLIC | $STATIC, $staticMethod(ModuleDescriptor, read, ModuleDescriptor*, $InputStream*, $Supplier*), "java.io.IOException"},
	{"read", "(Ljava/io/InputStream;)Ljava/lang/module/ModuleDescriptor;", nullptr, $PUBLIC | $STATIC, $staticMethod(ModuleDescriptor, read, ModuleDescriptor*, $InputStream*), "java.io.IOException"},
	{"read", "(Ljava/nio/ByteBuffer;Ljava/util/function/Supplier;)Ljava/lang/module/ModuleDescriptor;", "(Ljava/nio/ByteBuffer;Ljava/util/function/Supplier<Ljava/util/Set<Ljava/lang/String;>;>;)Ljava/lang/module/ModuleDescriptor;", $PUBLIC | $STATIC, $staticMethod(ModuleDescriptor, read, ModuleDescriptor*, $ByteBuffer*, $Supplier*)},
	{"read", "(Ljava/nio/ByteBuffer;)Ljava/lang/module/ModuleDescriptor;", nullptr, $PUBLIC | $STATIC, $staticMethod(ModuleDescriptor, read, ModuleDescriptor*, $ByteBuffer*)},
	{"requires", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/module/ModuleDescriptor$Requires;>;", $PUBLIC, $virtualMethod(ModuleDescriptor, requires, $Set*)},
	{"toNameAndVersion", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ModuleDescriptor, toNameAndVersion, $String*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ModuleDescriptor, toString, $String*)},
	{"toString", "(Ljava/util/Set;Ljava/lang/String;)Ljava/lang/String;", "<M:Ljava/lang/Object;>(Ljava/util/Set<TM;>;Ljava/lang/String;)Ljava/lang/String;", $PRIVATE | $STATIC, $staticMethod(ModuleDescriptor, toString, $String*, $Set*, $String*)},
	{"uses", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(ModuleDescriptor, uses, $Set*)},
	{"version", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/lang/module/ModuleDescriptor$Version;>;", $PUBLIC, $virtualMethod(ModuleDescriptor, version, $Optional*)},
	{}
};

$InnerClassInfo _ModuleDescriptor_InnerClassesInfo_[] = {
	{"java.lang.module.ModuleDescriptor$Builder", "java.lang.module.ModuleDescriptor", "Builder", $PUBLIC | $STATIC | $FINAL},
	{"java.lang.module.ModuleDescriptor$Version", "java.lang.module.ModuleDescriptor", "Version", $PUBLIC | $STATIC | $FINAL},
	{"java.lang.module.ModuleDescriptor$Provides", "java.lang.module.ModuleDescriptor", "Provides", $PUBLIC | $STATIC | $FINAL},
	{"java.lang.module.ModuleDescriptor$Opens", "java.lang.module.ModuleDescriptor", "Opens", $PUBLIC | $STATIC | $FINAL},
	{"java.lang.module.ModuleDescriptor$Exports", "java.lang.module.ModuleDescriptor", "Exports", $PUBLIC | $STATIC | $FINAL},
	{"java.lang.module.ModuleDescriptor$Requires", "java.lang.module.ModuleDescriptor", "Requires", $PUBLIC | $STATIC | $FINAL},
	{"java.lang.module.ModuleDescriptor$Modifier", "java.lang.module.ModuleDescriptor", "Modifier", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{"java.lang.module.ModuleDescriptor$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ModuleDescriptor_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.lang.module.ModuleDescriptor",
	"java.lang.Object",
	"java.lang.Comparable",
	_ModuleDescriptor_FieldInfo_,
	_ModuleDescriptor_MethodInfo_,
	"Ljava/lang/Object;Ljava/lang/Comparable<Ljava/lang/module/ModuleDescriptor;>;",
	nullptr,
	_ModuleDescriptor_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.module.ModuleDescriptor$Builder,java.lang.module.ModuleDescriptor$Version,java.lang.module.ModuleDescriptor$Provides,java.lang.module.ModuleDescriptor$Opens,java.lang.module.ModuleDescriptor$Opens$Modifier,java.lang.module.ModuleDescriptor$Exports,java.lang.module.ModuleDescriptor$Exports$Modifier,java.lang.module.ModuleDescriptor$Requires,java.lang.module.ModuleDescriptor$Requires$Modifier,java.lang.module.ModuleDescriptor$Modifier,java.lang.module.ModuleDescriptor$1"
};

$Object* allocate$ModuleDescriptor($Class* clazz) {
	return $of($alloc(ModuleDescriptor));
}

bool ModuleDescriptor::$assertionsDisabled = false;

void ModuleDescriptor::init$($String* name, $ModuleDescriptor$Version* version, $String* rawVersionString, $Set* modifiers, $Set* requires, $Set* exports, $Set* opens, $Set* uses, $Set* provides, $Set* packages, $String* mainClass) {
	$useLocalCurrentObjectStackCache();
	if (!ModuleDescriptor::$assertionsDisabled && !(version == nullptr || rawVersionString == nullptr)) {
		$throwNew($AssertionError);
	}
	$set(this, name$, name);
	$set(this, version$, version);
	$set(this, rawVersionString, rawVersionString);
	$set(this, modifiers$, $Set::copyOf(modifiers));
	$init($ModuleDescriptor$Modifier);
	this->open = $nc(modifiers)->contains($ModuleDescriptor$Modifier::OPEN);
	this->automatic = modifiers->contains($ModuleDescriptor$Modifier::AUTOMATIC);
	bool var$0 = !ModuleDescriptor::$assertionsDisabled;
	if (var$0) {
		int64_t var$1 = $nc($($nc($($nc($($nc(requires)->stream()))->map(static_cast<$Function*>($$new(ModuleDescriptor$$Lambda$name)))))->distinct()))->count();
		var$0 = !(var$1 == requires->size());
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	$set(this, requires$, $Set::copyOf(requires));
	$set(this, exports$, $Set::copyOf(exports));
	$set(this, opens$, $Set::copyOf(opens));
	$set(this, uses$, $Set::copyOf(uses));
	$set(this, provides$, $Set::copyOf(provides));
	$set(this, packages$, $Set::copyOf(packages));
	$set(this, mainClass$, mainClass);
}

void ModuleDescriptor::init$($String* name, $ModuleDescriptor$Version* version, $Set* modifiers, $Set* requires, $Set* exports, $Set* opens, $Set* uses, $Set* provides, $Set* packages, $String* mainClass, int32_t hashCode, bool unused) {
	$set(this, name$, name);
	$set(this, version$, version);
	$set(this, rawVersionString, nullptr);
	$set(this, modifiers$, modifiers);
	$init($ModuleDescriptor$Modifier);
	this->open = $nc(modifiers)->contains($ModuleDescriptor$Modifier::OPEN);
	this->automatic = modifiers->contains($ModuleDescriptor$Modifier::AUTOMATIC);
	$set(this, requires$, requires);
	$set(this, exports$, exports);
	$set(this, opens$, opens);
	$set(this, uses$, uses);
	$set(this, provides$, provides);
	$set(this, packages$, packages);
	$set(this, mainClass$, mainClass);
	this->hash = hashCode;
}

$String* ModuleDescriptor::name() {
	return this->name$;
}

$Set* ModuleDescriptor::modifiers() {
	return this->modifiers$;
}

bool ModuleDescriptor::isOpen() {
	return this->open;
}

bool ModuleDescriptor::isAutomatic() {
	return this->automatic;
}

$Set* ModuleDescriptor::requires() {
	return this->requires$;
}

$Set* ModuleDescriptor::exports() {
	return this->exports$;
}

$Set* ModuleDescriptor::opens() {
	return this->opens$;
}

$Set* ModuleDescriptor::uses() {
	return this->uses$;
}

$Set* ModuleDescriptor::provides() {
	return this->provides$;
}

$Optional* ModuleDescriptor::version() {
	return $Optional::ofNullable(this->version$);
}

$Optional* ModuleDescriptor::rawVersion() {
	if (this->version$ != nullptr) {
		return $Optional::of($($nc(this->version$)->toString()));
	} else {
		return $Optional::ofNullable(this->rawVersionString);
	}
}

$String* ModuleDescriptor::toNameAndVersion() {
	if (this->version$ != nullptr) {
		return $str({$(name()), "@"_s, this->version$});
	} else {
		return name();
	}
}

$Optional* ModuleDescriptor::mainClass() {
	return $Optional::ofNullable(this->mainClass$);
}

$Set* ModuleDescriptor::packages() {
	return this->packages$;
}

int32_t ModuleDescriptor::compareTo(ModuleDescriptor* that) {
	$useLocalCurrentObjectStackCache();
	if (this == that) {
		return 0;
	}
	int32_t c = $nc($(this->name()))->compareTo($($nc(that)->name()));
	if (c != 0) {
		return c;
	}
	c = compare($of(this->version$), $of($nc(that)->version$));
	if (c != 0) {
		return c;
	}
	c = compare($of(this->rawVersionString), $of($nc(that)->rawVersionString));
	if (c != 0) {
		return c;
	}
	int64_t v1 = modsValue($(this->modifiers()));
	int64_t v2 = modsValue($($nc(that)->modifiers()));
	c = $Long::compare(v1, v2);
	if (c != 0) {
		return c;
	}
	c = compare(this->requires$, $nc(that)->requires$);
	if (c != 0) {
		return c;
	}
	c = compare(this->packages$, $nc(that)->packages$);
	if (c != 0) {
		return c;
	}
	c = compare(this->exports$, $nc(that)->exports$);
	if (c != 0) {
		return c;
	}
	c = compare(this->opens$, $nc(that)->opens$);
	if (c != 0) {
		return c;
	}
	c = compare(this->uses$, $nc(that)->uses$);
	if (c != 0) {
		return c;
	}
	c = compare(this->provides$, $nc(that)->provides$);
	if (c != 0) {
		return c;
	}
	c = compare($of(this->mainClass$), $of($nc(that)->mainClass$));
	if (c != 0) {
		return c;
	}
	return 0;
}

bool ModuleDescriptor::equals(Object$* ob) {
	if ($equals(ob, this)) {
		return true;
	}
	$var(ModuleDescriptor, that, nullptr);
	bool var$1 = $instanceOf(ModuleDescriptor, ob);
	if (var$1) {
		$assign(that, $cast(ModuleDescriptor, ob));
		var$1 = true;
	}
	bool var$0 = (var$1);
	if (var$0) {
		bool var$11 = $nc(this->name$)->equals($nc(that)->name$);
		bool var$10 = var$11 && $nc(this->modifiers$)->equals($nc(that)->modifiers$);
		bool var$9 = var$10 && $nc(this->requires$)->equals($nc(that)->requires$);
		bool var$8 = var$9 && $Objects::equals(this->packages$, $nc(that)->packages$);
		bool var$7 = var$8 && $nc(this->exports$)->equals($nc(that)->exports$);
		bool var$6 = var$7 && $nc(this->opens$)->equals($nc(that)->opens$);
		bool var$5 = var$6 && $nc(this->uses$)->equals($nc(that)->uses$);
		bool var$4 = var$5 && $nc(this->provides$)->equals($nc(that)->provides$);
		bool var$3 = var$4 && $Objects::equals(this->version$, $nc(that)->version$);
		bool var$2 = var$3 && $Objects::equals(this->rawVersionString, $nc(that)->rawVersionString);
		var$0 = (var$2 && $Objects::equals(this->mainClass$, $nc(that)->mainClass$));
	}
	return var$0;
}

int32_t ModuleDescriptor::hashCode() {
	int32_t hc = this->hash;
	if (hc == 0) {
		hc = $nc(this->name$)->hashCode();
		hc = hc * 43 + $Objects::hashCode(this->modifiers$);
		hc = hc * 43 + $nc(this->requires$)->hashCode();
		hc = hc * 43 + $Objects::hashCode(this->packages$);
		hc = hc * 43 + $nc(this->exports$)->hashCode();
		hc = hc * 43 + $nc(this->opens$)->hashCode();
		hc = hc * 43 + $nc(this->uses$)->hashCode();
		hc = hc * 43 + $nc(this->provides$)->hashCode();
		hc = hc * 43 + $Objects::hashCode(this->version$);
		hc = hc * 43 + $Objects::hashCode(this->rawVersionString);
		hc = hc * 43 + $Objects::hashCode(this->mainClass$);
		if (hc == 0) {
			hc = -1;
		}
		this->hash = hc;
	}
	return hc;
}

$String* ModuleDescriptor::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	if (isOpen()) {
		sb->append("open "_s);
	}
	sb->append("module { name: "_s)->append($(toNameAndVersion()));
	if (!$nc(this->requires$)->isEmpty()) {
		sb->append(", "_s)->append($of(this->requires$));
	}
	if (!$nc(this->uses$)->isEmpty()) {
		sb->append(", uses: "_s)->append($of(this->uses$));
	}
	if (!$nc(this->exports$)->isEmpty()) {
		sb->append(", exports: "_s)->append($of(this->exports$));
	}
	if (!$nc(this->opens$)->isEmpty()) {
		sb->append(", opens: "_s)->append($of(this->opens$));
	}
	if (!$nc(this->provides$)->isEmpty()) {
		sb->append(", provides: "_s)->append($of(this->provides$));
	}
	sb->append(" }"_s);
	return sb->toString();
}

$ModuleDescriptor$Builder* ModuleDescriptor::newModule($String* name, $Set* ms) {
	$init(ModuleDescriptor);
	$var($Set, mods, $new($HashSet, static_cast<$Collection*>(ms)));
	$init($ModuleDescriptor$Modifier);
	bool var$0 = mods->contains($ModuleDescriptor$Modifier::AUTOMATIC);
	if (var$0 && mods->size() > 1) {
		$throwNew($IllegalArgumentException, "AUTOMATIC cannot be used with other modifiers"_s);
	}
	return $new($ModuleDescriptor$Builder, name, true, mods);
}

$ModuleDescriptor$Builder* ModuleDescriptor::newModule($String* name) {
	$init(ModuleDescriptor);
	return $new($ModuleDescriptor$Builder, name, true, $($Set::of()));
}

$ModuleDescriptor$Builder* ModuleDescriptor::newOpenModule($String* name) {
	$init(ModuleDescriptor);
	$init($ModuleDescriptor$Modifier);
	return $new($ModuleDescriptor$Builder, name, true, $($Set::of($of($ModuleDescriptor$Modifier::OPEN))));
}

$ModuleDescriptor$Builder* ModuleDescriptor::newAutomaticModule($String* name) {
	$init(ModuleDescriptor);
	$init($ModuleDescriptor$Modifier);
	return $new($ModuleDescriptor$Builder, name, true, $($Set::of($of($ModuleDescriptor$Modifier::AUTOMATIC))));
}

ModuleDescriptor* ModuleDescriptor::read($InputStream* in, $Supplier* packageFinder) {
	$init(ModuleDescriptor);
	return $nc($($ModuleInfo::read(in, $cast($Supplier, $Objects::requireNonNull(packageFinder)))))->descriptor();
}

ModuleDescriptor* ModuleDescriptor::read($InputStream* in) {
	$init(ModuleDescriptor);
	return $nc($($ModuleInfo::read(in, ($Supplier*)nullptr)))->descriptor();
}

ModuleDescriptor* ModuleDescriptor::read($ByteBuffer* bb, $Supplier* packageFinder) {
	$init(ModuleDescriptor);
	return $nc($($ModuleInfo::read(bb, $cast($Supplier, $Objects::requireNonNull(packageFinder)))))->descriptor();
}

ModuleDescriptor* ModuleDescriptor::read($ByteBuffer* bb) {
	$init(ModuleDescriptor);
	return $nc($($ModuleInfo::read(bb, ($Supplier*)nullptr)))->descriptor();
}

$String* ModuleDescriptor::packageName($String* cn) {
	$init(ModuleDescriptor);
	int32_t index = $nc(cn)->lastIndexOf((int32_t)u'.');
	return (index == -1) ? ""_s : cn->substring(0, index);
}

$String* ModuleDescriptor::toString($Set* mods, $String* what) {
	$init(ModuleDescriptor);
	$useLocalCurrentObjectStackCache();
	$var($Stream, var$0, $nc($($nc(mods)->stream()))->map(static_cast<$Function*>($$new(ModuleDescriptor$$Lambda$lambda$toString$0$1))));
	return $cast($String, $nc(($($Stream::concat(var$0, $($Stream::of($of(what)))))))->collect($($Collectors::joining(" "_s))));
}

int32_t ModuleDescriptor::compare(Object$* obj1, Object$* obj2) {
	$init(ModuleDescriptor);
	if (obj1 != nullptr) {
		return (obj2 != nullptr) ? $nc(($cast($Comparable, obj1)))->compareTo(obj2) : 1;
	} else {
		return (obj2 == nullptr) ? 0 : -1;
	}
}

int32_t ModuleDescriptor::compare($Set* s1, $Set* s2) {
	$init(ModuleDescriptor);
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, a1, $nc(s1)->toArray());
	$var($ObjectArray, a2, $nc(s2)->toArray());
	$Arrays::sort(a1);
	$Arrays::sort(a2);
	return $Arrays::compare($fcast($ComparableArray, a1), $fcast($ComparableArray, a2));
}

int64_t ModuleDescriptor::modsValue($Set* set) {
	$init(ModuleDescriptor);
	$useLocalCurrentObjectStackCache();
	int64_t value = 0;
	{
		$var($Iterator, i$, $nc(set)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Enum, e, $cast($Enum, i$->next()));
			{
				value += $sl(1, $nc(e)->ordinal());
			}
		}
	}
	return value;
}

int32_t ModuleDescriptor::compareTo(Object$* that) {
	return this->compareTo($cast(ModuleDescriptor, that));
}

$String* ModuleDescriptor::lambda$toString$0(Object$* e) {
	$init(ModuleDescriptor);
	$init($Locale);
	return $nc($($nc($of(e))->toString()))->toLowerCase($Locale::ROOT);
}

void clinit$ModuleDescriptor($Class* class$) {
	ModuleDescriptor::$assertionsDisabled = !ModuleDescriptor::class$->desiredAssertionStatus();
	{
		$SharedSecrets::setJavaLangModuleAccess($$new($ModuleDescriptor$1));
	}
}

ModuleDescriptor::ModuleDescriptor() {
}

$Class* ModuleDescriptor::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ModuleDescriptor$$Lambda$name::classInfo$.name)) {
			return ModuleDescriptor$$Lambda$name::load$(name, initialize);
		}
		if (name->equals(ModuleDescriptor$$Lambda$lambda$toString$0$1::classInfo$.name)) {
			return ModuleDescriptor$$Lambda$lambda$toString$0$1::load$(name, initialize);
		}
	}
	$loadClass(ModuleDescriptor, name, initialize, &_ModuleDescriptor_ClassInfo_, clinit$ModuleDescriptor, allocate$ModuleDescriptor);
	return class$;
}

$Class* ModuleDescriptor::class$ = nullptr;

		} // module
	} // lang
} // java