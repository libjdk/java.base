#include <java/util/AbstractList$ListItr.h>

#include <java/lang/IllegalStateException.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/util/AbstractList$Itr.h>
#include <java/util/AbstractList.h>
#include <java/util/ConcurrentModificationException.h>
#include <java/util/NoSuchElementException.h>
#include <java/util/function/Consumer.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractList = ::java::util::AbstractList;
using $AbstractList$Itr = ::java::util::AbstractList$Itr;
using $ConcurrentModificationException = ::java::util::ConcurrentModificationException;
using $NoSuchElementException = ::java::util::NoSuchElementException;
using $Consumer = ::java::util::function::Consumer;

namespace java {
	namespace util {

$FieldInfo _AbstractList$ListItr_FieldInfo_[] = {
	{"this$0", "Ljava/util/AbstractList;", nullptr, $FINAL | $SYNTHETIC, $field(AbstractList$ListItr, this$0)},
	{}
};

$MethodInfo _AbstractList$ListItr_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEachRemaining", "(Ljava/util/function/Consumer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*hasNext", "()Z", nullptr, $PUBLIC},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/AbstractList;I)V", nullptr, 0, $method(AbstractList$ListItr, init$, void, $AbstractList*, int32_t)},
	{"add", "(Ljava/lang/Object;)V", "(TE;)V", $PUBLIC, $virtualMethod(AbstractList$ListItr, add, void, Object$*)},
	{"hasPrevious", "()Z", nullptr, $PUBLIC, $virtualMethod(AbstractList$ListItr, hasPrevious, bool)},
	{"*next", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"nextIndex", "()I", nullptr, $PUBLIC, $virtualMethod(AbstractList$ListItr, nextIndex, int32_t)},
	{"previous", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(AbstractList$ListItr, previous, $Object*)},
	{"previousIndex", "()I", nullptr, $PUBLIC, $virtualMethod(AbstractList$ListItr, previousIndex, int32_t)},
	{"*remove", "()V", nullptr, $PUBLIC},
	{"set", "(Ljava/lang/Object;)V", "(TE;)V", $PUBLIC, $virtualMethod(AbstractList$ListItr, set, void, Object$*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _AbstractList$ListItr_InnerClassesInfo_[] = {
	{"java.util.AbstractList$ListItr", "java.util.AbstractList", "ListItr", $PRIVATE},
	{"java.util.AbstractList$Itr", "java.util.AbstractList", "Itr", $PRIVATE},
	{}
};

$ClassInfo _AbstractList$ListItr_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.AbstractList$ListItr",
	"java.util.AbstractList$Itr",
	"java.util.ListIterator",
	_AbstractList$ListItr_FieldInfo_,
	_AbstractList$ListItr_MethodInfo_,
	"Ljava/util/AbstractList<TE;>.Itr;Ljava/util/ListIterator<TE;>;",
	nullptr,
	_AbstractList$ListItr_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.AbstractList"
};

$Object* allocate$AbstractList$ListItr($Class* clazz) {
	return $of($alloc(AbstractList$ListItr));
}

bool AbstractList$ListItr::hasNext() {
	 return this->$AbstractList$Itr::hasNext();
}

$Object* AbstractList$ListItr::next() {
	 return this->$AbstractList$Itr::next();
}

void AbstractList$ListItr::remove() {
	this->$AbstractList$Itr::remove();
}

void AbstractList$ListItr::forEachRemaining($Consumer* action) {
	this->$AbstractList$Itr::forEachRemaining(action);
}

int32_t AbstractList$ListItr::hashCode() {
	 return this->$AbstractList$Itr::hashCode();
}

bool AbstractList$ListItr::equals(Object$* obj) {
	 return this->$AbstractList$Itr::equals(obj);
}

$Object* AbstractList$ListItr::clone() {
	 return this->$AbstractList$Itr::clone();
}

$String* AbstractList$ListItr::toString() {
	 return this->$AbstractList$Itr::toString();
}

void AbstractList$ListItr::finalize() {
	this->$AbstractList$Itr::finalize();
}

void AbstractList$ListItr::init$($AbstractList* this$0, int32_t index) {
	$set(this, this$0, this$0);
	$AbstractList$Itr::init$(this$0);
	this->cursor = index;
}

bool AbstractList$ListItr::hasPrevious() {
	return this->cursor != 0;
}

$Object* AbstractList$ListItr::previous() {
	checkForComodification();
	try {
		int32_t i = this->cursor - 1;
		$var($Object, previous, this->this$0->get(i));
		this->lastRet = (this->cursor = i);
		return $of(previous);
	} catch ($IndexOutOfBoundsException& e) {
		checkForComodification();
		$throwNew($NoSuchElementException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

int32_t AbstractList$ListItr::nextIndex() {
	return this->cursor;
}

int32_t AbstractList$ListItr::previousIndex() {
	return this->cursor - 1;
}

void AbstractList$ListItr::set(Object$* e) {
	if (this->lastRet < 0) {
		$throwNew($IllegalStateException);
	}
	checkForComodification();
	try {
		this->this$0->set(this->lastRet, e);
		this->expectedModCount = this->this$0->modCount;
	} catch ($IndexOutOfBoundsException& ex) {
		$throwNew($ConcurrentModificationException);
	}
}

void AbstractList$ListItr::add(Object$* e) {
	checkForComodification();
	try {
		int32_t i = this->cursor;
		this->this$0->add(i, e);
		this->lastRet = -1;
		this->cursor = i + 1;
		this->expectedModCount = this->this$0->modCount;
	} catch ($IndexOutOfBoundsException& ex) {
		$throwNew($ConcurrentModificationException);
	}
}

AbstractList$ListItr::AbstractList$ListItr() {
}

$Class* AbstractList$ListItr::load$($String* name, bool initialize) {
	$loadClass(AbstractList$ListItr, name, initialize, &_AbstractList$ListItr_ClassInfo_, allocate$AbstractList$ListItr);
	return class$;
}

$Class* AbstractList$ListItr::class$ = nullptr;

	} // util
} // java