#include <sun/net/www/MessageHeader.h>

#include <java/io/InputStream.h>
#include <java/lang/CharSequence.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/StringJoiner.h>
#include <sun/net/www/MessageHeader$HeaderIterator.h>
#include <jcpp.h>

using $InputStream = ::java::io::InputStream;
using $PrintStream = ::java::io::PrintStream;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $StringJoiner = ::java::util::StringJoiner;
using $MessageHeader$HeaderIterator = ::sun::net::www::MessageHeader$HeaderIterator;

namespace sun {
	namespace net {
		namespace www {

$FieldInfo _MessageHeader_FieldInfo_[] = {
	{"keys", "[Ljava/lang/String;", nullptr, $PRIVATE, $field(MessageHeader, keys)},
	{"values", "[Ljava/lang/String;", nullptr, $PRIVATE, $field(MessageHeader, values)},
	{"nkeys", "I", nullptr, $PRIVATE, $field(MessageHeader, nkeys)},
	{}
};

$MethodInfo _MessageHeader_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(MessageHeader, init$, void)},
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(MessageHeader, init$, void, $InputStream*), "java.io.IOException"},
	{"add", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MessageHeader, add, void, $String*, $String*)},
	{"canonicalID", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(MessageHeader, canonicalID, $String*, $String*)},
	{"filterAndAddHeaders", "([Ljava/lang/String;Ljava/util/Map;)Ljava/util/Map;", "([Ljava/lang/String;Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;)Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(MessageHeader, filterAndAddHeaders, $Map*, $StringArray*, $Map*)},
	{"filterNTLMResponses", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(MessageHeader, filterNTLMResponses, bool, $String*)},
	{"findNextValue", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MessageHeader, findNextValue, $String*, $String*, $String*)},
	{"findValue", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MessageHeader, findValue, $String*, $String*)},
	{"getHeaderNamesInList", "()Ljava/lang/String;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MessageHeader, getHeaderNamesInList, $String*)},
	{"getHeaders", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(MessageHeader, getHeaders, $Map*)},
	{"getHeaders", "([Ljava/lang/String;)Ljava/util/Map;", "([Ljava/lang/String;)Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(MessageHeader, getHeaders, $Map*, $StringArray*)},
	{"getKey", "(Ljava/lang/String;)I", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MessageHeader, getKey, int32_t, $String*)},
	{"getKey", "(I)Ljava/lang/String;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MessageHeader, getKey, $String*, int32_t)},
	{"getValue", "(I)Ljava/lang/String;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MessageHeader, getValue, $String*, int32_t)},
	{"grow", "()V", nullptr, $PRIVATE, $method(MessageHeader, grow, void)},
	{"isRequestline", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(MessageHeader, isRequestline, bool, $String*)},
	{"mergeHeader", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $virtualMethod(MessageHeader, mergeHeader, void, $InputStream*), "java.io.IOException"},
	{"multiValueIterator", "(Ljava/lang/String;)Ljava/util/Iterator;", "(Ljava/lang/String;)Ljava/util/Iterator<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(MessageHeader, multiValueIterator, $Iterator*, $String*)},
	{"parseHeader", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $virtualMethod(MessageHeader, parseHeader, void, $InputStream*), "java.io.IOException"},
	{"prepend", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MessageHeader, prepend, void, $String*, $String*)},
	{"print", "(Ljava/io/PrintStream;)V", nullptr, $PUBLIC, $virtualMethod(MessageHeader, print, void, $PrintStream*)},
	{"print", "(I[Ljava/lang/String;[Ljava/lang/String;Ljava/io/PrintStream;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(MessageHeader, print, void, int32_t, $StringArray*, $StringArray*, $PrintStream*)},
	{"remove", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MessageHeader, remove, void, $String*)},
	{"reset", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MessageHeader, reset, void)},
	{"set", "(ILjava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MessageHeader, set, void, int32_t, $String*, $String*)},
	{"set", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MessageHeader, set, void, $String*, $String*)},
	{"setIfNotSet", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MessageHeader, setIfNotSet, void, $String*, $String*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MessageHeader, toString, $String*)},
	{}
};

$InnerClassInfo _MessageHeader_InnerClassesInfo_[] = {
	{"sun.net.www.MessageHeader$HeaderIterator", "sun.net.www.MessageHeader", "HeaderIterator", 0},
	{}
};

$ClassInfo _MessageHeader_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.net.www.MessageHeader",
	"java.lang.Object",
	nullptr,
	_MessageHeader_FieldInfo_,
	_MessageHeader_MethodInfo_,
	nullptr,
	nullptr,
	_MessageHeader_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.net.www.MessageHeader$HeaderIterator"
};

$Object* allocate$MessageHeader($Class* clazz) {
	return $of($alloc(MessageHeader));
}

void MessageHeader::init$() {
	grow();
}

void MessageHeader::init$($InputStream* is) {
	parseHeader(is);
}

$String* MessageHeader::getHeaderNamesInList() {
	$synchronized(this) {
		$var($StringJoiner, joiner, $new($StringJoiner, ","_s));
		for (int32_t i = 0; i < this->nkeys; ++i) {
			joiner->add($nc(this->keys)->get(i));
		}
		return joiner->toString();
	}
}

void MessageHeader::reset() {
	$synchronized(this) {
		$set(this, keys, nullptr);
		$set(this, values, nullptr);
		this->nkeys = 0;
		grow();
	}
}

$String* MessageHeader::findValue($String* k) {
	$synchronized(this) {
		if (k == nullptr) {
			for (int32_t i = this->nkeys; --i >= 0;) {
				if ($nc(this->keys)->get(i) == nullptr) {
					return $nc(this->values)->get(i);
				}
			}
		} else {
			for (int32_t i = this->nkeys; --i >= 0;) {
				if ($nc(k)->equalsIgnoreCase($nc(this->keys)->get(i))) {
					return $nc(this->values)->get(i);
				}
			}
		}
		return nullptr;
	}
}

int32_t MessageHeader::getKey($String* k) {
	$synchronized(this) {
		for (int32_t i = this->nkeys; --i >= 0;) {
			if (($nc(this->keys)->get(i) == k) || (k != nullptr && k->equalsIgnoreCase($nc(this->keys)->get(i)))) {
				return i;
			}
		}
		return -1;
	}
}

$String* MessageHeader::getKey(int32_t n) {
	$synchronized(this) {
		if (n < 0 || n >= this->nkeys) {
			return nullptr;
		}
		return $nc(this->keys)->get(n);
	}
}

$String* MessageHeader::getValue(int32_t n) {
	$synchronized(this) {
		if (n < 0 || n >= this->nkeys) {
			return nullptr;
		}
		return $nc(this->values)->get(n);
	}
}

$String* MessageHeader::findNextValue($String* k, $String* v) {
	$synchronized(this) {
		bool foundV = false;
		if (k == nullptr) {
			for (int32_t i = this->nkeys; --i >= 0;) {
				if ($nc(this->keys)->get(i) == nullptr) {
					if (foundV) {
						return $nc(this->values)->get(i);
					} else if ($nc(this->values)->get(i) == v) {
						foundV = true;
					}
				}
			}
		} else {
			for (int32_t i = this->nkeys; --i >= 0;) {
				if ($nc(k)->equalsIgnoreCase($nc(this->keys)->get(i))) {
					if (foundV) {
						return $nc(this->values)->get(i);
					} else if ($nc(this->values)->get(i) == v) {
						foundV = true;
					}
				}
			}
		}
		return nullptr;
	}
}

bool MessageHeader::filterNTLMResponses($String* k) {
	$useLocalCurrentObjectStackCache();
	bool found = false;
	for (int32_t i = 0; i < this->nkeys; ++i) {
		bool var$1 = $nc(k)->equalsIgnoreCase($nc(this->keys)->get(i)) && $nc(this->values)->get(i) != nullptr;
		bool var$0 = var$1 && $nc($nc(this->values)->get(i))->length() > 5;
		if (var$0 && $($nc($nc(this->values)->get(i))->substring(0, 5))->equalsIgnoreCase("NTLM "_s)) {
			found = true;
			break;
		}
	}
	if (found) {
		int32_t j = 0;
		for (int32_t i = 0; i < this->nkeys; ++i) {
			bool var$2 = $nc(k)->equalsIgnoreCase($nc(this->keys)->get(i));
			if (var$2) {
				bool var$3 = "Negotiate"_s->equalsIgnoreCase($nc(this->values)->get(i));
				var$2 = (var$3 || "Kerberos"_s->equalsIgnoreCase($nc(this->values)->get(i)));
			}
			if (var$2) {
				continue;
			}
			if (i != j) {
				$nc(this->keys)->set(j, $nc(this->keys)->get(i));
				$nc(this->values)->set(j, $nc(this->values)->get(i));
			}
			++j;
		}
		if (j != this->nkeys) {
			this->nkeys = j;
			return true;
		}
	}
	return false;
}

$Iterator* MessageHeader::multiValueIterator($String* k) {
	return $new($MessageHeader$HeaderIterator, this, k, this);
}

$Map* MessageHeader::getHeaders() {
	$synchronized(this) {
		return getHeaders(nullptr);
	}
}

$Map* MessageHeader::getHeaders($StringArray* excludeList) {
	$synchronized(this) {
		return filterAndAddHeaders(excludeList, nullptr);
	}
}

$Map* MessageHeader::filterAndAddHeaders($StringArray* excludeList, $Map* include) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		bool skipIt = false;
		$var($Map, m, $new($HashMap));
		for (int32_t i = this->nkeys; --i >= 0;) {
			if (excludeList != nullptr) {
				for (int32_t j = 0; j < excludeList->length; ++j) {
					if ((excludeList->get(j) != nullptr) && ($nc(excludeList->get(j))->equalsIgnoreCase($nc(this->keys)->get(i)))) {
						skipIt = true;
						break;
					}
				}
			}
			if (!skipIt) {
				$var($List, l, $cast($List, m->get($nc(this->keys)->get(i))));
				if (l == nullptr) {
					$assign(l, $new($ArrayList));
					m->put($nc(this->keys)->get(i), l);
				}
				$nc(l)->add($nc(this->values)->get(i));
			} else {
				skipIt = false;
			}
		}
		if (include != nullptr) {
			{
				$var($Iterator, i$, $nc($(include->entrySet()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
					{
						$var($List, l, $cast($List, m->get($($nc(entry)->getKey()))));
						if (l == nullptr) {
							$assign(l, $new($ArrayList));
							m->put($cast($String, $($nc(entry)->getKey())), l);
						}
						$nc(l)->addAll($cast($Collection, $($nc(entry)->getValue())));
					}
				}
			}
		}
		{
			$var($Iterator, i$, $nc($(m->keySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, key, $cast($String, i$->next()));
				{
					m->put(key, $($Collections::unmodifiableList($cast($List, $(m->get(key))))));
				}
			}
		}
		return $Collections::unmodifiableMap(m);
	}
}

bool MessageHeader::isRequestline($String* line) {
	$useLocalCurrentObjectStackCache();
	$var($String, k, $nc(line)->trim());
	int32_t i = k->lastIndexOf((int32_t)u' ');
	if (i <= 0) {
		return false;
	}
	int32_t len = k->length();
	if (len - i < 9) {
		return false;
	}
	char16_t c1 = k->charAt(len - 3);
	char16_t c2 = k->charAt(len - 2);
	char16_t c3 = k->charAt(len - 1);
	if (c1 < u'1' || c1 > u'9') {
		return false;
	}
	if (c2 != u'.') {
		return false;
	}
	if (c3 < u'0' || c3 > u'9') {
		return false;
	}
	return ($(k->substring(i + 1, len - 3))->equalsIgnoreCase("HTTP/"_s));
}

void MessageHeader::print($PrintStream* p) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, k, nullptr);
	$var($StringArray, v, nullptr);
	int32_t n = 0;
	$synchronized(this) {
		n = this->nkeys;
		$assign(k, $cast($StringArray, $nc(this->keys)->clone()));
		$assign(v, $cast($StringArray, $nc(this->values)->clone()));
	}
	print(n, k, v, p);
}

void MessageHeader::print(int32_t nkeys, $StringArray* keys, $StringArray* values, $PrintStream* p) {
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < nkeys; ++i) {
		if ($nc(keys)->get(i) != nullptr) {
			$var($StringBuilder, sb, $new($StringBuilder, keys->get(i)));
			if ($nc(values)->get(i) != nullptr) {
				sb->append($$str({": "_s, values->get(i)}));
			} else if (i != 0 || !isRequestline(keys->get(i))) {
				sb->append(":"_s);
			}
			$nc(p)->print($of(sb->append("\r\n"_s)));
		}
	}
	$nc(p)->print("\r\n"_s);
	p->flush();
}

void MessageHeader::add($String* k, $String* v) {
	$synchronized(this) {
		grow();
		$nc(this->keys)->set(this->nkeys, k);
		$nc(this->values)->set(this->nkeys, v);
		++this->nkeys;
	}
}

void MessageHeader::prepend($String* k, $String* v) {
	$synchronized(this) {
		grow();
		for (int32_t i = this->nkeys; i > 0; --i) {
			$nc(this->keys)->set(i, $nc(this->keys)->get(i - 1));
			$nc(this->values)->set(i, $nc(this->values)->get(i - 1));
		}
		$nc(this->keys)->set(0, k);
		$nc(this->values)->set(0, v);
		++this->nkeys;
	}
}

void MessageHeader::set(int32_t i, $String* k, $String* v) {
	$synchronized(this) {
		grow();
		if (i < 0) {
			return;
		} else if (i >= this->nkeys) {
			add(k, v);
		} else {
			$nc(this->keys)->set(i, k);
			$nc(this->values)->set(i, v);
		}
	}
}

void MessageHeader::grow() {
	$useLocalCurrentObjectStackCache();
	if (this->keys == nullptr || this->nkeys >= $nc(this->keys)->length) {
		$var($StringArray, nk, $new($StringArray, this->nkeys + 4));
		$var($StringArray, nv, $new($StringArray, this->nkeys + 4));
		if (this->keys != nullptr) {
			$System::arraycopy(this->keys, 0, nk, 0, this->nkeys);
		}
		if (this->values != nullptr) {
			$System::arraycopy(this->values, 0, nv, 0, this->nkeys);
		}
		$set(this, keys, nk);
		$set(this, values, nv);
	}
}

void MessageHeader::remove($String* k) {
	$synchronized(this) {
		if (k == nullptr) {
			for (int32_t i = 0; i < this->nkeys; ++i) {
				while ($nc(this->keys)->get(i) == nullptr && i < this->nkeys) {
					for (int32_t j = i; j < this->nkeys - 1; ++j) {
						$nc(this->keys)->set(j, $nc(this->keys)->get(j + 1));
						$nc(this->values)->set(j, $nc(this->values)->get(j + 1));
					}
					--this->nkeys;
				}
			}
		} else {
			for (int32_t i = 0; i < this->nkeys; ++i) {
				while ($nc(k)->equalsIgnoreCase($nc(this->keys)->get(i)) && i < this->nkeys) {
					for (int32_t j = i; j < this->nkeys - 1; ++j) {
						$nc(this->keys)->set(j, $nc(this->keys)->get(j + 1));
						$nc(this->values)->set(j, $nc(this->values)->get(j + 1));
					}
					--this->nkeys;
				}
			}
		}
	}
}

void MessageHeader::set($String* k, $String* v) {
	$synchronized(this) {
		for (int32_t i = this->nkeys; --i >= 0;) {
			if ($nc(k)->equalsIgnoreCase($nc(this->keys)->get(i))) {
				$nc(this->values)->set(i, v);
				return;
			}
		}
		add(k, v);
	}
}

void MessageHeader::setIfNotSet($String* k, $String* v) {
	$synchronized(this) {
		if (findValue(k) == nullptr) {
			add(k, v);
		}
	}
}

$String* MessageHeader::canonicalID($String* id) {
	if (id == nullptr) {
		return ""_s;
	}
	int32_t st = 0;
	int32_t len = $nc(id)->length();
	bool substr = false;
	int32_t c = 0;
	while (st < len && ((c = id->charAt(st)) == u'<' || c <= u' ')) {
		++st;
		substr = true;
	}
	while (st < len && ((c = id->charAt(len - 1)) == u'>' || c <= u' ')) {
		--len;
		substr = true;
	}
	return substr ? id->substring(st, len) : id;
}

void MessageHeader::parseHeader($InputStream* is) {
	$synchronized(this) {
		this->nkeys = 0;
	}
	mergeHeader(is);
}

void MessageHeader::mergeHeader($InputStream* is) {
	$useLocalCurrentObjectStackCache();
	if (is == nullptr) {
		return;
	}
	$var($chars, s, $new($chars, 10));
	int32_t firstc = $nc(is)->read();
	while (firstc != u'\n' && firstc != u'\r' && firstc >= 0) {
		int32_t len = 0;
		int32_t keyend = -1;
		int32_t c = 0;
		bool inKey = firstc > u' ';
		$nc(s)->set(len++, (char16_t)firstc);
		bool parseloop$break = false;
		for (;;) {
			{
				while ((c = is->read()) >= 0) {
					switch (c) {
					case u':':
						{
							if (inKey && len > 0) {
								keyend = len;
							}
							inKey = false;
							break;
						}
					case u'\t':
						{
							c = u' ';
						}
					case u' ':
						{
							inKey = false;
							break;
						}
					case u'\r':
						{}
					case u'\n':
						{
							firstc = is->read();
							if (c == u'\r' && firstc == u'\n') {
								firstc = is->read();
								if (firstc == u'\r') {
									firstc = is->read();
								}
							}
							if (firstc == u'\n' || firstc == u'\r' || firstc > u' ') {
								parseloop$break = true;
								break;
							}
							c = u' ';
							break;
						}
					}

					if (parseloop$break) {
						break;
					}					if (len >= $nc(s)->length) {
						$var($chars, ns, $new($chars, s->length * 2));
						$System::arraycopy(s, 0, ns, 0, len);
						$assign(s, ns);
					}
					$nc(s)->set(len++, (char16_t)c);
				}
				if (parseloop$break) {
					break;
				}
				firstc = -1;
			}
			break;
		}
		while (len > 0 && s->get(len - 1) <= u' ') {
			--len;
		}
		$var($String, k, nullptr);
		if (keyend <= 0) {
			$assign(k, nullptr);
			keyend = 0;
		} else {
			$assign(k, $String::copyValueOf(s, 0, keyend));
			if (keyend < len && s->get(keyend) == u':') {
				++keyend;
			}
			while (keyend < len && s->get(keyend) <= u' ') {
				++keyend;
			}
		}
		$var($String, v, nullptr);
		if (keyend >= len) {
			$assign(v, $new($String));
		} else {
			$assign(v, $String::copyValueOf(s, keyend, len - keyend));
		}
		add(k, v);
	}
}

$String* MessageHeader::toString() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($String, result, $str({$($Object::toString()), $$str(this->nkeys), " pairs: "_s}));
		for (int32_t i = 0; i < $nc(this->keys)->length && i < this->nkeys; ++i) {
			$plusAssign(result, $$str({"{"_s, $nc(this->keys)->get(i), ": "_s, $nc(this->values)->get(i), "}"_s}));
		}
		return result;
	}
}

MessageHeader::MessageHeader() {
}

$Class* MessageHeader::load$($String* name, bool initialize) {
	$loadClass(MessageHeader, name, initialize, &_MessageHeader_ClassInfo_, allocate$MessageHeader);
	return class$;
}

$Class* MessageHeader::class$ = nullptr;

		} // www
	} // net
} // sun