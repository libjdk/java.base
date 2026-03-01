#include <java/io/ObjectOutputStream$DebugTraceInfoStack.h>

#include <java/io/ObjectOutputStream.h>
#include <java/lang/CharSequence.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <java/util/StringJoiner.h>
#include <jcpp.h>

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $StringJoiner = ::java::util::StringJoiner;

namespace java {
	namespace io {

$FieldInfo _ObjectOutputStream$DebugTraceInfoStack_FieldInfo_[] = {
	{"stack", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PRIVATE | $FINAL, $field(ObjectOutputStream$DebugTraceInfoStack, stack)},
	{}
};

$MethodInfo _ObjectOutputStream$DebugTraceInfoStack_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(ObjectOutputStream$DebugTraceInfoStack, init$, void)},
	{"clear", "()V", nullptr, 0, $virtualMethod(ObjectOutputStream$DebugTraceInfoStack, clear, void)},
	{"pop", "()V", nullptr, 0, $virtualMethod(ObjectOutputStream$DebugTraceInfoStack, pop, void)},
	{"push", "(Ljava/lang/String;)V", nullptr, 0, $virtualMethod(ObjectOutputStream$DebugTraceInfoStack, push, void, $String*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream$DebugTraceInfoStack, toString, $String*)},
	{}
};

$InnerClassInfo _ObjectOutputStream$DebugTraceInfoStack_InnerClassesInfo_[] = {
	{"java.io.ObjectOutputStream$DebugTraceInfoStack", "java.io.ObjectOutputStream", "DebugTraceInfoStack", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _ObjectOutputStream$DebugTraceInfoStack_ClassInfo_ = {
	$ACC_SUPER,
	"java.io.ObjectOutputStream$DebugTraceInfoStack",
	"java.lang.Object",
	nullptr,
	_ObjectOutputStream$DebugTraceInfoStack_FieldInfo_,
	_ObjectOutputStream$DebugTraceInfoStack_MethodInfo_,
	nullptr,
	nullptr,
	_ObjectOutputStream$DebugTraceInfoStack_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.io.ObjectOutputStream"
};

$Object* allocate$ObjectOutputStream$DebugTraceInfoStack($Class* clazz) {
	return $of($alloc(ObjectOutputStream$DebugTraceInfoStack));
}

void ObjectOutputStream$DebugTraceInfoStack::init$() {
	$set(this, stack, $new($ArrayList));
}

void ObjectOutputStream$DebugTraceInfoStack::clear() {
	$nc(this->stack)->clear();
}

void ObjectOutputStream$DebugTraceInfoStack::pop() {
	$nc(this->stack)->remove($nc(this->stack)->size() - 1);
}

void ObjectOutputStream$DebugTraceInfoStack::push($String* entry) {
	$nc(this->stack)->add($$str({"\t- "_s, entry}));
}

$String* ObjectOutputStream$DebugTraceInfoStack::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringJoiner, sj, $new($StringJoiner, "\n"_s));
	for (int32_t i = $nc(this->stack)->size() - 1; i >= 0; --i) {
		sj->add($cast($CharSequence, $($nc(this->stack)->get(i))));
	}
	return sj->toString();
}

ObjectOutputStream$DebugTraceInfoStack::ObjectOutputStream$DebugTraceInfoStack() {
}

$Class* ObjectOutputStream$DebugTraceInfoStack::load$($String* name, bool initialize) {
	$loadClass(ObjectOutputStream$DebugTraceInfoStack, name, initialize, &_ObjectOutputStream$DebugTraceInfoStack_ClassInfo_, allocate$ObjectOutputStream$DebugTraceInfoStack);
	return class$;
}

$Class* ObjectOutputStream$DebugTraceInfoStack::class$ = nullptr;

	} // io
} // java