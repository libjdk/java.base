#include <java.base.policyparser.h>

#include <sun/security/provider/PolicyParser.h>
#include <jcpp.h>

#ifdef JCPP_SUBSYSTEM_WINDOWS
#include <windows.h>
int WINAPI WinMain(HINSTANCE inst, HINSTANCE previnst, LPSTR cmdline, int cmdshow) {
	return $System::launchw(::java$base$policyparser::init, []($StringArray* args) -> void {
		::sun::security::provider::PolicyParser::main(args);
	});
}
#else
int main(int argc, char** argv) {
	return $System::launch(argc, argv, ::java$base$policyparser::init, []($StringArray* args) -> void {
		::sun::security::provider::PolicyParser::main(args);
	});
}
#endif