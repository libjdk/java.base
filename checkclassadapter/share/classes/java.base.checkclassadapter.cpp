#include <java.base.checkclassadapter.h>
#include <java.base.h>
#include <java/lang/ClassEntry.h>
#include <java/lang/Library.h>
#include <java/lang/ModuleInfo.h>
#include <java/lang/ResourceEntry.h>
#include <jcpp.h>

void java$base$checkclassadapter$PreloadClass() {
}

void java$base$checkclassadapter$PreinitClass() {
}

void java$base$checkclassadapter$LibEventAction(int32_t eventType, void* eventData) {
	if (eventType == JCPP_LIB_EVENT_TYPE_PRELOAD_CLASS) {
		java$base$checkclassadapter$PreloadClass();
	} else if (eventType == JCPP_LIB_EVENT_TYPE_PREINIT_CLASS) {
		java$base$checkclassadapter$PreinitClass();
	}
}

$StringArray* java$base$checkclassadapter$GetPackages() {
	return nullptr;
}

::java::lang::ClassEntry* java$base$checkclassadapter$GetClassEntry($String* name) {
	return nullptr;
}

$bytes* java$base$checkclassadapter$GetResource($String* name) {
	return nullptr;
}

void java$base$checkclassadapter::init() {
	::java$base::init();
	::java::lang::Library lib = {
		"java.base.checkclassadapter", "17.35", "",
		nullptr,
		java$base$checkclassadapter$LibEventAction,
		java$base$checkclassadapter$GetPackages,
		java$base$checkclassadapter$GetClassEntry,
		java$base$checkclassadapter$GetResource
	};
	$System::addLibrary(&lib);
}

#ifdef JCPP_SHARED_BUILD
extern "C" $export void JCPP_OnLoad() {
	java$base$checkclassadapter::init();
}
#endif