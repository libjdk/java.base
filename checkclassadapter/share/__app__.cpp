#include <java.base.checkclassadapter.h>

#include <jdk/internal/org/objectweb/asm/util/CheckClassAdapter.h>
#include <jcpp.h>

#ifdef JCPP_SUBSYSTEM_WINDOWS
#include <windows.h>
int WINAPI WinMain(HINSTANCE inst, HINSTANCE previnst, LPSTR cmdline, int cmdshow) {
	return $System::launchw(::java$base$checkclassadapter::init, []($StringArray* args) -> void {
		::jdk::internal::org::objectweb::asm$::util::CheckClassAdapter::main(args);
	});
}
#else
int main(int argc, char** argv) {
	return $System::launch(argc, argv, ::java$base$checkclassadapter::init, []($StringArray* args) -> void {
		::jdk::internal::org::objectweb::asm$::util::CheckClassAdapter::main(args);
	});
}
#endif