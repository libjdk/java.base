#include <java/lang/invoke/ProxyClassesDumper.h>

#include <java/io/FilePermission.h>
#include <java/lang/invoke/ProxyClassesDumper$1.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/InvalidPathException.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/OpenOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/attribute/FileAttribute.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Objects.h>
#include <sun/util/logging/PlatformLogger.h>
#include <jcpp.h>

#undef BAD_CHARS
#undef HEX
#undef REPLACEMENT

using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $OpenOptionArray = $Array<::java::nio::file::OpenOption>;
using $FileAttributeArray = $Array<::java::nio::file::attribute::FileAttribute>;
using $PermissionArray = $Array<::java::security::Permission>;
using $FilePermission = ::java::io::FilePermission;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ProxyClassesDumper$1 = ::java::lang::invoke::ProxyClassesDumper$1;
using $Files = ::java::nio::file::Files;
using $InvalidPathException = ::java::nio::file::InvalidPathException;
using $Path = ::java::nio::file::Path;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Objects = ::java::util::Objects;
using $PlatformLogger = ::sun::util::logging::PlatformLogger;

namespace java {
	namespace lang {
		namespace invoke {

$FieldInfo _ProxyClassesDumper_FieldInfo_[] = {
	{"HEX", "[C", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyClassesDumper, HEX)},
	{"BAD_CHARS", "[C", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyClassesDumper, BAD_CHARS)},
	{"REPLACEMENT", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyClassesDumper, REPLACEMENT)},
	{"dumpDir", "Ljava/nio/file/Path;", nullptr, $PRIVATE | $FINAL, $field(ProxyClassesDumper, dumpDir)},
	{}
};

$MethodInfo _ProxyClassesDumper_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/file/Path;)V", nullptr, $PRIVATE, $method(ProxyClassesDumper, init$, void, $Path*)},
	{"dumpClass", "(Ljava/lang/String;[B)V", nullptr, $PUBLIC, $method(ProxyClassesDumper, dumpClass, void, $String*, $bytes*)},
	{"encodeForFilename", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(ProxyClassesDumper, encodeForFilename, $String*, $String*)},
	{"getInstance", "(Ljava/lang/String;)Ljava/lang/invoke/ProxyClassesDumper;", nullptr, $PUBLIC | $STATIC, $staticMethod(ProxyClassesDumper, getInstance, ProxyClassesDumper*, $String*)},
	{"validateDumpDir", "(Ljava/nio/file/Path;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ProxyClassesDumper, validateDumpDir, void, $Path*)},
	{}
};

$InnerClassInfo _ProxyClassesDumper_InnerClassesInfo_[] = {
	{"java.lang.invoke.ProxyClassesDumper$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ProxyClassesDumper_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.lang.invoke.ProxyClassesDumper",
	"java.lang.Object",
	nullptr,
	_ProxyClassesDumper_FieldInfo_,
	_ProxyClassesDumper_MethodInfo_,
	nullptr,
	nullptr,
	_ProxyClassesDumper_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.invoke.ProxyClassesDumper$1"
};

$Object* allocate$ProxyClassesDumper($Class* clazz) {
	return $of($alloc(ProxyClassesDumper));
}

$chars* ProxyClassesDumper::HEX = nullptr;
$chars* ProxyClassesDumper::BAD_CHARS = nullptr;
$StringArray* ProxyClassesDumper::REPLACEMENT = nullptr;

ProxyClassesDumper* ProxyClassesDumper::getInstance($String* path$renamed) {
	$init(ProxyClassesDumper);
	$useLocalCurrentObjectStackCache();
	$var($String, path, path$renamed);
	$beforeCallerSensitive();
	if (nullptr == path) {
		return nullptr;
	}
	try {
		$assign(path, $nc(path)->trim());
		$var($Path, dir, $Path::of(path->isEmpty() ? "."_s : path, $$new($StringArray, 0)));
		$var($PrivilegedAction, var$0, static_cast<$PrivilegedAction*>($new($ProxyClassesDumper$1, dir)));
		$AccessController::doPrivileged(var$0, ($AccessControlContext*)nullptr, $$new($PermissionArray, {static_cast<$Permission*>($$new($FilePermission, "<<ALL FILES>>"_s, "read, write"_s))}));
		return $new(ProxyClassesDumper, dir);
	} catch ($InvalidPathException& ex) {
		$nc($($PlatformLogger::getLogger($(ProxyClassesDumper::class$->getName()))))->warning($$str({"Path "_s, path, " is not valid - dumping disabled"_s}), static_cast<$Throwable*>(ex));
	} catch ($IllegalArgumentException& iae) {
		$nc($($PlatformLogger::getLogger($(ProxyClassesDumper::class$->getName()))))->warning($$str({$(iae->getMessage()), " - dumping disabled"_s}));
	}
	return nullptr;
}

void ProxyClassesDumper::init$($Path* path) {
	$set(this, dumpDir, $cast($Path, $Objects::requireNonNull(path)));
}

void ProxyClassesDumper::validateDumpDir($Path* path) {
	$init(ProxyClassesDumper);
	$useLocalCurrentObjectStackCache();
	if (!$Files::exists(path, $$new($LinkOptionArray, 0))) {
		$throwNew($IllegalArgumentException, $$str({"Directory "_s, path, " does not exist"_s}));
	} else if (!$Files::isDirectory(path, $$new($LinkOptionArray, 0))) {
		$throwNew($IllegalArgumentException, $$str({"Path "_s, path, " is not a directory"_s}));
	} else if (!$Files::isWritable(path)) {
		$throwNew($IllegalArgumentException, $$str({"Directory "_s, path, " is not writable"_s}));
	}
}

$String* ProxyClassesDumper::encodeForFilename($String* className) {
	$init(ProxyClassesDumper);
	int32_t len = $nc(className)->length();
	$var($StringBuilder, sb, $new($StringBuilder, len));
	for (int32_t i = 0; i < len; ++i) {
		char16_t c = className->charAt(i);
		if (c <= 31) {
			sb->append(u'%');
			sb->append($nc(ProxyClassesDumper::HEX)->get((int32_t)((c >> 4) & (uint32_t)15)));
			sb->append($nc(ProxyClassesDumper::HEX)->get((int32_t)(c & (uint32_t)15)));
		} else {
			int32_t j = 0;
			for (; j < $nc(ProxyClassesDumper::BAD_CHARS)->length; ++j) {
				if (c == $nc(ProxyClassesDumper::BAD_CHARS)->get(j)) {
					sb->append($nc(ProxyClassesDumper::REPLACEMENT)->get(j));
					break;
				}
			}
			if (j >= $nc(ProxyClassesDumper::BAD_CHARS)->length) {
				sb->append(c);
			}
		}
	}
	return sb->toString();
}

void ProxyClassesDumper::dumpClass($String* className, $bytes* classBytes) {
	$useLocalCurrentObjectStackCache();
	$var($Path, file, nullptr);
	try {
		$assign(file, $nc(this->dumpDir)->resolve($$str({$(encodeForFilename(className)), ".class"_s})));
	} catch ($InvalidPathException& ex) {
		$nc($($PlatformLogger::getLogger($(ProxyClassesDumper::class$->getName()))))->warning($$str({"Invalid path for class "_s, className}));
		return;
	}
	try {
		$var($Path, dir, $nc(file)->getParent());
		$Files::createDirectories(dir, $$new($FileAttributeArray, 0));
		$Files::write(file, classBytes, $$new($OpenOptionArray, 0));
	} catch ($Exception& ignore) {
		$nc($($PlatformLogger::getLogger($(ProxyClassesDumper::class$->getName()))))->warning($$str({"Exception writing to path at "_s, $($nc(file)->toString())}));
	}
}

void clinit$ProxyClassesDumper($Class* class$) {
	$assignStatic(ProxyClassesDumper::HEX, $new($chars, {
		u'0',
		u'1',
		u'2',
		u'3',
		u'4',
		u'5',
		u'6',
		u'7',
		u'8',
		u'9',
		u'A',
		u'B',
		u'C',
		u'D',
		u'E',
		u'F'
	}));
	$assignStatic(ProxyClassesDumper::BAD_CHARS, $new($chars, {
		u'\\',
		u':',
		u'*',
		u'?',
		u'\"',
		u'<',
		u'>',
		u'|'
	}));
	$assignStatic(ProxyClassesDumper::REPLACEMENT, $new($StringArray, {
		"%5C"_s,
		"%3A"_s,
		"%2A"_s,
		"%3F"_s,
		"%22"_s,
		"%3C"_s,
		"%3E"_s,
		"%7C"_s
	}));
}

ProxyClassesDumper::ProxyClassesDumper() {
}

$Class* ProxyClassesDumper::load$($String* name, bool initialize) {
	$loadClass(ProxyClassesDumper, name, initialize, &_ProxyClassesDumper_ClassInfo_, clinit$ProxyClassesDumper, allocate$ProxyClassesDumper);
	return class$;
}

$Class* ProxyClassesDumper::class$ = nullptr;

		} // invoke
	} // lang
} // java