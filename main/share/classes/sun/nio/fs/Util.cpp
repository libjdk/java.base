#include <sun/nio/fs/Util.h>

#include <java/lang/AssertionError.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/file/LinkOption.h>
#include <java/util/Collection.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef NOFOLLOW_LINKS

using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Charset = ::java::nio::charset::Charset;
using $LinkOption = ::java::nio::file::LinkOption;
using $Collection = ::java::util::Collection;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace sun {
	namespace nio {
		namespace fs {

$CompoundAttribute _Util_MethodAnnotations_newSet3[] = {
	{"Ljava/lang/SafeVarargs;", nullptr},
	{}
};

$CompoundAttribute _Util_MethodAnnotations_newSet4[] = {
	{"Ljava/lang/SafeVarargs;", nullptr},
	{}
};

$FieldInfo _Util_FieldInfo_[] = {
	{"jnuEncoding", "Ljava/nio/charset/Charset;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Util, jnuEncoding$)},
	{}
};

$MethodInfo _Util_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(Util, init$, void)},
	{"followLinks", "([Ljava/nio/file/LinkOption;)Z", nullptr, $STATIC | $TRANSIENT, $staticMethod(Util, followLinks, bool, $LinkOptionArray*)},
	{"jnuEncoding", "()Ljava/nio/charset/Charset;", nullptr, $STATIC, $staticMethod(Util, jnuEncoding, $Charset*)},
	{"newSet", "([Ljava/lang/Object;)Ljava/util/Set;", "<E:Ljava/lang/Object;>([TE;)Ljava/util/Set<TE;>;", $STATIC | $TRANSIENT, $staticMethod(Util, newSet, $Set*, $ObjectArray*), nullptr, nullptr, _Util_MethodAnnotations_newSet3},
	{"newSet", "(Ljava/util/Set;[Ljava/lang/Object;)Ljava/util/Set;", "<E:Ljava/lang/Object;>(Ljava/util/Set<TE;>;[TE;)Ljava/util/Set<TE;>;", $STATIC | $TRANSIENT, $staticMethod(Util, newSet, $Set*, $Set*, $ObjectArray*), nullptr, nullptr, _Util_MethodAnnotations_newSet4},
	{"split", "(Ljava/lang/String;C)[Ljava/lang/String;", nullptr, $STATIC, $staticMethod(Util, split, $StringArray*, $String*, char16_t)},
	{"toBytes", "(Ljava/lang/String;)[B", nullptr, $STATIC, $staticMethod(Util, toBytes, $bytes*, $String*)},
	{"toString", "([B)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(Util, toString, $String*, $bytes*)},
	{}
};

$ClassInfo _Util_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.Util",
	"java.lang.Object",
	nullptr,
	_Util_FieldInfo_,
	_Util_MethodInfo_
};

$Object* allocate$Util($Class* clazz) {
	return $of($alloc(Util));
}

$Charset* Util::jnuEncoding$ = nullptr;

void Util::init$() {
}

$Charset* Util::jnuEncoding() {
	$init(Util);
	return Util::jnuEncoding$;
}

$bytes* Util::toBytes($String* s) {
	$init(Util);
	return $nc(s)->getBytes(Util::jnuEncoding$);
}

$String* Util::toString($bytes* bytes) {
	$init(Util);
	return $new($String, bytes, Util::jnuEncoding$);
}

$StringArray* Util::split($String* s, char16_t c) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	int32_t count = 0;
	for (int32_t i = 0; i < $nc(s)->length(); ++i) {
		if (s->charAt(i) == c) {
			++count;
		}
	}
	$var($StringArray, result, $new($StringArray, count + 1));
	int32_t n = 0;
	int32_t last = 0;
	for (int32_t i = 0; i < $nc(s)->length(); ++i) {
		if (s->charAt(i) == c) {
			result->set(n++, $(s->substring(last, i)));
			last = i + 1;
		}
	}
	result->set(n, $($nc(s)->substring(last, s->length())));
	return result;
}

$Set* Util::newSet($ObjectArray* elements) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	$var($HashSet, set, $new($HashSet));
	{
		$var($ObjectArray, arr$, elements);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Object0, e, arr$->get(i$));
			{
				set->add(e);
			}
		}
	}
	return set;
}

$Set* Util::newSet($Set* other, $ObjectArray* elements) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	$var($HashSet, set, $new($HashSet, static_cast<$Collection*>(other)));
	{
		$var($ObjectArray, arr$, elements);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Object0, e, arr$->get(i$));
			{
				set->add(e);
			}
		}
	}
	return set;
}

bool Util::followLinks($LinkOptionArray* options) {
	$init(Util);
	bool followLinks = true;
	{
		$var($LinkOptionArray, arr$, options);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$LinkOption* option = arr$->get(i$);
			{
				$init($LinkOption);
				if (option == $LinkOption::NOFOLLOW_LINKS) {
					followLinks = false;
				} else if (option == nullptr) {
					$throwNew($NullPointerException);
				} else {
					$throwNew($AssertionError, $of("Should not get here"_s));
				}
			}
		}
	}
	return followLinks;
}

void clinit$Util($Class* class$) {
	$assignStatic(Util::jnuEncoding$, $Charset::forName($($GetPropertyAction::privilegedGetProperty("sun.jnu.encoding"_s))));
}

Util::Util() {
}

$Class* Util::load$($String* name, bool initialize) {
	$loadClass(Util, name, initialize, &_Util_ClassInfo_, clinit$Util, allocate$Util);
	return class$;
}

$Class* Util::class$ = nullptr;

		} // fs
	} // nio
} // sun