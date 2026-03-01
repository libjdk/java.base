#include <sun/nio/ch/UnixDomainSockets.h>

#include <java/io/FileDescriptor.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/net/BindException.h>
#include <java/net/NetPermission.h>
#include <java/net/SocketAddress.h>
#include <java/net/UnixDomainSocketAddress.h>
#include <java/nio/channels/UnsupportedAddressTypeException.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/file/FileSystem.h>
#include <java/nio/file/FileSystems.h>
#include <java/nio/file/InvalidPathException.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/spi/FileSystemProvider.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Permission.h>
#include <java/security/SecureRandom.h>
#include <java/util/Random.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/nio/ch/UnixDomainSocketsUtil.h>
#include <sun/nio/fs/AbstractFileSystemProvider.h>
#include <jcpp.h>

#undef MAX_VALUE
#undef UNNAMED

using $FileDescriptor = ::java::io::FileDescriptor;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $BindException = ::java::net::BindException;
using $NetPermission = ::java::net::NetPermission;
using $SocketAddress = ::java::net::SocketAddress;
using $UnixDomainSocketAddress = ::java::net::UnixDomainSocketAddress;
using $UnsupportedAddressTypeException = ::java::nio::channels::UnsupportedAddressTypeException;
using $FileSystem = ::java::nio::file::FileSystem;
using $FileSystems = ::java::nio::file::FileSystems;
using $InvalidPathException = ::java::nio::file::InvalidPathException;
using $Path = ::java::nio::file::Path;
using $FileSystemProvider = ::java::nio::file::spi::FileSystemProvider;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Permission = ::java::security::Permission;
using $SecureRandom = ::java::security::SecureRandom;
using $Random = ::java::util::Random;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $UnixDomainSocketsUtil = ::sun::nio::ch::UnixDomainSocketsUtil;
using $AbstractFileSystemProvider = ::sun::nio::fs::AbstractFileSystemProvider;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _UnixDomainSockets_FieldInfo_[] = {
	{"UNNAMED", "Ljava/net/UnixDomainSocketAddress;", nullptr, $STATIC | $FINAL, $staticField(UnixDomainSockets, UNNAMED)},
	{"supported", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixDomainSockets, supported)},
	{"tempDir", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixDomainSockets, tempDir)},
	{"accessUnixDomainSocket", "Ljava/net/NetPermission;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixDomainSockets, accessUnixDomainSocket)},
	{"random", "Ljava/util/Random;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixDomainSockets, random)},
	{}
};

$MethodInfo _UnixDomainSockets_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(UnixDomainSockets, init$, void)},
	{"accept", "(Ljava/io/FileDescriptor;Ljava/io/FileDescriptor;[Ljava/lang/String;)I", nullptr, $STATIC, $staticMethod(UnixDomainSockets, accept, int32_t, $FileDescriptor*, $FileDescriptor*, $StringArray*), "java.io.IOException"},
	{"accept0", "(Ljava/io/FileDescriptor;Ljava/io/FileDescriptor;[Ljava/lang/Object;)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(UnixDomainSockets, accept0, int32_t, $FileDescriptor*, $FileDescriptor*, $ObjectArray*), "java.io.IOException"},
	{"bind", "(Ljava/io/FileDescriptor;Ljava/nio/file/Path;)V", nullptr, $STATIC, $staticMethod(UnixDomainSockets, bind, void, $FileDescriptor*, $Path*), "java.io.IOException"},
	{"bind0", "(Ljava/io/FileDescriptor;[B)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(UnixDomainSockets, bind0, void, $FileDescriptor*, $bytes*), "java.io.IOException"},
	{"checkAddress", "(Ljava/net/SocketAddress;)Ljava/net/UnixDomainSocketAddress;", nullptr, $STATIC, $staticMethod(UnixDomainSockets, checkAddress, $UnixDomainSocketAddress*, $SocketAddress*)},
	{"checkPermission", "()V", nullptr, $STATIC, $staticMethod(UnixDomainSockets, checkPermission, void)},
	{"connect", "(Ljava/io/FileDescriptor;Ljava/net/SocketAddress;)I", nullptr, $STATIC, $staticMethod(UnixDomainSockets, connect, int32_t, $FileDescriptor*, $SocketAddress*), "java.io.IOException"},
	{"connect", "(Ljava/io/FileDescriptor;Ljava/nio/file/Path;)I", nullptr, $STATIC, $staticMethod(UnixDomainSockets, connect, int32_t, $FileDescriptor*, $Path*), "java.io.IOException"},
	{"connect0", "(Ljava/io/FileDescriptor;[B)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(UnixDomainSockets, connect0, int32_t, $FileDescriptor*, $bytes*), "java.io.IOException"},
	{"generateTempName", "()Ljava/net/UnixDomainSocketAddress;", nullptr, $STATIC, $staticMethod(UnixDomainSockets, generateTempName, $UnixDomainSocketAddress*), "java.io.IOException"},
	{"getPathBytes", "(Ljava/nio/file/Path;)[B", nullptr, $STATIC, $staticMethod(UnixDomainSockets, getPathBytes, $bytes*, $Path*)},
	{"getRandom", "()Ljava/util/Random;", nullptr, $PRIVATE | $STATIC, $staticMethod(UnixDomainSockets, getRandom, $Random*)},
	{"getRevealedLocalAddress", "(Ljava/net/SocketAddress;)Ljava/net/UnixDomainSocketAddress;", nullptr, $STATIC, $staticMethod(UnixDomainSockets, getRevealedLocalAddress, $UnixDomainSocketAddress*, $SocketAddress*)},
	{"getRevealedLocalAddressAsString", "(Ljava/net/SocketAddress;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(UnixDomainSockets, getRevealedLocalAddressAsString, $String*, $SocketAddress*)},
	{"init", "()Z", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(UnixDomainSockets, init, bool)},
	{"isSupported", "()Z", nullptr, $STATIC, $staticMethod(UnixDomainSockets, isSupported, bool)},
	{"localAddress", "(Ljava/io/FileDescriptor;)Ljava/net/UnixDomainSocketAddress;", nullptr, $STATIC, $staticMethod(UnixDomainSockets, localAddress, $UnixDomainSocketAddress*, $FileDescriptor*), "java.io.IOException"},
	{"localAddress0", "(Ljava/io/FileDescriptor;)[B", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(UnixDomainSockets, localAddress0, $bytes*, $FileDescriptor*), "java.io.IOException"},
	{"socket", "()Ljava/io/FileDescriptor;", nullptr, $STATIC, $staticMethod(UnixDomainSockets, socket, $FileDescriptor*), "java.io.IOException"},
	{"socket0", "()I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(UnixDomainSockets, socket0, int32_t), "java.io.IOException"},
	{}
};

#define _METHOD_INDEX_accept0 2
#define _METHOD_INDEX_bind0 4
#define _METHOD_INDEX_connect0 9
#define _METHOD_INDEX_init 15
#define _METHOD_INDEX_localAddress0 18
#define _METHOD_INDEX_socket0 20

$ClassInfo _UnixDomainSockets_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.UnixDomainSockets",
	"java.lang.Object",
	nullptr,
	_UnixDomainSockets_FieldInfo_,
	_UnixDomainSockets_MethodInfo_
};

$Object* allocate$UnixDomainSockets($Class* clazz) {
	return $of($alloc(UnixDomainSockets));
}

$UnixDomainSocketAddress* UnixDomainSockets::UNNAMED = nullptr;
bool UnixDomainSockets::supported = false;
$String* UnixDomainSockets::tempDir = nullptr;
$NetPermission* UnixDomainSockets::accessUnixDomainSocket = nullptr;
$Random* UnixDomainSockets::random = nullptr;

void UnixDomainSockets::init$() {
}

bool UnixDomainSockets::isSupported() {
	$init(UnixDomainSockets);
	return UnixDomainSockets::supported;
}

void UnixDomainSockets::checkPermission() {
	$init(UnixDomainSockets);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission(UnixDomainSockets::accessUnixDomainSocket);
	}
}

$UnixDomainSocketAddress* UnixDomainSockets::getRevealedLocalAddress($SocketAddress* sa) {
	$init(UnixDomainSockets);
	$var($UnixDomainSocketAddress, addr, $cast($UnixDomainSocketAddress, sa));
	try {
		checkPermission();
	} catch ($SecurityException& e) {
		$assign(addr, UnixDomainSockets::UNNAMED);
	}
	return addr;
}

$UnixDomainSocketAddress* UnixDomainSockets::localAddress($FileDescriptor* fd) {
	$init(UnixDomainSockets);
	$useLocalCurrentObjectStackCache();
	$var($bytes, var$0, localAddress0(fd));
	$var($String, path, $new($String, var$0, $($UnixDomainSocketsUtil::getCharset())));
	return $UnixDomainSocketAddress::of(path);
}

$bytes* UnixDomainSockets::localAddress0($FileDescriptor* fd) {
	$init(UnixDomainSockets);
	$var($bytes, $ret, nullptr);
	$prepareNativeStatic(UnixDomainSockets, localAddress0, $bytes*, $FileDescriptor* fd);
	$assign($ret, $invokeNativeStaticObject(fd));
	$finishNativeStatic();
	return $ret;
}

$String* UnixDomainSockets::getRevealedLocalAddressAsString($SocketAddress* sa) {
	$init(UnixDomainSockets);
	return ($System::getSecurityManager() != nullptr) ? $nc($of(sa))->toString() : ""_s;
}

$UnixDomainSocketAddress* UnixDomainSockets::checkAddress($SocketAddress* sa) {
	$init(UnixDomainSockets);
	if (sa == nullptr) {
		$throwNew($NullPointerException);
	}
	if (!($instanceOf($UnixDomainSocketAddress, sa))) {
		$throwNew($UnsupportedAddressTypeException);
	}
	return $cast($UnixDomainSocketAddress, sa);
}

$bytes* UnixDomainSockets::getPathBytes($Path* path) {
	$init(UnixDomainSockets);
	$useLocalCurrentObjectStackCache();
	$var($FileSystemProvider, provider, $nc($($FileSystems::getDefault()))->provider());
	return $nc(($cast($AbstractFileSystemProvider, provider)))->getSunPathForSocketFile(path);
}

$FileDescriptor* UnixDomainSockets::socket() {
	$init(UnixDomainSockets);
	return $IOUtil::newFD(socket0());
}

void UnixDomainSockets::bind($FileDescriptor* fd, $Path* addr) {
	$init(UnixDomainSockets);
	$var($bytes, path, getPathBytes(addr));
	if ($nc(path)->length == 0) {
		$throwNew($BindException, "Server socket cannot bind to unnamed address"_s);
	}
	bind0(fd, path);
}

$Random* UnixDomainSockets::getRandom() {
	$init(UnixDomainSockets);
	try {
		return $SecureRandom::getInstance("NativePRNGNonBlocking"_s);
	} catch ($NoSuchAlgorithmException& e) {
		return $new($SecureRandom);
	}
	$shouldNotReachHere();
}

$UnixDomainSocketAddress* UnixDomainSockets::generateTempName() {
	$init(UnixDomainSockets);
	$useLocalCurrentObjectStackCache();
	$var($String, dir, UnixDomainSockets::tempDir);
	if (dir == nullptr) {
		$throwNew($BindException, "Could not locate temporary directory for sockets"_s);
	}
	int32_t rnd = $nc(UnixDomainSockets::random)->nextInt($Integer::MAX_VALUE);
	try {
		$var($Path, path, $Path::of(dir, $$new($StringArray, {$$str({"socket_"_s, $$str(rnd)})})));
		return $UnixDomainSocketAddress::of(path);
	} catch ($InvalidPathException& e) {
		$throwNew($BindException, "Invalid temporary directory"_s);
	}
	$shouldNotReachHere();
}

int32_t UnixDomainSockets::connect($FileDescriptor* fd, $SocketAddress* sa) {
	$init(UnixDomainSockets);
	return UnixDomainSockets::connect(fd, $($nc(($cast($UnixDomainSocketAddress, sa)))->getPath()));
}

int32_t UnixDomainSockets::connect($FileDescriptor* fd, $Path* path) {
	$init(UnixDomainSockets);
	return connect0(fd, $(getPathBytes(path)));
}

int32_t UnixDomainSockets::accept($FileDescriptor* fd, $FileDescriptor* newfd, $StringArray* paths) {
	$init(UnixDomainSockets);
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, array, $new($ObjectArray, 1));
	int32_t n = accept0(fd, newfd, array);
	if (n > 0) {
		$var($bytes, bytes, $cast($bytes, array->get(0)));
		$nc(paths)->set(0, $$new($String, bytes, $($UnixDomainSocketsUtil::getCharset())));
	}
	return n;
}

bool UnixDomainSockets::init() {
	$init(UnixDomainSockets);
	bool $ret = false;
	$prepareNativeStatic(UnixDomainSockets, init, bool);
	$ret = $invokeNativeStatic();
	$finishNativeStatic();
	return $ret;
}

int32_t UnixDomainSockets::socket0() {
	$init(UnixDomainSockets);
	int32_t $ret = 0;
	$prepareNativeStatic(UnixDomainSockets, socket0, int32_t);
	$ret = $invokeNativeStatic();
	$finishNativeStatic();
	return $ret;
}

void UnixDomainSockets::bind0($FileDescriptor* fd, $bytes* path) {
	$init(UnixDomainSockets);
	$prepareNativeStatic(UnixDomainSockets, bind0, void, $FileDescriptor* fd, $bytes* path);
	$invokeNativeStatic(fd, path);
	$finishNativeStatic();
}

int32_t UnixDomainSockets::connect0($FileDescriptor* fd, $bytes* path) {
	$init(UnixDomainSockets);
	int32_t $ret = 0;
	$prepareNativeStatic(UnixDomainSockets, connect0, int32_t, $FileDescriptor* fd, $bytes* path);
	$ret = $invokeNativeStatic(fd, path);
	$finishNativeStatic();
	return $ret;
}

int32_t UnixDomainSockets::accept0($FileDescriptor* fd, $FileDescriptor* newfd, $ObjectArray* array) {
	$init(UnixDomainSockets);
	int32_t $ret = 0;
	$prepareNativeStatic(UnixDomainSockets, accept0, int32_t, $FileDescriptor* fd, $FileDescriptor* newfd, $ObjectArray* array);
	$ret = $invokeNativeStatic(fd, newfd, array);
	$finishNativeStatic();
	return $ret;
}

void clinit$UnixDomainSockets($Class* class$) {
	$assignStatic(UnixDomainSockets::UNNAMED, $UnixDomainSocketAddress::of(""_s));
	$assignStatic(UnixDomainSockets::tempDir, $UnixDomainSocketsUtil::getTempDir());
	$assignStatic(UnixDomainSockets::accessUnixDomainSocket, $new($NetPermission, "accessUnixDomainSocket"_s));
	$assignStatic(UnixDomainSockets::random, UnixDomainSockets::getRandom());
	{
		$IOUtil::load();
		UnixDomainSockets::supported = UnixDomainSockets::init();
	}
}

UnixDomainSockets::UnixDomainSockets() {
}

$Class* UnixDomainSockets::load$($String* name, bool initialize) {
	$loadClass(UnixDomainSockets, name, initialize, &_UnixDomainSockets_ClassInfo_, clinit$UnixDomainSockets, allocate$UnixDomainSockets);
	return class$;
}

$Class* UnixDomainSockets::class$ = nullptr;

		} // ch
	} // nio
} // sun