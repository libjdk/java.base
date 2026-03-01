#include <java/lang/ProcessEnvironment.h>

#include <java/lang/ProcessEnvironment$CheckedEntrySet.h>
#include <java/lang/ProcessEnvironment$CheckedKeySet.h>
#include <java/lang/ProcessEnvironment$CheckedValues.h>
#include <java/lang/ProcessEnvironment$EntryComparator.h>
#include <java/lang/ProcessEnvironment$NameComparator.h>
#include <java/util/AbstractMap.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Comparator.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/TreeMap.h>
#include <jcpp.h>

#undef MIN_NAME_LENGTH
#undef SYSTEMROOT

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $ProcessEnvironment$CheckedEntrySet = ::java::lang::ProcessEnvironment$CheckedEntrySet;
using $ProcessEnvironment$CheckedKeySet = ::java::lang::ProcessEnvironment$CheckedKeySet;
using $ProcessEnvironment$CheckedValues = ::java::lang::ProcessEnvironment$CheckedValues;
using $ProcessEnvironment$EntryComparator = ::java::lang::ProcessEnvironment$EntryComparator;
using $ProcessEnvironment$NameComparator = ::java::lang::ProcessEnvironment$NameComparator;
using $AbstractMap = ::java::util::AbstractMap;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Comparator = ::java::util::Comparator;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $TreeMap = ::java::util::TreeMap;

namespace java {
	namespace lang {

$FieldInfo _ProcessEnvironment_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ProcessEnvironment, serialVersionUID)},
	{"MIN_NAME_LENGTH", "I", nullptr, $STATIC | $FINAL, $constField(ProcessEnvironment, MIN_NAME_LENGTH)},
	{"nameComparator", "Ljava/lang/ProcessEnvironment$NameComparator;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProcessEnvironment, nameComparator)},
	{"entryComparator", "Ljava/lang/ProcessEnvironment$EntryComparator;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProcessEnvironment, entryComparator)},
	{"theEnvironment", "Ljava/lang/ProcessEnvironment;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProcessEnvironment, theEnvironment)},
	{"theUnmodifiableEnvironment", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ProcessEnvironment, theUnmodifiableEnvironment)},
	{"theCaseInsensitiveEnvironment", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ProcessEnvironment, theCaseInsensitiveEnvironment)},
	{}
};

$MethodInfo _ProcessEnvironment_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ProcessEnvironment, init$, void)},
	{"<init>", "(I)V", nullptr, $PRIVATE, $method(ProcessEnvironment, init$, void, int32_t)},
	{"addToEnv", "(Ljava/lang/StringBuilder;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ProcessEnvironment, addToEnv, void, $StringBuilder*, $String*, $String*)},
	{"addToEnvIfSet", "(Ljava/lang/StringBuilder;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ProcessEnvironment, addToEnvIfSet, void, $StringBuilder*, $String*)},
	{"containsKey", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ProcessEnvironment, containsKey, bool, Object$*)},
	{"containsValue", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ProcessEnvironment, containsValue, bool, Object$*)},
	{"emptyEnvironment", "(I)Ljava/util/Map;", "(I)Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $STATIC, $staticMethod(ProcessEnvironment, emptyEnvironment, $Map*, int32_t)},
	{"entrySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/util/Map$Entry<Ljava/lang/String;Ljava/lang/String;>;>;", $PUBLIC, $virtualMethod(ProcessEnvironment, entrySet, $Set*)},
	{"environment", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $STATIC, $staticMethod(ProcessEnvironment, environment, $Map*)},
	{"environmentBlock", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(ProcessEnvironment, environmentBlock, $String*)},
	{"get", "(Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ProcessEnvironment, get, $Object*, Object$*)},
	{"getenv", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(ProcessEnvironment, getenv, $String*, $String*)},
	{"getenv", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $STATIC, $staticMethod(ProcessEnvironment, getenv, $Map*)},
	{"keySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(ProcessEnvironment, keySet, $Set*)},
	{"nonNullString", "(Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ProcessEnvironment, nonNullString, $String*, Object$*)},
	{"put", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $method(ProcessEnvironment, put, $String*, $String*, $String*)},
	{"put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(ProcessEnvironment, put, $Object*, Object$*, Object$*)},
	{"remove", "(Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ProcessEnvironment, remove, $Object*, Object$*)},
	{"toEnvironmentBlock", "()Ljava/lang/String;", nullptr, 0, $method(ProcessEnvironment, toEnvironmentBlock, $String*)},
	{"toEnvironmentBlock", "(Ljava/util/Map;)Ljava/lang/String;", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)Ljava/lang/String;", $STATIC, $staticMethod(ProcessEnvironment, toEnvironmentBlock, $String*, $Map*)},
	{"validateName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ProcessEnvironment, validateName, $String*, $String*)},
	{"validateValue", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ProcessEnvironment, validateValue, $String*, $String*)},
	{"values", "()Ljava/util/Collection;", "()Ljava/util/Collection<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(ProcessEnvironment, values, $Collection*)},
	{}
};

#define _METHOD_INDEX_environmentBlock 9

$InnerClassInfo _ProcessEnvironment_InnerClassesInfo_[] = {
	{"java.lang.ProcessEnvironment$EntryComparator", "java.lang.ProcessEnvironment", "EntryComparator", $PRIVATE | $STATIC | $FINAL},
	{"java.lang.ProcessEnvironment$NameComparator", "java.lang.ProcessEnvironment", "NameComparator", $PRIVATE | $STATIC | $FINAL},
	{"java.lang.ProcessEnvironment$CheckedKeySet", "java.lang.ProcessEnvironment", "CheckedKeySet", $PRIVATE | $STATIC},
	{"java.lang.ProcessEnvironment$CheckedValues", "java.lang.ProcessEnvironment", "CheckedValues", $PRIVATE | $STATIC},
	{"java.lang.ProcessEnvironment$CheckedEntrySet", "java.lang.ProcessEnvironment", "CheckedEntrySet", $PRIVATE | $STATIC},
	{"java.lang.ProcessEnvironment$CheckedEntry", "java.lang.ProcessEnvironment", "CheckedEntry", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _ProcessEnvironment_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.lang.ProcessEnvironment",
	"java.util.HashMap",
	nullptr,
	_ProcessEnvironment_FieldInfo_,
	_ProcessEnvironment_MethodInfo_,
	"Ljava/util/HashMap<Ljava/lang/String;Ljava/lang/String;>;",
	nullptr,
	_ProcessEnvironment_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.ProcessEnvironment$EntryComparator,java.lang.ProcessEnvironment$NameComparator,java.lang.ProcessEnvironment$CheckedKeySet,java.lang.ProcessEnvironment$CheckedValues,java.lang.ProcessEnvironment$CheckedEntrySet,java.lang.ProcessEnvironment$CheckedEntrySet$1,java.lang.ProcessEnvironment$CheckedEntry"
};

$Object* allocate$ProcessEnvironment($Class* clazz) {
	return $of($alloc(ProcessEnvironment));
}

$ProcessEnvironment$NameComparator* ProcessEnvironment::nameComparator = nullptr;
$ProcessEnvironment$EntryComparator* ProcessEnvironment::entryComparator = nullptr;
ProcessEnvironment* ProcessEnvironment::theEnvironment = nullptr;
$Map* ProcessEnvironment::theUnmodifiableEnvironment = nullptr;
$Map* ProcessEnvironment::theCaseInsensitiveEnvironment = nullptr;

$String* ProcessEnvironment::validateName($String* name) {
	$init(ProcessEnvironment);
	bool var$0 = $nc(name)->indexOf((int32_t)u'=', 1) != -1;
	if (var$0 || $nc(name)->indexOf((int32_t)u'\0') != -1) {
		$throwNew($IllegalArgumentException, $$str({"Invalid environment variable name: \""_s, name, "\""_s}));
	}
	return name;
}

$String* ProcessEnvironment::validateValue($String* value) {
	$init(ProcessEnvironment);
	if ($nc(value)->indexOf((int32_t)u'\0') != -1) {
		$throwNew($IllegalArgumentException, $$str({"Invalid environment variable value: \""_s, value, "\""_s}));
	}
	return value;
}

$String* ProcessEnvironment::nonNullString(Object$* o) {
	$init(ProcessEnvironment);
	if (o == nullptr) {
		$throwNew($NullPointerException);
	}
	return $cast($String, o);
}

$String* ProcessEnvironment::put($String* key, $String* value) {
	$useLocalCurrentObjectStackCache();
	$var($Object, var$0, $of(validateName(key)));
	return $cast($String, $HashMap::put(var$0, $(validateValue(value))));
}

$Object* ProcessEnvironment::get(Object$* key) {
	return $of($cast($String, $HashMap::get($(nonNullString(key)))));
}

bool ProcessEnvironment::containsKey(Object$* key) {
	return $HashMap::containsKey($(nonNullString(key)));
}

bool ProcessEnvironment::containsValue(Object$* value) {
	return $HashMap::containsValue($(nonNullString(value)));
}

$Object* ProcessEnvironment::remove(Object$* key) {
	return $of($cast($String, $HashMap::remove($(nonNullString(key)))));
}

$Set* ProcessEnvironment::keySet() {
	return $new($ProcessEnvironment$CheckedKeySet, $($HashMap::keySet()));
}

$Collection* ProcessEnvironment::values() {
	return $new($ProcessEnvironment$CheckedValues, $($HashMap::values()));
}

$Set* ProcessEnvironment::entrySet() {
	return $new($ProcessEnvironment$CheckedEntrySet, $($HashMap::entrySet()));
}

void ProcessEnvironment::init$() {
	$HashMap::init$();
}

void ProcessEnvironment::init$(int32_t capacity) {
	$HashMap::init$(capacity);
}

$String* ProcessEnvironment::getenv($String* name) {
	$init(ProcessEnvironment);
	return $cast($String, $nc(ProcessEnvironment::theCaseInsensitiveEnvironment)->get(name));
}

$Map* ProcessEnvironment::getenv() {
	$init(ProcessEnvironment);
	return ProcessEnvironment::theUnmodifiableEnvironment;
}

$Map* ProcessEnvironment::environment() {
	$init(ProcessEnvironment);
	return $cast($Map, $nc(ProcessEnvironment::theEnvironment)->clone());
}

$Map* ProcessEnvironment::emptyEnvironment(int32_t capacity) {
	$init(ProcessEnvironment);
	return $new(ProcessEnvironment, capacity);
}

$String* ProcessEnvironment::environmentBlock() {
	$init(ProcessEnvironment);
	$var($String, $ret, nullptr);
	$prepareNativeStatic(ProcessEnvironment, environmentBlock, $String*);
	$assign($ret, $invokeNativeStaticObject());
	$finishNativeStatic();
	return $ret;
}

$String* ProcessEnvironment::toEnvironmentBlock() {
	$useLocalCurrentObjectStackCache();
	$var($List, list, $new($ArrayList, $(static_cast<$Collection*>(entrySet()))));
	$Collections::sort(list, ProcessEnvironment::entryComparator);
	$var($StringBuilder, sb, $new($StringBuilder, size() * 30));
	int32_t cmp = -1;
	$var($String, SYSTEMROOT, "SystemRoot"_s);
	{
		$var($Iterator, i$, list->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($String, key, $cast($String, $nc(e)->getKey()));
				$var($String, value, $cast($String, e->getValue()));
				if (cmp < 0 && (cmp = $nc(ProcessEnvironment::nameComparator)->compare(key, SYSTEMROOT)) > 0) {
					addToEnvIfSet(sb, SYSTEMROOT);
				}
				addToEnv(sb, key, value);
			}
		}
	}
	if (cmp < 0) {
		addToEnvIfSet(sb, SYSTEMROOT);
	}
	if (sb->length() == 0) {
		sb->append(u'\0');
	}
	sb->append(u'\0');
	return sb->toString();
}

void ProcessEnvironment::addToEnvIfSet($StringBuilder* sb, $String* name) {
	$init(ProcessEnvironment);
	$var($String, s, getenv(name));
	if (s != nullptr) {
		addToEnv(sb, name, s);
	}
}

void ProcessEnvironment::addToEnv($StringBuilder* sb, $String* name, $String* val) {
	$init(ProcessEnvironment);
	$nc(sb)->append(name)->append(u'=')->append(val)->append(u'\0');
}

$String* ProcessEnvironment::toEnvironmentBlock($Map* map) {
	$init(ProcessEnvironment);
	return map == nullptr ? ($String*)nullptr : $nc(($cast(ProcessEnvironment, map)))->toEnvironmentBlock();
}

$Object* ProcessEnvironment::put(Object$* key, Object$* value) {
	return $of(this->put($cast($String, key), $cast($String, value)));
}

void clinit$ProcessEnvironment($Class* class$) {
	$useLocalCurrentObjectStackCache();
	{
		$assignStatic(ProcessEnvironment::nameComparator, $new($ProcessEnvironment$NameComparator));
		$assignStatic(ProcessEnvironment::entryComparator, $new($ProcessEnvironment$EntryComparator));
		$assignStatic(ProcessEnvironment::theEnvironment, $new(ProcessEnvironment));
		$assignStatic(ProcessEnvironment::theUnmodifiableEnvironment, $Collections::unmodifiableMap(ProcessEnvironment::theEnvironment));
		$var($String, envblock, ProcessEnvironment::environmentBlock());
		int32_t beg = 0;
		int32_t end = 0;
		int32_t eql = 0;
		{
			beg = 0;
			for (;; beg = end + 1) {
				bool var$0 = (end = $nc(envblock)->indexOf((int32_t)u'\0', beg)) != -1;
				if (!(var$0 && (eql = envblock->indexOf((int32_t)u'=', beg + 1)) != -1)) {
					break;
				}
				{
					if (eql < end) {
						$var($String, var$1, envblock->substring(beg, eql));
						$nc(ProcessEnvironment::theEnvironment)->put(var$1, $(envblock->substring(eql + 1, end)));
					}
				}
			}
		}
		$assignStatic(ProcessEnvironment::theCaseInsensitiveEnvironment, static_cast<$Map*>(static_cast<$AbstractMap*>($new($TreeMap, static_cast<$Comparator*>(ProcessEnvironment::nameComparator)))));
		$nc(ProcessEnvironment::theCaseInsensitiveEnvironment)->putAll(ProcessEnvironment::theEnvironment);
	}
}

ProcessEnvironment::ProcessEnvironment() {
}

$Class* ProcessEnvironment::load$($String* name, bool initialize) {
	$loadClass(ProcessEnvironment, name, initialize, &_ProcessEnvironment_ClassInfo_, clinit$ProcessEnvironment, allocate$ProcessEnvironment);
	return class$;
}

$Class* ProcessEnvironment::class$ = nullptr;

	} // lang
} // java