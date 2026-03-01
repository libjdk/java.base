#include <sun/util/resources/OpenListResourceBundle.h>

#include <java/util/Collection.h>
#include <java/util/Enumeration.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Map.h>
#include <java/util/ResourceBundle.h>
#include <java/util/Set.h>
#include <sun/util/ResourceBundleEnumeration.h>
#include <jcpp.h>

using $ObjectArray2 = $Array<::java::lang::Object, 2>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Collection = ::java::util::Collection;
using $Enumeration = ::java::util::Enumeration;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Map = ::java::util::Map;
using $ResourceBundle = ::java::util::ResourceBundle;
using $Set = ::java::util::Set;
using $ResourceBundleEnumeration = ::sun::util::ResourceBundleEnumeration;

namespace sun {
	namespace util {
		namespace resources {

$FieldInfo _OpenListResourceBundle_FieldInfo_[] = {
	{"lookup", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/Object;>;", $PRIVATE | $VOLATILE, $field(OpenListResourceBundle, lookup)},
	{"keyset", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $VOLATILE, $field(OpenListResourceBundle, keyset)},
	{}
};

$MethodInfo _OpenListResourceBundle_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(OpenListResourceBundle, init$, void)},
	{"createMap", "(I)Ljava/util/Map;", "<K:Ljava/lang/Object;V:Ljava/lang/Object;>(I)Ljava/util/Map<TK;TV;>;", $PROTECTED, $virtualMethod(OpenListResourceBundle, createMap, $Map*, int32_t)},
	{"createSet", "()Ljava/util/Set;", "<E:Ljava/lang/Object;>()Ljava/util/Set<TE;>;", $PROTECTED, $virtualMethod(OpenListResourceBundle, createSet, $Set*)},
	{"getContents", "()[[Ljava/lang/Object;", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(OpenListResourceBundle, getContents, $ObjectArray2*)},
	{"getKeys", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(OpenListResourceBundle, getKeys, $Enumeration*)},
	{"handleGetObject", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PROTECTED, $virtualMethod(OpenListResourceBundle, handleGetObject, $Object*, $String*)},
	{"handleKeySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PROTECTED, $virtualMethod(OpenListResourceBundle, handleKeySet, $Set*)},
	{"keySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(OpenListResourceBundle, keySet, $Set*)},
	{"loadLookup", "()V", nullptr, $PRIVATE, $method(OpenListResourceBundle, loadLookup, void)},
	{"loadLookupTablesIfNecessary", "()V", nullptr, 0, $virtualMethod(OpenListResourceBundle, loadLookupTablesIfNecessary, void)},
	{}
};

$ClassInfo _OpenListResourceBundle_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"sun.util.resources.OpenListResourceBundle",
	"java.util.ResourceBundle",
	nullptr,
	_OpenListResourceBundle_FieldInfo_,
	_OpenListResourceBundle_MethodInfo_
};

$Object* allocate$OpenListResourceBundle($Class* clazz) {
	return $of($alloc(OpenListResourceBundle));
}

void OpenListResourceBundle::init$() {
	$ResourceBundle::init$();
}

$Object* OpenListResourceBundle::handleGetObject($String* key) {
	if (key == nullptr) {
		$throwNew($NullPointerException);
	}
	loadLookupTablesIfNecessary();
	return $of($nc(this->lookup)->get(key));
}

$Enumeration* OpenListResourceBundle::getKeys() {
	$useLocalCurrentObjectStackCache();
	$var($ResourceBundle, parentBundle, this->parent);
	$var($Set, var$0, handleKeySet());
	return $new($ResourceBundleEnumeration, var$0, (parentBundle != nullptr) ? $($nc(parentBundle)->getKeys()) : ($Enumeration*)nullptr);
}

$Set* OpenListResourceBundle::handleKeySet() {
	loadLookupTablesIfNecessary();
	return $nc(this->lookup)->keySet();
}

$Set* OpenListResourceBundle::keySet() {
	$useLocalCurrentObjectStackCache();
	if (this->keyset != nullptr) {
		return this->keyset;
	}
	$var($Set, ks, createSet());
	$nc(ks)->addAll($(handleKeySet()));
	if (this->parent != nullptr) {
		ks->addAll($($nc(this->parent)->keySet()));
	}
	$synchronized(this) {
		if (this->keyset == nullptr) {
			$set(this, keyset, ks);
		}
	}
	return this->keyset;
}

void OpenListResourceBundle::loadLookupTablesIfNecessary() {
	if (this->lookup == nullptr) {
		loadLookup();
	}
}

void OpenListResourceBundle::loadLookup() {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray2, contents, getContents());
	$var($Map, temp, createMap($nc(contents)->length));
	for (int32_t i = 0; i < $nc(contents)->length; ++i) {
		$var($String, key, $cast($String, $nc(contents->get(i))->get(0)));
		$var($Object0, value, $nc(contents->get(i))->get(1));
		if (key == nullptr || value == nullptr) {
			$throwNew($NullPointerException);
		}
		$nc(temp)->put(key, value);
	}
	$synchronized(this) {
		if (this->lookup == nullptr) {
			$set(this, lookup, temp);
		}
	}
}

$Map* OpenListResourceBundle::createMap(int32_t size) {
	return $new($HashMap, size);
}

$Set* OpenListResourceBundle::createSet() {
	return $new($HashSet);
}

OpenListResourceBundle::OpenListResourceBundle() {
}

$Class* OpenListResourceBundle::load$($String* name, bool initialize) {
	$loadClass(OpenListResourceBundle, name, initialize, &_OpenListResourceBundle_ClassInfo_, allocate$OpenListResourceBundle);
	return class$;
}

$Class* OpenListResourceBundle::class$ = nullptr;

		} // resources
	} // util
} // sun