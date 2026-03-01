#include <sun/security/util/AlgorithmDecomposer.h>

#include <java/lang/CharSequence.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/HashSet.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <java/util/regex/Pattern.h>
#include <jcpp.h>

#undef CASE_INSENSITIVE
#undef PATTERN

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;
using $Pattern = ::java::util::regex::Pattern;

namespace sun {
	namespace security {
		namespace util {

$FieldInfo _AlgorithmDecomposer_FieldInfo_[] = {
	{"PATTERN", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AlgorithmDecomposer, PATTERN)},
	{}
};

$MethodInfo _AlgorithmDecomposer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(AlgorithmDecomposer, init$, void)},
	{"decompose", "(Ljava/lang/String;)Ljava/util/Set;", "(Ljava/lang/String;)Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(AlgorithmDecomposer, decompose, $Set*, $String*)},
	{"decomposeImpl", "(Ljava/lang/String;)Ljava/util/Set;", "(Ljava/lang/String;)Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(AlgorithmDecomposer, decomposeImpl, $Set*, $String*)},
	{"decomposeOneHash", "(Ljava/lang/String;)Ljava/util/Set;", "(Ljava/lang/String;)Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(AlgorithmDecomposer, decomposeOneHash, $Set*, $String*)},
	{"getAliases", "(Ljava/lang/String;)Ljava/util/Collection;", "(Ljava/lang/String;)Ljava/util/Collection<Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(AlgorithmDecomposer, getAliases, $Collection*, $String*)},
	{"hasLoop", "(Ljava/util/Set;Ljava/lang/String;Ljava/lang/String;)V", "(Ljava/util/Set<Ljava/lang/String;>;Ljava/lang/String;Ljava/lang/String;)V", $PRIVATE | $STATIC, $staticMethod(AlgorithmDecomposer, hasLoop, void, $Set*, $String*, $String*)},
	{"hashName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(AlgorithmDecomposer, hashName, $String*, $String*)},
	{}
};

$ClassInfo _AlgorithmDecomposer_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.util.AlgorithmDecomposer",
	"java.lang.Object",
	nullptr,
	_AlgorithmDecomposer_FieldInfo_,
	_AlgorithmDecomposer_MethodInfo_
};

$Object* allocate$AlgorithmDecomposer($Class* clazz) {
	return $of($alloc(AlgorithmDecomposer));
}

$Pattern* AlgorithmDecomposer::PATTERN = nullptr;

void AlgorithmDecomposer::init$() {
}

$Set* AlgorithmDecomposer::decomposeImpl($String* algorithm) {
	$init(AlgorithmDecomposer);
	$useLocalCurrentObjectStackCache();
	$var($Set, elements, $new($HashSet));
	$var($StringArray, transTokens, $nc(algorithm)->split("/"_s));
	{
		$var($StringArray, arr$, transTokens);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, transToken, arr$->get(i$));
			{
				if (transToken == nullptr || $nc(transToken)->isEmpty()) {
					continue;
				}
				$var($StringArray, tokens, $nc(AlgorithmDecomposer::PATTERN)->split(transToken));
				{
					$var($StringArray, arr$, tokens);
					int32_t len$ = arr$->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($String, token, arr$->get(i$));
						{
							if (token == nullptr || $nc(token)->isEmpty()) {
								continue;
							}
							elements->add(token);
						}
					}
				}
			}
		}
	}
	return elements;
}

$Set* AlgorithmDecomposer::decompose($String* algorithm) {
	if (algorithm == nullptr || $nc(algorithm)->isEmpty()) {
		return $new($HashSet);
	}
	$var($Set, elements, decomposeImpl(algorithm));
	bool var$0 = $nc(elements)->contains("SHA1"_s);
	if (var$0 && !elements->contains("SHA-1"_s)) {
		elements->add("SHA-1"_s);
	}
	bool var$1 = $nc(elements)->contains("SHA-1"_s);
	if (var$1 && !elements->contains("SHA1"_s)) {
		elements->add("SHA1"_s);
	}
	bool var$2 = $nc(elements)->contains("SHA224"_s);
	if (var$2 && !elements->contains("SHA-224"_s)) {
		elements->add("SHA-224"_s);
	}
	bool var$3 = $nc(elements)->contains("SHA-224"_s);
	if (var$3 && !elements->contains("SHA224"_s)) {
		elements->add("SHA224"_s);
	}
	bool var$4 = $nc(elements)->contains("SHA256"_s);
	if (var$4 && !elements->contains("SHA-256"_s)) {
		elements->add("SHA-256"_s);
	}
	bool var$5 = $nc(elements)->contains("SHA-256"_s);
	if (var$5 && !elements->contains("SHA256"_s)) {
		elements->add("SHA256"_s);
	}
	bool var$6 = $nc(elements)->contains("SHA384"_s);
	if (var$6 && !elements->contains("SHA-384"_s)) {
		elements->add("SHA-384"_s);
	}
	bool var$7 = $nc(elements)->contains("SHA-384"_s);
	if (var$7 && !elements->contains("SHA384"_s)) {
		elements->add("SHA384"_s);
	}
	bool var$8 = $nc(elements)->contains("SHA512"_s);
	if (var$8 && !elements->contains("SHA-512"_s)) {
		elements->add("SHA-512"_s);
	}
	bool var$9 = $nc(elements)->contains("SHA-512"_s);
	if (var$9 && !elements->contains("SHA512"_s)) {
		elements->add("SHA512"_s);
	}
	return elements;
}

$Collection* AlgorithmDecomposer::getAliases($String* algorithm) {
	$init(AlgorithmDecomposer);
	$var($StringArray, aliases, nullptr);
	bool var$0 = $nc(algorithm)->equalsIgnoreCase("DH"_s);
	if (var$0 || $nc(algorithm)->equalsIgnoreCase("DiffieHellman"_s)) {
		$assign(aliases, $new($StringArray, {
			"DH"_s,
			"DiffieHellman"_s
		}));
	} else {
		$assign(aliases, $new($StringArray, {algorithm}));
	}
	return $Arrays::asList(aliases);
}

void AlgorithmDecomposer::hasLoop($Set* elements, $String* find, $String* replace) {
	$init(AlgorithmDecomposer);
	if ($nc(elements)->contains(find)) {
		if (!elements->contains(replace)) {
			elements->add(replace);
		}
		elements->remove(find);
	}
}

$Set* AlgorithmDecomposer::decomposeOneHash($String* algorithm) {
	$init(AlgorithmDecomposer);
	if (algorithm == nullptr || $nc(algorithm)->isEmpty()) {
		return $new($HashSet);
	}
	$var($Set, elements, decomposeImpl(algorithm));
	hasLoop(elements, "SHA-1"_s, "SHA1"_s);
	hasLoop(elements, "SHA-224"_s, "SHA224"_s);
	hasLoop(elements, "SHA-256"_s, "SHA256"_s);
	hasLoop(elements, "SHA-384"_s, "SHA384"_s);
	hasLoop(elements, "SHA-512"_s, "SHA512"_s);
	return elements;
}

$String* AlgorithmDecomposer::hashName($String* algorithm) {
	$init(AlgorithmDecomposer);
	return $nc(algorithm)->replace(static_cast<$CharSequence*>("-"_s), static_cast<$CharSequence*>(""_s));
}

void clinit$AlgorithmDecomposer($Class* class$) {
	$assignStatic(AlgorithmDecomposer::PATTERN, $Pattern::compile("with|and|(?<!padd)in"_s, $Pattern::CASE_INSENSITIVE));
}

AlgorithmDecomposer::AlgorithmDecomposer() {
}

$Class* AlgorithmDecomposer::load$($String* name, bool initialize) {
	$loadClass(AlgorithmDecomposer, name, initialize, &_AlgorithmDecomposer_ClassInfo_, clinit$AlgorithmDecomposer, allocate$AlgorithmDecomposer);
	return class$;
}

$Class* AlgorithmDecomposer::class$ = nullptr;

		} // util
	} // security
} // sun