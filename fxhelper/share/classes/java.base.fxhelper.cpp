#include <java.base.fxhelper.h>
#include <java.base.h>
#include <java/lang/ClassEntry.h>
#include <java/lang/Library.h>
#include <java/lang/ModuleInfo.h>
#include <java/lang/ResourceEntry.h>
#include <jcpp.h>

void java$base$fxhelper$PreloadClass() {
}

void java$base$fxhelper$PreinitClass() {
}

void java$base$fxhelper$LibEventAction(int32_t eventType, void* eventData) {
	if (eventType == JCPP_LIB_EVENT_TYPE_PRELOAD_CLASS) {
		java$base$fxhelper$PreloadClass();
	} else if (eventType == JCPP_LIB_EVENT_TYPE_PREINIT_CLASS) {
		java$base$fxhelper$PreinitClass();
	}
}

$StringArray* java$base$fxhelper$GetPackages() {
	return nullptr;
}

::java::lang::ClassEntry* java$base$fxhelper$GetClassEntry($String* name) {
	return nullptr;
}

$bytes* java$base$fxhelper$GetResource($String* name) {
	return nullptr;
}

void java$base$fxhelper::init() {
	::java$base::init();
	::java::lang::Library lib = {
		"java.base.fxhelper", "17.35", "",
		nullptr,
		java$base$fxhelper$LibEventAction,
		java$base$fxhelper$GetPackages,
		java$base$fxhelper$GetClassEntry,
		java$base$fxhelper$GetResource
	};
	$System::addLibrary(&lib);
}

#ifdef JCPP_SHARED_BUILD
extern "C" $export void JCPP_OnLoad() {
	java$base$fxhelper::init();
}
#endif