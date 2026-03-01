#include <ExitVM.h>

#include <java/lang/RuntimePermission.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <jcpp.h>

using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;

$MethodInfo _ExitVM_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ExitVM, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ExitVM, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$ClassInfo _ExitVM_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ExitVM",
	"java.lang.Object",
	nullptr,
	nullptr,
	_ExitVM_MethodInfo_
};

$Object* allocate$ExitVM($Class* clazz) {
	return $of($alloc(ExitVM));
}

void ExitVM::init$() {
}

void ExitVM::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($RuntimePermission, newWildcard, $new($RuntimePermission, "exitVM.*"_s));
	$var($RuntimePermission, oldWildcard, $new($RuntimePermission, "exitVM"_s));
	$var($RuntimePermission, other, $new($RuntimePermission, "exitVM.23"_s));
	$nc($System::out)->println("Testing RuntimePermission(\"exitVM.*\")"_s);
	$nc($System::out)->println("    testing getName()"_s);
	if (!$nc($(newWildcard->getName()))->equals("exitVM.*"_s)) {
		$throwNew($Exception, $$str({"expected: exitVM.* received:"_s, $(newWildcard->getName())}));
	}
	$nc($System::out)->println("    testing equals(new RuntimePermission(\"exitVM.*\"))"_s);
	if (!newWildcard->equals($$new($RuntimePermission, "exitVM.*"_s))) {
		$throwNew($Exception, "expected true, received false"_s);
	}
	$nc($System::out)->println("    testing equals(new RuntimePermission(\"exitVM.23\"))"_s);
	if (newWildcard->equals(other)) {
		$throwNew($Exception, "expected false, received true"_s);
	}
	$nc($System::out)->println("    testing implies(new RuntimePermission(\"exitVM.23\"))"_s);
	if (!newWildcard->implies(other)) {
		$throwNew($Exception, "expected true, received false"_s);
	}
	$nc($System::out)->println("    testing implies(new RuntimePermission(\"exitVM.*\"))"_s);
	if (!newWildcard->implies($$new($RuntimePermission, "exitVM.*"_s))) {
		$throwNew($Exception, "expected true, received false"_s);
	}
	$nc($System::out)->println("    testing implies(new RuntimePermission(\"exitVM\"))"_s);
	if (!newWildcard->implies(oldWildcard)) {
		$throwNew($Exception, "expected true, received false"_s);
	}
	$nc($System::out)->println("Testing RuntimePermission(\"exitVM\")"_s);
	$nc($System::out)->println("    testing implies(new RuntimePermission(\"exitVM.*\"))"_s);
	if (!oldWildcard->implies(newWildcard)) {
		$throwNew($Exception, "expected true, received false"_s);
	}
	$nc($System::out)->println("    testing implies(new RuntimePermission(\"exitVM\"))"_s);
	if (!oldWildcard->implies($$new($RuntimePermission, "exitVM"_s))) {
		$throwNew($Exception, "expected true, received false"_s);
	}
	$nc($System::out)->println("    testing implies(new RuntimePermission(\"exitVM.23\"))"_s);
	if (!oldWildcard->implies(other)) {
		$throwNew($Exception, "expected true, received false"_s);
	}
	$nc($System::out)->println("Testing PermissionCollection containing RuntimePermission(\"exitVM.*\")"_s);
	$var($PermissionCollection, newPC, newWildcard->newPermissionCollection());
	$nc(newPC)->add(newWildcard);
	$nc($System::out)->println("    testing implies(new RuntimePermission(\"exitVM.23\"))"_s);
	if (!newPC->implies(other)) {
		$throwNew($Exception, "expected true, received false"_s);
	}
	$nc($System::out)->println("    testing implies(new RuntimePermission(\"exitVM.*\"))"_s);
	if (!newPC->implies($$new($RuntimePermission, "exitVM.*"_s))) {
		$throwNew($Exception, "expected true, received false"_s);
	}
	$nc($System::out)->println("    testing implies(new RuntimePermission(\"exitVM\"))"_s);
	if (!newPC->implies(oldWildcard)) {
		$throwNew($Exception, "expected true, received false"_s);
	}
	$nc($System::out)->println("Testing PermissionCollection containing RuntimePermission(\"exitVM\")"_s);
	$var($PermissionCollection, oldPC, oldWildcard->newPermissionCollection());
	$nc(oldPC)->add(oldWildcard);
	$nc($System::out)->println("    testing implies(new RuntimePermission(\"exitVM.23\"))"_s);
	if (!oldPC->implies(other)) {
		$throwNew($Exception, "expected true, received false"_s);
	}
	$nc($System::out)->println("    testing implies(new RuntimePermission(\"exitVM.*\"))"_s);
	if (!oldPC->implies($$new($RuntimePermission, "exitVM.*"_s))) {
		$throwNew($Exception, "expected true, received false"_s);
	}
	$nc($System::out)->println("    testing implies(new RuntimePermission(\"exitVM\"))"_s);
	if (!oldPC->implies(oldWildcard)) {
		$throwNew($Exception, "expected true, received false"_s);
	}
}

ExitVM::ExitVM() {
}

$Class* ExitVM::load$($String* name, bool initialize) {
	$loadClass(ExitVM, name, initialize, &_ExitVM_ClassInfo_, allocate$ExitVM);
	return class$;
}

$Class* ExitVM::class$ = nullptr;