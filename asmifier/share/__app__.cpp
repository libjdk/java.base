#include <java.base.asmifier.h>

#include <jdk/internal/org/objectweb/asm/util/ASMifier.h>
#include <jcpp.h>

#ifdef JCPP_SUBSYSTEM_WINDOWS
#include <windows.h>
int WINAPI WinMain(HINSTANCE inst, HINSTANCE previnst, LPSTR cmdline, int cmdshow) {
	return $System::launchw(::java$base$asmifier::init, []($StringArray* args) -> void {
		::jdk::internal::org::objectweb::asm$::util::ASMifier::main(args);
	});
}
#else
int main(int argc, char** argv) {
	return $System::launch(argc, argv, ::java$base$asmifier::init, []($StringArray* args) -> void {
		::jdk::internal::org::objectweb::asm$::util::ASMifier::main(args);
	});
}
#endif