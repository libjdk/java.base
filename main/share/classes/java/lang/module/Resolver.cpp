#include <java/lang/module/Resolver.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/ModuleLayer.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/Configuration.h>
#include <java/lang/module/FindException.h>
#include <java/lang/module/ModuleDescriptor$Exports.h>
#include <java/lang/module/ModuleDescriptor$Provides.h>
#include <java/lang/module/ModuleDescriptor$Requires$Modifier.h>
#include <java/lang/module/ModuleDescriptor$Requires.h>
#include <java/lang/module/ModuleDescriptor.h>
#include <java/lang/module/ModuleFinder.h>
#include <java/lang/module/ModuleReference.h>
#include <java/lang/module/ResolutionException.h>
#include <java/lang/module/ResolvedModule.h>
#include <java/net/URI.h>
#include <java/util/ArrayDeque.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Deque.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/HexFormat.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashSet.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/module/ModuleHashes.h>
#include <jdk/internal/module/ModuleReferenceImpl.h>
#include <jdk/internal/module/ModuleResolution.h>
#include <jdk/internal/module/ModuleTarget.h>
#include <jcpp.h>

#undef STATIC
#undef TRANSITIVE

using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $ModuleLayer = ::java::lang::ModuleLayer;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Configuration = ::java::lang::module::Configuration;
using $FindException = ::java::lang::module::FindException;
using $ModuleDescriptor = ::java::lang::module::ModuleDescriptor;
using $ModuleDescriptor$Exports = ::java::lang::module::ModuleDescriptor$Exports;
using $ModuleDescriptor$Provides = ::java::lang::module::ModuleDescriptor$Provides;
using $ModuleDescriptor$Requires = ::java::lang::module::ModuleDescriptor$Requires;
using $ModuleDescriptor$Requires$Modifier = ::java::lang::module::ModuleDescriptor$Requires$Modifier;
using $ModuleFinder = ::java::lang::module::ModuleFinder;
using $ModuleReference = ::java::lang::module::ModuleReference;
using $ResolutionException = ::java::lang::module::ResolutionException;
using $ResolvedModule = ::java::lang::module::ResolvedModule;
using $URI = ::java::net::URI;
using $ArrayDeque = ::java::util::ArrayDeque;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Deque = ::java::util::Deque;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $HexFormat = ::java::util::HexFormat;
using $Iterator = ::java::util::Iterator;
using $LinkedHashSet = ::java::util::LinkedHashSet;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $Supplier = ::java::util::function::Supplier;
using $Collectors = ::java::util::stream::Collectors;
using $Stream = ::java::util::stream::Stream;
using $ModuleHashes = ::jdk::internal::module::ModuleHashes;
using $ModuleReferenceImpl = ::jdk::internal::module::ModuleReferenceImpl;
using $ModuleResolution = ::jdk::internal::module::ModuleResolution;
using $ModuleTarget = ::jdk::internal::module::ModuleTarget;

namespace java {
	namespace lang {
		namespace module {

class Resolver$$Lambda$lambda$resolve$0 : public $Consumer {
	$class(Resolver$$Lambda$lambda$resolve$0, $NO_CLASS_INIT, $Consumer)
public:
	void init$(Resolver* inst, $Deque* q, $ModuleDescriptor* descriptor) {
		$set(this, inst$, inst);
		$set(this, q, q);
		$set(this, descriptor, descriptor);
	}
	virtual void accept(Object$* mref) override {
		$nc(inst$)->lambda$resolve$0(q, descriptor, $cast($ModuleReference, mref));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Resolver$$Lambda$lambda$resolve$0>());
	}
	Resolver* inst$ = nullptr;
	$Deque* q = nullptr;
	$ModuleDescriptor* descriptor = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Resolver$$Lambda$lambda$resolve$0::fieldInfos[4] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Resolver$$Lambda$lambda$resolve$0, inst$)},
	{"q", "Ljava/util/Deque;", nullptr, $PUBLIC, $field(Resolver$$Lambda$lambda$resolve$0, q)},
	{"descriptor", "Ljava/lang/module/ModuleDescriptor;", nullptr, $PUBLIC, $field(Resolver$$Lambda$lambda$resolve$0, descriptor)},
	{}
};
$MethodInfo Resolver$$Lambda$lambda$resolve$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/module/Resolver;Ljava/util/Deque;Ljava/lang/module/ModuleDescriptor;)V", nullptr, $PUBLIC, $method(Resolver$$Lambda$lambda$resolve$0, init$, void, Resolver*, $Deque*, $ModuleDescriptor*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Resolver$$Lambda$lambda$resolve$0, accept, void, Object$*)},
	{}
};
$ClassInfo Resolver$$Lambda$lambda$resolve$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Resolver$$Lambda$lambda$resolve$0",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* Resolver$$Lambda$lambda$resolve$0::load$($String* name, bool initialize) {
	$loadClass(Resolver$$Lambda$lambda$resolve$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Resolver$$Lambda$lambda$resolve$0::class$ = nullptr;

class Resolver$$Lambda$configurations$1 : public $Function {
	$class(Resolver$$Lambda$configurations$1, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($Configuration, inst$)->configurations());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Resolver$$Lambda$configurations$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Resolver$$Lambda$configurations$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Resolver$$Lambda$configurations$1, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Resolver$$Lambda$configurations$1, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Resolver$$Lambda$configurations$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Resolver$$Lambda$configurations$1",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Resolver$$Lambda$configurations$1::load$($String* name, bool initialize) {
	$loadClass(Resolver$$Lambda$configurations$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Resolver$$Lambda$configurations$1::class$ = nullptr;

class Resolver$$Lambda$lambda$bind$1$2 : public $Function {
	$class(Resolver$$Lambda$lambda$bind$1$2, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* c) override {
		 return $of(Resolver::lambda$bind$1($cast($Configuration, c)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Resolver$$Lambda$lambda$bind$1$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Resolver$$Lambda$lambda$bind$1$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Resolver$$Lambda$lambda$bind$1$2, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Resolver$$Lambda$lambda$bind$1$2, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Resolver$$Lambda$lambda$bind$1$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Resolver$$Lambda$lambda$bind$1$2",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Resolver$$Lambda$lambda$bind$1$2::load$($String* name, bool initialize) {
	$loadClass(Resolver$$Lambda$lambda$bind$1$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Resolver$$Lambda$lambda$bind$1$2::class$ = nullptr;

class Resolver$$Lambda$lambda$addFoundAutomaticModules$2$3 : public $Consumer {
	$class(Resolver$$Lambda$lambda$addFoundAutomaticModules$2$3, $NO_CLASS_INIT, $Consumer)
public:
	void init$(Resolver* inst, $Set* result) {
		$set(this, inst$, inst);
		$set(this, result, result);
	}
	virtual void accept(Object$* mref) override {
		$nc(inst$)->lambda$addFoundAutomaticModules$2(result, $cast($ModuleReference, mref));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Resolver$$Lambda$lambda$addFoundAutomaticModules$2$3>());
	}
	Resolver* inst$ = nullptr;
	$Set* result = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Resolver$$Lambda$lambda$addFoundAutomaticModules$2$3::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Resolver$$Lambda$lambda$addFoundAutomaticModules$2$3, inst$)},
	{"result", "Ljava/util/Set;", nullptr, $PUBLIC, $field(Resolver$$Lambda$lambda$addFoundAutomaticModules$2$3, result)},
	{}
};
$MethodInfo Resolver$$Lambda$lambda$addFoundAutomaticModules$2$3::methodInfos[3] = {
	{"<init>", "(Ljava/lang/module/Resolver;Ljava/util/Set;)V", nullptr, $PUBLIC, $method(Resolver$$Lambda$lambda$addFoundAutomaticModules$2$3, init$, void, Resolver*, $Set*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Resolver$$Lambda$lambda$addFoundAutomaticModules$2$3, accept, void, Object$*)},
	{}
};
$ClassInfo Resolver$$Lambda$lambda$addFoundAutomaticModules$2$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Resolver$$Lambda$lambda$addFoundAutomaticModules$2$3",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* Resolver$$Lambda$lambda$addFoundAutomaticModules$2$3::load$($String* name, bool initialize) {
	$loadClass(Resolver$$Lambda$lambda$addFoundAutomaticModules$2$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Resolver$$Lambda$lambda$addFoundAutomaticModules$2$3::class$ = nullptr;

class Resolver$$Lambda$name$4 : public $Function {
	$class(Resolver$$Lambda$name$4, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($ModuleDescriptor, inst$)->name());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Resolver$$Lambda$name$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Resolver$$Lambda$name$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Resolver$$Lambda$name$4, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Resolver$$Lambda$name$4, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Resolver$$Lambda$name$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Resolver$$Lambda$name$4",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Resolver$$Lambda$name$4::load$($String* name, bool initialize) {
	$loadClass(Resolver$$Lambda$name$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Resolver$$Lambda$name$4::class$ = nullptr;

class Resolver$$Lambda$lambda$makeGraph$7$5 : public $Function {
	$class(Resolver$$Lambda$lambda$makeGraph$7$5, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* c) override {
		 return $of(Resolver::lambda$makeGraph$7($cast($Configuration, c)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Resolver$$Lambda$lambda$makeGraph$7$5>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Resolver$$Lambda$lambda$makeGraph$7$5::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Resolver$$Lambda$lambda$makeGraph$7$5, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Resolver$$Lambda$lambda$makeGraph$7$5, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Resolver$$Lambda$lambda$makeGraph$7$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Resolver$$Lambda$lambda$makeGraph$7$5",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Resolver$$Lambda$lambda$makeGraph$7$5::load$($String* name, bool initialize) {
	$loadClass(Resolver$$Lambda$lambda$makeGraph$7$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Resolver$$Lambda$lambda$makeGraph$7$5::class$ = nullptr;

class Resolver$$Lambda$getKey$6 : public $Function {
	$class(Resolver$$Lambda$getKey$6, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $sure($Map$Entry, inst$)->getKey();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Resolver$$Lambda$getKey$6>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Resolver$$Lambda$getKey$6::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Resolver$$Lambda$getKey$6, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Resolver$$Lambda$getKey$6, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Resolver$$Lambda$getKey$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Resolver$$Lambda$getKey$6",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Resolver$$Lambda$getKey$6::load$($String* name, bool initialize) {
	$loadClass(Resolver$$Lambda$getKey$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Resolver$$Lambda$getKey$6::class$ = nullptr;

class Resolver$$Lambda$HashMap$7 : public $Supplier {
	$class(Resolver$$Lambda$HashMap$7, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of($new($HashMap));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Resolver$$Lambda$HashMap$7>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Resolver$$Lambda$HashMap$7::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Resolver$$Lambda$HashMap$7, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Resolver$$Lambda$HashMap$7, get, $Object*)},
	{}
};
$ClassInfo Resolver$$Lambda$HashMap$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Resolver$$Lambda$HashMap$7",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* Resolver$$Lambda$HashMap$7::load$($String* name, bool initialize) {
	$loadClass(Resolver$$Lambda$HashMap$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Resolver$$Lambda$HashMap$7::class$ = nullptr;

class Resolver$$Lambda$getValue$8 : public $Function {
	$class(Resolver$$Lambda$getValue$8, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $sure($Map$Entry, inst$)->getValue();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Resolver$$Lambda$getValue$8>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Resolver$$Lambda$getValue$8::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Resolver$$Lambda$getValue$8, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Resolver$$Lambda$getValue$8, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Resolver$$Lambda$getValue$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Resolver$$Lambda$getValue$8",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Resolver$$Lambda$getValue$8::load$($String* name, bool initialize) {
	$loadClass(Resolver$$Lambda$getValue$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Resolver$$Lambda$getValue$8::class$ = nullptr;

class Resolver$$Lambda$lambda$makeGraph$8$9 : public $Predicate {
	$class(Resolver$$Lambda$lambda$makeGraph$8$9, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* d) override {
		 return Resolver::lambda$makeGraph$8($cast($ResolvedModule, d));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Resolver$$Lambda$lambda$makeGraph$8$9>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Resolver$$Lambda$lambda$makeGraph$8$9::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Resolver$$Lambda$lambda$makeGraph$8$9, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Resolver$$Lambda$lambda$makeGraph$8$9, test, bool, Object$*)},
	{}
};
$ClassInfo Resolver$$Lambda$lambda$makeGraph$8$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Resolver$$Lambda$lambda$makeGraph$8$9",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* Resolver$$Lambda$lambda$makeGraph$8$9::load$($String* name, bool initialize) {
	$loadClass(Resolver$$Lambda$lambda$makeGraph$8$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Resolver$$Lambda$lambda$makeGraph$8$9::class$ = nullptr;

class Resolver$$Lambda$add$10 : public $Consumer {
	$class(Resolver$$Lambda$add$10, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Set* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* e) override {
		$nc(inst$)->add(e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Resolver$$Lambda$add$10>());
	}
	$Set* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Resolver$$Lambda$add$10::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Resolver$$Lambda$add$10, inst$)},
	{}
};
$MethodInfo Resolver$$Lambda$add$10::methodInfos[3] = {
	{"<init>", "(Ljava/util/Set;)V", nullptr, $PUBLIC, $method(Resolver$$Lambda$add$10, init$, void, $Set*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Resolver$$Lambda$add$10, accept, void, Object$*)},
	{}
};
$ClassInfo Resolver$$Lambda$add$10::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Resolver$$Lambda$add$10",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* Resolver$$Lambda$add$10::load$($String* name, bool initialize) {
	$loadClass(Resolver$$Lambda$add$10, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Resolver$$Lambda$add$10::class$ = nullptr;

class Resolver$$Lambda$modules$11 : public $Function {
	$class(Resolver$$Lambda$modules$11, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($Configuration, inst$)->modules());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Resolver$$Lambda$modules$11>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Resolver$$Lambda$modules$11::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Resolver$$Lambda$modules$11, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Resolver$$Lambda$modules$11, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Resolver$$Lambda$modules$11::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Resolver$$Lambda$modules$11",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Resolver$$Lambda$modules$11::load$($String* name, bool initialize) {
	$loadClass(Resolver$$Lambda$modules$11, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Resolver$$Lambda$modules$11::class$ = nullptr;

class Resolver$$Lambda$stream$12 : public $Function {
	$class(Resolver$$Lambda$stream$12, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($Collection, inst$)->stream());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Resolver$$Lambda$stream$12>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Resolver$$Lambda$stream$12::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Resolver$$Lambda$stream$12, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Resolver$$Lambda$stream$12, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Resolver$$Lambda$stream$12::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Resolver$$Lambda$stream$12",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Resolver$$Lambda$stream$12::load$($String* name, bool initialize) {
	$loadClass(Resolver$$Lambda$stream$12, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Resolver$$Lambda$stream$12::class$ = nullptr;

class Resolver$$Lambda$lambda$makeGraph$9$13 : public $Consumer {
	$class(Resolver$$Lambda$lambda$makeGraph$9$13, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Set* reads, $Set* requiresTransitive) {
		$set(this, reads, reads);
		$set(this, requiresTransitive, requiresTransitive);
	}
	virtual void accept(Object$* m) override {
		Resolver::lambda$makeGraph$9(reads, requiresTransitive, $cast($ResolvedModule, m));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Resolver$$Lambda$lambda$makeGraph$9$13>());
	}
	$Set* reads = nullptr;
	$Set* requiresTransitive = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Resolver$$Lambda$lambda$makeGraph$9$13::fieldInfos[3] = {
	{"reads", "Ljava/util/Set;", nullptr, $PUBLIC, $field(Resolver$$Lambda$lambda$makeGraph$9$13, reads)},
	{"requiresTransitive", "Ljava/util/Set;", nullptr, $PUBLIC, $field(Resolver$$Lambda$lambda$makeGraph$9$13, requiresTransitive)},
	{}
};
$MethodInfo Resolver$$Lambda$lambda$makeGraph$9$13::methodInfos[3] = {
	{"<init>", "(Ljava/util/Set;Ljava/util/Set;)V", nullptr, $PUBLIC, $method(Resolver$$Lambda$lambda$makeGraph$9$13, init$, void, $Set*, $Set*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Resolver$$Lambda$lambda$makeGraph$9$13, accept, void, Object$*)},
	{}
};
$ClassInfo Resolver$$Lambda$lambda$makeGraph$9$13::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Resolver$$Lambda$lambda$makeGraph$9$13",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* Resolver$$Lambda$lambda$makeGraph$9$13::load$($String* name, bool initialize) {
	$loadClass(Resolver$$Lambda$lambda$makeGraph$9$13, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Resolver$$Lambda$lambda$makeGraph$9$13::class$ = nullptr;

class Resolver$$Lambda$lambda$nameAndInfo$10$14 : public $Consumer {
	$class(Resolver$$Lambda$lambda$nameAndInfo$10$14, $NO_CLASS_INIT, $Consumer)
public:
	void init$($StringBuilder* sb) {
		$set(this, sb, sb);
	}
	virtual void accept(Object$* uri) override {
		Resolver::lambda$nameAndInfo$10(sb, $cast($URI, uri));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Resolver$$Lambda$lambda$nameAndInfo$10$14>());
	}
	$StringBuilder* sb = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Resolver$$Lambda$lambda$nameAndInfo$10$14::fieldInfos[2] = {
	{"sb", "Ljava/lang/StringBuilder;", nullptr, $PUBLIC, $field(Resolver$$Lambda$lambda$nameAndInfo$10$14, sb)},
	{}
};
$MethodInfo Resolver$$Lambda$lambda$nameAndInfo$10$14::methodInfos[3] = {
	{"<init>", "(Ljava/lang/StringBuilder;)V", nullptr, $PUBLIC, $method(Resolver$$Lambda$lambda$nameAndInfo$10$14, init$, void, $StringBuilder*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Resolver$$Lambda$lambda$nameAndInfo$10$14, accept, void, Object$*)},
	{}
};
$ClassInfo Resolver$$Lambda$lambda$nameAndInfo$10$14::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Resolver$$Lambda$lambda$nameAndInfo$10$14",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* Resolver$$Lambda$lambda$nameAndInfo$10$14::load$($String* name, bool initialize) {
	$loadClass(Resolver$$Lambda$lambda$nameAndInfo$10$14, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Resolver$$Lambda$lambda$nameAndInfo$10$14::class$ = nullptr;

class Resolver$$Lambda$lambda$makeGraph$6$15 : public $Function {
	$class(Resolver$$Lambda$lambda$makeGraph$6$15, $NO_CLASS_INIT, $Function)
public:
	void init$($Configuration* c) {
		$set(this, c, c);
	}
	virtual $Object* apply(Object$* m1) override {
		 return $of(Resolver::lambda$makeGraph$6(c, $cast($ResolvedModule, m1)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Resolver$$Lambda$lambda$makeGraph$6$15>());
	}
	$Configuration* c = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Resolver$$Lambda$lambda$makeGraph$6$15::fieldInfos[2] = {
	{"c", "Ljava/lang/module/Configuration;", nullptr, $PUBLIC, $field(Resolver$$Lambda$lambda$makeGraph$6$15, c)},
	{}
};
$MethodInfo Resolver$$Lambda$lambda$makeGraph$6$15::methodInfos[3] = {
	{"<init>", "(Ljava/lang/module/Configuration;)V", nullptr, $PUBLIC, $method(Resolver$$Lambda$lambda$makeGraph$6$15, init$, void, $Configuration*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Resolver$$Lambda$lambda$makeGraph$6$15, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Resolver$$Lambda$lambda$makeGraph$6$15::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Resolver$$Lambda$lambda$makeGraph$6$15",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Resolver$$Lambda$lambda$makeGraph$6$15::load$($String* name, bool initialize) {
	$loadClass(Resolver$$Lambda$lambda$makeGraph$6$15, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Resolver$$Lambda$lambda$makeGraph$6$15::class$ = nullptr;

class Resolver$$Lambda$lambda$makeGraph$3$16 : public $Predicate {
	$class(Resolver$$Lambda$lambda$makeGraph$3$16, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* r) override {
		 return Resolver::lambda$makeGraph$3($cast($ModuleDescriptor$Requires, r));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Resolver$$Lambda$lambda$makeGraph$3$16>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Resolver$$Lambda$lambda$makeGraph$3$16::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Resolver$$Lambda$lambda$makeGraph$3$16, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Resolver$$Lambda$lambda$makeGraph$3$16, test, bool, Object$*)},
	{}
};
$ClassInfo Resolver$$Lambda$lambda$makeGraph$3$16::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Resolver$$Lambda$lambda$makeGraph$3$16",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* Resolver$$Lambda$lambda$makeGraph$3$16::load$($String* name, bool initialize) {
	$loadClass(Resolver$$Lambda$lambda$makeGraph$3$16, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Resolver$$Lambda$lambda$makeGraph$3$16::class$ = nullptr;

class Resolver$$Lambda$lambda$makeGraph$4$17 : public $Function {
	$class(Resolver$$Lambda$lambda$makeGraph$4$17, $NO_CLASS_INIT, $Function)
public:
	void init$($Configuration* c) {
		$set(this, c, c);
	}
	virtual $Object* apply(Object$* r) override {
		 return $of(Resolver::lambda$makeGraph$4(c, $cast($ModuleDescriptor$Requires, r)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Resolver$$Lambda$lambda$makeGraph$4$17>());
	}
	$Configuration* c = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Resolver$$Lambda$lambda$makeGraph$4$17::fieldInfos[2] = {
	{"c", "Ljava/lang/module/Configuration;", nullptr, $PUBLIC, $field(Resolver$$Lambda$lambda$makeGraph$4$17, c)},
	{}
};
$MethodInfo Resolver$$Lambda$lambda$makeGraph$4$17::methodInfos[3] = {
	{"<init>", "(Ljava/lang/module/Configuration;)V", nullptr, $PUBLIC, $method(Resolver$$Lambda$lambda$makeGraph$4$17, init$, void, $Configuration*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Resolver$$Lambda$lambda$makeGraph$4$17, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Resolver$$Lambda$lambda$makeGraph$4$17::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Resolver$$Lambda$lambda$makeGraph$4$17",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Resolver$$Lambda$lambda$makeGraph$4$17::load$($String* name, bool initialize) {
	$loadClass(Resolver$$Lambda$lambda$makeGraph$4$17, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Resolver$$Lambda$lambda$makeGraph$4$17::class$ = nullptr;

class Resolver$$Lambda$lambda$makeGraph$5$18 : public $Function {
	$class(Resolver$$Lambda$lambda$makeGraph$5$18, $NO_CLASS_INIT, $Function)
public:
	void init$($ResolvedModule* m1) {
		$set(this, m1, m1);
	}
	virtual $Object* apply(Object$* m2) override {
		 return $of(Resolver::lambda$makeGraph$5(m1, $cast($ResolvedModule, m2)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Resolver$$Lambda$lambda$makeGraph$5$18>());
	}
	$ResolvedModule* m1 = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Resolver$$Lambda$lambda$makeGraph$5$18::fieldInfos[2] = {
	{"m1", "Ljava/lang/module/ResolvedModule;", nullptr, $PUBLIC, $field(Resolver$$Lambda$lambda$makeGraph$5$18, m1)},
	{}
};
$MethodInfo Resolver$$Lambda$lambda$makeGraph$5$18::methodInfos[3] = {
	{"<init>", "(Ljava/lang/module/ResolvedModule;)V", nullptr, $PUBLIC, $method(Resolver$$Lambda$lambda$makeGraph$5$18, init$, void, $ResolvedModule*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Resolver$$Lambda$lambda$makeGraph$5$18, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Resolver$$Lambda$lambda$makeGraph$5$18::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.Resolver$$Lambda$lambda$makeGraph$5$18",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Resolver$$Lambda$lambda$makeGraph$5$18::load$($String* name, bool initialize) {
	$loadClass(Resolver$$Lambda$lambda$makeGraph$5$18, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Resolver$$Lambda$lambda$makeGraph$5$18::class$ = nullptr;

$FieldInfo _Resolver_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Resolver, $assertionsDisabled)},
	{"beforeFinder", "Ljava/lang/module/ModuleFinder;", nullptr, $PRIVATE | $FINAL, $field(Resolver, beforeFinder)},
	{"parents", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/module/Configuration;>;", $PRIVATE | $FINAL, $field(Resolver, parents)},
	{"afterFinder", "Ljava/lang/module/ModuleFinder;", nullptr, $PRIVATE | $FINAL, $field(Resolver, afterFinder)},
	{"traceOutput", "Ljava/io/PrintStream;", nullptr, $PRIVATE | $FINAL, $field(Resolver, traceOutput)},
	{"nameToReference", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/module/ModuleReference;>;", $PRIVATE | $FINAL, $field(Resolver, nameToReference)},
	{"haveAllAutomaticModules", "Z", nullptr, $PRIVATE, $field(Resolver, haveAllAutomaticModules)},
	{"targetPlatform", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Resolver, targetPlatform$)},
	{"visited", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/module/ModuleDescriptor;>;", $PRIVATE, $field(Resolver, visited)},
	{"visitPath", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/module/ModuleDescriptor;>;", $PRIVATE, $field(Resolver, visitPath)},
	{}
};

$MethodInfo _Resolver_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/module/ModuleFinder;Ljava/util/List;Ljava/lang/module/ModuleFinder;Ljava/io/PrintStream;)V", "(Ljava/lang/module/ModuleFinder;Ljava/util/List<Ljava/lang/module/Configuration;>;Ljava/lang/module/ModuleFinder;Ljava/io/PrintStream;)V", 0, $method(Resolver, init$, void, $ModuleFinder*, $List*, $ModuleFinder*, $PrintStream*)},
	{"addFoundAutomaticModules", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/module/ModuleReference;>;", $PRIVATE, $method(Resolver, addFoundAutomaticModules, $Set*)},
	{"addFoundModule", "(Ljava/lang/module/ModuleReference;)V", nullptr, $PRIVATE, $method(Resolver, addFoundModule, void, $ModuleReference*)},
	{"bind", "()Ljava/lang/module/Resolver;", nullptr, 0, $method(Resolver, bind, Resolver*)},
	{"bind", "(Z)Ljava/lang/module/Resolver;", nullptr, 0, $method(Resolver, bind, Resolver*, bool)},
	{"checkExportSuppliers", "(Ljava/util/Map;)V", "(Ljava/util/Map<Ljava/lang/module/ResolvedModule;Ljava/util/Set<Ljava/lang/module/ResolvedModule;>;>;)V", $PRIVATE, $method(Resolver, checkExportSuppliers, void, $Map*)},
	{"checkHashes", "()V", nullptr, $PRIVATE, $method(Resolver, checkHashes, void)},
	{"checkTargetPlatform", "(Ljava/lang/String;Ljdk/internal/module/ModuleTarget;)V", nullptr, $PRIVATE, $method(Resolver, checkTargetPlatform, void, $String*, $ModuleTarget*)},
	{"computeIfAbsent", "(Ljava/util/Map;Ljava/lang/String;Ljava/lang/module/Configuration;Ljava/lang/module/ModuleReference;)Ljava/lang/module/ResolvedModule;", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/module/ResolvedModule;>;Ljava/lang/String;Ljava/lang/module/Configuration;Ljava/lang/module/ModuleReference;)Ljava/lang/module/ResolvedModule;", $PRIVATE, $method(Resolver, computeIfAbsent, $ResolvedModule*, $Map*, $String*, $Configuration*, $ModuleReference*)},
	{"cycleAsString", "(Ljava/lang/module/ModuleDescriptor;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Resolver, cycleAsString, $String*, $ModuleDescriptor*)},
	{"detectCycles", "()V", nullptr, $PRIVATE, $method(Resolver, detectCycles, void)},
	{"failTwoSuppliers", "(Ljava/lang/module/ModuleDescriptor;Ljava/lang/String;Ljava/lang/module/ModuleDescriptor;Ljava/lang/module/ModuleDescriptor;)V", nullptr, $PRIVATE, $method(Resolver, failTwoSuppliers, void, $ModuleDescriptor*, $String*, $ModuleDescriptor*, $ModuleDescriptor*)},
	{"findAll", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/module/ModuleReference;>;", $PRIVATE, $method(Resolver, findAll, $Set*)},
	{"findFail", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(Resolver, findFail, void, $String*, $ObjectArray*)},
	{"findInParent", "(Ljava/lang/String;)Ljava/lang/module/ResolvedModule;", nullptr, $PRIVATE, $method(Resolver, findInParent, $ResolvedModule*, $String*)},
	{"findWithAfterFinder", "(Ljava/lang/String;)Ljava/lang/module/ModuleReference;", nullptr, $PRIVATE, $method(Resolver, findWithAfterFinder, $ModuleReference*, $String*)},
	{"findWithBeforeFinder", "(Ljava/lang/String;)Ljava/lang/module/ModuleReference;", nullptr, $PRIVATE, $method(Resolver, findWithBeforeFinder, $ModuleReference*, $String*)},
	{"finish", "(Ljava/lang/module/Configuration;)Ljava/util/Map;", "(Ljava/lang/module/Configuration;)Ljava/util/Map<Ljava/lang/module/ResolvedModule;Ljava/util/Set<Ljava/lang/module/ResolvedModule;>;>;", 0, $method(Resolver, finish, $Map*, $Configuration*)},
	{"isTracing", "()Z", nullptr, $PRIVATE, $method(Resolver, isTracing, bool)},
	{"lambda$addFoundAutomaticModules$2", "(Ljava/util/Set;Ljava/lang/module/ModuleReference;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(Resolver, lambda$addFoundAutomaticModules$2, void, $Set*, $ModuleReference*)},
	{"lambda$bind$1", "(Ljava/lang/module/Configuration;)Ljava/util/stream/Stream;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Resolver, lambda$bind$1, $Stream*, $Configuration*)},
	{"lambda$makeGraph$3", "(Ljava/lang/module/ModuleDescriptor$Requires;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Resolver, lambda$makeGraph$3, bool, $ModuleDescriptor$Requires*)},
	{"lambda$makeGraph$4", "(Ljava/lang/module/Configuration;Ljava/lang/module/ModuleDescriptor$Requires;)Ljava/util/stream/Stream;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Resolver, lambda$makeGraph$4, $Stream*, $Configuration*, $ModuleDescriptor$Requires*)},
	{"lambda$makeGraph$5", "(Ljava/lang/module/ResolvedModule;Ljava/lang/module/ResolvedModule;)Ljava/util/Map$Entry;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Resolver, lambda$makeGraph$5, $Map$Entry*, $ResolvedModule*, $ResolvedModule*)},
	{"lambda$makeGraph$6", "(Ljava/lang/module/Configuration;Ljava/lang/module/ResolvedModule;)Ljava/util/stream/Stream;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Resolver, lambda$makeGraph$6, $Stream*, $Configuration*, $ResolvedModule*)},
	{"lambda$makeGraph$7", "(Ljava/lang/module/Configuration;)Ljava/util/stream/Stream;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Resolver, lambda$makeGraph$7, $Stream*, $Configuration*)},
	{"lambda$makeGraph$8", "(Ljava/lang/module/ResolvedModule;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Resolver, lambda$makeGraph$8, bool, $ResolvedModule*)},
	{"lambda$makeGraph$9", "(Ljava/util/Set;Ljava/util/Set;Ljava/lang/module/ResolvedModule;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Resolver, lambda$makeGraph$9, void, $Set*, $Set*, $ResolvedModule*)},
	{"lambda$nameAndInfo$10", "(Ljava/lang/StringBuilder;Ljava/net/URI;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Resolver, lambda$nameAndInfo$10, void, $StringBuilder*, $URI*)},
	{"lambda$resolve$0", "(Ljava/util/Deque;Ljava/lang/module/ModuleDescriptor;Ljava/lang/module/ModuleReference;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(Resolver, lambda$resolve$0, void, $Deque*, $ModuleDescriptor*, $ModuleReference*)},
	{"makeGraph", "(Ljava/lang/module/Configuration;)Ljava/util/Map;", "(Ljava/lang/module/Configuration;)Ljava/util/Map<Ljava/lang/module/ResolvedModule;Ljava/util/Set<Ljava/lang/module/ResolvedModule;>;>;", $PRIVATE, $method(Resolver, makeGraph, $Map*, $Configuration*)},
	{"nameAndInfo", "(Ljava/lang/module/ModuleReference;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Resolver, nameAndInfo, $String*, $ModuleReference*)},
	{"packageName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Resolver, packageName, $String*, $String*)},
	{"resolve", "(Ljava/util/Collection;)Ljava/lang/module/Resolver;", "(Ljava/util/Collection<Ljava/lang/String;>;)Ljava/lang/module/Resolver;", 0, $method(Resolver, resolve, Resolver*, $Collection*)},
	{"resolve", "(Ljava/util/Deque;)Ljava/util/Set;", "(Ljava/util/Deque<Ljava/lang/module/ModuleDescriptor;>;)Ljava/util/Set<Ljava/lang/module/ModuleDescriptor;>;", $PRIVATE, $method(Resolver, resolve, $Set*, $Deque*)},
	{"resolveFail", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(Resolver, resolveFail, void, $String*, $ObjectArray*)},
	{"targetPlatform", "()Ljava/lang/String;", nullptr, 0, $method(Resolver, targetPlatform, $String*)},
	{"trace", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PRIVATE | $TRANSIENT, $method(Resolver, trace, void, $String*, $ObjectArray*)},
	{"visit", "(Ljava/lang/module/ModuleDescriptor;)V", nullptr, $PRIVATE, $method(Resolver, visit, void, $ModuleDescriptor*)},
	{}
};

$ClassInfo _Resolver_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.lang.module.Resolver",
	"java.lang.Object",
	nullptr,
	_Resolver_FieldInfo_,
	_Resolver_MethodInfo_
};

$Object* allocate$Resolver($Class* clazz) {
	return $of($alloc(Resolver));
}

bool Resolver::$assertionsDisabled = false;

$String* Resolver::targetPlatform() {
	return this->targetPlatform$;
}

void Resolver::init$($ModuleFinder* beforeFinder, $List* parents, $ModuleFinder* afterFinder, $PrintStream* traceOutput) {
	$useLocalCurrentObjectStackCache();
	$set(this, nameToReference, $new($HashMap));
	$set(this, beforeFinder, beforeFinder);
	$set(this, parents, parents);
	$set(this, afterFinder, afterFinder);
	$set(this, traceOutput, traceOutput);
	{
		$var($Iterator, i$, $nc(parents)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Configuration, parent, $cast($Configuration, i$->next()));
			{
				$var($String, value, $nc(parent)->targetPlatform());
				if (value != nullptr) {
					if (this->targetPlatform$ == nullptr) {
						$set(this, targetPlatform$, value);
					} else if (!value->equals(this->targetPlatform$)) {
						$var($String, msg, $str({"Parents have conflicting constraints on target  platform: "_s, this->targetPlatform$, ", "_s, value}));
						$throwNew($IllegalArgumentException, msg);
					}
				}
			}
		}
	}
}

Resolver* Resolver::resolve($Collection* roots) {
	$useLocalCurrentObjectStackCache();
	$var($Deque, q, $new($ArrayDeque));
	{
		$var($Iterator, i$, $nc(roots)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, root, $cast($String, i$->next()));
			{
				$var($ModuleReference, mref, findWithBeforeFinder(root));
				if (mref == nullptr) {
					if (findInParent(root) != nullptr) {
						continue;
					}
					$assign(mref, findWithAfterFinder(root));
					if (mref == nullptr) {
						findFail("Module %s not found"_s, $$new($ObjectArray, {$of(root)}));
					}
				}
				if (isTracing()) {
					trace("root %s"_s, $$new($ObjectArray, {$($of(nameAndInfo(mref)))}));
				}
				addFoundModule(mref);
				q->push($($nc(mref)->descriptor()));
			}
		}
	}
	resolve(q);
	return this;
}

$Set* Resolver::resolve($Deque* q) {
	$useLocalCurrentObjectStackCache();
	$var($Set, resolved, $new($HashSet));
	while (!$nc(q)->isEmpty()) {
		$var($ModuleDescriptor, descriptor, $cast($ModuleDescriptor, q->poll()));
		if (!Resolver::$assertionsDisabled && !$nc(this->nameToReference)->containsKey($($nc(descriptor)->name()))) {
			$throwNew($AssertionError);
		}
		if ($nc(descriptor)->isAutomatic() && !this->haveAllAutomaticModules) {
			$nc($(addFoundAutomaticModules()))->forEach(static_cast<$Consumer*>($$new(Resolver$$Lambda$lambda$resolve$0, this, q, descriptor)));
			this->haveAllAutomaticModules = true;
		}
		{
			$var($Iterator, i$, $nc($($nc(descriptor)->requires()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($ModuleDescriptor$Requires, requires, $cast($ModuleDescriptor$Requires, i$->next()));
				{
					$init($ModuleDescriptor$Requires$Modifier);
					if ($nc($($nc(requires)->modifiers()))->contains($ModuleDescriptor$Requires$Modifier::STATIC)) {
						continue;
					}
					$var($String, dn, $nc(requires)->name());
					$var($ModuleReference, mref, findWithBeforeFinder(dn));
					if (mref == nullptr) {
						if (findInParent(dn) != nullptr) {
							continue;
						}
						$assign(mref, findWithAfterFinder(dn));
						if (mref == nullptr) {
							findFail("Module %s not found, required by %s"_s, $$new($ObjectArray, {
								$of(dn),
								$($of(descriptor->name()))
							}));
						}
					}
					bool var$0 = isTracing();
					if (var$0 && !$nc(dn)->equals("java.base"_s)) {
						trace("%s requires %s"_s, $$new($ObjectArray, {
							$($of(descriptor->name())),
							$($of(nameAndInfo(mref)))
						}));
					}
					if (!$nc(this->nameToReference)->containsKey(dn)) {
						addFoundModule(mref);
						q->offer($($nc(mref)->descriptor()));
					}
				}
			}
		}
		resolved->add(descriptor);
	}
	return resolved;
}

Resolver* Resolver::bind() {
	return bind(true);
}

Resolver* Resolver::bind(bool bindIncubatorModules) {
	$useLocalCurrentObjectStackCache();
	$var($Map, availableProviders, $new($HashMap));
	{
		$var($Iterator, i$, $nc($(findAll()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ModuleReference, mref, $cast($ModuleReference, i$->next()));
			{
				$var($ModuleDescriptor, descriptor, $nc(mref)->descriptor());
				bool candidate = false;
				if (!bindIncubatorModules && ($instanceOf($ModuleReferenceImpl, mref))) {
					$var($ModuleResolution, mres, $nc(($cast($ModuleReferenceImpl, mref)))->moduleResolution());
					candidate = (mres == nullptr) || ($nc(mres)->hasIncubatingWarning() == false);
				} else {
					candidate = true;
				}
				if (candidate && !$nc($($nc(descriptor)->provides()))->isEmpty()) {
					{
						$var($Iterator, i$, $nc($(descriptor->provides()))->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($ModuleDescriptor$Provides, provides, $cast($ModuleDescriptor$Provides, i$->next()));
							{
								$var($String, sn, $nc(provides)->service());
								$var($Set, providers, $cast($Set, availableProviders->get(sn)));
								if (providers == nullptr) {
									$assign(providers, $new($HashSet));
									availableProviders->put(sn, providers);
								}
								$nc(providers)->add(mref);
							}
						}
					}
				}
			}
		}
	}
	$var($Deque, q, $new($ArrayDeque));
	$var($Set, initialConsumers, nullptr);
	if ($ModuleLayer::boot() == nullptr) {
		$assign(initialConsumers, $new($HashSet));
	} else {
		$assign(initialConsumers, $cast($Set, $nc($($nc($($nc($($nc($($nc(this->parents)->stream()))->flatMap(static_cast<$Function*>($$new(Resolver$$Lambda$configurations$1)))))->distinct()))->flatMap(static_cast<$Function*>($$new(Resolver$$Lambda$lambda$bind$1$2)))))->collect($($Collectors::toSet()))));
	}
	{
		$var($Iterator, i$, $nc($($nc(this->nameToReference)->values()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ModuleReference, mref, $cast($ModuleReference, i$->next()));
			{
				$nc(initialConsumers)->add($($nc(mref)->descriptor()));
			}
		}
	}
	$var($Set, candidateConsumers, initialConsumers);
	do {
		{
			$var($Iterator, i$, $nc(candidateConsumers)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($ModuleDescriptor, descriptor, $cast($ModuleDescriptor, i$->next()));
				{
					if (!$nc($($nc(descriptor)->uses()))->isEmpty()) {
						$var($Set, modulesToBind, nullptr);
						if (isTracing()) {
							$assign(modulesToBind, $new($HashSet));
						}
						{
							$var($Iterator, i$, $nc($(descriptor->uses()))->iterator());
							for (; $nc(i$)->hasNext();) {
								$var($String, service, $cast($String, i$->next()));
								{
									$var($Set, mrefs, $cast($Set, availableProviders->get(service)));
									if (mrefs != nullptr) {
										{
											$var($Iterator, i$, mrefs->iterator());
											for (; $nc(i$)->hasNext();) {
												$var($ModuleReference, mref, $cast($ModuleReference, i$->next()));
												{
													$var($ModuleDescriptor, provider, $nc(mref)->descriptor());
													if (!$nc(provider)->equals(descriptor)) {
														bool var$0 = isTracing();
														if (var$0 && $nc(modulesToBind)->add(provider)) {
															trace("%s binds %s"_s, $$new($ObjectArray, {
																$($of(descriptor->name())),
																$($of(nameAndInfo(mref)))
															}));
														}
														$var($String, pn, provider->name());
														if (!$nc(this->nameToReference)->containsKey(pn)) {
															addFoundModule(mref);
															q->push(provider);
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		$assign(candidateConsumers, resolve(q));
	} while (!$nc(candidateConsumers)->isEmpty());
	return this;
}

$Set* Resolver::addFoundAutomaticModules() {
	$useLocalCurrentObjectStackCache();
	$var($Set, result, $new($HashSet));
	$nc($(findAll()))->forEach(static_cast<$Consumer*>($$new(Resolver$$Lambda$lambda$addFoundAutomaticModules$2$3, this, result)));
	return result;
}

void Resolver::addFoundModule($ModuleReference* mref) {
	$useLocalCurrentObjectStackCache();
	$var($String, mn, $nc($($nc(mref)->descriptor()))->name());
	if ($instanceOf($ModuleReferenceImpl, mref)) {
		$var($ModuleTarget, target, $nc(($cast($ModuleReferenceImpl, mref)))->moduleTarget());
		if (target != nullptr) {
			checkTargetPlatform(mn, target);
		}
	}
	$nc(this->nameToReference)->put(mn, mref);
}

void Resolver::checkTargetPlatform($String* mn, $ModuleTarget* target) {
	$useLocalCurrentObjectStackCache();
	$var($String, value, $nc(target)->targetPlatform());
	if (value != nullptr) {
		if (this->targetPlatform$ == nullptr) {
			$set(this, targetPlatform$, value);
		} else if (!value->equals(this->targetPlatform$)) {
			findFail("Module %s has constraints on target platform (%s) that conflict with other modules: %s"_s, $$new($ObjectArray, {
				$of(mn),
				$of(value),
				$of(this->targetPlatform$)
			}));
		}
	}
}

$Map* Resolver::finish($Configuration* cf) {
	detectCycles();
	checkHashes();
	$var($Map, graph, makeGraph(cf));
	checkExportSuppliers(graph);
	return graph;
}

void Resolver::detectCycles() {
	$useLocalCurrentObjectStackCache();
	$set(this, visited, $new($HashSet));
	$set(this, visitPath, $new($LinkedHashSet));
	{
		$var($Iterator, i$, $nc($($nc(this->nameToReference)->values()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ModuleReference, mref, $cast($ModuleReference, i$->next()));
			{
				visit($($nc(mref)->descriptor()));
			}
		}
	}
	$nc(this->visited)->clear();
}

void Resolver::visit($ModuleDescriptor* descriptor) {
	$useLocalCurrentObjectStackCache();
	if (!$nc(this->visited)->contains(descriptor)) {
		bool added = $nc(this->visitPath)->add(descriptor);
		if (!added) {
			resolveFail("Cycle detected: %s"_s, $$new($ObjectArray, {$($of(cycleAsString(descriptor)))}));
		}
		{
			$var($Iterator, i$, $nc($($nc(descriptor)->requires()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($ModuleDescriptor$Requires, requires, $cast($ModuleDescriptor$Requires, i$->next()));
				{
					$var($String, dn, $nc(requires)->name());
					$var($ModuleReference, mref, $cast($ModuleReference, $nc(this->nameToReference)->get(dn)));
					if (mref != nullptr) {
						$var($ModuleDescriptor, other, mref->descriptor());
						if (other != descriptor) {
							visit(other);
						}
					}
				}
			}
		}
		$nc(this->visitPath)->remove(descriptor);
		$nc(this->visited)->add(descriptor);
	}
}

$String* Resolver::cycleAsString($ModuleDescriptor* descriptor) {
	$useLocalCurrentObjectStackCache();
	$var($List, list, $new($ArrayList, static_cast<$Collection*>(this->visitPath)));
	list->add(descriptor);
	int32_t index = list->indexOf(descriptor);
	return $cast($String, $nc($($nc($($nc($(list->stream()))->skip(index)))->map(static_cast<$Function*>($$new(Resolver$$Lambda$name$4)))))->collect($($Collectors::joining(" -> "_s))));
}

void Resolver::checkHashes() {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($($nc(this->nameToReference)->values()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ModuleReference, mref, $cast($ModuleReference, i$->next()));
			{
				if (!($instanceOf($ModuleReferenceImpl, mref))) {
					continue;
				}
				$var($ModuleHashes, hashes, $nc(($cast($ModuleReferenceImpl, mref)))->recordedHashes());
				if (hashes == nullptr) {
					continue;
				}
				$var($ModuleDescriptor, descriptor, $nc(mref)->descriptor());
				$var($String, algorithm, $nc(hashes)->algorithm());
				{
					$var($Iterator, i$, $nc($(hashes->names()))->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($String, dn, $cast($String, i$->next()));
						{
							$var($ModuleReference, mref2, $cast($ModuleReference, $nc(this->nameToReference)->get(dn)));
							if (mref2 == nullptr) {
								$var($ResolvedModule, resolvedModule, findInParent(dn));
								if (resolvedModule != nullptr) {
									$assign(mref2, resolvedModule->reference());
								}
							}
							if (mref2 == nullptr) {
								continue;
							}
							if (!($instanceOf($ModuleReferenceImpl, mref2))) {
								findFail("Unable to compute the hash of module %s"_s, $$new($ObjectArray, {$of(dn)}));
							}
							$var($ModuleReferenceImpl, other, $cast($ModuleReferenceImpl, mref2));
							if (other != nullptr) {
								$var($bytes, recordedHash, hashes->hashFor(dn));
								$var($bytes, actualHash, other->computeHash(algorithm));
								if (actualHash == nullptr) {
									findFail("Unable to compute the hash of module %s"_s, $$new($ObjectArray, {$of(dn)}));
								}
								if (!$Arrays::equals(recordedHash, actualHash)) {
									$var($HexFormat, hex, $HexFormat::of());
									findFail("Hash of %s (%s) differs to expected hash (%s) recorded in %s"_s, $$new($ObjectArray, {
										$of(dn),
										$($of($nc(hex)->formatHex(actualHash))),
										$($of(hex->formatHex(recordedHash))),
										$($of($nc(descriptor)->name()))
									}));
								}
							}
						}
					}
				}
			}
		}
	}
}

$Map* Resolver::makeGraph($Configuration* cf) {
	$useLocalCurrentObjectStackCache();
	int32_t capacity = 1 + (4 * $nc(this->nameToReference)->size()) / 3;
	$var($Map, g1, $new($HashMap, capacity));
	$var($Map, g2, nullptr);
	if ($ModuleLayer::boot() == nullptr) {
		$assign(g2, $new($HashMap, capacity));
	} else {
		$var($Function, var$0, static_cast<$Function*>($new(Resolver$$Lambda$getKey$6)));
		$var($Supplier, var$1, static_cast<$Supplier*>($new(Resolver$$Lambda$HashMap$7)));
		$var($Function, var$2, static_cast<$Function*>($new(Resolver$$Lambda$getValue$8)));
		$assign(g2, $cast($Map, $nc($($nc($($nc($($nc($($nc(this->parents)->stream()))->flatMap(static_cast<$Function*>($$new(Resolver$$Lambda$configurations$1)))))->distinct()))->flatMap(static_cast<$Function*>($$new(Resolver$$Lambda$lambda$makeGraph$7$5)))))->collect($($Collectors::groupingBy(var$0, var$1, $($Collectors::mapping(var$2, $($Collectors::toSet()))))))));
	}
	$var($Map, nameToResolved, $new($HashMap, capacity));
	{
		$var($Iterator, i$, $nc($($nc(this->nameToReference)->values()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ModuleReference, mref, $cast($ModuleReference, i$->next()));
			{
				$var($ModuleDescriptor, descriptor, $nc(mref)->descriptor());
				$var($String, name, $nc(descriptor)->name());
				$var($ResolvedModule, m1, computeIfAbsent(nameToResolved, name, cf, mref));
				$var($Set, reads, $new($HashSet));
				$var($Set, requiresTransitive, $new($HashSet));
				{
					$var($Iterator, i$, $nc($(descriptor->requires()))->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($ModuleDescriptor$Requires, requires, $cast($ModuleDescriptor$Requires, i$->next()));
						{
							$var($String, dn, $nc(requires)->name());
							$var($ResolvedModule, m2, nullptr);
							$var($ModuleReference, mref2, $cast($ModuleReference, $nc(this->nameToReference)->get(dn)));
							if (mref2 != nullptr) {
								$assign(m2, computeIfAbsent(nameToResolved, dn, cf, mref2));
							} else {
								$assign(m2, findInParent(dn));
								if (m2 == nullptr) {
									$init($ModuleDescriptor$Requires$Modifier);
									if (!Resolver::$assertionsDisabled && !$nc($(requires->modifiers()))->contains($ModuleDescriptor$Requires$Modifier::STATIC)) {
										$throwNew($AssertionError);
									}
									continue;
								}
								if ($nc($($nc(m2)->descriptor()))->isAutomatic()) {
									$nc($($nc($($nc($(m2->reads()))->stream()))->filter(static_cast<$Predicate*>($$new(Resolver$$Lambda$lambda$makeGraph$8$9)))))->forEach(static_cast<$Consumer*>($$new(Resolver$$Lambda$add$10, static_cast<$Set*>(reads))));
								}
							}
							reads->add(m2);
							$init($ModuleDescriptor$Requires$Modifier);
							if ($nc($(requires->modifiers()))->contains($ModuleDescriptor$Requires$Modifier::TRANSITIVE)) {
								requiresTransitive->add(m2);
							}
						}
					}
				}
				if (descriptor->isAutomatic()) {
					{
						$var($Iterator, i$, $nc($($nc(this->nameToReference)->values()))->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($ModuleReference, mref2, $cast($ModuleReference, i$->next()));
							{
								$var($ModuleDescriptor, descriptor2, $nc(mref2)->descriptor());
								$var($String, name2, $nc(descriptor2)->name());
								if (!$nc(name)->equals(name2)) {
									$var($ResolvedModule, m2, computeIfAbsent(nameToResolved, name2, cf, mref2));
									reads->add(m2);
									if (descriptor2->isAutomatic()) {
										requiresTransitive->add(m2);
									}
								}
							}
						}
					}
					{
						$var($Iterator, i$, $nc(this->parents)->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($Configuration, parent, $cast($Configuration, i$->next()));
							{
								$nc($($nc($($nc($($nc(parent)->configurations()))->map(static_cast<$Function*>($$new(Resolver$$Lambda$modules$11)))))->flatMap(static_cast<$Function*>($$new(Resolver$$Lambda$stream$12)))))->forEach(static_cast<$Consumer*>($$new(Resolver$$Lambda$lambda$makeGraph$9$13, reads, requiresTransitive)));
							}
						}
					}
				}
				g1->put(m1, reads);
				$nc(g2)->put(m1, requiresTransitive);
			}
		}
	}
	bool changed = false;
	$var($List, toAdd, $new($ArrayList));
	do {
		changed = false;
		{
			$var($Iterator, i$, $nc($(g1->values()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Set, m1Reads, $cast($Set, i$->next()));
				{
					{
						$var($Iterator, i$, $nc(m1Reads)->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($ResolvedModule, m2, $cast($ResolvedModule, i$->next()));
							{
								$var($Set, m2RequiresTransitive, $cast($Set, $nc(g2)->get(m2)));
								if (m2RequiresTransitive != nullptr) {
									{
										$var($Iterator, i$, m2RequiresTransitive->iterator());
										for (; $nc(i$)->hasNext();) {
											$var($ResolvedModule, m3, $cast($ResolvedModule, i$->next()));
											{
												if (!m1Reads->contains(m3)) {
													toAdd->add(m3);
												}
											}
										}
									}
								}
							}
						}
					}
					if (!toAdd->isEmpty()) {
						m1Reads->addAll(toAdd);
						toAdd->clear();
						changed = true;
					}
				}
			}
		}
	} while (changed);
	return g1;
}

$ResolvedModule* Resolver::computeIfAbsent($Map* map, $String* name, $Configuration* cf, $ModuleReference* mref) {
	$var($ResolvedModule, m, $cast($ResolvedModule, $nc(map)->get(name)));
	if (m == nullptr) {
		$assign(m, $new($ResolvedModule, cf, mref));
		map->put(name, m);
	}
	return m;
}

void Resolver::checkExportSuppliers($Map* graph) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($($nc(graph)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($ModuleDescriptor, descriptor1, $nc(($cast($ResolvedModule, $($nc(e)->getKey()))))->descriptor());
				$var($String, name1, $nc(descriptor1)->name());
				$var($Set, names, $new($HashSet));
				names->add(name1);
				$var($Map, packageToExporter, $new($HashMap));
				$var($Set, packages, descriptor1->packages());
				{
					$var($Iterator, i$, $nc(packages)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($String, pn, $cast($String, i$->next()));
						{
							packageToExporter->put(pn, descriptor1);
						}
					}
				}
				$var($Set, reads, $cast($Set, e->getValue()));
				{
					$var($Iterator, i$, $nc(reads)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($ResolvedModule, endpoint, $cast($ResolvedModule, i$->next()));
						{
							$var($ModuleDescriptor, descriptor2, $nc(endpoint)->descriptor());
							$var($String, name2, $nc(descriptor2)->name());
							if (descriptor2 != descriptor1 && !names->add(name2)) {
								if ($nc(name2)->equals(name1)) {
									resolveFail("Module %s reads another module named %s"_s, $$new($ObjectArray, {
										$of(name1),
										$of(name1)
									}));
								} else {
									resolveFail("Module %s reads more than one module named %s"_s, $$new($ObjectArray, {
										$of(name1),
										$of(name2)
									}));
								}
							}
							if (descriptor2->isAutomatic()) {
								if (descriptor2 != descriptor1) {
									{
										$var($Iterator, i$, $nc($(descriptor2->packages()))->iterator());
										for (; $nc(i$)->hasNext();) {
											$var($String, source, $cast($String, i$->next()));
											{
												$var($ModuleDescriptor, supplier, $cast($ModuleDescriptor, packageToExporter->putIfAbsent(source, descriptor2)));
												if (supplier != nullptr) {
													failTwoSuppliers(descriptor1, source, descriptor2, supplier);
												}
											}
										}
									}
								}
							} else {
								{
									$var($Iterator, i$, $nc($(descriptor2->exports()))->iterator());
									for (; $nc(i$)->hasNext();) {
										$var($ModuleDescriptor$Exports, export$, $cast($ModuleDescriptor$Exports, i$->next()));
										{
											if ($nc(export$)->isQualified()) {
												if (!$nc($(export$->targets()))->contains($(descriptor1->name()))) {
													continue;
												}
											}
											$var($String, source, $nc(export$)->source());
											$var($ModuleDescriptor, supplier, $cast($ModuleDescriptor, packageToExporter->putIfAbsent(source, descriptor2)));
											if (supplier != nullptr) {
												failTwoSuppliers(descriptor1, source, descriptor2, supplier);
											}
										}
									}
								}
							}
						}
					}
				}
				if (!descriptor1->isAutomatic()) {
					{
						$var($Iterator, i$, $nc($(descriptor1->uses()))->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($String, service, $cast($String, i$->next()));
							{
								$var($String, pn, packageName(service));
								if (!packageToExporter->containsKey(pn)) {
									resolveFail("Module %s does not read a module that exports %s"_s, $$new($ObjectArray, {
										$($of(descriptor1->name())),
										$of(pn)
									}));
								}
							}
						}
					}
					{
						$var($Iterator, i$, $nc($(descriptor1->provides()))->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($ModuleDescriptor$Provides, provides, $cast($ModuleDescriptor$Provides, i$->next()));
							{
								$var($String, pn, packageName($($nc(provides)->service())));
								if (!packageToExporter->containsKey(pn)) {
									resolveFail("Module %s does not read a module that exports %s"_s, $$new($ObjectArray, {
										$($of(descriptor1->name())),
										$of(pn)
									}));
								}
							}
						}
					}
				}
			}
		}
	}
}

void Resolver::failTwoSuppliers($ModuleDescriptor* descriptor, $String* source, $ModuleDescriptor* supplier1$renamed, $ModuleDescriptor* supplier2$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($ModuleDescriptor, supplier2, supplier2$renamed);
	$var($ModuleDescriptor, supplier1, supplier1$renamed);
	if (supplier2 == descriptor) {
		$var($ModuleDescriptor, tmp, supplier1);
		$assign(supplier1, supplier2);
		$assign(supplier2, tmp);
	}
	if (supplier1 == descriptor) {
		resolveFail("Module %s contains package %s, module %s exports package %s to %s"_s, $$new($ObjectArray, {
			$($of($nc(descriptor)->name())),
			$of(source),
			$($of($nc(supplier2)->name())),
			$of(source),
			$($of(descriptor->name()))
		}));
	} else {
		resolveFail("Modules %s and %s export package %s to module %s"_s, $$new($ObjectArray, {
			$($of($nc(supplier1)->name())),
			$($of($nc(supplier2)->name())),
			$of(source),
			$($of($nc(descriptor)->name()))
		}));
	}
}

$ResolvedModule* Resolver::findInParent($String* mn) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc(this->parents)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Configuration, parent, $cast($Configuration, i$->next()));
			{
				$var($Optional, om, $nc(parent)->findModule(mn));
				if ($nc(om)->isPresent()) {
					return $cast($ResolvedModule, om->get());
				}
			}
		}
	}
	return nullptr;
}

$ModuleReference* Resolver::findWithBeforeFinder($String* mn) {
	return $cast($ModuleReference, $nc($($nc(this->beforeFinder)->find(mn)))->orElse(nullptr));
}

$ModuleReference* Resolver::findWithAfterFinder($String* mn) {
	return $cast($ModuleReference, $nc($($nc(this->afterFinder)->find(mn)))->orElse(nullptr));
}

$Set* Resolver::findAll() {
	$useLocalCurrentObjectStackCache();
	$var($Set, beforeModules, $nc(this->beforeFinder)->findAll());
	$var($Set, afterModules, $nc(this->afterFinder)->findAll());
	if ($nc(afterModules)->isEmpty()) {
		return beforeModules;
	}
	bool var$1 = $nc(beforeModules)->isEmpty();
	bool var$0 = var$1 && $nc(this->parents)->size() == 1;
	if (var$0) {
		var$0 = $equals($nc(this->parents)->get(0), $Configuration::empty());
	}
	if (var$0) {
		return afterModules;
	}
	$var($Set, result, $new($HashSet, static_cast<$Collection*>(beforeModules)));
	{
		$var($Iterator, i$, $nc(afterModules)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ModuleReference, mref, $cast($ModuleReference, i$->next()));
			{
				$var($String, name, $nc($($nc(mref)->descriptor()))->name());
				bool var$2 = !$nc($($nc(this->beforeFinder)->find(name)))->isPresent();
				if (var$2 && findInParent(name) == nullptr) {
					result->add(mref);
				}
			}
		}
	}
	return result;
}

$String* Resolver::packageName($String* cn) {
	$init(Resolver);
	int32_t index = $nc(cn)->lastIndexOf("."_s);
	return (index == -1) ? ""_s : cn->substring(0, index);
}

void Resolver::findFail($String* fmt, $ObjectArray* args) {
	$init(Resolver);
	$var($String, msg, $String::format(fmt, args));
	$throwNew($FindException, msg);
}

void Resolver::resolveFail($String* fmt, $ObjectArray* args) {
	$init(Resolver);
	$var($String, msg, $String::format(fmt, args));
	$throwNew($ResolutionException, msg);
}

bool Resolver::isTracing() {
	return this->traceOutput != nullptr;
}

void Resolver::trace($String* fmt, $ObjectArray* args) {
	if (this->traceOutput != nullptr) {
		$nc(this->traceOutput)->format(fmt, args);
		$nc(this->traceOutput)->println();
	}
}

$String* Resolver::nameAndInfo($ModuleReference* mref) {
	$useLocalCurrentObjectStackCache();
	$var($ModuleDescriptor, descriptor, $nc(mref)->descriptor());
	$var($StringBuilder, sb, $new($StringBuilder, $($nc(descriptor)->name())));
	$nc($(mref->location()))->ifPresent(static_cast<$Consumer*>($$new(Resolver$$Lambda$lambda$nameAndInfo$10$14, sb)));
	if ($nc(descriptor)->isAutomatic()) {
		sb->append(" automatic"_s);
	}
	return sb->toString();
}

void Resolver::lambda$nameAndInfo$10($StringBuilder* sb, $URI* uri) {
	$init(Resolver);
	$nc(sb)->append($$str({" "_s, uri}));
}

void Resolver::lambda$makeGraph$9($Set* reads, $Set* requiresTransitive, $ResolvedModule* m) {
	$init(Resolver);
	$useLocalCurrentObjectStackCache();
	$nc(reads)->add(m);
	if ($nc($($nc($($nc(m)->reference()))->descriptor()))->isAutomatic()) {
		$nc(requiresTransitive)->add(m);
	}
}

bool Resolver::lambda$makeGraph$8($ResolvedModule* d) {
	$init(Resolver);
	return $nc($($nc(d)->descriptor()))->isAutomatic();
}

$Stream* Resolver::lambda$makeGraph$7($Configuration* c) {
	$init(Resolver);
	$useLocalCurrentObjectStackCache();
	return $nc($($nc($($nc(c)->modules()))->stream()))->flatMap(static_cast<$Function*>($$new(Resolver$$Lambda$lambda$makeGraph$6$15, c)));
}

$Stream* Resolver::lambda$makeGraph$6($Configuration* c, $ResolvedModule* m1) {
	$init(Resolver);
	$useLocalCurrentObjectStackCache();
	return $nc($($nc($($nc($($nc($($nc($($nc(m1)->descriptor()))->requires()))->stream()))->filter(static_cast<$Predicate*>($$new(Resolver$$Lambda$lambda$makeGraph$3$16)))))->flatMap(static_cast<$Function*>($$new(Resolver$$Lambda$lambda$makeGraph$4$17, c)))))->map(static_cast<$Function*>($$new(Resolver$$Lambda$lambda$makeGraph$5$18, m1)));
}

$Map$Entry* Resolver::lambda$makeGraph$5($ResolvedModule* m1, $ResolvedModule* m2) {
	$init(Resolver);
	return $Map::entry(m1, m2);
}

$Stream* Resolver::lambda$makeGraph$4($Configuration* c, $ModuleDescriptor$Requires* r) {
	$init(Resolver);
	$useLocalCurrentObjectStackCache();
	$var($Optional, m2, $nc(c)->findModule($($nc(r)->name())));
	bool var$0 = !Resolver::$assertionsDisabled;
	if (var$0) {
		bool var$1 = $nc(m2)->isPresent();
		$init($ModuleDescriptor$Requires$Modifier);
		var$0 = !(var$1 || $nc($($nc(r)->modifiers()))->contains($ModuleDescriptor$Requires$Modifier::STATIC));
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	return $nc(m2)->stream();
}

bool Resolver::lambda$makeGraph$3($ModuleDescriptor$Requires* r) {
	$init(Resolver);
	$init($ModuleDescriptor$Requires$Modifier);
	return $nc($($nc(r)->modifiers()))->contains($ModuleDescriptor$Requires$Modifier::TRANSITIVE);
}

void Resolver::lambda$addFoundAutomaticModules$2($Set* result, $ModuleReference* mref) {
	$useLocalCurrentObjectStackCache();
	$var($String, mn, $nc($($nc(mref)->descriptor()))->name());
	bool var$0 = $nc($(mref->descriptor()))->isAutomatic();
	if (var$0 && !$nc(this->nameToReference)->containsKey(mn)) {
		addFoundModule(mref);
		$nc(result)->add(mref);
	}
}

$Stream* Resolver::lambda$bind$1($Configuration* c) {
	$init(Resolver);
	return $nc($($nc(c)->descriptors()))->stream();
}

void Resolver::lambda$resolve$0($Deque* q, $ModuleDescriptor* descriptor, $ModuleReference* mref) {
	$useLocalCurrentObjectStackCache();
	$var($ModuleDescriptor, other, $nc(mref)->descriptor());
	$nc(q)->offer(other);
	if (isTracing()) {
		trace("%s requires %s"_s, $$new($ObjectArray, {
			$($of($nc(descriptor)->name())),
			$($of(nameAndInfo(mref)))
		}));
	}
}

void clinit$Resolver($Class* class$) {
	Resolver::$assertionsDisabled = !Resolver::class$->desiredAssertionStatus();
}

Resolver::Resolver() {
}

$Class* Resolver::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Resolver$$Lambda$lambda$resolve$0::classInfo$.name)) {
			return Resolver$$Lambda$lambda$resolve$0::load$(name, initialize);
		}
		if (name->equals(Resolver$$Lambda$configurations$1::classInfo$.name)) {
			return Resolver$$Lambda$configurations$1::load$(name, initialize);
		}
		if (name->equals(Resolver$$Lambda$lambda$bind$1$2::classInfo$.name)) {
			return Resolver$$Lambda$lambda$bind$1$2::load$(name, initialize);
		}
		if (name->equals(Resolver$$Lambda$lambda$addFoundAutomaticModules$2$3::classInfo$.name)) {
			return Resolver$$Lambda$lambda$addFoundAutomaticModules$2$3::load$(name, initialize);
		}
		if (name->equals(Resolver$$Lambda$name$4::classInfo$.name)) {
			return Resolver$$Lambda$name$4::load$(name, initialize);
		}
		if (name->equals(Resolver$$Lambda$lambda$makeGraph$7$5::classInfo$.name)) {
			return Resolver$$Lambda$lambda$makeGraph$7$5::load$(name, initialize);
		}
		if (name->equals(Resolver$$Lambda$getKey$6::classInfo$.name)) {
			return Resolver$$Lambda$getKey$6::load$(name, initialize);
		}
		if (name->equals(Resolver$$Lambda$HashMap$7::classInfo$.name)) {
			return Resolver$$Lambda$HashMap$7::load$(name, initialize);
		}
		if (name->equals(Resolver$$Lambda$getValue$8::classInfo$.name)) {
			return Resolver$$Lambda$getValue$8::load$(name, initialize);
		}
		if (name->equals(Resolver$$Lambda$lambda$makeGraph$8$9::classInfo$.name)) {
			return Resolver$$Lambda$lambda$makeGraph$8$9::load$(name, initialize);
		}
		if (name->equals(Resolver$$Lambda$add$10::classInfo$.name)) {
			return Resolver$$Lambda$add$10::load$(name, initialize);
		}
		if (name->equals(Resolver$$Lambda$modules$11::classInfo$.name)) {
			return Resolver$$Lambda$modules$11::load$(name, initialize);
		}
		if (name->equals(Resolver$$Lambda$stream$12::classInfo$.name)) {
			return Resolver$$Lambda$stream$12::load$(name, initialize);
		}
		if (name->equals(Resolver$$Lambda$lambda$makeGraph$9$13::classInfo$.name)) {
			return Resolver$$Lambda$lambda$makeGraph$9$13::load$(name, initialize);
		}
		if (name->equals(Resolver$$Lambda$lambda$nameAndInfo$10$14::classInfo$.name)) {
			return Resolver$$Lambda$lambda$nameAndInfo$10$14::load$(name, initialize);
		}
		if (name->equals(Resolver$$Lambda$lambda$makeGraph$6$15::classInfo$.name)) {
			return Resolver$$Lambda$lambda$makeGraph$6$15::load$(name, initialize);
		}
		if (name->equals(Resolver$$Lambda$lambda$makeGraph$3$16::classInfo$.name)) {
			return Resolver$$Lambda$lambda$makeGraph$3$16::load$(name, initialize);
		}
		if (name->equals(Resolver$$Lambda$lambda$makeGraph$4$17::classInfo$.name)) {
			return Resolver$$Lambda$lambda$makeGraph$4$17::load$(name, initialize);
		}
		if (name->equals(Resolver$$Lambda$lambda$makeGraph$5$18::classInfo$.name)) {
			return Resolver$$Lambda$lambda$makeGraph$5$18::load$(name, initialize);
		}
	}
	$loadClass(Resolver, name, initialize, &_Resolver_ClassInfo_, clinit$Resolver, allocate$Resolver);
	return class$;
}

$Class* Resolver::class$ = nullptr;

		} // module
	} // lang
} // java