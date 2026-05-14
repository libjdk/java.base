#include <java.base.textifier.h>
#include <java.base.h>
#include <java/lang/ClassEntry.h>
#include <java/lang/Library.h>
#include <java/lang/ModuleInfo.h>
#include <java/lang/ResourceEntry.h>
#include <jcpp.h>

void java$base$textifier$PreloadClass() {
}

void java$base$textifier$PreinitClass() {
}

void java$base$textifier$LibEventAction(int32_t eventType, void* eventData) {
	if (eventType == JCPP_LIB_EVENT_TYPE_PRELOAD_CLASS) {
		java$base$textifier$PreloadClass();
	} else if (eventType == JCPP_LIB_EVENT_TYPE_PREINIT_CLASS) {
		java$base$textifier$PreinitClass();
	}
}

$StringArray* java$base$textifier$GetPackages() {
	return nullptr;
}

::java::lang::ClassEntry* java$base$textifier$GetClassEntry($String* name) {
	return nullptr;
}

$bytes* java$base$textifier$GetResource($String* name) {
	return nullptr;
}

void java$base$textifier::init() {
	::java$base::init();
	::java::lang::Library lib = {
		"java.base.textifier", "17.35", "",
		nullptr,
		java$base$textifier$LibEventAction,
		java$base$textifier$GetPackages,
		java$base$textifier$GetClassEntry,
		java$base$textifier$GetResource
	};
	$System::addLibrary(&lib);
}

#ifdef JCPP_SHARED_BUILD
extern "C" $export void JCPP_OnLoad() {
	java$base$textifier::init();
}
#endif