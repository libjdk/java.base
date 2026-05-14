#include <java.base.keytool.h>
#include <java.base.h>
#include <java/lang/ClassEntry.h>
#include <java/lang/Library.h>
#include <java/lang/ModuleInfo.h>
#include <java/lang/ResourceEntry.h>
#include <jcpp.h>

void java$base$keytool$PreloadClass() {
}

void java$base$keytool$PreinitClass() {
}

void java$base$keytool$LibEventAction(int32_t eventType, void* eventData) {
	if (eventType == JCPP_LIB_EVENT_TYPE_PRELOAD_CLASS) {
		java$base$keytool$PreloadClass();
	} else if (eventType == JCPP_LIB_EVENT_TYPE_PREINIT_CLASS) {
		java$base$keytool$PreinitClass();
	}
}

$StringArray* java$base$keytool$GetPackages() {
	return nullptr;
}

::java::lang::ClassEntry* java$base$keytool$GetClassEntry($String* name) {
	return nullptr;
}

$bytes* java$base$keytool$GetResource($String* name) {
	return nullptr;
}

void java$base$keytool::init() {
	::java$base::init();
	::java::lang::Library lib = {
		"java.base.keytool", "17.35", "",
		nullptr,
		java$base$keytool$LibEventAction,
		java$base$keytool$GetPackages,
		java$base$keytool$GetClassEntry,
		java$base$keytool$GetResource
	};
	$System::addLibrary(&lib);
}

#ifdef JCPP_SHARED_BUILD
extern "C" $export void JCPP_OnLoad() {
	java$base$keytool::init();
}
#endif