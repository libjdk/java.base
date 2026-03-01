#include <java/lang/ProcessEnvironment$StringEnvironment.h>

#include <java/lang/ProcessEnvironment$StringEntrySet.h>
#include <java/lang/ProcessEnvironment$StringKeySet.h>
#include <java/lang/ProcessEnvironment$StringValues.h>
#include <java/lang/ProcessEnvironment$Value.h>
#include <java/lang/ProcessEnvironment$Variable.h>
#include <java/lang/ProcessEnvironment.h>
#include <java/util/AbstractMap.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ProcessEnvironment$StringEntrySet = ::java::lang::ProcessEnvironment$StringEntrySet;
using $ProcessEnvironment$StringKeySet = ::java::lang::ProcessEnvironment$StringKeySet;
using $ProcessEnvironment$StringValues = ::java::lang::ProcessEnvironment$StringValues;
using $ProcessEnvironment$Value = ::java::lang::ProcessEnvironment$Value;
using $ProcessEnvironment$Variable = ::java::lang::ProcessEnvironment$Variable;
using $AbstractMap = ::java::util::AbstractMap;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;

namespace java {
	namespace lang {

$FieldInfo _ProcessEnvironment$StringEnvironment_FieldInfo_[] = {
	{"m", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/ProcessEnvironment$Variable;Ljava/lang/ProcessEnvironment$Value;>;", $PRIVATE, $field(ProcessEnvironment$StringEnvironment, m)},
	{}
};

$MethodInfo _ProcessEnvironment$StringEnvironment_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Map;)V", "(Ljava/util/Map<Ljava/lang/ProcessEnvironment$Variable;Ljava/lang/ProcessEnvironment$Value;>;)V", $PUBLIC, $method(ProcessEnvironment$StringEnvironment, init$, void, $Map*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(ProcessEnvironment$StringEnvironment, clear, void)},
	{"containsKey", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ProcessEnvironment$StringEnvironment, containsKey, bool, Object$*)},
	{"containsValue", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ProcessEnvironment$StringEnvironment, containsValue, bool, Object$*)},
	{"entrySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/util/Map$Entry<Ljava/lang/String;Ljava/lang/String;>;>;", $PUBLIC, $virtualMethod(ProcessEnvironment$StringEnvironment, entrySet, $Set*)},
	{"get", "(Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ProcessEnvironment$StringEnvironment, get, $Object*, Object$*)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(ProcessEnvironment$StringEnvironment, isEmpty, bool)},
	{"keySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(ProcessEnvironment$StringEnvironment, keySet, $Set*)},
	{"put", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ProcessEnvironment$StringEnvironment, put, $String*, $String*, $String*)},
	{"put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(ProcessEnvironment$StringEnvironment, put, $Object*, Object$*, Object$*)},
	{"remove", "(Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ProcessEnvironment$StringEnvironment, remove, $Object*, Object$*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(ProcessEnvironment$StringEnvironment, size, int32_t)},
	{"toEnvironmentBlock", "([I)[B", nullptr, $PUBLIC, $virtualMethod(ProcessEnvironment$StringEnvironment, toEnvironmentBlock, $bytes*, $ints*)},
	{"toString", "(Ljava/lang/ProcessEnvironment$Value;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ProcessEnvironment$StringEnvironment, toString, $String*, $ProcessEnvironment$Value*)},
	{"values", "()Ljava/util/Collection;", "()Ljava/util/Collection<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(ProcessEnvironment$StringEnvironment, values, $Collection*)},
	{}
};

$InnerClassInfo _ProcessEnvironment$StringEnvironment_InnerClassesInfo_[] = {
	{"java.lang.ProcessEnvironment$StringEnvironment", "java.lang.ProcessEnvironment", "StringEnvironment", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _ProcessEnvironment$StringEnvironment_ClassInfo_ = {
	$ACC_SUPER,
	"java.lang.ProcessEnvironment$StringEnvironment",
	"java.util.AbstractMap",
	nullptr,
	_ProcessEnvironment$StringEnvironment_FieldInfo_,
	_ProcessEnvironment$StringEnvironment_MethodInfo_,
	"Ljava/util/AbstractMap<Ljava/lang/String;Ljava/lang/String;>;",
	nullptr,
	_ProcessEnvironment$StringEnvironment_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.ProcessEnvironment"
};

$Object* allocate$ProcessEnvironment$StringEnvironment($Class* clazz) {
	return $of($alloc(ProcessEnvironment$StringEnvironment));
}

$String* ProcessEnvironment$StringEnvironment::toString($ProcessEnvironment$Value* v) {
	$init(ProcessEnvironment$StringEnvironment);
	return v == nullptr ? ($String*)nullptr : $nc(v)->toString();
}

void ProcessEnvironment$StringEnvironment::init$($Map* m) {
	$AbstractMap::init$();
	$set(this, m, m);
}

int32_t ProcessEnvironment$StringEnvironment::size() {
	return $nc(this->m)->size();
}

bool ProcessEnvironment$StringEnvironment::isEmpty() {
	return $nc(this->m)->isEmpty();
}

void ProcessEnvironment$StringEnvironment::clear() {
	$nc(this->m)->clear();
}

bool ProcessEnvironment$StringEnvironment::containsKey(Object$* key) {
	return $nc(this->m)->containsKey($($ProcessEnvironment$Variable::valueOfQueryOnly(key)));
}

bool ProcessEnvironment$StringEnvironment::containsValue(Object$* value) {
	return $nc(this->m)->containsValue($($ProcessEnvironment$Value::valueOfQueryOnly(value)));
}

$Object* ProcessEnvironment$StringEnvironment::get(Object$* key) {
	$useLocalCurrentObjectStackCache();
	return $of(toString($cast($ProcessEnvironment$Value, $($nc(this->m)->get($($ProcessEnvironment$Variable::valueOfQueryOnly(key)))))));
}

$String* ProcessEnvironment$StringEnvironment::put($String* key, $String* value) {
	$useLocalCurrentObjectStackCache();
	$var($Object, var$0, $of($ProcessEnvironment$Variable::valueOf(key)));
	return toString($cast($ProcessEnvironment$Value, $($nc(this->m)->put(var$0, $($ProcessEnvironment$Value::valueOf(value))))));
}

$Object* ProcessEnvironment$StringEnvironment::remove(Object$* key) {
	$useLocalCurrentObjectStackCache();
	return $of(toString($cast($ProcessEnvironment$Value, $($nc(this->m)->remove($($ProcessEnvironment$Variable::valueOfQueryOnly(key)))))));
}

$Set* ProcessEnvironment$StringEnvironment::keySet() {
	return $new($ProcessEnvironment$StringKeySet, $($nc(this->m)->keySet()));
}

$Set* ProcessEnvironment$StringEnvironment::entrySet() {
	return $new($ProcessEnvironment$StringEntrySet, $($nc(this->m)->entrySet()));
}

$Collection* ProcessEnvironment$StringEnvironment::values() {
	return $new($ProcessEnvironment$StringValues, $($nc(this->m)->values()));
}

$bytes* ProcessEnvironment$StringEnvironment::toEnvironmentBlock($ints* envc) {
	$useLocalCurrentObjectStackCache();
	int32_t count = $nc(this->m)->size() * 2;
	{
		$var($Iterator, i$, $nc($($nc(this->m)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				count += $nc($($nc(($cast($ProcessEnvironment$Variable, $($nc(entry)->getKey()))))->getBytes()))->length;
				count += $nc($($nc(($cast($ProcessEnvironment$Value, $(entry->getValue()))))->getBytes()))->length;
			}
		}
	}
	$var($bytes, block, $new($bytes, count));
	int32_t i = 0;
	{
		$var($Iterator, i$, $nc($($nc(this->m)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				$var($bytes, key, $nc(($cast($ProcessEnvironment$Variable, $($nc(entry)->getKey()))))->getBytes());
				$var($bytes, value, $nc(($cast($ProcessEnvironment$Value, $(entry->getValue()))))->getBytes());
				$System::arraycopy(key, 0, block, i, $nc(key)->length);
				i += $nc(key)->length;
				block->set(i++, (int8_t)u'=');
				$System::arraycopy(value, 0, block, i, $nc(value)->length);
				i += $nc(value)->length + 1;
			}
		}
	}
	$nc(envc)->set(0, $nc(this->m)->size());
	return block;
}

$Object* ProcessEnvironment$StringEnvironment::put(Object$* key, Object$* value) {
	return $of(this->put($cast($String, key), $cast($String, value)));
}

ProcessEnvironment$StringEnvironment::ProcessEnvironment$StringEnvironment() {
}

$Class* ProcessEnvironment$StringEnvironment::load$($String* name, bool initialize) {
	$loadClass(ProcessEnvironment$StringEnvironment, name, initialize, &_ProcessEnvironment$StringEnvironment_ClassInfo_, allocate$ProcessEnvironment$StringEnvironment);
	return class$;
}

$Class* ProcessEnvironment$StringEnvironment::class$ = nullptr;

	} // lang
} // java