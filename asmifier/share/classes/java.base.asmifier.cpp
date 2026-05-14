#include <java.base.asmifier.h>
#include <java.base.h>
#include <java/lang/ClassEntry.h>
#include <java/lang/Library.h>
#include <java/lang/ModuleInfo.h>
#include <java/lang/ResourceEntry.h>
#include <jcpp.h>

void java$base$asmifier$PreloadClass() {
}

void java$base$asmifier$PreinitClass() {
}

void java$base$asmifier$LibEventAction(int32_t eventType, void* eventData) {
	if (eventType == JCPP_LIB_EVENT_TYPE_PRELOAD_CLASS) {
		java$base$asmifier$PreloadClass();
	} else if (eventType == JCPP_LIB_EVENT_TYPE_PREINIT_CLASS) {
		java$base$asmifier$PreinitClass();
	}
}

$StringArray* java$base$asmifier$GetPackages() {
	return nullptr;
}

::java::lang::ClassEntry* java$base$asmifier$GetClassEntry($String* name) {
	return nullptr;
}

$bytes* java$base$asmifier$GetResource($String* name) {
	return nullptr;
}

void java$base$asmifier::init() {
	::java$base::init();
	::java::lang::Library lib = {
		"java.base.asmifier", "17.35", "",
		nullptr,
		java$base$asmifier$LibEventAction,
		java$base$asmifier$GetPackages,
		java$base$asmifier$GetClassEntry,
		java$base$asmifier$GetResource
	};
	$System::addLibrary(&lib);
}

#ifdef JCPP_SHARED_BUILD
extern "C" $export void JCPP_OnLoad() {
	java$base$asmifier::init();
}
#endif