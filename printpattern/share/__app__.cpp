#include <java.base.printpattern.h>

#include <java/util/regex/PrintPattern.h>
#include <jcpp.h>

#ifdef JCPP_SUBSYSTEM_WINDOWS
#include <windows.h>
int WINAPI WinMain(HINSTANCE inst, HINSTANCE previnst, LPSTR cmdline, int cmdshow) {
	return $System::launchw(::java$base$printpattern::init, []($StringArray* args) -> void {
		::java::util::regex::PrintPattern::main(args);
	});
}
#else
int main(int argc, char** argv) {
	return $System::launch(argc, argv, ::java$base$printpattern::init, []($StringArray* args) -> void {
		::java::util::regex::PrintPattern::main(args);
	});
}
#endif