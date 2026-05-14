#include <java.base.printpattern.h>
#include <java.base.h>
#include <java/lang/ClassEntry.h>
#include <java/lang/Library.h>
#include <java/lang/ModuleInfo.h>
#include <java/lang/ResourceEntry.h>
#include <jcpp.h>

void java$base$printpattern$PreloadClass() {
}

void java$base$printpattern$PreinitClass() {
}

void java$base$printpattern$LibEventAction(int32_t eventType, void* eventData) {
	if (eventType == JCPP_LIB_EVENT_TYPE_PRELOAD_CLASS) {
		java$base$printpattern$PreloadClass();
	} else if (eventType == JCPP_LIB_EVENT_TYPE_PREINIT_CLASS) {
		java$base$printpattern$PreinitClass();
	}
}

$StringArray* java$base$printpattern$GetPackages() {
	return nullptr;
}

::java::lang::ClassEntry* java$base$printpattern$GetClassEntry($String* name) {
	return nullptr;
}

$bytes* java$base$printpattern$GetResource($String* name) {
	return nullptr;
}

void java$base$printpattern::init() {
	::java$base::init();
	::java::lang::Library lib = {
		"java.base.printpattern", "17.35", "",
		nullptr,
		java$base$printpattern$LibEventAction,
		java$base$printpattern$GetPackages,
		java$base$printpattern$GetClassEntry,
		java$base$printpattern$GetResource
	};
	$System::addLibrary(&lib);
}

#ifdef JCPP_SHARED_BUILD
extern "C" $export void JCPP_OnLoad() {
	java$base$printpattern::init();
}
#endif