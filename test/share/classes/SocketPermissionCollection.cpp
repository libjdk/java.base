#include <SocketPermissionCollection.h>

#include <java/net/SocketPermission.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/security/SecurityPermission.h>
#include <java/util/Enumeration.h>
#include <jcpp.h>

using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $SocketPermission = ::java::net::SocketPermission;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $SecurityPermission = ::java::security::SecurityPermission;
using $Enumeration = ::java::util::Enumeration;

$MethodInfo _SocketPermissionCollection_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SocketPermissionCollection, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(SocketPermissionCollection, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$ClassInfo _SocketPermissionCollection_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"SocketPermissionCollection",
	"java.lang.Object",
	nullptr,
	nullptr,
	_SocketPermissionCollection_MethodInfo_
};

$Object* allocate$SocketPermissionCollection($Class* clazz) {
	return $of($alloc(SocketPermissionCollection));
}

void SocketPermissionCollection::init$() {
}

void SocketPermissionCollection::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	int32_t testFail = 0;
	$var($SocketPermission, perm, $new($SocketPermission, "www.example.com"_s, "connect"_s));
	$var($PermissionCollection, perms, perm->newPermissionCollection());
	$nc($System::out)->println("test 1: add throws IllegalArgExc for wrong perm type"_s);
	try {
		$nc(perms)->add($$new($SecurityPermission, "createAccessControlContext"_s));
		$nc($System::err)->println("Expected IllegalArgumentException"_s);
		++testFail;
	} catch ($IllegalArgumentException& iae) {
	}
	$nc($System::out)->println("test 2: implies returns false for wrong perm type"_s);
	if ($nc(perms)->implies($$new($SecurityPermission, "getPolicy"_s))) {
		$nc($System::err)->println("Expected false, returned true"_s);
		++testFail;
	}
	$nc($System::out)->println("test 3: implies returns true for match on name and action"_s);
	$nc(perms)->add($$new($SocketPermission, "www.example.com"_s, "connect"_s));
	if (!perms->implies($$new($SocketPermission, "www.example.com"_s, "connect"_s))) {
		$nc($System::err)->println("Expected true, returned false"_s);
		++testFail;
	}
	$nc($System::out)->println("test 4: implies returns false for match on name but not action"_s);
	if (perms->implies($$new($SocketPermission, "www.example.com"_s, "accept"_s))) {
		$nc($System::err)->println("Expected false, returned true"_s);
		++testFail;
	}
	$nc($System::out)->println("test 5: implies returns true for match on name and subset of actions"_s);
	perms->add($$new($SocketPermission, "www.example.org"_s, "accept, connect"_s));
	if (!perms->implies($$new($SocketPermission, "www.example.org"_s, "connect"_s))) {
		$nc($System::err)->println("Expected true, returned false"_s);
		++testFail;
	}
	$nc($System::out)->println("test 6: implies returns true for aggregate match on name and action"_s);
	perms->add($$new($SocketPermission, "www.example.us"_s, "accept"_s));
	perms->add($$new($SocketPermission, "www.example.us"_s, "connect"_s));
	if (!perms->implies($$new($SocketPermission, "www.example.us"_s, "accept"_s))) {
		$nc($System::err)->println("Expected true, returned false"_s);
		++testFail;
	}
	if (!perms->implies($$new($SocketPermission, "www.example.us"_s, "connect,accept"_s))) {
		$nc($System::err)->println("Expected true, returned false"_s);
		++testFail;
	}
	$nc($System::out)->println("test 7: implies returns true for wildcard and match on action"_s);
	perms->add($$new($SocketPermission, "*.example.edu"_s, "resolve"_s));
	if (!perms->implies($$new($SocketPermission, "foo.example.edu"_s, "resolve"_s))) {
		$nc($System::err)->println("Expected true, returned false"_s);
		++testFail;
	}
	$nc($System::out)->println("test 8: implies returns false for non-match on wildcard"_s);
	if (perms->implies($$new($SocketPermission, "foo.example.edu"_s, "connect"_s))) {
		$nc($System::err)->println("Expected false, returned true"_s);
		++testFail;
	}
	$nc($System::out)->println("test 9: implies returns true for matching port range and action"_s);
	perms->add($$new($SocketPermission, "204.160.241.0:1024-65535"_s, "connect"_s));
	if (!perms->implies($$new($SocketPermission, "204.160.241.0:1025"_s, "connect"_s))) {
		$nc($System::err)->println("Expected true, returned false"_s);
		++testFail;
	}
	$nc($System::out)->println("test 10: elements returns correct number of perms"_s);
	perms->add($$new($SocketPermission, "www.example.us"_s, "resolve"_s));
	int32_t numPerms = 0;
	$var($Enumeration, e, perms->elements());
	while ($nc(e)->hasMoreElements()) {
		++numPerms;
		$nc($System::out)->println($(e->nextElement()));
	}
	if (numPerms != 5) {
		$nc($System::err)->println($$str({"Expected 5, got "_s, $$str(numPerms)}));
		++testFail;
	}
	if (testFail > 0) {
		$throwNew($Exception, $$str({$$str(testFail), " test(s) failed"_s}));
	}
}

SocketPermissionCollection::SocketPermissionCollection() {
}

$Class* SocketPermissionCollection::load$($String* name, bool initialize) {
	$loadClass(SocketPermissionCollection, name, initialize, &_SocketPermissionCollection_ClassInfo_, allocate$SocketPermissionCollection);
	return class$;
}

$Class* SocketPermissionCollection::class$ = nullptr;