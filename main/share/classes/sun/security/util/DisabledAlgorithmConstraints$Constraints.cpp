#include <sun/security/util/DisabledAlgorithmConstraints$Constraints.h>

#include <java/lang/CharSequence.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/Key.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/StringTokenizer.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern.h>
#include <sun/security/util/AlgorithmDecomposer.h>
#include <sun/security/util/ConstraintsParameters.h>
#include <sun/security/util/CurveDB.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/DisabledAlgorithmConstraints$Constraint$Operator.h>
#include <sun/security/util/DisabledAlgorithmConstraints$Constraint.h>
#include <sun/security/util/DisabledAlgorithmConstraints$Constraints$Holder.h>
#include <sun/security/util/DisabledAlgorithmConstraints$DenyAfterConstraint.h>
#include <sun/security/util/DisabledAlgorithmConstraints$DisabledConstraint.h>
#include <sun/security/util/DisabledAlgorithmConstraints$KeySizeConstraint.h>
#include <sun/security/util/DisabledAlgorithmConstraints$UsageConstraint.h>
#include <sun/security/util/DisabledAlgorithmConstraints$jdkCAConstraint.h>
#include <sun/security/util/DisabledAlgorithmConstraints.h>
#include <sun/security/util/KeyUtil.h>
#include <sun/security/util/NamedCurve.h>
#include <jcpp.h>

#undef DENY_AFTER_PATTERN
#undef ENGLISH

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $Key = ::java::security::Key;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $StringTokenizer = ::java::util::StringTokenizer;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern = ::java::util::regex::Pattern;
using $AlgorithmDecomposer = ::sun::security::util::AlgorithmDecomposer;
using $ConstraintsParameters = ::sun::security::util::ConstraintsParameters;
using $CurveDB = ::sun::security::util::CurveDB;
using $Debug = ::sun::security::util::Debug;
using $DisabledAlgorithmConstraints = ::sun::security::util::DisabledAlgorithmConstraints;
using $DisabledAlgorithmConstraints$Constraint = ::sun::security::util::DisabledAlgorithmConstraints$Constraint;
using $DisabledAlgorithmConstraints$Constraint$Operator = ::sun::security::util::DisabledAlgorithmConstraints$Constraint$Operator;
using $DisabledAlgorithmConstraints$Constraints$Holder = ::sun::security::util::DisabledAlgorithmConstraints$Constraints$Holder;
using $DisabledAlgorithmConstraints$DenyAfterConstraint = ::sun::security::util::DisabledAlgorithmConstraints$DenyAfterConstraint;
using $DisabledAlgorithmConstraints$DisabledConstraint = ::sun::security::util::DisabledAlgorithmConstraints$DisabledConstraint;
using $DisabledAlgorithmConstraints$KeySizeConstraint = ::sun::security::util::DisabledAlgorithmConstraints$KeySizeConstraint;
using $DisabledAlgorithmConstraints$UsageConstraint = ::sun::security::util::DisabledAlgorithmConstraints$UsageConstraint;
using $DisabledAlgorithmConstraints$jdkCAConstraint = ::sun::security::util::DisabledAlgorithmConstraints$jdkCAConstraint;
using $KeyUtil = ::sun::security::util::KeyUtil;

namespace sun {
	namespace security {
		namespace util {

$FieldInfo _DisabledAlgorithmConstraints$Constraints_FieldInfo_[] = {
	{"constraintsMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Lsun/security/util/DisabledAlgorithmConstraints$Constraint;>;>;", $PRIVATE, $field(DisabledAlgorithmConstraints$Constraints, constraintsMap)},
	{}
};

$MethodInfo _DisabledAlgorithmConstraints$Constraints_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/util/List;)V", "(Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;)V", $PUBLIC, $method(DisabledAlgorithmConstraints$Constraints, init$, void, $String*, $List*)},
	{"getConstraints", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Lsun/security/util/DisabledAlgorithmConstraints$Constraint;>;", $PRIVATE, $method(DisabledAlgorithmConstraints$Constraints, getConstraints, $List*, $String*)},
	{"permits", "(Ljava/security/Key;)Z", nullptr, $PUBLIC, $virtualMethod(DisabledAlgorithmConstraints$Constraints, permits, bool, $Key*)},
	{"permits", "(Ljava/lang/String;Ljava/security/AlgorithmParameters;)Z", nullptr, $PUBLIC, $virtualMethod(DisabledAlgorithmConstraints$Constraints, permits, bool, $String*, $AlgorithmParameters*)},
	{"permits", "(Ljava/lang/String;Lsun/security/util/ConstraintsParameters;)V", nullptr, $PUBLIC, $virtualMethod(DisabledAlgorithmConstraints$Constraints, permits, void, $String*, $ConstraintsParameters*), "java.security.cert.CertPathValidatorException"},
	{}
};

$InnerClassInfo _DisabledAlgorithmConstraints$Constraints_InnerClassesInfo_[] = {
	{"sun.security.util.DisabledAlgorithmConstraints$Constraints", "sun.security.util.DisabledAlgorithmConstraints", "Constraints", $PRIVATE | $STATIC},
	{"sun.security.util.DisabledAlgorithmConstraints$Constraints$Holder", "sun.security.util.DisabledAlgorithmConstraints$Constraints", "Holder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _DisabledAlgorithmConstraints$Constraints_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.util.DisabledAlgorithmConstraints$Constraints",
	"java.lang.Object",
	nullptr,
	_DisabledAlgorithmConstraints$Constraints_FieldInfo_,
	_DisabledAlgorithmConstraints$Constraints_MethodInfo_,
	nullptr,
	nullptr,
	_DisabledAlgorithmConstraints$Constraints_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.util.DisabledAlgorithmConstraints"
};

$Object* allocate$DisabledAlgorithmConstraints$Constraints($Class* clazz) {
	return $of($alloc(DisabledAlgorithmConstraints$Constraints));
}

void DisabledAlgorithmConstraints$Constraints::init$($String* propertyName, $List* constraintArray) {
	$useLocalCurrentObjectStackCache();
	$set(this, constraintsMap, $new($HashMap));
	{
		$var($Iterator, i$, $nc(constraintArray)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, constraintEntry, $cast($String, i$->next()));
			{
				if (constraintEntry == nullptr || $nc(constraintEntry)->isEmpty()) {
					continue;
				}
				$assign(constraintEntry, $nc(constraintEntry)->trim());
				$init($DisabledAlgorithmConstraints);
				if ($DisabledAlgorithmConstraints::debug != nullptr) {
					$nc($DisabledAlgorithmConstraints::debug)->println($$str({"Constraints: "_s, constraintEntry}));
				}
				int32_t space = constraintEntry->indexOf((int32_t)u' ');
				$var($String, algorithm, $AlgorithmDecomposer::hashName((space > 0 ? $(constraintEntry->substring(0, space)) : constraintEntry)));
				$init($Locale);
				$var($Object, var$0, $of($nc(algorithm)->toUpperCase($Locale::ENGLISH)));
				$var($List, constraintList, $cast($List, $nc(this->constraintsMap)->getOrDefault(var$0, $$new($ArrayList, 1))));
				{
					$var($Iterator, i$, $nc($($AlgorithmDecomposer::getAliases(algorithm)))->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($String, alias, $cast($String, i$->next()));
						{
							$nc(this->constraintsMap)->putIfAbsent($($nc(alias)->toUpperCase($Locale::ENGLISH)), constraintList);
						}
					}
				}
				if (space <= 0 || $CurveDB::lookup(constraintEntry) != nullptr) {
					$nc(constraintList)->add($$new($DisabledAlgorithmConstraints$DisabledConstraint, algorithm));
					continue;
				}
				$var($String, policy, constraintEntry->substring(space + 1));
				$var($DisabledAlgorithmConstraints$Constraint, c, nullptr);
				$var($DisabledAlgorithmConstraints$Constraint, lastConstraint, nullptr);
				bool jdkCALimit = false;
				bool denyAfterLimit = false;
				{
					$var($StringArray, arr$, policy->split("&"_s));
					int32_t len$ = arr$->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($String, entry, arr$->get(i$));
						{
							$assign(entry, $nc(entry)->trim());
							$var($Matcher, matcher, nullptr);
							if (entry->startsWith("keySize"_s)) {
								if ($DisabledAlgorithmConstraints::debug != nullptr) {
									$nc($DisabledAlgorithmConstraints::debug)->println($$str({"Constraints set to keySize: "_s, entry}));
								}
								$var($StringTokenizer, tokens, $new($StringTokenizer, entry));
								if (!"keySize"_s->equals($(tokens->nextToken()))) {
									$throwNew($IllegalArgumentException, $$str({"Error in security property. Constraint unknown: "_s, entry}));
								}
								$var($String, var$1, algorithm);
								$var($DisabledAlgorithmConstraints$Constraint$Operator, var$2, $DisabledAlgorithmConstraints$Constraint$Operator::of($(tokens->nextToken())));
								$assign(c, $new($DisabledAlgorithmConstraints$KeySizeConstraint, var$1, var$2, $Integer::parseInt($(tokens->nextToken()))));
							} else if (entry->equalsIgnoreCase("jdkCA"_s)) {
								if ($DisabledAlgorithmConstraints::debug != nullptr) {
									$nc($DisabledAlgorithmConstraints::debug)->println("Constraints set to jdkCA."_s);
								}
								if (jdkCALimit) {
									$throwNew($IllegalArgumentException, $$str({"Only one jdkCA entry allowed in property. Constraint: "_s, constraintEntry}));
								}
								$assign(c, $new($DisabledAlgorithmConstraints$jdkCAConstraint, algorithm));
								jdkCALimit = true;
							} else {
								bool var$4 = entry->startsWith("denyAfter"_s);
								$init($DisabledAlgorithmConstraints$Constraints$Holder);
								if (var$4 && $nc(($assign(matcher, $nc($DisabledAlgorithmConstraints$Constraints$Holder::DENY_AFTER_PATTERN)->matcher(entry))))->matches()) {
									if ($DisabledAlgorithmConstraints::debug != nullptr) {
										$nc($DisabledAlgorithmConstraints::debug)->println("Constraints set to denyAfter"_s);
									}
									if (denyAfterLimit) {
										$throwNew($IllegalArgumentException, $$str({"Only one denyAfter entry allowed in property. Constraint: "_s, constraintEntry}));
									}
									int32_t year = $Integer::parseInt($($nc(matcher)->group(1)));
									int32_t month = $Integer::parseInt($($nc(matcher)->group(2)));
									int32_t day = $Integer::parseInt($($nc(matcher)->group(3)));
									$assign(c, $new($DisabledAlgorithmConstraints$DenyAfterConstraint, algorithm, year, month, day));
									denyAfterLimit = true;
								} else if (entry->startsWith("usage"_s)) {
									$var($StringArray, s, $(($(entry->substring(5)))->trim())->split(" "_s));
									$assign(c, $new($DisabledAlgorithmConstraints$UsageConstraint, algorithm, s));
									if ($DisabledAlgorithmConstraints::debug != nullptr) {
										$nc($DisabledAlgorithmConstraints::debug)->println($$str({"Constraints usage length is "_s, $$str(s->length)}));
									}
								} else {
									$throwNew($IllegalArgumentException, $$str({"Error in security property. Constraint unknown: "_s, entry}));
								}
							}
							if (lastConstraint == nullptr) {
								$nc(constraintList)->add(c);
							} else {
								$set($nc(lastConstraint), nextConstraint, c);
							}
							$assign(lastConstraint, c);
						}
					}
				}
			}
		}
	}
}

$List* DisabledAlgorithmConstraints$Constraints::getConstraints($String* algorithm) {
	$init($Locale);
	return $cast($List, $nc(this->constraintsMap)->get($($nc(algorithm)->toUpperCase($Locale::ENGLISH))));
}

bool DisabledAlgorithmConstraints$Constraints::permits($Key* key) {
	$useLocalCurrentObjectStackCache();
	$var($List, list, getConstraints($($nc(key)->getAlgorithm())));
	if (list == nullptr) {
		return true;
	}
	{
		$var($Iterator, i$, $nc(list)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($DisabledAlgorithmConstraints$Constraint, constraint, $cast($DisabledAlgorithmConstraints$Constraint, i$->next()));
			{
				if (!$nc(constraint)->permits(key)) {
					$init($DisabledAlgorithmConstraints);
					if ($DisabledAlgorithmConstraints::debug != nullptr) {
						$nc($DisabledAlgorithmConstraints::debug)->println($$str({"Constraints: failed key sizeconstraint check "_s, $$str($KeyUtil::getKeySize(key))}));
					}
					return false;
				}
			}
		}
	}
	return true;
}

bool DisabledAlgorithmConstraints$Constraints::permits($String* algorithm, $AlgorithmParameters* aps) {
	$useLocalCurrentObjectStackCache();
	$var($List, list, getConstraints(algorithm));
	if (list == nullptr) {
		return true;
	}
	{
		$var($Iterator, i$, $nc(list)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($DisabledAlgorithmConstraints$Constraint, constraint, $cast($DisabledAlgorithmConstraints$Constraint, i$->next()));
			{
				if (!$nc(constraint)->permits(aps)) {
					$init($DisabledAlgorithmConstraints);
					if ($DisabledAlgorithmConstraints::debug != nullptr) {
						$nc($DisabledAlgorithmConstraints::debug)->println($$str({"Constraints: failed algorithm parameters constraint check "_s, aps}));
					}
					return false;
				}
			}
		}
	}
	return true;
}

void DisabledAlgorithmConstraints$Constraints::permits($String* algorithm, $ConstraintsParameters* cp) {
	$useLocalCurrentObjectStackCache();
	$init($DisabledAlgorithmConstraints);
	if ($DisabledAlgorithmConstraints::debug != nullptr) {
		$nc($DisabledAlgorithmConstraints::debug)->println($$str({"Constraints.permits(): "_s, algorithm, ", "_s, $($nc($of(cp))->toString())}));
	}
	$var($Set, algorithms, $new($HashSet));
	if (algorithm != nullptr) {
		algorithms->addAll($($AlgorithmDecomposer::decomposeOneHash(algorithm)));
		algorithms->add(algorithm);
	}
	{
		$var($Iterator, i$, $nc($($nc(cp)->getKeys()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Key, key, $cast($Key, i$->next()));
			{
				algorithms->add($($nc(key)->getAlgorithm()));
			}
		}
	}
	{
		$var($Iterator, i$, algorithms->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, alg, $cast($String, i$->next()));
			{
				$var($List, list, getConstraints(alg));
				if (list == nullptr) {
					continue;
				}
				{
					$var($Iterator, i$, $nc(list)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($DisabledAlgorithmConstraints$Constraint, constraint, $cast($DisabledAlgorithmConstraints$Constraint, i$->next()));
						{
							$nc(constraint)->permits(cp);
						}
					}
				}
			}
		}
	}
}

DisabledAlgorithmConstraints$Constraints::DisabledAlgorithmConstraints$Constraints() {
}

$Class* DisabledAlgorithmConstraints$Constraints::load$($String* name, bool initialize) {
	$loadClass(DisabledAlgorithmConstraints$Constraints, name, initialize, &_DisabledAlgorithmConstraints$Constraints_ClassInfo_, allocate$DisabledAlgorithmConstraints$Constraints);
	return class$;
}

$Class* DisabledAlgorithmConstraints$Constraints::class$ = nullptr;

		} // util
	} // security
} // sun