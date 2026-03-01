#include <sun/security/provider/certpath/PolicyNodeImpl.h>

#include <java/lang/IllegalStateException.h>
#include <java/security/cert/PolicyNode.h>
#include <java/util/AbstractCollection.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/Set.h>
#include <sun/security/util/KnownOIDs.h>
#include <jcpp.h>

#undef ANY_POLICY
#undef CE_CERT_POLICIES_ANY

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $MethodInfo = ::java::lang::MethodInfo;
using $PolicyNode = ::java::security::cert::PolicyNode;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $Set = ::java::util::Set;
using $KnownOIDs = ::sun::security::util::KnownOIDs;

namespace sun {
	namespace security {
		namespace provider {
			namespace certpath {

$FieldInfo _PolicyNodeImpl_FieldInfo_[] = {
	{"ANY_POLICY", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PolicyNodeImpl, ANY_POLICY)},
	{"mParent", "Lsun/security/provider/certpath/PolicyNodeImpl;", nullptr, $PRIVATE, $field(PolicyNodeImpl, mParent)},
	{"mChildren", "Ljava/util/HashSet;", "Ljava/util/HashSet<Lsun/security/provider/certpath/PolicyNodeImpl;>;", $PRIVATE, $field(PolicyNodeImpl, mChildren)},
	{"mValidPolicy", "Ljava/lang/String;", nullptr, $PRIVATE, $field(PolicyNodeImpl, mValidPolicy)},
	{"mQualifierSet", "Ljava/util/HashSet;", "Ljava/util/HashSet<Ljava/security/cert/PolicyQualifierInfo;>;", $PRIVATE, $field(PolicyNodeImpl, mQualifierSet)},
	{"mCriticalityIndicator", "Z", nullptr, $PRIVATE, $field(PolicyNodeImpl, mCriticalityIndicator)},
	{"mExpectedPolicySet", "Ljava/util/HashSet;", "Ljava/util/HashSet<Ljava/lang/String;>;", $PRIVATE, $field(PolicyNodeImpl, mExpectedPolicySet)},
	{"mOriginalExpectedPolicySet", "Z", nullptr, $PRIVATE, $field(PolicyNodeImpl, mOriginalExpectedPolicySet)},
	{"mDepth", "I", nullptr, $PRIVATE, $field(PolicyNodeImpl, mDepth)},
	{"isImmutable", "Z", nullptr, $PRIVATE, $field(PolicyNodeImpl, isImmutable$)},
	{}
};

$MethodInfo _PolicyNodeImpl_MethodInfo_[] = {
	{"<init>", "(Lsun/security/provider/certpath/PolicyNodeImpl;Ljava/lang/String;Ljava/util/Set;ZLjava/util/Set;Z)V", "(Lsun/security/provider/certpath/PolicyNodeImpl;Ljava/lang/String;Ljava/util/Set<Ljava/security/cert/PolicyQualifierInfo;>;ZLjava/util/Set<Ljava/lang/String;>;Z)V", 0, $method(PolicyNodeImpl, init$, void, PolicyNodeImpl*, $String*, $Set*, bool, $Set*, bool)},
	{"<init>", "(Lsun/security/provider/certpath/PolicyNodeImpl;Lsun/security/provider/certpath/PolicyNodeImpl;)V", nullptr, 0, $method(PolicyNodeImpl, init$, void, PolicyNodeImpl*, PolicyNodeImpl*)},
	{"addChild", "(Lsun/security/provider/certpath/PolicyNodeImpl;)V", nullptr, $PRIVATE, $method(PolicyNodeImpl, addChild, void, PolicyNodeImpl*)},
	{"addExpectedPolicy", "(Ljava/lang/String;)V", nullptr, 0, $method(PolicyNodeImpl, addExpectedPolicy, void, $String*)},
	{"asString", "()Ljava/lang/String;", nullptr, 0, $method(PolicyNodeImpl, asString, $String*)},
	{"copyTree", "()Lsun/security/provider/certpath/PolicyNodeImpl;", nullptr, 0, $method(PolicyNodeImpl, copyTree, PolicyNodeImpl*)},
	{"copyTree", "(Lsun/security/provider/certpath/PolicyNodeImpl;)Lsun/security/provider/certpath/PolicyNodeImpl;", nullptr, $PRIVATE, $method(PolicyNodeImpl, copyTree, PolicyNodeImpl*, PolicyNodeImpl*)},
	{"deleteChild", "(Ljava/security/cert/PolicyNode;)V", nullptr, 0, $method(PolicyNodeImpl, deleteChild, void, $PolicyNode*)},
	{"getChildren", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Lsun/security/provider/certpath/PolicyNodeImpl;>;", $PUBLIC, $virtualMethod(PolicyNodeImpl, getChildren, $Iterator*)},
	{"getDepth", "()I", nullptr, $PUBLIC, $virtualMethod(PolicyNodeImpl, getDepth, int32_t)},
	{"getExpectedPolicies", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(PolicyNodeImpl, getExpectedPolicies, $Set*)},
	{"getParent", "()Ljava/security/cert/PolicyNode;", nullptr, $PUBLIC, $virtualMethod(PolicyNodeImpl, getParent, $PolicyNode*)},
	{"getPolicyNodes", "(I)Ljava/util/Set;", "(I)Ljava/util/Set<Lsun/security/provider/certpath/PolicyNodeImpl;>;", 0, $method(PolicyNodeImpl, getPolicyNodes, $Set*, int32_t)},
	{"getPolicyNodes", "(ILjava/util/Set;)V", "(ILjava/util/Set<Lsun/security/provider/certpath/PolicyNodeImpl;>;)V", $PRIVATE, $method(PolicyNodeImpl, getPolicyNodes, void, int32_t, $Set*)},
	{"getPolicyNodesExpected", "(ILjava/lang/String;Z)Ljava/util/Set;", "(ILjava/lang/String;Z)Ljava/util/Set<Lsun/security/provider/certpath/PolicyNodeImpl;>;", 0, $method(PolicyNodeImpl, getPolicyNodesExpected, $Set*, int32_t, $String*, bool)},
	{"getPolicyNodesExpectedHelper", "(ILjava/lang/String;Z)Ljava/util/Set;", "(ILjava/lang/String;Z)Ljava/util/Set<Lsun/security/provider/certpath/PolicyNodeImpl;>;", $PRIVATE, $method(PolicyNodeImpl, getPolicyNodesExpectedHelper, $Set*, int32_t, $String*, bool)},
	{"getPolicyNodesValid", "(ILjava/lang/String;)Ljava/util/Set;", "(ILjava/lang/String;)Ljava/util/Set<Lsun/security/provider/certpath/PolicyNodeImpl;>;", 0, $method(PolicyNodeImpl, getPolicyNodesValid, $Set*, int32_t, $String*)},
	{"getPolicyQualifiers", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/security/cert/PolicyQualifierInfo;>;", $PUBLIC, $virtualMethod(PolicyNodeImpl, getPolicyQualifiers, $Set*)},
	{"getValidPolicy", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PolicyNodeImpl, getValidPolicy, $String*)},
	{"isCritical", "()Z", nullptr, $PUBLIC, $virtualMethod(PolicyNodeImpl, isCritical, bool)},
	{"isImmutable", "()Z", nullptr, 0, $method(PolicyNodeImpl, isImmutable, bool)},
	{"policyToString", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(PolicyNodeImpl, policyToString, $String*, $String*)},
	{"prune", "(I)V", nullptr, 0, $method(PolicyNodeImpl, prune, void, int32_t)},
	{"setImmutable", "()V", nullptr, 0, $method(PolicyNodeImpl, setImmutable, void)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PolicyNodeImpl, toString, $String*)},
	{}
};

$ClassInfo _PolicyNodeImpl_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.provider.certpath.PolicyNodeImpl",
	"java.lang.Object",
	"java.security.cert.PolicyNode",
	_PolicyNodeImpl_FieldInfo_,
	_PolicyNodeImpl_MethodInfo_
};

$Object* allocate$PolicyNodeImpl($Class* clazz) {
	return $of($alloc(PolicyNodeImpl));
}

$String* PolicyNodeImpl::ANY_POLICY = nullptr;

void PolicyNodeImpl::init$(PolicyNodeImpl* parent, $String* validPolicy, $Set* qualifierSet, bool criticalityIndicator, $Set* expectedPolicySet, bool generatedByPolicyMapping) {
	this->isImmutable$ = false;
	$set(this, mParent, parent);
	$set(this, mChildren, $new($HashSet));
	if (validPolicy != nullptr) {
		$set(this, mValidPolicy, validPolicy);
	} else {
		$set(this, mValidPolicy, ""_s);
	}
	if (qualifierSet != nullptr) {
		$set(this, mQualifierSet, $new($HashSet, static_cast<$Collection*>(qualifierSet)));
	} else {
		$set(this, mQualifierSet, $new($HashSet));
	}
	this->mCriticalityIndicator = criticalityIndicator;
	if (expectedPolicySet != nullptr) {
		$set(this, mExpectedPolicySet, $new($HashSet, static_cast<$Collection*>(expectedPolicySet)));
	} else {
		$set(this, mExpectedPolicySet, $new($HashSet));
	}
	this->mOriginalExpectedPolicySet = !generatedByPolicyMapping;
	if (this->mParent != nullptr) {
		this->mDepth = $nc(this->mParent)->getDepth() + 1;
		$nc(this->mParent)->addChild(this);
	} else {
		this->mDepth = 0;
	}
}

void PolicyNodeImpl::init$(PolicyNodeImpl* parent, PolicyNodeImpl* node) {
	PolicyNodeImpl::init$(parent, $nc(node)->mValidPolicy, node->mQualifierSet, node->mCriticalityIndicator, node->mExpectedPolicySet, false);
}

$PolicyNode* PolicyNodeImpl::getParent() {
	return this->mParent;
}

$Iterator* PolicyNodeImpl::getChildren() {
	return $nc($($Collections::unmodifiableSet(this->mChildren)))->iterator();
}

int32_t PolicyNodeImpl::getDepth() {
	return this->mDepth;
}

$String* PolicyNodeImpl::getValidPolicy() {
	return this->mValidPolicy;
}

$Set* PolicyNodeImpl::getPolicyQualifiers() {
	return $Collections::unmodifiableSet(this->mQualifierSet);
}

$Set* PolicyNodeImpl::getExpectedPolicies() {
	return $Collections::unmodifiableSet(this->mExpectedPolicySet);
}

bool PolicyNodeImpl::isCritical() {
	return this->mCriticalityIndicator;
}

$String* PolicyNodeImpl::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, buffer, $new($StringBuilder, $(this->asString())));
	{
		$var($Iterator, i$, $nc(this->mChildren)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var(PolicyNodeImpl, node, $cast(PolicyNodeImpl, i$->next()));
			{
				buffer->append($of(node));
			}
		}
	}
	return buffer->toString();
}

bool PolicyNodeImpl::isImmutable() {
	return this->isImmutable$;
}

void PolicyNodeImpl::setImmutable() {
	$useLocalCurrentObjectStackCache();
	if (this->isImmutable$) {
		return;
	}
	{
		$var($Iterator, i$, $nc(this->mChildren)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var(PolicyNodeImpl, node, $cast(PolicyNodeImpl, i$->next()));
			{
				$nc(node)->setImmutable();
			}
		}
	}
	this->isImmutable$ = true;
}

void PolicyNodeImpl::addChild(PolicyNodeImpl* child) {
	if (this->isImmutable$) {
		$throwNew($IllegalStateException, "PolicyNode is immutable"_s);
	}
	$nc(this->mChildren)->add(child);
}

void PolicyNodeImpl::addExpectedPolicy($String* expectedPolicy) {
	if (this->isImmutable$) {
		$throwNew($IllegalStateException, "PolicyNode is immutable"_s);
	}
	if (this->mOriginalExpectedPolicySet) {
		$nc(this->mExpectedPolicySet)->clear();
		this->mOriginalExpectedPolicySet = false;
	}
	$nc(this->mExpectedPolicySet)->add(expectedPolicy);
}

void PolicyNodeImpl::prune(int32_t depth) {
	$useLocalCurrentObjectStackCache();
	if (this->isImmutable$) {
		$throwNew($IllegalStateException, "PolicyNode is immutable"_s);
	}
	if ($nc(this->mChildren)->size() == 0) {
		return;
	}
	$var($Iterator, it, $nc(this->mChildren)->iterator());
	while ($nc(it)->hasNext()) {
		$var(PolicyNodeImpl, node, $cast(PolicyNodeImpl, it->next()));
		$nc(node)->prune(depth);
		if (($nc(node->mChildren)->size() == 0) && (depth > this->mDepth + 1)) {
			it->remove();
		}
	}
}

void PolicyNodeImpl::deleteChild($PolicyNode* childNode) {
	if (this->isImmutable$) {
		$throwNew($IllegalStateException, "PolicyNode is immutable"_s);
	}
	$nc(this->mChildren)->remove(childNode);
}

PolicyNodeImpl* PolicyNodeImpl::copyTree() {
	return copyTree(nullptr);
}

PolicyNodeImpl* PolicyNodeImpl::copyTree(PolicyNodeImpl* parent) {
	$useLocalCurrentObjectStackCache();
	$var(PolicyNodeImpl, newNode, $new(PolicyNodeImpl, parent, this));
	{
		$var($Iterator, i$, $nc(this->mChildren)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var(PolicyNodeImpl, node, $cast(PolicyNodeImpl, i$->next()));
			{
				$nc(node)->copyTree(newNode);
			}
		}
	}
	return newNode;
}

$Set* PolicyNodeImpl::getPolicyNodes(int32_t depth) {
	$var($Set, set, $new($HashSet));
	getPolicyNodes(depth, set);
	return set;
}

void PolicyNodeImpl::getPolicyNodes(int32_t depth, $Set* set) {
	$useLocalCurrentObjectStackCache();
	if (this->mDepth == depth) {
		$nc(set)->add(this);
	} else {
		{
			$var($Iterator, i$, $nc(this->mChildren)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var(PolicyNodeImpl, node, $cast(PolicyNodeImpl, i$->next()));
				{
					$nc(node)->getPolicyNodes(depth, set);
				}
			}
		}
	}
}

$Set* PolicyNodeImpl::getPolicyNodesExpected(int32_t depth, $String* expectedOID, bool matchAny) {
	if ($nc(expectedOID)->equals(PolicyNodeImpl::ANY_POLICY)) {
		return getPolicyNodes(depth);
	} else {
		return getPolicyNodesExpectedHelper(depth, expectedOID, matchAny);
	}
}

$Set* PolicyNodeImpl::getPolicyNodesExpectedHelper(int32_t depth, $String* expectedOID, bool matchAny) {
	$useLocalCurrentObjectStackCache();
	$var($HashSet, set, $new($HashSet));
	if (this->mDepth < depth) {
		{
			$var($Iterator, i$, $nc(this->mChildren)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var(PolicyNodeImpl, node, $cast(PolicyNodeImpl, i$->next()));
				{
					set->addAll($($nc(node)->getPolicyNodesExpectedHelper(depth, expectedOID, matchAny)));
				}
			}
		}
	} else if (matchAny) {
		if ($nc(this->mExpectedPolicySet)->contains(PolicyNodeImpl::ANY_POLICY)) {
			set->add(this);
		}
	} else if ($nc(this->mExpectedPolicySet)->contains(expectedOID)) {
		set->add(this);
	}
	return set;
}

$Set* PolicyNodeImpl::getPolicyNodesValid(int32_t depth, $String* validOID) {
	$useLocalCurrentObjectStackCache();
	$var($HashSet, set, $new($HashSet));
	if (this->mDepth < depth) {
		{
			$var($Iterator, i$, $nc(this->mChildren)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var(PolicyNodeImpl, node, $cast(PolicyNodeImpl, i$->next()));
				{
					set->addAll($($nc(node)->getPolicyNodesValid(depth, validOID)));
				}
			}
		}
	} else if ($nc(this->mValidPolicy)->equals(validOID)) {
		set->add(this);
	}
	return set;
}

$String* PolicyNodeImpl::policyToString($String* oid) {
	$init(PolicyNodeImpl);
	if ($nc(oid)->equals(PolicyNodeImpl::ANY_POLICY)) {
		return "anyPolicy"_s;
	} else {
		return oid;
	}
}

$String* PolicyNodeImpl::asString() {
	$useLocalCurrentObjectStackCache();
	if (this->mParent == nullptr) {
		return "anyPolicy  ROOT\n"_s;
	} else {
		$var($StringBuilder, sb, $new($StringBuilder));
		{
			int32_t i = 0;
			int32_t n = getDepth();
			for (; i < n; ++i) {
				sb->append("  "_s);
			}
		}
		sb->append($(policyToString($(getValidPolicy()))));
		sb->append("  CRIT: "_s);
		sb->append(isCritical());
		sb->append("  EP: "_s);
		{
			$var($Iterator, i$, $nc($(getExpectedPolicies()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, policy, $cast($String, i$->next()));
				{
					sb->append($(policyToString(policy)));
					sb->append(" "_s);
				}
			}
		}
		sb->append(" ("_s);
		sb->append(getDepth());
		sb->append(")\n"_s);
		return sb->toString();
	}
}

void clinit$PolicyNodeImpl($Class* class$) {
	$init($KnownOIDs);
	$assignStatic(PolicyNodeImpl::ANY_POLICY, $KnownOIDs::CE_CERT_POLICIES_ANY->value());
}

PolicyNodeImpl::PolicyNodeImpl() {
}

$Class* PolicyNodeImpl::load$($String* name, bool initialize) {
	$loadClass(PolicyNodeImpl, name, initialize, &_PolicyNodeImpl_ClassInfo_, clinit$PolicyNodeImpl, allocate$PolicyNodeImpl);
	return class$;
}

$Class* PolicyNodeImpl::class$ = nullptr;

			} // certpath
		} // provider
	} // security
} // sun