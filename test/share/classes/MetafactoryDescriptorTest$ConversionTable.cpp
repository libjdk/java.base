#include <MetafactoryDescriptorTest$ConversionTable.h>

#include <MetafactoryDescriptorTest.h>
#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/function/Function.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $Function = ::java::util::function::Function;

class MetafactoryDescriptorTest$ConversionTable$$Lambda$lambda$put$0 : public $Function {
	$class(MetafactoryDescriptorTest$ConversionTable$$Lambda$lambda$put$0, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* f) override {
		 return $of(MetafactoryDescriptorTest$ConversionTable::lambda$put$0($cast($Class, f)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MetafactoryDescriptorTest$ConversionTable$$Lambda$lambda$put$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo MetafactoryDescriptorTest$ConversionTable$$Lambda$lambda$put$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(MetafactoryDescriptorTest$ConversionTable$$Lambda$lambda$put$0, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(MetafactoryDescriptorTest$ConversionTable$$Lambda$lambda$put$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo MetafactoryDescriptorTest$ConversionTable$$Lambda$lambda$put$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"MetafactoryDescriptorTest$ConversionTable$$Lambda$lambda$put$0",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* MetafactoryDescriptorTest$ConversionTable$$Lambda$lambda$put$0::load$($String* name, bool initialize) {
	$loadClass(MetafactoryDescriptorTest$ConversionTable$$Lambda$lambda$put$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MetafactoryDescriptorTest$ConversionTable$$Lambda$lambda$put$0::class$ = nullptr;

$FieldInfo _MetafactoryDescriptorTest$ConversionTable_FieldInfo_[] = {
	{"pairs", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Class<*>;Ljava/util/Set<Ljava/lang/Class<*>;>;>;", $PRIVATE | $FINAL, $field(MetafactoryDescriptorTest$ConversionTable, pairs)},
	{}
};

$MethodInfo _MetafactoryDescriptorTest$ConversionTable_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(MetafactoryDescriptorTest$ConversionTable, init$, void)},
	{"contains", "(Ljava/lang/Class;Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)Z", $PUBLIC, $virtualMethod(MetafactoryDescriptorTest$ConversionTable, contains, bool, $Class*, $Class*)},
	{"lambda$put$0", "(Ljava/lang/Class;)Ljava/util/Set;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(MetafactoryDescriptorTest$ConversionTable, lambda$put$0, $Set*, $Class*)},
	{"put", "(Ljava/lang/Class;Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)V", $PUBLIC, $virtualMethod(MetafactoryDescriptorTest$ConversionTable, put, void, $Class*, $Class*)},
	{}
};

$InnerClassInfo _MetafactoryDescriptorTest$ConversionTable_InnerClassesInfo_[] = {
	{"MetafactoryDescriptorTest$ConversionTable", "MetafactoryDescriptorTest", "ConversionTable", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _MetafactoryDescriptorTest$ConversionTable_ClassInfo_ = {
	$ACC_SUPER,
	"MetafactoryDescriptorTest$ConversionTable",
	"java.lang.Object",
	nullptr,
	_MetafactoryDescriptorTest$ConversionTable_FieldInfo_,
	_MetafactoryDescriptorTest$ConversionTable_MethodInfo_,
	nullptr,
	nullptr,
	_MetafactoryDescriptorTest$ConversionTable_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"MetafactoryDescriptorTest"
};

$Object* allocate$MetafactoryDescriptorTest$ConversionTable($Class* clazz) {
	return $of($alloc(MetafactoryDescriptorTest$ConversionTable));
}

void MetafactoryDescriptorTest$ConversionTable::init$() {
	$set(this, pairs, $new($HashMap));
}

void MetafactoryDescriptorTest$ConversionTable::put($Class* from, $Class* to) {
	$useLocalCurrentObjectStackCache();
	$var($Set, set, $cast($Set, $nc(this->pairs)->computeIfAbsent(from, static_cast<$Function*>($$new(MetafactoryDescriptorTest$ConversionTable$$Lambda$lambda$put$0)))));
	$nc(set)->add(to);
}

bool MetafactoryDescriptorTest$ConversionTable::contains($Class* from, $Class* to) {
	bool var$0 = $nc(this->pairs)->containsKey(from);
	return var$0 && $nc(($cast($Set, $($nc(this->pairs)->get(from)))))->contains(to);
}

$Set* MetafactoryDescriptorTest$ConversionTable::lambda$put$0($Class* f) {
	return $new($HashSet);
}

MetafactoryDescriptorTest$ConversionTable::MetafactoryDescriptorTest$ConversionTable() {
}

$Class* MetafactoryDescriptorTest$ConversionTable::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(MetafactoryDescriptorTest$ConversionTable$$Lambda$lambda$put$0::classInfo$.name)) {
			return MetafactoryDescriptorTest$ConversionTable$$Lambda$lambda$put$0::load$(name, initialize);
		}
	}
	$loadClass(MetafactoryDescriptorTest$ConversionTable, name, initialize, &_MetafactoryDescriptorTest$ConversionTable_ClassInfo_, allocate$MetafactoryDescriptorTest$ConversionTable);
	return class$;
}

$Class* MetafactoryDescriptorTest$ConversionTable::class$ = nullptr;