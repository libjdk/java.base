#include <sun/util/resources/ParallelListResourceBundle.h>

#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/ResourceBundle.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <java/util/concurrent/atomic/AtomicMarkableReference.h>
#include <sun/util/resources/OpenListResourceBundle.h>
#include <sun/util/resources/ParallelListResourceBundle$KeySet.h>
#include <jcpp.h>

using $ObjectArray2 = $Array<::java::lang::Object, 2>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $ResourceBundle = ::java::util::ResourceBundle;
using $Set = ::java::util::Set;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $AtomicMarkableReference = ::java::util::concurrent::atomic::AtomicMarkableReference;
using $OpenListResourceBundle = ::sun::util::resources::OpenListResourceBundle;
using $ParallelListResourceBundle$KeySet = ::sun::util::resources::ParallelListResourceBundle$KeySet;

namespace sun {
	namespace util {
		namespace resources {

$FieldInfo _ParallelListResourceBundle_FieldInfo_[] = {
	{"lookup", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/lang/String;Ljava/lang/Object;>;", $PRIVATE | $VOLATILE, $field(ParallelListResourceBundle, lookup)},
	{"keyset", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $VOLATILE, $field(ParallelListResourceBundle, keyset)},
	{"parallelContents", "Ljava/util/concurrent/atomic/AtomicMarkableReference;", "Ljava/util/concurrent/atomic/AtomicMarkableReference<[[Ljava/lang/Object;>;", $PRIVATE | $FINAL, $field(ParallelListResourceBundle, parallelContents)},
	{}
};

$MethodInfo _ParallelListResourceBundle_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(ParallelListResourceBundle, init$, void)},
	{"areParallelContentsComplete", "()Z", nullptr, 0, $virtualMethod(ParallelListResourceBundle, areParallelContentsComplete, bool)},
	{"containsKey", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(ParallelListResourceBundle, containsKey, bool, $String*)},
	{"getContents", "()[[Ljava/lang/Object;", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(ParallelListResourceBundle, getContents, $ObjectArray2*)},
	{"getKeys", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(ParallelListResourceBundle, getKeys, $Enumeration*)},
	{"getParent", "()Ljava/util/ResourceBundle;", nullptr, 0, $virtualMethod(ParallelListResourceBundle, getParent, $ResourceBundle*)},
	{"handleGetObject", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PROTECTED, $virtualMethod(ParallelListResourceBundle, handleGetObject, $Object*, $String*)},
	{"handleKeySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PROTECTED, $virtualMethod(ParallelListResourceBundle, handleKeySet, $Set*)},
	{"keySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(ParallelListResourceBundle, keySet, $Set*)},
	{"loadLookupTablesIfNecessary", "()V", nullptr, 0, $virtualMethod(ParallelListResourceBundle, loadLookupTablesIfNecessary, void)},
	{"resetKeySet", "()V", nullptr, $SYNCHRONIZED, $virtualMethod(ParallelListResourceBundle, resetKeySet, void)},
	{"setParallelContents", "(Lsun/util/resources/OpenListResourceBundle;)V", nullptr, $PUBLIC, $virtualMethod(ParallelListResourceBundle, setParallelContents, void, $OpenListResourceBundle*)},
	{}
};

$InnerClassInfo _ParallelListResourceBundle_InnerClassesInfo_[] = {
	{"sun.util.resources.ParallelListResourceBundle$KeySet", "sun.util.resources.ParallelListResourceBundle", "KeySet", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _ParallelListResourceBundle_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"sun.util.resources.ParallelListResourceBundle",
	"java.util.ResourceBundle",
	nullptr,
	_ParallelListResourceBundle_FieldInfo_,
	_ParallelListResourceBundle_MethodInfo_,
	nullptr,
	nullptr,
	_ParallelListResourceBundle_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.util.resources.ParallelListResourceBundle$KeySet,sun.util.resources.ParallelListResourceBundle$KeySet$1"
};

$Object* allocate$ParallelListResourceBundle($Class* clazz) {
	return $of($alloc(ParallelListResourceBundle));
}

void ParallelListResourceBundle::init$() {
	$ResourceBundle::init$();
	$set(this, parallelContents, $new($AtomicMarkableReference, nullptr, false));
}

$ResourceBundle* ParallelListResourceBundle::getParent() {
	return this->parent;
}

void ParallelListResourceBundle::setParallelContents($OpenListResourceBundle* rb) {
	if (rb == nullptr) {
		$nc(this->parallelContents)->compareAndSet(nullptr, nullptr, false, true);
	} else {
		$nc(this->parallelContents)->compareAndSet(nullptr, $($nc(rb)->getContents()), false, false);
	}
}

bool ParallelListResourceBundle::areParallelContentsComplete() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->parallelContents)->isMarked()) {
		return true;
	}
	$var($booleans, done, $new($booleans, 1));
	$var($ObjectArray2, data, $cast($ObjectArray2, $nc(this->parallelContents)->get(done)));
	return data != nullptr || done->get(0);
}

$Object* ParallelListResourceBundle::handleGetObject($String* key) {
	if (key == nullptr) {
		$throwNew($NullPointerException);
	}
	loadLookupTablesIfNecessary();
	return $of($nc(this->lookup)->get(key));
}

$Enumeration* ParallelListResourceBundle::getKeys() {
	return $Collections::enumeration($(keySet()));
}

bool ParallelListResourceBundle::containsKey($String* key) {
	return $nc($(keySet()))->contains(key);
}

$Set* ParallelListResourceBundle::handleKeySet() {
	loadLookupTablesIfNecessary();
	return $nc(this->lookup)->keySet();
}

$Set* ParallelListResourceBundle::keySet() {
	$useLocalCurrentObjectStackCache();
	$var($Set, ks, nullptr);
	while (($assign(ks, this->keyset)) == nullptr) {
		$assign(ks, $new($ParallelListResourceBundle$KeySet, $(handleKeySet()), this->parent));
		$synchronized(this) {
			if (this->keyset == nullptr) {
				$set(this, keyset, ks);
			}
		}
	}
	return ks;
}

void ParallelListResourceBundle::resetKeySet() {
	$synchronized(this) {
		$set(this, keyset, nullptr);
	}
}

void ParallelListResourceBundle::loadLookupTablesIfNecessary() {
	$useLocalCurrentObjectStackCache();
	$var($ConcurrentMap, map, this->lookup);
	if (map == nullptr) {
		$assign(map, $new($ConcurrentHashMap));
		{
			$var($ObjectArray2, arr$, getContents());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($ObjectArray, item, arr$->get(i$));
				{
					map->put($cast($String, $nc(item)->get(0)), item->get(1));
				}
			}
		}
	}
	$var($ObjectArray2, data, $cast($ObjectArray2, $nc(this->parallelContents)->getReference()));
	if (data != nullptr) {
		{
			$var($ObjectArray2, arr$, data);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($ObjectArray, item, arr$->get(i$));
				{
					$nc(map)->putIfAbsent($cast($String, $nc(item)->get(0)), item->get(1));
				}
			}
		}
		$nc(this->parallelContents)->set(nullptr, true);
	}
	if (this->lookup == nullptr) {
		$synchronized(this) {
			if (this->lookup == nullptr) {
				$set(this, lookup, map);
			}
		}
	}
}

ParallelListResourceBundle::ParallelListResourceBundle() {
}

$Class* ParallelListResourceBundle::load$($String* name, bool initialize) {
	$loadClass(ParallelListResourceBundle, name, initialize, &_ParallelListResourceBundle_ClassInfo_, allocate$ParallelListResourceBundle);
	return class$;
}

$Class* ParallelListResourceBundle::class$ = nullptr;

		} // resources
	} // util
} // sun