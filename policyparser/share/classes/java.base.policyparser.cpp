#include <java.base.policyparser.h>
#include <java.base.h>
#include <java/lang/ClassEntry.h>
#include <java/lang/Library.h>
#include <java/lang/ModuleInfo.h>
#include <java/lang/ResourceEntry.h>
#include <jcpp.h>

void java$base$policyparser$PreloadClass() {
}

void java$base$policyparser$PreinitClass() {
}

void java$base$policyparser$LibEventAction(int32_t eventType, void* eventData) {
	if (eventType == JCPP_LIB_EVENT_TYPE_PRELOAD_CLASS) {
		java$base$policyparser$PreloadClass();
	} else if (eventType == JCPP_LIB_EVENT_TYPE_PREINIT_CLASS) {
		java$base$policyparser$PreinitClass();
	}
}

$StringArray* java$base$policyparser$GetPackages() {
	return nullptr;
}

::java::lang::ClassEntry* java$base$policyparser$GetClassEntry($String* name) {
	return nullptr;
}

$bytes* java$base$policyparser$GetResource($String* name) {
	return nullptr;
}

void java$base$policyparser::init() {
	::java$base::init();
	::java::lang::Library lib = {
		"java.base.policyparser", "17.35", "",
		nullptr,
		java$base$policyparser$LibEventAction,
		java$base$policyparser$GetPackages,
		java$base$policyparser$GetClassEntry,
		java$base$policyparser$GetResource
	};
	$System::addLibrary(&lib);
}

#ifdef JCPP_SHARED_BUILD
extern "C" $export void JCPP_OnLoad() {
	java$base$policyparser::init();
}
#endif