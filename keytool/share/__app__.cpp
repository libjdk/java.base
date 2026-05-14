#include <java.base.keytool.h>

#include <sun/security/tools/keytool/Main.h>
#include <jcpp.h>

#ifdef JCPP_SUBSYSTEM_WINDOWS
#include <windows.h>
int WINAPI WinMain(HINSTANCE inst, HINSTANCE previnst, LPSTR cmdline, int cmdshow) {
	return $System::launchw(::java$base$keytool::init, []($StringArray* args) -> void {
		::sun::security::tools::keytool::Main::main(args);
	});
}
#else
int main(int argc, char** argv) {
	return $System::launch(argc, argv, ::java$base$keytool::init, []($StringArray* args) -> void {
		::sun::security::tools::keytool::Main::main(args);
	});
}
#endif