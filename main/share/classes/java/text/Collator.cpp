#include <java/text/Collator.h>

#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/lang/ref/SoftReference.h>
#include <java/text/CollationKey.h>
#include <java/text/spi/CollatorProvider.h>
#include <java/util/Comparator.h>
#include <java/util/Locale.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <sun/util/locale/provider/LocaleProviderAdapter.h>
#include <sun/util/locale/provider/LocaleServiceProviderPool.h>
#include <jcpp.h>

#undef CANONICAL_DECOMPOSITION
#undef EQUAL
#undef FULL_DECOMPOSITION
#undef GREATER
#undef IDENTICAL
#undef LESS
#undef NO_DECOMPOSITION
#undef PRIMARY
#undef SECONDARY
#undef TERTIARY

using $LocaleArray = $Array<::java::util::Locale>;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $SoftReference = ::java::lang::ref::SoftReference;
using $CollationKey = ::java::text::CollationKey;
using $CollatorProvider = ::java::text::spi::CollatorProvider;
using $Comparator = ::java::util::Comparator;
using $Locale = ::java::util::Locale;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $LocaleProviderAdapter = ::sun::util::locale::provider::LocaleProviderAdapter;
using $LocaleServiceProviderPool = ::sun::util::locale::provider::LocaleServiceProviderPool;

namespace java {
	namespace text {

$FieldInfo _Collator_FieldInfo_[] = {
	{"PRIMARY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Collator, PRIMARY)},
	{"SECONDARY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Collator, SECONDARY)},
	{"TERTIARY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Collator, TERTIARY)},
	{"IDENTICAL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Collator, IDENTICAL)},
	{"NO_DECOMPOSITION", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Collator, NO_DECOMPOSITION)},
	{"CANONICAL_DECOMPOSITION", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Collator, CANONICAL_DECOMPOSITION)},
	{"FULL_DECOMPOSITION", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Collator, FULL_DECOMPOSITION)},
	{"strength", "I", nullptr, $PRIVATE, $field(Collator, strength)},
	{"decmp", "I", nullptr, $PRIVATE, $field(Collator, decmp)},
	{"cache", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/util/Locale;Ljava/lang/ref/SoftReference<Ljava/text/Collator;>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Collator, cache)},
	{"LESS", "I", nullptr, $STATIC | $FINAL, $constField(Collator, LESS)},
	{"EQUAL", "I", nullptr, $STATIC | $FINAL, $constField(Collator, EQUAL)},
	{"GREATER", "I", nullptr, $STATIC | $FINAL, $constField(Collator, GREATER)},
	{}
};

$MethodInfo _Collator_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"hashCode", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"<init>", "()V", nullptr, $PROTECTED, $method(Collator, init$, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Collator, clone, $Object*)},
	{"compare", "(Ljava/lang/String;Ljava/lang/String;)I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Collator, compare, int32_t, $String*, $String*)},
	{"compare", "(Ljava/lang/Object;Ljava/lang/Object;)I", nullptr, $PUBLIC, $virtualMethod(Collator, compare, int32_t, Object$*, Object$*)},
	{"equals", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(Collator, equals, bool, $String*, $String*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Collator, equals, bool, Object$*)},
	{"getAvailableLocales", "()[Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $staticMethod(Collator, getAvailableLocales, $LocaleArray*)},
	{"getCollationKey", "(Ljava/lang/String;)Ljava/text/CollationKey;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Collator, getCollationKey, $CollationKey*, $String*)},
	{"getDecomposition", "()I", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Collator, getDecomposition, int32_t)},
	{"getInstance", "()Ljava/text/Collator;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $staticMethod(Collator, getInstance, Collator*)},
	{"getInstance", "(Ljava/util/Locale;)Ljava/text/Collator;", nullptr, $PUBLIC | $STATIC, $staticMethod(Collator, getInstance, Collator*, $Locale*)},
	{"getStrength", "()I", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Collator, getStrength, int32_t)},
	{"setDecomposition", "(I)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Collator, setDecomposition, void, int32_t)},
	{"setStrength", "(I)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Collator, setStrength, void, int32_t)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _Collator_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.text.Collator",
	"java.lang.Object",
	"java.util.Comparator,java.lang.Cloneable",
	_Collator_FieldInfo_,
	_Collator_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/Comparator<Ljava/lang/Object;>;Ljava/lang/Cloneable;"
};

$Object* allocate$Collator($Class* clazz) {
	return $of($alloc(Collator));
}

int32_t Collator::hashCode() {
	 return this->$Comparator::hashCode();
}

$String* Collator::toString() {
	 return this->$Comparator::toString();
}

void Collator::finalize() {
	this->$Comparator::finalize();
}

$ConcurrentMap* Collator::cache = nullptr;

Collator* Collator::getInstance() {
	$load(Collator);
	$synchronized(class$) {
		$init(Collator);
		return getInstance($($Locale::getDefault()));
	}
}

Collator* Collator::getInstance($Locale* desiredLocale) {
	$init(Collator);
	$useLocalCurrentObjectStackCache();
	$var($SoftReference, ref, $cast($SoftReference, $nc(Collator::cache)->get(desiredLocale)));
	$var(Collator, result, (ref != nullptr) ? $cast(Collator, $nc(ref)->get()) : (Collator*)nullptr);
	if (result == nullptr) {
		$var($LocaleProviderAdapter, adapter, nullptr);
		$load($CollatorProvider);
		$assign(adapter, $LocaleProviderAdapter::getAdapter($CollatorProvider::class$, desiredLocale));
		$var($CollatorProvider, provider, $nc(adapter)->getCollatorProvider());
		$assign(result, $nc(provider)->getInstance(desiredLocale));
		if (result == nullptr) {
			$assign(result, $nc($($nc($($LocaleProviderAdapter::forJRE()))->getCollatorProvider()))->getInstance(desiredLocale));
		}
		while (true) {
			if (ref != nullptr) {
				$nc(Collator::cache)->remove(desiredLocale, ref);
			}
			$assign(ref, $cast($SoftReference, $nc(Collator::cache)->putIfAbsent(desiredLocale, $$new($SoftReference, result))));
			if (ref == nullptr) {
				break;
			}
			$var(Collator, cachedColl, $cast(Collator, $nc(ref)->get()));
			if (cachedColl != nullptr) {
				$assign(result, cachedColl);
				break;
			}
		}
	}
	return $cast(Collator, $nc(result)->clone());
}

int32_t Collator::compare(Object$* o1, Object$* o2) {
	return compare($cast($String, o1), $cast($String, o2));
}

bool Collator::equals($String* source, $String* target) {
	return (compare(source, target) == Collator::EQUAL);
}

int32_t Collator::getStrength() {
	$synchronized(this) {
		return this->strength;
	}
}

void Collator::setStrength(int32_t newStrength) {
	$synchronized(this) {
		if ((newStrength != Collator::PRIMARY) && (newStrength != Collator::SECONDARY) && (newStrength != Collator::TERTIARY) && (newStrength != Collator::IDENTICAL)) {
			$throwNew($IllegalArgumentException, "Incorrect comparison level."_s);
		}
		this->strength = newStrength;
	}
}

int32_t Collator::getDecomposition() {
	$synchronized(this) {
		return this->decmp;
	}
}

void Collator::setDecomposition(int32_t decompositionMode) {
	$synchronized(this) {
		if ((decompositionMode != Collator::NO_DECOMPOSITION) && (decompositionMode != Collator::CANONICAL_DECOMPOSITION) && (decompositionMode != Collator::FULL_DECOMPOSITION)) {
			$throwNew($IllegalArgumentException, "Wrong decomposition mode."_s);
		}
		this->decmp = decompositionMode;
	}
}

$LocaleArray* Collator::getAvailableLocales() {
	$load(Collator);
	$synchronized(class$) {
		$init(Collator);
		$load($CollatorProvider);
		$var($LocaleServiceProviderPool, pool, $LocaleServiceProviderPool::getPool($CollatorProvider::class$));
		return $nc(pool)->getAvailableLocales();
	}
}

$Object* Collator::clone() {
	try {
		return $of($cast(Collator, $Comparator::clone()));
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

bool Collator::equals(Object$* that) {
	if ($equals(this, that)) {
		return true;
	}
	if (that == nullptr) {
		return false;
	}
	if ($of(this)->getClass() != $nc($of(that))->getClass()) {
		return false;
	}
	$var(Collator, other, $cast(Collator, that));
	return ((this->strength == $nc(other)->strength) && (this->decmp == other->decmp));
}

void Collator::init$() {
	this->strength = 0;
	this->decmp = 0;
	this->strength = Collator::TERTIARY;
	this->decmp = Collator::CANONICAL_DECOMPOSITION;
}

void clinit$Collator($Class* class$) {
	$assignStatic(Collator::cache, $new($ConcurrentHashMap));
}

Collator::Collator() {
}

$Class* Collator::load$($String* name, bool initialize) {
	$loadClass(Collator, name, initialize, &_Collator_ClassInfo_, clinit$Collator, allocate$Collator);
	return class$;
}

$Class* Collator::class$ = nullptr;

	} // text
} // java