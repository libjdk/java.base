#include <sun/util/resources/ParallelListResourceBundle$KeySet$1.h>

#include <java/lang/UnsupportedOperationException.h>
#include <java/util/Collection.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/NoSuchElementException.h>
#include <java/util/ResourceBundle.h>
#include <java/util/Set.h>
#include <sun/util/resources/ParallelListResourceBundle$KeySet.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Collection = ::java::util::Collection;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $NoSuchElementException = ::java::util::NoSuchElementException;
using $ResourceBundle = ::java::util::ResourceBundle;
using $Set = ::java::util::Set;
using $ParallelListResourceBundle$KeySet = ::sun::util::resources::ParallelListResourceBundle$KeySet;

namespace sun {
	namespace util {
		namespace resources {

$FieldInfo _ParallelListResourceBundle$KeySet$1_FieldInfo_[] = {
	{"this$0", "Lsun/util/resources/ParallelListResourceBundle$KeySet;", nullptr, $FINAL | $SYNTHETIC, $field(ParallelListResourceBundle$KeySet$1, this$0)},
	{"itr", "Ljava/util/Iterator;", "Ljava/util/Iterator<Ljava/lang/String;>;", $PRIVATE, $field(ParallelListResourceBundle$KeySet$1, itr)},
	{"usingParent", "Z", nullptr, $PRIVATE, $field(ParallelListResourceBundle$KeySet$1, usingParent)},
	{}
};

$MethodInfo _ParallelListResourceBundle$KeySet$1_MethodInfo_[] = {
	{"<init>", "(Lsun/util/resources/ParallelListResourceBundle$KeySet;)V", nullptr, 0, $method(ParallelListResourceBundle$KeySet$1, init$, void, $ParallelListResourceBundle$KeySet*)},
	{"hasNext", "()Z", nullptr, $PUBLIC, $virtualMethod(ParallelListResourceBundle$KeySet$1, hasNext, bool)},
	{"next", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ParallelListResourceBundle$KeySet$1, next, $Object*)},
	{"remove", "()V", nullptr, $PUBLIC, $virtualMethod(ParallelListResourceBundle$KeySet$1, remove, void)},
	{}
};

$EnclosingMethodInfo _ParallelListResourceBundle$KeySet$1_EnclosingMethodInfo_ = {
	"sun.util.resources.ParallelListResourceBundle$KeySet",
	"iterator",
	"()Ljava/util/Iterator;"
};

$InnerClassInfo _ParallelListResourceBundle$KeySet$1_InnerClassesInfo_[] = {
	{"sun.util.resources.ParallelListResourceBundle$KeySet", "sun.util.resources.ParallelListResourceBundle", "KeySet", $PRIVATE | $STATIC},
	{"sun.util.resources.ParallelListResourceBundle$KeySet$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ParallelListResourceBundle$KeySet$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.util.resources.ParallelListResourceBundle$KeySet$1",
	"java.lang.Object",
	"java.util.Iterator",
	_ParallelListResourceBundle$KeySet$1_FieldInfo_,
	_ParallelListResourceBundle$KeySet$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/Iterator<Ljava/lang/String;>;",
	&_ParallelListResourceBundle$KeySet$1_EnclosingMethodInfo_,
	_ParallelListResourceBundle$KeySet$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.util.resources.ParallelListResourceBundle"
};

$Object* allocate$ParallelListResourceBundle$KeySet$1($Class* clazz) {
	return $of($alloc(ParallelListResourceBundle$KeySet$1));
}

void ParallelListResourceBundle$KeySet$1::init$($ParallelListResourceBundle$KeySet* this$0) {
	$set(this, this$0, this$0);
	$set(this, itr, $nc(this->this$0->set)->iterator());
}

bool ParallelListResourceBundle$KeySet$1::hasNext() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->itr)->hasNext()) {
		return true;
	}
	if (!this->usingParent) {
		$var($Set, nextset, $new($HashSet, $(static_cast<$Collection*>($nc(this->this$0->parent)->keySet()))));
		nextset->removeAll(this->this$0->set);
		$set(this, itr, nextset->iterator());
		this->usingParent = true;
	}
	return $nc(this->itr)->hasNext();
}

$Object* ParallelListResourceBundle$KeySet$1::next() {
	if (hasNext()) {
		return $of($cast($String, $nc(this->itr)->next()));
	}
	$throwNew($NoSuchElementException);
}

void ParallelListResourceBundle$KeySet$1::remove() {
	$throwNew($UnsupportedOperationException);
}

ParallelListResourceBundle$KeySet$1::ParallelListResourceBundle$KeySet$1() {
}

$Class* ParallelListResourceBundle$KeySet$1::load$($String* name, bool initialize) {
	$loadClass(ParallelListResourceBundle$KeySet$1, name, initialize, &_ParallelListResourceBundle$KeySet$1_ClassInfo_, allocate$ParallelListResourceBundle$KeySet$1);
	return class$;
}

$Class* ParallelListResourceBundle$KeySet$1::class$ = nullptr;

		} // resources
	} // util
} // sun