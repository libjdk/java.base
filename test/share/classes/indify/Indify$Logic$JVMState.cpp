#include <indify/Indify$Logic$JVMState.h>

#include <indify/Indify$Logic.h>
#include <indify/Indify.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <jcpp.h>

using $Indify = ::indify::Indify;
using $Indify$Logic = ::indify::Indify$Logic;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;

namespace indify {

$FieldInfo _Indify$Logic$JVMState_FieldInfo_[] = {
	{"this$1", "Lindify/Indify$Logic;", nullptr, $FINAL | $SYNTHETIC, $field(Indify$Logic$JVMState, this$1)},
	{"stack", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Object;>;", $FINAL, $field(Indify$Logic$JVMState, stack)},
	{}
};

$MethodInfo _Indify$Logic$JVMState_MethodInfo_[] = {
	{"<init>", "(Lindify/Indify$Logic;)V", nullptr, $PRIVATE, $method(Indify$Logic$JVMState, init$, void, $Indify$Logic*)},
	{"args", "(ZLjava/lang/String;)Ljava/util/List;", "(ZLjava/lang/String;)Ljava/util/List<Ljava/lang/Object;>;", 0, $virtualMethod(Indify$Logic$JVMState, args, $List*, bool, $String*)},
	{"args", "(I)Ljava/util/List;", "(I)Ljava/util/List<Ljava/lang/Object;>;", 0, $virtualMethod(Indify$Logic$JVMState, args, $List*, int32_t)},
	{"pop", "()Ljava/lang/Object;", nullptr, 0, $virtualMethod(Indify$Logic$JVMState, pop, $Object*)},
	{"push", "(Ljava/lang/Object;)V", nullptr, 0, $virtualMethod(Indify$Logic$JVMState, push, void, Object$*)},
	{"push2", "(Ljava/lang/Object;)V", nullptr, 0, $virtualMethod(Indify$Logic$JVMState, push2, void, Object$*)},
	{"pushAt", "(ILjava/lang/Object;)V", nullptr, 0, $virtualMethod(Indify$Logic$JVMState, pushAt, void, int32_t, Object$*)},
	{"sp", "()I", nullptr, 0, $virtualMethod(Indify$Logic$JVMState, sp, int32_t)},
	{"stackMotion", "(I)Z", nullptr, 0, $virtualMethod(Indify$Logic$JVMState, stackMotion, bool, int32_t)},
	{"top", "()Ljava/lang/Object;", nullptr, 0, $virtualMethod(Indify$Logic$JVMState, top, $Object*)},
	{}
};

$InnerClassInfo _Indify$Logic$JVMState_InnerClassesInfo_[] = {
	{"indify.Indify$Logic", "indify.Indify", "Logic", $PRIVATE},
	{"indify.Indify$Logic$JVMState", "indify.Indify$Logic", "JVMState", $PRIVATE},
	{}
};

$ClassInfo _Indify$Logic$JVMState_ClassInfo_ = {
	$ACC_SUPER,
	"indify.Indify$Logic$JVMState",
	"java.lang.Object",
	nullptr,
	_Indify$Logic$JVMState_FieldInfo_,
	_Indify$Logic$JVMState_MethodInfo_,
	nullptr,
	nullptr,
	_Indify$Logic$JVMState_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"indify.Indify"
};

$Object* allocate$Indify$Logic$JVMState($Class* clazz) {
	return $of($alloc(Indify$Logic$JVMState));
}

void Indify$Logic$JVMState::init$($Indify$Logic* this$1) {
	$set(this, this$1, this$1);
	$set(this, stack, $new($ArrayList));
}

int32_t Indify$Logic$JVMState::sp() {
	return $nc(this->stack)->size();
}

void Indify$Logic$JVMState::push(Object$* x) {
	$nc(this->stack)->add(x);
}

void Indify$Logic$JVMState::push2(Object$* x) {
	$nc(this->stack)->add("_"_s);
	$nc(this->stack)->add(x);
}

void Indify$Logic$JVMState::pushAt(int32_t pos, Object$* x) {
	$nc(this->stack)->add($nc(this->stack)->size() + pos, x);
}

$Object* Indify$Logic$JVMState::pop() {
	return $of($nc(this->stack)->remove(sp() - 1));
}

$Object* Indify$Logic$JVMState::top() {
	return $of($nc(this->stack)->get(sp() - 1));
}

$List* Indify$Logic$JVMState::args(bool hasRecv, $String* type) {
	return args($Indify::argsize(type) + (hasRecv ? 1 : 0));
}

$List* Indify$Logic$JVMState::args(int32_t argsize) {
	int32_t var$0 = sp() - argsize;
	return $nc(this->stack)->subList(var$0, sp());
}

bool Indify$Logic$JVMState::stackMotion(int32_t bc) {
	$useLocalCurrentObjectStackCache();
	switch (bc) {
	case 87:
		{
			pop();
			break;
		}
	case 88:
		{
			pop();
			pop();
			break;
		}
	case 95:
		{
			pushAt(-1, $(pop()));
			break;
		}
	case 89:
		{
			push($(top()));
			break;
		}
	case 90:
		{
			pushAt(-2, $(top()));
			break;
		}
	case 91:
		{
			pushAt(-3, $(top()));
			break;
		}
	default:
		{
			return false;
		}
	}
	return true;
}

Indify$Logic$JVMState::Indify$Logic$JVMState() {
}

$Class* Indify$Logic$JVMState::load$($String* name, bool initialize) {
	$loadClass(Indify$Logic$JVMState, name, initialize, &_Indify$Logic$JVMState_ClassInfo_, allocate$Indify$Logic$JVMState);
	return class$;
}

$Class* Indify$Logic$JVMState::class$ = nullptr;

} // indify