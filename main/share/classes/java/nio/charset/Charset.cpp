#include <java/nio/charset/Charset.h>

#include <java/lang/CharSequence.h>
#include <java/lang/Error.h>
#include <java/lang/ThreadLocal.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/nio/charset/CharacterCodingException.h>
#include <java/nio/charset/Charset$1.h>
#include <java/nio/charset/Charset$2.h>
#include <java/nio/charset/Charset$3.h>
#include <java/nio/charset/Charset$ExtendedProviderHolder.h>
#include <java/nio/charset/CharsetDecoder.h>
#include <java/nio/charset/CharsetEncoder.h>
#include <java/nio/charset/CodingErrorAction.h>
#include <java/nio/charset/IllegalCharsetNameException.h>
#include <java/nio/charset/UnsupportedCharsetException.h>
#include <java/nio/charset/spi/CharsetProvider.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/SortedMap.h>
#include <jdk/internal/misc/VM.h>
#include <sun/nio/cs/StandardCharsets.h>
#include <sun/nio/cs/ThreadLocalCoders.h>
#include <sun/nio/cs/UTF_8.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef INSTANCE
#undef REPLACE

using $CharsetProviderArray = $Array<::java::nio::charset::spi::CharsetProvider>;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ThreadLocal = ::java::lang::ThreadLocal;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CharBuffer = ::java::nio::CharBuffer;
using $CharacterCodingException = ::java::nio::charset::CharacterCodingException;
using $Charset$1 = ::java::nio::charset::Charset$1;
using $Charset$2 = ::java::nio::charset::Charset$2;
using $Charset$3 = ::java::nio::charset::Charset$3;
using $Charset$ExtendedProviderHolder = ::java::nio::charset::Charset$ExtendedProviderHolder;
using $CharsetDecoder = ::java::nio::charset::CharsetDecoder;
using $CharsetEncoder = ::java::nio::charset::CharsetEncoder;
using $CodingErrorAction = ::java::nio::charset::CodingErrorAction;
using $IllegalCharsetNameException = ::java::nio::charset::IllegalCharsetNameException;
using $UnsupportedCharsetException = ::java::nio::charset::UnsupportedCharsetException;
using $CharsetProvider = ::java::nio::charset::spi::CharsetProvider;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $SortedMap = ::java::util::SortedMap;
using $VM = ::jdk::internal::misc::VM;
using $StandardCharsets = ::sun::nio::cs::StandardCharsets;
using $ThreadLocalCoders = ::sun::nio::cs::ThreadLocalCoders;
using $UTF_8 = ::sun::nio::cs::UTF_8;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace java {
	namespace nio {
		namespace charset {

$FieldInfo _Charset_FieldInfo_[] = {
	{"standardProvider", "Ljava/nio/charset/spi/CharsetProvider;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Charset, standardProvider)},
	{"zeroAliases", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Charset, zeroAliases)},
	{"cache1", "[Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(Charset, cache1)},
	{"cache2", "[Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(Charset, cache2)},
	{"gate", "Ljava/lang/ThreadLocal;", "Ljava/lang/ThreadLocal<Ljava/lang/ThreadLocal<*>;>;", $PRIVATE | $STATIC, $staticField(Charset, gate)},
	{"defaultCharset", "Ljava/nio/charset/Charset;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(Charset, defaultCharset$)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Charset, name$)},
	{"aliases", "[Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Charset, aliases$)},
	{"aliasSet", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE, $field(Charset, aliasSet)},
	{}
};

$MethodInfo _Charset_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;[Ljava/lang/String;)V", nullptr, $PROTECTED, $method(Charset, init$, void, $String*, $StringArray*)},
	{"aliases", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC | $FINAL, $method(Charset, aliases, $Set*)},
	{"availableCharsets", "()Ljava/util/SortedMap;", "()Ljava/util/SortedMap<Ljava/lang/String;Ljava/nio/charset/Charset;>;", $PUBLIC | $STATIC, $staticMethod(Charset, availableCharsets, $SortedMap*)},
	{"cache", "(Ljava/lang/String;Ljava/nio/charset/Charset;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Charset, cache, void, $String*, Charset*)},
	{"canEncode", "()Z", nullptr, $PUBLIC, $virtualMethod(Charset, canEncode, bool)},
	{"checkName", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Charset, checkName, void, $String*)},
	{"compareTo", "(Ljava/nio/charset/Charset;)I", nullptr, $PUBLIC | $FINAL, $method(Charset, compareTo, int32_t, Charset*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Charset, compareTo, int32_t, Object$*)},
	{"contains", "(Ljava/nio/charset/Charset;)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Charset, contains, bool, Charset*)},
	{"decode", "(Ljava/nio/ByteBuffer;)Ljava/nio/CharBuffer;", nullptr, $PUBLIC | $FINAL, $method(Charset, decode, $CharBuffer*, $ByteBuffer*)},
	{"defaultCharset", "()Ljava/nio/charset/Charset;", nullptr, $PUBLIC | $STATIC, $staticMethod(Charset, defaultCharset, Charset*)},
	{"displayName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Charset, displayName, $String*)},
	{"displayName", "(Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Charset, displayName, $String*, $Locale*)},
	{"encode", "(Ljava/nio/CharBuffer;)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $FINAL, $method(Charset, encode, $ByteBuffer*, $CharBuffer*)},
	{"encode", "(Ljava/lang/String;)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $FINAL, $method(Charset, encode, $ByteBuffer*, $String*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(Charset, equals, bool, Object$*)},
	{"forName", "(Ljava/lang/String;)Ljava/nio/charset/Charset;", nullptr, $PUBLIC | $STATIC, $staticMethod(Charset, forName, Charset*, $String*)},
	{"hashCode", "()I", nullptr, $PUBLIC | $FINAL, $virtualMethod(Charset, hashCode, int32_t)},
	{"isRegistered", "()Z", nullptr, $PUBLIC | $FINAL, $method(Charset, isRegistered, bool)},
	{"isSupported", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(Charset, isSupported, bool, $String*)},
	{"lookup", "(Ljava/lang/String;)Ljava/nio/charset/Charset;", nullptr, $PRIVATE | $STATIC, $staticMethod(Charset, lookup, Charset*, $String*)},
	{"lookup2", "(Ljava/lang/String;)Ljava/nio/charset/Charset;", nullptr, $PRIVATE | $STATIC, $staticMethod(Charset, lookup2, Charset*, $String*)},
	{"lookupExtendedCharset", "(Ljava/lang/String;)Ljava/nio/charset/Charset;", nullptr, $PRIVATE | $STATIC, $staticMethod(Charset, lookupExtendedCharset, Charset*, $String*)},
	{"lookupViaProviders", "(Ljava/lang/String;)Ljava/nio/charset/Charset;", nullptr, $PRIVATE | $STATIC, $staticMethod(Charset, lookupViaProviders, Charset*, $String*)},
	{"name", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $method(Charset, name, $String*)},
	{"newDecoder", "()Ljava/nio/charset/CharsetDecoder;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Charset, newDecoder, $CharsetDecoder*)},
	{"newEncoder", "()Ljava/nio/charset/CharsetEncoder;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Charset, newEncoder, $CharsetEncoder*)},
	{"providers", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Ljava/nio/charset/spi/CharsetProvider;>;", $PRIVATE | $STATIC, $staticMethod(Charset, providers, $Iterator*)},
	{"put", "(Ljava/util/Iterator;Ljava/util/Map;)V", "(Ljava/util/Iterator<Ljava/nio/charset/Charset;>;Ljava/util/Map<Ljava/lang/String;Ljava/nio/charset/Charset;>;)V", $PRIVATE | $STATIC, $staticMethod(Charset, put, void, $Iterator*, $Map*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $virtualMethod(Charset, toString, $String*)},
	{}
};

$InnerClassInfo _Charset_InnerClassesInfo_[] = {
	{"java.nio.charset.Charset$ExtendedProviderHolder", "java.nio.charset.Charset", "ExtendedProviderHolder", $PRIVATE | $STATIC},
	{"java.nio.charset.Charset$3", nullptr, nullptr, 0},
	{"java.nio.charset.Charset$2", nullptr, nullptr, 0},
	{"java.nio.charset.Charset$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Charset_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.nio.charset.Charset",
	"java.lang.Object",
	"java.lang.Comparable",
	_Charset_FieldInfo_,
	_Charset_MethodInfo_,
	"Ljava/lang/Object;Ljava/lang/Comparable<Ljava/nio/charset/Charset;>;",
	nullptr,
	_Charset_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.nio.charset.Charset$ExtendedProviderHolder,java.nio.charset.Charset$ExtendedProviderHolder$1,java.nio.charset.Charset$3,java.nio.charset.Charset$2,java.nio.charset.Charset$1"
};

$Object* allocate$Charset($Class* clazz) {
	return $of($alloc(Charset));
}

$CharsetProvider* Charset::standardProvider = nullptr;
$StringArray* Charset::zeroAliases = nullptr;
$volatile($ObjectArray*) Charset::cache1 = nullptr;
$volatile($ObjectArray*) Charset::cache2 = nullptr;
$ThreadLocal* Charset::gate = nullptr;
$volatile(Charset*) Charset::defaultCharset$ = nullptr;

void Charset::checkName($String* s) {
	$init(Charset);
	int32_t n = $nc(s)->length();
	if (n == 0) {
		$throwNew($IllegalCharsetNameException, s);
	}
	for (int32_t i = 0; i < n; ++i) {
		char16_t c = s->charAt(i);
		if (c >= u'A' && c <= u'Z') {
			continue;
		}
		if (c >= u'a' && c <= u'z') {
			continue;
		}
		if (c >= u'0' && c <= u'9') {
			continue;
		}
		if (c == u'-' && i != 0) {
			continue;
		}
		if (c == u'+' && i != 0) {
			continue;
		}
		if (c == u':' && i != 0) {
			continue;
		}
		if (c == u'_' && i != 0) {
			continue;
		}
		if (c == u'.' && i != 0) {
			continue;
		}
		$throwNew($IllegalCharsetNameException, s);
	}
}

void Charset::cache($String* charsetName, Charset* cs) {
	$init(Charset);
	$assignStatic(Charset::cache2, Charset::cache1);
	$assignStatic(Charset::cache1, $new($ObjectArray, {
		$of(charsetName),
		$of(cs)
	}));
}

$Iterator* Charset::providers() {
	$init(Charset);
	return $new($Charset$1);
}

Charset* Charset::lookupViaProviders($String* charsetName) {
	$init(Charset);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (!$VM::isBooted()) {
		return nullptr;
	}
	if ($nc(Charset::gate)->get() != nullptr) {
		return nullptr;
	}
	{
		$var($Throwable, var$0, nullptr);
		$var(Charset, var$2, nullptr);
		bool return$1 = false;
		try {
			$nc(Charset::gate)->set(Charset::gate);
			$assign(var$2, $cast(Charset, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Charset$2, charsetName)))));
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(Charset::gate)->set(nullptr);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

Charset* Charset::lookupExtendedCharset($String* charsetName) {
	$init(Charset);
	$useLocalCurrentObjectStackCache();
	if (!$VM::isBooted()) {
		return nullptr;
	}
	$init($Charset$ExtendedProviderHolder);
	$var($CharsetProviderArray, ecps, $Charset$ExtendedProviderHolder::extendedProviders$);
	{
		$var($CharsetProviderArray, arr$, ecps);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($CharsetProvider, cp, arr$->get(i$));
			{
				$var(Charset, cs, $nc(cp)->charsetForName(charsetName));
				if (cs != nullptr) {
					return cs;
				}
			}
		}
	}
	return nullptr;
}

Charset* Charset::lookup($String* charsetName) {
	$init(Charset);
	if (charsetName == nullptr) {
		$throwNew($IllegalArgumentException, "Null charset name"_s);
	}
	$var($ObjectArray, a, nullptr);
	bool var$0 = ($assign(a, Charset::cache1)) != nullptr;
	if (var$0 && $nc(charsetName)->equals($nc(a)->get(0))) {
		return $cast(Charset, $nc(a)->get(1));
	}
	return lookup2(charsetName);
}

Charset* Charset::lookup2($String* charsetName) {
	$init(Charset);
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, a, nullptr);
	bool var$0 = ($assign(a, Charset::cache2)) != nullptr;
	if (var$0 && $nc(charsetName)->equals($nc(a)->get(0))) {
		$assignStatic(Charset::cache2, Charset::cache1);
		$assignStatic(Charset::cache1, a);
		return $cast(Charset, $nc(a)->get(1));
	}
	$var(Charset, cs, nullptr);
	bool var$2 = ($assign(cs, $nc(Charset::standardProvider)->charsetForName(charsetName))) != nullptr;
	bool var$1 = var$2 || ($assign(cs, lookupExtendedCharset(charsetName))) != nullptr;
	if (var$1 || ($assign(cs, lookupViaProviders(charsetName))) != nullptr) {
		cache(charsetName, cs);
		return cs;
	}
	checkName(charsetName);
	return nullptr;
}

bool Charset::isSupported($String* charsetName) {
	$init(Charset);
	return (lookup(charsetName) != nullptr);
}

Charset* Charset::forName($String* charsetName) {
	$init(Charset);
	$var(Charset, cs, lookup(charsetName));
	if (cs != nullptr) {
		return cs;
	}
	$throwNew($UnsupportedCharsetException, charsetName);
}

void Charset::put($Iterator* i, $Map* m) {
	$init(Charset);
	$useLocalCurrentObjectStackCache();
	while ($nc(i)->hasNext()) {
		$var(Charset, cs, $cast(Charset, i->next()));
		if (!$nc(m)->containsKey($($nc(cs)->name()))) {
			m->put($($nc(cs)->name()), cs);
		}
	}
}

$SortedMap* Charset::availableCharsets() {
	$init(Charset);
	$beforeCallerSensitive();
	return $cast($SortedMap, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Charset$3))));
}

Charset* Charset::defaultCharset() {
	$init(Charset);
	$useLocalCurrentObjectStackCache();
	if (Charset::defaultCharset$ == nullptr) {
		$synchronized(Charset::class$) {
			$var($String, csn, $GetPropertyAction::privilegedGetProperty("file.encoding"_s));
			$var(Charset, cs, lookup(csn));
			if (cs != nullptr) {
				$assignStatic(Charset::defaultCharset$, cs);
			} else {
				$init($UTF_8);
				$assignStatic(Charset::defaultCharset$, $UTF_8::INSTANCE);
			}
		}
	}
	return Charset::defaultCharset$;
}

void Charset::init$($String* canonicalName, $StringArray* aliases) {
	$set(this, aliasSet, nullptr);
	$var($StringArray, as, $cast($StringArray, $Objects::requireNonNullElse(aliases, Charset::zeroAliases)));
	if (canonicalName != "ISO-8859-1"_s && canonicalName != "US-ASCII"_s && canonicalName != "UTF-8"_s) {
		checkName(canonicalName);
		for (int32_t i = 0; i < $nc(as)->length; ++i) {
			checkName(as->get(i));
		}
	}
	$set(this, name$, canonicalName);
	$set(this, aliases$, as);
}

$String* Charset::name() {
	return this->name$;
}

$Set* Charset::aliases() {
	if (this->aliasSet != nullptr) {
		return this->aliasSet;
	}
	int32_t n = $nc(this->aliases$)->length;
	$var($HashSet, hs, $new($HashSet, n));
	for (int32_t i = 0; i < n; ++i) {
		hs->add($nc(this->aliases$)->get(i));
	}
	$set(this, aliasSet, $Collections::unmodifiableSet(hs));
	return this->aliasSet;
}

$String* Charset::displayName() {
	return this->name$;
}

bool Charset::isRegistered() {
	bool var$0 = !$nc(this->name$)->startsWith("X-"_s);
	return var$0 && !$nc(this->name$)->startsWith("x-"_s);
}

$String* Charset::displayName($Locale* locale) {
	return this->name$;
}

bool Charset::canEncode() {
	return true;
}

$CharBuffer* Charset::decode($ByteBuffer* bb) {
	$useLocalCurrentObjectStackCache();
	try {
		$init($CodingErrorAction);
		return $nc($($nc($($nc($($ThreadLocalCoders::decoderFor(this)))->onMalformedInput($CodingErrorAction::REPLACE)))->onUnmappableCharacter($CodingErrorAction::REPLACE)))->decode(bb);
	} catch ($CharacterCodingException& x) {
		$throwNew($Error, static_cast<$Throwable*>(x));
	}
	$shouldNotReachHere();
}

$ByteBuffer* Charset::encode($CharBuffer* cb) {
	$useLocalCurrentObjectStackCache();
	try {
		$init($CodingErrorAction);
		return $nc($($nc($($nc($($ThreadLocalCoders::encoderFor(this)))->onMalformedInput($CodingErrorAction::REPLACE)))->onUnmappableCharacter($CodingErrorAction::REPLACE)))->encode(cb);
	} catch ($CharacterCodingException& x) {
		$throwNew($Error, static_cast<$Throwable*>(x));
	}
	$shouldNotReachHere();
}

$ByteBuffer* Charset::encode($String* str) {
	return encode($($CharBuffer::wrap(static_cast<$CharSequence*>(str))));
}

int32_t Charset::compareTo(Charset* that) {
	$useLocalCurrentObjectStackCache();
	return ($nc($(name()))->compareToIgnoreCase($($nc(that)->name())));
}

int32_t Charset::hashCode() {
	return $nc($(name()))->hashCode();
}

bool Charset::equals(Object$* ob) {
	if (!($instanceOf(Charset, ob))) {
		return false;
	}
	if ($equals(this, ob)) {
		return true;
	}
	return $nc(this->name$)->equals($($nc(($cast(Charset, ob)))->name()));
}

$String* Charset::toString() {
	return name();
}

int32_t Charset::compareTo(Object$* that) {
	return this->compareTo($cast(Charset, that));
}

void clinit$Charset($Class* class$) {
	$assignStatic(Charset::standardProvider, $new($StandardCharsets));
	$assignStatic(Charset::zeroAliases, $new($StringArray, 0));
	$assignStatic(Charset::gate, $new($ThreadLocal));
}

Charset::Charset() {
}

$Class* Charset::load$($String* name, bool initialize) {
	$loadClass(Charset, name, initialize, &_Charset_ClassInfo_, clinit$Charset, allocate$Charset);
	return class$;
}

$Class* Charset::class$ = nullptr;

		} // charset
	} // nio
} // java