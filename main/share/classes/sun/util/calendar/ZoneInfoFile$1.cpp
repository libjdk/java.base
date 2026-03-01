#include <sun/util/calendar/ZoneInfoFile$1.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/DataInputStream.h>
#include <java/io/File.h>
#include <java/io/FileInputStream.h>
#include <java/io/InputStream.h>
#include <java/lang/Error.h>
#include <java/time/ZoneId.h>
#include <jdk/internal/util/StaticProperty.h>
#include <sun/util/calendar/ZoneInfoFile.h>
#include <jcpp.h>

using $BufferedInputStream = ::java::io::BufferedInputStream;
using $DataInputStream = ::java::io::DataInputStream;
using $File = ::java::io::File;
using $FileInputStream = ::java::io::FileInputStream;
using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ZoneId = ::java::time::ZoneId;
using $StaticProperty = ::jdk::internal::util::StaticProperty;
using $ZoneInfoFile = ::sun::util::calendar::ZoneInfoFile;

namespace sun {
	namespace util {
		namespace calendar {

$MethodInfo _ZoneInfoFile$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(ZoneInfoFile$1, init$, void)},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC, $virtualMethod(ZoneInfoFile$1, run, $Object*)},
	{}
};

$EnclosingMethodInfo _ZoneInfoFile$1_EnclosingMethodInfo_ = {
	"sun.util.calendar.ZoneInfoFile",
	nullptr,
	nullptr
};

$InnerClassInfo _ZoneInfoFile$1_InnerClassesInfo_[] = {
	{"sun.util.calendar.ZoneInfoFile$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ZoneInfoFile$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.util.calendar.ZoneInfoFile$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_ZoneInfoFile$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Void;>;",
	&_ZoneInfoFile$1_EnclosingMethodInfo_,
	_ZoneInfoFile$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.util.calendar.ZoneInfoFile"
};

$Object* allocate$ZoneInfoFile$1($Class* clazz) {
	return $of($alloc(ZoneInfoFile$1));
}

void ZoneInfoFile$1::init$() {
}

$Object* ZoneInfoFile$1::run() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$init($File);
		$var($String, libDir, $str({$($StaticProperty::javaHome()), $File::separator, "lib"_s}));
		if ($$new($File, libDir, "tzdb.dat"_s)->exists()) {
			{
				$var($DataInputStream, dis, $new($DataInputStream, $$new($BufferedInputStream, $$new($FileInputStream, $$new($File, libDir, "tzdb.dat"_s)))));
				{
					$var($Throwable, var$0, nullptr);
					try {
						try {
							$ZoneInfoFile::load(dis);
						} catch ($Throwable& t$) {
							try {
								dis->close();
							} catch ($Throwable& x2) {
								t$->addSuppressed(x2);
							}
							$throw(t$);
						}
					} catch ($Throwable& var$1) {
						$assign(var$0, var$1);
					} /*finally*/ {
						dis->close();
					}
					if (var$0 != nullptr) {
						$throw(var$0);
					}
				}
			}
		} else {
			{
				$load($ZoneId);
				$var($DataInputStream, dis, $new($DataInputStream, $$new($BufferedInputStream, $($ZoneId::class$->getResourceAsStream("tzdb.dat"_s)))));
				{
					$var($Throwable, var$2, nullptr);
					try {
						try {
							$ZoneInfoFile::load(dis);
						} catch ($Throwable& t$) {
							try {
								dis->close();
							} catch ($Throwable& x2) {
								t$->addSuppressed(x2);
							}
							$throw(t$);
						}
					} catch ($Throwable& var$3) {
						$assign(var$2, var$3);
					} /*finally*/ {
						dis->close();
					}
					if (var$2 != nullptr) {
						$throw(var$2);
					}
				}
			}
		}
	} catch ($Exception& x) {
		$throwNew($Error, static_cast<$Throwable*>(x));
	}
	return $of(nullptr);
}

ZoneInfoFile$1::ZoneInfoFile$1() {
}

$Class* ZoneInfoFile$1::load$($String* name, bool initialize) {
	$loadClass(ZoneInfoFile$1, name, initialize, &_ZoneInfoFile$1_ClassInfo_, allocate$ZoneInfoFile$1);
	return class$;
}

$Class* ZoneInfoFile$1::class$ = nullptr;

		} // calendar
	} // util
} // sun