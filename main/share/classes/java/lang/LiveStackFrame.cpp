#include <java/lang/LiveStackFrame.h>

#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/StackWalker$ExtendedOption.h>
#include <java/lang/StackWalker$Option.h>
#include <java/lang/StackWalker.h>
#include <java/security/Permission.h>
#include <java/util/EnumSet.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef LOCALS_AND_OPERANDS

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $StackWalker = ::java::lang::StackWalker;
using $StackWalker$ExtendedOption = ::java::lang::StackWalker$ExtendedOption;
using $StackWalker$Option = ::java::lang::StackWalker$Option;
using $Permission = ::java::security::Permission;
using $EnumSet = ::java::util::EnumSet;
using $Set = ::java::util::Set;

namespace java {
	namespace lang {

$MethodInfo _LiveStackFrame_MethodInfo_[] = {
	{"getLocals", "()[Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LiveStackFrame, getLocals, $ObjectArray*)},
	{"getMonitors", "()[Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LiveStackFrame, getMonitors, $ObjectArray*)},
	{"getStack", "()[Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LiveStackFrame, getStack, $ObjectArray*)},
	{"getStackWalker", "()Ljava/lang/StackWalker;", nullptr, $PUBLIC | $STATIC, $staticMethod(LiveStackFrame, getStackWalker, $StackWalker*)},
	{"getStackWalker", "(Ljava/util/Set;)Ljava/lang/StackWalker;", "(Ljava/util/Set<Ljava/lang/StackWalker$Option;>;)Ljava/lang/StackWalker;", $PUBLIC | $STATIC, $staticMethod(LiveStackFrame, getStackWalker, $StackWalker*, $Set*)},
	{}
};

$InnerClassInfo _LiveStackFrame_InnerClassesInfo_[] = {
	{"java.lang.StackWalker$StackFrame", "java.lang.StackWalker", "StackFrame", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.lang.LiveStackFrame$PrimitiveSlot", "java.lang.LiveStackFrame", "PrimitiveSlot", $PUBLIC | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _LiveStackFrame_ClassInfo_ = {
	$INTERFACE | $ABSTRACT,
	"java.lang.LiveStackFrame",
	nullptr,
	"java.lang.StackWalker$StackFrame",
	nullptr,
	_LiveStackFrame_MethodInfo_,
	nullptr,
	nullptr,
	_LiveStackFrame_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.LiveStackFrame$PrimitiveSlot"
};

$Object* allocate$LiveStackFrame($Class* clazz) {
	return $of($alloc(LiveStackFrame));
}

$StackWalker* LiveStackFrame::getStackWalker() {
	$init(LiveStackFrame);
	$load($StackWalker$Option);
	return getStackWalker($($EnumSet::noneOf($StackWalker$Option::class$)));
}

$StackWalker* LiveStackFrame::getStackWalker($Set* options) {
	$init(LiveStackFrame);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, "liveStackFrames"_s));
	}
	$init($StackWalker$ExtendedOption);
	return $StackWalker::newInstance(options, $StackWalker$ExtendedOption::LOCALS_AND_OPERANDS);
}

$Class* LiveStackFrame::load$($String* name, bool initialize) {
	$loadClass(LiveStackFrame, name, initialize, &_LiveStackFrame_ClassInfo_, allocate$LiveStackFrame);
	return class$;
}

$Class* LiveStackFrame::class$ = nullptr;

	} // lang
} // java