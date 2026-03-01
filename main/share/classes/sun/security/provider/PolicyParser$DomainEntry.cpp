#include <sun/security/provider/PolicyParser$DomainEntry.h>

#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <sun/security/provider/PolicyParser$KeyStoreEntry.h>
#include <sun/security/provider/PolicyParser$ParsingException.h>
#include <sun/security/provider/PolicyParser.h>
#include <sun/security/util/LocalizedMessage.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $PolicyParser$KeyStoreEntry = ::sun::security::provider::PolicyParser$KeyStoreEntry;
using $PolicyParser$ParsingException = ::sun::security::provider::PolicyParser$ParsingException;
using $LocalizedMessage = ::sun::security::util::LocalizedMessage;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _PolicyParser$DomainEntry_FieldInfo_[] = {
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(PolicyParser$DomainEntry, name)},
	{"properties", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $FINAL, $field(PolicyParser$DomainEntry, properties)},
	{"entries", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Lsun/security/provider/PolicyParser$KeyStoreEntry;>;", $PRIVATE | $FINAL, $field(PolicyParser$DomainEntry, entries)},
	{}
};

$MethodInfo _PolicyParser$DomainEntry_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/util/Map;)V", "(Ljava/lang/String;Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)V", 0, $method(PolicyParser$DomainEntry, init$, void, $String*, $Map*)},
	{"add", "(Lsun/security/provider/PolicyParser$KeyStoreEntry;)V", nullptr, 0, $virtualMethod(PolicyParser$DomainEntry, add, void, $PolicyParser$KeyStoreEntry*), "sun.security.provider.PolicyParser$ParsingException"},
	{"getEntries", "()Ljava/util/Collection;", "()Ljava/util/Collection<Lsun/security/provider/PolicyParser$KeyStoreEntry;>;", 0, $virtualMethod(PolicyParser$DomainEntry, getEntries, $Collection*)},
	{"getName", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(PolicyParser$DomainEntry, getName, $String*)},
	{"getProperties", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", 0, $virtualMethod(PolicyParser$DomainEntry, getProperties, $Map*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PolicyParser$DomainEntry, toString, $String*)},
	{}
};

$InnerClassInfo _PolicyParser$DomainEntry_InnerClassesInfo_[] = {
	{"sun.security.provider.PolicyParser$DomainEntry", "sun.security.provider.PolicyParser", "DomainEntry", $STATIC},
	{}
};

$ClassInfo _PolicyParser$DomainEntry_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.provider.PolicyParser$DomainEntry",
	"java.lang.Object",
	nullptr,
	_PolicyParser$DomainEntry_FieldInfo_,
	_PolicyParser$DomainEntry_MethodInfo_,
	nullptr,
	nullptr,
	_PolicyParser$DomainEntry_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.provider.PolicyParser"
};

$Object* allocate$PolicyParser$DomainEntry($Class* clazz) {
	return $of($alloc(PolicyParser$DomainEntry));
}

void PolicyParser$DomainEntry::init$($String* name, $Map* properties) {
	$set(this, name, name);
	$set(this, properties, properties);
	$set(this, entries, $new($HashMap));
}

$String* PolicyParser$DomainEntry::getName() {
	return this->name;
}

$Map* PolicyParser$DomainEntry::getProperties() {
	return this->properties;
}

$Collection* PolicyParser$DomainEntry::getEntries() {
	return $nc(this->entries)->values();
}

void PolicyParser$DomainEntry::add($PolicyParser$KeyStoreEntry* entry) {
	$useLocalCurrentObjectStackCache();
	$var($String, keystoreName, $nc(entry)->getName());
	if (!$nc(this->entries)->containsKey(keystoreName)) {
		$nc(this->entries)->put(keystoreName, entry);
	} else {
		$var($LocalizedMessage, localizedMsg, $new($LocalizedMessage, "duplicate.keystore.name"_s));
		$var($ObjectArray, source, $new($ObjectArray, {$of(keystoreName)}));
		$var($String, msg, $str({"duplicate keystore name: "_s, keystoreName}));
		$throwNew($PolicyParser$ParsingException, msg, localizedMsg, source);
	}
}

$String* PolicyParser$DomainEntry::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, s, $$new($StringBuilder, "\ndomain "_s)->append(this->name));
	if (this->properties != nullptr) {
		{
			$var($Iterator, i$, $nc($($nc(this->properties)->entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, property, $cast($Map$Entry, i$->next()));
				{
					s->append("\n        "_s)->append($cast($String, $($nc(property)->getKey())))->append(u'=')->append($cast($String, $($nc(property)->getValue())));
				}
			}
		}
	}
	s->append(" {\n"_s);
	if (this->entries != nullptr) {
		{
			$var($Iterator, i$, $nc($($nc(this->entries)->values()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($PolicyParser$KeyStoreEntry, entry, $cast($PolicyParser$KeyStoreEntry, i$->next()));
				{
					s->append($of(entry))->append("\n"_s);
				}
			}
		}
	}
	s->append("}"_s);
	return s->toString();
}

PolicyParser$DomainEntry::PolicyParser$DomainEntry() {
}

$Class* PolicyParser$DomainEntry::load$($String* name, bool initialize) {
	$loadClass(PolicyParser$DomainEntry, name, initialize, &_PolicyParser$DomainEntry_ClassInfo_, allocate$PolicyParser$DomainEntry);
	return class$;
}

$Class* PolicyParser$DomainEntry::class$ = nullptr;

		} // provider
	} // security
} // sun