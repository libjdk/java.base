#include <sun/security/util/DomainName$Rules$RuleSet.h>

#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <sun/security/util/DomainName$1.h>
#include <sun/security/util/DomainName$CommonMatch.h>
#include <sun/security/util/DomainName$Match.h>
#include <sun/security/util/DomainName$OtherMatch.h>
#include <sun/security/util/DomainName$OtherRule.h>
#include <sun/security/util/DomainName$Rule$Type.h>
#include <sun/security/util/DomainName$Rule.h>
#include <sun/security/util/DomainName$Rules.h>
#include <sun/security/util/RegisteredDomain$Type.h>
#include <jcpp.h>

#undef AUTHS
#undef EXCEPTION
#undef NORMAL
#undef WILDCARD

using $RegisteredDomain$TypeArray = $Array<::sun::security::util::RegisteredDomain$Type>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $DomainName$1 = ::sun::security::util::DomainName$1;
using $DomainName$CommonMatch = ::sun::security::util::DomainName$CommonMatch;
using $DomainName$Match = ::sun::security::util::DomainName$Match;
using $DomainName$OtherMatch = ::sun::security::util::DomainName$OtherMatch;
using $DomainName$OtherRule = ::sun::security::util::DomainName$OtherRule;
using $DomainName$Rule = ::sun::security::util::DomainName$Rule;
using $DomainName$Rule$Type = ::sun::security::util::DomainName$Rule$Type;
using $RegisteredDomain$Type = ::sun::security::util::RegisteredDomain$Type;

namespace sun {
	namespace security {
		namespace util {

$FieldInfo _DomainName$Rules$RuleSet_FieldInfo_[] = {
	{"numLabels", "I", nullptr, $PRIVATE | $FINAL, $field(DomainName$Rules$RuleSet, numLabels$)},
	{"rules", "Ljava/util/Set;", "Ljava/util/Set<Lsun/security/util/DomainName$Rule;>;", $PRIVATE | $FINAL, $field(DomainName$Rules$RuleSet, rules)},
	{"hasExceptions", "Z", nullptr, 0, $field(DomainName$Rules$RuleSet, hasExceptions)},
	{"AUTHS", "[Lsun/security/util/RegisteredDomain$Type;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DomainName$Rules$RuleSet, AUTHS)},
	{}
};

$MethodInfo _DomainName$Rules$RuleSet_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, 0, $method(DomainName$Rules$RuleSet, init$, void, int32_t)},
	{"addRule", "(ILjava/lang/String;)V", nullptr, 0, $virtualMethod(DomainName$Rules$RuleSet, addRule, void, int32_t, $String*)},
	{"labels", "(Ljava/lang/String;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(DomainName$Rules$RuleSet, labels, int32_t, $String*, int32_t)},
	{"match", "(Ljava/lang/String;)Lsun/security/util/DomainName$Match;", nullptr, 0, $virtualMethod(DomainName$Rules$RuleSet, match, $DomainName$Match*, $String*)},
	{"matchException", "(Ljava/lang/String;Lsun/security/util/DomainName$Rule;)Lsun/security/util/DomainName$Match;", nullptr, $PRIVATE, $method(DomainName$Rules$RuleSet, matchException, $DomainName$Match*, $String*, $DomainName$Rule*)},
	{"matchNormal", "(Ljava/lang/String;Lsun/security/util/DomainName$Rule;)Lsun/security/util/DomainName$Match;", nullptr, $PRIVATE, $method(DomainName$Rules$RuleSet, matchNormal, $DomainName$Match*, $String*, $DomainName$Rule*)},
	{"matchOther", "(Ljava/lang/String;Lsun/security/util/DomainName$Rule;)Lsun/security/util/DomainName$Match;", nullptr, $PRIVATE, $method(DomainName$Rules$RuleSet, matchOther, $DomainName$Match*, $String*, $DomainName$Rule*)},
	{"matchWildcard", "(Ljava/lang/String;Lsun/security/util/DomainName$Rule;)Lsun/security/util/DomainName$Match;", nullptr, $PRIVATE, $method(DomainName$Rules$RuleSet, matchWildcard, $DomainName$Match*, $String*, $DomainName$Rule*)},
	{"numLabels", "(Ljava/lang/String;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(DomainName$Rules$RuleSet, numLabels, int32_t, $String*)},
	{"split", "(Ljava/lang/String;)Ljava/util/LinkedList;", "(Ljava/lang/String;)Ljava/util/LinkedList<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(DomainName$Rules$RuleSet, split, $LinkedList*, $String*)},
	{}
};

$InnerClassInfo _DomainName$Rules$RuleSet_InnerClassesInfo_[] = {
	{"sun.security.util.DomainName$Rules", "sun.security.util.DomainName", "Rules", $PRIVATE | $STATIC},
	{"sun.security.util.DomainName$Rules$RuleSet", "sun.security.util.DomainName$Rules", "RuleSet", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _DomainName$Rules$RuleSet_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.util.DomainName$Rules$RuleSet",
	"java.lang.Object",
	nullptr,
	_DomainName$Rules$RuleSet_FieldInfo_,
	_DomainName$Rules$RuleSet_MethodInfo_,
	nullptr,
	nullptr,
	_DomainName$Rules$RuleSet_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.util.DomainName"
};

$Object* allocate$DomainName$Rules$RuleSet($Class* clazz) {
	return $of($alloc(DomainName$Rules$RuleSet));
}

$RegisteredDomain$TypeArray* DomainName$Rules$RuleSet::AUTHS = nullptr;

void DomainName$Rules$RuleSet::init$(int32_t n) {
	$set(this, rules, $new($HashSet));
	this->hasExceptions = false;
	this->numLabels$ = n;
}

void DomainName$Rules$RuleSet::addRule(int32_t auth, $String* rule) {
	$useLocalCurrentObjectStackCache();
	if ($nc(rule)->startsWith("!"_s)) {
		$init($DomainName$Rule$Type);
		$nc(this->rules)->add($$new($DomainName$Rule, $(rule->substring(1)), $DomainName$Rule$Type::EXCEPTION, $nc(DomainName$Rules$RuleSet::AUTHS)->get(auth)));
		this->hasExceptions = true;
	} else {
		bool var$1 = rule->startsWith("*."_s);
		if (var$1 && rule->lastIndexOf((int32_t)u'*') == 0) {
			$init($DomainName$Rule$Type);
			$nc(this->rules)->add($$new($DomainName$Rule, $(rule->substring(2)), $DomainName$Rule$Type::WILDCARD, $nc(DomainName$Rules$RuleSet::AUTHS)->get(auth)));
		} else if (rule->indexOf((int32_t)u'*') == -1) {
			$init($DomainName$Rule$Type);
			$nc(this->rules)->add($$new($DomainName$Rule, rule, $DomainName$Rule$Type::NORMAL, $nc(DomainName$Rules$RuleSet::AUTHS)->get(auth)));
		} else {
			$nc(this->rules)->add($$new($DomainName$OtherRule, rule, $nc(DomainName$Rules$RuleSet::AUTHS)->get(auth), $(split(rule))));
		}
	}
}

$DomainName$Match* DomainName$Rules$RuleSet::match($String* domain) {
	$useLocalCurrentObjectStackCache();
	$var($DomainName$Match, match, nullptr);
	{
		$var($Iterator, i$, $nc(this->rules)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($DomainName$Rule, rule, $cast($DomainName$Rule, i$->next()));
			{
				$init($DomainName$1);
				{
					$var($DomainName$Match, excMatch, nullptr)
					switch ($nc($DomainName$1::$SwitchMap$sun$security$util$DomainName$Rule$Type)->get($nc(($nc(rule)->type))->ordinal())) {
					case 1:
						{
							if (match == nullptr) {
								$assign(match, matchNormal(domain, rule));
							}
							break;
						}
					case 2:
						{
							if (match == nullptr) {
								$assign(match, matchWildcard(domain, rule));
							}
							break;
						}
					case 3:
						{
							if (match == nullptr) {
								$assign(match, matchOther(domain, rule));
							}
							break;
						}
					case 4:
						{
							$assign(excMatch, matchException(domain, rule));
							if (excMatch != nullptr) {
								return excMatch;
							}
							break;
						}
					}
				}
			}
		}
	}
	return match;
}

$LinkedList* DomainName$Rules$RuleSet::split($String* rule) {
	$init(DomainName$Rules$RuleSet);
	$useLocalCurrentObjectStackCache();
	$var($StringArray, labels, $nc(rule)->split("\\."_s));
	return $new($LinkedList, $($Arrays::asList(labels)));
}

int32_t DomainName$Rules$RuleSet::numLabels($String* rule) {
	$init(DomainName$Rules$RuleSet);
	if ($nc(rule)->isEmpty()) {
		return 0;
	}
	int32_t len = $nc(rule)->length();
	int32_t count = 0;
	int32_t index = 0;
	while (index < len) {
		int32_t pos = 0;
		if ((pos = rule->indexOf((int32_t)u'.', index)) == -1) {
			return count + 1;
		}
		index = pos + 1;
		++count;
	}
	return count;
}

$DomainName$Match* DomainName$Rules$RuleSet::matchNormal($String* domain, $DomainName$Rule* rule) {
	int32_t index = labels(domain, this->numLabels$);
	if (index == -1) {
		return nullptr;
	}
	$var($String, substring, $nc(domain)->substring(index));
	if ($nc($nc(rule)->domain)->equals(substring)) {
		return $new($DomainName$CommonMatch, domain, rule, index);
	}
	return nullptr;
}

$DomainName$Match* DomainName$Rules$RuleSet::matchWildcard($String* domain, $DomainName$Rule* rule) {
	int32_t index = labels(domain, this->numLabels$ - 1);
	if (index > 0) {
		$var($String, substring, $nc(domain)->substring(index));
		if ($nc($nc(rule)->domain)->equals(substring)) {
			return $new($DomainName$CommonMatch, domain, rule, labels(domain, this->numLabels$));
		}
	}
	return nullptr;
}

$DomainName$Match* DomainName$Rules$RuleSet::matchException($String* domain, $DomainName$Rule* rule) {
	int32_t index = labels(domain, this->numLabels$);
	if (index == -1) {
		return nullptr;
	}
	$var($String, substring, $nc(domain)->substring(index));
	if ($nc($nc(rule)->domain)->equals(substring)) {
		return $new($DomainName$CommonMatch, domain, rule, labels(domain, this->numLabels$ - 1));
	}
	return nullptr;
}

$DomainName$Match* DomainName$Rules$RuleSet::matchOther($String* domain, $DomainName$Rule* rule) {
	$useLocalCurrentObjectStackCache();
	$var($DomainName$OtherRule, otherRule, $cast($DomainName$OtherRule, rule));
	$var($LinkedList, target, split(domain));
	int32_t diff = $nc(target)->size() - this->numLabels$;
	if (diff < 0) {
		return nullptr;
	}
	bool found = true;
	for (int32_t i = 0; i < this->numLabels$; ++i) {
		$var($String, ruleLabel, $cast($String, $nc($nc(otherRule)->labels)->get(i)));
		$var($String, targetLabel, $cast($String, target->get(i + diff)));
		bool var$0 = $nc(ruleLabel)->charAt(0) != u'*';
		if (var$0 && !ruleLabel->equalsIgnoreCase(targetLabel)) {
			found = false;
			break;
		}
	}
	if (found) {
		return $new($DomainName$OtherMatch, rule, this->numLabels$, target);
	}
	return nullptr;
}

int32_t DomainName$Rules$RuleSet::labels($String* s, int32_t n) {
	$init(DomainName$Rules$RuleSet);
	if (n < 1) {
		return -1;
	}
	int32_t index = $nc(s)->length();
	for (int32_t i = 0; i < n; ++i) {
		int32_t next = s->lastIndexOf((int32_t)u'.', index);
		if (next == -1) {
			if (i == n - 1) {
				return 0;
			} else {
				return -1;
			}
		}
		index = next - 1;
	}
	return index + 2;
}

void clinit$DomainName$Rules$RuleSet($Class* class$) {
	$assignStatic(DomainName$Rules$RuleSet::AUTHS, $RegisteredDomain$Type::values());
}

DomainName$Rules$RuleSet::DomainName$Rules$RuleSet() {
}

$Class* DomainName$Rules$RuleSet::load$($String* name, bool initialize) {
	$loadClass(DomainName$Rules$RuleSet, name, initialize, &_DomainName$Rules$RuleSet_ClassInfo_, clinit$DomainName$Rules$RuleSet, allocate$DomainName$Rules$RuleSet);
	return class$;
}

$Class* DomainName$Rules$RuleSet::class$ = nullptr;

		} // util
	} // security
} // sun