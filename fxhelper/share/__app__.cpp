#include <java.base.fxhelper.h>

#include <sun/launcher/LauncherHelper$FXHelper.h>
#include <jcpp.h>

#ifdef JCPP_SUBSYSTEM_WINDOWS
#include <windows.h>
int WINAPI WinMain(HINSTANCE inst, HINSTANCE previnst, LPSTR cmdline, int cmdshow) {
	return $System::launchw(::java$base$fxhelper::init, []($StringArray* args) -> void {
		::sun::launcher::LauncherHelper$FXHelper::main(args);
	});
}
#else
int main(int argc, char** argv) {
	return $System::launch(argc, argv, ::java$base$fxhelper::init, []($StringArray* args) -> void {
		::sun::launcher::LauncherHelper$FXHelper::main(args);
	});
}
#endif